static struct V_1 * F_1 ( void )
{
return V_2 ;
}
static T_1 F_2 ( void )
{
struct V_1 * V_3 = F_1 () ;
return V_3 -> V_4 ;
}
static void
F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_3 =
F_4 ( V_6 , struct V_1 , V_7 ) ;
struct V_8 * V_9 ;
bool V_10 = false ;
bool V_11 = false ;
F_5 ( & V_3 -> V_12 ) ;
V_9 = V_3 -> V_13 [ V_14 ] ;
for (; ; ) {
struct V_15 * V_16 ;
struct V_17 V_18 , V_19 , * V_20 [ 2 ] ;
int V_21 , V_22 = 0 , V_23 = 0 ;
bool V_24 ;
F_6 ( & V_3 -> V_25 ) ;
if ( F_7 ( & V_3 -> V_26 ) ) {
F_8 ( & V_3 -> V_25 ) ;
break;
}
V_16 = F_9 ( & V_3 -> V_26 ,
struct V_15 , V_27 ) ;
F_10 ( & V_16 -> V_27 ) ;
F_8 ( & V_3 -> V_25 ) ;
V_24 = V_16 -> V_24 ;
F_11 ( & V_18 , & V_16 -> V_18 , sizeof( V_16 -> V_18 ) ) ;
V_20 [ V_23 ++ ] = & V_18 ;
if ( V_16 -> V_19 ) {
F_11 ( & V_19 , V_16 -> V_19 , V_16 -> V_28 ) ;
V_20 [ V_23 ++ ] = & V_19 ;
}
V_21 = F_12 ( V_9 , V_20 , V_23 , V_22 , V_16 , V_29 ) ;
if ( V_21 < 0 ) {
F_6 ( & V_3 -> V_25 ) ;
F_13 ( & V_16 -> V_27 , & V_3 -> V_26 ) ;
F_8 ( & V_3 -> V_25 ) ;
break;
}
if ( V_24 ) {
struct V_8 * V_30 = V_3 -> V_13 [ V_31 ] ;
int V_32 ;
V_32 = F_14 ( & V_3 -> V_33 ) ;
if ( V_32 + 1 == F_15 ( V_30 ) )
V_11 = true ;
}
V_10 = true ;
}
if ( V_10 )
F_16 ( V_9 ) ;
F_17 ( & V_3 -> V_12 ) ;
if ( V_11 )
F_18 ( V_34 , & V_3 -> V_35 ) ;
}
static int
F_19 ( struct V_15 * V_16 )
{
struct V_1 * V_3 ;
int V_28 = V_16 -> V_28 ;
V_3 = F_1 () ;
if ( ! V_3 ) {
F_20 ( V_16 ) ;
return - V_36 ;
}
if ( V_16 -> V_24 )
F_21 ( & V_3 -> V_33 ) ;
F_6 ( & V_3 -> V_25 ) ;
F_22 ( & V_16 -> V_27 , & V_3 -> V_26 ) ;
F_8 ( & V_3 -> V_25 ) ;
F_18 ( V_34 , & V_3 -> V_7 ) ;
return V_28 ;
}
static void F_23 ( struct V_1 * V_3 )
{
int V_37 = V_38 ;
struct V_15 * V_16 ;
struct V_17 V_18 , V_19 , * V_20 [ 2 ] ;
struct V_8 * V_9 ;
int V_21 ;
V_9 = V_3 -> V_13 [ V_31 ] ;
do {
V_16 = F_24 ( sizeof( * V_16 ) , V_29 ) ;
if ( ! V_16 )
break;
V_16 -> V_19 = F_25 ( V_37 , V_29 ) ;
if ( ! V_16 -> V_19 ) {
F_20 ( V_16 ) ;
break;
}
V_16 -> V_28 = V_37 ;
F_11 ( & V_18 , & V_16 -> V_18 , sizeof( V_16 -> V_18 ) ) ;
V_20 [ 0 ] = & V_18 ;
F_11 ( & V_19 , V_16 -> V_19 , V_37 ) ;
V_20 [ 1 ] = & V_19 ;
V_21 = F_12 ( V_9 , V_20 , 0 , 2 , V_16 , V_29 ) ;
if ( V_21 ) {
F_20 ( V_16 ) ;
break;
}
V_3 -> V_39 ++ ;
} while ( V_9 -> V_40 );
if ( V_3 -> V_39 > V_3 -> V_41 )
V_3 -> V_41 = V_3 -> V_39 ;
F_16 ( V_9 ) ;
}
static void F_26 ( struct V_5 * V_6 )
{
struct V_1 * V_3 =
F_4 ( V_6 , struct V_1 , V_42 ) ;
struct V_8 * V_9 ;
bool V_10 = false ;
V_9 = V_3 -> V_13 [ V_14 ] ;
F_5 ( & V_3 -> V_12 ) ;
do {
struct V_15 * V_16 ;
unsigned int V_28 ;
F_27 ( V_9 ) ;
while ( ( V_16 = F_28 ( V_9 , & V_28 ) ) != NULL ) {
F_20 ( V_16 ) ;
V_10 = true ;
}
} while ( ! F_29 ( V_9 ) );
F_17 ( & V_3 -> V_12 ) ;
if ( V_10 )
F_18 ( V_34 , & V_3 -> V_7 ) ;
}
static bool F_30 ( struct V_1 * V_3 )
{
struct V_8 * V_9 = V_3 -> V_13 [ V_31 ] ;
int V_32 ;
F_31 () ;
V_32 = F_32 ( & V_3 -> V_33 ) ;
return V_32 < F_15 ( V_9 ) ;
}
static void F_33 ( struct V_5 * V_6 )
{
struct V_1 * V_3 =
F_4 ( V_6 , struct V_1 , V_35 ) ;
struct V_8 * V_9 ;
V_9 = V_3 -> V_13 [ V_31 ] ;
F_5 ( & V_3 -> V_43 ) ;
do {
F_27 ( V_9 ) ;
for (; ; ) {
struct V_15 * V_16 ;
unsigned int V_28 ;
if ( ! F_30 ( V_3 ) ) {
goto V_44;
}
V_16 = F_28 ( V_9 , & V_28 ) ;
if ( ! V_16 ) {
break;
}
V_3 -> V_39 -- ;
if ( F_34 ( V_28 < sizeof( V_16 -> V_18 ) ||
V_28 > sizeof( V_16 -> V_18 ) + V_16 -> V_28 ) ) {
F_20 ( V_16 ) ;
continue;
}
V_16 -> V_28 = V_28 - sizeof( V_16 -> V_18 ) ;
F_35 ( V_16 ) ;
}
} while ( ! F_29 ( V_9 ) );
V_44:
if ( V_3 -> V_39 < V_3 -> V_41 / 2 )
F_23 ( V_3 ) ;
F_17 ( & V_3 -> V_43 ) ;
}
static int F_36 ( struct V_1 * V_3 ,
struct V_45 * V_46 )
{
struct V_17 V_47 ;
struct V_8 * V_9 ;
V_9 = V_3 -> V_13 [ V_48 ] ;
F_11 ( & V_47 , V_46 , sizeof( * V_46 ) ) ;
return F_37 ( V_9 , & V_47 , 1 , V_46 , V_29 ) ;
}
static void F_38 ( struct V_1 * V_3 )
{
T_2 V_49 ;
for ( V_49 = 0 ; V_49 < F_39 ( V_3 -> V_50 ) ; V_49 ++ ) {
struct V_45 * V_46 = & V_3 -> V_50 [ V_49 ] ;
F_36 ( V_3 , V_46 ) ;
}
F_16 ( V_3 -> V_13 [ V_48 ] ) ;
}
static void F_40 ( struct V_51 * V_52 )
{
F_41 ( V_52 ) ;
V_52 -> V_53 = V_54 ;
V_52 -> V_55 = V_56 ;
V_52 -> V_57 ( V_52 ) ;
F_42 ( V_52 ) ;
}
static void F_43 ( struct V_1 * V_3 )
{
struct V_58 * V_59 = V_3 -> V_59 ;
T_3 V_4 ;
V_59 -> V_60 -> V_61 ( V_59 , F_44 ( struct V_62 , V_4 ) ,
& V_4 , sizeof( V_4 ) ) ;
V_3 -> V_4 = F_45 ( V_4 ) ;
}
static void F_46 ( struct V_1 * V_3 ,
struct V_45 * V_46 )
{
switch ( F_47 ( V_46 -> V_63 ) ) {
case V_64 :
F_43 ( V_3 ) ;
F_48 ( F_40 ) ;
break;
}
}
static void F_49 ( struct V_5 * V_6 )
{
struct V_1 * V_3 =
F_4 ( V_6 , struct V_1 , V_65 ) ;
struct V_8 * V_9 ;
V_9 = V_3 -> V_13 [ V_48 ] ;
F_5 ( & V_3 -> V_66 ) ;
do {
struct V_45 * V_46 ;
unsigned int V_28 ;
F_27 ( V_9 ) ;
while ( ( V_46 = F_28 ( V_9 , & V_28 ) ) != NULL ) {
if ( V_28 == sizeof( * V_46 ) )
F_46 ( V_3 , V_46 ) ;
F_36 ( V_3 , V_46 ) ;
}
} while ( ! F_29 ( V_9 ) );
F_16 ( V_3 -> V_13 [ V_48 ] ) ;
F_17 ( & V_3 -> V_66 ) ;
}
static void F_50 ( struct V_8 * V_9 )
{
struct V_1 * V_3 = V_9 -> V_59 -> V_67 ;
if ( ! V_3 )
return;
F_18 ( V_34 , & V_3 -> V_65 ) ;
}
static void F_51 ( struct V_8 * V_9 )
{
struct V_1 * V_3 = V_9 -> V_59 -> V_67 ;
if ( ! V_3 )
return;
F_18 ( V_34 , & V_3 -> V_42 ) ;
}
static void F_52 ( struct V_8 * V_9 )
{
struct V_1 * V_3 = V_9 -> V_59 -> V_67 ;
if ( ! V_3 )
return;
F_18 ( V_34 , & V_3 -> V_35 ) ;
}
static int F_53 ( struct V_58 * V_59 )
{
T_4 * V_68 [] = {
F_52 ,
F_51 ,
F_50 ,
} ;
static const char * const V_69 [] = {
L_1 ,
L_2 ,
L_3 ,
} ;
struct V_1 * V_3 = NULL ;
int V_21 ;
V_21 = F_54 ( & V_70 ) ;
if ( V_21 )
return V_21 ;
if ( V_2 ) {
V_21 = - V_71 ;
goto V_44;
}
V_3 = F_24 ( sizeof( * V_3 ) , V_29 ) ;
if ( ! V_3 ) {
V_21 = - V_72 ;
goto V_44;
}
V_3 -> V_59 = V_59 ;
V_21 = V_3 -> V_59 -> V_60 -> V_73 ( V_3 -> V_59 , V_74 ,
V_3 -> V_13 , V_68 , V_69 ) ;
if ( V_21 < 0 )
goto V_44;
F_43 ( V_3 ) ;
V_21 = F_55 ( & V_75 . V_76 ) ;
if ( V_21 < 0 )
goto V_77;
V_3 -> V_39 = 0 ;
V_3 -> V_41 = 0 ;
F_56 ( & V_3 -> V_33 , 0 ) ;
V_59 -> V_67 = V_3 ;
V_2 = V_3 ;
F_57 ( & V_3 -> V_12 ) ;
F_57 ( & V_3 -> V_43 ) ;
F_57 ( & V_3 -> V_66 ) ;
F_58 ( & V_3 -> V_25 ) ;
F_59 ( & V_3 -> V_26 ) ;
F_60 ( & V_3 -> V_35 , F_33 ) ;
F_60 ( & V_3 -> V_42 , F_26 ) ;
F_60 ( & V_3 -> V_65 , F_49 ) ;
F_60 ( & V_3 -> V_7 , F_3 ) ;
F_5 ( & V_3 -> V_43 ) ;
F_23 ( V_3 ) ;
F_17 ( & V_3 -> V_43 ) ;
F_5 ( & V_3 -> V_66 ) ;
F_38 ( V_3 ) ;
F_17 ( & V_3 -> V_66 ) ;
F_17 ( & V_70 ) ;
return 0 ;
V_77:
V_3 -> V_59 -> V_60 -> V_78 ( V_3 -> V_59 ) ;
V_44:
F_61 ( V_3 ) ;
F_17 ( & V_70 ) ;
return V_21 ;
}
static void F_62 ( struct V_58 * V_59 )
{
struct V_1 * V_3 = V_59 -> V_67 ;
struct V_15 * V_16 ;
F_63 ( & V_3 -> V_35 ) ;
F_63 ( & V_3 -> V_42 ) ;
F_63 ( & V_3 -> V_65 ) ;
F_63 ( & V_3 -> V_7 ) ;
V_59 -> V_60 -> V_79 ( V_59 ) ;
F_5 ( & V_3 -> V_43 ) ;
while ( ( V_16 = F_64 ( V_3 -> V_13 [ V_31 ] ) ) )
F_20 ( V_16 ) ;
F_17 ( & V_3 -> V_43 ) ;
F_5 ( & V_3 -> V_12 ) ;
while ( ( V_16 = F_64 ( V_3 -> V_13 [ V_14 ] ) ) )
F_20 ( V_16 ) ;
F_17 ( & V_3 -> V_12 ) ;
F_6 ( & V_3 -> V_25 ) ;
while ( ! F_7 ( & V_3 -> V_26 ) ) {
V_16 = F_9 ( & V_3 -> V_26 ,
struct V_15 , V_27 ) ;
F_65 ( & V_16 -> V_27 ) ;
F_20 ( V_16 ) ;
}
F_8 ( & V_3 -> V_25 ) ;
F_5 ( & V_70 ) ;
V_2 = NULL ;
F_66 () ;
F_17 ( & V_70 ) ;
V_59 -> V_60 -> V_78 ( V_59 ) ;
F_61 ( V_3 ) ;
}
static int T_5 F_67 ( void )
{
int V_21 ;
V_34 = F_68 ( L_4 , 0 , 0 ) ;
if ( ! V_34 )
return - V_72 ;
V_21 = F_69 ( & V_80 ) ;
if ( V_21 )
F_70 ( V_34 ) ;
return V_21 ;
}
static void T_6 F_71 ( void )
{
F_72 ( & V_80 ) ;
F_70 ( V_34 ) ;
}
