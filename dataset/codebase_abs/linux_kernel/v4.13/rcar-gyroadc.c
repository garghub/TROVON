static void F_1 ( struct V_1 * V_2 )
{
const unsigned long V_3 = F_2 ( V_2 -> V_4 ) / 1000000 ;
const unsigned long V_5 =
( V_2 -> V_6 == V_7 ) ? 10 : 5 ;
unsigned long V_8 = V_3 * V_5 ;
if ( V_8 & 1 )
V_8 ++ ;
F_3 ( 0 , V_2 -> V_9 + V_10 ) ;
if ( V_2 -> V_11 == V_12 )
F_3 ( 0 , V_2 -> V_9 + V_13 ) ;
F_3 ( V_2 -> V_6 , V_2 -> V_9 + V_14 ) ;
F_3 ( V_8 , V_2 -> V_9 + V_15 ) ;
F_3 ( V_3 * 1250 , V_2 -> V_9 + V_16 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_3 ( V_17 ,
V_2 -> V_9 + V_10 ) ;
F_5 ( 3 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_3 ( 0 , V_2 -> V_9 + V_10 ) ;
}
static int F_7 ( struct V_1 * V_2 , bool V_18 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
int V_21 ;
if ( V_18 ) {
V_21 = F_8 ( V_20 ) ;
if ( V_21 < 0 )
F_9 ( V_20 ) ;
} else {
F_10 ( V_20 ) ;
V_21 = F_11 ( V_20 ) ;
}
return V_21 ;
}
static int F_12 ( struct V_22 * V_23 ,
struct V_24 const * V_25 ,
int * V_26 , int * V_27 , long V_28 )
{
struct V_1 * V_2 = F_13 ( V_23 ) ;
struct V_29 * V_30 ;
unsigned int V_31 = F_14 ( V_25 -> V_32 ) ;
unsigned int V_33 ;
int V_21 ;
if ( V_2 -> V_6 == V_7 )
V_30 = V_2 -> V_33 [ 0 ] ;
else
V_30 = V_2 -> V_33 [ V_25 -> V_32 ] ;
switch ( V_28 ) {
case V_34 :
if ( V_25 -> type != V_35 )
return - V_36 ;
if ( ! V_30 )
return - V_36 ;
V_21 = F_15 ( V_23 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_7 ( V_2 , true ) ;
if ( V_21 < 0 ) {
F_16 ( V_23 ) ;
return V_21 ;
}
* V_26 = F_17 ( V_2 -> V_9 + V_31 ) ;
* V_26 &= F_18 ( V_2 -> V_37 ) - 1 ;
V_21 = F_7 ( V_2 , false ) ;
F_16 ( V_23 ) ;
if ( V_21 < 0 )
return V_21 ;
return V_38 ;
case V_39 :
if ( ! V_30 )
return - V_36 ;
V_33 = F_19 ( V_30 ) ;
* V_26 = V_33 / 1000 ;
* V_27 = 1 << V_2 -> V_37 ;
return V_40 ;
case V_41 :
* V_26 = V_42 ;
return V_38 ;
default:
return - V_36 ;
}
}
static int F_20 ( struct V_22 * V_23 ,
unsigned int V_43 , unsigned int V_44 ,
unsigned int * V_45 )
{
struct V_1 * V_2 = F_13 ( V_23 ) ;
unsigned int V_46 = V_47 ;
if ( V_45 == NULL )
return - V_36 ;
if ( V_43 % 4 )
return - V_36 ;
if ( V_2 -> V_11 == V_12 )
V_46 = V_13 ;
if ( V_43 > V_46 )
return - V_36 ;
* V_45 = F_17 ( V_2 -> V_9 + V_43 ) ;
return 0 ;
}
static int F_21 ( struct V_22 * V_23 )
{
const struct V_48 * V_49 ;
const struct V_24 * V_50 ;
struct V_1 * V_2 = F_13 ( V_23 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
struct V_51 * V_52 = V_20 -> V_53 ;
struct V_51 * V_54 ;
struct V_29 * V_33 ;
unsigned int V_43 ;
unsigned int V_55 = - 1 , V_56 ;
unsigned int V_37 ;
unsigned int V_57 ;
int V_21 , V_58 = 1 ;
F_22 (np, child) {
V_49 = F_23 ( V_59 , V_54 ) ;
if ( ! V_49 ) {
F_24 ( V_20 , L_1 ,
V_54 -> V_60 ) ;
continue;
}
V_56 = ( unsigned int ) V_49 -> V_61 ;
switch ( V_56 ) {
case V_7 :
V_37 = 12 ;
V_50 = V_62 ;
V_57 = F_25 ( V_62 ) ;
break;
case V_63 :
V_37 = 15 ;
V_50 = V_64 ;
V_57 = F_25 ( V_64 ) ;
break;
case V_65 :
V_37 = 16 ;
V_50 = V_66 ;
V_57 = F_25 ( V_66 ) ;
break;
default:
return - V_36 ;
}
if ( V_56 == V_7 ) {
V_43 = 0 ;
} else {
V_21 = F_26 ( V_54 , L_2 , & V_43 ) ;
if ( V_21 ) {
F_24 ( V_20 ,
L_3 ,
V_54 -> V_60 ) ;
return V_21 ;
}
if ( V_43 >= V_57 ) {
F_24 ( V_20 ,
L_4 ,
V_57 , V_54 -> V_60 , V_43 ) ;
return V_21 ;
}
}
if ( ! V_58 && ( V_55 != V_56 ) ) {
F_24 ( V_20 ,
L_5 ,
V_43 ) ;
return V_21 ;
}
V_20 -> V_53 = V_54 ;
V_33 = F_27 ( V_20 , L_6 ) ;
V_20 -> V_53 = V_52 ;
if ( F_28 ( V_33 ) ) {
F_29 ( V_20 , L_7 ,
V_43 ) ;
return F_30 ( V_33 ) ;
}
V_2 -> V_33 [ V_43 ] = V_33 ;
if ( ! V_58 )
continue;
V_55 = V_56 ;
V_58 = 0 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_6 = V_56 ;
V_2 -> V_37 = V_37 ;
V_23 -> V_50 = V_50 ;
V_23 -> V_57 = V_57 ;
if ( V_56 == V_7 )
break;
}
if ( V_58 ) {
F_24 ( V_20 , L_8 ) ;
return - V_36 ;
}
return 0 ;
}
static void F_31 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_13 ( V_23 ) ;
unsigned int V_67 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_57 ; V_67 ++ ) {
if ( ! V_2 -> V_33 [ V_67 ] )
continue;
F_32 ( V_2 -> V_33 [ V_67 ] ) ;
}
}
static int F_33 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_13 ( V_23 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
unsigned int V_67 ;
int V_21 ;
for ( V_67 = 0 ; V_67 < V_2 -> V_57 ; V_67 ++ ) {
if ( ! V_2 -> V_33 [ V_67 ] )
continue;
V_21 = F_34 ( V_2 -> V_33 [ V_67 ] ) ;
if ( V_21 ) {
F_24 ( V_20 , L_9 ,
V_67 , V_21 ) ;
goto V_68;
}
}
return 0 ;
V_68:
F_31 ( V_23 ) ;
return V_21 ;
}
static int F_35 ( struct V_69 * V_70 )
{
const struct V_48 * V_49 =
F_36 ( V_71 , & V_70 -> V_20 ) ;
struct V_19 * V_20 = & V_70 -> V_20 ;
struct V_1 * V_2 ;
struct V_22 * V_23 ;
struct V_72 * V_73 ;
int V_21 ;
V_23 = F_37 ( V_20 , sizeof( * V_2 ) ) ;
if ( ! V_23 ) {
F_24 ( V_20 , L_10 ) ;
return - V_74 ;
}
V_2 = F_13 ( V_23 ) ;
V_2 -> V_20 = V_20 ;
V_73 = F_38 ( V_70 , V_75 , 0 ) ;
V_2 -> V_9 = F_39 ( V_20 , V_73 ) ;
if ( F_28 ( V_2 -> V_9 ) )
return F_30 ( V_2 -> V_9 ) ;
V_2 -> V_4 = F_40 ( V_20 , L_11 ) ;
if ( F_28 ( V_2 -> V_4 ) ) {
V_21 = F_30 ( V_2 -> V_4 ) ;
if ( V_21 != - V_76 )
F_24 ( V_20 , L_12 , V_21 ) ;
return V_21 ;
}
V_21 = F_21 ( V_23 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_33 ( V_23 ) ;
if ( V_21 )
return V_21 ;
V_2 -> V_11 = (enum V_77 ) V_49 -> V_61 ;
F_41 ( V_70 , V_23 ) ;
V_23 -> V_60 = V_78 ;
V_23 -> V_20 . V_79 = V_20 ;
V_23 -> V_20 . V_53 = V_70 -> V_20 . V_53 ;
V_23 -> V_80 = & V_81 ;
V_23 -> V_82 = V_83 ;
V_21 = F_42 ( V_2 -> V_4 ) ;
if ( V_21 ) {
F_24 ( V_20 , L_13 ) ;
goto V_84;
}
F_43 ( V_20 , V_85 ) ;
F_44 ( V_20 ) ;
F_45 ( V_20 ) ;
F_8 ( V_20 ) ;
F_1 ( V_2 ) ;
F_4 ( V_2 ) ;
V_21 = F_46 ( V_23 ) ;
if ( V_21 ) {
F_24 ( V_20 , L_14 ) ;
goto V_86;
}
F_47 ( V_20 ) ;
return 0 ;
V_86:
F_6 ( V_2 ) ;
F_47 ( V_20 ) ;
F_48 ( V_20 ) ;
F_49 ( V_20 ) ;
F_50 ( V_2 -> V_4 ) ;
V_84:
F_31 ( V_23 ) ;
return V_21 ;
}
static int F_51 ( struct V_69 * V_70 )
{
struct V_22 * V_23 = F_52 ( V_70 ) ;
struct V_1 * V_2 = F_13 ( V_23 ) ;
struct V_19 * V_20 = V_2 -> V_20 ;
F_53 ( V_23 ) ;
F_8 ( V_20 ) ;
F_6 ( V_2 ) ;
F_47 ( V_20 ) ;
F_48 ( V_20 ) ;
F_49 ( V_20 ) ;
F_50 ( V_2 -> V_4 ) ;
F_31 ( V_23 ) ;
return 0 ;
}
static int F_54 ( struct V_19 * V_20 )
{
struct V_22 * V_23 = F_55 ( V_20 ) ;
struct V_1 * V_2 = F_13 ( V_23 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_19 * V_20 )
{
struct V_22 * V_23 = F_55 ( V_20 ) ;
struct V_1 * V_2 = F_13 ( V_23 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
