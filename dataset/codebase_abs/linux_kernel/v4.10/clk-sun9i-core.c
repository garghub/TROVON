static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = 1 ;
int V_5 = 1 ;
V_3 = F_2 ( V_2 -> V_6 , 6000000 ) ;
if ( V_3 > 255 ) {
V_4 = 0 ;
V_3 = ( V_3 + 1 ) / 2 ;
}
if ( V_3 > 255 ) {
V_5 = 0 ;
V_3 = ( V_3 + 1 ) / 2 ;
}
if ( V_3 > 255 )
V_3 = 255 ;
else if ( V_3 < 12 )
V_3 = 12 ;
V_2 -> V_6 = ( ( 24000000 * V_3 ) >> V_5 ) / ( V_4 + 1 ) ;
V_2 -> V_3 = V_3 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
}
static void T_1 F_3 ( struct V_7 * V_8 )
{
void T_2 * V_9 ;
V_9 = F_4 ( V_8 , 0 , F_5 ( V_8 ) ) ;
if ( F_6 ( V_9 ) ) {
F_7 ( L_1 ,
V_8 -> V_10 ) ;
return;
}
F_8 ( V_8 , & V_11 ,
& V_12 , V_9 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
T_3 div ;
if ( V_2 -> V_13 < V_2 -> V_6 )
V_2 -> V_6 = V_2 -> V_13 ;
div = F_2 ( V_2 -> V_13 , V_2 -> V_6 ) ;
if ( div > 4 )
div = 4 ;
V_2 -> V_6 = V_2 -> V_13 / div ;
V_2 -> V_4 = div ;
}
static void T_1 F_10 ( struct V_7 * V_8 )
{
void T_2 * V_9 ;
struct V_14 * V_15 ;
V_9 = F_4 ( V_8 , 0 , F_5 ( V_8 ) ) ;
if ( F_6 ( V_9 ) ) {
F_7 ( L_2 ,
V_8 -> V_10 ) ;
return;
}
V_15 = F_8 ( V_8 , & V_16 ,
& V_17 , V_9 ) ;
F_11 ( V_15 ) ;
F_12 ( V_15 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_3 V_18 ;
if ( V_2 -> V_13 < V_2 -> V_6 )
V_2 -> V_6 = V_2 -> V_13 ;
V_18 = F_14 ( F_2 ( V_2 -> V_13 , V_2 -> V_6 ) ) ;
if ( V_18 > 3 )
V_18 = 3 ;
V_2 -> V_6 = V_2 -> V_13 >> V_18 ;
V_2 -> V_5 = V_18 ;
}
static void T_1 F_15 ( struct V_7 * V_8 )
{
void T_2 * V_9 ;
V_9 = F_4 ( V_8 , 0 , F_5 ( V_8 ) ) ;
if ( F_6 ( V_9 ) ) {
F_7 ( L_3 ,
V_8 -> V_10 ) ;
return;
}
F_8 ( V_8 , & V_19 ,
& V_20 , V_9 ) ;
}
static void T_1 F_16 ( struct V_7 * V_8 )
{
void T_2 * V_9 ;
V_9 = F_4 ( V_8 , 0 , F_5 ( V_8 ) ) ;
if ( F_6 ( V_9 ) ) {
F_7 ( L_4 ,
V_8 -> V_10 ) ;
return;
}
F_8 ( V_8 , & V_21 ,
& V_22 , V_9 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
T_3 div ;
if ( V_2 -> V_13 < V_2 -> V_6 )
V_2 -> V_6 = V_2 -> V_13 ;
div = F_2 ( V_2 -> V_13 , V_2 -> V_6 ) ;
if ( div > 256 )
div = 256 ;
V_2 -> V_5 = F_14 ( div ) ;
V_2 -> V_4 = ( V_2 -> V_13 >> V_2 -> V_5 ) - 1 ;
V_2 -> V_6 = ( V_2 -> V_13 >> V_2 -> V_5 ) / ( V_2 -> V_4 + 1 ) ;
}
static void T_1 F_18 ( struct V_7 * V_8 )
{
void T_2 * V_9 ;
V_9 = F_4 ( V_8 , 0 , F_5 ( V_8 ) ) ;
if ( F_6 ( V_9 ) ) {
F_7 ( L_5 ,
V_8 -> V_10 ) ;
return;
}
F_8 ( V_8 , & V_23 ,
& V_24 , V_9 ) ;
}
