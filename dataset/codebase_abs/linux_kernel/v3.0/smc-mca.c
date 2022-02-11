static int T_1 F_1 ( struct V_1 * V_2 )
{
unsigned short V_3 ;
struct V_4 * V_5 ;
unsigned char V_6 , V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
char V_10 = V_9 -> V_10 ;
unsigned char V_11 = 0xff , V_12 = 0xff , V_13 = 0xff , V_14 = 0xff ;
int V_15 , V_16 ;
int V_17 = V_9 -> V_18 ;
int V_19 = 0 ;
int V_20 = 0 ;
int V_21 = V_22 [ V_23 ] ;
int V_24 = V_25 [ V_23 ] ;
if ( V_21 || V_24 ) {
F_3 ( V_26 L_1 ) ;
if ( V_21 ) {
F_3 ( V_26 L_2 ,
V_21 , V_24 ? ' ' : '\n' ) ;
}
if ( V_24 ) {
F_3 ( V_26 L_3 , V_24 ) ;
}
}
V_20 = 0 ;
V_19 = 0 ;
V_11 = F_4 ( V_9 , 2 ) ;
V_12 = F_4 ( V_9 , 3 ) ;
V_13 = F_4 ( V_9 , 4 ) ;
V_14 = F_4 ( V_9 , 5 ) ;
switch ( V_9 -> V_18 ) {
case V_27 :
case V_28 :
case V_29 :
case V_30 :
{
V_19 = V_31 [ ( V_11 & 0xf0 ) >> 4 ] . V_21 ;
V_20 = V_32 [ ( V_14 & 0xc ) >> 2 ] . V_33 ;
break;
}
case V_34 :
case V_35 :
case V_36 :
case V_37 :
{
V_19 = ( ( V_11 & 0x0fe ) * 0x10 ) ;
V_20 = V_32 [ ( V_14 & 3 ) ] . V_38 ;
break;
}
}
if( ! V_20 || ! V_19 ||
( V_24 && V_24 != V_20 ) ||
( V_21 && V_19 != V_21 ) )
return - V_39 ;
V_5 = F_5 () ;
if( ! V_5 )
return - V_40 ;
F_6 ( V_5 , V_2 ) ;
F_7 ( V_9 , V_41 [ V_17 ] ) ;
F_8 ( V_9 , 1 ) ;
F_3 ( V_26 L_4 ,
V_41 [ V_17 ] , V_10 + 1 ) ;
V_23 ++ ;
V_5 -> V_21 = V_3 = F_9 ( V_9 , V_19 ) ;
V_5 -> V_24 = F_10 ( V_9 , V_20 ) ;
V_5 -> V_42 = 0 ;
V_7 = 40 ;
switch ( V_17 ) {
case V_27 :
case V_28 :
{
for ( V_15 = 0 ; V_15 < 16 ; V_15 ++ ) {
if ( V_43 [ V_15 ] . V_44 == ( V_12 & ~ V_45 ) ) {
V_5 -> V_42 = ( unsigned long )
F_11 ( V_9 , ( void * ) V_43 [ V_15 ] . V_42 ) ;
V_7 = V_43 [ V_15 ] . V_7 ;
}
}
break;
}
case V_34 :
case V_35 :
case V_36 :
case V_37 :
{
V_5 -> V_42 = ( unsigned long )
F_11 ( V_9 , ( void * ) ( ( V_12 & 0xfc ) * 0x1000 ) ) ;
V_7 = 0x40 ;
break;
}
case V_29 :
case V_30 :
{
V_5 -> V_42 = ( unsigned long )
F_11 ( V_9 , ( void * ) ( 0xc0000 + ( 0x2000 * ( V_12 & 0xf ) ) ) ) ;
V_7 = 0x20 + ( 2 * ( V_12 & 0x10 ) ) ;
break;
}
}
if ( V_5 -> V_42 == 0 ) {
V_16 = - V_40 ;
goto V_46;
}
if ( ! F_12 ( V_3 , V_47 , V_48 ) ) {
V_16 = - V_40 ;
goto V_46;
}
V_6 = F_13 ( V_3 + 4 ) & 0x7f ;
F_14 ( V_6 , V_3 + 4 ) ;
for ( V_15 = 0 ; V_15 < 6 ; V_15 ++ )
V_5 -> V_49 [ V_15 ] = F_13 ( V_3 + 8 + V_15 ) ;
F_3 ( V_26 L_5 ,
V_10 + 1 , V_3 , V_5 -> V_49 ) ;
F_14 ( 0x80 | V_6 , V_3 + 4 ) ;
F_14 ( 0x80 | F_13 ( V_3 + 0x0c ) , V_3 + 0x0c ) ;
F_14 ( V_6 , V_3 + 4 ) ;
F_15 ( V_2 , V_5 ) ;
V_5 -> V_21 = V_3 + V_50 ;
V_51 . V_52 = L_6 ;
V_51 . V_53 = 1 ;
V_51 . V_54 = V_55 ;
V_51 . V_56 = V_55 + V_57 ;
V_51 . V_58 = V_7 ;
V_51 . V_59 = F_16 ( V_5 -> V_42 , ( V_51 . V_58 - V_55 ) * 256 ) ;
if ( ! V_51 . V_59 ) {
V_16 = - V_60 ;
goto V_61;
}
V_5 -> V_62 = V_5 -> V_42 + ( V_51 . V_58 - V_55 ) * 256 ;
F_3 ( L_7 ,
V_5 -> V_24 , V_5 -> V_42 , V_5 -> V_62 - 1 ) ;
V_51 . V_63 = & V_64 ;
V_51 . V_65 = & V_66 ;
V_51 . V_67 = & V_68 ;
V_51 . V_69 = & V_70 ;
V_51 . V_71 = V_10 ;
V_5 -> V_72 = & V_73 ;
F_17 ( V_5 , 0 ) ;
V_16 = F_18 ( V_5 ) ;
if ( V_16 )
goto V_74;
return 0 ;
V_74:
F_19 ( V_51 . V_59 ) ;
V_61:
F_20 ( V_3 , V_47 ) ;
V_46:
F_8 ( V_9 , 0 ) ;
F_21 ( V_5 ) ;
return V_16 ;
}
static int F_22 ( struct V_4 * V_5 )
{
int V_3 = V_5 -> V_21 - V_50 ;
int V_75 ;
if ( ( V_75 = F_23 ( V_5 -> V_24 , V_76 , 0 , V_5 -> V_52 , V_5 ) ) )
return V_75 ;
F_14 ( V_77 , V_3 ) ;
F_14 ( 0x80 , V_3 + 5 ) ;
F_14 ( 0x01 , V_3 + 6 ) ;
F_14 ( 0x04 , V_3 + 5 ) ;
F_24 ( V_5 ) ;
return 0 ;
}
static void V_64 ( struct V_4 * V_5 )
{
int V_3 = V_5 -> V_21 - V_50 ;
F_14 ( V_78 , V_3 ) ;
if ( V_79 > 1 )
F_3 ( L_8 , V_80 ) ;
V_51 . V_81 = 0 ;
F_14 ( 0x80 , V_3 + 5 ) ;
F_14 ( 0x01 , V_3 + 6 ) ;
if ( V_79 > 1 )
F_3 ( L_9 ) ;
}
static void V_70 ( struct V_4 * V_5 , struct V_82 * V_83 , int V_84 )
{
void T_2 * V_85 = V_51 . V_59 + ( ( V_84 - V_55 ) << 8 ) ;
#ifdef F_25
F_26 ( V_83 , V_85 , sizeof( struct V_82 ) ) ;
#else
( ( unsigned int * ) V_83 ) [ 0 ] = F_27 ( V_85 ) ;
#endif
}
static void V_66 ( struct V_4 * V_5 , int V_86 , struct V_87 * V_88 , int V_89 )
{
void T_2 * V_90 = V_51 . V_59 + V_89 - V_55 * 256 ;
if ( V_89 + V_86 > V_51 . V_58 * 256 ) {
int V_91 = V_51 . V_58 * 256 - V_89 ;
F_26 ( V_88 -> V_92 , V_90 , V_91 ) ;
V_86 -= V_91 ;
F_26 ( V_88 -> V_92 + V_91 , V_51 . V_59 + V_57 * 256 , V_86 ) ;
} else {
F_26 ( V_88 -> V_92 , V_90 , V_86 ) ;
}
}
static void V_68 ( struct V_4 * V_5 , int V_86 , const unsigned char * V_93 ,
int V_94 )
{
void T_2 * V_95 = V_51 . V_59 + ( ( V_94 - V_55 ) << 8 ) ;
F_28 ( V_95 , V_93 , V_86 ) ;
}
static int F_29 ( struct V_4 * V_5 )
{
int V_3 = V_5 -> V_21 - V_50 ;
F_30 ( V_5 ) ;
if ( V_79 > 1 )
F_3 ( L_10 , V_5 -> V_52 ) ;
F_14 ( 0x00 , V_3 + 6 ) ;
F_31 ( V_5 -> V_24 , V_5 ) ;
F_17 ( V_5 , 0 ) ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
struct V_4 * V_5 = F_33 ( V_2 ) ;
if ( V_5 ) {
int V_3 = V_5 -> V_21 - V_50 ;
F_34 ( V_5 ) ;
F_8 ( V_9 , 0 ) ;
F_20 ( V_3 , V_47 ) ;
F_19 ( V_51 . V_59 ) ;
F_21 ( V_5 ) ;
}
return 0 ;
}
static int T_1 F_35 ( void )
{
if( ! V_96 )
return - V_39 ;
F_36 ( & V_97 ) ;
return V_23 ? 0 : - V_39 ;
}
static void T_3 F_37 ( void )
{
F_38 ( & V_97 ) ;
}
