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
static void F_23 ( struct V_1 * V_2 ,
unsigned int V_25 , T_1 V_26 )
{
unsigned long V_27 ;
unsigned V_18 ;
unsigned V_28 ;
V_27 = F_1 ( V_2 , V_29 + V_25 * 4 ) ;
V_27 &= V_26 ;
V_27 &= V_2 -> V_30 [ V_25 ] ;
F_24 (offset, &events, 32 ) {
V_28 = ( 32 * V_25 ) + V_18 ;
F_25 ( F_26 ( V_2 -> V_16 . V_31 ,
V_28 ) ) ;
}
}
static void F_27 ( struct V_32 * V_33 )
{
struct V_16 * V_17 = F_28 ( V_33 ) ;
struct V_1 * V_2 = F_18 ( V_17 ) ;
struct V_34 * V_35 = F_29 ( V_33 ) ;
int V_36 = F_30 ( V_33 ) ;
int V_37 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < F_31 ( V_2 -> V_36 ) ; V_38 ++ ) {
if ( V_2 -> V_36 [ V_38 ] == V_36 ) {
V_37 = V_38 ;
break;
}
}
if ( V_38 == F_31 ( V_2 -> V_36 ) )
F_32 () ;
F_33 ( V_35 , V_33 ) ;
switch ( V_37 ) {
case 0 :
F_23 ( V_2 , 0 , 0x0fffffff ) ;
break;
case 1 :
F_23 ( V_2 , 0 , 0xf0000000 ) ;
F_23 ( V_2 , 1 , 0x00003fff ) ;
break;
case 2 :
F_23 ( V_2 , 1 , 0x003fc000 ) ;
break;
}
F_34 ( V_35 , V_33 ) ;
}
static inline void F_35 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_18 , bool V_39 )
{
T_1 V_22 ;
V_3 += F_6 ( V_18 ) * 4 ;
V_22 = F_1 ( V_2 , V_3 ) ;
if ( V_39 )
V_22 |= F_9 ( F_7 ( V_18 ) ) ;
else
V_22 &= ~ ( F_9 ( F_7 ( V_18 ) ) ) ;
F_3 ( V_2 , V_3 , V_22 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
unsigned V_18 , bool V_39 )
{
switch ( V_2 -> V_40 [ V_18 ] ) {
case V_41 :
F_35 ( V_2 , V_42 , V_18 , V_39 ) ;
break;
case V_43 :
F_35 ( V_2 , V_44 , V_18 , V_39 ) ;
break;
case V_45 :
F_35 ( V_2 , V_42 , V_18 , V_39 ) ;
F_35 ( V_2 , V_44 , V_18 , V_39 ) ;
break;
case V_46 :
F_35 ( V_2 , V_47 , V_18 , V_39 ) ;
break;
case V_48 :
F_35 ( V_2 , V_49 , V_18 , V_39 ) ;
break;
}
}
static void F_37 ( struct V_50 * V_51 )
{
struct V_16 * V_17 = F_38 ( V_51 ) ;
struct V_1 * V_2 = F_18 ( V_17 ) ;
unsigned V_28 = F_39 ( V_51 ) ;
unsigned V_18 = F_7 ( V_28 ) ;
unsigned V_25 = F_6 ( V_28 ) ;
unsigned long V_52 ;
F_40 ( & V_2 -> V_53 [ V_25 ] , V_52 ) ;
F_41 ( V_18 , & V_2 -> V_30 [ V_25 ] ) ;
F_36 ( V_2 , V_28 , true ) ;
F_42 ( & V_2 -> V_53 [ V_25 ] , V_52 ) ;
}
static void F_43 ( struct V_50 * V_51 )
{
struct V_16 * V_17 = F_38 ( V_51 ) ;
struct V_1 * V_2 = F_18 ( V_17 ) ;
unsigned V_28 = F_39 ( V_51 ) ;
unsigned V_18 = F_7 ( V_28 ) ;
unsigned V_25 = F_6 ( V_28 ) ;
unsigned long V_52 ;
F_40 ( & V_2 -> V_53 [ V_25 ] , V_52 ) ;
F_36 ( V_2 , V_28 , false ) ;
F_8 ( V_2 , V_29 , V_28 ) ;
F_44 ( V_18 , & V_2 -> V_30 [ V_25 ] ) ;
F_42 ( & V_2 -> V_53 [ V_25 ] , V_52 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
unsigned V_18 , unsigned int type )
{
switch ( type ) {
case V_54 :
case V_41 :
case V_43 :
case V_45 :
case V_46 :
case V_48 :
V_2 -> V_40 [ V_18 ] = type ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
unsigned V_18 , unsigned int type )
{
switch ( type ) {
case V_54 :
if ( V_2 -> V_40 [ V_18 ] != type ) {
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_40 [ V_18 ] = type ;
}
break;
case V_41 :
if ( V_2 -> V_40 [ V_18 ] == V_45 ) {
V_2 -> V_40 [ V_18 ] = V_43 ;
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_40 [ V_18 ] = type ;
} else if ( V_2 -> V_40 [ V_18 ] != type ) {
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_40 [ V_18 ] = type ;
F_36 ( V_2 , V_18 , true ) ;
}
break;
case V_43 :
if ( V_2 -> V_40 [ V_18 ] == V_45 ) {
V_2 -> V_40 [ V_18 ] = V_41 ;
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_40 [ V_18 ] = type ;
} else if ( V_2 -> V_40 [ V_18 ] != type ) {
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_40 [ V_18 ] = type ;
F_36 ( V_2 , V_18 , true ) ;
}
break;
case V_45 :
if ( V_2 -> V_40 [ V_18 ] == V_41 ) {
V_2 -> V_40 [ V_18 ] = V_43 ;
F_36 ( V_2 , V_18 , true ) ;
V_2 -> V_40 [ V_18 ] = type ;
} else if ( V_2 -> V_40 [ V_18 ] == V_43 ) {
V_2 -> V_40 [ V_18 ] = V_41 ;
F_36 ( V_2 , V_18 , true ) ;
V_2 -> V_40 [ V_18 ] = type ;
} else if ( V_2 -> V_40 [ V_18 ] != type ) {
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_40 [ V_18 ] = type ;
F_36 ( V_2 , V_18 , true ) ;
}
break;
case V_46 :
case V_48 :
if ( V_2 -> V_40 [ V_18 ] != type ) {
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_40 [ V_18 ] = type ;
F_36 ( V_2 , V_18 , true ) ;
}
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_47 ( struct V_50 * V_51 , unsigned int type )
{
struct V_16 * V_17 = F_38 ( V_51 ) ;
struct V_1 * V_2 = F_18 ( V_17 ) ;
unsigned V_28 = F_39 ( V_51 ) ;
unsigned V_18 = F_7 ( V_28 ) ;
unsigned V_25 = F_6 ( V_28 ) ;
unsigned long V_52 ;
int V_55 ;
F_40 ( & V_2 -> V_53 [ V_25 ] , V_52 ) ;
if ( F_48 ( V_18 , & V_2 -> V_30 [ V_25 ] ) )
V_55 = F_46 ( V_2 , V_28 , type ) ;
else
V_55 = F_45 ( V_2 , V_28 , type ) ;
if ( type & V_45 )
F_49 ( V_51 , V_56 ) ;
else
F_49 ( V_51 , V_57 ) ;
F_42 ( & V_2 -> V_53 [ V_25 ] , V_52 ) ;
return V_55 ;
}
static void F_50 ( struct V_50 * V_51 )
{
struct V_16 * V_17 = F_38 ( V_51 ) ;
struct V_1 * V_2 = F_18 ( V_17 ) ;
unsigned V_28 = F_39 ( V_51 ) ;
F_8 ( V_2 , V_29 , V_28 ) ;
}
static int F_51 ( struct V_58 * V_59 )
{
return F_31 ( V_60 ) ;
}
static const char * F_52 ( struct V_58 * V_59 ,
unsigned V_61 )
{
return V_60 [ V_61 ] ;
}
static int F_53 ( struct V_58 * V_59 ,
unsigned V_61 ,
const unsigned * * V_62 ,
unsigned * V_63 )
{
* V_62 = & V_64 [ V_61 ] . V_65 ;
* V_63 = 1 ;
return 0 ;
}
static void F_54 ( struct V_58 * V_59 ,
struct V_66 * V_67 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_55 ( V_59 ) ;
struct V_16 * V_17 = & V_2 -> V_16 ;
enum V_7 V_13 = F_10 ( V_2 , V_18 ) ;
const char * V_68 = V_12 [ V_13 ] ;
int V_22 = F_5 ( V_2 , V_19 , V_18 ) ;
int V_36 = F_56 ( V_17 -> V_31 , V_18 ) ;
F_57 ( V_67 , L_5 ,
V_68 , V_22 ? L_6 : L_7 ,
V_36 , V_69 [ V_2 -> V_40 [ V_18 ] ] ) ;
}
static void F_58 ( struct V_58 * V_59 ,
struct V_70 * V_71 , unsigned V_72 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_72 ; V_38 ++ )
if ( V_71 [ V_38 ] . type == V_73 )
F_59 ( V_71 [ V_38 ] . V_51 . V_74 . V_74 ) ;
F_59 ( V_71 ) ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_75 * V_76 , T_1 V_8 , T_1 V_77 ,
struct V_70 * * V_71 )
{
struct V_70 * V_78 = * V_71 ;
if ( V_77 >= F_31 ( V_12 ) ) {
F_61 ( V_2 -> V_11 , L_8 , V_76 , V_77 ) ;
return - V_21 ;
}
V_78 -> type = V_79 ;
V_78 -> V_51 . V_80 . V_37 = V_60 [ V_8 ] ;
V_78 -> V_51 . V_80 . V_81 = V_12 [ V_77 ] ;
( * V_71 ) ++ ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
struct V_75 * V_76 , T_1 V_8 , T_1 V_82 ,
struct V_70 * * V_71 )
{
struct V_70 * V_78 = * V_71 ;
unsigned long * V_74 ;
if ( V_82 > 2 ) {
F_61 ( V_2 -> V_11 , L_9 , V_76 , V_82 ) ;
return - V_21 ;
}
V_74 = F_63 ( sizeof( * V_74 ) , V_83 ) ;
if ( ! V_74 )
return - V_84 ;
V_74 [ 0 ] = F_64 ( V_85 , V_82 ) ;
V_78 -> type = V_73 ;
V_78 -> V_51 . V_74 . V_86 = V_64 [ V_8 ] . V_87 ;
V_78 -> V_51 . V_74 . V_74 = V_74 ;
V_78 -> V_51 . V_74 . V_88 = 1 ;
( * V_71 ) ++ ;
return 0 ;
}
static int F_65 ( struct V_58 * V_59 ,
struct V_75 * V_76 ,
struct V_70 * * V_78 , unsigned * V_72 )
{
struct V_1 * V_2 = F_55 ( V_59 ) ;
struct V_89 * V_62 , * V_90 , * V_91 ;
int V_63 , V_92 , V_93 , V_94 ;
struct V_70 * V_71 , * V_95 ;
int V_38 , V_96 ;
T_1 V_8 , V_97 , V_82 ;
V_62 = F_66 ( V_76 , L_10 , NULL ) ;
if ( ! V_62 ) {
F_61 ( V_2 -> V_11 , L_11 , V_76 ) ;
return - V_21 ;
}
V_90 = F_66 ( V_76 , L_12 , NULL ) ;
V_91 = F_66 ( V_76 , L_13 , NULL ) ;
if ( ! V_90 && ! V_91 ) {
F_61 ( V_2 -> V_11 ,
L_14 ,
V_76 ) ;
return - V_21 ;
}
V_63 = V_62 -> V_98 / 4 ;
V_92 = V_90 ? ( V_90 -> V_98 / 4 ) : 0 ;
V_93 = V_91 ? ( V_91 -> V_98 / 4 ) : 0 ;
if ( V_92 > 1 && V_92 != V_63 ) {
F_61 ( V_2 -> V_11 ,
L_15 ,
V_76 , V_63 ) ;
return - V_21 ;
}
if ( V_93 > 1 && V_93 != V_63 ) {
F_61 ( V_2 -> V_11 ,
L_16 ,
V_76 , V_63 ) ;
return - V_21 ;
}
V_94 = 0 ;
if ( V_92 )
V_94 ++ ;
if ( V_93 )
V_94 ++ ;
V_95 = V_71 = F_63 ( V_63 * V_94 * sizeof( * V_71 ) ,
V_83 ) ;
if ( ! V_71 )
return - V_84 ;
for ( V_38 = 0 ; V_38 < V_63 ; V_38 ++ ) {
V_96 = F_67 ( V_76 , L_10 , V_38 , & V_8 ) ;
if ( V_96 )
goto V_99;
if ( V_8 >= F_31 ( V_64 ) ) {
F_61 ( V_2 -> V_11 , L_17 ,
V_76 , V_8 ) ;
V_96 = - V_21 ;
goto V_99;
}
if ( V_92 ) {
V_96 = F_67 ( V_76 , L_12 ,
( V_92 > 1 ) ? V_38 : 0 , & V_97 ) ;
if ( V_96 )
goto V_99;
V_96 = F_60 ( V_2 , V_76 , V_8 ,
V_97 , & V_95 ) ;
if ( V_96 )
goto V_99;
}
if ( V_93 ) {
V_96 = F_67 ( V_76 , L_13 ,
( V_93 > 1 ) ? V_38 : 0 , & V_82 ) ;
if ( V_96 )
goto V_99;
V_96 = F_62 ( V_2 , V_76 , V_8 ,
V_82 , & V_95 ) ;
if ( V_96 )
goto V_99;
}
}
* V_78 = V_71 ;
* V_72 = V_63 * V_94 ;
return 0 ;
V_99:
F_58 ( V_59 , V_71 , V_63 * V_94 ) ;
return V_96 ;
}
static int F_68 ( struct V_58 * V_59 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_55 ( V_59 ) ;
F_14 ( V_2 , V_18 , V_15 ) ;
return 0 ;
}
static int F_69 ( struct V_58 * V_59 )
{
return V_100 ;
}
static const char * F_70 ( struct V_58 * V_59 ,
unsigned V_61 )
{
return V_12 [ V_61 ] ;
}
static int F_71 ( struct V_58 * V_59 ,
unsigned V_61 ,
const char * const * * V_101 ,
unsigned * const V_102 )
{
* V_101 = V_60 ;
* V_102 = F_31 ( V_60 ) ;
return 0 ;
}
static int F_72 ( struct V_58 * V_59 ,
unsigned V_103 ,
unsigned V_104 )
{
struct V_1 * V_2 = F_55 ( V_59 ) ;
F_14 ( V_2 , V_104 , V_103 ) ;
return 0 ;
}
static void F_73 ( struct V_58 * V_59 ,
struct V_105 * V_106 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_55 ( V_59 ) ;
F_14 ( V_2 , V_18 , V_15 ) ;
}
static int F_74 ( struct V_58 * V_59 ,
struct V_105 * V_106 ,
unsigned V_18 ,
bool V_107 )
{
struct V_1 * V_2 = F_55 ( V_59 ) ;
enum V_7 V_13 = V_107 ?
V_15 : V_20 ;
F_14 ( V_2 , V_18 , V_13 ) ;
return 0 ;
}
static int F_75 ( struct V_58 * V_59 ,
unsigned V_8 , unsigned long * V_108 )
{
return - V_109 ;
}
static int F_76 ( struct V_58 * V_59 ,
unsigned V_8 , unsigned long * V_74 ,
unsigned V_88 )
{
struct V_1 * V_2 = F_55 ( V_59 ) ;
enum V_110 V_111 ;
T_2 V_112 ;
T_1 V_113 , V_6 ;
int V_38 ;
for ( V_38 = 0 ; V_38 < V_88 ; V_38 ++ ) {
V_111 = F_77 ( V_74 [ V_38 ] ) ;
V_112 = F_78 ( V_74 [ V_38 ] ) ;
if ( V_111 != V_85 )
return - V_21 ;
V_113 = F_6 ( V_8 ) ;
V_6 = F_7 ( V_8 ) ;
F_3 ( V_2 , V_114 , V_112 & 3 ) ;
F_79 ( 1 ) ;
F_3 ( V_2 , V_115 + ( V_113 * 4 ) , F_9 ( V_6 ) ) ;
F_79 ( 1 ) ;
F_3 ( V_2 , V_115 + ( V_113 * 4 ) , 0 ) ;
}
return 0 ;
}
static int F_80 ( struct V_116 * V_117 )
{
struct V_118 * V_11 = & V_117 -> V_11 ;
struct V_75 * V_76 = V_11 -> V_119 ;
struct V_1 * V_2 ;
struct V_120 V_121 ;
int V_96 , V_38 ;
F_81 ( F_31 ( V_64 ) != V_122 ) ;
F_81 ( F_31 ( V_60 ) != V_122 ) ;
V_2 = F_82 ( V_11 , sizeof( * V_2 ) , V_83 ) ;
if ( ! V_2 )
return - V_84 ;
F_83 ( V_117 , V_2 ) ;
V_2 -> V_11 = V_11 ;
V_96 = F_84 ( V_76 , 0 , & V_121 ) ;
if ( V_96 ) {
F_61 ( V_11 , L_18 ) ;
return V_96 ;
}
V_2 -> V_4 = F_85 ( V_11 , & V_121 ) ;
if ( F_86 ( V_2 -> V_4 ) )
return F_87 ( V_2 -> V_4 ) ;
V_2 -> V_16 = V_123 ;
V_2 -> V_16 . V_124 = V_11 ;
V_2 -> V_16 . V_119 = V_76 ;
for ( V_38 = 0 ; V_38 < V_125 ; V_38 ++ ) {
unsigned long V_27 ;
unsigned V_18 ;
F_3 ( V_2 , V_42 + V_38 * 4 , 0 ) ;
F_3 ( V_2 , V_44 + V_38 * 4 , 0 ) ;
F_3 ( V_2 , V_47 + V_38 * 4 , 0 ) ;
F_3 ( V_2 , V_49 + V_38 * 4 , 0 ) ;
F_3 ( V_2 , V_126 + V_38 * 4 , 0 ) ;
F_3 ( V_2 , V_127 + V_38 * 4 , 0 ) ;
V_27 = F_1 ( V_2 , V_29 + V_38 * 4 ) ;
F_24 (offset, &events, 32 )
F_3 ( V_2 , V_29 + V_38 * 4 , F_9 ( V_18 ) ) ;
F_88 ( & V_2 -> V_53 [ V_38 ] ) ;
}
V_96 = F_89 ( & V_2 -> V_16 , V_2 ) ;
if ( V_96 ) {
F_61 ( V_11 , L_19 ) ;
return V_96 ;
}
V_96 = F_90 ( & V_2 -> V_16 , & V_128 ,
0 , V_57 , V_54 ) ;
if ( V_96 ) {
F_91 ( V_11 , L_20 ) ;
return V_96 ;
}
for ( V_38 = 0 ; V_38 < V_129 ; V_38 ++ ) {
V_2 -> V_36 [ V_38 ] = F_92 ( V_76 , V_38 ) ;
if ( V_2 -> V_36 [ V_38 ] == 0 )
continue;
F_93 ( & V_2 -> V_16 ,
& V_128 ,
V_2 -> V_36 [ V_38 ] ,
F_27 ) ;
}
V_2 -> V_130 = F_94 ( V_11 , & V_131 , V_2 ) ;
if ( F_86 ( V_2 -> V_130 ) ) {
F_95 ( & V_2 -> V_16 ) ;
return F_87 ( V_2 -> V_130 ) ;
}
V_2 -> V_132 = V_133 ;
V_2 -> V_132 . V_4 = V_2 -> V_16 . V_4 ;
V_2 -> V_132 . V_134 = & V_2 -> V_16 ;
F_96 ( V_2 -> V_130 , & V_2 -> V_132 ) ;
return 0 ;
}
