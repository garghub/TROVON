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
if ( ! F_15 ( V_8 ) )
return - V_35 ;
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
int V_36 = 0 ;
if ( ! V_8 -> V_15 . V_12 . V_17
&& ! V_8 -> V_15 . V_12 . V_18
&& V_8 -> V_15 . V_1 == V_2 )
V_36 = F_7 ( V_8 , V_2 ) ;
return V_36 ;
}
int F_18 ( struct V_7 * V_8 , int * V_37 )
{
int V_1 ;
int V_9 ;
if ( V_8 -> V_15 . V_1 == V_10 ) {
V_9 = F_14 ( V_8 ) ;
if ( ! V_9 && V_37 )
* V_37 = V_8 -> V_15 . V_1 ;
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
if ( V_37 )
* V_37 = V_1 ;
return 0 ;
}
int F_19 ( T_1 V_19 , int * V_37 )
{
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_13 ( V_19 , & V_8 ) ;
return V_9 ? V_9 : F_18 ( V_8 , V_37 ) ;
}
bool F_20 ( T_1 V_19 )
{
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_13 ( V_19 , & V_8 ) ;
return V_9 ? false : V_8 -> V_12 . V_13 ;
}
static void F_21 ( T_1 V_19 , T_3 V_38 , void * V_39 )
{
struct V_7 * V_27 ;
if ( V_38 != V_40 )
return;
V_27 = F_22 ( V_19 ) ;
if ( ! V_27 )
return;
F_23 ( & V_41 ) ;
if ( V_27 -> V_42 . V_12 . V_43 ) {
F_24 ( V_27 -> V_42 . V_44 , 0 ) ;
if ( V_27 -> V_42 . V_45 . V_46 . V_47 )
F_25 ( & V_27 -> V_42 . V_45 . V_46 ) ;
}
F_26 ( & V_41 ) ;
F_27 ( V_27 ) ;
}
T_2 F_28 ( struct V_7 * V_27 , struct V_8 * V_33 ,
void (* F_29)( struct V_48 * V_46 ) )
{
T_2 V_21 = V_49 ;
if ( ! V_33 && ! F_29 )
return V_50 ;
F_23 ( & V_41 ) ;
if ( V_27 -> V_42 . V_12 . V_43 )
goto V_16;
V_27 -> V_42 . V_44 = F_30 ( F_31 ( & V_27 -> V_33 ) ) ;
V_27 -> V_42 . V_45 . V_33 = V_33 ;
if ( F_29 )
F_32 ( & V_27 -> V_42 . V_45 . V_46 , F_29 ) ;
V_21 = F_33 ( V_27 -> V_19 , V_51 ,
F_21 , NULL ) ;
if ( F_5 ( V_21 ) )
goto V_16;
V_27 -> V_42 . V_12 . V_43 = true ;
V_16:
F_26 ( & V_41 ) ;
return V_21 ;
}
T_2 F_34 ( struct V_7 * V_27 )
{
T_2 V_21 = V_50 ;
F_23 ( & V_41 ) ;
if ( ! V_27 -> V_42 . V_12 . V_43 )
goto V_16;
V_21 = F_35 ( V_27 -> V_19 ,
V_51 ,
F_21 ) ;
if ( F_5 ( V_21 ) )
goto V_16;
if ( V_27 -> V_42 . V_45 . V_46 . V_47 ) {
F_36 ( & V_27 -> V_42 . V_45 . V_46 ) ;
V_27 -> V_42 . V_45 . V_46 . V_47 = NULL ;
}
V_27 -> V_42 . V_45 . V_33 = NULL ;
F_37 ( V_27 -> V_42 . V_44 ) ;
V_27 -> V_42 . V_12 . V_43 = false ;
V_16:
F_26 ( & V_41 ) ;
return V_21 ;
}
bool F_38 ( T_1 V_19 )
{
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_13 ( V_19 , & V_8 ) ;
return V_9 ? false : V_8 -> V_42 . V_12 . V_32 ;
}
static int F_39 ( struct V_8 * V_33 , struct V_7 * V_27 ,
T_3 V_31 , int * V_52 , int * V_53 )
{
char V_30 [] = { '_' , 'S' , '0' + V_31 , 'D' , '\0' } ;
T_1 V_19 = V_27 -> V_19 ;
unsigned long long V_36 ;
int V_54 , V_55 ;
bool V_42 = false ;
T_2 V_21 ;
V_54 = V_2 ;
V_55 = V_6 ;
if ( V_31 > V_56 ) {
V_36 = V_54 ;
V_21 = F_4 ( V_19 , V_30 , NULL , & V_36 ) ;
if ( ( F_5 ( V_21 ) && V_21 != V_57 )
|| V_36 > V_6 )
return - V_58 ;
if ( ! V_27 -> V_15 . V_28 [ V_36 ] . V_12 . V_32 ) {
if ( V_36 == V_5 )
V_36 = V_6 ;
else
return - V_58 ;
}
V_54 = V_36 ;
V_42 = F_40 ( V_33 ) && V_27 -> V_42 . V_12 . V_32
&& V_27 -> V_42 . V_59 >= V_31 ;
} else if ( F_41 ( V_33 , V_60 ) !=
V_61 ) {
V_42 = V_27 -> V_42 . V_12 . V_32 ;
}
if ( V_42 ) {
V_30 [ 3 ] = 'W' ;
V_21 = F_4 ( V_19 , V_30 , NULL , & V_36 ) ;
if ( V_21 == V_57 ) {
if ( V_31 > V_56 )
V_55 = V_54 ;
} else if ( F_42 ( V_21 ) && V_36 <= V_6 ) {
if ( ! V_27 -> V_15 . V_28 [ V_36 ] . V_12 . V_32 )
V_36 = V_6 ;
V_55 = V_36 > V_54 ? V_36 : V_54 ;
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
int F_43 ( struct V_8 * V_33 , int * V_52 , int V_62 )
{
struct V_7 * V_27 ;
int V_36 , V_54 , V_55 ;
if ( V_62 < V_2 || V_62 > V_6 )
return - V_11 ;
if ( V_62 > V_4 ) {
enum V_63 V_64 ;
V_64 = F_41 ( V_33 , V_65 ) ;
if ( V_64 == V_66 )
V_62 = V_4 ;
}
V_27 = F_44 ( V_33 ) ;
if ( ! V_27 ) {
F_45 ( V_33 , L_15 , V_67 ) ;
return - V_22 ;
}
V_36 = F_39 ( V_33 , V_27 , F_46 () ,
& V_54 , & V_55 ) ;
if ( V_36 )
return V_36 ;
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
static void F_47 ( struct V_48 * V_46 )
{
struct V_8 * V_33 ;
V_33 = F_48 ( V_46 , struct V_68 , V_46 ) -> V_33 ;
if ( V_33 ) {
F_49 ( V_33 , 0 ) ;
F_50 ( V_33 ) ;
}
}
static int F_51 ( struct V_7 * V_27 , T_3 V_31 ,
bool V_69 )
{
struct F_51 * V_42 = & V_27 -> V_42 ;
if ( V_69 ) {
T_2 V_70 ;
int error ;
error = F_52 ( V_27 , V_31 ) ;
if ( error )
return error ;
if ( V_27 -> V_42 . V_12 . V_71 )
return 0 ;
V_70 = F_53 ( V_42 -> V_72 , V_42 -> V_73 ) ;
if ( F_42 ( V_70 ) ) {
V_27 -> V_42 . V_12 . V_71 = 1 ;
} else {
F_54 ( V_27 ) ;
return - V_74 ;
}
} else {
if ( V_27 -> V_42 . V_12 . V_71 ) {
F_55 ( V_42 -> V_72 , V_42 -> V_73 ) ;
V_27 -> V_42 . V_12 . V_71 = 0 ;
}
F_54 ( V_27 ) ;
}
return 0 ;
}
int F_56 ( struct V_8 * V_75 , bool V_69 )
{
struct V_7 * V_27 ;
if ( ! F_57 ( V_75 ) )
return - V_11 ;
V_27 = F_44 ( V_75 ) ;
if ( ! V_27 ) {
F_45 ( V_75 , L_15 , V_67 ) ;
return - V_22 ;
}
return F_51 ( V_27 , V_56 , V_69 ) ;
}
int F_58 ( struct V_8 * V_33 , bool V_69 )
{
struct V_7 * V_27 ;
int error ;
if ( ! F_59 ( V_33 ) )
return - V_11 ;
V_27 = F_44 ( V_33 ) ;
if ( ! V_27 ) {
F_45 ( V_33 , L_15 , V_67 ) ;
return - V_22 ;
}
error = F_51 ( V_27 , F_46 () , V_69 ) ;
if ( ! error )
F_60 ( V_33 , L_16 ,
V_69 ? L_17 : L_18 ) ;
return error ;
}
static int F_61 ( struct V_8 * V_33 , struct V_7 * V_27 ,
T_3 V_76 )
{
int V_36 , V_1 ;
if ( ! F_62 ( V_27 ) )
return 0 ;
V_36 = F_39 ( V_33 , V_27 , V_76 , NULL , & V_1 ) ;
return V_36 ? V_36 : F_9 ( V_27 , V_1 ) ;
}
static int F_63 ( struct V_7 * V_27 )
{
return F_62 ( V_27 ) ?
F_9 ( V_27 , V_2 ) : 0 ;
}
int F_64 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_44 ( V_33 ) ;
bool V_77 ;
int error ;
if ( ! V_27 )
return 0 ;
V_77 = F_41 ( V_33 , V_60 ) >
V_61 ;
error = F_51 ( V_27 , V_56 , V_77 ) ;
if ( V_77 && error )
return - V_78 ;
error = F_61 ( V_33 , V_27 , V_56 ) ;
if ( error )
F_51 ( V_27 , V_56 , false ) ;
return error ;
}
int F_65 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_44 ( V_33 ) ;
int error ;
if ( ! V_27 )
return 0 ;
error = F_63 ( V_27 ) ;
F_51 ( V_27 , V_56 , false ) ;
return error ;
}
int F_66 ( struct V_8 * V_33 )
{
int V_36 = F_67 ( V_33 ) ;
return V_36 ? V_36 : F_64 ( V_33 ) ;
}
int F_68 ( struct V_8 * V_33 )
{
int V_36 = F_65 ( V_33 ) ;
return V_36 ? V_36 : F_69 ( V_33 ) ;
}
int F_70 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_44 ( V_33 ) ;
T_3 V_31 ;
bool V_42 ;
int error ;
if ( ! V_27 )
return 0 ;
V_31 = F_46 () ;
V_42 = F_40 ( V_33 ) && F_71 ( V_27 ) ;
error = F_51 ( V_27 , V_31 , V_42 ) ;
if ( V_42 && error )
return error ;
error = F_61 ( V_33 , V_27 , V_31 ) ;
if ( error )
F_51 ( V_27 , V_10 , false ) ;
return error ;
}
int F_72 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_44 ( V_33 ) ;
int error ;
if ( ! V_27 )
return 0 ;
error = F_63 ( V_27 ) ;
F_51 ( V_27 , V_10 , false ) ;
return error ;
}
int F_73 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_44 ( V_33 ) ;
T_3 V_79 ;
int V_36 , V_1 ;
V_36 = F_74 ( V_33 ) ;
if ( V_36 < 0 )
return V_36 ;
if ( ! V_27 || ! F_75 ( V_33 )
|| F_40 ( V_33 ) != ! ! V_27 -> V_42 . V_80 )
return 0 ;
V_79 = F_46 () ;
if ( V_79 == V_56 )
return 1 ;
if ( V_27 -> V_15 . V_12 . V_81 )
return 0 ;
V_36 = F_39 ( V_33 , V_27 , V_79 , NULL , & V_1 ) ;
return ! V_36 && V_1 == V_27 -> V_15 . V_1 ;
}
void F_76 ( struct V_8 * V_33 )
{
F_77 ( V_33 ) ;
if ( V_33 -> V_15 . V_82 )
F_78 ( V_33 ) ;
}
int F_79 ( struct V_8 * V_33 )
{
F_50 ( V_33 ) ;
return F_80 ( V_33 ) ;
}
int F_81 ( struct V_8 * V_33 )
{
int V_36 = F_82 ( V_33 ) ;
return V_36 ? V_36 : F_70 ( V_33 ) ;
}
int F_83 ( struct V_8 * V_33 )
{
int V_36 = F_72 ( V_33 ) ;
return V_36 ? V_36 : F_84 ( V_33 ) ;
}
int F_85 ( struct V_8 * V_33 )
{
F_50 ( V_33 ) ;
return F_86 ( V_33 ) ;
}
static void F_87 ( struct V_8 * V_33 , bool V_83 )
{
struct V_7 * V_27 = F_44 ( V_33 ) ;
if ( V_27 && V_33 -> V_84 == & V_85 ) {
V_33 -> V_84 = NULL ;
F_34 ( V_27 ) ;
if ( V_83 ) {
F_88 ( V_33 ) ;
F_89 ( V_33 ) ;
F_51 ( V_27 , V_56 , false ) ;
F_61 ( V_33 , V_27 , V_56 ) ;
}
}
}
int F_90 ( struct V_8 * V_33 , bool V_86 )
{
struct V_7 * V_27 = F_44 ( V_33 ) ;
if ( ! V_27 )
return - V_22 ;
if ( V_33 -> V_84 )
return - V_87 ;
if ( ! F_91 ( V_27 , V_33 ) )
return - V_88 ;
F_28 ( V_27 , V_33 , F_47 ) ;
V_33 -> V_84 = & V_85 ;
if ( V_86 ) {
F_63 ( V_27 ) ;
F_51 ( V_27 , V_56 , false ) ;
}
V_33 -> V_84 -> V_89 = F_87 ;
return 0 ;
}
