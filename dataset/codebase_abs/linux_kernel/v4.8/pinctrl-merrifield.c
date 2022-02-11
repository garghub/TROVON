static const struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 )
{
const struct V_1 * V_5 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_3 -> V_7 ; V_6 ++ ) {
V_5 = & V_3 -> V_8 [ V_6 ] ;
if ( V_4 >= V_5 -> V_9 &&
V_4 < V_5 -> V_9 + V_5 -> V_10 )
return V_5 ;
}
F_2 ( V_3 -> V_11 , L_1 , V_4 ) ;
return NULL ;
}
static bool F_3 ( struct V_2 * V_3 , unsigned int V_4 )
{
const struct V_1 * V_5 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return false ;
return ! V_5 -> V_12 ;
}
static void T_1 * F_4 ( struct V_2 * V_3 , unsigned int V_4 )
{
const struct V_1 * V_5 ;
unsigned int V_13 ;
V_5 = F_1 ( V_3 , V_4 ) ;
if ( ! V_5 )
return NULL ;
V_13 = F_5 ( V_5 , V_4 ) ;
return V_5 -> V_14 + V_15 + V_13 * 4 ;
}
static int F_6 ( struct V_16 * V_17 )
{
struct V_2 * V_3 = F_7 ( V_17 ) ;
return V_3 -> V_18 ;
}
static const char * F_8 ( struct V_16 * V_17 ,
unsigned int V_19 )
{
struct V_2 * V_3 = F_7 ( V_17 ) ;
return V_3 -> V_20 [ V_19 ] . V_21 ;
}
static int F_9 ( struct V_16 * V_17 , unsigned int V_19 ,
const unsigned int * * V_22 , unsigned int * V_10 )
{
struct V_2 * V_3 = F_7 ( V_17 ) ;
* V_22 = V_3 -> V_20 [ V_19 ] . V_22 ;
* V_10 = V_3 -> V_20 [ V_19 ] . V_10 ;
return 0 ;
}
static void F_10 ( struct V_16 * V_17 , struct V_23 * V_24 ,
unsigned int V_4 )
{
struct V_2 * V_3 = F_7 ( V_17 ) ;
void T_1 * V_25 ;
T_2 V_26 , V_27 ;
if ( ! F_3 ( V_3 , V_4 ) ) {
F_11 ( V_24 , L_2 ) ;
return;
}
V_25 = F_4 ( V_3 , V_4 ) ;
V_26 = F_12 ( V_25 ) ;
V_27 = ( V_26 & V_28 ) >> V_29 ;
if ( ! V_27 )
F_11 ( V_24 , L_3 ) ;
else
F_13 ( V_24 , L_4 , V_27 ) ;
F_13 ( V_24 , L_5 , V_26 ) ;
}
static int F_14 ( struct V_16 * V_17 )
{
struct V_2 * V_3 = F_7 ( V_17 ) ;
return V_3 -> V_30 ;
}
static const char * F_15 ( struct V_16 * V_17 ,
unsigned int V_31 )
{
struct V_2 * V_3 = F_7 ( V_17 ) ;
return V_3 -> V_32 [ V_31 ] . V_21 ;
}
static int F_16 ( struct V_16 * V_17 ,
unsigned int V_31 ,
const char * const * * V_20 ,
unsigned int * const V_18 )
{
struct V_2 * V_3 = F_7 ( V_17 ) ;
* V_20 = V_3 -> V_32 [ V_31 ] . V_20 ;
* V_18 = V_3 -> V_32 [ V_31 ] . V_18 ;
return 0 ;
}
static void F_17 ( struct V_2 * V_3 , unsigned int V_4 ,
T_2 V_33 , T_2 V_34 )
{
void T_1 * V_25 ;
T_2 V_26 ;
V_25 = F_4 ( V_3 , V_4 ) ;
V_26 = F_12 ( V_25 ) ;
V_26 &= ~ V_34 ;
V_26 |= V_33 & V_34 ;
F_18 ( V_26 , V_25 ) ;
}
static int F_19 ( struct V_16 * V_17 ,
unsigned int V_31 ,
unsigned int V_19 )
{
struct V_2 * V_3 = F_7 ( V_17 ) ;
const struct V_35 * V_36 = & V_3 -> V_20 [ V_19 ] ;
T_2 V_33 = V_36 -> V_27 << V_29 ;
T_2 V_34 = V_28 ;
unsigned long V_37 ;
unsigned int V_6 ;
for ( V_6 = 0 ; V_6 < V_36 -> V_10 ; V_6 ++ ) {
if ( ! F_3 ( V_3 , V_36 -> V_22 [ V_6 ] ) )
return - V_38 ;
}
F_20 ( & V_3 -> V_39 , V_37 ) ;
for ( V_6 = 0 ; V_6 < V_36 -> V_10 ; V_6 ++ )
F_17 ( V_3 , V_36 -> V_22 [ V_6 ] , V_33 , V_34 ) ;
F_21 ( & V_3 -> V_39 , V_37 ) ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 ,
struct V_40 * V_41 ,
unsigned int V_4 )
{
struct V_2 * V_3 = F_7 ( V_17 ) ;
T_2 V_33 = V_42 << V_29 ;
T_2 V_34 = V_28 ;
unsigned long V_37 ;
if ( ! F_3 ( V_3 , V_4 ) )
return - V_38 ;
F_20 ( & V_3 -> V_39 , V_37 ) ;
F_17 ( V_3 , V_4 , V_33 , V_34 ) ;
F_21 ( & V_3 -> V_39 , V_37 ) ;
return 0 ;
}
static int F_23 ( struct V_16 * V_17 , unsigned int V_4 ,
unsigned long * V_43 )
{
struct V_2 * V_3 = F_7 ( V_17 ) ;
enum V_44 V_45 = F_24 ( * V_43 ) ;
T_2 V_26 , V_46 ;
T_3 V_47 = 0 ;
if ( ! F_3 ( V_3 , V_4 ) )
return - V_48 ;
V_26 = F_12 ( F_4 ( V_3 , V_4 ) ) ;
V_46 = ( V_26 & V_49 ) >> V_50 ;
switch ( V_45 ) {
case V_51 :
if ( V_26 & V_52 )
return - V_53 ;
break;
case V_54 :
if ( ( V_26 & V_52 ) != V_55 )
return - V_53 ;
switch ( V_46 ) {
case V_56 :
V_47 = 910 ;
break;
case V_57 :
V_47 = 2000 ;
break;
case V_58 :
V_47 = 20000 ;
break;
case V_59 :
V_47 = 50000 ;
break;
}
break;
case V_60 :
if ( ( V_26 & V_52 ) != V_61 )
return - V_53 ;
switch ( V_46 ) {
case V_56 :
V_47 = 910 ;
break;
case V_57 :
V_47 = 2000 ;
break;
case V_58 :
V_47 = 20000 ;
break;
case V_59 :
V_47 = 50000 ;
break;
}
break;
case V_62 :
if ( ! ( V_26 & V_63 ) )
return - V_53 ;
break;
case V_64 :
if ( ! ( V_26 & V_65 ) )
V_47 = 0 ;
else
V_47 = 1 ;
break;
default:
return - V_48 ;
}
* V_43 = F_25 ( V_45 , V_47 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 , unsigned int V_4 ,
unsigned long V_43 )
{
unsigned int V_45 = F_24 ( V_43 ) ;
unsigned int V_47 = F_27 ( V_43 ) ;
T_2 V_33 = 0 , V_34 = 0 ;
unsigned long V_37 ;
switch ( V_45 ) {
case V_51 :
V_34 |= V_52 | V_49 ;
break;
case V_54 :
V_34 |= V_52 | V_49 ;
V_33 |= V_55 ;
switch ( V_47 ) {
case 50000 :
V_33 |= V_59 << V_50 ;
break;
case 20000 :
V_33 |= V_58 << V_50 ;
break;
case 2000 :
V_33 |= V_57 << V_50 ;
break;
default:
return - V_53 ;
}
break;
case V_60 :
V_34 |= V_52 | V_49 ;
V_33 |= V_61 ;
switch ( V_47 ) {
case 50000 :
V_33 |= V_59 << V_50 ;
break;
case 20000 :
V_33 |= V_58 << V_50 ;
break;
case 2000 :
V_33 |= V_57 << V_50 ;
break;
default:
return - V_53 ;
}
break;
case V_62 :
V_34 |= V_63 ;
if ( V_47 )
V_33 |= V_63 ;
break;
case V_64 :
V_34 |= V_65 ;
if ( V_47 )
V_33 |= V_65 ;
break;
}
F_20 ( & V_3 -> V_39 , V_37 ) ;
F_17 ( V_3 , V_4 , V_33 , V_34 ) ;
F_21 ( & V_3 -> V_39 , V_37 ) ;
return 0 ;
}
static int F_28 ( struct V_16 * V_17 , unsigned int V_4 ,
unsigned long * V_66 , unsigned int V_67 )
{
struct V_2 * V_3 = F_7 ( V_17 ) ;
unsigned int V_6 ;
int V_68 ;
for ( V_6 = 0 ; V_6 < V_67 ; V_6 ++ ) {
switch ( F_24 ( V_66 [ V_6 ] ) ) {
case V_51 :
case V_54 :
case V_60 :
case V_62 :
case V_64 :
V_68 = F_26 ( V_3 , V_4 , V_66 [ V_6 ] ) ;
if ( V_68 )
return V_68 ;
break;
default:
return - V_48 ;
}
}
return 0 ;
}
static int F_29 ( struct V_69 * V_70 )
{
struct V_1 * V_8 ;
struct V_2 * V_3 ;
struct V_71 * V_72 ;
void T_1 * V_14 ;
T_4 V_7 ;
unsigned int V_6 ;
V_3 = F_30 ( & V_70 -> V_11 , sizeof( * V_3 ) , V_73 ) ;
if ( ! V_3 )
return - V_74 ;
V_3 -> V_11 = & V_70 -> V_11 ;
F_31 ( & V_3 -> V_39 ) ;
V_72 = F_32 ( V_70 , V_75 , 0 ) ;
V_14 = F_33 ( & V_70 -> V_11 , V_72 ) ;
if ( F_34 ( V_14 ) )
return F_35 ( V_14 ) ;
V_7 = F_36 ( V_76 ) ,
V_8 = F_37 ( & V_70 -> V_11 , V_76 ,
V_7 * sizeof( V_76 ) ,
V_73 ) ;
if ( ! V_8 )
return - V_74 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
struct V_1 * V_5 = & V_8 [ V_6 ] ;
V_5 -> V_14 = V_14 + V_5 -> V_77 * V_78 ;
}
V_3 -> V_8 = V_8 ;
V_3 -> V_7 = V_7 ;
V_3 -> V_32 = V_79 ;
V_3 -> V_30 = F_36 ( V_79 ) ;
V_3 -> V_20 = V_80 ;
V_3 -> V_18 = F_36 ( V_80 ) ;
V_3 -> V_81 = V_82 ;
V_3 -> V_81 . V_21 = F_38 ( & V_70 -> V_11 ) ;
V_3 -> V_81 . V_22 = V_83 ;
V_3 -> V_81 . V_10 = F_36 ( V_83 ) ;
V_3 -> V_17 = F_39 ( & V_70 -> V_11 , & V_3 -> V_81 , V_3 ) ;
if ( F_34 ( V_3 -> V_17 ) ) {
F_40 ( & V_70 -> V_11 , L_6 ) ;
return F_35 ( V_3 -> V_17 ) ;
}
F_41 ( V_70 , V_3 ) ;
return 0 ;
}
static int T_5 F_42 ( void )
{
return F_43 ( & V_84 ) ;
}
static void T_6 F_44 ( void )
{
F_45 ( & V_84 ) ;
}
