static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_8 * V_10 = V_4 -> V_10 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_16 ) {
V_11 = V_7 -> V_14 -> V_15 -> V_16 ( V_2 ) ;
if ( V_11 < 0 ) {
F_3 ( L_1 , V_7 -> V_17 ) ;
goto V_18;
}
}
if ( V_4 -> V_19 -> V_15 && V_4 -> V_19 -> V_15 -> V_20 ) {
V_11 = V_4 -> V_19 -> V_15 -> V_20 ( V_2 ) ;
if ( V_11 < 0 ) {
F_3 ( L_2 , V_4 -> V_19 -> V_17 ) ;
goto V_21;
}
}
if ( V_2 -> V_22 == V_23 ) {
V_9 -> V_24 ++ ;
V_10 -> V_24 ++ ;
} else {
V_9 -> V_25 ++ ;
V_10 -> V_25 ++ ;
}
V_9 -> V_26 ++ ;
V_10 -> V_26 ++ ;
V_4 -> V_27 -> V_26 ++ ;
F_4 ( & V_4 -> V_12 ) ;
return 0 ;
V_21:
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> free )
V_7 -> V_14 -> V_15 -> free ( V_2 ) ;
V_18:
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_28 = V_2 -> V_5 ;
struct V_29 * V_30 = V_28 -> V_31 -> V_32 [ 0 ] . V_33 ;
struct V_6 * V_7 = V_28 -> V_7 ;
struct V_8 * V_9 = V_28 -> V_9 ;
struct V_8 * V_10 = V_28 -> V_10 ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
int V_38 ;
int V_11 = 0 ;
if ( V_2 -> V_22 == V_23 )
V_38 = V_39 ;
else
V_38 = V_40 ;
F_2 ( & V_28 -> V_41 -> V_42 , V_43 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_16 ) {
V_11 = V_7 -> V_14 -> V_15 -> V_16 ( V_2 ) ;
if ( V_11 < 0 ) {
F_3 ( L_1 , V_7 -> V_17 ) ;
goto V_18;
}
}
if ( V_28 -> V_19 -> V_15 && V_28 -> V_19 -> V_15 -> V_20 ) {
V_11 = V_28 -> V_19 -> V_15 -> V_20 ( V_2 ) ;
if ( V_11 < 0 ) {
F_3 ( L_2 , V_28 -> V_19 -> V_17 ) ;
goto V_21;
}
}
V_28 -> V_35 [ V_38 ] . V_44 = V_30 -> V_44 ;
if ( F_6 ( V_28 , V_38 , & V_37 ) <= 0 ) {
F_7 ( V_28 -> V_45 , L_3 ,
V_28 -> V_19 -> V_17 , V_38 ? L_4 : L_5 ) ;
}
F_8 ( V_28 , V_38 , & V_37 , 1 ) ;
V_28 -> V_35 [ V_38 ] . V_46 = V_47 ;
V_11 = F_9 ( V_28 , V_38 ) ;
if ( V_11 < 0 ) {
F_10 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_35 -> V_48 = V_49 ;
F_11 ( V_28 , V_38 ) ;
V_28 -> V_35 [ V_38 ] . V_44 = NULL ;
goto V_50;
}
F_12 ( V_28 , V_38 ) ;
F_13 ( & V_37 ) ;
V_28 -> V_35 [ V_38 ] . V_48 = V_51 ;
V_28 -> V_35 [ V_38 ] . V_46 = V_52 ;
if ( V_2 -> V_22 == V_23 ) {
V_9 -> V_24 ++ ;
V_10 -> V_24 ++ ;
} else {
V_9 -> V_25 ++ ;
V_10 -> V_25 ++ ;
}
V_9 -> V_26 ++ ;
V_10 -> V_26 ++ ;
V_28 -> V_27 -> V_26 ++ ;
F_4 ( & V_28 -> V_41 -> V_42 ) ;
return 0 ;
V_50:
if ( V_28 -> V_19 -> V_15 && V_28 -> V_19 -> V_15 -> V_53 )
V_28 -> V_19 -> V_15 -> V_53 ( V_2 ) ;
V_21:
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> free )
V_7 -> V_14 -> V_15 -> free ( V_2 ) ;
V_18:
V_28 -> V_35 [ V_38 ] . V_46 = V_52 ;
F_4 ( & V_28 -> V_41 -> V_42 ) ;
return V_11 ;
}
static void F_14 ( struct V_54 * V_55 )
{
struct V_3 * V_4 =
F_15 ( V_55 , struct V_3 , V_56 . V_55 ) ;
struct V_8 * V_10 = V_4 -> V_10 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
F_7 ( V_4 -> V_45 , L_6 ,
V_10 -> V_14 -> V_57 . V_58 ,
V_10 -> V_24 ? L_7 : L_8 ,
V_4 -> V_59 ? L_9 : L_10 ) ;
if ( V_4 -> V_59 == 1 ) {
V_4 -> V_59 = 0 ;
F_16 ( V_4 , V_39 ,
V_60 ) ;
}
F_4 ( & V_4 -> V_12 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_8 * V_10 = V_4 -> V_10 ;
struct V_61 * V_27 = V_4 -> V_27 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_2 -> V_22 == V_23 ) {
V_9 -> V_24 -- ;
V_10 -> V_24 -- ;
} else {
V_9 -> V_25 -- ;
V_10 -> V_25 -- ;
}
F_18 ( V_10 , 1 , V_2 -> V_22 ) ;
V_9 -> V_26 -- ;
V_10 -> V_26 -- ;
V_27 -> V_26 -- ;
if ( ! V_9 -> V_26 )
V_9 -> V_62 = 0 ;
if ( ! V_10 -> V_26 )
V_10 -> V_62 = 0 ;
if ( V_4 -> V_19 -> V_15 && V_4 -> V_19 -> V_15 -> V_53 )
V_4 -> V_19 -> V_15 -> V_53 ( V_2 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> free )
V_7 -> V_14 -> V_15 -> free ( V_2 ) ;
V_9 -> V_44 = NULL ;
if ( V_2 -> V_22 == V_23 ) {
if ( ! V_4 -> V_63 || V_27 -> V_64 ||
V_4 -> V_19 -> V_64 ) {
F_16 ( V_4 ,
V_39 ,
V_60 ) ;
} else {
V_4 -> V_59 = 1 ;
F_19 ( V_65 ,
& V_4 -> V_56 ,
F_20 ( V_4 -> V_63 ) ) ;
}
} else {
F_16 ( V_4 ,
V_40 ,
V_60 ) ;
}
F_4 ( & V_4 -> V_12 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_28 = V_2 -> V_5 ;
struct V_6 * V_7 = V_28 -> V_7 ;
struct V_8 * V_9 = V_28 -> V_9 ;
struct V_8 * V_10 = V_28 -> V_10 ;
struct V_34 * V_35 ;
int V_38 , V_11 ;
F_2 ( & V_28 -> V_41 -> V_42 , V_43 ) ;
if ( V_2 -> V_22 == V_23 ) {
V_38 = V_39 ;
V_9 -> V_24 -- ;
V_10 -> V_24 -- ;
} else {
V_38 = V_40 ;
V_9 -> V_25 -- ;
V_10 -> V_25 -- ;
}
V_9 -> V_26 -- ;
V_10 -> V_26 -- ;
V_28 -> V_27 -> V_26 -- ;
V_28 -> V_35 [ V_38 ] . V_46 = V_47 ;
V_11 = F_22 ( V_28 , V_38 ) ;
if ( V_11 < 0 )
F_23 ( V_28 -> V_45 , L_11 , V_11 ) ;
V_11 = F_24 ( V_28 , V_38 ) ;
F_10 (dpcm, &fe->dpcm[stream].be_clients, list_be)
V_35 -> V_48 = V_49 ;
if ( V_38 == V_39 )
F_25 ( V_28 , V_38 , V_60 ) ;
else
F_25 ( V_28 , V_38 , V_60 ) ;
V_28 -> V_35 [ V_38 ] . V_48 = V_66 ;
V_28 -> V_35 [ V_38 ] . V_46 = V_52 ;
F_11 ( V_28 , V_38 ) ;
V_28 -> V_35 [ V_38 ] . V_44 = NULL ;
if ( V_28 -> V_19 -> V_15 && V_28 -> V_19 -> V_15 -> V_53 )
V_28 -> V_19 -> V_15 -> V_53 ( V_2 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> free )
V_7 -> V_14 -> V_15 -> free ( V_2 ) ;
F_4 ( & V_28 -> V_41 -> V_42 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 , int V_67 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_10 = V_4 -> V_10 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_68 ) {
V_11 = V_7 -> V_14 -> V_15 -> V_68 ( V_2 , V_67 ) ;
if ( V_11 < 0 )
goto V_18;
}
switch ( V_67 ) {
case V_69 :
F_18 ( V_10 , 0 , V_2 -> V_22 ) ;
break;
case V_70 :
F_18 ( V_10 , 1 , V_2 -> V_22 ) ;
break;
}
V_18:
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_27 ( struct V_1 * V_2 , int V_67 )
{
struct V_3 * V_28 = V_2 -> V_5 ;
struct V_6 * V_7 = V_28 -> V_7 ;
int V_11 = 0 , V_38 ;
if ( V_67 == V_71 ||
V_67 == V_72 ) {
if ( V_7 -> V_14 -> V_15 &&
V_7 -> V_14 -> V_15 -> V_68 )
return V_7 -> V_14 -> V_15 -> V_68 ( V_2 , V_67 ) ;
}
if ( V_2 -> V_22 == V_23 )
V_38 = V_39 ;
else
V_38 = V_40 ;
F_2 ( & V_28 -> V_41 -> V_42 , V_43 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_68 ) {
V_11 = V_7 -> V_14 -> V_15 -> V_68 ( V_2 , V_67 ) ;
if ( V_11 < 0 )
goto V_18;
}
V_28 -> V_35 [ V_38 ] . V_46 = V_47 ;
V_11 = F_28 ( V_28 , V_38 , V_67 ) ;
switch ( V_67 ) {
case V_69 :
case V_73 :
case V_74 :
V_28 -> V_35 [ V_38 ] . V_48 = V_75 ;
break;
case V_70 :
case V_76 :
V_28 -> V_35 [ V_38 ] . V_48 = V_77 ;
break;
case V_78 :
V_28 -> V_35 [ V_38 ] . V_48 = V_79 ;
break;
}
V_18:
V_28 -> V_35 [ V_38 ] . V_46 = V_52 ;
F_4 ( & V_28 -> V_41 -> V_42 ) ;
return V_11 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_82 ) {
V_11 = V_7 -> V_14 -> V_15 -> V_82 ( V_2 , V_81 ) ;
if ( V_11 < 0 )
goto V_83;
}
if ( V_4 -> V_19 -> V_15 && V_4 -> V_19 -> V_15 -> V_82 ) {
V_11 = V_4 -> V_19 -> V_15 -> V_82 ( V_2 ) ;
if ( V_11 < 0 )
goto V_83;
}
if ( V_2 -> V_22 == V_23 )
F_16 ( V_4 , V_39 ,
V_84 ) ;
else
F_16 ( V_4 , V_40 ,
V_84 ) ;
V_4 -> V_59 = 0 ;
F_4 ( & V_4 -> V_12 ) ;
F_30 ( & V_4 -> V_56 ) ;
return V_11 ;
V_83:
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_80 * V_81 )
{
struct V_3 * V_28 = V_2 -> V_5 ;
struct V_29 * V_30 = V_28 -> V_31 -> V_32 [ 0 ] . V_33 ;
struct V_6 * V_7 = V_28 -> V_7 ;
int V_11 = 0 , V_38 ;
if ( V_2 -> V_22 == V_23 )
V_38 = V_39 ;
else
V_38 = V_40 ;
F_2 ( & V_28 -> V_41 -> V_42 , V_43 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_82 ) {
V_11 = V_7 -> V_14 -> V_15 -> V_82 ( V_2 , V_81 ) ;
if ( V_11 < 0 )
goto V_18;
}
if ( V_28 -> V_19 -> V_15 && V_28 -> V_19 -> V_15 -> V_82 ) {
V_11 = V_28 -> V_19 -> V_15 -> V_82 ( V_2 ) ;
if ( V_11 < 0 )
goto V_18;
}
memset ( & V_28 -> V_35 [ V_30 -> V_38 ] . V_85 , 0 ,
sizeof( struct V_86 ) ) ;
V_28 -> V_35 [ V_38 ] . V_46 = V_47 ;
V_11 = F_32 ( V_28 , V_38 ) ;
if ( V_11 < 0 )
goto V_18;
V_11 = F_33 ( V_28 , V_38 ) ;
if ( V_11 < 0 )
goto V_18;
if ( V_38 == V_39 )
F_25 ( V_28 , V_38 , V_84 ) ;
else
F_25 ( V_28 , V_38 , V_84 ) ;
V_28 -> V_35 [ V_38 ] . V_48 = V_87 ;
V_18:
V_28 -> V_35 [ V_38 ] . V_46 = V_52 ;
F_4 ( & V_28 -> V_41 -> V_42 ) ;
return V_11 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_88 * V_81 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_89 )
V_11 = V_7 -> V_14 -> V_15 -> V_89 ( V_2 , V_81 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_90 * V_91 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_92 )
V_11 = V_7 -> V_14 -> V_15 -> V_92 ( V_2 , V_91 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_93 * V_27 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_94 )
V_11 = V_7 -> V_14 -> V_15 -> V_94 ( V_2 , V_27 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_95 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_96 )
V_11 = V_7 -> V_14 -> V_15 -> V_96 ( V_2 , V_95 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_97 * V_98 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_99 )
V_7 -> V_14 -> V_15 -> V_99 ( V_2 , V_98 ) ;
F_4 ( & V_4 -> V_12 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
char T_2 * V_100 , T_1 V_101 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
F_2 ( & V_4 -> V_12 , V_4 -> V_13 ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_102 )
V_11 = V_7 -> V_14 -> V_15 -> V_102 ( V_2 , V_100 , V_101 ) ;
F_4 ( & V_4 -> V_12 ) ;
return V_11 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_105 )
V_11 = V_7 -> V_14 -> V_15 -> V_105 ( V_2 , V_104 ) ;
return V_11 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_103 * V_104 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_11 = 0 ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_106 )
V_11 = V_7 -> V_14 -> V_15 -> V_106 ( V_2 , V_104 ) ;
return V_11 ;
}
int F_42 ( struct V_3 * V_4 , int V_107 )
{
struct V_61 * V_27 = V_4 -> V_27 ;
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_8 * V_10 = V_4 -> V_10 ;
struct V_8 * V_9 = V_4 -> V_9 ;
struct V_108 * V_109 ;
struct V_110 * V_111 ;
char V_112 [ 64 ] ;
int V_11 = 0 , V_22 = 0 ;
snprintf ( V_112 , sizeof( V_112 ) , L_12 ,
V_4 -> V_19 -> V_58 , V_10 -> V_17 , V_107 ) ;
if ( V_10 -> V_14 -> V_57 . V_113 )
V_22 = V_23 ;
else if ( V_10 -> V_14 -> V_114 . V_113 )
V_22 = V_115 ;
else
return - V_116 ;
V_109 = F_43 ( sizeof( * V_109 ) , V_117 ) ;
if ( V_109 == NULL ) {
F_44 ( V_118 L_13 ) ;
return - V_119 ;
}
V_109 -> V_120 = F_45 ( V_4 -> V_41 -> V_45 , sizeof( V_121 ) ,
V_117 ) ;
if ( V_109 -> V_120 == NULL ) {
F_23 ( V_4 -> V_41 -> V_45 , L_14 ) ;
V_11 = - V_119 ;
goto V_122;
}
if ( V_4 -> V_19 -> V_123 ) {
snprintf ( V_112 , sizeof( V_112 ) , L_15 ,
V_4 -> V_19 -> V_58 ) ;
V_11 = F_46 ( V_4 -> V_41 -> V_124 , V_112 , V_107 ,
1 , 0 , & V_111 ) ;
if ( V_11 < 0 ) {
F_23 ( V_4 -> V_41 -> V_45 , L_16 ,
V_4 -> V_19 -> V_17 ) ;
goto V_122;
}
V_4 -> V_31 = V_111 ;
V_4 -> V_125 = 1 ;
V_111 -> V_32 [ V_39 ] . V_33 -> V_5 = V_4 ;
V_111 -> V_32 [ V_40 ] . V_33 -> V_5 = V_4 ;
memcpy ( V_109 -> V_120 , & V_126 , sizeof( V_126 ) ) ;
} else
memcpy ( V_109 -> V_120 , & V_121 , sizeof( V_121 ) ) ;
if ( V_7 -> V_14 -> V_15 && V_7 -> V_14 -> V_15 -> V_102 )
V_109 -> V_120 -> V_102 = F_39 ;
F_47 ( & V_109 -> V_127 ) ;
V_11 = F_48 ( V_4 -> V_41 -> V_124 , V_107 , V_22 , V_109 ) ;
if ( V_11 < 0 ) {
F_3 ( L_17 ,
V_27 -> V_17 ) ;
goto V_122;
}
F_49 ( & V_4 -> V_56 , F_14 ) ;
V_4 -> V_109 = V_109 ;
V_109 -> V_5 = V_4 ;
F_50 ( V_128 L_18 , V_10 -> V_17 ,
V_9 -> V_17 ) ;
return V_11 ;
V_122:
F_51 ( V_109 ) ;
return V_11 ;
}
