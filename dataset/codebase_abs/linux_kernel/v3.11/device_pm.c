const char * F_1 ( int V_1 )
{
switch ( V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
case V_6 :
return L_5 ;
default:
return L_6 ;
}
}
int F_2 ( struct V_7 * V_8 , int * V_1 )
{
int V_9 = V_10 ;
if ( ! V_8 || ! V_1 )
return - V_11 ;
if ( ! V_8 -> V_12 . V_13 ) {
* V_1 = V_8 -> V_14 ?
V_8 -> V_14 -> V_15 . V_1 : V_2 ;
goto V_16;
}
if ( V_8 -> V_15 . V_12 . V_17 ) {
int error = F_3 ( V_8 , & V_9 ) ;
if ( error )
return error ;
}
if ( V_8 -> V_15 . V_12 . V_18 ) {
T_1 V_19 = V_8 -> V_19 ;
unsigned long long V_20 ;
T_2 V_21 ;
V_21 = F_4 ( V_19 , L_7 , NULL , & V_20 ) ;
if ( F_5 ( V_21 ) )
return - V_22 ;
if ( V_20 > V_9 && V_20 < V_6 )
V_9 = V_20 ;
else if ( V_9 == V_10 )
V_9 = V_20 > V_4 ? V_6 : V_20 ;
}
if ( V_8 -> V_14 && V_8 -> V_14 -> V_15 . V_1 == V_10
&& V_9 == V_2 )
V_8 -> V_14 -> V_15 . V_1 = V_2 ;
* V_1 = V_9 ;
V_16:
F_6 ( ( V_23 , L_8 ,
V_8 -> V_24 . V_25 , F_1 ( * V_1 ) ) ) ;
return 0 ;
}
static int F_7 ( struct V_7 * V_26 , int V_1 )
{
if ( V_26 -> V_15 . V_27 [ V_1 ] . V_12 . V_28 ) {
char V_29 [ 5 ] = { '_' , 'P' , 'S' , '0' + V_1 , '\0' } ;
T_2 V_21 ;
V_21 = F_8 ( V_26 -> V_19 , V_29 , NULL , NULL ) ;
if ( F_5 ( V_21 ) )
return - V_22 ;
}
return 0 ;
}
int F_9 ( struct V_7 * V_8 , int V_1 )
{
int V_9 = 0 ;
bool V_30 = false ;
if ( ! V_8 || ( V_1 < V_2 ) || ( V_1 > V_6 ) )
return - V_11 ;
if ( V_1 == V_8 -> V_15 . V_1 ) {
F_6 ( ( V_23 , L_9 ,
F_1 ( V_1 ) ) ) ;
return 0 ;
}
if ( ! V_8 -> V_15 . V_27 [ V_1 ] . V_12 . V_31 ) {
F_10 (KERN_WARNING PREFIX L_10 ,
acpi_power_state_string(state)) ;
return - V_22 ;
}
if ( V_8 -> V_14 && ( V_1 < V_8 -> V_14 -> V_15 . V_1 ) ) {
F_10 (KERN_WARNING PREFIX
L_11
L_12 ) ;
return - V_22 ;
}
if ( V_1 == V_6
&& V_8 -> V_15 . V_27 [ V_6 ] . V_12 . V_32 ) {
V_1 = V_5 ;
V_30 = true ;
}
if ( V_1 < V_8 -> V_15 . V_1 && V_1 != V_2
&& V_8 -> V_15 . V_1 >= V_5 ) {
F_10 (KERN_WARNING PREFIX
L_13 ) ;
return - V_22 ;
}
if ( V_8 -> V_15 . V_12 . V_17 ) {
V_9 = F_11 ( V_8 , V_1 ) ;
if ( V_9 )
goto V_33;
}
V_9 = F_7 ( V_8 , V_1 ) ;
if ( V_9 )
goto V_33;
if ( V_30 ) {
V_8 -> V_15 . V_1 = V_1 ;
V_1 = V_6 ;
V_9 = F_11 ( V_8 , V_1 ) ;
}
V_33:
if ( V_9 ) {
F_10 (KERN_WARNING PREFIX
L_14 ,
device->pnp.bus_id,
acpi_power_state_string(state)) ;
} else {
V_8 -> V_15 . V_1 = V_1 ;
F_6 ( ( V_23 ,
L_15 ,
V_8 -> V_24 . V_25 ,
F_1 ( V_1 ) ) ) ;
}
return V_9 ;
}
int F_12 ( T_1 V_19 , int V_1 )
{
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_13 ( V_19 , & V_8 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_8 -> V_12 . V_13 ) {
F_6 ( ( V_23 ,
L_16 ,
F_14 ( & V_8 -> V_34 ) ) ) ;
return - V_22 ;
}
return F_9 ( V_8 , V_1 ) ;
}
int F_15 ( struct V_7 * V_8 )
{
int V_1 ;
int V_9 ;
if ( ! V_8 )
return - V_11 ;
V_8 -> V_15 . V_1 = V_10 ;
V_9 = F_2 ( V_8 , & V_1 ) ;
if ( V_9 )
return V_9 ;
if ( V_1 < V_6 && V_8 -> V_15 . V_12 . V_17 ) {
V_9 = F_16 ( V_8 , V_1 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_7 ( V_8 , V_1 ) ;
if ( V_9 )
return V_9 ;
} else if ( V_1 == V_10 ) {
V_1 = V_2 ;
}
V_8 -> V_15 . V_1 = V_1 ;
return 0 ;
}
int F_17 ( struct V_7 * V_8 )
{
int V_35 = 0 ;
if ( ! V_8 -> V_15 . V_12 . V_17
&& ! V_8 -> V_15 . V_12 . V_18
&& V_8 -> V_15 . V_1 == V_2 )
V_35 = F_7 ( V_8 , V_2 ) ;
return V_35 ;
}
int F_18 ( T_1 V_19 , int * V_36 )
{
struct V_7 * V_8 ;
int V_1 ;
int V_9 ;
V_9 = F_13 ( V_19 , & V_8 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_2 ( V_8 , & V_1 ) ;
if ( V_9 )
return V_9 ;
if ( V_1 == V_10 ) {
V_1 = V_2 ;
V_9 = F_9 ( V_8 , V_1 ) ;
if ( V_9 )
return V_9 ;
} else {
if ( V_8 -> V_15 . V_12 . V_17 ) {
V_9 = F_11 ( V_8 , V_1 ) ;
if ( V_9 )
return V_9 ;
}
V_8 -> V_15 . V_1 = V_1 ;
}
if ( V_36 )
* V_36 = V_1 ;
return 0 ;
}
bool F_19 ( T_1 V_19 )
{
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_13 ( V_19 , & V_8 ) ;
return V_9 ? false : V_8 -> V_12 . V_13 ;
}
T_2 F_20 ( struct V_7 * V_26 ,
T_3 V_37 , void * V_38 )
{
T_2 V_21 = V_39 ;
F_21 ( & V_40 ) ;
if ( V_26 -> V_41 . V_12 . V_42 )
goto V_16;
V_21 = F_22 ( V_26 -> V_19 ,
V_43 ,
V_37 , V_38 ) ;
if ( F_5 ( V_21 ) )
goto V_16;
V_26 -> V_41 . V_12 . V_42 = true ;
V_16:
F_23 ( & V_40 ) ;
return V_21 ;
}
T_2 F_24 ( struct V_7 * V_26 ,
T_3 V_37 )
{
T_2 V_21 = V_44 ;
F_21 ( & V_40 ) ;
if ( ! V_26 -> V_41 . V_12 . V_42 )
goto V_16;
V_21 = F_25 ( V_26 -> V_19 ,
V_43 ,
V_37 ) ;
if ( F_5 ( V_21 ) )
goto V_16;
V_26 -> V_41 . V_12 . V_42 = false ;
V_16:
F_23 ( & V_40 ) ;
return V_21 ;
}
bool F_26 ( T_1 V_19 )
{
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_13 ( V_19 , & V_8 ) ;
return V_9 ? false : V_8 -> V_41 . V_12 . V_31 ;
}
static int F_27 ( struct V_8 * V_34 , struct V_7 * V_26 ,
T_4 V_45 , int * V_46 , int * V_47 )
{
char V_29 [] = { '_' , 'S' , '0' + V_45 , 'D' , '\0' } ;
T_1 V_19 = V_26 -> V_19 ;
unsigned long long V_35 ;
int V_48 , V_49 ;
bool V_41 = false ;
T_2 V_21 ;
V_48 = V_2 ;
V_49 = V_6 ;
if ( V_45 > V_50 ) {
V_35 = V_48 ;
V_21 = F_4 ( V_19 , V_29 , NULL , & V_35 ) ;
if ( ( F_5 ( V_21 ) && V_21 != V_51 )
|| V_35 > V_6 )
return - V_52 ;
if ( ! V_26 -> V_15 . V_27 [ V_35 ] . V_12 . V_31 ) {
if ( V_35 == V_5 )
V_35 = V_6 ;
else
return - V_52 ;
}
V_48 = V_35 ;
V_41 = F_28 ( V_34 ) && V_26 -> V_41 . V_12 . V_31
&& V_26 -> V_41 . V_53 >= V_45 ;
} else if ( F_29 ( V_34 , V_54 ) !=
V_55 ) {
V_41 = V_26 -> V_41 . V_12 . V_31 ;
}
if ( V_41 ) {
V_29 [ 3 ] = 'W' ;
V_21 = F_4 ( V_19 , V_29 , NULL , & V_35 ) ;
if ( V_21 == V_51 ) {
if ( V_45 > V_50 )
V_49 = V_48 ;
} else if ( F_30 ( V_21 ) && V_35 <= V_6 ) {
if ( ! V_26 -> V_15 . V_27 [ V_35 ] . V_12 . V_31 )
V_35 = V_6 ;
V_49 = V_35 > V_48 ? V_35 : V_48 ;
} else {
return - V_52 ;
}
}
if ( V_46 )
* V_46 = V_48 ;
if ( V_47 )
* V_47 = V_49 ;
return 0 ;
}
int F_31 ( struct V_8 * V_34 , int * V_46 , int V_56 )
{
T_1 V_19 = F_32 ( V_34 ) ;
struct V_7 * V_26 ;
int V_35 , V_48 , V_49 ;
if ( V_56 < V_2 || V_56 > V_6 )
return - V_11 ;
if ( V_56 > V_5 ) {
enum V_57 V_58 ;
V_58 = F_29 ( V_34 , V_59 ) ;
if ( V_58 == V_60 )
V_56 = V_5 ;
}
if ( ! V_19 || F_13 ( V_19 , & V_26 ) ) {
F_33 ( V_34 , L_17 , V_61 ) ;
return - V_22 ;
}
V_35 = F_27 ( V_34 , V_26 , F_34 () ,
& V_48 , & V_49 ) ;
if ( V_35 )
return V_35 ;
if ( V_56 < V_48 )
return - V_11 ;
if ( V_49 > V_56 ) {
for ( V_49 = V_56 ; V_49 > V_48 ; V_49 -- ) {
if ( V_26 -> V_15 . V_27 [ V_49 ] . V_12 . V_31 )
break;
}
}
if ( V_46 )
* V_46 = V_48 ;
return V_49 ;
}
static void F_35 ( T_1 V_19 , T_4 V_62 , void * V_38 )
{
struct V_8 * V_34 = V_38 ;
if ( V_62 == V_63 && V_34 ) {
F_36 ( V_34 , 0 ) ;
F_37 ( V_34 ) ;
}
}
int F_38 ( struct V_7 * V_26 , bool V_64 )
{
struct V_65 * V_41 = & V_26 -> V_41 ;
if ( V_64 ) {
T_2 V_66 ;
int error ;
error = F_39 ( V_26 , V_50 ) ;
if ( error )
return error ;
V_66 = F_40 ( V_41 -> V_67 , V_41 -> V_68 ) ;
if ( F_5 ( V_66 ) ) {
F_41 ( V_26 ) ;
return - V_69 ;
}
} else {
F_42 ( V_41 -> V_67 , V_41 -> V_68 ) ;
F_41 ( V_26 ) ;
}
return 0 ;
}
int F_43 ( struct V_8 * V_70 , bool V_64 )
{
struct V_7 * V_26 ;
T_1 V_19 ;
if ( ! F_44 ( V_70 ) )
return - V_11 ;
V_19 = F_32 ( V_70 ) ;
if ( ! V_19 || F_13 ( V_19 , & V_26 ) ) {
F_33 ( V_70 , L_17 ,
V_61 ) ;
return - V_22 ;
}
return F_38 ( V_26 , V_64 ) ;
}
static inline void F_35 ( T_1 V_19 , T_4 V_62 ,
void * V_38 ) {}
int F_45 ( struct V_7 * V_26 , T_4 V_45 ,
bool V_64 )
{
return V_64 ?
F_39 ( V_26 , V_45 ) :
F_41 ( V_26 ) ;
}
int F_46 ( struct V_8 * V_34 , bool V_64 )
{
T_1 V_19 ;
struct V_7 * V_26 ;
int error ;
if ( ! F_47 ( V_34 ) )
return - V_11 ;
V_19 = F_32 ( V_34 ) ;
if ( ! V_19 || F_13 ( V_19 , & V_26 ) ) {
F_33 ( V_34 , L_17 , V_61 ) ;
return - V_22 ;
}
error = F_45 ( V_26 , F_34 () ,
V_64 ) ;
if ( ! error )
F_48 ( V_34 , L_18 ,
V_64 ? L_19 : L_20 ) ;
return error ;
}
struct V_7 * F_49 ( struct V_8 * V_34 )
{
T_1 V_19 = F_32 ( V_34 ) ;
struct V_7 * V_26 ;
return V_19 && ! F_13 ( V_19 , & V_26 ) ? V_26 : NULL ;
}
static int F_50 ( struct V_8 * V_34 , struct V_7 * V_26 ,
T_4 V_71 )
{
int V_35 , V_1 ;
if ( ! F_51 ( V_26 ) )
return 0 ;
V_35 = F_27 ( V_34 , V_26 , V_71 , NULL , & V_1 ) ;
return V_35 ? V_35 : F_9 ( V_26 , V_1 ) ;
}
static int F_52 ( struct V_7 * V_26 )
{
return F_51 ( V_26 ) ?
F_9 ( V_26 , V_2 ) : 0 ;
}
int F_53 ( struct V_8 * V_34 )
{
struct V_7 * V_26 = F_49 ( V_34 ) ;
bool V_72 ;
int error ;
if ( ! V_26 )
return 0 ;
V_72 = F_29 ( V_34 , V_54 ) >
V_55 ;
error = F_38 ( V_26 , V_72 ) ;
if ( V_72 && error )
return - V_73 ;
error = F_50 ( V_34 , V_26 , V_50 ) ;
if ( error )
F_38 ( V_26 , false ) ;
return error ;
}
int F_54 ( struct V_8 * V_34 )
{
struct V_7 * V_26 = F_49 ( V_34 ) ;
int error ;
if ( ! V_26 )
return 0 ;
error = F_52 ( V_26 ) ;
F_38 ( V_26 , false ) ;
return error ;
}
int F_55 ( struct V_8 * V_34 )
{
int V_35 = F_56 ( V_34 ) ;
return V_35 ? V_35 : F_53 ( V_34 ) ;
}
int F_57 ( struct V_8 * V_34 )
{
int V_35 = F_54 ( V_34 ) ;
return V_35 ? V_35 : F_58 ( V_34 ) ;
}
int F_59 ( struct V_8 * V_34 )
{
struct V_7 * V_26 = F_49 ( V_34 ) ;
T_4 V_45 ;
bool V_41 ;
int error ;
if ( ! V_26 )
return 0 ;
V_45 = F_34 () ;
V_41 = F_28 ( V_34 ) ;
error = F_45 ( V_26 , V_45 , V_41 ) ;
if ( V_41 && error )
return error ;
error = F_50 ( V_34 , V_26 , V_45 ) ;
if ( error )
F_45 ( V_26 , V_10 , false ) ;
return error ;
}
int F_60 ( struct V_8 * V_34 )
{
struct V_7 * V_26 = F_49 ( V_34 ) ;
int error ;
if ( ! V_26 )
return 0 ;
error = F_52 ( V_26 ) ;
F_45 ( V_26 , V_10 , false ) ;
return error ;
}
int F_61 ( struct V_8 * V_34 )
{
F_37 ( V_34 ) ;
return F_62 ( V_34 ) ;
}
int F_63 ( struct V_8 * V_34 )
{
int V_35 = F_64 ( V_34 ) ;
return V_35 ? V_35 : F_59 ( V_34 ) ;
}
int F_65 ( struct V_8 * V_34 )
{
int V_35 = F_60 ( V_34 ) ;
return V_35 ? V_35 : F_66 ( V_34 ) ;
}
int F_67 ( struct V_8 * V_34 , bool V_74 )
{
struct V_7 * V_26 = F_49 ( V_34 ) ;
if ( ! V_26 )
return - V_22 ;
if ( V_34 -> V_75 )
return - V_76 ;
F_20 ( V_26 , F_35 , V_34 ) ;
V_34 -> V_75 = & V_77 ;
if ( V_74 ) {
F_52 ( V_26 ) ;
F_38 ( V_26 , false ) ;
}
return 0 ;
}
void F_68 ( struct V_8 * V_34 , bool V_78 )
{
struct V_7 * V_26 = F_49 ( V_34 ) ;
if ( V_26 && V_34 -> V_75 == & V_77 ) {
V_34 -> V_75 = NULL ;
F_24 ( V_26 , F_35 ) ;
if ( V_78 ) {
F_69 ( V_34 ) ;
F_70 ( V_34 ) ;
F_38 ( V_26 , false ) ;
F_50 ( V_34 , V_26 , V_50 ) ;
}
}
}
void F_71 ( T_1 V_19 , struct V_8 * V_79 )
{
struct V_80 * V_81 ;
struct V_7 * V_26 ;
if ( ! V_79 || F_13 ( V_19 , & V_26 ) )
return;
F_21 ( & V_26 -> V_82 ) ;
F_72 (dep, &adev->power_dependent, node)
if ( V_81 -> V_34 == V_79 )
goto V_16;
V_81 = F_73 ( sizeof( * V_81 ) , V_83 ) ;
if ( V_81 ) {
V_81 -> V_34 = V_79 ;
F_74 ( & V_81 -> V_84 , & V_26 -> V_85 ) ;
}
V_16:
F_23 ( & V_26 -> V_82 ) ;
}
void F_75 ( T_1 V_19 , struct V_8 * V_79 )
{
struct V_80 * V_81 ;
struct V_7 * V_26 ;
if ( ! V_79 || F_13 ( V_19 , & V_26 ) )
return;
F_21 ( & V_26 -> V_82 ) ;
F_72 (dep, &adev->power_dependent, node)
if ( V_81 -> V_34 == V_79 ) {
F_76 ( & V_81 -> V_84 ) ;
F_77 ( V_81 ) ;
break;
}
F_23 ( & V_26 -> V_82 ) ;
}
