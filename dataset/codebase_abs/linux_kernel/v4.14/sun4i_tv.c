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
static void F_8 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
struct V_30 * V_31 = F_9 ( V_3 -> V_31 ) ;
struct V_32 * V_33 = V_31 -> V_33 ;
F_6 ( L_4 ) ;
F_10 ( V_33 , 1 ) ;
F_11 ( V_29 -> V_34 , V_35 ,
V_36 ,
0 ) ;
F_12 ( V_31 -> V_37 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
struct V_30 * V_31 = F_9 ( V_3 -> V_31 ) ;
struct V_32 * V_33 = V_31 -> V_33 ;
F_6 ( L_5 ) ;
F_14 ( V_31 -> V_37 ) ;
F_11 ( V_29 -> V_34 , V_35 ,
V_36 ,
V_36 ) ;
F_15 ( V_33 , 1 ) ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_7 * V_8 ,
struct V_7 * V_38 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
struct V_30 * V_31 = F_9 ( V_3 -> V_31 ) ;
struct V_32 * V_33 = V_31 -> V_33 ;
const struct V_6 * V_6 = F_4 ( V_8 ) ;
F_17 ( V_33 , V_8 ) ;
F_18 ( V_33 , 1 , V_3 ) ;
F_11 ( V_29 -> V_34 , V_35 ,
V_39 ,
F_19 ( 0 , 1 ) |
F_19 ( 1 , 2 ) |
F_19 ( 2 , 3 ) |
F_19 ( 3 , 4 ) ) ;
F_20 ( V_29 -> V_34 , V_40 ,
V_6 -> V_8 |
( V_6 -> V_41 ? V_42 : 0 ) |
V_43 |
V_44 |
V_45 |
V_46 ) ;
F_20 ( V_29 -> V_34 , V_47 ,
F_21 ( 0 ) |
( V_6 -> V_48 ? F_21 ( 3 ) : 0 ) |
V_49 |
V_50 |
V_51 |
V_52 |
( V_6 -> V_53 ? F_22 ( 25 ) : 0 ) |
F_22 ( 30 ) ) ;
F_20 ( V_29 -> V_34 , V_54 ,
F_23 ( 1 , 0 ) |
F_23 ( 2 , 0 ) ) ;
F_20 ( V_29 -> V_34 , V_55 ,
V_6 -> V_56 ) ;
F_20 ( V_29 -> V_34 , V_57 ,
F_24 ( V_6 -> V_58 ) |
F_25 ( V_6 -> V_59 ) ) ;
F_20 ( V_29 -> V_34 , V_60 ,
F_26 ( 22 ) |
F_27 ( V_6 -> V_61 ) ) ;
F_20 ( V_29 -> V_34 , V_62 ,
F_28 ( V_6 -> V_63 -> V_64 ) |
F_29 ( V_6 -> V_63 -> V_65 ) ) ;
F_20 ( V_29 -> V_34 , V_66 ,
F_30 ( 0 , 0x18 ) |
F_30 ( 1 , 0x18 ) |
F_30 ( 2 , 0x18 ) |
F_30 ( 3 , 0x18 ) ) ;
F_20 ( V_29 -> V_34 , V_67 ,
F_31 ( V_6 -> V_68 -> V_69 ) |
F_32 ( V_6 -> V_68 -> V_70 ) ) ;
F_20 ( V_29 -> V_34 , V_71 ,
F_33 ( 126 ) |
F_34 ( 68 ) |
F_35 ( 22 ) ) ;
F_20 ( V_29 -> V_34 , V_72 ,
F_36 ( V_6 -> V_73 -> V_69 ) |
F_37 ( V_6 -> V_73 -> V_70 ) ) ;
F_20 ( V_29 -> V_34 , V_74 ,
F_38 ( 0x10 ) |
F_39 ( V_6 -> V_75 ) ) ;
F_20 ( V_29 -> V_34 , V_76 ,
F_40 ( 1440 ) ) ;
F_20 ( V_29 -> V_34 , V_77 ,
V_78 ) ;
F_20 ( V_29 -> V_34 , V_79 ,
V_80 |
V_81 ) ;
F_20 ( V_29 -> V_34 , V_82 ,
F_41 ( V_6 -> V_83 -> V_84 ) |
F_42 ( V_6 -> V_83 -> line ) |
( V_6 -> V_83 -> V_85 ?
V_86 : 0 ) ) ;
F_20 ( V_29 -> V_34 , V_87 , 0 ) ;
}
static void F_43 ( struct V_2 * V_3 )
{
F_44 ( V_3 ) ;
}
static int F_45 ( struct V_4 * V_5 )
{
int V_9 ;
for ( V_9 = 0 ; V_9 < F_5 ( V_10 ) ; V_9 ++ ) {
struct V_7 * V_8 ;
const struct V_6 * V_6 = & V_10 [ V_9 ] ;
V_8 = F_46 ( V_5 -> V_88 ) ;
if ( ! V_8 ) {
F_47 ( L_6 ) ;
return 0 ;
}
strcpy ( V_8 -> V_11 , V_6 -> V_11 ) ;
F_7 ( V_6 , V_8 ) ;
F_48 ( V_5 , V_8 ) ;
}
return V_9 ;
}
static int F_49 ( struct V_4 * V_5 ,
struct V_7 * V_8 )
{
return V_89 ;
}
static void
F_50 ( struct V_4 * V_5 )
{
F_51 ( V_5 ) ;
}
static int F_52 ( struct V_90 * V_88 , struct V_90 * V_91 ,
void * V_92 )
{
struct V_93 * V_94 = F_53 ( V_88 ) ;
struct V_95 * V_96 = V_92 ;
struct V_97 * V_98 = V_96 -> V_99 ;
struct V_1 * V_29 ;
struct V_100 * V_101 ;
void T_1 * V_34 ;
int V_102 ;
V_29 = F_54 ( V_88 , sizeof( * V_29 ) , V_103 ) ;
if ( ! V_29 )
return - V_104 ;
V_29 -> V_98 = V_98 ;
F_55 ( V_88 , V_29 ) ;
V_101 = F_56 ( V_94 , V_105 , 0 ) ;
V_34 = F_57 ( V_88 , V_101 ) ;
if ( F_58 ( V_34 ) ) {
F_59 ( V_88 , L_7 ) ;
return F_60 ( V_34 ) ;
}
V_29 -> V_34 = F_61 ( V_88 , V_34 ,
& V_106 ) ;
if ( F_58 ( V_29 -> V_34 ) ) {
F_59 ( V_88 , L_8 ) ;
return F_60 ( V_29 -> V_34 ) ;
}
V_29 -> V_107 = F_62 ( V_88 , NULL ) ;
if ( F_58 ( V_29 -> V_107 ) ) {
F_59 ( V_88 , L_9 ) ;
return F_60 ( V_29 -> V_107 ) ;
}
V_102 = F_63 ( V_29 -> V_107 ) ;
if ( V_102 ) {
F_59 ( V_88 , L_10 ) ;
return V_102 ;
}
V_29 -> V_108 = F_64 ( V_88 , NULL ) ;
if ( F_58 ( V_29 -> V_108 ) ) {
F_59 ( V_88 , L_11 ) ;
V_102 = F_60 ( V_29 -> V_108 ) ;
goto V_109;
}
F_65 ( V_29 -> V_108 ) ;
F_66 ( & V_29 -> V_3 ,
& V_110 ) ;
V_102 = F_67 ( V_96 ,
& V_29 -> V_3 ,
& V_111 ,
V_112 ,
NULL ) ;
if ( V_102 ) {
F_59 ( V_88 , L_12 ) ;
goto V_113;
}
V_29 -> V_3 . V_114 = F_68 ( V_96 ,
V_88 -> V_115 ) ;
if ( ! V_29 -> V_3 . V_114 ) {
V_102 = - V_116 ;
goto V_113;
}
F_69 ( & V_29 -> V_5 ,
& V_117 ) ;
V_102 = F_70 ( V_96 , & V_29 -> V_5 ,
& V_118 ,
V_119 ) ;
if ( V_102 ) {
F_59 ( V_88 ,
L_13 ) ;
goto V_120;
}
V_29 -> V_5 . V_121 = true ;
F_71 ( & V_29 -> V_5 , & V_29 -> V_3 ) ;
return 0 ;
V_120:
F_44 ( & V_29 -> V_3 ) ;
V_113:
F_72 ( V_29 -> V_108 ) ;
V_109:
F_73 ( V_29 -> V_107 ) ;
return V_102 ;
}
static void F_74 ( struct V_90 * V_88 , struct V_90 * V_91 ,
void * V_92 )
{
struct V_1 * V_29 = F_75 ( V_88 ) ;
F_51 ( & V_29 -> V_5 ) ;
F_44 ( & V_29 -> V_3 ) ;
F_72 ( V_29 -> V_108 ) ;
}
static int F_76 ( struct V_93 * V_94 )
{
return F_77 ( & V_94 -> V_88 , & V_122 ) ;
}
static int F_78 ( struct V_93 * V_94 )
{
F_79 ( & V_94 -> V_88 , & V_122 ) ;
return 0 ;
}
