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
if ( V_34 )
F_15 ( L_13 ) ;
F_16 () ;
}
static void F_17 ( struct V_35 * V_36 )
{
F_4 ( L_14 , V_36 -> V_37 ) ;
if ( V_36 -> V_29 ) {
struct V_38 V_39 ;
F_18 ( V_36 -> V_29 , & V_39 ) ;
F_19 ( & V_39 , 0 ) ;
} else {
F_4 ( L_15 ) ;
}
}
static void F_20 ( struct V_40 * V_41 , void * V_42 )
{
struct V_43 * V_44 = F_21 ( V_41 , V_42 ) ;
F_22 () ;
F_4 ( L_16 , V_42 , V_41 -> V_45 ,
V_41 -> V_46 ) ;
if ( ! ( V_41 -> V_30 & V_47 ) )
return;
F_4 ( L_17 ) ;
F_17 ( & V_44 -> V_48 ) ;
F_4 ( L_18 ) ;
F_17 ( & V_44 -> V_49 ) ;
}
void F_23 ( struct V_40 * V_41 , void * V_42 ,
T_3 V_50 )
{
unsigned long V_30 ;
F_9 ( & V_30 ) ;
F_4 ( L_19 ) ;
F_4 ( L_20 , V_50 ) ;
F_20 ( V_41 , V_42 ) ;
F_12 ( & V_30 ) ;
}
static void F_24 ( struct V_6 * V_7 )
{
const void * V_1 = V_7 -> V_10 ;
if ( ( V_1 >= ( void * ) V_51 ) &&
( V_1 < V_52 ) ) {
struct V_53 * V_53 = F_25 ( V_1 ) ;
if ( F_26 ( V_53 ) ) {
void * V_42 ;
struct V_40 * V_41 = V_53 -> V_54 ;
V_42 = F_27 ( V_41 , V_53 ,
( void * ) V_7 -> V_10 ) ;
F_20 ( V_41 , V_42 ) ;
return;
}
F_28 ( V_53 , L_21 ) ;
}
if ( F_6 ( V_1 ) ) {
if ( ! F_8 ( V_1 ) )
F_4 ( L_22 , V_1 ) ;
}
F_22 () ;
}
static bool F_29 ( const void * V_55 , const void * V_56 )
{
return ( V_55 <= V_56 ) && ( V_56 < V_55 + V_57 ) ;
}
static int F_30 ( const void * V_55 , const void * V_50 )
{
return 3 + ( V_58 / 8 ) * 2 + ( V_50 - V_55 ) * 2 +
( V_50 - V_55 ) / V_59 + 1 ;
}
static void F_31 ( const void * V_1 )
{
int V_60 ;
const void * V_50 = F_2 ( V_1 ) ;
const void * V_61 ;
V_61 = ( void * ) F_32 ( ( unsigned long ) V_50 ,
V_57 )
- V_62 * V_57 ;
F_4 ( L_23 ) ;
for ( V_60 = - V_62 ; V_60 <= V_62 ; V_60 ++ ) {
const void * V_63 = F_33 ( V_61 ) ;
char V_64 [ 4 + ( V_58 / 8 ) * 2 ] ;
char V_65 [ V_57 ] ;
snprintf ( V_64 , sizeof( V_64 ) ,
( V_60 == 0 ) ? L_24 : L_25 , V_63 ) ;
memcpy ( V_65 , V_61 , V_57 ) ;
F_34 ( V_66 , V_64 ,
V_67 , V_57 , 1 ,
V_65 , V_57 , 0 ) ;
if ( F_29 ( V_61 , V_50 ) )
F_4 ( L_26 ,
F_30 ( V_61 , V_50 ) ,
'^' ) ;
V_61 += V_57 ;
}
}
static void F_35 ( struct V_6 * V_7 )
{
unsigned long V_30 ;
const char * V_8 ;
F_9 ( & V_30 ) ;
if ( V_7 -> V_10 <
F_33 ( ( void * ) V_68 ) ) {
if ( ( unsigned long ) V_7 -> V_10 < V_69 )
V_8 = L_27 ;
else if ( ( unsigned long ) V_7 -> V_10 < V_70 )
V_8 = L_28 ;
else
V_8 = L_29 ;
F_4 ( L_30 ,
V_8 , V_7 -> V_10 ) ;
F_4 ( L_9 ,
V_7 -> V_23 ? L_10 : L_11 ,
V_7 -> V_11 , V_24 -> V_25 ,
F_5 ( V_24 ) ) ;
F_22 () ;
} else {
F_3 ( V_7 ) ;
F_24 ( V_7 ) ;
F_31 ( V_7 -> V_4 ) ;
}
F_12 ( & V_30 ) ;
}
void F_36 ( unsigned long V_1 , T_1 V_2 ,
bool V_23 , unsigned long V_22 )
{
struct V_6 V_7 ;
if ( F_37 ( ! F_38 () ) )
return;
F_39 () ;
V_7 . V_10 = ( void * ) V_1 ;
V_7 . V_11 = V_2 ;
V_7 . V_23 = V_23 ;
V_7 . V_22 = V_22 ;
F_35 ( & V_7 ) ;
}
void F_40 ( unsigned long V_1 , T_1 V_2 )
{
F_36 ( V_1 , V_2 , false , V_71 ) ;
}
void F_41 ( unsigned long V_1 , T_1 V_2 )
{
F_36 ( V_1 , V_2 , true , V_71 ) ;
}
