static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static T_1 T_2 F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return ( T_1 ) F_4 ( V_4 -> V_5 ) ;
}
static T_3 T_2 F_5 ( void )
{
return F_3 ( & V_6 . V_3 ) ;
}
static int T_4 F_6 ( struct V_7 * V_8 )
{
int V_9 ;
V_6 . V_10 = F_7 ( V_8 , 0 ) ;
if ( ! V_6 . V_10 ) {
F_8 ( L_1 ) ;
return - V_11 ;
}
V_6 . V_5 = V_6 . V_10 ;
if ( F_4 ( V_6 . V_10 + V_12 ) &
V_13 )
V_6 . V_5 += V_14 ;
else
V_6 . V_5 += V_15 ;
V_9 = F_9 ( & V_6 . V_3 , 32768 ) ;
if ( V_9 ) {
F_8 ( L_2 ) ;
return V_9 ;
}
F_10 ( F_5 , 32 , 32768 ) ;
F_11 ( L_3 ) ;
return 0 ;
}
