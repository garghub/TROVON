static inline T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 [ 0 ] . V_5 ;
void T_2 * V_7 = V_2 -> V_8 ;
return V_5 -> V_9 ( V_7 + V_3 ) ;
}
static inline void F_2 ( struct V_1 * V_2 , unsigned int V_3 ,
T_1 V_10 )
{
struct V_4 * V_5 = & V_2 -> V_6 [ 0 ] . V_5 ;
void T_2 * V_7 = V_2 -> V_8 ;
V_5 -> V_11 ( V_7 + V_3 , V_10 ) ;
}
static int F_3 ( struct V_4 * V_5 , unsigned V_3 )
{
struct V_12 * V_13 = F_4 ( V_5 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
return F_5 ( V_2 -> V_14 , V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned int V_15 )
{
T_1 V_16 = F_1 ( V_2 , V_17 ) ;
if ( F_7 ( V_2 -> V_6 [ 0 ] . V_5 . V_18 + V_15 ) )
V_16 &= ~ F_8 ( V_15 ) ;
else
V_16 |= F_8 ( V_15 ) ;
F_2 ( V_2 , V_17 , V_16 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
T_1 V_19 = F_10 ( V_2 -> V_8 + V_20 ) ;
T_1 V_21 = V_19 ;
while ( V_19 ) {
int V_22 = F_11 ( V_19 ) - 1 ;
int V_23 = F_5 ( V_2 -> V_14 , V_22 ) ;
F_12 ( V_23 ) ;
V_19 &= ~ F_8 ( V_22 ) ;
if ( ( F_13 ( V_23 ) & V_24 )
== V_25 )
F_6 ( V_2 , V_22 ) ;
}
return V_21 ;
}
static void F_14 ( struct V_26 * V_27 )
{
struct V_1 * V_2 = F_15 ( V_27 ) ;
struct V_28 * V_29 = F_16 ( V_27 ) ;
F_9 ( V_2 ) ;
if ( V_29 -> V_30 )
V_29 -> V_30 ( F_17 ( V_27 ) ) ;
}
static void F_18 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = F_19 ( V_32 ) ;
struct V_1 * V_2 = V_34 -> V_35 ;
struct V_4 * V_5 = & V_2 -> V_6 [ 0 ] . V_5 ;
unsigned long V_36 ;
T_1 V_10 ;
F_20 ( & V_5 -> V_37 , V_36 ) ;
V_10 = F_1 ( V_2 , V_38 ) ;
V_10 |= F_8 ( V_32 -> V_22 ) ;
F_2 ( V_2 , V_38 , V_10 ) ;
F_21 ( & V_5 -> V_37 , V_36 ) ;
}
static void F_22 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = F_19 ( V_32 ) ;
struct V_1 * V_2 = V_34 -> V_35 ;
struct V_4 * V_5 = & V_2 -> V_6 [ 0 ] . V_5 ;
unsigned long V_36 ;
T_1 V_10 ;
F_20 ( & V_5 -> V_37 , V_36 ) ;
V_10 = F_1 ( V_2 , V_38 ) ;
V_10 &= ~ F_8 ( V_32 -> V_22 ) ;
F_2 ( V_2 , V_38 , V_10 ) ;
F_21 ( & V_5 -> V_37 , V_36 ) ;
}
static int F_23 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = F_19 ( V_32 ) ;
struct V_1 * V_2 = V_34 -> V_35 ;
struct V_4 * V_5 = & V_2 -> V_6 [ 0 ] . V_5 ;
if ( F_24 ( V_5 , F_25 ( V_32 ) ) ) {
F_26 ( V_2 -> V_39 , L_1 ,
F_25 ( V_32 ) ) ;
return - V_40 ;
}
return 0 ;
}
static void F_27 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = F_19 ( V_32 ) ;
struct V_1 * V_2 = V_34 -> V_35 ;
struct V_4 * V_5 = & V_2 -> V_6 [ 0 ] . V_5 ;
F_28 ( V_5 , F_25 ( V_32 ) ) ;
}
static int F_29 ( struct V_31 * V_32 , T_1 type )
{
struct V_33 * V_34 = F_19 ( V_32 ) ;
struct V_1 * V_2 = V_34 -> V_35 ;
struct V_4 * V_5 = & V_2 -> V_6 [ 0 ] . V_5 ;
int V_41 = V_32 -> V_22 ;
unsigned long V_42 , V_43 , V_36 ;
if ( type & ~ ( V_44 | V_45 |
V_46 | V_47 ) )
return - V_40 ;
F_20 ( & V_5 -> V_37 , V_36 ) ;
V_42 = F_1 ( V_2 , V_48 ) ;
V_43 = F_1 ( V_2 , V_17 ) ;
switch ( type ) {
case V_25 :
V_42 |= F_8 ( V_41 ) ;
F_6 ( V_2 , V_41 ) ;
break;
case V_44 :
V_42 |= F_8 ( V_41 ) ;
V_43 |= F_8 ( V_41 ) ;
break;
case V_45 :
V_42 |= F_8 ( V_41 ) ;
V_43 &= ~ F_8 ( V_41 ) ;
break;
case V_46 :
V_42 &= ~ F_8 ( V_41 ) ;
V_43 |= F_8 ( V_41 ) ;
break;
case V_47 :
V_42 &= ~ F_8 ( V_41 ) ;
V_43 &= ~ F_8 ( V_41 ) ;
break;
}
F_30 ( V_32 , type ) ;
F_2 ( V_2 , V_48 , V_42 ) ;
F_2 ( V_2 , V_17 , V_43 ) ;
F_21 ( & V_5 -> V_37 , V_36 ) ;
return 0 ;
}
static int F_31 ( struct V_4 * V_5 ,
unsigned V_3 , unsigned V_49 )
{
struct V_12 * V_13 = F_4 ( V_5 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
unsigned long V_36 , V_50 ;
unsigned long V_51 = V_5 -> V_52 ( V_5 , V_3 ) ;
F_20 ( & V_5 -> V_37 , V_36 ) ;
V_50 = F_1 ( V_2 , V_53 ) ;
if ( V_49 )
F_2 ( V_2 , V_53 , V_50 | V_51 ) ;
else
F_2 ( V_2 , V_53 , V_50 & ~ V_51 ) ;
F_21 ( & V_5 -> V_37 , V_36 ) ;
return 0 ;
}
static int F_32 ( struct V_4 * V_5 , unsigned V_3 ,
unsigned long V_54 )
{
T_1 V_49 ;
if ( F_33 ( V_54 ) != V_55 )
return - V_56 ;
V_49 = F_34 ( V_54 ) ;
return F_31 ( V_5 , V_3 , V_49 ) ;
}
static T_3 F_35 ( int V_57 , void * V_58 )
{
T_1 V_59 ;
struct V_1 * V_2 = V_58 ;
V_59 = F_9 ( V_2 ) ;
return V_59 ? V_60 : V_61 ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_62 * V_63 )
{
struct V_4 * V_5 = & V_13 -> V_5 ;
struct V_64 * V_65 = V_63 -> V_65 ;
struct V_33 * V_66 = NULL ;
unsigned int V_22 , V_67 = V_5 -> V_67 ;
struct V_68 * V_69 ;
int V_70 , V_71 ;
V_2 -> V_14 = F_37 ( V_65 , V_67 ,
& V_72 , V_2 ) ;
if ( ! V_2 -> V_14 )
return;
V_70 = F_38 ( V_2 -> V_14 , V_67 , 2 ,
L_2 , V_73 ,
V_74 , 0 ,
V_75 ) ;
if ( V_70 ) {
F_39 ( V_2 -> V_39 , L_3 ) ;
F_40 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
return;
}
V_66 = F_41 ( V_2 -> V_14 , 0 ) ;
if ( ! V_66 ) {
F_40 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
return;
}
V_66 -> V_7 = V_2 -> V_8 ;
V_66 -> V_35 = V_2 ;
for ( V_71 = 0 ; V_71 < 2 ; V_71 ++ ) {
V_69 = & V_66 -> V_76 [ V_71 ] ;
V_69 -> V_29 . V_77 = V_78 ;
V_69 -> V_29 . V_79 = V_80 ;
V_69 -> V_29 . V_81 = V_82 ;
V_69 -> V_29 . V_83 = F_29 ;
V_69 -> V_29 . V_84 = F_18 ;
V_69 -> V_29 . V_85 = F_22 ;
V_69 -> V_29 . V_86 = F_23 ;
V_69 -> V_29 . V_87 = F_27 ;
V_69 -> V_8 . V_88 = V_89 ;
V_69 -> V_8 . V_51 = V_90 ;
V_69 -> type = V_91 ;
}
V_66 -> V_76 [ 0 ] . type = V_91 ;
V_66 -> V_76 [ 1 ] . type = V_25 ;
V_66 -> V_76 [ 1 ] . V_92 = V_93 ;
if ( ! V_63 -> V_94 ) {
F_42 ( V_63 -> V_57 , F_14 ,
V_2 ) ;
} else {
V_70 = F_43 ( V_2 -> V_39 , V_63 -> V_57 ,
F_35 ,
V_95 , L_4 , V_2 ) ;
if ( V_70 ) {
F_26 ( V_2 -> V_39 , L_5 ) ;
F_40 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
return;
}
}
for ( V_22 = 0 ; V_22 < V_67 ; V_22 ++ )
F_44 ( V_2 -> V_14 , V_22 ) ;
V_13 -> V_5 . V_96 = F_3 ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = & V_2 -> V_6 [ 0 ] ;
struct V_4 * V_5 = & V_13 -> V_5 ;
unsigned int V_67 = V_5 -> V_67 ;
T_4 V_22 ;
if ( ! V_2 -> V_14 )
return;
for ( V_22 = 0 ; V_22 < V_67 ; V_22 ++ )
F_46 ( F_5 ( V_2 -> V_14 , V_22 ) ) ;
F_40 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_62 * V_63 ,
unsigned int V_15 )
{
struct V_12 * V_13 ;
void T_2 * V_97 , * V_98 , * V_99 ;
int V_70 ;
V_13 = & V_2 -> V_6 [ V_15 ] ;
V_13 -> V_2 = V_2 ;
V_13 -> V_100 = V_63 -> V_100 ;
#ifdef F_48
V_13 -> V_101 = F_49 ( V_2 -> V_39 , sizeof( * V_13 -> V_101 ) , V_102 ) ;
if ( ! V_13 -> V_101 )
return - V_103 ;
#endif
V_97 = V_2 -> V_8 + V_104 + ( V_63 -> V_100 * V_105 ) ;
V_98 = V_2 -> V_8 + V_106 + ( V_63 -> V_100 * V_107 ) ;
V_99 = V_2 -> V_8 + V_108 +
( V_63 -> V_100 * V_109 ) ;
V_70 = F_50 ( & V_13 -> V_5 , V_2 -> V_39 , 4 , V_97 , V_98 , NULL , V_99 ,
NULL , false ) ;
if ( V_70 ) {
F_26 ( V_2 -> V_39 , L_6 ,
V_13 -> V_100 ) ;
return V_70 ;
}
#ifdef F_51
V_13 -> V_5 . V_110 = F_52 ( V_63 -> V_65 ) ;
#endif
V_13 -> V_5 . V_67 = V_63 -> V_67 ;
V_13 -> V_5 . V_18 = V_63 -> V_111 ;
if ( V_63 -> V_100 == 0 )
V_13 -> V_5 . V_112 = F_32 ;
if ( V_63 -> V_57 )
F_36 ( V_2 , V_13 , V_63 ) ;
V_70 = F_53 ( & V_13 -> V_5 , V_13 ) ;
if ( V_70 )
F_26 ( V_2 -> V_39 , L_7 ,
V_13 -> V_100 ) ;
else
V_13 -> V_113 = true ;
if ( V_63 -> V_57 )
F_54 ( & V_13 -> V_5 ) ;
return V_70 ;
}
static void F_55 ( struct V_1 * V_2 )
{
unsigned int V_114 ;
for ( V_114 = 0 ; V_114 < V_2 -> V_115 ; ++ V_114 )
if ( V_2 -> V_6 [ V_114 ] . V_113 )
F_56 ( & V_2 -> V_6 [ V_114 ] . V_5 ) ;
}
static struct V_116 *
F_57 ( struct V_117 * V_39 )
{
struct V_64 * V_65 ;
struct V_116 * V_118 ;
struct V_62 * V_63 ;
int V_119 ;
int V_71 ;
V_119 = F_58 ( V_39 ) ;
if ( V_119 == 0 )
return F_59 ( - V_120 ) ;
V_118 = F_49 ( V_39 , sizeof( * V_118 ) , V_102 ) ;
if ( ! V_118 )
return F_59 ( - V_103 ) ;
V_118 -> V_121 = F_60 ( V_39 , V_119 , sizeof( * V_63 ) , V_102 ) ;
if ( ! V_118 -> V_121 )
return F_59 ( - V_103 ) ;
V_118 -> V_119 = V_119 ;
V_71 = 0 ;
F_61 (dev, fwnode) {
V_63 = & V_118 -> V_121 [ V_71 ++ ] ;
V_63 -> V_65 = V_65 ;
if ( F_62 ( V_65 , L_8 , & V_63 -> V_100 ) ||
V_63 -> V_100 >= V_122 ) {
F_26 ( V_39 ,
L_9 , V_71 ) ;
F_63 ( V_65 ) ;
return F_59 ( - V_40 ) ;
}
if ( F_62 ( V_65 , L_10 ,
& V_63 -> V_67 ) ) {
F_39 ( V_39 ,
L_11 ,
V_71 ) ;
V_63 -> V_67 = 32 ;
}
if ( V_39 -> V_110 && V_63 -> V_100 == 0 &&
F_64 ( V_65 ,
L_12 ) ) {
V_63 -> V_57 = F_65 ( F_52 ( V_65 ) , 0 ) ;
if ( ! V_63 -> V_57 )
F_66 ( V_39 , L_13 , V_63 -> V_100 ) ;
}
if ( F_67 ( V_39 ) && V_63 -> V_100 == 0 )
V_63 -> V_57 = F_68 ( F_69 ( V_39 ) , 0 ) ;
V_63 -> V_94 = false ;
V_63 -> V_111 = - 1 ;
}
return V_118 ;
}
static int F_70 ( struct V_123 * V_124 )
{
unsigned int V_71 ;
struct V_125 * V_126 ;
struct V_1 * V_2 ;
int V_70 ;
struct V_117 * V_39 = & V_124 -> V_39 ;
struct V_116 * V_118 = F_71 ( V_39 ) ;
if ( ! V_118 ) {
V_118 = F_57 ( V_39 ) ;
if ( F_72 ( V_118 ) )
return F_73 ( V_118 ) ;
}
if ( ! V_118 -> V_119 )
return - V_120 ;
V_2 = F_49 ( & V_124 -> V_39 , sizeof( * V_2 ) , V_102 ) ;
if ( ! V_2 )
return - V_103 ;
V_2 -> V_39 = & V_124 -> V_39 ;
V_2 -> V_115 = V_118 -> V_119 ;
V_2 -> V_6 = F_60 ( & V_124 -> V_39 , V_2 -> V_115 ,
sizeof( * V_2 -> V_6 ) , V_102 ) ;
if ( ! V_2 -> V_6 )
return - V_103 ;
V_126 = F_74 ( V_124 , V_127 , 0 ) ;
V_2 -> V_8 = F_75 ( & V_124 -> V_39 , V_126 ) ;
if ( F_72 ( V_2 -> V_8 ) )
return F_73 ( V_2 -> V_8 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_115 ; V_71 ++ ) {
V_70 = F_47 ( V_2 , & V_118 -> V_121 [ V_71 ] , V_71 ) ;
if ( V_70 )
goto V_128;
}
F_76 ( V_124 , V_2 ) ;
return 0 ;
V_128:
F_55 ( V_2 ) ;
F_45 ( V_2 ) ;
return V_70 ;
}
static int F_77 ( struct V_123 * V_124 )
{
struct V_1 * V_2 = F_78 ( V_124 ) ;
F_55 ( V_2 ) ;
F_45 ( V_2 ) ;
return 0 ;
}
static int F_79 ( struct V_117 * V_39 )
{
struct V_123 * V_124 = F_69 ( V_39 ) ;
struct V_1 * V_2 = F_78 ( V_124 ) ;
struct V_4 * V_5 = & V_2 -> V_6 [ 0 ] . V_5 ;
unsigned long V_36 ;
int V_71 ;
F_20 ( & V_5 -> V_37 , V_36 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_115 ; V_71 ++ ) {
unsigned int V_3 ;
unsigned int V_100 = V_2 -> V_6 [ V_71 ] . V_100 ;
struct V_129 * V_101 = V_2 -> V_6 [ V_71 ] . V_101 ;
F_80 ( ! V_101 ) ;
V_3 = V_108 + V_100 * V_109 ;
V_101 -> V_130 = F_1 ( V_2 , V_3 ) ;
V_3 = V_106 + V_100 * V_107 ;
V_101 -> V_131 = F_1 ( V_2 , V_3 ) ;
V_3 = V_104 + V_100 * V_105 ;
V_101 -> V_132 = F_1 ( V_2 , V_3 ) ;
if ( V_100 == 0 ) {
V_101 -> V_133 = F_1 ( V_2 , V_90 ) ;
V_101 -> V_134 = F_1 ( V_2 , V_38 ) ;
V_101 -> V_135 = F_1 ( V_2 , V_17 ) ;
V_101 -> V_136 = F_1 ( V_2 , V_48 ) ;
V_101 -> V_137 = F_1 ( V_2 , V_53 ) ;
F_2 ( V_2 , V_90 , 0xffffffff ) ;
}
}
F_21 ( & V_5 -> V_37 , V_36 ) ;
return 0 ;
}
static int F_81 ( struct V_117 * V_39 )
{
struct V_123 * V_124 = F_69 ( V_39 ) ;
struct V_1 * V_2 = F_78 ( V_124 ) ;
struct V_4 * V_5 = & V_2 -> V_6 [ 0 ] . V_5 ;
unsigned long V_36 ;
int V_71 ;
F_20 ( & V_5 -> V_37 , V_36 ) ;
for ( V_71 = 0 ; V_71 < V_2 -> V_115 ; V_71 ++ ) {
unsigned int V_3 ;
unsigned int V_100 = V_2 -> V_6 [ V_71 ] . V_100 ;
struct V_129 * V_101 = V_2 -> V_6 [ V_71 ] . V_101 ;
F_80 ( ! V_101 ) ;
V_3 = V_106 + V_100 * V_107 ;
F_2 ( V_2 , V_3 , V_101 -> V_131 ) ;
V_3 = V_108 + V_100 * V_109 ;
F_2 ( V_2 , V_3 , V_101 -> V_130 ) ;
V_3 = V_104 + V_100 * V_105 ;
F_2 ( V_2 , V_3 , V_101 -> V_132 ) ;
if ( V_100 == 0 ) {
F_2 ( V_2 , V_48 , V_101 -> V_136 ) ;
F_2 ( V_2 , V_17 , V_101 -> V_135 ) ;
F_2 ( V_2 , V_53 , V_101 -> V_137 ) ;
F_2 ( V_2 , V_38 , V_101 -> V_134 ) ;
F_2 ( V_2 , V_90 , V_101 -> V_133 ) ;
F_2 ( V_2 , V_89 , 0xffffffff ) ;
}
}
F_21 ( & V_5 -> V_37 , V_36 ) ;
return 0 ;
}
