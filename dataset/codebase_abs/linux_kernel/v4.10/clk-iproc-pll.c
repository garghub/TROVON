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
if ( V_16 -> V_25 & V_40 )
V_18 |= F_13 ( V_39 -> V_41 ) | F_13 ( V_39 -> V_42 ) ;
else
V_18 &= ~ ( F_13 ( V_39 -> V_41 ) | F_13 ( V_39 -> V_42 ) ) ;
F_6 ( V_2 , V_2 -> V_27 , V_39 -> V_21 , V_18 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_43 ,
unsigned int V_44 , unsigned int V_45 )
{
T_1 V_18 ;
const struct V_15 * V_16 = V_2 -> V_16 ;
const struct V_38 * V_39 = & V_16 -> V_39 ;
const struct V_46 * V_47 = & V_16 -> V_47 ;
V_18 = F_4 ( V_2 -> V_27 + V_47 -> V_21 ) ;
V_18 &= ~ ( F_10 ( V_47 -> V_48 ) << V_47 -> V_49 |
F_10 ( V_47 -> V_50 ) << V_47 -> V_51 |
F_10 ( V_47 -> V_52 ) << V_47 -> V_53 ) ;
V_18 |= V_45 << V_47 -> V_49 | V_43 << V_47 -> V_51 |
V_44 << V_47 -> V_53 ;
F_6 ( V_2 , V_2 -> V_27 , V_47 -> V_21 , V_18 ) ;
V_18 = F_4 ( V_2 -> V_27 + V_39 -> V_21 ) ;
if ( V_16 -> V_25 & V_40 )
V_18 &= ~ ( F_13 ( V_39 -> V_41 ) | F_13 ( V_39 -> V_42 ) ) ;
else
V_18 |= F_13 ( V_39 -> V_41 ) | F_13 ( V_39 -> V_42 ) ;
F_6 ( V_2 , V_2 -> V_27 , V_39 -> V_21 , V_18 ) ;
}
static int F_15 ( struct V_54 * V_55 , unsigned int V_56 ,
unsigned long V_57 )
{
struct V_1 * V_2 = V_55 -> V_2 ;
const struct V_58 * V_59 = & V_2 -> V_6 [ V_56 ] ;
const struct V_15 * V_16 = V_2 -> V_16 ;
int V_44 = 0 , V_45 , V_43 , V_60 ;
unsigned long V_7 = V_59 -> V_7 ;
T_1 V_18 ;
enum V_10 V_11 ;
unsigned long V_9 ;
if ( V_59 -> V_61 == 0 )
V_9 = V_57 * 2 ;
else
V_9 = V_57 / V_59 -> V_61 ;
if ( V_7 >= V_62 && V_7 < V_63 ) {
V_45 = 4 ;
V_11 = V_64 ;
} else if ( V_7 >= V_63 && V_7 && V_7 < V_65 ) {
V_45 = 3 ;
V_11 = V_66 ;
} else if ( V_7 >= V_65 && V_7 < V_67 ) {
V_45 = 3 ;
V_11 = V_68 ;
} else {
F_16 ( L_1 , V_69 ,
V_55 -> V_70 , V_7 ) ;
return - V_8 ;
}
V_43 = F_2 ( V_9 , V_11 ) ;
if ( V_43 < 0 ) {
F_16 ( L_2 , V_69 , V_55 -> V_70 ) ;
return V_43 ;
}
V_60 = F_11 ( V_2 ) ;
if ( V_60 ) {
F_16 ( L_3 , V_69 , V_55 -> V_70 ) ;
return V_60 ;
}
F_12 ( V_2 ) ;
if ( V_16 -> V_25 & V_71 ) {
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_72 . V_21 ) ;
V_18 &= ~ ( F_10 ( V_16 -> V_72 . V_73 ) <<
V_16 -> V_72 . V_22 ) ;
V_18 |= V_74 << V_16 -> V_72 . V_22 ;
F_6 ( V_2 , V_2 -> V_27 ,
V_16 -> V_72 . V_21 , V_18 ) ;
}
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_75 . V_76 , 0 ) ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_75 . V_77 ) ;
if ( V_7 >= V_62 && V_7 < V_78 )
V_18 |= ( 1 << V_79 ) ;
if ( V_7 < V_63 )
V_18 &= ~ ( 1 << V_80 ) ;
else
V_18 |= ( 1 << V_80 ) ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_75 . V_77 , V_18 ) ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_81 . V_21 ) ;
V_18 &= ~ ( F_10 ( V_16 -> V_81 . V_73 ) << V_16 -> V_81 . V_22 ) ;
V_18 |= V_59 -> V_81 << V_16 -> V_81 . V_22 ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_81 . V_21 , V_18 ) ;
if ( V_16 -> V_25 & V_82 ) {
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_83 . V_21 ) ;
V_18 &= ~ ( F_10 ( V_16 -> V_83 . V_73 ) <<
V_16 -> V_83 . V_22 ) ;
V_18 |= V_59 -> V_83 << V_16 -> V_83 . V_22 ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_83 . V_21 ,
V_18 ) ;
}
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_61 . V_21 ) ;
V_18 &= ~ ( F_10 ( V_16 -> V_61 . V_73 ) << V_16 -> V_61 . V_22 ) ;
V_18 |= V_59 -> V_61 << V_16 -> V_61 . V_22 ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_61 . V_21 , V_18 ) ;
F_14 ( V_2 , V_43 , V_44 , V_45 ) ;
V_60 = F_3 ( V_2 ) ;
if ( V_60 < 0 ) {
F_16 ( L_4 , V_69 , V_55 -> V_70 ) ;
return V_60 ;
}
return 0 ;
}
static int F_17 ( struct V_84 * V_85 )
{
struct V_54 * V_55 = F_18 ( V_85 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
return F_11 ( V_2 ) ;
}
static void F_19 ( struct V_84 * V_85 )
{
struct V_54 * V_55 = F_18 ( V_85 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
const struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_25 & V_86 )
return;
F_9 ( V_2 ) ;
}
static unsigned long F_20 ( struct V_84 * V_85 ,
unsigned long V_57 )
{
struct V_54 * V_55 = F_18 ( V_85 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
const struct V_15 * V_16 = V_2 -> V_16 ;
T_1 V_18 ;
T_3 V_87 , V_81 , V_83 ;
unsigned int V_61 ;
if ( V_57 == 0 )
return 0 ;
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_20 . V_21 ) ;
if ( ( V_18 & ( 1 << V_16 -> V_20 . V_22 ) ) == 0 ) {
V_55 -> V_7 = 0 ;
return 0 ;
}
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_81 . V_21 ) ;
V_81 = ( V_18 >> V_16 -> V_81 . V_22 ) &
F_10 ( V_16 -> V_81 . V_73 ) ;
V_87 = V_81 << 20 ;
if ( V_16 -> V_25 & V_82 ) {
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_83 . V_21 ) ;
V_83 = ( V_18 >> V_16 -> V_83 . V_22 ) &
F_10 ( V_16 -> V_83 . V_73 ) ;
V_87 += V_83 ;
}
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_61 . V_21 ) ;
V_61 = ( V_18 >> V_16 -> V_61 . V_22 ) & F_10 ( V_16 -> V_61 . V_73 ) ;
V_55 -> V_7 = ( V_87 * V_57 ) >> 20 ;
if ( V_61 == 0 )
V_55 -> V_7 *= 2 ;
else
V_55 -> V_7 /= V_61 ;
return V_55 -> V_7 ;
}
static long F_21 ( struct V_84 * V_85 , unsigned long V_7 ,
unsigned long * V_57 )
{
unsigned V_4 ;
struct V_54 * V_55 = F_18 ( V_85 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
if ( V_7 == 0 || * V_57 == 0 || ! V_2 -> V_6 )
return - V_8 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
if ( V_7 <= V_2 -> V_6 [ V_4 ] . V_7 )
break;
}
if ( V_4 == V_2 -> V_5 )
V_4 -- ;
return V_2 -> V_6 [ V_4 ] . V_7 ;
}
static int F_22 ( struct V_84 * V_85 , unsigned long V_7 ,
unsigned long V_57 )
{
struct V_54 * V_55 = F_18 ( V_85 ) ;
struct V_1 * V_2 = V_55 -> V_2 ;
int V_56 , V_60 ;
V_56 = F_1 ( V_2 , V_7 ) ;
if ( V_56 < 0 )
return V_56 ;
V_60 = F_15 ( V_55 , V_56 , V_57 ) ;
return V_60 ;
}
static int F_23 ( struct V_84 * V_85 )
{
struct V_54 * V_55 = F_18 ( V_85 ) ;
const struct V_88 * V_16 = V_55 -> V_16 ;
struct V_1 * V_2 = V_55 -> V_2 ;
T_1 V_18 ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_89 . V_21 ) ;
V_18 &= ~ ( 1 << V_16 -> V_89 . V_90 ) ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_89 . V_21 , V_18 ) ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_89 . V_21 ) ;
V_18 &= ~ ( 1 << V_16 -> V_89 . V_91 ) ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_89 . V_21 , V_18 ) ;
return 0 ;
}
static void F_24 ( struct V_84 * V_85 )
{
struct V_54 * V_55 = F_18 ( V_85 ) ;
const struct V_88 * V_16 = V_55 -> V_16 ;
struct V_1 * V_2 = V_55 -> V_2 ;
T_1 V_18 ;
if ( V_16 -> V_25 & V_86 )
return;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_89 . V_21 ) ;
V_18 |= 1 << V_16 -> V_89 . V_90 ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_89 . V_21 , V_18 ) ;
}
static unsigned long F_25 ( struct V_84 * V_85 ,
unsigned long V_57 )
{
struct V_54 * V_55 = F_18 ( V_85 ) ;
const struct V_88 * V_16 = V_55 -> V_16 ;
struct V_1 * V_2 = V_55 -> V_2 ;
T_1 V_18 ;
unsigned int V_92 ;
if ( V_57 == 0 )
return 0 ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_92 . V_21 ) ;
V_92 = ( V_18 >> V_16 -> V_92 . V_22 ) & F_10 ( V_16 -> V_92 . V_73 ) ;
if ( V_92 == 0 )
V_92 = 256 ;
if ( V_16 -> V_25 & V_93 )
V_55 -> V_7 = V_57 / ( V_92 * 2 ) ;
else
V_55 -> V_7 = V_57 / V_92 ;
return V_55 -> V_7 ;
}
static long F_26 ( struct V_84 * V_85 , unsigned long V_7 ,
unsigned long * V_57 )
{
unsigned int div ;
if ( V_7 == 0 || * V_57 == 0 )
return - V_8 ;
if ( V_7 == * V_57 )
return * V_57 ;
div = F_27 ( * V_57 , V_7 ) ;
if ( div < 2 )
return * V_57 ;
if ( div > 256 )
div = 256 ;
return * V_57 / div ;
}
static int F_28 ( struct V_84 * V_85 , unsigned long V_7 ,
unsigned long V_57 )
{
struct V_54 * V_55 = F_18 ( V_85 ) ;
const struct V_88 * V_16 = V_55 -> V_16 ;
struct V_1 * V_2 = V_55 -> V_2 ;
T_1 V_18 ;
unsigned int div ;
if ( V_7 == 0 || V_57 == 0 )
return - V_8 ;
if ( V_16 -> V_25 & V_93 )
div = F_27 ( V_57 , V_7 * 2 ) ;
else
div = F_27 ( V_57 , V_7 ) ;
if ( div > 256 )
return - V_8 ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_92 . V_21 ) ;
if ( div == 256 ) {
V_18 &= ~ ( F_10 ( V_16 -> V_92 . V_73 ) << V_16 -> V_92 . V_22 ) ;
} else {
V_18 &= ~ ( F_10 ( V_16 -> V_92 . V_73 ) << V_16 -> V_92 . V_22 ) ;
V_18 |= div << V_16 -> V_92 . V_22 ;
}
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_92 . V_21 , V_18 ) ;
if ( V_16 -> V_25 & V_93 )
V_55 -> V_7 = V_57 / ( div * 2 ) ;
else
V_55 -> V_7 = V_57 / div ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_25 & V_94 ) {
T_1 V_18 ;
V_18 = F_4 ( V_2 -> V_27 + V_16 -> V_95 . V_21 ) ;
V_18 |= F_13 ( V_16 -> V_95 . V_22 ) ;
F_6 ( V_2 , V_2 -> V_27 , V_16 -> V_95 . V_21 ,
V_18 ) ;
}
}
void T_4 F_30 ( struct V_96 * V_97 ,
const struct V_15 * V_98 ,
const struct V_58 * V_59 ,
unsigned int V_5 ,
const struct V_88 * V_99 ,
unsigned int V_100 )
{
int V_4 , V_60 ;
struct V_1 * V_2 ;
struct V_54 * V_101 ;
struct V_102 V_103 ;
const char * V_104 ;
if ( F_31 ( ! V_98 ) || F_31 ( ! V_99 ) )
return;
V_2 = F_32 ( sizeof( * V_2 ) , V_105 ) ;
if ( F_31 ( ! V_2 ) )
return;
V_2 -> V_106 = F_32 ( sizeof( * V_2 -> V_106 -> V_107 ) * V_100 +
sizeof( * V_2 -> V_106 ) , V_105 ) ;
if ( F_31 ( ! V_2 -> V_106 ) )
goto V_108;
V_2 -> V_106 -> V_109 = V_100 ;
V_2 -> V_110 = F_33 ( V_100 , sizeof( * V_2 -> V_110 ) , V_105 ) ;
if ( F_31 ( ! V_2 -> V_110 ) )
goto V_111;
V_2 -> V_27 = F_34 ( V_97 , 0 ) ;
if ( F_31 ( ! V_2 -> V_27 ) )
goto V_112;
V_2 -> V_36 = F_34 ( V_97 , 1 ) ;
if ( V_98 -> V_25 & V_28 ) {
V_2 -> V_29 = F_34 ( V_97 , 2 ) ;
if ( F_31 ( ! V_2 -> V_29 ) )
goto V_113;
}
if ( V_98 -> V_25 & V_114 ) {
V_2 -> V_19 = F_34 ( V_97 , 2 ) ;
if ( ! V_2 -> V_19 )
goto V_115;
} else
V_2 -> V_19 = V_2 -> V_27 ;
V_2 -> V_16 = V_98 ;
V_101 = & V_2 -> V_110 [ 0 ] ;
V_101 -> V_2 = V_2 ;
V_101 -> V_70 = V_97 -> V_70 ;
V_103 . V_70 = V_97 -> V_70 ;
V_103 . V_116 = & V_117 ;
V_103 . V_25 = 0 ;
V_104 = F_35 ( V_97 , 0 ) ;
V_103 . V_118 = ( V_104 ? & V_104 : NULL ) ;
V_103 . V_119 = ( V_104 ? 1 : 0 ) ;
V_101 -> V_85 . V_103 = & V_103 ;
if ( V_59 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_59 ;
}
F_29 ( V_2 ) ;
V_60 = F_36 ( NULL , & V_101 -> V_85 ) ;
if ( F_31 ( V_60 ) )
goto V_120;
V_2 -> V_106 -> V_107 [ 0 ] = & V_101 -> V_85 ;
for ( V_4 = 1 ; V_4 < V_100 ; V_4 ++ ) {
const char * V_121 ;
memset ( & V_103 , 0 , sizeof( V_103 ) ) ;
V_104 = V_97 -> V_70 ;
V_60 = F_37 ( V_97 , L_5 ,
V_4 , & V_121 ) ;
if ( F_31 ( V_60 ) )
goto V_122;
V_101 = & V_2 -> V_110 [ V_4 ] ;
V_101 -> V_70 = V_121 ;
V_101 -> V_2 = V_2 ;
V_101 -> V_16 = & V_99 [ V_4 ] ;
V_103 . V_70 = V_121 ;
V_103 . V_116 = & V_123 ;
V_103 . V_25 = 0 ;
V_103 . V_118 = ( V_104 ? & V_104 : NULL ) ;
V_103 . V_119 = ( V_104 ? 1 : 0 ) ;
V_101 -> V_85 . V_103 = & V_103 ;
V_60 = F_36 ( NULL , & V_101 -> V_85 ) ;
if ( F_31 ( V_60 ) )
goto V_122;
V_2 -> V_106 -> V_107 [ V_4 ] = & V_101 -> V_85 ;
}
V_60 = F_38 ( V_97 , V_124 ,
V_2 -> V_106 ) ;
if ( F_31 ( V_60 ) )
goto V_122;
return;
V_122:
while ( -- V_4 >= 0 )
F_39 ( V_2 -> V_106 -> V_107 [ V_4 ] ) ;
V_120:
if ( V_2 -> V_19 != V_2 -> V_27 )
F_40 ( V_2 -> V_19 ) ;
V_115:
if ( V_2 -> V_29 )
F_40 ( V_2 -> V_29 ) ;
V_113:
if ( V_2 -> V_36 )
F_40 ( V_2 -> V_36 ) ;
F_40 ( V_2 -> V_27 ) ;
V_112:
F_41 ( V_2 -> V_110 ) ;
V_111:
F_41 ( V_2 -> V_106 ) ;
V_108:
F_41 ( V_2 ) ;
}
