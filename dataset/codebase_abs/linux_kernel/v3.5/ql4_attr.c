static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 , T_2 V_8 ,
T_3 V_9 )
{
struct V_10 * V_11 = F_2 ( F_3 ( F_4 ( V_4 ,
struct V_12 , V_4 ) ) ) ;
if ( ! F_5 ( V_11 ) )
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
if ( ! F_5 ( V_11 ) )
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
F_16 ( V_11 ) ;
V_18 = F_17 ( V_11 , V_26 ) ;
if ( V_18 == V_27 ) {
F_10 ( V_24 , V_11 ,
L_4 ,
V_22 , V_11 -> V_28 ) ;
F_18 ( V_11 , V_26 ,
V_29 ) ;
F_15 ( V_30 , & V_11 -> V_15 ) ;
} else
F_10 ( V_24 , V_11 ,
L_5 ,
V_22 , V_18 ) ;
F_19 ( V_11 ) ;
break;
default:
break;
}
return V_9 ;
}
void F_20 ( struct V_10 * V_11 )
{
struct V_31 * V_32 = V_11 -> V_32 ;
struct V_33 * V_34 ;
int V_20 ;
for ( V_34 = V_35 ; V_34 -> V_36 ; V_34 ++ ) {
V_20 = F_21 ( & V_32 -> V_37 . V_4 ,
V_34 -> V_38 ) ;
if ( V_20 )
F_10 ( V_21 , V_11 ,
L_6 ,
V_34 -> V_36 , V_20 ) ;
}
}
void F_22 ( struct V_10 * V_11 )
{
struct V_31 * V_32 = V_11 -> V_32 ;
struct V_33 * V_34 ;
for ( V_34 = V_35 ; V_34 -> V_36 ; V_34 ++ )
F_23 ( & V_32 -> V_37 . V_4 ,
V_34 -> V_38 ) ;
}
static T_1
F_24 ( struct V_12 * V_39 ,
struct V_40 * V_38 , char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_25 ( V_39 ) ) ;
if ( F_5 ( V_11 ) )
return snprintf ( V_7 , V_41 , L_7 ,
V_11 -> V_42 [ 0 ] ,
V_11 -> V_42 [ 1 ] ,
V_11 -> V_43 , V_11 -> V_44 ) ;
else
return snprintf ( V_7 , V_41 , L_8 ,
V_11 -> V_42 [ 0 ] ,
V_11 -> V_42 [ 1 ] ,
V_11 -> V_43 , V_11 -> V_44 ) ;
}
static T_1
F_26 ( struct V_12 * V_39 , struct V_40 * V_38 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_25 ( V_39 ) ) ;
return snprintf ( V_7 , V_41 , L_9 , V_11 -> V_45 ) ;
}
static T_1
F_27 ( struct V_12 * V_39 , struct V_40 * V_38 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_25 ( V_39 ) ) ;
return snprintf ( V_7 , V_41 , L_10 , V_11 -> V_46 ,
V_11 -> V_47 ) ;
}
static T_1
F_28 ( struct V_12 * V_39 , struct V_40 * V_38 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_25 ( V_39 ) ) ;
return snprintf ( V_7 , V_41 , L_8 ,
V_11 -> V_48 , V_11 -> V_49 ,
V_11 -> V_50 , V_11 -> V_51 ) ;
}
static T_1
F_29 ( struct V_12 * V_39 , struct V_40 * V_38 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_25 ( V_39 ) ) ;
return snprintf ( V_7 , V_41 , L_11 , V_11 -> V_52 ) ;
}
static T_1
F_30 ( struct V_12 * V_39 , struct V_40 * V_38 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_25 ( V_39 ) ) ;
F_31 ( V_11 ) ;
return snprintf ( V_7 , V_41 , L_12 , V_11 -> V_53 ,
V_11 -> V_54 ) ;
}
static T_1
F_32 ( struct V_12 * V_39 , struct V_40 * V_38 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_25 ( V_39 ) ) ;
if ( ! F_5 ( V_11 ) )
return - V_55 ;
return snprintf ( V_7 , V_41 , L_13 , V_11 -> V_56 ) ;
}
static T_1
F_33 ( struct V_12 * V_39 , struct V_40 * V_38 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_25 ( V_39 ) ) ;
if ( ! F_5 ( V_11 ) )
return - V_55 ;
return snprintf ( V_7 , V_41 , L_13 , V_11 -> V_57 ) ;
}
static T_1
F_34 ( struct V_12 * V_39 , struct V_40 * V_38 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_25 ( V_39 ) ) ;
if ( ! F_5 ( V_11 ) )
return - V_55 ;
return snprintf ( V_7 , V_41 , L_13 , V_11 -> V_58 ) ;
}
static T_1
F_35 ( struct V_12 * V_39 , struct V_40 * V_38 ,
char * V_7 )
{
struct V_10 * V_11 = F_2 ( F_25 ( V_39 ) ) ;
return snprintf ( V_7 , V_41 , L_9 , V_11 -> V_59 ) ;
}
