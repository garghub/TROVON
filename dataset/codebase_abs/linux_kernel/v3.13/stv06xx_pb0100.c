static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 =
F_2 ( V_2 -> V_4 , struct V_3 , V_5 ) ;
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_10 = - V_11 ;
switch ( V_2 -> V_12 ) {
case V_13 :
V_10 = F_3 ( V_3 , V_2 -> V_14 ) ;
if ( V_10 )
break;
if ( V_2 -> V_14 )
break;
V_10 = F_4 ( V_3 , V_8 -> V_15 -> V_14 ) ;
if ( V_10 )
break;
V_10 = F_5 ( V_3 , V_8 -> V_16 -> V_14 ) ;
break;
case V_17 + 0x1001 :
V_10 = F_6 ( V_3 , V_2 -> V_14 ) ;
break;
}
return V_10 ;
}
static int F_7 ( struct V_6 * V_6 )
{
struct V_18 * V_19 = & V_6 -> V_3 . V_5 ;
struct V_7 * V_8 ;
static const struct V_20 V_21 = {
. V_22 = & V_23 ,
. V_12 = V_17 + 0x1000 ,
. type = V_24 ,
. V_25 = L_1 ,
. V_26 = 255 ,
. V_27 = 1 ,
. V_28 = 128 ,
} ;
static const struct V_20 V_29 = {
. V_22 = & V_23 ,
. V_12 = V_17 + 0x1001 ,
. type = V_30 ,
. V_25 = L_2 ,
. V_26 = 1 ,
. V_27 = 1 ,
. V_28 = 1 ,
} ;
V_8 = F_8 ( sizeof( * V_8 ) , V_31 ) ;
if ( ! V_8 )
return - V_32 ;
F_9 ( V_19 , 6 ) ;
V_8 -> V_33 = F_10 ( V_19 , & V_23 ,
V_13 , 0 , 1 , 1 , 1 ) ;
V_8 -> V_16 = F_10 ( V_19 , & V_23 ,
V_34 , 0 , 511 , 1 , 12 ) ;
V_8 -> V_15 = F_10 ( V_19 , & V_23 ,
V_35 , 0 , 255 , 1 , 128 ) ;
V_8 -> V_36 = F_10 ( V_19 , & V_23 ,
V_37 , - 255 , 255 , 1 , 0 ) ;
V_8 -> V_38 = F_10 ( V_19 , & V_23 ,
V_39 , - 255 , 255 , 1 , 0 ) ;
V_8 -> V_40 = F_11 ( V_19 , & V_29 , NULL ) ;
V_8 -> V_41 = F_11 ( V_19 , & V_21 , NULL ) ;
if ( V_19 -> error ) {
F_12 ( V_8 ) ;
return V_19 -> error ;
}
V_6 -> V_9 = V_8 ;
F_13 ( 5 , & V_8 -> V_33 , 0 , false ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_6 )
{
T_1 V_42 ;
int V_10 ;
V_10 = F_15 ( V_6 , V_43 , & V_42 ) ;
if ( V_10 < 0 )
return - V_44 ;
if ( ( V_42 >> 8 ) != 0x64 )
return - V_44 ;
F_16 ( L_3 ) ;
V_6 -> V_3 . V_45 . V_46 = V_47 ;
V_6 -> V_3 . V_45 . V_48 = F_17 ( V_47 ) ;
return 0 ;
}
static int F_18 ( struct V_6 * V_6 )
{
int V_10 , V_49 , V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
struct V_3 * V_3 = (struct V_3 * ) V_6 ;
struct V_45 * V_45 = & V_6 -> V_3 . V_45 ;
T_2 V_55 = V_45 -> V_46 [ V_6 -> V_3 . V_56 ] . V_57 ;
V_54 = F_19 ( V_6 -> V_3 . V_58 , V_6 -> V_3 . V_59 ) ;
V_52 = F_20 ( V_54 , V_6 -> V_3 . V_52 ) ;
if ( ! V_52 )
return - V_44 ;
V_49 = F_21 ( V_52 -> V_60 [ 0 ] . V_61 . V_62 ) ;
V_50 = V_6 -> V_42 -> V_50 [ V_6 -> V_3 . V_56 ] ;
if ( V_49 < V_50 )
F_22 ( V_6 , V_63 , F_23 ( 4 ) | F_23 ( 3 ) | F_23 ( 1 ) ) ;
else
F_22 ( V_6 , V_63 , F_23 ( 5 ) | F_23 ( 3 ) | F_23 ( 1 ) ) ;
if ( V_55 & V_64 ) {
F_22 ( V_6 , V_65 , 30 ) ;
F_22 ( V_6 , V_66 , 20 ) ;
F_22 ( V_6 , V_67 , 240 - 1 ) ;
F_22 ( V_6 , V_68 , 320 - 1 ) ;
} else {
F_22 ( V_6 , V_65 , 8 ) ;
F_22 ( V_6 , V_66 , 4 ) ;
F_22 ( V_6 , V_67 , 288 - 1 ) ;
F_22 ( V_6 , V_68 , 352 - 1 ) ;
}
if ( V_55 & V_69 ) {
F_24 ( V_6 , V_70 , 0x02 ) ;
F_24 ( V_6 , V_71 , 0x06 ) ;
F_24 ( V_6 , V_72 , 0x10 ) ;
} else {
F_24 ( V_6 , V_70 , 0x01 ) ;
F_24 ( V_6 , V_71 , 0x0a ) ;
F_24 ( V_6 , V_72 , 0x20 ) ;
}
V_10 = F_22 ( V_6 , V_73 , F_23 ( 5 ) | F_23 ( 3 ) | F_23 ( 1 ) ) ;
F_25 ( V_74 , L_4 , V_10 ) ;
return ( V_10 < 0 ) ? V_10 : 0 ;
}
static int F_26 ( struct V_6 * V_6 )
{
struct V_3 * V_3 = (struct V_3 * ) V_6 ;
int V_10 ;
V_10 = F_22 ( V_6 , V_75 , 1 ) ;
if ( V_10 < 0 )
goto V_76;
V_10 = F_22 ( V_6 , V_73 , F_23 ( 5 ) | F_23 ( 3 ) ) ;
F_25 ( V_74 , L_5 ) ;
V_76:
return ( V_10 < 0 ) ? V_10 : 0 ;
}
static int F_27 ( struct V_6 * V_6 )
{
F_24 ( V_6 , V_77 , 1 ) ;
F_24 ( V_6 , V_72 , 0 ) ;
F_22 ( V_6 , V_78 , 1 ) ;
F_22 ( V_6 , V_78 , 0 ) ;
F_22 ( V_6 , V_73 , F_23 ( 5 ) | F_23 ( 3 ) ) ;
F_22 ( V_6 , V_79 , F_23 ( 12 ) | F_23 ( 10 ) | F_23 ( 6 ) ) ;
F_22 ( V_6 , V_80 , 12 ) ;
F_22 ( V_6 , V_81 , 12 ) ;
F_22 ( V_6 , V_82 , 180 ) ;
F_22 ( V_6 , V_83 , 12 ) ;
F_22 ( V_6 , V_84 , 3 ) ;
F_22 ( V_6 , V_85 , 0 ) ;
F_22 ( V_6 , V_86 , 1 ) ;
F_22 ( V_6 , V_87 , 800 ) ;
F_22 ( V_6 , V_88 , 10 ) ;
F_22 ( V_6 , V_89 , 0 ) ;
F_22 ( V_6 , V_90 , 0 ) ;
F_22 ( V_6 , V_91 , 11 ) ;
F_22 ( V_6 , V_92 , 0 ) ;
F_24 ( V_6 , V_77 , 0x11 ) ;
F_24 ( V_6 , V_93 , 0x45 ) ;
F_24 ( V_6 , V_94 , 0x07 ) ;
F_22 ( V_6 , V_63 , F_23 ( 4 ) | F_23 ( 3 ) | F_23 ( 1 ) ) ;
F_22 ( V_6 , V_95 , 14 ) ;
F_22 ( V_6 , V_96 , 0 ) ;
F_22 ( V_6 , V_97 , 0 ) ;
F_22 ( V_6 , V_98 , 123 ) ;
F_24 ( V_6 , V_99 , 0xc2 ) ;
F_24 ( V_6 , V_100 , 0xb0 ) ;
return 0 ;
}
static int F_28 ( struct V_6 * V_6 )
{
return 0 ;
}
static int F_4 ( struct V_3 * V_3 , T_3 V_14 )
{
int V_10 ;
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
struct V_7 * V_8 = V_6 -> V_9 ;
V_10 = F_22 ( V_6 , V_101 , V_14 ) ;
if ( ! V_10 )
V_10 = F_22 ( V_6 , V_102 , V_14 ) ;
F_25 ( V_103 , L_6 , V_14 , V_10 ) ;
if ( ! V_10 )
V_10 = F_29 ( V_3 , V_8 -> V_36 -> V_14 ) ;
if ( ! V_10 )
V_10 = F_30 ( V_3 , V_8 -> V_38 -> V_14 ) ;
return V_10 ;
}
static int F_29 ( struct V_3 * V_3 , T_3 V_14 )
{
int V_10 ;
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
struct V_7 * V_8 = V_6 -> V_9 ;
V_14 += V_8 -> V_15 -> V_14 ;
if ( V_14 < 0 )
V_14 = 0 ;
else if ( V_14 > 255 )
V_14 = 255 ;
V_10 = F_22 ( V_6 , V_104 , V_14 ) ;
F_25 ( V_103 , L_7 , V_14 , V_10 ) ;
return V_10 ;
}
static int F_30 ( struct V_3 * V_3 , T_3 V_14 )
{
int V_10 ;
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
struct V_7 * V_8 = V_6 -> V_9 ;
V_14 += V_8 -> V_15 -> V_14 ;
if ( V_14 < 0 )
V_14 = 0 ;
else if ( V_14 > 255 )
V_14 = 255 ;
V_10 = F_22 ( V_6 , V_105 , V_14 ) ;
F_25 ( V_103 , L_8 , V_14 , V_10 ) ;
return V_10 ;
}
static int F_5 ( struct V_3 * V_3 , T_3 V_14 )
{
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
int V_10 ;
V_10 = F_22 ( V_6 , V_98 , V_14 ) ;
F_25 ( V_103 , L_9 , V_14 , V_10 ) ;
return V_10 ;
}
static int F_3 ( struct V_3 * V_3 , T_3 V_14 )
{
int V_10 ;
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
struct V_7 * V_8 = V_6 -> V_9 ;
if ( V_14 ) {
if ( V_8 -> V_40 -> V_14 )
V_14 = F_23 ( 6 ) | F_23 ( 4 ) | F_23 ( 0 ) ;
else
V_14 = F_23 ( 4 ) | F_23 ( 0 ) ;
} else
V_14 = 0 ;
V_10 = F_22 ( V_6 , V_89 , V_14 ) ;
F_25 ( V_103 , L_10 ,
V_14 , V_8 -> V_40 -> V_14 , V_10 ) ;
return V_10 ;
}
static int F_6 ( struct V_3 * V_3 , T_3 V_14 )
{
int V_10 , V_106 , V_107 , V_108 ;
struct V_6 * V_6 = (struct V_6 * ) V_3 ;
V_106 = V_3 -> V_109 . V_110 * V_3 -> V_109 . V_111 ;
V_106 = V_106 / ( 8 * 8 ) + V_106 / ( 64 * 64 ) ;
V_107 = ( V_106 * V_14 ) >> 8 ;
V_108 = V_106 - V_107 ;
V_10 = F_22 ( V_6 , V_112 , V_107 ) ;
if ( ! V_10 )
V_10 = F_22 ( V_6 , V_113 , V_108 ) ;
F_25 ( V_103 , L_11 , V_14 , V_10 ) ;
return V_10 ;
}
