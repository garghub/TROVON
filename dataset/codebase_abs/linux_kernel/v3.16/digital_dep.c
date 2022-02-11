static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 , sizeof( V_5 ) ) ;
V_4 -> V_6 [ 0 ] = V_4 -> V_7 ;
if ( V_2 -> V_8 == V_9 )
* F_2 ( V_4 , sizeof( V_5 ) ) = V_10 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
V_5 V_11 ;
if ( V_4 -> V_7 < 2 )
return - V_12 ;
if ( V_2 -> V_8 == V_9 )
F_4 ( V_4 , sizeof( V_5 ) ) ;
V_11 = V_4 -> V_6 [ 0 ] ;
if ( V_11 != V_4 -> V_7 )
return - V_12 ;
F_4 ( V_4 , sizeof( V_5 ) ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , void * V_13 ,
struct V_3 * V_14 )
{
struct V_15 * V_16 = V_13 ;
struct V_17 * V_18 ;
V_5 V_19 ;
int V_20 ;
if ( F_6 ( V_14 ) ) {
V_20 = F_7 ( V_14 ) ;
V_14 = NULL ;
goto exit;
}
V_20 = V_2 -> V_21 ( V_14 ) ;
if ( V_20 ) {
F_8 ( L_1 ) ;
goto exit;
}
V_20 = F_3 ( V_2 , V_14 ) ;
if ( V_20 ) {
F_8 ( L_2 ) ;
goto exit;
}
if ( V_14 -> V_7 < sizeof( struct V_17 ) ) {
V_20 = - V_12 ;
goto exit;
}
V_19 = V_14 -> V_7 - sizeof( struct V_17 ) ;
V_18 = (struct V_17 * ) V_14 -> V_6 ;
V_20 = F_9 ( V_2 -> V_22 , V_18 -> V_23 , V_19 ) ;
if ( V_20 )
goto exit;
V_20 = F_10 ( V_2 -> V_22 , V_16 -> V_24 , V_25 ,
V_26 ) ;
V_2 -> V_27 = 0 ;
exit:
F_11 ( V_14 ) ;
if ( V_20 )
V_2 -> V_28 = 0 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_15 * V_16 , T_1 V_29 , T_1 * V_23 ,
T_2 V_19 )
{
struct V_3 * V_4 ;
struct V_30 * V_31 ;
T_3 V_11 ;
V_11 = V_32 + V_19 ;
if ( V_11 > V_33 ) {
F_8 ( L_3 ) ;
return - V_34 ;
}
V_4 = F_13 ( V_2 , V_11 ) ;
if ( ! V_4 )
return - V_35 ;
F_14 ( V_4 , sizeof( struct V_30 ) ) ;
V_31 = (struct V_30 * ) V_4 -> V_6 ;
memset ( V_31 , 0 , sizeof( struct V_30 ) ) ;
V_31 -> V_36 = V_37 ;
V_31 -> V_38 = V_39 ;
if ( V_16 -> V_40 )
memcpy ( V_31 -> V_41 , V_16 -> V_42 , V_43 ) ;
else
F_15 ( V_31 -> V_41 , V_44 ) ;
V_31 -> V_45 = 0 ;
V_31 -> V_46 = 0 ;
V_31 -> V_47 = 0 ;
V_31 -> V_48 = V_49 ;
if ( V_19 ) {
V_31 -> V_48 |= V_50 ;
memcpy ( F_14 ( V_4 , V_19 ) , V_23 , V_19 ) ;
}
F_1 ( V_2 , V_4 ) ;
V_2 -> V_51 ( V_4 ) ;
return F_16 ( V_2 , V_4 , 500 , F_5 ,
V_16 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_52 * V_53 , V_5 V_54 )
{
struct V_55 * V_56 ;
struct V_3 * V_4 ;
int V_20 ;
V_4 = F_13 ( V_2 , 1 ) ;
if ( ! V_4 )
return - V_35 ;
* F_14 ( V_4 , 1 ) = V_54 ;
F_2 ( V_4 , sizeof( struct V_55 ) ) ;
V_56 = (struct V_55 * ) V_4 -> V_6 ;
V_56 -> V_36 = V_37 ;
V_56 -> V_38 = V_57 ;
V_56 -> V_58 = V_59 |
V_60 ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_51 ( V_4 ) ;
V_20 = F_16 ( V_2 , V_4 , 1500 , V_61 ,
V_53 ) ;
return V_20 ;
}
static void V_61 ( struct V_1 * V_2 , void * V_13 ,
struct V_3 * V_14 )
{
struct V_52 * V_53 = V_13 ;
struct V_55 * V_62 ;
V_5 V_58 ;
T_3 V_11 ;
int V_20 ;
if ( F_6 ( V_14 ) ) {
V_20 = F_7 ( V_14 ) ;
V_14 = NULL ;
goto exit;
}
V_20 = V_2 -> V_21 ( V_14 ) ;
if ( V_20 ) {
F_8 ( L_1 ) ;
goto error;
}
V_20 = F_3 ( V_2 , V_14 ) ;
if ( V_20 ) {
F_8 ( L_2 ) ;
goto exit;
}
V_62 = (struct V_55 * ) V_14 -> V_6 ;
if ( V_14 -> V_7 < sizeof( struct V_55 ) ||
V_62 -> V_36 != V_63 ||
V_62 -> V_38 != V_64 ) {
V_20 = - V_12 ;
goto error;
}
V_58 = V_62 -> V_58 ;
switch ( F_18 ( V_58 ) ) {
case V_65 :
if ( F_19 ( V_58 ) != V_2 -> V_27 ) {
F_8 ( L_4 ) ;
V_20 = - V_12 ;
goto error;
}
V_2 -> V_27 =
F_19 ( V_2 -> V_27 + 1 ) ;
V_20 = 0 ;
break;
case V_66 :
F_20 ( L_5 ) ;
V_20 = - V_12 ;
goto error;
case V_59 :
if ( ! F_21 ( V_58 ) ) {
V_20 = - V_34 ;
goto error;
}
V_20 = F_17 ( V_2 , V_53 , V_14 -> V_6 [ 3 ] ) ;
if ( V_20 )
goto error;
F_22 ( V_14 ) ;
return;
}
if ( F_23 ( V_58 ) ) {
F_20 ( L_6 ) ;
V_20 = - V_12 ;
goto error;
}
V_11 = sizeof( struct V_55 ) ;
if ( F_24 ( V_58 ) )
V_11 ++ ;
if ( V_11 > V_14 -> V_7 ) {
V_20 = - V_12 ;
goto error;
}
F_4 ( V_14 , V_11 ) ;
exit:
V_53 -> V_67 ( V_53 -> V_68 , V_14 , V_20 ) ;
error:
F_25 ( V_53 ) ;
if ( V_20 )
F_22 ( V_14 ) ;
}
int F_26 ( struct V_1 * V_2 ,
struct V_15 * V_16 , struct V_3 * V_4 ,
struct V_52 * V_53 )
{
struct V_55 * V_56 ;
F_2 ( V_4 , sizeof( struct V_55 ) ) ;
V_56 = (struct V_55 * ) V_4 -> V_6 ;
V_56 -> V_36 = V_37 ;
V_56 -> V_38 = V_57 ;
V_56 -> V_58 = V_2 -> V_27 ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_51 ( V_4 ) ;
return F_16 ( V_2 , V_4 , 1500 , V_61 ,
V_53 ) ;
}
static void F_27 ( struct V_1 * V_2 , V_5 V_69 )
{
V_2 -> V_8 = V_69 ;
V_2 -> V_51 = V_70 ;
V_2 -> V_21 = V_71 ;
if ( F_28 ( V_2 ) )
return;
switch ( V_2 -> V_8 ) {
case V_9 :
V_2 -> V_51 = V_72 ;
V_2 -> V_21 = V_73 ;
break;
case V_74 :
case V_75 :
V_2 -> V_51 = V_76 ;
V_2 -> V_21 = V_77 ;
break;
default:
break;
}
}
static void F_29 ( struct V_1 * V_2 , void * V_13 ,
struct V_3 * V_14 )
{
int V_20 ;
struct V_55 * V_56 ;
T_2 V_11 ;
if ( F_6 ( V_14 ) ) {
V_20 = F_7 ( V_14 ) ;
V_14 = NULL ;
goto exit;
}
V_20 = V_2 -> V_21 ( V_14 ) ;
if ( V_20 ) {
F_8 ( L_1 ) ;
goto exit;
}
V_20 = F_3 ( V_2 , V_14 ) ;
if ( V_20 ) {
F_8 ( L_2 ) ;
goto exit;
}
V_11 = sizeof( struct V_55 ) ;
V_56 = (struct V_55 * ) V_14 -> V_6 ;
if ( V_14 -> V_7 < V_11 || V_56 -> V_36 != V_37 ||
V_56 -> V_38 != V_57 ) {
V_20 = - V_12 ;
goto exit;
}
if ( F_24 ( V_56 -> V_58 ) )
V_11 ++ ;
if ( V_14 -> V_7 < V_11 ) {
V_20 = - V_12 ;
goto exit;
}
switch ( F_18 ( V_56 -> V_58 ) ) {
case V_65 :
F_30 ( L_7 ) ;
V_2 -> V_27 = F_19 ( V_56 -> V_58 ) ;
break;
case V_66 :
F_20 ( L_5 ) ;
V_20 = - V_34 ;
goto exit;
break;
case V_59 :
F_20 ( L_8 ) ;
V_20 = - V_34 ;
goto exit;
break;
}
F_4 ( V_14 , V_11 ) ;
V_20 = F_31 ( V_2 -> V_22 , V_14 ) ;
exit:
if ( V_20 )
F_22 ( V_14 ) ;
}
int F_32 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_55 * V_62 ;
F_2 ( V_4 , sizeof( struct V_55 ) ) ;
V_62 = (struct V_55 * ) V_4 -> V_6 ;
V_62 -> V_36 = V_63 ;
V_62 -> V_38 = V_64 ;
V_62 -> V_58 = V_2 -> V_27 ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_51 ( V_4 ) ;
return F_33 ( V_2 , V_4 , 1500 , F_29 ,
NULL ) ;
}
static void F_34 ( struct V_1 * V_2 ,
void * V_13 , struct V_3 * V_14 )
{
V_5 V_69 = ( unsigned long ) V_13 ;
if ( F_6 ( V_14 ) )
return;
F_27 ( V_2 , V_69 ) ;
F_35 ( V_2 , V_78 , V_69 ) ;
F_36 ( V_2 , 1500 , F_29 , NULL ) ;
F_11 ( V_14 ) ;
}
static int F_37 ( struct V_1 * V_2 , V_5 V_45 ,
V_5 V_69 )
{
struct V_79 * V_80 ;
struct V_3 * V_4 ;
int V_20 ;
V_4 = F_13 ( V_2 , sizeof( struct V_79 ) ) ;
if ( ! V_4 )
return - V_35 ;
F_14 ( V_4 , sizeof( struct V_79 ) ) ;
V_80 = (struct V_79 * ) V_4 -> V_6 ;
V_80 -> V_36 = V_63 ;
V_80 -> V_38 = V_81 ;
V_80 -> V_45 = V_45 ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_51 ( V_4 ) ;
V_20 = F_33 ( V_2 , V_4 , 0 , F_34 ,
( void * ) ( unsigned long ) V_69 ) ;
if ( V_20 )
F_22 ( V_4 ) ;
return V_20 ;
}
static void F_38 ( struct V_1 * V_2 , void * V_13 ,
struct V_3 * V_14 )
{
int V_20 ;
struct V_82 * V_83 ;
V_5 V_69 ;
V_5 V_84 ;
if ( F_6 ( V_14 ) ) {
V_20 = F_7 ( V_14 ) ;
V_14 = NULL ;
goto exit;
}
V_20 = V_2 -> V_21 ( V_14 ) ;
if ( V_20 ) {
F_8 ( L_1 ) ;
goto exit;
}
V_20 = F_3 ( V_2 , V_14 ) ;
if ( V_20 ) {
F_8 ( L_2 ) ;
goto exit;
}
V_83 = (struct V_82 * ) V_14 -> V_6 ;
if ( V_14 -> V_7 != sizeof( struct V_82 ) ||
V_83 -> V_36 != V_37 ||
V_83 -> V_38 != V_85 ) {
V_20 = - V_12 ;
goto exit;
}
V_84 = ( V_83 -> V_86 >> 3 ) & 0x07 ;
switch ( V_84 ) {
case 0 :
V_69 = V_9 ;
break;
case 1 :
V_69 = V_74 ;
break;
case 2 :
V_69 = V_75 ;
break;
default:
F_20 ( L_9 , V_84 ) ;
goto exit;
}
V_20 = F_37 ( V_2 , V_83 -> V_45 , V_69 ) ;
exit:
F_22 ( V_14 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
void * V_13 , struct V_3 * V_14 )
{
int V_87 ;
if ( F_6 ( V_14 ) ) {
F_40 ( V_2 ) ;
return;
}
V_87 = 2 ;
if ( V_14 -> V_6 [ 0 ] == V_10 )
V_87 ++ ;
if ( V_14 -> V_6 [ V_87 ] == V_85 )
F_38 ( V_2 , V_13 , V_14 ) ;
else
F_29 ( V_2 , V_13 , V_14 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_17 * V_18 ;
struct V_3 * V_4 ;
V_5 * V_23 ;
T_2 V_19 ;
int V_20 ;
V_23 = F_42 ( V_2 -> V_22 , & V_19 ) ;
if ( ! V_23 )
V_19 = 0 ;
V_4 = F_13 ( V_2 , sizeof( struct V_17 ) + V_19 ) ;
if ( ! V_4 )
return - V_35 ;
F_14 ( V_4 , sizeof( struct V_17 ) ) ;
V_18 = (struct V_17 * ) V_4 -> V_6 ;
memset ( V_18 , 0 , sizeof( struct V_17 ) ) ;
V_18 -> V_36 = V_63 ;
V_18 -> V_38 = V_88 ;
memcpy ( V_18 -> V_41 , V_31 -> V_41 , sizeof( V_31 -> V_41 ) ) ;
V_18 -> V_89 = 8 ;
V_18 -> V_48 = V_49 ;
if ( V_19 ) {
F_14 ( V_4 , V_19 ) ;
V_18 -> V_48 |= V_50 ;
memcpy ( V_18 -> V_23 , V_23 , V_19 ) ;
}
F_1 ( V_2 , V_4 ) ;
V_2 -> V_51 ( V_4 ) ;
V_20 = F_33 ( V_2 , V_4 , 999 ,
F_39 , NULL ) ;
if ( V_20 ) {
F_22 ( V_4 ) ;
return V_20 ;
}
return V_20 ;
}
void F_43 ( struct V_1 * V_2 , void * V_13 ,
struct V_3 * V_14 )
{
int V_20 ;
struct V_30 * V_31 ;
T_2 V_19 , V_90 ;
if ( F_6 ( V_14 ) ) {
V_20 = F_7 ( V_14 ) ;
V_14 = NULL ;
goto exit;
}
if ( ! V_14 -> V_7 ) {
V_20 = - V_12 ;
goto exit;
}
if ( V_14 -> V_6 [ 0 ] == V_10 ) {
V_90 = V_32 + 2 ;
F_27 ( V_2 , V_9 ) ;
} else {
V_90 = V_32 + 1 ;
F_27 ( V_2 , V_74 ) ;
}
if ( V_14 -> V_7 < V_90 ) {
V_20 = - V_12 ;
goto exit;
}
V_2 -> V_28 = V_91 ;
V_20 = V_2 -> V_21 ( V_14 ) ;
if ( V_20 ) {
F_8 ( L_1 ) ;
goto exit;
}
V_20 = F_3 ( V_2 , V_14 ) ;
if ( V_20 ) {
F_8 ( L_2 ) ;
goto exit;
}
V_31 = (struct V_30 * ) V_14 -> V_6 ;
if ( V_31 -> V_36 != V_37 ||
V_31 -> V_38 != V_39 ) {
V_20 = - V_34 ;
goto exit;
}
V_20 = F_35 ( V_2 , V_92 ,
V_93 ) ;
if ( V_20 )
goto exit;
V_20 = F_41 ( V_2 , V_31 ) ;
if ( V_20 )
goto exit;
V_19 = V_14 -> V_7 - sizeof( struct V_30 ) ;
V_20 = F_44 ( V_2 -> V_22 , V_91 ,
V_94 , V_31 -> V_23 , V_19 ) ;
if ( V_20 )
goto exit;
V_2 -> V_95 = 0 ;
V_20 = 0 ;
exit:
if ( V_20 )
F_40 ( V_2 ) ;
F_11 ( V_14 ) ;
}
