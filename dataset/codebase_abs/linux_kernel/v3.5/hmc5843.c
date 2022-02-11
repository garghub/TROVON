static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 )
{
return F_2 ( V_2 ,
V_4 ,
V_3 & V_5 ) ;
}
static int F_3 ( struct V_6 * V_7 ,
int V_8 ,
int * V_9 )
{
struct V_1 * V_2 = F_4 ( V_7 -> V_10 . V_11 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
T_1 V_14 ;
F_6 ( & V_13 -> V_15 ) ;
V_14 = F_7 ( V_2 , V_16 ) ;
while ( ! ( V_14 & V_17 ) )
V_14 = F_7 ( V_2 , V_16 ) ;
V_14 = F_8 ( V_2 , V_8 ) ;
F_9 ( & V_13 -> V_15 ) ;
if ( V_14 < 0 )
return - V_18 ;
* V_9 = ( V_19 ) F_10 ( ( V_20 ) V_14 ) ;
return V_21 ;
}
static T_3 F_11 ( struct V_22 * V_10 ,
struct V_23 * V_24 ,
char * V_25 )
{
struct V_6 * V_7 = F_12 ( V_10 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
return sprintf ( V_25 , L_1 , V_13 -> V_3 ) ;
}
static T_3 F_13 ( struct V_22 * V_10 ,
struct V_23 * V_24 ,
const char * V_25 ,
T_4 V_26 )
{
struct V_6 * V_7 = F_12 ( V_10 ) ;
struct V_1 * V_2 = F_4 ( V_7 -> V_10 . V_11 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
struct V_27 * V_28 = F_14 ( V_24 ) ;
unsigned long V_3 = 0 ;
T_1 V_29 ;
int error ;
F_6 ( & V_13 -> V_15 ) ;
error = F_15 ( V_25 , 10 , & V_3 ) ;
if ( error ) {
V_26 = error ;
goto exit;
}
F_16 ( V_10 , L_2 , V_3 ) ;
if ( V_3 > V_30 ) {
V_26 = - V_18 ;
goto exit;
}
V_29 = F_2 ( V_2 , V_28 -> V_8 ,
V_3 ) ;
if ( V_29 ) {
V_26 = - V_18 ;
goto exit;
}
V_13 -> V_3 = V_3 ;
exit:
F_9 ( & V_13 -> V_15 ) ;
return V_26 ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
T_2 V_31 )
{
struct V_6 * V_7 = F_18 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
T_2 V_32 ;
V_32 = ( V_31 & V_33 ) |
( V_13 -> V_34 << V_35 ) ;
return F_2 ( V_2 , V_36 , V_32 ) ;
}
static T_3 F_19 ( struct V_22 * V_10 ,
struct V_23 * V_24 ,
char * V_25 )
{
struct V_6 * V_7 = F_12 ( V_10 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
return sprintf ( V_25 , L_1 , V_13 -> V_31 ) ;
}
static T_3 F_20 ( struct V_22 * V_10 ,
struct V_23 * V_24 ,
const char * V_25 ,
T_4 V_26 )
{
struct V_6 * V_7 = F_12 ( V_10 ) ;
struct V_1 * V_2 = F_4 ( V_7 -> V_10 . V_11 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
unsigned long V_31 = 0 ;
int error ;
error = F_15 ( V_25 , 10 , & V_31 ) ;
if ( error )
return error ;
if ( V_31 >= V_37 )
return - V_18 ;
F_6 ( & V_13 -> V_15 ) ;
F_16 ( V_10 , L_3 , V_31 ) ;
if ( F_17 ( V_2 , V_31 ) ) {
V_26 = - V_18 ;
goto exit;
}
V_13 -> V_31 = V_31 ;
exit:
F_9 ( & V_13 -> V_15 ) ;
return V_26 ;
}
static T_3 F_21 ( struct V_22 * V_10 ,
struct V_23 * V_24 ,
char * V_25 )
{
struct V_6 * V_7 = F_12 ( V_10 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
T_3 V_38 = 0 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
T_3 V_41 = sprintf ( V_25 , L_4 , V_13 -> V_42 -> V_43 [ V_39 ] ) ;
V_25 += V_41 ;
V_38 += V_41 ;
}
V_25 [ - 1 ] = '\n' ;
return V_38 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
T_2 V_34 )
{
struct V_6 * V_7 = F_18 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
T_2 V_32 ;
if ( V_34 >= V_40 ) {
F_23 ( & V_2 -> V_10 ,
L_5 ) ;
return - V_18 ;
}
V_32 = V_13 -> V_31 | ( V_34 << V_35 ) ;
return F_2 ( V_2 , V_36 , V_32 ) ;
}
static int F_24 ( struct V_12 * V_13 ,
const char * V_25 )
{
const char * const * V_44 = V_13 -> V_42 -> V_43 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_40 ; V_39 ++ ) {
if ( F_25 ( V_25 , V_44 [ V_39 ] ) )
return V_39 ;
}
return - V_18 ;
}
static T_3 F_26 ( struct V_22 * V_10 ,
struct V_23 * V_24 ,
const char * V_25 , T_4 V_26 )
{
struct V_6 * V_7 = F_12 ( V_10 ) ;
struct V_1 * V_2 = F_4 ( V_7 -> V_10 . V_11 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
int V_34 ;
V_34 = F_24 ( V_13 , V_25 ) ;
if ( V_34 < 0 ) {
F_23 ( & V_2 -> V_10 ,
L_6 ) ;
return V_34 ;
}
F_6 ( & V_13 -> V_15 ) ;
F_16 ( V_10 , L_7 , V_34 ) ;
if ( F_22 ( V_2 , V_34 ) ) {
V_26 = - V_18 ;
goto exit;
}
V_13 -> V_34 = V_34 ;
exit:
F_9 ( & V_13 -> V_15 ) ;
return V_26 ;
}
static T_3 F_27 ( struct V_22 * V_10 ,
struct V_23 * V_24 , char * V_25 )
{
struct V_6 * V_7 = F_12 ( V_10 ) ;
struct V_1 * V_2 = F_4 ( V_7 -> V_10 . V_11 ) ;
struct V_27 * V_28 = F_14 ( V_24 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
T_1 V_34 ;
V_34 = F_7 ( V_2 , V_28 -> V_8 ) ;
if ( V_34 < 0 )
return V_34 ;
V_34 = ( V_34 & V_45 ) >> V_35 ;
return sprintf ( V_25 , L_8 , V_13 -> V_42 -> V_43 [ V_34 ] ) ;
}
static T_3 F_28 ( struct V_22 * V_10 ,
struct V_23 * V_24 ,
char * V_25 )
{
T_2 V_46 ;
struct V_6 * V_7 = F_12 ( V_10 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
V_46 = V_13 -> V_46 ;
return sprintf ( V_25 , L_1 , V_13 -> V_42 -> V_47 [ V_46 ] ) ;
}
static T_3 F_29 ( struct V_22 * V_10 ,
struct V_23 * V_24 ,
const char * V_25 ,
T_4 V_26 )
{
struct V_6 * V_7 = F_12 ( V_10 ) ;
struct V_1 * V_2 = F_4 ( V_7 -> V_10 . V_11 ) ;
struct V_27 * V_28 = F_14 ( V_24 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
unsigned long V_46 = 0 ;
int error ;
F_6 ( & V_13 -> V_15 ) ;
error = F_15 ( V_25 , 10 , & V_46 ) ;
if ( error ) {
V_26 = error ;
goto exit;
}
F_16 ( V_10 , L_9 , V_46 ) ;
if ( V_46 > V_48 ) {
V_26 = - V_18 ;
goto exit;
}
V_13 -> V_46 = V_46 ;
V_46 = V_46 << V_49 ;
if ( F_2 ( V_2 , V_28 -> V_8 , V_46 ) )
V_26 = - V_18 ;
exit:
F_9 ( & V_13 -> V_15 ) ;
return V_26 ;
}
static int F_30 ( struct V_6 * V_7 ,
struct V_50 const * V_51 ,
int * V_9 , int * V_52 ,
long V_53 )
{
struct V_12 * V_13 = F_5 ( V_7 ) ;
switch ( V_53 ) {
case V_54 :
return F_3 ( V_7 ,
V_51 -> V_8 ,
V_9 ) ;
case V_55 :
* V_9 = 0 ;
* V_52 = V_13 -> V_42 -> V_56 [ V_13 -> V_46 ] ;
return V_57 ;
} ;
return - V_18 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_58 * V_59 )
{
unsigned char V_60 [ V_61 ] ;
if ( V_2 -> V_62 != V_63 )
return - V_64 ;
if ( F_32 ( V_2 , V_65 ,
V_61 , V_60 )
!= V_61 )
return - V_64 ;
if ( 0 != strncmp ( V_60 , V_66 , V_61 ) )
return - V_64 ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 ,
const struct V_67 * V_68 )
{
struct V_6 * V_7 = F_18 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
V_13 -> V_42 = & V_69 [ V_68 -> V_70 ] ;
V_7 -> V_71 = V_13 -> V_42 -> V_71 ;
V_7 -> V_72 = V_13 -> V_42 -> V_72 ;
F_17 ( V_2 , V_13 -> V_31 ) ;
F_22 ( V_2 , V_13 -> V_34 ) ;
F_1 ( V_2 , V_13 -> V_3 ) ;
F_2 ( V_2 , V_73 , V_13 -> V_46 ) ;
F_34 ( & V_13 -> V_15 ) ;
F_35 ( L_10 , V_68 -> V_74 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_67 * V_68 )
{
struct V_12 * V_13 ;
struct V_6 * V_7 ;
int V_75 = 0 ;
V_7 = F_37 ( sizeof( * V_13 ) ) ;
if ( V_7 == NULL ) {
V_75 = - V_76 ;
goto exit;
}
V_13 = F_5 ( V_7 ) ;
V_13 -> V_31 = V_77 ;
V_13 -> V_46 = V_78 ;
V_13 -> V_3 = V_79 ;
F_38 ( V_2 , V_7 ) ;
F_33 ( V_2 , V_68 ) ;
V_7 -> V_59 = & V_80 ;
V_7 -> V_74 = V_68 -> V_74 ;
V_7 -> V_10 . V_11 = & V_2 -> V_10 ;
V_7 -> V_81 = V_82 ;
V_75 = F_39 ( V_7 ) ;
if ( V_75 )
goto V_83;
return 0 ;
V_83:
F_40 ( V_7 ) ;
exit:
return V_75 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_18 ( V_2 ) ;
F_42 ( V_7 ) ;
F_1 ( V_2 , V_30 ) ;
F_40 ( V_7 ) ;
return 0 ;
}
static int F_43 ( struct V_22 * V_10 )
{
F_1 ( F_4 ( V_10 ) , V_30 ) ;
return 0 ;
}
static int F_44 ( struct V_22 * V_10 )
{
struct V_1 * V_2 = F_4 ( V_10 ) ;
struct V_6 * V_7 = F_18 ( V_2 ) ;
struct V_12 * V_13 = F_5 ( V_7 ) ;
F_1 ( V_2 , V_13 -> V_3 ) ;
return 0 ;
}
