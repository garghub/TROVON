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
T_1 V_18 = * ( T_1 * ) V_5 ;
F_6 ( V_2 , L_4 ,
V_18 , V_14 , V_19 ) ;
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
struct V_29 V_30 ;
F_9 ( V_2 ) ;
F_12 ( & V_2 -> V_31 ) ;
V_2 -> V_24 = 0 ;
V_2 -> V_25 = 0 ;
V_19 = F_13 ( V_2 -> V_9 , V_2 -> V_28 , F_4 ,
NULL , NULL ) ;
if ( V_19 ) {
F_6 ( V_2 , L_5 , V_19 ) ;
return - V_27 ;
}
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_18 = V_32 ;
V_30 . V_17 = ( unsigned long ) V_2 ;
if ( F_8 ( V_2 , & V_30 , sizeof( V_30 ) ) ) {
F_6 ( V_2 , L_6 ) ;
return - V_27 ;
}
F_7 ( V_2 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
enum V_33 V_28 ,
struct V_34 * V_35 )
{
struct V_36 V_30 ;
F_5 ( V_2 , L_7 , V_28 ) ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_18 = V_37 ;
V_30 . V_7 = V_2 -> V_6 ;
V_30 . V_38 = V_28 ;
switch ( V_28 ) {
case V_39 :
V_30 . V_40 = 0 ;
break;
case V_41 :
V_30 . V_40 = 0 ;
break;
case V_42 :
V_30 . V_40 = 1 ;
V_30 . V_3 [ 0 ] = V_35 -> V_43 ;
break;
case V_44 :
V_30 . V_40 = 1 ;
V_30 . V_3 [ 0 ] = V_35 -> V_45 ;
break;
case V_46 :
V_30 . V_40 = 1 ;
V_30 . V_3 [ 0 ] = V_35 -> V_47 ;
break;
case V_48 :
V_30 . V_40 = 1 ;
V_30 . V_3 [ 0 ] = V_35 -> V_49 ;
break;
case V_50 :
V_30 . V_40 = 0 ;
break;
default:
F_6 ( V_2 , L_8 , V_28 ) ;
return - V_27 ;
}
if ( F_8 ( V_2 , & V_30 , sizeof( V_30 ) ) ) {
F_6 ( V_2 ,
L_9 , V_28 ) ;
return - V_27 ;
}
F_5 ( V_2 , L_10 , V_28 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , unsigned int V_51 ,
struct V_52 * V_53 ,
struct V_54 * V_55 ,
unsigned int * V_12 )
{
struct V_56 V_30 ;
F_5 ( V_2 , L_11 , V_51 ) ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_18 = V_57 ;
V_30 . V_7 = V_2 -> V_6 ;
V_30 . V_51 = V_51 ;
if ( V_53 ) {
if ( ( V_53 -> V_58 [ 0 ] . V_59 % 16 == 0 ) &&
( V_53 -> V_58 [ 1 ] . V_59 % 16 == 0 ) &&
( V_53 -> V_58 [ 2 ] . V_59 % 16 == 0 ) ) {
V_30 . V_60 [ 0 ] = V_53 -> V_58 [ 0 ] . V_59 ;
V_30 . V_60 [ 1 ] = V_53 -> V_58 [ 1 ] . V_59 ;
V_30 . V_60 [ 2 ] = V_53 -> V_58 [ 2 ] . V_59 ;
} else {
F_6 ( V_2 , L_12 ) ;
return - V_27 ;
}
}
if ( V_55 ) {
V_30 . V_61 = V_55 -> V_59 ;
V_30 . V_12 = V_55 -> V_62 ;
}
if ( F_8 ( V_2 , & V_30 , sizeof( V_30 ) ) ) {
F_6 ( V_2 , L_13 ,
V_51 ) ;
return - V_27 ;
}
F_5 ( V_2 , L_14 ,
V_51 , V_2 -> V_11 , V_2 -> V_12 , V_2 -> V_13 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_63 V_30 ;
F_9 ( V_2 ) ;
memset ( & V_30 , 0 , sizeof( V_30 ) ) ;
V_30 . V_18 = V_64 ;
V_30 . V_7 = V_2 -> V_6 ;
if ( F_8 ( V_2 , & V_30 , sizeof( V_30 ) ) ) {
F_6 ( V_2 , L_15 ) ;
return - V_27 ;
}
F_7 ( V_2 ) ;
return 0 ;
}
