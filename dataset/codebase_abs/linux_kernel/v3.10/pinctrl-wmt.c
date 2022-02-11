static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
T_1 V_5 ;
V_5 = F_2 ( V_2 -> V_6 + V_3 ) ;
V_5 |= V_4 ;
F_3 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
T_1 V_5 ;
V_5 = F_2 ( V_2 -> V_6 + V_3 ) ;
V_5 &= ~ V_4 ;
F_3 ( V_5 , V_2 -> V_6 + V_3 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
return V_9 ;
}
static const char * F_6 ( struct V_7 * V_8 ,
unsigned V_10 )
{
return V_11 [ V_10 ] ;
}
static int F_7 ( struct V_7 * V_8 ,
unsigned V_10 ,
const char * const * * V_12 ,
unsigned * const V_13 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
* V_12 = V_2 -> V_12 ;
* V_13 = V_2 -> V_14 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_15 ,
unsigned V_16 )
{
T_1 V_17 = F_10 ( V_16 ) ;
T_1 V_18 = F_11 ( V_16 ) ;
T_1 V_19 = V_2 -> V_20 [ V_17 ] . V_19 ;
T_1 V_21 = V_2 -> V_20 [ V_17 ] . V_21 ;
if ( V_21 == V_22 ) {
F_12 ( V_2 -> V_23 , L_1 ,
V_16 ) ;
return - V_24 ;
}
switch ( V_15 ) {
case V_25 :
if ( V_19 != V_22 )
F_1 ( V_2 , V_19 , F_13 ( V_18 ) ) ;
F_4 ( V_2 , V_21 , F_13 ( V_18 ) ) ;
break;
case V_26 :
if ( V_19 != V_22 )
F_1 ( V_2 , V_19 , F_13 ( V_18 ) ) ;
F_1 ( V_2 , V_21 , F_13 ( V_18 ) ) ;
break;
case V_27 :
if ( V_19 == V_22 ) {
F_12 ( V_2 -> V_23 , L_2 ,
V_16 ) ;
return - V_24 ;
}
F_4 ( V_2 , V_19 , F_13 ( V_18 ) ) ;
}
return 0 ;
}
static int F_14 ( struct V_7 * V_8 ,
unsigned V_28 ,
unsigned V_29 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
T_1 V_30 = V_2 -> V_31 [ V_29 ] . V_32 ;
return F_9 ( V_2 , V_28 , V_30 ) ;
}
static void F_15 ( struct V_7 * V_8 ,
unsigned V_28 ,
unsigned V_29 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
T_1 V_30 = V_2 -> V_31 [ V_29 ] . V_32 ;
F_9 ( V_2 , V_25 , V_30 ) ;
}
static void F_16 ( struct V_7 * V_8 ,
struct V_33 * V_34 ,
unsigned V_35 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
F_9 ( V_2 , V_25 , V_35 ) ;
}
static int F_17 ( struct V_7 * V_8 ,
struct V_33 * V_34 ,
unsigned V_35 ,
bool V_36 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
F_9 ( V_2 , ( V_36 ? V_25 : V_26 ) ,
V_35 ) ;
return 0 ;
}
static int F_18 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
return V_2 -> V_14 ;
}
static const char * F_19 ( struct V_7 * V_8 ,
unsigned V_10 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
return V_2 -> V_12 [ V_10 ] ;
}
static int F_20 ( struct V_7 * V_8 ,
unsigned V_10 ,
const unsigned * * V_31 ,
unsigned * V_37 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
* V_31 = & V_2 -> V_31 [ V_10 ] . V_32 ;
* V_37 = 1 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , T_1 V_16 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_39 ; V_38 ++ ) {
if ( V_2 -> V_31 [ V_38 ] . V_32 == V_16 )
return V_38 ;
}
return - V_24 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
T_1 V_16 , T_1 V_42 ,
struct V_43 * * V_44 )
{
int V_45 ;
struct V_43 * V_46 = * V_44 ;
if ( V_42 >= F_23 ( V_11 ) ) {
F_12 ( V_2 -> V_23 , L_3 , V_42 ) ;
return - V_24 ;
}
V_45 = F_21 ( V_2 , V_16 ) ;
if ( V_45 < 0 ) {
F_12 ( V_2 -> V_23 , L_4 , V_16 ) ;
return V_45 ;
}
V_46 -> type = V_47 ;
V_46 -> V_2 . V_48 . V_45 = V_2 -> V_12 [ V_45 ] ;
V_46 -> V_2 . V_48 . V_49 = V_11 [ V_42 ] ;
( * V_44 ) ++ ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
T_1 V_16 , T_1 V_50 ,
struct V_43 * * V_44 )
{
int V_45 ;
unsigned long * V_51 ;
struct V_43 * V_46 = * V_44 ;
if ( V_50 > 2 ) {
F_12 ( V_2 -> V_23 , L_5 , V_50 ) ;
return - V_24 ;
}
V_45 = F_21 ( V_2 , V_16 ) ;
if ( V_45 < 0 ) {
F_12 ( V_2 -> V_23 , L_4 , V_16 ) ;
return V_45 ;
}
V_51 = F_25 ( sizeof( * V_51 ) , V_52 ) ;
if ( ! V_51 )
return - V_53 ;
V_51 [ 0 ] = V_50 ;
V_46 -> type = V_54 ;
V_46 -> V_2 . V_51 . V_55 = V_2 -> V_12 [ V_45 ] ;
V_46 -> V_2 . V_51 . V_51 = V_51 ;
V_46 -> V_2 . V_51 . V_56 = 1 ;
( * V_44 ) ++ ;
return 0 ;
}
static void F_26 ( struct V_7 * V_8 ,
struct V_43 * V_44 ,
unsigned V_57 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_57 ; V_38 ++ )
if ( V_44 [ V_38 ] . type == V_54 )
F_27 ( V_44 [ V_38 ] . V_2 . V_51 . V_51 ) ;
F_27 ( V_44 ) ;
}
static int F_28 ( struct V_7 * V_8 ,
struct V_40 * V_41 ,
struct V_43 * * V_46 ,
unsigned * V_57 )
{
struct V_43 * V_44 , * V_58 ;
struct V_59 * V_31 , * V_60 , * V_61 ;
T_1 V_16 , V_15 , V_50 ;
int V_37 , V_62 , V_63 , V_64 ;
int V_38 , V_65 ;
struct V_1 * V_2 = F_8 ( V_8 ) ;
V_31 = F_29 ( V_41 , L_6 , NULL ) ;
if ( ! V_31 ) {
F_12 ( V_2 -> V_23 , L_7 ) ;
return - V_24 ;
}
V_60 = F_29 ( V_41 , L_8 , NULL ) ;
V_61 = F_29 ( V_41 , L_9 , NULL ) ;
if ( ! V_60 && ! V_61 ) {
F_12 ( V_2 -> V_23 , L_10 ) ;
return - V_24 ;
}
V_37 = V_31 -> V_66 / sizeof( T_1 ) ;
V_62 = V_60 ? ( V_60 -> V_66 / sizeof( T_1 ) ) : 0 ;
V_63 = V_61 ? ( V_61 -> V_66 / sizeof( T_1 ) ) : 0 ;
if ( V_62 > 1 && V_62 != V_37 ) {
F_12 ( V_2 -> V_23 , L_11 ,
V_37 ) ;
return - V_24 ;
}
if ( V_63 > 1 && V_63 != V_37 ) {
F_12 ( V_2 -> V_23 , L_12 ,
V_37 ) ;
return - V_24 ;
}
V_64 = 0 ;
if ( V_62 )
V_64 ++ ;
if ( V_63 )
V_64 ++ ;
V_58 = V_44 = F_25 ( V_37 * V_64 * sizeof( * V_44 ) ,
V_52 ) ;
if ( ! V_44 )
return - V_53 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
V_65 = F_30 ( V_41 , L_6 , V_38 , & V_16 ) ;
if ( V_65 )
goto V_67;
if ( V_16 >= ( V_2 -> V_68 * 32 ) ) {
F_12 ( V_2 -> V_23 , L_13 ) ;
V_65 = - V_24 ;
goto V_67;
}
if ( V_62 ) {
V_65 = F_30 ( V_41 , L_8 ,
( V_62 > 1 ? V_38 : 0 ) , & V_15 ) ;
if ( V_65 )
goto V_67;
V_65 = F_22 ( V_2 , V_41 , V_16 , V_15 ,
& V_58 ) ;
if ( V_65 )
goto V_67;
}
if ( V_63 ) {
V_65 = F_30 ( V_41 , L_9 ,
( V_63 > 1 ? V_38 : 0 ) , & V_50 ) ;
if ( V_65 )
goto V_67;
V_65 = F_24 ( V_2 , V_41 , V_16 , V_50 ,
& V_58 ) ;
if ( V_65 )
goto V_67;
}
}
* V_46 = V_44 ;
* V_57 = V_37 * V_64 ;
return 0 ;
V_67:
F_26 ( V_8 , V_44 , V_37 * V_64 ) ;
return V_65 ;
}
static int F_31 ( struct V_7 * V_8 , unsigned V_16 ,
unsigned long * V_69 )
{
return - V_70 ;
}
static int F_32 ( struct V_7 * V_8 , unsigned V_16 ,
unsigned long V_69 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
enum V_71 V_72 = F_33 ( V_69 ) ;
T_2 V_73 = F_34 ( V_69 ) ;
T_1 V_17 = F_10 ( V_16 ) ;
T_1 V_18 = F_11 ( V_16 ) ;
T_1 V_74 = V_2 -> V_20 [ V_17 ] . V_74 ;
T_1 V_75 = V_2 -> V_20 [ V_17 ] . V_75 ;
if ( ( V_74 == V_22 ) || ( V_75 == V_22 ) ) {
F_12 ( V_2 -> V_23 , L_14 ,
V_16 ) ;
return - V_24 ;
}
if ( ( V_72 == V_76 ) ||
( V_72 == V_77 ) ) {
if ( V_73 == 0 )
V_72 = V_78 ;
}
switch ( V_72 ) {
case V_78 :
F_4 ( V_2 , V_74 , F_13 ( V_18 ) ) ;
break;
case V_76 :
F_4 ( V_2 , V_75 , F_13 ( V_18 ) ) ;
F_1 ( V_2 , V_74 , F_13 ( V_18 ) ) ;
break;
case V_77 :
F_1 ( V_2 , V_75 , F_13 ( V_18 ) ) ;
F_1 ( V_2 , V_74 , F_13 ( V_18 ) ) ;
break;
default:
F_12 ( V_2 -> V_23 , L_15 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_35 ( struct V_79 * V_80 , unsigned V_35 )
{
return F_36 ( V_80 -> V_6 + V_35 ) ;
}
static void F_37 ( struct V_79 * V_80 , unsigned V_35 )
{
F_38 ( V_80 -> V_6 + V_35 ) ;
}
static int F_39 ( struct V_79 * V_80 , unsigned V_35 )
{
struct V_1 * V_2 = F_40 ( V_80 -> V_23 ) ;
T_1 V_17 = F_10 ( V_35 ) ;
T_1 V_18 = F_11 ( V_35 ) ;
T_1 V_21 = V_2 -> V_20 [ V_17 ] . V_21 ;
T_1 V_5 ;
V_5 = F_2 ( V_2 -> V_6 + V_21 ) ;
if ( V_5 & F_13 ( V_18 ) )
return V_81 ;
else
return V_82 ;
}
static int F_41 ( struct V_79 * V_80 , unsigned V_35 )
{
return F_42 ( V_80 -> V_6 + V_35 ) ;
}
static int F_43 ( struct V_79 * V_80 , unsigned V_35 ,
int V_83 )
{
return F_44 ( V_80 -> V_6 + V_35 ) ;
}
static int F_45 ( struct V_79 * V_80 , unsigned V_35 )
{
struct V_1 * V_2 = F_40 ( V_80 -> V_23 ) ;
T_1 V_17 = F_10 ( V_35 ) ;
T_1 V_18 = F_11 ( V_35 ) ;
T_1 V_84 = V_2 -> V_20 [ V_17 ] . V_84 ;
if ( V_84 == V_22 ) {
F_12 ( V_2 -> V_23 , L_16 ) ;
return - V_24 ;
}
return ! ! ( F_2 ( V_2 -> V_6 + V_84 ) & F_13 ( V_18 ) ) ;
}
static void F_46 ( struct V_79 * V_80 , unsigned V_35 ,
int V_5 )
{
struct V_1 * V_2 = F_40 ( V_80 -> V_23 ) ;
T_1 V_17 = F_10 ( V_35 ) ;
T_1 V_18 = F_11 ( V_35 ) ;
T_1 V_85 = V_2 -> V_20 [ V_17 ] . V_85 ;
if ( V_85 == V_22 ) {
F_12 ( V_2 -> V_23 , L_17 ) ;
return;
}
if ( V_5 )
F_1 ( V_2 , V_85 , F_13 ( V_18 ) ) ;
else
F_4 ( V_2 , V_85 , F_13 ( V_18 ) ) ;
}
int F_47 ( struct V_86 * V_87 ,
struct V_1 * V_2 )
{
int V_65 ;
struct V_88 * V_89 ;
V_89 = F_48 ( V_87 , V_90 , 0 ) ;
V_2 -> V_6 = F_49 ( & V_87 -> V_23 , V_89 ) ;
if ( ! V_2 -> V_6 ) {
F_12 ( & V_87 -> V_23 , L_18 ) ;
return - V_91 ;
}
V_92 . V_31 = V_2 -> V_31 ;
V_92 . V_39 = V_2 -> V_39 ;
V_2 -> V_79 = V_93 ;
V_2 -> V_79 . V_23 = & V_87 -> V_23 ;
V_2 -> V_79 . V_94 = V_87 -> V_23 . V_94 ;
V_2 -> V_79 . V_95 = V_2 -> V_68 * 32 ;
F_50 ( V_87 , V_2 ) ;
V_2 -> V_23 = & V_87 -> V_23 ;
V_2 -> V_96 = F_51 ( & V_92 , & V_87 -> V_23 , V_2 ) ;
if ( ! V_2 -> V_96 ) {
F_12 ( & V_87 -> V_23 , L_19 ) ;
return - V_24 ;
}
V_65 = F_52 ( & V_2 -> V_79 ) ;
if ( V_65 ) {
F_12 ( & V_87 -> V_23 , L_20 ) ;
goto V_97;
}
V_65 = F_53 ( & V_2 -> V_79 , F_54 ( V_2 -> V_23 ) ,
0 , 0 , V_2 -> V_68 * 32 ) ;
if ( V_65 )
goto V_98;
F_55 ( & V_87 -> V_23 , L_21 ) ;
return 0 ;
V_98:
if ( F_56 ( & V_2 -> V_79 ) )
F_12 ( & V_87 -> V_23 , L_22 ) ;
V_97:
F_57 ( V_2 -> V_96 ) ;
return V_65 ;
}
int F_58 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_59 ( V_87 ) ;
int V_65 ;
V_65 = F_56 ( & V_2 -> V_79 ) ;
if ( V_65 )
F_12 ( & V_87 -> V_23 , L_22 ) ;
F_57 ( V_2 -> V_96 ) ;
return 0 ;
}
