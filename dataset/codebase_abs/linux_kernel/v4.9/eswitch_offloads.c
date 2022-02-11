struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_8 V_9 = { 0 } ;
struct V_10 * V_11 = NULL ;
struct V_1 * V_12 ;
void * V_13 ;
int V_14 ;
if ( V_3 -> V_15 != V_16 )
return F_2 ( - V_17 ) ;
V_14 = V_7 -> V_14 & ~ ( V_18 | V_19 ) ;
if ( V_14 & V_20 ) {
V_9 . type = V_21 ;
V_9 . V_22 = V_7 -> V_23 -> V_24 ;
V_14 = V_20 ;
} else if ( V_14 & V_25 ) {
V_11 = F_3 ( V_3 -> V_26 , true ) ;
if ( F_4 ( V_11 ) )
return F_5 ( V_11 ) ;
V_9 . type = V_27 ;
V_9 . V_11 = V_11 ;
}
V_13 = F_6 ( V_28 , V_5 -> V_29 , V_30 ) ;
F_7 ( V_31 , V_13 , V_32 , V_7 -> V_33 -> V_24 ) ;
V_13 = F_6 ( V_28 , V_5 -> V_34 , V_30 ) ;
F_8 ( V_31 , V_13 , V_32 ) ;
V_5 -> V_35 = V_36 |
V_37 ;
V_12 = F_9 ( (struct V_38 * ) V_3 -> V_39 . V_40 ,
V_5 , V_14 , 0 , & V_9 ) ;
if ( F_4 ( V_12 ) )
F_10 ( V_3 -> V_26 , V_11 ) ;
return V_12 ;
}
static int F_11 ( struct V_2 * V_3 , T_1 V_41 )
{
struct V_42 * V_43 ;
int V_44 , V_45 = 0 ;
F_12 ( V_3 -> V_26 , L_1 , V_46 , V_41 ? L_2 : L_3 ) ;
for ( V_44 = 1 ; V_44 < V_3 -> V_47 ; V_44 ++ ) {
V_43 = & V_3 -> V_48 . V_49 [ V_44 ] ;
if ( ! V_43 -> V_50 )
continue;
V_45 = F_13 ( V_3 , V_43 -> V_24 , 0 , 0 , V_41 ) ;
if ( V_45 )
goto V_51;
}
V_51:
return V_45 ;
}
static struct V_42 *
F_14 ( struct V_6 * V_7 , bool V_52 , bool V_53 )
{
struct V_42 * V_33 , * V_23 , * V_24 = NULL ;
V_33 = V_7 -> V_33 ;
V_23 = V_7 -> V_23 ;
if ( V_52 )
V_24 = V_33 ;
else if ( V_53 )
V_24 = V_23 ;
else
V_24 = V_33 ;
return V_24 ;
}
static int F_15 ( struct V_6 * V_7 ,
bool V_52 , bool V_53 , bool V_54 )
{
struct V_42 * V_33 , * V_23 ;
if ( ( V_52 || V_53 ) && ! V_54 )
goto V_55;
V_33 = V_7 -> V_33 ;
V_23 = V_7 -> V_23 ;
if ( V_52 && V_33 -> V_24 == V_56 )
goto V_55;
if ( V_53 && V_23 -> V_24 == V_56 )
goto V_55;
if ( ! V_52 && ! V_53 && V_54 )
if ( V_33 -> V_57 && V_23 -> V_24 == V_56 )
goto V_55;
if ( V_52 && V_33 -> V_58 && ( V_33 -> V_57 != V_7 -> V_57 ) )
goto V_55;
return 0 ;
V_55:
return - V_59 ;
}
int F_16 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_60 * V_48 = & V_3 -> V_39 . V_48 ;
struct V_42 * V_24 = NULL ;
bool V_52 , V_53 , V_54 ;
int V_45 = 0 ;
V_52 = ! ! ( V_7 -> V_14 & V_18 ) ;
V_53 = ! ! ( V_7 -> V_14 & V_19 ) ;
V_54 = ! ! ( V_7 -> V_14 & V_20 ) ;
V_45 = F_15 ( V_7 , V_52 , V_53 , V_54 ) ;
if ( V_45 )
return V_45 ;
V_7 -> V_61 = false ;
V_24 = F_14 ( V_7 , V_52 , V_53 ) ;
if ( ! V_52 && ! V_53 && V_54 ) {
if ( V_7 -> V_23 -> V_24 == V_56 ) {
V_24 -> V_58 ++ ;
V_7 -> V_61 = true ;
}
return 0 ;
}
if ( ! V_52 && ! V_53 )
return 0 ;
if ( ! ( V_48 -> V_62 ) ) {
V_45 = F_11 ( V_3 , V_63 ) ;
if ( V_45 )
goto V_51;
}
V_48 -> V_62 ++ ;
if ( V_52 ) {
if ( V_24 -> V_58 )
goto V_64;
V_45 = F_13 ( V_3 , V_24 -> V_24 , V_7 -> V_57 , 0 ,
V_65 | V_63 ) ;
if ( V_45 )
goto V_51;
V_24 -> V_57 = V_7 -> V_57 ;
V_64:
V_24 -> V_58 ++ ;
}
V_51:
if ( ! V_45 )
V_7 -> V_61 = true ;
return V_45 ;
}
int F_17 ( struct V_2 * V_3 ,
struct V_6 * V_7 )
{
struct V_60 * V_48 = & V_3 -> V_39 . V_48 ;
struct V_42 * V_24 = NULL ;
bool V_52 , V_53 , V_54 ;
int V_45 = 0 ;
if ( ! V_7 -> V_61 )
return 0 ;
V_52 = ! ! ( V_7 -> V_14 & V_18 ) ;
V_53 = ! ! ( V_7 -> V_14 & V_19 ) ;
V_54 = ! ! ( V_7 -> V_14 & V_20 ) ;
V_24 = F_14 ( V_7 , V_52 , V_53 ) ;
if ( ! V_52 && ! V_53 && V_54 ) {
if ( V_7 -> V_23 -> V_24 == V_56 )
V_24 -> V_58 -- ;
return 0 ;
}
if ( V_52 ) {
V_24 -> V_58 -- ;
if ( V_24 -> V_58 )
goto V_66;
V_24 -> V_57 = 0 ;
V_45 = F_13 ( V_3 , V_24 -> V_24 ,
0 , 0 , V_63 ) ;
if ( V_45 )
goto V_51;
}
V_66:
V_48 -> V_62 -- ;
if ( V_48 -> V_62 )
return 0 ;
V_45 = F_11 ( V_3 , 0 ) ;
V_51:
return V_45 ;
}
static struct V_1 *
F_18 ( struct V_2 * V_3 , int V_24 , T_2 V_67 )
{
struct V_8 V_9 ;
struct V_1 * V_68 ;
struct V_4 * V_5 ;
void * V_13 ;
V_5 = F_19 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_20 ( V_3 -> V_26 , L_4 ) ;
V_68 = F_2 ( - V_69 ) ;
goto V_51;
}
V_13 = F_6 ( V_28 , V_5 -> V_29 , V_30 ) ;
F_7 ( V_31 , V_13 , V_70 , V_67 ) ;
F_7 ( V_31 , V_13 , V_32 , 0x0 ) ;
V_13 = F_6 ( V_28 , V_5 -> V_34 , V_30 ) ;
F_8 ( V_31 , V_13 , V_70 ) ;
F_8 ( V_31 , V_13 , V_32 ) ;
V_5 -> V_35 = V_37 ;
V_9 . type = V_21 ;
V_9 . V_22 = V_24 ;
V_68 = F_9 ( V_3 -> V_39 . V_48 . V_40 , V_5 ,
V_20 ,
0 , & V_9 ) ;
if ( F_4 ( V_68 ) )
F_20 ( V_3 -> V_26 , L_5 , F_21 ( V_68 ) ) ;
V_51:
F_22 ( V_5 ) ;
return V_68 ;
}
void F_23 ( struct V_2 * V_3 ,
struct V_42 * V_43 )
{
struct V_71 * V_72 , * V_73 ;
if ( V_3 -> V_15 != V_16 )
return;
F_24 (esw_sq, tmp, &rep->vport_sqs_list, list) {
F_25 ( V_72 -> V_74 ) ;
F_26 ( & V_72 -> V_75 ) ;
F_27 ( V_72 ) ;
}
}
int F_28 ( struct V_2 * V_3 ,
struct V_42 * V_43 ,
T_3 * V_76 , int V_77 )
{
struct V_1 * V_68 ;
struct V_71 * V_72 ;
int V_45 ;
int V_78 ;
if ( V_3 -> V_15 != V_16 )
return 0 ;
for ( V_78 = 0 ; V_78 < V_77 ; V_78 ++ ) {
V_72 = F_29 ( sizeof( * V_72 ) , V_79 ) ;
if ( ! V_72 ) {
V_45 = - V_69 ;
goto V_80;
}
V_68 = F_18 ( V_3 ,
V_43 -> V_24 ,
V_76 [ V_78 ] ) ;
if ( F_4 ( V_68 ) ) {
V_45 = F_21 ( V_68 ) ;
F_27 ( V_72 ) ;
goto V_80;
}
V_72 -> V_74 = V_68 ;
F_30 ( & V_72 -> V_75 , & V_43 -> V_81 ) ;
}
return 0 ;
V_80:
F_23 ( V_3 , V_43 ) ;
return V_45 ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_8 V_9 ;
struct V_1 * V_68 = NULL ;
struct V_4 * V_5 ;
int V_45 = 0 ;
V_5 = F_19 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_20 ( V_3 -> V_26 , L_4 ) ;
V_45 = - V_69 ;
goto V_51;
}
V_9 . type = V_21 ;
V_9 . V_22 = 0 ;
V_68 = F_9 ( V_3 -> V_39 . V_48 . V_40 , V_5 ,
V_20 ,
0 , & V_9 ) ;
if ( F_4 ( V_68 ) ) {
V_45 = F_21 ( V_68 ) ;
F_20 ( V_3 -> V_26 , L_6 , V_45 ) ;
goto V_51;
}
V_3 -> V_39 . V_48 . V_82 = V_68 ;
V_51:
F_22 ( V_5 ) ;
return V_45 ;
}
static int F_32 ( struct V_2 * V_3 , int V_83 )
{
int V_84 = F_33 ( V_85 ) ;
struct V_86 * V_26 = V_3 -> V_26 ;
struct V_87 * V_88 ;
struct V_38 * V_40 = NULL ;
struct V_89 * V_90 ;
T_2 * V_91 ;
void * V_34 ;
int V_92 , V_93 , V_45 = 0 ;
V_91 = F_19 ( V_84 ) ;
if ( ! V_91 )
return - V_69 ;
V_88 = F_34 ( V_26 , V_94 ) ;
if ( ! V_88 ) {
F_20 ( V_26 , L_7 ) ;
goto V_95;
}
F_12 ( V_26 , L_8 ,
F_35 ( V_26 , V_96 ) ) ;
V_40 = F_36 ( V_88 , V_97 ,
V_98 ,
V_99 , 0 ) ;
if ( F_4 ( V_40 ) ) {
V_45 = F_21 ( V_40 ) ;
F_20 ( V_26 , L_9 , V_45 ) ;
goto V_100;
}
V_3 -> V_39 . V_40 = V_40 ;
V_92 = V_83 + V_101 + 1 ;
V_40 = F_37 ( V_88 , V_102 , V_92 , 0 ) ;
if ( F_4 ( V_40 ) ) {
V_45 = F_21 ( V_40 ) ;
F_20 ( V_26 , L_10 , V_45 ) ;
goto V_103;
}
V_3 -> V_39 . V_48 . V_40 = V_40 ;
memset ( V_91 , 0 , V_84 ) ;
F_7 ( V_85 , V_91 , V_35 ,
V_37 ) ;
V_34 = F_6 ( V_85 , V_91 , V_34 ) ;
F_8 ( V_28 , V_34 , V_30 . V_70 ) ;
F_8 ( V_28 , V_34 , V_30 . V_32 ) ;
V_93 = V_83 + V_101 ;
F_7 ( V_85 , V_91 , V_104 , 0 ) ;
F_7 ( V_85 , V_91 , V_105 , V_93 - 1 ) ;
V_90 = F_38 ( V_40 , V_91 ) ;
if ( F_4 ( V_90 ) ) {
V_45 = F_21 ( V_90 ) ;
F_20 ( V_26 , L_11 , V_45 ) ;
goto V_106;
}
V_3 -> V_39 . V_48 . V_107 = V_90 ;
memset ( V_91 , 0 , V_84 ) ;
F_7 ( V_85 , V_91 , V_35 , 0 ) ;
F_7 ( V_85 , V_91 , V_104 , V_93 ) ;
F_7 ( V_85 , V_91 , V_105 , V_93 + 1 ) ;
V_90 = F_38 ( V_40 , V_91 ) ;
if ( F_4 ( V_90 ) ) {
V_45 = F_21 ( V_90 ) ;
F_20 ( V_26 , L_12 , V_45 ) ;
goto V_108;
}
V_3 -> V_39 . V_48 . V_109 = V_90 ;
V_45 = F_31 ( V_3 ) ;
if ( V_45 )
goto V_110;
return 0 ;
V_110:
F_39 ( V_3 -> V_39 . V_48 . V_109 ) ;
V_108:
F_39 ( V_3 -> V_39 . V_48 . V_107 ) ;
V_106:
F_40 ( V_3 -> V_39 . V_48 . V_40 ) ;
V_103:
F_40 ( V_3 -> V_39 . V_40 ) ;
V_100:
V_95:
F_22 ( V_91 ) ;
return V_45 ;
}
static void F_41 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_39 . V_40 )
return;
F_12 ( V_3 -> V_26 , L_13 ) ;
F_25 ( V_3 -> V_39 . V_48 . V_82 ) ;
F_39 ( V_3 -> V_39 . V_48 . V_107 ) ;
F_39 ( V_3 -> V_39 . V_48 . V_109 ) ;
F_40 ( V_3 -> V_39 . V_48 . V_40 ) ;
F_40 ( V_3 -> V_39 . V_40 ) ;
}
static int F_42 ( struct V_2 * V_3 )
{
struct V_87 * V_111 ;
struct V_38 * V_112 ;
struct V_86 * V_26 = V_3 -> V_26 ;
int V_45 = 0 ;
V_111 = F_34 ( V_26 , V_113 ) ;
if ( ! V_111 ) {
F_20 ( V_3 -> V_26 , L_14 ) ;
return - V_69 ;
}
V_112 = F_37 ( V_111 , 0 , V_26 -> V_114 . V_115 . V_116 + 2 , 0 ) ;
if ( F_4 ( V_112 ) ) {
V_45 = F_21 ( V_112 ) ;
F_20 ( V_3 -> V_26 , L_15 , V_45 ) ;
return V_45 ;
}
V_3 -> V_48 . V_112 = V_112 ;
return 0 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_117 * V_48 = & V_3 -> V_48 ;
F_40 ( V_48 -> V_112 ) ;
}
static int F_44 ( struct V_2 * V_3 )
{
int V_84 = F_33 ( V_85 ) ;
struct V_89 * V_90 ;
struct V_118 * V_114 = & V_3 -> V_26 -> V_114 ;
T_2 * V_91 ;
void * V_34 , * V_13 ;
int V_45 = 0 ;
int V_83 = V_114 -> V_115 . V_116 + 2 ;
V_91 = F_19 ( V_84 ) ;
if ( ! V_91 )
return - V_69 ;
memset ( V_91 , 0 , V_84 ) ;
F_7 ( V_85 , V_91 , V_35 ,
V_37 ) ;
V_34 = F_6 ( V_85 , V_91 , V_34 ) ;
V_13 = F_6 ( V_28 , V_34 , V_30 ) ;
F_8 ( V_31 , V_13 , V_32 ) ;
F_7 ( V_85 , V_91 , V_104 , 0 ) ;
F_7 ( V_85 , V_91 , V_105 , V_83 - 1 ) ;
V_90 = F_38 ( V_3 -> V_48 . V_112 , V_91 ) ;
if ( F_4 ( V_90 ) ) {
V_45 = F_21 ( V_90 ) ;
F_45 ( V_3 -> V_26 , L_16 , V_45 ) ;
goto V_51;
}
V_3 -> V_48 . V_119 = V_90 ;
V_51:
F_27 ( V_91 ) ;
return V_45 ;
}
static void F_46 ( struct V_2 * V_3 )
{
F_39 ( V_3 -> V_48 . V_119 ) ;
}
struct V_1 *
F_47 ( struct V_2 * V_3 , int V_24 , T_2 V_120 )
{
struct V_8 V_9 ;
struct V_1 * V_68 ;
struct V_4 * V_5 ;
void * V_13 ;
V_5 = F_19 ( sizeof( * V_5 ) ) ;
if ( ! V_5 ) {
F_20 ( V_3 -> V_26 , L_17 ) ;
V_68 = F_2 ( - V_69 ) ;
goto V_51;
}
V_13 = F_6 ( V_28 , V_5 -> V_29 , V_30 ) ;
F_7 ( V_31 , V_13 , V_32 , V_24 ) ;
V_13 = F_6 ( V_28 , V_5 -> V_34 , V_30 ) ;
F_8 ( V_31 , V_13 , V_32 ) ;
V_5 -> V_35 = V_37 ;
V_9 . type = V_121 ;
V_9 . V_122 = V_120 ;
V_68 = F_9 ( V_3 -> V_48 . V_112 , V_5 ,
V_20 ,
0 , & V_9 ) ;
if ( F_4 ( V_68 ) ) {
F_20 ( V_3 -> V_26 , L_18 , F_21 ( V_68 ) ) ;
goto V_51;
}
V_51:
F_22 ( V_5 ) ;
return V_68 ;
}
static int F_48 ( struct V_2 * V_3 )
{
int V_45 , V_123 , V_116 = V_3 -> V_26 -> V_114 . V_115 . V_116 ;
if ( V_3 -> V_15 != V_124 ) {
F_20 ( V_3 -> V_26 , L_19 ) ;
return - V_125 ;
}
F_49 ( V_3 ) ;
V_45 = F_50 ( V_3 , V_116 , V_16 ) ;
if ( V_45 ) {
F_20 ( V_3 -> V_26 , L_20 , V_45 ) ;
V_123 = F_50 ( V_3 , V_116 , V_124 ) ;
if ( V_123 )
F_20 ( V_3 -> V_26 , L_21 , V_45 ) ;
}
return V_45 ;
}
int F_51 ( struct V_2 * V_3 , int V_83 )
{
struct V_42 * V_43 ;
int V_24 ;
int V_45 ;
V_45 = F_32 ( V_3 , V_83 ) ;
if ( V_45 )
return V_45 ;
V_45 = F_42 ( V_3 ) ;
if ( V_45 )
goto V_126;
V_45 = F_44 ( V_3 ) ;
if ( V_45 )
goto V_127;
for ( V_24 = 0 ; V_24 < V_83 ; V_24 ++ ) {
V_43 = & V_3 -> V_48 . V_49 [ V_24 ] ;
if ( ! V_43 -> V_50 )
continue;
V_45 = V_43 -> V_128 ( V_3 , V_43 ) ;
if ( V_45 )
goto V_129;
}
return 0 ;
V_129:
for ( V_24 -- ; V_24 >= 0 ; V_24 -- ) {
V_43 = & V_3 -> V_48 . V_49 [ V_24 ] ;
if ( ! V_43 -> V_50 )
continue;
V_43 -> V_130 ( V_3 , V_43 ) ;
}
F_46 ( V_3 ) ;
V_127:
F_43 ( V_3 ) ;
V_126:
F_41 ( V_3 ) ;
return V_45 ;
}
static int F_52 ( struct V_2 * V_3 )
{
int V_45 , V_123 , V_116 = V_3 -> V_26 -> V_114 . V_115 . V_116 ;
F_49 ( V_3 ) ;
V_45 = F_50 ( V_3 , V_116 , V_124 ) ;
if ( V_45 ) {
F_20 ( V_3 -> V_26 , L_22 , V_45 ) ;
V_123 = F_50 ( V_3 , V_116 , V_16 ) ;
if ( V_123 )
F_20 ( V_3 -> V_26 , L_23 , V_45 ) ;
}
return V_45 ;
}
void F_53 ( struct V_2 * V_3 , int V_83 )
{
struct V_42 * V_43 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_83 ; V_24 ++ ) {
V_43 = & V_3 -> V_48 . V_49 [ V_24 ] ;
if ( ! V_43 -> V_50 )
continue;
V_43 -> V_130 ( V_3 , V_43 ) ;
}
F_46 ( V_3 ) ;
F_43 ( V_3 ) ;
F_41 ( V_3 ) ;
}
static int F_54 ( T_3 V_15 , T_3 * V_131 )
{
switch ( V_15 ) {
case V_132 :
* V_131 = V_124 ;
break;
case V_133 :
* V_131 = V_16 ;
break;
default:
return - V_125 ;
}
return 0 ;
}
static int F_55 ( T_3 V_131 , T_3 * V_15 )
{
switch ( V_131 ) {
case V_124 :
* V_15 = V_132 ;
break;
case V_16 :
* V_15 = V_133 ;
break;
default:
return - V_125 ;
}
return 0 ;
}
int F_56 ( struct V_134 * V_134 , T_3 V_15 )
{
struct V_86 * V_26 ;
T_3 V_135 , V_131 = 0 ;
V_26 = F_57 ( V_134 ) ;
if ( ! F_58 ( V_26 , V_136 ) )
return - V_17 ;
V_135 = V_26 -> V_114 . V_137 -> V_15 ;
if ( V_135 == V_138 )
return - V_17 ;
if ( F_54 ( V_15 , & V_131 ) )
return - V_125 ;
if ( V_135 == V_131 )
return 0 ;
if ( V_15 == V_133 )
return F_48 ( V_26 -> V_114 . V_137 ) ;
else if ( V_15 == V_132 )
return F_52 ( V_26 -> V_114 . V_137 ) ;
else
return - V_125 ;
}
int F_59 ( struct V_134 * V_134 , T_3 * V_15 )
{
struct V_86 * V_26 ;
V_26 = F_57 ( V_134 ) ;
if ( ! F_58 ( V_26 , V_136 ) )
return - V_17 ;
if ( V_26 -> V_114 . V_137 -> V_15 == V_138 )
return - V_17 ;
return F_55 ( V_26 -> V_114 . V_137 -> V_15 , V_15 ) ;
}
void F_60 ( struct V_2 * V_3 ,
int V_139 ,
struct V_42 * V_140 )
{
struct V_117 * V_48 = & V_3 -> V_48 ;
struct V_42 * V_43 ;
V_43 = & V_48 -> V_49 [ V_139 ] ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
V_43 -> V_128 = V_140 -> V_128 ;
V_43 -> V_130 = V_140 -> V_130 ;
V_43 -> V_24 = V_140 -> V_24 ;
V_43 -> V_141 = V_140 -> V_141 ;
F_61 ( V_43 -> V_142 , V_140 -> V_142 ) ;
F_62 ( & V_43 -> V_81 ) ;
V_43 -> V_50 = true ;
}
void F_63 ( struct V_2 * V_3 ,
int V_139 )
{
struct V_117 * V_48 = & V_3 -> V_48 ;
struct V_42 * V_43 ;
V_43 = & V_48 -> V_49 [ V_139 ] ;
if ( V_3 -> V_15 == V_16 && V_3 -> V_143 [ V_139 ] . V_144 )
V_43 -> V_130 ( V_3 , V_43 ) ;
V_43 -> V_50 = false ;
}
