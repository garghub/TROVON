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
int V_19 ;
if ( F_6 ( V_14 ) ) {
V_19 = F_7 ( V_14 ) ;
V_14 = NULL ;
goto exit;
}
V_19 = V_2 -> V_20 ( V_14 ) ;
if ( V_19 ) {
F_8 ( L_1 ) ;
goto exit;
}
V_19 = F_3 ( V_2 , V_14 ) ;
if ( V_19 ) {
F_8 ( L_2 ) ;
goto exit;
}
V_18 = (struct V_17 * ) V_14 -> V_6 ;
if ( ( V_14 -> V_7 != sizeof( * V_18 ) ) ||
( V_18 -> V_21 != V_22 ) ||
( V_18 -> V_23 != V_24 ) ) {
V_19 = - V_12 ;
goto exit;
}
V_19 = F_9 ( V_2 , V_25 ,
V_26 ) ;
if ( V_19 )
goto exit;
V_19 = F_9 ( V_2 , V_27 ,
V_28 ) ;
if ( V_19 )
goto exit;
if ( ! F_10 ( V_2 ) &&
( V_2 -> V_8 == V_9 ) ) {
V_2 -> V_29 = V_30 ;
V_2 -> V_20 = V_31 ;
}
V_2 -> V_8 = V_26 ;
F_11 ( V_2 -> V_32 , V_16 -> V_33 , V_34 ,
V_35 ) ;
V_2 -> V_36 = 0 ;
exit:
F_12 ( V_14 ) ;
if ( V_19 )
V_2 -> V_37 = 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_3 * V_4 ;
struct V_38 * V_39 ;
V_4 = F_14 ( V_2 , sizeof( * V_39 ) ) ;
if ( ! V_4 )
return - V_40 ;
F_15 ( V_4 , sizeof( * V_39 ) ) ;
V_39 = (struct V_38 * ) V_4 -> V_6 ;
V_39 -> V_21 = V_41 ;
V_39 -> V_23 = V_42 ;
V_39 -> V_43 = 0 ;
V_39 -> V_44 = ( 0x2 << 3 ) | 0x2 ;
V_39 -> V_45 = V_46 ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_29 ( V_4 ) ;
return F_16 ( V_2 , V_4 , 500 , F_5 ,
V_16 ) ;
}
static void F_17 ( struct V_1 * V_2 , void * V_13 ,
struct V_3 * V_14 )
{
struct V_15 * V_16 = V_13 ;
struct V_47 * V_48 ;
V_5 V_49 ;
int V_19 ;
if ( F_6 ( V_14 ) ) {
V_19 = F_7 ( V_14 ) ;
V_14 = NULL ;
goto exit;
}
V_19 = V_2 -> V_20 ( V_14 ) ;
if ( V_19 ) {
F_8 ( L_1 ) ;
goto exit;
}
V_19 = F_3 ( V_2 , V_14 ) ;
if ( V_19 ) {
F_8 ( L_2 ) ;
goto exit;
}
if ( V_14 -> V_7 < sizeof( struct V_47 ) ) {
V_19 = - V_12 ;
goto exit;
}
V_49 = V_14 -> V_7 - sizeof( struct V_47 ) ;
V_48 = (struct V_47 * ) V_14 -> V_6 ;
V_19 = F_18 ( V_2 -> V_32 , V_48 -> V_50 , V_49 ) ;
if ( V_19 )
goto exit;
if ( ( V_2 -> V_51 & V_52 ) &&
( V_2 -> V_8 != V_26 ) ) {
V_19 = F_13 ( V_2 , V_16 ) ;
if ( ! V_19 )
goto exit;
}
V_19 = F_11 ( V_2 -> V_32 , V_16 -> V_33 , V_34 ,
V_35 ) ;
V_2 -> V_36 = 0 ;
exit:
F_12 ( V_14 ) ;
if ( V_19 )
V_2 -> V_37 = 0 ;
}
int F_19 ( struct V_1 * V_2 ,
struct V_15 * V_16 , T_1 V_53 , T_1 * V_50 ,
T_2 V_49 )
{
struct V_3 * V_4 ;
struct V_54 * V_55 ;
T_3 V_11 ;
V_11 = V_56 + V_49 ;
if ( V_11 > V_57 ) {
F_8 ( L_3 ) ;
return - V_58 ;
}
V_4 = F_14 ( V_2 , V_11 ) ;
if ( ! V_4 )
return - V_40 ;
F_15 ( V_4 , sizeof( struct V_54 ) ) ;
V_55 = (struct V_54 * ) V_4 -> V_6 ;
memset ( V_55 , 0 , sizeof( struct V_54 ) ) ;
V_55 -> V_21 = V_41 ;
V_55 -> V_23 = V_59 ;
if ( V_16 -> V_60 )
memcpy ( V_55 -> V_61 , V_16 -> V_62 , V_63 ) ;
else
F_20 ( V_55 -> V_61 , V_64 ) ;
V_55 -> V_43 = 0 ;
V_55 -> V_65 = 0 ;
V_55 -> V_66 = 0 ;
V_55 -> V_67 = V_68 ;
if ( V_49 ) {
V_55 -> V_67 |= V_69 ;
memcpy ( F_15 ( V_4 , V_49 ) , V_50 , V_49 ) ;
}
F_1 ( V_2 , V_4 ) ;
V_2 -> V_29 ( V_4 ) ;
return F_16 ( V_2 , V_4 , 500 , F_17 ,
V_16 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_70 * V_71 , V_5 V_72 )
{
struct V_73 * V_74 ;
struct V_3 * V_4 ;
int V_19 ;
V_4 = F_14 ( V_2 , 1 ) ;
if ( ! V_4 )
return - V_40 ;
* F_15 ( V_4 , 1 ) = V_72 ;
F_2 ( V_4 , sizeof( struct V_73 ) ) ;
V_74 = (struct V_73 * ) V_4 -> V_6 ;
V_74 -> V_21 = V_41 ;
V_74 -> V_23 = V_75 ;
V_74 -> V_76 = V_77 |
V_78 ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_29 ( V_4 ) ;
V_19 = F_16 ( V_2 , V_4 , 1500 , V_79 ,
V_71 ) ;
return V_19 ;
}
static void V_79 ( struct V_1 * V_2 , void * V_13 ,
struct V_3 * V_14 )
{
struct V_70 * V_71 = V_13 ;
struct V_73 * V_80 ;
V_5 V_76 ;
T_3 V_11 ;
int V_19 ;
if ( F_6 ( V_14 ) ) {
V_19 = F_7 ( V_14 ) ;
V_14 = NULL ;
goto exit;
}
V_19 = V_2 -> V_20 ( V_14 ) ;
if ( V_19 ) {
F_8 ( L_1 ) ;
goto error;
}
V_19 = F_3 ( V_2 , V_14 ) ;
if ( V_19 ) {
F_8 ( L_2 ) ;
goto exit;
}
V_80 = (struct V_73 * ) V_14 -> V_6 ;
if ( V_14 -> V_7 < sizeof( struct V_73 ) ||
V_80 -> V_21 != V_22 ||
V_80 -> V_23 != V_81 ) {
V_19 = - V_12 ;
goto error;
}
V_76 = V_80 -> V_76 ;
switch ( F_22 ( V_76 ) ) {
case V_82 :
if ( F_23 ( V_76 ) != V_2 -> V_36 ) {
F_8 ( L_4 ) ;
V_19 = - V_12 ;
goto error;
}
V_2 -> V_36 =
F_23 ( V_2 -> V_36 + 1 ) ;
V_19 = 0 ;
break;
case V_83 :
F_24 ( L_5 ) ;
V_19 = - V_12 ;
goto error;
case V_77 :
if ( ! F_25 ( V_76 ) ) {
V_19 = - V_58 ;
goto error;
}
V_19 = F_21 ( V_2 , V_71 , V_14 -> V_6 [ 3 ] ) ;
if ( V_19 )
goto error;
F_26 ( V_14 ) ;
return;
}
if ( F_27 ( V_76 ) ) {
F_24 ( L_6 ) ;
V_19 = - V_12 ;
goto error;
}
V_11 = sizeof( struct V_73 ) ;
if ( F_28 ( V_76 ) )
V_11 ++ ;
if ( V_11 > V_14 -> V_7 ) {
V_19 = - V_12 ;
goto error;
}
F_4 ( V_14 , V_11 ) ;
exit:
V_71 -> V_84 ( V_71 -> V_85 , V_14 , V_19 ) ;
error:
F_29 ( V_71 ) ;
if ( V_19 )
F_26 ( V_14 ) ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_15 * V_16 , struct V_3 * V_4 ,
struct V_70 * V_71 )
{
struct V_73 * V_74 ;
F_2 ( V_4 , sizeof( struct V_73 ) ) ;
V_74 = (struct V_73 * ) V_4 -> V_6 ;
V_74 -> V_21 = V_41 ;
V_74 -> V_23 = V_75 ;
V_74 -> V_76 = V_2 -> V_36 ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_29 ( V_4 ) ;
return F_16 ( V_2 , V_4 , 1500 , V_79 ,
V_71 ) ;
}
static void F_31 ( struct V_1 * V_2 , V_5 V_86 )
{
V_2 -> V_8 = V_86 ;
V_2 -> V_29 = V_87 ;
V_2 -> V_20 = V_88 ;
if ( F_32 ( V_2 ) )
return;
switch ( V_2 -> V_8 ) {
case V_9 :
V_2 -> V_29 = V_89 ;
V_2 -> V_20 = V_90 ;
break;
case V_91 :
case V_26 :
V_2 -> V_29 = V_30 ;
V_2 -> V_20 = V_31 ;
break;
default:
break;
}
}
static void F_33 ( struct V_1 * V_2 , void * V_13 ,
struct V_3 * V_14 )
{
int V_19 ;
struct V_73 * V_74 ;
T_2 V_11 ;
if ( F_6 ( V_14 ) ) {
V_19 = F_7 ( V_14 ) ;
V_14 = NULL ;
goto exit;
}
V_19 = V_2 -> V_20 ( V_14 ) ;
if ( V_19 ) {
F_8 ( L_1 ) ;
goto exit;
}
V_19 = F_3 ( V_2 , V_14 ) ;
if ( V_19 ) {
F_8 ( L_2 ) ;
goto exit;
}
V_11 = sizeof( struct V_73 ) ;
V_74 = (struct V_73 * ) V_14 -> V_6 ;
if ( V_14 -> V_7 < V_11 || V_74 -> V_21 != V_41 ||
V_74 -> V_23 != V_75 ) {
V_19 = - V_12 ;
goto exit;
}
if ( F_28 ( V_74 -> V_76 ) )
V_11 ++ ;
if ( V_14 -> V_7 < V_11 ) {
V_19 = - V_12 ;
goto exit;
}
switch ( F_22 ( V_74 -> V_76 ) ) {
case V_82 :
F_34 ( L_7 ) ;
V_2 -> V_36 = F_23 ( V_74 -> V_76 ) ;
break;
case V_83 :
F_24 ( L_5 ) ;
V_19 = - V_58 ;
goto exit;
case V_77 :
F_24 ( L_8 ) ;
V_19 = - V_58 ;
goto exit;
}
F_4 ( V_14 , V_11 ) ;
V_19 = F_35 ( V_2 -> V_32 , V_14 ) ;
exit:
if ( V_19 )
F_26 ( V_14 ) ;
}
int F_36 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_73 * V_80 ;
F_2 ( V_4 , sizeof( struct V_73 ) ) ;
V_80 = (struct V_73 * ) V_4 -> V_6 ;
V_80 -> V_21 = V_22 ;
V_80 -> V_23 = V_81 ;
V_80 -> V_76 = V_2 -> V_36 ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_29 ( V_4 ) ;
return F_37 ( V_2 , V_4 , 1500 , F_33 ,
NULL ) ;
}
static void F_38 ( struct V_1 * V_2 ,
void * V_13 , struct V_3 * V_14 )
{
V_5 V_86 = ( unsigned long ) V_13 ;
if ( F_6 ( V_14 ) )
return;
F_31 ( V_2 , V_86 ) ;
F_39 ( V_2 , V_25 , V_86 ) ;
F_40 ( V_2 , 1500 , F_33 , NULL ) ;
F_12 ( V_14 ) ;
}
static int F_41 ( struct V_1 * V_2 , V_5 V_43 ,
V_5 V_86 )
{
struct V_17 * V_18 ;
struct V_3 * V_4 ;
int V_19 ;
V_4 = F_14 ( V_2 , sizeof( struct V_17 ) ) ;
if ( ! V_4 )
return - V_40 ;
F_15 ( V_4 , sizeof( struct V_17 ) ) ;
V_18 = (struct V_17 * ) V_4 -> V_6 ;
V_18 -> V_21 = V_22 ;
V_18 -> V_23 = V_24 ;
V_18 -> V_43 = V_43 ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_29 ( V_4 ) ;
V_19 = F_37 ( V_2 , V_4 , 0 , F_38 ,
( void * ) ( unsigned long ) V_86 ) ;
if ( V_19 )
F_26 ( V_4 ) ;
return V_19 ;
}
static void F_42 ( struct V_1 * V_2 , void * V_13 ,
struct V_3 * V_14 )
{
int V_19 ;
struct V_38 * V_39 ;
V_5 V_86 ;
V_5 V_92 ;
if ( F_6 ( V_14 ) ) {
V_19 = F_7 ( V_14 ) ;
V_14 = NULL ;
goto exit;
}
V_19 = V_2 -> V_20 ( V_14 ) ;
if ( V_19 ) {
F_8 ( L_1 ) ;
goto exit;
}
V_19 = F_3 ( V_2 , V_14 ) ;
if ( V_19 ) {
F_8 ( L_2 ) ;
goto exit;
}
V_39 = (struct V_38 * ) V_14 -> V_6 ;
if ( V_14 -> V_7 != sizeof( struct V_38 ) ||
V_39 -> V_21 != V_41 ||
V_39 -> V_23 != V_42 ) {
V_19 = - V_12 ;
goto exit;
}
V_92 = ( V_39 -> V_44 >> 3 ) & 0x07 ;
switch ( V_92 ) {
case 0 :
V_86 = V_9 ;
break;
case 1 :
V_86 = V_91 ;
break;
case 2 :
V_86 = V_26 ;
break;
default:
F_24 ( L_9 , V_92 ) ;
goto exit;
}
V_19 = F_41 ( V_2 , V_39 -> V_43 , V_86 ) ;
exit:
F_26 ( V_14 ) ;
}
static void F_43 ( struct V_1 * V_2 ,
void * V_13 , struct V_3 * V_14 )
{
int V_93 ;
if ( F_6 ( V_14 ) ) {
F_44 ( V_2 ) ;
return;
}
V_93 = 2 ;
if ( V_14 -> V_6 [ 0 ] == V_10 )
V_93 ++ ;
if ( V_14 -> V_6 [ V_93 ] == V_42 )
F_42 ( V_2 , V_13 , V_14 ) ;
else
F_33 ( V_2 , V_13 , V_14 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_54 * V_55 )
{
struct V_47 * V_48 ;
struct V_3 * V_4 ;
V_5 * V_50 ;
T_2 V_49 ;
int V_19 ;
V_50 = F_46 ( V_2 -> V_32 , & V_49 ) ;
if ( ! V_50 )
V_49 = 0 ;
V_4 = F_14 ( V_2 , sizeof( struct V_47 ) + V_49 ) ;
if ( ! V_4 )
return - V_40 ;
F_15 ( V_4 , sizeof( struct V_47 ) ) ;
V_48 = (struct V_47 * ) V_4 -> V_6 ;
memset ( V_48 , 0 , sizeof( struct V_47 ) ) ;
V_48 -> V_21 = V_22 ;
V_48 -> V_23 = V_94 ;
memcpy ( V_48 -> V_61 , V_55 -> V_61 , sizeof( V_55 -> V_61 ) ) ;
V_48 -> V_95 = 8 ;
V_48 -> V_67 = V_68 ;
if ( V_49 ) {
F_15 ( V_4 , V_49 ) ;
V_48 -> V_67 |= V_69 ;
memcpy ( V_48 -> V_50 , V_50 , V_49 ) ;
}
F_1 ( V_2 , V_4 ) ;
V_2 -> V_29 ( V_4 ) ;
V_19 = F_37 ( V_2 , V_4 , 999 ,
F_43 , NULL ) ;
if ( V_19 ) {
F_26 ( V_4 ) ;
return V_19 ;
}
return V_19 ;
}
void F_47 ( struct V_1 * V_2 , void * V_13 ,
struct V_3 * V_14 )
{
int V_19 ;
struct V_54 * V_55 ;
T_2 V_49 , V_96 ;
V_5 V_97 ;
if ( F_6 ( V_14 ) ) {
V_19 = F_7 ( V_14 ) ;
V_14 = NULL ;
goto exit;
}
if ( ! V_14 -> V_7 ) {
V_19 = - V_12 ;
goto exit;
}
if ( V_14 -> V_6 [ 0 ] == V_10 ) {
V_96 = V_56 + 2 ;
F_31 ( V_2 , V_9 ) ;
} else {
V_96 = V_56 + 1 ;
F_31 ( V_2 , V_91 ) ;
}
if ( V_14 -> V_7 < V_96 ) {
V_19 = - V_12 ;
goto exit;
}
V_2 -> V_37 = V_98 ;
V_19 = V_2 -> V_20 ( V_14 ) ;
if ( V_19 ) {
F_8 ( L_1 ) ;
goto exit;
}
V_19 = F_3 ( V_2 , V_14 ) ;
if ( V_19 ) {
F_8 ( L_2 ) ;
goto exit;
}
V_55 = (struct V_54 * ) V_14 -> V_6 ;
if ( V_55 -> V_21 != V_41 ||
V_55 -> V_23 != V_59 ) {
V_19 = - V_58 ;
goto exit;
}
V_19 = F_39 ( V_2 , V_27 ,
V_99 ) ;
if ( V_19 )
goto exit;
V_19 = F_45 ( V_2 , V_55 ) ;
if ( V_19 )
goto exit;
V_49 = V_14 -> V_7 - sizeof( struct V_54 ) ;
V_97 = V_2 -> V_97 ;
V_2 -> V_97 = 0 ;
V_19 = F_48 ( V_2 -> V_32 , V_98 ,
V_100 , V_55 -> V_50 , V_49 ) ;
if ( V_19 ) {
V_2 -> V_97 = V_97 ;
goto exit;
}
V_19 = 0 ;
exit:
if ( V_19 )
F_44 ( V_2 ) ;
F_12 ( V_14 ) ;
}
