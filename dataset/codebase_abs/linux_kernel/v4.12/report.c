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
static bool F_3 ( struct V_6 * V_7 )
{
return ( V_7 -> V_8 >=
F_4 ( ( void * ) V_9 ) ) ;
}
static const char * F_5 ( struct V_6 * V_7 )
{
const char * V_10 = L_1 ;
T_2 * V_11 ;
V_7 -> V_4 = F_1 ( V_7 -> V_8 ,
V_7 -> V_12 ) ;
V_11 = ( T_2 * ) F_2 ( V_7 -> V_4 ) ;
if ( * V_11 > 0 && * V_11 <= V_5 - 1 )
V_11 ++ ;
switch ( * V_11 ) {
case 0 ... V_5 - 1 :
V_10 = L_2 ;
break;
case V_13 :
case V_14 :
V_10 = L_3 ;
break;
case V_15 :
V_10 = L_4 ;
break;
case V_16 :
case V_17 :
case V_18 :
case V_19 :
V_10 = L_5 ;
break;
case V_20 :
case V_21 :
V_10 = L_6 ;
break;
case V_22 :
V_10 = L_7 ;
break;
}
return V_10 ;
}
const char * F_6 ( struct V_6 * V_7 )
{
const char * V_10 = L_1 ;
if ( ( unsigned long ) V_7 -> V_8 < V_23 )
V_10 = L_8 ;
else if ( ( unsigned long ) V_7 -> V_8 < V_24 )
V_10 = L_9 ;
else
V_10 = L_10 ;
return V_10 ;
}
static const char * F_7 ( struct V_6 * V_7 )
{
if ( F_3 ( V_7 ) )
return F_5 ( V_7 ) ;
return F_6 ( V_7 ) ;
}
static void F_8 ( struct V_6 * V_7 )
{
const char * V_10 = F_7 ( V_7 ) ;
F_9 ( L_11 ,
V_10 , ( void * ) V_7 -> V_25 ) ;
F_9 ( L_12 ,
V_7 -> V_26 ? L_13 : L_14 , V_7 -> V_12 ,
V_7 -> V_8 , V_27 -> V_28 , F_10 ( V_27 ) ) ;
}
static inline bool F_11 ( const void * V_1 )
{
if ( V_1 >= ( void * ) V_29 && V_1 < ( void * ) V_30 )
return true ;
if ( F_12 ( ( unsigned long ) V_1 ) )
return true ;
return false ;
}
static inline bool F_13 ( const void * V_1 )
{
return V_1 >= ( void * ) & V_31 . V_32 &&
( V_1 <= ( void * ) & V_31 . V_32 +
sizeof( V_31 . V_32 ) ) ;
}
static void F_14 ( unsigned long * V_33 )
{
F_15 () ;
F_16 ( & V_34 , * V_33 ) ;
F_9 ( L_15 ) ;
}
static void F_17 ( unsigned long * V_33 )
{
F_9 ( L_15 ) ;
F_18 ( V_35 , V_36 ) ;
F_19 ( & V_34 , * V_33 ) ;
if ( V_37 )
F_20 ( L_16 ) ;
F_21 () ;
}
static void F_22 ( struct V_38 * V_39 , const char * V_40 )
{
F_9 ( L_17 , V_40 , V_39 -> V_41 ) ;
if ( V_39 -> V_32 ) {
struct V_42 V_43 ;
F_23 ( V_39 -> V_32 , & V_43 ) ;
F_24 ( & V_43 , 0 ) ;
} else {
F_9 ( L_18 ) ;
}
}
static struct V_44 * F_25 ( const void * V_1 )
{
if ( ( V_1 >= ( void * ) V_45 ) &&
( V_1 < V_46 ) )
return F_26 ( V_1 ) ;
return NULL ;
}
static void F_27 ( struct V_47 * V_48 , void * V_49 ,
const void * V_1 )
{
unsigned long V_8 = ( unsigned long ) V_1 ;
unsigned long V_50 = ( unsigned long ) V_49 ;
const char * V_51 ;
int V_52 ;
F_9 ( L_19
L_20 ,
V_49 , V_48 -> V_53 , V_48 -> V_54 ) ;
if ( ! V_1 )
return;
if ( V_8 < V_50 ) {
V_51 = L_21 ;
V_52 = V_50 - V_8 ;
} else if ( V_8 >= V_50 + V_48 -> V_54 ) {
V_51 = L_22 ;
V_52 = V_8 - ( V_50 + V_48 -> V_54 ) ;
} else {
V_51 = L_23 ;
V_52 = V_8 - V_50 ;
}
F_9 ( L_24
L_25 ,
V_52 , V_51 , V_48 -> V_54 , ( void * ) V_50 ,
( void * ) ( V_50 + V_48 -> V_54 ) ) ;
}
static void F_28 ( struct V_47 * V_48 , void * V_49 ,
const void * V_1 )
{
struct V_55 * V_56 = F_29 ( V_48 , V_49 ) ;
if ( V_48 -> V_33 & V_57 ) {
F_22 ( & V_56 -> V_58 , L_26 ) ;
F_9 ( L_27 ) ;
F_22 ( & V_56 -> V_59 , L_28 ) ;
F_9 ( L_27 ) ;
}
F_27 ( V_48 , V_49 , V_1 ) ;
}
static void F_30 ( void * V_1 )
{
struct V_44 * V_44 = F_25 ( V_1 ) ;
F_31 () ;
F_9 ( L_27 ) ;
if ( V_44 && F_32 ( V_44 ) ) {
struct V_47 * V_48 = V_44 -> V_60 ;
void * V_49 = F_33 ( V_48 , V_44 , V_1 ) ;
F_28 ( V_48 , V_49 , V_1 ) ;
}
if ( F_11 ( V_1 ) && ! F_13 ( V_1 ) ) {
F_9 ( L_29 ) ;
F_9 ( L_30 , V_1 ) ;
}
if ( V_44 ) {
F_9 ( L_31 ) ;
F_34 ( V_44 , L_32 ) ;
}
}
static bool F_35 ( const void * V_61 , const void * V_62 )
{
return ( V_61 <= V_62 ) && ( V_62 < V_61 + V_63 ) ;
}
static int F_36 ( const void * V_61 , const void * V_64 )
{
return 3 + ( V_65 / 8 ) * 2 + ( V_64 - V_61 ) * 2 +
( V_64 - V_61 ) / V_66 + 1 ;
}
static void F_37 ( const void * V_1 )
{
int V_67 ;
const void * V_64 = F_2 ( V_1 ) ;
const void * V_68 ;
V_68 = ( void * ) F_38 ( ( unsigned long ) V_64 ,
V_63 )
- V_69 * V_63 ;
F_9 ( L_33 ) ;
for ( V_67 = - V_69 ; V_67 <= V_69 ; V_67 ++ ) {
const void * V_70 = F_4 ( V_68 ) ;
char V_71 [ 4 + ( V_65 / 8 ) * 2 ] ;
char V_72 [ V_63 ] ;
snprintf ( V_71 , sizeof( V_71 ) ,
( V_67 == 0 ) ? L_34 : L_35 , V_70 ) ;
memcpy ( V_72 , V_68 , V_63 ) ;
F_39 ( V_73 , V_71 ,
V_74 , V_63 , 1 ,
V_72 , V_63 , 0 ) ;
if ( F_35 ( V_68 , V_64 ) )
F_9 ( L_36 ,
F_36 ( V_68 , V_64 ) ,
'^' ) ;
V_68 += V_63 ;
}
}
void F_40 ( struct V_47 * V_48 , void * V_49 ,
void * V_25 )
{
unsigned long V_33 ;
F_14 ( & V_33 ) ;
F_9 ( L_37 , V_25 ) ;
F_9 ( L_27 ) ;
F_30 ( V_49 ) ;
F_9 ( L_27 ) ;
F_37 ( V_49 ) ;
F_17 ( & V_33 ) ;
}
static void F_41 ( struct V_6 * V_7 )
{
unsigned long V_33 ;
F_14 ( & V_33 ) ;
F_8 ( V_7 ) ;
F_9 ( L_27 ) ;
if ( ! F_3 ( V_7 ) ) {
F_31 () ;
} else {
F_30 ( ( void * ) V_7 -> V_8 ) ;
F_9 ( L_27 ) ;
F_37 ( V_7 -> V_4 ) ;
}
F_17 ( & V_33 ) ;
}
bool F_42 ( void )
{
return F_43 ( V_75 , & V_76 ) ;
}
void F_44 ( bool V_77 )
{
if ( ! V_77 )
F_45 ( V_75 , & V_76 ) ;
}
static int T_3 F_46 ( char * V_78 )
{
F_47 ( V_75 , & V_76 ) ;
return 1 ;
}
static inline bool F_48 ( void )
{
if ( V_27 -> V_79 )
return false ;
if ( F_49 ( V_75 , & V_76 ) )
return true ;
return ! F_43 ( V_80 , & V_76 ) ;
}
void F_50 ( unsigned long V_1 , T_1 V_2 ,
bool V_26 , unsigned long V_25 )
{
struct V_6 V_7 ;
if ( F_51 ( ! F_48 () ) )
return;
F_52 () ;
V_7 . V_8 = ( void * ) V_1 ;
V_7 . V_12 = V_2 ;
V_7 . V_26 = V_26 ;
V_7 . V_25 = V_25 ;
F_41 ( & V_7 ) ;
}
void F_53 ( unsigned long V_1 , T_1 V_2 )
{
F_50 ( V_1 , V_2 , false , V_81 ) ;
}
void F_54 ( unsigned long V_1 , T_1 V_2 )
{
F_50 ( V_1 , V_2 , true , V_81 ) ;
}
