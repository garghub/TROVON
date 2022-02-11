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
struct V_1 * F_7 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_1 ;
struct V_9 V_10 = {
. V_3 = V_3 ,
. type = V_8 ,
. V_11 = V_12 | V_13 | V_14 ,
. V_15 = V_4 ,
. V_16 = NULL ,
} ;
V_7:
V_1 = F_3 ( V_6 , V_4 ) ;
if ( ! V_1 ) {
F_4 () ;
goto V_7;
}
if ( F_8 ( V_1 ) )
goto V_17;
V_10 . V_1 = V_1 ;
if ( F_9 ( & V_10 ) ) {
F_10 ( V_1 , 1 ) ;
goto V_7;
}
F_11 ( V_1 ) ;
if ( F_12 ( V_1 -> V_6 != V_6 ) ) {
F_10 ( V_1 , 1 ) ;
goto V_7;
}
if ( F_12 ( ! F_8 ( V_1 ) ) )
F_13 ( V_3 ) ;
V_17:
return V_1 ;
}
bool F_14 ( struct V_2 * V_3 , T_2 V_18 , int type )
{
switch ( type ) {
case V_19 :
break;
case V_20 :
if ( F_12 ( V_18 >= F_15 ( V_3 ) ) )
return false ;
break;
case V_21 :
if ( F_12 ( V_18 >= F_16 ( V_3 ) ||
V_18 < F_17 ( V_3 ) -> V_22 ) )
return false ;
break;
case V_23 :
if ( F_12 ( V_18 >= F_18 ( V_3 ) -> V_24 ||
V_18 < F_19 ( V_3 ) ) )
return false ;
break;
case V_25 :
if ( F_12 ( V_18 >= F_20 ( V_3 ) ||
V_18 < F_16 ( V_3 ) ) )
return false ;
break;
default:
F_21 () ;
}
return true ;
}
int F_22 ( struct V_2 * V_3 , T_2 V_26 , int V_27 , int type )
{
T_2 V_28 = 0 ;
struct V_1 * V_1 ;
T_2 V_29 = V_26 ;
struct V_9 V_10 = {
. V_3 = V_3 ,
. type = V_8 ,
. V_11 = V_12 | V_13 | V_14 ,
. V_16 = NULL ,
} ;
for (; V_27 -- > 0 ; V_29 ++ ) {
if ( ! F_14 ( V_3 , V_29 , type ) )
goto V_17;
switch ( type ) {
case V_19 :
if ( F_12 ( V_29 >=
F_23 ( F_24 ( V_3 ) -> V_30 ) ) )
V_29 = 0 ;
V_10 . V_15 = F_25 ( V_3 ,
V_29 * V_31 ) ;
break;
case V_20 :
V_10 . V_15 = F_26 ( V_3 ,
V_29 * V_32 ) ;
if ( V_29 != V_26 && V_28 + 1 != V_10 . V_15 )
goto V_17;
V_28 = V_10 . V_15 ;
break;
case V_21 :
case V_23 :
case V_25 :
V_10 . V_15 = V_29 ;
break;
default:
F_21 () ;
}
V_1 = F_3 ( F_2 ( V_3 ) , V_10 . V_15 ) ;
if ( ! V_1 )
continue;
if ( F_8 ( V_1 ) ) {
F_10 ( V_1 , 1 ) ;
continue;
}
V_10 . V_1 = V_1 ;
F_27 ( & V_10 ) ;
F_10 ( V_1 , 0 ) ;
}
V_17:
F_28 ( V_3 , V_8 , V_33 ) ;
return V_29 - V_26 ;
}
void F_29 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_1 ;
bool V_34 = false ;
V_1 = F_30 ( F_2 ( V_3 ) , V_4 ) ;
if ( ! V_1 || ( V_1 && ! F_8 ( V_1 ) ) )
V_34 = true ;
F_10 ( V_1 , 0 ) ;
if ( V_34 )
F_22 ( V_3 , V_4 , F_31 ( V_3 ) , V_25 ) ;
}
static int F_32 ( struct V_1 * V_1 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_33 ( V_1 ) ;
F_34 ( V_1 , V_8 ) ;
if ( F_12 ( F_35 ( V_3 , V_37 ) ) )
goto V_38;
if ( V_36 -> V_39 && V_1 -> V_4 < F_36 ( V_3 , 0 ) )
goto V_38;
if ( F_12 ( F_37 ( V_3 ) ) )
goto V_38;
F_5 ( V_1 , V_8 ) ;
F_38 ( V_3 , V_1 ) ;
F_39 ( V_3 , V_40 ) ;
F_40 ( V_1 ) ;
if ( V_36 -> V_39 )
F_28 ( V_3 , V_8 , V_41 ) ;
return 0 ;
V_38:
F_41 ( V_36 , V_1 ) ;
return V_42 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_35 * V_36 )
{
struct V_2 * V_3 = F_43 ( V_6 ) ;
long V_43 , V_44 ;
F_44 ( V_6 -> V_45 , V_36 , V_8 ) ;
if ( V_36 -> V_46 ||
F_45 ( V_3 , V_40 ) < F_46 ( V_3 , V_8 ) )
goto V_47;
F_47 ( & V_3 -> V_48 ) ;
V_43 = F_48 ( V_3 , V_8 , V_36 ) ;
V_44 = F_49 ( V_3 , V_8 , V_36 -> V_49 ) ;
F_50 ( & V_3 -> V_48 ) ;
V_36 -> V_49 = F_51 ( ( long ) 0 , V_36 -> V_49 - V_44 - V_43 ) ;
return 0 ;
V_47:
V_36 -> V_50 += F_45 ( V_3 , V_40 ) ;
return 0 ;
}
long F_49 ( struct V_2 * V_3 , enum V_51 type ,
long V_49 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
T_1 V_4 = 0 , V_52 = V_53 ;
struct V_54 V_55 ;
long V_56 = 0 ;
struct V_35 V_36 = {
. V_39 = 0 ,
} ;
F_52 ( & V_55 , 0 ) ;
while ( V_4 <= V_52 ) {
int V_57 , V_58 ;
V_58 = F_53 ( & V_55 , V_6 , & V_4 ,
V_59 ,
F_54 ( V_52 - V_4 , ( T_1 ) V_60 - 1 ) + 1 ) ;
if ( F_12 ( V_58 == 0 ) )
break;
for ( V_57 = 0 ; V_57 < V_58 ; V_57 ++ ) {
struct V_1 * V_1 = V_55 . V_61 [ V_57 ] ;
F_11 ( V_1 ) ;
if ( F_12 ( V_1 -> V_6 != V_6 ) ) {
V_62:
F_40 ( V_1 ) ;
continue;
}
if ( ! F_55 ( V_1 ) ) {
goto V_62;
}
if ( ! F_56 ( V_1 ) )
goto V_62;
if ( V_6 -> V_63 -> V_64 ( V_1 , & V_36 ) ) {
F_40 ( V_1 ) ;
break;
}
V_56 ++ ;
if ( F_12 ( V_56 >= V_49 ) )
break;
}
F_57 ( & V_55 ) ;
F_4 () ;
}
if ( V_56 )
F_28 ( V_3 , type , V_41 ) ;
return V_56 ;
}
static int F_58 ( struct V_1 * V_1 )
{
F_59 ( V_1 , V_8 ) ;
F_6 ( V_1 ) ;
if ( ! F_55 ( V_1 ) ) {
F_60 ( V_1 ) ;
F_61 ( F_33 ( V_1 ) , V_40 ) ;
F_62 ( V_1 ) ;
F_63 ( V_1 ) ;
return 1 ;
}
return 0 ;
}
static void F_64 ( struct V_2 * V_3 , T_3 V_65 , int type )
{
struct V_66 * V_67 = & V_3 -> V_67 [ type ] ;
struct V_68 * V_69 , * V_70 ;
V_70 = F_65 ( V_71 , V_72 ) ;
V_73:
F_66 ( V_72 | V_74 ) ;
F_67 ( & V_67 -> V_75 ) ;
V_69 = F_68 ( & V_67 -> V_76 , V_65 ) ;
if ( ! V_69 ) {
V_69 = V_70 ;
if ( F_69 ( & V_67 -> V_76 , V_65 , V_69 ) ) {
F_70 ( & V_67 -> V_75 ) ;
F_71 () ;
goto V_73;
}
memset ( V_69 , 0 , sizeof( struct V_68 ) ) ;
V_69 -> V_65 = V_65 ;
F_72 ( & V_69 -> V_77 , & V_67 -> V_78 ) ;
if ( type != V_79 )
V_67 -> V_80 ++ ;
}
F_70 ( & V_67 -> V_75 ) ;
F_71 () ;
if ( V_69 != V_70 )
F_73 ( V_71 , V_70 ) ;
}
static void F_74 ( struct V_2 * V_3 , T_3 V_65 , int type )
{
struct V_66 * V_67 = & V_3 -> V_67 [ type ] ;
struct V_68 * V_69 ;
F_67 ( & V_67 -> V_75 ) ;
V_69 = F_68 ( & V_67 -> V_76 , V_65 ) ;
if ( V_69 ) {
F_75 ( & V_69 -> V_77 ) ;
F_76 ( & V_67 -> V_76 , V_65 ) ;
V_67 -> V_80 -- ;
F_70 ( & V_67 -> V_75 ) ;
F_73 ( V_71 , V_69 ) ;
return;
}
F_70 ( & V_67 -> V_75 ) ;
}
void F_77 ( struct V_2 * V_3 , T_3 V_65 , int type )
{
F_64 ( V_3 , V_65 , type ) ;
}
void F_78 ( struct V_2 * V_3 , T_3 V_65 , int type )
{
F_74 ( V_3 , V_65 , type ) ;
}
bool F_79 ( struct V_2 * V_3 , T_3 V_65 , int V_81 )
{
struct V_66 * V_67 = & V_3 -> V_67 [ V_81 ] ;
struct V_68 * V_69 ;
F_67 ( & V_67 -> V_75 ) ;
V_69 = F_68 ( & V_67 -> V_76 , V_65 ) ;
F_70 ( & V_67 -> V_75 ) ;
return V_69 ? true : false ;
}
void F_80 ( struct V_2 * V_3 )
{
struct V_68 * V_69 , * V_70 ;
int V_57 ;
for ( V_57 = V_82 ; V_57 <= V_83 ; V_57 ++ ) {
struct V_66 * V_67 = & V_3 -> V_67 [ V_57 ] ;
F_67 ( & V_67 -> V_75 ) ;
F_81 (e, tmp, &im->ino_list, list) {
F_75 ( & V_69 -> V_77 ) ;
F_76 ( & V_67 -> V_76 , V_69 -> V_65 ) ;
F_73 ( V_71 , V_69 ) ;
V_67 -> V_80 -- ;
}
F_70 ( & V_67 -> V_75 ) ;
}
}
int F_82 ( struct V_2 * V_3 )
{
struct V_66 * V_67 = & V_3 -> V_67 [ V_79 ] ;
int V_84 = 0 ;
F_67 ( & V_67 -> V_75 ) ;
if ( F_12 ( V_67 -> V_80 >= V_3 -> V_85 ) )
V_84 = - V_86 ;
else
V_67 -> V_80 ++ ;
F_70 ( & V_67 -> V_75 ) ;
return V_84 ;
}
void F_83 ( struct V_2 * V_3 )
{
struct V_66 * V_67 = & V_3 -> V_67 [ V_79 ] ;
F_67 ( & V_67 -> V_75 ) ;
F_84 ( V_3 , V_67 -> V_80 == 0 ) ;
V_67 -> V_80 -- ;
F_70 ( & V_67 -> V_75 ) ;
}
void F_85 ( struct V_2 * V_3 , T_3 V_65 )
{
F_64 ( V_3 , V_65 , V_79 ) ;
}
void F_86 ( struct V_2 * V_3 , T_3 V_65 )
{
F_74 ( V_3 , V_65 , V_79 ) ;
}
static int F_87 ( struct V_2 * V_3 , T_3 V_65 )
{
struct V_87 * V_87 ;
V_87 = F_88 ( V_3 -> V_88 , V_65 ) ;
if ( F_89 ( V_87 ) ) {
F_84 ( V_3 , F_90 ( V_87 ) == - V_89 ) ;
return F_90 ( V_87 ) ;
}
F_91 ( V_87 ) ;
F_92 ( V_87 ) ;
return 0 ;
}
int F_93 ( struct V_2 * V_3 )
{
T_2 V_90 , V_91 , V_57 , V_92 ;
int V_84 ;
if ( ! F_94 ( F_95 ( V_3 ) , V_93 ) )
return 0 ;
V_90 = F_19 ( V_3 ) + 1 + F_96 ( V_3 ) ;
V_91 = F_97 ( V_3 ) - 1 - F_96 ( V_3 ) ;
F_22 ( V_3 , V_90 , V_91 , V_23 ) ;
for ( V_57 = 0 ; V_57 < V_91 ; V_57 ++ ) {
struct V_1 * V_1 = F_7 ( V_3 , V_90 + V_57 ) ;
struct V_94 * V_95 ;
V_95 = (struct V_94 * ) F_98 ( V_1 ) ;
for ( V_92 = 0 ; V_92 < F_99 ( V_95 -> V_96 ) ; V_92 ++ ) {
T_3 V_65 = F_99 ( V_95 -> V_65 [ V_92 ] ) ;
V_84 = F_87 ( V_3 , V_65 ) ;
if ( V_84 ) {
F_10 ( V_1 , 1 ) ;
return V_84 ;
}
}
F_10 ( V_1 , 1 ) ;
}
F_100 ( F_95 ( V_3 ) , V_93 ) ;
return 0 ;
}
static void F_101 ( struct V_2 * V_3 , T_2 V_90 )
{
struct V_97 * V_98 ;
struct V_94 * V_95 = NULL ;
unsigned int V_99 = 0 ;
unsigned short V_4 = 1 ;
unsigned short V_91 ;
struct V_1 * V_1 = NULL ;
struct V_68 * V_100 = NULL ;
struct V_66 * V_67 = & V_3 -> V_67 [ V_79 ] ;
V_91 = F_102 ( V_67 -> V_80 ) ;
V_98 = & V_67 -> V_78 ;
F_103 (orphan, head, list) {
if ( ! V_1 ) {
V_1 = F_1 ( V_3 , V_90 ++ ) ;
V_95 =
(struct V_94 * ) F_98 ( V_1 ) ;
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
}
V_95 -> V_65 [ V_99 ++ ] = F_104 ( V_100 -> V_65 ) ;
if ( V_99 == V_101 ) {
V_95 -> V_15 = F_105 ( V_4 ) ;
V_95 -> V_102 = F_105 ( V_91 ) ;
V_95 -> V_96 = F_104 ( V_99 ) ;
F_106 ( V_1 ) ;
F_10 ( V_1 , 1 ) ;
V_4 ++ ;
V_99 = 0 ;
V_1 = NULL ;
}
}
if ( V_1 ) {
V_95 -> V_15 = F_105 ( V_4 ) ;
V_95 -> V_102 = F_105 ( V_91 ) ;
V_95 -> V_96 = F_104 ( V_99 ) ;
F_106 ( V_1 ) ;
F_10 ( V_1 , 1 ) ;
}
}
static struct V_1 * F_107 ( struct V_2 * V_3 ,
T_2 V_103 , unsigned long long * V_104 )
{
struct V_1 * V_105 , * V_106 = NULL ;
unsigned long V_107 = V_3 -> V_108 ;
struct V_109 * V_110 ;
unsigned long long V_111 = 0 , V_112 = 0 ;
T_4 V_113 ;
T_5 V_114 = 0 ;
V_105 = F_7 ( V_3 , V_103 ) ;
V_110 = (struct V_109 * ) F_98 ( V_105 ) ;
V_113 = F_99 ( V_110 -> V_115 ) ;
if ( V_113 >= V_107 )
goto V_116;
V_114 = F_99 ( * ( ( V_117 * ) ( ( unsigned char * ) V_110 + V_113 ) ) ) ;
if ( ! F_108 ( V_114 , V_110 , V_113 ) )
goto V_116;
V_112 = F_109 ( V_110 ) ;
V_103 += F_99 ( V_110 -> V_118 ) - 1 ;
V_106 = F_7 ( V_3 , V_103 ) ;
V_110 = (struct V_109 * ) F_98 ( V_106 ) ;
V_113 = F_99 ( V_110 -> V_115 ) ;
if ( V_113 >= V_107 )
goto V_119;
V_114 = F_99 ( * ( ( V_117 * ) ( ( unsigned char * ) V_110 + V_113 ) ) ) ;
if ( ! F_108 ( V_114 , V_110 , V_113 ) )
goto V_119;
V_111 = F_109 ( V_110 ) ;
if ( V_111 == V_112 ) {
* V_104 = V_111 ;
F_10 ( V_106 , 1 ) ;
return V_105 ;
}
V_119:
F_10 ( V_106 , 1 ) ;
V_116:
F_10 ( V_105 , 1 ) ;
return NULL ;
}
int F_110 ( struct V_2 * V_3 )
{
struct V_109 * V_110 ;
struct V_120 * V_121 = V_3 -> V_122 ;
struct V_1 * V_123 , * V_124 , * V_125 ;
unsigned long V_107 = V_3 -> V_108 ;
unsigned long long V_126 = 0 , V_127 = 0 ;
unsigned long long V_128 ;
unsigned int V_129 = 1 + F_96 ( V_3 ) ;
T_2 V_130 ;
int V_57 ;
V_3 -> V_131 = F_111 ( V_129 * V_107 , V_132 ) ;
if ( ! V_3 -> V_131 )
return - V_133 ;
V_128 = F_99 ( V_121 -> V_134 ) ;
V_123 = F_107 ( V_3 , V_128 , & V_126 ) ;
V_128 += ( ( unsigned long long ) 1 ) <<
F_99 ( V_121 -> V_135 ) ;
V_124 = F_107 ( V_3 , V_128 , & V_127 ) ;
if ( V_123 && V_124 ) {
if ( F_112 ( V_127 , V_126 ) )
V_125 = V_124 ;
else
V_125 = V_123 ;
} else if ( V_123 ) {
V_125 = V_123 ;
} else if ( V_124 ) {
V_125 = V_124 ;
} else {
goto V_136;
}
V_110 = (struct V_109 * ) F_98 ( V_125 ) ;
memcpy ( V_3 -> V_131 , V_110 , V_107 ) ;
if ( V_129 <= 1 )
goto V_137;
V_130 = F_99 ( V_121 -> V_134 ) ;
if ( V_125 == V_124 )
V_130 += 1 << F_99 ( V_121 -> V_135 ) ;
for ( V_57 = 1 ; V_57 < V_129 ; V_57 ++ ) {
void * V_138 ;
unsigned char * V_131 = ( unsigned char * ) V_3 -> V_131 ;
V_125 = F_7 ( V_3 , V_130 + V_57 ) ;
V_138 = F_98 ( V_125 ) ;
memcpy ( V_131 + V_57 * V_107 , V_138 , V_107 ) ;
F_10 ( V_125 , 1 ) ;
}
V_137:
F_10 ( V_123 , 1 ) ;
F_10 ( V_124 , 1 ) ;
return 0 ;
V_136:
F_113 ( V_3 -> V_131 ) ;
return - V_139 ;
}
static int F_114 ( struct V_87 * V_87 , struct V_140 * V_141 )
{
struct V_2 * V_3 = F_115 ( V_87 ) ;
if ( F_116 ( F_117 ( V_87 ) , V_142 ) )
return - V_143 ;
F_118 ( F_117 ( V_87 ) , V_142 ) ;
F_117 ( V_87 ) -> V_144 = V_141 ;
F_72 ( & V_141 -> V_77 , & V_3 -> V_145 ) ;
F_119 ( V_3 ) ;
return 0 ;
}
void F_120 ( struct V_87 * V_87 , struct V_1 * V_1 )
{
struct V_2 * V_3 = F_115 ( V_87 ) ;
struct V_140 * V_141 ;
int V_146 = 0 ;
if ( ! F_121 ( V_87 -> V_147 ) && ! F_122 ( V_87 -> V_147 ) &&
! F_123 ( V_87 -> V_147 ) )
return;
if ( ! F_121 ( V_87 -> V_147 ) ) {
F_124 ( V_87 ) ;
goto V_17;
}
V_141 = F_65 ( V_148 , V_72 ) ;
V_141 -> V_87 = V_87 ;
F_125 ( & V_141 -> V_77 ) ;
F_67 ( & V_3 -> V_149 ) ;
V_146 = F_114 ( V_87 , V_141 ) ;
F_124 ( V_87 ) ;
F_70 ( & V_3 -> V_149 ) ;
if ( V_146 )
F_73 ( V_148 , V_141 ) ;
V_17:
F_62 ( V_1 ) ;
F_63 ( V_1 ) ;
}
void F_126 ( struct V_87 * V_87 )
{
struct V_2 * V_3 = F_115 ( V_87 ) ;
struct V_140 * V_141 =
F_65 ( V_148 , V_72 ) ;
int V_146 = 0 ;
V_141 -> V_87 = V_87 ;
F_125 ( & V_141 -> V_77 ) ;
F_67 ( & V_3 -> V_149 ) ;
V_146 = F_114 ( V_87 , V_141 ) ;
F_70 ( & V_3 -> V_149 ) ;
if ( V_146 )
F_73 ( V_148 , V_141 ) ;
}
void F_127 ( struct V_87 * V_87 )
{
struct V_2 * V_3 = F_115 ( V_87 ) ;
struct V_140 * V_150 ;
if ( ! F_121 ( V_87 -> V_147 ) )
return;
F_67 ( & V_3 -> V_149 ) ;
if ( F_128 ( V_87 ) ||
! F_116 ( F_117 ( V_87 ) , V_142 ) ) {
F_70 ( & V_3 -> V_149 ) ;
return;
}
V_150 = F_117 ( V_87 ) -> V_144 ;
F_75 ( & V_150 -> V_77 ) ;
F_117 ( V_87 ) -> V_144 = NULL ;
F_129 ( F_117 ( V_87 ) , V_142 ) ;
F_130 ( V_3 ) ;
F_70 ( & V_3 -> V_149 ) ;
F_73 ( V_148 , V_150 ) ;
if ( F_116 ( F_117 ( V_87 ) , V_151 ) ) {
F_129 ( F_117 ( V_87 ) , V_151 ) ;
F_92 ( V_87 ) ;
}
}
void F_131 ( struct V_2 * V_3 )
{
struct V_97 * V_98 ;
struct V_140 * V_150 ;
struct V_87 * V_87 ;
V_73:
if ( F_12 ( F_37 ( V_3 ) ) )
return;
F_67 ( & V_3 -> V_149 ) ;
V_98 = & V_3 -> V_145 ;
if ( F_132 ( V_98 ) ) {
F_70 ( & V_3 -> V_149 ) ;
return;
}
V_150 = F_133 ( V_98 -> V_152 , struct V_140 , V_77 ) ;
V_87 = F_134 ( V_150 -> V_87 ) ;
F_70 ( & V_3 -> V_149 ) ;
if ( V_87 ) {
F_135 ( V_87 -> V_153 ) ;
F_92 ( V_87 ) ;
} else {
F_28 ( V_3 , V_154 , V_41 ) ;
F_4 () ;
}
goto V_73;
}
static int F_136 ( struct V_2 * V_3 )
{
struct V_35 V_36 = {
. V_155 = V_156 ,
. V_49 = V_53 ,
. V_39 = 0 ,
} ;
struct V_157 V_158 ;
int V_84 = 0 ;
F_137 ( & V_158 ) ;
V_159:
F_138 ( V_3 ) ;
if ( F_45 ( V_3 , V_160 ) ) {
F_139 ( V_3 ) ;
F_131 ( V_3 ) ;
if ( F_12 ( F_37 ( V_3 ) ) ) {
V_84 = - V_161 ;
goto V_17;
}
goto V_159;
}
V_162:
F_140 ( & V_3 -> V_163 ) ;
if ( F_45 ( V_3 , V_164 ) ) {
F_141 ( & V_3 -> V_163 ) ;
F_142 ( V_3 , 0 , & V_36 ) ;
if ( F_12 ( F_37 ( V_3 ) ) ) {
F_139 ( V_3 ) ;
V_84 = - V_161 ;
goto V_17;
}
goto V_162;
}
V_17:
F_143 ( & V_158 ) ;
return V_84 ;
}
static void F_144 ( struct V_2 * V_3 )
{
F_141 ( & V_3 -> V_163 ) ;
F_139 ( V_3 ) ;
}
static void F_145 ( struct V_2 * V_3 )
{
F_146 ( V_165 ) ;
for (; ; ) {
F_147 ( & V_3 -> V_166 , & V_165 , V_167 ) ;
if ( ! F_45 ( V_3 , V_168 ) )
break;
F_148 () ;
}
F_149 ( & V_3 -> V_166 , & V_165 ) ;
}
static void F_150 ( struct V_2 * V_3 , struct V_169 * V_170 )
{
struct V_109 * V_131 = F_95 ( V_3 ) ;
struct V_171 * V_172 = F_151 ( V_3 , V_173 ) ;
struct V_174 * V_175 = F_24 ( V_3 ) ;
unsigned long V_176 = V_3 -> V_67 [ V_79 ] . V_80 ;
T_3 V_177 = V_175 -> V_178 ;
T_2 V_90 ;
unsigned int V_179 , V_91 ;
T_5 V_180 = 0 ;
int V_57 ;
int V_181 = F_96 ( V_3 ) ;
T_2 V_182 = F_152 ( V_3 , V_172 ) ;
bool V_183 = false ;
if ( F_153 ( V_3 , V_182 ) )
V_183 = true ;
while ( F_45 ( V_3 , V_40 ) ) {
F_49 ( V_3 , V_8 , V_53 ) ;
if ( F_12 ( F_37 ( V_3 ) ) )
return;
}
F_154 ( V_3 , & V_177 ) ;
V_131 -> V_184 = F_155 ( F_156 ( V_3 ) ) ;
V_131 -> V_185 = F_155 ( F_157 ( V_3 ) ) ;
V_131 -> V_186 = F_104 ( F_158 ( V_3 ) ) ;
for ( V_57 = 0 ; V_57 < V_187 ; V_57 ++ ) {
V_131 -> V_188 [ V_57 ] =
F_104 ( F_159 ( V_3 , V_57 + V_189 ) ) ;
V_131 -> V_190 [ V_57 ] =
F_105 ( F_160 ( V_3 , V_57 + V_189 ) ) ;
V_131 -> V_191 [ V_57 + V_189 ] =
F_161 ( V_3 , V_57 + V_189 ) ;
}
for ( V_57 = 0 ; V_57 < V_192 ; V_57 ++ ) {
V_131 -> V_193 [ V_57 ] =
F_104 ( F_159 ( V_3 , V_57 + V_194 ) ) ;
V_131 -> V_195 [ V_57 ] =
F_105 ( F_160 ( V_3 , V_57 + V_194 ) ) ;
V_131 -> V_191 [ V_57 + V_194 ] =
F_161 ( V_3 , V_57 + V_194 ) ;
}
V_131 -> V_196 = F_104 ( V_196 ( V_3 ) ) ;
V_131 -> V_197 = F_104 ( V_197 ( V_3 ) ) ;
V_131 -> F_154 = F_104 ( V_177 ) ;
V_179 = F_162 ( V_3 , false ) ;
if ( V_179 < V_192 )
F_163 ( V_131 , V_198 ) ;
else
F_100 ( V_131 , V_198 ) ;
V_91 = F_102 ( V_176 ) ;
V_131 -> V_199 = F_104 ( 1 + V_181 +
V_91 ) ;
if ( F_164 ( V_170 -> V_200 ) )
V_131 -> V_118 = F_104 ( V_201 +
V_181 + V_179 +
V_91 + V_187 ) ;
else
V_131 -> V_118 = F_104 ( V_201 +
V_181 + V_179 +
V_91 ) ;
if ( V_170 -> V_200 == V_202 )
F_163 ( V_131 , V_203 ) ;
else
F_100 ( V_131 , V_203 ) ;
if ( V_170 -> V_200 == V_204 )
F_163 ( V_131 , V_205 ) ;
else
F_100 ( V_131 , V_205 ) ;
if ( V_176 )
F_163 ( V_131 , V_93 ) ;
else
F_100 ( V_131 , V_93 ) ;
if ( F_35 ( V_3 , V_206 ) )
F_163 ( V_131 , V_207 ) ;
F_165 ( V_3 , F_166 ( V_3 , V_208 ) ) ;
F_167 ( V_3 , F_166 ( V_3 , V_209 ) ) ;
V_180 = F_168 ( V_131 , F_99 ( V_131 -> V_115 ) ) ;
* ( ( V_117 * ) ( ( unsigned char * ) V_131 +
F_99 ( V_131 -> V_115 ) ) )
= F_104 ( V_180 ) ;
V_90 = F_19 ( V_3 ) ;
F_169 ( V_3 , V_131 , V_90 ++ ) ;
for ( V_57 = 1 ; V_57 < 1 + V_181 ; V_57 ++ )
F_169 ( V_3 , ( char * ) V_131 + V_57 * V_210 ,
V_90 ++ ) ;
if ( V_176 ) {
F_101 ( V_3 , V_90 ) ;
V_90 += V_91 ;
}
F_170 ( V_3 , V_90 ) ;
V_90 += V_179 ;
if ( F_164 ( V_170 -> V_200 ) ) {
F_171 ( V_3 , V_90 ) ;
V_90 += V_187 ;
}
F_169 ( V_3 , V_131 , V_90 ) ;
F_145 ( V_3 ) ;
if ( F_12 ( F_37 ( V_3 ) ) )
return;
F_172 ( F_173 ( V_3 ) , 0 , V_53 ) ;
F_172 ( F_2 ( V_3 ) , 0 , V_53 ) ;
V_3 -> V_211 = V_3 -> V_212 ;
V_3 -> V_213 = 0 ;
F_49 ( V_3 , V_214 , V_53 ) ;
F_145 ( V_3 ) ;
if ( V_183 )
F_174 ( F_2 ( V_3 ) , V_182 ,
V_182 ) ;
F_80 ( V_3 ) ;
if ( F_12 ( F_37 ( V_3 ) ) )
return;
F_175 ( V_3 , V_170 ) ;
F_176 ( V_3 , V_215 ) ;
}
void F_177 ( struct V_2 * V_3 , struct V_169 * V_170 )
{
struct V_109 * V_131 = F_95 ( V_3 ) ;
unsigned long long V_216 ;
F_47 ( & V_3 -> V_48 ) ;
if ( ! F_35 ( V_3 , V_215 ) &&
( V_170 -> V_200 == V_204 || V_170 -> V_200 == V_217 ||
( V_170 -> V_200 == V_218 && ! V_3 -> V_219 ) ) )
goto V_17;
if ( F_12 ( F_37 ( V_3 ) ) )
goto V_17;
if ( F_178 ( V_3 -> V_88 ) )
goto V_17;
F_179 ( V_3 -> V_88 , V_170 -> V_200 , L_1 ) ;
if ( F_136 ( V_3 ) )
goto V_17;
F_179 ( V_3 -> V_88 , V_170 -> V_200 , L_2 ) ;
F_28 ( V_3 , V_154 , V_41 ) ;
F_28 ( V_3 , V_220 , V_41 ) ;
F_28 ( V_3 , V_8 , V_41 ) ;
V_216 = F_109 ( V_131 ) ;
V_131 -> V_221 = F_155 ( ++ V_216 ) ;
F_180 ( V_3 ) ;
F_181 ( V_3 , V_170 ) ;
F_150 ( V_3 , V_170 ) ;
F_144 ( V_3 ) ;
F_182 ( V_3 -> V_222 ) ;
if ( V_170 -> V_200 == V_223 )
F_183 ( V_3 -> V_88 , V_224 ,
L_3 , V_216 ) ;
V_17:
F_50 ( & V_3 -> V_48 ) ;
F_179 ( V_3 -> V_88 , V_170 -> V_200 , L_4 ) ;
}
void F_184 ( struct V_2 * V_3 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_225 ; V_57 ++ ) {
struct V_66 * V_67 = & V_3 -> V_67 [ V_57 ] ;
F_185 ( & V_67 -> V_76 , V_226 ) ;
F_186 ( & V_67 -> V_75 ) ;
F_125 ( & V_67 -> V_78 ) ;
V_67 -> V_80 = 0 ;
}
V_3 -> V_85 = ( V_3 -> V_227 - V_201 -
V_228 - F_96 ( V_3 ) ) *
V_101 ;
}
int T_6 F_187 ( void )
{
V_71 = F_188 ( L_5 ,
sizeof( struct V_68 ) ) ;
if ( ! V_71 )
return - V_133 ;
V_148 = F_188 ( L_6 ,
sizeof( struct V_140 ) ) ;
if ( ! V_148 ) {
F_189 ( V_71 ) ;
return - V_133 ;
}
return 0 ;
}
void F_190 ( void )
{
F_189 ( V_71 ) ;
F_189 ( V_148 ) ;
}
