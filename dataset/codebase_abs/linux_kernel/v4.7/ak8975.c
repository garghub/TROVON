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
static int F_4 ( struct V_2 * V_3 )
{
const struct V_4 * V_5 = F_5 ( V_3 ) ;
struct V_6 * V_1 = F_6 ( V_5 ) ;
int V_7 ;
V_1 -> V_8 = F_7 ( & V_3 -> V_9 , L_1 ) ;
if ( F_8 ( V_1 -> V_8 ) ) {
V_7 = F_9 ( V_1 -> V_8 ) ;
if ( V_7 == - V_10 )
V_7 = 0 ;
} else {
V_7 = F_10 ( V_1 -> V_8 ) ;
}
if ( V_7 )
F_11 ( & V_3 -> V_9 , L_2 , V_7 ) ;
return V_7 ;
}
static void F_12 ( const struct V_2 * V_3 )
{
const struct V_4 * V_5 = F_5 ( V_3 ) ;
const struct V_6 * V_1 = F_6 ( V_5 ) ;
if ( ! F_8 ( V_1 -> V_8 ) )
F_13 ( V_1 -> V_8 ) ;
}
static int F_14 ( struct V_2 * V_3 ,
enum V_11 type )
{
T_2 V_12 [ 2 ] ;
int V_7 ;
V_7 = F_15 ( V_3 , V_13 ,
2 , V_12 ) ;
if ( V_7 < 0 ) {
F_11 ( & V_3 -> V_9 , L_3 ) ;
return V_7 ;
}
if ( V_12 [ 0 ] != V_14 )
return - V_10 ;
switch ( type ) {
case V_15 :
case V_16 :
return 0 ;
case V_17 :
if ( V_12 [ 1 ] == V_18 )
return 0 ;
break;
case V_19 :
if ( V_12 [ 1 ] == V_20 )
return 0 ;
break;
default:
F_11 ( & V_3 -> V_9 , L_4 , type ) ;
}
return - V_10 ;
}
static int F_16 ( struct V_6 * V_1 , enum V_21 V_22 )
{
T_2 V_23 ;
int V_7 ;
V_23 = ( V_1 -> V_24 & ~ V_1 -> V_25 -> V_26 [ V_27 ] ) |
V_1 -> V_25 -> V_28 [ V_22 ] ;
V_7 = F_17 ( V_1 -> V_3 ,
V_1 -> V_25 -> V_29 [ V_30 ] , V_23 ) ;
if ( V_7 < 0 ) {
return V_7 ;
}
V_1 -> V_24 = V_23 ;
F_18 ( 100 , 500 ) ;
return 0 ;
}
static T_3 F_19 ( int V_31 , void * V_1 )
{
struct V_6 * V_32 = V_1 ;
F_20 ( 0 , & V_32 -> V_33 ) ;
F_21 ( & V_32 -> V_34 ) ;
return V_35 ;
}
static int F_22 ( struct V_6 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
int V_36 ;
int V_31 ;
F_23 ( & V_1 -> V_34 ) ;
F_24 ( 0 , & V_1 -> V_33 ) ;
if ( V_3 -> V_31 )
V_31 = V_3 -> V_31 ;
else
V_31 = F_25 ( V_1 -> V_37 ) ;
V_36 = F_26 ( & V_3 -> V_9 , V_31 , F_19 ,
V_38 | V_39 ,
F_27 ( & V_3 -> V_9 ) , V_1 ) ;
if ( V_36 < 0 ) {
F_11 ( & V_3 -> V_9 ,
L_5 ,
V_31 , V_1 -> V_37 , V_36 ) ;
return V_36 ;
}
V_1 -> V_40 = V_31 ;
return V_36 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_5 ( V_3 ) ;
struct V_6 * V_1 = F_6 ( V_5 ) ;
int V_7 ;
V_7 = F_16 ( V_1 , V_41 ) ;
if ( V_7 < 0 ) {
F_11 ( & V_3 -> V_9 , L_6 ) ;
return V_7 ;
}
V_7 = F_15 ( V_3 ,
V_1 -> V_25 -> V_29 [ V_42 ] ,
3 , V_1 -> V_43 ) ;
if ( V_7 < 0 ) {
F_11 ( & V_3 -> V_9 , L_7 ) ;
return V_7 ;
}
V_7 = F_16 ( V_1 , V_44 ) ;
if ( V_7 < 0 ) {
F_11 ( & V_3 -> V_9 , L_8 ) ;
return V_7 ;
}
if ( V_1 -> V_37 > 0 || V_3 -> V_31 > 0 ) {
V_7 = F_22 ( V_1 ) ;
if ( V_7 < 0 ) {
F_11 ( & V_3 -> V_9 ,
L_9 ) ;
return V_7 ;
}
}
V_1 -> V_45 [ 0 ] = V_1 -> V_25 -> V_45 ( V_1 -> V_43 [ 0 ] ) ;
V_1 -> V_45 [ 1 ] = V_1 -> V_25 -> V_45 ( V_1 -> V_43 [ 1 ] ) ;
V_1 -> V_45 [ 2 ] = V_1 -> V_25 -> V_45 ( V_1 -> V_43 [ 2 ] ) ;
return 0 ;
}
static int F_29 ( struct V_6 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
T_4 V_46 = V_47 ;
int V_7 ;
while ( V_46 ) {
F_30 ( V_48 ) ;
if ( F_31 ( V_1 -> V_37 ) )
break;
V_46 -= V_48 ;
}
if ( ! V_46 ) {
F_11 ( & V_3 -> V_9 , L_10 ) ;
return - V_49 ;
}
V_7 = F_32 ( V_3 , V_1 -> V_25 -> V_29 [ V_50 ] ) ;
if ( V_7 < 0 )
F_11 ( & V_3 -> V_9 , L_11 ) ;
return V_7 ;
}
static int F_33 ( struct V_6 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
T_2 V_51 ;
T_4 V_46 = V_47 ;
int V_7 ;
while ( V_46 ) {
F_30 ( V_48 ) ;
V_7 = F_32 ( V_3 ,
V_1 -> V_25 -> V_29 [ V_50 ] ) ;
if ( V_7 < 0 ) {
F_11 ( & V_3 -> V_9 , L_11 ) ;
return V_7 ;
}
V_51 = V_7 ;
if ( V_51 )
break;
V_46 -= V_48 ;
}
if ( ! V_46 ) {
F_11 ( & V_3 -> V_9 , L_10 ) ;
return - V_49 ;
}
return V_51 ;
}
static int F_34 ( struct V_6 * V_1 )
{
int V_7 ;
V_7 = F_35 ( V_1 -> V_34 ,
F_36 ( 0 , & V_1 -> V_33 ) ,
V_52 ) ;
F_24 ( 0 , & V_1 -> V_33 ) ;
return V_7 > 0 ? 0 : - V_53 ;
}
static int F_37 ( struct V_6 * V_1 ,
const struct V_2 * V_3 )
{
int V_7 = F_16 ( V_1 , V_54 ) ;
if ( V_7 < 0 ) {
F_11 ( & V_3 -> V_9 , L_12 ) ;
return V_7 ;
}
if ( V_1 -> V_40 )
V_7 = F_34 ( V_1 ) ;
else if ( F_38 ( V_1 -> V_37 ) )
V_7 = F_29 ( V_1 ) ;
else
V_7 = F_33 ( V_1 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_7 & V_1 -> V_25 -> V_26 [ V_55 ] ) {
V_7 = F_32 ( V_3 ,
V_1 -> V_25 -> V_29 [ V_56 ] ) ;
if ( V_7 < 0 ) {
F_11 ( & V_3 -> V_9 , L_13 ) ;
return V_7 ;
}
if ( V_7 & ( V_1 -> V_25 -> V_26 [ V_57 ] |
V_1 -> V_25 -> V_26 [ V_58 ] ) ) {
F_11 ( & V_3 -> V_9 , L_14 , V_7 ) ;
return - V_49 ;
}
}
return 0 ;
}
static int F_39 ( struct V_4 * V_5 , int V_59 , int * V_60 )
{
struct V_6 * V_1 = F_6 ( V_5 ) ;
const struct V_2 * V_3 = V_1 -> V_3 ;
const struct V_61 * V_25 = V_1 -> V_25 ;
int V_7 ;
F_40 ( & V_1 -> V_62 ) ;
V_7 = F_37 ( V_1 , V_3 ) ;
if ( V_7 )
goto exit;
V_7 = F_41 ( V_3 , V_25 -> V_63 [ V_59 ] ) ;
if ( V_7 < 0 )
goto exit;
F_42 ( & V_1 -> V_62 ) ;
* V_60 = F_43 ( V_64 , V_7 , - V_25 -> V_65 , V_25 -> V_65 ) ;
return V_66 ;
exit:
F_42 ( & V_1 -> V_62 ) ;
F_11 ( & V_3 -> V_9 , L_15 ) ;
return V_7 ;
}
static int F_44 ( struct V_4 * V_5 ,
struct V_67 const * V_68 ,
int * V_60 , int * V_69 ,
long V_70 )
{
struct V_6 * V_1 = F_6 ( V_5 ) ;
switch ( V_70 ) {
case V_71 :
return F_39 ( V_5 , V_68 -> V_72 , V_60 ) ;
case V_73 :
* V_60 = 0 ;
* V_69 = V_1 -> V_45 [ V_68 -> V_72 ] ;
return V_74 ;
}
return - V_49 ;
}
static const struct V_75 *
F_45 ( const struct V_4 * V_5 ,
const struct V_67 * V_68 )
{
return & ( (struct V_6 * ) F_6 ( V_5 ) ) -> V_76 ;
}
static const char * F_46 ( struct V_77 * V_9 ,
enum V_11 * V_78 )
{
const struct V_79 * V_80 ;
V_80 = F_47 ( V_9 -> V_81 -> V_82 , V_9 ) ;
if ( ! V_80 )
return NULL ;
* V_78 = ( int ) V_80 -> V_83 ;
return F_27 ( V_9 ) ;
}
static void F_48 ( struct V_4 * V_5 )
{
struct V_6 * V_1 = F_6 ( V_5 ) ;
const struct V_2 * V_3 = V_1 -> V_3 ;
const struct V_61 * V_25 = V_1 -> V_25 ;
int V_7 ;
V_64 V_84 [ 8 ] ;
F_40 ( & V_1 -> V_62 ) ;
V_7 = F_37 ( V_1 , V_3 ) ;
if ( V_7 )
goto V_85;
V_7 = F_49 ( V_3 ,
V_25 -> V_63 [ 0 ] ,
3 * sizeof( V_84 [ 0 ] ) ,
( T_2 * ) V_84 ) ;
if ( V_7 < 0 )
goto V_85;
F_42 ( & V_1 -> V_62 ) ;
V_84 [ 0 ] = F_43 ( V_64 , F_50 ( V_84 [ 0 ] ) , - V_25 -> V_65 , V_25 -> V_65 ) ;
V_84 [ 1 ] = F_43 ( V_64 , F_50 ( V_84 [ 1 ] ) , - V_25 -> V_65 , V_25 -> V_65 ) ;
V_84 [ 2 ] = F_43 ( V_64 , F_50 ( V_84 [ 2 ] ) , - V_25 -> V_65 , V_25 -> V_65 ) ;
F_51 ( V_5 , V_84 , F_52 () ) ;
return;
V_85:
F_42 ( & V_1 -> V_62 ) ;
F_11 ( & V_3 -> V_9 , L_16 ) ;
}
static T_3 F_53 ( int V_31 , void * V_86 )
{
const struct V_87 * V_88 = V_86 ;
struct V_4 * V_5 = V_88 -> V_5 ;
F_48 ( V_5 ) ;
F_54 ( V_5 -> V_89 ) ;
return V_35 ;
}
static int F_55 ( struct V_2 * V_3 ,
const struct V_90 * V_80 )
{
struct V_6 * V_1 ;
struct V_4 * V_5 ;
int V_37 ;
int V_91 ;
const char * V_92 = NULL ;
enum V_11 V_78 = V_93 ;
const struct V_94 * V_95 =
F_56 ( & V_3 -> V_9 ) ;
if ( V_95 )
V_37 = V_95 -> V_37 ;
else if ( V_3 -> V_9 . V_96 )
V_37 = F_57 ( V_3 -> V_9 . V_96 , 0 ) ;
else
V_37 = - 1 ;
if ( V_37 == - V_97 )
return - V_97 ;
if ( F_38 ( V_37 ) ) {
V_91 = F_58 ( & V_3 -> V_9 , V_37 ,
V_98 , L_17 ) ;
if ( V_91 < 0 ) {
F_11 ( & V_3 -> V_9 ,
L_18 ,
V_37 , V_91 ) ;
return V_91 ;
}
}
V_5 = F_59 ( & V_3 -> V_9 , sizeof( * V_1 ) ) ;
if ( V_5 == NULL )
return - V_99 ;
V_1 = F_6 ( V_5 ) ;
F_60 ( V_3 , V_5 ) ;
V_1 -> V_3 = V_3 ;
V_1 -> V_37 = V_37 ;
V_1 -> V_40 = 0 ;
if ( ! V_95 ) {
V_91 = F_61 ( & V_3 -> V_9 ,
L_19 ,
& V_1 -> V_76 ) ;
if ( V_91 )
return V_91 ;
} else
V_1 -> V_76 = V_95 -> V_76 ;
if ( V_80 ) {
V_78 = (enum V_11 ) ( V_80 -> V_83 ) ;
V_92 = V_80 -> V_92 ;
} else if ( F_62 ( & V_3 -> V_9 ) ) {
V_92 = F_46 ( & V_3 -> V_9 , & V_78 ) ;
if ( ! V_92 )
return - V_10 ;
} else
return - V_100 ;
if ( V_78 >= V_93 ) {
F_11 ( & V_3 -> V_9 , L_20 ,
V_78 ) ;
return - V_10 ;
}
V_1 -> V_25 = & V_101 [ V_78 ] ;
V_91 = F_4 ( V_3 ) ;
if ( V_91 )
return V_91 ;
V_91 = F_14 ( V_3 , V_1 -> V_25 -> type ) ;
if ( V_91 < 0 ) {
F_11 ( & V_3 -> V_9 , L_21 ) ;
goto V_102;
}
F_63 ( & V_3 -> V_9 , L_22 , V_92 ) ;
V_91 = F_28 ( V_3 ) ;
if ( V_91 < 0 ) {
F_11 ( & V_3 -> V_9 , L_23 , V_92 ) ;
goto V_102;
}
F_64 ( & V_1 -> V_62 ) ;
V_5 -> V_9 . V_103 = & V_3 -> V_9 ;
V_5 -> V_104 = V_105 ;
V_5 -> V_106 = F_65 ( V_105 ) ;
V_5 -> V_107 = & V_108 ;
V_5 -> V_109 = V_110 ;
V_5 -> V_111 = V_112 ;
V_5 -> V_92 = V_92 ;
V_91 = F_66 ( V_5 , NULL , F_53 ,
NULL ) ;
if ( V_91 ) {
F_11 ( & V_3 -> V_9 , L_24 ) ;
goto V_102;
}
V_91 = F_67 ( V_5 ) ;
if ( V_91 ) {
F_11 ( & V_3 -> V_9 , L_25 ) ;
goto V_113;
}
return 0 ;
V_113:
F_68 ( V_5 ) ;
V_102:
F_12 ( V_3 ) ;
return V_91 ;
}
static int F_69 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_5 ( V_3 ) ;
F_70 ( V_5 ) ;
F_68 ( V_5 ) ;
F_12 ( V_3 ) ;
return 0 ;
}
