static int F_1 ( void )
{
return ! ! ( ( F_2 () & 0xffffffe0 ) == 0x69052e20 ) ;
}
static int F_3 ( void )
{
if ( F_4 () || V_1 )
return 1 ;
else
return 0 ;
}
static void T_1 F_5 ( void )
{
if ( F_3 () ) {
F_6 ( 200000000 ) ;
} else {
F_6 ( 198000000 ) ;
}
}
void T_1 F_7 ( void )
{
F_8 () ;
F_9 ( V_2 , F_10 ( V_2 ) ) ;
}
static int T_1
F_11 ( const struct V_3 * V_4 , T_2 V_5 , T_2 V_6 )
{
int V_7 ;
if ( V_5 == 0 ) {
V_7 = V_8 ;
} else if ( V_5 == 1 ) {
V_7 = V_9 ;
} else if ( V_5 == 2 ) {
V_7 = V_10 ;
} else if ( V_5 == 3 ) {
V_7 = V_11 ;
} else {
F_12 ( V_12 L_1
L_2 , V_4 -> V_13 -> V_14 ,
F_13 ( V_4 -> V_15 ) , F_14 ( V_4 -> V_15 ) ) ;
V_7 = - 1 ;
}
return V_7 ;
}
static int T_1
F_15 ( const struct V_3 * V_4 , T_2 V_5 , T_2 V_6 )
{
int V_7 ;
if ( V_5 == 0 ) {
V_7 = V_8 ;
} else if ( V_5 == 1 ) {
V_7 = V_11 ;
} else if ( V_5 == 2 ) {
V_7 = V_10 ;
} else if ( V_5 == 3 ) {
V_7 = V_9 ;
} else {
F_12 ( V_12 L_3
L_2 , V_4 -> V_13 -> V_14 ,
F_13 ( V_4 -> V_15 ) , F_14 ( V_4 -> V_15 ) ) ;
V_7 = - 1 ;
}
return V_7 ;
}
static int T_1 F_16 ( void )
{
if ( F_3 () )
F_17 ( & V_16 ) ;
else if ( F_18 () ) {
if ( F_1 () ) {
F_12 ( L_4 ) ;
F_12 ( L_5 ) ;
F_12 ( L_6
L_7 ) ;
F_12 ( L_8
L_9 , V_17 ) ;
}
F_17 ( & V_18 ) ;
}
return 0 ;
}
void F_19 ( void )
{
* V_19 = 0x60 ;
* V_20 = 0xE9 ;
F_20 ( 1 ) ;
* V_19 = 0x0F ;
* V_20 = 0xE8 ;
F_20 ( 1 ) ;
* V_19 = 0x03 ;
* V_20 = 0xE8 ;
F_20 ( 1 ) ;
* V_19 = 0x00 ;
* V_20 = 0xEA ;
while ( 1 )
;
}
static void T_1 F_21 ( void )
{
F_22 () ;
F_23 ( & V_21 ) ;
F_23 ( & V_22 ) ;
F_23 ( & V_23 ) ;
F_23 ( & V_24 ) ;
F_23 ( & V_25 ) ;
F_23 ( & V_26 ) ;
if ( F_3 () )
V_27 = F_19 ;
if ( ! F_1 () )
F_23 ( & V_28 ) ;
}
static int T_1 F_24 ( char * V_29 )
{
V_1 = 1 ;
return 1 ;
}
