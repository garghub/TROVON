static inline bool
F_1 ( struct V_1 * V_2 )
{
return false ;
}
static inline int
F_2 ( T_1 * V_3 , int V_4 , int V_5 )
{
return - V_6 ;
}
static T_2
F_3 ( void * V_7 , T_2 V_4 , T_2 V_8 , struct V_9 * V_3 )
{
T_2 V_10 = ( V_4 + V_8 + 0xfff ) & ~ 0xfff ;
T_2 V_11 = V_4 & ~ 0x00000fff ;
T_2 V_12 = V_10 - V_11 ;
if ( F_4 ( V_3 , V_10 ) >= 0 ) {
int V_13 = F_2 ( V_3 -> V_7 , V_11 , V_12 ) ;
if ( V_13 == V_12 )
return V_12 ;
}
return 0 ;
}
static T_2
F_5 ( void * V_7 , T_2 V_4 , T_2 V_8 , struct V_9 * V_3 )
{
T_2 V_10 = ( V_4 + V_8 + 0xfff ) & ~ 0xfff ;
T_2 V_11 = V_4 & ~ 0xfff ;
T_2 V_12 = 0 ;
if ( F_4 ( V_3 , V_10 ) >= 0 ) {
while ( V_11 + V_12 < V_10 ) {
int V_13 = F_2 ( V_3 -> V_7 ,
V_11 + V_12 ,
0x1000 ) ;
if ( V_13 != 0x1000 )
break;
V_12 += 0x1000 ;
}
}
return V_12 ;
}
static void *
F_6 ( struct V_9 * V_3 , const char * V_14 )
{
if ( ! F_1 ( F_7 ( V_3 ) -> V_2 ) )
return F_8 ( - V_15 ) ;
return NULL ;
}
