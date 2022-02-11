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
static T_3 F_32 ( int V_54 , void * V_55 )
{
T_1 V_56 ;
struct V_1 * V_2 = V_55 ;
V_56 = F_9 ( V_2 ) ;
return V_56 ? V_57 : V_58 ;
}
static void F_33 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_59 * V_60 )
{
struct V_4 * V_5 = & V_13 -> V_5 ;
struct V_61 * V_62 = V_60 -> V_62 ;
struct V_33 * V_63 = NULL ;
unsigned int V_22 , V_64 = V_5 -> V_64 ;
struct V_65 * V_66 ;
int V_67 , V_68 ;
V_2 -> V_14 = F_34 ( V_62 , V_64 ,
& V_69 , V_2 ) ;
if ( ! V_2 -> V_14 )
return;
V_67 = F_35 ( V_2 -> V_14 , V_64 , 2 ,
L_2 , V_70 ,
V_71 , 0 ,
V_72 ) ;
if ( V_67 ) {
F_36 ( V_2 -> V_39 , L_3 ) ;
F_37 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
return;
}
V_63 = F_38 ( V_2 -> V_14 , 0 ) ;
if ( ! V_63 ) {
F_37 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
return;
}
V_63 -> V_7 = V_2 -> V_8 ;
V_63 -> V_35 = V_2 ;
for ( V_68 = 0 ; V_68 < 2 ; V_68 ++ ) {
V_66 = & V_63 -> V_73 [ V_68 ] ;
V_66 -> V_29 . V_74 = V_75 ;
V_66 -> V_29 . V_76 = V_77 ;
V_66 -> V_29 . V_78 = V_79 ;
V_66 -> V_29 . V_80 = F_29 ;
V_66 -> V_29 . V_81 = F_18 ;
V_66 -> V_29 . V_82 = F_22 ;
V_66 -> V_29 . V_83 = F_23 ;
V_66 -> V_29 . V_84 = F_27 ;
V_66 -> V_8 . V_85 = V_86 ;
V_66 -> V_8 . V_51 = V_87 ;
V_66 -> type = V_88 ;
}
V_63 -> V_73 [ 0 ] . type = V_88 ;
V_63 -> V_73 [ 1 ] . type = V_25 ;
V_63 -> V_73 [ 1 ] . V_89 = V_90 ;
if ( ! V_60 -> V_91 ) {
F_39 ( V_60 -> V_54 , F_14 ,
V_2 ) ;
} else {
V_67 = F_40 ( V_2 -> V_39 , V_60 -> V_54 ,
F_32 ,
V_92 , L_4 , V_2 ) ;
if ( V_67 ) {
F_26 ( V_2 -> V_39 , L_5 ) ;
F_37 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
return;
}
}
for ( V_22 = 0 ; V_22 < V_64 ; V_22 ++ )
F_41 ( V_2 -> V_14 , V_22 ) ;
V_13 -> V_5 . V_93 = F_3 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = & V_2 -> V_6 [ 0 ] ;
struct V_4 * V_5 = & V_13 -> V_5 ;
unsigned int V_64 = V_5 -> V_64 ;
T_4 V_22 ;
if ( ! V_2 -> V_14 )
return;
for ( V_22 = 0 ; V_22 < V_64 ; V_22 ++ )
F_43 ( F_5 ( V_2 -> V_14 , V_22 ) ) ;
F_37 ( V_2 -> V_14 ) ;
V_2 -> V_14 = NULL ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_59 * V_60 ,
unsigned int V_15 )
{
struct V_12 * V_13 ;
void T_2 * V_94 , * V_95 , * V_96 ;
int V_67 ;
V_13 = & V_2 -> V_6 [ V_15 ] ;
V_13 -> V_2 = V_2 ;
V_13 -> V_97 = V_60 -> V_97 ;
#ifdef F_45
V_13 -> V_98 = F_46 ( V_2 -> V_39 , sizeof( * V_13 -> V_98 ) , V_99 ) ;
if ( ! V_13 -> V_98 )
return - V_100 ;
#endif
V_94 = V_2 -> V_8 + V_101 + ( V_60 -> V_97 * V_102 ) ;
V_95 = V_2 -> V_8 + V_103 + ( V_60 -> V_97 * V_104 ) ;
V_96 = V_2 -> V_8 + V_105 +
( V_60 -> V_97 * V_106 ) ;
V_67 = F_47 ( & V_13 -> V_5 , V_2 -> V_39 , 4 , V_94 , V_95 , NULL , V_96 ,
NULL , false ) ;
if ( V_67 ) {
F_26 ( V_2 -> V_39 , L_6 ,
V_13 -> V_97 ) ;
return V_67 ;
}
#ifdef F_48
V_13 -> V_5 . V_107 = F_49 ( V_60 -> V_62 ) ;
#endif
V_13 -> V_5 . V_64 = V_60 -> V_64 ;
V_13 -> V_5 . V_18 = V_60 -> V_108 ;
if ( V_60 -> V_97 == 0 )
V_13 -> V_5 . V_109 = F_31 ;
if ( V_60 -> V_54 )
F_33 ( V_2 , V_13 , V_60 ) ;
V_67 = F_50 ( & V_13 -> V_5 , V_13 ) ;
if ( V_67 )
F_26 ( V_2 -> V_39 , L_7 ,
V_13 -> V_97 ) ;
else
V_13 -> V_110 = true ;
if ( V_60 -> V_54 )
F_51 ( & V_13 -> V_5 ) ;
return V_67 ;
}
static void F_52 ( struct V_1 * V_2 )
{
unsigned int V_111 ;
for ( V_111 = 0 ; V_111 < V_2 -> V_112 ; ++ V_111 )
if ( V_2 -> V_6 [ V_111 ] . V_110 )
F_53 ( & V_2 -> V_6 [ V_111 ] . V_5 ) ;
}
static struct V_113 *
F_54 ( struct V_114 * V_39 )
{
struct V_61 * V_62 ;
struct V_113 * V_115 ;
struct V_59 * V_60 ;
int V_116 ;
int V_68 ;
V_116 = F_55 ( V_39 ) ;
if ( V_116 == 0 )
return F_56 ( - V_117 ) ;
V_115 = F_46 ( V_39 , sizeof( * V_115 ) , V_99 ) ;
if ( ! V_115 )
return F_56 ( - V_100 ) ;
V_115 -> V_118 = F_57 ( V_39 , V_116 , sizeof( * V_60 ) , V_99 ) ;
if ( ! V_115 -> V_118 )
return F_56 ( - V_100 ) ;
V_115 -> V_116 = V_116 ;
V_68 = 0 ;
F_58 (dev, fwnode) {
V_60 = & V_115 -> V_118 [ V_68 ++ ] ;
V_60 -> V_62 = V_62 ;
if ( F_59 ( V_62 , L_8 , & V_60 -> V_97 ) ||
V_60 -> V_97 >= V_119 ) {
F_26 ( V_39 ,
L_9 , V_68 ) ;
return F_56 ( - V_40 ) ;
}
if ( F_59 ( V_62 , L_10 ,
& V_60 -> V_64 ) ) {
F_36 ( V_39 ,
L_11 ,
V_68 ) ;
V_60 -> V_64 = 32 ;
}
if ( V_39 -> V_107 && V_60 -> V_97 == 0 &&
F_60 ( V_62 ,
L_12 ) ) {
V_60 -> V_54 = F_61 ( F_49 ( V_62 ) , 0 ) ;
if ( ! V_60 -> V_54 )
F_62 ( V_39 , L_13 , V_60 -> V_97 ) ;
}
if ( F_63 ( V_39 ) && V_60 -> V_97 == 0 )
V_60 -> V_54 = F_64 ( F_65 ( V_39 ) , 0 ) ;
V_60 -> V_91 = false ;
V_60 -> V_108 = - 1 ;
}
return V_115 ;
}
static int F_66 ( struct V_120 * V_121 )
{
unsigned int V_68 ;
struct V_122 * V_123 ;
struct V_1 * V_2 ;
int V_67 ;
struct V_114 * V_39 = & V_121 -> V_39 ;
struct V_113 * V_115 = F_67 ( V_39 ) ;
if ( ! V_115 ) {
V_115 = F_54 ( V_39 ) ;
if ( F_68 ( V_115 ) )
return F_69 ( V_115 ) ;
}
if ( ! V_115 -> V_116 )
return - V_117 ;
V_2 = F_46 ( & V_121 -> V_39 , sizeof( * V_2 ) , V_99 ) ;
if ( ! V_2 )
return - V_100 ;
V_2 -> V_39 = & V_121 -> V_39 ;
V_2 -> V_112 = V_115 -> V_116 ;
V_2 -> V_6 = F_57 ( & V_121 -> V_39 , V_2 -> V_112 ,
sizeof( * V_2 -> V_6 ) , V_99 ) ;
if ( ! V_2 -> V_6 )
return - V_100 ;
V_123 = F_70 ( V_121 , V_124 , 0 ) ;
V_2 -> V_8 = F_71 ( & V_121 -> V_39 , V_123 ) ;
if ( F_68 ( V_2 -> V_8 ) )
return F_69 ( V_2 -> V_8 ) ;
for ( V_68 = 0 ; V_68 < V_2 -> V_112 ; V_68 ++ ) {
V_67 = F_44 ( V_2 , & V_115 -> V_118 [ V_68 ] , V_68 ) ;
if ( V_67 )
goto V_125;
}
F_72 ( V_121 , V_2 ) ;
return 0 ;
V_125:
F_52 ( V_2 ) ;
F_42 ( V_2 ) ;
return V_67 ;
}
static int F_73 ( struct V_120 * V_121 )
{
struct V_1 * V_2 = F_74 ( V_121 ) ;
F_52 ( V_2 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_114 * V_39 )
{
struct V_120 * V_121 = F_65 ( V_39 ) ;
struct V_1 * V_2 = F_74 ( V_121 ) ;
struct V_4 * V_5 = & V_2 -> V_6 [ 0 ] . V_5 ;
unsigned long V_36 ;
int V_68 ;
F_20 ( & V_5 -> V_37 , V_36 ) ;
for ( V_68 = 0 ; V_68 < V_2 -> V_112 ; V_68 ++ ) {
unsigned int V_3 ;
unsigned int V_97 = V_2 -> V_6 [ V_68 ] . V_97 ;
struct V_126 * V_98 = V_2 -> V_6 [ V_68 ] . V_98 ;
F_76 ( ! V_98 ) ;
V_3 = V_105 + V_97 * V_106 ;
V_98 -> V_127 = F_1 ( V_2 , V_3 ) ;
V_3 = V_103 + V_97 * V_104 ;
V_98 -> V_128 = F_1 ( V_2 , V_3 ) ;
V_3 = V_101 + V_97 * V_102 ;
V_98 -> V_129 = F_1 ( V_2 , V_3 ) ;
if ( V_97 == 0 ) {
V_98 -> V_130 = F_1 ( V_2 , V_87 ) ;
V_98 -> V_131 = F_1 ( V_2 , V_38 ) ;
V_98 -> V_132 = F_1 ( V_2 , V_17 ) ;
V_98 -> V_133 = F_1 ( V_2 , V_48 ) ;
V_98 -> V_134 = F_1 ( V_2 , V_53 ) ;
F_2 ( V_2 , V_87 , 0xffffffff ) ;
}
}
F_21 ( & V_5 -> V_37 , V_36 ) ;
return 0 ;
}
static int F_77 ( struct V_114 * V_39 )
{
struct V_120 * V_121 = F_65 ( V_39 ) ;
struct V_1 * V_2 = F_74 ( V_121 ) ;
struct V_4 * V_5 = & V_2 -> V_6 [ 0 ] . V_5 ;
unsigned long V_36 ;
int V_68 ;
F_20 ( & V_5 -> V_37 , V_36 ) ;
for ( V_68 = 0 ; V_68 < V_2 -> V_112 ; V_68 ++ ) {
unsigned int V_3 ;
unsigned int V_97 = V_2 -> V_6 [ V_68 ] . V_97 ;
struct V_126 * V_98 = V_2 -> V_6 [ V_68 ] . V_98 ;
F_76 ( ! V_98 ) ;
V_3 = V_103 + V_97 * V_104 ;
F_2 ( V_2 , V_3 , V_98 -> V_128 ) ;
V_3 = V_105 + V_97 * V_106 ;
F_2 ( V_2 , V_3 , V_98 -> V_127 ) ;
V_3 = V_101 + V_97 * V_102 ;
F_2 ( V_2 , V_3 , V_98 -> V_129 ) ;
if ( V_97 == 0 ) {
F_2 ( V_2 , V_48 , V_98 -> V_133 ) ;
F_2 ( V_2 , V_17 , V_98 -> V_132 ) ;
F_2 ( V_2 , V_53 , V_98 -> V_134 ) ;
F_2 ( V_2 , V_38 , V_98 -> V_131 ) ;
F_2 ( V_2 , V_87 , V_98 -> V_130 ) ;
F_2 ( V_2 , V_86 , 0xffffffff ) ;
}
}
F_21 ( & V_5 -> V_37 , V_36 ) ;
return 0 ;
}
