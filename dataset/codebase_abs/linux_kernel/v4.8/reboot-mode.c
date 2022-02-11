static unsigned int F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
const char * V_4 = L_1 ;
int V_5 = 0 ;
struct V_6 * V_7 ;
if ( ! V_3 )
V_3 = V_4 ;
F_2 (info, &reboot->head, list) {
if ( ! strcmp ( V_7 -> V_8 , V_3 ) ) {
V_5 = V_7 -> V_5 ;
break;
}
}
return V_5 ;
}
static int F_3 ( struct V_9 * V_10 ,
unsigned long V_8 , void * V_3 )
{
struct V_1 * V_2 ;
unsigned int V_5 ;
V_2 = F_4 ( V_10 , struct V_1 , V_11 ) ;
V_5 = F_1 ( V_2 , V_3 ) ;
if ( V_5 )
V_2 -> V_12 ( V_2 , V_5 ) ;
return V_13 ;
}
int F_5 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_14 * V_15 ;
struct V_16 * V_17 = V_2 -> V_18 -> V_19 ;
T_1 V_20 = strlen ( V_21 ) ;
int V_22 ;
F_6 ( & V_2 -> V_23 ) ;
F_7 (np, prop) {
if ( strncmp ( V_15 -> V_24 , V_21 , V_20 ) )
continue;
V_7 = F_8 ( V_2 -> V_18 , sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 ) {
V_22 = - V_26 ;
goto error;
}
if ( F_9 ( V_17 , V_15 -> V_24 , & V_7 -> V_5 ) ) {
F_10 ( V_2 -> V_18 , L_2 ,
V_7 -> V_8 ) ;
F_11 ( V_2 -> V_18 , V_7 ) ;
continue;
}
V_7 -> V_8 = F_12 ( V_15 -> V_24 + V_20 , V_25 ) ;
if ( ! V_7 -> V_8 ) {
V_22 = - V_26 ;
goto error;
} else if ( V_7 -> V_8 [ 0 ] == '\0' ) {
F_13 ( V_7 -> V_8 ) ;
V_22 = - V_27 ;
F_10 ( V_2 -> V_18 , L_3 ,
V_15 -> V_24 ) ;
goto error;
}
F_14 ( & V_7 -> V_28 , & V_2 -> V_23 ) ;
}
V_2 -> V_11 . V_29 = F_3 ;
F_15 ( & V_2 -> V_11 ) ;
return 0 ;
error:
F_2 (info, &reboot->head, list)
F_13 ( V_7 -> V_8 ) ;
return V_22 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
F_17 ( & V_2 -> V_11 ) ;
F_2 (info, &reboot->head, list)
F_13 ( V_7 -> V_8 ) ;
return 0 ;
}
