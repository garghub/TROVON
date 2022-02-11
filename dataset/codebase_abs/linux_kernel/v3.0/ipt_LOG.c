static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 ,
unsigned int V_7 )
{
struct V_8 V_9 ;
const struct V_8 * V_10 ;
unsigned int V_11 ;
if ( V_4 -> type == V_12 )
V_11 = V_4 -> V_13 . log . V_11 ;
else
V_11 = V_14 ;
V_10 = F_2 ( V_6 , V_7 , sizeof( V_9 ) , & V_9 ) ;
if ( V_10 == NULL ) {
F_3 ( V_2 , L_1 ) ;
return;
}
F_3 ( V_2 , L_2 ,
& V_10 -> V_15 , & V_10 -> V_16 ) ;
F_3 ( V_2 , L_3 ,
F_4 ( V_10 -> V_17 ) , V_10 -> V_18 & V_19 ,
V_10 -> V_18 & V_20 , V_10 -> V_21 , F_4 ( V_10 -> V_22 ) ) ;
if ( F_4 ( V_10 -> V_23 ) & V_24 )
F_3 ( V_2 , L_4 ) ;
if ( F_4 ( V_10 -> V_23 ) & V_25 )
F_3 ( V_2 , L_5 ) ;
if ( F_4 ( V_10 -> V_23 ) & V_26 )
F_3 ( V_2 , L_6 ) ;
if ( F_4 ( V_10 -> V_23 ) & V_27 )
F_3 ( V_2 , L_7 , F_4 ( V_10 -> V_23 ) & V_27 ) ;
if ( ( V_11 & V_28 ) &&
V_10 -> V_29 * 4 > sizeof( struct V_8 ) ) {
const unsigned char * V_30 ;
unsigned char V_31 [ 4 * 15 - sizeof( struct V_8 ) ] ;
unsigned int V_32 , V_33 ;
V_33 = V_10 -> V_29 * 4 - sizeof( struct V_8 ) ;
V_30 = F_2 ( V_6 , V_7 + sizeof( V_9 ) ,
V_33 , V_31 ) ;
if ( V_30 == NULL ) {
F_3 ( V_2 , L_1 ) ;
return;
}
F_3 ( V_2 , L_8 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
F_3 ( V_2 , L_9 , V_30 [ V_32 ] ) ;
F_3 ( V_2 , L_10 ) ;
}
switch ( V_10 -> V_34 ) {
case V_35 : {
struct V_36 V_37 ;
const struct V_36 * V_38 ;
F_3 ( V_2 , L_11 ) ;
if ( F_4 ( V_10 -> V_23 ) & V_27 )
break;
V_38 = F_2 ( V_6 , V_7 + V_10 -> V_29 * 4 ,
sizeof( V_37 ) , & V_37 ) ;
if ( V_38 == NULL ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_39 - V_7 - V_10 -> V_29 * 4 ) ;
break;
}
F_3 ( V_2 , L_13 ,
F_4 ( V_38 -> V_40 ) , F_4 ( V_38 -> V_41 ) ) ;
if ( V_11 & V_42 )
F_3 ( V_2 , L_14 ,
F_5 ( V_38 -> V_43 ) , F_5 ( V_38 -> V_44 ) ) ;
F_3 ( V_2 , L_15 , F_4 ( V_38 -> V_45 ) ) ;
F_3 ( V_2 , L_16 , ( V_46 ) ( F_5 ( F_6 ( V_38 ) & V_47 ) >> 22 ) ) ;
if ( V_38 -> V_48 )
F_3 ( V_2 , L_17 ) ;
if ( V_38 -> V_49 )
F_3 ( V_2 , L_18 ) ;
if ( V_38 -> V_50 )
F_3 ( V_2 , L_19 ) ;
if ( V_38 -> V_51 )
F_3 ( V_2 , L_20 ) ;
if ( V_38 -> V_52 )
F_3 ( V_2 , L_21 ) ;
if ( V_38 -> V_53 )
F_3 ( V_2 , L_22 ) ;
if ( V_38 -> V_54 )
F_3 ( V_2 , L_23 ) ;
if ( V_38 -> V_55 )
F_3 ( V_2 , L_24 ) ;
F_3 ( V_2 , L_25 , F_4 ( V_38 -> V_56 ) ) ;
if ( ( V_11 & V_57 ) &&
V_38 -> V_58 * 4 > sizeof( struct V_36 ) ) {
unsigned char V_31 [ 4 * 15 - sizeof( struct V_36 ) ] ;
const unsigned char * V_30 ;
unsigned int V_32 , V_33 ;
V_33 = V_38 -> V_58 * 4 - sizeof( struct V_36 ) ;
V_30 = F_2 ( V_6 ,
V_7 + V_10 -> V_29 * 4 + sizeof( V_37 ) ,
V_33 , V_31 ) ;
if ( V_30 == NULL ) {
F_3 ( V_2 , L_1 ) ;
return;
}
F_3 ( V_2 , L_8 ) ;
for ( V_32 = 0 ; V_32 < V_33 ; V_32 ++ )
F_3 ( V_2 , L_9 , V_30 [ V_32 ] ) ;
F_3 ( V_2 , L_10 ) ;
}
break;
}
case V_59 :
case V_60 : {
struct V_61 V_62 ;
const struct V_61 * V_63 ;
if ( V_10 -> V_34 == V_59 )
F_3 ( V_2 , L_26 ) ;
else
F_3 ( V_2 , L_27 ) ;
if ( F_4 ( V_10 -> V_23 ) & V_27 )
break;
V_63 = F_2 ( V_6 , V_7 + V_10 -> V_29 * 4 ,
sizeof( V_62 ) , & V_62 ) ;
if ( V_63 == NULL ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_39 - V_7 - V_10 -> V_29 * 4 ) ;
break;
}
F_3 ( V_2 , L_28 ,
F_4 ( V_63 -> V_40 ) , F_4 ( V_63 -> V_41 ) ,
F_4 ( V_63 -> V_39 ) ) ;
break;
}
case V_64 : {
struct V_65 V_66 ;
const struct V_65 * V_67 ;
static const T_1 V_68 [ V_69 + 1 ]
= { [ V_70 ] = 4 ,
[ V_71 ]
= 8 + sizeof( struct V_8 ) ,
[ V_72 ]
= 8 + sizeof( struct V_8 ) ,
[ V_73 ]
= 8 + sizeof( struct V_8 ) ,
[ V_74 ] = 4 ,
[ V_75 ]
= 8 + sizeof( struct V_8 ) ,
[ V_76 ]
= 8 + sizeof( struct V_8 ) ,
[ V_77 ] = 20 ,
[ V_78 ] = 20 ,
[ V_79 ] = 12 ,
[ V_80 ] = 12 } ;
F_3 ( V_2 , L_29 ) ;
if ( F_4 ( V_10 -> V_23 ) & V_27 )
break;
V_67 = F_2 ( V_6 , V_7 + V_10 -> V_29 * 4 ,
sizeof( V_66 ) , & V_66 ) ;
if ( V_67 == NULL ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_39 - V_7 - V_10 -> V_29 * 4 ) ;
break;
}
F_3 ( V_2 , L_30 , V_67 -> type , V_67 -> V_81 ) ;
if ( V_67 -> type <= V_69 &&
V_68 [ V_67 -> type ] &&
V_6 -> V_39 - V_7 - V_10 -> V_29 * 4 < V_68 [ V_67 -> type ] ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_39 - V_7 - V_10 -> V_29 * 4 ) ;
break;
}
switch ( V_67 -> type ) {
case V_70 :
case V_74 :
F_3 ( V_2 , L_31 ,
F_4 ( V_67 -> V_82 . V_83 . V_22 ) ,
F_4 ( V_67 -> V_82 . V_83 . V_84 ) ) ;
break;
case V_76 :
F_3 ( V_2 , L_32 ,
F_5 ( V_67 -> V_82 . V_85 ) >> 24 ) ;
break;
case V_73 :
F_3 ( V_2 , L_33 , & V_67 -> V_82 . V_85 ) ;
case V_71 :
case V_72 :
case V_75 :
if ( ! V_7 ) {
F_3 ( V_2 , L_34 ) ;
F_1 ( V_2 , V_4 , V_6 ,
V_7 + V_10 -> V_29 * 4 + sizeof( V_66 ) ) ;
F_3 ( V_2 , L_35 ) ;
}
if ( V_67 -> type == V_71 &&
V_67 -> V_81 == V_86 )
F_3 ( V_2 , L_36 , F_4 ( V_67 -> V_82 . V_87 . V_88 ) ) ;
}
break;
}
case V_89 : {
struct V_90 V_91 ;
const struct V_90 * V_92 ;
if ( F_4 ( V_10 -> V_23 ) & V_27 )
break;
F_3 ( V_2 , L_37 ) ;
V_92 = F_2 ( V_6 , V_7 + V_10 -> V_29 * 4 ,
sizeof( V_91 ) , & V_91 ) ;
if ( V_92 == NULL ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_39 - V_7 - V_10 -> V_29 * 4 ) ;
break;
}
F_3 ( V_2 , L_38 , F_5 ( V_92 -> V_93 ) ) ;
break;
}
case V_94 : {
struct V_95 V_96 ;
const struct V_95 * V_97 ;
F_3 ( V_2 , L_39 ) ;
if ( F_4 ( V_10 -> V_23 ) & V_27 )
break;
V_97 = F_2 ( V_6 , V_7 + V_10 -> V_29 * 4 ,
sizeof( V_96 ) , & V_96 ) ;
if ( V_97 == NULL ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_39 - V_7 - V_10 -> V_29 * 4 ) ;
break;
}
F_3 ( V_2 , L_38 , F_5 ( V_97 -> V_93 ) ) ;
break;
}
default:
F_3 ( V_2 , L_40 , V_10 -> V_34 ) ;
}
if ( ( V_11 & V_98 ) && ! V_7 && V_6 -> V_99 ) {
F_7 ( & V_6 -> V_99 -> V_100 ) ;
if ( V_6 -> V_99 -> V_101 && V_6 -> V_99 -> V_101 -> V_102 )
F_3 ( V_2 , L_41 ,
V_6 -> V_99 -> V_101 -> V_102 -> V_103 -> V_104 ,
V_6 -> V_99 -> V_101 -> V_102 -> V_103 -> V_105 ) ;
F_8 ( & V_6 -> V_99 -> V_100 ) ;
}
if ( ! V_7 && V_6 -> V_106 )
F_3 ( V_2 , L_42 , V_6 -> V_106 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_107 * V_108 = V_6 -> V_108 ;
unsigned int V_11 = 0 ;
if ( V_4 -> type == V_12 )
V_11 = V_4 -> V_13 . log . V_11 ;
if ( ! ( V_11 & V_109 ) )
goto V_110;
switch ( V_108 -> type ) {
case V_111 :
F_3 ( V_2 , L_43 ,
F_10 ( V_6 ) -> V_112 , F_10 ( V_6 ) -> V_113 ,
F_4 ( F_10 ( V_6 ) -> V_114 ) ) ;
return;
default:
break;
}
V_110:
F_3 ( V_2 , L_44 ) ;
if ( V_108 -> V_115 &&
V_6 -> V_116 != V_6 -> V_117 ) {
const unsigned char * V_118 = F_11 ( V_6 ) ;
unsigned int V_32 ;
F_3 ( V_2 , L_45 , * V_118 ++ ) ;
for ( V_32 = 1 ; V_32 < V_108 -> V_115 ; V_32 ++ , V_118 ++ )
F_3 ( V_2 , L_46 , * V_118 ) ;
}
F_3 ( V_2 , L_47 ) ;
}
static void
F_12 ( T_2 V_119 ,
unsigned int V_120 ,
const struct V_5 * V_6 ,
const struct V_107 * V_121 ,
const struct V_107 * V_122 ,
const struct V_3 * V_123 ,
const char * V_124 )
{
struct V_1 * V_2 = F_13 () ;
if ( ! V_123 )
V_123 = & V_125 ;
F_3 ( V_2 , L_48 , V_123 -> V_13 . log . V_126 ,
V_124 ,
V_121 ? V_121 -> V_127 : L_49 ,
V_122 ? V_122 -> V_127 : L_49 ) ;
#ifdef F_14
if ( V_6 -> V_128 ) {
const struct V_107 * V_129 ;
const struct V_107 * V_130 ;
V_129 = V_6 -> V_128 -> V_129 ;
if ( V_129 && V_121 != V_129 )
F_3 ( V_2 , L_50 , V_129 -> V_127 ) ;
V_130 = V_6 -> V_128 -> V_130 ;
if ( V_130 && V_122 != V_130 )
F_3 ( V_2 , L_51 , V_130 -> V_127 ) ;
}
#endif
if ( V_121 != NULL )
F_9 ( V_2 , V_123 , V_6 ) ;
F_1 ( V_2 , V_123 , V_6 , 0 ) ;
F_15 ( V_2 ) ;
}
static unsigned int
F_16 ( struct V_5 * V_6 , const struct V_131 * V_132 )
{
const struct V_133 * V_123 = V_132 -> V_134 ;
struct V_3 V_135 ;
V_135 . type = V_12 ;
V_135 . V_13 . log . V_126 = V_123 -> V_126 ;
V_135 . V_13 . log . V_11 = V_123 -> V_11 ;
F_12 ( V_136 , V_132 -> V_120 , V_6 , V_132 -> V_121 , V_132 -> V_122 , & V_135 ,
V_123 -> V_124 ) ;
return V_137 ;
}
static int F_17 ( const struct V_138 * V_132 )
{
const struct V_133 * V_123 = V_132 -> V_134 ;
if ( V_123 -> V_126 >= 8 ) {
F_18 ( L_52 , V_123 -> V_126 ) ;
return - V_139 ;
}
if ( V_123 -> V_124 [ sizeof( V_123 -> V_124 ) - 1 ] != '\0' ) {
F_18 ( L_53 ) ;
return - V_139 ;
}
return 0 ;
}
static int T_3 F_19 ( void )
{
int V_140 ;
V_140 = F_20 ( & V_141 ) ;
if ( V_140 < 0 )
return V_140 ;
F_21 ( V_136 , & V_142 ) ;
return 0 ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_142 ) ;
F_24 ( & V_141 ) ;
}
