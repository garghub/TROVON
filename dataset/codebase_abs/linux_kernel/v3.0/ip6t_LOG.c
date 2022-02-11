static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 , unsigned int V_7 ,
int V_8 )
{
T_1 V_9 ;
int V_10 ;
struct V_11 V_12 ;
const struct V_11 * V_13 ;
unsigned int V_14 ;
unsigned int V_15 = 0 ;
unsigned int V_16 ;
if ( V_4 -> type == V_17 )
V_16 = V_4 -> V_18 . log . V_16 ;
else
V_16 = V_19 ;
V_13 = F_2 ( V_6 , V_7 , sizeof( V_12 ) , & V_12 ) ;
if ( V_13 == NULL ) {
F_3 ( V_2 , L_1 ) ;
return;
}
F_3 ( V_2 , L_2 , & V_13 -> V_20 , & V_13 -> V_21 ) ;
F_3 ( V_2 , L_3 ,
F_4 ( V_13 -> V_22 ) + sizeof( struct V_11 ) ,
( F_5 ( * ( V_23 * ) V_13 ) & 0x0ff00000 ) >> 20 ,
V_13 -> V_24 ,
( F_5 ( * ( V_23 * ) V_13 ) & 0x000fffff ) ) ;
V_10 = 0 ;
V_14 = V_7 + sizeof( struct V_11 ) ;
V_9 = V_13 -> V_25 ;
while ( V_9 != V_26 && F_6 ( V_9 ) ) {
struct V_27 V_28 ;
const struct V_27 * V_29 ;
V_29 = F_2 ( V_6 , V_14 , sizeof( V_28 ) , & V_28 ) ;
if ( V_29 == NULL ) {
F_3 ( V_2 , L_1 ) ;
return;
}
if ( V_16 & V_30 )
F_3 ( V_2 , L_4 ) ;
switch ( V_9 ) {
case V_31 : {
struct V_32 V_33 ;
const struct V_32 * V_34 ;
F_3 ( V_2 , L_5 ) ;
V_34 = F_2 ( V_6 , V_14 , sizeof( V_33 ) ,
& V_33 ) ;
if ( V_34 == NULL ) {
F_3 ( V_2 , L_6 ) ;
return;
}
F_3 ( V_2 , L_7 , F_4 ( V_34 -> V_35 ) & 0xFFF8 ) ;
if ( V_34 -> V_35 & F_7 ( 0x0001 ) )
F_3 ( V_2 , L_8 ) ;
F_3 ( V_2 , L_9 , F_5 ( V_34 -> V_36 ) ) ;
if ( F_4 ( V_34 -> V_35 ) & 0xFFF8 )
V_10 = 1 ;
V_15 = 8 ;
break;
}
case V_37 :
case V_38 :
case V_39 :
if ( V_10 ) {
if ( V_16 & V_30 )
F_3 ( V_2 , L_10 ) ;
return;
}
V_15 = F_8 ( V_29 ) ;
break;
case V_40 :
if ( V_16 & V_30 ) {
struct V_41 V_42 ;
const struct V_41 * V_43 ;
F_3 ( V_2 , L_11 ) ;
if ( V_10 ) {
F_3 ( V_2 , L_10 ) ;
return;
}
V_43 = F_2 ( V_6 , V_14 , sizeof( V_42 ) ,
& V_42 ) ;
if ( V_43 == NULL ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_44 - V_14 ) ;
return;
}
F_3 ( V_2 , L_13 , F_5 ( V_43 -> V_45 ) ) ;
}
V_15 = ( V_29 -> V_15 + 2 ) << 2 ;
break;
case V_46 :
if ( V_16 & V_30 ) {
struct V_47 V_48 ;
const struct V_47 * V_49 ;
F_3 ( V_2 , L_14 ) ;
if ( V_10 ) {
F_3 ( V_2 , L_10 ) ;
return;
}
V_49 = F_2 ( V_6 , V_14 , sizeof( V_48 ) ,
& V_48 ) ;
if ( V_49 == NULL ) {
F_3 ( V_2 , L_12 ,
V_6 -> V_44 - V_14 ) ;
return;
}
F_3 ( V_2 , L_15 , F_5 ( V_49 -> V_45 ) ) ;
}
return;
default:
F_3 ( V_2 , L_16 , V_9 ) ;
return;
}
if ( V_16 & V_30 )
F_3 ( V_2 , L_17 ) ;
V_9 = V_29 -> V_25 ;
V_14 += V_15 ;
}
switch ( V_9 ) {
case V_50 : {
struct V_51 V_52 ;
const struct V_51 * V_53 ;
F_3 ( V_2 , L_18 ) ;
if ( V_10 )
break;
V_53 = F_2 ( V_6 , V_14 , sizeof( V_52 ) , & V_52 ) ;
if ( V_53 == NULL ) {
F_3 ( V_2 , L_19 , V_6 -> V_44 - V_14 ) ;
return;
}
F_3 ( V_2 , L_20 ,
F_4 ( V_53 -> V_54 ) , F_4 ( V_53 -> V_55 ) ) ;
if ( V_16 & V_56 )
F_3 ( V_2 , L_21 ,
F_5 ( V_53 -> V_57 ) , F_5 ( V_53 -> V_58 ) ) ;
F_3 ( V_2 , L_22 , F_4 ( V_53 -> V_59 ) ) ;
F_3 ( V_2 , L_23 , ( T_1 ) ( F_5 ( F_9 ( V_53 ) & V_60 ) >> 22 ) ) ;
if ( V_53 -> V_61 )
F_3 ( V_2 , L_24 ) ;
if ( V_53 -> V_62 )
F_3 ( V_2 , L_25 ) ;
if ( V_53 -> V_63 )
F_3 ( V_2 , L_26 ) ;
if ( V_53 -> V_64 )
F_3 ( V_2 , L_27 ) ;
if ( V_53 -> V_65 )
F_3 ( V_2 , L_28 ) ;
if ( V_53 -> V_66 )
F_3 ( V_2 , L_29 ) ;
if ( V_53 -> V_67 )
F_3 ( V_2 , L_30 ) ;
if ( V_53 -> V_68 )
F_3 ( V_2 , L_31 ) ;
F_3 ( V_2 , L_32 , F_4 ( V_53 -> V_69 ) ) ;
if ( ( V_16 & V_70 ) &&
V_53 -> V_71 * 4 > sizeof( struct V_51 ) ) {
T_1 V_72 [ 60 - sizeof( struct V_51 ) ] ;
const T_1 * V_73 ;
unsigned int V_74 ;
unsigned int V_75 = V_53 -> V_71 * 4
- sizeof( struct V_51 ) ;
V_73 = F_2 ( V_6 ,
V_14 + sizeof( struct V_51 ) ,
V_75 , V_72 ) ;
if ( V_73 == NULL ) {
F_3 ( V_2 , L_33 ) ;
return;
}
F_3 ( V_2 , L_34 ) ;
for ( V_74 = 0 ; V_74 < V_75 ; V_74 ++ )
F_3 ( V_2 , L_35 , V_73 [ V_74 ] ) ;
F_3 ( V_2 , L_17 ) ;
}
break;
}
case V_76 :
case V_77 : {
struct V_78 V_79 ;
const struct V_78 * V_80 ;
if ( V_9 == V_76 )
F_3 ( V_2 , L_36 ) ;
else
F_3 ( V_2 , L_37 ) ;
if ( V_10 )
break;
V_80 = F_2 ( V_6 , V_14 , sizeof( V_79 ) , & V_79 ) ;
if ( V_80 == NULL ) {
F_3 ( V_2 , L_19 , V_6 -> V_44 - V_14 ) ;
return;
}
F_3 ( V_2 , L_38 ,
F_4 ( V_80 -> V_54 ) , F_4 ( V_80 -> V_55 ) ,
F_4 ( V_80 -> V_44 ) ) ;
break;
}
case V_81 : {
struct V_82 V_83 ;
const struct V_82 * V_84 ;
F_3 ( V_2 , L_39 ) ;
if ( V_10 )
break;
V_84 = F_2 ( V_6 , V_14 , sizeof( V_83 ) , & V_83 ) ;
if ( V_84 == NULL ) {
F_3 ( V_2 , L_19 , V_6 -> V_44 - V_14 ) ;
return;
}
F_3 ( V_2 , L_40 , V_84 -> V_85 , V_84 -> V_86 ) ;
switch ( V_84 -> V_85 ) {
case V_87 :
case V_88 :
F_3 ( V_2 , L_41 ,
F_4 ( V_84 -> V_89 ) ,
F_4 ( V_84 -> V_90 ) ) ;
break;
case V_91 :
case V_92 :
case V_93 :
break;
case V_94 :
F_3 ( V_2 , L_42 , F_5 ( V_84 -> V_95 ) ) ;
case V_96 :
case V_97 :
case V_98 :
if ( V_8 ) {
F_3 ( V_2 , L_43 ) ;
F_1 ( V_2 , V_4 , V_6 ,
V_14 + sizeof( V_83 ) , 0 ) ;
F_3 ( V_2 , L_44 ) ;
}
if ( V_84 -> V_85 == V_97 )
F_3 ( V_2 , L_45 , F_5 ( V_84 -> V_99 ) ) ;
}
break;
}
default:
F_3 ( V_2 , L_46 , V_9 ) ;
}
if ( ( V_16 & V_100 ) && V_8 && V_6 -> V_101 ) {
F_10 ( & V_6 -> V_101 -> V_102 ) ;
if ( V_6 -> V_101 -> V_103 && V_6 -> V_101 -> V_103 -> V_104 )
F_3 ( V_2 , L_47 ,
V_6 -> V_101 -> V_103 -> V_104 -> V_105 -> V_106 ,
V_6 -> V_101 -> V_103 -> V_104 -> V_105 -> V_107 ) ;
F_11 ( & V_6 -> V_101 -> V_102 ) ;
}
if ( ! V_8 && V_6 -> V_108 )
F_3 ( V_2 , L_48 , V_6 -> V_108 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
struct V_109 * V_110 = V_6 -> V_110 ;
unsigned int V_16 = 0 ;
if ( V_4 -> type == V_17 )
V_16 = V_4 -> V_18 . log . V_16 ;
if ( ! ( V_16 & V_111 ) )
goto V_112;
switch ( V_110 -> type ) {
case V_113 :
F_3 ( V_2 , L_49 ,
F_13 ( V_6 ) -> V_114 , F_13 ( V_6 ) -> V_115 ,
F_4 ( F_13 ( V_6 ) -> V_116 ) ) ;
return;
default:
break;
}
V_112:
F_3 ( V_2 , L_50 ) ;
if ( V_110 -> V_117 &&
V_6 -> V_118 != V_6 -> V_119 ) {
const unsigned char * V_120 = F_14 ( V_6 ) ;
unsigned int V_44 = V_110 -> V_117 ;
unsigned int V_74 ;
if ( V_110 -> type == V_121 &&
( V_120 -= V_122 ) < V_6 -> V_123 )
V_120 = NULL ;
if ( V_120 != NULL ) {
F_3 ( V_2 , L_51 , * V_120 ++ ) ;
for ( V_74 = 1 ; V_74 < V_44 ; V_74 ++ )
F_3 ( V_2 , L_52 , * V_120 ++ ) ;
}
F_3 ( V_2 , L_53 ) ;
if ( V_110 -> type == V_121 ) {
const struct V_124 * V_125 =
(struct V_124 * ) F_14 ( V_6 ) ;
F_3 ( V_2 , L_54 , & V_125 -> V_20 , & V_125 -> V_21 ) ;
}
} else
F_3 ( V_2 , L_53 ) ;
}
static void
F_15 ( T_1 V_126 ,
unsigned int V_127 ,
const struct V_5 * V_6 ,
const struct V_109 * V_128 ,
const struct V_109 * V_129 ,
const struct V_3 * V_130 ,
const char * V_131 )
{
struct V_1 * V_2 = F_16 () ;
if ( ! V_130 )
V_130 = & V_132 ;
F_3 ( V_2 , L_55 , V_130 -> V_18 . log . V_133 ,
V_131 ,
V_128 ? V_128 -> V_134 : L_56 ,
V_129 ? V_129 -> V_134 : L_56 ) ;
if ( V_128 != NULL )
F_12 ( V_2 , V_130 , V_6 ) ;
F_1 ( V_2 , V_130 , V_6 , F_17 ( V_6 ) , 1 ) ;
F_18 ( V_2 ) ;
}
static unsigned int
F_19 ( struct V_5 * V_6 , const struct V_135 * V_136 )
{
const struct V_137 * V_130 = V_136 -> V_138 ;
struct V_3 V_139 ;
V_139 . type = V_17 ;
V_139 . V_18 . log . V_133 = V_130 -> V_133 ;
V_139 . V_18 . log . V_16 = V_130 -> V_16 ;
F_15 ( V_140 , V_136 -> V_127 , V_6 , V_136 -> V_128 , V_136 -> V_129 ,
& V_139 , V_130 -> V_131 ) ;
return V_141 ;
}
static int F_20 ( const struct V_142 * V_136 )
{
const struct V_137 * V_130 = V_136 -> V_138 ;
if ( V_130 -> V_133 >= 8 ) {
F_21 ( L_57 , V_130 -> V_133 ) ;
return - V_143 ;
}
if ( V_130 -> V_131 [ sizeof( V_130 -> V_131 ) - 1 ] != '\0' ) {
F_21 ( L_58 ) ;
return - V_143 ;
}
return 0 ;
}
static int T_2 F_22 ( void )
{
int V_144 ;
V_144 = F_23 ( & V_145 ) ;
if ( V_144 < 0 )
return V_144 ;
F_24 ( V_140 , & V_146 ) ;
return 0 ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_146 ) ;
F_27 ( & V_145 ) ;
}
