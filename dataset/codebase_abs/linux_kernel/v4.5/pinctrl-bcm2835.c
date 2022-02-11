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
static void F_19 ( struct V_16 * V_17 , unsigned V_18 , int V_20 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
F_8 ( V_2 , V_20 ? V_21 : V_22 , V_18 ) ;
}
static int F_20 ( struct V_16 * V_17 ,
unsigned V_18 , int V_20 )
{
F_19 ( V_17 , V_18 , V_20 ) ;
return F_21 ( V_17 -> V_4 + V_18 ) ;
}
static int F_22 ( struct V_16 * V_17 , unsigned V_18 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
return F_23 ( V_2 -> V_23 , V_18 ) ;
}
static T_2 F_24 ( int V_24 , void * V_25 )
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
F_25 (offset, &events, 32 ) {
V_30 = ( 32 * V_28 ) + V_18 ;
type = V_2 -> V_33 [ V_30 ] ;
F_26 ( F_23 ( V_2 -> V_23 , V_30 ) ) ;
}
return V_29 ? V_34 : V_35 ;
}
static inline void F_27 ( struct V_1 * V_2 ,
unsigned V_3 , unsigned V_18 , bool V_36 )
{
T_1 V_20 ;
V_3 += F_6 ( V_18 ) * 4 ;
V_20 = F_1 ( V_2 , V_3 ) ;
if ( V_36 )
V_20 |= F_9 ( F_7 ( V_18 ) ) ;
else
V_20 &= ~ ( F_9 ( F_7 ( V_18 ) ) ) ;
F_3 ( V_2 , V_3 , V_20 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
unsigned V_18 , bool V_36 )
{
switch ( V_2 -> V_33 [ V_18 ] ) {
case V_37 :
F_27 ( V_2 , V_38 , V_18 , V_36 ) ;
break;
case V_39 :
F_27 ( V_2 , V_40 , V_18 , V_36 ) ;
break;
case V_41 :
F_27 ( V_2 , V_38 , V_18 , V_36 ) ;
F_27 ( V_2 , V_40 , V_18 , V_36 ) ;
break;
case V_42 :
F_27 ( V_2 , V_43 , V_18 , V_36 ) ;
break;
case V_44 :
F_27 ( V_2 , V_45 , V_18 , V_36 ) ;
break;
}
}
static void F_29 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned V_30 = F_31 ( V_47 ) ;
unsigned V_18 = F_7 ( V_30 ) ;
unsigned V_28 = F_6 ( V_30 ) ;
unsigned long V_48 ;
F_32 ( & V_2 -> V_49 [ V_28 ] , V_48 ) ;
F_33 ( V_18 , & V_2 -> V_32 [ V_28 ] ) ;
F_28 ( V_2 , V_30 , true ) ;
F_34 ( & V_2 -> V_49 [ V_28 ] , V_48 ) ;
}
static void F_35 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned V_30 = F_31 ( V_47 ) ;
unsigned V_18 = F_7 ( V_30 ) ;
unsigned V_28 = F_6 ( V_30 ) ;
unsigned long V_48 ;
F_32 ( & V_2 -> V_49 [ V_28 ] , V_48 ) ;
F_28 ( V_2 , V_30 , false ) ;
F_8 ( V_2 , V_31 , V_30 ) ;
F_36 ( V_18 , & V_2 -> V_32 [ V_28 ] ) ;
F_34 ( & V_2 -> V_49 [ V_28 ] , V_48 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
unsigned V_18 , unsigned int type )
{
switch ( type ) {
case V_50 :
case V_37 :
case V_39 :
case V_41 :
case V_42 :
case V_44 :
V_2 -> V_33 [ V_18 ] = type ;
break;
default:
return - V_51 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 ,
unsigned V_18 , unsigned int type )
{
switch ( type ) {
case V_50 :
if ( V_2 -> V_33 [ V_18 ] != type ) {
F_28 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
}
break;
case V_37 :
if ( V_2 -> V_33 [ V_18 ] == V_41 ) {
V_2 -> V_33 [ V_18 ] = V_39 ;
F_28 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
} else if ( V_2 -> V_33 [ V_18 ] != type ) {
F_28 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
F_28 ( V_2 , V_18 , true ) ;
}
break;
case V_39 :
if ( V_2 -> V_33 [ V_18 ] == V_41 ) {
V_2 -> V_33 [ V_18 ] = V_37 ;
F_28 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
} else if ( V_2 -> V_33 [ V_18 ] != type ) {
F_28 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
F_28 ( V_2 , V_18 , true ) ;
}
break;
case V_41 :
if ( V_2 -> V_33 [ V_18 ] == V_37 ) {
V_2 -> V_33 [ V_18 ] = V_39 ;
F_28 ( V_2 , V_18 , true ) ;
V_2 -> V_33 [ V_18 ] = type ;
} else if ( V_2 -> V_33 [ V_18 ] == V_39 ) {
V_2 -> V_33 [ V_18 ] = V_37 ;
F_28 ( V_2 , V_18 , true ) ;
V_2 -> V_33 [ V_18 ] = type ;
} else if ( V_2 -> V_33 [ V_18 ] != type ) {
F_28 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
F_28 ( V_2 , V_18 , true ) ;
}
break;
case V_42 :
case V_44 :
if ( V_2 -> V_33 [ V_18 ] != type ) {
F_28 ( V_2 , V_18 , false ) ;
V_2 -> V_33 [ V_18 ] = type ;
F_28 ( V_2 , V_18 , true ) ;
}
break;
default:
return - V_51 ;
}
return 0 ;
}
static int F_39 ( struct V_46 * V_47 , unsigned int type )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned V_30 = F_31 ( V_47 ) ;
unsigned V_18 = F_7 ( V_30 ) ;
unsigned V_28 = F_6 ( V_30 ) ;
unsigned long V_48 ;
int V_52 ;
F_32 ( & V_2 -> V_49 [ V_28 ] , V_48 ) ;
if ( F_40 ( V_18 , & V_2 -> V_32 [ V_28 ] ) )
V_52 = F_38 ( V_2 , V_30 , type ) ;
else
V_52 = F_37 ( V_2 , V_30 , type ) ;
if ( type & V_41 )
F_41 ( V_47 , V_53 ) ;
else
F_41 ( V_47 , V_54 ) ;
F_34 ( & V_2 -> V_49 [ V_28 ] , V_48 ) ;
return V_52 ;
}
static void F_42 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_30 ( V_47 ) ;
unsigned V_30 = F_31 ( V_47 ) ;
F_8 ( V_2 , V_31 , V_30 ) ;
}
static int F_43 ( struct V_55 * V_56 )
{
return F_44 ( V_57 ) ;
}
static const char * F_45 ( struct V_55 * V_56 ,
unsigned V_58 )
{
return V_57 [ V_58 ] ;
}
static int F_46 ( struct V_55 * V_56 ,
unsigned V_58 ,
const unsigned * * V_59 ,
unsigned * V_60 )
{
* V_59 = & V_61 [ V_58 ] . V_62 ;
* V_60 = 1 ;
return 0 ;
}
static void F_47 ( struct V_55 * V_56 ,
struct V_63 * V_64 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_48 ( V_56 ) ;
enum V_7 V_13 = F_10 ( V_2 , V_18 ) ;
const char * V_65 = V_12 [ V_13 ] ;
int V_20 = F_5 ( V_2 , V_19 , V_18 ) ;
int V_24 = F_49 ( V_2 -> V_23 , V_18 ) ;
F_50 ( V_64 , L_5 ,
V_65 , V_20 ? L_6 : L_7 ,
V_24 , V_66 [ V_2 -> V_33 [ V_18 ] ] ) ;
}
static void F_51 ( struct V_55 * V_56 ,
struct V_67 * V_68 , unsigned V_69 )
{
int V_70 ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ )
if ( V_68 [ V_70 ] . type == V_71 )
F_52 ( V_68 [ V_70 ] . V_47 . V_72 . V_72 ) ;
F_52 ( V_68 ) ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_73 * V_74 , T_1 V_8 , T_1 V_75 ,
struct V_67 * * V_68 )
{
struct V_67 * V_76 = * V_68 ;
if ( V_75 >= F_44 ( V_12 ) ) {
F_54 ( V_2 -> V_11 , L_8 ,
F_55 ( V_74 ) , V_75 ) ;
return - V_51 ;
}
V_76 -> type = V_77 ;
V_76 -> V_47 . V_78 . V_79 = V_57 [ V_8 ] ;
V_76 -> V_47 . V_78 . V_80 = V_12 [ V_75 ] ;
( * V_68 ) ++ ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_73 * V_74 , T_1 V_8 , T_1 V_81 ,
struct V_67 * * V_68 )
{
struct V_67 * V_76 = * V_68 ;
unsigned long * V_72 ;
if ( V_81 > 2 ) {
F_54 ( V_2 -> V_11 , L_9 ,
F_55 ( V_74 ) , V_81 ) ;
return - V_51 ;
}
V_72 = F_57 ( sizeof( * V_72 ) , V_82 ) ;
if ( ! V_72 )
return - V_83 ;
V_72 [ 0 ] = F_58 ( V_84 , V_81 ) ;
V_76 -> type = V_71 ;
V_76 -> V_47 . V_72 . V_85 = V_61 [ V_8 ] . V_86 ;
V_76 -> V_47 . V_72 . V_72 = V_72 ;
V_76 -> V_47 . V_72 . V_87 = 1 ;
( * V_68 ) ++ ;
return 0 ;
}
static int F_59 ( struct V_55 * V_56 ,
struct V_73 * V_74 ,
struct V_67 * * V_76 , unsigned * V_69 )
{
struct V_1 * V_2 = F_48 ( V_56 ) ;
struct V_88 * V_59 , * V_89 , * V_90 ;
int V_60 , V_91 , V_92 , V_93 ;
struct V_67 * V_68 , * V_94 ;
int V_70 , V_95 ;
T_1 V_8 , V_96 , V_81 ;
V_59 = F_60 ( V_74 , L_10 , NULL ) ;
if ( ! V_59 ) {
F_54 ( V_2 -> V_11 , L_11 ,
F_55 ( V_74 ) ) ;
return - V_51 ;
}
V_89 = F_60 ( V_74 , L_12 , NULL ) ;
V_90 = F_60 ( V_74 , L_13 , NULL ) ;
if ( ! V_89 && ! V_90 ) {
F_54 ( V_2 -> V_11 ,
L_14 ,
F_55 ( V_74 ) ) ;
return - V_51 ;
}
V_60 = V_59 -> V_97 / 4 ;
V_91 = V_89 ? ( V_89 -> V_97 / 4 ) : 0 ;
V_92 = V_90 ? ( V_90 -> V_97 / 4 ) : 0 ;
if ( V_91 > 1 && V_91 != V_60 ) {
F_54 ( V_2 -> V_11 ,
L_15 ,
F_55 ( V_74 ) , V_60 ) ;
return - V_51 ;
}
if ( V_92 > 1 && V_92 != V_60 ) {
F_54 ( V_2 -> V_11 ,
L_16 ,
F_55 ( V_74 ) , V_60 ) ;
return - V_51 ;
}
V_93 = 0 ;
if ( V_91 )
V_93 ++ ;
if ( V_92 )
V_93 ++ ;
V_94 = V_68 = F_57 ( V_60 * V_93 * sizeof( * V_68 ) ,
V_82 ) ;
if ( ! V_68 )
return - V_83 ;
for ( V_70 = 0 ; V_70 < V_60 ; V_70 ++ ) {
V_95 = F_61 ( V_74 , L_10 , V_70 , & V_8 ) ;
if ( V_95 )
goto V_98;
if ( V_8 >= F_44 ( V_61 ) ) {
F_54 ( V_2 -> V_11 , L_17 ,
F_55 ( V_74 ) , V_8 ) ;
V_95 = - V_51 ;
goto V_98;
}
if ( V_91 ) {
V_95 = F_61 ( V_74 , L_12 ,
( V_91 > 1 ) ? V_70 : 0 , & V_96 ) ;
if ( V_95 )
goto V_98;
V_95 = F_53 ( V_2 , V_74 , V_8 ,
V_96 , & V_94 ) ;
if ( V_95 )
goto V_98;
}
if ( V_92 ) {
V_95 = F_61 ( V_74 , L_13 ,
( V_91 > 1 ) ? V_70 : 0 , & V_81 ) ;
if ( V_95 )
goto V_98;
V_95 = F_56 ( V_2 , V_74 , V_8 ,
V_81 , & V_94 ) ;
if ( V_95 )
goto V_98;
}
}
* V_76 = V_68 ;
* V_69 = V_60 * V_93 ;
return 0 ;
V_98:
F_51 ( V_56 , V_68 , V_60 * V_93 ) ;
return V_95 ;
}
static int F_62 ( struct V_55 * V_56 )
{
return V_99 ;
}
static const char * F_63 ( struct V_55 * V_56 ,
unsigned V_58 )
{
return V_12 [ V_58 ] ;
}
static int F_64 ( struct V_55 * V_56 ,
unsigned V_58 ,
const char * const * * V_100 ,
unsigned * const V_101 )
{
* V_100 = V_57 ;
* V_101 = F_44 ( V_57 ) ;
return 0 ;
}
static int F_65 ( struct V_55 * V_56 ,
unsigned V_102 ,
unsigned V_103 )
{
struct V_1 * V_2 = F_48 ( V_56 ) ;
F_14 ( V_2 , V_103 , V_102 ) ;
return 0 ;
}
static void F_66 ( struct V_55 * V_56 ,
struct V_104 * V_105 ,
unsigned V_18 )
{
struct V_1 * V_2 = F_48 ( V_56 ) ;
F_14 ( V_2 , V_18 , V_15 ) ;
}
static int F_67 ( struct V_55 * V_56 ,
struct V_104 * V_105 ,
unsigned V_18 ,
bool V_106 )
{
struct V_1 * V_2 = F_48 ( V_56 ) ;
enum V_7 V_13 = V_106 ?
V_15 : V_107 ;
F_14 ( V_2 , V_18 , V_13 ) ;
return 0 ;
}
static int F_68 ( struct V_55 * V_56 ,
unsigned V_8 , unsigned long * V_108 )
{
return - V_109 ;
}
static int F_69 ( struct V_55 * V_56 ,
unsigned V_8 , unsigned long * V_72 ,
unsigned V_87 )
{
struct V_1 * V_2 = F_48 ( V_56 ) ;
enum V_110 V_111 ;
T_3 V_112 ;
T_1 V_113 , V_6 ;
int V_70 ;
for ( V_70 = 0 ; V_70 < V_87 ; V_70 ++ ) {
V_111 = F_70 ( V_72 [ V_70 ] ) ;
V_112 = F_71 ( V_72 [ V_70 ] ) ;
if ( V_111 != V_84 )
return - V_51 ;
V_113 = F_6 ( V_8 ) ;
V_6 = F_7 ( V_8 ) ;
F_3 ( V_2 , V_114 , V_112 & 3 ) ;
F_72 ( 150 ) ;
F_3 ( V_2 , V_115 + ( V_113 * 4 ) , F_9 ( V_6 ) ) ;
F_72 ( 150 ) ;
F_3 ( V_2 , V_115 + ( V_113 * 4 ) , 0 ) ;
}
return 0 ;
}
static int F_73 ( struct V_116 * V_117 )
{
struct V_118 * V_11 = & V_117 -> V_11 ;
struct V_73 * V_74 = V_11 -> V_119 ;
struct V_1 * V_2 ;
struct V_120 V_121 ;
int V_95 , V_70 ;
F_74 ( F_44 ( V_61 ) != V_122 ) ;
F_74 ( F_44 ( V_57 ) != V_122 ) ;
V_2 = F_75 ( V_11 , sizeof( * V_2 ) , V_82 ) ;
if ( ! V_2 )
return - V_83 ;
F_76 ( V_117 , V_2 ) ;
V_2 -> V_11 = V_11 ;
V_95 = F_77 ( V_74 , 0 , & V_121 ) ;
if ( V_95 ) {
F_54 ( V_11 , L_18 ) ;
return V_95 ;
}
V_2 -> V_4 = F_78 ( V_11 , & V_121 ) ;
if ( F_79 ( V_2 -> V_4 ) )
return F_80 ( V_2 -> V_4 ) ;
V_2 -> V_16 = V_123 ;
V_2 -> V_16 . V_124 = V_11 ;
V_2 -> V_16 . V_119 = V_74 ;
V_2 -> V_23 = F_81 ( V_74 , V_122 ,
& V_125 , NULL ) ;
if ( ! V_2 -> V_23 ) {
F_54 ( V_11 , L_19 ) ;
return - V_83 ;
}
for ( V_70 = 0 ; V_70 < V_122 ; V_70 ++ ) {
int V_24 = F_82 ( V_2 -> V_23 , V_70 ) ;
F_83 ( V_24 , & V_126 ) ;
F_84 ( V_24 , & V_127 ,
V_54 ) ;
F_85 ( V_24 , V_2 ) ;
}
for ( V_70 = 0 ; V_70 < V_128 ; V_70 ++ ) {
unsigned long V_29 ;
unsigned V_18 ;
int V_129 ;
char * V_86 ;
F_3 ( V_2 , V_38 + V_70 * 4 , 0 ) ;
F_3 ( V_2 , V_40 + V_70 * 4 , 0 ) ;
F_3 ( V_2 , V_43 + V_70 * 4 , 0 ) ;
F_3 ( V_2 , V_45 + V_70 * 4 , 0 ) ;
F_3 ( V_2 , V_130 + V_70 * 4 , 0 ) ;
F_3 ( V_2 , V_131 + V_70 * 4 , 0 ) ;
V_29 = F_1 ( V_2 , V_31 + V_70 * 4 ) ;
F_25 (offset, &events, 32 )
F_3 ( V_2 , V_31 + V_70 * 4 , F_9 ( V_18 ) ) ;
V_2 -> V_24 [ V_70 ] = F_86 ( V_74 , V_70 ) ;
V_2 -> V_46 [ V_70 ] . V_2 = V_2 ;
V_2 -> V_46 [ V_70 ] . V_28 = V_70 ;
F_87 ( & V_2 -> V_49 [ V_70 ] ) ;
V_129 = strlen ( F_88 ( V_2 -> V_11 ) ) + 16 ;
V_86 = F_75 ( V_2 -> V_11 , V_129 , V_82 ) ;
if ( ! V_86 )
return - V_83 ;
snprintf ( V_86 , V_129 , L_20 , F_88 ( V_2 -> V_11 ) , V_70 ) ;
V_95 = F_89 ( V_11 , V_2 -> V_24 [ V_70 ] ,
F_24 , V_132 ,
V_86 , & V_2 -> V_46 [ V_70 ] ) ;
if ( V_95 ) {
F_54 ( V_11 , L_21 , V_2 -> V_24 [ V_70 ] ) ;
return V_95 ;
}
}
V_95 = F_90 ( & V_2 -> V_16 , V_2 ) ;
if ( V_95 ) {
F_54 ( V_11 , L_22 ) ;
return V_95 ;
}
V_2 -> V_133 = F_91 ( & V_134 , V_11 , V_2 ) ;
if ( F_79 ( V_2 -> V_133 ) ) {
F_92 ( & V_2 -> V_16 ) ;
return F_80 ( V_2 -> V_133 ) ;
}
V_2 -> V_135 = V_136 ;
V_2 -> V_135 . V_4 = V_2 -> V_16 . V_4 ;
V_2 -> V_135 . V_137 = & V_2 -> V_16 ;
F_93 ( V_2 -> V_133 , & V_2 -> V_135 ) ;
return 0 ;
}
static int F_94 ( struct V_116 * V_117 )
{
struct V_1 * V_2 = F_95 ( V_117 ) ;
F_96 ( V_2 -> V_133 ) ;
F_92 ( & V_2 -> V_16 ) ;
return 0 ;
}
