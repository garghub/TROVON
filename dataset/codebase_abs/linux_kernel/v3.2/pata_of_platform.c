static int T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
struct V_8 V_9 ;
struct V_8 V_10 ;
struct V_8 V_11 ;
unsigned int V_12 = 0 ;
int V_13 = 0 ;
int V_14 ;
const T_2 * V_15 ;
V_3 = F_2 ( V_5 , 0 , & V_9 ) ;
if ( V_3 ) {
F_3 ( & V_2 -> V_6 , L_1
L_2 ) ;
return - V_16 ;
}
if ( F_4 ( V_5 , L_3 ) ) {
V_10 = V_9 ;
V_10 . V_17 = V_10 . V_17 + 0x3f6 ;
V_9 . V_18 = V_10 . V_17 - 1 ;
} else {
V_3 = F_2 ( V_5 , 1 , & V_10 ) ;
if ( V_3 ) {
F_3 ( & V_2 -> V_6 , L_4
L_2 ) ;
return - V_16 ;
}
}
V_3 = F_5 ( V_5 , 0 , & V_11 ) ;
if ( ! V_3 )
V_11 . V_17 = V_11 . V_18 = 0 ;
else
V_11 . V_19 = 0 ;
V_15 = F_6 ( V_5 , L_5 , NULL ) ;
if ( V_15 )
V_12 = F_7 ( V_15 ) ;
V_15 = F_6 ( V_5 , L_6 , NULL ) ;
if ( V_15 ) {
V_13 = F_7 ( V_15 ) ;
if ( V_13 > 6 ) {
F_3 ( & V_2 -> V_6 , L_7 ) ;
return - V_16 ;
}
} else {
F_8 ( & V_2 -> V_6 , L_8 ) ;
}
V_14 = 1 << V_13 ;
V_14 |= ( 1 << V_13 ) - 1 ;
return F_9 ( & V_2 -> V_6 , & V_9 , & V_10 , & V_11 ,
V_12 , V_14 ) ;
}
static int T_3 F_10 ( struct V_1 * V_2 )
{
return F_11 ( & V_2 -> V_6 ) ;
}
static int T_4 F_12 ( void )
{
return F_13 ( & V_20 ) ;
}
static void T_5 F_14 ( void )
{
F_15 ( & V_20 ) ;
}
