void F_1 ( struct V_1 * V_2 , bool V_3 )
{
F_2 ( V_2 , V_4 ) ;
V_2 -> V_5 -> V_6 |= V_7 ;
if ( ! V_3 )
F_3 ( V_2 ) ;
}
struct V_8 * F_4 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
struct V_8 * V_8 = NULL ;
V_12:
V_8 = F_6 ( V_11 , V_9 , false ) ;
if ( ! V_8 ) {
F_7 () ;
goto V_12;
}
F_8 ( V_8 , V_13 , true ) ;
if ( ! F_9 ( V_8 ) )
F_10 ( V_8 ) ;
return V_8 ;
}
static struct V_8 * F_11 ( struct V_1 * V_2 , T_1 V_9 ,
bool V_14 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
struct V_8 * V_8 ;
struct V_15 V_16 = {
. V_2 = V_2 ,
. type = V_13 ,
. V_17 = V_18 ,
. V_19 = V_20 | V_21 | V_22 ,
. V_23 = V_9 ,
. V_24 = V_9 ,
. V_25 = NULL ,
} ;
if ( F_12 ( ! V_14 ) )
V_16 . V_19 &= ~ V_21 ;
V_12:
V_8 = F_6 ( V_11 , V_9 , false ) ;
if ( ! V_8 ) {
F_7 () ;
goto V_12;
}
if ( F_9 ( V_8 ) )
goto V_26;
V_16 . V_8 = V_8 ;
if ( F_13 ( & V_16 ) ) {
F_14 ( V_8 , 1 ) ;
goto V_12;
}
F_15 ( V_8 ) ;
if ( F_12 ( V_8 -> V_11 != V_11 ) ) {
F_14 ( V_8 , 1 ) ;
goto V_12;
}
if ( F_12 ( ! F_9 ( V_8 ) ) )
F_1 ( V_2 , false ) ;
V_26:
return V_8 ;
}
struct V_8 * F_16 ( struct V_1 * V_2 , T_1 V_9 )
{
return F_11 ( V_2 , V_9 , true ) ;
}
struct V_8 * F_17 ( struct V_1 * V_2 , T_1 V_9 )
{
return F_11 ( V_2 , V_9 , false ) ;
}
bool F_18 ( struct V_1 * V_2 , T_2 V_27 , int type )
{
switch ( type ) {
case V_28 :
break;
case V_29 :
if ( F_12 ( V_27 >= F_19 ( V_2 ) ) )
return false ;
break;
case V_30 :
if ( F_12 ( V_27 >= F_20 ( V_2 ) ||
V_27 < F_21 ( V_2 ) -> V_31 ) )
return false ;
break;
case V_32 :
if ( F_12 ( V_27 >= F_22 ( V_2 ) -> V_33 ||
V_27 < F_23 ( V_2 ) ) )
return false ;
break;
case V_34 :
if ( F_12 ( V_27 >= F_24 ( V_2 ) ||
V_27 < F_20 ( V_2 ) ) )
return false ;
break;
default:
F_25 () ;
}
return true ;
}
int F_26 ( struct V_1 * V_2 , T_2 V_35 , int V_36 ,
int type , bool V_37 )
{
struct V_8 * V_8 ;
T_2 V_38 = V_35 ;
struct V_15 V_16 = {
. V_2 = V_2 ,
. type = V_13 ,
. V_17 = V_18 ,
. V_19 = V_37 ? ( V_20 | V_21 | V_22 ) : V_39 ,
. V_25 = NULL ,
} ;
struct V_40 V_41 ;
if ( F_12 ( type == V_34 ) )
V_16 . V_19 &= ~ V_21 ;
F_27 ( & V_41 ) ;
for (; V_36 -- > 0 ; V_38 ++ ) {
if ( ! F_18 ( V_2 , V_38 , type ) )
goto V_26;
switch ( type ) {
case V_28 :
if ( F_12 ( V_38 >=
F_28 ( F_29 ( V_2 ) -> V_42 ) ) )
V_38 = 0 ;
V_16 . V_24 = F_30 ( V_2 ,
V_38 * V_43 ) ;
break;
case V_29 :
V_16 . V_24 = F_31 ( V_2 ,
V_38 * V_44 ) ;
break;
case V_30 :
case V_32 :
case V_34 :
V_16 . V_24 = V_38 ;
break;
default:
F_25 () ;
}
V_8 = F_6 ( F_5 ( V_2 ) ,
V_16 . V_24 , false ) ;
if ( ! V_8 )
continue;
if ( F_9 ( V_8 ) ) {
F_14 ( V_8 , 1 ) ;
continue;
}
V_16 . V_8 = V_8 ;
V_16 . V_23 = V_16 . V_24 ;
F_32 ( & V_16 ) ;
F_14 ( V_8 , 0 ) ;
}
V_26:
F_33 ( V_2 , V_13 , V_45 ) ;
F_34 ( & V_41 ) ;
return V_38 - V_35 ;
}
void F_35 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_8 * V_8 ;
bool V_46 = false ;
V_8 = F_36 ( F_5 ( V_2 ) , V_9 ) ;
if ( ! V_8 || ! F_9 ( V_8 ) )
V_46 = true ;
F_14 ( V_8 , 0 ) ;
if ( V_46 )
F_26 ( V_2 , V_9 , F_37 ( V_2 ) , V_34 , true ) ;
}
static int F_38 ( struct V_8 * V_8 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_39 ( V_8 ) ;
F_40 ( V_8 , V_13 ) ;
if ( F_12 ( F_41 ( V_2 , V_49 ) ) )
goto V_50;
if ( V_48 -> V_51 && V_8 -> V_9 < F_42 ( V_2 , 0 ) )
goto V_50;
if ( F_12 ( F_43 ( V_2 ) ) )
goto V_50;
F_44 ( V_2 , V_8 ) ;
F_45 ( V_2 , V_52 ) ;
if ( V_48 -> V_51 )
F_46 ( V_2 , NULL , V_8 , 0 , V_13 , V_53 ) ;
F_47 ( V_8 ) ;
if ( F_12 ( F_43 ( V_2 ) ) )
F_33 ( V_2 , V_13 , V_53 ) ;
return 0 ;
V_50:
F_48 ( V_48 , V_8 ) ;
return V_54 ;
}
static int F_49 ( struct V_10 * V_11 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_50 ( V_11 ) ;
long V_55 , V_56 ;
if ( V_48 -> V_57 ||
F_51 ( V_2 , V_52 ) < F_52 ( V_2 , V_13 ) )
goto V_58;
F_53 ( V_11 -> V_59 , V_48 , V_13 ) ;
F_54 ( & V_2 -> V_60 ) ;
V_55 = F_55 ( V_2 , V_13 , V_48 ) ;
V_56 = F_56 ( V_2 , V_13 , V_48 -> V_61 ) ;
F_57 ( & V_2 -> V_60 ) ;
V_48 -> V_61 = F_58 ( ( long ) 0 , V_48 -> V_61 - V_56 - V_55 ) ;
return 0 ;
V_58:
V_48 -> V_62 += F_51 ( V_2 , V_52 ) ;
F_53 ( V_11 -> V_59 , V_48 , V_13 ) ;
return 0 ;
}
long F_56 ( struct V_1 * V_2 , enum V_63 type ,
long V_61 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
T_1 V_9 = 0 , V_64 = V_65 , V_66 = V_65 ;
struct V_67 V_68 ;
long V_69 = 0 ;
struct V_47 V_48 = {
. V_51 = 0 ,
} ;
struct V_40 V_41 ;
F_59 ( & V_68 , 0 ) ;
F_27 ( & V_41 ) ;
while ( V_9 <= V_64 ) {
int V_70 , V_71 ;
V_71 = F_60 ( & V_68 , V_11 , & V_9 ,
V_72 ,
F_61 ( V_64 - V_9 , ( T_1 ) V_73 - 1 ) + 1 ) ;
if ( F_12 ( V_71 == 0 ) )
break;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
struct V_8 * V_8 = V_68 . V_74 [ V_70 ] ;
if ( V_66 == V_65 )
V_66 = V_8 -> V_9 - 1 ;
if ( V_61 != V_75 && V_8 -> V_9 != V_66 + 1 ) {
F_62 ( & V_68 ) ;
goto V_76;
}
F_15 ( V_8 ) ;
if ( F_12 ( V_8 -> V_11 != V_11 ) ) {
V_77:
F_47 ( V_8 ) ;
continue;
}
if ( ! F_63 ( V_8 ) ) {
goto V_77;
}
F_8 ( V_8 , V_13 , true ) ;
F_64 ( F_65 ( V_8 ) ) ;
if ( ! F_66 ( V_8 ) )
goto V_77;
if ( V_11 -> V_78 -> V_79 ( V_8 , & V_48 ) ) {
F_47 ( V_8 ) ;
break;
}
V_69 ++ ;
V_66 = V_8 -> V_9 ;
if ( F_12 ( V_69 >= V_61 ) )
break;
}
F_62 ( & V_68 ) ;
F_7 () ;
}
V_76:
if ( V_69 )
F_33 ( V_2 , type , V_53 ) ;
F_34 ( & V_41 ) ;
return V_69 ;
}
static int F_67 ( struct V_8 * V_8 )
{
F_68 ( V_8 , V_13 ) ;
if ( ! F_9 ( V_8 ) )
F_10 ( V_8 ) ;
if ( ! F_63 ( V_8 ) ) {
F_69 ( V_8 ) ;
F_70 ( F_39 ( V_8 ) , V_52 ) ;
F_71 ( V_8 ) ;
F_72 ( V_8 ) ;
return 1 ;
}
return 0 ;
}
static void F_73 ( struct V_1 * V_2 , T_3 V_80 , int type )
{
struct V_81 * V_82 = & V_2 -> V_82 [ type ] ;
struct V_83 * V_84 , * V_85 ;
V_85 = F_74 ( V_86 , V_87 ) ;
V_88:
F_75 ( V_87 | V_89 ) ;
F_76 ( & V_82 -> V_90 ) ;
V_84 = F_77 ( & V_82 -> V_91 , V_80 ) ;
if ( ! V_84 ) {
V_84 = V_85 ;
if ( F_78 ( & V_82 -> V_91 , V_80 , V_84 ) ) {
F_79 ( & V_82 -> V_90 ) ;
F_80 () ;
goto V_88;
}
memset ( V_84 , 0 , sizeof( struct V_83 ) ) ;
V_84 -> V_80 = V_80 ;
F_81 ( & V_84 -> V_92 , & V_82 -> V_93 ) ;
if ( type != V_94 )
V_82 -> V_95 ++ ;
}
F_79 ( & V_82 -> V_90 ) ;
F_80 () ;
if ( V_84 != V_85 )
F_82 ( V_86 , V_85 ) ;
}
static void F_83 ( struct V_1 * V_2 , T_3 V_80 , int type )
{
struct V_81 * V_82 = & V_2 -> V_82 [ type ] ;
struct V_83 * V_84 ;
F_76 ( & V_82 -> V_90 ) ;
V_84 = F_77 ( & V_82 -> V_91 , V_80 ) ;
if ( V_84 ) {
F_84 ( & V_84 -> V_92 ) ;
F_85 ( & V_82 -> V_91 , V_80 ) ;
V_82 -> V_95 -- ;
F_79 ( & V_82 -> V_90 ) ;
F_82 ( V_86 , V_84 ) ;
return;
}
F_79 ( & V_82 -> V_90 ) ;
}
void F_86 ( struct V_1 * V_2 , T_3 V_80 , int type )
{
F_73 ( V_2 , V_80 , type ) ;
}
void F_87 ( struct V_1 * V_2 , T_3 V_80 , int type )
{
F_83 ( V_2 , V_80 , type ) ;
}
bool F_88 ( struct V_1 * V_2 , T_3 V_80 , int V_96 )
{
struct V_81 * V_82 = & V_2 -> V_82 [ V_96 ] ;
struct V_83 * V_84 ;
F_76 ( & V_82 -> V_90 ) ;
V_84 = F_77 ( & V_82 -> V_91 , V_80 ) ;
F_79 ( & V_82 -> V_90 ) ;
return V_84 ? true : false ;
}
void F_89 ( struct V_1 * V_2 , bool V_97 )
{
struct V_83 * V_84 , * V_85 ;
int V_70 ;
for ( V_70 = V_97 ? V_94 : V_98 ; V_70 <= V_99 ; V_70 ++ ) {
struct V_81 * V_82 = & V_2 -> V_82 [ V_70 ] ;
F_76 ( & V_82 -> V_90 ) ;
F_90 (e, tmp, &im->ino_list, list) {
F_84 ( & V_84 -> V_92 ) ;
F_85 ( & V_82 -> V_91 , V_84 -> V_80 ) ;
F_82 ( V_86 , V_84 ) ;
V_82 -> V_95 -- ;
}
F_79 ( & V_82 -> V_90 ) ;
}
}
int F_91 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = & V_2 -> V_82 [ V_94 ] ;
int V_100 = 0 ;
F_76 ( & V_82 -> V_90 ) ;
#ifdef F_92
if ( F_93 ( V_2 , V_101 ) ) {
F_79 ( & V_82 -> V_90 ) ;
return - V_102 ;
}
#endif
if ( F_12 ( V_82 -> V_95 >= V_2 -> V_103 ) )
V_100 = - V_102 ;
else
V_82 -> V_95 ++ ;
F_79 ( & V_82 -> V_90 ) ;
return V_100 ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = & V_2 -> V_82 [ V_94 ] ;
F_76 ( & V_82 -> V_90 ) ;
F_95 ( V_2 , V_82 -> V_95 == 0 ) ;
V_82 -> V_95 -- ;
F_79 ( & V_82 -> V_90 ) ;
}
void F_96 ( struct V_104 * V_104 )
{
F_73 ( F_97 ( V_104 ) , V_104 -> V_105 , V_94 ) ;
F_98 ( V_104 ) ;
}
void F_99 ( struct V_1 * V_2 , T_3 V_80 )
{
F_83 ( V_2 , V_80 , V_94 ) ;
}
static int F_100 ( struct V_1 * V_2 , T_3 V_80 )
{
struct V_104 * V_104 ;
struct V_106 V_107 ;
int V_100 = F_91 ( V_2 ) ;
if ( V_100 ) {
F_101 ( V_2 , V_108 ) ;
F_102 ( V_2 -> V_5 , V_109 ,
L_1 ,
V_110 , V_80 ) ;
return V_100 ;
}
F_73 ( V_2 , V_80 , V_94 ) ;
V_104 = F_103 ( V_2 -> V_5 , V_80 ) ;
if ( F_104 ( V_104 ) ) {
F_95 ( V_2 , F_105 ( V_104 ) == - V_111 ) ;
return F_105 ( V_104 ) ;
}
F_106 ( V_104 ) ;
F_107 ( V_104 ) ;
F_108 ( V_2 , V_80 , & V_107 ) ;
if ( V_107 . V_112 != V_113 ) {
F_101 ( V_2 , V_108 ) ;
F_102 ( V_2 -> V_5 , V_109 ,
L_1 ,
V_110 , V_80 ) ;
return - V_114 ;
}
F_83 ( V_2 , V_80 , V_94 ) ;
return 0 ;
}
int F_109 ( struct V_1 * V_2 )
{
T_2 V_115 , V_116 , V_70 , V_117 ;
int V_100 ;
if ( ! F_110 ( V_2 , V_118 ) )
return 0 ;
V_115 = F_23 ( V_2 ) + 1 + F_111 ( V_2 ) ;
V_116 = F_112 ( V_2 ) - 1 - F_111 ( V_2 ) ;
F_26 ( V_2 , V_115 , V_116 , V_32 , true ) ;
for ( V_70 = 0 ; V_70 < V_116 ; V_70 ++ ) {
struct V_8 * V_8 = F_16 ( V_2 , V_115 + V_70 ) ;
struct V_119 * V_120 ;
V_120 = (struct V_119 * ) F_113 ( V_8 ) ;
for ( V_117 = 0 ; V_117 < F_114 ( V_120 -> V_121 ) ; V_117 ++ ) {
T_3 V_80 = F_114 ( V_120 -> V_80 [ V_117 ] ) ;
V_100 = F_100 ( V_2 , V_80 ) ;
if ( V_100 ) {
F_14 ( V_8 , 1 ) ;
return V_100 ;
}
}
F_14 ( V_8 , 1 ) ;
}
F_115 ( V_2 , V_118 ) ;
return 0 ;
}
static void F_116 ( struct V_1 * V_2 , T_2 V_115 )
{
struct V_122 * V_123 ;
struct V_119 * V_120 = NULL ;
unsigned int V_124 = 0 ;
unsigned short V_9 = 1 ;
unsigned short V_116 ;
struct V_8 * V_8 = NULL ;
struct V_83 * V_125 = NULL ;
struct V_81 * V_82 = & V_2 -> V_82 [ V_94 ] ;
V_116 = F_117 ( V_82 -> V_95 ) ;
V_123 = & V_82 -> V_93 ;
F_118 (orphan, head, list) {
if ( ! V_8 ) {
V_8 = F_4 ( V_2 , V_115 ++ ) ;
V_120 =
(struct V_119 * ) F_113 ( V_8 ) ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
}
V_120 -> V_80 [ V_124 ++ ] = F_119 ( V_125 -> V_80 ) ;
if ( V_124 == V_126 ) {
V_120 -> V_112 = F_120 ( V_9 ) ;
V_120 -> V_127 = F_120 ( V_116 ) ;
V_120 -> V_121 = F_119 ( V_124 ) ;
F_121 ( V_8 ) ;
F_14 ( V_8 , 1 ) ;
V_9 ++ ;
V_124 = 0 ;
V_8 = NULL ;
}
}
if ( V_8 ) {
V_120 -> V_112 = F_120 ( V_9 ) ;
V_120 -> V_127 = F_120 ( V_116 ) ;
V_120 -> V_121 = F_119 ( V_124 ) ;
F_121 ( V_8 ) ;
F_14 ( V_8 , 1 ) ;
}
}
static int F_122 ( struct V_1 * V_2 , T_2 V_128 ,
struct V_129 * * V_130 , struct V_8 * * V_131 ,
unsigned long long * V_132 )
{
unsigned long V_133 = V_2 -> V_134 ;
T_4 V_135 = 0 ;
T_5 V_136 = 0 ;
* V_131 = F_16 ( V_2 , V_128 ) ;
* V_130 = (struct V_129 * ) F_113 ( * V_131 ) ;
V_135 = F_114 ( ( * V_130 ) -> V_137 ) ;
if ( V_135 >= V_133 ) {
F_102 ( V_2 -> V_5 , V_109 ,
L_2 , V_135 ) ;
return - V_138 ;
}
V_136 = F_114 ( * ( ( V_139 * ) ( ( unsigned char * ) * V_130
+ V_135 ) ) ) ;
if ( ! F_123 ( V_2 , V_136 , * V_130 , V_135 ) ) {
F_102 ( V_2 -> V_5 , V_109 , L_3 ) ;
return - V_138 ;
}
* V_132 = F_124 ( * V_130 ) ;
return 0 ;
}
static struct V_8 * F_125 ( struct V_1 * V_2 ,
T_2 V_128 , unsigned long long * V_132 )
{
struct V_8 * V_140 = NULL , * V_141 = NULL ;
struct V_129 * V_130 = NULL ;
unsigned long long V_142 = 0 , V_143 = 0 ;
int V_100 ;
V_100 = F_122 ( V_2 , V_128 , & V_130 ,
& V_140 , V_132 ) ;
if ( V_100 )
goto V_144;
V_143 = * V_132 ;
V_128 += F_114 ( V_130 -> V_145 ) - 1 ;
V_100 = F_122 ( V_2 , V_128 , & V_130 ,
& V_141 , V_132 ) ;
if ( V_100 )
goto V_146;
V_142 = * V_132 ;
if ( V_142 == V_143 ) {
* V_132 = V_142 ;
F_14 ( V_141 , 1 ) ;
return V_140 ;
}
V_146:
F_14 ( V_141 , 1 ) ;
V_144:
F_14 ( V_140 , 1 ) ;
return NULL ;
}
int F_126 ( struct V_1 * V_2 )
{
struct V_129 * V_130 ;
struct V_147 * V_148 = V_2 -> V_149 ;
struct V_8 * V_150 , * V_151 , * V_152 ;
unsigned long V_133 = V_2 -> V_134 ;
unsigned long long V_153 = 0 , V_154 = 0 ;
unsigned long long V_155 ;
unsigned int V_156 = 1 + F_111 ( V_2 ) ;
T_2 V_157 ;
int V_70 ;
V_2 -> V_158 = F_127 ( V_156 * V_133 , V_159 ) ;
if ( ! V_2 -> V_158 )
return - V_160 ;
V_155 = F_114 ( V_148 -> V_161 ) ;
V_150 = F_125 ( V_2 , V_155 , & V_153 ) ;
V_155 += ( ( unsigned long long ) 1 ) <<
F_114 ( V_148 -> V_162 ) ;
V_151 = F_125 ( V_2 , V_155 , & V_154 ) ;
if ( V_150 && V_151 ) {
if ( F_128 ( V_154 , V_153 ) )
V_152 = V_151 ;
else
V_152 = V_150 ;
} else if ( V_150 ) {
V_152 = V_150 ;
} else if ( V_151 ) {
V_152 = V_151 ;
} else {
goto V_163;
}
V_130 = (struct V_129 * ) F_113 ( V_152 ) ;
memcpy ( V_2 -> V_158 , V_130 , V_133 ) ;
if ( F_129 ( V_2 ) )
goto V_163;
if ( V_156 <= 1 )
goto V_164;
V_157 = F_114 ( V_148 -> V_161 ) ;
if ( V_152 == V_151 )
V_157 += 1 << F_114 ( V_148 -> V_162 ) ;
for ( V_70 = 1 ; V_70 < V_156 ; V_70 ++ ) {
void * V_165 ;
unsigned char * V_158 = ( unsigned char * ) V_2 -> V_158 ;
V_152 = F_16 ( V_2 , V_157 + V_70 ) ;
V_165 = F_113 ( V_152 ) ;
memcpy ( V_158 + V_70 * V_133 , V_165 , V_133 ) ;
F_14 ( V_152 , 1 ) ;
}
V_164:
F_14 ( V_150 , 1 ) ;
F_14 ( V_151 , 1 ) ;
return 0 ;
V_163:
F_130 ( V_2 -> V_158 ) ;
return - V_138 ;
}
static void F_131 ( struct V_104 * V_104 , enum V_166 type )
{
struct V_1 * V_2 = F_97 ( V_104 ) ;
int V_167 = ( type == V_168 ) ? V_169 : V_170 ;
if ( F_132 ( V_104 , V_167 ) )
return;
F_133 ( V_104 , V_167 ) ;
F_81 ( & F_134 ( V_104 ) -> V_171 , & V_2 -> V_172 [ type ] ) ;
F_135 ( V_2 , type ) ;
}
static void F_136 ( struct V_104 * V_104 , enum V_166 type )
{
int V_167 = ( type == V_168 ) ? V_169 : V_170 ;
if ( F_137 ( V_104 ) || ! F_132 ( V_104 , V_167 ) )
return;
F_138 ( & F_134 ( V_104 ) -> V_171 ) ;
F_139 ( V_104 , V_167 ) ;
F_140 ( F_97 ( V_104 ) , type ) ;
}
void F_141 ( struct V_104 * V_104 , struct V_8 * V_8 )
{
struct V_1 * V_2 = F_97 ( V_104 ) ;
enum V_166 type = F_142 ( V_104 -> V_173 ) ? V_168 : V_174 ;
if ( ! F_142 ( V_104 -> V_173 ) && ! F_143 ( V_104 -> V_173 ) &&
! F_144 ( V_104 -> V_173 ) )
return;
F_76 ( & V_2 -> V_175 [ type ] ) ;
if ( type != V_174 || F_145 ( V_2 , V_176 ) )
F_131 ( V_104 , type ) ;
F_146 ( V_104 ) ;
F_79 ( & V_2 -> V_175 [ type ] ) ;
F_71 ( V_8 ) ;
F_72 ( V_8 ) ;
}
void F_147 ( struct V_104 * V_104 )
{
struct V_1 * V_2 = F_97 ( V_104 ) ;
enum V_166 type = F_142 ( V_104 -> V_173 ) ? V_168 : V_174 ;
if ( ! F_142 ( V_104 -> V_173 ) && ! F_143 ( V_104 -> V_173 ) &&
! F_144 ( V_104 -> V_173 ) )
return;
if ( type == V_174 && ! F_145 ( V_2 , V_176 ) )
return;
F_76 ( & V_2 -> V_175 [ type ] ) ;
F_136 ( V_104 , type ) ;
F_79 ( & V_2 -> V_175 [ type ] ) ;
}
int F_148 ( struct V_1 * V_2 , enum V_166 type )
{
struct V_122 * V_123 ;
struct V_104 * V_104 ;
struct V_177 * V_178 ;
bool V_179 = ( type == V_168 ) ;
F_149 ( V_2 -> V_5 , V_179 ,
F_51 ( V_2 , V_179 ?
V_180 : V_181 ) ) ;
V_88:
if ( F_12 ( F_43 ( V_2 ) ) )
return - V_114 ;
F_76 ( & V_2 -> V_175 [ type ] ) ;
V_123 = & V_2 -> V_172 [ type ] ;
if ( F_150 ( V_123 ) ) {
F_79 ( & V_2 -> V_175 [ type ] ) ;
F_151 ( V_2 -> V_5 , V_179 ,
F_51 ( V_2 , V_179 ?
V_180 : V_181 ) ) ;
return 0 ;
}
V_178 = F_152 ( V_123 -> V_182 , struct V_177 , V_171 ) ;
V_104 = F_153 ( & V_178 -> V_183 ) ;
F_79 ( & V_2 -> V_175 [ type ] ) ;
if ( V_104 ) {
F_154 ( V_104 -> V_184 ) ;
F_107 ( V_104 ) ;
} else {
F_33 ( V_2 , V_185 , V_53 ) ;
F_7 () ;
}
goto V_88;
}
int F_155 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = & V_2 -> V_172 [ V_186 ] ;
struct V_104 * V_104 ;
struct V_177 * V_178 ;
T_6 V_187 = F_51 ( V_2 , V_188 ) ;
while ( V_187 -- ) {
if ( F_12 ( F_43 ( V_2 ) ) )
return - V_114 ;
F_76 ( & V_2 -> V_175 [ V_186 ] ) ;
if ( F_150 ( V_123 ) ) {
F_79 ( & V_2 -> V_175 [ V_186 ] ) ;
return 0 ;
}
V_178 = F_152 ( V_123 -> V_182 , struct V_177 ,
V_189 ) ;
V_104 = F_153 ( & V_178 -> V_183 ) ;
F_79 ( & V_2 -> V_175 [ V_186 ] ) ;
if ( V_104 ) {
F_98 ( V_104 ) ;
F_107 ( V_104 ) ;
}
} ;
return 0 ;
}
static int F_156 ( struct V_1 * V_2 )
{
struct V_47 V_48 = {
. V_190 = V_191 ,
. V_61 = V_75 ,
. V_51 = 0 ,
} ;
struct V_40 V_41 ;
int V_100 = 0 ;
F_27 ( & V_41 ) ;
V_192:
F_157 ( V_2 ) ;
if ( F_51 ( V_2 , V_180 ) ) {
F_158 ( V_2 ) ;
V_100 = F_148 ( V_2 , V_168 ) ;
if ( V_100 )
goto V_26;
goto V_192;
}
if ( F_51 ( V_2 , V_188 ) ) {
F_158 ( V_2 ) ;
V_100 = F_155 ( V_2 ) ;
if ( V_100 )
goto V_26;
goto V_192;
}
V_193:
F_159 ( & V_2 -> V_194 ) ;
if ( F_51 ( V_2 , V_195 ) ) {
F_160 ( & V_2 -> V_194 ) ;
V_100 = F_161 ( V_2 , & V_48 ) ;
if ( V_100 ) {
F_158 ( V_2 ) ;
goto V_26;
}
goto V_193;
}
V_26:
F_34 ( & V_41 ) ;
return V_100 ;
}
static void F_162 ( struct V_1 * V_2 )
{
F_160 ( & V_2 -> V_194 ) ;
F_163 ( V_2 ) ;
F_158 ( V_2 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
F_165 ( V_196 ) ;
for (; ; ) {
F_166 ( & V_2 -> V_197 , & V_196 , V_198 ) ;
if ( ! F_167 ( & V_2 -> V_199 ) )
break;
F_168 ( 5 * V_200 ) ;
}
F_169 ( & V_2 -> V_197 , & V_196 ) ;
}
static void F_170 ( struct V_1 * V_2 , struct V_201 * V_202 )
{
unsigned long V_203 = V_2 -> V_82 [ V_94 ] . V_95 ;
struct V_129 * V_158 = F_171 ( V_2 ) ;
F_76 ( & V_2 -> V_204 ) ;
if ( V_202 -> V_205 == V_206 )
F_172 ( V_158 , V_207 ) ;
else
F_173 ( V_158 , V_207 ) ;
if ( V_202 -> V_205 == V_208 )
F_172 ( V_158 , V_209 ) ;
else
F_173 ( V_158 , V_209 ) ;
if ( V_203 )
F_172 ( V_158 , V_118 ) ;
else
F_173 ( V_158 , V_118 ) ;
if ( F_41 ( V_2 , V_108 ) )
F_172 ( V_158 , V_210 ) ;
F_172 ( V_158 , V_211 ) ;
F_79 ( & V_2 -> V_204 ) ;
}
static int F_174 ( struct V_1 * V_2 , struct V_201 * V_202 )
{
struct V_129 * V_158 = F_171 ( V_2 ) ;
struct V_212 * V_213 = F_29 ( V_2 ) ;
unsigned long V_203 = V_2 -> V_82 [ V_94 ] . V_95 ;
T_3 V_214 = V_213 -> V_215 ;
T_2 V_115 ;
unsigned int V_216 , V_116 ;
T_5 V_217 = 0 ;
int V_70 ;
int V_218 = F_111 ( V_2 ) ;
struct V_219 * V_5 = V_2 -> V_5 ;
struct V_220 * V_221 = F_175 ( V_2 , V_222 ) ;
T_7 V_223 ;
while ( F_51 ( V_2 , V_52 ) ) {
F_56 ( V_2 , V_13 , V_75 ) ;
if ( F_12 ( F_43 ( V_2 ) ) )
return - V_114 ;
}
F_176 ( V_2 , & V_214 ) ;
V_158 -> V_224 = F_177 ( F_178 ( V_2 ) ) ;
V_158 -> V_225 = F_177 ( F_179 ( V_2 ) ) ;
V_158 -> V_226 = F_119 ( F_180 ( V_2 ) ) ;
for ( V_70 = 0 ; V_70 < V_227 ; V_70 ++ ) {
V_158 -> V_228 [ V_70 ] =
F_119 ( F_181 ( V_2 , V_70 + V_222 ) ) ;
V_158 -> V_229 [ V_70 ] =
F_120 ( F_182 ( V_2 , V_70 + V_222 ) ) ;
V_158 -> V_230 [ V_70 + V_222 ] =
F_183 ( V_2 , V_70 + V_222 ) ;
}
for ( V_70 = 0 ; V_70 < V_231 ; V_70 ++ ) {
V_158 -> V_232 [ V_70 ] =
F_119 ( F_181 ( V_2 , V_70 + V_233 ) ) ;
V_158 -> V_234 [ V_70 ] =
F_120 ( F_182 ( V_2 , V_70 + V_233 ) ) ;
V_158 -> V_230 [ V_70 + V_233 ] =
F_183 ( V_2 , V_70 + V_233 ) ;
}
V_158 -> V_235 = F_119 ( V_235 ( V_2 ) ) ;
V_158 -> V_236 = F_119 ( V_236 ( V_2 ) ) ;
V_158 -> F_176 = F_119 ( V_214 ) ;
V_216 = F_184 ( V_2 , false ) ;
F_76 ( & V_2 -> V_204 ) ;
if ( V_216 < V_231 )
F_172 ( V_158 , V_237 ) ;
else
F_173 ( V_158 , V_237 ) ;
F_79 ( & V_2 -> V_204 ) ;
V_116 = F_117 ( V_203 ) ;
V_158 -> V_238 = F_119 ( 1 + V_218 +
V_116 ) ;
if ( F_185 ( V_202 -> V_205 ) )
V_158 -> V_145 = F_119 ( V_239 +
V_218 + V_216 +
V_116 + V_227 ) ;
else
V_158 -> V_145 = F_119 ( V_239 +
V_218 + V_216 +
V_116 ) ;
F_170 ( V_2 , V_202 ) ;
F_186 ( V_2 , F_187 ( V_2 , V_240 ) ) ;
F_188 ( V_2 , F_187 ( V_2 , V_241 ) ) ;
V_217 = F_189 ( V_2 , V_158 , F_114 ( V_158 -> V_137 ) ) ;
* ( ( V_139 * ) ( ( unsigned char * ) V_158 +
F_114 ( V_158 -> V_137 ) ) )
= F_119 ( V_217 ) ;
V_115 = F_23 ( V_2 ) ;
F_164 ( V_2 ) ;
if ( F_12 ( F_43 ( V_2 ) ) )
return - V_114 ;
F_190 ( V_2 , V_158 , V_115 ++ ) ;
for ( V_70 = 1 ; V_70 < 1 + V_218 ; V_70 ++ )
F_190 ( V_2 , ( char * ) V_158 + V_70 * V_242 ,
V_115 ++ ) ;
if ( V_203 ) {
F_116 ( V_2 , V_115 ) ;
V_115 += V_116 ;
}
F_191 ( V_2 , V_115 ) ;
V_115 += V_216 ;
V_223 = V_2 -> V_223 ;
if ( V_5 -> V_243 -> V_244 )
V_223 += F_192 ( V_2 ) ;
V_221 -> V_245 -> V_246 . V_223 = F_177 ( V_223 ) ;
if ( F_185 ( V_202 -> V_205 ) ) {
F_193 ( V_2 , V_115 ) ;
V_115 += V_227 ;
}
F_190 ( V_2 , V_158 , V_115 ) ;
F_164 ( V_2 ) ;
if ( F_12 ( F_43 ( V_2 ) ) )
return - V_114 ;
F_194 ( F_195 ( V_2 ) , 0 , V_247 ) ;
F_194 ( F_5 ( V_2 ) , 0 , V_247 ) ;
V_2 -> V_248 = V_2 -> V_249 ;
F_196 ( & V_2 -> V_250 , 0 ) ;
F_56 ( V_2 , V_251 , V_75 ) ;
F_164 ( V_2 ) ;
F_89 ( V_2 , false ) ;
if ( F_12 ( F_43 ( V_2 ) ) )
return - V_114 ;
F_197 ( V_2 , V_202 ) ;
F_198 ( V_2 , V_252 ) ;
F_198 ( V_2 , V_253 ) ;
if ( F_51 ( V_2 , V_195 ) ||
F_51 ( V_2 , V_188 ) )
F_101 ( V_2 , V_252 ) ;
F_95 ( V_2 , F_51 ( V_2 , V_180 ) ) ;
return 0 ;
}
int F_199 ( struct V_1 * V_2 , struct V_201 * V_202 )
{
struct V_129 * V_158 = F_171 ( V_2 ) ;
unsigned long long V_254 ;
int V_100 = 0 ;
F_54 ( & V_2 -> V_60 ) ;
if ( ! F_41 ( V_2 , V_252 ) &&
( V_202 -> V_205 == V_208 || V_202 -> V_205 == V_255 ||
( V_202 -> V_205 == V_256 && ! V_2 -> V_257 ) ) )
goto V_26;
if ( F_12 ( F_43 ( V_2 ) ) ) {
V_100 = - V_114 ;
goto V_26;
}
if ( F_200 ( V_2 -> V_5 ) ) {
V_100 = - V_258 ;
goto V_26;
}
F_201 ( V_2 -> V_5 , V_202 -> V_205 , L_4 ) ;
V_100 = F_156 ( V_2 ) ;
if ( V_100 )
goto V_26;
F_201 ( V_2 -> V_5 , V_202 -> V_205 , L_5 ) ;
F_3 ( V_2 ) ;
if ( V_202 -> V_205 == V_256 && ! F_41 ( V_2 , V_252 ) ) {
F_95 ( V_2 , F_29 ( V_2 ) -> V_259 ) ;
F_95 ( V_2 , F_22 ( V_2 ) -> V_260 ) ;
F_95 ( V_2 , F_202 ( V_2 ) ) ;
F_203 ( V_2 , V_202 ) ;
F_197 ( V_2 , V_202 ) ;
F_204 ( V_2 ) ;
F_162 ( V_2 ) ;
goto V_26;
}
V_254 = F_124 ( V_158 ) ;
V_158 -> V_261 = F_177 ( ++ V_254 ) ;
F_205 ( V_2 ) ;
F_203 ( V_2 , V_202 ) ;
V_100 = F_174 ( V_2 , V_202 ) ;
F_204 ( V_2 ) ;
F_162 ( V_2 ) ;
F_206 ( V_2 -> V_262 ) ;
if ( V_202 -> V_205 == V_263 )
F_102 ( V_2 -> V_5 , V_264 ,
L_6 , V_254 ) ;
F_207 ( V_2 , V_265 ) ;
F_201 ( V_2 -> V_5 , V_202 -> V_205 , L_7 ) ;
V_26:
F_57 ( & V_2 -> V_60 ) ;
return V_100 ;
}
void F_208 ( struct V_1 * V_2 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_266 ; V_70 ++ ) {
struct V_81 * V_82 = & V_2 -> V_82 [ V_70 ] ;
F_209 ( & V_82 -> V_91 , V_267 ) ;
F_210 ( & V_82 -> V_90 ) ;
F_211 ( & V_82 -> V_93 ) ;
V_82 -> V_95 = 0 ;
}
V_2 -> V_103 = ( V_2 -> V_268 - V_239 -
V_269 - F_111 ( V_2 ) ) *
V_126 ;
}
int T_8 F_212 ( void )
{
V_86 = F_213 ( L_8 ,
sizeof( struct V_83 ) ) ;
if ( ! V_86 )
return - V_160 ;
V_270 = F_213 ( L_9 ,
sizeof( struct V_271 ) ) ;
if ( ! V_270 ) {
F_214 ( V_86 ) ;
return - V_160 ;
}
return 0 ;
}
void F_215 ( void )
{
F_214 ( V_86 ) ;
F_214 ( V_270 ) ;
}
