static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = F_2 ( V_3 ) ;
struct V_5 * V_5 = F_3 ( V_4 ) ;
return F_4 ( V_5 ) ;
}
static T_1 F_5 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return F_6 ( V_8 , V_9 , L_1 , V_1 -> V_10 ) ;
}
static T_1 F_7 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_1 V_12 = - V_13 ;
unsigned V_10 ;
V_12 = sscanf ( V_8 , L_2 , & V_10 ) ;
if ( V_12 != 1 ) {
V_12 = - V_14 ;
goto V_15;
}
V_1 -> V_10 = F_8 ( unsigned , V_10 , 500 ) ;
F_9 ( & V_1 -> V_16 ) ;
F_10 ( V_17 ) ;
F_11 ( V_17 , & V_1 -> V_16 ,
F_12 ( V_1 -> V_10 / 2 ) ) ;
V_15:
return V_12 < 0 ? V_12 : V_11 ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
const struct V_18 * V_19 ;
T_1 V_12 = 0 ;
if ( V_1 -> V_20 != NULL )
V_19 = & V_1 -> V_20 -> V_21 ;
else
V_19 = & V_22 ;
V_12 += F_14 ( V_8 , V_9 , V_19 ) ;
V_12 += sprintf ( V_8 + V_12 , L_3 ) ;
return V_12 ;
}
static T_1 F_15 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_18 V_19 ;
T_1 V_12 ;
V_12 = sscanf ( V_8 ,
L_4
L_4
L_4
L_5 ,
& V_19 . V_23 [ 0 ] , & V_19 . V_23 [ 1 ] ,
& V_19 . V_23 [ 2 ] , & V_19 . V_23 [ 3 ] ,
& V_19 . V_23 [ 4 ] , & V_19 . V_23 [ 5 ] ,
& V_19 . V_23 [ 6 ] , & V_19 . V_23 [ 7 ] ,
& V_19 . V_23 [ 8 ] , & V_19 . V_23 [ 9 ] ,
& V_19 . V_23 [ 10 ] , & V_19 . V_23 [ 11 ] ,
& V_19 . V_23 [ 12 ] , & V_19 . V_23 [ 13 ] ,
& V_19 . V_23 [ 14 ] , & V_19 . V_23 [ 15 ] ) ;
if ( V_12 != 16 ) {
F_16 ( V_3 , L_6
L_7 , ( int ) V_12 ) ;
return - V_14 ;
}
V_12 = F_17 ( V_1 , & V_19 ) ;
return V_12 < 0 ? V_12 : V_11 ;
}
static T_1 F_18 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_8 , L_7 , V_1 -> V_24 ) ;
}
static T_1 F_19 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_24 ;
T_1 V_12 ;
V_12 = sscanf ( V_8 , L_8 , & V_24 ) ;
if ( V_12 != 1 )
return - V_14 ;
if ( V_24 >= V_25 )
return - V_14 ;
V_1 -> V_24 = V_24 ;
return V_11 ;
}
static T_1 F_20 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_8 , L_9 ,
V_1 -> V_26 , V_1 -> V_27 ) ;
}
static T_1 F_21 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_28 , V_29 ;
T_1 V_12 ;
V_12 = sscanf ( V_8 , L_10 , & V_28 , & V_29 ) ;
if ( V_12 != 2 )
return - V_14 ;
V_1 -> V_26 = V_28 ;
V_1 -> V_27 = V_29 ;
return V_11 ;
}
static T_1 F_22 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
char * V_8 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_8 , L_7 , V_1 -> V_30 ) ;
}
static T_1 F_23 ( struct V_2 * V_3 ,
struct V_6 * V_7 ,
const char * V_8 , T_2 V_11 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
T_3 V_30 ;
T_1 V_12 ;
V_12 = sscanf ( V_8 , L_8 , & V_30 ) ;
if ( V_12 != 1 )
return - V_14 ;
V_1 -> V_30 = F_24 ( T_3 , V_30 , V_31 ) ;
return V_11 ;
}
int F_25 ( struct V_1 * V_1 )
{
int V_12 = 0 ;
V_1 -> V_10 = V_32 ;
V_1 -> V_24 = V_25 - 1 ;
V_1 -> V_26 = 4 ;
V_1 -> V_27 = 2 ;
V_1 -> V_30 = V_33 ;
F_26 ( & V_1 -> V_34 ) ;
V_12 = F_27 ( V_1 ) ;
if ( V_12 < 0 )
goto V_35;
V_12 = F_28 ( V_1 ) ;
if ( V_12 < 0 )
goto V_36;
V_12 = F_29 ( V_1 ) ;
if ( V_12 < 0 )
goto V_37;
V_12 = F_30 ( V_1 ) ;
if ( V_12 < 0 )
goto V_38;
return 0 ;
V_38:
F_31 ( V_1 ) ;
V_37:
F_32 ( V_1 ) ;
V_36:
F_33 ( V_1 ) ;
V_35:
return V_12 ;
}
static inline struct V_39 * F_34 ( struct V_1 * V_1 )
{
return & V_1 -> V_5 . V_40 . V_41 -> V_42 ;
}
int F_35 ( struct V_1 * V_1 )
{
int V_12 = 0 ;
struct V_2 * V_3 = V_1 -> V_5 . V_40 . V_41 ;
V_12 = F_36 ( F_34 ( V_1 ) , & V_43 ) ;
if ( V_12 < 0 ) {
F_16 ( V_3 , L_11 , V_12 ) ;
goto V_44;
}
return 0 ;
V_44:
return V_12 ;
}
void F_37 ( struct V_1 * V_1 )
{
F_38 ( V_1 ) ;
F_39 ( F_34 ( V_1 ) , & V_43 ) ;
}
void F_40 ( struct V_1 * V_1 )
{
F_41 ( V_1 ) ;
F_31 ( V_1 ) ;
F_32 ( V_1 ) ;
F_33 ( V_1 ) ;
}
T_4 F_42 ( void )
{
T_4 V_45 ;
F_43 ( & V_46 ) ;
V_45 = F_44 ( V_47 , V_48 ) ;
if ( V_45 >= V_48 ) {
V_45 = 0 ;
goto V_15;
}
F_45 ( V_45 , V_47 ) ;
V_45 = ( T_4 ) 0xff - V_45 ;
V_15:
F_46 ( & V_46 ) ;
return V_45 ;
}
void F_47 ( T_4 V_45 )
{
V_45 = 0xff - V_45 ;
F_48 ( V_45 >= V_48 ) ;
F_43 ( & V_46 ) ;
F_49 ( ! F_50 ( V_45 , V_47 ) ) ;
F_51 ( V_45 , V_47 ) ;
F_46 ( & V_46 ) ;
}
void F_52 ( struct V_1 * V_1 , struct V_49 * V_49 , int V_50 )
{
struct V_51 * V_51 = F_53 ( V_1 , V_49 -> V_3 ) ;
if ( V_50 == 0 && V_51 ) {
V_51 -> V_52 = V_53 ;
if ( ! F_54 ( & V_51 -> V_54 ) )
F_55 ( V_17 , & V_51 -> V_55 ) ;
else
F_56 ( V_51 ) ;
}
F_57 ( & V_1 -> V_5 , V_49 , V_50 ) ;
}
void F_58 ( struct V_1 * V_1 )
{
if ( V_1 -> V_56 )
F_59 ( V_1 -> V_56 ) ;
}
static int T_5 F_60 ( void )
{
int V_12 ;
V_12 = F_61 () ;
if ( V_12 < 0 )
goto V_57;
V_17 = F_62 ( L_12 ) ;
if ( V_17 == NULL ) {
V_12 = - V_58 ;
F_63 ( V_59 L_13 ) ;
goto V_60;
}
F_64 ( & V_61 ) ;
F_65 ( V_47 , V_48 ) ;
F_45 ( 0 , V_47 ) ;
return 0 ;
V_60:
F_66 () ;
V_57:
return V_12 ;
}
static void T_6 F_67 ( void )
{
F_51 ( 0 , V_47 ) ;
if ( ! F_68 ( V_47 , V_48 ) ) {
char V_8 [ 256 ] ;
F_69 ( V_8 , sizeof( V_8 ) , V_47 ,
V_48 ) ;
F_63 ( V_59 L_14
L_15 , V_8 ) ;
F_49 ( 1 ) ;
}
F_70 ( & V_61 ) ;
F_71 ( V_17 ) ;
F_66 () ;
}
