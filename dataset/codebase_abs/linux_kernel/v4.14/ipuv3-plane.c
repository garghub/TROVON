static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline struct V_5 * F_3 ( struct V_6 * V_3 )
{
return F_2 ( V_3 , struct V_5 , V_4 ) ;
}
int F_4 ( struct V_5 * V_5 )
{
return F_5 ( V_5 -> V_7 , V_5 -> V_8 ,
V_9 ) ;
}
static inline unsigned long
F_6 ( struct V_2 * V_10 , int V_11 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_14 * V_15 ;
int V_16 = V_10 -> V_17 . V_18 >> 16 ;
int V_19 = V_10 -> V_17 . y1 >> 16 ;
V_15 = F_7 ( V_13 , V_11 ) ;
F_8 ( ! V_15 ) ;
return V_15 -> V_20 + V_13 -> V_21 [ V_11 ] + V_13 -> V_22 [ V_11 ] * V_19 +
V_13 -> V_23 -> V_24 [ V_11 ] * V_16 ;
}
static inline unsigned long
F_9 ( struct V_2 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_14 * V_15 ;
unsigned long V_25 = F_6 ( V_10 , 0 ) ;
int V_16 = V_10 -> V_17 . V_18 >> 16 ;
int V_19 = V_10 -> V_17 . y1 >> 16 ;
V_15 = F_7 ( V_13 , 1 ) ;
F_8 ( ! V_15 ) ;
V_16 /= F_10 ( V_13 -> V_23 -> V_23 ) ;
V_19 /= F_11 ( V_13 -> V_23 -> V_23 ) ;
return V_15 -> V_20 + V_13 -> V_21 [ 1 ] + V_13 -> V_22 [ 1 ] * V_19 +
V_13 -> V_23 -> V_24 [ 1 ] * V_16 - V_25 ;
}
static inline unsigned long
F_12 ( struct V_2 * V_10 )
{
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_14 * V_15 ;
unsigned long V_25 = F_6 ( V_10 , 0 ) ;
int V_16 = V_10 -> V_17 . V_18 >> 16 ;
int V_19 = V_10 -> V_17 . y1 >> 16 ;
V_15 = F_7 ( V_13 , 2 ) ;
F_8 ( ! V_15 ) ;
V_16 /= F_10 ( V_13 -> V_23 -> V_23 ) ;
V_19 /= F_11 ( V_13 -> V_23 -> V_23 ) ;
return V_15 -> V_20 + V_13 -> V_21 [ 2 ] + V_13 -> V_22 [ 2 ] * V_19 +
V_13 -> V_23 -> V_24 [ 2 ] * V_16 - V_25 ;
}
void F_13 ( struct V_5 * V_5 )
{
if ( ! F_14 ( V_5 -> V_26 ) )
F_15 ( V_5 -> V_26 ) ;
if ( ! F_14 ( V_5 -> V_27 ) )
F_16 ( V_5 -> V_27 ) ;
if ( ! F_14 ( V_5 -> V_8 ) )
F_17 ( V_5 -> V_8 ) ;
if ( ! F_14 ( V_5 -> V_28 ) )
F_17 ( V_5 -> V_28 ) ;
}
int F_18 ( struct V_5 * V_5 )
{
int V_29 ;
int V_28 ;
V_5 -> V_8 = F_19 ( V_5 -> V_7 , V_5 -> V_30 ) ;
if ( F_20 ( V_5 -> V_8 ) ) {
V_29 = F_21 ( V_5 -> V_8 ) ;
F_22 ( L_1 , V_29 ) ;
return V_29 ;
}
V_28 = F_23 ( V_5 -> V_30 ) ;
if ( V_28 >= 0 ) {
V_5 -> V_28 = F_19 ( V_5 -> V_7 , V_28 ) ;
if ( F_20 ( V_5 -> V_28 ) ) {
V_29 = F_21 ( V_5 -> V_28 ) ;
F_22 ( L_2 ,
V_28 , V_29 ) ;
return V_29 ;
}
}
V_5 -> V_27 = F_24 ( V_5 -> V_7 , V_5 -> V_30 ) ;
if ( F_20 ( V_5 -> V_27 ) ) {
V_29 = F_21 ( V_5 -> V_27 ) ;
F_22 ( L_3 , V_29 ) ;
goto V_31;
}
if ( V_5 -> V_32 >= 0 ) {
V_5 -> V_26 = F_25 ( V_5 -> V_7 , V_5 -> V_32 ) ;
if ( F_20 ( V_5 -> V_26 ) ) {
V_29 = F_21 ( V_5 -> V_26 ) ;
F_22 ( L_4 , V_29 ) ;
goto V_31;
}
}
return 0 ;
V_31:
F_13 ( V_5 ) ;
return V_29 ;
}
static bool F_26 ( struct V_5 * V_5 )
{
switch ( V_5 -> V_4 . V_10 -> V_13 -> V_23 -> V_23 ) {
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
return true ;
default:
return false ;
}
}
static void F_27 ( struct V_5 * V_5 )
{
if ( V_5 -> V_26 )
F_28 ( V_5 -> V_7 ) ;
F_29 ( V_5 -> V_27 ) ;
F_30 ( V_5 -> V_8 ) ;
if ( F_26 ( V_5 ) )
F_30 ( V_5 -> V_28 ) ;
if ( V_5 -> V_26 )
F_31 ( V_5 -> V_26 ) ;
}
void F_32 ( struct V_5 * V_5 , bool V_39 )
{
F_33 ( L_5 , __LINE__ , V_40 ) ;
F_34 ( V_5 -> V_8 , 50 ) ;
if ( V_5 -> V_26 && V_39 )
F_35 ( V_5 -> V_26 , false ) ;
F_36 ( V_5 -> V_8 ) ;
if ( V_5 -> V_28 )
F_36 ( V_5 -> V_28 ) ;
F_37 ( V_5 -> V_27 ) ;
if ( V_5 -> V_26 )
F_38 ( V_5 -> V_7 ) ;
if ( F_39 ( V_5 -> V_7 ) )
F_40 ( V_5 -> V_8 ) ;
}
void F_41 ( struct V_6 * V_11 )
{
struct V_5 * V_5 = F_3 ( V_11 ) ;
if ( V_5 -> V_41 ) {
V_5 -> V_41 = false ;
F_32 ( V_5 , false ) ;
}
}
static void F_42 ( struct V_6 * V_11 )
{
struct V_5 * V_5 = F_3 ( V_11 ) ;
F_33 ( L_5 , __LINE__ , V_40 ) ;
F_43 ( V_11 ) ;
F_44 ( V_5 ) ;
}
void F_45 ( struct V_6 * V_11 )
{
struct V_1 * V_42 ;
if ( V_11 -> V_10 ) {
V_42 = F_1 ( V_11 -> V_10 ) ;
F_46 ( V_11 -> V_10 ) ;
F_44 ( V_42 ) ;
}
V_42 = F_47 ( sizeof( * V_42 ) , V_43 ) ;
if ( V_42 ) {
V_42 -> V_4 . V_11 = V_11 ;
V_42 -> V_4 . V_44 = V_45 ;
}
V_11 -> V_10 = & V_42 -> V_4 ;
}
struct V_2 * F_48 ( struct V_6 * V_11 )
{
struct V_1 * V_10 ;
if ( F_49 ( ! V_11 -> V_10 ) )
return NULL ;
V_10 = F_50 ( sizeof( * V_10 ) , V_43 ) ;
if ( V_10 )
F_51 ( V_11 , & V_10 -> V_4 ) ;
return & V_10 -> V_4 ;
}
void F_52 ( struct V_6 * V_11 ,
struct V_2 * V_10 )
{
struct V_1 * V_42 = F_1 ( V_10 ) ;
F_46 ( V_10 ) ;
F_44 ( V_42 ) ;
}
static int F_53 ( struct V_6 * V_11 ,
struct V_2 * V_10 )
{
struct V_2 * V_46 = V_11 -> V_10 ;
struct V_47 * V_48 ;
struct V_49 * V_50 = V_11 -> V_50 -> V_50 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_12 * V_51 = V_46 -> V_13 ;
unsigned long V_25 , V_52 , V_53 , V_54 , V_55 , V_56 ;
bool V_57 = ( V_11 -> type == V_58 ) ;
struct V_59 V_60 ;
int V_61 , V_62 ;
int V_29 ;
if ( ! V_13 )
return 0 ;
if ( ! V_10 -> V_63 )
return - V_64 ;
V_48 =
F_54 ( V_10 -> V_10 , V_10 -> V_63 ) ;
if ( F_49 ( ! V_48 ) )
return - V_64 ;
V_60 . V_18 = 0 ;
V_60 . y1 = 0 ;
V_60 . V_65 = V_48 -> V_66 . V_67 ;
V_60 . V_68 = V_48 -> V_66 . V_69 ;
V_29 = F_55 ( V_10 , & V_60 ,
V_70 ,
V_70 ,
V_57 , true ) ;
if ( V_29 )
return V_29 ;
if ( ! V_48 -> V_71 )
return - V_64 ;
switch ( V_11 -> type ) {
case V_72 :
if ( F_56 ( & V_10 -> V_73 ) < 13 )
return - V_64 ;
break;
case V_58 :
break;
default:
F_57 ( V_50 , L_6 , V_11 -> type ) ;
return - V_64 ;
}
if ( F_58 ( & V_10 -> V_73 ) < 2 )
return - V_64 ;
if ( V_51 &&
( F_56 ( & V_10 -> V_73 ) != F_56 ( & V_46 -> V_73 ) ||
F_58 ( & V_10 -> V_73 ) != F_58 ( & V_46 -> V_73 ) ||
V_13 -> V_23 != V_51 -> V_23 ) )
V_48 -> V_74 = true ;
V_25 = F_6 ( V_10 , 0 ) ;
if ( V_25 & 0x7 )
return - V_64 ;
if ( V_13 -> V_22 [ 0 ] < 1 || V_13 -> V_22 [ 0 ] > 16384 )
return - V_64 ;
if ( V_51 && V_13 -> V_22 [ 0 ] != V_51 -> V_22 [ 0 ] )
V_48 -> V_74 = true ;
switch ( V_13 -> V_23 -> V_23 ) {
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
V_53 = F_12 ( V_10 ) ;
if ( V_53 & 0x7 || V_53 > 0xfffff8 )
return - V_64 ;
if ( V_51 && ( V_13 -> V_23 == V_51 -> V_23 ) ) {
V_55 = F_12 ( V_46 ) ;
if ( V_53 != V_55 )
V_48 -> V_74 = true ;
}
if ( V_13 -> V_22 [ 1 ] != V_13 -> V_22 [ 2 ] )
return - V_64 ;
case V_81 :
case V_82 :
V_52 = F_9 ( V_10 ) ;
if ( V_52 & 0x7 || V_52 > 0xfffff8 )
return - V_64 ;
if ( V_51 && ( V_13 -> V_23 == V_51 -> V_23 ) ) {
V_54 = F_9 ( V_46 ) ;
if ( V_52 != V_54 )
V_48 -> V_74 = true ;
}
if ( V_13 -> V_22 [ 1 ] < 1 || V_13 -> V_22 [ 1 ] > 16384 )
return - V_64 ;
if ( V_51 && V_51 -> V_22 [ 1 ] != V_13 -> V_22 [ 1 ] )
V_48 -> V_74 = true ;
V_61 = F_10 ( V_13 -> V_23 -> V_23 ) ;
V_62 = F_11 ( V_13 -> V_23 -> V_23 ) ;
if ( ( ( V_10 -> V_17 . V_18 >> 16 ) & ( V_61 - 1 ) ) ||
( ( V_10 -> V_17 . y1 >> 16 ) & ( V_62 - 1 ) ) )
return - V_64 ;
break;
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_56 = F_6 ( V_10 , 1 ) ;
if ( V_56 & 0x7 )
return - V_64 ;
if ( V_13 -> V_22 [ 1 ] < 1 || V_13 -> V_22 [ 1 ] > 16384 )
return - V_64 ;
if ( V_51 && V_51 -> V_22 [ 1 ] != V_13 -> V_22 [ 1 ] )
V_48 -> V_74 = true ;
break;
}
return 0 ;
}
static void F_59 ( struct V_6 * V_11 ,
struct V_2 * V_46 )
{
struct V_5 * V_5 = F_3 ( V_11 ) ;
if ( V_5 -> V_26 )
F_35 ( V_5 -> V_26 , true ) ;
V_5 -> V_41 = true ;
}
static int F_60 ( int V_83 )
{
switch ( V_83 ) {
case V_84 :
return 1 ;
case V_85 :
return 2 ;
case V_86 :
return 3 ;
default:
return 0 ;
}
}
static void F_61 ( T_1 V_87 , T_1 V_24 , T_1 V_88 ,
T_2 * V_89 , T_2 * V_90 )
{
const unsigned int V_91 = V_87 * V_24 ;
unsigned int V_92 , V_93 ;
for ( V_92 = 64 / V_24 ; V_92 > 0 ; -- V_92 ) {
if ( F_62 ( V_91 , V_92 * V_24 ) <= V_88 )
break;
}
* V_89 = V_92 ;
for ( V_93 = 8 ; V_93 > 1 ; V_93 /= 2 ) {
if ( F_62 ( V_91 , V_92 * V_24 * V_93 ) <= V_88 )
break;
}
* V_90 = V_93 ;
}
static void F_63 ( struct V_6 * V_11 ,
struct V_2 * V_46 )
{
struct V_5 * V_5 = F_3 ( V_11 ) ;
struct V_2 * V_10 = V_11 -> V_10 ;
struct V_1 * V_42 = F_1 ( V_10 ) ;
struct V_47 * V_48 = V_10 -> V_63 -> V_10 ;
struct V_12 * V_13 = V_10 -> V_13 ;
struct V_59 * V_73 = & V_10 -> V_73 ;
unsigned long V_25 , V_52 , V_53 ;
unsigned long V_56 = 0 ;
enum V_94 V_95 ;
unsigned int V_96 = 0 ;
const struct V_97 * V_98 ;
T_2 V_89 , V_90 ;
T_1 V_87 , V_99 ;
int V_100 ;
if ( V_5 -> V_32 == V_101 )
F_64 ( V_5 -> V_26 , V_73 -> V_18 , V_73 -> y1 ) ;
V_25 = F_6 ( V_10 , 0 ) ;
if ( V_42 -> V_102 ) {
V_96 = F_60 ( V_5 -> V_30 ) ;
F_65 ( V_5 -> V_8 , V_96 ,
F_56 ( & V_10 -> V_17 ) >> 16 ,
F_58 ( & V_10 -> V_17 ) >> 16 ,
V_13 -> V_22 [ 0 ] ,
V_13 -> V_23 -> V_23 , & V_25 ) ;
}
if ( V_46 -> V_13 && ! F_66 ( V_48 ) ) {
if ( V_42 -> V_102 )
return;
V_100 = F_67 ( V_5 -> V_8 ) ;
F_68 ( V_5 -> V_8 , ! V_100 , V_25 ) ;
F_69 ( V_5 -> V_8 , ! V_100 ) ;
if ( F_26 ( V_5 ) ) {
V_100 = F_67 ( V_5 -> V_28 ) ;
F_68 ( V_5 -> V_28 , ! V_100 ,
V_56 ) ;
F_69 ( V_5 -> V_28 , ! V_100 ) ;
}
return;
}
V_95 = F_70 ( V_13 -> V_23 -> V_23 ) ;
switch ( V_5 -> V_32 ) {
case V_103 :
F_71 ( V_5 -> V_26 , V_95 , V_104 ) ;
F_72 ( V_5 -> V_26 , true , 0 , true ) ;
break;
case V_101 :
F_71 ( V_5 -> V_26 , V_95 ,
V_105 ) ;
switch ( V_13 -> V_23 -> V_23 ) {
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_114 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
F_72 ( V_5 -> V_26 , false , 0 , false ) ;
break;
default:
F_72 ( V_5 -> V_26 , true , 0 , true ) ;
break;
}
}
F_73 ( V_5 -> V_27 , F_56 ( V_73 ) ) ;
V_87 = F_56 ( & V_10 -> V_17 ) >> 16 ;
V_99 = F_58 ( & V_10 -> V_17 ) >> 16 ;
V_98 = V_97 ( V_13 -> V_23 -> V_23 ) ;
F_61 ( V_87 , V_98 -> V_24 [ 0 ] , V_13 -> V_22 [ 0 ] ,
& V_89 , & V_90 ) ;
F_74 ( V_5 -> V_8 ) ;
F_75 ( V_5 -> V_8 , V_87 , V_99 ) ;
F_76 ( V_5 -> V_8 , V_13 -> V_23 -> V_23 ) ;
F_77 ( V_5 -> V_8 , V_89 ) ;
F_78 ( V_5 -> V_8 ) ;
F_79 ( V_5 -> V_8 , 1 ) ;
F_80 ( V_5 -> V_8 , V_13 -> V_22 [ 0 ] ) ;
F_81 ( V_5 -> V_8 , V_96 ) ;
switch ( V_13 -> V_23 -> V_23 ) {
case V_75 :
case V_76 :
case V_77 :
case V_78 :
case V_79 :
case V_80 :
V_52 = F_9 ( V_10 ) ;
V_53 = F_12 ( V_10 ) ;
if ( V_13 -> V_23 -> V_23 == V_76 ||
V_13 -> V_23 -> V_23 == V_78 ||
V_13 -> V_23 -> V_23 == V_80 )
F_82 ( V_52 , V_53 ) ;
F_83 ( V_5 -> V_8 ,
V_13 -> V_22 [ 1 ] , V_52 , V_53 ) ;
F_84 ( V_5 -> V_4 . V_50 -> V_50 ,
L_7 , V_25 , V_52 , V_53 ,
V_10 -> V_17 . V_18 >> 16 , V_10 -> V_17 . y1 >> 16 ) ;
break;
case V_81 :
case V_82 :
V_52 = F_9 ( V_10 ) ;
F_83 ( V_5 -> V_8 ,
V_13 -> V_22 [ 1 ] , V_52 , V_52 ) ;
F_84 ( V_5 -> V_4 . V_50 -> V_50 ,
L_8 , V_25 , V_52 ,
V_10 -> V_17 . V_18 >> 16 , V_10 -> V_17 . y1 >> 16 ) ;
break;
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_38 :
V_56 = F_6 ( V_10 , 1 ) ;
V_90 = 0 ;
F_84 ( V_5 -> V_4 . V_50 -> V_50 , L_9 ,
V_25 , V_56 , V_10 -> V_17 . V_18 >> 16 , V_10 -> V_17 . y1 >> 16 ) ;
F_77 ( V_5 -> V_8 , 16 ) ;
F_74 ( V_5 -> V_28 ) ;
F_75 ( V_5 -> V_28 ,
F_56 ( & V_10 -> V_17 ) >> 16 ,
F_58 ( & V_10 -> V_17 ) >> 16 ) ;
F_85 ( V_5 -> V_28 , 8 ) ;
F_78 ( V_5 -> V_28 ) ;
F_79 ( V_5 -> V_28 , 1 ) ;
F_80 ( V_5 -> V_28 , V_13 -> V_22 [ 1 ] ) ;
F_77 ( V_5 -> V_28 , 16 ) ;
F_68 ( V_5 -> V_28 , 0 , V_56 ) ;
F_68 ( V_5 -> V_28 , 1 , V_56 ) ;
break;
default:
F_84 ( V_5 -> V_4 . V_50 -> V_50 , L_10 ,
V_25 , V_10 -> V_17 . V_18 >> 16 , V_10 -> V_17 . y1 >> 16 ) ;
break;
}
F_68 ( V_5 -> V_8 , 0 , V_25 ) ;
F_68 ( V_5 -> V_8 , 1 , V_25 ) ;
F_86 ( V_5 -> V_8 , V_90 ) ;
F_27 ( V_5 ) ;
}
int F_87 ( struct V_115 * V_50 ,
struct V_116 * V_10 )
{
struct V_2 * V_117 ;
struct V_6 * V_11 ;
int V_118 = F_88 () ;
int V_119 ;
F_89 (state, plane, plane_state, i) {
struct V_1 * V_42 =
F_1 ( V_117 ) ;
struct V_5 * V_5 = F_3 ( V_11 ) ;
if ( F_39 ( V_5 -> V_7 ) && V_118 &&
V_117 -> V_13 &&
F_90 ( V_5 -> V_7 ,
V_117 -> V_13 -> V_23 -> V_23 ,
V_117 -> V_13 -> V_120 ) ) {
V_42 -> V_102 = true ;
V_118 -- ;
} else {
V_42 -> V_102 = false ;
}
}
return 0 ;
}
struct V_5 * F_91 ( struct V_115 * V_50 , struct V_121 * V_7 ,
int V_30 , int V_26 , unsigned int V_122 ,
enum V_123 type )
{
struct V_5 * V_5 ;
int V_29 ;
F_33 ( L_11 ,
V_30 , V_26 , V_122 ) ;
V_5 = F_47 ( sizeof( * V_5 ) , V_43 ) ;
if ( ! V_5 ) {
F_22 ( L_12 ) ;
return F_92 ( - V_124 ) ;
}
V_5 -> V_7 = V_7 ;
V_5 -> V_30 = V_30 ;
V_5 -> V_32 = V_26 ;
V_29 = F_93 ( V_50 , & V_5 -> V_4 , V_122 ,
& V_125 , V_126 ,
F_94 ( V_126 ) ,
NULL , type , NULL ) ;
if ( V_29 ) {
F_22 ( L_13 ) ;
F_44 ( V_5 ) ;
return F_92 ( V_29 ) ;
}
F_95 ( & V_5 -> V_4 , & V_127 ) ;
return V_5 ;
}
