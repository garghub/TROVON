static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 ;
char V_11 [ V_12 ] ;
unsigned int V_13 ;
int V_14 ;
F_3 ( V_11 , V_7 -> V_15 ,
false , false ) ;
V_14 = F_4 ( V_9 -> V_16 , F_5 ( V_17 ) , V_11 ) ;
if ( V_14 ) {
F_6 ( V_9 -> V_18 -> V_2 , L_1 ) ;
return V_14 ;
}
F_7 ( V_11 , & V_13 , NULL , NULL ) ;
return sprintf ( V_5 , L_2 , V_13 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 ;
char V_11 [ V_12 ] ;
unsigned int V_19 ;
int V_14 ;
F_3 ( V_11 , V_7 -> V_15 ,
false , false ) ;
V_14 = F_4 ( V_9 -> V_16 , F_5 ( V_17 ) , V_11 ) ;
if ( V_14 ) {
F_6 ( V_9 -> V_18 -> V_2 , L_1 ) ;
return V_14 ;
}
F_7 ( V_11 , NULL , & V_19 , NULL ) ;
return sprintf ( V_5 , L_2 , V_19 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_20 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 ;
char V_11 [ V_12 ] ;
unsigned long V_21 ;
int V_14 ;
V_14 = F_10 ( V_5 , 10 , & V_21 ) ;
if ( V_14 )
return V_14 ;
if ( V_21 != 1 )
return - V_22 ;
F_3 ( V_11 , V_7 -> V_15 , true , true ) ;
V_14 = F_11 ( V_9 -> V_16 , F_5 ( V_17 ) , V_11 ) ;
if ( V_14 ) {
F_6 ( V_9 -> V_18 -> V_2 , L_3 ) ;
return V_14 ;
}
return V_20 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 ;
char V_23 [ V_24 ] ;
int V_14 ;
F_13 ( V_23 , V_7 -> V_15 ) ;
V_14 = F_4 ( V_9 -> V_16 , F_5 ( V_25 ) , V_23 ) ;
if ( V_14 ) {
F_6 ( V_9 -> V_18 -> V_2 , L_4 ) ;
return V_14 ;
}
return sprintf ( V_5 , L_2 , F_14 ( V_23 ) ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 ;
char V_26 [ V_27 ] ;
int V_14 ;
F_16 ( V_26 , V_7 -> V_15 , 0 ) ;
V_14 = F_4 ( V_9 -> V_16 , F_5 ( V_28 ) , V_26 ) ;
if ( V_14 ) {
F_6 ( V_9 -> V_18 -> V_2 , L_5 ) ;
return V_14 ;
}
return sprintf ( V_5 , L_2 ,
F_17 ( V_26 ) ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_20 )
{
struct V_6 * V_7 =
F_2 ( V_4 , struct V_6 , V_8 ) ;
struct V_9 * V_9 = V_7 -> V_10 ;
char V_26 [ V_27 ] ;
unsigned long V_21 ;
int V_14 ;
V_14 = F_10 ( V_5 , 10 , & V_21 ) ;
if ( V_14 )
return V_14 ;
if ( V_21 > 255 )
return - V_22 ;
F_16 ( V_26 , V_7 -> V_15 , V_21 ) ;
V_14 = F_11 ( V_9 -> V_16 , F_5 ( V_28 ) , V_26 ) ;
if ( V_14 ) {
F_6 ( V_9 -> V_18 -> V_2 , L_6 ) ;
return V_14 ;
}
return V_20 ;
}
static void F_19 ( struct V_9 * V_9 ,
enum V_29 V_30 ,
unsigned int V_15 , unsigned int V_31 ) {
struct V_6 * V_6 ;
unsigned int V_32 ;
V_32 = V_9 -> V_33 ;
V_6 = & V_9 -> V_34 [ V_32 ] ;
switch ( V_30 ) {
case V_35 :
V_6 -> V_8 . V_36 = F_1 ;
V_6 -> V_8 . V_4 . V_37 = V_38 ;
snprintf ( V_6 -> V_39 , sizeof( V_6 -> V_39 ) ,
L_7 , V_31 + 1 ) ;
break;
case V_40 :
V_6 -> V_8 . V_36 = F_8 ;
V_6 -> V_8 . V_4 . V_37 = V_38 ;
snprintf ( V_6 -> V_39 , sizeof( V_6 -> V_39 ) ,
L_8 , V_31 + 1 ) ;
break;
case V_41 :
V_6 -> V_8 . V_42 = F_9 ;
V_6 -> V_8 . V_4 . V_37 = V_43 ;
snprintf ( V_6 -> V_39 , sizeof( V_6 -> V_39 ) ,
L_9 , V_31 + 1 ) ;
break;
case V_44 :
V_6 -> V_8 . V_36 = F_12 ;
V_6 -> V_8 . V_4 . V_37 = V_38 ;
snprintf ( V_6 -> V_39 , sizeof( V_6 -> V_39 ) ,
L_10 , V_31 + 1 ) ;
break;
case V_45 :
V_6 -> V_8 . V_36 = F_15 ;
V_6 -> V_8 . V_42 = F_18 ;
V_6 -> V_8 . V_4 . V_37 = V_43 | V_38 ;
snprintf ( V_6 -> V_39 , sizeof( V_6 -> V_39 ) ,
L_11 , V_31 + 1 ) ;
break;
default:
F_20 ( 1 ) ;
}
V_6 -> V_15 = V_15 ;
V_6 -> V_10 = V_9 ;
V_6 -> V_8 . V_4 . V_39 = V_6 -> V_39 ;
F_21 ( & V_6 -> V_8 . V_4 ) ;
V_9 -> V_46 [ V_32 ] = & V_6 -> V_8 . V_4 ;
V_9 -> V_33 ++ ;
}
static int F_22 ( struct V_9 * V_9 )
{
char V_47 [ V_48 ] = { 0 } ;
char V_11 [ V_12 ] ;
T_3 V_49 ;
int V_50 ;
int V_14 ;
V_14 = F_4 ( V_9 -> V_16 , F_5 ( V_51 ) , V_47 ) ;
if ( V_14 ) {
F_6 ( V_9 -> V_18 -> V_2 , L_12 ) ;
return V_14 ;
}
V_49 = F_23 ( V_47 ) ;
for ( V_50 = 0 ; V_50 < V_49 ; V_50 ++ ) {
F_3 ( V_11 , V_50 , true , true ) ;
V_14 = F_11 ( V_9 -> V_16 ,
F_5 ( V_17 ) , V_11 ) ;
if ( V_14 ) {
F_6 ( V_9 -> V_18 -> V_2 , L_13 ,
V_50 ) ;
return V_14 ;
}
F_19 ( V_9 ,
V_35 , V_50 , V_50 ) ;
F_19 ( V_9 ,
V_40 , V_50 , V_50 ) ;
F_19 ( V_9 ,
V_41 , V_50 , V_50 ) ;
}
return 0 ;
}
static int F_24 ( struct V_9 * V_9 )
{
char V_52 [ V_53 ] = { 0 } ;
enum V_54 V_55 ;
unsigned int V_15 ;
unsigned int V_31 ;
T_4 V_56 ;
T_3 V_57 ;
int V_14 ;
V_14 = F_4 ( V_9 -> V_16 , F_5 ( V_58 ) , V_52 ) ;
if ( V_14 ) {
F_6 ( V_9 -> V_18 -> V_2 , L_14 ) ;
return V_14 ;
}
F_25 ( V_52 , & V_55 , & V_56 , & V_57 ) ;
V_31 = 0 ;
for ( V_15 = 0 ; V_15 < V_59 ; V_15 ++ ) {
if ( V_56 & F_26 ( V_15 ) )
F_19 ( V_9 ,
V_44 ,
V_15 , V_31 ++ ) ;
}
V_31 = 0 ;
for ( V_15 = 0 ; V_15 < V_60 ; V_15 ++ ) {
if ( V_57 & F_26 ( V_15 ) )
F_19 ( V_9 ,
V_45 ,
V_15 , V_31 ++ ) ;
}
return 0 ;
}
int F_27 ( struct V_61 * V_61 ,
const struct V_62 * V_62 ,
struct V_9 * * V_63 )
{
struct V_9 * V_9 ;
struct V_1 * V_64 ;
int V_14 ;
V_9 = F_28 ( V_62 -> V_2 , sizeof( * V_9 ) ,
V_65 ) ;
if ( ! V_9 )
return - V_66 ;
V_9 -> V_16 = V_61 ;
V_9 -> V_18 = V_62 ;
V_14 = F_22 ( V_9 ) ;
if ( V_14 )
goto V_67;
V_14 = F_24 ( V_9 ) ;
if ( V_14 )
goto V_68;
V_9 -> V_69 [ 0 ] = & V_9 -> V_70 ;
V_9 -> V_70 . V_46 = V_9 -> V_46 ;
V_64 = F_29 ( V_62 -> V_2 ,
L_15 ,
V_9 ,
V_9 -> V_69 ) ;
if ( F_30 ( V_64 ) ) {
V_14 = F_31 ( V_64 ) ;
goto V_71;
}
V_9 -> V_64 = V_64 ;
* V_63 = V_9 ;
return 0 ;
V_71:
V_68:
V_67:
return V_14 ;
}
