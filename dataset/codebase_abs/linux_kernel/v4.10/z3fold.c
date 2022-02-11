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
F_5 ( V_11 , & V_5 -> V_9 ) ;
V_6 -> V_12 = 0 ;
V_6 -> V_13 = 0 ;
V_6 -> V_14 = 0 ;
V_6 -> V_15 = 0 ;
V_6 -> V_16 = 0 ;
F_4 ( & V_6 -> V_17 ) ;
return V_6 ;
}
static void F_6 ( struct V_4 * V_6 )
{
F_7 ( F_8 ( V_6 ) ) ;
}
static unsigned long F_9 ( struct V_4 * V_6 , enum V_17 V_18 )
{
unsigned long V_19 ;
V_19 = ( unsigned long ) V_6 ;
if ( V_18 != V_20 )
V_19 += ( V_18 + V_6 -> V_15 ) & V_21 ;
return V_19 ;
}
static struct V_4 * F_10 ( unsigned long V_19 )
{
return (struct V_4 * ) ( V_19 & V_22 ) ;
}
static enum V_17 F_11 ( unsigned long V_19 )
{
struct V_4 * V_6 = F_10 ( V_19 ) ;
return ( V_19 - V_6 -> V_15 ) & V_21 ;
}
static int F_12 ( struct V_4 * V_6 )
{
int V_23 ;
if ( V_6 -> V_13 != 0 ) {
int V_24 = V_6 -> V_12 ?
0 : V_6 -> V_16 - 1 ;
int V_25 = V_6 -> V_14 ?
0 : V_26 - V_6 -> V_16 - V_6 -> V_13 ;
V_23 = F_13 ( V_24 , V_25 ) ;
} else
V_23 = V_26 - V_6 -> V_12 - V_6 -> V_14 ;
return V_23 ;
}
static struct V_27 * F_14 ( T_2 V_28 ,
const struct V_29 * V_30 )
{
struct V_27 * V_31 ;
int V_32 ;
V_31 = F_15 ( sizeof( struct V_27 ) , V_28 ) ;
if ( ! V_31 )
return NULL ;
F_16 ( & V_31 -> V_33 ) ;
F_17 (i, 0 )
F_4 ( & V_31 -> V_34 [ V_32 ] ) ;
F_4 ( & V_31 -> V_35 ) ;
F_4 ( & V_31 -> V_7 ) ;
V_31 -> V_36 = 0 ;
V_31 -> V_30 = V_30 ;
return V_31 ;
}
static void F_18 ( struct V_27 * V_31 )
{
F_19 ( V_31 ) ;
}
static int F_20 ( struct V_4 * V_6 )
{
struct V_5 * V_5 = F_8 ( V_6 ) ;
void * V_37 = V_6 ;
if ( ! F_21 ( V_11 , & V_5 -> V_9 ) &&
V_6 -> V_13 != 0 &&
V_6 -> V_12 == 0 && V_6 -> V_14 == 0 ) {
memmove ( V_37 + V_38 ,
V_37 + ( V_6 -> V_16 << V_3 ) ,
V_6 -> V_13 << V_3 ) ;
V_6 -> V_12 = V_6 -> V_13 ;
V_6 -> V_13 = 0 ;
V_6 -> V_16 = 0 ;
V_6 -> V_15 ++ ;
return 1 ;
}
return 0 ;
}
static int F_22 ( struct V_27 * V_31 , T_1 V_1 , T_2 V_28 ,
unsigned long * V_19 )
{
int V_39 = 0 , V_32 , V_40 ;
struct V_4 * V_6 = NULL ;
enum V_17 V_18 ;
struct V_5 * V_5 ;
if ( ! V_1 || ( V_28 & V_41 ) )
return - V_42 ;
if ( V_1 > V_43 )
return - V_44 ;
if ( V_1 > V_43 - V_38 - V_2 )
V_18 = V_20 ;
else {
V_39 = F_1 ( V_1 ) ;
F_23 ( & V_31 -> V_33 ) ;
V_6 = NULL ;
F_17 (i, chunks) {
if ( ! F_24 ( & V_31 -> V_34 [ V_32 ] ) ) {
V_6 = F_25 ( & V_31 -> V_34 [ V_32 ] ,
struct V_4 , V_17 ) ;
V_5 = F_8 ( V_6 ) ;
if ( V_6 -> V_12 == 0 ) {
if ( V_6 -> V_13 != 0 &&
V_39 >= V_6 -> V_16 )
V_18 = V_45 ;
else
V_18 = V_46 ;
} else if ( V_6 -> V_14 == 0 )
V_18 = V_45 ;
else if ( V_6 -> V_13 == 0 )
V_18 = V_47 ;
else {
F_26 ( L_1 ) ;
F_27 ( 1 ) ;
continue;
}
F_28 ( & V_6 -> V_17 ) ;
goto V_48;
}
}
V_18 = V_46 ;
F_29 ( & V_31 -> V_33 ) ;
}
V_5 = F_30 ( V_28 ) ;
if ( ! V_5 )
return - V_49 ;
F_23 ( & V_31 -> V_33 ) ;
V_31 -> V_36 ++ ;
V_6 = F_2 ( V_5 ) ;
if ( V_18 == V_20 ) {
F_31 ( V_10 , & V_5 -> V_9 ) ;
goto V_50;
}
V_48:
if ( V_18 == V_46 )
V_6 -> V_12 = V_39 ;
else if ( V_18 == V_45 )
V_6 -> V_14 = V_39 ;
else {
V_6 -> V_13 = V_39 ;
V_6 -> V_16 = V_6 -> V_12 + 1 ;
}
if ( V_6 -> V_12 == 0 || V_6 -> V_14 == 0 ||
V_6 -> V_13 == 0 ) {
V_40 = F_12 ( V_6 ) ;
F_32 ( & V_6 -> V_17 , & V_31 -> V_34 [ V_40 ] ) ;
} else {
F_32 ( & V_6 -> V_17 , & V_31 -> V_35 ) ;
}
V_50:
if ( ! F_24 ( & V_5 -> V_7 ) )
F_28 ( & V_5 -> V_7 ) ;
F_32 ( & V_5 -> V_7 , & V_31 -> V_7 ) ;
* V_19 = F_9 ( V_6 , V_18 ) ;
F_29 ( & V_31 -> V_33 ) ;
return 0 ;
}
static void F_33 ( struct V_27 * V_31 , unsigned long V_19 )
{
struct V_4 * V_6 ;
int V_40 ;
struct V_5 * V_5 ;
enum V_17 V_18 ;
F_23 ( & V_31 -> V_33 ) ;
V_6 = F_10 ( V_19 ) ;
V_5 = F_8 ( V_6 ) ;
if ( F_21 ( V_10 , & V_5 -> V_9 ) ) {
V_18 = V_20 ;
} else {
V_18 = F_11 ( V_19 ) ;
switch ( V_18 ) {
case V_46 :
V_6 -> V_12 = 0 ;
break;
case V_47 :
V_6 -> V_13 = 0 ;
V_6 -> V_16 = 0 ;
break;
case V_45 :
V_6 -> V_14 = 0 ;
break;
default:
F_26 ( L_2 , V_51 , V_18 ) ;
F_27 ( 1 ) ;
F_29 ( & V_31 -> V_33 ) ;
return;
}
}
if ( F_21 ( V_8 , & V_5 -> V_9 ) ) {
F_29 ( & V_31 -> V_33 ) ;
return;
}
if ( V_18 != V_20 ) {
F_28 ( & V_6 -> V_17 ) ;
}
if ( V_18 == V_20 ||
( V_6 -> V_12 == 0 && V_6 -> V_13 == 0 &&
V_6 -> V_14 == 0 ) ) {
F_28 ( & V_5 -> V_7 ) ;
F_5 ( V_10 , & V_5 -> V_9 ) ;
F_6 ( V_6 ) ;
V_31 -> V_36 -- ;
} else {
F_20 ( V_6 ) ;
V_40 = F_12 ( V_6 ) ;
F_32 ( & V_6 -> V_17 , & V_31 -> V_34 [ V_40 ] ) ;
}
F_29 ( & V_31 -> V_33 ) ;
}
static int F_34 ( struct V_27 * V_31 , unsigned int V_52 )
{
int V_32 , V_53 = 0 , V_40 ;
struct V_4 * V_6 ;
struct V_5 * V_5 ;
unsigned long V_54 = 0 , V_55 = 0 , V_56 = 0 ;
F_23 ( & V_31 -> V_33 ) ;
if ( ! V_31 -> V_30 || ! V_31 -> V_30 -> V_57 || F_24 ( & V_31 -> V_7 ) ||
V_52 == 0 ) {
F_29 ( & V_31 -> V_33 ) ;
return - V_42 ;
}
for ( V_32 = 0 ; V_32 < V_52 ; V_32 ++ ) {
V_5 = F_35 ( & V_31 -> V_7 , struct V_5 , V_7 ) ;
F_28 ( & V_5 -> V_7 ) ;
F_31 ( V_8 , & V_5 -> V_9 ) ;
V_6 = F_3 ( V_5 ) ;
if ( ! F_21 ( V_10 , & V_5 -> V_9 ) ) {
F_28 ( & V_6 -> V_17 ) ;
V_54 = 0 ;
V_56 = 0 ;
V_55 = 0 ;
if ( V_6 -> V_12 )
V_54 = F_9 ( V_6 , V_46 ) ;
if ( V_6 -> V_13 )
V_55 = F_9 ( V_6 , V_47 ) ;
if ( V_6 -> V_14 )
V_56 = F_9 ( V_6 , V_45 ) ;
} else {
V_54 = F_9 ( V_6 , V_20 ) ;
V_56 = V_55 = 0 ;
}
F_29 ( & V_31 -> V_33 ) ;
if ( V_55 ) {
V_53 = V_31 -> V_30 -> V_57 ( V_31 , V_55 ) ;
if ( V_53 )
goto V_58;
}
if ( V_54 ) {
V_53 = V_31 -> V_30 -> V_57 ( V_31 , V_54 ) ;
if ( V_53 )
goto V_58;
}
if ( V_56 ) {
V_53 = V_31 -> V_30 -> V_57 ( V_31 , V_56 ) ;
if ( V_53 )
goto V_58;
}
V_58:
F_23 ( & V_31 -> V_33 ) ;
F_5 ( V_8 , & V_5 -> V_9 ) ;
if ( ( F_21 ( V_10 , & V_5 -> V_9 ) && V_53 == 0 ) ||
( V_6 -> V_12 == 0 && V_6 -> V_14 == 0 &&
V_6 -> V_13 == 0 ) ) {
F_5 ( V_10 , & V_5 -> V_9 ) ;
F_6 ( V_6 ) ;
V_31 -> V_36 -- ;
F_29 ( & V_31 -> V_33 ) ;
return 0 ;
} else if ( ! F_21 ( V_10 , & V_5 -> V_9 ) ) {
if ( V_6 -> V_12 != 0 &&
V_6 -> V_14 != 0 &&
V_6 -> V_13 != 0 ) {
F_32 ( & V_6 -> V_17 , & V_31 -> V_35 ) ;
} else {
F_20 ( V_6 ) ;
V_40 = F_12 ( V_6 ) ;
F_32 ( & V_6 -> V_17 ,
& V_31 -> V_34 [ V_40 ] ) ;
}
}
F_32 ( & V_5 -> V_7 , & V_31 -> V_7 ) ;
}
F_29 ( & V_31 -> V_33 ) ;
return - V_59 ;
}
static void * F_36 ( struct V_27 * V_31 , unsigned long V_19 )
{
struct V_4 * V_6 ;
struct V_5 * V_5 ;
void * V_60 ;
enum V_17 V_17 ;
F_23 ( & V_31 -> V_33 ) ;
V_6 = F_10 ( V_19 ) ;
V_60 = V_6 ;
V_5 = F_8 ( V_6 ) ;
if ( F_21 ( V_10 , & V_5 -> V_9 ) )
goto V_61;
V_17 = F_11 ( V_19 ) ;
switch ( V_17 ) {
case V_46 :
V_60 += V_38 ;
break;
case V_47 :
V_60 += V_6 -> V_16 << V_3 ;
F_31 ( V_11 , & V_5 -> V_9 ) ;
break;
case V_45 :
V_60 += V_43 - ( V_6 -> V_14 << V_3 ) ;
break;
default:
F_26 ( L_3 , V_17 ) ;
F_27 ( 1 ) ;
V_60 = NULL ;
break;
}
V_61:
F_29 ( & V_31 -> V_33 ) ;
return V_60 ;
}
static void F_37 ( struct V_27 * V_31 , unsigned long V_19 )
{
struct V_4 * V_6 ;
struct V_5 * V_5 ;
enum V_17 V_17 ;
F_23 ( & V_31 -> V_33 ) ;
V_6 = F_10 ( V_19 ) ;
V_5 = F_8 ( V_6 ) ;
if ( F_21 ( V_10 , & V_5 -> V_9 ) ) {
F_29 ( & V_31 -> V_33 ) ;
return;
}
V_17 = F_11 ( V_19 ) ;
if ( V_17 == V_47 )
F_5 ( V_11 , & V_5 -> V_9 ) ;
F_29 ( & V_31 -> V_33 ) ;
}
static T_3 F_38 ( struct V_27 * V_31 )
{
return V_31 -> V_36 ;
}
static int F_39 ( struct V_27 * V_31 , unsigned long V_19 )
{
if ( V_31 -> V_62 && V_31 -> V_63 && V_31 -> V_63 -> V_57 )
return V_31 -> V_63 -> V_57 ( V_31 -> V_62 , V_19 ) ;
else
return - V_64 ;
}
static void * F_40 ( const char * V_65 , T_2 V_28 ,
const struct V_63 * V_63 ,
struct V_62 * V_62 )
{
struct V_27 * V_31 ;
V_31 = F_14 ( V_28 , V_63 ? & V_66 : NULL ) ;
if ( V_31 ) {
V_31 -> V_62 = V_62 ;
V_31 -> V_63 = V_63 ;
}
return V_31 ;
}
static void F_41 ( void * V_31 )
{
F_18 ( V_31 ) ;
}
static int F_42 ( void * V_31 , T_1 V_1 , T_2 V_28 ,
unsigned long * V_19 )
{
return F_22 ( V_31 , V_1 , V_28 , V_19 ) ;
}
static void F_43 ( void * V_31 , unsigned long V_19 )
{
F_33 ( V_31 , V_19 ) ;
}
static int F_44 ( void * V_31 , unsigned int V_67 ,
unsigned int * V_68 )
{
unsigned int V_69 = 0 ;
int V_53 = - V_42 ;
while ( V_69 < V_67 ) {
V_53 = F_34 ( V_31 , 8 ) ;
if ( V_53 < 0 )
break;
V_69 ++ ;
}
if ( V_68 )
* V_68 = V_69 ;
return V_53 ;
}
static void * F_45 ( void * V_31 , unsigned long V_19 ,
enum V_70 V_71 )
{
return F_36 ( V_31 , V_19 ) ;
}
static void F_46 ( void * V_31 , unsigned long V_19 )
{
F_37 ( V_31 , V_19 ) ;
}
static T_3 F_47 ( void * V_31 )
{
return F_38 ( V_31 ) * V_43 ;
}
static int T_4 F_48 ( void )
{
F_49 ( sizeof( struct V_4 ) > V_38 ) ;
F_50 ( & V_72 ) ;
return 0 ;
}
static void T_5 F_51 ( void )
{
F_52 ( & V_72 ) ;
}
