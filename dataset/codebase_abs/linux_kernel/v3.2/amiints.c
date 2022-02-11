static void F_1 ( struct V_1 * V_2 )
{
V_3 . V_4 = V_5 | ( 1 << ( V_2 -> V_6 - V_7 ) ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
V_3 . V_4 = 1 << ( V_2 -> V_6 - V_7 ) ;
}
static void F_3 ( unsigned int V_6 , struct V_8 * V_9 )
{
unsigned short V_10 = V_3 . V_11 & V_3 . V_12 ;
if ( V_10 & V_13 ) {
V_3 . V_14 = V_13 ;
F_4 ( V_15 ) ;
}
if ( V_10 & V_16 ) {
V_3 . V_14 = V_16 ;
F_4 ( V_17 ) ;
}
if ( V_10 & V_18 ) {
V_3 . V_14 = V_18 ;
F_4 ( V_19 ) ;
}
}
static void F_5 ( unsigned int V_6 , struct V_8 * V_9 )
{
unsigned short V_10 = V_3 . V_11 & V_3 . V_12 ;
if ( V_10 & V_20 ) {
V_3 . V_14 = V_20 ;
F_4 ( V_21 ) ;
}
if ( V_10 & V_22 ) {
V_3 . V_14 = V_22 ;
F_4 ( V_23 ) ;
}
if ( V_10 & V_24 ) {
V_3 . V_14 = V_24 ;
F_4 ( V_25 ) ;
}
}
static void F_6 ( unsigned int V_6 , struct V_8 * V_9 )
{
unsigned short V_10 = V_3 . V_11 & V_3 . V_12 ;
if ( V_10 & V_26 ) {
V_3 . V_14 = V_26 ;
F_4 ( V_27 ) ;
}
if ( V_10 & V_28 ) {
V_3 . V_14 = V_28 ;
F_4 ( V_29 ) ;
}
if ( V_10 & V_30 ) {
V_3 . V_14 = V_30 ;
F_4 ( V_31 ) ;
}
if ( V_10 & V_32 ) {
V_3 . V_14 = V_32 ;
F_4 ( V_33 ) ;
}
}
static void F_7 ( unsigned int V_6 , struct V_8 * V_9 )
{
unsigned short V_10 = V_3 . V_11 & V_3 . V_12 ;
if ( V_10 & V_34 ) {
F_4 ( V_35 ) ;
}
if ( V_10 & V_36 ) {
V_3 . V_14 = V_36 ;
F_4 ( V_37 ) ;
}
}
void T_1 F_8 ( void )
{
F_9 ( & V_38 , V_39 , V_7 ,
V_40 ) ;
F_10 ( V_41 , F_3 ) ;
F_10 ( V_42 , F_5 ) ;
F_10 ( V_43 , F_6 ) ;
F_10 ( V_44 , F_7 ) ;
if ( F_11 ( V_45 ) )
V_46 . V_47 = V_48 ;
V_3 . V_4 = 0x7fff ;
V_3 . V_14 = 0x7fff ;
V_3 . V_4 = V_5 | V_49 ;
F_12 ( & V_50 ) ;
F_12 ( & V_51 ) ;
}
