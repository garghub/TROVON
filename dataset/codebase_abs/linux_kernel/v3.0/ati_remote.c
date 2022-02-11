static void F_1 ( struct V_1 * V_2 , unsigned char * V_3 ,
unsigned int V_4 )
{
if ( ( V_4 == 1 ) && ( V_3 [ 0 ] != ( unsigned char ) 0xff ) && ( V_3 [ 0 ] != 0x00 ) )
F_2 ( V_2 , L_1 , V_3 [ 0 ] ) ;
else if ( V_4 == 4 )
F_2 ( V_2 , L_2 ,
V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] ) ;
else
F_2 ( V_2 , L_3 ,
V_4 , V_3 [ 0 ] , V_3 [ 1 ] , V_3 [ 2 ] , V_3 [ 3 ] , V_3 [ 4 ] , V_3 [ 5 ] ) ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_4 ( V_6 ) ;
V_7 -> V_8 -> V_2 = V_7 -> V_9 ;
if ( F_5 ( V_7 -> V_8 , V_10 ) ) {
F_6 ( & V_7 -> V_11 -> V_2 ,
L_4 , V_12 ) ;
return - V_13 ;
}
return 0 ;
}
static void F_7 ( struct V_5 * V_6 )
{
struct V_7 * V_7 = F_4 ( V_6 ) ;
F_8 ( V_7 -> V_8 ) ;
}
static void F_9 ( struct V_14 * V_14 )
{
struct V_7 * V_7 = V_14 -> V_15 ;
if ( V_14 -> V_16 ) {
F_10 ( & V_7 -> V_11 -> V_2 , L_5 ,
V_12 , V_14 -> V_16 ) ;
return;
}
V_7 -> V_17 |= V_18 ;
F_11 () ;
F_12 ( & V_7 -> V_19 ) ;
}
static int F_13 ( struct V_7 * V_7 , T_1 V_20 , unsigned char * V_3 )
{
int V_21 = 0 ;
memcpy ( V_7 -> V_22 -> V_23 + 1 , V_3 , F_14 ( V_20 ) ) ;
( ( char * ) V_7 -> V_22 -> V_23 ) [ 0 ] = F_15 ( V_20 ) ;
V_7 -> V_22 -> V_24 = F_14 ( V_20 ) + 1 ;
V_7 -> V_22 -> V_2 = V_7 -> V_9 ;
V_7 -> V_17 = V_25 ;
V_21 = F_5 ( V_7 -> V_22 , V_26 ) ;
if ( V_21 ) {
F_10 ( & V_7 -> V_11 -> V_2 ,
L_6 , V_21 ) ;
return V_21 ;
}
F_16 ( V_7 -> V_19 ,
( ( V_7 -> V_22 -> V_16 != - V_27 ) ||
( V_7 -> V_17 & V_18 ) ) ,
V_28 ) ;
F_8 ( V_7 -> V_22 ) ;
return V_21 ;
}
static int F_17 ( int V_29 , unsigned char V_30 , unsigned char V_31 )
{
int V_32 ;
for ( V_32 = 0 ; V_33 [ V_32 ] . V_34 != V_35 ; V_32 ++ ) {
if ( ( ( ( V_33 [ V_32 ] . V_36 & 0x0f ) == ( V_30 & 0x0f ) ) ) &&
( ( ( ( V_33 [ V_32 ] . V_36 >> 4 ) -
( V_30 >> 4 ) + V_29 ) & 0x0f ) == 0x0f ) &&
( V_33 [ V_32 ] . V_37 == V_31 ) )
return V_32 ;
}
return - 1 ;
}
static int F_18 ( struct V_7 * V_7 )
{
static const char V_38 [] = { 1 , 2 , 4 , 6 , 9 , 13 , 20 } ;
unsigned long V_39 = V_40 ;
int V_41 ;
if ( F_19 ( V_39 , V_7 -> V_42 + F_20 ( 250 ) ) ) {
V_41 = 1 ;
V_7 -> V_43 = V_39 ;
}
else if ( F_21 ( V_39 , V_7 -> V_43 + F_20 ( 125 ) ) )
V_41 = V_38 [ 0 ] ;
else if ( F_21 ( V_39 , V_7 -> V_43 + F_20 ( 250 ) ) )
V_41 = V_38 [ 1 ] ;
else if ( F_21 ( V_39 , V_7 -> V_43 + F_20 ( 500 ) ) )
V_41 = V_38 [ 2 ] ;
else if ( F_21 ( V_39 , V_7 -> V_43 + F_20 ( 1000 ) ) )
V_41 = V_38 [ 3 ] ;
else if ( F_21 ( V_39 , V_7 -> V_43 + F_20 ( 1500 ) ) )
V_41 = V_38 [ 4 ] ;
else if ( F_21 ( V_39 , V_7 -> V_43 + F_20 ( 2000 ) ) )
V_41 = V_38 [ 5 ] ;
else
V_41 = V_38 [ 6 ] ;
return V_41 ;
}
static void F_22 ( struct V_14 * V_14 )
{
struct V_7 * V_7 = V_14 -> V_15 ;
unsigned char * V_3 = V_7 -> V_44 ;
struct V_5 * V_2 = V_7 -> V_45 ;
int V_46 , V_41 ;
int V_47 ;
if ( ( V_14 -> V_48 != 4 ) || ( V_3 [ 0 ] != 0x14 ) ||
( ( V_3 [ 3 ] & 0x0f ) != 0x00 ) ) {
F_1 ( & V_14 -> V_2 -> V_2 , V_3 , V_14 -> V_48 ) ;
return;
}
V_47 = ( V_3 [ 3 ] >> 4 ) & 0x0f ;
if ( V_49 & ( 1 << ( V_47 + 1 ) ) ) {
F_23 ( & V_7 -> V_11 -> V_2 ,
L_7 ,
V_47 , V_3 [ 1 ] , V_3 [ 2 ] , V_49 ) ;
return;
}
V_46 = F_17 ( V_47 , V_3 [ 1 ] , V_3 [ 2 ] ) ;
if ( V_46 < 0 ) {
F_2 ( & V_7 -> V_11 -> V_2 ,
L_8 ,
V_47 , V_3 [ 1 ] , V_3 [ 2 ] ) ;
return;
}
F_23 ( & V_7 -> V_11 -> V_2 ,
L_9 ,
V_47 , V_3 [ 1 ] , V_3 [ 2 ] , V_46 , V_33 [ V_46 ] . V_50 ) ;
if ( V_33 [ V_46 ] . V_34 == V_51 ) {
F_24 ( V_2 , V_33 [ V_46 ] . type ,
V_33 [ V_46 ] . V_50 ,
V_33 [ V_46 ] . V_52 ) ;
F_25 ( V_2 ) ;
V_7 -> V_42 = V_40 ;
return;
}
if ( V_33 [ V_46 ] . V_34 == V_53 ) {
unsigned long V_39 = V_40 ;
if ( V_7 -> V_54 [ 0 ] == V_3 [ 1 ] &&
V_7 -> V_54 [ 1 ] == V_3 [ 2 ] &&
F_21 ( V_39 , V_7 -> V_42 +
F_20 ( V_55 ) ) ) {
V_7 -> V_56 ++ ;
} else {
V_7 -> V_56 = 0 ;
V_7 -> V_57 = V_39 ;
}
V_7 -> V_54 [ 0 ] = V_3 [ 1 ] ;
V_7 -> V_54 [ 1 ] = V_3 [ 2 ] ;
V_7 -> V_42 = V_39 ;
if ( V_7 -> V_56 > 0 &&
( V_7 -> V_56 < 5 ||
F_21 ( V_39 , V_7 -> V_57 +
F_20 ( V_58 ) ) ) )
return;
F_24 ( V_2 , V_33 [ V_46 ] . type ,
V_33 [ V_46 ] . V_50 , 1 ) ;
F_25 ( V_2 ) ;
F_24 ( V_2 , V_33 [ V_46 ] . type ,
V_33 [ V_46 ] . V_50 , 0 ) ;
F_25 ( V_2 ) ;
} else {
V_41 = F_18 ( V_7 ) ;
switch ( V_33 [ V_46 ] . V_34 ) {
case V_59 :
F_24 ( V_2 , V_33 [ V_46 ] . type ,
V_33 [ V_46 ] . V_50 ,
V_33 [ V_46 ] . V_52 * V_41 ) ;
break;
case V_60 :
F_26 ( V_2 , V_61 , - V_41 ) ;
F_26 ( V_2 , V_62 , - V_41 ) ;
break;
case V_63 :
F_26 ( V_2 , V_61 , V_41 ) ;
F_26 ( V_2 , V_62 , - V_41 ) ;
break;
case V_64 :
F_26 ( V_2 , V_61 , - V_41 ) ;
F_26 ( V_2 , V_62 , V_41 ) ;
break;
case V_65 :
F_26 ( V_2 , V_61 , V_41 ) ;
F_26 ( V_2 , V_62 , V_41 ) ;
break;
default:
F_10 ( & V_7 -> V_11 -> V_2 , L_10 ,
V_33 [ V_46 ] . V_34 ) ;
}
F_25 ( V_2 ) ;
V_7 -> V_42 = V_40 ;
V_7 -> V_54 [ 0 ] = V_3 [ 1 ] ;
V_7 -> V_54 [ 1 ] = V_3 [ 2 ] ;
}
}
static void F_27 ( struct V_14 * V_14 )
{
struct V_7 * V_7 = V_14 -> V_15 ;
int V_21 ;
switch ( V_14 -> V_16 ) {
case 0 :
F_22 ( V_14 ) ;
break;
case - V_66 :
case - V_67 :
case - V_68 :
F_10 ( & V_7 -> V_11 -> V_2 , L_11 ,
V_12 ) ;
return;
default:
F_10 ( & V_7 -> V_11 -> V_2 , L_12 ,
V_12 , V_14 -> V_16 ) ;
}
V_21 = F_5 ( V_14 , V_26 ) ;
if ( V_21 )
F_6 ( & V_7 -> V_11 -> V_2 , L_13 ,
V_12 , V_21 ) ;
}
static int F_28 ( struct V_69 * V_9 ,
struct V_7 * V_7 )
{
V_7 -> V_44 = F_29 ( V_9 , V_70 , V_26 ,
& V_7 -> V_71 ) ;
if ( ! V_7 -> V_44 )
return - 1 ;
V_7 -> V_72 = F_29 ( V_9 , V_70 , V_26 ,
& V_7 -> V_73 ) ;
if ( ! V_7 -> V_72 )
return - 1 ;
V_7 -> V_8 = F_30 ( 0 , V_10 ) ;
if ( ! V_7 -> V_8 )
return - 1 ;
V_7 -> V_22 = F_30 ( 0 , V_10 ) ;
if ( ! V_7 -> V_22 )
return - 1 ;
return 0 ;
}
static void F_31 ( struct V_7 * V_7 )
{
F_32 ( V_7 -> V_8 ) ;
F_32 ( V_7 -> V_22 ) ;
F_33 ( V_7 -> V_9 , V_70 ,
V_7 -> V_44 , V_7 -> V_71 ) ;
F_33 ( V_7 -> V_9 , V_70 ,
V_7 -> V_72 , V_7 -> V_73 ) ;
}
static void F_34 ( struct V_7 * V_7 )
{
struct V_5 * V_45 = V_7 -> V_45 ;
int V_32 ;
V_45 -> V_74 [ 0 ] = F_35 ( V_75 ) | F_35 ( V_76 ) ;
V_45 -> V_77 [ F_36 ( V_78 ) ] = F_35 ( V_79 ) |
F_35 ( V_80 ) | F_35 ( V_81 ) | F_35 ( V_82 ) ;
V_45 -> V_83 [ 0 ] = F_35 ( V_61 ) | F_35 ( V_62 ) ;
for ( V_32 = 0 ; V_33 [ V_32 ] . V_34 != V_35 ; V_32 ++ )
if ( V_33 [ V_32 ] . type == V_75 )
F_37 ( V_33 [ V_32 ] . V_50 , V_45 -> V_77 ) ;
F_38 ( V_45 , V_7 ) ;
V_45 -> V_84 = F_3 ;
V_45 -> V_85 = F_7 ;
V_45 -> V_86 = V_7 -> V_86 ;
V_45 -> V_87 = V_7 -> V_87 ;
F_39 ( V_7 -> V_9 , & V_45 -> V_88 ) ;
V_45 -> V_2 . V_89 = & V_7 -> V_9 -> V_2 ;
}
static int F_40 ( struct V_7 * V_7 )
{
struct V_69 * V_9 = V_7 -> V_9 ;
int V_90 , V_91 ;
F_41 ( & V_7 -> V_19 ) ;
V_90 = F_42 ( V_9 , V_7 -> V_92 -> V_93 ) ;
V_91 = F_43 ( V_9 , V_90 , F_44 ( V_90 ) ) ;
V_91 = ( V_91 > V_70 ) ? V_70 : V_91 ;
F_45 ( V_7 -> V_8 , V_9 , V_90 , V_7 -> V_44 ,
V_91 , F_27 , V_7 ,
V_7 -> V_92 -> V_94 ) ;
V_7 -> V_8 -> V_95 = V_7 -> V_71 ;
V_7 -> V_8 -> V_96 |= V_97 ;
V_90 = F_46 ( V_9 , V_7 -> V_98 -> V_93 ) ;
V_91 = F_43 ( V_9 , V_90 , F_44 ( V_90 ) ) ;
V_91 = ( V_91 > V_70 ) ? V_70 : V_91 ;
F_45 ( V_7 -> V_22 , V_9 , V_90 , V_7 -> V_72 ,
V_91 , F_9 , V_7 ,
V_7 -> V_98 -> V_94 ) ;
V_7 -> V_22 -> V_95 = V_7 -> V_73 ;
V_7 -> V_22 -> V_96 |= V_97 ;
if ( ( F_13 ( V_7 , 0x8004 , V_99 ) ) ||
( F_13 ( V_7 , 0x8007 , V_100 ) ) ) {
F_6 ( & V_7 -> V_11 -> V_2 ,
L_14 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_47 ( struct V_101 * V_11 , const struct V_102 * V_88 )
{
struct V_69 * V_9 = F_48 ( V_11 ) ;
struct V_103 * V_104 = V_11 -> V_105 ;
struct V_106 * V_92 , * V_98 ;
struct V_7 * V_7 ;
struct V_5 * V_5 ;
int V_107 = - V_108 ;
if ( V_104 -> V_109 . V_110 != 2 ) {
V_107 ( L_15 , V_12 ) ;
return - V_111 ;
}
V_92 = & V_104 -> V_112 [ 0 ] . V_109 ;
V_98 = & V_104 -> V_112 [ 1 ] . V_109 ;
if ( ! F_49 ( V_92 ) ) {
V_107 ( L_16 , V_12 ) ;
return - V_111 ;
}
if ( F_50 ( V_92 -> V_113 ) == 0 ) {
V_107 ( L_17 , V_12 ) ;
return - V_111 ;
}
V_7 = F_51 ( sizeof ( struct V_7 ) , V_10 ) ;
V_5 = F_52 () ;
if ( ! V_7 || ! V_5 )
goto V_114;
if ( F_28 ( V_9 , V_7 ) )
goto V_115;
V_7 -> V_92 = V_92 ;
V_7 -> V_98 = V_98 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_45 = V_5 ;
V_7 -> V_11 = V_11 ;
F_53 ( V_9 , V_7 -> V_87 , sizeof( V_7 -> V_87 ) ) ;
F_54 ( V_7 -> V_87 , L_18 , sizeof( V_7 -> V_87 ) ) ;
if ( V_9 -> V_116 )
F_55 ( V_7 -> V_86 , V_9 -> V_116 , sizeof( V_7 -> V_86 ) ) ;
if ( V_9 -> V_117 )
snprintf ( V_7 -> V_86 , sizeof( V_7 -> V_86 ) ,
L_19 , V_7 -> V_86 , V_9 -> V_117 ) ;
if ( ! strlen ( V_7 -> V_86 ) )
snprintf ( V_7 -> V_86 , sizeof( V_7 -> V_86 ) ,
V_118 L_20 ,
F_50 ( V_7 -> V_9 -> V_119 . V_120 ) ,
F_50 ( V_7 -> V_9 -> V_119 . V_121 ) ) ;
F_34 ( V_7 ) ;
V_107 = F_40 ( V_7 ) ;
if ( V_107 )
goto V_122;
V_107 = F_56 ( V_7 -> V_45 ) ;
if ( V_107 )
goto V_122;
F_57 ( V_11 , V_7 ) ;
return 0 ;
V_122: F_8 ( V_7 -> V_8 ) ;
F_8 ( V_7 -> V_22 ) ;
V_115: F_31 ( V_7 ) ;
V_114: F_58 ( V_5 ) ;
F_59 ( V_7 ) ;
return V_107 ;
}
static void F_60 ( struct V_101 * V_11 )
{
struct V_7 * V_7 ;
V_7 = F_61 ( V_11 ) ;
F_57 ( V_11 , NULL ) ;
if ( ! V_7 ) {
F_2 ( & V_11 -> V_2 , L_21 , V_12 ) ;
return;
}
F_8 ( V_7 -> V_8 ) ;
F_8 ( V_7 -> V_22 ) ;
F_62 ( V_7 -> V_45 ) ;
F_31 ( V_7 ) ;
F_59 ( V_7 ) ;
}
static int T_2 F_63 ( void )
{
int V_123 ;
V_123 = F_64 ( & V_124 ) ;
if ( V_123 )
F_65 (KERN_ERR KBUILD_MODNAME
L_22 , result) ;
else
F_65 (KERN_INFO KBUILD_MODNAME L_23 DRIVER_VERSION L_24
DRIVER_DESC L_25 ) ;
return V_123 ;
}
static void T_3 F_66 ( void )
{
F_67 ( & V_124 ) ;
}
