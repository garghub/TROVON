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
static void F_4 ( struct V_1 * V_2 ,
int V_9 )
{
F_5 ( V_9 , V_2 -> V_10 + V_11 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
int V_9 )
{
F_5 ( V_9 , V_2 -> V_10 + V_12 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_5 ( V_13 ,
V_2 -> V_10 + V_14 ) ;
return V_15 ;
}
static inline
void F_8 ( struct V_1 * V_2 )
{
T_2 V_16 ;
V_16 = F_9 ( V_2 -> V_10 + V_17 ) ;
V_16 &= ( ~ V_18 << V_19 ) ;
V_16 |= ( V_20 << V_19 ) ;
V_16 |= V_21 ;
F_5 ( V_16 , V_2 -> V_10 + V_17 ) ;
V_16 = F_9 ( V_2 -> V_10 + V_22 ) ;
V_16 &= ( ~ V_23 <<
V_24 ) ;
V_16 |= ( V_25 << V_24 ) ;
F_5 ( V_16 , V_2 -> V_10 + V_22 ) ;
}
static T_3 F_10 ( int V_26 , void * V_27 )
{
struct V_1 * V_2 = V_27 ;
unsigned int V_28 ;
T_2 V_16 ;
V_16 = F_9 ( V_2 -> V_10 + V_29 ) ;
V_28 = ( ( V_16 >> V_30 ) &
V_31 ) ;
if ( ! V_28 )
return V_32 ;
F_11 ( & V_2 -> V_33 ) ;
return V_34 ;
}
static T_4
F_12 ( struct V_35 * V_36 )
{
void * V_37 ;
T_4 V_38 ;
struct V_39 * V_40 =
F_13 ( V_36 , struct V_39 , V_41 ) ;
struct V_1 * V_2 =
F_13 ( V_36 -> V_42 , struct V_1 , V_43 ) ;
F_14 ( V_2 -> V_44 . V_45 ,
L_1 ,
V_46 , V_40 , & V_40 -> V_41 ) ;
F_15 ( & V_2 -> V_47 ) ;
V_38 = F_16 ( V_36 ) ;
V_37 = V_2 -> V_48 + V_2 -> V_49 ;
memcpy ( V_37 , & V_40 -> V_50 , V_2 -> V_51 ) ;
V_2 -> V_52 ++ ;
V_2 -> V_49 ++ ;
if ( V_2 -> V_49 >= V_53 )
V_2 -> V_49 = 0 ;
F_17 ( & V_2 -> V_47 ) ;
return V_38 ;
}
static struct V_39 *
F_18 ( struct V_1 * V_2 )
{
struct V_39 * V_40 ;
bool V_54 = false ;
F_15 ( & V_2 -> V_47 ) ;
if ( F_19 ( & V_2 -> V_55 ) ) {
F_17 ( & V_2 -> V_47 ) ;
F_11 ( & V_2 -> V_33 ) ;
return NULL ;
}
F_20 (sw_desc, &xor_dev->free_sw_desc, free_list) {
if ( F_21 ( & V_40 -> V_41 ) ) {
V_54 = true ;
break;
}
}
if ( ! V_54 ) {
F_17 ( & V_2 -> V_47 ) ;
return NULL ;
}
F_22 ( & V_40 -> V_56 ) ;
F_17 ( & V_2 -> V_47 ) ;
return V_40 ;
}
static struct V_35 *
F_23 ( struct V_57 * V_42 , T_1 V_58 ,
T_1 V_5 , T_5 V_59 , unsigned long V_60 )
{
struct V_39 * V_40 ;
struct V_3 * V_61 ;
struct V_1 * V_2 ;
V_2 = F_13 ( V_42 , struct V_1 , V_43 ) ;
F_14 ( V_2 -> V_44 . V_45 ,
L_2 ,
V_46 , V_59 , & V_5 , & V_58 , V_60 ) ;
V_40 = F_18 ( V_2 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_41 . V_60 = V_60 ;
V_61 = & V_40 -> V_50 ;
V_61 -> V_62 = V_40 -> V_63 ;
V_61 -> V_64 =
V_65 << V_66 ;
if ( V_60 & V_67 )
V_61 -> V_64 |= V_68 ;
V_61 -> V_69 [ 0 ] = F_2 ( V_5 ) ;
V_61 -> V_69 [ 1 ] =
F_3 ( V_5 ) & 0xFFFF ;
V_61 -> V_69 [ 2 ] = F_2 ( V_58 ) ;
V_61 -> V_69 [ 3 ] =
F_3 ( V_58 ) & 0xFFFF ;
V_61 -> V_70 = V_59 ;
return & V_40 -> V_41 ;
}
static struct V_35 *
F_24 ( struct V_57 * V_42 , T_1 V_58 , T_1 * V_5 ,
unsigned int V_71 , T_5 V_59 , unsigned long V_60 )
{
struct V_39 * V_40 ;
struct V_3 * V_61 ;
struct V_1 * V_2 =
F_13 ( V_42 , struct V_1 , V_43 ) ;
int V_72 ;
if ( V_71 > V_73 || V_71 < 1 )
return NULL ;
F_14 ( V_2 -> V_44 . V_45 ,
L_3 ,
V_46 , V_71 , V_59 , & V_58 , V_60 ) ;
V_40 = F_18 ( V_2 ) ;
if ( ! V_40 )
return NULL ;
V_40 -> V_41 . V_60 = V_60 ;
V_61 = & V_40 -> V_50 ;
V_61 -> V_62 = V_40 -> V_63 ;
V_61 -> V_64 =
V_74 << V_66 ;
V_61 -> V_64 |= V_75 ;
if ( V_60 & V_67 )
V_61 -> V_64 |= V_68 ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ )
F_1 ( V_2 , V_61 , V_5 [ V_72 ] , V_72 ) ;
V_61 -> V_64 |=
V_71 << V_76 ;
V_61 -> V_69 [ 2 ] = F_2 ( V_58 ) ;
V_61 -> V_69 [ 3 ] =
F_3 ( V_58 ) & 0xFFFF ;
V_61 -> V_70 = V_59 ;
return & V_40 -> V_41 ;
}
static struct V_35 *
F_25 ( struct V_57 * V_42 , unsigned long V_60 )
{
struct V_39 * V_40 ;
struct V_3 * V_61 ;
struct V_1 * V_2 =
F_13 ( V_42 , struct V_1 , V_43 ) ;
V_40 = F_18 ( V_2 ) ;
if ( ! V_40 )
return NULL ;
V_61 = & V_40 -> V_50 ;
V_61 -> V_62 = V_40 -> V_63 ;
V_61 -> V_64 =
V_77 << V_66 ;
V_61 -> V_64 |= V_68 ;
return & V_40 -> V_41 ;
}
static void F_26 ( struct V_57 * V_42 )
{
struct V_1 * V_2 =
F_13 ( V_42 , struct V_1 , V_43 ) ;
F_15 ( & V_2 -> V_47 ) ;
F_4 ( V_2 , V_2 -> V_52 ) ;
V_2 -> V_52 = 0 ;
F_17 ( & V_2 -> V_47 ) ;
}
static inline
int F_27 ( struct V_1 * V_2 ,
int * V_78 )
{
T_2 V_16 ;
V_16 = F_9 ( V_2 -> V_10 + V_29 ) ;
* V_78 = ( ( V_16 >> V_79 ) &
V_80 ) ;
return ( ( V_16 >> V_30 ) &
V_31 ) ;
}
static void F_28 ( unsigned long V_27 )
{
struct V_1 * V_2 = (struct V_1 * ) V_27 ;
int V_78 , V_81 , V_72 ;
struct V_39 * V_82 = NULL ;
F_14 ( V_2 -> V_44 . V_45 , L_4 , V_46 , __LINE__ ) ;
V_81 = F_27 ( V_2 , & V_78 ) ;
for ( V_72 = 0 ; V_72 < V_81 ; V_72 ++ ) {
struct V_3 * V_83 =
V_2 -> V_48 + V_78 ;
V_82 =
& V_2 -> V_84 [ V_83 -> V_62 ] ;
if ( V_82 -> V_41 . V_38 > 0 ) {
F_29 ( & V_82 -> V_41 ) ;
if ( V_82 -> V_41 . V_85 )
V_82 -> V_41 . V_85 (
V_82 -> V_41 . V_86 ) ;
F_30 ( & V_82 -> V_41 ) ;
}
F_31 ( & V_82 -> V_41 ) ;
F_15 ( & V_2 -> V_47 ) ;
F_32 ( & V_82 -> V_56 ,
& V_2 -> V_55 ) ;
F_17 ( & V_2 -> V_47 ) ;
V_78 ++ ;
if ( V_78 >= V_53 )
V_78 = 0 ;
}
if ( V_81 != 0 ) {
F_6 ( V_2 , V_81 ) ;
}
}
static void F_33 ( struct V_87 * V_4 , struct V_88 * V_89 )
{
struct V_1 * V_2 = F_34 ( V_4 -> V_45 ) ;
F_5 ( V_89 -> V_90 ,
V_2 -> V_10 + V_91 ) ;
F_5 ( V_89 -> V_92 & 0xFFFF ,
V_2 -> V_10 + V_93 ) ;
F_5 ( V_89 -> V_27 ,
V_2 -> V_10 + V_94 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
T_2 V_16 ;
F_5 ( V_53 ,
V_2 -> V_10 + V_95 ) ;
F_5 ( V_2 -> V_96 & 0xFFFFFFFF ,
V_2 -> V_10 + V_97 ) ;
F_5 ( ( V_2 -> V_96 & 0xFFFF00000000 ) >> 32 ,
V_2 -> V_10 + V_98 ) ;
V_16 = F_9 ( V_2 -> V_10 + V_99 ) ;
V_16 &= ~ V_100 ;
V_16 |= V_101 |
V_102 ;
F_5 ( V_16 , V_2 -> V_10 + V_99 ) ;
V_16 = F_9 ( V_2 -> V_10 + V_103 ) ;
V_16 &= ~ V_100 ;
V_16 |= V_101 |
V_102 ;
F_5 ( V_16 , V_2 -> V_10 + V_103 ) ;
V_16 = ( ( V_104 <<
V_105 ) |
( V_106 <<
V_107 ) |
( V_108 <<
V_109 ) |
( V_110 <<
V_111 ) ) ;
F_5 ( V_16 , V_2 -> V_112 + V_113 ) ;
V_16 = F_9 ( V_2 -> V_112 + V_114 ) ;
V_16 |= V_115 ;
F_5 ( V_16 , V_2 -> V_112 + V_114 ) ;
F_5 ( 0 , V_2 -> V_10 + V_116 ) ;
return 0 ;
}
static int F_36 ( struct V_117 * V_45 , T_6 V_118 )
{
struct V_1 * V_2 = F_37 ( V_45 ) ;
F_5 ( 0x1 , V_2 -> V_10 + V_116 ) ;
return 0 ;
}
static int F_38 ( struct V_117 * V_45 )
{
struct V_1 * V_2 = F_37 ( V_45 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_117 * V_119 )
{
struct V_1 * V_2 ;
struct V_120 * V_121 ;
int V_72 , V_122 = 0 ;
struct V_123 * V_124 ;
struct V_39 * V_40 ;
struct V_87 * V_87 ;
F_40 ( sizeof( struct V_3 ) !=
V_15 ) ;
V_2 = F_41 ( & V_119 -> V_45 , sizeof( * V_2 ) , V_125 ) ;
if ( ! V_2 )
return - V_126 ;
V_121 = F_42 ( V_119 , V_127 , 0 ) ;
V_2 -> V_10 = F_43 ( & V_119 -> V_45 , V_121 ) ;
if ( F_44 ( V_2 -> V_10 ) )
return F_45 ( V_2 -> V_10 ) ;
V_121 = F_42 ( V_119 , V_127 , 1 ) ;
V_2 -> V_112 = F_43 ( & V_119 -> V_45 , V_121 ) ;
if ( F_44 ( V_2 -> V_112 ) )
return F_45 ( V_2 -> V_112 ) ;
F_46 ( V_119 , V_2 ) ;
V_122 = F_47 ( & V_119 -> V_45 , F_48 ( 40 ) ) ;
if ( V_122 )
return V_122 ;
V_2 -> V_128 = F_49 ( & V_119 -> V_45 , NULL ) ;
if ( F_44 ( V_2 -> V_128 ) && F_45 ( V_2 -> V_128 ) == - V_129 )
return - V_129 ;
if ( ! F_44 ( V_2 -> V_128 ) ) {
V_122 = F_50 ( V_2 -> V_128 ) ;
if ( V_122 )
return V_122 ;
}
V_122 = F_51 ( & V_119 -> V_45 , 1 ,
F_33 ) ;
if ( V_122 )
goto V_130;
V_87 = F_52 ( & V_119 -> V_45 ) ;
if ( ! V_87 )
goto V_131;
V_122 = F_53 ( & V_119 -> V_45 , V_87 -> V_26 ,
F_10 , 0 ,
F_54 ( & V_119 -> V_45 ) , V_2 ) ;
if ( V_122 )
goto V_131;
F_55 ( & V_2 -> V_33 , F_28 ,
( unsigned long ) V_2 ) ;
V_2 -> V_51 = F_7 ( V_2 ) ;
F_56 ( & V_2 -> V_43 ) ;
V_2 -> V_48 =
F_57 ( & V_119 -> V_45 ,
V_2 -> V_51 * V_53 ,
& V_2 -> V_96 , V_125 ) ;
if ( ! V_2 -> V_48 ) {
V_122 = - V_126 ;
goto V_131;
}
V_2 -> V_84 = F_41 ( & V_119 -> V_45 , sizeof( * V_40 ) *
V_53 , V_125 ) ;
if ( ! V_2 -> V_84 ) {
V_122 = - V_126 ;
goto V_132;
}
F_58 ( & V_2 -> V_47 ) ;
F_59 ( & V_2 -> V_55 ) ;
for ( V_72 = 0 ; V_72 < V_53 ; V_72 ++ ) {
struct V_39 * V_40 =
V_2 -> V_84 + V_72 ;
V_40 -> V_63 = V_72 ;
F_60 ( & V_40 -> V_41 ,
& V_2 -> V_43 ) ;
V_40 -> V_41 . V_133 = F_12 ;
F_61 ( & V_40 -> V_41 ) ;
F_32 ( & V_40 -> V_56 ,
& V_2 -> V_55 ) ;
}
V_124 = & V_2 -> V_44 ;
F_62 ( V_124 -> V_134 ) ;
F_63 ( V_135 , V_124 -> V_134 ) ;
F_63 ( V_136 , V_124 -> V_134 ) ;
F_63 ( V_137 , V_124 -> V_134 ) ;
F_59 ( & V_124 -> V_138 ) ;
V_124 -> V_139 = V_140 ;
V_124 -> V_141 = F_26 ;
V_124 -> V_45 = & V_119 -> V_45 ;
V_124 -> V_142 = F_23 ;
V_124 -> V_143 = F_25 ;
V_124 -> V_144 = 8 ;
V_124 -> V_145 = F_24 ;
V_2 -> V_43 . V_146 = V_124 ;
F_64 ( & V_2 -> V_43 . V_147 ,
& V_124 -> V_138 ) ;
F_8 ( V_2 ) ;
F_35 ( V_2 ) ;
V_122 = F_65 ( V_124 ) ;
if ( V_122 )
goto V_132;
F_66 ( & V_119 -> V_45 , L_5 ) ;
return 0 ;
V_132:
F_67 ( & V_119 -> V_45 ,
V_2 -> V_51 * V_53 ,
V_2 -> V_48 , V_2 -> V_96 ) ;
V_131:
F_68 ( & V_119 -> V_45 ) ;
V_130:
if ( ! F_44 ( V_2 -> V_128 ) )
F_69 ( V_2 -> V_128 ) ;
return V_122 ;
}
static int F_70 ( struct V_117 * V_119 )
{
struct V_1 * V_2 = F_37 ( V_119 ) ;
F_71 ( & V_2 -> V_44 ) ;
F_67 ( & V_119 -> V_45 ,
V_2 -> V_51 * V_53 ,
V_2 -> V_48 , V_2 -> V_96 ) ;
F_68 ( & V_119 -> V_45 ) ;
F_69 ( V_2 -> V_128 ) ;
return 0 ;
}
