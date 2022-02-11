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
struct V_33 * V_34 ,
unsigned V_35 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
F_9 ( V_2 , V_25 , V_35 ) ;
}
static int F_16 ( struct V_7 * V_8 ,
struct V_33 * V_34 ,
unsigned V_35 ,
bool V_36 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
F_9 ( V_2 , ( V_36 ? V_25 : V_26 ) ,
V_35 ) ;
return 0 ;
}
static int F_17 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
return V_2 -> V_14 ;
}
static const char * F_18 ( struct V_7 * V_8 ,
unsigned V_10 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
return V_2 -> V_12 [ V_10 ] ;
}
static int F_19 ( struct V_7 * V_8 ,
unsigned V_10 ,
const unsigned * * V_31 ,
unsigned * V_37 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
* V_31 = & V_2 -> V_31 [ V_10 ] . V_32 ;
* V_37 = 1 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_16 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_2 -> V_39 ; V_38 ++ ) {
if ( V_2 -> V_31 [ V_38 ] . V_32 == V_16 )
return V_38 ;
}
return - V_24 ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_40 * V_41 ,
T_1 V_16 , T_1 V_42 ,
struct V_43 * * V_44 )
{
int V_45 ;
struct V_43 * V_46 = * V_44 ;
if ( V_42 >= F_22 ( V_11 ) ) {
F_12 ( V_2 -> V_23 , L_3 , V_42 ) ;
return - V_24 ;
}
V_45 = F_20 ( V_2 , V_16 ) ;
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
static int F_23 ( struct V_1 * V_2 ,
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
V_45 = F_20 ( V_2 , V_16 ) ;
if ( V_45 < 0 ) {
F_12 ( V_2 -> V_23 , L_4 , V_16 ) ;
return V_45 ;
}
V_51 = F_24 ( sizeof( * V_51 ) , V_52 ) ;
if ( ! V_51 )
return - V_53 ;
switch ( V_50 ) {
case 0 :
V_51 [ 0 ] = V_54 ;
break;
case 1 :
V_51 [ 0 ] = V_55 ;
break;
case 2 :
V_51 [ 0 ] = V_56 ;
break;
default:
V_51 [ 0 ] = V_54 ;
F_12 ( V_2 -> V_23 , L_6 , V_50 ) ;
}
V_46 -> type = V_57 ;
V_46 -> V_2 . V_51 . V_58 = V_2 -> V_12 [ V_45 ] ;
V_46 -> V_2 . V_51 . V_51 = V_51 ;
V_46 -> V_2 . V_51 . V_59 = 1 ;
( * V_44 ) ++ ;
return 0 ;
}
static void F_25 ( struct V_7 * V_8 ,
struct V_43 * V_44 ,
unsigned V_60 )
{
int V_38 ;
for ( V_38 = 0 ; V_38 < V_60 ; V_38 ++ )
if ( V_44 [ V_38 ] . type == V_57 )
F_26 ( V_44 [ V_38 ] . V_2 . V_51 . V_51 ) ;
F_26 ( V_44 ) ;
}
static int F_27 ( struct V_7 * V_8 ,
struct V_40 * V_41 ,
struct V_43 * * V_46 ,
unsigned * V_60 )
{
struct V_43 * V_44 , * V_61 ;
struct V_62 * V_31 , * V_63 , * V_64 ;
T_1 V_16 , V_15 , V_50 ;
int V_37 , V_65 , V_66 , V_67 ;
int V_38 , V_68 ;
struct V_1 * V_2 = F_8 ( V_8 ) ;
V_31 = F_28 ( V_41 , L_7 , NULL ) ;
if ( ! V_31 ) {
F_12 ( V_2 -> V_23 , L_8 ) ;
return - V_24 ;
}
V_63 = F_28 ( V_41 , L_9 , NULL ) ;
V_64 = F_28 ( V_41 , L_10 , NULL ) ;
if ( ! V_63 && ! V_64 ) {
F_12 ( V_2 -> V_23 , L_11 ) ;
return - V_24 ;
}
V_37 = V_31 -> V_69 / sizeof( T_1 ) ;
V_65 = V_63 ? ( V_63 -> V_69 / sizeof( T_1 ) ) : 0 ;
V_66 = V_64 ? ( V_64 -> V_69 / sizeof( T_1 ) ) : 0 ;
if ( V_65 > 1 && V_65 != V_37 ) {
F_12 ( V_2 -> V_23 , L_12 ,
V_37 ) ;
return - V_24 ;
}
if ( V_66 > 1 && V_66 != V_37 ) {
F_12 ( V_2 -> V_23 , L_13 ,
V_37 ) ;
return - V_24 ;
}
V_67 = 0 ;
if ( V_65 )
V_67 ++ ;
if ( V_66 )
V_67 ++ ;
V_61 = V_44 = F_24 ( V_37 * V_67 * sizeof( * V_44 ) ,
V_52 ) ;
if ( ! V_44 )
return - V_53 ;
for ( V_38 = 0 ; V_38 < V_37 ; V_38 ++ ) {
V_68 = F_29 ( V_41 , L_7 , V_38 , & V_16 ) ;
if ( V_68 )
goto V_70;
if ( V_16 >= ( V_2 -> V_71 * 32 ) ) {
F_12 ( V_2 -> V_23 , L_14 ) ;
V_68 = - V_24 ;
goto V_70;
}
if ( V_65 ) {
V_68 = F_29 ( V_41 , L_9 ,
( V_65 > 1 ? V_38 : 0 ) , & V_15 ) ;
if ( V_68 )
goto V_70;
V_68 = F_21 ( V_2 , V_41 , V_16 , V_15 ,
& V_61 ) ;
if ( V_68 )
goto V_70;
}
if ( V_66 ) {
V_68 = F_29 ( V_41 , L_10 ,
( V_66 > 1 ? V_38 : 0 ) , & V_50 ) ;
if ( V_68 )
goto V_70;
V_68 = F_23 ( V_2 , V_41 , V_16 , V_50 ,
& V_61 ) ;
if ( V_68 )
goto V_70;
}
}
* V_46 = V_44 ;
* V_60 = V_37 * V_67 ;
return 0 ;
V_70:
F_25 ( V_8 , V_44 , V_37 * V_67 ) ;
return V_68 ;
}
static int F_30 ( struct V_7 * V_8 , unsigned V_16 ,
unsigned long * V_72 )
{
return - V_73 ;
}
static int F_31 ( struct V_7 * V_8 , unsigned V_16 ,
unsigned long * V_51 , unsigned V_59 )
{
struct V_1 * V_2 = F_8 ( V_8 ) ;
enum V_74 V_75 ;
T_2 V_76 ;
T_1 V_17 = F_10 ( V_16 ) ;
T_1 V_18 = F_11 ( V_16 ) ;
T_1 V_77 = V_2 -> V_20 [ V_17 ] . V_77 ;
T_1 V_78 = V_2 -> V_20 [ V_17 ] . V_78 ;
int V_38 ;
if ( ( V_77 == V_22 ) || ( V_78 == V_22 ) ) {
F_12 ( V_2 -> V_23 , L_15 ,
V_16 ) ;
return - V_24 ;
}
for ( V_38 = 0 ; V_38 < V_59 ; V_38 ++ ) {
V_75 = F_32 ( V_51 [ V_38 ] ) ;
V_76 = F_33 ( V_51 [ V_38 ] ) ;
if ( ( V_75 == V_55 ) ||
( V_75 == V_56 ) ) {
if ( V_76 == 0 )
V_75 = V_54 ;
}
switch ( V_75 ) {
case V_54 :
F_4 ( V_2 , V_77 , F_13 ( V_18 ) ) ;
break;
case V_55 :
F_4 ( V_2 , V_78 , F_13 ( V_18 ) ) ;
F_1 ( V_2 , V_77 , F_13 ( V_18 ) ) ;
break;
case V_56 :
F_1 ( V_2 , V_78 , F_13 ( V_18 ) ) ;
F_1 ( V_2 , V_77 , F_13 ( V_18 ) ) ;
break;
default:
F_12 ( V_2 -> V_23 , L_16 ) ;
return - V_24 ;
}
}
return 0 ;
}
static int F_34 ( struct V_79 * V_80 , unsigned V_35 )
{
struct V_1 * V_2 = F_35 ( V_80 -> V_23 ) ;
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
static int F_36 ( struct V_79 * V_80 , unsigned V_35 )
{
struct V_1 * V_2 = F_35 ( V_80 -> V_23 ) ;
T_1 V_17 = F_10 ( V_35 ) ;
T_1 V_18 = F_11 ( V_35 ) ;
T_1 V_83 = V_2 -> V_20 [ V_17 ] . V_83 ;
if ( V_83 == V_22 ) {
F_12 ( V_2 -> V_23 , L_17 ) ;
return - V_24 ;
}
return ! ! ( F_2 ( V_2 -> V_6 + V_83 ) & F_13 ( V_18 ) ) ;
}
static void F_37 ( struct V_79 * V_80 , unsigned V_35 ,
int V_5 )
{
struct V_1 * V_2 = F_35 ( V_80 -> V_23 ) ;
T_1 V_17 = F_10 ( V_35 ) ;
T_1 V_18 = F_11 ( V_35 ) ;
T_1 V_84 = V_2 -> V_20 [ V_17 ] . V_84 ;
if ( V_84 == V_22 ) {
F_12 ( V_2 -> V_23 , L_18 ) ;
return;
}
if ( V_5 )
F_1 ( V_2 , V_84 , F_13 ( V_18 ) ) ;
else
F_4 ( V_2 , V_84 , F_13 ( V_18 ) ) ;
}
static int F_38 ( struct V_79 * V_80 , unsigned V_35 )
{
return F_39 ( V_80 -> V_6 + V_35 ) ;
}
static int F_40 ( struct V_79 * V_80 , unsigned V_35 ,
int V_85 )
{
F_37 ( V_80 , V_35 , V_85 ) ;
return F_41 ( V_80 -> V_6 + V_35 ) ;
}
int F_42 ( struct V_86 * V_87 ,
struct V_1 * V_2 )
{
int V_68 ;
struct V_88 * V_89 ;
V_89 = F_43 ( V_87 , V_90 , 0 ) ;
V_2 -> V_6 = F_44 ( & V_87 -> V_23 , V_89 ) ;
if ( F_45 ( V_2 -> V_6 ) )
return F_46 ( V_2 -> V_6 ) ;
V_91 . V_31 = V_2 -> V_31 ;
V_91 . V_39 = V_2 -> V_39 ;
V_2 -> V_79 = V_92 ;
V_2 -> V_79 . V_23 = & V_87 -> V_23 ;
V_2 -> V_79 . V_93 = V_87 -> V_23 . V_93 ;
V_2 -> V_79 . V_94 = V_2 -> V_71 * 32 ;
F_47 ( V_87 , V_2 ) ;
V_2 -> V_23 = & V_87 -> V_23 ;
V_2 -> V_95 = F_48 ( & V_91 , & V_87 -> V_23 , V_2 ) ;
if ( F_45 ( V_2 -> V_95 ) ) {
F_12 ( & V_87 -> V_23 , L_19 ) ;
return F_46 ( V_2 -> V_95 ) ;
}
V_68 = F_49 ( & V_2 -> V_79 ) ;
if ( V_68 ) {
F_12 ( & V_87 -> V_23 , L_20 ) ;
goto V_96;
}
V_68 = F_50 ( & V_2 -> V_79 , F_51 ( V_2 -> V_23 ) ,
0 , 0 , V_2 -> V_71 * 32 ) ;
if ( V_68 )
goto V_97;
F_52 ( & V_87 -> V_23 , L_21 ) ;
return 0 ;
V_97:
F_53 ( & V_2 -> V_79 ) ;
V_96:
F_54 ( V_2 -> V_95 ) ;
return V_68 ;
}
int F_55 ( struct V_86 * V_87 )
{
struct V_1 * V_2 = F_56 ( V_87 ) ;
F_53 ( & V_2 -> V_79 ) ;
F_54 ( V_2 -> V_95 ) ;
return 0 ;
}
