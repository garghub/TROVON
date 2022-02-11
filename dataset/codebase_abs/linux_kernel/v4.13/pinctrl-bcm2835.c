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
unsigned int type ;
V_27 = F_1 ( V_2 , V_29 + V_25 * 4 ) ;
V_27 &= V_26 ;
V_27 &= V_2 -> V_30 [ V_25 ] ;
F_24 (offset, &events, 32 ) {
V_28 = ( 32 * V_25 ) + V_18 ;
type = V_2 -> V_31 [ V_28 ] ;
F_25 ( F_26 ( V_2 -> V_16 . V_32 ,
V_28 ) ) ;
}
}
static void F_27 ( struct V_33 * V_34 )
{
struct V_16 * V_17 = F_28 ( V_34 ) ;
struct V_1 * V_2 = F_18 ( V_17 ) ;
struct V_35 * V_36 = F_29 ( V_34 ) ;
int V_37 = F_30 ( V_34 ) ;
int V_38 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < F_31 ( V_2 -> V_37 ) ; V_39 ++ ) {
if ( V_2 -> V_37 [ V_39 ] == V_37 ) {
V_38 = V_2 -> V_40 [ V_39 ] ;
break;
}
}
if ( V_39 == F_31 ( V_2 -> V_37 ) )
F_32 () ;
F_33 ( V_36 , V_34 ) ;
switch ( V_38 ) {
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
F_34 ( V_36 , V_34 ) ;
}
static inline void F_35 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_18 , bool V_41 )
{
T_1 V_22 ;
V_3 += F_6 ( V_18 ) * 4 ;
V_22 = F_1 ( V_2 , V_3 ) ;
if ( V_41 )
V_22 |= F_9 ( F_7 ( V_18 ) ) ;
else
V_22 &= ~ ( F_9 ( F_7 ( V_18 ) ) ) ;
F_3 ( V_2 , V_3 , V_22 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
unsigned V_18 , bool V_41 )
{
switch ( V_2 -> V_31 [ V_18 ] ) {
case V_42 :
F_35 ( V_2 , V_43 , V_18 , V_41 ) ;
break;
case V_44 :
F_35 ( V_2 , V_45 , V_18 , V_41 ) ;
break;
case V_46 :
F_35 ( V_2 , V_43 , V_18 , V_41 ) ;
F_35 ( V_2 , V_45 , V_18 , V_41 ) ;
break;
case V_47 :
F_35 ( V_2 , V_48 , V_18 , V_41 ) ;
break;
case V_49 :
F_35 ( V_2 , V_50 , V_18 , V_41 ) ;
break;
}
}
static void F_37 ( struct V_51 * V_52 )
{
struct V_16 * V_17 = F_38 ( V_52 ) ;
struct V_1 * V_2 = F_18 ( V_17 ) ;
unsigned V_28 = F_39 ( V_52 ) ;
unsigned V_18 = F_7 ( V_28 ) ;
unsigned V_25 = F_6 ( V_28 ) ;
unsigned long V_53 ;
F_40 ( & V_2 -> V_54 [ V_25 ] , V_53 ) ;
F_41 ( V_18 , & V_2 -> V_30 [ V_25 ] ) ;
F_36 ( V_2 , V_28 , true ) ;
F_42 ( & V_2 -> V_54 [ V_25 ] , V_53 ) ;
}
static void F_43 ( struct V_51 * V_52 )
{
struct V_16 * V_17 = F_38 ( V_52 ) ;
struct V_1 * V_2 = F_18 ( V_17 ) ;
unsigned V_28 = F_39 ( V_52 ) ;
unsigned V_18 = F_7 ( V_28 ) ;
unsigned V_25 = F_6 ( V_28 ) ;
unsigned long V_53 ;
F_40 ( & V_2 -> V_54 [ V_25 ] , V_53 ) ;
F_36 ( V_2 , V_28 , false ) ;
F_8 ( V_2 , V_29 , V_28 ) ;
F_44 ( V_18 , & V_2 -> V_30 [ V_25 ] ) ;
F_42 ( & V_2 -> V_54 [ V_25 ] , V_53 ) ;
}
static int F_45 ( struct V_1 * V_2 ,
unsigned V_18 , unsigned int type )
{
switch ( type ) {
case V_55 :
case V_42 :
case V_44 :
case V_46 :
case V_47 :
case V_49 :
V_2 -> V_31 [ V_18 ] = type ;
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
case V_55 :
if ( V_2 -> V_31 [ V_18 ] != type ) {
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_31 [ V_18 ] = type ;
}
break;
case V_42 :
if ( V_2 -> V_31 [ V_18 ] == V_46 ) {
V_2 -> V_31 [ V_18 ] = V_44 ;
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_31 [ V_18 ] = type ;
} else if ( V_2 -> V_31 [ V_18 ] != type ) {
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_31 [ V_18 ] = type ;
F_36 ( V_2 , V_18 , true ) ;
}
break;
case V_44 :
if ( V_2 -> V_31 [ V_18 ] == V_46 ) {
V_2 -> V_31 [ V_18 ] = V_42 ;
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_31 [ V_18 ] = type ;
} else if ( V_2 -> V_31 [ V_18 ] != type ) {
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_31 [ V_18 ] = type ;
F_36 ( V_2 , V_18 , true ) ;
}
break;
case V_46 :
if ( V_2 -> V_31 [ V_18 ] == V_42 ) {
V_2 -> V_31 [ V_18 ] = V_44 ;
F_36 ( V_2 , V_18 , true ) ;
V_2 -> V_31 [ V_18 ] = type ;
} else if ( V_2 -> V_31 [ V_18 ] == V_44 ) {
V_2 -> V_31 [ V_18 ] = V_42 ;
F_36 ( V_2 , V_18 , true ) ;
V_2 -> V_31 [ V_18 ] = type ;
} else if ( V_2 -> V_31 [ V_18 ] != type ) {
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_31 [ V_18 ] = type ;
F_36 ( V_2 , V_18 , true ) ;
}
break;
case V_47 :
case V_49 :
if ( V_2 -> V_31 [ V_18 ] != type ) {
F_36 ( V_2 , V_18 , false ) ;
V_2 -> V_31 [ V_18 ] = type ;
F_36 ( V_2 , V_18 , true ) ;
}
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_47 ( struct V_51 * V_52 , unsigned int type )
{
struct V_16 * V_17 = F_38 ( V_52 ) ;
struct V_1 * V_2 = F_18 ( V_17 ) ;
unsigned V_28 = F_39 ( V_52 ) ;
unsigned V_18 = F_7 ( V_28 ) ;
unsigned V_25 = F_6 ( V_28 ) ;
unsigned long V_53 ;
int V_56 ;
F_40 ( & V_2 -> V_54 [ V_25 ] , V_53 ) ;
if ( F_48 ( V_18 , & V_2 -> V_30 [ V_25 ] ) )
V_56 = F_46 ( V_2 , V_28 , type ) ;
else
V_56 = F_45 ( V_2 , V_28 , type ) ;
if ( type & V_46 )
F_49 ( V_52 , V_57 ) ;
else
F_49 ( V_52 , V_58 ) ;
F_42 ( & V_2 -> V_54 [ V_25 ] , V_53 ) ;
return V_56 ;
}
static void F_50 ( struct V_51 * V_52 )
{
struct V_16 * V_17 = F_38 ( V_52 ) ;
struct V_1 * V_2 = F_18 ( V_17 ) ;
unsigned V_28 = F_39 ( V_52 ) ;
F_8 ( V_2 , V_29 , V_28 ) ;
}
static int F_51 ( struct V_59 * V_60 )
{
return F_31 ( V_61 ) ;
}
static const char * F_52 ( struct V_59 * V_60 ,
unsigned V_62 )
{
return V_61 [ V_62 ] ;
}
static int F_53 ( struct V_59 * V_60 ,
unsigned V_62 ,
const unsigned * * V_63 ,
unsigned * V_64 )
{
* V_63 = & V_65 [ V_62 ] . V_66 ;
* V_64 = 1 ;
return 0 ;
}
static void F_54 ( struct V_59 * V_60 ,
struct V_67 * V_68 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_55 ( V_60 ) ;
struct V_16 * V_17 = & V_2 -> V_16 ;
enum V_7 V_13 = F_10 ( V_2 , V_18 ) ;
const char * V_69 = V_12 [ V_13 ] ;
int V_22 = F_5 ( V_2 , V_19 , V_18 ) ;
int V_37 = F_56 ( V_17 -> V_32 , V_18 ) ;
F_57 ( V_68 , L_5 ,
V_69 , V_22 ? L_6 : L_7 ,
V_37 , V_70 [ V_2 -> V_31 [ V_18 ] ] ) ;
}
static void F_58 ( struct V_59 * V_60 ,
struct V_71 * V_72 , unsigned V_73 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_73 ; V_39 ++ )
if ( V_72 [ V_39 ] . type == V_74 )
F_59 ( V_72 [ V_39 ] . V_52 . V_75 . V_75 ) ;
F_59 ( V_72 ) ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_76 * V_77 , T_1 V_8 , T_1 V_78 ,
struct V_71 * * V_72 )
{
struct V_71 * V_79 = * V_72 ;
if ( V_78 >= F_31 ( V_12 ) ) {
F_61 ( V_2 -> V_11 , L_8 ,
F_62 ( V_77 ) , V_78 ) ;
return - V_21 ;
}
V_79 -> type = V_80 ;
V_79 -> V_52 . V_81 . V_38 = V_61 [ V_8 ] ;
V_79 -> V_52 . V_81 . V_82 = V_12 [ V_78 ] ;
( * V_72 ) ++ ;
return 0 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_76 * V_77 , T_1 V_8 , T_1 V_83 ,
struct V_71 * * V_72 )
{
struct V_71 * V_79 = * V_72 ;
unsigned long * V_75 ;
if ( V_83 > 2 ) {
F_61 ( V_2 -> V_11 , L_9 ,
F_62 ( V_77 ) , V_83 ) ;
return - V_21 ;
}
V_75 = F_64 ( sizeof( * V_75 ) , V_84 ) ;
if ( ! V_75 )
return - V_85 ;
V_75 [ 0 ] = F_65 ( V_86 , V_83 ) ;
V_79 -> type = V_74 ;
V_79 -> V_52 . V_75 . V_87 = V_65 [ V_8 ] . V_88 ;
V_79 -> V_52 . V_75 . V_75 = V_75 ;
V_79 -> V_52 . V_75 . V_89 = 1 ;
( * V_72 ) ++ ;
return 0 ;
}
static int F_66 ( struct V_59 * V_60 ,
struct V_76 * V_77 ,
struct V_71 * * V_79 , unsigned * V_73 )
{
struct V_1 * V_2 = F_55 ( V_60 ) ;
struct V_90 * V_63 , * V_91 , * V_92 ;
int V_64 , V_93 , V_94 , V_95 ;
struct V_71 * V_72 , * V_96 ;
int V_39 , V_97 ;
T_1 V_8 , V_98 , V_83 ;
V_63 = F_67 ( V_77 , L_10 , NULL ) ;
if ( ! V_63 ) {
F_61 ( V_2 -> V_11 , L_11 ,
F_62 ( V_77 ) ) ;
return - V_21 ;
}
V_91 = F_67 ( V_77 , L_12 , NULL ) ;
V_92 = F_67 ( V_77 , L_13 , NULL ) ;
if ( ! V_91 && ! V_92 ) {
F_61 ( V_2 -> V_11 ,
L_14 ,
F_62 ( V_77 ) ) ;
return - V_21 ;
}
V_64 = V_63 -> V_99 / 4 ;
V_93 = V_91 ? ( V_91 -> V_99 / 4 ) : 0 ;
V_94 = V_92 ? ( V_92 -> V_99 / 4 ) : 0 ;
if ( V_93 > 1 && V_93 != V_64 ) {
F_61 ( V_2 -> V_11 ,
L_15 ,
F_62 ( V_77 ) , V_64 ) ;
return - V_21 ;
}
if ( V_94 > 1 && V_94 != V_64 ) {
F_61 ( V_2 -> V_11 ,
L_16 ,
F_62 ( V_77 ) , V_64 ) ;
return - V_21 ;
}
V_95 = 0 ;
if ( V_93 )
V_95 ++ ;
if ( V_94 )
V_95 ++ ;
V_96 = V_72 = F_64 ( V_64 * V_95 * sizeof( * V_72 ) ,
V_84 ) ;
if ( ! V_72 )
return - V_85 ;
for ( V_39 = 0 ; V_39 < V_64 ; V_39 ++ ) {
V_97 = F_68 ( V_77 , L_10 , V_39 , & V_8 ) ;
if ( V_97 )
goto V_100;
if ( V_8 >= F_31 ( V_65 ) ) {
F_61 ( V_2 -> V_11 , L_17 ,
F_62 ( V_77 ) , V_8 ) ;
V_97 = - V_21 ;
goto V_100;
}
if ( V_93 ) {
V_97 = F_68 ( V_77 , L_12 ,
( V_93 > 1 ) ? V_39 : 0 , & V_98 ) ;
if ( V_97 )
goto V_100;
V_97 = F_60 ( V_2 , V_77 , V_8 ,
V_98 , & V_96 ) ;
if ( V_97 )
goto V_100;
}
if ( V_94 ) {
V_97 = F_68 ( V_77 , L_13 ,
( V_94 > 1 ) ? V_39 : 0 , & V_83 ) ;
if ( V_97 )
goto V_100;
V_97 = F_63 ( V_2 , V_77 , V_8 ,
V_83 , & V_96 ) ;
if ( V_97 )
goto V_100;
}
}
* V_79 = V_72 ;
* V_73 = V_64 * V_95 ;
return 0 ;
V_100:
F_58 ( V_60 , V_72 , V_64 * V_95 ) ;
return V_97 ;
}
static int F_69 ( struct V_59 * V_60 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_55 ( V_60 ) ;
F_14 ( V_2 , V_18 , V_15 ) ;
return 0 ;
}
static int F_70 ( struct V_59 * V_60 )
{
return V_101 ;
}
static const char * F_71 ( struct V_59 * V_60 ,
unsigned V_62 )
{
return V_12 [ V_62 ] ;
}
static int F_72 ( struct V_59 * V_60 ,
unsigned V_62 ,
const char * const * * V_102 ,
unsigned * const V_103 )
{
* V_102 = V_61 ;
* V_103 = F_31 ( V_61 ) ;
return 0 ;
}
static int F_73 ( struct V_59 * V_60 ,
unsigned V_104 ,
unsigned V_105 )
{
struct V_1 * V_2 = F_55 ( V_60 ) ;
F_14 ( V_2 , V_105 , V_104 ) ;
return 0 ;
}
static void F_74 ( struct V_59 * V_60 ,
struct V_106 * V_107 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_55 ( V_60 ) ;
F_14 ( V_2 , V_18 , V_15 ) ;
}
static int F_75 ( struct V_59 * V_60 ,
struct V_106 * V_107 ,
unsigned V_18 ,
bool V_108 )
{
struct V_1 * V_2 = F_55 ( V_60 ) ;
enum V_7 V_13 = V_108 ?
V_15 : V_20 ;
F_14 ( V_2 , V_18 , V_13 ) ;
return 0 ;
}
static int F_76 ( struct V_59 * V_60 ,
unsigned V_8 , unsigned long * V_109 )
{
return - V_110 ;
}
static int F_77 ( struct V_59 * V_60 ,
unsigned V_8 , unsigned long * V_75 ,
unsigned V_89 )
{
struct V_1 * V_2 = F_55 ( V_60 ) ;
enum V_111 V_112 ;
T_2 V_113 ;
T_1 V_114 , V_6 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_89 ; V_39 ++ ) {
V_112 = F_78 ( V_75 [ V_39 ] ) ;
V_113 = F_79 ( V_75 [ V_39 ] ) ;
if ( V_112 != V_86 )
return - V_21 ;
V_114 = F_6 ( V_8 ) ;
V_6 = F_7 ( V_8 ) ;
F_3 ( V_2 , V_115 , V_113 & 3 ) ;
F_80 ( 1 ) ;
F_3 ( V_2 , V_116 + ( V_114 * 4 ) , F_9 ( V_6 ) ) ;
F_80 ( 1 ) ;
F_3 ( V_2 , V_116 + ( V_114 * 4 ) , 0 ) ;
}
return 0 ;
}
static int F_81 ( struct V_117 * V_118 )
{
struct V_119 * V_11 = & V_118 -> V_11 ;
struct V_76 * V_77 = V_11 -> V_120 ;
struct V_1 * V_2 ;
struct V_121 V_122 ;
int V_97 , V_39 ;
F_82 ( F_31 ( V_65 ) != V_123 ) ;
F_82 ( F_31 ( V_61 ) != V_123 ) ;
V_2 = F_83 ( V_11 , sizeof( * V_2 ) , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
F_84 ( V_118 , V_2 ) ;
V_2 -> V_11 = V_11 ;
V_97 = F_85 ( V_77 , 0 , & V_122 ) ;
if ( V_97 ) {
F_61 ( V_11 , L_18 ) ;
return V_97 ;
}
V_2 -> V_4 = F_86 ( V_11 , & V_122 ) ;
if ( F_87 ( V_2 -> V_4 ) )
return F_88 ( V_2 -> V_4 ) ;
V_2 -> V_16 = V_124 ;
V_2 -> V_16 . V_125 = V_11 ;
V_2 -> V_16 . V_120 = V_77 ;
for ( V_39 = 0 ; V_39 < V_126 ; V_39 ++ ) {
unsigned long V_27 ;
unsigned V_18 ;
F_3 ( V_2 , V_43 + V_39 * 4 , 0 ) ;
F_3 ( V_2 , V_45 + V_39 * 4 , 0 ) ;
F_3 ( V_2 , V_48 + V_39 * 4 , 0 ) ;
F_3 ( V_2 , V_50 + V_39 * 4 , 0 ) ;
F_3 ( V_2 , V_127 + V_39 * 4 , 0 ) ;
F_3 ( V_2 , V_128 + V_39 * 4 , 0 ) ;
V_27 = F_1 ( V_2 , V_29 + V_39 * 4 ) ;
F_24 (offset, &events, 32 )
F_3 ( V_2 , V_29 + V_39 * 4 , F_9 ( V_18 ) ) ;
F_89 ( & V_2 -> V_54 [ V_39 ] ) ;
}
V_97 = F_90 ( & V_2 -> V_16 , V_2 ) ;
if ( V_97 ) {
F_61 ( V_11 , L_19 ) ;
return V_97 ;
}
V_97 = F_91 ( & V_2 -> V_16 , & V_129 ,
0 , V_58 , V_55 ) ;
if ( V_97 ) {
F_92 ( V_11 , L_20 ) ;
return V_97 ;
}
for ( V_39 = 0 ; V_39 < V_130 ; V_39 ++ ) {
V_2 -> V_37 [ V_39 ] = F_93 ( V_77 , V_39 ) ;
V_2 -> V_40 [ V_39 ] = V_39 ;
if ( V_2 -> V_37 [ V_39 ] == 0 )
continue;
F_94 ( & V_2 -> V_16 ,
& V_129 ,
V_2 -> V_37 [ V_39 ] ,
F_27 ) ;
}
V_2 -> V_131 = F_95 ( V_11 , & V_132 , V_2 ) ;
if ( F_87 ( V_2 -> V_131 ) ) {
F_96 ( & V_2 -> V_16 ) ;
return F_88 ( V_2 -> V_131 ) ;
}
V_2 -> V_133 = V_134 ;
V_2 -> V_133 . V_4 = V_2 -> V_16 . V_4 ;
V_2 -> V_133 . V_135 = & V_2 -> V_16 ;
F_97 ( V_2 -> V_131 , & V_2 -> V_133 ) ;
return 0 ;
}
