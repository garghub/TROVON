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
static void F_6 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 = V_2 -> V_16 ;
T_1 V_18 ;
if ( V_16 -> V_24 & V_25 ) {
V_18 = F_4 ( V_2 -> V_26 + V_16 -> V_27 . V_21 ) ;
V_18 &= ~ ( 1 << V_16 -> V_27 . V_28 ) ;
F_7 ( V_18 , V_2 -> V_26 + V_16 -> V_27 . V_21 ) ;
}
V_18 = F_4 ( V_2 -> V_29 + V_16 -> V_30 . V_21 ) ;
V_18 |= ( 1 << V_16 -> V_30 . V_31 ) ;
F_7 ( V_18 , V_2 -> V_29 + V_16 -> V_30 . V_21 ) ;
V_18 &= ~ ( F_8 ( V_16 -> V_30 . V_32 ) << V_16 -> V_30 . V_33 ) ;
F_7 ( V_18 , V_2 -> V_29 + V_16 -> V_30 . V_21 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 = V_2 -> V_16 ;
T_1 V_18 ;
V_18 = F_4 ( V_2 -> V_29 + V_16 -> V_30 . V_21 ) ;
V_18 |= F_8 ( V_16 -> V_30 . V_32 ) << V_16 -> V_30 . V_33 ;
V_18 &= ~ ( 1 << V_16 -> V_30 . V_31 ) ;
F_7 ( V_18 , V_2 -> V_29 + V_16 -> V_30 . V_21 ) ;
if ( V_16 -> V_24 & V_25 ) {
V_18 = F_4 ( V_2 -> V_26 + V_16 -> V_27 . V_21 ) ;
V_18 |= ( 1 << V_16 -> V_27 . V_28 ) ;
F_7 ( V_18 , V_2 -> V_26 + V_16 -> V_27 . V_21 ) ;
}
return 0 ;
}
static void F_10 ( struct V_1 * V_2 )
{
T_1 V_18 ;
const struct V_15 * V_16 = V_2 -> V_16 ;
const struct V_34 * V_35 = & V_16 -> V_35 ;
V_18 = F_4 ( V_2 -> V_19 + V_35 -> V_21 ) ;
V_18 &= ~ ( 1 << V_35 -> V_36 | 1 << V_35 -> V_37 ) ;
F_7 ( V_18 , V_2 -> V_19 + V_35 -> V_21 ) ;
if ( F_11 ( V_16 -> V_24 & V_38 ) )
F_4 ( V_2 -> V_19 + V_35 -> V_21 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_39 ,
unsigned int V_40 , unsigned int V_41 )
{
T_1 V_18 ;
const struct V_15 * V_16 = V_2 -> V_16 ;
const struct V_34 * V_35 = & V_16 -> V_35 ;
V_18 = F_4 ( V_2 -> V_19 + V_35 -> V_21 ) ;
V_18 &= ~ ( F_8 ( V_35 -> V_42 ) << V_35 -> V_43 |
F_8 ( V_35 -> V_44 ) << V_35 -> V_45 |
F_8 ( V_35 -> V_46 ) << V_35 -> V_47 ) ;
V_18 |= V_41 << V_35 -> V_43 | V_39 << V_35 -> V_45 |
V_40 << V_35 -> V_47 ;
V_18 |= 1 << V_35 -> V_36 | 1 << V_35 -> V_37 ;
F_7 ( V_18 , V_2 -> V_19 + V_35 -> V_21 ) ;
if ( F_11 ( V_16 -> V_24 & V_38 ) )
F_4 ( V_2 -> V_19 + V_35 -> V_21 ) ;
}
static int F_13 ( struct V_48 * V_49 , unsigned int V_50 ,
unsigned long V_51 )
{
struct V_1 * V_2 = V_49 -> V_2 ;
const struct V_52 * V_53 = & V_2 -> V_6 [ V_50 ] ;
const struct V_15 * V_16 = V_2 -> V_16 ;
int V_40 = 0 , V_41 , V_39 , V_54 ;
unsigned long V_7 = V_53 -> V_7 ;
T_1 V_18 ;
enum V_10 V_11 ;
unsigned long V_9 ;
if ( V_53 -> V_55 == 0 )
V_9 = V_51 * 2 ;
else
V_9 = V_51 / V_53 -> V_55 ;
if ( V_7 >= V_56 && V_7 < V_57 ) {
V_41 = 4 ;
V_11 = V_58 ;
} else if ( V_7 >= V_57 && V_7 && V_7 < V_59 ) {
V_41 = 3 ;
V_11 = V_60 ;
} else if ( V_7 >= V_59 && V_7 < V_61 ) {
V_41 = 3 ;
V_11 = V_62 ;
} else {
F_14 ( L_1 , V_63 ,
V_49 -> V_64 , V_7 ) ;
return - V_8 ;
}
V_39 = F_2 ( V_9 , V_11 ) ;
if ( V_39 < 0 ) {
F_14 ( L_2 , V_63 , V_49 -> V_64 ) ;
return V_39 ;
}
V_54 = F_9 ( V_2 ) ;
if ( V_54 ) {
F_14 ( L_3 , V_63 , V_49 -> V_64 ) ;
return V_54 ;
}
F_10 ( V_2 ) ;
F_7 ( 0 , V_2 -> V_19 + V_16 -> V_65 . V_66 ) ;
if ( F_11 ( V_16 -> V_24 & V_38 ) )
F_4 ( V_2 -> V_19 + V_16 -> V_65 . V_66 ) ;
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_65 . V_67 ) ;
if ( V_7 >= V_56 && V_7 < V_68 )
V_18 |= ( 1 << V_69 ) ;
if ( V_7 < V_57 )
V_18 &= ~ ( 1 << V_70 ) ;
else
V_18 |= ( 1 << V_70 ) ;
F_7 ( V_18 , V_2 -> V_19 + V_16 -> V_65 . V_67 ) ;
if ( F_11 ( V_16 -> V_24 & V_38 ) )
F_4 ( V_2 -> V_19 + V_16 -> V_65 . V_67 ) ;
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_71 . V_21 ) ;
V_18 &= ~ ( F_8 ( V_16 -> V_71 . V_72 ) << V_16 -> V_71 . V_22 ) ;
V_18 |= V_53 -> V_71 << V_16 -> V_71 . V_22 ;
F_7 ( V_18 , V_2 -> V_19 + V_16 -> V_71 . V_21 ) ;
if ( F_11 ( V_16 -> V_24 & V_38 ) )
F_4 ( V_2 -> V_19 + V_16 -> V_71 . V_21 ) ;
if ( V_16 -> V_24 & V_73 ) {
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_74 . V_21 ) ;
V_18 &= ~ ( F_8 ( V_16 -> V_74 . V_72 ) <<
V_16 -> V_74 . V_22 ) ;
V_18 |= V_53 -> V_74 << V_16 -> V_74 . V_22 ;
F_7 ( V_18 , V_2 -> V_19 + V_16 -> V_74 . V_21 ) ;
if ( F_11 ( V_16 -> V_24 & V_38 ) )
F_4 ( V_2 -> V_19 + V_16 -> V_74 . V_21 ) ;
}
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_55 . V_21 ) ;
V_18 &= ~ ( F_8 ( V_16 -> V_55 . V_72 ) << V_16 -> V_55 . V_22 ) ;
V_18 |= V_53 -> V_55 << V_16 -> V_55 . V_22 ;
F_7 ( V_18 , V_2 -> V_19 + V_16 -> V_55 . V_21 ) ;
if ( F_11 ( V_16 -> V_24 & V_38 ) )
F_4 ( V_2 -> V_19 + V_16 -> V_55 . V_21 ) ;
F_12 ( V_2 , V_39 , V_40 , V_41 ) ;
V_54 = F_3 ( V_2 ) ;
if ( V_54 < 0 ) {
F_14 ( L_4 , V_63 , V_49 -> V_64 ) ;
return V_54 ;
}
return 0 ;
}
static int F_15 ( struct V_75 * V_76 )
{
struct V_48 * V_49 = F_16 ( V_76 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
return F_9 ( V_2 ) ;
}
static void F_17 ( struct V_75 * V_76 )
{
struct V_48 * V_49 = F_16 ( V_76 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
const struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_24 & V_77 )
return;
F_6 ( V_2 ) ;
}
static unsigned long F_18 ( struct V_75 * V_76 ,
unsigned long V_51 )
{
struct V_48 * V_49 = F_16 ( V_76 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
const struct V_15 * V_16 = V_2 -> V_16 ;
T_1 V_18 ;
T_2 V_78 ;
unsigned int V_71 , V_74 , V_55 ;
if ( V_51 == 0 )
return 0 ;
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_20 . V_21 ) ;
if ( ( V_18 & ( 1 << V_16 -> V_20 . V_22 ) ) == 0 ) {
V_49 -> V_7 = 0 ;
return 0 ;
}
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_71 . V_21 ) ;
V_71 = ( V_18 >> V_16 -> V_71 . V_22 ) &
F_8 ( V_16 -> V_71 . V_72 ) ;
V_78 = ( T_2 ) V_71 << V_16 -> V_71 . V_22 ;
if ( V_16 -> V_24 & V_73 ) {
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_74 . V_21 ) ;
V_74 = ( V_18 >> V_16 -> V_74 . V_22 ) &
F_8 ( V_16 -> V_74 . V_72 ) ;
if ( V_74 != 0 )
V_78 = ( ( T_2 ) V_71 << V_16 -> V_71 . V_22 ) |
V_74 ;
}
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_55 . V_21 ) ;
V_55 = ( V_18 >> V_16 -> V_55 . V_22 ) & F_8 ( V_16 -> V_55 . V_72 ) ;
V_49 -> V_7 = ( V_78 * V_51 ) >> V_16 -> V_71 . V_22 ;
if ( V_55 == 0 )
V_49 -> V_7 *= 2 ;
else
V_49 -> V_7 /= V_55 ;
return V_49 -> V_7 ;
}
static long F_19 ( struct V_75 * V_76 , unsigned long V_7 ,
unsigned long * V_51 )
{
unsigned V_4 ;
struct V_48 * V_49 = F_16 ( V_76 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
if ( V_7 == 0 || * V_51 == 0 || ! V_2 -> V_6 )
return - V_8 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
if ( V_7 <= V_2 -> V_6 [ V_4 ] . V_7 )
break;
}
if ( V_4 == V_2 -> V_5 )
V_4 -- ;
return V_2 -> V_6 [ V_4 ] . V_7 ;
}
static int F_20 ( struct V_75 * V_76 , unsigned long V_7 ,
unsigned long V_51 )
{
struct V_48 * V_49 = F_16 ( V_76 ) ;
struct V_1 * V_2 = V_49 -> V_2 ;
int V_50 , V_54 ;
V_50 = F_1 ( V_2 , V_7 ) ;
if ( V_50 < 0 )
return V_50 ;
V_54 = F_13 ( V_49 , V_50 , V_51 ) ;
return V_54 ;
}
static int F_21 ( struct V_75 * V_76 )
{
struct V_48 * V_49 = F_16 ( V_76 ) ;
const struct V_79 * V_16 = V_49 -> V_16 ;
struct V_1 * V_2 = V_49 -> V_2 ;
T_1 V_18 ;
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_80 . V_21 ) ;
V_18 &= ~ ( 1 << V_16 -> V_80 . V_81 ) ;
F_7 ( V_18 , V_2 -> V_19 + V_16 -> V_80 . V_21 ) ;
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_80 . V_21 ) ;
V_18 &= ~ ( 1 << V_16 -> V_80 . V_82 ) ;
F_7 ( V_18 , V_2 -> V_19 + V_16 -> V_80 . V_21 ) ;
if ( F_11 ( V_16 -> V_24 & V_38 ) )
F_4 ( V_2 -> V_19 + V_16 -> V_80 . V_21 ) ;
return 0 ;
}
static void F_22 ( struct V_75 * V_76 )
{
struct V_48 * V_49 = F_16 ( V_76 ) ;
const struct V_79 * V_16 = V_49 -> V_16 ;
struct V_1 * V_2 = V_49 -> V_2 ;
T_1 V_18 ;
if ( V_16 -> V_24 & V_77 )
return;
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_80 . V_21 ) ;
V_18 |= 1 << V_16 -> V_80 . V_81 ;
F_7 ( V_18 , V_2 -> V_19 + V_16 -> V_80 . V_21 ) ;
if ( F_11 ( V_16 -> V_24 & V_38 ) )
F_4 ( V_2 -> V_19 + V_16 -> V_80 . V_21 ) ;
}
static unsigned long F_23 ( struct V_75 * V_76 ,
unsigned long V_51 )
{
struct V_48 * V_49 = F_16 ( V_76 ) ;
const struct V_79 * V_16 = V_49 -> V_16 ;
struct V_1 * V_2 = V_49 -> V_2 ;
T_1 V_18 ;
unsigned int V_83 ;
if ( V_51 == 0 )
return 0 ;
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_83 . V_21 ) ;
V_83 = ( V_18 >> V_16 -> V_83 . V_22 ) & F_8 ( V_16 -> V_83 . V_72 ) ;
if ( V_83 == 0 )
V_83 = 256 ;
V_49 -> V_7 = V_51 / V_83 ;
return V_49 -> V_7 ;
}
static long F_24 ( struct V_75 * V_76 , unsigned long V_7 ,
unsigned long * V_51 )
{
unsigned int div ;
if ( V_7 == 0 || * V_51 == 0 )
return - V_8 ;
if ( V_7 == * V_51 )
return * V_51 ;
div = F_25 ( * V_51 , V_7 ) ;
if ( div < 2 )
return * V_51 ;
if ( div > 256 )
div = 256 ;
return * V_51 / div ;
}
static int F_26 ( struct V_75 * V_76 , unsigned long V_7 ,
unsigned long V_51 )
{
struct V_48 * V_49 = F_16 ( V_76 ) ;
const struct V_79 * V_16 = V_49 -> V_16 ;
struct V_1 * V_2 = V_49 -> V_2 ;
T_1 V_18 ;
unsigned int div ;
if ( V_7 == 0 || V_51 == 0 )
return - V_8 ;
div = F_25 ( V_51 , V_7 ) ;
if ( div > 256 )
return - V_8 ;
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_83 . V_21 ) ;
if ( div == 256 ) {
V_18 &= ~ ( F_8 ( V_16 -> V_83 . V_72 ) << V_16 -> V_83 . V_22 ) ;
} else {
V_18 &= ~ ( F_8 ( V_16 -> V_83 . V_72 ) << V_16 -> V_83 . V_22 ) ;
V_18 |= div << V_16 -> V_83 . V_22 ;
}
F_7 ( V_18 , V_2 -> V_19 + V_16 -> V_83 . V_21 ) ;
if ( F_11 ( V_16 -> V_24 & V_38 ) )
F_4 ( V_2 -> V_19 + V_16 -> V_83 . V_21 ) ;
V_49 -> V_7 = V_51 / div ;
return 0 ;
}
static void F_27 ( struct V_1 * V_2 )
{
const struct V_15 * V_16 = V_2 -> V_16 ;
if ( V_16 -> V_24 & V_84 ) {
T_1 V_18 ;
V_18 = F_4 ( V_2 -> V_19 + V_16 -> V_85 . V_21 ) ;
V_18 |= F_28 ( V_16 -> V_85 . V_22 ) ;
F_7 ( V_18 , V_2 -> V_19 + V_16 -> V_85 . V_21 ) ;
if ( F_11 ( V_16 -> V_24 & V_38 ) )
F_4 ( V_2 -> V_19 + V_16 -> V_85 . V_21 ) ;
}
}
void T_3 F_29 ( struct V_86 * V_87 ,
const struct V_15 * V_88 ,
const struct V_52 * V_53 ,
unsigned int V_5 ,
const struct V_79 * V_89 ,
unsigned int V_90 )
{
int V_4 , V_54 ;
struct V_49 * V_49 ;
struct V_1 * V_2 ;
struct V_48 * V_91 ;
struct V_92 V_93 ;
const char * V_94 ;
if ( F_30 ( ! V_88 ) || F_30 ( ! V_89 ) )
return;
V_2 = F_31 ( sizeof( * V_2 ) , V_95 ) ;
if ( F_30 ( ! V_2 ) )
return;
V_2 -> V_96 . V_97 = V_90 ;
V_2 -> V_96 . V_98 = F_32 ( V_90 , sizeof( * V_2 -> V_96 . V_98 ) ,
V_95 ) ;
if ( F_30 ( ! V_2 -> V_96 . V_98 ) )
goto V_99;
V_2 -> V_98 = F_32 ( V_90 , sizeof( * V_2 -> V_98 ) , V_95 ) ;
if ( F_30 ( ! V_2 -> V_98 ) )
goto V_100;
V_2 -> V_19 = F_33 ( V_87 , 0 ) ;
if ( F_30 ( ! V_2 -> V_19 ) )
goto V_101;
V_2 -> V_29 = F_33 ( V_87 , 1 ) ;
if ( F_30 ( ! V_2 -> V_29 ) )
goto V_102;
if ( V_88 -> V_24 & V_25 ) {
V_2 -> V_26 = F_33 ( V_87 , 2 ) ;
if ( F_30 ( ! V_2 -> V_26 ) )
goto V_103;
}
V_2 -> V_16 = V_88 ;
V_91 = & V_2 -> V_98 [ 0 ] ;
V_91 -> V_2 = V_2 ;
V_91 -> V_64 = V_87 -> V_64 ;
V_93 . V_64 = V_87 -> V_64 ;
V_93 . V_104 = & V_105 ;
V_93 . V_24 = 0 ;
V_94 = F_34 ( V_87 , 0 ) ;
V_93 . V_106 = ( V_94 ? & V_94 : NULL ) ;
V_93 . V_107 = ( V_94 ? 1 : 0 ) ;
V_91 -> V_76 . V_93 = & V_93 ;
if ( V_53 ) {
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_53 ;
}
F_27 ( V_2 ) ;
V_49 = F_35 ( NULL , & V_91 -> V_76 ) ;
if ( F_30 ( F_36 ( V_49 ) ) )
goto V_108;
V_2 -> V_96 . V_98 [ 0 ] = V_49 ;
for ( V_4 = 1 ; V_4 < V_90 ; V_4 ++ ) {
const char * V_109 ;
memset ( & V_93 , 0 , sizeof( V_93 ) ) ;
V_94 = V_87 -> V_64 ;
V_54 = F_37 ( V_87 , L_5 ,
V_4 , & V_109 ) ;
if ( F_30 ( V_54 ) )
goto V_110;
V_91 = & V_2 -> V_98 [ V_4 ] ;
V_91 -> V_64 = V_109 ;
V_91 -> V_2 = V_2 ;
V_91 -> V_16 = & V_89 [ V_4 ] ;
V_93 . V_64 = V_109 ;
V_93 . V_104 = & V_111 ;
V_93 . V_24 = 0 ;
V_93 . V_106 = ( V_94 ? & V_94 : NULL ) ;
V_93 . V_107 = ( V_94 ? 1 : 0 ) ;
V_91 -> V_76 . V_93 = & V_93 ;
V_49 = F_35 ( NULL , & V_91 -> V_76 ) ;
if ( F_30 ( F_36 ( V_49 ) ) )
goto V_110;
V_2 -> V_96 . V_98 [ V_4 ] = V_49 ;
}
V_54 = F_38 ( V_87 , V_112 , & V_2 -> V_96 ) ;
if ( F_30 ( V_54 ) )
goto V_110;
return;
V_110:
for ( V_4 = 0 ; V_4 < V_90 ; V_4 ++ )
F_39 ( V_2 -> V_96 . V_98 [ V_4 ] ) ;
V_108:
if ( V_2 -> V_26 )
F_40 ( V_2 -> V_26 ) ;
V_103:
F_40 ( V_2 -> V_29 ) ;
V_102:
F_40 ( V_2 -> V_19 ) ;
V_101:
F_41 ( V_2 -> V_98 ) ;
V_100:
F_41 ( V_2 -> V_96 . V_98 ) ;
V_99:
F_41 ( V_2 ) ;
}
