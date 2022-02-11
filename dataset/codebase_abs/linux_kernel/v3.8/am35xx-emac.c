static void F_1 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 |= ( V_3 | V_4 |
V_5 | V_6 ) ;
F_3 ( V_1 , V_2 ) ;
F_2 ( V_2 ) ;
}
static void F_4 ( void )
{
T_1 V_1 ;
V_1 = F_2 ( V_2 ) ;
V_1 |= ( V_3 | V_4 ) ;
F_3 ( V_1 , V_2 ) ;
F_2 ( V_2 ) ;
}
static int T_2 F_5 ( struct V_7 * V_8 ,
void * V_9 , int V_10 )
{
struct V_11 * V_12 ;
V_12 = F_6 ( V_8 -> V_13 -> V_14 , 0 , V_8 , V_9 , V_10 ,
NULL , 0 , false ) ;
if ( F_7 ( V_12 ) ) {
F_8 ( 1 , L_1 ,
V_8 -> V_13 -> V_14 , V_8 -> V_14 ) ;
return F_9 ( V_12 ) ;
}
return 0 ;
}
void T_2 F_10 ( unsigned long V_15 , T_3 V_16 )
{
struct V_7 * V_8 ;
T_1 V_1 ;
int V_17 ;
V_8 = F_11 ( L_2 ) ;
if ( ! V_8 ) {
F_12 ( L_3 ) ;
return;
}
V_18 . V_19 = V_15 ;
V_17 = F_5 ( V_8 , & V_18 ,
sizeof( V_18 ) ) ;
if ( V_17 ) {
F_12 ( L_4 ) ;
return;
}
V_8 = F_11 ( L_5 ) ;
if ( ! V_8 ) {
F_12 ( L_6 ) ;
return;
}
V_20 . V_16 = V_16 ;
V_17 = F_5 ( V_8 , & V_20 ,
sizeof( V_20 ) ) ;
if ( V_17 ) {
F_12 ( L_7 ) ;
return;
}
V_1 = F_2 ( V_21 ) ;
V_1 &= ~ V_22 ;
F_3 ( V_1 , V_21 ) ;
F_2 ( V_21 ) ;
}
