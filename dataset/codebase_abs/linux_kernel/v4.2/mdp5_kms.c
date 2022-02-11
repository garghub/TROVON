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
int V_11 ;
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
int V_12 = V_3 -> V_5 -> V_13 . V_14 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
struct V_15 * V_16 = V_10 -> V_17 [ V_11 ] ;
struct V_18 * V_19 = V_10 -> V_20 [ V_11 ] ;
if ( ! V_16 )
continue;
F_14 ( V_16 , V_19 ) ;
}
F_15 ( V_3 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
F_17 ( V_22 ) ;
}
static long F_18 ( struct V_1 * V_2 , unsigned long V_23 ,
struct V_24 * V_25 )
{
return V_23 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_24 * V_26 ,
bool V_27 )
{
if ( V_27 )
return F_20 ( V_25 ,
V_26 ) ;
else
return F_21 ( V_25 , V_26 ) ;
}
static void F_22 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_30 * V_31 = V_3 -> V_5 -> V_32 ;
unsigned V_11 ;
for ( V_11 = 0 ; V_11 < V_31 -> V_33 ; V_11 ++ )
F_23 ( V_31 -> V_34 [ V_11 ] , V_29 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_35 * V_36 = V_3 -> V_36 ;
F_25 ( V_3 ) ;
if ( V_36 ) {
V_36 -> V_37 -> V_38 ( V_36 , V_39 , F_26 ( V_39 ) ) ;
V_36 -> V_37 -> V_40 ( V_36 ) ;
}
if ( V_3 -> V_8 )
F_27 ( V_3 -> V_8 ) ;
if ( V_3 -> V_41 )
F_28 ( V_3 -> V_41 ) ;
if ( V_3 -> V_42 )
F_29 ( V_3 -> V_42 ) ;
F_30 ( V_3 ) ;
}
int F_15 ( struct V_3 * V_3 )
{
F_31 ( L_1 ) ;
F_32 ( V_3 -> V_43 ) ;
F_32 ( V_3 -> V_44 ) ;
F_32 ( V_3 -> V_45 ) ;
F_32 ( V_3 -> V_46 ) ;
return 0 ;
}
int F_12 ( struct V_3 * V_3 )
{
F_31 ( L_1 ) ;
F_33 ( V_3 -> V_43 ) ;
F_33 ( V_3 -> V_44 ) ;
F_33 ( V_3 -> V_45 ) ;
F_33 ( V_3 -> V_46 ) ;
return 0 ;
}
static struct V_24 * F_34 ( struct V_3 * V_3 ,
enum V_47 V_48 , int V_49 ,
enum V_50 V_51 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_30 * V_31 = V_5 -> V_32 ;
struct V_24 * V_25 ;
struct V_52 V_53 = {
. V_54 = V_49 ,
. type = V_48 ,
. V_55 = V_51 ,
} ;
if ( ( V_48 == V_56 ) &&
( V_51 == V_57 ) )
V_25 = F_35 ( V_5 , & V_53 ) ;
else
V_25 = F_36 ( V_5 , & V_53 ) ;
if ( F_37 ( V_25 ) ) {
F_38 ( V_5 -> V_5 , L_2 ) ;
return V_25 ;
}
V_25 -> V_58 = ( 1 << V_31 -> V_33 ) - 1 ;
V_31 -> V_59 [ V_31 -> V_60 ++ ] = V_25 ;
return V_25 ;
}
static int F_39 ( const struct V_61 * V_62 , int V_49 )
{
const enum V_47 * V_63 = V_62 -> V_53 . V_64 ;
const int V_65 = F_26 ( V_62 -> V_53 . V_64 ) ;
int V_66 = 0 , V_11 ;
for ( V_11 = 0 ; V_11 < V_65 ; V_11 ++ ) {
if ( V_63 [ V_11 ] == V_56 ) {
if ( V_49 == V_11 )
return V_66 ;
V_66 ++ ;
}
}
return - V_67 ;
}
static int F_40 ( struct V_3 * V_3 , int V_49 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_30 * V_31 = V_5 -> V_32 ;
const struct V_61 * V_62 =
F_41 ( V_3 -> V_42 ) ;
enum V_47 V_48 = V_62 -> V_53 . V_64 [ V_49 ] ;
struct V_24 * V_25 ;
int V_68 = 0 ;
switch ( V_48 ) {
case V_69 :
break;
case V_70 :
if ( ! V_31 -> V_71 )
break;
V_25 = F_34 ( V_3 , V_70 , V_49 ,
V_72 ) ;
if ( F_37 ( V_25 ) ) {
V_68 = F_42 ( V_25 ) ;
break;
}
V_68 = F_43 ( V_31 -> V_71 , V_5 , V_25 ) ;
break;
case V_73 :
if ( ! V_31 -> V_74 )
break;
V_25 = F_34 ( V_3 , V_73 , V_49 ,
V_72 ) ;
if ( F_37 ( V_25 ) ) {
V_68 = F_42 ( V_25 ) ;
break;
}
V_68 = F_44 ( V_31 -> V_74 , V_5 , V_25 ) ;
break;
case V_56 :
{
int V_75 = F_39 ( V_62 , V_49 ) ;
struct V_24 * V_76 [ V_77 ] ;
enum V_50 V_55 ;
int V_11 ;
if ( ( V_75 >= F_26 ( V_31 -> V_78 ) ) || ( V_75 < 0 ) ) {
F_38 ( V_5 -> V_5 , L_3 ,
V_49 ) ;
V_68 = - V_67 ;
break;
}
if ( ! V_31 -> V_78 [ V_75 ] )
break;
for ( V_11 = 0 ; V_11 < V_77 ; V_11 ++ ) {
V_55 = ( V_11 == V_79 ) ?
V_57 :
V_80 ;
V_76 [ V_11 ] = F_34 ( V_3 , V_56 ,
V_49 , V_55 ) ;
if ( F_37 ( V_76 ) ) {
V_68 = F_42 ( V_76 ) ;
break;
}
}
V_68 = F_45 ( V_31 -> V_78 [ V_75 ] , V_5 , V_76 ) ;
break;
}
default:
F_38 ( V_5 -> V_5 , L_4 , V_48 ) ;
V_68 = - V_67 ;
break;
}
return V_68 ;
}
static int F_46 ( struct V_3 * V_3 )
{
static const enum V_81 V_34 [] = {
V_82 , V_83 , V_84 , V_85 ,
} ;
static const enum V_81 V_86 [] = {
V_87 , V_88 , V_89 , V_90 ,
} ;
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_30 * V_31 = V_5 -> V_32 ;
const struct V_61 * V_62 ;
int V_11 , V_68 ;
V_62 = F_41 ( V_3 -> V_42 ) ;
V_68 = F_47 ( V_3 ) ;
if ( V_68 )
goto V_91;
for ( V_11 = 0 ; V_11 < V_62 -> V_92 . V_93 ; V_11 ++ ) {
struct V_15 * V_16 ;
struct V_21 * V_22 ;
V_16 = F_48 ( V_5 , V_34 [ V_11 ] , true ,
V_62 -> V_92 . V_94 [ V_11 ] ) ;
if ( F_37 ( V_16 ) ) {
V_68 = F_42 ( V_16 ) ;
F_38 ( V_5 -> V_5 , L_5 ,
F_49 ( V_34 [ V_11 ] ) , V_68 ) ;
goto V_91;
}
V_22 = F_50 ( V_5 , V_16 , V_11 ) ;
if ( F_37 ( V_22 ) ) {
V_68 = F_42 ( V_22 ) ;
F_38 ( V_5 -> V_5 , L_6 ,
F_49 ( V_34 [ V_11 ] ) , V_68 ) ;
goto V_91;
}
V_31 -> V_34 [ V_31 -> V_33 ++ ] = V_22 ;
}
for ( V_11 = 0 ; V_11 < V_62 -> V_95 . V_93 ; V_11 ++ ) {
struct V_15 * V_16 ;
V_16 = F_48 ( V_5 , V_86 [ V_11 ] , false ,
V_62 -> V_95 . V_94 [ V_11 ] ) ;
if ( F_37 ( V_16 ) ) {
V_68 = F_42 ( V_16 ) ;
F_38 ( V_5 -> V_5 , L_7 ,
F_49 ( V_86 [ V_11 ] ) , V_68 ) ;
goto V_91;
}
}
for ( V_11 = 0 ; V_11 < F_26 ( V_62 -> V_53 . V_64 ) ; V_11 ++ ) {
V_68 = F_40 ( V_3 , V_11 ) ;
if ( V_68 )
goto V_91;
}
return 0 ;
V_91:
return V_68 ;
}
static void F_51 ( struct V_3 * V_3 ,
T_1 * V_96 , T_1 * V_97 )
{
T_1 V_98 ;
F_12 ( V_3 ) ;
V_98 = F_52 ( V_3 , V_99 ) ;
F_15 ( V_3 ) ;
* V_96 = F_53 ( V_98 , V_100 ) ;
* V_97 = F_53 ( V_98 , V_101 ) ;
F_31 ( L_8 , * V_96 , * V_97 ) ;
}
static int F_54 ( struct V_102 * V_103 , struct V_104 * * V_105 ,
const char * V_106 )
{
struct V_107 * V_5 = & V_103 -> V_5 ;
struct V_104 * V_104 = F_55 ( V_5 , V_106 ) ;
if ( F_37 ( V_104 ) ) {
F_38 ( V_5 , L_9 , V_106 , F_42 ( V_104 ) ) ;
return F_42 ( V_104 ) ;
}
* V_105 = V_104 ;
return 0 ;
}
struct V_1 * F_56 ( struct V_4 * V_5 )
{
struct V_102 * V_103 = V_5 -> V_108 ;
struct V_109 * V_110 ;
struct V_3 * V_3 ;
struct V_1 * V_2 = NULL ;
struct V_35 * V_36 ;
T_1 V_96 , V_97 ;
int V_11 , V_68 ;
V_3 = F_57 ( sizeof( * V_3 ) , V_111 ) ;
if ( ! V_3 ) {
F_38 ( V_5 -> V_5 , L_10 ) ;
V_68 = - V_112 ;
goto V_91;
}
F_58 ( & V_3 -> V_7 ) ;
F_59 ( & V_3 -> V_94 , & V_113 ) ;
V_2 = & V_3 -> V_94 . V_94 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_114 = F_60 ( V_103 , L_11 , L_12 ) ;
if ( F_37 ( V_3 -> V_114 ) ) {
V_68 = F_42 ( V_3 -> V_114 ) ;
goto V_91;
}
V_3 -> V_115 = F_60 ( V_103 , L_13 , L_14 ) ;
if ( F_37 ( V_3 -> V_115 ) ) {
V_68 = F_42 ( V_3 -> V_115 ) ;
goto V_91;
}
V_3 -> V_116 = F_61 ( & V_103 -> V_5 , L_15 ) ;
if ( F_37 ( V_3 -> V_116 ) ) {
V_68 = F_42 ( V_3 -> V_116 ) ;
goto V_91;
}
V_68 = F_62 ( V_3 -> V_116 ) ;
if ( V_68 ) {
F_38 ( V_5 -> V_5 , L_16 , V_68 ) ;
goto V_91;
}
V_68 = F_54 ( V_103 , & V_3 -> V_44 , L_17 ) ;
if ( V_68 )
goto V_91;
V_68 = F_54 ( V_103 , & V_3 -> V_43 , L_18 ) ;
if ( V_68 )
goto V_91;
V_68 = F_54 ( V_103 , & V_3 -> V_117 , L_19 ) ;
if ( V_68 )
goto V_91;
V_68 = F_54 ( V_103 , & V_3 -> V_45 , L_20 ) ;
if ( V_68 )
goto V_91;
V_68 = F_54 ( V_103 , & V_3 -> V_46 , L_21 ) ;
if ( V_68 )
goto V_91;
V_68 = F_54 ( V_103 , & V_3 -> V_118 , L_22 ) ;
if ( V_68 )
goto V_91;
F_63 ( V_3 -> V_117 , 200000000 ) ;
F_51 ( V_3 , & V_96 , & V_97 ) ;
V_3 -> V_42 = F_64 ( V_3 , V_96 , V_97 ) ;
if ( F_37 ( V_3 -> V_42 ) ) {
V_68 = F_42 ( V_3 -> V_42 ) ;
V_3 -> V_42 = NULL ;
goto V_91;
}
V_110 = F_65 ( V_3 -> V_42 ) ;
F_63 ( V_3 -> V_117 , V_110 -> V_119 -> V_120 ) ;
V_3 -> V_41 = F_66 ( V_3 -> V_5 , & V_110 -> V_119 -> V_41 ) ;
if ( F_37 ( V_3 -> V_41 ) ) {
V_68 = F_42 ( V_3 -> V_41 ) ;
V_3 -> V_41 = NULL ;
goto V_91;
}
V_3 -> V_8 = F_67 ( V_5 , V_3 -> V_114 , V_110 -> V_119 ) ;
if ( F_37 ( V_3 -> V_8 ) ) {
V_68 = F_42 ( V_3 -> V_8 ) ;
V_3 -> V_8 = NULL ;
goto V_91;
}
F_12 ( V_3 ) ;
for ( V_11 = 0 ; V_11 < V_121 ; V_11 ++ ) {
if ( F_68 ( V_110 -> V_119 -> V_53 . V_64 [ V_11 ] ) ||
! V_110 -> V_119 -> V_53 . V_94 [ V_11 ] )
continue;
F_6 ( V_3 , F_69 ( V_11 ) , 0 ) ;
}
F_15 ( V_3 ) ;
F_70 ( 16 ) ;
if ( V_110 -> V_122 . V_123 ) {
V_36 = F_71 ( & V_103 -> V_5 , V_110 -> V_122 . V_123 ) ;
if ( F_37 ( V_36 ) ) {
V_68 = F_42 ( V_36 ) ;
F_38 ( V_5 -> V_5 , L_23 , V_68 ) ;
goto V_91;
}
V_68 = V_36 -> V_37 -> V_124 ( V_36 , V_39 ,
F_26 ( V_39 ) ) ;
if ( V_68 ) {
F_38 ( V_5 -> V_5 , L_24 , V_68 ) ;
V_36 -> V_37 -> V_40 ( V_36 ) ;
goto V_91;
}
} else {
F_72 ( V_5 -> V_5 , L_25
L_26 ) ;
V_36 = NULL ;
}
V_3 -> V_36 = V_36 ;
V_3 -> V_66 = F_73 ( V_5 , V_36 ) ;
if ( V_3 -> V_66 < 0 ) {
V_68 = V_3 -> V_66 ;
F_38 ( V_5 -> V_5 , L_27 , V_68 ) ;
goto V_91;
}
V_68 = F_46 ( V_3 ) ;
if ( V_68 ) {
F_38 ( V_5 -> V_5 , L_28 , V_68 ) ;
goto V_91;
}
return V_2 ;
V_91:
if ( V_2 )
F_24 ( V_2 ) ;
return F_74 ( V_68 ) ;
}
