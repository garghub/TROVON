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
if ( F_7 ( ( ( V_8 + 7 ) & V_6 ) >= 7 ) )
return false ;
return F_5 ( * ( T_2 * ) V_11 ) ;
}
return false ;
}
static T_3 bool F_10 ( unsigned long V_8 )
{
T_6 * V_11 = ( T_6 * ) F_2 ( ( void * ) V_8 ) ;
if ( F_5 ( * V_11 ) ) {
T_5 V_12 = * ( T_5 * ) V_11 ;
T_4 V_13 = ( V_8 + 15 ) & V_6 ;
if ( F_5 ( V_12 ) )
return true ;
if ( F_7 ( ! V_13 ) )
return false ;
return F_4 ( V_8 + 15 ) ;
}
return false ;
}
static T_3 unsigned long F_11 ( const T_2 * V_14 ,
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
static T_3 unsigned long F_12 ( const void * V_14 ,
const void * V_15 )
{
unsigned int V_16 ;
unsigned long V_17 ;
unsigned int V_18 = ( unsigned long ) V_14 % 8 ;
if ( V_15 - V_14 <= 16 )
return F_11 ( V_14 , V_15 - V_14 ) ;
if ( V_18 ) {
V_18 = 8 - V_18 ;
V_17 = F_11 ( V_14 , V_18 ) ;
if ( F_5 ( V_17 ) )
return V_17 ;
V_14 += V_18 ;
}
V_16 = ( V_15 - V_14 ) / 8 ;
while ( V_16 ) {
if ( F_5 ( * ( V_19 * ) V_14 ) )
return F_11 ( V_14 , 8 ) ;
V_14 += 8 ;
V_16 -- ;
}
return F_11 ( V_14 , ( V_15 - V_14 ) % 8 ) ;
}
static T_3 bool F_13 ( unsigned long V_8 ,
T_1 V_2 )
{
unsigned long V_17 ;
V_17 = F_12 ( F_2 ( ( void * ) V_8 ) ,
F_2 ( ( void * ) V_8 + V_2 - 1 ) + 1 ) ;
if ( F_5 ( V_17 ) ) {
unsigned long V_13 = V_8 + V_2 - 1 ;
T_4 * V_20 = ( T_4 * ) F_2 ( ( void * ) V_13 ) ;
if ( F_5 ( V_17 != ( unsigned long ) V_20 ||
( ( V_13 & V_6 ) >= * V_20 ) ) )
return true ;
}
return false ;
}
static T_3 bool F_14 ( unsigned long V_8 , T_1 V_2 )
{
if ( F_15 ( V_2 ) ) {
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
return F_10 ( V_8 ) ;
default:
F_16 () ;
}
}
return F_13 ( V_8 , V_2 ) ;
}
static T_3 void F_17 ( unsigned long V_8 ,
T_1 V_2 , bool V_21 )
{
struct V_22 V_23 ;
if ( F_5 ( V_2 == 0 ) )
return;
if ( F_5 ( ( void * ) V_8 <
F_18 ( ( void * ) V_24 ) ) ) {
V_23 . V_25 = ( void * ) V_8 ;
V_23 . V_26 = V_2 ;
V_23 . V_27 = V_21 ;
V_23 . V_28 = V_29 ;
F_19 ( & V_23 ) ;
return;
}
if ( F_7 ( ! F_14 ( V_8 , V_2 ) ) )
return;
F_20 ( V_8 , V_2 , V_21 , V_29 ) ;
}
void * memset ( void * V_8 , int V_30 , T_1 V_31 )
{
F_21 ( ( unsigned long ) V_8 , V_31 ) ;
return F_22 ( V_8 , V_30 , V_31 ) ;
}
void * memmove ( void * V_32 , const void * V_33 , T_1 V_31 )
{
F_23 ( ( unsigned long ) V_33 , V_31 ) ;
F_21 ( ( unsigned long ) V_32 , V_31 ) ;
return F_24 ( V_32 , V_33 , V_31 ) ;
}
void * memcpy ( void * V_32 , const void * V_33 , T_1 V_31 )
{
F_23 ( ( unsigned long ) V_33 , V_31 ) ;
F_21 ( ( unsigned long ) V_32 , V_31 ) ;
return F_25 ( V_32 , V_33 , V_31 ) ;
}
void F_26 ( struct V_34 * V_34 , unsigned int V_35 )
{
if ( F_7 ( ! F_27 ( V_34 ) ) )
F_3 ( F_28 ( V_34 ) , V_36 << V_35 ) ;
}
void F_29 ( struct V_34 * V_34 , unsigned int V_35 )
{
if ( F_7 ( ! F_27 ( V_34 ) ) )
F_1 ( F_28 ( V_34 ) ,
V_36 << V_35 ,
V_37 ) ;
}
void F_30 ( struct V_34 * V_34 )
{
F_1 ( F_28 ( V_34 ) ,
V_36 << F_31 ( V_34 ) ,
V_38 ) ;
}
void F_32 ( struct V_39 * V_40 , void * V_41 )
{
F_3 ( V_41 , V_40 -> V_42 ) ;
}
void F_33 ( struct V_39 * V_40 , void * V_41 )
{
F_1 ( V_41 ,
F_34 ( V_40 -> V_42 , V_43 ) ,
V_38 ) ;
}
void F_35 ( struct V_39 * V_40 , void * V_41 )
{
F_36 ( V_40 , V_41 , V_40 -> V_42 ) ;
}
void F_37 ( struct V_39 * V_40 , void * V_41 )
{
unsigned long V_2 = V_40 -> V_42 ;
unsigned long V_44 = F_34 ( V_2 , V_43 ) ;
if ( F_5 ( V_40 -> V_45 & V_46 ) )
return;
F_1 ( V_41 , V_44 , V_47 ) ;
}
void F_36 ( struct V_39 * V_40 , const void * V_41 , T_1 V_2 )
{
unsigned long V_48 ;
unsigned long V_49 ;
if ( F_5 ( V_41 == NULL ) )
return;
V_48 = F_34 ( ( unsigned long ) ( V_41 + V_2 ) ,
V_43 ) ;
V_49 = F_34 ( ( unsigned long ) V_41 + V_40 -> V_42 ,
V_43 ) ;
F_3 ( V_41 , V_2 ) ;
F_1 ( ( void * ) V_48 , V_49 - V_48 ,
V_38 ) ;
}
void F_38 ( const void * V_50 , T_1 V_2 )
{
struct V_34 * V_34 ;
unsigned long V_48 ;
unsigned long V_49 ;
if ( F_5 ( V_50 == NULL ) )
return;
V_34 = F_39 ( V_50 ) ;
V_48 = F_34 ( ( unsigned long ) ( V_50 + V_2 ) ,
V_43 ) ;
V_49 = ( unsigned long ) V_50 + ( V_36 << F_31 ( V_34 ) ) ;
F_3 ( V_50 , V_2 ) ;
F_1 ( ( void * ) V_48 , V_49 - V_48 ,
V_51 ) ;
}
void F_40 ( const void * V_41 , T_1 V_2 )
{
struct V_34 * V_34 ;
if ( F_5 ( V_41 == V_52 ) )
return;
V_34 = F_41 ( V_41 ) ;
if ( F_5 ( ! F_42 ( V_34 ) ) )
F_38 ( V_41 , V_2 ) ;
else
F_36 ( V_34 -> V_53 , V_41 , V_2 ) ;
}
void F_43 ( void * V_50 )
{
struct V_34 * V_34 ;
V_34 = F_41 ( V_50 ) ;
if ( F_5 ( ! F_42 ( V_34 ) ) )
F_1 ( V_50 , V_36 << F_31 ( V_34 ) ,
V_37 ) ;
else
F_37 ( V_34 -> V_53 , V_50 ) ;
}
void F_44 ( const void * V_50 )
{
struct V_34 * V_34 = F_39 ( V_50 ) ;
F_1 ( V_50 , V_36 << F_31 ( V_34 ) ,
V_37 ) ;
}
int F_45 ( void * V_8 , T_1 V_2 )
{
void * V_17 ;
T_1 V_54 ;
unsigned long V_4 ;
V_4 = ( unsigned long ) F_2 ( V_8 ) ;
V_54 = F_34 ( V_2 >> V_55 ,
V_36 ) ;
if ( F_46 ( ! F_47 ( V_4 ) ) )
return - V_56 ;
V_17 = F_48 ( V_54 , 1 , V_4 ,
V_4 + V_54 ,
V_57 | V_58 | V_59 ,
V_60 , V_61 , V_62 ,
F_49 ( 0 ) ) ;
if ( V_17 ) {
F_50 ( V_8 ) -> V_45 |= V_63 ;
return 0 ;
}
return - V_64 ;
}
void F_51 ( const struct V_65 * V_66 )
{
if ( V_66 -> V_45 & V_63 )
F_52 ( F_2 ( V_66 -> V_8 ) ) ;
}
static void F_53 ( struct V_67 * V_68 )
{
T_1 V_69 = F_34 ( V_68 -> V_2 , V_43 ) ;
F_3 ( V_68 -> V_70 , V_68 -> V_2 ) ;
F_1 ( V_68 -> V_70 + V_69 ,
V_68 -> V_71 - V_69 ,
V_72 ) ;
}
void F_54 ( struct V_67 * V_73 , T_1 V_2 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_2 ; V_74 ++ )
F_53 ( & V_73 [ V_74 ] ) ;
}
void F_55 ( struct V_67 * V_73 , T_1 V_2 )
{
}
void F_23 ( unsigned long V_8 , T_1 V_2 )
{
F_17 ( V_8 , V_2 , false ) ;
}
void F_21 ( unsigned long V_8 , T_1 V_2 )
{
F_17 ( V_8 , V_2 , true ) ;
}
void F_56 ( void ) {}
static int F_57 ( struct V_75 * V_76 ,
unsigned long V_77 , void * V_78 )
{
return ( V_77 == V_79 ) ? V_80 : V_81 ;
}
static int T_7 F_58 ( void )
{
F_59 ( L_1 ) ;
F_59 ( L_2 ) ;
F_60 ( F_57 , 0 ) ;
return 0 ;
}
