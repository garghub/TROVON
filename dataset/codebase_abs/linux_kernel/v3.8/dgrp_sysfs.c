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
void F_5 ( void )
{
int V_12 = 0 ;
int V_13 = 1U << ( 32 - V_14 ) ;
V_15 = F_6 ( V_16 , L_5 ) ;
V_12 = F_7 ( V_15 , & V_17 ) ;
V_18 = F_8 ( V_15 , NULL ,
F_9 ( 0 , V_13 + 1 ) , NULL , L_6 ) ;
V_12 = F_10 ( & V_18 -> V_19 ,
& V_20 ) ;
if ( V_12 ) {
F_11 ( L_7 ,
V_21 ) ;
F_12 ( & V_18 -> V_19 ,
& V_20 ) ;
return;
}
V_22 = F_8 ( V_15 , NULL ,
F_9 ( 0 , V_13 + 2 ) , NULL , L_8 ) ;
}
void F_13 ( void )
{
struct V_23 * V_24 ;
int V_13 = 1U << ( 32 - V_14 ) ;
F_14 (nd, &nd_struct_list, list)
F_15 ( V_24 ) ;
F_12 ( & V_18 -> V_19 ,
& V_20 ) ;
F_16 ( V_15 , & V_17 ) ;
F_17 ( V_15 , F_9 ( 0 , V_13 + 1 ) ) ;
F_17 ( V_15 , F_9 ( 0 , V_13 + 2 ) ) ;
F_18 ( V_15 ) ;
}
static T_1 F_19 ( struct V_7 * V_8 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_23 * V_24 ;
if ( ! V_8 )
return 0 ;
V_24 = (struct V_23 * ) F_20 ( V_8 ) ;
if ( ! V_24 )
return 0 ;
return snprintf ( V_4 , V_5 , L_1 , F_21 ( V_24 -> V_25 ) ) ;
}
static T_1 F_22 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
struct V_23 * V_24 ;
if ( ! V_8 )
return 0 ;
V_24 = (struct V_23 * ) F_20 ( V_8 ) ;
if ( ! V_24 )
return 0 ;
if ( V_24 -> V_25 == V_26 )
return snprintf ( V_4 , V_5 , L_1 , V_24 -> V_27 ) ;
return 0 ;
}
static T_1 F_23 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
struct V_23 * V_24 ;
if ( ! V_8 )
return 0 ;
V_24 = (struct V_23 * ) F_20 ( V_8 ) ;
if ( ! V_24 )
return 0 ;
if ( V_24 -> V_25 == V_26 )
return snprintf ( V_4 , V_5 , L_9 ,
( V_24 -> V_28 >> 8 ) & 0xff ,
V_24 -> V_28 & 0xff ) ;
return 0 ;
}
static T_1 F_24 ( struct V_7 * V_8 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_23 * V_24 ;
if ( ! V_8 )
return 0 ;
V_24 = (struct V_23 * ) F_20 ( V_8 ) ;
if ( ! V_24 )
return 0 ;
if ( V_24 -> V_25 == V_26 )
return snprintf ( V_4 , V_5 , L_3 , V_24 -> V_29 ) ;
return 0 ;
}
static T_1 F_25 ( struct V_7 * V_8 ,
struct V_9 * V_3 ,
char * V_4 )
{
struct V_23 * V_24 ;
if ( ! V_8 )
return 0 ;
V_24 = (struct V_23 * ) F_20 ( V_8 ) ;
if ( ! V_24 )
return 0 ;
if ( V_24 -> V_25 == V_26 )
return snprintf ( V_4 , V_5 , L_9 ,
( V_24 -> V_30 >> 8 ) & 0xff ,
V_24 -> V_30 & 0xff ) ;
return 0 ;
}
void F_26 ( struct V_23 * V_24 )
{
int V_12 ;
char V_31 [ 10 ] ;
if ( V_24 -> V_32 )
F_27 ( V_24 -> V_32 , V_31 ) ;
else
sprintf ( V_31 , L_10 , V_24 -> V_33 ) ;
V_24 -> V_34 = F_8 ( V_15 , V_22 ,
F_9 ( 0 , V_24 -> V_33 ) , NULL , V_31 ) ;
V_12 = F_10 ( & V_24 -> V_34 -> V_19 ,
& V_35 ) ;
if ( V_12 ) {
F_11 ( L_11 ,
V_21 ) ;
F_12 ( & V_24 -> V_34 -> V_19 ,
& V_35 ) ;
return;
}
F_28 ( V_24 -> V_34 , V_24 ) ;
}
void F_15 ( struct V_23 * V_24 )
{
if ( V_24 -> V_34 ) {
F_12 ( & V_24 -> V_34 -> V_19 ,
& V_35 ) ;
F_17 ( V_15 , F_9 ( 0 , V_24 -> V_33 ) ) ;
V_24 -> V_34 = NULL ;
}
}
static T_1 F_29 ( struct V_7 * V_36 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_37 * V_38 ;
if ( ! V_36 )
return 0 ;
V_38 = (struct V_37 * ) F_20 ( V_36 ) ;
if ( ! V_38 )
return 0 ;
return snprintf ( V_4 , V_5 , L_1 ,
V_38 -> V_39 ? L_12 : L_13 ) ;
}
static T_1 F_30 ( struct V_7 * V_36 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_40 * V_41 ;
struct V_37 * V_38 ;
if ( ! V_36 )
return 0 ;
V_38 = (struct V_37 * ) F_20 ( V_36 ) ;
if ( ! V_38 )
return 0 ;
V_41 = V_38 -> V_42 ;
if ( ! V_41 )
return 0 ;
return snprintf ( V_4 , V_5 , L_3 ,
V_38 -> V_39 ? ( V_43 / V_41 -> V_44 ) : 0 ) ;
}
static T_1 F_31 ( struct V_7 * V_36 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_40 * V_41 ;
struct V_37 * V_38 ;
if ( ! V_36 )
return 0 ;
V_38 = (struct V_37 * ) F_20 ( V_36 ) ;
if ( ! V_38 )
return 0 ;
V_41 = V_38 -> V_42 ;
if ( ! V_41 )
return 0 ;
if ( V_41 -> V_45 ) {
return snprintf ( V_4 , V_5 , L_14 ,
( V_41 -> V_46 & V_47 ) ? L_15 : L_16 ,
( V_41 -> V_46 & V_48 ) ? L_17 : L_16 ,
( V_41 -> V_46 & V_49 ) ? L_18 : L_16 ,
( V_41 -> V_46 & V_50 ) ? L_19 : L_16 ,
( V_41 -> V_46 & V_51 ) ? L_20 : L_16 ,
( V_41 -> V_46 & V_52 ) ? L_21 : L_16 ) ;
}
return 0 ;
}
static T_1 F_32 ( struct V_7 * V_36 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_40 * V_41 ;
struct V_37 * V_38 ;
if ( ! V_36 )
return 0 ;
V_38 = (struct V_37 * ) F_20 ( V_36 ) ;
if ( ! V_38 )
return 0 ;
V_41 = V_38 -> V_42 ;
if ( ! V_41 )
return 0 ;
return snprintf ( V_4 , V_5 , L_22 , V_41 -> V_53 ) ;
}
static T_1 F_33 ( struct V_7 * V_36 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_40 * V_41 ;
struct V_37 * V_38 ;
if ( ! V_36 )
return 0 ;
V_38 = (struct V_37 * ) F_20 ( V_36 ) ;
if ( ! V_38 )
return 0 ;
V_41 = V_38 -> V_42 ;
if ( ! V_41 )
return 0 ;
return snprintf ( V_4 , V_5 , L_22 , V_41 -> V_54 ) ;
}
static T_1 F_34 ( struct V_7 * V_36 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_40 * V_41 ;
struct V_37 * V_38 ;
if ( ! V_36 )
return 0 ;
V_38 = (struct V_37 * ) F_20 ( V_36 ) ;
if ( ! V_38 )
return 0 ;
V_41 = V_38 -> V_42 ;
if ( ! V_41 )
return 0 ;
return snprintf ( V_4 , V_5 , L_22 , V_41 -> V_55 ) ;
}
static T_1 F_35 ( struct V_7 * V_36 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_40 * V_41 ;
struct V_37 * V_38 ;
if ( ! V_36 )
return 0 ;
V_38 = (struct V_37 * ) F_20 ( V_36 ) ;
if ( ! V_38 )
return 0 ;
V_41 = V_38 -> V_42 ;
if ( ! V_41 )
return 0 ;
return snprintf ( V_4 , V_5 , L_22 , V_41 -> V_56 . V_57 ) ;
}
static T_1 F_36 ( struct V_7 * V_36 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_40 * V_41 ;
struct V_37 * V_38 ;
if ( ! V_36 )
return 0 ;
V_38 = (struct V_37 * ) F_20 ( V_36 ) ;
if ( ! V_38 )
return 0 ;
V_41 = V_38 -> V_42 ;
if ( ! V_41 )
return 0 ;
return snprintf ( V_4 , V_5 , L_3 , V_41 -> V_58 ) ;
}
static T_1 F_37 ( struct V_7 * V_36 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_40 * V_41 ;
struct V_37 * V_38 ;
if ( ! V_36 )
return 0 ;
V_38 = (struct V_37 * ) F_20 ( V_36 ) ;
if ( ! V_38 )
return 0 ;
V_41 = V_38 -> V_42 ;
if ( ! V_41 )
return 0 ;
return snprintf ( V_4 , V_5 , L_3 , V_41 -> V_59 ) ;
}
static T_1 F_38 ( struct V_7 * V_36 ,
struct V_9 * V_3 , char * V_4 )
{
struct V_23 * V_24 ;
struct V_40 * V_41 ;
struct V_37 * V_38 ;
char V_31 [ 10 ] ;
if ( ! V_36 )
return 0 ;
V_38 = (struct V_37 * ) F_20 ( V_36 ) ;
if ( ! V_38 )
return 0 ;
V_41 = V_38 -> V_42 ;
if ( ! V_41 )
return 0 ;
V_24 = V_41 -> V_60 ;
if ( ! V_24 )
return 0 ;
F_27 ( V_24 -> V_32 , V_31 ) ;
return snprintf ( V_4 , V_5 , L_23 ,
V_38 -> V_61 == V_62 ? L_24 : L_25 ,
V_31 , V_41 -> V_63 ) ;
}
void F_39 ( struct V_37 * V_38 , struct V_7 * V_8 )
{
int V_12 ;
V_12 = F_10 ( & V_8 -> V_19 , & V_64 ) ;
if ( V_12 ) {
F_11 ( L_26 ,
V_21 ) ;
F_12 ( & V_8 -> V_19 , & V_64 ) ;
return;
}
F_28 ( V_8 , V_38 ) ;
}
void F_40 ( struct V_7 * V_8 )
{
F_12 ( & V_8 -> V_19 , & V_64 ) ;
}
