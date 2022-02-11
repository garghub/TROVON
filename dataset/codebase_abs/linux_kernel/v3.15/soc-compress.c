static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_13 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_13 ( V_2 ) ;
if ( V_8 < 0 ) {
F_3 ( L_1 , V_7 -> V_14 ) ;
goto V_15;
}
}
if ( V_4 -> V_16 -> V_12 && V_4 -> V_16 -> V_12 -> V_17 ) {
V_8 = V_4 -> V_16 -> V_12 -> V_17 ( V_2 ) ;
if ( V_8 < 0 ) {
F_3 ( L_2 , V_4 -> V_16 -> V_14 ) ;
goto V_18;
}
}
F_4 ( V_4 , V_2 -> V_19 ) ;
F_5 ( & V_4 -> V_9 ) ;
return 0 ;
V_18:
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> free )
V_7 -> V_11 -> V_12 -> free ( V_2 ) ;
V_15:
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_20 = V_2 -> V_5 ;
struct V_21 * V_22 = V_20 -> V_23 -> V_24 [ 0 ] . V_25 ;
struct V_6 * V_7 = V_20 -> V_7 ;
struct V_26 * V_27 ;
struct V_28 * V_29 ;
int V_30 ;
int V_8 = 0 ;
if ( V_2 -> V_19 == V_31 )
V_30 = V_32 ;
else
V_30 = V_33 ;
F_2 ( & V_20 -> V_34 -> V_35 , V_36 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_13 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_13 ( V_2 ) ;
if ( V_8 < 0 ) {
F_3 ( L_1 , V_7 -> V_14 ) ;
goto V_15;
}
}
if ( V_20 -> V_16 -> V_12 && V_20 -> V_16 -> V_12 -> V_17 ) {
V_8 = V_20 -> V_16 -> V_12 -> V_17 ( V_2 ) ;
if ( V_8 < 0 ) {
F_3 ( L_2 , V_20 -> V_16 -> V_14 ) ;
goto V_18;
}
}
V_20 -> V_27 [ V_30 ] . V_37 = V_22 -> V_37 ;
if ( F_7 ( V_20 , V_30 , & V_29 ) <= 0 ) {
F_8 ( V_20 -> V_38 , L_3 ,
V_20 -> V_16 -> V_14 , V_30 ? L_4 : L_5 ) ;
}
F_9 ( V_20 , V_30 , & V_29 , 1 ) ;
V_20 -> V_27 [ V_30 ] . V_39 = V_40 ;
V_8 = F_10 ( V_20 , V_30 ) ;
if ( V_8 < 0 ) {
F_11 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_27 -> V_41 = V_42 ;
F_12 ( V_20 , V_30 ) ;
V_20 -> V_27 [ V_30 ] . V_37 = NULL ;
goto V_43;
}
F_13 ( V_20 , V_30 ) ;
F_14 ( & V_29 ) ;
V_20 -> V_27 [ V_30 ] . V_41 = V_44 ;
V_20 -> V_27 [ V_30 ] . V_39 = V_45 ;
F_4 ( V_20 , V_30 ) ;
F_5 ( & V_20 -> V_34 -> V_35 ) ;
return 0 ;
V_43:
if ( V_20 -> V_16 -> V_12 && V_20 -> V_16 -> V_12 -> V_46 )
V_20 -> V_16 -> V_12 -> V_46 ( V_2 ) ;
V_18:
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> free )
V_7 -> V_11 -> V_12 -> free ( V_2 ) ;
V_15:
V_20 -> V_27 [ V_30 ] . V_39 = V_45 ;
F_5 ( & V_20 -> V_34 -> V_35 ) ;
return V_8 ;
}
static void F_15 ( struct V_47 * V_48 )
{
struct V_3 * V_4 =
F_16 ( V_48 , struct V_3 , V_49 . V_48 ) ;
struct V_50 * V_51 = V_4 -> V_51 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
F_8 ( V_4 -> V_38 , L_6 ,
V_51 -> V_11 -> V_52 . V_53 ,
V_51 -> V_54 ? L_7 : L_8 ,
V_4 -> V_55 ? L_9 : L_10 ) ;
if ( V_4 -> V_55 == 1 ) {
V_4 -> V_55 = 0 ;
F_17 ( V_4 , V_32 ,
V_56 ) ;
}
F_5 ( & V_4 -> V_9 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_50 * V_57 = V_4 -> V_57 ;
struct V_50 * V_51 = V_4 -> V_51 ;
int V_30 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_2 -> V_19 == V_31 )
V_30 = V_32 ;
else
V_30 = V_33 ;
F_19 ( V_4 , V_30 ) ;
F_20 ( V_51 , 1 , V_2 -> V_19 ) ;
if ( ! V_57 -> V_58 )
V_57 -> V_59 = 0 ;
if ( ! V_51 -> V_58 )
V_51 -> V_59 = 0 ;
if ( V_4 -> V_16 -> V_12 && V_4 -> V_16 -> V_12 -> V_46 )
V_4 -> V_16 -> V_12 -> V_46 ( V_2 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> free )
V_7 -> V_11 -> V_12 -> free ( V_2 ) ;
V_57 -> V_37 = NULL ;
if ( V_2 -> V_19 == V_31 ) {
if ( F_21 ( V_4 ) ) {
F_17 ( V_4 ,
V_32 ,
V_56 ) ;
} else {
V_4 -> V_55 = 1 ;
F_22 ( V_60 ,
& V_4 -> V_49 ,
F_23 ( V_4 -> V_61 ) ) ;
}
} else {
F_17 ( V_4 ,
V_33 ,
V_56 ) ;
}
F_5 ( & V_4 -> V_9 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_20 = V_2 -> V_5 ;
struct V_6 * V_7 = V_20 -> V_7 ;
struct V_26 * V_27 ;
int V_30 , V_8 ;
F_2 ( & V_20 -> V_34 -> V_35 , V_36 ) ;
if ( V_2 -> V_19 == V_31 )
V_30 = V_32 ;
else
V_30 = V_33 ;
F_19 ( V_20 , V_30 ) ;
V_20 -> V_27 [ V_30 ] . V_39 = V_40 ;
V_8 = F_25 ( V_20 , V_30 ) ;
if ( V_8 < 0 )
F_26 ( V_20 -> V_38 , L_11 , V_8 ) ;
V_8 = F_27 ( V_20 , V_30 ) ;
F_11 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_27 -> V_41 = V_42 ;
if ( V_30 == V_32 )
F_28 ( V_20 , V_30 , V_56 ) ;
else
F_28 ( V_20 , V_30 , V_56 ) ;
V_20 -> V_27 [ V_30 ] . V_41 = V_62 ;
V_20 -> V_27 [ V_30 ] . V_39 = V_45 ;
F_12 ( V_20 , V_30 ) ;
V_20 -> V_27 [ V_30 ] . V_37 = NULL ;
if ( V_20 -> V_16 -> V_12 && V_20 -> V_16 -> V_12 -> V_46 )
V_20 -> V_16 -> V_12 -> V_46 ( V_2 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> free )
V_7 -> V_11 -> V_12 -> free ( V_2 ) ;
F_5 ( & V_20 -> V_34 -> V_35 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 , int V_63 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_50 * V_51 = V_4 -> V_51 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_64 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_64 ( V_2 , V_63 ) ;
if ( V_8 < 0 )
goto V_15;
}
switch ( V_63 ) {
case V_65 :
F_20 ( V_51 , 0 , V_2 -> V_19 ) ;
break;
case V_66 :
F_20 ( V_51 , 1 , V_2 -> V_19 ) ;
break;
}
V_15:
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_30 ( struct V_1 * V_2 , int V_63 )
{
struct V_3 * V_20 = V_2 -> V_5 ;
struct V_6 * V_7 = V_20 -> V_7 ;
int V_8 = 0 , V_30 ;
if ( V_63 == V_67 ||
V_63 == V_68 ) {
if ( V_7 -> V_11 -> V_12 &&
V_7 -> V_11 -> V_12 -> V_64 )
return V_7 -> V_11 -> V_12 -> V_64 ( V_2 , V_63 ) ;
}
if ( V_2 -> V_19 == V_31 )
V_30 = V_32 ;
else
V_30 = V_33 ;
F_2 ( & V_20 -> V_34 -> V_35 , V_36 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_64 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_64 ( V_2 , V_63 ) ;
if ( V_8 < 0 )
goto V_15;
}
V_20 -> V_27 [ V_30 ] . V_39 = V_40 ;
V_8 = F_31 ( V_20 , V_30 , V_63 ) ;
switch ( V_63 ) {
case V_65 :
case V_69 :
case V_70 :
V_20 -> V_27 [ V_30 ] . V_41 = V_71 ;
break;
case V_66 :
case V_72 :
V_20 -> V_27 [ V_30 ] . V_41 = V_73 ;
break;
case V_74 :
V_20 -> V_27 [ V_30 ] . V_41 = V_75 ;
break;
}
V_15:
V_20 -> V_27 [ V_30 ] . V_39 = V_45 ;
F_5 ( & V_20 -> V_34 -> V_35 ) ;
return V_8 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_78 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_78 ( V_2 , V_77 ) ;
if ( V_8 < 0 )
goto V_79;
}
if ( V_4 -> V_16 -> V_12 && V_4 -> V_16 -> V_12 -> V_78 ) {
V_8 = V_4 -> V_16 -> V_12 -> V_78 ( V_2 ) ;
if ( V_8 < 0 )
goto V_79;
}
if ( V_2 -> V_19 == V_31 )
F_17 ( V_4 , V_32 ,
V_80 ) ;
else
F_17 ( V_4 , V_33 ,
V_80 ) ;
V_4 -> V_55 = 0 ;
F_5 ( & V_4 -> V_9 ) ;
F_33 ( & V_4 -> V_49 ) ;
return V_8 ;
V_79:
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
struct V_3 * V_20 = V_2 -> V_5 ;
struct V_21 * V_22 = V_20 -> V_23 -> V_24 [ 0 ] . V_25 ;
struct V_6 * V_7 = V_20 -> V_7 ;
int V_8 = 0 , V_30 ;
if ( V_2 -> V_19 == V_31 )
V_30 = V_32 ;
else
V_30 = V_33 ;
F_2 ( & V_20 -> V_34 -> V_35 , V_36 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_78 ) {
V_8 = V_7 -> V_11 -> V_12 -> V_78 ( V_2 , V_77 ) ;
if ( V_8 < 0 )
goto V_15;
}
if ( V_20 -> V_16 -> V_12 && V_20 -> V_16 -> V_12 -> V_78 ) {
V_8 = V_20 -> V_16 -> V_12 -> V_78 ( V_2 ) ;
if ( V_8 < 0 )
goto V_15;
}
memset ( & V_20 -> V_27 [ V_22 -> V_30 ] . V_81 , 0 ,
sizeof( struct V_82 ) ) ;
V_20 -> V_27 [ V_30 ] . V_39 = V_40 ;
V_8 = F_35 ( V_20 , V_30 ) ;
if ( V_8 < 0 )
goto V_15;
V_8 = F_36 ( V_20 , V_30 ) ;
if ( V_8 < 0 )
goto V_15;
if ( V_30 == V_32 )
F_28 ( V_20 , V_30 , V_80 ) ;
else
F_28 ( V_20 , V_30 , V_80 ) ;
V_20 -> V_27 [ V_30 ] . V_41 = V_83 ;
V_15:
V_20 -> V_27 [ V_30 ] . V_39 = V_45 ;
F_5 ( & V_20 -> V_34 -> V_35 ) ;
return V_8 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_84 * V_77 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_85 )
V_8 = V_7 -> V_11 -> V_12 -> V_85 ( V_2 , V_77 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_86 * V_87 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_88 )
V_8 = V_7 -> V_11 -> V_12 -> V_88 ( V_2 , V_87 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_89 * V_90 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_91 )
V_8 = V_7 -> V_11 -> V_12 -> V_91 ( V_2 , V_90 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_40 ( struct V_1 * V_2 , T_1 V_92 )
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
static int F_41 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_96 )
V_7 -> V_11 -> V_12 -> V_96 ( V_2 , V_95 ) ;
F_5 ( & V_4 -> V_9 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
char T_2 * V_97 , T_1 V_98 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
F_2 ( & V_4 -> V_9 , V_4 -> V_10 ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_99 )
V_8 = V_7 -> V_11 -> V_12 -> V_99 ( V_2 , V_97 , V_98 ) ;
F_5 ( & V_4 -> V_9 ) ;
return V_8 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_102 )
V_8 = V_7 -> V_11 -> V_12 -> V_102 ( V_2 , V_101 ) ;
return V_8 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_100 * V_101 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 = 0 ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_103 )
V_8 = V_7 -> V_11 -> V_12 -> V_103 ( V_2 , V_101 ) ;
return V_8 ;
}
int F_45 ( struct V_3 * V_4 , int V_104 )
{
struct V_105 * V_90 = V_4 -> V_90 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_50 * V_51 = V_4 -> V_51 ;
struct V_50 * V_57 = V_4 -> V_57 ;
struct V_106 * V_107 ;
struct V_108 * V_109 ;
char V_110 [ 64 ] ;
int V_8 = 0 , V_19 = 0 ;
snprintf ( V_110 , sizeof( V_110 ) , L_12 ,
V_4 -> V_16 -> V_53 , V_51 -> V_14 , V_104 ) ;
if ( V_51 -> V_11 -> V_52 . V_111 )
V_19 = V_31 ;
else if ( V_51 -> V_11 -> V_112 . V_111 )
V_19 = V_113 ;
else
return - V_114 ;
V_107 = F_46 ( sizeof( * V_107 ) , V_115 ) ;
if ( V_107 == NULL ) {
F_47 ( V_116 L_13 ) ;
return - V_117 ;
}
V_107 -> V_118 = F_48 ( V_4 -> V_34 -> V_38 , sizeof( V_119 ) ,
V_115 ) ;
if ( V_107 -> V_118 == NULL ) {
F_26 ( V_4 -> V_34 -> V_38 , L_14 ) ;
V_8 = - V_117 ;
goto V_120;
}
if ( V_4 -> V_16 -> V_121 ) {
snprintf ( V_110 , sizeof( V_110 ) , L_15 ,
V_4 -> V_16 -> V_53 ) ;
V_8 = F_49 ( V_4 -> V_34 -> V_122 , V_110 , V_104 ,
1 , 0 , & V_109 ) ;
if ( V_8 < 0 ) {
F_26 ( V_4 -> V_34 -> V_38 , L_16 ,
V_4 -> V_16 -> V_14 ) ;
goto V_120;
}
V_4 -> V_23 = V_109 ;
V_4 -> V_123 = 1 ;
V_109 -> V_24 [ V_32 ] . V_25 -> V_5 = V_4 ;
V_109 -> V_24 [ V_33 ] . V_25 -> V_5 = V_4 ;
memcpy ( V_107 -> V_118 , & V_124 , sizeof( V_124 ) ) ;
} else
memcpy ( V_107 -> V_118 , & V_119 , sizeof( V_119 ) ) ;
if ( V_7 -> V_11 -> V_12 && V_7 -> V_11 -> V_12 -> V_99 )
V_107 -> V_118 -> V_99 = F_42 ;
F_50 ( & V_107 -> V_125 ) ;
V_8 = F_51 ( V_4 -> V_34 -> V_122 , V_104 , V_19 , V_107 ) ;
if ( V_8 < 0 ) {
F_3 ( L_17 ,
V_90 -> V_14 ) ;
goto V_120;
}
F_52 ( & V_4 -> V_49 , F_15 ) ;
V_4 -> V_107 = V_107 ;
V_107 -> V_5 = V_4 ;
F_53 ( V_126 L_18 , V_51 -> V_14 ,
V_57 -> V_14 ) ;
return V_8 ;
V_120:
F_54 ( V_107 ) ;
return V_8 ;
}
