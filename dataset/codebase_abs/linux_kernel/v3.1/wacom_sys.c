static int F_1 ( struct V_1 * V_2 , unsigned char type ,
unsigned char V_3 , void * V_4 , int V_5 )
{
return F_2 ( F_3 ( V_2 ) ,
F_4 ( F_3 ( V_2 ) , 0 ) ,
V_6 , V_7 | V_8 ,
( type << 8 ) + V_3 , V_2 -> V_9 [ 0 ] . V_10 . V_11 ,
V_4 , V_5 , 100 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned char type ,
unsigned char V_3 , void * V_4 , int V_5 )
{
return F_2 ( F_3 ( V_2 ) ,
F_6 ( F_3 ( V_2 ) , 0 ) ,
V_12 , V_7 | V_8 ,
( type << 8 ) + V_3 , V_2 -> V_9 [ 0 ] . V_10 . V_11 ,
V_4 , V_5 , 1000 ) ;
}
static void F_7 ( struct V_13 * V_13 )
{
struct V_14 * V_14 = V_13 -> V_15 ;
int V_16 ;
switch ( V_13 -> V_17 ) {
case 0 :
break;
case - V_18 :
case - V_19 :
case - V_20 :
F_8 ( L_1 , V_21 , V_13 -> V_17 ) ;
return;
default:
F_8 ( L_2 , V_21 , V_13 -> V_17 ) ;
goto exit;
}
F_9 ( & V_14 -> V_22 , V_13 -> V_23 ) ;
exit:
F_10 ( V_14 -> V_24 ) ;
V_16 = F_11 ( V_13 , V_25 ) ;
if ( V_16 )
F_12 ( L_3 ,
V_21 , V_16 ) ;
}
static int F_13 ( struct V_26 * V_27 )
{
struct V_14 * V_14 = F_14 ( V_27 ) ;
int V_16 = 0 ;
if ( F_15 ( V_14 -> V_2 ) < 0 )
return - V_28 ;
F_16 ( & V_14 -> V_29 ) ;
if ( F_11 ( V_14 -> V_30 , V_31 ) ) {
V_16 = - V_28 ;
goto V_32;
}
V_14 -> V_33 = true ;
V_14 -> V_2 -> V_34 = 1 ;
V_32:
F_17 ( & V_14 -> V_29 ) ;
F_18 ( V_14 -> V_2 ) ;
return V_16 ;
}
static void F_19 ( struct V_26 * V_27 )
{
struct V_14 * V_14 = F_14 ( V_27 ) ;
int V_35 ;
V_35 = F_15 ( V_14 -> V_2 ) ;
F_16 ( & V_14 -> V_29 ) ;
F_20 ( V_14 -> V_30 ) ;
V_14 -> V_33 = false ;
V_14 -> V_2 -> V_34 = 0 ;
F_17 ( & V_14 -> V_29 ) ;
if ( ! V_35 )
F_18 ( V_14 -> V_2 ) ;
}
static int F_21 ( struct V_1 * V_2 , struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_40 * V_27 = F_3 ( V_2 ) ;
char V_41 = 0 ;
int V_42 = 0 ;
int V_43 = 0 , V_44 = V_45 , V_46 = 0 , V_47 = 0 ;
unsigned char * V_48 ;
V_48 = F_22 ( V_37 -> V_49 , V_31 ) ;
if ( ! V_48 )
return - V_50 ;
do {
V_42 = F_2 ( V_27 , F_4 ( V_27 , 0 ) ,
V_51 ,
V_8 | V_52 ,
V_53 << 8 ,
V_2 -> V_9 [ 0 ] . V_10 . V_11 ,
V_48 ,
V_37 -> V_49 ,
5000 ) ;
} while ( V_42 < 0 && V_41 ++ < V_54 );
if ( V_42 < 0 )
goto V_32;
for ( V_43 = 0 ; V_43 < V_37 -> V_49 ; V_43 ++ ) {
switch ( V_48 [ V_43 ] ) {
case V_55 :
switch ( V_48 [ V_43 + 1 ] ) {
case V_56 :
V_44 = V_57 ;
V_43 ++ ;
break;
case V_58 :
V_44 = V_59 ;
V_43 ++ ;
break;
}
break;
case V_60 :
switch ( V_48 [ V_43 + 1 ] ) {
case V_61 :
if ( V_44 == V_59 ) {
if ( V_46 ) {
V_39 -> V_62 = V_63 ;
if ( V_39 -> type == V_64 ) {
V_39 -> V_65 = V_66 ;
V_39 -> V_62 = V_67 ;
}
if ( V_39 -> type == V_68 ) {
V_39 -> V_65 = V_69 ;
V_39 -> V_62 = V_67 ;
V_39 -> V_70 =
F_23 ( & V_48 [ V_43 + 5 ] ) ;
V_39 -> V_71 =
F_23 ( & V_48 [ V_43 + 8 ] ) ;
V_43 += 15 ;
} else {
V_39 -> V_71 =
F_23 ( & V_48 [ V_43 + 3 ] ) ;
V_39 -> V_70 =
F_23 ( & V_48 [ V_43 + 6 ] ) ;
V_39 -> V_72 = V_48 [ V_43 + 9 ] ;
V_39 -> V_73 = V_48 [ V_43 + 11 ] ;
V_43 += 12 ;
}
} else if ( V_47 ) {
if ( V_39 -> type == V_64 )
V_39 -> V_65 = V_74 ;
if ( V_39 -> type == V_68 )
V_39 -> V_65 = V_75 ;
V_39 -> V_62 = V_76 ;
V_39 -> V_71 =
F_23 ( & V_48 [ V_43 + 3 ] ) ;
V_43 += 4 ;
}
}
break;
case V_77 :
if ( V_44 == V_59 ) {
if ( V_46 ) {
V_39 -> V_62 = V_63 ;
if ( V_39 -> type == V_64 ) {
V_39 -> V_65 = V_66 ;
V_39 -> V_62 = V_67 ;
V_39 -> V_78 =
F_23 ( & V_48 [ V_43 + 3 ] ) ;
V_39 -> V_79 =
F_23 ( & V_48 [ V_43 + 6 ] ) ;
V_43 += 7 ;
} else if ( V_39 -> type == V_68 ) {
V_39 -> V_65 = V_69 ;
V_39 -> V_62 = V_67 ;
V_39 -> V_79 =
F_23 ( & V_48 [ V_43 + 3 ] ) ;
V_39 -> V_78 =
F_23 ( & V_48 [ V_43 + 6 ] ) ;
V_43 += 12 ;
} else {
V_39 -> V_78 =
V_39 -> V_71 ;
V_39 -> V_79 =
F_23 ( & V_48 [ V_43 + 3 ] ) ;
V_43 += 4 ;
}
} else if ( V_47 ) {
if ( V_39 -> type == V_64 )
V_39 -> V_65 = V_74 ;
if ( V_39 -> type == V_68 )
V_39 -> V_65 = V_75 ;
V_39 -> V_62 = V_76 ;
V_39 -> V_78 =
F_23 ( & V_48 [ V_43 + 3 ] ) ;
V_43 += 4 ;
}
}
break;
case V_80 :
V_46 = 1 ;
V_43 ++ ;
break;
case V_81 :
V_47 = 1 ;
V_43 ++ ;
break;
}
break;
case V_82 :
V_46 = V_44 = 0 ;
break;
}
}
V_32:
V_42 = 0 ;
F_24 ( V_48 ) ;
return V_42 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
unsigned char * V_83 ;
int V_41 = 0 , V_84 = 2 ;
int error = - V_50 ;
V_83 = F_26 ( 4 , V_31 ) ;
if ( ! V_83 )
return error ;
if ( V_39 -> type == V_64 ) {
do {
V_83 [ 0 ] = 3 ;
V_83 [ 1 ] = 4 ;
V_83 [ 2 ] = 0 ;
V_83 [ 3 ] = 0 ;
V_84 = 3 ;
error = F_5 ( V_2 , V_85 ,
V_84 , V_83 , 4 ) ;
if ( error >= 0 )
error = F_1 ( V_2 ,
V_85 , V_84 ,
V_83 , 4 ) ;
} while ( ( error < 0 || V_83 [ 1 ] != 4 ) && V_41 ++ < V_54 );
} else if ( V_39 -> type != V_86 ) {
do {
V_83 [ 0 ] = 2 ;
V_83 [ 1 ] = 2 ;
error = F_5 ( V_2 , V_85 ,
V_84 , V_83 , 2 ) ;
if ( error >= 0 )
error = F_1 ( V_2 ,
V_85 , V_84 ,
V_83 , 2 ) ;
} while ( ( error < 0 || V_83 [ 1 ] != 2 ) && V_41 ++ < V_54 );
}
F_24 ( V_83 ) ;
return error < 0 ? error : 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_38 * V_39 )
{
int error = 0 ;
struct V_87 * V_88 = V_2 -> V_89 ;
struct V_36 * V_37 ;
V_39 -> V_62 = V_76 ;
V_39 -> V_90 = 4 ;
V_39 -> V_91 = 4 ;
V_39 -> V_92 = 0 ;
V_39 -> V_93 = 0 ;
if ( ( V_39 -> type != V_86 ) && ( V_39 -> type != V_64 ) &&
( V_39 -> type != V_68 ) )
goto V_32;
if ( F_28 ( V_88 , V_94 , & V_37 ) ) {
if ( F_28 ( & V_88 -> V_95 [ 0 ] ,
V_53 , & V_37 ) ) {
F_29 ( L_4 ) ;
error = 1 ;
goto V_32;
}
}
error = F_21 ( V_2 , V_37 , V_39 ) ;
if ( error )
goto V_32;
V_32:
return error ;
}
static struct V_96 * F_30 ( struct V_40 * V_27 )
{
struct V_96 * V_97 ;
F_31 (data, &wacom_udev_list, list) {
if ( V_97 -> V_27 == V_27 ) {
F_32 ( & V_97 -> V_98 ) ;
return V_97 ;
}
}
return NULL ;
}
static int F_33 ( struct V_22 * V_14 ,
struct V_40 * V_27 )
{
struct V_96 * V_97 ;
int V_16 = 0 ;
F_16 ( & V_99 ) ;
V_97 = F_30 ( V_27 ) ;
if ( ! V_97 ) {
V_97 = F_22 ( sizeof( struct V_96 ) , V_31 ) ;
if ( ! V_97 ) {
V_16 = - V_50 ;
goto V_32;
}
F_34 ( & V_97 -> V_98 ) ;
V_97 -> V_27 = V_27 ;
F_35 ( & V_97 -> V_100 , & V_101 ) ;
}
V_14 -> V_102 = & V_97 -> V_102 ;
V_32:
F_17 ( & V_99 ) ;
return V_16 ;
}
static void F_36 ( struct V_98 * V_98 )
{
struct V_96 * V_97 =
F_37 ( V_98 , struct V_96 , V_98 ) ;
F_16 ( & V_99 ) ;
F_38 ( & V_97 -> V_100 ) ;
F_17 ( & V_99 ) ;
F_24 ( V_97 ) ;
}
static void F_39 ( struct V_22 * V_14 )
{
struct V_96 * V_97 ;
if ( V_14 -> V_102 ) {
V_97 = F_37 ( V_14 -> V_102 , struct V_96 , V_102 ) ;
F_40 ( & V_97 -> V_98 , F_36 ) ;
V_14 -> V_102 = NULL ;
}
}
static int F_41 ( struct V_1 * V_2 , const struct V_103 * V_3 )
{
struct V_40 * V_27 = F_3 ( V_2 ) ;
struct V_104 * V_95 ;
struct V_14 * V_14 ;
struct V_22 * V_22 ;
struct V_38 * V_39 ;
struct V_26 * V_26 ;
int error ;
if ( ! V_3 -> V_105 )
return - V_106 ;
V_14 = F_22 ( sizeof( struct V_14 ) , V_31 ) ;
V_26 = F_42 () ;
if ( ! V_14 || ! V_26 ) {
error = - V_50 ;
goto V_107;
}
V_22 = & V_14 -> V_22 ;
V_22 -> V_39 = * ( (struct V_38 * ) V_3 -> V_105 ) ;
V_39 = & V_22 -> V_39 ;
if ( V_39 -> V_65 > V_108 ) {
error = - V_106 ;
goto V_107;
}
V_22 -> V_97 = F_43 ( V_27 , V_108 ,
V_31 , & V_14 -> V_109 ) ;
if ( ! V_22 -> V_97 ) {
error = - V_50 ;
goto V_107;
}
V_14 -> V_30 = F_44 ( 0 , V_31 ) ;
if ( ! V_14 -> V_30 ) {
error = - V_50 ;
goto V_110;
}
V_14 -> V_24 = V_27 ;
V_14 -> V_2 = V_2 ;
F_45 ( & V_14 -> V_29 ) ;
F_46 ( V_27 , V_14 -> V_111 , sizeof( V_14 -> V_111 ) ) ;
F_47 ( V_14 -> V_111 , L_5 , sizeof( V_14 -> V_111 ) ) ;
V_22 -> V_112 = V_26 ;
V_95 = & V_2 -> V_89 -> V_95 [ 0 ] . V_10 ;
error = F_27 ( V_2 , V_39 ) ;
if ( error )
goto V_113;
F_48 ( V_39 ) ;
F_49 ( V_22 -> V_114 , V_39 -> V_114 , sizeof( V_22 -> V_114 ) ) ;
if ( V_39 -> V_115 & V_116 ) {
F_47 ( V_22 -> V_114 ,
V_39 -> V_62 == V_76 ?
L_6 : L_7 ,
sizeof( V_22 -> V_114 ) ) ;
error = F_33 ( V_22 , V_27 ) ;
if ( error )
goto V_113;
}
V_26 -> V_114 = V_22 -> V_114 ;
V_26 -> V_27 . V_117 = & V_2 -> V_27 ;
V_26 -> V_33 = F_13 ;
V_26 -> V_118 = F_19 ;
F_50 ( V_27 , & V_26 -> V_3 ) ;
F_51 ( V_26 , V_14 ) ;
F_52 ( V_26 , V_22 ) ;
F_53 ( V_14 -> V_30 , V_27 ,
F_54 ( V_27 , V_95 -> V_119 ) ,
V_22 -> V_97 , V_39 -> V_65 ,
F_7 , V_14 , V_95 -> V_120 ) ;
V_14 -> V_30 -> V_121 = V_14 -> V_109 ;
V_14 -> V_30 -> V_122 |= V_123 ;
error = F_55 ( V_26 ) ;
if ( error )
goto V_124;
F_25 ( V_2 , V_39 ) ;
F_56 ( V_2 , V_14 ) ;
return 0 ;
V_124: F_39 ( V_22 ) ;
V_113: F_57 ( V_14 -> V_30 ) ;
V_110: F_58 ( V_27 , V_108 , V_22 -> V_97 , V_14 -> V_109 ) ;
V_107: F_59 ( V_26 ) ;
F_24 ( V_14 ) ;
return error ;
}
static void F_60 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_61 ( V_2 ) ;
F_56 ( V_2 , NULL ) ;
F_20 ( V_14 -> V_30 ) ;
F_62 ( V_14 -> V_22 . V_112 ) ;
F_57 ( V_14 -> V_30 ) ;
F_58 ( F_3 ( V_2 ) , V_108 ,
V_14 -> V_22 . V_97 , V_14 -> V_109 ) ;
F_39 ( & V_14 -> V_22 ) ;
F_24 ( V_14 ) ;
}
static int F_63 ( struct V_1 * V_2 , T_1 V_125 )
{
struct V_14 * V_14 = F_61 ( V_2 ) ;
F_16 ( & V_14 -> V_29 ) ;
F_20 ( V_14 -> V_30 ) ;
F_17 ( & V_14 -> V_29 ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_14 * V_14 = F_61 ( V_2 ) ;
struct V_38 * V_39 = & V_14 -> V_22 . V_39 ;
int V_126 ;
F_16 ( & V_14 -> V_29 ) ;
F_25 ( V_2 , V_39 ) ;
if ( V_14 -> V_33 )
V_126 = F_11 ( V_14 -> V_30 , V_127 ) ;
else
V_126 = 0 ;
F_17 ( & V_14 -> V_29 ) ;
return V_126 ;
}
static int F_65 ( struct V_1 * V_2 )
{
return F_64 ( V_2 ) ;
}
static int T_2 F_66 ( void )
{
int V_42 ;
V_42 = F_67 ( & V_128 ) ;
if ( V_42 == 0 )
F_29 (KERN_INFO KBUILD_MODNAME L_8 DRIVER_VERSION L_9
DRIVER_DESC L_10 ) ;
return V_42 ;
}
static void T_3 F_68 ( void )
{
F_69 ( & V_128 ) ;
}
