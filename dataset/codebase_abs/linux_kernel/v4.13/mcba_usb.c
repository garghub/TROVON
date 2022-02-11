static inline void F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_2 -> V_5 [ V_3 ] . V_6 = V_7 ;
V_2 -> V_5 [ V_3 ] . V_2 = V_2 ;
}
F_2 ( & V_2 -> V_8 , F_3 ( V_2 -> V_5 ) ) ;
}
static inline struct V_9 * F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
int V_3 = 0 ;
struct V_9 * V_12 = NULL ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( V_2 -> V_5 [ V_3 ] . V_6 == V_7 ) {
V_12 = & V_2 -> V_5 [ V_3 ] ;
V_12 -> V_6 = V_3 ;
if ( V_11 ) {
V_12 -> V_13 = true ;
V_12 -> V_14 = V_11 -> V_15 ;
} else {
V_12 -> V_13 = false ;
V_12 -> V_14 = 0 ;
}
F_5 ( & V_2 -> V_8 ) ;
break;
}
}
if ( ! F_6 ( & V_2 -> V_8 ) )
F_7 ( V_2 -> V_16 ) ;
return V_12 ;
}
static inline void F_8 ( struct V_9 * V_12 )
{
F_9 ( & V_12 -> V_2 -> V_8 ) ;
V_12 -> V_6 = V_7 ;
F_10 ( V_12 -> V_2 -> V_16 ) ;
}
static void F_11 ( struct V_17 * V_17 )
{
struct V_9 * V_12 = V_17 -> V_18 ;
struct V_19 * V_16 ;
F_12 ( ! V_12 ) ;
V_16 = V_12 -> V_2 -> V_16 ;
F_13 ( V_17 -> V_20 , V_17 -> V_21 ,
V_17 -> V_22 , V_17 -> V_23 ) ;
if ( V_12 -> V_13 ) {
if ( ! F_14 ( V_16 ) )
return;
V_16 -> V_24 . V_25 ++ ;
V_16 -> V_24 . V_26 += V_12 -> V_14 ;
F_15 ( V_16 , V_27 ) ;
F_16 ( V_16 , V_12 -> V_6 ) ;
}
if ( V_17 -> V_28 )
F_17 ( V_16 , L_1 , V_17 -> V_28 ) ;
F_8 ( V_12 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
struct V_29 * V_30 ,
struct V_9 * V_12 )
{
struct V_17 * V_17 ;
T_2 * V_31 ;
int V_32 ;
V_17 = F_19 ( 0 , V_33 ) ;
if ( ! V_17 )
return - V_34 ;
V_31 = F_20 ( V_2 -> V_35 , V_36 , V_33 ,
& V_17 -> V_23 ) ;
if ( ! V_31 ) {
V_32 = - V_34 ;
goto V_37;
}
memcpy ( V_31 , V_30 , V_36 ) ;
F_21 ( V_17 , V_2 -> V_35 ,
F_22 ( V_2 -> V_35 , V_38 ) , V_31 ,
V_36 , F_11 ,
V_12 ) ;
V_17 -> V_39 |= V_40 ;
F_23 ( V_17 , & V_2 -> V_41 ) ;
V_32 = F_24 ( V_17 , V_33 ) ;
if ( F_25 ( V_32 ) )
goto V_42;
F_26 ( V_17 ) ;
return 0 ;
V_42:
F_27 ( V_17 ) ;
F_13 ( V_2 -> V_35 , V_36 , V_31 ,
V_17 -> V_23 ) ;
if ( V_32 == - V_43 )
F_28 ( V_2 -> V_16 ) ;
else
F_29 ( V_2 -> V_16 , L_2 , V_32 ) ;
V_37:
F_26 ( V_17 ) ;
return V_32 ;
}
static T_1 F_30 ( struct V_44 * V_45 ,
struct V_19 * V_16 )
{
struct V_1 * V_2 = F_31 ( V_16 ) ;
struct V_10 * V_11 = (struct V_10 * ) V_45 -> V_46 ;
struct V_9 * V_12 = NULL ;
struct V_47 * V_24 = & V_2 -> V_16 -> V_24 ;
T_3 V_48 ;
int V_32 ;
struct V_49 V_30 = {
. V_50 = V_51
} ;
if ( F_32 ( V_16 , V_45 ) )
return V_52 ;
V_12 = F_4 ( V_2 , V_11 ) ;
if ( ! V_12 )
return V_53 ;
F_33 ( V_45 , V_2 -> V_16 , V_12 -> V_6 ) ;
if ( V_11 -> V_54 & V_55 ) {
V_48 = V_56 ;
V_48 |= ( V_11 -> V_54 & 0x1ffc0000 ) >> 13 ;
V_48 |= ( V_11 -> V_54 & 0x30000 ) >> 16 ;
F_34 ( V_48 , & V_30 . V_48 ) ;
F_34 ( V_11 -> V_54 & 0xffff , & V_30 . V_57 ) ;
} else {
F_34 ( ( V_11 -> V_54 & V_58 ) << 5 ,
& V_30 . V_48 ) ;
V_30 . V_57 = 0 ;
}
V_30 . V_14 = V_11 -> V_15 ;
memcpy ( V_30 . V_46 , V_11 -> V_46 , V_30 . V_14 ) ;
if ( V_11 -> V_54 & V_59 )
V_30 . V_14 |= V_60 ;
V_32 = F_18 ( V_2 , (struct V_29 * ) & V_30 , V_12 ) ;
if ( V_32 )
goto V_61;
return V_52 ;
V_61:
F_35 ( V_2 -> V_16 , V_12 -> V_6 ) ;
F_8 ( V_12 ) ;
F_36 ( V_45 ) ;
V_24 -> V_62 ++ ;
return V_52 ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_9 * V_12 = NULL ;
int V_32 ;
V_12 = F_4 ( V_2 , NULL ) ;
if ( ! V_12 ) {
F_38 ( V_2 -> V_16 ,
L_3 ,
V_30 -> V_50 ) ;
return;
}
V_32 = F_18 ( V_2 , V_30 , V_12 ) ;
if ( V_32 )
F_38 ( V_2 -> V_16 , L_4 ,
V_30 -> V_50 ) ;
}
static void F_39 ( struct V_1 * V_2 , T_3 V_63 )
{
struct V_64 V_30 = {
. V_50 = V_65
} ;
F_34 ( V_63 , & V_30 . V_63 ) ;
F_37 ( V_2 , (struct V_29 * ) & V_30 ) ;
}
static void F_40 ( struct V_1 * V_2 , T_2 V_66 )
{
struct V_67 V_30 = {
. V_50 = V_68 ,
. V_66 = V_66
} ;
F_37 ( V_2 , (struct V_29 * ) & V_30 ) ;
}
static void F_41 ( struct V_1 * V_2 ,
struct V_49 * V_69 )
{
struct V_10 * V_11 ;
struct V_44 * V_45 ;
struct V_47 * V_24 = & V_2 -> V_16 -> V_24 ;
T_3 V_48 ;
V_45 = F_42 ( V_2 -> V_16 , & V_11 ) ;
if ( ! V_45 )
return;
V_48 = F_43 ( & V_69 -> V_48 ) ;
if ( V_48 & V_56 ) {
V_11 -> V_54 = V_55 ;
V_11 -> V_54 |= ( V_48 & 0xffe0 ) << 13 ;
V_11 -> V_54 |= ( V_48 & 3 ) << 16 ;
V_11 -> V_54 |= F_43 ( & V_69 -> V_57 ) ;
} else {
V_11 -> V_54 = ( V_48 & 0xffe0 ) >> 5 ;
}
if ( V_69 -> V_14 & V_60 )
V_11 -> V_54 |= V_59 ;
V_11 -> V_15 = F_44 ( V_69 -> V_14 & V_70 ) ;
memcpy ( V_11 -> V_46 , V_69 -> V_46 , V_11 -> V_15 ) ;
V_24 -> V_71 ++ ;
V_24 -> V_72 += V_11 -> V_15 ;
F_15 ( V_2 -> V_16 , V_73 ) ;
F_45 ( V_45 ) ;
}
static void F_46 ( struct V_1 * V_2 ,
struct V_74 * V_69 )
{
if ( F_25 ( V_2 -> V_75 ) ) {
F_17 ( V_2 -> V_16 , L_5 ,
V_69 -> V_76 , V_69 -> V_77 ) ;
V_2 -> V_75 = false ;
}
if ( V_69 -> V_78 )
V_2 -> V_13 . V_79 = V_80 ;
else
V_2 -> V_13 . V_79 = V_81 ;
}
static T_4 F_47 ( struct V_82 * V_69 )
{
const T_4 V_63 = F_43 ( & V_69 -> V_83 ) ;
if ( ( V_63 == 33 ) || ( V_63 == 83 ) )
return V_63 * 1000 + 333 ;
else
return V_63 * 1000 ;
}
static void F_48 ( struct V_1 * V_2 ,
struct V_82 * V_69 )
{
if ( F_25 ( V_2 -> V_84 ) ) {
F_17 ( V_2 -> V_16 , L_6 ,
V_69 -> V_76 , V_69 -> V_77 ) ;
V_2 -> V_84 = false ;
}
if ( F_25 ( V_2 -> V_85 ) ) {
const T_4 V_63 = F_47 ( V_69 ) ;
V_2 -> V_85 = false ;
if ( V_63 != V_2 -> V_13 . V_86 . V_63 )
F_38 (
V_2 -> V_16 ,
L_7 ,
V_63 , V_2 -> V_13 . V_86 . V_63 ) ;
}
V_2 -> V_87 . V_88 = V_69 -> V_89 ;
V_2 -> V_87 . V_90 = V_69 -> V_91 ;
if ( V_69 -> V_92 )
V_2 -> V_13 . V_93 = V_94 ;
else if ( ( V_2 -> V_87 . V_88 > V_95 ) ||
( V_2 -> V_87 . V_90 > V_95 ) )
V_2 -> V_13 . V_93 = V_96 ;
else if ( ( V_2 -> V_87 . V_88 > V_97 ) ||
( V_2 -> V_87 . V_90 > V_97 ) )
V_2 -> V_13 . V_93 = V_98 ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_29 * V_69 )
{
switch ( V_69 -> V_50 ) {
case V_99 :
F_48 ( V_2 ,
(struct V_82 * ) V_69 ) ;
break;
case V_100 :
F_46 ( V_2 ,
(struct V_74 * ) V_69 ) ;
break;
case V_101 :
F_41 ( V_2 , (struct V_49 * ) V_69 ) ;
break;
case V_102 :
break;
case V_103 :
break;
default:
F_29 ( V_2 -> V_16 , L_8 ,
V_69 -> V_50 ) ;
break;
}
}
static void F_50 ( struct V_17 * V_17 )
{
struct V_1 * V_2 = V_17 -> V_18 ;
struct V_19 * V_16 ;
int V_104 ;
int V_105 = 0 ;
V_16 = V_2 -> V_16 ;
if ( ! F_14 ( V_16 ) )
return;
switch ( V_17 -> V_28 ) {
case 0 :
break;
case - V_106 :
case - V_107 :
return;
default:
F_17 ( V_16 , L_9 , V_17 -> V_28 ) ;
goto V_108;
}
while ( V_105 < V_17 -> V_109 ) {
struct V_29 * V_69 ;
if ( V_105 + sizeof( struct V_29 ) > V_17 -> V_109 ) {
F_38 ( V_2 -> V_16 , L_10 ) ;
break;
}
V_69 = (struct V_29 * ) ( V_17 -> V_22 + V_105 ) ;
F_49 ( V_2 , V_69 ) ;
V_105 += sizeof( struct V_29 ) ;
}
V_108:
F_21 ( V_17 , V_2 -> V_35 ,
F_51 ( V_2 -> V_35 , V_38 ) ,
V_17 -> V_22 , V_110 ,
F_50 , V_2 ) ;
V_104 = F_24 ( V_17 , V_33 ) ;
if ( V_104 == - V_43 )
F_28 ( V_16 ) ;
else if ( V_104 )
F_38 ( V_16 , L_11 ,
V_104 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_19 * V_16 = V_2 -> V_16 ;
int V_32 , V_3 ;
F_1 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_111 ; V_3 ++ ) {
struct V_17 * V_17 = NULL ;
T_2 * V_31 ;
V_17 = F_19 ( 0 , V_112 ) ;
if ( ! V_17 ) {
V_32 = - V_34 ;
break;
}
V_31 = F_20 ( V_2 -> V_35 , V_110 ,
V_112 , & V_17 -> V_23 ) ;
if ( ! V_31 ) {
F_38 ( V_16 , L_12 ) ;
F_26 ( V_17 ) ;
V_32 = - V_34 ;
break;
}
F_21 ( V_17 , V_2 -> V_35 ,
F_51 ( V_2 -> V_35 , V_113 ) ,
V_31 , V_110 ,
F_50 , V_2 ) ;
V_17 -> V_39 |= V_40 ;
F_23 ( V_17 , & V_2 -> V_114 ) ;
V_32 = F_24 ( V_17 , V_112 ) ;
if ( V_32 ) {
F_27 ( V_17 ) ;
F_13 ( V_2 -> V_35 , V_110 ,
V_31 , V_17 -> V_23 ) ;
F_26 ( V_17 ) ;
break;
}
F_26 ( V_17 ) ;
}
if ( V_3 == 0 ) {
F_29 ( V_16 , L_13 ) ;
return V_32 ;
}
if ( V_3 < V_111 )
F_29 ( V_16 , L_14 ) ;
F_40 ( V_2 , V_115 ) ;
F_40 ( V_2 , V_116 ) ;
return V_32 ;
}
static int F_53 ( struct V_19 * V_16 )
{
struct V_1 * V_2 = F_31 ( V_16 ) ;
int V_32 ;
V_32 = F_54 ( V_16 ) ;
if ( V_32 )
return V_32 ;
V_2 -> V_85 = true ;
V_2 -> V_13 . V_93 = V_117 ;
F_15 ( V_16 , V_118 ) ;
F_55 ( V_16 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 )
{
F_57 ( & V_2 -> V_114 ) ;
F_57 ( & V_2 -> V_41 ) ;
}
static int F_58 ( struct V_19 * V_16 )
{
struct V_1 * V_2 = F_31 ( V_16 ) ;
V_2 -> V_13 . V_93 = V_119 ;
F_7 ( V_16 ) ;
F_56 ( V_2 ) ;
F_59 ( V_16 ) ;
F_15 ( V_16 , V_120 ) ;
return 0 ;
}
static int F_60 ( struct V_19 * V_16 , enum V_121 V_122 )
{
return 0 ;
}
static int F_61 ( const struct V_19 * V_16 ,
struct V_123 * V_87 )
{
struct V_1 * V_2 = F_31 ( V_16 ) ;
V_87 -> V_88 = V_2 -> V_87 . V_88 ;
V_87 -> V_90 = V_2 -> V_87 . V_90 ;
return 0 ;
}
static int F_62 ( struct V_19 * V_16 )
{
struct V_1 * V_2 = F_31 ( V_16 ) ;
const T_3 V_124 = V_2 -> V_13 . V_86 . V_63 / 1000 ;
F_39 ( V_2 , V_124 ) ;
return 0 ;
}
static int F_63 ( struct V_19 * V_16 , T_3 V_125 )
{
struct V_1 * V_2 = F_31 ( V_16 ) ;
struct V_126 V_30 = {
. V_50 = V_127
} ;
if ( V_125 == V_80 )
V_30 . V_79 = 1 ;
else
V_30 . V_79 = 0 ;
F_37 ( V_2 , (struct V_29 * ) & V_30 ) ;
return 0 ;
}
static int F_64 ( struct V_128 * V_129 ,
const struct V_130 * V_131 )
{
struct V_19 * V_16 ;
struct V_1 * V_2 ;
int V_32 = - V_34 ;
struct V_132 * V_133 = F_65 ( V_129 ) ;
V_16 = F_66 ( sizeof( struct V_1 ) , V_4 ) ;
if ( ! V_16 ) {
F_67 ( & V_129 -> V_20 , L_15 ) ;
return - V_34 ;
}
V_2 = F_31 ( V_16 ) ;
V_2 -> V_35 = V_133 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_75 = true ;
V_2 -> V_84 = true ;
V_2 -> V_85 = false ;
F_68 ( & V_2 -> V_114 ) ;
F_68 ( & V_2 -> V_41 ) ;
F_69 ( V_129 , V_2 ) ;
V_2 -> V_13 . V_93 = V_119 ;
V_2 -> V_13 . V_134 = V_135 ;
V_2 -> V_13 . V_136 = F_3 ( V_135 ) ;
V_2 -> V_13 . V_137 = V_138 ;
V_2 -> V_13 . V_139 = F_3 ( V_138 ) ;
V_2 -> V_13 . V_140 = F_63 ;
V_2 -> V_13 . V_141 = F_60 ;
V_2 -> V_13 . V_142 = F_61 ;
V_2 -> V_13 . V_143 = F_62 ;
V_16 -> V_144 = & V_145 ;
V_16 -> V_146 |= V_147 ;
F_70 ( V_16 , & V_129 -> V_20 ) ;
V_32 = F_71 ( V_16 ) ;
if ( V_32 ) {
F_38 ( V_16 , L_16 , V_32 ) ;
goto V_148;
}
F_72 ( V_16 ) ;
V_32 = F_52 ( V_2 ) ;
if ( V_32 ) {
if ( V_32 == - V_43 )
F_28 ( V_2 -> V_16 ) ;
F_29 ( V_16 , L_17 , V_32 ) ;
goto V_149;
}
F_73 ( & V_129 -> V_20 , L_18 ) ;
return 0 ;
V_149:
F_74 ( V_2 -> V_16 ) ;
V_148:
F_75 ( V_16 ) ;
return V_32 ;
}
static void F_76 ( struct V_128 * V_129 )
{
struct V_1 * V_2 = F_77 ( V_129 ) ;
F_69 ( V_129 , NULL ) ;
F_17 ( V_2 -> V_16 , L_19 ) ;
F_74 ( V_2 -> V_16 ) ;
F_75 ( V_2 -> V_16 ) ;
F_56 ( V_2 ) ;
}
