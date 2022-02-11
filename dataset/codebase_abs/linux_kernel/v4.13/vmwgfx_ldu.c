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
static void F_21 ( struct V_5 * V_6 )
{
}
static void F_22 ( struct V_5 * V_6 )
{
}
static void F_23 ( struct V_5 * V_6 )
{
}
static void F_24 ( struct V_53 * V_54 )
{
F_1 ( F_25 ( V_54 ) ) ;
}
static void F_26 ( struct V_55 * V_56 )
{
F_1 ( F_27 ( V_56 ) ) ;
}
static void
F_28 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
}
static int
F_29 ( struct V_57 * V_58 ,
struct V_59 * V_61 )
{
return 0 ;
}
static void
F_30 ( struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_47 * V_48 ;
struct V_13 * V_14 ;
struct V_5 * V_6 = V_58 -> V_26 -> V_6 ? : V_60 -> V_6 ;
V_2 = F_6 ( V_6 ) ;
V_8 = V_44 ( V_58 -> V_62 ) ;
V_14 = V_58 -> V_26 -> V_14 ;
V_48 = ( V_14 ) ? F_31 ( V_14 ) : NULL ;
if ( V_48 )
F_17 ( V_8 , V_2 , V_48 ) ;
else
F_16 ( V_8 , V_2 ) ;
F_7 ( V_8 ) ;
}
static int F_32 ( struct V_7 * V_8 , unsigned V_52 )
{
struct V_1 * V_2 ;
struct V_63 * V_62 = V_8 -> V_62 ;
struct V_55 * V_56 ;
struct V_53 * V_54 ;
struct V_57 * V_25 , * V_64 ;
struct V_5 * V_6 ;
int V_65 ;
V_2 = F_33 ( sizeof( * V_2 ) , V_66 ) ;
if ( ! V_2 )
return - V_67 ;
V_2 -> V_4 . V_52 = V_52 ;
V_6 = & V_2 -> V_4 . V_6 ;
V_54 = & V_2 -> V_4 . V_54 ;
V_56 = & V_2 -> V_4 . V_56 ;
V_25 = & V_2 -> V_4 . V_25 ;
V_64 = & V_2 -> V_4 . V_64 ;
F_34 ( & V_2 -> V_3 ) ;
V_2 -> V_4 . V_68 = ( V_52 == 0 ) ;
V_2 -> V_4 . V_69 = V_8 -> V_70 ;
V_2 -> V_4 . V_71 = V_8 -> V_72 ;
V_2 -> V_4 . V_73 = NULL ;
V_2 -> V_4 . V_74 = true ;
F_35 ( V_25 ) ;
V_65 = F_36 ( V_62 , & V_2 -> V_4 . V_25 ,
0 , & V_75 ,
V_76 ,
F_37 ( V_76 ) ,
V_77 , NULL ) ;
if ( V_65 ) {
F_38 ( L_1 ) ;
goto V_78;
}
F_39 ( V_25 , & V_79 ) ;
F_35 ( V_64 ) ;
V_65 = F_36 ( V_62 , & V_2 -> V_4 . V_64 ,
0 , & V_80 ,
V_81 ,
F_37 ( V_81 ) ,
V_82 , NULL ) ;
if ( V_65 ) {
F_38 ( L_2 ) ;
F_40 ( & V_2 -> V_4 . V_25 ) ;
goto V_78;
}
F_39 ( V_64 , & V_83 ) ;
F_41 ( V_56 ) ;
V_65 = F_42 ( V_62 , V_56 , & V_84 ,
V_85 ) ;
if ( V_65 ) {
F_38 ( L_3 ) ;
goto V_78;
}
F_43 ( V_56 , & V_86 ) ;
V_56 -> V_87 = F_44 ( V_56 , true ) ;
F_45 ( V_56 -> V_26 ) -> V_74 = true ;
V_65 = F_46 ( V_62 , V_54 , & V_88 ,
V_89 , NULL ) ;
if ( V_65 ) {
F_38 ( L_4 ) ;
goto V_90;
}
( void ) F_47 ( V_56 , V_54 ) ;
V_54 -> V_91 = ( 1 << V_52 ) ;
V_54 -> V_92 = 0 ;
V_65 = F_48 ( V_56 ) ;
if ( V_65 ) {
F_38 ( L_5 ) ;
goto V_93;
}
F_49 ( V_6 ) ;
V_65 = F_50 ( V_62 , V_6 , & V_2 -> V_4 . V_25 ,
& V_2 -> V_4 . V_64 ,
& V_94 , NULL ) ;
if ( V_65 ) {
F_38 ( L_6 ) ;
goto V_95;
}
F_51 ( V_6 , & V_96 ) ;
F_52 ( V_6 , 256 ) ;
F_53 ( & V_56 -> V_4 ,
V_8 -> V_97 , 1 ) ;
F_53 ( & V_56 -> V_4 ,
V_62 -> V_98 . V_99 , 0 ) ;
F_53 ( & V_56 -> V_4 ,
V_62 -> V_98 . V_100 , 0 ) ;
if ( V_8 -> V_101 )
F_53
( & V_56 -> V_4 ,
V_8 -> V_101 ,
1 ) ;
return 0 ;
V_95:
F_54 ( V_56 ) ;
V_93:
F_55 ( V_54 ) ;
V_90:
F_56 ( V_56 ) ;
V_78:
F_4 ( V_2 ) ;
return V_65 ;
}
int F_57 ( struct V_7 * V_8 )
{
struct V_63 * V_62 = V_8 -> V_62 ;
int V_15 , V_65 ;
if ( V_8 -> V_11 ) {
F_58 ( L_7 ) ;
return - V_102 ;
}
V_8 -> V_11 = F_59 ( sizeof( * V_8 -> V_11 ) , V_66 ) ;
if ( ! V_8 -> V_11 )
return - V_67 ;
F_34 ( & V_8 -> V_11 -> V_3 ) ;
V_8 -> V_11 -> V_35 = 0 ;
V_8 -> V_11 -> V_43 = 0 ;
V_8 -> V_11 -> V_14 = NULL ;
if ( V_8 -> V_16 & V_103 )
V_65 = F_60 ( V_62 , V_104 ) ;
else
V_65 = F_60 ( V_62 , 1 ) ;
if ( V_65 != 0 )
goto V_78;
F_61 ( V_8 , true ) ;
if ( V_8 -> V_16 & V_103 )
for ( V_15 = 0 ; V_15 < V_104 ; ++ V_15 )
F_32 ( V_8 , V_15 ) ;
else
F_32 ( V_8 , 0 ) ;
V_8 -> V_105 = V_106 ;
F_58 ( L_8 ) ;
return 0 ;
V_78:
F_4 ( V_8 -> V_11 ) ;
V_8 -> V_11 = NULL ;
return V_65 ;
}
int F_62 ( struct V_7 * V_8 )
{
struct V_63 * V_62 = V_8 -> V_62 ;
if ( ! V_8 -> V_11 )
return - V_107 ;
F_63 ( V_62 ) ;
F_15 ( ! F_11 ( & V_8 -> V_11 -> V_3 ) ) ;
F_4 ( V_8 -> V_11 ) ;
return 0 ;
}
int F_64 ( struct V_7 * V_8 ,
struct V_47 * V_108 ,
unsigned V_109 , unsigned V_110 ,
struct V_111 * V_112 ,
unsigned V_113 , int V_114 )
{
T_1 V_115 ;
int V_15 ;
struct {
T_2 V_116 ;
T_3 V_117 ;
} * V_118 ;
V_115 = sizeof( * V_118 ) * V_113 ;
V_118 = F_65 ( V_8 , V_115 ) ;
if ( F_66 ( V_118 == NULL ) ) {
F_38 ( L_9 ) ;
return - V_67 ;
}
memset ( V_118 , 0 , V_115 ) ;
for ( V_15 = 0 ; V_15 < V_113 ; V_15 ++ , V_112 += V_114 ) {
V_118 [ V_15 ] . V_116 = V_119 ;
V_118 [ V_15 ] . V_117 . V_20 = V_112 -> V_120 ;
V_118 [ V_15 ] . V_117 . V_23 = V_112 -> y1 ;
V_118 [ V_15 ] . V_117 . V_32 = V_112 -> V_121 - V_112 -> V_120 ;
V_118 [ V_15 ] . V_117 . V_33 = V_112 -> V_122 - V_112 -> y1 ;
}
F_67 ( V_8 , V_115 ) ;
return 0 ;
}
