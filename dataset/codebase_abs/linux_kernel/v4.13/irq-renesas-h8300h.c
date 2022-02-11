static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = V_2 -> V_4 - 12 ;
V_3 = V_5 [ V_4 ] ;
if ( V_3 >= 0 ) {
if ( V_3 < 8 )
F_2 ( V_3 & 7 , V_6 ) ;
else
F_2 ( V_3 & 7 , ( V_6 + 1 ) ) ;
}
}
static void F_3 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = V_2 -> V_4 - 12 ;
V_3 = V_5 [ V_4 ] ;
if ( V_3 >= 0 ) {
if ( V_3 < 8 )
F_4 ( V_3 & 7 , V_6 ) ;
else
F_4 ( V_3 & 7 , ( V_6 + 1 ) ) ;
}
}
static int F_5 ( struct V_7 * V_8 , unsigned int V_9 ,
T_1 V_10 )
{
F_6 ( V_9 , & V_11 , V_12 ) ;
return 0 ;
}
static int T_2 F_7 ( struct V_13 * V_14 ,
struct V_13 * V_15 )
{
struct V_7 * V_16 ;
V_17 = F_8 ( V_14 , 0 ) ;
F_9 ( ! V_17 ) ;
F_10 ( 0x00 , V_6 + 0 ) ;
F_10 ( 0x00 , V_6 + 1 ) ;
V_16 = F_11 ( V_14 , V_18 , & V_19 , NULL ) ;
F_9 ( ! V_16 ) ;
F_12 ( V_16 ) ;
return 0 ;
}
