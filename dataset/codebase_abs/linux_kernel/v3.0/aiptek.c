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
int V_15 = 0 ;
int V_16 , V_17 , V_18 , V_19 , V_20 , V_21 , V_22 , V_23 , V_5 , V_24 , V_25 , V_26 , V_27 ;
switch ( V_9 -> V_28 ) {
case 0 :
break;
case - V_29 :
case - V_30 :
case - V_31 :
F_4 ( L_2 ,
V_32 , V_9 -> V_28 ) ;
return;
default:
F_4 ( L_3 ,
V_32 , V_9 -> V_28 ) ;
goto exit;
}
if ( V_10 -> V_33 == 1 && F_5 ( V_10 -> V_34 , V_35 ) ) {
goto exit;
}
V_10 -> V_33 = 0 ;
V_10 -> V_36 ++ ;
if ( V_12 [ 0 ] == 1 ) {
if ( V_10 -> V_37 . V_38 ==
V_39 ) {
V_10 -> V_40 =
V_41 ;
} else {
V_18 = ( signed char ) V_12 [ 2 ] ;
V_19 = ( signed char ) V_12 [ 3 ] ;
V_15 = V_12 [ 1 ] & 0x07 ;
V_21 = ( V_12 [ 1 ] & V_10 -> V_37 . V_42 >> 2 ) != 0 ? 1 : 0 ;
V_22 = ( V_12 [ 1 ] & V_10 -> V_37 . V_43 >> 2 ) != 0 ? 1 : 0 ;
V_23 = ( V_12 [ 1 ] & V_10 -> V_37 . V_44 >> 2 ) != 0 ? 1 : 0 ;
F_6 ( V_14 , V_45 , V_21 ) ;
F_6 ( V_14 , V_46 , V_23 ) ;
F_6 ( V_14 , V_47 , V_22 ) ;
F_7 ( V_14 , V_48 ,
1 | V_49 ) ;
F_8 ( V_14 , V_50 , V_18 ) ;
F_8 ( V_14 , V_51 , V_19 ) ;
if ( V_10 -> V_37 . V_52 != V_53 ) {
F_8 ( V_14 , V_54 ,
V_10 -> V_37 . V_52 ) ;
V_10 -> V_37 . V_52 = V_53 ;
}
if ( V_10 -> V_55 != - 1 ) {
F_6 ( V_14 ,
V_56 [ V_10 -> V_55 ] , 0 ) ;
V_10 -> V_55 = - 1 ;
}
F_9 ( V_14 ) ;
}
}
else if ( V_12 [ 0 ] == 2 ) {
if ( V_10 -> V_37 . V_38 == V_57 ) {
V_10 -> V_40 = V_58 ;
} else if ( ! F_10
( V_10 -> V_37 . V_59 ) ) {
V_10 -> V_40 = V_60 ;
} else {
V_18 = F_11 ( V_12 + 1 ) ;
V_19 = F_11 ( V_12 + 3 ) ;
V_20 = F_11 ( V_12 + 6 ) ;
V_24 = ( V_12 [ 5 ] & 0x01 ) != 0 ? 1 : 0 ;
V_5 = ( V_12 [ 5 ] & 0x02 ) != 0 ? 1 : 0 ;
V_25 = ( V_12 [ 5 ] & 0x04 ) != 0 ? 1 : 0 ;
V_15 = V_12 [ 5 ] & 0x18 ;
V_26 = ( V_12 [ 5 ] & V_10 -> V_37 . V_61 ) != 0 ? 1 : 0 ;
V_27 = ( V_12 [ 5 ] & V_10 -> V_37 . V_62 ) != 0 ? 1 : 0 ;
if ( V_24 != 0 ) {
if ( V_10 -> V_63 !=
V_10 -> V_37 . V_64 ) {
F_6 ( V_14 ,
V_10 -> V_63 , 0 ) ;
F_6 ( V_14 ,
V_10 -> V_37 . V_64 ,
1 ) ;
V_10 -> V_63 =
V_10 -> V_37 . V_64 ;
}
if ( V_5 != 0 ) {
F_7 ( V_14 , V_65 , V_18 ) ;
F_7 ( V_14 , V_66 , V_19 ) ;
F_7 ( V_14 , V_67 , V_20 ) ;
F_6 ( V_14 , V_68 , V_25 ) ;
F_6 ( V_14 , V_69 , V_26 ) ;
F_6 ( V_14 , V_70 , V_27 ) ;
if ( V_10 -> V_37 . V_71 !=
V_72 ) {
F_7 ( V_14 ,
V_73 ,
V_10 -> V_37 . V_71 ) ;
}
if ( V_10 -> V_37 . V_74 != V_72 ) {
F_7 ( V_14 ,
V_75 ,
V_10 -> V_37 . V_74 ) ;
}
if ( V_10 -> V_37 . V_52 !=
V_53 ) {
F_7 ( V_14 ,
V_76 ,
V_10 -> V_37 . V_52 ) ;
V_10 -> V_37 . V_52 = V_53 ;
}
}
F_7 ( V_14 , V_48 , V_5 | V_77 ) ;
if ( V_10 -> V_55 != - 1 ) {
F_6 ( V_14 ,
V_56 [ V_10 -> V_55 ] , 0 ) ;
V_10 -> V_55 = - 1 ;
}
F_9 ( V_14 ) ;
}
}
}
else if ( V_12 [ 0 ] == 3 ) {
if ( V_10 -> V_37 . V_38 == V_57 ) {
V_10 -> V_40 = V_58 ;
} else if ( ! F_12
( V_10 -> V_37 . V_59 ) ) {
V_10 -> V_40 = V_60 ;
} else {
V_18 = F_11 ( V_12 + 1 ) ;
V_19 = F_11 ( V_12 + 3 ) ;
V_15 = V_12 [ 5 ] & 0x1c ;
V_24 = ( V_12 [ 5 ] & 0x01 ) != 0 ? 1 : 0 ;
V_5 = ( V_12 [ 5 ] & 0x02 ) != 0 ? 1 : 0 ;
V_21 = ( V_12 [ 5 ] & V_10 -> V_37 . V_42 ) != 0 ? 1 : 0 ;
V_22 = ( V_12 [ 5 ] & V_10 -> V_37 . V_43 ) != 0 ? 1 : 0 ;
V_23 = ( V_12 [ 5 ] & V_10 -> V_37 . V_44 ) != 0 ? 1 : 0 ;
if ( V_24 != 0 ) {
if ( V_10 -> V_63 !=
V_10 -> V_37 . V_64 ) {
F_6 ( V_14 ,
V_10 -> V_63 , 0 ) ;
F_6 ( V_14 ,
V_10 -> V_37 . V_64 ,
1 ) ;
V_10 -> V_63 =
V_10 -> V_37 . V_64 ;
}
if ( V_5 != 0 ) {
F_7 ( V_14 , V_65 , V_18 ) ;
F_7 ( V_14 , V_66 , V_19 ) ;
F_6 ( V_14 , V_45 , V_21 ) ;
F_6 ( V_14 , V_46 , V_23 ) ;
F_6 ( V_14 , V_47 , V_22 ) ;
if ( V_10 -> V_37 . V_52 != V_53 ) {
F_7 ( V_14 ,
V_76 ,
V_10 -> V_37 . V_52 ) ;
V_10 -> V_37 . V_52 = V_53 ;
}
}
F_7 ( V_14 , V_48 , V_5 | V_78 ) ;
if ( V_10 -> V_55 != - 1 ) {
F_6 ( V_14 ,
V_56 [ V_10 -> V_55 ] , 0 ) ;
V_10 -> V_55 = - 1 ;
}
F_9 ( V_14 ) ;
}
}
}
else if ( V_12 [ 0 ] == 4 ) {
V_15 = V_12 [ 1 ] & 0x18 ;
V_24 = ( V_12 [ 1 ] & 0x01 ) != 0 ? 1 : 0 ;
V_5 = ( V_12 [ 1 ] & 0x02 ) != 0 ? 1 : 0 ;
V_25 = ( V_12 [ 1 ] & 0x04 ) != 0 ? 1 : 0 ;
V_26 = ( V_12 [ 1 ] & V_10 -> V_37 . V_61 ) != 0 ? 1 : 0 ;
V_27 = ( V_12 [ 1 ] & V_10 -> V_37 . V_62 ) != 0 ? 1 : 0 ;
V_17 = V_24 && V_5 && V_25 && ! ( V_12 [ 3 ] & 1 ) ? ( V_12 [ 3 ] >> 1 ) : - 1 ;
V_20 = F_11 ( V_12 + 4 ) ;
if ( V_24 ) {
if ( V_10 -> V_63 !=
V_10 -> V_37 . V_64 ) {
F_6 ( V_14 ,
V_10 -> V_63 , 0 ) ;
F_6 ( V_14 ,
V_10 -> V_37 . V_64 ,
1 ) ;
V_10 -> V_63 =
V_10 -> V_37 . V_64 ;
}
}
if ( V_10 -> V_55 != - 1 && V_10 -> V_55 != V_17 ) {
F_6 ( V_14 , V_56 [ V_10 -> V_55 ] , 0 ) ;
V_10 -> V_55 = - 1 ;
}
if ( V_17 != - 1 && V_17 != V_10 -> V_55 ) {
F_6 ( V_14 , V_56 [ V_17 ] , 1 ) ;
V_10 -> V_55 = V_17 ;
}
F_7 ( V_14 , V_48 ,
V_5 | V_77 ) ;
F_9 ( V_14 ) ;
}
else if ( V_12 [ 0 ] == 5 ) {
V_15 = V_12 [ 1 ] & 0x1c ;
V_24 = ( V_12 [ 1 ] & 0x01 ) != 0 ? 1 : 0 ;
V_5 = ( V_12 [ 1 ] & 0x02 ) != 0 ? 1 : 0 ;
V_21 = ( V_12 [ 1 ] & V_10 -> V_37 . V_42 ) != 0 ? 1 : 0 ;
V_22 = ( V_12 [ 1 ] & V_10 -> V_37 . V_43 ) != 0 ? 1 : 0 ;
V_23 = ( V_12 [ 1 ] & V_10 -> V_37 . V_44 ) != 0 ? 1 : 0 ;
V_17 = V_24 && V_5 && V_21 && ! ( V_12 [ 3 ] & 1 ) ? ( V_12 [ 3 ] >> 1 ) : 0 ;
if ( V_24 ) {
if ( V_10 -> V_63 !=
V_10 -> V_37 . V_64 ) {
F_6 ( V_14 ,
V_10 -> V_63 , 0 ) ;
F_6 ( V_14 ,
V_10 -> V_37 . V_64 , 1 ) ;
V_10 -> V_63 = V_10 -> V_37 . V_64 ;
}
}
if ( V_10 -> V_55 != - 1 && V_10 -> V_55 != V_17 ) {
F_6 ( V_14 , V_56 [ V_10 -> V_55 ] , 0 ) ;
V_10 -> V_55 = - 1 ;
}
if ( V_17 != - 1 && V_17 != V_10 -> V_55 ) {
F_6 ( V_14 , V_56 [ V_17 ] , 1 ) ;
V_10 -> V_55 = V_17 ;
}
F_7 ( V_14 , V_48 ,
V_5 | V_78 ) ;
F_9 ( V_14 ) ;
}
else if ( V_12 [ 0 ] == 6 ) {
V_17 = F_11 ( V_12 + 1 ) ;
if ( V_17 > 0 ) {
F_6 ( V_14 , V_56 [ V_17 - 1 ] ,
0 ) ;
}
if ( V_17 < 25 ) {
F_6 ( V_14 , V_56 [ V_17 + 1 ] ,
0 ) ;
}
if ( V_10 -> V_63 !=
V_10 -> V_37 . V_64 ) {
F_6 ( V_14 ,
V_10 -> V_63 , 0 ) ;
F_6 ( V_14 ,
V_10 -> V_37 . V_64 ,
1 ) ;
V_10 -> V_63 =
V_10 -> V_37 . V_64 ;
}
F_6 ( V_14 , V_56 [ V_17 ] , 1 ) ;
F_7 ( V_14 , V_48 ,
1 | V_49 ) ;
F_9 ( V_14 ) ;
} else {
F_4 ( L_4 , V_12 [ 0 ] ) ;
}
if ( V_10 -> V_79 != V_15 &&
V_10 -> V_37 . V_80 != 0 && V_10 -> V_33 != 1 ) {
V_10 -> V_34 = V_35 +
( ( V_10 -> V_37 . V_80 * V_81 ) / 1000 ) ;
V_10 -> V_33 = 1 ;
}
V_10 -> V_79 = V_15 ;
exit:
V_16 = F_13 ( V_9 , V_82 ) ;
if ( V_16 != 0 ) {
F_14 ( L_5 ,
V_32 , V_16 ) ;
}
}
static int F_15 ( struct V_13 * V_14 )
{
struct V_10 * V_10 = F_16 ( V_14 ) ;
V_10 -> V_9 -> V_83 = V_10 -> V_84 ;
if ( F_13 ( V_10 -> V_9 , V_85 ) != 0 )
return - V_86 ;
return 0 ;
}
static void F_17 ( struct V_13 * V_14 )
{
struct V_10 * V_10 = F_16 ( V_14 ) ;
F_18 ( V_10 -> V_9 ) ;
}
static int
F_19 ( struct V_10 * V_10 ,
unsigned char V_87 ,
unsigned char V_88 , void * V_89 , int V_90 )
{
return F_20 ( V_10 -> V_84 ,
F_21 ( V_10 -> V_84 , 0 ) ,
V_91 ,
V_92 | V_93 |
V_94 , ( V_87 << 8 ) + V_88 ,
V_10 -> V_95 , V_89 , V_90 , 5000 ) ;
}
static int
F_22 ( struct V_10 * V_10 ,
unsigned char V_87 ,
unsigned char V_88 , void * V_89 , int V_90 )
{
return F_20 ( V_10 -> V_84 ,
F_23 ( V_10 -> V_84 , 0 ) ,
V_96 ,
V_92 | V_93 |
V_97 , ( V_87 << 8 ) + V_88 ,
V_10 -> V_95 , V_89 , V_90 , 5000 ) ;
}
static int
F_24 ( struct V_10 * V_10 , unsigned char V_98 , unsigned char V_12 )
{
const int V_99 = 3 * sizeof( V_100 ) ;
int V_101 ;
V_100 * V_102 ;
V_102 = F_25 ( V_99 , V_85 ) ;
if ( ! V_102 )
return - V_103 ;
V_102 [ 0 ] = 2 ;
V_102 [ 1 ] = V_98 ;
V_102 [ 2 ] = V_12 ;
if ( ( V_101 =
F_19 ( V_10 , 3 , 2 , V_102 , V_99 ) ) != V_99 ) {
F_4 ( L_6 ,
V_98 , V_12 ) ;
}
F_26 ( V_102 ) ;
return V_101 < 0 ? V_101 : 0 ;
}
static int
F_27 ( struct V_10 * V_10 , unsigned char V_98 , unsigned char V_12 )
{
const int V_99 = 3 * sizeof( V_100 ) ;
int V_101 ;
V_100 * V_102 ;
V_102 = F_25 ( V_99 , V_85 ) ;
if ( ! V_102 )
return - V_103 ;
V_102 [ 0 ] = 2 ;
V_102 [ 1 ] = V_98 ;
V_102 [ 2 ] = V_12 ;
if ( F_24 ( V_10 , V_98 , V_12 ) != 0 ) {
F_26 ( V_102 ) ;
return - V_86 ;
}
F_28 ( V_10 -> V_37 . V_104 ) ;
if ( ( V_101 =
F_22 ( V_10 , 3 , 2 , V_102 , V_99 ) ) != V_99 ) {
F_4 ( L_7 ,
V_102 [ 0 ] , V_102 [ 1 ] , V_102 [ 2 ] ) ;
V_101 = - V_86 ;
} else {
V_101 = F_11 ( V_102 + 1 ) ;
}
F_26 ( V_102 ) ;
return V_101 ;
}
static int F_29 ( struct V_10 * V_10 )
{
int V_101 ;
if ( ( V_101 = F_24 ( V_10 , 0x18 , 0x04 ) ) < 0 )
return V_101 ;
if ( ( V_101 = F_27 ( V_10 , 0x02 , 0x00 ) ) < 0 )
return V_101 ;
V_10 -> V_105 . V_106 = V_101 & 0xff ;
if ( ( V_101 = F_27 ( V_10 , 0x03 , 0x00 ) ) < 0 )
return V_101 ;
V_10 -> V_105 . V_107 = V_101 ;
if ( ( V_101 = F_27 ( V_10 , 0x04 , 0x00 ) ) < 0 )
return V_101 ;
V_10 -> V_105 . V_108 = V_101 ;
if ( ( V_101 = F_27 ( V_10 , 0x01 , 0x00 ) ) < 0 )
return V_101 ;
F_30 ( V_10 -> V_14 , V_65 , 0 , V_101 - 1 , 0 , 0 ) ;
if ( ( V_101 = F_27 ( V_10 , 0x01 , 0x01 ) ) < 0 )
return V_101 ;
F_30 ( V_10 -> V_14 , V_66 , 0 , V_101 - 1 , 0 , 0 ) ;
if ( ( V_101 = F_27 ( V_10 , 0x08 , 0x00 ) ) < 0 )
return V_101 ;
F_30 ( V_10 -> V_14 , V_67 , 0 , V_101 - 1 , 0 , 0 ) ;
if ( V_10 -> V_37 . V_38 ==
V_39 ) {
if ( ( V_101 = F_24 ( V_10 , 0x10 , 0x01 ) ) < 0 ) {
return V_101 ;
}
} else {
if ( ( V_101 = F_24 ( V_10 , 0x10 , 0x00 ) ) < 0 ) {
return V_101 ;
}
}
if ( ( V_101 = F_24 ( V_10 , 0x11 , 0x02 ) ) < 0 )
return V_101 ;
#if 0
if ((ret = aiptek_command(aiptek, 0x17, 0x00)) < 0)
return ret;
#endif
if ( ( V_101 = F_24 ( V_10 , 0x12 , 0xff ) ) < 0 )
return V_101 ;
V_10 -> V_40 = V_109 ;
V_10 -> V_36 = 0 ;
return 0 ;
}
static T_2 F_31 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_8 ,
F_33 ( V_10 -> V_14 , V_65 ) + 1 ,
F_33 ( V_10 -> V_14 , V_66 ) + 1 ) ;
}
static T_2 F_34 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_9 ,
F_2 ( V_114 ,
V_10 -> V_37 . V_59 ) ) ;
}
static T_2
F_35 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
int V_115 = F_1 ( V_114 , V_102 , V_4 ) ;
if ( V_115 == V_7 )
return - V_116 ;
V_10 -> V_117 . V_59 = V_115 ;
return V_4 ;
}
static T_2 F_36 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_9 ,
F_2 ( V_118 ,
V_10 -> V_37 . V_38 ) ) ;
}
static T_2
F_37 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
int V_115 = F_1 ( V_118 , V_102 , V_4 ) ;
if ( V_115 == V_7 )
return - V_116 ;
V_10 -> V_117 . V_38 = V_115 ;
return V_4 ;
}
static T_2 F_38 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_9 ,
F_2 ( V_119 ,
V_10 -> V_37 . V_64 ) ) ;
}
static T_2
F_39 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
int V_115 = F_1 ( V_119 , V_102 , V_4 ) ;
if ( V_115 == V_7 )
return - V_116 ;
V_10 -> V_117 . V_64 = V_115 ;
return V_4 ;
}
static T_2 F_40 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
if ( V_10 -> V_37 . V_71 == V_72 ) {
return snprintf ( V_102 , V_113 , L_10 ) ;
} else {
return snprintf ( V_102 , V_113 , L_11 ,
V_10 -> V_37 . V_71 ) ;
}
}
static T_2
F_41 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
long V_18 ;
if ( F_42 ( V_102 , 10 , & V_18 ) ) {
T_1 V_120 = V_102 [ V_4 - 1 ] == '\n' ? V_4 - 1 : V_4 ;
if ( strncmp ( V_102 , L_12 , V_120 ) )
return - V_116 ;
V_10 -> V_117 . V_71 = V_72 ;
} else {
if ( V_18 < V_121 || V_18 > V_122 )
return - V_116 ;
V_10 -> V_117 . V_71 = V_18 ;
}
return V_4 ;
}
static T_2 F_43 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
if ( V_10 -> V_37 . V_74 == V_72 ) {
return snprintf ( V_102 , V_113 , L_10 ) ;
} else {
return snprintf ( V_102 , V_113 , L_11 ,
V_10 -> V_37 . V_74 ) ;
}
}
static T_2
F_44 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
long V_19 ;
if ( F_42 ( V_102 , 10 , & V_19 ) ) {
T_1 V_120 = V_102 [ V_4 - 1 ] == '\n' ? V_4 - 1 : V_4 ;
if ( strncmp ( V_102 , L_12 , V_120 ) )
return - V_116 ;
V_10 -> V_117 . V_74 = V_72 ;
} else {
if ( V_19 < V_121 || V_19 > V_122 )
return - V_116 ;
V_10 -> V_117 . V_74 = V_19 ;
}
return V_4 ;
}
static T_2 F_45 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_11 , V_10 -> V_37 . V_80 ) ;
}
static T_2
F_46 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
long V_123 ;
if ( F_42 ( V_102 , 10 , & V_123 ) )
return - V_116 ;
V_10 -> V_117 . V_80 = ( int ) V_123 ;
return V_4 ;
}
static T_2 F_47 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_11 ,
V_10 -> V_37 . V_104 ) ;
}
static T_2
F_48 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
long V_124 ;
if ( F_42 ( V_102 , 10 , & V_124 ) )
return - V_116 ;
V_10 -> V_117 . V_104 = ( int ) V_124 ;
return V_4 ;
}
static T_2 F_49 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_13 , V_10 -> V_36 ) ;
}
static T_2 F_50 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
char * V_125 ;
switch ( V_10 -> V_40 ) {
case V_109 :
V_125 = L_14 ;
break;
case V_41 :
V_125 = L_15 ;
break;
case V_58 :
V_125 = L_16 ;
break;
case V_60 :
if ( V_10 -> V_37 . V_59 ==
V_126 ) {
V_125 = L_17 ;
} else {
V_125 = L_18 ;
}
break;
default:
return 0 ;
}
return snprintf ( V_102 , V_113 , V_125 ) ;
}
static T_2 F_51 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_9 ,
F_2 ( V_127 ,
V_10 -> V_37 . V_62 ) ) ;
}
static T_2
F_52 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
int V_128 = F_1 ( V_127 , V_102 , V_4 ) ;
if ( V_128 == V_7 )
return - V_116 ;
V_10 -> V_117 . V_62 = V_128 ;
return V_4 ;
}
static T_2 F_53 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_9 ,
F_2 ( V_127 ,
V_10 -> V_37 . V_61 ) ) ;
}
static T_2
F_54 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
int V_128 = F_1 ( V_127 , V_102 , V_4 ) ;
if ( V_128 == V_7 )
return - V_116 ;
V_10 -> V_117 . V_61 = V_128 ;
return V_4 ;
}
static T_2 F_55 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_9 ,
F_2 ( V_129 ,
V_10 -> V_37 . V_42 ) ) ;
}
static T_2
F_56 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
int V_128 = F_1 ( V_129 , V_102 , V_4 ) ;
if ( V_128 == V_7 )
return - V_116 ;
V_10 -> V_117 . V_42 = V_128 ;
return V_4 ;
}
static T_2 F_57 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_9 ,
F_2 ( V_129 ,
V_10 -> V_37 . V_44 ) ) ;
}
static T_2
F_58 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
int V_128 = F_1 ( V_129 , V_102 , V_4 ) ;
if ( V_128 == V_7 )
return - V_116 ;
V_10 -> V_117 . V_44 = V_128 ;
return V_4 ;
}
static T_2 F_59 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_9 ,
F_2 ( V_129 ,
V_10 -> V_37 . V_43 ) ) ;
}
static T_2
F_60 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
int V_128 = F_1 ( V_129 , V_102 , V_4 ) ;
if ( V_128 == V_7 )
return - V_116 ;
V_10 -> V_117 . V_43 = V_128 ;
return V_4 ;
}
static T_2 F_61 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
if ( V_10 -> V_37 . V_52 == V_53 ) {
return snprintf ( V_102 , V_113 , L_10 ) ;
} else {
return snprintf ( V_102 , V_113 , L_11 ,
V_10 -> V_37 . V_52 ) ;
}
}
static T_2
F_62 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
long V_130 ;
if ( F_42 ( V_102 , 10 , & V_130 ) ) return - V_116 ;
V_10 -> V_117 . V_52 = ( int ) V_130 ;
return V_4 ;
}
static T_2 F_63 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
return snprintf ( V_102 , V_113 ,
L_19 ) ;
}
static T_2
F_64 ( struct V_110 * V_83 , struct V_111 * V_112 , const char * V_102 , T_1 V_4 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
memcpy ( & V_10 -> V_37 , & V_10 -> V_117 ,
sizeof( struct V_131 ) ) ;
if ( F_29 ( V_10 ) < 0 )
return - V_86 ;
return V_4 ;
}
static T_2 F_65 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_20 , V_10 -> V_105 . V_107 ) ;
}
static T_2 F_66 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_20 , V_10 -> V_105 . V_106 ) ;
}
static T_2 F_67 ( struct V_110 * V_83 , struct V_111 * V_112 , char * V_102 )
{
struct V_10 * V_10 = F_32 ( V_83 ) ;
return snprintf ( V_102 , V_113 , L_21 ,
V_10 -> V_105 . V_108 ) ;
}
static int
F_68 ( struct V_132 * V_133 , const struct V_134 * V_135 )
{
struct V_136 * V_84 = F_69 ( V_133 ) ;
struct V_137 * V_138 ;
struct V_10 * V_10 ;
struct V_13 * V_14 ;
int V_139 ;
int V_140 [] = { 0 ,
V_141 ,
V_142 ,
V_143 ,
V_144 ,
V_145 ,
V_146
} ;
int F_14 = - V_103 ;
V_140 [ 0 ] = V_104 ;
V_10 = F_70 ( sizeof( struct V_10 ) , V_85 ) ;
V_14 = F_71 () ;
if ( ! V_10 || ! V_14 ) {
F_72 ( & V_133 -> V_83 ,
L_22 ) ;
goto V_147;
}
V_10 -> V_12 = F_73 ( V_84 , V_148 ,
V_82 , & V_10 -> V_149 ) ;
if ( ! V_10 -> V_12 ) {
F_72 ( & V_133 -> V_83 , L_23 ) ;
goto V_147;
}
V_10 -> V_9 = F_74 ( 0 , V_85 ) ;
if ( ! V_10 -> V_9 ) {
F_72 ( & V_133 -> V_83 , L_24 ) ;
goto V_150;
}
V_10 -> V_14 = V_14 ;
V_10 -> V_84 = V_84 ;
V_10 -> V_95 = V_133 -> V_151 [ 0 ] . V_152 . V_153 ;
V_10 -> V_33 = 0 ;
V_10 -> V_34 = 0 ;
V_10 -> V_79 = 0 ;
V_10 -> V_55 = - 1 ;
V_10 -> V_37 . V_59 = V_154 ;
V_10 -> V_37 . V_38 = V_39 ;
V_10 -> V_37 . V_64 = V_155 ;
V_10 -> V_37 . V_71 = V_72 ;
V_10 -> V_37 . V_74 = V_72 ;
V_10 -> V_37 . V_42 = V_156 ;
V_10 -> V_37 . V_44 = V_157 ;
V_10 -> V_37 . V_43 = V_158 ;
V_10 -> V_37 . V_62 = V_159 ;
V_10 -> V_37 . V_61 = V_160 ;
V_10 -> V_37 . V_80 = V_80 ;
V_10 -> V_37 . V_104 = V_104 ;
V_10 -> V_117 = V_10 -> V_37 ;
F_75 ( V_84 , V_10 -> V_105 . V_161 ,
sizeof( V_10 -> V_105 . V_161 ) ) ;
F_76 ( V_10 -> V_105 . V_161 , L_25 ,
sizeof( V_10 -> V_105 . V_161 ) ) ;
V_14 -> V_162 = L_26 ;
V_14 -> V_163 = V_10 -> V_105 . V_161 ;
F_77 ( V_84 , & V_14 -> V_135 ) ;
V_14 -> V_83 . V_164 = & V_133 -> V_83 ;
F_78 ( V_14 , V_10 ) ;
V_14 -> V_165 = F_15 ;
V_14 -> V_166 = F_17 ;
for ( V_139 = 0 ; V_139 < F_79 ( V_167 ) ; ++ V_139 )
F_80 ( V_167 [ V_139 ] , V_14 -> V_168 ) ;
for ( V_139 = 0 ; V_139 < F_79 ( V_169 ) ; ++ V_139 )
F_80 ( V_169 [ V_139 ] , V_14 -> V_170 ) ;
for ( V_139 = 0 ; V_139 < F_79 ( V_171 ) ; ++ V_139 )
F_80 ( V_171 [ V_139 ] , V_14 -> V_172 ) ;
F_80 ( V_173 , V_14 -> V_174 ) ;
for ( V_139 = 0 ; V_139 < F_79 ( V_175 ) ; ++ V_139 )
F_80 ( V_175 [ V_139 ] , V_14 -> V_176 ) ;
for ( V_139 = 0 ; V_139 < F_79 ( V_56 ) ; ++ V_139 )
F_80 ( V_56 [ V_139 ] , V_14 -> V_176 ) ;
F_30 ( V_14 , V_65 , 0 , 2999 , 0 , 0 ) ;
F_30 ( V_14 , V_66 , 0 , 2249 , 0 , 0 ) ;
F_30 ( V_14 , V_67 , 0 , 511 , 0 , 0 ) ;
F_30 ( V_14 , V_73 , V_121 , V_122 , 0 , 0 ) ;
F_30 ( V_14 , V_75 , V_121 , V_122 , 0 , 0 ) ;
F_30 ( V_14 , V_76 , V_177 , V_178 - 1 , 0 , 0 ) ;
V_138 = & V_133 -> V_151 [ 0 ] . V_138 [ 0 ] . V_152 ;
F_81 ( V_10 -> V_9 ,
V_10 -> V_84 ,
F_82 ( V_10 -> V_84 ,
V_138 -> V_179 ) ,
V_10 -> V_12 , 8 , F_3 , V_10 ,
V_138 -> V_180 ) ;
V_10 -> V_9 -> V_181 = V_10 -> V_149 ;
V_10 -> V_9 -> V_182 |= V_183 ;
for ( V_139 = 0 ; V_139 < F_79 ( V_140 ) ; ++ V_139 ) {
V_10 -> V_37 . V_104 = V_140 [ V_139 ] ;
( void ) F_29 ( V_10 ) ;
if ( F_33 ( V_10 -> V_14 , V_65 ) > 0 ) {
F_83 ( & V_133 -> V_83 ,
L_27 ,
V_10 -> V_37 . V_104 ) ;
break;
}
}
if ( V_139 == F_79 ( V_140 ) ) {
F_83 ( & V_133 -> V_83 ,
L_28 ) ;
goto V_150;
}
F_84 ( V_133 , V_10 ) ;
F_14 = F_85 ( & V_133 -> V_83 . V_184 , & V_185 ) ;
if ( F_14 ) {
F_72 ( & V_133 -> V_83 , L_29 ,
F_14 ) ;
goto V_186;
}
F_14 = F_86 ( V_10 -> V_14 ) ;
if ( F_14 ) {
F_72 ( & V_133 -> V_83 ,
L_30 , F_14 ) ;
goto V_187;
}
return 0 ;
V_187: F_87 ( & V_133 -> V_83 . V_184 , & V_185 ) ;
V_186: F_88 ( V_10 -> V_9 ) ;
V_150: F_89 ( V_84 , V_148 , V_10 -> V_12 ,
V_10 -> V_149 ) ;
V_147: F_84 ( V_133 , NULL ) ;
F_90 ( V_14 ) ;
F_26 ( V_10 ) ;
return F_14 ;
}
static void F_91 ( struct V_132 * V_133 )
{
struct V_10 * V_10 = F_92 ( V_133 ) ;
F_84 ( V_133 , NULL ) ;
if ( V_10 != NULL ) {
F_18 ( V_10 -> V_9 ) ;
F_93 ( V_10 -> V_14 ) ;
F_87 ( & V_133 -> V_83 . V_184 , & V_185 ) ;
F_88 ( V_10 -> V_9 ) ;
F_89 ( F_69 ( V_133 ) ,
V_148 ,
V_10 -> V_12 , V_10 -> V_149 ) ;
F_26 ( V_10 ) ;
}
}
static int T_3 F_94 ( void )
{
int V_188 = F_95 ( & V_189 ) ;
if ( V_188 == 0 ) {
F_96 (KERN_INFO KBUILD_MODNAME L_31 DRIVER_VERSION L_32
DRIVER_DESC L_33 ) ;
F_96 (KERN_INFO KBUILD_MODNAME L_31 DRIVER_AUTHOR L_33 ) ;
}
return V_188 ;
}
static void T_4 F_97 ( void )
{
F_98 ( & V_189 ) ;
}
