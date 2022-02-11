static int F_1 ( enum V_1 V_2 , int * V_3 , T_1 V_4 )
{
switch ( V_2 ) {
case V_5 :
if ( V_4 & V_6 )
* V_3 = 0 ;
else
* V_3 = 1 ;
break;
case V_7 :
if ( V_4 & V_8 )
return - V_9 ;
break;
case V_10 :
if ( V_4 & V_8 )
* V_3 = 1 ;
else
return - V_9 ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static int F_2 ( enum V_1 V_2 , int * V_3 , T_1 V_4 ,
unsigned V_12 )
{
T_2 V_13 ;
if ( V_12 == V_14 )
V_13 = V_15 ;
else
V_13 = V_16 ;
switch ( V_2 ) {
case V_17 :
if ( V_4 & ( V_18 << V_13 ) )
* V_3 = 1 ;
else
return - V_9 ;
break;
case V_19 :
if ( V_4 & ( V_20 << V_13 ) )
* V_3 = 1 ;
else
* V_3 = 0 ;
break;
case V_21 :
if ( V_4 & ( V_22 << V_13 ) )
* V_3 = 3 ;
else
* V_3 = 50 ;
break;
case V_23 :
if ( V_4 & ( V_24 << V_13 ) )
return - V_9 ;
else
* V_3 = 1 ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static int F_3 ( enum V_1 V_2 , int * V_3 , T_1 V_4 ,
struct V_25 * V_26 )
{
switch ( V_2 ) {
case V_7 :
if ( ( ! ( V_4 & V_27 ) ) && ( V_4 & V_28 ) )
;
else
return - V_9 ;
break;
case V_29 :
if ( V_4 & V_28 )
return - V_9 ;
else
* V_3 = 1 ;
break;
case V_10 :
if ( V_4 & V_27 )
* V_3 = 1 ;
else
return - V_9 ;
break;
case V_17 :
if ( V_4 & V_30 )
* V_3 = 1 ;
else
return - V_9 ;
break;
case V_19 :
if ( V_26 -> type == V_31 )
return - V_11 ;
if ( V_4 & V_32 )
* V_3 = 1 ;
else
* V_3 = 0 ;
break;
case V_23 :
if ( V_4 & V_33 )
return - V_9 ;
else
* V_3 = 1 ;
break;
case V_34 :
if ( V_26 -> type != V_31 )
return - V_11 ;
* V_3 = ( V_4 & V_35 ) >> V_36 ;
switch ( * V_3 ) {
case 3 : * V_3 += 5 ;
case 2 : * V_3 += 5 ;
case 1 : * V_3 += 3 ;
case 0 : * V_3 += 4 ;
}
break;
default:
return - V_11 ;
}
return 0 ;
}
static struct V_25 * F_4 ( unsigned V_12 )
{
int V_37 ;
for ( V_37 = 0 ; V_37 < F_5 ( V_38 ) ; V_37 ++ ) {
if ( V_38 [ V_37 ] . V_39 == V_12 )
return V_38 [ V_37 ] . V_40 ;
}
return NULL ;
}
static int F_6 ( struct V_41 * V_42 , unsigned V_12 ,
unsigned long * V_43 )
{
struct V_44 * V_45 = F_7 ( V_42 ) ;
enum V_1 V_2 = F_8 ( * V_43 ) ;
struct V_25 * V_26 ;
int V_46 , V_3 = 0 ;
T_1 V_4 ;
V_26 = F_4 ( V_12 ) ;
if ( ! V_26 )
return - V_9 ;
V_4 = F_9 ( V_45 -> V_47 + V_26 -> V_48 ) ;
if ( V_26 -> type == V_49 )
V_46 = F_2 ( V_2 , & V_3 , V_4 , V_12 ) ;
else if ( V_26 -> type == V_50 )
V_46 = F_1 ( V_2 , & V_3 , V_4 ) ;
else
V_46 = F_3 ( V_2 , & V_3 , V_4 , V_26 ) ;
if ( V_46 < 0 )
return V_46 ;
* V_43 = F_10 ( V_2 , ( V_51 ) V_3 ) ;
return 0 ;
}
static int F_11 ( struct V_41 * V_42 ,
enum V_1 V_2 ,
V_51 V_52 , T_1 * V_4 )
{
switch ( V_2 ) {
case V_5 :
if ( V_52 )
* V_4 &= ~ V_6 ;
else
* V_4 |= V_6 ;
break;
case V_7 :
* V_4 &= ~ V_8 ;
break;
case V_10 :
* V_4 |= V_8 ;
break;
default:
F_12 ( V_42 -> V_53 , L_1 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_13 ( struct V_41 * V_42 ,
enum V_1 V_2 ,
V_51 V_52 , T_1 * V_4 ,
unsigned V_12 )
{
T_2 V_13 ;
if ( V_12 == V_14 )
V_13 = V_15 ;
else
V_13 = V_16 ;
switch ( V_2 ) {
case V_17 :
if ( V_52 )
* V_4 |= ( V_18 << V_13 ) ;
else
* V_4 &= ~ ( V_18 << V_13 ) ;
break;
case V_19 :
if ( V_52 )
* V_4 |= ( V_20 << V_13 ) ;
else
* V_4 &= ~ ( V_20 << V_13 ) ;
break;
case V_21 :
if ( V_52 == 3 )
* V_4 |= ( V_22 << V_13 ) ;
else if ( V_52 == 50 )
* V_4 &= ~ ( V_22 << V_13 ) ;
else
return - V_11 ;
break;
case V_23 :
if ( V_52 )
* V_4 &= ~ ( V_24 << V_13 ) ;
else
* V_4 |= ( V_24 << V_13 ) ;
break;
default:
F_12 ( V_42 -> V_53 , L_1 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_14 ( struct V_41 * V_42 ,
enum V_1 V_2 ,
V_51 V_52 , T_1 * V_4 ,
struct V_25 * V_26 )
{
switch ( V_2 ) {
case V_7 :
* V_4 &= ~ V_27 ;
* V_4 |= V_28 ;
break;
case V_29 :
* V_4 &= ~ V_28 ;
break;
case V_10 :
* V_4 |= V_27 ;
break;
case V_17 :
if ( V_52 )
* V_4 |= V_30 ;
else
* V_4 &= ~ V_30 ;
break;
case V_19 :
if ( V_26 -> type == V_31 ) {
F_12 ( V_42 -> V_53 , L_2 ) ;
return - V_11 ;
}
if ( V_52 == 0 )
* V_4 &= ~ V_32 ;
else
* V_4 |= V_32 ;
break;
case V_23 :
if ( V_52 )
* V_4 &= ~ V_33 ;
else
* V_4 |= V_33 ;
break;
case V_34 :
if ( V_26 -> type != V_31 ) {
F_12 ( V_42 -> V_53 , L_3 ) ;
return - V_11 ;
}
* V_4 &= ~ V_35 ;
switch ( V_52 ) {
case 20 : V_52 -= 5 ;
case 14 : V_52 -= 5 ;
case 8 : V_52 -= 3 ;
case 4 : V_52 -= 4 ;
break;
default:
F_12 ( V_42 -> V_53 , L_4 , V_52 ) ;
return - V_11 ;
}
* V_4 |= V_52 << V_36 ;
break;
default:
F_12 ( V_42 -> V_53 , L_1 ) ;
return - V_11 ;
}
return 0 ;
}
static int F_15 ( struct V_41 * V_42 , unsigned V_12 ,
unsigned long * V_54 , unsigned V_55 )
{
struct V_44 * V_45 = F_7 ( V_42 ) ;
struct V_25 * V_26 ;
enum V_1 V_2 ;
V_51 V_52 ;
T_1 V_4 ;
int V_46 ;
int V_37 ;
V_26 = F_4 ( V_12 ) ;
if ( ! V_26 )
return - V_9 ;
V_4 = F_9 ( V_45 -> V_47 + V_26 -> V_48 ) ;
for ( V_37 = 0 ; V_37 < V_55 ; V_37 ++ ) {
V_2 = F_8 ( V_54 [ V_37 ] ) ;
V_52 = F_16 ( V_54 [ V_37 ] ) ;
if ( V_26 -> type == V_49 )
V_46 = F_13 ( V_42 , V_2 , V_52 , & V_4 , V_12 ) ;
else if ( V_26 -> type == V_50 )
V_46 = F_11 ( V_42 , V_2 , V_52 , & V_4 ) ;
else
V_46 = F_14 ( V_42 , V_2 , V_52 , & V_4 , V_26 ) ;
if ( V_46 )
return V_46 ;
}
F_17 ( V_4 , V_45 -> V_47 + V_26 -> V_48 ) ;
return 0 ;
}
static int F_18 ( struct V_41 * V_42 )
{
return F_5 ( V_56 ) ;
}
static const char * F_19 ( struct V_41 * V_42 ,
unsigned V_57 )
{
return V_56 [ V_57 ] ;
}
static int F_20 ( struct V_41 * V_42 ,
unsigned V_57 ,
const char * const * * V_58 ,
unsigned * const V_59 )
{
struct V_44 * V_45 = F_7 ( V_42 ) ;
* V_58 = V_45 -> V_60 [ V_57 ] . V_58 ;
* V_59 = V_45 -> V_60 [ V_57 ] . V_61 ;
return 0 ;
}
static int F_21 ( struct V_41 * V_42 , unsigned V_57 ,
unsigned V_62 )
{
struct V_44 * V_45 = F_7 ( V_42 ) ;
struct V_25 * V_12 = V_38 [ V_62 ] . V_40 ;
int V_60 ;
T_1 V_4 ;
if ( V_12 -> type == V_50 ) {
if ( V_57 == V_63 )
return 0 ;
goto V_64;
}
if ( V_12 -> type == V_49 ) {
if ( V_57 == V_65 )
return 0 ;
goto V_64;
}
if ( V_57 == V_66 && ( V_12 -> V_67 & V_68 ) ) {
T_1 V_48 ;
F_17 ( V_69 , V_45 -> V_47 + V_12 -> V_48 ) ;
if ( F_22 ( V_12 -> V_67 ) == 0 )
V_48 = V_70 ;
else
V_48 = V_71 ;
V_4 = F_9 ( V_45 -> V_47 + V_48 ) ;
V_4 |= V_12 -> V_67 & V_72 ;
F_17 ( V_4 , V_45 -> V_47 + V_48 ) ;
return 0 ;
}
if ( V_57 == V_73 && ( V_12 -> V_67 & V_68 ) ) {
F_17 ( V_69 , V_45 -> V_47 + V_12 -> V_48 ) ;
V_4 = F_9 ( V_45 -> V_47 + V_74 ) ;
V_4 |= V_75 ;
F_17 ( V_4 , V_45 -> V_47 + V_74 ) ;
return 0 ;
}
for ( V_60 = 0 ; V_60 < V_76 ; V_60 ++ ) {
if ( V_57 == V_12 -> V_77 [ V_60 ] )
break;
}
if ( V_60 >= V_76 )
goto V_64;
V_4 = F_9 ( V_45 -> V_47 + V_12 -> V_48 ) ;
V_4 &= ~ V_78 ;
F_17 ( V_4 | V_60 , V_45 -> V_47 + V_12 -> V_48 ) ;
return 0 ;
V_64:
F_12 ( V_42 -> V_53 , L_5 , V_38 [ V_62 ] . V_79 ,
V_56 [ V_57 ] ) ;
return - V_9 ;
}
static int F_23 ( struct V_41 * V_42 )
{
return F_5 ( V_38 ) ;
}
static const char * F_24 ( struct V_41 * V_42 ,
unsigned V_62 )
{
return V_38 [ V_62 ] . V_79 ;
}
static int F_25 ( struct V_41 * V_42 ,
unsigned V_62 ,
const unsigned * * V_80 ,
unsigned * V_81 )
{
* V_80 = & V_38 [ V_62 ] . V_39 ;
* V_81 = 1 ;
return 0 ;
}
static bool F_26 ( unsigned V_12 , unsigned V_57 )
{
struct V_25 * V_82 = V_38 [ V_12 ] . V_40 ;
int V_37 ;
if ( V_57 == V_73 && V_82 -> V_67 == V_83 )
return true ;
if ( V_57 == V_66 && V_82 -> V_67 )
return true ;
if ( V_57 == V_65 && V_82 -> type == V_49 )
return true ;
if ( V_57 == V_63 && V_82 -> type == V_50 )
return true ;
for ( V_37 = 0 ; V_37 < V_76 ; V_37 ++ ) {
if ( V_57 == V_82 -> V_77 [ V_37 ] )
return true ;
}
return false ;
}
static int F_27 ( struct V_84 * V_53 ,
struct V_44 * V_45 )
{
V_51 V_80 [ F_5 ( V_38 ) ] ;
int V_60 , V_61 , V_37 ;
for ( V_60 = 0 ; V_60 < V_85 ; V_61 = 0 , V_60 ++ ) {
for ( V_37 = 0 ; V_37 < F_5 ( V_38 ) ; V_37 ++ ) {
if ( F_26 ( V_37 , V_60 ) )
V_80 [ V_61 ++ ] = V_37 ;
}
V_45 -> V_60 [ V_60 ] . V_61 = V_61 ;
V_45 -> V_60 [ V_60 ] . V_58 = F_28 ( V_53 , V_61 *
sizeof( char * ) , V_86 ) ;
if ( ! V_45 -> V_60 [ V_60 ] . V_58 )
return - V_87 ;
for ( V_37 = 0 ; V_37 < V_61 ; V_37 ++ )
V_45 -> V_60 [ V_60 ] . V_58 [ V_37 ] = V_38 [ V_80 [ V_37 ] ] . V_79 ;
}
return 0 ;
}
static int F_29 ( struct V_88 * V_89 )
{
struct V_44 * V_45 ;
struct V_90 * V_91 ;
int V_46 ;
V_45 = F_28 ( & V_89 -> V_53 , sizeof( * V_45 ) , V_86 ) ;
if ( ! V_45 )
return - V_87 ;
V_91 = F_30 ( V_89 , V_92 , 0 ) ;
V_45 -> V_47 = F_31 ( & V_89 -> V_53 , V_91 ) ;
if ( F_32 ( V_45 -> V_47 ) )
return F_33 ( V_45 -> V_47 ) ;
V_45 -> V_93 = F_34 ( & V_89 -> V_53 , NULL ) ;
if ( F_32 ( V_45 -> V_93 ) ) {
F_12 ( & V_89 -> V_53 , L_6 ) ;
return F_33 ( V_45 -> V_93 ) ;
}
V_46 = F_27 ( & V_89 -> V_53 , V_45 ) ;
if ( V_46 ) {
F_12 ( & V_89 -> V_53 , L_7 ) ;
return V_46 ;
}
V_46 = F_35 ( V_45 -> V_93 ) ;
if ( V_46 ) {
F_12 ( & V_89 -> V_53 , L_8 ) ;
return V_46 ;
}
F_36 ( V_89 , V_45 ) ;
V_45 -> V_94 = F_37 ( & V_95 , & V_89 -> V_53 , V_45 ) ;
if ( F_32 ( V_45 -> V_94 ) ) {
F_12 ( & V_89 -> V_53 , L_9 ) ;
F_38 ( V_45 -> V_93 ) ;
return F_33 ( V_45 -> V_94 ) ;
}
return 0 ;
}
static int F_39 ( struct V_88 * V_89 )
{
struct V_44 * V_45 = F_40 ( V_89 ) ;
F_41 ( V_45 -> V_94 ) ;
F_38 ( V_45 -> V_93 ) ;
return 0 ;
}
