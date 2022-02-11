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
V_16 = V_12 -> V_4 . V_6 . V_16 ;
return F_10 ( V_8 , V_21 , V_22 , V_16 -> V_28 [ 0 ] ,
V_16 -> V_29 , V_16 -> V_30 ) ;
}
if ( ! F_11 ( & V_10 -> V_3 ) ) {
V_12 = F_12 ( V_10 -> V_3 . V_31 , F_13 ( * V_12 ) , V_3 ) ;
V_16 = V_12 -> V_4 . V_6 . V_16 ;
F_10 ( V_8 , V_16 -> V_32 , V_16 -> V_33 , V_16 -> V_28 [ 0 ] ,
V_16 -> V_29 , V_16 -> V_30 ) ;
}
F_14 ( V_8 , V_34 ,
V_10 -> V_35 ? V_10 -> V_35 : 1 ) ;
V_17 = 0 ;
F_8 (entry, &lds->active, active) {
V_6 = & V_12 -> V_4 . V_6 ;
F_14 ( V_8 , V_36 , V_17 ) ;
F_14 ( V_8 , V_37 , ! V_17 ) ;
F_14 ( V_8 , V_38 , V_6 -> V_23 ) ;
F_14 ( V_8 , V_39 , V_6 -> V_26 ) ;
F_14 ( V_8 , V_40 , V_6 -> V_24 . V_25 ) ;
F_14 ( V_8 , V_41 , V_6 -> V_24 . V_27 ) ;
F_14 ( V_8 , V_36 , V_42 ) ;
V_17 ++ ;
}
F_15 ( V_17 != V_10 -> V_35 ) ;
V_10 -> V_43 = V_10 -> V_35 ;
F_8 (entry, &lds->active, active) {
V_14 = & V_12 -> V_4 ;
if ( ! V_14 -> V_44 )
continue;
V_18 = F_16 ( V_8 ,
V_14 -> V_44 ,
64 , 64 ,
V_14 -> V_45 ,
V_14 -> V_46 ) ;
if ( V_18 == 0 )
break;
F_17 ( L_1 ) ;
}
return 0 ;
}
static int F_18 ( struct V_7 * V_47 ,
struct V_1 * V_2 )
{
struct V_9 * V_48 = V_47 -> V_11 ;
if ( F_11 ( & V_2 -> V_3 ) )
return 0 ;
F_2 ( & V_2 -> V_3 ) ;
if ( -- ( V_48 -> V_35 ) == 0 ) {
F_15 ( ! V_48 -> V_16 ) ;
if ( V_48 -> V_16 -> V_49 )
V_48 -> V_16 -> V_49 ( V_48 -> V_16 ) ;
V_48 -> V_16 = NULL ;
}
return 0 ;
}
static int F_19 ( struct V_7 * V_47 ,
struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_9 * V_48 = V_47 -> V_11 ;
struct V_1 * V_12 ;
struct V_52 * V_53 ;
F_15 ( ! V_48 -> V_35 && V_48 -> V_16 ) ;
if ( V_51 != V_48 -> V_16 ) {
if ( V_48 -> V_16 && V_48 -> V_16 -> V_49 )
V_48 -> V_16 -> V_49 ( V_48 -> V_16 ) ;
if ( V_51 -> V_54 )
V_51 -> V_54 ( V_51 ) ;
V_48 -> V_16 = V_51 ;
}
if ( ! F_11 ( & V_2 -> V_3 ) )
return 0 ;
V_53 = & V_48 -> V_3 ;
F_8 (entry, &ld->active, active) {
if ( V_12 -> V_4 . V_55 > V_2 -> V_4 . V_55 )
break;
V_53 = & V_12 -> V_3 ;
}
F_20 ( & V_2 -> V_3 , V_53 ) ;
V_48 -> V_35 ++ ;
return 0 ;
}
static int F_21 ( struct V_56 * V_57 )
{
struct V_7 * V_8 ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
struct V_60 * V_24 ;
struct V_61 * V_62 ;
struct V_50 * V_51 ;
struct V_15 * V_16 ;
struct V_5 * V_6 ;
if ( ! V_57 )
return - V_63 ;
if ( ! V_57 -> V_6 )
return - V_63 ;
V_6 = V_57 -> V_6 ;
V_2 = F_6 ( V_6 ) ;
V_51 = V_57 -> V_16 ? F_22 ( V_57 -> V_16 ) : NULL ;
V_8 = V_47 ( V_6 -> V_64 ) ;
if ( V_57 -> V_65 > 1 ) {
F_17 ( L_2 ) ;
return - V_63 ;
}
if ( V_57 -> V_65 == 1 &&
V_57 -> V_66 [ 0 ] != & V_2 -> V_4 . V_59 ) {
F_17 ( L_3 ,
V_57 -> V_66 [ 0 ] , & V_2 -> V_4 . V_59 ) ;
return - V_63 ;
}
if ( V_8 -> V_11 -> V_16 && V_51 &&
! ( V_8 -> V_11 -> V_35 == 1 &&
! F_11 ( & V_2 -> V_3 ) ) &&
V_8 -> V_11 -> V_16 != V_51 ) {
F_17 ( L_4 ) ;
return - V_63 ;
}
V_59 = & V_2 -> V_4 . V_59 ;
V_62 = & V_2 -> V_4 . V_62 ;
if ( V_57 -> V_65 == 0 || ! V_57 -> V_24 || ! V_57 -> V_16 ) {
V_59 -> V_62 = NULL ;
V_62 -> V_6 = NULL ;
V_6 -> V_16 = NULL ;
F_18 ( V_8 , V_2 ) ;
return F_7 ( V_8 ) ;
}
V_24 = V_57 -> V_24 ;
V_16 = V_57 -> V_16 ;
if ( V_57 -> V_23 + V_24 -> V_25 > V_16 -> V_32 ||
V_57 -> V_26 + V_24 -> V_27 > V_16 -> V_33 ) {
F_17 ( L_5 ) ;
return - V_63 ;
}
F_23 ( V_8 ) ;
V_6 -> V_16 = V_16 ;
V_62 -> V_6 = V_6 ;
V_59 -> V_62 = V_62 ;
V_6 -> V_23 = V_57 -> V_23 ;
V_6 -> V_26 = V_57 -> V_26 ;
V_6 -> V_24 = * V_24 ;
F_19 ( V_8 , V_2 , V_51 ) ;
return F_7 ( V_8 ) ;
}
static void F_24 ( struct V_61 * V_62 )
{
F_1 ( F_25 ( V_62 ) ) ;
}
static void F_26 ( struct V_58 * V_59 )
{
F_1 ( F_27 ( V_59 ) ) ;
}
static int F_28 ( struct V_7 * V_8 , unsigned V_55 )
{
struct V_1 * V_2 ;
struct V_67 * V_64 = V_8 -> V_64 ;
struct V_58 * V_59 ;
struct V_61 * V_62 ;
struct V_5 * V_6 ;
V_2 = F_29 ( sizeof( * V_2 ) , V_68 ) ;
if ( ! V_2 )
return - V_69 ;
V_2 -> V_4 . V_55 = V_55 ;
V_6 = & V_2 -> V_4 . V_6 ;
V_62 = & V_2 -> V_4 . V_62 ;
V_59 = & V_2 -> V_4 . V_59 ;
F_30 ( & V_2 -> V_3 ) ;
V_2 -> V_4 . V_70 = ( V_55 == 0 ) ;
V_2 -> V_4 . V_71 = V_8 -> V_72 ;
V_2 -> V_4 . V_73 = V_8 -> V_74 ;
V_2 -> V_4 . V_75 = NULL ;
V_2 -> V_4 . V_76 = true ;
F_31 ( V_64 , V_59 , & V_77 ,
V_78 ) ;
V_59 -> V_79 = F_32 ( V_59 , true ) ;
F_33 ( V_64 , V_62 , & V_80 ,
V_81 ) ;
F_34 ( V_59 , V_62 ) ;
V_62 -> V_82 = ( 1 << V_55 ) ;
V_62 -> V_83 = 0 ;
F_35 ( V_64 , V_6 , & V_84 ) ;
F_36 ( V_6 , 256 ) ;
F_37 ( V_59 ,
V_64 -> V_85 . V_86 ,
1 ) ;
return 0 ;
}
int F_38 ( struct V_7 * V_8 )
{
struct V_67 * V_64 = V_8 -> V_64 ;
int V_17 , V_18 ;
if ( V_8 -> V_11 ) {
F_39 ( L_6 ) ;
return - V_63 ;
}
V_8 -> V_11 = F_40 ( sizeof( * V_8 -> V_11 ) , V_68 ) ;
if ( ! V_8 -> V_11 )
return - V_69 ;
F_30 ( & V_8 -> V_11 -> V_3 ) ;
V_8 -> V_11 -> V_35 = 0 ;
V_8 -> V_11 -> V_43 = 0 ;
V_8 -> V_11 -> V_16 = NULL ;
if ( V_8 -> V_19 & V_87 )
V_18 = F_41 ( V_64 , V_88 ) ;
else
V_18 = F_41 ( V_64 , 1 ) ;
if ( V_18 != 0 )
goto V_89;
V_18 = F_42 ( V_64 ) ;
if ( V_18 != 0 )
goto V_90;
if ( V_8 -> V_19 & V_87 )
for ( V_17 = 0 ; V_17 < V_88 ; ++ V_17 )
F_28 ( V_8 , V_17 ) ;
else
F_28 ( V_8 , 0 ) ;
return 0 ;
V_90:
F_43 ( V_64 ) ;
V_89:
F_4 ( V_8 -> V_11 ) ;
V_8 -> V_11 = NULL ;
return V_18 ;
}
int F_44 ( struct V_7 * V_8 )
{
struct V_67 * V_64 = V_8 -> V_64 ;
if ( ! V_8 -> V_11 )
return - V_91 ;
F_43 ( V_64 ) ;
F_15 ( ! F_11 ( & V_8 -> V_11 -> V_3 ) ) ;
F_4 ( V_8 -> V_11 ) ;
return 0 ;
}
