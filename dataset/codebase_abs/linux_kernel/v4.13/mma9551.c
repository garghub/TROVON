static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
int * V_5 )
{
T_1 V_6 , V_7 , V_8 ;
T_2 V_9 ;
int V_10 ;
switch ( V_4 -> V_11 ) {
case V_12 :
V_9 = V_13 ;
V_6 = V_14 ;
break;
case V_15 :
V_9 = V_16 ;
V_6 = V_17 ;
break;
case V_18 :
V_9 = V_19 ;
V_6 = V_20 ;
break;
default:
return - V_21 ;
}
V_10 = F_2 ( V_2 , true ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_3 ( V_2 , V_22 ,
V_9 , & V_7 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_3 ( V_2 , V_22 ,
V_24 , & V_8 ) ;
if ( V_10 < 0 )
goto V_23;
V_7 &= ~ V_25 ;
V_8 = ( V_8 >> V_6 ) & 0x03 ;
if ( V_8 == 1 || V_8 == 3 )
* V_5 = 90 * ( V_8 + 1 ) - V_7 ;
else
* V_5 = V_7 + 90 * V_8 ;
V_10 = V_26 ;
V_23:
F_2 ( V_2 , false ) ;
return V_10 ;
}
static int F_4 ( struct V_27 * V_28 ,
struct V_3 const * V_4 ,
int * V_5 , int * V_29 , long V_30 )
{
struct V_31 * V_32 = F_5 ( V_28 ) ;
int V_10 ;
switch ( V_30 ) {
case V_33 :
switch ( V_4 -> type ) {
case V_34 :
F_6 ( & V_32 -> V_35 ) ;
V_10 = F_1 ( V_32 -> V_2 , V_4 , V_5 ) ;
F_7 ( & V_32 -> V_35 ) ;
return V_10 ;
default:
return - V_21 ;
}
case V_36 :
switch ( V_4 -> type ) {
case V_37 :
F_6 ( & V_32 -> V_35 ) ;
V_10 = F_8 ( V_32 -> V_2 ,
V_4 , V_5 , V_29 ) ;
F_7 ( & V_32 -> V_35 ) ;
return V_10 ;
default:
return - V_21 ;
}
case V_38 :
switch ( V_4 -> type ) {
case V_37 :
return F_9 ( V_5 , V_29 ) ;
default:
return - V_21 ;
}
default:
return - V_21 ;
}
}
static int F_10 ( struct V_27 * V_28 ,
const struct V_3 * V_4 ,
enum V_39 type ,
enum V_40 V_41 )
{
struct V_31 * V_32 = F_5 ( V_28 ) ;
switch ( V_4 -> type ) {
case V_34 :
return V_32 -> V_42 [ V_4 -> V_11 - 1 ] ;
default:
return - V_21 ;
}
}
static int F_11 ( struct V_27 * V_28 ,
enum V_43 V_44 ,
int V_45 )
{
struct V_31 * V_32 = F_5 ( V_28 ) ;
enum V_46 V_47 ;
int V_10 ;
V_47 = V_44 - 1 ;
if ( V_32 -> V_42 [ V_47 ] == V_45 )
return 0 ;
if ( V_45 == 0 ) {
V_10 = F_12 ( V_32 -> V_2 ,
(enum V_48 ) V_47 ,
V_49 , 0 , 0 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_2 ( V_32 -> V_2 , false ) ;
if ( V_10 < 0 )
return V_10 ;
} else {
int V_50 ;
switch ( V_44 ) {
case V_12 :
V_50 = 7 + 8 * V_13 ;
break;
case V_15 :
V_50 = 7 + 8 * V_16 ;
break;
case V_18 :
V_50 = 7 + 8 * V_19 ;
break;
default:
return - V_21 ;
}
V_10 = F_2 ( V_32 -> V_2 , true ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_12 ( V_32 -> V_2 ,
(enum V_48 ) V_47 ,
V_22 , V_50 , 0 ) ;
if ( V_10 < 0 ) {
F_2 ( V_32 -> V_2 , false ) ;
return V_10 ;
}
}
V_32 -> V_42 [ V_47 ] = V_45 ;
return V_10 ;
}
static int F_13 ( struct V_27 * V_28 ,
const struct V_3 * V_4 ,
enum V_39 type ,
enum V_40 V_41 ,
int V_45 )
{
struct V_31 * V_32 = F_5 ( V_28 ) ;
int V_10 ;
switch ( V_4 -> type ) {
case V_34 :
F_6 ( & V_32 -> V_35 ) ;
V_10 = F_11 ( V_28 ,
V_4 -> V_11 , V_45 ) ;
F_7 ( & V_32 -> V_35 ) ;
return V_10 ;
default:
return - V_21 ;
}
}
static int F_14 ( struct V_27 * V_28 ,
const struct V_3 * V_4 ,
enum V_39 type ,
enum V_40 V_41 ,
enum V_51 V_52 ,
int V_5 , int V_29 )
{
struct V_31 * V_32 = F_5 ( V_28 ) ;
int V_10 ;
switch ( V_4 -> type ) {
case V_34 :
if ( V_29 != 0 || V_5 < 1 || V_5 > 10 )
return - V_21 ;
F_6 ( & V_32 -> V_35 ) ;
V_10 = F_15 ( V_32 -> V_2 ,
V_22 ,
V_53 ,
V_54 ,
V_5 ) ;
F_7 ( & V_32 -> V_35 ) ;
return V_10 ;
default:
return - V_21 ;
}
}
static int F_16 ( struct V_27 * V_28 ,
const struct V_3 * V_4 ,
enum V_39 type ,
enum V_40 V_41 ,
enum V_51 V_52 ,
int * V_5 , int * V_29 )
{
struct V_31 * V_32 = F_5 ( V_28 ) ;
int V_10 ;
T_1 V_55 ;
switch ( V_4 -> type ) {
case V_34 :
F_6 ( & V_32 -> V_35 ) ;
V_10 = F_17 ( V_32 -> V_2 ,
V_22 ,
V_53 , & V_55 ) ;
F_7 ( & V_32 -> V_35 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_5 = V_55 & V_54 ;
* V_29 = 0 ;
return V_26 ;
default:
return - V_21 ;
}
}
static T_3 F_18 ( int V_56 , void * V_57 )
{
struct V_27 * V_28 = V_57 ;
struct V_31 * V_32 = F_5 ( V_28 ) ;
int V_58 , V_10 , V_47 = - 1 ;
T_2 V_59 ;
T_1 V_5 ;
F_6 ( & V_32 -> V_35 ) ;
for ( V_58 = 0 ; V_58 < 3 ; V_58 ++ )
if ( V_56 == V_32 -> V_60 [ V_58 ] ) {
V_47 = V_58 ;
break;
}
if ( V_47 == - 1 ) {
F_19 ( & V_32 -> V_2 -> V_61 ,
L_1 , V_32 -> V_60 [ 3 ] ) ;
goto V_62;
}
switch ( V_47 ) {
case V_63 :
V_59 = V_13 ;
break;
case V_64 :
V_59 = V_16 ;
break;
case V_65 :
V_59 = V_19 ;
break;
}
V_10 = F_3 ( V_32 -> V_2 , V_22 ,
V_59 , & V_5 ) ;
if ( V_10 < 0 ) {
F_20 ( & V_32 -> V_2 -> V_61 ,
L_2 , V_10 ) ;
goto V_62;
}
F_21 ( V_28 ,
F_22 ( V_34 , 0 , ( V_47 + 1 ) ,
V_66 , V_67 ) ,
F_23 ( V_28 ) ) ;
V_62:
F_7 ( & V_32 -> V_35 ) ;
return V_68 ;
}
static int F_24 ( struct V_31 * V_32 )
{
int V_10 ;
V_10 = F_25 ( V_32 -> V_2 ) ;
if ( V_10 )
return V_10 ;
return F_26 ( V_32 -> V_2 , true ) ;
}
static int F_27 ( struct V_27 * V_28 )
{
struct V_69 * V_70 ;
int V_58 , V_10 ;
struct V_31 * V_32 = F_5 ( V_28 ) ;
struct V_71 * V_61 = & V_32 -> V_2 -> V_61 ;
for ( V_58 = 0 ; V_58 < V_72 ; V_58 ++ ) {
V_70 = F_28 ( V_61 , NULL , V_58 , V_73 ) ;
if ( F_29 ( V_70 ) ) {
F_20 ( V_61 , L_3 ) ;
return F_30 ( V_70 ) ;
}
V_10 = F_31 ( V_70 ) ;
if ( V_10 < 0 )
return V_10 ;
V_32 -> V_60 [ V_58 ] = V_10 ;
V_10 = F_32 ( V_61 , V_32 -> V_60 [ V_58 ] ,
NULL , F_18 ,
V_74 | V_75 ,
V_76 , V_28 ) ;
if ( V_10 < 0 ) {
F_20 ( V_61 , L_4 , V_32 -> V_60 [ V_58 ] ) ;
return V_10 ;
}
F_33 ( V_61 , L_5 ,
F_34 ( V_70 ) , V_32 -> V_60 [ V_58 ] ) ;
}
return 0 ;
}
static const char * F_35 ( struct V_71 * V_61 )
{
const struct V_77 * V_78 ;
V_78 = F_36 ( V_61 -> V_79 -> V_80 , V_61 ) ;
if ( ! V_78 )
return NULL ;
return F_37 ( V_61 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
const struct V_81 * V_78 )
{
struct V_31 * V_32 ;
struct V_27 * V_28 ;
const char * V_82 = NULL ;
int V_10 ;
V_28 = F_39 ( & V_2 -> V_61 , sizeof( * V_32 ) ) ;
if ( ! V_28 )
return - V_83 ;
V_32 = F_5 ( V_28 ) ;
F_40 ( V_2 , V_28 ) ;
V_32 -> V_2 = V_2 ;
if ( V_78 )
V_82 = V_78 -> V_82 ;
else if ( F_41 ( & V_2 -> V_61 ) )
V_82 = F_35 ( & V_2 -> V_61 ) ;
V_10 = F_24 ( V_32 ) ;
if ( V_10 < 0 )
return V_10 ;
F_42 ( & V_32 -> V_35 ) ;
V_28 -> V_61 . V_84 = & V_2 -> V_61 ;
V_28 -> V_85 = V_86 ;
V_28 -> V_87 = F_43 ( V_86 ) ;
V_28 -> V_82 = V_82 ;
V_28 -> V_88 = V_89 ;
V_28 -> V_52 = & V_90 ;
V_10 = F_27 ( V_28 ) ;
if ( V_10 < 0 )
goto V_23;
V_10 = F_44 ( & V_2 -> V_61 ) ;
if ( V_10 < 0 )
goto V_23;
F_45 ( & V_2 -> V_61 ) ;
F_46 ( & V_2 -> V_61 ,
V_91 ) ;
F_47 ( & V_2 -> V_61 ) ;
V_10 = F_48 ( V_28 ) ;
if ( V_10 < 0 ) {
F_20 ( & V_2 -> V_61 , L_6 ) ;
goto V_23;
}
return 0 ;
V_23:
F_26 ( V_2 , false ) ;
return V_10 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_27 * V_28 = F_50 ( V_2 ) ;
struct V_31 * V_32 = F_5 ( V_28 ) ;
F_51 ( V_28 ) ;
F_52 ( & V_2 -> V_61 ) ;
F_53 ( & V_2 -> V_61 ) ;
F_54 ( & V_2 -> V_61 ) ;
F_6 ( & V_32 -> V_35 ) ;
F_26 ( V_32 -> V_2 , false ) ;
F_7 ( & V_32 -> V_35 ) ;
return 0 ;
}
static int F_55 ( struct V_71 * V_61 )
{
struct V_27 * V_28 = F_50 ( F_56 ( V_61 ) ) ;
struct V_31 * V_32 = F_5 ( V_28 ) ;
int V_10 ;
F_6 ( & V_32 -> V_35 ) ;
V_10 = F_26 ( V_32 -> V_2 , false ) ;
F_7 ( & V_32 -> V_35 ) ;
if ( V_10 < 0 ) {
F_20 ( & V_32 -> V_2 -> V_61 , L_7 ) ;
return - V_92 ;
}
return 0 ;
}
static int F_57 ( struct V_71 * V_61 )
{
struct V_27 * V_28 = F_50 ( F_56 ( V_61 ) ) ;
struct V_31 * V_32 = F_5 ( V_28 ) ;
int V_10 ;
V_10 = F_26 ( V_32 -> V_2 , true ) ;
if ( V_10 < 0 )
return V_10 ;
F_58 ( V_93 ) ;
return 0 ;
}
static int F_59 ( struct V_71 * V_61 )
{
struct V_27 * V_28 = F_50 ( F_56 ( V_61 ) ) ;
struct V_31 * V_32 = F_5 ( V_28 ) ;
int V_10 ;
F_6 ( & V_32 -> V_35 ) ;
V_10 = F_26 ( V_32 -> V_2 , false ) ;
F_7 ( & V_32 -> V_35 ) ;
return V_10 ;
}
static int F_60 ( struct V_71 * V_61 )
{
struct V_27 * V_28 = F_50 ( F_56 ( V_61 ) ) ;
struct V_31 * V_32 = F_5 ( V_28 ) ;
int V_10 ;
F_6 ( & V_32 -> V_35 ) ;
V_10 = F_26 ( V_32 -> V_2 , true ) ;
F_7 ( & V_32 -> V_35 ) ;
return V_10 ;
}
