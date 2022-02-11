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
int V_9 = 0 ;
bool V_31 = false ;
if ( ! V_8 || ! V_8 -> V_12 . V_13
|| ( V_1 < V_2 ) || ( V_1 > V_6 ) )
return - V_11 ;
if ( V_1 == V_8 -> V_15 . V_1 ) {
F_6 ( ( V_24 , L_9 ,
V_8 -> V_25 . V_26 ,
F_1 ( V_1 ) ) ) ;
return 0 ;
}
if ( ! V_8 -> V_15 . V_28 [ V_1 ] . V_12 . V_32 ) {
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
if ( V_1 == V_6
&& V_8 -> V_15 . V_28 [ V_6 ] . V_12 . V_34 ) {
V_1 = V_5 ;
V_31 = true ;
}
if ( V_1 < V_8 -> V_15 . V_1 && V_1 != V_2
&& V_8 -> V_15 . V_1 >= V_5 ) {
F_10 ( & V_8 -> V_33 ,
L_12 ) ;
return - V_22 ;
}
if ( V_8 -> V_15 . V_12 . V_17 ) {
V_9 = F_11 ( V_8 , V_1 ) ;
if ( V_9 )
goto V_35;
}
V_9 = F_7 ( V_8 , V_1 ) ;
if ( V_9 )
goto V_35;
if ( V_31 ) {
V_8 -> V_15 . V_1 = V_1 ;
V_1 = V_6 ;
V_9 = F_11 ( V_8 , V_1 ) ;
}
V_35:
if ( V_9 ) {
F_10 ( & V_8 -> V_33 , L_13 ,
F_1 ( V_1 ) ) ;
} else {
V_8 -> V_15 . V_1 = V_1 ;
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
return 0 ;
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
T_2 F_21 ( struct V_7 * V_27 ,
T_3 V_38 , void * V_39 )
{
T_2 V_21 = V_40 ;
F_22 ( & V_41 ) ;
if ( V_27 -> V_42 . V_12 . V_43 )
goto V_16;
V_21 = F_23 ( V_27 -> V_19 ,
V_44 ,
V_38 , V_39 ) ;
if ( F_5 ( V_21 ) )
goto V_16;
V_27 -> V_42 . V_12 . V_43 = true ;
V_16:
F_24 ( & V_41 ) ;
return V_21 ;
}
T_2 F_25 ( struct V_7 * V_27 ,
T_3 V_38 )
{
T_2 V_21 = V_45 ;
F_22 ( & V_41 ) ;
if ( ! V_27 -> V_42 . V_12 . V_43 )
goto V_16;
V_21 = F_26 ( V_27 -> V_19 ,
V_44 ,
V_38 ) ;
if ( F_5 ( V_21 ) )
goto V_16;
V_27 -> V_42 . V_12 . V_43 = false ;
V_16:
F_24 ( & V_41 ) ;
return V_21 ;
}
bool F_27 ( T_1 V_19 )
{
struct V_7 * V_8 ;
int V_9 ;
V_9 = F_13 ( V_19 , & V_8 ) ;
return V_9 ? false : V_8 -> V_42 . V_12 . V_32 ;
}
static int F_28 ( struct V_8 * V_33 , struct V_7 * V_27 ,
T_4 V_46 , int * V_47 , int * V_48 )
{
char V_30 [] = { '_' , 'S' , '0' + V_46 , 'D' , '\0' } ;
T_1 V_19 = V_27 -> V_19 ;
unsigned long long V_36 ;
int V_49 , V_50 ;
bool V_42 = false ;
T_2 V_21 ;
V_49 = V_2 ;
V_50 = V_6 ;
if ( V_46 > V_51 ) {
V_36 = V_49 ;
V_21 = F_4 ( V_19 , V_30 , NULL , & V_36 ) ;
if ( ( F_5 ( V_21 ) && V_21 != V_52 )
|| V_36 > V_6 )
return - V_53 ;
if ( ! V_27 -> V_15 . V_28 [ V_36 ] . V_12 . V_32 ) {
if ( V_36 == V_5 )
V_36 = V_6 ;
else
return - V_53 ;
}
V_49 = V_36 ;
V_42 = F_29 ( V_33 ) && V_27 -> V_42 . V_12 . V_32
&& V_27 -> V_42 . V_54 >= V_46 ;
} else if ( F_30 ( V_33 , V_55 ) !=
V_56 ) {
V_42 = V_27 -> V_42 . V_12 . V_32 ;
}
if ( V_42 ) {
V_30 [ 3 ] = 'W' ;
V_21 = F_4 ( V_19 , V_30 , NULL , & V_36 ) ;
if ( V_21 == V_52 ) {
if ( V_46 > V_51 )
V_50 = V_49 ;
} else if ( F_31 ( V_21 ) && V_36 <= V_6 ) {
if ( ! V_27 -> V_15 . V_28 [ V_36 ] . V_12 . V_32 )
V_36 = V_6 ;
V_50 = V_36 > V_49 ? V_36 : V_49 ;
} else {
return - V_53 ;
}
}
if ( V_47 )
* V_47 = V_49 ;
if ( V_48 )
* V_48 = V_50 ;
return 0 ;
}
int F_32 ( struct V_8 * V_33 , int * V_47 , int V_57 )
{
T_1 V_19 = F_33 ( V_33 ) ;
struct V_7 * V_27 ;
int V_36 , V_49 , V_50 ;
if ( V_57 < V_2 || V_57 > V_6 )
return - V_11 ;
if ( V_57 > V_5 ) {
enum V_58 V_59 ;
V_59 = F_30 ( V_33 , V_60 ) ;
if ( V_59 == V_61 )
V_57 = V_5 ;
}
if ( ! V_19 || F_13 ( V_19 , & V_27 ) ) {
F_34 ( V_33 , L_15 , V_62 ) ;
return - V_22 ;
}
V_36 = F_28 ( V_33 , V_27 , F_35 () ,
& V_49 , & V_50 ) ;
if ( V_36 )
return V_36 ;
if ( V_57 < V_49 )
return - V_11 ;
if ( V_50 > V_57 ) {
for ( V_50 = V_57 ; V_50 > V_49 ; V_50 -- ) {
if ( V_27 -> V_15 . V_28 [ V_50 ] . V_12 . V_32 )
break;
}
}
if ( V_47 )
* V_47 = V_49 ;
return V_50 ;
}
static void F_36 ( T_1 V_19 , T_4 V_63 , void * V_39 )
{
struct V_8 * V_33 = V_39 ;
if ( V_63 == V_64 && V_33 ) {
F_37 ( V_33 , 0 ) ;
F_38 ( V_33 ) ;
}
}
int F_39 ( struct V_7 * V_27 , bool V_65 )
{
struct V_66 * V_42 = & V_27 -> V_42 ;
if ( V_65 ) {
T_2 V_67 ;
int error ;
error = F_40 ( V_27 , V_51 ) ;
if ( error )
return error ;
V_67 = F_41 ( V_42 -> V_68 , V_42 -> V_69 ) ;
if ( F_5 ( V_67 ) ) {
F_42 ( V_27 ) ;
return - V_70 ;
}
} else {
F_43 ( V_42 -> V_68 , V_42 -> V_69 ) ;
F_42 ( V_27 ) ;
}
return 0 ;
}
int F_44 ( struct V_8 * V_71 , bool V_65 )
{
struct V_7 * V_27 ;
T_1 V_19 ;
if ( ! F_45 ( V_71 ) )
return - V_11 ;
V_19 = F_33 ( V_71 ) ;
if ( ! V_19 || F_13 ( V_19 , & V_27 ) ) {
F_34 ( V_71 , L_15 ,
V_62 ) ;
return - V_22 ;
}
return F_39 ( V_27 , V_65 ) ;
}
static inline void F_36 ( T_1 V_19 , T_4 V_63 ,
void * V_39 ) {}
int F_46 ( struct V_7 * V_27 , T_4 V_46 ,
bool V_65 )
{
return V_65 ?
F_40 ( V_27 , V_46 ) :
F_42 ( V_27 ) ;
}
int F_47 ( struct V_8 * V_33 , bool V_65 )
{
T_1 V_19 ;
struct V_7 * V_27 ;
int error ;
if ( ! F_48 ( V_33 ) )
return - V_11 ;
V_19 = F_33 ( V_33 ) ;
if ( ! V_19 || F_13 ( V_19 , & V_27 ) ) {
F_34 ( V_33 , L_15 , V_62 ) ;
return - V_22 ;
}
error = F_46 ( V_27 , F_35 () ,
V_65 ) ;
if ( ! error )
F_49 ( V_33 , L_16 ,
V_65 ? L_17 : L_18 ) ;
return error ;
}
static int F_50 ( struct V_8 * V_33 , struct V_7 * V_27 ,
T_4 V_72 )
{
int V_36 , V_1 ;
if ( ! F_51 ( V_27 ) )
return 0 ;
V_36 = F_28 ( V_33 , V_27 , V_72 , NULL , & V_1 ) ;
return V_36 ? V_36 : F_9 ( V_27 , V_1 ) ;
}
static int F_52 ( struct V_7 * V_27 )
{
return F_51 ( V_27 ) ?
F_9 ( V_27 , V_2 ) : 0 ;
}
int F_53 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_54 ( V_33 ) ;
bool V_73 ;
int error ;
if ( ! V_27 )
return 0 ;
V_73 = F_30 ( V_33 , V_55 ) >
V_56 ;
error = F_39 ( V_27 , V_73 ) ;
if ( V_73 && error )
return - V_74 ;
error = F_50 ( V_33 , V_27 , V_51 ) ;
if ( error )
F_39 ( V_27 , false ) ;
return error ;
}
int F_55 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_54 ( V_33 ) ;
int error ;
if ( ! V_27 )
return 0 ;
error = F_52 ( V_27 ) ;
F_39 ( V_27 , false ) ;
return error ;
}
int F_56 ( struct V_8 * V_33 )
{
int V_36 = F_57 ( V_33 ) ;
return V_36 ? V_36 : F_53 ( V_33 ) ;
}
int F_58 ( struct V_8 * V_33 )
{
int V_36 = F_55 ( V_33 ) ;
return V_36 ? V_36 : F_59 ( V_33 ) ;
}
int F_60 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_54 ( V_33 ) ;
T_4 V_46 ;
bool V_42 ;
int error ;
if ( ! V_27 )
return 0 ;
V_46 = F_35 () ;
V_42 = F_29 ( V_33 ) ;
error = F_46 ( V_27 , V_46 , V_42 ) ;
if ( V_42 && error )
return error ;
error = F_50 ( V_33 , V_27 , V_46 ) ;
if ( error )
F_46 ( V_27 , V_10 , false ) ;
return error ;
}
int F_61 ( struct V_8 * V_33 )
{
struct V_7 * V_27 = F_54 ( V_33 ) ;
int error ;
if ( ! V_27 )
return 0 ;
error = F_52 ( V_27 ) ;
F_46 ( V_27 , V_10 , false ) ;
return error ;
}
int F_62 ( struct V_8 * V_33 )
{
F_38 ( V_33 ) ;
return F_63 ( V_33 ) ;
}
int F_64 ( struct V_8 * V_33 )
{
int V_36 = F_65 ( V_33 ) ;
return V_36 ? V_36 : F_60 ( V_33 ) ;
}
int F_66 ( struct V_8 * V_33 )
{
int V_36 = F_61 ( V_33 ) ;
return V_36 ? V_36 : F_67 ( V_33 ) ;
}
int F_68 ( struct V_8 * V_33 , bool V_75 )
{
struct V_7 * V_27 = F_54 ( V_33 ) ;
if ( ! V_27 )
return - V_22 ;
if ( V_33 -> V_76 )
return - V_77 ;
F_21 ( V_27 , F_36 , V_33 ) ;
V_33 -> V_76 = & V_78 ;
if ( V_75 ) {
F_52 ( V_27 ) ;
F_39 ( V_27 , false ) ;
}
return 0 ;
}
void F_69 ( struct V_8 * V_33 , bool V_79 )
{
struct V_7 * V_27 = F_54 ( V_33 ) ;
if ( V_27 && V_33 -> V_76 == & V_78 ) {
V_33 -> V_76 = NULL ;
F_25 ( V_27 , F_36 ) ;
if ( V_79 ) {
F_70 ( V_33 ) ;
F_71 ( V_33 ) ;
F_39 ( V_27 , false ) ;
F_50 ( V_33 , V_27 , V_51 ) ;
}
}
}
