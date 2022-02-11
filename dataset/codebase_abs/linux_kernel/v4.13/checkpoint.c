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
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_36 ( V_8 ) ;
F_37 ( V_8 , V_13 ) ;
if ( F_12 ( F_38 ( V_2 , V_49 ) ) )
goto V_50;
if ( V_48 -> V_51 && V_8 -> V_9 < F_39 ( V_2 , 0 ) )
goto V_50;
if ( F_12 ( F_40 ( V_2 ) ) )
goto V_50;
F_41 ( V_2 , V_8 ) ;
F_42 ( V_2 , V_52 ) ;
if ( V_48 -> V_51 )
F_43 ( V_2 , V_8 -> V_11 -> V_53 ,
0 , V_8 -> V_9 , V_13 ) ;
F_44 ( V_8 ) ;
if ( F_12 ( F_40 ( V_2 ) ) )
F_45 ( V_2 , V_13 ) ;
return 0 ;
V_50:
F_46 ( V_48 , V_8 ) ;
return V_54 ;
}
static int F_47 ( struct V_10 * V_11 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_48 ( V_11 ) ;
long V_55 , V_56 ;
if ( F_12 ( F_38 ( V_2 , V_49 ) ) )
goto V_57;
if ( V_48 -> V_58 ||
F_49 ( V_2 , V_52 ) < F_50 ( V_2 , V_13 ) )
goto V_57;
if ( ! F_51 ( & V_2 -> V_59 ) )
goto V_57;
F_52 ( V_11 -> V_53 , V_48 , V_13 ) ;
V_55 = F_53 ( V_2 , V_13 , V_48 ) ;
V_56 = F_54 ( V_2 , V_13 , V_48 -> V_60 ) ;
F_55 ( & V_2 -> V_59 ) ;
V_48 -> V_60 = F_56 ( ( long ) 0 , V_48 -> V_60 - V_56 - V_55 ) ;
return 0 ;
V_57:
V_48 -> V_61 += F_49 ( V_2 , V_52 ) ;
F_52 ( V_11 -> V_53 , V_48 , V_13 ) ;
return 0 ;
}
long F_54 ( struct V_1 * V_2 , enum V_62 type ,
long V_60 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
T_1 V_9 = 0 , V_63 = V_64 , V_65 = V_64 ;
struct V_66 V_67 ;
long V_68 = 0 ;
struct V_47 V_48 = {
. V_51 = 0 ,
} ;
struct V_40 V_41 ;
F_57 ( & V_67 , 0 ) ;
F_27 ( & V_41 ) ;
while ( V_9 <= V_63 ) {
int V_69 , V_70 ;
V_70 = F_58 ( & V_67 , V_11 , & V_9 ,
V_71 ,
F_59 ( V_63 - V_9 , ( T_1 ) V_72 - 1 ) + 1 ) ;
if ( F_12 ( V_70 == 0 ) )
break;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
struct V_8 * V_8 = V_67 . V_73 [ V_69 ] ;
if ( V_65 == V_64 )
V_65 = V_8 -> V_9 - 1 ;
if ( V_60 != V_74 && V_8 -> V_9 != V_65 + 1 ) {
F_60 ( & V_67 ) ;
goto V_75;
}
F_15 ( V_8 ) ;
if ( F_12 ( V_8 -> V_11 != V_11 ) ) {
V_76:
F_44 ( V_8 ) ;
continue;
}
if ( ! F_61 ( V_8 ) ) {
goto V_76;
}
F_8 ( V_8 , V_13 , true ) ;
F_62 ( F_63 ( V_8 ) ) ;
if ( ! F_64 ( V_8 ) )
goto V_76;
if ( V_11 -> V_77 -> V_78 ( V_8 , & V_48 ) ) {
F_44 ( V_8 ) ;
break;
}
V_68 ++ ;
V_65 = V_8 -> V_9 ;
if ( F_12 ( V_68 >= V_60 ) )
break;
}
F_60 ( & V_67 ) ;
F_7 () ;
}
V_75:
if ( V_68 )
F_45 ( V_2 , type ) ;
F_32 ( & V_41 ) ;
return V_68 ;
}
static int F_65 ( struct V_8 * V_8 )
{
F_66 ( V_8 , V_13 ) ;
if ( ! F_9 ( V_8 ) )
F_10 ( V_8 ) ;
if ( ! F_61 ( V_8 ) ) {
F_67 ( V_8 ) ;
F_68 ( F_36 ( V_8 ) , V_52 ) ;
F_69 ( V_8 ) ;
F_70 ( V_8 ) ;
return 1 ;
}
return 0 ;
}
static void F_71 ( struct V_1 * V_2 , T_3 V_79 , int type )
{
struct V_80 * V_81 = & V_2 -> V_81 [ type ] ;
struct V_82 * V_83 , * V_84 ;
V_84 = F_72 ( V_85 , V_86 ) ;
V_87:
F_73 ( V_86 | V_88 ) ;
F_74 ( & V_81 -> V_89 ) ;
V_83 = F_75 ( & V_81 -> V_90 , V_79 ) ;
if ( ! V_83 ) {
V_83 = V_84 ;
if ( F_76 ( & V_81 -> V_90 , V_79 , V_83 ) ) {
F_77 ( & V_81 -> V_89 ) ;
F_78 () ;
goto V_87;
}
memset ( V_83 , 0 , sizeof( struct V_82 ) ) ;
V_83 -> V_79 = V_79 ;
F_79 ( & V_83 -> V_91 , & V_81 -> V_92 ) ;
if ( type != V_93 )
V_81 -> V_94 ++ ;
}
F_77 ( & V_81 -> V_89 ) ;
F_78 () ;
if ( V_83 != V_84 )
F_80 ( V_85 , V_84 ) ;
}
static void F_81 ( struct V_1 * V_2 , T_3 V_79 , int type )
{
struct V_80 * V_81 = & V_2 -> V_81 [ type ] ;
struct V_82 * V_83 ;
F_74 ( & V_81 -> V_89 ) ;
V_83 = F_75 ( & V_81 -> V_90 , V_79 ) ;
if ( V_83 ) {
F_82 ( & V_83 -> V_91 ) ;
F_83 ( & V_81 -> V_90 , V_79 ) ;
V_81 -> V_94 -- ;
F_77 ( & V_81 -> V_89 ) ;
F_80 ( V_85 , V_83 ) ;
return;
}
F_77 ( & V_81 -> V_89 ) ;
}
void F_84 ( struct V_1 * V_2 , T_3 V_79 , int type )
{
F_71 ( V_2 , V_79 , type ) ;
}
void F_85 ( struct V_1 * V_2 , T_3 V_79 , int type )
{
F_81 ( V_2 , V_79 , type ) ;
}
bool F_86 ( struct V_1 * V_2 , T_3 V_79 , int V_95 )
{
struct V_80 * V_81 = & V_2 -> V_81 [ V_95 ] ;
struct V_82 * V_83 ;
F_74 ( & V_81 -> V_89 ) ;
V_83 = F_75 ( & V_81 -> V_90 , V_79 ) ;
F_77 ( & V_81 -> V_89 ) ;
return V_83 ? true : false ;
}
void F_87 ( struct V_1 * V_2 , bool V_96 )
{
struct V_82 * V_83 , * V_84 ;
int V_69 ;
for ( V_69 = V_96 ? V_93 : V_97 ; V_69 <= V_98 ; V_69 ++ ) {
struct V_80 * V_81 = & V_2 -> V_81 [ V_69 ] ;
F_74 ( & V_81 -> V_89 ) ;
F_88 (e, tmp, &im->ino_list, list) {
F_82 ( & V_83 -> V_91 ) ;
F_83 ( & V_81 -> V_90 , V_83 -> V_79 ) ;
F_80 ( V_85 , V_83 ) ;
V_81 -> V_94 -- ;
}
F_77 ( & V_81 -> V_89 ) ;
}
}
int F_89 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = & V_2 -> V_81 [ V_93 ] ;
int V_99 = 0 ;
F_74 ( & V_81 -> V_89 ) ;
#ifdef F_90
if ( F_91 ( V_2 , V_100 ) ) {
F_77 ( & V_81 -> V_89 ) ;
F_92 ( V_100 ) ;
return - V_101 ;
}
#endif
if ( F_12 ( V_81 -> V_94 >= V_2 -> V_102 ) )
V_99 = - V_101 ;
else
V_81 -> V_94 ++ ;
F_77 ( & V_81 -> V_89 ) ;
return V_99 ;
}
void F_93 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = & V_2 -> V_81 [ V_93 ] ;
F_74 ( & V_81 -> V_89 ) ;
F_94 ( V_2 , V_81 -> V_94 == 0 ) ;
V_81 -> V_94 -- ;
F_77 ( & V_81 -> V_89 ) ;
}
void F_95 ( struct V_103 * V_103 )
{
F_71 ( F_96 ( V_103 ) , V_103 -> V_104 , V_93 ) ;
F_97 ( V_103 ) ;
}
void F_98 ( struct V_1 * V_2 , T_3 V_79 )
{
F_81 ( V_2 , V_79 , V_93 ) ;
}
static int F_99 ( struct V_1 * V_2 , T_3 V_79 )
{
struct V_103 * V_103 ;
struct V_105 V_106 ;
int V_99 = F_89 ( V_2 ) ;
if ( V_99 ) {
F_100 ( V_2 , V_107 ) ;
F_101 ( V_2 -> V_5 , V_108 ,
L_1 ,
V_109 , V_79 ) ;
return V_99 ;
}
F_71 ( V_2 , V_79 , V_93 ) ;
V_103 = F_102 ( V_2 -> V_5 , V_79 ) ;
if ( F_103 ( V_103 ) ) {
F_94 ( V_2 , F_104 ( V_103 ) == - V_110 ) ;
return F_104 ( V_103 ) ;
}
F_105 ( V_103 ) ;
F_106 ( V_103 ) ;
F_107 ( V_2 , V_79 , & V_106 ) ;
if ( V_106 . V_111 != V_112 ) {
F_100 ( V_2 , V_107 ) ;
F_101 ( V_2 -> V_5 , V_108 ,
L_2 ,
V_109 , V_79 ) ;
return - V_113 ;
}
F_81 ( V_2 , V_79 , V_93 ) ;
return 0 ;
}
int F_108 ( struct V_1 * V_2 )
{
T_2 V_114 , V_115 , V_69 , V_116 ;
int V_99 ;
if ( ! F_109 ( V_2 , V_117 ) )
return 0 ;
V_114 = F_23 ( V_2 ) + 1 + F_110 ( V_2 ) ;
V_115 = F_111 ( V_2 ) - 1 - F_110 ( V_2 ) ;
F_26 ( V_2 , V_114 , V_115 , V_31 , true ) ;
for ( V_69 = 0 ; V_69 < V_115 ; V_69 ++ ) {
struct V_8 * V_8 = F_16 ( V_2 , V_114 + V_69 ) ;
struct V_118 * V_119 ;
V_119 = (struct V_118 * ) F_112 ( V_8 ) ;
for ( V_116 = 0 ; V_116 < F_113 ( V_119 -> V_120 ) ; V_116 ++ ) {
T_3 V_79 = F_113 ( V_119 -> V_79 [ V_116 ] ) ;
V_99 = F_99 ( V_2 , V_79 ) ;
if ( V_99 ) {
F_14 ( V_8 , 1 ) ;
return V_99 ;
}
}
F_14 ( V_8 , 1 ) ;
}
F_114 ( V_2 , V_117 ) ;
return 0 ;
}
static void F_115 ( struct V_1 * V_2 , T_2 V_114 )
{
struct V_121 * V_122 ;
struct V_118 * V_119 = NULL ;
unsigned int V_123 = 0 ;
unsigned short V_9 = 1 ;
unsigned short V_115 ;
struct V_8 * V_8 = NULL ;
struct V_82 * V_124 = NULL ;
struct V_80 * V_81 = & V_2 -> V_81 [ V_93 ] ;
V_115 = F_116 ( V_81 -> V_94 ) ;
V_122 = & V_81 -> V_92 ;
F_117 (orphan, head, list) {
if ( ! V_8 ) {
V_8 = F_4 ( V_2 , V_114 ++ ) ;
V_119 =
(struct V_118 * ) F_112 ( V_8 ) ;
memset ( V_119 , 0 , sizeof( * V_119 ) ) ;
}
V_119 -> V_79 [ V_123 ++ ] = F_118 ( V_124 -> V_79 ) ;
if ( V_123 == V_125 ) {
V_119 -> V_111 = F_119 ( V_9 ) ;
V_119 -> V_126 = F_119 ( V_115 ) ;
V_119 -> V_120 = F_118 ( V_123 ) ;
F_120 ( V_8 ) ;
F_14 ( V_8 , 1 ) ;
V_9 ++ ;
V_123 = 0 ;
V_8 = NULL ;
}
}
if ( V_8 ) {
V_119 -> V_111 = F_119 ( V_9 ) ;
V_119 -> V_126 = F_119 ( V_115 ) ;
V_119 -> V_120 = F_118 ( V_123 ) ;
F_120 ( V_8 ) ;
F_14 ( V_8 , 1 ) ;
}
}
static int F_121 ( struct V_1 * V_2 , T_2 V_127 ,
struct V_128 * * V_129 , struct V_8 * * V_130 ,
unsigned long long * V_131 )
{
unsigned long V_132 = V_2 -> V_133 ;
T_4 V_134 = 0 ;
T_5 V_135 = 0 ;
* V_130 = F_16 ( V_2 , V_127 ) ;
* V_129 = (struct V_128 * ) F_112 ( * V_130 ) ;
V_134 = F_113 ( ( * V_129 ) -> V_136 ) ;
if ( V_134 > ( V_132 - sizeof( V_137 ) ) ) {
F_101 ( V_2 -> V_5 , V_108 ,
L_3 , V_134 ) ;
return - V_138 ;
}
V_135 = F_122 ( * V_129 ) ;
if ( ! F_123 ( V_2 , V_135 , * V_129 , V_134 ) ) {
F_101 ( V_2 -> V_5 , V_108 , L_4 ) ;
return - V_138 ;
}
* V_131 = F_124 ( * V_129 ) ;
return 0 ;
}
static struct V_8 * F_125 ( struct V_1 * V_2 ,
T_2 V_127 , unsigned long long * V_131 )
{
struct V_8 * V_139 = NULL , * V_140 = NULL ;
struct V_128 * V_129 = NULL ;
unsigned long long V_141 = 0 , V_142 = 0 ;
int V_99 ;
V_99 = F_121 ( V_2 , V_127 , & V_129 ,
& V_139 , V_131 ) ;
if ( V_99 )
goto V_143;
V_142 = * V_131 ;
V_127 += F_113 ( V_129 -> V_144 ) - 1 ;
V_99 = F_121 ( V_2 , V_127 , & V_129 ,
& V_140 , V_131 ) ;
if ( V_99 )
goto V_145;
V_141 = * V_131 ;
if ( V_141 == V_142 ) {
* V_131 = V_141 ;
F_14 ( V_140 , 1 ) ;
return V_139 ;
}
V_145:
F_14 ( V_140 , 1 ) ;
V_143:
F_14 ( V_139 , 1 ) ;
return NULL ;
}
int F_126 ( struct V_1 * V_2 )
{
struct V_128 * V_129 ;
struct V_146 * V_147 = V_2 -> V_148 ;
struct V_8 * V_149 , * V_150 , * V_151 ;
unsigned long V_132 = V_2 -> V_133 ;
unsigned long long V_152 = 0 , V_153 = 0 ;
unsigned long long V_154 ;
unsigned int V_155 = 1 + F_110 ( V_2 ) ;
T_2 V_156 ;
int V_69 ;
V_2 -> V_157 = F_127 ( V_155 * V_132 , V_158 ) ;
if ( ! V_2 -> V_157 )
return - V_159 ;
V_154 = F_113 ( V_147 -> V_160 ) ;
V_149 = F_125 ( V_2 , V_154 , & V_152 ) ;
V_154 += ( ( unsigned long long ) 1 ) <<
F_113 ( V_147 -> V_161 ) ;
V_150 = F_125 ( V_2 , V_154 , & V_153 ) ;
if ( V_149 && V_150 ) {
if ( F_128 ( V_153 , V_152 ) )
V_151 = V_150 ;
else
V_151 = V_149 ;
} else if ( V_149 ) {
V_151 = V_149 ;
} else if ( V_150 ) {
V_151 = V_150 ;
} else {
goto V_162;
}
V_129 = (struct V_128 * ) F_112 ( V_151 ) ;
memcpy ( V_2 -> V_157 , V_129 , V_132 ) ;
if ( F_129 ( V_2 ) )
goto V_163;
if ( V_151 == V_149 )
V_2 -> V_164 = 1 ;
else
V_2 -> V_164 = 2 ;
if ( V_155 <= 1 )
goto V_165;
V_156 = F_113 ( V_147 -> V_160 ) ;
if ( V_151 == V_150 )
V_156 += 1 << F_113 ( V_147 -> V_161 ) ;
for ( V_69 = 1 ; V_69 < V_155 ; V_69 ++ ) {
void * V_166 ;
unsigned char * V_157 = ( unsigned char * ) V_2 -> V_157 ;
V_151 = F_16 ( V_2 , V_156 + V_69 ) ;
V_166 = F_112 ( V_151 ) ;
memcpy ( V_157 + V_69 * V_132 , V_166 , V_132 ) ;
F_14 ( V_151 , 1 ) ;
}
V_165:
F_14 ( V_149 , 1 ) ;
F_14 ( V_150 , 1 ) ;
return 0 ;
V_163:
F_14 ( V_149 , 1 ) ;
F_14 ( V_150 , 1 ) ;
V_162:
F_130 ( V_2 -> V_157 ) ;
return - V_138 ;
}
static void F_131 ( struct V_103 * V_103 , enum V_167 type )
{
struct V_1 * V_2 = F_96 ( V_103 ) ;
int V_168 = ( type == V_169 ) ? V_170 : V_171 ;
if ( F_132 ( V_103 , V_168 ) )
return;
F_133 ( V_103 , V_168 ) ;
if ( ! F_134 ( V_103 ) )
F_79 ( & F_135 ( V_103 ) -> V_172 ,
& V_2 -> V_173 [ type ] ) ;
F_136 ( V_2 , type ) ;
}
static void F_137 ( struct V_103 * V_103 , enum V_167 type )
{
int V_168 = ( type == V_169 ) ? V_170 : V_171 ;
if ( F_138 ( V_103 ) || ! F_132 ( V_103 , V_168 ) )
return;
F_139 ( & F_135 ( V_103 ) -> V_172 ) ;
F_140 ( V_103 , V_168 ) ;
F_141 ( F_96 ( V_103 ) , type ) ;
}
void F_142 ( struct V_103 * V_103 , struct V_8 * V_8 )
{
struct V_1 * V_2 = F_96 ( V_103 ) ;
enum V_167 type = F_143 ( V_103 -> V_174 ) ? V_169 : V_175 ;
if ( ! F_143 ( V_103 -> V_174 ) && ! F_144 ( V_103 -> V_174 ) &&
! F_145 ( V_103 -> V_174 ) )
return;
F_74 ( & V_2 -> V_176 [ type ] ) ;
if ( type != V_175 || F_146 ( V_2 , V_177 ) )
F_131 ( V_103 , type ) ;
F_147 ( V_103 ) ;
F_77 ( & V_2 -> V_176 [ type ] ) ;
F_69 ( V_8 ) ;
F_70 ( V_8 ) ;
}
void F_148 ( struct V_103 * V_103 )
{
struct V_1 * V_2 = F_96 ( V_103 ) ;
enum V_167 type = F_143 ( V_103 -> V_174 ) ? V_169 : V_175 ;
if ( ! F_143 ( V_103 -> V_174 ) && ! F_144 ( V_103 -> V_174 ) &&
! F_145 ( V_103 -> V_174 ) )
return;
if ( type == V_175 && ! F_146 ( V_2 , V_177 ) )
return;
F_74 ( & V_2 -> V_176 [ type ] ) ;
F_137 ( V_103 , type ) ;
F_77 ( & V_2 -> V_176 [ type ] ) ;
}
int F_149 ( struct V_1 * V_2 , enum V_167 type )
{
struct V_121 * V_122 ;
struct V_103 * V_103 ;
struct V_178 * V_179 ;
bool V_180 = ( type == V_169 ) ;
unsigned long V_79 = 0 ;
F_150 ( V_2 -> V_5 , V_180 ,
F_49 ( V_2 , V_180 ?
V_181 : V_182 ) ) ;
V_87:
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_113 ;
F_74 ( & V_2 -> V_176 [ type ] ) ;
V_122 = & V_2 -> V_173 [ type ] ;
if ( F_151 ( V_122 ) ) {
F_77 ( & V_2 -> V_176 [ type ] ) ;
F_152 ( V_2 -> V_5 , V_180 ,
F_49 ( V_2 , V_180 ?
V_181 : V_182 ) ) ;
return 0 ;
}
V_179 = F_153 ( V_122 , struct V_178 , V_172 ) ;
V_103 = F_154 ( & V_179 -> V_183 ) ;
F_77 ( & V_2 -> V_176 [ type ] ) ;
if ( V_103 ) {
unsigned long V_184 = V_103 -> V_104 ;
F_155 ( V_103 -> V_185 ) ;
F_106 ( V_103 ) ;
if ( V_79 == V_184 ) {
F_156 ( V_186 , V_187 / 50 ) ;
F_7 () ;
} else {
V_79 = V_184 ;
}
} else {
F_45 ( V_2 , V_188 ) ;
F_7 () ;
}
goto V_87;
}
int F_157 ( struct V_1 * V_2 )
{
struct V_121 * V_122 = & V_2 -> V_173 [ V_189 ] ;
struct V_103 * V_103 ;
struct V_178 * V_179 ;
T_6 V_190 = F_49 ( V_2 , V_191 ) ;
while ( V_190 -- ) {
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_113 ;
F_74 ( & V_2 -> V_176 [ V_189 ] ) ;
if ( F_151 ( V_122 ) ) {
F_77 ( & V_2 -> V_176 [ V_189 ] ) ;
return 0 ;
}
V_179 = F_153 ( V_122 , struct V_178 ,
V_192 ) ;
V_103 = F_154 ( & V_179 -> V_183 ) ;
F_77 ( & V_2 -> V_176 [ V_189 ] ) ;
if ( V_103 ) {
F_158 ( V_103 , 0 ) ;
if ( F_132 ( V_103 , V_193 ) )
F_97 ( V_103 ) ;
F_106 ( V_103 ) ;
}
} ;
return 0 ;
}
static void F_159 ( struct V_1 * V_2 )
{
struct V_128 * V_157 = F_160 ( V_2 ) ;
struct V_194 * V_195 = F_29 ( V_2 ) ;
T_3 V_196 = V_195 -> V_197 ;
F_161 ( V_2 , & V_196 ) ;
V_157 -> V_198 = F_162 ( F_163 ( V_2 ) ) ;
V_157 -> V_199 = F_118 ( V_199 ( V_2 ) ) ;
V_157 -> V_200 = F_118 ( V_200 ( V_2 ) ) ;
V_157 -> F_161 = F_118 ( V_196 ) ;
}
static int F_164 ( struct V_1 * V_2 )
{
struct V_47 V_48 = {
. V_201 = V_202 ,
. V_60 = V_74 ,
. V_51 = 0 ,
} ;
struct V_40 V_41 ;
int V_99 = 0 ;
F_27 ( & V_41 ) ;
V_203:
F_165 ( V_2 ) ;
if ( F_49 ( V_2 , V_181 ) ) {
F_166 ( V_2 ) ;
V_99 = F_149 ( V_2 , V_169 ) ;
if ( V_99 )
goto V_25;
F_7 () ;
goto V_203;
}
F_167 ( & V_2 -> V_204 ) ;
if ( F_49 ( V_2 , V_191 ) ) {
F_168 ( & V_2 -> V_204 ) ;
F_166 ( V_2 ) ;
V_99 = F_157 ( V_2 ) ;
if ( V_99 )
goto V_25;
F_7 () ;
goto V_203;
}
V_205:
F_167 ( & V_2 -> V_206 ) ;
if ( F_49 ( V_2 , V_207 ) ) {
F_168 ( & V_2 -> V_206 ) ;
V_99 = F_169 ( V_2 , & V_48 ) ;
if ( V_99 ) {
F_168 ( & V_2 -> V_204 ) ;
F_166 ( V_2 ) ;
goto V_25;
}
F_7 () ;
goto V_205;
}
F_159 ( V_2 ) ;
F_168 ( & V_2 -> V_204 ) ;
V_25:
F_32 ( & V_41 ) ;
return V_99 ;
}
static void F_170 ( struct V_1 * V_2 )
{
F_168 ( & V_2 -> V_206 ) ;
F_166 ( V_2 ) ;
}
static void F_171 ( struct V_1 * V_2 )
{
F_172 ( V_208 ) ;
for (; ; ) {
F_173 ( & V_2 -> V_209 , & V_208 , V_210 ) ;
if ( ! F_49 ( V_2 , V_211 ) )
break;
F_174 ( 5 * V_187 ) ;
}
F_175 ( & V_2 -> V_209 , & V_208 ) ;
}
static void F_176 ( struct V_1 * V_2 , struct V_212 * V_213 )
{
unsigned long V_214 = V_2 -> V_81 [ V_93 ] . V_94 ;
struct V_128 * V_157 = F_160 ( V_2 ) ;
unsigned long V_215 ;
F_177 ( & V_2 -> V_216 , V_215 ) ;
if ( ( V_213 -> V_217 & V_218 ) &&
F_113 ( V_157 -> V_144 ) >
V_2 -> V_219 - F_29 ( V_2 ) -> V_220 )
F_178 ( V_2 , false ) ;
if ( V_213 -> V_217 & V_221 )
F_179 ( V_157 , V_222 ) ;
if ( V_213 -> V_217 & V_218 )
F_179 ( V_157 , V_223 ) ;
else
F_180 ( V_157 , V_223 ) ;
if ( V_213 -> V_217 & V_224 )
F_179 ( V_157 , V_225 ) ;
else
F_180 ( V_157 , V_225 ) ;
if ( V_214 )
F_179 ( V_157 , V_117 ) ;
else
F_180 ( V_157 , V_117 ) ;
if ( F_38 ( V_2 , V_107 ) )
F_179 ( V_157 , V_226 ) ;
F_179 ( V_157 , V_227 ) ;
F_181 ( & V_2 -> V_216 , V_215 ) ;
}
static int F_182 ( struct V_1 * V_2 , struct V_212 * V_213 )
{
struct V_128 * V_157 = F_160 ( V_2 ) ;
struct V_194 * V_195 = F_29 ( V_2 ) ;
unsigned long V_214 = V_2 -> V_81 [ V_93 ] . V_94 , V_215 ;
T_2 V_114 ;
unsigned int V_228 , V_115 ;
T_5 V_229 = 0 ;
int V_69 ;
int V_230 = F_110 ( V_2 ) ;
struct V_231 * V_5 = V_2 -> V_5 ;
struct V_232 * V_233 = F_183 ( V_2 , V_234 ) ;
T_7 V_235 ;
while ( F_49 ( V_2 , V_52 ) ) {
F_54 ( V_2 , V_13 , V_74 ) ;
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_113 ;
}
V_157 -> V_236 = F_162 ( F_184 ( V_2 ) ) ;
V_157 -> V_237 = F_118 ( F_185 ( V_2 ) ) ;
for ( V_69 = 0 ; V_69 < V_238 ; V_69 ++ ) {
V_157 -> V_239 [ V_69 ] =
F_118 ( F_186 ( V_2 , V_69 + V_234 ) ) ;
V_157 -> V_240 [ V_69 ] =
F_119 ( F_187 ( V_2 , V_69 + V_234 ) ) ;
V_157 -> V_241 [ V_69 + V_234 ] =
F_188 ( V_2 , V_69 + V_234 ) ;
}
for ( V_69 = 0 ; V_69 < V_242 ; V_69 ++ ) {
V_157 -> V_243 [ V_69 ] =
F_118 ( F_186 ( V_2 , V_69 + V_244 ) ) ;
V_157 -> V_245 [ V_69 ] =
F_119 ( F_187 ( V_2 , V_69 + V_244 ) ) ;
V_157 -> V_241 [ V_69 + V_244 ] =
F_188 ( V_2 , V_69 + V_244 ) ;
}
V_228 = F_189 ( V_2 , false ) ;
F_177 ( & V_2 -> V_216 , V_215 ) ;
if ( V_228 < V_242 )
F_179 ( V_157 , V_246 ) ;
else
F_180 ( V_157 , V_246 ) ;
F_181 ( & V_2 -> V_216 , V_215 ) ;
V_115 = F_116 ( V_214 ) ;
V_157 -> V_247 = F_118 ( 1 + V_230 +
V_115 ) ;
if ( F_190 ( V_213 -> V_217 ) )
V_157 -> V_144 = F_118 ( V_248 +
V_230 + V_228 +
V_115 + V_238 ) ;
else
V_157 -> V_144 = F_118 ( V_248 +
V_230 + V_228 +
V_115 ) ;
F_176 ( V_2 , V_213 ) ;
F_191 ( V_2 , F_192 ( V_2 , V_249 ) ) ;
F_193 ( V_2 , F_192 ( V_2 , V_250 ) ) ;
V_229 = F_194 ( V_2 , V_157 , F_113 ( V_157 -> V_136 ) ) ;
* ( ( V_137 * ) ( ( unsigned char * ) V_157 +
F_113 ( V_157 -> V_136 ) ) )
= F_118 ( V_229 ) ;
V_114 = F_195 ( V_2 ) ;
if ( F_196 ( V_2 , V_213 ) ) {
T_8 V_251 = F_124 ( V_157 ) ;
T_2 V_252 ;
V_251 |= ( ( T_8 ) V_229 << 32 ) ;
* ( V_253 * ) V_195 -> V_254 = F_162 ( V_251 ) ;
V_252 = V_114 + V_2 -> V_219 - V_195 -> V_220 ;
for ( V_69 = 0 ; V_69 < V_195 -> V_220 ; V_69 ++ )
F_197 ( V_2 , V_195 -> V_254 +
( V_69 << V_255 ) , V_252 + V_69 ) ;
while ( F_49 ( V_2 , V_52 ) ) {
F_54 ( V_2 , V_13 , V_74 ) ;
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_113 ;
}
}
F_171 ( V_2 ) ;
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_113 ;
F_197 ( V_2 , V_157 , V_114 ++ ) ;
for ( V_69 = 1 ; V_69 < 1 + V_230 ; V_69 ++ )
F_197 ( V_2 , ( char * ) V_157 + V_69 * V_256 ,
V_114 ++ ) ;
if ( V_214 ) {
F_115 ( V_2 , V_114 ) ;
V_114 += V_115 ;
}
F_198 ( V_2 , V_114 ) ;
V_114 += V_228 ;
V_235 = V_2 -> V_235 ;
if ( V_5 -> V_257 -> V_258 )
V_235 += F_199 ( V_2 ) ;
V_233 -> V_259 -> V_260 . V_235 = F_162 ( V_235 ) ;
if ( F_190 ( V_213 -> V_217 ) ) {
F_200 ( V_2 , V_114 ) ;
V_114 += V_238 ;
}
F_197 ( V_2 , V_157 , V_114 ) ;
F_171 ( V_2 ) ;
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_113 ;
F_201 ( F_202 ( V_2 ) , 0 , V_261 ) ;
F_201 ( F_5 ( V_2 ) , 0 , V_261 ) ;
V_2 -> V_262 = V_2 -> V_263 ;
F_203 ( & V_2 -> V_264 , 0 ) ;
F_54 ( V_2 , V_265 , V_74 ) ;
F_171 ( V_2 ) ;
F_87 ( V_2 , false ) ;
if ( F_12 ( F_40 ( V_2 ) ) )
return - V_113 ;
F_204 ( V_2 , V_266 ) ;
F_204 ( V_2 , V_267 ) ;
F_205 ( V_2 ) ;
if ( F_49 ( V_2 , V_207 ) ||
F_49 ( V_2 , V_191 ) )
F_100 ( V_2 , V_266 ) ;
F_94 ( V_2 , F_49 ( V_2 , V_181 ) ) ;
return 0 ;
}
int F_206 ( struct V_1 * V_2 , struct V_212 * V_213 )
{
struct V_128 * V_157 = F_160 ( V_2 ) ;
unsigned long long V_268 ;
int V_99 = 0 ;
F_207 ( & V_2 -> V_59 ) ;
if ( ! F_38 ( V_2 , V_266 ) &&
( ( V_213 -> V_217 & V_224 ) || ( V_213 -> V_217 & V_269 ) ||
( ( V_213 -> V_217 & V_270 ) && ! V_2 -> V_271 ) ) )
goto V_25;
if ( F_12 ( F_40 ( V_2 ) ) ) {
V_99 = - V_113 ;
goto V_25;
}
if ( F_208 ( V_2 -> V_5 ) ) {
V_99 = - V_272 ;
goto V_25;
}
F_209 ( V_2 -> V_5 , V_213 -> V_217 , L_5 ) ;
V_99 = F_164 ( V_2 ) ;
if ( V_99 )
goto V_25;
F_209 ( V_2 -> V_5 , V_213 -> V_217 , L_6 ) ;
F_3 ( V_2 ) ;
if ( V_213 -> V_217 & V_270 ) {
if ( ! F_210 ( V_2 , V_213 ) ) {
F_170 ( V_2 ) ;
goto V_25;
}
if ( F_29 ( V_2 ) -> V_273 == 0 &&
F_22 ( V_2 ) -> V_274 == 0 &&
F_211 ( V_2 ) == 0 ) {
F_212 ( V_2 , V_213 ) ;
F_213 ( V_2 , V_213 ) ;
F_170 ( V_2 ) ;
goto V_25;
}
}
V_268 = F_124 ( V_157 ) ;
V_157 -> V_275 = F_162 ( ++ V_268 ) ;
F_214 ( V_2 , V_213 ) ;
F_212 ( V_2 , V_213 ) ;
V_99 = F_182 ( V_2 , V_213 ) ;
if ( V_99 )
F_215 ( V_2 ) ;
else
F_213 ( V_2 , V_213 ) ;
F_170 ( V_2 ) ;
F_216 ( V_2 -> V_276 ) ;
if ( V_213 -> V_217 & V_277 )
F_101 ( V_2 -> V_5 , V_278 ,
L_7 , V_268 ) ;
F_217 ( V_2 , V_279 ) ;
F_209 ( V_2 -> V_5 , V_213 -> V_217 , L_8 ) ;
V_25:
F_55 ( & V_2 -> V_59 ) ;
return V_99 ;
}
void F_218 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_280 ; V_69 ++ ) {
struct V_80 * V_81 = & V_2 -> V_81 [ V_69 ] ;
F_219 ( & V_81 -> V_90 , V_281 ) ;
F_220 ( & V_81 -> V_89 ) ;
F_221 ( & V_81 -> V_92 ) ;
V_81 -> V_94 = 0 ;
}
V_2 -> V_102 = ( V_2 -> V_219 - V_248 -
V_282 - F_110 ( V_2 ) ) *
V_125 ;
}
int T_9 F_222 ( void )
{
V_85 = F_223 ( L_9 ,
sizeof( struct V_82 ) ) ;
if ( ! V_85 )
return - V_159 ;
V_283 = F_223 ( L_10 ,
sizeof( struct V_284 ) ) ;
if ( ! V_283 ) {
F_224 ( V_85 ) ;
return - V_159 ;
}
return 0 ;
}
void F_225 ( void )
{
F_224 ( V_85 ) ;
F_224 ( V_283 ) ;
}
