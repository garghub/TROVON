static int F_1 ( T_1 V_1 )
{
struct V_2 V_3 = {
. V_4 = V_5 ,
. V_6 = V_7 ,
. V_8 . V_9 . V_10 = V_1 ,
} ;
return F_2 ( & V_3 ) ;
}
static int F_3 ( T_1 V_1 )
{
struct V_2 V_3 = {
. V_4 = V_11 ,
. V_6 = V_7 ,
. V_8 . V_9 . V_10 = V_1 ,
} ;
return F_2 ( & V_3 ) ;
}
static T_2 F_4 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
char * V_16 )
{
struct V_17 * V_18 = F_5 ( V_13 , struct V_17 , V_13 ) ;
return sprintf ( V_16 , L_1 , ! ! ( V_18 -> V_19 & V_20 ) ) ;
}
static T_2 T_3 F_6 ( struct V_12 * V_13 ,
struct V_14 * V_15 ,
const char * V_16 , T_4 V_21 )
{
struct V_17 * V_17 = F_5 ( V_13 , struct V_17 , V_13 ) ;
unsigned long long V_22 ;
T_2 V_23 ;
if ( ! F_7 ( V_24 ) )
return - V_25 ;
if ( F_8 ( V_16 , 0 , & V_22 ) < 0 )
return - V_26 ;
switch ( V_22 ) {
case 0 :
V_23 = F_1 ( V_17 -> V_1 ) ;
break;
case 1 :
V_23 = F_3 ( V_17 -> V_1 ) ;
break;
default:
V_23 = - V_26 ;
}
if ( V_23 >= 0 )
V_23 = V_21 ;
return V_23 ;
}
static bool F_9 ( T_1 V_19 )
{
return ! ! ( V_19 & V_20 ) ;
}
static void F_10 ( struct V_27 * V_28 ,
struct V_17 * V_17 )
{
if ( F_9 ( V_28 -> V_19 ) &&
! F_9 ( V_17 -> V_19 ) ) {
V_17 -> V_19 |= V_20 ;
F_11 ( & V_17 -> V_13 . V_29 , V_30 ) ;
} else if ( ! F_9 ( V_28 -> V_19 ) &&
F_9 ( V_17 -> V_19 ) ) {
V_17 -> V_19 &= ~ V_20 ;
F_11 ( & V_17 -> V_13 . V_29 , V_31 ) ;
}
}
static struct V_17 * F_12 ( T_1 V_1 )
{
struct V_17 * V_17 ;
F_13 (pcpu, &xen_pcpus, list) {
if ( V_17 -> V_1 == V_1 )
return V_17 ;
}
return NULL ;
}
static void F_14 ( struct V_12 * V_13 )
{
struct V_17 * V_17 = F_5 ( V_13 , struct V_17 , V_13 ) ;
F_15 ( & V_17 -> V_32 ) ;
F_16 ( V_17 ) ;
}
static void F_17 ( struct V_17 * V_17 )
{
struct V_12 * V_13 ;
if ( ! V_17 )
return;
V_13 = & V_17 -> V_13 ;
if ( V_13 -> V_33 )
F_18 ( V_13 , & V_34 ) ;
F_19 ( V_13 ) ;
}
static int F_20 ( struct V_17 * V_17 )
{
struct V_12 * V_13 ;
int V_35 = - V_26 ;
if ( ! V_17 )
return V_35 ;
V_13 = & V_17 -> V_13 ;
V_13 -> V_36 = & V_37 ;
V_13 -> V_33 = V_17 -> V_1 ;
V_13 -> V_38 = F_14 ;
V_35 = F_21 ( V_13 ) ;
if ( V_35 ) {
F_14 ( V_13 ) ;
return V_35 ;
}
if ( V_13 -> V_33 ) {
V_35 = F_22 ( V_13 , & V_34 ) ;
if ( V_35 ) {
F_19 ( V_13 ) ;
return V_35 ;
}
}
return 0 ;
}
static struct V_17 * F_23 ( struct V_27 * V_28 )
{
struct V_17 * V_17 ;
int V_35 ;
if ( V_28 -> V_19 & V_39 )
return F_24 ( - V_40 ) ;
V_17 = F_25 ( sizeof( struct V_17 ) , V_41 ) ;
if ( ! V_17 )
return F_24 ( - V_42 ) ;
F_26 ( & V_17 -> V_32 ) ;
V_17 -> V_1 = V_28 -> V_43 ;
V_17 -> V_19 = V_28 -> V_19 ;
F_27 ( & V_17 -> V_32 , & V_44 ) ;
V_35 = F_20 ( V_17 ) ;
if ( V_35 ) {
F_28 ( L_2 , V_28 -> V_43 ) ;
return F_24 ( - V_45 ) ;
}
return V_17 ;
}
static int F_29 ( T_1 V_18 , T_1 * V_46 )
{
int V_23 ;
struct V_17 * V_17 = NULL ;
struct V_27 * V_28 ;
struct V_2 V_3 = {
. V_4 = V_47 ,
. V_6 = V_7 ,
. V_8 . V_48 . V_43 = V_18 ,
} ;
V_23 = F_2 ( & V_3 ) ;
if ( V_23 )
return V_23 ;
V_28 = & V_3 . V_8 . V_48 ;
if ( V_46 )
* V_46 = V_28 -> V_49 ;
V_17 = F_12 ( V_18 ) ;
if ( V_28 -> V_19 & V_39 ) {
F_17 ( V_17 ) ;
return 0 ;
}
if ( ! V_17 ) {
V_17 = F_23 ( V_28 ) ;
if ( F_30 ( V_17 ) )
return - V_40 ;
} else
F_10 ( V_28 , V_17 ) ;
return 0 ;
}
static int F_31 ( void )
{
T_1 V_18 = 0 , V_46 = 0 ;
int V_35 = 0 ;
struct V_17 * V_17 , * V_50 ;
F_32 ( & V_51 ) ;
while ( ! V_35 && ( V_18 <= V_46 ) ) {
V_35 = F_29 ( V_18 , & V_46 ) ;
V_18 ++ ;
}
if ( V_35 )
F_33 (pcpu, tmp, &xen_pcpus, list)
F_17 ( V_17 ) ;
F_34 ( & V_51 ) ;
return V_35 ;
}
static void F_35 ( struct V_52 * V_53 )
{
F_31 () ;
}
static T_5 F_36 ( int V_54 , void * V_55 )
{
F_37 ( & V_56 ) ;
return V_57 ;
}
void F_38 ( void )
{
F_37 ( & V_56 ) ;
}
int F_39 ( T_1 V_58 )
{
int V_1 = 0 , V_59 = 0 ;
struct V_2 V_3 ;
V_3 . V_4 = V_47 ;
while ( V_1 <= V_59 ) {
V_3 . V_8 . V_48 . V_43 = V_1 ;
if ( F_2 ( & V_3 ) ) {
V_1 ++ ;
continue;
}
if ( V_58 == V_3 . V_8 . V_48 . V_58 )
return V_1 ;
if ( V_3 . V_8 . V_48 . V_49 > V_59 )
V_59 = V_3 . V_8 . V_48 . V_49 ;
V_1 ++ ;
}
return - V_40 ;
}
static int T_6 F_40 ( void )
{
int V_54 , V_23 ;
if ( ! F_41 () )
return - V_40 ;
V_54 = F_42 ( V_60 , 0 ,
F_36 , 0 ,
L_3 , NULL ) ;
if ( V_54 < 0 ) {
F_28 ( L_4 ) ;
return V_54 ;
}
V_23 = F_43 ( & V_37 , NULL ) ;
if ( V_23 ) {
F_28 ( L_5 ) ;
goto V_61;
}
V_23 = F_31 () ;
if ( V_23 ) {
F_28 ( L_6 ) ;
goto V_62;
}
return 0 ;
V_62:
F_44 ( & V_37 ) ;
V_61:
F_45 ( V_54 , NULL ) ;
return V_23 ;
}
