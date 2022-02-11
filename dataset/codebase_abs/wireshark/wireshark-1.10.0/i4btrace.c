int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
T_3 V_5 ;
T_4 V_6 = FALSE ;
T_5 * V_7 ;
V_8 = V_9 ;
V_4 = F_2 ( & V_5 , sizeof( V_5 ) , V_1 -> V_10 ) ;
if ( V_4 != sizeof( V_5 ) ) {
* V_2 = F_3 ( V_1 -> V_10 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_11 )
return - 1 ;
return 0 ;
}
if ( ! F_4 ( V_5 ) ) {
V_5 . V_12 = F_5 ( V_5 . V_12 ) ;
V_5 . V_13 = F_5 ( V_5 . V_13 ) ;
V_5 . type = F_5 ( V_5 . type ) ;
V_5 . V_14 = F_5 ( V_5 . V_14 ) ;
V_5 . V_15 = F_5 ( V_5 . V_15 ) ;
if ( ! F_4 ( V_5 ) ) {
return 0 ;
}
V_6 = TRUE ;
}
if ( F_6 ( V_1 -> V_10 , 0 , V_16 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_17 = V_18 ;
V_7 = ( T_5 * ) F_7 ( sizeof( T_5 ) ) ;
V_1 -> V_19 = ( void * ) V_7 ;
V_1 -> V_20 = V_21 ;
V_1 -> V_22 = V_23 ;
V_1 -> V_24 = 0 ;
V_7 -> V_6 = V_6 ;
V_1 -> V_25 = V_26 ;
V_1 -> V_27 = V_28 ;
return 1 ;
}
static T_4 V_21 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_29 )
{
int V_30 ;
T_3 V_5 ;
T_7 V_12 ;
void * V_31 ;
* V_29 = F_8 ( V_1 -> V_10 ) ;
V_30 = F_9 ( V_1 -> V_10 , & V_5 , V_2 , V_3 ) ;
if ( V_30 <= 0 ) {
return FALSE ;
}
F_10 ( V_1 , & V_5 ) ;
if ( V_5 . V_12 < sizeof( V_5 ) ) {
* V_2 = V_32 ;
* V_3 = F_11 ( L_1 ,
V_5 . V_12 , ( unsigned long ) sizeof( V_5 ) ) ;
return FALSE ;
}
V_12 = V_5 . V_12 - ( T_7 ) sizeof( V_5 ) ;
if ( V_12 > V_33 ) {
* V_2 = V_32 ;
* V_3 = F_11 ( L_2 ,
V_12 , V_33 ) ;
return FALSE ;
}
V_1 -> V_34 . V_35 = V_36 ;
V_1 -> V_34 . V_37 = V_12 ;
V_1 -> V_34 . V_38 = V_12 ;
V_1 -> V_34 . V_39 . V_40 = V_5 . V_41 ;
V_1 -> V_34 . V_39 . V_42 = V_5 . V_43 * 1000 ;
F_12 ( V_1 -> V_44 , V_12 ) ;
V_31 = F_13 ( V_1 -> V_44 ) ;
if ( ! F_14 ( V_1 -> V_10 , ( V_45 * ) V_31 , V_12 , V_2 , V_3 ) )
return FALSE ;
switch ( V_5 . type ) {
case V_46 :
V_1 -> V_34 . V_47 = V_48 ;
break;
case V_49 :
case V_50 :
case V_51 :
V_1 -> V_34 . V_47 = V_26 ;
break;
}
F_15 ( & V_5 , & V_1 -> V_34 . V_52 ) ;
return TRUE ;
}
static T_4
V_23 ( T_1 * V_1 , T_6 V_53 ,
struct V_54 * V_34 , V_45 * V_55 , int V_12 ,
int * V_2 , T_2 * * V_3 )
{
union V_56 * V_52 = & V_34 -> V_52 ;
int V_30 ;
T_3 V_5 ;
if ( F_6 ( V_1 -> V_57 , V_53 , V_16 , V_2 ) == - 1 )
return FALSE ;
V_30 = F_9 ( V_1 -> V_57 , & V_5 , V_2 , V_3 ) ;
if ( V_30 <= 0 ) {
if ( V_30 == 0 ) {
* V_2 = V_11 ;
}
return FALSE ;
}
F_10 ( V_1 , & V_5 ) ;
F_15 ( & V_5 , V_52 ) ;
return F_14 ( V_1 -> V_57 , V_55 , V_12 , V_2 , V_3 ) ;
}
static int
F_9 ( T_8 V_10 , T_3 * V_5 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
V_8 = V_9 ;
V_4 = F_2 ( V_5 , sizeof *V_5 , V_10 ) ;
if ( V_4 != sizeof *V_5 ) {
* V_2 = F_3 ( V_10 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
if ( V_4 != 0 ) {
* V_2 = V_11 ;
return - 1 ;
}
return 0 ;
}
return 1 ;
}
static void
F_10 ( T_1 * V_1 , T_3 * V_5 )
{
T_5 * V_7 = ( T_5 * ) V_1 -> V_19 ;
if ( V_7 -> V_6 ) {
V_5 -> V_12 = F_5 ( V_5 -> V_12 ) ;
V_5 -> V_13 = F_5 ( V_5 -> V_13 ) ;
V_5 -> type = F_5 ( V_5 -> type ) ;
V_5 -> V_14 = F_5 ( V_5 -> V_14 ) ;
V_5 -> V_15 = F_5 ( V_5 -> V_15 ) ;
V_5 -> V_58 = F_5 ( V_5 -> V_58 ) ;
V_5 -> V_41 = F_5 ( V_5 -> V_41 ) ;
V_5 -> V_43 = F_5 ( V_5 -> V_43 ) ;
}
}
static T_4
F_14 ( T_8 V_10 , V_45 * V_55 , int V_12 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
V_8 = V_9 ;
V_4 = F_2 ( V_55 , V_12 , V_10 ) ;
if ( V_4 != V_12 ) {
* V_2 = F_3 ( V_10 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_11 ;
return FALSE ;
}
return TRUE ;
}
static void
F_15 ( T_3 * V_5 ,
union V_56 * V_52 )
{
V_52 -> V_59 . V_60 = ( V_5 -> V_14 == V_61 ) ;
switch ( V_5 -> type ) {
case V_49 :
V_52 -> V_59 . V_62 = 0 ;
break;
case V_50 :
V_52 -> V_59 . V_62 = 1 ;
break;
case V_51 :
V_52 -> V_59 . V_62 = 2 ;
break;
}
}
