static struct V_1 * F_1 ( T_1 V_2 , T_2 type )
{
struct V_1 * V_3 ;
V_3 = F_2 ( sizeof( struct V_1 ) + V_2 , V_4 ) ;
if ( ! V_3 )
return NULL ;
V_3 -> type = type ;
return V_3 ;
}
static int F_3 ( struct V_5 * V_6 ,
struct V_1 * V_3 , T_1 V_2 )
{
int V_7 ;
V_2 += sizeof( struct V_1 ) ;
V_7 = F_4 ( V_6 , ( T_2 * ) V_3 , V_2 ) ;
if ( V_7 != V_2 ) {
F_5 ( & V_6 -> V_8 , L_1 ) ;
return V_7 ;
}
return 0 ;
}
static inline int F_6 ( struct V_5 * V_6 , T_2 V_9 )
{
struct V_1 * V_3 ;
int V_7 ;
V_3 = F_1 ( 1 , V_10 ) ;
if ( ! V_3 )
return - V_11 ;
V_3 -> V_12 [ 0 ] = V_9 ;
V_7 = F_3 ( V_6 , V_3 , 1 ) ;
F_7 ( V_3 ) ;
return V_7 ;
}
static void F_8 ( struct V_13 * V_14 )
{
struct V_1 * V_3 ;
T_2 * V_15 = V_14 -> V_16 -> V_17 ;
int V_18 , V_19 , V_20 ;
V_3 = F_1 ( V_14 -> V_21 * V_14 -> V_22 / 8 ,
V_23 ) ;
if ( ! V_3 )
return;
for ( V_18 = 0 ; V_18 < ( V_14 -> V_22 / 8 ) ; V_18 ++ ) {
for ( V_19 = 0 ; V_19 < V_14 -> V_21 ; V_19 ++ ) {
T_1 V_24 = V_18 * V_14 -> V_21 + V_19 ;
V_3 -> V_12 [ V_24 ] = 0 ;
for ( V_20 = 0 ; V_20 < 8 ; V_20 ++ ) {
T_1 V_25 = V_14 -> V_21 * V_18 ;
T_1 V_26 = V_25 + ( V_14 -> V_21 * V_20 + V_19 ) / 8 ;
T_2 V_27 = * ( V_15 + V_26 ) ;
T_2 V_28 = V_27 & ( 1 << ( V_19 % 8 ) ) ;
V_28 = V_28 >> ( V_19 % 8 ) ;
V_3 -> V_12 [ V_24 ] |= V_28 << V_20 ;
}
}
}
F_3 ( V_14 -> V_6 , V_3 , V_14 -> V_21 * V_14 -> V_22 / 8 ) ;
F_7 ( V_3 ) ;
}
static T_3 F_9 ( struct V_29 * V_16 , const char T_4 * V_30 ,
T_5 V_31 , T_6 * V_32 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
unsigned long V_33 ;
unsigned long V_34 = * V_32 ;
T_2 T_7 * V_35 ;
V_33 = V_16 -> V_36 . V_37 ;
if ( V_34 > V_33 )
return - V_38 ;
if ( V_31 + V_34 > V_33 )
V_31 = V_33 - V_34 ;
if ( ! V_31 )
return - V_38 ;
V_35 = ( void V_39 * ) ( V_16 -> V_17 + V_34 ) ;
if ( F_10 ( V_35 , V_30 , V_31 ) )
return - V_40 ;
F_8 ( V_14 ) ;
* V_32 += V_31 ;
return V_31 ;
}
static int F_11 ( int V_41 , struct V_29 * V_16 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
if ( V_41 != V_42 )
return F_6 ( V_14 -> V_6 , V_43 ) ;
else
return F_6 ( V_14 -> V_6 , V_44 ) ;
}
static void F_12 ( struct V_29 * V_16 , const struct V_45 * V_46 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
F_13 ( V_16 , V_46 ) ;
F_8 ( V_14 ) ;
}
static void F_14 ( struct V_29 * V_16 , const struct V_47 * V_48 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
F_15 ( V_16 , V_48 ) ;
F_8 ( V_14 ) ;
}
static void F_16 ( struct V_29 * V_16 , const struct V_49 * V_50 )
{
struct V_13 * V_14 = V_16 -> V_14 ;
F_17 ( V_16 , V_50 ) ;
F_8 ( V_14 ) ;
}
static void F_18 ( struct V_29 * V_16 ,
struct V_51 * V_52 )
{
F_8 ( V_16 -> V_14 ) ;
}
static int F_19 ( struct V_13 * V_14 )
{
int V_7 ;
T_1 V_53 , V_54 , V_55 , V_56 ;
if ( V_14 -> V_57 -> V_58 ) {
V_14 -> V_59 = F_20 ( & V_14 -> V_6 -> V_8 , NULL ) ;
if ( F_21 ( V_14 -> V_59 ) ) {
F_5 ( & V_14 -> V_6 -> V_8 , L_2 ) ;
return F_22 ( V_14 -> V_59 ) ;
}
V_14 -> V_60 = F_23 ( V_14 -> V_59 ) ;
F_24 ( V_14 -> V_59 , V_14 -> V_60 / 2 , V_14 -> V_60 ) ;
F_25 ( V_14 -> V_59 ) ;
F_26 ( & V_14 -> V_6 -> V_8 , L_3 ,
V_14 -> V_59 -> V_59 , V_14 -> V_60 ) ;
} ;
V_7 = F_6 ( V_14 -> V_6 , V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_14 -> V_62 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_14 -> V_63 ) {
V_7 = F_6 ( V_14 -> V_6 , V_64 ) ;
if ( V_7 < 0 )
return V_7 ;
} ;
V_55 = 0xc0 | ( V_14 -> V_55 & 0x1 ) << 3 ;
V_7 = F_6 ( V_14 -> V_6 , V_55 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_65 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_14 -> V_22 - 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_66 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_14 -> V_67 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_68 ) ;
if ( V_7 < 0 )
return V_7 ;
V_54 = ( ( V_14 -> V_69 - 1 ) & 0xf ) | ( V_14 -> V_70 & 0xf ) << 4 ;
V_7 = F_6 ( V_14 -> V_6 , V_54 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_71 ) ;
if ( V_7 < 0 )
return V_7 ;
V_53 = ( V_14 -> V_72 & 0xf ) | ( V_14 -> V_73 & 0xf ) << 4 ;
V_7 = F_6 ( V_14 -> V_6 , V_53 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_74 ) ;
if ( V_7 < 0 )
return V_7 ;
V_56 = 0x02 | ! ( V_14 -> V_75 & 0x1 ) << 4
| ( V_14 -> V_76 & 0x1 ) << 5 ;
V_7 = F_6 ( V_14 -> V_6 , V_56 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_77 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_14 -> V_78 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_79 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 ,
( V_14 -> V_57 -> V_80 & 0x1 << 2 ) & 0x14 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_81 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 ,
V_82 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_83 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , 0x0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_14 -> V_21 - 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_84 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , 0x0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 ,
V_14 -> V_85 + ( V_14 -> V_22 / 8 ) - 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_44 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_27 ( struct V_86 * V_87 )
{
struct V_13 * V_14 = F_28 ( V_87 ) ;
int V_7 ;
int V_88 = V_87 -> V_89 . V_88 ;
V_14 -> V_62 = V_88 ;
V_7 = F_6 ( V_14 -> V_6 , V_61 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_6 ( V_14 -> V_6 , V_14 -> V_62 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_29 ( struct V_86 * V_87 )
{
struct V_13 * V_14 = F_28 ( V_87 ) ;
return V_14 -> V_62 ;
}
static int F_30 ( struct V_86 * V_87 ,
struct V_29 * V_16 )
{
return ( V_16 -> V_90 == V_87 ) ;
}
static int F_31 ( struct V_5 * V_6 ,
const struct V_91 * V_92 )
{
struct V_86 * V_93 ;
char V_94 [ 12 ] ;
struct V_29 * V_16 ;
struct V_95 * V_96 = V_6 -> V_8 . V_97 ;
struct V_98 * V_99 ;
T_1 V_100 ;
struct V_13 * V_14 ;
T_2 * V_15 ;
int V_7 ;
if ( ! V_96 ) {
F_5 ( & V_6 -> V_8 , L_4 ) ;
return - V_38 ;
}
V_16 = F_32 ( sizeof( struct V_13 ) , & V_6 -> V_8 ) ;
if ( ! V_16 ) {
F_5 ( & V_6 -> V_8 , L_5 ) ;
return - V_11 ;
}
V_14 = V_16 -> V_14 ;
V_14 -> V_16 = V_16 ;
V_14 -> V_6 = V_6 ;
V_14 -> V_57 = (struct V_101 * ) F_33 (
V_102 , & V_6 -> V_8 ) -> V_12 ;
V_14 -> V_103 = F_34 ( V_6 -> V_8 . V_97 ,
L_6 , 0 ) ;
if ( ! F_35 ( V_14 -> V_103 ) ) {
V_7 = - V_38 ;
goto V_104;
}
if ( F_36 ( V_96 , L_7 , & V_14 -> V_21 ) )
V_14 -> V_21 = 96 ;
if ( F_36 ( V_96 , L_8 , & V_14 -> V_22 ) )
V_14 -> V_22 = 16 ;
if ( F_36 ( V_96 , L_9 , & V_14 -> V_85 ) )
V_14 -> V_85 = 1 ;
if ( F_36 ( V_96 , L_10 , & V_14 -> V_67 ) )
V_14 -> V_67 = 0 ;
if ( F_36 ( V_96 , L_11 , & V_14 -> V_72 ) )
V_14 -> V_72 = 2 ;
if ( F_36 ( V_96 , L_12 , & V_14 -> V_73 ) )
V_14 -> V_73 = 2 ;
V_14 -> V_63 = ! F_37 ( V_96 , L_13 ) ;
V_14 -> V_75 = F_37 ( V_96 , L_14 ) ;
V_14 -> V_76 = F_37 ( V_96 , L_15 ) ;
V_14 -> V_55 = F_37 ( V_96 , L_16 ) ;
V_14 -> V_62 = 127 ;
V_14 -> V_78 = V_14 -> V_57 -> V_105 ;
V_14 -> V_69 = V_14 -> V_57 -> V_106 ;
V_14 -> V_70 = V_14 -> V_57 -> V_107 ;
V_100 = V_14 -> V_21 * V_14 -> V_22 / 8 ;
V_15 = ( void * ) F_38 ( V_4 | V_108 ,
F_39 ( V_100 ) ) ;
if ( ! V_15 ) {
F_5 ( & V_6 -> V_8 , L_17 ) ;
V_7 = - V_11 ;
goto V_104;
}
V_99 = F_40 ( & V_6 -> V_8 , sizeof( struct V_98 ) , V_4 ) ;
if ( ! V_99 ) {
F_5 ( & V_6 -> V_8 , L_18 ) ;
V_7 = - V_11 ;
goto V_104;
}
V_99 -> V_109 = V_110 / V_111 ;
V_99 -> V_112 = F_18 ;
V_16 -> V_113 = & V_114 ;
V_16 -> V_36 = V_115 ;
V_16 -> V_36 . V_116 = V_14 -> V_21 / 8 ;
V_16 -> V_117 = V_99 ;
V_16 -> V_118 = V_119 ;
V_16 -> V_118 . V_120 = V_14 -> V_21 ;
V_16 -> V_118 . V_121 = V_14 -> V_21 ;
V_16 -> V_118 . V_122 = V_14 -> V_22 ;
V_16 -> V_118 . V_123 = V_14 -> V_22 ;
V_16 -> V_118 . V_124 . V_125 = 1 ;
V_16 -> V_118 . V_124 . V_126 = 0 ;
V_16 -> V_118 . V_127 . V_125 = 1 ;
V_16 -> V_118 . V_127 . V_126 = 0 ;
V_16 -> V_118 . V_128 . V_125 = 1 ;
V_16 -> V_118 . V_128 . V_126 = 0 ;
V_16 -> V_17 = ( T_2 V_39 T_7 * ) V_15 ;
V_16 -> V_36 . V_129 = F_41 ( V_15 ) ;
V_16 -> V_36 . V_37 = V_100 ;
F_42 ( V_16 ) ;
V_7 = F_43 ( & V_6 -> V_8 , V_14 -> V_103 ,
V_130 ,
L_19 ) ;
if ( V_7 ) {
F_5 ( & V_6 -> V_8 ,
L_20 ,
V_14 -> V_103 , V_7 ) ;
goto V_131;
}
F_44 ( V_6 , V_16 ) ;
F_45 ( V_14 -> V_103 , 0 ) ;
F_46 ( 4 ) ;
F_45 ( V_14 -> V_103 , 1 ) ;
F_46 ( 4 ) ;
V_7 = F_19 ( V_14 ) ;
if ( V_7 )
goto V_131;
V_7 = F_47 ( V_16 ) ;
if ( V_7 ) {
F_5 ( & V_6 -> V_8 , L_21 ) ;
goto V_132;
}
snprintf ( V_94 , sizeof( V_94 ) , L_22 , V_16 -> V_96 ) ;
V_93 = F_48 ( V_94 , & V_6 -> V_8 , V_14 ,
& V_133 , NULL ) ;
if ( F_21 ( V_93 ) ) {
F_5 ( & V_6 -> V_8 , L_23 ,
F_22 ( V_93 ) ) ;
goto V_134;
}
V_93 -> V_89 . V_88 = V_14 -> V_62 ;
V_93 -> V_89 . V_135 = V_136 ;
V_16 -> V_90 = V_93 ;
F_49 ( & V_6 -> V_8 , L_24 , V_16 -> V_96 , V_16 -> V_36 . V_92 , V_100 ) ;
return 0 ;
V_134:
F_50 ( V_16 ) ;
V_132:
if ( V_14 -> V_57 -> V_58 ) {
F_51 ( V_14 -> V_59 ) ;
F_52 ( V_14 -> V_59 ) ;
} ;
V_131:
F_53 ( V_16 ) ;
V_104:
F_54 ( V_16 ) ;
return V_7 ;
}
static int F_55 ( struct V_5 * V_6 )
{
struct V_29 * V_16 = F_56 ( V_6 ) ;
struct V_13 * V_14 = V_16 -> V_14 ;
F_6 ( V_14 -> V_6 , V_43 ) ;
F_57 ( V_16 -> V_90 ) ;
F_50 ( V_16 ) ;
if ( V_14 -> V_57 -> V_58 ) {
F_51 ( V_14 -> V_59 ) ;
F_52 ( V_14 -> V_59 ) ;
} ;
F_53 ( V_16 ) ;
F_58 ( F_59 ( V_16 -> V_36 . V_129 ) , F_39 ( V_16 -> V_36 . V_37 ) ) ;
F_54 ( V_16 ) ;
return 0 ;
}
