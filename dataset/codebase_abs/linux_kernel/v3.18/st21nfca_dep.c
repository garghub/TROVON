static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ,
struct V_3 ,
V_5 . V_6 ) ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
if ( V_4 ) {
V_8 = V_4 -> V_11 -> V_12 ;
V_10 = V_4 -> V_5 . V_13 ;
F_3 ( & V_8 -> V_8 ) ;
F_4 ( V_4 -> V_11 , V_14 ,
V_15 , V_10 -> V_16 , V_10 -> V_17 ,
V_4 -> V_18 , V_4 ) ;
F_5 ( & V_8 -> V_8 ) ;
F_6 ( V_10 ) ;
}
}
static void F_7 ( struct V_3 * V_4 ,
struct V_9 * V_10 )
{
V_4 -> V_5 . V_13 = V_10 ;
F_8 ( & V_4 -> V_5 . V_6 ) ;
}
static int F_9 ( struct V_19 * V_11 ,
struct V_20 * V_21 )
{
struct V_22 * V_23 ;
struct V_9 * V_10 ;
T_1 V_24 ;
int V_25 ;
struct V_3 * V_4 = F_10 ( V_11 ) ;
V_24 = V_21 -> V_26 - sizeof( struct V_20 ) ;
V_10 = F_11 ( V_21 -> V_26 + 1 , V_27 ) ;
if ( ! V_10 )
return - V_28 ;
F_12 ( V_10 , sizeof( struct V_22 ) ) ;
V_23 = (struct V_22 * ) V_10 -> V_16 ;
memset ( V_23 , 0 , sizeof( struct V_22 ) ) ;
V_23 -> V_26 = V_21 -> V_26 + 1 ;
V_23 -> V_29 = V_30 ;
V_23 -> V_31 = V_32 ;
memcpy ( V_23 -> V_33 , V_21 -> V_33 , 6 ) ;
V_23 -> V_34 = 0x00 ;
V_23 -> V_35 = 0x00 ;
V_23 -> V_36 = V_37 ;
V_23 -> V_38 = V_39 ;
if ( V_24 ) {
F_12 ( V_10 , V_24 ) ;
V_23 -> V_38 |= V_40 ;
memcpy ( V_23 -> V_41 , V_21 -> V_41 , V_24 ) ;
V_25 = F_13 ( V_11 -> V_12 , V_23 -> V_41 ,
V_24 ) ;
if ( V_25 < 0 )
return V_25 ;
}
V_4 -> V_5 . V_42 = 0 ;
V_25 = F_14 ( V_11 , V_43 ,
V_44 , V_10 -> V_16 , V_10 -> V_17 ) ;
F_6 ( V_10 ) ;
return V_25 ;
}
static int F_15 ( struct V_19 * V_11 ,
struct V_9 * V_10 )
{
struct V_20 * V_21 ;
T_1 V_24 ;
int V_25 ;
F_16 ( V_10 , V_10 -> V_17 - 1 ) ;
if ( ! V_10 -> V_17 ) {
V_25 = - V_45 ;
goto exit;
}
if ( V_10 -> V_17 < V_46 ) {
V_25 = - V_47 ;
goto exit;
}
V_21 = (struct V_20 * ) V_10 -> V_16 ;
if ( V_21 -> V_26 < sizeof( struct V_20 ) ) {
V_25 = - V_47 ;
goto exit;
}
V_25 = F_9 ( V_11 , V_21 ) ;
if ( V_25 )
goto exit;
V_24 = V_10 -> V_17 - sizeof( struct V_20 ) ;
V_25 = F_17 ( V_11 -> V_12 , V_48 ,
V_49 , V_21 -> V_41 , V_24 ) ;
if ( V_25 )
goto exit;
V_25 = 0 ;
exit:
return V_25 ;
}
static int F_18 ( struct V_19 * V_11 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 ;
struct V_9 * V_10 ;
T_2 V_54 [ 2 ] = { 0 , 0 } ;
int V_25 ;
V_10 = F_11 ( sizeof( struct V_52 ) , V_27 ) ;
if ( ! V_10 )
return - V_28 ;
F_12 ( V_10 , sizeof( struct V_52 ) ) ;
V_53 = (struct V_52 * ) V_10 -> V_16 ;
V_53 -> V_26 = sizeof( struct V_52 ) ;
V_53 -> V_29 = V_30 ;
V_53 -> V_31 = V_55 ;
V_53 -> V_56 = V_51 -> V_56 ;
V_25 = F_14 ( V_11 , V_43 ,
V_44 , V_10 -> V_16 , V_10 -> V_17 ) ;
if ( V_25 < 0 )
goto error;
if ( F_19 ( V_51 -> V_57 ) &&
F_20 ( V_51 -> V_57 ) ) {
V_54 [ 0 ] = V_58 ;
V_54 [ 1 ] = V_58 ;
}
V_25 = F_14 ( V_11 , V_43 ,
V_59 , V_54 , 2 ) ;
error:
F_6 ( V_10 ) ;
return V_25 ;
}
static int F_21 ( struct V_19 * V_11 ,
struct V_9 * V_10 )
{
struct V_50 * V_51 ;
int V_25 ;
F_16 ( V_10 , V_10 -> V_17 - 1 ) ;
if ( ! V_10 -> V_17 ) {
V_25 = - V_45 ;
goto exit;
}
V_51 = (struct V_50 * ) V_10 -> V_16 ;
if ( V_10 -> V_17 < sizeof( struct V_50 ) ) {
V_25 = - V_45 ;
goto exit;
}
V_25 = F_18 ( V_11 , V_51 ) ;
exit:
return V_25 ;
}
int F_22 ( struct V_19 * V_11 , struct V_9 * V_10 )
{
int V_25 ;
struct V_3 * V_4 = F_10 ( V_11 ) ;
* F_23 ( V_10 , 1 ) = V_4 -> V_5 . V_42 ;
* F_23 ( V_10 , 1 ) = V_60 ;
* F_23 ( V_10 , 1 ) = V_30 ;
* F_23 ( V_10 , 1 ) = V_10 -> V_17 ;
V_25 = F_14 ( V_11 , V_43 ,
V_44 , V_10 -> V_16 , V_10 -> V_17 ) ;
F_6 ( V_10 ) ;
return V_25 ;
}
static int F_24 ( struct V_19 * V_11 ,
struct V_9 * V_10 )
{
struct V_61 * V_62 ;
T_2 V_63 ;
int V_25 ;
struct V_3 * V_4 = F_10 ( V_11 ) ;
F_16 ( V_10 , V_10 -> V_17 - 1 ) ;
V_63 = 4 ;
V_62 = (struct V_61 * ) V_10 -> V_16 ;
if ( V_10 -> V_17 < V_63 ) {
V_25 = - V_45 ;
goto exit;
}
if ( F_25 ( V_62 -> V_64 ) )
V_63 ++ ;
if ( F_26 ( V_62 -> V_64 ) )
V_63 ++ ;
if ( V_10 -> V_17 < V_63 ) {
V_25 = - V_45 ;
goto exit;
}
switch ( F_27 ( V_62 -> V_64 ) ) {
case V_65 :
V_4 -> V_5 . V_42 =
F_28 ( V_62 -> V_64 ) ;
break;
case V_66 :
F_29 ( L_1 ) ;
break;
case V_67 :
F_29 ( L_2 ) ;
break;
}
F_30 ( V_10 , V_63 ) ;
return F_31 ( V_11 -> V_12 , V_10 ) ;
exit:
return V_25 ;
}
int F_32 ( struct V_19 * V_11 , struct V_9 * V_10 ,
T_2 V_68 )
{
T_2 V_29 , V_31 ;
int V_25 ;
V_29 = V_10 -> V_16 [ 1 ] ;
switch ( V_29 ) {
case V_69 :
V_31 = V_10 -> V_16 [ 2 ] ;
switch ( V_31 ) {
case V_70 :
V_25 = F_15 ( V_11 , V_10 ) ;
break;
case V_71 :
V_25 = F_21 ( V_11 , V_10 ) ;
break;
case V_72 :
V_25 = F_24 ( V_11 , V_10 ) ;
break;
default:
return 1 ;
}
default:
return 1 ;
}
return V_25 ;
}
static void F_33 ( struct V_19 * V_11 , T_2 V_56 , T_2 V_34 ,
T_2 V_35 , T_2 V_73 )
{
struct V_9 * V_10 ;
struct V_50 * V_51 ;
struct V_3 * V_4 = F_10 ( V_11 ) ;
V_10 =
F_11 ( sizeof( struct V_50 ) + 1 , V_27 ) ;
if ( ! V_10 )
return;
F_34 ( V_10 , 1 ) ;
F_12 ( V_10 , sizeof( struct V_50 ) ) ;
V_51 = (struct V_50 * ) V_10 -> V_16 ;
V_51 -> V_26 = sizeof( struct V_50 ) ;
V_51 -> V_29 = V_69 ;
V_51 -> V_31 = V_71 ;
V_51 -> V_56 = V_56 ;
V_51 -> V_57 = ( 0x30 & V_34 << 4 ) | ( V_35 & 0x03 ) ;
V_51 -> V_74 = V_73 ;
* F_23 ( V_10 , 1 ) = V_4 -> V_5 . V_36 | 0x10 ;
F_7 ( V_4 , V_10 ) ;
}
static void F_35 ( void * V_75 , struct V_9 * V_10 ,
int V_76 )
{
struct V_3 * V_4 = V_75 ;
struct V_22 * V_23 ;
int V_25 ;
if ( V_76 != 0 )
return;
if ( ! V_10 )
return;
switch ( V_4 -> V_77 ) {
case V_78 :
F_16 ( V_10 , V_10 -> V_17 - 1 ) ;
V_23 = (struct V_22 * ) V_10 -> V_16 ;
V_25 = F_13 ( V_4 -> V_11 -> V_12 ,
V_23 -> V_41 ,
V_10 -> V_17 - sizeof( struct V_22 ) ) ;
if ( V_25 < 0 )
return;
if ( V_23 -> V_36 >= 0x0e )
V_4 -> V_5 . V_36 = 0x0e ;
else
V_4 -> V_5 . V_36 = V_23 -> V_36 + 1 ;
V_4 -> V_5 . V_36 |= 0x10 ;
V_25 = F_36 ( V_4 -> V_11 -> V_12 , V_4 -> V_5 . V_79 ,
V_49 , V_80 ) ;
if ( V_25 < 0 )
return;
V_4 -> V_5 . V_42 = 0 ;
if ( F_37 ( V_23 -> V_38 ) != V_4 -> V_5 . V_73 )
F_33 ( V_4 -> V_11 , V_23 -> V_56 ,
V_23 -> V_34 , V_23 -> V_35 ,
F_37 ( V_23 -> V_38 ) ) ;
break;
default:
F_6 ( V_10 ) ;
break;
}
}
int F_38 ( struct V_19 * V_11 , T_2 * V_81 , T_1 V_24 )
{
struct V_9 * V_10 ;
struct V_3 * V_4 = F_10 ( V_11 ) ;
struct V_20 * V_21 ;
struct V_82 * V_83 ;
T_3 V_63 ;
V_4 -> V_5 . V_36 = V_37 ;
V_63 = V_46 + V_24 ;
if ( V_63 > V_84 ) {
F_39 ( L_3 ) ;
return - V_85 ;
}
V_10 =
F_11 ( sizeof( struct V_20 ) + V_24 + 1 , V_27 ) ;
if ( ! V_10 )
return - V_28 ;
F_34 ( V_10 , 1 ) ;
F_12 ( V_10 , sizeof( struct V_20 ) ) ;
V_21 = (struct V_20 * ) V_10 -> V_16 ;
memset ( V_21 , 0 , sizeof( struct V_20 ) ) ;
V_21 -> V_29 = V_69 ;
V_21 -> V_31 = V_70 ;
memset ( V_21 -> V_33 , 0 , V_86 ) ;
V_83 = V_11 -> V_12 -> V_87 ;
if ( V_83 -> V_88 > 0 )
memcpy ( V_21 -> V_33 , V_83 -> V_89 ,
V_83 -> V_88 ) ;
else
F_40 ( V_21 -> V_33 , V_86 ) ;
V_21 -> V_56 = 0x0 ;
V_21 -> V_34 = 0x00 ;
V_21 -> V_35 = 0x00 ;
V_21 -> V_38 = V_39 ;
if ( V_24 ) {
V_21 -> V_38 |= V_40 ;
memcpy ( F_12 ( V_10 , V_24 ) , V_81 , V_24 ) ;
}
V_21 -> V_26 = sizeof( struct V_20 ) + V_11 -> V_24 ;
* F_23 ( V_10 , 1 ) = V_4 -> V_5 . V_36 | 0x10 ;
V_4 -> V_77 = V_78 ;
V_4 -> V_90 = V_4 ;
V_4 -> V_18 = F_35 ;
V_4 -> V_5 . V_35 = V_21 -> V_35 ;
V_4 -> V_5 . V_34 = V_21 -> V_34 ;
V_4 -> V_5 . V_73 = F_37 ( V_21 -> V_38 ) ;
return F_4 ( V_11 , V_14 ,
V_15 , V_10 -> V_16 ,
V_10 -> V_17 , V_4 -> V_18 , V_4 ) ;
}
static void F_41 ( void * V_75 , struct V_9 * V_10 ,
int V_76 )
{
struct V_3 * V_4 = V_75 ;
struct V_61 * V_91 ;
int V_63 ;
if ( V_76 != 0 )
return;
if ( ! V_10 )
return;
switch ( V_4 -> V_77 ) {
case V_78 :
V_91 = (struct V_61 * ) V_10 -> V_16 ;
V_63 = 3 ;
if ( V_10 -> V_17 < V_63 )
goto exit;
if ( F_25 ( V_91 -> V_64 ) )
V_63 ++ ;
if ( F_26 ( V_91 -> V_64 ) )
V_63 ++ ;
if ( V_10 -> V_17 < V_63 )
goto exit;
F_16 ( V_10 , V_10 -> V_17 - 1 ) ;
switch ( F_27 ( V_91 -> V_64 ) ) {
case V_66 :
F_29 ( L_1 ) ;
case V_65 :
V_4 -> V_5 . V_42 =
F_28 ( V_91 -> V_64 + 1 ) ;
V_63 ++ ;
F_30 ( V_10 , V_63 ) ;
F_31 ( V_4 -> V_11 -> V_12 , V_10 ) ;
break;
case V_67 :
F_29 ( L_2 ) ;
F_30 ( V_10 , V_63 ) ;
* F_23 ( V_10 , 1 ) = V_72 ;
* F_23 ( V_10 , 1 ) = V_69 ;
* F_23 ( V_10 , 1 ) = V_10 -> V_17 ;
* F_23 ( V_10 , 1 ) = V_4 -> V_5 . V_36 | 0x10 ;
F_7 ( V_4 , V_10 ) ;
break;
}
return;
default:
break;
}
exit:
F_6 ( V_10 ) ;
}
int F_42 ( struct V_19 * V_11 , struct V_9 * V_10 )
{
struct V_3 * V_4 = F_10 ( V_11 ) ;
V_4 -> V_77 = V_78 ;
V_4 -> V_90 = V_4 ;
V_4 -> V_18 = F_41 ;
* F_23 ( V_10 , 1 ) = V_4 -> V_5 . V_42 ;
* F_23 ( V_10 , 1 ) = V_72 ;
* F_23 ( V_10 , 1 ) = V_69 ;
* F_23 ( V_10 , 1 ) = V_10 -> V_17 ;
* F_23 ( V_10 , 1 ) = V_4 -> V_5 . V_36 | 0x10 ;
return F_4 ( V_11 , V_14 ,
V_15 ,
V_10 -> V_16 , V_10 -> V_17 ,
V_4 -> V_18 , V_4 ) ;
}
void F_43 ( struct V_19 * V_11 )
{
struct V_3 * V_4 = F_10 ( V_11 ) ;
F_44 ( & V_4 -> V_5 . V_6 , F_1 ) ;
V_4 -> V_5 . V_42 = 0 ;
V_4 -> V_5 . V_79 = 0 ;
V_4 -> V_5 . V_36 = V_37 ;
}
void F_45 ( struct V_19 * V_11 )
{
struct V_3 * V_4 = F_10 ( V_11 ) ;
F_46 ( & V_4 -> V_5 . V_6 ) ;
}
