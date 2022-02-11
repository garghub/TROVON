static void F_1 ( struct V_1 * V_2 )
{
memset ( ( V_3 * ) V_2 , 0 , sizeof( struct V_1 ) ) ;
F_2 ( & V_2 -> V_4 ) ;
F_3 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
F_4 ( & V_2 -> V_7 ) ;
V_2 -> V_8 = 0 ;
F_5 ( & V_2 -> V_9 ) ;
F_6 ( & V_2 -> V_10 ) ;
#ifdef F_7
F_3 ( & V_2 -> V_11 ) ;
F_3 ( & V_2 -> V_12 ) ;
V_2 -> V_13 = 0 ;
V_2 -> V_14 = 0 ;
V_2 -> V_15 = 0 ;
V_2 -> V_16 = false ;
V_2 -> V_17 = 0 ;
V_2 -> V_18 = 0 ;
V_2 -> V_19 = 0 ;
V_2 -> V_20 = 0 ;
V_2 -> V_21 = 0 ;
V_2 -> V_22 = 0 ;
V_2 -> V_23 = 0 ;
V_2 -> V_24 = 0 ;
#endif
}
T_1 F_8 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
T_2 V_27 ;
V_26 -> V_28 = F_9 ( sizeof( struct V_1 ) * V_29 + 4 ) ;
if ( ! V_26 -> V_28 )
return V_30 ;
V_26 -> V_31 = V_26 -> V_28 + 4 -
( ( V_32 ) ( V_26 -> V_28 ) & 3 ) ;
F_4 ( & V_26 -> V_33 ) ;
F_2 ( & V_26 -> V_34 ) ;
V_26 -> V_35 = 0 ;
F_4 ( & V_26 -> V_7 ) ;
F_4 ( & V_26 -> V_36 ) ;
V_2 = (struct V_1 * ) ( V_26 -> V_31 ) ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
F_1 ( V_2 ) ;
F_3 ( & ( V_26 -> V_37 [ V_27 ] ) ) ;
F_10 ( & V_2 -> V_5 , F_11 ( & V_26 -> V_33 ) ) ;
V_2 ++ ;
}
#ifdef F_7
V_26 -> V_38 = 0 ;
V_26 -> V_39 = 0 ;
F_3 ( & V_26 -> V_11 ) ;
F_3 ( & V_26 -> V_12 ) ;
F_2 ( & V_26 -> V_40 ) ;
F_2 ( & V_26 -> V_41 ) ;
V_26 -> V_42 = 0 ;
V_26 -> V_43 = 0 ;
V_26 -> V_44 = 3 ;
V_26 -> V_45 = 3 ;
V_26 -> V_13 = 3 ;
V_26 -> V_46 = V_29 ;
#endif
return V_47 ;
}
inline int F_12 ( struct V_25 * V_48 , struct V_1 * V_49 )
{
int V_50 = ( ( ( V_3 * ) V_49 ) - V_48 -> V_31 ) / sizeof( struct V_1 ) ;
if ( ! F_13 ( V_50 ) )
F_14 ( L_1 , V_51 , V_50 ) ;
return V_50 ;
}
inline struct V_1 * F_15 ( struct V_25 * V_48 , int V_50 )
{
if ( ! F_13 ( V_50 ) )
F_14 ( L_1 , V_51 , V_50 ) ;
return (struct V_1 * ) ( V_48 -> V_31 + V_50 * sizeof( struct V_1 ) ) ;
}
T_1 F_16 ( struct V_25 * V_26 )
{
struct V_52 * V_53 , * V_54 ;
struct V_1 * V_2 = NULL ;
struct V_55 * V_56 ;
int V_57 ;
if ( V_26 ) {
F_17 ( & V_26 -> V_34 ) ;
for ( V_57 = 0 ; V_57 < V_29 ; V_57 ++ ) {
V_53 = & ( V_26 -> V_37 [ V_57 ] ) ;
V_54 = V_53 -> V_58 ;
while ( V_53 != V_54 ) {
int V_27 ;
V_2 = F_18 ( V_54 , struct V_1 , V_6 ) ;
V_54 = V_54 -> V_58 ;
for ( V_27 = 0 ; V_27 < 16 ; V_27 ++ ) {
V_56 = & V_2 -> V_59 [ V_27 ] ;
F_19 ( & V_56 -> V_60 ) ;
}
}
}
F_20 ( & V_26 -> V_34 ) ;
if ( V_26 -> V_28 )
F_21 ( V_26 -> V_28 ) ;
}
return V_47 ;
}
struct V_1 * F_22 ( struct V_25 * V_26 , V_3 * V_61 )
{
T_2 V_57 ;
struct V_52 * V_62 ;
struct V_1 * V_2 ;
struct V_63 * V_64 ;
struct V_55 * V_56 ;
int V_27 = 0 ;
T_3 V_65 = 0xffff ;
V_64 = & V_26 -> V_33 ;
F_17 ( & ( V_64 -> V_4 ) ) ;
if ( F_23 ( & V_64 -> V_66 ) ) {
F_20 ( & V_64 -> V_4 ) ;
V_2 = NULL ;
} else {
V_2 = F_18 ( ( & V_64 -> V_66 ) -> V_58 , struct V_1 , V_5 ) ;
F_24 ( & ( V_2 -> V_5 ) ) ;
F_20 ( & V_64 -> V_4 ) ;
F_1 ( V_2 ) ;
memcpy ( V_2 -> V_61 , V_61 , V_67 ) ;
V_57 = F_25 ( V_61 ) ;
F_26 ( V_68 , V_69 , ( L_2 , V_57 ) ) ;
if ( V_57 >= V_29 ) {
F_26 ( V_68 , V_70 , ( L_3 ) ) ;
V_2 = NULL ;
goto exit;
}
V_62 = & ( V_26 -> V_37 [ V_57 ] ) ;
F_17 ( & ( V_26 -> V_34 ) ) ;
F_10 ( & V_2 -> V_6 , V_62 ) ;
V_26 -> V_35 ++ ;
F_20 ( & V_26 -> V_34 ) ;
for ( V_27 = 0 ; V_27 < 16 ; V_27 ++ )
memcpy ( & V_2 -> V_10 . V_71 . V_72 [ V_27 ] , & V_65 , 2 ) ;
F_26 ( V_68 , V_69 ,
( L_4 ,
V_26 -> V_35 , V_61 ) ) ;
F_27 ( V_26 -> V_73 , V_2 ) ;
for ( V_27 = 0 ; V_27 < 16 ; V_27 ++ ) {
V_56 = & V_2 -> V_59 [ V_27 ] ;
V_56 -> V_73 = V_26 -> V_73 ;
V_56 -> V_74 = false ;
V_56 -> V_75 = 0xffff ;
V_56 -> V_76 = 0xffff ;
V_56 -> V_77 = 64 ;
F_4 ( & V_56 -> V_78 ) ;
F_28 ( V_56 ) ;
}
V_2 -> V_79 . V_80 = ( - 1 ) ;
V_2 -> V_79 . V_81 = ( - 1 ) ;
V_2 -> V_82 = 0xffff ;
}
exit:
return V_2 ;
}
T_1 F_29 ( struct V_83 * V_73 , struct V_1 * V_2 )
{
int V_27 ;
struct V_63 * V_64 ;
struct V_55 * V_56 ;
struct V_84 * V_85 ;
struct V_86 * V_87 = & V_73 -> V_88 ;
struct V_25 * V_26 = & V_73 -> V_48 ;
if ( V_2 == NULL )
goto exit;
V_64 = & V_26 -> V_33 ;
V_85 = & V_2 -> V_9 ;
F_17 ( & V_87 -> V_4 ) ;
F_30 ( V_87 , & V_2 -> V_7 ) ;
V_2 -> V_8 = 0 ;
F_30 ( V_87 , & V_85 -> V_89 . V_90 ) ;
F_24 ( & ( V_85 -> V_89 . V_91 ) ) ;
F_30 ( V_87 , & V_85 -> V_92 . V_90 ) ;
F_24 ( & ( V_85 -> V_92 . V_91 ) ) ;
F_30 ( V_87 , & V_85 -> V_93 . V_90 ) ;
F_24 ( & ( V_85 -> V_93 . V_91 ) ) ;
F_30 ( V_87 , & V_85 -> V_94 . V_90 ) ;
F_24 ( & ( V_85 -> V_94 . V_91 ) ) ;
F_20 ( & V_87 -> V_4 ) ;
F_24 ( & V_2 -> V_6 ) ;
F_26 ( V_68 , V_70 , ( L_5 , V_26 -> V_35 , V_2 -> V_61 [ 0 ] , V_2 -> V_61 [ 1 ] , V_2 -> V_61 [ 2 ] , V_2 -> V_61 [ 3 ] , V_2 -> V_61 [ 4 ] , V_2 -> V_61 [ 5 ] ) ) ;
V_26 -> V_35 -- ;
F_5 ( & V_2 -> V_9 ) ;
F_6 ( & V_2 -> V_10 ) ;
F_19 ( & V_2 -> V_95 ) ;
for ( V_27 = 0 ; V_27 < 16 ; V_27 ++ ) {
struct V_52 * V_53 , * V_54 ;
struct V_96 * V_97 ;
struct V_96 * V_98 ;
struct V_63 * V_99 ;
struct V_63 * V_100 = & V_73 -> V_101 . V_102 ;
V_56 = & V_2 -> V_59 [ V_27 ] ;
F_19 ( & V_56 -> V_60 ) ;
V_99 = & V_56 -> V_78 ;
F_17 ( & V_99 -> V_4 ) ;
V_53 = F_11 ( V_99 ) ;
V_54 = V_53 -> V_58 ;
while ( ! F_23 ( V_53 ) ) {
V_97 = F_18 ( V_54 , struct V_96 , V_5 ) ;
V_98 = (struct V_96 * ) V_97 ;
V_54 = V_54 -> V_58 ;
F_24 ( & ( V_98 -> V_5 ) ) ;
F_31 ( V_98 , V_100 ) ;
}
F_20 ( & V_99 -> V_4 ) ;
}
if ( ! ( V_2 -> V_103 & V_104 ) )
F_32 ( V_73 , V_105 , V_2 , false ) ;
#ifdef F_7
F_17 ( & V_26 -> V_41 ) ;
if ( ! F_23 ( & V_2 -> V_12 ) ) {
F_24 ( & V_2 -> V_12 ) ;
V_26 -> V_43 -- ;
}
F_20 ( & V_26 -> V_41 ) ;
V_2 -> V_13 = 0 ;
V_2 -> V_106 = 0 ;
V_2 -> V_107 = 0 ;
V_2 -> V_108 = 0 ;
V_2 -> V_109 = 0 ;
V_2 -> V_110 = 0 ;
V_2 -> V_111 = 0 ;
V_2 -> V_112 = 0 ;
V_2 -> V_113 = 0 ;
V_26 -> V_38 &= ~ F_33 ( V_2 -> V_114 ) ;
V_26 -> V_39 &= ~ F_33 ( V_2 -> V_114 ) ;
if ( ( V_2 -> V_114 > 0 ) && ( V_26 -> V_115 [ V_2 -> V_114 - 1 ] == V_2 ) ) {
V_26 -> V_115 [ V_2 -> V_114 - 1 ] = NULL ;
V_2 -> V_114 = 0 ;
}
V_2 -> V_23 = 0 ;
#endif
F_17 ( & ( V_64 -> V_4 ) ) ;
F_10 ( & V_2 -> V_5 , F_11 ( V_64 ) ) ;
F_20 ( & V_64 -> V_4 ) ;
exit:
return V_47 ;
}
void F_34 ( struct V_83 * V_73 )
{
struct V_52 * V_54 , * V_53 ;
T_2 V_57 ;
struct V_1 * V_2 = NULL ;
struct V_25 * V_26 = & V_73 -> V_48 ;
struct V_1 * V_116 = F_35 ( V_73 ) ;
if ( V_26 -> V_35 == 1 )
return;
F_17 ( & V_26 -> V_34 ) ;
for ( V_57 = 0 ; V_57 < V_29 ; V_57 ++ ) {
V_53 = & ( V_26 -> V_37 [ V_57 ] ) ;
V_54 = V_53 -> V_58 ;
while ( V_53 != V_54 ) {
V_2 = F_18 ( V_54 , struct V_1 , V_6 ) ;
V_54 = V_54 -> V_58 ;
if ( V_116 != V_2 )
F_29 ( V_73 , V_2 ) ;
}
}
F_20 ( & V_26 -> V_34 ) ;
}
struct V_1 * F_36 ( struct V_25 * V_26 , V_3 * V_61 )
{
struct V_52 * V_54 , * V_53 ;
struct V_1 * V_2 = NULL ;
T_1 V_57 ;
V_3 * V_117 ;
V_3 V_118 [ V_67 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
if ( V_61 == NULL )
return NULL ;
if ( F_37 ( V_61 ) )
V_117 = V_118 ;
else
V_117 = V_61 ;
V_57 = F_25 ( V_117 ) ;
F_17 ( & V_26 -> V_34 ) ;
V_53 = & ( V_26 -> V_37 [ V_57 ] ) ;
V_54 = V_53 -> V_58 ;
while ( V_53 != V_54 ) {
V_2 = F_18 ( V_54 , struct V_1 , V_6 ) ;
if ( ( ! memcmp ( V_2 -> V_61 , V_117 , V_67 ) ) == true ) {
break;
}
V_2 = NULL ;
V_54 = V_54 -> V_58 ;
}
F_20 ( & V_26 -> V_34 ) ;
return V_2 ;
}
T_1 F_38 ( struct V_83 * V_73 )
{
struct V_1 * V_2 ;
T_1 V_119 = V_47 ;
unsigned char V_120 [ V_67 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
struct V_25 * V_26 = & V_73 -> V_48 ;
V_2 = F_22 ( V_26 , V_120 ) ;
if ( V_2 == NULL ) {
V_119 = V_30 ;
F_26 ( V_68 , V_70 , ( L_6 ) ) ;
goto exit;
}
V_2 -> V_121 = 1 ;
exit:
return V_119 ;
}
struct V_1 * F_35 ( struct V_83 * V_73 )
{
struct V_1 * V_2 ;
struct V_25 * V_26 = & V_73 -> V_48 ;
V_3 V_118 [ V_67 ] = { 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
V_2 = F_36 ( V_26 , V_118 ) ;
return V_2 ;
}
V_3 F_39 ( struct V_83 * V_73 , V_3 * V_122 )
{
V_3 V_119 = true ;
#ifdef F_7
struct V_52 * V_54 , * V_53 ;
struct V_123 * V_124 ;
V_3 V_125 = false ;
struct V_25 * V_26 = & V_73 -> V_48 ;
struct V_126 * V_127 = & V_26 -> V_128 ;
struct V_63 * V_129 = & V_127 -> V_130 ;
F_17 ( & ( V_129 -> V_4 ) ) ;
V_53 = F_11 ( V_129 ) ;
V_54 = V_53 -> V_58 ;
while ( V_53 != V_54 ) {
V_124 = F_18 ( V_54 , struct V_123 , V_5 ) ;
V_54 = V_54 -> V_58 ;
if ( ! memcmp ( V_124 -> V_117 , V_122 , V_67 ) ) {
if ( V_124 -> V_131 ) {
V_125 = true ;
break;
}
}
}
F_20 ( & V_129 -> V_4 ) ;
if ( V_127 -> V_132 == 1 )
V_119 = ( V_125 ) ? false : true ;
else if ( V_127 -> V_132 == 2 )
V_119 = ( V_125 ) ? true : false ;
else
V_119 = true ;
#endif
return V_119 ;
}
