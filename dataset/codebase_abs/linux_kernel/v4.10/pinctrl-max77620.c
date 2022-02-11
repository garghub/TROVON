static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 (
struct V_1 * V_2 , unsigned int V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
static int F_4 (
struct V_1 * V_2 , unsigned int V_6 ,
const unsigned int * * V_9 , unsigned int * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_9 = V_4 -> V_7 [ V_6 ] . V_9 ;
* V_10 = V_4 -> V_7 [ V_6 ] . V_11 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_12 ;
}
static const char * F_6 ( struct V_1 * V_2 ,
unsigned int V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_14 [ V_13 ] . V_8 ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_13 ,
const char * const * * V_15 ,
unsigned int * const V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_15 = V_4 -> V_14 [ V_13 ] . V_15 ;
* V_16 = V_4 -> V_14 [ V_13 ] . V_17 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_13 , unsigned int V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_18 ;
int V_19 ;
if ( V_13 == V_20 ) {
V_18 = 0 ;
} else if ( V_13 == V_4 -> V_7 [ V_6 ] . V_21 ) {
V_18 = 1 << V_6 ;
} else {
F_9 ( V_4 -> V_22 , L_1 ,
V_6 , V_13 ) ;
return - V_23 ;
}
V_19 = F_10 ( V_4 -> V_24 , V_25 ,
F_11 ( V_6 ) , V_18 ) ;
if ( V_19 < 0 )
F_9 ( V_4 -> V_22 , L_2 , V_19 ) ;
return V_19 ;
}
static int F_12 ( struct V_1 * V_2 ,
unsigned int V_26 , unsigned long * V_27 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_28 * V_22 = V_4 -> V_22 ;
enum V_29 V_30 = F_13 ( * V_27 ) ;
unsigned int V_18 ;
int V_31 = 0 ;
int V_19 ;
switch ( V_30 ) {
case V_32 :
if ( V_4 -> V_33 [ V_26 ] . V_34 == V_35 )
V_31 = 1 ;
break;
case V_36 :
if ( V_4 -> V_33 [ V_26 ] . V_34 == V_37 )
V_31 = 1 ;
break;
case V_38 :
V_19 = F_14 ( V_4 -> V_24 , V_39 , & V_18 ) ;
if ( V_19 < 0 ) {
F_9 ( V_22 , L_3 , V_19 ) ;
return V_19 ;
}
if ( V_18 & F_11 ( V_26 ) )
V_31 = 1 ;
break;
case V_40 :
V_19 = F_14 ( V_4 -> V_24 , V_41 , & V_18 ) ;
if ( V_19 < 0 ) {
F_9 ( V_22 , L_4 , V_19 ) ;
return V_19 ;
}
if ( V_18 & F_11 ( V_26 ) )
V_31 = 1 ;
break;
default:
F_9 ( V_22 , L_5 ) ;
return - V_42 ;
}
* V_27 = F_15 ( V_30 , ( V_43 ) V_31 ) ;
return 0 ;
}
static int F_16 ( struct V_3 * V_4 ,
int V_44 , int * V_45 )
{
unsigned int V_18 ;
int V_19 ;
V_19 = F_14 ( V_4 -> V_24 , V_44 , & V_18 ) ;
if ( V_19 < 0 ) {
F_9 ( V_4 -> V_22 , L_3 , V_19 ) ;
return V_19 ;
}
* V_45 = ( V_18 & V_46 ) >> V_47 ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 ,
int V_26 , int V_30 )
{
struct V_48 * V_49 = & V_4 -> V_49 [ V_26 ] ;
int V_44 , V_19 ;
int V_50 ;
int V_51 , V_52 ;
if ( ( V_26 < V_53 ) || ( V_26 > V_54 ) )
return 0 ;
V_44 = V_55 + V_26 - 1 ;
switch ( V_30 ) {
case V_56 :
case V_57 :
V_51 = V_46 ;
V_52 = V_47 ;
V_50 = V_49 -> V_58 ;
if ( V_30 == V_57 )
V_50 = V_49 -> V_59 ;
break;
case V_60 :
case V_61 :
V_51 = V_62 ;
V_52 = V_63 ;
V_50 = V_49 -> V_64 ;
if ( V_30 == V_61 )
V_50 = V_49 -> V_65 ;
break;
case V_66 :
case V_67 :
V_51 = V_68 ;
V_52 = V_69 ;
V_50 = V_49 -> V_70 ;
if ( V_30 == V_67 )
V_50 = V_49 -> V_71 ;
break;
default:
F_9 ( V_4 -> V_22 , L_6 ,
V_30 , V_26 ) ;
return - V_23 ;
}
if ( V_50 < 0 )
return 0 ;
V_19 = F_10 ( V_4 -> V_24 , V_44 , V_51 , V_50 << V_52 ) ;
if ( V_19 < 0 )
F_9 ( V_4 -> V_22 , L_7 , V_44 , V_19 ) ;
return V_19 ;
}
static int F_18 ( struct V_1 * V_2 ,
unsigned int V_26 , unsigned long * V_72 ,
unsigned int V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_28 * V_22 = V_4 -> V_22 ;
struct V_48 * V_49 ;
int V_30 ;
V_43 V_50 ;
unsigned int V_18 ;
unsigned int V_74 ;
unsigned int V_75 ;
int V_44 , V_19 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_73 ; V_76 ++ ) {
V_30 = F_13 ( V_72 [ V_76 ] ) ;
V_50 = F_19 ( V_72 [ V_76 ] ) ;
switch ( V_30 ) {
case V_32 :
V_18 = V_50 ? 0 : 1 ;
V_19 = F_10 ( V_4 -> V_24 ,
V_77 + V_26 ,
V_78 ,
V_18 ) ;
if ( V_19 < 0 ) {
F_9 ( V_22 , L_7 ,
V_77 + V_26 , V_19 ) ;
return V_19 ;
}
V_4 -> V_33 [ V_26 ] . V_34 = V_18 ?
V_37 : V_35 ;
break;
case V_36 :
V_18 = V_50 ? 1 : 0 ;
V_19 = F_10 ( V_4 -> V_24 ,
V_77 + V_26 ,
V_78 ,
V_18 ) ;
if ( V_19 < 0 ) {
F_9 ( V_22 , L_7 ,
V_77 + V_26 , V_19 ) ;
return V_19 ;
}
V_4 -> V_33 [ V_26 ] . V_34 = V_18 ?
V_37 : V_35 ;
break;
case V_56 :
case V_60 :
case V_66 :
if ( ( V_26 < V_53 ) || ( V_26 > V_54 ) )
return - V_23 ;
V_49 = & V_4 -> V_49 [ V_26 ] ;
if ( ( V_30 == V_56 ) &&
( V_50 == V_79 ) ) {
V_44 = V_55 + V_26 - 1 ;
V_19 = F_16 (
V_4 , V_44 ,
& V_49 -> V_58 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
}
if ( V_30 == V_56 )
V_49 -> V_58 = V_50 ;
else if ( V_30 == V_60 )
V_49 -> V_64 = V_50 ;
else
V_49 -> V_70 = V_50 ;
V_19 = F_17 ( V_4 , V_26 , V_30 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
case V_57 :
case V_61 :
case V_67 :
if ( ( V_26 < V_53 ) || ( V_26 > V_54 ) )
return - V_23 ;
V_49 = & V_4 -> V_49 [ V_26 ] ;
if ( ( V_30 == V_57 ) &&
( V_50 == V_79 ) ) {
V_44 = V_55 + V_26 - 1 ;
V_19 = F_16 (
V_4 , V_44 ,
& V_49 -> V_59 ) ;
if ( V_19 < 0 )
return V_19 ;
break;
}
if ( V_30 == V_57 )
V_49 -> V_59 = V_50 ;
else if ( V_30 == V_61 )
V_49 -> V_65 = V_50 ;
else
V_49 -> V_71 =
V_50 ;
break;
case V_38 :
case V_40 :
V_74 = ( V_30 == V_38 ) ?
F_11 ( V_26 ) : 0 ;
V_75 = ( V_30 == V_40 ) ?
F_11 ( V_26 ) : 0 ;
V_19 = F_10 ( V_4 -> V_24 ,
V_39 ,
F_11 ( V_26 ) , V_74 ) ;
if ( V_19 < 0 ) {
F_9 ( V_22 , L_8 ,
V_19 ) ;
return V_19 ;
}
V_19 = F_10 ( V_4 -> V_24 ,
V_41 ,
F_11 ( V_26 ) , V_75 ) ;
if ( V_19 < 0 ) {
F_9 ( V_22 , L_9 ,
V_19 ) ;
return V_19 ;
}
break;
default:
F_9 ( V_22 , L_5 ) ;
return - V_42 ;
}
}
return 0 ;
}
static int F_20 ( struct V_80 * V_81 )
{
struct V_82 * V_83 = F_21 ( V_81 -> V_22 . V_84 ) ;
struct V_3 * V_4 ;
int V_76 ;
V_4 = F_22 ( & V_81 -> V_22 , sizeof( * V_4 ) , V_85 ) ;
if ( ! V_4 )
return - V_86 ;
V_4 -> V_22 = & V_81 -> V_22 ;
V_4 -> V_22 -> V_87 = V_81 -> V_22 . V_84 -> V_87 ;
V_4 -> V_24 = V_83 -> V_24 ;
V_4 -> V_9 = V_88 ;
V_4 -> V_10 = F_23 ( V_88 ) ;
V_4 -> V_14 = V_89 ;
V_4 -> V_12 = F_23 ( V_89 ) ;
V_4 -> V_7 = V_90 ;
V_4 -> V_5 = F_23 ( V_90 ) ;
F_24 ( V_81 , V_4 ) ;
V_91 . V_8 = F_25 ( & V_81 -> V_22 ) ;
V_91 . V_9 = V_88 ;
V_91 . V_11 = F_23 ( V_88 ) ;
V_91 . V_92 =
F_23 ( V_93 ) ;
V_91 . V_94 = V_93 ;
for ( V_76 = 0 ; V_76 < V_95 ; ++ V_76 ) {
V_4 -> V_49 [ V_76 ] . V_58 = - 1 ;
V_4 -> V_49 [ V_76 ] . V_64 = - 1 ;
V_4 -> V_49 [ V_76 ] . V_70 = - 1 ;
V_4 -> V_49 [ V_76 ] . V_59 = - 1 ;
V_4 -> V_49 [ V_76 ] . V_65 = - 1 ;
V_4 -> V_49 [ V_76 ] . V_71 = - 1 ;
}
V_4 -> V_96 = F_26 ( & V_81 -> V_22 , & V_91 ,
V_4 ) ;
if ( F_27 ( V_4 -> V_96 ) ) {
F_9 ( & V_81 -> V_22 , L_10 ) ;
return F_28 ( V_4 -> V_96 ) ;
}
return 0 ;
}
static int F_29 ( struct V_28 * V_22 )
{
struct V_3 * V_4 = F_21 ( V_22 ) ;
int V_26 , V_97 ;
for ( V_26 = 0 ; V_26 < V_95 ; ++ V_26 ) {
if ( ( V_26 < V_53 ) || ( V_26 > V_54 ) )
continue;
for ( V_97 = 0 ; V_97 < 3 ; ++ V_97 )
F_17 (
V_4 , V_26 , V_98 [ V_97 ] ) ;
}
return 0 ;
}
static int F_30 ( struct V_28 * V_22 )
{
struct V_3 * V_4 = F_21 ( V_22 ) ;
int V_26 , V_97 ;
for ( V_26 = 0 ; V_26 < V_95 ; ++ V_26 ) {
if ( ( V_26 < V_53 ) || ( V_26 > V_54 ) )
continue;
for ( V_97 = 0 ; V_97 < 3 ; ++ V_97 )
F_17 (
V_4 , V_26 , V_99 [ V_97 ] ) ;
}
return 0 ;
}
