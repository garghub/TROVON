static T_1 F_1 ( struct V_1 * V_1 )
{
return 1 << ( V_2 + F_2 ( V_1 ) ) ;
}
static void *
F_3 ( int V_3 , void * * V_4 , int V_5 , bool V_6 )
{
struct V_7 * V_8 ;
struct V_1 * V_1 ;
int V_9 = ( V_3 == - 1 ) ? V_3 : F_4 ( V_3 ) ;
unsigned long V_10 ;
T_1 V_11 = V_5 << V_2 ;
int V_12 , V_13 , V_14 ;
for ( V_12 = 0 , V_13 = 0 ; V_12 < V_5 ; ) {
V_1 = F_5 ( V_4 [ V_12 ] ) ;
if ( F_6 ( ! F_7 ( V_1 ) && V_5 > 1 ) )
return NULL ;
V_12 += 1 << F_2 ( V_1 ) ;
V_13 ++ ;
}
if ( V_6 && V_13 > 1 )
return NULL ;
V_8 = F_8 ( F_9 ( struct V_7 , V_8 [ V_13 ] ) , V_15 , V_9 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_5 = V_5 ;
V_8 -> V_16 = V_13 ;
V_8 -> V_17 = V_6 ;
V_8 -> V_18 = V_4 ;
V_8 -> V_19 = V_11 - V_11 % V_20 ;
for ( V_12 = 0 , V_13 = 0 , V_10 = 0 , V_14 = 0 ; V_13 < V_8 -> V_16 ; V_13 ++ ) {
unsigned int V_21 ;
V_1 = F_5 ( V_4 [ V_12 ] ) ;
V_21 = F_7 ( V_1 ) ? 1 << F_2 ( V_1 ) : 1 ;
V_8 -> V_8 [ V_13 ] . V_1 = V_1 ;
V_8 -> V_8 [ V_13 ] . V_10 = V_10 ;
V_8 -> V_8 [ V_13 ] . V_22 = ( V_14 ? V_20 - V_14 : 0 ) ;
V_8 -> V_8 [ V_13 ] . V_11 = F_1 ( V_1 ) - V_8 -> V_8 [ V_13 ] . V_22 ;
V_14 = V_8 -> V_8 [ V_13 ] . V_11 % V_20 ;
V_8 -> V_8 [ V_13 ] . V_11 -= V_14 ;
V_12 += V_21 ;
V_10 += V_21 << V_2 ;
}
return V_8 ;
}
static void F_10 ( void * V_23 )
{
F_11 ( V_23 ) ;
}
static unsigned long F_12 ( struct V_7 * V_8 , unsigned int V_24 )
{
return V_8 -> V_8 [ V_24 ] . V_10 + V_8 -> V_8 [ V_24 ] . V_22 ;
}
static void
F_13 ( struct V_7 * V_8 )
{
int V_3 = F_14 () ;
struct V_25 * V_26 = F_15 ( V_27 , V_3 ) . V_26 ;
struct V_28 * V_29 = & V_8 -> V_8 [ V_8 -> V_30 ] ;
unsigned long V_31 , V_32 = 0 , V_33 = V_29 -> V_11 ;
struct V_1 * V_1 = V_29 -> V_1 ;
V_31 = F_16 ( & V_8 -> V_34 ) ;
if ( ! V_8 -> V_17 ) {
if ( V_8 -> V_33 < V_29 -> V_10 + F_1 ( V_1 ) )
V_33 = V_8 -> V_33 - V_29 -> V_10 - V_29 -> V_22 ;
V_31 -= V_29 -> V_10 + V_29 -> V_22 ;
if ( V_33 - V_31 > V_35 )
V_32 = V_33 - V_35 ;
else if ( V_33 - V_31 > V_20 )
V_32 = V_33 - V_20 ;
else
V_32 = V_33 ;
}
V_26 -> V_36 = ( V_37 ) ( long ) F_17 ( V_1 ) + V_29 -> V_22 ;
V_26 -> V_38 = V_26 -> V_36 + V_31 ;
V_26 -> V_39 = V_26 -> V_36 + V_33 ;
V_26 -> V_40 = ! V_8 -> V_17
? V_26 -> V_36 + V_32
: V_26 -> V_39 + V_20 ;
}
static void F_18 ( struct V_28 * V_29 , unsigned long V_34 )
{
unsigned long V_31 = V_34 - V_29 -> V_10 ;
memset ( F_17 ( V_29 -> V_1 ) + V_31 , 0 , V_29 -> V_11 - V_31 ) ;
}
static bool F_19 ( struct V_7 * V_8 , struct V_41 * V_42 )
{
if ( V_8 -> V_17 )
return false ;
if ( F_16 ( & V_8 -> V_43 ) >= V_42 -> V_44 . V_11 ||
V_42 -> V_44 . V_11 - F_16 ( & V_8 -> V_43 ) < V_20 )
return true ;
return false ;
}
static void F_20 ( struct V_41 * V_42 )
{
int V_3 = F_14 () ;
struct V_25 * V_26 = F_15 ( V_27 , V_3 ) . V_26 ;
struct V_7 * V_8 = F_21 ( & V_42 -> V_44 ) ;
unsigned long V_31 = V_26 -> V_38 - V_26 -> V_36 , V_45 , V_34 ;
if ( ! V_8 )
return;
V_34 = V_31 + F_12 ( V_8 , V_8 -> V_30 ) ;
V_45 = F_22 ( & V_8 -> V_34 , V_34 ) ;
if ( ! V_8 -> V_17 ) {
if ( V_45 == V_34 )
return;
if ( V_26 -> V_38 >= V_26 -> V_39 )
F_23 ( & V_8 -> V_46 ) ;
F_24 ( V_34 - V_45 , & V_8 -> V_43 ) ;
} else {
F_25 ( & V_8 -> V_43 , V_34 ) ;
}
}
static void F_26 ( struct V_47 * V_48 )
{
struct V_41 * V_42 = F_27 ( & V_41 ) ;
struct V_7 * V_8 = F_21 ( & V_42 -> V_44 ) ;
V_37 V_49 = 0 ;
if ( ! V_8 || F_19 ( V_8 , V_42 ) )
return;
V_48 -> V_50 . V_51 = 1 ;
V_48 -> V_50 . V_52 = 0 ;
if ( ! V_8 -> V_17 )
V_49 |= V_53 ;
if ( ! V_48 -> V_54 . V_55 )
V_49 |= V_56 ;
if ( ! V_48 -> V_54 . V_57 )
V_49 |= V_58 ;
F_13 ( V_8 ) ;
F_28 () ;
F_29 ( V_49 ) ;
}
static void F_30 ( struct V_47 * V_48 , int V_59 )
{
struct V_41 * V_42 = F_27 ( & V_41 ) ;
F_26 ( V_48 ) ;
F_31 ( V_42 -> V_60 ) = 1 ;
}
static void F_32 ( struct V_47 * V_48 )
{
F_33 () ;
if ( V_48 -> V_50 . V_52 & V_61 )
return;
F_31 ( V_48 -> V_50 . V_52 ) |= V_61 ;
}
static void F_34 ( struct V_47 * V_48 , int V_59 )
{
struct V_41 * V_42 = F_27 ( & V_41 ) ;
F_31 ( V_42 -> V_60 ) = 0 ;
F_32 ( V_48 ) ;
if ( V_59 & V_62 )
F_20 ( V_42 ) ;
}
void F_35 ( void )
{
struct V_41 * V_42 = F_27 ( & V_41 ) ;
if ( V_42 -> V_44 . V_48 && V_42 -> V_60 )
F_26 ( V_42 -> V_44 . V_48 ) ;
}
void F_36 ( void )
{
struct V_41 * V_42 = F_27 ( & V_41 ) ;
if ( V_42 -> V_44 . V_48 )
F_32 ( V_42 -> V_44 . V_48 ) ;
}
static int
F_37 ( struct V_7 * V_8 , struct V_63 * V_44 )
{
unsigned long V_34 , V_64 , V_65 , V_14 , V_66 , V_67 , V_68 ;
unsigned int V_69 ;
struct V_28 * V_29 , * V_70 ;
int V_71 ;
if ( V_8 -> V_17 )
return 0 ;
V_34 = V_44 -> V_34 & ( ( V_8 -> V_5 << V_2 ) - 1 ) ;
if ( F_6 ( V_34 != F_16 ( & V_8 -> V_34 ) ) )
return - V_72 ;
V_29 = & V_8 -> V_8 [ V_8 -> V_30 ] ;
V_64 = V_29 -> V_10 + V_29 -> V_22 + V_29 -> V_11 - V_34 ;
V_14 = V_64 ;
if ( V_64 > V_44 -> V_11 ) {
V_64 = V_44 -> V_11 ;
V_64 -= V_64 % V_20 ;
}
if ( V_64 <= V_35 ) {
V_69 = V_8 -> V_30 + 1 ;
if ( V_69 >= V_8 -> V_16 )
V_69 = 0 ;
V_70 = & V_8 -> V_8 [ V_69 ] ;
V_66 = F_1 ( V_29 -> V_1 ) - V_29 -> V_22 - V_29 -> V_11 +
V_70 -> V_22 ;
V_67 = V_14 + V_66 ;
if ( V_44 -> V_11 >= V_67 ) {
V_65 = V_70 -> V_11 ;
if ( V_65 + V_67 > V_44 -> V_11 ) {
V_65 = V_44 -> V_11 - V_67 ;
V_65 -= V_65 % V_20 ;
}
if ( V_65 > V_64 || ! V_64 ) {
if ( V_14 )
F_18 ( V_29 , V_34 ) ;
V_71 = F_38 ( V_44 , V_67 ) ;
if ( V_71 )
return V_71 ;
V_29 = V_70 ;
V_64 = V_65 ;
V_34 = V_29 -> V_10 + V_29 -> V_22 ;
V_8 -> V_30 = V_69 ;
F_25 ( & V_8 -> V_34 , V_34 ) ;
}
}
}
V_68 = V_35 + V_20 + V_44 -> V_68 -
V_44 -> V_34 ;
if ( V_64 > V_68 ) {
V_64 = V_68 ;
V_64 -= V_64 % V_20 ;
}
V_8 -> V_33 = V_34 + V_64 ;
if ( ! V_64 )
return - V_73 ;
return 0 ;
}
int F_39 ( void )
{
struct V_41 * V_42 = F_27 ( & V_41 ) ;
struct V_47 * V_48 = V_42 -> V_44 . V_48 ;
struct V_7 * V_8 ;
T_2 V_74 ;
int V_75 ;
if ( ! V_48 || ! V_42 -> V_60 )
return 0 ;
V_8 = F_21 ( & V_42 -> V_44 ) ;
if ( ! V_8 || V_8 -> V_17 )
return 0 ;
V_74 = F_16 ( & V_8 -> V_34 ) ;
F_20 ( V_42 ) ;
if ( V_74 == F_16 ( & V_8 -> V_34 ) )
return 0 ;
F_40 ( & V_42 -> V_44 , F_22 ( & V_8 -> V_43 , 0 ) ,
! ! F_22 ( & V_8 -> V_46 , 0 ) ) ;
V_8 = F_41 ( & V_42 -> V_44 , V_48 ) ;
if ( ! V_8 )
return 1 ;
V_75 = F_37 ( V_8 , & V_42 -> V_44 ) ;
if ( V_75 )
F_40 ( & V_42 -> V_44 , 0 , false ) ;
return 1 ;
}
static void F_42 ( struct V_47 * V_48 , int V_76 )
{
struct V_27 * V_77 = F_27 ( & V_27 ) ;
struct V_41 * V_42 = F_27 ( & V_41 ) ;
struct V_7 * V_8 = F_21 ( & V_42 -> V_44 ) ;
F_34 ( V_48 , V_62 ) ;
if ( V_8 ) {
if ( V_8 -> V_17 )
V_42 -> V_44 . V_34 =
F_22 ( & V_8 -> V_43 ,
V_8 -> V_5 << V_2 ) ;
F_40 ( & V_42 -> V_44 , F_22 ( & V_8 -> V_43 , 0 ) ,
! ! F_22 ( & V_8 -> V_46 , 0 ) ) ;
}
V_77 -> V_26 -> V_38 = V_42 -> V_78 . V_36 ;
V_77 -> V_26 -> V_36 = V_42 -> V_78 . V_36 ;
V_77 -> V_26 -> V_39 = V_42 -> V_78 . V_39 ;
V_77 -> V_26 -> V_40 = V_42 -> V_78 . V_40 ;
}
static int F_43 ( struct V_47 * V_48 , int V_76 )
{
struct V_7 * V_8 ;
struct V_41 * V_42 = F_27 ( & V_41 ) ;
struct V_27 * V_77 = F_27 ( & V_27 ) ;
struct V_79 * V_80 = & V_48 -> V_50 ;
int V_71 = - V_81 ;
V_48 -> V_50 . V_52 = V_61 ;
if ( F_44 ( V_82 , V_77 -> V_83 ) )
return - V_81 ;
if ( V_42 -> V_44 . V_48 )
return - V_81 ;
V_8 = F_41 ( & V_42 -> V_44 , V_48 ) ;
if ( ! V_8 )
return - V_72 ;
V_71 = F_37 ( V_8 , & V_42 -> V_44 ) ;
if ( V_71 ) {
F_40 ( & V_42 -> V_44 , 0 , false ) ;
return V_71 ;
}
V_42 -> V_78 . V_36 = V_77 -> V_26 -> V_36 ;
V_42 -> V_78 . V_39 = V_77 -> V_26 -> V_39 ;
V_42 -> V_78 . V_40 = V_77 -> V_26 -> V_40 ;
if ( V_76 & V_84 ) {
F_30 ( V_48 , 0 ) ;
if ( V_80 -> V_52 & V_61 ) {
F_42 ( V_48 , 0 ) ;
return - V_81 ;
}
}
return 0 ;
}
static void F_45 ( struct V_47 * V_48 )
{
F_46 () ;
F_47 ( V_85 ) ;
}
static int F_48 ( struct V_47 * V_48 )
{
int V_71 ;
if ( V_48 -> V_54 . type != V_86 . type )
return - V_87 ;
if ( F_49 ( V_85 ) )
return - V_81 ;
if ( V_48 -> V_54 . V_55 && F_50 () &&
! F_51 ( V_88 ) )
return - V_89 ;
V_71 = F_52 () ;
if ( V_71 ) {
F_47 ( V_85 ) ;
return V_71 ;
}
V_48 -> V_90 = F_45 ;
return 0 ;
}
static void F_53 ( struct V_47 * V_48 )
{
}
static T_3 int F_54 ( void )
{
if ( ! F_55 ( V_91 ) || ! V_92 . V_42 )
return - V_93 ;
V_86 . V_94 = V_95 | V_96 ;
V_86 . V_97 = V_98 ;
V_86 . V_99 = F_48 ;
V_86 . V_100 = F_43 ;
V_86 . V_101 = F_42 ;
V_86 . V_102 = F_30 ;
V_86 . V_103 = F_34 ;
V_86 . V_104 = F_53 ;
V_86 . V_105 = F_3 ;
V_86 . V_106 = F_10 ;
return F_56 ( & V_86 , L_1 , - 1 ) ;
}
