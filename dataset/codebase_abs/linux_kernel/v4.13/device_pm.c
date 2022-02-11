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
V_9 = V_20 > V_4 ? V_5 : V_20 ;
}
if ( ! V_8 -> V_15 . V_12 . V_23 && V_8 -> V_14
&& V_8 -> V_14 -> V_15 . V_1 == V_10
&& V_9 == V_2 )
V_8 -> V_14 -> V_15 . V_1 = V_2 ;
* V_1 = V_9 ;
V_16:
F_6 ( ( V_24 , L_8 ,
V_8 -> V_25 . V_26 , F_1 ( * V_1 ) ) ) ;
return 0 ;
}
static int F_7 ( struct V_7 * V_27 , int V_1 )
{
if ( V_27 -> V_15 . V_28 [ V_1 ] . V_12 . V_29 ) {
char V_30 [ 5 ] = { '_' , 'P' , 'S' , '0' + V_1 , '\0' } ;
T_2 V_21 ;
V_21 = F_8 ( V_27 -> V_19 , V_30 , NULL , NULL ) ;
if ( F_5 ( V_21 ) )
return - V_22 ;
}
return 0 ;
}
int F_9 ( struct V_7 * V_8 , int V_1 )
{
int V_31 = V_1 ;
int V_9 = 0 ;
if ( ! V_8 || ! V_8 -> V_12 . V_13
|| ( V_1 < V_2 ) || ( V_1 > V_6 ) )
return - V_11 ;
if ( V_1 == V_8 -> V_15 . V_1 ) {
F_6 ( ( V_24 , L_9 ,
V_8 -> V_25 . V_26 ,
F_1 ( V_1 ) ) ) ;
return 0 ;
}
if ( V_1 == V_6 ) {
V_1 = V_5 ;
if ( ! V_8 -> V_15 . V_28 [ V_6 ] . V_12 . V_32 )
V_31 = V_1 ;
} else if ( ! V_8 -> V_15 . V_28 [ V_1 ] . V_12 . V_32 ) {
F_10 ( & V_8 -> V_33 , L_10 ,
F_1 ( V_1 ) ) ;
return - V_22 ;
}
if ( ! V_8 -> V_15 . V_12 . V_23 &&
V_8 -> V_14 && ( V_1 < V_8 -> V_14 -> V_15 . V_1 ) ) {
F_10 ( & V_8 -> V_33 ,
L_11 ,
F_1 ( V_1 ) ,
F_1 ( V_8 -> V_14 -> V_15 . V_1 ) ) ;
return - V_22 ;
}
if ( V_1 > V_2 ) {
if ( V_1 < V_8 -> V_15 . V_1 ) {
F_10 ( & V_8 -> V_33 , L_12 ,
F_1 ( V_8 -> V_15 . V_1 ) ,
F_1 ( V_1 ) ) ;
return - V_22 ;
}
V_9 = F_7 ( V_8 , V_1 ) ;
if ( V_9 )
goto V_34;
if ( V_8 -> V_15 . V_12 . V_17 )
V_9 = F_11 ( V_8 , V_31 ) ;
} else {
if ( V_8 -> V_15 . V_12 . V_17 ) {
V_9 = F_11 ( V_8 , V_2 ) ;
if ( V_9 )
goto V_34;
}
V_9 = F_7 ( V_8 , V_2 ) ;
}
V_34:
if ( V_9 ) {
F_10 ( & V_8 -> V_33 , L_13 ,
F_1 ( V_1 ) ) ;
} else {
V_8 -> V_15 . V_1 = V_31 ;
F_6 ( ( V_24 ,
L_14 ,
V_8 -> V_25 . V_26 ,
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
return F_9 ( V_8 , V_1 ) ;
}
int F_14 ( struct V_7 * V_8 )
{
int V_1 ;
int V_9 ;
if ( ! V_8 )
return - V_11 ;
V_8 -> V_15 . V_1 = V_10 ;
if ( ! F_15 ( V_8 ) ) {
V_8 -> V_12 . V_35 = false ;
return - V_36 ;
}
V_9 = F_2 ( V_8 , & V_1 ) ;
if ( V_9 )
return V_9 ;
if ( V_1 < V_6 && V_8 -> V_15 . V_12 . V_17 ) {
V_9 = F_16 ( V_8 , V_1 ) ;
if ( V_9 )
return V_9 ;
if ( V_1 == V_2 ) {
V_9 = F_7 ( V_8 , V_1 ) ;
if ( V_9 )
return V_9 ;
}
} else if ( V_1 == V_10 ) {
V_1 = V_2 ;
}
V_8 -> V_15 . V_1 = V_1 ;
return 0 ;
}
int F_17 ( struct V_7 * V_8 )
{
int V_37 = 0 ;
if ( ! V_8 -> V_15 . V_12 . V_17
&& ! V_8 -> V_15 . V_12 . V_18
&& V_8 -> V_15 . V_1 == V_2 )
V_37 = F_7 ( V_8 , V_2 ) ;
return V_37 ;
}
int F_18 ( struct V_7 * V_8 , int * V_38 )
{
int V_1 ;
int V_9 ;
if ( V_8 -> V_15 . V_1 == V_10 ) {
V_9 = F_14 ( V_8 ) ;
if ( ! V_9 && V_38 )
* V_38 = V_8 -> V_15 . V_1 ;
return V_9 ;
}
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
if ( V_38 )
* V_38 = V_1 ;
return 0 ;
}
int F_19 ( T_1 V_19 , int * V_38 )
{
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_13 ( V_19 , & V_8 ) ;
return V_9 ? V_9 : F_18 ( V_8 , V_38 ) ;
}
bool F_20 ( T_1 V_19 )
{
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_13 ( V_19 , & V_8 ) ;
return V_9 ? false : V_8 -> V_12 . V_13 ;
}
void F_21 ( struct V_8 * V_33 )
{
F_22 ( V_33 , 0 , F_23 () ) ;
}
static void F_24 ( T_1 V_19 , T_3 V_39 , void * V_40 )
{
struct V_7 * V_27 ;
if ( V_39 != V_41 )
return;
V_27 = F_25 ( V_19 ) ;
if ( ! V_27 )
return;
F_26 ( & V_42 ) ;
if ( V_27 -> V_43 . V_12 . V_44 ) {
F_27 ( V_27 -> V_43 . V_45 , 0 , F_23 () ) ;
if ( V_27 -> V_43 . V_46 . V_47 )
V_27 -> V_43 . V_46 . V_47 ( & V_27 -> V_43 . V_46 ) ;
}
F_28 ( & V_42 ) ;
F_29 ( V_27 ) ;
}
T_2 F_30 ( struct V_7 * V_27 , struct V_8 * V_33 ,
void (* V_47)( struct V_48 * V_46 ) )
{
T_2 V_21 = V_49 ;
if ( ! V_33 && ! V_47 )
return V_50 ;
F_26 ( & V_42 ) ;
if ( V_27 -> V_43 . V_12 . V_44 )
goto V_16;
V_27 -> V_43 . V_45 = F_31 ( F_32 ( & V_27 -> V_33 ) ) ;
V_27 -> V_43 . V_46 . V_33 = V_33 ;
V_27 -> V_43 . V_46 . V_47 = V_47 ;
V_21 = F_33 ( V_27 -> V_19 , V_51 ,
F_24 , NULL ) ;
if ( F_5 ( V_21 ) )
goto V_16;
V_27 -> V_43 . V_12 . V_44 = true ;
V_16:
F_28 ( & V_42 ) ;
return V_21 ;
}
T_2 F_34 ( struct V_7 * V_27 )
{
T_2 V_21 = V_50 ;
F_26 ( & V_42 ) ;
if ( ! V_27 -> V_43 . V_12 . V_44 )
goto V_16;
V_21 = F_35 ( V_27 -> V_19 ,
V_51 ,
F_24 ) ;
if ( F_5 ( V_21 ) )
goto V_16;
V_27 -> V_43 . V_46 . V_47 = NULL ;
V_27 -> V_43 . V_46 . V_33 = NULL ;
F_36 ( V_27 -> V_43 . V_45 ) ;
V_27 -> V_43 . V_12 . V_44 = false ;
V_16:
F_28 ( & V_42 ) ;
return V_21 ;
}
bool F_37 ( T_1 V_19 )
{
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_13 ( V_19 , & V_8 ) ;
return V_9 ? false : V_8 -> V_43 . V_12 . V_32 ;
}
bool F_38 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_39 ( V_33 ) ;
return V_27 ? F_40 ( V_27 ) : false ;
}
static int F_41 ( struct V_8 * V_33 , struct V_7 * V_27 ,
T_3 V_31 , int * V_52 , int * V_53 )
{
char V_30 [] = { '_' , 'S' , '0' + V_31 , 'D' , '\0' } ;
T_1 V_19 = V_27 -> V_19 ;
unsigned long long V_37 ;
int V_54 , V_55 ;
bool V_43 = false ;
T_2 V_21 ;
V_54 = V_2 ;
V_55 = V_6 ;
if ( V_31 > V_56 ) {
V_37 = V_54 ;
V_21 = F_4 ( V_19 , V_30 , NULL , & V_37 ) ;
if ( ( F_5 ( V_21 ) && V_21 != V_57 )
|| V_37 > V_6 )
return - V_58 ;
if ( ! V_27 -> V_15 . V_28 [ V_37 ] . V_12 . V_32 ) {
if ( V_37 == V_5 )
V_37 = V_6 ;
else
return - V_58 ;
}
V_54 = V_37 ;
V_43 = F_42 ( V_33 ) && V_27 -> V_43 . V_12 . V_32
&& V_27 -> V_43 . V_59 >= V_31 ;
} else if ( F_43 ( V_33 , V_60 ) !=
V_61 ) {
V_43 = V_27 -> V_43 . V_12 . V_32 ;
}
if ( V_43 ) {
V_30 [ 3 ] = 'W' ;
V_21 = F_4 ( V_19 , V_30 , NULL , & V_37 ) ;
if ( V_21 == V_57 ) {
if ( V_31 > V_56 )
V_55 = V_54 ;
} else if ( F_44 ( V_21 ) && V_37 <= V_6 ) {
if ( ! V_27 -> V_15 . V_28 [ V_37 ] . V_12 . V_32 )
V_37 = V_6 ;
V_55 = V_37 > V_54 ? V_37 : V_54 ;
} else {
return - V_58 ;
}
}
if ( V_52 )
* V_52 = V_54 ;
if ( V_53 )
* V_53 = V_55 ;
return 0 ;
}
int F_45 ( struct V_8 * V_33 , int * V_52 , int V_62 )
{
struct V_7 * V_27 ;
int V_37 , V_54 , V_55 ;
if ( V_62 < V_2 || V_62 > V_6 )
return - V_11 ;
if ( V_62 > V_4 ) {
enum V_63 V_64 ;
V_64 = F_43 ( V_33 , V_65 ) ;
if ( V_64 == V_66 )
V_62 = V_4 ;
}
V_27 = F_39 ( V_33 ) ;
if ( ! V_27 ) {
F_46 ( V_33 , L_15 , V_67 ) ;
return - V_22 ;
}
V_37 = F_41 ( V_33 , V_27 , F_47 () ,
& V_54 , & V_55 ) ;
if ( V_37 )
return V_37 ;
if ( V_62 < V_54 )
return - V_11 ;
if ( V_55 > V_62 ) {
for ( V_55 = V_62 ; V_55 > V_54 ; V_55 -- ) {
if ( V_27 -> V_15 . V_28 [ V_55 ] . V_12 . V_32 )
break;
}
}
if ( V_52 )
* V_52 = V_54 ;
return V_55 ;
}
static void F_48 ( struct V_48 * V_46 )
{
struct V_8 * V_33 = V_46 -> V_33 ;
if ( V_33 ) {
F_49 ( V_33 , 0 ) ;
F_50 ( V_33 ) ;
}
}
static int F_51 ( struct V_7 * V_27 , T_3 V_31 ,
bool V_68 )
{
struct F_51 * V_43 = & V_27 -> V_43 ;
if ( V_68 ) {
T_2 V_69 ;
int error ;
if ( V_27 -> V_43 . V_12 . V_70 )
return 0 ;
error = F_52 ( V_27 , V_31 ) ;
if ( error )
return error ;
V_69 = F_53 ( V_43 -> V_71 , V_43 -> V_72 ) ;
if ( F_5 ( V_69 ) ) {
F_54 ( V_27 ) ;
return - V_73 ;
}
V_27 -> V_43 . V_12 . V_70 = 1 ;
} else if ( V_27 -> V_43 . V_12 . V_70 ) {
F_55 ( V_43 -> V_71 , V_43 -> V_72 ) ;
F_54 ( V_27 ) ;
V_27 -> V_43 . V_12 . V_70 = 0 ;
}
return 0 ;
}
int F_56 ( struct V_8 * V_33 , bool V_68 )
{
struct V_7 * V_27 ;
int error ;
V_27 = F_39 ( V_33 ) ;
if ( ! V_27 ) {
F_46 ( V_33 , L_15 , V_67 ) ;
return - V_22 ;
}
if ( ! F_40 ( V_27 ) )
return - V_11 ;
error = F_51 ( V_27 , F_47 () , V_68 ) ;
if ( ! error )
F_46 ( V_33 , L_16 , V_68 ? L_17 : L_18 ) ;
return error ;
}
static int F_57 ( struct V_8 * V_33 , struct V_7 * V_27 ,
T_3 V_74 )
{
int V_37 , V_1 ;
if ( ! F_58 ( V_27 ) )
return 0 ;
V_37 = F_41 ( V_33 , V_27 , V_74 , NULL , & V_1 ) ;
return V_37 ? V_37 : F_9 ( V_27 , V_1 ) ;
}
static int F_59 ( struct V_7 * V_27 )
{
return F_58 ( V_27 ) ?
F_9 ( V_27 , V_2 ) : 0 ;
}
int F_60 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_39 ( V_33 ) ;
bool V_75 ;
int error ;
if ( ! V_27 )
return 0 ;
V_75 = F_43 ( V_33 , V_60 ) >
V_61 ;
error = F_51 ( V_27 , V_56 , V_75 ) ;
if ( V_75 && error )
return - V_76 ;
error = F_57 ( V_33 , V_27 , V_56 ) ;
if ( error )
F_51 ( V_27 , V_56 , false ) ;
return error ;
}
int F_61 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_39 ( V_33 ) ;
int error ;
if ( ! V_27 )
return 0 ;
error = F_59 ( V_27 ) ;
F_51 ( V_27 , V_56 , false ) ;
return error ;
}
int F_62 ( struct V_8 * V_33 )
{
int V_37 = F_63 ( V_33 ) ;
return V_37 ? V_37 : F_60 ( V_33 ) ;
}
int F_64 ( struct V_8 * V_33 )
{
int V_37 = F_61 ( V_33 ) ;
return V_37 ? V_37 : F_65 ( V_33 ) ;
}
int F_66 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_39 ( V_33 ) ;
T_3 V_31 ;
bool V_43 ;
int error ;
if ( ! V_27 )
return 0 ;
V_31 = F_47 () ;
V_43 = F_42 ( V_33 ) && F_40 ( V_27 ) ;
error = F_51 ( V_27 , V_31 , V_43 ) ;
if ( V_43 && error )
return error ;
error = F_57 ( V_33 , V_27 , V_31 ) ;
if ( error )
F_51 ( V_27 , V_10 , false ) ;
return error ;
}
int F_67 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_39 ( V_33 ) ;
int error ;
if ( ! V_27 )
return 0 ;
error = F_59 ( V_27 ) ;
F_51 ( V_27 , V_10 , false ) ;
return error ;
}
int F_68 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_39 ( V_33 ) ;
T_3 V_77 ;
int V_37 , V_1 ;
V_37 = F_69 ( V_33 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( ! V_27 || ! F_70 ( V_33 )
|| F_42 ( V_33 ) != ! ! V_27 -> V_43 . V_78 )
return 0 ;
V_77 = F_47 () ;
if ( V_77 == V_56 )
return 1 ;
if ( V_27 -> V_15 . V_12 . V_79 )
return 0 ;
V_37 = F_41 ( V_33 , V_27 , V_77 , NULL , & V_1 ) ;
return ! V_37 && V_1 == V_27 -> V_15 . V_1 ;
}
int F_71 ( struct V_8 * V_33 )
{
F_72 ( V_33 ) ;
return F_73 ( V_33 ) ;
}
int F_74 ( struct V_8 * V_33 )
{
int V_37 = F_75 ( V_33 ) ;
return V_37 ? V_37 : F_66 ( V_33 ) ;
}
int F_76 ( struct V_8 * V_33 )
{
int V_37 = F_67 ( V_33 ) ;
return V_37 ? V_37 : F_77 ( V_33 ) ;
}
int F_78 ( struct V_8 * V_33 )
{
F_72 ( V_33 ) ;
return F_79 ( V_33 ) ;
}
static void F_80 ( struct V_8 * V_33 , bool V_80 )
{
struct V_7 * V_27 = F_39 ( V_33 ) ;
if ( V_27 && V_33 -> V_81 == & V_82 ) {
F_81 ( V_33 , NULL ) ;
F_34 ( V_27 ) ;
if ( V_80 ) {
F_82 ( V_33 ) ;
F_83 ( V_33 ) ;
F_51 ( V_27 , V_56 , false ) ;
F_57 ( V_33 , V_27 , V_56 ) ;
}
}
}
int F_84 ( struct V_8 * V_33 , bool V_83 )
{
struct V_7 * V_27 = F_39 ( V_33 ) ;
if ( ! V_27 )
return - V_22 ;
if ( V_33 -> V_81 )
return - V_84 ;
if ( ! F_85 ( V_27 , V_33 ) )
return - V_85 ;
F_30 ( V_27 , V_33 , F_48 ) ;
F_81 ( V_33 , & V_82 ) ;
if ( V_83 ) {
F_59 ( V_27 ) ;
F_51 ( V_27 , V_56 , false ) ;
}
V_33 -> V_81 -> V_86 = F_80 ;
return 0 ;
}
