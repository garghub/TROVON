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
int F_8 ( struct V_15 * V_16 , struct V_1 * V_2 ,
T_3 V_17 , int V_18 , int * V_19 )
{
char V_20 [] = L_1 ;
unsigned long long V_21 , V_22 ;
bool V_8 = false ;
if ( V_18 < V_23 || V_18 > V_24 )
return - V_25 ;
if ( V_18 > V_26 ) {
enum V_27 V_28 ;
V_28 = F_9 ( V_16 , V_29 ) ;
if ( V_28 == V_30 )
V_18 = V_26 ;
}
V_20 [ 2 ] = '0' + V_17 ;
V_21 = V_23 ;
V_22 = V_24 ;
if ( V_17 > V_31 ) {
F_10 ( V_2 -> V_12 , V_20 , NULL , & V_21 ) ;
V_8 = F_11 ( V_16 ) && V_2 -> V_8 . V_9 . V_32
&& V_2 -> V_8 . V_33 >= V_17 ;
} else if ( F_9 ( V_16 , V_34 ) !=
V_35 ) {
V_8 = V_2 -> V_8 . V_9 . V_32 ;
}
if ( V_8 ) {
T_1 V_5 ;
V_20 [ 3 ] = 'W' ;
V_5 = F_10 ( V_2 -> V_12 , V_20 , NULL ,
& V_22 ) ;
if ( F_4 ( V_5 ) ) {
if ( V_17 != V_31 ||
V_5 != V_36 )
V_22 = V_21 ;
} else if ( V_22 < V_21 ) {
F_12 ( V_37 L_2 ,
V_20 ) ;
V_21 = V_22 ;
}
}
if ( V_18 < V_21 )
return - V_25 ;
if ( V_19 )
* V_19 = V_21 ;
if ( V_22 > V_18 ) {
for ( V_22 = V_18 ; V_22 > V_21 ; V_22 -- ) {
if ( V_2 -> V_38 . V_39 [ V_22 ] . V_9 . V_32 )
break;
}
}
return V_22 ;
}
int F_13 ( struct V_15 * V_16 , int * V_19 , int V_18 )
{
T_4 V_12 = F_14 ( V_16 ) ;
struct V_1 * V_2 ;
if ( ! V_12 || F_4 ( F_15 ( V_12 , & V_2 ) ) ) {
F_16 ( V_16 , L_3 , V_40 ) ;
return - V_41 ;
}
return F_8 ( V_16 , V_2 , F_17 () ,
V_18 , V_19 ) ;
}
static void F_18 ( T_4 V_12 , T_3 V_42 , void * V_4 )
{
struct V_15 * V_16 = V_4 ;
if ( V_42 == V_43 && V_16 ) {
F_19 ( V_16 , 0 ) ;
F_20 ( V_16 ) ;
}
}
int F_21 ( struct V_1 * V_2 , bool V_44 )
{
struct V_45 * V_8 = & V_2 -> V_8 ;
if ( V_44 ) {
T_1 V_46 ;
int error ;
error = F_22 ( V_2 , V_31 ) ;
if ( error )
return error ;
V_46 = F_23 ( V_8 -> V_47 , V_8 -> V_48 ) ;
if ( F_4 ( V_46 ) ) {
F_24 ( V_2 ) ;
return - V_49 ;
}
} else {
F_25 ( V_8 -> V_47 , V_8 -> V_48 ) ;
F_24 ( V_2 ) ;
}
return 0 ;
}
int F_26 ( struct V_15 * V_50 , bool V_44 )
{
struct V_1 * V_2 ;
T_4 V_12 ;
if ( ! F_27 ( V_50 ) )
return - V_25 ;
V_12 = F_14 ( V_50 ) ;
if ( ! V_12 || F_4 ( F_15 ( V_12 , & V_2 ) ) ) {
F_16 ( V_50 , L_3 ,
V_40 ) ;
return - V_41 ;
}
return F_21 ( V_2 , V_44 ) ;
}
static inline void F_18 ( T_4 V_12 , T_3 V_42 ,
void * V_4 ) {}
int F_28 ( struct V_1 * V_2 , T_3 V_17 ,
bool V_44 )
{
return V_44 ?
F_22 ( V_2 , V_17 ) :
F_24 ( V_2 ) ;
}
int F_29 ( struct V_15 * V_16 , bool V_44 )
{
T_4 V_12 ;
struct V_1 * V_2 ;
int error ;
if ( ! F_30 ( V_16 ) )
return - V_25 ;
V_12 = F_14 ( V_16 ) ;
if ( ! V_12 || F_4 ( F_15 ( V_12 , & V_2 ) ) ) {
F_16 ( V_16 , L_3 , V_40 ) ;
return - V_41 ;
}
error = F_28 ( V_2 , F_17 () ,
V_44 ) ;
if ( ! error )
F_31 ( V_16 , L_4 ,
V_44 ? L_5 : L_6 ) ;
return error ;
}
static struct V_1 * F_32 ( struct V_15 * V_16 )
{
T_4 V_12 = F_14 ( V_16 ) ;
struct V_1 * V_2 ;
return V_12 && ! F_15 ( V_12 , & V_2 ) ? V_2 : NULL ;
}
static int F_33 ( struct V_15 * V_16 , struct V_1 * V_2 ,
T_3 V_51 )
{
int V_52 ;
if ( ! F_34 ( V_2 ) )
return 0 ;
V_52 = F_8 ( V_16 , V_2 , V_51 ,
V_24 , NULL ) ;
if ( V_52 < V_23 || V_52 > V_24 )
return - V_49 ;
return F_35 ( V_2 , V_52 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
return F_34 ( V_2 ) ?
F_35 ( V_2 , V_23 ) : 0 ;
}
int F_37 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_32 ( V_16 ) ;
bool V_53 ;
int error ;
if ( ! V_2 )
return 0 ;
V_53 = F_9 ( V_16 , V_34 ) >
V_35 ;
error = F_21 ( V_2 , V_53 ) ;
if ( V_53 && error )
return - V_54 ;
error = F_33 ( V_16 , V_2 , V_31 ) ;
if ( error )
F_21 ( V_2 , false ) ;
return error ;
}
int F_38 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_32 ( V_16 ) ;
int error ;
if ( ! V_2 )
return 0 ;
error = F_36 ( V_2 ) ;
F_21 ( V_2 , false ) ;
return error ;
}
int F_39 ( struct V_15 * V_16 )
{
int V_55 = F_40 ( V_16 ) ;
return V_55 ? V_55 : F_37 ( V_16 ) ;
}
int F_41 ( struct V_15 * V_16 )
{
int V_55 = F_38 ( V_16 ) ;
return V_55 ? V_55 : F_42 ( V_16 ) ;
}
int F_43 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_32 ( V_16 ) ;
T_3 V_17 ;
bool V_8 ;
int error ;
if ( ! V_2 )
return 0 ;
V_17 = F_17 () ;
V_8 = F_11 ( V_16 ) ;
error = F_28 ( V_2 , V_17 , V_8 ) ;
if ( V_8 && error )
return error ;
error = F_33 ( V_16 , V_2 , V_17 ) ;
if ( error )
F_28 ( V_2 , V_56 , false ) ;
return error ;
}
int F_44 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_32 ( V_16 ) ;
int error ;
if ( ! V_2 )
return 0 ;
error = F_36 ( V_2 ) ;
F_28 ( V_2 , V_56 , false ) ;
return error ;
}
int F_45 ( struct V_15 * V_16 )
{
F_20 ( V_16 ) ;
return F_46 ( V_16 ) ;
}
int F_47 ( struct V_15 * V_16 )
{
int V_55 = F_48 ( V_16 ) ;
return V_55 ? V_55 : F_43 ( V_16 ) ;
}
int F_49 ( struct V_15 * V_16 )
{
int V_55 = F_44 ( V_16 ) ;
return V_55 ? V_55 : F_50 ( V_16 ) ;
}
int F_51 ( struct V_15 * V_16 , bool V_57 )
{
struct V_1 * V_2 = F_32 ( V_16 ) ;
if ( ! V_2 )
return - V_41 ;
if ( V_16 -> V_58 )
return - V_59 ;
F_1 ( V_2 , F_18 , V_16 ) ;
V_16 -> V_58 = & V_60 ;
if ( V_57 ) {
F_36 ( V_2 ) ;
F_21 ( V_2 , false ) ;
}
return 0 ;
}
void F_52 ( struct V_15 * V_16 , bool V_61 )
{
struct V_1 * V_2 = F_32 ( V_16 ) ;
if ( V_2 && V_16 -> V_58 == & V_60 ) {
V_16 -> V_58 = NULL ;
F_6 ( V_2 , F_18 ) ;
if ( V_61 ) {
F_53 ( V_16 ) ;
F_54 ( V_16 ) ;
F_21 ( V_2 , false ) ;
F_33 ( V_16 , V_2 , V_31 ) ;
}
}
}
