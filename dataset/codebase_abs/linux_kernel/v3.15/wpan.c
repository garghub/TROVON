static int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 =
(struct V_8 * ) & V_4 -> V_10 ;
int V_11 = - V_12 ;
F_3 ( & V_7 -> V_13 ) ;
switch ( V_5 ) {
case V_14 :
{
T_1 V_15 , V_16 ;
V_15 = F_4 ( V_7 -> V_15 ) ;
V_16 = F_4 ( V_7 -> V_16 ) ;
if ( V_15 == V_17 ||
V_16 == V_18 ) {
V_11 = - V_19 ;
break;
}
V_9 -> V_20 = V_21 ;
V_9 -> V_22 . V_23 = V_24 ;
V_9 -> V_22 . V_15 = V_15 ;
V_9 -> V_22 . V_16 = V_16 ;
V_11 = 0 ;
break;
}
case V_25 :
F_5 ( & V_2 -> V_2 ,
L_1 ) ;
if ( V_9 -> V_20 != V_21 ||
V_9 -> V_22 . V_23 != V_24 ||
V_9 -> V_22 . V_15 == V_17 ||
V_9 -> V_22 . V_16 == V_18 ||
V_9 -> V_22 . V_16 == V_26 ) {
V_11 = - V_27 ;
break;
}
V_7 -> V_15 = F_6 ( V_9 -> V_22 . V_15 ) ;
V_7 -> V_16 = F_6 ( V_9 -> V_22 . V_16 ) ;
V_11 = 0 ;
break;
}
F_7 ( & V_7 -> V_13 ) ;
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 , void * V_28 )
{
struct V_29 * V_22 = V_28 ;
if ( F_9 ( V_2 ) )
return - V_30 ;
memcpy ( V_2 -> V_31 , V_22 -> V_32 , V_2 -> V_33 ) ;
F_10 ( V_2 ) ;
return 0 ;
}
int F_11 ( struct V_1 * V_2 ,
const struct V_34 * V_35 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( & V_7 -> V_36 -> V_37 ) ;
V_7 -> V_38 = * V_35 ;
F_13 ( & V_7 -> V_36 -> V_37 ) ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_12 ( & V_7 -> V_36 -> V_37 ) ;
* V_35 = V_7 -> V_38 ;
F_13 ( & V_7 -> V_36 -> V_37 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
int V_39 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_40 * V_41 = V_7 -> V_36 -> V_41 ;
V_39 = F_16 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
F_12 ( & V_41 -> V_42 ) ;
if ( V_41 -> V_43 ) {
V_39 = V_41 -> V_43 ( V_41 , V_7 -> V_38 . V_44 ) ;
if ( V_39 < 0 )
goto V_45;
}
if ( V_41 -> V_46 ) {
V_39 = V_41 -> V_46 ( V_41 , V_7 -> V_38 . V_47 ) ;
if ( V_39 < 0 )
goto V_45;
}
if ( V_41 -> V_48 ) {
V_39 = V_41 -> V_48 ( V_41 , V_7 -> V_38 . V_49 ) ;
if ( V_39 < 0 )
goto V_45;
}
if ( V_41 -> V_50 ) {
V_39 = V_41 -> V_50 ( V_41 , V_7 -> V_38 . V_51 ) ;
if ( V_39 < 0 )
goto V_45;
}
if ( V_41 -> V_52 ) {
V_39 = V_41 -> V_52 ( V_41 , V_7 -> V_38 . V_53 ,
V_7 -> V_38 . V_54 ,
V_7 -> V_38 . V_55 ) ;
if ( V_39 < 0 )
goto V_45;
}
if ( V_41 -> V_56 ) {
V_39 = V_41 -> V_56 ( V_41 ,
V_7 -> V_38 . V_57 ) ;
if ( V_39 < 0 )
goto V_45;
}
F_13 ( & V_41 -> V_42 ) ;
return 0 ;
V_45:
F_13 ( & V_41 -> V_42 ) ;
return V_39 ;
}
static int F_17 ( struct V_58 * V_59 ,
struct V_1 * V_2 ,
unsigned short type ,
const void * V_60 ,
const void * V_61 ,
unsigned V_62 )
{
struct V_63 V_64 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_65 ;
if ( ! V_60 )
return - V_27 ;
memset ( & V_64 . V_66 , 0 , sizeof( V_64 . V_66 ) ) ;
V_64 . V_66 . type = F_18 ( V_59 ) ;
V_64 . V_66 . V_67 = F_19 ( V_59 ) ;
V_64 . V_66 . V_68 = F_20 ( V_59 ) ;
if ( ! V_61 ) {
F_3 ( & V_7 -> V_13 ) ;
if ( V_7 -> V_16 == F_6 ( V_18 ) ||
V_7 -> V_16 == F_6 ( V_26 ) ||
V_7 -> V_15 == F_6 ( V_17 ) ) {
V_64 . V_69 . V_70 = V_71 ;
V_64 . V_69 . V_72 = V_7 -> V_72 ;
} else {
V_64 . V_69 . V_70 = V_24 ;
V_64 . V_69 . V_16 = V_7 -> V_16 ;
}
V_64 . V_69 . V_15 = V_7 -> V_15 ;
F_7 ( & V_7 -> V_13 ) ;
} else {
V_64 . V_69 = * ( const struct V_73 * ) V_61 ;
}
V_64 . V_74 = * ( const struct V_73 * ) V_60 ;
V_65 = F_21 ( V_59 , & V_64 ) ;
if ( V_65 < 0 )
return - V_27 ;
F_22 ( V_59 ) ;
V_59 -> V_75 = V_65 ;
if ( V_65 + V_62 + 2 > V_2 -> V_76 )
return - V_77 ;
return V_65 ;
}
static int
F_23 ( const struct V_58 * V_59 , unsigned char * V_78 )
{
struct V_63 V_64 ;
struct V_73 * V_22 = (struct V_73 * ) V_78 ;
if ( F_24 ( V_59 , & V_64 ) < 0 ) {
F_25 ( L_2 ) ;
return 0 ;
}
* V_22 = V_64 . V_69 ;
return sizeof( * V_22 ) ;
}
static T_2
F_26 ( struct V_58 * V_59 , struct V_1 * V_2 )
{
struct V_6 * V_7 ;
T_3 V_79 , V_80 ;
V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_13 ) ;
V_79 = V_7 -> V_79 ;
V_80 = V_7 -> V_80 ;
F_7 ( & V_7 -> V_13 ) ;
if ( V_79 == V_81 ||
V_80 >= V_82 ||
V_79 >= V_83 ) {
F_27 ( V_59 ) ;
return V_84 ;
}
V_59 -> V_85 = V_2 -> V_86 ;
V_2 -> V_87 . V_88 ++ ;
V_2 -> V_87 . V_89 += V_59 -> V_62 ;
return F_28 ( V_7 -> V_36 , V_59 , V_80 , V_79 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_2 -> V_33 = V_90 ;
memset ( V_2 -> V_91 , 0xff , V_90 ) ;
V_2 -> V_92 = V_93 ;
V_2 -> V_94 = & V_95 ;
V_2 -> V_96 = 2 ;
V_2 -> V_76 = V_97 ;
V_2 -> V_98 = 300 ;
V_2 -> type = V_99 ;
V_2 -> V_100 = V_101 | V_102 ;
V_2 -> V_103 = 0 ;
V_2 -> V_104 = V_105 ;
V_2 -> V_106 = & V_107 ;
V_2 -> V_108 = & V_109 ;
V_7 = F_2 ( V_2 ) ;
V_7 -> type = V_110 ;
V_7 -> V_79 = V_81 ;
V_7 -> V_80 = 0 ;
F_30 ( & V_7 -> V_13 ) ;
F_31 ( & V_7 -> V_111 , 1 ) ;
F_31 ( & V_7 -> V_112 , 1 ) ;
V_7 -> V_38 . V_53 = 3 ;
V_7 -> V_38 . V_54 = 5 ;
V_7 -> V_38 . V_55 = 4 ;
V_7 -> V_38 . V_57 = - 1 ;
V_7 -> V_15 = F_6 ( V_17 ) ;
V_7 -> V_16 = F_6 ( V_18 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_58 * V_59 )
{
return F_33 ( V_59 ) ;
}
static int
F_34 ( struct V_6 * V_113 , struct V_58 * V_59 )
{
T_4 V_114 , V_115 ;
F_25 ( L_3 , V_113 -> V_2 -> V_116 ) ;
F_3 ( & V_113 -> V_13 ) ;
V_114 = V_113 -> V_15 ;
V_115 = V_113 -> V_16 ;
switch ( F_35 ( V_59 ) -> V_74 . V_70 ) {
case V_117 :
if ( F_35 ( V_59 ) -> V_74 . V_70 != V_117 )
V_59 -> V_118 = V_119 ;
else
V_59 -> V_118 = V_120 ;
break;
case V_71 :
if ( F_35 ( V_59 ) -> V_74 . V_15 != V_114 &&
F_35 ( V_59 ) -> V_74 . V_15 != F_6 ( V_17 ) )
V_59 -> V_118 = V_119 ;
else if ( F_35 ( V_59 ) -> V_74 . V_72 == V_113 -> V_72 )
V_59 -> V_118 = V_120 ;
else
V_59 -> V_118 = V_119 ;
break;
case V_24 :
if ( F_35 ( V_59 ) -> V_74 . V_15 != V_114 &&
F_35 ( V_59 ) -> V_74 . V_15 != F_6 ( V_17 ) )
V_59 -> V_118 = V_119 ;
else if ( F_35 ( V_59 ) -> V_74 . V_16 == V_115 )
V_59 -> V_118 = V_120 ;
else if ( F_35 ( V_59 ) -> V_74 . V_16 ==
F_6 ( V_18 ) )
V_59 -> V_118 = V_121 ;
else
V_59 -> V_118 = V_119 ;
break;
default:
break;
}
F_7 ( & V_113 -> V_13 ) ;
V_59 -> V_2 = V_113 -> V_2 ;
V_113 -> V_2 -> V_87 . V_122 ++ ;
V_113 -> V_2 -> V_87 . V_123 += V_59 -> V_62 ;
switch ( F_18 ( V_59 ) ) {
case V_124 :
return F_32 ( V_113 -> V_2 , V_59 ) ;
default:
F_36 ( L_4 ,
F_18 ( V_59 ) ) ;
F_27 ( V_59 ) ;
return V_125 ;
}
}
static void F_37 ( const char * V_116 ,
const struct V_73 * V_22 )
{
if ( V_22 -> V_70 == V_117 )
F_25 ( L_5 , V_116 ) ;
F_25 ( L_6 , V_116 , F_4 ( V_22 -> V_15 ) ) ;
if ( V_22 -> V_70 == V_24 ) {
F_25 ( L_7 , V_116 ,
F_4 ( V_22 -> V_16 ) ) ;
} else {
T_5 V_36 = F_38 ( ( V_126 T_5 ) V_22 -> V_72 ) ;
F_25 ( L_8 , V_116 , & V_36 ) ;
}
}
static int F_39 ( struct V_58 * V_59 )
{
int V_65 ;
struct V_63 V_64 ;
V_65 = F_40 ( V_59 , & V_64 ) ;
if ( V_65 < 0 )
return - V_27 ;
V_59 -> V_75 = V_65 ;
F_25 ( L_9 , F_41 ( ( T_4 * ) & V_64 . V_66 ) ,
V_64 . V_127 ) ;
F_35 ( V_59 ) -> V_100 = V_64 . V_66 . type ;
if ( V_64 . V_66 . V_68 )
F_35 ( V_59 ) -> V_100 |= V_128 ;
if ( V_64 . V_66 . V_67 )
F_35 ( V_59 ) -> V_100 |= V_129 ;
F_37 ( L_10 , & V_64 . V_74 ) ;
F_37 ( L_11 , & V_64 . V_69 ) ;
F_35 ( V_59 ) -> V_69 = V_64 . V_69 ;
F_35 ( V_59 ) -> V_74 = V_64 . V_74 ;
if ( V_64 . V_66 . V_67 ) {
T_5 V_130 ;
F_25 ( L_12 , V_64 . V_131 . V_132 ) ;
switch ( V_64 . V_131 . V_133 ) {
case V_134 :
F_25 ( L_13 ) ;
break;
case V_135 :
F_25 ( L_14 , V_64 . V_131 . V_136 ) ;
break;
case V_137 :
F_25 ( L_15 ,
F_42 ( V_64 . V_131 . V_138 ) >> 16 ,
F_42 ( V_64 . V_131 . V_138 ) & 0xffff ,
V_64 . V_131 . V_136 ) ;
break;
case V_139 :
V_130 = F_38 ( ( V_126 T_5 ) V_64 . V_131 . V_140 ) ;
F_25 ( L_16 , & V_130 ,
V_64 . V_131 . V_136 ) ;
break;
}
return - V_27 ;
}
return 0 ;
}
void F_43 ( struct V_141 * V_7 , struct V_58 * V_59 )
{
int V_142 ;
struct V_58 * V_143 ;
struct V_6 * V_113 ;
V_142 = F_39 ( V_59 ) ;
if ( V_142 ) {
F_25 ( L_17 ) ;
return;
}
F_44 () ;
F_45 (sdata, &priv->slaves, list) {
if ( V_113 -> type != V_110 )
continue;
V_143 = F_46 ( V_59 , V_144 ) ;
if ( V_143 )
F_34 ( V_113 , V_143 ) ;
}
F_47 () ;
}
