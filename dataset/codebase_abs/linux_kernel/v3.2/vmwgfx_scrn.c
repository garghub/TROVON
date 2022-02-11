static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( V_2 ) ;
}
static void F_4 ( struct V_4 * V_5 )
{
F_1 ( F_5 ( V_5 ) ) ;
}
static void F_6 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
if ( V_2 -> V_11 ) {
if ( -- ( V_9 -> V_12 ) == 0 )
V_9 -> V_13 = NULL ;
V_2 -> V_11 = false ;
}
}
static void F_7 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_14 * V_15 )
{
struct V_8 * V_9 = V_7 -> V_10 ;
F_8 ( ! V_9 -> V_12 && V_9 -> V_13 ) ;
if ( ! V_2 -> V_11 && V_2 -> V_3 . V_16 ) {
V_9 -> V_13 = V_15 ;
V_2 -> V_11 = true ;
V_9 -> V_12 ++ ;
}
}
static int F_9 ( struct V_6 * V_17 ,
struct V_1 * V_2 ,
T_1 V_18 , T_1 V_19 ,
struct V_20 * V_21 )
{
T_2 V_22 ;
struct {
struct {
T_1 V_23 ;
} V_24 ;
T_3 V_25 ;
} * V_26 ;
F_8 ( ! V_2 -> V_27 ) ;
V_22 = sizeof( * V_26 ) ;
V_26 = F_10 ( V_17 , V_22 ) ;
if ( F_11 ( V_26 == NULL ) ) {
F_12 ( L_1 ) ;
return - V_28 ;
}
memset ( V_26 , 0 , V_22 ) ;
V_26 -> V_24 . V_23 = V_29 ;
V_26 -> V_25 . V_30 = sizeof( T_3 ) ;
V_26 -> V_25 . V_31 = V_2 -> V_3 . V_32 ;
V_26 -> V_25 . V_33 = V_34 |
( V_2 -> V_3 . V_32 == 0 ? V_35 : 0 ) ;
V_26 -> V_25 . V_36 . V_37 = V_21 -> V_38 ;
V_26 -> V_25 . V_36 . V_39 = V_21 -> V_40 ;
if ( V_2 -> V_3 . V_16 ) {
V_26 -> V_25 . V_41 . V_18 = V_18 ;
V_26 -> V_25 . V_41 . V_19 = V_19 ;
} else {
V_26 -> V_25 . V_41 . V_18 = V_2 -> V_3 . V_42 ;
V_26 -> V_25 . V_41 . V_19 = V_2 -> V_3 . V_43 ;
}
F_13 ( & V_2 -> V_27 -> V_3 , & V_26 -> V_25 . V_44 . V_45 ) ;
V_26 -> V_25 . V_44 . V_46 = V_21 -> V_38 * 4 ;
F_14 ( V_17 , V_22 ) ;
V_2 -> V_47 = true ;
return 0 ;
}
static int F_15 ( struct V_6 * V_17 ,
struct V_1 * V_2 )
{
T_2 V_22 ;
int V_48 ;
struct {
struct {
T_1 V_23 ;
} V_24 ;
T_4 V_49 ;
} * V_26 ;
if ( F_11 ( ! V_2 -> V_47 ) )
return 0 ;
V_22 = sizeof( * V_26 ) ;
V_26 = F_10 ( V_17 , V_22 ) ;
if ( F_11 ( V_26 == NULL ) ) {
F_12 ( L_1 ) ;
return - V_28 ;
}
memset ( V_26 , 0 , V_22 ) ;
V_26 -> V_24 . V_23 = V_50 ;
V_26 -> V_49 . V_51 = V_2 -> V_3 . V_32 ;
F_14 ( V_17 , V_22 ) ;
V_48 = F_16 ( V_17 , false , true , 0 , false , 3 * V_52 ) ;
if ( F_11 ( V_48 != 0 ) )
F_12 ( L_2 ) ;
else
V_2 -> V_47 = false ;
return V_48 ;
}
static void F_17 ( struct V_6 * V_17 ,
struct V_1 * V_2 )
{
struct V_53 * V_54 ;
if ( F_11 ( V_2 -> V_27 == NULL ) )
return;
V_54 = & V_2 -> V_27 -> V_3 ;
F_18 ( & V_54 ) ;
V_2 -> V_27 = NULL ;
V_2 -> V_55 = 0 ;
}
static int F_19 ( struct V_6 * V_17 ,
struct V_1 * V_2 ,
unsigned long V_36 )
{
int V_48 ;
if ( V_2 -> V_55 == V_36 )
return 0 ;
if ( V_2 -> V_27 )
F_17 ( V_17 , V_2 ) ;
V_2 -> V_27 = F_20 ( sizeof( * V_2 -> V_27 ) , V_56 ) ;
if ( F_11 ( V_2 -> V_27 == NULL ) )
return - V_28 ;
F_21 ( V_17 ) ;
V_48 = F_22 ( V_17 , V_2 -> V_27 , V_36 ,
& V_57 ,
false , & V_58 ) ;
F_23 ( V_17 ) ;
if ( F_11 ( V_48 != 0 ) )
V_2 -> V_27 = NULL ;
else
V_2 -> V_55 = V_36 ;
return V_48 ;
}
static int F_24 ( struct V_59 * V_60 )
{
struct V_6 * V_17 ;
struct V_1 * V_2 ;
struct V_61 * V_62 ;
struct V_20 * V_21 ;
struct V_63 * V_64 ;
struct V_14 * V_15 ;
struct V_65 * V_66 ;
struct V_4 * V_5 ;
int V_48 = 0 ;
if ( ! V_60 )
return - V_67 ;
if ( ! V_60 -> V_5 )
return - V_67 ;
V_5 = V_60 -> V_5 ;
V_2 = F_5 ( V_5 ) ;
V_15 = V_60 -> V_66 ? F_25 ( V_60 -> V_66 ) : NULL ;
V_17 = V_7 ( V_5 -> V_68 ) ;
if ( V_60 -> V_69 > 1 ) {
F_12 ( L_3 ) ;
return - V_67 ;
}
if ( V_60 -> V_69 == 1 &&
V_60 -> V_70 [ 0 ] != & V_2 -> V_3 . V_62 ) {
F_12 ( L_4 ,
V_60 -> V_70 [ 0 ] , & V_2 -> V_3 . V_62 ) ;
return - V_67 ;
}
if ( V_2 -> V_3 . V_16 &&
V_17 -> V_10 -> V_13 && V_15 &&
! ( V_17 -> V_10 -> V_12 == 1 &&
V_2 -> V_11 ) &&
V_17 -> V_10 -> V_13 != V_15 ) {
F_12 ( L_5 ) ;
return - V_67 ;
}
V_62 = & V_2 -> V_3 . V_62 ;
V_64 = & V_2 -> V_3 . V_64 ;
if ( V_60 -> V_69 == 0 || ! V_60 -> V_21 || ! V_60 -> V_66 ) {
V_48 = F_15 ( V_17 , V_2 ) ;
if ( F_11 ( V_48 != 0 ) )
return V_48 ;
V_62 -> V_64 = NULL ;
V_64 -> V_5 = NULL ;
V_5 -> V_66 = NULL ;
V_5 -> V_18 = 0 ;
V_5 -> V_19 = 0 ;
F_6 ( V_17 , V_2 ) ;
F_17 ( V_17 , V_2 ) ;
return 0 ;
}
V_21 = V_60 -> V_21 ;
V_66 = V_60 -> V_66 ;
if ( V_60 -> V_18 + V_21 -> V_38 > V_66 -> V_37 ||
V_60 -> V_19 + V_21 -> V_40 > V_66 -> V_39 ) {
F_12 ( L_6 ) ;
return - V_67 ;
}
F_26 ( V_17 ) ;
if ( V_21 -> V_38 != V_5 -> V_21 . V_38 ||
V_21 -> V_40 != V_5 -> V_21 . V_40 ) {
V_48 = F_15 ( V_17 , V_2 ) ;
if ( F_11 ( V_48 != 0 ) )
return V_48 ;
F_17 ( V_17 , V_2 ) ;
}
if ( ! V_2 -> V_27 ) {
T_2 V_36 = V_21 -> V_38 * V_21 -> V_40 * 4 ;
V_48 = F_19 ( V_17 , V_2 , V_36 ) ;
if ( F_11 ( V_48 != 0 ) )
return V_48 ;
}
V_48 = F_9 ( V_17 , V_2 , V_60 -> V_18 , V_60 -> V_19 , V_21 ) ;
if ( F_11 ( V_48 != 0 ) ) {
if ( V_2 -> V_47 )
return V_48 ;
V_62 -> V_64 = NULL ;
V_64 -> V_5 = NULL ;
V_5 -> V_66 = NULL ;
V_5 -> V_18 = 0 ;
V_5 -> V_19 = 0 ;
return V_48 ;
}
F_7 ( V_17 , V_2 , V_15 ) ;
V_62 -> V_64 = V_64 ;
V_64 -> V_5 = V_5 ;
V_5 -> V_21 = * V_21 ;
V_5 -> V_66 = V_66 ;
V_5 -> V_18 = V_60 -> V_18 ;
V_5 -> V_19 = V_60 -> V_19 ;
return 0 ;
}
static void F_27 ( struct V_63 * V_64 )
{
F_1 ( F_28 ( V_64 ) ) ;
}
static void F_29 ( struct V_61 * V_62 )
{
F_1 ( F_30 ( V_62 ) ) ;
}
static int F_31 ( struct V_6 * V_17 , unsigned V_32 )
{
struct V_1 * V_2 ;
struct V_71 * V_68 = V_17 -> V_68 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_4 * V_5 ;
V_2 = F_20 ( sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 )
return - V_28 ;
V_2 -> V_3 . V_32 = V_32 ;
V_5 = & V_2 -> V_3 . V_5 ;
V_64 = & V_2 -> V_3 . V_64 ;
V_62 = & V_2 -> V_3 . V_62 ;
V_2 -> V_11 = false ;
V_2 -> V_3 . V_72 = ( V_32 == 0 ) ;
V_2 -> V_3 . V_73 = 800 ;
V_2 -> V_3 . V_74 = 600 ;
V_2 -> V_3 . V_75 = NULL ;
V_2 -> V_3 . V_16 = true ;
F_32 ( V_68 , V_62 , & V_76 ,
V_77 ) ;
V_62 -> V_78 = F_33 ( V_62 , true ) ;
F_34 ( V_68 , V_64 , & V_79 ,
V_80 ) ;
F_35 ( V_62 , V_64 ) ;
V_64 -> V_81 = ( 1 << V_32 ) ;
V_64 -> V_82 = 0 ;
F_36 ( V_68 , V_5 , & V_83 ) ;
F_37 ( V_5 , 256 ) ;
F_38 ( V_62 ,
V_68 -> V_84 . V_85 ,
1 ) ;
return 0 ;
}
int F_39 ( struct V_6 * V_17 )
{
struct V_71 * V_68 = V_17 -> V_68 ;
int V_86 , V_48 ;
if ( V_17 -> V_10 ) {
F_40 ( L_7 ) ;
return - V_67 ;
}
if ( ! ( V_17 -> V_87 . V_88 & V_89 ) ) {
F_40 ( L_8
L_9 ) ;
return - V_90 ;
}
V_48 = - V_28 ;
V_17 -> V_10 = F_41 ( sizeof( * V_17 -> V_10 ) , V_56 ) ;
if ( F_11 ( ! V_17 -> V_10 ) )
goto V_91;
V_17 -> V_10 -> V_12 = 0 ;
V_17 -> V_10 -> V_13 = NULL ;
V_48 = F_42 ( V_68 , V_92 ) ;
if ( F_11 ( V_48 != 0 ) )
goto V_93;
V_48 = F_43 ( V_68 ) ;
if ( F_11 ( V_48 != 0 ) )
goto V_94;
for ( V_86 = 0 ; V_86 < V_92 ; ++ V_86 )
F_31 ( V_17 , V_86 ) ;
F_40 ( L_10 ) ;
return 0 ;
V_94:
F_44 ( V_68 ) ;
V_93:
F_3 ( V_17 -> V_10 ) ;
V_17 -> V_10 = NULL ;
V_91:
return V_48 ;
}
int F_45 ( struct V_6 * V_17 )
{
struct V_71 * V_68 = V_17 -> V_68 ;
if ( ! V_17 -> V_10 )
return - V_90 ;
F_44 ( V_68 ) ;
F_3 ( V_17 -> V_10 ) ;
return 0 ;
}
