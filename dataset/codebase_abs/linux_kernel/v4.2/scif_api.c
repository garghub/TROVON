T_1 F_1 ( void )
{
struct V_1 * V_2 ;
F_2 () ;
V_2 = F_3 ( sizeof( * V_2 ) , V_3 ) ;
if ( ! V_2 )
goto V_4;
V_2 -> V_5 . V_6 = F_3 ( sizeof( * V_2 -> V_5 . V_6 ) , V_3 ) ;
if ( ! V_2 -> V_5 . V_6 )
goto V_7;
F_4 ( & V_2 -> V_8 ) ;
F_5 ( & V_2 -> V_9 ) ;
F_5 ( & V_2 -> V_10 ) ;
V_2 -> V_11 = V_12 ;
F_6 ( V_13 . V_14 . V_15 ,
L_1 , V_2 ) ;
return V_2 ;
V_7:
F_7 ( V_2 ) ;
V_4:
return NULL ;
}
static struct V_1 * F_8 ( struct V_1 * V_2 )
{
struct V_16 V_17 ;
struct V_1 * V_18 = NULL ;
struct V_1 * V_19 ;
struct V_20 * V_21 , * V_22 ;
int V_23 ;
F_9 ( & V_2 -> V_24 ) ;
F_9 ( & V_2 -> V_25 ) ;
F_10 ( & V_2 -> V_9 ) ;
F_11 ( & V_2 -> V_9 ) ;
F_10 ( & V_2 -> V_10 ) ;
F_11 ( & V_2 -> V_10 ) ;
F_10 ( & V_13 . V_26 ) ;
F_12 (pos, tmpq, &scif_info.connected) {
V_19 = F_13 ( V_21 , struct V_1 , V_27 ) ;
if ( V_19 == V_2 ) {
F_14 ( V_21 ) ;
V_18 = V_19 ;
F_15 ( & V_2 -> V_8 ) ;
break;
}
}
if ( ! V_18 ) {
F_12 (pos, tmpq, &scif_info.disconnected) {
V_19 = F_13 ( V_21 , struct V_1 , V_27 ) ;
if ( V_19 == V_2 ) {
F_14 ( V_21 ) ;
break;
}
}
F_11 ( & V_13 . V_26 ) ;
return NULL ;
}
F_16 ( & V_2 -> V_28 ) ;
V_17 . V_29 = V_30 ;
V_17 . V_31 = V_2 -> V_32 ;
V_17 . V_33 = V_2 -> V_34 ;
V_17 . V_35 [ 0 ] = ( V_36 ) V_2 ;
V_17 . V_35 [ 1 ] = V_2 -> V_37 ;
V_23 = F_17 ( V_2 -> V_38 , & V_17 ) ;
F_18 ( & V_2 -> V_8 ) ;
F_11 ( & V_13 . V_26 ) ;
if ( ! V_23 )
F_19 ( & V_2 -> V_28 ,
V_39 ) ;
return V_2 ;
}
int F_20 ( T_1 V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
struct V_1 * V_19 ;
struct V_20 * V_21 , * V_22 ;
enum V_41 V_42 ;
bool V_43 ;
F_6 ( V_13 . V_14 . V_15 , L_2 ,
V_2 , V_44 [ V_2 -> V_11 ] ) ;
F_2 () ;
F_15 ( & V_2 -> V_8 ) ;
V_43 = ( V_2 -> V_45 == V_46 ) ;
F_18 ( & V_2 -> V_8 ) ;
if ( V_43 )
F_21 ( & V_13 . V_47 ) ;
F_15 ( & V_2 -> V_8 ) ;
V_42 = V_2 -> V_11 ;
V_2 -> V_11 = V_48 ;
switch ( V_42 ) {
case V_49 :
case V_50 :
F_18 ( & V_2 -> V_8 ) ;
F_10 ( & V_13 . V_26 ) ;
F_12 (pos, tmpq, &scif_info.disconnected) {
V_19 = F_13 ( V_21 , struct V_1 , V_27 ) ;
if ( V_19 == V_2 ) {
F_14 ( V_21 ) ;
break;
}
}
F_11 ( & V_13 . V_26 ) ;
break;
case V_12 :
case V_51 :
case V_52 :
F_18 ( & V_2 -> V_8 ) ;
break;
case V_53 :
case V_54 :
case V_48 :
{
F_18 ( & V_2 -> V_8 ) ;
F_8 ( V_2 ) ;
break;
}
case V_55 :
case V_56 :
{
struct V_57 * V_58 ;
struct V_16 V_17 ;
struct V_1 * V_59 ;
F_18 ( & V_2 -> V_8 ) ;
F_15 ( & V_13 . V_60 ) ;
F_12 (pos, tmpq, &scif_info.listen) {
V_19 = F_13 ( V_21 , struct V_1 , V_27 ) ;
if ( V_19 == V_2 )
F_14 ( V_21 ) ;
}
while ( V_2 -> V_61 ) {
V_59 = F_22 ( & V_2 -> V_62 ,
struct V_1 , V_63 ) ;
F_14 ( & V_59 -> V_63 ) ;
F_23 ( V_59 -> V_32 . V_32 ) ;
F_12 (pos, tmpq, &scif_info.uaccept) {
V_19 = F_13 ( V_21 , struct V_1 ,
V_64 ) ;
if ( V_19 == V_59 ) {
F_14 ( V_21 ) ;
break;
}
}
F_18 ( & V_13 . V_60 ) ;
F_10 ( & V_13 . V_26 ) ;
F_12 (pos, tmpq, &scif_info.connected) {
V_19 = F_13 ( V_21 ,
struct V_1 , V_27 ) ;
if ( V_19 == V_59 ) {
F_14 ( V_21 ) ;
break;
}
}
F_12 (pos, tmpq, &scif_info.disconnected) {
V_19 = F_13 ( V_21 ,
struct V_1 , V_27 ) ;
if ( V_19 == V_59 ) {
F_14 ( V_21 ) ;
break;
}
}
F_11 ( & V_13 . V_26 ) ;
F_24 ( V_59 ) ;
F_15 ( & V_13 . V_60 ) ;
F_25 ( V_59 , V_65 ) ;
V_2 -> V_61 -- ;
}
F_15 ( & V_2 -> V_8 ) ;
F_18 ( & V_13 . V_60 ) ;
while ( V_2 -> V_66 ) {
V_58 = F_22 ( & V_2 -> V_67 ,
struct V_57 , V_27 ) ;
F_14 ( & V_58 -> V_27 ) ;
V_17 . V_29 = V_68 ;
V_17 . V_33 . V_69 = V_58 -> V_17 . V_31 . V_69 ;
V_17 . V_33 . V_32 = V_58 -> V_17 . V_31 . V_32 ;
V_17 . V_35 [ 0 ] = V_58 -> V_17 . V_35 [ 0 ] ;
V_17 . V_35 [ 1 ] = V_58 -> V_17 . V_35 [ 1 ] ;
F_17 ( & V_70 [ V_58 -> V_17 . V_31 . V_69 ] ,
& V_17 ) ;
V_2 -> V_66 -- ;
F_7 ( V_58 ) ;
}
F_18 ( & V_2 -> V_8 ) ;
F_9 ( & V_2 -> V_71 ) ;
break;
}
}
F_23 ( V_2 -> V_32 . V_32 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 , ! V_65 ) ;
return 0 ;
}
int F_26 ( T_1 V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
switch ( V_2 -> V_11 ) {
case V_55 :
{
V_2 -> V_11 = V_56 ;
F_9 ( & V_2 -> V_71 ) ;
break;
}
default:
break;
}
return 0 ;
}
int F_27 ( T_1 V_40 , T_2 V_72 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
int V_73 = 0 ;
int V_74 ;
F_6 ( V_13 . V_14 . V_15 ,
L_3 ,
V_2 , V_44 [ V_2 -> V_11 ] , V_72 ) ;
if ( V_72 ) {
if ( V_72 < V_75 && ! F_28 ( V_76 ) ) {
V_73 = - V_77 ;
goto V_78;
}
}
F_15 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_11 == V_51 ) {
V_73 = - V_79 ;
goto V_80;
} else if ( V_2 -> V_11 != V_12 ) {
V_73 = - V_81 ;
goto V_80;
}
if ( V_72 ) {
V_74 = F_29 ( V_72 ) ;
if ( V_74 != V_72 ) {
V_73 = - V_79 ;
goto V_80;
}
} else {
V_72 = F_30 () ;
if ( ! V_72 ) {
V_73 = - V_82 ;
goto V_80;
}
}
V_2 -> V_11 = V_51 ;
V_2 -> V_32 . V_69 = V_13 . V_83 ;
V_2 -> V_32 . V_32 = V_72 ;
V_2 -> V_45 = V_84 ;
V_73 = V_72 ;
F_6 ( V_13 . V_14 . V_15 ,
L_4 , V_72 ) ;
V_80:
F_18 ( & V_2 -> V_8 ) ;
V_78:
return V_73 ;
}
int F_31 ( T_1 V_40 , int V_85 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
F_6 ( V_13 . V_14 . V_15 ,
L_5 , V_2 , V_44 [ V_2 -> V_11 ] ) ;
F_15 ( & V_2 -> V_8 ) ;
switch ( V_2 -> V_11 ) {
case V_49 :
case V_48 :
case V_56 :
case V_12 :
case V_50 :
F_18 ( & V_2 -> V_8 ) ;
return - V_79 ;
case V_55 :
case V_54 :
case V_52 :
case V_53 :
F_18 ( & V_2 -> V_8 ) ;
return - V_81 ;
case V_51 :
break;
}
V_2 -> V_11 = V_55 ;
V_2 -> V_85 = V_85 ;
V_2 -> V_66 = 0 ;
V_2 -> V_61 = 0 ;
F_32 ( & V_2 -> V_67 ) ;
F_33 ( & V_2 -> V_71 ) ;
F_32 ( & V_2 -> V_62 ) ;
F_18 ( & V_2 -> V_8 ) ;
F_24 ( V_2 ) ;
V_2 -> V_5 . V_6 = NULL ;
F_15 ( & V_13 . V_60 ) ;
F_34 ( & V_2 -> V_27 , & V_13 . V_86 ) ;
F_18 ( & V_13 . V_60 ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
int V_23 = 0 ;
struct V_16 V_17 ;
struct V_87 * V_88 ;
V_23 = F_36 ( V_2 -> V_5 . V_6 , & V_2 -> V_5 . V_89 ,
V_90 , V_2 -> V_38 ) ;
if ( V_23 ) {
F_37 ( & V_2 -> V_38 -> V_91 -> V_92 ,
L_6 ,
V_93 , V_23 , V_2 -> V_5 . V_89 ) ;
V_2 -> V_11 = V_51 ;
goto V_94;
}
V_88 = F_38 ( V_2 -> V_38 ) ;
if ( F_39 ( V_88 ) ) {
V_23 = F_40 ( V_88 ) ;
goto V_95;
}
V_17 . V_31 = V_2 -> V_32 ;
V_17 . V_33 = V_2 -> V_96 ;
V_17 . V_29 = V_97 ;
V_17 . V_35 [ 0 ] = ( V_36 ) V_2 ;
V_17 . V_35 [ 1 ] = V_2 -> V_5 . V_89 ;
V_23 = F_41 ( V_2 -> V_38 , & V_17 ) ;
if ( V_23 )
goto V_98;
F_42 ( V_88 ) ;
V_23 = F_43 ( V_2 -> V_71 , V_2 -> V_11 != V_52 ,
V_39 ) ;
if ( ! V_23 ) {
F_37 ( & V_2 -> V_38 -> V_91 -> V_92 ,
L_7 , V_93 , __LINE__ ) ;
V_2 -> V_11 = V_51 ;
}
V_88 = F_38 ( V_2 -> V_38 ) ;
if ( F_39 ( V_88 ) ) {
V_23 = F_40 ( V_88 ) ;
goto V_95;
}
if ( V_2 -> V_11 == V_53 ) {
V_23 = F_44 ( V_2 -> V_38 ,
V_2 -> V_5 . V_6 ,
V_2 -> V_5 . V_99 ) ;
if ( V_23 ) {
F_37 ( & V_2 -> V_38 -> V_91 -> V_92 ,
L_8 , V_93 , __LINE__ , V_23 ) ;
V_17 . V_29 = V_100 ;
V_17 . V_35 [ 0 ] = V_2 -> V_37 ;
F_41 ( V_2 -> V_38 , & V_17 ) ;
V_2 -> V_11 = V_51 ;
goto V_98;
}
V_17 . V_29 = V_101 ;
V_17 . V_35 [ 0 ] = V_2 -> V_37 ;
V_23 = F_41 ( V_2 -> V_38 , & V_17 ) ;
if ( V_23 ) {
V_2 -> V_11 = V_51 ;
goto V_98;
}
V_2 -> V_11 = V_54 ;
F_10 ( & V_13 . V_26 ) ;
F_34 ( & V_2 -> V_27 , & V_13 . V_102 ) ;
F_11 ( & V_13 . V_26 ) ;
F_6 ( & V_2 -> V_38 -> V_91 -> V_92 ,
L_9 , V_2 ) ;
} else if ( V_2 -> V_11 == V_51 ) {
F_6 ( & V_2 -> V_38 -> V_91 -> V_92 ,
L_10 , V_2 ) ;
V_23 = - V_103 ;
goto V_98;
}
F_42 ( V_88 ) ;
return V_23 ;
V_98:
F_42 ( V_88 ) ;
V_95:
F_45 ( V_2 ) ;
V_94:
return V_23 ;
}
void F_46 ( struct V_104 * V_105 )
{
struct V_1 * V_2 ;
do {
V_2 = NULL ;
F_15 ( & V_13 . V_106 ) ;
if ( ! F_47 ( & V_13 . V_107 ) ) {
V_2 = F_22 ( & V_13 . V_107 ,
struct V_1 , V_108 ) ;
F_14 ( & V_2 -> V_108 ) ;
}
F_18 ( & V_13 . V_106 ) ;
if ( V_2 )
V_2 -> V_109 = F_35 ( V_2 ) ;
} while ( V_2 );
}
int F_48 ( T_1 V_40 , struct V_110 * V_33 , bool V_111 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
int V_23 = 0 ;
struct V_70 * V_38 ;
struct V_87 * V_88 ;
F_6 ( V_13 . V_14 . V_15 , L_11 , V_2 ,
V_44 [ V_2 -> V_11 ] ) ;
if ( ! V_70 || V_33 -> V_69 > V_13 . V_112 )
return - V_113 ;
F_2 () ;
V_38 = & V_70 [ V_33 -> V_69 ] ;
V_88 = F_38 ( V_38 ) ;
if ( F_39 ( V_88 ) ) {
V_23 = F_40 ( V_88 ) ;
return V_23 ;
}
F_15 ( & V_2 -> V_8 ) ;
switch ( V_2 -> V_11 ) {
case V_49 :
case V_48 :
V_23 = - V_79 ;
break;
case V_50 :
if ( V_2 -> V_45 == V_46 )
V_2 -> V_45 = V_114 ;
else
V_23 = - V_79 ;
break;
case V_55 :
case V_56 :
V_23 = - V_115 ;
break;
case V_52 :
case V_53 :
if ( V_2 -> V_45 == V_46 )
V_23 = - V_116 ;
else
V_23 = - V_81 ;
break;
case V_54 :
if ( V_2 -> V_45 == V_46 )
V_2 -> V_45 = V_114 ;
else
V_23 = - V_81 ;
break;
case V_12 :
V_2 -> V_32 . V_32 = F_30 () ;
if ( ! V_2 -> V_32 . V_32 ) {
V_23 = - V_82 ;
} else {
V_2 -> V_32 . V_69 = V_13 . V_83 ;
V_2 -> V_45 = V_84 ;
}
case V_51 :
if ( V_2 -> V_45 == V_46 ) {
V_2 -> V_45 = V_114 ;
} else if ( V_2 -> V_45 == V_114 ) {
V_23 = - V_116 ;
} else {
V_2 -> V_96 = * V_33 ;
F_33 ( & V_2 -> V_24 ) ;
F_33 ( & V_2 -> V_25 ) ;
F_33 ( & V_2 -> V_71 ) ;
V_2 -> V_45 = 0 ;
if ( F_49 ( V_111 ) )
V_2 -> V_45 = V_46 ;
}
break;
}
if ( V_23 || V_2 -> V_45 == V_114 )
goto V_117;
V_2 -> V_11 = V_52 ;
V_2 -> V_38 = & V_70 [ V_33 -> V_69 ] ;
V_2 -> V_5 . V_6 -> V_118 = V_119 ;
if ( V_2 -> V_45 == V_46 ) {
F_15 ( & V_13 . V_106 ) ;
F_34 ( & V_2 -> V_108 , & V_13 . V_107 ) ;
F_18 ( & V_13 . V_106 ) ;
V_23 = - V_116 ;
F_50 ( & V_13 . V_47 ) ;
}
V_117:
F_18 ( & V_2 -> V_8 ) ;
F_42 ( V_88 ) ;
if ( V_23 ) {
return V_23 ;
} else if ( V_2 -> V_45 == V_114 ) {
F_21 ( & V_13 . V_47 ) ;
V_23 = V_2 -> V_109 ;
F_15 ( & V_2 -> V_8 ) ;
V_2 -> V_45 = V_84 ;
F_18 ( & V_2 -> V_8 ) ;
} else {
V_23 = F_35 ( V_2 ) ;
}
return V_23 ;
}
int F_51 ( T_1 V_40 , struct V_110 * V_33 )
{
return F_48 ( V_40 , V_33 , false ) ;
}
int F_52 ( T_1 V_40 , struct V_110 * V_34 ,
T_1 * V_120 , int V_121 )
{
struct V_1 * V_122 = (struct V_1 * ) V_40 ;
struct V_1 * V_123 ;
struct V_57 * V_58 ;
struct V_16 V_17 ;
int V_23 ;
struct V_87 * V_88 ;
F_6 ( V_13 . V_14 . V_15 ,
L_12 , V_122 , V_44 [ V_122 -> V_11 ] ) ;
if ( V_121 & ~ V_124 )
return - V_79 ;
if ( ! V_34 || ! V_120 )
return - V_79 ;
F_2 () ;
F_15 ( & V_122 -> V_8 ) ;
if ( V_122 -> V_11 != V_55 ) {
F_18 ( & V_122 -> V_8 ) ;
return - V_79 ;
}
if ( ! V_122 -> V_66 && ! ( V_121 & V_124 ) ) {
F_18 ( & V_122 -> V_8 ) ;
return - V_125 ;
}
V_122 -> V_126 = V_127 -> V_126 ;
V_128:
F_18 ( & V_122 -> V_8 ) ;
V_23 = F_53 ( V_122 -> V_71 ,
( V_122 -> V_66 ||
( V_122 -> V_11 != V_55 ) ) ) ;
if ( V_23 )
return V_23 ;
if ( V_122 -> V_11 != V_55 )
return - V_129 ;
F_15 ( & V_122 -> V_8 ) ;
if ( ! V_122 -> V_66 )
goto V_128;
V_58 = F_22 ( & V_122 -> V_67 , struct V_57 , V_27 ) ;
F_14 ( & V_58 -> V_27 ) ;
V_122 -> V_66 -- ;
F_18 ( & V_122 -> V_8 ) ;
V_34 -> V_69 = V_58 -> V_17 . V_31 . V_69 ;
V_34 -> V_32 = V_58 -> V_17 . V_31 . V_32 ;
V_123 = F_3 ( sizeof( * V_123 ) , V_3 ) ;
if ( ! V_123 ) {
V_23 = - V_130 ;
goto V_131;
}
F_4 ( & V_123 -> V_8 ) ;
F_5 ( & V_123 -> V_9 ) ;
F_5 ( & V_123 -> V_10 ) ;
V_123 -> V_11 = V_52 ;
V_123 -> V_38 = & V_70 [ V_34 -> V_69 ] ;
V_123 -> V_37 = V_58 -> V_17 . V_35 [ 0 ] ;
V_123 -> V_5 . V_6 = F_3 ( sizeof( * V_123 -> V_5 . V_6 ) , V_3 ) ;
if ( ! V_123 -> V_5 . V_6 ) {
V_23 = - V_130 ;
goto V_132;
}
V_123 -> V_5 . V_6 -> V_118 = V_119 ;
V_88 = F_38 ( V_123 -> V_38 ) ;
if ( F_39 ( V_88 ) ) {
V_23 = F_40 ( V_88 ) ;
goto V_133;
}
V_23 = F_54 ( V_123 -> V_5 . V_6 , & V_123 -> V_5 . V_89 ,
V_58 -> V_17 . V_35 [ 1 ] , V_90 ,
V_123 -> V_38 ) ;
if ( V_23 ) {
F_6 ( & V_123 -> V_38 -> V_91 -> V_92 ,
L_13 ,
V_122 , V_123 , V_23 , V_123 -> V_5 . V_89 ) ;
F_42 ( V_88 ) ;
goto V_133;
}
V_123 -> V_32 . V_69 = V_122 -> V_32 . V_69 ;
V_123 -> V_32 . V_32 = V_122 -> V_32 . V_32 ;
V_123 -> V_34 . V_69 = V_34 -> V_69 ;
V_123 -> V_34 . V_32 = V_34 -> V_32 ;
F_33 ( & V_123 -> V_24 ) ;
F_33 ( & V_123 -> V_25 ) ;
F_33 ( & V_123 -> V_71 ) ;
V_17 . V_29 = V_134 ;
V_17 . V_31 = V_123 -> V_32 ;
V_17 . V_35 [ 0 ] = V_123 -> V_37 ;
V_17 . V_35 [ 1 ] = V_123 -> V_5 . V_89 ;
V_17 . V_35 [ 2 ] = ( V_36 ) V_123 ;
V_23 = F_41 ( V_123 -> V_38 , & V_17 ) ;
F_42 ( V_88 ) ;
if ( V_23 )
goto V_133;
V_135:
V_23 = F_43 ( V_123 -> V_71 , V_123 -> V_11 != V_52 ,
V_136 ) ;
if ( ! V_23 && F_55 ( V_123 ) )
goto V_135;
V_23 = ! V_23 ? - V_113 : 0 ;
if ( V_23 )
goto V_133;
F_7 ( V_58 ) ;
F_15 ( & V_123 -> V_8 ) ;
if ( V_123 -> V_11 == V_48 ) {
F_18 ( & V_123 -> V_8 ) ;
F_24 ( V_123 ) ;
F_7 ( V_123 ) ;
if ( V_121 & V_124 ) {
F_15 ( & V_122 -> V_8 ) ;
goto V_128;
}
return - V_125 ;
}
F_56 ( V_123 -> V_32 . V_32 ) ;
* V_120 = ( T_1 ) V_123 ;
F_18 ( & V_123 -> V_8 ) ;
return 0 ;
V_133:
F_24 ( V_123 ) ;
V_132:
F_7 ( V_123 ) ;
V_131:
V_17 . V_29 = V_68 ;
V_17 . V_33 . V_69 = V_58 -> V_17 . V_31 . V_69 ;
V_17 . V_33 . V_32 = V_58 -> V_17 . V_31 . V_32 ;
V_17 . V_35 [ 0 ] = V_58 -> V_17 . V_35 [ 0 ] ;
V_17 . V_35 [ 1 ] = V_58 -> V_17 . V_35 [ 1 ] ;
F_17 ( & V_70 [ V_58 -> V_17 . V_31 . V_69 ] , & V_17 ) ;
F_7 ( V_58 ) ;
return V_23 ;
}
static inline int F_57 ( T_1 V_40 , int V_137 , int V_121 )
{
int V_73 = - V_79 ;
if ( V_137 < 0 )
goto V_138;
if ( V_121 && ( ! ( V_121 & V_139 ) ) )
goto V_138;
V_73 = 0 ;
V_138:
return V_73 ;
}
static int F_58 ( T_1 V_40 , void * V_17 , int V_137 , int V_121 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
struct V_16 V_140 ;
int V_141 = 0 , V_142 = 0 , V_143 ;
int V_73 = 0 ;
struct V_144 * V_6 = V_2 -> V_5 . V_6 ;
if ( V_121 & V_145 )
F_2 () ;
F_15 ( & V_2 -> V_8 ) ;
while ( V_142 != V_137 && V_54 == V_2 -> V_11 ) {
V_143 = F_59 ( & V_6 -> V_146 ) ;
if ( V_143 ) {
V_141 = F_60 ( V_137 - V_142 , V_143 ) ;
V_73 = F_61 ( & V_6 -> V_146 , V_17 ,
V_141 ) ;
if ( V_73 < 0 )
break;
F_62 ( & V_6 -> V_146 ) ;
V_140 . V_31 = V_2 -> V_32 ;
V_140 . V_29 = V_147 ;
V_140 . V_35 [ 0 ] = V_2 -> V_37 ;
V_73 = F_41 ( V_2 -> V_38 , & V_140 ) ;
if ( V_73 )
break;
V_142 += V_141 ;
V_17 = V_17 + V_141 ;
continue;
}
V_141 = F_60 ( V_137 - V_142 , V_90 - 1 ) ;
if ( ! ( V_121 & V_145 ) )
break;
F_18 ( & V_2 -> V_8 ) ;
V_73 =
F_53 ( V_2 -> V_24 ,
( V_54 != V_2 -> V_11 ) ||
( F_59 ( & V_6 -> V_146 ) >=
V_141 ) ) ;
F_15 ( & V_2 -> V_8 ) ;
if ( V_73 )
break;
}
if ( V_142 )
V_73 = V_142 ;
else if ( ! V_73 && V_54 != V_2 -> V_11 )
V_73 = V_50 == V_2 -> V_11 ?
- V_148 : - V_149 ;
F_18 ( & V_2 -> V_8 ) ;
return V_73 ;
}
static int F_63 ( T_1 V_40 , void * V_17 , int V_137 , int V_121 )
{
int V_150 ;
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
struct V_16 V_140 ;
int V_151 = 0 , V_152 = V_137 , V_153 ;
int V_73 = 0 ;
struct V_144 * V_6 = V_2 -> V_5 . V_6 ;
if ( V_121 & V_139 )
F_2 () ;
F_15 ( & V_2 -> V_8 ) ;
while ( V_152 && ( V_54 == V_2 -> V_11 ||
V_50 == V_2 -> V_11 ) ) {
V_153 = F_64 ( & V_6 -> V_154 , V_152 ) ;
if ( V_153 ) {
V_151 = F_60 ( V_152 , V_153 ) ;
V_150 = F_65 ( & V_6 -> V_154 ,
V_17 , V_151 ) ;
if ( V_2 -> V_11 == V_54 ) {
F_66 ( & V_6 -> V_154 ) ;
V_140 . V_31 = V_2 -> V_32 ;
V_140 . V_29 = V_155 ;
V_140 . V_35 [ 0 ] = V_2 -> V_37 ;
V_73 = F_41 ( V_2 -> V_38 ,
& V_140 ) ;
if ( V_73 )
break;
}
V_152 -= V_151 ;
V_17 = V_17 + V_151 ;
continue;
}
if ( V_2 -> V_11 == V_50 )
break;
if ( ! ( V_121 & V_139 ) )
break;
V_151 = F_60 ( V_152 , V_90 - 1 ) ;
F_18 ( & V_2 -> V_8 ) ;
V_73 =
F_53 ( V_2 -> V_25 ,
V_54 != V_2 -> V_11 ||
F_64 ( & V_6 -> V_154 ,
V_151 )
>= V_151 ) ;
F_15 ( & V_2 -> V_8 ) ;
if ( V_73 )
break;
}
if ( V_137 - V_152 )
V_73 = V_137 - V_152 ;
else if ( ! V_73 && V_2 -> V_11 != V_54 )
V_73 = V_2 -> V_11 == V_50 ?
- V_148 : - V_149 ;
F_18 ( & V_2 -> V_8 ) ;
return V_73 ;
}
int F_67 ( T_1 V_40 , void T_3 * V_17 , int V_137 , int V_121 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
int V_23 = 0 ;
int V_142 = 0 ;
char * V_74 ;
int V_156 ;
int V_157 = F_60 ( V_137 , ( 1 << ( V_158 + V_159 - 1 ) ) ) ;
F_6 ( V_13 . V_14 . V_15 ,
L_14 , V_2 , V_44 [ V_2 -> V_11 ] ) ;
if ( ! V_137 )
return 0 ;
V_23 = F_57 ( V_40 , V_137 , V_121 ) ;
if ( V_23 )
goto V_160;
V_74 = F_68 ( V_157 , V_3 ) ;
if ( ! V_74 ) {
V_23 = - V_130 ;
goto V_160;
}
F_10 ( & V_2 -> V_9 ) ;
while ( V_142 != V_137 ) {
V_156 = V_137 - V_142 ;
V_156 = F_60 ( V_157 , V_156 ) ;
if ( F_69 ( V_74 , V_17 , V_156 ) ) {
V_23 = - V_161 ;
goto V_162;
}
V_23 = F_58 ( V_40 , V_74 , V_156 , V_121 ) ;
if ( V_23 < 0 )
goto V_162;
V_142 += V_23 ;
V_17 += V_23 ;
if ( V_23 != V_156 )
goto V_162;
}
V_162:
F_11 ( & V_2 -> V_9 ) ;
F_7 ( V_74 ) ;
V_160:
return V_23 < 0 ? V_23 : V_142 ;
}
int F_70 ( T_1 V_40 , void T_3 * V_17 , int V_137 , int V_121 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
int V_23 = 0 ;
int V_163 = 0 ;
char * V_74 ;
int V_156 ;
int V_157 = F_60 ( V_137 , ( 1 << ( V_158 + V_159 - 1 ) ) ) ;
F_6 ( V_13 . V_14 . V_15 ,
L_15 , V_2 , V_44 [ V_2 -> V_11 ] ) ;
if ( ! V_137 )
return 0 ;
V_23 = F_57 ( V_40 , V_137 , V_121 ) ;
if ( V_23 )
goto V_164;
V_74 = F_68 ( V_157 , V_3 ) ;
if ( ! V_74 ) {
V_23 = - V_130 ;
goto V_164;
}
F_10 ( & V_2 -> V_10 ) ;
while ( V_163 != V_137 ) {
V_156 = V_137 - V_163 ;
V_156 = F_60 ( V_157 , V_156 ) ;
V_23 = F_63 ( V_40 , V_74 , V_156 , V_121 ) ;
if ( V_23 < 0 )
goto V_165;
if ( F_71 ( V_17 , V_74 , V_23 ) ) {
V_23 = - V_161 ;
goto V_165;
}
V_163 += V_23 ;
V_17 += V_23 ;
if ( V_23 != V_156 )
goto V_165;
}
V_165:
F_11 ( & V_2 -> V_10 ) ;
F_7 ( V_74 ) ;
V_164:
return V_23 < 0 ? V_23 : V_163 ;
}
int F_72 ( T_1 V_40 , void * V_17 , int V_137 , int V_121 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
int V_73 ;
F_6 ( V_13 . V_14 . V_15 ,
L_16 , V_2 , V_44 [ V_2 -> V_11 ] ) ;
if ( ! V_137 )
return 0 ;
V_73 = F_57 ( V_40 , V_137 , V_121 ) ;
if ( V_73 )
return V_73 ;
if ( ! V_2 -> V_38 )
return - V_149 ;
if ( V_121 & V_145 )
F_10 ( & V_2 -> V_9 ) ;
V_73 = F_58 ( V_40 , V_17 , V_137 , V_121 ) ;
if ( V_121 & V_145 )
F_11 ( & V_2 -> V_9 ) ;
return V_73 ;
}
int F_73 ( T_1 V_40 , void * V_17 , int V_137 , int V_121 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
int V_73 ;
F_6 ( V_13 . V_14 . V_15 ,
L_17 , V_2 , V_44 [ V_2 -> V_11 ] ) ;
if ( ! V_137 )
return 0 ;
V_73 = F_57 ( V_40 , V_137 , V_121 ) ;
if ( V_73 )
return V_73 ;
if ( V_121 & V_139 )
F_10 ( & V_2 -> V_10 ) ;
V_73 = F_63 ( V_40 , V_17 , V_137 , V_121 ) ;
if ( V_121 & V_139 )
F_11 ( & V_2 -> V_10 ) ;
return V_73 ;
}
int F_74 ( T_2 * V_166 , int V_137 , T_2 * V_167 )
{
int V_168 = 0 ;
int V_169 = 0 ;
int V_69 ;
if ( ! F_75 () )
F_76 () ;
* V_167 = V_13 . V_83 ;
F_10 ( & V_13 . V_170 ) ;
V_137 = F_77 ( int , V_137 , V_13 . V_171 ) ;
for ( V_69 = 0 ; V_69 <= V_13 . V_112 ; V_69 ++ ) {
if ( F_78 ( & V_70 [ V_69 ] ) ) {
V_168 ++ ;
if ( V_169 < V_137 )
V_166 [ V_169 ++ ] = V_69 ;
}
}
F_6 ( V_13 . V_14 . V_15 ,
L_18 ,
V_13 . V_171 , V_168 , V_169 ) ;
F_11 ( & V_13 . V_170 ) ;
return V_168 ;
}
