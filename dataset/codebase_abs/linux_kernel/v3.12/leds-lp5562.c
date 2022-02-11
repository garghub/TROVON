static inline void F_1 ( void )
{
F_2 ( 200 , 300 ) ;
}
static inline void F_3 ( void )
{
F_2 ( 500 , 600 ) ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_4 [] = {
V_5 ,
V_6 ,
V_7 ,
V_8 ,
} ;
V_2 -> V_3 = V_3 ;
F_5 ( V_2 -> V_9 , V_4 [ V_2 -> V_10 ] , V_3 ) ;
}
static void F_6 ( struct V_11 * V_9 )
{
enum V_12 V_13 = V_9 -> V_14 ;
T_1 V_15 [] = {
[ V_16 ] = V_17 ,
[ V_18 ] = V_19 ,
[ V_20 ] = V_21 ,
} ;
T_1 V_22 [] = {
[ V_16 ] = V_23 ,
[ V_18 ] = V_24 ,
[ V_20 ] = V_25 ,
} ;
F_7 ( V_9 , V_26 , V_15 [ V_13 ] , V_22 [ V_13 ] ) ;
F_1 () ;
}
static void F_8 ( struct V_11 * V_9 )
{
F_5 ( V_9 , V_26 , V_27 ) ;
F_1 () ;
}
static void F_9 ( struct V_11 * V_9 , bool V_28 )
{
int V_29 ;
T_1 V_30 ;
T_1 V_31 ;
if ( ! V_28 ) {
F_5 ( V_9 , V_32 , V_33 ) ;
F_3 () ;
F_8 ( V_9 ) ;
F_5 ( V_9 , V_34 , V_35 ) ;
F_5 ( V_9 , V_26 , V_36 ) ;
F_1 () ;
return;
}
V_29 = F_10 ( V_9 , V_26 , & V_30 ) ;
if ( V_29 )
return;
V_29 = F_10 ( V_9 , V_32 , & V_31 ) ;
if ( V_29 )
return;
if ( F_11 ( V_30 ) ) {
V_30 = ( V_30 & ~ V_17 ) | V_37 ;
V_31 = ( V_31 & ~ V_38 ) | V_37 ;
}
if ( F_12 ( V_30 ) ) {
V_30 = ( V_30 & ~ V_19 ) | V_39 ;
V_31 = ( V_31 & ~ V_40 ) | V_39 ;
}
if ( F_13 ( V_30 ) ) {
V_30 = ( V_30 & ~ V_21 ) | V_41 ;
V_31 = ( V_31 & ~ V_42 ) | V_41 ;
}
F_5 ( V_9 , V_26 , V_30 ) ;
F_1 () ;
F_7 ( V_9 , V_32 , V_43 , V_31 ) ;
F_3 () ;
}
static int F_14 ( struct V_11 * V_9 ,
const T_1 * V_44 , T_2 V_45 )
{
enum V_12 V_13 = V_9 -> V_14 ;
T_1 V_46 [ V_47 ] = { 0 } ;
T_1 V_4 [] = {
[ V_16 ] = V_48 ,
[ V_18 ] = V_49 ,
[ V_20 ] = V_50 ,
} ;
unsigned V_51 ;
char V_52 [ 3 ] ;
int V_53 ;
int V_54 ;
int V_55 = 0 ;
int V_29 ;
int V_56 ;
for ( V_56 = 0 ; V_56 < V_47 ; V_56 ++ )
F_5 ( V_9 , V_4 [ V_13 ] + V_56 , 0 ) ;
V_56 = 0 ;
while ( ( V_55 < V_45 - 1 ) && ( V_56 < V_47 ) ) {
V_29 = sscanf ( V_44 + V_55 , L_1 , V_52 , & V_54 ) ;
if ( V_29 != 1 )
goto V_57;
V_29 = sscanf ( V_52 , L_2 , & V_51 ) ;
if ( V_29 != 1 )
goto V_57;
V_46 [ V_56 ] = ( T_1 ) V_51 ;
V_55 += V_54 ;
V_56 ++ ;
}
if ( V_56 % 2 )
goto V_57;
V_53 = V_56 ;
for ( V_56 = 0 ; V_56 < V_53 ; V_56 ++ )
F_5 ( V_9 , V_4 [ V_13 ] + V_56 , V_46 [ V_56 ] ) ;
return 0 ;
V_57:
F_15 ( & V_9 -> V_58 -> V_59 , L_3 ) ;
return - V_60 ;
}
static void F_16 ( struct V_11 * V_9 )
{
const struct V_61 * V_62 = V_9 -> V_62 ;
if ( V_62 -> V_45 > V_47 ) {
F_15 ( & V_9 -> V_58 -> V_59 , L_4 ,
V_62 -> V_45 ) ;
return;
}
F_6 ( V_9 ) ;
F_14 ( V_9 , V_62 -> V_44 , V_62 -> V_45 ) ;
}
static int F_17 ( struct V_11 * V_9 )
{
int V_29 ;
T_1 V_63 = V_64 ;
V_29 = F_5 ( V_9 , V_26 , V_36 ) ;
if ( V_29 )
return V_29 ;
F_1 () ;
if ( ! F_18 ( V_9 ) )
V_63 |= V_65 ;
V_29 = F_5 ( V_9 , V_66 , V_63 ) ;
if ( V_29 )
return V_29 ;
F_5 ( V_9 , V_67 , 0 ) ;
F_5 ( V_9 , V_68 , 0 ) ;
F_5 ( V_9 , V_69 , 0 ) ;
F_5 ( V_9 , V_70 , 0 ) ;
F_5 ( V_9 , V_34 , V_35 ) ;
return 0 ;
}
static void F_19 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_20 ( V_72 , struct V_1 ,
V_73 ) ;
struct V_11 * V_9 = V_2 -> V_9 ;
T_1 V_4 [] = {
V_67 ,
V_68 ,
V_69 ,
V_70 ,
} ;
F_21 ( & V_9 -> V_74 ) ;
F_5 ( V_9 , V_4 [ V_2 -> V_10 ] , V_2 -> V_75 ) ;
F_22 ( & V_9 -> V_74 ) ;
}
static void F_23 ( struct V_11 * V_9 ,
T_1 V_76 , const T_1 * V_77 , int V_45 )
{
int V_56 ;
if ( ! V_77 || V_45 <= 0 )
return;
for ( V_56 = 0 ; V_56 < V_45 ; V_56 ++ )
F_5 ( V_9 , V_76 + V_56 , * ( V_77 + V_56 ) ) ;
F_5 ( V_9 , V_76 + V_56 , 0 ) ;
F_5 ( V_9 , V_76 + V_56 + 1 , 0 ) ;
}
static inline bool F_24 ( struct V_78 * V_79 )
{
return ( V_79 -> V_80 >= V_47 ||
V_79 -> V_81 >= V_47 ||
V_79 -> V_82 >= V_47 ) ;
}
static int F_25 ( struct V_11 * V_9 , int V_30 )
{
struct V_78 * V_79 ;
int V_56 ;
if ( V_30 == V_83 ) {
F_9 ( V_9 , false ) ;
return 0 ;
}
V_79 = V_9 -> V_84 -> V_85 + ( V_30 - 1 ) ;
if ( ! V_79 || F_24 ( V_79 ) ) {
F_15 ( & V_9 -> V_58 -> V_59 , L_5 ) ;
return - V_60 ;
}
F_8 ( V_9 ) ;
F_5 ( V_9 , V_34 , V_86 ) ;
for ( V_56 = V_16 ; V_56 <= V_20 ; V_56 ++ ) {
V_9 -> V_14 = V_56 ;
F_6 ( V_9 ) ;
}
F_5 ( V_9 , V_48 , 0 ) ;
F_5 ( V_9 , V_48 + 1 , 0 ) ;
F_5 ( V_9 , V_49 , 0 ) ;
F_5 ( V_9 , V_49 + 1 , 0 ) ;
F_5 ( V_9 , V_50 , 0 ) ;
F_5 ( V_9 , V_50 + 1 , 0 ) ;
F_23 ( V_9 , V_48 ,
V_79 -> V_87 , V_79 -> V_80 ) ;
F_23 ( V_9 , V_49 ,
V_79 -> V_88 , V_79 -> V_81 ) ;
F_23 ( V_9 , V_50 ,
V_79 -> V_89 , V_79 -> V_82 ) ;
F_9 ( V_9 , true ) ;
return 0 ;
}
static T_3 F_26 ( struct V_90 * V_59 ,
struct V_91 * V_92 ,
const char * V_93 , T_2 V_94 )
{
struct V_1 * V_2 = F_27 ( F_28 ( V_59 ) ) ;
struct V_11 * V_9 = V_2 -> V_9 ;
struct V_78 * V_79 = V_9 -> V_84 -> V_85 ;
int V_95 = V_9 -> V_84 -> V_95 ;
unsigned long V_30 ;
int V_29 ;
V_29 = F_29 ( V_93 , 0 , & V_30 ) ;
if ( V_29 )
return V_29 ;
if ( V_30 > V_95 || ! V_79 )
return - V_60 ;
F_21 ( & V_9 -> V_74 ) ;
V_29 = F_25 ( V_9 , V_30 ) ;
F_22 ( & V_9 -> V_74 ) ;
if ( V_29 )
return V_29 ;
return V_94 ;
}
static T_3 F_30 ( struct V_90 * V_59 ,
struct V_91 * V_92 ,
const char * V_93 , T_2 V_94 )
{
struct V_1 * V_2 = F_27 ( F_28 ( V_59 ) ) ;
struct V_11 * V_9 = V_2 -> V_9 ;
T_1 V_15 ;
T_1 V_22 ;
if ( F_31 ( V_93 , L_6 ) ) {
V_15 = V_96 ;
V_22 = V_86 ;
} else if ( F_31 ( V_93 , L_7 ) ) {
enum V_12 V_13 = V_9 -> V_14 ;
V_15 = V_97 ;
switch ( V_13 ) {
case V_16 :
V_22 = V_98 ;
break;
case V_18 :
V_22 = V_99 ;
break;
case V_20 :
V_22 = V_100 ;
break;
default:
return - V_60 ;
}
} else {
F_15 ( V_59 , L_8 ) ;
return - V_60 ;
}
F_21 ( & V_9 -> V_74 ) ;
F_7 ( V_9 , V_34 , V_15 , V_22 ) ;
F_22 ( & V_9 -> V_74 ) ;
return V_94 ;
}
static int F_32 ( struct V_101 * V_102 ,
const struct V_103 * V_104 )
{
int V_29 ;
struct V_11 * V_9 ;
struct V_1 * V_2 ;
struct V_105 * V_84 ;
struct V_106 * V_107 = V_102 -> V_59 . V_108 ;
if ( ! F_33 ( & V_102 -> V_59 ) ) {
if ( V_107 ) {
V_29 = F_34 ( & V_102 -> V_59 , V_107 ) ;
if ( V_29 < 0 )
return V_29 ;
} else {
F_15 ( & V_102 -> V_59 , L_9 ) ;
return - V_60 ;
}
}
V_84 = F_33 ( & V_102 -> V_59 ) ;
V_9 = F_35 ( & V_102 -> V_59 , sizeof( * V_9 ) , V_109 ) ;
if ( ! V_9 )
return - V_110 ;
V_2 = F_35 ( & V_102 -> V_59 ,
sizeof( * V_2 ) * V_84 -> V_111 , V_109 ) ;
if ( ! V_2 )
return - V_110 ;
V_9 -> V_58 = V_102 ;
V_9 -> V_84 = V_84 ;
V_9 -> V_63 = & V_112 ;
F_36 ( & V_9 -> V_74 ) ;
F_37 ( V_102 , V_2 ) ;
V_29 = F_38 ( V_9 ) ;
if ( V_29 )
goto V_113;
V_29 = F_39 ( V_2 , V_9 ) ;
if ( V_29 )
goto V_114;
V_29 = F_40 ( V_9 ) ;
if ( V_29 ) {
F_15 ( & V_102 -> V_59 , L_10 ) ;
goto V_115;
}
return 0 ;
V_115:
F_41 ( V_2 , V_9 ) ;
V_114:
F_42 ( V_9 ) ;
V_113:
return V_29 ;
}
static int F_43 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_27 ( V_102 ) ;
struct V_11 * V_9 = V_2 -> V_9 ;
F_8 ( V_9 ) ;
F_44 ( V_9 ) ;
F_41 ( V_2 , V_9 ) ;
F_42 ( V_9 ) ;
return 0 ;
}
