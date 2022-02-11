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
if ( ( V_17 == F_13 ( & F_14 ( V_4 ) ) ||
F_13 ( & F_14 ( V_4 ) ) < 0 ) &&
F_15 ( V_4 ) )
break;
V_4 = NULL ;
}
if ( ! V_4 ) {
F_16 ( L_1 , V_17 ) ;
V_4 = F_17 () ;
}
if ( ! V_4 || ! F_15 ( V_4 ) )
return NULL ;
F_12 (itr, &accel_dev->crypto_list) {
struct V_1 * V_2 ;
unsigned long V_21 ;
V_2 = F_6 ( V_19 , struct V_1 , V_10 ) ;
V_21 = F_7 ( & V_2 -> V_3 ) ;
if ( V_20 > V_21 ) {
V_18 = V_2 ;
V_20 = V_21 ;
}
}
if ( V_18 ) {
if ( F_18 ( 1 , & V_18 -> V_3 ) == 1 ) {
if ( F_19 ( V_4 ) ) {
F_20 ( & V_18 -> V_3 ) ;
F_21 ( & F_14 ( V_4 ) ,
L_2 ) ;
return NULL ;
}
}
}
return V_18 ;
}
static int F_22 ( struct V_5 * V_4 )
{
int V_9 ;
unsigned long V_22 ;
unsigned long V_23 , V_24 , V_25 ;
int V_26 ;
struct V_1 * V_2 ;
char V_27 [ V_28 ] ;
char V_29 [ V_30 ] ;
F_23 ( & V_4 -> V_31 ) ;
F_24 ( V_27 , V_32 , sizeof( V_27 ) ) ;
if ( F_25 ( V_4 , V_33 , V_27 , V_29 ) )
return - V_34 ;
if ( F_26 ( V_29 , 0 , & V_23 ) )
return - V_34 ;
for ( V_9 = 0 ; V_9 < V_23 ; V_9 ++ ) {
V_2 = F_27 ( sizeof( * V_2 ) , V_35 ,
F_13 ( & F_14 ( V_4 ) ) ) ;
if ( ! V_2 )
goto V_36;
F_28 ( & V_2 -> V_10 , & V_4 -> V_31 ) ;
V_2 -> V_37 = V_9 ;
F_29 ( & V_2 -> V_3 , 0 ) ;
V_2 -> V_4 = V_4 ;
snprintf ( V_27 , sizeof( V_27 ) , V_38 L_3 V_39 , V_9 ) ;
if ( F_25 ( V_4 , V_33 , V_27 , V_29 ) )
goto V_36;
if ( F_26 ( V_29 , 10 , & V_22 ) )
goto V_36;
snprintf ( V_27 , sizeof( V_27 ) , V_38 L_3 V_40 , V_9 ) ;
if ( F_25 ( V_4 , V_33 , V_27 , V_29 ) )
goto V_36;
if ( F_26 ( V_29 , 10 , & V_24 ) )
goto V_36;
V_24 = V_24 >> 1 ;
snprintf ( V_27 , sizeof( V_27 ) , V_38 L_3 V_41 , V_9 ) ;
if ( F_25 ( V_4 , V_33 , V_27 , V_29 ) )
goto V_36;
if ( F_26 ( V_29 , 10 , & V_25 ) )
goto V_36;
V_25 = V_25 >> 1 ;
V_26 = V_42 ;
snprintf ( V_27 , sizeof( V_27 ) , V_38 L_3 V_43 , V_9 ) ;
if ( F_30 ( V_4 , V_33 , V_22 , V_24 ,
V_26 , V_27 , NULL , 0 , & V_2 -> V_11 ) )
goto V_36;
snprintf ( V_27 , sizeof( V_27 ) , V_38 L_3 V_44 , V_9 ) ;
if ( F_30 ( V_4 , V_33 , V_22 , V_25 ,
V_26 , V_27 , NULL , 0 , & V_2 -> V_15 ) )
goto V_36;
V_26 = V_26 >> 1 ;
snprintf ( V_27 , sizeof( V_27 ) , V_38 L_3 V_45 , V_9 ) ;
if ( F_30 ( V_4 , V_33 , V_22 , V_25 ,
V_26 , V_27 , NULL , 0 , & V_2 -> V_13 ) )
goto V_36;
V_26 = V_46 ;
snprintf ( V_27 , sizeof( V_27 ) , V_38 L_3 V_47 , V_9 ) ;
if ( F_30 ( V_4 , V_33 , V_22 , V_24 ,
V_26 , V_27 , V_48 , 0 ,
& V_2 -> V_12 ) )
goto V_36;
snprintf ( V_27 , sizeof( V_27 ) , V_38 L_3 V_49 , V_9 ) ;
if ( F_30 ( V_4 , V_33 , V_22 , V_25 ,
V_26 , V_27 , V_48 , 0 ,
& V_2 -> V_16 ) )
goto V_36;
snprintf ( V_27 , sizeof( V_27 ) , V_38 L_3 V_50 , V_9 ) ;
if ( F_30 ( V_4 , V_33 , V_22 , V_25 ,
V_26 , V_27 , V_48 , 0 ,
& V_2 -> V_14 ) )
goto V_36;
}
return 0 ;
V_36:
F_4 ( V_4 ) ;
return - V_51 ;
}
static int F_31 ( struct V_5 * V_4 )
{
if ( F_22 ( V_4 ) )
return - V_34 ;
return 0 ;
}
static int F_32 ( struct V_5 * V_4 )
{
return F_4 ( V_4 ) ;
}
static int F_33 ( struct V_5 * V_4 ,
enum V_52 V_53 )
{
int V_54 ;
switch ( V_53 ) {
case V_55 :
V_54 = F_31 ( V_4 ) ;
break;
case V_56 :
V_54 = F_32 ( V_4 ) ;
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
default:
V_54 = 0 ;
}
return V_54 ;
}
int F_34 ( void )
{
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_62 = F_33 ;
V_61 . V_63 = L_4 ;
return F_35 ( & V_61 ) ;
}
int F_36 ( void )
{
return F_37 ( & V_61 ) ;
}
