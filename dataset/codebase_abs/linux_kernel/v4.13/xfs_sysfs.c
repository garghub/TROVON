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
int V_14 ;
int V_15 ;
V_14 = F_8 ( V_5 , 0 , & V_15 ) ;
if ( V_14 )
return V_14 ;
if ( V_15 == 1 )
V_16 . V_17 = true ;
else if ( V_15 == 0 )
V_16 . V_17 = false ;
else
return - V_18 ;
return V_8 ;
}
STATIC T_1
F_9 (
struct V_4 * V_4 ,
char * V_5 )
{
return snprintf ( V_5 , V_19 , L_1 , V_16 . V_17 ? 1 : 0 ) ;
}
STATIC T_1
F_10 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
int V_14 ;
int V_15 ;
V_14 = F_8 ( V_5 , 0 , & V_15 ) ;
if ( V_14 )
return V_14 ;
if ( V_15 < 0 || V_15 > 60 )
return - V_18 ;
V_16 . V_20 = V_15 ;
return V_8 ;
}
STATIC T_1
F_11 (
struct V_4 * V_4 ,
char * V_5 )
{
return snprintf ( V_5 , V_19 , L_1 , V_16 . V_20 ) ;
}
static inline struct V_21 *
F_12 ( struct V_4 * V_4 )
{
struct V_11 * V_12 = F_6 ( V_4 ) ;
return F_2 ( V_12 , struct V_21 , V_22 ) ;
}
STATIC T_1
F_13 (
struct V_4 * V_4 ,
char * V_5 )
{
struct V_21 * V_23 = F_12 ( V_4 ) ;
return F_14 ( V_23 -> V_24 , V_5 ) ;
}
STATIC T_1
F_15 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
int V_14 ;
int V_15 ;
struct V_21 * V_23 = F_12 ( V_4 ) ;
V_14 = F_8 ( V_5 , 0 , & V_15 ) ;
if ( V_14 )
return V_14 ;
if ( V_15 != 1 )
return - V_18 ;
F_16 ( V_23 -> V_24 ) ;
return V_8 ;
}
static inline struct V_25 *
F_17 ( struct V_4 * V_4 )
{
struct V_11 * V_12 = F_6 ( V_4 ) ;
return F_2 ( V_12 , struct V_25 , V_26 ) ;
}
STATIC T_1
F_18 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_27 ;
int V_28 ;
struct V_25 * log = F_17 ( V_4 ) ;
F_19 ( & log -> V_29 ) ;
V_27 = log -> V_30 ;
V_28 = log -> V_31 ;
F_20 ( & log -> V_29 ) ;
return snprintf ( V_5 , V_19 , L_2 , V_27 , V_28 ) ;
}
STATIC T_1
F_21 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_27 ;
int V_28 ;
struct V_25 * log = F_17 ( V_4 ) ;
F_22 ( & log -> V_32 , & V_27 , & V_28 ) ;
return snprintf ( V_5 , V_19 , L_2 , V_27 , V_28 ) ;
}
STATIC T_1
F_23 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_27 ;
int V_33 ;
struct V_25 * log = F_17 ( V_4 ) ;
F_24 ( & log -> V_34 . V_35 , & V_27 , & V_33 ) ;
return snprintf ( V_5 , V_19 , L_2 , V_27 , V_33 ) ;
}
STATIC T_1
F_25 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_27 ;
int V_33 ;
struct V_25 * log = F_17 ( V_4 ) ;
F_24 ( & log -> V_36 . V_35 , & V_27 , & V_33 ) ;
return snprintf ( V_5 , V_19 , L_2 , V_27 , V_33 ) ;
}
static inline struct V_37 *
F_26 ( struct V_4 * V_4 )
{
struct V_11 * V_12 = F_6 ( V_4 ) ;
return F_2 ( V_12 , struct V_37 , V_12 ) ;
}
static inline struct V_10 *
F_27 ( struct V_4 * V_4 )
{
struct V_11 * V_12 = F_6 ( V_4 ) ;
return F_2 ( V_12 , struct V_10 , V_38 ) ;
}
static T_1
F_28 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_39 ;
struct V_37 * V_40 = F_26 ( V_4 ) ;
if ( V_40 -> V_41 == V_42 )
V_39 = - 1 ;
else
V_39 = V_40 -> V_41 ;
return snprintf ( V_5 , V_19 , L_1 , V_39 ) ;
}
static T_1
F_29 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
struct V_37 * V_40 = F_26 ( V_4 ) ;
int V_14 ;
int V_15 ;
V_14 = F_8 ( V_5 , 0 , & V_15 ) ;
if ( V_14 )
return V_14 ;
if ( V_15 < - 1 )
return - V_18 ;
if ( V_15 == - 1 )
V_40 -> V_41 = V_42 ;
else
V_40 -> V_41 = V_15 ;
return V_8 ;
}
static T_1
F_30 (
struct V_4 * V_4 ,
char * V_5 )
{
int V_43 ;
struct V_37 * V_40 = F_26 ( V_4 ) ;
if ( V_40 -> V_44 == V_42 )
V_43 = - 1 ;
else
V_43 = F_31 ( V_40 -> V_44 ) / V_45 ;
return snprintf ( V_5 , V_19 , L_1 , V_43 ) ;
}
static T_1
F_32 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
struct V_37 * V_40 = F_26 ( V_4 ) ;
int V_14 ;
int V_15 ;
V_14 = F_8 ( V_5 , 0 , & V_15 ) ;
if ( V_14 )
return V_14 ;
if ( V_15 < - 1 || V_15 > 86400 )
return - V_18 ;
if ( V_15 == - 1 )
V_40 -> V_44 = V_42 ;
else {
V_40 -> V_44 = F_33 ( V_15 * V_45 ) ;
ASSERT ( F_33 ( V_15 * V_45 ) < V_46 ) ;
}
return V_8 ;
}
static T_1
F_34 (
struct V_4 * V_4 ,
char * V_5 )
{
struct V_10 * V_47 = F_27 ( V_4 ) ;
return snprintf ( V_5 , V_19 , L_1 , V_47 -> V_48 ) ;
}
static T_1
F_35 (
struct V_4 * V_4 ,
const char * V_5 ,
T_2 V_8 )
{
struct V_10 * V_47 = F_27 ( V_4 ) ;
int V_14 ;
int V_15 ;
V_14 = F_8 ( V_5 , 0 , & V_15 ) ;
if ( V_14 )
return V_14 ;
if ( V_15 < 0 || V_15 > 1 )
return - V_18 ;
V_47 -> V_48 = V_15 ;
return V_8 ;
}
static int
F_36 (
struct V_10 * V_47 ,
int V_49 ,
const char * V_50 ,
struct V_11 * V_51 ,
const struct V_52 V_53 [] )
{
struct V_37 * V_40 ;
int error ;
int V_54 ;
ASSERT ( V_49 < V_55 ) ;
error = F_37 ( V_51 , & V_56 ,
& V_47 -> V_38 , V_50 ) ;
if ( error )
return error ;
for ( V_54 = 0 ; V_54 < V_57 ; V_54 ++ ) {
V_40 = & V_47 -> V_58 [ V_49 ] [ V_54 ] ;
error = F_37 ( & V_40 -> V_12 , & V_59 ,
V_51 , V_53 [ V_54 ] . V_60 ) ;
if ( error )
goto V_61;
V_40 -> V_41 = V_53 [ V_54 ] . V_41 ;
if ( V_53 [ V_54 ] . V_44 == V_42 )
V_40 -> V_44 = V_42 ;
else
V_40 -> V_44 = F_33 (
V_53 [ V_54 ] . V_44 * V_45 ) ;
}
return 0 ;
V_61:
for ( V_54 -- ; V_54 >= 0 ; V_54 -- ) {
V_40 = & V_47 -> V_58 [ V_49 ] [ V_54 ] ;
F_38 ( & V_40 -> V_12 ) ;
}
F_38 ( V_51 ) ;
return error ;
}
int
F_39 (
struct V_10 * V_47 )
{
int error ;
error = F_37 ( & V_47 -> V_38 , & V_56 ,
& V_47 -> V_13 , L_3 ) ;
if ( error )
return error ;
error = F_40 ( & V_47 -> V_38 . V_4 ,
F_41 ( V_62 ) ) ;
if ( error )
goto V_61;
error = F_36 ( V_47 , V_63 ,
L_4 , & V_47 -> V_64 ,
V_65 ) ;
if ( error )
goto V_61;
return 0 ;
V_61:
F_38 ( & V_47 -> V_38 ) ;
return error ;
}
void
F_42 (
struct V_10 * V_47 )
{
struct V_37 * V_40 ;
int V_54 , V_66 ;
for ( V_54 = 0 ; V_54 < V_55 ; V_54 ++ ) {
for ( V_66 = 0 ; V_66 < V_57 ; V_66 ++ ) {
V_40 = & V_47 -> V_58 [ V_54 ] [ V_66 ] ;
F_38 ( & V_40 -> V_12 ) ;
}
}
F_38 ( & V_47 -> V_64 ) ;
F_38 ( & V_47 -> V_38 ) ;
}
struct V_37 *
F_43 (
struct V_10 * V_47 ,
int V_67 ,
int error )
{
struct V_37 * V_40 ;
if ( error < 0 )
error = - error ;
switch ( error ) {
case V_68 :
V_40 = & V_47 -> V_58 [ V_67 ] [ V_69 ] ;
break;
case V_70 :
V_40 = & V_47 -> V_58 [ V_67 ] [ V_71 ] ;
break;
case V_72 :
V_40 = & V_47 -> V_58 [ V_67 ] [ V_73 ] ;
break;
default:
V_40 = & V_47 -> V_58 [ V_67 ] [ V_74 ] ;
break;
}
return V_40 ;
}
