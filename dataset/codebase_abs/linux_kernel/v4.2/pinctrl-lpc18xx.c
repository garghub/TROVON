static int F_1 ( enum V_1 V_2 , int * V_3 , T_1 V_4 )
{
return - V_5 ;
}
static int F_2 ( enum V_1 V_2 , int * V_3 , T_1 V_4 ,
unsigned V_6 )
{
T_2 V_7 ;
if ( V_6 == V_8 )
V_7 = V_9 ;
else
V_7 = V_10 ;
switch ( V_2 ) {
case V_11 :
if ( V_4 & ( V_12 << V_7 ) )
* V_3 = 1 ;
else
return - V_13 ;
break;
case V_14 :
if ( V_4 & ( V_15 << V_7 ) )
* V_3 = 1 ;
else
* V_3 = 0 ;
break;
case V_16 :
if ( V_4 & ( V_17 << V_7 ) )
* V_3 = 3 ;
else
* V_3 = 50 ;
break;
case V_18 :
if ( V_4 & ( V_19 << V_7 ) )
return - V_13 ;
else
* V_3 = 1 ;
break;
default:
return - V_5 ;
}
return 0 ;
}
static int F_3 ( enum V_1 V_2 , int * V_3 , T_1 V_4 ,
struct V_20 * V_21 )
{
switch ( V_2 ) {
case V_22 :
if ( ( ! ( V_4 & V_23 ) ) && ( V_4 & V_24 ) )
;
else
return - V_13 ;
break;
case V_25 :
if ( V_4 & V_24 )
return - V_13 ;
else
* V_3 = 1 ;
break;
case V_26 :
if ( V_4 & V_23 )
* V_3 = 1 ;
else
return - V_13 ;
break;
case V_11 :
if ( V_4 & V_27 )
* V_3 = 1 ;
else
return - V_13 ;
break;
case V_14 :
if ( V_21 -> type == V_28 )
return - V_5 ;
if ( V_4 & V_29 )
* V_3 = 1 ;
else
* V_3 = 0 ;
break;
case V_18 :
if ( V_4 & V_30 )
return - V_13 ;
else
* V_3 = 1 ;
break;
case V_31 :
if ( V_21 -> type != V_28 )
return - V_5 ;
* V_3 = ( V_4 & V_32 ) >> V_33 ;
switch ( * V_3 ) {
case 3 : * V_3 += 5 ;
case 2 : * V_3 += 5 ;
case 1 : * V_3 += 3 ;
case 0 : * V_3 += 4 ;
}
break;
default:
return - V_5 ;
}
return 0 ;
}
static struct V_20 * F_4 ( unsigned V_6 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < F_5 ( V_35 ) ; V_34 ++ ) {
if ( V_35 [ V_34 ] . V_36 == V_6 )
return V_35 [ V_34 ] . V_37 ;
}
return NULL ;
}
static int F_6 ( struct V_38 * V_39 , unsigned V_6 ,
unsigned long * V_40 )
{
struct V_41 * V_42 = F_7 ( V_39 ) ;
enum V_1 V_2 = F_8 ( * V_40 ) ;
struct V_20 * V_21 ;
int V_43 , V_3 = 0 ;
T_1 V_4 ;
V_21 = F_4 ( V_6 ) ;
if ( ! V_21 )
return - V_13 ;
V_4 = F_9 ( V_42 -> V_44 + V_21 -> V_45 ) ;
if ( V_21 -> type == V_46 )
V_43 = F_2 ( V_2 , & V_3 , V_4 , V_6 ) ;
else if ( V_21 -> type == V_47 )
V_43 = F_1 ( V_2 , & V_3 , V_4 ) ;
else
V_43 = F_3 ( V_2 , & V_3 , V_4 , V_21 ) ;
if ( V_43 < 0 )
return V_43 ;
* V_40 = F_10 ( V_2 , ( V_48 ) V_3 ) ;
return 0 ;
}
static int F_11 ( struct V_38 * V_39 ,
enum V_1 V_2 ,
V_48 V_49 , T_1 * V_4 )
{
return - V_5 ;
}
static int F_12 ( struct V_38 * V_39 ,
enum V_1 V_2 ,
V_48 V_49 , T_1 * V_4 ,
unsigned V_6 )
{
T_2 V_7 ;
if ( V_6 == V_8 )
V_7 = V_9 ;
else
V_7 = V_10 ;
switch ( V_2 ) {
case V_11 :
if ( V_49 )
* V_4 |= ( V_12 << V_7 ) ;
else
* V_4 &= ~ ( V_12 << V_7 ) ;
break;
case V_14 :
if ( V_49 )
* V_4 |= ( V_15 << V_7 ) ;
else
* V_4 &= ~ ( V_15 << V_7 ) ;
break;
case V_16 :
if ( V_49 == 3 )
* V_4 |= ( V_17 << V_7 ) ;
else if ( V_49 == 50 )
* V_4 &= ~ ( V_17 << V_7 ) ;
else
return - V_5 ;
break;
case V_18 :
if ( V_49 )
* V_4 &= ~ ( V_19 << V_7 ) ;
else
* V_4 |= ( V_19 << V_7 ) ;
break;
default:
F_13 ( V_39 -> V_50 , L_1 ) ;
return - V_5 ;
}
return 0 ;
}
static int F_14 ( struct V_38 * V_39 ,
enum V_1 V_2 ,
V_48 V_49 , T_1 * V_4 ,
struct V_20 * V_21 )
{
switch ( V_2 ) {
case V_22 :
* V_4 &= ~ V_23 ;
* V_4 |= V_24 ;
break;
case V_25 :
* V_4 &= ~ V_24 ;
break;
case V_26 :
* V_4 |= V_23 ;
break;
case V_11 :
if ( V_49 )
* V_4 |= V_27 ;
else
* V_4 &= ~ V_27 ;
break;
case V_14 :
if ( V_21 -> type == V_28 ) {
F_13 ( V_39 -> V_50 , L_2 ) ;
return - V_5 ;
}
if ( V_49 == 0 )
* V_4 &= ~ V_29 ;
else
* V_4 |= V_29 ;
break;
case V_18 :
if ( V_49 )
* V_4 &= ~ V_30 ;
else
* V_4 |= V_30 ;
break;
case V_31 :
if ( V_21 -> type != V_28 ) {
F_13 ( V_39 -> V_50 , L_3 ) ;
return - V_5 ;
}
* V_4 &= ~ V_32 ;
switch ( V_49 ) {
case 20 : V_49 -= 5 ;
case 14 : V_49 -= 5 ;
case 8 : V_49 -= 3 ;
case 4 : V_49 -= 4 ;
break;
default:
F_13 ( V_39 -> V_50 , L_4 , V_49 ) ;
return - V_5 ;
}
* V_4 |= V_49 << V_33 ;
break;
default:
F_13 ( V_39 -> V_50 , L_1 ) ;
return - V_5 ;
}
return 0 ;
}
static int F_15 ( struct V_38 * V_39 , unsigned V_6 ,
unsigned long * V_51 , unsigned V_52 )
{
struct V_41 * V_42 = F_7 ( V_39 ) ;
struct V_20 * V_21 ;
enum V_1 V_2 ;
V_48 V_49 ;
T_1 V_4 ;
int V_43 ;
int V_34 ;
V_21 = F_4 ( V_6 ) ;
if ( ! V_21 )
return - V_13 ;
V_4 = F_9 ( V_42 -> V_44 + V_21 -> V_45 ) ;
for ( V_34 = 0 ; V_34 < V_52 ; V_34 ++ ) {
V_2 = F_8 ( V_51 [ V_34 ] ) ;
V_49 = F_16 ( V_51 [ V_34 ] ) ;
if ( V_21 -> type == V_46 )
V_43 = F_12 ( V_39 , V_2 , V_49 , & V_4 , V_6 ) ;
else if ( V_21 -> type == V_47 )
V_43 = F_11 ( V_39 , V_2 , V_49 , & V_4 ) ;
else
V_43 = F_14 ( V_39 , V_2 , V_49 , & V_4 , V_21 ) ;
if ( V_43 )
return V_43 ;
}
F_17 ( V_4 , V_42 -> V_44 + V_21 -> V_45 ) ;
return 0 ;
}
static int F_18 ( struct V_38 * V_39 )
{
return F_5 ( V_53 ) ;
}
static const char * F_19 ( struct V_38 * V_39 ,
unsigned V_54 )
{
return V_53 [ V_54 ] ;
}
static int F_20 ( struct V_38 * V_39 ,
unsigned V_54 ,
const char * const * * V_55 ,
unsigned * const V_56 )
{
struct V_41 * V_42 = F_7 ( V_39 ) ;
* V_55 = V_42 -> V_57 [ V_54 ] . V_55 ;
* V_56 = V_42 -> V_57 [ V_54 ] . V_58 ;
return 0 ;
}
static int F_21 ( struct V_38 * V_39 , unsigned V_54 ,
unsigned V_59 )
{
struct V_41 * V_42 = F_7 ( V_39 ) ;
struct V_20 * V_6 = V_35 [ V_59 ] . V_37 ;
int V_57 ;
T_1 V_4 ;
if ( V_6 -> type == V_47 ) {
if ( V_54 == V_60 )
return 0 ;
goto V_61;
}
if ( V_6 -> type == V_46 ) {
if ( V_54 == V_62 )
return 0 ;
goto V_61;
}
if ( V_54 == V_63 && ( V_6 -> V_64 & V_65 ) ) {
T_1 V_45 ;
F_17 ( V_66 , V_42 -> V_44 + V_6 -> V_45 ) ;
if ( F_22 ( V_6 -> V_64 ) == 0 )
V_45 = V_67 ;
else
V_45 = V_68 ;
V_4 = F_9 ( V_42 -> V_44 + V_45 ) ;
V_4 |= V_6 -> V_64 & V_69 ;
F_17 ( V_4 , V_42 -> V_44 + V_45 ) ;
return 0 ;
}
if ( V_54 == V_70 && ( V_6 -> V_64 & V_65 ) ) {
F_17 ( V_66 , V_42 -> V_44 + V_6 -> V_45 ) ;
V_4 = F_9 ( V_42 -> V_44 + V_71 ) ;
V_4 |= V_72 ;
F_17 ( V_4 , V_42 -> V_44 + V_71 ) ;
return 0 ;
}
for ( V_57 = 0 ; V_57 < V_73 ; V_57 ++ ) {
if ( V_54 == V_6 -> V_74 [ V_57 ] )
break;
}
if ( V_57 >= V_73 )
goto V_61;
V_4 = F_9 ( V_42 -> V_44 + V_6 -> V_45 ) ;
V_4 &= ~ V_75 ;
F_17 ( V_4 | V_57 , V_42 -> V_44 + V_6 -> V_45 ) ;
return 0 ;
V_61:
F_13 ( V_39 -> V_50 , L_5 , V_35 [ V_59 ] . V_76 ,
V_53 [ V_54 ] ) ;
return - V_13 ;
}
static int F_23 ( struct V_38 * V_39 )
{
return F_5 ( V_35 ) ;
}
static const char * F_24 ( struct V_38 * V_39 ,
unsigned V_59 )
{
return V_35 [ V_59 ] . V_76 ;
}
static int F_25 ( struct V_38 * V_39 ,
unsigned V_59 ,
const unsigned * * V_77 ,
unsigned * V_78 )
{
* V_77 = & V_35 [ V_59 ] . V_36 ;
* V_78 = 1 ;
return 0 ;
}
static bool F_26 ( unsigned V_6 , unsigned V_54 )
{
struct V_20 * V_79 = V_35 [ V_6 ] . V_37 ;
int V_34 ;
if ( V_54 == V_70 && V_79 -> V_64 == V_80 )
return true ;
if ( V_54 == V_63 && V_79 -> V_64 )
return true ;
if ( V_54 == V_62 && V_79 -> type == V_46 )
return true ;
if ( V_54 == V_60 && V_79 -> type == V_47 )
return true ;
for ( V_34 = 0 ; V_34 < V_73 ; V_34 ++ ) {
if ( V_54 == V_79 -> V_74 [ V_34 ] )
return true ;
}
return false ;
}
static int F_27 ( struct V_81 * V_50 ,
struct V_41 * V_42 )
{
V_48 V_77 [ F_5 ( V_35 ) ] ;
int V_57 , V_58 , V_34 ;
for ( V_57 = 0 ; V_57 < V_82 ; V_58 = 0 , V_57 ++ ) {
for ( V_34 = 0 ; V_34 < F_5 ( V_35 ) ; V_34 ++ ) {
if ( F_26 ( V_34 , V_57 ) )
V_77 [ V_58 ++ ] = V_34 ;
}
V_42 -> V_57 [ V_57 ] . V_58 = V_58 ;
V_42 -> V_57 [ V_57 ] . V_55 = F_28 ( V_50 , V_58 *
sizeof( char * ) , V_83 ) ;
if ( ! V_42 -> V_57 [ V_57 ] . V_55 )
return - V_84 ;
for ( V_34 = 0 ; V_34 < V_58 ; V_34 ++ )
V_42 -> V_57 [ V_57 ] . V_55 [ V_34 ] = V_35 [ V_77 [ V_34 ] ] . V_76 ;
}
return 0 ;
}
static int F_29 ( struct V_85 * V_86 )
{
struct V_41 * V_42 ;
struct V_87 * V_88 ;
int V_43 ;
V_42 = F_28 ( & V_86 -> V_50 , sizeof( * V_42 ) , V_83 ) ;
if ( ! V_42 )
return - V_84 ;
V_88 = F_30 ( V_86 , V_89 , 0 ) ;
V_42 -> V_44 = F_31 ( & V_86 -> V_50 , V_88 ) ;
if ( F_32 ( V_42 -> V_44 ) )
return F_33 ( V_42 -> V_44 ) ;
V_42 -> V_90 = F_34 ( & V_86 -> V_50 , NULL ) ;
if ( F_32 ( V_42 -> V_90 ) ) {
F_13 ( & V_86 -> V_50 , L_6 ) ;
return F_33 ( V_42 -> V_90 ) ;
}
V_43 = F_27 ( & V_86 -> V_50 , V_42 ) ;
if ( V_43 ) {
F_13 ( & V_86 -> V_50 , L_7 ) ;
return V_43 ;
}
V_43 = F_35 ( V_42 -> V_90 ) ;
if ( V_43 ) {
F_13 ( & V_86 -> V_50 , L_8 ) ;
return V_43 ;
}
F_36 ( V_86 , V_42 ) ;
V_42 -> V_91 = F_37 ( & V_92 , & V_86 -> V_50 , V_42 ) ;
if ( F_32 ( V_42 -> V_91 ) ) {
F_13 ( & V_86 -> V_50 , L_9 ) ;
F_38 ( V_42 -> V_90 ) ;
return F_33 ( V_42 -> V_91 ) ;
}
return 0 ;
}
static int F_39 ( struct V_85 * V_86 )
{
struct V_41 * V_42 = F_40 ( V_86 ) ;
F_41 ( V_42 -> V_91 ) ;
F_38 ( V_42 -> V_90 ) ;
return 0 ;
}
