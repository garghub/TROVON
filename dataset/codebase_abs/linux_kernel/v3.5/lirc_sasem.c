static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 -> V_6 ) ;
F_4 ( V_2 -> V_5 -> V_6 ) ;
F_4 ( V_2 -> V_5 ) ;
F_4 ( V_2 ) ;
if ( V_7 )
F_5 ( V_8 L_1 , V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_10 ;
int V_11 = V_2 -> V_5 -> V_11 ;
V_10 = F_7 ( V_11 ) ;
if ( V_10 )
F_5 ( V_12 L_2 ,
V_9 , V_10 ) ;
else
F_5 ( V_8 L_3 ,
V_11 ) ;
}
static int F_8 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
struct V_15 * V_16 ;
struct V_1 * V_2 = NULL ;
int V_17 ;
int V_10 = 0 ;
F_9 ( & V_18 ) ;
V_17 = F_10 ( V_13 ) ;
V_16 = F_11 ( & V_19 , V_17 ) ;
if ( ! V_16 ) {
F_5 (KERN_ERR KBUILD_MODNAME
L_4 ,
__func__, subminor) ;
V_10 = - V_20 ;
goto exit;
}
V_2 = F_12 ( V_16 ) ;
if ( ! V_2 ) {
F_13 ( & V_16 -> V_21 ,
L_5 ,
V_9 , V_17 ) ;
V_10 = - V_20 ;
goto exit;
}
F_9 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_23 ) {
F_13 ( & V_16 -> V_21 ,
L_6 , V_9 ) ;
V_10 = - V_24 ;
} else {
V_2 -> V_23 = 1 ;
V_14 -> V_25 = V_2 ;
F_14 ( & V_16 -> V_21 , L_7 ) ;
}
F_15 ( & V_2 -> V_22 ) ;
exit:
F_15 ( & V_18 ) ;
return V_10 ;
}
static long F_16 ( struct V_14 * V_14 , unsigned V_26 , unsigned long V_27 )
{
struct V_1 * V_2 = NULL ;
V_2 = (struct V_1 * ) V_14 -> V_25 ;
if ( ! V_2 ) {
F_5 (KERN_ERR KBUILD_MODNAME
L_8 , __func__) ;
return - V_20 ;
}
F_9 ( & V_2 -> V_22 ) ;
switch ( V_26 ) {
case V_28 :
if ( V_27 > 1000 )
V_27 = 1000 ;
V_2 -> V_29 = ( unsigned int ) V_27 ;
break;
default:
F_5 ( V_8 L_9 ) ;
F_15 ( & V_2 -> V_22 ) ;
return - V_30 ;
}
F_15 ( & V_2 -> V_22 ) ;
return 0 ;
}
static int F_17 ( struct V_13 * V_13 , struct V_14 * V_14 )
{
struct V_1 * V_2 = NULL ;
int V_10 = 0 ;
V_2 = (struct V_1 * ) V_14 -> V_25 ;
if ( ! V_2 ) {
F_5 (KERN_ERR KBUILD_MODNAME
L_8 , __func__) ;
return - V_20 ;
}
F_9 ( & V_2 -> V_22 ) ;
if ( ! V_2 -> V_23 ) {
F_13 ( & V_2 -> V_21 -> V_21 , L_10 , V_9 ) ;
V_10 = - V_31 ;
} else {
V_2 -> V_23 = 0 ;
F_5 ( V_8 L_11 ) ;
if ( ! V_2 -> V_32 && ! V_2 -> V_33 ) {
F_15 ( & V_2 -> V_22 ) ;
F_1 ( V_2 ) ;
return V_10 ;
}
}
F_15 ( & V_2 -> V_22 ) ;
return V_10 ;
}
static int F_18 ( struct V_1 * V_2 )
{
unsigned int V_34 ;
int V_35 = 0 ;
int V_10 = 0 ;
V_34 = F_19 ( V_2 -> V_21 ,
V_2 -> V_36 -> V_37 ) ;
V_35 = V_2 -> V_36 -> V_38 ;
F_20 ( V_2 -> V_3 , V_2 -> V_21 , V_34 ,
V_2 -> V_39 , sizeof( V_2 -> V_39 ) ,
V_40 , V_2 , V_35 ) ;
V_2 -> V_3 -> V_41 = 0 ;
F_21 ( & V_2 -> V_42 . V_43 ) ;
F_22 ( & ( V_2 -> V_42 . V_44 ) , 1 ) ;
V_10 = F_23 ( V_2 -> V_3 , V_45 ) ;
if ( V_10 ) {
F_22 ( & ( V_2 -> V_42 . V_44 ) , 0 ) ;
F_13 ( & V_2 -> V_21 -> V_21 , L_12 ,
V_9 , V_10 ) ;
} else {
F_15 ( & V_2 -> V_22 ) ;
F_24 ( & V_2 -> V_42 . V_43 ) ;
F_9 ( & V_2 -> V_22 ) ;
V_10 = V_2 -> V_42 . V_46 ;
if ( V_10 )
F_13 ( & V_2 -> V_21 -> V_21 ,
L_13 ,
V_9 , V_10 ) ;
}
return V_10 ;
}
static T_1 F_25 ( struct V_14 * V_14 , const char * V_47 ,
T_2 V_48 , T_3 * V_49 )
{
int V_50 ;
int V_10 = 0 ;
struct V_1 * V_2 ;
int * V_51 = NULL ;
V_2 = (struct V_1 * ) V_14 -> V_25 ;
if ( ! V_2 ) {
F_5 (KERN_ERR KBUILD_MODNAME
L_8 , __func__) ;
return - V_20 ;
}
F_9 ( & V_2 -> V_22 ) ;
if ( ! V_2 -> V_32 ) {
F_5 (KERN_ERR KBUILD_MODNAME
L_14 , __func__) ;
V_10 = - V_20 ;
goto exit;
}
if ( V_48 <= 0 || V_48 > V_52 ) {
F_13 ( & V_2 -> V_21 -> V_21 , L_15 ,
V_9 ) ;
V_10 = - V_53 ;
goto exit;
}
V_51 = F_26 ( V_47 , V_48 ) ;
if ( F_27 ( V_51 ) ) {
V_10 = F_28 ( V_51 ) ;
goto exit;
}
memcpy ( V_2 -> V_42 . V_51 , V_51 , V_48 ) ;
for ( V_50 = V_48 ; V_50 < V_52 ; ++ V_50 )
V_2 -> V_42 . V_51 [ V_50 ] = ' ' ;
for ( V_50 = 0 ; V_50 < 9 ; V_50 ++ ) {
switch ( V_50 ) {
case 0 :
memcpy ( V_2 -> V_39 , L_16 , 8 ) ;
V_2 -> V_39 [ 1 ] = ( V_2 -> V_29 ) ?
( 0x2B - ( V_2 -> V_29 - 1 ) / 250 )
: 0x2B ;
break;
case 1 :
memcpy ( V_2 -> V_39 , L_17 , 8 ) ;
break;
case 2 :
memcpy ( V_2 -> V_39 , L_18 , 8 ) ;
break;
case 3 :
memcpy ( V_2 -> V_39 , V_2 -> V_42 . V_51 , 8 ) ;
break;
case 4 :
memcpy ( V_2 -> V_39 ,
V_2 -> V_42 . V_51 + 8 , 8 ) ;
break;
case 5 :
memcpy ( V_2 -> V_39 , L_17 , 8 ) ;
break;
case 6 :
memcpy ( V_2 -> V_39 , L_19 , 8 ) ;
break;
case 7 :
memcpy ( V_2 -> V_39 ,
V_2 -> V_42 . V_51 + 16 , 8 ) ;
break;
case 8 :
memcpy ( V_2 -> V_39 ,
V_2 -> V_42 . V_51 + 24 , 8 ) ;
break;
}
V_10 = F_18 ( V_2 ) ;
if ( V_10 ) {
F_13 ( & V_2 -> V_21 -> V_21 ,
L_20 ,
V_9 , V_50 ) ;
goto exit;
}
}
exit:
F_15 ( & V_2 -> V_22 ) ;
F_4 ( V_51 ) ;
return ( ! V_10 ) ? V_48 : V_10 ;
}
static void V_40 ( struct V_54 * V_54 )
{
struct V_1 * V_2 ;
if ( ! V_54 )
return;
V_2 = (struct V_1 * ) V_54 -> V_2 ;
if ( ! V_2 )
return;
V_2 -> V_42 . V_46 = V_54 -> V_46 ;
F_22 ( & V_2 -> V_42 . V_44 , 0 ) ;
F_29 ( & V_2 -> V_42 . V_43 ) ;
return;
}
static int F_30 ( void * V_55 )
{
int V_10 = 0 ;
struct V_1 * V_2 ;
F_9 ( & V_18 ) ;
V_2 = (struct V_1 * ) V_55 ;
F_9 ( & V_2 -> V_22 ) ;
if ( V_2 -> V_33 ) {
F_13 ( & V_2 -> V_21 -> V_21 , L_21 ,
V_9 ) ;
V_10 = - V_24 ;
goto exit;
}
F_20 ( V_2 -> V_4 , V_2 -> V_21 ,
F_31 ( V_2 -> V_21 ,
V_2 -> V_56 -> V_37 ) ,
V_2 -> V_57 , sizeof( V_2 -> V_57 ) ,
V_58 , V_2 , V_2 -> V_56 -> V_38 ) ;
V_10 = F_23 ( V_2 -> V_4 , V_45 ) ;
if ( V_10 )
F_13 ( & V_2 -> V_21 -> V_21 ,
L_22 ,
V_9 , V_10 ) ;
else {
V_2 -> V_33 = 1 ;
F_5 ( V_8 L_23 ) ;
}
exit:
F_15 ( & V_2 -> V_22 ) ;
F_15 ( & V_18 ) ;
return V_10 ;
}
static void F_32 ( void * V_55 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_55 ;
if ( ! V_2 ) {
F_5 (KERN_ERR KBUILD_MODNAME
L_8 , __func__) ;
return;
}
F_9 ( & V_2 -> V_22 ) ;
F_33 ( V_2 -> V_4 ) ;
V_2 -> V_33 = 0 ;
F_5 ( V_8 L_24 ) ;
if ( ! V_2 -> V_32 ) {
F_6 ( V_2 ) ;
if ( ! V_2 -> V_23 ) {
F_15 ( & V_2 -> V_22 ) ;
F_1 ( V_2 ) ;
return;
}
}
F_15 ( & V_2 -> V_22 ) ;
return;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_54 * V_54 )
{
int V_59 = V_54 -> V_41 ;
unsigned char * V_47 = V_54 -> V_60 ;
long V_61 ;
struct V_62 V_63 ;
int V_50 ;
if ( V_59 != 8 ) {
F_5 ( V_64 L_25 ,
V_9 , V_59 ) ;
return;
}
if ( V_7 ) {
F_5 ( V_8 L_26 ) ;
for ( V_50 = 0 ; V_50 < 8 ; ++ V_50 )
F_5 ( V_65 L_27 , V_47 [ V_50 ] ) ;
F_5 ( V_65 L_28 ) ;
}
F_35 ( & V_63 ) ;
V_61 = ( V_63 . V_66 - V_2 -> V_67 . V_66 ) * 1000 +
( V_63 . V_68 - V_2 -> V_67 . V_68 ) / 1000 ;
if ( memcmp ( V_47 , L_29 , 8 ) == 0 ) {
if ( ( V_61 < 250 ) && ( V_2 -> V_69 != 0 ) ) {
memcpy ( V_47 , & V_2 -> V_70 , 8 ) ;
V_2 -> V_67 . V_66 = V_63 . V_66 ;
V_2 -> V_67 . V_68 = V_63 . V_68 ;
}
} else {
memcpy ( & V_2 -> V_70 , V_47 , 8 ) ;
V_2 -> V_69 = 1 ;
V_2 -> V_67 . V_66 = V_63 . V_66 ;
V_2 -> V_67 . V_68 = V_63 . V_68 ;
}
F_36 ( V_2 -> V_5 -> V_6 , V_47 ) ;
F_37 ( & V_2 -> V_5 -> V_6 -> V_71 ) ;
}
static void V_58 ( struct V_54 * V_54 )
{
struct V_1 * V_2 ;
if ( ! V_54 )
return;
V_2 = (struct V_1 * ) V_54 -> V_2 ;
if ( ! V_2 )
return;
switch ( V_54 -> V_46 ) {
case - V_72 :
return;
case 0 :
if ( V_2 -> V_33 )
F_34 ( V_2 , V_54 ) ;
break;
default:
F_5 ( V_64 L_30 ,
V_9 , V_54 -> V_46 ) ;
break;
}
F_23 ( V_2 -> V_4 , V_73 ) ;
return;
}
static int F_38 ( struct V_15 * V_16 ,
const struct V_74 * V_75 )
{
struct V_76 * V_21 = NULL ;
struct V_77 * V_78 = NULL ;
struct V_79 * V_56 = NULL ;
struct V_79 * V_36 = NULL ;
struct V_54 * V_4 = NULL ;
struct V_54 * V_3 = NULL ;
struct V_80 * V_5 = NULL ;
struct V_81 * V_6 = NULL ;
int V_82 = 0 ;
int V_83 ;
int V_10 = 0 ;
int V_84 ;
int V_85 ;
int V_86 ;
struct V_1 * V_2 = NULL ;
int V_50 ;
F_14 ( & V_16 -> V_21 , L_31 , V_9 ) ;
V_21 = F_39 ( F_40 ( V_16 ) ) ;
V_78 = V_16 -> V_87 ;
V_83 = V_78 -> V_88 . V_89 ;
V_85 = 0 ;
V_84 = 0 ;
for ( V_50 = 0 ; V_50 < V_83 && ! ( V_85 && V_84 ) ; ++ V_50 ) {
struct V_79 * V_90 ;
int V_91 ;
int V_92 ;
V_90 = & V_78 -> V_93 [ V_50 ] . V_88 ;
V_91 = V_90 -> V_37 & V_94 ;
V_92 = V_90 -> V_95 & V_96 ;
if ( ! V_85 &&
V_91 == V_97 &&
V_92 == V_98 ) {
V_56 = V_90 ;
V_85 = 1 ;
if ( V_7 )
F_14 ( & V_16 -> V_21 ,
L_32 , V_9 ) ;
} else if ( ! V_84 &&
V_91 == V_99 &&
V_92 == V_98 ) {
V_36 = V_90 ;
V_84 = 1 ;
if ( V_7 )
F_14 ( & V_16 -> V_21 ,
L_33 , V_9 ) ;
}
}
if ( ! V_85 ) {
F_13 ( & V_16 -> V_21 ,
L_34 , V_9 ) ;
V_10 = - V_20 ;
goto exit;
}
if ( ! V_84 )
F_14 ( & V_16 -> V_21 ,
L_35 ,
V_9 ) ;
V_86 = 0 ;
V_2 = F_41 ( sizeof( struct V_1 ) , V_45 ) ;
if ( ! V_2 ) {
F_13 ( & V_16 -> V_21 ,
L_36 , V_9 ) ;
V_86 = 1 ;
goto V_100;
}
V_5 = F_41 ( sizeof( struct V_80 ) , V_45 ) ;
if ( ! V_5 ) {
F_13 ( & V_16 -> V_21 ,
L_37 , V_9 ) ;
V_86 = 2 ;
goto V_100;
}
V_6 = F_42 ( sizeof( struct V_81 ) , V_45 ) ;
if ( ! V_6 ) {
F_13 ( & V_16 -> V_21 ,
L_38 , V_9 ) ;
V_86 = 3 ;
goto V_100;
}
if ( F_43 ( V_6 , V_101 , V_102 ) ) {
F_13 ( & V_16 -> V_21 ,
L_39 , V_9 ) ;
V_86 = 4 ;
goto V_100;
}
V_4 = F_44 ( 0 , V_45 ) ;
if ( ! V_4 ) {
F_13 ( & V_16 -> V_21 ,
L_40 , V_9 ) ;
V_86 = 5 ;
goto V_100;
}
if ( V_84 ) {
V_3 = F_44 ( 0 , V_45 ) ;
if ( ! V_3 ) {
F_13 ( & V_16 -> V_21 ,
L_41 ,
V_9 ) ;
V_86 = 6 ;
goto V_100;
}
}
F_45 ( & V_2 -> V_22 ) ;
strcpy ( V_5 -> V_103 , V_104 ) ;
V_5 -> V_11 = - 1 ;
V_5 -> V_105 = 64 ;
V_5 -> V_106 = 0 ;
V_5 -> V_107 = V_108 ;
V_5 -> V_55 = V_2 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_109 = F_30 ;
V_5 -> V_110 = F_32 ;
V_5 -> V_21 = & V_16 -> V_21 ;
V_5 -> V_111 = V_112 ;
F_9 ( & V_2 -> V_22 ) ;
V_82 = F_46 ( V_5 ) ;
if ( V_82 < 0 ) {
F_13 ( & V_16 -> V_21 ,
L_42 , V_9 ) ;
V_86 = 7 ;
V_10 = V_82 ;
goto V_113;
} else
F_5 ( V_8 L_43 ,
V_9 , V_82 ) ;
V_5 -> V_11 = V_82 ;
V_2 -> V_21 = V_21 ;
V_2 -> V_32 = 1 ;
V_2 -> V_56 = V_56 ;
V_2 -> V_4 = V_4 ;
if ( V_84 ) {
V_2 -> V_36 = V_36 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_29 = 1000 ;
}
V_2 -> V_5 = V_5 ;
F_47 ( V_16 , V_2 ) ;
if ( V_84 ) {
if ( V_7 )
F_5 ( V_8 L_44 ) ;
if ( F_48 ( V_16 , & V_114 ) )
F_5 ( V_8 L_45
L_46 , V_9 ) ;
}
F_5 ( V_8 L_47 ,
V_9 , V_21 -> V_115 -> V_116 , V_21 -> V_117 ) ;
V_113:
F_15 ( & V_2 -> V_22 ) ;
V_100:
switch ( V_86 ) {
case 7 :
if ( V_84 )
F_2 ( V_3 ) ;
case 6 :
F_2 ( V_4 ) ;
case 5 :
F_3 ( V_6 ) ;
case 4 :
F_4 ( V_6 ) ;
case 3 :
F_4 ( V_5 ) ;
case 2 :
F_4 ( V_2 ) ;
V_2 = NULL ;
case 1 :
if ( V_10 == 0 )
V_10 = - V_118 ;
}
exit:
return V_10 ;
}
static void F_49 ( struct V_15 * V_16 )
{
struct V_1 * V_2 ;
F_9 ( & V_18 ) ;
V_2 = F_12 ( V_16 ) ;
F_9 ( & V_2 -> V_22 ) ;
F_5 ( V_8 L_48 , V_9 ) ;
F_47 ( V_16 , NULL ) ;
V_2 -> V_32 = 0 ;
F_33 ( V_2 -> V_4 ) ;
if ( F_50 ( & V_2 -> V_42 . V_44 ) ) {
F_33 ( V_2 -> V_3 ) ;
F_24 ( & V_2 -> V_42 . V_43 ) ;
}
if ( ! V_2 -> V_33 )
F_6 ( V_2 ) ;
F_51 ( V_16 , & V_114 ) ;
F_15 ( & V_2 -> V_22 ) ;
if ( ! V_2 -> V_33 && ! V_2 -> V_23 )
F_1 ( V_2 ) ;
F_15 ( & V_18 ) ;
}
