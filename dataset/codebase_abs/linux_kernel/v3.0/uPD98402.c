static int F_1 ( struct V_1 * V_2 , struct V_3 T_1 * V_4 , int V_5 )
{
struct V_3 V_6 ;
int error = 0 ;
F_2 ( F_3 ( V_7 ) , & F_4 ( V_2 ) -> V_3 . V_8 ) ;
F_5 ( & F_4 ( V_2 ) -> V_3 , & V_6 ) ;
if ( V_4 ) error = F_6 ( V_4 , & V_6 , sizeof( V_6 ) ) ;
if ( V_5 && ! error ) {
V_6 . V_9 = V_6 . V_10 = V_6 . V_11 = 0 ;
F_7 ( & F_4 ( V_2 ) -> V_3 , & V_6 ) ;
}
return error ? - V_12 : 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned char V_13 )
{
static const unsigned char V_14 [] = { 1 , 2 , 3 , 0 } ;
static const unsigned char V_15 [] = { 1 , 0 , 0 , 2 } ;
const char * V_16 ;
unsigned long V_17 ;
switch ( V_13 ) {
case V_18 :
V_16 = V_14 ;
break;
case V_19 :
V_16 = V_15 ;
break;
default:
return - V_20 ;
}
F_9 ( & F_4 ( V_2 ) -> V_21 , V_17 ) ;
F_10 ( V_16 [ 0 ] , V_22 ) ;
F_10 ( V_16 [ 1 ] , V_23 ) ;
F_10 ( V_16 [ 2 ] , V_24 ) ;
F_10 ( ( F_3 ( V_25 ) & ~ V_26 ) | ( V_16 [ 3 ] <<
V_27 ) , V_25 ) ;
F_11 ( & F_4 ( V_2 ) -> V_21 , V_17 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_2 T_1 * V_4 )
{
unsigned long V_17 ;
unsigned char V_28 [ 3 ] ;
F_9 ( & F_4 ( V_2 ) -> V_21 , V_17 ) ;
V_28 [ 0 ] = F_3 ( V_29 ) ;
V_28 [ 1 ] = F_3 ( V_30 ) ;
V_28 [ 2 ] = F_3 ( V_31 ) ;
F_11 ( & F_4 ( V_2 ) -> V_21 , V_17 ) ;
return ( F_13 ( V_28 [ 0 ] , V_4 ) || F_13 ( V_28 [ 1 ] , V_4 + 1 ) ||
F_13 ( V_28 [ 2 ] , V_4 + 2 ) || F_13 ( 0xff , V_4 + 3 ) ||
F_13 ( 0xff , V_4 + 4 ) || F_13 ( 0xff , V_4 + 5 ) ) ? - V_12 : 0 ;
}
static int F_14 ( struct V_1 * V_2 , int V_32 )
{
unsigned char V_33 ;
V_33 = F_3 ( V_25 ) & ~ ( V_34 | V_35 |
V_36 ) ;
switch ( F_15 ( V_32 ) ) {
case V_37 :
break;
case V_38 :
V_33 |= V_34 ;
break;
case V_39 :
V_33 |= V_35 ;
break;
default:
return - V_20 ;
}
switch ( F_16 ( V_32 ) ) {
case V_37 :
break;
case V_38 :
V_33 |= V_36 ;
break;
default:
return - V_20 ;
}
F_10 ( V_33 , V_25 ) ;
F_4 ( V_2 ) -> V_40 = V_32 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned int V_41 , void T_1 * V_4 )
{
switch ( V_41 ) {
case V_42 :
case V_43 :
return F_1 ( V_2 , V_4 , V_41 == V_42 ) ;
case V_44 :
return F_8 ( V_2 , ( int ) ( unsigned long ) V_4 ) ;
case V_45 :
return F_13 ( F_4 ( V_2 ) -> V_13 , ( int T_1 * ) V_4 ) ?
- V_12 : 0 ;
case V_46 :
return F_12 ( V_2 , V_4 ) ;
case V_47 :
return F_14 ( V_2 , ( int ) ( unsigned long ) V_4 ) ;
case V_48 :
return F_13 ( F_4 ( V_2 ) -> V_40 , ( int T_1 * ) V_4 ) ?
- V_12 : 0 ;
case V_49 :
return F_13 ( V_50 | V_51 |
V_52 , ( int T_1 * ) V_4 ) ? - V_12 : 0 ;
default:
return - V_53 ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
unsigned char V_54 ;
V_54 = F_3 ( V_55 ) ;
if ( V_54 & V_56 ) F_19 ( V_57 , V_58 ) ;
if ( V_54 & V_59 ) F_19 ( V_60 , V_61 ) ;
if ( V_54 & V_62 ) F_19 ( V_63 , V_64 ) ;
if ( V_54 & V_65 ) F_19 ( V_66 , V_67 ) ;
if ( V_54 & V_68 ) F_19 ( V_69 , V_70 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
static unsigned long V_71 = 0 ;
unsigned char V_72 ;
while ( ( V_72 = F_3 ( V_73 ) ) ) {
if ( V_72 & V_74 )
F_21 ( V_75 L_1 ,
V_2 -> type , V_2 -> V_76 ) ;
if ( V_72 & V_77 ) F_18 ( V_2 ) ;
if ( V_72 & V_78 ) {
( void ) F_3 ( V_79 ) ;
F_2 ( F_3 ( V_7 ) ,
& F_4 ( V_2 ) -> V_3 . V_8 ) ;
}
if ( ( V_72 & V_80 ) &&
( F_22 ( V_81 , V_71 ) || V_71 == 0 ) ) {
F_21 ( V_82 L_2
L_3 , V_2 -> type , V_2 -> V_76 ) ;
V_71 = ( V_81 + V_83 / 2 ) | 1 ;
}
}
}
static int F_23 ( struct V_1 * V_2 )
{
F_24 ( L_4 ) ;
if ( ! ( V_2 -> V_84 = F_25 ( sizeof( struct V_85 ) , V_86 ) ) )
return - V_87 ;
F_26 ( & F_4 ( V_2 ) -> V_21 ) ;
memset ( & F_4 ( V_2 ) -> V_3 , 0 , sizeof( struct V_88 ) ) ;
( void ) F_3 ( V_55 ) ;
F_10 ( V_89 , V_90 ) ;
( void ) F_3 ( V_79 ) ;
F_10 ( ~ V_91 , V_92 ) ;
( void ) F_3 ( V_73 ) ;
F_10 ( ~ ( V_77 | V_93 | V_80 |
V_74 ) , V_94 ) ;
( void ) F_1 ( V_2 , NULL , 1 ) ;
F_27 ( & F_4 ( V_2 ) -> V_3 . V_9 , - 1 ) ;
F_27 ( & F_4 ( V_2 ) -> V_3 . V_10 , - 1 ) ;
F_27 ( & F_4 ( V_2 ) -> V_3 . V_11 , - 1 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
F_29 ( F_4 ( V_2 ) ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_2 )
{
F_24 ( L_5 ) ;
V_2 -> V_95 = & V_96 ;
return 0 ;
}
static T_3 int F_31 ( void )
{
return 0 ;
}
