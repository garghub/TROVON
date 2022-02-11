static void F_1 ( struct V_1 * V_1 )
{
struct V_2 V_3 = {
. V_4 = V_1 -> V_5 ,
} ;
F_2 ( V_1 , V_6 , V_7 , & V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_1 , int V_8 )
{
F_4 ( V_1 -> V_9 , V_10 , V_11 ,
V_12 [ V_8 ] [ 0 ] . V_13 , V_12 [ V_8 ] [ 0 ] . V_14 , 0 ) ;
F_4 ( V_1 -> V_15 , V_10 , V_11 ,
V_12 [ V_8 ] [ 1 ] . V_13 , V_12 [ V_8 ] [ 1 ] . V_14 , 0 ) ;
F_4 ( V_1 -> V_9 , V_10 , V_11 ,
V_16 [ V_8 ] [ 0 ] . V_13 , V_16 [ V_8 ] [ 0 ] . V_14 , 0 ) ;
F_4 ( V_1 -> V_15 , V_10 , V_11 ,
V_16 [ V_8 ] [ 1 ] . V_13 , V_16 [ V_8 ] [ 1 ] . V_14 , 0 ) ;
}
static int F_5 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_6 ( V_18 -> V_21 ,
struct V_19 , V_22 ) ;
struct V_1 * V_1 = V_20 -> V_23 ;
switch ( V_18 -> V_24 ) {
case V_25 :
V_1 -> V_26 = V_18 -> V_27 ;
F_3 ( V_1 , V_18 -> V_27 ? 6 :
V_28 [ V_1 -> V_29 ] ) ;
break;
default:
return - V_30 ;
}
return 0 ;
}
static int F_7 ( struct V_19 * V_20 )
{
struct V_31 * V_32 = & V_20 -> V_22 ;
struct V_1 * V_1 = NULL ;
F_8 ( V_32 , & V_33 ,
V_25 , 0 , 1 , 1 , 1 ) ;
if ( V_32 -> error )
return V_32 -> error ;
V_1 = F_9 ( sizeof( struct V_1 ) , V_34 ) ;
if ( V_1 == NULL ) {
F_10 ( L_1 ) ;
return - V_35 ;
}
snprintf ( V_1 -> V_36 . V_37 , sizeof( V_1 -> V_36 . V_37 ) , L_2 , V_38 ) ;
F_11 ( V_20 , & V_1 -> V_36 , V_39 ) ;
if ( F_12 ( & V_1 -> V_36 ) < 0 ) {
F_13 ( L_3 ) ;
F_14 ( V_1 ) ;
return - V_40 ;
}
V_1 -> V_41 = F_15 ( & V_20 -> V_42 , & V_1 -> V_36 ,
L_4 , V_43 , NULL ) ;
V_1 -> V_9 = F_15 ( & V_20 -> V_42 , & V_1 -> V_36 ,
L_5 , V_44 , NULL ) ;
V_1 -> V_15 = F_15 ( & V_20 -> V_42 , & V_1 -> V_36 ,
L_5 , V_45 , NULL ) ;
V_1 -> V_46 = F_15 ( & V_20 -> V_42 , & V_1 -> V_36 ,
L_6 , V_47 , NULL ) ;
V_1 -> V_48 = F_15 ( & V_20 -> V_42 , & V_1 -> V_36 ,
L_7 , V_49 , NULL ) ;
V_1 -> V_6 = F_15 ( & V_20 -> V_42 , & V_1 -> V_36 ,
L_8 , V_50 , NULL ) ;
if ( ! V_1 -> V_9 || ! V_1 -> V_15 || ! V_1 -> V_46 ||
! V_1 -> V_48 || ! V_1 -> V_41 || ! V_1 -> V_6 ) {
F_16 ( L_9 ) ;
F_17 ( & V_1 -> V_36 ) ;
F_14 ( V_1 ) ;
return - V_51 ;
}
V_20 -> V_23 = V_1 ;
F_18 ( V_32 ) ;
return 0 ;
}
static int F_19 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_23 ;
struct V_52 V_53 ;
struct V_54 V_55 ;
T_1 V_56 = V_57 ;
int V_58 = 0 , V_59 = 0 ;
F_3 ( V_1 , 6 ) ;
F_20 ( V_1 , V_60 , V_61 , V_56 ) ;
V_58 = 0 ;
F_20 ( V_1 , V_62 , V_11 , V_63 ,
V_64 , 0 ) ;
V_55 . V_65 = V_66 ;
V_55 . V_67 = V_68 ;
V_55 . type = V_69 ;
F_21 ( V_1 , V_6 , V_70 , & V_55 ) ;
V_1 -> V_71 . V_6 = 0 ;
V_1 -> V_71 . type = V_72 ;
V_1 -> V_71 . V_73 = V_74 ;
F_21 ( V_1 , V_6 , V_75 , & V_1 -> V_71 ) ;
F_22 ( V_20 , V_76 , 0x00404050 ) ;
F_20 ( V_1 , V_60 , V_77 , 1 ) ;
F_20 ( V_1 , V_60 , V_61 , V_56 ) ;
F_21 ( V_1 , V_60 , V_61 , V_56 ) ;
F_23 ( V_1 , V_62 , V_11 , 3 , 17 , 0 ) ;
F_23 ( V_1 , V_62 , V_11 , 3 , 13 , 0 ) ;
V_1 -> V_29 = 0 ;
V_1 -> V_78 = V_28 [ V_1 -> V_29 ] ;
V_1 -> V_26 = 1 ;
V_1 -> V_5 = V_79 ;
F_1 ( V_1 ) ;
V_53 . V_67 = 0x1b ;
V_53 . V_80 = 0 ;
V_53 . V_81 = V_82 [ 0 ] . V_83 ;
V_53 . V_84 = & V_82 [ 0 ] . V_85 [ 0 ] ;
V_59 = F_24 ( & V_1 -> V_36 , & V_53 , 1 ) ;
if ( V_59 == 1 ) {
V_86 . V_80 &= ~ V_87 ;
for ( V_58 = 1 ; ; V_58 ++ ) {
if ( - 1 == V_82 [ V_58 ] . V_83 )
break;
V_53 . V_81 = V_82 [ V_58 ] . V_83 ;
V_53 . V_84 = & V_82 [ V_58 ] . V_85 [ 0 ] ;
V_59 = F_24 ( & V_1 -> V_36 , & V_53 , 1 ) ;
if ( V_59 != 1 ) {
F_10 ( L_10 ) ;
goto V_59;
}
}
F_25 ( L_11 ) ;
}
V_59:
F_26 ( V_20 , V_88 [ V_1 -> V_29 ] . V_89 ,
V_88 [ V_1 -> V_29 ] . V_90 ) ;
F_22 ( V_20 , V_91 , 0x00000000 ) ;
F_22 ( V_20 , V_92 , 0x02000200 ) ;
F_22 ( V_20 , V_93 , ( V_94 | V_95 | V_96 | V_97 ) ) ;
return 0 ;
}
static int F_27 ( struct V_98 * V_98 , void * V_99 , struct V_100 * V_58 )
{
F_28 ( L_12 , V_58 -> V_101 ) ;
if ( V_58 -> V_101 >= V_102 )
return - V_30 ;
memcpy ( V_58 , & V_103 [ V_58 -> V_101 ] , sizeof( struct V_100 ) ) ;
return 0 ;
}
static int F_29 ( struct V_98 * V_98 , void * V_99 , unsigned int * V_58 )
{
struct V_19 * V_20 = ( (struct V_104 * ) V_99 ) -> V_20 ;
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_23 ;
* V_58 = V_1 -> V_29 ;
F_28 ( L_13 , * V_58 ) ;
return 0 ;
}
static int F_30 ( struct V_98 * V_98 , void * V_99 , unsigned int V_13 )
{
struct V_19 * V_20 = ( (struct V_104 * ) V_99 ) -> V_20 ;
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_23 ;
int V_59 = 0 ;
int V_58 = 0 ;
F_28 ( L_14 , V_13 ) ;
if ( V_13 >= V_102 )
return - V_30 ;
V_1 -> V_29 = V_13 ;
F_26 ( V_20 , V_88 [ V_13 ] . V_89 ,
V_88 [ V_13 ] . V_90 ) ;
switch ( V_13 ) {
case V_105 :
V_58 = V_63 ;
V_59 = F_23 ( V_1 , V_62 , V_11 , 3 , 17 , 0 ) ;
if ( ! V_59 )
V_59 = F_23 ( V_1 , V_62 , V_11 , 3 , 13 , 0 ) ;
break;
case V_106 :
V_58 = V_107 ;
break;
case V_108 :
V_58 = V_109 ;
break;
case V_110 :
V_58 = V_63 ;
V_59 = F_23 ( V_1 , V_62 , V_11 , 1 , 17 , 0 ) ;
break;
}
if ( V_59 )
return V_59 ;
if ( F_20 ( V_1 , V_62 , V_11 , V_58 , V_64 , 0 ) )
F_16 ( L_15 ) ;
V_1 -> V_78 = V_28 [ V_13 ] ;
if ( 0 == V_1 -> V_26 )
F_3 ( V_1 , V_1 -> V_78 ) ;
if ( V_1 -> V_78 == 0 )
F_1 ( V_1 ) ;
return 0 ;
}
static int F_31 ( struct V_98 * V_98 , void * V_99 , struct V_2 * V_3 )
{
struct V_19 * V_20 = ( (struct V_104 * ) V_99 ) -> V_20 ;
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_23 ;
if ( V_3 -> V_101 ) {
F_10 ( L_16 ,
V_3 -> V_101 ) ;
return - V_30 ;
}
F_28 ( L_17 , V_3 -> V_101 ) ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
F_32 ( V_3 -> V_37 , L_18 , sizeof( V_3 -> V_37 ) ) ;
V_3 -> type = V_72 ;
V_3 -> V_111 = V_112 | V_113 |
V_114 | V_115 | V_116 ;
V_3 -> V_4 = V_1 -> V_5 ;
return F_33 ( V_20 , V_6 , V_117 , V_3 ) ;
}
static int F_34 ( struct V_98 * V_98 , void * V_99 , const struct V_2 * V_3 )
{
struct V_19 * V_20 = ( (struct V_104 * ) V_99 ) -> V_20 ;
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_23 ;
if ( V_3 -> V_101 ) {
F_10 ( L_19 ,
V_3 -> V_101 ) ;
return - V_30 ;
}
V_1 -> V_5 = V_3 -> V_4 ;
return F_33 ( V_20 , V_6 , V_7 , V_3 ) ;
}
static int F_35 ( struct V_98 * V_98 , void * V_99 , T_1 * V_118 )
{
struct V_19 * V_20 = ( (struct V_104 * ) V_99 ) -> V_20 ;
return F_33 ( V_20 , V_62 , V_119 , V_118 ) ;
}
static int F_36 ( struct V_98 * V_98 , void * V_99 , struct V_120 * V_121 )
{
struct V_19 * V_20 = ( (struct V_104 * ) V_99 ) -> V_20 ;
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_23 ;
if ( V_121 -> V_6 )
return - V_30 ;
* V_121 = V_1 -> V_71 ;
F_28 ( L_20 , V_1 -> V_71 . V_73 ) ;
return 0 ;
}
static int F_37 ( struct V_98 * V_98 , void * V_99 , const struct V_120 * V_121 )
{
struct V_19 * V_20 = ( (struct V_104 * ) V_99 ) -> V_20 ;
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_23 ;
struct V_122 * V_123 = V_20 -> V_124 ;
if ( V_121 -> V_6 )
return - V_30 ;
if ( V_72 != V_121 -> type )
return - V_30 ;
F_28 ( L_21 , V_1 -> V_71 . V_73 ) ;
F_21 ( V_1 , V_6 , V_75 , V_121 ) ;
V_1 -> V_71 = * V_121 ;
F_21 ( V_1 , V_6 , V_125 , & V_1 -> V_71 ) ;
if ( V_1 -> V_78 == 0 )
F_1 ( V_1 ) ;
if ( V_1 -> V_29 )
return 0 ;
F_38 ( & V_20 -> V_126 ) ;
V_123 -> V_127 = 0 ;
F_39 ( & V_20 -> V_126 ) ;
return 0 ;
}
static int F_40 ( struct V_98 * V_98 , void * V_99 , struct V_128 * V_129 )
{
if ( V_129 -> V_101 >= V_130 )
return - V_30 ;
* V_129 = V_131 [ V_129 -> V_101 ] ;
return 0 ;
}
static int F_41 ( struct V_98 * V_98 , void * V_99 , struct V_128 * V_129 )
{
struct V_19 * V_20 = ( (struct V_104 * ) V_99 ) -> V_20 ;
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_23 ;
F_28 ( L_22 ) ;
* V_129 = V_131 [ V_1 -> V_78 ] ;
return 0 ;
}
static int F_42 ( struct V_98 * V_98 , void * V_99 , const struct V_128 * V_129 )
{
struct V_19 * V_20 = ( (struct V_104 * ) V_99 ) -> V_20 ;
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_23 ;
F_10 ( L_23 , V_129 -> V_101 ) ;
if ( V_103 [ V_1 -> V_29 ] . V_132 & ( 1 << V_129 -> V_101 ) ) {
if ( V_1 -> V_78 != V_129 -> V_101 ) {
V_1 -> V_78 = V_129 -> V_101 ;
F_3 ( V_1 , V_129 -> V_101 ) ;
if ( V_1 -> V_78 == 0 )
F_1 ( V_1 ) ;
}
return 0 ;
}
return - V_30 ;
}
static int F_43 ( struct V_98 * V_98 , void * V_99 , struct V_133 * V_134 )
{
struct V_19 * V_20 = ( (struct V_104 * ) V_99 ) -> V_20 ;
if ( V_134 -> V_134 > F_44 ( V_20 -> V_135 , 0 ) - 4 )
return - V_30 ;
V_134 -> V_27 = F_45 ( V_20 , V_134 -> V_134 ) ;
V_134 -> V_136 = 4 ;
return 0 ;
}
static int F_46 ( struct V_98 * V_98 , void * V_99 , const struct V_133 * V_134 )
{
struct V_19 * V_20 = ( (struct V_104 * ) V_99 ) -> V_20 ;
if ( V_134 -> V_134 > F_44 ( V_20 -> V_135 , 0 ) - 4 )
return - V_30 ;
F_22 ( V_20 , V_134 -> V_134 , V_134 -> V_27 ) ;
return 0 ;
}
static int F_47 ( struct V_19 * V_20 , struct V_137 * V_138 )
{
struct V_1 * V_1 ;
F_28 ( L_24 , V_20 ) ;
F_48 ( V_20 , & V_124 ) ;
if ( F_7 ( V_20 ) ) {
F_49 ( V_20 ) ;
return - 1 ;
}
V_1 = (struct V_1 * ) V_20 -> V_23 ;
V_124 . V_139 . F_27 = F_27 ;
V_124 . V_139 . F_29 = F_29 ;
V_124 . V_139 . F_30 = F_30 ;
V_124 . V_139 . F_35 = F_35 ;
V_124 . V_139 . F_31 = F_31 ;
V_124 . V_139 . F_34 = F_34 ;
V_124 . V_139 . F_36 = F_36 ;
V_124 . V_139 . F_37 = F_37 ;
V_124 . V_139 . F_40 = F_40 ;
V_124 . V_139 . F_41 = F_41 ;
V_124 . V_139 . F_42 = F_42 ;
#ifdef F_50
V_124 . V_139 . F_43 = F_43 ;
V_124 . V_139 . F_46 = F_46 ;
#endif
if ( F_51 ( & V_1 -> V_140 , V_20 , L_25 , V_141 ) ) {
F_52 ( L_26 ) ;
F_49 ( V_20 ) ;
return - 1 ;
}
if ( F_53 ( V_20 ) ) {
if ( F_51 ( & V_1 -> V_142 , V_20 , L_25 , V_143 ) ) {
F_52 ( L_27 ) ;
}
}
F_25 ( L_28 , V_38 ) ;
V_38 ++ ;
F_19 ( V_20 ) ;
return 0 ;
}
static int F_54 ( struct V_19 * V_20 )
{
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_23 ;
F_28 ( L_24 , V_20 ) ;
F_3 ( V_1 , 6 ) ;
F_55 ( & V_1 -> V_140 , V_20 ) ;
if ( F_53 ( V_20 ) )
F_55 ( & V_1 -> V_142 , V_20 ) ;
F_49 ( V_20 ) ;
V_38 -- ;
F_17 ( & V_1 -> V_36 ) ;
F_14 ( V_1 ) ;
return 0 ;
}
static int F_56 ( struct V_19 * V_20 , struct V_144 * V_145 )
{
struct V_1 * V_1 = (struct V_1 * ) V_20 -> V_23 ;
if ( V_146 == V_145 -> V_24 ) {
T_1 V_56 = V_146 ;
F_10 ( L_29 ) ;
F_22 ( V_20 , V_76 , 0x00404050 ) ;
F_20 ( V_1 , V_60 , V_77 , 0 ) ;
F_20 ( V_1 , V_60 , V_61 , V_56 ) ;
if ( V_1 -> V_29 == 0 )
F_21 ( V_1 , V_60 , V_61 , V_56 ) ;
} else {
T_1 V_56 = V_57 ;
if ( V_1 -> V_29 )
V_56 = V_145 -> V_24 ;
F_10 ( L_30 ) ;
F_22 ( V_20 , V_76 , 0x00404050 ) ;
F_20 ( V_1 , V_60 , V_77 , 1 ) ;
F_20 ( V_1 , V_60 , V_61 , V_56 ) ;
if ( V_1 -> V_29 == 0 )
F_21 ( V_1 , V_60 , V_61 , V_56 ) ;
}
return 0 ;
}
static int T_2 F_57 ( void )
{
if ( F_58 ( & V_86 ) ) {
F_13 ( L_31 ) ;
return - V_51 ;
}
return 0 ;
}
static void T_3 F_59 ( void )
{
F_60 ( & V_86 ) ;
}
