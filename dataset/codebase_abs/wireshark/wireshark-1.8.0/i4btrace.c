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
if ( * V_2 != 0 )
return - 1 ;
return 0 ;
}
if ( ! F_4 ( V_5 ) ) {
V_5 . V_11 = F_5 ( V_5 . V_11 ) ;
V_5 . V_12 = F_5 ( V_5 . V_12 ) ;
V_5 . type = F_5 ( V_5 . type ) ;
V_5 . V_13 = F_5 ( V_5 . V_13 ) ;
V_5 . V_14 = F_5 ( V_5 . V_14 ) ;
if ( ! F_4 ( V_5 ) ) {
return 0 ;
}
V_6 = TRUE ;
}
if ( F_6 ( V_1 -> V_10 , 0 , V_15 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_16 = V_17 ;
V_7 = ( T_5 * ) F_7 ( sizeof( T_5 ) ) ;
V_1 -> V_18 = ( void * ) V_7 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = 0 ;
V_7 -> V_6 = V_6 ;
V_1 -> V_24 = V_25 ;
V_1 -> V_26 = V_27 ;
return 1 ;
}
static T_4 V_20 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_28 )
{
int V_29 ;
T_3 V_5 ;
T_7 V_11 ;
void * V_30 ;
* V_28 = F_8 ( V_1 -> V_10 ) ;
V_29 = F_9 ( V_1 -> V_10 , & V_5 , V_2 , V_3 ) ;
if ( V_29 <= 0 ) {
return FALSE ;
}
F_10 ( V_1 , & V_5 ) ;
if ( V_5 . V_11 < sizeof( V_5 ) ) {
* V_2 = V_31 ;
* V_3 = F_11 ( L_1 ,
V_5 . V_11 , ( unsigned long ) sizeof( V_5 ) ) ;
return FALSE ;
}
V_11 = V_5 . V_11 - ( T_7 ) sizeof( V_5 ) ;
if ( V_11 > V_32 ) {
* V_2 = V_31 ;
* V_3 = F_11 ( L_2 ,
V_11 , V_32 ) ;
return FALSE ;
}
V_1 -> V_33 . V_34 = V_35 ;
V_1 -> V_33 . V_36 = V_11 ;
V_1 -> V_33 . V_37 = V_11 ;
V_1 -> V_33 . V_38 . V_39 = V_5 . V_40 ;
V_1 -> V_33 . V_38 . V_41 = V_5 . V_42 * 1000 ;
F_12 ( V_1 -> V_43 , V_11 ) ;
V_30 = F_13 ( V_1 -> V_43 ) ;
if ( ! F_14 ( V_1 -> V_10 , V_30 , V_11 , V_2 , V_3 ) )
return FALSE ;
switch ( V_5 . type ) {
case V_44 :
V_1 -> V_33 . V_45 = V_46 ;
break;
case V_47 :
case V_48 :
case V_49 :
V_1 -> V_33 . V_45 = V_25 ;
break;
}
F_15 ( & V_5 , & V_1 -> V_50 ) ;
return TRUE ;
}
static T_4
V_22 ( T_1 * V_1 , T_6 V_51 ,
union V_52 * V_50 , T_8 * V_53 , int V_11 ,
int * V_2 , T_2 * * V_3 )
{
int V_29 ;
T_3 V_5 ;
if ( F_6 ( V_1 -> V_54 , V_51 , V_15 , V_2 ) == - 1 )
return FALSE ;
V_29 = F_9 ( V_1 -> V_54 , & V_5 , V_2 , V_3 ) ;
if ( V_29 <= 0 ) {
if ( V_29 == 0 ) {
* V_2 = V_55 ;
}
return FALSE ;
}
F_10 ( V_1 , & V_5 ) ;
F_15 ( & V_5 , V_50 ) ;
return F_14 ( V_1 -> V_54 , V_53 , V_11 , V_2 , V_3 ) ;
}
static int
F_9 ( T_9 V_10 , T_3 * V_5 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
V_8 = V_9 ;
V_4 = F_2 ( V_5 , sizeof *V_5 , V_10 ) ;
if ( V_4 != sizeof *V_5 ) {
* V_2 = F_3 ( V_10 , V_3 ) ;
if ( * V_2 != 0 )
return - 1 ;
if ( V_4 != 0 ) {
* V_2 = V_55 ;
return - 1 ;
}
return 0 ;
}
return 1 ;
}
static void
F_10 ( T_1 * V_1 , T_3 * V_5 )
{
T_5 * V_7 = ( T_5 * ) V_1 -> V_18 ;
if ( V_7 -> V_6 ) {
V_5 -> V_11 = F_5 ( V_5 -> V_11 ) ;
V_5 -> V_12 = F_5 ( V_5 -> V_12 ) ;
V_5 -> type = F_5 ( V_5 -> type ) ;
V_5 -> V_13 = F_5 ( V_5 -> V_13 ) ;
V_5 -> V_14 = F_5 ( V_5 -> V_14 ) ;
V_5 -> V_56 = F_5 ( V_5 -> V_56 ) ;
V_5 -> V_40 = F_5 ( V_5 -> V_40 ) ;
V_5 -> V_42 = F_5 ( V_5 -> V_42 ) ;
}
}
static T_4
F_14 ( T_9 V_10 , T_8 * V_53 , int V_11 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
V_8 = V_9 ;
V_4 = F_2 ( V_53 , V_11 , V_10 ) ;
if ( V_4 != V_11 ) {
* V_2 = F_3 ( V_10 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_55 ;
return FALSE ;
}
return TRUE ;
}
static void
F_15 ( T_3 * V_5 ,
union V_52 * V_50 )
{
V_50 -> V_57 . V_58 = ( V_5 -> V_13 == V_59 ) ;
switch ( V_5 -> type ) {
case V_47 :
V_50 -> V_57 . V_60 = 0 ;
break;
case V_48 :
V_50 -> V_57 . V_60 = 1 ;
break;
case V_49 :
V_50 -> V_57 . V_60 = 2 ;
break;
}
}
