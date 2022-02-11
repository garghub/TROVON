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
int F_8 ( struct V_18 * V_19 ,
int V_13 ,
struct V_7 * V_8 )
{
struct V_3 * V_4 ;
struct V_12 * V_20 ;
struct V_1 * V_2 ;
struct V_15 * V_16 ;
int V_21 ;
F_9 (p, &chip->pcm_list) {
V_20 = F_3 ( V_4 , struct V_12 , V_9 ) ;
if ( V_20 -> V_22 != V_8 -> V_22 )
continue;
V_2 = & V_20 -> V_14 [ V_13 ] ;
if ( ! V_2 -> V_23 )
continue;
if ( V_2 -> V_23 == V_8 -> V_23 ) {
F_10 ( & V_8 -> V_9 , & V_2 -> V_24 ) ;
V_2 -> V_6 ++ ;
V_2 -> V_25 |= V_8 -> V_25 ;
return 0 ;
}
}
F_9 (p, &chip->pcm_list) {
V_20 = F_3 ( V_4 , struct V_12 , V_9 ) ;
if ( V_20 -> V_22 != V_8 -> V_22 )
continue;
V_2 = & V_20 -> V_14 [ V_13 ] ;
if ( V_2 -> V_23 )
continue;
V_21 = F_11 ( V_20 -> V_16 , V_13 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
F_12 ( V_20 , V_13 , V_8 ) ;
return 0 ;
}
V_20 = F_13 ( sizeof( * V_20 ) , V_26 ) ;
if ( ! V_20 )
return - V_27 ;
V_20 -> V_28 = V_19 -> V_29 ;
V_20 -> V_19 = V_19 ;
V_20 -> V_22 = V_8 -> V_22 ;
V_21 = F_14 ( V_19 -> V_30 , L_1 , V_19 -> V_29 ,
V_13 == V_31 ? 1 : 0 ,
V_13 == V_31 ? 0 : 1 ,
& V_16 ) ;
if ( V_21 < 0 ) {
F_4 ( V_20 ) ;
return V_21 ;
}
V_20 -> V_16 = V_16 ;
V_16 -> V_17 = V_20 ;
V_16 -> V_32 = F_7 ;
V_16 -> V_33 = 0 ;
if ( V_19 -> V_29 > 0 )
sprintf ( V_16 -> V_34 , L_2 , V_19 -> V_29 ) ;
else
strcpy ( V_16 -> V_34 , L_1 ) ;
F_12 ( V_20 , V_13 , V_8 ) ;
F_15 ( & V_20 -> V_9 , & V_19 -> V_35 ) ;
V_19 -> V_29 ++ ;
F_16 ( V_20 ) ;
return 0 ;
}
static int F_17 ( struct V_18 * V_19 ,
struct V_36 * V_37 ,
int V_38 , int V_39 )
{
struct V_40 * V_41 ;
struct V_42 * V_43 = F_18 ( V_37 ) ;
int V_44 = 0 ;
V_41 = F_19 ( V_37 -> V_23 [ 0 ] . V_45 , V_37 -> V_23 [ 0 ] . V_46 , NULL , V_47 ) ;
if ( ! V_41 && V_43 -> V_48 >= 2 )
V_41 = F_19 ( V_37 -> V_23 [ 1 ] . V_45 , V_37 -> V_23 [ 1 ] . V_46 , NULL , V_47 ) ;
if ( ! V_41 || V_41 -> V_49 < 7 ||
V_41 -> V_50 != V_51 ) {
F_20 ( V_52 L_3
L_4 ,
V_19 -> V_53 -> V_54 , V_39 ,
V_43 -> V_55 ) ;
return 0 ;
}
if ( V_38 == V_56 ) {
V_44 = V_41 -> V_57 ;
} else {
struct V_58 * V_59 =
(struct V_58 * ) V_41 ;
V_44 = V_41 -> V_57 & V_60 ;
if ( V_59 -> V_61 & V_62 )
V_44 |= V_63 ;
}
return V_44 ;
}
static struct V_64 *
F_21 ( struct V_36 * V_65 ,
int V_66 )
{
struct V_64 * V_67 = NULL ;
while ( ( V_67 = F_22 ( V_65 -> V_45 ,
V_65 -> V_46 ,
V_67 , V_68 ) ) ) {
if ( V_67 -> V_69 == V_66 )
return V_67 ;
}
return NULL ;
}
static struct V_70 *
F_23 ( struct V_36 * V_65 ,
int V_66 )
{
struct V_70 * V_67 = NULL ;
while ( ( V_67 = F_22 ( V_65 -> V_45 ,
V_65 -> V_46 ,
V_67 , V_71 ) ) ) {
if ( V_67 -> V_69 == V_66 )
return V_67 ;
}
return NULL ;
}
int F_24 ( struct V_18 * V_19 , int V_39 )
{
struct V_72 * V_53 ;
struct V_73 * V_74 ;
struct V_36 * V_37 ;
struct V_42 * V_43 ;
int V_75 , V_76 , V_21 , V_13 ;
int V_77 = 0 , V_78 = 0 ;
struct V_7 * V_8 = NULL ;
int V_79 , V_38 , clock = 0 ;
struct V_80 * V_81 ;
V_53 = V_19 -> V_53 ;
V_74 = F_25 ( V_53 , V_39 ) ;
V_79 = V_74 -> V_82 ;
if ( V_19 -> V_83 == F_26 ( 0x04fa , 0x4201 ) )
V_79 = 4 ;
for ( V_75 = 0 ; V_75 < V_79 ; V_75 ++ ) {
V_37 = & V_74 -> V_84 [ V_75 ] ;
V_43 = F_18 ( V_37 ) ;
V_38 = V_43 -> V_85 ;
if ( ( V_43 -> V_86 != V_87 &&
V_43 -> V_86 != V_88 ) ||
( V_43 -> V_89 != V_90 &&
V_43 -> V_89 != V_91 ) ||
V_43 -> V_48 < 1 ||
F_27 ( F_28 ( V_37 , 0 ) -> V_92 ) == 0 )
continue;
if ( ( F_28 ( V_37 , 0 ) -> V_57 & V_93 ) !=
V_94 )
continue;
V_13 = ( F_28 ( V_37 , 0 ) -> V_95 & V_96 ) ?
V_97 : V_31 ;
V_76 = V_43 -> V_55 ;
if ( F_29 ( V_19 , V_39 , V_76 ) )
continue;
switch ( V_38 ) {
default:
F_30 ( V_52 L_5 ,
V_53 -> V_54 , V_39 , V_76 , V_38 ) ;
V_38 = V_56 ;
case V_56 : {
struct V_98 * V_20 =
F_22 ( V_37 -> V_45 , V_37 -> V_46 , NULL , V_99 ) ;
if ( ! V_20 ) {
F_20 ( V_100 L_6 ,
V_53 -> V_54 , V_39 , V_76 ) ;
continue;
}
if ( V_20 -> V_49 < sizeof( * V_20 ) ) {
F_20 ( V_100 L_7 ,
V_53 -> V_54 , V_39 , V_76 ) ;
continue;
}
V_77 = F_27 ( V_20 -> V_101 ) ;
break;
}
case V_102 : {
struct V_64 * V_103 ;
struct V_70 * V_104 ;
struct V_105 * V_20 =
F_22 ( V_37 -> V_45 , V_37 -> V_46 , NULL , V_99 ) ;
if ( ! V_20 ) {
F_20 ( V_100 L_6 ,
V_53 -> V_54 , V_39 , V_76 ) ;
continue;
}
if ( V_20 -> V_49 < sizeof( * V_20 ) ) {
F_20 ( V_100 L_7 ,
V_53 -> V_54 , V_39 , V_76 ) ;
continue;
}
V_78 = V_20 -> V_106 ;
V_77 = F_31 ( V_20 -> V_107 ) ;
V_103 = F_21 ( V_19 -> V_108 ,
V_20 -> V_109 ) ;
if ( V_103 ) {
clock = V_103 -> V_110 ;
break;
}
V_104 = F_23 ( V_19 -> V_108 ,
V_20 -> V_109 ) ;
if ( V_104 ) {
clock = V_104 -> V_110 ;
break;
}
F_20 ( V_100 L_8 ,
V_53 -> V_54 , V_39 , V_76 , V_20 -> V_109 ) ;
continue;
}
}
V_81 = F_22 ( V_37 -> V_45 , V_37 -> V_46 , NULL , V_111 ) ;
if ( ! V_81 ) {
F_20 ( V_100 L_9 ,
V_53 -> V_54 , V_39 , V_76 ) ;
continue;
}
if ( ( ( V_38 == V_56 ) && ( V_81 -> V_49 < 8 ) ) ||
( ( V_38 == V_102 ) && ( V_81 -> V_49 < 6 ) ) ) {
F_20 ( V_100 L_10 ,
V_53 -> V_54 , V_39 , V_76 ) ;
continue;
}
if ( V_81 -> V_106 == 1 &&
V_81 -> V_112 == 2 &&
V_76 == 2 && V_79 == 3 &&
V_8 && V_8 -> V_84 == 1 && V_8 -> V_113 == 1 &&
V_8 -> V_25 == V_114 &&
V_38 == V_56 &&
F_27 ( F_28 ( V_37 , 0 ) -> V_92 ) ==
V_8 -> V_115 * 2 )
continue;
V_8 = F_13 ( sizeof( * V_8 ) , V_26 ) ;
if ( ! V_8 ) {
F_20 ( V_100 L_11 ) ;
return - V_27 ;
}
V_8 -> V_74 = V_39 ;
V_8 -> V_84 = V_76 ;
V_8 -> V_116 = V_75 ;
V_8 -> V_23 = F_28 ( V_37 , 0 ) -> V_95 ;
V_8 -> V_117 = F_28 ( V_37 , 0 ) -> V_57 ;
V_8 -> V_118 = F_32 ( V_19 , V_37 ) ;
V_8 -> V_115 = F_27 ( F_28 ( V_37 , 0 ) -> V_92 ) ;
V_8 -> V_113 = V_78 ;
if ( F_33 ( V_53 ) == V_119 )
V_8 -> V_115 = ( ( ( V_8 -> V_115 >> 11 ) & 3 ) + 1 )
* ( V_8 -> V_115 & 0x7ff ) ;
V_8 -> V_44 = F_17 ( V_19 , V_37 , V_38 , V_39 ) ;
V_8 -> clock = clock ;
switch ( V_19 -> V_83 ) {
case F_26 ( 0x0a92 , 0x0053 ) :
V_8 -> V_44 &= ~ V_120 ;
break;
case F_26 ( 0x041e , 0x3020 ) :
case F_26 ( 0x0763 , 0x2003 ) :
V_8 -> V_44 |= V_120 ;
break;
case F_26 ( 0x0763 , 0x2001 ) :
case F_26 ( 0x0763 , 0x2012 ) :
case F_26 ( 0x047f , 0x0ca1 ) :
case F_26 ( 0x077d , 0x07af ) :
V_8 -> V_117 &= ~ V_121 ;
if ( V_13 == V_31 )
V_8 -> V_117 |= V_122 ;
else
V_8 -> V_117 |= V_123 ;
break;
}
if ( F_34 ( V_19 , V_8 , V_77 , V_81 , V_13 , V_37 ) < 0 ) {
F_4 ( V_8 -> V_10 ) ;
F_4 ( V_8 ) ;
V_8 = NULL ;
continue;
}
F_30 ( V_124 L_12 , V_53 -> V_54 , V_39 , V_76 , V_8 -> V_23 ) ;
V_21 = F_8 ( V_19 , V_13 , V_8 ) ;
if ( V_21 < 0 ) {
F_4 ( V_8 -> V_10 ) ;
F_4 ( V_8 ) ;
return V_21 ;
}
F_35 ( V_19 -> V_53 , V_39 , V_76 ) ;
F_36 ( V_19 , V_39 , V_37 , V_8 ) ;
F_37 ( V_19 , V_39 , V_37 , V_8 , V_8 -> V_125 ) ;
}
return 0 ;
}
