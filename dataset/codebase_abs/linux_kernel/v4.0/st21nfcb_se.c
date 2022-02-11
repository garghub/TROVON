static T_1 F_1 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_4 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
for ( V_3 = 1 ; V_3 < V_7 ; V_3 ++ ) {
V_4 = F_3 ( V_6 -> V_8 . V_9 [ V_3 ] ) ;
if ( F_4 ( V_4 ) )
V_3 ++ ;
if ( F_5 ( V_4 ) ) {
V_3 ++ ;
return V_6 -> V_8 . V_9 [ V_3 ] >> 4 ;
}
}
return V_10 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_11 ;
struct V_12 * V_13 ;
V_11 = F_7 ( V_2 , V_14 ,
V_15 , & V_13 ) ;
if ( V_11 < 0 )
return;
if ( V_13 -> V_16 <= V_7 ) {
memcpy ( V_6 -> V_8 . V_9 , V_13 -> V_17 , V_13 -> V_16 ) ;
V_6 -> V_8 . V_18 =
F_8 ( F_1 ( V_2 ) ) ;
}
F_9 ( V_13 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_3 , V_19 , V_11 ;
struct V_12 * V_20 , * V_21 ;
struct V_22 * V_23 ;
T_1 V_24 [] = { V_25 ,
V_26 } ;
T_1 V_27 [] = { V_28 ,
V_26 , 0 } ;
V_11 = F_11 ( V_2 , V_29 ,
V_30 ,
V_31 ) ;
if ( V_11 < 0 )
goto V_32;
V_11 = F_12 ( V_2 , V_30 ,
V_33 , V_24 , sizeof( V_24 ) ,
& V_20 ) ;
if ( V_11 < 0 )
goto V_32;
for ( V_3 = 0 ; V_3 < V_20 -> V_16 ; V_3 ++ ) {
V_27 [ 2 ] = V_20 -> V_17 [ V_3 ] ;
V_11 = F_12 ( V_2 , V_30 ,
V_33 , V_27 ,
sizeof( V_27 ) , & V_21 ) ;
if ( V_11 )
continue;
V_23 = (struct V_22 * ) V_21 -> V_17 ;
if ( V_23 -> V_34 == V_14 &&
V_23 -> V_35 != V_36 ) {
F_13 ( L_1 ,
V_23 -> V_35 ) ;
continue;
}
for ( V_19 = 0 ; ( V_19 < F_14 ( V_37 ) ) &&
( V_37 [ V_19 ] . V_38 != V_23 -> V_34 ) ; V_19 ++ )
;
if ( V_19 < F_14 ( V_37 ) &&
V_37 [ V_19 ] . V_38 == V_23 -> V_34 &&
F_15 ( V_23 -> V_39 ) ) {
V_37 [ V_19 ] . V_40 = V_27 [ 2 ] ;
V_2 -> V_41 -> V_42 [ V_37 [ V_19 ] . V_38 ] =
V_37 [ V_19 ] . V_40 ;
V_2 -> V_41 -> V_43 [ V_37 [ V_19 ] . V_40 ] . V_38 =
V_37 [ V_19 ] . V_38 ;
V_2 -> V_41 -> V_43 [ V_37 [ V_19 ] . V_40 ] . V_44 =
V_23 -> V_35 ;
}
}
memcpy ( V_2 -> V_41 -> V_45 . V_46 , V_37 ,
sizeof( V_37 ) ) ;
V_32:
F_9 ( V_21 ) ;
F_9 ( V_20 ) ;
return V_11 ;
}
static void F_16 ( struct V_1 * V_2 ,
T_1 V_47 , struct V_12 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_47 ) {
case V_48 :
if ( V_6 -> V_8 . V_49 ) {
if ( ! F_17 ( V_13 ) ) {
F_18 ( & V_6 -> V_8 . V_50 ) ;
V_6 -> V_8 . V_49 = false ;
F_19 ( & V_6 -> V_8 . V_51 ) ;
} else {
F_20 ( & V_6 -> V_8 . V_50 ,
V_52 +
F_21 ( V_53 ) ) ;
}
}
break;
}
}
static int F_22 ( struct V_1 * V_2 ,
T_1 V_47 ,
struct V_12 * V_13 )
{
int V_11 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_23 ( L_2 , V_47 ) ;
switch ( V_47 ) {
case V_54 :
F_18 ( & V_6 -> V_8 . V_55 ) ;
V_6 -> V_8 . V_56 = false ;
V_6 -> V_8 . V_57 ( V_6 -> V_8 . V_58 ,
V_13 -> V_17 , V_13 -> V_16 , 0 ) ;
break;
case V_59 :
F_20 ( & V_6 -> V_8 . V_55 , V_52 +
F_21 ( V_6 -> V_8 . V_18 ) ) ;
break;
}
F_9 ( V_13 ) ;
return V_11 ;
}
static int F_24 ( struct V_1 * V_2 ,
T_1 V_44 , T_1 V_47 ,
struct V_12 * V_13 )
{
int V_11 = 0 ;
struct V_60 * V_61 = & V_2 -> V_62 -> V_61 ;
struct V_63 * V_64 ;
F_23 ( L_3 , V_47 ) ;
switch ( V_47 ) {
case V_65 :
break;
case V_66 :
if ( V_13 -> V_16 < V_67 + 2 &&
V_13 -> V_17 [ 0 ] != V_68 )
return - V_69 ;
V_64 = (struct V_63 * ) F_25 ( V_61 ,
V_13 -> V_16 - 2 , V_70 ) ;
V_64 -> V_71 = V_13 -> V_17 [ 1 ] ;
memcpy ( V_64 -> V_72 , & V_13 -> V_17 [ 2 ] , V_13 -> V_17 [ 1 ] ) ;
if ( V_13 -> V_17 [ V_64 -> V_71 + 2 ] !=
V_73 )
return - V_69 ;
V_64 -> V_74 = V_13 -> V_17 [ V_64 -> V_71 + 3 ] ;
memcpy ( V_64 -> V_75 , V_13 -> V_17 +
V_64 -> V_71 + 4 , V_64 -> V_74 ) ;
V_11 = F_26 ( V_2 -> V_62 , V_44 , V_64 ) ;
default:
return 1 ;
}
F_9 ( V_13 ) ;
return V_11 ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_40 ,
T_1 V_47 , struct V_12 * V_13 )
{
T_1 V_38 = V_2 -> V_41 -> V_43 [ V_40 ] . V_38 ;
T_1 V_44 = V_2 -> V_41 -> V_43 [ V_40 ] . V_44 ;
switch ( V_38 ) {
case V_76 :
F_16 ( V_2 , V_47 , V_13 ) ;
break;
case V_14 :
F_22 ( V_2 , V_47 , V_13 ) ;
break;
case V_77 :
F_24 ( V_2 , V_44 , V_47 ,
V_13 ) ;
break;
}
}
void F_28 ( struct V_1 * V_2 , T_1 V_40 , T_1 V_78 ,
struct V_12 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_38 = V_2 -> V_41 -> V_43 [ V_40 ] . V_38 ;
F_23 ( L_4 , V_78 ) ;
switch ( V_78 ) {
case V_79 :
if ( V_38 != V_14 &&
V_2 -> V_41 -> V_43 [ V_40 ] . V_44 != V_80 )
V_2 -> V_41 -> V_81 ++ ;
if ( V_2 -> V_41 -> V_81 ==
V_2 -> V_41 -> V_82 ) {
F_18 ( & V_6 -> V_8 . V_50 ) ;
V_6 -> V_8 . V_49 = false ;
V_2 -> V_41 -> V_81 = 0 ;
F_19 ( & V_6 -> V_8 . V_51 ) ;
}
break;
}
}
static int F_29 ( struct V_1 * V_2 , T_1 V_83 ,
T_1 V_84 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_11 ;
struct V_12 * V_85 ;
T_1 V_86 ;
switch ( V_83 ) {
case V_80 :
V_2 -> V_41 -> V_81 = 0 ;
V_2 -> V_41 -> V_82 = V_87 ;
break;
case V_36 :
V_2 -> V_41 -> V_81 = 0 ;
V_2 -> V_41 -> V_82 = V_88 ;
break;
default:
return - V_89 ;
}
F_30 ( & V_6 -> V_8 . V_51 ) ;
V_11 = F_31 ( V_2 , V_83 , V_90 ) ;
if ( V_11 != V_91 )
return V_11 ;
F_20 ( & V_6 -> V_8 . V_50 , V_52 +
F_21 ( V_92 ) ) ;
V_6 -> V_8 . V_49 = true ;
F_32 ( & V_6 -> V_8 . V_51 ) ;
F_33 ( 3000 , 5000 ) ;
V_11 = F_7 ( V_2 , V_76 ,
V_93 , & V_85 ) ;
if ( V_11 != V_94 )
return V_11 ;
V_86 = V_85 -> V_17 [ V_85 -> V_16 - 1 ] ;
F_9 ( V_85 ) ;
if ( V_84 == V_95 && V_86 == V_83 )
return V_83 ;
else if ( V_84 == V_96 && V_86 != V_83 )
return V_83 ;
return - 1 ;
}
int F_34 ( struct V_1 * V_2 , T_2 V_83 )
{
int V_11 ;
F_23 ( L_5 ) ;
if ( V_83 == V_97 ) {
V_11 = F_35 ( V_2 , V_14 ,
V_98 , NULL , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
}
return 0 ;
}
int F_36 ( struct V_1 * V_2 , T_2 V_83 )
{
int V_11 ;
F_23 ( L_6 ) ;
if ( V_83 == V_99 ) {
V_11 = F_35 ( V_2 , V_14 ,
V_100 , NULL , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_101 * V_102 ;
struct V_103 V_104 ;
struct V_105 * V_106 ;
int V_11 , V_107 ;
V_102 =
F_38 ( sizeof( struct V_101 ) +
sizeof( struct V_103 ) , V_70 ) ;
if ( V_102 == NULL ) {
V_11 = - V_108 ;
goto exit;
}
V_102 -> type = V_109 ;
V_102 -> V_110 = sizeof( struct V_103 ) ;
V_104 . V_111 = V_2 -> V_41 -> V_112 ;
V_104 . V_113 = V_114 ;
memcpy ( V_102 -> V_115 , & V_104 , sizeof( struct V_103 ) ) ;
V_11 = F_39 ( V_2 , V_116 , 1 ,
sizeof( struct V_101 ) +
sizeof( struct V_103 ) ,
V_102 ) ;
if ( V_11 != V_91 )
goto V_117;
V_106 = V_2 -> V_41 -> V_106 ;
if ( ! V_106 )
goto V_117;
memcpy ( V_2 -> V_41 -> V_45 . V_46 , V_37 ,
sizeof( V_37 ) ) ;
V_107 = F_40 ( V_118 , V_119 ) ;
if ( V_107 >= V_119 ) {
V_11 = - V_120 ;
goto V_117;
}
F_41 ( V_2 -> V_41 -> V_45 . V_121 ,
sizeof( V_2 -> V_41 -> V_45 . V_121 ) ,
L_7 , L_8 , V_107 ) ;
V_11 = F_42 ( V_2 ) ;
if ( V_11 != V_94 )
goto exit;
V_11 = F_31 ( V_2 , V_2 -> V_41 -> V_106 -> V_111 ,
V_90 ) ;
if ( V_11 != V_91 )
goto exit;
return 0 ;
V_117:
F_43 ( V_102 ) ;
exit:
return V_11 ;
}
int F_44 ( struct V_1 * V_2 )
{
T_1 V_122 [ 2 ] ;
int V_11 ;
int V_123 = 0 ;
F_23 ( L_9 ) ;
V_11 = F_37 ( V_2 ) ;
if ( V_11 != 0 )
return V_11 ;
V_122 [ 0 ] = V_80 ;
V_122 [ 1 ] = V_99 ;
V_11 = F_45 ( V_2 , V_76 ,
V_124 ,
V_122 , sizeof( V_122 ) ) ;
if ( V_11 != V_94 )
return V_11 ;
V_11 = F_29 ( V_2 , V_80 ,
V_95 ) ;
if ( V_11 == V_80 ) {
F_46 ( V_2 -> V_62 , V_80 , V_125 ) ;
V_123 ++ ;
}
V_11 = F_29 ( V_2 , V_99 ,
V_95 ) ;
if ( V_11 == V_99 ) {
F_46 ( V_2 -> V_62 , V_99 ,
V_97 ) ;
V_123 ++ ;
F_6 ( V_2 ) ;
}
return ! V_123 ;
}
int F_47 ( struct V_1 * V_2 , T_2 V_83 ,
T_1 * V_126 , T_3 V_127 ,
T_4 V_57 , void * V_58 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_23 ( L_10 ) ;
switch ( V_83 ) {
case V_99 :
V_6 -> V_8 . V_57 = V_57 ;
V_6 -> V_8 . V_58 = V_58 ;
F_20 ( & V_6 -> V_8 . V_55 , V_52 +
F_21 ( V_6 -> V_8 . V_18 ) ) ;
V_6 -> V_8 . V_56 = true ;
return F_35 ( V_2 , V_14 ,
V_54 , V_126 ,
V_127 ) ;
default:
return - V_120 ;
}
}
static void F_48 ( unsigned long V_17 )
{
T_1 V_122 = 0x01 ;
struct V_5 * V_6 = (struct V_5 * ) V_17 ;
F_23 ( L_10 ) ;
V_6 -> V_8 . V_56 = false ;
if ( ! V_6 -> V_8 . V_128 ) {
V_6 -> V_8 . V_128 = true ;
F_35 ( V_6 -> V_129 -> V_2 , V_14 ,
V_100 , NULL , 0 ) ;
} else {
V_6 -> V_8 . V_128 = false ;
F_35 ( V_6 -> V_129 -> V_2 , V_30 ,
V_130 , & V_122 , 1 ) ;
}
V_6 -> V_8 . V_57 ( V_6 -> V_8 . V_58 , NULL , 0 , - V_131 ) ;
}
static void F_49 ( unsigned long V_17 )
{
struct V_5 * V_6 = (struct V_5 * ) V_17 ;
F_23 ( L_10 ) ;
V_6 -> V_8 . V_49 = false ;
F_19 ( & V_6 -> V_8 . V_51 ) ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_51 ( & V_6 -> V_8 . V_51 ) ;
F_52 ( & V_6 -> V_8 . V_55 ) ;
V_6 -> V_8 . V_55 . V_17 = ( unsigned long ) V_6 ;
V_6 -> V_8 . V_55 . V_132 = F_48 ;
V_6 -> V_8 . V_56 = false ;
F_52 ( & V_6 -> V_8 . V_50 ) ;
V_6 -> V_8 . V_50 . V_17 = ( unsigned long ) V_6 ;
V_6 -> V_8 . V_50 . V_132 =
F_49 ;
V_6 -> V_8 . V_49 = false ;
V_6 -> V_8 . V_128 = false ;
V_6 -> V_8 . V_18 =
F_8 ( V_10 ) ;
return 0 ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_8 . V_56 )
F_18 ( & V_6 -> V_8 . V_55 ) ;
if ( V_6 -> V_8 . V_49 )
F_18 ( & V_6 -> V_8 . V_50 ) ;
V_6 -> V_8 . V_49 = false ;
V_6 -> V_8 . V_56 = false ;
}
