static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) == 1 ;
}
static inline void F_3 ( struct V_4 * V_5 , T_1 V_6 )
{
F_4 ( V_6 , F_5 ( V_5 , 4 ) ) ;
}
static inline void F_6 ( struct V_4 * V_5 ,
T_2 V_7 , enum V_8 V_9 )
{
F_7 ( F_8 ( V_5 , V_10 , V_11 ,
F_9 ( V_12 , V_7 ) |
F_9 ( V_13 , V_9 ) ) ) ;
}
static inline void F_10 ( struct V_1 * V_2 ,
struct V_4 * V_5 , bool V_14 )
{
T_1 V_15 , V_16 = 0 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_17 / 4 ; V_15 ++ )
V_16 ^= F_11 ( V_5 -> V_18 + V_15 * 4 ) ;
F_12 ( V_2 , V_5 , V_16 , V_14 ) ;
}
static struct V_4 *
F_13 ( struct V_1 * V_2 , const void * V_18 , int V_17 )
{
struct V_4 * V_5 ;
F_7 ( V_17 % 4 ) ;
V_5 = F_14 ( V_17 + V_19 + 4 , V_20 ) ;
F_15 ( V_5 , V_19 ) ;
memcpy ( F_5 ( V_5 , V_17 ) , V_18 , V_17 ) ;
return V_5 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 V_7 )
{
struct V_21 * V_21 = V_2 -> V_22 . V_23 . V_21 ;
T_1 V_24 ;
int V_25 , V_26 , V_15 = 5 ;
while ( V_15 -- ) {
if ( ! F_17 ( & V_2 -> V_22 . V_27 ,
F_18 ( 300 ) ) ) {
F_19 ( V_2 -> V_2 , L_1 , V_28 ) ;
continue;
}
V_24 = F_11 ( V_2 -> V_22 . V_23 . V_29 ) ;
V_25 = V_21 -> V_30 * F_20 ( V_21 ) ;
V_26 = F_21 ( V_2 , V_31 , V_32 ,
& V_2 -> V_22 . V_23 , V_20 ,
V_33 ,
& V_2 -> V_22 . V_27 ) ;
if ( V_26 )
return V_26 ;
if ( V_25 )
F_22 ( V_2 -> V_2 , L_2 ,
V_25 ) ;
if ( F_23 ( V_34 , V_24 ) == V_7 &&
F_23 ( V_35 , V_24 ) == V_36 )
return 0 ;
F_22 ( V_2 -> V_2 , L_3 ,
F_23 ( V_35 , V_24 ) ,
V_7 , F_23 ( V_34 , V_24 ) ) ;
}
F_22 ( V_2 -> V_2 , L_4 , V_28 ) ;
return - V_37 ;
}
static int
F_24 ( struct V_1 * V_2 , struct V_4 * V_5 ,
enum V_8 V_9 , bool V_38 )
{
struct V_39 * V_40 = F_25 ( V_2 ) ;
unsigned V_41 = F_26 ( V_40 ,
V_2 -> V_42 [ V_43 ] ) ;
int V_44 , V_26 ;
T_2 V_7 = 0 ;
if ( F_27 ( V_45 , & V_2 -> V_46 ) )
return 0 ;
F_28 ( & V_2 -> V_22 . V_47 ) ;
if ( V_38 )
while ( ! V_7 )
V_7 = ++ V_2 -> V_22 . V_48 & 0xf ;
F_6 ( V_5 , V_7 , V_9 ) ;
if ( V_2 -> V_22 . V_27 . V_49 )
F_22 ( V_2 -> V_2 , L_5 ) ;
F_10 ( V_2 , V_5 , V_38 ) ;
F_29 ( V_2 , V_41 , V_5 -> V_17 ) ;
V_26 = F_30 ( V_40 , V_41 , V_5 -> V_18 , V_5 -> V_17 , & V_44 , 500 ) ;
if ( V_26 ) {
F_22 ( V_2 -> V_2 , L_6 , V_26 ) ;
goto V_50;
}
if ( V_44 != V_5 -> V_17 )
F_22 ( V_2 -> V_2 , L_7 , V_28 ) ;
if ( V_38 )
V_26 = F_16 ( V_2 , V_7 ) ;
V_50:
F_31 ( & V_2 -> V_22 . V_47 ) ;
F_32 ( V_5 ) ;
return V_26 ;
}
static int F_33 ( struct V_1 * V_2 ,
enum V_51 V_52 , T_1 V_6 )
{
struct V_4 * V_5 ;
struct {
T_3 V_53 ;
T_3 V_54 ;
} V_55 V_56 ( 4 ) V_57 = {
. V_53 = F_34 ( V_52 ) ,
. V_54 = F_34 ( V_6 ) ,
} ;
V_5 = F_13 ( V_2 , & V_57 , sizeof( V_57 ) ) ;
return F_24 ( V_2 , V_5 , V_58 , V_52 == 5 ) ;
}
int F_35 ( struct V_1 * V_2 , int V_59 )
{
int V_26 ;
if ( ! F_27 ( V_60 , & V_2 -> V_46 ) )
return 0 ;
V_26 = F_33 ( V_2 , V_61 ,
V_59 ) ;
if ( V_26 ) {
F_19 ( V_2 -> V_2 , L_8 ) ;
return V_26 ;
}
V_2 -> V_62 = true ;
return 0 ;
}
int
F_36 ( struct V_1 * V_2 , enum V_63 V_64 , T_1 V_6 )
{
struct V_4 * V_5 ;
struct {
T_3 V_53 ;
T_3 V_54 ;
} V_55 V_56 ( 4 ) V_57 = {
. V_53 = F_34 ( V_64 ) ,
. V_54 = F_34 ( V_6 ) ,
} ;
V_5 = F_13 ( V_2 , & V_57 , sizeof( V_57 ) ) ;
return F_24 ( V_2 , V_5 , V_65 , true ) ;
}
int F_37 ( struct V_1 * V_2 , T_1 V_66 ,
const struct V_67 * V_18 , int V_68 )
{
const int V_69 = V_70 / 8 ;
struct V_4 * V_5 ;
int V_71 , V_15 , V_26 ;
if ( ! V_68 )
return 0 ;
V_71 = F_38 ( V_69 , V_68 ) ;
V_5 = F_14 ( V_71 * 8 + V_19 + 4 , V_20 ) ;
if ( ! V_5 )
return - V_72 ;
F_15 ( V_5 , V_19 ) ;
for ( V_15 = 0 ; V_15 < V_71 ; V_15 ++ ) {
F_3 ( V_5 , V_66 + V_18 [ V_15 ] . V_73 ) ;
F_3 ( V_5 , V_18 [ V_15 ] . V_54 ) ;
}
V_26 = F_24 ( V_2 , V_5 , V_74 , V_71 == V_68 ) ;
if ( V_26 )
return V_26 ;
return F_37 ( V_2 , V_66 , V_18 + V_71 , V_68 - V_71 ) ;
}
int F_39 ( struct V_1 * V_2 , T_1 V_75 ,
const T_1 * V_18 , int V_68 )
{
const int V_76 = V_70 / 4 - 1 ;
struct V_4 * V_5 ;
int V_71 , V_15 , V_26 ;
if ( ! V_68 )
return 0 ;
V_71 = F_38 ( V_76 , V_68 ) ;
V_5 = F_14 ( V_71 * 4 + V_19 + 4 , V_20 ) ;
if ( ! V_5 )
return - V_72 ;
F_15 ( V_5 , V_19 ) ;
F_3 ( V_5 , V_77 + V_75 ) ;
for ( V_15 = 0 ; V_15 < V_71 ; V_15 ++ )
F_3 ( V_5 , V_18 [ V_15 ] ) ;
V_26 = F_24 ( V_2 , V_5 , V_78 , V_71 == V_68 ) ;
if ( V_26 )
return V_26 ;
return F_39 ( V_2 , V_75 + V_71 * 4 ,
V_18 + V_71 , V_68 - V_71 ) ;
}
static int F_40 ( struct V_1 * V_2 ,
const struct V_79 * V_80 ,
const void * V_18 , T_1 V_17 , T_1 V_81 )
{
F_41 ( V_82 ) ;
struct V_79 V_29 = * V_80 ;
T_3 V_73 ;
T_1 V_6 ;
int V_26 ;
V_73 = F_34 ( F_9 ( V_83 , V_84 ) |
F_9 ( V_85 , V_10 ) |
F_9 ( V_86 , V_17 ) ) ;
memcpy ( V_29 . V_29 , & V_73 , sizeof( V_73 ) ) ;
memcpy ( V_29 . V_29 + sizeof( V_73 ) , V_18 , V_17 ) ;
memset ( V_29 . V_29 + sizeof( V_73 ) + V_17 , 0 , 8 ) ;
V_26 = F_42 ( V_2 , V_87 ,
V_88 , V_81 ) ;
if ( V_26 )
return V_26 ;
V_17 = F_43 ( V_17 , 4 ) ;
V_26 = F_42 ( V_2 , V_87 ,
V_89 , V_17 << 16 ) ;
if ( V_26 )
return V_26 ;
V_29 . V_17 = V_19 + V_17 + 4 ;
V_26 = F_21 ( V_2 , V_90 , V_43 ,
& V_29 , V_20 ,
V_33 , & V_82 ) ;
if ( V_26 )
return V_26 ;
if ( ! F_17 ( & V_82 , F_18 ( 1000 ) ) ) {
F_22 ( V_2 -> V_2 , L_9 ) ;
F_44 ( V_29 . V_21 ) ;
return - V_37 ;
}
if ( F_20 ( V_29 . V_21 ) ) {
F_22 ( V_2 -> V_2 , L_10 ,
V_29 . V_21 -> V_30 ) ;
return V_29 . V_21 -> V_30 ;
}
V_6 = F_2 ( V_2 , V_91 ) ;
V_6 ++ ;
F_45 ( V_2 , V_91 , V_6 ) ;
return 0 ;
}
static int
F_46 ( struct V_1 * V_2 , struct V_79 * V_80 ,
const void * V_18 , int V_17 , T_1 V_81 )
{
int V_68 , V_26 ;
if ( V_17 == 0 )
return 0 ;
V_68 = F_38 ( V_92 , V_17 ) ;
V_26 = F_40 ( V_2 , V_80 , V_18 , V_68 , V_81 ) ;
if ( V_26 )
return V_26 ;
if ( ! F_47 ( V_2 , V_93 , F_48 ( 31 ) , F_48 ( 31 ) , 500 ) )
return - V_37 ;
return F_46 ( V_2 , V_80 , V_18 + V_68 , V_17 - V_68 , V_81 + V_68 ) ;
}
static int
F_49 ( struct V_1 * V_2 , const struct V_94 * V_95 )
{
struct V_79 V_80 ;
void * V_96 ;
T_1 V_97 , V_98 ;
int V_15 , V_26 ;
V_96 = F_50 ( V_95 -> V_96 , sizeof( V_95 -> V_96 ) , V_20 ) ;
if ( ! V_96 )
return - V_72 ;
if ( F_51 ( V_2 , V_99 , & V_80 ) ) {
V_26 = - V_72 ;
goto error;
}
V_97 = F_52 ( V_95 -> V_100 . V_97 ) - sizeof( V_95 -> V_96 ) ;
F_53 ( V_2 -> V_2 , L_11 ,
V_97 , sizeof( V_95 -> V_96 ) ) ;
V_26 = F_46 ( V_2 , & V_80 , V_95 -> V_101 , V_97 , sizeof( V_95 -> V_96 ) ) ;
if ( V_26 )
goto error;
V_98 = F_52 ( V_95 -> V_100 . V_98 ) ;
F_53 ( V_2 -> V_2 , L_12 , V_98 ) ;
V_26 = F_46 ( V_2 , & V_80 , V_95 -> V_101 + V_97 ,
V_98 , V_102 ) ;
if ( V_26 )
goto error;
V_26 = F_54 ( V_2 , V_103 , V_90 ,
0x12 , 0 , V_96 , sizeof( V_95 -> V_96 ) ) ;
if ( V_26 < 0 )
goto error;
V_26 = 0 ;
for ( V_15 = 100 ; V_15 && ! F_1 ( V_2 ) ; V_15 -- )
F_55 ( 10 ) ;
if ( ! V_15 ) {
V_26 = - V_37 ;
goto error;
}
F_53 ( V_2 -> V_2 , L_13 ) ;
error:
F_56 ( V_96 ) ;
F_57 ( V_2 , & V_80 ) ;
return V_26 ;
}
static int F_58 ( struct V_1 * V_2 )
{
const struct V_104 * V_95 ;
const struct V_105 * V_100 ;
int V_17 , V_26 ;
T_1 V_6 ;
F_45 ( V_2 , V_106 , ( V_107 |
V_108 ) ) ;
if ( F_1 ( V_2 ) )
return 0 ;
V_26 = F_59 ( & V_95 , V_109 , V_2 -> V_2 ) ;
if ( V_26 )
return V_26 ;
if ( ! V_95 || ! V_95 -> V_18 || V_95 -> V_110 < sizeof( * V_100 ) )
goto V_111;
V_100 = ( const struct V_105 * ) V_95 -> V_18 ;
if ( F_52 ( V_100 -> V_97 ) <= V_112 )
goto V_111;
V_17 = sizeof( * V_100 ) ;
V_17 += F_52 ( V_100 -> V_97 ) ;
V_17 += F_52 ( V_100 -> V_98 ) ;
if ( V_95 -> V_110 != V_17 )
goto V_111;
V_6 = F_60 ( V_100 -> V_113 ) ;
F_61 ( V_2 -> V_2 ,
L_14 ,
( V_6 >> 12 ) & 0xf , ( V_6 >> 8 ) & 0xf , V_6 & 0xf ,
F_60 ( V_100 -> V_114 ) , V_100 -> V_115 ) ;
V_17 = F_52 ( V_100 -> V_97 ) ;
F_45 ( V_2 , 0x94c , 0 ) ;
F_45 ( V_2 , V_116 , 0 ) ;
F_62 ( V_2 ) ;
F_55 ( 5 ) ;
F_45 ( V_2 , 0xa44 , 0 ) ;
F_45 ( V_2 , 0x230 , 0x84210 ) ;
F_45 ( V_2 , 0x400 , 0x80c00 ) ;
F_45 ( V_2 , 0x800 , 1 ) ;
F_63 ( V_2 , V_117 , 0 , ( V_118 |
V_119 |
V_120 |
V_121 ) ) ;
F_45 ( V_2 , V_116 , 1 ) ;
F_45 ( V_2 , V_106 , ( V_107 |
V_108 ) ) ;
V_6 = F_64 ( V_2 , V_106 , V_122 ) ;
V_6 &= ~ V_122 ;
F_45 ( V_2 , V_106 , V_6 ) ;
F_45 ( V_2 , V_123 , 0x400230 ) ;
F_45 ( V_2 , V_124 , 1 ) ;
F_45 ( V_2 , V_125 , 0x44 ) ;
F_45 ( V_2 , V_126 , 3 ) ;
V_26 = F_49 ( V_2 , ( const struct V_94 * ) V_95 -> V_18 ) ;
F_65 ( V_95 ) ;
return V_26 ;
V_111:
F_22 ( V_2 -> V_2 , L_15 ) ;
F_65 ( V_95 ) ;
return - V_127 ;
}
int F_66 ( struct V_1 * V_2 )
{
int V_26 ;
F_67 ( & V_2 -> V_22 . V_47 ) ;
V_26 = F_58 ( V_2 ) ;
if ( V_26 )
return V_26 ;
F_68 ( V_60 , & V_2 -> V_46 ) ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 )
{
int V_26 ;
V_26 = F_33 ( V_2 , V_128 , 1 ) ;
if ( V_26 )
return V_26 ;
F_70 ( & V_2 -> V_22 . V_27 ) ;
if ( F_51 ( V_2 , V_129 , & V_2 -> V_22 . V_23 ) ) {
F_57 ( V_2 , & V_2 -> V_22 . V_23 ) ;
return - V_72 ;
}
V_26 = F_21 ( V_2 , V_31 , V_32 ,
& V_2 -> V_22 . V_23 , V_20 ,
V_33 , & V_2 -> V_22 . V_27 ) ;
if ( V_26 ) {
F_57 ( V_2 , & V_2 -> V_22 . V_23 ) ;
return V_26 ;
}
return 0 ;
}
void F_71 ( struct V_1 * V_2 )
{
F_44 ( V_2 -> V_22 . V_23 . V_21 ) ;
F_57 ( V_2 , & V_2 -> V_22 . V_23 ) ;
}
