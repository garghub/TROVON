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
F_9 ( V_9 ) ;
return V_9 ;
}
static struct V_9 * F_10 ( struct V_1 * V_2 , T_1 V_10 ,
bool V_15 )
{
struct V_11 * V_12 = F_5 ( V_2 ) ;
struct V_9 * V_9 ;
struct V_16 V_17 = {
. V_2 = V_2 ,
. type = V_14 ,
. V_18 = V_19 | V_20 | V_21 ,
. V_22 = V_10 ,
. V_23 = V_10 ,
. V_24 = NULL ,
} ;
if ( F_11 ( ! V_15 ) )
V_17 . V_18 &= ~ V_20 ;
V_13:
V_9 = F_6 ( V_12 , V_10 , false ) ;
if ( ! V_9 ) {
F_7 () ;
goto V_13;
}
if ( F_12 ( V_9 ) )
goto V_25;
V_17 . V_9 = V_9 ;
if ( F_13 ( & V_17 ) ) {
F_14 ( V_9 , 1 ) ;
goto V_13;
}
F_15 ( V_9 ) ;
if ( F_11 ( V_9 -> V_12 != V_12 ) ) {
F_14 ( V_9 , 1 ) ;
goto V_13;
}
if ( F_11 ( ! F_12 ( V_9 ) ) )
F_1 ( V_2 , false ) ;
V_25:
return V_9 ;
}
struct V_9 * F_16 ( struct V_1 * V_2 , T_1 V_10 )
{
return F_10 ( V_2 , V_10 , true ) ;
}
struct V_9 * F_17 ( struct V_1 * V_2 , T_1 V_10 )
{
return F_10 ( V_2 , V_10 , false ) ;
}
bool F_18 ( struct V_1 * V_2 , T_2 V_26 , int type )
{
switch ( type ) {
case V_27 :
break;
case V_28 :
if ( F_11 ( V_26 >= F_19 ( V_2 ) ) )
return false ;
break;
case V_29 :
if ( F_11 ( V_26 >= F_20 ( V_2 ) ||
V_26 < F_21 ( V_2 ) -> V_30 ) )
return false ;
break;
case V_31 :
if ( F_11 ( V_26 >= F_22 ( V_2 ) -> V_32 ||
V_26 < F_23 ( V_2 ) ) )
return false ;
break;
case V_33 :
if ( F_11 ( V_26 >= F_24 ( V_2 ) ||
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
struct V_9 * V_9 ;
T_2 V_37 = V_34 ;
struct V_16 V_17 = {
. V_2 = V_2 ,
. type = V_14 ,
. V_18 = V_36 ? ( V_19 | V_20 | V_21 ) : V_38 ,
. V_24 = NULL ,
} ;
struct V_39 V_40 ;
if ( F_11 ( type == V_33 ) )
V_17 . V_18 &= ~ V_20 ;
F_27 ( & V_40 ) ;
for (; V_35 -- > 0 ; V_37 ++ ) {
if ( ! F_18 ( V_2 , V_37 , type ) )
goto V_25;
switch ( type ) {
case V_27 :
if ( F_11 ( V_37 >=
F_28 ( F_29 ( V_2 ) -> V_41 ) ) )
V_37 = 0 ;
V_17 . V_23 = F_30 ( V_2 ,
V_37 * V_42 ) ;
break;
case V_28 :
V_17 . V_23 = F_31 ( V_2 ,
V_37 * V_43 ) ;
break;
case V_29 :
case V_31 :
case V_33 :
V_17 . V_23 = V_37 ;
break;
default:
F_25 () ;
}
V_9 = F_6 ( F_5 ( V_2 ) ,
V_17 . V_23 , false ) ;
if ( ! V_9 )
continue;
if ( F_12 ( V_9 ) ) {
F_14 ( V_9 , 1 ) ;
continue;
}
V_17 . V_9 = V_9 ;
V_17 . V_22 = V_17 . V_23 ;
F_32 ( & V_17 ) ;
F_14 ( V_9 , 0 ) ;
}
V_25:
F_33 ( V_2 , V_14 , V_44 ) ;
F_34 ( & V_40 ) ;
return V_37 - V_34 ;
}
void F_35 ( struct V_1 * V_2 , T_1 V_10 )
{
struct V_9 * V_9 ;
bool V_45 = false ;
V_9 = F_36 ( F_5 ( V_2 ) , V_10 ) ;
if ( ! V_9 || ! F_12 ( V_9 ) )
V_45 = true ;
F_14 ( V_9 , 0 ) ;
if ( V_45 )
F_26 ( V_2 , V_10 , F_37 ( V_2 ) , V_33 , true ) ;
}
static int F_38 ( struct V_9 * V_9 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_39 ( V_9 ) ;
F_40 ( V_9 , V_14 ) ;
if ( F_11 ( F_41 ( V_2 , V_48 ) ) )
goto V_49;
if ( V_47 -> V_50 && V_9 -> V_10 < F_42 ( V_2 , 0 ) )
goto V_49;
if ( F_11 ( F_43 ( V_2 ) ) )
goto V_49;
F_44 ( V_2 , V_9 ) ;
F_45 ( V_2 , V_51 ) ;
if ( V_47 -> V_50 )
F_46 ( V_2 , NULL , V_9 , 0 , V_14 , V_52 ) ;
F_47 ( V_9 ) ;
if ( F_11 ( F_43 ( V_2 ) ) )
F_33 ( V_2 , V_14 , V_52 ) ;
return 0 ;
V_49:
F_48 ( V_47 , V_9 ) ;
return V_53 ;
}
static int F_49 ( struct V_11 * V_12 ,
struct V_46 * V_47 )
{
struct V_1 * V_2 = F_50 ( V_12 ) ;
long V_54 , V_55 ;
if ( V_47 -> V_56 ||
F_51 ( V_2 , V_51 ) < F_52 ( V_2 , V_14 ) )
goto V_57;
F_53 ( V_12 -> V_58 , V_47 , V_14 ) ;
F_54 ( & V_2 -> V_59 ) ;
V_54 = F_55 ( V_2 , V_14 , V_47 ) ;
V_55 = F_56 ( V_2 , V_14 , V_47 -> V_60 ) ;
F_57 ( & V_2 -> V_59 ) ;
V_47 -> V_60 = F_58 ( ( long ) 0 , V_47 -> V_60 - V_55 - V_54 ) ;
return 0 ;
V_57:
V_47 -> V_61 += F_51 ( V_2 , V_51 ) ;
F_53 ( V_12 -> V_58 , V_47 , V_14 ) ;
return 0 ;
}
long F_56 ( struct V_1 * V_2 , enum V_62 type ,
long V_60 )
{
struct V_11 * V_12 = F_5 ( V_2 ) ;
T_1 V_10 = 0 , V_63 = V_64 , V_65 = V_64 ;
struct V_66 V_67 ;
long V_68 = 0 ;
struct V_46 V_47 = {
. V_50 = 0 ,
} ;
struct V_39 V_40 ;
F_59 ( & V_67 , 0 ) ;
F_27 ( & V_40 ) ;
while ( V_10 <= V_63 ) {
int V_69 , V_70 ;
V_70 = F_60 ( & V_67 , V_12 , & V_10 ,
V_71 ,
F_61 ( V_63 - V_10 , ( T_1 ) V_72 - 1 ) + 1 ) ;
if ( F_11 ( V_70 == 0 ) )
break;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
struct V_9 * V_9 = V_67 . V_73 [ V_69 ] ;
if ( V_65 == V_64 )
V_65 = V_9 -> V_10 - 1 ;
if ( V_60 != V_74 && V_9 -> V_10 != V_65 + 1 ) {
F_62 ( & V_67 ) ;
goto V_75;
}
F_15 ( V_9 ) ;
if ( F_11 ( V_9 -> V_12 != V_12 ) ) {
V_76:
F_47 ( V_9 ) ;
continue;
}
if ( ! F_63 ( V_9 ) ) {
goto V_76;
}
F_8 ( V_9 , V_14 , true ) ;
F_64 ( F_65 ( V_9 ) ) ;
if ( ! F_66 ( V_9 ) )
goto V_76;
if ( V_12 -> V_77 -> V_78 ( V_9 , & V_47 ) ) {
F_47 ( V_9 ) ;
break;
}
V_68 ++ ;
V_65 = V_9 -> V_10 ;
if ( F_11 ( V_68 >= V_60 ) )
break;
}
F_62 ( & V_67 ) ;
F_7 () ;
}
V_75:
if ( V_68 )
F_33 ( V_2 , type , V_52 ) ;
F_34 ( & V_40 ) ;
return V_68 ;
}
static int F_67 ( struct V_9 * V_9 )
{
F_68 ( V_9 , V_14 ) ;
F_9 ( V_9 ) ;
if ( ! F_63 ( V_9 ) ) {
F_69 ( V_9 ) ;
F_70 ( F_39 ( V_9 ) , V_51 ) ;
F_71 ( V_9 ) ;
F_72 ( V_9 ) ;
return 1 ;
}
return 0 ;
}
static void F_73 ( struct V_1 * V_2 , T_3 V_79 , int type )
{
struct V_80 * V_81 = & V_2 -> V_81 [ type ] ;
struct V_82 * V_83 , * V_84 ;
V_84 = F_74 ( V_85 , V_86 ) ;
V_87:
F_75 ( V_86 | V_88 ) ;
F_76 ( & V_81 -> V_89 ) ;
V_83 = F_77 ( & V_81 -> V_90 , V_79 ) ;
if ( ! V_83 ) {
V_83 = V_84 ;
if ( F_78 ( & V_81 -> V_90 , V_79 , V_83 ) ) {
F_79 ( & V_81 -> V_89 ) ;
F_80 () ;
goto V_87;
}
memset ( V_83 , 0 , sizeof( struct V_82 ) ) ;
V_83 -> V_79 = V_79 ;
F_81 ( & V_83 -> V_91 , & V_81 -> V_92 ) ;
if ( type != V_93 )
V_81 -> V_94 ++ ;
}
F_79 ( & V_81 -> V_89 ) ;
F_80 () ;
if ( V_83 != V_84 )
F_82 ( V_85 , V_84 ) ;
}
static void F_83 ( struct V_1 * V_2 , T_3 V_79 , int type )
{
struct V_80 * V_81 = & V_2 -> V_81 [ type ] ;
struct V_82 * V_83 ;
F_76 ( & V_81 -> V_89 ) ;
V_83 = F_77 ( & V_81 -> V_90 , V_79 ) ;
if ( V_83 ) {
F_84 ( & V_83 -> V_91 ) ;
F_85 ( & V_81 -> V_90 , V_79 ) ;
V_81 -> V_94 -- ;
F_79 ( & V_81 -> V_89 ) ;
F_82 ( V_85 , V_83 ) ;
return;
}
F_79 ( & V_81 -> V_89 ) ;
}
void F_86 ( struct V_1 * V_2 , T_3 V_79 , int type )
{
F_73 ( V_2 , V_79 , type ) ;
}
void F_87 ( struct V_1 * V_2 , T_3 V_79 , int type )
{
F_83 ( V_2 , V_79 , type ) ;
}
bool F_88 ( struct V_1 * V_2 , T_3 V_79 , int V_95 )
{
struct V_80 * V_81 = & V_2 -> V_81 [ V_95 ] ;
struct V_82 * V_83 ;
F_76 ( & V_81 -> V_89 ) ;
V_83 = F_77 ( & V_81 -> V_90 , V_79 ) ;
F_79 ( & V_81 -> V_89 ) ;
return V_83 ? true : false ;
}
void F_89 ( struct V_1 * V_2 , bool V_96 )
{
struct V_82 * V_83 , * V_84 ;
int V_69 ;
for ( V_69 = V_96 ? V_93 : V_97 ; V_69 <= V_98 ; V_69 ++ ) {
struct V_80 * V_81 = & V_2 -> V_81 [ V_69 ] ;
F_76 ( & V_81 -> V_89 ) ;
F_90 (e, tmp, &im->ino_list, list) {
F_84 ( & V_83 -> V_91 ) ;
F_85 ( & V_81 -> V_90 , V_83 -> V_79 ) ;
F_82 ( V_85 , V_83 ) ;
V_81 -> V_94 -- ;
}
F_79 ( & V_81 -> V_89 ) ;
}
}
int F_91 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = & V_2 -> V_81 [ V_93 ] ;
int V_99 = 0 ;
F_76 ( & V_81 -> V_89 ) ;
#ifdef F_92
if ( F_93 ( V_100 ) ) {
F_79 ( & V_81 -> V_89 ) ;
return - V_101 ;
}
#endif
if ( F_11 ( V_81 -> V_94 >= V_2 -> V_102 ) )
V_99 = - V_101 ;
else
V_81 -> V_94 ++ ;
F_79 ( & V_81 -> V_89 ) ;
return V_99 ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = & V_2 -> V_81 [ V_93 ] ;
F_76 ( & V_81 -> V_89 ) ;
F_95 ( V_2 , V_81 -> V_94 == 0 ) ;
V_81 -> V_94 -- ;
F_79 ( & V_81 -> V_89 ) ;
}
void F_96 ( struct V_1 * V_2 , T_3 V_79 )
{
F_73 ( V_2 , V_79 , V_93 ) ;
}
void F_97 ( struct V_1 * V_2 , T_3 V_79 )
{
F_83 ( V_2 , V_79 , V_93 ) ;
}
static int F_98 ( struct V_1 * V_2 , T_3 V_79 )
{
struct V_103 * V_103 ;
V_103 = F_99 ( V_2 -> V_6 , V_79 ) ;
if ( F_100 ( V_103 ) ) {
F_95 ( V_2 , F_101 ( V_103 ) == - V_104 ) ;
return F_101 ( V_103 ) ;
}
F_102 ( V_103 ) ;
F_103 ( V_103 ) ;
return 0 ;
}
int F_104 ( struct V_1 * V_2 )
{
T_2 V_105 , V_106 , V_69 , V_107 ;
int V_99 ;
if ( ! F_105 ( F_106 ( V_2 ) , V_108 ) )
return 0 ;
V_105 = F_23 ( V_2 ) + 1 + F_107 ( V_2 ) ;
V_106 = F_108 ( V_2 ) - 1 - F_107 ( V_2 ) ;
F_26 ( V_2 , V_105 , V_106 , V_31 , true ) ;
for ( V_69 = 0 ; V_69 < V_106 ; V_69 ++ ) {
struct V_9 * V_9 = F_16 ( V_2 , V_105 + V_69 ) ;
struct V_109 * V_110 ;
V_110 = (struct V_109 * ) F_109 ( V_9 ) ;
for ( V_107 = 0 ; V_107 < F_110 ( V_110 -> V_111 ) ; V_107 ++ ) {
T_3 V_79 = F_110 ( V_110 -> V_79 [ V_107 ] ) ;
V_99 = F_98 ( V_2 , V_79 ) ;
if ( V_99 ) {
F_14 ( V_9 , 1 ) ;
return V_99 ;
}
}
F_14 ( V_9 , 1 ) ;
}
F_111 ( F_106 ( V_2 ) , V_108 ) ;
return 0 ;
}
static void F_112 ( struct V_1 * V_2 , T_2 V_105 )
{
struct V_112 * V_113 ;
struct V_109 * V_110 = NULL ;
unsigned int V_114 = 0 ;
unsigned short V_10 = 1 ;
unsigned short V_106 ;
struct V_9 * V_9 = NULL ;
struct V_82 * V_115 = NULL ;
struct V_80 * V_81 = & V_2 -> V_81 [ V_93 ] ;
V_106 = F_113 ( V_81 -> V_94 ) ;
V_113 = & V_81 -> V_92 ;
F_114 (orphan, head, list) {
if ( ! V_9 ) {
V_9 = F_4 ( V_2 , V_105 ++ ) ;
V_110 =
(struct V_109 * ) F_109 ( V_9 ) ;
memset ( V_110 , 0 , sizeof( * V_110 ) ) ;
}
V_110 -> V_79 [ V_114 ++ ] = F_115 ( V_115 -> V_79 ) ;
if ( V_114 == V_116 ) {
V_110 -> V_117 = F_116 ( V_10 ) ;
V_110 -> V_118 = F_116 ( V_106 ) ;
V_110 -> V_111 = F_115 ( V_114 ) ;
F_117 ( V_9 ) ;
F_14 ( V_9 , 1 ) ;
V_10 ++ ;
V_114 = 0 ;
V_9 = NULL ;
}
}
if ( V_9 ) {
V_110 -> V_117 = F_116 ( V_10 ) ;
V_110 -> V_118 = F_116 ( V_106 ) ;
V_110 -> V_111 = F_115 ( V_114 ) ;
F_117 ( V_9 ) ;
F_14 ( V_9 , 1 ) ;
}
}
static struct V_9 * F_118 ( struct V_1 * V_2 ,
T_2 V_119 , unsigned long long * V_120 )
{
struct V_9 * V_121 , * V_122 = NULL ;
unsigned long V_123 = V_2 -> V_124 ;
struct V_125 * V_126 ;
unsigned long long V_127 = 0 , V_128 = 0 ;
T_4 V_129 ;
T_5 V_130 = 0 ;
V_121 = F_16 ( V_2 , V_119 ) ;
V_126 = (struct V_125 * ) F_109 ( V_121 ) ;
V_129 = F_110 ( V_126 -> V_131 ) ;
if ( V_129 >= V_123 )
goto V_132;
V_130 = F_110 ( * ( ( V_133 * ) ( ( unsigned char * ) V_126 + V_129 ) ) ) ;
if ( ! F_119 ( V_2 , V_130 , V_126 , V_129 ) )
goto V_132;
V_128 = F_120 ( V_126 ) ;
V_119 += F_110 ( V_126 -> V_134 ) - 1 ;
V_122 = F_16 ( V_2 , V_119 ) ;
V_126 = (struct V_125 * ) F_109 ( V_122 ) ;
V_129 = F_110 ( V_126 -> V_131 ) ;
if ( V_129 >= V_123 )
goto V_135;
V_130 = F_110 ( * ( ( V_133 * ) ( ( unsigned char * ) V_126 + V_129 ) ) ) ;
if ( ! F_119 ( V_2 , V_130 , V_126 , V_129 ) )
goto V_135;
V_127 = F_120 ( V_126 ) ;
if ( V_127 == V_128 ) {
* V_120 = V_127 ;
F_14 ( V_122 , 1 ) ;
return V_121 ;
}
V_135:
F_14 ( V_122 , 1 ) ;
V_132:
F_14 ( V_121 , 1 ) ;
return NULL ;
}
int F_121 ( struct V_1 * V_2 )
{
struct V_125 * V_126 ;
struct V_136 * V_137 = V_2 -> V_138 ;
struct V_9 * V_139 , * V_140 , * V_141 ;
unsigned long V_123 = V_2 -> V_124 ;
unsigned long long V_142 = 0 , V_143 = 0 ;
unsigned long long V_144 ;
unsigned int V_145 = 1 + F_107 ( V_2 ) ;
T_2 V_146 ;
int V_69 ;
V_2 -> V_4 = F_122 ( V_145 * V_123 , V_147 ) ;
if ( ! V_2 -> V_4 )
return - V_148 ;
V_144 = F_110 ( V_137 -> V_149 ) ;
V_139 = F_118 ( V_2 , V_144 , & V_142 ) ;
V_144 += ( ( unsigned long long ) 1 ) <<
F_110 ( V_137 -> V_150 ) ;
V_140 = F_118 ( V_2 , V_144 , & V_143 ) ;
if ( V_139 && V_140 ) {
if ( F_123 ( V_143 , V_142 ) )
V_141 = V_140 ;
else
V_141 = V_139 ;
} else if ( V_139 ) {
V_141 = V_139 ;
} else if ( V_140 ) {
V_141 = V_140 ;
} else {
goto V_151;
}
V_126 = (struct V_125 * ) F_109 ( V_141 ) ;
memcpy ( V_2 -> V_4 , V_126 , V_123 ) ;
if ( F_124 ( V_2 ) )
goto V_151;
if ( V_145 <= 1 )
goto V_152;
V_146 = F_110 ( V_137 -> V_149 ) ;
if ( V_141 == V_140 )
V_146 += 1 << F_110 ( V_137 -> V_150 ) ;
for ( V_69 = 1 ; V_69 < V_145 ; V_69 ++ ) {
void * V_153 ;
unsigned char * V_4 = ( unsigned char * ) V_2 -> V_4 ;
V_141 = F_16 ( V_2 , V_146 + V_69 ) ;
V_153 = F_109 ( V_141 ) ;
memcpy ( V_4 + V_69 * V_123 , V_153 , V_123 ) ;
F_14 ( V_141 , 1 ) ;
}
V_152:
F_14 ( V_139 , 1 ) ;
F_14 ( V_140 , 1 ) ;
return 0 ;
V_151:
F_125 ( V_2 -> V_4 ) ;
return - V_154 ;
}
static void F_126 ( struct V_103 * V_103 , enum V_155 type )
{
struct V_1 * V_2 = F_127 ( V_103 ) ;
struct V_156 * V_157 = F_128 ( V_103 ) ;
int V_158 = ( type == V_159 ) ? V_160 : V_161 ;
if ( F_129 ( V_157 , V_158 ) )
return;
F_130 ( V_157 , V_158 ) ;
F_81 ( & V_157 -> V_162 , & V_2 -> V_163 [ type ] ) ;
F_131 ( V_2 , type ) ;
}
static void F_132 ( struct V_103 * V_103 , enum V_155 type )
{
struct V_156 * V_157 = F_128 ( V_103 ) ;
int V_158 = ( type == V_159 ) ? V_160 : V_161 ;
if ( F_133 ( V_103 ) ||
! F_129 ( F_128 ( V_103 ) , V_158 ) )
return;
F_134 ( & V_157 -> V_162 ) ;
F_135 ( V_157 , V_158 ) ;
F_136 ( F_127 ( V_103 ) , type ) ;
}
void F_137 ( struct V_103 * V_103 , struct V_9 * V_9 )
{
struct V_1 * V_2 = F_127 ( V_103 ) ;
enum V_155 type = F_138 ( V_103 -> V_164 ) ? V_159 : V_165 ;
if ( ! F_138 ( V_103 -> V_164 ) && ! F_139 ( V_103 -> V_164 ) &&
! F_140 ( V_103 -> V_164 ) )
return;
if ( type != V_165 || F_141 ( V_2 , V_166 ) ) {
F_76 ( & V_2 -> V_167 [ type ] ) ;
F_126 ( V_103 , type ) ;
F_79 ( & V_2 -> V_167 [ type ] ) ;
}
F_142 ( V_103 ) ;
F_71 ( V_9 ) ;
F_72 ( V_9 ) ;
}
void F_143 ( struct V_103 * V_103 )
{
struct V_1 * V_2 = F_127 ( V_103 ) ;
enum V_155 type = F_138 ( V_103 -> V_164 ) ? V_159 : V_165 ;
if ( ! F_138 ( V_103 -> V_164 ) && ! F_139 ( V_103 -> V_164 ) &&
! F_140 ( V_103 -> V_164 ) )
return;
if ( type == V_165 && ! F_141 ( V_2 , V_166 ) )
return;
F_76 ( & V_2 -> V_167 [ type ] ) ;
F_132 ( V_103 , type ) ;
F_79 ( & V_2 -> V_167 [ type ] ) ;
}
int F_144 ( struct V_1 * V_2 , enum V_155 type )
{
struct V_112 * V_113 ;
struct V_103 * V_103 ;
struct V_156 * V_157 ;
bool V_168 = ( type == V_159 ) ;
F_145 ( V_2 -> V_6 , V_168 ,
F_51 ( V_2 , V_168 ?
V_169 : V_170 ) ) ;
V_87:
if ( F_11 ( F_43 ( V_2 ) ) )
return - V_171 ;
F_76 ( & V_2 -> V_167 [ type ] ) ;
V_113 = & V_2 -> V_163 [ type ] ;
if ( F_146 ( V_113 ) ) {
F_79 ( & V_2 -> V_167 [ type ] ) ;
F_147 ( V_2 -> V_6 , V_168 ,
F_51 ( V_2 , V_168 ?
V_169 : V_170 ) ) ;
return 0 ;
}
V_157 = F_148 ( V_113 -> V_172 , struct V_156 , V_162 ) ;
V_103 = F_149 ( & V_157 -> V_173 ) ;
F_79 ( & V_2 -> V_167 [ type ] ) ;
if ( V_103 ) {
F_150 ( V_103 -> V_174 ) ;
F_103 ( V_103 ) ;
} else {
F_33 ( V_2 , V_175 , V_52 ) ;
F_7 () ;
}
goto V_87;
}
static int F_151 ( struct V_1 * V_2 )
{
struct V_46 V_47 = {
. V_176 = V_177 ,
. V_60 = V_74 ,
. V_50 = 0 ,
} ;
struct V_39 V_40 ;
int V_99 = 0 ;
F_27 ( & V_40 ) ;
V_178:
F_152 ( V_2 ) ;
if ( F_51 ( V_2 , V_169 ) ) {
F_153 ( V_2 ) ;
V_99 = F_144 ( V_2 , V_159 ) ;
if ( V_99 )
goto V_25;
goto V_178;
}
V_179:
F_154 ( & V_2 -> V_180 ) ;
if ( F_51 ( V_2 , V_181 ) ) {
F_155 ( & V_2 -> V_180 ) ;
V_99 = F_156 ( V_2 , & V_47 ) ;
if ( V_99 ) {
F_153 ( V_2 ) ;
goto V_25;
}
goto V_179;
}
V_25:
F_34 ( & V_40 ) ;
return V_99 ;
}
static void F_157 ( struct V_1 * V_2 )
{
F_155 ( & V_2 -> V_180 ) ;
F_153 ( V_2 ) ;
}
static void F_158 ( struct V_1 * V_2 )
{
F_159 ( V_182 ) ;
for (; ; ) {
F_160 ( & V_2 -> V_183 , & V_182 , V_184 ) ;
if ( ! F_161 ( & V_2 -> V_185 ) )
break;
F_162 ( 5 * V_186 ) ;
}
F_163 ( & V_2 -> V_183 , & V_182 ) ;
}
static int F_164 ( struct V_1 * V_2 , struct V_187 * V_188 )
{
struct V_125 * V_4 = F_106 ( V_2 ) ;
struct V_189 * V_190 = F_165 ( V_2 , V_191 ) ;
struct V_192 * V_193 = F_29 ( V_2 ) ;
unsigned long V_194 = V_2 -> V_81 [ V_93 ] . V_94 ;
T_3 V_195 = V_193 -> V_196 ;
T_2 V_105 ;
unsigned int V_197 , V_106 ;
T_5 V_198 = 0 ;
int V_69 ;
int V_199 = F_107 ( V_2 ) ;
T_2 V_200 = F_166 ( V_2 , V_190 ) ;
bool V_201 = false ;
struct V_202 * V_6 = V_2 -> V_6 ;
struct V_189 * V_203 = F_165 ( V_2 , V_204 ) ;
T_6 V_205 ;
if ( F_167 ( V_2 , V_200 ) )
V_201 = true ;
while ( F_51 ( V_2 , V_51 ) ) {
F_56 ( V_2 , V_14 , V_74 ) ;
if ( F_11 ( F_43 ( V_2 ) ) )
return - V_171 ;
}
F_168 ( V_2 , & V_195 ) ;
V_4 -> V_206 = F_169 ( F_170 ( V_2 ) ) ;
V_4 -> V_207 = F_169 ( F_171 ( V_2 ) ) ;
V_4 -> V_208 = F_115 ( F_172 ( V_2 ) ) ;
for ( V_69 = 0 ; V_69 < V_209 ; V_69 ++ ) {
V_4 -> V_210 [ V_69 ] =
F_115 ( F_173 ( V_2 , V_69 + V_204 ) ) ;
V_4 -> V_211 [ V_69 ] =
F_116 ( F_174 ( V_2 , V_69 + V_204 ) ) ;
V_4 -> V_212 [ V_69 + V_204 ] =
F_175 ( V_2 , V_69 + V_204 ) ;
}
for ( V_69 = 0 ; V_69 < V_213 ; V_69 ++ ) {
V_4 -> V_214 [ V_69 ] =
F_115 ( F_173 ( V_2 , V_69 + V_215 ) ) ;
V_4 -> V_216 [ V_69 ] =
F_116 ( F_174 ( V_2 , V_69 + V_215 ) ) ;
V_4 -> V_212 [ V_69 + V_215 ] =
F_175 ( V_2 , V_69 + V_215 ) ;
}
V_4 -> V_217 = F_115 ( V_217 ( V_2 ) ) ;
V_4 -> V_218 = F_115 ( V_218 ( V_2 ) ) ;
V_4 -> F_168 = F_115 ( V_195 ) ;
V_197 = F_176 ( V_2 , false ) ;
if ( V_197 < V_213 )
F_2 ( V_4 , V_219 ) ;
else
F_111 ( V_4 , V_219 ) ;
V_106 = F_113 ( V_194 ) ;
V_4 -> V_220 = F_115 ( 1 + V_199 +
V_106 ) ;
if ( F_177 ( V_188 -> V_221 ) )
V_4 -> V_134 = F_115 ( V_222 +
V_199 + V_197 +
V_106 + V_209 ) ;
else
V_4 -> V_134 = F_115 ( V_222 +
V_199 + V_197 +
V_106 ) ;
if ( V_188 -> V_221 == V_223 )
F_2 ( V_4 , V_224 ) ;
else
F_111 ( V_4 , V_224 ) ;
if ( V_188 -> V_221 == V_225 )
F_2 ( V_4 , V_226 ) ;
else
F_111 ( V_4 , V_226 ) ;
if ( V_194 )
F_2 ( V_4 , V_108 ) ;
else
F_111 ( V_4 , V_108 ) ;
if ( F_41 ( V_2 , V_227 ) )
F_2 ( V_4 , V_228 ) ;
F_178 ( V_2 , F_179 ( V_2 , V_229 ) ) ;
F_180 ( V_2 , F_179 ( V_2 , V_230 ) ) ;
V_198 = F_181 ( V_2 , V_4 , F_110 ( V_4 -> V_131 ) ) ;
* ( ( V_133 * ) ( ( unsigned char * ) V_4 +
F_110 ( V_4 -> V_131 ) ) )
= F_115 ( V_198 ) ;
V_105 = F_23 ( V_2 ) ;
F_158 ( V_2 ) ;
if ( F_11 ( F_43 ( V_2 ) ) )
return - V_171 ;
F_182 ( V_2 , V_4 , V_105 ++ ) ;
for ( V_69 = 1 ; V_69 < 1 + V_199 ; V_69 ++ )
F_182 ( V_2 , ( char * ) V_4 + V_69 * V_231 ,
V_105 ++ ) ;
if ( V_194 ) {
F_112 ( V_2 , V_105 ) ;
V_105 += V_106 ;
}
F_183 ( V_2 , V_105 ) ;
V_105 += V_197 ;
V_205 = V_2 -> V_205 ;
if ( V_6 -> V_232 -> V_233 )
V_205 += F_184 ( V_2 ) ;
V_203 -> V_234 -> V_235 . V_205 = F_169 ( V_205 ) ;
if ( F_177 ( V_188 -> V_221 ) ) {
F_185 ( V_2 , V_105 ) ;
V_105 += V_209 ;
}
F_182 ( V_2 , V_4 , V_105 ) ;
F_158 ( V_2 ) ;
if ( F_11 ( F_43 ( V_2 ) ) )
return - V_171 ;
F_186 ( F_187 ( V_2 ) , 0 , V_236 ) ;
F_186 ( F_5 ( V_2 ) , 0 , V_236 ) ;
V_2 -> V_237 = V_2 -> V_238 ;
F_188 ( & V_2 -> V_239 , 0 ) ;
F_56 ( V_2 , V_240 , V_74 ) ;
F_158 ( V_2 ) ;
if ( V_201 )
F_189 ( F_5 ( V_2 ) , V_200 ,
V_200 ) ;
F_89 ( V_2 , false ) ;
if ( F_11 ( F_43 ( V_2 ) ) )
return - V_171 ;
F_190 ( V_2 , V_188 ) ;
F_191 ( V_2 , V_241 ) ;
return 0 ;
}
int F_192 ( struct V_1 * V_2 , struct V_187 * V_188 )
{
struct V_125 * V_4 = F_106 ( V_2 ) ;
unsigned long long V_242 ;
int V_99 = 0 ;
F_54 ( & V_2 -> V_59 ) ;
if ( ! F_41 ( V_2 , V_241 ) &&
( V_188 -> V_221 == V_225 || V_188 -> V_221 == V_243 ||
( V_188 -> V_221 == V_244 && ! V_2 -> V_245 ) ) )
goto V_25;
if ( F_11 ( F_43 ( V_2 ) ) ) {
V_99 = - V_171 ;
goto V_25;
}
if ( F_193 ( V_2 -> V_6 ) ) {
V_99 = - V_246 ;
goto V_25;
}
F_194 ( V_2 -> V_6 , V_188 -> V_221 , L_1 ) ;
V_99 = F_151 ( V_2 ) ;
if ( V_99 )
goto V_25;
F_194 ( V_2 -> V_6 , V_188 -> V_221 , L_2 ) ;
F_3 ( V_2 ) ;
V_242 = F_120 ( V_4 ) ;
V_4 -> V_247 = F_169 ( ++ V_242 ) ;
F_195 ( V_2 ) ;
F_196 ( V_2 , V_188 ) ;
V_99 = F_164 ( V_2 , V_188 ) ;
F_157 ( V_2 ) ;
F_197 ( V_2 -> V_248 ) ;
if ( V_188 -> V_221 == V_249 )
F_198 ( V_2 -> V_6 , V_250 ,
L_3 , V_242 ) ;
F_199 ( V_2 , V_251 ) ;
F_194 ( V_2 -> V_6 , V_188 -> V_221 , L_4 ) ;
V_25:
F_57 ( & V_2 -> V_59 ) ;
return V_99 ;
}
void F_200 ( struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_252 ; V_69 ++ ) {
struct V_80 * V_81 = & V_2 -> V_81 [ V_69 ] ;
F_201 ( & V_81 -> V_90 , V_253 ) ;
F_202 ( & V_81 -> V_89 ) ;
F_203 ( & V_81 -> V_92 ) ;
V_81 -> V_94 = 0 ;
}
V_2 -> V_102 = ( V_2 -> V_254 - V_222 -
V_255 - F_107 ( V_2 ) ) *
V_116 ;
}
int T_7 F_204 ( void )
{
V_85 = F_205 ( L_5 ,
sizeof( struct V_82 ) ) ;
if ( ! V_85 )
return - V_148 ;
V_256 = F_205 ( L_6 ,
sizeof( struct V_257 ) ) ;
if ( ! V_256 ) {
F_206 ( V_85 ) ;
return - V_148 ;
}
return 0 ;
}
void F_207 ( void )
{
F_206 ( V_85 ) ;
F_206 ( V_256 ) ;
}
