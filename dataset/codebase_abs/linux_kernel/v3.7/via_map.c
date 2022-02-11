static int F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
T_2 * V_4 = V_2 -> V_5 ;
F_2 ( L_1 ) ;
V_4 -> V_6 = F_3 ( V_2 ) ;
if ( ! V_4 -> V_6 ) {
F_4 ( L_2 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_5 ( V_2 ) ;
return - V_7 ;
}
V_4 -> V_8 = F_6 ( V_2 , V_3 -> V_9 ) ;
if ( ! V_4 -> V_8 ) {
F_4 ( L_3 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_5 ( V_2 ) ;
return - V_7 ;
}
V_4 -> V_10 = F_6 ( V_2 , V_3 -> V_11 ) ;
if ( ! V_4 -> V_10 ) {
F_4 ( L_4 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
F_5 ( V_2 ) ;
return - V_7 ;
}
V_4 -> V_12 =
( V_13 * ) ( ( V_14 * ) V_4 -> V_6 -> V_15 +
V_3 -> V_16 ) ;
V_4 -> V_17 = V_3 -> V_17 ;
F_7 ( V_4 ) ;
F_8 ( V_2 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
return 0 ;
}
int F_10 ( struct V_1 * V_2 , void * V_18 , struct V_19 * V_20 )
{
T_1 * V_3 = V_18 ;
F_2 ( L_1 ) ;
switch ( V_3 -> V_21 ) {
case V_22 :
return F_1 ( V_2 , V_3 ) ;
case V_23 :
return F_5 ( V_2 ) ;
}
return - V_7 ;
}
int F_11 ( struct V_1 * V_2 , unsigned long V_24 )
{
T_2 * V_4 ;
int V_25 = 0 ;
V_4 = F_12 ( sizeof( T_2 ) , V_26 ) ;
if ( V_4 == NULL )
return - V_27 ;
F_13 ( & V_4 -> V_28 ) ;
V_2 -> V_5 = ( void * ) V_4 ;
V_4 -> V_24 = V_24 ;
F_14 ( V_2 -> V_29 ) ;
V_25 = F_15 ( V_2 , 1 ) ;
if ( V_25 ) {
F_16 ( V_4 ) ;
return V_25 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 )
{
T_2 * V_4 = V_2 -> V_5 ;
F_18 ( & V_4 -> V_28 ) ;
F_19 ( & V_4 -> V_28 ) ;
F_16 ( V_4 ) ;
return 0 ;
}
