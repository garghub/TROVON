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
} ;
struct V_39 V_40 ;
if ( F_12 ( type == V_33 ) )
V_16 . V_19 &= ~ V_20 ;
F_27 ( & V_40 ) ;
for (; V_35 -- > 0 ; V_37 ++ ) {
if ( ! F_18 ( V_2 , V_37 , type ) )
goto V_25;
switch ( type ) {
case V_27 :
if ( F_12 ( V_37 >=
F_28 ( F_29 ( V_2 ) -> V_41 ) ) )
V_37 = 0 ;
V_16 . V_23 = F_30 ( V_2 ,
V_37 * V_42 ) ;
break;
case V_28 :
V_16 . V_23 = F_31 ( V_2 ,
V_37 * V_43 ) ;
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
V_16 . V_22 = V_16 . V_23 ;
F_32 ( & V_16 ) ;
F_14 ( V_8 , 0 ) ;
}
V_25:
F_33 ( V_2 , V_13 , V_44 ) ;
F_34 ( & V_40 ) ;
return V_37 - V_34 ;
}
void F_35 ( struct V_1 * V_2 , T_1 V_9 )
{
struct V_8 * V_8 ;
bool V_45 = false ;
V_8 = F_36 ( F_5 ( V_2 ) , V_9 ) ;
if ( ! V_8 || ! F_9 ( V_8 ) )
V_45 = true ;
F_14 ( V_8 , 0 ) ;
if ( V_45 )
F_26 ( V_2 , V_9 , V_46 , V_33 , true ) ;
}
static int F_37 ( struct V_8 * V_8 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_38 ( V_8 ) ;
F_39 ( V_8 , V_13 ) ;
if ( F_12 ( F_40 ( V_2 , V_49 ) ) )
goto V_50;
if ( V_48 -> V_51 && V_8 -> V_9 < F_41 ( V_2 , 0 ) )
goto V_50;
if ( F_12 ( F_42 ( V_2 ) ) )
goto V_50;
F_43 ( V_2 , V_8 ) ;
F_44 ( V_2 , V_52 ) ;
if ( V_48 -> V_51 )
F_45 ( V_2 , NULL , V_8 , 0 , V_13 , V_53 ) ;
F_46 ( V_8 ) ;
if ( F_12 ( F_42 ( V_2 ) ) )
F_33 ( V_2 , V_13 , V_53 ) ;
return 0 ;
V_50:
F_47 ( V_48 , V_8 ) ;
return V_54 ;
}
static int F_48 ( struct V_10 * V_11 ,
struct V_47 * V_48 )
{
struct V_1 * V_2 = F_49 ( V_11 ) ;
long V_55 , V_56 ;
if ( V_48 -> V_57 ||
F_50 ( V_2 , V_52 ) < F_51 ( V_2 , V_13 ) )
goto V_58;
F_52 ( V_11 -> V_59 , V_48 , V_13 ) ;
F_53 ( & V_2 -> V_60 ) ;
V_55 = F_54 ( V_2 , V_13 , V_48 ) ;
V_56 = F_55 ( V_2 , V_13 , V_48 -> V_61 ) ;
F_56 ( & V_2 -> V_60 ) ;
V_48 -> V_61 = F_57 ( ( long ) 0 , V_48 -> V_61 - V_56 - V_55 ) ;
return 0 ;
V_58:
V_48 -> V_62 += F_50 ( V_2 , V_52 ) ;
F_52 ( V_11 -> V_59 , V_48 , V_13 ) ;
return 0 ;
}
long F_55 ( struct V_1 * V_2 , enum V_63 type ,
long V_61 )
{
struct V_10 * V_11 = F_5 ( V_2 ) ;
T_1 V_9 = 0 , V_64 = V_65 , V_66 = V_65 ;
struct V_67 V_68 ;
long V_69 = 0 ;
struct V_47 V_48 = {
. V_51 = 0 ,
} ;
struct V_39 V_40 ;
F_58 ( & V_68 , 0 ) ;
F_27 ( & V_40 ) ;
while ( V_9 <= V_64 ) {
int V_70 , V_71 ;
V_71 = F_59 ( & V_68 , V_11 , & V_9 ,
V_72 ,
F_60 ( V_64 - V_9 , ( T_1 ) V_73 - 1 ) + 1 ) ;
if ( F_12 ( V_71 == 0 ) )
break;
for ( V_70 = 0 ; V_70 < V_71 ; V_70 ++ ) {
struct V_8 * V_8 = V_68 . V_74 [ V_70 ] ;
if ( V_66 == V_65 )
V_66 = V_8 -> V_9 - 1 ;
if ( V_61 != V_75 && V_8 -> V_9 != V_66 + 1 ) {
F_61 ( & V_68 ) ;
goto V_76;
}
F_15 ( V_8 ) ;
if ( F_12 ( V_8 -> V_11 != V_11 ) ) {
V_77:
F_46 ( V_8 ) ;
continue;
}
if ( ! F_62 ( V_8 ) ) {
goto V_77;
}
F_8 ( V_8 , V_13 , true ) ;
F_63 ( F_64 ( V_8 ) ) ;
if ( ! F_65 ( V_8 ) )
goto V_77;
if ( V_11 -> V_78 -> V_79 ( V_8 , & V_48 ) ) {
F_46 ( V_8 ) ;
break;
}
V_69 ++ ;
V_66 = V_8 -> V_9 ;
if ( F_12 ( V_69 >= V_61 ) )
break;
}
F_61 ( & V_68 ) ;
F_7 () ;
}
V_76:
if ( V_69 )
F_33 ( V_2 , type , V_53 ) ;
F_34 ( & V_40 ) ;
return V_69 ;
}
static int F_66 ( struct V_8 * V_8 )
{
F_67 ( V_8 , V_13 ) ;
if ( ! F_9 ( V_8 ) )
F_10 ( V_8 ) ;
if ( ! F_62 ( V_8 ) ) {
F_68 ( V_8 ) ;
F_69 ( F_38 ( V_8 ) , V_52 ) ;
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
int V_70 ;
for ( V_70 = V_97 ? V_94 : V_98 ; V_70 <= V_99 ; V_70 ++ ) {
struct V_81 * V_82 = & V_2 -> V_82 [ V_70 ] ;
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
void F_93 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = & V_2 -> V_82 [ V_94 ] ;
F_75 ( & V_82 -> V_90 ) ;
F_94 ( V_2 , V_82 -> V_95 == 0 ) ;
V_82 -> V_95 -- ;
F_78 ( & V_82 -> V_90 ) ;
}
void F_95 ( struct V_104 * V_104 )
{
F_72 ( F_96 ( V_104 ) , V_104 -> V_105 , V_94 ) ;
F_97 ( V_104 ) ;
}
void F_98 ( struct V_1 * V_2 , T_3 V_80 )
{
F_82 ( V_2 , V_80 , V_94 ) ;
}
static int F_99 ( struct V_1 * V_2 , T_3 V_80 )
{
struct V_104 * V_104 ;
struct V_106 V_107 ;
int V_100 = F_90 ( V_2 ) ;
if ( V_100 ) {
F_100 ( V_2 , V_108 ) ;
F_101 ( V_2 -> V_5 , V_109 ,
L_1 ,
V_110 , V_80 ) ;
return V_100 ;
}
F_72 ( V_2 , V_80 , V_94 ) ;
V_104 = F_102 ( V_2 -> V_5 , V_80 ) ;
if ( F_103 ( V_104 ) ) {
F_94 ( V_2 , F_104 ( V_104 ) == - V_111 ) ;
return F_104 ( V_104 ) ;
}
F_105 ( V_104 ) ;
F_106 ( V_104 ) ;
F_107 ( V_2 , V_80 , & V_107 ) ;
if ( V_107 . V_112 != V_113 ) {
F_100 ( V_2 , V_108 ) ;
F_101 ( V_2 -> V_5 , V_109 ,
L_1 ,
V_110 , V_80 ) ;
return - V_114 ;
}
F_82 ( V_2 , V_80 , V_94 ) ;
return 0 ;
}
int F_108 ( struct V_1 * V_2 )
{
T_2 V_115 , V_116 , V_70 , V_117 ;
int V_100 ;
if ( ! F_109 ( V_2 , V_118 ) )
return 0 ;
V_115 = F_23 ( V_2 ) + 1 + F_110 ( V_2 ) ;
V_116 = F_111 ( V_2 ) - 1 - F_110 ( V_2 ) ;
F_26 ( V_2 , V_115 , V_116 , V_31 , true ) ;
for ( V_70 = 0 ; V_70 < V_116 ; V_70 ++ ) {
struct V_8 * V_8 = F_16 ( V_2 , V_115 + V_70 ) ;
struct V_119 * V_120 ;
V_120 = (struct V_119 * ) F_112 ( V_8 ) ;
for ( V_117 = 0 ; V_117 < F_113 ( V_120 -> V_121 ) ; V_117 ++ ) {
T_3 V_80 = F_113 ( V_120 -> V_80 [ V_117 ] ) ;
V_100 = F_99 ( V_2 , V_80 ) ;
if ( V_100 ) {
F_14 ( V_8 , 1 ) ;
return V_100 ;
}
}
F_14 ( V_8 , 1 ) ;
}
F_114 ( V_2 , V_118 ) ;
return 0 ;
}
static void F_115 ( struct V_1 * V_2 , T_2 V_115 )
{
struct V_122 * V_123 ;
struct V_119 * V_120 = NULL ;
unsigned int V_124 = 0 ;
unsigned short V_9 = 1 ;
unsigned short V_116 ;
struct V_8 * V_8 = NULL ;
struct V_83 * V_125 = NULL ;
struct V_81 * V_82 = & V_2 -> V_82 [ V_94 ] ;
V_116 = F_116 ( V_82 -> V_95 ) ;
V_123 = & V_82 -> V_93 ;
F_117 (orphan, head, list) {
if ( ! V_8 ) {
V_8 = F_4 ( V_2 , V_115 ++ ) ;
V_120 =
(struct V_119 * ) F_112 ( V_8 ) ;
memset ( V_120 , 0 , sizeof( * V_120 ) ) ;
}
V_120 -> V_80 [ V_124 ++ ] = F_118 ( V_125 -> V_80 ) ;
if ( V_124 == V_126 ) {
V_120 -> V_112 = F_119 ( V_9 ) ;
V_120 -> V_127 = F_119 ( V_116 ) ;
V_120 -> V_121 = F_118 ( V_124 ) ;
F_120 ( V_8 ) ;
F_14 ( V_8 , 1 ) ;
V_9 ++ ;
V_124 = 0 ;
V_8 = NULL ;
}
}
if ( V_8 ) {
V_120 -> V_112 = F_119 ( V_9 ) ;
V_120 -> V_127 = F_119 ( V_116 ) ;
V_120 -> V_121 = F_118 ( V_124 ) ;
F_120 ( V_8 ) ;
F_14 ( V_8 , 1 ) ;
}
}
static int F_121 ( struct V_1 * V_2 , T_2 V_128 ,
struct V_129 * * V_130 , struct V_8 * * V_131 ,
unsigned long long * V_132 )
{
unsigned long V_133 = V_2 -> V_134 ;
T_4 V_135 = 0 ;
T_5 V_136 = 0 ;
* V_131 = F_16 ( V_2 , V_128 ) ;
* V_130 = (struct V_129 * ) F_112 ( * V_131 ) ;
V_135 = F_113 ( ( * V_130 ) -> V_137 ) ;
if ( V_135 >= V_133 ) {
F_101 ( V_2 -> V_5 , V_109 ,
L_2 , V_135 ) ;
return - V_138 ;
}
V_136 = F_113 ( * ( ( V_139 * ) ( ( unsigned char * ) * V_130
+ V_135 ) ) ) ;
if ( ! F_122 ( V_2 , V_136 , * V_130 , V_135 ) ) {
F_101 ( V_2 -> V_5 , V_109 , L_3 ) ;
return - V_138 ;
}
* V_132 = F_123 ( * V_130 ) ;
return 0 ;
}
static struct V_8 * F_124 ( struct V_1 * V_2 ,
T_2 V_128 , unsigned long long * V_132 )
{
struct V_8 * V_140 = NULL , * V_141 = NULL ;
struct V_129 * V_130 = NULL ;
unsigned long long V_142 = 0 , V_143 = 0 ;
int V_100 ;
V_100 = F_121 ( V_2 , V_128 , & V_130 ,
& V_140 , V_132 ) ;
if ( V_100 )
goto V_144;
V_143 = * V_132 ;
V_128 += F_113 ( V_130 -> V_145 ) - 1 ;
V_100 = F_121 ( V_2 , V_128 , & V_130 ,
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
int F_125 ( struct V_1 * V_2 )
{
struct V_129 * V_130 ;
struct V_147 * V_148 = V_2 -> V_149 ;
struct V_8 * V_150 , * V_151 , * V_152 ;
unsigned long V_133 = V_2 -> V_134 ;
unsigned long long V_153 = 0 , V_154 = 0 ;
unsigned long long V_155 ;
unsigned int V_156 = 1 + F_110 ( V_2 ) ;
T_2 V_157 ;
int V_70 ;
V_2 -> V_158 = F_126 ( V_156 * V_133 , V_159 ) ;
if ( ! V_2 -> V_158 )
return - V_160 ;
V_155 = F_113 ( V_148 -> V_161 ) ;
V_150 = F_124 ( V_2 , V_155 , & V_153 ) ;
V_155 += ( ( unsigned long long ) 1 ) <<
F_113 ( V_148 -> V_162 ) ;
V_151 = F_124 ( V_2 , V_155 , & V_154 ) ;
if ( V_150 && V_151 ) {
if ( F_127 ( V_154 , V_153 ) )
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
V_130 = (struct V_129 * ) F_112 ( V_152 ) ;
memcpy ( V_2 -> V_158 , V_130 , V_133 ) ;
if ( F_128 ( V_2 ) )
goto V_164;
if ( V_152 == V_150 )
V_2 -> V_165 = 1 ;
else
V_2 -> V_165 = 2 ;
if ( V_156 <= 1 )
goto V_166;
V_157 = F_113 ( V_148 -> V_161 ) ;
if ( V_152 == V_151 )
V_157 += 1 << F_113 ( V_148 -> V_162 ) ;
for ( V_70 = 1 ; V_70 < V_156 ; V_70 ++ ) {
void * V_167 ;
unsigned char * V_158 = ( unsigned char * ) V_2 -> V_158 ;
V_152 = F_16 ( V_2 , V_157 + V_70 ) ;
V_167 = F_112 ( V_152 ) ;
memcpy ( V_158 + V_70 * V_133 , V_167 , V_133 ) ;
F_14 ( V_152 , 1 ) ;
}
V_166:
F_14 ( V_150 , 1 ) ;
F_14 ( V_151 , 1 ) ;
return 0 ;
V_164:
F_14 ( V_150 , 1 ) ;
F_14 ( V_151 , 1 ) ;
V_163:
F_129 ( V_2 -> V_158 ) ;
return - V_138 ;
}
static void F_130 ( struct V_104 * V_104 , enum V_168 type )
{
struct V_1 * V_2 = F_96 ( V_104 ) ;
int V_169 = ( type == V_170 ) ? V_171 : V_172 ;
if ( F_131 ( V_104 , V_169 ) )
return;
F_132 ( V_104 , V_169 ) ;
F_80 ( & F_133 ( V_104 ) -> V_173 , & V_2 -> V_174 [ type ] ) ;
F_134 ( V_2 , type ) ;
}
static void F_135 ( struct V_104 * V_104 , enum V_168 type )
{
int V_169 = ( type == V_170 ) ? V_171 : V_172 ;
if ( F_136 ( V_104 ) || ! F_131 ( V_104 , V_169 ) )
return;
F_137 ( & F_133 ( V_104 ) -> V_173 ) ;
F_138 ( V_104 , V_169 ) ;
F_139 ( F_96 ( V_104 ) , type ) ;
}
void F_140 ( struct V_104 * V_104 , struct V_8 * V_8 )
{
struct V_1 * V_2 = F_96 ( V_104 ) ;
enum V_168 type = F_141 ( V_104 -> V_175 ) ? V_170 : V_176 ;
if ( ! F_141 ( V_104 -> V_175 ) && ! F_142 ( V_104 -> V_175 ) &&
! F_143 ( V_104 -> V_175 ) )
return;
F_75 ( & V_2 -> V_177 [ type ] ) ;
if ( type != V_176 || F_144 ( V_2 , V_178 ) )
F_130 ( V_104 , type ) ;
F_145 ( V_104 ) ;
F_78 ( & V_2 -> V_177 [ type ] ) ;
F_70 ( V_8 ) ;
F_71 ( V_8 ) ;
}
void F_146 ( struct V_104 * V_104 )
{
struct V_1 * V_2 = F_96 ( V_104 ) ;
enum V_168 type = F_141 ( V_104 -> V_175 ) ? V_170 : V_176 ;
if ( ! F_141 ( V_104 -> V_175 ) && ! F_142 ( V_104 -> V_175 ) &&
! F_143 ( V_104 -> V_175 ) )
return;
if ( type == V_176 && ! F_144 ( V_2 , V_178 ) )
return;
F_75 ( & V_2 -> V_177 [ type ] ) ;
F_135 ( V_104 , type ) ;
F_78 ( & V_2 -> V_177 [ type ] ) ;
}
int F_147 ( struct V_1 * V_2 , enum V_168 type )
{
struct V_122 * V_123 ;
struct V_104 * V_104 ;
struct V_179 * V_180 ;
bool V_181 = ( type == V_170 ) ;
F_148 ( V_2 -> V_5 , V_181 ,
F_50 ( V_2 , V_181 ?
V_182 : V_183 ) ) ;
V_88:
if ( F_12 ( F_42 ( V_2 ) ) )
return - V_114 ;
F_75 ( & V_2 -> V_177 [ type ] ) ;
V_123 = & V_2 -> V_174 [ type ] ;
if ( F_149 ( V_123 ) ) {
F_78 ( & V_2 -> V_177 [ type ] ) ;
F_150 ( V_2 -> V_5 , V_181 ,
F_50 ( V_2 , V_181 ?
V_182 : V_183 ) ) ;
return 0 ;
}
V_180 = F_151 ( V_123 -> V_184 , struct V_179 , V_173 ) ;
V_104 = F_152 ( & V_180 -> V_185 ) ;
F_78 ( & V_2 -> V_177 [ type ] ) ;
if ( V_104 ) {
F_153 ( V_104 -> V_186 ) ;
F_106 ( V_104 ) ;
} else {
F_33 ( V_2 , V_187 , V_53 ) ;
F_7 () ;
}
goto V_88;
}
int F_154 ( struct V_1 * V_2 )
{
struct V_122 * V_123 = & V_2 -> V_174 [ V_188 ] ;
struct V_104 * V_104 ;
struct V_179 * V_180 ;
T_6 V_189 = F_50 ( V_2 , V_190 ) ;
while ( V_189 -- ) {
if ( F_12 ( F_42 ( V_2 ) ) )
return - V_114 ;
F_75 ( & V_2 -> V_177 [ V_188 ] ) ;
if ( F_149 ( V_123 ) ) {
F_78 ( & V_2 -> V_177 [ V_188 ] ) ;
return 0 ;
}
V_180 = F_151 ( V_123 -> V_184 , struct V_179 ,
V_191 ) ;
V_104 = F_152 ( & V_180 -> V_185 ) ;
F_78 ( & V_2 -> V_177 [ V_188 ] ) ;
if ( V_104 ) {
F_155 ( V_104 , 0 ) ;
if ( F_131 ( V_104 , V_192 ) )
F_97 ( V_104 ) ;
F_106 ( V_104 ) ;
}
} ;
return 0 ;
}
static int F_156 ( struct V_1 * V_2 )
{
struct V_47 V_48 = {
. V_193 = V_194 ,
. V_61 = V_75 ,
. V_51 = 0 ,
} ;
struct V_39 V_40 ;
int V_100 = 0 ;
F_27 ( & V_40 ) ;
V_195:
F_157 ( V_2 ) ;
if ( F_50 ( V_2 , V_182 ) ) {
F_158 ( V_2 ) ;
V_100 = F_147 ( V_2 , V_170 ) ;
if ( V_100 )
goto V_25;
goto V_195;
}
if ( F_50 ( V_2 , V_190 ) ) {
F_158 ( V_2 ) ;
V_100 = F_154 ( V_2 ) ;
if ( V_100 )
goto V_25;
goto V_195;
}
V_196:
F_159 ( & V_2 -> V_197 ) ;
if ( F_50 ( V_2 , V_198 ) ) {
F_160 ( & V_2 -> V_197 ) ;
V_100 = F_161 ( V_2 , & V_48 ) ;
if ( V_100 ) {
F_158 ( V_2 ) ;
goto V_25;
}
goto V_196;
}
V_25:
F_34 ( & V_40 ) ;
return V_100 ;
}
static void F_162 ( struct V_1 * V_2 )
{
F_160 ( & V_2 -> V_197 ) ;
F_163 ( V_2 , false ) ;
F_158 ( V_2 ) ;
}
static void F_164 ( struct V_1 * V_2 )
{
F_165 ( V_199 ) ;
for (; ; ) {
F_166 ( & V_2 -> V_200 , & V_199 , V_201 ) ;
if ( ! F_50 ( V_2 , V_202 ) )
break;
F_167 ( 5 * V_203 ) ;
}
F_168 ( & V_2 -> V_200 , & V_199 ) ;
}
static void F_169 ( struct V_1 * V_2 , struct V_204 * V_205 )
{
unsigned long V_206 = V_2 -> V_82 [ V_94 ] . V_95 ;
struct V_129 * V_158 = F_170 ( V_2 ) ;
F_75 ( & V_2 -> V_207 ) ;
if ( V_205 -> V_208 == V_209 )
F_171 ( V_158 , V_210 ) ;
else
F_172 ( V_158 , V_210 ) ;
if ( V_205 -> V_208 == V_211 )
F_171 ( V_158 , V_212 ) ;
else
F_172 ( V_158 , V_212 ) ;
if ( V_206 )
F_171 ( V_158 , V_118 ) ;
else
F_172 ( V_158 , V_118 ) ;
if ( F_40 ( V_2 , V_108 ) )
F_171 ( V_158 , V_213 ) ;
F_171 ( V_158 , V_214 ) ;
F_78 ( & V_2 -> V_207 ) ;
}
static int F_173 ( struct V_1 * V_2 , struct V_204 * V_205 )
{
struct V_129 * V_158 = F_170 ( V_2 ) ;
struct V_215 * V_216 = F_29 ( V_2 ) ;
unsigned long V_206 = V_2 -> V_82 [ V_94 ] . V_95 ;
T_3 V_217 = V_216 -> V_218 ;
T_2 V_115 ;
unsigned int V_219 , V_116 ;
T_5 V_220 = 0 ;
int V_70 ;
int V_221 = F_110 ( V_2 ) ;
struct V_222 * V_5 = V_2 -> V_5 ;
struct V_223 * V_224 = F_174 ( V_2 , V_225 ) ;
T_7 V_226 ;
while ( F_50 ( V_2 , V_52 ) ) {
F_55 ( V_2 , V_13 , V_75 ) ;
if ( F_12 ( F_42 ( V_2 ) ) )
return - V_114 ;
}
F_175 ( V_2 , & V_217 ) ;
V_158 -> V_227 = F_176 ( F_177 ( V_2 ) ) ;
V_158 -> V_228 = F_176 ( F_178 ( V_2 ) ) ;
V_158 -> V_229 = F_118 ( F_179 ( V_2 ) ) ;
for ( V_70 = 0 ; V_70 < V_230 ; V_70 ++ ) {
V_158 -> V_231 [ V_70 ] =
F_118 ( F_180 ( V_2 , V_70 + V_225 ) ) ;
V_158 -> V_232 [ V_70 ] =
F_119 ( F_181 ( V_2 , V_70 + V_225 ) ) ;
V_158 -> V_233 [ V_70 + V_225 ] =
F_182 ( V_2 , V_70 + V_225 ) ;
}
for ( V_70 = 0 ; V_70 < V_234 ; V_70 ++ ) {
V_158 -> V_235 [ V_70 ] =
F_118 ( F_180 ( V_2 , V_70 + V_236 ) ) ;
V_158 -> V_237 [ V_70 ] =
F_119 ( F_181 ( V_2 , V_70 + V_236 ) ) ;
V_158 -> V_233 [ V_70 + V_236 ] =
F_182 ( V_2 , V_70 + V_236 ) ;
}
V_158 -> V_238 = F_118 ( V_238 ( V_2 ) ) ;
V_158 -> V_239 = F_118 ( V_239 ( V_2 ) ) ;
V_158 -> F_175 = F_118 ( V_217 ) ;
V_219 = F_183 ( V_2 , false ) ;
F_75 ( & V_2 -> V_207 ) ;
if ( V_219 < V_234 )
F_171 ( V_158 , V_240 ) ;
else
F_172 ( V_158 , V_240 ) ;
F_78 ( & V_2 -> V_207 ) ;
V_116 = F_116 ( V_206 ) ;
V_158 -> V_241 = F_118 ( 1 + V_221 +
V_116 ) ;
if ( F_184 ( V_205 -> V_208 ) )
V_158 -> V_145 = F_118 ( V_242 +
V_221 + V_219 +
V_116 + V_230 ) ;
else
V_158 -> V_145 = F_118 ( V_242 +
V_221 + V_219 +
V_116 ) ;
F_169 ( V_2 , V_205 ) ;
F_185 ( V_2 , F_186 ( V_2 , V_243 ) ) ;
F_187 ( V_2 , F_186 ( V_2 , V_244 ) ) ;
V_220 = F_188 ( V_2 , V_158 , F_113 ( V_158 -> V_137 ) ) ;
* ( ( V_139 * ) ( ( unsigned char * ) V_158 +
F_113 ( V_158 -> V_137 ) ) )
= F_118 ( V_220 ) ;
V_115 = F_189 ( V_2 ) ;
F_164 ( V_2 ) ;
if ( F_12 ( F_42 ( V_2 ) ) )
return - V_114 ;
F_190 ( V_2 , V_158 , V_115 ++ ) ;
for ( V_70 = 1 ; V_70 < 1 + V_221 ; V_70 ++ )
F_190 ( V_2 , ( char * ) V_158 + V_70 * V_245 ,
V_115 ++ ) ;
if ( V_206 ) {
F_115 ( V_2 , V_115 ) ;
V_115 += V_116 ;
}
F_191 ( V_2 , V_115 ) ;
V_115 += V_219 ;
V_226 = V_2 -> V_226 ;
if ( V_5 -> V_246 -> V_247 )
V_226 += F_192 ( V_2 ) ;
V_224 -> V_248 -> V_249 . V_226 = F_176 ( V_226 ) ;
if ( F_184 ( V_205 -> V_208 ) ) {
F_193 ( V_2 , V_115 ) ;
V_115 += V_230 ;
}
F_190 ( V_2 , V_158 , V_115 ) ;
F_164 ( V_2 ) ;
if ( F_12 ( F_42 ( V_2 ) ) )
return - V_114 ;
F_194 ( F_195 ( V_2 ) , 0 , V_250 ) ;
F_194 ( F_5 ( V_2 ) , 0 , V_250 ) ;
V_2 -> V_251 = V_2 -> V_252 ;
F_196 ( & V_2 -> V_253 , 0 ) ;
F_55 ( V_2 , V_254 , V_75 ) ;
F_164 ( V_2 ) ;
F_88 ( V_2 , false ) ;
if ( F_12 ( F_42 ( V_2 ) ) )
return - V_114 ;
F_197 ( V_2 , V_255 ) ;
F_197 ( V_2 , V_256 ) ;
F_198 ( V_2 ) ;
if ( F_50 ( V_2 , V_198 ) ||
F_50 ( V_2 , V_190 ) )
F_100 ( V_2 , V_255 ) ;
F_94 ( V_2 , F_50 ( V_2 , V_182 ) ) ;
return 0 ;
}
int F_199 ( struct V_1 * V_2 , struct V_204 * V_205 )
{
struct V_129 * V_158 = F_170 ( V_2 ) ;
unsigned long long V_257 ;
int V_100 = 0 ;
F_53 ( & V_2 -> V_60 ) ;
if ( ! F_40 ( V_2 , V_255 ) &&
( V_205 -> V_208 == V_211 || V_205 -> V_208 == V_258 ||
( V_205 -> V_208 == V_259 && ! V_2 -> V_260 ) ) )
goto V_25;
if ( F_12 ( F_42 ( V_2 ) ) ) {
V_100 = - V_114 ;
goto V_25;
}
if ( F_200 ( V_2 -> V_5 ) ) {
V_100 = - V_261 ;
goto V_25;
}
F_201 ( V_2 -> V_5 , V_205 -> V_208 , L_4 ) ;
V_100 = F_156 ( V_2 ) ;
if ( V_100 )
goto V_25;
F_201 ( V_2 -> V_5 , V_205 -> V_208 , L_5 ) ;
F_3 ( V_2 ) ;
if ( V_205 -> V_208 == V_259 && ! F_40 ( V_2 , V_255 ) ) {
F_94 ( V_2 , F_29 ( V_2 ) -> V_262 ) ;
F_94 ( V_2 , F_22 ( V_2 ) -> V_263 ) ;
F_94 ( V_2 , F_202 ( V_2 ) ) ;
F_203 ( V_2 , V_205 ) ;
F_204 ( V_2 , V_205 ) ;
F_205 ( V_2 ) ;
F_162 ( V_2 ) ;
goto V_25;
}
V_257 = F_123 ( V_158 ) ;
V_158 -> V_264 = F_176 ( ++ V_257 ) ;
F_206 ( V_2 ) ;
F_203 ( V_2 , V_205 ) ;
V_100 = F_173 ( V_2 , V_205 ) ;
if ( V_100 ) {
F_207 ( V_2 ) ;
} else {
F_204 ( V_2 , V_205 ) ;
F_205 ( V_2 ) ;
}
F_162 ( V_2 ) ;
F_208 ( V_2 -> V_265 ) ;
if ( V_205 -> V_208 == V_266 )
F_101 ( V_2 -> V_5 , V_267 ,
L_6 , V_257 ) ;
F_209 ( V_2 , V_268 ) ;
F_201 ( V_2 -> V_5 , V_205 -> V_208 , L_7 ) ;
V_25:
F_56 ( & V_2 -> V_60 ) ;
return V_100 ;
}
void F_210 ( struct V_1 * V_2 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_269 ; V_70 ++ ) {
struct V_81 * V_82 = & V_2 -> V_82 [ V_70 ] ;
F_211 ( & V_82 -> V_91 , V_270 ) ;
F_212 ( & V_82 -> V_90 ) ;
F_213 ( & V_82 -> V_93 ) ;
V_82 -> V_95 = 0 ;
}
V_2 -> V_103 = ( V_2 -> V_271 - V_242 -
V_272 - F_110 ( V_2 ) ) *
V_126 ;
}
int T_8 F_214 ( void )
{
V_86 = F_215 ( L_8 ,
sizeof( struct V_83 ) ) ;
if ( ! V_86 )
return - V_160 ;
V_273 = F_215 ( L_9 ,
sizeof( struct V_274 ) ) ;
if ( ! V_273 ) {
F_216 ( V_86 ) ;
return - V_160 ;
}
return 0 ;
}
void F_217 ( void )
{
F_216 ( V_86 ) ;
F_216 ( V_273 ) ;
}
