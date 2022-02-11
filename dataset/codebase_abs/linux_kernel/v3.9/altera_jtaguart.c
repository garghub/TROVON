static unsigned int F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 -> V_3 + V_4 ) &
V_5 ) ? V_6 : 0 ;
}
static unsigned int F_3 ( struct V_1 * V_2 )
{
return V_7 | V_8 | V_9 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_10 )
{
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_11 * V_12 =
F_6 ( V_2 , struct V_11 , V_2 ) ;
V_12 -> V_13 |= V_14 ;
F_7 ( V_12 -> V_13 , V_2 -> V_3 + V_4 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_11 * V_12 =
F_6 ( V_2 , struct V_11 , V_2 ) ;
V_12 -> V_13 &= ~ V_14 ;
F_7 ( V_12 -> V_13 , V_2 -> V_3 + V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_11 * V_12 =
F_6 ( V_2 , struct V_11 , V_2 ) ;
V_12 -> V_13 &= ~ V_15 ;
F_7 ( V_12 -> V_13 , V_2 -> V_3 + V_4 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_16 )
{
}
static void F_11 ( struct V_1 * V_2 )
{
}
static void F_12 ( struct V_1 * V_2 ,
struct V_17 * V_18 ,
struct V_17 * V_19 )
{
if ( V_19 )
F_13 ( V_18 , V_19 ) ;
}
static void F_14 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_2 ;
unsigned char V_20 , V_21 ;
unsigned long V_22 ;
while ( ( V_22 = F_2 ( V_2 -> V_3 + V_23 ) ) &
V_24 ) {
V_20 = V_22 & V_25 ;
V_21 = V_26 ;
V_2 -> V_27 . V_28 ++ ;
if ( F_15 ( V_2 , V_20 ) )
continue;
F_16 ( V_2 , 0 , 0 , V_20 , V_21 ) ;
}
F_17 ( & V_2 -> V_29 -> V_2 ) ;
}
static void F_18 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = & V_12 -> V_2 ;
struct V_30 * V_31 = & V_2 -> V_29 -> V_31 ;
unsigned int V_32 , V_33 ;
if ( V_2 -> V_34 ) {
F_7 ( V_2 -> V_34 , V_2 -> V_3 + V_23 ) ;
V_2 -> V_34 = 0 ;
V_2 -> V_27 . V_35 ++ ;
return;
}
V_32 = F_19 ( V_31 ) ;
if ( V_32 > 0 ) {
V_33 = ( F_2 ( V_2 -> V_3 + V_4 ) &
V_5 ) >>
V_36 ;
if ( V_33 > V_32 )
V_33 = V_32 ;
if ( V_33 > 0 ) {
V_32 -= V_33 ;
while ( V_33 -- ) {
F_7 ( V_31 -> V_37 [ V_31 -> V_38 ] ,
V_2 -> V_3 + V_23 ) ;
V_31 -> V_38 = ( V_31 -> V_38 + 1 ) & ( V_39 - 1 ) ;
V_2 -> V_27 . V_35 ++ ;
}
if ( V_32 < V_40 )
F_20 ( V_2 ) ;
}
}
if ( V_32 == 0 ) {
V_12 -> V_13 &= ~ V_14 ;
F_7 ( V_12 -> V_13 , V_2 -> V_3 + V_4 ) ;
}
}
static T_1 F_21 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
struct V_11 * V_12 =
F_6 ( V_2 , struct V_11 , V_2 ) ;
unsigned int V_43 ;
V_43 = ( F_2 ( V_2 -> V_3 + V_4 ) >>
V_44 ) & V_12 -> V_13 ;
F_22 ( & V_2 -> V_45 ) ;
if ( V_43 & V_15 )
F_14 ( V_12 ) ;
if ( V_43 & V_14 )
F_18 ( V_12 ) ;
F_23 ( & V_2 -> V_45 ) ;
return F_24 ( V_43 ) ;
}
static void F_25 ( struct V_1 * V_2 , int V_46 )
{
V_2 -> type = V_47 ;
F_7 ( 0 , V_2 -> V_3 + V_4 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_11 * V_12 =
F_6 ( V_2 , struct V_11 , V_2 ) ;
unsigned long V_46 ;
int V_48 ;
V_48 = F_27 ( V_2 -> V_41 , F_21 , 0 ,
V_49 , V_2 ) ;
if ( V_48 ) {
F_28 ( V_49 L_1
L_2 , V_2 -> line , V_2 -> V_41 ) ;
return V_48 ;
}
F_29 ( & V_2 -> V_45 , V_46 ) ;
V_12 -> V_13 = V_15 ;
F_7 ( V_12 -> V_13 , V_2 -> V_3 + V_4 ) ;
F_30 ( & V_2 -> V_45 , V_46 ) ;
return 0 ;
}
static void F_31 ( struct V_1 * V_2 )
{
struct V_11 * V_12 =
F_6 ( V_2 , struct V_11 , V_2 ) ;
unsigned long V_46 ;
F_29 ( & V_2 -> V_45 , V_46 ) ;
V_12 -> V_13 = 0 ;
F_7 ( V_12 -> V_13 , V_2 -> V_3 + V_4 ) ;
F_30 ( & V_2 -> V_45 , V_46 ) ;
F_32 ( V_2 -> V_41 , V_2 ) ;
}
static const char * F_33 ( struct V_1 * V_2 )
{
return ( V_2 -> type == V_47 ) ? L_3 : NULL ;
}
static int F_34 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_35 ( struct V_1 * V_2 )
{
}
static int F_36 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
if ( V_51 -> type != V_52 && V_51 -> type != V_47 )
return - V_53 ;
return 0 ;
}
static void F_37 ( struct V_54 * V_55 , const char V_56 )
{
struct V_1 * V_2 = & ( V_57 + V_55 -> V_58 ) -> V_2 ;
unsigned long V_22 ;
unsigned long V_46 ;
F_29 ( & V_2 -> V_45 , V_46 ) ;
while ( ( ( V_22 = F_2 ( V_2 -> V_3 + V_4 ) ) &
V_5 ) == 0 ) {
if ( ( V_22 & V_59 ) == 0 ) {
F_30 ( & V_2 -> V_45 , V_46 ) ;
return;
}
F_30 ( & V_2 -> V_45 , V_46 ) ;
F_38 () ;
F_29 ( & V_2 -> V_45 , V_46 ) ;
}
F_7 ( V_56 , V_2 -> V_3 + V_23 ) ;
F_30 ( & V_2 -> V_45 , V_46 ) ;
}
static void F_37 ( struct V_54 * V_55 , const char V_56 )
{
struct V_1 * V_2 = & ( V_57 + V_55 -> V_58 ) -> V_2 ;
unsigned long V_46 ;
F_29 ( & V_2 -> V_45 , V_46 ) ;
while ( ( F_2 ( V_2 -> V_3 + V_4 ) &
V_5 ) == 0 ) {
F_30 ( & V_2 -> V_45 , V_46 ) ;
F_38 () ;
F_29 ( & V_2 -> V_45 , V_46 ) ;
}
F_7 ( V_56 , V_2 -> V_3 + V_23 ) ;
F_30 ( & V_2 -> V_45 , V_46 ) ;
}
static void F_39 ( struct V_54 * V_55 , const char * V_60 ,
unsigned int V_33 )
{
for (; V_33 ; V_33 -- , V_60 ++ ) {
F_37 ( V_55 , * V_60 ) ;
if ( * V_60 == '\n' )
F_37 ( V_55 , '\r' ) ;
}
}
static int T_2 F_40 ( struct V_54 * V_55 ,
char * V_61 )
{
struct V_1 * V_2 ;
if ( V_55 -> V_58 < 0 || V_55 -> V_58 >= V_62 )
return - V_53 ;
V_2 = & V_57 [ V_55 -> V_58 ] . V_2 ;
if ( V_2 -> V_3 == NULL )
return - V_63 ;
return 0 ;
}
static int T_2 F_41 ( void )
{
F_42 ( & V_64 ) ;
return 0 ;
}
static int F_43 ( struct V_65 * V_66 )
{
struct V_67 * V_68 = V_66 -> V_69 . V_70 ;
struct V_1 * V_2 ;
struct V_71 * V_72 , * V_73 ;
int V_74 = V_66 -> V_75 ;
if ( V_74 == - 1 )
V_74 = 0 ;
if ( V_74 >= V_62 )
return - V_53 ;
V_2 = & V_57 [ V_74 ] . V_2 ;
V_73 = F_44 ( V_66 , V_76 , 0 ) ;
if ( V_73 )
V_2 -> V_77 = V_73 -> V_78 ;
else if ( V_68 )
V_2 -> V_77 = V_68 -> V_77 ;
else
return - V_63 ;
V_72 = F_44 ( V_66 , V_79 , 0 ) ;
if ( V_72 )
V_2 -> V_41 = V_72 -> V_78 ;
else if ( V_68 )
V_2 -> V_41 = V_68 -> V_41 ;
else
return - V_63 ;
V_2 -> V_3 = F_45 ( V_2 -> V_77 , V_80 ) ;
if ( ! V_2 -> V_3 )
return - V_81 ;
V_2 -> line = V_74 ;
V_2 -> type = V_47 ;
V_2 -> V_82 = V_83 ;
V_2 -> V_84 = & V_85 ;
V_2 -> V_46 = V_86 ;
F_46 ( & V_87 , V_2 ) ;
return 0 ;
}
static int F_47 ( struct V_65 * V_66 )
{
struct V_1 * V_2 ;
int V_74 = V_66 -> V_75 ;
if ( V_74 == - 1 )
V_74 = 0 ;
V_2 = & V_57 [ V_74 ] . V_2 ;
F_48 ( & V_87 , V_2 ) ;
return 0 ;
}
static int T_2 F_49 ( void )
{
int V_88 ;
V_88 = F_50 ( & V_87 ) ;
if ( V_88 )
return V_88 ;
V_88 = F_51 ( & V_89 ) ;
if ( V_88 )
F_52 ( & V_87 ) ;
return V_88 ;
}
static void T_3 F_53 ( void )
{
F_54 ( & V_89 ) ;
F_52 ( & V_87 ) ;
}
