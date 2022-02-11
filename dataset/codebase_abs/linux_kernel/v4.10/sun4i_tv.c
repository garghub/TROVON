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
struct V_34 * V_35 = V_33 -> V_35 ;
struct V_36 * V_37 = V_35 -> V_37 ;
F_6 ( L_4 ) ;
F_10 ( V_37 , 1 ) ;
F_11 ( V_33 -> V_38 , V_39 ,
V_40 ,
0 ) ;
F_12 ( V_35 -> V_41 ) ;
}
static void F_13 ( struct V_2 * V_3 )
{
struct V_1 * V_33 = F_1 ( V_3 ) ;
struct V_34 * V_35 = V_33 -> V_35 ;
struct V_36 * V_37 = V_35 -> V_37 ;
F_6 ( L_5 ) ;
F_14 ( V_35 -> V_41 ) ;
F_11 ( V_33 -> V_38 , V_39 ,
V_40 ,
V_40 ) ;
F_15 ( V_37 , 1 ) ;
}
static void F_16 ( struct V_2 * V_3 ,
struct V_7 * V_8 ,
struct V_7 * V_42 )
{
struct V_1 * V_33 = F_1 ( V_3 ) ;
struct V_34 * V_35 = V_33 -> V_35 ;
struct V_36 * V_37 = V_35 -> V_37 ;
const struct V_6 * V_6 = F_4 ( V_8 ) ;
F_17 ( V_37 , V_8 ) ;
F_11 ( V_33 -> V_38 , V_39 ,
V_43 ,
F_18 ( 0 , 1 ) |
F_18 ( 1 , 2 ) |
F_18 ( 2 , 3 ) |
F_18 ( 3 , 4 ) ) ;
F_19 ( V_33 -> V_38 , V_44 ,
V_6 -> V_8 |
( V_6 -> V_45 ? V_46 : 0 ) |
V_47 |
V_48 |
V_49 |
V_50 ) ;
F_19 ( V_33 -> V_38 , V_51 ,
F_20 ( 0 ) |
( V_6 -> V_52 ? F_20 ( 3 ) : 0 ) |
V_53 |
V_54 |
V_55 |
V_56 |
( V_6 -> V_57 ? F_21 ( 25 ) : 0 ) |
F_21 ( 30 ) ) ;
F_19 ( V_33 -> V_38 , V_58 ,
F_22 ( 1 , 0 ) |
F_22 ( 2 , 0 ) ) ;
F_19 ( V_33 -> V_38 , V_59 ,
V_6 -> V_60 ) ;
F_19 ( V_33 -> V_38 , V_61 ,
F_23 ( V_6 -> V_62 ) |
F_24 ( V_6 -> V_63 ) ) ;
F_19 ( V_33 -> V_38 , V_64 ,
F_25 ( 22 ) |
F_26 ( V_6 -> V_65 ) ) ;
F_19 ( V_33 -> V_38 , V_66 ,
F_27 ( V_6 -> V_67 -> V_68 ) |
F_28 ( V_6 -> V_67 -> V_69 ) ) ;
F_19 ( V_33 -> V_38 , V_70 ,
F_29 ( 0 , 0x18 ) |
F_29 ( 1 , 0x18 ) |
F_29 ( 2 , 0x18 ) |
F_29 ( 3 , 0x18 ) ) ;
F_19 ( V_33 -> V_38 , V_71 ,
F_30 ( V_6 -> V_72 -> V_73 ) |
F_31 ( V_6 -> V_72 -> V_74 ) ) ;
F_19 ( V_33 -> V_38 , V_75 ,
F_32 ( 126 ) |
F_33 ( 68 ) |
F_34 ( 22 ) ) ;
F_19 ( V_33 -> V_38 , V_76 ,
F_35 ( V_6 -> V_77 -> V_73 ) |
F_36 ( V_6 -> V_77 -> V_74 ) ) ;
F_19 ( V_33 -> V_38 , V_78 ,
F_37 ( 0x10 ) |
F_38 ( V_6 -> V_79 ) ) ;
F_19 ( V_33 -> V_38 , V_80 ,
F_39 ( 1440 ) ) ;
F_19 ( V_33 -> V_38 , V_81 ,
V_82 ) ;
F_19 ( V_33 -> V_38 , V_83 ,
V_84 |
V_85 ) ;
F_19 ( V_33 -> V_38 , V_86 ,
F_40 ( V_6 -> V_87 -> V_88 ) |
F_41 ( V_6 -> V_87 -> line ) |
( V_6 -> V_87 -> V_89 ?
V_90 : 0 ) ) ;
F_19 ( V_33 -> V_38 , V_91 , 0 ) ;
F_42 ( V_37 -> V_92 , V_8 -> V_93 * 1000 ) ;
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
V_8 = F_46 ( V_5 -> V_94 ) ;
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
return V_95 ;
}
static void
F_50 ( struct V_4 * V_5 )
{
F_51 ( V_5 ) ;
}
static int F_52 ( struct V_96 * V_94 , struct V_96 * V_97 ,
void * V_98 )
{
struct V_99 * V_100 = F_53 ( V_94 ) ;
struct V_101 * V_102 = V_98 ;
struct V_34 * V_35 = V_102 -> V_103 ;
struct V_1 * V_33 ;
struct V_104 * V_105 ;
void T_1 * V_38 ;
int V_106 ;
V_33 = F_54 ( V_94 , sizeof( * V_33 ) , V_107 ) ;
if ( ! V_33 )
return - V_108 ;
V_33 -> V_35 = V_35 ;
F_55 ( V_94 , V_33 ) ;
V_105 = F_56 ( V_100 , V_109 , 0 ) ;
V_38 = F_57 ( V_94 , V_105 ) ;
if ( F_58 ( V_38 ) ) {
F_59 ( V_94 , L_7 ) ;
return F_60 ( V_38 ) ;
}
V_33 -> V_38 = F_61 ( V_94 , V_38 ,
& V_110 ) ;
if ( F_58 ( V_33 -> V_38 ) ) {
F_59 ( V_94 , L_8 ) ;
return F_60 ( V_33 -> V_38 ) ;
}
V_33 -> V_111 = F_62 ( V_94 , NULL ) ;
if ( F_58 ( V_33 -> V_111 ) ) {
F_59 ( V_94 , L_9 ) ;
return F_60 ( V_33 -> V_111 ) ;
}
V_106 = F_63 ( V_33 -> V_111 ) ;
if ( V_106 ) {
F_59 ( V_94 , L_10 ) ;
return V_106 ;
}
V_33 -> V_112 = F_64 ( V_94 , NULL ) ;
if ( F_58 ( V_33 -> V_112 ) ) {
F_59 ( V_94 , L_11 ) ;
V_106 = F_60 ( V_33 -> V_112 ) ;
goto V_113;
}
F_65 ( V_33 -> V_112 ) ;
F_66 ( & V_33 -> V_3 ,
& V_114 ) ;
V_106 = F_67 ( V_102 ,
& V_33 -> V_3 ,
& V_115 ,
V_116 ,
NULL ) ;
if ( V_106 ) {
F_59 ( V_94 , L_12 ) ;
goto V_117;
}
V_33 -> V_3 . V_118 = F_21 ( 0 ) ;
F_68 ( & V_33 -> V_5 ,
& V_119 ) ;
V_106 = F_69 ( V_102 , & V_33 -> V_5 ,
& V_120 ,
V_121 ) ;
if ( V_106 ) {
F_59 ( V_94 ,
L_13 ) ;
goto V_122;
}
V_33 -> V_5 . V_123 = true ;
F_70 ( & V_33 -> V_5 , & V_33 -> V_3 ) ;
return 0 ;
V_122:
F_44 ( & V_33 -> V_3 ) ;
V_117:
F_71 ( V_33 -> V_112 ) ;
V_113:
F_72 ( V_33 -> V_111 ) ;
return V_106 ;
}
static void F_73 ( struct V_96 * V_94 , struct V_96 * V_97 ,
void * V_98 )
{
struct V_1 * V_33 = F_74 ( V_94 ) ;
F_51 ( & V_33 -> V_5 ) ;
F_44 ( & V_33 -> V_3 ) ;
F_71 ( V_33 -> V_112 ) ;
}
static int F_75 ( struct V_99 * V_100 )
{
return F_76 ( & V_100 -> V_94 , & V_124 ) ;
}
static int F_77 ( struct V_99 * V_100 )
{
F_78 ( & V_100 -> V_94 , & V_124 ) ;
return 0 ;
}
