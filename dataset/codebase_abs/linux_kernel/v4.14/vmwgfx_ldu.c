static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( & V_2 -> V_4 ) ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_5 * V_6 )
{
F_1 ( F_6 ( V_6 ) ) ;
}
static int F_7 ( struct V_7 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_11 ;
struct V_1 * V_12 ;
struct V_13 * V_14 = NULL ;
struct V_5 * V_6 = NULL ;
int V_15 = 0 ;
if ( ! ( V_8 -> V_16 & V_17 ) ) {
int V_18 = 0 , V_19 = 0 ;
F_8 (entry, &lds->active, active) {
V_6 = & V_12 -> V_4 . V_6 ;
V_18 = F_9 ( V_18 , V_6 -> V_20 + V_6 -> V_21 . V_22 ) ;
V_19 = F_9 ( V_19 , V_6 -> V_23 + V_6 -> V_21 . V_24 ) ;
V_15 ++ ;
}
if ( V_6 == NULL )
return 0 ;
V_14 = V_12 -> V_4 . V_6 . V_25 -> V_26 -> V_14 ;
return F_10 ( V_8 , V_18 , V_19 , V_14 -> V_27 [ 0 ] ,
V_14 -> V_28 -> V_29 [ 0 ] * 8 ,
V_14 -> V_28 -> V_30 ) ;
}
if ( ! F_11 ( & V_10 -> V_3 ) ) {
V_12 = F_12 ( V_10 -> V_3 . V_31 , F_13 ( * V_12 ) , V_3 ) ;
V_14 = V_12 -> V_4 . V_6 . V_25 -> V_26 -> V_14 ;
F_10 ( V_8 , V_14 -> V_32 , V_14 -> V_33 , V_14 -> V_27 [ 0 ] ,
V_14 -> V_28 -> V_29 [ 0 ] * 8 , V_14 -> V_28 -> V_30 ) ;
}
F_14 ( V_8 , V_34 ,
V_10 -> V_35 ? V_10 -> V_35 : 1 ) ;
V_15 = 0 ;
F_8 (entry, &lds->active, active) {
V_6 = & V_12 -> V_4 . V_6 ;
F_14 ( V_8 , V_36 , V_15 ) ;
F_14 ( V_8 , V_37 , ! V_15 ) ;
F_14 ( V_8 , V_38 , V_6 -> V_20 ) ;
F_14 ( V_8 , V_39 , V_6 -> V_23 ) ;
F_14 ( V_8 , V_40 , V_6 -> V_21 . V_22 ) ;
F_14 ( V_8 , V_41 , V_6 -> V_21 . V_24 ) ;
F_14 ( V_8 , V_36 , V_42 ) ;
V_15 ++ ;
}
F_15 ( V_15 != V_10 -> V_35 ) ;
V_10 -> V_43 = V_10 -> V_35 ;
return 0 ;
}
static int F_16 ( struct V_7 * V_44 ,
struct V_1 * V_2 )
{
struct V_9 * V_45 = V_44 -> V_11 ;
if ( F_11 ( & V_2 -> V_3 ) )
return 0 ;
F_2 ( & V_2 -> V_3 ) ;
if ( -- ( V_45 -> V_35 ) == 0 ) {
F_15 ( ! V_45 -> V_14 ) ;
if ( V_45 -> V_14 -> V_46 )
V_45 -> V_14 -> V_46 ( V_45 -> V_14 ) ;
V_45 -> V_14 = NULL ;
}
return 0 ;
}
static int F_17 ( struct V_7 * V_44 ,
struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_9 * V_45 = V_44 -> V_11 ;
struct V_1 * V_12 ;
struct V_49 * V_50 ;
F_15 ( ! V_45 -> V_35 && V_45 -> V_14 ) ;
if ( V_48 != V_45 -> V_14 ) {
if ( V_45 -> V_14 && V_45 -> V_14 -> V_46 )
V_45 -> V_14 -> V_46 ( V_45 -> V_14 ) ;
F_18 ( V_44 ) ;
if ( V_48 -> V_51 )
V_48 -> V_51 ( V_48 ) ;
V_45 -> V_14 = V_48 ;
}
if ( ! F_11 ( & V_2 -> V_3 ) )
return 0 ;
V_50 = & V_45 -> V_3 ;
F_8 (entry, &ld->active, active) {
if ( V_12 -> V_4 . V_52 > V_2 -> V_4 . V_52 )
break;
V_50 = & V_12 -> V_3 ;
}
F_19 ( & V_2 -> V_3 , V_50 ) ;
V_45 -> V_35 ++ ;
return 0 ;
}
static void F_20 ( struct V_5 * V_6 )
{
}
static void F_21 ( struct V_5 * V_6 ,
struct V_53 * V_54 )
{
}
static void F_22 ( struct V_5 * V_6 ,
struct V_53 * V_54 )
{
}
static void F_23 ( struct V_55 * V_56 )
{
F_1 ( F_24 ( V_56 ) ) ;
}
static void F_25 ( struct V_57 * V_58 )
{
F_1 ( F_26 ( V_58 ) ) ;
}
static void
F_27 ( struct V_59 * V_60 ,
struct V_61 * V_54 )
{
}
static int
F_28 ( struct V_59 * V_60 ,
struct V_61 * V_62 )
{
return 0 ;
}
static void
F_29 ( struct V_59 * V_60 ,
struct V_61 * V_54 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_47 * V_48 ;
struct V_13 * V_14 ;
struct V_5 * V_6 = V_60 -> V_26 -> V_6 ? : V_54 -> V_6 ;
V_2 = F_6 ( V_6 ) ;
V_8 = V_44 ( V_60 -> V_63 ) ;
V_14 = V_60 -> V_26 -> V_14 ;
V_48 = ( V_14 ) ? F_30 ( V_14 ) : NULL ;
if ( V_48 )
F_17 ( V_8 , V_2 , V_48 ) ;
else
F_16 ( V_8 , V_2 ) ;
F_7 ( V_8 ) ;
}
static int F_31 ( struct V_7 * V_8 , unsigned V_52 )
{
struct V_1 * V_2 ;
struct V_64 * V_63 = V_8 -> V_63 ;
struct V_57 * V_58 ;
struct V_55 * V_56 ;
struct V_59 * V_25 , * V_65 ;
struct V_5 * V_6 ;
int V_66 ;
V_2 = F_32 ( sizeof( * V_2 ) , V_67 ) ;
if ( ! V_2 )
return - V_68 ;
V_2 -> V_4 . V_52 = V_52 ;
V_6 = & V_2 -> V_4 . V_6 ;
V_56 = & V_2 -> V_4 . V_56 ;
V_58 = & V_2 -> V_4 . V_58 ;
V_25 = & V_2 -> V_4 . V_25 ;
V_65 = & V_2 -> V_4 . V_65 ;
F_33 ( & V_2 -> V_3 ) ;
V_2 -> V_4 . V_69 = ( V_52 == 0 ) ;
V_2 -> V_4 . V_70 = V_8 -> V_71 ;
V_2 -> V_4 . V_72 = V_8 -> V_73 ;
V_2 -> V_4 . V_74 = NULL ;
V_2 -> V_4 . V_75 = true ;
F_34 ( V_25 ) ;
V_66 = F_35 ( V_63 , & V_2 -> V_4 . V_25 ,
0 , & V_76 ,
V_77 ,
F_36 ( V_77 ) ,
NULL , V_78 , NULL ) ;
if ( V_66 ) {
F_37 ( L_1 ) ;
goto V_79;
}
F_38 ( V_25 , & V_80 ) ;
F_34 ( V_65 ) ;
V_66 = F_35 ( V_63 , & V_2 -> V_4 . V_65 ,
0 , & V_81 ,
V_82 ,
F_36 ( V_82 ) ,
NULL , V_83 , NULL ) ;
if ( V_66 ) {
F_37 ( L_2 ) ;
F_39 ( & V_2 -> V_4 . V_25 ) ;
goto V_79;
}
F_38 ( V_65 , & V_84 ) ;
F_40 ( V_58 ) ;
V_66 = F_41 ( V_63 , V_58 , & V_85 ,
V_86 ) ;
if ( V_66 ) {
F_37 ( L_3 ) ;
goto V_79;
}
F_42 ( V_58 , & V_87 ) ;
V_58 -> V_88 = F_43 ( V_58 , true ) ;
F_44 ( V_58 -> V_26 ) -> V_75 = true ;
V_66 = F_45 ( V_63 , V_56 , & V_89 ,
V_90 , NULL ) ;
if ( V_66 ) {
F_37 ( L_4 ) ;
goto V_91;
}
( void ) F_46 ( V_58 , V_56 ) ;
V_56 -> V_92 = ( 1 << V_52 ) ;
V_56 -> V_93 = 0 ;
V_66 = F_47 ( V_58 ) ;
if ( V_66 ) {
F_37 ( L_5 ) ;
goto V_94;
}
F_48 ( V_6 ) ;
V_66 = F_49 ( V_63 , V_6 , & V_2 -> V_4 . V_25 ,
& V_2 -> V_4 . V_65 ,
& V_95 , NULL ) ;
if ( V_66 ) {
F_37 ( L_6 ) ;
goto V_96;
}
F_50 ( V_6 , & V_97 ) ;
F_51 ( V_6 , 256 ) ;
F_52 ( & V_58 -> V_4 ,
V_8 -> V_98 , 1 ) ;
F_52 ( & V_58 -> V_4 ,
V_63 -> V_99 . V_100 , 0 ) ;
F_52 ( & V_58 -> V_4 ,
V_63 -> V_99 . V_101 , 0 ) ;
if ( V_8 -> V_102 )
F_52
( & V_58 -> V_4 ,
V_8 -> V_102 ,
1 ) ;
return 0 ;
V_96:
F_53 ( V_58 ) ;
V_94:
F_54 ( V_56 ) ;
V_91:
F_55 ( V_58 ) ;
V_79:
F_4 ( V_2 ) ;
return V_66 ;
}
int F_56 ( struct V_7 * V_8 )
{
struct V_64 * V_63 = V_8 -> V_63 ;
int V_15 , V_66 ;
if ( V_8 -> V_11 ) {
F_57 ( L_7 ) ;
return - V_103 ;
}
V_8 -> V_11 = F_58 ( sizeof( * V_8 -> V_11 ) , V_67 ) ;
if ( ! V_8 -> V_11 )
return - V_68 ;
F_33 ( & V_8 -> V_11 -> V_3 ) ;
V_8 -> V_11 -> V_35 = 0 ;
V_8 -> V_11 -> V_43 = 0 ;
V_8 -> V_11 -> V_14 = NULL ;
if ( V_8 -> V_16 & V_104 )
V_66 = F_59 ( V_63 , V_105 ) ;
else
V_66 = F_59 ( V_63 , 1 ) ;
if ( V_66 != 0 )
goto V_79;
F_60 ( V_8 , true ) ;
if ( V_8 -> V_16 & V_104 )
for ( V_15 = 0 ; V_15 < V_105 ; ++ V_15 )
F_31 ( V_8 , V_15 ) ;
else
F_31 ( V_8 , 0 ) ;
V_8 -> V_106 = V_107 ;
F_57 ( L_8 ) ;
return 0 ;
V_79:
F_4 ( V_8 -> V_11 ) ;
V_8 -> V_11 = NULL ;
return V_66 ;
}
int F_61 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_11 )
return - V_108 ;
F_15 ( ! F_11 ( & V_8 -> V_11 -> V_3 ) ) ;
F_4 ( V_8 -> V_11 ) ;
return 0 ;
}
int F_62 ( struct V_7 * V_8 ,
struct V_47 * V_109 ,
unsigned V_110 , unsigned V_111 ,
struct V_112 * V_113 ,
unsigned V_114 , int V_115 )
{
T_1 V_116 ;
int V_15 ;
struct {
T_2 V_117 ;
T_3 V_118 ;
} * V_119 ;
V_116 = sizeof( * V_119 ) * V_114 ;
V_119 = F_63 ( V_8 , V_116 ) ;
if ( F_64 ( V_119 == NULL ) ) {
F_37 ( L_9 ) ;
return - V_68 ;
}
memset ( V_119 , 0 , V_116 ) ;
for ( V_15 = 0 ; V_15 < V_114 ; V_15 ++ , V_113 += V_115 ) {
V_119 [ V_15 ] . V_117 = V_120 ;
V_119 [ V_15 ] . V_118 . V_20 = V_113 -> V_121 ;
V_119 [ V_15 ] . V_118 . V_23 = V_113 -> y1 ;
V_119 [ V_15 ] . V_118 . V_32 = V_113 -> V_122 - V_113 -> V_121 ;
V_119 [ V_15 ] . V_118 . V_33 = V_113 -> V_123 - V_113 -> y1 ;
}
F_65 ( V_8 , V_116 ) ;
return 0 ;
}
