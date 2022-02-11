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
static T_5 F_9 ( struct V_27 * V_28 ,
struct V_29 * V_15 , int V_30 )
{
struct V_12 * V_13 = F_10 ( V_28 ) ;
return V_13 -> V_31 ? V_15 -> V_32 : 0 ;
}
static bool F_11 ( T_1 V_19 )
{
return ! ! ( V_19 & V_20 ) ;
}
static void F_12 ( struct V_33 * V_34 ,
struct V_17 * V_17 )
{
if ( F_11 ( V_34 -> V_19 ) &&
! F_11 ( V_17 -> V_19 ) ) {
V_17 -> V_19 |= V_20 ;
F_13 ( & V_17 -> V_13 . V_28 , V_35 ) ;
} else if ( ! F_11 ( V_34 -> V_19 ) &&
F_11 ( V_17 -> V_19 ) ) {
V_17 -> V_19 &= ~ V_20 ;
F_13 ( & V_17 -> V_13 . V_28 , V_36 ) ;
}
}
static struct V_17 * F_14 ( T_1 V_1 )
{
struct V_17 * V_17 ;
F_15 (pcpu, &xen_pcpus, list) {
if ( V_17 -> V_1 == V_1 )
return V_17 ;
}
return NULL ;
}
static void F_16 ( struct V_12 * V_13 )
{
struct V_17 * V_17 = F_5 ( V_13 , struct V_17 , V_13 ) ;
F_17 ( & V_17 -> V_37 ) ;
F_18 ( V_17 ) ;
}
static void F_19 ( struct V_17 * V_17 )
{
struct V_12 * V_13 ;
if ( ! V_17 )
return;
V_13 = & V_17 -> V_13 ;
F_20 ( V_13 ) ;
}
static int F_21 ( struct V_17 * V_17 )
{
struct V_12 * V_13 ;
int V_38 = - V_26 ;
if ( ! V_17 )
return V_38 ;
V_13 = & V_17 -> V_13 ;
V_13 -> V_39 = & V_40 ;
V_13 -> V_31 = V_17 -> V_1 ;
V_13 -> V_41 = F_16 ;
V_13 -> V_42 = V_43 ;
V_38 = F_22 ( V_13 ) ;
if ( V_38 ) {
F_16 ( V_13 ) ;
return V_38 ;
}
return 0 ;
}
static struct V_17 * F_23 ( struct V_33 * V_34 )
{
struct V_17 * V_17 ;
int V_38 ;
if ( V_34 -> V_19 & V_44 )
return F_24 ( - V_45 ) ;
V_17 = F_25 ( sizeof( struct V_17 ) , V_46 ) ;
if ( ! V_17 )
return F_24 ( - V_47 ) ;
F_26 ( & V_17 -> V_37 ) ;
V_17 -> V_1 = V_34 -> V_48 ;
V_17 -> V_19 = V_34 -> V_19 ;
F_27 ( & V_17 -> V_37 , & V_49 ) ;
V_38 = F_21 ( V_17 ) ;
if ( V_38 ) {
F_28 ( L_2 , V_34 -> V_48 ) ;
return F_24 ( - V_50 ) ;
}
return V_17 ;
}
static int F_29 ( T_1 V_18 , T_1 * V_51 )
{
int V_23 ;
struct V_17 * V_17 = NULL ;
struct V_33 * V_34 ;
struct V_2 V_3 = {
. V_4 = V_52 ,
. V_6 = V_7 ,
. V_8 . V_53 . V_48 = V_18 ,
} ;
V_23 = F_2 ( & V_3 ) ;
if ( V_23 )
return V_23 ;
V_34 = & V_3 . V_8 . V_53 ;
if ( V_51 )
* V_51 = V_34 -> V_54 ;
V_17 = F_14 ( V_18 ) ;
if ( V_34 -> V_19 & V_44 ) {
F_19 ( V_17 ) ;
return 0 ;
}
if ( ! V_17 ) {
V_17 = F_23 ( V_34 ) ;
if ( F_30 ( V_17 ) )
return - V_45 ;
} else
F_12 ( V_34 , V_17 ) ;
return 0 ;
}
static int F_31 ( void )
{
T_1 V_18 = 0 , V_51 = 0 ;
int V_38 = 0 ;
struct V_17 * V_17 , * V_55 ;
F_32 ( & V_56 ) ;
while ( ! V_38 && ( V_18 <= V_51 ) ) {
V_38 = F_29 ( V_18 , & V_51 ) ;
V_18 ++ ;
}
if ( V_38 )
F_33 (pcpu, tmp, &xen_pcpus, list)
F_19 ( V_17 ) ;
F_34 ( & V_56 ) ;
return V_38 ;
}
static void F_35 ( struct V_57 * V_58 )
{
F_31 () ;
}
static T_6 F_36 ( int V_59 , void * V_60 )
{
F_37 ( & V_61 ) ;
return V_62 ;
}
void F_38 ( void )
{
F_37 ( & V_61 ) ;
}
int F_39 ( T_1 V_63 )
{
int V_1 = 0 , V_64 = 0 ;
struct V_2 V_3 ;
V_3 . V_4 = V_52 ;
while ( V_1 <= V_64 ) {
V_3 . V_8 . V_53 . V_48 = V_1 ;
if ( F_2 ( & V_3 ) ) {
V_1 ++ ;
continue;
}
if ( V_63 == V_3 . V_8 . V_53 . V_63 )
return V_1 ;
if ( V_3 . V_8 . V_53 . V_54 > V_64 )
V_64 = V_3 . V_8 . V_53 . V_54 ;
V_1 ++ ;
}
return - V_45 ;
}
static int T_7 F_40 ( void )
{
int V_59 , V_23 ;
if ( ! F_41 () )
return - V_45 ;
V_59 = F_42 ( V_65 , 0 ,
F_36 , 0 ,
L_3 , NULL ) ;
if ( V_59 < 0 ) {
F_28 ( L_4 ) ;
return V_59 ;
}
V_23 = F_43 ( & V_40 , NULL ) ;
if ( V_23 ) {
F_28 ( L_5 ) ;
goto V_66;
}
V_23 = F_31 () ;
if ( V_23 ) {
F_28 ( L_6 ) ;
goto V_67;
}
return 0 ;
V_67:
F_44 ( & V_40 ) ;
V_66:
F_45 ( V_59 , NULL ) ;
return V_23 ;
}
