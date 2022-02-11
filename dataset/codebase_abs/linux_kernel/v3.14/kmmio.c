static struct V_1 * F_1 ( unsigned long V_2 )
{
return & V_3 [ F_2 ( V_2 , V_4 ) ] ;
}
static struct V_5 * F_3 ( unsigned long V_6 )
{
struct V_5 * V_7 ;
F_4 (p, &kmmio_probes, list) {
if ( V_6 >= V_7 -> V_6 && V_6 < ( V_7 -> V_6 + V_7 -> V_8 ) )
return V_7 ;
}
return NULL ;
}
static struct V_9 * F_5 ( unsigned long V_2 )
{
struct V_1 * V_10 ;
struct V_9 * V_11 ;
V_2 &= V_12 ;
V_10 = F_1 ( V_2 ) ;
F_4 (f, head, list) {
if ( V_11 -> V_2 == V_2 )
return V_11 ;
}
return NULL ;
}
static void F_6 ( T_1 * V_13 , bool V_14 , T_2 * V_15 )
{
T_2 V_16 = F_7 ( * V_13 ) ;
if ( V_14 ) {
* V_15 = V_16 & V_17 ;
V_16 &= ~ V_17 ;
} else
V_16 |= * V_15 ;
F_8 ( V_13 , F_9 ( V_16 ) ) ;
}
static void F_10 ( T_3 * V_18 , bool V_14 , T_4 * V_15 )
{
T_4 V_16 = F_11 ( * V_18 ) ;
if ( V_14 ) {
* V_15 = V_16 & V_17 ;
V_16 &= ~ V_17 ;
} else
V_16 |= * V_15 ;
F_12 ( V_18 , F_13 ( V_16 ) ) ;
}
static int F_14 ( struct V_9 * V_11 , bool V_14 )
{
unsigned int V_19 ;
T_3 * V_18 = F_15 ( V_11 -> V_2 , & V_19 ) ;
if ( ! V_18 ) {
F_16 ( L_1 , V_11 -> V_2 ) ;
return - 1 ;
}
switch ( V_19 ) {
case V_20 :
F_6 ( ( T_1 * ) V_18 , V_14 , & V_11 -> V_21 ) ;
break;
case V_22 :
F_10 ( V_18 , V_14 , & V_11 -> V_21 ) ;
break;
default:
F_16 ( L_2 , V_19 ) ;
return - 1 ;
}
F_17 ( V_11 -> V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_9 * V_11 )
{
int V_23 ;
F_19 (f->armed, KERN_ERR pr_fmt(L_3)) ;
if ( V_11 -> V_24 ) {
F_20 ( L_4 ,
V_11 -> V_2 , V_11 -> V_25 , ! ! V_11 -> V_21 ) ;
}
V_23 = F_14 ( V_11 , true ) ;
F_19 (ret < 0 , KERN_ERR pr_fmt(L_5),
f->page) ;
V_11 -> V_24 = true ;
return V_23 ;
}
static void F_21 ( struct V_9 * V_11 )
{
int V_23 = F_14 ( V_11 , false ) ;
F_19 ( V_23 < 0 ,
V_26 L_6 , V_11 -> V_2 ) ;
V_11 -> V_24 = false ;
}
int F_22 ( struct V_27 * V_28 , unsigned long V_6 )
{
struct V_29 * V_30 ;
struct V_9 * V_31 ;
int V_23 = 0 ;
F_23 () ;
F_24 () ;
V_31 = F_5 ( V_6 ) ;
if ( ! V_31 ) {
goto V_32;
}
V_30 = & F_25 ( V_33 ) ;
if ( V_30 -> V_34 ) {
if ( V_6 == V_30 -> V_6 ) {
F_26 ( L_7 ,
V_6 , F_27 () ) ;
if ( ! V_31 -> V_21 )
F_28 ( L_8 ,
V_6 , F_27 () ) ;
} else {
F_29 ( L_9 ,
F_27 () , V_6 ) ;
F_29 ( L_10 , V_30 -> V_6 ) ;
F_21 ( V_31 ) ;
}
goto V_35;
}
V_30 -> V_34 ++ ;
V_30 -> V_36 = V_31 ;
V_30 -> V_37 = F_3 ( V_6 ) ;
V_30 -> V_38 = ( V_28 -> V_39 & ( V_40 | V_41 ) ) ;
V_30 -> V_6 = V_6 ;
if ( V_30 -> V_37 && V_30 -> V_37 -> V_42 )
V_30 -> V_37 -> V_42 ( V_30 -> V_37 , V_28 , V_6 ) ;
V_28 -> V_39 |= V_40 ;
V_28 -> V_39 &= ~ V_41 ;
F_21 ( V_30 -> V_36 ) ;
F_30 ( V_33 ) ;
return 1 ;
V_35:
F_30 ( V_33 ) ;
V_32:
F_31 () ;
F_32 () ;
return V_23 ;
}
static int F_33 ( unsigned long V_43 , struct V_27 * V_28 )
{
int V_23 = 0 ;
struct V_29 * V_30 = & F_25 ( V_33 ) ;
if ( ! V_30 -> V_34 ) {
F_20 ( L_11 ,
F_27 () ) ;
goto V_44;
}
if ( V_30 -> V_37 && V_30 -> V_37 -> V_45 )
V_30 -> V_37 -> V_45 ( V_30 -> V_37 , V_43 , V_28 ) ;
F_34 ( & V_46 ) ;
if ( V_30 -> V_36 -> V_25 )
F_18 ( V_30 -> V_36 ) ;
F_35 ( & V_46 ) ;
V_28 -> V_39 &= ~ V_40 ;
V_28 -> V_39 |= V_30 -> V_38 ;
V_30 -> V_34 -- ;
F_36 ( V_30 -> V_34 ) ;
F_31 () ;
F_32 () ;
if ( ! ( V_28 -> V_39 & V_40 ) )
V_23 = 1 ;
V_44:
F_30 ( V_33 ) ;
return V_23 ;
}
static int F_37 ( unsigned long V_2 )
{
struct V_9 * V_11 ;
V_2 &= V_12 ;
V_11 = F_5 ( V_2 ) ;
if ( V_11 ) {
if ( ! V_11 -> V_25 )
F_18 ( V_11 ) ;
V_11 -> V_25 ++ ;
return 0 ;
}
V_11 = F_38 ( sizeof( * V_11 ) , V_47 ) ;
if ( ! V_11 )
return - 1 ;
V_11 -> V_25 = 1 ;
V_11 -> V_2 = V_2 ;
if ( F_18 ( V_11 ) ) {
F_39 ( V_11 ) ;
return - 1 ;
}
F_40 ( & V_11 -> V_48 , F_1 ( V_11 -> V_2 ) ) ;
return 0 ;
}
static void F_41 ( unsigned long V_2 ,
struct V_9 * * V_49 )
{
struct V_9 * V_11 ;
V_2 &= V_12 ;
V_11 = F_5 ( V_2 ) ;
if ( ! V_11 )
return;
V_11 -> V_25 -- ;
F_36 ( V_11 -> V_25 < 0 ) ;
if ( ! V_11 -> V_25 ) {
F_21 ( V_11 ) ;
if ( ! V_11 -> V_50 ) {
V_11 -> V_51 = * V_49 ;
* V_49 = V_11 ;
V_11 -> V_50 = true ;
}
}
}
int F_42 ( struct V_5 * V_7 )
{
unsigned long V_39 ;
int V_23 = 0 ;
unsigned long V_52 = 0 ;
const unsigned long V_53 = V_7 -> V_8 + ( V_7 -> V_6 & ~ V_12 ) ;
F_43 ( & V_46 , V_39 ) ;
if ( F_3 ( V_7 -> V_6 ) ) {
V_23 = - V_54 ;
goto V_44;
}
V_55 ++ ;
F_40 ( & V_7 -> V_48 , & V_56 ) ;
while ( V_52 < V_53 ) {
if ( F_37 ( V_7 -> V_6 + V_52 ) )
F_16 ( L_12 ) ;
V_52 += V_57 ;
}
V_44:
F_44 ( & V_46 , V_39 ) ;
return V_23 ;
}
static void F_45 ( struct V_58 * V_10 )
{
struct V_59 * V_60 = F_46 (
V_10 ,
struct V_59 ,
V_61 ) ;
struct V_9 * V_11 = V_60 -> V_49 ;
while ( V_11 ) {
struct V_9 * V_62 = V_11 -> V_51 ;
F_36 ( V_11 -> V_25 ) ;
F_39 ( V_11 ) ;
V_11 = V_62 ;
}
F_39 ( V_60 ) ;
}
static void F_47 ( struct V_58 * V_10 )
{
struct V_59 * V_60 =
F_46 ( V_10 , struct V_59 , V_61 ) ;
struct V_9 * V_11 = V_60 -> V_49 ;
struct V_9 * * V_63 = & V_60 -> V_49 ;
unsigned long V_39 ;
F_43 ( & V_46 , V_39 ) ;
while ( V_11 ) {
if ( ! V_11 -> V_25 ) {
F_48 ( & V_11 -> V_48 ) ;
V_63 = & V_11 -> V_51 ;
} else {
* V_63 = V_11 -> V_51 ;
V_11 -> V_51 = NULL ;
V_11 -> V_50 = false ;
}
V_11 = * V_63 ;
}
F_44 ( & V_46 , V_39 ) ;
F_49 ( & V_60 -> V_61 , F_45 ) ;
}
void F_50 ( struct V_5 * V_7 )
{
unsigned long V_39 ;
unsigned long V_52 = 0 ;
const unsigned long V_53 = V_7 -> V_8 + ( V_7 -> V_6 & ~ V_12 ) ;
struct V_9 * V_49 = NULL ;
struct V_59 * V_64 ;
F_43 ( & V_46 , V_39 ) ;
while ( V_52 < V_53 ) {
F_41 ( V_7 -> V_6 + V_52 , & V_49 ) ;
V_52 += V_57 ;
}
F_48 ( & V_7 -> V_48 ) ;
V_55 -- ;
F_44 ( & V_46 , V_39 ) ;
if ( ! V_49 )
return;
V_64 = F_51 ( sizeof( * V_64 ) , V_47 ) ;
if ( ! V_64 ) {
F_52 ( L_13 ) ;
return;
}
V_64 -> V_49 = V_49 ;
F_49 ( & V_64 -> V_61 , F_47 ) ;
}
static int
F_53 ( struct V_65 * V_66 , unsigned long V_67 , void * args )
{
struct V_68 * V_69 = args ;
unsigned long * V_70 = ( unsigned long * ) F_54 ( V_69 -> V_71 ) ;
if ( V_67 == V_72 && ( * V_70 & V_73 ) )
if ( F_33 ( * V_70 , V_69 -> V_28 ) == 1 ) {
* V_70 &= ~ V_73 ;
return V_74 ;
}
return V_75 ;
}
int F_55 ( void )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ )
F_56 ( & V_3 [ V_76 ] ) ;
return F_57 ( & V_78 ) ;
}
void F_58 ( void )
{
int V_76 ;
F_59 ( & V_78 ) ;
for ( V_76 = 0 ; V_76 < V_77 ; V_76 ++ ) {
F_19 ( ! F_60 ( & V_3 [ V_76 ] ) ,
V_26 L_14 ) ;
}
}
