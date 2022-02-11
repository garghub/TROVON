const char * F_1 ( void )
{
return L_1 ;
}
void T_1 F_2 ( void )
{
T_2 V_1 ;
F_3 ( V_2 ,
V_2 + V_3 ) ;
F_4 () ;
V_1 = F_5 ( V_4 ) ;
F_6 () ;
V_1 |= V_5 | V_6 ;
F_7 ( V_1 , V_4 ) ;
F_8 ( V_7 , 0 ) ;
F_9 ( V_8 L_2 ) ;
}
static int F_10 ( const struct V_9 * V_10 , T_3 V_11 , T_3 V_12 )
{
if ( ( V_11 < 12 ) || ( V_11 > 13 ) || V_12 == 0 )
return - 1 ;
if ( V_11 == 12 ) {
switch ( V_12 ) {
case 1 : return V_13 ;
case 2 : return V_14 ;
case 3 : return V_15 ;
case 4 : return V_16 ;
}
}
if ( V_11 == 13 ) {
switch ( V_12 ) {
case 1 : return V_16 ;
case 2 : return V_13 ;
case 3 : return V_14 ;
case 4 : return V_15 ;
}
}
return - 1 ;
}
static void T_1 F_11 ( void )
{
int V_17 = ( F_5 ( V_18 ) & ( 0x7 << 1 ) ) |
( ( F_12 ( V_19 ) >> 6 ) & 0x1 ) ;
switch ( V_17 ) {
case 0 :
case 2 :
case 8 :
case 0xC :
case 0xD :
V_20 . V_21 = 1 ;
case 1 :
case 9 :
case 3 :
case 0xE :
case 0xF :
F_13 ( & V_22 ) ;
}
}
static int T_1 F_14 ( void )
{
int V_23 ;
F_15 ( V_24 , V_25 ) ;
F_15 ( V_26 , V_25 ) ;
F_15 ( V_27 , V_28 ) ;
F_16 ( 201 ) ;
F_16 ( 202 ) ;
F_17 (
V_29 ,
V_29 + 0x000400000 - 1 ,
V_30 ,
V_30 + 0x000400000 - 1 ,
V_31 ,
V_31 + 0x000010000 - 1 ,
V_27 , V_24 , 0 , 0 , 0 ) ;
F_17 (
V_29 + 0x008000000 ,
V_29 + 0x008400000 - 1 ,
V_30 + 0x008000000 ,
V_30 + 0x008400000 - 1 ,
V_31 + 0x008000000 ,
V_31 + 0x008010000 - 1 ,
V_27 , V_26 , 0 , 0 , 1 ) ;
F_18 ( 206 ) ;
F_11 () ;
V_23 = F_12 ( V_19 ) & V_32 ;
F_19 ( 128 * 1024 * 1024 , 4 , V_23 ) ;
F_13 ( & V_33 ) ;
F_13 ( & V_34 ) ;
return 0 ;
}
