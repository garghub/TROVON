static inline void F_1 ( struct V_1 * V_1 , int V_2 )
{
F_2 ( V_1 -> V_3 , V_4 , V_5 ,
V_6 [ V_2 ] [ 0 ] . V_7 , V_6 [ V_2 ] [ 0 ] . V_8 , 0 ) ;
F_2 ( V_1 -> V_9 , V_4 , V_5 ,
V_6 [ V_2 ] [ 1 ] . V_7 , V_6 [ V_2 ] [ 1 ] . V_8 , 0 ) ;
}
static inline void F_3 ( struct V_1 * V_1 , int V_2 )
{
F_2 ( V_1 -> V_3 , V_4 , V_5 ,
V_10 [ V_2 ] [ 0 ] . V_7 , V_10 [ V_2 ] [ 0 ] . V_8 , 0 ) ;
F_2 ( V_1 -> V_9 , V_4 , V_5 ,
V_10 [ V_2 ] [ 1 ] . V_7 , V_10 [ V_2 ] [ 1 ] . V_8 , 0 ) ;
}
static int F_4 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = NULL ;
V_1 = F_5 ( sizeof( struct V_1 ) , V_13 ) ;
if ( V_1 == NULL ) {
F_6 ( ( L_1 ) ) ;
return - V_14 ;
}
snprintf ( V_1 -> V_15 . V_16 , sizeof( V_1 -> V_15 . V_16 ) , L_2 , V_17 ) ;
F_7 ( V_12 , & V_1 -> V_15 , V_18 ) ;
if ( F_8 ( & V_1 -> V_15 ) < 0 ) {
F_9 ( ( L_3 ) ) ;
F_10 ( V_1 ) ;
return - V_19 ;
}
V_1 -> V_20 = F_11 ( & V_12 -> V_21 , & V_1 -> V_15 ,
L_4 , V_22 , NULL ) ;
V_1 -> V_3 = F_11 ( & V_12 -> V_21 , & V_1 -> V_15 ,
L_5 , V_23 , NULL ) ;
V_1 -> V_9 = F_11 ( & V_12 -> V_21 , & V_1 -> V_15 ,
L_5 , V_24 , NULL ) ;
V_1 -> V_25 = F_11 ( & V_12 -> V_21 , & V_1 -> V_15 ,
L_6 , V_26 , NULL ) ;
V_1 -> V_27 = F_11 ( & V_12 -> V_21 , & V_1 -> V_15 ,
L_7 , V_28 , NULL ) ;
V_1 -> V_29 = F_11 ( & V_12 -> V_21 , & V_1 -> V_15 ,
L_8 , V_30 , NULL ) ;
if ( ! V_1 -> V_3 || ! V_1 -> V_9 || ! V_1 -> V_25 ||
! V_1 -> V_27 || ! V_1 -> V_20 || ! V_1 -> V_29 ) {
F_12 ( L_9 ) ;
F_13 ( & V_1 -> V_15 ) ;
F_10 ( V_1 ) ;
return - V_31 ;
}
V_12 -> V_32 = V_1 ;
return 0 ;
}
static int F_14 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = (struct V_1 * ) V_12 -> V_32 ;
struct V_33 V_34 ;
struct V_35 V_36 ;
T_1 V_37 = V_38 ;
int V_39 = 0 , V_40 = 0 ;
F_15 ( V_1 , V_41 , V_42 , V_37 ) ;
V_39 = 0 ;
F_15 ( V_1 , V_43 , V_5 , V_44 ,
V_45 , 0 ) ;
V_36 . V_46 = V_47 ;
V_36 . V_48 = V_49 ;
V_36 . type = V_50 ;
F_16 ( V_1 , V_29 , V_51 , & V_36 ) ;
V_1 -> V_52 . V_29 = 0 ;
V_1 -> V_52 . type = V_53 ;
V_1 -> V_52 . V_54 = V_55 ;
F_16 ( V_1 , V_29 , V_56 , & V_1 -> V_52 ) ;
F_16 ( V_1 , V_41 , V_42 , V_37 ) ;
F_3 ( V_1 , 6 ) ;
F_1 ( V_1 , 6 ) ;
F_17 ( V_1 , V_43 , V_5 , 3 , 17 , 0 ) ;
F_17 ( V_1 , V_43 , V_5 , 3 , 13 , 0 ) ;
V_1 -> V_57 = 0 ;
V_1 -> V_58 = 1 ;
V_1 -> V_59 = V_60 ;
V_34 . V_48 = 0x1b ;
V_34 . V_61 = 0 ;
V_34 . V_62 = V_63 [ 0 ] . V_64 ;
V_34 . V_65 = & V_63 [ 0 ] . V_66 [ 0 ] ;
V_40 = F_18 ( & V_1 -> V_15 , & V_34 , 1 ) ;
if ( V_40 == 1 ) {
V_67 . V_61 &= ~ V_68 ;
for ( V_39 = 1 ; ; V_39 ++ ) {
if ( - 1 == V_63 [ V_39 ] . V_64 )
break;
V_34 . V_62 = V_63 [ V_39 ] . V_64 ;
V_34 . V_65 = & V_63 [ V_39 ] . V_66 [ 0 ] ;
V_40 = F_18 ( & V_1 -> V_15 , & V_34 , 1 ) ;
if ( V_40 != 1 ) {
F_6 ( ( L_10 ) ) ;
goto V_40;
}
}
F_19 ( ( L_11 ) ) ;
}
V_40:
F_20 ( V_12 , V_69 [ V_1 -> V_57 ] . V_70 ,
V_69 [ V_1 -> V_57 ] . V_71 ) ;
F_21 ( V_12 , V_72 , 0x00000000 ) ;
F_21 ( V_12 , V_73 , 0x02000200 ) ;
F_21 ( V_12 , V_74 , ( V_75 | V_76 | V_77 | V_78 ) ) ;
return 0 ;
}
static int F_22 ( struct V_79 * V_79 , void * V_80 , struct V_81 * V_82 )
{
struct V_11 * V_12 = ( (struct V_83 * ) V_80 ) -> V_12 ;
int V_39 ;
for ( V_39 = V_84 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( V_85 [ V_39 ] . V_86 == V_82 -> V_86 ) {
* V_82 = V_85 [ V_39 ] ;
F_6 ( ( L_12 , V_82 -> V_86 ) ) ;
return 0 ;
}
}
return V_12 -> V_87 -> V_88 -> F_22 ( V_79 , V_80 , V_82 ) ;
}
static int F_23 ( struct V_79 * V_79 , void * V_80 , struct V_89 * V_90 )
{
struct V_11 * V_12 = ( (struct V_83 * ) V_80 ) -> V_12 ;
struct V_1 * V_1 = (struct V_1 * ) V_12 -> V_32 ;
int V_39 ;
for ( V_39 = V_84 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( V_85 [ V_39 ] . V_86 == V_90 -> V_86 )
break;
}
if ( V_39 < 0 )
return V_12 -> V_87 -> V_88 -> F_23 ( V_79 , V_80 , V_90 ) ;
if ( V_90 -> V_86 == V_91 ) {
V_90 -> V_92 = V_1 -> V_58 ;
F_6 ( ( L_13 , V_90 -> V_92 ) ) ;
return 0 ;
}
F_24 ( ( L_13 , V_90 -> V_92 ) ) ;
return 0 ;
}
static int F_25 ( struct V_79 * V_79 , void * V_80 , struct V_89 * V_90 )
{
struct V_11 * V_12 = ( (struct V_83 * ) V_80 ) -> V_12 ;
struct V_1 * V_1 = (struct V_1 * ) V_12 -> V_32 ;
int V_39 = 0 ;
for ( V_39 = V_84 - 1 ; V_39 >= 0 ; V_39 -- ) {
if ( V_85 [ V_39 ] . V_86 == V_90 -> V_86 )
break;
}
if ( V_39 < 0 )
return V_12 -> V_87 -> V_88 -> F_25 ( V_79 , V_80 , V_90 ) ;
if ( V_90 -> V_86 == V_91 ) {
V_1 -> V_58 = V_90 -> V_92 ;
F_3 ( V_1 , V_90 -> V_92 ? 6 :
V_93 [ V_1 -> V_57 ] ) ;
F_24 ( ( L_14 , V_90 -> V_92 ) ) ;
}
return 0 ;
}
static int F_26 ( struct V_79 * V_79 , void * V_80 , struct V_94 * V_39 )
{
F_24 ( ( L_15 , V_39 -> V_95 ) ) ;
if ( V_39 -> V_95 >= V_96 )
return - V_97 ;
memcpy ( V_39 , & V_98 [ V_39 -> V_95 ] , sizeof( struct V_94 ) ) ;
return 0 ;
}
static int F_27 ( struct V_79 * V_79 , void * V_80 , unsigned int * V_39 )
{
struct V_11 * V_12 = ( (struct V_83 * ) V_80 ) -> V_12 ;
struct V_1 * V_1 = (struct V_1 * ) V_12 -> V_32 ;
* V_39 = V_1 -> V_57 ;
F_24 ( ( L_16 , * V_39 ) ) ;
return 0 ;
}
static int F_28 ( struct V_79 * V_79 , void * V_80 , unsigned int V_7 )
{
struct V_11 * V_12 = ( (struct V_83 * ) V_80 ) -> V_12 ;
struct V_1 * V_1 = (struct V_1 * ) V_12 -> V_32 ;
int V_40 = 0 ;
int V_39 = 0 ;
F_24 ( ( L_17 , V_7 ) ) ;
if ( V_7 >= V_96 )
return - V_97 ;
V_1 -> V_57 = V_7 ;
F_20 ( V_12 , V_69 [ V_7 ] . V_70 ,
V_69 [ V_7 ] . V_71 ) ;
switch ( V_7 ) {
case V_99 :
V_39 = V_44 ;
V_40 = F_17 ( V_1 , V_43 , V_5 , 3 , 17 , 0 ) ;
if ( ! V_40 )
V_40 = F_17 ( V_1 , V_43 , V_5 , 3 , 13 , 0 ) ;
break;
case V_100 :
V_39 = V_101 ;
break;
case V_102 :
V_39 = V_103 ;
break;
case V_104 :
V_39 = V_44 ;
V_40 = F_17 ( V_1 , V_43 , V_5 , 1 , 17 , 0 ) ;
break;
}
if ( V_40 )
return V_40 ;
if ( F_15 ( V_1 , V_43 , V_5 , V_39 , V_45 , 0 ) )
F_12 ( V_105 L_18 ) ;
if ( 0 == V_1 -> V_58 )
F_3 ( V_1 , V_93 [ V_7 ] ) ;
return 0 ;
}
static int F_29 ( struct V_79 * V_79 , void * V_80 , struct V_106 * V_107 )
{
struct V_11 * V_12 = ( (struct V_83 * ) V_80 ) -> V_12 ;
struct V_1 * V_1 = (struct V_1 * ) V_12 -> V_32 ;
if ( V_107 -> V_95 ) {
F_6 ( ( L_19 , V_107 -> V_95 ) ) ;
return - V_97 ;
}
F_24 ( ( L_20 , V_107 -> V_95 ) ) ;
memset ( V_107 , 0 , sizeof( * V_107 ) ) ;
F_30 ( V_107 -> V_16 , L_21 , sizeof( V_107 -> V_16 ) ) ;
V_107 -> type = V_53 ;
V_107 -> V_108 = V_109 | V_110 |
V_111 | V_112 | V_113 ;
V_107 -> V_114 = V_1 -> V_59 ;
return F_31 ( V_12 , V_29 , V_115 , V_107 ) ;
}
static int F_32 ( struct V_79 * V_79 , void * V_80 , struct V_106 * V_107 )
{
struct V_11 * V_12 = ( (struct V_83 * ) V_80 ) -> V_12 ;
struct V_1 * V_1 = (struct V_1 * ) V_12 -> V_32 ;
if ( V_107 -> V_95 ) {
F_6 ( ( L_22 , V_107 -> V_95 ) ) ;
return - V_97 ;
}
V_1 -> V_59 = V_107 -> V_114 ;
return F_31 ( V_12 , V_29 , V_116 , V_107 ) ;
}
static int F_33 ( struct V_79 * V_79 , void * V_80 , struct V_117 * V_118 )
{
struct V_11 * V_12 = ( (struct V_83 * ) V_80 ) -> V_12 ;
struct V_1 * V_1 = (struct V_1 * ) V_12 -> V_32 ;
if ( V_1 -> V_57 ) {
F_6 ( ( L_23 ,
V_1 -> V_57 ) ) ;
return - V_97 ;
}
* V_118 = V_1 -> V_52 ;
F_24 ( ( L_24 , V_1 -> V_52 . V_54 ) ) ;
return 0 ;
}
static int F_34 ( struct V_79 * V_79 , void * V_80 , struct V_117 * V_118 )
{
struct V_11 * V_12 = ( (struct V_83 * ) V_80 ) -> V_12 ;
struct V_1 * V_1 = (struct V_1 * ) V_12 -> V_32 ;
struct V_119 * V_120 = V_12 -> V_121 ;
if ( V_118 -> V_29 )
return - V_97 ;
if ( V_53 != V_118 -> type )
return - V_97 ;
if ( V_1 -> V_57 ) {
F_6 ( ( L_25 , V_1 -> V_57 ) ) ;
return - V_97 ;
}
V_1 -> V_52 = * V_118 ;
F_24 ( ( L_26 , V_1 -> V_52 . V_54 ) ) ;
F_16 ( V_1 , V_29 , V_56 , & V_1 -> V_52 ) ;
F_35 ( & V_12 -> V_122 ) ;
V_120 -> V_123 = 0 ;
F_36 ( & V_12 -> V_122 ) ;
return 0 ;
}
static int F_37 ( struct V_79 * V_79 , void * V_80 , struct V_124 * V_125 )
{
struct V_11 * V_12 = ( (struct V_83 * ) V_80 ) -> V_12 ;
struct V_1 * V_1 = (struct V_1 * ) V_12 -> V_32 ;
if ( V_125 -> V_95 > V_96 ) {
F_6 ( ( L_27 , V_125 -> V_95 ) ) ;
return - V_97 ;
}
F_24 ( ( L_28 , V_125 -> V_95 ) ) ;
memcpy ( V_125 , & V_126 [ V_93 [ V_1 -> V_57 ] ] , sizeof( struct V_124 ) ) ;
return 0 ;
}
static int F_38 ( struct V_79 * V_79 , void * V_80 , struct V_124 * V_125 )
{
F_6 ( ( L_29 , V_125 -> V_95 ) ) ;
return 0 ;
}
static int F_39 ( struct V_79 * V_79 , void * V_80 , struct V_127 * V_128 )
{
struct V_11 * V_12 = ( (struct V_83 * ) V_80 ) -> V_12 ;
return F_31 ( V_12 , V_41 , V_129 , V_128 ) ;
}
static int F_40 ( struct V_79 * V_79 , void * V_80 , struct V_127 * V_128 )
{
struct V_11 * V_12 = ( (struct V_83 * ) V_80 ) -> V_12 ;
return F_31 ( V_12 , V_41 , V_130 , V_128 ) ;
}
static long F_41 ( struct V_79 * V_79 , void * V_80 , bool V_131 ,
int V_132 , void * V_133 )
{
struct V_11 * V_12 = ( (struct V_83 * ) V_80 ) -> V_12 ;
struct V_1 * V_1 = (struct V_1 * ) V_12 -> V_32 ;
switch ( V_132 ) {
case V_134 :
{
int V_39 = * ( int * ) V_133 ;
if ( V_39 < 0 || V_39 >= V_135 ) {
F_6 ( ( L_30 , V_39 ) ) ;
return - V_97 ;
}
F_24 ( ( L_31 , V_39 ) ) ;
F_1 ( V_1 , V_39 ) ;
return 0 ;
}
case V_136 :
{
int V_39 = * ( int * ) V_133 ;
if ( V_39 < 0 || V_39 >= V_135 ) {
F_6 ( ( L_32 , V_39 ) ) ;
return - V_97 ;
}
F_24 ( ( L_33 , V_39 ) ) ;
F_3 ( V_1 , V_39 ) ;
return 0 ;
}
default:
return - V_137 ;
}
return 0 ;
}
static int F_42 ( struct V_11 * V_12 , struct V_138 * V_139 )
{
struct V_1 * V_1 ;
F_24 ( ( L_34 , V_12 ) ) ;
F_43 ( V_12 , & V_121 ) ;
if ( F_4 ( V_12 ) ) {
F_44 ( V_12 ) ;
return - 1 ;
}
V_1 = (struct V_1 * ) V_12 -> V_32 ;
V_121 . V_140 . F_22 = F_22 ;
V_121 . V_140 . F_23 = F_23 ;
V_121 . V_140 . F_25 = F_25 ;
V_121 . V_140 . F_26 = F_26 ;
V_121 . V_140 . F_27 = F_27 ;
V_121 . V_140 . F_28 = F_28 ;
V_121 . V_140 . F_29 = F_29 ;
V_121 . V_140 . F_32 = F_32 ;
V_121 . V_140 . F_33 = F_33 ;
V_121 . V_140 . F_34 = F_34 ;
V_121 . V_140 . F_37 = F_37 ;
V_121 . V_140 . F_38 = F_38 ;
#ifdef F_45
V_121 . V_140 . F_39 = F_39 ;
V_121 . V_140 . F_40 = F_40 ;
#endif
V_121 . V_140 . F_41 = F_41 ;
if ( F_46 ( & V_1 -> V_141 , V_12 , L_35 , V_142 ) ) {
F_47 ( ( L_36 ) ) ;
F_44 ( V_12 ) ;
return - 1 ;
}
if ( F_48 ( V_12 ) ) {
if ( F_46 ( & V_1 -> V_143 , V_12 , L_35 , V_144 ) ) {
F_47 ( ( L_37 ) ) ;
}
}
F_12 ( L_38 , V_17 ) ;
V_17 ++ ;
F_14 ( V_12 ) ;
return 0 ;
}
static int F_49 ( struct V_11 * V_12 )
{
struct V_1 * V_1 = (struct V_1 * ) V_12 -> V_32 ;
F_24 ( ( L_34 , V_12 ) ) ;
F_50 ( & V_1 -> V_141 , V_12 ) ;
if ( F_48 ( V_12 ) )
F_50 ( & V_1 -> V_143 , V_12 ) ;
F_44 ( V_12 ) ;
V_17 -- ;
F_13 ( & V_1 -> V_15 ) ;
F_10 ( V_1 ) ;
return 0 ;
}
static int F_51 ( struct V_11 * V_12 , struct V_145 * V_146 )
{
struct V_1 * V_1 = (struct V_1 * ) V_12 -> V_32 ;
if ( V_147 == V_146 -> V_86 ) {
T_1 V_37 = V_147 ;
F_6 ( ( L_39 ) ) ;
F_21 ( V_12 , V_148 , 0x00404050 ) ;
F_15 ( V_1 , V_41 , V_149 , 0 ) ;
F_16 ( V_1 , V_41 , V_42 , V_37 ) ;
} else {
T_1 V_37 = V_38 ;
F_6 ( ( L_40 ) ) ;
F_21 ( V_12 , V_148 , 0x00404050 ) ;
F_15 ( V_1 , V_41 , V_149 , 1 ) ;
F_16 ( V_1 , V_41 , V_42 , V_37 ) ;
}
return 0 ;
}
static int T_2 F_52 ( void )
{
if ( F_53 ( & V_67 ) ) {
F_9 ( ( L_41 ) ) ;
return - V_31 ;
}
return 0 ;
}
static void T_3 F_54 ( void )
{
F_55 ( & V_67 ) ;
}
