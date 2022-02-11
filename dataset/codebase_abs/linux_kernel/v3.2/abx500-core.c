static void F_1 ( struct V_1 * V_2 , struct V_3 * * V_4 )
{
struct V_5 * V_6 ;
* V_4 = NULL ;
F_2 (dev_entry, &abx500_list, list) {
if ( V_6 -> V_2 == V_2 ) {
* V_4 = & V_6 -> V_4 ;
return;
}
}
}
int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_4 ( sizeof( struct V_5 ) , V_7 ) ;
if ( ! V_6 ) {
F_5 ( V_2 , L_1 ) ;
return - V_8 ;
}
V_6 -> V_2 = V_2 ;
memcpy ( & V_6 -> V_4 , V_4 , sizeof( struct V_3 ) ) ;
F_6 ( & V_6 -> V_9 , & V_10 ) ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 , * V_11 ;
F_8 (dev_entry, tmp, &abx500_list, list)
{
if ( V_6 -> V_2 == V_2 ) {
F_9 ( & V_6 -> V_9 ) ;
F_10 ( V_6 ) ;
}
}
}
int F_11 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 ,
T_1 V_14 )
{
struct V_3 * V_4 ;
F_1 ( V_2 -> V_15 , & V_4 ) ;
if ( ( V_4 != NULL ) && ( V_4 -> V_16 != NULL ) )
return V_4 -> V_16 ( V_2 , V_12 , V_13 , V_14 ) ;
else
return - V_17 ;
}
int F_12 ( struct V_1 * V_2 , T_1 V_12 , T_1 V_13 ,
T_1 * V_14 )
{
struct V_3 * V_4 ;
F_1 ( V_2 -> V_15 , & V_4 ) ;
if ( ( V_4 != NULL ) && ( V_4 -> V_18 != NULL ) )
return V_4 -> V_18 ( V_2 , V_12 , V_13 , V_14 ) ;
else
return - V_17 ;
}
int F_13 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_19 , T_1 * V_20 , T_1 V_21 )
{
struct V_3 * V_4 ;
F_1 ( V_2 -> V_15 , & V_4 ) ;
if ( ( V_4 != NULL ) && ( V_4 -> V_22 != NULL ) )
return V_4 -> V_22 ( V_2 , V_12 ,
V_19 , V_20 , V_21 ) ;
else
return - V_17 ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_12 ,
T_1 V_13 , T_1 V_23 , T_1 V_24 )
{
struct V_3 * V_4 ;
F_1 ( V_2 -> V_15 , & V_4 ) ;
if ( ( V_4 != NULL ) && ( V_4 -> V_25 != NULL ) )
return V_4 -> V_25 ( V_2 , V_12 ,
V_13 , V_23 , V_24 ) ;
else
return - V_17 ;
}
int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_1 ( V_2 -> V_15 , & V_4 ) ;
if ( ( V_4 != NULL ) && ( V_4 -> V_26 != NULL ) )
return V_4 -> V_26 ( V_2 ) ;
else
return - V_17 ;
}
int F_16 ( struct V_1 * V_2 , T_1 * V_27 )
{
struct V_3 * V_4 ;
F_1 ( V_2 -> V_15 , & V_4 ) ;
if ( ( V_4 != NULL ) && ( V_4 -> V_28 != NULL ) )
return V_4 -> V_28 ( V_2 , V_27 ) ;
else
return - V_17 ;
}
int F_17 ( struct V_1 * V_2 , unsigned int V_29 )
{
struct V_3 * V_4 ;
F_1 ( V_2 -> V_15 , & V_4 ) ;
if ( ( V_4 != NULL ) && ( V_4 -> V_30 != NULL ) )
return V_4 -> V_30 ( V_2 , V_29 ) ;
else
return - V_17 ;
}
