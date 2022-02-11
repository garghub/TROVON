static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ )
if ( V_3 == V_2 -> V_6 [ V_4 ] . V_7 )
break;
if ( V_4 >= V_2 -> V_5 )
return - V_8 ;
return V_4 ;
}
static int F_2 ( unsigned long V_9 , enum V_10 V_11 )
{
int V_4 ;
if ( V_9 < V_12 [ 0 ] [ 0 ] )
return - V_8 ;
for ( V_4 = 0 ; V_4 < V_13 ; V_4 ++ ) {
if ( V_9 >= V_12 [ V_4 ] [ 0 ] &&
V_9 < V_12 [ V_4 ] [ 1 ] )
return V_14 [ V_11 ] [ V_4 ] ;
}
return - V_8 ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_4 ;
const struct V_15 * V_16 = V_2 -> V_16 ;
for ( V_4 = 0 ; V_4 < V_17 ; V_4 ++ ) {
T_1 V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_20 . V_21 ) ;
if ( V_18 & ( 1 << V_16 -> V_20 . V_22 ) )
return 0 ;
F_5 ( 10 ) ;
}
return - V_23 ;
}
static void F_6 ( const struct V_1 * V_2 , void T_2 * V_24 ,
const T_1 V_21 , T_1 V_18 )
{
const struct V_15 * V_16 = V_2 -> V_16 ;
F_7 ( V_18 , V_24 + V_21 ) ;
if ( F_8 ( V_16 -> V_25 & V_26 &&
( V_24 == V_2 -> V_19 || V_24 == V_2 -> V_27 ) ) )
V_18 = F_4 ( V_24 + V_21 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 = V_2 -> V_16 ;
T_1 V_18 ;
if ( V_16 -> V_25 & V_28 ) {
V_18 = F_4 ( V_2 -> V_29 + V_16 -> V_30 . V_21 ) ;
V_18 &= ~ ( 1 << V_16 -> V_30 . V_31 ) ;
F_6 ( V_2 , V_2 -> V_29 , V_16 -> V_30 . V_21 , V_18 ) ;
}
if ( V_16 -> V_25 & V_32 ) {
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_33 . V_21 ) ;
V_18 |= F_10 ( V_16 -> V_33 . V_34 ) << V_16 -> V_33 . V_35 ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_33 . V_21 , V_18 ) ;
}
if ( V_2 -> V_36 ) {
V_18 = F_4 ( V_2 -> V_36 + V_16 -> V_33 . V_21 ) ;
V_18 |= 1 << V_16 -> V_33 . V_37 ;
F_6 ( V_2 , V_2 -> V_36 , V_16 -> V_33 . V_21 , V_18 ) ;
V_18 &= ~ ( F_10 ( V_16 -> V_33 . V_34 ) << V_16 -> V_33 . V_35 ) ;
F_6 ( V_2 , V_2 -> V_36 , V_16 -> V_33 . V_21 , V_18 ) ;
}
}
static int F_11 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 = V_2 -> V_16 ;
T_1 V_18 ;
if ( V_16 -> V_25 & V_32 ) {
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_33 . V_21 ) ;
V_18 &= ~ ( F_10 ( V_16 -> V_33 . V_34 ) << V_16 -> V_33 . V_35 ) ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_33 . V_21 , V_18 ) ;
}
if ( V_2 -> V_36 ) {
V_18 = F_4 ( V_2 -> V_36 + V_16 -> V_33 . V_21 ) ;
V_18 |= F_10 ( V_16 -> V_33 . V_34 ) << V_16 -> V_33 . V_35 ;
V_18 &= ~ ( 1 << V_16 -> V_33 . V_37 ) ;
F_6 ( V_2 , V_2 -> V_36 , V_16 -> V_33 . V_21 , V_18 ) ;
}
if ( V_16 -> V_25 & V_28 ) {
V_18 = F_4 ( V_2 -> V_29 + V_16 -> V_30 . V_21 ) ;
V_18 |= ( 1 << V_16 -> V_30 . V_31 ) ;
F_6 ( V_2 , V_2 -> V_29 , V_16 -> V_30 . V_21 , V_18 ) ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
T_1 V_18 ;
const struct V_15 * V_16 = V_2 -> V_16 ;
const struct V_38 * V_39 = & V_16 -> V_39 ;
V_18 = F_4 ( V_2 -> V_27 + V_39 -> V_21 ) ;
V_18 &= ~ ( 1 << V_39 -> V_40 | 1 << V_39 -> V_41 ) ;
F_6 ( V_2 , V_2 -> V_27 , V_39 -> V_21 , V_18 ) ;
}
static void F_13 ( struct V_1 * V_2 , unsigned int V_42 ,
unsigned int V_43 , unsigned int V_44 )
{
T_1 V_18 ;
const struct V_15 * V_16 = V_2 -> V_16 ;
const struct V_38 * V_39 = & V_16 -> V_39 ;
const struct V_45 * V_46 = & V_16 -> V_46 ;
V_18 = F_4 ( V_2 -> V_27 + V_46 -> V_21 ) ;
V_18 &= ~ ( F_10 ( V_46 -> V_47 ) << V_46 -> V_48 |
F_10 ( V_46 -> V_49 ) << V_46 -> V_50 |
F_10 ( V_46 -> V_51 ) << V_46 -> V_52 ) ;
V_18 |= V_44 << V_46 -> V_48 | V_42 << V_46 -> V_50 |
V_43 << V_46 -> V_52 ;
F_6 ( V_2 , V_2 -> V_27 , V_46 -> V_21 , V_18 ) ;
V_18 = F_4 ( V_2 -> V_27 + V_39 -> V_21 ) ;
V_18 |= 1 << V_39 -> V_40 | 1 << V_39 -> V_41 ;
F_6 ( V_2 , V_2 -> V_27 , V_39 -> V_21 , V_18 ) ;
}
static int F_14 ( struct V_53 * V_54 , unsigned int V_55 ,
unsigned long V_56 )
{
struct V_1 * V_2 = V_54 -> V_2 ;
const struct V_57 * V_58 = & V_2 -> V_6 [ V_55 ] ;
const struct V_15 * V_16 = V_2 -> V_16 ;
int V_43 = 0 , V_44 , V_42 , V_59 ;
unsigned long V_7 = V_58 -> V_7 ;
T_1 V_18 ;
enum V_10 V_11 ;
unsigned long V_9 ;
if ( V_58 -> V_60 == 0 )
V_9 = V_56 * 2 ;
else
V_9 = V_56 / V_58 -> V_60 ;
if ( V_7 >= V_61 && V_7 < V_62 ) {
V_44 = 4 ;
V_11 = V_63 ;
} else if ( V_7 >= V_62 && V_7 && V_7 < V_64 ) {
V_44 = 3 ;
V_11 = V_65 ;
} else if ( V_7 >= V_64 && V_7 < V_66 ) {
V_44 = 3 ;
V_11 = V_67 ;
} else {
F_15 ( L_1 , V_68 ,
V_54 -> V_69 , V_7 ) ;
return - V_8 ;
}
V_42 = F_2 ( V_9 , V_11 ) ;
if ( V_42 < 0 ) {
F_15 ( L_2 , V_68 , V_54 -> V_69 ) ;
return V_42 ;
}
V_59 = F_11 ( V_2 ) ;
if ( V_59 ) {
F_15 ( L_3 , V_68 , V_54 -> V_69 ) ;
return V_59 ;
}
F_12 ( V_2 ) ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_70 . V_71 , 0 ) ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_70 . V_72 ) ;
if ( V_7 >= V_61 && V_7 < V_73 )
V_18 |= ( 1 << V_74 ) ;
if ( V_7 < V_62 )
V_18 &= ~ ( 1 << V_75 ) ;
else
V_18 |= ( 1 << V_75 ) ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_70 . V_72 , V_18 ) ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_76 . V_21 ) ;
V_18 &= ~ ( F_10 ( V_16 -> V_76 . V_77 ) << V_16 -> V_76 . V_22 ) ;
V_18 |= V_58 -> V_76 << V_16 -> V_76 . V_22 ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_76 . V_21 , V_18 ) ;
if ( V_16 -> V_25 & V_78 ) {
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_79 . V_21 ) ;
V_18 &= ~ ( F_10 ( V_16 -> V_79 . V_77 ) <<
V_16 -> V_79 . V_22 ) ;
V_18 |= V_58 -> V_79 << V_16 -> V_79 . V_22 ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_79 . V_21 ,
V_18 ) ;
}
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_60 . V_21 ) ;
V_18 &= ~ ( F_10 ( V_16 -> V_60 . V_77 ) << V_16 -> V_60 . V_22 ) ;
V_18 |= V_58 -> V_60 << V_16 -> V_60 . V_22 ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_60 . V_21 , V_18 ) ;
F_13 ( V_2 , V_42 , V_43 , V_44 ) ;
V_59 = F_3 ( V_2 ) ;
if ( V_59 < 0 ) {
F_15 ( L_4 , V_68 , V_54 -> V_69 ) ;
return V_59 ;
}
return 0 ;
}
static int F_16 ( struct V_80 * V_81 )
{
struct V_53 * V_54 = F_17 ( V_81 ) ;
struct V_1 * V_2 = V_54 -> V_2 ;
return F_11 ( V_2 ) ;
}
static void F_18 ( struct V_80 * V_81 )
{
struct V_53 * V_54 = F_17 ( V_81 ) ;
struct V_1 * V_2 = V_54 -> V_2 ;
const struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_25 & V_82 )
return;
F_9 ( V_2 ) ;
}
static unsigned long F_19 ( struct V_80 * V_81 ,
unsigned long V_56 )
{
struct V_53 * V_54 = F_17 ( V_81 ) ;
struct V_1 * V_2 = V_54 -> V_2 ;
const struct V_15 * V_16 = V_2 -> V_16 ;
T_1 V_18 ;
T_3 V_83 , V_76 , V_79 ;
unsigned int V_60 ;
if ( V_56 == 0 )
return 0 ;
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_20 . V_21 ) ;
if ( ( V_18 & ( 1 << V_16 -> V_20 . V_22 ) ) == 0 ) {
V_54 -> V_7 = 0 ;
return 0 ;
}
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_76 . V_21 ) ;
V_76 = ( V_18 >> V_16 -> V_76 . V_22 ) &
F_10 ( V_16 -> V_76 . V_77 ) ;
V_83 = V_76 << 20 ;
if ( V_16 -> V_25 & V_78 ) {
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_79 . V_21 ) ;
V_79 = ( V_18 >> V_16 -> V_79 . V_22 ) &
F_10 ( V_16 -> V_79 . V_77 ) ;
V_83 += V_79 ;
}
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_60 . V_21 ) ;
V_60 = ( V_18 >> V_16 -> V_60 . V_22 ) & F_10 ( V_16 -> V_60 . V_77 ) ;
V_54 -> V_7 = ( V_83 * V_56 ) >> 20 ;
if ( V_60 == 0 )
V_54 -> V_7 *= 2 ;
else
V_54 -> V_7 /= V_60 ;
return V_54 -> V_7 ;
}
static long F_20 ( struct V_80 * V_81 , unsigned long V_7 ,
unsigned long * V_56 )
{
unsigned V_4 ;
struct V_53 * V_54 = F_17 ( V_81 ) ;
struct V_1 * V_2 = V_54 -> V_2 ;
if ( V_7 == 0 || * V_56 == 0 || ! V_2 -> V_6 )
return - V_8 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
if ( V_7 <= V_2 -> V_6 [ V_4 ] . V_7 )
break;
}
if ( V_4 == V_2 -> V_5 )
V_4 -- ;
return V_2 -> V_6 [ V_4 ] . V_7 ;
}
static int F_21 ( struct V_80 * V_81 , unsigned long V_7 ,
unsigned long V_56 )
{
struct V_53 * V_54 = F_17 ( V_81 ) ;
struct V_1 * V_2 = V_54 -> V_2 ;
int V_55 , V_59 ;
V_55 = F_1 ( V_2 , V_7 ) ;
if ( V_55 < 0 )
return V_55 ;
V_59 = F_14 ( V_54 , V_55 , V_56 ) ;
return V_59 ;
}
static int F_22 ( struct V_80 * V_81 )
{
struct V_53 * V_54 = F_17 ( V_81 ) ;
const struct V_84 * V_16 = V_54 -> V_16 ;
struct V_1 * V_2 = V_54 -> V_2 ;
T_1 V_18 ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_85 . V_21 ) ;
V_18 &= ~ ( 1 << V_16 -> V_85 . V_86 ) ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_85 . V_21 , V_18 ) ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_85 . V_21 ) ;
V_18 &= ~ ( 1 << V_16 -> V_85 . V_87 ) ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_85 . V_21 , V_18 ) ;
return 0 ;
}
static void F_23 ( struct V_80 * V_81 )
{
struct V_53 * V_54 = F_17 ( V_81 ) ;
const struct V_84 * V_16 = V_54 -> V_16 ;
struct V_1 * V_2 = V_54 -> V_2 ;
T_1 V_18 ;
if ( V_16 -> V_25 & V_82 )
return;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_85 . V_21 ) ;
V_18 |= 1 << V_16 -> V_85 . V_86 ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_85 . V_21 , V_18 ) ;
}
static unsigned long F_24 ( struct V_80 * V_81 ,
unsigned long V_56 )
{
struct V_53 * V_54 = F_17 ( V_81 ) ;
const struct V_84 * V_16 = V_54 -> V_16 ;
struct V_1 * V_2 = V_54 -> V_2 ;
T_1 V_18 ;
unsigned int V_88 ;
if ( V_56 == 0 )
return 0 ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_88 . V_21 ) ;
V_88 = ( V_18 >> V_16 -> V_88 . V_22 ) & F_10 ( V_16 -> V_88 . V_77 ) ;
if ( V_88 == 0 )
V_88 = 256 ;
V_54 -> V_7 = V_56 / V_88 ;
return V_54 -> V_7 ;
}
static long F_25 ( struct V_80 * V_81 , unsigned long V_7 ,
unsigned long * V_56 )
{
unsigned int div ;
if ( V_7 == 0 || * V_56 == 0 )
return - V_8 ;
if ( V_7 == * V_56 )
return * V_56 ;
div = F_26 ( * V_56 , V_7 ) ;
if ( div < 2 )
return * V_56 ;
if ( div > 256 )
div = 256 ;
return * V_56 / div ;
}
static int F_27 ( struct V_80 * V_81 , unsigned long V_7 ,
unsigned long V_56 )
{
struct V_53 * V_54 = F_17 ( V_81 ) ;
const struct V_84 * V_16 = V_54 -> V_16 ;
struct V_1 * V_2 = V_54 -> V_2 ;
T_1 V_18 ;
unsigned int div ;
if ( V_7 == 0 || V_56 == 0 )
return - V_8 ;
div = F_26 ( V_56 , V_7 ) ;
if ( div > 256 )
return - V_8 ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_88 . V_21 ) ;
if ( div == 256 ) {
V_18 &= ~ ( F_10 ( V_16 -> V_88 . V_77 ) << V_16 -> V_88 . V_22 ) ;
} else {
V_18 &= ~ ( F_10 ( V_16 -> V_88 . V_77 ) << V_16 -> V_88 . V_22 ) ;
V_18 |= div << V_16 -> V_88 . V_22 ;
}
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_88 . V_21 , V_18 ) ;
V_54 -> V_7 = V_56 / div ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_25 & V_89 ) {
T_1 V_18 ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_90 . V_21 ) ;
V_18 |= F_29 ( V_16 -> V_90 . V_22 ) ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_90 . V_21 ,
V_18 ) ;
}
}
void T_4 F_30 ( struct V_91 * V_92 ,
const struct V_15 * V_93 ,
const struct V_57 * V_58 ,
unsigned int V_5 ,
const struct V_84 * V_94 ,
unsigned int V_95 )
{
int V_4 , V_59 ;
struct V_54 * V_54 ;
struct V_1 * V_2 ;
struct V_53 * V_96 ;
struct V_97 V_98 ;
const char * V_99 ;
if ( F_31 ( ! V_93 ) || F_31 ( ! V_94 ) )
return;
V_2 = F_32 ( sizeof( * V_2 ) , V_100 ) ;
if ( F_31 ( ! V_2 ) )
return;
V_2 -> V_101 . V_102 = V_95 ;
V_2 -> V_101 . V_103 = F_33 ( V_95 , sizeof( * V_2 -> V_101 . V_103 ) ,
V_100 ) ;
if ( F_31 ( ! V_2 -> V_101 . V_103 ) )
goto V_104;
V_2 -> V_103 = F_33 ( V_95 , sizeof( * V_2 -> V_103 ) , V_100 ) ;
if ( F_31 ( ! V_2 -> V_103 ) )
goto V_105;
V_2 -> V_27 = F_34 ( V_92 , 0 ) ;
if ( F_31 ( ! V_2 -> V_27 ) )
goto V_106;
V_2 -> V_36 = F_34 ( V_92 , 1 ) ;
if ( V_93 -> V_25 & V_28 ) {
V_2 -> V_29 = F_34 ( V_92 , 2 ) ;
if ( F_31 ( ! V_2 -> V_29 ) )
goto V_107;
}
if ( V_93 -> V_25 & V_108 ) {
V_2 -> V_19 = F_34 ( V_92 , 2 ) ;
if ( ! V_2 -> V_19 )
goto V_109;
} else
V_2 -> V_19 = V_2 -> V_27 ;
V_2 -> V_16 = V_93 ;
V_96 = & V_2 -> V_103 [ 0 ] ;
V_96 -> V_2 = V_2 ;
V_96 -> V_69 = V_92 -> V_69 ;
V_98 . V_69 = V_92 -> V_69 ;
V_98 . V_110 = & V_111 ;
V_98 . V_25 = 0 ;
V_99 = F_35 ( V_92 , 0 ) ;
V_98 . V_112 = ( V_99 ? & V_99 : NULL ) ;
V_98 . V_113 = ( V_99 ? 1 : 0 ) ;
V_96 -> V_81 . V_98 = & V_98 ;
if ( V_58 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_58 ;
}
F_28 ( V_2 ) ;
V_54 = F_36 ( NULL , & V_96 -> V_81 ) ;
if ( F_31 ( F_37 ( V_54 ) ) )
goto V_114;
V_2 -> V_101 . V_103 [ 0 ] = V_54 ;
for ( V_4 = 1 ; V_4 < V_95 ; V_4 ++ ) {
const char * V_115 ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_99 = V_92 -> V_69 ;
V_59 = F_38 ( V_92 , L_5 ,
V_4 , & V_115 ) ;
if ( F_31 ( V_59 ) )
goto V_116;
V_96 = & V_2 -> V_103 [ V_4 ] ;
V_96 -> V_69 = V_115 ;
V_96 -> V_2 = V_2 ;
V_96 -> V_16 = & V_94 [ V_4 ] ;
V_98 . V_69 = V_115 ;
V_98 . V_110 = & V_117 ;
V_98 . V_25 = 0 ;
V_98 . V_112 = ( V_99 ? & V_99 : NULL ) ;
V_98 . V_113 = ( V_99 ? 1 : 0 ) ;
V_96 -> V_81 . V_98 = & V_98 ;
V_54 = F_36 ( NULL , & V_96 -> V_81 ) ;
if ( F_31 ( F_37 ( V_54 ) ) )
goto V_116;
V_2 -> V_101 . V_103 [ V_4 ] = V_54 ;
}
V_59 = F_39 ( V_92 , V_118 , & V_2 -> V_101 ) ;
if ( F_31 ( V_59 ) )
goto V_116;
return;
V_116:
for ( V_4 = 0 ; V_4 < V_95 ; V_4 ++ )
F_40 ( V_2 -> V_101 . V_103 [ V_4 ] ) ;
V_114:
if ( V_2 -> V_19 != V_2 -> V_27 )
F_41 ( V_2 -> V_19 ) ;
V_109:
if ( V_2 -> V_29 )
F_41 ( V_2 -> V_29 ) ;
V_107:
if ( V_2 -> V_36 )
F_41 ( V_2 -> V_36 ) ;
F_41 ( V_2 -> V_27 ) ;
V_106:
F_42 ( V_2 -> V_103 ) ;
V_105:
F_42 ( V_2 -> V_101 . V_103 ) ;
V_104:
F_42 ( V_2 ) ;
}
