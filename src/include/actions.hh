#ifndef ACTIONS_HH
#define ACTIONS_HH 1

#include <string>
#include "../oflib/oxm-match.h"
#include "../oflib/ofl-messages.h"
#include "../oflib/ofl-structs.h"
#include "../oflib/ofl-actions.h"

namespace vigil {

class Actions {
public:
    struct ofl_action_header **acts;
    static int act_num;

    Actions(int action_num);

    void
    CreateOutput(uint32_t port, uint16_t max_len);
    
    template<typename T>
    void
    CreateSetField(T* value, std::string field){
        struct ofl_action_set_field *a = (struct ofl_action_set_field*) xmalloc(sizeof (struct ofl_action_set_field));
        a->field = (struct ofl_match_tlv*) xmalloc(sizeof(struct ofl_match_tlv));
        a->field->header = fields[field];
        a->field->value = (uint8_t*) value;
        acts[act_num] = (struct ofl_action_header*) a;
        acts[act_num]->type = OFPAT_SET_FIELD;
        act_num++;
    }
    
    void 
    CreateCopyTTL(enum ofp_action_type type);
    
    void 
    CreateDecTTL(enum ofp_action_type type);
    
    void 
    CreatePushAction(enum ofp_action_type type);
    
    void 
    CreatePopVlan();
    
    void 
    CreatePopMpls(uint16_t ethertype);
    
    void 
    CreateSetNwTTL(uint8_t);

    void 
    CreateSetMplsTTL(uint8_t);
    
    void 
    CreateSetQueue(uint32_t queue_id);
    
    void 
    CreateGroupAction(uint32_t group_id);
    
};

}//namespace vigil
#endif
