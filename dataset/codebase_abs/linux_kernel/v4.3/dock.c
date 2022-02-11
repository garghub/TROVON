static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
V_6 = F_2 ( sizeof( * V_6 ) , V_7 ) ;
if ( ! V_6 )
return - V_8 ;
V_6 -> V_4 = V_4 ;
F_3 ( & V_6 -> V_9 ) ;
F_4 ( & V_6 -> V_9 , & V_2 -> V_10 ) ;
return 0 ;
}
static void F_5 ( struct V_5 * V_6 , T_1 V_11 ,
enum V_12 V_13 )
{
struct V_3 * V_4 = V_6 -> V_4 ;
F_6 () ;
if ( ! V_4 -> V_14 )
goto V_15;
if ( V_13 == V_16 ) {
void (* F_7)( struct V_3 * );
F_7 = V_4 -> V_14 -> F_7 ;
if ( F_7 ) {
F_8 () ;
F_7 ( V_4 ) ;
return;
}
} else if ( V_13 == V_17 ) {
void (* F_9)( struct V_3 * , T_1 );
F_9 = V_4 -> V_14 -> F_9 ;
if ( F_9 ) {
F_8 () ;
F_9 ( V_4 , V_11 ) ;
return;
}
} else {
int (* F_10)( struct V_3 * , T_1 );
F_10 = V_4 -> V_14 -> F_10 ;
if ( F_10 ) {
F_8 () ;
F_10 ( V_4 , V_11 ) ;
return;
}
}
V_15:
F_8 () ;
}
static struct V_1 * F_11 ( T_2 V_18 )
{
struct V_1 * V_2 ;
F_12 (ds, &dock_stations, sibling)
if ( V_2 -> V_18 == V_18 )
return V_2 ;
return NULL ;
}
static struct V_5 *
F_13 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_12 (dd, &ds->dependent_devices, list)
if ( V_4 == V_6 -> V_4 )
return V_6 ;
return NULL ;
}
void F_14 ( struct V_3 * V_4 ,
T_2 V_19 )
{
struct V_1 * V_2 = F_11 ( V_19 ) ;
if ( V_2 && ! F_13 ( V_2 , V_4 ) )
F_1 ( V_2 , V_4 ) ;
}
int F_15 ( struct V_3 * V_4 )
{
struct V_1 * V_1 ;
if ( ! V_20 )
return 0 ;
if ( F_16 ( V_4 -> V_18 ) )
return 1 ;
F_12 (dock_station, &dock_stations, sibling)
if ( F_13 ( V_1 , V_4 ) )
return 1 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
unsigned long long V_21 ;
T_3 V_22 ;
if ( V_2 ) {
V_22 = F_18 ( V_2 -> V_18 , L_1 , NULL , & V_21 ) ;
if ( F_19 ( V_22 ) && V_21 )
return 1 ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
F_21 (dd, &ds->dependent_devices, list)
F_5 ( V_6 , V_23 , false ) ;
F_21 (dd, &ds->dependent_devices, list)
F_22 ( V_6 -> V_4 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_11 )
{
struct V_5 * V_6 ;
F_12 (dd, &ds->dependent_devices, list)
F_5 ( V_6 , V_11 , V_16 ) ;
F_12 (dd, &ds->dependent_devices, list)
F_5 ( V_6 , V_11 , V_24 ) ;
F_12 (dd, &ds->dependent_devices, list) {
struct V_3 * V_4 = V_6 -> V_4 ;
if ( ! F_24 ( V_4 ) ) {
int V_25 = F_25 ( V_4 -> V_18 ) ;
if ( V_25 )
F_26 ( & V_4 -> V_26 , L_2 , - V_25 ) ;
}
}
}
static void F_27 ( struct V_1 * V_2 , T_1 V_11 , int V_27 )
{
struct V_28 * V_26 = & V_2 -> V_29 -> V_26 ;
char V_30 [ 13 ] ;
char * V_31 [] = { V_30 , NULL } ;
struct V_5 * V_6 ;
if ( V_27 == V_32 )
sprintf ( V_30 , L_3 ) ;
else
sprintf ( V_30 , L_4 ) ;
if ( V_27 == V_33 )
F_28 ( & V_26 -> V_34 , V_35 , V_31 ) ;
F_12 (dd, &ds->dependent_devices, list)
F_5 ( V_6 , V_11 , V_17 ) ;
if ( V_27 != V_33 )
F_28 ( & V_26 -> V_34 , V_35 , V_31 ) ;
}
static void F_29 ( struct V_1 * V_2 , int V_36 )
{
T_3 V_22 ;
struct V_37 V_38 ;
union V_39 V_40 ;
unsigned long long V_41 ;
F_30 ( V_2 -> V_18 , L_5 , V_36 ? L_6 : L_7 ) ;
V_38 . V_42 = 1 ;
V_38 . V_43 = & V_40 ;
V_40 . type = V_44 ;
V_40 . integer . V_41 = V_36 ;
V_22 = F_18 ( V_2 -> V_18 , L_8 , & V_38 , & V_41 ) ;
if ( F_31 ( V_22 ) && V_22 != V_45 )
F_32 ( V_2 -> V_18 , L_9 ,
V_22 ) ;
}
static inline void V_36 ( struct V_1 * V_2 )
{
F_29 ( V_2 , 1 ) ;
}
static inline void F_33 ( struct V_1 * V_2 )
{
F_29 ( V_2 , 0 ) ;
}
static inline void F_34 ( struct V_1 * V_2 )
{
V_2 -> V_46 |= V_47 ;
}
static inline void F_35 ( struct V_1 * V_2 )
{
V_2 -> V_46 &= ~ ( V_47 ) ;
V_2 -> V_48 = V_49 ;
}
static inline void F_36 ( struct V_1 * V_2 )
{
V_2 -> V_46 |= V_50 ;
}
static inline void F_37 ( struct V_1 * V_2 )
{
V_2 -> V_46 &= ~ ( V_50 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_46 & V_47 ) ||
F_39 ( V_49 , ( V_2 -> V_48 + V_51 ) ) )
return 1 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_11 )
{
if ( F_38 ( V_2 ) )
return - V_52 ;
F_27 ( V_2 , V_11 , V_32 ) ;
F_20 ( V_2 ) ;
F_33 ( V_2 ) ;
F_41 ( V_2 -> V_18 , 0 ) ;
F_42 ( V_2 -> V_18 ) ;
if ( F_17 ( V_2 ) ) {
F_32 ( V_2 -> V_18 , L_10 ) ;
return - V_52 ;
}
F_37 ( V_2 ) ;
return 0 ;
}
int F_43 ( struct V_3 * V_4 , T_1 V_11 )
{
T_2 V_18 = V_4 -> V_18 ;
struct V_1 * V_2 = F_11 ( V_18 ) ;
int V_53 = 0 ;
if ( ! V_2 )
return - V_54 ;
if ( ( V_2 -> V_46 & V_55 ) && V_11 == V_56 )
V_11 = V_23 ;
switch ( V_11 ) {
case V_57 :
case V_56 :
if ( ! F_38 ( V_2 ) && ! F_24 ( V_4 ) ) {
F_34 ( V_2 ) ;
V_36 ( V_2 ) ;
if ( ! F_17 ( V_2 ) ) {
F_32 ( V_18 , L_11 ) ;
F_35 ( V_2 ) ;
break;
}
F_23 ( V_2 , V_11 ) ;
F_35 ( V_2 ) ;
F_27 ( V_2 , V_11 , V_33 ) ;
F_41 ( V_2 -> V_18 , 1 ) ;
F_44 () ;
break;
}
if ( F_17 ( V_2 ) || F_38 ( V_2 ) )
break;
V_53 = 1 ;
V_11 = V_23 ;
case V_23 :
F_36 ( V_2 ) ;
if ( ( V_58 && ! ( V_2 -> V_46 & V_59 ) )
|| V_53 )
F_40 ( V_2 , V_11 ) ;
else
F_27 ( V_2 , V_11 , V_32 ) ;
break;
}
return 0 ;
}
static T_4 F_45 ( struct V_28 * V_26 ,
struct V_60 * V_61 , char * V_62 )
{
struct V_1 * V_1 = V_26 -> V_63 ;
struct V_3 * V_4 = NULL ;
F_46 ( V_1 -> V_18 , & V_4 ) ;
return snprintf ( V_62 , V_64 , L_12 , F_24 ( V_4 ) ) ;
}
static T_4 F_47 ( struct V_28 * V_26 ,
struct V_60 * V_61 , char * V_62 )
{
struct V_1 * V_1 = V_26 -> V_63 ;
return snprintf ( V_62 , V_64 , L_13 , V_1 -> V_46 ) ;
}
static T_4 F_48 ( struct V_28 * V_26 , struct V_60 * V_61 ,
const char * V_62 , T_5 V_42 )
{
int V_25 ;
struct V_1 * V_1 = V_26 -> V_63 ;
if ( ! V_42 )
return - V_65 ;
F_49 () ;
F_36 ( V_1 ) ;
V_25 = F_40 ( V_1 , V_23 ) ;
F_50 () ;
return V_25 ? V_25 : V_42 ;
}
static T_4 F_51 ( struct V_28 * V_26 ,
struct V_60 * V_61 , char * V_62 )
{
unsigned long long V_66 ;
struct V_1 * V_1 = V_26 -> V_63 ;
T_3 V_22 = F_18 ( V_1 -> V_18 ,
L_14 , NULL , & V_66 ) ;
if ( F_31 ( V_22 ) )
return 0 ;
return snprintf ( V_62 , V_64 , L_15 , V_66 ) ;
}
static T_4 F_52 ( struct V_28 * V_26 ,
struct V_60 * V_61 , char * V_62 )
{
struct V_1 * V_1 = V_26 -> V_63 ;
char * type ;
if ( V_1 -> V_46 & V_55 )
type = L_16 ;
else if ( V_1 -> V_46 & V_59 )
type = L_17 ;
else if ( V_1 -> V_46 & V_67 )
type = L_18 ;
else
type = L_19 ;
return snprintf ( V_62 , V_64 , L_5 , type ) ;
}
void F_53 ( struct V_3 * V_4 )
{
struct V_1 * V_1 , V_2 = { NULL , } ;
struct V_68 V_69 ;
T_2 V_18 = V_4 -> V_18 ;
struct V_70 * V_6 ;
int V_25 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
V_69 . V_71 = L_20 ;
V_69 . V_72 = V_20 ;
V_69 . V_73 = F_54 ( V_4 ) ;
V_69 . V_74 = & V_2 ;
V_69 . V_75 = sizeof( V_2 ) ;
V_6 = F_55 ( & V_69 ) ;
if ( F_56 ( V_6 ) )
return;
V_1 = V_6 -> V_26 . V_63 ;
V_1 -> V_18 = V_18 ;
V_1 -> V_29 = V_6 ;
V_1 -> V_48 = V_49 - V_51 ;
F_3 ( & V_1 -> V_76 ) ;
F_3 ( & V_1 -> V_10 ) ;
F_57 ( & V_6 -> V_26 , 0 ) ;
if ( F_16 ( V_18 ) )
V_1 -> V_46 |= V_55 ;
if ( F_58 ( V_18 ) )
V_1 -> V_46 |= V_59 ;
if ( F_59 ( V_4 ) )
V_1 -> V_46 |= V_67 ;
V_25 = F_60 ( & V_6 -> V_26 . V_34 , & V_77 ) ;
if ( V_25 )
goto V_78;
V_25 = F_1 ( V_1 , V_4 ) ;
if ( V_25 )
goto V_79;
V_20 ++ ;
F_61 ( & V_1 -> V_76 , & V_80 ) ;
V_4 -> V_46 . V_81 = true ;
F_62 ( & V_4 -> V_26 , L_21 ,
V_20 ) ;
return;
V_79:
F_63 ( & V_6 -> V_26 . V_34 , & V_77 ) ;
V_78:
F_64 ( V_6 ) ;
F_32 ( V_18 , L_22 , V_82 , V_25 ) ;
}
