static int F_1 ( T_1 V_1 )
{
return ( V_1 + V_2 - 1 ) >> V_3 ;
}
static struct V_4 * F_2 ( struct V_5 * V_5 )
{
struct V_4 * V_6 = F_3 ( V_5 ) ;
F_4 ( & V_5 -> V_7 ) ;
F_5 ( V_8 , & V_5 -> V_9 ) ;
F_5 ( V_10 , & V_5 -> V_9 ) ;
F_6 ( & V_6 -> V_11 ) ;
F_7 ( & V_6 -> V_12 ) ;
V_6 -> V_13 = 0 ;
V_6 -> V_14 = 0 ;
V_6 -> V_15 = 0 ;
V_6 -> V_16 = 0 ;
V_6 -> V_17 = 0 ;
F_4 ( & V_6 -> V_18 ) ;
return V_6 ;
}
static void F_8 ( struct V_5 * V_5 )
{
F_9 ( V_5 ) ;
}
static void F_10 ( struct V_19 * V_20 )
{
struct V_4 * V_6 ;
struct V_5 * V_5 ;
V_6 = F_11 ( V_20 , struct V_4 , V_12 ) ;
V_5 = F_12 ( V_6 ) ;
if ( ! F_13 ( & V_6 -> V_18 ) )
F_14 ( & V_6 -> V_18 ) ;
if ( ! F_13 ( & V_5 -> V_7 ) )
F_14 ( & V_5 -> V_7 ) ;
F_8 ( V_5 ) ;
}
static inline void F_15 ( struct V_4 * V_6 )
{
F_16 ( & V_6 -> V_11 ) ;
}
static inline int F_17 ( struct V_4 * V_6 )
{
return F_18 ( & V_6 -> V_11 ) ;
}
static inline void F_19 ( struct V_4 * V_6 )
{
F_20 ( & V_6 -> V_11 ) ;
}
static unsigned long F_21 ( struct V_4 * V_6 , enum V_18 V_21 )
{
unsigned long V_22 ;
V_22 = ( unsigned long ) V_6 ;
if ( V_21 != V_23 )
V_22 += ( V_21 + V_6 -> V_16 ) & V_24 ;
return V_22 ;
}
static struct V_4 * F_22 ( unsigned long V_22 )
{
return (struct V_4 * ) ( V_22 & V_25 ) ;
}
static enum V_18 F_23 ( unsigned long V_22 )
{
struct V_4 * V_6 = F_22 ( V_22 ) ;
return ( V_22 - V_6 -> V_16 ) & V_24 ;
}
static int F_24 ( struct V_4 * V_6 )
{
int V_26 ;
if ( V_6 -> V_14 != 0 ) {
int V_27 = V_6 -> V_13 ?
0 : V_6 -> V_17 - V_28 ;
int V_29 = V_6 -> V_15 ?
0 : V_30 -
( V_6 -> V_17 + V_6 -> V_14 ) ;
V_26 = F_25 ( V_27 , V_29 ) ;
} else
V_26 = V_31 - V_6 -> V_13 - V_6 -> V_15 ;
return V_26 ;
}
static struct V_32 * F_26 ( T_2 V_33 ,
const struct V_34 * V_35 )
{
struct V_32 * V_36 ;
int V_37 ;
V_36 = F_27 ( sizeof( struct V_32 ) , V_33 ) ;
if ( ! V_36 )
return NULL ;
F_6 ( & V_36 -> V_38 ) ;
F_28 (i, 0 )
F_4 ( & V_36 -> V_39 [ V_37 ] ) ;
F_4 ( & V_36 -> V_7 ) ;
F_29 ( & V_36 -> V_40 , 0 ) ;
V_36 -> V_35 = V_35 ;
return V_36 ;
}
static void F_30 ( struct V_32 * V_36 )
{
F_31 ( V_36 ) ;
}
static inline void * F_32 ( struct V_4 * V_6 ,
unsigned short V_41 )
{
void * V_42 = V_6 ;
return memmove ( V_42 + ( V_41 << V_3 ) ,
V_42 + ( V_6 -> V_17 << V_3 ) ,
V_6 -> V_14 << V_3 ) ;
}
static int F_33 ( struct V_4 * V_6 )
{
struct V_5 * V_5 = F_12 ( V_6 ) ;
if ( F_34 ( V_10 , & V_5 -> V_9 ) )
return 0 ;
if ( V_6 -> V_14 == 0 )
return 0 ;
if ( V_6 -> V_13 == 0 && V_6 -> V_15 == 0 ) {
F_32 ( V_6 , V_28 ) ;
V_6 -> V_13 = V_6 -> V_14 ;
V_6 -> V_14 = 0 ;
V_6 -> V_17 = 0 ;
V_6 -> V_16 ++ ;
return 1 ;
}
if ( V_6 -> V_13 != 0 && V_6 -> V_15 == 0 &&
V_6 -> V_17 - ( V_6 -> V_13 + V_28 ) >=
V_43 ) {
F_32 ( V_6 , V_6 -> V_13 + V_28 ) ;
V_6 -> V_17 = V_6 -> V_13 + V_28 ;
return 1 ;
} else if ( V_6 -> V_15 != 0 && V_6 -> V_13 == 0 &&
V_30 - ( V_6 -> V_15 + V_6 -> V_17
+ V_6 -> V_14 ) >=
V_43 ) {
unsigned short V_44 = V_30 - V_6 -> V_15 -
V_6 -> V_14 ;
F_32 ( V_6 , V_44 ) ;
V_6 -> V_17 = V_44 ;
return 1 ;
}
return 0 ;
}
static int F_35 ( struct V_32 * V_36 , T_1 V_1 , T_2 V_33 ,
unsigned long * V_22 )
{
int V_45 = 0 , V_37 , V_46 ;
struct V_4 * V_6 = NULL ;
enum V_18 V_21 ;
struct V_5 * V_5 ;
if ( ! V_1 || ( V_33 & V_47 ) )
return - V_48 ;
if ( V_1 > V_49 )
return - V_50 ;
if ( V_1 > V_49 - V_51 - V_2 )
V_21 = V_23 ;
else {
V_45 = F_1 ( V_1 ) ;
V_6 = NULL ;
F_28 (i, chunks) {
F_16 ( & V_36 -> V_38 ) ;
V_6 = F_36 ( & V_36 -> V_39 [ V_37 ] ,
struct V_4 , V_18 ) ;
if ( ! V_6 || ! F_17 ( V_6 ) ) {
F_20 ( & V_36 -> V_38 ) ;
continue;
}
F_37 ( & V_6 -> V_12 ) ;
F_38 ( & V_6 -> V_18 ) ;
F_20 ( & V_36 -> V_38 ) ;
V_5 = F_12 ( V_6 ) ;
if ( V_6 -> V_13 == 0 ) {
if ( V_6 -> V_14 != 0 &&
V_45 >= V_6 -> V_17 )
V_21 = V_52 ;
else
V_21 = V_53 ;
} else if ( V_6 -> V_15 == 0 )
V_21 = V_52 ;
else if ( V_6 -> V_14 == 0 )
V_21 = V_54 ;
else {
F_19 ( V_6 ) ;
F_16 ( & V_36 -> V_38 ) ;
if ( F_39 ( & V_6 -> V_12 ,
F_10 ) )
F_40 ( & V_36 -> V_40 ) ;
F_20 ( & V_36 -> V_38 ) ;
F_41 ( L_1 ) ;
F_42 ( 1 ) ;
continue;
}
goto V_55;
}
V_21 = V_53 ;
}
V_5 = F_43 ( V_33 ) ;
if ( ! V_5 )
return - V_56 ;
F_44 ( & V_36 -> V_40 ) ;
V_6 = F_2 ( V_5 ) ;
if ( V_21 == V_23 ) {
F_45 ( V_8 , & V_5 -> V_9 ) ;
F_16 ( & V_36 -> V_38 ) ;
goto V_57;
}
F_15 ( V_6 ) ;
V_55:
if ( V_21 == V_53 )
V_6 -> V_13 = V_45 ;
else if ( V_21 == V_52 )
V_6 -> V_15 = V_45 ;
else {
V_6 -> V_14 = V_45 ;
V_6 -> V_17 = V_6 -> V_13 + V_28 ;
}
F_16 ( & V_36 -> V_38 ) ;
if ( V_6 -> V_13 == 0 || V_6 -> V_15 == 0 ||
V_6 -> V_14 == 0 ) {
V_46 = F_24 ( V_6 ) ;
F_46 ( & V_6 -> V_18 , & V_36 -> V_39 [ V_46 ] ) ;
}
V_57:
if ( ! F_13 ( & V_5 -> V_7 ) )
F_14 ( & V_5 -> V_7 ) ;
F_46 ( & V_5 -> V_7 , & V_36 -> V_7 ) ;
* V_22 = F_21 ( V_6 , V_21 ) ;
F_20 ( & V_36 -> V_38 ) ;
if ( V_21 != V_23 )
F_19 ( V_6 ) ;
return 0 ;
}
static void F_47 ( struct V_32 * V_36 , unsigned long V_22 )
{
struct V_4 * V_6 ;
int V_46 ;
struct V_5 * V_5 ;
enum V_18 V_21 ;
V_6 = F_22 ( V_22 ) ;
V_5 = F_12 ( V_6 ) ;
if ( F_34 ( V_8 , & V_5 -> V_9 ) ) {
V_21 = V_23 ;
} else {
F_15 ( V_6 ) ;
V_21 = F_23 ( V_22 ) ;
switch ( V_21 ) {
case V_53 :
V_6 -> V_13 = 0 ;
break;
case V_54 :
V_6 -> V_14 = 0 ;
V_6 -> V_17 = 0 ;
break;
case V_52 :
V_6 -> V_15 = 0 ;
break;
default:
F_41 ( L_2 , V_58 , V_21 ) ;
F_42 ( 1 ) ;
F_19 ( V_6 ) ;
return;
}
}
if ( V_21 == V_23 ) {
F_16 ( & V_36 -> V_38 ) ;
F_14 ( & V_5 -> V_7 ) ;
F_20 ( & V_36 -> V_38 ) ;
F_8 ( V_5 ) ;
F_40 ( & V_36 -> V_40 ) ;
} else {
if ( V_6 -> V_13 != 0 || V_6 -> V_14 != 0 ||
V_6 -> V_15 != 0 ) {
F_33 ( V_6 ) ;
F_16 ( & V_36 -> V_38 ) ;
if ( ! F_13 ( & V_6 -> V_18 ) )
F_14 ( & V_6 -> V_18 ) ;
V_46 = F_24 ( V_6 ) ;
F_46 ( & V_6 -> V_18 , & V_36 -> V_39 [ V_46 ] ) ;
F_20 ( & V_36 -> V_38 ) ;
}
F_19 ( V_6 ) ;
F_16 ( & V_36 -> V_38 ) ;
if ( F_39 ( & V_6 -> V_12 , F_10 ) )
F_40 ( & V_36 -> V_40 ) ;
F_20 ( & V_36 -> V_38 ) ;
}
}
static int F_48 ( struct V_32 * V_36 , unsigned int V_59 )
{
int V_37 , V_60 = 0 , V_46 ;
struct V_4 * V_6 ;
struct V_5 * V_5 ;
unsigned long V_61 = 0 , V_62 = 0 , V_63 = 0 ;
F_16 ( & V_36 -> V_38 ) ;
if ( ! V_36 -> V_35 || ! V_36 -> V_35 -> V_64 || V_59 == 0 ) {
F_20 ( & V_36 -> V_38 ) ;
return - V_48 ;
}
for ( V_37 = 0 ; V_37 < V_59 ; V_37 ++ ) {
if ( F_13 ( & V_36 -> V_7 ) ) {
F_20 ( & V_36 -> V_38 ) ;
return - V_48 ;
}
V_5 = F_49 ( & V_36 -> V_7 , struct V_5 , V_7 ) ;
F_38 ( & V_5 -> V_7 ) ;
V_6 = F_3 ( V_5 ) ;
if ( ! F_34 ( V_8 , & V_5 -> V_9 ) ) {
if ( ! F_13 ( & V_6 -> V_18 ) )
F_38 ( & V_6 -> V_18 ) ;
F_37 ( & V_6 -> V_12 ) ;
F_20 ( & V_36 -> V_38 ) ;
F_15 ( V_6 ) ;
V_61 = 0 ;
V_63 = 0 ;
V_62 = 0 ;
if ( V_6 -> V_13 )
V_61 = F_21 ( V_6 , V_53 ) ;
if ( V_6 -> V_14 )
V_62 = F_21 ( V_6 , V_54 ) ;
if ( V_6 -> V_15 )
V_63 = F_21 ( V_6 , V_52 ) ;
F_19 ( V_6 ) ;
} else {
V_61 = F_21 ( V_6 , V_23 ) ;
V_63 = V_62 = 0 ;
F_20 ( & V_36 -> V_38 ) ;
}
if ( V_62 ) {
V_60 = V_36 -> V_35 -> V_64 ( V_36 , V_62 ) ;
if ( V_60 )
goto V_65;
}
if ( V_61 ) {
V_60 = V_36 -> V_35 -> V_64 ( V_36 , V_61 ) ;
if ( V_60 )
goto V_65;
}
if ( V_63 ) {
V_60 = V_36 -> V_35 -> V_64 ( V_36 , V_63 ) ;
if ( V_60 )
goto V_65;
}
V_65:
if ( F_34 ( V_8 , & V_5 -> V_9 ) ) {
if ( V_60 == 0 ) {
F_8 ( V_5 ) ;
return 0 ;
} else {
F_16 ( & V_36 -> V_38 ) ;
}
} else {
F_15 ( V_6 ) ;
if ( ( V_6 -> V_13 || V_6 -> V_15 ||
V_6 -> V_14 ) &&
! ( V_6 -> V_13 && V_6 -> V_15 &&
V_6 -> V_14 ) ) {
F_33 ( V_6 ) ;
F_16 ( & V_36 -> V_38 ) ;
V_46 = F_24 ( V_6 ) ;
F_46 ( & V_6 -> V_18 ,
& V_36 -> V_39 [ V_46 ] ) ;
F_20 ( & V_36 -> V_38 ) ;
}
F_19 ( V_6 ) ;
F_16 ( & V_36 -> V_38 ) ;
if ( F_39 ( & V_6 -> V_12 , F_10 ) ) {
F_20 ( & V_36 -> V_38 ) ;
F_40 ( & V_36 -> V_40 ) ;
return 0 ;
}
}
F_46 ( & V_5 -> V_7 , & V_36 -> V_7 ) ;
}
F_20 ( & V_36 -> V_38 ) ;
return - V_66 ;
}
static void * F_50 ( struct V_32 * V_36 , unsigned long V_22 )
{
struct V_4 * V_6 ;
struct V_5 * V_5 ;
void * V_67 ;
enum V_18 V_18 ;
V_6 = F_22 ( V_22 ) ;
V_67 = V_6 ;
V_5 = F_12 ( V_6 ) ;
if ( F_34 ( V_8 , & V_5 -> V_9 ) )
goto V_68;
F_15 ( V_6 ) ;
V_18 = F_23 ( V_22 ) ;
switch ( V_18 ) {
case V_53 :
V_67 += V_51 ;
break;
case V_54 :
V_67 += V_6 -> V_17 << V_3 ;
F_45 ( V_10 , & V_5 -> V_9 ) ;
break;
case V_52 :
V_67 += V_49 - ( V_6 -> V_15 << V_3 ) ;
break;
default:
F_41 ( L_3 , V_18 ) ;
F_42 ( 1 ) ;
V_67 = NULL ;
break;
}
F_19 ( V_6 ) ;
V_68:
return V_67 ;
}
static void F_51 ( struct V_32 * V_36 , unsigned long V_22 )
{
struct V_4 * V_6 ;
struct V_5 * V_5 ;
enum V_18 V_18 ;
V_6 = F_22 ( V_22 ) ;
V_5 = F_12 ( V_6 ) ;
if ( F_34 ( V_8 , & V_5 -> V_9 ) )
return;
F_15 ( V_6 ) ;
V_18 = F_23 ( V_22 ) ;
if ( V_18 == V_54 )
F_5 ( V_10 , & V_5 -> V_9 ) ;
F_19 ( V_6 ) ;
}
static T_3 F_52 ( struct V_32 * V_36 )
{
return F_53 ( & V_36 -> V_40 ) ;
}
static int F_54 ( struct V_32 * V_36 , unsigned long V_22 )
{
if ( V_36 -> V_69 && V_36 -> V_70 && V_36 -> V_70 -> V_64 )
return V_36 -> V_70 -> V_64 ( V_36 -> V_69 , V_22 ) ;
else
return - V_71 ;
}
static void * F_55 ( const char * V_72 , T_2 V_33 ,
const struct V_70 * V_70 ,
struct V_69 * V_69 )
{
struct V_32 * V_36 ;
V_36 = F_26 ( V_33 , V_70 ? & V_73 : NULL ) ;
if ( V_36 ) {
V_36 -> V_69 = V_69 ;
V_36 -> V_70 = V_70 ;
}
return V_36 ;
}
static void F_56 ( void * V_36 )
{
F_30 ( V_36 ) ;
}
static int F_57 ( void * V_36 , T_1 V_1 , T_2 V_33 ,
unsigned long * V_22 )
{
return F_35 ( V_36 , V_1 , V_33 , V_22 ) ;
}
static void F_58 ( void * V_36 , unsigned long V_22 )
{
F_47 ( V_36 , V_22 ) ;
}
static int F_59 ( void * V_36 , unsigned int V_74 ,
unsigned int * V_75 )
{
unsigned int V_76 = 0 ;
int V_60 = - V_48 ;
while ( V_76 < V_74 ) {
V_60 = F_48 ( V_36 , 8 ) ;
if ( V_60 < 0 )
break;
V_76 ++ ;
}
if ( V_75 )
* V_75 = V_76 ;
return V_60 ;
}
static void * F_60 ( void * V_36 , unsigned long V_22 ,
enum V_77 V_78 )
{
return F_50 ( V_36 , V_22 ) ;
}
static void F_61 ( void * V_36 , unsigned long V_22 )
{
F_51 ( V_36 , V_22 ) ;
}
static T_3 F_62 ( void * V_36 )
{
return F_52 ( V_36 ) * V_49 ;
}
static int T_4 F_63 ( void )
{
F_64 ( V_51 > V_49 ) ;
F_65 ( & V_79 ) ;
return 0 ;
}
static void T_5 F_66 ( void )
{
F_67 ( & V_79 ) ;
}
