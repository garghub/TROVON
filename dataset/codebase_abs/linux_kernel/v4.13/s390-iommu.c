static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static bool F_3 ( enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
return true ;
case V_8 :
return true ;
default:
return false ;
}
}
static struct V_2 * F_4 ( unsigned V_9 )
{
struct V_1 * V_1 ;
if ( V_9 != V_10 )
return NULL ;
V_1 = F_5 ( sizeof( * V_1 ) , V_11 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_12 = F_6 () ;
if ( ! V_1 -> V_12 ) {
F_7 ( V_1 ) ;
return NULL ;
}
F_8 ( & V_1 -> V_13 ) ;
F_8 ( & V_1 -> V_14 ) ;
F_9 ( & V_1 -> V_15 ) ;
return & V_1 -> V_4 ;
}
static void F_10 ( struct V_2 * V_4 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
F_11 ( V_1 -> V_12 ) ;
F_7 ( V_1 ) ;
}
static int F_12 ( struct V_2 * V_4 ,
struct V_16 * V_17 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_18 * V_19 = F_13 ( V_17 ) -> V_20 ;
struct V_21 * V_22 ;
unsigned long V_23 ;
int V_24 ;
if ( ! V_19 )
return - V_25 ;
V_22 = F_5 ( sizeof( * V_22 ) , V_11 ) ;
if ( ! V_22 )
return - V_26 ;
if ( V_19 -> V_12 )
F_14 ( V_19 ) ;
V_19 -> V_12 = V_1 -> V_12 ;
V_24 = F_15 ( V_19 , 0 , V_19 -> V_27 , V_19 -> V_28 ,
( V_29 ) V_19 -> V_12 ) ;
if ( V_24 )
goto V_30;
F_16 ( & V_1 -> V_14 , V_23 ) ;
if ( F_17 ( & V_1 -> V_15 ) ) {
V_4 -> V_31 . V_32 = V_19 -> V_27 ;
V_4 -> V_31 . V_33 = V_19 -> V_28 ;
V_4 -> V_31 . V_34 = true ;
} else if ( V_4 -> V_31 . V_32 != V_19 -> V_27 ||
V_4 -> V_31 . V_33 != V_19 -> V_28 ) {
V_24 = - V_35 ;
F_18 ( & V_1 -> V_14 , V_23 ) ;
goto V_30;
}
V_22 -> V_19 = V_19 ;
V_19 -> V_1 = V_1 ;
F_19 ( & V_22 -> V_36 , & V_1 -> V_15 ) ;
F_18 ( & V_1 -> V_14 , V_23 ) ;
return 0 ;
V_30:
F_20 ( V_19 ) ;
F_7 ( V_22 ) ;
return V_24 ;
}
static void F_21 ( struct V_2 * V_4 ,
struct V_16 * V_17 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_18 * V_19 = F_13 ( V_17 ) -> V_20 ;
struct V_21 * V_22 , * V_37 ;
unsigned long V_23 ;
int V_38 = 0 ;
if ( ! V_19 )
return;
F_16 ( & V_1 -> V_14 , V_23 ) ;
F_22 (domain_device, tmp, &s390_domain->devices,
list) {
if ( V_22 -> V_19 == V_19 ) {
F_23 ( & V_22 -> V_36 ) ;
F_7 ( V_22 ) ;
V_38 = 1 ;
break;
}
}
F_18 ( & V_1 -> V_14 , V_23 ) ;
if ( V_38 ) {
V_19 -> V_1 = NULL ;
F_24 ( V_19 , 0 ) ;
F_20 ( V_19 ) ;
}
}
static int F_25 ( struct V_16 * V_17 )
{
struct V_39 * V_40 = F_26 ( V_17 ) ;
if ( F_27 ( V_40 ) )
return F_28 ( V_40 ) ;
F_29 ( V_40 ) ;
return 0 ;
}
static void F_30 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_13 ( V_17 ) -> V_20 ;
struct V_2 * V_4 ;
if ( V_19 && V_19 -> V_1 ) {
V_4 = F_31 ( V_17 ) ;
if ( V_4 )
F_21 ( V_4 , V_17 ) ;
}
F_32 ( V_17 ) ;
}
static int F_33 ( struct V_1 * V_1 ,
unsigned long V_41 , T_1 V_42 ,
T_2 V_43 , int V_23 )
{
struct V_21 * V_22 ;
T_3 * V_44 = ( T_3 * ) ( V_41 & V_45 ) ;
T_1 V_46 = V_42 ;
unsigned long V_47 , V_48 , V_49 ;
unsigned long * V_50 ;
int V_24 = 0 ;
if ( V_42 < V_1 -> V_4 . V_31 . V_32 ||
V_42 + V_43 > V_1 -> V_4 . V_31 . V_33 )
return - V_35 ;
V_48 = F_34 ( V_43 ) >> V_51 ;
if ( ! V_48 )
return 0 ;
F_16 ( & V_1 -> V_13 , V_47 ) ;
for ( V_49 = 0 ; V_49 < V_48 ; V_49 ++ ) {
V_50 = F_35 ( V_1 -> V_12 , V_42 ) ;
if ( ! V_50 ) {
V_24 = - V_26 ;
goto V_52;
}
F_36 ( V_50 , V_44 , V_23 ) ;
V_44 += V_53 ;
V_42 += V_53 ;
}
F_37 ( & V_1 -> V_14 ) ;
F_38 (domain_device, &s390_domain->devices, list) {
V_24 = F_39 ( ( V_29 ) V_22 -> V_19 -> V_54 << 32 ,
V_46 , V_48 * V_53 ) ;
if ( V_24 )
break;
}
F_40 ( & V_1 -> V_14 ) ;
V_52:
if ( V_24 && ( ( V_23 & V_55 ) == V_56 ) ) {
V_23 = V_57 ;
while ( V_49 -- > 0 ) {
V_44 -= V_53 ;
V_42 -= V_53 ;
V_50 = F_35 ( V_1 -> V_12 ,
V_42 ) ;
if ( ! V_50 )
break;
F_36 ( V_50 , V_44 , V_23 ) ;
}
}
F_18 ( & V_1 -> V_13 , V_47 ) ;
return V_24 ;
}
static int F_41 ( struct V_2 * V_4 , unsigned long V_58 ,
T_4 V_59 , T_2 V_43 , int V_60 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_23 = V_56 , V_24 = 0 ;
if ( ! ( V_60 & V_61 ) )
return - V_35 ;
if ( ! ( V_60 & V_62 ) )
V_23 |= V_63 ;
V_24 = F_33 ( V_1 , ( unsigned long ) V_59 , V_58 ,
V_43 , V_23 ) ;
return V_24 ;
}
static T_4 F_42 ( struct V_2 * V_4 ,
T_1 V_58 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
unsigned long * V_64 , * V_65 , * V_66 , V_23 ;
unsigned int V_67 , V_68 , V_69 ;
T_4 V_70 = 0 ;
if ( V_58 < V_4 -> V_31 . V_32 ||
V_58 > V_4 -> V_31 . V_33 )
return 0 ;
V_67 = F_43 ( V_58 ) ;
V_68 = F_44 ( V_58 ) ;
V_69 = F_45 ( V_58 ) ;
V_66 = V_1 -> V_12 ;
F_16 ( & V_1 -> V_13 , V_23 ) ;
if ( V_66 && F_46 ( V_66 [ V_67 ] ) ) {
V_64 = F_47 ( V_66 [ V_67 ] ) ;
if ( V_64 && F_46 ( V_64 [ V_68 ] ) ) {
V_65 = F_48 ( V_64 [ V_68 ] ) ;
if ( V_65 && F_49 ( V_65 [ V_69 ] ) )
V_70 = V_65 [ V_69 ] & V_71 ;
}
}
F_18 ( & V_1 -> V_13 , V_23 ) ;
return V_70 ;
}
static T_2 F_50 ( struct V_2 * V_4 ,
unsigned long V_58 , T_2 V_43 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_23 = V_57 ;
T_4 V_59 ;
int V_24 ;
V_59 = F_42 ( V_4 , V_58 ) ;
if ( ! V_59 )
return 0 ;
V_24 = F_33 ( V_1 , ( unsigned long ) V_59 , V_58 ,
V_43 , V_23 ) ;
if ( V_24 )
return 0 ;
return V_43 ;
}
static int T_5 F_51 ( void )
{
return F_52 ( & V_72 , & V_73 ) ;
}
