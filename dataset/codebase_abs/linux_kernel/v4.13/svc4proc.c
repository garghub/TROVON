static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * * V_6 , struct V_7 * * V_8 )
{
struct V_5 * V_9 = NULL ;
struct V_7 * V_10 = NULL ;
struct V_11 * V_12 = & V_4 -> V_12 ;
T_1 error = 0 ;
if ( ! V_13 )
return V_14 ;
if ( ! ( V_9 = F_2 ( V_2 , V_12 -> V_15 , V_12 -> V_16 ) )
|| ( V_4 -> V_17 && F_3 ( V_9 ) < 0 ) )
goto V_18;
* V_6 = V_9 ;
if ( V_8 != NULL ) {
if ( ( error = F_4 ( V_2 , & V_10 , & V_12 -> V_19 ) ) != 0 )
goto V_18;
* V_8 = V_10 ;
V_12 -> V_20 . V_21 = V_10 -> V_22 ;
V_12 -> V_20 . V_23 = ( V_24 ) V_9 ;
V_12 -> V_20 . V_25 = & V_26 ;
}
return 0 ;
V_18:
F_5 ( V_9 ) ;
if ( error )
return error ;
return V_14 ;
}
static T_1
F_6 ( struct V_1 * V_2 )
{
F_7 ( L_1 ) ;
return V_27 ;
}
static T_1
F_8 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_4 = V_2 -> V_30 ;
struct V_5 * V_9 ;
struct V_7 * V_10 ;
T_1 V_31 = V_27 ;
F_7 ( L_2 ) ;
V_29 -> V_32 = V_4 -> V_32 ;
if ( ( V_29 -> V_33 = F_1 ( V_2 , V_4 , & V_9 , & V_10 ) ) )
return V_29 -> V_33 == V_34 ? V_35 : V_27 ;
V_29 -> V_33 = F_9 ( V_2 , V_10 , V_9 , & V_4 -> V_12 , & V_29 -> V_12 , & V_29 -> V_32 ) ;
if ( V_29 -> V_33 == V_34 )
V_31 = V_35 ;
else
F_7 ( L_3 , F_10 ( V_29 -> V_33 ) ) ;
F_5 ( V_9 ) ;
F_11 ( V_10 ) ;
return V_31 ;
}
static T_1
F_12 ( struct V_1 * V_2 )
{
return F_8 ( V_2 , V_2 -> V_36 ) ;
}
static T_1
F_13 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_4 = V_2 -> V_30 ;
struct V_5 * V_9 ;
struct V_7 * V_10 ;
T_1 V_31 = V_27 ;
F_7 ( L_4 ) ;
V_29 -> V_32 = V_4 -> V_32 ;
if ( ( V_29 -> V_33 = F_1 ( V_2 , V_4 , & V_9 , & V_10 ) ) )
return V_29 -> V_33 == V_34 ? V_35 : V_27 ;
#if 0
if (host->h_nsmstate && host->h_nsmstate != argp->state) {
resp->status = nlm_lck_denied_nolocks;
} else
#endif
V_29 -> V_33 = F_14 ( V_2 , V_10 , V_9 , & V_4 -> V_12 ,
V_4 -> V_37 , & V_4 -> V_32 ,
V_4 -> V_38 ) ;
if ( V_29 -> V_33 == V_34 )
V_31 = V_35 ;
else
F_7 ( L_5 , F_10 ( V_29 -> V_33 ) ) ;
F_5 ( V_9 ) ;
F_11 ( V_10 ) ;
return V_31 ;
}
static T_1
F_15 ( struct V_1 * V_2 )
{
return F_13 ( V_2 , V_2 -> V_36 ) ;
}
static T_1
F_16 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_4 = V_2 -> V_30 ;
struct V_5 * V_9 ;
struct V_7 * V_10 ;
F_7 ( L_6 ) ;
V_29 -> V_32 = V_4 -> V_32 ;
if ( F_17 ( F_18 ( V_2 ) ) ) {
V_29 -> V_33 = V_39 ;
return V_27 ;
}
if ( ( V_29 -> V_33 = F_1 ( V_2 , V_4 , & V_9 , & V_10 ) ) )
return V_29 -> V_33 == V_34 ? V_35 : V_27 ;
V_29 -> V_33 = F_19 ( F_18 ( V_2 ) , V_10 , & V_4 -> V_12 ) ;
F_7 ( L_7 , F_10 ( V_29 -> V_33 ) ) ;
F_5 ( V_9 ) ;
F_11 ( V_10 ) ;
return V_27 ;
}
static T_1
F_20 ( struct V_1 * V_2 )
{
return F_16 ( V_2 , V_2 -> V_36 ) ;
}
static T_1
F_21 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_4 = V_2 -> V_30 ;
struct V_5 * V_9 ;
struct V_7 * V_10 ;
F_7 ( L_8 ) ;
V_29 -> V_32 = V_4 -> V_32 ;
if ( F_17 ( F_18 ( V_2 ) ) ) {
V_29 -> V_33 = V_39 ;
return V_27 ;
}
if ( ( V_29 -> V_33 = F_1 ( V_2 , V_4 , & V_9 , & V_10 ) ) )
return V_29 -> V_33 == V_34 ? V_35 : V_27 ;
V_29 -> V_33 = F_22 ( F_18 ( V_2 ) , V_10 , & V_4 -> V_12 ) ;
F_7 ( L_9 , F_10 ( V_29 -> V_33 ) ) ;
F_5 ( V_9 ) ;
F_11 ( V_10 ) ;
return V_27 ;
}
static T_1
F_23 ( struct V_1 * V_2 )
{
return F_21 ( V_2 , V_2 -> V_36 ) ;
}
static T_1
F_24 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_4 = V_2 -> V_30 ;
V_29 -> V_32 = V_4 -> V_32 ;
F_7 ( L_10 ) ;
V_29 -> V_33 = F_25 ( F_26 ( V_2 ) , & V_4 -> V_12 ) ;
F_7 ( L_11 , F_10 ( V_29 -> V_33 ) ) ;
return V_27 ;
}
static T_1
F_27 ( struct V_1 * V_2 )
{
return F_24 ( V_2 , V_2 -> V_36 ) ;
}
static void F_28 ( struct V_40 * V_41 , void * V_42 )
{
F_7 ( L_12 , V_41 -> V_43 ,
- V_41 -> V_44 ) ;
}
static void F_29 ( void * V_42 )
{
F_30 ( V_42 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 , T_2 V_45 ,
T_1 (* F_32)( struct V_1 * , struct V_28 * ) )
{
struct V_3 * V_4 = V_2 -> V_30 ;
struct V_5 * V_9 ;
struct V_46 * V_47 ;
T_1 V_48 ;
V_9 = F_2 ( V_2 ,
V_4 -> V_12 . V_15 ,
V_4 -> V_12 . V_16 ) ;
if ( V_9 == NULL )
return V_49 ;
V_47 = F_33 ( V_9 ) ;
F_5 ( V_9 ) ;
if ( V_47 == NULL )
return V_49 ;
V_48 = F_32 ( V_2 , & V_47 -> V_50 ) ;
if ( V_48 != 0 ) {
F_30 ( V_47 ) ;
return V_48 ;
}
V_47 -> V_51 = V_52 ;
if ( F_34 ( V_47 , V_45 , & V_53 ) < 0 )
return V_49 ;
return V_27 ;
}
static T_1 F_35 ( struct V_1 * V_2 )
{
F_7 ( L_13 ) ;
return F_31 ( V_2 , V_54 , F_8 ) ;
}
static T_1 F_36 ( struct V_1 * V_2 )
{
F_7 ( L_14 ) ;
return F_31 ( V_2 , V_55 , F_13 ) ;
}
static T_1 F_37 ( struct V_1 * V_2 )
{
F_7 ( L_15 ) ;
return F_31 ( V_2 , V_56 , F_16 ) ;
}
static T_1 F_38 ( struct V_1 * V_2 )
{
F_7 ( L_16 ) ;
return F_31 ( V_2 , V_57 , F_21 ) ;
}
static T_1 F_39 ( struct V_1 * V_2 )
{
F_7 ( L_17 ) ;
return F_31 ( V_2 , V_58 , F_24 ) ;
}
static T_1
F_40 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_30 ;
struct V_28 * V_29 = V_2 -> V_36 ;
struct V_5 * V_9 ;
struct V_7 * V_10 ;
F_7 ( L_18 ) ;
V_29 -> V_32 = V_4 -> V_32 ;
if ( F_17 ( F_18 ( V_2 ) ) && ! V_4 -> V_38 ) {
V_29 -> V_33 = V_39 ;
return V_27 ;
}
if ( ( V_29 -> V_33 = F_1 ( V_2 , V_4 , & V_9 , & V_10 ) ) )
return V_29 -> V_33 == V_34 ? V_35 : V_27 ;
V_29 -> V_33 = F_41 ( V_9 , V_10 , V_4 ) ;
F_7 ( L_19 , F_10 ( V_29 -> V_33 ) ) ;
F_5 ( V_9 ) ;
F_11 ( V_10 ) ;
return V_27 ;
}
static T_1
F_42 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_30 ;
struct V_28 * V_29 = V_2 -> V_36 ;
struct V_5 * V_9 ;
struct V_7 * V_10 ;
F_7 ( L_20 ) ;
V_29 -> V_32 = V_4 -> V_32 ;
if ( F_17 ( F_18 ( V_2 ) ) ) {
V_29 -> V_33 = V_39 ;
return V_27 ;
}
if ( ( V_29 -> V_33 = F_1 ( V_2 , V_4 , & V_9 , & V_10 ) ) )
return V_29 -> V_33 == V_34 ? V_35 : V_27 ;
V_29 -> V_33 = F_43 ( V_9 , V_10 , V_4 ) ;
F_7 ( L_21 , F_10 ( V_29 -> V_33 ) ) ;
F_5 ( V_9 ) ;
F_11 ( V_10 ) ;
return V_27 ;
}
static T_1
F_44 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_30 ;
F_7 ( L_22 ) ;
V_4 -> V_17 = 0 ;
return F_15 ( V_2 ) ;
}
static T_1
F_45 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_30 ;
struct V_5 * V_9 ;
if ( F_1 ( V_2 , V_4 , & V_9 , NULL ) )
return V_27 ;
F_46 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_27 ;
}
static T_1
F_47 ( struct V_1 * V_2 )
{
struct V_59 * V_4 = V_2 -> V_30 ;
F_7 ( L_23 ) ;
if ( ! F_48 ( V_2 ) ) {
char V_60 [ V_61 ] ;
F_49 ( V_62 L_24 ,
F_50 ( V_2 , V_60 , sizeof( V_60 ) ) ) ;
return V_49 ;
}
F_51 ( F_18 ( V_2 ) , V_4 ) ;
return V_27 ;
}
static T_1
F_52 ( struct V_1 * V_2 )
{
struct V_28 * V_4 = V_2 -> V_30 ;
if ( ! V_13 )
return V_27 ;
F_7 ( L_25 ) ;
F_53 ( & V_4 -> V_32 , V_4 -> V_33 ) ;
return V_27 ;
}
