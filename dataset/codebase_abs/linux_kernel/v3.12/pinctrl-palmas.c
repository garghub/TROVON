static int F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
unsigned int V_5 ;
int V_6 ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_8 ; ++ V_7 ) {
V_4 = & V_2 -> V_9 [ V_7 ] ;
if ( V_4 -> V_10 == V_11 ) {
V_2 -> V_12 [ V_7 ] = 0 ;
continue;
}
V_6 = F_2 ( V_2 -> V_13 , V_4 -> V_10 ,
V_4 -> V_14 , & V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_15 , L_1 ,
V_4 -> V_14 , V_6 ) ;
return V_6 ;
}
V_5 &= V_4 -> V_16 ;
V_2 -> V_12 [ V_7 ] = V_5 >> V_4 -> V_17 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 ,
bool V_18 )
{
int V_6 ;
int V_5 ;
V_5 = V_18 ? V_19 : 0 ;
V_6 = F_5 ( V_2 -> V_13 , V_20 ,
V_21 ,
V_19 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( V_2 -> V_15 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 ,
bool V_18 )
{
int V_6 ;
int V_5 ;
V_5 = V_18 ? V_22 : 0 ;
V_6 = F_5 ( V_2 -> V_13 , V_20 ,
V_21 ,
V_22 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( V_2 -> V_15 , L_2 , V_6 ) ;
return V_6 ;
}
static int F_7 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
return V_2 -> V_8 ;
}
static const char * F_9 ( struct V_23 * V_24 ,
unsigned V_25 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
return V_2 -> V_9 [ V_25 ] . V_26 ;
}
static int F_10 ( struct V_23 * V_24 ,
unsigned V_25 , const unsigned * * V_27 , unsigned * V_28 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
* V_27 = V_2 -> V_9 [ V_25 ] . V_27 ;
* V_28 = V_2 -> V_9 [ V_25 ] . V_29 ;
return 0 ;
}
static int F_11 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
return V_2 -> V_30 ;
}
static const char * F_12 ( struct V_23 * V_24 ,
unsigned V_31 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
return V_2 -> V_32 [ V_31 ] . V_26 ;
}
static int F_13 ( struct V_23 * V_24 ,
unsigned V_31 , const char * const * * V_33 ,
unsigned * const V_34 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
* V_33 = V_2 -> V_32 [ V_31 ] . V_33 ;
* V_34 = V_2 -> V_32 [ V_31 ] . V_35 ;
return 0 ;
}
static int F_14 ( struct V_23 * V_24 , unsigned V_31 ,
unsigned V_25 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
const struct V_3 * V_4 ;
int V_7 ;
int V_6 ;
V_4 = & V_2 -> V_9 [ V_25 ] ;
if ( V_31 <= V_36 ) {
if ( ! V_4 -> V_37 [ V_31 ] ) {
F_3 ( V_2 -> V_15 , L_3 ,
V_4 -> V_26 , V_31 ) ;
return - V_38 ;
}
V_7 = V_31 ;
} else {
for ( V_7 = 0 ; V_7 < F_15 ( V_4 -> V_37 ) ; V_7 ++ ) {
if ( ! V_4 -> V_37 [ V_7 ] )
continue;
if ( V_4 -> V_37 [ V_7 ] -> V_39 == V_31 )
break;
}
if ( F_16 ( V_7 == F_15 ( V_4 -> V_37 ) ) ) {
F_3 ( V_2 -> V_15 , L_3 ,
V_4 -> V_26 , V_31 ) ;
return - V_38 ;
}
}
if ( V_4 -> V_10 == V_11 ) {
if ( F_16 ( V_7 != 0 ) )
return - V_38 ;
return 0 ;
}
F_17 ( V_2 -> V_15 , L_4 ,
V_40 , V_4 -> V_10 , V_4 -> V_14 ,
V_4 -> V_16 , V_7 << V_4 -> V_17 ) ;
V_6 = F_5 ( V_2 -> V_13 , V_4 -> V_10 , V_4 -> V_14 ,
V_4 -> V_16 , V_7 << V_4 -> V_17 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_15 , L_5 ,
V_4 -> V_14 , V_6 ) ;
return V_6 ;
}
V_2 -> V_12 [ V_25 ] = V_7 ;
return 0 ;
}
static int F_18 ( struct V_23 * V_24 ,
unsigned V_41 , unsigned long * V_42 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
enum V_43 V_44 = F_19 ( * V_42 ) ;
const struct V_3 * V_4 ;
const struct V_45 * V_37 ;
unsigned int V_5 ;
int V_6 ;
int V_46 , V_47 ;
int V_48 ;
int V_49 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_8 ; ++ V_50 ) {
if ( V_2 -> V_9 [ V_50 ] . V_27 [ 0 ] == V_41 )
break;
}
if ( V_50 == V_2 -> V_8 ) {
F_3 ( V_2 -> V_15 ,
L_6 , V_41 ) ;
return - V_51 ;
}
V_4 = & V_2 -> V_9 [ V_50 ] ;
V_37 = V_4 -> V_37 [ V_2 -> V_12 [ V_50 ] ] ;
if ( ! V_37 ) {
F_3 ( V_2 -> V_15 ,
L_7 , V_4 -> V_26 ) ;
return - V_51 ;
}
switch ( V_44 ) {
case V_52 :
case V_53 :
case V_54 :
if ( ! V_37 -> V_55 ) {
F_3 ( V_2 -> V_15 ,
L_8 ,
V_4 -> V_26 ) ;
return - V_51 ;
}
V_46 = V_37 -> V_55 -> V_56 ;
V_47 = V_37 -> V_55 -> V_57 ;
V_6 = F_2 ( V_2 -> V_13 , V_46 , V_47 , & V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_15 , L_9 ,
V_47 , V_6 ) ;
return V_6 ;
}
V_48 = V_5 & V_37 -> V_55 -> V_58 ;
V_49 = 0 ;
if ( ( V_37 -> V_55 -> V_59 >= 0 ) &&
( V_37 -> V_55 -> V_59 == V_48 ) &&
( V_44 == V_52 ) )
V_49 = 1 ;
else if ( ( V_37 -> V_55 -> V_60 >= 0 ) &&
( V_37 -> V_55 -> V_60 == V_48 ) &&
( V_44 == V_53 ) )
V_49 = 1 ;
else if ( ( V_37 -> V_55 -> V_61 >= 0 ) &&
( V_37 -> V_55 -> V_61 == V_48 ) &&
( V_44 == V_54 ) )
V_49 = 1 ;
break;
case V_62 :
if ( ! V_37 -> V_63 ) {
F_3 ( V_2 -> V_15 ,
L_10 ,
V_4 -> V_26 ) ;
return - V_51 ;
}
V_46 = V_37 -> V_63 -> V_64 ;
V_47 = V_37 -> V_63 -> V_65 ;
V_6 = F_2 ( V_2 -> V_13 , V_46 , V_47 , & V_5 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_15 , L_9 ,
V_47 , V_6 ) ;
return V_6 ;
}
V_48 = V_5 & V_37 -> V_63 -> V_66 ;
V_49 = - 1 ;
if ( ( V_37 -> V_63 -> V_67 >= 0 ) &&
( V_37 -> V_63 -> V_67 == V_48 ) )
V_49 = 0 ;
else if ( ( V_37 -> V_63 -> V_68 >= 0 ) &&
( V_37 -> V_63 -> V_68 == V_48 ) )
V_49 = 1 ;
if ( V_49 < 0 ) {
F_3 ( V_2 -> V_15 ,
L_10 ,
V_4 -> V_26 ) ;
return - V_51 ;
}
break;
default:
F_3 ( V_2 -> V_15 , L_11 ) ;
return - V_51 ;
}
* V_42 = F_20 ( V_44 , ( V_69 ) V_49 ) ;
return 0 ;
}
static int F_21 ( struct V_23 * V_24 ,
unsigned V_41 , unsigned long * V_70 ,
unsigned V_71 )
{
struct V_1 * V_2 = F_8 ( V_24 ) ;
enum V_43 V_44 ;
V_69 V_72 ;
const struct V_3 * V_4 ;
const struct V_45 * V_37 ;
int V_6 ;
int V_46 , V_47 , V_73 ;
int V_48 ;
int V_50 ;
int V_7 ;
for ( V_50 = 0 ; V_50 < V_2 -> V_8 ; ++ V_50 ) {
if ( V_2 -> V_9 [ V_50 ] . V_27 [ 0 ] == V_41 )
break;
}
if ( V_50 == V_2 -> V_8 ) {
F_3 ( V_2 -> V_15 ,
L_6 , V_41 ) ;
return - V_51 ;
}
V_4 = & V_2 -> V_9 [ V_50 ] ;
V_37 = V_4 -> V_37 [ V_2 -> V_12 [ V_50 ] ] ;
if ( ! V_37 ) {
F_3 ( V_2 -> V_15 ,
L_7 , V_4 -> V_26 ) ;
return - V_51 ;
}
for ( V_7 = 0 ; V_7 < V_71 ; V_7 ++ ) {
V_44 = F_19 ( V_70 [ V_7 ] ) ;
V_72 = F_22 ( V_70 [ V_7 ] ) ;
if ( V_44 == V_74 )
continue;
switch ( V_44 ) {
case V_52 :
case V_53 :
case V_54 :
if ( ! V_37 -> V_55 ) {
F_3 ( V_2 -> V_15 ,
L_8 ,
V_4 -> V_26 ) ;
return - V_51 ;
}
V_46 = V_37 -> V_55 -> V_56 ;
V_47 = V_37 -> V_55 -> V_57 ;
V_73 = V_37 -> V_55 -> V_58 ;
if ( V_44 == V_52 )
V_48 = V_37 -> V_55 -> V_59 ;
else if ( V_44 == V_53 )
V_48 = V_37 -> V_55 -> V_60 ;
else
V_48 = V_37 -> V_55 -> V_61 ;
if ( V_48 < 0 ) {
F_3 ( V_2 -> V_15 ,
L_8 ,
V_4 -> V_26 ) ;
return - V_51 ;
}
break;
case V_62 :
if ( ! V_37 -> V_63 ) {
F_3 ( V_2 -> V_15 ,
L_10 ,
V_4 -> V_26 ) ;
return - V_51 ;
}
V_46 = V_37 -> V_63 -> V_64 ;
V_47 = V_37 -> V_63 -> V_65 ;
V_73 = V_37 -> V_63 -> V_66 ;
if ( V_72 == 0 )
V_48 = V_37 -> V_63 -> V_67 ;
else
V_48 = V_37 -> V_63 -> V_68 ;
if ( V_48 < 0 ) {
F_3 ( V_2 -> V_15 ,
L_10 ,
V_4 -> V_26 ) ;
return - V_51 ;
}
break;
default:
F_3 ( V_2 -> V_15 , L_11 ) ;
return - V_51 ;
}
F_17 ( V_2 -> V_15 , L_12 ,
V_40 , V_46 , V_47 , V_73 , V_48 ) ;
V_6 = F_5 ( V_2 -> V_13 , V_46 , V_47 , V_73 , V_48 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 -> V_15 , L_5 ,
V_47 , V_6 ) ;
return V_6 ;
}
}
return 0 ;
}
static int F_23 ( struct V_23 * V_24 ,
unsigned V_25 , unsigned long * V_42 )
{
F_3 ( V_24 -> V_15 , L_13 ) ;
return - V_51 ;
}
static int F_24 ( struct V_23 * V_24 ,
unsigned V_25 , unsigned long * V_70 ,
unsigned V_71 )
{
F_3 ( V_24 -> V_15 , L_14 ) ;
return - V_51 ;
}
static int F_25 ( struct V_75 * V_76 )
{
struct V_1 * V_2 ;
const struct V_77 * V_78 = & V_79 ;
int V_6 ;
bool V_80 = false ;
bool V_81 = false ;
if ( V_76 -> V_15 . V_82 ) {
const struct V_83 * V_84 ;
V_84 = F_26 ( V_85 , & V_76 -> V_15 ) ;
V_78 = V_84 -> V_86 ;
V_80 = F_27 ( V_76 -> V_15 . V_82 ,
L_15 ) ;
V_81 = F_27 ( V_76 -> V_15 . V_82 ,
L_16 ) ;
}
V_2 = F_28 ( & V_76 -> V_15 , sizeof( * V_2 ) , V_87 ) ;
if ( ! V_2 ) {
F_3 ( & V_76 -> V_15 , L_17 ) ;
return - V_88 ;
}
V_2 -> V_15 = & V_76 -> V_15 ;
V_2 -> V_13 = F_29 ( V_76 -> V_15 . V_89 ) ;
V_2 -> V_27 = V_90 ;
V_2 -> V_28 = F_15 ( V_90 ) ;
V_2 -> V_32 = V_91 ;
V_2 -> V_30 = F_15 ( V_91 ) ;
V_2 -> V_9 = V_78 -> V_9 ;
V_2 -> V_8 = V_78 -> V_8 ;
F_30 ( V_76 , V_2 ) ;
F_4 ( V_2 , V_80 ) ;
F_6 ( V_2 , V_81 ) ;
V_6 = F_1 ( V_2 ) ;
if ( V_6 < 0 ) {
F_3 ( & V_76 -> V_15 ,
L_18 , V_6 ) ;
return V_6 ;
}
V_92 . V_26 = F_31 ( & V_76 -> V_15 ) ;
V_92 . V_27 = V_90 ;
V_92 . V_29 = F_15 ( V_90 ) ;
V_2 -> V_93 = F_32 ( & V_92 , & V_76 -> V_15 , V_2 ) ;
if ( ! V_2 -> V_93 ) {
F_3 ( & V_76 -> V_15 , L_19 ) ;
return - V_94 ;
}
return 0 ;
}
static int F_33 ( struct V_75 * V_76 )
{
struct V_1 * V_2 = F_34 ( V_76 ) ;
F_35 ( V_2 -> V_93 ) ;
return 0 ;
}
