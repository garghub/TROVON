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
static void F_19 ( struct V_41 * V_42 )
{
int V_3 = F_14 () ;
struct V_25 * V_26 = F_15 ( V_27 , V_3 ) . V_26 ;
struct V_7 * V_8 = F_20 ( & V_42 -> V_43 ) ;
unsigned long V_31 = V_26 -> V_38 - V_26 -> V_36 , V_44 , V_34 ;
if ( ! V_8 )
return;
V_34 = V_31 + F_12 ( V_8 , V_8 -> V_30 ) ;
V_44 = F_21 ( & V_8 -> V_34 , V_34 ) ;
if ( ! V_8 -> V_17 ) {
if ( V_44 == V_34 )
return;
if ( V_26 -> V_38 >= V_26 -> V_39 )
F_22 ( & V_42 -> V_43 ,
V_45 ) ;
F_23 ( V_34 - V_44 , & V_8 -> V_46 ) ;
} else {
F_24 ( & V_8 -> V_46 , V_34 ) ;
}
}
static void F_25 ( struct V_47 * V_48 )
{
struct V_41 * V_42 = F_26 ( & V_41 ) ;
struct V_7 * V_8 = F_20 ( & V_42 -> V_43 ) ;
V_37 V_49 = 0 ;
if ( ! V_8 -> V_17 )
V_49 |= V_50 ;
if ( ! V_48 -> V_51 . V_52 )
V_49 |= V_53 ;
if ( ! V_48 -> V_51 . V_54 )
V_49 |= V_55 ;
F_13 ( V_8 ) ;
F_27 () ;
F_28 ( V_42 -> V_56 , V_57 ) ;
F_29 ( V_49 ) ;
}
static void F_30 ( struct V_47 * V_48 , int V_58 )
{
struct V_27 * V_59 = F_26 ( & V_27 ) ;
struct V_41 * V_42 = F_26 ( & V_41 ) ;
struct V_7 * V_8 ;
V_8 = F_31 ( & V_42 -> V_43 , V_48 ) ;
if ( ! V_8 )
goto V_60;
if ( F_32 ( V_8 , & V_42 -> V_43 ) )
goto V_61;
V_42 -> V_62 . V_36 = V_59 -> V_26 -> V_36 ;
V_42 -> V_62 . V_39 = V_59 -> V_26 -> V_39 ;
V_42 -> V_62 . V_40 = V_59 -> V_26 -> V_40 ;
V_48 -> V_63 . V_64 = 1 ;
V_48 -> V_63 . V_56 = 0 ;
F_25 ( V_48 ) ;
return;
V_61:
F_33 ( & V_42 -> V_43 , 0 ) ;
V_60:
V_48 -> V_63 . V_56 = V_65 ;
}
static void F_34 ( struct V_47 * V_48 , int V_56 )
{
struct V_41 * V_42 = F_26 ( & V_41 ) ;
F_28 ( V_42 -> V_56 , V_56 ) ;
F_35 () ;
}
static void F_36 ( struct V_47 * V_48 , int V_58 )
{
struct V_27 * V_59 = F_26 ( & V_27 ) ;
struct V_41 * V_42 = F_26 ( & V_41 ) ;
struct V_7 * V_8 = NULL ;
int V_56 = F_37 ( V_42 -> V_56 ) ;
if ( V_56 == V_57 )
F_34 ( V_48 , V_66 ) ;
if ( V_56 != V_66 )
V_8 = F_20 ( & V_42 -> V_43 ) ;
V_48 -> V_63 . V_56 |= V_65 ;
if ( V_58 & V_67 ) {
F_19 ( V_42 ) ;
if ( V_8 ) {
if ( V_8 -> V_17 )
V_42 -> V_43 . V_34 =
F_21 ( & V_8 -> V_46 ,
V_8 -> V_5 << V_2 ) ;
F_33 ( & V_42 -> V_43 ,
F_21 ( & V_8 -> V_46 , 0 ) ) ;
}
V_59 -> V_26 -> V_38 = V_42 -> V_62 . V_36 ;
V_59 -> V_26 -> V_36 = V_42 -> V_62 . V_36 ;
V_59 -> V_26 -> V_39 = V_42 -> V_62 . V_39 ;
V_59 -> V_26 -> V_40 = V_42 -> V_62 . V_40 ;
}
}
void F_38 ( void )
{
struct V_41 * V_42 = F_26 ( & V_41 ) ;
int V_56 = F_37 ( V_42 -> V_56 ) ;
if ( F_6 ( V_56 == V_57 ) )
return;
if ( V_56 == V_66 )
return;
if ( V_42 -> V_43 . V_48 )
F_25 ( V_42 -> V_43 . V_48 ) ;
}
void F_39 ( void )
{
struct V_41 * V_42 = F_26 ( & V_41 ) ;
if ( F_37 ( V_42 -> V_56 ) != V_57 )
return;
if ( V_42 -> V_43 . V_48 )
F_34 ( V_42 -> V_43 . V_48 , V_68 ) ;
}
static int
F_32 ( struct V_7 * V_8 , struct V_69 * V_43 )
{
unsigned long V_34 , V_70 , V_71 , V_14 , V_72 , V_73 , V_74 ;
unsigned int V_75 ;
struct V_28 * V_29 , * V_76 ;
int V_77 ;
if ( V_8 -> V_17 )
return 0 ;
V_34 = V_43 -> V_34 & ( ( V_8 -> V_5 << V_2 ) - 1 ) ;
V_29 = & V_8 -> V_8 [ V_8 -> V_30 ] ;
V_70 = V_29 -> V_10 + V_29 -> V_22 + V_29 -> V_11 - V_34 ;
V_14 = V_70 ;
if ( V_70 > V_43 -> V_11 ) {
V_70 = V_43 -> V_11 ;
V_70 -= V_70 % V_20 ;
}
if ( V_70 <= V_35 ) {
V_75 = V_8 -> V_30 + 1 ;
if ( V_75 >= V_8 -> V_16 )
V_75 = 0 ;
V_76 = & V_8 -> V_8 [ V_75 ] ;
V_72 = F_1 ( V_29 -> V_1 ) - V_29 -> V_22 - V_29 -> V_11 +
V_76 -> V_22 ;
V_73 = V_14 + V_72 ;
if ( V_43 -> V_11 >= V_73 ) {
V_71 = V_76 -> V_11 ;
if ( V_71 + V_73 > V_43 -> V_11 ) {
V_71 = V_43 -> V_11 - V_73 ;
V_71 -= V_71 % V_20 ;
}
if ( V_71 > V_70 || ! V_70 ) {
if ( V_14 )
F_18 ( V_29 , V_34 ) ;
V_77 = F_40 ( V_43 , V_73 ) ;
if ( V_77 )
return V_77 ;
V_29 = V_76 ;
V_70 = V_71 ;
V_34 = V_29 -> V_10 + V_29 -> V_22 ;
V_8 -> V_30 = V_75 ;
F_24 ( & V_8 -> V_34 , V_34 ) ;
}
}
}
V_74 = V_35 + V_20 + V_43 -> V_74 -
V_43 -> V_34 ;
if ( V_70 > V_74 ) {
V_70 = V_74 ;
V_70 -= V_70 % V_20 ;
}
V_8 -> V_33 = V_34 + V_70 ;
if ( ! V_70 )
return - V_78 ;
return 0 ;
}
int F_41 ( void )
{
struct V_25 * V_26 = F_26 ( & V_27 ) -> V_26 ;
struct V_41 * V_42 = F_26 ( & V_41 ) ;
struct V_47 * V_48 = V_42 -> V_43 . V_48 ;
struct V_7 * V_8 ;
T_2 V_79 ;
int V_80 = - V_78 , V_81 = 0 ;
if ( V_26 && ( V_26 -> V_38 >= V_26 -> V_40 ) )
V_81 = 1 ;
if ( F_37 ( V_42 -> V_56 ) == V_66 )
return V_81 ;
V_8 = F_20 ( & V_42 -> V_43 ) ;
if ( ! V_8 )
return V_81 ;
if ( V_8 -> V_17 )
return 0 ;
V_79 = F_16 ( & V_8 -> V_34 ) ;
F_19 ( V_42 ) ;
if ( V_79 == F_16 ( & V_8 -> V_34 ) )
return V_81 ;
F_33 ( & V_42 -> V_43 , F_21 ( & V_8 -> V_46 , 0 ) ) ;
V_8 = F_31 ( & V_42 -> V_43 , V_48 ) ;
if ( V_8 )
V_80 = F_32 ( V_8 , & V_42 -> V_43 ) ;
if ( V_80 ) {
F_28 ( V_42 -> V_56 , V_66 ) ;
if ( V_8 ) {
F_42 () ;
F_33 ( & V_42 -> V_43 , 0 ) ;
}
}
return 1 ;
}
static void F_43 ( struct V_47 * V_48 , int V_82 )
{
F_36 ( V_48 , V_67 ) ;
}
static int F_44 ( struct V_47 * V_48 , int V_82 )
{
struct V_41 * V_42 = F_26 ( & V_41 ) ;
struct V_27 * V_59 = F_26 ( & V_27 ) ;
struct V_83 * V_84 = & V_48 -> V_63 ;
V_48 -> V_63 . V_56 = V_65 ;
if ( F_45 ( V_85 , V_59 -> V_86 ) )
return - V_87 ;
if ( V_42 -> V_43 . V_48 )
return - V_87 ;
if ( V_82 & V_88 ) {
F_30 ( V_48 , 0 ) ;
if ( V_84 -> V_56 & V_65 )
return - V_89 ;
}
return 0 ;
}
static void F_46 ( struct V_47 * V_48 )
{
F_47 () ;
F_48 ( V_90 ) ;
}
static int F_49 ( struct V_47 * V_48 )
{
int V_77 ;
if ( V_48 -> V_51 . type != V_91 . type )
return - V_92 ;
if ( F_50 ( V_90 ) )
return - V_87 ;
if ( V_48 -> V_51 . V_52 && F_51 () &&
! F_52 ( V_93 ) )
return - V_94 ;
V_77 = F_53 () ;
if ( V_77 ) {
F_48 ( V_90 ) ;
return V_77 ;
}
V_48 -> V_95 = F_46 ;
return 0 ;
}
static void F_54 ( struct V_47 * V_48 )
{
}
static T_3 int F_55 ( void )
{
if ( ! F_56 ( V_96 ) || ! V_97 . V_42 )
return - V_98 ;
V_91 . V_99 = V_100 | V_101 |
V_102 ;
V_91 . V_103 = V_104 ;
V_91 . V_105 = F_49 ;
V_91 . V_106 = F_44 ;
V_91 . V_107 = F_43 ;
V_91 . V_108 = F_30 ;
V_91 . V_109 = F_36 ;
V_91 . V_110 = F_54 ;
V_91 . V_111 = F_3 ;
V_91 . V_112 = F_10 ;
return F_57 ( & V_91 , L_1 , - 1 ) ;
}
