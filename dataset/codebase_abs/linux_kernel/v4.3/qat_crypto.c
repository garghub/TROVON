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
F_9 ( V_7 ) ;
F_10 ( V_2 ) ;
}
return 0 ;
}
struct V_1 * F_11 ( int V_15 )
{
struct V_5 * V_4 = NULL ;
struct V_1 * V_16 = NULL ;
struct V_6 * V_17 ;
unsigned long V_18 = ~ 0 ;
F_12 (itr, adf_devmgr_get_head()) {
V_4 = F_6 ( V_17 , struct V_5 , V_10 ) ;
if ( ( V_15 == F_13 ( & F_14 ( V_4 ) ) ||
F_13 ( & F_14 ( V_4 ) ) < 0 ) &&
F_15 ( V_4 ) &&
! F_16 ( & V_4 -> V_19 ) )
break;
V_4 = NULL ;
}
if ( ! V_4 ) {
F_17 ( L_1 , V_15 ) ;
V_4 = F_18 () ;
}
if ( ! V_4 || ! F_15 ( V_4 ) )
return NULL ;
F_12 (itr, &accel_dev->crypto_list) {
struct V_1 * V_2 ;
unsigned long V_20 ;
V_2 = F_6 ( V_17 , struct V_1 , V_10 ) ;
V_20 = F_7 ( & V_2 -> V_3 ) ;
if ( V_18 > V_20 ) {
V_16 = V_2 ;
V_18 = V_20 ;
}
}
if ( V_16 ) {
if ( F_19 ( 1 , & V_16 -> V_3 ) == 1 ) {
if ( F_20 ( V_4 ) ) {
F_21 ( & V_16 -> V_3 ) ;
F_22 ( & F_14 ( V_4 ) ,
L_2 ) ;
return NULL ;
}
}
}
return V_16 ;
}
static int F_23 ( struct V_5 * V_4 )
{
int V_9 ;
unsigned long V_21 ;
unsigned long V_22 , V_23 , V_24 ;
int V_25 ;
struct V_1 * V_2 ;
char V_26 [ V_27 ] ;
char V_28 [ V_29 ] ;
F_24 ( & V_4 -> V_19 ) ;
F_25 ( V_26 , V_30 , sizeof( V_26 ) ) ;
if ( F_26 ( V_4 , V_31 , V_26 , V_28 ) )
return - V_32 ;
if ( F_27 ( V_28 , 0 , & V_22 ) )
return - V_32 ;
for ( V_9 = 0 ; V_9 < V_22 ; V_9 ++ ) {
V_2 = F_28 ( sizeof( * V_2 ) , V_33 ,
F_13 ( & F_14 ( V_4 ) ) ) ;
if ( ! V_2 )
goto V_34;
F_29 ( & V_2 -> V_10 , & V_4 -> V_19 ) ;
V_2 -> V_35 = V_9 ;
F_30 ( & V_2 -> V_3 , 0 ) ;
V_2 -> V_4 = V_4 ;
snprintf ( V_26 , sizeof( V_26 ) , V_36 L_3 V_37 , V_9 ) ;
if ( F_26 ( V_4 , V_31 , V_26 , V_28 ) )
goto V_34;
if ( F_27 ( V_28 , 10 , & V_21 ) )
goto V_34;
snprintf ( V_26 , sizeof( V_26 ) , V_36 L_3 V_38 , V_9 ) ;
if ( F_26 ( V_4 , V_31 , V_26 , V_28 ) )
goto V_34;
if ( F_27 ( V_28 , 10 , & V_23 ) )
goto V_34;
V_23 = V_23 >> 1 ;
snprintf ( V_26 , sizeof( V_26 ) , V_36 L_3 V_39 , V_9 ) ;
if ( F_26 ( V_4 , V_31 , V_26 , V_28 ) )
goto V_34;
if ( F_27 ( V_28 , 10 , & V_24 ) )
goto V_34;
V_24 = V_24 >> 1 ;
V_25 = V_40 ;
snprintf ( V_26 , sizeof( V_26 ) , V_36 L_3 V_41 , V_9 ) ;
if ( F_31 ( V_4 , V_31 , V_21 , V_23 ,
V_25 , V_26 , NULL , 0 , & V_2 -> V_11 ) )
goto V_34;
V_25 = V_25 >> 1 ;
snprintf ( V_26 , sizeof( V_26 ) , V_36 L_3 V_42 , V_9 ) ;
if ( F_31 ( V_4 , V_31 , V_21 , V_24 ,
V_25 , V_26 , NULL , 0 , & V_2 -> V_13 ) )
goto V_34;
V_25 = V_43 ;
snprintf ( V_26 , sizeof( V_26 ) , V_36 L_3 V_44 , V_9 ) ;
if ( F_31 ( V_4 , V_31 , V_21 , V_23 ,
V_25 , V_26 , V_45 , 0 ,
& V_2 -> V_12 ) )
goto V_34;
snprintf ( V_26 , sizeof( V_26 ) , V_36 L_3 V_46 , V_9 ) ;
if ( F_31 ( V_4 , V_31 , V_21 , V_24 ,
V_25 , V_26 , V_47 , 0 ,
& V_2 -> V_14 ) )
goto V_34;
}
return 0 ;
V_34:
F_4 ( V_4 ) ;
return - V_48 ;
}
static int F_32 ( struct V_5 * V_4 )
{
if ( F_23 ( V_4 ) )
return - V_32 ;
return 0 ;
}
static int F_33 ( struct V_5 * V_4 )
{
return F_4 ( V_4 ) ;
}
static int F_34 ( struct V_5 * V_4 ,
enum V_49 V_50 )
{
int V_51 ;
switch ( V_50 ) {
case V_52 :
V_51 = F_32 ( V_4 ) ;
break;
case V_53 :
V_51 = F_33 ( V_4 ) ;
break;
case V_54 :
case V_55 :
case V_56 :
case V_57 :
default:
V_51 = 0 ;
}
return V_51 ;
}
int F_35 ( void )
{
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_59 = F_34 ;
V_58 . V_60 = L_4 ;
return F_36 ( & V_58 ) ;
}
int F_37 ( void )
{
return F_38 ( & V_58 ) ;
}
