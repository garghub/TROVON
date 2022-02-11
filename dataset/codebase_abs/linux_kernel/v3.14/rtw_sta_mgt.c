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
static void F_17 ( struct V_27 * V_28 )
{
struct V_54 * V_55 , * V_56 ;
struct V_1 * V_2 = NULL ;
V_3 ;
F_18 ( & V_28 -> V_36 ) ;
V_56 = F_12 ( & V_28 -> V_35 ) ;
V_55 = F_19 ( V_56 ) ;
while ( ( F_20 ( V_56 , V_55 ) ) == false ) {
V_2 = F_21 ( V_55 , struct V_1 , V_6 ) ;
V_55 = F_19 ( V_55 ) ;
}
F_22 ( & V_28 -> V_36 ) ;
V_26 ;
}
static void F_23 ( struct V_27 * V_28 )
{
F_17 ( V_28 ) ;
}
T_1 F_24 ( struct V_27 * V_28 )
{
struct V_54 * V_56 , * V_55 ;
struct V_1 * V_2 = NULL ;
struct V_57 * V_58 ;
int V_59 ;
V_3 ;
if ( V_28 ) {
F_18 ( & V_28 -> V_36 ) ;
for ( V_59 = 0 ; V_59 < V_31 ; V_59 ++ ) {
V_56 = & ( V_28 -> V_39 [ V_59 ] ) ;
V_55 = F_19 ( V_56 ) ;
while ( ( F_20 ( V_56 , V_55 ) ) == false ) {
int V_29 ;
V_2 = F_21 ( V_55 , struct V_1 , V_7 ) ;
V_55 = F_19 ( V_55 ) ;
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ ) {
V_58 = & V_2 -> V_60 [ V_29 ] ;
F_25 ( & V_58 -> V_61 ) ;
}
}
}
F_22 ( & V_28 -> V_36 ) ;
F_23 ( V_28 ) ;
if ( V_28 -> V_30 )
F_26 ( V_28 -> V_30 , sizeof( struct V_1 ) * V_31 + 4 ) ;
}
V_26 ;
return V_49 ;
}
struct V_1 * F_27 ( struct V_27 * V_28 , V_4 * V_62 )
{
T_2 V_59 ;
struct V_54 * V_63 ;
struct V_1 * V_2 ;
struct V_64 * V_65 ;
struct V_57 * V_58 ;
int V_29 = 0 ;
T_3 V_66 = 0xffff ;
V_3 ;
V_65 = & V_28 -> V_35 ;
F_18 ( & ( V_65 -> V_5 ) ) ;
if ( F_28 ( V_65 ) == true ) {
F_22 ( & V_65 -> V_5 ) ;
V_2 = NULL ;
} else {
V_2 = F_21 ( F_19 ( & V_65 -> V_67 ) , struct V_1 , V_6 ) ;
F_29 ( & ( V_2 -> V_6 ) ) ;
F_22 ( & V_65 -> V_5 ) ;
F_1 ( V_2 ) ;
memcpy ( V_2 -> V_62 , V_62 , V_68 ) ;
V_59 = F_30 ( V_62 ) ;
F_31 ( V_69 , V_70 , ( L_2 , V_59 ) ) ;
if ( V_59 >= V_31 ) {
F_31 ( V_69 , V_71 , ( L_3 ) ) ;
V_2 = NULL ;
goto exit;
}
V_63 = & ( V_28 -> V_39 [ V_59 ] ) ;
F_18 ( & ( V_28 -> V_36 ) ) ;
F_11 ( & V_2 -> V_7 , V_63 ) ;
V_28 -> V_37 ++ ;
F_22 ( & V_28 -> V_36 ) ;
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ )
memcpy ( & V_2 -> V_11 . V_72 . V_73 [ V_29 ] , & V_66 , 2 ) ;
F_31 ( V_69 , V_70 ,
( L_4 ,
V_28 -> V_37 , V_62 ) ) ;
F_32 ( V_28 -> V_74 , V_2 ) ;
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ ) {
V_58 = & V_2 -> V_60 [ V_29 ] ;
V_58 -> V_74 = V_28 -> V_74 ;
V_58 -> V_75 = false ;
V_58 -> V_76 = 0xffff ;
V_58 -> V_77 = 0xffff ;
V_58 -> V_78 = 64 ;
F_5 ( & V_58 -> V_79 ) ;
F_33 ( V_58 ) ;
}
V_2 -> V_80 . V_81 = ( - 1 ) ;
V_2 -> V_80 . V_82 = ( - 1 ) ;
V_2 -> V_83 = 0xffff ;
}
exit:
V_26 ;
return V_2 ;
}
T_1 F_34 ( struct V_84 * V_74 , struct V_1 * V_2 )
{
int V_29 ;
struct V_64 * V_65 ;
struct V_57 * V_58 ;
struct V_85 * V_86 ;
struct V_87 * V_88 = & V_74 -> V_89 ;
struct V_27 * V_28 = & V_74 -> V_50 ;
V_3 ;
if ( V_2 == NULL )
goto exit;
V_65 = & V_28 -> V_35 ;
V_86 = & V_2 -> V_10 ;
F_18 ( & V_88 -> V_5 ) ;
F_35 ( V_88 , & V_2 -> V_8 ) ;
V_2 -> V_9 = 0 ;
F_35 ( V_88 , & V_86 -> V_90 . V_91 ) ;
F_29 ( & ( V_86 -> V_90 . V_92 ) ) ;
F_35 ( V_88 , & V_86 -> V_93 . V_91 ) ;
F_29 ( & ( V_86 -> V_93 . V_92 ) ) ;
F_35 ( V_88 , & V_86 -> V_94 . V_91 ) ;
F_29 ( & ( V_86 -> V_94 . V_92 ) ) ;
F_35 ( V_88 , & V_86 -> V_95 . V_91 ) ;
F_29 ( & ( V_86 -> V_95 . V_92 ) ) ;
F_22 ( & V_88 -> V_5 ) ;
F_29 ( & V_2 -> V_7 ) ;
F_31 ( V_69 , V_71 , ( L_5 , V_28 -> V_37 , V_2 -> V_62 [ 0 ] , V_2 -> V_62 [ 1 ] , V_2 -> V_62 [ 2 ] , V_2 -> V_62 [ 3 ] , V_2 -> V_62 [ 4 ] , V_2 -> V_62 [ 5 ] ) ) ;
V_28 -> V_37 -- ;
F_6 ( & V_2 -> V_10 ) ;
F_7 ( & V_2 -> V_11 ) ;
F_25 ( & V_2 -> V_96 ) ;
for ( V_29 = 0 ; V_29 < 16 ; V_29 ++ ) {
struct V_54 * V_56 , * V_55 ;
union V_97 * V_98 ;
struct V_64 * V_99 ;
struct V_64 * V_100 = & V_74 -> V_101 . V_102 ;
V_58 = & V_2 -> V_60 [ V_29 ] ;
F_25 ( & V_58 -> V_61 ) ;
V_99 = & V_58 -> V_79 ;
F_18 ( & V_99 -> V_5 ) ;
V_56 = F_12 ( V_99 ) ;
V_55 = F_19 ( V_56 ) ;
while ( ! F_36 ( V_56 ) ) {
V_98 = F_21 ( V_55 , union V_97 , V_103 ) ;
V_55 = F_19 ( V_55 ) ;
F_29 ( & ( V_98 -> V_103 . V_104 . V_6 ) ) ;
F_37 ( V_98 , V_100 ) ;
}
F_22 ( & V_99 -> V_5 ) ;
}
if ( ! ( V_2 -> V_105 & V_106 ) )
F_38 ( V_74 , V_107 , V_2 , false ) ;
#ifdef F_8
F_18 ( & V_28 -> V_43 ) ;
if ( ! F_36 ( & V_2 -> V_13 ) ) {
F_29 ( & V_2 -> V_13 ) ;
V_28 -> V_45 -- ;
}
F_22 ( & V_28 -> V_43 ) ;
V_2 -> V_14 = 0 ;
V_2 -> V_108 = 0 ;
V_2 -> V_109 = 0 ;
V_2 -> V_110 = 0 ;
V_2 -> V_111 = 0 ;
V_2 -> V_112 = 0 ;
V_2 -> V_113 = 0 ;
V_2 -> V_114 = 0 ;
V_2 -> V_115 = 0 ;
V_28 -> V_40 &= ~ F_39 ( V_2 -> V_116 ) ;
V_28 -> V_41 &= ~ F_39 ( V_2 -> V_116 ) ;
if ( ( V_2 -> V_116 > 0 ) && ( V_28 -> V_117 [ V_2 -> V_116 - 1 ] == V_2 ) ) {
V_28 -> V_117 [ V_2 -> V_116 - 1 ] = NULL ;
V_2 -> V_116 = 0 ;
}
V_2 -> V_24 = 0 ;
#endif
F_18 ( & ( V_65 -> V_5 ) ) ;
F_11 ( & V_2 -> V_6 , F_12 ( V_65 ) ) ;
F_22 ( & V_65 -> V_5 ) ;
exit:
V_26 ;
return V_49 ;
}
void F_40 ( struct V_84 * V_74 )
{
struct V_54 * V_55 , * V_56 ;
T_2 V_59 ;
struct V_1 * V_2 = NULL ;
struct V_27 * V_28 = & V_74 -> V_50 ;
struct V_1 * V_118 = F_41 ( V_74 ) ;
V_3 ;
if ( V_28 -> V_37 == 1 )
goto exit;
F_18 ( & V_28 -> V_36 ) ;
for ( V_59 = 0 ; V_59 < V_31 ; V_59 ++ ) {
V_56 = & ( V_28 -> V_39 [ V_59 ] ) ;
V_55 = F_19 ( V_56 ) ;
while ( ( ! F_20 ( V_56 , V_55 ) ) ) {
V_2 = F_21 ( V_55 , struct V_1 , V_7 ) ;
V_55 = F_19 ( V_55 ) ;
if ( V_118 != V_2 )
F_34 ( V_74 , V_2 ) ;
}
}
F_22 ( & V_28 -> V_36 ) ;
exit:
V_26 ;
}
struct V_1 * F_42 ( struct V_27 * V_28 , V_4 * V_62 )
{
struct V_54 * V_55 , * V_56 ;
struct V_1 * V_2 = NULL ;
T_1 V_59 ;
V_4 * V_119 ;
V_4 V_120 [ V_68 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_3 ;
if ( V_62 == NULL )
return NULL ;
if ( F_43 ( V_62 ) )
V_119 = V_120 ;
else
V_119 = V_62 ;
V_59 = F_30 ( V_119 ) ;
F_18 ( & V_28 -> V_36 ) ;
V_56 = & ( V_28 -> V_39 [ V_59 ] ) ;
V_55 = F_19 ( V_56 ) ;
while ( ( ! F_20 ( V_56 , V_55 ) ) ) {
V_2 = F_21 ( V_55 , struct V_1 , V_7 ) ;
if ( ( F_44 ( V_2 -> V_62 , V_119 , V_68 ) ) == true ) {
break;
}
V_2 = NULL ;
V_55 = F_19 ( V_55 ) ;
}
F_22 ( & V_28 -> V_36 ) ;
V_26 ;
return V_2 ;
}
T_1 F_45 ( struct V_84 * V_74 )
{
struct V_1 * V_2 ;
T_1 V_121 = V_49 ;
unsigned char V_122 [ V_68 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_27 * V_28 = & V_74 -> V_50 ;
V_3 ;
V_2 = F_27 ( V_28 , V_122 ) ;
if ( V_2 == NULL ) {
V_121 = V_32 ;
F_31 ( V_69 , V_71 , ( L_6 ) ) ;
goto exit;
}
V_2 -> V_123 = 1 ;
exit:
V_26 ;
return V_121 ;
}
struct V_1 * F_41 ( struct V_84 * V_74 )
{
struct V_1 * V_2 ;
struct V_27 * V_28 = & V_74 -> V_50 ;
V_4 V_120 [ V_68 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_3 ;
V_2 = F_42 ( V_28 , V_120 ) ;
V_26 ;
return V_2 ;
}
V_4 F_46 ( struct V_84 * V_74 , V_4 * V_124 )
{
V_4 V_121 = true ;
#ifdef F_8
struct V_54 * V_55 , * V_56 ;
struct V_125 * V_126 ;
V_4 V_127 = false ;
struct V_27 * V_28 = & V_74 -> V_50 ;
struct V_128 * V_129 = & V_28 -> V_130 ;
struct V_64 * V_131 = & V_129 -> V_132 ;
F_18 ( & ( V_131 -> V_5 ) ) ;
V_56 = F_12 ( V_131 ) ;
V_55 = F_19 ( V_56 ) ;
while ( ( ! F_20 ( V_56 , V_55 ) ) ) {
V_126 = F_21 ( V_55 , struct V_125 , V_6 ) ;
V_55 = F_19 ( V_55 ) ;
if ( F_44 ( V_126 -> V_119 , V_124 , V_68 ) ) {
if ( V_126 -> V_133 ) {
V_127 = true ;
break;
}
}
}
F_22 ( & V_131 -> V_5 ) ;
if ( V_129 -> V_134 == 1 )
V_121 = ( V_127 ) ? false : true ;
else if ( V_129 -> V_134 == 2 )
V_121 = ( V_127 ) ? true : false ;
else
V_121 = true ;
#endif
return V_121 ;
}
