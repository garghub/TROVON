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
static void F_9 ( struct V_29 * V_30 )
{
F_4 ( L_11 , V_30 -> V_31 ) ;
if ( V_30 -> V_28 ) {
struct V_32 V_33 ;
F_10 ( V_30 -> V_28 , & V_33 ) ;
F_11 ( & V_33 , 0 ) ;
} else {
F_4 ( L_12 ) ;
}
}
static void F_12 ( struct V_34 * V_35 , struct V_36 * V_36 ,
void * V_37 , char * V_38 )
{
struct V_39 * V_40 = F_13 ( V_35 , V_37 ) ;
struct V_41 * V_42 ;
F_14 () ;
F_4 ( L_13 , V_37 , V_35 -> V_43 ) ;
if ( ! ( V_35 -> V_44 & V_45 ) )
return;
switch ( V_40 -> V_46 ) {
case V_47 :
F_4 ( L_14 ) ;
break;
case V_48 :
F_4 ( L_15 ,
V_40 -> V_49 ) ;
F_4 ( L_16 ) ;
F_9 ( & V_40 -> V_30 ) ;
break;
case V_50 :
case V_51 :
F_4 ( L_17 ,
V_40 -> V_49 ) ;
V_42 = F_15 ( V_35 , V_37 ) ;
F_4 ( L_16 ) ;
F_9 ( & V_40 -> V_30 ) ;
F_4 ( L_18 ) ;
F_9 ( & V_42 -> V_30 ) ;
break;
}
}
static void F_16 ( struct V_6 * V_7 )
{
const void * V_1 = V_7 -> V_10 ;
if ( ( V_1 >= ( void * ) V_52 ) &&
( V_1 < V_53 ) ) {
struct V_36 * V_36 = F_17 ( V_1 ) ;
if ( F_18 ( V_36 ) ) {
void * V_37 ;
struct V_34 * V_35 = V_36 -> V_54 ;
V_37 = F_19 ( V_35 , V_36 ,
( void * ) V_7 -> V_10 ) ;
F_12 ( V_35 , V_36 , V_37 ,
L_19 ) ;
return;
}
F_20 ( V_36 , L_19 ) ;
}
if ( F_6 ( V_1 ) ) {
if ( ! F_8 ( V_1 ) )
F_4 ( L_20 , V_1 ) ;
}
F_14 () ;
}
static bool F_21 ( const void * V_55 , const void * V_56 )
{
return ( V_55 <= V_56 ) && ( V_56 < V_55 + V_57 ) ;
}
static int F_22 ( const void * V_55 , const void * V_58 )
{
return 3 + ( V_59 / 8 ) * 2 + ( V_58 - V_55 ) * 2 +
( V_58 - V_55 ) / V_60 + 1 ;
}
static void F_23 ( const void * V_1 )
{
int V_61 ;
const void * V_58 = F_2 ( V_1 ) ;
const void * V_62 ;
V_62 = ( void * ) F_24 ( ( unsigned long ) V_58 ,
V_57 )
- V_63 * V_57 ;
F_4 ( L_21 ) ;
for ( V_61 = - V_63 ; V_61 <= V_63 ; V_61 ++ ) {
const void * V_64 = F_25 ( V_62 ) ;
char V_65 [ 4 + ( V_59 / 8 ) * 2 ] ;
char V_66 [ V_57 ] ;
snprintf ( V_65 , sizeof( V_65 ) ,
( V_61 == 0 ) ? L_22 : L_23 , V_64 ) ;
memcpy ( V_66 , V_62 , V_57 ) ;
F_26 ( V_67 , V_65 ,
V_68 , V_57 , 1 ,
V_66 , V_57 , 0 ) ;
if ( F_21 ( V_62 , V_58 ) )
F_4 ( L_24 ,
F_22 ( V_62 , V_58 ) ,
'^' ) ;
V_62 += V_57 ;
}
}
static void F_27 ( struct V_6 * V_7 )
{
unsigned long V_44 ;
const char * V_8 ;
F_28 () ;
F_29 ( & V_69 , V_44 ) ;
F_4 ( L_25 ) ;
if ( V_7 -> V_10 <
F_25 ( ( void * ) V_70 ) ) {
if ( ( unsigned long ) V_7 -> V_10 < V_71 )
V_8 = L_26 ;
else if ( ( unsigned long ) V_7 -> V_10 < V_72 )
V_8 = L_27 ;
else
V_8 = L_28 ;
F_4 ( L_29 ,
V_8 , V_7 -> V_10 ) ;
F_4 ( L_8 ,
V_7 -> V_22 ? L_9 : L_10 ,
V_7 -> V_11 , V_23 -> V_24 ,
F_5 ( V_23 ) ) ;
F_14 () ;
} else {
F_3 ( V_7 ) ;
F_16 ( V_7 ) ;
F_23 ( V_7 -> V_4 ) ;
}
F_4 ( L_25 ) ;
F_30 ( V_73 , V_74 ) ;
F_31 ( & V_69 , V_44 ) ;
F_32 () ;
}
void F_33 ( unsigned long V_1 , T_1 V_2 ,
bool V_22 , unsigned long V_21 )
{
struct V_6 V_7 ;
if ( F_34 ( ! F_35 () ) )
return;
V_7 . V_10 = ( void * ) V_1 ;
V_7 . V_11 = V_2 ;
V_7 . V_22 = V_22 ;
V_7 . V_21 = V_21 ;
F_27 ( & V_7 ) ;
}
void F_36 ( unsigned long V_1 , T_1 V_2 )
{
F_33 ( V_1 , V_2 , false , V_75 ) ;
}
void F_37 ( unsigned long V_1 , T_1 V_2 )
{
F_33 ( V_1 , V_2 , true , V_75 ) ;
}
