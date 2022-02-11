static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 = - V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ ) {
if ( V_7 [ V_6 ] [ 0 ] == V_3 ) {
F_3 ( & V_2 -> V_8 ) ;
V_4 = F_4 ( V_2 -> V_9 , V_10 ,
V_7 [ V_6 ] [ 1 ] ) ;
if ( ! V_4 )
V_2 -> V_11 = V_3 ;
F_5 ( & V_2 -> V_8 ) ;
break;
}
}
return V_4 ;
}
static int F_6 ( struct V_1 * V_2 , int V_12 )
{
int V_4 = - V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_13 ) ; V_6 ++ ) {
if ( V_13 [ V_6 ] == V_12 ) {
F_3 ( & V_2 -> V_8 ) ;
V_4 = F_7 ( V_2 -> V_9 ,
V_14 ,
V_15 ,
V_6 << V_16 ) ;
if ( V_4 ) {
F_5 ( & V_2 -> V_8 ) ;
break;
}
V_4 = F_7 ( V_2 -> V_9 ,
V_17 ,
V_18 ,
V_6 << V_19 ) ;
if ( ! V_4 )
V_2 -> V_20 = V_6 ;
F_5 ( & V_2 -> V_8 ) ;
break;
}
}
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 , int V_12 )
{
int V_4 = - V_5 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_21 ) ; V_6 ++ ) {
if ( V_21 [ V_6 ] == V_12 ) {
F_3 ( & V_2 -> V_8 ) ;
V_4 = F_7 ( V_2 -> V_9 ,
V_14 ,
V_22 , V_6 ) ;
if ( ! V_4 )
V_2 -> V_23 = V_6 ;
F_5 ( & V_2 -> V_8 ) ;
break;
}
}
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 , bool V_24 )
{
struct V_25 * V_26 = & V_2 -> V_27 -> V_26 ;
int V_4 = 0 ;
F_3 ( & V_2 -> V_8 ) ;
if ( V_24 ) {
int V_28 ;
V_28 = F_10 ( V_26 ) ;
V_4 = F_11 ( V_26 ) ;
if ( V_28 )
F_12 ( V_2 -> V_11 ,
V_29 ) ;
} else {
F_13 ( V_26 ) ;
V_4 = F_14 ( V_26 ) ;
}
F_5 ( & V_2 -> V_8 ) ;
return V_4 ;
}
static int F_9 ( struct V_1 * V_2 , bool V_24 )
{
return 0 ;
}
static int F_15 ( struct V_30 * V_31 ,
struct V_32 const * V_33 ,
int * V_12 , int * V_3 , long V_34 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
T_1 V_35 ;
int V_4 = - V_5 ;
if ( V_2 -> V_36 )
return - V_37 ;
switch ( V_34 ) {
case V_38 :
F_9 ( V_2 , true ) ;
switch ( V_33 -> type ) {
case V_39 :
V_4 = F_17 ( V_2 -> V_9 , V_33 -> V_40 , V_12 ) ;
if ( ! V_4 )
V_4 = V_41 ;
break;
case V_42 :
V_4 = F_18 ( V_2 -> V_9 , V_33 -> V_40 ,
& V_35 , 2 ) ;
if ( ! V_4 ) {
V_4 = V_41 ;
* V_12 = F_19 ( V_35 ) ;
}
break;
default:
V_4 = - V_5 ;
}
F_9 ( V_2 , false ) ;
break;
case V_43 :
F_3 ( & V_2 -> V_8 ) ;
switch ( V_33 -> type ) {
case V_42 :
* V_12 = 0 ;
* V_3 = V_2 -> V_11 ;
V_4 = V_44 ;
break;
default:
V_4 = - V_5 ;
}
F_5 ( & V_2 -> V_8 ) ;
break;
case V_45 :
F_3 ( & V_2 -> V_8 ) ;
switch ( V_33 -> type ) {
case V_39 :
* V_12 = V_13 [ V_2 -> V_20 ] ;
V_4 = V_41 ;
break;
case V_42 :
* V_12 = V_21 [ V_2 -> V_23 ] ;
V_4 = V_41 ;
break;
default:
V_4 = - V_5 ;
}
F_5 ( & V_2 -> V_8 ) ;
break;
}
return V_4 ;
}
static int F_20 ( struct V_30 * V_31 ,
struct V_32 const * V_33 ,
int V_12 , int V_3 , long V_34 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
switch ( V_34 ) {
case V_43 :
switch ( V_33 -> type ) {
case V_42 :
if ( V_12 != 0 )
return - V_5 ;
return F_1 ( V_2 , V_3 ) ;
default:
return - V_5 ;
}
case V_45 :
if ( V_3 != 0 )
return - V_5 ;
switch ( V_33 -> type ) {
case V_39 :
return F_6 ( V_2 , V_12 ) ;
case V_42 :
return F_8 ( V_2 , V_12 ) ;
default:
return - V_5 ;
}
default:
return - V_5 ;
} ;
return 0 ;
}
static inline int F_21 ( const struct V_32 * V_33 ,
enum V_46 V_47 ,
T_2 * V_48 )
{
switch ( V_47 ) {
case V_49 :
switch ( V_33 -> type ) {
case V_39 :
* V_48 = V_50 ;
break;
case V_42 :
* V_48 = V_51 ;
break;
default:
return - V_5 ;
}
break;
case V_52 :
switch ( V_33 -> type ) {
case V_39 :
* V_48 = V_53 ;
break;
case V_42 :
* V_48 = V_54 ;
break;
default:
return - V_5 ;
}
break;
default:
return - V_5 ;
}
return 0 ;
}
static int F_22 ( struct V_30 * V_31 ,
const struct V_32 * V_33 ,
enum V_55 type ,
enum V_46 V_47 ,
enum V_56 V_57 ,
int * V_12 , int * V_3 )
{
T_2 V_48 ;
T_1 V_35 ;
int V_4 = 0 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
if ( V_57 != V_58 )
return - V_5 ;
V_4 = F_21 ( V_33 , V_47 , & V_48 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_33 -> type == V_39 ) {
V_4 = F_17 ( V_2 -> V_9 , V_48 , V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
} else if ( V_33 -> type == V_42 ) {
V_4 = F_18 ( V_2 -> V_9 , V_48 , & V_35 , 2 ) ;
if ( V_4 < 0 )
return V_4 ;
* V_12 = F_19 ( V_35 ) ;
} else
return - V_5 ;
* V_3 = 0 ;
return V_41 ;
}
static int F_23 ( struct V_30 * V_31 ,
const struct V_32 * V_33 ,
enum V_55 type ,
enum V_46 V_47 ,
enum V_56 V_57 ,
int V_12 , int V_3 )
{
T_2 V_48 ;
T_1 V_35 ;
int V_4 = 0 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
if ( V_57 != V_58 )
return - V_5 ;
V_4 = F_21 ( V_33 , V_47 , & V_48 ) ;
if ( V_4 < 0 )
return V_4 ;
if ( V_33 -> type == V_39 ) {
if ( V_12 < 0 || V_12 > V_59 )
return - V_5 ;
V_4 = F_4 ( V_2 -> V_9 , V_48 , V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
} else if ( V_33 -> type == V_42 ) {
if ( V_12 < 0 || V_12 > V_60 )
return - V_5 ;
V_35 = F_24 ( V_12 ) ;
V_4 = F_25 ( V_2 -> V_9 , V_48 , & V_35 , 2 ) ;
if ( V_4 < 0 )
return V_4 ;
} else
return - V_5 ;
return 0 ;
}
static int F_26 ( struct V_30 * V_31 ,
const struct V_32 * V_33 ,
enum V_55 type ,
enum V_46 V_47 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
switch ( V_33 -> type ) {
case V_39 :
return V_2 -> V_61 ;
case V_42 :
return V_2 -> V_62 ;
default:
return - V_5 ;
}
return 0 ;
}
static int F_27 ( struct V_30 * V_31 ,
const struct V_32 * V_33 ,
enum V_55 type ,
enum V_46 V_47 ,
int V_63 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_4 ;
V_63 = ! ! V_63 ;
switch ( V_33 -> type ) {
case V_39 :
if ( V_2 -> V_61 == V_63 )
return - V_5 ;
V_4 = F_28 ( V_2 -> V_64 , V_63 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_61 = V_63 ;
F_9 ( V_2 , V_63 ) ;
break;
case V_42 :
if ( V_2 -> V_62 == V_63 )
return - V_5 ;
V_4 = F_28 ( V_2 -> V_65 , V_63 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_62 = V_63 ;
F_9 ( V_2 , V_63 ) ;
break;
default:
return - V_5 ;
}
return 0 ;
}
static inline int F_29 ( struct V_1 * V_2 )
{
int V_66 ;
int V_4 ;
V_4 = F_17 ( V_2 -> V_9 , V_67 , & V_66 ) ;
if ( V_4 )
return V_4 ;
return V_66 ;
}
static void F_30 ( struct V_1 * V_2 )
{
int V_4 , V_66 = 0 ;
F_3 ( & V_2 -> V_8 ) ;
V_2 -> V_36 = 1 ;
while ( V_66 || ( V_66 = F_29 ( V_2 ) > 0 ) ) {
V_4 = F_18 ( V_2 -> V_9 , V_68 ,
& V_2 -> V_69 , 4 ) ;
if ( V_4 )
goto V_70;
F_31 ( V_2 -> V_31 , V_2 -> V_69 ) ;
V_66 -- ;
}
V_70:
V_2 -> V_36 = 0 ;
F_5 ( & V_2 -> V_8 ) ;
}
static T_3 F_32 ( int V_71 , void * V_72 )
{
struct V_30 * V_31 = V_72 ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_4 , V_73 ;
V_4 = F_17 ( V_2 -> V_9 , V_74 , & V_73 ) ;
if ( V_4 < 0 ) {
F_33 ( & V_2 -> V_27 -> V_26 , L_1 ) ;
return V_75 ;
}
if ( ( V_73 & V_76 ) && V_2 -> V_62 ) {
F_34 ( V_31 ,
F_35 ( V_42 , 0 ,
V_77 ,
V_78 ) ,
F_36 () ) ;
F_4 ( V_2 -> V_9 , V_79 , 1 ) ;
}
if ( ( V_73 & V_80 ) && V_2 -> V_61 ) {
F_34 ( V_31 ,
F_35 ( V_39 , 0 ,
V_77 ,
V_78 ) ,
F_36 () ) ;
F_4 ( V_2 -> V_9 , V_81 , 1 ) ;
}
if ( V_73 & V_82 )
F_30 ( V_2 ) ;
return V_75 ;
}
static int F_37 ( struct V_1 * V_2 , bool V_63 )
{
return F_7 ( V_2 -> V_9 , V_83 , 1 , V_63 ) ;
}
static int F_38 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_4 ;
V_4 = F_28 ( V_2 -> V_84 , 1 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_28 ( V_2 -> V_85 , 1 ) ;
if ( V_4 )
return V_4 ;
F_11 ( & V_2 -> V_27 -> V_26 ) ;
return 0 ;
}
static int F_39 ( struct V_30 * V_31 )
{
struct V_1 * V_2 = F_16 ( V_31 ) ;
int V_4 ;
V_4 = F_28 ( V_2 -> V_85 , 0 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_28 ( V_2 -> V_84 , 0 ) ;
if ( V_4 )
return V_4 ;
F_14 ( & V_2 -> V_27 -> V_26 ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_27 -> V_26 ;
struct V_9 * V_9 = V_2 -> V_9 ;
V_2 -> V_65 = F_41 ( V_26 , V_9 ,
V_86 ) ;
if ( F_42 ( V_2 -> V_65 ) ) {
F_33 ( V_26 , L_2 ) ;
return F_43 ( V_2 -> V_65 ) ;
}
V_2 -> V_84 = F_41 ( V_26 , V_9 ,
V_87 ) ;
if ( F_42 ( V_2 -> V_84 ) ) {
F_33 ( V_26 , L_3 ) ;
return F_43 ( V_2 -> V_84 ) ;
}
V_2 -> V_64 = F_41 ( V_26 , V_9 ,
V_88 ) ;
if ( F_42 ( V_2 -> V_64 ) ) {
F_33 ( V_26 , L_4 ) ;
return F_43 ( V_2 -> V_64 ) ;
}
V_2 -> V_89 = F_41 ( V_26 , V_9 ,
V_90 ) ;
if ( F_42 ( V_2 -> V_89 ) ) {
F_33 ( V_26 , L_5 ) ;
return F_43 ( V_2 -> V_89 ) ;
}
V_2 -> V_85 = F_41 ( V_26 , V_9 ,
V_91 ) ;
if ( F_42 ( V_2 -> V_85 ) ) {
F_33 ( V_26 , L_6 ) ;
return F_43 ( V_2 -> V_85 ) ;
}
V_2 -> V_92 = F_41 ( V_26 , V_9 ,
V_93 ) ;
if ( F_42 ( V_2 -> V_92 ) ) {
F_33 ( V_26 , L_7 ) ;
return F_43 ( V_2 -> V_92 ) ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_4 ;
V_4 = F_1 ( V_2 , 28000 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_28 ( V_2 -> V_84 , 0 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_28 ( V_2 -> V_85 , 0 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_28 ( V_2 -> V_64 , 0 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_28 ( V_2 -> V_92 , 1 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_28 ( V_2 -> V_65 , 0 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_28 ( V_2 -> V_89 , 1 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_4 ( V_2 -> V_9 , V_94 ,
V_95 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_7 ( V_2 -> V_9 , V_96 ,
V_97 ,
F_45 ( 0 ) << V_98 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_4 ( V_2 -> V_9 , V_99 ,
V_100 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_4 ( V_2 -> V_9 , V_101 ,
V_102 ) ;
if ( V_4 )
return V_4 ;
return F_37 ( V_2 , 1 ) ;
}
static int F_46 ( struct V_103 * V_27 ,
const struct V_104 * V_105 )
{
struct V_1 * V_2 ;
struct V_106 * V_69 ;
struct V_30 * V_31 ;
int V_4 ;
V_31 = F_47 ( & V_27 -> V_26 , sizeof( * V_2 ) ) ;
if ( ! V_31 )
return - V_107 ;
V_69 = F_48 ( & V_27 -> V_26 ) ;
if ( ! V_69 )
return - V_107 ;
F_49 ( V_31 , V_69 ) ;
V_31 -> V_26 . V_108 = & V_27 -> V_26 ;
V_31 -> V_57 = & V_109 ;
V_31 -> V_110 = V_111 ;
V_31 -> V_112 = V_113 ;
V_31 -> V_114 = F_2 ( V_113 ) ;
V_31 -> V_115 = V_116 ;
V_31 -> V_117 = ( V_118 | V_119 ) ;
V_31 -> V_120 = & V_121 ;
V_2 = F_16 ( V_31 ) ;
F_50 ( V_27 , V_31 ) ;
V_2 -> V_9 = F_51 ( V_27 , & V_122 ) ;
if ( F_42 ( V_2 -> V_9 ) ) {
F_33 ( & V_27 -> V_26 , L_8 ) ;
return F_43 ( V_2 -> V_9 ) ;
}
V_2 -> V_27 = V_27 ;
V_2 -> V_31 = V_31 ;
F_52 ( & V_2 -> V_8 ) ;
V_4 = F_53 ( & V_27 -> V_26 ) ;
if ( V_4 )
goto V_123;
F_54 ( & V_27 -> V_26 ) ;
F_55 ( & V_27 -> V_26 , 5000 ) ;
F_56 ( & V_27 -> V_26 ) ;
F_9 ( V_2 , true ) ;
V_4 = F_40 ( V_2 ) ;
if ( V_4 )
goto V_123;
V_4 = F_44 ( V_2 ) ;
if ( V_4 )
goto V_123;
if ( V_27 -> V_71 <= 0 ) {
F_33 ( & V_27 -> V_26 , L_9 ) ;
V_4 = - V_5 ;
goto V_123;
}
V_4 = F_57 ( & V_27 -> V_26 , V_27 -> V_71 ,
NULL , F_32 ,
V_124 | V_125 ,
L_10 ,
V_31 ) ;
if ( V_4 ) {
F_33 ( & V_27 -> V_26 , L_11 , V_27 -> V_71 ) ;
goto V_123;
}
V_4 = F_58 ( V_31 ) ;
if ( V_4 )
goto V_123;
F_9 ( V_2 , false ) ;
return 0 ;
V_123:
F_9 ( V_2 , false ) ;
return V_4 ;
}
static int F_59 ( struct V_103 * V_27 )
{
struct V_30 * V_31 = F_60 ( V_27 ) ;
struct V_1 * V_2 = F_16 ( V_31 ) ;
F_61 ( V_31 ) ;
F_62 ( & V_27 -> V_26 ) ;
F_63 ( & V_27 -> V_26 ) ;
F_37 ( V_2 , 0 ) ;
return 0 ;
}
static int F_64 ( struct V_25 * V_26 )
{
struct V_1 * V_2 =
F_16 ( F_60 ( F_65 ( V_26 ) ) ) ;
return F_37 ( V_2 , 0 ) ;
}
static int F_66 ( struct V_25 * V_26 )
{
struct V_1 * V_2 =
F_16 ( F_60 ( F_65 ( V_26 ) ) ) ;
return F_37 ( V_2 , 1 ) ;
}
