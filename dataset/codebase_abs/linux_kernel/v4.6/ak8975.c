static long F_1 ( T_1 V_1 )
{
return ( ( ( long ) V_1 + 128 ) * 3000 ) / 256 ;
}
static long F_2 ( T_1 V_1 )
{
return ( ( ( long ) V_1 + 128 ) * 6000 ) / 256 ;
}
static long F_3 ( T_1 V_1 )
{
return ( ( ( long ) V_1 + 128 ) * 1500 ) / 256 ;
}
static int F_4 ( struct V_2 * V_3 ,
enum V_4 type )
{
T_2 V_5 [ 2 ] ;
int V_6 ;
V_6 = F_5 ( V_3 , V_7 ,
2 , V_5 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_3 -> V_8 , L_1 ) ;
return V_6 ;
}
if ( V_5 [ 0 ] != V_9 )
return - V_10 ;
switch ( type ) {
case V_11 :
case V_12 :
return 0 ;
case V_13 :
if ( V_5 [ 1 ] == V_14 )
return 0 ;
break;
case V_15 :
if ( V_5 [ 1 ] == V_16 )
return 0 ;
break;
default:
F_6 ( & V_3 -> V_8 , L_2 , type ) ;
}
return - V_10 ;
}
static int F_7 ( struct V_17 * V_1 , enum V_18 V_19 )
{
T_2 V_20 ;
int V_6 ;
V_20 = ( V_1 -> V_21 & ~ V_1 -> V_22 -> V_23 [ V_24 ] ) |
V_1 -> V_22 -> V_25 [ V_19 ] ;
V_6 = F_8 ( V_1 -> V_3 ,
V_1 -> V_22 -> V_26 [ V_27 ] , V_20 ) ;
if ( V_6 < 0 ) {
return V_6 ;
}
V_1 -> V_21 = V_20 ;
F_9 ( 100 , 500 ) ;
return 0 ;
}
static T_3 F_10 ( int V_28 , void * V_1 )
{
struct V_17 * V_29 = V_1 ;
F_11 ( 0 , & V_29 -> V_30 ) ;
F_12 ( & V_29 -> V_31 ) ;
return V_32 ;
}
static int F_13 ( struct V_17 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
int V_33 ;
int V_28 ;
F_14 ( & V_1 -> V_31 ) ;
F_15 ( 0 , & V_1 -> V_30 ) ;
if ( V_3 -> V_28 )
V_28 = V_3 -> V_28 ;
else
V_28 = F_16 ( V_1 -> V_34 ) ;
V_33 = F_17 ( & V_3 -> V_8 , V_28 , F_10 ,
V_35 | V_36 ,
F_18 ( & V_3 -> V_8 ) , V_1 ) ;
if ( V_33 < 0 ) {
F_6 ( & V_3 -> V_8 ,
L_3 ,
V_28 , V_1 -> V_34 , V_33 ) ;
return V_33 ;
}
V_1 -> V_37 = V_28 ;
return V_33 ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_38 * V_39 = F_20 ( V_3 ) ;
struct V_17 * V_1 = F_21 ( V_39 ) ;
int V_6 ;
V_6 = F_7 ( V_1 , V_40 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_3 -> V_8 , L_4 ) ;
return V_6 ;
}
V_6 = F_5 ( V_3 ,
V_1 -> V_22 -> V_26 [ V_41 ] ,
3 , V_1 -> V_42 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_3 -> V_8 , L_5 ) ;
return V_6 ;
}
V_6 = F_7 ( V_1 , V_43 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_3 -> V_8 , L_6 ) ;
return V_6 ;
}
if ( V_1 -> V_34 > 0 || V_3 -> V_28 > 0 ) {
V_6 = F_13 ( V_1 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_3 -> V_8 ,
L_7 ) ;
return V_6 ;
}
}
V_1 -> V_44 [ 0 ] = V_1 -> V_22 -> V_44 ( V_1 -> V_42 [ 0 ] ) ;
V_1 -> V_44 [ 1 ] = V_1 -> V_22 -> V_44 ( V_1 -> V_42 [ 1 ] ) ;
V_1 -> V_44 [ 2 ] = V_1 -> V_22 -> V_44 ( V_1 -> V_42 [ 2 ] ) ;
return 0 ;
}
static int F_22 ( struct V_17 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
T_4 V_45 = V_46 ;
int V_6 ;
while ( V_45 ) {
F_23 ( V_47 ) ;
if ( F_24 ( V_1 -> V_34 ) )
break;
V_45 -= V_47 ;
}
if ( ! V_45 ) {
F_6 ( & V_3 -> V_8 , L_8 ) ;
return - V_48 ;
}
V_6 = F_25 ( V_3 , V_1 -> V_22 -> V_26 [ V_49 ] ) ;
if ( V_6 < 0 )
F_6 ( & V_3 -> V_8 , L_9 ) ;
return V_6 ;
}
static int F_26 ( struct V_17 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
T_2 V_50 ;
T_4 V_45 = V_46 ;
int V_6 ;
while ( V_45 ) {
F_23 ( V_47 ) ;
V_6 = F_25 ( V_3 ,
V_1 -> V_22 -> V_26 [ V_49 ] ) ;
if ( V_6 < 0 ) {
F_6 ( & V_3 -> V_8 , L_9 ) ;
return V_6 ;
}
V_50 = V_6 ;
if ( V_50 )
break;
V_45 -= V_47 ;
}
if ( ! V_45 ) {
F_6 ( & V_3 -> V_8 , L_8 ) ;
return - V_48 ;
}
return V_50 ;
}
static int F_27 ( struct V_17 * V_1 )
{
int V_6 ;
V_6 = F_28 ( V_1 -> V_31 ,
F_29 ( 0 , & V_1 -> V_30 ) ,
V_51 ) ;
F_15 ( 0 , & V_1 -> V_30 ) ;
return V_6 > 0 ? 0 : - V_52 ;
}
static int F_30 ( struct V_38 * V_39 , int V_53 , int * V_54 )
{
struct V_17 * V_1 = F_21 ( V_39 ) ;
struct V_2 * V_3 = V_1 -> V_3 ;
int V_6 ;
F_31 ( & V_1 -> V_55 ) ;
V_6 = F_7 ( V_1 , V_56 ) ;
if ( V_6 < 0 ) {
F_6 ( & V_3 -> V_8 , L_10 ) ;
goto exit;
}
if ( V_1 -> V_37 )
V_6 = F_27 ( V_1 ) ;
else if ( F_32 ( V_1 -> V_34 ) )
V_6 = F_22 ( V_1 ) ;
else
V_6 = F_26 ( V_1 ) ;
if ( V_6 < 0 )
goto exit;
if ( V_6 & V_1 -> V_22 -> V_23 [ V_57 ] ) {
V_6 = F_25 ( V_3 ,
V_1 -> V_22 -> V_26 [ V_58 ] ) ;
if ( V_6 < 0 ) {
F_6 ( & V_3 -> V_8 , L_11 ) ;
goto exit;
}
if ( V_6 & ( V_1 -> V_22 -> V_23 [ V_59 ] |
V_1 -> V_22 -> V_23 [ V_60 ] ) ) {
F_6 ( & V_3 -> V_8 , L_12 , V_6 ) ;
V_6 = - V_48 ;
goto exit;
}
}
V_6 = F_33 ( V_3 , V_1 -> V_22 -> V_61 [ V_53 ] ) ;
if ( V_6 < 0 ) {
F_6 ( & V_3 -> V_8 , L_13 ) ;
goto exit;
}
F_34 ( & V_1 -> V_55 ) ;
* V_54 = F_35 ( V_62 , V_6 , - V_1 -> V_22 -> V_63 , V_1 -> V_22 -> V_63 ) ;
return V_64 ;
exit:
F_34 ( & V_1 -> V_55 ) ;
return V_6 ;
}
static int F_36 ( struct V_38 * V_39 ,
struct V_65 const * V_66 ,
int * V_54 , int * V_67 ,
long V_68 )
{
struct V_17 * V_1 = F_21 ( V_39 ) ;
switch ( V_68 ) {
case V_69 :
return F_30 ( V_39 , V_66 -> V_70 , V_54 ) ;
case V_71 :
* V_54 = 0 ;
* V_67 = V_1 -> V_44 [ V_66 -> V_70 ] ;
return V_72 ;
}
return - V_48 ;
}
static const char * F_37 ( struct V_73 * V_8 ,
enum V_4 * V_74 )
{
const struct V_75 * V_76 ;
V_76 = F_38 ( V_8 -> V_77 -> V_78 , V_8 ) ;
if ( ! V_76 )
return NULL ;
* V_74 = ( int ) V_76 -> V_79 ;
return F_18 ( V_8 ) ;
}
static int F_39 ( struct V_2 * V_3 ,
const struct V_80 * V_76 )
{
struct V_17 * V_1 ;
struct V_38 * V_39 ;
int V_34 ;
int V_81 ;
const char * V_82 = NULL ;
enum V_4 V_74 = V_83 ;
if ( V_3 -> V_8 . V_84 )
V_34 = * ( int * ) ( V_3 -> V_8 . V_84 ) ;
else if ( V_3 -> V_8 . V_85 )
V_34 = F_40 ( V_3 -> V_8 . V_85 , 0 ) ;
else
V_34 = - 1 ;
if ( V_34 == - V_86 )
return - V_86 ;
if ( F_32 ( V_34 ) ) {
V_81 = F_41 ( & V_3 -> V_8 , V_34 ,
V_87 , L_14 ) ;
if ( V_81 < 0 ) {
F_6 ( & V_3 -> V_8 ,
L_15 ,
V_34 , V_81 ) ;
return V_81 ;
}
}
V_39 = F_42 ( & V_3 -> V_8 , sizeof( * V_1 ) ) ;
if ( V_39 == NULL )
return - V_88 ;
V_1 = F_21 ( V_39 ) ;
F_43 ( V_3 , V_39 ) ;
V_1 -> V_3 = V_3 ;
V_1 -> V_34 = V_34 ;
V_1 -> V_37 = 0 ;
if ( V_76 ) {
V_74 = (enum V_4 ) ( V_76 -> V_79 ) ;
V_82 = V_76 -> V_82 ;
} else if ( F_44 ( & V_3 -> V_8 ) )
V_82 = F_37 ( & V_3 -> V_8 , & V_74 ) ;
else
return - V_89 ;
if ( V_74 >= V_83 ) {
F_6 ( & V_3 -> V_8 , L_16 ,
V_74 ) ;
return - V_10 ;
}
V_1 -> V_22 = & V_90 [ V_74 ] ;
V_81 = F_4 ( V_3 , V_1 -> V_22 -> type ) ;
if ( V_81 < 0 ) {
F_6 ( & V_3 -> V_8 , L_17 ) ;
return V_81 ;
}
F_45 ( & V_3 -> V_8 , L_18 , V_82 ) ;
V_81 = F_19 ( V_3 ) ;
if ( V_81 < 0 ) {
F_6 ( & V_3 -> V_8 , L_19 , V_82 ) ;
return V_81 ;
}
F_46 ( & V_1 -> V_55 ) ;
V_39 -> V_8 . V_91 = & V_3 -> V_8 ;
V_39 -> V_92 = V_93 ;
V_39 -> V_94 = F_47 ( V_93 ) ;
V_39 -> V_95 = & V_96 ;
V_39 -> V_97 = V_98 ;
V_39 -> V_82 = V_82 ;
return F_48 ( & V_3 -> V_8 , V_39 ) ;
}
