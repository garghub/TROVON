static void F_1 ( const void * V_1 , T_1 V_2 , T_2 V_3 )
{
void * V_4 , * V_5 ;
V_4 = F_2 ( V_1 ) ;
V_5 = F_2 ( V_1 + V_2 ) ;
memset ( V_4 , V_3 , V_5 - V_4 ) ;
}
void F_3 ( const void * V_1 , T_1 V_2 )
{
F_1 ( V_1 , V_2 , 0 ) ;
if ( V_2 & V_6 ) {
T_2 * V_7 = ( T_2 * ) F_2 ( V_1 + V_2 ) ;
* V_7 = V_2 & V_6 ;
}
}
static T_3 bool F_4 ( unsigned long V_8 )
{
T_4 V_9 = * ( T_4 * ) F_2 ( ( void * ) V_8 ) ;
if ( F_5 ( V_9 ) ) {
T_4 V_10 = V_8 & V_6 ;
return F_5 ( V_10 >= V_9 ) ;
}
return false ;
}
static T_3 bool F_6 ( unsigned long V_8 )
{
T_5 * V_11 = ( T_5 * ) F_2 ( ( void * ) V_8 ) ;
if ( F_5 ( * V_11 ) ) {
if ( F_4 ( V_8 + 1 ) )
return true ;
if ( F_7 ( ( ( V_8 + 1 ) & V_6 ) != 0 ) )
return false ;
return F_5 ( * ( T_2 * ) V_11 ) ;
}
return false ;
}
static T_3 bool F_8 ( unsigned long V_8 )
{
T_5 * V_11 = ( T_5 * ) F_2 ( ( void * ) V_8 ) ;
if ( F_5 ( * V_11 ) ) {
if ( F_4 ( V_8 + 3 ) )
return true ;
if ( F_7 ( ( ( V_8 + 3 ) & V_6 ) >= 3 ) )
return false ;
return F_5 ( * ( T_2 * ) V_11 ) ;
}
return false ;
}
static T_3 bool F_9 ( unsigned long V_8 )
{
T_5 * V_11 = ( T_5 * ) F_2 ( ( void * ) V_8 ) ;
if ( F_5 ( * V_11 ) ) {
if ( F_4 ( V_8 + 7 ) )
return true ;
if ( F_7 ( F_10 ( V_8 , V_12 ) ) )
return false ;
return F_5 ( * ( T_2 * ) V_11 ) ;
}
return false ;
}
static T_3 bool F_11 ( unsigned long V_8 )
{
T_6 * V_11 = ( T_6 * ) F_2 ( ( void * ) V_8 ) ;
if ( F_5 ( * V_11 ) ) {
T_5 V_13 = * ( T_5 * ) V_11 ;
if ( F_5 ( V_13 ) )
return true ;
if ( F_7 ( F_10 ( V_8 , V_12 ) ) )
return false ;
return F_4 ( V_8 + 15 ) ;
}
return false ;
}
static T_3 unsigned long F_12 ( const T_2 * V_14 ,
T_1 V_2 )
{
while ( V_2 ) {
if ( F_5 ( * V_14 ) )
return ( unsigned long ) V_14 ;
V_14 ++ ;
V_2 -- ;
}
return 0 ;
}
static T_3 unsigned long F_13 ( const void * V_14 ,
const void * V_15 )
{
unsigned int V_16 ;
unsigned long V_17 ;
unsigned int V_18 = ( unsigned long ) V_14 % 8 ;
if ( V_15 - V_14 <= 16 )
return F_12 ( V_14 , V_15 - V_14 ) ;
if ( V_18 ) {
V_18 = 8 - V_18 ;
V_17 = F_12 ( V_14 , V_18 ) ;
if ( F_5 ( V_17 ) )
return V_17 ;
V_14 += V_18 ;
}
V_16 = ( V_15 - V_14 ) / 8 ;
while ( V_16 ) {
if ( F_5 ( * ( V_19 * ) V_14 ) )
return F_12 ( V_14 , 8 ) ;
V_14 += 8 ;
V_16 -- ;
}
return F_12 ( V_14 , ( V_15 - V_14 ) % 8 ) ;
}
static T_3 bool F_14 ( unsigned long V_8 ,
T_1 V_2 )
{
unsigned long V_17 ;
V_17 = F_13 ( F_2 ( ( void * ) V_8 ) ,
F_2 ( ( void * ) V_8 + V_2 - 1 ) + 1 ) ;
if ( F_5 ( V_17 ) ) {
unsigned long V_20 = V_8 + V_2 - 1 ;
T_4 * V_21 = ( T_4 * ) F_2 ( ( void * ) V_20 ) ;
if ( F_5 ( V_17 != ( unsigned long ) V_21 ||
( ( long ) ( V_20 & V_6 ) >= * V_21 ) ) )
return true ;
}
return false ;
}
static T_3 bool F_15 ( unsigned long V_8 , T_1 V_2 )
{
if ( F_16 ( V_2 ) ) {
switch ( V_2 ) {
case 1 :
return F_4 ( V_8 ) ;
case 2 :
return F_6 ( V_8 ) ;
case 4 :
return F_8 ( V_8 ) ;
case 8 :
return F_9 ( V_8 ) ;
case 16 :
return F_11 ( V_8 ) ;
default:
F_17 () ;
}
}
return F_14 ( V_8 , V_2 ) ;
}
static T_3 void F_18 ( unsigned long V_8 ,
T_1 V_2 , bool V_22 )
{
if ( F_5 ( V_2 == 0 ) )
return;
if ( F_5 ( ( void * ) V_8 <
F_19 ( ( void * ) V_23 ) ) ) {
F_20 ( V_8 , V_2 , V_22 , V_24 ) ;
return;
}
if ( F_7 ( ! F_15 ( V_8 , V_2 ) ) )
return;
F_20 ( V_8 , V_2 , V_22 , V_24 ) ;
}
void * memset ( void * V_8 , int V_25 , T_1 V_26 )
{
F_21 ( ( unsigned long ) V_8 , V_26 ) ;
return F_22 ( V_8 , V_25 , V_26 ) ;
}
void * memmove ( void * V_27 , const void * V_28 , T_1 V_26 )
{
F_23 ( ( unsigned long ) V_28 , V_26 ) ;
F_21 ( ( unsigned long ) V_27 , V_26 ) ;
return F_24 ( V_27 , V_28 , V_26 ) ;
}
void * memcpy ( void * V_27 , const void * V_28 , T_1 V_26 )
{
F_23 ( ( unsigned long ) V_28 , V_26 ) ;
F_21 ( ( unsigned long ) V_27 , V_26 ) ;
return F_25 ( V_27 , V_28 , V_26 ) ;
}
void F_26 ( struct V_29 * V_29 , unsigned int V_30 )
{
if ( F_7 ( ! F_27 ( V_29 ) ) )
F_3 ( F_28 ( V_29 ) , V_31 << V_30 ) ;
}
void F_29 ( struct V_29 * V_29 , unsigned int V_30 )
{
if ( F_7 ( ! F_27 ( V_29 ) ) )
F_1 ( F_28 ( V_29 ) ,
V_31 << V_30 ,
V_32 ) ;
}
void F_30 ( struct V_29 * V_29 )
{
F_1 ( F_28 ( V_29 ) ,
V_31 << F_31 ( V_29 ) ,
V_33 ) ;
}
void F_32 ( struct V_34 * V_35 , void * V_36 )
{
F_3 ( V_36 , V_35 -> V_37 ) ;
}
void F_33 ( struct V_34 * V_35 , void * V_36 )
{
F_1 ( V_36 ,
F_34 ( V_35 -> V_37 , V_12 ) ,
V_33 ) ;
}
void F_35 ( struct V_34 * V_35 , void * V_36 )
{
F_36 ( V_35 , V_36 , V_35 -> V_37 ) ;
}
void F_37 ( struct V_34 * V_35 , void * V_36 )
{
unsigned long V_2 = V_35 -> V_37 ;
unsigned long V_38 = F_34 ( V_2 , V_12 ) ;
if ( F_5 ( V_35 -> V_39 & V_40 ) )
return;
F_1 ( V_36 , V_38 , V_41 ) ;
}
void F_36 ( struct V_34 * V_35 , const void * V_36 , T_1 V_2 )
{
unsigned long V_42 ;
unsigned long V_43 ;
if ( F_5 ( V_36 == NULL ) )
return;
V_42 = F_34 ( ( unsigned long ) ( V_36 + V_2 ) ,
V_12 ) ;
V_43 = F_34 ( ( unsigned long ) V_36 + V_35 -> V_37 ,
V_12 ) ;
F_3 ( V_36 , V_2 ) ;
F_1 ( ( void * ) V_42 , V_43 - V_42 ,
V_33 ) ;
}
void F_38 ( const void * V_44 , T_1 V_2 )
{
struct V_29 * V_29 ;
unsigned long V_42 ;
unsigned long V_43 ;
if ( F_5 ( V_44 == NULL ) )
return;
V_29 = F_39 ( V_44 ) ;
V_42 = F_34 ( ( unsigned long ) ( V_44 + V_2 ) ,
V_12 ) ;
V_43 = ( unsigned long ) V_44 + ( V_31 << F_31 ( V_29 ) ) ;
F_3 ( V_44 , V_2 ) ;
F_1 ( ( void * ) V_42 , V_43 - V_42 ,
V_45 ) ;
}
void F_40 ( const void * V_36 , T_1 V_2 )
{
struct V_29 * V_29 ;
if ( F_5 ( V_36 == V_46 ) )
return;
V_29 = F_41 ( V_36 ) ;
if ( F_5 ( ! F_42 ( V_29 ) ) )
F_38 ( V_36 , V_2 ) ;
else
F_36 ( V_29 -> V_47 , V_36 , V_2 ) ;
}
void F_43 ( void * V_44 )
{
struct V_29 * V_29 ;
V_29 = F_41 ( V_44 ) ;
if ( F_5 ( ! F_42 ( V_29 ) ) )
F_1 ( V_44 , V_31 << F_31 ( V_29 ) ,
V_32 ) ;
else
F_37 ( V_29 -> V_47 , V_44 ) ;
}
void F_44 ( const void * V_44 )
{
struct V_29 * V_29 = F_39 ( V_44 ) ;
F_1 ( V_44 , V_31 << F_31 ( V_29 ) ,
V_32 ) ;
}
int F_45 ( void * V_8 , T_1 V_2 )
{
void * V_17 ;
T_1 V_48 ;
unsigned long V_4 ;
V_4 = ( unsigned long ) F_2 ( V_8 ) ;
V_48 = F_34 ( V_2 >> V_49 ,
V_31 ) ;
if ( F_46 ( ! F_47 ( V_4 ) ) )
return - V_50 ;
V_17 = F_48 ( V_48 , 1 , V_4 ,
V_4 + V_48 ,
V_51 | V_52 | V_53 ,
V_54 , V_55 , V_56 ,
F_49 ( 0 ) ) ;
if ( V_17 ) {
F_50 ( V_8 ) -> V_39 |= V_57 ;
F_51 ( V_17 ) ;
return 0 ;
}
return - V_58 ;
}
void F_52 ( const struct V_59 * V_60 )
{
if ( V_60 -> V_39 & V_57 )
F_53 ( F_2 ( V_60 -> V_8 ) ) ;
}
static void F_54 ( struct V_61 * V_62 )
{
T_1 V_63 = F_34 ( V_62 -> V_2 , V_12 ) ;
F_3 ( V_62 -> V_64 , V_62 -> V_2 ) ;
F_1 ( V_62 -> V_64 + V_63 ,
V_62 -> V_65 - V_63 ,
V_66 ) ;
}
void F_55 ( struct V_61 * V_67 , T_1 V_2 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_2 ; V_68 ++ )
F_54 ( & V_67 [ V_68 ] ) ;
}
void F_56 ( struct V_61 * V_67 , T_1 V_2 )
{
}
void F_23 ( unsigned long V_8 , T_1 V_2 )
{
F_18 ( V_8 , V_2 , false ) ;
}
void F_21 ( unsigned long V_8 , T_1 V_2 )
{
F_18 ( V_8 , V_2 , true ) ;
}
void F_57 ( void ) {}
static int F_58 ( struct V_69 * V_70 ,
unsigned long V_71 , void * V_72 )
{
return ( V_71 == V_73 ) ? V_74 : V_75 ;
}
static int T_7 F_59 ( void )
{
F_60 ( L_1 ) ;
F_60 ( L_2 ) ;
F_61 ( F_58 , 0 ) ;
return 0 ;
}
