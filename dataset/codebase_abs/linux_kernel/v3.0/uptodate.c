T_1 F_1 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 || ! V_2 -> V_3 ) ;
return V_2 -> V_3 -> V_4 ( V_2 ) ;
}
struct V_5 * F_3 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 || ! V_2 -> V_3 ) ;
return V_2 -> V_3 -> V_6 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 || ! V_2 -> V_3 ) ;
V_2 -> V_3 -> V_7 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 || ! V_2 -> V_3 ) ;
V_2 -> V_3 -> V_8 ( V_2 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 || ! V_2 -> V_3 ) ;
V_2 -> V_3 -> V_9 ( V_2 ) ;
}
void F_7 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 || ! V_2 -> V_3 ) ;
V_2 -> V_3 -> V_10 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
int V_11 )
{
V_2 -> V_12 |= V_13 ;
V_2 -> V_14 = 0 ;
if ( V_11 ) {
V_2 -> V_15 = 0 ;
V_2 -> V_16 = 0 ;
}
}
void F_9 ( struct V_1 * V_2 ,
const struct V_17 * V_18 )
{
F_2 ( ! V_18 ) ;
V_2 -> V_3 = V_18 ;
F_8 ( V_2 , 1 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 ) ;
F_8 ( V_2 , 1 ) ;
}
static unsigned int F_12 ( struct V_19 * V_20 )
{
unsigned int V_21 = 0 ;
struct V_22 * V_23 ;
struct V_24 * V_25 ;
while ( ( V_23 = F_13 ( V_20 ) ) != NULL ) {
V_25 = F_14 ( V_23 , struct V_24 , V_26 ) ;
F_15 (
( unsigned long long ) V_25 -> V_27 ) ;
F_16 ( & V_25 -> V_26 , V_20 ) ;
F_17 ( V_28 , V_25 ) ;
V_21 ++ ;
}
return V_21 ;
}
void F_11 ( struct V_1 * V_2 )
{
unsigned int V_29 , V_30 , V_21 ;
struct V_19 V_20 = V_31 ;
F_2 ( ! V_2 || ! V_2 -> V_3 ) ;
F_4 ( V_2 ) ;
V_29 = ! ( V_2 -> V_12 & V_13 ) ;
V_30 = V_2 -> V_14 ;
F_18 (
( unsigned long long ) F_1 ( V_2 ) ,
V_30 , V_29 ) ;
if ( V_29 )
V_20 = V_2 -> V_32 . V_33 ;
F_8 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
V_21 = F_12 ( & V_20 ) ;
if ( V_29 && V_21 != V_30 )
F_19 ( V_34 , L_1 ,
( unsigned long long ) F_1 ( V_2 ) ,
V_30 , V_21 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
T_2 V_25 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_2 -> V_14 ; V_35 ++ ) {
if ( V_25 == V_2 -> V_32 . V_36 [ V_35 ] )
return V_35 ;
}
return - 1 ;
}
static struct V_24 *
F_21 ( struct V_1 * V_2 ,
T_2 V_37 )
{
struct V_22 * V_38 = V_2 -> V_32 . V_33 . V_22 ;
struct V_24 * V_25 = NULL ;
while ( V_38 ) {
V_25 = F_14 ( V_38 , struct V_24 , V_26 ) ;
if ( V_37 < V_25 -> V_27 )
V_38 = V_38 -> V_39 ;
else if ( V_37 > V_25 -> V_27 )
V_38 = V_38 -> V_40 ;
else
return V_25 ;
}
return NULL ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
int V_43 = - 1 ;
struct V_24 * V_25 = NULL ;
F_4 ( V_2 ) ;
F_23 (
( unsigned long long ) F_1 ( V_2 ) ,
( unsigned long long ) V_42 -> V_44 ,
! ! ( V_2 -> V_12 & V_13 ) ) ;
if ( V_2 -> V_12 & V_13 )
V_43 = F_20 ( V_2 , V_42 -> V_44 ) ;
else
V_25 = F_21 ( V_2 , V_42 -> V_44 ) ;
F_5 ( V_2 ) ;
F_24 ( V_43 , V_25 ) ;
return ( V_43 != - 1 ) || ( V_25 != NULL ) ;
}
int F_25 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
if ( ! F_26 ( V_42 ) )
return 0 ;
if ( F_27 ( V_42 ) )
return 1 ;
return F_22 ( V_2 , V_42 ) ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
return F_29 ( V_42 ) && F_22 ( V_2 , V_42 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
T_2 V_37 )
{
F_2 ( V_2 -> V_14 >= V_45 ) ;
F_31 (
( unsigned long long ) F_1 ( V_2 ) ,
( unsigned long long ) V_37 , V_2 -> V_14 ) ;
V_2 -> V_32 . V_36 [ V_2 -> V_14 ] = V_37 ;
V_2 -> V_14 ++ ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_24 * V_46 )
{
T_2 V_37 = V_46 -> V_27 ;
struct V_22 * V_47 = NULL ;
struct V_22 * * V_48 = & V_2 -> V_32 . V_33 . V_22 ;
struct V_24 * V_49 ;
F_33 (
( unsigned long long ) F_1 ( V_2 ) ,
( unsigned long long ) V_37 , V_2 -> V_14 ) ;
while( * V_48 ) {
V_47 = * V_48 ;
V_49 = F_14 ( V_47 , struct V_24 , V_26 ) ;
if ( V_37 < V_49 -> V_27 )
V_48 = & ( * V_48 ) -> V_39 ;
else if ( V_37 > V_49 -> V_27 )
V_48 = & ( * V_48 ) -> V_40 ;
else {
F_19 ( V_34 , L_2 ,
( unsigned long long ) V_37 ) ;
F_34 () ;
}
}
F_35 ( & V_46 -> V_26 , V_47 , V_48 ) ;
F_36 ( & V_46 -> V_26 , & V_2 -> V_32 . V_33 ) ;
V_2 -> V_14 ++ ;
}
static inline int F_37 ( struct V_1 * V_2 )
{
return ( V_2 -> V_12 & V_13 ) &&
( V_2 -> V_14 < V_45 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_24 * * V_29 )
{
int V_35 ;
F_39 ( V_2 -> V_14 != V_45 ,
L_3 ,
( unsigned long long ) F_1 ( V_2 ) ,
V_2 -> V_14 , V_45 ) ;
F_39 ( ! ( V_2 -> V_12 & V_13 ) ,
L_4 ,
( unsigned long long ) F_1 ( V_2 ) ) ;
for ( V_35 = 0 ; V_35 < V_45 ; V_35 ++ )
V_29 [ V_35 ] -> V_27 = V_2 -> V_32 . V_36 [ V_35 ] ;
V_2 -> V_12 &= ~ V_13 ;
V_2 -> V_32 . V_33 = V_31 ;
V_2 -> V_14 = 0 ;
for ( V_35 = 0 ; V_35 < V_45 ; V_35 ++ ) {
F_32 ( V_2 , V_29 [ V_35 ] ) ;
V_29 [ V_35 ] = NULL ;
}
F_40 (
( unsigned long long ) F_1 ( V_2 ) ,
V_2 -> V_12 , V_2 -> V_14 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
T_2 V_37 ,
int V_50 )
{
int V_35 ;
struct V_24 * V_46 = NULL ;
struct V_24 * V_29 [ V_45 ] =
{ NULL , } ;
F_42 (
( unsigned long long ) F_1 ( V_2 ) ,
( unsigned long long ) V_37 , V_50 ) ;
V_46 = F_43 ( V_28 , V_51 ) ;
if ( ! V_46 ) {
F_44 ( - V_52 ) ;
return;
}
V_46 -> V_27 = V_37 ;
if ( V_50 ) {
for ( V_35 = 0 ; V_35 < V_45 ; V_35 ++ ) {
V_29 [ V_35 ] = F_43 ( V_28 ,
V_51 ) ;
if ( ! V_29 [ V_35 ] ) {
F_44 ( - V_52 ) ;
goto V_53;
}
}
}
F_4 ( V_2 ) ;
if ( F_37 ( V_2 ) ) {
F_30 ( V_2 , V_37 ) ;
F_5 ( V_2 ) ;
goto V_53;
}
if ( V_50 )
F_38 ( V_2 , V_29 ) ;
F_32 ( V_2 , V_46 ) ;
F_5 ( V_2 ) ;
V_46 = NULL ;
V_53:
if ( V_46 )
F_17 ( V_28 , V_46 ) ;
if ( V_29 [ 0 ] ) {
for ( V_35 = 0 ; V_35 < V_45 ; V_35 ++ )
if ( V_29 [ V_35 ] )
F_17 ( V_28 ,
V_29 [ V_35 ] ) ;
}
}
void F_45 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
int V_54 ;
if ( F_22 ( V_2 , V_42 ) )
return;
F_46 (
( unsigned long long ) F_1 ( V_2 ) ,
( unsigned long long ) V_42 -> V_44 ) ;
F_4 ( V_2 ) ;
if ( F_37 ( V_2 ) ) {
F_30 ( V_2 , V_42 -> V_44 ) ;
F_5 ( V_2 ) ;
return;
}
V_54 = 0 ;
if ( V_2 -> V_12 & V_13 ) {
V_54 = 1 ;
}
F_5 ( V_2 ) ;
F_41 ( V_2 , V_42 -> V_44 , V_54 ) ;
}
void F_47 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
F_2 ( F_22 ( V_2 , V_42 ) ) ;
F_48 ( V_42 ) ;
F_6 ( V_2 ) ;
F_45 ( V_2 , V_42 ) ;
F_7 ( V_2 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
int V_43 )
{
T_2 * V_55 = V_2 -> V_32 . V_36 ;
int V_56 ;
F_2 ( V_43 < 0 || V_43 >= V_45 ) ;
F_2 ( V_43 >= V_2 -> V_14 ) ;
F_2 ( ! V_2 -> V_14 ) ;
F_50 (
( unsigned long long ) F_1 ( V_2 ) ,
V_43 , V_2 -> V_14 ) ;
V_2 -> V_14 -- ;
if ( V_2 -> V_14 && V_43 < V_2 -> V_14 ) {
V_56 = sizeof( T_2 ) * ( V_2 -> V_14 - V_43 ) ;
memmove ( & V_55 [ V_43 ] , & V_55 [ V_43 + 1 ] , V_56 ) ;
}
}
static void F_51 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
F_52 (
( unsigned long long ) F_1 ( V_2 ) ,
( unsigned long long ) V_25 -> V_27 ) ;
F_16 ( & V_25 -> V_26 , & V_2 -> V_32 . V_33 ) ;
V_2 -> V_14 -- ;
}
static void F_53 ( struct V_1 * V_2 ,
T_2 V_37 )
{
int V_43 ;
struct V_24 * V_25 = NULL ;
F_4 ( V_2 ) ;
F_54 (
( unsigned long long ) F_1 ( V_2 ) ,
( unsigned long long ) V_37 , V_2 -> V_14 ,
V_2 -> V_12 ) ;
if ( V_2 -> V_12 & V_13 ) {
V_43 = F_20 ( V_2 , V_37 ) ;
if ( V_43 != - 1 )
F_49 ( V_2 , V_43 ) ;
} else {
V_25 = F_21 ( V_2 , V_37 ) ;
if ( V_25 )
F_51 ( V_2 , V_25 ) ;
}
F_5 ( V_2 ) ;
if ( V_25 )
F_17 ( V_28 , V_25 ) ;
}
void F_55 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
T_2 V_37 = V_42 -> V_44 ;
F_53 ( V_2 , V_37 ) ;
}
void F_56 ( struct V_1 * V_2 ,
T_2 V_37 ,
T_3 V_57 )
{
struct V_5 * V_58 = F_3 ( V_2 ) ;
unsigned int V_35 , V_59 = F_57 ( V_58 , 1 ) * V_57 ;
for ( V_35 = 0 ; V_35 < V_59 ; V_35 ++ , V_37 ++ )
F_53 ( V_2 , V_37 ) ;
}
int T_4 F_58 ( void )
{
V_28 = F_59 ( L_5 ,
sizeof( struct V_24 ) ,
0 , V_60 , NULL ) ;
if ( ! V_28 )
return - V_52 ;
return 0 ;
}
void F_60 ( void )
{
if ( V_28 )
F_61 ( V_28 ) ;
}
