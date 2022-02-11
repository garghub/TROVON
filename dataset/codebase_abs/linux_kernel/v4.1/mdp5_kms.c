static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
unsigned long V_6 ;
F_4 ( V_5 -> V_5 ) ;
F_5 ( & V_3 -> V_7 , V_6 ) ;
F_6 ( V_3 , F_7 ( 0 ) , 0 ) ;
F_8 ( & V_3 -> V_7 , V_6 ) ;
F_9 ( V_3 -> V_8 ) ;
F_10 ( V_5 -> V_5 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
F_12 ( V_3 ) ;
}
static void F_13 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
F_14 ( V_3 ) ;
}
static long F_15 ( struct V_1 * V_2 , unsigned long V_11 ,
struct V_12 * V_13 )
{
return V_11 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
struct V_12 * V_14 ,
bool V_15 )
{
if ( V_15 )
return F_17 ( V_13 ,
V_14 ) ;
else
return F_18 ( V_13 , V_14 ) ;
}
static void F_19 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_18 * V_19 = V_3 -> V_5 -> V_20 ;
unsigned V_21 ;
for ( V_21 = 0 ; V_21 < V_19 -> V_22 ; V_21 ++ )
F_20 ( V_19 -> V_23 [ V_21 ] , V_17 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_24 * V_25 = V_3 -> V_25 ;
F_22 ( V_3 ) ;
if ( V_25 ) {
V_25 -> V_26 -> V_27 ( V_25 , V_28 , F_23 ( V_28 ) ) ;
V_25 -> V_26 -> V_29 ( V_25 ) ;
}
if ( V_3 -> V_8 )
F_24 ( V_3 -> V_8 ) ;
if ( V_3 -> V_30 )
F_25 ( V_3 -> V_30 ) ;
if ( V_3 -> V_31 )
F_26 ( V_3 -> V_31 ) ;
F_27 ( V_3 ) ;
}
int F_14 ( struct V_3 * V_3 )
{
F_28 ( L_1 ) ;
F_29 ( V_3 -> V_32 ) ;
F_29 ( V_3 -> V_33 ) ;
F_29 ( V_3 -> V_34 ) ;
F_29 ( V_3 -> V_35 ) ;
return 0 ;
}
int F_12 ( struct V_3 * V_3 )
{
F_28 ( L_1 ) ;
F_30 ( V_3 -> V_32 ) ;
F_30 ( V_3 -> V_33 ) ;
F_30 ( V_3 -> V_34 ) ;
F_30 ( V_3 -> V_35 ) ;
return 0 ;
}
static struct V_12 * F_31 ( struct V_3 * V_3 ,
enum V_36 V_37 , int V_38 ,
enum V_39 V_40 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_18 * V_19 = V_5 -> V_20 ;
struct V_12 * V_13 ;
struct V_41 V_42 = {
. V_43 = V_38 ,
. type = V_37 ,
. V_44 = V_40 ,
} ;
if ( ( V_37 == V_45 ) &&
( V_40 == V_46 ) )
V_13 = F_32 ( V_5 , & V_42 ) ;
else
V_13 = F_33 ( V_5 , & V_42 ) ;
if ( F_34 ( V_13 ) ) {
F_35 ( V_5 -> V_5 , L_2 ) ;
return V_13 ;
}
V_13 -> V_47 = ( 1 << V_19 -> V_22 ) - 1 ;
V_19 -> V_48 [ V_19 -> V_49 ++ ] = V_13 ;
return V_13 ;
}
static int F_36 ( const struct V_50 * V_51 , int V_38 )
{
const enum V_36 * V_52 = V_51 -> V_42 . V_53 ;
const int V_54 = F_23 ( V_51 -> V_42 . V_53 ) ;
int V_55 = 0 , V_21 ;
for ( V_21 = 0 ; V_21 < V_54 ; V_21 ++ ) {
if ( V_52 [ V_21 ] == V_45 ) {
if ( V_38 == V_21 )
return V_55 ;
V_55 ++ ;
}
}
return - V_56 ;
}
static int F_37 ( struct V_3 * V_3 , int V_38 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_18 * V_19 = V_5 -> V_20 ;
const struct V_50 * V_51 =
F_38 ( V_3 -> V_31 ) ;
enum V_36 V_37 = V_51 -> V_42 . V_53 [ V_38 ] ;
struct V_12 * V_13 ;
int V_57 = 0 ;
switch ( V_37 ) {
case V_58 :
break;
case V_59 :
if ( ! V_19 -> V_60 )
break;
V_13 = F_31 ( V_3 , V_59 , V_38 ,
V_61 ) ;
if ( F_34 ( V_13 ) ) {
V_57 = F_39 ( V_13 ) ;
break;
}
V_57 = F_40 ( V_19 -> V_60 , V_5 , V_13 ) ;
break;
case V_62 :
if ( ! V_19 -> V_63 )
break;
V_13 = F_31 ( V_3 , V_62 , V_38 ,
V_61 ) ;
if ( F_34 ( V_13 ) ) {
V_57 = F_39 ( V_13 ) ;
break;
}
V_57 = F_41 ( V_19 -> V_63 , V_5 , V_13 ) ;
break;
case V_45 :
{
int V_64 = F_36 ( V_51 , V_38 ) ;
struct V_12 * V_65 [ V_66 ] ;
enum V_39 V_44 ;
int V_21 ;
if ( ( V_64 >= F_23 ( V_19 -> V_67 ) ) || ( V_64 < 0 ) ) {
F_35 ( V_5 -> V_5 , L_3 ,
V_38 ) ;
V_57 = - V_56 ;
break;
}
if ( ! V_19 -> V_67 [ V_64 ] )
break;
for ( V_21 = 0 ; V_21 < V_66 ; V_21 ++ ) {
V_44 = ( V_21 == V_68 ) ?
V_46 :
V_69 ;
V_65 [ V_21 ] = F_31 ( V_3 , V_45 ,
V_38 , V_44 ) ;
if ( F_34 ( V_65 ) ) {
V_57 = F_39 ( V_65 ) ;
break;
}
}
V_57 = F_42 ( V_19 -> V_67 [ V_64 ] , V_5 , V_65 ) ;
break;
}
default:
F_35 ( V_5 -> V_5 , L_4 , V_37 ) ;
V_57 = - V_56 ;
break;
}
return V_57 ;
}
static int F_43 ( struct V_3 * V_3 )
{
static const enum V_70 V_23 [] = {
V_71 , V_72 , V_73 , V_74 ,
} ;
static const enum V_70 V_75 [] = {
V_76 , V_77 , V_78 , V_79 ,
} ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_18 * V_19 = V_5 -> V_20 ;
const struct V_50 * V_51 ;
int V_21 , V_57 ;
V_51 = F_38 ( V_3 -> V_31 ) ;
V_57 = F_44 ( V_3 ) ;
if ( V_57 )
goto V_80;
for ( V_21 = 0 ; V_21 < V_51 -> V_81 . V_82 ; V_21 ++ ) {
struct V_83 * V_84 ;
struct V_85 * V_86 ;
V_84 = F_45 ( V_5 , V_23 [ V_21 ] , true ,
V_51 -> V_81 . V_87 [ V_21 ] ) ;
if ( F_34 ( V_84 ) ) {
V_57 = F_39 ( V_84 ) ;
F_35 ( V_5 -> V_5 , L_5 ,
F_46 ( V_23 [ V_21 ] ) , V_57 ) ;
goto V_80;
}
V_86 = F_47 ( V_5 , V_84 , V_21 ) ;
if ( F_34 ( V_86 ) ) {
V_57 = F_39 ( V_86 ) ;
F_35 ( V_5 -> V_5 , L_6 ,
F_46 ( V_23 [ V_21 ] ) , V_57 ) ;
goto V_80;
}
V_19 -> V_23 [ V_19 -> V_22 ++ ] = V_86 ;
}
for ( V_21 = 0 ; V_21 < V_51 -> V_88 . V_82 ; V_21 ++ ) {
struct V_83 * V_84 ;
V_84 = F_45 ( V_5 , V_75 [ V_21 ] , false ,
V_51 -> V_88 . V_87 [ V_21 ] ) ;
if ( F_34 ( V_84 ) ) {
V_57 = F_39 ( V_84 ) ;
F_35 ( V_5 -> V_5 , L_7 ,
F_46 ( V_75 [ V_21 ] ) , V_57 ) ;
goto V_80;
}
}
for ( V_21 = 0 ; V_21 < F_23 ( V_51 -> V_42 . V_53 ) ; V_21 ++ ) {
V_57 = F_37 ( V_3 , V_21 ) ;
if ( V_57 )
goto V_80;
}
return 0 ;
V_80:
return V_57 ;
}
static void F_48 ( struct V_3 * V_3 ,
T_1 * V_89 , T_1 * V_90 )
{
T_1 V_91 ;
F_12 ( V_3 ) ;
V_91 = F_49 ( V_3 , V_92 ) ;
F_14 ( V_3 ) ;
* V_89 = F_50 ( V_91 , V_93 ) ;
* V_90 = F_50 ( V_91 , V_94 ) ;
F_28 ( L_8 , * V_89 , * V_90 ) ;
}
static int F_51 ( struct V_95 * V_96 , struct V_97 * * V_98 ,
const char * V_99 )
{
struct V_100 * V_5 = & V_96 -> V_5 ;
struct V_97 * V_97 = F_52 ( V_5 , V_99 ) ;
if ( F_34 ( V_97 ) ) {
F_35 ( V_5 , L_9 , V_99 , F_39 ( V_97 ) ) ;
return F_39 ( V_97 ) ;
}
* V_98 = V_97 ;
return 0 ;
}
struct V_1 * F_53 ( struct V_4 * V_5 )
{
struct V_95 * V_96 = V_5 -> V_101 ;
struct V_102 * V_103 ;
struct V_3 * V_3 ;
struct V_1 * V_2 = NULL ;
struct V_24 * V_25 ;
T_1 V_89 , V_90 ;
int V_21 , V_57 ;
V_3 = F_54 ( sizeof( * V_3 ) , V_104 ) ;
if ( ! V_3 ) {
F_35 ( V_5 -> V_5 , L_10 ) ;
V_57 = - V_105 ;
goto V_80;
}
F_55 ( & V_3 -> V_7 ) ;
F_56 ( & V_3 -> V_87 , & V_106 ) ;
V_2 = & V_3 -> V_87 . V_87 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_107 = F_57 ( V_96 , L_11 , L_12 ) ;
if ( F_34 ( V_3 -> V_107 ) ) {
V_57 = F_39 ( V_3 -> V_107 ) ;
goto V_80;
}
V_3 -> V_108 = F_57 ( V_96 , L_13 , L_14 ) ;
if ( F_34 ( V_3 -> V_108 ) ) {
V_57 = F_39 ( V_3 -> V_108 ) ;
goto V_80;
}
V_3 -> V_109 = F_58 ( & V_96 -> V_5 , L_15 ) ;
if ( F_34 ( V_3 -> V_109 ) ) {
V_57 = F_39 ( V_3 -> V_109 ) ;
goto V_80;
}
V_57 = F_59 ( V_3 -> V_109 ) ;
if ( V_57 ) {
F_35 ( V_5 -> V_5 , L_16 , V_57 ) ;
goto V_80;
}
V_57 = F_51 ( V_96 , & V_3 -> V_33 , L_17 ) ;
if ( V_57 )
goto V_80;
V_57 = F_51 ( V_96 , & V_3 -> V_32 , L_18 ) ;
if ( V_57 )
goto V_80;
V_57 = F_51 ( V_96 , & V_3 -> V_110 , L_19 ) ;
if ( V_57 )
goto V_80;
V_57 = F_51 ( V_96 , & V_3 -> V_34 , L_20 ) ;
if ( V_57 )
goto V_80;
V_57 = F_51 ( V_96 , & V_3 -> V_35 , L_21 ) ;
if ( V_57 )
goto V_80;
V_57 = F_51 ( V_96 , & V_3 -> V_111 , L_22 ) ;
if ( V_57 )
goto V_80;
F_60 ( V_3 -> V_110 , 200000000 ) ;
F_48 ( V_3 , & V_89 , & V_90 ) ;
V_3 -> V_31 = F_61 ( V_3 , V_89 , V_90 ) ;
if ( F_34 ( V_3 -> V_31 ) ) {
V_57 = F_39 ( V_3 -> V_31 ) ;
V_3 -> V_31 = NULL ;
goto V_80;
}
V_103 = F_62 ( V_3 -> V_31 ) ;
F_60 ( V_3 -> V_110 , V_103 -> V_112 -> V_113 ) ;
V_3 -> V_30 = F_63 ( V_3 -> V_5 , & V_103 -> V_112 -> V_30 ) ;
if ( F_34 ( V_3 -> V_30 ) ) {
V_57 = F_39 ( V_3 -> V_30 ) ;
V_3 -> V_30 = NULL ;
goto V_80;
}
V_3 -> V_8 = F_64 ( V_5 , V_3 -> V_107 , V_103 -> V_112 ) ;
if ( F_34 ( V_3 -> V_8 ) ) {
V_57 = F_39 ( V_3 -> V_8 ) ;
V_3 -> V_8 = NULL ;
goto V_80;
}
F_12 ( V_3 ) ;
for ( V_21 = 0 ; V_21 < V_114 ; V_21 ++ ) {
if ( F_65 ( V_103 -> V_112 -> V_42 . V_53 [ V_21 ] ) ||
! V_103 -> V_112 -> V_42 . V_87 [ V_21 ] )
continue;
F_6 ( V_3 , F_66 ( V_21 ) , 0 ) ;
}
F_14 ( V_3 ) ;
F_67 ( 16 ) ;
if ( V_103 -> V_115 . V_116 ) {
V_25 = F_68 ( & V_96 -> V_5 , V_103 -> V_115 . V_116 ) ;
if ( F_34 ( V_25 ) ) {
V_57 = F_39 ( V_25 ) ;
F_35 ( V_5 -> V_5 , L_23 , V_57 ) ;
goto V_80;
}
V_57 = V_25 -> V_26 -> V_117 ( V_25 , V_28 ,
F_23 ( V_28 ) ) ;
if ( V_57 ) {
F_35 ( V_5 -> V_5 , L_24 , V_57 ) ;
V_25 -> V_26 -> V_29 ( V_25 ) ;
goto V_80;
}
} else {
F_69 ( V_5 -> V_5 , L_25
L_26 ) ;
V_25 = NULL ;
}
V_3 -> V_25 = V_25 ;
V_3 -> V_55 = F_70 ( V_5 , V_25 ) ;
if ( V_3 -> V_55 < 0 ) {
V_57 = V_3 -> V_55 ;
F_35 ( V_5 -> V_5 , L_27 , V_57 ) ;
goto V_80;
}
V_57 = F_43 ( V_3 ) ;
if ( V_57 ) {
F_35 ( V_5 -> V_5 , L_28 , V_57 ) ;
goto V_80;
}
return V_2 ;
V_80:
if ( V_2 )
F_21 ( V_2 ) ;
return F_71 ( V_57 ) ;
}
