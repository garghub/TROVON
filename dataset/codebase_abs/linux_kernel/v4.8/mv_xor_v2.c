static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , int V_6 )
{
int V_7 = ( ( V_6 >> 1 ) * 3 ) ;
if ( ( V_6 & 0x1 ) == 0 ) {
V_4 -> V_8 [ V_7 ] = F_2 ( V_5 ) ;
V_4 -> V_8 [ V_7 + 2 ] &= ~ 0xFFFF ;
V_4 -> V_8 [ V_7 + 2 ] |=
F_3 ( V_5 ) & 0xFFFF ;
} else {
V_4 -> V_8 [ V_7 + 1 ] =
F_2 ( V_5 ) ;
V_4 -> V_8 [ V_7 + 2 ] &= ~ 0xFFFF0000 ;
V_4 -> V_8 [ V_7 + 2 ] |=
( F_3 ( V_5 ) & 0xFFFF ) << 16 ;
}
}
static int F_4 ( struct V_1 * V_2 )
{
T_2 V_9 = F_5 ( V_2 -> V_10 + V_11 ) ;
return ( ( V_9 >> V_12 )
& V_13 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
int V_14 )
{
F_7 ( V_14 , V_2 -> V_10 + V_15 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
int V_14 )
{
F_7 ( V_14 , V_2 -> V_10 + V_16 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
F_7 ( V_17 ,
V_2 -> V_10 + V_18 ) ;
return V_19 ;
}
static inline
void F_10 ( struct V_1 * V_2 , int V_20 )
{
T_2 V_9 ;
V_9 = F_5 ( V_2 -> V_10 + V_21 ) ;
V_9 &= ( ~ V_22 << V_23 ) ;
V_9 |= ( V_20 << V_23 ) ;
F_7 ( V_9 , V_2 -> V_10 + V_21 ) ;
}
static T_3 F_11 ( int V_24 , void * V_25 )
{
struct V_1 * V_2 = V_25 ;
unsigned int V_26 ;
T_2 V_9 ;
V_9 = F_5 ( V_2 -> V_10 + V_27 ) ;
V_26 = ( ( V_9 >> V_28 ) &
V_29 ) ;
if ( ! V_26 )
return V_30 ;
F_10 ( V_2 , V_31 ) ;
F_12 ( & V_2 -> V_32 ) ;
return V_33 ;
}
static T_4
F_13 ( struct V_34 * V_35 )
{
int V_36 ;
void * V_37 ;
T_4 V_38 ;
struct V_39 * V_40 =
F_14 ( V_35 , struct V_39 , V_41 ) ;
struct V_1 * V_2 =
F_14 ( V_35 -> V_42 , struct V_1 , V_43 ) ;
F_15 ( V_2 -> V_44 . V_45 ,
L_1 ,
V_46 , V_40 , & V_40 -> V_41 ) ;
F_16 ( & V_2 -> V_47 ) ;
V_38 = F_17 ( V_35 ) ;
V_36 = F_4 ( V_2 ) ;
V_37 = V_2 -> V_48 + V_36 ;
memcpy ( V_37 , & V_40 -> V_49 , V_2 -> V_50 ) ;
V_2 -> V_51 ++ ;
F_18 ( & V_2 -> V_47 ) ;
return V_38 ;
}
static struct V_39 *
F_19 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
F_16 ( & V_2 -> V_47 ) ;
if ( F_20 ( & V_2 -> V_52 ) ) {
F_18 ( & V_2 -> V_47 ) ;
F_12 ( & V_2 -> V_32 ) ;
return NULL ;
}
V_40 = F_21 ( & V_2 -> V_52 ,
struct V_39 , V_53 ) ;
F_22 ( & V_40 -> V_53 ) ;
F_18 ( & V_2 -> V_47 ) ;
F_23 ( & V_40 -> V_41 , & V_2 -> V_43 ) ;
V_40 -> V_41 . V_54 = F_13 ;
F_24 ( & V_40 -> V_41 ) ;
return V_40 ;
}
static struct V_34 *
F_25 ( struct V_55 * V_42 , T_1 V_56 ,
T_1 V_5 , T_5 V_57 , unsigned long V_58 )
{
struct V_39 * V_40 ;
struct V_3 * V_59 ;
struct V_1 * V_2 ;
V_2 = F_14 ( V_42 , struct V_1 , V_43 ) ;
F_15 ( V_2 -> V_44 . V_45 ,
L_2 ,
V_46 , V_57 , & V_5 , & V_56 , V_58 ) ;
V_40 = F_19 ( V_2 ) ;
V_40 -> V_41 . V_58 = V_58 ;
V_59 = & V_40 -> V_49 ;
V_59 -> V_60 = V_40 -> V_61 ;
V_59 -> V_62 =
V_63 << V_64 ;
if ( V_58 & V_65 )
V_59 -> V_62 |= V_66 ;
V_59 -> V_67 [ 0 ] = F_2 ( V_5 ) ;
V_59 -> V_67 [ 1 ] =
F_3 ( V_5 ) & 0xFFFF ;
V_59 -> V_67 [ 2 ] = F_2 ( V_56 ) ;
V_59 -> V_67 [ 3 ] =
F_3 ( V_56 ) & 0xFFFF ;
V_59 -> V_68 = V_57 ;
return & V_40 -> V_41 ;
}
static struct V_34 *
F_26 ( struct V_55 * V_42 , T_1 V_56 , T_1 * V_5 ,
unsigned int V_69 , T_5 V_57 , unsigned long V_58 )
{
struct V_39 * V_40 ;
struct V_3 * V_59 ;
struct V_1 * V_2 =
F_14 ( V_42 , struct V_1 , V_43 ) ;
int V_70 ;
if ( V_69 > V_71 || V_69 < 1 )
return NULL ;
F_15 ( V_2 -> V_44 . V_45 ,
L_3 ,
V_46 , V_69 , V_57 , & V_56 , V_58 ) ;
V_40 = F_19 ( V_2 ) ;
V_40 -> V_41 . V_58 = V_58 ;
V_59 = & V_40 -> V_49 ;
V_59 -> V_60 = V_40 -> V_61 ;
V_59 -> V_62 =
V_72 << V_64 ;
V_59 -> V_62 |= V_73 ;
if ( V_58 & V_65 )
V_59 -> V_62 |= V_66 ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ )
F_1 ( V_2 , V_59 , V_5 [ V_70 ] , V_70 ) ;
V_59 -> V_62 |=
V_69 << V_74 ;
V_59 -> V_67 [ 2 ] = F_2 ( V_56 ) ;
V_59 -> V_67 [ 3 ] =
F_3 ( V_56 ) & 0xFFFF ;
V_59 -> V_68 = V_57 ;
return & V_40 -> V_41 ;
}
static struct V_34 *
F_27 ( struct V_55 * V_42 , unsigned long V_58 )
{
struct V_39 * V_40 ;
struct V_3 * V_59 ;
struct V_1 * V_2 =
F_14 ( V_42 , struct V_1 , V_43 ) ;
V_40 = F_19 ( V_2 ) ;
V_59 = & V_40 -> V_49 ;
V_59 -> V_60 = V_40 -> V_61 ;
V_59 -> V_62 =
V_75 << V_64 ;
V_59 -> V_62 |= V_66 ;
return & V_40 -> V_41 ;
}
static void F_28 ( struct V_55 * V_42 )
{
struct V_1 * V_2 =
F_14 ( V_42 , struct V_1 , V_43 ) ;
F_16 ( & V_2 -> V_47 ) ;
F_6 ( V_2 , V_2 -> V_51 ) ;
V_2 -> V_51 = 0 ;
F_7 ( 0 , V_2 -> V_10 + V_76 ) ;
F_18 ( & V_2 -> V_47 ) ;
}
static inline
int F_29 ( struct V_1 * V_2 ,
int * V_77 )
{
T_2 V_9 ;
V_9 = F_5 ( V_2 -> V_10 + V_27 ) ;
* V_77 = ( ( V_9 >> V_78 ) &
V_79 ) ;
return ( ( V_9 >> V_28 ) &
V_29 ) ;
}
static void F_30 ( unsigned long V_25 )
{
struct V_1 * V_2 = (struct V_1 * ) V_25 ;
int V_77 , V_80 , V_70 ;
struct V_3 * V_81 = NULL ;
struct V_39 * V_82 = NULL ;
F_15 ( V_2 -> V_44 . V_45 , L_4 , V_46 , __LINE__ ) ;
V_80 = F_29 ( V_2 , & V_77 ) ;
V_81 = V_2 -> V_48 + V_77 ;
for ( V_70 = 0 ; V_70 < V_80 ; V_70 ++ ) {
if ( V_77 > V_31 )
V_77 = 0 ;
if ( V_82 != NULL )
V_81 ++ ;
V_82 =
& V_2 -> V_83 [ V_81 -> V_60 ] ;
if ( V_82 -> V_41 . V_38 > 0 ) {
F_31 ( & V_82 -> V_41 ) ;
if ( V_82 -> V_41 . V_84 )
V_82 -> V_41 . V_84 (
V_82 -> V_41 . V_85 ) ;
F_32 ( & V_82 -> V_41 ) ;
}
F_33 ( & V_82 -> V_41 ) ;
F_16 ( & V_2 -> V_47 ) ;
F_34 ( & V_82 -> V_53 ,
& V_2 -> V_52 ) ;
F_18 ( & V_2 -> V_47 ) ;
V_77 ++ ;
}
if ( V_80 != 0 ) {
F_8 ( V_2 , V_80 ) ;
}
F_10 ( V_2 , 0 ) ;
}
static void F_35 ( struct V_86 * V_4 , struct V_87 * V_88 )
{
struct V_1 * V_2 = F_36 ( V_4 -> V_45 ) ;
F_7 ( V_88 -> V_89 ,
V_2 -> V_10 + V_90 ) ;
F_7 ( V_88 -> V_91 & 0xFFFF ,
V_2 -> V_10 + V_92 ) ;
F_7 ( V_88 -> V_25 ,
V_2 -> V_10 + V_93 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
T_2 V_9 ;
F_7 ( V_31 ,
V_2 -> V_10 + V_94 ) ;
F_7 ( V_2 -> V_95 & 0xFFFFFFFF ,
V_2 -> V_10 + V_96 ) ;
F_7 ( ( V_2 -> V_95 & 0xFFFF00000000 ) >> 32 ,
V_2 -> V_10 + V_97 ) ;
F_7 ( 0 , V_2 -> V_10 + V_76 ) ;
V_9 = F_5 ( V_2 -> V_10 + V_98 ) ;
V_9 &= ~ V_99 ;
V_9 |= V_100 |
V_101 ;
F_7 ( V_9 , V_2 -> V_10 + V_98 ) ;
V_9 = F_5 ( V_2 -> V_10 + V_102 ) ;
V_9 &= ~ V_99 ;
V_9 |= V_100 |
V_101 ;
F_7 ( V_9 , V_2 -> V_10 + V_102 ) ;
V_9 = ( ( V_103 <<
V_104 ) |
( V_105 <<
V_106 ) |
( V_107 <<
V_108 ) |
( V_109 <<
V_110 ) ) ;
F_7 ( V_9 , V_2 -> V_111 + V_112 ) ;
V_9 = F_5 ( V_2 -> V_111 + V_113 ) ;
V_9 |= V_114 ;
F_7 ( V_9 , V_2 -> V_111 + V_113 ) ;
return 0 ;
}
static int F_38 ( struct V_115 * V_116 )
{
struct V_1 * V_2 ;
struct V_117 * V_118 ;
int V_70 , V_119 = 0 ;
struct V_120 * V_121 ;
struct V_39 * V_40 ;
struct V_86 * V_86 ;
F_39 ( sizeof( struct V_3 ) !=
V_19 ) ;
V_2 = F_40 ( & V_116 -> V_45 , sizeof( * V_2 ) , V_122 ) ;
if ( ! V_2 )
return - V_123 ;
V_118 = F_41 ( V_116 , V_124 , 0 ) ;
V_2 -> V_10 = F_42 ( & V_116 -> V_45 , V_118 ) ;
if ( F_43 ( V_2 -> V_10 ) )
return F_44 ( V_2 -> V_10 ) ;
V_118 = F_41 ( V_116 , V_124 , 1 ) ;
V_2 -> V_111 = F_42 ( & V_116 -> V_45 , V_118 ) ;
if ( F_43 ( V_2 -> V_111 ) )
return F_44 ( V_2 -> V_111 ) ;
F_45 ( V_116 , V_2 ) ;
V_2 -> V_125 = F_46 ( & V_116 -> V_45 , NULL ) ;
if ( F_43 ( V_2 -> V_125 ) && F_44 ( V_2 -> V_125 ) == - V_126 )
return - V_126 ;
if ( ! F_43 ( V_2 -> V_125 ) ) {
V_119 = F_47 ( V_2 -> V_125 ) ;
if ( V_119 )
return V_119 ;
}
V_119 = F_48 ( & V_116 -> V_45 , 1 ,
F_35 ) ;
if ( V_119 )
goto V_127;
V_86 = F_49 ( & V_116 -> V_45 ) ;
if ( ! V_86 )
goto V_128;
V_119 = F_50 ( & V_116 -> V_45 , V_86 -> V_24 ,
F_11 , 0 ,
F_51 ( & V_116 -> V_45 ) , V_2 ) ;
if ( V_119 )
goto V_128;
F_52 ( & V_2 -> V_32 , F_30 ,
( unsigned long ) V_2 ) ;
V_2 -> V_50 = F_9 ( V_2 ) ;
F_53 ( & V_2 -> V_43 ) ;
V_2 -> V_48 =
F_54 ( & V_116 -> V_45 ,
V_2 -> V_50 * V_31 ,
& V_2 -> V_95 , V_122 ) ;
if ( ! V_2 -> V_48 ) {
V_119 = - V_123 ;
goto V_128;
}
V_2 -> V_83 = F_40 ( & V_116 -> V_45 , sizeof( * V_40 ) *
V_31 , V_122 ) ;
if ( ! V_2 -> V_83 ) {
V_119 = - V_123 ;
goto V_129;
}
F_55 ( & V_2 -> V_47 ) ;
F_56 ( & V_2 -> V_52 ) ;
for ( V_70 = 0 ; V_70 < V_31 ; V_70 ++ ) {
V_2 -> V_83 [ V_70 ] . V_61 = V_70 ;
F_34 ( & V_2 -> V_83 [ V_70 ] . V_53 ,
& V_2 -> V_52 ) ;
}
V_121 = & V_2 -> V_44 ;
F_57 ( V_121 -> V_130 ) ;
F_58 ( V_131 , V_121 -> V_130 ) ;
F_58 ( V_132 , V_121 -> V_130 ) ;
F_58 ( V_133 , V_121 -> V_130 ) ;
F_56 ( & V_121 -> V_134 ) ;
V_121 -> V_135 = V_136 ;
V_121 -> V_137 = F_28 ;
V_121 -> V_45 = & V_116 -> V_45 ;
V_121 -> V_138 = F_25 ;
V_121 -> V_139 = F_27 ;
V_121 -> V_140 = 8 ;
V_121 -> V_141 = F_26 ;
V_2 -> V_43 . V_142 = V_121 ;
F_59 ( & V_2 -> V_43 . V_143 ,
& V_121 -> V_134 ) ;
F_37 ( V_2 ) ;
V_119 = F_60 ( V_121 ) ;
if ( V_119 )
goto V_129;
F_61 ( & V_116 -> V_45 , L_5 ) ;
return 0 ;
V_129:
F_62 ( & V_116 -> V_45 ,
V_2 -> V_50 * V_31 ,
V_2 -> V_48 , V_2 -> V_95 ) ;
V_128:
F_63 ( & V_116 -> V_45 ) ;
V_127:
if ( ! F_43 ( V_2 -> V_125 ) )
F_64 ( V_2 -> V_125 ) ;
return V_119 ;
}
static int F_65 ( struct V_115 * V_116 )
{
struct V_1 * V_2 = F_66 ( V_116 ) ;
F_67 ( & V_2 -> V_44 ) ;
F_62 ( & V_116 -> V_45 ,
V_2 -> V_50 * V_31 ,
V_2 -> V_48 , V_2 -> V_95 ) ;
F_63 ( & V_116 -> V_45 ) ;
F_64 ( V_2 -> V_125 ) ;
return 0 ;
}
