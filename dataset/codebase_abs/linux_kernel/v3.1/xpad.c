static void F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( ! ( V_2 -> V_7 & V_8 ) ) {
F_2 ( V_6 , V_9 ,
( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 12 ) ) ) ;
F_2 ( V_6 , V_12 ,
~ ( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 14 ) ) ) ;
F_2 ( V_6 , V_13 ,
( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 16 ) ) ) ;
F_2 ( V_6 , V_14 ,
~ ( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 18 ) ) ) ;
}
if ( V_2 -> V_7 & V_15 ) {
F_4 ( V_6 , V_16 , V_4 [ 10 ] ) ;
F_4 ( V_6 , V_17 , V_4 [ 11 ] ) ;
} else {
F_2 ( V_6 , V_18 , V_4 [ 10 ] ) ;
F_2 ( V_6 , V_19 , V_4 [ 11 ] ) ;
}
if ( V_2 -> V_7 & V_20 ) {
F_4 ( V_6 , V_21 , V_4 [ 2 ] & 0x04 ) ;
F_4 ( V_6 , V_22 , V_4 [ 2 ] & 0x08 ) ;
F_4 ( V_6 , V_23 , V_4 [ 2 ] & 0x01 ) ;
F_4 ( V_6 , V_24 , V_4 [ 2 ] & 0x02 ) ;
} else {
F_2 ( V_6 , V_25 ,
! ! ( V_4 [ 2 ] & 0x08 ) - ! ! ( V_4 [ 2 ] & 0x04 ) ) ;
F_2 ( V_6 , V_26 ,
! ! ( V_4 [ 2 ] & 0x02 ) - ! ! ( V_4 [ 2 ] & 0x01 ) ) ;
}
F_4 ( V_6 , V_27 , V_4 [ 2 ] & 0x10 ) ;
F_4 ( V_6 , V_28 , V_4 [ 2 ] & 0x20 ) ;
F_4 ( V_6 , V_29 , V_4 [ 2 ] & 0x40 ) ;
F_4 ( V_6 , V_30 , V_4 [ 2 ] & 0x80 ) ;
F_4 ( V_6 , V_31 , V_4 [ 4 ] ) ;
F_4 ( V_6 , V_32 , V_4 [ 5 ] ) ;
F_4 ( V_6 , V_33 , V_4 [ 6 ] ) ;
F_4 ( V_6 , V_34 , V_4 [ 7 ] ) ;
F_4 ( V_6 , V_35 , V_4 [ 8 ] ) ;
F_4 ( V_6 , V_36 , V_4 [ 9 ] ) ;
F_5 ( V_6 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned char * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_2 -> V_7 & V_20 ) {
F_4 ( V_6 , V_21 , V_4 [ 2 ] & 0x04 ) ;
F_4 ( V_6 , V_22 , V_4 [ 2 ] & 0x08 ) ;
F_4 ( V_6 , V_23 , V_4 [ 2 ] & 0x01 ) ;
F_4 ( V_6 , V_24 , V_4 [ 2 ] & 0x02 ) ;
} else {
F_2 ( V_6 , V_25 ,
! ! ( V_4 [ 2 ] & 0x08 ) - ! ! ( V_4 [ 2 ] & 0x04 ) ) ;
F_2 ( V_6 , V_26 ,
! ! ( V_4 [ 2 ] & 0x02 ) - ! ! ( V_4 [ 2 ] & 0x01 ) ) ;
}
F_4 ( V_6 , V_27 , V_4 [ 2 ] & 0x10 ) ;
F_4 ( V_6 , V_28 , V_4 [ 2 ] & 0x20 ) ;
F_4 ( V_6 , V_29 , V_4 [ 2 ] & 0x40 ) ;
F_4 ( V_6 , V_30 , V_4 [ 2 ] & 0x80 ) ;
F_4 ( V_6 , V_31 , V_4 [ 3 ] & 0x10 ) ;
F_4 ( V_6 , V_32 , V_4 [ 3 ] & 0x20 ) ;
F_4 ( V_6 , V_33 , V_4 [ 3 ] & 0x40 ) ;
F_4 ( V_6 , V_34 , V_4 [ 3 ] & 0x80 ) ;
F_4 ( V_6 , V_37 , V_4 [ 3 ] & 0x01 ) ;
F_4 ( V_6 , V_38 , V_4 [ 3 ] & 0x02 ) ;
F_4 ( V_6 , V_39 , V_4 [ 3 ] & 0x04 ) ;
if ( ! ( V_2 -> V_7 & V_8 ) ) {
F_2 ( V_6 , V_9 ,
( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 6 ) ) ) ;
F_2 ( V_6 , V_12 ,
~ ( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 8 ) ) ) ;
F_2 ( V_6 , V_13 ,
( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 10 ) ) ) ;
F_2 ( V_6 , V_14 ,
~ ( V_10 ) F_3 ( ( V_11 * ) ( V_4 + 12 ) ) ) ;
}
if ( V_2 -> V_7 & V_15 ) {
F_4 ( V_6 , V_16 , V_4 [ 4 ] ) ;
F_4 ( V_6 , V_17 , V_4 [ 5 ] ) ;
} else {
F_2 ( V_6 , V_18 , V_4 [ 4 ] ) ;
F_2 ( V_6 , V_19 , V_4 [ 5 ] ) ;
}
F_5 ( V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_3 , unsigned char * V_4 )
{
if ( V_4 [ 0 ] & 0x08 ) {
if ( V_4 [ 1 ] & 0x80 ) {
V_2 -> V_40 = 1 ;
F_8 ( V_2 -> V_41 , V_42 ) ;
} else
V_2 -> V_40 = 0 ;
}
if ( ! ( V_4 [ 1 ] & 0x1 ) )
return;
F_6 ( V_2 , V_3 , & V_4 [ 4 ] ) ;
}
static void F_9 ( struct V_43 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_44 ;
int V_45 , V_46 ;
V_46 = V_43 -> V_46 ;
switch ( V_46 ) {
case 0 :
break;
case - V_47 :
case - V_48 :
case - V_49 :
F_10 ( L_1 ,
V_50 , V_46 ) ;
return;
default:
F_10 ( L_2 ,
V_50 , V_46 ) ;
goto exit;
}
switch ( V_2 -> V_51 ) {
case V_52 :
F_6 ( V_2 , 0 , V_2 -> V_53 ) ;
break;
case V_54 :
F_7 ( V_2 , 0 , V_2 -> V_53 ) ;
break;
default:
F_1 ( V_2 , 0 , V_2 -> V_53 ) ;
}
exit:
V_45 = F_8 ( V_43 , V_42 ) ;
if ( V_45 )
F_11 ( L_3 ,
V_50 , V_45 ) ;
}
static void F_12 ( struct V_43 * V_43 )
{
switch ( V_43 -> V_46 ) {
case 0 :
break;
case - V_47 :
case - V_48 :
case - V_49 :
F_10 ( L_1 , V_50 , V_43 -> V_46 ) ;
break;
default:
F_10 ( L_2 , V_50 , V_43 -> V_46 ) ;
}
}
static void F_13 ( struct V_43 * V_43 )
{
int V_45 , V_46 ;
V_46 = V_43 -> V_46 ;
switch ( V_46 ) {
case 0 :
return;
case - V_47 :
case - V_48 :
case - V_49 :
F_10 ( L_1 , V_50 , V_46 ) ;
return;
default:
F_10 ( L_2 , V_50 , V_46 ) ;
goto exit;
}
exit:
V_45 = F_8 ( V_43 , V_42 ) ;
if ( V_45 )
F_11 ( L_3 ,
V_50 , V_45 ) ;
}
static int F_14 ( struct V_55 * V_56 , struct V_1 * V_2 )
{
struct V_57 * V_58 ;
int error ;
if ( V_2 -> V_51 == V_59 )
return 0 ;
V_2 -> V_60 = F_15 ( V_2 -> V_61 , V_62 ,
V_63 , & V_2 -> V_64 ) ;
if ( ! V_2 -> V_60 ) {
error = - V_65 ;
goto V_66;
}
F_16 ( & V_2 -> V_67 ) ;
V_2 -> V_68 = F_17 ( 0 , V_63 ) ;
if ( ! V_2 -> V_68 ) {
error = - V_65 ;
goto V_69;
}
V_58 = & V_56 -> V_70 -> V_71 [ 1 ] . V_72 ;
F_18 ( V_2 -> V_68 , V_2 -> V_61 ,
F_19 ( V_2 -> V_61 , V_58 -> V_73 ) ,
V_2 -> V_60 , V_62 ,
F_13 , V_2 , V_58 -> V_74 ) ;
V_2 -> V_68 -> V_75 = V_2 -> V_64 ;
V_2 -> V_68 -> V_76 |= V_77 ;
return 0 ;
V_69: F_20 ( V_2 -> V_61 , V_62 , V_2 -> V_60 , V_2 -> V_64 ) ;
V_66: return error ;
}
static void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_51 != V_59 )
F_22 ( V_2 -> V_68 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_51 != V_59 ) {
F_24 ( V_2 -> V_68 ) ;
F_20 ( V_2 -> V_61 , V_62 ,
V_2 -> V_60 , V_2 -> V_64 ) ;
}
}
static int F_14 ( struct V_55 * V_56 , struct V_1 * V_2 ) { return 0 ; }
static void F_23 ( struct V_1 * V_2 ) {}
static void F_21 ( struct V_1 * V_2 ) {}
static int F_25 ( struct V_5 * V_6 , void * V_4 , struct V_78 * V_79 )
{
struct V_1 * V_2 = F_26 ( V_6 ) ;
if ( V_79 -> type == V_80 ) {
T_2 V_81 = V_79 -> V_82 . V_83 . V_84 ;
T_2 V_85 = V_79 -> V_82 . V_83 . V_86 ;
switch ( V_2 -> V_51 ) {
case V_87 :
V_2 -> V_60 [ 0 ] = 0x00 ;
V_2 -> V_60 [ 1 ] = 0x06 ;
V_2 -> V_60 [ 2 ] = 0x00 ;
V_2 -> V_60 [ 3 ] = V_81 / 256 ;
V_2 -> V_60 [ 4 ] = 0x00 ;
V_2 -> V_60 [ 5 ] = V_85 / 256 ;
V_2 -> V_68 -> V_88 = 6 ;
return F_8 ( V_2 -> V_68 , V_42 ) ;
case V_52 :
V_2 -> V_60 [ 0 ] = 0x00 ;
V_2 -> V_60 [ 1 ] = 0x08 ;
V_2 -> V_60 [ 2 ] = 0x00 ;
V_2 -> V_60 [ 3 ] = V_81 / 256 ;
V_2 -> V_60 [ 4 ] = V_85 / 256 ;
V_2 -> V_60 [ 5 ] = 0x00 ;
V_2 -> V_60 [ 6 ] = 0x00 ;
V_2 -> V_60 [ 7 ] = 0x00 ;
V_2 -> V_68 -> V_88 = 8 ;
return F_8 ( V_2 -> V_68 , V_42 ) ;
case V_54 :
V_2 -> V_60 [ 0 ] = 0x00 ;
V_2 -> V_60 [ 1 ] = 0x01 ;
V_2 -> V_60 [ 2 ] = 0x0F ;
V_2 -> V_60 [ 3 ] = 0xC0 ;
V_2 -> V_60 [ 4 ] = 0x00 ;
V_2 -> V_60 [ 5 ] = V_81 / 256 ;
V_2 -> V_60 [ 6 ] = V_85 / 256 ;
V_2 -> V_60 [ 7 ] = 0x00 ;
V_2 -> V_60 [ 8 ] = 0x00 ;
V_2 -> V_60 [ 9 ] = 0x00 ;
V_2 -> V_60 [ 10 ] = 0x00 ;
V_2 -> V_60 [ 11 ] = 0x00 ;
V_2 -> V_68 -> V_88 = 12 ;
return F_8 ( V_2 -> V_68 , V_42 ) ;
default:
F_10 ( L_4 ,
V_50 , V_2 -> V_51 ) ;
return - 1 ;
}
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
if ( V_2 -> V_51 == V_59 )
return 0 ;
F_28 ( V_2 -> V_6 , V_89 , V_80 ) ;
return F_29 ( V_2 -> V_6 , NULL , F_25 ) ;
}
static int F_27 ( struct V_1 * V_2 ) { return 0 ; }
static void F_30 ( struct V_1 * V_2 , int V_90 )
{
if ( V_90 >= 0 && V_90 < 14 ) {
F_31 ( & V_2 -> V_67 ) ;
V_2 -> V_60 [ 0 ] = 0x01 ;
V_2 -> V_60 [ 1 ] = 0x03 ;
V_2 -> V_60 [ 2 ] = V_90 ;
V_2 -> V_68 -> V_88 = 3 ;
F_8 ( V_2 -> V_68 , V_63 ) ;
F_32 ( & V_2 -> V_67 ) ;
}
}
static void F_33 ( struct V_91 * V_92 ,
enum V_93 V_94 )
{
struct V_95 * V_95 = F_34 ( V_92 ,
struct V_95 , V_92 ) ;
F_30 ( V_95 -> V_2 , V_94 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
static T_3 V_96 = F_36 ( 0 ) ;
long V_97 ;
struct V_95 * V_98 ;
struct V_91 * V_92 ;
int error ;
if ( V_2 -> V_51 != V_52 )
return 0 ;
V_2 -> V_98 = V_98 = F_37 ( sizeof( struct V_95 ) , V_63 ) ;
if ( ! V_98 )
return - V_65 ;
V_97 = ( long ) F_38 ( & V_96 ) - 1 ;
snprintf ( V_98 -> V_99 , sizeof( V_98 -> V_99 ) , L_5 , V_97 ) ;
V_98 -> V_2 = V_2 ;
V_92 = & V_98 -> V_92 ;
V_92 -> V_99 = V_98 -> V_99 ;
V_92 -> V_100 = F_33 ;
error = F_39 ( & V_2 -> V_61 -> V_6 , V_92 ) ;
if ( error ) {
F_40 ( V_98 ) ;
V_2 -> V_98 = NULL ;
return error ;
}
F_30 ( V_2 , ( V_97 % 4 ) + 2 ) ;
return 0 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_95 * V_95 = V_2 -> V_98 ;
if ( V_95 ) {
F_42 ( & V_95 -> V_92 ) ;
F_40 ( V_95 ) ;
}
}
static int F_35 ( struct V_1 * V_2 ) { return 0 ; }
static void F_41 ( struct V_1 * V_2 ) { }
static int F_43 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_26 ( V_6 ) ;
if( V_2 -> V_51 == V_54 )
return 0 ;
V_2 -> V_101 -> V_6 = V_2 -> V_61 ;
if ( F_8 ( V_2 -> V_101 , V_63 ) )
return - V_102 ;
return 0 ;
}
static void F_44 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_26 ( V_6 ) ;
if ( V_2 -> V_51 != V_54 )
F_22 ( V_2 -> V_101 ) ;
F_21 ( V_2 ) ;
}
static void F_45 ( struct V_5 * V_5 , signed short abs )
{
F_46 ( abs , V_5 -> V_103 ) ;
switch ( abs ) {
case V_9 :
case V_12 :
case V_13 :
case V_14 :
F_47 ( V_5 , abs , - 32768 , 32767 , 16 , 128 ) ;
break;
case V_18 :
case V_19 :
F_47 ( V_5 , abs , 0 , 255 , 0 , 0 ) ;
break;
case V_25 :
case V_26 :
F_47 ( V_5 , abs , - 1 , 1 , 0 , 0 ) ;
break;
}
}
static int F_48 ( struct V_55 * V_56 , const struct V_104 * V_105 )
{
struct V_106 * V_61 = F_49 ( V_56 ) ;
struct V_1 * V_2 ;
struct V_5 * V_5 ;
struct V_57 * V_107 ;
int V_108 , error ;
for ( V_108 = 0 ; V_109 [ V_108 ] . V_110 ; V_108 ++ ) {
if ( ( F_50 ( V_61 -> V_111 . V_110 ) == V_109 [ V_108 ] . V_110 ) &&
( F_50 ( V_61 -> V_111 . V_112 ) == V_109 [ V_108 ] . V_112 ) )
break;
}
V_2 = F_37 ( sizeof( struct V_1 ) , V_63 ) ;
V_5 = F_51 () ;
if ( ! V_2 || ! V_5 ) {
error = - V_65 ;
goto V_66;
}
V_2 -> V_53 = F_15 ( V_61 , V_62 ,
V_63 , & V_2 -> V_113 ) ;
if ( ! V_2 -> V_53 ) {
error = - V_65 ;
goto V_66;
}
V_2 -> V_101 = F_17 ( 0 , V_63 ) ;
if ( ! V_2 -> V_101 ) {
error = - V_65 ;
goto V_69;
}
V_2 -> V_61 = V_61 ;
V_2 -> V_7 = V_109 [ V_108 ] . V_7 ;
V_2 -> V_51 = V_109 [ V_108 ] . V_51 ;
if ( V_2 -> V_51 == V_59 ) {
if ( V_56 -> V_70 -> V_72 . V_114 == V_115 ) {
if ( V_56 -> V_70 -> V_72 . V_116 == 129 )
V_2 -> V_51 = V_54 ;
else
V_2 -> V_51 = V_52 ;
} else
V_2 -> V_51 = V_87 ;
if ( V_117 )
V_2 -> V_7 |= V_20 ;
if ( V_118 )
V_2 -> V_7 |= V_15 ;
if ( V_119 )
V_2 -> V_7 |= V_8 ;
}
V_2 -> V_6 = V_5 ;
F_52 ( V_61 , V_2 -> V_120 , sizeof( V_2 -> V_120 ) ) ;
F_53 ( V_2 -> V_120 , L_6 , sizeof( V_2 -> V_120 ) ) ;
V_5 -> V_99 = V_109 [ V_108 ] . V_99 ;
V_5 -> V_120 = V_2 -> V_120 ;
F_54 ( V_61 , & V_5 -> V_105 ) ;
V_5 -> V_6 . V_121 = & V_56 -> V_6 ;
F_55 ( V_5 , V_2 ) ;
V_5 -> V_122 = F_43 ;
V_5 -> V_123 = F_44 ;
V_5 -> V_124 [ 0 ] = F_56 ( V_125 ) ;
if ( ! ( V_2 -> V_7 & V_8 ) ) {
V_5 -> V_124 [ 0 ] |= F_56 ( V_126 ) ;
for ( V_108 = 0 ; V_127 [ V_108 ] >= 0 ; V_108 ++ )
F_45 ( V_5 , V_127 [ V_108 ] ) ;
}
for ( V_108 = 0 ; V_128 [ V_108 ] >= 0 ; V_108 ++ )
F_57 ( V_128 [ V_108 ] , V_5 -> V_129 ) ;
if ( V_2 -> V_51 == V_52 || V_2 -> V_51 == V_54 ) {
for ( V_108 = 0 ; V_130 [ V_108 ] >= 0 ; V_108 ++ )
F_57 ( V_130 [ V_108 ] , V_5 -> V_129 ) ;
} else {
for ( V_108 = 0 ; V_131 [ V_108 ] >= 0 ; V_108 ++ )
F_57 ( V_131 [ V_108 ] , V_5 -> V_129 ) ;
}
if ( V_2 -> V_7 & V_20 ) {
for ( V_108 = 0 ; V_132 [ V_108 ] >= 0 ; V_108 ++ )
F_57 ( V_132 [ V_108 ] , V_5 -> V_129 ) ;
} else {
for ( V_108 = 0 ; V_133 [ V_108 ] >= 0 ; V_108 ++ )
F_45 ( V_5 , V_133 [ V_108 ] ) ;
}
if ( V_2 -> V_7 & V_15 ) {
for ( V_108 = 0 ; V_134 [ V_108 ] >= 0 ; V_108 ++ )
F_57 ( V_134 [ V_108 ] , V_5 -> V_129 ) ;
} else {
for ( V_108 = 0 ; V_135 [ V_108 ] >= 0 ; V_108 ++ )
F_45 ( V_5 , V_135 [ V_108 ] ) ;
}
error = F_14 ( V_56 , V_2 ) ;
if ( error )
goto V_136;
error = F_27 ( V_2 ) ;
if ( error )
goto V_137;
error = F_35 ( V_2 ) ;
if ( error )
goto V_138;
V_107 = & V_56 -> V_70 -> V_71 [ 0 ] . V_72 ;
F_18 ( V_2 -> V_101 , V_61 ,
F_58 ( V_61 , V_107 -> V_73 ) ,
V_2 -> V_53 , V_62 , F_9 ,
V_2 , V_107 -> V_74 ) ;
V_2 -> V_101 -> V_75 = V_2 -> V_113 ;
V_2 -> V_101 -> V_76 |= V_77 ;
error = F_59 ( V_2 -> V_6 ) ;
if ( error )
goto V_139;
F_60 ( V_56 , V_2 ) ;
if ( V_2 -> V_51 == V_54 ) {
V_2 -> V_41 = F_17 ( 0 , V_63 ) ;
if ( ! V_2 -> V_41 ) {
error = - V_65 ;
goto V_140;
}
V_2 -> V_141 = F_37 ( V_62 , V_63 ) ;
if ( ! V_2 -> V_141 ) {
error = - V_65 ;
goto V_142;
}
V_2 -> V_141 [ 2 ] = 0x08 ;
switch ( V_56 -> V_70 -> V_72 . V_143 ) {
case 0 :
V_2 -> V_141 [ 3 ] = 0x42 ;
break;
case 2 :
V_2 -> V_141 [ 3 ] = 0x43 ;
break;
case 4 :
V_2 -> V_141 [ 3 ] = 0x44 ;
break;
case 6 :
V_2 -> V_141 [ 3 ] = 0x45 ;
}
V_107 = & V_56 -> V_70 -> V_71 [ 1 ] . V_72 ;
F_61 ( V_2 -> V_41 , V_61 ,
F_62 ( V_61 , V_107 -> V_73 ) ,
V_2 -> V_141 , V_62 , F_12 , V_2 ) ;
V_2 -> V_101 -> V_6 = V_2 -> V_61 ;
error = F_8 ( V_2 -> V_101 , V_63 ) ;
if ( error )
goto V_144;
}
return 0 ;
V_144: F_40 ( V_2 -> V_141 ) ;
V_142: F_24 ( V_2 -> V_41 ) ;
V_140: F_63 ( V_5 ) ;
V_5 = NULL ;
V_139: F_41 ( V_2 ) ;
V_138: if ( V_5 )
F_64 ( V_5 ) ;
V_137: F_23 ( V_2 ) ;
V_136: F_24 ( V_2 -> V_101 ) ;
V_69: F_20 ( V_61 , V_62 , V_2 -> V_53 , V_2 -> V_113 ) ;
V_66: F_65 ( V_5 ) ;
F_40 ( V_2 ) ;
return error ;
}
static void F_66 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_67 ( V_56 ) ;
F_41 ( V_2 ) ;
F_63 ( V_2 -> V_6 ) ;
F_23 ( V_2 ) ;
if ( V_2 -> V_51 == V_54 ) {
F_22 ( V_2 -> V_41 ) ;
F_24 ( V_2 -> V_41 ) ;
F_22 ( V_2 -> V_101 ) ;
}
F_24 ( V_2 -> V_101 ) ;
F_20 ( V_2 -> V_61 , V_62 ,
V_2 -> V_53 , V_2 -> V_113 ) ;
F_40 ( V_2 -> V_141 ) ;
F_40 ( V_2 ) ;
F_60 ( V_56 , NULL ) ;
}
static int T_4 F_68 ( void )
{
return F_69 ( & V_145 ) ;
}
static void T_5 F_70 ( void )
{
F_71 ( & V_145 ) ;
}
