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
. V_19 = V_20 | V_21 ,
. V_22 = V_9 ,
. V_23 = V_9 ,
. V_24 = NULL ,
} ;
if ( F_12 ( ! V_14 ) )
V_16 . V_19 &= ~ V_20 ;
V_12:
V_8 = F_6 ( V_11 , V_9 , false ) ;
if ( ! V_8 ) {
F_7 () ;
goto V_12;
}
if ( F_9 ( V_8 ) )
goto V_25;
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
V_25:
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
bool F_18 ( struct V_1 * V_2 , T_2 V_26 , int type )
{
switch ( type ) {
case V_27 :
break;
case V_28 :
if ( F_12 ( V_26 >= F_19 ( V_2 ) ) )
return false ;
break;
case V_29 :
if ( F_12 ( V_26 >= F_20 ( V_2 ) ||
V_26 < F_21 ( V_2 ) -> V_30 ) )
return false ;
break;
case V_31 :
if ( F_12 ( V_26 >= F_22 ( V_2 ) -> V_32 ||
V_26 < F_23 ( V_2 ) ) )
return false ;
break;
case V_33 :
if ( F_12 ( V_26 >= F_24 ( V_2 ) ||
V_26 < F_20 ( V_2 ) ) )
return false ;
break;
default:
F_25 () ;
}
return true ;
}
int F_26 ( struct V_1 * V_2 , T_2 V_34 , int V_35 ,
int type , bool V_36 )
{
struct V_8 * V_8 ;
T_2 V_37 = V_34 ;
struct V_15 V_16 = {
. V_2 = V_2 ,
. type = V_13 ,
. V_17 = V_18 ,
. V_19 = V_36 ? ( V_20 | V_21 ) : V_38 ,
. V_24 = NULL ,
. V_39 = false ,
} ;
struct V_40 V_41 ;
if ( F_12 ( type == V_33 ) )
V_16 . V_19 &= ~ V_20 ;
F_27 ( & V_41 ) ;
for (; V_35 -- > 0 ; V_37 ++ ) {
if ( ! F_18 ( V_2 , V_37 , type ) )
goto V_25;
switch ( type ) {
case V_27 :
if ( F_12 ( V_37 >=
F_28 ( F_29 ( V_2 ) -> V_42 ) ) )
V_37 = 0 ;
V_16 . V_23 = F_30 ( V_2 ,
V_37 * V_43 ) ;
break;
case V_28 :
V_16 . V_23 = F_31 ( V_2 ,
V_37 * V_44 ) ;
break;
case V_29 :
case V_31 :
case V_33 :
V_16 . V_23 = V_37 ;
break;
default:
F_25 () ;
}
V_8 = F_6 ( F_5 ( V_2 ) ,
V_16 . V_23 , false ) ;
if ( ! V_8 )
continue;
if ( F_9 ( V_8 ) ) {
F_14 ( V_8 , 1 ) ;
continue;
}
V_16 . V_8 = V_8 ;
F_13 ( & V_16 ) ;
F_14 ( V_8 , 0 ) ;
}
V_25:
F_32 ( & V_41 ) ;
return V_37 - V_34 ;
}
void F_33 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_8 * V_8 ;
bool V_45 = false ;
V_8 = F_34 ( F_5 ( V_2 ) , V_9 ) ;
if ( ! V_8 || ! F_9 ( V_8 ) )
V_45 = true ;
F_14 ( V_8 , 0 ) ;
if ( V_45 )
F_26 ( V_2 , V_9 , V_46 , V_33 , true ) ;
}
static int F_35 ( struct V_8 * V_8 ,
struct V_47 * V_48 ,
enum V_49 V_50 )
{
struct V_1 * V_2 = F_36 ( V_8 ) ;
F_37 ( V_8 , V_13 ) ;
if ( F_12 ( F_38 ( V_2 , V_51 ) ) )
goto V_52;
if ( V_48 -> V_53 && V_8 -> V_9 < F_39 ( V_2 , 0 ) )
goto V_52;
if ( F_12 ( F_40 ( V_2 ) ) )
goto V_52;
F_41 ( V_2 , V_8 , V_50 ) ;
F_42 ( V_2 , V_54 ) ;
if ( V_48 -> V_53 )
F_43 ( V_2 , V_8 -> V_11 -> V_55 ,
0 , V_8 -> V_9 , V_13 ) ;
F_44 ( V_8 ) ;
if ( F_12 ( F_40 ( V_2 ) ) )
F_45 ( V_2 , V_13 ) ;
return 0 ;
V_52:
F_46 ( V_48 , V_8 ) ;
return V_56 ;
}
static int F_47 ( struct V_8 * V_8 ,
struct V_47 * V_48 )
{
return F_35 ( V_8 , V_48 , V_57 ) ;
}
static int F_48 ( struct V_10 * V_11 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_49 ( V_11 ) ;
long V_58 , V_59 ;
if ( F_12 ( F_38 ( V_2 , V_51 ) ) )
goto V_60;
if ( V_48 -> V_61 ||
F_50 ( V_2 , V_54 ) < F_51 ( V_2 , V_13 ) )
goto V_60;
if ( ! F_52 ( & V_2 -> V_62 ) )
goto V_60;
F_53 ( V_11 -> V_55 , V_48 , V_13 ) ;
V_58 = F_54 ( V_2 , V_13 , V_48 ) ;
V_59 = F_55 ( V_2 , V_13 , V_48 -> V_63 , V_57 ) ;
F_56 ( & V_2 -> V_62 ) ;
V_48 -> V_63 = F_57 ( ( long ) 0 , V_48 -> V_63 - V_59 - V_58 ) ;
return 0 ;
V_60:
V_48 -> V_64 += F_50 ( V_2 , V_54 ) ;
F_53 ( V_11 -> V_55 , V_48 , V_13 ) ;
return 0 ;
}
long F_55 ( struct V_1 * V_2 , enum V_65 type ,
long V_63 , enum V_49 V_50 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
T_1 V_9 = 0 , V_66 = V_67 , V_68 = V_67 ;
struct V_69 V_70 ;
long V_71 = 0 ;
struct V_47 V_48 = {
. V_53 = 0 ,
} ;
struct V_40 V_41 ;
F_58 ( & V_70 , 0 ) ;
F_27 ( & V_41 ) ;
while ( V_9 <= V_66 ) {
int V_72 , V_73 ;
V_73 = F_59 ( & V_70 , V_11 , & V_9 ,
V_74 ,
F_60 ( V_66 - V_9 , ( T_1 ) V_75 - 1 ) + 1 ) ;
if ( F_12 ( V_73 == 0 ) )
break;
for ( V_72 = 0 ; V_72 < V_73 ; V_72 ++ ) {
struct V_8 * V_8 = V_70 . V_76 [ V_72 ] ;
if ( V_68 == V_67 )
V_68 = V_8 -> V_9 - 1 ;
if ( V_63 != V_77 && V_8 -> V_9 != V_68 + 1 ) {
F_61 ( & V_70 ) ;
goto V_78;
}
F_15 ( V_8 ) ;
if ( F_12 ( V_8 -> V_11 != V_11 ) ) {
V_79:
F_44 ( V_8 ) ;
continue;
}
if ( ! F_62 ( V_8 ) ) {
goto V_79;
}
F_8 ( V_8 , V_13 , true ) ;
F_63 ( F_64 ( V_8 ) ) ;
if ( ! F_65 ( V_8 ) )
goto V_79;
if ( F_35 ( V_8 , & V_48 , V_50 ) ) {
F_44 ( V_8 ) ;
break;
}
V_71 ++ ;
V_68 = V_8 -> V_9 ;
if ( F_12 ( V_71 >= V_63 ) )
break;
}
F_61 ( & V_70 ) ;
F_7 () ;
}
V_78:
if ( V_71 )
F_45 ( V_2 , type ) ;
F_32 ( & V_41 ) ;
return V_71 ;
}
static int F_66 ( struct V_8 * V_8 )
{
F_67 ( V_8 , V_13 ) ;
if ( ! F_9 ( V_8 ) )
F_10 ( V_8 ) ;
if ( ! F_62 ( V_8 ) ) {
F_68 ( V_8 ) ;
F_69 ( F_36 ( V_8 ) , V_54 ) ;
F_70 ( V_8 ) ;
F_71 ( V_8 ) ;
return 1 ;
}
return 0 ;
}
static void F_72 ( struct V_1 * V_2 , T_3 V_80 , int type )
{
struct V_81 * V_82 = & V_2 -> V_82 [ type ] ;
struct V_83 * V_84 , * V_85 ;
V_85 = F_73 ( V_86 , V_87 ) ;
V_88:
F_74 ( V_87 | V_89 ) ;
F_75 ( & V_82 -> V_90 ) ;
V_84 = F_76 ( & V_82 -> V_91 , V_80 ) ;
if ( ! V_84 ) {
V_84 = V_85 ;
if ( F_77 ( & V_82 -> V_91 , V_80 , V_84 ) ) {
F_78 ( & V_82 -> V_90 ) ;
F_79 () ;
goto V_88;
}
memset ( V_84 , 0 , sizeof( struct V_83 ) ) ;
V_84 -> V_80 = V_80 ;
F_80 ( & V_84 -> V_92 , & V_82 -> V_93 ) ;
if ( type != V_94 )
V_82 -> V_95 ++ ;
}
F_78 ( & V_82 -> V_90 ) ;
F_79 () ;
if ( V_84 != V_85 )
F_81 ( V_86 , V_85 ) ;
}
static void F_82 ( struct V_1 * V_2 , T_3 V_80 , int type )
{
struct V_81 * V_82 = & V_2 -> V_82 [ type ] ;
struct V_83 * V_84 ;
F_75 ( & V_82 -> V_90 ) ;
V_84 = F_76 ( & V_82 -> V_91 , V_80 ) ;
if ( V_84 ) {
F_83 ( & V_84 -> V_92 ) ;
F_84 ( & V_82 -> V_91 , V_80 ) ;
V_82 -> V_95 -- ;
F_78 ( & V_82 -> V_90 ) ;
F_81 ( V_86 , V_84 ) ;
return;
}
F_78 ( & V_82 -> V_90 ) ;
}
void F_85 ( struct V_1 * V_2 , T_3 V_80 , int type )
{
F_72 ( V_2 , V_80 , type ) ;
}
void F_86 ( struct V_1 * V_2 , T_3 V_80 , int type )
{
F_82 ( V_2 , V_80 , type ) ;
}
bool F_87 ( struct V_1 * V_2 , T_3 V_80 , int V_96 )
{
struct V_81 * V_82 = & V_2 -> V_82 [ V_96 ] ;
struct V_83 * V_84 ;
F_75 ( & V_82 -> V_90 ) ;
V_84 = F_76 ( & V_82 -> V_91 , V_80 ) ;
F_78 ( & V_82 -> V_90 ) ;
return V_84 ? true : false ;
}
void F_88 ( struct V_1 * V_2 , bool V_97 )
{
struct V_83 * V_84 , * V_85 ;
int V_72 ;
for ( V_72 = V_97 ? V_94 : V_98 ; V_72 <= V_99 ; V_72 ++ ) {
struct V_81 * V_82 = & V_2 -> V_82 [ V_72 ] ;
F_75 ( & V_82 -> V_90 ) ;
F_89 (e, tmp, &im->ino_list, list) {
F_83 ( & V_84 -> V_92 ) ;
F_84 ( & V_82 -> V_91 , V_84 -> V_80 ) ;
F_81 ( V_86 , V_84 ) ;
V_82 -> V_95 -- ;
}
F_78 ( & V_82 -> V_90 ) ;
}
}
int F_90 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = & V_2 -> V_82 [ V_94 ] ;
int V_100 = 0 ;
F_75 ( & V_82 -> V_90 ) ;
#ifdef F_91
if ( F_92 ( V_2 , V_101 ) ) {
F_78 ( & V_82 -> V_90 ) ;
F_93 ( V_101 ) ;
return - V_102 ;
}
#endif
if ( F_12 ( V_82 -> V_95 >= V_2 -> V_103 ) )
V_100 = - V_102 ;
else
V_82 -> V_95 ++ ;
F_78 ( & V_82 -> V_90 ) ;
return V_100 ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = & V_2 -> V_82 [ V_94 ] ;
F_75 ( & V_82 -> V_90 ) ;
F_95 ( V_2 , V_82 -> V_95 == 0 ) ;
V_82 -> V_95 -- ;
F_78 ( & V_82 -> V_90 ) ;
}
void F_96 ( struct V_104 * V_104 )
{
F_72 ( F_97 ( V_104 ) , V_104 -> V_105 , V_94 ) ;
F_98 ( V_104 ) ;
}
void F_99 ( struct V_1 * V_2 , T_3 V_80 )
{
F_82 ( V_2 , V_80 , V_94 ) ;
}
static int F_100 ( struct V_1 * V_2 , T_3 V_80 )
{
struct V_104 * V_104 ;
struct V_106 V_107 ;
int V_100 = F_90 ( V_2 ) ;
if ( V_100 ) {
F_101 ( V_2 , V_108 ) ;
F_102 ( V_2 -> V_5 , V_109 ,
L_1 ,
V_110 , V_80 ) ;
return V_100 ;
}
F_72 ( V_2 , V_80 , V_94 ) ;
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
L_2 ,
V_110 , V_80 ) ;
return - V_114 ;
}
F_82 ( V_2 , V_80 , V_94 ) ;
return 0 ;
}
int F_109 ( struct V_1 * V_2 )
{
T_2 V_115 , V_116 , V_72 , V_117 ;
unsigned int V_6 = V_2 -> V_5 -> V_6 ;
int V_100 = 0 ;
if ( ! F_110 ( V_2 , V_118 ) )
return 0 ;
if ( V_6 & V_7 ) {
F_102 ( V_2 -> V_5 , V_119 , L_3 ) ;
V_2 -> V_5 -> V_6 &= ~ V_7 ;
}
#ifdef F_111
V_2 -> V_5 -> V_6 |= V_120 ;
F_112 ( V_2 ) ;
#endif
V_115 = F_23 ( V_2 ) + 1 + F_113 ( V_2 ) ;
V_116 = F_114 ( V_2 ) - 1 - F_113 ( V_2 ) ;
F_26 ( V_2 , V_115 , V_116 , V_31 , true ) ;
for ( V_72 = 0 ; V_72 < V_116 ; V_72 ++ ) {
struct V_8 * V_8 = F_16 ( V_2 , V_115 + V_72 ) ;
struct V_121 * V_122 ;
V_122 = (struct V_121 * ) F_115 ( V_8 ) ;
for ( V_117 = 0 ; V_117 < F_116 ( V_122 -> V_123 ) ; V_117 ++ ) {
T_3 V_80 = F_116 ( V_122 -> V_80 [ V_117 ] ) ;
V_100 = F_100 ( V_2 , V_80 ) ;
if ( V_100 ) {
F_14 ( V_8 , 1 ) ;
goto V_25;
}
}
F_14 ( V_8 , 1 ) ;
}
F_117 ( V_2 , V_118 ) ;
V_25:
#ifdef F_111
F_118 ( V_2 -> V_5 ) ;
#endif
V_2 -> V_5 -> V_6 = V_6 ;
return V_100 ;
}
static void F_119 ( struct V_1 * V_2 , T_2 V_115 )
{
struct V_124 * V_125 ;
struct V_121 * V_122 = NULL ;
unsigned int V_126 = 0 ;
unsigned short V_9 = 1 ;
unsigned short V_116 ;
struct V_8 * V_8 = NULL ;
struct V_83 * V_127 = NULL ;
struct V_81 * V_82 = & V_2 -> V_82 [ V_94 ] ;
V_116 = F_120 ( V_82 -> V_95 ) ;
V_125 = & V_82 -> V_93 ;
F_121 (orphan, head, list) {
if ( ! V_8 ) {
V_8 = F_4 ( V_2 , V_115 ++ ) ;
V_122 =
(struct V_121 * ) F_115 ( V_8 ) ;
memset ( V_122 , 0 , sizeof( * V_122 ) ) ;
}
V_122 -> V_80 [ V_126 ++ ] = F_122 ( V_127 -> V_80 ) ;
if ( V_126 == V_128 ) {
V_122 -> V_112 = F_123 ( V_9 ) ;
V_122 -> V_129 = F_123 ( V_116 ) ;
V_122 -> V_123 = F_122 ( V_126 ) ;
F_124 ( V_8 ) ;
F_14 ( V_8 , 1 ) ;
V_9 ++ ;
V_126 = 0 ;
V_8 = NULL ;
}
}
if ( V_8 ) {
V_122 -> V_112 = F_123 ( V_9 ) ;
V_122 -> V_129 = F_123 ( V_116 ) ;
V_122 -> V_123 = F_122 ( V_126 ) ;
F_124 ( V_8 ) ;
F_14 ( V_8 , 1 ) ;
}
}
static int F_125 ( struct V_1 * V_2 , T_2 V_130 ,
struct V_131 * * V_132 , struct V_8 * * V_133 ,
unsigned long long * V_134 )
{
unsigned long V_135 = V_2 -> V_136 ;
T_4 V_137 = 0 ;
T_5 V_138 = 0 ;
* V_133 = F_16 ( V_2 , V_130 ) ;
* V_132 = (struct V_131 * ) F_115 ( * V_133 ) ;
V_137 = F_116 ( ( * V_132 ) -> V_139 ) ;
if ( V_137 > ( V_135 - sizeof( V_140 ) ) ) {
F_102 ( V_2 -> V_5 , V_109 ,
L_4 , V_137 ) ;
return - V_141 ;
}
V_138 = F_126 ( * V_132 ) ;
if ( ! F_127 ( V_2 , V_138 , * V_132 , V_137 ) ) {
F_102 ( V_2 -> V_5 , V_109 , L_5 ) ;
return - V_141 ;
}
* V_134 = F_128 ( * V_132 ) ;
return 0 ;
}
static struct V_8 * F_129 ( struct V_1 * V_2 ,
T_2 V_130 , unsigned long long * V_134 )
{
struct V_8 * V_142 = NULL , * V_143 = NULL ;
struct V_131 * V_132 = NULL ;
unsigned long long V_144 = 0 , V_145 = 0 ;
int V_100 ;
V_100 = F_125 ( V_2 , V_130 , & V_132 ,
& V_142 , V_134 ) ;
if ( V_100 )
goto V_146;
V_145 = * V_134 ;
V_130 += F_116 ( V_132 -> V_147 ) - 1 ;
V_100 = F_125 ( V_2 , V_130 , & V_132 ,
& V_143 , V_134 ) ;
if ( V_100 )
goto V_148;
V_144 = * V_134 ;
if ( V_144 == V_145 ) {
* V_134 = V_144 ;
F_14 ( V_143 , 1 ) ;
return V_142 ;
}
V_148:
F_14 ( V_143 , 1 ) ;
V_146:
F_14 ( V_142 , 1 ) ;
return NULL ;
}
int F_130 ( struct V_1 * V_2 )
{
struct V_131 * V_132 ;
struct V_149 * V_150 = V_2 -> V_151 ;
struct V_8 * V_152 , * V_153 , * V_154 ;
unsigned long V_135 = V_2 -> V_136 ;
unsigned long long V_155 = 0 , V_156 = 0 ;
unsigned long long V_157 ;
unsigned int V_158 = 1 + F_113 ( V_2 ) ;
T_2 V_159 ;
int V_72 ;
V_2 -> V_160 = F_131 ( V_158 * V_135 , V_161 ) ;
if ( ! V_2 -> V_160 )
return - V_162 ;
V_157 = F_116 ( V_150 -> V_163 ) ;
V_152 = F_129 ( V_2 , V_157 , & V_155 ) ;
V_157 += ( ( unsigned long long ) 1 ) <<
F_116 ( V_150 -> V_164 ) ;
V_153 = F_129 ( V_2 , V_157 , & V_156 ) ;
if ( V_152 && V_153 ) {
if ( F_132 ( V_156 , V_155 ) )
V_154 = V_153 ;
else
V_154 = V_152 ;
} else if ( V_152 ) {
V_154 = V_152 ;
} else if ( V_153 ) {
V_154 = V_153 ;
} else {
goto V_165;
}
V_132 = (struct V_131 * ) F_115 ( V_154 ) ;
memcpy ( V_2 -> V_160 , V_132 , V_135 ) ;
if ( F_133 ( V_2 ) )
goto V_166;
if ( V_154 == V_152 )
V_2 -> V_167 = 1 ;
else
V_2 -> V_167 = 2 ;
if ( V_158 <= 1 )
goto V_168;
V_159 = F_116 ( V_150 -> V_163 ) ;
if ( V_154 == V_153 )
V_159 += 1 << F_116 ( V_150 -> V_164 ) ;
for ( V_72 = 1 ; V_72 < V_158 ; V_72 ++ ) {
void * V_169 ;
unsigned char * V_160 = ( unsigned char * ) V_2 -> V_160 ;
V_154 = F_16 ( V_2 , V_159 + V_72 ) ;
V_169 = F_115 ( V_154 ) ;
memcpy ( V_160 + V_72 * V_135 , V_169 , V_135 ) ;
F_14 ( V_154 , 1 ) ;
}
V_168:
F_14 ( V_152 , 1 ) ;
F_14 ( V_153 , 1 ) ;
return 0 ;
V_166:
F_14 ( V_152 , 1 ) ;
F_14 ( V_153 , 1 ) ;
V_165:
F_134 ( V_2 -> V_160 ) ;
return - V_141 ;
}
static void F_135 ( struct V_104 * V_104 , enum V_170 type )
{
struct V_1 * V_2 = F_97 ( V_104 ) ;
int V_171 = ( type == V_172 ) ? V_173 : V_174 ;
if ( F_136 ( V_104 , V_171 ) )
return;
F_137 ( V_104 , V_171 ) ;
if ( ! F_138 ( V_104 ) )
F_80 ( & F_139 ( V_104 ) -> V_175 ,
& V_2 -> V_176 [ type ] ) ;
F_140 ( V_2 , type ) ;
}
static void F_141 ( struct V_104 * V_104 , enum V_170 type )
{
int V_171 = ( type == V_172 ) ? V_173 : V_174 ;
if ( F_142 ( V_104 ) || ! F_136 ( V_104 , V_171 ) )
return;
F_143 ( & F_139 ( V_104 ) -> V_175 ) ;
F_144 ( V_104 , V_171 ) ;
F_145 ( F_97 ( V_104 ) , type ) ;
}
void F_146 ( struct V_104 * V_104 , struct V_8 * V_8 )
{
struct V_1 * V_2 = F_97 ( V_104 ) ;
enum V_170 type = F_147 ( V_104 -> V_177 ) ? V_172 : V_178 ;
if ( ! F_147 ( V_104 -> V_177 ) && ! F_148 ( V_104 -> V_177 ) &&
! F_149 ( V_104 -> V_177 ) )
return;
F_75 ( & V_2 -> V_179 [ type ] ) ;
if ( type != V_178 || F_150 ( V_2 , V_180 ) )
F_135 ( V_104 , type ) ;
F_151 ( V_104 ) ;
F_78 ( & V_2 -> V_179 [ type ] ) ;
F_70 ( V_8 ) ;
F_71 ( V_8 ) ;
}
void F_152 ( struct V_104 * V_104 )
{
struct V_1 * V_2 = F_97 ( V_104 ) ;
enum V_170 type = F_147 ( V_104 -> V_177 ) ? V_172 : V_178 ;
if ( ! F_147 ( V_104 -> V_177 ) && ! F_148 ( V_104 -> V_177 ) &&
! F_149 ( V_104 -> V_177 ) )
return;
if ( type == V_178 && ! F_150 ( V_2 , V_180 ) )
return;
F_75 ( & V_2 -> V_179 [ type ] ) ;
F_141 ( V_104 , type ) ;
F_78 ( & V_2 -> V_179 [ type ] ) ;
}
int F_153 ( struct V_1 * V_2 , enum V_170 type )
{
struct V_124 * V_125 ;
struct V_104 * V_104 ;
struct V_181 * V_182 ;
bool V_183 = ( type == V_172 ) ;
unsigned long V_80 = 0 ;
F_154 ( V_2 -> V_5 , V_183 ,
F_50 ( V_2 , V_183 ?
V_184 : V_185 ) ) ;
V_88:
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_114 ;
F_75 ( & V_2 -> V_179 [ type ] ) ;
V_125 = & V_2 -> V_176 [ type ] ;
if ( F_155 ( V_125 ) ) {
F_78 ( & V_2 -> V_179 [ type ] ) ;
F_156 ( V_2 -> V_5 , V_183 ,
F_50 ( V_2 , V_183 ?
V_184 : V_185 ) ) ;
return 0 ;
}
V_182 = F_157 ( V_125 , struct V_181 , V_175 ) ;
V_104 = F_158 ( & V_182 -> V_186 ) ;
F_78 ( & V_2 -> V_179 [ type ] ) ;
if ( V_104 ) {
unsigned long V_187 = V_104 -> V_105 ;
if ( V_183 )
F_139 ( V_104 ) -> V_188 = V_189 ;
F_159 ( V_104 -> V_190 ) ;
if ( V_183 )
F_139 ( V_104 ) -> V_188 = NULL ;
F_107 ( V_104 ) ;
if ( V_80 == V_187 ) {
F_160 ( V_191 , V_192 / 50 ) ;
F_7 () ;
} else {
V_80 = V_187 ;
}
} else {
F_45 ( V_2 , V_193 ) ;
F_7 () ;
}
goto V_88;
}
int F_161 ( struct V_1 * V_2 )
{
struct V_124 * V_125 = & V_2 -> V_176 [ V_194 ] ;
struct V_104 * V_104 ;
struct V_181 * V_182 ;
T_6 V_195 = F_50 ( V_2 , V_196 ) ;
while ( V_195 -- ) {
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_114 ;
F_75 ( & V_2 -> V_179 [ V_194 ] ) ;
if ( F_155 ( V_125 ) ) {
F_78 ( & V_2 -> V_179 [ V_194 ] ) ;
return 0 ;
}
V_182 = F_157 ( V_125 , struct V_181 ,
V_197 ) ;
V_104 = F_158 ( & V_182 -> V_186 ) ;
F_78 ( & V_2 -> V_179 [ V_194 ] ) ;
if ( V_104 ) {
F_162 ( V_104 , 0 ) ;
if ( F_136 ( V_104 , V_198 ) )
F_98 ( V_104 ) ;
F_107 ( V_104 ) ;
}
} ;
return 0 ;
}
static void F_163 ( struct V_1 * V_2 )
{
struct V_131 * V_160 = F_164 ( V_2 ) ;
struct V_199 * V_200 = F_29 ( V_2 ) ;
T_3 V_201 = V_200 -> V_202 ;
F_165 ( V_2 , & V_201 ) ;
V_160 -> V_203 = F_166 ( F_167 ( V_2 ) ) ;
V_160 -> V_204 = F_122 ( V_204 ( V_2 ) ) ;
V_160 -> V_205 = F_122 ( V_205 ( V_2 ) ) ;
V_160 -> F_165 = F_122 ( V_201 ) ;
}
static int F_168 ( struct V_1 * V_2 )
{
struct V_47 V_48 = {
. V_206 = V_207 ,
. V_63 = V_77 ,
. V_53 = 0 ,
} ;
struct V_40 V_41 ;
int V_100 = 0 ;
F_27 ( & V_41 ) ;
V_208:
F_169 ( V_2 ) ;
if ( F_50 ( V_2 , V_184 ) ) {
F_170 ( V_2 ) ;
V_100 = F_153 ( V_2 , V_172 ) ;
if ( V_100 )
goto V_25;
F_7 () ;
goto V_208;
}
F_171 ( & V_2 -> V_209 ) ;
if ( F_50 ( V_2 , V_196 ) ) {
F_172 ( & V_2 -> V_209 ) ;
F_170 ( V_2 ) ;
V_100 = F_161 ( V_2 ) ;
if ( V_100 )
goto V_25;
F_7 () ;
goto V_208;
}
V_210:
F_171 ( & V_2 -> V_211 ) ;
if ( F_50 ( V_2 , V_212 ) ) {
F_172 ( & V_2 -> V_211 ) ;
V_100 = F_173 ( V_2 , & V_48 , false , V_213 ) ;
if ( V_100 ) {
F_172 ( & V_2 -> V_209 ) ;
F_170 ( V_2 ) ;
goto V_25;
}
F_7 () ;
goto V_210;
}
F_163 ( V_2 ) ;
F_172 ( & V_2 -> V_209 ) ;
V_25:
F_32 ( & V_41 ) ;
return V_100 ;
}
static void F_174 ( struct V_1 * V_2 )
{
F_172 ( & V_2 -> V_211 ) ;
F_170 ( V_2 ) ;
}
static void F_175 ( struct V_1 * V_2 )
{
F_176 ( V_214 ) ;
for (; ; ) {
F_177 ( & V_2 -> V_215 , & V_214 , V_216 ) ;
if ( ! F_50 ( V_2 , V_217 ) )
break;
F_178 ( 5 * V_192 ) ;
}
F_179 ( & V_2 -> V_215 , & V_214 ) ;
}
static void F_180 ( struct V_1 * V_2 , struct V_218 * V_219 )
{
unsigned long V_220 = V_2 -> V_82 [ V_94 ] . V_95 ;
struct V_131 * V_160 = F_164 ( V_2 ) ;
unsigned long V_221 ;
F_181 ( & V_2 -> V_222 , V_221 ) ;
if ( ( V_219 -> V_223 & V_224 ) &&
F_116 ( V_160 -> V_147 ) >
V_2 -> V_225 - F_29 ( V_2 ) -> V_226 )
F_182 ( V_2 , false ) ;
if ( V_219 -> V_223 & V_227 )
F_183 ( V_160 , V_228 ) ;
if ( V_219 -> V_223 & V_224 )
F_183 ( V_160 , V_229 ) ;
else
F_184 ( V_160 , V_229 ) ;
if ( V_219 -> V_223 & V_230 )
F_183 ( V_160 , V_231 ) ;
else
F_184 ( V_160 , V_231 ) ;
if ( V_220 )
F_183 ( V_160 , V_118 ) ;
else
F_184 ( V_160 , V_118 ) ;
if ( F_38 ( V_2 , V_108 ) )
F_183 ( V_160 , V_232 ) ;
F_183 ( V_160 , V_233 ) ;
F_185 ( & V_2 -> V_222 , V_221 ) ;
}
static int F_186 ( struct V_1 * V_2 , struct V_218 * V_219 )
{
struct V_131 * V_160 = F_164 ( V_2 ) ;
struct V_199 * V_200 = F_29 ( V_2 ) ;
unsigned long V_220 = V_2 -> V_82 [ V_94 ] . V_95 , V_221 ;
T_2 V_115 ;
unsigned int V_234 , V_116 ;
T_5 V_235 = 0 ;
int V_72 ;
int V_236 = F_113 ( V_2 ) ;
struct V_237 * V_5 = V_2 -> V_5 ;
struct V_238 * V_239 = F_187 ( V_2 , V_240 ) ;
T_7 V_241 ;
while ( F_50 ( V_2 , V_54 ) ) {
F_55 ( V_2 , V_13 , V_77 , V_242 ) ;
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_114 ;
}
V_160 -> V_243 = F_166 ( F_188 ( V_2 ) ) ;
V_160 -> V_244 = F_122 ( F_189 ( V_2 ) ) ;
for ( V_72 = 0 ; V_72 < V_245 ; V_72 ++ ) {
V_160 -> V_246 [ V_72 ] =
F_122 ( F_190 ( V_2 , V_72 + V_240 ) ) ;
V_160 -> V_247 [ V_72 ] =
F_123 ( F_191 ( V_2 , V_72 + V_240 ) ) ;
V_160 -> V_248 [ V_72 + V_240 ] =
F_192 ( V_2 , V_72 + V_240 ) ;
}
for ( V_72 = 0 ; V_72 < V_249 ; V_72 ++ ) {
V_160 -> V_250 [ V_72 ] =
F_122 ( F_190 ( V_2 , V_72 + V_251 ) ) ;
V_160 -> V_252 [ V_72 ] =
F_123 ( F_191 ( V_2 , V_72 + V_251 ) ) ;
V_160 -> V_248 [ V_72 + V_251 ] =
F_192 ( V_2 , V_72 + V_251 ) ;
}
V_234 = F_193 ( V_2 , false ) ;
F_181 ( & V_2 -> V_222 , V_221 ) ;
if ( V_234 < V_249 )
F_183 ( V_160 , V_253 ) ;
else
F_184 ( V_160 , V_253 ) ;
F_185 ( & V_2 -> V_222 , V_221 ) ;
V_116 = F_120 ( V_220 ) ;
V_160 -> V_254 = F_122 ( 1 + V_236 +
V_116 ) ;
if ( F_194 ( V_219 -> V_223 ) )
V_160 -> V_147 = F_122 ( V_255 +
V_236 + V_234 +
V_116 + V_245 ) ;
else
V_160 -> V_147 = F_122 ( V_255 +
V_236 + V_234 +
V_116 ) ;
F_180 ( V_2 , V_219 ) ;
F_195 ( V_2 , F_196 ( V_2 , V_256 ) ) ;
F_197 ( V_2 , F_196 ( V_2 , V_257 ) ) ;
V_235 = F_198 ( V_2 , V_160 , F_116 ( V_160 -> V_139 ) ) ;
* ( ( V_140 * ) ( ( unsigned char * ) V_160 +
F_116 ( V_160 -> V_139 ) ) )
= F_122 ( V_235 ) ;
V_115 = F_199 ( V_2 ) ;
if ( F_200 ( V_2 , V_219 ) ) {
T_8 V_258 = F_128 ( V_160 ) ;
T_2 V_259 ;
V_258 |= ( ( T_8 ) V_235 << 32 ) ;
* ( V_260 * ) V_200 -> V_261 = F_166 ( V_258 ) ;
V_259 = V_115 + V_2 -> V_225 - V_200 -> V_226 ;
for ( V_72 = 0 ; V_72 < V_200 -> V_226 ; V_72 ++ )
F_201 ( V_2 , V_200 -> V_261 +
( V_72 << V_262 ) , V_259 + V_72 ) ;
while ( F_50 ( V_2 , V_54 ) ) {
F_55 ( V_2 , V_13 , V_77 , V_242 ) ;
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_114 ;
}
}
F_175 ( V_2 ) ;
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_114 ;
F_201 ( V_2 , V_160 , V_115 ++ ) ;
for ( V_72 = 1 ; V_72 < 1 + V_236 ; V_72 ++ )
F_201 ( V_2 , ( char * ) V_160 + V_72 * V_263 ,
V_115 ++ ) ;
if ( V_220 ) {
F_119 ( V_2 , V_115 ) ;
V_115 += V_116 ;
}
F_202 ( V_2 , V_115 ) ;
V_115 += V_234 ;
V_241 = V_2 -> V_241 ;
if ( V_5 -> V_264 -> V_265 )
V_241 += F_203 ( V_2 ) ;
V_239 -> V_266 -> V_267 . V_241 = F_166 ( V_241 ) ;
if ( F_194 ( V_219 -> V_223 ) ) {
F_204 ( V_2 , V_115 ) ;
V_115 += V_245 ;
}
F_201 ( V_2 , V_160 , V_115 ) ;
F_175 ( V_2 ) ;
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_114 ;
F_205 ( F_206 ( V_2 ) , 0 , V_268 ) ;
F_205 ( F_5 ( V_2 ) , 0 , V_268 ) ;
V_2 -> V_269 = V_2 -> V_270 ;
F_207 ( & V_2 -> V_271 , 0 ) ;
F_55 ( V_2 , V_272 , V_77 , V_242 ) ;
F_175 ( V_2 ) ;
F_88 ( V_2 , false ) ;
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_114 ;
F_208 ( V_2 , V_273 ) ;
F_208 ( V_2 , V_274 ) ;
F_209 ( V_2 ) ;
if ( F_50 ( V_2 , V_212 ) ||
F_50 ( V_2 , V_196 ) )
F_101 ( V_2 , V_273 ) ;
F_95 ( V_2 , F_50 ( V_2 , V_184 ) ) ;
return 0 ;
}
int F_210 ( struct V_1 * V_2 , struct V_218 * V_219 )
{
struct V_131 * V_160 = F_164 ( V_2 ) ;
unsigned long long V_275 ;
int V_100 = 0 ;
F_211 ( & V_2 -> V_62 ) ;
if ( ! F_38 ( V_2 , V_273 ) &&
( ( V_219 -> V_223 & V_230 ) || ( V_219 -> V_223 & V_276 ) ||
( ( V_219 -> V_223 & V_277 ) && ! V_2 -> V_278 ) ) )
goto V_25;
if ( F_12 ( F_40 ( V_2 ) ) ) {
V_100 = - V_114 ;
goto V_25;
}
if ( F_212 ( V_2 -> V_5 ) ) {
V_100 = - V_279 ;
goto V_25;
}
F_213 ( V_2 -> V_5 , V_219 -> V_223 , L_6 ) ;
V_100 = F_168 ( V_2 ) ;
if ( V_100 )
goto V_25;
F_213 ( V_2 -> V_5 , V_219 -> V_223 , L_7 ) ;
F_3 ( V_2 ) ;
if ( V_219 -> V_223 & V_277 ) {
if ( ! F_214 ( V_2 , V_219 ) ) {
F_174 ( V_2 ) ;
goto V_25;
}
if ( F_29 ( V_2 ) -> V_280 == 0 &&
F_22 ( V_2 ) -> V_281 == 0 &&
F_215 ( V_2 ) == 0 ) {
F_216 ( V_2 , V_219 ) ;
F_217 ( V_2 , V_219 ) ;
F_174 ( V_2 ) ;
goto V_25;
}
}
V_275 = F_128 ( V_160 ) ;
V_160 -> V_282 = F_166 ( ++ V_275 ) ;
F_218 ( V_2 , V_219 ) ;
F_216 ( V_2 , V_219 ) ;
V_100 = F_186 ( V_2 , V_219 ) ;
if ( V_100 )
F_219 ( V_2 ) ;
else
F_217 ( V_2 , V_219 ) ;
F_174 ( V_2 ) ;
F_220 ( V_2 -> V_283 ) ;
if ( V_219 -> V_223 & V_284 )
F_102 ( V_2 -> V_5 , V_285 ,
L_8 , V_275 ) ;
F_221 ( V_2 , V_286 ) ;
F_213 ( V_2 -> V_5 , V_219 -> V_223 , L_9 ) ;
V_25:
F_56 ( & V_2 -> V_62 ) ;
return V_100 ;
}
void F_222 ( struct V_1 * V_2 )
{
int V_72 ;
for ( V_72 = 0 ; V_72 < V_287 ; V_72 ++ ) {
struct V_81 * V_82 = & V_2 -> V_82 [ V_72 ] ;
F_223 ( & V_82 -> V_91 , V_288 ) ;
F_224 ( & V_82 -> V_90 ) ;
F_225 ( & V_82 -> V_93 ) ;
V_82 -> V_95 = 0 ;
}
V_2 -> V_103 = ( V_2 -> V_225 - V_255 -
V_289 - F_113 ( V_2 ) ) *
V_128 ;
}
int T_9 F_226 ( void )
{
V_86 = F_227 ( L_10 ,
sizeof( struct V_83 ) ) ;
if ( ! V_86 )
return - V_162 ;
V_290 = F_227 ( L_11 ,
sizeof( struct V_291 ) ) ;
if ( ! V_290 ) {
F_228 ( V_86 ) ;
return - V_162 ;
}
return 0 ;
}
void F_229 ( void )
{
F_228 ( V_86 ) ;
F_228 ( V_290 ) ;
}
