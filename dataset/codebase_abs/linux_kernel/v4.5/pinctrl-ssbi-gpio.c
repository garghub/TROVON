static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
unsigned int V_6 = V_5 << 4 ;
int V_7 ;
V_7 = F_2 ( V_2 -> V_8 , V_4 -> V_9 , V_6 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_10 , L_1 , V_5 ) ;
return V_7 ;
}
V_7 = F_4 ( V_2 -> V_8 , V_4 -> V_9 , & V_6 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_10 , L_2 , V_5 ) ;
return V_7 ;
}
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 ,
T_1 V_6 )
{
int V_7 ;
V_6 |= V_11 ;
V_6 |= V_5 << 4 ;
V_7 = F_2 ( V_2 -> V_8 , V_4 -> V_9 , V_6 ) ;
if ( V_7 )
F_3 ( V_2 -> V_10 , L_3 ) ;
return V_7 ;
}
static int F_6 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
return V_2 -> V_14 ;
}
static const char * F_8 ( struct V_12 * V_13 ,
unsigned V_15 )
{
return V_16 [ V_15 ] ;
}
static int F_9 ( struct V_12 * V_13 ,
unsigned V_15 ,
const unsigned * * V_17 ,
unsigned * V_18 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
* V_17 = & V_2 -> V_19 . V_17 [ V_15 ] . V_20 ;
* V_18 = 1 ;
return 0 ;
}
static int F_10 ( struct V_12 * V_13 )
{
return F_11 ( V_21 ) ;
}
static const char * F_12 ( struct V_12 * V_13 ,
unsigned V_22 )
{
return V_21 [ V_22 ] ;
}
static int F_13 ( struct V_12 * V_13 ,
unsigned V_22 ,
const char * const * * V_23 ,
unsigned * const V_24 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
* V_23 = V_16 ;
* V_24 = V_2 -> V_14 ;
return 0 ;
}
static int F_14 ( struct V_12 * V_13 ,
unsigned V_22 ,
unsigned V_15 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_2 -> V_19 . V_17 [ V_15 ] . V_25 ;
T_1 V_6 ;
V_4 -> V_22 = V_22 ;
V_6 = V_4 -> V_22 << 1 ;
F_5 ( V_2 , V_4 , 4 , V_6 ) ;
return 0 ;
}
static int F_15 ( struct V_12 * V_13 ,
unsigned int V_26 ,
unsigned long * V_27 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_2 -> V_19 . V_17 [ V_26 ] . V_25 ;
unsigned V_28 = F_16 ( * V_27 ) ;
unsigned V_29 ;
switch ( V_28 ) {
case V_30 :
V_29 = V_4 -> V_31 == V_32 ;
break;
case V_33 :
V_29 = V_4 -> V_31 == V_34 ;
break;
case V_35 :
V_29 = V_4 -> V_31 <= V_36 ;
break;
case V_37 :
V_29 = V_4 -> V_38 ;
break;
case V_39 :
V_29 = V_4 -> V_40 ;
break;
case V_41 :
V_29 = V_4 -> V_42 == V_43 ;
break;
case V_44 :
if ( V_4 -> V_42 & V_45 )
V_29 = V_4 -> V_46 ;
else
V_29 = 0 ;
break;
case V_47 :
V_29 = V_4 -> V_48 ;
break;
case V_49 :
V_29 = V_4 -> V_50 ;
break;
case V_51 :
V_29 = ! V_4 -> V_52 ;
break;
case V_53 :
V_29 = V_4 -> V_52 ;
break;
default:
return - V_54 ;
}
* V_27 = F_17 ( V_28 , V_29 ) ;
return 0 ;
}
static int F_18 ( struct V_12 * V_13 ,
unsigned int V_26 ,
unsigned long * V_55 ,
unsigned V_56 )
{
struct V_1 * V_2 = F_7 ( V_13 ) ;
struct V_3 * V_4 = V_2 -> V_19 . V_17 [ V_26 ] . V_25 ;
unsigned V_28 ;
unsigned V_29 ;
unsigned V_57 ;
T_1 V_58 = 0 ;
T_1 V_6 ;
for ( V_57 = 0 ; V_57 < V_56 ; V_57 ++ ) {
V_28 = F_16 ( V_55 [ V_57 ] ) ;
V_29 = F_19 ( V_55 [ V_57 ] ) ;
switch ( V_28 ) {
case V_30 :
V_4 -> V_31 = V_32 ;
V_58 |= F_20 ( 2 ) ;
V_4 -> V_40 = 0 ;
V_58 |= F_20 ( 3 ) ;
break;
case V_33 :
V_4 -> V_31 = V_34 ;
V_58 |= F_20 ( 2 ) ;
V_4 -> V_40 = 0 ;
V_58 |= F_20 ( 3 ) ;
break;
case V_37 :
if ( V_29 > V_36 ) {
F_3 ( V_2 -> V_10 , L_4 ) ;
return - V_54 ;
}
V_4 -> V_38 = V_29 ;
case V_35 :
V_4 -> V_31 = V_4 -> V_38 ;
V_58 |= F_20 ( 2 ) ;
V_4 -> V_40 = 0 ;
V_58 |= F_20 ( 3 ) ;
break;
case V_39 :
V_4 -> V_40 = 1 ;
V_58 |= F_20 ( 3 ) ;
break;
case V_41 :
V_4 -> V_42 = V_43 ;
V_58 |= F_20 ( 0 ) | F_20 ( 1 ) ;
break;
case V_44 :
V_4 -> V_42 = V_45 ;
V_4 -> V_46 = ! ! V_29 ;
V_58 |= F_20 ( 0 ) | F_20 ( 1 ) ;
break;
case V_47 :
V_4 -> V_48 = V_29 ;
V_58 |= F_20 ( 0 ) ;
break;
case V_49 :
if ( V_29 > V_59 ) {
F_3 ( V_2 -> V_10 , L_5 ) ;
return - V_54 ;
}
V_4 -> V_50 = V_29 ;
V_58 |= F_20 ( 3 ) ;
break;
case V_51 :
V_4 -> V_52 = 0 ;
V_58 |= F_20 ( 1 ) ;
break;
case V_53 :
V_4 -> V_52 = 1 ;
V_58 |= F_20 ( 1 ) ;
break;
default:
F_3 ( V_2 -> V_10 ,
L_6 ,
V_28 ) ;
return - V_54 ;
}
}
if ( V_58 & F_20 ( 0 ) ) {
V_6 = V_4 -> V_48 << 1 ;
V_6 |= V_60 ;
F_5 ( V_2 , V_4 , 0 , V_6 ) ;
}
if ( V_58 & F_20 ( 1 ) ) {
V_6 = V_4 -> V_42 << 2 ;
V_6 |= V_4 -> V_52 << 1 ;
V_6 |= V_4 -> V_46 ;
F_5 ( V_2 , V_4 , 1 , V_6 ) ;
}
if ( V_58 & F_20 ( 2 ) ) {
V_6 = V_4 -> V_31 << 1 ;
F_5 ( V_2 , V_4 , 2 , V_6 ) ;
}
if ( V_58 & F_20 ( 3 ) ) {
V_6 = V_4 -> V_50 << 2 ;
V_6 |= V_4 -> V_40 ;
F_5 ( V_2 , V_4 , 3 , V_6 ) ;
}
if ( V_58 & F_20 ( 4 ) ) {
V_6 = V_4 -> V_22 << 1 ;
F_5 ( V_2 , V_4 , 4 , V_6 ) ;
}
if ( V_58 & F_20 ( 5 ) ) {
V_6 = 0 ;
if ( ! V_4 -> V_61 )
V_6 |= F_20 ( 3 ) ;
F_5 ( V_2 , V_4 , 5 , V_6 ) ;
}
return 0 ;
}
static int F_21 ( struct V_62 * V_63 ,
unsigned V_26 )
{
struct V_1 * V_2 = F_22 ( V_63 ) ;
struct V_3 * V_4 = V_2 -> V_19 . V_17 [ V_26 ] . V_25 ;
T_1 V_6 ;
V_4 -> V_42 = V_43 ;
V_6 = V_4 -> V_42 << 2 ;
F_5 ( V_2 , V_4 , 1 , V_6 ) ;
return 0 ;
}
static int F_23 ( struct V_62 * V_63 ,
unsigned V_26 ,
int V_64 )
{
struct V_1 * V_2 = F_22 ( V_63 ) ;
struct V_3 * V_4 = V_2 -> V_19 . V_17 [ V_26 ] . V_25 ;
T_1 V_6 ;
V_4 -> V_42 = V_45 ;
V_4 -> V_46 = ! ! V_64 ;
V_6 = V_4 -> V_42 << 2 ;
V_6 |= V_4 -> V_52 << 1 ;
V_6 |= V_4 -> V_46 ;
F_5 ( V_2 , V_4 , 1 , V_6 ) ;
return 0 ;
}
static int F_24 ( struct V_62 * V_63 , unsigned V_26 )
{
struct V_1 * V_2 = F_22 ( V_63 ) ;
struct V_3 * V_4 = V_2 -> V_19 . V_17 [ V_26 ] . V_25 ;
bool V_65 ;
int V_7 ;
if ( V_4 -> V_42 == V_45 ) {
V_7 = V_4 -> V_46 ;
} else {
V_7 = F_25 ( V_4 -> V_66 , V_67 , & V_65 ) ;
if ( ! V_7 )
V_7 = ! ! V_65 ;
}
return V_7 ;
}
static void F_26 ( struct V_62 * V_63 , unsigned V_26 , int V_64 )
{
struct V_1 * V_2 = F_22 ( V_63 ) ;
struct V_3 * V_4 = V_2 -> V_19 . V_17 [ V_26 ] . V_25 ;
T_1 V_6 ;
V_4 -> V_46 = ! ! V_64 ;
V_6 = V_4 -> V_42 << 2 ;
V_6 |= V_4 -> V_52 << 1 ;
V_6 |= V_4 -> V_46 ;
F_5 ( V_2 , V_4 , 1 , V_6 ) ;
}
static int F_27 ( struct V_62 * V_63 ,
const struct V_68 * V_69 ,
T_2 * V_70 )
{
if ( V_63 -> V_71 < 2 )
return - V_54 ;
if ( V_70 )
* V_70 = V_69 -> args [ 1 ] ;
return V_69 -> args [ 0 ] - 1 ;
}
static int F_28 ( struct V_62 * V_63 , unsigned V_26 )
{
struct V_1 * V_2 = F_22 ( V_63 ) ;
struct V_3 * V_4 = V_2 -> V_19 . V_17 [ V_26 ] . V_25 ;
return V_4 -> V_66 ;
}
static void F_29 ( struct V_72 * V_73 ,
struct V_12 * V_13 ,
struct V_62 * V_63 ,
unsigned V_26 ,
unsigned V_74 )
{
struct V_1 * V_2 = F_22 ( V_63 ) ;
struct V_3 * V_4 = V_2 -> V_19 . V_17 [ V_26 ] . V_25 ;
static const char * const V_75 [] = {
L_7 , L_8 , L_9 , L_10
} ;
static const char * const V_76 [] = {
L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16
} ;
static const char * const V_77 [] = {
L_17 , L_18
} ;
static const char * const V_78 [] = {
L_19 , L_20 , L_21 , L_22
} ;
F_30 ( V_73 , L_23 , V_26 + 1 ) ;
if ( V_4 -> V_40 ) {
F_31 ( V_73 , L_24 ) ;
} else {
F_30 ( V_73 , L_25 , V_75 [ V_4 -> V_42 ] ) ;
F_30 ( V_73 , L_26 , V_21 [ V_4 -> V_22 ] ) ;
F_30 ( V_73 , L_27 , V_4 -> V_48 ) ;
F_30 ( V_73 , L_28 , V_76 [ V_4 -> V_31 ] ) ;
F_30 ( V_73 , L_29 , V_77 [ V_4 -> V_52 ] ) ;
F_30 ( V_73 , L_25 , V_4 -> V_46 ? L_20 : L_22 ) ;
F_30 ( V_73 , L_26 , V_78 [ V_4 -> V_50 ] ) ;
if ( V_4 -> V_61 )
F_31 ( V_73 , L_30 ) ;
}
}
static void F_32 ( struct V_72 * V_73 , struct V_62 * V_63 )
{
unsigned V_74 = V_63 -> V_79 ;
unsigned V_57 ;
for ( V_57 = 0 ; V_57 < V_63 -> V_80 ; V_57 ++ , V_74 ++ ) {
F_29 ( V_73 , NULL , V_63 , V_57 , V_74 ) ;
F_31 ( V_73 , L_31 ) ;
}
}
static int F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_6 ;
V_6 = F_1 ( V_2 , V_4 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_48 = ( V_6 >> 1 ) & 0x7 ;
V_6 = F_1 ( V_2 , V_4 , 1 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_42 = ( V_6 >> 2 ) & 0x3 ;
V_4 -> V_52 = ! ! ( V_6 & F_20 ( 1 ) ) ;
V_4 -> V_46 = V_6 & F_20 ( 0 ) ;
V_6 = F_1 ( V_2 , V_4 , 2 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_31 = ( V_6 >> 1 ) & 0x7 ;
if ( V_4 -> V_31 <= V_36 )
V_4 -> V_38 = V_4 -> V_31 ;
else
V_4 -> V_38 = V_81 ;
V_6 = F_1 ( V_2 , V_4 , 3 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_50 = ( V_6 >> 2 ) & 0x3 ;
V_4 -> V_40 = V_6 & F_20 ( 0 ) ;
V_6 = F_1 ( V_2 , V_4 , 4 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_22 = ( V_6 >> 1 ) & 0x7 ;
V_6 = F_1 ( V_2 , V_4 , 5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_4 -> V_61 = ! ( V_6 & F_20 ( 3 ) ) ;
return 0 ;
}
static int F_34 ( struct V_82 * V_83 )
{
struct V_3 * V_84 ;
struct V_85 * V_17 ;
struct V_1 * V_2 ;
int V_7 ;
int V_57 , V_14 ;
V_2 = F_35 ( & V_83 -> V_10 , sizeof( * V_2 ) , V_86 ) ;
if ( ! V_2 )
return - V_87 ;
V_2 -> V_10 = & V_83 -> V_10 ;
V_14 = F_36 ( V_83 ) ;
if ( ! V_14 )
return - V_54 ;
if ( V_14 < 0 )
return V_14 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_8 = F_37 ( V_83 -> V_10 . V_88 , NULL ) ;
if ( ! V_2 -> V_8 ) {
F_3 ( & V_83 -> V_10 , L_32 ) ;
return - V_89 ;
}
V_2 -> V_19 = V_90 ;
V_2 -> V_19 . V_14 = V_2 -> V_14 ;
V_17 = F_38 ( & V_83 -> V_10 ,
V_2 -> V_19 . V_14 ,
sizeof( struct V_85 ) ,
V_86 ) ;
if ( ! V_17 )
return - V_87 ;
V_84 = F_38 ( & V_83 -> V_10 ,
V_2 -> V_19 . V_14 ,
sizeof( struct V_3 ) ,
V_86 ) ;
if ( ! V_84 )
return - V_87 ;
for ( V_57 = 0 ; V_57 < V_2 -> V_19 . V_14 ; V_57 ++ ) {
V_84 [ V_57 ] . V_9 = F_39 ( V_57 ) ;
V_84 [ V_57 ] . V_66 = F_40 ( V_83 , V_57 ) ;
if ( V_84 [ V_57 ] . V_66 < 0 ) {
F_3 ( & V_83 -> V_10 ,
L_33 , V_57 ) ;
return V_84 [ V_57 ] . V_66 ;
}
V_7 = F_33 ( V_2 , & V_84 [ V_57 ] ) ;
if ( V_7 )
return V_7 ;
V_17 [ V_57 ] . V_20 = V_57 ;
V_17 [ V_57 ] . V_91 = V_16 [ V_57 ] ;
V_17 [ V_57 ] . V_25 = & V_84 [ V_57 ] ;
}
V_2 -> V_19 . V_17 = V_17 ;
V_2 -> V_19 . V_92 = F_11 ( V_93 ) ;
V_2 -> V_19 . V_94 = V_93 ;
#ifdef F_41
V_2 -> V_19 . V_95 = V_96 ;
#endif
V_2 -> V_2 = F_42 ( & V_2 -> V_19 , & V_83 -> V_10 , V_2 ) ;
if ( F_43 ( V_2 -> V_2 ) ) {
F_3 ( & V_83 -> V_10 , L_34 ) ;
return F_44 ( V_2 -> V_2 ) ;
}
V_2 -> V_63 = V_97 ;
V_2 -> V_63 . V_79 = - 1 ;
V_2 -> V_63 . V_88 = & V_83 -> V_10 ;
V_2 -> V_63 . V_98 = V_83 -> V_10 . V_98 ;
V_2 -> V_63 . V_71 = 2 ;
V_2 -> V_63 . V_99 = F_45 ( V_2 -> V_10 ) ;
V_2 -> V_63 . V_80 = V_2 -> V_14 ;
V_7 = F_46 ( & V_2 -> V_63 , V_2 ) ;
if ( V_7 ) {
F_3 ( & V_83 -> V_10 , L_35 ) ;
goto V_100;
}
V_7 = F_47 ( & V_2 -> V_63 ,
F_45 ( V_2 -> V_10 ) ,
0 , 0 , V_2 -> V_63 . V_80 ) ;
if ( V_7 ) {
F_3 ( V_2 -> V_10 , L_36 ) ;
goto V_101;
}
F_48 ( V_83 , V_2 ) ;
F_49 ( & V_83 -> V_10 , L_37 ) ;
return 0 ;
V_101:
F_50 ( & V_2 -> V_63 ) ;
V_100:
F_51 ( V_2 -> V_2 ) ;
return V_7 ;
}
static int F_52 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_53 ( V_83 ) ;
F_50 ( & V_2 -> V_63 ) ;
F_51 ( V_2 -> V_2 ) ;
return 0 ;
}
