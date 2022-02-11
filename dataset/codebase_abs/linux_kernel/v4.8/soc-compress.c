static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_13 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_13 ( V_2 ) ;
if ( V_8 < 0 ) {
F_3 ( L_1 ,
V_7 -> V_14 . V_15 ) ;
goto V_16;
}
}
if ( V_4 -> V_17 -> V_12 && V_4 -> V_17 -> V_12 -> V_18 ) {
V_8 = V_4 -> V_17 -> V_12 -> V_18 ( V_2 ) ;
if ( V_8 < 0 ) {
F_3 ( L_2 , V_4 -> V_17 -> V_15 ) ;
goto V_19;
}
}
F_4 ( V_4 , V_2 -> V_20 ) ;
F_5 ( & V_4 -> V_9 ) ;
return 0 ;
V_19:
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> free )
V_7 -> V_11 -> V_12 -> free ( V_2 ) ;
V_16:
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_21 = V_2 -> V_5 ;
struct V_22 * V_23 = V_21 -> V_24 -> V_25 [ 0 ] . V_26 ;
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
int V_31 ;
int V_8 = 0 ;
if ( V_2 -> V_20 == V_32 )
V_31 = V_33 ;
else
V_31 = V_34 ;
F_2 ( & V_21 -> V_35 -> V_36 , V_37 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_13 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_13 ( V_2 ) ;
if ( V_8 < 0 ) {
F_3 ( L_1 ,
V_7 -> V_14 . V_15 ) ;
goto V_16;
}
}
if ( V_21 -> V_17 -> V_12 && V_21 -> V_17 -> V_12 -> V_18 ) {
V_8 = V_21 -> V_17 -> V_12 -> V_18 ( V_2 ) ;
if ( V_8 < 0 ) {
F_3 ( L_2 , V_21 -> V_17 -> V_15 ) ;
goto V_19;
}
}
V_21 -> V_28 [ V_31 ] . V_38 = V_23 -> V_38 ;
V_8 = F_7 ( V_21 , V_31 , & V_30 ) ;
if ( V_8 < 0 )
goto V_39;
else if ( V_8 == 0 )
F_8 ( V_21 -> V_40 , L_3 ,
V_21 -> V_17 -> V_15 , V_31 ? L_4 : L_5 ) ;
F_9 ( V_21 , V_31 , & V_30 , 1 ) ;
V_21 -> V_28 [ V_31 ] . V_41 = V_42 ;
V_8 = F_10 ( V_21 , V_31 ) ;
if ( V_8 < 0 ) {
F_11 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_28 -> V_43 = V_44 ;
F_12 ( V_21 , V_31 ) ;
V_21 -> V_28 [ V_31 ] . V_38 = NULL ;
goto V_45;
}
F_13 ( V_21 , V_31 ) ;
F_14 ( & V_30 ) ;
V_21 -> V_28 [ V_31 ] . V_43 = V_46 ;
V_21 -> V_28 [ V_31 ] . V_41 = V_47 ;
F_4 ( V_21 , V_31 ) ;
F_5 ( & V_21 -> V_35 -> V_36 ) ;
return 0 ;
V_45:
F_14 ( & V_30 ) ;
V_39:
if ( V_21 -> V_17 -> V_12 && V_21 -> V_17 -> V_12 -> V_48 )
V_21 -> V_17 -> V_12 -> V_48 ( V_2 ) ;
V_19:
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> free )
V_7 -> V_11 -> V_12 -> free ( V_2 ) ;
V_16:
V_21 -> V_28 [ V_31 ] . V_41 = V_47 ;
F_5 ( & V_21 -> V_35 -> V_36 ) ;
return V_8 ;
}
static void F_15 ( struct V_49 * V_50 )
{
struct V_3 * V_4 =
F_16 ( V_50 , struct V_3 , V_51 . V_50 ) ;
struct V_52 * V_53 = V_4 -> V_53 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
F_8 ( V_4 -> V_40 , L_6 ,
V_53 -> V_11 -> V_54 . V_55 ,
V_53 -> V_56 ? L_7 : L_8 ,
V_4 -> V_57 ? L_9 : L_10 ) ;
if ( V_4 -> V_57 == 1 ) {
V_4 -> V_57 = 0 ;
F_17 ( V_4 , V_33 ,
V_58 ) ;
}
F_5 ( & V_4 -> V_9 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_52 * V_59 = V_4 -> V_59 ;
struct V_52 * V_53 = V_4 -> V_53 ;
int V_31 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_2 -> V_20 == V_32 )
V_31 = V_33 ;
else
V_31 = V_34 ;
F_19 ( V_4 , V_31 ) ;
F_20 ( V_53 , 1 , V_2 -> V_20 ) ;
if ( ! V_59 -> V_60 )
V_59 -> V_61 = 0 ;
if ( ! V_53 -> V_60 )
V_53 -> V_61 = 0 ;
if ( V_4 -> V_17 -> V_12 && V_4 -> V_17 -> V_12 -> V_48 )
V_4 -> V_17 -> V_12 -> V_48 ( V_2 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> free )
V_7 -> V_11 -> V_12 -> free ( V_2 ) ;
if ( V_2 -> V_20 == V_32 ) {
if ( F_21 ( V_4 ) ) {
F_17 ( V_4 ,
V_33 ,
V_58 ) ;
} else {
V_4 -> V_57 = 1 ;
F_22 ( V_62 ,
& V_4 -> V_51 ,
F_23 ( V_4 -> V_63 ) ) ;
}
} else {
F_17 ( V_4 ,
V_34 ,
V_58 ) ;
}
F_5 ( & V_4 -> V_9 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_21 = V_2 -> V_5 ;
struct V_6 * V_7 = V_21 -> V_7 ;
struct V_27 * V_28 ;
int V_31 , V_8 ;
F_2 ( & V_21 -> V_35 -> V_36 , V_37 ) ;
if ( V_2 -> V_20 == V_32 )
V_31 = V_33 ;
else
V_31 = V_34 ;
F_19 ( V_21 , V_31 ) ;
V_21 -> V_28 [ V_31 ] . V_41 = V_42 ;
V_8 = F_25 ( V_21 , V_31 ) ;
if ( V_8 < 0 )
F_26 ( V_21 -> V_40 , L_11 , V_8 ) ;
V_8 = F_27 ( V_21 , V_31 ) ;
F_11 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_28 -> V_43 = V_44 ;
F_28 ( V_21 , V_31 , V_58 ) ;
V_21 -> V_28 [ V_31 ] . V_43 = V_64 ;
V_21 -> V_28 [ V_31 ] . V_41 = V_47 ;
F_12 ( V_21 , V_31 ) ;
V_21 -> V_28 [ V_31 ] . V_38 = NULL ;
if ( V_21 -> V_17 -> V_12 && V_21 -> V_17 -> V_12 -> V_48 )
V_21 -> V_17 -> V_12 -> V_48 ( V_2 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> free )
V_7 -> V_11 -> V_12 -> free ( V_2 ) ;
F_5 ( & V_21 -> V_35 -> V_36 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , int V_65 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_52 * V_53 = V_4 -> V_53 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_66 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_66 ( V_2 , V_65 ) ;
if ( V_8 < 0 )
goto V_16;
}
switch ( V_65 ) {
case V_67 :
F_20 ( V_53 , 0 , V_2 -> V_20 ) ;
break;
case V_68 :
F_20 ( V_53 , 1 , V_2 -> V_20 ) ;
break;
}
V_16:
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_30 ( struct V_1 * V_2 , int V_65 )
{
struct V_3 * V_21 = V_2 -> V_5 ;
struct V_6 * V_7 = V_21 -> V_7 ;
int V_8 = 0 , V_31 ;
if ( V_65 == V_69 ||
V_65 == V_70 ) {
if ( V_7 -> V_11 -> V_12 &&
V_7 -> V_11 -> V_12 -> V_66 )
return V_7 -> V_11 -> V_12 -> V_66 ( V_2 ,
V_65 ) ;
}
if ( V_2 -> V_20 == V_32 )
V_31 = V_33 ;
else
V_31 = V_34 ;
F_2 ( & V_21 -> V_35 -> V_36 , V_37 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_66 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_66 ( V_2 , V_65 ) ;
if ( V_8 < 0 )
goto V_16;
}
V_21 -> V_28 [ V_31 ] . V_41 = V_42 ;
V_8 = F_31 ( V_21 , V_31 , V_65 ) ;
switch ( V_65 ) {
case V_67 :
case V_71 :
case V_72 :
V_21 -> V_28 [ V_31 ] . V_43 = V_73 ;
break;
case V_68 :
case V_74 :
V_21 -> V_28 [ V_31 ] . V_43 = V_75 ;
break;
case V_76 :
V_21 -> V_28 [ V_31 ] . V_43 = V_77 ;
break;
}
V_16:
V_21 -> V_28 [ V_31 ] . V_41 = V_47 ;
F_5 ( & V_21 -> V_35 -> V_36 ) ;
return V_8 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_80 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_80 ( V_2 , V_79 ) ;
if ( V_8 < 0 )
goto V_81;
}
if ( V_4 -> V_17 -> V_12 && V_4 -> V_17 -> V_12 -> V_80 ) {
V_8 = V_4 -> V_17 -> V_12 -> V_80 ( V_2 ) ;
if ( V_8 < 0 )
goto V_81;
}
if ( V_2 -> V_20 == V_32 )
F_17 ( V_4 , V_33 ,
V_82 ) ;
else
F_17 ( V_4 , V_34 ,
V_82 ) ;
V_4 -> V_57 = 0 ;
F_5 ( & V_4 -> V_9 ) ;
F_33 ( & V_4 -> V_51 ) ;
return V_8 ;
V_81:
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_78 * V_79 )
{
struct V_3 * V_21 = V_2 -> V_5 ;
struct V_22 * V_23 = V_21 -> V_24 -> V_25 [ 0 ] . V_26 ;
struct V_6 * V_7 = V_21 -> V_7 ;
int V_8 = 0 , V_31 ;
if ( V_2 -> V_20 == V_32 )
V_31 = V_33 ;
else
V_31 = V_34 ;
F_2 ( & V_21 -> V_35 -> V_36 , V_37 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_80 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_80 ( V_2 , V_79 ) ;
if ( V_8 < 0 )
goto V_16;
}
if ( V_21 -> V_17 -> V_12 && V_21 -> V_17 -> V_12 -> V_80 ) {
V_8 = V_21 -> V_17 -> V_12 -> V_80 ( V_2 ) ;
if ( V_8 < 0 )
goto V_16;
}
memset ( & V_21 -> V_28 [ V_23 -> V_31 ] . V_83 , 0 ,
sizeof( struct V_84 ) ) ;
V_21 -> V_28 [ V_31 ] . V_41 = V_42 ;
V_8 = F_35 ( V_21 , V_31 ) ;
if ( V_8 < 0 )
goto V_16;
V_8 = F_36 ( V_21 , V_31 ) ;
if ( V_8 < 0 )
goto V_16;
F_28 ( V_21 , V_31 , V_82 ) ;
V_21 -> V_28 [ V_31 ] . V_43 = V_85 ;
V_16:
V_21 -> V_28 [ V_31 ] . V_41 = V_47 ;
F_5 ( & V_21 -> V_35 -> V_36 ) ;
return V_8 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_86 * V_79 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_87 )
V_8 = V_7 -> V_11 -> V_12 -> V_87 ( V_2 , V_79 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_88 * V_89 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_90 )
V_8 = V_7 -> V_11 -> V_12 -> V_90 ( V_2 , V_89 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_91 * V_92 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_93 )
V_8 = V_7 -> V_11 -> V_12 -> V_93 ( V_2 , V_92 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_94 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_95 )
V_8 = V_7 -> V_11 -> V_12 -> V_95 ( V_2 , V_94 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_96 * V_97 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_98 )
V_8 = V_7 -> V_11 -> V_12 -> V_98 ( V_2 , V_97 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_42 ( struct V_1 * V_2 ,
char T_2 * V_99 , T_1 V_100 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_101 )
V_8 = V_7 -> V_11 -> V_12 -> V_101 ( V_2 , V_99 , V_100 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_104 )
V_8 = V_7 -> V_11 -> V_12 -> V_104 ( V_2 , V_103 ) ;
return V_8 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_105 )
V_8 = V_7 -> V_11 -> V_12 -> V_105 ( V_2 , V_103 ) ;
return V_8 ;
}
int F_45 ( struct V_3 * V_4 , int V_106 )
{
struct V_107 * V_92 = V_4 -> V_92 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_52 * V_53 = V_4 -> V_53 ;
struct V_52 * V_59 = V_4 -> V_59 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
char V_112 [ 64 ] ;
int V_8 = 0 , V_20 = 0 ;
int V_54 = 0 , V_113 = 0 ;
if ( V_4 -> V_114 > 1 ) {
F_26 ( V_4 -> V_35 -> V_40 , L_12 ) ;
return - V_115 ;
}
snprintf ( V_112 , sizeof( V_112 ) , L_13 ,
V_4 -> V_17 -> V_55 , V_53 -> V_15 , V_106 ) ;
if ( V_53 -> V_11 -> V_54 . V_116 )
V_54 = 1 ;
if ( V_53 -> V_11 -> V_113 . V_116 )
V_113 = 1 ;
V_113 = V_113 && V_59 -> V_11 -> V_113 . V_116 ;
V_54 = V_54 && V_59 -> V_11 -> V_54 . V_116 ;
if ( V_54 + V_113 != 1 ) {
F_26 ( V_4 -> V_35 -> V_40 , L_14 ,
V_54 , V_113 ) ;
return - V_115 ;
}
if( V_54 )
V_20 = V_32 ;
else
V_20 = V_117 ;
V_109 = F_46 ( sizeof( * V_109 ) , V_118 ) ;
if ( V_109 == NULL ) {
F_47 ( V_119 L_15 ) ;
return - V_120 ;
}
V_109 -> V_121 = F_48 ( V_4 -> V_35 -> V_40 , sizeof( V_122 ) ,
V_118 ) ;
if ( V_109 -> V_121 == NULL ) {
F_26 ( V_4 -> V_35 -> V_40 , L_16 ) ;
V_8 = - V_120 ;
goto V_123;
}
if ( V_4 -> V_17 -> V_124 ) {
snprintf ( V_112 , sizeof( V_112 ) , L_17 ,
V_4 -> V_17 -> V_55 ) ;
V_8 = F_49 ( V_4 -> V_35 -> V_125 , V_112 , V_106 ,
V_4 -> V_17 -> V_126 ,
V_4 -> V_17 -> V_127 , & V_111 ) ;
if ( V_8 < 0 ) {
F_26 ( V_4 -> V_35 -> V_40 , L_18 ,
V_4 -> V_17 -> V_15 ) ;
goto V_123;
}
V_4 -> V_24 = V_111 ;
V_4 -> V_128 = 1 ;
if ( V_4 -> V_17 -> V_126 )
V_111 -> V_25 [ V_33 ] . V_26 -> V_5 = V_4 ;
else if ( V_4 -> V_17 -> V_127 )
V_111 -> V_25 [ V_34 ] . V_26 -> V_5 = V_4 ;
memcpy ( V_109 -> V_121 , & V_129 , sizeof( V_129 ) ) ;
} else
memcpy ( V_109 -> V_121 , & V_122 , sizeof( V_122 ) ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_101 )
V_109 -> V_121 -> V_101 = F_42 ;
F_50 ( & V_109 -> V_130 ) ;
snprintf ( V_112 , sizeof( V_112 ) , L_13 ,
V_4 -> V_17 -> V_55 ,
V_4 -> V_53 -> V_15 , V_106 ) ;
V_8 = F_51 ( V_4 -> V_35 -> V_125 , V_106 , V_20 ,
V_112 , V_109 ) ;
if ( V_8 < 0 ) {
F_3 ( L_19 ,
V_92 -> V_14 . V_15 ) ;
goto V_123;
}
F_52 ( & V_4 -> V_51 , F_15 ) ;
V_4 -> V_109 = V_109 ;
V_109 -> V_5 = V_4 ;
F_53 ( V_131 L_20 , V_53 -> V_15 ,
V_59 -> V_15 ) ;
return V_8 ;
V_123:
F_54 ( V_109 ) ;
return V_8 ;
}
