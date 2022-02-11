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
static void F_4 ( struct V_8 * V_9 , void * V_10 )
{
void * V_11 = F_5 ( V_9 ) ;
T_1 V_2 = V_10 - V_11 ;
F_3 ( V_11 , V_2 ) ;
}
void F_6 ( struct V_8 * V_9 )
{
F_4 ( V_9 , F_5 ( V_9 ) + V_12 ) ;
}
T_3 void F_7 ( void * V_10 )
{
F_4 ( V_13 , V_10 ) ;
}
static T_4 bool F_8 ( unsigned long V_14 )
{
T_5 V_15 = * ( T_5 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_9 ( V_15 ) ) {
T_5 V_16 = V_14 & V_6 ;
return F_9 ( V_16 >= V_15 ) ;
}
return false ;
}
static T_4 bool F_10 ( unsigned long V_14 )
{
T_6 * V_17 = ( T_6 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_9 ( * V_17 ) ) {
if ( F_8 ( V_14 + 1 ) )
return true ;
if ( F_11 ( ( ( V_14 + 1 ) & V_6 ) != 0 ) )
return false ;
return F_9 ( * ( T_2 * ) V_17 ) ;
}
return false ;
}
static T_4 bool F_12 ( unsigned long V_14 )
{
T_6 * V_17 = ( T_6 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_9 ( * V_17 ) ) {
if ( F_8 ( V_14 + 3 ) )
return true ;
if ( F_11 ( ( ( V_14 + 3 ) & V_6 ) >= 3 ) )
return false ;
return F_9 ( * ( T_2 * ) V_17 ) ;
}
return false ;
}
static T_4 bool F_13 ( unsigned long V_14 )
{
T_6 * V_17 = ( T_6 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_9 ( * V_17 ) ) {
if ( F_8 ( V_14 + 7 ) )
return true ;
if ( F_11 ( F_14 ( V_14 , V_18 ) ) )
return false ;
return F_9 ( * ( T_2 * ) V_17 ) ;
}
return false ;
}
static T_4 bool F_15 ( unsigned long V_14 )
{
T_7 * V_17 = ( T_7 * ) F_2 ( ( void * ) V_14 ) ;
if ( F_9 ( * V_17 ) ) {
T_6 V_19 = * ( T_6 * ) V_17 ;
if ( F_9 ( V_19 ) )
return true ;
if ( F_11 ( F_14 ( V_14 , V_18 ) ) )
return false ;
return F_8 ( V_14 + 15 ) ;
}
return false ;
}
static T_4 unsigned long F_16 ( const T_2 * V_20 ,
T_1 V_2 )
{
while ( V_2 ) {
if ( F_9 ( * V_20 ) )
return ( unsigned long ) V_20 ;
V_20 ++ ;
V_2 -- ;
}
return 0 ;
}
static T_4 unsigned long F_17 ( const void * V_20 ,
const void * V_21 )
{
unsigned int V_22 ;
unsigned long V_23 ;
unsigned int V_24 = ( unsigned long ) V_20 % 8 ;
if ( V_21 - V_20 <= 16 )
return F_16 ( V_20 , V_21 - V_20 ) ;
if ( V_24 ) {
V_24 = 8 - V_24 ;
V_23 = F_16 ( V_20 , V_24 ) ;
if ( F_9 ( V_23 ) )
return V_23 ;
V_20 += V_24 ;
}
V_22 = ( V_21 - V_20 ) / 8 ;
while ( V_22 ) {
if ( F_9 ( * ( V_25 * ) V_20 ) )
return F_16 ( V_20 , 8 ) ;
V_20 += 8 ;
V_22 -- ;
}
return F_16 ( V_20 , ( V_21 - V_20 ) % 8 ) ;
}
static T_4 bool F_18 ( unsigned long V_14 ,
T_1 V_2 )
{
unsigned long V_23 ;
V_23 = F_17 ( F_2 ( ( void * ) V_14 ) ,
F_2 ( ( void * ) V_14 + V_2 - 1 ) + 1 ) ;
if ( F_9 ( V_23 ) ) {
unsigned long V_26 = V_14 + V_2 - 1 ;
T_5 * V_27 = ( T_5 * ) F_2 ( ( void * ) V_26 ) ;
if ( F_9 ( V_23 != ( unsigned long ) V_27 ||
( ( long ) ( V_26 & V_6 ) >= * V_27 ) ) )
return true ;
}
return false ;
}
static T_4 bool F_19 ( unsigned long V_14 , T_1 V_2 )
{
if ( F_20 ( V_2 ) ) {
switch ( V_2 ) {
case 1 :
return F_8 ( V_14 ) ;
case 2 :
return F_10 ( V_14 ) ;
case 4 :
return F_12 ( V_14 ) ;
case 8 :
return F_13 ( V_14 ) ;
case 16 :
return F_15 ( V_14 ) ;
default:
F_21 () ;
}
}
return F_18 ( V_14 , V_2 ) ;
}
static T_4 void F_22 ( unsigned long V_14 ,
T_1 V_2 , bool V_28 )
{
if ( F_9 ( V_2 == 0 ) )
return;
if ( F_9 ( ( void * ) V_14 <
F_23 ( ( void * ) V_29 ) ) ) {
F_24 ( V_14 , V_2 , V_28 , V_30 ) ;
return;
}
if ( F_11 ( ! F_19 ( V_14 , V_2 ) ) )
return;
F_24 ( V_14 , V_2 , V_28 , V_30 ) ;
}
void * memset ( void * V_14 , int V_31 , T_1 V_32 )
{
F_25 ( ( unsigned long ) V_14 , V_32 ) ;
return F_26 ( V_14 , V_31 , V_32 ) ;
}
void * memmove ( void * V_33 , const void * V_34 , T_1 V_32 )
{
F_27 ( ( unsigned long ) V_34 , V_32 ) ;
F_25 ( ( unsigned long ) V_33 , V_32 ) ;
return F_28 ( V_33 , V_34 , V_32 ) ;
}
void * memcpy ( void * V_33 , const void * V_34 , T_1 V_32 )
{
F_27 ( ( unsigned long ) V_34 , V_32 ) ;
F_25 ( ( unsigned long ) V_33 , V_32 ) ;
return F_29 ( V_33 , V_34 , V_32 ) ;
}
void F_30 ( struct V_35 * V_35 , unsigned int V_36 )
{
if ( F_11 ( ! F_31 ( V_35 ) ) )
F_3 ( F_32 ( V_35 ) , V_37 << V_36 ) ;
}
void F_33 ( struct V_35 * V_35 , unsigned int V_36 )
{
if ( F_11 ( ! F_31 ( V_35 ) ) )
F_1 ( F_32 ( V_35 ) ,
V_37 << V_36 ,
V_38 ) ;
}
void F_34 ( struct V_35 * V_35 )
{
F_1 ( F_32 ( V_35 ) ,
V_37 << F_35 ( V_35 ) ,
V_39 ) ;
}
void F_36 ( struct V_40 * V_41 , void * V_42 )
{
F_3 ( V_42 , V_41 -> V_43 ) ;
}
void F_37 ( struct V_40 * V_41 , void * V_42 )
{
F_1 ( V_42 ,
F_38 ( V_41 -> V_43 , V_18 ) ,
V_39 ) ;
}
void F_39 ( struct V_40 * V_41 , void * V_42 )
{
F_40 ( V_41 , V_42 , V_41 -> V_43 ) ;
}
void F_41 ( struct V_40 * V_41 , void * V_42 )
{
unsigned long V_2 = V_41 -> V_43 ;
unsigned long V_44 = F_38 ( V_2 , V_18 ) ;
if ( F_9 ( V_41 -> V_45 & V_46 ) )
return;
F_1 ( V_42 , V_44 , V_47 ) ;
}
void F_40 ( struct V_40 * V_41 , const void * V_42 , T_1 V_2 )
{
unsigned long V_48 ;
unsigned long V_49 ;
if ( F_9 ( V_42 == NULL ) )
return;
V_48 = F_38 ( ( unsigned long ) ( V_42 + V_2 ) ,
V_18 ) ;
V_49 = F_38 ( ( unsigned long ) V_42 + V_41 -> V_43 ,
V_18 ) ;
F_3 ( V_42 , V_2 ) ;
F_1 ( ( void * ) V_48 , V_49 - V_48 ,
V_39 ) ;
}
void F_42 ( const void * V_50 , T_1 V_2 )
{
struct V_35 * V_35 ;
unsigned long V_48 ;
unsigned long V_49 ;
if ( F_9 ( V_50 == NULL ) )
return;
V_35 = F_43 ( V_50 ) ;
V_48 = F_38 ( ( unsigned long ) ( V_50 + V_2 ) ,
V_18 ) ;
V_49 = ( unsigned long ) V_50 + ( V_37 << F_35 ( V_35 ) ) ;
F_3 ( V_50 , V_2 ) ;
F_1 ( ( void * ) V_48 , V_49 - V_48 ,
V_51 ) ;
}
void F_44 ( const void * V_42 , T_1 V_2 )
{
struct V_35 * V_35 ;
if ( F_9 ( V_42 == V_52 ) )
return;
V_35 = F_45 ( V_42 ) ;
if ( F_9 ( ! F_46 ( V_35 ) ) )
F_42 ( V_42 , V_2 ) ;
else
F_40 ( V_35 -> V_53 , V_42 , V_2 ) ;
}
void F_47 ( void * V_50 )
{
struct V_35 * V_35 ;
V_35 = F_45 ( V_50 ) ;
if ( F_9 ( ! F_46 ( V_35 ) ) )
F_1 ( V_50 , V_37 << F_35 ( V_35 ) ,
V_38 ) ;
else
F_41 ( V_35 -> V_53 , V_50 ) ;
}
void F_48 ( const void * V_50 )
{
struct V_35 * V_35 = F_43 ( V_50 ) ;
F_1 ( V_50 , V_37 << F_35 ( V_35 ) ,
V_38 ) ;
}
int F_49 ( void * V_14 , T_1 V_2 )
{
void * V_23 ;
T_1 V_54 ;
unsigned long V_4 ;
V_4 = ( unsigned long ) F_2 ( V_14 ) ;
V_54 = F_38 ( V_2 >> V_55 ,
V_37 ) ;
if ( F_50 ( ! F_51 ( V_4 ) ) )
return - V_56 ;
V_23 = F_52 ( V_54 , 1 , V_4 ,
V_4 + V_54 ,
V_57 | V_58 | V_59 ,
V_60 , V_61 , V_62 ,
F_53 ( 0 ) ) ;
if ( V_23 ) {
F_54 ( V_14 ) -> V_45 |= V_63 ;
F_55 ( V_23 ) ;
return 0 ;
}
return - V_64 ;
}
void F_56 ( const struct V_65 * V_66 )
{
if ( V_66 -> V_45 & V_63 )
F_57 ( F_2 ( V_66 -> V_14 ) ) ;
}
static void F_58 ( struct V_67 * V_68 )
{
T_1 V_69 = F_38 ( V_68 -> V_2 , V_18 ) ;
F_3 ( V_68 -> V_70 , V_68 -> V_2 ) ;
F_1 ( V_68 -> V_70 + V_69 ,
V_68 -> V_71 - V_69 ,
V_72 ) ;
}
void F_59 ( struct V_67 * V_73 , T_1 V_2 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_2 ; V_74 ++ )
F_58 ( & V_73 [ V_74 ] ) ;
}
void F_60 ( struct V_67 * V_73 , T_1 V_2 )
{
}
void F_27 ( unsigned long V_14 , T_1 V_2 )
{
F_22 ( V_14 , V_2 , false ) ;
}
void F_25 ( unsigned long V_14 , T_1 V_2 )
{
F_22 ( V_14 , V_2 , true ) ;
}
void F_61 ( void ) {}
static int F_62 ( struct V_75 * V_76 ,
unsigned long V_77 , void * V_78 )
{
return ( V_77 == V_79 ) ? V_80 : V_81 ;
}
static int T_8 F_63 ( void )
{
F_64 ( L_1 ) ;
F_64 ( L_2 ) ;
F_65 ( F_62 , 0 ) ;
return 0 ;
}
