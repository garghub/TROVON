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
goto V_39;
}
F_13 ( V_21 , V_31 ) ;
F_14 ( & V_30 ) ;
V_21 -> V_28 [ V_31 ] . V_43 = V_45 ;
V_21 -> V_28 [ V_31 ] . V_41 = V_46 ;
F_4 ( V_21 , V_31 ) ;
F_5 ( & V_21 -> V_35 -> V_36 ) ;
return 0 ;
V_39:
if ( V_21 -> V_17 -> V_12 && V_21 -> V_17 -> V_12 -> V_47 )
V_21 -> V_17 -> V_12 -> V_47 ( V_2 ) ;
V_19:
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> free )
V_7 -> V_11 -> V_12 -> free ( V_2 ) ;
V_16:
V_21 -> V_28 [ V_31 ] . V_41 = V_46 ;
F_5 ( & V_21 -> V_35 -> V_36 ) ;
return V_8 ;
}
static void F_15 ( struct V_48 * V_49 )
{
struct V_3 * V_4 =
F_16 ( V_49 , struct V_3 , V_50 . V_49 ) ;
struct V_51 * V_52 = V_4 -> V_52 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
F_8 ( V_4 -> V_40 , L_6 ,
V_52 -> V_11 -> V_53 . V_54 ,
V_52 -> V_55 ? L_7 : L_8 ,
V_4 -> V_56 ? L_9 : L_10 ) ;
if ( V_4 -> V_56 == 1 ) {
V_4 -> V_56 = 0 ;
F_17 ( V_4 , V_33 ,
V_57 ) ;
}
F_5 ( & V_4 -> V_9 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_51 * V_58 = V_4 -> V_58 ;
struct V_51 * V_52 = V_4 -> V_52 ;
int V_31 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_2 -> V_20 == V_32 )
V_31 = V_33 ;
else
V_31 = V_34 ;
F_19 ( V_4 , V_31 ) ;
F_20 ( V_52 , 1 , V_2 -> V_20 ) ;
if ( ! V_58 -> V_59 )
V_58 -> V_60 = 0 ;
if ( ! V_52 -> V_59 )
V_52 -> V_60 = 0 ;
if ( V_4 -> V_17 -> V_12 && V_4 -> V_17 -> V_12 -> V_47 )
V_4 -> V_17 -> V_12 -> V_47 ( V_2 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> free )
V_7 -> V_11 -> V_12 -> free ( V_2 ) ;
if ( V_2 -> V_20 == V_32 ) {
if ( F_21 ( V_4 ) ) {
F_17 ( V_4 ,
V_33 ,
V_57 ) ;
} else {
V_4 -> V_56 = 1 ;
F_22 ( V_61 ,
& V_4 -> V_50 ,
F_23 ( V_4 -> V_62 ) ) ;
}
} else {
F_17 ( V_4 ,
V_34 ,
V_57 ) ;
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
F_28 ( V_21 , V_31 , V_57 ) ;
V_21 -> V_28 [ V_31 ] . V_43 = V_63 ;
V_21 -> V_28 [ V_31 ] . V_41 = V_46 ;
F_12 ( V_21 , V_31 ) ;
V_21 -> V_28 [ V_31 ] . V_38 = NULL ;
if ( V_21 -> V_17 -> V_12 && V_21 -> V_17 -> V_12 -> V_47 )
V_21 -> V_17 -> V_12 -> V_47 ( V_2 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> free )
V_7 -> V_11 -> V_12 -> free ( V_2 ) ;
F_5 ( & V_21 -> V_35 -> V_36 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , int V_64 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_51 * V_52 = V_4 -> V_52 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_65 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_65 ( V_2 , V_64 ) ;
if ( V_8 < 0 )
goto V_16;
}
switch ( V_64 ) {
case V_66 :
F_20 ( V_52 , 0 , V_2 -> V_20 ) ;
break;
case V_67 :
F_20 ( V_52 , 1 , V_2 -> V_20 ) ;
break;
}
V_16:
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_30 ( struct V_1 * V_2 , int V_64 )
{
struct V_3 * V_21 = V_2 -> V_5 ;
struct V_6 * V_7 = V_21 -> V_7 ;
int V_8 = 0 , V_31 ;
if ( V_64 == V_68 ||
V_64 == V_69 ) {
if ( V_7 -> V_11 -> V_12 &&
V_7 -> V_11 -> V_12 -> V_65 )
return V_7 -> V_11 -> V_12 -> V_65 ( V_2 ,
V_64 ) ;
}
if ( V_2 -> V_20 == V_32 )
V_31 = V_33 ;
else
V_31 = V_34 ;
F_2 ( & V_21 -> V_35 -> V_36 , V_37 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_65 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_65 ( V_2 , V_64 ) ;
if ( V_8 < 0 )
goto V_16;
}
V_21 -> V_28 [ V_31 ] . V_41 = V_42 ;
V_8 = F_31 ( V_21 , V_31 , V_64 ) ;
switch ( V_64 ) {
case V_66 :
case V_70 :
case V_71 :
V_21 -> V_28 [ V_31 ] . V_43 = V_72 ;
break;
case V_67 :
case V_73 :
V_21 -> V_28 [ V_31 ] . V_43 = V_74 ;
break;
case V_75 :
V_21 -> V_28 [ V_31 ] . V_43 = V_76 ;
break;
}
V_16:
V_21 -> V_28 [ V_31 ] . V_41 = V_46 ;
F_5 ( & V_21 -> V_35 -> V_36 ) ;
return V_8 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_79 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_79 ( V_2 , V_78 ) ;
if ( V_8 < 0 )
goto V_80;
}
if ( V_4 -> V_17 -> V_12 && V_4 -> V_17 -> V_12 -> V_79 ) {
V_8 = V_4 -> V_17 -> V_12 -> V_79 ( V_2 ) ;
if ( V_8 < 0 )
goto V_80;
}
if ( V_2 -> V_20 == V_32 )
F_17 ( V_4 , V_33 ,
V_81 ) ;
else
F_17 ( V_4 , V_34 ,
V_81 ) ;
V_4 -> V_56 = 0 ;
F_5 ( & V_4 -> V_9 ) ;
F_33 ( & V_4 -> V_50 ) ;
return V_8 ;
V_80:
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
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
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_79 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_79 ( V_2 , V_78 ) ;
if ( V_8 < 0 )
goto V_16;
}
if ( V_21 -> V_17 -> V_12 && V_21 -> V_17 -> V_12 -> V_79 ) {
V_8 = V_21 -> V_17 -> V_12 -> V_79 ( V_2 ) ;
if ( V_8 < 0 )
goto V_16;
}
memset ( & V_21 -> V_28 [ V_23 -> V_31 ] . V_82 , 0 ,
sizeof( struct V_83 ) ) ;
V_21 -> V_28 [ V_31 ] . V_41 = V_42 ;
V_8 = F_35 ( V_21 , V_31 ) ;
if ( V_8 < 0 )
goto V_16;
V_8 = F_36 ( V_21 , V_31 ) ;
if ( V_8 < 0 )
goto V_16;
F_28 ( V_21 , V_31 , V_81 ) ;
V_21 -> V_28 [ V_31 ] . V_43 = V_84 ;
V_16:
V_21 -> V_28 [ V_31 ] . V_41 = V_46 ;
F_5 ( & V_21 -> V_35 -> V_36 ) ;
return V_8 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_85 * V_78 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_86 )
V_8 = V_7 -> V_11 -> V_12 -> V_86 ( V_2 , V_78 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_87 * V_88 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_89 )
V_8 = V_7 -> V_11 -> V_12 -> V_89 ( V_2 , V_88 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_92 )
V_8 = V_7 -> V_11 -> V_12 -> V_92 ( V_2 , V_91 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_93 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_94 )
V_8 = V_7 -> V_11 -> V_12 -> V_94 ( V_2 , V_93 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_95 * V_96 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_97 )
V_7 -> V_11 -> V_12 -> V_97 ( V_2 , V_96 ) ;
F_5 ( & V_4 -> V_9 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
char T_2 * V_98 , T_1 V_99 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_100 )
V_8 = V_7 -> V_11 -> V_12 -> V_100 ( V_2 , V_98 , V_99 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_103 )
V_8 = V_7 -> V_11 -> V_12 -> V_103 ( V_2 , V_102 ) ;
return V_8 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_104 )
V_8 = V_7 -> V_11 -> V_12 -> V_104 ( V_2 , V_102 ) ;
return V_8 ;
}
int F_45 ( struct V_3 * V_4 , int V_105 )
{
struct V_106 * V_91 = V_4 -> V_91 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_51 * V_52 = V_4 -> V_52 ;
struct V_51 * V_58 = V_4 -> V_58 ;
struct V_107 * V_108 ;
struct V_109 * V_110 ;
char V_111 [ 64 ] ;
int V_8 = 0 , V_20 = 0 ;
if ( V_4 -> V_112 > 1 ) {
F_26 ( V_4 -> V_35 -> V_40 , L_12 ) ;
return - V_113 ;
}
snprintf ( V_111 , sizeof( V_111 ) , L_13 ,
V_4 -> V_17 -> V_54 , V_52 -> V_15 , V_105 ) ;
if ( V_52 -> V_11 -> V_53 . V_114 )
V_20 = V_32 ;
else if ( V_52 -> V_11 -> V_115 . V_114 )
V_20 = V_116 ;
else
return - V_113 ;
V_108 = F_46 ( sizeof( * V_108 ) , V_117 ) ;
if ( V_108 == NULL ) {
F_47 ( V_118 L_14 ) ;
return - V_119 ;
}
V_108 -> V_120 = F_48 ( V_4 -> V_35 -> V_40 , sizeof( V_121 ) ,
V_117 ) ;
if ( V_108 -> V_120 == NULL ) {
F_26 ( V_4 -> V_35 -> V_40 , L_15 ) ;
V_8 = - V_119 ;
goto V_122;
}
if ( V_4 -> V_17 -> V_123 ) {
snprintf ( V_111 , sizeof( V_111 ) , L_16 ,
V_4 -> V_17 -> V_54 ) ;
V_8 = F_49 ( V_4 -> V_35 -> V_124 , V_111 , V_105 ,
V_4 -> V_17 -> V_125 ,
V_4 -> V_17 -> V_126 , & V_110 ) ;
if ( V_8 < 0 ) {
F_26 ( V_4 -> V_35 -> V_40 , L_17 ,
V_4 -> V_17 -> V_15 ) ;
goto V_122;
}
V_4 -> V_24 = V_110 ;
V_4 -> V_127 = 1 ;
if ( V_4 -> V_17 -> V_125 )
V_110 -> V_25 [ V_33 ] . V_26 -> V_5 = V_4 ;
else if ( V_4 -> V_17 -> V_126 )
V_110 -> V_25 [ V_34 ] . V_26 -> V_5 = V_4 ;
memcpy ( V_108 -> V_120 , & V_128 , sizeof( V_128 ) ) ;
} else
memcpy ( V_108 -> V_120 , & V_121 , sizeof( V_121 ) ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_100 )
V_108 -> V_120 -> V_100 = F_42 ;
F_50 ( & V_108 -> V_129 ) ;
V_8 = F_51 ( V_4 -> V_35 -> V_124 , V_105 , V_20 , V_108 ) ;
if ( V_8 < 0 ) {
F_3 ( L_18 ,
V_91 -> V_14 . V_15 ) ;
goto V_122;
}
F_52 ( & V_4 -> V_50 , F_15 ) ;
V_4 -> V_108 = V_108 ;
V_108 -> V_5 = V_4 ;
F_53 ( V_130 L_19 , V_52 -> V_15 ,
V_58 -> V_15 ) ;
return V_8 ;
V_122:
F_54 ( V_108 ) ;
return V_8 ;
}
