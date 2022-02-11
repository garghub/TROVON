static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_4 -> V_6 ) >> V_4 -> V_7 ;
V_5 &= V_8 ;
return V_5 ? 180 : 0 ;
}
static int F_4 ( struct V_1 * V_2 , int V_9 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
if ( V_9 % 180 == 0 ) {
V_5 = ! ! V_9 ;
} else {
F_5 ( L_1 ,
V_10 , V_9 , F_6 ( V_2 ) ) ;
return - V_11 ;
}
if ( V_4 -> V_12 & V_13 ) {
F_7 ( F_8 ( V_5 , V_8 , V_4 -> V_7 ) ,
V_4 -> V_6 ) ;
} else {
unsigned long V_12 ;
T_1 V_6 ;
F_9 ( V_4 -> V_14 , V_12 ) ;
V_6 = F_3 ( V_4 -> V_6 ) ;
V_6 &= ~ F_10 ( V_4 -> V_7 ) ;
V_6 |= V_5 ;
F_7 ( V_6 , V_4 -> V_6 ) ;
F_11 ( V_4 -> V_14 , V_12 ) ;
}
return 0 ;
}
struct V_15 * F_12 ( const char * V_16 ,
const char * const * V_17 , T_2 V_18 ,
void T_3 * V_6 , int V_7 , int V_12 ,
T_4 * V_14 )
{
struct V_19 V_20 ;
struct V_3 * V_4 ;
struct V_15 * V_15 ;
V_4 = F_13 ( sizeof( * V_4 ) , V_21 ) ;
if ( ! V_4 )
return NULL ;
V_20 . V_16 = V_16 ;
V_20 . V_18 = V_18 ;
V_20 . V_12 = V_22 ;
V_20 . V_17 = V_17 ;
V_20 . V_23 = & V_24 ;
V_4 -> V_2 . V_20 = & V_20 ;
V_4 -> V_6 = V_6 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_14 = V_14 ;
V_15 = F_14 ( NULL , & V_4 -> V_2 ) ;
if ( F_15 ( V_15 ) )
goto V_25;
return V_15 ;
V_25:
F_16 ( V_4 ) ;
return NULL ;
}
