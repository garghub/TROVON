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
static int F_4 ( const struct V_2 * V_1 )
{
int V_3 ;
V_3 = F_5 ( V_1 -> V_4 ) ;
if ( V_3 ) {
F_6 ( & V_1 -> V_5 -> V_6 ,
L_1 ) ;
return V_3 ;
}
V_3 = F_5 ( V_1 -> V_7 ) ;
if ( V_3 ) {
F_6 ( & V_1 -> V_5 -> V_6 ,
L_2 ) ;
return V_3 ;
}
F_7 ( 500 , 1000 ) ;
return 0 ;
}
static void F_8 ( const struct V_2 * V_1 )
{
F_9 ( V_1 -> V_7 ) ;
F_9 ( V_1 -> V_4 ) ;
}
static int F_10 ( struct V_8 * V_5 ,
enum V_9 type )
{
T_2 V_10 [ 2 ] ;
int V_3 ;
V_3 = F_11 (
V_5 , V_11 , 2 , V_10 ) ;
if ( V_3 < 0 ) {
F_12 ( & V_5 -> V_6 , L_3 ) ;
return V_3 ;
}
if ( V_10 [ 0 ] != V_12 )
return - V_13 ;
switch ( type ) {
case V_14 :
case V_15 :
return 0 ;
case V_16 :
if ( V_10 [ 1 ] == V_17 )
return 0 ;
break;
case V_18 :
if ( V_10 [ 1 ] == V_19 )
return 0 ;
break;
default:
F_12 ( & V_5 -> V_6 , L_4 , type ) ;
}
return - V_13 ;
}
static int F_13 ( struct V_2 * V_1 , enum V_20 V_21 )
{
T_2 V_22 ;
int V_3 ;
V_22 = ( V_1 -> V_23 & ~ V_1 -> V_24 -> V_25 [ V_26 ] ) |
V_1 -> V_24 -> V_27 [ V_21 ] ;
V_3 = F_14 ( V_1 -> V_5 ,
V_1 -> V_24 -> V_28 [ V_29 ] , V_22 ) ;
if ( V_3 < 0 ) {
return V_3 ;
}
V_1 -> V_23 = V_22 ;
F_7 ( 100 , 500 ) ;
return 0 ;
}
static T_3 F_15 ( int V_30 , void * V_1 )
{
struct V_2 * V_31 = V_1 ;
F_16 ( 0 , & V_31 -> V_32 ) ;
F_17 ( & V_31 -> V_33 ) ;
return V_34 ;
}
static int F_18 ( struct V_2 * V_1 )
{
struct V_8 * V_5 = V_1 -> V_5 ;
int V_35 ;
int V_30 ;
F_19 ( & V_1 -> V_33 ) ;
F_20 ( 0 , & V_1 -> V_32 ) ;
if ( V_5 -> V_30 )
V_30 = V_5 -> V_30 ;
else
V_30 = F_21 ( V_1 -> V_36 ) ;
V_35 = F_22 ( & V_5 -> V_6 , V_30 , F_15 ,
V_37 | V_38 ,
F_23 ( & V_5 -> V_6 ) , V_1 ) ;
if ( V_35 < 0 ) {
F_12 ( & V_5 -> V_6 ,
L_5 ,
V_30 , V_1 -> V_36 , V_35 ) ;
return V_35 ;
}
V_1 -> V_39 = V_30 ;
return V_35 ;
}
static int F_24 ( struct V_8 * V_5 )
{
struct V_40 * V_41 = F_25 ( V_5 ) ;
struct V_2 * V_1 = F_26 ( V_41 ) ;
int V_3 ;
V_3 = F_13 ( V_1 , V_42 ) ;
if ( V_3 < 0 ) {
F_12 ( & V_5 -> V_6 , L_6 ) ;
return V_3 ;
}
V_3 = F_11 (
V_5 , V_1 -> V_24 -> V_28 [ V_43 ] ,
3 , V_1 -> V_44 ) ;
if ( V_3 < 0 ) {
F_12 ( & V_5 -> V_6 , L_7 ) ;
return V_3 ;
}
V_3 = F_13 ( V_1 , V_45 ) ;
if ( V_3 < 0 ) {
F_12 ( & V_5 -> V_6 , L_8 ) ;
return V_3 ;
}
if ( V_1 -> V_36 > 0 || V_5 -> V_30 > 0 ) {
V_3 = F_18 ( V_1 ) ;
if ( V_3 < 0 ) {
F_12 ( & V_5 -> V_6 ,
L_9 ) ;
return V_3 ;
}
}
V_1 -> V_46 [ 0 ] = V_1 -> V_24 -> V_46 ( V_1 -> V_44 [ 0 ] ) ;
V_1 -> V_46 [ 1 ] = V_1 -> V_24 -> V_46 ( V_1 -> V_44 [ 1 ] ) ;
V_1 -> V_46 [ 2 ] = V_1 -> V_24 -> V_46 ( V_1 -> V_44 [ 2 ] ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_1 )
{
struct V_8 * V_5 = V_1 -> V_5 ;
T_4 V_47 = V_48 ;
int V_3 ;
while ( V_47 ) {
F_28 ( V_49 ) ;
if ( F_29 ( V_1 -> V_36 ) )
break;
V_47 -= V_49 ;
}
if ( ! V_47 ) {
F_12 ( & V_5 -> V_6 , L_10 ) ;
return - V_50 ;
}
V_3 = F_30 ( V_5 , V_1 -> V_24 -> V_28 [ V_51 ] ) ;
if ( V_3 < 0 )
F_12 ( & V_5 -> V_6 , L_11 ) ;
return V_3 ;
}
static int F_31 ( struct V_2 * V_1 )
{
struct V_8 * V_5 = V_1 -> V_5 ;
T_2 V_52 ;
T_4 V_47 = V_48 ;
int V_3 ;
while ( V_47 ) {
F_28 ( V_49 ) ;
V_3 = F_30 ( V_5 ,
V_1 -> V_24 -> V_28 [ V_51 ] ) ;
if ( V_3 < 0 ) {
F_12 ( & V_5 -> V_6 , L_11 ) ;
return V_3 ;
}
V_52 = V_3 ;
if ( V_52 )
break;
V_47 -= V_49 ;
}
if ( ! V_47 ) {
F_12 ( & V_5 -> V_6 , L_10 ) ;
return - V_50 ;
}
return V_52 ;
}
static int F_32 ( struct V_2 * V_1 )
{
int V_3 ;
V_3 = F_33 ( V_1 -> V_33 ,
F_34 ( 0 , & V_1 -> V_32 ) ,
V_53 ) ;
F_20 ( 0 , & V_1 -> V_32 ) ;
return V_3 > 0 ? 0 : - V_54 ;
}
static int F_35 ( struct V_2 * V_1 ,
const struct V_8 * V_5 )
{
int V_3 = F_13 ( V_1 , V_55 ) ;
if ( V_3 < 0 ) {
F_12 ( & V_5 -> V_6 , L_12 ) ;
return V_3 ;
}
if ( V_1 -> V_39 )
V_3 = F_32 ( V_1 ) ;
else if ( F_36 ( V_1 -> V_36 ) )
V_3 = F_27 ( V_1 ) ;
else
V_3 = F_31 ( V_1 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_3 & V_1 -> V_24 -> V_25 [ V_56 ] ) {
V_3 = F_30 ( V_5 ,
V_1 -> V_24 -> V_28 [ V_57 ] ) ;
if ( V_3 < 0 ) {
F_12 ( & V_5 -> V_6 , L_13 ) ;
return V_3 ;
}
if ( V_3 & ( V_1 -> V_24 -> V_25 [ V_58 ] |
V_1 -> V_24 -> V_25 [ V_59 ] ) ) {
F_12 ( & V_5 -> V_6 , L_14 , V_3 ) ;
return - V_50 ;
}
}
return 0 ;
}
static int F_37 ( struct V_40 * V_41 , int V_60 , int * V_61 )
{
struct V_2 * V_1 = F_26 ( V_41 ) ;
const struct V_8 * V_5 = V_1 -> V_5 ;
const struct V_62 * V_24 = V_1 -> V_24 ;
T_5 V_63 ;
T_1 V_64 ;
int V_3 ;
F_38 ( & V_1 -> V_5 -> V_6 ) ;
F_39 ( & V_1 -> V_65 ) ;
V_3 = F_35 ( V_1 , V_5 ) ;
if ( V_3 )
goto exit;
V_3 = F_11 (
V_5 , V_24 -> V_66 [ V_60 ] ,
sizeof( V_63 ) , ( T_2 * ) & V_63 ) ;
if ( V_3 < 0 )
goto exit;
F_40 ( & V_1 -> V_65 ) ;
F_41 ( & V_1 -> V_5 -> V_6 ) ;
F_42 ( & V_1 -> V_5 -> V_6 ) ;
V_64 = F_43 ( V_63 ) ;
* V_61 = F_44 ( V_67 , V_64 , - V_24 -> V_68 , V_24 -> V_68 ) ;
return V_69 ;
exit:
F_40 ( & V_1 -> V_65 ) ;
F_12 ( & V_5 -> V_6 , L_15 ) ;
return V_3 ;
}
static int F_45 ( struct V_40 * V_41 ,
struct V_70 const * V_71 ,
int * V_61 , int * V_72 ,
long V_73 )
{
struct V_2 * V_1 = F_26 ( V_41 ) ;
switch ( V_73 ) {
case V_74 :
return F_37 ( V_41 , V_71 -> V_75 , V_61 ) ;
case V_76 :
* V_61 = 0 ;
* V_72 = V_1 -> V_46 [ V_71 -> V_75 ] ;
return V_77 ;
}
return - V_50 ;
}
static const struct V_78 *
F_46 ( const struct V_40 * V_41 ,
const struct V_70 * V_71 )
{
return & ( (struct V_2 * ) F_26 ( V_41 ) ) -> V_79 ;
}
static const char * F_47 ( struct V_80 * V_6 ,
enum V_9 * V_81 )
{
const struct V_82 * V_83 ;
V_83 = F_48 ( V_6 -> V_84 -> V_85 , V_6 ) ;
if ( ! V_83 )
return NULL ;
* V_81 = ( int ) V_83 -> V_86 ;
return F_23 ( V_6 ) ;
}
static void F_49 ( struct V_40 * V_41 )
{
struct V_2 * V_1 = F_26 ( V_41 ) ;
const struct V_8 * V_5 = V_1 -> V_5 ;
const struct V_62 * V_24 = V_1 -> V_24 ;
int V_3 ;
V_67 V_64 [ 8 ] ;
T_5 V_87 [ 3 ] ;
F_39 ( & V_1 -> V_65 ) ;
V_3 = F_35 ( V_1 , V_5 ) ;
if ( V_3 )
goto V_88;
V_3 = F_11 ( V_5 ,
V_24 -> V_66 [ 0 ] ,
3 * sizeof( V_87 [ 0 ] ) ,
( T_2 * ) V_87 ) ;
if ( V_3 < 0 )
goto V_88;
F_40 ( & V_1 -> V_65 ) ;
V_64 [ 0 ] = F_44 ( V_67 , F_43 ( V_87 [ 0 ] ) , - V_24 -> V_68 , V_24 -> V_68 ) ;
V_64 [ 1 ] = F_44 ( V_67 , F_43 ( V_87 [ 1 ] ) , - V_24 -> V_68 , V_24 -> V_68 ) ;
V_64 [ 2 ] = F_44 ( V_67 , F_43 ( V_87 [ 2 ] ) , - V_24 -> V_68 , V_24 -> V_68 ) ;
F_50 ( V_41 , V_64 ,
F_51 ( V_41 ) ) ;
return;
V_88:
F_40 ( & V_1 -> V_65 ) ;
F_12 ( & V_5 -> V_6 , L_16 ) ;
}
static T_3 F_52 ( int V_30 , void * V_89 )
{
const struct V_90 * V_91 = V_89 ;
struct V_40 * V_41 = V_91 -> V_41 ;
F_49 ( V_41 ) ;
F_53 ( V_41 -> V_92 ) ;
return V_34 ;
}
static int F_54 ( struct V_8 * V_5 ,
const struct V_93 * V_83 )
{
struct V_2 * V_1 ;
struct V_40 * V_41 ;
int V_36 ;
int V_94 ;
const char * V_95 = NULL ;
enum V_9 V_81 = V_96 ;
const struct V_97 * V_98 =
F_55 ( & V_5 -> V_6 ) ;
if ( V_98 )
V_36 = V_98 -> V_36 ;
else if ( V_5 -> V_6 . V_99 )
V_36 = F_56 ( V_5 -> V_6 . V_99 , 0 ) ;
else
V_36 = - 1 ;
if ( V_36 == - V_100 )
return - V_100 ;
if ( F_36 ( V_36 ) ) {
V_94 = F_57 ( & V_5 -> V_6 , V_36 ,
V_101 , L_17 ) ;
if ( V_94 < 0 ) {
F_12 ( & V_5 -> V_6 ,
L_18 ,
V_36 , V_94 ) ;
return V_94 ;
}
}
V_41 = F_58 ( & V_5 -> V_6 , sizeof( * V_1 ) ) ;
if ( V_41 == NULL )
return - V_102 ;
V_1 = F_26 ( V_41 ) ;
F_59 ( V_5 , V_41 ) ;
V_1 -> V_5 = V_5 ;
V_1 -> V_36 = V_36 ;
V_1 -> V_39 = 0 ;
if ( ! V_98 ) {
V_94 = F_60 ( & V_5 -> V_6 ,
L_19 ,
& V_1 -> V_79 ) ;
if ( V_94 )
return V_94 ;
} else
V_1 -> V_79 = V_98 -> V_79 ;
if ( V_83 ) {
V_81 = (enum V_9 ) ( V_83 -> V_86 ) ;
V_95 = V_83 -> V_95 ;
} else if ( F_61 ( & V_5 -> V_6 ) ) {
V_95 = F_47 ( & V_5 -> V_6 , & V_81 ) ;
if ( ! V_95 )
return - V_13 ;
} else
return - V_103 ;
if ( V_81 >= V_96 ) {
F_12 ( & V_5 -> V_6 , L_20 ,
V_81 ) ;
return - V_13 ;
}
V_1 -> V_24 = & V_104 [ V_81 ] ;
V_1 -> V_4 = F_62 ( & V_5 -> V_6 , L_21 ) ;
if ( F_63 ( V_1 -> V_4 ) )
return F_64 ( V_1 -> V_4 ) ;
V_1 -> V_7 = F_62 ( & V_5 -> V_6 , L_22 ) ;
if ( F_63 ( V_1 -> V_7 ) )
return F_64 ( V_1 -> V_7 ) ;
V_94 = F_4 ( V_1 ) ;
if ( V_94 )
return V_94 ;
V_94 = F_10 ( V_5 , V_1 -> V_24 -> type ) ;
if ( V_94 < 0 ) {
F_12 ( & V_5 -> V_6 , L_23 ) ;
goto V_105;
}
F_65 ( & V_5 -> V_6 , L_24 , V_95 ) ;
V_94 = F_24 ( V_5 ) ;
if ( V_94 < 0 ) {
F_12 ( & V_5 -> V_6 , L_25 , V_95 ) ;
goto V_105;
}
F_66 ( & V_1 -> V_65 ) ;
V_41 -> V_6 . V_106 = & V_5 -> V_6 ;
V_41 -> V_107 = V_108 ;
V_41 -> V_109 = F_67 ( V_108 ) ;
V_41 -> V_110 = & V_111 ;
V_41 -> V_112 = V_113 ;
V_41 -> V_114 = V_115 ;
V_41 -> V_95 = V_95 ;
V_94 = F_68 ( V_41 , NULL , F_52 ,
NULL ) ;
if ( V_94 ) {
F_12 ( & V_5 -> V_6 , L_26 ) ;
goto V_105;
}
V_94 = F_69 ( V_41 ) ;
if ( V_94 ) {
F_12 ( & V_5 -> V_6 , L_27 ) ;
goto V_116;
}
F_70 ( & V_5 -> V_6 ) ;
F_71 ( & V_5 -> V_6 ) ;
F_72 ( & V_5 -> V_6 ) ;
F_73 ( & V_5 -> V_6 , 50 ) ;
F_74 ( & V_5 -> V_6 ) ;
F_75 ( & V_5 -> V_6 ) ;
return 0 ;
V_116:
F_76 ( V_41 ) ;
V_105:
F_8 ( V_1 ) ;
return V_94 ;
}
static int F_77 ( struct V_8 * V_5 )
{
struct V_40 * V_41 = F_25 ( V_5 ) ;
struct V_2 * V_1 = F_26 ( V_41 ) ;
F_38 ( & V_5 -> V_6 ) ;
F_78 ( & V_5 -> V_6 ) ;
F_79 ( & V_5 -> V_6 ) ;
F_80 ( V_41 ) ;
F_76 ( V_41 ) ;
F_13 ( V_1 , V_45 ) ;
F_8 ( V_1 ) ;
return 0 ;
}
static int F_81 ( struct V_80 * V_6 )
{
struct V_8 * V_5 = F_82 ( V_6 ) ;
struct V_40 * V_41 = F_25 ( V_5 ) ;
struct V_2 * V_1 = F_26 ( V_41 ) ;
int V_3 ;
V_3 = F_13 ( V_1 , V_45 ) ;
if ( V_3 < 0 ) {
F_12 ( & V_5 -> V_6 , L_8 ) ;
return V_3 ;
}
F_8 ( V_1 ) ;
return 0 ;
}
static int F_83 ( struct V_80 * V_6 )
{
struct V_8 * V_5 = F_82 ( V_6 ) ;
struct V_40 * V_41 = F_25 ( V_5 ) ;
struct V_2 * V_1 = F_26 ( V_41 ) ;
int V_3 ;
F_4 ( V_1 ) ;
V_3 = F_13 ( V_1 , V_45 ) ;
if ( V_3 < 0 ) {
F_12 ( & V_5 -> V_6 , L_8 ) ;
return V_3 ;
}
return 0 ;
}
