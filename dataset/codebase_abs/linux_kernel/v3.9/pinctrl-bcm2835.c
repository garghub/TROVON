static inline T_1 F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static inline int F_5 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_6 )
{
V_3 += F_6 ( V_6 ) * 4 ;
return ( F_1 ( V_2 , V_3 ) >> F_7 ( V_6 ) ) & 1 ;
}
static inline void F_8 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_6 )
{
V_3 += F_6 ( V_6 ) * 4 ;
F_3 ( V_2 , V_3 , F_9 ( F_7 ( V_6 ) ) ) ;
}
static inline enum V_7 F_10 (
struct V_1 * V_2 , unsigned V_8 )
{
T_1 V_5 = F_1 ( V_2 , F_11 ( V_8 ) ) ;
enum V_7 V_9 = ( V_5 >> F_12 ( V_8 ) ) & V_10 ;
F_13 ( V_2 -> V_11 , L_1 , V_5 , V_8 ,
V_12 [ V_9 ] ) ;
return V_9 ;
}
static inline void F_14 (
struct V_1 * V_2 , unsigned V_8 ,
enum V_7 V_13 )
{
T_1 V_5 = F_1 ( V_2 , F_11 ( V_8 ) ) ;
enum V_7 V_14 = ( V_5 >> F_12 ( V_8 ) ) & V_10 ;
F_13 ( V_2 -> V_11 , L_2 , V_5 , V_8 ,
V_12 [ V_14 ] ) ;
if ( V_14 == V_13 )
return;
if ( V_14 != V_15 && V_13 != V_15 ) {
V_5 &= ~ ( V_10 << F_12 ( V_8 ) ) ;
V_5 |= V_15 << F_12 ( V_8 ) ;
F_13 ( V_2 -> V_11 , L_3 , V_5 , V_8 ,
V_12 [ V_15 ] ) ;
F_3 ( V_2 , F_11 ( V_8 ) , V_5 ) ;
}
V_5 &= ~ ( V_10 << F_12 ( V_8 ) ) ;
V_5 |= V_13 << F_12 ( V_8 ) ;
F_13 ( V_2 -> V_11 , L_4 , V_5 , V_8 ,
V_12 [ V_13 ] ) ;
F_3 ( V_2 , F_11 ( V_8 ) , V_5 ) ;
}
static int F_15 ( struct V_16 * V_17 , unsigned V_18 )
{
return F_16 ( V_17 -> V_4 + V_18 ) ;
}
static void F_17 ( struct V_16 * V_17 , unsigned V_18 )
{
F_18 ( V_17 -> V_4 + V_18 ) ;
}
static int F_19 ( struct V_16 * V_17 , unsigned V_18 )
{
return F_20 ( V_17 -> V_4 + V_18 ) ;
}
static int F_21 ( struct V_16 * V_17 , unsigned V_18 )
{
struct V_1 * V_2 = F_22 ( V_17 -> V_11 ) ;
return F_5 ( V_2 , V_19 , V_18 ) ;
}
static int F_23 ( struct V_16 * V_17 ,
unsigned V_18 , int V_20 )
{
return F_24 ( V_17 -> V_4 + V_18 ) ;
}
static void F_25 ( struct V_16 * V_17 , unsigned V_18 , int V_20 )
{
struct V_1 * V_2 = F_22 ( V_17 -> V_11 ) ;
F_8 ( V_2 , V_20 ? V_21 : V_22 , V_18 ) ;
}
static int F_26 ( struct V_16 * V_17 , unsigned V_18 )
{
struct V_1 * V_2 = F_22 ( V_17 -> V_11 ) ;
return F_27 ( V_2 -> V_23 , V_18 ) ;
}
static T_2 F_28 ( int V_24 , void * V_25 )
{
struct V_26 * V_27 = V_25 ;
struct V_1 * V_2 = V_27 -> V_2 ;
int V_28 = V_27 -> V_28 ;
unsigned long V_29 ;
unsigned V_18 ;
unsigned V_30 ;
unsigned int type ;
V_29 = F_1 ( V_2 , V_31 + V_28 * 4 ) ;
V_29 &= V_2 -> V_32 [ V_28 ] ;
F_29 (offset, &events, 32 ) {
V_30 = ( 32 * V_28 ) + V_18 ;
type = V_2 -> V_33 [ V_30 ] ;
if ( ! ( type & V_34 ) )
F_8 ( V_2 , V_31 , V_30 ) ;
F_30 ( F_27 ( V_2 -> V_23 , V_30 ) ) ;
if ( type & V_34 )
F_8 ( V_2 , V_31 , V_30 ) ;
}
return V_29 ? V_35 : V_36 ;
}
static inline void F_31 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_18 , bool V_37 )
{
T_1 V_20 ;
V_3 += F_6 ( V_18 ) * 4 ;
V_20 = F_1 ( V_2 , V_3 ) ;
if ( V_37 )
V_20 |= F_9 ( F_7 ( V_18 ) ) ;
else
V_20 &= ~ ( F_9 ( F_7 ( V_18 ) ) ) ;
F_3 ( V_2 , V_3 , V_20 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
unsigned V_18 , bool V_37 )
{
switch ( V_2 -> V_33 [ V_18 ] ) {
case V_38 :
F_31 ( V_2 , V_39 , V_18 , V_37 ) ;
break;
case V_40 :
F_31 ( V_2 , V_41 , V_18 , V_37 ) ;
break;
case V_42 :
F_31 ( V_2 , V_39 , V_18 , V_37 ) ;
F_31 ( V_2 , V_41 , V_18 , V_37 ) ;
break;
case V_43 :
F_31 ( V_2 , V_44 , V_18 , V_37 ) ;
break;
case V_45 :
F_31 ( V_2 , V_46 , V_18 , V_37 ) ;
break;
}
}
static void F_33 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_34 ( V_48 ) ;
unsigned V_30 = F_35 ( V_48 ) ;
unsigned V_18 = F_7 ( V_30 ) ;
unsigned V_28 = F_6 ( V_30 ) ;
unsigned long V_49 ;
F_36 ( & V_2 -> V_50 [ V_28 ] , V_49 ) ;
F_37 ( V_18 , & V_2 -> V_32 [ V_28 ] ) ;
F_32 ( V_2 , V_30 , true ) ;
F_38 ( & V_2 -> V_50 [ V_28 ] , V_49 ) ;
}
static void F_39 ( struct V_47 * V_48 )
{
struct V_1 * V_2 = F_34 ( V_48 ) ;
unsigned V_30 = F_35 ( V_48 ) ;
unsigned V_18 = F_7 ( V_30 ) ;
unsigned V_28 = F_6 ( V_30 ) ;
unsigned long V_49 ;
F_36 ( & V_2 -> V_50 [ V_28 ] , V_49 ) ;
F_32 ( V_2 , V_30 , false ) ;
F_40 ( V_18 , & V_2 -> V_32 [ V_28 ] ) ;
F_38 ( & V_2 -> V_50 [ V_28 ] , V_49 ) ;
}
static int F_41 ( struct V_1 * V_2 ,
unsigned V_18 , unsigned int type )
{
switch ( type ) {
case V_51 :
case V_38 :
case V_40 :
case V_42 :
case V_43 :
case V_45 :
V_2 -> V_33 [ V_18 ] = type ;
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
unsigned V_18 , unsigned int type )
{
switch ( type ) {
case V_51 :
if ( V_2 -> V_33 [ V_18 ] != type ) {
F_32 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
}
break;
case V_38 :
if ( V_2 -> V_33 [ V_18 ] == V_42 ) {
V_2 -> V_33 [ V_18 ] = V_40 ;
F_32 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
} else if ( V_2 -> V_33 [ V_18 ] != type ) {
F_32 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
F_32 ( V_2 , V_18 , true ) ;
}
break;
case V_40 :
if ( V_2 -> V_33 [ V_18 ] == V_42 ) {
V_2 -> V_33 [ V_18 ] = V_38 ;
F_32 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
} else if ( V_2 -> V_33 [ V_18 ] != type ) {
F_32 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
F_32 ( V_2 , V_18 , true ) ;
}
break;
case V_42 :
if ( V_2 -> V_33 [ V_18 ] == V_38 ) {
V_2 -> V_33 [ V_18 ] = V_40 ;
F_32 ( V_2 , V_18 , true ) ;
V_2 -> V_33 [ V_18 ] = type ;
} else if ( V_2 -> V_33 [ V_18 ] == V_40 ) {
V_2 -> V_33 [ V_18 ] = V_38 ;
F_32 ( V_2 , V_18 , true ) ;
V_2 -> V_33 [ V_18 ] = type ;
} else if ( V_2 -> V_33 [ V_18 ] != type ) {
F_32 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
F_32 ( V_2 , V_18 , true ) ;
}
break;
case V_43 :
case V_45 :
if ( V_2 -> V_33 [ V_18 ] != type ) {
F_32 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
F_32 ( V_2 , V_18 , true ) ;
}
break;
default:
return - V_52 ;
}
return 0 ;
}
static int F_43 ( struct V_47 * V_48 , unsigned int type )
{
struct V_1 * V_2 = F_34 ( V_48 ) ;
unsigned V_30 = F_35 ( V_48 ) ;
unsigned V_18 = F_7 ( V_30 ) ;
unsigned V_28 = F_6 ( V_30 ) ;
unsigned long V_49 ;
int V_53 ;
F_36 ( & V_2 -> V_50 [ V_28 ] , V_49 ) ;
if ( F_44 ( V_18 , & V_2 -> V_32 [ V_28 ] ) )
V_53 = F_42 ( V_2 , V_30 , type ) ;
else
V_53 = F_41 ( V_2 , V_30 , type ) ;
F_38 ( & V_2 -> V_50 [ V_28 ] , V_49 ) ;
return V_53 ;
}
static int F_45 ( struct V_54 * V_55 )
{
return F_46 ( V_56 ) ;
}
static const char * F_47 ( struct V_54 * V_55 ,
unsigned V_57 )
{
return V_56 [ V_57 ] ;
}
static int F_48 ( struct V_54 * V_55 ,
unsigned V_57 ,
const unsigned * * V_58 ,
unsigned * V_59 )
{
* V_58 = & V_60 [ V_57 ] . V_61 ;
* V_59 = 1 ;
return 0 ;
}
static void F_49 ( struct V_54 * V_55 ,
struct V_62 * V_63 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_50 ( V_55 ) ;
enum V_7 V_13 = F_10 ( V_2 , V_18 ) ;
const char * V_64 = V_12 [ V_13 ] ;
int V_20 = F_5 ( V_2 , V_19 , V_18 ) ;
int V_24 = F_51 ( V_2 -> V_23 , V_18 ) ;
F_52 ( V_63 , L_5 ,
V_64 , V_20 ? L_6 : L_7 ,
V_24 , V_65 [ V_2 -> V_33 [ V_18 ] ] ) ;
}
static void F_53 ( struct V_54 * V_55 ,
struct V_66 * V_67 , unsigned V_68 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ )
if ( V_67 [ V_69 ] . type == V_70 )
F_54 ( V_67 [ V_69 ] . V_48 . V_71 . V_71 ) ;
F_54 ( V_67 ) ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_72 * V_73 , T_1 V_8 , T_1 V_74 ,
struct V_66 * * V_67 )
{
struct V_66 * V_75 = * V_67 ;
if ( V_74 >= F_46 ( V_12 ) ) {
F_56 ( V_2 -> V_11 , L_8 ,
F_57 ( V_73 ) , V_74 ) ;
return - V_52 ;
}
V_75 -> type = V_76 ;
V_75 -> V_48 . V_77 . V_78 = V_56 [ V_8 ] ;
V_75 -> V_48 . V_77 . V_79 = V_12 [ V_74 ] ;
( * V_67 ) ++ ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_72 * V_73 , T_1 V_8 , T_1 V_80 ,
struct V_66 * * V_67 )
{
struct V_66 * V_75 = * V_67 ;
unsigned long * V_71 ;
if ( V_80 > 2 ) {
F_56 ( V_2 -> V_11 , L_9 ,
F_57 ( V_73 ) , V_80 ) ;
return - V_52 ;
}
V_71 = F_59 ( sizeof( * V_71 ) , V_81 ) ;
if ( ! V_71 )
return - V_82 ;
V_71 [ 0 ] = F_60 ( V_83 , V_80 ) ;
V_75 -> type = V_70 ;
V_75 -> V_48 . V_71 . V_84 = V_60 [ V_8 ] . V_85 ;
V_75 -> V_48 . V_71 . V_71 = V_71 ;
V_75 -> V_48 . V_71 . V_86 = 1 ;
( * V_67 ) ++ ;
return 0 ;
}
static inline T_1 F_61 ( struct V_87 * V_88 , int V_69 )
{
return F_62 ( ( ( V_89 * ) V_88 -> V_20 ) + V_69 ) ;
}
static int F_63 ( struct V_54 * V_55 ,
struct V_72 * V_73 ,
struct V_66 * * V_75 , unsigned * V_68 )
{
struct V_1 * V_2 = F_50 ( V_55 ) ;
struct V_87 * V_58 , * V_90 , * V_91 ;
int V_59 , V_92 , V_93 , V_94 ;
struct V_66 * V_67 , * V_95 ;
int V_69 , V_96 ;
T_1 V_8 , V_97 , V_80 ;
V_58 = F_64 ( V_73 , L_10 , NULL ) ;
if ( ! V_58 ) {
F_56 ( V_2 -> V_11 , L_11 ,
F_57 ( V_73 ) ) ;
return - V_52 ;
}
V_90 = F_64 ( V_73 , L_12 , NULL ) ;
V_91 = F_64 ( V_73 , L_13 , NULL ) ;
if ( ! V_90 && ! V_91 ) {
F_56 ( V_2 -> V_11 ,
L_14 ,
F_57 ( V_73 ) ) ;
return - V_52 ;
}
V_59 = V_58 -> V_98 / 4 ;
V_92 = V_90 ? ( V_90 -> V_98 / 4 ) : 0 ;
V_93 = V_91 ? ( V_91 -> V_98 / 4 ) : 0 ;
if ( V_92 > 1 && V_92 != V_59 ) {
F_56 ( V_2 -> V_11 ,
L_15 ,
F_57 ( V_73 ) , V_59 ) ;
return - V_52 ;
}
if ( V_93 > 1 && V_93 != V_59 ) {
F_56 ( V_2 -> V_11 ,
L_16 ,
F_57 ( V_73 ) , V_59 ) ;
return - V_52 ;
}
V_94 = 0 ;
if ( V_92 )
V_94 ++ ;
if ( V_93 )
V_94 ++ ;
V_95 = V_67 = F_59 ( V_59 * V_94 * sizeof( * V_67 ) ,
V_81 ) ;
if ( ! V_67 )
return - V_82 ;
for ( V_69 = 0 ; V_69 < V_59 ; V_69 ++ ) {
V_8 = F_61 ( V_58 , V_69 ) ;
if ( V_8 >= F_46 ( V_60 ) ) {
F_56 ( V_2 -> V_11 , L_17 ,
F_57 ( V_73 ) , V_8 ) ;
V_96 = - V_52 ;
goto V_99;
}
if ( V_92 ) {
V_97 = F_61 ( V_90 , ( V_92 > 1 ) ? V_69 : 0 ) ;
V_96 = F_55 ( V_2 , V_73 , V_8 ,
V_97 , & V_95 ) ;
if ( V_96 )
goto V_99;
}
if ( V_93 ) {
V_80 = F_61 ( V_91 , ( V_93 > 1 ) ? V_69 : 0 ) ;
V_96 = F_58 ( V_2 , V_73 , V_8 ,
V_80 , & V_95 ) ;
if ( V_96 )
goto V_99;
}
}
* V_75 = V_67 ;
* V_68 = V_59 * V_94 ;
return 0 ;
V_99:
F_54 ( V_67 ) ;
return V_96 ;
}
static int F_65 ( struct V_54 * V_55 )
{
return V_100 ;
}
static const char * F_66 ( struct V_54 * V_55 ,
unsigned V_57 )
{
return V_12 [ V_57 ] ;
}
static int F_67 ( struct V_54 * V_55 ,
unsigned V_57 ,
const char * const * * V_101 ,
unsigned * const V_102 )
{
* V_101 = V_56 ;
* V_102 = F_46 ( V_56 ) ;
return 0 ;
}
static int F_68 ( struct V_54 * V_55 ,
unsigned V_103 ,
unsigned V_104 )
{
struct V_1 * V_2 = F_50 ( V_55 ) ;
F_14 ( V_2 , V_104 , V_103 ) ;
return 0 ;
}
static void F_69 ( struct V_54 * V_55 ,
unsigned V_103 ,
unsigned V_104 )
{
struct V_1 * V_2 = F_50 ( V_55 ) ;
F_14 ( V_2 , V_104 , V_15 ) ;
}
static void F_70 ( struct V_54 * V_55 ,
struct V_105 * V_106 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_50 ( V_55 ) ;
F_14 ( V_2 , V_18 , V_15 ) ;
}
static int F_71 ( struct V_54 * V_55 ,
struct V_105 * V_106 ,
unsigned V_18 ,
bool V_107 )
{
struct V_1 * V_2 = F_50 ( V_55 ) ;
enum V_7 V_13 = V_107 ?
V_15 : V_108 ;
F_14 ( V_2 , V_18 , V_13 ) ;
return 0 ;
}
static int F_72 ( struct V_54 * V_55 ,
unsigned V_8 , unsigned long * V_109 )
{
return - V_110 ;
}
static int F_73 ( struct V_54 * V_55 ,
unsigned V_8 , unsigned long V_109 )
{
struct V_1 * V_2 = F_50 ( V_55 ) ;
enum V_111 V_112 = F_74 ( V_109 ) ;
T_3 V_113 = F_75 ( V_109 ) ;
T_1 V_114 , V_6 ;
if ( V_112 != V_83 )
return - V_52 ;
V_114 = F_6 ( V_8 ) ;
V_6 = F_7 ( V_8 ) ;
F_3 ( V_2 , V_115 , V_113 & 3 ) ;
F_76 ( 150 ) ;
F_3 ( V_2 , V_116 + ( V_114 * 4 ) , F_9 ( V_6 ) ) ;
F_76 ( 150 ) ;
F_3 ( V_2 , V_116 + ( V_114 * 4 ) , 0 ) ;
return 0 ;
}
static int F_77 ( struct V_117 * V_118 )
{
struct V_119 * V_11 = & V_118 -> V_11 ;
struct V_72 * V_73 = V_11 -> V_120 ;
struct V_1 * V_2 ;
struct V_121 V_122 ;
int V_96 , V_69 ;
F_78 ( F_46 ( V_60 ) != V_123 ) ;
F_78 ( F_46 ( V_56 ) != V_123 ) ;
V_2 = F_79 ( V_11 , sizeof( * V_2 ) , V_81 ) ;
if ( ! V_2 )
return - V_82 ;
F_80 ( V_118 , V_2 ) ;
V_2 -> V_11 = V_11 ;
V_96 = F_81 ( V_73 , 0 , & V_122 ) ;
if ( V_96 ) {
F_56 ( V_11 , L_18 ) ;
return V_96 ;
}
V_2 -> V_4 = F_82 ( V_11 , & V_122 ) ;
if ( F_83 ( V_2 -> V_4 ) )
return F_84 ( V_2 -> V_4 ) ;
V_2 -> V_16 = V_124 ;
V_2 -> V_16 . V_11 = V_11 ;
V_2 -> V_16 . V_120 = V_73 ;
V_2 -> V_23 = F_85 ( V_73 , V_123 ,
& V_125 , NULL ) ;
if ( ! V_2 -> V_23 ) {
F_56 ( V_11 , L_19 ) ;
return - V_82 ;
}
for ( V_69 = 0 ; V_69 < V_123 ; V_69 ++ ) {
int V_24 = F_86 ( V_2 -> V_23 , V_69 ) ;
F_87 ( V_24 , & V_126 ) ;
F_88 ( V_24 , & V_127 ,
V_128 ) ;
F_89 ( V_24 , V_2 ) ;
F_90 ( V_24 , V_129 ) ;
}
for ( V_69 = 0 ; V_69 < V_130 ; V_69 ++ ) {
unsigned long V_29 ;
unsigned V_18 ;
int V_131 ;
char * V_85 ;
F_3 ( V_2 , V_39 + V_69 * 4 , 0 ) ;
F_3 ( V_2 , V_41 + V_69 * 4 , 0 ) ;
F_3 ( V_2 , V_44 + V_69 * 4 , 0 ) ;
F_3 ( V_2 , V_46 + V_69 * 4 , 0 ) ;
F_3 ( V_2 , V_132 + V_69 * 4 , 0 ) ;
F_3 ( V_2 , V_133 + V_69 * 4 , 0 ) ;
V_29 = F_1 ( V_2 , V_31 + V_69 * 4 ) ;
F_29 (offset, &events, 32 )
F_3 ( V_2 , V_31 + V_69 * 4 , F_9 ( V_18 ) ) ;
V_2 -> V_24 [ V_69 ] = F_91 ( V_73 , V_69 ) ;
V_2 -> V_47 [ V_69 ] . V_2 = V_2 ;
V_2 -> V_47 [ V_69 ] . V_28 = V_69 ;
F_92 ( & V_2 -> V_50 [ V_69 ] ) ;
V_131 = strlen ( F_93 ( V_2 -> V_11 ) ) + 16 ;
V_85 = F_79 ( V_2 -> V_11 , V_131 , V_81 ) ;
if ( ! V_85 )
return - V_82 ;
snprintf ( V_85 , V_131 , L_20 , F_93 ( V_2 -> V_11 ) , V_69 ) ;
V_96 = F_94 ( V_11 , V_2 -> V_24 [ V_69 ] ,
F_28 , V_134 ,
V_85 , & V_2 -> V_47 [ V_69 ] ) ;
if ( V_96 ) {
F_56 ( V_11 , L_21 , V_2 -> V_24 [ V_69 ] ) ;
return V_96 ;
}
}
V_96 = F_95 ( & V_2 -> V_16 ) ;
if ( V_96 ) {
F_56 ( V_11 , L_22 ) ;
return V_96 ;
}
V_2 -> V_135 = F_96 ( & V_136 , V_11 , V_2 ) ;
if ( ! V_2 -> V_135 ) {
F_97 ( & V_2 -> V_16 ) ;
return - V_52 ;
}
V_2 -> V_137 = V_138 ;
V_2 -> V_137 . V_4 = V_2 -> V_16 . V_4 ;
V_2 -> V_137 . V_139 = & V_2 -> V_16 ;
F_98 ( V_2 -> V_135 , & V_2 -> V_137 ) ;
return 0 ;
}
static int F_99 ( struct V_117 * V_118 )
{
struct V_1 * V_2 = F_100 ( V_118 ) ;
F_101 ( V_2 -> V_135 ) ;
F_97 ( & V_2 -> V_16 ) ;
return 0 ;
}
