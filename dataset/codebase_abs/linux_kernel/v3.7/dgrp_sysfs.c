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
static T_1 F_5 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
return snprintf ( V_4 , V_5 , L_3 , V_12 ) ;
}
static T_1 F_6 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
const char * V_4 , T_2 V_11 )
{
sscanf ( V_4 , L_4 , & V_12 ) ;
return V_11 ;
}
void F_7 ( void )
{
int V_13 = 0 ;
int V_14 = 1U << ( 32 - V_15 ) ;
V_16 = F_8 ( V_17 , L_5 ) ;
V_13 = F_9 ( V_16 , & V_18 ) ;
V_19 = F_10 ( V_16 , NULL ,
F_11 ( 0 , V_14 + 1 ) , NULL , L_6 ) ;
V_13 = F_12 ( & V_19 -> V_20 ,
& V_21 ) ;
if ( V_13 ) {
F_13 ( L_7 ,
V_22 ) ;
F_14 ( & V_19 -> V_20 ,
& V_21 ) ;
return;
}
V_23 = F_10 ( V_16 , NULL ,
F_11 ( 0 , V_14 + 2 ) , NULL , L_8 ) ;
}
void F_15 ( void )
{
struct V_24 * V_25 ;
int V_14 = 1U << ( 32 - V_15 ) ;
F_16 (nd, &nd_struct_list, list)
F_17 ( V_25 ) ;
F_14 ( & V_19 -> V_20 ,
& V_21 ) ;
F_18 ( V_16 , & V_18 ) ;
F_19 ( V_16 , F_11 ( 0 , V_14 + 1 ) ) ;
F_19 ( V_16 , F_11 ( 0 , V_14 + 2 ) ) ;
F_20 ( V_16 ) ;
}
static T_1 F_21 ( struct V_7 * V_8 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_24 * V_25 ;
if ( ! V_8 )
return 0 ;
V_25 = (struct V_24 * ) F_22 ( V_8 ) ;
if ( ! V_25 )
return 0 ;
return snprintf ( V_4 , V_5 , L_1 , F_23 ( V_25 -> V_26 ) ) ;
}
static T_1 F_24 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
struct V_24 * V_25 ;
if ( ! V_8 )
return 0 ;
V_25 = (struct V_24 * ) F_22 ( V_8 ) ;
if ( ! V_25 )
return 0 ;
if ( V_25 -> V_26 == V_27 && V_25 -> V_28 )
return snprintf ( V_4 , V_5 , L_1 , V_25 -> V_28 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
struct V_24 * V_25 ;
if ( ! V_8 )
return 0 ;
V_25 = (struct V_24 * ) F_22 ( V_8 ) ;
if ( ! V_25 )
return 0 ;
if ( V_25 -> V_26 == V_27 )
return snprintf ( V_4 , V_5 , L_9 ,
( V_25 -> V_29 >> 8 ) & 0xff ,
V_25 -> V_29 & 0xff ) ;
return 0 ;
}
static T_1 F_26 ( struct V_7 * V_8 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_24 * V_25 ;
if ( ! V_8 )
return 0 ;
V_25 = (struct V_24 * ) F_22 ( V_8 ) ;
if ( ! V_25 )
return 0 ;
if ( V_25 -> V_26 == V_27 )
return snprintf ( V_4 , V_5 , L_3 , V_25 -> V_30 ) ;
return 0 ;
}
static T_1 F_27 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
struct V_24 * V_25 ;
if ( ! V_8 )
return 0 ;
V_25 = (struct V_24 * ) F_22 ( V_8 ) ;
if ( ! V_25 )
return 0 ;
if ( V_25 -> V_26 == V_27 )
return snprintf ( V_4 , V_5 , L_9 ,
( V_25 -> V_31 >> 8 ) & 0xff ,
V_25 -> V_31 & 0xff ) ;
return 0 ;
}
void F_28 ( struct V_24 * V_25 )
{
int V_13 ;
char V_32 [ 10 ] ;
if ( V_25 -> V_33 )
F_29 ( V_25 -> V_33 , V_32 ) ;
else
sprintf ( V_32 , L_10 , V_25 -> V_34 ) ;
V_25 -> V_35 = F_10 ( V_16 , V_23 ,
F_11 ( 0 , V_25 -> V_34 ) , NULL , V_32 ) ;
V_13 = F_12 ( & V_25 -> V_35 -> V_20 ,
& V_36 ) ;
if ( V_13 ) {
F_13 ( L_11 ,
V_22 ) ;
F_14 ( & V_25 -> V_35 -> V_20 ,
& V_36 ) ;
return;
}
F_30 ( V_25 -> V_35 , V_25 ) ;
}
void F_17 ( struct V_24 * V_25 )
{
if ( V_25 -> V_35 ) {
F_14 ( & V_25 -> V_35 -> V_20 ,
& V_36 ) ;
F_19 ( V_16 , F_11 ( 0 , V_25 -> V_34 ) ) ;
V_25 -> V_35 = NULL ;
}
}
static T_1 F_31 ( struct V_7 * V_37 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_38 * V_39 ;
if ( ! V_37 )
return 0 ;
V_39 = (struct V_38 * ) F_22 ( V_37 ) ;
if ( ! V_39 )
return 0 ;
return snprintf ( V_4 , V_5 , L_1 ,
V_39 -> V_40 ? L_12 : L_13 ) ;
}
static T_1 F_32 ( struct V_7 * V_37 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_41 * V_42 ;
struct V_38 * V_39 ;
if ( ! V_37 )
return 0 ;
V_39 = (struct V_38 * ) F_22 ( V_37 ) ;
if ( ! V_39 )
return 0 ;
V_42 = V_39 -> V_43 ;
if ( ! V_42 )
return 0 ;
return snprintf ( V_4 , V_5 , L_3 ,
V_39 -> V_40 ? ( V_44 / V_42 -> V_45 ) : 0 ) ;
}
static T_1 F_33 ( struct V_7 * V_37 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_41 * V_42 ;
struct V_38 * V_39 ;
if ( ! V_37 )
return 0 ;
V_39 = (struct V_38 * ) F_22 ( V_37 ) ;
if ( ! V_39 )
return 0 ;
V_42 = V_39 -> V_43 ;
if ( ! V_42 )
return 0 ;
if ( V_42 -> V_46 ) {
return snprintf ( V_4 , V_5 , L_14 ,
( V_42 -> V_47 & V_48 ) ? L_15 : L_16 ,
( V_42 -> V_47 & V_49 ) ? L_17 : L_16 ,
( V_42 -> V_47 & V_50 ) ? L_18 : L_16 ,
( V_42 -> V_47 & V_51 ) ? L_19 : L_16 ,
( V_42 -> V_47 & V_52 ) ? L_20 : L_16 ,
( V_42 -> V_47 & V_53 ) ? L_21 : L_16 ) ;
}
return 0 ;
}
static T_1 F_34 ( struct V_7 * V_37 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_41 * V_42 ;
struct V_38 * V_39 ;
if ( ! V_37 )
return 0 ;
V_39 = (struct V_38 * ) F_22 ( V_37 ) ;
if ( ! V_39 )
return 0 ;
V_42 = V_39 -> V_43 ;
if ( ! V_42 )
return 0 ;
return snprintf ( V_4 , V_5 , L_22 , V_42 -> V_54 ) ;
}
static T_1 F_35 ( struct V_7 * V_37 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_41 * V_42 ;
struct V_38 * V_39 ;
if ( ! V_37 )
return 0 ;
V_39 = (struct V_38 * ) F_22 ( V_37 ) ;
if ( ! V_39 )
return 0 ;
V_42 = V_39 -> V_43 ;
if ( ! V_42 )
return 0 ;
return snprintf ( V_4 , V_5 , L_22 , V_42 -> V_55 ) ;
}
static T_1 F_36 ( struct V_7 * V_37 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_41 * V_42 ;
struct V_38 * V_39 ;
if ( ! V_37 )
return 0 ;
V_39 = (struct V_38 * ) F_22 ( V_37 ) ;
if ( ! V_39 )
return 0 ;
V_42 = V_39 -> V_43 ;
if ( ! V_42 )
return 0 ;
return snprintf ( V_4 , V_5 , L_22 , V_42 -> V_56 ) ;
}
static T_1 F_37 ( struct V_7 * V_37 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_41 * V_42 ;
struct V_38 * V_39 ;
if ( ! V_37 )
return 0 ;
V_39 = (struct V_38 * ) F_22 ( V_37 ) ;
if ( ! V_39 )
return 0 ;
V_42 = V_39 -> V_43 ;
if ( ! V_42 )
return 0 ;
return snprintf ( V_4 , V_5 , L_22 , V_42 -> V_57 . V_58 ) ;
}
static T_1 F_38 ( struct V_7 * V_37 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_41 * V_42 ;
struct V_38 * V_39 ;
if ( ! V_37 )
return 0 ;
V_39 = (struct V_38 * ) F_22 ( V_37 ) ;
if ( ! V_39 )
return 0 ;
V_42 = V_39 -> V_43 ;
if ( ! V_42 )
return 0 ;
return snprintf ( V_4 , V_5 , L_3 , V_42 -> V_59 ) ;
}
static T_1 F_39 ( struct V_7 * V_37 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_41 * V_42 ;
struct V_38 * V_39 ;
if ( ! V_37 )
return 0 ;
V_39 = (struct V_38 * ) F_22 ( V_37 ) ;
if ( ! V_39 )
return 0 ;
V_42 = V_39 -> V_43 ;
if ( ! V_42 )
return 0 ;
return snprintf ( V_4 , V_5 , L_3 , V_42 -> V_60 ) ;
}
static T_1 F_40 ( struct V_7 * V_37 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_24 * V_25 ;
struct V_41 * V_42 ;
struct V_38 * V_39 ;
char V_32 [ 10 ] ;
if ( ! V_37 )
return 0 ;
V_39 = (struct V_38 * ) F_22 ( V_37 ) ;
if ( ! V_39 )
return 0 ;
V_42 = V_39 -> V_43 ;
if ( ! V_42 )
return 0 ;
V_25 = V_42 -> V_61 ;
if ( ! V_25 )
return 0 ;
F_29 ( V_25 -> V_33 , V_32 ) ;
return snprintf ( V_4 , V_5 , L_23 ,
V_39 -> V_62 == V_63 ? L_24 : L_25 ,
V_32 , V_42 -> V_64 ) ;
}
void F_41 ( struct V_38 * V_39 , struct V_7 * V_8 )
{
int V_13 ;
V_13 = F_12 ( & V_8 -> V_20 , & V_65 ) ;
if ( V_13 ) {
F_13 ( L_26 ,
V_22 ) ;
F_14 ( & V_8 -> V_20 , & V_65 ) ;
return;
}
F_30 ( V_8 , V_39 ) ;
}
void F_42 ( struct V_7 * V_8 )
{
F_14 ( & V_8 -> V_20 , & V_65 ) ;
}
