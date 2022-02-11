static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4
= F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
F_4 ( V_2 ) ;
F_5 ( V_4 ) ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
unsigned V_8 , unsigned V_9 ,
struct V_10 * V_11 ,
unsigned V_12 )
{
struct V_3 * V_4
= F_2 ( V_2 ) ;
return F_7 ( V_4 , V_11 , V_12 ) ;
}
int
F_8 ( struct V_13 * V_14 ,
struct V_3 * V_15 ,
const struct V_16 * V_17 ,
struct V_18 * V_5 )
{
int V_19 ;
struct V_20 * V_21 ;
V_15 -> V_5 = V_5 ;
V_21 = F_9 ( V_5 ) ;
F_10 ( V_14 , & V_15 -> V_22 , V_17 ) ;
V_19 = F_11 ( V_14 , & V_15 -> V_22 , & V_23 ) ;
if ( V_19 ) {
V_15 -> V_5 = NULL ;
return V_19 ;
}
F_12 ( & V_15 -> V_24 ) ;
V_15 -> V_25 = V_15 -> y1 = V_26 ;
V_15 -> V_27 = V_15 -> V_28 = 0 ;
return 0 ;
}
static void F_13 ( struct V_29 * V_30 )
{
struct V_13 * V_14 = V_30 -> V_14 ;
struct V_31 * V_32 = V_14 -> V_33 ;
struct V_34 * V_35 = F_14 ( V_30 ) ;
F_15 ( V_32 , V_35 -> V_36 , 0 ,
V_30 -> V_37 . V_38 ,
V_30 -> V_37 . V_39 , 0 , 0 ) ;
}
static void F_16 ( struct V_29 * V_30 )
{
}
static void F_17 ( struct V_29 * V_30 )
{
struct V_13 * V_14 = V_30 -> V_14 ;
struct V_31 * V_32 = V_14 -> V_33 ;
struct V_34 * V_35 = F_14 ( V_30 ) ;
F_15 ( V_32 , V_35 -> V_36 , 0 , 0 , 0 , 0 , 0 ) ;
}
static int F_18 ( struct V_29 * V_30 ,
struct V_40 * V_41 )
{
return 0 ;
}
static void F_19 ( struct V_29 * V_30 ,
struct V_40 * V_42 )
{
unsigned long V_8 ;
F_20 ( & V_30 -> V_14 -> V_43 , V_8 ) ;
if ( V_30 -> V_41 -> V_44 )
F_21 ( V_30 , V_30 -> V_41 -> V_44 ) ;
V_30 -> V_41 -> V_44 = NULL ;
F_22 ( & V_30 -> V_14 -> V_43 , V_8 ) ;
}
static void F_23 ( struct V_45 * V_46 ,
struct V_47 * V_37 ,
struct V_47 * V_48 )
{
}
static void F_24 ( struct V_45 * V_46 )
{
}
static void F_25 ( struct V_45 * V_46 )
{
}
static int F_26 ( struct V_49 * V_50 )
{
struct V_34 * V_35 =
F_27 ( V_50 ) ;
struct V_47 * V_37 = NULL ;
int V_51 , V_52 , V_53 ;
V_52 = F_28 ( V_35 -> V_54 . V_55 . V_52 ) ;
V_53 = F_28 ( V_35 -> V_54 . V_55 . V_53 ) ;
V_51 = F_29 ( V_50 , V_56 , V_57 ) ;
if ( V_52 == 0 || V_53 == 0 ) {
V_52 = V_58 ;
V_53 = V_59 ;
F_30 ( V_50 , V_58 , V_59 ) ;
} else {
F_31 ( L_1 , V_52 , V_53 ) ;
V_37 = F_32 ( V_50 -> V_14 , V_52 , V_53 , 60 ,
false , false , false ) ;
V_37 -> type |= V_60 ;
F_33 ( V_50 , V_37 ) ;
V_51 ++ ;
}
return V_51 ;
}
static int F_34 ( struct V_49 * V_50 ,
struct V_47 * V_37 )
{
struct V_34 * V_35 =
F_27 ( V_50 ) ;
int V_52 , V_53 ;
V_52 = F_28 ( V_35 -> V_54 . V_55 . V_52 ) ;
V_53 = F_28 ( V_35 -> V_54 . V_55 . V_53 ) ;
if ( ! ( V_37 -> type & V_60 ) )
return V_61 ;
if ( V_37 -> V_38 == V_58 && V_37 -> V_39 == V_59 )
return V_61 ;
if ( V_37 -> V_38 <= V_52 && V_37 -> V_38 >= V_52 - 16 &&
V_37 -> V_39 <= V_53 && V_37 -> V_39 >= V_53 - 16 )
return V_61 ;
F_31 ( L_2 , V_37 -> V_38 , V_37 -> V_39 ) ;
return V_62 ;
}
static enum V_63 F_35 (
struct V_49 * V_50 ,
bool V_64 )
{
struct V_34 * V_35 =
F_27 ( V_50 ) ;
if ( V_35 -> V_54 . V_65 )
return V_66 ;
else
return V_67 ;
}
static void F_36 ( struct V_49 * V_50 )
{
struct V_34 * V_34 =
F_27 ( V_50 ) ;
F_37 ( V_50 ) ;
F_38 ( V_50 ) ;
F_5 ( V_34 ) ;
}
static int F_39 ( struct V_31 * V_32 , int V_36 )
{
struct V_13 * V_14 = V_32 -> V_68 ;
struct V_34 * V_35 = V_32 -> V_69 + V_36 ;
struct V_49 * V_50 = & V_35 -> V_70 ;
struct V_45 * V_46 = & V_35 -> V_71 ;
struct V_29 * V_30 = & V_35 -> V_30 ;
struct V_72 * V_73 , * V_74 ;
V_35 -> V_36 = V_36 ;
if ( V_36 == 0 ) {
V_35 -> V_54 . V_65 = F_40 ( true ) ;
V_35 -> V_54 . V_55 . V_52 = F_40 ( V_58 ) ;
V_35 -> V_54 . V_55 . V_53 = F_40 ( V_59 ) ;
}
V_73 = F_41 ( V_32 , V_75 , V_36 ) ;
if ( F_42 ( V_73 ) )
return F_43 ( V_73 ) ;
V_74 = F_41 ( V_32 , V_76 , V_36 ) ;
if ( F_42 ( V_74 ) )
return F_43 ( V_74 ) ;
F_44 ( V_14 , V_30 , V_73 , V_74 ,
& V_77 , NULL ) ;
F_45 ( V_30 , & V_78 ) ;
V_73 -> V_30 = V_30 ;
V_74 -> V_30 = V_30 ;
F_46 ( V_14 , V_50 , & V_79 ,
V_80 ) ;
F_47 ( V_50 , & V_81 ) ;
F_48 ( V_14 , V_46 , & V_82 ,
V_83 , NULL ) ;
F_49 ( V_46 , & V_84 ) ;
V_46 -> V_85 = 1 << V_36 ;
F_50 ( V_50 , V_46 ) ;
F_51 ( V_50 ) ;
return 0 ;
}
static struct V_1 *
F_52 ( struct V_13 * V_14 ,
struct V_6 * V_7 ,
const struct V_16 * V_17 )
{
struct V_18 * V_5 = NULL ;
struct V_3 * V_4 ;
int V_19 ;
V_5 = F_53 ( V_7 , V_17 -> V_86 [ 0 ] ) ;
if ( ! V_5 )
return F_54 ( - V_87 ) ;
V_4 = F_55 ( sizeof( * V_4 ) , V_88 ) ;
if ( V_4 == NULL )
return F_54 ( - V_89 ) ;
V_19 = F_8 ( V_14 , V_4 , V_17 , V_5 ) ;
if ( V_19 ) {
F_5 ( V_4 ) ;
F_3 ( V_5 ) ;
return NULL ;
}
return & V_4 -> V_22 ;
}
static void F_56 ( struct V_90 * V_41 )
{
struct V_13 * V_14 = V_41 -> V_14 ;
F_57 ( V_14 , V_41 ) ;
F_58 ( V_14 , V_41 ) ;
F_59 ( V_14 , V_41 , 0 ) ;
F_60 ( V_41 ) ;
F_61 ( V_14 , V_41 ) ;
F_62 ( V_14 , V_41 ) ;
}
int F_63 ( struct V_31 * V_32 )
{
int V_91 ;
F_64 ( V_32 -> V_68 ) ;
V_32 -> V_68 -> V_92 . V_93 = & V_94 ;
V_32 -> V_68 -> V_92 . V_95 = & V_96 ;
V_32 -> V_68 -> V_92 . V_97 = V_98 ;
V_32 -> V_68 -> V_92 . V_99 = V_100 ;
V_32 -> V_68 -> V_92 . V_101 = V_56 ;
V_32 -> V_68 -> V_92 . V_102 = V_57 ;
for ( V_91 = 0 ; V_91 < V_32 -> V_103 ; ++ V_91 )
F_39 ( V_32 , V_91 ) ;
F_65 ( V_32 -> V_68 ) ;
return 0 ;
}
void F_66 ( struct V_31 * V_32 )
{
F_67 ( V_32 ) ;
F_68 ( V_32 -> V_68 ) ;
}
