void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( 1 , & V_2 -> V_3 ) == 0 )
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
if ( V_2 -> V_15 )
F_8 ( V_2 -> V_15 ) ;
if ( V_2 -> V_16 )
F_8 ( V_2 -> V_16 ) ;
F_9 ( V_7 ) ;
F_10 ( V_2 ) ;
}
return 0 ;
}
struct V_1 * F_11 ( int V_17 )
{
struct V_5 * V_4 = NULL ;
struct V_1 * V_18 = NULL ;
struct V_6 * V_19 ;
unsigned long V_20 = ~ 0 ;
F_12 (itr, adf_devmgr_get_head()) {
V_4 = F_6 ( V_19 , struct V_5 , V_10 ) ;
if ( V_4 -> V_21 == V_17 && F_13 ( V_4 ) )
break;
V_4 = NULL ;
}
if ( ! V_4 ) {
F_14 ( L_1 ) ;
V_4 = F_15 () ;
}
if ( ! V_4 || ! F_13 ( V_4 ) )
return NULL ;
F_12 (itr, &accel_dev->crypto_list) {
struct V_1 * V_2 ;
unsigned long V_22 ;
V_2 = F_6 ( V_19 , struct V_1 , V_10 ) ;
V_22 = F_7 ( & V_2 -> V_3 ) ;
if ( V_20 > V_22 ) {
V_18 = V_2 ;
V_20 = V_22 ;
}
}
if ( V_18 ) {
if ( F_16 ( 1 , & V_18 -> V_3 ) == 1 ) {
if ( F_17 ( V_4 ) ) {
F_18 ( & V_18 -> V_3 ) ;
F_14 ( L_2 ) ;
return NULL ;
}
}
}
return V_18 ;
}
static int F_19 ( struct V_5 * V_4 )
{
int V_9 ;
unsigned long V_23 ;
unsigned long V_24 , V_25 , V_26 ;
int V_27 ;
struct V_1 * V_2 ;
char V_28 [ V_29 ] ;
char V_30 [ V_31 ] ;
F_20 ( & V_4 -> V_32 ) ;
F_21 ( V_28 , V_33 , sizeof( V_28 ) ) ;
if ( F_22 ( V_4 , V_34 , V_28 , V_30 ) )
return - V_35 ;
if ( F_23 ( V_30 , 0 , & V_24 ) )
return - V_35 ;
for ( V_9 = 0 ; V_9 < V_24 ; V_9 ++ ) {
V_2 = F_24 ( sizeof( * V_2 ) , V_36 ,
V_4 -> V_21 ) ;
if ( ! V_2 )
goto V_37;
F_25 ( & V_2 -> V_10 , & V_4 -> V_32 ) ;
V_2 -> V_38 = V_9 ;
F_26 ( & V_2 -> V_3 , 0 ) ;
V_2 -> V_4 = V_4 ;
snprintf ( V_28 , sizeof( V_28 ) , V_39 L_3 V_40 , V_9 ) ;
if ( F_22 ( V_4 , V_34 , V_28 , V_30 ) )
goto V_37;
if ( F_23 ( V_30 , 10 , & V_23 ) )
goto V_37;
snprintf ( V_28 , sizeof( V_28 ) , V_39 L_3 V_41 , V_9 ) ;
if ( F_22 ( V_4 , V_34 , V_28 , V_30 ) )
goto V_37;
if ( F_23 ( V_30 , 10 , & V_25 ) )
goto V_37;
V_25 = V_25 >> 1 ;
snprintf ( V_28 , sizeof( V_28 ) , V_39 L_3 V_42 , V_9 ) ;
if ( F_22 ( V_4 , V_34 , V_28 , V_30 ) )
goto V_37;
if ( F_23 ( V_30 , 10 , & V_26 ) )
goto V_37;
V_26 = V_26 >> 1 ;
V_27 = V_43 ;
snprintf ( V_28 , sizeof( V_28 ) , V_39 L_3 V_44 , V_9 ) ;
if ( F_27 ( V_4 , V_34 , V_23 , V_25 ,
V_27 , V_28 , NULL , 0 , & V_2 -> V_11 ) )
goto V_37;
snprintf ( V_28 , sizeof( V_28 ) , V_39 L_3 V_45 , V_9 ) ;
if ( F_27 ( V_4 , V_34 , V_23 , V_26 ,
V_27 , V_28 , NULL , 0 , & V_2 -> V_15 ) )
goto V_37;
V_27 = V_27 >> 1 ;
snprintf ( V_28 , sizeof( V_28 ) , V_39 L_3 V_46 , V_9 ) ;
if ( F_27 ( V_4 , V_34 , V_23 , V_26 ,
V_27 , V_28 , NULL , 0 , & V_2 -> V_13 ) )
goto V_37;
V_27 = V_47 ;
snprintf ( V_28 , sizeof( V_28 ) , V_39 L_3 V_48 , V_9 ) ;
if ( F_27 ( V_4 , V_34 , V_23 , V_25 ,
V_27 , V_28 , V_49 , 0 ,
& V_2 -> V_12 ) )
goto V_37;
snprintf ( V_28 , sizeof( V_28 ) , V_39 L_3 V_50 , V_9 ) ;
if ( F_27 ( V_4 , V_34 , V_23 , V_26 ,
V_27 , V_28 , V_49 , 0 ,
& V_2 -> V_16 ) )
goto V_37;
snprintf ( V_28 , sizeof( V_28 ) , V_39 L_3 V_51 , V_9 ) ;
if ( F_27 ( V_4 , V_34 , V_23 , V_26 ,
V_27 , V_28 , V_49 , 0 ,
& V_2 -> V_14 ) )
goto V_37;
}
return 0 ;
V_37:
F_4 ( V_4 ) ;
return - V_52 ;
}
static int F_28 ( struct V_5 * V_4 )
{
if ( F_19 ( V_4 ) )
return - V_35 ;
return 0 ;
}
static int F_29 ( struct V_5 * V_4 )
{
return F_4 ( V_4 ) ;
}
static int F_30 ( struct V_5 * V_4 ,
enum V_53 V_54 )
{
int V_55 ;
switch ( V_54 ) {
case V_56 :
V_55 = F_28 ( V_4 ) ;
break;
case V_57 :
V_55 = F_29 ( V_4 ) ;
break;
case V_58 :
case V_59 :
case V_60 :
case V_61 :
default:
V_55 = 0 ;
}
return V_55 ;
}
int F_31 ( void )
{
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_63 = F_30 ;
V_62 . V_64 = L_4 ;
return F_32 ( & V_62 ) ;
}
int F_33 ( void )
{
return F_34 ( & V_62 ) ;
}
