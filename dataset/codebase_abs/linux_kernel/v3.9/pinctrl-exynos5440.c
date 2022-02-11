static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
static int F_4 ( struct V_1 * V_2 ,
unsigned V_6 , const unsigned * * V_9 , unsigned * V_10 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
* V_9 = V_4 -> V_7 [ V_6 ] . V_9 ;
* V_10 = V_4 -> V_7 [ V_6 ] . V_10 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_11 * V_12 , struct V_13 * * V_14 ,
unsigned * V_15 )
{
struct V_16 * V_17 = V_2 -> V_17 ;
struct V_13 * V_18 ;
unsigned long * V_19 = NULL ;
char * V_20 , * V_21 ;
int V_22 = 0 , V_23 = 0 , V_24 = 0 ;
for ( V_24 = 0 ; V_24 < F_6 ( V_25 ) ; V_24 ++ )
if ( F_7 ( V_12 , V_25 [ V_24 ] . V_26 , NULL ) )
V_22 ++ ;
if ( V_22 )
V_23 = 1 ;
if ( F_7 ( V_12 , L_1 , NULL ) )
V_23 ++ ;
if ( ! V_23 ) {
F_8 ( V_17 , L_2
L_3 , V_12 -> V_8 ) ;
return - V_27 ;
}
V_18 = F_9 ( sizeof( * V_18 ) * V_23 , V_28 ) ;
if ( ! V_18 ) {
F_8 ( V_17 , L_4 ) ;
return - V_29 ;
}
* V_15 = 0 ;
V_20 = F_9 ( strlen ( V_12 -> V_8 ) + V_30 , V_28 ) ;
if ( ! V_20 ) {
F_8 ( V_17 , L_5 ) ;
goto V_31;
}
sprintf ( V_20 , L_6 , V_12 -> V_8 , V_32 ) ;
if ( ! V_22 )
goto V_33;
V_19 = F_9 ( sizeof( * V_19 ) * V_22 , V_28 ) ;
if ( ! V_19 ) {
F_8 ( V_17 , L_7 ) ;
goto V_34;
}
for ( V_24 = 0 , V_22 = 0 ; V_24 < F_6 ( V_25 ) ; V_24 ++ ) {
T_1 V_35 ;
if ( ! F_10 ( V_12 , V_25 [ V_24 ] . V_26 , & V_35 ) )
V_19 [ V_22 ++ ] =
F_11 ( V_25 [ V_24 ] . V_36 , V_35 ) ;
}
V_18 [ * V_15 ] . V_37 . V_38 . V_39 = V_20 ;
V_18 [ * V_15 ] . V_37 . V_38 . V_38 = V_19 ;
V_18 [ * V_15 ] . V_37 . V_38 . V_40 = V_22 ;
V_18 [ * V_15 ] . type = V_41 ;
* V_15 += 1 ;
V_33:
if ( F_7 ( V_12 , L_1 , NULL ) ) {
V_21 = F_9 ( strlen ( V_12 -> V_8 ) + V_42 , V_28 ) ;
if ( ! V_21 ) {
F_8 ( V_17 , L_8 ) ;
goto V_43;
}
sprintf ( V_21 , L_6 , V_12 -> V_8 , V_44 ) ;
V_18 [ * V_15 ] . V_37 . V_45 . V_46 = V_20 ;
V_18 [ * V_15 ] . V_37 . V_45 . V_47 = V_21 ;
V_18 [ * V_15 ] . type = V_48 ;
* V_15 += 1 ;
}
* V_14 = V_18 ;
return 0 ;
V_43:
F_12 ( V_19 ) ;
V_34:
F_12 ( V_20 ) ;
V_31:
F_12 ( V_18 ) ;
return - V_29 ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_13 * V_18 , unsigned V_49 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_49 ; V_24 ++ ) {
if ( V_18 [ V_24 ] . type == V_48 ) {
F_12 ( V_18 [ V_24 ] . V_37 . V_45 . V_47 ) ;
if ( ! V_24 )
F_12 ( V_18 [ V_24 ] . V_37 . V_45 . V_46 ) ;
} else if ( V_18 -> type == V_41 ) {
F_12 ( V_18 [ V_24 ] . V_37 . V_38 . V_38 ) ;
if ( ! V_24 )
F_12 ( V_18 [ V_24 ] . V_37 . V_38 . V_39 ) ;
}
} ;
F_12 ( V_18 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
return V_4 -> V_50 ;
}
static const char * F_15 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
return V_4 -> V_51 [ V_6 ] . V_8 ;
}
static int F_16 ( struct V_1 * V_2 ,
unsigned V_6 , const char * const * * V_52 ,
unsigned * const V_53 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_2 ) ;
* V_52 = V_4 -> V_51 [ V_6 ] . V_52 ;
* V_53 = V_4 -> V_51 [ V_6 ] . V_53 ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , unsigned V_6 ,
unsigned V_46 , bool V_54 )
{
struct V_3 * V_4 ;
void T_2 * V_55 ;
T_1 V_47 ;
T_1 V_37 ;
V_4 = F_2 ( V_2 ) ;
V_55 = V_4 -> V_56 ;
V_47 = V_4 -> V_51 [ V_6 ] . V_47 ;
V_37 = F_18 ( V_55 + V_57 ) ;
if ( V_54 )
V_37 |= ( 1 << V_47 ) ;
else
V_37 &= ~ ( 1 << V_47 ) ;
F_19 ( V_37 , V_55 + V_57 ) ;
}
static int F_20 ( struct V_1 * V_2 , unsigned V_6 ,
unsigned V_46 )
{
F_17 ( V_2 , V_6 , V_46 , true ) ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 ,
unsigned V_6 , unsigned V_46 )
{
F_17 ( V_2 , V_6 , V_46 , false ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_58 * V_59 , unsigned V_60 , bool V_61 )
{
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , unsigned int V_62 ,
unsigned long V_63 )
{
struct V_3 * V_4 ;
void T_2 * V_55 ;
enum V_64 V_36 = F_24 ( V_63 ) ;
T_1 V_65 = F_25 ( V_63 ) ;
T_1 V_37 ;
V_4 = F_2 ( V_2 ) ;
V_55 = V_4 -> V_56 ;
switch ( V_36 ) {
case V_66 :
V_37 = F_18 ( V_55 + V_67 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
if ( V_65 )
V_37 |= ( 1 << V_62 ) ;
F_19 ( V_37 , V_55 + V_67 ) ;
V_37 = F_18 ( V_55 + V_68 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
if ( V_65 == 2 )
V_37 |= ( 1 << V_62 ) ;
F_19 ( V_37 , V_55 + V_68 ) ;
break;
case V_69 :
V_37 = F_18 ( V_55 + V_70 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
V_37 |= ( ( V_65 & 1 ) << V_62 ) ;
F_19 ( V_37 , V_55 + V_70 ) ;
V_65 >>= 1 ;
V_37 = F_18 ( V_55 + V_71 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
V_37 |= ( ( V_65 & 1 ) << V_62 ) ;
F_19 ( V_37 , V_55 + V_71 ) ;
break;
case V_72 :
V_37 = F_18 ( V_55 + V_73 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
V_37 |= ( ( V_65 & 1 ) << V_62 ) ;
F_19 ( V_37 , V_55 + V_73 ) ;
break;
case V_74 :
V_37 = F_18 ( V_55 + V_75 ) ;
V_37 &= ~ ( 1 << V_62 ) ;
V_37 |= ( ( V_65 & 1 ) << V_62 ) ;
F_19 ( V_37 , V_55 + V_75 ) ;
break;
default:
F_26 ( 1 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , unsigned int V_62 ,
unsigned long * V_63 )
{
struct V_3 * V_4 ;
void T_2 * V_55 ;
enum V_64 V_36 = F_24 ( * V_63 ) ;
T_1 V_37 ;
V_4 = F_2 ( V_2 ) ;
V_55 = V_4 -> V_56 ;
switch ( V_36 ) {
case V_66 :
V_37 = F_18 ( V_55 + V_67 ) ;
V_37 = ( V_37 >> V_62 ) & 1 ;
if ( ! V_37 )
* V_63 = 0 ;
else
* V_63 = ( ( F_18 ( V_55 + V_68 ) >> V_62 ) & 1 ) + 1 ;
break;
case V_69 :
V_37 = F_18 ( V_55 + V_70 ) ;
V_37 = ( V_37 >> V_62 ) & 1 ;
* V_63 = V_37 ;
V_37 = F_18 ( V_55 + V_71 ) ;
V_37 = ( V_37 >> V_62 ) & 1 ;
* V_63 |= ( V_37 << 1 ) ;
break;
case V_72 :
V_37 = F_18 ( V_55 + V_73 ) ;
* V_63 = ( V_37 >> V_62 ) & 1 ;
break;
case V_74 :
V_37 = F_18 ( V_55 + V_75 ) ;
* V_63 = ( V_37 >> V_62 ) & 1 ;
break;
default:
F_26 ( 1 ) ;
return - V_27 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
unsigned V_46 , unsigned long V_63 )
{
struct V_3 * V_4 ;
const unsigned int * V_9 ;
unsigned int V_76 ;
V_4 = F_2 ( V_2 ) ;
V_9 = V_4 -> V_7 [ V_46 ] . V_9 ;
for ( V_76 = 0 ; V_76 < V_4 -> V_7 [ V_46 ] . V_10 ; V_76 ++ )
F_23 ( V_2 , V_9 [ V_76 ] , V_63 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
unsigned int V_46 , unsigned long * V_63 )
{
struct V_3 * V_4 ;
const unsigned int * V_9 ;
V_4 = F_2 ( V_2 ) ;
V_9 = V_4 -> V_7 [ V_46 ] . V_9 ;
F_27 ( V_2 , V_9 [ 0 ] , V_63 ) ;
return 0 ;
}
static void F_30 ( struct V_77 * V_78 , unsigned V_60 , int V_35 )
{
struct V_3 * V_4 = F_31 ( V_78 -> V_17 ) ;
void T_2 * V_55 = V_4 -> V_56 ;
T_1 V_37 ;
V_37 = F_18 ( V_55 + V_79 ) ;
V_37 &= ~ ( 1 << V_60 ) ;
if ( V_35 )
V_37 |= 1 << V_60 ;
F_19 ( V_37 , V_55 + V_79 ) ;
}
static int F_32 ( struct V_77 * V_78 , unsigned V_60 )
{
struct V_3 * V_4 = F_31 ( V_78 -> V_17 ) ;
void T_2 * V_55 = V_4 -> V_56 ;
T_1 V_37 ;
V_37 = F_18 ( V_55 + V_80 ) ;
V_37 >>= V_60 ;
V_37 &= 1 ;
return V_37 ;
}
static int F_33 ( struct V_77 * V_78 , unsigned V_60 )
{
struct V_3 * V_4 = F_31 ( V_78 -> V_17 ) ;
void T_2 * V_55 = V_4 -> V_56 ;
T_1 V_37 ;
V_37 = F_18 ( V_55 + V_81 ) ;
V_37 &= ~ ( 1 << V_60 ) ;
F_19 ( V_37 , V_55 + V_81 ) ;
V_37 = F_18 ( V_55 + V_82 ) ;
V_37 |= 1 << V_60 ;
F_19 ( V_37 , V_55 + V_82 ) ;
return 0 ;
}
static int F_34 ( struct V_77 * V_78 , unsigned V_60 ,
int V_35 )
{
struct V_3 * V_4 = F_31 ( V_78 -> V_17 ) ;
void T_2 * V_55 = V_4 -> V_56 ;
T_1 V_37 ;
F_30 ( V_78 , V_60 , V_35 ) ;
V_37 = F_18 ( V_55 + V_82 ) ;
V_37 &= ~ ( 1 << V_60 ) ;
F_19 ( V_37 , V_55 + V_82 ) ;
V_37 = F_18 ( V_55 + V_81 ) ;
V_37 |= 1 << V_60 ;
F_19 ( V_37 , V_55 + V_81 ) ;
return 0 ;
}
static int F_35 ( struct V_83 * V_84 ,
struct V_11 * V_85 , unsigned int * * V_86 ,
unsigned int * V_87 )
{
struct V_16 * V_17 = & V_84 -> V_17 ;
struct V_88 * V_89 ;
V_89 = F_7 ( V_85 , L_9 , NULL ) ;
if ( ! V_89 )
return - V_90 ;
* V_87 = V_89 -> V_91 / sizeof( unsigned long ) ;
if ( ! * V_87 ) {
F_8 ( V_17 , L_10 , V_85 -> V_8 ) ;
return - V_27 ;
}
* V_86 = F_36 ( V_17 , * V_87 * sizeof( * * V_86 ) , V_28 ) ;
if ( ! * V_86 ) {
F_8 ( V_17 , L_11 ) ;
return - V_29 ;
}
return F_37 ( V_85 , L_9 ,
* V_86 , * V_87 ) ;
}
static int F_38 ( struct V_83 * V_84 ,
struct V_3 * V_4 )
{
struct V_16 * V_17 = & V_84 -> V_17 ;
struct V_11 * V_92 = V_17 -> V_93 ;
struct V_11 * V_85 ;
struct V_94 * V_52 , * V_95 ;
struct V_96 * V_97 , * V_98 ;
unsigned * V_86 ;
unsigned int V_87 , V_99 , V_100 = 0 ;
char * V_20 , * V_21 ;
int V_101 ;
V_99 = F_39 ( V_92 ) ;
if ( ! V_99 )
return - V_27 ;
V_52 = F_36 ( V_17 , V_99 * sizeof( * V_52 ) , V_28 ) ;
if ( ! V_52 ) {
F_8 ( V_17 , L_12 ) ;
return - V_27 ;
}
V_95 = V_52 ;
V_97 = F_36 ( V_17 , V_99 * sizeof( * V_97 ) , V_28 ) ;
if ( ! V_97 ) {
F_8 ( V_17 , L_13 ) ;
return - V_27 ;
}
V_98 = V_97 ;
F_40 (dev_np, cfg_np) {
T_1 V_47 ;
V_101 = F_35 ( V_84 , V_85 ,
& V_86 , & V_87 ) ;
if ( V_101 )
return V_101 ;
V_20 = F_36 ( V_17 , strlen ( V_85 -> V_8 ) + V_30 ,
V_28 ) ;
if ( ! V_20 ) {
F_8 ( V_17 , L_5 ) ;
return - V_29 ;
}
sprintf ( V_20 , L_6 , V_85 -> V_8 , V_32 ) ;
V_95 -> V_8 = V_20 ;
V_95 -> V_9 = V_86 ;
V_95 -> V_10 = V_87 ;
V_95 ++ ;
V_101 = F_10 ( V_85 , L_1 ,
& V_47 ) ;
if ( V_101 )
continue;
V_21 = F_36 ( V_17 , strlen ( V_85 -> V_8 ) + V_42 ,
V_28 ) ;
if ( ! V_21 ) {
F_8 ( V_17 , L_8 ) ;
return - V_29 ;
}
sprintf ( V_21 , L_6 , V_85 -> V_8 , V_44 ) ;
V_98 -> V_8 = V_21 ;
V_98 -> V_52 = F_36 ( V_17 , sizeof( char * ) , V_28 ) ;
if ( ! V_98 -> V_52 ) {
F_8 ( V_17 , L_14
L_15 ) ;
return - V_29 ;
}
V_98 -> V_52 [ 0 ] = V_20 ;
V_98 -> V_53 = 1 ;
V_98 -> V_47 = V_47 ;
V_98 ++ ;
V_100 ++ ;
}
V_4 -> V_7 = V_52 ;
V_4 -> V_5 = V_99 ;
V_4 -> V_51 = V_97 ;
V_4 -> V_50 = V_100 ;
return 0 ;
}
static int F_41 ( struct V_83 * V_84 ,
struct V_3 * V_4 )
{
struct V_16 * V_17 = & V_84 -> V_17 ;
struct V_102 * V_103 ;
struct V_1 * V_104 ;
struct V_105 * V_106 , * V_107 ;
struct V_58 V_108 ;
char * V_109 ;
int V_62 , V_101 ;
V_103 = F_36 ( V_17 , sizeof( * V_103 ) , V_28 ) ;
if ( ! V_103 ) {
F_8 ( V_17 , L_16 ) ;
return - V_29 ;
}
V_103 -> V_8 = L_17 ;
V_103 -> V_110 = V_111 ;
V_103 -> V_112 = & V_113 ;
V_103 -> V_114 = & V_115 ;
V_103 -> V_116 = & V_117 ;
V_106 = F_36 ( & V_84 -> V_17 , sizeof( * V_106 ) *
V_118 , V_28 ) ;
if ( ! V_106 ) {
F_8 ( & V_84 -> V_17 , L_18 ) ;
return - V_29 ;
}
V_103 -> V_9 = V_106 ;
V_103 -> V_87 = V_118 ;
for ( V_62 = 0 , V_107 = V_106 ; V_62 < V_103 -> V_87 ; V_62 ++ , V_107 ++ )
V_107 -> V_119 = V_62 ;
V_109 = F_36 ( & V_84 -> V_17 , sizeof( char ) * V_120 *
V_103 -> V_87 , V_28 ) ;
if ( ! V_109 ) {
F_8 ( & V_84 -> V_17 , L_19 ) ;
return - V_29 ;
}
for ( V_62 = 0 ; V_62 < V_103 -> V_87 ; V_62 ++ ) {
sprintf ( V_109 , L_20 , V_62 ) ;
V_107 = V_106 + V_62 ;
V_107 -> V_8 = V_109 ;
V_109 += V_120 ;
}
V_101 = F_38 ( V_84 , V_4 ) ;
if ( V_101 )
return V_101 ;
V_104 = F_42 ( V_103 , & V_84 -> V_17 , V_4 ) ;
if ( ! V_104 ) {
F_8 ( & V_84 -> V_17 , L_21 ) ;
return - V_27 ;
}
V_108 . V_8 = L_22 ;
V_108 . V_121 = 0 ;
V_108 . V_55 = 0 ;
V_108 . V_87 = V_118 ;
V_108 . V_78 = V_4 -> V_78 ;
F_43 ( V_104 , & V_108 ) ;
return 0 ;
}
static int F_44 ( struct V_83 * V_84 ,
struct V_3 * V_4 )
{
struct V_77 * V_78 ;
int V_101 ;
V_78 = F_36 ( & V_84 -> V_17 , sizeof( * V_78 ) , V_28 ) ;
if ( ! V_78 ) {
F_8 ( & V_84 -> V_17 , L_23 ) ;
return - V_29 ;
}
V_4 -> V_78 = V_78 ;
V_78 -> V_55 = 0 ;
V_78 -> V_122 = V_118 ;
V_78 -> V_17 = & V_84 -> V_17 ;
V_78 -> V_123 = F_30 ;
V_78 -> V_124 = F_32 ;
V_78 -> V_125 = F_33 ;
V_78 -> V_126 = F_34 ;
V_78 -> V_127 = L_24 ;
V_78 -> V_110 = V_111 ;
V_101 = F_45 ( V_78 ) ;
if ( V_101 ) {
F_8 ( & V_84 -> V_17 , L_25
L_26 , V_78 -> V_127 , V_101 ) ;
return V_101 ;
}
return 0 ;
}
static int F_46 ( struct V_83 * V_84 ,
struct V_3 * V_4 )
{
int V_101 = F_47 ( V_4 -> V_78 ) ;
if ( V_101 ) {
F_8 ( & V_84 -> V_17 , L_27 ) ;
return V_101 ;
}
return 0 ;
}
static int F_48 ( struct V_83 * V_84 )
{
struct V_16 * V_17 = & V_84 -> V_17 ;
struct V_3 * V_4 ;
struct V_128 * V_129 ;
int V_101 ;
if ( ! V_17 -> V_93 ) {
F_8 ( V_17 , L_28 ) ;
return - V_130 ;
}
V_4 = F_36 ( V_17 , sizeof( V_4 ) , V_28 ) ;
if ( ! V_4 ) {
F_8 ( V_17 , L_29 ) ;
return - V_29 ;
}
V_129 = F_49 ( V_84 , V_131 , 0 ) ;
if ( ! V_129 ) {
F_8 ( V_17 , L_30 ) ;
return - V_90 ;
}
V_4 -> V_56 = F_50 ( & V_84 -> V_17 , V_129 ) ;
if ( F_51 ( V_4 -> V_56 ) )
return F_52 ( V_4 -> V_56 ) ;
V_101 = F_44 ( V_84 , V_4 ) ;
if ( V_101 )
return V_101 ;
V_101 = F_41 ( V_84 , V_4 ) ;
if ( V_101 ) {
F_46 ( V_84 , V_4 ) ;
return V_101 ;
}
F_53 ( V_84 , V_4 ) ;
F_54 ( V_17 , L_31 ) ;
return 0 ;
}
static int T_3 F_55 ( void )
{
return F_56 ( & V_132 ) ;
}
static void T_4 F_57 ( void )
{
F_58 ( & V_132 ) ;
}
