void F_1 ( struct V_1 * V_2 , bool V_3 )
{
F_2 ( V_2 -> V_4 , V_5 ) ;
V_2 -> V_6 -> V_7 |= V_8 ;
if ( ! V_3 )
F_3 ( V_2 ) ;
}
struct V_9 * F_4 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_11 * V_12 = F_5 ( V_2 ) ;
struct V_9 * V_9 = NULL ;
V_13:
V_9 = F_6 ( V_12 , V_10 , false ) ;
if ( ! V_9 ) {
F_7 () ;
goto V_13;
}
F_8 ( V_9 , V_14 , true ) ;
if ( ! F_9 ( V_9 ) )
F_10 ( V_9 ) ;
return V_9 ;
}
static struct V_9 * F_11 ( struct V_1 * V_2 , T_1 V_10 ,
bool V_15 )
{
struct V_11 * V_12 = F_5 ( V_2 ) ;
struct V_9 * V_9 ;
struct V_16 V_17 = {
. V_2 = V_2 ,
. type = V_14 ,
. V_18 = V_19 ,
. V_20 = V_21 | V_22 | V_23 ,
. V_24 = V_10 ,
. V_25 = V_10 ,
. V_26 = NULL ,
} ;
if ( F_12 ( ! V_15 ) )
V_17 . V_20 &= ~ V_22 ;
V_13:
V_9 = F_6 ( V_12 , V_10 , false ) ;
if ( ! V_9 ) {
F_7 () ;
goto V_13;
}
if ( F_9 ( V_9 ) )
goto V_27;
V_17 . V_9 = V_9 ;
if ( F_13 ( & V_17 ) ) {
F_14 ( V_9 , 1 ) ;
goto V_13;
}
F_15 ( V_9 ) ;
if ( F_12 ( V_9 -> V_12 != V_12 ) ) {
F_14 ( V_9 , 1 ) ;
goto V_13;
}
if ( F_12 ( ! F_9 ( V_9 ) ) )
F_1 ( V_2 , false ) ;
V_27:
return V_9 ;
}
struct V_9 * F_16 ( struct V_1 * V_2 , T_1 V_10 )
{
return F_11 ( V_2 , V_10 , true ) ;
}
struct V_9 * F_17 ( struct V_1 * V_2 , T_1 V_10 )
{
return F_11 ( V_2 , V_10 , false ) ;
}
bool F_18 ( struct V_1 * V_2 , T_2 V_28 , int type )
{
switch ( type ) {
case V_29 :
break;
case V_30 :
if ( F_12 ( V_28 >= F_19 ( V_2 ) ) )
return false ;
break;
case V_31 :
if ( F_12 ( V_28 >= F_20 ( V_2 ) ||
V_28 < F_21 ( V_2 ) -> V_32 ) )
return false ;
break;
case V_33 :
if ( F_12 ( V_28 >= F_22 ( V_2 ) -> V_34 ||
V_28 < F_23 ( V_2 ) ) )
return false ;
break;
case V_35 :
if ( F_12 ( V_28 >= F_24 ( V_2 ) ||
V_28 < F_20 ( V_2 ) ) )
return false ;
break;
default:
F_25 () ;
}
return true ;
}
int F_26 ( struct V_1 * V_2 , T_2 V_36 , int V_37 ,
int type , bool V_38 )
{
struct V_9 * V_9 ;
T_2 V_39 = V_36 ;
struct V_16 V_17 = {
. V_2 = V_2 ,
. type = V_14 ,
. V_18 = V_19 ,
. V_20 = V_38 ? ( V_21 | V_22 | V_23 ) : V_40 ,
. V_26 = NULL ,
} ;
struct V_41 V_42 ;
if ( F_12 ( type == V_35 ) )
V_17 . V_20 &= ~ V_22 ;
F_27 ( & V_42 ) ;
for (; V_37 -- > 0 ; V_39 ++ ) {
if ( ! F_18 ( V_2 , V_39 , type ) )
goto V_27;
switch ( type ) {
case V_29 :
if ( F_12 ( V_39 >=
F_28 ( F_29 ( V_2 ) -> V_43 ) ) )
V_39 = 0 ;
V_17 . V_25 = F_30 ( V_2 ,
V_39 * V_44 ) ;
break;
case V_30 :
V_17 . V_25 = F_31 ( V_2 ,
V_39 * V_45 ) ;
break;
case V_31 :
case V_33 :
case V_35 :
V_17 . V_25 = V_39 ;
break;
default:
F_25 () ;
}
V_9 = F_6 ( F_5 ( V_2 ) ,
V_17 . V_25 , false ) ;
if ( ! V_9 )
continue;
if ( F_9 ( V_9 ) ) {
F_14 ( V_9 , 1 ) ;
continue;
}
V_17 . V_9 = V_9 ;
V_17 . V_24 = V_17 . V_25 ;
F_32 ( & V_17 ) ;
F_14 ( V_9 , 0 ) ;
}
V_27:
F_33 ( V_2 , V_14 , V_46 ) ;
F_34 ( & V_42 ) ;
return V_39 - V_36 ;
}
void F_35 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_9 * V_9 ;
bool V_47 = false ;
V_9 = F_36 ( F_5 ( V_2 ) , V_10 ) ;
if ( ! V_9 || ! F_9 ( V_9 ) )
V_47 = true ;
F_14 ( V_9 , 0 ) ;
if ( V_47 )
F_26 ( V_2 , V_10 , F_37 ( V_2 ) , V_35 , true ) ;
}
static int F_38 ( struct V_9 * V_9 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_39 ( V_9 ) ;
F_40 ( V_9 , V_14 ) ;
if ( F_12 ( F_41 ( V_2 , V_50 ) ) )
goto V_51;
if ( V_49 -> V_52 && V_9 -> V_10 < F_42 ( V_2 , 0 ) )
goto V_51;
if ( F_12 ( F_43 ( V_2 ) ) )
goto V_51;
F_44 ( V_2 , V_9 ) ;
F_45 ( V_2 , V_53 ) ;
if ( V_49 -> V_52 )
F_46 ( V_2 , NULL , V_9 , 0 , V_14 , V_54 ) ;
F_47 ( V_9 ) ;
if ( F_12 ( F_43 ( V_2 ) ) )
F_33 ( V_2 , V_14 , V_54 ) ;
return 0 ;
V_51:
F_48 ( V_49 , V_9 ) ;
return V_55 ;
}
static int F_49 ( struct V_11 * V_12 ,
struct V_48 * V_49 )
{
struct V_1 * V_2 = F_50 ( V_12 ) ;
struct V_41 V_42 ;
long V_56 , V_57 ;
if ( V_49 -> V_58 ||
F_51 ( V_2 , V_53 ) < F_52 ( V_2 , V_14 ) )
goto V_59;
F_53 ( V_12 -> V_60 , V_49 , V_14 ) ;
F_54 ( & V_2 -> V_61 ) ;
V_56 = F_55 ( V_2 , V_14 , V_49 ) ;
F_27 ( & V_42 ) ;
V_57 = F_56 ( V_2 , V_14 , V_49 -> V_62 ) ;
F_34 ( & V_42 ) ;
F_57 ( & V_2 -> V_61 ) ;
V_49 -> V_62 = F_58 ( ( long ) 0 , V_49 -> V_62 - V_57 - V_56 ) ;
return 0 ;
V_59:
V_49 -> V_63 += F_51 ( V_2 , V_53 ) ;
F_53 ( V_12 -> V_60 , V_49 , V_14 ) ;
return 0 ;
}
long F_56 ( struct V_1 * V_2 , enum V_64 type ,
long V_62 )
{
struct V_11 * V_12 = F_5 ( V_2 ) ;
T_1 V_10 = 0 , V_65 = V_66 , V_67 = V_66 ;
struct V_68 V_69 ;
long V_70 = 0 ;
struct V_48 V_49 = {
. V_52 = 0 ,
} ;
struct V_41 V_42 ;
F_59 ( & V_69 , 0 ) ;
F_27 ( & V_42 ) ;
while ( V_10 <= V_65 ) {
int V_71 , V_72 ;
V_72 = F_60 ( & V_69 , V_12 , & V_10 ,
V_73 ,
F_61 ( V_65 - V_10 , ( T_1 ) V_74 - 1 ) + 1 ) ;
if ( F_12 ( V_72 == 0 ) )
break;
for ( V_71 = 0 ; V_71 < V_72 ; V_71 ++ ) {
struct V_9 * V_9 = V_69 . V_75 [ V_71 ] ;
if ( V_67 == V_66 )
V_67 = V_9 -> V_10 - 1 ;
if ( V_62 != V_76 && V_9 -> V_10 != V_67 + 1 ) {
F_62 ( & V_69 ) ;
goto V_77;
}
F_15 ( V_9 ) ;
if ( F_12 ( V_9 -> V_12 != V_12 ) ) {
V_78:
F_47 ( V_9 ) ;
continue;
}
if ( ! F_63 ( V_9 ) ) {
goto V_78;
}
F_8 ( V_9 , V_14 , true ) ;
F_64 ( F_65 ( V_9 ) ) ;
if ( ! F_66 ( V_9 ) )
goto V_78;
if ( V_12 -> V_79 -> V_80 ( V_9 , & V_49 ) ) {
F_47 ( V_9 ) ;
break;
}
V_70 ++ ;
V_67 = V_9 -> V_10 ;
if ( F_12 ( V_70 >= V_62 ) )
break;
}
F_62 ( & V_69 ) ;
F_7 () ;
}
V_77:
if ( V_70 )
F_33 ( V_2 , type , V_54 ) ;
F_34 ( & V_42 ) ;
return V_70 ;
}
static int F_67 ( struct V_9 * V_9 )
{
F_68 ( V_9 , V_14 ) ;
if ( ! F_9 ( V_9 ) )
F_10 ( V_9 ) ;
if ( ! F_63 ( V_9 ) ) {
F_69 ( V_9 ) ;
F_70 ( F_39 ( V_9 ) , V_53 ) ;
F_71 ( V_9 ) ;
F_72 ( V_9 ) ;
return 1 ;
}
return 0 ;
}
static void F_73 ( struct V_1 * V_2 , T_3 V_81 , int type )
{
struct V_82 * V_83 = & V_2 -> V_83 [ type ] ;
struct V_84 * V_85 , * V_86 ;
V_86 = F_74 ( V_87 , V_88 ) ;
V_89:
F_75 ( V_88 | V_90 ) ;
F_76 ( & V_83 -> V_91 ) ;
V_85 = F_77 ( & V_83 -> V_92 , V_81 ) ;
if ( ! V_85 ) {
V_85 = V_86 ;
if ( F_78 ( & V_83 -> V_92 , V_81 , V_85 ) ) {
F_79 ( & V_83 -> V_91 ) ;
F_80 () ;
goto V_89;
}
memset ( V_85 , 0 , sizeof( struct V_84 ) ) ;
V_85 -> V_81 = V_81 ;
F_81 ( & V_85 -> V_93 , & V_83 -> V_94 ) ;
if ( type != V_95 )
V_83 -> V_96 ++ ;
}
F_79 ( & V_83 -> V_91 ) ;
F_80 () ;
if ( V_85 != V_86 )
F_82 ( V_87 , V_86 ) ;
}
static void F_83 ( struct V_1 * V_2 , T_3 V_81 , int type )
{
struct V_82 * V_83 = & V_2 -> V_83 [ type ] ;
struct V_84 * V_85 ;
F_76 ( & V_83 -> V_91 ) ;
V_85 = F_77 ( & V_83 -> V_92 , V_81 ) ;
if ( V_85 ) {
F_84 ( & V_85 -> V_93 ) ;
F_85 ( & V_83 -> V_92 , V_81 ) ;
V_83 -> V_96 -- ;
F_79 ( & V_83 -> V_91 ) ;
F_82 ( V_87 , V_85 ) ;
return;
}
F_79 ( & V_83 -> V_91 ) ;
}
void F_86 ( struct V_1 * V_2 , T_3 V_81 , int type )
{
F_73 ( V_2 , V_81 , type ) ;
}
void F_87 ( struct V_1 * V_2 , T_3 V_81 , int type )
{
F_83 ( V_2 , V_81 , type ) ;
}
bool F_88 ( struct V_1 * V_2 , T_3 V_81 , int V_97 )
{
struct V_82 * V_83 = & V_2 -> V_83 [ V_97 ] ;
struct V_84 * V_85 ;
F_76 ( & V_83 -> V_91 ) ;
V_85 = F_77 ( & V_83 -> V_92 , V_81 ) ;
F_79 ( & V_83 -> V_91 ) ;
return V_85 ? true : false ;
}
void F_89 ( struct V_1 * V_2 , bool V_98 )
{
struct V_84 * V_85 , * V_86 ;
int V_71 ;
for ( V_71 = V_98 ? V_95 : V_99 ; V_71 <= V_100 ; V_71 ++ ) {
struct V_82 * V_83 = & V_2 -> V_83 [ V_71 ] ;
F_76 ( & V_83 -> V_91 ) ;
F_90 (e, tmp, &im->ino_list, list) {
F_84 ( & V_85 -> V_93 ) ;
F_85 ( & V_83 -> V_92 , V_85 -> V_81 ) ;
F_82 ( V_87 , V_85 ) ;
V_83 -> V_96 -- ;
}
F_79 ( & V_83 -> V_91 ) ;
}
}
int F_91 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = & V_2 -> V_83 [ V_95 ] ;
int V_101 = 0 ;
F_76 ( & V_83 -> V_91 ) ;
#ifdef F_92
if ( F_93 ( V_102 ) ) {
F_79 ( & V_83 -> V_91 ) ;
return - V_103 ;
}
#endif
if ( F_12 ( V_83 -> V_96 >= V_2 -> V_104 ) )
V_101 = - V_103 ;
else
V_83 -> V_96 ++ ;
F_79 ( & V_83 -> V_91 ) ;
return V_101 ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_82 * V_83 = & V_2 -> V_83 [ V_95 ] ;
F_76 ( & V_83 -> V_91 ) ;
F_95 ( V_2 , V_83 -> V_96 == 0 ) ;
V_83 -> V_96 -- ;
F_79 ( & V_83 -> V_91 ) ;
}
void F_96 ( struct V_105 * V_105 )
{
F_73 ( F_97 ( V_105 ) , V_105 -> V_106 , V_95 ) ;
F_98 ( V_105 ) ;
}
void F_99 ( struct V_1 * V_2 , T_3 V_81 )
{
F_83 ( V_2 , V_81 , V_95 ) ;
}
static int F_100 ( struct V_1 * V_2 , T_3 V_81 )
{
struct V_105 * V_105 ;
V_105 = F_101 ( V_2 -> V_6 , V_81 ) ;
if ( F_102 ( V_105 ) ) {
F_95 ( V_2 , F_103 ( V_105 ) == - V_107 ) ;
return F_103 ( V_105 ) ;
}
F_104 ( V_105 ) ;
F_105 ( V_105 ) ;
return 0 ;
}
int F_106 ( struct V_1 * V_2 )
{
T_2 V_108 , V_109 , V_71 , V_110 ;
int V_101 ;
if ( ! F_107 ( F_108 ( V_2 ) , V_111 ) )
return 0 ;
V_108 = F_23 ( V_2 ) + 1 + F_109 ( V_2 ) ;
V_109 = F_110 ( V_2 ) - 1 - F_109 ( V_2 ) ;
F_26 ( V_2 , V_108 , V_109 , V_33 , true ) ;
for ( V_71 = 0 ; V_71 < V_109 ; V_71 ++ ) {
struct V_9 * V_9 = F_16 ( V_2 , V_108 + V_71 ) ;
struct V_112 * V_113 ;
V_113 = (struct V_112 * ) F_111 ( V_9 ) ;
for ( V_110 = 0 ; V_110 < F_112 ( V_113 -> V_114 ) ; V_110 ++ ) {
T_3 V_81 = F_112 ( V_113 -> V_81 [ V_110 ] ) ;
V_101 = F_100 ( V_2 , V_81 ) ;
if ( V_101 ) {
F_14 ( V_9 , 1 ) ;
return V_101 ;
}
}
F_14 ( V_9 , 1 ) ;
}
F_113 ( F_108 ( V_2 ) , V_111 ) ;
return 0 ;
}
static void F_114 ( struct V_1 * V_2 , T_2 V_108 )
{
struct V_115 * V_116 ;
struct V_112 * V_113 = NULL ;
unsigned int V_117 = 0 ;
unsigned short V_10 = 1 ;
unsigned short V_109 ;
struct V_9 * V_9 = NULL ;
struct V_84 * V_118 = NULL ;
struct V_82 * V_83 = & V_2 -> V_83 [ V_95 ] ;
V_109 = F_115 ( V_83 -> V_96 ) ;
V_116 = & V_83 -> V_94 ;
F_116 (orphan, head, list) {
if ( ! V_9 ) {
V_9 = F_4 ( V_2 , V_108 ++ ) ;
V_113 =
(struct V_112 * ) F_111 ( V_9 ) ;
memset ( V_113 , 0 , sizeof( * V_113 ) ) ;
}
V_113 -> V_81 [ V_117 ++ ] = F_117 ( V_118 -> V_81 ) ;
if ( V_117 == V_119 ) {
V_113 -> V_120 = F_118 ( V_10 ) ;
V_113 -> V_121 = F_118 ( V_109 ) ;
V_113 -> V_114 = F_117 ( V_117 ) ;
F_119 ( V_9 ) ;
F_14 ( V_9 , 1 ) ;
V_10 ++ ;
V_117 = 0 ;
V_9 = NULL ;
}
}
if ( V_9 ) {
V_113 -> V_120 = F_118 ( V_10 ) ;
V_113 -> V_121 = F_118 ( V_109 ) ;
V_113 -> V_114 = F_117 ( V_117 ) ;
F_119 ( V_9 ) ;
F_14 ( V_9 , 1 ) ;
}
}
static struct V_9 * F_120 ( struct V_1 * V_2 ,
T_2 V_122 , unsigned long long * V_123 )
{
struct V_9 * V_124 , * V_125 = NULL ;
unsigned long V_126 = V_2 -> V_127 ;
struct V_128 * V_129 ;
unsigned long long V_130 = 0 , V_131 = 0 ;
T_4 V_132 ;
T_5 V_133 = 0 ;
V_124 = F_16 ( V_2 , V_122 ) ;
V_129 = (struct V_128 * ) F_111 ( V_124 ) ;
V_132 = F_112 ( V_129 -> V_134 ) ;
if ( V_132 >= V_126 )
goto V_135;
V_133 = F_112 ( * ( ( V_136 * ) ( ( unsigned char * ) V_129 + V_132 ) ) ) ;
if ( ! F_121 ( V_2 , V_133 , V_129 , V_132 ) )
goto V_135;
V_131 = F_122 ( V_129 ) ;
V_122 += F_112 ( V_129 -> V_137 ) - 1 ;
V_125 = F_16 ( V_2 , V_122 ) ;
V_129 = (struct V_128 * ) F_111 ( V_125 ) ;
V_132 = F_112 ( V_129 -> V_134 ) ;
if ( V_132 >= V_126 )
goto V_138;
V_133 = F_112 ( * ( ( V_136 * ) ( ( unsigned char * ) V_129 + V_132 ) ) ) ;
if ( ! F_121 ( V_2 , V_133 , V_129 , V_132 ) )
goto V_138;
V_130 = F_122 ( V_129 ) ;
if ( V_130 == V_131 ) {
* V_123 = V_130 ;
F_14 ( V_125 , 1 ) ;
return V_124 ;
}
V_138:
F_14 ( V_125 , 1 ) ;
V_135:
F_14 ( V_124 , 1 ) ;
return NULL ;
}
int F_123 ( struct V_1 * V_2 )
{
struct V_128 * V_129 ;
struct V_139 * V_140 = V_2 -> V_141 ;
struct V_9 * V_142 , * V_143 , * V_144 ;
unsigned long V_126 = V_2 -> V_127 ;
unsigned long long V_145 = 0 , V_146 = 0 ;
unsigned long long V_147 ;
unsigned int V_148 = 1 + F_109 ( V_2 ) ;
T_2 V_149 ;
int V_71 ;
V_2 -> V_4 = F_124 ( V_148 * V_126 , V_150 ) ;
if ( ! V_2 -> V_4 )
return - V_151 ;
V_147 = F_112 ( V_140 -> V_152 ) ;
V_142 = F_120 ( V_2 , V_147 , & V_145 ) ;
V_147 += ( ( unsigned long long ) 1 ) <<
F_112 ( V_140 -> V_153 ) ;
V_143 = F_120 ( V_2 , V_147 , & V_146 ) ;
if ( V_142 && V_143 ) {
if ( F_125 ( V_146 , V_145 ) )
V_144 = V_143 ;
else
V_144 = V_142 ;
} else if ( V_142 ) {
V_144 = V_142 ;
} else if ( V_143 ) {
V_144 = V_143 ;
} else {
goto V_154;
}
V_129 = (struct V_128 * ) F_111 ( V_144 ) ;
memcpy ( V_2 -> V_4 , V_129 , V_126 ) ;
if ( F_126 ( V_2 ) )
goto V_154;
if ( V_148 <= 1 )
goto V_155;
V_149 = F_112 ( V_140 -> V_152 ) ;
if ( V_144 == V_143 )
V_149 += 1 << F_112 ( V_140 -> V_153 ) ;
for ( V_71 = 1 ; V_71 < V_148 ; V_71 ++ ) {
void * V_156 ;
unsigned char * V_4 = ( unsigned char * ) V_2 -> V_4 ;
V_144 = F_16 ( V_2 , V_149 + V_71 ) ;
V_156 = F_111 ( V_144 ) ;
memcpy ( V_4 + V_71 * V_126 , V_156 , V_126 ) ;
F_14 ( V_144 , 1 ) ;
}
V_155:
F_14 ( V_142 , 1 ) ;
F_14 ( V_143 , 1 ) ;
return 0 ;
V_154:
F_127 ( V_2 -> V_4 ) ;
return - V_157 ;
}
static void F_128 ( struct V_105 * V_105 , enum V_158 type )
{
struct V_1 * V_2 = F_97 ( V_105 ) ;
int V_159 = ( type == V_160 ) ? V_161 : V_162 ;
if ( F_129 ( V_105 , V_159 ) )
return;
F_130 ( V_105 , V_159 ) ;
F_81 ( & F_131 ( V_105 ) -> V_163 , & V_2 -> V_164 [ type ] ) ;
F_132 ( V_2 , type ) ;
}
static void F_133 ( struct V_105 * V_105 , enum V_158 type )
{
int V_159 = ( type == V_160 ) ? V_161 : V_162 ;
if ( F_134 ( V_105 ) || ! F_129 ( V_105 , V_159 ) )
return;
F_135 ( & F_131 ( V_105 ) -> V_163 ) ;
F_136 ( V_105 , V_159 ) ;
F_137 ( F_97 ( V_105 ) , type ) ;
}
void F_138 ( struct V_105 * V_105 , struct V_9 * V_9 )
{
struct V_1 * V_2 = F_97 ( V_105 ) ;
enum V_158 type = F_139 ( V_105 -> V_165 ) ? V_160 : V_166 ;
if ( ! F_139 ( V_105 -> V_165 ) && ! F_140 ( V_105 -> V_165 ) &&
! F_141 ( V_105 -> V_165 ) )
return;
F_76 ( & V_2 -> V_167 [ type ] ) ;
if ( type != V_166 || F_142 ( V_2 , V_168 ) )
F_128 ( V_105 , type ) ;
F_143 ( V_105 ) ;
F_79 ( & V_2 -> V_167 [ type ] ) ;
F_71 ( V_9 ) ;
F_72 ( V_9 ) ;
}
void F_144 ( struct V_105 * V_105 )
{
struct V_1 * V_2 = F_97 ( V_105 ) ;
enum V_158 type = F_139 ( V_105 -> V_165 ) ? V_160 : V_166 ;
if ( ! F_139 ( V_105 -> V_165 ) && ! F_140 ( V_105 -> V_165 ) &&
! F_141 ( V_105 -> V_165 ) )
return;
if ( type == V_166 && ! F_142 ( V_2 , V_168 ) )
return;
F_76 ( & V_2 -> V_167 [ type ] ) ;
F_133 ( V_105 , type ) ;
F_79 ( & V_2 -> V_167 [ type ] ) ;
}
int F_145 ( struct V_1 * V_2 , enum V_158 type )
{
struct V_115 * V_116 ;
struct V_105 * V_105 ;
struct V_169 * V_170 ;
bool V_171 = ( type == V_160 ) ;
F_146 ( V_2 -> V_6 , V_171 ,
F_51 ( V_2 , V_171 ?
V_172 : V_173 ) ) ;
V_89:
if ( F_12 ( F_43 ( V_2 ) ) )
return - V_174 ;
F_76 ( & V_2 -> V_167 [ type ] ) ;
V_116 = & V_2 -> V_164 [ type ] ;
if ( F_147 ( V_116 ) ) {
F_79 ( & V_2 -> V_167 [ type ] ) ;
F_148 ( V_2 -> V_6 , V_171 ,
F_51 ( V_2 , V_171 ?
V_172 : V_173 ) ) ;
return 0 ;
}
V_170 = F_149 ( V_116 -> V_175 , struct V_169 , V_163 ) ;
V_105 = F_150 ( & V_170 -> V_176 ) ;
F_79 ( & V_2 -> V_167 [ type ] ) ;
if ( V_105 ) {
F_151 ( V_105 -> V_177 ) ;
F_105 ( V_105 ) ;
} else {
F_33 ( V_2 , V_178 , V_54 ) ;
F_7 () ;
}
goto V_89;
}
int F_152 ( struct V_1 * V_2 )
{
struct V_115 * V_116 = & V_2 -> V_164 [ V_179 ] ;
struct V_105 * V_105 ;
struct V_169 * V_170 ;
T_6 V_180 = F_51 ( V_2 , V_181 ) ;
while ( V_180 -- ) {
if ( F_12 ( F_43 ( V_2 ) ) )
return - V_174 ;
F_76 ( & V_2 -> V_167 [ V_179 ] ) ;
if ( F_147 ( V_116 ) ) {
F_79 ( & V_2 -> V_167 [ V_179 ] ) ;
return 0 ;
}
V_170 = F_149 ( V_116 -> V_175 , struct V_169 ,
V_182 ) ;
V_105 = F_150 ( & V_170 -> V_176 ) ;
F_79 ( & V_2 -> V_167 [ V_179 ] ) ;
if ( V_105 ) {
F_98 ( V_105 ) ;
F_105 ( V_105 ) ;
}
} ;
return 0 ;
}
static int F_153 ( struct V_1 * V_2 )
{
struct V_48 V_49 = {
. V_183 = V_184 ,
. V_62 = V_76 ,
. V_52 = 0 ,
} ;
struct V_41 V_42 ;
int V_101 = 0 ;
F_27 ( & V_42 ) ;
V_185:
F_154 ( V_2 ) ;
if ( F_51 ( V_2 , V_172 ) ) {
F_155 ( V_2 ) ;
V_101 = F_145 ( V_2 , V_160 ) ;
if ( V_101 )
goto V_27;
goto V_185;
}
if ( F_51 ( V_2 , V_181 ) ) {
F_155 ( V_2 ) ;
V_101 = F_152 ( V_2 ) ;
if ( V_101 )
goto V_27;
goto V_185;
}
V_186:
F_156 ( & V_2 -> V_187 ) ;
if ( F_51 ( V_2 , V_188 ) ) {
F_157 ( & V_2 -> V_187 ) ;
V_101 = F_158 ( V_2 , & V_49 ) ;
if ( V_101 ) {
F_155 ( V_2 ) ;
goto V_27;
}
goto V_186;
}
V_27:
F_34 ( & V_42 ) ;
return V_101 ;
}
static void F_159 ( struct V_1 * V_2 )
{
F_157 ( & V_2 -> V_187 ) ;
F_160 ( V_2 ) ;
F_155 ( V_2 ) ;
}
static void F_161 ( struct V_1 * V_2 )
{
F_162 ( V_189 ) ;
for (; ; ) {
F_163 ( & V_2 -> V_190 , & V_189 , V_191 ) ;
if ( ! F_164 ( & V_2 -> V_192 ) )
break;
F_165 ( 5 * V_193 ) ;
}
F_166 ( & V_2 -> V_190 , & V_189 ) ;
}
static int F_167 ( struct V_1 * V_2 , struct V_194 * V_195 )
{
struct V_128 * V_4 = F_108 ( V_2 ) ;
struct V_196 * V_197 = F_168 ( V_2 , V_198 ) ;
struct V_199 * V_200 = F_29 ( V_2 ) ;
unsigned long V_201 = V_2 -> V_83 [ V_95 ] . V_96 ;
T_3 V_202 = V_200 -> V_203 ;
T_2 V_108 ;
unsigned int V_204 , V_109 ;
T_5 V_205 = 0 ;
int V_71 ;
int V_206 = F_109 ( V_2 ) ;
T_2 V_207 = F_169 ( V_2 , V_197 ) ;
bool V_208 = false ;
struct V_209 * V_6 = V_2 -> V_6 ;
struct V_196 * V_210 = F_168 ( V_2 , V_211 ) ;
T_7 V_212 ;
if ( ! F_142 ( V_2 , V_213 ) && F_170 ( V_2 , V_207 ) )
V_208 = true ;
while ( F_51 ( V_2 , V_53 ) ) {
F_56 ( V_2 , V_14 , V_76 ) ;
if ( F_12 ( F_43 ( V_2 ) ) )
return - V_174 ;
}
F_171 ( V_2 , & V_202 ) ;
V_4 -> V_214 = F_172 ( F_173 ( V_2 ) ) ;
V_4 -> V_215 = F_172 ( F_174 ( V_2 ) ) ;
V_4 -> V_216 = F_117 ( F_175 ( V_2 ) ) ;
for ( V_71 = 0 ; V_71 < V_217 ; V_71 ++ ) {
V_4 -> V_218 [ V_71 ] =
F_117 ( F_176 ( V_2 , V_71 + V_211 ) ) ;
V_4 -> V_219 [ V_71 ] =
F_118 ( F_177 ( V_2 , V_71 + V_211 ) ) ;
V_4 -> V_220 [ V_71 + V_211 ] =
F_178 ( V_2 , V_71 + V_211 ) ;
}
for ( V_71 = 0 ; V_71 < V_221 ; V_71 ++ ) {
V_4 -> V_222 [ V_71 ] =
F_117 ( F_176 ( V_2 , V_71 + V_223 ) ) ;
V_4 -> V_224 [ V_71 ] =
F_118 ( F_177 ( V_2 , V_71 + V_223 ) ) ;
V_4 -> V_220 [ V_71 + V_223 ] =
F_178 ( V_2 , V_71 + V_223 ) ;
}
V_4 -> V_225 = F_117 ( V_225 ( V_2 ) ) ;
V_4 -> V_226 = F_117 ( V_226 ( V_2 ) ) ;
V_4 -> F_171 = F_117 ( V_202 ) ;
V_204 = F_179 ( V_2 , false ) ;
if ( V_204 < V_221 )
F_2 ( V_4 , V_227 ) ;
else
F_113 ( V_4 , V_227 ) ;
V_109 = F_115 ( V_201 ) ;
V_4 -> V_228 = F_117 ( 1 + V_206 +
V_109 ) ;
if ( F_180 ( V_195 -> V_229 ) )
V_4 -> V_137 = F_117 ( V_230 +
V_206 + V_204 +
V_109 + V_217 ) ;
else
V_4 -> V_137 = F_117 ( V_230 +
V_206 + V_204 +
V_109 ) ;
if ( V_195 -> V_229 == V_231 )
F_2 ( V_4 , V_232 ) ;
else
F_113 ( V_4 , V_232 ) ;
if ( V_195 -> V_229 == V_233 )
F_2 ( V_4 , V_234 ) ;
else
F_113 ( V_4 , V_234 ) ;
if ( V_201 )
F_2 ( V_4 , V_111 ) ;
else
F_113 ( V_4 , V_111 ) ;
if ( F_41 ( V_2 , V_235 ) )
F_2 ( V_4 , V_236 ) ;
F_181 ( V_2 , F_182 ( V_2 , V_237 ) ) ;
F_183 ( V_2 , F_182 ( V_2 , V_238 ) ) ;
V_205 = F_184 ( V_2 , V_4 , F_112 ( V_4 -> V_134 ) ) ;
* ( ( V_136 * ) ( ( unsigned char * ) V_4 +
F_112 ( V_4 -> V_134 ) ) )
= F_117 ( V_205 ) ;
V_108 = F_23 ( V_2 ) ;
F_161 ( V_2 ) ;
if ( F_12 ( F_43 ( V_2 ) ) )
return - V_174 ;
F_185 ( V_2 , V_4 , V_108 ++ ) ;
for ( V_71 = 1 ; V_71 < 1 + V_206 ; V_71 ++ )
F_185 ( V_2 , ( char * ) V_4 + V_71 * V_239 ,
V_108 ++ ) ;
if ( V_201 ) {
F_114 ( V_2 , V_108 ) ;
V_108 += V_109 ;
}
F_186 ( V_2 , V_108 ) ;
V_108 += V_204 ;
V_212 = V_2 -> V_212 ;
if ( V_6 -> V_240 -> V_241 )
V_212 += F_187 ( V_2 ) ;
V_210 -> V_242 -> V_243 . V_212 = F_172 ( V_212 ) ;
if ( F_180 ( V_195 -> V_229 ) ) {
F_188 ( V_2 , V_108 ) ;
V_108 += V_217 ;
}
F_185 ( V_2 , V_4 , V_108 ) ;
F_161 ( V_2 ) ;
if ( F_12 ( F_43 ( V_2 ) ) )
return - V_174 ;
F_189 ( F_190 ( V_2 ) , 0 , V_244 ) ;
F_189 ( F_5 ( V_2 ) , 0 , V_244 ) ;
V_2 -> V_245 = V_2 -> V_246 ;
F_191 ( & V_2 -> V_247 , 0 ) ;
F_56 ( V_2 , V_248 , V_76 ) ;
F_161 ( V_2 ) ;
if ( V_208 )
F_192 ( F_5 ( V_2 ) , V_207 ,
V_207 ) ;
F_89 ( V_2 , false ) ;
if ( F_12 ( F_43 ( V_2 ) ) )
return - V_174 ;
F_193 ( V_2 , V_195 ) ;
F_194 ( V_2 , V_249 ) ;
return 0 ;
}
int F_195 ( struct V_1 * V_2 , struct V_194 * V_195 )
{
struct V_128 * V_4 = F_108 ( V_2 ) ;
unsigned long long V_250 ;
int V_101 = 0 ;
F_54 ( & V_2 -> V_61 ) ;
if ( ! F_41 ( V_2 , V_249 ) &&
( V_195 -> V_229 == V_233 || V_195 -> V_229 == V_251 ||
( V_195 -> V_229 == V_252 && ! V_2 -> V_253 ) ) )
goto V_27;
if ( F_12 ( F_43 ( V_2 ) ) ) {
V_101 = - V_174 ;
goto V_27;
}
if ( F_196 ( V_2 -> V_6 ) ) {
V_101 = - V_254 ;
goto V_27;
}
F_197 ( V_2 -> V_6 , V_195 -> V_229 , L_1 ) ;
V_101 = F_153 ( V_2 ) ;
if ( V_101 )
goto V_27;
F_197 ( V_2 -> V_6 , V_195 -> V_229 , L_2 ) ;
F_3 ( V_2 ) ;
V_250 = F_122 ( V_4 ) ;
V_4 -> V_255 = F_172 ( ++ V_250 ) ;
F_198 ( V_2 ) ;
F_199 ( V_2 , V_195 ) ;
V_101 = F_167 ( V_2 , V_195 ) ;
F_159 ( V_2 ) ;
F_200 ( V_2 -> V_256 ) ;
if ( V_195 -> V_229 == V_257 )
F_201 ( V_2 -> V_6 , V_258 ,
L_3 , V_250 ) ;
F_202 ( V_2 , V_259 ) ;
F_197 ( V_2 -> V_6 , V_195 -> V_229 , L_4 ) ;
V_27:
F_57 ( & V_2 -> V_61 ) ;
return V_101 ;
}
void F_203 ( struct V_1 * V_2 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_260 ; V_71 ++ ) {
struct V_82 * V_83 = & V_2 -> V_83 [ V_71 ] ;
F_204 ( & V_83 -> V_92 , V_261 ) ;
F_205 ( & V_83 -> V_91 ) ;
F_206 ( & V_83 -> V_94 ) ;
V_83 -> V_96 = 0 ;
}
V_2 -> V_104 = ( V_2 -> V_262 - V_230 -
V_263 - F_109 ( V_2 ) ) *
V_119 ;
}
int T_8 F_207 ( void )
{
V_87 = F_208 ( L_5 ,
sizeof( struct V_84 ) ) ;
if ( ! V_87 )
return - V_151 ;
V_264 = F_208 ( L_6 ,
sizeof( struct V_265 ) ) ;
if ( ! V_264 ) {
F_209 ( V_87 ) ;
return - V_151 ;
}
return 0 ;
}
void F_210 ( void )
{
F_209 ( V_87 ) ;
F_209 ( V_264 ) ;
}
