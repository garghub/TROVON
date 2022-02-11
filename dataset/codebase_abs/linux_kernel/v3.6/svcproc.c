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
if ( ( error = F_5 ( V_11 , & V_19 , & V_21 -> V_27 ) ) != 0 )
goto V_26;
* V_17 = V_19 ;
V_21 -> V_28 . V_29 = V_19 -> V_30 ;
V_21 -> V_28 . V_31 = ( V_32 ) V_18 ;
V_21 -> V_28 . V_33 = & V_34 ;
}
return 0 ;
V_26:
F_6 ( V_18 ) ;
if ( error )
return error ;
return V_5 ;
}
static T_1
F_7 ( struct V_10 * V_11 , void * V_13 , void * V_35 )
{
F_8 ( L_1 ) ;
return V_36 ;
}
static T_1
F_9 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_37 * V_35 )
{
struct V_14 * V_18 ;
struct V_16 * V_19 ;
T_1 V_38 = V_36 ;
F_8 ( L_2 ) ;
V_35 -> V_39 = V_13 -> V_39 ;
if ( ( V_35 -> V_1 = F_2 ( V_11 , V_13 , & V_18 , & V_19 ) ) )
return V_35 -> V_1 == V_8 ? V_40 : V_36 ;
V_35 -> V_1 = F_10 ( F_11 ( V_11 , V_19 , V_18 , & V_13 -> V_21 , & V_35 -> V_21 , & V_35 -> V_39 ) ) ;
if ( V_35 -> V_1 == V_8 )
V_38 = V_40 ;
else
F_8 ( L_3 ,
F_12 ( V_35 -> V_1 ) , V_11 -> V_41 ) ;
F_6 ( V_18 ) ;
F_13 ( V_19 ) ;
return V_38 ;
}
static T_1
F_14 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_37 * V_35 )
{
struct V_14 * V_18 ;
struct V_16 * V_19 ;
T_1 V_38 = V_36 ;
F_8 ( L_4 ) ;
V_35 -> V_39 = V_13 -> V_39 ;
if ( ( V_35 -> V_1 = F_2 ( V_11 , V_13 , & V_18 , & V_19 ) ) )
return V_35 -> V_1 == V_8 ? V_40 : V_36 ;
#if 0
if (host->h_nsmstate && host->h_nsmstate != argp->state) {
resp->status = nlm_lck_denied_nolocks;
} else
#endif
V_35 -> V_1 = F_10 ( F_15 ( V_11 , V_19 , V_18 , & V_13 -> V_21 ,
V_13 -> V_42 , & V_13 -> V_39 ,
V_13 -> V_43 ) ) ;
if ( V_35 -> V_1 == V_8 )
V_38 = V_40 ;
else
F_8 ( L_5 , F_12 ( V_35 -> V_1 ) ) ;
F_6 ( V_18 ) ;
F_13 ( V_19 ) ;
return V_38 ;
}
static T_1
F_16 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_37 * V_35 )
{
struct V_14 * V_18 ;
struct V_16 * V_19 ;
struct V_44 * V_44 = F_17 ( V_11 ) ;
F_8 ( L_6 ) ;
V_35 -> V_39 = V_13 -> V_39 ;
if ( F_18 ( V_44 ) ) {
V_35 -> V_1 = V_7 ;
return V_36 ;
}
if ( ( V_35 -> V_1 = F_2 ( V_11 , V_13 , & V_18 , & V_19 ) ) )
return V_35 -> V_1 == V_8 ? V_40 : V_36 ;
V_35 -> V_1 = F_10 ( F_19 ( V_44 , V_19 , & V_13 -> V_21 ) ) ;
F_8 ( L_7 , F_12 ( V_35 -> V_1 ) ) ;
F_6 ( V_18 ) ;
F_13 ( V_19 ) ;
return V_36 ;
}
static T_1
F_20 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_37 * V_35 )
{
struct V_14 * V_18 ;
struct V_16 * V_19 ;
struct V_44 * V_44 = F_17 ( V_11 ) ;
F_8 ( L_8 ) ;
V_35 -> V_39 = V_13 -> V_39 ;
if ( F_18 ( V_44 ) ) {
V_35 -> V_1 = V_7 ;
return V_36 ;
}
if ( ( V_35 -> V_1 = F_2 ( V_11 , V_13 , & V_18 , & V_19 ) ) )
return V_35 -> V_1 == V_8 ? V_40 : V_36 ;
V_35 -> V_1 = F_10 ( F_21 ( V_44 , V_19 , & V_13 -> V_21 ) ) ;
F_8 ( L_9 , F_12 ( V_35 -> V_1 ) ) ;
F_6 ( V_18 ) ;
F_13 ( V_19 ) ;
return V_36 ;
}
static T_1
F_22 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_37 * V_35 )
{
V_35 -> V_39 = V_13 -> V_39 ;
F_8 ( L_10 ) ;
V_35 -> V_1 = F_23 ( F_24 ( V_11 ) , & V_13 -> V_21 ) ;
F_8 ( L_11 , F_12 ( V_35 -> V_1 ) ) ;
return V_36 ;
}
static void F_25 ( struct V_45 * V_46 , void * V_47 )
{
F_8 ( L_12 , V_46 -> V_48 ,
- V_46 -> V_49 ) ;
}
void F_26 ( struct V_50 * V_51 )
{
if ( ! F_27 ( & V_51 -> V_52 ) )
return;
F_6 ( V_51 -> V_53 ) ;
F_28 ( V_51 ) ;
}
static void F_29 ( void * V_47 )
{
F_26 ( V_47 ) ;
}
static T_1 F_30 ( struct V_10 * V_11 , T_2 V_54 , struct V_12 * V_13 ,
T_1 (* F_31)( struct V_10 * , struct V_12 * , struct V_37 * ) )
{
struct V_14 * V_18 ;
struct V_50 * V_51 ;
T_1 V_55 ;
V_18 = F_3 ( V_11 ,
V_13 -> V_21 . V_23 ,
V_13 -> V_21 . V_24 ) ;
if ( V_18 == NULL )
return V_56 ;
V_51 = F_32 ( V_18 ) ;
F_6 ( V_18 ) ;
if ( V_51 == NULL )
return V_56 ;
V_55 = F_31 ( V_11 , V_13 , & V_51 -> V_57 ) ;
if ( V_55 != 0 ) {
F_26 ( V_51 ) ;
return V_55 ;
}
V_51 -> V_58 = V_59 ;
if ( F_33 ( V_51 , V_54 , & V_60 ) < 0 )
return V_56 ;
return V_36 ;
}
static T_1 F_34 ( struct V_10 * V_11 , struct V_12 * V_13 ,
void * V_35 )
{
F_8 ( L_13 ) ;
return F_30 ( V_11 , V_61 , V_13 , F_9 ) ;
}
static T_1 F_35 ( struct V_10 * V_11 , struct V_12 * V_13 ,
void * V_35 )
{
F_8 ( L_14 ) ;
return F_30 ( V_11 , V_62 , V_13 , F_14 ) ;
}
static T_1 F_36 ( struct V_10 * V_11 , struct V_12 * V_13 ,
void * V_35 )
{
F_8 ( L_15 ) ;
return F_30 ( V_11 , V_63 , V_13 , F_16 ) ;
}
static T_1
F_37 ( struct V_10 * V_11 , struct V_12 * V_13 ,
void * V_35 )
{
F_8 ( L_16 ) ;
return F_30 ( V_11 , V_64 , V_13 , F_20 ) ;
}
static T_1
F_38 ( struct V_10 * V_11 , struct V_12 * V_13 ,
void * V_35 )
{
F_8 ( L_17 ) ;
return F_30 ( V_11 , V_65 , V_13 , F_22 ) ;
}
static T_1
F_39 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_37 * V_35 )
{
struct V_14 * V_18 ;
struct V_16 * V_19 ;
F_8 ( L_18 ) ;
V_35 -> V_39 = V_13 -> V_39 ;
if ( F_18 ( F_17 ( V_11 ) ) && ! V_13 -> V_43 ) {
V_35 -> V_1 = V_7 ;
return V_36 ;
}
if ( ( V_35 -> V_1 = F_2 ( V_11 , V_13 , & V_18 , & V_19 ) ) )
return V_35 -> V_1 == V_8 ? V_40 : V_36 ;
V_35 -> V_1 = F_10 ( F_40 ( V_18 , V_19 , V_13 ) ) ;
F_8 ( L_19 , F_12 ( V_35 -> V_1 ) ) ;
F_6 ( V_18 ) ;
F_13 ( V_19 ) ;
return V_36 ;
}
static T_1
F_41 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_37 * V_35 )
{
struct V_14 * V_18 ;
struct V_16 * V_19 ;
F_8 ( L_20 ) ;
V_35 -> V_39 = V_13 -> V_39 ;
if ( F_18 ( F_17 ( V_11 ) ) ) {
V_35 -> V_1 = V_7 ;
return V_36 ;
}
if ( ( V_35 -> V_1 = F_2 ( V_11 , V_13 , & V_18 , & V_19 ) ) )
return V_35 -> V_1 == V_8 ? V_40 : V_36 ;
V_35 -> V_1 = F_10 ( F_42 ( V_18 , V_19 , V_13 ) ) ;
F_8 ( L_21 , F_12 ( V_35 -> V_1 ) ) ;
F_6 ( V_18 ) ;
F_13 ( V_19 ) ;
return V_36 ;
}
static T_1
F_43 ( struct V_10 * V_11 , struct V_12 * V_13 ,
struct V_37 * V_35 )
{
F_8 ( L_22 ) ;
V_13 -> V_25 = 0 ;
return F_14 ( V_11 , V_13 , V_35 ) ;
}
static T_1
F_44 ( struct V_10 * V_11 , struct V_12 * V_13 ,
void * V_35 )
{
struct V_14 * V_18 ;
if ( F_2 ( V_11 , V_13 , & V_18 , NULL ) )
return V_36 ;
F_45 ( V_18 ) ;
F_6 ( V_18 ) ;
return V_36 ;
}
static T_1
F_46 ( struct V_10 * V_11 , struct V_66 * V_13 ,
void * V_35 )
{
F_8 ( L_23 ) ;
if ( ! F_47 ( V_11 ) ) {
char V_67 [ V_68 ] ;
F_48 ( V_69 L_24 ,
F_49 ( V_11 , V_67 , sizeof( V_67 ) ) ) ;
return V_56 ;
}
F_50 ( V_13 ) ;
return V_36 ;
}
static T_1
F_51 ( struct V_10 * V_11 , struct V_37 * V_13 ,
void * V_35 )
{
if ( ! V_22 )
return V_36 ;
F_8 ( L_25 ) ;
F_52 ( & V_13 -> V_39 , V_13 -> V_1 ) ;
return V_36 ;
}
