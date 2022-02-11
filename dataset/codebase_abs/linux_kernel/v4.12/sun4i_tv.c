static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 ,
V_3 ) ;
}
static inline struct V_1 *
F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 ,
V_5 ) ;
}
static const struct V_6 * F_4 ( const struct V_7 * V_8 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_5 ( V_10 ) ; V_9 ++ ) {
const struct V_6 * V_6 = & V_10 [ V_9 ] ;
F_6 ( L_1 ,
V_8 -> V_11 , V_6 -> V_11 ) ;
if ( ! strcmp ( V_8 -> V_11 , V_6 -> V_11 ) )
return V_6 ;
}
for ( V_9 = 0 ; V_9 < F_5 ( V_10 ) ; V_9 ++ ) {
const struct V_6 * V_6 = & V_10 [ V_9 ] ;
F_6 ( L_2 ,
V_8 -> V_11 , V_6 -> V_11 ,
V_8 -> V_12 , V_6 -> V_12 ) ;
if ( V_8 -> V_12 == V_6 -> V_12 )
return V_6 ;
}
return NULL ;
}
static void F_7 ( const struct V_6 * V_6 ,
struct V_7 * V_8 )
{
F_6 ( L_3 , V_8 -> V_11 ) ;
V_8 -> type = V_13 ;
V_8 -> clock = 13500 ;
V_8 -> V_14 = V_15 ;
V_8 -> V_16 = V_6 -> V_16 ;
V_8 -> V_17 = V_8 -> V_16 + V_6 -> V_18 ;
V_8 -> V_19 = V_8 -> V_17 + V_6 -> V_20 ;
V_8 -> V_21 = V_8 -> V_19 + V_6 -> V_22 ;
V_8 -> V_12 = V_6 -> V_12 ;
V_8 -> V_23 = V_8 -> V_12 + V_6 -> V_24 ;
V_8 -> V_25 = V_8 -> V_23 + V_6 -> V_26 ;
V_8 -> V_27 = V_8 -> V_25 + V_6 -> V_28 ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_29 * V_30 ,
struct V_31 * V_32 )
{
return 0 ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_33 = F_1 ( V_3 ) ;
struct V_34 * V_35 = F_10 ( V_3 -> V_35 ) ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_38 * V_39 = V_35 -> V_39 ;
F_6 ( L_4 ) ;
F_11 ( V_37 , 1 ) ;
F_12 ( V_33 -> V_40 , V_41 ,
V_42 ,
0 ) ;
F_13 ( V_39 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_33 = F_1 ( V_3 ) ;
struct V_34 * V_35 = F_10 ( V_3 -> V_35 ) ;
struct V_36 * V_37 = V_35 -> V_37 ;
struct V_38 * V_39 = V_35 -> V_39 ;
F_6 ( L_5 ) ;
F_15 ( V_39 ) ;
F_12 ( V_33 -> V_40 , V_41 ,
V_42 ,
V_42 ) ;
F_16 ( V_37 , 1 ) ;
}
static void F_17 ( struct V_2 * V_3 ,
struct V_7 * V_8 ,
struct V_7 * V_43 )
{
struct V_1 * V_33 = F_1 ( V_3 ) ;
struct V_34 * V_35 = F_10 ( V_3 -> V_35 ) ;
struct V_36 * V_37 = V_35 -> V_37 ;
const struct V_6 * V_6 = F_4 ( V_8 ) ;
F_18 ( V_37 , V_8 ) ;
F_12 ( V_33 -> V_40 , V_41 ,
V_44 ,
F_19 ( 0 , 1 ) |
F_19 ( 1 , 2 ) |
F_19 ( 2 , 3 ) |
F_19 ( 3 , 4 ) ) ;
F_20 ( V_33 -> V_40 , V_45 ,
V_6 -> V_8 |
( V_6 -> V_46 ? V_47 : 0 ) |
V_48 |
V_49 |
V_50 |
V_51 ) ;
F_20 ( V_33 -> V_40 , V_52 ,
F_21 ( 0 ) |
( V_6 -> V_53 ? F_21 ( 3 ) : 0 ) |
V_54 |
V_55 |
V_56 |
V_57 |
( V_6 -> V_58 ? F_22 ( 25 ) : 0 ) |
F_22 ( 30 ) ) ;
F_20 ( V_33 -> V_40 , V_59 ,
F_23 ( 1 , 0 ) |
F_23 ( 2 , 0 ) ) ;
F_20 ( V_33 -> V_40 , V_60 ,
V_6 -> V_61 ) ;
F_20 ( V_33 -> V_40 , V_62 ,
F_24 ( V_6 -> V_63 ) |
F_25 ( V_6 -> V_64 ) ) ;
F_20 ( V_33 -> V_40 , V_65 ,
F_26 ( 22 ) |
F_27 ( V_6 -> V_66 ) ) ;
F_20 ( V_33 -> V_40 , V_67 ,
F_28 ( V_6 -> V_68 -> V_69 ) |
F_29 ( V_6 -> V_68 -> V_70 ) ) ;
F_20 ( V_33 -> V_40 , V_71 ,
F_30 ( 0 , 0x18 ) |
F_30 ( 1 , 0x18 ) |
F_30 ( 2 , 0x18 ) |
F_30 ( 3 , 0x18 ) ) ;
F_20 ( V_33 -> V_40 , V_72 ,
F_31 ( V_6 -> V_73 -> V_74 ) |
F_32 ( V_6 -> V_73 -> V_75 ) ) ;
F_20 ( V_33 -> V_40 , V_76 ,
F_33 ( 126 ) |
F_34 ( 68 ) |
F_35 ( 22 ) ) ;
F_20 ( V_33 -> V_40 , V_77 ,
F_36 ( V_6 -> V_78 -> V_74 ) |
F_37 ( V_6 -> V_78 -> V_75 ) ) ;
F_20 ( V_33 -> V_40 , V_79 ,
F_38 ( 0x10 ) |
F_39 ( V_6 -> V_80 ) ) ;
F_20 ( V_33 -> V_40 , V_81 ,
F_40 ( 1440 ) ) ;
F_20 ( V_33 -> V_40 , V_82 ,
V_83 ) ;
F_20 ( V_33 -> V_40 , V_84 ,
V_85 |
V_86 ) ;
F_20 ( V_33 -> V_40 , V_87 ,
F_41 ( V_6 -> V_88 -> V_89 ) |
F_42 ( V_6 -> V_88 -> line ) |
( V_6 -> V_88 -> V_90 ?
V_91 : 0 ) ) ;
F_20 ( V_33 -> V_40 , V_92 , 0 ) ;
F_43 ( V_37 -> V_93 , V_8 -> V_94 * 1000 ) ;
}
static void F_44 ( struct V_2 * V_3 )
{
F_45 ( V_3 ) ;
}
static int F_46 ( struct V_4 * V_5 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_5 ( V_10 ) ; V_9 ++ ) {
struct V_7 * V_8 ;
const struct V_6 * V_6 = & V_10 [ V_9 ] ;
V_8 = F_47 ( V_5 -> V_95 ) ;
if ( ! V_8 ) {
F_48 ( L_6 ) ;
return 0 ;
}
strcpy ( V_8 -> V_11 , V_6 -> V_11 ) ;
F_7 ( V_6 , V_8 ) ;
F_49 ( V_5 , V_8 ) ;
}
return V_9 ;
}
static int F_50 ( struct V_4 * V_5 ,
struct V_7 * V_8 )
{
return V_96 ;
}
static void
F_51 ( struct V_4 * V_5 )
{
F_52 ( V_5 ) ;
}
static int F_53 ( struct V_97 * V_95 , struct V_97 * V_98 ,
void * V_99 )
{
struct V_100 * V_101 = F_54 ( V_95 ) ;
struct V_102 * V_103 = V_99 ;
struct V_104 * V_105 = V_103 -> V_106 ;
struct V_1 * V_33 ;
struct V_107 * V_108 ;
void T_1 * V_40 ;
int V_109 ;
V_33 = F_55 ( V_95 , sizeof( * V_33 ) , V_110 ) ;
if ( ! V_33 )
return - V_111 ;
V_33 -> V_105 = V_105 ;
F_56 ( V_95 , V_33 ) ;
V_108 = F_57 ( V_101 , V_112 , 0 ) ;
V_40 = F_58 ( V_95 , V_108 ) ;
if ( F_59 ( V_40 ) ) {
F_60 ( V_95 , L_7 ) ;
return F_61 ( V_40 ) ;
}
V_33 -> V_40 = F_62 ( V_95 , V_40 ,
& V_113 ) ;
if ( F_59 ( V_33 -> V_40 ) ) {
F_60 ( V_95 , L_8 ) ;
return F_61 ( V_33 -> V_40 ) ;
}
V_33 -> V_114 = F_63 ( V_95 , NULL ) ;
if ( F_59 ( V_33 -> V_114 ) ) {
F_60 ( V_95 , L_9 ) ;
return F_61 ( V_33 -> V_114 ) ;
}
V_109 = F_64 ( V_33 -> V_114 ) ;
if ( V_109 ) {
F_60 ( V_95 , L_10 ) ;
return V_109 ;
}
V_33 -> V_115 = F_65 ( V_95 , NULL ) ;
if ( F_59 ( V_33 -> V_115 ) ) {
F_60 ( V_95 , L_11 ) ;
V_109 = F_61 ( V_33 -> V_115 ) ;
goto V_116;
}
F_66 ( V_33 -> V_115 ) ;
F_67 ( & V_33 -> V_3 ,
& V_117 ) ;
V_109 = F_68 ( V_103 ,
& V_33 -> V_3 ,
& V_118 ,
V_119 ,
NULL ) ;
if ( V_109 ) {
F_60 ( V_95 , L_12 ) ;
goto V_120;
}
V_33 -> V_3 . V_121 = F_69 ( V_103 ,
V_95 -> V_122 ) ;
if ( ! V_33 -> V_3 . V_121 ) {
V_109 = - V_123 ;
goto V_120;
}
F_70 ( & V_33 -> V_5 ,
& V_124 ) ;
V_109 = F_71 ( V_103 , & V_33 -> V_5 ,
& V_125 ,
V_126 ) ;
if ( V_109 ) {
F_60 ( V_95 ,
L_13 ) ;
goto V_127;
}
V_33 -> V_5 . V_128 = true ;
F_72 ( & V_33 -> V_5 , & V_33 -> V_3 ) ;
return 0 ;
V_127:
F_45 ( & V_33 -> V_3 ) ;
V_120:
F_73 ( V_33 -> V_115 ) ;
V_116:
F_74 ( V_33 -> V_114 ) ;
return V_109 ;
}
static void F_75 ( struct V_97 * V_95 , struct V_97 * V_98 ,
void * V_99 )
{
struct V_1 * V_33 = F_76 ( V_95 ) ;
F_52 ( & V_33 -> V_5 ) ;
F_45 ( & V_33 -> V_3 ) ;
F_73 ( V_33 -> V_115 ) ;
}
static int F_77 ( struct V_100 * V_101 )
{
return F_78 ( & V_101 -> V_95 , & V_129 ) ;
}
static int F_79 ( struct V_100 * V_101 )
{
F_80 ( & V_101 -> V_95 , & V_129 ) ;
return 0 ;
}
