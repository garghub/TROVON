static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
STATIC T_1
F_3 (
struct V_4 * V_4 ,
struct V_2 * V_3 ,
char * V_5 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return V_6 -> V_7 ? V_6 -> V_7 ( V_4 , V_5 ) : 0 ;
}
STATIC T_1
F_4 (
struct V_4 * V_4 ,
struct V_2 * V_3 ,
const char * V_5 ,
T_2 V_8 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
return V_6 -> V_9 ? V_6 -> V_9 ( V_4 , V_5 , V_8 ) : 0 ;
}
static inline struct V_10 *
F_5 ( struct V_4 * V_4 )
{
struct V_11 * V_12 = F_6 ( V_4 ) ;
return F_2 ( V_12 , struct V_10 , V_13 ) ;
}
STATIC T_1
F_7 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
struct V_10 * V_14 = F_5 ( V_4 ) ;
int V_15 ;
int V_16 ;
V_15 = F_8 ( V_5 , 0 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 == 1 )
V_14 -> V_17 = true ;
else if ( V_16 == 0 )
V_14 -> V_17 = false ;
else
return - V_18 ;
return V_8 ;
}
STATIC T_1
F_9 (
struct V_4 * V_4 ,
char * V_5 )
{
struct V_10 * V_14 = F_5 ( V_4 ) ;
return snprintf ( V_5 , V_19 , L_1 , V_14 -> V_17 ? 1 : 0 ) ;
}
STATIC T_1
F_10 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
int V_15 ;
int V_16 ;
V_15 = F_8 ( V_5 , 0 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 < 0 || V_16 > 60 )
return - V_18 ;
V_20 . V_21 = V_16 ;
return V_8 ;
}
STATIC T_1
F_11 (
struct V_4 * V_4 ,
char * V_5 )
{
return snprintf ( V_5 , V_19 , L_1 , V_20 . V_21 ) ;
}
static inline struct V_22 *
F_12 ( struct V_4 * V_4 )
{
struct V_11 * V_12 = F_6 ( V_4 ) ;
return F_2 ( V_12 , struct V_22 , V_23 ) ;
}
STATIC T_1
F_13 (
struct V_4 * V_4 ,
char * V_5 )
{
struct V_22 * V_24 = F_12 ( V_4 ) ;
return F_14 ( V_24 -> V_25 , V_5 ) ;
}
STATIC T_1
F_15 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
int V_15 ;
int V_16 ;
struct V_22 * V_24 = F_12 ( V_4 ) ;
V_15 = F_8 ( V_5 , 0 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 != 1 )
return - V_18 ;
F_16 ( V_24 -> V_25 ) ;
return V_8 ;
}
static inline struct V_26 *
F_17 ( struct V_4 * V_4 )
{
struct V_11 * V_12 = F_6 ( V_4 ) ;
return F_2 ( V_12 , struct V_26 , V_27 ) ;
}
STATIC T_1
F_18 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_28 ;
int V_29 ;
struct V_26 * log = F_17 ( V_4 ) ;
F_19 ( & log -> V_30 ) ;
V_28 = log -> V_31 ;
V_29 = log -> V_32 ;
F_20 ( & log -> V_30 ) ;
return snprintf ( V_5 , V_19 , L_2 , V_28 , V_29 ) ;
}
STATIC T_1
F_21 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_28 ;
int V_29 ;
struct V_26 * log = F_17 ( V_4 ) ;
F_22 ( & log -> V_33 , & V_28 , & V_29 ) ;
return snprintf ( V_5 , V_19 , L_2 , V_28 , V_29 ) ;
}
STATIC T_1
F_23 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_28 ;
int V_34 ;
struct V_26 * log = F_17 ( V_4 ) ;
F_24 ( & log -> V_35 . V_36 , & V_28 , & V_34 ) ;
return snprintf ( V_5 , V_19 , L_2 , V_28 , V_34 ) ;
}
STATIC T_1
F_25 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_28 ;
int V_34 ;
struct V_26 * log = F_17 ( V_4 ) ;
F_24 ( & log -> V_37 . V_36 , & V_28 , & V_34 ) ;
return snprintf ( V_5 , V_19 , L_2 , V_28 , V_34 ) ;
}
STATIC T_1
F_26 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
struct V_26 * log = F_17 ( V_4 ) ;
int V_15 ;
T_3 V_16 ;
V_15 = F_27 ( V_5 , 0 , & V_16 ) ;
if ( V_15 )
return V_15 ;
log -> V_38 = V_16 ;
return V_8 ;
}
STATIC T_1
F_28 (
struct V_4 * V_4 ,
char * V_5 )
{
struct V_26 * log = F_17 ( V_4 ) ;
return snprintf ( V_5 , V_19 , L_1 , log -> V_38 ) ;
}
static inline struct V_39 *
F_29 ( struct V_4 * V_4 )
{
struct V_11 * V_12 = F_6 ( V_4 ) ;
return F_2 ( V_12 , struct V_39 , V_12 ) ;
}
static inline struct V_10 *
F_30 ( struct V_4 * V_4 )
{
struct V_11 * V_12 = F_6 ( V_4 ) ;
return F_2 ( V_12 , struct V_10 , V_40 ) ;
}
static T_1
F_31 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_41 ;
struct V_39 * V_42 = F_29 ( V_4 ) ;
if ( V_42 -> V_43 == V_44 )
V_41 = - 1 ;
else
V_41 = V_42 -> V_45 ;
return snprintf ( V_5 , V_19 , L_1 , V_41 ) ;
}
static T_1
F_32 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
struct V_39 * V_42 = F_29 ( V_4 ) ;
int V_15 ;
int V_16 ;
V_15 = F_8 ( V_5 , 0 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 < - 1 )
return - V_18 ;
if ( V_16 == - 1 )
V_42 -> V_43 = V_44 ;
else
V_42 -> V_45 = V_16 ;
return V_8 ;
}
static T_1
F_33 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_46 ;
struct V_39 * V_42 = F_29 ( V_4 ) ;
if ( V_42 -> V_43 == V_44 )
V_46 = - 1 ;
else
V_46 = F_34 ( V_42 -> V_43 ) / V_47 ;
return snprintf ( V_5 , V_19 , L_1 , V_46 ) ;
}
static T_1
F_35 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
struct V_39 * V_42 = F_29 ( V_4 ) ;
int V_15 ;
int V_16 ;
V_15 = F_8 ( V_5 , 0 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 < - 1 || V_16 > 86400 )
return - V_18 ;
if ( V_16 == - 1 )
V_42 -> V_43 = V_44 ;
else {
V_42 -> V_43 = F_36 ( V_16 * V_47 ) ;
ASSERT ( F_36 ( V_16 * V_47 ) < V_48 ) ;
}
return V_8 ;
}
static T_1
F_37 (
struct V_4 * V_4 ,
char * V_5 )
{
struct V_10 * V_14 = F_30 ( V_4 ) ;
return snprintf ( V_5 , V_19 , L_1 , V_14 -> V_49 ) ;
}
static T_1
F_38 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
struct V_10 * V_14 = F_30 ( V_4 ) ;
int V_15 ;
int V_16 ;
V_15 = F_8 ( V_5 , 0 , & V_16 ) ;
if ( V_15 )
return V_15 ;
if ( V_16 < 0 || V_16 > 1 )
return - V_18 ;
V_14 -> V_49 = V_16 ;
return V_8 ;
}
static int
F_39 (
struct V_10 * V_14 ,
int V_50 ,
const char * V_51 ,
struct V_11 * V_52 ,
const struct V_53 V_54 [] )
{
struct V_39 * V_42 ;
int error ;
int V_55 ;
ASSERT ( V_50 < V_56 ) ;
error = F_40 ( V_52 , & V_57 ,
& V_14 -> V_40 , V_51 ) ;
if ( error )
return error ;
for ( V_55 = 0 ; V_55 < V_58 ; V_55 ++ ) {
V_42 = & V_14 -> V_59 [ V_50 ] [ V_55 ] ;
error = F_40 ( & V_42 -> V_12 , & V_60 ,
V_52 , V_54 [ V_55 ] . V_61 ) ;
if ( error )
goto V_62;
V_42 -> V_45 = V_54 [ V_55 ] . V_45 ;
if ( V_54 [ V_55 ] . V_43 == V_44 )
V_42 -> V_43 = V_44 ;
else
V_42 -> V_43 = F_36 (
V_54 [ V_55 ] . V_43 * V_47 ) ;
}
return 0 ;
V_62:
for ( V_55 -- ; V_55 >= 0 ; V_55 -- ) {
V_42 = & V_14 -> V_59 [ V_50 ] [ V_55 ] ;
F_41 ( & V_42 -> V_12 ) ;
}
F_41 ( V_52 ) ;
return error ;
}
int
F_42 (
struct V_10 * V_14 )
{
int error ;
error = F_40 ( & V_14 -> V_40 , & V_57 ,
& V_14 -> V_13 , L_3 ) ;
if ( error )
return error ;
error = F_43 ( & V_14 -> V_40 . V_4 ,
F_44 ( V_63 ) ) ;
if ( error )
goto V_62;
error = F_39 ( V_14 , V_64 ,
L_4 , & V_14 -> V_65 ,
V_66 ) ;
if ( error )
goto V_62;
return 0 ;
V_62:
F_41 ( & V_14 -> V_40 ) ;
return error ;
}
void
F_45 (
struct V_10 * V_14 )
{
struct V_39 * V_42 ;
int V_55 , V_67 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
for ( V_67 = 0 ; V_67 < V_58 ; V_67 ++ ) {
V_42 = & V_14 -> V_59 [ V_55 ] [ V_67 ] ;
F_41 ( & V_42 -> V_12 ) ;
}
}
F_41 ( & V_14 -> V_65 ) ;
F_41 ( & V_14 -> V_40 ) ;
}
struct V_39 *
F_46 (
struct V_10 * V_14 ,
int V_68 ,
int error )
{
struct V_39 * V_42 ;
if ( error < 0 )
error = - error ;
switch ( error ) {
case V_69 :
V_42 = & V_14 -> V_59 [ V_68 ] [ V_70 ] ;
break;
case V_71 :
V_42 = & V_14 -> V_59 [ V_68 ] [ V_72 ] ;
break;
case V_73 :
V_42 = & V_14 -> V_59 [ V_68 ] [ V_74 ] ;
break;
default:
V_42 = & V_14 -> V_59 [ V_68 ] [ V_75 ] ;
break;
}
return V_42 ;
}
