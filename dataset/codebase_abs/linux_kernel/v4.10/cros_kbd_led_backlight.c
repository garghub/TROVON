static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
union V_5 V_6 ;
struct V_7 V_8 ;
T_1 V_9 ;
V_6 . type = V_10 ;
V_6 . integer . V_11 = V_4 ;
V_8 . V_12 = 1 ;
V_8 . V_13 = & V_6 ;
V_9 = F_2 ( NULL , V_14 ,
& V_8 , NULL ) ;
if ( F_3 ( V_9 ) )
F_4 ( V_2 -> V_15 , L_1 ,
V_9 ) ;
}
static enum V_3
F_5 ( struct V_1 * V_2 )
{
unsigned long long V_4 ;
T_1 V_9 ;
V_9 = F_6 ( NULL , V_16 ,
NULL , & V_4 ) ;
if ( F_3 ( V_9 ) ) {
F_4 ( V_2 -> V_15 , L_2 ,
V_9 ) ;
return - V_17 ;
}
return V_4 ;
}
static int F_7 ( struct V_18 * V_19 )
{
struct V_1 * V_2 ;
T_2 V_20 ;
T_1 V_9 ;
int error ;
V_9 = F_8 ( V_21 ,
V_22 ,
& V_20 ) ;
if ( F_3 ( V_9 ) ) {
F_4 ( & V_19 -> V_15 , L_3 ,
V_22 , V_9 ) ;
return - V_23 ;
}
V_2 = F_9 ( & V_19 -> V_15 , sizeof( * V_2 ) , V_24 ) ;
if ( ! V_2 )
return - V_25 ;
V_2 -> V_26 = L_4 ;
V_2 -> V_27 = V_28 ;
V_2 -> V_29 |= V_30 ;
V_2 -> V_31 = F_1 ;
V_2 -> V_32 = F_5 ;
error = F_10 ( & V_19 -> V_15 , V_2 ) ;
if ( error )
return error ;
return 0 ;
}
