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
}
F_4 ( L_7 ,
V_8 , ( void * ) V_7 -> V_21 ,
V_7 -> V_10 ) ;
F_4 ( L_8 ,
V_7 -> V_22 ? L_9 : L_10 ,
V_7 -> V_11 , V_23 -> V_24 , F_5 ( V_23 ) ) ;
}
static inline bool F_6 ( const void * V_1 )
{
if ( V_1 >= ( void * ) V_25 && V_1 < ( void * ) V_26 )
return true ;
if ( F_7 ( ( unsigned long ) V_1 ) )
return true ;
return false ;
}
static inline bool F_8 ( const void * V_1 )
{
return V_1 >= ( void * ) & V_27 . V_28 &&
( V_1 <= ( void * ) & V_27 . V_28 +
sizeof( V_27 . V_28 ) ) ;
}
static void F_9 ( unsigned long * V_29 )
{
F_10 () ;
F_11 ( & V_30 , * V_29 ) ;
F_4 ( L_11 ) ;
}
static void F_12 ( unsigned long * V_29 )
{
F_4 ( L_11 ) ;
F_13 ( V_31 , V_32 ) ;
F_14 ( & V_30 , * V_29 ) ;
F_15 () ;
}
static void F_16 ( struct V_33 * V_34 )
{
F_4 ( L_12 , V_34 -> V_35 ) ;
if ( V_34 -> V_28 ) {
struct V_36 V_37 ;
F_17 ( V_34 -> V_28 , & V_37 ) ;
F_18 ( & V_37 , 0 ) ;
} else {
F_4 ( L_13 ) ;
}
}
static void F_19 ( struct V_38 * V_39 , void * V_40 )
{
struct V_41 * V_42 = F_20 ( V_39 , V_40 ) ;
F_21 () ;
F_4 ( L_14 , V_40 , V_39 -> V_43 ,
V_39 -> V_44 ) ;
if ( ! ( V_39 -> V_29 & V_45 ) )
return;
F_4 ( L_15 ) ;
F_16 ( & V_42 -> V_46 ) ;
F_4 ( L_16 ) ;
F_16 ( & V_42 -> V_47 ) ;
}
void F_22 ( struct V_38 * V_39 , void * V_40 ,
T_3 V_48 )
{
unsigned long V_29 ;
F_9 ( & V_29 ) ;
F_4 ( L_17 ) ;
F_4 ( L_18 , V_48 ) ;
F_19 ( V_39 , V_40 ) ;
F_12 ( & V_29 ) ;
}
static void F_23 ( struct V_6 * V_7 )
{
const void * V_1 = V_7 -> V_10 ;
if ( ( V_1 >= ( void * ) V_49 ) &&
( V_1 < V_50 ) ) {
struct V_51 * V_51 = F_24 ( V_1 ) ;
if ( F_25 ( V_51 ) ) {
void * V_40 ;
struct V_38 * V_39 = V_51 -> V_52 ;
V_40 = F_26 ( V_39 , V_51 ,
( void * ) V_7 -> V_10 ) ;
F_19 ( V_39 , V_40 ) ;
return;
}
F_27 ( V_51 , L_19 ) ;
}
if ( F_6 ( V_1 ) ) {
if ( ! F_8 ( V_1 ) )
F_4 ( L_20 , V_1 ) ;
}
F_21 () ;
}
static bool F_28 ( const void * V_53 , const void * V_54 )
{
return ( V_53 <= V_54 ) && ( V_54 < V_53 + V_55 ) ;
}
static int F_29 ( const void * V_53 , const void * V_48 )
{
return 3 + ( V_56 / 8 ) * 2 + ( V_48 - V_53 ) * 2 +
( V_48 - V_53 ) / V_57 + 1 ;
}
static void F_30 ( const void * V_1 )
{
int V_58 ;
const void * V_48 = F_2 ( V_1 ) ;
const void * V_59 ;
V_59 = ( void * ) F_31 ( ( unsigned long ) V_48 ,
V_55 )
- V_60 * V_55 ;
F_4 ( L_21 ) ;
for ( V_58 = - V_60 ; V_58 <= V_60 ; V_58 ++ ) {
const void * V_61 = F_32 ( V_59 ) ;
char V_62 [ 4 + ( V_56 / 8 ) * 2 ] ;
char V_63 [ V_55 ] ;
snprintf ( V_62 , sizeof( V_62 ) ,
( V_58 == 0 ) ? L_22 : L_23 , V_61 ) ;
memcpy ( V_63 , V_59 , V_55 ) ;
F_33 ( V_64 , V_62 ,
V_65 , V_55 , 1 ,
V_63 , V_55 , 0 ) ;
if ( F_28 ( V_59 , V_48 ) )
F_4 ( L_24 ,
F_29 ( V_59 , V_48 ) ,
'^' ) ;
V_59 += V_55 ;
}
}
static void F_34 ( struct V_6 * V_7 )
{
unsigned long V_29 ;
const char * V_8 ;
F_9 ( & V_29 ) ;
if ( V_7 -> V_10 <
F_32 ( ( void * ) V_66 ) ) {
if ( ( unsigned long ) V_7 -> V_10 < V_67 )
V_8 = L_25 ;
else if ( ( unsigned long ) V_7 -> V_10 < V_68 )
V_8 = L_26 ;
else
V_8 = L_27 ;
F_4 ( L_28 ,
V_8 , V_7 -> V_10 ) ;
F_4 ( L_8 ,
V_7 -> V_22 ? L_9 : L_10 ,
V_7 -> V_11 , V_23 -> V_24 ,
F_5 ( V_23 ) ) ;
F_21 () ;
} else {
F_3 ( V_7 ) ;
F_23 ( V_7 ) ;
F_30 ( V_7 -> V_4 ) ;
}
F_12 ( & V_29 ) ;
}
void F_35 ( unsigned long V_1 , T_1 V_2 ,
bool V_22 , unsigned long V_21 )
{
struct V_6 V_7 ;
if ( F_36 ( ! F_37 () ) )
return;
V_7 . V_10 = ( void * ) V_1 ;
V_7 . V_11 = V_2 ;
V_7 . V_22 = V_22 ;
V_7 . V_21 = V_21 ;
F_34 ( & V_7 ) ;
}
void F_38 ( unsigned long V_1 , T_1 V_2 )
{
F_35 ( V_1 , V_2 , false , V_69 ) ;
}
void F_39 ( unsigned long V_1 , T_1 V_2 )
{
F_35 ( V_1 , V_2 , true , V_69 ) ;
}
