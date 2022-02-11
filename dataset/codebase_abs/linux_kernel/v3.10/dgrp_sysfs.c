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
sscanf ( V_4 , L_4 , & V_10 ) ;
return V_11 ;
}
int F_5 ( void )
{
int V_12 = 0 ;
int V_13 = 1U << ( 32 - V_14 ) ;
V_15 = F_6 ( V_16 , L_5 ) ;
if ( F_7 ( V_15 ) )
return F_8 ( V_15 ) ;
V_12 = F_9 ( V_15 , & V_17 ) ;
if ( V_12 )
goto V_18;
V_19 = F_10 ( V_15 , NULL ,
F_11 ( 0 , V_13 + 1 ) , NULL , L_6 ) ;
if ( F_7 ( V_19 ) ) {
V_12 = F_8 ( V_19 ) ;
goto V_20;
}
V_12 = F_12 ( & V_19 -> V_21 ,
& V_22 ) ;
if ( V_12 ) {
F_13 ( L_7 ,
V_23 ) ;
goto V_24;
}
V_25 = F_10 ( V_15 , NULL ,
F_11 ( 0 , V_13 + 2 ) , NULL , L_8 ) ;
if ( F_7 ( V_25 ) ) {
V_12 = F_8 ( V_25 ) ;
goto V_26;
}
return 0 ;
V_26:
F_14 ( & V_19 -> V_21 ,
& V_22 ) ;
V_24:
F_15 ( V_15 , F_11 ( 0 , V_13 + 1 ) ) ;
V_20:
F_16 ( V_15 , & V_17 ) ;
V_18:
F_17 ( V_15 ) ;
return V_12 ;
}
void F_18 ( void )
{
struct V_27 * V_28 ;
int V_13 = 1U << ( 32 - V_14 ) ;
F_19 (nd, &nd_struct_list, list)
F_20 ( V_28 ) ;
F_14 ( & V_19 -> V_21 ,
& V_22 ) ;
F_16 ( V_15 , & V_17 ) ;
F_15 ( V_15 , F_11 ( 0 , V_13 + 1 ) ) ;
F_15 ( V_15 , F_11 ( 0 , V_13 + 2 ) ) ;
F_17 ( V_15 ) ;
}
static T_1 F_21 ( struct V_7 * V_8 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_27 * V_28 ;
if ( ! V_8 )
return 0 ;
V_28 = (struct V_27 * ) F_22 ( V_8 ) ;
if ( ! V_28 )
return 0 ;
return snprintf ( V_4 , V_5 , L_1 , F_23 ( V_28 -> V_29 ) ) ;
}
static T_1 F_24 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
struct V_27 * V_28 ;
if ( ! V_8 )
return 0 ;
V_28 = (struct V_27 * ) F_22 ( V_8 ) ;
if ( ! V_28 )
return 0 ;
if ( V_28 -> V_29 == V_30 )
return snprintf ( V_4 , V_5 , L_1 , V_28 -> V_31 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
struct V_27 * V_28 ;
if ( ! V_8 )
return 0 ;
V_28 = (struct V_27 * ) F_22 ( V_8 ) ;
if ( ! V_28 )
return 0 ;
if ( V_28 -> V_29 == V_30 )
return snprintf ( V_4 , V_5 , L_9 ,
( V_28 -> V_32 >> 8 ) & 0xff ,
V_28 -> V_32 & 0xff ) ;
return 0 ;
}
static T_1 F_26 ( struct V_7 * V_8 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_27 * V_28 ;
if ( ! V_8 )
return 0 ;
V_28 = (struct V_27 * ) F_22 ( V_8 ) ;
if ( ! V_28 )
return 0 ;
if ( V_28 -> V_29 == V_30 )
return snprintf ( V_4 , V_5 , L_3 , V_28 -> V_33 ) ;
return 0 ;
}
static T_1 F_27 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
struct V_27 * V_28 ;
if ( ! V_8 )
return 0 ;
V_28 = (struct V_27 * ) F_22 ( V_8 ) ;
if ( ! V_28 )
return 0 ;
if ( V_28 -> V_29 == V_30 )
return snprintf ( V_4 , V_5 , L_9 ,
( V_28 -> V_34 >> 8 ) & 0xff ,
V_28 -> V_34 & 0xff ) ;
return 0 ;
}
void F_28 ( struct V_27 * V_28 )
{
int V_12 ;
char V_35 [ 10 ] ;
if ( V_28 -> V_36 )
F_29 ( V_28 -> V_36 , V_35 ) ;
else
sprintf ( V_35 , L_10 , V_28 -> V_37 ) ;
V_28 -> V_38 = F_10 ( V_15 , V_25 ,
F_11 ( 0 , V_28 -> V_37 ) , NULL , V_35 ) ;
V_12 = F_12 ( & V_28 -> V_38 -> V_21 ,
& V_39 ) ;
if ( V_12 ) {
F_13 ( L_11 ,
V_23 ) ;
F_14 ( & V_28 -> V_38 -> V_21 ,
& V_39 ) ;
return;
}
F_30 ( V_28 -> V_38 , V_28 ) ;
}
void F_20 ( struct V_27 * V_28 )
{
if ( V_28 -> V_38 ) {
F_14 ( & V_28 -> V_38 -> V_21 ,
& V_39 ) ;
F_15 ( V_15 , F_11 ( 0 , V_28 -> V_37 ) ) ;
V_28 -> V_38 = NULL ;
}
}
static T_1 F_31 ( struct V_7 * V_40 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_41 * V_42 ;
if ( ! V_40 )
return 0 ;
V_42 = (struct V_41 * ) F_22 ( V_40 ) ;
if ( ! V_42 )
return 0 ;
return snprintf ( V_4 , V_5 , L_1 ,
V_42 -> V_43 ? L_12 : L_13 ) ;
}
static T_1 F_32 ( struct V_7 * V_40 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_44 * V_45 ;
struct V_41 * V_42 ;
if ( ! V_40 )
return 0 ;
V_42 = (struct V_41 * ) F_22 ( V_40 ) ;
if ( ! V_42 )
return 0 ;
V_45 = V_42 -> V_46 ;
if ( ! V_45 )
return 0 ;
return snprintf ( V_4 , V_5 , L_3 ,
V_42 -> V_43 ? ( V_47 / V_45 -> V_48 ) : 0 ) ;
}
static T_1 F_33 ( struct V_7 * V_40 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_44 * V_45 ;
struct V_41 * V_42 ;
if ( ! V_40 )
return 0 ;
V_42 = (struct V_41 * ) F_22 ( V_40 ) ;
if ( ! V_42 )
return 0 ;
V_45 = V_42 -> V_46 ;
if ( ! V_45 )
return 0 ;
if ( V_45 -> V_49 ) {
return snprintf ( V_4 , V_5 , L_14 ,
( V_45 -> V_50 & V_51 ) ? L_15 : L_16 ,
( V_45 -> V_50 & V_52 ) ? L_17 : L_16 ,
( V_45 -> V_50 & V_53 ) ? L_18 : L_16 ,
( V_45 -> V_50 & V_54 ) ? L_19 : L_16 ,
( V_45 -> V_50 & V_55 ) ? L_20 : L_16 ,
( V_45 -> V_50 & V_56 ) ? L_21 : L_16 ) ;
}
return 0 ;
}
static T_1 F_34 ( struct V_7 * V_40 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_44 * V_45 ;
struct V_41 * V_42 ;
if ( ! V_40 )
return 0 ;
V_42 = (struct V_41 * ) F_22 ( V_40 ) ;
if ( ! V_42 )
return 0 ;
V_45 = V_42 -> V_46 ;
if ( ! V_45 )
return 0 ;
return snprintf ( V_4 , V_5 , L_22 , V_45 -> V_57 ) ;
}
static T_1 F_35 ( struct V_7 * V_40 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_44 * V_45 ;
struct V_41 * V_42 ;
if ( ! V_40 )
return 0 ;
V_42 = (struct V_41 * ) F_22 ( V_40 ) ;
if ( ! V_42 )
return 0 ;
V_45 = V_42 -> V_46 ;
if ( ! V_45 )
return 0 ;
return snprintf ( V_4 , V_5 , L_22 , V_45 -> V_58 ) ;
}
static T_1 F_36 ( struct V_7 * V_40 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_44 * V_45 ;
struct V_41 * V_42 ;
if ( ! V_40 )
return 0 ;
V_42 = (struct V_41 * ) F_22 ( V_40 ) ;
if ( ! V_42 )
return 0 ;
V_45 = V_42 -> V_46 ;
if ( ! V_45 )
return 0 ;
return snprintf ( V_4 , V_5 , L_22 , V_45 -> V_59 ) ;
}
static T_1 F_37 ( struct V_7 * V_40 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_44 * V_45 ;
struct V_41 * V_42 ;
if ( ! V_40 )
return 0 ;
V_42 = (struct V_41 * ) F_22 ( V_40 ) ;
if ( ! V_42 )
return 0 ;
V_45 = V_42 -> V_46 ;
if ( ! V_45 )
return 0 ;
return snprintf ( V_4 , V_5 , L_22 , V_45 -> V_60 . V_61 ) ;
}
static T_1 F_38 ( struct V_7 * V_40 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_44 * V_45 ;
struct V_41 * V_42 ;
if ( ! V_40 )
return 0 ;
V_42 = (struct V_41 * ) F_22 ( V_40 ) ;
if ( ! V_42 )
return 0 ;
V_45 = V_42 -> V_46 ;
if ( ! V_45 )
return 0 ;
return snprintf ( V_4 , V_5 , L_3 , V_45 -> V_62 ) ;
}
static T_1 F_39 ( struct V_7 * V_40 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_44 * V_45 ;
struct V_41 * V_42 ;
if ( ! V_40 )
return 0 ;
V_42 = (struct V_41 * ) F_22 ( V_40 ) ;
if ( ! V_42 )
return 0 ;
V_45 = V_42 -> V_46 ;
if ( ! V_45 )
return 0 ;
return snprintf ( V_4 , V_5 , L_3 , V_45 -> V_63 ) ;
}
static T_1 F_40 ( struct V_7 * V_40 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_27 * V_28 ;
struct V_44 * V_45 ;
struct V_41 * V_42 ;
char V_35 [ 10 ] ;
if ( ! V_40 )
return 0 ;
V_42 = (struct V_41 * ) F_22 ( V_40 ) ;
if ( ! V_42 )
return 0 ;
V_45 = V_42 -> V_46 ;
if ( ! V_45 )
return 0 ;
V_28 = V_45 -> V_64 ;
if ( ! V_28 )
return 0 ;
F_29 ( V_28 -> V_36 , V_35 ) ;
return snprintf ( V_4 , V_5 , L_23 ,
V_42 -> V_65 == V_66 ? L_24 : L_25 ,
V_35 , V_45 -> V_67 ) ;
}
void F_41 ( struct V_41 * V_42 , struct V_7 * V_8 )
{
int V_12 ;
V_12 = F_12 ( & V_8 -> V_21 , & V_68 ) ;
if ( V_12 ) {
F_13 ( L_26 ,
V_23 ) ;
F_14 ( & V_8 -> V_21 , & V_68 ) ;
return;
}
F_30 ( V_8 , V_42 ) ;
}
void F_42 ( struct V_7 * V_8 )
{
F_14 ( & V_8 -> V_21 , & V_68 ) ;
}
