static const void * F_1 ( const void * V_1 , T_1 V_2 )
{
T_2 V_3 = * ( T_2 * ) F_2 ( V_1 ) ;
const void * V_4 = V_1 ;
while ( ! V_3 && V_4 < V_1 + V_2 ) {
V_4 += V_5 ;
V_3 = * ( T_2 * ) F_2 ( V_4 ) ;
}
return V_4 ;
}
static void F_3 ( struct V_6 * V_7 )
{
const char * V_8 = L_1 ;
T_2 * V_9 ;
V_7 -> V_4 = F_1 ( V_7 -> V_10 ,
V_7 -> V_11 ) ;
V_9 = ( T_2 * ) F_2 ( V_7 -> V_4 ) ;
if ( * V_9 > 0 && * V_9 <= V_5 - 1 )
V_9 ++ ;
switch ( * V_9 ) {
case 0 ... V_5 - 1 :
V_8 = L_2 ;
break;
case V_12 :
case V_13 :
V_8 = L_3 ;
break;
case V_14 :
V_8 = L_4 ;
break;
case V_15 :
case V_16 :
case V_17 :
case V_18 :
V_8 = L_5 ;
break;
case V_19 :
case V_20 :
V_8 = L_6 ;
break;
case V_21 :
V_8 = L_7 ;
break;
}
F_4 ( L_8 ,
V_8 , ( void * ) V_7 -> V_22 ,
V_7 -> V_10 ) ;
F_4 ( L_9 ,
V_7 -> V_23 ? L_10 : L_11 ,
V_7 -> V_11 , V_24 -> V_25 , F_5 ( V_24 ) ) ;
}
static inline bool F_6 ( const void * V_1 )
{
if ( V_1 >= ( void * ) V_26 && V_1 < ( void * ) V_27 )
return true ;
if ( F_7 ( ( unsigned long ) V_1 ) )
return true ;
return false ;
}
static inline bool F_8 ( const void * V_1 )
{
return V_1 >= ( void * ) & V_28 . V_29 &&
( V_1 <= ( void * ) & V_28 . V_29 +
sizeof( V_28 . V_29 ) ) ;
}
static void F_9 ( unsigned long * V_30 )
{
F_10 () ;
F_11 ( & V_31 , * V_30 ) ;
F_4 ( L_12 ) ;
}
static void F_12 ( unsigned long * V_30 )
{
F_4 ( L_12 ) ;
F_13 ( V_32 , V_33 ) ;
F_14 ( & V_31 , * V_30 ) ;
F_15 () ;
}
static void F_16 ( struct V_34 * V_35 )
{
F_4 ( L_13 , V_35 -> V_36 ) ;
if ( V_35 -> V_29 ) {
struct V_37 V_38 ;
F_17 ( V_35 -> V_29 , & V_38 ) ;
F_18 ( & V_38 , 0 ) ;
} else {
F_4 ( L_14 ) ;
}
}
static void F_19 ( struct V_39 * V_40 , void * V_41 )
{
struct V_42 * V_43 = F_20 ( V_40 , V_41 ) ;
F_21 () ;
F_4 ( L_15 , V_41 , V_40 -> V_44 ,
V_40 -> V_45 ) ;
if ( ! ( V_40 -> V_30 & V_46 ) )
return;
F_4 ( L_16 ) ;
F_16 ( & V_43 -> V_47 ) ;
F_4 ( L_17 ) ;
F_16 ( & V_43 -> V_48 ) ;
}
void F_22 ( struct V_39 * V_40 , void * V_41 ,
T_3 V_49 )
{
unsigned long V_30 ;
F_9 ( & V_30 ) ;
F_4 ( L_18 ) ;
F_4 ( L_19 , V_49 ) ;
F_19 ( V_40 , V_41 ) ;
F_12 ( & V_30 ) ;
}
static void F_23 ( struct V_6 * V_7 )
{
const void * V_1 = V_7 -> V_10 ;
if ( ( V_1 >= ( void * ) V_50 ) &&
( V_1 < V_51 ) ) {
struct V_52 * V_52 = F_24 ( V_1 ) ;
if ( F_25 ( V_52 ) ) {
void * V_41 ;
struct V_39 * V_40 = V_52 -> V_53 ;
V_41 = F_26 ( V_40 , V_52 ,
( void * ) V_7 -> V_10 ) ;
F_19 ( V_40 , V_41 ) ;
return;
}
F_27 ( V_52 , L_20 ) ;
}
if ( F_6 ( V_1 ) ) {
if ( ! F_8 ( V_1 ) )
F_4 ( L_21 , V_1 ) ;
}
F_21 () ;
}
static bool F_28 ( const void * V_54 , const void * V_55 )
{
return ( V_54 <= V_55 ) && ( V_55 < V_54 + V_56 ) ;
}
static int F_29 ( const void * V_54 , const void * V_49 )
{
return 3 + ( V_57 / 8 ) * 2 + ( V_49 - V_54 ) * 2 +
( V_49 - V_54 ) / V_58 + 1 ;
}
static void F_30 ( const void * V_1 )
{
int V_59 ;
const void * V_49 = F_2 ( V_1 ) ;
const void * V_60 ;
V_60 = ( void * ) F_31 ( ( unsigned long ) V_49 ,
V_56 )
- V_61 * V_56 ;
F_4 ( L_22 ) ;
for ( V_59 = - V_61 ; V_59 <= V_61 ; V_59 ++ ) {
const void * V_62 = F_32 ( V_60 ) ;
char V_63 [ 4 + ( V_57 / 8 ) * 2 ] ;
char V_64 [ V_56 ] ;
snprintf ( V_63 , sizeof( V_63 ) ,
( V_59 == 0 ) ? L_23 : L_24 , V_62 ) ;
memcpy ( V_64 , V_60 , V_56 ) ;
F_33 ( V_65 , V_63 ,
V_66 , V_56 , 1 ,
V_64 , V_56 , 0 ) ;
if ( F_28 ( V_60 , V_49 ) )
F_4 ( L_25 ,
F_29 ( V_60 , V_49 ) ,
'^' ) ;
V_60 += V_56 ;
}
}
static void F_34 ( struct V_6 * V_7 )
{
unsigned long V_30 ;
const char * V_8 ;
F_9 ( & V_30 ) ;
if ( V_7 -> V_10 <
F_32 ( ( void * ) V_67 ) ) {
if ( ( unsigned long ) V_7 -> V_10 < V_68 )
V_8 = L_26 ;
else if ( ( unsigned long ) V_7 -> V_10 < V_69 )
V_8 = L_27 ;
else
V_8 = L_28 ;
F_4 ( L_29 ,
V_8 , V_7 -> V_10 ) ;
F_4 ( L_9 ,
V_7 -> V_23 ? L_10 : L_11 ,
V_7 -> V_11 , V_24 -> V_25 ,
F_5 ( V_24 ) ) ;
F_21 () ;
} else {
F_3 ( V_7 ) ;
F_23 ( V_7 ) ;
F_30 ( V_7 -> V_4 ) ;
}
F_12 ( & V_30 ) ;
}
void F_35 ( unsigned long V_1 , T_1 V_2 ,
bool V_23 , unsigned long V_22 )
{
struct V_6 V_7 ;
if ( F_36 ( ! F_37 () ) )
return;
V_7 . V_10 = ( void * ) V_1 ;
V_7 . V_11 = V_2 ;
V_7 . V_23 = V_23 ;
V_7 . V_22 = V_22 ;
F_34 ( & V_7 ) ;
}
void F_38 ( unsigned long V_1 , T_1 V_2 )
{
F_35 ( V_1 , V_2 , false , V_70 ) ;
}
void F_39 ( unsigned long V_1 , T_1 V_2 )
{
F_35 ( V_1 , V_2 , true , V_70 ) ;
}
