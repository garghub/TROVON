static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned long * V_5 ,
enum V_6 * V_7 ,
T_1 * V_8 ,
bool V_9 )
{
struct V_10 * V_11 ;
int V_12 ;
* V_7 = V_13 ;
if ( V_4 -> V_14 == 0 )
return - V_15 ;
for ( V_11 = F_2 ( V_4 ) ; V_11 ; V_11 = F_3 ( V_4 , V_11 ) ) {
if ( ! F_4 ( V_4 , V_11 ) )
return - V_15 ;
V_12 = V_11 -> V_16 - F_5 ( sizeof( struct V_10 ) ) ;
F_6 ( L_1 ,
V_11 -> V_17 , V_11 -> V_18 , V_12 ) ;
if ( V_11 -> V_17 != V_19 )
continue;
switch ( V_11 -> V_18 ) {
case V_20 :
if ( V_4 -> V_21 & V_22 ) {
if ( V_12 != sizeof( T_1 ) )
return - V_15 ;
* V_5 = * ( T_1 * ) F_7 ( V_11 ) ;
} else {
if ( V_12 != sizeof( unsigned long ) )
return - V_15 ;
* V_5 = * ( unsigned long * )
F_7 ( V_11 ) ;
}
F_6 ( L_2 , * V_5 ) ;
break;
case V_23 :
if ( * V_7 != V_13 )
return - V_15 ;
* V_7 = V_24 ;
if ( V_12 != sizeof( * V_8 ) )
return - V_15 ;
* V_8 = * ( unsigned int * ) F_7 ( V_11 ) ;
F_6 ( L_3 , * V_8 ) ;
if ( * V_8 == 0 )
return - V_15 ;
break;
case V_25 :
if ( * V_7 != V_13 )
return - V_15 ;
* V_7 = V_26 ;
if ( V_12 != 0 )
return - V_15 ;
if ( ! V_9 )
return - V_27 ;
break;
default:
return - V_15 ;
}
}
F_8 ( L_4 ) ;
return 0 ;
}
static void F_9 ( struct V_28 * V_29 , T_1 V_8 )
{
F_10 ( & V_29 -> V_30 ) ;
if ( V_29 -> V_31 <= V_32 ) {
V_29 -> V_31 = V_33 ;
V_29 -> V_8 = V_8 ;
F_11 ( V_34 , & V_29 -> V_35 ) ;
F_12 ( & V_29 -> V_36 ) ;
F_12 ( & V_29 -> V_37 ) ;
F_13 ( V_38 , & V_29 -> V_35 ) ;
F_13 ( V_39 , & V_29 -> V_35 ) ;
F_13 ( V_40 , & V_29 -> V_41 ) ;
F_14 ( V_29 ) ;
}
F_15 ( & V_29 -> V_30 ) ;
}
int F_16 ( struct V_42 * V_43 , struct V_1 * V_2 ,
struct V_44 * V_45 , struct V_3 * V_4 ,
T_2 V_12 )
{
struct V_46 * V_47 ;
enum V_6 V_48 ;
struct V_28 * V_29 ;
unsigned long V_5 = 0 ;
struct V_49 * V_49 ;
T_3 V_50 ;
T_1 V_8 = 0 ;
int V_51 ;
F_17 ( L_5 ) ;
ASSERT ( V_45 != NULL ) ;
V_51 = F_1 ( V_2 , V_4 , & V_5 , & V_48 , & V_8 ,
false ) ;
if ( V_51 < 0 )
return V_51 ;
V_47 = NULL ;
if ( V_45 ) {
V_50 = V_2 -> V_50 ;
if ( V_4 -> V_52 ) {
F_18 ( struct V_53 * , V_54 ,
V_4 -> V_52 ) ;
V_50 = F_19 ( V_54 -> V_55 ) ;
}
V_49 = V_2 -> V_49 ;
if ( V_49 && ! V_2 -> V_49 -> V_56 . V_57 )
V_49 = NULL ;
V_47 = F_20 ( V_2 , V_45 , V_49 , V_50 ,
V_58 ) ;
if ( F_21 ( V_47 ) )
return F_22 ( V_47 ) ;
}
V_29 = F_23 ( V_2 , V_45 , V_47 , V_5 ,
V_8 == 0 , V_58 ) ;
if ( V_45 )
F_24 ( V_45 , V_47 ) ;
if ( F_21 ( V_29 ) ) {
F_8 ( L_6 , F_22 ( V_29 ) ) ;
return F_22 ( V_29 ) ;
}
F_6 ( L_7 ,
V_29 -> V_59 , V_29 -> V_5 , V_29 -> V_31 , V_29 -> V_60 ) ;
if ( V_29 -> V_31 >= V_32 ) {
V_51 = - V_61 ;
} else if ( V_48 == V_24 ) {
F_9 ( V_29 , V_8 ) ;
} else if ( V_48 != V_13 ) {
V_51 = - V_15 ;
} else if ( V_29 -> V_31 != V_62 ) {
V_51 = - V_63 ;
} else {
V_51 = F_25 ( V_43 , V_2 , V_29 , V_4 , V_12 ) ;
}
F_26 ( V_29 ) ;
F_8 ( L_8 , V_51 ) ;
return V_51 ;
}
int F_27 ( struct V_28 * V_29 , struct V_3 * V_4 ,
T_2 V_12 )
{
int V_51 ;
F_17 ( L_9 , V_29 -> V_59 , V_64 [ V_29 -> V_31 ] ) ;
F_28 ( V_4 -> V_52 , == , NULL ) ;
F_28 ( V_4 -> V_65 , == , NULL ) ;
F_29 ( & V_29 -> V_66 -> V_67 ) ;
F_6 ( L_7 ,
V_29 -> V_59 , V_29 -> V_5 , V_29 -> V_31 , V_29 -> V_60 ) ;
if ( V_29 -> V_31 >= V_32 ) {
V_51 = - V_61 ;
} else if ( V_29 -> V_31 != V_62 &&
V_29 -> V_31 != V_68 &&
V_29 -> V_31 != V_69 ) {
V_51 = - V_63 ;
} else {
T_4 V_70 = F_30 () ;
F_31 ( V_71 ) ;
V_51 = F_25 ( NULL , V_29 -> V_66 , V_29 , V_4 , V_12 ) ;
F_31 ( V_70 ) ;
}
F_32 ( & V_29 -> V_66 -> V_67 ) ;
F_8 ( L_8 , V_51 ) ;
return V_51 ;
}
void F_33 ( struct V_28 * V_29 , T_1 V_8 )
{
F_17 ( L_10 , V_29 -> V_59 , V_8 ) ;
F_29 ( & V_29 -> V_66 -> V_67 ) ;
F_6 ( L_7 ,
V_29 -> V_59 , V_29 -> V_5 , V_29 -> V_31 , V_29 -> V_60 ) ;
if ( V_29 -> V_31 < V_32 )
F_9 ( V_29 , V_8 ) ;
F_32 ( & V_29 -> V_66 -> V_67 ) ;
F_8 ( L_5 ) ;
}
int F_34 ( struct V_42 * V_43 , struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_12 )
{
enum V_6 V_48 ;
struct V_28 * V_29 ;
unsigned long V_5 = 0 ;
T_1 V_8 = 0 ;
int V_51 ;
F_17 ( L_5 ) ;
V_51 = F_1 ( V_2 , V_4 , & V_5 , & V_48 , & V_8 ,
true ) ;
if ( V_51 < 0 )
return V_51 ;
if ( V_48 == V_26 ) {
V_29 = F_35 ( V_2 , V_5 ) ;
if ( F_21 ( V_29 ) )
return F_22 ( V_29 ) ;
F_26 ( V_29 ) ;
return 0 ;
}
V_29 = F_36 ( V_2 , V_5 ) ;
if ( ! V_29 )
return - V_72 ;
if ( V_29 -> V_31 >= V_32 ) {
V_51 = - V_61 ;
goto V_73;
}
switch ( V_48 ) {
case V_13 :
if ( V_29 -> V_31 != V_62 &&
V_29 -> V_31 != V_68 &&
V_29 -> V_31 != V_69 ) {
V_51 = - V_63 ;
break;
}
V_51 = F_25 ( V_43 , V_2 , V_29 , V_4 , V_12 ) ;
break;
case V_24 :
F_9 ( V_29 , V_8 ) ;
break;
default:
F_37 () ;
}
V_73:
F_26 ( V_29 ) ;
F_8 ( L_8 , V_51 ) ;
return V_51 ;
}
int F_38 ( struct V_44 * V_45 , struct V_74 * V_75 )
{
struct V_76 V_77 [ 1 ] ;
struct V_3 V_4 ;
int V_51 , V_78 ;
F_17 ( L_11 , V_75 -> V_12 ) ;
V_77 [ 0 ] . V_79 = V_75 -> V_80 ;
V_77 [ 0 ] . V_81 = V_75 -> V_12 ;
V_4 . V_52 = & V_45 -> V_82 -> V_54 . V_83 . sin ;
V_4 . V_84 = sizeof( V_45 -> V_82 -> V_54 . V_83 . sin ) ;
V_4 . V_65 = NULL ;
V_4 . V_14 = 0 ;
V_4 . V_21 = 0 ;
if ( V_75 -> V_12 - sizeof( struct V_85 ) < V_45 -> V_82 -> V_86 ) {
F_39 ( & V_45 -> V_87 -> V_88 ) ;
V_51 = F_40 ( V_45 -> V_87 -> V_66 , & V_4 , V_77 , 1 ,
V_77 [ 0 ] . V_81 ) ;
F_41 ( & V_45 -> V_87 -> V_88 ) ;
if ( V_51 == - V_89 )
goto V_90;
F_8 ( L_12 , V_51 , V_45 -> V_82 -> V_86 ) ;
return V_51 ;
}
V_90:
F_6 ( L_13 ) ;
F_42 ( & V_45 -> V_87 -> V_88 ) ;
V_78 = V_91 ;
V_51 = F_43 ( V_45 -> V_87 -> V_66 , V_92 , V_93 ,
( char * ) & V_78 , sizeof( V_78 ) ) ;
if ( V_51 == 0 ) {
V_51 = F_40 ( V_45 -> V_87 -> V_66 , & V_4 , V_77 , 1 ,
V_77 [ 0 ] . V_81 ) ;
V_78 = V_94 ;
F_43 ( V_45 -> V_87 -> V_66 , V_92 ,
V_93 , ( char * ) & V_78 , sizeof( V_78 ) ) ;
}
F_44 ( & V_45 -> V_87 -> V_88 ) ;
F_8 ( L_14 , V_51 , V_45 -> V_82 -> V_86 ) ;
return V_51 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_28 * V_29 ,
long * V_95 )
{
F_46 ( V_96 , V_97 ) ;
int V_51 ;
F_17 ( L_15 ,
F_47 ( V_29 -> V_98 , V_29 -> V_99 , V_29 -> V_100 ) ,
* V_95 ) ;
F_48 ( & V_29 -> V_101 , & V_96 ) ;
for (; ; ) {
F_49 ( V_102 ) ;
V_51 = 0 ;
if ( F_47 ( V_29 -> V_98 , V_29 -> V_99 ,
V_29 -> V_100 ) > 0 )
break;
if ( F_50 ( V_97 ) ) {
V_51 = F_51 ( * V_95 ) ;
break;
}
F_32 ( & V_2 -> V_67 ) ;
* V_95 = F_52 ( * V_95 ) ;
F_29 ( & V_2 -> V_67 ) ;
}
F_53 ( & V_29 -> V_101 , & V_96 ) ;
F_49 ( V_103 ) ;
F_8 ( L_8 , V_51 ) ;
return V_51 ;
}
static inline void F_54 ( struct V_28 * V_29 )
{
F_55 ( & V_29 -> V_30 ) ;
if ( F_56 ( & V_29 -> V_36 ) >= 0 ) {
F_13 ( V_40 , & V_29 -> V_41 ) ;
if ( V_29 -> V_31 < V_32 &&
! F_57 ( V_38 , & V_29 -> V_35 ) )
F_14 ( V_29 ) ;
}
F_58 ( & V_29 -> V_30 ) ;
}
static void F_59 ( struct V_28 * V_29 , struct V_74 * V_75 ,
bool V_104 )
{
struct V_105 * V_106 = F_60 ( V_75 ) ;
int V_51 ;
F_61 ( L_16 , V_75 , V_29 -> V_98 ) ;
ASSERT ( V_29 -> V_107 != NULL ) ;
V_29 -> V_107 [ V_29 -> V_98 ] = ( unsigned long ) V_75 ;
F_62 () ;
V_29 -> V_98 = ( V_29 -> V_98 + 1 ) & ( V_29 -> V_100 - 1 ) ;
if ( V_104 || V_29 -> V_31 == V_68 ) {
F_6 ( L_17 ) ;
F_10 ( & V_29 -> V_30 ) ;
switch ( V_29 -> V_31 ) {
case V_62 :
V_29 -> V_31 = V_108 ;
break;
case V_68 :
V_29 -> V_31 = V_69 ;
if ( ! V_104 )
break;
case V_69 :
V_29 -> V_31 = V_109 ;
break;
default:
break;
}
F_15 ( & V_29 -> V_30 ) ;
}
F_63 ( L_18 ,
F_64 ( V_106 -> V_110 . V_111 ) , F_64 ( V_106 -> V_110 . V_112 ) ) ;
V_106 -> V_113 = false ;
V_106 -> V_114 = V_115 + V_116 * V_117 ;
if ( ! F_57 ( V_40 , & V_29 -> V_41 ) ) {
F_6 ( L_19 ) ;
V_29 -> V_36 . V_118 = V_106 -> V_114 ;
F_65 ( & V_29 -> V_36 ) ;
}
V_51 = - V_119 ;
if ( F_56 ( & V_29 -> V_37 ) >= 0 ) {
V_51 = F_38 ( V_29 -> V_60 -> V_45 , V_75 ) ;
F_61 ( L_20 , V_75 ) ;
} else {
F_6 ( L_21 ) ;
}
if ( V_51 < 0 ) {
F_6 ( L_22 , V_51 ) ;
V_106 -> V_113 = true ;
F_54 ( V_29 ) ;
}
F_8 ( L_5 ) ;
}
static int F_25 ( struct V_42 * V_43 ,
struct V_1 * V_2 ,
struct V_28 * V_29 ,
struct V_3 * V_4 , T_2 V_12 )
{
struct V_105 * V_106 ;
unsigned char T_5 * V_120 ;
struct V_74 * V_75 ;
struct V_121 * V_77 ;
struct V_122 * V_67 = & V_2 -> V_67 ;
long V_95 ;
bool V_123 ;
int V_51 , V_124 , V_125 , V_126 ;
F_17 ( L_23 , V_4 -> V_127 , V_12 ) ;
V_95 = F_66 ( V_67 , V_4 -> V_21 & V_128 ) ;
F_13 ( V_129 , & V_67 -> V_130 -> V_41 ) ;
if ( V_67 -> V_131 || ( V_67 -> V_132 & V_133 ) )
return - V_134 ;
V_77 = V_4 -> V_135 ;
V_124 = V_4 -> V_127 - 1 ;
V_120 = V_77 -> V_79 ;
V_125 = V_77 -> V_81 ;
V_77 ++ ;
V_123 = V_4 -> V_21 & V_136 ;
V_75 = V_29 -> V_137 ;
V_29 -> V_137 = NULL ;
V_126 = 0 ;
do {
int V_138 ;
if ( V_125 > V_12 )
V_125 = V_12 ;
F_6 ( L_24 , V_125 , V_120 ) ;
if ( ! V_75 ) {
T_2 V_139 , V_140 , V_141 , V_142 ;
F_6 ( L_25 ) ;
if ( F_47 ( V_29 -> V_98 , V_29 -> V_99 ,
V_29 -> V_100 ) <= 0 ) {
V_51 = - V_119 ;
if ( V_4 -> V_21 & V_128 )
goto V_143;
V_51 = F_45 ( V_2 , V_29 ,
& V_95 ) ;
if ( V_51 < 0 )
goto V_143;
}
V_141 = V_29 -> V_60 -> V_45 -> V_82 -> V_86 ;
V_141 -= V_29 -> V_60 -> V_144 ;
V_141 &= ~ ( V_29 -> V_60 -> V_145 - 1UL ) ;
V_140 = V_141 ;
if ( V_140 > V_12 && ! V_123 )
V_140 = V_12 ;
V_142 = V_140 + V_29 -> V_60 -> V_145 ;
V_142 &= ~ ( V_29 -> V_60 -> V_145 - 1UL ) ;
V_139 = V_142 + V_29 -> V_60 -> V_146 ;
F_6 ( L_26 , V_140 , V_142 , V_139 ) ;
V_75 = F_67 (
V_67 , V_139 , V_4 -> V_21 & V_128 , & V_51 ) ;
if ( ! V_75 )
goto V_143;
F_68 ( V_75 ) ;
F_6 ( L_27 , V_75 ) ;
F_28 ( V_75 -> V_147 , == , 0 ) ;
F_6 ( L_28 , V_29 -> V_60 -> V_146 ) ;
F_69 ( V_75 , V_29 -> V_60 -> V_146 ) ;
V_75 -> V_12 += V_29 -> V_60 -> V_146 ;
V_106 = F_60 ( V_75 ) ;
V_106 -> V_148 = V_140 ;
if ( V_106 -> V_148 > F_70 ( V_75 ) )
V_106 -> V_148 = F_70 ( V_75 ) ;
F_61 ( L_29 ,
F_71 ( V_75 ) ,
F_70 ( V_75 ) ,
F_72 ( V_75 ) ,
V_106 -> V_148 ) ;
V_75 -> V_149 = V_150 ;
}
F_6 ( L_30 ) ;
V_106 = F_60 ( V_75 ) ;
V_138 = F_70 ( V_75 ) ;
F_28 ( V_138 , > , 0 ) ;
if ( V_138 > V_125 )
V_138 = V_125 ;
if ( V_138 > V_106 -> V_148 )
V_138 = V_106 -> V_148 ;
F_6 ( L_31 ) ;
V_51 = F_73 ( V_75 , V_120 , V_138 ) ;
F_6 ( L_32 ) ;
if ( V_51 < 0 )
goto V_151;
V_106 -> V_148 -= V_138 ;
V_75 -> V_147 += V_138 ;
V_126 += V_138 ;
V_12 -= V_138 ;
V_125 -= V_138 ;
V_120 += V_138 ;
while ( V_125 == 0 && V_124 > 0 ) {
V_120 = V_77 -> V_79 ;
V_125 = V_77 -> V_81 ;
V_77 ++ ;
V_124 -- ;
}
if ( V_12 == 0 ) {
V_125 = 0 ;
V_124 = 0 ;
}
if ( V_29 -> V_31 > V_32 )
goto V_152;
if ( V_106 -> V_148 <= 0 || ( V_125 == 0 && ! V_123 ) ) {
struct V_153 * V_60 = V_29 -> V_60 ;
T_2 V_154 ;
if ( V_60 -> V_155 ) {
V_154 = V_60 -> V_144 + V_75 -> V_147 ;
V_154 = V_60 -> V_145 - V_154 ;
V_154 &= V_60 -> V_145 - 1 ;
F_6 ( L_33 , V_154 ) ;
if ( V_154 )
memset ( F_74 ( V_75 , V_154 ) , 0 , V_154 ) ;
}
V_106 -> V_110 . V_156 = V_60 -> V_156 ;
V_106 -> V_110 . V_157 = V_29 -> V_157 ;
V_106 -> V_110 . V_158 = V_29 -> V_159 ;
V_106 -> V_110 . V_112 =
F_75 ( F_76 ( & V_29 -> V_160 ) ) ;
V_106 -> V_110 . V_111 =
F_75 ( F_76 ( & V_60 -> V_111 ) ) ;
V_106 -> V_110 . type = V_161 ;
V_106 -> V_110 . V_162 = 0 ;
V_106 -> V_110 . V_163 = V_60 -> V_164 ;
V_106 -> V_110 . V_165 = 0 ;
V_106 -> V_110 . V_166 = V_60 -> V_50 ;
V_106 -> V_110 . V_41 = V_60 -> V_167 ;
if ( V_12 == 0 && ! V_123 )
V_106 -> V_110 . V_41 |= V_168 ;
else if ( F_47 ( V_29 -> V_98 , V_29 -> V_99 ,
V_29 -> V_100 ) > 1 )
V_106 -> V_110 . V_41 |= V_169 ;
V_51 = F_77 (
V_29 , V_75 , V_75 -> V_147 ,
V_75 -> V_80 + sizeof( struct V_85 ) ) ;
if ( V_51 < 0 )
goto V_73;
memcpy ( V_75 -> V_80 , & V_106 -> V_110 ,
sizeof( struct V_85 ) ) ;
F_59 ( V_29 , V_75 , V_125 == 0 && ! V_123 ) ;
V_75 = NULL ;
}
} while ( V_125 > 0 );
V_170:
V_51 = V_126 ;
V_73:
V_29 -> V_137 = V_75 ;
F_8 ( L_8 , V_51 ) ;
return V_51 ;
V_152:
F_78 ( V_75 ) ;
if ( V_29 -> V_31 == V_171 )
V_51 = V_29 -> V_60 -> V_45 -> V_82 -> V_172 ;
else
V_51 = - V_173 ;
F_8 ( L_8 , V_51 ) ;
return V_51 ;
V_143:
if ( V_126 )
goto V_170;
goto V_73;
V_151:
V_51 = - V_174 ;
goto V_73;
}
