static void F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 , V_5 = 10000 ;
do {
V_4 = F_2 ( V_2 -> V_6 , V_7 ) ;
if ( -- V_5 == 0 )
break;
F_3 ( 1 ) ;
} while ( ( V_4 & V_3 ) != V_3 );
}
static void F_4 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
F_1 ( V_2 , V_11 ) ;
F_6 ( V_2 -> V_6 , V_12 , V_10 ) ;
V_2 -> V_9 . V_13 . V_14 ++ ;
}
static void
F_7 ( struct V_15 * V_16 , const char * V_17 , unsigned int V_18 )
{
struct V_1 * V_2 = & V_19 [ V_16 -> V_20 ] ;
unsigned long V_21 ;
int V_22 = 1 ;
if ( V_23 )
V_22 = F_8 ( & V_2 -> V_9 . V_24 , V_21 ) ;
else
F_9 ( & V_2 -> V_9 . V_24 , V_21 ) ;
V_2 -> V_25 = F_2 ( V_2 -> V_6 , V_26 ) ;
F_6 ( V_2 -> V_6 , V_26 , V_2 -> V_25 & ~ V_27 ) ;
F_10 ( & V_2 -> V_9 , V_17 , V_18 , F_4 ) ;
while ( ( F_2 ( V_2 -> V_6 , V_7 ) & V_11 ) == 0 )
F_11 () ;
F_6 ( V_2 -> V_6 , V_26 , V_2 -> V_25 ) ;
if ( V_22 )
F_12 ( & V_2 -> V_9 . V_24 , V_21 ) ;
}
static int F_13 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_14 ( struct V_8 * V_9 )
{
}
static void F_15 ( struct V_8 * V_9 , int V_21 )
{
V_9 -> type = V_28 ;
}
static T_1 F_16 ( int V_29 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
struct V_31 * V_9 = & V_2 -> V_9 . V_32 -> V_9 ;
T_1 V_33 ;
unsigned int V_34 ;
unsigned char V_35 ;
F_17 ( & V_2 -> V_9 . V_24 ) ;
V_34 = F_2 ( V_2 -> V_6 , V_36 ) ;
if ( ! V_34 ) {
V_33 = V_37 ;
goto V_38;
}
do {
V_2 -> V_9 . V_13 . V_39 ++ ;
V_35 = F_2 ( V_2 -> V_6 , V_40 ) ;
if ( V_2 -> V_9 . V_41 != V_42 )
F_18 ( V_9 , V_35 , V_43 ) ;
} while ( F_2 ( V_2 -> V_6 , V_7 ) & V_44 );
F_19 ( V_9 ) ;
V_33 = V_45 ;
F_6 ( V_2 -> V_6 , V_36 , 1 ) ;
V_38:
F_20 ( & V_2 -> V_9 . V_24 ) ;
return V_33 ;
}
static int F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_46 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_47 = F_2 ( V_2 -> V_6 , V_48 ) & ~ V_49 ;
F_6 ( V_2 -> V_6 , V_48 , V_2 -> V_47 ) ;
V_46 = F_22 ( V_2 -> V_9 . V_29 , F_16 ,
V_50 , L_1 , V_2 ) ;
if ( V_46 )
return V_46 ;
V_2 -> V_25 = V_27 ;
F_6 ( V_2 -> V_6 , V_26 , V_2 -> V_25 ) ;
V_2 -> V_9 . V_41 &= ~ V_42 ;
return 0 ;
}
static void F_23 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_9 . V_41 |= V_42 ;
V_2 -> V_25 = 0 ;
F_6 ( V_2 -> V_6 , V_26 , V_2 -> V_25 ) ;
F_24 ( V_2 -> V_9 . V_29 , V_9 ) ;
}
static int F_25 ( struct V_8 * V_9 ,
struct V_51 * V_52 )
{
return - V_53 ;
}
static const char * F_26 ( struct V_8 * V_9 )
{
return V_9 -> type == V_28 ? L_1 : NULL ;
}
static void F_27 ( struct V_8 * V_9 ,
struct V_54 * V_55 , struct V_54 * V_56 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_9 . V_57 = V_42
| V_58 ;
V_2 -> V_9 . V_41 = 0 ;
if ( ( V_55 -> V_59 & V_60 ) == 0 )
V_2 -> V_9 . V_41 |= V_42 ;
if ( V_56 )
F_28 ( V_55 , V_56 ) ;
}
static void F_29 ( struct V_8 * V_9 , int V_61 )
{
}
static void F_30 ( struct V_8 * V_9 )
{
}
static void F_31 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_9 . V_41 = V_42 ;
}
static void F_32 ( struct V_1 * V_2 , unsigned char V_10 )
{
F_1 ( V_2 , V_11 ) ;
F_6 ( V_2 -> V_6 , V_12 , V_10 ) ;
V_2 -> V_9 . V_13 . V_14 ++ ;
}
static void F_33 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_62 * V_63 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_63 = & V_2 -> V_9 . V_32 -> V_63 ;
if ( V_9 -> V_64 ) {
F_32 ( V_2 , V_2 -> V_9 . V_64 ) ;
V_9 -> V_64 = 0 ;
}
while ( ! ( F_34 ( V_63 ) || F_35 ( & V_2 -> V_9 ) ) ) {
F_32 ( V_2 , V_63 -> V_65 [ V_63 -> V_66 ] ) ;
V_63 -> V_66 = ( V_63 -> V_66 + 1 ) & ( V_67 - 1 ) ;
}
}
static unsigned int F_36 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_37 ( struct V_8 * V_9 , unsigned int V_68 )
{
}
static void F_38 ( struct V_8 * V_9 )
{
}
static unsigned int F_39 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
unsigned long V_21 ;
int V_33 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
F_9 ( & V_2 -> V_9 . V_24 , V_21 ) ;
V_33 = F_2 ( V_2 -> V_6 , V_7 ) ;
F_12 ( & V_2 -> V_9 . V_24 , V_21 ) ;
return V_33 & V_69 ? V_70 : 0 ;
}
int F_40 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = NULL ;
int V_33 = - 1 ;
int V_71 ;
static int V_72 = 1 ;
int V_73 ;
int V_74 ;
struct V_75 * V_76 ;
F_41 ( & V_77 ) ;
V_76 = V_9 -> V_78 -> V_79 ;
if ( V_76 == NULL )
goto V_38;
V_74 = F_42 ( V_76 , 0 ) ;
for ( V_71 = 0 ; V_71 < V_80 ; V_71 ++ )
if ( V_19 [ V_71 ] . V_9 . V_81 == V_74 ) {
V_2 = & V_19 [ V_71 ] ;
break;
}
if ( V_2 == NULL )
for ( V_71 = 0 ; V_71 < V_80 ; V_71 ++ )
if ( V_19 [ V_71 ] . V_9 . type == V_82 &&
V_19 [ V_71 ] . V_9 . V_81 == 0 ) {
V_2 = & V_19 [ V_71 ] ;
break;
}
if ( V_2 == NULL ) {
V_33 = - V_83 ;
goto V_38;
}
if ( V_72 )
F_43 ( & V_84 ) ;
V_72 = 0 ;
V_2 -> V_9 . V_85 = V_9 -> V_85 ;
V_2 -> V_9 . V_29 = V_9 -> V_29 ;
V_2 -> V_9 . V_86 = V_9 -> V_86 ;
V_2 -> V_9 . V_87 = V_9 -> V_87 ;
V_2 -> V_9 . V_88 = V_9 -> V_88 ;
V_2 -> V_9 . V_89 = V_9 -> V_89 ;
V_2 -> V_9 . V_21 = V_9 -> V_21 ;
V_2 -> V_9 . V_90 = V_9 -> V_90 ;
V_2 -> V_9 . V_91 = V_9 -> V_91 ;
if ( V_9 -> V_78 )
V_2 -> V_9 . V_78 = V_9 -> V_78 ;
if ( V_2 -> V_9 . V_81 != V_74 ) {
V_2 -> V_9 . V_92 = & V_93 ;
V_2 -> V_9 . V_87 = 16 ;
F_44 ( & V_2 -> V_9 . V_24 ) ;
V_2 -> V_9 . V_81 = V_74 ;
V_73 = F_45 ( V_76 , 0 ) ;
V_2 -> V_6 = F_46 ( V_76 , V_74 , V_73 ) ;
if ( ! F_47 ( V_2 -> V_6 ) ) {
F_48 ( V_94 L_2 ) ;
goto V_38;
}
}
V_33 = F_49 ( & V_84 , & V_2 -> V_9 ) ;
if ( V_33 == 0 )
V_33 = V_2 -> V_9 . line ;
V_38:
F_50 ( & V_77 ) ;
return V_33 ;
}
void F_51 ( int line )
{
struct V_1 * V_2 = & V_19 [ line ] ;
F_41 ( & V_77 ) ;
F_52 ( & V_84 , & V_2 -> V_9 ) ;
V_2 -> V_9 . type = V_82 ;
F_50 ( & V_77 ) ;
}
static int T_2 F_53 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_75 * V_76 ;
const char * V_95 ;
int V_74 ;
int V_73 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_80 ; V_71 ++ )
if ( V_19 [ V_71 ] . V_9 . type == V_82 ) {
V_2 = & V_19 [ V_71 ] ;
break;
}
if ( V_2 == NULL )
return - 1 ;
V_95 = F_54 ( V_96 , L_3 , NULL ) ;
if ( V_95 == NULL )
return - 1 ;
V_76 = F_55 ( V_95 ) ;
if ( ! V_76 )
return - 1 ;
F_44 ( & V_2 -> V_9 . V_24 ) ;
V_2 -> V_9 . V_92 = & V_93 ;
V_2 -> V_9 . type = V_28 ;
V_2 -> V_9 . V_87 = 16 ;
V_74 = F_42 ( V_76 , 0 ) ;
V_73 = F_45 ( V_76 , 0 ) ;
V_2 -> V_9 . V_81 = V_74 ;
V_2 -> V_6 = F_46 ( V_76 , V_74 , V_73 ) ;
if ( ! F_47 ( V_2 -> V_6 ) ) {
F_48 ( L_4 ) ;
return - 1 ;
}
F_56 ( & V_97 ) ;
return 0 ;
}
