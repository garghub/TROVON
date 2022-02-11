static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
if ( ! V_2 -> V_6 )
return;
F_2 (p, n, &subs->fmt_list) {
struct V_7 * V_8 = F_3 ( V_4 , struct V_7 , V_9 ) ;
F_4 ( V_8 -> V_10 ) ;
F_4 ( V_8 ) ;
}
F_4 ( V_2 -> V_11 . V_9 ) ;
}
static void F_5 ( struct V_12 * V_13 )
{
F_1 ( & V_13 -> V_14 [ 0 ] ) ;
F_1 ( & V_13 -> V_14 [ 1 ] ) ;
F_6 ( & V_13 -> V_9 ) ;
F_4 ( V_13 ) ;
}
static void F_7 ( struct V_15 * V_16 )
{
struct V_12 * V_13 = V_16 -> V_17 ;
if ( V_13 ) {
V_13 -> V_16 = NULL ;
F_5 ( V_13 ) ;
}
}
static void F_8 ( struct V_12 * V_18 ,
int V_13 ,
struct V_7 * V_8 )
{
struct V_1 * V_2 = & V_18 -> V_14 [ V_13 ] ;
F_9 ( & V_2 -> V_19 ) ;
F_10 ( & V_2 -> V_20 ) ;
V_2 -> V_13 = V_18 ;
V_2 -> V_21 = V_13 ;
V_2 -> V_22 = V_18 -> V_23 -> V_22 ;
V_2 -> V_24 = V_18 -> V_23 -> V_24 ;
V_2 -> V_25 = F_11 ( V_2 -> V_22 ) ;
F_12 ( V_18 -> V_16 , V_13 ) ;
F_13 ( & V_8 -> V_9 , & V_2 -> V_19 ) ;
V_2 -> V_26 |= V_8 -> V_26 ;
V_2 -> V_6 ++ ;
V_2 -> V_27 = V_8 -> V_27 ;
V_2 -> V_28 = V_8 -> V_29 ;
}
int F_14 ( struct V_30 * V_23 ,
int V_13 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 ;
struct V_12 * V_18 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_31 ;
F_15 (p, &chip->pcm_list) {
V_18 = F_3 ( V_4 , struct V_12 , V_9 ) ;
if ( V_18 -> V_27 != V_8 -> V_27 )
continue;
V_2 = & V_18 -> V_14 [ V_13 ] ;
if ( V_2 -> V_28 == V_8 -> V_29 ) {
F_13 ( & V_8 -> V_9 , & V_2 -> V_19 ) ;
V_2 -> V_6 ++ ;
V_2 -> V_26 |= V_8 -> V_26 ;
return 0 ;
}
}
F_15 (p, &chip->pcm_list) {
V_18 = F_3 ( V_4 , struct V_12 , V_9 ) ;
if ( V_18 -> V_27 != V_8 -> V_27 )
continue;
V_2 = & V_18 -> V_14 [ V_13 ] ;
if ( V_2 -> V_28 )
continue;
V_31 = F_16 ( V_18 -> V_16 , V_13 , 1 ) ;
if ( V_31 < 0 )
return V_31 ;
F_8 ( V_18 , V_13 , V_8 ) ;
return 0 ;
}
V_18 = F_17 ( sizeof( * V_18 ) , V_32 ) ;
if ( ! V_18 )
return - V_33 ;
V_18 -> V_34 = V_23 -> V_35 ;
V_18 -> V_23 = V_23 ;
V_18 -> V_27 = V_8 -> V_27 ;
V_31 = F_18 ( V_23 -> V_36 , L_1 , V_23 -> V_35 ,
V_13 == V_37 ? 1 : 0 ,
V_13 == V_37 ? 0 : 1 ,
& V_16 ) ;
if ( V_31 < 0 ) {
F_4 ( V_18 ) ;
return V_31 ;
}
V_18 -> V_16 = V_16 ;
V_16 -> V_17 = V_18 ;
V_16 -> V_38 = F_7 ;
V_16 -> V_39 = 0 ;
if ( V_23 -> V_35 > 0 )
sprintf ( V_16 -> V_40 , L_2 , V_23 -> V_35 ) ;
else
strcpy ( V_16 -> V_40 , L_1 ) ;
F_8 ( V_18 , V_13 , V_8 ) ;
F_19 ( & V_18 -> V_9 , & V_23 -> V_41 ) ;
V_23 -> V_35 ++ ;
F_20 ( V_18 ) ;
return 0 ;
}
static int F_21 ( struct V_30 * V_23 ,
struct V_42 * V_43 ,
int V_44 , int V_45 )
{
struct V_46 * V_47 ;
struct V_48 * V_49 = F_22 ( V_43 ) ;
int V_50 = 0 ;
V_47 = F_23 ( V_43 -> V_29 [ 0 ] . V_51 , V_43 -> V_29 [ 0 ] . V_52 , NULL , V_53 ) ;
if ( ! V_47 && V_49 -> V_54 >= 2 )
V_47 = F_23 ( V_43 -> V_29 [ 1 ] . V_51 , V_43 -> V_29 [ 1 ] . V_52 , NULL , V_53 ) ;
if ( ! V_47 || V_47 -> V_55 < 7 ||
V_47 -> V_56 != V_57 ) {
F_24 ( V_58 L_3
L_4 ,
V_23 -> V_22 -> V_59 , V_45 ,
V_49 -> V_60 ) ;
return 0 ;
}
if ( V_44 == V_61 ) {
V_50 = V_47 -> V_62 ;
} else {
struct V_63 * V_64 =
(struct V_63 * ) V_47 ;
V_50 = V_47 -> V_62 & V_65 ;
if ( V_64 -> V_66 & V_67 )
V_50 |= V_68 ;
}
return V_50 ;
}
static struct V_69 *
F_25 ( struct V_42 * V_70 ,
int V_71 )
{
struct V_69 * V_72 = NULL ;
while ( ( V_72 = F_26 ( V_70 -> V_51 ,
V_70 -> V_52 ,
V_72 , V_73 ) ) ) {
if ( V_72 -> V_74 == V_71 )
return V_72 ;
}
return NULL ;
}
static struct V_75 *
F_27 ( struct V_42 * V_70 ,
int V_71 )
{
struct V_75 * V_72 = NULL ;
while ( ( V_72 = F_26 ( V_70 -> V_51 ,
V_70 -> V_52 ,
V_72 , V_76 ) ) ) {
if ( V_72 -> V_74 == V_71 )
return V_72 ;
}
return NULL ;
}
int F_28 ( struct V_30 * V_23 , int V_45 )
{
struct V_77 * V_22 ;
struct V_78 * V_79 ;
struct V_42 * V_43 ;
struct V_48 * V_49 ;
int V_80 , V_81 , V_31 , V_13 ;
int V_82 = 0 , V_83 = 0 ;
struct V_7 * V_8 = NULL ;
int V_84 , V_44 , clock = 0 ;
struct V_85 * V_86 ;
V_22 = V_23 -> V_22 ;
V_79 = F_29 ( V_22 , V_45 ) ;
V_84 = V_79 -> V_87 ;
if ( V_23 -> V_88 == F_30 ( 0x04fa , 0x4201 ) )
V_84 = 4 ;
for ( V_80 = 0 ; V_80 < V_84 ; V_80 ++ ) {
V_43 = & V_79 -> V_89 [ V_80 ] ;
V_49 = F_22 ( V_43 ) ;
V_44 = V_49 -> V_90 ;
if ( ( V_49 -> V_91 != V_92 &&
V_49 -> V_91 != V_93 ) ||
( V_49 -> V_94 != V_95 &&
V_49 -> V_94 != V_96 ) ||
V_49 -> V_54 < 1 ||
F_31 ( F_32 ( V_43 , 0 ) -> V_97 ) == 0 )
continue;
if ( ( F_32 ( V_43 , 0 ) -> V_62 & V_98 ) !=
V_99 )
continue;
V_13 = ( F_32 ( V_43 , 0 ) -> V_100 & V_101 ) ?
V_102 : V_37 ;
V_81 = V_49 -> V_60 ;
if ( F_33 ( V_23 , V_45 , V_81 ) )
continue;
switch ( V_44 ) {
default:
F_34 ( V_58 L_5 ,
V_22 -> V_59 , V_45 , V_81 , V_44 ) ;
V_44 = V_61 ;
case V_61 : {
struct V_103 * V_18 =
F_26 ( V_43 -> V_51 , V_43 -> V_52 , NULL , V_104 ) ;
if ( ! V_18 ) {
F_24 ( V_105 L_6 ,
V_22 -> V_59 , V_45 , V_81 ) ;
continue;
}
if ( V_18 -> V_55 < sizeof( * V_18 ) ) {
F_24 ( V_105 L_7 ,
V_22 -> V_59 , V_45 , V_81 ) ;
continue;
}
V_82 = F_31 ( V_18 -> V_106 ) ;
break;
}
case V_107 : {
struct V_69 * V_108 ;
struct V_75 * V_109 ;
struct V_110 * V_18 =
F_26 ( V_43 -> V_51 , V_43 -> V_52 , NULL , V_104 ) ;
if ( ! V_18 ) {
F_24 ( V_105 L_6 ,
V_22 -> V_59 , V_45 , V_81 ) ;
continue;
}
if ( V_18 -> V_55 < sizeof( * V_18 ) ) {
F_24 ( V_105 L_7 ,
V_22 -> V_59 , V_45 , V_81 ) ;
continue;
}
V_83 = V_18 -> V_111 ;
V_82 = F_35 ( V_18 -> V_112 ) ;
V_108 = F_25 ( V_23 -> V_113 ,
V_18 -> V_114 ) ;
if ( V_108 ) {
clock = V_108 -> V_115 ;
break;
}
V_109 = F_27 ( V_23 -> V_113 ,
V_18 -> V_114 ) ;
if ( V_109 ) {
clock = V_109 -> V_115 ;
break;
}
F_24 ( V_105 L_8 ,
V_22 -> V_59 , V_45 , V_81 , V_18 -> V_114 ) ;
continue;
}
}
V_86 = F_26 ( V_43 -> V_51 , V_43 -> V_52 , NULL , V_116 ) ;
if ( ! V_86 ) {
F_24 ( V_105 L_9 ,
V_22 -> V_59 , V_45 , V_81 ) ;
continue;
}
if ( ( ( V_44 == V_61 ) && ( V_86 -> V_55 < 8 ) ) ||
( ( V_44 == V_107 ) && ( V_86 -> V_55 < 6 ) ) ) {
F_24 ( V_105 L_10 ,
V_22 -> V_59 , V_45 , V_81 ) ;
continue;
}
if ( V_86 -> V_111 == 1 &&
V_86 -> V_117 == 2 &&
V_81 == 2 && V_84 == 3 &&
V_8 && V_8 -> V_89 == 1 && V_8 -> V_118 == 1 &&
V_8 -> V_26 == V_119 &&
V_44 == V_61 &&
F_31 ( F_32 ( V_43 , 0 ) -> V_97 ) ==
V_8 -> V_120 * 2 )
continue;
V_8 = F_17 ( sizeof( * V_8 ) , V_32 ) ;
if ( ! V_8 ) {
F_24 ( V_105 L_11 ) ;
return - V_33 ;
}
V_8 -> V_79 = V_45 ;
V_8 -> V_89 = V_81 ;
V_8 -> V_121 = V_80 ;
V_8 -> V_29 = F_32 ( V_43 , 0 ) -> V_100 ;
V_8 -> V_122 = F_32 ( V_43 , 0 ) -> V_62 ;
V_8 -> V_123 = F_36 ( V_23 , V_43 ) ;
V_8 -> V_120 = F_31 ( F_32 ( V_43 , 0 ) -> V_97 ) ;
V_8 -> V_118 = V_83 ;
if ( F_11 ( V_22 ) == V_124 )
V_8 -> V_120 = ( ( ( V_8 -> V_120 >> 11 ) & 3 ) + 1 )
* ( V_8 -> V_120 & 0x7ff ) ;
V_8 -> V_50 = F_21 ( V_23 , V_43 , V_44 , V_45 ) ;
V_8 -> clock = clock ;
switch ( V_23 -> V_88 ) {
case F_30 ( 0x0a92 , 0x0053 ) :
V_8 -> V_50 &= ~ V_125 ;
break;
case F_30 ( 0x041e , 0x3020 ) :
case F_30 ( 0x0763 , 0x2003 ) :
V_8 -> V_50 |= V_125 ;
break;
case F_30 ( 0x0763 , 0x2001 ) :
case F_30 ( 0x0763 , 0x2012 ) :
case F_30 ( 0x047f , 0x0ca1 ) :
case F_30 ( 0x077d , 0x07af ) :
V_8 -> V_122 &= ~ V_126 ;
if ( V_13 == V_37 )
V_8 -> V_122 |= V_127 ;
else
V_8 -> V_122 |= V_128 ;
break;
}
if ( F_37 ( V_23 , V_8 , V_82 , V_86 , V_13 , V_43 ) < 0 ) {
F_4 ( V_8 -> V_10 ) ;
F_4 ( V_8 ) ;
V_8 = NULL ;
continue;
}
F_34 ( V_129 L_12 , V_22 -> V_59 , V_45 , V_81 , V_8 -> V_29 ) ;
V_31 = F_14 ( V_23 , V_13 , V_8 ) ;
if ( V_31 < 0 ) {
F_4 ( V_8 -> V_10 ) ;
F_4 ( V_8 ) ;
return V_31 ;
}
F_38 ( V_23 -> V_22 , V_45 , V_81 ) ;
F_39 ( V_23 , V_45 , V_43 , V_8 ) ;
F_40 ( V_23 , V_45 , V_43 , V_8 , V_8 -> V_130 ) ;
}
return 0 ;
}
