struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_1 = NULL ;
V_7:
V_1 = F_3 ( V_6 , V_4 ) ;
if ( ! V_1 ) {
F_4 () ;
goto V_7;
}
F_5 ( V_1 , V_8 , true ) ;
F_6 ( V_1 ) ;
return V_1 ;
}
static struct V_1 * F_7 ( struct V_2 * V_3 , T_1 V_4 ,
bool V_9 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_1 ;
struct V_10 V_11 = {
. V_3 = V_3 ,
. type = V_8 ,
. V_12 = V_13 | V_14 | V_15 ,
. V_16 = V_4 ,
. V_17 = V_4 ,
. V_18 = NULL ,
} ;
if ( F_8 ( ! V_9 ) )
V_11 . V_12 &= ~ V_14 ;
V_7:
V_1 = F_3 ( V_6 , V_4 ) ;
if ( ! V_1 ) {
F_4 () ;
goto V_7;
}
if ( F_9 ( V_1 ) )
goto V_19;
V_11 . V_1 = V_1 ;
if ( F_10 ( & V_11 ) ) {
F_11 ( V_1 , 1 ) ;
goto V_7;
}
F_12 ( V_1 ) ;
if ( F_8 ( V_1 -> V_6 != V_6 ) ) {
F_11 ( V_1 , 1 ) ;
goto V_7;
}
if ( F_8 ( ! F_9 ( V_1 ) ) )
F_13 ( V_3 ) ;
V_19:
return V_1 ;
}
struct V_1 * F_14 ( struct V_2 * V_3 , T_1 V_4 )
{
return F_7 ( V_3 , V_4 , true ) ;
}
struct V_1 * F_15 ( struct V_2 * V_3 , T_1 V_4 )
{
return F_7 ( V_3 , V_4 , false ) ;
}
bool F_16 ( struct V_2 * V_3 , T_2 V_20 , int type )
{
switch ( type ) {
case V_21 :
break;
case V_22 :
if ( F_8 ( V_20 >= F_17 ( V_3 ) ) )
return false ;
break;
case V_23 :
if ( F_8 ( V_20 >= F_18 ( V_3 ) ||
V_20 < F_19 ( V_3 ) -> V_24 ) )
return false ;
break;
case V_25 :
if ( F_8 ( V_20 >= F_20 ( V_3 ) -> V_26 ||
V_20 < F_21 ( V_3 ) ) )
return false ;
break;
case V_27 :
if ( F_8 ( V_20 >= F_22 ( V_3 ) ||
V_20 < F_18 ( V_3 ) ) )
return false ;
break;
default:
F_23 () ;
}
return true ;
}
int F_24 ( struct V_2 * V_3 , T_2 V_28 , int V_29 ,
int type , bool V_30 )
{
struct V_1 * V_1 ;
T_2 V_31 = V_28 ;
struct V_10 V_11 = {
. V_3 = V_3 ,
. type = V_8 ,
. V_12 = V_30 ? ( V_13 | V_14 | V_15 ) : V_32 ,
. V_18 = NULL ,
} ;
struct V_33 V_34 ;
if ( F_8 ( type == V_27 ) )
V_11 . V_12 &= ~ V_14 ;
F_25 ( & V_34 ) ;
for (; V_29 -- > 0 ; V_31 ++ ) {
if ( ! F_16 ( V_3 , V_31 , type ) )
goto V_19;
switch ( type ) {
case V_21 :
if ( F_8 ( V_31 >=
F_26 ( F_27 ( V_3 ) -> V_35 ) ) )
V_31 = 0 ;
V_11 . V_17 = F_28 ( V_3 ,
V_31 * V_36 ) ;
break;
case V_22 :
V_11 . V_17 = F_29 ( V_3 ,
V_31 * V_37 ) ;
break;
case V_23 :
case V_25 :
case V_27 :
V_11 . V_17 = V_31 ;
break;
default:
F_23 () ;
}
V_1 = F_3 ( F_2 ( V_3 ) , V_11 . V_17 ) ;
if ( ! V_1 )
continue;
if ( F_9 ( V_1 ) ) {
F_11 ( V_1 , 1 ) ;
continue;
}
V_11 . V_1 = V_1 ;
V_11 . V_16 = V_11 . V_17 ;
F_30 ( & V_11 ) ;
F_11 ( V_1 , 0 ) ;
}
V_19:
F_31 ( V_3 , V_8 , V_38 ) ;
F_32 ( & V_34 ) ;
return V_31 - V_28 ;
}
void F_33 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_1 ;
bool V_39 = false ;
V_1 = F_34 ( F_2 ( V_3 ) , V_4 ) ;
if ( ! V_1 || ( V_1 && ! F_9 ( V_1 ) ) )
V_39 = true ;
F_11 ( V_1 , 0 ) ;
if ( V_39 )
F_24 ( V_3 , V_4 , F_35 ( V_3 ) , V_27 , true ) ;
}
static int F_36 ( struct V_1 * V_1 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_37 ( V_1 ) ;
F_38 ( V_1 , V_8 ) ;
if ( F_8 ( F_39 ( V_3 , V_42 ) ) )
goto V_43;
if ( V_41 -> V_44 && V_1 -> V_4 < F_40 ( V_3 , 0 ) )
goto V_43;
if ( F_8 ( F_41 ( V_3 ) ) )
goto V_43;
F_42 ( V_3 , V_1 ) ;
F_43 ( V_3 , V_45 ) ;
if ( V_41 -> V_44 )
F_44 ( V_3 , NULL , V_1 , 0 , V_8 , V_46 ) ;
F_45 ( V_1 ) ;
if ( F_8 ( F_41 ( V_3 ) ) )
F_31 ( V_3 , V_8 , V_46 ) ;
return 0 ;
V_43:
F_46 ( V_41 , V_1 ) ;
return V_47 ;
}
static int F_47 ( struct V_5 * V_6 ,
struct V_40 * V_41 )
{
struct V_2 * V_3 = F_48 ( V_6 ) ;
long V_48 , V_49 ;
if ( V_41 -> V_50 ||
F_49 ( V_3 , V_45 ) < F_50 ( V_3 , V_8 ) )
goto V_51;
F_51 ( V_6 -> V_52 , V_41 , V_8 ) ;
F_52 ( & V_3 -> V_53 ) ;
V_48 = F_53 ( V_3 , V_8 , V_41 ) ;
V_49 = F_54 ( V_3 , V_8 , V_41 -> V_54 ) ;
F_55 ( & V_3 -> V_53 ) ;
V_41 -> V_54 = F_56 ( ( long ) 0 , V_41 -> V_54 - V_49 - V_48 ) ;
return 0 ;
V_51:
V_41 -> V_55 += F_49 ( V_3 , V_45 ) ;
F_51 ( V_6 -> V_52 , V_41 , V_8 ) ;
return 0 ;
}
long F_54 ( struct V_2 * V_3 , enum V_56 type ,
long V_54 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
T_1 V_4 = 0 , V_57 = V_58 , V_59 = V_58 ;
struct V_60 V_61 ;
long V_62 = 0 ;
struct V_40 V_41 = {
. V_44 = 0 ,
} ;
struct V_33 V_34 ;
F_57 ( & V_61 , 0 ) ;
F_25 ( & V_34 ) ;
while ( V_4 <= V_57 ) {
int V_63 , V_64 ;
V_64 = F_58 ( & V_61 , V_6 , & V_4 ,
V_65 ,
F_59 ( V_57 - V_4 , ( T_1 ) V_66 - 1 ) + 1 ) ;
if ( F_8 ( V_64 == 0 ) )
break;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ ) {
struct V_1 * V_1 = V_61 . V_67 [ V_63 ] ;
if ( V_59 == V_58 )
V_59 = V_1 -> V_4 - 1 ;
if ( V_54 != V_68 && V_1 -> V_4 != V_59 + 1 ) {
F_60 ( & V_61 ) ;
goto V_69;
}
F_12 ( V_1 ) ;
if ( F_8 ( V_1 -> V_6 != V_6 ) ) {
V_70:
F_45 ( V_1 ) ;
continue;
}
if ( ! F_61 ( V_1 ) ) {
goto V_70;
}
F_5 ( V_1 , V_8 , true ) ;
F_62 ( F_63 ( V_1 ) ) ;
if ( ! F_64 ( V_1 ) )
goto V_70;
if ( V_6 -> V_71 -> V_72 ( V_1 , & V_41 ) ) {
F_45 ( V_1 ) ;
break;
}
V_62 ++ ;
V_59 = V_1 -> V_4 ;
if ( F_8 ( V_62 >= V_54 ) )
break;
}
F_60 ( & V_61 ) ;
F_4 () ;
}
V_69:
if ( V_62 )
F_31 ( V_3 , type , V_46 ) ;
F_32 ( & V_34 ) ;
return V_62 ;
}
static int F_65 ( struct V_1 * V_1 )
{
F_66 ( V_1 , V_8 ) ;
F_6 ( V_1 ) ;
if ( ! F_61 ( V_1 ) ) {
F_67 ( V_1 ) ;
F_68 ( F_37 ( V_1 ) , V_45 ) ;
F_69 ( V_1 ) ;
F_70 ( V_1 ) ;
return 1 ;
}
return 0 ;
}
static void F_71 ( struct V_2 * V_3 , T_3 V_73 , int type )
{
struct V_74 * V_75 = & V_3 -> V_75 [ type ] ;
struct V_76 * V_77 , * V_78 ;
V_78 = F_72 ( V_79 , V_80 ) ;
V_81:
F_73 ( V_80 | V_82 ) ;
F_74 ( & V_75 -> V_83 ) ;
V_77 = F_75 ( & V_75 -> V_84 , V_73 ) ;
if ( ! V_77 ) {
V_77 = V_78 ;
if ( F_76 ( & V_75 -> V_84 , V_73 , V_77 ) ) {
F_77 ( & V_75 -> V_83 ) ;
F_78 () ;
goto V_81;
}
memset ( V_77 , 0 , sizeof( struct V_76 ) ) ;
V_77 -> V_73 = V_73 ;
F_79 ( & V_77 -> V_85 , & V_75 -> V_86 ) ;
if ( type != V_87 )
V_75 -> V_88 ++ ;
}
F_77 ( & V_75 -> V_83 ) ;
F_78 () ;
if ( V_77 != V_78 )
F_80 ( V_79 , V_78 ) ;
}
static void F_81 ( struct V_2 * V_3 , T_3 V_73 , int type )
{
struct V_74 * V_75 = & V_3 -> V_75 [ type ] ;
struct V_76 * V_77 ;
F_74 ( & V_75 -> V_83 ) ;
V_77 = F_75 ( & V_75 -> V_84 , V_73 ) ;
if ( V_77 ) {
F_82 ( & V_77 -> V_85 ) ;
F_83 ( & V_75 -> V_84 , V_73 ) ;
V_75 -> V_88 -- ;
F_77 ( & V_75 -> V_83 ) ;
F_80 ( V_79 , V_77 ) ;
return;
}
F_77 ( & V_75 -> V_83 ) ;
}
void F_84 ( struct V_2 * V_3 , T_3 V_73 , int type )
{
F_71 ( V_3 , V_73 , type ) ;
}
void F_85 ( struct V_2 * V_3 , T_3 V_73 , int type )
{
F_81 ( V_3 , V_73 , type ) ;
}
bool F_86 ( struct V_2 * V_3 , T_3 V_73 , int V_89 )
{
struct V_74 * V_75 = & V_3 -> V_75 [ V_89 ] ;
struct V_76 * V_77 ;
F_74 ( & V_75 -> V_83 ) ;
V_77 = F_75 ( & V_75 -> V_84 , V_73 ) ;
F_77 ( & V_75 -> V_83 ) ;
return V_77 ? true : false ;
}
void F_87 ( struct V_2 * V_3 )
{
struct V_76 * V_77 , * V_78 ;
int V_63 ;
for ( V_63 = V_90 ; V_63 <= V_91 ; V_63 ++ ) {
struct V_74 * V_75 = & V_3 -> V_75 [ V_63 ] ;
F_74 ( & V_75 -> V_83 ) ;
F_88 (e, tmp, &im->ino_list, list) {
F_82 ( & V_77 -> V_85 ) ;
F_83 ( & V_75 -> V_84 , V_77 -> V_73 ) ;
F_80 ( V_79 , V_77 ) ;
V_75 -> V_88 -- ;
}
F_77 ( & V_75 -> V_83 ) ;
}
}
int F_89 ( struct V_2 * V_3 )
{
struct V_74 * V_75 = & V_3 -> V_75 [ V_87 ] ;
int V_92 = 0 ;
F_74 ( & V_75 -> V_83 ) ;
if ( F_8 ( V_75 -> V_88 >= V_3 -> V_93 ) )
V_92 = - V_94 ;
else
V_75 -> V_88 ++ ;
F_77 ( & V_75 -> V_83 ) ;
return V_92 ;
}
void F_90 ( struct V_2 * V_3 )
{
struct V_74 * V_75 = & V_3 -> V_75 [ V_87 ] ;
F_74 ( & V_75 -> V_83 ) ;
F_91 ( V_3 , V_75 -> V_88 == 0 ) ;
V_75 -> V_88 -- ;
F_77 ( & V_75 -> V_83 ) ;
}
void F_92 ( struct V_2 * V_3 , T_3 V_73 )
{
F_71 ( V_3 , V_73 , V_87 ) ;
}
void F_93 ( struct V_2 * V_3 , T_3 V_73 )
{
F_81 ( V_3 , V_73 , V_87 ) ;
}
static int F_94 ( struct V_2 * V_3 , T_3 V_73 )
{
struct V_95 * V_95 ;
V_95 = F_95 ( V_3 -> V_96 , V_73 ) ;
if ( F_96 ( V_95 ) ) {
F_91 ( V_3 , F_97 ( V_95 ) == - V_97 ) ;
return F_97 ( V_95 ) ;
}
F_98 ( V_95 ) ;
F_99 ( V_95 ) ;
return 0 ;
}
int F_100 ( struct V_2 * V_3 )
{
T_2 V_98 , V_99 , V_63 , V_100 ;
int V_92 ;
if ( ! F_101 ( F_102 ( V_3 ) , V_101 ) )
return 0 ;
V_98 = F_21 ( V_3 ) + 1 + F_103 ( V_3 ) ;
V_99 = F_104 ( V_3 ) - 1 - F_103 ( V_3 ) ;
F_24 ( V_3 , V_98 , V_99 , V_25 , true ) ;
for ( V_63 = 0 ; V_63 < V_99 ; V_63 ++ ) {
struct V_1 * V_1 = F_14 ( V_3 , V_98 + V_63 ) ;
struct V_102 * V_103 ;
V_103 = (struct V_102 * ) F_105 ( V_1 ) ;
for ( V_100 = 0 ; V_100 < F_106 ( V_103 -> V_104 ) ; V_100 ++ ) {
T_3 V_73 = F_106 ( V_103 -> V_73 [ V_100 ] ) ;
V_92 = F_94 ( V_3 , V_73 ) ;
if ( V_92 ) {
F_11 ( V_1 , 1 ) ;
return V_92 ;
}
}
F_11 ( V_1 , 1 ) ;
}
F_107 ( F_102 ( V_3 ) , V_101 ) ;
return 0 ;
}
static void F_108 ( struct V_2 * V_3 , T_2 V_98 )
{
struct V_105 * V_106 ;
struct V_102 * V_103 = NULL ;
unsigned int V_107 = 0 ;
unsigned short V_4 = 1 ;
unsigned short V_99 ;
struct V_1 * V_1 = NULL ;
struct V_76 * V_108 = NULL ;
struct V_74 * V_75 = & V_3 -> V_75 [ V_87 ] ;
V_99 = F_109 ( V_75 -> V_88 ) ;
V_106 = & V_75 -> V_86 ;
F_110 (orphan, head, list) {
if ( ! V_1 ) {
V_1 = F_1 ( V_3 , V_98 ++ ) ;
V_103 =
(struct V_102 * ) F_105 ( V_1 ) ;
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
}
V_103 -> V_73 [ V_107 ++ ] = F_111 ( V_108 -> V_73 ) ;
if ( V_107 == V_109 ) {
V_103 -> V_110 = F_112 ( V_4 ) ;
V_103 -> V_111 = F_112 ( V_99 ) ;
V_103 -> V_104 = F_111 ( V_107 ) ;
F_113 ( V_1 ) ;
F_11 ( V_1 , 1 ) ;
V_4 ++ ;
V_107 = 0 ;
V_1 = NULL ;
}
}
if ( V_1 ) {
V_103 -> V_110 = F_112 ( V_4 ) ;
V_103 -> V_111 = F_112 ( V_99 ) ;
V_103 -> V_104 = F_111 ( V_107 ) ;
F_113 ( V_1 ) ;
F_11 ( V_1 , 1 ) ;
}
}
static struct V_1 * F_114 ( struct V_2 * V_3 ,
T_2 V_112 , unsigned long long * V_113 )
{
struct V_1 * V_114 , * V_115 = NULL ;
unsigned long V_116 = V_3 -> V_117 ;
struct V_118 * V_119 ;
unsigned long long V_120 = 0 , V_121 = 0 ;
T_4 V_122 ;
T_5 V_123 = 0 ;
V_114 = F_14 ( V_3 , V_112 ) ;
V_119 = (struct V_118 * ) F_105 ( V_114 ) ;
V_122 = F_106 ( V_119 -> V_124 ) ;
if ( V_122 >= V_116 )
goto V_125;
V_123 = F_106 ( * ( ( V_126 * ) ( ( unsigned char * ) V_119 + V_122 ) ) ) ;
if ( ! F_115 ( V_3 , V_123 , V_119 , V_122 ) )
goto V_125;
V_121 = F_116 ( V_119 ) ;
V_112 += F_106 ( V_119 -> V_127 ) - 1 ;
V_115 = F_14 ( V_3 , V_112 ) ;
V_119 = (struct V_118 * ) F_105 ( V_115 ) ;
V_122 = F_106 ( V_119 -> V_124 ) ;
if ( V_122 >= V_116 )
goto V_128;
V_123 = F_106 ( * ( ( V_126 * ) ( ( unsigned char * ) V_119 + V_122 ) ) ) ;
if ( ! F_115 ( V_3 , V_123 , V_119 , V_122 ) )
goto V_128;
V_120 = F_116 ( V_119 ) ;
if ( V_120 == V_121 ) {
* V_113 = V_120 ;
F_11 ( V_115 , 1 ) ;
return V_114 ;
}
V_128:
F_11 ( V_115 , 1 ) ;
V_125:
F_11 ( V_114 , 1 ) ;
return NULL ;
}
int F_117 ( struct V_2 * V_3 )
{
struct V_118 * V_119 ;
struct V_129 * V_130 = V_3 -> V_131 ;
struct V_1 * V_132 , * V_133 , * V_134 ;
unsigned long V_116 = V_3 -> V_117 ;
unsigned long long V_135 = 0 , V_136 = 0 ;
unsigned long long V_137 ;
unsigned int V_138 = 1 + F_103 ( V_3 ) ;
T_2 V_139 ;
int V_63 ;
V_3 -> V_140 = F_118 ( V_138 * V_116 , V_141 ) ;
if ( ! V_3 -> V_140 )
return - V_142 ;
V_137 = F_106 ( V_130 -> V_143 ) ;
V_132 = F_114 ( V_3 , V_137 , & V_135 ) ;
V_137 += ( ( unsigned long long ) 1 ) <<
F_106 ( V_130 -> V_144 ) ;
V_133 = F_114 ( V_3 , V_137 , & V_136 ) ;
if ( V_132 && V_133 ) {
if ( F_119 ( V_136 , V_135 ) )
V_134 = V_133 ;
else
V_134 = V_132 ;
} else if ( V_132 ) {
V_134 = V_132 ;
} else if ( V_133 ) {
V_134 = V_133 ;
} else {
goto V_145;
}
V_119 = (struct V_118 * ) F_105 ( V_134 ) ;
memcpy ( V_3 -> V_140 , V_119 , V_116 ) ;
if ( F_120 ( V_3 ) )
goto V_145;
if ( V_138 <= 1 )
goto V_146;
V_139 = F_106 ( V_130 -> V_143 ) ;
if ( V_134 == V_133 )
V_139 += 1 << F_106 ( V_130 -> V_144 ) ;
for ( V_63 = 1 ; V_63 < V_138 ; V_63 ++ ) {
void * V_147 ;
unsigned char * V_140 = ( unsigned char * ) V_3 -> V_140 ;
V_134 = F_14 ( V_3 , V_139 + V_63 ) ;
V_147 = F_105 ( V_134 ) ;
memcpy ( V_140 + V_63 * V_116 , V_147 , V_116 ) ;
F_11 ( V_134 , 1 ) ;
}
V_146:
F_11 ( V_132 , 1 ) ;
F_11 ( V_133 , 1 ) ;
return 0 ;
V_145:
F_121 ( V_3 -> V_140 ) ;
return - V_148 ;
}
static void F_122 ( struct V_95 * V_95 , enum V_149 type )
{
struct V_2 * V_3 = F_123 ( V_95 ) ;
struct V_150 * V_151 = F_124 ( V_95 ) ;
int V_152 = ( type == V_153 ) ? V_154 : V_155 ;
if ( F_125 ( V_151 , V_152 ) )
return;
F_126 ( V_151 , V_152 ) ;
F_79 ( & V_151 -> V_156 , & V_3 -> V_157 [ type ] ) ;
F_127 ( V_3 , type ) ;
}
static void F_128 ( struct V_95 * V_95 , enum V_149 type )
{
struct V_150 * V_151 = F_124 ( V_95 ) ;
int V_152 = ( type == V_153 ) ? V_154 : V_155 ;
if ( F_129 ( V_95 ) ||
! F_125 ( F_124 ( V_95 ) , V_152 ) )
return;
F_130 ( & V_151 -> V_156 ) ;
F_131 ( V_151 , V_152 ) ;
F_132 ( F_123 ( V_95 ) , type ) ;
}
void F_133 ( struct V_95 * V_95 , struct V_1 * V_1 )
{
struct V_2 * V_3 = F_123 ( V_95 ) ;
enum V_149 type = F_134 ( V_95 -> V_158 ) ? V_153 : V_159 ;
if ( ! F_134 ( V_95 -> V_158 ) && ! F_135 ( V_95 -> V_158 ) &&
! F_136 ( V_95 -> V_158 ) )
return;
F_74 ( & V_3 -> V_160 [ type ] ) ;
F_122 ( V_95 , type ) ;
F_137 ( V_95 ) ;
F_77 ( & V_3 -> V_160 [ type ] ) ;
F_69 ( V_1 ) ;
F_70 ( V_1 ) ;
}
void F_138 ( struct V_95 * V_95 )
{
struct V_2 * V_3 = F_123 ( V_95 ) ;
F_74 ( & V_3 -> V_160 [ V_153 ] ) ;
F_122 ( V_95 , V_153 ) ;
F_77 ( & V_3 -> V_160 [ V_153 ] ) ;
}
void F_139 ( struct V_95 * V_95 )
{
struct V_2 * V_3 = F_123 ( V_95 ) ;
struct V_150 * V_151 = F_124 ( V_95 ) ;
enum V_149 type = F_134 ( V_95 -> V_158 ) ? V_153 : V_159 ;
if ( ! F_134 ( V_95 -> V_158 ) && ! F_135 ( V_95 -> V_158 ) &&
! F_136 ( V_95 -> V_158 ) )
return;
F_74 ( & V_3 -> V_160 [ type ] ) ;
F_128 ( V_95 , type ) ;
F_77 ( & V_3 -> V_160 [ type ] ) ;
if ( F_125 ( V_151 , V_161 ) ) {
F_131 ( V_151 , V_161 ) ;
F_99 ( V_95 ) ;
}
}
int F_140 ( struct V_2 * V_3 , enum V_149 type )
{
struct V_105 * V_106 ;
struct V_95 * V_95 ;
struct V_150 * V_151 ;
bool V_162 = ( type == V_153 ) ;
F_141 ( V_3 -> V_96 , V_162 ,
F_49 ( V_3 , V_162 ?
V_163 : V_164 ) ) ;
V_81:
if ( F_8 ( F_41 ( V_3 ) ) )
return - V_165 ;
F_74 ( & V_3 -> V_160 [ type ] ) ;
V_106 = & V_3 -> V_157 [ type ] ;
if ( F_142 ( V_106 ) ) {
F_77 ( & V_3 -> V_160 [ type ] ) ;
F_143 ( V_3 -> V_96 , V_162 ,
F_49 ( V_3 , V_162 ?
V_163 : V_164 ) ) ;
return 0 ;
}
V_151 = F_144 ( V_106 -> V_166 , struct V_150 , V_156 ) ;
V_95 = F_145 ( & V_151 -> V_167 ) ;
F_77 ( & V_3 -> V_160 [ type ] ) ;
if ( V_95 ) {
F_146 ( V_95 -> V_168 ) ;
F_99 ( V_95 ) ;
} else {
F_31 ( V_3 , V_169 , V_46 ) ;
F_4 () ;
}
goto V_81;
}
static int F_147 ( struct V_2 * V_3 )
{
struct V_40 V_41 = {
. V_170 = V_171 ,
. V_54 = V_68 ,
. V_44 = 0 ,
} ;
struct V_33 V_34 ;
int V_92 = 0 ;
F_25 ( & V_34 ) ;
V_172:
F_148 ( V_3 ) ;
if ( F_49 ( V_3 , V_163 ) ) {
F_149 ( V_3 ) ;
V_92 = F_140 ( V_3 , V_153 ) ;
if ( V_92 )
goto V_19;
goto V_172;
}
V_173:
F_150 ( & V_3 -> V_174 ) ;
if ( F_49 ( V_3 , V_175 ) ) {
F_151 ( & V_3 -> V_174 ) ;
V_92 = F_152 ( V_3 , 0 , & V_41 ) ;
if ( V_92 ) {
F_149 ( V_3 ) ;
goto V_19;
}
goto V_173;
}
V_19:
F_32 ( & V_34 ) ;
return V_92 ;
}
static void F_153 ( struct V_2 * V_3 )
{
F_151 ( & V_3 -> V_174 ) ;
F_149 ( V_3 ) ;
}
static void F_154 ( struct V_2 * V_3 )
{
F_155 ( V_176 ) ;
for (; ; ) {
F_156 ( & V_3 -> V_177 , & V_176 , V_178 ) ;
if ( ! F_49 ( V_3 , V_179 ) )
break;
F_157 ( 5 * V_180 ) ;
}
F_158 ( & V_3 -> V_177 , & V_176 ) ;
}
static int F_159 ( struct V_2 * V_3 , struct V_181 * V_182 )
{
struct V_118 * V_140 = F_102 ( V_3 ) ;
struct V_183 * V_184 = F_160 ( V_3 , V_185 ) ;
struct V_186 * V_187 = F_27 ( V_3 ) ;
unsigned long V_188 = V_3 -> V_75 [ V_87 ] . V_88 ;
T_3 V_189 = V_187 -> V_190 ;
T_2 V_98 ;
unsigned int V_191 , V_99 ;
T_5 V_192 = 0 ;
int V_63 ;
int V_193 = F_103 ( V_3 ) ;
T_2 V_194 = F_161 ( V_3 , V_184 ) ;
bool V_195 = false ;
struct V_196 * V_96 = V_3 -> V_96 ;
struct V_183 * V_197 = F_160 ( V_3 , V_198 ) ;
T_6 V_199 ;
if ( F_162 ( V_3 , V_194 ) )
V_195 = true ;
while ( F_49 ( V_3 , V_45 ) ) {
F_54 ( V_3 , V_8 , V_68 ) ;
if ( F_8 ( F_41 ( V_3 ) ) )
return - V_165 ;
}
F_163 ( V_3 , & V_189 ) ;
V_140 -> V_200 = F_164 ( F_165 ( V_3 ) ) ;
V_140 -> V_201 = F_164 ( F_166 ( V_3 ) ) ;
V_140 -> V_202 = F_111 ( F_167 ( V_3 ) ) ;
for ( V_63 = 0 ; V_63 < V_203 ; V_63 ++ ) {
V_140 -> V_204 [ V_63 ] =
F_111 ( F_168 ( V_3 , V_63 + V_198 ) ) ;
V_140 -> V_205 [ V_63 ] =
F_112 ( F_169 ( V_3 , V_63 + V_198 ) ) ;
V_140 -> V_206 [ V_63 + V_198 ] =
F_170 ( V_3 , V_63 + V_198 ) ;
}
for ( V_63 = 0 ; V_63 < V_207 ; V_63 ++ ) {
V_140 -> V_208 [ V_63 ] =
F_111 ( F_168 ( V_3 , V_63 + V_209 ) ) ;
V_140 -> V_210 [ V_63 ] =
F_112 ( F_169 ( V_3 , V_63 + V_209 ) ) ;
V_140 -> V_206 [ V_63 + V_209 ] =
F_170 ( V_3 , V_63 + V_209 ) ;
}
V_140 -> V_211 = F_111 ( V_211 ( V_3 ) ) ;
V_140 -> V_212 = F_111 ( V_212 ( V_3 ) ) ;
V_140 -> F_163 = F_111 ( V_189 ) ;
V_191 = F_171 ( V_3 , false ) ;
if ( V_191 < V_207 )
F_172 ( V_140 , V_213 ) ;
else
F_107 ( V_140 , V_213 ) ;
V_99 = F_109 ( V_188 ) ;
V_140 -> V_214 = F_111 ( 1 + V_193 +
V_99 ) ;
if ( F_173 ( V_182 -> V_215 ) )
V_140 -> V_127 = F_111 ( V_216 +
V_193 + V_191 +
V_99 + V_203 ) ;
else
V_140 -> V_127 = F_111 ( V_216 +
V_193 + V_191 +
V_99 ) ;
if ( V_182 -> V_215 == V_217 )
F_172 ( V_140 , V_218 ) ;
else
F_107 ( V_140 , V_218 ) ;
if ( V_182 -> V_215 == V_219 )
F_172 ( V_140 , V_220 ) ;
else
F_107 ( V_140 , V_220 ) ;
if ( V_188 )
F_172 ( V_140 , V_101 ) ;
else
F_107 ( V_140 , V_101 ) ;
if ( F_39 ( V_3 , V_221 ) )
F_172 ( V_140 , V_222 ) ;
F_174 ( V_3 , F_175 ( V_3 , V_223 ) ) ;
F_176 ( V_3 , F_175 ( V_3 , V_224 ) ) ;
V_192 = F_177 ( V_3 , V_140 , F_106 ( V_140 -> V_124 ) ) ;
* ( ( V_126 * ) ( ( unsigned char * ) V_140 +
F_106 ( V_140 -> V_124 ) ) )
= F_111 ( V_192 ) ;
V_98 = F_21 ( V_3 ) ;
F_154 ( V_3 ) ;
if ( F_8 ( F_41 ( V_3 ) ) )
return - V_165 ;
F_178 ( V_3 , V_140 , V_98 ++ ) ;
for ( V_63 = 1 ; V_63 < 1 + V_193 ; V_63 ++ )
F_178 ( V_3 , ( char * ) V_140 + V_63 * V_225 ,
V_98 ++ ) ;
if ( V_188 ) {
F_108 ( V_3 , V_98 ) ;
V_98 += V_99 ;
}
F_179 ( V_3 , V_98 ) ;
V_98 += V_191 ;
V_199 = V_3 -> V_199 ;
if ( V_96 -> V_226 -> V_227 )
V_199 += F_180 ( V_3 ) ;
V_197 -> V_228 -> V_229 . V_199 = F_164 ( V_199 ) ;
if ( F_173 ( V_182 -> V_215 ) ) {
F_181 ( V_3 , V_98 ) ;
V_98 += V_203 ;
}
F_178 ( V_3 , V_140 , V_98 ) ;
F_154 ( V_3 ) ;
if ( F_8 ( F_41 ( V_3 ) ) )
return - V_165 ;
F_182 ( F_183 ( V_3 ) , 0 , V_230 ) ;
F_182 ( F_2 ( V_3 ) , 0 , V_230 ) ;
V_3 -> V_231 = V_3 -> V_232 ;
V_3 -> V_233 = 0 ;
F_54 ( V_3 , V_234 , V_68 ) ;
F_154 ( V_3 ) ;
if ( V_195 )
F_184 ( F_2 ( V_3 ) , V_194 ,
V_194 ) ;
F_87 ( V_3 ) ;
if ( F_8 ( F_41 ( V_3 ) ) )
return - V_165 ;
F_185 ( V_3 , V_182 ) ;
F_186 ( V_3 , V_235 ) ;
return 0 ;
}
int F_187 ( struct V_2 * V_3 , struct V_181 * V_182 )
{
struct V_118 * V_140 = F_102 ( V_3 ) ;
unsigned long long V_236 ;
int V_92 = 0 ;
F_52 ( & V_3 -> V_53 ) ;
if ( ! F_39 ( V_3 , V_235 ) &&
( V_182 -> V_215 == V_219 || V_182 -> V_215 == V_237 ||
( V_182 -> V_215 == V_238 && ! V_3 -> V_239 ) ) )
goto V_19;
if ( F_8 ( F_41 ( V_3 ) ) ) {
V_92 = - V_165 ;
goto V_19;
}
if ( F_188 ( V_3 -> V_96 ) ) {
V_92 = - V_240 ;
goto V_19;
}
F_189 ( V_3 -> V_96 , V_182 -> V_215 , L_1 ) ;
V_92 = F_147 ( V_3 ) ;
if ( V_92 )
goto V_19;
F_189 ( V_3 -> V_96 , V_182 -> V_215 , L_2 ) ;
F_190 ( V_3 ) ;
V_236 = F_116 ( V_140 ) ;
V_140 -> V_241 = F_164 ( ++ V_236 ) ;
F_191 ( V_3 ) ;
F_192 ( V_3 , V_182 ) ;
V_92 = F_159 ( V_3 , V_182 ) ;
F_153 ( V_3 ) ;
F_193 ( V_3 -> V_242 ) ;
if ( V_182 -> V_215 == V_243 )
F_194 ( V_3 -> V_96 , V_244 ,
L_3 , V_236 ) ;
F_195 ( V_3 , V_245 ) ;
F_189 ( V_3 -> V_96 , V_182 -> V_215 , L_4 ) ;
V_19:
F_55 ( & V_3 -> V_53 ) ;
return V_92 ;
}
void F_196 ( struct V_2 * V_3 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_246 ; V_63 ++ ) {
struct V_74 * V_75 = & V_3 -> V_75 [ V_63 ] ;
F_197 ( & V_75 -> V_84 , V_247 ) ;
F_198 ( & V_75 -> V_83 ) ;
F_199 ( & V_75 -> V_86 ) ;
V_75 -> V_88 = 0 ;
}
V_3 -> V_93 = ( V_3 -> V_248 - V_216 -
V_249 - F_103 ( V_3 ) ) *
V_109 ;
}
int T_7 F_200 ( void )
{
V_79 = F_201 ( L_5 ,
sizeof( struct V_76 ) ) ;
if ( ! V_79 )
return - V_142 ;
V_250 = F_201 ( L_6 ,
sizeof( struct V_251 ) ) ;
if ( ! V_250 ) {
F_202 ( V_79 ) ;
return - V_142 ;
}
return 0 ;
}
void F_203 ( void )
{
F_202 ( V_79 ) ;
F_202 ( V_250 ) ;
}
