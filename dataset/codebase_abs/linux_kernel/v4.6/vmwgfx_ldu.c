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
V_16 -> V_30 , V_16 -> V_31 ) ;
}
if ( ! F_11 ( & V_10 -> V_3 ) ) {
V_12 = F_12 ( V_10 -> V_3 . V_32 , F_13 ( * V_12 ) , V_3 ) ;
V_16 = V_12 -> V_4 . V_6 . V_28 -> V_16 ;
F_10 ( V_8 , V_16 -> V_33 , V_16 -> V_34 , V_16 -> V_29 [ 0 ] ,
V_16 -> V_30 , V_16 -> V_31 ) ;
}
F_14 ( V_8 , V_35 ,
V_10 -> V_36 ? V_10 -> V_36 : 1 ) ;
V_17 = 0 ;
F_8 (entry, &lds->active, active) {
V_6 = & V_12 -> V_4 . V_6 ;
F_14 ( V_8 , V_37 , V_17 ) ;
F_14 ( V_8 , V_38 , ! V_17 ) ;
F_14 ( V_8 , V_39 , V_6 -> V_23 ) ;
F_14 ( V_8 , V_40 , V_6 -> V_26 ) ;
F_14 ( V_8 , V_41 , V_6 -> V_24 . V_25 ) ;
F_14 ( V_8 , V_42 , V_6 -> V_24 . V_27 ) ;
F_14 ( V_8 , V_37 , V_43 ) ;
V_17 ++ ;
}
F_15 ( V_17 != V_10 -> V_36 ) ;
V_10 -> V_44 = V_10 -> V_36 ;
F_8 (entry, &lds->active, active) {
V_14 = & V_12 -> V_4 ;
if ( ! V_14 -> V_45 )
continue;
V_18 = F_16 ( V_8 ,
V_14 -> V_45 ,
64 , 64 ,
V_14 -> V_46 ,
V_14 -> V_47 ) ;
if ( V_18 == 0 )
break;
F_17 ( L_1 ) ;
}
return 0 ;
}
static int F_18 ( struct V_7 * V_48 ,
struct V_1 * V_2 )
{
struct V_9 * V_49 = V_48 -> V_11 ;
if ( F_11 ( & V_2 -> V_3 ) )
return 0 ;
F_2 ( & V_2 -> V_3 ) ;
if ( -- ( V_49 -> V_36 ) == 0 ) {
F_15 ( ! V_49 -> V_16 ) ;
if ( V_49 -> V_16 -> V_50 )
V_49 -> V_16 -> V_50 ( V_49 -> V_16 ) ;
V_49 -> V_16 = NULL ;
}
return 0 ;
}
static int F_19 ( struct V_7 * V_48 ,
struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_9 * V_49 = V_48 -> V_11 ;
struct V_1 * V_12 ;
struct V_53 * V_54 ;
F_15 ( ! V_49 -> V_36 && V_49 -> V_16 ) ;
if ( V_52 != V_49 -> V_16 ) {
if ( V_49 -> V_16 && V_49 -> V_16 -> V_50 )
V_49 -> V_16 -> V_50 ( V_49 -> V_16 ) ;
if ( V_52 -> V_55 )
V_52 -> V_55 ( V_52 ) ;
V_49 -> V_16 = V_52 ;
}
if ( ! F_11 ( & V_2 -> V_3 ) )
return 0 ;
V_54 = & V_49 -> V_3 ;
F_8 (entry, &ld->active, active) {
if ( V_12 -> V_4 . V_56 > V_2 -> V_4 . V_56 )
break;
V_54 = & V_12 -> V_3 ;
}
F_20 ( & V_2 -> V_3 , V_54 ) ;
V_49 -> V_36 ++ ;
return 0 ;
}
static int F_21 ( struct V_57 * V_58 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_59 * V_60 ;
struct V_61 * V_24 ;
struct V_62 * V_63 ;
struct V_51 * V_52 ;
struct V_15 * V_16 ;
struct V_5 * V_6 ;
if ( ! V_58 )
return - V_64 ;
if ( ! V_58 -> V_6 )
return - V_64 ;
V_6 = V_58 -> V_6 ;
V_2 = F_6 ( V_6 ) ;
V_52 = V_58 -> V_16 ? F_22 ( V_58 -> V_16 ) : NULL ;
V_8 = V_48 ( V_6 -> V_65 ) ;
if ( V_58 -> V_66 > 1 ) {
F_17 ( L_2 ) ;
return - V_64 ;
}
if ( V_58 -> V_66 == 1 &&
V_58 -> V_67 [ 0 ] != & V_2 -> V_4 . V_60 ) {
F_17 ( L_3 ,
V_58 -> V_67 [ 0 ] , & V_2 -> V_4 . V_60 ) ;
return - V_64 ;
}
if ( V_8 -> V_11 -> V_16 && V_52 &&
! ( V_8 -> V_11 -> V_36 == 1 &&
! F_11 ( & V_2 -> V_3 ) ) &&
V_8 -> V_11 -> V_16 != V_52 ) {
F_17 ( L_4 ) ;
return - V_64 ;
}
V_60 = & V_2 -> V_4 . V_60 ;
V_63 = & V_2 -> V_4 . V_63 ;
if ( V_58 -> V_66 == 0 || ! V_58 -> V_24 || ! V_58 -> V_16 ) {
V_60 -> V_63 = NULL ;
V_63 -> V_6 = NULL ;
V_6 -> V_28 -> V_16 = NULL ;
V_6 -> V_68 = false ;
F_18 ( V_8 , V_2 ) ;
return F_7 ( V_8 ) ;
}
V_24 = V_58 -> V_24 ;
V_16 = V_58 -> V_16 ;
if ( V_58 -> V_23 + V_24 -> V_25 > V_16 -> V_33 ||
V_58 -> V_26 + V_24 -> V_27 > V_16 -> V_34 ) {
F_17 ( L_5 ) ;
return - V_64 ;
}
F_23 ( V_8 ) ;
V_6 -> V_28 -> V_16 = V_16 ;
V_63 -> V_6 = V_6 ;
V_60 -> V_63 = V_63 ;
V_6 -> V_23 = V_58 -> V_23 ;
V_6 -> V_26 = V_58 -> V_26 ;
V_6 -> V_24 = * V_24 ;
V_6 -> V_68 = true ;
V_2 -> V_4 . V_69 = V_58 -> V_23 ;
V_2 -> V_4 . V_70 = V_58 -> V_26 ;
F_19 ( V_8 , V_2 , V_52 ) ;
return F_7 ( V_8 ) ;
}
static void F_24 ( struct V_62 * V_63 )
{
F_1 ( F_25 ( V_63 ) ) ;
}
static void F_26 ( struct V_59 * V_60 )
{
F_1 ( F_27 ( V_60 ) ) ;
}
static int F_28 ( struct V_7 * V_8 , unsigned V_56 )
{
struct V_1 * V_2 ;
struct V_71 * V_65 = V_8 -> V_65 ;
struct V_59 * V_60 ;
struct V_62 * V_63 ;
struct V_5 * V_6 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_72 ) ;
if ( ! V_2 )
return - V_73 ;
V_2 -> V_4 . V_56 = V_56 ;
V_6 = & V_2 -> V_4 . V_6 ;
V_63 = & V_2 -> V_4 . V_63 ;
V_60 = & V_2 -> V_4 . V_60 ;
F_30 ( & V_2 -> V_3 ) ;
V_2 -> V_4 . V_74 = ( V_56 == 0 ) ;
V_2 -> V_4 . V_75 = V_8 -> V_76 ;
V_2 -> V_4 . V_77 = V_8 -> V_78 ;
V_2 -> V_4 . V_79 = NULL ;
V_2 -> V_4 . V_80 = true ;
F_31 ( V_65 , V_60 , & V_81 ,
V_82 ) ;
V_60 -> V_83 = F_32 ( V_60 , true ) ;
F_33 ( V_65 , V_63 , & V_84 ,
V_85 , NULL ) ;
F_34 ( V_60 , V_63 ) ;
V_63 -> V_86 = ( 1 << V_56 ) ;
V_63 -> V_87 = 0 ;
( void ) F_35 ( V_60 ) ;
F_36 ( V_65 , V_6 , & V_88 ) ;
F_37 ( V_6 , 256 ) ;
F_38 ( & V_60 -> V_4 ,
V_65 -> V_89 . V_90 ,
1 ) ;
F_38 ( & V_60 -> V_4 ,
V_8 -> V_91 , 1 ) ;
F_38 ( & V_60 -> V_4 ,
V_65 -> V_89 . V_92 , 0 ) ;
F_38 ( & V_60 -> V_4 ,
V_65 -> V_89 . V_93 , 0 ) ;
if ( V_8 -> V_94 )
F_38
( & V_60 -> V_4 ,
V_8 -> V_94 ,
1 ) ;
return 0 ;
}
int F_39 ( struct V_7 * V_8 )
{
struct V_71 * V_65 = V_8 -> V_65 ;
int V_17 , V_18 ;
if ( V_8 -> V_11 ) {
F_40 ( L_6 ) ;
return - V_64 ;
}
V_8 -> V_11 = F_41 ( sizeof( * V_8 -> V_11 ) , V_72 ) ;
if ( ! V_8 -> V_11 )
return - V_73 ;
F_30 ( & V_8 -> V_11 -> V_3 ) ;
V_8 -> V_11 -> V_36 = 0 ;
V_8 -> V_11 -> V_44 = 0 ;
V_8 -> V_11 -> V_16 = NULL ;
if ( V_8 -> V_19 & V_95 )
V_18 = F_42 ( V_65 , V_96 ) ;
else
V_18 = F_42 ( V_65 , 1 ) ;
if ( V_18 != 0 )
goto V_97;
V_18 = F_43 ( V_65 ) ;
if ( V_18 != 0 )
goto V_98;
F_44 ( V_8 , true ) ;
if ( V_8 -> V_19 & V_95 )
for ( V_17 = 0 ; V_17 < V_96 ; ++ V_17 )
F_28 ( V_8 , V_17 ) ;
else
F_28 ( V_8 , 0 ) ;
V_8 -> V_99 = V_100 ;
F_40 ( L_7 ) ;
return 0 ;
V_98:
F_45 ( V_65 ) ;
V_97:
F_4 ( V_8 -> V_11 ) ;
V_8 -> V_11 = NULL ;
return V_18 ;
}
int F_46 ( struct V_7 * V_8 )
{
struct V_71 * V_65 = V_8 -> V_65 ;
if ( ! V_8 -> V_11 )
return - V_101 ;
F_45 ( V_65 ) ;
F_15 ( ! F_11 ( & V_8 -> V_11 -> V_3 ) ) ;
F_4 ( V_8 -> V_11 ) ;
return 0 ;
}
int F_47 ( struct V_7 * V_8 ,
struct V_51 * V_102 ,
unsigned V_103 , unsigned V_104 ,
struct V_105 * V_106 ,
unsigned V_107 , int V_108 )
{
T_1 V_109 ;
int V_17 ;
struct {
T_2 V_110 ;
T_3 V_111 ;
} * V_112 ;
V_109 = sizeof( * V_112 ) * V_107 ;
V_112 = F_48 ( V_8 , V_109 ) ;
if ( F_49 ( V_112 == NULL ) ) {
F_17 ( L_8 ) ;
return - V_73 ;
}
memset ( V_112 , 0 , V_109 ) ;
for ( V_17 = 0 ; V_17 < V_107 ; V_17 ++ , V_106 += V_108 ) {
V_112 [ V_17 ] . V_110 = V_113 ;
V_112 [ V_17 ] . V_111 . V_23 = V_106 -> V_114 ;
V_112 [ V_17 ] . V_111 . V_26 = V_106 -> y1 ;
V_112 [ V_17 ] . V_111 . V_33 = V_106 -> V_115 - V_106 -> V_114 ;
V_112 [ V_17 ] . V_111 . V_34 = V_106 -> V_116 - V_106 -> y1 ;
}
F_50 ( V_8 , V_109 ) ;
return 0 ;
}
