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
F_11 ( V_18 -> V_16 , V_13 ) ;
F_12 ( & V_8 -> V_9 , & V_2 -> V_19 ) ;
V_2 -> V_25 |= V_8 -> V_25 ;
V_2 -> V_6 ++ ;
V_2 -> V_26 = V_8 -> V_26 ;
V_2 -> V_27 = V_8 -> V_28 ;
}
int F_13 ( struct V_29 * V_23 ,
int V_13 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 ;
struct V_12 * V_18 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_30 ;
F_14 (p, &chip->pcm_list) {
V_18 = F_3 ( V_4 , struct V_12 , V_9 ) ;
if ( V_18 -> V_26 != V_8 -> V_26 )
continue;
V_2 = & V_18 -> V_14 [ V_13 ] ;
if ( V_2 -> V_27 == V_8 -> V_28 ) {
F_12 ( & V_8 -> V_9 , & V_2 -> V_19 ) ;
V_2 -> V_6 ++ ;
V_2 -> V_25 |= V_8 -> V_25 ;
return 0 ;
}
}
F_14 (p, &chip->pcm_list) {
V_18 = F_3 ( V_4 , struct V_12 , V_9 ) ;
if ( V_18 -> V_26 != V_8 -> V_26 )
continue;
V_2 = & V_18 -> V_14 [ V_13 ] ;
if ( V_2 -> V_27 )
continue;
V_30 = F_15 ( V_18 -> V_16 , V_13 , 1 ) ;
if ( V_30 < 0 )
return V_30 ;
F_8 ( V_18 , V_13 , V_8 ) ;
return 0 ;
}
V_18 = F_16 ( sizeof( * V_18 ) , V_31 ) ;
if ( ! V_18 )
return - V_32 ;
V_18 -> V_33 = V_23 -> V_34 ;
V_18 -> V_23 = V_23 ;
V_18 -> V_26 = V_8 -> V_26 ;
V_30 = F_17 ( V_23 -> V_35 , L_1 , V_23 -> V_34 ,
V_13 == V_36 ? 1 : 0 ,
V_13 == V_36 ? 0 : 1 ,
& V_16 ) ;
if ( V_30 < 0 ) {
F_4 ( V_18 ) ;
return V_30 ;
}
V_18 -> V_16 = V_16 ;
V_16 -> V_17 = V_18 ;
V_16 -> V_37 = F_7 ;
V_16 -> V_38 = 0 ;
if ( V_23 -> V_34 > 0 )
sprintf ( V_16 -> V_39 , L_2 , V_23 -> V_34 ) ;
else
strcpy ( V_16 -> V_39 , L_1 ) ;
F_8 ( V_18 , V_13 , V_8 ) ;
F_18 ( & V_18 -> V_9 , & V_23 -> V_40 ) ;
V_23 -> V_34 ++ ;
F_19 ( V_18 ) ;
return 0 ;
}
static int F_20 ( struct V_29 * V_23 ,
struct V_41 * V_42 ,
int V_43 , int V_44 )
{
struct V_45 * V_46 ;
struct V_47 * V_48 = F_21 ( V_42 ) ;
int V_49 = 0 ;
V_46 = F_22 ( V_42 -> V_28 [ 0 ] . V_50 , V_42 -> V_28 [ 0 ] . V_51 , NULL , V_52 ) ;
if ( ! V_46 && V_48 -> V_53 >= 2 )
V_46 = F_22 ( V_42 -> V_28 [ 1 ] . V_50 , V_42 -> V_28 [ 1 ] . V_51 , NULL , V_52 ) ;
if ( ! V_46 || V_46 -> V_54 < 7 ||
V_46 -> V_55 != V_56 ) {
F_23 ( V_57 L_3
L_4 ,
V_23 -> V_22 -> V_58 , V_44 ,
V_48 -> V_59 ) ;
return 0 ;
}
if ( V_43 == V_60 ) {
V_49 = V_46 -> V_61 ;
} else {
struct V_62 * V_63 =
(struct V_62 * ) V_46 ;
V_49 = V_46 -> V_61 & V_64 ;
if ( V_63 -> V_65 & V_66 )
V_49 |= V_67 ;
}
return V_49 ;
}
static struct V_68 *
F_24 ( struct V_41 * V_69 ,
int V_70 )
{
struct V_68 * V_71 = NULL ;
while ( ( V_71 = F_25 ( V_69 -> V_50 ,
V_69 -> V_51 ,
V_71 , V_72 ) ) ) {
if ( V_71 -> V_73 == V_70 )
return V_71 ;
}
return NULL ;
}
static struct V_74 *
F_26 ( struct V_41 * V_69 ,
int V_70 )
{
struct V_74 * V_71 = NULL ;
while ( ( V_71 = F_25 ( V_69 -> V_50 ,
V_69 -> V_51 ,
V_71 , V_75 ) ) ) {
if ( V_71 -> V_73 == V_70 )
return V_71 ;
}
return NULL ;
}
int F_27 ( struct V_29 * V_23 , int V_44 )
{
struct V_76 * V_22 ;
struct V_77 * V_78 ;
struct V_41 * V_42 ;
struct V_47 * V_48 ;
int V_79 , V_80 , V_30 , V_13 ;
int V_81 = 0 , V_82 = 0 ;
struct V_7 * V_8 = NULL ;
int V_83 , V_43 , clock = 0 ;
struct V_84 * V_85 ;
V_22 = V_23 -> V_22 ;
V_78 = F_28 ( V_22 , V_44 ) ;
V_83 = V_78 -> V_86 ;
if ( V_23 -> V_87 == F_29 ( 0x04fa , 0x4201 ) )
V_83 = 4 ;
for ( V_79 = 0 ; V_79 < V_83 ; V_79 ++ ) {
V_42 = & V_78 -> V_88 [ V_79 ] ;
V_48 = F_21 ( V_42 ) ;
V_43 = V_48 -> V_89 ;
if ( ( V_48 -> V_90 != V_91 &&
V_48 -> V_90 != V_92 ) ||
( V_48 -> V_93 != V_94 &&
V_48 -> V_93 != V_95 ) ||
V_48 -> V_53 < 1 ||
F_30 ( F_31 ( V_42 , 0 ) -> V_96 ) == 0 )
continue;
if ( ( F_31 ( V_42 , 0 ) -> V_61 & V_97 ) !=
V_98 )
continue;
V_13 = ( F_31 ( V_42 , 0 ) -> V_99 & V_100 ) ?
V_101 : V_36 ;
V_80 = V_48 -> V_59 ;
if ( F_32 ( V_23 , V_44 , V_80 ) )
continue;
switch ( V_43 ) {
default:
F_33 ( V_57 L_5 ,
V_22 -> V_58 , V_44 , V_80 , V_43 ) ;
V_43 = V_60 ;
case V_60 : {
struct V_102 * V_18 =
F_25 ( V_42 -> V_50 , V_42 -> V_51 , NULL , V_103 ) ;
if ( ! V_18 ) {
F_23 ( V_104 L_6 ,
V_22 -> V_58 , V_44 , V_80 ) ;
continue;
}
if ( V_18 -> V_54 < sizeof( * V_18 ) ) {
F_23 ( V_104 L_7 ,
V_22 -> V_58 , V_44 , V_80 ) ;
continue;
}
V_81 = F_30 ( V_18 -> V_105 ) ;
break;
}
case V_106 : {
struct V_68 * V_107 ;
struct V_74 * V_108 ;
struct V_109 * V_18 =
F_25 ( V_42 -> V_50 , V_42 -> V_51 , NULL , V_103 ) ;
if ( ! V_18 ) {
F_23 ( V_104 L_6 ,
V_22 -> V_58 , V_44 , V_80 ) ;
continue;
}
if ( V_18 -> V_54 < sizeof( * V_18 ) ) {
F_23 ( V_104 L_7 ,
V_22 -> V_58 , V_44 , V_80 ) ;
continue;
}
V_82 = V_18 -> V_110 ;
V_81 = F_34 ( V_18 -> V_111 ) ;
V_107 = F_24 ( V_23 -> V_112 ,
V_18 -> V_113 ) ;
if ( V_107 ) {
clock = V_107 -> V_114 ;
break;
}
V_108 = F_26 ( V_23 -> V_112 ,
V_18 -> V_113 ) ;
if ( V_108 ) {
clock = V_108 -> V_114 ;
break;
}
F_23 ( V_104 L_8 ,
V_22 -> V_58 , V_44 , V_80 , V_18 -> V_113 ) ;
continue;
}
}
V_85 = F_25 ( V_42 -> V_50 , V_42 -> V_51 , NULL , V_115 ) ;
if ( ! V_85 ) {
F_23 ( V_104 L_9 ,
V_22 -> V_58 , V_44 , V_80 ) ;
continue;
}
if ( ( ( V_43 == V_60 ) && ( V_85 -> V_54 < 8 ) ) ||
( ( V_43 == V_106 ) && ( V_85 -> V_54 < 6 ) ) ) {
F_23 ( V_104 L_10 ,
V_22 -> V_58 , V_44 , V_80 ) ;
continue;
}
if ( V_85 -> V_110 == 1 &&
V_85 -> V_116 == 2 &&
V_80 == 2 && V_83 == 3 &&
V_8 && V_8 -> V_88 == 1 && V_8 -> V_117 == 1 &&
V_8 -> V_25 == V_118 &&
V_43 == V_60 &&
F_30 ( F_31 ( V_42 , 0 ) -> V_96 ) ==
V_8 -> V_119 * 2 )
continue;
V_8 = F_16 ( sizeof( * V_8 ) , V_31 ) ;
if ( ! V_8 ) {
F_23 ( V_104 L_11 ) ;
return - V_32 ;
}
V_8 -> V_78 = V_44 ;
V_8 -> V_88 = V_80 ;
V_8 -> V_120 = V_79 ;
V_8 -> V_28 = F_31 ( V_42 , 0 ) -> V_99 ;
V_8 -> V_121 = F_31 ( V_42 , 0 ) -> V_61 ;
V_8 -> V_122 = F_35 ( V_23 , V_42 ) ;
V_8 -> V_119 = F_30 ( F_31 ( V_42 , 0 ) -> V_96 ) ;
V_8 -> V_117 = V_82 ;
if ( F_36 ( V_22 ) == V_123 )
V_8 -> V_119 = ( ( ( V_8 -> V_119 >> 11 ) & 3 ) + 1 )
* ( V_8 -> V_119 & 0x7ff ) ;
V_8 -> V_49 = F_20 ( V_23 , V_42 , V_43 , V_44 ) ;
V_8 -> clock = clock ;
switch ( V_23 -> V_87 ) {
case F_29 ( 0x0a92 , 0x0053 ) :
V_8 -> V_49 &= ~ V_124 ;
break;
case F_29 ( 0x041e , 0x3020 ) :
case F_29 ( 0x0763 , 0x2003 ) :
V_8 -> V_49 |= V_124 ;
break;
case F_29 ( 0x0763 , 0x2001 ) :
case F_29 ( 0x0763 , 0x2012 ) :
case F_29 ( 0x047f , 0x0ca1 ) :
case F_29 ( 0x077d , 0x07af ) :
V_8 -> V_121 &= ~ V_125 ;
if ( V_13 == V_36 )
V_8 -> V_121 |= V_126 ;
else
V_8 -> V_121 |= V_127 ;
break;
}
if ( F_37 ( V_23 , V_8 , V_81 , V_85 , V_13 , V_42 ) < 0 ) {
F_4 ( V_8 -> V_10 ) ;
F_4 ( V_8 ) ;
V_8 = NULL ;
continue;
}
F_33 ( V_128 L_12 , V_22 -> V_58 , V_44 , V_80 , V_8 -> V_28 ) ;
V_30 = F_13 ( V_23 , V_13 , V_8 ) ;
if ( V_30 < 0 ) {
F_4 ( V_8 -> V_10 ) ;
F_4 ( V_8 ) ;
return V_30 ;
}
F_38 ( V_23 -> V_22 , V_44 , V_80 ) ;
F_39 ( V_23 , V_44 , V_42 , V_8 ) ;
F_40 ( V_23 , V_44 , V_42 , V_8 , V_8 -> V_129 ) ;
}
return 0 ;
}
