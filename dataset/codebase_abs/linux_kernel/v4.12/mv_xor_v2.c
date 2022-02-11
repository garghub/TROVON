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
static T_2 F_8 ( int V_16 , void * V_17 )
{
struct V_1 * V_2 = V_17 ;
unsigned int V_18 ;
T_3 V_19 ;
V_19 = F_9 ( V_2 -> V_10 + V_20 ) ;
V_18 = ( ( V_19 >> V_21 ) &
V_22 ) ;
if ( ! V_18 )
return V_23 ;
F_10 ( & V_2 -> V_24 ) ;
return V_25 ;
}
static T_4
F_11 ( struct V_26 * V_27 )
{
void * V_28 ;
T_4 V_29 ;
struct V_30 * V_31 =
F_12 ( V_27 , struct V_30 , V_32 ) ;
struct V_1 * V_2 =
F_12 ( V_27 -> V_33 , struct V_1 , V_34 ) ;
F_13 ( V_2 -> V_35 . V_36 ,
L_1 ,
V_37 , V_31 , & V_31 -> V_32 ) ;
F_14 ( & V_2 -> V_38 ) ;
V_29 = F_15 ( V_27 ) ;
V_28 = V_2 -> V_39 + V_2 -> V_40 ;
memcpy ( V_28 , & V_31 -> V_41 , V_2 -> V_42 ) ;
V_2 -> V_43 ++ ;
V_2 -> V_40 ++ ;
if ( V_2 -> V_40 >= V_44 )
V_2 -> V_40 = 0 ;
F_16 ( & V_2 -> V_38 ) ;
return V_29 ;
}
static struct V_30 *
F_17 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
bool V_45 = false ;
F_14 ( & V_2 -> V_38 ) ;
if ( F_18 ( & V_2 -> V_46 ) ) {
F_16 ( & V_2 -> V_38 ) ;
F_10 ( & V_2 -> V_24 ) ;
return NULL ;
}
F_19 (sw_desc, &xor_dev->free_sw_desc, free_list) {
if ( F_20 ( & V_31 -> V_32 ) ) {
V_45 = true ;
break;
}
}
if ( ! V_45 ) {
F_16 ( & V_2 -> V_38 ) ;
return NULL ;
}
F_21 ( & V_31 -> V_47 ) ;
F_16 ( & V_2 -> V_38 ) ;
return V_31 ;
}
static struct V_26 *
F_22 ( struct V_48 * V_33 , T_1 V_49 ,
T_1 V_5 , T_5 V_50 , unsigned long V_51 )
{
struct V_30 * V_31 ;
struct V_3 * V_52 ;
struct V_1 * V_2 ;
V_2 = F_12 ( V_33 , struct V_1 , V_34 ) ;
F_13 ( V_2 -> V_35 . V_36 ,
L_2 ,
V_37 , V_50 , & V_5 , & V_49 , V_51 ) ;
V_31 = F_17 ( V_2 ) ;
if ( ! V_31 )
return NULL ;
V_31 -> V_32 . V_51 = V_51 ;
V_52 = & V_31 -> V_41 ;
V_52 -> V_53 = V_31 -> V_54 ;
V_52 -> V_55 =
V_56 << V_57 ;
if ( V_51 & V_58 )
V_52 -> V_55 |= V_59 ;
V_52 -> V_60 [ 0 ] = F_2 ( V_5 ) ;
V_52 -> V_60 [ 1 ] =
F_3 ( V_5 ) & 0xFFFF ;
V_52 -> V_60 [ 2 ] = F_2 ( V_49 ) ;
V_52 -> V_60 [ 3 ] =
F_3 ( V_49 ) & 0xFFFF ;
V_52 -> V_61 = V_50 ;
return & V_31 -> V_32 ;
}
static struct V_26 *
F_23 ( struct V_48 * V_33 , T_1 V_49 , T_1 * V_5 ,
unsigned int V_62 , T_5 V_50 , unsigned long V_51 )
{
struct V_30 * V_31 ;
struct V_3 * V_52 ;
struct V_1 * V_2 =
F_12 ( V_33 , struct V_1 , V_34 ) ;
int V_63 ;
if ( V_62 > V_64 || V_62 < 1 )
return NULL ;
F_13 ( V_2 -> V_35 . V_36 ,
L_3 ,
V_37 , V_62 , V_50 , & V_49 , V_51 ) ;
V_31 = F_17 ( V_2 ) ;
if ( ! V_31 )
return NULL ;
V_31 -> V_32 . V_51 = V_51 ;
V_52 = & V_31 -> V_41 ;
V_52 -> V_53 = V_31 -> V_54 ;
V_52 -> V_55 =
V_65 << V_57 ;
V_52 -> V_55 |= V_66 ;
if ( V_51 & V_58 )
V_52 -> V_55 |= V_59 ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ )
F_1 ( V_2 , V_52 , V_5 [ V_63 ] , V_63 ) ;
V_52 -> V_55 |=
V_62 << V_67 ;
V_52 -> V_60 [ 2 ] = F_2 ( V_49 ) ;
V_52 -> V_60 [ 3 ] =
F_3 ( V_49 ) & 0xFFFF ;
V_52 -> V_61 = V_50 ;
return & V_31 -> V_32 ;
}
static struct V_26 *
F_24 ( struct V_48 * V_33 , unsigned long V_51 )
{
struct V_30 * V_31 ;
struct V_3 * V_52 ;
struct V_1 * V_2 =
F_12 ( V_33 , struct V_1 , V_34 ) ;
V_31 = F_17 ( V_2 ) ;
if ( ! V_31 )
return NULL ;
V_52 = & V_31 -> V_41 ;
V_52 -> V_53 = V_31 -> V_54 ;
V_52 -> V_55 =
V_68 << V_57 ;
V_52 -> V_55 |= V_59 ;
return & V_31 -> V_32 ;
}
static void F_25 ( struct V_48 * V_33 )
{
struct V_1 * V_2 =
F_12 ( V_33 , struct V_1 , V_34 ) ;
F_14 ( & V_2 -> V_38 ) ;
F_4 ( V_2 , V_2 -> V_43 ) ;
V_2 -> V_43 = 0 ;
F_5 ( 0 , V_2 -> V_10 + V_69 ) ;
F_16 ( & V_2 -> V_38 ) ;
}
static inline
int F_26 ( struct V_1 * V_2 ,
int * V_70 )
{
T_3 V_19 ;
V_19 = F_9 ( V_2 -> V_10 + V_20 ) ;
* V_70 = ( ( V_19 >> V_71 ) &
V_72 ) ;
return ( ( V_19 >> V_21 ) &
V_22 ) ;
}
static void F_27 ( unsigned long V_17 )
{
struct V_1 * V_2 = (struct V_1 * ) V_17 ;
int V_70 , V_73 , V_63 ;
struct V_30 * V_74 = NULL ;
F_13 ( V_2 -> V_35 . V_36 , L_4 , V_37 , __LINE__ ) ;
V_73 = F_26 ( V_2 , & V_70 ) ;
for ( V_63 = 0 ; V_63 < V_73 ; V_63 ++ ) {
struct V_3 * V_75 =
V_2 -> V_39 + V_70 ;
V_74 =
& V_2 -> V_76 [ V_75 -> V_53 ] ;
if ( V_74 -> V_32 . V_29 > 0 ) {
F_28 ( & V_74 -> V_32 ) ;
if ( V_74 -> V_32 . V_77 )
V_74 -> V_32 . V_77 (
V_74 -> V_32 . V_78 ) ;
F_29 ( & V_74 -> V_32 ) ;
}
F_30 ( & V_74 -> V_32 ) ;
F_14 ( & V_2 -> V_38 ) ;
F_31 ( & V_74 -> V_47 ,
& V_2 -> V_46 ) ;
F_16 ( & V_2 -> V_38 ) ;
V_70 ++ ;
if ( V_70 >= V_44 )
V_70 = 0 ;
}
if ( V_73 != 0 ) {
F_6 ( V_2 , V_73 ) ;
}
}
static void F_32 ( struct V_79 * V_4 , struct V_80 * V_81 )
{
struct V_1 * V_2 = F_33 ( V_4 -> V_36 ) ;
F_5 ( V_81 -> V_82 ,
V_2 -> V_10 + V_83 ) ;
F_5 ( V_81 -> V_84 & 0xFFFF ,
V_2 -> V_10 + V_85 ) ;
F_5 ( V_81 -> V_17 ,
V_2 -> V_10 + V_86 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
T_3 V_19 ;
F_5 ( V_44 ,
V_2 -> V_10 + V_87 ) ;
F_5 ( V_2 -> V_88 & 0xFFFFFFFF ,
V_2 -> V_10 + V_89 ) ;
F_5 ( ( V_2 -> V_88 & 0xFFFF00000000 ) >> 32 ,
V_2 -> V_10 + V_90 ) ;
V_19 = F_9 ( V_2 -> V_10 + V_91 ) ;
V_19 &= ~ V_92 ;
V_19 |= V_93 |
V_94 ;
F_5 ( V_19 , V_2 -> V_10 + V_91 ) ;
V_19 = F_9 ( V_2 -> V_10 + V_95 ) ;
V_19 &= ~ V_92 ;
V_19 |= V_93 |
V_94 ;
F_5 ( V_19 , V_2 -> V_10 + V_95 ) ;
V_19 = ( ( V_96 <<
V_97 ) |
( V_98 <<
V_99 ) |
( V_100 <<
V_101 ) |
( V_102 <<
V_103 ) ) ;
F_5 ( V_19 , V_2 -> V_104 + V_105 ) ;
V_19 = F_9 ( V_2 -> V_104 + V_106 ) ;
V_19 |= V_107 ;
F_5 ( V_19 , V_2 -> V_104 + V_106 ) ;
F_5 ( 0 , V_2 -> V_10 + V_69 ) ;
return 0 ;
}
static int F_35 ( struct V_108 * V_109 )
{
struct V_1 * V_2 ;
struct V_110 * V_111 ;
int V_63 , V_112 = 0 ;
struct V_113 * V_114 ;
struct V_30 * V_31 ;
struct V_79 * V_79 ;
F_36 ( sizeof( struct V_3 ) !=
V_15 ) ;
V_2 = F_37 ( & V_109 -> V_36 , sizeof( * V_2 ) , V_115 ) ;
if ( ! V_2 )
return - V_116 ;
V_111 = F_38 ( V_109 , V_117 , 0 ) ;
V_2 -> V_10 = F_39 ( & V_109 -> V_36 , V_111 ) ;
if ( F_40 ( V_2 -> V_10 ) )
return F_41 ( V_2 -> V_10 ) ;
V_111 = F_38 ( V_109 , V_117 , 1 ) ;
V_2 -> V_104 = F_39 ( & V_109 -> V_36 , V_111 ) ;
if ( F_40 ( V_2 -> V_104 ) )
return F_41 ( V_2 -> V_104 ) ;
F_42 ( V_109 , V_2 ) ;
V_112 = F_43 ( & V_109 -> V_36 , F_44 ( 40 ) ) ;
if ( V_112 )
return V_112 ;
V_2 -> V_118 = F_45 ( & V_109 -> V_36 , NULL ) ;
if ( F_40 ( V_2 -> V_118 ) && F_41 ( V_2 -> V_118 ) == - V_119 )
return - V_119 ;
if ( ! F_40 ( V_2 -> V_118 ) ) {
V_112 = F_46 ( V_2 -> V_118 ) ;
if ( V_112 )
return V_112 ;
}
V_112 = F_47 ( & V_109 -> V_36 , 1 ,
F_32 ) ;
if ( V_112 )
goto V_120;
V_79 = F_48 ( & V_109 -> V_36 ) ;
if ( ! V_79 )
goto V_121;
V_112 = F_49 ( & V_109 -> V_36 , V_79 -> V_16 ,
F_8 , 0 ,
F_50 ( & V_109 -> V_36 ) , V_2 ) ;
if ( V_112 )
goto V_121;
F_51 ( & V_2 -> V_24 , F_27 ,
( unsigned long ) V_2 ) ;
V_2 -> V_42 = F_7 ( V_2 ) ;
F_52 ( & V_2 -> V_34 ) ;
V_2 -> V_39 =
F_53 ( & V_109 -> V_36 ,
V_2 -> V_42 * V_44 ,
& V_2 -> V_88 , V_115 ) ;
if ( ! V_2 -> V_39 ) {
V_112 = - V_116 ;
goto V_121;
}
V_2 -> V_76 = F_37 ( & V_109 -> V_36 , sizeof( * V_31 ) *
V_44 , V_115 ) ;
if ( ! V_2 -> V_76 ) {
V_112 = - V_116 ;
goto V_122;
}
F_54 ( & V_2 -> V_38 ) ;
F_55 ( & V_2 -> V_46 ) ;
for ( V_63 = 0 ; V_63 < V_44 ; V_63 ++ ) {
struct V_30 * V_31 =
V_2 -> V_76 + V_63 ;
V_31 -> V_54 = V_63 ;
F_56 ( & V_31 -> V_32 ,
& V_2 -> V_34 ) ;
V_31 -> V_32 . V_123 = F_11 ;
F_57 ( & V_31 -> V_32 ) ;
F_31 ( & V_31 -> V_47 ,
& V_2 -> V_46 ) ;
}
V_114 = & V_2 -> V_35 ;
F_58 ( V_114 -> V_124 ) ;
F_59 ( V_125 , V_114 -> V_124 ) ;
F_59 ( V_126 , V_114 -> V_124 ) ;
F_59 ( V_127 , V_114 -> V_124 ) ;
F_55 ( & V_114 -> V_128 ) ;
V_114 -> V_129 = V_130 ;
V_114 -> V_131 = F_25 ;
V_114 -> V_36 = & V_109 -> V_36 ;
V_114 -> V_132 = F_22 ;
V_114 -> V_133 = F_24 ;
V_114 -> V_134 = 8 ;
V_114 -> V_135 = F_23 ;
V_2 -> V_34 . V_136 = V_114 ;
F_60 ( & V_2 -> V_34 . V_137 ,
& V_114 -> V_128 ) ;
F_34 ( V_2 ) ;
V_112 = F_61 ( V_114 ) ;
if ( V_112 )
goto V_122;
F_62 ( & V_109 -> V_36 , L_5 ) ;
return 0 ;
V_122:
F_63 ( & V_109 -> V_36 ,
V_2 -> V_42 * V_44 ,
V_2 -> V_39 , V_2 -> V_88 ) ;
V_121:
F_64 ( & V_109 -> V_36 ) ;
V_120:
if ( ! F_40 ( V_2 -> V_118 ) )
F_65 ( V_2 -> V_118 ) ;
return V_112 ;
}
static int F_66 ( struct V_108 * V_109 )
{
struct V_1 * V_2 = F_67 ( V_109 ) ;
F_68 ( & V_2 -> V_35 ) ;
F_63 ( & V_109 -> V_36 ,
V_2 -> V_42 * V_44 ,
V_2 -> V_39 , V_2 -> V_88 ) ;
F_64 ( & V_109 -> V_36 ) ;
F_65 ( V_2 -> V_118 ) ;
return 0 ;
}
