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
struct V_18 * V_19 = F_13 ( V_17 ) -> V_20 ;
if ( F_27 ( V_40 ) )
return F_28 ( V_40 ) ;
F_29 ( V_40 ) ;
F_30 ( & V_19 -> V_41 , V_17 ) ;
return 0 ;
}
static void F_31 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_13 ( V_17 ) -> V_20 ;
struct V_2 * V_4 ;
if ( V_19 && V_19 -> V_1 ) {
V_4 = F_32 ( V_17 ) ;
if ( V_4 )
F_21 ( V_4 , V_17 ) ;
}
F_33 ( & V_19 -> V_41 , V_17 ) ;
F_34 ( V_17 ) ;
}
static int F_35 ( struct V_1 * V_1 ,
unsigned long V_42 , T_1 V_43 ,
T_2 V_44 , int V_23 )
{
struct V_21 * V_22 ;
T_3 * V_45 = ( T_3 * ) ( V_42 & V_46 ) ;
T_1 V_47 = V_43 ;
unsigned long V_48 , V_49 , V_50 ;
unsigned long * V_51 ;
int V_24 = 0 ;
if ( V_43 < V_1 -> V_4 . V_31 . V_32 ||
V_43 + V_44 > V_1 -> V_4 . V_31 . V_33 )
return - V_35 ;
V_49 = F_36 ( V_44 ) >> V_52 ;
if ( ! V_49 )
return 0 ;
F_16 ( & V_1 -> V_13 , V_48 ) ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ ) {
V_51 = F_37 ( V_1 -> V_12 , V_43 ) ;
if ( ! V_51 ) {
V_24 = - V_26 ;
goto V_53;
}
F_38 ( V_51 , V_45 , V_23 ) ;
V_45 += V_54 ;
V_43 += V_54 ;
}
F_39 ( & V_1 -> V_14 ) ;
F_40 (domain_device, &s390_domain->devices, list) {
V_24 = F_41 ( ( V_29 ) V_22 -> V_19 -> V_55 << 32 ,
V_47 , V_49 * V_54 ) ;
if ( V_24 )
break;
}
F_42 ( & V_1 -> V_14 ) ;
V_53:
if ( V_24 && ( ( V_23 & V_56 ) == V_57 ) ) {
V_23 = V_58 ;
while ( V_50 -- > 0 ) {
V_45 -= V_54 ;
V_43 -= V_54 ;
V_51 = F_37 ( V_1 -> V_12 ,
V_43 ) ;
if ( ! V_51 )
break;
F_38 ( V_51 , V_45 , V_23 ) ;
}
}
F_18 ( & V_1 -> V_13 , V_48 ) ;
return V_24 ;
}
static int F_43 ( struct V_2 * V_4 , unsigned long V_59 ,
T_4 V_60 , T_2 V_44 , int V_61 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_23 = V_57 , V_24 = 0 ;
if ( ! ( V_61 & V_62 ) )
return - V_35 ;
if ( ! ( V_61 & V_63 ) )
V_23 |= V_64 ;
V_24 = F_35 ( V_1 , ( unsigned long ) V_60 , V_59 ,
V_44 , V_23 ) ;
return V_24 ;
}
static T_4 F_44 ( struct V_2 * V_4 ,
T_1 V_59 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
unsigned long * V_65 , * V_66 , * V_67 , V_23 ;
unsigned int V_68 , V_69 , V_70 ;
T_4 V_71 = 0 ;
if ( V_59 < V_4 -> V_31 . V_32 ||
V_59 > V_4 -> V_31 . V_33 )
return 0 ;
V_68 = F_45 ( V_59 ) ;
V_69 = F_46 ( V_59 ) ;
V_70 = F_47 ( V_59 ) ;
V_67 = V_1 -> V_12 ;
F_16 ( & V_1 -> V_13 , V_23 ) ;
if ( V_67 && F_48 ( V_67 [ V_68 ] ) ) {
V_65 = F_49 ( V_67 [ V_68 ] ) ;
if ( V_65 && F_48 ( V_65 [ V_69 ] ) ) {
V_66 = F_50 ( V_65 [ V_69 ] ) ;
if ( V_66 && F_51 ( V_66 [ V_70 ] ) )
V_71 = V_66 [ V_70 ] & V_72 ;
}
}
F_18 ( & V_1 -> V_13 , V_23 ) ;
return V_71 ;
}
static T_2 F_52 ( struct V_2 * V_4 ,
unsigned long V_59 , T_2 V_44 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_23 = V_58 ;
T_4 V_60 ;
int V_24 ;
V_60 = F_44 ( V_4 , V_59 ) ;
if ( ! V_60 )
return 0 ;
V_24 = F_35 ( V_1 , ( unsigned long ) V_60 , V_59 ,
V_44 , V_23 ) ;
if ( V_24 )
return 0 ;
return V_44 ;
}
int F_53 ( struct V_18 * V_19 )
{
int V_24 = 0 ;
V_24 = F_54 ( & V_19 -> V_41 , NULL , NULL ,
L_1 , V_19 -> V_73 ) ;
if ( V_24 )
goto V_74;
F_55 ( & V_19 -> V_41 , & V_75 ) ;
V_24 = F_56 ( & V_19 -> V_41 ) ;
if ( V_24 )
goto V_76;
return 0 ;
V_76:
F_57 ( & V_19 -> V_41 ) ;
V_74:
return V_24 ;
}
void F_58 ( struct V_18 * V_19 )
{
F_59 ( & V_19 -> V_41 ) ;
F_57 ( & V_19 -> V_41 ) ;
}
static int T_5 F_60 ( void )
{
return F_61 ( & V_77 , & V_75 ) ;
}
