static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( & V_4 -> V_6 -> V_7 . V_8 , NULL , L_1 ) ;
F_4 ( & V_4 -> V_6 -> V_7 . V_8 , V_9 ) ;
}
static T_1 F_5 ( int V_10 , void * V_11 )
{
struct V_3 * V_4 = V_11 ;
F_6 ( & V_4 -> V_5 ) ;
return V_12 ;
}
static T_2 F_7 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
struct V_17 * V_18 = V_4 -> V_18 ;
int V_19 = F_9 ( V_18 -> V_20 ) ;
if ( V_18 -> V_21 )
V_19 = ! V_19 ;
return sprintf ( V_16 , L_2 , V_19 ) ;
}
static int F_10 ( struct V_3 * V_4 ,
struct V_17 * V_18 )
{
int V_22 ;
int V_23 ;
struct V_24 * V_6 = V_4 -> V_6 ;
V_4 -> V_18 = V_18 ;
V_22 = F_11 ( & V_6 -> V_7 , V_18 -> V_20 , L_3 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_12 ( V_18 -> V_20 ) ;
if ( V_22 )
return V_22 ;
V_23 = F_13 ( V_18 -> V_20 ) ;
if ( V_23 < 0 )
return 0 ;
F_14 ( & V_4 -> V_5 , F_1 ) ;
F_15 ( V_23 , V_25 ) ;
V_22 = F_16 ( & V_6 -> V_7 , V_23 , F_5 ,
V_26 , L_3 , V_4 ) ;
return V_22 ;
}
static void F_17 ( struct V_3 * V_4 , int V_27 )
{
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; V_28 ++ )
F_18 ( V_4 -> V_30 [ V_28 ] , ( V_27 >> V_28 ) & 1 ) ;
}
static int F_19 ( struct V_3 * V_4 )
{
int V_28 ;
int V_27 = 0 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_29 ; V_28 ++ ) {
int V_19 ;
V_19 = F_9 ( V_4 -> V_30 [ V_28 ] ) ;
V_27 |= ( V_19 << V_28 ) ;
}
return V_27 ;
}
static void F_20 ( struct V_3 * V_4 , int V_31 )
{
if ( V_4 -> V_31 == V_31 )
return;
F_17 ( V_4 , V_4 -> V_32 [ V_31 ] . V_27 ) ;
V_4 -> V_31 = V_31 ;
}
static int F_21 ( struct V_3 * V_4 )
{
int V_27 = F_19 ( V_4 ) ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_33 ; V_28 ++ )
if ( V_4 -> V_32 [ V_28 ] . V_27 == V_27 )
return V_28 ;
F_22 ( & V_4 -> V_6 -> V_7 ,
L_4 , V_27 ) ;
return - V_34 ;
}
static int F_23 ( struct V_3 * V_4 , int V_35 )
{
struct V_36 * V_32 = V_4 -> V_32 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_4 -> V_33 ; V_28 ++ )
if ( V_32 [ V_28 ] . V_35 >= V_35 )
return V_28 ;
return V_4 -> V_33 - 1 ;
}
static T_2 F_24 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
T_3 V_37 = V_4 -> V_31 * 255 / ( V_4 -> V_33 - 1 ) ;
return sprintf ( V_16 , L_2 , V_37 ) ;
}
static T_2 F_25 ( struct V_13 * V_7 , struct V_14 * V_15 ,
const char * V_16 , T_4 V_38 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
unsigned long V_37 ;
int V_31 ;
int V_39 = V_38 ;
if ( F_26 ( V_16 , 10 , & V_37 ) || V_37 > 255 )
return - V_34 ;
F_27 ( & V_4 -> V_40 ) ;
if ( ! V_4 -> V_41 ) {
V_39 = - V_42 ;
goto V_43;
}
V_31 = F_28 ( V_37 * ( V_4 -> V_33 - 1 ) , 255 ) ;
F_20 ( V_4 , V_31 ) ;
V_43:
F_29 ( & V_4 -> V_40 ) ;
return V_39 ;
}
static T_2 F_30 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_16 , L_2 , V_4 -> V_41 ) ;
}
static T_2 F_31 ( struct V_13 * V_7 , struct V_14 * V_15 ,
const char * V_16 , T_4 V_38 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
unsigned long V_44 ;
if ( F_26 ( V_16 , 10 , & V_44 ) || V_44 > 1 )
return - V_34 ;
if ( V_4 -> V_41 == V_44 )
return V_38 ;
F_27 ( & V_4 -> V_40 ) ;
V_4 -> V_41 = V_44 ;
if ( V_44 == 0 )
F_20 ( V_4 , V_4 -> V_33 - 1 ) ;
F_29 ( & V_4 -> V_40 ) ;
return V_38 ;
}
static T_2 F_32 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
return sprintf ( V_16 , L_5 ) ;
}
static T_2 F_33 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_16 , L_2 , V_4 -> V_32 [ 0 ] . V_35 ) ;
}
static T_2 F_34 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_16 , L_2 ,
V_4 -> V_32 [ V_4 -> V_33 - 1 ] . V_35 ) ;
}
static T_2 F_35 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
return sprintf ( V_16 , L_2 , V_4 -> V_32 [ V_4 -> V_31 ] . V_35 ) ;
}
static T_2 F_36 ( struct V_13 * V_7 , struct V_14 * V_15 ,
const char * V_16 , T_4 V_38 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
unsigned long V_35 ;
int V_39 = V_38 ;
if ( F_26 ( V_16 , 10 , & V_35 ) )
return - V_34 ;
F_27 ( & V_4 -> V_40 ) ;
if ( ! V_4 -> V_41 ) {
V_39 = - V_42 ;
goto V_43;
}
F_20 ( V_4 , F_23 ( V_4 , V_35 ) ) ;
V_43:
F_29 ( & V_4 -> V_40 ) ;
return V_39 ;
}
static T_2 F_37 ( struct V_13 * V_7 ,
struct V_14 * V_15 , char * V_16 )
{
return sprintf ( V_16 , L_6 ) ;
}
static T_5 F_38 ( struct V_45 * V_8 ,
struct V_46 * V_15 , int V_47 )
{
struct V_13 * V_7 = F_2 ( V_8 , struct V_13 , V_8 ) ;
struct V_3 * V_48 = F_8 ( V_7 ) ;
if ( V_47 == 1 && ! V_48 -> V_18 )
return 0 ;
if ( V_47 > 1 && ! V_48 -> V_30 )
return 0 ;
return V_15 -> V_49 ;
}
static int F_39 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_24 * V_6 = V_4 -> V_6 ;
int V_29 = V_51 -> V_29 ;
unsigned * V_30 = V_51 -> V_30 ;
int V_28 , V_22 ;
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
V_22 = F_11 ( & V_6 -> V_7 , V_30 [ V_28 ] ,
L_7 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_40 ( V_30 [ V_28 ] , F_9 ( V_30 [ V_28 ] ) ) ;
if ( V_22 )
return V_22 ;
}
V_4 -> V_29 = V_29 ;
V_4 -> V_30 = V_30 ;
V_4 -> V_33 = V_51 -> V_33 ;
V_4 -> V_32 = V_51 -> V_32 ;
V_4 -> V_41 = true ;
V_4 -> V_31 = F_21 ( V_4 ) ;
if ( V_4 -> V_31 < 0 )
return - V_52 ;
return 0 ;
}
static int F_41 ( struct V_13 * V_7 ,
struct V_50 * V_51 )
{
struct V_53 * V_54 ;
struct V_36 * V_32 ;
unsigned * V_30 ;
unsigned V_28 ;
T_6 V_55 ;
struct V_56 * V_57 ;
const T_7 * V_58 ;
V_54 = V_7 -> V_59 ;
V_51 -> V_29 = F_42 ( V_54 ) ;
if ( V_51 -> V_29 <= 0 ) {
F_43 ( V_7 , L_8 ) ;
return - V_52 ;
}
V_30 = F_44 ( V_7 , V_51 -> V_29 * sizeof( unsigned ) ,
V_60 ) ;
if ( ! V_30 )
return - V_61 ;
for ( V_28 = 0 ; V_28 < V_51 -> V_29 ; V_28 ++ ) {
int V_44 ;
V_44 = F_45 ( V_54 , V_28 ) ;
if ( V_44 < 0 )
return V_44 ;
V_30 [ V_28 ] = V_44 ;
}
V_51 -> V_30 = V_30 ;
V_57 = F_46 ( V_54 , L_9 , & V_28 ) ;
if ( ! V_57 ) {
F_43 ( V_7 , L_10 ) ;
return - V_52 ;
}
V_28 = V_28 / sizeof( T_6 ) ;
if ( V_28 == 0 || V_28 & 1 ) {
F_43 ( V_7 , L_11 ) ;
return - V_52 ;
}
V_51 -> V_33 = V_28 / 2 ;
V_32 = F_44 ( V_7 ,
V_51 -> V_33 * sizeof( struct V_36 ) ,
V_60 ) ;
if ( ! V_32 )
return - V_61 ;
V_58 = NULL ;
for ( V_28 = 0 ; V_28 < V_51 -> V_33 ; V_28 ++ ) {
V_58 = F_47 ( V_57 , V_58 , & V_55 ) ;
if ( ! V_58 )
return - V_52 ;
V_32 [ V_28 ] . V_35 = V_55 ;
V_58 = F_47 ( V_57 , V_58 , & V_55 ) ;
if ( ! V_58 )
return - V_52 ;
V_32 [ V_28 ] . V_27 = V_55 ;
}
V_51 -> V_32 = V_32 ;
if ( F_48 ( V_54 , L_12 ) > 0 ) {
struct V_17 * V_18 ;
int V_44 ;
enum V_62 V_63 ;
V_18 = F_44 ( V_7 , sizeof( struct V_17 ) ,
V_60 ) ;
if ( ! V_18 )
return - V_61 ;
V_44 = F_49 ( V_54 , L_12 , 0 , & V_63 ) ;
if ( V_44 < 0 )
return V_44 ;
V_18 -> V_20 = V_44 ;
V_18 -> V_21 = V_63 & V_64 ;
V_51 -> V_18 = V_18 ;
}
return 0 ;
}
static int F_50 ( struct V_24 * V_6 )
{
int V_22 ;
struct V_3 * V_4 ;
struct V_50 * V_51 = F_51 ( & V_6 -> V_7 ) ;
#ifdef F_52
if ( ! V_51 ) {
V_51 = F_44 ( & V_6 -> V_7 ,
sizeof( struct V_50 ) ,
V_60 ) ;
if ( ! V_51 )
return - V_61 ;
V_22 = F_41 ( & V_6 -> V_7 , V_51 ) ;
if ( V_22 )
return V_22 ;
}
#else
if ( ! V_51 )
return - V_34 ;
#endif
V_4 = F_44 ( & V_6 -> V_7 , sizeof( struct V_3 ) ,
V_60 ) ;
if ( ! V_4 )
return - V_61 ;
V_4 -> V_6 = V_6 ;
F_53 ( V_6 , V_4 ) ;
F_54 ( & V_4 -> V_40 ) ;
if ( V_51 -> V_18 ) {
V_22 = F_10 ( V_4 , V_51 -> V_18 ) ;
if ( V_22 )
return V_22 ;
}
if ( V_51 -> V_30 && V_51 -> V_29 > 0 ) {
if ( ! V_51 -> V_32 || V_51 -> V_33 <= 1 )
return - V_34 ;
V_22 = F_39 ( V_4 , V_51 ) ;
if ( V_22 )
return V_22 ;
}
V_22 = F_55 ( & V_6 -> V_7 . V_8 , & V_65 ) ;
if ( V_22 )
return V_22 ;
V_4 -> V_66 = F_56 ( & V_6 -> V_7 ) ;
if ( F_57 ( V_4 -> V_66 ) ) {
V_22 = F_58 ( V_4 -> V_66 ) ;
goto V_67;
}
F_59 ( & V_6 -> V_7 , L_13 ) ;
return 0 ;
V_67:
F_60 ( & V_6 -> V_7 . V_8 , & V_65 ) ;
return V_22 ;
}
static int F_61 ( struct V_24 * V_6 )
{
struct V_3 * V_4 = F_62 ( V_6 ) ;
F_63 ( V_4 -> V_66 ) ;
F_60 ( & V_6 -> V_7 . V_8 , & V_65 ) ;
return 0 ;
}
static int F_64 ( struct V_13 * V_7 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
if ( V_4 -> V_30 ) {
V_4 -> V_68 = V_4 -> V_31 ;
F_20 ( V_4 , 0 ) ;
}
return 0 ;
}
static int F_65 ( struct V_13 * V_7 )
{
struct V_3 * V_4 = F_8 ( V_7 ) ;
if ( V_4 -> V_30 )
F_20 ( V_4 , V_4 -> V_68 ) ;
return 0 ;
}
