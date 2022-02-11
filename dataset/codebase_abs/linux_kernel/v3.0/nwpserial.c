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
struct V_31 * V_32 = V_2 -> V_9 . V_33 -> V_9 . V_32 ;
T_1 V_34 ;
unsigned int V_35 ;
unsigned char V_36 ;
F_17 ( & V_2 -> V_9 . V_24 ) ;
V_35 = F_2 ( V_2 -> V_6 , V_37 ) ;
if ( ! V_35 ) {
V_34 = V_38 ;
goto V_39;
}
do {
V_2 -> V_9 . V_13 . V_40 ++ ;
V_36 = F_2 ( V_2 -> V_6 , V_41 ) ;
if ( V_2 -> V_9 . V_42 != V_43 )
F_18 ( V_32 , V_36 , V_44 ) ;
} while ( F_2 ( V_2 -> V_6 , V_7 ) & V_45 );
F_19 ( V_32 ) ;
V_34 = V_46 ;
F_6 ( V_2 -> V_6 , V_37 , 1 ) ;
V_39:
F_20 ( & V_2 -> V_9 . V_24 ) ;
return V_34 ;
}
static int F_21 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
int V_47 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_48 = F_2 ( V_2 -> V_6 , V_49 ) & ~ V_50 ;
F_6 ( V_2 -> V_6 , V_49 , V_2 -> V_48 ) ;
V_47 = F_22 ( V_2 -> V_9 . V_29 , F_16 ,
V_51 , L_1 , V_2 ) ;
if ( V_47 )
return V_47 ;
V_2 -> V_25 = V_27 ;
F_6 ( V_2 -> V_6 , V_26 , V_2 -> V_25 ) ;
V_2 -> V_9 . V_42 &= ~ V_43 ;
return 0 ;
}
static void F_23 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_9 . V_42 |= V_43 ;
V_2 -> V_25 = 0 ;
F_6 ( V_2 -> V_6 , V_26 , V_2 -> V_25 ) ;
F_24 ( V_2 -> V_9 . V_29 , V_9 ) ;
}
static int F_25 ( struct V_8 * V_9 ,
struct V_52 * V_53 )
{
return - V_54 ;
}
static const char * F_26 ( struct V_8 * V_9 )
{
return V_9 -> type == V_28 ? L_1 : NULL ;
}
static void F_27 ( struct V_8 * V_9 ,
struct V_55 * V_56 , struct V_55 * V_57 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_9 . V_58 = V_43
| V_59 ;
V_2 -> V_9 . V_42 = 0 ;
if ( ( V_56 -> V_60 & V_61 ) == 0 )
V_2 -> V_9 . V_42 |= V_43 ;
if ( V_57 )
F_28 ( V_56 , V_57 ) ;
}
static void F_29 ( struct V_8 * V_9 , int V_62 )
{
}
static void F_30 ( struct V_8 * V_9 )
{
}
static void F_31 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_2 -> V_9 . V_42 = V_43 ;
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
struct V_63 * V_64 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
V_64 = & V_2 -> V_9 . V_33 -> V_64 ;
if ( V_9 -> V_65 ) {
F_32 ( V_2 , V_2 -> V_9 . V_65 ) ;
V_9 -> V_65 = 0 ;
}
while ( ! ( F_34 ( V_64 ) || F_35 ( & V_2 -> V_9 ) ) ) {
F_32 ( V_2 , V_64 -> V_66 [ V_64 -> V_67 ] ) ;
V_64 -> V_67 = ( V_64 -> V_67 + 1 ) & ( V_68 - 1 ) ;
}
}
static unsigned int F_36 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_37 ( struct V_8 * V_9 , unsigned int V_69 )
{
}
static void F_38 ( struct V_8 * V_9 )
{
}
static unsigned int F_39 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
unsigned long V_21 ;
int V_34 ;
V_2 = F_5 ( V_9 , struct V_1 , V_9 ) ;
F_9 ( & V_2 -> V_9 . V_24 , V_21 ) ;
V_34 = F_2 ( V_2 -> V_6 , V_7 ) ;
F_12 ( & V_2 -> V_9 . V_24 , V_21 ) ;
return V_34 & V_70 ? V_71 : 0 ;
}
int F_40 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = NULL ;
int V_34 = - 1 ;
int V_72 ;
static int V_73 = 1 ;
int V_74 ;
int V_75 ;
struct V_76 * V_77 ;
F_41 ( & V_78 ) ;
V_77 = V_9 -> V_79 -> V_80 ;
if ( V_77 == NULL )
goto V_39;
V_75 = F_42 ( V_77 , 0 ) ;
for ( V_72 = 0 ; V_72 < V_81 ; V_72 ++ )
if ( V_19 [ V_72 ] . V_9 . V_82 == V_75 ) {
V_2 = & V_19 [ V_72 ] ;
break;
}
if ( V_2 == NULL )
for ( V_72 = 0 ; V_72 < V_81 ; V_72 ++ )
if ( V_19 [ V_72 ] . V_9 . type == V_83 &&
V_19 [ V_72 ] . V_9 . V_82 == 0 ) {
V_2 = & V_19 [ V_72 ] ;
break;
}
if ( V_2 == NULL ) {
V_34 = - V_84 ;
goto V_39;
}
if ( V_73 )
F_43 ( & V_85 ) ;
V_73 = 0 ;
V_2 -> V_9 . V_86 = V_9 -> V_86 ;
V_2 -> V_9 . V_29 = V_9 -> V_29 ;
V_2 -> V_9 . V_87 = V_9 -> V_87 ;
V_2 -> V_9 . V_88 = V_9 -> V_88 ;
V_2 -> V_9 . V_89 = V_9 -> V_89 ;
V_2 -> V_9 . V_90 = V_9 -> V_90 ;
V_2 -> V_9 . V_21 = V_9 -> V_21 ;
V_2 -> V_9 . V_91 = V_9 -> V_91 ;
V_2 -> V_9 . V_92 = V_9 -> V_92 ;
if ( V_9 -> V_79 )
V_2 -> V_9 . V_79 = V_9 -> V_79 ;
if ( V_2 -> V_9 . V_82 != V_75 ) {
V_2 -> V_9 . V_93 = & V_94 ;
V_2 -> V_9 . V_88 = 16 ;
F_44 ( & V_2 -> V_9 . V_24 ) ;
V_2 -> V_9 . V_82 = V_75 ;
V_74 = F_45 ( V_77 , 0 ) ;
V_2 -> V_6 = F_46 ( V_77 , V_75 , V_74 ) ;
if ( ! F_47 ( V_2 -> V_6 ) ) {
F_48 ( V_95 L_2 ) ;
goto V_39;
}
}
V_34 = F_49 ( & V_85 , & V_2 -> V_9 ) ;
if ( V_34 == 0 )
V_34 = V_2 -> V_9 . line ;
V_39:
F_50 ( & V_78 ) ;
return V_34 ;
}
void F_51 ( int line )
{
struct V_1 * V_2 = & V_19 [ line ] ;
F_41 ( & V_78 ) ;
F_52 ( & V_85 , & V_2 -> V_9 ) ;
V_2 -> V_9 . type = V_83 ;
F_50 ( & V_78 ) ;
}
static int T_2 F_53 ( void )
{
struct V_1 * V_2 = NULL ;
struct V_76 * V_77 ;
const char * V_96 ;
int V_75 ;
int V_74 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_81 ; V_72 ++ )
if ( V_19 [ V_72 ] . V_9 . type == V_83 ) {
V_2 = & V_19 [ V_72 ] ;
break;
}
if ( V_2 == NULL )
return - 1 ;
V_96 = F_54 ( V_97 , L_3 , NULL ) ;
if ( V_96 == NULL )
return - 1 ;
V_77 = F_55 ( V_96 ) ;
if ( ! V_77 )
return - 1 ;
F_44 ( & V_2 -> V_9 . V_24 ) ;
V_2 -> V_9 . V_93 = & V_94 ;
V_2 -> V_9 . type = V_28 ;
V_2 -> V_9 . V_88 = 16 ;
V_75 = F_42 ( V_77 , 0 ) ;
V_74 = F_45 ( V_77 , 0 ) ;
V_2 -> V_9 . V_82 = V_75 ;
V_2 -> V_6 = F_46 ( V_77 , V_75 , V_74 ) ;
if ( ! F_47 ( V_2 -> V_6 ) ) {
F_48 ( L_4 ) ;
return - 1 ;
}
F_56 ( & V_98 ) ;
return 0 ;
}
