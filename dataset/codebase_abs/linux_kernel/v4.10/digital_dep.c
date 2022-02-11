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
memcpy ( F_12 ( V_20 , V_6 -> V_21 ) , V_8 -> V_9 ,
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
F_13 ( struct V_5 * V_6 , T_1 V_22 ,
struct V_7 * V_26 ,
int (* F_14)( struct V_5 * V_6 ,
struct V_18
* V_19 ) ,
struct V_18 * V_19 )
{
struct V_7 * V_20 ;
int V_27 ;
if ( F_15 ( V_22 ) && ( ! V_6 -> V_24 ) ) {
V_6 -> V_24 =
F_16 ( 8 * V_6 -> V_28 ,
V_29 ) ;
if ( ! V_6 -> V_24 ) {
V_27 = - V_25 ;
goto error;
}
}
if ( V_6 -> V_24 ) {
if ( V_26 -> V_10 > F_17 ( V_6 -> V_24 ) ) {
V_20 = F_18 ( V_6 -> V_24 ,
F_19 (
V_6 -> V_24 ) ,
8 * V_6 -> V_28 ,
V_29 ) ;
if ( ! V_20 ) {
V_27 = - V_25 ;
goto error;
}
F_10 ( V_6 -> V_24 ) ;
V_6 -> V_24 = V_20 ;
}
memcpy ( F_12 ( V_6 -> V_24 , V_26 -> V_10 ) , V_26 -> V_9 ,
V_26 -> V_10 ) ;
F_10 ( V_26 ) ;
V_26 = NULL ;
if ( F_15 ( V_22 ) ) {
V_27 = F_14 ( V_6 , V_19 ) ;
if ( V_27 )
goto error;
return NULL ;
}
V_26 = V_6 -> V_24 ;
V_6 -> V_24 = NULL ;
}
return V_26 ;
error:
F_10 ( V_26 ) ;
F_10 ( V_6 -> V_24 ) ;
V_6 -> V_24 = NULL ;
return F_11 ( V_27 ) ;
}
static void F_20 ( struct V_5 * V_6 , void * V_30 ,
struct V_7 * V_26 )
{
struct V_31 * V_32 = V_30 ;
struct V_33 * V_34 ;
int V_27 ;
if ( F_21 ( V_26 ) ) {
V_27 = F_22 ( V_26 ) ;
V_26 = NULL ;
goto exit;
}
V_27 = V_6 -> V_35 ( V_26 ) ;
if ( V_27 ) {
F_23 ( L_1 ) ;
goto exit;
}
V_27 = F_6 ( V_6 , V_26 ) ;
if ( V_27 ) {
F_23 ( L_2 ) ;
goto exit;
}
V_34 = (struct V_33 * ) V_26 -> V_9 ;
if ( ( V_26 -> V_10 != sizeof( * V_34 ) ) ||
( V_34 -> V_36 != V_37 ) ||
( V_34 -> V_38 != V_39 ) ) {
V_27 = - V_15 ;
goto exit;
}
V_27 = F_24 ( V_6 , V_40 ,
V_41 ) ;
if ( V_27 )
goto exit;
V_27 = F_24 ( V_6 , V_42 ,
V_43 ) ;
if ( V_27 )
goto exit;
if ( ! F_25 ( V_6 ) &&
( V_6 -> V_11 == V_12 ) ) {
V_6 -> V_44 = V_45 ;
V_6 -> V_35 = V_46 ;
}
V_6 -> V_11 = V_41 ;
F_26 ( V_6 -> V_47 , V_32 -> V_48 , V_49 ,
V_50 ) ;
V_6 -> V_51 = 0 ;
exit:
F_27 ( V_26 ) ;
if ( V_27 )
V_6 -> V_52 = 0 ;
}
static int F_28 ( struct V_5 * V_6 ,
struct V_31 * V_32 )
{
struct V_7 * V_8 ;
struct V_53 * V_54 ;
int V_27 ;
T_1 V_3 , V_1 ;
V_8 = F_9 ( V_6 , sizeof( * V_54 ) ) ;
if ( ! V_8 )
return - V_25 ;
F_12 ( V_8 , sizeof( * V_54 ) ) ;
V_54 = (struct V_53 * ) V_8 -> V_9 ;
V_54 -> V_36 = V_55 ;
V_54 -> V_38 = V_56 ;
V_54 -> V_57 = 0 ;
V_54 -> V_58 = ( 0x2 << 3 ) | 0x2 ;
V_3 = F_29 ( V_6 -> V_28 , V_6 -> V_21 ) ;
V_1 = F_3 ( V_3 ) ;
V_54 -> V_59 = F_30 ( V_1 ) ;
V_6 -> V_28 = V_3 ;
V_6 -> V_21 = V_3 ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_44 ( V_8 ) ;
V_27 = F_31 ( V_6 , V_8 , V_6 -> V_60 ,
F_20 , V_32 ) ;
if ( V_27 )
F_10 ( V_8 ) ;
return V_27 ;
}
static void F_32 ( struct V_5 * V_6 , void * V_30 ,
struct V_7 * V_26 )
{
struct V_31 * V_32 = V_30 ;
struct V_61 * V_62 ;
T_1 V_63 , V_1 ;
T_1 V_64 ;
int V_27 ;
if ( F_21 ( V_26 ) ) {
V_27 = F_22 ( V_26 ) ;
V_26 = NULL ;
goto exit;
}
V_27 = V_6 -> V_35 ( V_26 ) ;
if ( V_27 ) {
F_23 ( L_1 ) ;
goto exit;
}
V_27 = F_6 ( V_6 , V_26 ) ;
if ( V_27 ) {
F_23 ( L_2 ) ;
goto exit;
}
if ( V_26 -> V_10 < sizeof( struct V_61 ) ) {
V_27 = - V_15 ;
goto exit;
}
V_63 = V_26 -> V_10 - sizeof( struct V_61 ) ;
V_62 = (struct V_61 * ) V_26 -> V_9 ;
V_64 = F_33 ( V_62 -> V_65 ) ;
if ( V_64 > V_66 )
V_64 = V_66 ;
V_6 -> V_60 = V_67 [ V_64 ] ;
V_1 = F_34 ( V_62 -> V_68 ) ;
V_6 -> V_21 = F_1 ( V_1 ) ;
if ( ! V_6 -> V_21 ) {
V_27 = - V_69 ;
goto exit;
}
V_27 = F_35 ( V_6 -> V_47 , V_62 -> V_70 , V_63 ) ;
if ( V_27 )
goto exit;
if ( ( V_6 -> V_71 & V_72 ) &&
( V_6 -> V_11 != V_41 ) ) {
V_27 = F_28 ( V_6 , V_32 ) ;
if ( ! V_27 )
goto exit;
}
V_27 = F_26 ( V_6 -> V_47 , V_32 -> V_48 , V_49 ,
V_50 ) ;
V_6 -> V_51 = 0 ;
exit:
F_27 ( V_26 ) ;
if ( V_27 )
V_6 -> V_52 = 0 ;
}
int F_36 ( struct V_5 * V_6 ,
struct V_31 * V_32 , T_2 V_73 , T_2 * V_70 ,
T_3 V_63 )
{
struct V_7 * V_8 ;
struct V_74 * V_75 ;
T_4 V_14 ;
int V_27 ;
T_1 V_1 ;
V_14 = V_76 + V_63 ;
if ( V_14 > V_77 ) {
F_23 ( L_3 ) ;
return - V_69 ;
}
V_8 = F_9 ( V_6 , V_14 ) ;
if ( ! V_8 )
return - V_25 ;
F_12 ( V_8 , sizeof( struct V_74 ) ) ;
V_75 = (struct V_74 * ) V_8 -> V_9 ;
memset ( V_75 , 0 , sizeof( struct V_74 ) ) ;
V_75 -> V_36 = V_55 ;
V_75 -> V_38 = V_78 ;
if ( V_32 -> V_79 )
memcpy ( V_75 -> V_80 , V_32 -> V_81 , V_82 ) ;
else
F_37 ( V_75 -> V_80 , V_83 ) ;
V_75 -> V_57 = 0 ;
V_75 -> V_84 = 0 ;
V_75 -> V_85 = 0 ;
V_6 -> V_28 = V_86 ;
V_1 = F_3 ( V_6 -> V_28 ) ;
V_75 -> V_68 = F_38 ( V_1 ) ;
if ( V_63 ) {
V_75 -> V_68 |= V_87 ;
memcpy ( F_12 ( V_8 , V_63 ) , V_70 , V_63 ) ;
}
F_4 ( V_6 , V_8 ) ;
V_6 -> V_44 ( V_8 ) ;
V_27 = F_31 ( V_6 , V_8 , V_88 ,
F_32 , V_32 ) ;
if ( V_27 )
F_10 ( V_8 ) ;
return V_27 ;
}
static int F_39 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
struct V_16 * V_89 ;
struct V_7 * V_8 ;
int V_27 ;
V_8 = F_9 ( V_6 , 1 ) ;
if ( ! V_8 )
return - V_25 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_89 = (struct V_16 * ) V_8 -> V_9 ;
V_89 -> V_36 = V_55 ;
V_89 -> V_38 = V_90 ;
V_89 -> V_22 = V_91 |
V_6 -> V_51 ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_44 ( V_8 ) ;
V_6 -> V_92 = F_40 ( V_8 , V_29 ) ;
V_27 = F_31 ( V_6 , V_8 , V_6 -> V_60 ,
V_93 , V_19 ) ;
if ( V_27 ) {
F_10 ( V_8 ) ;
F_10 ( V_6 -> V_92 ) ;
V_6 -> V_92 = NULL ;
}
return V_27 ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
struct V_16 * V_89 ;
struct V_7 * V_8 ;
int V_27 ;
V_8 = F_9 ( V_6 , 1 ) ;
if ( ! V_8 )
return - V_25 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_89 = (struct V_16 * ) V_8 -> V_9 ;
V_89 -> V_36 = V_55 ;
V_89 -> V_38 = V_90 ;
V_89 -> V_22 = V_91 |
V_94 | V_6 -> V_51 ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_44 ( V_8 ) ;
V_27 = F_31 ( V_6 , V_8 , V_6 -> V_60 ,
V_93 , V_19 ) ;
if ( V_27 )
F_10 ( V_8 ) ;
return V_27 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
struct V_16 * V_89 ;
struct V_7 * V_8 ;
int V_27 ;
V_8 = F_9 ( V_6 , 1 ) ;
if ( ! V_8 )
return - V_25 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_89 = (struct V_16 * ) V_8 -> V_9 ;
V_89 -> V_36 = V_55 ;
V_89 -> V_38 = V_90 ;
V_89 -> V_22 = V_95 ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_44 ( V_8 ) ;
V_27 = F_31 ( V_6 , V_8 , V_6 -> V_60 ,
V_93 , V_19 ) ;
if ( V_27 )
F_10 ( V_8 ) ;
return V_27 ;
}
static int F_43 ( struct V_5 * V_6 ,
struct V_18 * V_19 , T_1 V_96 )
{
struct V_16 * V_89 ;
struct V_7 * V_8 ;
int V_27 ;
T_5 V_97 ;
V_97 = V_6 -> V_60 * V_96 ;
if ( V_97 > V_67 [ V_66 ] )
V_97 = V_67 [ V_66 ] ;
V_8 = F_9 ( V_6 , 1 ) ;
if ( ! V_8 )
return - V_25 ;
* F_12 ( V_8 , 1 ) = V_96 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_89 = (struct V_16 * ) V_8 -> V_9 ;
V_89 -> V_36 = V_55 ;
V_89 -> V_38 = V_90 ;
V_89 -> V_22 = V_95 |
V_98 ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_44 ( V_8 ) ;
V_27 = F_31 ( V_6 , V_8 , V_97 ,
V_93 , V_19 ) ;
if ( V_27 )
F_10 ( V_8 ) ;
return V_27 ;
}
static int F_44 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
int V_27 ;
if ( ! V_6 -> V_92 )
return - V_69 ;
F_45 ( V_6 -> V_92 ) ;
V_27 = F_31 ( V_6 , V_6 -> V_92 , V_6 -> V_60 ,
V_93 , V_19 ) ;
if ( V_27 )
F_10 ( V_6 -> V_92 ) ;
return V_27 ;
}
static void V_93 ( struct V_5 * V_6 , void * V_30 ,
struct V_7 * V_26 )
{
struct V_18 * V_19 = V_30 ;
struct V_16 * V_99 ;
T_1 V_22 ;
T_4 V_14 ;
int V_27 ;
T_1 V_96 ;
if ( F_21 ( V_26 ) ) {
V_27 = F_22 ( V_26 ) ;
V_26 = NULL ;
if ( ( V_27 == - V_15 || ( V_27 == - V_100 && V_6 -> V_101 ) ) &&
( V_6 -> V_101 ++ < V_102 ) ) {
V_6 -> V_103 = 0 ;
V_27 = F_41 ( V_6 , V_19 ) ;
if ( V_27 )
goto error;
return;
} else if ( ( V_27 == - V_100 ) &&
( V_6 -> V_103 ++ < V_104 ) ) {
V_6 -> V_101 = 0 ;
V_27 = F_42 ( V_6 , V_19 ) ;
if ( V_27 )
goto error;
return;
}
goto exit;
}
V_27 = F_6 ( V_6 , V_26 ) ;
if ( V_27 ) {
F_23 ( L_2 ) ;
goto exit;
}
V_27 = V_6 -> V_35 ( V_26 ) ;
if ( V_27 ) {
if ( ( V_26 -> V_10 >= 4 ) &&
( V_6 -> V_101 ++ < V_102 ) ) {
V_6 -> V_103 = 0 ;
V_27 = F_41 ( V_6 , V_19 ) ;
if ( V_27 )
goto error;
F_10 ( V_26 ) ;
return;
}
F_23 ( L_1 ) ;
goto error;
}
V_6 -> V_103 = 0 ;
V_6 -> V_101 = 0 ;
if ( V_26 -> V_10 > V_6 -> V_28 ) {
V_27 = - V_105 ;
goto exit;
}
V_14 = sizeof( struct V_16 ) ;
V_99 = (struct V_16 * ) V_26 -> V_9 ;
if ( V_26 -> V_10 < V_14 || V_99 -> V_36 != V_37 ||
V_99 -> V_38 != V_106 ) {
V_27 = - V_15 ;
goto error;
}
V_22 = V_99 -> V_22 ;
if ( F_46 ( V_22 ) ) {
F_23 ( L_4 ) ;
V_27 = - V_15 ;
goto error;
}
if ( F_47 ( V_22 ) ) {
V_27 = - V_15 ;
goto exit;
}
if ( V_14 > V_26 -> V_10 ) {
V_27 = - V_15 ;
goto error;
}
F_7 ( V_26 , V_14 ) ;
switch ( F_48 ( V_22 ) ) {
case V_107 :
if ( F_49 ( V_22 ) != V_6 -> V_51 ) {
F_23 ( L_5 ) ;
V_27 = - V_15 ;
goto error;
}
V_6 -> V_51 =
F_49 ( V_6 -> V_51 + 1 ) ;
F_10 ( V_6 -> V_92 ) ;
V_6 -> V_92 = NULL ;
V_26 = F_13 ( V_6 , V_22 , V_26 ,
F_39 ,
V_19 ) ;
if ( F_21 ( V_26 ) ) {
V_27 = F_22 ( V_26 ) ;
V_26 = NULL ;
goto error;
}
if ( ! V_26 )
return;
V_27 = 0 ;
break;
case V_91 :
if ( F_50 ( V_22 ) ) {
F_23 ( L_6 ) ;
V_27 = - V_15 ;
goto exit;
}
if ( F_49 ( V_22 ) != V_6 -> V_51 ) {
F_23 ( L_5 ) ;
V_27 = - V_15 ;
goto exit;
}
V_6 -> V_51 =
F_49 ( V_6 -> V_51 + 1 ) ;
if ( ! V_6 -> V_24 ) {
F_23 ( L_7 ) ;
V_27 = - V_15 ;
goto exit;
}
F_10 ( V_6 -> V_92 ) ;
V_6 -> V_92 = NULL ;
V_27 = F_51 ( V_6 , NULL ,
V_6 -> V_24 ,
V_6 -> V_19 ) ;
if ( V_27 )
goto error;
goto V_108;
case V_95 :
if ( ! F_52 ( V_22 ) ) {
V_27 = F_44 ( V_6 , V_19 ) ;
if ( V_27 )
goto error;
goto V_108;
}
if ( V_6 -> V_103 || V_6 -> V_101 ) {
F_23 ( L_8 ) ;
V_27 = - V_15 ;
goto error;
}
V_96 = F_53 ( V_26 -> V_9 [ 0 ] ) ;
if ( ! V_96 || V_96 > V_109 ) {
F_23 ( L_9 ) ;
V_27 = - V_15 ;
goto error;
}
V_27 = F_43 ( V_6 , V_19 , V_96 ) ;
if ( V_27 )
goto error;
goto V_108;
}
exit:
V_19 -> V_110 ( V_19 -> V_111 , V_26 , V_27 ) ;
error:
F_54 ( V_19 ) ;
F_10 ( V_6 -> V_24 ) ;
V_6 -> V_24 = NULL ;
F_10 ( V_6 -> V_92 ) ;
V_6 -> V_92 = NULL ;
if ( V_27 )
F_10 ( V_26 ) ;
return;
V_108:
F_27 ( V_26 ) ;
}
int F_51 ( struct V_5 * V_6 ,
struct V_31 * V_32 , struct V_7 * V_8 ,
struct V_18 * V_19 )
{
struct V_16 * V_89 ;
struct V_7 * V_24 , * V_112 ;
int V_27 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_89 = (struct V_16 * ) V_8 -> V_9 ;
V_89 -> V_36 = V_55 ;
V_89 -> V_38 = V_90 ;
V_89 -> V_22 = V_6 -> V_51 ;
V_6 -> V_103 = 0 ;
V_6 -> V_101 = 0 ;
V_24 = V_6 -> V_24 ;
V_112 = F_8 ( V_6 , V_8 , V_89 , V_19 ) ;
if ( F_21 ( V_112 ) )
return F_22 ( V_112 ) ;
F_4 ( V_6 , V_112 ) ;
V_6 -> V_44 ( V_112 ) ;
V_6 -> V_92 = F_40 ( V_112 , V_29 ) ;
V_27 = F_31 ( V_6 , V_112 , V_6 -> V_60 ,
V_93 , V_19 ) ;
if ( V_27 ) {
if ( V_112 != V_8 )
F_10 ( V_112 ) ;
F_10 ( V_24 ) ;
V_6 -> V_24 = NULL ;
F_10 ( V_6 -> V_92 ) ;
V_6 -> V_92 = NULL ;
}
return V_27 ;
}
static void F_55 ( struct V_5 * V_6 , T_1 V_113 )
{
V_6 -> V_11 = V_113 ;
V_6 -> V_44 = V_114 ;
V_6 -> V_35 = V_115 ;
if ( F_56 ( V_6 ) )
return;
switch ( V_6 -> V_11 ) {
case V_12 :
V_6 -> V_44 = V_116 ;
V_6 -> V_35 = V_117 ;
break;
case V_118 :
case V_41 :
V_6 -> V_44 = V_45 ;
V_6 -> V_35 = V_46 ;
break;
default:
break;
}
}
static int F_57 ( struct V_5 * V_6 ,
struct V_18 * V_19 )
{
struct V_16 * V_99 ;
struct V_7 * V_8 ;
int V_27 ;
V_8 = F_9 ( V_6 , 1 ) ;
if ( ! V_8 )
return - V_25 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_99 = (struct V_16 * ) V_8 -> V_9 ;
V_99 -> V_36 = V_37 ;
V_99 -> V_38 = V_106 ;
V_99 -> V_22 = V_91 |
V_6 -> V_51 ;
if ( V_6 -> V_57 ) {
V_99 -> V_22 |= V_119 ;
memcpy ( F_12 ( V_8 , sizeof( V_6 -> V_57 ) ) , & V_6 -> V_57 ,
sizeof( V_6 -> V_57 ) ) ;
}
V_6 -> V_51 =
F_49 ( V_6 -> V_51 + 1 ) ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_44 ( V_8 ) ;
V_6 -> V_92 = F_40 ( V_8 , V_29 ) ;
V_27 = F_58 ( V_6 , V_8 , 1500 , V_120 ,
V_19 ) ;
if ( V_27 ) {
F_10 ( V_8 ) ;
F_10 ( V_6 -> V_92 ) ;
V_6 -> V_92 = NULL ;
}
return V_27 ;
}
static int F_59 ( struct V_5 * V_6 )
{
struct V_16 * V_99 ;
struct V_7 * V_8 ;
int V_27 ;
V_8 = F_9 ( V_6 , 1 ) ;
if ( ! V_8 )
return - V_25 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_99 = (struct V_16 * ) V_8 -> V_9 ;
V_99 -> V_36 = V_37 ;
V_99 -> V_38 = V_106 ;
V_99 -> V_22 = V_95 ;
if ( V_6 -> V_57 ) {
V_99 -> V_22 |= V_119 ;
memcpy ( F_12 ( V_8 , sizeof( V_6 -> V_57 ) ) , & V_6 -> V_57 ,
sizeof( V_6 -> V_57 ) ) ;
}
F_4 ( V_6 , V_8 ) ;
V_6 -> V_44 ( V_8 ) ;
V_27 = F_58 ( V_6 , V_8 , 1500 , V_120 ,
NULL ) ;
if ( V_27 )
F_10 ( V_8 ) ;
return V_27 ;
}
static int F_60 ( struct V_5 * V_6 )
{
int V_27 ;
if ( ! V_6 -> V_92 )
return - V_69 ;
F_45 ( V_6 -> V_92 ) ;
V_27 = F_58 ( V_6 , V_6 -> V_92 , 1500 ,
V_120 , NULL ) ;
if ( V_27 )
F_10 ( V_6 -> V_92 ) ;
return V_27 ;
}
static void V_120 ( struct V_5 * V_6 , void * V_30 ,
struct V_7 * V_26 )
{
int V_27 ;
struct V_16 * V_89 ;
T_1 V_22 ;
T_3 V_14 ;
if ( F_21 ( V_26 ) ) {
V_27 = F_22 ( V_26 ) ;
V_26 = NULL ;
goto exit;
}
V_27 = V_6 -> V_35 ( V_26 ) ;
if ( V_27 ) {
F_23 ( L_1 ) ;
goto exit;
}
V_27 = F_6 ( V_6 , V_26 ) ;
if ( V_27 ) {
F_23 ( L_2 ) ;
goto exit;
}
if ( V_26 -> V_10 > V_6 -> V_28 ) {
V_27 = - V_105 ;
goto exit;
}
V_14 = sizeof( struct V_16 ) ;
V_89 = (struct V_16 * ) V_26 -> V_9 ;
if ( V_26 -> V_10 < V_14 || V_89 -> V_36 != V_55 ||
V_89 -> V_38 != V_90 ) {
V_27 = - V_15 ;
goto exit;
}
V_22 = V_89 -> V_22 ;
if ( F_46 ( V_22 ) ) {
if ( V_6 -> V_57 && ( V_6 -> V_57 == V_26 -> V_9 [ 3 ] ) ) {
V_14 ++ ;
} else {
V_27 = - V_15 ;
goto exit;
}
} else if ( V_6 -> V_57 ) {
V_27 = - V_15 ;
goto exit;
}
if ( F_47 ( V_22 ) ) {
V_27 = - V_15 ;
goto exit;
}
if ( V_14 > V_26 -> V_10 ) {
V_27 = - V_15 ;
goto exit;
}
F_7 ( V_26 , V_14 ) ;
switch ( F_48 ( V_22 ) ) {
case V_107 :
F_61 ( L_10 ) ;
if ( V_6 -> V_103 ) {
V_6 -> V_103 = 0 ;
if ( F_49 ( V_22 ) ==
F_49 ( V_6 -> V_51 - 1 ) ) {
V_27 = F_60 ( V_6 ) ;
if ( V_27 )
goto exit;
goto V_108;
}
}
if ( F_49 ( V_22 ) != V_6 -> V_51 ) {
F_23 ( L_11 ) ;
V_27 = - V_15 ;
goto exit;
}
F_10 ( V_6 -> V_92 ) ;
V_6 -> V_92 = NULL ;
V_26 = F_13 ( V_6 , V_22 , V_26 ,
F_57 , NULL ) ;
if ( F_21 ( V_26 ) ) {
V_27 = F_22 ( V_26 ) ;
V_26 = NULL ;
goto exit;
}
if ( ! V_26 )
return;
V_27 = 0 ;
break;
case V_91 :
if ( F_50 ( V_22 ) ) {
if ( F_49 ( V_22 + 1 ) !=
V_6 -> V_51 ) {
V_27 = - V_15 ;
goto exit;
}
V_6 -> V_103 = 0 ;
V_27 = F_60 ( V_6 ) ;
if ( V_27 )
goto exit;
goto V_108;
}
if ( V_6 -> V_103 ) {
V_6 -> V_103 = 0 ;
if ( F_49 ( V_22 + 1 ) ==
V_6 -> V_51 ) {
V_27 = F_60 ( V_6 ) ;
if ( V_27 )
goto exit;
goto V_108;
}
}
if ( ! V_6 -> V_24 ||
F_49 ( V_22 ) !=
V_6 -> V_51 ) {
V_27 = - V_15 ;
goto exit;
}
F_10 ( V_6 -> V_92 ) ;
V_6 -> V_92 = NULL ;
V_27 = F_62 ( V_6 , V_6 -> V_24 ) ;
if ( V_27 )
goto exit;
goto V_108;
case V_95 :
if ( F_52 ( V_22 ) ) {
V_27 = - V_69 ;
goto exit;
}
V_27 = F_59 ( V_6 ) ;
if ( V_27 )
goto exit;
V_6 -> V_103 ++ ;
goto V_108;
}
V_27 = F_63 ( V_6 -> V_47 , V_26 ) ;
exit:
F_10 ( V_6 -> V_24 ) ;
V_6 -> V_24 = NULL ;
V_6 -> V_103 = 0 ;
F_10 ( V_6 -> V_92 ) ;
V_6 -> V_92 = NULL ;
if ( V_27 )
F_10 ( V_26 ) ;
return;
V_108:
F_27 ( V_26 ) ;
}
int F_62 ( struct V_5 * V_6 , struct V_7 * V_8 )
{
struct V_16 * V_99 ;
struct V_7 * V_24 , * V_112 ;
int V_27 ;
F_5 ( V_8 , sizeof( struct V_16 ) ) ;
V_99 = (struct V_16 * ) V_8 -> V_9 ;
V_99 -> V_36 = V_37 ;
V_99 -> V_38 = V_106 ;
V_99 -> V_22 = V_6 -> V_51 ;
if ( V_6 -> V_57 ) {
V_99 -> V_22 |= V_119 ;
memcpy ( F_12 ( V_8 , sizeof( V_6 -> V_57 ) ) , & V_6 -> V_57 ,
sizeof( V_6 -> V_57 ) ) ;
}
V_6 -> V_51 =
F_49 ( V_6 -> V_51 + 1 ) ;
V_24 = V_6 -> V_24 ;
V_112 = F_8 ( V_6 , V_8 , V_99 , NULL ) ;
if ( F_21 ( V_112 ) )
return F_22 ( V_112 ) ;
F_4 ( V_6 , V_112 ) ;
V_6 -> V_44 ( V_112 ) ;
V_6 -> V_92 = F_40 ( V_112 , V_29 ) ;
V_27 = F_58 ( V_6 , V_112 , 1500 , V_120 ,
NULL ) ;
if ( V_27 ) {
if ( V_112 != V_8 )
F_10 ( V_112 ) ;
F_10 ( V_24 ) ;
V_6 -> V_24 = NULL ;
F_10 ( V_6 -> V_92 ) ;
V_6 -> V_92 = NULL ;
}
return V_27 ;
}
static void F_64 ( struct V_5 * V_6 ,
void * V_30 , struct V_7 * V_26 )
{
T_1 V_113 = ( unsigned long ) V_30 ;
if ( F_21 ( V_26 ) )
return;
F_55 ( V_6 , V_113 ) ;
F_65 ( V_6 , V_40 , V_113 ) ;
F_66 ( V_6 , 1500 , V_120 , NULL ) ;
F_27 ( V_26 ) ;
}
static int F_67 ( struct V_5 * V_6 , T_1 V_57 ,
T_1 V_113 )
{
struct V_33 * V_34 ;
struct V_7 * V_8 ;
int V_27 ;
V_8 = F_9 ( V_6 , sizeof( struct V_33 ) ) ;
if ( ! V_8 )
return - V_25 ;
F_12 ( V_8 , sizeof( struct V_33 ) ) ;
V_34 = (struct V_33 * ) V_8 -> V_9 ;
V_34 -> V_36 = V_37 ;
V_34 -> V_38 = V_39 ;
V_34 -> V_57 = V_57 ;
F_4 ( V_6 , V_8 ) ;
V_6 -> V_44 ( V_8 ) ;
V_6 -> V_51 = 0 ;
V_27 = F_58 ( V_6 , V_8 , 0 , F_64 ,
( void * ) ( unsigned long ) V_113 ) ;
if ( V_27 )
F_10 ( V_8 ) ;
return V_27 ;
}
static void F_68 ( struct V_5 * V_6 , void * V_30 ,
struct V_7 * V_26 )
{
int V_27 ;
struct V_53 * V_54 ;
T_1 V_113 ;
T_1 V_121 , V_3 , V_1 ;
if ( F_21 ( V_26 ) ) {
V_27 = F_22 ( V_26 ) ;
V_26 = NULL ;
goto exit;
}
V_27 = V_6 -> V_35 ( V_26 ) ;
if ( V_27 ) {
F_23 ( L_1 ) ;
goto exit;
}
V_27 = F_6 ( V_6 , V_26 ) ;
if ( V_27 ) {
F_23 ( L_2 ) ;
goto exit;
}
V_54 = (struct V_53 * ) V_26 -> V_9 ;
if ( V_26 -> V_10 != sizeof( struct V_53 ) ||
V_54 -> V_36 != V_55 ||
V_54 -> V_38 != V_56 ) {
V_27 = - V_15 ;
goto exit;
}
V_121 = ( V_54 -> V_58 >> 3 ) & 0x07 ;
switch ( V_121 ) {
case 0 :
V_113 = V_12 ;
break;
case 1 :
V_113 = V_118 ;
break;
case 2 :
V_113 = V_41 ;
break;
default:
F_69 ( L_12 , V_121 ) ;
goto exit;
}
V_1 = F_70 ( V_54 -> V_59 ) ;
V_3 = F_1 ( V_1 ) ;
if ( ! V_3 || ( V_3 > F_29 ( V_6 -> V_28 ,
V_6 -> V_21 ) ) ) {
V_27 = - V_69 ;
goto exit;
}
V_6 -> V_28 = V_3 ;
V_6 -> V_21 = V_3 ;
V_27 = F_67 ( V_6 , V_54 -> V_57 , V_113 ) ;
exit:
F_10 ( V_26 ) ;
}
static void F_71 ( struct V_5 * V_6 ,
void * V_30 , struct V_7 * V_26 )
{
int V_122 ;
if ( F_21 ( V_26 ) ) {
F_72 ( V_6 ) ;
return;
}
V_122 = 2 ;
if ( V_26 -> V_9 [ 0 ] == V_13 )
V_122 ++ ;
V_6 -> V_103 = 0 ;
if ( V_26 -> V_9 [ V_122 ] == V_56 )
F_68 ( V_6 , V_30 , V_26 ) ;
else
V_120 ( V_6 , V_30 , V_26 ) ;
}
static int F_73 ( struct V_5 * V_6 ,
struct V_74 * V_75 )
{
struct V_61 * V_62 ;
struct V_7 * V_8 ;
T_1 * V_70 , V_1 ;
T_3 V_63 ;
int V_27 ;
V_70 = F_74 ( V_6 -> V_47 , & V_63 ) ;
if ( ! V_70 )
V_63 = 0 ;
V_8 = F_9 ( V_6 , sizeof( struct V_61 ) + V_63 ) ;
if ( ! V_8 )
return - V_25 ;
F_12 ( V_8 , sizeof( struct V_61 ) ) ;
V_62 = (struct V_61 * ) V_8 -> V_9 ;
memset ( V_62 , 0 , sizeof( struct V_61 ) ) ;
V_62 -> V_36 = V_37 ;
V_62 -> V_38 = V_123 ;
memcpy ( V_62 -> V_80 , V_75 -> V_80 , sizeof( V_75 -> V_80 ) ) ;
V_62 -> V_65 = V_124 ;
V_6 -> V_28 = V_86 ;
V_1 = F_3 ( V_6 -> V_28 ) ;
V_62 -> V_68 = F_38 ( V_1 ) ;
if ( V_63 ) {
F_12 ( V_8 , V_63 ) ;
V_62 -> V_68 |= V_87 ;
memcpy ( V_62 -> V_70 , V_70 , V_63 ) ;
}
F_4 ( V_6 , V_8 ) ;
V_6 -> V_44 ( V_8 ) ;
V_6 -> V_51 = 0 ;
V_27 = F_58 ( V_6 , V_8 , 999 ,
F_71 , NULL ) ;
if ( V_27 )
F_10 ( V_8 ) ;
return V_27 ;
}
void F_75 ( struct V_5 * V_6 , void * V_30 ,
struct V_7 * V_26 )
{
int V_27 ;
struct V_74 * V_75 ;
T_3 V_63 , V_125 ;
T_1 V_126 , V_1 ;
if ( F_21 ( V_26 ) ) {
V_27 = F_22 ( V_26 ) ;
V_26 = NULL ;
goto exit;
}
if ( ! V_26 -> V_10 ) {
V_27 = - V_15 ;
goto exit;
}
if ( V_26 -> V_9 [ 0 ] == V_13 ) {
V_125 = V_76 + 2 ;
F_55 ( V_6 , V_12 ) ;
} else {
V_125 = V_76 + 1 ;
F_55 ( V_6 , V_118 ) ;
}
if ( V_26 -> V_10 < V_125 ) {
V_27 = - V_15 ;
goto exit;
}
V_6 -> V_52 = V_127 ;
V_27 = V_6 -> V_35 ( V_26 ) ;
if ( V_27 ) {
F_23 ( L_1 ) ;
goto exit;
}
V_27 = F_6 ( V_6 , V_26 ) ;
if ( V_27 ) {
F_23 ( L_2 ) ;
goto exit;
}
V_75 = (struct V_74 * ) V_26 -> V_9 ;
if ( V_75 -> V_36 != V_55 ||
V_75 -> V_38 != V_78 ||
V_75 -> V_57 > V_128 ) {
V_27 = - V_69 ;
goto exit;
}
V_1 = F_34 ( V_75 -> V_68 ) ;
V_6 -> V_21 = F_1 ( V_1 ) ;
if ( ! V_6 -> V_21 ) {
V_27 = - V_69 ;
goto exit;
}
V_6 -> V_57 = V_75 -> V_57 ;
V_27 = F_65 ( V_6 , V_42 ,
V_129 ) ;
if ( V_27 )
goto exit;
V_27 = F_73 ( V_6 , V_75 ) ;
if ( V_27 )
goto exit;
V_63 = V_26 -> V_10 - sizeof( struct V_74 ) ;
V_126 = V_6 -> V_126 ;
V_6 -> V_126 = 0 ;
V_27 = F_76 ( V_6 -> V_47 , V_127 ,
V_130 , V_75 -> V_70 , V_63 ) ;
if ( V_27 ) {
V_6 -> V_126 = V_126 ;
goto exit;
}
V_27 = 0 ;
exit:
if ( V_27 )
F_72 ( V_6 ) ;
F_27 ( V_26 ) ;
}
