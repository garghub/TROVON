static void F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = 0 ;
F_2 ( & V_5 ) ;
if ( V_3 ) {
if ( ! V_2 -> V_6 ) {
V_4 = ( V_7 == NULL ) ;
V_2 -> V_8 = V_9 ;
V_2 -> V_10 = NULL ;
V_9 = V_2 ;
if ( V_2 -> V_8 ) {
V_2 -> V_8 -> V_10 = V_2 ;
} else {
V_7 = V_2 ;
}
V_2 -> V_6 = ! 0 ;
}
} else {
if ( V_2 -> V_6 ) {
V_2 -> V_6 = 0 ;
if ( V_2 -> V_10 ) {
V_2 -> V_10 -> V_8 = V_2 -> V_8 ;
} else {
V_9 = V_2 -> V_8 ;
}
if ( V_2 -> V_8 ) {
V_2 -> V_8 -> V_10 = V_2 -> V_10 ;
} else {
V_7 = V_2 -> V_10 ;
}
}
}
F_3 ( & V_5 ) ;
if ( V_4 ) F_4 ( & V_11 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_12 , L_1 , V_2 ) ;
if ( V_2 -> V_13 ) F_7 ( V_2 -> V_13 ) ;
F_1 ( V_2 , 0 ) ;
F_2 ( & V_5 ) ;
if ( V_2 -> V_14 ) {
V_2 -> V_14 -> V_15 = V_2 -> V_15 ;
} else {
V_16 = V_2 -> V_15 ;
}
if ( V_2 -> V_15 ) {
V_2 -> V_15 -> V_14 = V_2 -> V_14 ;
} else {
V_17 = V_2 -> V_14 ;
}
if ( ! V_17 ) {
F_4 ( & V_11 ) ;
}
F_3 ( & V_5 ) ;
F_8 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_1 ( V_2 , ! 0 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_18 * V_19 , * V_20 ;
F_6 ( V_12 ,
L_2 , V_2 ) ;
if ( ! V_2 -> V_21 && ! V_2 -> V_22 ) {
V_2 -> V_21 = ! 0 ;
F_6 ( V_12 ,
L_3 , V_2 ) ;
if ( F_11 ( V_2 -> V_13 ,
( void ( * ) ( void * ) ) F_9 ,
V_2 ) ) {
V_2 -> V_23 . V_24 =
F_12 ( V_2 -> V_13 ) ;
if ( V_2 -> V_25 ) V_2 -> V_25 ( V_2 ) ;
} else {
F_6 ( V_12 ,
L_4 ,
V_2 ) ;
}
}
for ( V_19 = V_2 -> V_26 ; V_19 ; V_19 = V_20 ) {
V_20 = V_19 -> V_27 ;
if ( V_19 -> V_28 ) V_19 -> V_28 ( V_19 ) ;
}
if ( V_2 -> V_22 && ! V_2 -> V_26 ) {
F_5 ( V_2 ) ;
return;
}
}
static int F_13 ( void )
{
return V_29 && ( V_17 == NULL ) ;
}
static int F_14 ( void * V_30 )
{
struct V_1 * V_2 ;
F_6 ( V_12 , L_5 ) ;
do {
while ( ( V_2 = V_7 ) != NULL ) {
F_1 ( V_2 , 0 ) ;
F_10 ( V_2 ) ;
}
F_15 (
V_11 ,
( ( V_7 != NULL ) ||
F_13 () ) ) ;
} while ( ! F_13 () );
V_31 = ! 0 ;
F_4 ( & V_32 ) ;
F_6 ( V_12 , L_6 ) ;
F_15 (
V_11 ,
F_16 () ) ;
F_6 ( V_12 , L_7 ) ;
return 0 ;
}
int F_17 ( void )
{
V_33 = F_18 ( F_14 ,
NULL ,
L_8 ) ;
return ( V_33 ? 0 : - V_34 ) ;
}
void F_19 ( void )
{
V_29 = ! 0 ;
F_4 ( & V_11 ) ;
F_15 (
V_32 ,
V_31 ) ;
F_20 ( V_33 ) ;
}
struct V_1 * F_21 (
struct V_35 * V_36 ,
const struct V_37 * V_38 ,
void (* V_25)( struct V_1 * ) )
{
struct V_1 * V_2 = NULL ;
V_2 = F_22 ( sizeof( * V_2 ) , V_39 ) ;
if ( ! V_2 ) goto V_40;
F_6 ( V_12 , L_9 , V_2 ) ;
V_2 -> V_25 = V_25 ;
F_23 ( & V_2 -> V_41 ) ;
F_2 ( & V_5 ) ;
V_2 -> V_15 = V_16 ;
V_2 -> V_14 = NULL ;
V_16 = V_2 ;
if ( V_2 -> V_15 ) {
V_2 -> V_15 -> V_14 = V_2 ;
} else {
V_17 = V_2 ;
}
F_3 ( & V_5 ) ;
V_2 -> V_13 = F_24 ( V_36 , V_38 ) ;
if ( ! V_2 -> V_13 ) {
F_5 ( V_2 ) ;
V_2 = NULL ;
goto V_40;
}
F_1 ( V_2 , ! 0 ) ;
V_40:
return V_2 ;
}
static void F_25 ( struct V_1 * V_2 )
{
unsigned int V_42 , V_43 ;
struct V_18 * V_44 ;
struct V_45 * V_13 = V_2 -> V_13 ;
V_43 = F_26 ( V_13 ) ;
V_42 = V_43 ;
for ( V_44 = V_2 -> V_26 ; V_44 ; V_44 = V_44 -> V_27 ) {
if ( ! V_44 -> V_46 ) continue;
V_42 &= V_44 -> V_46 ;
}
F_27 ( V_13 , V_43 , V_42 ) ;
F_28 ( V_13 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_41 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
int V_47 = 0 ;
if ( ! ( V_2 -> V_26 || ! V_2 -> V_22 ) ) {
V_47 = ! 0 ;
}
F_3 ( & V_2 -> V_41 ) ;
if ( V_47 ) F_9 ( V_2 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
F_32 ( V_2 -> V_13 ) ;
V_2 -> V_22 = ! 0 ;
F_9 ( V_2 ) ;
}
void F_33 ( struct V_18 * V_44 , struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
V_44 -> V_13 = V_2 -> V_13 ;
V_44 -> V_48 = V_2 ;
V_44 -> V_27 = NULL ;
V_44 -> V_49 = V_2 -> V_50 ;
if ( V_2 -> V_50 ) {
V_2 -> V_50 -> V_27 = V_44 ;
} else {
V_2 -> V_26 = V_44 ;
}
V_2 -> V_50 = V_44 ;
F_30 ( V_2 ) ;
}
static void F_34 ( struct V_18 * V_44 )
{
if ( ! V_44 -> V_24 ) return;
F_35 ( V_44 -> V_24 -> V_24 ) ;
V_44 -> V_24 -> V_51 = NULL ;
V_44 -> V_24 = NULL ;
}
void F_36 ( struct V_18 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_48 ;
F_29 ( V_2 ) ;
V_44 -> V_46 = 0 ;
F_34 ( V_44 ) ;
F_25 ( V_2 ) ;
if ( V_44 -> V_27 ) {
V_44 -> V_27 -> V_49 = V_44 -> V_49 ;
} else {
V_2 -> V_50 = V_44 -> V_49 ;
}
if ( V_44 -> V_49 ) {
V_44 -> V_49 -> V_27 = V_44 -> V_27 ;
} else {
V_2 -> V_26 = V_44 -> V_27 ;
}
V_44 -> V_13 = NULL ;
F_30 ( V_2 ) ;
}
int F_37 ( struct V_18 * V_44 , unsigned int V_52 )
{
unsigned int V_42 , V_43 ;
int V_53 = 0 ;
struct V_18 * V_54 ;
struct V_45 * V_13 = V_44 -> V_13 ;
V_43 = F_26 ( V_13 ) ;
V_52 &= V_43 ;
if ( V_52 == V_44 -> V_46 ) {
return 0 ;
}
F_29 ( V_44 -> V_48 ) ;
do {
if ( ! V_52 ) {
V_44 -> V_46 = 0 ;
F_25 ( V_44 -> V_48 ) ;
break;
}
V_42 = V_43 ;
for ( V_54 = V_44 -> V_48 -> V_26 ; V_54 ; V_54 = V_54 -> V_27 ) {
if ( V_54 == V_44 ) continue;
if ( ! V_54 -> V_46 ) continue;
V_42 &= V_54 -> V_46 ;
}
if ( ! ( V_42 & V_52 ) ) {
V_53 = - V_55 ;
break;
}
V_42 &= V_52 ;
if ( ( V_53 = F_27 ( V_13 , V_43 , V_42 ) ) != 0 ) {
break;
}
V_44 -> V_46 = V_52 ;
F_28 ( V_13 ) ;
} while ( 0 );
F_30 ( V_44 -> V_48 ) ;
return V_53 ;
}
unsigned int F_38 ( struct V_18 * V_44 )
{
return V_44 -> V_46 ;
}
int F_39 ( struct V_18 * V_44 ,
struct V_56 * V_57 )
{
int V_58 = 0 ;
F_29 ( V_44 -> V_48 ) ; do {
if ( V_57 == V_44 -> V_24 ) break;
if ( V_57 && V_57 -> V_51 ) {
V_58 = - V_59 ;
break;
}
F_34 ( V_44 ) ;
if ( ! V_57 ) break;
V_57 -> V_51 = V_44 ;
V_44 -> V_24 = V_57 ;
} while ( 0 ); F_30 ( V_44 -> V_48 ) ;
return V_58 ;
}
struct V_60 * F_40 (
struct V_56 * V_57 )
{
struct V_60 * V_44 ;
V_44 = F_41 () ;
if ( ! V_44 ) return NULL ;
F_42 ( V_44 , V_57 -> V_24 ) ;
F_43 ( V_44 , V_61 , sizeof( V_61 ) ) ;
return V_44 ;
}
