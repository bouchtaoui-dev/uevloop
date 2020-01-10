#ifndef EVENT_H
#define	EVENT_H

#include <stdint.h>
#include <stdbool.h>
#include "../utils/closure.h"

enum event_type {
    CLOSURE_EVENT,
    TIMER_EVENT,
    SIGNAL_EVENT
};
typedef enum event_type event_type_t;

typedef struct event event_t;
struct event {
    event_type_t type;
    closure_t closure;
    bool repeating;
    struct{
        uint32_t due_time;
        uint16_t timeout;
    } timer;
};

void event_destroy(event_t *event);

void event_config_closure(event_t *event, closure_t *closure);
void event_config_signal(event_t *event, bool repeating, closure_t *closure);
void event_config_timer(
    event_t *event,
    uint16_t timeout_in_ms,
    bool repeating,
    bool immediate,
    closure_t *closure,
    uint32_t current_time
);

#endif	/* EVENT_H */
