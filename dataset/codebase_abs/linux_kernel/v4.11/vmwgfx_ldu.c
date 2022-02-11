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
struct V_15 * V_16 = NULL ;
struct V_5 * V_6 = NULL ;
int V_17 = 0 , V_18 ;
if ( ! ( V_8 -> V_19 & V_20 ) ) {
int V_21 = 0 , V_22 = 0 ;
F_8 (entry, &lds->active, active) {
V_6 = & V_12 -> V_4 . V_6 ;
V_21 = F_9 ( V_21 , V_6 -> V_23 + V_6 -> V_24 . V_25 ) ;
V_22 = F_9 ( V_22 , V_6 -> V_26 + V_6 -> V_24 . V_27 ) ;
V_17 ++ ;
}
if ( V_6 == NULL )
return 0 ;
V_16 = V_12 -> V_4 . V_6 . V_28 -> V_16 ;
return F_10 ( V_8 , V_21 , V_22 , V_16 -> V_29 [ 0 ] ,
V_16 -> V_30 -> V_31 [ 0 ] * 8 ,
V_16 -> V_30 -> V_32 ) ;
}
if ( ! F_11 ( & V_10 -> V_3 ) ) {
V_12 = F_12 ( V_10 -> V_3 . V_33 , F_13 ( * V_12 ) , V_3 ) ;
V_16 = V_12 -> V_4 . V_6 . V_28 -> V_16 ;
F_10 ( V_8 , V_16 -> V_34 , V_16 -> V_35 , V_16 -> V_29 [ 0 ] ,
V_16 -> V_30 -> V_31 [ 0 ] * 8 , V_16 -> V_30 -> V_32 ) ;
}
F_14 ( V_8 , V_36 ,
V_10 -> V_37 ? V_10 -> V_37 : 1 ) ;
V_17 = 0 ;
F_8 (entry, &lds->active, active) {
V_6 = & V_12 -> V_4 . V_6 ;
F_14 ( V_8 , V_38 , V_17 ) ;
F_14 ( V_8 , V_39 , ! V_17 ) ;
F_14 ( V_8 , V_40 , V_6 -> V_23 ) ;
F_14 ( V_8 , V_41 , V_6 -> V_26 ) ;
F_14 ( V_8 , V_42 , V_6 -> V_24 . V_25 ) ;
F_14 ( V_8 , V_43 , V_6 -> V_24 . V_27 ) ;
F_14 ( V_8 , V_38 , V_44 ) ;
V_17 ++ ;
}
F_15 ( V_17 != V_10 -> V_37 ) ;
V_10 -> V_45 = V_10 -> V_37 ;
F_8 (entry, &lds->active, active) {
V_14 = & V_12 -> V_4 ;
if ( ! V_14 -> V_46 )
continue;
V_18 = F_16 ( V_8 ,
V_14 -> V_46 ,
64 , 64 ,
V_14 -> V_47 ,
V_14 -> V_48 ) ;
if ( V_18 == 0 )
break;
F_17 ( L_1 ) ;
}
return 0 ;
}
static int F_18 ( struct V_7 * V_49 ,
struct V_1 * V_2 )
{
struct V_9 * V_50 = V_49 -> V_11 ;
if ( F_11 ( & V_2 -> V_3 ) )
return 0 ;
F_2 ( & V_2 -> V_3 ) ;
if ( -- ( V_50 -> V_37 ) == 0 ) {
F_15 ( ! V_50 -> V_16 ) ;
if ( V_50 -> V_16 -> V_51 )
V_50 -> V_16 -> V_51 ( V_50 -> V_16 ) ;
V_50 -> V_16 = NULL ;
}
return 0 ;
}
static int F_19 ( struct V_7 * V_49 ,
struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_9 * V_50 = V_49 -> V_11 ;
struct V_1 * V_12 ;
struct V_54 * V_55 ;
F_15 ( ! V_50 -> V_37 && V_50 -> V_16 ) ;
if ( V_53 != V_50 -> V_16 ) {
if ( V_50 -> V_16 && V_50 -> V_16 -> V_51 )
V_50 -> V_16 -> V_51 ( V_50 -> V_16 ) ;
if ( V_53 -> V_56 )
V_53 -> V_56 ( V_53 ) ;
V_50 -> V_16 = V_53 ;
}
if ( ! F_11 ( & V_2 -> V_3 ) )
return 0 ;
V_55 = & V_50 -> V_3 ;
F_8 (entry, &ld->active, active) {
if ( V_12 -> V_4 . V_57 > V_2 -> V_4 . V_57 )
break;
V_55 = & V_12 -> V_3 ;
}
F_20 ( & V_2 -> V_3 , V_55 ) ;
V_50 -> V_37 ++ ;
return 0 ;
}
static int F_21 ( struct V_58 * V_59 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_60 * V_61 ;
struct V_62 * V_24 ;
struct V_63 * V_64 ;
struct V_52 * V_53 ;
struct V_15 * V_16 ;
struct V_5 * V_6 ;
if ( ! V_59 )
return - V_65 ;
if ( ! V_59 -> V_6 )
return - V_65 ;
V_6 = V_59 -> V_6 ;
V_2 = F_6 ( V_6 ) ;
V_53 = V_59 -> V_16 ? F_22 ( V_59 -> V_16 ) : NULL ;
V_8 = V_49 ( V_6 -> V_66 ) ;
if ( V_59 -> V_67 > 1 ) {
F_17 ( L_2 ) ;
return - V_65 ;
}
if ( V_59 -> V_67 == 1 &&
V_59 -> V_68 [ 0 ] != & V_2 -> V_4 . V_61 ) {
F_17 ( L_3 ,
V_59 -> V_68 [ 0 ] , & V_2 -> V_4 . V_61 ) ;
return - V_65 ;
}
if ( V_8 -> V_11 -> V_16 && V_53 &&
! ( V_8 -> V_11 -> V_37 == 1 &&
! F_11 ( & V_2 -> V_3 ) ) &&
V_8 -> V_11 -> V_16 != V_53 ) {
F_17 ( L_4 ) ;
return - V_65 ;
}
V_61 = & V_2 -> V_4 . V_61 ;
V_64 = & V_2 -> V_4 . V_64 ;
if ( V_59 -> V_67 == 0 || ! V_59 -> V_24 || ! V_59 -> V_16 ) {
V_61 -> V_64 = NULL ;
V_64 -> V_6 = NULL ;
V_6 -> V_28 -> V_16 = NULL ;
V_6 -> V_69 = false ;
F_18 ( V_8 , V_2 ) ;
return F_7 ( V_8 ) ;
}
V_24 = V_59 -> V_24 ;
V_16 = V_59 -> V_16 ;
if ( V_59 -> V_23 + V_24 -> V_25 > V_16 -> V_34 ||
V_59 -> V_26 + V_24 -> V_27 > V_16 -> V_35 ) {
F_17 ( L_5 ) ;
return - V_65 ;
}
F_23 ( V_8 ) ;
V_6 -> V_28 -> V_16 = V_16 ;
V_64 -> V_6 = V_6 ;
V_61 -> V_64 = V_64 ;
V_6 -> V_23 = V_59 -> V_23 ;
V_6 -> V_26 = V_59 -> V_26 ;
V_6 -> V_24 = * V_24 ;
V_6 -> V_69 = true ;
V_2 -> V_4 . V_70 = V_59 -> V_23 ;
V_2 -> V_4 . V_71 = V_59 -> V_26 ;
F_19 ( V_8 , V_2 , V_53 ) ;
return F_7 ( V_8 ) ;
}
static void F_24 ( struct V_63 * V_64 )
{
F_1 ( F_25 ( V_64 ) ) ;
}
static void F_26 ( struct V_60 * V_61 )
{
F_1 ( F_27 ( V_61 ) ) ;
}
static int F_28 ( struct V_7 * V_8 , unsigned V_57 )
{
struct V_1 * V_2 ;
struct V_72 * V_66 = V_8 -> V_66 ;
struct V_60 * V_61 ;
struct V_63 * V_64 ;
struct V_5 * V_6 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_73 ) ;
if ( ! V_2 )
return - V_74 ;
V_2 -> V_4 . V_57 = V_57 ;
V_6 = & V_2 -> V_4 . V_6 ;
V_64 = & V_2 -> V_4 . V_64 ;
V_61 = & V_2 -> V_4 . V_61 ;
F_30 ( & V_2 -> V_3 ) ;
V_2 -> V_4 . V_75 = ( V_57 == 0 ) ;
V_2 -> V_4 . V_76 = V_8 -> V_77 ;
V_2 -> V_4 . V_78 = V_8 -> V_79 ;
V_2 -> V_4 . V_80 = NULL ;
V_2 -> V_4 . V_81 = true ;
F_31 ( V_66 , V_61 , & V_82 ,
V_83 ) ;
V_61 -> V_84 = F_32 ( V_61 , true ) ;
F_33 ( V_66 , V_64 , & V_85 ,
V_86 , NULL ) ;
F_34 ( V_61 , V_64 ) ;
V_64 -> V_87 = ( 1 << V_57 ) ;
V_64 -> V_88 = 0 ;
( void ) F_35 ( V_61 ) ;
F_36 ( V_66 , V_6 , & V_89 ) ;
F_37 ( V_6 , 256 ) ;
F_38 ( & V_61 -> V_4 ,
V_8 -> V_90 , 1 ) ;
F_38 ( & V_61 -> V_4 ,
V_66 -> V_91 . V_92 , 0 ) ;
F_38 ( & V_61 -> V_4 ,
V_66 -> V_91 . V_93 , 0 ) ;
if ( V_8 -> V_94 )
F_38
( & V_61 -> V_4 ,
V_8 -> V_94 ,
1 ) ;
return 0 ;
}
int F_39 ( struct V_7 * V_8 )
{
struct V_72 * V_66 = V_8 -> V_66 ;
int V_17 , V_18 ;
if ( V_8 -> V_11 ) {
F_40 ( L_6 ) ;
return - V_65 ;
}
V_8 -> V_11 = F_41 ( sizeof( * V_8 -> V_11 ) , V_73 ) ;
if ( ! V_8 -> V_11 )
return - V_74 ;
F_30 ( & V_8 -> V_11 -> V_3 ) ;
V_8 -> V_11 -> V_37 = 0 ;
V_8 -> V_11 -> V_45 = 0 ;
V_8 -> V_11 -> V_16 = NULL ;
if ( V_8 -> V_19 & V_95 )
V_18 = F_42 ( V_66 , V_96 ) ;
else
V_18 = F_42 ( V_66 , 1 ) ;
if ( V_18 != 0 )
goto V_97;
F_43 ( V_8 , true ) ;
if ( V_8 -> V_19 & V_95 )
for ( V_17 = 0 ; V_17 < V_96 ; ++ V_17 )
F_28 ( V_8 , V_17 ) ;
else
F_28 ( V_8 , 0 ) ;
V_8 -> V_98 = V_99 ;
F_40 ( L_7 ) ;
return 0 ;
V_97:
F_4 ( V_8 -> V_11 ) ;
V_8 -> V_11 = NULL ;
return V_18 ;
}
int F_44 ( struct V_7 * V_8 )
{
struct V_72 * V_66 = V_8 -> V_66 ;
if ( ! V_8 -> V_11 )
return - V_100 ;
F_45 ( V_66 ) ;
F_15 ( ! F_11 ( & V_8 -> V_11 -> V_3 ) ) ;
F_4 ( V_8 -> V_11 ) ;
return 0 ;
}
int F_46 ( struct V_7 * V_8 ,
struct V_52 * V_101 ,
unsigned V_102 , unsigned V_103 ,
struct V_104 * V_105 ,
unsigned V_106 , int V_107 )
{
T_1 V_108 ;
int V_17 ;
struct {
T_2 V_109 ;
T_3 V_110 ;
} * V_111 ;
V_108 = sizeof( * V_111 ) * V_106 ;
V_111 = F_47 ( V_8 , V_108 ) ;
if ( F_48 ( V_111 == NULL ) ) {
F_17 ( L_8 ) ;
return - V_74 ;
}
memset ( V_111 , 0 , V_108 ) ;
for ( V_17 = 0 ; V_17 < V_106 ; V_17 ++ , V_105 += V_107 ) {
V_111 [ V_17 ] . V_109 = V_112 ;
V_111 [ V_17 ] . V_110 . V_23 = V_105 -> V_113 ;
V_111 [ V_17 ] . V_110 . V_26 = V_105 -> y1 ;
V_111 [ V_17 ] . V_110 . V_34 = V_105 -> V_114 - V_105 -> V_113 ;
V_111 [ V_17 ] . V_110 . V_35 = V_105 -> V_115 - V_105 -> y1 ;
}
F_49 ( V_8 , V_108 ) ;
return 0 ;
}
