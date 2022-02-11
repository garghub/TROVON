static int F_1 ( const struct V_1 * V_2 , const char * V_3 , T_1 V_4 )
{
const struct V_1 * V_5 ;
if ( V_3 [ V_4 - 1 ] == '\n' )
V_4 -- ;
for ( V_5 = V_2 ; V_5 -> string ; V_5 ++ )
if ( ! strncmp ( V_3 , V_5 -> string , V_4 ) )
return V_5 -> V_6 ;
return V_7 ;
}
static const char * F_2 ( const struct V_1 * V_2 , int V_8 )
{
const struct V_1 * V_5 ;
for ( V_5 = V_2 ; V_5 -> V_6 != V_7 ; V_5 ++ )
if ( V_8 == V_5 -> V_6 )
return V_5 -> string ;
return L_1 ;
}
static void F_3 ( struct V_9 * V_9 )
{
struct V_10 * V_10 = V_9 -> V_11 ;
unsigned char * V_12 = V_10 -> V_12 ;
struct V_13 * V_14 = V_10 -> V_14 ;
struct V_15 * V_16 = V_10 -> V_16 ;
int V_17 = 0 ;
int V_18 , V_19 , V_20 , V_21 , V_22 , V_23 , V_24 , V_25 , V_5 , V_26 , V_27 , V_28 , V_29 ;
switch ( V_9 -> V_30 ) {
case 0 :
break;
case - V_31 :
case - V_32 :
case - V_33 :
F_4 ( & V_16 -> V_34 , L_2 ,
V_35 , V_9 -> V_30 ) ;
return;
default:
F_4 ( & V_16 -> V_34 , L_3 ,
V_35 , V_9 -> V_30 ) ;
goto exit;
}
if ( V_10 -> V_36 == 1 && F_5 ( V_10 -> V_37 , V_38 ) ) {
goto exit;
}
V_10 -> V_36 = 0 ;
V_10 -> V_39 ++ ;
if ( V_12 [ 0 ] == 1 ) {
if ( V_10 -> V_40 . V_41 ==
V_42 ) {
V_10 -> V_43 =
V_44 ;
} else {
V_20 = ( signed char ) V_12 [ 2 ] ;
V_21 = ( signed char ) V_12 [ 3 ] ;
V_17 = V_12 [ 1 ] & 0x07 ;
V_23 = ( V_12 [ 1 ] & V_10 -> V_40 . V_45 >> 2 ) != 0 ? 1 : 0 ;
V_24 = ( V_12 [ 1 ] & V_10 -> V_40 . V_46 >> 2 ) != 0 ? 1 : 0 ;
V_25 = ( V_12 [ 1 ] & V_10 -> V_40 . V_47 >> 2 ) != 0 ? 1 : 0 ;
F_6 ( V_14 , V_48 , V_23 ) ;
F_6 ( V_14 , V_49 , V_25 ) ;
F_6 ( V_14 , V_50 , V_24 ) ;
F_7 ( V_14 , V_51 ,
1 | V_52 ) ;
F_8 ( V_14 , V_53 , V_20 ) ;
F_8 ( V_14 , V_54 , V_21 ) ;
if ( V_10 -> V_40 . V_55 != V_56 ) {
F_8 ( V_14 , V_57 ,
V_10 -> V_40 . V_55 ) ;
V_10 -> V_40 . V_55 = V_56 ;
}
if ( V_10 -> V_58 != - 1 ) {
F_6 ( V_14 ,
V_59 [ V_10 -> V_58 ] , 0 ) ;
V_10 -> V_58 = - 1 ;
}
F_9 ( V_14 ) ;
}
}
else if ( V_12 [ 0 ] == 2 ) {
if ( V_10 -> V_40 . V_41 == V_60 ) {
V_10 -> V_43 = V_61 ;
} else if ( ! F_10
( V_10 -> V_40 . V_62 ) ) {
V_10 -> V_43 = V_63 ;
} else {
V_20 = F_11 ( V_12 + 1 ) ;
V_21 = F_11 ( V_12 + 3 ) ;
V_22 = F_11 ( V_12 + 6 ) ;
V_26 = ( V_12 [ 5 ] & 0x01 ) != 0 ? 1 : 0 ;
V_5 = ( V_12 [ 5 ] & 0x02 ) != 0 ? 1 : 0 ;
V_27 = ( V_12 [ 5 ] & 0x04 ) != 0 ? 1 : 0 ;
V_17 = V_12 [ 5 ] & 0x18 ;
V_28 = ( V_12 [ 5 ] & V_10 -> V_40 . V_64 ) != 0 ? 1 : 0 ;
V_29 = ( V_12 [ 5 ] & V_10 -> V_40 . V_65 ) != 0 ? 1 : 0 ;
if ( V_26 != 0 ) {
if ( V_10 -> V_66 !=
V_10 -> V_40 . V_67 ) {
F_6 ( V_14 ,
V_10 -> V_66 , 0 ) ;
F_6 ( V_14 ,
V_10 -> V_40 . V_67 ,
1 ) ;
V_10 -> V_66 =
V_10 -> V_40 . V_67 ;
}
if ( V_5 != 0 ) {
F_7 ( V_14 , V_68 , V_20 ) ;
F_7 ( V_14 , V_69 , V_21 ) ;
F_7 ( V_14 , V_70 , V_22 ) ;
F_6 ( V_14 , V_71 , V_27 ) ;
F_6 ( V_14 , V_72 , V_28 ) ;
F_6 ( V_14 , V_73 , V_29 ) ;
if ( V_10 -> V_40 . V_74 !=
V_75 ) {
F_7 ( V_14 ,
V_76 ,
V_10 -> V_40 . V_74 ) ;
}
if ( V_10 -> V_40 . V_77 != V_75 ) {
F_7 ( V_14 ,
V_78 ,
V_10 -> V_40 . V_77 ) ;
}
if ( V_10 -> V_40 . V_55 !=
V_56 ) {
F_7 ( V_14 ,
V_79 ,
V_10 -> V_40 . V_55 ) ;
V_10 -> V_40 . V_55 = V_56 ;
}
}
F_7 ( V_14 , V_51 , V_5 | V_80 ) ;
if ( V_10 -> V_58 != - 1 ) {
F_6 ( V_14 ,
V_59 [ V_10 -> V_58 ] , 0 ) ;
V_10 -> V_58 = - 1 ;
}
F_9 ( V_14 ) ;
}
}
}
else if ( V_12 [ 0 ] == 3 ) {
if ( V_10 -> V_40 . V_41 == V_60 ) {
V_10 -> V_43 = V_61 ;
} else if ( ! F_12
( V_10 -> V_40 . V_62 ) ) {
V_10 -> V_43 = V_63 ;
} else {
V_20 = F_11 ( V_12 + 1 ) ;
V_21 = F_11 ( V_12 + 3 ) ;
V_17 = V_12 [ 5 ] & 0x1c ;
V_26 = ( V_12 [ 5 ] & 0x01 ) != 0 ? 1 : 0 ;
V_5 = ( V_12 [ 5 ] & 0x02 ) != 0 ? 1 : 0 ;
V_23 = ( V_12 [ 5 ] & V_10 -> V_40 . V_45 ) != 0 ? 1 : 0 ;
V_24 = ( V_12 [ 5 ] & V_10 -> V_40 . V_46 ) != 0 ? 1 : 0 ;
V_25 = ( V_12 [ 5 ] & V_10 -> V_40 . V_47 ) != 0 ? 1 : 0 ;
if ( V_26 != 0 ) {
if ( V_10 -> V_66 !=
V_10 -> V_40 . V_67 ) {
F_6 ( V_14 ,
V_10 -> V_66 , 0 ) ;
F_6 ( V_14 ,
V_10 -> V_40 . V_67 ,
1 ) ;
V_10 -> V_66 =
V_10 -> V_40 . V_67 ;
}
if ( V_5 != 0 ) {
F_7 ( V_14 , V_68 , V_20 ) ;
F_7 ( V_14 , V_69 , V_21 ) ;
F_6 ( V_14 , V_48 , V_23 ) ;
F_6 ( V_14 , V_49 , V_25 ) ;
F_6 ( V_14 , V_50 , V_24 ) ;
if ( V_10 -> V_40 . V_55 != V_56 ) {
F_7 ( V_14 ,
V_79 ,
V_10 -> V_40 . V_55 ) ;
V_10 -> V_40 . V_55 = V_56 ;
}
}
F_7 ( V_14 , V_51 , V_5 | V_81 ) ;
if ( V_10 -> V_58 != - 1 ) {
F_6 ( V_14 ,
V_59 [ V_10 -> V_58 ] , 0 ) ;
V_10 -> V_58 = - 1 ;
}
F_9 ( V_14 ) ;
}
}
}
else if ( V_12 [ 0 ] == 4 ) {
V_17 = V_12 [ 1 ] & 0x18 ;
V_26 = ( V_12 [ 1 ] & 0x01 ) != 0 ? 1 : 0 ;
V_5 = ( V_12 [ 1 ] & 0x02 ) != 0 ? 1 : 0 ;
V_27 = ( V_12 [ 1 ] & 0x04 ) != 0 ? 1 : 0 ;
V_28 = ( V_12 [ 1 ] & V_10 -> V_40 . V_64 ) != 0 ? 1 : 0 ;
V_29 = ( V_12 [ 1 ] & V_10 -> V_40 . V_65 ) != 0 ? 1 : 0 ;
V_19 = V_26 && V_5 && V_27 && ! ( V_12 [ 3 ] & 1 ) ? ( V_12 [ 3 ] >> 1 ) : - 1 ;
V_22 = F_11 ( V_12 + 4 ) ;
if ( V_26 ) {
if ( V_10 -> V_66 !=
V_10 -> V_40 . V_67 ) {
F_6 ( V_14 ,
V_10 -> V_66 , 0 ) ;
F_6 ( V_14 ,
V_10 -> V_40 . V_67 ,
1 ) ;
V_10 -> V_66 =
V_10 -> V_40 . V_67 ;
}
}
if ( V_10 -> V_58 != - 1 && V_10 -> V_58 != V_19 ) {
F_6 ( V_14 , V_59 [ V_10 -> V_58 ] , 0 ) ;
V_10 -> V_58 = - 1 ;
}
if ( V_19 != - 1 && V_19 != V_10 -> V_58 ) {
F_6 ( V_14 , V_59 [ V_19 ] , 1 ) ;
V_10 -> V_58 = V_19 ;
}
F_7 ( V_14 , V_51 ,
V_5 | V_80 ) ;
F_9 ( V_14 ) ;
}
else if ( V_12 [ 0 ] == 5 ) {
V_17 = V_12 [ 1 ] & 0x1c ;
V_26 = ( V_12 [ 1 ] & 0x01 ) != 0 ? 1 : 0 ;
V_5 = ( V_12 [ 1 ] & 0x02 ) != 0 ? 1 : 0 ;
V_23 = ( V_12 [ 1 ] & V_10 -> V_40 . V_45 ) != 0 ? 1 : 0 ;
V_24 = ( V_12 [ 1 ] & V_10 -> V_40 . V_46 ) != 0 ? 1 : 0 ;
V_25 = ( V_12 [ 1 ] & V_10 -> V_40 . V_47 ) != 0 ? 1 : 0 ;
V_19 = V_26 && V_5 && V_23 && ! ( V_12 [ 3 ] & 1 ) ? ( V_12 [ 3 ] >> 1 ) : 0 ;
if ( V_26 ) {
if ( V_10 -> V_66 !=
V_10 -> V_40 . V_67 ) {
F_6 ( V_14 ,
V_10 -> V_66 , 0 ) ;
F_6 ( V_14 ,
V_10 -> V_40 . V_67 , 1 ) ;
V_10 -> V_66 = V_10 -> V_40 . V_67 ;
}
}
if ( V_10 -> V_58 != - 1 && V_10 -> V_58 != V_19 ) {
F_6 ( V_14 , V_59 [ V_10 -> V_58 ] , 0 ) ;
V_10 -> V_58 = - 1 ;
}
if ( V_19 != - 1 && V_19 != V_10 -> V_58 ) {
F_6 ( V_14 , V_59 [ V_19 ] , 1 ) ;
V_10 -> V_58 = V_19 ;
}
F_7 ( V_14 , V_51 ,
V_5 | V_81 ) ;
F_9 ( V_14 ) ;
}
else if ( V_12 [ 0 ] == 6 ) {
V_19 = F_11 ( V_12 + 1 ) ;
if ( V_19 > 0 ) {
F_6 ( V_14 , V_59 [ V_19 - 1 ] ,
0 ) ;
}
if ( V_19 < 25 ) {
F_6 ( V_14 , V_59 [ V_19 + 1 ] ,
0 ) ;
}
if ( V_10 -> V_66 !=
V_10 -> V_40 . V_67 ) {
F_6 ( V_14 ,
V_10 -> V_66 , 0 ) ;
F_6 ( V_14 ,
V_10 -> V_40 . V_67 ,
1 ) ;
V_10 -> V_66 =
V_10 -> V_40 . V_67 ;
}
F_6 ( V_14 , V_59 [ V_19 ] , 1 ) ;
F_7 ( V_14 , V_51 ,
1 | V_52 ) ;
F_9 ( V_14 ) ;
} else {
F_4 ( & V_16 -> V_34 , L_4 , V_12 [ 0 ] ) ;
}
if ( V_10 -> V_82 != V_17 &&
V_10 -> V_40 . V_83 != 0 && V_10 -> V_36 != 1 ) {
V_10 -> V_37 = V_38 +
( ( V_10 -> V_40 . V_83 * V_84 ) / 1000 ) ;
V_10 -> V_36 = 1 ;
}
V_10 -> V_82 = V_17 ;
exit:
V_18 = F_13 ( V_9 , V_85 ) ;
if ( V_18 != 0 ) {
F_14 ( & V_16 -> V_34 ,
L_5 ,
V_35 , V_18 ) ;
}
}
static int F_15 ( struct V_13 * V_14 )
{
struct V_10 * V_10 = F_16 ( V_14 ) ;
V_10 -> V_9 -> V_34 = F_17 ( V_10 -> V_16 ) ;
if ( F_13 ( V_10 -> V_9 , V_86 ) != 0 )
return - V_87 ;
return 0 ;
}
static void F_18 ( struct V_13 * V_14 )
{
struct V_10 * V_10 = F_16 ( V_14 ) ;
F_19 ( V_10 -> V_9 ) ;
}
static int
F_20 ( struct V_10 * V_10 ,
unsigned char V_88 ,
unsigned char V_89 , void * V_90 , int V_91 )
{
struct V_92 * V_93 = F_17 ( V_10 -> V_16 ) ;
return F_21 ( V_93 ,
F_22 ( V_93 , 0 ) ,
V_94 ,
V_95 | V_96 |
V_97 , ( V_88 << 8 ) + V_89 ,
V_10 -> V_98 , V_90 , V_91 , 5000 ) ;
}
static int
F_23 ( struct V_10 * V_10 ,
unsigned char V_88 ,
unsigned char V_89 , void * V_90 , int V_91 )
{
struct V_92 * V_93 = F_17 ( V_10 -> V_16 ) ;
return F_21 ( V_93 ,
F_24 ( V_93 , 0 ) ,
V_99 ,
V_95 | V_96 |
V_100 , ( V_88 << 8 ) + V_89 ,
V_10 -> V_98 , V_90 , V_91 , 5000 ) ;
}
static int
F_25 ( struct V_10 * V_10 , unsigned char V_101 , unsigned char V_12 )
{
const int V_102 = 3 * sizeof( V_103 ) ;
int V_104 ;
V_103 * V_105 ;
V_105 = F_26 ( V_102 , V_86 ) ;
if ( ! V_105 )
return - V_106 ;
V_105 [ 0 ] = 2 ;
V_105 [ 1 ] = V_101 ;
V_105 [ 2 ] = V_12 ;
if ( ( V_104 =
F_20 ( V_10 , 3 , 2 , V_105 , V_102 ) ) != V_102 ) {
F_4 ( & V_10 -> V_16 -> V_34 ,
L_6 ,
V_101 , V_12 ) ;
}
F_27 ( V_105 ) ;
return V_104 < 0 ? V_104 : 0 ;
}
static int
F_28 ( struct V_10 * V_10 , unsigned char V_101 , unsigned char V_12 )
{
const int V_102 = 3 * sizeof( V_103 ) ;
int V_104 ;
V_103 * V_105 ;
V_105 = F_26 ( V_102 , V_86 ) ;
if ( ! V_105 )
return - V_106 ;
V_105 [ 0 ] = 2 ;
V_105 [ 1 ] = V_101 ;
V_105 [ 2 ] = V_12 ;
if ( F_25 ( V_10 , V_101 , V_12 ) != 0 ) {
F_27 ( V_105 ) ;
return - V_87 ;
}
F_29 ( V_10 -> V_40 . V_107 ) ;
if ( ( V_104 =
F_23 ( V_10 , 3 , 2 , V_105 , V_102 ) ) != V_102 ) {
F_4 ( & V_10 -> V_16 -> V_34 ,
L_7 ,
V_105 [ 0 ] , V_105 [ 1 ] , V_105 [ 2 ] ) ;
V_104 = - V_87 ;
} else {
V_104 = F_11 ( V_105 + 1 ) ;
}
F_27 ( V_105 ) ;
return V_104 ;
}
static int F_30 ( struct V_10 * V_10 )
{
int V_104 ;
if ( ( V_104 = F_25 ( V_10 , 0x18 , 0x04 ) ) < 0 )
return V_104 ;
if ( ( V_104 = F_28 ( V_10 , 0x02 , 0x00 ) ) < 0 )
return V_104 ;
V_10 -> V_108 . V_109 = V_104 & 0xff ;
if ( ( V_104 = F_28 ( V_10 , 0x03 , 0x00 ) ) < 0 )
return V_104 ;
V_10 -> V_108 . V_110 = V_104 ;
if ( ( V_104 = F_28 ( V_10 , 0x04 , 0x00 ) ) < 0 )
return V_104 ;
V_10 -> V_108 . V_111 = V_104 ;
if ( ( V_104 = F_28 ( V_10 , 0x01 , 0x00 ) ) < 0 )
return V_104 ;
F_31 ( V_10 -> V_14 , V_68 , 0 , V_104 - 1 , 0 , 0 ) ;
if ( ( V_104 = F_28 ( V_10 , 0x01 , 0x01 ) ) < 0 )
return V_104 ;
F_31 ( V_10 -> V_14 , V_69 , 0 , V_104 - 1 , 0 , 0 ) ;
if ( ( V_104 = F_28 ( V_10 , 0x08 , 0x00 ) ) < 0 )
return V_104 ;
F_31 ( V_10 -> V_14 , V_70 , 0 , V_104 - 1 , 0 , 0 ) ;
if ( V_10 -> V_40 . V_41 ==
V_42 ) {
if ( ( V_104 = F_25 ( V_10 , 0x10 , 0x01 ) ) < 0 ) {
return V_104 ;
}
} else {
if ( ( V_104 = F_25 ( V_10 , 0x10 , 0x00 ) ) < 0 ) {
return V_104 ;
}
}
if ( ( V_104 = F_25 ( V_10 , 0x11 , 0x02 ) ) < 0 )
return V_104 ;
#if 0
if ((ret = aiptek_command(aiptek, 0x17, 0x00)) < 0)
return ret;
#endif
if ( ( V_104 = F_25 ( V_10 , 0x12 , 0xff ) ) < 0 )
return V_104 ;
V_10 -> V_43 = V_112 ;
V_10 -> V_39 = 0 ;
return 0 ;
}
static T_2 F_32 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_8 ,
F_34 ( V_10 -> V_14 , V_68 ) + 1 ,
F_34 ( V_10 -> V_14 , V_69 ) + 1 ) ;
}
static T_2 F_35 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_9 ,
F_2 ( V_117 ,
V_10 -> V_40 . V_62 ) ) ;
}
static T_2
F_36 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
int V_118 = F_1 ( V_117 , V_105 , V_4 ) ;
if ( V_118 == V_7 )
return - V_119 ;
V_10 -> V_120 . V_62 = V_118 ;
return V_4 ;
}
static T_2 F_37 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_9 ,
F_2 ( V_121 ,
V_10 -> V_40 . V_41 ) ) ;
}
static T_2
F_38 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
int V_118 = F_1 ( V_121 , V_105 , V_4 ) ;
if ( V_118 == V_7 )
return - V_119 ;
V_10 -> V_120 . V_41 = V_118 ;
return V_4 ;
}
static T_2 F_39 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_9 ,
F_2 ( V_122 ,
V_10 -> V_40 . V_67 ) ) ;
}
static T_2
F_40 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
int V_118 = F_1 ( V_122 , V_105 , V_4 ) ;
if ( V_118 == V_7 )
return - V_119 ;
V_10 -> V_120 . V_67 = V_118 ;
return V_4 ;
}
static T_2 F_41 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
if ( V_10 -> V_40 . V_74 == V_75 ) {
return snprintf ( V_105 , V_116 , L_10 ) ;
} else {
return snprintf ( V_105 , V_116 , L_11 ,
V_10 -> V_40 . V_74 ) ;
}
}
static T_2
F_42 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
int V_20 ;
if ( F_43 ( V_105 , 10 , & V_20 ) ) {
T_1 V_123 = V_105 [ V_4 - 1 ] == '\n' ? V_4 - 1 : V_4 ;
if ( strncmp ( V_105 , L_12 , V_123 ) )
return - V_119 ;
V_10 -> V_120 . V_74 = V_75 ;
} else {
if ( V_20 < V_124 || V_20 > V_125 )
return - V_119 ;
V_10 -> V_120 . V_74 = V_20 ;
}
return V_4 ;
}
static T_2 F_44 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
if ( V_10 -> V_40 . V_77 == V_75 ) {
return snprintf ( V_105 , V_116 , L_10 ) ;
} else {
return snprintf ( V_105 , V_116 , L_11 ,
V_10 -> V_40 . V_77 ) ;
}
}
static T_2
F_45 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
int V_21 ;
if ( F_43 ( V_105 , 10 , & V_21 ) ) {
T_1 V_123 = V_105 [ V_4 - 1 ] == '\n' ? V_4 - 1 : V_4 ;
if ( strncmp ( V_105 , L_12 , V_123 ) )
return - V_119 ;
V_10 -> V_120 . V_77 = V_75 ;
} else {
if ( V_21 < V_124 || V_21 > V_125 )
return - V_119 ;
V_10 -> V_120 . V_77 = V_21 ;
}
return V_4 ;
}
static T_2 F_46 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_11 , V_10 -> V_40 . V_83 ) ;
}
static T_2
F_47 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
int V_126 , V_127 ;
V_126 = F_43 ( V_105 , 10 , & V_127 ) ;
if ( V_126 )
return V_126 ;
V_10 -> V_120 . V_83 = V_127 ;
return V_4 ;
}
static T_2 F_48 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_11 ,
V_10 -> V_40 . V_107 ) ;
}
static T_2
F_49 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
int V_126 , V_128 ;
V_126 = F_43 ( V_105 , 10 , & V_128 ) ;
if ( V_126 )
return V_126 ;
V_10 -> V_120 . V_107 = V_128 ;
return V_4 ;
}
static T_2 F_50 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_13 , V_10 -> V_39 ) ;
}
static T_2 F_51 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
char * V_129 ;
switch ( V_10 -> V_43 ) {
case V_112 :
V_129 = L_14 ;
break;
case V_44 :
V_129 = L_15 ;
break;
case V_61 :
V_129 = L_16 ;
break;
case V_63 :
if ( V_10 -> V_40 . V_62 ==
V_130 ) {
V_129 = L_17 ;
} else {
V_129 = L_18 ;
}
break;
default:
return 0 ;
}
return snprintf ( V_105 , V_116 , V_129 ) ;
}
static T_2 F_52 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_9 ,
F_2 ( V_131 ,
V_10 -> V_40 . V_65 ) ) ;
}
static T_2
F_53 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
int V_132 = F_1 ( V_131 , V_105 , V_4 ) ;
if ( V_132 == V_7 )
return - V_119 ;
V_10 -> V_120 . V_65 = V_132 ;
return V_4 ;
}
static T_2 F_54 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_9 ,
F_2 ( V_131 ,
V_10 -> V_40 . V_64 ) ) ;
}
static T_2
F_55 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
int V_132 = F_1 ( V_131 , V_105 , V_4 ) ;
if ( V_132 == V_7 )
return - V_119 ;
V_10 -> V_120 . V_64 = V_132 ;
return V_4 ;
}
static T_2 F_56 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_9 ,
F_2 ( V_133 ,
V_10 -> V_40 . V_45 ) ) ;
}
static T_2
F_57 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
int V_132 = F_1 ( V_133 , V_105 , V_4 ) ;
if ( V_132 == V_7 )
return - V_119 ;
V_10 -> V_120 . V_45 = V_132 ;
return V_4 ;
}
static T_2 F_58 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_9 ,
F_2 ( V_133 ,
V_10 -> V_40 . V_47 ) ) ;
}
static T_2
F_59 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
int V_132 = F_1 ( V_133 , V_105 , V_4 ) ;
if ( V_132 == V_7 )
return - V_119 ;
V_10 -> V_120 . V_47 = V_132 ;
return V_4 ;
}
static T_2 F_60 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_9 ,
F_2 ( V_133 ,
V_10 -> V_40 . V_46 ) ) ;
}
static T_2
F_61 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
int V_132 = F_1 ( V_133 , V_105 , V_4 ) ;
if ( V_132 == V_7 )
return - V_119 ;
V_10 -> V_120 . V_46 = V_132 ;
return V_4 ;
}
static T_2 F_62 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
if ( V_10 -> V_40 . V_55 == V_56 ) {
return snprintf ( V_105 , V_116 , L_10 ) ;
} else {
return snprintf ( V_105 , V_116 , L_11 ,
V_10 -> V_40 . V_55 ) ;
}
}
static T_2
F_63 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
int V_126 , V_134 ;
V_126 = F_43 ( V_105 , 10 , & V_134 ) ;
if ( V_126 )
return V_126 ;
V_10 -> V_120 . V_55 = V_134 ;
return V_4 ;
}
static T_2 F_64 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
return snprintf ( V_105 , V_116 ,
L_19 ) ;
}
static T_2
F_65 ( struct V_113 * V_34 , struct V_114 * V_115 , const char * V_105 , T_1 V_4 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
memcpy ( & V_10 -> V_40 , & V_10 -> V_120 ,
sizeof( struct V_135 ) ) ;
if ( F_30 ( V_10 ) < 0 )
return - V_87 ;
return V_4 ;
}
static T_2 F_66 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_20 , V_10 -> V_108 . V_110 ) ;
}
static T_2 F_67 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_20 , V_10 -> V_108 . V_109 ) ;
}
static T_2 F_68 ( struct V_113 * V_34 , struct V_114 * V_115 , char * V_105 )
{
struct V_10 * V_10 = F_33 ( V_34 ) ;
return snprintf ( V_105 , V_116 , L_21 ,
V_10 -> V_108 . V_111 ) ;
}
static int
F_69 ( struct V_15 * V_16 , const struct V_136 * V_137 )
{
struct V_92 * V_138 = F_17 ( V_16 ) ;
struct V_139 * V_140 ;
struct V_10 * V_10 ;
struct V_13 * V_14 ;
int V_141 ;
int V_142 [] = { 0 ,
V_143 ,
V_144 ,
V_145 ,
V_146 ,
V_147 ,
V_148
} ;
int V_126 = - V_106 ;
V_142 [ 0 ] = V_107 ;
V_10 = F_70 ( sizeof( struct V_10 ) , V_86 ) ;
V_14 = F_71 () ;
if ( ! V_10 || ! V_14 ) {
F_72 ( & V_16 -> V_34 ,
L_22 ) ;
goto V_149;
}
V_10 -> V_12 = F_73 ( V_138 , V_150 ,
V_85 , & V_10 -> V_151 ) ;
if ( ! V_10 -> V_12 ) {
F_72 ( & V_16 -> V_34 , L_23 ) ;
goto V_149;
}
V_10 -> V_9 = F_74 ( 0 , V_86 ) ;
if ( ! V_10 -> V_9 ) {
F_72 ( & V_16 -> V_34 , L_24 ) ;
goto V_152;
}
V_10 -> V_14 = V_14 ;
V_10 -> V_16 = V_16 ;
V_10 -> V_98 = V_16 -> V_153 [ 0 ] . V_154 . V_155 ;
V_10 -> V_36 = 0 ;
V_10 -> V_37 = 0 ;
V_10 -> V_82 = 0 ;
V_10 -> V_58 = - 1 ;
V_10 -> V_40 . V_62 = V_156 ;
V_10 -> V_40 . V_41 = V_42 ;
V_10 -> V_40 . V_67 = V_157 ;
V_10 -> V_40 . V_74 = V_75 ;
V_10 -> V_40 . V_77 = V_75 ;
V_10 -> V_40 . V_45 = V_158 ;
V_10 -> V_40 . V_47 = V_159 ;
V_10 -> V_40 . V_46 = V_160 ;
V_10 -> V_40 . V_65 = V_161 ;
V_10 -> V_40 . V_64 = V_162 ;
V_10 -> V_40 . V_83 = V_83 ;
V_10 -> V_40 . V_107 = V_107 ;
V_10 -> V_120 = V_10 -> V_40 ;
F_75 ( V_138 , V_10 -> V_108 . V_163 ,
sizeof( V_10 -> V_108 . V_163 ) ) ;
F_76 ( V_10 -> V_108 . V_163 , L_25 ,
sizeof( V_10 -> V_108 . V_163 ) ) ;
V_14 -> V_164 = L_26 ;
V_14 -> V_165 = V_10 -> V_108 . V_163 ;
F_77 ( V_138 , & V_14 -> V_137 ) ;
V_14 -> V_34 . V_166 = & V_16 -> V_34 ;
F_78 ( V_14 , V_10 ) ;
V_14 -> V_167 = F_15 ;
V_14 -> V_168 = F_18 ;
for ( V_141 = 0 ; V_141 < F_79 ( V_169 ) ; ++ V_141 )
F_80 ( V_169 [ V_141 ] , V_14 -> V_170 ) ;
for ( V_141 = 0 ; V_141 < F_79 ( V_171 ) ; ++ V_141 )
F_80 ( V_171 [ V_141 ] , V_14 -> V_172 ) ;
for ( V_141 = 0 ; V_141 < F_79 ( V_173 ) ; ++ V_141 )
F_80 ( V_173 [ V_141 ] , V_14 -> V_174 ) ;
F_80 ( V_175 , V_14 -> V_176 ) ;
for ( V_141 = 0 ; V_141 < F_79 ( V_177 ) ; ++ V_141 )
F_80 ( V_177 [ V_141 ] , V_14 -> V_178 ) ;
for ( V_141 = 0 ; V_141 < F_79 ( V_59 ) ; ++ V_141 )
F_80 ( V_59 [ V_141 ] , V_14 -> V_178 ) ;
F_31 ( V_14 , V_68 , 0 , 2999 , 0 , 0 ) ;
F_31 ( V_14 , V_69 , 0 , 2249 , 0 , 0 ) ;
F_31 ( V_14 , V_70 , 0 , 511 , 0 , 0 ) ;
F_31 ( V_14 , V_76 , V_124 , V_125 , 0 , 0 ) ;
F_31 ( V_14 , V_78 , V_124 , V_125 , 0 , 0 ) ;
F_31 ( V_14 , V_79 , V_179 , V_180 - 1 , 0 , 0 ) ;
if ( V_16 -> V_153 [ 0 ] . V_154 . V_181 < 1 ) {
F_14 ( & V_16 -> V_34 ,
L_27 ,
V_16 -> V_153 [ 0 ] . V_154 . V_181 ) ;
V_126 = - V_119 ;
goto V_182;
}
V_140 = & V_16 -> V_153 [ 0 ] . V_140 [ 0 ] . V_154 ;
F_81 ( V_10 -> V_9 ,
V_138 ,
F_82 ( V_138 ,
V_140 -> V_183 ) ,
V_10 -> V_12 , 8 , F_3 , V_10 ,
V_140 -> V_184 ) ;
V_10 -> V_9 -> V_185 = V_10 -> V_151 ;
V_10 -> V_9 -> V_186 |= V_187 ;
for ( V_141 = 0 ; V_141 < F_79 ( V_142 ) ; ++ V_141 ) {
V_10 -> V_40 . V_107 = V_142 [ V_141 ] ;
( void ) F_30 ( V_10 ) ;
if ( F_34 ( V_10 -> V_14 , V_68 ) > 0 ) {
F_83 ( & V_16 -> V_34 ,
L_28 ,
V_10 -> V_40 . V_107 ) ;
break;
}
}
if ( V_141 == F_79 ( V_142 ) ) {
F_83 ( & V_16 -> V_34 ,
L_29 ) ;
V_126 = - V_119 ;
goto V_182;
}
F_84 ( V_16 , V_10 ) ;
V_126 = F_85 ( & V_16 -> V_34 . V_188 , & V_189 ) ;
if ( V_126 ) {
F_72 ( & V_16 -> V_34 , L_30 ,
V_126 ) ;
goto V_182;
}
V_126 = F_86 ( V_10 -> V_14 ) ;
if ( V_126 ) {
F_72 ( & V_16 -> V_34 ,
L_31 , V_126 ) ;
goto V_190;
}
return 0 ;
V_190: F_87 ( & V_16 -> V_34 . V_188 , & V_189 ) ;
V_182: F_88 ( V_10 -> V_9 ) ;
V_152: F_89 ( V_138 , V_150 , V_10 -> V_12 ,
V_10 -> V_151 ) ;
V_149: F_84 ( V_16 , NULL ) ;
F_90 ( V_14 ) ;
F_27 ( V_10 ) ;
return V_126 ;
}
static void F_91 ( struct V_15 * V_16 )
{
struct V_10 * V_10 = F_92 ( V_16 ) ;
F_84 ( V_16 , NULL ) ;
if ( V_10 != NULL ) {
F_19 ( V_10 -> V_9 ) ;
F_93 ( V_10 -> V_14 ) ;
F_87 ( & V_16 -> V_34 . V_188 , & V_189 ) ;
F_88 ( V_10 -> V_9 ) ;
F_89 ( F_17 ( V_16 ) ,
V_150 ,
V_10 -> V_12 , V_10 -> V_151 ) ;
F_27 ( V_10 ) ;
}
}
