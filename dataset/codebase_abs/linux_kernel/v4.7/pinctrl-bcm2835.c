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
static int F_17 ( struct V_16 * V_17 , unsigned V_18 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
return F_5 ( V_2 , V_19 , V_18 ) ;
}
static int F_19 ( struct V_16 * V_17 , unsigned int V_18 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
enum V_7 V_13 = F_10 ( V_2 , V_18 ) ;
if ( V_13 > V_20 )
return - V_21 ;
return ( V_13 == V_15 ) ;
}
static void F_20 ( struct V_16 * V_17 , unsigned V_18 , int V_22 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
F_8 ( V_2 , V_22 ? V_23 : V_24 , V_18 ) ;
}
static int F_21 ( struct V_16 * V_17 ,
unsigned V_18 , int V_22 )
{
F_20 ( V_17 , V_18 , V_22 ) ;
return F_22 ( V_17 -> V_4 + V_18 ) ;
}
static int F_23 ( struct V_16 * V_17 , unsigned V_18 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
return F_24 ( V_2 -> V_25 , V_18 ) ;
}
static T_2 F_25 ( int V_26 , void * V_27 )
{
struct V_28 * V_29 = V_27 ;
struct V_1 * V_2 = V_29 -> V_2 ;
int V_30 = V_29 -> V_30 ;
unsigned long V_31 ;
unsigned V_18 ;
unsigned V_32 ;
unsigned int type ;
V_31 = F_1 ( V_2 , V_33 + V_30 * 4 ) ;
V_31 &= V_2 -> V_34 [ V_30 ] ;
F_26 (offset, &events, 32 ) {
V_32 = ( 32 * V_30 ) + V_18 ;
type = V_2 -> V_35 [ V_32 ] ;
F_27 ( F_24 ( V_2 -> V_25 , V_32 ) ) ;
}
return V_31 ? V_36 : V_37 ;
}
static inline void F_28 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_18 , bool V_38 )
{
T_1 V_22 ;
V_3 += F_6 ( V_18 ) * 4 ;
V_22 = F_1 ( V_2 , V_3 ) ;
if ( V_38 )
V_22 |= F_9 ( F_7 ( V_18 ) ) ;
else
V_22 &= ~ ( F_9 ( F_7 ( V_18 ) ) ) ;
F_3 ( V_2 , V_3 , V_22 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
unsigned V_18 , bool V_38 )
{
switch ( V_2 -> V_35 [ V_18 ] ) {
case V_39 :
F_28 ( V_2 , V_40 , V_18 , V_38 ) ;
break;
case V_41 :
F_28 ( V_2 , V_42 , V_18 , V_38 ) ;
break;
case V_43 :
F_28 ( V_2 , V_40 , V_18 , V_38 ) ;
F_28 ( V_2 , V_42 , V_18 , V_38 ) ;
break;
case V_44 :
F_28 ( V_2 , V_45 , V_18 , V_38 ) ;
break;
case V_46 :
F_28 ( V_2 , V_47 , V_18 , V_38 ) ;
break;
}
}
static void F_30 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_31 ( V_49 ) ;
unsigned V_32 = F_32 ( V_49 ) ;
unsigned V_18 = F_7 ( V_32 ) ;
unsigned V_30 = F_6 ( V_32 ) ;
unsigned long V_50 ;
F_33 ( & V_2 -> V_51 [ V_30 ] , V_50 ) ;
F_34 ( V_18 , & V_2 -> V_34 [ V_30 ] ) ;
F_29 ( V_2 , V_32 , true ) ;
F_35 ( & V_2 -> V_51 [ V_30 ] , V_50 ) ;
}
static void F_36 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_31 ( V_49 ) ;
unsigned V_32 = F_32 ( V_49 ) ;
unsigned V_18 = F_7 ( V_32 ) ;
unsigned V_30 = F_6 ( V_32 ) ;
unsigned long V_50 ;
F_33 ( & V_2 -> V_51 [ V_30 ] , V_50 ) ;
F_29 ( V_2 , V_32 , false ) ;
F_8 ( V_2 , V_33 , V_32 ) ;
F_37 ( V_18 , & V_2 -> V_34 [ V_30 ] ) ;
F_35 ( & V_2 -> V_51 [ V_30 ] , V_50 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
unsigned V_18 , unsigned int type )
{
switch ( type ) {
case V_52 :
case V_39 :
case V_41 :
case V_43 :
case V_44 :
case V_46 :
V_2 -> V_35 [ V_18 ] = type ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
unsigned V_18 , unsigned int type )
{
switch ( type ) {
case V_52 :
if ( V_2 -> V_35 [ V_18 ] != type ) {
F_29 ( V_2 , V_18 , false ) ;
V_2 -> V_35 [ V_18 ] = type ;
}
break;
case V_39 :
if ( V_2 -> V_35 [ V_18 ] == V_43 ) {
V_2 -> V_35 [ V_18 ] = V_41 ;
F_29 ( V_2 , V_18 , false ) ;
V_2 -> V_35 [ V_18 ] = type ;
} else if ( V_2 -> V_35 [ V_18 ] != type ) {
F_29 ( V_2 , V_18 , false ) ;
V_2 -> V_35 [ V_18 ] = type ;
F_29 ( V_2 , V_18 , true ) ;
}
break;
case V_41 :
if ( V_2 -> V_35 [ V_18 ] == V_43 ) {
V_2 -> V_35 [ V_18 ] = V_39 ;
F_29 ( V_2 , V_18 , false ) ;
V_2 -> V_35 [ V_18 ] = type ;
} else if ( V_2 -> V_35 [ V_18 ] != type ) {
F_29 ( V_2 , V_18 , false ) ;
V_2 -> V_35 [ V_18 ] = type ;
F_29 ( V_2 , V_18 , true ) ;
}
break;
case V_43 :
if ( V_2 -> V_35 [ V_18 ] == V_39 ) {
V_2 -> V_35 [ V_18 ] = V_41 ;
F_29 ( V_2 , V_18 , true ) ;
V_2 -> V_35 [ V_18 ] = type ;
} else if ( V_2 -> V_35 [ V_18 ] == V_41 ) {
V_2 -> V_35 [ V_18 ] = V_39 ;
F_29 ( V_2 , V_18 , true ) ;
V_2 -> V_35 [ V_18 ] = type ;
} else if ( V_2 -> V_35 [ V_18 ] != type ) {
F_29 ( V_2 , V_18 , false ) ;
V_2 -> V_35 [ V_18 ] = type ;
F_29 ( V_2 , V_18 , true ) ;
}
break;
case V_44 :
case V_46 :
if ( V_2 -> V_35 [ V_18 ] != type ) {
F_29 ( V_2 , V_18 , false ) ;
V_2 -> V_35 [ V_18 ] = type ;
F_29 ( V_2 , V_18 , true ) ;
}
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_40 ( struct V_48 * V_49 , unsigned int type )
{
struct V_1 * V_2 = F_31 ( V_49 ) ;
unsigned V_32 = F_32 ( V_49 ) ;
unsigned V_18 = F_7 ( V_32 ) ;
unsigned V_30 = F_6 ( V_32 ) ;
unsigned long V_50 ;
int V_53 ;
F_33 ( & V_2 -> V_51 [ V_30 ] , V_50 ) ;
if ( F_41 ( V_18 , & V_2 -> V_34 [ V_30 ] ) )
V_53 = F_39 ( V_2 , V_32 , type ) ;
else
V_53 = F_38 ( V_2 , V_32 , type ) ;
if ( type & V_43 )
F_42 ( V_49 , V_54 ) ;
else
F_42 ( V_49 , V_55 ) ;
F_35 ( & V_2 -> V_51 [ V_30 ] , V_50 ) ;
return V_53 ;
}
static void F_43 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_31 ( V_49 ) ;
unsigned V_32 = F_32 ( V_49 ) ;
F_8 ( V_2 , V_33 , V_32 ) ;
}
static int F_44 ( struct V_56 * V_57 )
{
return F_45 ( V_58 ) ;
}
static const char * F_46 ( struct V_56 * V_57 ,
unsigned V_59 )
{
return V_58 [ V_59 ] ;
}
static int F_47 ( struct V_56 * V_57 ,
unsigned V_59 ,
const unsigned * * V_60 ,
unsigned * V_61 )
{
* V_60 = & V_62 [ V_59 ] . V_63 ;
* V_61 = 1 ;
return 0 ;
}
static void F_48 ( struct V_56 * V_57 ,
struct V_64 * V_65 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_49 ( V_57 ) ;
enum V_7 V_13 = F_10 ( V_2 , V_18 ) ;
const char * V_66 = V_12 [ V_13 ] ;
int V_22 = F_5 ( V_2 , V_19 , V_18 ) ;
int V_26 = F_50 ( V_2 -> V_25 , V_18 ) ;
F_51 ( V_65 , L_5 ,
V_66 , V_22 ? L_6 : L_7 ,
V_26 , V_67 [ V_2 -> V_35 [ V_18 ] ] ) ;
}
static void F_52 ( struct V_56 * V_57 ,
struct V_68 * V_69 , unsigned V_70 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_70 ; V_71 ++ )
if ( V_69 [ V_71 ] . type == V_72 )
F_53 ( V_69 [ V_71 ] . V_49 . V_73 . V_73 ) ;
F_53 ( V_69 ) ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_74 * V_75 , T_1 V_8 , T_1 V_76 ,
struct V_68 * * V_69 )
{
struct V_68 * V_77 = * V_69 ;
if ( V_76 >= F_45 ( V_12 ) ) {
F_55 ( V_2 -> V_11 , L_8 ,
F_56 ( V_75 ) , V_76 ) ;
return - V_21 ;
}
V_77 -> type = V_78 ;
V_77 -> V_49 . V_79 . V_80 = V_58 [ V_8 ] ;
V_77 -> V_49 . V_79 . V_81 = V_12 [ V_76 ] ;
( * V_69 ) ++ ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_74 * V_75 , T_1 V_8 , T_1 V_82 ,
struct V_68 * * V_69 )
{
struct V_68 * V_77 = * V_69 ;
unsigned long * V_73 ;
if ( V_82 > 2 ) {
F_55 ( V_2 -> V_11 , L_9 ,
F_56 ( V_75 ) , V_82 ) ;
return - V_21 ;
}
V_73 = F_58 ( sizeof( * V_73 ) , V_83 ) ;
if ( ! V_73 )
return - V_84 ;
V_73 [ 0 ] = F_59 ( V_85 , V_82 ) ;
V_77 -> type = V_72 ;
V_77 -> V_49 . V_73 . V_86 = V_62 [ V_8 ] . V_87 ;
V_77 -> V_49 . V_73 . V_73 = V_73 ;
V_77 -> V_49 . V_73 . V_88 = 1 ;
( * V_69 ) ++ ;
return 0 ;
}
static int F_60 ( struct V_56 * V_57 ,
struct V_74 * V_75 ,
struct V_68 * * V_77 , unsigned * V_70 )
{
struct V_1 * V_2 = F_49 ( V_57 ) ;
struct V_89 * V_60 , * V_90 , * V_91 ;
int V_61 , V_92 , V_93 , V_94 ;
struct V_68 * V_69 , * V_95 ;
int V_71 , V_96 ;
T_1 V_8 , V_97 , V_82 ;
V_60 = F_61 ( V_75 , L_10 , NULL ) ;
if ( ! V_60 ) {
F_55 ( V_2 -> V_11 , L_11 ,
F_56 ( V_75 ) ) ;
return - V_21 ;
}
V_90 = F_61 ( V_75 , L_12 , NULL ) ;
V_91 = F_61 ( V_75 , L_13 , NULL ) ;
if ( ! V_90 && ! V_91 ) {
F_55 ( V_2 -> V_11 ,
L_14 ,
F_56 ( V_75 ) ) ;
return - V_21 ;
}
V_61 = V_60 -> V_98 / 4 ;
V_92 = V_90 ? ( V_90 -> V_98 / 4 ) : 0 ;
V_93 = V_91 ? ( V_91 -> V_98 / 4 ) : 0 ;
if ( V_92 > 1 && V_92 != V_61 ) {
F_55 ( V_2 -> V_11 ,
L_15 ,
F_56 ( V_75 ) , V_61 ) ;
return - V_21 ;
}
if ( V_93 > 1 && V_93 != V_61 ) {
F_55 ( V_2 -> V_11 ,
L_16 ,
F_56 ( V_75 ) , V_61 ) ;
return - V_21 ;
}
V_94 = 0 ;
if ( V_92 )
V_94 ++ ;
if ( V_93 )
V_94 ++ ;
V_95 = V_69 = F_58 ( V_61 * V_94 * sizeof( * V_69 ) ,
V_83 ) ;
if ( ! V_69 )
return - V_84 ;
for ( V_71 = 0 ; V_71 < V_61 ; V_71 ++ ) {
V_96 = F_62 ( V_75 , L_10 , V_71 , & V_8 ) ;
if ( V_96 )
goto V_99;
if ( V_8 >= F_45 ( V_62 ) ) {
F_55 ( V_2 -> V_11 , L_17 ,
F_56 ( V_75 ) , V_8 ) ;
V_96 = - V_21 ;
goto V_99;
}
if ( V_92 ) {
V_96 = F_62 ( V_75 , L_12 ,
( V_92 > 1 ) ? V_71 : 0 , & V_97 ) ;
if ( V_96 )
goto V_99;
V_96 = F_54 ( V_2 , V_75 , V_8 ,
V_97 , & V_95 ) ;
if ( V_96 )
goto V_99;
}
if ( V_93 ) {
V_96 = F_62 ( V_75 , L_13 ,
( V_93 > 1 ) ? V_71 : 0 , & V_82 ) ;
if ( V_96 )
goto V_99;
V_96 = F_57 ( V_2 , V_75 , V_8 ,
V_82 , & V_95 ) ;
if ( V_96 )
goto V_99;
}
}
* V_77 = V_69 ;
* V_70 = V_61 * V_94 ;
return 0 ;
V_99:
F_52 ( V_57 , V_69 , V_61 * V_94 ) ;
return V_96 ;
}
static int F_63 ( struct V_56 * V_57 )
{
return V_100 ;
}
static const char * F_64 ( struct V_56 * V_57 ,
unsigned V_59 )
{
return V_12 [ V_59 ] ;
}
static int F_65 ( struct V_56 * V_57 ,
unsigned V_59 ,
const char * const * * V_101 ,
unsigned * const V_102 )
{
* V_101 = V_58 ;
* V_102 = F_45 ( V_58 ) ;
return 0 ;
}
static int F_66 ( struct V_56 * V_57 ,
unsigned V_103 ,
unsigned V_104 )
{
struct V_1 * V_2 = F_49 ( V_57 ) ;
F_14 ( V_2 , V_104 , V_103 ) ;
return 0 ;
}
static void F_67 ( struct V_56 * V_57 ,
struct V_105 * V_106 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_49 ( V_57 ) ;
F_14 ( V_2 , V_18 , V_15 ) ;
}
static int F_68 ( struct V_56 * V_57 ,
struct V_105 * V_106 ,
unsigned V_18 ,
bool V_107 )
{
struct V_1 * V_2 = F_49 ( V_57 ) ;
enum V_7 V_13 = V_107 ?
V_15 : V_20 ;
F_14 ( V_2 , V_18 , V_13 ) ;
return 0 ;
}
static int F_69 ( struct V_56 * V_57 ,
unsigned V_8 , unsigned long * V_108 )
{
return - V_109 ;
}
static int F_70 ( struct V_56 * V_57 ,
unsigned V_8 , unsigned long * V_73 ,
unsigned V_88 )
{
struct V_1 * V_2 = F_49 ( V_57 ) ;
enum V_110 V_111 ;
T_3 V_112 ;
T_1 V_113 , V_6 ;
int V_71 ;
for ( V_71 = 0 ; V_71 < V_88 ; V_71 ++ ) {
V_111 = F_71 ( V_73 [ V_71 ] ) ;
V_112 = F_72 ( V_73 [ V_71 ] ) ;
if ( V_111 != V_85 )
return - V_21 ;
V_113 = F_6 ( V_8 ) ;
V_6 = F_7 ( V_8 ) ;
F_3 ( V_2 , V_114 , V_112 & 3 ) ;
F_73 ( 150 ) ;
F_3 ( V_2 , V_115 + ( V_113 * 4 ) , F_9 ( V_6 ) ) ;
F_73 ( 150 ) ;
F_3 ( V_2 , V_115 + ( V_113 * 4 ) , 0 ) ;
}
return 0 ;
}
static int F_74 ( struct V_116 * V_117 )
{
struct V_118 * V_11 = & V_117 -> V_11 ;
struct V_74 * V_75 = V_11 -> V_119 ;
struct V_1 * V_2 ;
struct V_120 V_121 ;
int V_96 , V_71 ;
F_75 ( F_45 ( V_62 ) != V_122 ) ;
F_75 ( F_45 ( V_58 ) != V_122 ) ;
V_2 = F_76 ( V_11 , sizeof( * V_2 ) , V_83 ) ;
if ( ! V_2 )
return - V_84 ;
F_77 ( V_117 , V_2 ) ;
V_2 -> V_11 = V_11 ;
V_96 = F_78 ( V_75 , 0 , & V_121 ) ;
if ( V_96 ) {
F_55 ( V_11 , L_18 ) ;
return V_96 ;
}
V_2 -> V_4 = F_79 ( V_11 , & V_121 ) ;
if ( F_80 ( V_2 -> V_4 ) )
return F_81 ( V_2 -> V_4 ) ;
V_2 -> V_16 = V_123 ;
V_2 -> V_16 . V_124 = V_11 ;
V_2 -> V_16 . V_119 = V_75 ;
V_2 -> V_25 = F_82 ( V_75 , V_122 ,
& V_125 , NULL ) ;
if ( ! V_2 -> V_25 ) {
F_55 ( V_11 , L_19 ) ;
return - V_84 ;
}
for ( V_71 = 0 ; V_71 < V_122 ; V_71 ++ ) {
int V_26 = F_83 ( V_2 -> V_25 , V_71 ) ;
F_84 ( V_26 , & V_126 ) ;
F_85 ( V_26 , & V_127 ,
V_55 ) ;
F_86 ( V_26 , V_2 ) ;
}
for ( V_71 = 0 ; V_71 < V_128 ; V_71 ++ ) {
unsigned long V_31 ;
unsigned V_18 ;
int V_129 ;
char * V_87 ;
F_3 ( V_2 , V_40 + V_71 * 4 , 0 ) ;
F_3 ( V_2 , V_42 + V_71 * 4 , 0 ) ;
F_3 ( V_2 , V_45 + V_71 * 4 , 0 ) ;
F_3 ( V_2 , V_47 + V_71 * 4 , 0 ) ;
F_3 ( V_2 , V_130 + V_71 * 4 , 0 ) ;
F_3 ( V_2 , V_131 + V_71 * 4 , 0 ) ;
V_31 = F_1 ( V_2 , V_33 + V_71 * 4 ) ;
F_26 (offset, &events, 32 )
F_3 ( V_2 , V_33 + V_71 * 4 , F_9 ( V_18 ) ) ;
V_2 -> V_26 [ V_71 ] = F_87 ( V_75 , V_71 ) ;
V_2 -> V_48 [ V_71 ] . V_2 = V_2 ;
V_2 -> V_48 [ V_71 ] . V_30 = V_71 ;
F_88 ( & V_2 -> V_51 [ V_71 ] ) ;
V_129 = strlen ( F_89 ( V_2 -> V_11 ) ) + 16 ;
V_87 = F_76 ( V_2 -> V_11 , V_129 , V_83 ) ;
if ( ! V_87 )
return - V_84 ;
snprintf ( V_87 , V_129 , L_20 , F_89 ( V_2 -> V_11 ) , V_71 ) ;
V_96 = F_90 ( V_11 , V_2 -> V_26 [ V_71 ] ,
F_25 , V_132 ,
V_87 , & V_2 -> V_48 [ V_71 ] ) ;
if ( V_96 ) {
F_55 ( V_11 , L_21 , V_2 -> V_26 [ V_71 ] ) ;
return V_96 ;
}
}
V_96 = F_91 ( & V_2 -> V_16 , V_2 ) ;
if ( V_96 ) {
F_55 ( V_11 , L_22 ) ;
return V_96 ;
}
V_2 -> V_133 = F_92 ( V_11 , & V_134 , V_2 ) ;
if ( F_80 ( V_2 -> V_133 ) ) {
F_93 ( & V_2 -> V_16 ) ;
return F_81 ( V_2 -> V_133 ) ;
}
V_2 -> V_135 = V_136 ;
V_2 -> V_135 . V_4 = V_2 -> V_16 . V_4 ;
V_2 -> V_135 . V_137 = & V_2 -> V_16 ;
F_94 ( V_2 -> V_133 , & V_2 -> V_135 ) ;
return 0 ;
}
static int F_95 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = F_96 ( V_117 ) ;
F_93 ( & V_2 -> V_16 ) ;
return 0 ;
}
