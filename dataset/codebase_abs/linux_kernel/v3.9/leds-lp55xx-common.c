static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static struct V_1 * F_3 ( struct V_4 * V_5 )
{
return F_1 ( F_4 ( V_5 ) ) ;
}
static void F_5 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_10 = V_9 -> V_11 . V_10 ;
T_1 V_12 = V_9 -> V_11 . V_12 ;
F_6 ( V_7 , V_10 , V_12 ) ;
}
static int F_7 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
T_1 V_10 = V_9 -> V_13 . V_10 ;
T_1 V_12 = V_9 -> V_13 . V_12 ;
int V_14 ;
V_14 = F_6 ( V_7 , V_10 , V_12 ) ;
if ( V_14 )
return V_14 ;
F_8 ( 1000 , 2000 ) ;
V_14 = F_9 ( V_7 , V_10 , & V_12 ) ;
if ( V_14 )
return V_14 ;
if ( V_12 != V_9 -> V_13 . V_12 )
return - V_15 ;
return 0 ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
if ( ! V_9 -> V_16 )
return 0 ;
return V_9 -> V_16 ( V_7 ) ;
}
static T_2 F_11 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
char * V_19 )
{
struct V_1 * V_20 = F_3 ( V_5 ) ;
return sprintf ( V_19 , L_1 , V_20 -> V_21 ) ;
}
static T_2 F_12 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
const char * V_19 , T_3 V_22 )
{
struct V_1 * V_20 = F_3 ( V_5 ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
unsigned long V_23 ;
if ( F_13 ( V_19 , 0 , & V_23 ) )
return - V_24 ;
if ( V_23 > V_20 -> V_25 )
return - V_24 ;
if ( ! V_7 -> V_9 -> V_26 )
return V_22 ;
F_14 ( & V_7 -> V_27 ) ;
V_7 -> V_9 -> V_26 ( V_20 , ( T_1 ) V_23 ) ;
F_15 ( & V_7 -> V_27 ) ;
return V_22 ;
}
static T_2 F_16 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
char * V_19 )
{
struct V_1 * V_20 = F_3 ( V_5 ) ;
return sprintf ( V_19 , L_1 , V_20 -> V_25 ) ;
}
static void F_17 ( struct V_2 * V_3 ,
enum V_28 V_29 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
V_20 -> V_29 = ( T_1 ) V_29 ;
F_18 ( & V_20 -> V_30 ) ;
}
static int F_19 ( struct V_1 * V_20 ,
struct V_6 * V_7 , int V_31 )
{
struct V_32 * V_33 = V_7 -> V_33 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_4 * V_5 = & V_7 -> V_34 -> V_5 ;
char V_35 [ 32 ] ;
int V_14 ;
int V_36 = V_9 -> V_36 ;
if ( V_31 >= V_36 ) {
F_20 ( V_5 , L_2 , V_31 , V_36 ) ;
return - V_24 ;
}
if ( V_33 -> V_37 [ V_31 ] . V_21 == 0 )
return 0 ;
V_20 -> V_21 = V_33 -> V_37 [ V_31 ] . V_21 ;
V_20 -> V_25 = V_33 -> V_37 [ V_31 ] . V_25 ;
V_20 -> V_38 = V_33 -> V_37 [ V_31 ] . V_38 ;
if ( V_20 -> V_38 >= V_36 ) {
F_20 ( V_5 , L_3 ,
V_36 - 1 ) ;
return - V_24 ;
}
V_20 -> V_3 . V_39 = F_17 ;
if ( V_33 -> V_37 [ V_31 ] . V_35 ) {
V_20 -> V_3 . V_35 = V_33 -> V_37 [ V_31 ] . V_35 ;
} else {
snprintf ( V_35 , sizeof( V_35 ) , L_4 ,
V_33 -> V_40 ? : V_7 -> V_34 -> V_35 , V_31 ) ;
V_20 -> V_3 . V_35 = V_35 ;
}
V_14 = F_21 ( V_5 , & V_20 -> V_3 ) ;
if ( V_14 ) {
F_20 ( V_5 , L_5 , V_14 ) ;
return V_14 ;
}
V_14 = F_22 ( & V_20 -> V_3 . V_5 -> V_41 , & V_42 ) ;
if ( V_14 ) {
F_20 ( V_5 , L_6 , V_14 ) ;
F_23 ( & V_20 -> V_3 ) ;
return V_14 ;
}
return 0 ;
}
static void F_24 ( const struct V_43 * V_44 , void * V_45 )
{
struct V_6 * V_7 = V_45 ;
struct V_4 * V_5 = & V_7 -> V_34 -> V_5 ;
if ( ! V_44 ) {
F_20 ( V_5 , L_7 ) ;
goto V_46;
}
F_14 ( & V_7 -> V_27 ) ;
V_7 -> V_44 = V_44 ;
if ( V_7 -> V_9 -> V_47 )
V_7 -> V_9 -> V_47 ( V_7 ) ;
F_15 ( & V_7 -> V_27 ) ;
V_46:
F_25 ( V_7 -> V_44 ) ;
}
static int F_26 ( struct V_6 * V_7 )
{
const char * V_35 = V_7 -> V_34 -> V_35 ;
struct V_4 * V_5 = & V_7 -> V_34 -> V_5 ;
return F_27 ( V_48 , true , V_35 , V_5 ,
V_49 , V_7 , F_24 ) ;
}
static T_2 F_28 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
char * V_19 )
{
struct V_1 * V_20 = F_29 ( F_30 ( V_5 ) ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
return sprintf ( V_19 , L_1 , V_7 -> V_50 ) ;
}
static T_2 F_31 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
const char * V_19 , T_3 V_22 )
{
struct V_1 * V_20 = F_29 ( F_30 ( V_5 ) ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
unsigned long V_12 ;
int V_14 ;
if ( F_13 ( V_19 , 0 , & V_12 ) )
return - V_24 ;
switch ( V_12 ) {
case V_51 :
case V_52 :
case V_53 :
F_14 ( & V_7 -> V_27 ) ;
V_7 -> V_50 = V_12 ;
V_14 = F_26 ( V_7 ) ;
F_15 ( & V_7 -> V_27 ) ;
break;
default:
F_20 ( V_5 , L_8 , V_12 ) ;
return - V_24 ;
}
if ( V_14 ) {
F_20 ( V_5 , L_9 , V_14 ) ;
return V_14 ;
}
return V_22 ;
}
static inline void F_32 ( struct V_6 * V_7 , bool V_54 )
{
if ( V_7 -> V_9 -> V_55 )
V_7 -> V_9 -> V_55 ( V_7 , V_54 ) ;
}
static T_2 F_33 ( struct V_4 * V_5 ,
struct V_17 * V_18 ,
const char * V_19 , T_3 V_22 )
{
struct V_1 * V_20 = F_29 ( F_30 ( V_5 ) ) ;
struct V_6 * V_7 = V_20 -> V_7 ;
unsigned long V_12 ;
if ( F_13 ( V_19 , 0 , & V_12 ) )
return - V_24 ;
if ( V_12 <= 0 ) {
F_32 ( V_7 , false ) ;
return V_22 ;
}
F_14 ( & V_7 -> V_27 ) ;
F_32 ( V_7 , true ) ;
F_15 ( & V_7 -> V_27 ) ;
return V_22 ;
}
int F_6 ( struct V_6 * V_7 , T_1 V_56 , T_1 V_12 )
{
return F_34 ( V_7 -> V_34 , V_56 , V_12 ) ;
}
int F_9 ( struct V_6 * V_7 , T_1 V_56 , T_1 * V_12 )
{
T_4 V_14 ;
V_14 = F_35 ( V_7 -> V_34 , V_56 ) ;
if ( V_14 < 0 )
return V_14 ;
* V_12 = V_14 ;
return 0 ;
}
int F_36 ( struct V_6 * V_7 , T_1 V_56 , T_1 V_57 , T_1 V_12 )
{
int V_14 ;
T_1 V_58 ;
V_14 = F_9 ( V_7 , V_56 , & V_58 ) ;
if ( V_14 )
return V_14 ;
V_58 &= ~ V_57 ;
V_58 |= V_12 & V_57 ;
return F_6 ( V_7 , V_56 , V_58 ) ;
}
int F_37 ( struct V_6 * V_7 )
{
struct V_32 * V_33 ;
struct V_8 * V_9 ;
struct V_4 * V_5 = & V_7 -> V_34 -> V_5 ;
int V_14 = 0 ;
F_38 ( ! V_7 ) ;
V_33 = V_7 -> V_33 ;
V_9 = V_7 -> V_9 ;
if ( ! V_33 || ! V_9 )
return - V_24 ;
if ( V_33 -> V_59 ) {
V_14 = V_33 -> V_59 () ;
if ( V_14 < 0 ) {
F_20 ( V_5 , L_10 , V_14 ) ;
goto V_60;
}
}
if ( V_33 -> V_13 ) {
V_33 -> V_13 ( 0 ) ;
F_8 ( 1000 , 2000 ) ;
V_33 -> V_13 ( 1 ) ;
F_8 ( 1000 , 2000 ) ;
}
F_5 ( V_7 ) ;
F_8 ( 10000 , 20000 ) ;
V_14 = F_7 ( V_7 ) ;
if ( V_14 ) {
F_20 ( V_5 , L_11 , V_14 ) ;
goto V_60;
}
V_14 = F_10 ( V_7 ) ;
if ( V_14 ) {
F_20 ( V_5 , L_12 , V_14 ) ;
goto V_61;
}
return 0 ;
V_61:
F_39 ( V_7 ) ;
V_60:
return V_14 ;
}
void F_39 ( struct V_6 * V_7 )
{
struct V_32 * V_33 = V_7 -> V_33 ;
if ( V_33 -> V_13 )
V_33 -> V_13 ( 0 ) ;
if ( V_33 -> V_62 )
V_33 -> V_62 () ;
}
int F_40 ( struct V_1 * V_20 , struct V_6 * V_7 )
{
struct V_32 * V_33 = V_7 -> V_33 ;
struct V_8 * V_9 = V_7 -> V_9 ;
int V_63 = V_33 -> V_63 ;
struct V_1 * V_64 ;
T_1 V_21 ;
int V_14 ;
int V_65 ;
if ( ! V_9 -> V_66 ) {
F_20 ( & V_7 -> V_34 -> V_5 , L_13 ) ;
return - V_24 ;
}
for ( V_65 = 0 ; V_65 < V_63 ; V_65 ++ ) {
if ( V_33 -> V_37 [ V_65 ] . V_21 == 0 )
continue;
V_21 = V_33 -> V_37 [ V_65 ] . V_21 ;
V_64 = V_20 + V_65 ;
V_14 = F_19 ( V_64 , V_7 , V_65 ) ;
if ( V_14 )
goto V_67;
F_41 ( & V_64 -> V_30 , V_9 -> V_66 ) ;
V_7 -> V_68 ++ ;
V_64 -> V_7 = V_7 ;
if ( V_9 -> V_26 )
V_9 -> V_26 ( V_64 , V_21 ) ;
}
return 0 ;
V_67:
F_42 ( V_20 , V_7 ) ;
return V_14 ;
}
void F_42 ( struct V_1 * V_20 , struct V_6 * V_7 )
{
int V_65 ;
struct V_1 * V_64 ;
for ( V_65 = 0 ; V_65 < V_7 -> V_68 ; V_65 ++ ) {
V_64 = V_20 + V_65 ;
F_23 ( & V_64 -> V_3 ) ;
F_43 ( & V_64 -> V_30 ) ;
}
}
int F_44 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = & V_7 -> V_34 -> V_5 ;
struct V_8 * V_9 = V_7 -> V_9 ;
int V_14 ;
if ( ! V_9 -> V_55 || ! V_9 -> V_47 )
goto V_69;
V_14 = F_22 ( & V_5 -> V_41 , & V_70 ) ;
if ( V_14 )
return V_14 ;
V_69:
return V_9 -> V_71 ?
F_22 ( & V_5 -> V_41 , V_9 -> V_71 ) : 0 ;
}
void F_45 ( struct V_6 * V_7 )
{
struct V_4 * V_5 = & V_7 -> V_34 -> V_5 ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_9 -> V_71 )
F_46 ( & V_5 -> V_41 , V_9 -> V_71 ) ;
F_46 ( & V_5 -> V_41 , & V_70 ) ;
}
