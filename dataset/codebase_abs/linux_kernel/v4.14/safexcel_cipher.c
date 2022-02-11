static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
T_1 V_7 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_10 * V_11 ;
unsigned V_12 = 0 ;
if ( V_2 -> V_13 == V_14 ) {
V_12 = V_15 / sizeof( T_1 ) ;
memcpy ( V_6 -> V_16 . V_11 , V_9 -> V_17 , V_15 ) ;
V_6 -> V_16 . V_18 |= V_19 ;
}
V_11 = (struct V_10 * ) ( V_6 -> V_16 . V_11 + V_12 ) ;
V_11 [ 0 ] . V_20 = V_21 ;
V_11 [ 0 ] . V_22 = V_7 ;
V_11 [ 0 ] . V_23 = V_24 ;
V_11 [ 0 ] . V_25 = V_26 |
V_27 |
V_28 ;
}
static int F_3 ( struct V_29 * V_30 , const T_2 * V_31 ,
unsigned int V_32 )
{
struct V_33 * V_34 = F_4 ( V_30 ) ;
struct V_1 * V_2 = F_5 ( V_34 ) ;
struct V_35 V_36 ;
int V_37 , V_38 ;
V_37 = F_6 ( & V_36 , V_31 , V_32 ) ;
if ( V_37 ) {
F_7 ( V_30 , V_39 ) ;
return V_37 ;
}
for ( V_38 = 0 ; V_38 < V_32 / sizeof( T_1 ) ; V_38 ++ ) {
if ( V_2 -> V_31 [ V_38 ] != F_8 ( V_36 . V_40 [ V_38 ] ) ) {
V_2 -> V_41 . V_42 = true ;
break;
}
}
for ( V_38 = 0 ; V_38 < V_32 / sizeof( T_1 ) ; V_38 ++ )
V_2 -> V_31 [ V_38 ] = F_8 ( V_36 . V_40 [ V_38 ] ) ;
V_2 -> V_43 = V_32 ;
F_9 ( & V_36 , sizeof( V_36 ) ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_5 * V_6 )
{
struct V_44 * V_45 = V_2 -> V_45 ;
int V_46 ;
if ( V_2 -> V_47 == V_48 )
V_6 -> V_16 . V_49 |= V_50 ;
else
V_6 -> V_16 . V_49 |= V_51 ;
V_6 -> V_16 . V_49 |= V_52 ;
V_6 -> V_16 . V_53 |= V_2 -> V_13 ;
switch ( V_2 -> V_43 ) {
case V_54 :
V_6 -> V_16 . V_49 |= V_55 ;
V_46 = 4 ;
break;
case V_56 :
V_6 -> V_16 . V_49 |= V_57 ;
V_46 = 6 ;
break;
case V_58 :
V_6 -> V_16 . V_49 |= V_59 ;
V_46 = 8 ;
break;
default:
F_11 ( V_45 -> V_60 , L_1 ,
V_2 -> V_43 ) ;
return - V_61 ;
}
V_6 -> V_16 . V_49 |= F_12 ( V_46 ) ;
return 0 ;
}
static int F_13 ( struct V_44 * V_45 , int V_62 ,
struct V_3 * V_4 ,
bool * V_63 , int * V_37 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_64 * V_65 ;
int V_66 = 0 ;
* V_37 = 0 ;
F_14 ( & V_45 -> V_62 [ V_62 ] . V_67 ) ;
do {
V_65 = F_15 ( V_45 , & V_45 -> V_62 [ V_62 ] . V_68 ) ;
if ( F_16 ( V_65 ) ) {
F_11 ( V_45 -> V_60 ,
L_2 ) ;
* V_37 = F_17 ( V_65 ) ;
break;
}
if ( V_65 -> V_69 . V_70 ) {
F_11 ( V_45 -> V_60 ,
L_3 ,
V_65 -> V_69 . V_70 ) ;
* V_37 = - V_71 ;
}
V_66 ++ ;
} while ( ! V_65 -> V_72 );
F_18 ( V_45 , V_62 ) ;
F_19 ( & V_45 -> V_62 [ V_62 ] . V_67 ) ;
if ( V_9 -> V_73 == V_9 -> V_74 ) {
F_20 ( V_45 -> V_60 , V_9 -> V_73 ,
F_21 ( V_9 -> V_73 , V_9 -> V_75 ) ,
V_76 ) ;
} else {
F_20 ( V_45 -> V_60 , V_9 -> V_73 ,
F_21 ( V_9 -> V_73 , V_9 -> V_75 ) ,
V_77 ) ;
F_20 ( V_45 -> V_60 , V_9 -> V_74 ,
F_21 ( V_9 -> V_74 , V_9 -> V_75 ) ,
V_78 ) ;
}
* V_63 = true ;
return V_66 ;
}
static int F_22 ( struct V_3 * V_4 ,
int V_62 , struct V_79 * V_80 ,
int * V_81 , int * V_82 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = F_5 ( V_9 -> V_41 . V_34 ) ;
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_5 * V_6 ;
struct V_64 * V_65 ;
struct V_83 * V_84 ;
int V_85 , V_86 , V_87 = 0 , V_88 = 0 , V_89 = V_9 -> V_75 ;
int V_38 , V_37 = 0 ;
if ( V_9 -> V_73 == V_9 -> V_74 ) {
V_85 = F_23 ( V_45 -> V_60 , V_9 -> V_73 ,
F_21 ( V_9 -> V_73 , V_9 -> V_75 ) ,
V_76 ) ;
V_86 = V_85 ;
if ( ! V_85 )
return - V_61 ;
} else {
V_85 = F_23 ( V_45 -> V_60 , V_9 -> V_73 ,
F_21 ( V_9 -> V_73 , V_9 -> V_75 ) ,
V_77 ) ;
if ( ! V_85 )
return - V_61 ;
V_86 = F_23 ( V_45 -> V_60 , V_9 -> V_74 ,
F_21 ( V_9 -> V_74 , V_9 -> V_75 ) ,
V_78 ) ;
if ( ! V_86 ) {
F_20 ( V_45 -> V_60 , V_9 -> V_73 ,
F_21 ( V_9 -> V_73 , V_9 -> V_75 ) ,
V_77 ) ;
return - V_61 ;
}
}
memcpy ( V_2 -> V_41 . V_90 -> V_91 , V_2 -> V_31 , V_2 -> V_43 ) ;
F_14 ( & V_45 -> V_62 [ V_62 ] . V_67 ) ;
F_24 (req->src, sg, nr_src, i) {
int V_32 = F_25 ( V_84 ) ;
if ( V_89 - V_32 < 0 )
V_32 = V_89 ;
V_6 = F_26 ( V_45 , V_62 , ! V_87 , ! ( V_89 - V_32 ) ,
F_27 ( V_84 ) , V_32 , V_9 -> V_75 ,
V_2 -> V_41 . V_92 ) ;
if ( F_16 ( V_6 ) ) {
V_37 = F_17 ( V_6 ) ;
goto V_93;
}
V_87 ++ ;
if ( V_87 == 1 ) {
F_10 ( V_2 , V_6 ) ;
F_1 ( V_2 , V_4 , V_6 , V_9 -> V_75 ) ;
}
V_89 -= V_32 ;
if ( ! V_89 )
break;
}
F_24 (req->dst, sg, nr_dst, i) {
bool V_94 = ! V_38 , V_95 = ( V_38 == V_86 - 1 ) ;
T_1 V_32 = F_25 ( V_84 ) ;
V_65 = F_28 ( V_45 , V_62 , V_94 , V_95 ,
F_27 ( V_84 ) , V_32 ) ;
if ( F_16 ( V_65 ) ) {
V_37 = F_17 ( V_65 ) ;
goto V_96;
}
V_88 ++ ;
}
F_19 ( & V_45 -> V_62 [ V_62 ] . V_67 ) ;
V_80 -> V_9 = & V_9 -> V_41 ;
V_2 -> V_41 . V_97 = F_13 ;
* V_81 = V_87 ;
* V_82 = V_88 ;
return 0 ;
V_96:
for ( V_38 = 0 ; V_38 < V_88 ; V_38 ++ )
F_29 ( V_45 , & V_45 -> V_62 [ V_62 ] . V_68 ) ;
V_93:
for ( V_38 = 0 ; V_38 < V_87 ; V_38 ++ )
F_29 ( V_45 , & V_45 -> V_62 [ V_62 ] . V_98 ) ;
F_19 ( & V_45 -> V_62 [ V_62 ] . V_67 ) ;
if ( V_9 -> V_73 == V_9 -> V_74 ) {
F_20 ( V_45 -> V_60 , V_9 -> V_73 ,
F_21 ( V_9 -> V_73 , V_9 -> V_75 ) ,
V_76 ) ;
} else {
F_20 ( V_45 -> V_60 , V_9 -> V_73 ,
F_21 ( V_9 -> V_73 , V_9 -> V_75 ) ,
V_77 ) ;
F_20 ( V_45 -> V_60 , V_9 -> V_74 ,
F_21 ( V_9 -> V_74 , V_9 -> V_75 ) ,
V_78 ) ;
}
return V_37 ;
}
static int F_30 ( struct V_44 * V_45 ,
int V_62 ,
struct V_3 * V_4 ,
bool * V_63 , int * V_37 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = F_5 ( V_9 -> V_41 . V_34 ) ;
struct V_64 * V_65 ;
int V_66 = 0 , V_99 ;
* V_37 = 0 ;
F_14 ( & V_45 -> V_62 [ V_62 ] . V_67 ) ;
do {
V_65 = F_15 ( V_45 , & V_45 -> V_62 [ V_62 ] . V_68 ) ;
if ( F_16 ( V_65 ) ) {
F_11 ( V_45 -> V_60 ,
L_4 ) ;
* V_37 = F_17 ( V_65 ) ;
break;
}
if ( V_65 -> V_69 . V_70 ) {
F_11 ( V_45 -> V_60 , L_5 ,
V_65 -> V_69 . V_70 ) ;
* V_37 = - V_71 ;
}
V_66 ++ ;
} while ( ! V_65 -> V_72 );
F_18 ( V_45 , V_62 ) ;
F_19 ( & V_45 -> V_62 [ V_62 ] . V_67 ) ;
if ( V_2 -> V_41 . V_100 ) {
F_31 ( V_45 -> V_101 , V_2 -> V_41 . V_90 ,
V_2 -> V_41 . V_92 ) ;
* V_63 = true ;
return V_66 ;
}
V_62 = F_32 ( V_45 ) ;
V_2 -> V_41 . V_62 = V_62 ;
V_2 -> V_41 . V_42 = false ;
V_2 -> V_41 . V_102 = F_22 ;
F_14 ( & V_45 -> V_62 [ V_62 ] . V_103 ) ;
V_99 = F_33 ( & V_45 -> V_62 [ V_62 ] . V_104 , V_4 ) ;
F_19 ( & V_45 -> V_62 [ V_62 ] . V_103 ) ;
if ( V_99 != - V_105 )
* V_37 = V_99 ;
if ( ! V_45 -> V_62 [ V_62 ] . V_106 )
F_34 ( V_45 , V_62 ) ;
* V_63 = false ;
return V_66 ;
}
static int F_35 ( struct V_3 * V_4 ,
int V_62 , struct V_79 * V_80 ,
int * V_81 , int * V_82 )
{
struct V_8 * V_9 = F_2 ( V_4 ) ;
struct V_1 * V_2 = F_5 ( V_9 -> V_41 . V_34 ) ;
struct V_44 * V_45 = V_2 -> V_45 ;
int V_37 ;
V_2 -> V_41 . V_97 = F_30 ;
V_37 = F_36 ( V_4 , & V_2 -> V_41 , V_45 ,
V_2 -> V_41 . V_92 , V_62 , V_80 ) ;
if ( F_37 ( V_37 ) )
return V_37 ;
* V_81 = 1 ;
* V_82 = 1 ;
return 0 ;
}
static int F_38 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_5 ( V_34 ) ;
struct V_44 * V_45 = V_2 -> V_45 ;
struct V_8 V_9 ;
struct V_107 V_108 = {} ;
int V_62 = V_2 -> V_41 . V_62 ;
memset ( & V_9 , 0 , sizeof( struct V_8 ) ) ;
F_39 ( & V_108 . V_109 ) ;
F_40 ( & V_9 , V_110 ,
V_111 , & V_108 ) ;
F_41 ( & V_9 , F_42 ( V_34 ) ) ;
V_2 = F_5 ( V_9 . V_41 . V_34 ) ;
V_2 -> V_41 . V_100 = true ;
V_2 -> V_41 . V_102 = F_35 ;
F_14 ( & V_45 -> V_62 [ V_62 ] . V_103 ) ;
F_33 ( & V_45 -> V_62 [ V_62 ] . V_104 , & V_9 . V_41 ) ;
F_19 ( & V_45 -> V_62 [ V_62 ] . V_103 ) ;
if ( ! V_45 -> V_62 [ V_62 ] . V_106 )
F_34 ( V_45 , V_62 ) ;
F_43 ( & V_108 . V_109 ) ;
if ( V_108 . error ) {
F_44 ( V_45 -> V_60 ,
L_6 ,
V_108 . error ) ;
return V_108 . error ;
}
return 0 ;
}
static int F_45 ( struct V_8 * V_9 ,
enum V_112 V_113 , T_1 V_13 )
{
struct V_1 * V_2 = F_5 ( V_9 -> V_41 . V_34 ) ;
struct V_44 * V_45 = V_2 -> V_45 ;
int V_37 , V_62 ;
V_2 -> V_47 = V_113 ;
V_2 -> V_13 = V_13 ;
if ( V_2 -> V_41 . V_90 ) {
if ( V_2 -> V_41 . V_42 )
V_2 -> V_41 . V_102 = F_35 ;
} else {
V_2 -> V_41 . V_62 = F_32 ( V_45 ) ;
V_2 -> V_41 . V_102 = F_22 ;
V_2 -> V_41 . V_90 = F_46 ( V_45 -> V_101 ,
F_47 ( V_9 -> V_41 ) ,
& V_2 -> V_41 . V_92 ) ;
if ( ! V_2 -> V_41 . V_90 )
return - V_114 ;
}
V_62 = V_2 -> V_41 . V_62 ;
F_14 ( & V_45 -> V_62 [ V_62 ] . V_103 ) ;
V_37 = F_33 ( & V_45 -> V_62 [ V_62 ] . V_104 , & V_9 -> V_41 ) ;
F_19 ( & V_45 -> V_62 [ V_62 ] . V_103 ) ;
if ( ! V_45 -> V_62 [ V_62 ] . V_106 )
F_34 ( V_45 , V_62 ) ;
return V_37 ;
}
static int F_48 ( struct V_8 * V_9 )
{
return F_45 ( V_9 , V_48 ,
V_115 ) ;
}
static int F_49 ( struct V_8 * V_9 )
{
return F_45 ( V_9 , V_116 ,
V_115 ) ;
}
static int F_50 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_5 ( V_34 ) ;
struct V_117 * V_118 =
F_51 ( V_34 -> V_119 , struct V_117 ,
V_120 . V_121 . V_41 ) ;
V_2 -> V_45 = V_118 -> V_45 ;
return 0 ;
}
static void F_52 ( struct V_33 * V_34 )
{
struct V_1 * V_2 = F_5 ( V_34 ) ;
struct V_44 * V_45 = V_2 -> V_45 ;
int V_37 ;
F_9 ( V_2 -> V_31 , 8 * sizeof( T_1 ) ) ;
if ( ! V_2 -> V_41 . V_90 )
return;
F_9 ( V_2 -> V_41 . V_90 -> V_91 , 8 * sizeof( T_1 ) ) ;
V_37 = F_38 ( V_34 ) ;
if ( V_37 )
F_44 ( V_45 -> V_60 , L_7 , V_37 ) ;
}
static int F_53 ( struct V_8 * V_9 )
{
return F_45 ( V_9 , V_48 ,
V_14 ) ;
}
static int F_54 ( struct V_8 * V_9 )
{
return F_45 ( V_9 , V_116 ,
V_14 ) ;
}
