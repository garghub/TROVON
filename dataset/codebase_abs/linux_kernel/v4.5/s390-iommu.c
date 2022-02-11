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
V_24 = F_15 ( V_19 , 0 , V_19 -> V_27 + V_28 ,
V_19 -> V_27 + V_19 -> V_29 - 1 ,
( V_30 ) V_19 -> V_12 ) ;
if ( V_24 )
goto V_31;
F_16 ( & V_1 -> V_14 , V_23 ) ;
if ( F_17 ( & V_1 -> V_15 ) ) {
V_4 -> V_32 . V_33 = V_19 -> V_27 ;
V_4 -> V_32 . V_34 = V_19 -> V_35 ;
V_4 -> V_32 . V_36 = true ;
} else if ( V_4 -> V_32 . V_33 != V_19 -> V_27 ||
V_4 -> V_32 . V_34 != V_19 -> V_35 ) {
V_24 = - V_37 ;
F_18 ( & V_1 -> V_14 , V_23 ) ;
goto V_31;
}
V_22 -> V_19 = V_19 ;
V_19 -> V_1 = V_1 ;
F_19 ( & V_22 -> V_38 , & V_1 -> V_15 ) ;
F_18 ( & V_1 -> V_14 , V_23 ) ;
return 0 ;
V_31:
F_20 ( V_19 ) ;
F_7 ( V_22 ) ;
return V_24 ;
}
static void F_21 ( struct V_2 * V_4 ,
struct V_16 * V_17 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_18 * V_19 = F_13 ( V_17 ) -> V_20 ;
struct V_21 * V_22 , * V_39 ;
unsigned long V_23 ;
int V_40 = 0 ;
if ( ! V_19 )
return;
F_16 ( & V_1 -> V_14 , V_23 ) ;
F_22 (domain_device, tmp, &s390_domain->devices,
list) {
if ( V_22 -> V_19 == V_19 ) {
F_23 ( & V_22 -> V_38 ) ;
F_7 ( V_22 ) ;
V_40 = 1 ;
break;
}
}
F_18 ( & V_1 -> V_14 , V_23 ) ;
if ( V_40 ) {
V_19 -> V_1 = NULL ;
F_24 ( V_19 , 0 ) ;
F_20 ( V_19 ) ;
}
}
static int F_25 ( struct V_16 * V_17 )
{
struct V_41 * V_42 ;
int V_24 ;
V_42 = F_26 ( V_17 ) ;
if ( ! V_42 ) {
V_42 = F_27 () ;
if ( F_28 ( V_42 ) )
return F_29 ( V_42 ) ;
}
V_24 = F_30 ( V_42 , V_17 ) ;
F_31 ( V_42 ) ;
return V_24 ;
}
static void F_32 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_13 ( V_17 ) -> V_20 ;
struct V_2 * V_4 ;
if ( V_19 && V_19 -> V_1 ) {
V_4 = F_33 ( V_17 ) ;
if ( V_4 )
F_21 ( V_4 , V_17 ) ;
}
F_34 ( V_17 ) ;
}
static int F_35 ( struct V_1 * V_1 ,
unsigned long V_43 , T_1 V_44 ,
T_2 V_45 , int V_23 )
{
struct V_21 * V_22 ;
T_3 * V_46 = ( T_3 * ) ( V_43 & V_47 ) ;
T_1 V_48 = V_44 ;
unsigned long V_49 , V_50 , V_51 ;
unsigned long * V_52 ;
int V_24 = 0 ;
if ( V_44 < V_1 -> V_4 . V_32 . V_33 ||
V_44 + V_45 > V_1 -> V_4 . V_32 . V_34 )
return - V_37 ;
V_50 = F_36 ( V_45 ) >> V_53 ;
if ( ! V_50 )
return 0 ;
F_16 ( & V_1 -> V_13 , V_49 ) ;
for ( V_51 = 0 ; V_51 < V_50 ; V_51 ++ ) {
V_52 = F_37 ( V_1 -> V_12 , V_44 ) ;
if ( ! V_52 ) {
V_24 = - V_26 ;
goto V_54;
}
F_38 ( V_52 , V_46 , V_23 ) ;
V_46 += V_55 ;
V_44 += V_55 ;
}
F_39 ( & V_1 -> V_14 ) ;
F_40 (domain_device, &s390_domain->devices, list) {
V_24 = F_41 ( ( V_30 ) V_22 -> V_19 -> V_56 << 32 ,
V_48 , V_50 * V_55 ) ;
if ( V_24 )
break;
}
F_42 ( & V_1 -> V_14 ) ;
V_54:
if ( V_24 && ( ( V_23 & V_57 ) == V_58 ) ) {
V_23 = V_59 ;
while ( V_51 -- > 0 ) {
V_46 -= V_55 ;
V_44 -= V_55 ;
V_52 = F_37 ( V_1 -> V_12 ,
V_44 ) ;
if ( ! V_52 )
break;
F_38 ( V_52 , V_46 , V_23 ) ;
}
}
F_18 ( & V_1 -> V_13 , V_49 ) ;
return V_24 ;
}
static int F_43 ( struct V_2 * V_4 , unsigned long V_60 ,
T_4 V_61 , T_2 V_45 , int V_62 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_23 = V_58 , V_24 = 0 ;
if ( ! ( V_62 & V_63 ) )
return - V_37 ;
if ( ! ( V_62 & V_64 ) )
V_23 |= V_65 ;
V_24 = F_35 ( V_1 , ( unsigned long ) V_61 , V_60 ,
V_45 , V_23 ) ;
return V_24 ;
}
static T_4 F_44 ( struct V_2 * V_4 ,
T_1 V_60 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
unsigned long * V_66 , * V_67 , * V_68 , V_23 ;
unsigned int V_69 , V_70 , V_71 ;
T_4 V_72 = 0 ;
if ( V_60 < V_4 -> V_32 . V_33 ||
V_60 > V_4 -> V_32 . V_34 )
return 0 ;
V_69 = F_45 ( V_60 ) ;
V_70 = F_46 ( V_60 ) ;
V_71 = F_47 ( V_60 ) ;
V_68 = V_1 -> V_12 ;
F_16 ( & V_1 -> V_13 , V_23 ) ;
if ( V_68 && F_48 ( V_68 [ V_69 ] ) ) {
V_66 = F_49 ( V_68 [ V_69 ] ) ;
if ( V_66 && F_48 ( V_66 [ V_70 ] ) ) {
V_67 = F_50 ( V_66 [ V_70 ] ) ;
if ( V_67 && F_51 ( V_67 [ V_71 ] ) )
V_72 = V_67 [ V_71 ] & V_73 ;
}
}
F_18 ( & V_1 -> V_13 , V_23 ) ;
return V_72 ;
}
static T_2 F_52 ( struct V_2 * V_4 ,
unsigned long V_60 , T_2 V_45 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
int V_23 = V_59 ;
T_4 V_61 ;
int V_24 ;
V_61 = F_44 ( V_4 , V_60 ) ;
if ( ! V_61 )
return 0 ;
V_24 = F_35 ( V_1 , ( unsigned long ) V_61 , V_60 ,
V_45 , V_23 ) ;
if ( V_24 )
return 0 ;
return V_45 ;
}
static int T_5 F_53 ( void )
{
return F_54 ( & V_74 , & V_75 ) ;
}
