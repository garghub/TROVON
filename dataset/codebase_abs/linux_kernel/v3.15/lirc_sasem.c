static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 ) ;
F_2 ( V_2 -> V_4 ) ;
F_3 ( V_2 -> V_5 -> V_6 ) ;
F_4 ( V_2 -> V_5 -> V_6 ) ;
F_4 ( V_2 -> V_5 ) ;
F_4 ( V_2 ) ;
if ( V_7 )
F_5 ( L_1 , V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
int V_9 ;
int V_10 = V_2 -> V_5 -> V_10 ;
V_9 = F_7 ( V_10 ) ;
if ( V_9 )
F_8 ( L_2 ,
V_8 , V_9 ) ;
else
F_5 ( L_3 , V_10 ) ;
}
static int F_9 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 = NULL ;
int V_15 ;
int V_9 = 0 ;
F_10 ( & V_16 ) ;
V_15 = F_11 ( V_11 ) ;
V_14 = F_12 ( & V_17 , V_15 ) ;
if ( ! V_14 ) {
F_8 ( L_4 ,
V_8 , V_15 ) ;
V_9 = - V_18 ;
goto exit;
}
V_2 = F_13 ( V_14 ) ;
if ( ! V_2 ) {
F_14 ( & V_14 -> V_19 ,
L_5 ,
V_8 , V_15 ) ;
V_9 = - V_18 ;
goto exit;
}
F_10 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_21 ) {
F_14 ( & V_14 -> V_19 ,
L_6 , V_8 ) ;
V_9 = - V_22 ;
} else {
V_2 -> V_21 = 1 ;
V_12 -> V_23 = V_2 ;
F_15 ( & V_14 -> V_19 , L_7 ) ;
}
F_16 ( & V_2 -> V_20 ) ;
exit:
F_16 ( & V_16 ) ;
return V_9 ;
}
static long F_17 ( struct V_12 * V_12 , unsigned V_24 , unsigned long V_25 )
{
struct V_1 * V_2 = NULL ;
V_2 = (struct V_1 * ) V_12 -> V_23 ;
if ( ! V_2 ) {
F_8 ( L_8 , V_8 ) ;
return - V_18 ;
}
F_10 ( & V_2 -> V_20 ) ;
switch ( V_24 ) {
case V_26 :
if ( V_25 > 1000 )
V_25 = 1000 ;
V_2 -> V_27 = ( unsigned int ) V_25 ;
break;
default:
F_5 ( L_9 ) ;
F_16 ( & V_2 -> V_20 ) ;
return - V_28 ;
}
F_16 ( & V_2 -> V_20 ) ;
return 0 ;
}
static int F_18 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
struct V_1 * V_2 = NULL ;
int V_9 = 0 ;
V_2 = (struct V_1 * ) V_12 -> V_23 ;
if ( ! V_2 ) {
F_8 ( L_8 , V_8 ) ;
return - V_18 ;
}
F_10 ( & V_2 -> V_20 ) ;
if ( ! V_2 -> V_21 ) {
F_14 ( & V_2 -> V_19 -> V_19 , L_10 , V_8 ) ;
V_9 = - V_29 ;
} else {
V_2 -> V_21 = 0 ;
F_15 ( & V_2 -> V_19 -> V_19 , L_11 ) ;
if ( ! V_2 -> V_30 && ! V_2 -> V_31 ) {
F_16 ( & V_2 -> V_20 ) ;
F_1 ( V_2 ) ;
return V_9 ;
}
}
F_16 ( & V_2 -> V_20 ) ;
return V_9 ;
}
static int F_19 ( struct V_1 * V_2 )
{
unsigned int V_32 ;
int V_33 = 0 ;
int V_9 = 0 ;
V_32 = F_20 ( V_2 -> V_19 ,
V_2 -> V_34 -> V_35 ) ;
V_33 = V_2 -> V_34 -> V_36 ;
F_21 ( V_2 -> V_3 , V_2 -> V_19 , V_32 ,
V_2 -> V_37 , sizeof( V_2 -> V_37 ) ,
V_38 , V_2 , V_33 ) ;
V_2 -> V_3 -> V_39 = 0 ;
F_22 ( & V_2 -> V_40 . V_41 ) ;
F_23 ( & ( V_2 -> V_40 . V_42 ) , 1 ) ;
V_9 = F_24 ( V_2 -> V_3 , V_43 ) ;
if ( V_9 ) {
F_23 ( & ( V_2 -> V_40 . V_42 ) , 0 ) ;
F_14 ( & V_2 -> V_19 -> V_19 , L_12 ,
V_8 , V_9 ) ;
} else {
F_16 ( & V_2 -> V_20 ) ;
F_25 ( & V_2 -> V_40 . V_41 ) ;
F_10 ( & V_2 -> V_20 ) ;
V_9 = V_2 -> V_40 . V_44 ;
if ( V_9 )
F_14 ( & V_2 -> V_19 -> V_19 ,
L_13 ,
V_8 , V_9 ) ;
}
return V_9 ;
}
static T_1 F_26 ( struct V_12 * V_12 , const char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
int V_48 ;
int V_9 = 0 ;
struct V_1 * V_2 ;
int * V_49 = NULL ;
V_2 = (struct V_1 * ) V_12 -> V_23 ;
if ( ! V_2 ) {
F_8 ( L_8 , V_8 ) ;
return - V_18 ;
}
F_10 ( & V_2 -> V_20 ) ;
if ( ! V_2 -> V_30 ) {
F_8 ( L_14 , V_8 ) ;
V_9 = - V_18 ;
goto exit;
}
if ( V_46 <= 0 || V_46 > V_50 ) {
F_14 ( & V_2 -> V_19 -> V_19 , L_15 ,
V_8 ) ;
V_9 = - V_51 ;
goto exit;
}
V_49 = F_27 ( ( void const T_2 * ) V_45 , V_46 ) ;
if ( F_28 ( V_49 ) ) {
V_9 = F_29 ( V_49 ) ;
goto exit;
}
memcpy ( V_2 -> V_40 . V_49 , V_49 , V_46 ) ;
for ( V_48 = V_46 ; V_48 < V_50 ; ++ V_48 )
V_2 -> V_40 . V_49 [ V_48 ] = ' ' ;
for ( V_48 = 0 ; V_48 < 9 ; V_48 ++ ) {
switch ( V_48 ) {
case 0 :
memcpy ( V_2 -> V_37 , L_16 , 8 ) ;
V_2 -> V_37 [ 1 ] = ( V_2 -> V_27 ) ?
( 0x2B - ( V_2 -> V_27 - 1 ) / 250 )
: 0x2B ;
break;
case 1 :
memcpy ( V_2 -> V_37 , L_17 , 8 ) ;
break;
case 2 :
memcpy ( V_2 -> V_37 , L_18 , 8 ) ;
break;
case 3 :
memcpy ( V_2 -> V_37 , V_2 -> V_40 . V_49 , 8 ) ;
break;
case 4 :
memcpy ( V_2 -> V_37 ,
V_2 -> V_40 . V_49 + 8 , 8 ) ;
break;
case 5 :
memcpy ( V_2 -> V_37 , L_17 , 8 ) ;
break;
case 6 :
memcpy ( V_2 -> V_37 , L_19 , 8 ) ;
break;
case 7 :
memcpy ( V_2 -> V_37 ,
V_2 -> V_40 . V_49 + 16 , 8 ) ;
break;
case 8 :
memcpy ( V_2 -> V_37 ,
V_2 -> V_40 . V_49 + 24 , 8 ) ;
break;
}
V_9 = F_19 ( V_2 ) ;
if ( V_9 ) {
F_14 ( & V_2 -> V_19 -> V_19 ,
L_20 ,
V_8 , V_48 ) ;
goto exit;
}
}
exit:
F_16 ( & V_2 -> V_20 ) ;
F_4 ( V_49 ) ;
return ( ! V_9 ) ? V_46 : V_9 ;
}
static void V_38 ( struct V_52 * V_52 )
{
struct V_1 * V_2 ;
if ( ! V_52 )
return;
V_2 = (struct V_1 * ) V_52 -> V_2 ;
if ( ! V_2 )
return;
V_2 -> V_40 . V_44 = V_52 -> V_44 ;
F_23 ( & V_2 -> V_40 . V_42 , 0 ) ;
F_30 ( & V_2 -> V_40 . V_41 ) ;
return;
}
static int F_31 ( void * V_53 )
{
int V_9 = 0 ;
struct V_1 * V_2 ;
F_10 ( & V_16 ) ;
V_2 = (struct V_1 * ) V_53 ;
F_10 ( & V_2 -> V_20 ) ;
if ( V_2 -> V_31 ) {
F_14 ( & V_2 -> V_19 -> V_19 , L_21 ,
V_8 ) ;
V_9 = - V_22 ;
goto exit;
}
F_21 ( V_2 -> V_4 , V_2 -> V_19 ,
F_32 ( V_2 -> V_19 ,
V_2 -> V_54 -> V_35 ) ,
V_2 -> V_55 , sizeof( V_2 -> V_55 ) ,
V_56 , V_2 , V_2 -> V_54 -> V_36 ) ;
V_9 = F_24 ( V_2 -> V_4 , V_43 ) ;
if ( V_9 )
F_14 ( & V_2 -> V_19 -> V_19 ,
L_22 ,
V_8 , V_9 ) ;
else {
V_2 -> V_31 = 1 ;
F_15 ( & V_2 -> V_19 -> V_19 , L_23 ) ;
}
exit:
F_16 ( & V_2 -> V_20 ) ;
F_16 ( & V_16 ) ;
return V_9 ;
}
static void F_33 ( void * V_53 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_53 ;
if ( ! V_2 ) {
F_8 ( L_8 , V_8 ) ;
return;
}
F_10 ( & V_2 -> V_20 ) ;
F_34 ( V_2 -> V_4 ) ;
V_2 -> V_31 = 0 ;
F_5 ( L_24 ) ;
if ( ! V_2 -> V_30 ) {
F_6 ( V_2 ) ;
if ( ! V_2 -> V_21 ) {
F_16 ( & V_2 -> V_20 ) ;
F_1 ( V_2 ) ;
return;
}
}
F_16 ( & V_2 -> V_20 ) ;
return;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_52 * V_52 )
{
int V_57 = V_52 -> V_39 ;
unsigned char * V_45 = V_52 -> V_58 ;
long V_59 ;
struct V_60 V_61 ;
int V_48 ;
if ( V_57 != 8 ) {
F_36 ( & V_2 -> V_19 -> V_19 ,
L_25 ,
V_8 , V_57 ) ;
return;
}
if ( V_7 ) {
F_37 ( V_62 L_26 ) ;
for ( V_48 = 0 ; V_48 < 8 ; ++ V_48 )
F_37 ( V_63 L_27 , V_45 [ V_48 ] ) ;
F_37 ( V_63 L_28 ) ;
}
F_38 ( & V_61 ) ;
V_59 = ( V_61 . V_64 - V_2 -> V_65 . V_64 ) * 1000 +
( V_61 . V_66 - V_2 -> V_65 . V_66 ) / 1000 ;
if ( memcmp ( V_45 , L_29 , 8 ) == 0 ) {
if ( ( V_59 < 250 ) && ( V_2 -> V_67 != 0 ) ) {
memcpy ( V_45 , & V_2 -> V_68 , 8 ) ;
V_2 -> V_65 . V_64 = V_61 . V_64 ;
V_2 -> V_65 . V_66 = V_61 . V_66 ;
}
} else {
memcpy ( & V_2 -> V_68 , V_45 , 8 ) ;
V_2 -> V_67 = 1 ;
V_2 -> V_65 . V_64 = V_61 . V_64 ;
V_2 -> V_65 . V_66 = V_61 . V_66 ;
}
F_39 ( V_2 -> V_5 -> V_6 , V_45 ) ;
F_40 ( & V_2 -> V_5 -> V_6 -> V_69 ) ;
}
static void V_56 ( struct V_52 * V_52 )
{
struct V_1 * V_2 ;
if ( ! V_52 )
return;
V_2 = (struct V_1 * ) V_52 -> V_2 ;
if ( ! V_2 )
return;
switch ( V_52 -> V_44 ) {
case - V_70 :
return;
case 0 :
if ( V_2 -> V_31 )
F_35 ( V_2 , V_52 ) ;
break;
default:
F_36 ( & V_52 -> V_19 -> V_19 , L_30 ,
V_8 , V_52 -> V_44 ) ;
break;
}
F_24 ( V_2 -> V_4 , V_71 ) ;
return;
}
static int F_41 ( struct V_13 * V_14 ,
const struct V_72 * V_73 )
{
struct V_74 * V_19 = NULL ;
struct V_75 * V_76 = NULL ;
struct V_77 * V_54 = NULL ;
struct V_77 * V_34 = NULL ;
struct V_52 * V_4 = NULL ;
struct V_52 * V_3 = NULL ;
struct V_78 * V_5 = NULL ;
struct V_79 * V_6 = NULL ;
int V_80 = 0 ;
int V_81 ;
int V_9 = 0 ;
int V_82 ;
int V_83 ;
int V_84 ;
struct V_1 * V_2 = NULL ;
int V_48 ;
F_15 ( & V_14 -> V_19 , L_31 , V_8 ) ;
V_19 = F_42 ( F_43 ( V_14 ) ) ;
V_76 = V_14 -> V_85 ;
V_81 = V_76 -> V_86 . V_87 ;
V_83 = 0 ;
V_82 = 0 ;
for ( V_48 = 0 ; V_48 < V_81 && ! ( V_83 && V_82 ) ; ++ V_48 ) {
struct V_77 * V_88 ;
int V_89 ;
int V_90 ;
V_88 = & V_76 -> V_91 [ V_48 ] . V_86 ;
V_89 = V_88 -> V_35 & V_92 ;
V_90 = V_88 -> V_93 & V_94 ;
if ( ! V_83 &&
V_89 == V_95 &&
V_90 == V_96 ) {
V_54 = V_88 ;
V_83 = 1 ;
if ( V_7 )
F_15 ( & V_14 -> V_19 ,
L_32 , V_8 ) ;
} else if ( ! V_82 &&
V_89 == V_97 &&
V_90 == V_96 ) {
V_34 = V_88 ;
V_82 = 1 ;
if ( V_7 )
F_15 ( & V_14 -> V_19 ,
L_33 , V_8 ) ;
}
}
if ( ! V_83 ) {
F_14 ( & V_14 -> V_19 ,
L_34 , V_8 ) ;
V_9 = - V_18 ;
goto exit;
}
if ( ! V_82 )
F_15 ( & V_14 -> V_19 ,
L_35 ,
V_8 ) ;
V_84 = 0 ;
V_2 = F_44 ( sizeof( struct V_1 ) , V_43 ) ;
if ( ! V_2 ) {
V_84 = 1 ;
goto V_98;
}
V_5 = F_44 ( sizeof( struct V_78 ) , V_43 ) ;
if ( ! V_5 ) {
V_84 = 2 ;
goto V_98;
}
V_6 = F_45 ( sizeof( struct V_79 ) , V_43 ) ;
if ( ! V_6 ) {
V_84 = 3 ;
goto V_98;
}
if ( F_46 ( V_6 , V_99 , V_100 ) ) {
F_14 ( & V_14 -> V_19 ,
L_36 , V_8 ) ;
V_84 = 4 ;
goto V_98;
}
V_4 = F_47 ( 0 , V_43 ) ;
if ( ! V_4 ) {
F_14 ( & V_14 -> V_19 ,
L_37 , V_8 ) ;
V_84 = 5 ;
goto V_98;
}
if ( V_82 ) {
V_3 = F_47 ( 0 , V_43 ) ;
if ( ! V_3 ) {
F_14 ( & V_14 -> V_19 ,
L_38 ,
V_8 ) ;
V_84 = 6 ;
goto V_98;
}
}
F_48 ( & V_2 -> V_20 ) ;
strcpy ( V_5 -> V_101 , V_102 ) ;
V_5 -> V_10 = - 1 ;
V_5 -> V_103 = 64 ;
V_5 -> V_104 = 0 ;
V_5 -> V_105 = V_106 ;
V_5 -> V_53 = V_2 ;
V_5 -> V_6 = V_6 ;
V_5 -> V_107 = F_31 ;
V_5 -> V_108 = F_33 ;
V_5 -> V_19 = & V_14 -> V_19 ;
V_5 -> V_109 = V_110 ;
F_10 ( & V_2 -> V_20 ) ;
V_80 = F_49 ( V_5 ) ;
if ( V_80 < 0 ) {
F_14 ( & V_14 -> V_19 ,
L_39 , V_8 ) ;
V_84 = 7 ;
V_9 = V_80 ;
goto V_111;
} else
F_15 ( & V_14 -> V_19 ,
L_40 ,
V_8 , V_80 ) ;
V_5 -> V_10 = V_80 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_30 = 1 ;
V_2 -> V_54 = V_54 ;
V_2 -> V_4 = V_4 ;
if ( V_82 ) {
V_2 -> V_34 = V_34 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_27 = 1000 ;
}
V_2 -> V_5 = V_5 ;
F_50 ( V_14 , V_2 ) ;
if ( V_82 ) {
if ( V_7 )
F_15 ( & V_14 -> V_19 ,
L_41 ) ;
if ( F_51 ( V_14 , & V_112 ) )
F_15 ( & V_14 -> V_19 ,
L_42 ,
V_8 ) ;
}
F_15 ( & V_14 -> V_19 ,
L_43 ,
V_8 , V_19 -> V_113 -> V_114 , V_19 -> V_115 ) ;
V_111:
F_16 ( & V_2 -> V_20 ) ;
V_98:
switch ( V_84 ) {
case 7 :
if ( V_82 )
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
if ( V_9 == 0 )
V_9 = - V_116 ;
}
exit:
return V_9 ;
}
static void F_52 ( struct V_13 * V_14 )
{
struct V_1 * V_2 ;
F_10 ( & V_16 ) ;
V_2 = F_13 ( V_14 ) ;
F_10 ( & V_2 -> V_20 ) ;
F_15 ( & V_14 -> V_19 , L_44 ,
V_8 ) ;
F_50 ( V_14 , NULL ) ;
V_2 -> V_30 = 0 ;
F_34 ( V_2 -> V_4 ) ;
if ( F_53 ( & V_2 -> V_40 . V_42 ) ) {
F_34 ( V_2 -> V_3 ) ;
F_25 ( & V_2 -> V_40 . V_41 ) ;
}
if ( ! V_2 -> V_31 )
F_6 ( V_2 ) ;
F_54 ( V_14 , & V_112 ) ;
F_16 ( & V_2 -> V_20 ) ;
if ( ! V_2 -> V_31 && ! V_2 -> V_21 )
F_1 ( V_2 ) ;
F_16 ( & V_16 ) ;
}
