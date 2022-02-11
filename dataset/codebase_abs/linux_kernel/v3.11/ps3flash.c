static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
T_1 V_8 = F_3 ( V_2 , V_2 -> V_9 ,
V_3 , V_6 -> V_10 ,
V_4 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_7 . V_11 , L_1 , V_12 ,
__LINE__ , V_4 ? L_2 : L_3 , V_8 ) ;
return - V_13 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
int V_8 ;
if ( ! V_6 -> V_14 || V_6 -> V_15 < 0 )
return 0 ;
V_8 = F_1 ( V_2 , V_6 -> V_15 , 1 ) ;
if ( V_8 )
return V_8 ;
V_6 -> V_14 = false ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
int V_8 ;
if ( V_3 == V_6 -> V_15 )
return 0 ;
V_8 = F_5 ( V_2 ) ;
if ( V_8 )
return V_8 ;
V_6 -> V_15 = - 1 ;
V_8 = F_1 ( V_2 , V_3 , 0 ) ;
if ( V_8 )
return V_8 ;
V_6 -> V_15 = V_3 ;
return 0 ;
}
static T_2 F_7 ( struct V_16 * V_16 , T_2 V_17 , int V_18 )
{
struct V_1 * V_2 = V_19 ;
return F_8 ( V_16 , V_17 , V_18 , V_20 ,
V_2 -> V_21 [ V_2 -> V_22 ] . V_23 * V_2 -> V_24 ) ;
}
static T_3 F_9 ( char T_4 * V_25 , void * V_26 ,
T_5 V_27 , T_2 * V_28 )
{
struct V_1 * V_2 = V_19 ;
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
T_1 V_23 , V_29 , V_17 ;
int V_8 ;
T_5 V_30 , V_31 ;
const void * V_32 ;
F_10 ( & V_2 -> V_7 . V_11 ,
L_4 ,
V_12 , __LINE__ , V_27 , * V_28 , V_25 , V_26 ) ;
V_23 = V_2 -> V_21 [ V_2 -> V_22 ] . V_23 * V_2 -> V_24 ;
if ( * V_28 >= V_23 || ! V_27 )
return 0 ;
if ( * V_28 + V_27 > V_23 ) {
F_10 ( & V_2 -> V_7 . V_11 ,
L_5 , V_12 ,
__LINE__ , V_27 , V_23 - * V_28 ) ;
V_27 = V_23 - * V_28 ;
}
V_29 = * V_28 / V_2 -> V_33 * V_6 -> V_10 ;
V_17 = * V_28 % V_2 -> V_33 ;
V_30 = V_27 ;
do {
V_31 = F_11 ( T_1 , V_30 , V_2 -> V_33 - V_17 ) ;
V_32 = V_2 -> V_34 + V_17 ;
F_12 ( & V_6 -> V_35 ) ;
V_8 = F_6 ( V_2 , V_29 ) ;
if ( V_8 )
goto V_36;
F_10 ( & V_2 -> V_7 . V_11 ,
L_6 ,
V_12 , __LINE__ , V_31 , V_32 , V_25 , V_26 ) ;
if ( V_25 ) {
if ( F_13 ( V_25 , V_32 , V_31 ) ) {
V_8 = - V_37 ;
goto V_36;
}
V_25 += V_31 ;
}
if ( V_26 ) {
memcpy ( V_26 , V_32 , V_31 ) ;
V_26 += V_31 ;
}
F_14 ( & V_6 -> V_35 ) ;
* V_28 += V_31 ;
V_30 -= V_31 ;
V_29 += V_6 -> V_10 ;
V_17 = 0 ;
} while ( V_30 > 0 );
return V_27 ;
V_36:
F_14 ( & V_6 -> V_35 ) ;
return V_8 ;
}
static T_3 F_15 ( const char T_4 * V_25 ,
const void * V_26 , T_5 V_27 , T_2 * V_28 )
{
struct V_1 * V_2 = V_19 ;
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
T_1 V_23 , V_29 , V_17 ;
int V_8 = 0 ;
T_5 V_30 , V_31 ;
void * V_38 ;
F_10 ( & V_2 -> V_7 . V_11 ,
L_7 ,
V_12 , __LINE__ , V_27 , * V_28 , V_25 , V_26 ) ;
V_23 = V_2 -> V_21 [ V_2 -> V_22 ] . V_23 * V_2 -> V_24 ;
if ( * V_28 >= V_23 || ! V_27 )
return 0 ;
if ( * V_28 + V_27 > V_23 ) {
F_10 ( & V_2 -> V_7 . V_11 ,
L_5 , V_12 ,
__LINE__ , V_27 , V_23 - * V_28 ) ;
V_27 = V_23 - * V_28 ;
}
V_29 = * V_28 / V_2 -> V_33 * V_6 -> V_10 ;
V_17 = * V_28 % V_2 -> V_33 ;
V_30 = V_27 ;
do {
V_31 = F_11 ( T_1 , V_30 , V_2 -> V_33 - V_17 ) ;
V_38 = V_2 -> V_34 + V_17 ;
F_12 ( & V_6 -> V_35 ) ;
if ( V_31 != V_2 -> V_33 )
V_8 = F_6 ( V_2 , V_29 ) ;
else if ( V_29 != V_6 -> V_15 )
V_8 = F_5 ( V_2 ) ;
if ( V_8 )
goto V_36;
F_10 ( & V_2 -> V_7 . V_11 ,
L_8 ,
V_12 , __LINE__ , V_31 , V_25 , V_26 , V_38 ) ;
if ( V_25 ) {
if ( F_16 ( V_38 , V_25 , V_31 ) ) {
V_8 = - V_37 ;
goto V_36;
}
V_25 += V_31 ;
}
if ( V_26 ) {
memcpy ( V_38 , V_26 , V_31 ) ;
V_26 += V_31 ;
}
V_6 -> V_15 = V_29 ;
V_6 -> V_14 = true ;
F_14 ( & V_6 -> V_35 ) ;
* V_28 += V_31 ;
V_30 -= V_31 ;
V_29 += V_6 -> V_10 ;
V_17 = 0 ;
} while ( V_30 > 0 );
return V_27 ;
V_36:
F_14 ( & V_6 -> V_35 ) ;
return V_8 ;
}
static T_3 F_17 ( struct V_16 * V_16 , char T_4 * V_39 ,
T_5 V_27 , T_2 * V_28 )
{
return F_9 ( V_39 , NULL , V_27 , V_28 ) ;
}
static T_3 F_18 ( struct V_16 * V_16 , const char T_4 * V_39 ,
T_5 V_27 , T_2 * V_28 )
{
return F_15 ( V_39 , NULL , V_27 , V_28 ) ;
}
static T_3 F_19 ( void * V_39 , T_5 V_27 , T_2 V_28 )
{
return F_9 ( NULL , V_39 , V_27 , & V_28 ) ;
}
static T_3 F_20 ( const void * V_39 , T_5 V_27 ,
T_2 V_28 )
{
T_3 V_8 ;
int V_40 ;
V_8 = F_15 ( NULL , V_39 , V_27 , & V_28 ) ;
if ( V_8 < 0 )
return V_8 ;
V_40 = F_5 ( V_19 ) ;
if ( V_40 )
return V_40 ;
return V_8 ;
}
static int F_21 ( struct V_16 * V_16 , T_6 V_41 )
{
return F_5 ( V_19 ) ;
}
static int F_22 ( struct V_16 * V_16 , T_2 V_42 , T_2 V_43 , int V_44 )
{
struct V_45 * V_45 = F_23 ( V_16 ) ;
int V_46 ;
F_12 ( & V_45 -> V_47 ) ;
V_46 = F_5 ( V_19 ) ;
F_14 ( & V_45 -> V_47 ) ;
return V_46 ;
}
static T_7 F_24 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
int V_8 ;
T_1 V_15 , V_50 ;
V_8 = F_25 ( V_2 -> V_7 . V_51 , & V_15 , & V_50 ) ;
if ( V_15 != V_2 -> V_15 )
F_4 ( & V_2 -> V_7 . V_11 ,
L_9 ,
V_12 , __LINE__ , V_15 , V_2 -> V_15 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_7 . V_11 , L_10 ,
V_12 , __LINE__ , V_8 , V_50 ) ;
} else {
V_2 -> V_52 = V_50 ;
F_26 ( & V_2 -> V_53 ) ;
}
return V_54 ;
}
static int F_27 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_28 ( & V_56 -> V_11 ) ;
struct V_5 * V_6 ;
int error ;
unsigned long V_57 ;
V_57 = V_2 -> V_21 [ V_2 -> V_22 ] . V_42 * V_2 -> V_24 ;
if ( V_57 % V_58 ) {
F_4 ( & V_2 -> V_7 . V_11 ,
L_11 , V_12 ,
__LINE__ , V_57 ) ;
return - V_59 ;
}
V_57 = V_2 -> V_21 [ V_2 -> V_22 ] . V_23 * V_2 -> V_24 ;
if ( V_57 % V_58 ) {
F_4 ( & V_2 -> V_7 . V_11 ,
L_12 , V_12 ,
__LINE__ , V_57 ) ;
return - V_59 ;
}
if ( ! V_60 . V_61 )
return - V_62 ;
if ( V_19 ) {
F_4 ( & V_2 -> V_7 . V_11 ,
L_13 ) ;
return - V_63 ;
}
V_19 = V_2 ;
V_6 = F_29 ( sizeof( * V_6 ) , V_64 ) ;
if ( ! V_6 ) {
error = - V_65 ;
goto V_36;
}
F_30 ( & V_2 -> V_7 , V_6 ) ;
F_31 ( & V_6 -> V_35 ) ;
V_6 -> V_15 = - 1 ;
V_2 -> V_33 = V_60 . V_23 ;
V_2 -> V_34 = V_60 . V_61 ;
V_6 -> V_10 = V_2 -> V_33 / V_2 -> V_24 ;
error = F_32 ( V_2 , F_24 ) ;
if ( error )
goto V_66;
V_67 . V_68 = & V_2 -> V_7 . V_11 ;
error = F_33 ( & V_67 ) ;
if ( error ) {
F_4 ( & V_2 -> V_7 . V_11 , L_14 ,
V_12 , __LINE__ , error ) ;
goto V_69;
}
F_34 ( & V_2 -> V_7 . V_11 , L_15 ,
V_12 , __LINE__ , V_67 . V_70 ) ;
F_35 ( & V_71 ) ;
return 0 ;
V_69:
F_36 ( V_2 ) ;
V_66:
F_37 ( V_6 ) ;
F_30 ( & V_2 -> V_7 , NULL ) ;
V_36:
V_19 = NULL ;
return error ;
}
static int F_38 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_28 ( & V_56 -> V_11 ) ;
F_35 ( NULL ) ;
F_39 ( & V_67 ) ;
F_36 ( V_2 ) ;
F_37 ( F_2 ( & V_2 -> V_7 ) ) ;
F_30 ( & V_2 -> V_7 , NULL ) ;
V_19 = NULL ;
return 0 ;
}
static int T_8 F_40 ( void )
{
return F_41 ( & V_72 ) ;
}
static void T_9 F_42 ( void )
{
F_43 ( & V_72 ) ;
}
