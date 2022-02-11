static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 = F_2 ( V_2 , 6 ) ;
if ( V_5 == 0 ) {
F_3 ( V_2 , 0 , V_6 , 5 ) ;
F_4 ( V_2 , F_5 ( V_3 ) ) ;
F_4 ( V_2 , F_6 ( V_3 ) ) ;
F_4 ( V_2 , V_4 ) ;
F_4 ( V_2 , V_7 ) ;
F_4 ( V_2 , 0x00000000 ) ;
F_7 ( V_2 ) ;
}
return V_5 ;
}
static int
F_8 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int V_5 = F_2 ( V_2 , 5 ) ;
if ( V_5 == 0 ) {
F_3 ( V_2 , 0 , V_6 , 4 ) ;
F_4 ( V_2 , F_5 ( V_3 ) ) ;
F_4 ( V_2 , F_6 ( V_3 ) ) ;
F_4 ( V_2 , V_4 ) ;
F_4 ( V_2 , V_8 |
V_9 ) ;
F_7 ( V_2 ) ;
}
return V_5 ;
}
static int
F_9 ( struct V_1 * V_2 )
{
int V_5 = F_10 ( V_2 ) ;
if ( V_5 == 0 ) {
struct V_10 * V_11 = V_2 -> V_12 ;
V_11 -> V_13 . V_14 = F_1 ;
V_11 -> V_13 . V_15 = F_8 ;
}
return V_5 ;
}
int
F_11 ( struct V_16 * V_17 )
{
int V_5 = F_12 ( V_17 ) ;
if ( V_5 == 0 ) {
struct V_18 * V_19 = V_17 -> V_12 ;
V_19 -> V_13 . V_20 = F_9 ;
}
return V_5 ;
}
