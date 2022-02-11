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
F_5 ( V_1 , V_8 ) ;
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
. V_17 = NULL ,
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
goto V_18;
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
V_18:
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
bool F_16 ( struct V_2 * V_3 , T_2 V_19 , int type )
{
switch ( type ) {
case V_20 :
break;
case V_21 :
if ( F_8 ( V_19 >= F_17 ( V_3 ) ) )
return false ;
break;
case V_22 :
if ( F_8 ( V_19 >= F_18 ( V_3 ) ||
V_19 < F_19 ( V_3 ) -> V_23 ) )
return false ;
break;
case V_24 :
if ( F_8 ( V_19 >= F_20 ( V_3 ) -> V_25 ||
V_19 < F_21 ( V_3 ) ) )
return false ;
break;
case V_26 :
if ( F_8 ( V_19 >= F_22 ( V_3 ) ||
V_19 < F_18 ( V_3 ) ) )
return false ;
break;
default:
F_23 () ;
}
return true ;
}
int F_24 ( struct V_2 * V_3 , T_2 V_27 , int V_28 ,
int type , bool V_29 )
{
T_2 V_30 = 0 ;
struct V_1 * V_1 ;
T_2 V_31 = V_27 ;
struct V_10 V_11 = {
. V_3 = V_3 ,
. type = V_8 ,
. V_12 = V_29 ? ( V_13 | V_14 | V_15 ) : V_32 ,
. V_17 = NULL ,
} ;
if ( F_8 ( type == V_26 ) )
V_11 . V_12 &= ~ V_14 ;
for (; V_28 -- > 0 ; V_31 ++ ) {
if ( ! F_16 ( V_3 , V_31 , type ) )
goto V_18;
switch ( type ) {
case V_20 :
if ( F_8 ( V_31 >=
F_25 ( F_26 ( V_3 ) -> V_33 ) ) )
V_31 = 0 ;
V_11 . V_16 = F_27 ( V_3 ,
V_31 * V_34 ) ;
break;
case V_21 :
V_11 . V_16 = F_28 ( V_3 ,
V_31 * V_35 ) ;
if ( V_31 != V_27 && V_30 + 1 != V_11 . V_16 )
goto V_18;
V_30 = V_11 . V_16 ;
break;
case V_22 :
case V_24 :
case V_26 :
V_11 . V_16 = V_31 ;
break;
default:
F_23 () ;
}
V_1 = F_3 ( F_2 ( V_3 ) , V_11 . V_16 ) ;
if ( ! V_1 )
continue;
if ( F_9 ( V_1 ) ) {
F_11 ( V_1 , 1 ) ;
continue;
}
V_11 . V_1 = V_1 ;
F_29 ( & V_11 ) ;
F_11 ( V_1 , 0 ) ;
}
V_18:
F_30 ( V_3 , V_8 , V_36 ) ;
return V_31 - V_27 ;
}
void F_31 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_1 ;
bool V_37 = false ;
V_1 = F_32 ( F_2 ( V_3 ) , V_4 ) ;
if ( ! V_1 || ( V_1 && ! F_9 ( V_1 ) ) )
V_37 = true ;
F_11 ( V_1 , 0 ) ;
if ( V_37 )
F_24 ( V_3 , V_4 , F_33 ( V_3 ) , V_26 , true ) ;
}
static int F_34 ( struct V_1 * V_1 ,
struct V_38 * V_39 )
{
struct V_2 * V_3 = F_35 ( V_1 ) ;
F_36 ( V_1 , V_8 ) ;
if ( F_8 ( F_37 ( V_3 , V_40 ) ) )
goto V_41;
if ( V_39 -> V_42 && V_1 -> V_4 < F_38 ( V_3 , 0 ) )
goto V_41;
if ( F_8 ( F_39 ( V_3 ) ) )
goto V_41;
F_5 ( V_1 , V_8 ) ;
F_40 ( V_3 , V_1 ) ;
F_41 ( V_3 , V_43 ) ;
F_42 ( V_1 ) ;
if ( V_39 -> V_42 )
F_30 ( V_3 , V_8 , V_44 ) ;
return 0 ;
V_41:
F_43 ( V_39 , V_1 ) ;
return V_45 ;
}
static int F_44 ( struct V_5 * V_6 ,
struct V_38 * V_39 )
{
struct V_2 * V_3 = F_45 ( V_6 ) ;
long V_46 , V_47 ;
F_46 ( V_6 -> V_48 , V_39 , V_8 ) ;
if ( V_39 -> V_49 ||
F_47 ( V_3 , V_43 ) < F_48 ( V_3 , V_8 ) )
goto V_50;
F_49 ( & V_3 -> V_51 ) ;
V_46 = F_50 ( V_3 , V_8 , V_39 ) ;
V_47 = F_51 ( V_3 , V_8 , V_39 -> V_52 ) ;
F_52 ( & V_3 -> V_51 ) ;
V_39 -> V_52 = F_53 ( ( long ) 0 , V_39 -> V_52 - V_47 - V_46 ) ;
return 0 ;
V_50:
V_39 -> V_53 += F_47 ( V_3 , V_43 ) ;
return 0 ;
}
long F_51 ( struct V_2 * V_3 , enum V_54 type ,
long V_52 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
T_1 V_4 = 0 , V_55 = V_56 , V_57 = V_56 ;
struct V_58 V_59 ;
long V_60 = 0 ;
struct V_38 V_39 = {
. V_42 = 0 ,
} ;
F_54 ( & V_59 , 0 ) ;
while ( V_4 <= V_55 ) {
int V_61 , V_62 ;
V_62 = F_55 ( & V_59 , V_6 , & V_4 ,
V_63 ,
F_56 ( V_55 - V_4 , ( T_1 ) V_64 - 1 ) + 1 ) ;
if ( F_8 ( V_62 == 0 ) )
break;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
struct V_1 * V_1 = V_59 . V_65 [ V_61 ] ;
if ( V_57 == V_56 )
V_57 = V_1 -> V_4 - 1 ;
if ( V_52 != V_56 && V_1 -> V_4 != V_57 + 1 ) {
F_57 ( & V_59 ) ;
goto V_66;
}
F_12 ( V_1 ) ;
if ( F_8 ( V_1 -> V_6 != V_6 ) ) {
V_67:
F_42 ( V_1 ) ;
continue;
}
if ( ! F_58 ( V_1 ) ) {
goto V_67;
}
if ( ! F_59 ( V_1 ) )
goto V_67;
if ( V_6 -> V_68 -> V_69 ( V_1 , & V_39 ) ) {
F_42 ( V_1 ) ;
break;
}
V_60 ++ ;
V_57 = V_1 -> V_4 ;
if ( F_8 ( V_60 >= V_52 ) )
break;
}
F_57 ( & V_59 ) ;
F_4 () ;
}
V_66:
if ( V_60 )
F_30 ( V_3 , type , V_44 ) ;
return V_60 ;
}
static int F_60 ( struct V_1 * V_1 )
{
F_61 ( V_1 , V_8 ) ;
F_6 ( V_1 ) ;
if ( ! F_58 ( V_1 ) ) {
F_62 ( V_1 ) ;
F_63 ( F_35 ( V_1 ) , V_43 ) ;
F_64 ( V_1 ) ;
F_65 ( V_1 ) ;
return 1 ;
}
return 0 ;
}
static void F_66 ( struct V_2 * V_3 , T_3 V_70 , int type )
{
struct V_71 * V_72 = & V_3 -> V_72 [ type ] ;
struct V_73 * V_74 , * V_75 ;
V_75 = F_67 ( V_76 , V_77 ) ;
V_78:
F_68 ( V_77 | V_79 ) ;
F_69 ( & V_72 -> V_80 ) ;
V_74 = F_70 ( & V_72 -> V_81 , V_70 ) ;
if ( ! V_74 ) {
V_74 = V_75 ;
if ( F_71 ( & V_72 -> V_81 , V_70 , V_74 ) ) {
F_72 ( & V_72 -> V_80 ) ;
F_73 () ;
goto V_78;
}
memset ( V_74 , 0 , sizeof( struct V_73 ) ) ;
V_74 -> V_70 = V_70 ;
F_74 ( & V_74 -> V_82 , & V_72 -> V_83 ) ;
if ( type != V_84 )
V_72 -> V_85 ++ ;
}
F_72 ( & V_72 -> V_80 ) ;
F_73 () ;
if ( V_74 != V_75 )
F_75 ( V_76 , V_75 ) ;
}
static void F_76 ( struct V_2 * V_3 , T_3 V_70 , int type )
{
struct V_71 * V_72 = & V_3 -> V_72 [ type ] ;
struct V_73 * V_74 ;
F_69 ( & V_72 -> V_80 ) ;
V_74 = F_70 ( & V_72 -> V_81 , V_70 ) ;
if ( V_74 ) {
F_77 ( & V_74 -> V_82 ) ;
F_78 ( & V_72 -> V_81 , V_70 ) ;
V_72 -> V_85 -- ;
F_72 ( & V_72 -> V_80 ) ;
F_75 ( V_76 , V_74 ) ;
return;
}
F_72 ( & V_72 -> V_80 ) ;
}
void F_79 ( struct V_2 * V_3 , T_3 V_70 , int type )
{
F_66 ( V_3 , V_70 , type ) ;
}
void F_80 ( struct V_2 * V_3 , T_3 V_70 , int type )
{
F_76 ( V_3 , V_70 , type ) ;
}
bool F_81 ( struct V_2 * V_3 , T_3 V_70 , int V_86 )
{
struct V_71 * V_72 = & V_3 -> V_72 [ V_86 ] ;
struct V_73 * V_74 ;
F_69 ( & V_72 -> V_80 ) ;
V_74 = F_70 ( & V_72 -> V_81 , V_70 ) ;
F_72 ( & V_72 -> V_80 ) ;
return V_74 ? true : false ;
}
void F_82 ( struct V_2 * V_3 )
{
struct V_73 * V_74 , * V_75 ;
int V_61 ;
for ( V_61 = V_87 ; V_61 <= V_88 ; V_61 ++ ) {
struct V_71 * V_72 = & V_3 -> V_72 [ V_61 ] ;
F_69 ( & V_72 -> V_80 ) ;
F_83 (e, tmp, &im->ino_list, list) {
F_77 ( & V_74 -> V_82 ) ;
F_78 ( & V_72 -> V_81 , V_74 -> V_70 ) ;
F_75 ( V_76 , V_74 ) ;
V_72 -> V_85 -- ;
}
F_72 ( & V_72 -> V_80 ) ;
}
}
int F_84 ( struct V_2 * V_3 )
{
struct V_71 * V_72 = & V_3 -> V_72 [ V_84 ] ;
int V_89 = 0 ;
F_69 ( & V_72 -> V_80 ) ;
if ( F_8 ( V_72 -> V_85 >= V_3 -> V_90 ) )
V_89 = - V_91 ;
else
V_72 -> V_85 ++ ;
F_72 ( & V_72 -> V_80 ) ;
return V_89 ;
}
void F_85 ( struct V_2 * V_3 )
{
struct V_71 * V_72 = & V_3 -> V_72 [ V_84 ] ;
F_69 ( & V_72 -> V_80 ) ;
F_86 ( V_3 , V_72 -> V_85 == 0 ) ;
V_72 -> V_85 -- ;
F_72 ( & V_72 -> V_80 ) ;
}
void F_87 ( struct V_2 * V_3 , T_3 V_70 )
{
F_66 ( V_3 , V_70 , V_84 ) ;
}
void F_88 ( struct V_2 * V_3 , T_3 V_70 )
{
F_76 ( V_3 , V_70 , V_84 ) ;
}
static int F_89 ( struct V_2 * V_3 , T_3 V_70 )
{
struct V_92 * V_92 ;
V_92 = F_90 ( V_3 -> V_93 , V_70 ) ;
if ( F_91 ( V_92 ) ) {
F_86 ( V_3 , F_92 ( V_92 ) == - V_94 ) ;
return F_92 ( V_92 ) ;
}
F_93 ( V_92 ) ;
F_94 ( V_92 ) ;
return 0 ;
}
int F_95 ( struct V_2 * V_3 )
{
T_2 V_95 , V_96 , V_61 , V_97 ;
int V_89 ;
if ( ! F_96 ( F_97 ( V_3 ) , V_98 ) )
return 0 ;
V_95 = F_21 ( V_3 ) + 1 + F_98 ( V_3 ) ;
V_96 = F_99 ( V_3 ) - 1 - F_98 ( V_3 ) ;
F_24 ( V_3 , V_95 , V_96 , V_24 , true ) ;
for ( V_61 = 0 ; V_61 < V_96 ; V_61 ++ ) {
struct V_1 * V_1 = F_14 ( V_3 , V_95 + V_61 ) ;
struct V_99 * V_100 ;
V_100 = (struct V_99 * ) F_100 ( V_1 ) ;
for ( V_97 = 0 ; V_97 < F_101 ( V_100 -> V_101 ) ; V_97 ++ ) {
T_3 V_70 = F_101 ( V_100 -> V_70 [ V_97 ] ) ;
V_89 = F_89 ( V_3 , V_70 ) ;
if ( V_89 ) {
F_11 ( V_1 , 1 ) ;
return V_89 ;
}
}
F_11 ( V_1 , 1 ) ;
}
F_102 ( F_97 ( V_3 ) , V_98 ) ;
return 0 ;
}
static void F_103 ( struct V_2 * V_3 , T_2 V_95 )
{
struct V_102 * V_103 ;
struct V_99 * V_100 = NULL ;
unsigned int V_104 = 0 ;
unsigned short V_4 = 1 ;
unsigned short V_96 ;
struct V_1 * V_1 = NULL ;
struct V_73 * V_105 = NULL ;
struct V_71 * V_72 = & V_3 -> V_72 [ V_84 ] ;
V_96 = F_104 ( V_72 -> V_85 ) ;
V_103 = & V_72 -> V_83 ;
F_105 (orphan, head, list) {
if ( ! V_1 ) {
V_1 = F_1 ( V_3 , V_95 ++ ) ;
V_100 =
(struct V_99 * ) F_100 ( V_1 ) ;
memset ( V_100 , 0 , sizeof( * V_100 ) ) ;
}
V_100 -> V_70 [ V_104 ++ ] = F_106 ( V_105 -> V_70 ) ;
if ( V_104 == V_106 ) {
V_100 -> V_16 = F_107 ( V_4 ) ;
V_100 -> V_107 = F_107 ( V_96 ) ;
V_100 -> V_101 = F_106 ( V_104 ) ;
F_108 ( V_1 ) ;
F_11 ( V_1 , 1 ) ;
V_4 ++ ;
V_104 = 0 ;
V_1 = NULL ;
}
}
if ( V_1 ) {
V_100 -> V_16 = F_107 ( V_4 ) ;
V_100 -> V_107 = F_107 ( V_96 ) ;
V_100 -> V_101 = F_106 ( V_104 ) ;
F_108 ( V_1 ) ;
F_11 ( V_1 , 1 ) ;
}
}
static struct V_1 * F_109 ( struct V_2 * V_3 ,
T_2 V_108 , unsigned long long * V_109 )
{
struct V_1 * V_110 , * V_111 = NULL ;
unsigned long V_112 = V_3 -> V_113 ;
struct V_114 * V_115 ;
unsigned long long V_116 = 0 , V_117 = 0 ;
T_4 V_118 ;
T_5 V_119 = 0 ;
V_110 = F_14 ( V_3 , V_108 ) ;
V_115 = (struct V_114 * ) F_100 ( V_110 ) ;
V_118 = F_101 ( V_115 -> V_120 ) ;
if ( V_118 >= V_112 )
goto V_121;
V_119 = F_101 ( * ( ( V_122 * ) ( ( unsigned char * ) V_115 + V_118 ) ) ) ;
if ( ! F_110 ( V_119 , V_115 , V_118 ) )
goto V_121;
V_117 = F_111 ( V_115 ) ;
V_108 += F_101 ( V_115 -> V_123 ) - 1 ;
V_111 = F_14 ( V_3 , V_108 ) ;
V_115 = (struct V_114 * ) F_100 ( V_111 ) ;
V_118 = F_101 ( V_115 -> V_120 ) ;
if ( V_118 >= V_112 )
goto V_124;
V_119 = F_101 ( * ( ( V_122 * ) ( ( unsigned char * ) V_115 + V_118 ) ) ) ;
if ( ! F_110 ( V_119 , V_115 , V_118 ) )
goto V_124;
V_116 = F_111 ( V_115 ) ;
if ( V_116 == V_117 ) {
* V_109 = V_116 ;
F_11 ( V_111 , 1 ) ;
return V_110 ;
}
V_124:
F_11 ( V_111 , 1 ) ;
V_121:
F_11 ( V_110 , 1 ) ;
return NULL ;
}
int F_112 ( struct V_2 * V_3 )
{
struct V_114 * V_115 ;
struct V_125 * V_126 = V_3 -> V_127 ;
struct V_1 * V_128 , * V_129 , * V_130 ;
unsigned long V_112 = V_3 -> V_113 ;
unsigned long long V_131 = 0 , V_132 = 0 ;
unsigned long long V_133 ;
unsigned int V_134 = 1 + F_98 ( V_3 ) ;
T_2 V_135 ;
int V_61 ;
V_3 -> V_136 = F_113 ( V_134 * V_112 , V_137 ) ;
if ( ! V_3 -> V_136 )
return - V_138 ;
V_133 = F_101 ( V_126 -> V_139 ) ;
V_128 = F_109 ( V_3 , V_133 , & V_131 ) ;
V_133 += ( ( unsigned long long ) 1 ) <<
F_101 ( V_126 -> V_140 ) ;
V_129 = F_109 ( V_3 , V_133 , & V_132 ) ;
if ( V_128 && V_129 ) {
if ( F_114 ( V_132 , V_131 ) )
V_130 = V_129 ;
else
V_130 = V_128 ;
} else if ( V_128 ) {
V_130 = V_128 ;
} else if ( V_129 ) {
V_130 = V_129 ;
} else {
goto V_141;
}
V_115 = (struct V_114 * ) F_100 ( V_130 ) ;
memcpy ( V_3 -> V_136 , V_115 , V_112 ) ;
if ( V_134 <= 1 )
goto V_142;
V_135 = F_101 ( V_126 -> V_139 ) ;
if ( V_130 == V_129 )
V_135 += 1 << F_101 ( V_126 -> V_140 ) ;
for ( V_61 = 1 ; V_61 < V_134 ; V_61 ++ ) {
void * V_143 ;
unsigned char * V_136 = ( unsigned char * ) V_3 -> V_136 ;
V_130 = F_14 ( V_3 , V_135 + V_61 ) ;
V_143 = F_100 ( V_130 ) ;
memcpy ( V_136 + V_61 * V_112 , V_143 , V_112 ) ;
F_11 ( V_130 , 1 ) ;
}
V_142:
F_11 ( V_128 , 1 ) ;
F_11 ( V_129 , 1 ) ;
return 0 ;
V_141:
F_115 ( V_3 -> V_136 ) ;
return - V_144 ;
}
static int F_116 ( struct V_92 * V_92 , struct V_145 * V_146 )
{
struct V_2 * V_3 = F_117 ( V_92 ) ;
if ( F_118 ( F_119 ( V_92 ) , V_147 ) )
return - V_148 ;
F_120 ( F_119 ( V_92 ) , V_147 ) ;
F_119 ( V_92 ) -> V_149 = V_146 ;
F_74 ( & V_146 -> V_82 , & V_3 -> V_150 ) ;
F_121 ( V_3 ) ;
return 0 ;
}
void F_122 ( struct V_92 * V_92 , struct V_1 * V_1 )
{
struct V_2 * V_3 = F_117 ( V_92 ) ;
struct V_145 * V_146 ;
int V_151 = 0 ;
if ( ! F_123 ( V_92 -> V_152 ) && ! F_124 ( V_92 -> V_152 ) &&
! F_125 ( V_92 -> V_152 ) )
return;
if ( ! F_123 ( V_92 -> V_152 ) ) {
F_126 ( V_92 ) ;
goto V_18;
}
V_146 = F_67 ( V_153 , V_77 ) ;
V_146 -> V_92 = V_92 ;
F_127 ( & V_146 -> V_82 ) ;
F_69 ( & V_3 -> V_154 ) ;
V_151 = F_116 ( V_92 , V_146 ) ;
F_126 ( V_92 ) ;
F_72 ( & V_3 -> V_154 ) ;
if ( V_151 )
F_75 ( V_153 , V_146 ) ;
V_18:
F_64 ( V_1 ) ;
F_65 ( V_1 ) ;
}
void F_128 ( struct V_92 * V_92 )
{
struct V_2 * V_3 = F_117 ( V_92 ) ;
struct V_145 * V_146 =
F_67 ( V_153 , V_77 ) ;
int V_151 = 0 ;
V_146 -> V_92 = V_92 ;
F_127 ( & V_146 -> V_82 ) ;
F_69 ( & V_3 -> V_154 ) ;
V_151 = F_116 ( V_92 , V_146 ) ;
F_72 ( & V_3 -> V_154 ) ;
if ( V_151 )
F_75 ( V_153 , V_146 ) ;
}
void F_129 ( struct V_92 * V_92 )
{
struct V_2 * V_3 = F_117 ( V_92 ) ;
struct V_145 * V_155 ;
if ( ! F_123 ( V_92 -> V_152 ) )
return;
F_69 ( & V_3 -> V_154 ) ;
if ( F_130 ( V_92 ) ||
! F_118 ( F_119 ( V_92 ) , V_147 ) ) {
F_72 ( & V_3 -> V_154 ) ;
return;
}
V_155 = F_119 ( V_92 ) -> V_149 ;
F_77 ( & V_155 -> V_82 ) ;
F_119 ( V_92 ) -> V_149 = NULL ;
F_131 ( F_119 ( V_92 ) , V_147 ) ;
F_132 ( V_3 ) ;
F_72 ( & V_3 -> V_154 ) ;
F_75 ( V_153 , V_155 ) ;
if ( F_118 ( F_119 ( V_92 ) , V_156 ) ) {
F_131 ( F_119 ( V_92 ) , V_156 ) ;
F_94 ( V_92 ) ;
}
}
void F_133 ( struct V_2 * V_3 )
{
struct V_102 * V_103 ;
struct V_145 * V_155 ;
struct V_92 * V_92 ;
V_78:
if ( F_8 ( F_39 ( V_3 ) ) )
return;
F_69 ( & V_3 -> V_154 ) ;
V_103 = & V_3 -> V_150 ;
if ( F_134 ( V_103 ) ) {
F_72 ( & V_3 -> V_154 ) ;
return;
}
V_155 = F_135 ( V_103 -> V_157 , struct V_145 , V_82 ) ;
V_92 = F_136 ( V_155 -> V_92 ) ;
F_72 ( & V_3 -> V_154 ) ;
if ( V_92 ) {
F_137 ( V_92 -> V_158 ) ;
F_94 ( V_92 ) ;
} else {
F_30 ( V_3 , V_159 , V_44 ) ;
F_4 () ;
}
goto V_78;
}
static int F_138 ( struct V_2 * V_3 )
{
struct V_38 V_39 = {
. V_160 = V_161 ,
. V_52 = V_56 ,
. V_42 = 0 ,
} ;
struct V_162 V_163 ;
int V_89 = 0 ;
F_139 ( & V_163 ) ;
V_164:
F_140 ( V_3 ) ;
if ( F_47 ( V_3 , V_165 ) ) {
F_141 ( V_3 ) ;
F_133 ( V_3 ) ;
if ( F_8 ( F_39 ( V_3 ) ) ) {
V_89 = - V_166 ;
goto V_18;
}
goto V_164;
}
V_167:
F_142 ( & V_3 -> V_168 ) ;
if ( F_47 ( V_3 , V_169 ) ) {
F_143 ( & V_3 -> V_168 ) ;
F_144 ( V_3 , 0 , & V_39 ) ;
if ( F_8 ( F_39 ( V_3 ) ) ) {
F_141 ( V_3 ) ;
V_89 = - V_166 ;
goto V_18;
}
goto V_167;
}
V_18:
F_145 ( & V_163 ) ;
return V_89 ;
}
static void F_146 ( struct V_2 * V_3 )
{
F_143 ( & V_3 -> V_168 ) ;
F_141 ( V_3 ) ;
}
static void F_147 ( struct V_2 * V_3 )
{
F_148 ( V_170 ) ;
for (; ; ) {
F_149 ( & V_3 -> V_171 , & V_170 , V_172 ) ;
if ( ! F_47 ( V_3 , V_173 ) )
break;
F_150 () ;
}
F_151 ( & V_3 -> V_171 , & V_170 ) ;
}
static void F_152 ( struct V_2 * V_3 , struct V_174 * V_175 )
{
struct V_114 * V_136 = F_97 ( V_3 ) ;
struct V_176 * V_177 = F_153 ( V_3 , V_178 ) ;
struct V_179 * V_180 = F_26 ( V_3 ) ;
unsigned long V_181 = V_3 -> V_72 [ V_84 ] . V_85 ;
T_3 V_182 = V_180 -> V_183 ;
T_2 V_95 ;
unsigned int V_184 , V_96 ;
T_5 V_185 = 0 ;
int V_61 ;
int V_186 = F_98 ( V_3 ) ;
T_2 V_187 = F_154 ( V_3 , V_177 ) ;
bool V_188 = false ;
if ( F_155 ( V_3 , V_187 ) )
V_188 = true ;
while ( F_47 ( V_3 , V_43 ) ) {
F_51 ( V_3 , V_8 , V_56 ) ;
if ( F_8 ( F_39 ( V_3 ) ) )
return;
}
F_156 ( V_3 , & V_182 ) ;
V_136 -> V_189 = F_157 ( F_158 ( V_3 ) ) ;
V_136 -> V_190 = F_157 ( F_159 ( V_3 ) ) ;
V_136 -> V_191 = F_106 ( F_160 ( V_3 ) ) ;
for ( V_61 = 0 ; V_61 < V_192 ; V_61 ++ ) {
V_136 -> V_193 [ V_61 ] =
F_106 ( F_161 ( V_3 , V_61 + V_194 ) ) ;
V_136 -> V_195 [ V_61 ] =
F_107 ( F_162 ( V_3 , V_61 + V_194 ) ) ;
V_136 -> V_196 [ V_61 + V_194 ] =
F_163 ( V_3 , V_61 + V_194 ) ;
}
for ( V_61 = 0 ; V_61 < V_197 ; V_61 ++ ) {
V_136 -> V_198 [ V_61 ] =
F_106 ( F_161 ( V_3 , V_61 + V_199 ) ) ;
V_136 -> V_200 [ V_61 ] =
F_107 ( F_162 ( V_3 , V_61 + V_199 ) ) ;
V_136 -> V_196 [ V_61 + V_199 ] =
F_163 ( V_3 , V_61 + V_199 ) ;
}
V_136 -> V_201 = F_106 ( V_201 ( V_3 ) ) ;
V_136 -> V_202 = F_106 ( V_202 ( V_3 ) ) ;
V_136 -> F_156 = F_106 ( V_182 ) ;
V_184 = F_164 ( V_3 , false ) ;
if ( V_184 < V_197 )
F_165 ( V_136 , V_203 ) ;
else
F_102 ( V_136 , V_203 ) ;
V_96 = F_104 ( V_181 ) ;
V_136 -> V_204 = F_106 ( 1 + V_186 +
V_96 ) ;
if ( F_166 ( V_175 -> V_205 ) )
V_136 -> V_123 = F_106 ( V_206 +
V_186 + V_184 +
V_96 + V_192 ) ;
else
V_136 -> V_123 = F_106 ( V_206 +
V_186 + V_184 +
V_96 ) ;
if ( V_175 -> V_205 == V_207 )
F_165 ( V_136 , V_208 ) ;
else
F_102 ( V_136 , V_208 ) ;
if ( V_175 -> V_205 == V_209 )
F_165 ( V_136 , V_210 ) ;
else
F_102 ( V_136 , V_210 ) ;
if ( V_181 )
F_165 ( V_136 , V_98 ) ;
else
F_102 ( V_136 , V_98 ) ;
if ( F_37 ( V_3 , V_211 ) )
F_165 ( V_136 , V_212 ) ;
F_167 ( V_3 , F_168 ( V_3 , V_213 ) ) ;
F_169 ( V_3 , F_168 ( V_3 , V_214 ) ) ;
V_185 = F_170 ( V_136 , F_101 ( V_136 -> V_120 ) ) ;
* ( ( V_122 * ) ( ( unsigned char * ) V_136 +
F_101 ( V_136 -> V_120 ) ) )
= F_106 ( V_185 ) ;
V_95 = F_21 ( V_3 ) ;
F_147 ( V_3 ) ;
if ( F_8 ( F_39 ( V_3 ) ) )
return;
F_171 ( V_3 , V_136 , V_95 ++ ) ;
for ( V_61 = 1 ; V_61 < 1 + V_186 ; V_61 ++ )
F_171 ( V_3 , ( char * ) V_136 + V_61 * V_215 ,
V_95 ++ ) ;
if ( V_181 ) {
F_103 ( V_3 , V_95 ) ;
V_95 += V_96 ;
}
F_172 ( V_3 , V_95 ) ;
V_95 += V_184 ;
if ( F_166 ( V_175 -> V_205 ) ) {
F_173 ( V_3 , V_95 ) ;
V_95 += V_192 ;
}
F_171 ( V_3 , V_136 , V_95 ) ;
F_147 ( V_3 ) ;
if ( F_8 ( F_39 ( V_3 ) ) )
return;
F_174 ( F_175 ( V_3 ) , 0 , V_56 ) ;
F_174 ( F_2 ( V_3 ) , 0 , V_56 ) ;
V_3 -> V_216 = V_3 -> V_217 ;
V_3 -> V_218 = 0 ;
F_51 ( V_3 , V_219 , V_56 ) ;
F_147 ( V_3 ) ;
if ( V_188 )
F_176 ( F_2 ( V_3 ) , V_187 ,
V_187 ) ;
F_82 ( V_3 ) ;
if ( F_8 ( F_39 ( V_3 ) ) )
return;
F_177 ( V_3 , V_175 ) ;
F_178 ( V_3 , V_220 ) ;
}
void F_179 ( struct V_2 * V_3 , struct V_174 * V_175 )
{
struct V_114 * V_136 = F_97 ( V_3 ) ;
unsigned long long V_221 ;
F_49 ( & V_3 -> V_51 ) ;
if ( ! F_37 ( V_3 , V_220 ) &&
( V_175 -> V_205 == V_209 || V_175 -> V_205 == V_222 ||
( V_175 -> V_205 == V_223 && ! V_3 -> V_224 ) ) )
goto V_18;
if ( F_8 ( F_39 ( V_3 ) ) )
goto V_18;
if ( F_180 ( V_3 -> V_93 ) )
goto V_18;
F_181 ( V_3 -> V_93 , V_175 -> V_205 , L_1 ) ;
if ( F_138 ( V_3 ) )
goto V_18;
F_181 ( V_3 -> V_93 , V_175 -> V_205 , L_2 ) ;
F_30 ( V_3 , V_159 , V_44 ) ;
F_30 ( V_3 , V_225 , V_44 ) ;
F_30 ( V_3 , V_8 , V_44 ) ;
V_221 = F_111 ( V_136 ) ;
V_136 -> V_226 = F_157 ( ++ V_221 ) ;
F_182 ( V_3 ) ;
F_183 ( V_3 , V_175 ) ;
F_152 ( V_3 , V_175 ) ;
F_146 ( V_3 ) ;
F_184 ( V_3 -> V_227 ) ;
if ( V_175 -> V_205 == V_228 )
F_185 ( V_3 -> V_93 , V_229 ,
L_3 , V_221 ) ;
V_3 -> V_230 = F_186 ( V_231 + V_232 * V_3 -> V_233 ) ;
V_18:
F_52 ( & V_3 -> V_51 ) ;
F_181 ( V_3 -> V_93 , V_175 -> V_205 , L_4 ) ;
}
void F_187 ( struct V_2 * V_3 )
{
int V_61 ;
for ( V_61 = 0 ; V_61 < V_234 ; V_61 ++ ) {
struct V_71 * V_72 = & V_3 -> V_72 [ V_61 ] ;
F_188 ( & V_72 -> V_81 , V_235 ) ;
F_189 ( & V_72 -> V_80 ) ;
F_127 ( & V_72 -> V_83 ) ;
V_72 -> V_85 = 0 ;
}
V_3 -> V_90 = ( V_3 -> V_236 - V_206 -
V_237 - F_98 ( V_3 ) ) *
V_106 ;
}
int T_6 F_190 ( void )
{
V_76 = F_191 ( L_5 ,
sizeof( struct V_73 ) ) ;
if ( ! V_76 )
return - V_138 ;
V_153 = F_191 ( L_6 ,
sizeof( struct V_145 ) ) ;
if ( ! V_153 ) {
F_192 ( V_76 ) ;
return - V_138 ;
}
return 0 ;
}
void F_193 ( void )
{
F_192 ( V_76 ) ;
F_192 ( V_153 ) ;
}
