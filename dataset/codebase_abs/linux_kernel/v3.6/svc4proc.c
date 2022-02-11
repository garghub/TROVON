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
F_6 ( struct V_1 * V_2 , void * V_4 , void * V_27 )
{
F_7 ( L_1 ) ;
return V_28 ;
}
static T_1
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_29 * V_27 )
{
struct V_5 * V_9 ;
struct V_7 * V_10 ;
T_1 V_30 = V_28 ;
F_7 ( L_2 ) ;
V_27 -> V_31 = V_4 -> V_31 ;
if ( ( V_27 -> V_32 = F_1 ( V_2 , V_4 , & V_9 , & V_10 ) ) )
return V_27 -> V_32 == V_33 ? V_34 : V_28 ;
V_27 -> V_32 = F_9 ( V_2 , V_10 , V_9 , & V_4 -> V_12 , & V_27 -> V_12 , & V_27 -> V_31 ) ;
if ( V_27 -> V_32 == V_33 )
V_30 = V_34 ;
else
F_7 ( L_3 , F_10 ( V_27 -> V_32 ) ) ;
F_5 ( V_9 ) ;
F_11 ( V_10 ) ;
return V_30 ;
}
static T_1
F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_29 * V_27 )
{
struct V_5 * V_9 ;
struct V_7 * V_10 ;
T_1 V_30 = V_28 ;
F_7 ( L_4 ) ;
V_27 -> V_31 = V_4 -> V_31 ;
if ( ( V_27 -> V_32 = F_1 ( V_2 , V_4 , & V_9 , & V_10 ) ) )
return V_27 -> V_32 == V_33 ? V_34 : V_28 ;
#if 0
if (host->h_nsmstate && host->h_nsmstate != argp->state) {
resp->status = nlm_lck_denied_nolocks;
} else
#endif
V_27 -> V_32 = F_13 ( V_2 , V_10 , V_9 , & V_4 -> V_12 ,
V_4 -> V_35 , & V_4 -> V_31 ,
V_4 -> V_36 ) ;
if ( V_27 -> V_32 == V_33 )
V_30 = V_34 ;
else
F_7 ( L_5 , F_10 ( V_27 -> V_32 ) ) ;
F_5 ( V_9 ) ;
F_11 ( V_10 ) ;
return V_30 ;
}
static T_1
F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_29 * V_27 )
{
struct V_5 * V_9 ;
struct V_7 * V_10 ;
F_7 ( L_6 ) ;
V_27 -> V_31 = V_4 -> V_31 ;
if ( F_15 ( F_16 ( V_2 ) ) ) {
V_27 -> V_32 = V_37 ;
return V_28 ;
}
if ( ( V_27 -> V_32 = F_1 ( V_2 , V_4 , & V_9 , & V_10 ) ) )
return V_27 -> V_32 == V_33 ? V_34 : V_28 ;
V_27 -> V_32 = F_17 ( F_16 ( V_2 ) , V_10 , & V_4 -> V_12 ) ;
F_7 ( L_7 , F_10 ( V_27 -> V_32 ) ) ;
F_5 ( V_9 ) ;
F_11 ( V_10 ) ;
return V_28 ;
}
static T_1
F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_29 * V_27 )
{
struct V_5 * V_9 ;
struct V_7 * V_10 ;
F_7 ( L_8 ) ;
V_27 -> V_31 = V_4 -> V_31 ;
if ( F_15 ( F_16 ( V_2 ) ) ) {
V_27 -> V_32 = V_37 ;
return V_28 ;
}
if ( ( V_27 -> V_32 = F_1 ( V_2 , V_4 , & V_9 , & V_10 ) ) )
return V_27 -> V_32 == V_33 ? V_34 : V_28 ;
V_27 -> V_32 = F_19 ( F_16 ( V_2 ) , V_10 , & V_4 -> V_12 ) ;
F_7 ( L_9 , F_10 ( V_27 -> V_32 ) ) ;
F_5 ( V_9 ) ;
F_11 ( V_10 ) ;
return V_28 ;
}
static T_1
F_20 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_29 * V_27 )
{
V_27 -> V_31 = V_4 -> V_31 ;
F_7 ( L_10 ) ;
V_27 -> V_32 = F_21 ( F_22 ( V_2 ) , & V_4 -> V_12 ) ;
F_7 ( L_11 , F_10 ( V_27 -> V_32 ) ) ;
return V_28 ;
}
static void F_23 ( struct V_38 * V_39 , void * V_40 )
{
F_7 ( L_12 , V_39 -> V_41 ,
- V_39 -> V_42 ) ;
}
static void F_24 ( void * V_40 )
{
F_25 ( V_40 ) ;
}
static T_1 F_26 ( struct V_1 * V_2 , T_2 V_43 , struct V_3 * V_4 ,
T_1 (* F_27)( struct V_1 * , struct V_3 * , struct V_29 * ) )
{
struct V_5 * V_9 ;
struct V_44 * V_45 ;
T_1 V_46 ;
V_9 = F_2 ( V_2 ,
V_4 -> V_12 . V_15 ,
V_4 -> V_12 . V_16 ) ;
if ( V_9 == NULL )
return V_47 ;
V_45 = F_28 ( V_9 ) ;
F_5 ( V_9 ) ;
if ( V_45 == NULL )
return V_47 ;
V_46 = F_27 ( V_2 , V_4 , & V_45 -> V_48 ) ;
if ( V_46 != 0 ) {
F_25 ( V_45 ) ;
return V_46 ;
}
V_45 -> V_49 = V_50 ;
if ( F_29 ( V_45 , V_43 , & V_51 ) < 0 )
return V_47 ;
return V_28 ;
}
static T_1 F_30 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_27 )
{
F_7 ( L_13 ) ;
return F_26 ( V_2 , V_52 , V_4 , F_8 ) ;
}
static T_1 F_31 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_27 )
{
F_7 ( L_14 ) ;
return F_26 ( V_2 , V_53 , V_4 , F_12 ) ;
}
static T_1 F_32 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_27 )
{
F_7 ( L_15 ) ;
return F_26 ( V_2 , V_54 , V_4 , F_14 ) ;
}
static T_1 F_33 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_27 )
{
F_7 ( L_16 ) ;
return F_26 ( V_2 , V_55 , V_4 , F_18 ) ;
}
static T_1 F_34 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_27 )
{
F_7 ( L_17 ) ;
return F_26 ( V_2 , V_56 , V_4 , F_20 ) ;
}
static T_1
F_35 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_29 * V_27 )
{
struct V_5 * V_9 ;
struct V_7 * V_10 ;
F_7 ( L_18 ) ;
V_27 -> V_31 = V_4 -> V_31 ;
if ( F_15 ( F_16 ( V_2 ) ) && ! V_4 -> V_36 ) {
V_27 -> V_32 = V_37 ;
return V_28 ;
}
if ( ( V_27 -> V_32 = F_1 ( V_2 , V_4 , & V_9 , & V_10 ) ) )
return V_27 -> V_32 == V_33 ? V_34 : V_28 ;
V_27 -> V_32 = F_36 ( V_9 , V_10 , V_4 ) ;
F_7 ( L_19 , F_10 ( V_27 -> V_32 ) ) ;
F_5 ( V_9 ) ;
F_11 ( V_10 ) ;
return V_28 ;
}
static T_1
F_37 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_29 * V_27 )
{
struct V_5 * V_9 ;
struct V_7 * V_10 ;
F_7 ( L_20 ) ;
V_27 -> V_31 = V_4 -> V_31 ;
if ( F_15 ( F_16 ( V_2 ) ) ) {
V_27 -> V_32 = V_37 ;
return V_28 ;
}
if ( ( V_27 -> V_32 = F_1 ( V_2 , V_4 , & V_9 , & V_10 ) ) )
return V_27 -> V_32 == V_33 ? V_34 : V_28 ;
V_27 -> V_32 = F_38 ( V_9 , V_10 , V_4 ) ;
F_7 ( L_21 , F_10 ( V_27 -> V_32 ) ) ;
F_5 ( V_9 ) ;
F_11 ( V_10 ) ;
return V_28 ;
}
static T_1
F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_29 * V_27 )
{
F_7 ( L_22 ) ;
V_4 -> V_17 = 0 ;
return F_12 ( V_2 , V_4 , V_27 ) ;
}
static T_1
F_40 ( struct V_1 * V_2 , struct V_3 * V_4 ,
void * V_27 )
{
struct V_5 * V_9 ;
if ( F_1 ( V_2 , V_4 , & V_9 , NULL ) )
return V_28 ;
F_41 ( V_9 ) ;
F_5 ( V_9 ) ;
return V_28 ;
}
static T_1
F_42 ( struct V_1 * V_2 , struct V_57 * V_4 ,
void * V_27 )
{
F_7 ( L_23 ) ;
if ( ! F_43 ( V_2 ) ) {
char V_58 [ V_59 ] ;
F_44 ( V_60 L_24 ,
F_45 ( V_2 , V_58 , sizeof( V_58 ) ) ) ;
return V_47 ;
}
F_46 ( V_4 ) ;
return V_28 ;
}
static T_1
F_47 ( struct V_1 * V_2 , struct V_29 * V_4 ,
void * V_27 )
{
if ( ! V_13 )
return V_28 ;
F_7 ( L_25 ) ;
F_48 ( & V_4 -> V_31 , V_4 -> V_32 ) ;
return V_28 ;
}
