static unsigned int F_1 ( unsigned long V_1 )
{
unsigned long V_2 ;
unsigned int V_3 = ( V_1 >> 24 ) & 0xff ;
if ( F_2 ( V_4 ) ) {
F_3 ( V_5 , V_2 ) ;
V_3 |= ( V_2 << 2 ) & 0xff00 ;
}
return V_3 ;
}
static unsigned long F_4 ( unsigned int V_3 )
{
unsigned long V_1 ;
V_1 = ( ( V_3 & 0xffU ) << 24 ) ;
return V_1 ;
}
static unsigned int F_5 ( unsigned long V_1 )
{
T_1 V_6 ;
F_3 ( V_7 , V_6 ) ;
return ( ( V_6 >> ( 28 - 8 ) ) & 0xfff00 ) | ( V_1 >> 24 ) ;
}
static unsigned long F_6 ( unsigned int V_3 )
{
return V_3 << 24 ;
}
static int F_7 ( int V_8 )
{
return 1 ;
}
static int F_8 ( void )
{
return 1 ;
}
static int F_9 ( int V_9 , int V_10 )
{
return V_9 >> V_10 ;
}
static void F_10 ( int V_8 , unsigned int V_11 )
{
F_11 ( V_12 , ( V_8 << 16 ) | V_11 ) ;
}
static void F_12 ( int V_8 , unsigned int V_11 )
{
F_13 ( V_13 , ( V_8 << 12 ) | V_11 ) ;
}
static int F_14 ( int V_14 , unsigned long V_15 )
{
F_15 ( V_14 , V_16 ) ;
F_15 ( V_14 , V_17 |
( V_15 >> 12 ) ) ;
return 0 ;
}
static void F_16 ( int V_18 , int V_19 )
{
int V_20 , V_8 = F_17 ( V_21 , V_18 ) ;
unsigned int V_22 ;
F_18 () ;
V_20 = F_19 ( V_21 ) ;
if ( ! ( ( V_8 ^ V_20 ) >> V_23 ) ) {
unsigned long V_24 ;
F_20 ( V_24 ) ;
F_21 ( V_8 , V_19 ,
V_25 ) ;
F_22 ( V_24 ) ;
F_23 () ;
return;
}
F_23 () ;
V_22 = ( V_19 == V_26 ) ? V_27 : V_28 ;
F_15 ( V_8 , V_22 | V_19 ) ;
}
static void F_24 ( const struct V_29 * V_30 , int V_19 )
{
unsigned int V_18 ;
F_25 (cpu, mask)
F_16 ( V_18 , V_19 ) ;
}
static void F_26 ( const struct V_29 * V_30 ,
int V_19 )
{
unsigned int V_31 = F_27 () ;
unsigned int V_18 ;
F_25 (cpu, mask) {
if ( V_18 != V_31 )
F_16 ( V_18 , V_19 ) ;
}
}
static void F_28 ( int V_19 )
{
unsigned int V_31 = F_27 () ;
unsigned int V_18 ;
F_29 (cpu) {
if ( V_18 != V_31 )
F_16 ( V_18 , V_19 ) ;
}
}
static void F_30 ( int V_19 )
{
F_24 ( V_32 , V_19 ) ;
}
static void F_31 ( int V_19 )
{
F_32 ( V_33 , V_19 ) ;
}
static int T_2 F_33 ( void )
{
return V_34 == & V_35 ;
}
static int T_2 F_34 ( void )
{
return V_34 == & V_36 ;
}
static void F_35 ( struct V_37 * V_38 , int V_39 )
{
T_1 V_11 ;
T_3 V_40 = 1 ;
F_36 ( V_41 , V_39 ) ;
if ( F_2 ( V_4 ) ) {
F_3 ( V_5 , V_11 ) ;
V_40 = ( ( V_11 >> 3 ) & 7 ) + 1 ;
}
V_38 -> V_42 = V_39 / V_40 ;
}
static int T_2 F_37 ( void )
{
switch ( V_43 ) {
case 1 :
F_38 ( V_44 , V_45 ) ;
F_15 = F_10 ;
break;
case 2 :
F_38 ( V_46 , V_47 ) ;
F_15 = F_12 ;
break;
default:
return 0 ;
}
V_48 . F_35 = F_35 ;
V_49 . V_50 . V_51 = V_52 ;
return 0 ;
}
static int F_39 ( char * V_53 , char * V_54 )
{
if ( ( strncmp ( V_53 , L_1 , 6 ) != 0 ) ||
( strncmp ( V_54 , L_2 , 8 ) != 0 ) )
return 0 ;
V_43 = 1 ;
return 1 ;
}
static int F_40 ( char * V_53 , char * V_54 )
{
if ( ( strncmp ( V_53 , L_1 , 6 ) != 0 ) ||
( strncmp ( V_54 , L_3 , 8 ) != 0 ) )
return 0 ;
V_43 = 2 ;
return 1 ;
}
static void F_41 ( void )
{
}
static T_3 F_42 ( void )
{
return 0 ;
}
