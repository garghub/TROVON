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
T_2 V_8 ;
F_8 ( & V_16 -> V_20 -> V_21 -> V_22 ) ;
switch ( V_18 ) {
case 1 :
V_17 += V_16 -> V_23 ;
break;
case 2 :
V_17 += V_2 -> V_24 [ V_2 -> V_25 ] . V_26 * V_2 -> V_27 ;
break;
}
if ( V_17 < 0 ) {
V_8 = - V_28 ;
goto V_29;
}
V_16 -> V_23 = V_17 ;
V_8 = V_16 -> V_23 ;
V_29:
F_9 ( & V_16 -> V_20 -> V_21 -> V_22 ) ;
return V_8 ;
}
static T_3 F_10 ( char T_4 * V_30 , void * V_31 ,
T_5 V_32 , T_2 * V_33 )
{
struct V_1 * V_2 = V_19 ;
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
T_1 V_26 , V_34 , V_17 ;
int V_8 ;
T_5 V_35 , V_36 ;
const void * V_37 ;
F_11 ( & V_2 -> V_7 . V_11 ,
L_4 ,
V_12 , __LINE__ , V_32 , * V_33 , V_30 , V_31 ) ;
V_26 = V_2 -> V_24 [ V_2 -> V_25 ] . V_26 * V_2 -> V_27 ;
if ( * V_33 >= V_26 || ! V_32 )
return 0 ;
if ( * V_33 + V_32 > V_26 ) {
F_11 ( & V_2 -> V_7 . V_11 ,
L_5 , V_12 ,
__LINE__ , V_32 , V_26 - * V_33 ) ;
V_32 = V_26 - * V_33 ;
}
V_34 = * V_33 / V_2 -> V_38 * V_6 -> V_10 ;
V_17 = * V_33 % V_2 -> V_38 ;
V_35 = V_32 ;
do {
V_36 = F_12 ( T_1 , V_35 , V_2 -> V_38 - V_17 ) ;
V_37 = V_2 -> V_39 + V_17 ;
F_8 ( & V_6 -> V_40 ) ;
V_8 = F_6 ( V_2 , V_34 ) ;
if ( V_8 )
goto V_41;
F_11 ( & V_2 -> V_7 . V_11 ,
L_6 ,
V_12 , __LINE__ , V_36 , V_37 , V_30 , V_31 ) ;
if ( V_30 ) {
if ( F_13 ( V_30 , V_37 , V_36 ) ) {
V_8 = - V_42 ;
goto V_41;
}
V_30 += V_36 ;
}
if ( V_31 ) {
memcpy ( V_31 , V_37 , V_36 ) ;
V_31 += V_36 ;
}
F_9 ( & V_6 -> V_40 ) ;
* V_33 += V_36 ;
V_35 -= V_36 ;
V_34 += V_6 -> V_10 ;
V_17 = 0 ;
} while ( V_35 > 0 );
return V_32 ;
V_41:
F_9 ( & V_6 -> V_40 ) ;
return V_8 ;
}
static T_3 F_14 ( const char T_4 * V_30 ,
const void * V_31 , T_5 V_32 , T_2 * V_33 )
{
struct V_1 * V_2 = V_19 ;
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
T_1 V_26 , V_34 , V_17 ;
int V_8 = 0 ;
T_5 V_35 , V_36 ;
void * V_43 ;
F_11 ( & V_2 -> V_7 . V_11 ,
L_7 ,
V_12 , __LINE__ , V_32 , * V_33 , V_30 , V_31 ) ;
V_26 = V_2 -> V_24 [ V_2 -> V_25 ] . V_26 * V_2 -> V_27 ;
if ( * V_33 >= V_26 || ! V_32 )
return 0 ;
if ( * V_33 + V_32 > V_26 ) {
F_11 ( & V_2 -> V_7 . V_11 ,
L_5 , V_12 ,
__LINE__ , V_32 , V_26 - * V_33 ) ;
V_32 = V_26 - * V_33 ;
}
V_34 = * V_33 / V_2 -> V_38 * V_6 -> V_10 ;
V_17 = * V_33 % V_2 -> V_38 ;
V_35 = V_32 ;
do {
V_36 = F_12 ( T_1 , V_35 , V_2 -> V_38 - V_17 ) ;
V_43 = V_2 -> V_39 + V_17 ;
F_8 ( & V_6 -> V_40 ) ;
if ( V_36 != V_2 -> V_38 )
V_8 = F_6 ( V_2 , V_34 ) ;
else if ( V_34 != V_6 -> V_15 )
V_8 = F_5 ( V_2 ) ;
if ( V_8 )
goto V_41;
F_11 ( & V_2 -> V_7 . V_11 ,
L_8 ,
V_12 , __LINE__ , V_36 , V_30 , V_31 , V_43 ) ;
if ( V_30 ) {
if ( F_15 ( V_43 , V_30 , V_36 ) ) {
V_8 = - V_42 ;
goto V_41;
}
V_30 += V_36 ;
}
if ( V_31 ) {
memcpy ( V_43 , V_31 , V_36 ) ;
V_31 += V_36 ;
}
V_6 -> V_15 = V_34 ;
V_6 -> V_14 = true ;
F_9 ( & V_6 -> V_40 ) ;
* V_33 += V_36 ;
V_35 -= V_36 ;
V_34 += V_6 -> V_10 ;
V_17 = 0 ;
} while ( V_35 > 0 );
return V_32 ;
V_41:
F_9 ( & V_6 -> V_40 ) ;
return V_8 ;
}
static T_3 F_16 ( struct V_16 * V_16 , char T_4 * V_44 ,
T_5 V_32 , T_2 * V_33 )
{
return F_10 ( V_44 , NULL , V_32 , V_33 ) ;
}
static T_3 F_17 ( struct V_16 * V_16 , const char T_4 * V_44 ,
T_5 V_32 , T_2 * V_33 )
{
return F_14 ( V_44 , NULL , V_32 , V_33 ) ;
}
static T_3 F_18 ( void * V_44 , T_5 V_32 , T_2 V_33 )
{
return F_10 ( NULL , V_44 , V_32 , & V_33 ) ;
}
static T_3 F_19 ( const void * V_44 , T_5 V_32 ,
T_2 V_33 )
{
T_3 V_8 ;
int V_45 ;
V_8 = F_14 ( NULL , V_44 , V_32 , & V_33 ) ;
if ( V_8 < 0 )
return V_8 ;
V_45 = F_5 ( V_19 ) ;
if ( V_45 )
return V_45 ;
return V_8 ;
}
static int F_20 ( struct V_16 * V_16 , T_6 V_46 )
{
return F_5 ( V_19 ) ;
}
static int F_21 ( struct V_16 * V_16 , int V_47 )
{
return F_5 ( V_19 ) ;
}
static T_7 F_22 ( int V_48 , void * V_49 )
{
struct V_1 * V_2 = V_49 ;
int V_8 ;
T_1 V_15 , V_50 ;
V_8 = F_23 ( V_2 -> V_7 . V_51 , & V_15 , & V_50 ) ;
if ( V_15 != V_2 -> V_15 )
F_4 ( & V_2 -> V_7 . V_11 ,
L_9 ,
V_12 , __LINE__ , V_15 , V_2 -> V_15 ) ;
if ( V_8 ) {
F_4 ( & V_2 -> V_7 . V_11 , L_10 ,
V_12 , __LINE__ , V_8 , V_50 ) ;
} else {
V_2 -> V_52 = V_50 ;
F_24 ( & V_2 -> V_53 ) ;
}
return V_54 ;
}
static int T_8 F_25 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( & V_56 -> V_11 ) ;
struct V_5 * V_6 ;
int error ;
unsigned long V_57 ;
V_57 = V_2 -> V_24 [ V_2 -> V_25 ] . V_58 * V_2 -> V_27 ;
if ( V_57 % V_59 ) {
F_4 ( & V_2 -> V_7 . V_11 ,
L_11 , V_12 ,
__LINE__ , V_57 ) ;
return - V_28 ;
}
V_57 = V_2 -> V_24 [ V_2 -> V_25 ] . V_26 * V_2 -> V_27 ;
if ( V_57 % V_59 ) {
F_4 ( & V_2 -> V_7 . V_11 ,
L_12 , V_12 ,
__LINE__ , V_57 ) ;
return - V_28 ;
}
if ( ! V_60 . V_61 )
return - V_62 ;
if ( V_19 ) {
F_4 ( & V_2 -> V_7 . V_11 ,
L_13 ) ;
return - V_63 ;
}
V_19 = V_2 ;
V_6 = F_27 ( sizeof( * V_6 ) , V_64 ) ;
if ( ! V_6 ) {
error = - V_65 ;
goto V_41;
}
F_28 ( & V_2 -> V_7 , V_6 ) ;
F_29 ( & V_6 -> V_40 ) ;
V_6 -> V_15 = - 1 ;
V_2 -> V_38 = V_60 . V_26 ;
V_2 -> V_39 = V_60 . V_61 ;
V_6 -> V_10 = V_2 -> V_38 / V_2 -> V_27 ;
error = F_30 ( V_2 , F_22 ) ;
if ( error )
goto V_66;
V_67 . V_68 = & V_2 -> V_7 . V_11 ;
error = F_31 ( & V_67 ) ;
if ( error ) {
F_4 ( & V_2 -> V_7 . V_11 , L_14 ,
V_12 , __LINE__ , error ) ;
goto V_69;
}
F_32 ( & V_2 -> V_7 . V_11 , L_15 ,
V_12 , __LINE__ , V_67 . V_70 ) ;
F_33 ( & V_71 ) ;
return 0 ;
V_69:
F_34 ( V_2 ) ;
V_66:
F_35 ( V_6 ) ;
F_28 ( & V_2 -> V_7 , NULL ) ;
V_41:
V_19 = NULL ;
return error ;
}
static int F_36 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = F_26 ( & V_56 -> V_11 ) ;
F_33 ( NULL ) ;
F_37 ( & V_67 ) ;
F_34 ( V_2 ) ;
F_35 ( F_2 ( & V_2 -> V_7 ) ) ;
F_28 ( & V_2 -> V_7 , NULL ) ;
V_19 = NULL ;
return 0 ;
}
static int T_9 F_38 ( void )
{
return F_39 ( & V_72 ) ;
}
static void T_10 F_40 ( void )
{
F_41 ( & V_72 ) ;
}
