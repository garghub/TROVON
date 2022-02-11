static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 , T_2 V_8 ,
T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
if ( F_5 ( V_11 ) )
return - V_13 ;
if ( ! F_6 ( V_14 , & V_11 -> V_15 ) )
return 0 ;
return F_7 ( V_7 , V_9 , & V_8 , V_11 -> V_16 ,
V_11 -> V_17 ) ;
}
static T_1
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 , T_2 V_8 ,
T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
T_4 V_18 ;
long V_19 ;
int V_20 = 0 ;
if ( F_5 ( V_11 ) )
return - V_13 ;
if ( V_8 != 0 )
return V_20 ;
V_7 [ 1 ] = 0 ;
V_20 = F_9 ( V_7 , 10 , & V_19 ) ;
if ( V_20 ) {
F_10 ( V_21 , V_11 , L_1 ,
V_22 , V_20 ) ;
return V_20 ;
}
switch ( V_19 ) {
case 0 :
if ( F_11 ( V_14 , & V_11 -> V_15 ) ) {
F_12 ( V_23 , & V_11 -> V_15 ) ;
F_13 ( V_11 ) ;
F_14 ( F_10 ( V_24 , V_11 ,
L_2 ) ) ;
}
break;
case 1 :
if ( F_6 ( V_23 , & V_11 -> V_15 ) &&
! F_6 ( V_14 , & V_11 -> V_15 ) ) {
F_15 ( V_14 , & V_11 -> V_15 ) ;
F_14 ( F_10 ( V_24 , V_11 ,
L_3 ,
V_11 -> V_25 ) ) ;
}
break;
case 2 :
V_11 -> V_26 -> V_27 ( V_11 ) ;
V_18 = F_16 ( V_11 , V_28 ) ;
if ( V_18 == V_29 ) {
F_10 ( V_24 , V_11 , L_4 ,
V_22 ) ;
F_17 ( V_11 , V_28 ,
V_30 ) ;
if ( F_18 ( V_11 ) ||
( ( F_19 ( V_11 ) || F_20 ( V_11 ) ) &&
F_21 ( V_11 ) ) ) {
F_15 ( V_31 , & V_11 -> V_15 ) ;
F_15 ( V_32 , & V_11 -> V_15 ) ;
F_10 ( V_24 , V_11 , L_5 ,
V_22 , V_11 -> V_33 ) ;
}
} else
F_10 ( V_24 , V_11 ,
L_6 ,
V_22 , V_18 ) ;
V_11 -> V_26 -> V_34 ( V_11 ) ;
break;
default:
break;
}
return V_9 ;
}
void F_22 ( struct V_10 * V_11 )
{
struct V_35 * V_36 = V_11 -> V_36 ;
struct V_37 * V_38 ;
int V_20 ;
for ( V_38 = V_39 ; V_38 -> V_40 ; V_38 ++ ) {
V_20 = F_23 ( & V_36 -> V_41 . V_4 ,
V_38 -> V_42 ) ;
if ( V_20 )
F_10 ( V_21 , V_11 ,
L_7 ,
V_38 -> V_40 , V_20 ) ;
}
}
void F_24 ( struct V_10 * V_11 )
{
struct V_35 * V_36 = V_11 -> V_36 ;
struct V_37 * V_38 ;
for ( V_38 = V_39 ; V_38 -> V_40 ; V_38 ++ )
F_25 ( & V_36 -> V_41 . V_4 ,
V_38 -> V_42 ) ;
}
static T_1
F_26 ( struct V_12 * V_43 ,
struct V_44 * V_42 , char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
if ( F_28 ( V_11 ) )
return snprintf ( V_7 , V_45 , L_8 ,
V_11 -> V_46 . V_47 , V_11 -> V_46 . V_48 ,
V_11 -> V_46 . V_49 , V_11 -> V_46 . V_50 ) ;
else
return snprintf ( V_7 , V_45 , L_9 ,
V_11 -> V_46 . V_47 , V_11 -> V_46 . V_48 ,
V_11 -> V_46 . V_49 , V_11 -> V_46 . V_50 ) ;
}
static T_1
F_29 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
return snprintf ( V_7 , V_45 , L_10 , V_11 -> V_51 ) ;
}
static T_1
F_30 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
return snprintf ( V_7 , V_45 , L_11 , V_11 -> V_46 . V_52 ,
V_11 -> V_46 . V_53 ) ;
}
static T_1
F_31 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
return snprintf ( V_7 , V_45 , L_9 ,
V_11 -> V_46 . V_54 , V_11 -> V_46 . V_55 ,
V_11 -> V_46 . V_56 , V_11 -> V_46 . V_57 ) ;
}
static T_1
F_32 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
return snprintf ( V_7 , V_45 , L_12 , V_11 -> V_58 ) ;
}
static T_1
F_33 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
F_34 ( V_11 ) ;
return snprintf ( V_7 , V_45 , L_13 , V_11 -> V_59 ,
V_11 -> V_60 ) ;
}
static T_1
F_35 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
if ( F_5 ( V_11 ) )
return - V_61 ;
return snprintf ( V_7 , V_45 , L_14 , V_11 -> V_62 ) ;
}
static T_1
F_36 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
if ( F_5 ( V_11 ) )
return - V_61 ;
return snprintf ( V_7 , V_45 , L_14 , V_11 -> V_63 ) ;
}
static T_1
F_37 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
if ( F_5 ( V_11 ) )
return - V_61 ;
return snprintf ( V_7 , V_45 , L_14 , V_11 -> V_64 ) ;
}
static T_1
F_38 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
return snprintf ( V_7 , V_45 , L_10 , V_11 -> V_65 ) ;
}
static T_1
F_39 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
return snprintf ( V_7 , V_45 , L_15 , V_11 -> V_46 . V_66 ,
V_11 -> V_46 . V_67 ) ;
}
static T_1
F_40 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
return snprintf ( V_7 , V_45 , L_10 , V_11 -> V_46 . V_68 ) ;
}
static T_1
F_41 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
return snprintf ( V_7 , V_45 , L_10 , V_11 -> V_46 . V_69 ) ;
}
static T_1
F_42 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
char * V_70 = NULL ;
switch ( V_11 -> V_46 . V_71 ) {
case 1 :
V_70 = L_16 ;
break;
case 2 :
V_70 = L_17 ;
break;
case 3 :
V_70 = L_18 ;
break;
}
return snprintf ( V_7 , V_45 , L_10 , V_70 ) ;
}
static T_1
F_43 ( struct V_12 * V_43 , struct V_44 * V_42 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_27 ( V_43 ) ) ;
F_44 ( V_11 ) ;
return snprintf ( V_7 , V_45 , L_19 , V_11 -> V_72 ,
V_11 -> V_73 ) ;
}
