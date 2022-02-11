static struct V_1 * F_1 ( void )
{
return V_2 ;
}
static T_1 F_2 ( void )
{
struct V_1 * V_3 = F_1 () ;
return V_3 -> V_4 ;
}
static void F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_3 =
F_4 ( V_6 , struct V_1 , V_7 ) ;
F_5 ( V_8 ) ;
F_6 ( & V_3 -> V_9 ) ;
F_7 ( & V_3 -> V_10 , & V_8 ) ;
F_8 ( & V_3 -> V_9 ) ;
F_9 ( & V_3 -> V_11 ) ;
while ( ! F_10 ( & V_8 ) ) {
struct V_12 * V_13 ;
V_13 = F_11 ( & V_8 , struct V_12 , V_14 ) ;
F_12 ( & V_13 -> V_14 ) ;
F_13 ( V_13 ) ;
}
F_14 ( & V_3 -> V_11 ) ;
}
static int F_15 ( struct V_1 * V_3 ,
struct V_12 * V_13 )
{
int V_15 = V_13 -> V_15 ;
F_6 ( & V_3 -> V_9 ) ;
F_16 ( & V_13 -> V_14 , & V_3 -> V_10 ) ;
F_8 ( & V_3 -> V_9 ) ;
F_17 ( V_16 , & V_3 -> V_7 ) ;
return V_15 ;
}
static void
F_18 ( struct V_5 * V_6 )
{
struct V_1 * V_3 =
F_4 ( V_6 , struct V_1 , V_17 ) ;
struct V_18 * V_19 ;
bool V_20 = false ;
bool V_21 = false ;
F_9 ( & V_3 -> V_22 ) ;
V_19 = V_3 -> V_23 [ V_24 ] ;
for (; ; ) {
struct V_12 * V_13 ;
struct V_25 V_26 , V_27 , * V_28 [ 2 ] ;
int V_29 , V_30 = 0 , V_31 = 0 ;
bool V_32 ;
F_6 ( & V_3 -> V_33 ) ;
if ( F_10 ( & V_3 -> V_34 ) ) {
F_8 ( & V_3 -> V_33 ) ;
break;
}
V_13 = F_11 ( & V_3 -> V_34 ,
struct V_12 , V_14 ) ;
F_12 ( & V_13 -> V_14 ) ;
F_8 ( & V_3 -> V_33 ) ;
V_32 = V_13 -> V_32 ;
F_19 ( & V_26 , & V_13 -> V_26 , sizeof( V_13 -> V_26 ) ) ;
V_28 [ V_31 ++ ] = & V_26 ;
if ( V_13 -> V_27 ) {
F_19 ( & V_27 , V_13 -> V_27 , V_13 -> V_15 ) ;
V_28 [ V_31 ++ ] = & V_27 ;
}
V_29 = F_20 ( V_19 , V_28 , V_31 , V_30 , V_13 , V_35 ) ;
if ( V_29 < 0 ) {
F_6 ( & V_3 -> V_33 ) ;
F_21 ( & V_13 -> V_14 , & V_3 -> V_34 ) ;
F_8 ( & V_3 -> V_33 ) ;
break;
}
if ( V_32 ) {
struct V_18 * V_36 = V_3 -> V_23 [ V_37 ] ;
int V_38 ;
V_38 = F_22 ( & V_3 -> V_39 ) ;
if ( V_38 + 1 == F_23 ( V_36 ) )
V_21 = true ;
}
V_20 = true ;
}
if ( V_20 )
F_24 ( V_19 ) ;
F_14 ( & V_3 -> V_22 ) ;
if ( V_21 )
F_17 ( V_16 , & V_3 -> V_40 ) ;
}
static int
F_25 ( struct V_12 * V_13 )
{
struct V_1 * V_3 ;
int V_15 = V_13 -> V_15 ;
V_3 = F_1 () ;
if ( ! V_3 ) {
F_26 ( V_13 ) ;
return - V_41 ;
}
if ( F_27 ( V_13 -> V_26 . V_42 ) == V_3 -> V_4 )
return F_15 ( V_3 , V_13 ) ;
if ( V_13 -> V_32 )
F_28 ( & V_3 -> V_39 ) ;
F_6 ( & V_3 -> V_33 ) ;
F_16 ( & V_13 -> V_14 , & V_3 -> V_34 ) ;
F_8 ( & V_3 -> V_33 ) ;
F_17 ( V_16 , & V_3 -> V_17 ) ;
return V_15 ;
}
static void F_29 ( struct V_1 * V_3 )
{
int V_43 = V_44 ;
struct V_12 * V_13 ;
struct V_25 V_26 , V_27 , * V_28 [ 2 ] ;
struct V_18 * V_19 ;
int V_29 ;
V_19 = V_3 -> V_23 [ V_37 ] ;
do {
V_13 = F_30 ( sizeof( * V_13 ) , V_35 ) ;
if ( ! V_13 )
break;
V_13 -> V_27 = F_31 ( V_43 , V_35 ) ;
if ( ! V_13 -> V_27 ) {
F_26 ( V_13 ) ;
break;
}
V_13 -> V_15 = V_43 ;
F_19 ( & V_26 , & V_13 -> V_26 , sizeof( V_13 -> V_26 ) ) ;
V_28 [ 0 ] = & V_26 ;
F_19 ( & V_27 , V_13 -> V_27 , V_43 ) ;
V_28 [ 1 ] = & V_27 ;
V_29 = F_20 ( V_19 , V_28 , 0 , 2 , V_13 , V_35 ) ;
if ( V_29 ) {
F_26 ( V_13 ) ;
break;
}
V_3 -> V_45 ++ ;
} while ( V_19 -> V_46 );
if ( V_3 -> V_45 > V_3 -> V_47 )
V_3 -> V_47 = V_3 -> V_45 ;
F_24 ( V_19 ) ;
}
static void F_32 ( struct V_5 * V_6 )
{
struct V_1 * V_3 =
F_4 ( V_6 , struct V_1 , V_48 ) ;
struct V_18 * V_19 ;
bool V_20 = false ;
V_19 = V_3 -> V_23 [ V_24 ] ;
F_9 ( & V_3 -> V_22 ) ;
do {
struct V_12 * V_13 ;
unsigned int V_15 ;
F_33 ( V_19 ) ;
while ( ( V_13 = F_34 ( V_19 , & V_15 ) ) != NULL ) {
F_26 ( V_13 ) ;
V_20 = true ;
}
} while ( ! F_35 ( V_19 ) );
F_14 ( & V_3 -> V_22 ) ;
if ( V_20 )
F_17 ( V_16 , & V_3 -> V_17 ) ;
}
static bool F_36 ( struct V_1 * V_3 )
{
struct V_18 * V_19 = V_3 -> V_23 [ V_37 ] ;
int V_38 ;
F_37 () ;
V_38 = F_38 ( & V_3 -> V_39 ) ;
return V_38 < F_23 ( V_19 ) ;
}
static void F_39 ( struct V_5 * V_6 )
{
struct V_1 * V_3 =
F_4 ( V_6 , struct V_1 , V_40 ) ;
struct V_18 * V_19 ;
V_19 = V_3 -> V_23 [ V_37 ] ;
F_9 ( & V_3 -> V_11 ) ;
do {
F_33 ( V_19 ) ;
for (; ; ) {
struct V_12 * V_13 ;
unsigned int V_15 ;
if ( ! F_36 ( V_3 ) ) {
goto V_49;
}
V_13 = F_34 ( V_19 , & V_15 ) ;
if ( ! V_13 ) {
break;
}
V_3 -> V_45 -- ;
if ( F_40 ( V_15 < sizeof( V_13 -> V_26 ) ||
V_15 > sizeof( V_13 -> V_26 ) + V_13 -> V_15 ) ) {
F_26 ( V_13 ) ;
continue;
}
V_13 -> V_15 = V_15 - sizeof( V_13 -> V_26 ) ;
F_13 ( V_13 ) ;
}
} while ( ! F_35 ( V_19 ) );
V_49:
if ( V_3 -> V_45 < V_3 -> V_47 / 2 )
F_29 ( V_3 ) ;
F_14 ( & V_3 -> V_11 ) ;
}
static int F_41 ( struct V_1 * V_3 ,
struct V_50 * V_51 )
{
struct V_25 V_52 ;
struct V_18 * V_19 ;
V_19 = V_3 -> V_23 [ V_53 ] ;
F_19 ( & V_52 , V_51 , sizeof( * V_51 ) ) ;
return F_42 ( V_19 , & V_52 , 1 , V_51 , V_35 ) ;
}
static void F_43 ( struct V_1 * V_3 )
{
T_2 V_54 ;
for ( V_54 = 0 ; V_54 < F_44 ( V_3 -> V_55 ) ; V_54 ++ ) {
struct V_50 * V_51 = & V_3 -> V_55 [ V_54 ] ;
F_41 ( V_3 , V_51 ) ;
}
F_24 ( V_3 -> V_23 [ V_53 ] ) ;
}
static void F_45 ( struct V_56 * V_57 )
{
F_46 ( V_57 ) ;
V_57 -> V_58 = V_59 ;
V_57 -> V_60 = V_61 ;
V_57 -> V_62 ( V_57 ) ;
F_47 ( V_57 ) ;
}
static void F_48 ( struct V_1 * V_3 )
{
struct V_63 * V_64 = V_3 -> V_64 ;
T_3 V_4 ;
V_64 -> V_65 -> V_66 ( V_64 , F_49 ( struct V_67 , V_4 ) ,
& V_4 , sizeof( V_4 ) ) ;
V_3 -> V_4 = F_50 ( V_4 ) ;
}
static void F_51 ( struct V_1 * V_3 ,
struct V_50 * V_51 )
{
switch ( F_27 ( V_51 -> V_68 ) ) {
case V_69 :
F_48 ( V_3 ) ;
F_52 ( F_45 ) ;
break;
}
}
static void F_53 ( struct V_5 * V_6 )
{
struct V_1 * V_3 =
F_4 ( V_6 , struct V_1 , V_70 ) ;
struct V_18 * V_19 ;
V_19 = V_3 -> V_23 [ V_53 ] ;
F_9 ( & V_3 -> V_71 ) ;
do {
struct V_50 * V_51 ;
unsigned int V_15 ;
F_33 ( V_19 ) ;
while ( ( V_51 = F_34 ( V_19 , & V_15 ) ) != NULL ) {
if ( V_15 == sizeof( * V_51 ) )
F_51 ( V_3 , V_51 ) ;
F_41 ( V_3 , V_51 ) ;
}
} while ( ! F_35 ( V_19 ) );
F_24 ( V_3 -> V_23 [ V_53 ] ) ;
F_14 ( & V_3 -> V_71 ) ;
}
static void F_54 ( struct V_18 * V_19 )
{
struct V_1 * V_3 = V_19 -> V_64 -> V_72 ;
if ( ! V_3 )
return;
F_17 ( V_16 , & V_3 -> V_70 ) ;
}
static void F_55 ( struct V_18 * V_19 )
{
struct V_1 * V_3 = V_19 -> V_64 -> V_72 ;
if ( ! V_3 )
return;
F_17 ( V_16 , & V_3 -> V_48 ) ;
}
static void F_56 ( struct V_18 * V_19 )
{
struct V_1 * V_3 = V_19 -> V_64 -> V_72 ;
if ( ! V_3 )
return;
F_17 ( V_16 , & V_3 -> V_40 ) ;
}
static int F_57 ( struct V_63 * V_64 )
{
T_4 * V_73 [] = {
F_56 ,
F_55 ,
F_54 ,
} ;
static const char * const V_74 [] = {
L_1 ,
L_2 ,
L_3 ,
} ;
struct V_1 * V_3 = NULL ;
int V_29 ;
V_29 = F_58 ( & V_75 ) ;
if ( V_29 )
return V_29 ;
if ( V_2 ) {
V_29 = - V_76 ;
goto V_49;
}
V_3 = F_30 ( sizeof( * V_3 ) , V_35 ) ;
if ( ! V_3 ) {
V_29 = - V_77 ;
goto V_49;
}
V_3 -> V_64 = V_64 ;
V_29 = V_3 -> V_64 -> V_65 -> V_78 ( V_3 -> V_64 , V_79 ,
V_3 -> V_23 , V_73 , V_74 ) ;
if ( V_29 < 0 )
goto V_49;
F_48 ( V_3 ) ;
V_29 = F_59 ( & V_80 . V_81 ) ;
if ( V_29 < 0 )
goto V_82;
V_3 -> V_45 = 0 ;
V_3 -> V_47 = 0 ;
F_60 ( & V_3 -> V_39 , 0 ) ;
V_64 -> V_72 = V_3 ;
V_2 = V_3 ;
F_61 ( & V_3 -> V_22 ) ;
F_61 ( & V_3 -> V_11 ) ;
F_61 ( & V_3 -> V_71 ) ;
F_62 ( & V_3 -> V_33 ) ;
F_63 ( & V_3 -> V_34 ) ;
F_62 ( & V_3 -> V_9 ) ;
F_63 ( & V_3 -> V_10 ) ;
F_64 ( & V_3 -> V_40 , F_39 ) ;
F_64 ( & V_3 -> V_48 , F_32 ) ;
F_64 ( & V_3 -> V_70 , F_53 ) ;
F_64 ( & V_3 -> V_17 , F_18 ) ;
F_64 ( & V_3 -> V_7 , F_3 ) ;
F_9 ( & V_3 -> V_11 ) ;
F_29 ( V_3 ) ;
F_14 ( & V_3 -> V_11 ) ;
F_9 ( & V_3 -> V_71 ) ;
F_43 ( V_3 ) ;
F_14 ( & V_3 -> V_71 ) ;
F_14 ( & V_75 ) ;
return 0 ;
V_82:
V_3 -> V_64 -> V_65 -> V_83 ( V_3 -> V_64 ) ;
V_49:
F_65 ( V_3 ) ;
F_14 ( & V_75 ) ;
return V_29 ;
}
static void F_66 ( struct V_63 * V_64 )
{
struct V_1 * V_3 = V_64 -> V_72 ;
struct V_12 * V_13 ;
F_67 ( & V_3 -> V_7 ) ;
F_67 ( & V_3 -> V_40 ) ;
F_67 ( & V_3 -> V_48 ) ;
F_67 ( & V_3 -> V_70 ) ;
F_67 ( & V_3 -> V_17 ) ;
V_64 -> V_65 -> V_84 ( V_64 ) ;
F_9 ( & V_3 -> V_11 ) ;
while ( ( V_13 = F_68 ( V_3 -> V_23 [ V_37 ] ) ) )
F_26 ( V_13 ) ;
F_14 ( & V_3 -> V_11 ) ;
F_9 ( & V_3 -> V_22 ) ;
while ( ( V_13 = F_68 ( V_3 -> V_23 [ V_24 ] ) ) )
F_26 ( V_13 ) ;
F_14 ( & V_3 -> V_22 ) ;
F_6 ( & V_3 -> V_33 ) ;
while ( ! F_10 ( & V_3 -> V_34 ) ) {
V_13 = F_11 ( & V_3 -> V_34 ,
struct V_12 , V_14 ) ;
F_69 ( & V_13 -> V_14 ) ;
F_26 ( V_13 ) ;
}
F_8 ( & V_3 -> V_33 ) ;
F_6 ( & V_3 -> V_9 ) ;
while ( ! F_10 ( & V_3 -> V_10 ) ) {
V_13 = F_11 ( & V_3 -> V_10 ,
struct V_12 , V_14 ) ;
F_69 ( & V_13 -> V_14 ) ;
F_26 ( V_13 ) ;
}
F_8 ( & V_3 -> V_9 ) ;
F_9 ( & V_75 ) ;
V_2 = NULL ;
F_70 () ;
F_14 ( & V_75 ) ;
V_64 -> V_65 -> V_83 ( V_64 ) ;
F_65 ( V_3 ) ;
}
static int T_5 F_71 ( void )
{
int V_29 ;
V_16 = F_72 ( L_4 , 0 , 0 ) ;
if ( ! V_16 )
return - V_77 ;
V_29 = F_73 ( & V_85 ) ;
if ( V_29 )
F_74 ( V_16 ) ;
return V_29 ;
}
static void T_6 F_75 ( void )
{
F_76 ( & V_85 ) ;
F_74 ( V_16 ) ;
}
