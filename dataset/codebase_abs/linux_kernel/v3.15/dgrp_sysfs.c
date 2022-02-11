static T_1 F_1 ( struct V_1 * V_1 ,
struct V_2 * V_3 , char * V_4 )
{
return snprintf ( V_4 , V_5 , L_1 , V_6 ) ;
}
static T_1 F_2 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
return snprintf ( V_4 , V_5 , L_2 ) ;
}
static T_1 F_3 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
return snprintf ( V_4 , V_5 , L_3 , V_10 ) ;
}
static T_1 F_4 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
const char * V_4 , T_2 V_11 )
{
if ( sscanf ( V_4 , L_4 , & V_10 ) != 1 )
return - V_12 ;
return V_11 ;
}
int F_5 ( void )
{
int V_13 = 0 ;
int V_14 = 1U << ( 32 - V_15 ) ;
V_16 = F_6 ( V_17 , L_5 ) ;
if ( F_7 ( V_16 ) )
return F_8 ( V_16 ) ;
V_13 = F_9 ( V_16 , & V_18 ) ;
if ( V_13 )
goto V_19;
V_20 = F_10 ( V_16 , NULL ,
F_11 ( 0 , V_14 + 1 ) , NULL , L_6 ) ;
if ( F_7 ( V_20 ) ) {
V_13 = F_8 ( V_20 ) ;
goto V_21;
}
V_13 = F_12 ( & V_20 -> V_22 ,
& V_23 ) ;
if ( V_13 ) {
F_13 ( L_7 ,
V_24 ) ;
goto V_25;
}
V_26 = F_10 ( V_16 , NULL ,
F_11 ( 0 , V_14 + 2 ) , NULL , L_8 ) ;
if ( F_7 ( V_26 ) ) {
V_13 = F_8 ( V_26 ) ;
goto V_27;
}
return 0 ;
V_27:
F_14 ( & V_20 -> V_22 ,
& V_23 ) ;
V_25:
F_15 ( V_16 , F_11 ( 0 , V_14 + 1 ) ) ;
V_21:
F_16 ( V_16 , & V_18 ) ;
V_19:
F_17 ( V_16 ) ;
return V_13 ;
}
void F_18 ( void )
{
struct V_28 * V_29 ;
int V_14 = 1U << ( 32 - V_15 ) ;
F_19 (nd, &nd_struct_list, list)
F_20 ( V_29 ) ;
F_14 ( & V_20 -> V_22 ,
& V_23 ) ;
F_16 ( V_16 , & V_18 ) ;
F_15 ( V_16 , F_11 ( 0 , V_14 + 1 ) ) ;
F_15 ( V_16 , F_11 ( 0 , V_14 + 2 ) ) ;
F_17 ( V_16 ) ;
}
static T_1 F_21 ( struct V_7 * V_8 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_28 * V_29 ;
if ( ! V_8 )
return 0 ;
V_29 = F_22 ( V_8 ) ;
if ( ! V_29 )
return 0 ;
return snprintf ( V_4 , V_5 , L_1 , F_23 ( V_29 -> V_30 ) ) ;
}
static T_1 F_24 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
struct V_28 * V_29 ;
if ( ! V_8 )
return 0 ;
V_29 = F_22 ( V_8 ) ;
if ( ! V_29 )
return 0 ;
if ( V_29 -> V_30 == V_31 )
return snprintf ( V_4 , V_5 , L_1 , V_29 -> V_32 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
struct V_28 * V_29 ;
if ( ! V_8 )
return 0 ;
V_29 = F_22 ( V_8 ) ;
if ( ! V_29 )
return 0 ;
if ( V_29 -> V_30 == V_31 )
return snprintf ( V_4 , V_5 , L_9 ,
( V_29 -> V_33 >> 8 ) & 0xff ,
V_29 -> V_33 & 0xff ) ;
return 0 ;
}
static T_1 F_26 ( struct V_7 * V_8 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_28 * V_29 ;
if ( ! V_8 )
return 0 ;
V_29 = F_22 ( V_8 ) ;
if ( ! V_29 )
return 0 ;
if ( V_29 -> V_30 == V_31 )
return snprintf ( V_4 , V_5 , L_3 , V_29 -> V_34 ) ;
return 0 ;
}
static T_1 F_27 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
struct V_28 * V_29 ;
if ( ! V_8 )
return 0 ;
V_29 = F_22 ( V_8 ) ;
if ( ! V_29 )
return 0 ;
if ( V_29 -> V_30 == V_31 )
return snprintf ( V_4 , V_5 , L_9 ,
( V_29 -> V_35 >> 8 ) & 0xff ,
V_29 -> V_35 & 0xff ) ;
return 0 ;
}
void F_28 ( struct V_28 * V_29 )
{
int V_13 ;
char V_36 [ 10 ] ;
if ( V_29 -> V_37 )
F_29 ( V_29 -> V_37 , V_36 ) ;
else
sprintf ( V_36 , L_10 , V_29 -> V_38 ) ;
V_29 -> V_39 = F_10 ( V_16 , V_26 ,
F_11 ( 0 , V_29 -> V_38 ) , NULL , L_11 , V_36 ) ;
V_13 = F_12 ( & V_29 -> V_39 -> V_22 ,
& V_40 ) ;
if ( V_13 ) {
F_13 ( L_12 ,
V_24 ) ;
F_14 ( & V_29 -> V_39 -> V_22 ,
& V_40 ) ;
return;
}
F_30 ( V_29 -> V_39 , V_29 ) ;
}
void F_20 ( struct V_28 * V_29 )
{
if ( V_29 -> V_39 ) {
F_14 ( & V_29 -> V_39 -> V_22 ,
& V_40 ) ;
F_15 ( V_16 , F_11 ( 0 , V_29 -> V_38 ) ) ;
V_29 -> V_39 = NULL ;
}
}
static T_1 F_31 ( struct V_7 * V_41 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_42 * V_43 ;
if ( ! V_41 )
return 0 ;
V_43 = F_22 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
return snprintf ( V_4 , V_5 , L_1 ,
V_43 -> V_44 ? L_13 : L_14 ) ;
}
static T_1 F_32 ( struct V_7 * V_41 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_45 * V_46 ;
struct V_42 * V_43 ;
if ( ! V_41 )
return 0 ;
V_43 = F_22 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
V_46 = V_43 -> V_47 ;
if ( ! V_46 )
return 0 ;
return snprintf ( V_4 , V_5 , L_3 ,
V_43 -> V_44 ? ( V_48 / V_46 -> V_49 ) : 0 ) ;
}
static T_1 F_33 ( struct V_7 * V_41 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_45 * V_46 ;
struct V_42 * V_43 ;
if ( ! V_41 )
return 0 ;
V_43 = F_22 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
V_46 = V_43 -> V_47 ;
if ( ! V_46 )
return 0 ;
if ( V_46 -> V_50 ) {
return snprintf ( V_4 , V_5 , L_15 ,
( V_46 -> V_51 & V_52 ) ? L_16 : L_17 ,
( V_46 -> V_51 & V_53 ) ? L_18 : L_17 ,
( V_46 -> V_51 & V_54 ) ? L_19 : L_17 ,
( V_46 -> V_51 & V_55 ) ? L_20 : L_17 ,
( V_46 -> V_51 & V_56 ) ? L_21 : L_17 ,
( V_46 -> V_51 & V_57 ) ? L_22 : L_17 ) ;
}
return 0 ;
}
static T_1 F_34 ( struct V_7 * V_41 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_45 * V_46 ;
struct V_42 * V_43 ;
if ( ! V_41 )
return 0 ;
V_43 = F_22 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
V_46 = V_43 -> V_47 ;
if ( ! V_46 )
return 0 ;
return snprintf ( V_4 , V_5 , L_23 , V_46 -> V_58 ) ;
}
static T_1 F_35 ( struct V_7 * V_41 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_45 * V_46 ;
struct V_42 * V_43 ;
if ( ! V_41 )
return 0 ;
V_43 = F_22 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
V_46 = V_43 -> V_47 ;
if ( ! V_46 )
return 0 ;
return snprintf ( V_4 , V_5 , L_23 , V_46 -> V_59 ) ;
}
static T_1 F_36 ( struct V_7 * V_41 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_45 * V_46 ;
struct V_42 * V_43 ;
if ( ! V_41 )
return 0 ;
V_43 = F_22 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
V_46 = V_43 -> V_47 ;
if ( ! V_46 )
return 0 ;
return snprintf ( V_4 , V_5 , L_23 , V_46 -> V_60 ) ;
}
static T_1 F_37 ( struct V_7 * V_41 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_45 * V_46 ;
struct V_42 * V_43 ;
if ( ! V_41 )
return 0 ;
V_43 = F_22 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
V_46 = V_43 -> V_47 ;
if ( ! V_46 )
return 0 ;
return snprintf ( V_4 , V_5 , L_23 , V_46 -> V_61 . V_62 ) ;
}
static T_1 F_38 ( struct V_7 * V_41 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_45 * V_46 ;
struct V_42 * V_43 ;
if ( ! V_41 )
return 0 ;
V_43 = F_22 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
V_46 = V_43 -> V_47 ;
if ( ! V_46 )
return 0 ;
return snprintf ( V_4 , V_5 , L_3 , V_46 -> V_63 ) ;
}
static T_1 F_39 ( struct V_7 * V_41 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_45 * V_46 ;
struct V_42 * V_43 ;
if ( ! V_41 )
return 0 ;
V_43 = F_22 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
V_46 = V_43 -> V_47 ;
if ( ! V_46 )
return 0 ;
return snprintf ( V_4 , V_5 , L_3 , V_46 -> V_64 ) ;
}
static T_1 F_40 ( struct V_7 * V_41 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_28 * V_29 ;
struct V_45 * V_46 ;
struct V_42 * V_43 ;
char V_36 [ 10 ] ;
if ( ! V_41 )
return 0 ;
V_43 = F_22 ( V_41 ) ;
if ( ! V_43 )
return 0 ;
V_46 = V_43 -> V_47 ;
if ( ! V_46 )
return 0 ;
V_29 = V_46 -> V_65 ;
if ( ! V_29 )
return 0 ;
F_29 ( V_29 -> V_37 , V_36 ) ;
return snprintf ( V_4 , V_5 , L_24 ,
V_43 -> V_66 == V_67 ? L_25 : L_26 ,
V_36 , V_46 -> V_68 ) ;
}
void F_41 ( struct V_42 * V_43 , struct V_7 * V_8 )
{
int V_13 ;
V_13 = F_12 ( & V_8 -> V_22 , & V_69 ) ;
if ( V_13 ) {
F_13 ( L_27 ,
V_24 ) ;
F_14 ( & V_8 -> V_22 , & V_69 ) ;
return;
}
F_30 ( V_8 , V_43 ) ;
}
void F_42 ( struct V_7 * V_8 )
{
F_14 ( & V_8 -> V_22 , & V_69 ) ;
}
