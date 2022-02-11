static void F_1 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_3 , T_2 * V_4 , T_2 * V_5 , T_2 * V_6 )
{
int V_7 ;
int V_8 = 1 ;
int V_9 = 1 ;
V_7 = F_2 ( * V_1 , 6000000 ) ;
if ( V_7 > 255 ) {
V_8 = 0 ;
V_7 = ( V_7 + 1 ) / 2 ;
}
if ( V_7 > 255 ) {
V_9 = 0 ;
V_7 = ( V_7 + 1 ) / 2 ;
}
if ( V_7 > 255 )
V_7 = 255 ;
else if ( V_7 < 12 )
V_7 = 12 ;
* V_1 = ( ( 24000000 * V_7 ) >> V_9 ) / ( V_8 + 1 ) ;
if ( V_3 == NULL )
return;
* V_3 = V_7 ;
* V_5 = V_8 ;
* V_6 = V_9 ;
}
static void T_3 F_3 ( struct V_10 * V_11 )
{
void T_4 * V_12 ;
V_12 = F_4 ( V_11 , 0 , F_5 ( V_11 ) ) ;
if ( F_6 ( V_12 ) ) {
F_7 ( L_1 ,
V_11 -> V_13 ) ;
return;
}
F_8 ( V_11 , & V_14 ,
& V_15 , V_12 ) ;
}
static void F_9 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_7 , T_2 * V_4 , T_2 * V_8 , T_2 * V_9 )
{
T_1 div ;
if ( V_2 < * V_1 )
* V_1 = V_2 ;
div = F_2 ( V_2 , * V_1 ) ;
if ( div > 4 )
div = 4 ;
* V_1 = V_2 / div ;
if ( ! V_8 )
return;
* V_8 = div ;
}
static void T_3 F_10 ( struct V_10 * V_11 )
{
void T_4 * V_12 ;
struct V_16 * V_17 ;
V_12 = F_4 ( V_11 , 0 , F_5 ( V_11 ) ) ;
if ( F_6 ( V_12 ) ) {
F_7 ( L_2 ,
V_11 -> V_13 ) ;
return;
}
V_17 = F_8 ( V_11 , & V_18 ,
& V_19 , V_12 ) ;
F_11 ( V_17 ) ;
F_12 ( V_17 ) ;
}
static void F_13 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_7 , T_2 * V_4 , T_2 * V_8 , T_2 * V_9 )
{
T_1 V_20 ;
if ( V_2 < * V_1 )
* V_1 = V_2 ;
V_20 = F_14 ( F_2 ( V_2 , * V_1 ) ) ;
if ( V_20 > 3 )
V_20 = 3 ;
* V_1 = V_2 >> V_20 ;
if ( ! V_9 )
return;
* V_9 = V_20 ;
}
static void T_3 F_15 ( struct V_10 * V_11 )
{
void T_4 * V_12 ;
V_12 = F_4 ( V_11 , 0 , F_5 ( V_11 ) ) ;
if ( F_6 ( V_12 ) ) {
F_7 ( L_3 ,
V_11 -> V_13 ) ;
return;
}
F_8 ( V_11 , & V_21 ,
& V_22 , V_12 ) ;
}
static void T_3 F_16 ( struct V_10 * V_11 )
{
void T_4 * V_12 ;
V_12 = F_4 ( V_11 , 0 , F_5 ( V_11 ) ) ;
if ( F_6 ( V_12 ) ) {
F_7 ( L_4 ,
V_11 -> V_13 ) ;
return;
}
F_8 ( V_11 , & V_23 ,
& V_24 , V_12 ) ;
}
static void F_17 ( T_1 * V_1 , T_1 V_2 ,
T_2 * V_7 , T_2 * V_4 , T_2 * V_8 , T_2 * V_9 )
{
T_1 div ;
T_2 V_25 , V_26 ;
if ( V_2 < * V_1 )
* V_1 = V_2 ;
div = F_2 ( V_2 , * V_1 ) ;
if ( div > 256 )
div = 256 ;
V_26 = F_14 ( div ) ;
V_25 = ( V_2 >> V_26 ) - 1 ;
* V_1 = ( V_2 >> V_26 ) / ( V_25 + 1 ) ;
if ( V_7 == NULL )
return;
* V_8 = V_25 ;
* V_9 = V_26 ;
}
static void T_3 F_18 ( struct V_10 * V_11 )
{
void T_4 * V_12 ;
V_12 = F_4 ( V_11 , 0 , F_5 ( V_11 ) ) ;
if ( F_6 ( V_12 ) ) {
F_7 ( L_5 ,
V_11 -> V_13 ) ;
return;
}
F_8 ( V_11 , & V_27 ,
& V_28 , V_12 ) ;
}
