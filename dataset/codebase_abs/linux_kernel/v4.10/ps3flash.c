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
F_24 ( V_45 ) ;
V_46 = F_5 ( V_19 ) ;
F_25 ( V_45 ) ;
return V_46 ;
}
static T_7 F_26 ( int V_47 , void * V_48 )
{
struct V_1 * V_2 = V_48 ;
int V_8 ;
T_1 V_15 , V_49 ;
V_8 = F_27 ( V_2 -> V_7 . V_50 , & V_15 , & V_49 ) ;
if ( V_15 != V_2 -> V_15 )
F_4 ( & V_2 -> V_7 . V_11 ,
L_9 ,
V_12 , __LINE__ , V_15 , V_2 -> V_15 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_7 . V_11 , L_10 ,
V_12 , __LINE__ , V_8 , V_49 ) ;
} else {
V_2 -> V_51 = V_49 ;
F_28 ( & V_2 -> V_52 ) ;
}
return V_53 ;
}
static int F_29 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_30 ( & V_55 -> V_11 ) ;
struct V_5 * V_6 ;
int error ;
unsigned long V_56 ;
V_56 = V_2 -> V_21 [ V_2 -> V_22 ] . V_42 * V_2 -> V_24 ;
if ( V_56 % V_57 ) {
F_4 ( & V_2 -> V_7 . V_11 ,
L_11 , V_12 ,
__LINE__ , V_56 ) ;
return - V_58 ;
}
V_56 = V_2 -> V_21 [ V_2 -> V_22 ] . V_23 * V_2 -> V_24 ;
if ( V_56 % V_57 ) {
F_4 ( & V_2 -> V_7 . V_11 ,
L_12 , V_12 ,
__LINE__ , V_56 ) ;
return - V_58 ;
}
if ( ! V_59 . V_60 )
return - V_61 ;
if ( V_19 ) {
F_4 ( & V_2 -> V_7 . V_11 ,
L_13 ) ;
return - V_62 ;
}
V_19 = V_2 ;
V_6 = F_31 ( sizeof( * V_6 ) , V_63 ) ;
if ( ! V_6 ) {
error = - V_64 ;
goto V_36;
}
F_32 ( & V_2 -> V_7 , V_6 ) ;
F_33 ( & V_6 -> V_35 ) ;
V_6 -> V_15 = - 1 ;
V_2 -> V_33 = V_59 . V_23 ;
V_2 -> V_34 = V_59 . V_60 ;
V_6 -> V_10 = V_2 -> V_33 / V_2 -> V_24 ;
error = F_34 ( V_2 , F_26 ) ;
if ( error )
goto V_65;
V_66 . V_67 = & V_2 -> V_7 . V_11 ;
error = F_35 ( & V_66 ) ;
if ( error ) {
F_4 ( & V_2 -> V_7 . V_11 , L_14 ,
V_12 , __LINE__ , error ) ;
goto V_68;
}
F_36 ( & V_2 -> V_7 . V_11 , L_15 ,
V_12 , __LINE__ , V_66 . V_69 ) ;
F_37 ( & V_70 ) ;
return 0 ;
V_68:
F_38 ( V_2 ) ;
V_65:
F_39 ( V_6 ) ;
F_32 ( & V_2 -> V_7 , NULL ) ;
V_36:
V_19 = NULL ;
return error ;
}
static int F_40 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_30 ( & V_55 -> V_11 ) ;
F_37 ( NULL ) ;
F_41 ( & V_66 ) ;
F_38 ( V_2 ) ;
F_39 ( F_2 ( & V_2 -> V_7 ) ) ;
F_32 ( & V_2 -> V_7 , NULL ) ;
V_19 = NULL ;
return 0 ;
}
static int T_8 F_42 ( void )
{
return F_43 ( & V_71 ) ;
}
static void T_9 F_44 ( void )
{
F_45 ( & V_71 ) ;
}
