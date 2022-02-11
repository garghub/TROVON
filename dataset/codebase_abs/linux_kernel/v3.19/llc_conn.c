int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_2 ) ;
struct V_8 * V_9 = F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
V_9 -> V_10 = V_9 -> V_11 = 0 ;
V_5 = F_5 ( V_4 -> V_2 , V_4 ) ;
if ( F_6 ( V_5 != 0 ) ) {
F_7 ( V_12 L_1 , V_13 ) ;
goto V_14;
}
if ( F_6 ( ! V_9 -> V_10 && ! V_9 -> V_11 ) ) {
if ( ! V_4 -> V_15 )
goto V_14;
goto V_16;
}
if ( F_6 ( V_9 -> V_10 && V_9 -> V_11 ) )
F_4 ( V_4 ) ;
switch ( V_9 -> V_10 ) {
case V_17 :
F_8 ( V_2 , V_4 , V_17 ) ;
if ( F_6 ( F_9 ( V_2 , V_4 ) ) ) {
F_7 ( V_12 L_2 ,
V_13 ) ;
F_10 ( V_4 ) ;
}
break;
case V_18 :
F_11 ( & V_2 -> V_19 , V_4 ) ;
V_2 -> V_20 ( V_2 ) ;
break;
case V_21 :
F_12 ( V_2 ) ;
if ( V_2 -> V_22 == V_23 &&
V_2 -> V_24 == V_25 ) {
V_2 -> V_26 = V_27 ;
V_2 -> V_28 -> V_29 = V_30 ;
V_2 -> V_24 = V_31 ;
if ( ! F_13 ( V_2 , V_32 ) ) {
F_14 ( V_2 , V_32 ) ;
V_2 -> V_20 ( V_2 ) ;
}
}
F_10 ( V_4 ) ;
F_15 ( V_2 ) ;
break;
case V_33 :
F_7 ( V_34 L_3 , V_13 ) ;
F_10 ( V_4 ) ;
break;
default:
if ( V_9 -> V_10 ) {
F_7 ( V_34 L_4 ,
V_13 , V_9 -> V_10 ) ;
F_10 ( V_4 ) ;
}
break;
}
switch ( V_9 -> V_11 ) {
case V_17 :
if ( ! F_16 ( V_7 -> V_29 ) )
V_2 -> V_35 ( V_2 ) ;
else
V_5 = V_7 -> V_36 = 1 ;
break;
case V_18 :
if ( V_2 -> V_22 == V_23 &&
V_2 -> V_24 == V_37 ) {
if ( V_9 -> V_38 ) {
V_2 -> V_28 -> V_29 = V_30 ;
V_2 -> V_24 = V_31 ;
} else {
V_2 -> V_28 -> V_29 = V_39 ;
V_2 -> V_24 = V_25 ;
}
V_2 -> V_20 ( V_2 ) ;
}
break;
case V_21 :
F_12 ( V_2 ) ;
if ( V_2 -> V_22 == V_23 && V_2 -> V_24 == V_40 ) {
V_2 -> V_28 -> V_29 = V_30 ;
V_2 -> V_24 = V_31 ;
V_2 -> V_20 ( V_2 ) ;
}
F_15 ( V_2 ) ;
break;
case V_33 :
F_7 ( V_34 L_5 , V_13 ) ;
break;
default:
if ( V_9 -> V_11 ) {
F_7 ( V_34 L_4 ,
V_13 , V_9 -> V_11 ) ;
break;
}
goto V_16;
}
V_14:
F_10 ( V_4 ) ;
V_16:
F_10 ( V_4 ) ;
return V_5 ;
}
void F_17 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_11 ( & V_2 -> V_41 , V_4 ) ;
F_18 ( V_2 ) ;
}
void F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = F_3 ( V_4 ) ;
V_9 -> V_10 = V_17 ;
}
void F_20 ( struct V_1 * V_2 , T_1 V_42 , T_1 V_43 )
{
struct V_3 * V_4 ;
struct V_44 * V_45 ;
T_2 V_46 ;
struct V_6 * V_7 ;
T_1 V_47 = 0 ;
F_21 ( V_2 , V_42 , & V_46 ) ;
if ( ! V_46 )
goto V_48;
V_7 = F_2 ( V_2 ) ;
while ( ( V_4 = F_22 ( & V_7 -> V_49 ) ) != NULL ) {
V_45 = F_23 ( V_4 ) ;
F_24 ( V_4 , V_50 ) ;
F_25 ( V_4 , V_43 ) ;
F_11 ( & V_2 -> V_41 , V_4 ) ;
V_43 = 0 ;
V_7 -> V_51 = F_26 ( V_45 ) ;
V_47 ++ ;
}
if ( V_47 > 0 )
V_7 -> V_51 = ( V_7 -> V_51 + 1 ) % V_52 ;
F_18 ( V_2 ) ;
V_48: ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_42 , T_1 V_53 )
{
struct V_3 * V_4 ;
T_2 V_46 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
T_1 V_47 = 0 ;
F_21 ( V_2 , V_42 , & V_46 ) ;
if ( ! V_46 )
goto V_48;
while ( ( V_4 = F_22 ( & V_7 -> V_49 ) ) != NULL ) {
struct V_44 * V_45 = F_23 ( V_4 ) ;
F_24 ( V_4 , V_54 ) ;
F_25 ( V_4 , V_53 ) ;
F_11 ( & V_2 -> V_41 , V_4 ) ;
V_53 = 0 ;
V_7 -> V_51 = F_26 ( V_45 ) ;
V_47 ++ ;
}
if ( V_47 > 0 )
V_7 -> V_51 = ( V_7 -> V_51 + 1 ) % V_52 ;
F_18 ( V_2 ) ;
V_48: ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_42 , T_2 * V_55 )
{
int V_56 , V_57 ;
struct V_3 * V_4 ;
struct V_44 * V_45 ;
int V_58 = 0 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_59 = F_28 ( & V_7 -> V_49 ) ;
if ( ! V_59 )
goto V_48;
V_4 = F_29 ( & V_7 -> V_49 ) ;
V_45 = F_23 ( V_4 ) ;
V_56 = ( ( int ) V_52 + ( int ) V_42 -
( int ) F_26 ( V_45 ) ) % V_52 ;
for ( V_57 = 0 ; V_57 < V_56 && V_57 < V_59 ; V_57 ++ ) {
V_4 = F_22 ( & V_7 -> V_49 ) ;
F_10 ( V_4 ) ;
V_58 ++ ;
}
V_48:
* V_55 = F_28 ( & V_7 -> V_49 ) ;
return V_58 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
while ( ( V_4 = F_22 ( & V_2 -> V_41 ) ) != NULL ) {
struct V_44 * V_45 = F_23 ( V_4 ) ;
if ( F_30 ( V_45 ) &&
! ( V_4 -> V_60 -> V_61 & V_62 ) ) {
struct V_3 * V_63 = F_31 ( V_4 , V_64 ) ;
F_11 ( & F_2 ( V_2 ) -> V_49 , V_4 ) ;
if ( ! V_63 )
break;
V_4 = V_63 ;
}
F_32 ( V_4 ) ;
}
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = 1 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_65 * V_66 ;
if ( V_7 -> V_29 > V_67 )
goto V_48;
V_5 = 0 ;
V_66 = F_33 ( V_2 , V_4 ) ;
if ( V_66 ) {
V_5 = F_34 ( V_2 , V_66 , V_4 ) ;
if ( ! V_5 && V_66 -> V_68 != V_69 ) {
V_7 -> V_29 = V_66 -> V_68 ;
if ( ! F_16 ( V_7 -> V_29 ) )
V_2 -> V_20 ( V_2 ) ;
}
}
V_48:
return V_5 ;
}
static struct V_65 * F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_65 * * V_70 ;
const T_3 * V_71 ;
struct V_8 * V_9 = F_3 ( V_4 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_72 * V_73 =
& V_74 [ V_7 -> V_29 - 1 ] ;
for ( V_70 = V_73 -> V_75 +
F_35 ( V_7 -> V_29 - 1 , V_9 -> type ) ;
( * V_70 ) -> V_9 ; V_70 ++ ) {
if ( ! ( ( * V_70 ) -> V_9 ) ( V_2 , V_4 ) ) {
for ( V_71 = ( * V_70 ) -> V_76 ;
V_71 && * V_71 &&
! (* V_71)( V_2 , V_4 ) ; V_71 ++ )
;
if ( ! V_71 || ! * V_71 )
return * V_70 ;
}
}
return NULL ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_65 * V_66 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
const T_4 * V_77 ;
for ( V_77 = V_66 -> V_78 ;
V_77 && * V_77 ; V_77 ++ ) {
int V_79 = (* V_77)( V_2 , V_4 ) ;
if ( V_79 == 2 ) {
V_5 = V_79 ;
break;
} else if ( V_79 )
V_5 = 1 ;
}
return V_5 ;
}
static inline bool F_36 ( const struct V_80 * V_81 ,
const struct V_82 * V_83 ,
const struct V_82 * V_84 ,
const struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_7 -> V_84 . V_85 == V_84 -> V_85 &&
V_7 -> V_83 . V_85 == V_83 -> V_85 &&
F_37 ( V_7 -> V_84 . V_86 , V_84 -> V_86 ) &&
F_37 ( V_7 -> V_83 . V_86 , V_83 -> V_86 ) ;
}
static struct V_1 * F_38 ( struct V_80 * V_81 ,
struct V_82 * V_83 ,
struct V_82 * V_84 )
{
struct V_1 * V_5 ;
struct V_87 * V_88 ;
int V_89 = F_39 ( V_81 , V_84 ) ;
struct V_90 * V_91 = & V_81 -> V_92 [ V_89 ] ;
F_40 () ;
V_93:
F_41 (rc, node, laddr_hb) {
if ( F_36 ( V_81 , V_83 , V_84 , V_5 ) ) {
if ( F_6 ( ! F_42 ( & V_5 -> V_94 ) ) )
goto V_93;
if ( F_6 ( F_2 ( V_5 ) -> V_81 != V_81 ||
! F_36 ( V_81 , V_83 , V_84 , V_5 ) ) ) {
F_15 ( V_5 ) ;
continue;
}
goto V_95;
}
}
V_5 = NULL ;
if ( F_6 ( F_43 ( V_88 ) != V_89 ) )
goto V_93;
V_95:
F_44 () ;
return V_5 ;
}
struct V_1 * F_45 ( struct V_80 * V_81 ,
struct V_82 * V_83 ,
struct V_82 * V_84 )
{
struct V_1 * V_2 ;
F_46 () ;
V_2 = F_38 ( V_81 , V_83 , V_84 ) ;
F_47 () ;
return V_2 ;
}
static inline bool F_48 ( const struct V_80 * V_81 ,
const struct V_82 * V_84 ,
const struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return V_2 -> V_22 == V_23 && V_2 -> V_24 == V_96 &&
V_7 -> V_84 . V_85 == V_84 -> V_85 &&
F_37 ( V_7 -> V_84 . V_86 , V_84 -> V_86 ) ;
}
static struct V_1 * F_49 ( struct V_80 * V_81 ,
struct V_82 * V_84 )
{
struct V_1 * V_5 ;
struct V_87 * V_88 ;
int V_89 = F_39 ( V_81 , V_84 ) ;
struct V_90 * V_91 = & V_81 -> V_92 [ V_89 ] ;
F_40 () ;
V_93:
F_41 (rc, node, laddr_hb) {
if ( F_48 ( V_81 , V_84 , V_5 ) ) {
if ( F_6 ( ! F_42 ( & V_5 -> V_94 ) ) )
goto V_93;
if ( F_6 ( F_2 ( V_5 ) -> V_81 != V_81 ||
! F_48 ( V_81 , V_84 , V_5 ) ) ) {
F_15 ( V_5 ) ;
continue;
}
goto V_95;
}
}
V_5 = NULL ;
if ( F_6 ( F_43 ( V_88 ) != V_89 ) )
goto V_93;
V_95:
F_44 () ;
return V_5 ;
}
static struct V_1 * F_50 ( struct V_80 * V_81 ,
struct V_82 * V_84 )
{
static struct V_82 V_97 ;
struct V_1 * V_5 = F_49 ( V_81 , V_84 ) ;
if ( ! V_5 )
V_5 = F_49 ( V_81 , & V_97 ) ;
return V_5 ;
}
static struct V_1 * F_51 ( struct V_80 * V_81 ,
struct V_82 * V_83 ,
struct V_82 * V_84 )
{
struct V_1 * V_2 = F_38 ( V_81 , V_83 , V_84 ) ;
return V_2 ? : F_50 ( V_81 , V_84 ) ;
}
T_1 F_16 ( T_1 V_29 )
{
return V_29 != V_98 && V_29 != V_99 &&
V_29 != V_100 ;
}
static T_2 T_5 F_52 ( struct V_72 * V_29 , T_2 V_101 )
{
T_2 V_102 = 0 ;
struct V_65 * * V_70 ;
for ( V_70 = V_29 -> V_75 + V_101 ;
( * V_70 ) -> V_9 ; V_70 ++ )
++ V_102 ;
return V_102 ;
}
void T_5 F_53 ( void )
{
struct V_72 * V_73 ;
int V_29 , V_103 , V_104 ;
for ( V_29 = 0 ; V_29 < V_67 ; V_29 ++ ) {
V_73 = & V_74 [ V_29 ] ;
V_104 = 0 ;
for ( V_103 = 0 ; V_103 < V_105 ; V_103 ++ ) {
V_106 [ V_29 ] [ V_103 ] = V_104 ;
V_104 += F_52 ( V_73 ,
V_104 ) + 1 ;
}
}
}
static int F_35 ( int V_29 , int V_103 )
{
int V_5 = 0 ;
switch ( V_103 ) {
case V_107 :
V_5 = V_106 [ V_29 ] [ 0 ] ; break;
case V_108 :
V_5 = V_106 [ V_29 ] [ 4 ] ; break;
case V_109 :
V_5 = V_106 [ V_29 ] [ 1 ] ; break;
case V_110 :
case V_111 :
case V_112 :
case V_113 :
V_5 = V_106 [ V_29 ] [ 3 ] ; break;
}
return V_5 ;
}
void F_54 ( struct V_80 * V_81 , struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_114 * V_115 = F_55 ( V_81 , V_7 -> V_60 -> V_116 ) ;
struct V_90 * V_91 = F_56 ( V_81 , & V_7 -> V_84 ) ;
F_57 ( V_81 ) ;
F_2 ( V_2 ) -> V_81 = V_81 ;
F_58 ( & V_81 -> V_117 ) ;
V_81 -> V_118 ++ ;
F_59 ( V_2 , V_91 ) ;
F_60 ( & V_7 -> V_119 , V_115 ) ;
F_61 ( & V_81 -> V_117 ) ;
}
void F_62 ( struct V_80 * V_81 , struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_58 ( & V_81 -> V_117 ) ;
F_63 ( V_2 ) ;
F_64 ( & V_7 -> V_119 ) ;
V_81 -> V_118 -- ;
F_61 ( & V_81 -> V_117 ) ;
F_65 ( V_81 ) ;
}
static int F_66 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_8 * V_9 = F_3 ( V_4 ) ;
V_9 -> type = V_108 ;
V_9 -> V_120 = 0 ;
return F_1 ( V_2 , V_4 ) ;
}
static struct V_1 * F_67 ( struct V_1 * V_2 ,
struct V_121 * V_60 ,
struct V_82 * V_122 ,
struct V_82 * V_83 )
{
struct V_1 * V_123 = F_68 ( F_69 ( V_2 ) , V_2 -> V_124 , V_64 ,
V_2 -> V_125 ) ;
struct V_6 * V_126 , * V_7 = F_2 ( V_2 ) ;
if ( ! V_123 )
goto V_48;
V_126 = F_2 ( V_123 ) ;
memcpy ( & V_126 -> V_84 , V_83 , sizeof( V_126 -> V_84 ) ) ;
memcpy ( & V_126 -> V_83 , V_122 , sizeof( V_126 -> V_83 ) ) ;
V_126 -> V_60 = V_60 ;
F_70 ( V_60 ) ;
F_54 ( V_7 -> V_81 , V_123 ) ;
F_57 ( V_7 -> V_81 ) ;
V_48:
return V_123 ;
}
void F_71 ( struct V_80 * V_81 , struct V_3 * V_4 )
{
struct V_82 V_122 , V_83 ;
struct V_1 * V_2 ;
F_72 ( V_4 , V_122 . V_86 ) ;
F_73 ( V_4 , & V_122 . V_85 ) ;
F_74 ( V_4 , V_83 . V_86 ) ;
F_75 ( V_4 , & V_83 . V_85 ) ;
V_2 = F_51 ( V_81 , & V_122 , & V_83 ) ;
if ( ! V_2 )
goto V_127;
F_76 ( V_2 ) ;
if ( F_6 ( V_2 -> V_24 == V_96 ) ) {
struct V_1 * V_123 = F_67 ( V_2 , V_4 -> V_60 ,
& V_122 , & V_83 ) ;
if ( ! V_123 )
goto V_128;
F_77 ( V_4 , V_123 ) ;
} else {
V_4 -> V_2 = V_2 ;
}
if ( ! F_78 ( V_2 ) )
F_66 ( V_2 , V_4 ) ;
else {
F_79 ( L_6 , V_13 ) ;
F_80 ( V_4 , V_129 ) ;
if ( F_81 ( V_2 , V_4 , V_2 -> V_130 ) )
goto V_128;
}
V_48:
F_82 ( V_2 ) ;
F_15 ( V_2 ) ;
return;
V_127:
F_10 ( V_4 ) ;
return;
V_128:
F_10 ( V_4 ) ;
goto V_48;
}
static int F_83 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_84 ( F_85 ( V_4 ) == V_129 ) ) {
if ( F_84 ( V_7 -> V_29 > 1 ) )
V_5 = F_66 ( V_2 , V_4 ) ;
else
goto V_14;
} else if ( F_85 ( V_4 ) == V_131 ) {
if ( F_84 ( V_7 -> V_29 > 1 ) )
V_5 = F_1 ( V_2 , V_4 ) ;
else
goto V_14;
} else {
F_7 ( V_12 L_7 , V_13 ) ;
goto V_14;
}
V_48:
return V_5 ;
V_14:
F_10 ( V_4 ) ;
goto V_48;
}
static void F_86 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_29 = V_132 ;
V_7 -> V_133 = V_7 -> V_134 = 2 ;
V_7 -> V_135 = V_7 -> V_136 = 1 ;
F_87 ( & V_7 -> V_137 . V_138 , V_139 ,
( unsigned long ) V_2 ) ;
V_7 -> V_137 . V_140 = V_141 ;
F_87 ( & V_7 -> V_142 . V_138 , V_143 ,
( unsigned long ) V_2 ) ;
V_7 -> V_142 . V_140 = V_144 ;
F_87 ( & V_7 -> V_145 . V_138 , V_146 ,
( unsigned long ) V_2 ) ;
V_7 -> V_145 . V_140 = V_147 ;
F_87 ( & V_7 -> V_148 . V_138 , V_149 ,
( unsigned long ) V_2 ) ;
V_7 -> V_148 . V_140 = V_150 ;
V_7 -> V_151 = 2 ;
V_7 -> V_152 = 2 ;
V_7 -> V_153 = 128 ;
F_88 ( & V_7 -> V_49 ) ;
V_2 -> V_154 = F_83 ;
}
struct V_1 * F_68 ( struct V_155 * V_155 , int V_156 , T_6 V_157 , struct V_158 * V_159 )
{
struct V_1 * V_2 = F_89 ( V_155 , V_156 , V_157 , V_159 ) ;
if ( ! V_2 )
goto V_48;
F_86 ( V_2 ) ;
F_90 ( NULL , V_2 ) ;
#ifdef F_91
F_92 ( & V_160 ) ;
F_7 ( V_161 L_8 , V_2 ,
V_13 , F_93 ( & V_160 ) ) ;
#endif
V_48:
return V_2 ;
}
void F_94 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
V_7 -> V_29 = V_162 ;
F_95 ( V_2 , NULL ) ;
#ifdef F_96
F_7 ( V_34 L_9 , V_13 ,
F_28 ( & V_7 -> V_49 ) ,
F_28 ( & V_2 -> V_41 ) ) ;
#endif
F_97 ( & V_2 -> V_19 ) ;
F_97 ( & V_2 -> V_41 ) ;
F_97 ( & V_7 -> V_49 ) ;
#ifdef F_91
if ( F_93 ( & V_2 -> V_94 ) != 1 ) {
F_7 ( V_161 L_10 ,
V_2 , V_13 , F_93 ( & V_2 -> V_94 ) ) ;
F_7 ( V_161 L_11 ,
F_93 ( & V_160 ) ) ;
} else {
F_98 ( & V_160 ) ;
F_7 ( V_161 L_12 , V_2 ,
V_13 , F_93 ( & V_160 ) ) ;
}
#endif
F_15 ( V_2 ) ;
}
void F_99 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_95 ( V_2 , NULL ) ;
F_97 ( & V_2 -> V_41 ) ;
F_97 ( & V_7 -> V_49 ) ;
V_7 -> V_163 = 0 ;
V_7 -> V_164 = 0 ;
V_7 -> V_165 = 0 ;
F_100 ( V_2 , 0 ) ;
V_7 -> V_166 = 0 ;
V_7 -> V_167 = 0 ;
V_7 -> V_168 = 0 ;
V_7 -> V_169 = 0 ;
V_7 -> V_170 = 0 ;
V_7 -> V_135 = 1 ;
V_7 -> V_133 = 2 ;
V_7 -> V_134 = 2 ;
V_7 -> V_171 = 0 ;
V_7 -> V_36 = 0 ;
V_7 -> V_172 = 0 ;
}
