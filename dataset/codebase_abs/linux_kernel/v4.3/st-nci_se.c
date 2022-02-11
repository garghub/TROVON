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
return V_11 ;
V_11 = F_12 ( V_2 , V_30 ,
V_32 , V_24 , sizeof( V_24 ) ,
& V_20 ) ;
if ( V_11 < 0 )
return V_11 ;
for ( V_3 = 0 ; V_3 < V_20 -> V_16 ; V_3 ++ ) {
V_27 [ 2 ] = V_20 -> V_17 [ V_3 ] ;
V_11 = F_12 ( V_2 , V_30 ,
V_32 , V_27 ,
sizeof( V_27 ) , & V_21 ) ;
if ( V_11 )
continue;
V_23 = (struct V_22 * ) V_21 -> V_17 ;
if ( V_23 -> V_33 == V_14 &&
V_23 -> V_34 != V_35 ) {
F_13 ( L_1 ,
V_23 -> V_34 ) ;
F_9 ( V_21 ) ;
continue;
}
for ( V_19 = 0 ; ( V_19 < F_14 ( V_36 ) ) &&
( V_36 [ V_19 ] . V_37 != V_23 -> V_33 ) ; V_19 ++ )
;
if ( V_19 < F_14 ( V_36 ) &&
V_36 [ V_19 ] . V_37 == V_23 -> V_33 &&
F_15 ( V_23 -> V_38 ) ) {
V_36 [ V_19 ] . V_39 = V_27 [ 2 ] ;
V_2 -> V_40 -> V_41 [ V_36 [ V_19 ] . V_37 ] =
V_36 [ V_19 ] . V_39 ;
V_2 -> V_40 -> V_42 [ V_36 [ V_19 ] . V_39 ] . V_37 =
V_36 [ V_19 ] . V_37 ;
V_2 -> V_40 -> V_42 [ V_36 [ V_19 ] . V_39 ] . V_43 =
V_23 -> V_34 ;
}
F_9 ( V_21 ) ;
}
memcpy ( V_2 -> V_40 -> V_44 . V_45 , V_36 ,
sizeof( V_36 ) ) ;
F_9 ( V_20 ) ;
return V_11 ;
}
static void F_16 ( struct V_1 * V_2 ,
T_1 V_46 , struct V_12 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_46 ) {
case V_47 :
if ( V_6 -> V_8 . V_48 ) {
if ( ! F_17 ( V_13 ) ) {
F_18 ( & V_6 -> V_8 . V_49 ) ;
V_6 -> V_8 . V_48 = false ;
F_19 ( & V_6 -> V_8 . V_50 ) ;
} else {
F_20 ( & V_6 -> V_8 . V_49 ,
V_51 +
F_21 ( V_52 ) ) ;
}
}
break;
}
}
static int F_22 ( struct V_1 * V_2 ,
T_1 V_46 ,
struct V_12 * V_13 )
{
int V_11 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_23 ( L_2 , V_46 ) ;
switch ( V_46 ) {
case V_53 :
F_18 ( & V_6 -> V_8 . V_54 ) ;
V_6 -> V_8 . V_55 = false ;
V_6 -> V_8 . V_56 ( V_6 -> V_8 . V_57 ,
V_13 -> V_17 , V_13 -> V_16 , 0 ) ;
break;
case V_58 :
F_20 ( & V_6 -> V_8 . V_54 , V_51 +
F_21 ( V_6 -> V_8 . V_18 ) ) ;
break;
}
F_9 ( V_13 ) ;
return V_11 ;
}
static int F_24 ( struct V_1 * V_2 ,
T_1 V_43 , T_1 V_46 ,
struct V_12 * V_13 )
{
int V_11 = 0 ;
struct V_59 * V_60 = & V_2 -> V_61 -> V_60 ;
struct V_62 * V_63 ;
F_23 ( L_3 , V_46 ) ;
switch ( V_46 ) {
case V_64 :
break;
case V_65 :
if ( V_13 -> V_16 < V_66 + 2 &&
V_13 -> V_17 [ 0 ] != V_67 )
return - V_68 ;
V_63 = (struct V_62 * ) F_25 ( V_60 ,
V_13 -> V_16 - 2 , V_69 ) ;
V_63 -> V_70 = V_13 -> V_17 [ 1 ] ;
memcpy ( V_63 -> V_71 , & V_13 -> V_17 [ 2 ] , V_63 -> V_70 ) ;
if ( V_13 -> V_17 [ V_63 -> V_70 + 2 ] !=
V_72 )
return - V_68 ;
V_63 -> V_73 = V_13 -> V_17 [ V_63 -> V_70 + 3 ] ;
memcpy ( V_63 -> V_74 , V_13 -> V_17 +
V_63 -> V_70 + 4 , V_63 -> V_73 ) ;
V_11 = F_26 ( V_2 -> V_61 , V_43 , V_63 ) ;
break;
default:
return 1 ;
}
F_9 ( V_13 ) ;
return V_11 ;
}
void F_27 ( struct V_1 * V_2 , T_1 V_39 ,
T_1 V_46 , struct V_12 * V_13 )
{
T_1 V_37 = V_2 -> V_40 -> V_42 [ V_39 ] . V_37 ;
T_1 V_43 = V_2 -> V_40 -> V_42 [ V_39 ] . V_43 ;
switch ( V_37 ) {
case V_75 :
F_16 ( V_2 , V_46 , V_13 ) ;
break;
case V_14 :
F_22 ( V_2 , V_46 , V_13 ) ;
break;
case V_76 :
F_24 ( V_2 , V_43 , V_46 ,
V_13 ) ;
break;
}
}
void F_28 ( struct V_1 * V_2 , T_1 V_39 , T_1 V_77 ,
struct V_12 * V_13 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_37 = V_2 -> V_40 -> V_42 [ V_39 ] . V_37 ;
F_23 ( L_4 , V_77 ) ;
switch ( V_77 ) {
case V_78 :
if ( V_37 != V_14 &&
V_2 -> V_40 -> V_42 [ V_39 ] . V_43 != V_79 )
V_2 -> V_40 -> V_80 ++ ;
if ( V_2 -> V_40 -> V_80 ==
V_2 -> V_40 -> V_81 ) {
F_18 ( & V_6 -> V_8 . V_49 ) ;
V_6 -> V_8 . V_48 = false ;
V_2 -> V_40 -> V_80 = 0 ;
F_19 ( & V_6 -> V_8 . V_50 ) ;
}
break;
}
}
static int F_29 ( struct V_1 * V_2 , T_1 V_82 ,
T_1 V_83 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_11 ;
struct V_12 * V_84 ;
T_1 V_85 ;
switch ( V_82 ) {
case V_79 :
V_2 -> V_40 -> V_80 = 0 ;
V_2 -> V_40 -> V_81 = V_86 ;
break;
case V_35 :
V_2 -> V_40 -> V_80 = 0 ;
V_2 -> V_40 -> V_81 = V_87 ;
break;
default:
return - V_88 ;
}
F_30 ( & V_6 -> V_8 . V_50 ) ;
V_11 = F_31 ( V_2 , V_82 , V_89 ) ;
if ( V_11 != V_90 )
return V_11 ;
F_20 ( & V_6 -> V_8 . V_49 , V_51 +
F_21 ( V_91 ) ) ;
V_6 -> V_8 . V_48 = true ;
F_32 ( & V_6 -> V_8 . V_50 ) ;
F_33 ( 3000 , 5000 ) ;
V_11 = F_7 ( V_2 , V_75 ,
V_92 , & V_84 ) ;
if ( V_11 != V_93 )
return V_11 ;
V_85 = V_84 -> V_17 [ V_84 -> V_16 - 1 ] ;
F_9 ( V_84 ) ;
if ( V_83 == V_94 && V_85 == V_82 )
return V_82 ;
else if ( V_83 == V_95 && V_85 != V_82 )
return V_82 ;
return - 1 ;
}
int F_34 ( struct V_1 * V_2 , T_2 V_82 )
{
int V_11 ;
F_23 ( L_5 ) ;
if ( V_82 == V_96 ) {
V_11 = F_35 ( V_2 , V_14 ,
V_97 , NULL , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
}
return 0 ;
}
int F_36 ( struct V_1 * V_2 , T_2 V_82 )
{
int V_11 ;
F_23 ( L_6 ) ;
if ( V_82 == V_98 ) {
V_11 = F_35 ( V_2 , V_14 ,
V_99 , NULL , 0 ) ;
if ( V_11 < 0 )
return V_11 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_100 * V_101 ;
struct V_102 V_103 ;
struct V_104 * V_105 ;
int V_11 , V_106 ;
V_101 =
F_38 ( sizeof( struct V_100 ) +
sizeof( struct V_102 ) , V_69 ) ;
if ( V_101 == NULL ) {
V_11 = - V_107 ;
goto exit;
}
V_101 -> type = V_108 ;
V_101 -> V_109 = sizeof( struct V_102 ) ;
V_103 . V_110 = V_2 -> V_40 -> V_111 ;
V_103 . V_112 = V_113 ;
memcpy ( V_101 -> V_114 , & V_103 ,
sizeof( struct V_102 ) ) ;
V_11 = F_39 ( V_2 , V_115 , 1 ,
sizeof( struct V_100 ) +
sizeof( struct V_102 ) ,
V_101 ) ;
if ( V_11 != V_90 )
goto V_116;
V_105 = V_2 -> V_40 -> V_105 ;
if ( ! V_105 )
goto V_116;
memcpy ( V_2 -> V_40 -> V_44 . V_45 , V_36 ,
sizeof( V_36 ) ) ;
V_106 = F_40 ( V_117 , V_118 ) ;
if ( V_106 >= V_118 ) {
V_11 = - V_119 ;
goto V_116;
}
F_41 ( V_2 -> V_40 -> V_44 . V_120 ,
sizeof( V_2 -> V_40 -> V_44 . V_120 ) ,
L_7 , L_8 , V_106 ) ;
V_11 = F_42 ( V_2 ) ;
if ( V_11 != V_93 )
goto V_116;
V_11 = F_31 ( V_2 , V_2 -> V_40 -> V_105 -> V_110 ,
V_89 ) ;
if ( V_11 != V_90 )
goto V_116;
V_116:
F_43 ( V_101 ) ;
exit:
return V_11 ;
}
int F_44 ( struct V_1 * V_2 )
{
T_1 V_121 [ 2 ] ;
int V_11 ;
int V_122 = 0 ;
F_23 ( L_9 ) ;
V_11 = F_37 ( V_2 ) ;
if ( V_11 != 0 )
return V_11 ;
V_121 [ 0 ] = V_79 ;
V_121 [ 1 ] = V_98 ;
V_11 = F_45 ( V_2 , V_75 ,
V_123 ,
V_121 , sizeof( V_121 ) ) ;
if ( V_11 != V_93 )
return V_11 ;
V_11 = F_29 ( V_2 , V_79 ,
V_94 ) ;
if ( V_11 == V_79 ) {
F_46 ( V_2 -> V_61 , V_79 , V_124 ) ;
V_122 ++ ;
}
V_11 = F_29 ( V_2 , V_98 ,
V_94 ) ;
if ( V_11 == V_98 ) {
F_46 ( V_2 -> V_61 , V_98 ,
V_96 ) ;
V_122 ++ ;
F_6 ( V_2 ) ;
}
return ! V_122 ;
}
int F_47 ( struct V_1 * V_2 , T_2 V_82 ,
T_1 * V_125 , T_3 V_126 ,
T_4 V_56 , void * V_57 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_23 ( L_10 ) ;
switch ( V_82 ) {
case V_98 :
V_6 -> V_8 . V_56 = V_56 ;
V_6 -> V_8 . V_57 = V_57 ;
F_20 ( & V_6 -> V_8 . V_54 , V_51 +
F_21 ( V_6 -> V_8 . V_18 ) ) ;
V_6 -> V_8 . V_55 = true ;
return F_35 ( V_2 , V_14 ,
V_53 , V_125 ,
V_126 ) ;
default:
return - V_119 ;
}
}
static void F_48 ( unsigned long V_17 )
{
T_1 V_121 = 0x01 ;
struct V_5 * V_6 = (struct V_5 * ) V_17 ;
F_23 ( L_10 ) ;
V_6 -> V_8 . V_55 = false ;
if ( ! V_6 -> V_8 . V_127 ) {
V_6 -> V_8 . V_127 = true ;
F_35 ( V_6 -> V_128 -> V_2 , V_14 ,
V_99 , NULL , 0 ) ;
} else {
V_6 -> V_8 . V_127 = false ;
F_35 ( V_6 -> V_128 -> V_2 , V_30 ,
V_129 , & V_121 , 1 ) ;
}
V_6 -> V_8 . V_56 ( V_6 -> V_8 . V_57 , NULL , 0 , - V_130 ) ;
}
static void F_49 ( unsigned long V_17 )
{
struct V_5 * V_6 = (struct V_5 * ) V_17 ;
F_23 ( L_10 ) ;
V_6 -> V_8 . V_48 = false ;
F_19 ( & V_6 -> V_8 . V_50 ) ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_51 ( & V_6 -> V_8 . V_50 ) ;
F_52 ( & V_6 -> V_8 . V_54 ) ;
V_6 -> V_8 . V_54 . V_17 = ( unsigned long ) V_6 ;
V_6 -> V_8 . V_54 . V_131 = F_48 ;
V_6 -> V_8 . V_55 = false ;
F_52 ( & V_6 -> V_8 . V_49 ) ;
V_6 -> V_8 . V_49 . V_17 = ( unsigned long ) V_6 ;
V_6 -> V_8 . V_49 . V_131 =
F_49 ;
V_6 -> V_8 . V_48 = false ;
V_6 -> V_8 . V_127 = false ;
V_6 -> V_8 . V_18 =
F_8 ( V_10 ) ;
return 0 ;
}
void F_53 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_6 -> V_8 . V_55 )
F_18 ( & V_6 -> V_8 . V_54 ) ;
if ( V_6 -> V_8 . V_48 )
F_18 ( & V_6 -> V_8 . V_49 ) ;
V_6 -> V_8 . V_48 = false ;
V_6 -> V_8 . V_55 = false ;
}
