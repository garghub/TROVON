static T_1 F_1 ( T_1 V_1 )
{
if ( V_1 >= F_2 ( V_2 ) )
return 0 ;
return V_2 [ V_1 ] ;
}
static T_1 F_3 ( T_1 V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < F_2 ( V_2 ) ; V_4 ++ )
if ( V_2 [ V_4 ] == V_3 )
return V_4 ;
return 0xff ;
}
static void F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
F_5 ( V_8 , sizeof( T_1 ) ) ;
V_8 -> V_9 [ 0 ] = V_8 -> V_10 ;
if ( V_6 -> V_11 == V_12 )
* F_5 ( V_8 , sizeof( T_1 ) ) = V_13 ;
}
static int F_6 ( struct V_5 * V_6 ,
struct V_7 * V_8 )
{
T_1 V_14 ;
if ( V_8 -> V_10 < 2 )
return - V_15 ;
if ( V_6 -> V_11 == V_12 )
F_7 ( V_8 , sizeof( T_1 ) ) ;
V_14 = V_8 -> V_9 [ 0 ] ;
if ( V_14 != V_8 -> V_10 )
return - V_15 ;
F_7 ( V_8 , sizeof( T_1 ) ) ;
return 0 ;
}
static struct V_7 *
F_8 ( struct V_5 * V_6 , struct V_7 * V_8 ,
struct V_16 * V_17 ,
struct V_18 * V_19 )
{
struct V_7 * V_20 ;
if ( V_8 -> V_10 > V_6 -> V_21 ) {
V_17 -> V_22 |= V_23 ;
V_20 = F_9 ( V_6 , V_6 -> V_21 ) ;
if ( ! V_20 ) {
F_10 ( V_6 -> V_24 ) ;
V_6 -> V_24 = NULL ;
return F_11 ( - V_25 ) ;
}
F_12 ( V_20 , V_6 -> V_26 + V_27 +
V_28 ) ;
memcpy ( F_13 ( V_20 , V_6 -> V_21 ) , V_8 -> V_9 ,
V_6 -> V_21 ) ;
F_7 ( V_8 , V_6 -> V_21 ) ;
V_6 -> V_24 = V_8 ;
V_6 -> V_19 = V_19 ;
} else {
V_6 -> V_24 = NULL ;
V_20 = V_8 ;
}
return V_20 ;
}
static struct V_7 *
F_14 ( struct V_5 * V_6 , T_1 V_22 ,
struct V_7 * V_29 ,
int (* F_15)( struct V_5 * V_6 ,
struct V_18
* V_19 ) ,
struct V_18 * V_19 )
{
struct V_7 * V_20 ;
int V_30 ;
if ( F_16 ( V_22 ) && ( ! V_6 -> V_24 ) ) {
V_6 -> V_24 =
F_17 ( 8 * V_6 -> V_31 ,
V_32 ) ;
if ( ! V_6 -> V_24 ) {
V_30 = - V_25 ;
goto error;
}
}
if ( V_6 -> V_24 ) {
if ( V_29 -> V_10 > F_18 ( V_6 -> V_24 ) ) {
V_20 = F_19 ( V_6 -> V_24 ,
F_20 (
V_6 -> V_24 ) ,
8 * V_6 -> V_31 ,
V_32 ) ;
if ( ! V_20 ) {
V_30 = - V_25 ;
goto error;
}
F_10 ( V_6 -> V_24 ) ;
V_6 -> V_24 = V_20 ;
}
memcpy ( F_13 ( V_6 -> V_24 , V_29 -> V_10 ) , V_29 -> V_9 ,
V_29 -> V_10 ) ;
F_10 ( V_29 ) ;
V_29 = NULL ;
if ( F_16 ( V_22 ) ) {
V_30 = F_15 ( V_6 , V_19 ) ;
if ( V_30 )
goto error;
return NULL ;
}
V_29 = V_6 -> V_24 ;
V_6 -> V_24 = NULL ;
}
return V_29 ;
error:
F_10 ( V_29 ) ;
F_10 ( V_6 -> V_24 ) ;
V_6 -> V_24 = NULL ;
return F_11 ( V_30 ) ;
}
static void F_21 ( struct V_5 * V_6 , void * V_33 ,
struct V_7 * V_29 )
{
struct V_34 * V_35 = V_33 ;
struct V_36 * V_37 ;
int V_30 ;
if ( F_22 ( V_29 ) ) {
V_30 = F_23 ( V_29 ) ;
V_29 = NULL ;
goto exit;
}
V_30 = V_6 -> V_38 ( V_29 ) ;
if ( V_30 ) {
F_24 ( L_1 ) ;
goto exit;
}
V_30 = F_6 ( V_6 , V_29 ) ;
if ( V_30 ) {
F_24 ( L_2 ) ;
goto exit;
}
V_37 = (struct V_36 * ) V_29 -> V_9 ;
if ( ( V_29 -> V_10 != sizeof( * V_37 ) ) ||
( V_37 -> V_39 != V_40 ) ||
( V_37 -> V_41 != V_42 ) ) {
V_30 = - V_15 ;
goto exit;
}
V_30 = F_25 ( V_6 , V_43 ,
V_44 ) ;
if ( V_30 )
goto exit;
V_30 = F_25 ( V_6 , V_45 ,
V_46 ) ;
if ( V_30 )
goto exit;
if ( ! F_26 ( V_6 ) &&
( V_6 -> V_11 == V_12 ) ) {
V_6 -> V_47 = V_48 ;
V_6 -> V_38 = V_49 ;
}
V_6 -> V_11 = V_44 ;
F_27 ( V_6 -> V_50 , V_35 -> V_51 , V_52 ,
V_53 ) ;
V_6 -> V_54 = 0 ;
exit:
F_28 ( V_29 ) ;
if ( V_30 )
V_6 -> V_55 = 0 ;
}
static int F_29 ( struct V_5 * V_6 ,
struct V_34 * V_35 )
{
struct V_7 * V_8 ;
struct V_56 * V_57 ;
int V_30 ;
T_1 V_3 , V_1 ;
V_8 = F_9 ( V_6 , sizeof( * V_57 ) ) ;
if ( ! V_8 )
return - V_25 ;
F_13 ( V_8 , sizeof( * V_57 ) ) ;
V_57 = (struct V_56 * ) V_8 -> V_9 ;
V_57 -> V_39 = V_58 ;
V_57 -> V_41 = V_59 ;
V_57 -> V_60 = 0 ;
V_57 -> V_61 = ( 0x2 << 3 ) | 0x2 ;
V_3 = F_30 ( V_6 -> V_31 , V_6 -> V_21 ) ;
V_1 = F_3 ( V_3 ) ;
V_57 -> V_62 = F_31 ( V_1 ) ;
V_6 -> V_31 = V_3 ;
V_6 -> V_21 = V_3 ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_47 ( V_8 ) ;
V_30 = F_32 ( V_6 , V_8 , 500 , F_21 ,
V_35 ) ;
if ( V_30 )
F_10 ( V_8 ) ;
return V_30 ;
}
static void F_33 ( struct V_5 * V_6 , void * V_33 ,
struct V_7 * V_29 )
{
struct V_34 * V_35 = V_33 ;
struct V_63 * V_64 ;
T_1 V_65 , V_1 ;
int V_30 ;
if ( F_22 ( V_29 ) ) {
V_30 = F_23 ( V_29 ) ;
V_29 = NULL ;
goto exit;
}
V_30 = V_6 -> V_38 ( V_29 ) ;
if ( V_30 ) {
F_24 ( L_1 ) ;
goto exit;
}
V_30 = F_6 ( V_6 , V_29 ) ;
if ( V_30 ) {
F_24 ( L_2 ) ;
goto exit;
}
if ( V_29 -> V_10 < sizeof( struct V_63 ) ) {
V_30 = - V_15 ;
goto exit;
}
V_65 = V_29 -> V_10 - sizeof( struct V_63 ) ;
V_64 = (struct V_63 * ) V_29 -> V_9 ;
V_1 = F_34 ( V_64 -> V_66 ) ;
V_6 -> V_21 = F_1 ( V_1 ) ;
if ( ! V_6 -> V_21 ) {
V_30 = - V_67 ;
goto exit;
}
V_30 = F_35 ( V_6 -> V_50 , V_64 -> V_68 , V_65 ) ;
if ( V_30 )
goto exit;
if ( ( V_6 -> V_69 & V_70 ) &&
( V_6 -> V_11 != V_44 ) ) {
V_30 = F_29 ( V_6 , V_35 ) ;
if ( ! V_30 )
goto exit;
}
V_30 = F_27 ( V_6 -> V_50 , V_35 -> V_51 , V_52 ,
V_53 ) ;
V_6 -> V_54 = 0 ;
exit:
F_28 ( V_29 ) ;
if ( V_30 )
V_6 -> V_55 = 0 ;
}
int F_36 ( struct V_5 * V_6 ,
struct V_34 * V_35 , T_2 V_71 , T_2 * V_68 ,
T_3 V_65 )
{
struct V_7 * V_8 ;
struct V_72 * V_73 ;
T_4 V_14 ;
int V_30 ;
T_1 V_1 ;
V_14 = V_74 + V_65 ;
if ( V_14 > V_75 ) {
F_24 ( L_3 ) ;
return - V_67 ;
}
V_8 = F_9 ( V_6 , V_14 ) ;
if ( ! V_8 )
return - V_25 ;
F_13 ( V_8 , sizeof( struct V_72 ) ) ;
V_73 = (struct V_72 * ) V_8 -> V_9 ;
memset ( V_73 , 0 , sizeof( struct V_72 ) ) ;
V_73 -> V_39 = V_58 ;
V_73 -> V_41 = V_76 ;
if ( V_35 -> V_77 )
memcpy ( V_73 -> V_78 , V_35 -> V_79 , V_80 ) ;
else
F_37 ( V_73 -> V_78 , V_81 ) ;
V_73 -> V_60 = 0 ;
V_73 -> V_82 = 0 ;
V_73 -> V_83 = 0 ;
V_6 -> V_31 = V_84 ;
V_1 = F_3 ( V_6 -> V_31 ) ;
V_73 -> V_66 = F_38 ( V_1 ) ;
if ( V_65 ) {
V_73 -> V_66 |= V_85 ;
memcpy ( F_13 ( V_8 , V_65 ) , V_68 , V_65 ) ;
}
F_4 ( V_6 , V_8 ) ;
V_6 -> V_47 ( V_8 ) ;
V_30 = F_32 ( V_6 , V_8 , 500 , F_33 ,
V_35 ) ;
if ( V_30 )
F_10 ( V_8 ) ;
return V_30 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
struct V_16 * V_86 ;
struct V_7 * V_8 ;
int V_30 ;
V_8 = F_9 ( V_6 , 1 ) ;
if ( ! V_8 )
return - V_25 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_86 = (struct V_16 * ) V_8 -> V_9 ;
V_86 -> V_39 = V_58 ;
V_86 -> V_41 = V_87 ;
V_86 -> V_22 = V_88 |
V_6 -> V_54 ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_47 ( V_8 ) ;
V_6 -> V_89 = F_40 ( V_8 ) ;
V_6 -> V_90 = V_8 -> V_10 ;
V_30 = F_32 ( V_6 , V_8 , 1500 , V_91 ,
V_19 ) ;
if ( V_30 ) {
F_10 ( V_8 ) ;
F_10 ( V_6 -> V_89 ) ;
V_6 -> V_89 = NULL ;
}
return V_30 ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
struct V_16 * V_86 ;
struct V_7 * V_8 ;
int V_30 ;
V_8 = F_9 ( V_6 , 1 ) ;
if ( ! V_8 )
return - V_25 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_86 = (struct V_16 * ) V_8 -> V_9 ;
V_86 -> V_39 = V_58 ;
V_86 -> V_41 = V_87 ;
V_86 -> V_22 = V_88 |
V_92 | V_6 -> V_54 ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_47 ( V_8 ) ;
V_30 = F_32 ( V_6 , V_8 , 1500 , V_91 ,
V_19 ) ;
if ( V_30 )
F_10 ( V_8 ) ;
return V_30 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
struct V_16 * V_86 ;
struct V_7 * V_8 ;
int V_30 ;
V_8 = F_9 ( V_6 , 1 ) ;
if ( ! V_8 )
return - V_25 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_86 = (struct V_16 * ) V_8 -> V_9 ;
V_86 -> V_39 = V_58 ;
V_86 -> V_41 = V_87 ;
V_86 -> V_22 = V_93 ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_47 ( V_8 ) ;
V_30 = F_32 ( V_6 , V_8 , 1500 , V_91 ,
V_19 ) ;
if ( V_30 )
F_10 ( V_8 ) ;
return V_30 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_18 * V_19 , T_1 V_94 )
{
struct V_16 * V_86 ;
struct V_7 * V_8 ;
int V_30 ;
V_8 = F_9 ( V_6 , 1 ) ;
if ( ! V_8 )
return - V_25 ;
* F_13 ( V_8 , 1 ) = V_94 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_86 = (struct V_16 * ) V_8 -> V_9 ;
V_86 -> V_39 = V_58 ;
V_86 -> V_41 = V_87 ;
V_86 -> V_22 = V_93 |
V_95 ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_47 ( V_8 ) ;
V_6 -> V_89 = F_40 ( V_8 ) ;
V_6 -> V_90 = V_8 -> V_10 ;
V_30 = F_32 ( V_6 , V_8 , 1500 , V_91 ,
V_19 ) ;
if ( V_30 ) {
F_10 ( V_8 ) ;
F_10 ( V_6 -> V_89 ) ;
V_6 -> V_89 = NULL ;
}
return V_30 ;
}
static int F_44 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
F_40 ( V_6 -> V_89 ) ;
F_5 ( V_6 -> V_89 , V_6 -> V_90 ) ;
return F_32 ( V_6 , V_6 -> V_89 , 1500 ,
V_91 , V_19 ) ;
}
static void V_91 ( struct V_5 * V_6 , void * V_33 ,
struct V_7 * V_29 )
{
struct V_18 * V_19 = V_33 ;
struct V_16 * V_96 ;
T_1 V_22 ;
T_4 V_14 ;
int V_30 ;
if ( F_22 ( V_29 ) ) {
V_30 = F_23 ( V_29 ) ;
V_29 = NULL ;
if ( ( ( V_30 != - V_97 ) || V_6 -> V_98 ) &&
( V_6 -> V_98 ++ < V_99 ) ) {
V_6 -> V_100 = 0 ;
V_30 = F_41 ( V_6 , V_19 ) ;
if ( V_30 )
goto error;
return;
} else if ( ( V_30 == - V_97 ) &&
( V_6 -> V_100 ++ < V_101 ) ) {
V_6 -> V_98 = 0 ;
V_30 = F_42 ( V_6 , V_19 ) ;
if ( V_30 )
goto error;
return;
}
goto exit;
}
V_30 = F_6 ( V_6 , V_29 ) ;
if ( V_30 ) {
F_24 ( L_2 ) ;
goto exit;
}
V_30 = V_6 -> V_38 ( V_29 ) ;
if ( V_30 ) {
if ( ( V_29 -> V_10 >= 4 ) &&
( V_6 -> V_98 ++ < V_99 ) ) {
V_6 -> V_100 = 0 ;
V_30 = F_41 ( V_6 , V_19 ) ;
if ( V_30 )
goto error;
F_10 ( V_29 ) ;
return;
}
F_24 ( L_1 ) ;
goto error;
}
V_6 -> V_100 = 0 ;
V_6 -> V_98 = 0 ;
if ( V_29 -> V_10 > V_6 -> V_31 ) {
V_30 = - V_102 ;
goto exit;
}
V_14 = sizeof( struct V_16 ) ;
V_96 = (struct V_16 * ) V_29 -> V_9 ;
if ( V_29 -> V_10 < V_14 || V_96 -> V_39 != V_40 ||
V_96 -> V_41 != V_103 ) {
V_30 = - V_15 ;
goto error;
}
V_22 = V_96 -> V_22 ;
if ( F_45 ( V_22 ) ) {
F_24 ( L_4 ) ;
V_30 = - V_15 ;
goto error;
}
if ( F_46 ( V_22 ) ) {
V_30 = - V_15 ;
goto exit;
}
if ( V_14 > V_29 -> V_10 ) {
V_30 = - V_15 ;
goto error;
}
F_7 ( V_29 , V_14 ) ;
switch ( F_47 ( V_22 ) ) {
case V_104 :
if ( F_48 ( V_22 ) != V_6 -> V_54 ) {
F_24 ( L_5 ) ;
V_30 = - V_15 ;
goto error;
}
V_6 -> V_54 =
F_48 ( V_6 -> V_54 + 1 ) ;
F_10 ( V_6 -> V_89 ) ;
V_6 -> V_89 = NULL ;
V_29 = F_14 ( V_6 , V_22 , V_29 ,
F_39 ,
V_19 ) ;
if ( F_22 ( V_29 ) ) {
V_30 = F_23 ( V_29 ) ;
V_29 = NULL ;
goto error;
}
if ( ! V_29 )
return;
V_30 = 0 ;
break;
case V_88 :
if ( F_48 ( V_22 ) != V_6 -> V_54 ) {
F_24 ( L_5 ) ;
V_30 = - V_15 ;
goto exit;
}
V_6 -> V_54 =
F_48 ( V_6 -> V_54 + 1 ) ;
if ( V_6 -> V_24 && ! F_49 ( V_22 ) ) {
F_10 ( V_6 -> V_89 ) ;
V_6 -> V_89 = NULL ;
V_30 = F_50 ( V_6 , NULL ,
V_6 -> V_24 ,
V_6 -> V_19 ) ;
if ( V_30 )
goto error;
return;
}
F_51 ( L_6 ) ;
V_30 = - V_67 ;
goto exit;
case V_93 :
if ( ! F_52 ( V_22 ) ) {
V_30 = F_44 ( V_6 , V_19 ) ;
if ( V_30 ) {
F_10 ( V_6 -> V_89 ) ;
goto error;
}
return;
}
F_10 ( V_6 -> V_89 ) ;
V_6 -> V_89 = NULL ;
V_30 = F_43 ( V_6 , V_19 , V_29 -> V_9 [ 0 ] ) ;
if ( V_30 )
goto error;
F_10 ( V_29 ) ;
return;
}
exit:
V_19 -> V_105 ( V_19 -> V_106 , V_29 , V_30 ) ;
error:
F_53 ( V_19 ) ;
F_10 ( V_6 -> V_24 ) ;
V_6 -> V_24 = NULL ;
F_10 ( V_6 -> V_89 ) ;
V_6 -> V_89 = NULL ;
if ( V_30 )
F_10 ( V_29 ) ;
}
int F_50 ( struct V_5 * V_6 ,
struct V_34 * V_35 , struct V_7 * V_8 ,
struct V_18 * V_19 )
{
struct V_16 * V_86 ;
struct V_7 * V_24 , * V_107 ;
int V_30 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_86 = (struct V_16 * ) V_8 -> V_9 ;
V_86 -> V_39 = V_58 ;
V_86 -> V_41 = V_87 ;
V_86 -> V_22 = V_6 -> V_54 ;
V_6 -> V_100 = 0 ;
V_6 -> V_98 = 0 ;
V_24 = V_6 -> V_24 ;
V_107 = F_8 ( V_6 , V_8 , V_86 , V_19 ) ;
if ( F_22 ( V_107 ) )
return F_23 ( V_107 ) ;
F_4 ( V_6 , V_107 ) ;
V_6 -> V_47 ( V_107 ) ;
V_6 -> V_89 = F_40 ( V_107 ) ;
V_6 -> V_90 = V_107 -> V_10 ;
V_30 = F_32 ( V_6 , V_107 , 1500 , V_91 ,
V_19 ) ;
if ( V_30 ) {
if ( V_107 != V_8 )
F_10 ( V_107 ) ;
F_10 ( V_24 ) ;
V_6 -> V_24 = NULL ;
F_10 ( V_6 -> V_89 ) ;
V_6 -> V_89 = NULL ;
}
return V_30 ;
}
static void F_54 ( struct V_5 * V_6 , T_1 V_108 )
{
V_6 -> V_11 = V_108 ;
V_6 -> V_47 = V_109 ;
V_6 -> V_38 = V_110 ;
if ( F_55 ( V_6 ) )
return;
switch ( V_6 -> V_11 ) {
case V_12 :
V_6 -> V_47 = V_111 ;
V_6 -> V_38 = V_112 ;
break;
case V_113 :
case V_44 :
V_6 -> V_47 = V_48 ;
V_6 -> V_38 = V_49 ;
break;
default:
break;
}
}
static int F_56 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
struct V_16 * V_96 ;
struct V_7 * V_8 ;
int V_30 ;
V_8 = F_9 ( V_6 , 1 ) ;
if ( ! V_8 )
return - V_25 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_96 = (struct V_16 * ) V_8 -> V_9 ;
V_96 -> V_39 = V_40 ;
V_96 -> V_41 = V_103 ;
V_96 -> V_22 = V_88 |
V_6 -> V_54 ;
if ( V_6 -> V_60 ) {
V_96 -> V_22 |= V_114 ;
memcpy ( F_13 ( V_8 , sizeof( V_6 -> V_60 ) ) , & V_6 -> V_60 ,
sizeof( V_6 -> V_60 ) ) ;
}
V_6 -> V_54 =
F_48 ( V_6 -> V_54 + 1 ) ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_47 ( V_8 ) ;
V_6 -> V_89 = F_40 ( V_8 ) ;
V_6 -> V_90 = V_8 -> V_10 ;
V_30 = F_57 ( V_6 , V_8 , 1500 , V_115 ,
V_19 ) ;
if ( V_30 ) {
F_10 ( V_8 ) ;
F_10 ( V_6 -> V_89 ) ;
V_6 -> V_89 = NULL ;
}
return V_30 ;
}
static int F_58 ( struct V_5 * V_6 )
{
struct V_16 * V_96 ;
struct V_7 * V_8 ;
int V_30 ;
V_8 = F_9 ( V_6 , 1 ) ;
if ( ! V_8 )
return - V_25 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_96 = (struct V_16 * ) V_8 -> V_9 ;
V_96 -> V_39 = V_40 ;
V_96 -> V_41 = V_103 ;
V_96 -> V_22 = V_93 ;
if ( V_6 -> V_60 ) {
V_96 -> V_22 |= V_114 ;
memcpy ( F_13 ( V_8 , sizeof( V_6 -> V_60 ) ) , & V_6 -> V_60 ,
sizeof( V_6 -> V_60 ) ) ;
}
F_4 ( V_6 , V_8 ) ;
V_6 -> V_47 ( V_8 ) ;
V_30 = F_57 ( V_6 , V_8 , 1500 , V_115 ,
NULL ) ;
if ( V_30 )
F_10 ( V_8 ) ;
return V_30 ;
}
static int F_59 ( struct V_5 * V_6 )
{
F_40 ( V_6 -> V_89 ) ;
F_5 ( V_6 -> V_89 , V_6 -> V_90 ) ;
return F_57 ( V_6 , V_6 -> V_89 , 1500 ,
V_115 , NULL ) ;
}
static void V_115 ( struct V_5 * V_6 , void * V_33 ,
struct V_7 * V_29 )
{
int V_30 ;
struct V_16 * V_86 ;
T_1 V_22 ;
T_3 V_14 ;
if ( F_22 ( V_29 ) ) {
V_30 = F_23 ( V_29 ) ;
V_29 = NULL ;
goto exit;
}
V_30 = V_6 -> V_38 ( V_29 ) ;
if ( V_30 ) {
F_24 ( L_1 ) ;
goto exit;
}
V_30 = F_6 ( V_6 , V_29 ) ;
if ( V_30 ) {
F_24 ( L_2 ) ;
goto exit;
}
if ( V_29 -> V_10 > V_6 -> V_31 ) {
V_30 = - V_102 ;
goto exit;
}
V_14 = sizeof( struct V_16 ) ;
V_86 = (struct V_16 * ) V_29 -> V_9 ;
if ( V_29 -> V_10 < V_14 || V_86 -> V_39 != V_58 ||
V_86 -> V_41 != V_87 ) {
V_30 = - V_15 ;
goto exit;
}
V_22 = V_86 -> V_22 ;
if ( F_45 ( V_22 ) ) {
if ( V_6 -> V_60 && ( V_6 -> V_60 == V_29 -> V_9 [ 3 ] ) ) {
V_14 ++ ;
} else {
V_30 = - V_15 ;
goto exit;
}
} else if ( V_6 -> V_60 ) {
V_30 = - V_15 ;
goto exit;
}
if ( F_46 ( V_22 ) ) {
V_30 = - V_15 ;
goto exit;
}
if ( V_14 > V_29 -> V_10 ) {
V_30 = - V_15 ;
goto exit;
}
F_7 ( V_29 , V_14 ) ;
switch ( F_47 ( V_22 ) ) {
case V_104 :
F_60 ( L_7 ) ;
if ( ( V_6 -> V_100 && ( F_48 ( V_22 - 1 ) !=
V_6 -> V_54 ) ) ||
( F_48 ( V_22 ) != V_6 -> V_54 ) ) {
F_24 ( L_8 ) ;
V_30 = - V_15 ;
goto exit;
}
if ( V_6 -> V_100 ) {
V_6 -> V_100 = 0 ;
V_30 = F_59 ( V_6 ) ;
if ( V_30 )
goto exit;
return;
}
F_10 ( V_6 -> V_89 ) ;
V_6 -> V_89 = NULL ;
V_29 = F_14 ( V_6 , V_22 , V_29 ,
F_56 , NULL ) ;
if ( F_22 ( V_29 ) ) {
V_30 = F_23 ( V_29 ) ;
V_29 = NULL ;
goto exit;
}
if ( ! V_29 )
return;
V_30 = 0 ;
break;
case V_88 :
if ( ! F_49 ( V_22 ) ) {
if ( ( V_6 -> V_100 &&
( F_48 ( V_22 - 1 ) !=
V_6 -> V_54 ) ) ||
( F_48 ( V_22 ) !=
V_6 -> V_54 ) ||
! V_6 -> V_24 || ! V_6 -> V_89 ) {
V_30 = - V_15 ;
goto exit;
}
if ( V_6 -> V_100 ) {
V_6 -> V_100 = 0 ;
V_30 = F_59 ( V_6 ) ;
if ( V_30 )
goto exit;
return;
}
F_10 ( V_6 -> V_89 ) ;
V_6 -> V_89 = NULL ;
V_30 = F_61 ( V_6 , V_6 -> V_24 ) ;
if ( V_30 )
goto exit;
} else {
if ( ( F_48 ( V_22 + 1 ) !=
V_6 -> V_54 ) ||
! V_6 -> V_89 ) {
V_30 = - V_15 ;
goto exit;
}
V_6 -> V_100 = 0 ;
V_30 = F_59 ( V_6 ) ;
if ( V_30 ) {
F_10 ( V_6 -> V_89 ) ;
goto exit;
}
}
return;
case V_93 :
if ( F_52 ( V_22 ) ) {
V_30 = - V_67 ;
goto exit;
}
V_30 = F_58 ( V_6 ) ;
if ( V_30 )
goto exit;
V_6 -> V_100 ++ ;
F_10 ( V_29 ) ;
return;
}
V_30 = F_62 ( V_6 -> V_50 , V_29 ) ;
exit:
F_10 ( V_6 -> V_24 ) ;
V_6 -> V_24 = NULL ;
V_6 -> V_100 = 0 ;
F_10 ( V_6 -> V_89 ) ;
V_6 -> V_89 = NULL ;
if ( V_30 )
F_10 ( V_29 ) ;
}
int F_61 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_16 * V_96 ;
struct V_7 * V_24 , * V_107 ;
int V_30 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_96 = (struct V_16 * ) V_8 -> V_9 ;
V_96 -> V_39 = V_40 ;
V_96 -> V_41 = V_103 ;
V_96 -> V_22 = V_6 -> V_54 ;
if ( V_6 -> V_60 ) {
V_96 -> V_22 |= V_114 ;
memcpy ( F_13 ( V_8 , sizeof( V_6 -> V_60 ) ) , & V_6 -> V_60 ,
sizeof( V_6 -> V_60 ) ) ;
}
V_6 -> V_54 =
F_48 ( V_6 -> V_54 + 1 ) ;
V_24 = V_6 -> V_24 ;
V_107 = F_8 ( V_6 , V_8 , V_96 , NULL ) ;
if ( F_22 ( V_107 ) )
return F_23 ( V_107 ) ;
F_4 ( V_6 , V_107 ) ;
V_6 -> V_47 ( V_107 ) ;
V_6 -> V_89 = F_40 ( V_107 ) ;
V_6 -> V_90 = V_107 -> V_10 ;
V_30 = F_57 ( V_6 , V_107 , 1500 , V_115 ,
NULL ) ;
if ( V_30 ) {
if ( V_107 != V_8 )
F_10 ( V_107 ) ;
F_10 ( V_24 ) ;
V_6 -> V_24 = NULL ;
F_10 ( V_6 -> V_89 ) ;
V_6 -> V_89 = NULL ;
}
return V_30 ;
}
static void F_63 ( struct V_5 * V_6 ,
void * V_33 , struct V_7 * V_29 )
{
T_1 V_108 = ( unsigned long ) V_33 ;
if ( F_22 ( V_29 ) )
return;
F_54 ( V_6 , V_108 ) ;
F_64 ( V_6 , V_43 , V_108 ) ;
F_65 ( V_6 , 1500 , V_115 , NULL ) ;
F_28 ( V_29 ) ;
}
static int F_66 ( struct V_5 * V_6 , T_1 V_60 ,
T_1 V_108 )
{
struct V_36 * V_37 ;
struct V_7 * V_8 ;
int V_30 ;
V_8 = F_9 ( V_6 , sizeof( struct V_36 ) ) ;
if ( ! V_8 )
return - V_25 ;
F_13 ( V_8 , sizeof( struct V_36 ) ) ;
V_37 = (struct V_36 * ) V_8 -> V_9 ;
V_37 -> V_39 = V_40 ;
V_37 -> V_41 = V_42 ;
V_37 -> V_60 = V_60 ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_47 ( V_8 ) ;
V_6 -> V_54 = 0 ;
V_30 = F_57 ( V_6 , V_8 , 0 , F_63 ,
( void * ) ( unsigned long ) V_108 ) ;
if ( V_30 )
F_10 ( V_8 ) ;
return V_30 ;
}
static void F_67 ( struct V_5 * V_6 , void * V_33 ,
struct V_7 * V_29 )
{
int V_30 ;
struct V_56 * V_57 ;
T_1 V_108 ;
T_1 V_116 , V_3 , V_1 ;
if ( F_22 ( V_29 ) ) {
V_30 = F_23 ( V_29 ) ;
V_29 = NULL ;
goto exit;
}
V_30 = V_6 -> V_38 ( V_29 ) ;
if ( V_30 ) {
F_24 ( L_1 ) ;
goto exit;
}
V_30 = F_6 ( V_6 , V_29 ) ;
if ( V_30 ) {
F_24 ( L_2 ) ;
goto exit;
}
V_57 = (struct V_56 * ) V_29 -> V_9 ;
if ( V_29 -> V_10 != sizeof( struct V_56 ) ||
V_57 -> V_39 != V_58 ||
V_57 -> V_41 != V_59 ) {
V_30 = - V_15 ;
goto exit;
}
V_116 = ( V_57 -> V_61 >> 3 ) & 0x07 ;
switch ( V_116 ) {
case 0 :
V_108 = V_12 ;
break;
case 1 :
V_108 = V_113 ;
break;
case 2 :
V_108 = V_44 ;
break;
default:
F_51 ( L_9 , V_116 ) ;
goto exit;
}
V_1 = F_68 ( V_57 -> V_62 ) ;
V_3 = F_1 ( V_1 ) ;
if ( ! V_3 || ( V_3 > F_30 ( V_6 -> V_31 ,
V_6 -> V_21 ) ) ) {
V_30 = - V_67 ;
goto exit;
}
V_6 -> V_31 = V_3 ;
V_6 -> V_21 = V_3 ;
V_30 = F_66 ( V_6 , V_57 -> V_60 , V_108 ) ;
exit:
F_10 ( V_29 ) ;
}
static void F_69 ( struct V_5 * V_6 ,
void * V_33 , struct V_7 * V_29 )
{
int V_117 ;
if ( F_22 ( V_29 ) ) {
F_70 ( V_6 ) ;
return;
}
V_117 = 2 ;
if ( V_29 -> V_9 [ 0 ] == V_13 )
V_117 ++ ;
V_6 -> V_100 = 0 ;
if ( V_29 -> V_9 [ V_117 ] == V_59 )
F_67 ( V_6 , V_33 , V_29 ) ;
else
V_115 ( V_6 , V_33 , V_29 ) ;
}
static int F_71 ( struct V_5 * V_6 ,
struct V_72 * V_73 )
{
struct V_63 * V_64 ;
struct V_7 * V_8 ;
T_1 * V_68 , V_1 ;
T_3 V_65 ;
int V_30 ;
V_68 = F_72 ( V_6 -> V_50 , & V_65 ) ;
if ( ! V_68 )
V_65 = 0 ;
V_8 = F_9 ( V_6 , sizeof( struct V_63 ) + V_65 ) ;
if ( ! V_8 )
return - V_25 ;
F_13 ( V_8 , sizeof( struct V_63 ) ) ;
V_64 = (struct V_63 * ) V_8 -> V_9 ;
memset ( V_64 , 0 , sizeof( struct V_63 ) ) ;
V_64 -> V_39 = V_40 ;
V_64 -> V_41 = V_118 ;
memcpy ( V_64 -> V_78 , V_73 -> V_78 , sizeof( V_73 -> V_78 ) ) ;
V_64 -> V_119 = 8 ;
V_6 -> V_31 = V_84 ;
V_1 = F_3 ( V_6 -> V_31 ) ;
V_64 -> V_66 = F_38 ( V_1 ) ;
if ( V_65 ) {
F_13 ( V_8 , V_65 ) ;
V_64 -> V_66 |= V_85 ;
memcpy ( V_64 -> V_68 , V_68 , V_65 ) ;
}
F_4 ( V_6 , V_8 ) ;
V_6 -> V_47 ( V_8 ) ;
V_6 -> V_54 = 0 ;
V_30 = F_57 ( V_6 , V_8 , 999 ,
F_69 , NULL ) ;
if ( V_30 )
F_10 ( V_8 ) ;
return V_30 ;
}
void F_73 ( struct V_5 * V_6 , void * V_33 ,
struct V_7 * V_29 )
{
int V_30 ;
struct V_72 * V_73 ;
T_3 V_65 , V_120 ;
T_1 V_121 , V_1 ;
if ( F_22 ( V_29 ) ) {
V_30 = F_23 ( V_29 ) ;
V_29 = NULL ;
goto exit;
}
if ( ! V_29 -> V_10 ) {
V_30 = - V_15 ;
goto exit;
}
if ( V_29 -> V_9 [ 0 ] == V_13 ) {
V_120 = V_74 + 2 ;
F_54 ( V_6 , V_12 ) ;
} else {
V_120 = V_74 + 1 ;
F_54 ( V_6 , V_113 ) ;
}
if ( V_29 -> V_10 < V_120 ) {
V_30 = - V_15 ;
goto exit;
}
V_6 -> V_55 = V_122 ;
V_30 = V_6 -> V_38 ( V_29 ) ;
if ( V_30 ) {
F_24 ( L_1 ) ;
goto exit;
}
V_30 = F_6 ( V_6 , V_29 ) ;
if ( V_30 ) {
F_24 ( L_2 ) ;
goto exit;
}
V_73 = (struct V_72 * ) V_29 -> V_9 ;
if ( V_73 -> V_39 != V_58 ||
V_73 -> V_41 != V_76 ||
V_73 -> V_60 > V_123 ) {
V_30 = - V_67 ;
goto exit;
}
V_1 = F_34 ( V_73 -> V_66 ) ;
V_6 -> V_21 = F_1 ( V_1 ) ;
if ( ! V_6 -> V_21 ) {
V_30 = - V_67 ;
goto exit;
}
V_6 -> V_60 = V_73 -> V_60 ;
V_30 = F_64 ( V_6 , V_45 ,
V_124 ) ;
if ( V_30 )
goto exit;
V_30 = F_71 ( V_6 , V_73 ) ;
if ( V_30 )
goto exit;
V_65 = V_29 -> V_10 - sizeof( struct V_72 ) ;
V_121 = V_6 -> V_121 ;
V_6 -> V_121 = 0 ;
V_30 = F_74 ( V_6 -> V_50 , V_122 ,
V_125 , V_73 -> V_68 , V_65 ) ;
if ( V_30 ) {
V_6 -> V_121 = V_121 ;
goto exit;
}
V_30 = 0 ;
exit:
if ( V_30 )
F_70 ( V_6 ) ;
F_28 ( V_29 ) ;
}
