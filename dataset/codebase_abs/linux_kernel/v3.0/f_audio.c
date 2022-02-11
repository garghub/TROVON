static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 ;
V_3 = F_2 ( sizeof *V_3 , V_4 ) ;
if ( ! V_3 )
return F_3 ( - V_5 ) ;
V_3 -> V_6 = F_2 ( V_2 , V_4 ) ;
if ( ! V_3 -> V_6 ) {
F_4 ( V_3 ) ;
return F_3 ( - V_5 ) ;
}
return V_3 ;
}
static void F_5 ( struct V_1 * V_7 )
{
F_4 ( V_7 -> V_6 ) ;
F_4 ( V_7 ) ;
}
static inline struct V_8 * F_6 ( struct V_9 * V_10 )
{
return F_7 ( V_10 , struct V_8 , V_11 . V_12 ) ;
}
static void F_8 ( struct V_13 * V_14 )
{
struct V_8 * V_15 = F_7 ( V_14 , struct V_8 ,
V_16 ) ;
struct V_1 * V_17 ;
F_9 ( & V_15 -> V_18 ) ;
if ( F_10 ( & V_15 -> V_19 ) ) {
F_11 ( & V_15 -> V_18 ) ;
return;
}
V_17 = F_12 ( & V_15 -> V_19 ,
struct V_1 , V_20 ) ;
F_13 ( & V_17 -> V_20 ) ;
F_11 ( & V_15 -> V_18 ) ;
F_14 ( & V_15 -> V_11 , V_17 -> V_6 , V_17 -> V_21 ) ;
F_5 ( V_17 ) ;
}
static int F_15 ( struct V_22 * V_23 , struct V_24 * V_25 )
{
struct V_8 * V_15 = V_25 -> V_26 ;
struct V_27 * V_28 = V_15 -> V_11 . V_12 . V_29 -> V_28 ;
struct V_1 * V_3 = V_15 -> V_3 ;
int V_30 ;
if ( ! V_3 )
return - V_31 ;
if ( V_32 - V_3 -> V_21 < V_25 -> V_21 ) {
F_16 ( & V_3 -> V_20 , & V_15 -> V_19 ) ;
F_17 ( & V_15 -> V_16 ) ;
V_3 = F_1 ( V_32 ) ;
if ( F_18 ( V_3 ) )
return - V_5 ;
}
memcpy ( V_3 -> V_6 + V_3 -> V_21 , V_25 -> V_6 , V_25 -> V_21 ) ;
V_3 -> V_21 += V_25 -> V_21 ;
V_15 -> V_3 = V_3 ;
V_30 = F_19 ( V_23 , V_25 , V_4 ) ;
if ( V_30 )
ERROR ( V_28 , L_1 , V_23 -> V_33 , V_30 ) ;
return 0 ;
}
static void F_20 ( struct V_22 * V_23 , struct V_24 * V_25 )
{
struct V_8 * V_15 = V_25 -> V_26 ;
int V_34 = V_25 -> V_34 ;
T_1 V_14 = 0 ;
struct V_22 * V_35 = V_15 -> V_35 ;
switch ( V_34 ) {
case 0 :
if ( V_23 == V_35 )
F_15 ( V_23 , V_25 ) ;
else if ( V_15 -> V_36 ) {
memcpy ( & V_14 , V_25 -> V_6 , V_25 -> V_37 ) ;
V_15 -> V_36 -> V_38 ( V_15 -> V_36 , V_15 -> V_39 ,
F_21 ( V_14 ) ) ;
V_15 -> V_36 = NULL ;
}
break;
default:
break;
}
}
static int F_22 ( struct V_9 * V_10 ,
const struct V_40 * V_41 )
{
struct V_8 * V_15 = F_6 ( V_10 ) ;
struct V_27 * V_28 = V_10 -> V_29 -> V_28 ;
struct V_24 * V_25 = V_28 -> V_25 ;
T_2 V_42 = ( ( F_21 ( V_41 -> V_43 ) >> 8 ) & 0xFF ) ;
T_3 V_44 = F_21 ( V_41 -> V_45 ) ;
T_3 V_46 = F_21 ( V_41 -> V_47 ) ;
T_2 V_48 = ( V_46 >> 8 ) & 0xFF ;
T_2 V_49 = ( V_41 -> V_50 & 0x0F ) ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
F_23 ( V_28 , L_2 ,
V_41 -> V_50 , V_46 , V_44 , V_42 ) ;
F_24 (cs, &audio->cs, list) {
if ( V_52 -> V_42 == V_42 ) {
F_24 (con, &cs->control, list) {
if ( V_54 -> type == V_48 ) {
V_15 -> V_36 = V_54 ;
break;
}
}
break;
}
}
V_15 -> V_39 = V_49 ;
V_25 -> V_26 = V_15 ;
V_25 -> V_55 = F_20 ;
return V_44 ;
}
static int F_25 ( struct V_9 * V_10 ,
const struct V_40 * V_41 )
{
struct V_8 * V_15 = F_6 ( V_10 ) ;
struct V_27 * V_28 = V_10 -> V_29 -> V_28 ;
struct V_24 * V_25 = V_28 -> V_25 ;
int V_56 = - V_57 ;
T_2 V_42 = ( ( F_21 ( V_41 -> V_43 ) >> 8 ) & 0xFF ) ;
T_3 V_44 = F_21 ( V_41 -> V_45 ) ;
T_3 V_46 = F_21 ( V_41 -> V_47 ) ;
T_2 V_48 = ( V_46 >> 8 ) & 0xFF ;
T_2 V_49 = ( V_41 -> V_50 & 0x0F ) ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
F_23 ( V_28 , L_2 ,
V_41 -> V_50 , V_46 , V_44 , V_42 ) ;
F_24 (cs, &audio->cs, list) {
if ( V_52 -> V_42 == V_42 ) {
F_24 (con, &cs->control, list) {
if ( V_54 -> type == V_48 && V_54 -> V_58 ) {
V_56 = V_54 -> V_58 ( V_54 , V_49 ) ;
break;
}
}
break;
}
}
V_25 -> V_26 = V_15 ;
V_25 -> V_55 = F_20 ;
memcpy ( V_25 -> V_6 , & V_56 , V_44 ) ;
return V_44 ;
}
static int F_26 ( struct V_9 * V_10 ,
const struct V_40 * V_41 )
{
struct V_27 * V_28 = V_10 -> V_29 -> V_28 ;
int V_56 = - V_57 ;
T_3 V_23 = F_21 ( V_41 -> V_43 ) ;
T_3 V_44 = F_21 ( V_41 -> V_45 ) ;
T_3 V_46 = F_21 ( V_41 -> V_47 ) ;
F_23 ( V_28 , L_3 ,
V_41 -> V_50 , V_46 , V_44 , V_23 ) ;
switch ( V_41 -> V_50 ) {
case V_59 :
V_56 = 0 ;
break;
case V_60 :
break;
case V_61 :
break;
case V_62 :
break;
case V_63 :
break;
default:
break;
}
return V_56 ;
}
static int F_27 ( struct V_9 * V_10 ,
const struct V_40 * V_41 )
{
struct V_27 * V_28 = V_10 -> V_29 -> V_28 ;
int V_56 = - V_57 ;
T_2 V_23 = ( ( F_21 ( V_41 -> V_43 ) >> 8 ) & 0xFF ) ;
T_3 V_44 = F_21 ( V_41 -> V_45 ) ;
T_3 V_46 = F_21 ( V_41 -> V_47 ) ;
F_23 ( V_28 , L_3 ,
V_41 -> V_50 , V_46 , V_44 , V_23 ) ;
switch ( V_41 -> V_50 ) {
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_56 = 3 ;
break;
case V_68 :
break;
default:
break;
}
return V_56 ;
}
static int
F_28 ( struct V_9 * V_10 , const struct V_40 * V_41 )
{
struct V_27 * V_28 = V_10 -> V_29 -> V_28 ;
struct V_24 * V_25 = V_28 -> V_25 ;
int V_56 = - V_57 ;
T_3 V_69 = F_21 ( V_41 -> V_43 ) ;
T_3 V_46 = F_21 ( V_41 -> V_47 ) ;
T_3 V_70 = F_21 ( V_41 -> V_45 ) ;
switch ( V_41 -> V_71 ) {
case V_72 | V_73 | V_74 :
V_56 = F_22 ( V_10 , V_41 ) ;
break;
case V_75 | V_73 | V_74 :
V_56 = F_25 ( V_10 , V_41 ) ;
break;
case V_72 | V_73 | V_76 :
V_56 = F_26 ( V_10 , V_41 ) ;
break;
case V_75 | V_73 | V_76 :
V_56 = F_27 ( V_10 , V_41 ) ;
break;
default:
ERROR ( V_28 , L_4 ,
V_41 -> V_71 , V_41 -> V_50 ,
V_46 , V_69 , V_70 ) ;
}
if ( V_56 >= 0 ) {
F_23 ( V_28 , L_5 ,
V_41 -> V_71 , V_41 -> V_50 ,
V_46 , V_69 , V_70 ) ;
V_25 -> V_77 = 0 ;
V_25 -> V_37 = V_56 ;
V_56 = F_19 ( V_28 -> V_78 -> V_79 , V_25 , V_4 ) ;
if ( V_56 < 0 )
ERROR ( V_28 , L_6 , V_56 ) ;
}
return V_56 ;
}
static int F_29 ( struct V_9 * V_10 , unsigned V_80 , unsigned V_81 )
{
struct V_8 * V_15 = F_6 ( V_10 ) ;
struct V_27 * V_28 = V_10 -> V_29 -> V_28 ;
struct V_22 * V_35 = V_15 -> V_35 ;
struct V_24 * V_25 ;
int V_82 = 0 , V_30 = 0 ;
F_23 ( V_28 , L_7 , V_80 , V_81 ) ;
if ( V_80 == 1 ) {
if ( V_81 == 1 ) {
F_30 ( V_35 , V_15 -> V_83 ) ;
V_35 -> V_84 = V_15 ;
V_15 -> V_3 = F_1 ( V_32 ) ;
if ( F_18 ( V_15 -> V_3 ) )
return - V_5 ;
for ( V_82 = 0 ; V_82 < V_85 && V_30 == 0 ; V_82 ++ ) {
V_25 = F_31 ( V_35 , V_4 ) ;
if ( V_25 ) {
V_25 -> V_6 = F_2 ( V_86 ,
V_4 ) ;
if ( V_25 -> V_6 ) {
V_25 -> V_37 = V_86 ;
V_25 -> V_26 = V_15 ;
V_25 -> V_55 =
F_20 ;
V_30 = F_19 ( V_35 ,
V_25 , V_4 ) ;
if ( V_30 )
ERROR ( V_28 ,
L_1 ,
V_35 -> V_33 , V_30 ) ;
} else
V_30 = - V_5 ;
} else
V_30 = - V_5 ;
}
} else {
struct V_1 * V_3 = V_15 -> V_3 ;
if ( V_3 ) {
F_16 ( & V_3 -> V_20 ,
& V_15 -> V_19 ) ;
F_17 ( & V_15 -> V_16 ) ;
}
}
}
return V_30 ;
}
static void F_32 ( struct V_9 * V_10 )
{
return;
}
static void F_33 ( struct V_8 * V_15 )
{
struct V_87 * V_11 = & V_15 -> V_11 ;
T_2 * V_88 ;
int V_89 ;
V_90 . V_91 = F_34 ( V_11 ) ;
V_92 . V_91 = F_34 ( V_11 ) ;
V_89 = F_35 ( V_11 ) ;
V_88 = V_92 . V_93 [ 0 ] ;
memcpy ( V_88 , & V_89 , 3 ) ;
return;
}
static int T_4
F_36 ( struct V_94 * V_95 , struct V_9 * V_10 )
{
struct V_27 * V_28 = V_95 -> V_28 ;
struct V_8 * V_15 = F_6 ( V_10 ) ;
int V_34 ;
struct V_22 * V_23 ;
F_33 ( V_15 ) ;
V_34 = F_37 ( V_95 , V_10 ) ;
if ( V_34 < 0 )
goto V_96;
V_97 . V_98 = V_34 ;
V_34 = F_37 ( V_95 , V_10 ) ;
if ( V_34 < 0 )
goto V_96;
V_99 . V_98 = V_34 ;
V_100 . V_98 = V_34 ;
V_34 = - V_101 ;
V_23 = F_38 ( V_28 -> V_78 , & V_102 ) ;
if ( ! V_23 )
goto V_96;
V_15 -> V_35 = V_23 ;
V_23 -> V_84 = V_28 ;
V_34 = - V_5 ;
if ( F_39 ( V_95 -> V_28 -> V_78 ) ) {
V_95 -> V_103 = true ;
V_10 -> V_104 = F_40 ( V_105 ) ;
} else
V_10 -> V_106 = F_40 ( V_105 ) ;
return 0 ;
V_96:
return V_34 ;
}
static void
F_41 ( struct V_94 * V_95 , struct V_9 * V_10 )
{
struct V_8 * V_15 = F_6 ( V_10 ) ;
F_42 ( V_10 -> V_106 ) ;
F_42 ( V_10 -> V_104 ) ;
F_4 ( V_15 ) ;
}
static int F_43 ( struct V_53 * V_54 , T_2 V_49 , int V_56 )
{
V_54 -> V_14 [ V_49 ] = V_56 ;
return 0 ;
}
static int F_44 ( struct V_53 * V_54 , T_2 V_49 )
{
return V_54 -> V_14 [ V_49 ] ;
}
int T_4 F_45 ( struct V_8 * V_15 )
{
F_46 ( & V_15 -> V_52 ) ;
F_47 ( & V_107 . V_20 , & V_15 -> V_52 ) ;
F_46 ( & V_107 . V_108 ) ;
F_47 ( & V_109 . V_20 , & V_107 . V_108 ) ;
F_47 ( & V_110 . V_20 , & V_107 . V_108 ) ;
V_110 . V_14 [ V_111 ] = 0xffc0 ;
V_110 . V_14 [ V_112 ] = 0xe3a0 ;
V_110 . V_14 [ V_113 ] = 0xfff0 ;
V_110 . V_14 [ V_114 ] = 0x0030 ;
return 0 ;
}
int T_4 F_48 ( struct V_94 * V_95 )
{
struct V_8 * V_15 ;
int V_34 ;
V_15 = F_2 ( sizeof *V_15 , V_115 ) ;
if ( ! V_15 )
return - V_5 ;
V_15 -> V_11 . V_12 . V_33 = L_8 ;
V_15 -> V_11 . V_78 = V_95 -> V_28 -> V_78 ;
F_46 ( & V_15 -> V_19 ) ;
F_49 ( & V_15 -> V_18 ) ;
V_34 = F_50 ( & V_15 -> V_11 ) ;
if ( V_34 < 0 )
goto V_116;
V_15 -> V_11 . V_12 . V_117 = V_118 ;
V_15 -> V_11 . V_12 . V_119 = F_36 ;
V_15 -> V_11 . V_12 . V_120 = F_41 ;
V_15 -> V_11 . V_12 . V_121 = F_29 ;
V_15 -> V_11 . V_12 . V_122 = F_28 ;
V_15 -> V_11 . V_12 . V_123 = F_32 ;
V_15 -> V_83 = & V_102 ;
F_45 ( V_15 ) ;
F_51 ( & V_15 -> V_16 , F_8 ) ;
V_34 = F_52 ( V_95 , & V_15 -> V_11 . V_12 ) ;
if ( V_34 )
goto V_124;
F_53 ( V_95 -> V_28 , L_9 ,
V_32 , V_86 , V_85 ) ;
return V_34 ;
V_124:
F_54 () ;
V_116:
F_4 ( V_15 ) ;
return V_34 ;
}
