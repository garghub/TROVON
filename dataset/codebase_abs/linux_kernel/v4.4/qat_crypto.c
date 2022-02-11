void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
F_3 ( V_2 -> V_4 ) ;
}
static int F_4 ( struct V_5 * V_4 )
{
struct V_1 * V_2 ;
struct V_6 * V_7 , * V_8 ;
int V_9 ;
F_5 (list_ptr, tmp, &accel_dev->crypto_list) {
V_2 = F_6 ( V_7 , struct V_1 , V_10 ) ;
for ( V_9 = 0 ; V_9 < F_7 ( & V_2 -> V_3 ) ; V_9 ++ )
F_1 ( V_2 ) ;
if ( V_2 -> V_11 )
F_8 ( V_2 -> V_11 ) ;
if ( V_2 -> V_12 )
F_8 ( V_2 -> V_12 ) ;
if ( V_2 -> V_13 )
F_8 ( V_2 -> V_13 ) ;
if ( V_2 -> V_14 )
F_8 ( V_2 -> V_14 ) ;
F_9 ( V_7 ) ;
F_10 ( V_2 ) ;
}
return 0 ;
}
struct V_1 * F_11 ( int V_15 )
{
struct V_5 * V_4 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_6 * V_16 ;
unsigned long V_17 = ~ 0 ;
F_12 (itr, adf_devmgr_get_head()) {
struct V_5 * V_18 ;
unsigned long V_19 ;
V_18 = F_6 ( V_16 , struct V_5 , V_10 ) ;
if ( ( V_15 == F_13 ( & F_14 ( V_18 ) ) ||
F_13 ( & F_14 ( V_18 ) ) < 0 ) &&
F_15 ( V_18 ) &&
! F_16 ( & V_18 -> V_20 ) ) {
V_19 = F_7 ( & V_18 -> V_21 ) ;
if ( V_17 > V_19 ) {
V_4 = V_18 ;
V_17 = V_19 ;
}
}
}
if ( ! V_4 )
F_17 ( L_1 , V_15 ) ;
F_12 (itr, adf_devmgr_get_head()) {
struct V_5 * V_18 ;
V_18 = F_6 ( V_16 , struct V_5 , V_10 ) ;
if ( F_15 ( V_18 ) &&
! F_16 ( & V_18 -> V_20 ) ) {
V_4 = V_18 ;
break;
}
}
if ( ! V_4 )
return NULL ;
V_17 = ~ 0 ;
F_12 (itr, &accel_dev->crypto_list) {
struct V_1 * V_22 ;
unsigned long V_19 ;
V_22 = F_6 ( V_16 , struct V_1 , V_10 ) ;
V_19 = F_7 ( & V_22 -> V_3 ) ;
if ( V_17 > V_19 ) {
V_2 = V_22 ;
V_17 = V_19 ;
}
}
if ( V_2 ) {
if ( F_18 ( V_4 ) ) {
F_19 ( & F_14 ( V_4 ) , L_2 ) ;
return NULL ;
}
F_20 ( & V_2 -> V_3 ) ;
}
return V_2 ;
}
static int F_21 ( struct V_5 * V_4 )
{
int V_9 ;
unsigned long V_23 ;
unsigned long V_24 , V_25 , V_26 ;
int V_27 ;
struct V_1 * V_2 ;
char V_28 [ V_29 ] ;
char V_30 [ V_31 ] ;
F_22 ( & V_4 -> V_20 ) ;
F_23 ( V_28 , V_32 , sizeof( V_28 ) ) ;
if ( F_24 ( V_4 , V_33 , V_28 , V_30 ) )
return - V_34 ;
if ( F_25 ( V_30 , 0 , & V_24 ) )
return - V_34 ;
for ( V_9 = 0 ; V_9 < V_24 ; V_9 ++ ) {
V_2 = F_26 ( sizeof( * V_2 ) , V_35 ,
F_13 ( & F_14 ( V_4 ) ) ) ;
if ( ! V_2 )
goto V_36;
F_27 ( & V_2 -> V_10 , & V_4 -> V_20 ) ;
V_2 -> V_37 = V_9 ;
F_28 ( & V_2 -> V_3 , 0 ) ;
V_2 -> V_4 = V_4 ;
snprintf ( V_28 , sizeof( V_28 ) , V_38 L_3 V_39 , V_9 ) ;
if ( F_24 ( V_4 , V_33 , V_28 , V_30 ) )
goto V_36;
if ( F_25 ( V_30 , 10 , & V_23 ) )
goto V_36;
snprintf ( V_28 , sizeof( V_28 ) , V_38 L_3 V_40 , V_9 ) ;
if ( F_24 ( V_4 , V_33 , V_28 , V_30 ) )
goto V_36;
if ( F_25 ( V_30 , 10 , & V_25 ) )
goto V_36;
V_25 = V_25 >> 1 ;
snprintf ( V_28 , sizeof( V_28 ) , V_38 L_3 V_41 , V_9 ) ;
if ( F_24 ( V_4 , V_33 , V_28 , V_30 ) )
goto V_36;
if ( F_25 ( V_30 , 10 , & V_26 ) )
goto V_36;
V_26 = V_26 >> 1 ;
V_27 = V_42 ;
snprintf ( V_28 , sizeof( V_28 ) , V_38 L_3 V_43 , V_9 ) ;
if ( F_29 ( V_4 , V_33 , V_23 , V_25 ,
V_27 , V_28 , NULL , 0 , & V_2 -> V_11 ) )
goto V_36;
V_27 = V_27 >> 1 ;
snprintf ( V_28 , sizeof( V_28 ) , V_38 L_3 V_44 , V_9 ) ;
if ( F_29 ( V_4 , V_33 , V_23 , V_26 ,
V_27 , V_28 , NULL , 0 , & V_2 -> V_13 ) )
goto V_36;
V_27 = V_45 ;
snprintf ( V_28 , sizeof( V_28 ) , V_38 L_3 V_46 , V_9 ) ;
if ( F_29 ( V_4 , V_33 , V_23 , V_25 ,
V_27 , V_28 , V_47 , 0 ,
& V_2 -> V_12 ) )
goto V_36;
snprintf ( V_28 , sizeof( V_28 ) , V_38 L_3 V_48 , V_9 ) ;
if ( F_29 ( V_4 , V_33 , V_23 , V_26 ,
V_27 , V_28 , V_49 , 0 ,
& V_2 -> V_14 ) )
goto V_36;
}
return 0 ;
V_36:
F_4 ( V_4 ) ;
return - V_50 ;
}
static int F_30 ( struct V_5 * V_4 )
{
if ( F_21 ( V_4 ) )
return - V_34 ;
return 0 ;
}
static int F_31 ( struct V_5 * V_4 )
{
return F_4 ( V_4 ) ;
}
static int F_32 ( struct V_5 * V_4 ,
enum V_51 V_52 )
{
int V_53 ;
switch ( V_52 ) {
case V_54 :
V_53 = F_30 ( V_4 ) ;
break;
case V_55 :
V_53 = F_31 ( V_4 ) ;
break;
case V_56 :
case V_57 :
case V_58 :
case V_59 :
default:
V_53 = 0 ;
}
return V_53 ;
}
int F_33 ( void )
{
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_61 = F_32 ;
V_60 . V_62 = L_4 ;
return F_34 ( & V_60 ) ;
}
int F_35 ( void )
{
return F_36 ( & V_60 ) ;
}
