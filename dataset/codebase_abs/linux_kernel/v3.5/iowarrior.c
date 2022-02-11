static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , unsigned char type ,
unsigned char V_5 , void * V_6 , int V_7 )
{
return F_2 ( V_2 , F_3 ( V_2 , 0 ) ,
V_8 ,
V_9 | V_10 |
V_11 , ( type << 8 ) + V_5 ,
V_4 -> V_12 . V_13 , V_6 , V_7 ,
V_14 * V_15 ) ;
}
static int F_4 ( struct V_16 * V_17 , unsigned char type ,
unsigned char V_5 , void * V_6 , int V_7 )
{
return F_2 ( F_5 ( V_17 ) ,
F_6 ( F_5 ( V_17 ) , 0 ) ,
V_18 ,
V_10 | V_11 ,
( type << 8 ) + V_5 ,
V_17 -> V_19 -> V_12 . V_13 , V_6 ,
V_7 , V_15 ) ;
}
static void F_7 ( struct V_20 * V_20 )
{
struct V_21 * V_2 = V_20 -> V_22 ;
int V_23 ;
int V_24 ;
int V_25 ;
int V_26 ;
int V_27 = V_20 -> V_27 ;
int V_28 ;
switch ( V_27 ) {
case 0 :
break;
case - V_29 :
case - V_30 :
case - V_31 :
return;
default:
goto exit;
}
F_8 ( & V_2 -> V_32 ) ;
V_23 = F_9 ( & V_2 -> V_23 ) ;
V_25 = ( V_23 == 0 ) ? ( V_33 - 1 ) : ( V_23 - 1 ) ;
V_24 = F_9 ( & V_2 -> V_24 ) ;
if ( ( V_23 != V_24 )
&& ( V_2 -> V_34 -> V_19 -> V_12 . V_13 == 0 ) ) {
V_26 = V_25 * ( V_2 -> V_35 + 1 ) ;
if ( ! memcmp
( V_2 -> V_36 + V_26 , V_20 -> V_37 ,
V_2 -> V_35 ) ) {
F_10 ( & V_2 -> V_32 ) ;
goto exit;
}
}
V_25 = ( V_23 == ( V_33 - 1 ) ) ? 0 : ( V_23 + 1 ) ;
if ( V_24 == V_25 ) {
V_24 = ( ++ V_24 == V_33 ) ? 0 : V_24 ;
F_11 ( & V_2 -> V_24 , V_24 ) ;
F_11 ( & V_2 -> V_38 , 1 ) ;
}
V_26 = V_23 * ( V_2 -> V_35 + 1 ) ;
memcpy ( V_2 -> V_36 + V_26 , V_20 -> V_37 ,
V_2 -> V_35 ) ;
* ( V_2 -> V_36 + V_26 + ( V_2 -> V_35 ) ) = V_2 -> V_39 ++ ;
F_11 ( & V_2 -> V_23 , V_25 ) ;
F_10 ( & V_2 -> V_32 ) ;
F_12 ( & V_2 -> V_40 ) ;
exit:
V_28 = F_13 ( V_20 , V_41 ) ;
if ( V_28 )
F_14 ( & V_2 -> V_34 -> V_2 , L_1 ,
V_42 , V_28 ) ;
}
static void F_15 ( struct V_20 * V_20 )
{
struct V_21 * V_2 ;
int V_27 = V_20 -> V_27 ;
V_2 = V_20 -> V_22 ;
if ( V_27 &&
! ( V_27 == - V_30 ||
V_27 == - V_29 || V_27 == - V_31 ) ) {
F_16 ( L_2 ,
V_42 , V_27 ) ;
}
F_17 ( V_20 -> V_2 , V_20 -> V_43 ,
V_20 -> V_37 , V_20 -> V_44 ) ;
F_18 ( & V_2 -> V_45 ) ;
F_12 ( & V_2 -> V_46 ) ;
}
static inline void F_19 ( struct V_21 * V_2 )
{
F_16 ( L_3 , V_42 , V_2 -> V_47 ) ;
F_20 ( V_2 -> V_48 ) ;
F_21 ( V_2 -> V_49 ) ;
F_20 ( V_2 -> V_36 ) ;
F_20 ( V_2 ) ;
}
static int F_22 ( struct V_21 * V_2 )
{
int V_23 , V_24 ;
V_24 = F_9 ( & V_2 -> V_24 ) ;
V_23 = F_9 ( & V_2 -> V_23 ) ;
return ( V_24 == V_23 ? - 1 : V_24 ) ;
}
static T_1 F_23 ( struct V_50 * V_50 , char T_2 * V_51 ,
T_3 V_52 , T_4 * V_53 )
{
struct V_21 * V_2 ;
int V_24 ;
int V_26 ;
V_2 = V_50 -> V_54 ;
if ( V_2 == NULL || ! V_2 -> V_55 )
return - V_56 ;
F_16 ( L_4 , V_42 , V_2 -> V_47 , V_52 ) ;
if ( ( V_52 != V_2 -> V_35 )
&& ( V_52 != ( V_2 -> V_35 + 1 ) ) )
return - V_57 ;
do {
F_11 ( & V_2 -> V_38 , 0 ) ;
if ( ( V_24 = F_22 ( V_2 ) ) == - 1 ) {
if ( V_50 -> V_58 & V_59 )
return - V_60 ;
else {
int V_61 = F_24 ( V_2 -> V_40 ,
( ! V_2 -> V_55
|| ( V_24 =
F_22
( V_2 ) ) !=
- 1 ) ) ;
if ( V_61 ) {
return - V_62 ;
}
if ( ! V_2 -> V_55 ) {
return - V_56 ;
}
if ( V_24 == - 1 ) {
return 0 ;
}
}
}
V_26 = V_24 * ( V_2 -> V_35 + 1 ) ;
if ( F_25 ( V_51 , V_2 -> V_36 + V_26 , V_52 ) ) {
return - V_63 ;
}
} while ( F_9 ( & V_2 -> V_38 ) );
V_24 = ++ V_24 == V_33 ? 0 : V_24 ;
F_11 ( & V_2 -> V_24 , V_24 ) ;
return V_52 ;
}
static T_1 F_26 ( struct V_50 * V_50 ,
const char T_2 * V_64 ,
T_3 V_52 , T_4 * V_53 )
{
struct V_21 * V_2 ;
int V_28 = 0 ;
char * V_6 = NULL ;
struct V_20 * V_65 = NULL ;
V_2 = V_50 -> V_54 ;
F_27 ( & V_2 -> V_66 ) ;
if ( ! V_2 -> V_55 ) {
V_28 = - V_56 ;
goto exit;
}
F_16 ( L_4 , V_42 , V_2 -> V_47 , V_52 ) ;
if ( V_52 == 0 ) {
V_28 = 0 ;
goto exit;
}
if ( V_52 != V_2 -> V_35 ) {
V_28 = - V_57 ;
goto exit;
}
switch ( V_2 -> V_67 ) {
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_6 = F_28 ( V_52 , V_72 ) ;
if ( ! V_6 ) {
V_28 = - V_73 ;
goto exit;
}
if ( F_29 ( V_6 , V_64 , V_52 ) ) {
V_28 = - V_63 ;
F_20 ( V_6 ) ;
goto exit;
}
V_28 = F_4 ( V_2 -> V_34 , 2 , 0 , V_6 , V_52 ) ;
F_20 ( V_6 ) ;
goto exit;
break;
case V_74 :
if ( F_9 ( & V_2 -> V_45 ) == V_75 ) {
if ( V_50 -> V_58 & V_59 ) {
V_28 = - V_60 ;
goto exit;
} else {
V_28 = F_24 ( V_2 -> V_46 ,
( ! V_2 -> V_55 || ( F_9 ( & V_2 -> V_45 ) < V_75 ) ) ) ;
if ( V_28 ) {
V_28 = - V_62 ;
goto exit;
}
if ( ! V_2 -> V_55 ) {
V_28 = - V_56 ;
goto exit;
}
if ( ! V_2 -> V_76 ) {
V_28 = - V_56 ;
goto exit;
}
}
}
F_30 ( & V_2 -> V_45 ) ;
V_65 = F_31 ( 0 , V_72 ) ;
if ( ! V_65 ) {
V_28 = - V_73 ;
F_16 ( L_5 , V_42 ) ;
goto V_77;
}
V_6 = F_32 ( V_2 -> V_78 , V_2 -> V_35 ,
V_72 , & V_65 -> V_44 ) ;
if ( ! V_6 ) {
V_28 = - V_73 ;
F_16 ( L_6 , V_42 ) ;
goto V_79;
}
F_33 ( V_65 , V_2 -> V_78 ,
F_34 ( V_2 -> V_78 ,
V_2 -> V_80 -> V_81 ) ,
V_6 , V_2 -> V_35 ,
F_15 , V_2 ,
V_2 -> V_80 -> V_82 ) ;
V_65 -> V_83 |= V_84 ;
if ( F_29 ( V_6 , V_64 , V_52 ) ) {
V_28 = - V_63 ;
goto error;
}
V_28 = F_13 ( V_65 , V_72 ) ;
if ( V_28 ) {
F_16 ( L_7 , V_42 ,
V_28 , F_9 ( & V_2 -> V_45 ) ) ;
goto error;
}
V_28 = V_52 ;
F_21 ( V_65 ) ;
goto exit;
break;
default:
F_14 ( & V_2 -> V_34 -> V_2 , L_8 ,
V_42 , V_2 -> V_67 ) ;
V_28 = - V_63 ;
goto exit;
break;
}
error:
F_17 ( V_2 -> V_78 , V_2 -> V_35 , V_6 ,
V_65 -> V_44 ) ;
V_79:
F_21 ( V_65 ) ;
V_77:
F_18 ( & V_2 -> V_45 ) ;
F_12 ( & V_2 -> V_46 ) ;
exit:
F_35 ( & V_2 -> V_66 ) ;
return V_28 ;
}
static long F_36 ( struct V_50 * V_50 , unsigned int V_85 ,
unsigned long V_86 )
{
struct V_21 * V_2 = NULL ;
T_5 * V_51 ;
T_5 T_2 * V_64 ;
int V_28 ;
int V_87 ;
V_2 = V_50 -> V_54 ;
if ( V_2 == NULL ) {
return - V_56 ;
}
V_51 = F_37 ( V_2 -> V_35 , V_72 ) ;
if ( ! V_51 )
return - V_73 ;
F_27 ( & V_88 ) ;
F_27 ( & V_2 -> V_66 ) ;
if ( ! V_2 -> V_55 ) {
V_28 = - V_56 ;
goto V_89;
}
F_16 ( L_9 , V_42 , V_2 -> V_47 , V_85 ,
V_86 ) ;
V_28 = 0 ;
V_87 = 0 ;
switch ( V_85 ) {
case V_90 :
if ( V_2 -> V_67 == V_68 ||
V_2 -> V_67 == V_69 ||
V_2 -> V_67 == V_70 ||
V_2 -> V_67 == V_71 ) {
V_64 = ( T_5 T_2 * ) V_86 ;
V_87 = F_29 ( V_51 , V_64 ,
V_2 -> V_35 ) ;
if ( V_87 ) {
V_28 = - V_63 ;
} else {
V_87 = F_4 ( V_2 -> V_34 , 2 , 0 ,
V_51 ,
V_2 -> V_35 ) ;
if ( V_87 < 0 )
V_28 = V_87 ;
}
} else {
V_28 = - V_57 ;
F_14 ( & V_2 -> V_34 -> V_2 ,
L_10 ,
V_2 -> V_67 ) ;
}
break;
case V_91 :
V_64 = ( T_5 T_2 * ) V_86 ;
V_87 = F_1 ( V_2 -> V_78 ,
V_2 -> V_34 -> V_19 , 1 , 0 ,
V_51 , V_2 -> V_35 ) ;
if ( V_87 < 0 )
V_28 = V_87 ;
else {
V_87 = F_25 ( V_64 , V_51 , V_2 -> V_35 ) ;
if ( V_87 )
V_28 = - V_63 ;
}
break;
case V_92 :
{
struct V_93 V_94 ;
struct V_95 * V_96 = & V_2 -> V_78 -> V_97 -> V_12 ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_98 = F_38 ( V_2 -> V_78 -> V_99 . V_100 ) ;
V_94 . V_101 = V_2 -> V_67 ;
V_94 . V_102 = F_38 ( V_2 -> V_78 -> V_99 . V_103 ) ;
V_94 . V_104 = F_38 ( V_2 -> V_78 -> V_104 ) ;
V_94 . V_105 = V_2 -> V_34 -> V_19 -> V_12 . V_13 ;
V_94 . V_35 = V_2 -> V_35 ;
memcpy ( V_94 . V_106 , V_2 -> V_107 ,
sizeof( V_2 -> V_107 ) ) ;
if ( V_96 == NULL ) {
V_94 . V_108 = - 1 ;
} else {
V_94 . V_108 = V_96 -> V_109 * 2 ;
}
V_87 = F_25 ( (struct V_93 T_2 * ) V_86 , & V_94 ,
sizeof( struct V_93 ) ) ;
if ( V_87 )
V_28 = - V_63 ;
break;
}
default:
V_28 = - V_110 ;
break;
}
V_89:
F_35 ( & V_2 -> V_66 ) ;
F_35 ( & V_88 ) ;
F_20 ( V_51 ) ;
return V_28 ;
}
static int F_39 ( struct V_111 * V_111 , struct V_50 * V_50 )
{
struct V_21 * V_2 = NULL ;
struct V_16 * V_34 ;
int V_112 ;
int V_28 = 0 ;
F_16 ( L_11 , V_42 ) ;
F_27 ( & V_88 ) ;
V_112 = F_40 ( V_111 ) ;
V_34 = F_41 ( & V_113 , V_112 ) ;
if ( ! V_34 ) {
F_35 ( & V_88 ) ;
F_42 ( V_114 L_12 ,
V_42 , V_112 ) ;
return - V_56 ;
}
F_27 ( & V_115 ) ;
V_2 = F_43 ( V_34 ) ;
if ( ! V_2 ) {
F_35 ( & V_115 ) ;
F_35 ( & V_88 ) ;
return - V_56 ;
}
F_27 ( & V_2 -> V_66 ) ;
F_35 ( & V_115 ) ;
if ( V_2 -> V_76 ) {
V_28 = - V_116 ;
goto V_117;
}
if ( ( V_28 = F_13 ( V_2 -> V_49 , V_72 ) ) < 0 ) {
F_14 ( & V_34 -> V_2 , L_13 , V_28 ) ;
V_28 = - V_63 ;
goto V_117;
}
++ V_2 -> V_76 ;
V_50 -> V_54 = V_2 ;
V_28 = 0 ;
V_117:
F_35 ( & V_2 -> V_66 ) ;
F_35 ( & V_88 ) ;
return V_28 ;
}
static int F_44 ( struct V_111 * V_111 , struct V_50 * V_50 )
{
struct V_21 * V_2 ;
int V_28 = 0 ;
V_2 = V_50 -> V_54 ;
if ( V_2 == NULL ) {
return - V_56 ;
}
F_16 ( L_3 , V_42 , V_2 -> V_47 ) ;
F_27 ( & V_2 -> V_66 ) ;
if ( V_2 -> V_76 <= 0 ) {
V_28 = - V_56 ;
F_35 ( & V_2 -> V_66 ) ;
} else {
V_2 -> V_76 = 0 ;
V_28 = 0 ;
if ( V_2 -> V_55 ) {
F_45 ( V_2 -> V_49 ) ;
F_12 ( & V_2 -> V_40 ) ;
F_12 ( & V_2 -> V_46 ) ;
F_35 ( & V_2 -> V_66 ) ;
} else {
F_35 ( & V_2 -> V_66 ) ;
F_19 ( V_2 ) ;
}
}
return V_28 ;
}
static unsigned F_46 ( struct V_50 * V_50 , T_6 * V_118 )
{
struct V_21 * V_2 = V_50 -> V_54 ;
unsigned int V_119 = 0 ;
if ( ! V_2 -> V_55 )
return V_120 | V_121 ;
F_47 ( V_50 , & V_2 -> V_40 , V_118 ) ;
F_47 ( V_50 , & V_2 -> V_46 , V_118 ) ;
if ( ! V_2 -> V_55 )
return V_120 | V_121 ;
if ( F_22 ( V_2 ) != - 1 )
V_119 |= V_122 | V_123 ;
if ( F_9 ( & V_2 -> V_45 ) < V_75 )
V_119 |= V_124 | V_125 ;
return V_119 ;
}
static char * F_48 ( struct V_126 * V_2 , T_7 * V_127 )
{
return F_49 ( V_72 , L_14 , F_50 ( V_2 ) ) ;
}
static int F_51 ( struct V_16 * V_34 ,
const struct V_128 * V_5 )
{
struct V_1 * V_78 = F_5 ( V_34 ) ;
struct V_21 * V_2 = NULL ;
struct V_3 * V_129 ;
struct V_130 * V_131 ;
int V_132 ;
int V_28 = - V_73 ;
V_2 = F_37 ( sizeof( struct V_21 ) , V_72 ) ;
if ( V_2 == NULL ) {
F_14 ( & V_34 -> V_2 , L_15 ) ;
return V_28 ;
}
F_52 ( & V_2 -> V_66 ) ;
F_11 ( & V_2 -> V_23 , 0 ) ;
F_11 ( & V_2 -> V_24 , 0 ) ;
F_53 ( & V_2 -> V_32 ) ;
F_11 ( & V_2 -> V_38 , 0 ) ;
F_54 ( & V_2 -> V_40 ) ;
F_11 ( & V_2 -> V_45 , 0 ) ;
F_54 ( & V_2 -> V_46 ) ;
V_2 -> V_78 = V_78 ;
V_2 -> V_34 = V_34 ;
V_129 = V_34 -> V_19 ;
V_2 -> V_67 = F_38 ( V_78 -> V_99 . V_133 ) ;
for ( V_132 = 0 ; V_132 < V_129 -> V_12 . V_134 ; ++ V_132 ) {
V_131 = & V_129 -> V_131 [ V_132 ] . V_12 ;
if ( F_55 ( V_131 ) )
V_2 -> V_135 = V_131 ;
if ( F_56 ( V_131 ) )
V_2 -> V_80 = V_131 ;
}
V_2 -> V_35 = F_57 ( V_2 -> V_135 ) ;
if ( ( V_2 -> V_34 -> V_19 -> V_12 . V_13 == 0 ) &&
( V_2 -> V_67 == V_74 ) )
V_2 -> V_35 = 7 ;
V_2 -> V_49 = F_31 ( 0 , V_72 ) ;
if ( ! V_2 -> V_49 ) {
F_14 ( & V_34 -> V_2 , L_16 ) ;
goto error;
}
V_2 -> V_48 = F_28 ( V_2 -> V_35 , V_72 ) ;
if ( ! V_2 -> V_48 ) {
F_14 ( & V_34 -> V_2 , L_17 ) ;
goto error;
}
F_33 ( V_2 -> V_49 , V_2 -> V_78 ,
F_58 ( V_2 -> V_78 ,
V_2 -> V_135 -> V_81 ) ,
V_2 -> V_48 , V_2 -> V_35 ,
F_7 , V_2 ,
V_2 -> V_135 -> V_82 ) ;
V_2 -> V_36 =
F_28 ( ( ( V_2 -> V_35 + 1 ) * V_33 ) ,
V_72 ) ;
if ( ! V_2 -> V_36 ) {
F_14 ( & V_34 -> V_2 , L_18 ) ;
goto error;
}
memset ( V_2 -> V_107 , 0x00 , sizeof( V_2 -> V_107 ) ) ;
F_59 ( V_78 , V_78 -> V_99 . V_136 , V_2 -> V_107 ,
sizeof( V_2 -> V_107 ) ) ;
if ( strlen ( V_2 -> V_107 ) != 8 )
memset ( V_2 -> V_107 , 0x00 , sizeof( V_2 -> V_107 ) ) ;
if ( V_2 -> V_34 -> V_19 -> V_12 . V_13 == 0 ) {
F_2 ( V_78 , F_6 ( V_78 , 0 ) ,
0x0A ,
V_10 | V_11 , 0 ,
0 , NULL , 0 , V_137 ) ;
}
V_2 -> V_55 = 1 ;
F_60 ( V_34 , V_2 ) ;
V_28 = F_61 ( V_34 , & V_138 ) ;
if ( V_28 ) {
F_14 ( & V_34 -> V_2 , L_19 ) ;
F_60 ( V_34 , NULL ) ;
goto error;
}
V_2 -> V_47 = V_34 -> V_47 ;
F_62 ( & V_34 -> V_2 , L_20
L_21 , V_2 -> V_67 , V_2 -> V_107 ,
V_129 -> V_12 . V_13 , V_2 -> V_47 - V_139 ) ;
return V_28 ;
error:
F_19 ( V_2 ) ;
return V_28 ;
}
static void F_63 ( struct V_16 * V_34 )
{
struct V_21 * V_2 ;
int V_47 ;
V_2 = F_43 ( V_34 ) ;
F_27 ( & V_115 ) ;
F_60 ( V_34 , NULL ) ;
V_47 = V_2 -> V_47 ;
F_64 ( V_34 , & V_138 ) ;
F_27 ( & V_2 -> V_66 ) ;
V_2 -> V_55 = 0 ;
F_35 ( & V_2 -> V_66 ) ;
F_35 ( & V_115 ) ;
if ( V_2 -> V_76 ) {
F_45 ( V_2 -> V_49 ) ;
F_12 ( & V_2 -> V_40 ) ;
F_12 ( & V_2 -> V_46 ) ;
} else {
F_19 ( V_2 ) ;
}
F_62 ( & V_34 -> V_2 , L_22 ,
V_47 - V_139 ) ;
}
