int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_1 * V_5 ;
F_2 ( L_1 ,
V_6 , V_2 -> V_7 , V_2 -> type ) ;
F_3 ( & V_8 ) ;
F_4 (entry, &dongle_list) {
V_5 = F_5 ( V_4 , struct V_1 , V_9 ) ;
if ( V_2 -> type == V_5 -> type ) {
F_6 ( & V_8 ) ;
return - V_10 ;
}
}
F_7 ( & V_2 -> V_9 , & V_9 ) ;
F_6 ( & V_8 ) ;
return 0 ;
}
int F_8 ( struct V_1 * V_5 )
{
F_3 ( & V_8 ) ;
F_9 ( & V_5 -> V_9 ) ;
F_6 ( & V_8 ) ;
return 0 ;
}
int F_10 ( struct V_11 * V_12 , T_1 type )
{
struct V_3 * V_4 ;
const struct V_1 * V_5 = NULL ;
int V_13 = - V_14 ;
F_11 ( L_2 , type ) ;
if ( V_12 -> V_15 != NULL )
return - V_16 ;
F_3 ( & V_8 ) ;
F_4 (entry, &dongle_list) {
V_5 = F_5 ( V_4 , struct V_1 , V_9 ) ;
if ( V_5 -> type == type )
break;
else
V_5 = NULL ;
}
if ( ! V_5 ) {
V_13 = - V_17 ;
goto V_18;
}
if ( ! F_12 ( V_5 -> V_19 ) ) {
V_13 = - V_20 ;
goto V_18;
}
V_12 -> V_15 = V_5 ;
if ( ! V_5 -> V_21 || ( V_13 = V_5 -> V_21 ( V_12 ) ) != 0 )
goto V_22;
F_6 ( & V_8 ) ;
return 0 ;
V_22:
V_12 -> V_15 = NULL ;
F_13 ( V_5 -> V_19 ) ;
V_18:
F_6 ( & V_8 ) ;
return V_13 ;
}
int F_14 ( struct V_11 * V_12 )
{
const struct V_1 * V_5 = V_12 -> V_15 ;
if ( V_5 ) {
if ( V_5 -> V_23 )
V_5 -> V_23 ( V_12 ) ;
V_12 -> V_15 = NULL ;
F_13 ( V_5 -> V_19 ) ;
}
return 0 ;
}
