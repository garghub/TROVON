static int F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return V_3 ;
case V_4 :
return V_5 ;
case V_6 :
return V_7 ;
case V_8 :
return V_9 ;
case V_10 :
return V_11 ;
case V_12 :
return V_13 ;
case V_14 :
return V_15 ;
case V_16 :
return V_17 ;
case V_18 :
return V_19 ;
case V_20 :
return V_21 ;
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
}
return - 1 ;
}
static int F_2 ( int V_26 )
{
switch ( V_26 ) {
case V_27 :
case V_7 :
case V_19 :
case V_9 :
return V_28 ;
}
return 0 ;
}
static struct V_29 * F_3 ( struct V_30 * V_31 )
{
int V_32 ;
unsigned int V_33 ;
V_32 = F_4 ( V_31 -> V_34 + V_35 ) ;
if ( ! V_32 )
goto V_36;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ )
if ( ( V_32 != V_31 -> V_38 [ V_33 ] . V_39 ) &&
( V_32 != V_31 -> V_38 [ V_33 ] . V_40 ) )
return & V_31 -> V_38 [ V_33 ] ;
F_5 ( L_1 ,
F_6 ( & V_31 -> V_41 ) , V_32 ) ;
V_36:
return & V_31 -> V_38 [ 0 ] ;
}
static
struct V_29 * F_7 ( struct V_30 * V_31 )
{
int V_32 ;
unsigned int V_33 ;
V_32 = F_4 ( V_31 -> V_34 + V_35 ) ;
if ( ! V_32 )
goto V_36;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ )
if ( ( V_32 == V_31 -> V_38 [ V_33 ] . V_39 ) ||
( V_32 == V_31 -> V_38 [ V_33 ] . V_40 ) )
return & V_31 -> V_38 [ V_33 ] ;
V_36:
F_8 ( L_2 ,
V_32 , F_6 ( & V_31 -> V_41 ) ) ;
return NULL ;
}
static void F_9 ( struct V_30 * V_31 )
{
struct V_42 * V_42 = & V_31 -> V_41 . V_42 ;
struct V_43 * V_44 = F_10 ( V_42 -> V_45 ) ;
struct V_46 * V_47 = F_11 ( V_31 -> V_48 ) ;
unsigned int V_33 ;
F_8 ( L_3 , F_6 ( & V_31 -> V_41 ) ) ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
V_31 -> V_38 [ V_33 ] . V_49 -> V_50 |= V_51 ;
V_31 -> V_38 [ V_33 ] . V_52 -> V_50 |= V_51 ;
}
if ( F_12 ( V_44 -> V_53 == V_54 ?
V_47 -> V_55 : V_47 -> V_56 , & V_31 -> V_57 ) )
F_8 ( L_4 ) ;
if ( V_31 -> V_58 )
F_13 ( V_31 -> V_58 ) ;
V_31 -> V_41 . V_59 = V_60 ;
}
int F_14 ( struct V_61 * V_62 ,
unsigned long V_63 , void * V_64 )
{
struct V_30 * V_31 = F_15 ( V_62 , struct V_30 , V_57 ) ;
if ( V_31 -> V_41 . V_59 == V_65 ) {
F_8 ( L_5 ,
F_6 ( & V_31 -> V_41 ) ) ;
F_9 ( V_31 ) ;
}
switch ( V_63 ) {
case V_66 :
V_31 -> V_67 = true ;
break;
case V_68 :
V_31 -> V_67 = false ;
break;
default:
F_5 ( L_6 , V_63 ) ;
break;
}
return 0 ;
}
static void F_16 ( struct V_30 * V_31 )
{
struct V_69 * V_70 = V_31 -> V_48 -> V_71 ;
T_1 V_72 ;
void * V_73 ;
unsigned int V_33 , V_74 ;
V_74 = sizeof( struct V_75 ) *
V_76 * V_37 ;
V_73 = F_17 ( V_31 -> V_48 ,
V_74 , & V_72 , V_77 | V_78 ) ;
if ( ! V_73 ) {
F_5 ( L_7 ) ;
return;
}
memset ( V_73 , 0 , V_74 ) ;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ ) {
if ( V_72 & 0xF ) {
F_5 ( L_8 ) ;
return;
}
V_31 -> V_38 [ V_33 ] . V_49 = V_73 ;
V_31 -> V_38 [ V_33 ] . V_40 = V_72 ;
F_8 ( L_9 , V_33 , V_73 ) ;
V_73 += sizeof( struct V_75 ) ;
V_72 += sizeof( struct V_75 ) ;
if ( V_72 & 0xF ) {
F_5 ( L_8 ) ;
return;
}
V_31 -> V_38 [ V_33 ] . V_52 = V_73 ;
V_31 -> V_38 [ V_33 ] . V_39 = V_72 ;
F_8 ( L_10 , V_33 , V_73 ) ;
V_73 += sizeof( struct V_75 ) ;
V_72 += sizeof( struct V_75 ) ;
}
if ( F_18 ( V_70 , L_11 ) ) {
char * V_79 ;
switch ( V_31 -> V_41 . V_80 ) {
case V_81 :
V_79 = L_12 ;
break;
case V_82 :
V_79 = L_13 ;
break;
case V_83 :
V_79 = L_14 ;
break;
case V_84 :
V_79 = L_15 ;
break;
default:
F_5 ( L_16 ) ;
return;
}
V_31 -> V_58 = F_19 ( V_31 -> V_48 , V_79 ) ;
if ( F_20 ( V_31 -> V_58 ) )
F_5 ( L_17 , V_79 ) ;
V_31 -> V_85 = F_19 ( V_31 -> V_48 , L_18 ) ;
if ( F_20 ( V_31 -> V_85 ) )
F_5 ( L_19 ) ;
V_31 -> V_86 = F_19 ( V_31 -> V_48 , L_20 ) ;
if ( F_20 ( V_31 -> V_86 ) )
F_5 ( L_21 ) ;
}
}
static void F_21 ( struct V_42 * V_42 ,
struct V_87 * V_88 )
{
struct V_87 * V_89 = V_42 -> V_89 ;
struct V_90 * V_41 = F_22 ( V_42 ) ;
struct V_30 * V_31 = F_23 ( V_41 ) ;
struct V_91 * V_45 = V_89 -> V_45 ;
struct V_46 * V_47 = F_11 ( V_31 -> V_48 ) ;
struct V_92 * V_93 = V_89 -> V_93 ;
bool V_94 = V_41 -> V_59 == V_60 ? true : false ;
struct V_43 * V_44 ;
struct V_95 * V_96 ;
int V_97 , V_98 , V_99 , V_100 ;
int V_101 , V_102 , V_103 , V_104 ;
struct V_105 * V_106 ;
struct V_29 * V_107 ;
struct V_29 * V_108 ;
struct V_75 * V_49 , * V_52 ;
T_2 V_109 ;
T_2 V_110 ;
int V_26 ;
unsigned int V_111 , V_112 ;
T_2 V_113 , V_114 , V_115 , V_116 ;
int V_117 ;
if ( ! V_45 )
return;
V_44 = F_10 ( V_45 ) ;
V_96 = & V_45 -> V_96 ;
V_97 = V_89 -> V_118 ;
V_98 = V_89 -> V_119 ;
V_99 = F_24 ( V_89 -> V_120 , 0 , V_96 -> V_121 - V_97 ) ;
V_100 = F_24 ( V_89 -> V_122 , 0 , V_96 -> V_123 - V_98 ) ;
V_101 = V_89 -> V_101 >> 16 ;
V_102 = V_89 -> V_102 >> 16 ;
V_103 = V_89 -> V_103 >> 16 ;
V_104 = V_89 -> V_104 >> 16 ;
F_25 ( L_22 ,
V_45 -> V_73 . V_53 , F_26 ( V_44 ) ,
V_42 -> V_73 . V_53 , F_6 ( V_41 ) ) ;
F_25 ( L_23 ,
F_6 ( V_41 ) ,
V_99 , V_100 , V_97 , V_98 ,
V_103 , V_104 , V_101 , V_102 ) ;
V_107 = F_3 ( V_31 ) ;
V_49 = V_107 -> V_49 ;
V_52 = V_107 -> V_52 ;
F_27 ( V_31 -> V_48 , L_24 , V_124 ,
F_6 ( V_41 ) , V_49 , V_52 ) ;
V_49 -> V_125 = V_126 ;
V_49 -> V_127 = V_128 ;
V_26 = F_1 ( V_93 -> V_129 ) ;
if ( V_26 == - 1 ) {
F_5 ( L_25 ,
( char * ) & V_93 -> V_129 ) ;
return;
}
V_49 -> V_127 |= V_26 ;
V_49 -> V_127 |= F_2 ( V_26 ) ;
V_49 -> V_50 &= ~ V_51 ;
V_106 = F_28 ( V_93 , 0 ) ;
if ( ! V_106 ) {
F_5 ( L_26 ) ;
return;
}
F_8 ( L_27 , V_93 -> V_73 . V_53 ,
( char * ) & V_93 -> V_129 ,
( unsigned long ) V_106 -> V_130 ) ;
F_29 ( V_93 -> V_129 , & V_111 , & V_112 ) ;
V_49 -> V_131 = ( T_2 ) V_106 -> V_130 + V_93 -> V_132 [ 0 ] ;
V_49 -> V_131 += V_101 * ( V_112 >> 3 ) ;
V_49 -> V_131 += V_102 * V_93 -> V_133 [ 0 ] ;
V_49 -> V_134 = V_93 -> V_133 [ 0 ] ;
V_49 -> V_135 = F_24 ( V_104 , 0 , V_136 ) << 16 |
F_24 ( V_103 , 0 , V_136 ) ;
V_113 = F_30 ( * V_96 , V_98 ) ;
V_115 = F_30 ( * V_96 , V_98 + V_100 - 1 ) ;
V_114 = F_31 ( * V_96 , V_97 ) ;
V_116 = F_31 ( * V_96 , V_97 + V_99 - 1 ) ;
V_49 -> V_137 = ( V_113 << 16 ) | V_114 ;
V_49 -> V_138 = ( V_115 << 16 ) | V_116 ;
memcpy ( V_52 , V_49 , sizeof( * V_52 ) ) ;
V_49 -> V_139 = V_107 -> V_39 ;
V_52 -> V_139 = V_107 -> V_40 ;
if ( V_96 -> V_140 & V_141 )
V_52 -> V_131 = V_49 -> V_131 +
V_93 -> V_133 [ 0 ] ;
if ( V_94 ) {
if ( F_32 ( V_44 -> V_53 == V_54 ?
V_47 -> V_55 : V_47 -> V_56 ,
& V_31 -> V_57 , V_45 ) ) {
F_5 ( L_28 ) ;
return;
}
if ( V_31 -> V_58 ) {
struct V_142 * V_143 ;
int V_144 = V_96 -> clock * 1000 ;
if ( V_44 -> V_53 == V_54 )
V_143 = V_31 -> V_85 ;
else
V_143 = V_31 -> V_86 ;
if ( V_143 )
F_33 ( V_31 -> V_58 , V_143 ) ;
V_117 = F_34 ( V_31 -> V_58 , V_144 ) ;
if ( V_117 < 0 ) {
F_5 ( L_29 ,
V_144 ) ;
return;
}
if ( F_35 ( V_31 -> V_58 ) ) {
F_5 ( L_30 ) ;
return;
}
}
}
V_108 = F_7 ( V_31 ) ;
V_109 = V_107 -> V_40 ;
V_110 = V_107 -> V_39 ;
F_27 ( V_31 -> V_48 , L_31 ,
F_4 ( V_31 -> V_34 + V_35 ) ) ;
F_27 ( V_31 -> V_48 , L_32 ,
( unsigned long ) V_106 -> V_130 ,
F_4 ( V_31 -> V_34 + V_145 ) ) ;
if ( ! V_108 ) {
F_8 ( L_33 ,
F_6 ( V_41 ) ) ;
F_36 ( V_31 -> V_67 ?
V_110 : V_109 ,
V_31 -> V_34 + V_35 ) ;
goto V_36;
}
if ( V_96 -> V_140 & V_141 ) {
if ( V_31 -> V_67 ) {
V_108 -> V_52 -> V_139 = V_109 ;
} else {
F_36 ( V_109 ,
V_31 -> V_34 + V_35 ) ;
}
} else {
F_36 ( V_109 , V_31 -> V_34 + V_35 ) ;
}
V_36:
V_41 -> V_59 = V_146 ;
}
static void F_37 ( struct V_42 * V_42 ,
struct V_87 * V_88 )
{
struct V_90 * V_41 = F_22 ( V_42 ) ;
struct V_43 * V_44 = F_10 ( V_42 -> V_45 ) ;
if ( ! V_42 -> V_45 ) {
F_8 ( L_34 ,
V_42 -> V_73 . V_53 ) ;
return;
}
F_8 ( L_22 ,
V_42 -> V_45 -> V_73 . V_53 , F_26 ( V_44 ) ,
V_42 -> V_73 . V_53 , F_6 ( V_41 ) ) ;
V_41 -> V_59 = V_147 ;
}
struct V_42 * F_38 ( struct V_148 * V_149 ,
struct V_150 * V_48 , int V_80 ,
void T_3 * V_151 ,
unsigned int V_152 ,
enum V_153 type )
{
struct V_30 * V_31 ;
int V_117 ;
V_31 = F_39 ( V_48 , sizeof( * V_31 ) , V_77 ) ;
if ( ! V_31 ) {
F_5 ( L_35 ) ;
return NULL ;
}
V_31 -> V_48 = V_48 ;
V_31 -> V_34 = V_151 ;
V_31 -> V_41 . V_80 = V_80 ;
V_31 -> V_41 . V_59 = V_60 ;
V_31 -> V_57 . V_154 = F_14 ;
F_16 ( V_31 ) ;
V_117 = F_40 ( V_149 , & V_31 -> V_41 . V_42 ,
V_152 ,
& V_155 ,
V_156 ,
F_41 ( V_156 ) ,
type , NULL ) ;
if ( V_117 ) {
F_5 ( L_36 ) ;
goto V_157;
}
F_42 ( & V_31 -> V_41 . V_42 , & V_158 ) ;
F_43 ( & V_31 -> V_41 , type ) ;
return & V_31 -> V_41 . V_42 ;
V_157:
F_44 ( V_48 , V_31 ) ;
return NULL ;
}
