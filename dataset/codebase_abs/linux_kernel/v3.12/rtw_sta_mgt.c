static void F_1 ( struct V_1 * V_2 )
{
V_3 ;
F_2 ( ( V_4 * ) V_2 , 0 , sizeof ( struct V_1 ) ) ;
F_3 ( & V_2 -> V_5 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_8 ) ;
V_2 -> V_9 = 0 ;
F_6 ( & V_2 -> V_10 ) ;
F_7 ( & V_2 -> V_11 ) ;
#ifdef F_8
F_4 ( & V_2 -> V_12 ) ;
F_4 ( & V_2 -> V_13 ) ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
V_2 -> V_17 = false ;
#ifdef F_8
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = 0 ;
#endif
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
#endif
V_26 ;
}
T_1 F_9 ( struct V_27 * V_28 )
{
struct V_1 * V_2 ;
T_2 V_29 ;
V_3 ;
V_28 -> V_30 = F_10 ( sizeof( struct V_1 ) * V_31 + 4 ) ;
if ( ! V_28 -> V_30 )
return V_32 ;
V_28 -> V_33 = V_28 -> V_30 + 4 -
( ( V_34 ) ( V_28 -> V_30 ) & 3 ) ;
F_5 ( & V_28 -> V_35 ) ;
F_3 ( & V_28 -> V_36 ) ;
V_28 -> V_37 = 0 ;
F_5 ( & V_28 -> V_8 ) ;
F_5 ( & V_28 -> V_38 ) ;
V_2 = (struct V_1 * ) ( V_28 -> V_33 ) ;
for ( V_29 = 0 ; V_29 < V_31 ; V_29 ++ ) {
F_1 ( V_2 ) ;
F_4 ( & ( V_28 -> V_39 [ V_29 ] ) ) ;
F_11 ( & V_2 -> V_6 , F_12 ( & V_28 -> V_35 ) ) ;
V_2 ++ ;
}
#ifdef F_8
V_28 -> V_40 = 0 ;
V_28 -> V_41 = 0 ;
F_4 ( & V_28 -> V_12 ) ;
F_4 ( & V_28 -> V_13 ) ;
F_3 ( & V_28 -> V_42 ) ;
F_3 ( & V_28 -> V_43 ) ;
V_28 -> V_44 = 0 ;
V_28 -> V_45 = 0 ;
V_28 -> V_46 = 3 ;
V_28 -> V_47 = 3 ;
V_28 -> V_14 = 3 ;
V_28 -> V_48 = V_31 ;
#endif
V_26 ;
return V_49 ;
}
inline int F_13 ( struct V_27 * V_50 , struct V_1 * V_51 )
{
int V_52 = ( ( ( V_4 * ) V_51 ) - V_50 -> V_33 ) / sizeof( struct V_1 ) ;
if ( ! F_14 ( V_52 ) )
F_15 ( L_1 , V_53 , V_52 ) ;
return V_52 ;
}
inline struct V_1 * F_16 ( struct V_27 * V_50 , int V_52 )
{
if ( ! F_14 ( V_52 ) )
F_15 ( L_1 , V_53 , V_52 ) ;
return (struct V_1 * ) ( V_50 -> V_33 + V_52 * sizeof( struct V_1 ) ) ;
}
void F_17 ( struct V_54 * V_55 )
{
V_3 ;
F_18 ( & V_55 -> V_5 ) ;
F_18 ( & ( V_55 -> V_56 . V_57 . V_5 ) ) ;
F_18 ( & ( V_55 -> V_58 . V_57 . V_5 ) ) ;
F_18 ( & ( V_55 -> V_59 . V_57 . V_5 ) ) ;
F_18 ( & ( V_55 -> V_60 . V_57 . V_5 ) ) ;
V_26 ;
}
static void F_19 ( struct V_61 * V_62 )
{
V_3 ;
F_18 ( & V_62 -> V_5 ) ;
F_18 ( & ( V_62 -> V_63 . V_5 ) ) ;
V_26 ;
}
void F_20 ( struct V_1 * V_2 )
{
V_3 ;
if ( & V_2 -> V_5 != NULL )
F_18 ( & V_2 -> V_5 ) ;
F_17 ( & V_2 -> V_10 ) ;
F_19 ( & V_2 -> V_11 ) ;
V_26 ;
}
void F_21 ( struct V_27 * V_28 )
{
unsigned long V_64 ;
struct V_65 * V_66 , * V_67 ;
struct V_1 * V_2 = NULL ;
V_3 ;
F_22 ( & V_28 -> V_36 , & V_64 ) ;
V_67 = F_12 ( & V_28 -> V_35 ) ;
V_66 = F_23 ( V_67 ) ;
while ( ( F_24 ( V_67 , V_66 ) ) == false ) {
V_2 = F_25 ( V_66 , struct V_1 , V_6 ) ;
V_66 = F_23 ( V_66 ) ;
F_20 ( V_2 ) ;
}
F_26 ( & V_28 -> V_36 , & V_64 ) ;
V_26 ;
}
static void F_27 ( struct V_27 * V_28 )
{
#ifdef F_8
struct V_68 * V_69 = & V_28 -> V_70 ;
#endif
F_21 ( V_28 ) ;
F_18 ( & V_28 -> V_35 . V_5 ) ;
F_18 ( & V_28 -> V_36 ) ;
F_18 ( & V_28 -> V_38 . V_5 ) ;
F_18 ( & V_28 -> V_8 . V_5 ) ;
#ifdef F_8
F_18 ( & V_28 -> V_42 ) ;
F_18 ( & V_28 -> V_43 ) ;
F_18 ( & V_69 -> V_71 . V_5 ) ;
#endif
}
T_1 F_28 ( struct V_27 * V_28 )
{
unsigned long V_64 ;
struct V_65 * V_67 , * V_66 ;
struct V_1 * V_2 = NULL ;
struct V_72 * V_73 ;
int V_74 ;
V_3 ;
if ( V_28 ) {
F_22 ( & V_28 -> V_36 , & V_64 ) ;
for ( V_74 = 0 ; V_74 < V_31 ; V_74 ++ ) {
V_67 = & ( V_28 -> V_39 [ V_74 ] ) ;
V_66 = F_23 ( V_67 ) ;
while ( ( F_24 ( V_67 , V_66 ) ) == false ) {
int V_29 ;
V_2 = F_25 ( V_66 , struct V_1 , V_7 ) ;
V_66 = F_23 ( V_66 ) ;
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ ) {
V_73 = & V_2 -> V_75 [ V_29 ] ;
F_29 ( & V_73 -> V_76 ) ;
}
}
}
F_26 ( & V_28 -> V_36 , & V_64 ) ;
F_27 ( V_28 ) ;
if ( V_28 -> V_30 ) {
F_30 ( V_28 -> V_30 , sizeof( struct V_1 ) * V_31 + 4 ) ;
}
}
V_26 ;
return V_49 ;
}
struct V_1 * F_31 ( struct V_27 * V_28 , V_4 * V_77 )
{
unsigned long V_64 , V_78 ;
T_2 V_74 ;
struct V_65 * V_79 ;
struct V_1 * V_2 ;
struct V_80 * V_81 ;
struct V_72 * V_73 ;
int V_29 = 0 ;
T_3 V_82 = 0xffff ;
V_3 ;
V_81 = & V_28 -> V_35 ;
F_22 ( & ( V_81 -> V_5 ) , & V_64 ) ;
if ( F_32 ( V_81 ) == true ) {
F_26 ( & ( V_81 -> V_5 ) , & V_64 ) ;
V_2 = NULL ;
} else {
V_2 = F_25 ( F_23 ( & V_81 -> V_83 ) , struct V_1 , V_6 ) ;
F_33 ( & ( V_2 -> V_6 ) ) ;
F_26 ( & ( V_81 -> V_5 ) , & V_64 ) ;
F_1 ( V_2 ) ;
memcpy ( V_2 -> V_77 , V_77 , V_84 ) ;
V_74 = F_34 ( V_77 ) ;
F_35 ( V_85 , V_86 , ( L_2 , V_74 ) ) ;
if ( V_74 >= V_31 ) {
F_35 ( V_85 , V_87 , ( L_3 ) ) ;
V_2 = NULL ;
goto exit;
}
V_79 = & ( V_28 -> V_39 [ V_74 ] ) ;
F_22 ( & ( V_28 -> V_36 ) , & V_78 ) ;
F_11 ( & V_2 -> V_7 , V_79 ) ;
V_28 -> V_37 ++ ;
F_26 ( & ( V_28 -> V_36 ) , & V_78 ) ;
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ )
memcpy ( & V_2 -> V_11 . V_88 . V_89 [ V_29 ] , & V_82 , 2 ) ;
F_35 ( V_85 , V_86 ,
( L_4 ,
V_28 -> V_37 , V_77 ) ) ;
F_36 ( V_28 -> V_90 , V_2 ) ;
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ ) {
V_73 = & V_2 -> V_75 [ V_29 ] ;
V_73 -> V_90 = V_28 -> V_90 ;
V_73 -> V_91 = false ;
V_73 -> V_92 = 0xffff ;
V_73 -> V_93 = 0xffff ;
V_73 -> V_94 = 64 ;
F_5 ( & V_73 -> V_95 ) ;
F_37 ( V_73 ) ;
}
V_2 -> V_96 . V_97 = ( - 1 ) ;
V_2 -> V_96 . V_98 = ( - 1 ) ;
V_2 -> V_99 = 0xffff ;
}
exit:
V_26 ;
return V_2 ;
}
T_1 F_38 ( struct V_100 * V_90 , struct V_1 * V_2 )
{
int V_29 ;
unsigned long V_101 ;
struct V_80 * V_81 ;
struct V_72 * V_73 ;
struct V_54 * V_102 ;
struct V_103 * V_104 = & V_90 -> V_105 ;
struct V_27 * V_28 = & V_90 -> V_50 ;
V_3 ;
if ( V_2 == NULL )
goto exit;
V_81 = & V_28 -> V_35 ;
V_102 = & V_2 -> V_10 ;
F_22 ( & V_104 -> V_5 , & V_101 ) ;
F_39 ( V_104 , & V_2 -> V_8 ) ;
V_2 -> V_9 = 0 ;
F_39 ( V_104 , & V_102 -> V_60 . V_57 ) ;
F_33 ( & ( V_102 -> V_60 . V_106 ) ) ;
F_39 ( V_104 , & V_102 -> V_59 . V_57 ) ;
F_33 ( & ( V_102 -> V_59 . V_106 ) ) ;
F_39 ( V_104 , & V_102 -> V_58 . V_57 ) ;
F_33 ( & ( V_102 -> V_58 . V_106 ) ) ;
F_39 ( V_104 , & V_102 -> V_56 . V_57 ) ;
F_33 ( & ( V_102 -> V_56 . V_106 ) ) ;
F_26 ( & V_104 -> V_5 , & V_101 ) ;
F_33 ( & V_2 -> V_7 ) ;
F_35 ( V_85 , V_87 , ( L_5 , V_28 -> V_37 , V_2 -> V_77 [ 0 ] , V_2 -> V_77 [ 1 ] , V_2 -> V_77 [ 2 ] , V_2 -> V_77 [ 3 ] , V_2 -> V_77 [ 4 ] , V_2 -> V_77 [ 5 ] ) ) ;
V_28 -> V_37 -- ;
F_6 ( & V_2 -> V_10 ) ;
F_7 ( & V_2 -> V_11 ) ;
F_29 ( & V_2 -> V_107 ) ;
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ ) {
unsigned long V_64 ;
struct V_65 * V_67 , * V_66 ;
union V_108 * V_109 ;
struct V_80 * V_110 ;
struct V_80 * V_111 = & V_90 -> V_112 . V_113 ;
V_73 = & V_2 -> V_75 [ V_29 ] ;
F_29 ( & V_73 -> V_76 ) ;
V_110 = & V_73 -> V_95 ;
F_22 ( & V_110 -> V_5 , & V_64 ) ;
V_67 = F_12 ( V_110 ) ;
V_66 = F_23 ( V_67 ) ;
while ( ! F_40 ( V_67 ) ) {
V_109 = F_25 ( V_66 , union V_108 , V_114 ) ;
V_66 = F_23 ( V_66 ) ;
F_33 ( & ( V_109 -> V_114 . V_115 . V_6 ) ) ;
F_41 ( V_109 , V_111 ) ;
}
F_26 ( & V_110 -> V_5 , & V_64 ) ;
}
if ( ! ( V_2 -> V_116 & V_117 ) )
F_42 ( V_90 , V_118 , V_2 , false ) ;
#ifdef F_8
F_22 ( & V_28 -> V_43 , & V_101 ) ;
if ( ! F_40 ( & V_2 -> V_13 ) ) {
F_33 ( & V_2 -> V_13 ) ;
V_28 -> V_45 -- ;
}
F_26 ( & V_28 -> V_43 , & V_101 ) ;
V_2 -> V_14 = 0 ;
V_2 -> V_119 = 0 ;
V_2 -> V_120 = 0 ;
V_2 -> V_121 = 0 ;
V_2 -> V_122 = 0 ;
V_2 -> V_123 = 0 ;
V_2 -> V_124 = 0 ;
V_2 -> V_125 = 0 ;
V_2 -> V_126 = 0 ;
V_28 -> V_40 &= ~ F_43 ( V_2 -> V_127 ) ;
V_28 -> V_41 &= ~ F_43 ( V_2 -> V_127 ) ;
if ( ( V_2 -> V_127 > 0 ) && ( V_28 -> V_128 [ V_2 -> V_127 - 1 ] == V_2 ) ) {
V_28 -> V_128 [ V_2 -> V_127 - 1 ] = NULL ;
V_2 -> V_127 = 0 ;
}
V_2 -> V_24 = 0 ;
#endif
F_22 ( & ( V_81 -> V_5 ) , & V_101 ) ;
F_11 ( & V_2 -> V_6 , F_12 ( V_81 ) ) ;
F_26 ( & ( V_81 -> V_5 ) , & V_101 ) ;
exit:
V_26 ;
return V_49 ;
}
void F_44 ( struct V_100 * V_90 )
{
unsigned long V_64 ;
struct V_65 * V_66 , * V_67 ;
T_2 V_74 ;
struct V_1 * V_2 = NULL ;
struct V_27 * V_28 = & V_90 -> V_50 ;
struct V_1 * V_129 = F_45 ( V_90 ) ;
V_3 ;
if ( V_28 -> V_37 == 1 )
goto exit;
F_22 ( & V_28 -> V_36 , & V_64 ) ;
for ( V_74 = 0 ; V_74 < V_31 ; V_74 ++ ) {
V_67 = & ( V_28 -> V_39 [ V_74 ] ) ;
V_66 = F_23 ( V_67 ) ;
while ( ( ! F_24 ( V_67 , V_66 ) ) ) {
V_2 = F_25 ( V_66 , struct V_1 , V_7 ) ;
V_66 = F_23 ( V_66 ) ;
if ( V_129 != V_2 )
F_38 ( V_90 , V_2 ) ;
}
}
F_26 ( & V_28 -> V_36 , & V_64 ) ;
exit:
V_26 ;
}
struct V_1 * F_46 ( struct V_27 * V_28 , V_4 * V_77 )
{
unsigned long V_64 ;
struct V_65 * V_66 , * V_67 ;
struct V_1 * V_2 = NULL ;
T_1 V_74 ;
V_4 * V_130 ;
V_4 V_131 [ V_84 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_3 ;
if ( V_77 == NULL )
return NULL ;
if ( F_47 ( V_77 ) )
V_130 = V_131 ;
else
V_130 = V_77 ;
V_74 = F_34 ( V_130 ) ;
F_22 ( & V_28 -> V_36 , & V_64 ) ;
V_67 = & ( V_28 -> V_39 [ V_74 ] ) ;
V_66 = F_23 ( V_67 ) ;
while ( ( ! F_24 ( V_67 , V_66 ) ) ) {
V_2 = F_25 ( V_66 , struct V_1 , V_7 ) ;
if ( ( F_48 ( V_2 -> V_77 , V_130 , V_84 ) ) == true ) {
break;
}
V_2 = NULL ;
V_66 = F_23 ( V_66 ) ;
}
F_26 ( & V_28 -> V_36 , & V_64 ) ;
V_26 ;
return V_2 ;
}
T_1 F_49 ( struct V_100 * V_90 )
{
struct V_1 * V_2 ;
T_1 V_132 = V_49 ;
unsigned char V_133 [ V_84 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_27 * V_28 = & V_90 -> V_50 ;
V_3 ;
V_2 = F_31 ( V_28 , V_133 ) ;
if ( V_2 == NULL ) {
V_132 = V_32 ;
F_35 ( V_85 , V_87 , ( L_6 ) ) ;
goto exit;
}
V_2 -> V_134 = 1 ;
exit:
V_26 ;
return V_132 ;
}
struct V_1 * F_45 ( struct V_100 * V_90 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = & V_90 -> V_50 ;
V_4 V_131 [ V_84 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_3 ;
V_2 = F_46 ( V_28 , V_131 ) ;
V_26 ;
return V_2 ;
}
V_4 F_50 ( struct V_100 * V_90 , V_4 * V_135 )
{
V_4 V_132 = true ;
#ifdef F_8
unsigned long V_64 ;
struct V_65 * V_66 , * V_67 ;
struct V_136 * V_137 ;
V_4 V_138 = false ;
struct V_27 * V_28 = & V_90 -> V_50 ;
struct V_68 * V_69 = & V_28 -> V_70 ;
struct V_80 * V_139 = & V_69 -> V_71 ;
F_22 ( & ( V_139 -> V_5 ) , & V_64 ) ;
V_67 = F_12 ( V_139 ) ;
V_66 = F_23 ( V_67 ) ;
while ( ( ! F_24 ( V_67 , V_66 ) ) ) {
V_137 = F_25 ( V_66 , struct V_136 , V_6 ) ;
V_66 = F_23 ( V_66 ) ;
if ( F_48 ( V_137 -> V_130 , V_135 , V_84 ) ) {
if ( V_137 -> V_140 ) {
V_138 = true ;
break;
}
}
}
F_26 ( & ( V_139 -> V_5 ) , & V_64 ) ;
if ( V_69 -> V_141 == 1 )
V_132 = ( V_138 ) ? false : true ;
else if ( V_69 -> V_141 == 2 )
V_132 = ( V_138 ) ? true : false ;
else
V_132 = true ;
#endif
return V_132 ;
}
