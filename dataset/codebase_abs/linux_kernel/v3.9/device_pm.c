T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 , void * V_4 )
{
T_1 V_5 = V_6 ;
F_2 ( & V_7 ) ;
if ( V_2 -> V_8 . V_9 . V_10 )
goto V_11;
V_5 = F_3 ( V_2 -> V_12 ,
V_13 ,
V_3 , V_4 ) ;
if ( F_4 ( V_5 ) )
goto V_11;
V_2 -> V_8 . V_9 . V_10 = true ;
V_11:
F_5 ( & V_7 ) ;
return V_5 ;
}
T_1 F_6 ( struct V_1 * V_2 ,
T_2 V_3 )
{
T_1 V_5 = V_14 ;
F_2 ( & V_7 ) ;
if ( ! V_2 -> V_8 . V_9 . V_10 )
goto V_11;
V_5 = F_7 ( V_2 -> V_12 ,
V_13 ,
V_3 ) ;
if ( F_4 ( V_5 ) )
goto V_11;
V_2 -> V_8 . V_9 . V_10 = false ;
V_11:
F_5 ( & V_7 ) ;
return V_5 ;
}
const char * F_8 ( int V_15 )
{
switch ( V_15 ) {
case V_16 :
return L_1 ;
case V_17 :
return L_2 ;
case V_18 :
return L_3 ;
case V_19 :
return L_4 ;
case V_20 :
return L_5 ;
default:
return L_6 ;
}
}
int F_9 ( struct V_1 * V_21 , int * V_15 )
{
int V_22 = V_23 ;
if ( ! V_21 || ! V_15 )
return - V_24 ;
if ( ! V_21 -> V_9 . V_25 ) {
* V_15 = V_21 -> V_26 ?
V_21 -> V_26 -> V_27 . V_15 : V_16 ;
goto V_11;
}
if ( V_21 -> V_27 . V_9 . V_28 ) {
unsigned long long V_29 ;
T_1 V_5 = F_10 ( V_21 -> V_12 ,
L_7 , NULL , & V_29 ) ;
if ( F_4 ( V_5 ) )
return - V_30 ;
V_22 = V_29 ;
}
if ( V_22 <= V_18 ) {
;
} else if ( V_21 -> V_27 . V_9 . V_31 ) {
int error = F_11 ( V_21 , & V_22 ) ;
if ( error )
return error ;
} else if ( V_22 == V_19 ) {
V_22 = V_32 ;
}
if ( V_21 -> V_26 && V_21 -> V_26 -> V_27 . V_15 == V_23
&& V_22 == V_16 )
V_21 -> V_26 -> V_27 . V_15 = V_16 ;
* V_15 = V_22 ;
V_11:
F_12 ( ( V_33 , L_8 ,
V_21 -> V_34 . V_35 , F_8 ( * V_15 ) ) ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , int V_15 )
{
if ( V_2 -> V_27 . V_36 [ V_15 ] . V_9 . V_37 ) {
char V_38 [ 5 ] = { '_' , 'P' , 'S' , '0' + V_15 , '\0' } ;
T_1 V_5 ;
V_5 = F_14 ( V_2 -> V_12 , V_38 , NULL , NULL ) ;
if ( F_4 ( V_5 ) )
return - V_30 ;
}
return 0 ;
}
int F_15 ( struct V_1 * V_21 , int V_15 )
{
int V_22 = 0 ;
bool V_39 = false ;
if ( ! V_21 || ( V_15 < V_16 ) || ( V_15 > V_20 ) )
return - V_24 ;
if ( V_15 == V_21 -> V_27 . V_15 ) {
F_12 ( ( V_33 , L_9 ,
F_8 ( V_15 ) ) ) ;
return 0 ;
}
if ( ! V_21 -> V_27 . V_36 [ V_15 ] . V_9 . V_40 ) {
F_16 (KERN_WARNING PREFIX L_10 ,
acpi_power_state_string(state)) ;
return - V_30 ;
}
if ( V_21 -> V_26 && ( V_15 < V_21 -> V_26 -> V_27 . V_15 ) ) {
F_16 (KERN_WARNING PREFIX
L_11
L_12 ) ;
return - V_30 ;
}
if ( V_15 == V_20
&& V_21 -> V_27 . V_36 [ V_20 ] . V_9 . V_41 ) {
V_15 = V_19 ;
V_39 = true ;
}
if ( V_15 < V_21 -> V_27 . V_15 && V_15 != V_16
&& V_21 -> V_27 . V_15 >= V_19 ) {
F_16 (KERN_WARNING PREFIX
L_13 ) ;
return - V_30 ;
}
if ( V_21 -> V_27 . V_9 . V_31 ) {
V_22 = F_17 ( V_21 , V_15 ) ;
if ( V_22 )
goto V_42;
}
V_22 = F_13 ( V_21 , V_15 ) ;
if ( V_22 )
goto V_42;
if ( V_39 ) {
V_21 -> V_27 . V_15 = V_15 ;
V_15 = V_20 ;
V_22 = F_17 ( V_21 , V_15 ) ;
}
V_42:
if ( V_22 ) {
F_16 (KERN_WARNING PREFIX
L_14 ,
device->pnp.bus_id,
acpi_power_state_string(state)) ;
} else {
V_21 -> V_27 . V_15 = V_15 ;
F_12 ( ( V_33 ,
L_15 ,
V_21 -> V_34 . V_35 ,
F_8 ( V_15 ) ) ) ;
}
return V_22 ;
}
int F_18 ( T_3 V_12 , int V_15 )
{
struct V_1 * V_21 ;
int V_22 ;
V_22 = F_19 ( V_12 , & V_21 ) ;
if ( V_22 )
return V_22 ;
if ( ! V_21 -> V_9 . V_25 ) {
F_12 ( ( V_33 ,
L_16 ,
F_20 ( & V_21 -> V_43 ) ) ) ;
return - V_30 ;
}
return F_15 ( V_21 , V_15 ) ;
}
int F_21 ( struct V_1 * V_21 )
{
int V_15 ;
int V_22 ;
if ( ! V_21 )
return - V_24 ;
V_21 -> V_27 . V_15 = V_23 ;
V_22 = F_9 ( V_21 , & V_15 ) ;
if ( V_22 )
return V_22 ;
if ( V_15 < V_20 && V_21 -> V_27 . V_9 . V_31 ) {
V_22 = F_22 ( V_21 , V_15 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_13 ( V_21 , V_15 ) ;
if ( V_22 )
return V_22 ;
} else if ( V_15 == V_23 ) {
V_15 = V_16 ;
V_22 = F_13 ( V_21 , V_15 ) ;
if ( V_22 )
return V_22 ;
}
V_21 -> V_27 . V_15 = V_15 ;
return 0 ;
}
int F_23 ( T_3 V_12 , int * V_44 )
{
struct V_1 * V_21 ;
int V_15 ;
int V_22 ;
V_22 = F_19 ( V_12 , & V_21 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_9 ( V_21 , & V_15 ) ;
if ( V_22 )
return V_22 ;
if ( V_15 == V_23 )
V_15 = V_16 ;
V_22 = F_15 ( V_21 , V_15 ) ;
if ( ! V_22 && V_44 )
* V_44 = V_15 ;
return V_22 ;
}
bool F_24 ( T_3 V_12 )
{
struct V_1 * V_21 ;
int V_22 ;
V_22 = F_19 ( V_12 , & V_21 ) ;
return V_22 ? false : V_21 -> V_9 . V_25 ;
}
bool F_25 ( T_3 V_12 )
{
struct V_1 * V_21 ;
int V_22 ;
V_22 = F_19 ( V_12 , & V_21 ) ;
return V_22 ? false : V_21 -> V_8 . V_9 . V_40 ;
}
int F_26 ( struct V_21 * V_43 , struct V_1 * V_2 ,
T_4 V_45 , int V_46 , int * V_47 )
{
char V_48 [] = L_17 ;
unsigned long long V_49 , V_50 ;
bool V_8 = false ;
if ( V_46 < V_16 || V_46 > V_32 )
return - V_24 ;
if ( V_46 > V_19 ) {
enum V_51 V_52 ;
V_52 = F_27 ( V_43 , V_53 ) ;
if ( V_52 == V_54 )
V_46 = V_19 ;
}
V_48 [ 2 ] = '0' + V_45 ;
V_49 = V_16 ;
V_50 = V_32 ;
if ( V_45 > V_55 ) {
F_10 ( V_2 -> V_12 , V_48 , NULL , & V_49 ) ;
V_8 = F_28 ( V_43 ) && V_2 -> V_8 . V_9 . V_40
&& V_2 -> V_8 . V_56 >= V_45 ;
} else if ( F_27 ( V_43 , V_57 ) !=
V_58 ) {
V_8 = V_2 -> V_8 . V_9 . V_40 ;
}
if ( V_8 ) {
T_1 V_5 ;
V_48 [ 3 ] = 'W' ;
V_5 = F_10 ( V_2 -> V_12 , V_48 , NULL ,
& V_50 ) ;
if ( F_4 ( V_5 ) ) {
if ( V_45 != V_55 ||
V_5 != V_59 )
V_50 = V_49 ;
} else if ( V_50 < V_49 ) {
F_16 ( V_60 L_18 ,
V_48 ) ;
V_49 = V_50 ;
}
}
if ( V_46 < V_49 )
return - V_24 ;
if ( V_47 )
* V_47 = V_49 ;
if ( V_50 > V_46 ) {
for ( V_50 = V_46 ; V_50 > V_49 ; V_50 -- ) {
if ( V_2 -> V_27 . V_36 [ V_50 ] . V_9 . V_40 )
break;
}
}
return V_50 ;
}
int F_29 ( struct V_21 * V_43 , int * V_47 , int V_46 )
{
T_3 V_12 = F_30 ( V_43 ) ;
struct V_1 * V_2 ;
if ( ! V_12 || F_19 ( V_12 , & V_2 ) ) {
F_31 ( V_43 , L_19 , V_61 ) ;
return - V_30 ;
}
return F_26 ( V_43 , V_2 , F_32 () ,
V_46 , V_47 ) ;
}
static void F_33 ( T_3 V_12 , T_4 V_62 , void * V_4 )
{
struct V_21 * V_43 = V_4 ;
if ( V_62 == V_63 && V_43 ) {
F_34 ( V_43 , 0 ) ;
F_35 ( V_43 ) ;
}
}
int F_36 ( struct V_1 * V_2 , bool V_64 )
{
struct V_65 * V_8 = & V_2 -> V_8 ;
if ( V_64 ) {
T_1 V_66 ;
int error ;
error = F_37 ( V_2 , V_55 ) ;
if ( error )
return error ;
V_66 = F_38 ( V_8 -> V_67 , V_8 -> V_68 ) ;
if ( F_4 ( V_66 ) ) {
F_39 ( V_2 ) ;
return - V_69 ;
}
} else {
F_40 ( V_8 -> V_67 , V_8 -> V_68 ) ;
F_39 ( V_2 ) ;
}
return 0 ;
}
int F_41 ( struct V_21 * V_70 , bool V_64 )
{
struct V_1 * V_2 ;
T_3 V_12 ;
if ( ! F_42 ( V_70 ) )
return - V_24 ;
V_12 = F_30 ( V_70 ) ;
if ( ! V_12 || F_19 ( V_12 , & V_2 ) ) {
F_31 ( V_70 , L_19 ,
V_61 ) ;
return - V_30 ;
}
return F_36 ( V_2 , V_64 ) ;
}
static inline void F_33 ( T_3 V_12 , T_4 V_62 ,
void * V_4 ) {}
int F_43 ( struct V_1 * V_2 , T_4 V_45 ,
bool V_64 )
{
return V_64 ?
F_37 ( V_2 , V_45 ) :
F_39 ( V_2 ) ;
}
int F_44 ( struct V_21 * V_43 , bool V_64 )
{
T_3 V_12 ;
struct V_1 * V_2 ;
int error ;
if ( ! F_45 ( V_43 ) )
return - V_24 ;
V_12 = F_30 ( V_43 ) ;
if ( ! V_12 || F_19 ( V_12 , & V_2 ) ) {
F_31 ( V_43 , L_19 , V_61 ) ;
return - V_30 ;
}
error = F_43 ( V_2 , F_32 () ,
V_64 ) ;
if ( ! error )
F_46 ( V_43 , L_20 ,
V_64 ? L_21 : L_22 ) ;
return error ;
}
struct V_1 * F_47 ( struct V_21 * V_43 )
{
T_3 V_12 = F_30 ( V_43 ) ;
struct V_1 * V_2 ;
return V_12 && ! F_19 ( V_12 , & V_2 ) ? V_2 : NULL ;
}
static int F_48 ( struct V_21 * V_43 , struct V_1 * V_2 ,
T_4 V_71 )
{
int V_72 ;
if ( ! F_49 ( V_2 ) )
return 0 ;
V_72 = F_26 ( V_43 , V_2 , V_71 ,
V_32 , NULL ) ;
if ( V_72 < V_16 || V_72 > V_32 )
return - V_69 ;
return F_15 ( V_2 , V_72 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
return F_49 ( V_2 ) ?
F_15 ( V_2 , V_16 ) : 0 ;
}
int F_51 ( struct V_21 * V_43 )
{
struct V_1 * V_2 = F_47 ( V_43 ) ;
bool V_73 ;
int error ;
if ( ! V_2 )
return 0 ;
V_73 = F_27 ( V_43 , V_57 ) >
V_58 ;
error = F_36 ( V_2 , V_73 ) ;
if ( V_73 && error )
return - V_74 ;
error = F_48 ( V_43 , V_2 , V_55 ) ;
if ( error )
F_36 ( V_2 , false ) ;
return error ;
}
int F_52 ( struct V_21 * V_43 )
{
struct V_1 * V_2 = F_47 ( V_43 ) ;
int error ;
if ( ! V_2 )
return 0 ;
error = F_50 ( V_2 ) ;
F_36 ( V_2 , false ) ;
return error ;
}
int F_53 ( struct V_21 * V_43 )
{
int V_75 = F_54 ( V_43 ) ;
return V_75 ? V_75 : F_51 ( V_43 ) ;
}
int F_55 ( struct V_21 * V_43 )
{
int V_75 = F_52 ( V_43 ) ;
return V_75 ? V_75 : F_56 ( V_43 ) ;
}
int F_57 ( struct V_21 * V_43 )
{
struct V_1 * V_2 = F_47 ( V_43 ) ;
T_4 V_45 ;
bool V_8 ;
int error ;
if ( ! V_2 )
return 0 ;
V_45 = F_32 () ;
V_8 = F_28 ( V_43 ) ;
error = F_43 ( V_2 , V_45 , V_8 ) ;
if ( V_8 && error )
return error ;
error = F_48 ( V_43 , V_2 , V_45 ) ;
if ( error )
F_43 ( V_2 , V_23 , false ) ;
return error ;
}
int F_58 ( struct V_21 * V_43 )
{
struct V_1 * V_2 = F_47 ( V_43 ) ;
int error ;
if ( ! V_2 )
return 0 ;
error = F_50 ( V_2 ) ;
F_43 ( V_2 , V_23 , false ) ;
return error ;
}
int F_59 ( struct V_21 * V_43 )
{
F_35 ( V_43 ) ;
return F_60 ( V_43 ) ;
}
int F_61 ( struct V_21 * V_43 )
{
int V_75 = F_62 ( V_43 ) ;
return V_75 ? V_75 : F_57 ( V_43 ) ;
}
int F_63 ( struct V_21 * V_43 )
{
int V_75 = F_58 ( V_43 ) ;
return V_75 ? V_75 : F_64 ( V_43 ) ;
}
int F_65 ( struct V_21 * V_43 , bool V_76 )
{
struct V_1 * V_2 = F_47 ( V_43 ) ;
if ( ! V_2 )
return - V_30 ;
if ( V_43 -> V_77 )
return - V_78 ;
F_1 ( V_2 , F_33 , V_43 ) ;
V_43 -> V_77 = & V_79 ;
if ( V_76 ) {
F_50 ( V_2 ) ;
F_36 ( V_2 , false ) ;
}
return 0 ;
}
void F_66 ( struct V_21 * V_43 , bool V_80 )
{
struct V_1 * V_2 = F_47 ( V_43 ) ;
if ( V_2 && V_43 -> V_77 == & V_79 ) {
V_43 -> V_77 = NULL ;
F_6 ( V_2 , F_33 ) ;
if ( V_80 ) {
F_67 ( V_43 ) ;
F_68 ( V_43 ) ;
F_36 ( V_2 , false ) ;
F_48 ( V_43 , V_2 , V_55 ) ;
}
}
}
void F_69 ( T_3 V_12 , struct V_21 * V_81 )
{
struct V_82 * V_83 ;
struct V_1 * V_2 ;
if ( ! V_81 || F_19 ( V_12 , & V_2 ) )
return;
F_2 ( & V_2 -> V_84 ) ;
F_70 (dep, &adev->power_dependent, node)
if ( V_83 -> V_43 == V_81 )
goto V_11;
V_83 = F_71 ( sizeof( * V_83 ) , V_85 ) ;
if ( V_83 ) {
V_83 -> V_43 = V_81 ;
F_72 ( & V_83 -> V_86 , & V_2 -> V_87 ) ;
}
V_11:
F_5 ( & V_2 -> V_84 ) ;
}
void F_73 ( T_3 V_12 , struct V_21 * V_81 )
{
struct V_82 * V_83 ;
struct V_1 * V_2 ;
if ( ! V_81 || F_19 ( V_12 , & V_2 ) )
return;
F_2 ( & V_2 -> V_84 ) ;
F_70 (dep, &adev->power_dependent, node)
if ( V_83 -> V_43 == V_81 ) {
F_74 ( & V_83 -> V_86 ) ;
F_75 ( V_83 ) ;
break;
}
F_5 ( & V_2 -> V_84 ) ;
}
