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
F_25 ( V_19 , L_15 ) ;
V_27 = F_26 ( V_19 ) ;
if ( ! V_27 )
return;
F_27 ( & V_42 ) ;
if ( V_27 -> V_43 . V_12 . V_44 ) {
F_28 ( V_27 -> V_43 . V_45 , 0 , F_23 () ) ;
if ( V_27 -> V_43 . V_46 . V_47 ) {
F_25 ( V_19 , L_16 ,
V_27 -> V_43 . V_46 . V_47 ,
F_29 ( V_27 -> V_43 . V_46 . V_33 ) ) ;
V_27 -> V_43 . V_46 . V_47 ( & V_27 -> V_43 . V_46 ) ;
}
}
F_30 ( & V_42 ) ;
F_31 ( V_27 ) ;
}
T_2 F_32 ( struct V_7 * V_27 , struct V_8 * V_33 ,
void (* V_47)( struct V_48 * V_46 ) )
{
T_2 V_21 = V_49 ;
if ( ! V_33 && ! V_47 )
return V_50 ;
F_27 ( & V_42 ) ;
if ( V_27 -> V_43 . V_12 . V_44 )
goto V_16;
V_27 -> V_43 . V_45 = F_33 ( F_29 ( & V_27 -> V_33 ) ) ;
V_27 -> V_43 . V_46 . V_33 = V_33 ;
V_27 -> V_43 . V_46 . V_47 = V_47 ;
V_21 = F_34 ( V_27 -> V_19 , V_51 ,
F_24 , NULL ) ;
if ( F_5 ( V_21 ) )
goto V_16;
V_27 -> V_43 . V_12 . V_44 = true ;
V_16:
F_30 ( & V_42 ) ;
return V_21 ;
}
T_2 F_35 ( struct V_7 * V_27 )
{
T_2 V_21 = V_50 ;
F_27 ( & V_42 ) ;
if ( ! V_27 -> V_43 . V_12 . V_44 )
goto V_16;
V_21 = F_36 ( V_27 -> V_19 ,
V_51 ,
F_24 ) ;
if ( F_5 ( V_21 ) )
goto V_16;
V_27 -> V_43 . V_46 . V_47 = NULL ;
V_27 -> V_43 . V_46 . V_33 = NULL ;
F_37 ( V_27 -> V_43 . V_45 ) ;
V_27 -> V_43 . V_12 . V_44 = false ;
V_16:
F_30 ( & V_42 ) ;
return V_21 ;
}
bool F_38 ( T_1 V_19 )
{
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_13 ( V_19 , & V_8 ) ;
return V_9 ? false : V_8 -> V_43 . V_12 . V_32 ;
}
bool F_39 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_40 ( V_33 ) ;
return V_27 ? F_41 ( V_27 ) : false ;
}
static int F_42 ( struct V_8 * V_33 , struct V_7 * V_27 ,
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
V_43 = F_43 ( V_33 ) && V_27 -> V_43 . V_12 . V_32
&& V_27 -> V_43 . V_59 >= V_31 ;
} else if ( F_44 ( V_33 , V_60 ) !=
V_61 ) {
V_43 = V_27 -> V_43 . V_12 . V_32 ;
}
if ( V_43 ) {
V_30 [ 3 ] = 'W' ;
V_21 = F_4 ( V_19 , V_30 , NULL , & V_37 ) ;
if ( V_21 == V_57 ) {
if ( V_31 > V_56 )
V_55 = V_54 ;
} else if ( F_45 ( V_21 ) && V_37 <= V_6 ) {
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
int F_46 ( struct V_8 * V_33 , int * V_52 , int V_62 )
{
struct V_7 * V_27 ;
int V_37 , V_54 , V_55 ;
if ( V_62 < V_2 || V_62 > V_6 )
return - V_11 ;
if ( V_62 > V_4 ) {
enum V_63 V_64 ;
V_64 = F_44 ( V_33 , V_65 ) ;
if ( V_64 == V_66 )
V_62 = V_4 ;
}
V_27 = F_40 ( V_33 ) ;
if ( ! V_27 ) {
F_47 ( V_33 , L_17 , V_67 ) ;
return - V_22 ;
}
V_37 = F_42 ( V_33 , V_27 , F_48 () ,
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
static void F_49 ( struct V_48 * V_46 )
{
struct V_8 * V_33 = V_46 -> V_33 ;
if ( V_33 ) {
F_50 ( V_33 , 0 ) ;
F_51 ( V_33 ) ;
}
}
static int F_52 ( struct V_7 * V_27 ,
T_3 V_31 , int V_68 )
{
struct V_69 * V_43 = & V_27 -> V_43 ;
T_2 V_21 ;
int error = 0 ;
F_27 ( & V_70 ) ;
if ( V_43 -> V_71 >= V_68 )
goto V_16;
if ( V_43 -> V_71 > 0 )
goto V_72;
error = F_53 ( V_27 , V_31 ) ;
if ( error )
goto V_16;
V_21 = F_54 ( V_43 -> V_73 , V_43 -> V_74 ) ;
if ( F_5 ( V_21 ) ) {
F_55 ( V_27 ) ;
error = - V_75 ;
goto V_16;
}
V_72:
V_43 -> V_71 ++ ;
V_16:
F_30 ( & V_70 ) ;
return error ;
}
static int F_56 ( struct V_7 * V_27 , T_3 V_31 )
{
return F_52 ( V_27 , V_31 , 1 ) ;
}
static void F_57 ( struct V_7 * V_27 )
{
struct V_69 * V_43 = & V_27 -> V_43 ;
F_27 ( & V_70 ) ;
if ( ! V_43 -> V_71 )
goto V_16;
F_58 ( V_43 -> V_73 , V_43 -> V_74 ) ;
F_55 ( V_27 ) ;
V_43 -> V_71 -- ;
V_16:
F_30 ( & V_70 ) ;
}
static int F_59 ( struct V_8 * V_33 , bool V_76 ,
int V_68 )
{
struct V_7 * V_27 ;
int error ;
V_27 = F_40 ( V_33 ) ;
if ( ! V_27 ) {
F_47 ( V_33 , L_17 , V_67 ) ;
return - V_22 ;
}
if ( ! F_41 ( V_27 ) )
return - V_11 ;
if ( ! V_76 ) {
F_57 ( V_27 ) ;
F_47 ( V_33 , L_18 ) ;
return 0 ;
}
error = F_52 ( V_27 , F_48 () ,
V_68 ) ;
if ( ! error )
F_47 ( V_33 , L_19 ) ;
return error ;
}
int F_60 ( struct V_8 * V_33 , bool V_76 )
{
return F_59 ( V_33 , V_76 , 1 ) ;
}
int F_61 ( struct V_8 * V_33 , bool V_76 )
{
return F_59 ( V_33 , V_76 , V_77 ) ;
}
static int F_62 ( struct V_8 * V_33 , struct V_7 * V_27 ,
T_3 V_78 )
{
int V_37 , V_1 ;
if ( ! F_63 ( V_27 ) )
return 0 ;
V_37 = F_42 ( V_33 , V_27 , V_78 , NULL , & V_1 ) ;
return V_37 ? V_37 : F_9 ( V_27 , V_1 ) ;
}
static int F_64 ( struct V_7 * V_27 )
{
return F_63 ( V_27 ) ?
F_9 ( V_27 , V_2 ) : 0 ;
}
int F_65 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_40 ( V_33 ) ;
bool V_79 ;
int error ;
if ( ! V_27 )
return 0 ;
V_79 = F_44 ( V_33 , V_60 ) >
V_61 ;
if ( V_79 ) {
error = F_56 ( V_27 , V_56 ) ;
if ( error )
return - V_80 ;
}
error = F_62 ( V_33 , V_27 , V_56 ) ;
if ( error && V_79 )
F_57 ( V_27 ) ;
return error ;
}
int F_66 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_40 ( V_33 ) ;
int error ;
if ( ! V_27 )
return 0 ;
error = F_64 ( V_27 ) ;
F_57 ( V_27 ) ;
return error ;
}
int F_67 ( struct V_8 * V_33 )
{
int V_37 = F_68 ( V_33 ) ;
return V_37 ? V_37 : F_65 ( V_33 ) ;
}
int F_69 ( struct V_8 * V_33 )
{
int V_37 = F_66 ( V_33 ) ;
return V_37 ? V_37 : F_70 ( V_33 ) ;
}
int F_71 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_40 ( V_33 ) ;
T_3 V_31 ;
bool V_43 ;
int error ;
if ( ! V_27 )
return 0 ;
V_31 = F_48 () ;
V_43 = F_43 ( V_33 ) && F_41 ( V_27 ) ;
if ( V_43 ) {
error = F_56 ( V_27 , V_31 ) ;
if ( error )
return error ;
}
error = F_62 ( V_33 , V_27 , V_31 ) ;
if ( error && V_43 )
F_57 ( V_27 ) ;
return error ;
}
int F_72 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_40 ( V_33 ) ;
int error ;
if ( ! V_27 )
return 0 ;
error = F_64 ( V_27 ) ;
F_57 ( V_27 ) ;
return error ;
}
int F_73 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_40 ( V_33 ) ;
T_3 V_81 ;
int V_37 , V_1 ;
V_37 = F_74 ( V_33 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( ! V_27 || ! F_75 ( V_33 )
|| F_43 ( V_33 ) != ! ! V_27 -> V_43 . V_82 )
return 0 ;
V_81 = F_48 () ;
if ( V_81 == V_56 )
return 1 ;
if ( V_27 -> V_15 . V_12 . V_83 )
return 0 ;
V_37 = F_42 ( V_33 , V_27 , V_81 , NULL , & V_1 ) ;
return ! V_37 && V_1 == V_27 -> V_15 . V_1 ;
}
int F_76 ( struct V_8 * V_33 )
{
F_77 ( V_33 ) ;
return F_78 ( V_33 ) ;
}
int F_79 ( struct V_8 * V_33 )
{
int V_37 = F_80 ( V_33 ) ;
return V_37 ? V_37 : F_71 ( V_33 ) ;
}
int F_81 ( struct V_8 * V_33 )
{
int V_37 = F_72 ( V_33 ) ;
return V_37 ? V_37 : F_82 ( V_33 ) ;
}
int F_83 ( struct V_8 * V_33 )
{
F_77 ( V_33 ) ;
return F_84 ( V_33 ) ;
}
static void F_85 ( struct V_8 * V_33 , bool V_84 )
{
struct V_7 * V_27 = F_40 ( V_33 ) ;
if ( V_27 && V_33 -> V_85 == & V_86 ) {
F_86 ( V_33 , NULL ) ;
F_35 ( V_27 ) ;
if ( V_84 ) {
F_87 ( V_33 ) ;
F_88 ( V_33 ) ;
F_57 ( V_27 ) ;
F_62 ( V_33 , V_27 , V_56 ) ;
}
}
}
int F_89 ( struct V_8 * V_33 , bool V_87 )
{
struct V_7 * V_27 = F_40 ( V_33 ) ;
if ( ! V_27 )
return - V_22 ;
if ( V_33 -> V_85 )
return - V_88 ;
if ( ! F_90 ( V_27 , V_33 ) )
return - V_89 ;
F_32 ( V_27 , V_33 , F_49 ) ;
F_86 ( V_33 , & V_86 ) ;
if ( V_87 ) {
F_64 ( V_27 ) ;
F_57 ( V_27 ) ;
}
V_33 -> V_85 -> V_90 = F_85 ;
return 0 ;
}
