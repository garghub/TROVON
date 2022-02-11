static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_4 * V_5 , unsigned int V_6 )
{
struct V_2 * V_3 = & V_5 -> V_7 [ 0 ] . V_3 ;
void T_2 * V_8 = V_5 -> V_9 ;
return V_3 -> V_10 ( V_8 + V_6 ) ;
}
static inline void F_4 ( struct V_4 * V_5 , unsigned int V_6 ,
T_1 V_11 )
{
struct V_2 * V_3 = & V_5 -> V_7 [ 0 ] . V_3 ;
void T_2 * V_8 = V_5 -> V_9 ;
V_3 -> V_12 ( V_8 + V_6 , V_11 ) ;
}
static int F_5 ( struct V_13 * V_14 , unsigned V_6 )
{
struct V_2 * V_3 = F_6 ( V_14 ) ;
struct V_1 * V_15 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_15 -> V_5 ;
return F_7 ( V_5 -> V_16 , V_6 ) ;
}
static void F_8 ( struct V_4 * V_5 , unsigned int V_17 )
{
T_1 V_18 = F_3 ( V_5 , V_19 ) ;
if ( F_9 ( V_5 -> V_7 [ 0 ] . V_3 . V_14 . V_20 + V_17 ) )
V_18 &= ~ F_10 ( V_17 ) ;
else
V_18 |= F_10 ( V_17 ) ;
F_4 ( V_5 , V_19 , V_18 ) ;
}
static T_1 F_11 ( struct V_4 * V_5 )
{
T_1 V_21 = F_12 ( V_5 -> V_9 + V_22 ) ;
T_1 V_23 = V_21 ;
while ( V_21 ) {
int V_24 = F_13 ( V_21 ) - 1 ;
int V_25 = F_7 ( V_5 -> V_16 , V_24 ) ;
F_14 ( V_25 ) ;
V_21 &= ~ F_10 ( V_24 ) ;
if ( ( F_15 ( V_25 ) & V_26 )
== V_27 )
F_8 ( V_5 , V_24 ) ;
}
return V_23 ;
}
static void F_16 ( struct V_28 * V_29 )
{
struct V_4 * V_5 = F_17 ( V_29 ) ;
struct V_30 * V_31 = F_18 ( V_29 ) ;
F_11 ( V_5 ) ;
if ( V_31 -> V_32 )
V_31 -> V_32 ( F_19 ( V_29 ) ) ;
}
static void F_20 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_21 ( V_34 ) ;
struct V_4 * V_5 = V_36 -> V_37 ;
struct V_2 * V_3 = & V_5 -> V_7 [ 0 ] . V_3 ;
unsigned long V_38 ;
T_1 V_11 ;
F_22 ( & V_3 -> V_39 , V_38 ) ;
V_11 = F_3 ( V_5 , V_40 ) ;
V_11 |= F_10 ( V_34 -> V_24 ) ;
F_4 ( V_5 , V_40 , V_11 ) ;
F_23 ( & V_3 -> V_39 , V_38 ) ;
}
static void F_24 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_21 ( V_34 ) ;
struct V_4 * V_5 = V_36 -> V_37 ;
struct V_2 * V_3 = & V_5 -> V_7 [ 0 ] . V_3 ;
unsigned long V_38 ;
T_1 V_11 ;
F_22 ( & V_3 -> V_39 , V_38 ) ;
V_11 = F_3 ( V_5 , V_40 ) ;
V_11 &= ~ F_10 ( V_34 -> V_24 ) ;
F_4 ( V_5 , V_40 , V_11 ) ;
F_23 ( & V_3 -> V_39 , V_38 ) ;
}
static int F_25 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_21 ( V_34 ) ;
struct V_4 * V_5 = V_36 -> V_37 ;
struct V_2 * V_3 = & V_5 -> V_7 [ 0 ] . V_3 ;
if ( F_26 ( & V_3 -> V_14 , F_27 ( V_34 ) ) ) {
F_28 ( V_5 -> V_41 , L_1 ,
F_27 ( V_34 ) ) ;
return - V_42 ;
}
return 0 ;
}
static void F_29 ( struct V_33 * V_34 )
{
struct V_35 * V_36 = F_21 ( V_34 ) ;
struct V_4 * V_5 = V_36 -> V_37 ;
struct V_2 * V_3 = & V_5 -> V_7 [ 0 ] . V_3 ;
F_30 ( & V_3 -> V_14 , F_27 ( V_34 ) ) ;
}
static int F_31 ( struct V_33 * V_34 , T_1 type )
{
struct V_35 * V_36 = F_21 ( V_34 ) ;
struct V_4 * V_5 = V_36 -> V_37 ;
struct V_2 * V_3 = & V_5 -> V_7 [ 0 ] . V_3 ;
int V_43 = V_34 -> V_24 ;
unsigned long V_44 , V_45 , V_38 ;
if ( type & ~ ( V_46 | V_47 |
V_48 | V_49 ) )
return - V_42 ;
F_22 ( & V_3 -> V_39 , V_38 ) ;
V_44 = F_3 ( V_5 , V_50 ) ;
V_45 = F_3 ( V_5 , V_19 ) ;
switch ( type ) {
case V_27 :
V_44 |= F_10 ( V_43 ) ;
F_8 ( V_5 , V_43 ) ;
break;
case V_46 :
V_44 |= F_10 ( V_43 ) ;
V_45 |= F_10 ( V_43 ) ;
break;
case V_47 :
V_44 |= F_10 ( V_43 ) ;
V_45 &= ~ F_10 ( V_43 ) ;
break;
case V_48 :
V_44 &= ~ F_10 ( V_43 ) ;
V_45 |= F_10 ( V_43 ) ;
break;
case V_49 :
V_44 &= ~ F_10 ( V_43 ) ;
V_45 &= ~ F_10 ( V_43 ) ;
break;
}
F_32 ( V_34 , type ) ;
F_4 ( V_5 , V_50 , V_44 ) ;
F_4 ( V_5 , V_19 , V_45 ) ;
F_23 ( & V_3 -> V_39 , V_38 ) ;
return 0 ;
}
static int F_33 ( struct V_13 * V_14 ,
unsigned V_6 , unsigned V_51 )
{
struct V_2 * V_3 = F_6 ( V_14 ) ;
struct V_1 * V_15 = F_1 ( V_3 ) ;
struct V_4 * V_5 = V_15 -> V_5 ;
unsigned long V_38 , V_52 ;
unsigned long V_53 = V_3 -> V_54 ( V_3 , V_6 ) ;
F_22 ( & V_3 -> V_39 , V_38 ) ;
V_52 = F_3 ( V_5 , V_55 ) ;
if ( V_51 )
F_4 ( V_5 , V_55 , V_52 | V_53 ) ;
else
F_4 ( V_5 , V_55 , V_52 & ~ V_53 ) ;
F_23 ( & V_3 -> V_39 , V_38 ) ;
return 0 ;
}
static T_3 F_34 ( int V_56 , void * V_57 )
{
T_1 V_58 ;
struct V_4 * V_5 = V_57 ;
V_58 = F_11 ( V_5 ) ;
return V_58 ? V_59 : V_60 ;
}
static void F_35 ( struct V_4 * V_5 ,
struct V_1 * V_15 ,
struct V_61 * V_62 )
{
struct V_13 * V_14 = & V_15 -> V_3 . V_14 ;
struct V_63 * V_64 = V_62 -> V_64 ;
struct V_35 * V_65 = NULL ;
unsigned int V_24 , V_66 = V_14 -> V_66 ;
struct V_67 * V_68 ;
int V_69 , V_70 ;
V_5 -> V_16 = F_36 ( V_64 , V_66 ,
& V_71 , V_5 ) ;
if ( ! V_5 -> V_16 )
return;
V_69 = F_37 ( V_5 -> V_16 , V_66 , 2 ,
L_2 , V_72 ,
V_73 , 0 ,
V_74 ) ;
if ( V_69 ) {
F_38 ( V_5 -> V_41 , L_3 ) ;
F_39 ( V_5 -> V_16 ) ;
V_5 -> V_16 = NULL ;
return;
}
V_65 = F_40 ( V_5 -> V_16 , 0 ) ;
if ( ! V_65 ) {
F_39 ( V_5 -> V_16 ) ;
V_5 -> V_16 = NULL ;
return;
}
V_65 -> V_8 = V_5 -> V_9 ;
V_65 -> V_37 = V_5 ;
for ( V_70 = 0 ; V_70 < 2 ; V_70 ++ ) {
V_68 = & V_65 -> V_75 [ V_70 ] ;
V_68 -> V_31 . V_76 = V_77 ;
V_68 -> V_31 . V_78 = V_79 ;
V_68 -> V_31 . V_80 = V_81 ;
V_68 -> V_31 . V_82 = F_31 ;
V_68 -> V_31 . V_83 = F_20 ;
V_68 -> V_31 . V_84 = F_24 ;
V_68 -> V_31 . V_85 = F_25 ;
V_68 -> V_31 . V_86 = F_29 ;
V_68 -> V_9 . V_87 = V_88 ;
V_68 -> V_9 . V_53 = V_89 ;
V_68 -> type = V_90 ;
}
V_65 -> V_75 [ 0 ] . type = V_90 ;
V_65 -> V_75 [ 1 ] . type = V_27 ;
V_65 -> V_75 [ 1 ] . V_91 = V_92 ;
if ( ! V_62 -> V_93 ) {
F_41 ( V_62 -> V_56 , F_16 ,
V_5 ) ;
} else {
V_69 = F_42 ( V_5 -> V_41 , V_62 -> V_56 ,
F_34 ,
V_94 , L_4 , V_5 ) ;
if ( V_69 ) {
F_28 ( V_5 -> V_41 , L_5 ) ;
F_39 ( V_5 -> V_16 ) ;
V_5 -> V_16 = NULL ;
return;
}
}
for ( V_24 = 0 ; V_24 < V_66 ; V_24 ++ )
F_43 ( V_5 -> V_16 , V_24 ) ;
V_15 -> V_3 . V_14 . V_95 = F_5 ;
}
static void F_44 ( struct V_4 * V_5 )
{
struct V_1 * V_15 = & V_5 -> V_7 [ 0 ] ;
struct V_13 * V_14 = & V_15 -> V_3 . V_14 ;
unsigned int V_66 = V_14 -> V_66 ;
T_4 V_24 ;
if ( ! V_5 -> V_16 )
return;
for ( V_24 = 0 ; V_24 < V_66 ; V_24 ++ )
F_45 ( F_7 ( V_5 -> V_16 , V_24 ) ) ;
F_39 ( V_5 -> V_16 ) ;
V_5 -> V_16 = NULL ;
}
static int F_46 ( struct V_4 * V_5 ,
struct V_61 * V_62 ,
unsigned int V_17 )
{
struct V_1 * V_15 ;
void T_2 * V_96 , * V_97 , * V_98 ;
int V_69 ;
V_15 = & V_5 -> V_7 [ V_17 ] ;
V_15 -> V_5 = V_5 ;
V_15 -> V_99 = V_62 -> V_99 ;
#ifdef F_47
V_15 -> V_100 = F_48 ( V_5 -> V_41 , sizeof( * V_15 -> V_100 ) , V_101 ) ;
if ( ! V_15 -> V_100 )
return - V_102 ;
#endif
V_96 = V_5 -> V_9 + V_103 + ( V_62 -> V_99 * V_104 ) ;
V_97 = V_5 -> V_9 + V_105 + ( V_62 -> V_99 * V_106 ) ;
V_98 = V_5 -> V_9 + V_107 +
( V_62 -> V_99 * V_108 ) ;
V_69 = F_49 ( & V_15 -> V_3 , V_5 -> V_41 , 4 , V_96 , V_97 , NULL , V_98 ,
NULL , false ) ;
if ( V_69 ) {
F_28 ( V_5 -> V_41 , L_6 ,
V_62 -> V_109 ) ;
return V_69 ;
}
#ifdef F_50
V_15 -> V_3 . V_14 . V_110 = V_62 -> V_64 ;
#endif
V_15 -> V_3 . V_14 . V_66 = V_62 -> V_66 ;
V_15 -> V_3 . V_14 . V_20 = V_62 -> V_111 ;
if ( V_62 -> V_99 == 0 )
V_15 -> V_3 . V_14 . V_112 = F_33 ;
if ( V_62 -> V_56 )
F_35 ( V_5 , V_15 , V_62 ) ;
V_69 = F_51 ( & V_15 -> V_3 . V_14 ) ;
if ( V_69 )
F_28 ( V_5 -> V_41 , L_7 ,
V_62 -> V_109 ) ;
else
V_15 -> V_113 = true ;
return V_69 ;
}
static void F_52 ( struct V_4 * V_5 )
{
unsigned int V_114 ;
for ( V_114 = 0 ; V_114 < V_5 -> V_115 ; ++ V_114 )
if ( V_5 -> V_7 [ V_114 ] . V_113 )
F_53 ( & V_5 -> V_7 [ V_114 ] . V_3 . V_14 ) ;
}
static struct V_116 *
F_54 ( struct V_117 * V_41 )
{
struct V_63 * V_64 , * V_118 ;
struct V_116 * V_119 ;
struct V_61 * V_62 ;
int V_120 ;
int V_70 ;
V_64 = V_41 -> V_110 ;
if ( ! F_55 ( F_50 ) || ! V_64 )
return F_56 ( - V_121 ) ;
V_120 = F_57 ( V_64 ) ;
if ( V_120 == 0 )
return F_56 ( - V_121 ) ;
V_119 = F_48 ( V_41 , sizeof( * V_119 ) , V_101 ) ;
if ( ! V_119 )
return F_56 ( - V_102 ) ;
V_119 -> V_122 = F_58 ( V_41 , V_120 , sizeof( * V_62 ) , V_101 ) ;
if ( ! V_119 -> V_122 )
return F_56 ( - V_102 ) ;
V_119 -> V_120 = V_120 ;
V_70 = 0 ;
F_59 (node, port_np) {
V_62 = & V_119 -> V_122 [ V_70 ++ ] ;
V_62 -> V_64 = V_118 ;
if ( F_60 ( V_118 , L_8 , & V_62 -> V_99 ) ||
V_62 -> V_99 >= V_123 ) {
F_28 ( V_41 , L_9 ,
V_118 -> V_124 ) ;
return F_56 ( - V_42 ) ;
}
if ( F_60 ( V_118 , L_10 ,
& V_62 -> V_66 ) ) {
F_38 ( V_41 , L_11 ,
V_118 -> V_124 ) ;
V_62 -> V_66 = 32 ;
}
if ( V_62 -> V_99 == 0 &&
F_61 ( V_118 , L_12 ) ) {
V_62 -> V_56 = F_62 ( V_118 , 0 ) ;
if ( ! V_62 -> V_56 ) {
F_63 ( V_41 , L_13 ,
V_118 -> V_124 ) ;
}
}
V_62 -> V_93 = false ;
V_62 -> V_111 = - 1 ;
V_62 -> V_109 = V_118 -> V_124 ;
}
return V_119 ;
}
static int F_64 ( struct V_125 * V_126 )
{
unsigned int V_70 ;
struct V_127 * V_128 ;
struct V_4 * V_5 ;
int V_69 ;
struct V_117 * V_41 = & V_126 -> V_41 ;
struct V_116 * V_119 = F_65 ( V_41 ) ;
if ( ! V_119 ) {
V_119 = F_54 ( V_41 ) ;
if ( F_66 ( V_119 ) )
return F_67 ( V_119 ) ;
}
if ( ! V_119 -> V_120 )
return - V_121 ;
V_5 = F_48 ( & V_126 -> V_41 , sizeof( * V_5 ) , V_101 ) ;
if ( ! V_5 )
return - V_102 ;
V_5 -> V_41 = & V_126 -> V_41 ;
V_5 -> V_115 = V_119 -> V_120 ;
V_5 -> V_7 = F_58 ( & V_126 -> V_41 , V_5 -> V_115 ,
sizeof( * V_5 -> V_7 ) , V_101 ) ;
if ( ! V_5 -> V_7 )
return - V_102 ;
V_128 = F_68 ( V_126 , V_129 , 0 ) ;
V_5 -> V_9 = F_69 ( & V_126 -> V_41 , V_128 ) ;
if ( F_66 ( V_5 -> V_9 ) )
return F_67 ( V_5 -> V_9 ) ;
for ( V_70 = 0 ; V_70 < V_5 -> V_115 ; V_70 ++ ) {
V_69 = F_46 ( V_5 , & V_119 -> V_122 [ V_70 ] , V_70 ) ;
if ( V_69 )
goto V_130;
}
F_70 ( V_126 , V_5 ) ;
return 0 ;
V_130:
F_52 ( V_5 ) ;
F_44 ( V_5 ) ;
return V_69 ;
}
static int F_71 ( struct V_125 * V_126 )
{
struct V_4 * V_5 = F_72 ( V_126 ) ;
F_52 ( V_5 ) ;
F_44 ( V_5 ) ;
return 0 ;
}
static int F_73 ( struct V_117 * V_41 )
{
struct V_125 * V_126 = F_74 ( V_41 ) ;
struct V_4 * V_5 = F_72 ( V_126 ) ;
struct V_2 * V_3 = & V_5 -> V_7 [ 0 ] . V_3 ;
unsigned long V_38 ;
int V_70 ;
F_22 ( & V_3 -> V_39 , V_38 ) ;
for ( V_70 = 0 ; V_70 < V_5 -> V_115 ; V_70 ++ ) {
unsigned int V_6 ;
unsigned int V_99 = V_5 -> V_7 [ V_70 ] . V_99 ;
struct V_131 * V_100 = V_5 -> V_7 [ V_70 ] . V_100 ;
F_75 ( ! V_100 ) ;
V_6 = V_107 + V_99 * V_108 ;
V_100 -> V_132 = F_3 ( V_5 , V_6 ) ;
V_6 = V_105 + V_99 * V_106 ;
V_100 -> V_133 = F_3 ( V_5 , V_6 ) ;
V_6 = V_103 + V_99 * V_104 ;
V_100 -> V_134 = F_3 ( V_5 , V_6 ) ;
if ( V_99 == 0 ) {
V_100 -> V_135 = F_3 ( V_5 , V_89 ) ;
V_100 -> V_136 = F_3 ( V_5 , V_40 ) ;
V_100 -> V_137 = F_3 ( V_5 , V_19 ) ;
V_100 -> V_138 = F_3 ( V_5 , V_50 ) ;
V_100 -> V_139 = F_3 ( V_5 , V_55 ) ;
F_4 ( V_5 , V_89 , 0xffffffff ) ;
}
}
F_23 ( & V_3 -> V_39 , V_38 ) ;
return 0 ;
}
static int F_76 ( struct V_117 * V_41 )
{
struct V_125 * V_126 = F_74 ( V_41 ) ;
struct V_4 * V_5 = F_72 ( V_126 ) ;
struct V_2 * V_3 = & V_5 -> V_7 [ 0 ] . V_3 ;
unsigned long V_38 ;
int V_70 ;
F_22 ( & V_3 -> V_39 , V_38 ) ;
for ( V_70 = 0 ; V_70 < V_5 -> V_115 ; V_70 ++ ) {
unsigned int V_6 ;
unsigned int V_99 = V_5 -> V_7 [ V_70 ] . V_99 ;
struct V_131 * V_100 = V_5 -> V_7 [ V_70 ] . V_100 ;
F_75 ( ! V_100 ) ;
V_6 = V_105 + V_99 * V_106 ;
F_4 ( V_5 , V_6 , V_100 -> V_133 ) ;
V_6 = V_107 + V_99 * V_108 ;
F_4 ( V_5 , V_6 , V_100 -> V_132 ) ;
V_6 = V_103 + V_99 * V_104 ;
F_4 ( V_5 , V_6 , V_100 -> V_134 ) ;
if ( V_99 == 0 ) {
F_4 ( V_5 , V_50 , V_100 -> V_138 ) ;
F_4 ( V_5 , V_19 , V_100 -> V_137 ) ;
F_4 ( V_5 , V_55 , V_100 -> V_139 ) ;
F_4 ( V_5 , V_40 , V_100 -> V_136 ) ;
F_4 ( V_5 , V_89 , V_100 -> V_135 ) ;
F_4 ( V_5 , V_88 , 0xffffffff ) ;
}
}
F_23 ( & V_3 -> V_39 , V_38 ) ;
return 0 ;
}
