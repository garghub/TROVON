static void F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
V_2 -> V_6 = V_5 -> V_7 ;
V_2 -> V_8 = F_2 ( V_2 -> V_9 , V_5 -> V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 , void * V_3 )
{
struct V_10 * V_5 = V_3 ;
V_2 -> V_11 = V_5 -> V_11 ;
V_2 -> V_12 = V_5 -> V_12 ;
V_2 -> V_13 = V_5 -> V_13 ;
}
static void F_4 ( void * V_3 , unsigned int V_14 , void * V_15 )
{
struct V_16 * V_5 = V_3 ;
struct V_1 * V_2 =
(struct V_1 * ) ( unsigned long ) V_5 -> V_17 ;
F_5 ( V_2 , L_1 ,
V_5 -> V_18 , V_2 , V_5 -> V_19 ) ;
switch ( V_5 -> V_18 ) {
case V_20 :
F_1 ( V_2 , V_3 ) ;
break;
case V_21 :
break;
case V_22 :
F_3 ( V_2 , V_3 ) ;
break;
case V_23 :
break;
default:
F_6 ( V_2 , L_2 , V_5 -> V_18 ) ;
break;
}
V_2 -> V_24 = 1 ;
V_2 -> V_25 = ( V_5 -> V_19 != V_26 ) ;
F_7 ( V_2 ) ;
}
static int F_8 ( struct V_1 * V_2 , void * V_5 ,
int V_14 )
{
int V_19 ;
F_9 ( V_2 ) ;
if ( ! V_2 -> V_9 ) {
F_6 ( V_2 , L_3 ) ;
return - V_27 ;
}
V_19 = F_10 ( V_2 -> V_9 , V_2 -> V_28 , V_5 , V_14 ) ;
if ( V_19 ) {
F_6 ( V_2 , L_4 ,
* ( V_29 * ) V_5 , V_14 , V_19 ) ;
return - V_27 ;
}
if ( V_2 -> V_25 )
return - V_27 ;
F_7 ( V_2 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 )
{
int V_19 ;
struct V_30 V_31 ;
F_9 ( V_2 ) ;
F_12 ( & V_2 -> V_32 ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
V_19 = F_13 ( V_2 -> V_9 , V_2 -> V_28 , F_4 ,
NULL , NULL ) ;
if ( V_19 ) {
F_6 ( V_2 , L_5 , V_19 ) ;
return - V_27 ;
}
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_18 = V_33 ;
V_31 . V_17 = ( unsigned long ) V_2 ;
if ( F_8 ( V_2 , & V_31 , sizeof( V_31 ) ) ) {
F_6 ( V_2 , L_6 ) ;
return - V_27 ;
}
F_7 ( V_2 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
enum V_34 V_28 ,
struct V_35 * V_36 )
{
struct V_37 V_31 ;
F_5 ( V_2 , L_7 , V_28 ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_18 = V_38 ;
V_31 . V_7 = V_2 -> V_6 ;
V_31 . V_39 = V_28 ;
switch ( V_28 ) {
case V_40 :
V_31 . V_41 = 0 ;
break;
case V_42 :
V_31 . V_41 = 0 ;
break;
case V_43 :
V_31 . V_41 = 1 ;
V_31 . V_3 [ 0 ] = V_36 -> V_44 ;
break;
case V_45 :
V_31 . V_41 = 1 ;
V_31 . V_3 [ 0 ] = V_36 -> V_46 ;
break;
case V_47 :
V_31 . V_41 = 1 ;
V_31 . V_3 [ 0 ] = V_36 -> V_48 ;
break;
case V_49 :
V_31 . V_41 = 1 ;
V_31 . V_3 [ 0 ] = V_36 -> V_50 ;
break;
case V_51 :
V_31 . V_41 = 0 ;
break;
default:
F_6 ( V_2 , L_8 , V_28 ) ;
return - V_27 ;
}
if ( F_8 ( V_2 , & V_31 , sizeof( V_31 ) ) ) {
F_6 ( V_2 ,
L_9 , V_28 ) ;
return - V_27 ;
}
F_5 ( V_2 , L_10 , V_28 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , unsigned int V_52 ,
struct V_53 * V_54 ,
struct V_55 * V_56 ,
unsigned int * V_12 )
{
struct V_57 V_31 ;
F_5 ( V_2 , L_11 , V_52 ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_18 = V_58 ;
V_31 . V_7 = V_2 -> V_6 ;
V_31 . V_52 = V_52 ;
if ( V_54 ) {
if ( ( V_54 -> V_59 [ 0 ] . V_60 % 16 == 0 ) &&
( V_54 -> V_59 [ 1 ] . V_60 % 16 == 0 ) &&
( V_54 -> V_59 [ 2 ] . V_60 % 16 == 0 ) ) {
V_31 . V_61 [ 0 ] = V_54 -> V_59 [ 0 ] . V_60 ;
V_31 . V_61 [ 1 ] = V_54 -> V_59 [ 1 ] . V_60 ;
V_31 . V_61 [ 2 ] = V_54 -> V_59 [ 2 ] . V_60 ;
} else {
F_6 ( V_2 , L_12 ) ;
return - V_27 ;
}
}
if ( V_56 ) {
V_31 . V_62 = V_56 -> V_60 ;
V_31 . V_12 = V_56 -> V_63 ;
}
if ( F_8 ( V_2 , & V_31 , sizeof( V_31 ) ) ) {
F_6 ( V_2 , L_13 ,
V_52 ) ;
return - V_27 ;
}
F_5 ( V_2 , L_14 ,
V_52 , V_2 -> V_11 , V_2 -> V_12 , V_2 -> V_13 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_64 V_31 ;
F_9 ( V_2 ) ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_31 . V_18 = V_65 ;
V_31 . V_7 = V_2 -> V_6 ;
if ( F_8 ( V_2 , & V_31 , sizeof( V_31 ) ) ) {
F_6 ( V_2 , L_15 ) ;
return - V_27 ;
}
F_7 ( V_2 ) ;
return 0 ;
}
