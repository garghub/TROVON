static T_1
F_1 ( T_1 V_1 , T_2 V_2 )
{
if ( V_2 != 4 ) {
switch ( V_1 ) {
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
break;
case V_9 :
V_1 = V_4 ;
break;
default:
V_1 = V_5 ;
}
}
return ( V_1 ) ;
}
static T_1
F_2 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_14 * * V_15 , struct V_16 * * V_17 )
{
struct V_14 * V_18 = NULL ;
struct V_16 * V_19 = NULL ;
struct V_20 * V_21 = & V_13 -> V_21 ;
T_1 error = 0 ;
if ( ! V_22 )
return V_5 ;
if ( ! ( V_18 = F_3 ( V_11 , V_21 -> V_23 , V_21 -> V_24 ) )
|| ( V_13 -> V_25 && F_4 ( V_18 ) < 0 ) )
goto V_26;
* V_15 = V_18 ;
if ( V_17 != NULL ) {
error = F_5 ( F_6 ( V_11 , & V_19 , & V_21 -> V_27 ) ) ;
if ( error != 0 )
goto V_26;
* V_17 = V_19 ;
V_21 -> V_28 . V_29 = V_19 -> V_30 ;
V_21 -> V_28 . V_31 = ( V_32 ) V_18 ;
V_21 -> V_28 . V_33 = & V_34 ;
}
return 0 ;
V_26:
F_7 ( V_18 ) ;
if ( error )
return error ;
return V_5 ;
}
static T_1
F_8 ( struct V_10 * V_11 )
{
F_9 ( L_1 ) ;
return V_35 ;
}
static T_1
F_10 ( struct V_10 * V_11 , struct V_36 * V_37 )
{
struct V_12 * V_13 = V_11 -> V_38 ;
struct V_14 * V_18 ;
struct V_16 * V_19 ;
T_1 V_39 = V_35 ;
F_9 ( L_2 ) ;
V_37 -> V_40 = V_13 -> V_40 ;
if ( ( V_37 -> V_1 = F_2 ( V_11 , V_13 , & V_18 , & V_19 ) ) )
return V_37 -> V_1 == V_8 ? V_41 : V_35 ;
V_37 -> V_1 = F_5 ( F_11 ( V_11 , V_19 , V_18 , & V_13 -> V_21 , & V_37 -> V_21 , & V_37 -> V_40 ) ) ;
if ( V_37 -> V_1 == V_8 )
V_39 = V_41 ;
else
F_9 ( L_3 ,
F_12 ( V_37 -> V_1 ) , V_11 -> V_42 ) ;
F_7 ( V_18 ) ;
F_13 ( V_19 ) ;
return V_39 ;
}
static T_1
F_14 ( struct V_10 * V_11 )
{
return F_10 ( V_11 , V_11 -> V_43 ) ;
}
static T_1
F_15 ( struct V_10 * V_11 , struct V_36 * V_37 )
{
struct V_12 * V_13 = V_11 -> V_38 ;
struct V_14 * V_18 ;
struct V_16 * V_19 ;
T_1 V_39 = V_35 ;
F_9 ( L_4 ) ;
V_37 -> V_40 = V_13 -> V_40 ;
if ( ( V_37 -> V_1 = F_2 ( V_11 , V_13 , & V_18 , & V_19 ) ) )
return V_37 -> V_1 == V_8 ? V_41 : V_35 ;
#if 0
if (host->h_nsmstate && host->h_nsmstate != argp->state) {
resp->status = nlm_lck_denied_nolocks;
} else
#endif
V_37 -> V_1 = F_5 ( F_16 ( V_11 , V_19 , V_18 , & V_13 -> V_21 ,
V_13 -> V_44 , & V_13 -> V_40 ,
V_13 -> V_45 ) ) ;
if ( V_37 -> V_1 == V_8 )
V_39 = V_41 ;
else
F_9 ( L_5 , F_12 ( V_37 -> V_1 ) ) ;
F_7 ( V_18 ) ;
F_13 ( V_19 ) ;
return V_39 ;
}
static T_1
F_17 ( struct V_10 * V_11 )
{
return F_15 ( V_11 , V_11 -> V_43 ) ;
}
static T_1
F_18 ( struct V_10 * V_11 , struct V_36 * V_37 )
{
struct V_12 * V_13 = V_11 -> V_38 ;
struct V_14 * V_18 ;
struct V_16 * V_19 ;
struct V_46 * V_46 = F_19 ( V_11 ) ;
F_9 ( L_6 ) ;
V_37 -> V_40 = V_13 -> V_40 ;
if ( F_20 ( V_46 ) ) {
V_37 -> V_1 = V_7 ;
return V_35 ;
}
if ( ( V_37 -> V_1 = F_2 ( V_11 , V_13 , & V_18 , & V_19 ) ) )
return V_37 -> V_1 == V_8 ? V_41 : V_35 ;
V_37 -> V_1 = F_5 ( F_21 ( V_46 , V_19 , & V_13 -> V_21 ) ) ;
F_9 ( L_7 , F_12 ( V_37 -> V_1 ) ) ;
F_7 ( V_18 ) ;
F_13 ( V_19 ) ;
return V_35 ;
}
static T_1
F_22 ( struct V_10 * V_11 )
{
return F_18 ( V_11 , V_11 -> V_43 ) ;
}
static T_1
F_23 ( struct V_10 * V_11 , struct V_36 * V_37 )
{
struct V_12 * V_13 = V_11 -> V_38 ;
struct V_14 * V_18 ;
struct V_16 * V_19 ;
struct V_46 * V_46 = F_19 ( V_11 ) ;
F_9 ( L_8 ) ;
V_37 -> V_40 = V_13 -> V_40 ;
if ( F_20 ( V_46 ) ) {
V_37 -> V_1 = V_7 ;
return V_35 ;
}
if ( ( V_37 -> V_1 = F_2 ( V_11 , V_13 , & V_18 , & V_19 ) ) )
return V_37 -> V_1 == V_8 ? V_41 : V_35 ;
V_37 -> V_1 = F_5 ( F_24 ( V_46 , V_19 , & V_13 -> V_21 ) ) ;
F_9 ( L_9 , F_12 ( V_37 -> V_1 ) ) ;
F_7 ( V_18 ) ;
F_13 ( V_19 ) ;
return V_35 ;
}
static T_1
F_25 ( struct V_10 * V_11 )
{
return F_23 ( V_11 , V_11 -> V_43 ) ;
}
static T_1
F_26 ( struct V_10 * V_11 , struct V_36 * V_37 )
{
struct V_12 * V_13 = V_11 -> V_38 ;
V_37 -> V_40 = V_13 -> V_40 ;
F_9 ( L_10 ) ;
V_37 -> V_1 = F_27 ( F_28 ( V_11 ) , & V_13 -> V_21 ) ;
F_9 ( L_11 , F_12 ( V_37 -> V_1 ) ) ;
return V_35 ;
}
static T_1
F_29 ( struct V_10 * V_11 )
{
return F_26 ( V_11 , V_11 -> V_43 ) ;
}
static void F_30 ( struct V_47 * V_48 , void * V_49 )
{
F_9 ( L_12 , V_48 -> V_50 ,
- V_48 -> V_51 ) ;
}
void F_31 ( struct V_52 * V_53 )
{
if ( ! F_32 ( & V_53 -> V_54 ) )
return;
F_7 ( V_53 -> V_55 ) ;
F_33 ( V_53 ) ;
}
static void F_34 ( void * V_49 )
{
F_31 ( V_49 ) ;
}
static T_1 F_35 ( struct V_10 * V_11 , T_2 V_56 ,
T_1 (* F_36)( struct V_10 * , struct V_36 * ) )
{
struct V_12 * V_13 = V_11 -> V_38 ;
struct V_14 * V_18 ;
struct V_52 * V_53 ;
T_1 V_57 ;
V_18 = F_3 ( V_11 ,
V_13 -> V_21 . V_23 ,
V_13 -> V_21 . V_24 ) ;
if ( V_18 == NULL )
return V_58 ;
V_53 = F_37 ( V_18 ) ;
F_7 ( V_18 ) ;
if ( V_53 == NULL )
return V_58 ;
V_57 = F_36 ( V_11 , & V_53 -> V_59 ) ;
if ( V_57 != 0 ) {
F_31 ( V_53 ) ;
return V_57 ;
}
V_53 -> V_60 = V_61 ;
if ( F_38 ( V_53 , V_56 , & V_62 ) < 0 )
return V_58 ;
return V_35 ;
}
static T_1 F_39 ( struct V_10 * V_11 )
{
F_9 ( L_13 ) ;
return F_35 ( V_11 , V_63 , F_10 ) ;
}
static T_1 F_40 ( struct V_10 * V_11 )
{
F_9 ( L_14 ) ;
return F_35 ( V_11 , V_64 , F_15 ) ;
}
static T_1 F_41 ( struct V_10 * V_11 )
{
F_9 ( L_15 ) ;
return F_35 ( V_11 , V_65 , F_18 ) ;
}
static T_1
F_42 ( struct V_10 * V_11 )
{
F_9 ( L_16 ) ;
return F_35 ( V_11 , V_66 , F_23 ) ;
}
static T_1
F_43 ( struct V_10 * V_11 )
{
F_9 ( L_17 ) ;
return F_35 ( V_11 , V_67 , F_26 ) ;
}
static T_1
F_44 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_38 ;
struct V_36 * V_37 = V_11 -> V_43 ;
struct V_14 * V_18 ;
struct V_16 * V_19 ;
F_9 ( L_18 ) ;
V_37 -> V_40 = V_13 -> V_40 ;
if ( F_20 ( F_19 ( V_11 ) ) && ! V_13 -> V_45 ) {
V_37 -> V_1 = V_7 ;
return V_35 ;
}
if ( ( V_37 -> V_1 = F_2 ( V_11 , V_13 , & V_18 , & V_19 ) ) )
return V_37 -> V_1 == V_8 ? V_41 : V_35 ;
V_37 -> V_1 = F_5 ( F_45 ( V_18 , V_19 , V_13 ) ) ;
F_9 ( L_19 , F_12 ( V_37 -> V_1 ) ) ;
F_7 ( V_18 ) ;
F_13 ( V_19 ) ;
return V_35 ;
}
static T_1
F_46 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_38 ;
struct V_36 * V_37 = V_11 -> V_43 ;
struct V_14 * V_18 ;
struct V_16 * V_19 ;
F_9 ( L_20 ) ;
V_37 -> V_40 = V_13 -> V_40 ;
if ( F_20 ( F_19 ( V_11 ) ) ) {
V_37 -> V_1 = V_7 ;
return V_35 ;
}
if ( ( V_37 -> V_1 = F_2 ( V_11 , V_13 , & V_18 , & V_19 ) ) )
return V_37 -> V_1 == V_8 ? V_41 : V_35 ;
V_37 -> V_1 = F_5 ( F_47 ( V_18 , V_19 , V_13 ) ) ;
F_9 ( L_21 , F_12 ( V_37 -> V_1 ) ) ;
F_7 ( V_18 ) ;
F_13 ( V_19 ) ;
return V_35 ;
}
static T_1
F_48 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_38 ;
F_9 ( L_22 ) ;
V_13 -> V_25 = 0 ;
return F_17 ( V_11 ) ;
}
static T_1
F_49 ( struct V_10 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_38 ;
struct V_14 * V_18 ;
if ( F_2 ( V_11 , V_13 , & V_18 , NULL ) )
return V_35 ;
F_50 ( V_18 ) ;
F_7 ( V_18 ) ;
return V_35 ;
}
static T_1
F_51 ( struct V_10 * V_11 )
{
struct V_68 * V_13 = V_11 -> V_38 ;
F_9 ( L_23 ) ;
if ( ! F_52 ( V_11 ) ) {
char V_69 [ V_70 ] ;
F_53 ( V_71 L_24 ,
F_54 ( V_11 , V_69 , sizeof( V_69 ) ) ) ;
return V_58 ;
}
F_55 ( F_19 ( V_11 ) , V_13 ) ;
return V_35 ;
}
static T_1
F_56 ( struct V_10 * V_11 )
{
struct V_36 * V_13 = V_11 -> V_38 ;
if ( ! V_22 )
return V_35 ;
F_9 ( L_25 ) ;
F_57 ( & V_13 -> V_40 , V_13 -> V_1 ) ;
return V_35 ;
}
