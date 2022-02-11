static struct V_1 * F_1 ( struct V_2 * V_3 ,
union V_4 * V_5 )
{
struct V_6 * V_7 = V_3 -> V_8 . V_6 ;
struct V_1 * V_9 ;
int V_10 ;
while ( V_7 ) {
V_9 = F_2 ( V_7 , struct V_1 , V_7 ) ;
V_10 = memcmp ( V_5 -> V_11 , V_9 -> V_12 . V_5 . V_11 , sizeof *V_5 ) ;
if ( ! V_10 )
return V_9 ;
if ( V_10 < 0 )
V_7 = V_7 -> V_13 ;
else
V_7 = V_7 -> V_14 ;
}
return NULL ;
}
static struct V_1 * F_3 ( struct V_2 * V_3 ,
struct V_1 * V_9 ,
int V_15 )
{
struct V_6 * * V_16 = & V_3 -> V_8 . V_6 ;
struct V_6 * V_17 = NULL ;
struct V_1 * V_18 ;
int V_10 ;
while ( * V_16 ) {
V_17 = * V_16 ;
V_18 = F_2 ( V_17 , struct V_1 , V_7 ) ;
V_10 = memcmp ( V_9 -> V_12 . V_5 . V_11 , V_18 -> V_12 . V_5 . V_11 ,
sizeof V_9 -> V_12 . V_5 ) ;
if ( V_10 < 0 )
V_16 = & ( * V_16 ) -> V_13 ;
else if ( V_10 > 0 )
V_16 = & ( * V_16 ) -> V_14 ;
else if ( V_15 )
V_16 = & ( * V_16 ) -> V_13 ;
else
return V_18 ;
}
F_4 ( & V_9 -> V_7 , V_17 , V_16 ) ;
F_5 ( & V_9 -> V_7 , & V_3 -> V_8 ) ;
return NULL ;
}
static void F_6 ( struct V_2 * V_3 )
{
if ( F_7 ( & V_3 -> V_19 ) )
F_8 ( & V_3 -> V_20 ) ;
}
static void F_9 ( struct V_1 * V_9 )
{
struct V_2 * V_3 = V_9 -> V_3 ;
unsigned long V_21 ;
F_10 ( & V_3 -> V_22 , V_21 ) ;
if ( F_7 ( & V_9 -> V_19 ) ) {
F_11 ( & V_9 -> V_7 , & V_3 -> V_8 ) ;
F_12 ( & V_3 -> V_22 , V_21 ) ;
F_13 ( V_9 ) ;
F_6 ( V_3 ) ;
} else
F_12 ( & V_3 -> V_22 , V_21 ) ;
}
static void F_14 ( struct V_23 * V_24 )
{
if ( F_7 ( & V_24 -> V_19 ) )
F_8 ( & V_24 -> V_20 ) ;
}
static void F_15 ( struct V_23 * V_24 )
{
struct V_1 * V_9 = V_24 -> V_9 ;
unsigned long V_21 ;
F_10 ( & V_9 -> V_22 , V_21 ) ;
F_16 ( & V_24 -> V_25 , & V_9 -> V_26 ) ;
if ( V_9 -> V_27 == V_28 ) {
V_9 -> V_27 = V_29 ;
F_17 ( & V_9 -> V_19 ) ;
F_18 ( V_30 , & V_9 -> V_31 ) ;
}
F_12 ( & V_9 -> V_22 , V_21 ) ;
}
static void F_19 ( struct V_1 * V_9 , T_1 V_32 , int V_33 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < 3 ; V_34 ++ , V_32 >>= 1 )
if ( V_32 & 0x1 )
V_9 -> V_35 [ V_34 ] += V_33 ;
}
static T_1 F_20 ( struct V_1 * V_9 )
{
T_1 V_36 = 0 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < 3 ; V_34 ++ )
if ( ! V_9 -> V_35 [ V_34 ] )
V_36 |= ( 0x1 << V_34 ) ;
return V_36 & V_9 -> V_12 . V_32 ;
}
static int F_21 ( T_2 V_37 ,
T_2 V_38 ,
T_2 V_39 ,
T_1 V_40 , T_1 V_41 , T_1 V_42 )
{
int V_43 ;
if ( ! ( V_37 & V_38 ) || ! ( V_37 & V_39 ) )
return 0 ;
switch ( V_40 ) {
case V_44 :
V_43 = ( V_41 <= V_42 ) ;
break;
case V_45 :
V_43 = ( V_41 >= V_42 ) ;
break;
case V_46 :
V_43 = ( V_41 != V_42 ) ;
break;
default:
V_43 = 0 ;
break;
}
return V_43 ;
}
static int F_22 ( struct V_47 * V_48 ,
struct V_47 * V_49 , T_2 V_37 )
{
if ( V_37 & V_50 &&
memcmp ( & V_48 -> V_51 , & V_49 -> V_51 , sizeof V_48 -> V_51 ) )
return - V_52 ;
if ( V_37 & V_53 && V_48 -> V_54 != V_49 -> V_54 )
return - V_52 ;
if ( V_37 & V_55 && V_48 -> V_56 != V_49 -> V_56 )
return - V_52 ;
if ( F_21 ( V_37 , V_57 ,
V_58 , V_49 -> V_59 ,
V_48 -> V_60 , V_49 -> V_60 ) )
return - V_52 ;
if ( V_37 & V_61 &&
V_48 -> V_62 != V_49 -> V_62 )
return - V_52 ;
if ( V_37 & V_63 && V_48 -> V_64 != V_49 -> V_64 )
return - V_52 ;
if ( F_21 ( V_37 , V_65 ,
V_66 , V_49 -> V_67 ,
V_48 -> V_68 , V_49 -> V_68 ) )
return - V_52 ;
if ( F_21 ( V_37 ,
V_69 ,
V_70 ,
V_49 -> V_71 ,
V_48 -> V_72 , V_49 -> V_72 ) )
return - V_52 ;
if ( V_37 & V_73 && V_48 -> V_74 != V_49 -> V_74 )
return - V_52 ;
if ( V_37 & V_75 &&
V_48 -> V_76 != V_49 -> V_76 )
return - V_52 ;
if ( V_37 & V_77 &&
V_48 -> V_78 != V_49 -> V_78 )
return - V_52 ;
if ( V_37 & V_79 && V_48 -> V_80 != V_49 -> V_80 )
return - V_52 ;
return 0 ;
}
static int F_23 ( struct V_1 * V_9 , struct V_23 * V_24 )
{
struct V_2 * V_3 = V_9 -> V_3 ;
int V_10 ;
V_9 -> V_81 = V_24 ;
V_10 = F_24 ( & V_82 , V_3 -> V_83 -> V_84 ,
V_3 -> V_85 , V_86 ,
& V_24 -> V_87 . V_12 ,
V_24 -> V_87 . V_37 ,
3000 , V_88 , V_89 , V_9 ,
& V_9 -> V_90 ) ;
if ( V_10 >= 0 ) {
V_9 -> V_91 = V_10 ;
V_10 = 0 ;
}
return V_10 ;
}
static int F_25 ( struct V_1 * V_9 , T_1 V_36 )
{
struct V_2 * V_3 = V_9 -> V_3 ;
struct V_47 V_12 ;
int V_10 ;
V_12 = V_9 -> V_12 ;
V_12 . V_32 = V_36 ;
V_9 -> V_36 = V_36 ;
V_10 = F_24 ( & V_82 , V_3 -> V_83 -> V_84 ,
V_3 -> V_85 , V_92 , & V_12 ,
V_93 |
V_50 |
V_94 ,
3000 , V_88 , V_95 ,
V_9 , & V_9 -> V_90 ) ;
if ( V_10 >= 0 ) {
V_9 -> V_91 = V_10 ;
V_10 = 0 ;
}
return V_10 ;
}
static void F_26 ( struct V_1 * V_9 , struct V_23 * V_24 ,
T_1 V_32 )
{
V_24 -> V_27 = V_96 ;
F_19 ( V_9 , V_32 , 1 ) ;
V_9 -> V_12 . V_32 |= V_32 ;
V_24 -> V_87 . V_12 = V_9 -> V_12 ;
V_24 -> V_87 . V_12 . V_32 = V_32 ;
F_27 ( & V_24 -> V_25 , & V_9 -> V_97 ) ;
}
static int F_28 ( struct V_1 * V_9 , struct V_23 * V_24 ,
int V_98 )
{
F_29 ( & V_9 -> V_22 ) ;
F_30 ( & V_24 -> V_25 ) ;
F_31 ( & V_9 -> V_22 ) ;
return V_24 -> V_87 . V_99 ( V_98 , & V_24 -> V_87 ) ;
}
static void F_32 ( struct V_1 * V_9 )
{
struct V_23 * V_24 ;
int V_10 = 0 ;
T_3 V_100 ;
if ( V_9 -> V_27 == V_101 )
V_10 = F_33 ( V_9 -> V_3 -> V_83 -> V_84 ,
V_9 -> V_3 -> V_85 ,
F_34 ( V_9 -> V_12 . V_64 ) , & V_100 ) ;
F_29 ( & V_9 -> V_22 ) ;
if ( V_9 -> V_27 == V_101 && ! V_10 &&
V_9 -> V_100 == V_100 )
goto V_102;
while ( ! F_35 ( & V_9 -> V_97 ) ) {
V_24 = F_36 ( V_9 -> V_97 . V_103 ,
struct V_23 , V_25 ) ;
F_17 ( & V_24 -> V_19 ) ;
F_30 ( & V_24 -> V_25 ) ;
F_19 ( V_9 , V_24 -> V_87 . V_12 . V_32 , - 1 ) ;
V_24 -> V_27 = V_104 ;
F_31 ( & V_9 -> V_22 ) ;
V_10 = V_24 -> V_87 . V_99 ( - V_105 ,
& V_24 -> V_87 ) ;
F_14 ( V_24 ) ;
if ( V_10 )
F_37 ( & V_24 -> V_87 ) ;
F_29 ( & V_9 -> V_22 ) ;
}
V_9 -> V_12 . V_32 = 0 ;
V_102:
V_9 -> V_27 = V_29 ;
F_31 ( & V_9 -> V_22 ) ;
}
static void F_38 ( struct V_106 * V_31 )
{
struct V_1 * V_9 ;
struct V_23 * V_24 ;
struct V_107 * V_87 ;
int V_98 , V_10 ;
T_1 V_32 ;
V_9 = F_39 ( V_31 , F_40 ( * V_9 ) , V_31 ) ;
V_108:
F_29 ( & V_9 -> V_22 ) ;
while ( ! F_35 ( & V_9 -> V_26 ) ||
( V_9 -> V_27 != V_29 ) ) {
if ( V_9 -> V_27 != V_29 ) {
F_31 ( & V_9 -> V_22 ) ;
F_32 ( V_9 ) ;
goto V_108;
}
V_24 = F_36 ( V_9 -> V_26 . V_103 ,
struct V_23 , V_25 ) ;
V_87 = & V_24 -> V_87 ;
V_32 = V_87 -> V_12 . V_32 ;
F_17 ( & V_24 -> V_19 ) ;
if ( V_32 == ( V_9 -> V_12 . V_32 & V_32 ) ) {
V_98 = F_22 ( & V_9 -> V_12 , & V_87 -> V_12 ,
V_87 -> V_37 ) ;
if ( ! V_98 )
F_26 ( V_9 , V_24 , V_32 ) ;
else
F_30 ( & V_24 -> V_25 ) ;
F_31 ( & V_9 -> V_22 ) ;
V_10 = V_87 -> V_99 ( V_98 , V_87 ) ;
} else {
F_31 ( & V_9 -> V_22 ) ;
V_98 = F_23 ( V_9 , V_24 ) ;
if ( ! V_98 ) {
F_14 ( V_24 ) ;
return;
}
V_10 = F_28 ( V_9 , V_24 , V_98 ) ;
}
F_14 ( V_24 ) ;
if ( V_10 )
F_37 ( & V_24 -> V_87 ) ;
F_29 ( & V_9 -> V_22 ) ;
}
V_32 = F_20 ( V_9 ) ;
if ( V_32 ) {
V_9 -> V_12 . V_32 &= ~ V_32 ;
F_31 ( & V_9 -> V_22 ) ;
if ( F_25 ( V_9 , V_32 ) )
goto V_108;
} else {
V_9 -> V_27 = V_28 ;
F_31 ( & V_9 -> V_22 ) ;
F_9 ( V_9 ) ;
}
}
static void F_41 ( struct V_1 * V_9 , int V_98 )
{
struct V_23 * V_24 ;
int V_10 ;
F_29 ( & V_9 -> V_22 ) ;
V_24 = F_36 ( V_9 -> V_26 . V_103 ,
struct V_23 , V_25 ) ;
if ( V_9 -> V_81 == V_24 ) {
F_17 ( & V_24 -> V_19 ) ;
F_30 ( & V_24 -> V_25 ) ;
F_31 ( & V_9 -> V_22 ) ;
V_10 = V_24 -> V_87 . V_99 ( V_98 , & V_24 -> V_87 ) ;
F_14 ( V_24 ) ;
if ( V_10 )
F_37 ( & V_24 -> V_87 ) ;
} else
F_31 ( & V_9 -> V_22 ) ;
}
static void V_89 ( int V_98 , struct V_47 * V_12 ,
void * V_109 )
{
struct V_1 * V_9 = V_109 ;
T_3 V_100 = V_110 ;
if ( V_98 )
F_41 ( V_9 , V_98 ) ;
else {
F_33 ( V_9 -> V_3 -> V_83 -> V_84 , V_9 -> V_3 -> V_85 ,
F_34 ( V_12 -> V_64 ) , & V_100 ) ;
F_29 ( & V_9 -> V_3 -> V_22 ) ;
V_9 -> V_12 = * V_12 ;
if ( V_9 -> V_27 == V_29 &&
V_9 -> V_100 == V_110 )
V_9 -> V_100 = V_100 ;
if ( ! memcmp ( & V_111 , & V_9 -> V_12 . V_5 , sizeof V_111 ) ) {
F_11 ( & V_9 -> V_7 , & V_9 -> V_3 -> V_8 ) ;
F_3 ( V_9 -> V_3 , V_9 , 1 ) ;
}
F_31 ( & V_9 -> V_3 -> V_22 ) ;
}
F_38 ( & V_9 -> V_31 ) ;
}
static void V_95 ( int V_98 , struct V_47 * V_12 ,
void * V_109 )
{
struct V_1 * V_9 = V_109 ;
if ( V_98 && V_9 -> V_112 > 0 &&
! F_25 ( V_9 , V_9 -> V_36 ) )
V_9 -> V_112 -- ;
else
F_38 ( & V_9 -> V_31 ) ;
}
static struct V_1 * F_42 ( struct V_2 * V_3 ,
union V_4 * V_5 , T_4 V_113 )
{
struct V_1 * V_9 , * V_18 ;
unsigned long V_21 ;
int V_114 ;
V_114 = ! memcmp ( & V_111 , V_5 , sizeof V_111 ) ;
if ( ! V_114 ) {
F_10 ( & V_3 -> V_22 , V_21 ) ;
V_9 = F_1 ( V_3 , V_5 ) ;
if ( V_9 )
goto V_115;
F_12 ( & V_3 -> V_22 , V_21 ) ;
}
V_9 = F_43 ( sizeof *V_9 , V_113 ) ;
if ( ! V_9 )
return NULL ;
V_9 -> V_112 = 3 ;
V_9 -> V_3 = V_3 ;
V_9 -> V_12 . V_5 = * V_5 ;
V_9 -> V_100 = V_110 ;
F_44 ( & V_9 -> V_26 ) ;
F_44 ( & V_9 -> V_97 ) ;
F_45 ( & V_9 -> V_31 , F_38 ) ;
F_46 ( & V_9 -> V_22 ) ;
F_10 ( & V_3 -> V_22 , V_21 ) ;
V_18 = F_3 ( V_3 , V_9 , V_114 ) ;
if ( V_18 ) {
F_13 ( V_9 ) ;
V_9 = V_18 ;
} else
F_17 ( & V_3 -> V_19 ) ;
V_115:
F_17 ( & V_9 -> V_19 ) ;
F_12 ( & V_3 -> V_22 , V_21 ) ;
return V_9 ;
}
struct V_107 *
F_47 ( struct V_116 * V_117 ,
struct V_118 * V_84 , T_1 V_85 ,
struct V_47 * V_12 ,
T_2 V_37 , T_4 V_113 ,
int (* V_99)( int V_98 ,
struct V_107 * V_87 ) ,
void * V_109 )
{
struct V_119 * V_83 ;
struct V_23 * V_24 ;
struct V_107 * V_87 ;
int V_10 ;
V_83 = F_48 ( V_84 , & V_120 ) ;
if ( ! V_83 )
return F_49 ( - V_121 ) ;
V_24 = F_50 ( sizeof *V_24 , V_113 ) ;
if ( ! V_24 )
return F_49 ( - V_122 ) ;
F_51 ( V_117 ) ;
V_24 -> V_117 = V_117 ;
V_24 -> V_87 . V_12 = * V_12 ;
V_24 -> V_87 . V_37 = V_37 ;
V_24 -> V_87 . V_99 = V_99 ;
V_24 -> V_87 . V_109 = V_109 ;
F_52 ( & V_24 -> V_20 ) ;
F_53 ( & V_24 -> V_19 , 1 ) ;
V_24 -> V_27 = V_123 ;
V_24 -> V_9 = F_42 ( & V_83 -> V_3 [ V_85 - V_83 -> V_124 ] ,
& V_12 -> V_5 , V_113 ) ;
if ( ! V_24 -> V_9 ) {
V_10 = - V_122 ;
goto V_43;
}
V_87 = & V_24 -> V_87 ;
F_15 ( V_24 ) ;
return V_87 ;
V_43:
F_54 ( V_117 ) ;
F_13 ( V_24 ) ;
return F_49 ( V_10 ) ;
}
void F_37 ( struct V_107 * V_87 )
{
struct V_23 * V_24 ;
struct V_1 * V_9 ;
V_24 = F_39 ( V_87 , struct V_23 , V_87 ) ;
V_9 = V_24 -> V_9 ;
F_29 ( & V_9 -> V_22 ) ;
if ( V_24 -> V_27 == V_96 )
F_19 ( V_9 , V_87 -> V_12 . V_32 , - 1 ) ;
F_30 ( & V_24 -> V_25 ) ;
if ( V_9 -> V_27 == V_28 ) {
V_9 -> V_27 = V_29 ;
F_31 ( & V_9 -> V_22 ) ;
F_18 ( V_30 , & V_9 -> V_31 ) ;
} else {
F_31 ( & V_9 -> V_22 ) ;
F_9 ( V_9 ) ;
}
F_14 ( V_24 ) ;
F_55 ( & V_24 -> V_20 ) ;
F_54 ( V_24 -> V_117 ) ;
F_13 ( V_24 ) ;
}
int F_56 ( struct V_118 * V_84 , T_1 V_85 ,
union V_4 * V_5 , struct V_47 * V_12 )
{
struct V_119 * V_83 ;
struct V_2 * V_3 ;
struct V_1 * V_9 ;
unsigned long V_21 ;
int V_10 = 0 ;
V_83 = F_48 ( V_84 , & V_120 ) ;
if ( ! V_83 )
return - V_121 ;
V_3 = & V_83 -> V_3 [ V_85 - V_83 -> V_124 ] ;
F_10 ( & V_3 -> V_22 , V_21 ) ;
V_9 = F_1 ( V_3 , V_5 ) ;
if ( V_9 )
* V_12 = V_9 -> V_12 ;
else
V_10 = - V_125 ;
F_12 ( & V_3 -> V_22 , V_21 ) ;
return V_10 ;
}
int F_57 ( struct V_118 * V_84 , T_1 V_85 ,
struct V_47 * V_12 ,
struct V_126 * V_127 )
{
int V_10 ;
T_3 V_128 ;
T_1 V_129 ;
V_10 = F_58 ( V_84 , & V_12 -> V_51 , & V_129 , & V_128 ) ;
if ( V_10 )
return V_10 ;
memset ( V_127 , 0 , sizeof *V_127 ) ;
V_127 -> V_130 = F_34 ( V_12 -> V_56 ) ;
V_127 -> V_74 = V_12 -> V_74 ;
V_127 -> V_85 = V_85 ;
V_127 -> V_131 = V_12 -> V_68 ;
V_127 -> V_132 = V_133 ;
V_127 -> V_134 . V_135 = V_12 -> V_5 ;
V_127 -> V_134 . V_136 = ( T_1 ) V_128 ;
V_127 -> V_134 . V_76 = F_59 ( V_12 -> V_76 ) ;
V_127 -> V_134 . V_78 = V_12 -> V_78 ;
V_127 -> V_134 . V_62 = V_12 -> V_62 ;
return 0 ;
}
static void F_60 ( struct V_2 * V_3 ,
enum V_137 V_27 )
{
struct V_1 * V_9 ;
struct V_6 * V_7 ;
unsigned long V_21 ;
F_10 ( & V_3 -> V_22 , V_21 ) ;
for ( V_7 = F_61 ( & V_3 -> V_8 ) ; V_7 ; V_7 = F_62 ( V_7 ) ) {
V_9 = F_2 ( V_7 , struct V_1 , V_7 ) ;
F_63 ( & V_9 -> V_22 ) ;
if ( V_9 -> V_27 == V_28 ) {
F_17 ( & V_9 -> V_19 ) ;
F_18 ( V_30 , & V_9 -> V_31 ) ;
}
if ( V_9 -> V_27 != V_138 )
V_9 -> V_27 = V_27 ;
F_64 ( & V_9 -> V_22 ) ;
}
F_12 ( & V_3 -> V_22 , V_21 ) ;
}
static void F_65 ( struct V_139 * V_140 ,
struct V_141 * V_142 )
{
struct V_119 * V_83 ;
int V_143 ;
V_83 = F_39 ( V_140 , struct V_119 , V_144 ) ;
if ( F_66 ( V_83 -> V_84 , V_142 -> V_145 . V_85 ) !=
V_146 )
return;
V_143 = V_142 -> V_145 . V_85 - V_83 -> V_124 ;
switch ( V_142 -> V_142 ) {
case V_147 :
case V_148 :
case V_149 :
case V_150 :
F_60 ( & V_83 -> V_3 [ V_143 ] , V_138 ) ;
break;
case V_151 :
F_60 ( & V_83 -> V_3 [ V_143 ] , V_101 ) ;
break;
default:
break;
}
}
static void F_67 ( struct V_118 * V_84 )
{
struct V_119 * V_83 ;
struct V_2 * V_3 ;
int V_34 ;
int V_152 = 0 ;
if ( F_68 ( V_84 -> V_153 ) != V_154 )
return;
V_83 = F_50 ( sizeof *V_83 + V_84 -> V_155 * sizeof *V_3 ,
V_88 ) ;
if ( ! V_83 )
return;
if ( V_84 -> V_153 == V_156 )
V_83 -> V_124 = V_83 -> V_157 = 0 ;
else {
V_83 -> V_124 = 1 ;
V_83 -> V_157 = V_84 -> V_155 ;
}
for ( V_34 = 0 ; V_34 <= V_83 -> V_157 - V_83 -> V_124 ; V_34 ++ ) {
if ( F_66 ( V_84 , V_83 -> V_124 + V_34 ) !=
V_146 )
continue;
V_3 = & V_83 -> V_3 [ V_34 ] ;
V_3 -> V_83 = V_83 ;
V_3 -> V_85 = V_83 -> V_124 + V_34 ;
F_46 ( & V_3 -> V_22 ) ;
V_3 -> V_8 = V_158 ;
F_52 ( & V_3 -> V_20 ) ;
F_53 ( & V_3 -> V_19 , 1 ) ;
++ V_152 ;
}
if ( ! V_152 ) {
F_13 ( V_83 ) ;
return;
}
V_83 -> V_84 = V_84 ;
F_69 ( V_84 , & V_120 , V_83 ) ;
F_70 ( & V_83 -> V_144 , V_84 , F_65 ) ;
F_71 ( & V_83 -> V_144 ) ;
}
static void F_72 ( struct V_118 * V_84 )
{
struct V_119 * V_83 ;
struct V_2 * V_3 ;
int V_34 ;
V_83 = F_48 ( V_84 , & V_120 ) ;
if ( ! V_83 )
return;
F_73 ( & V_83 -> V_144 ) ;
F_74 ( V_30 ) ;
for ( V_34 = 0 ; V_34 <= V_83 -> V_157 - V_83 -> V_124 ; V_34 ++ ) {
if ( F_66 ( V_84 , V_83 -> V_124 + V_34 ) ==
V_146 ) {
V_3 = & V_83 -> V_3 [ V_34 ] ;
F_6 ( V_3 ) ;
F_55 ( & V_3 -> V_20 ) ;
}
}
F_13 ( V_83 ) ;
}
int F_75 ( void )
{
int V_10 ;
V_30 = F_76 ( L_1 ) ;
if ( ! V_30 )
return - V_122 ;
F_77 ( & V_82 ) ;
V_10 = F_78 ( & V_120 ) ;
if ( V_10 )
goto V_43;
return 0 ;
V_43:
F_79 ( & V_82 ) ;
F_80 ( V_30 ) ;
return V_10 ;
}
void F_81 ( void )
{
F_82 ( & V_120 ) ;
F_79 ( & V_82 ) ;
F_80 ( V_30 ) ;
}
