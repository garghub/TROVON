static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) & V_3 -> V_4 ;
}
static int F_2 ( struct V_1 * V_5 , void * V_6 , T_1 V_7 , T_2 V_8 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
T_2 * V_12 ;
int V_13 ;
V_12 = F_3 ( V_7 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
memcpy ( V_12 , V_6 , V_7 ) ;
V_13 = F_4 ( V_10 , F_5 ( V_10 , 0 ) ,
V_8 ,
V_16 | V_17 |
V_18 ,
0 , 0 , V_12 , V_7 , V_19 ) ;
if ( V_13 < 0 )
F_6 ( & V_10 -> V_20 , L_1 , V_21 , V_13 ) ;
else
V_13 = 0 ;
F_7 ( V_12 ) ;
return V_13 ;
}
static void F_8 ( struct V_22 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_25 ;
F_7 ( V_24 ) ;
F_9 ( V_22 ) ;
}
static int F_10 ( struct V_1 * V_5 , void * V_6 , T_1 V_7 , T_2 V_8 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_22 * V_22 ;
struct V_23 * V_24 ;
T_2 * V_26 ;
int V_13 ;
V_22 = F_11 ( 0 , V_27 ) ;
if ( ! V_22 )
return - V_15 ;
V_24 = F_3 ( sizeof( * V_24 ) + V_7 , V_27 ) ;
if ( ! V_24 ) {
F_9 ( V_22 ) ;
return - V_15 ;
}
V_26 = ( T_2 * ) V_24 + sizeof( * V_24 ) ;
memcpy ( V_26 , V_6 , V_7 ) ;
V_24 -> V_28 = V_8 ;
V_24 -> V_29 = V_16 | V_17 | V_18 ;
V_24 -> V_30 = 0 ;
V_24 -> V_31 = 0 ;
V_24 -> V_32 = F_12 ( V_7 ) ;
F_13 ( V_22 , V_10 , F_5 ( V_10 , 0 ) ,
( unsigned char * ) V_24 , V_26 , V_7 ,
F_8 , V_24 ) ;
V_13 = F_14 ( V_22 , V_27 ) ;
if ( V_13 ) {
F_9 ( V_22 ) ;
F_7 ( V_24 ) ;
}
return V_13 ;
}
static int F_15 ( struct V_2 * V_3 , void * V_6 , T_1 V_7 , T_2 V_8 ,
bool V_33 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_33 )
return F_10 ( V_5 , V_6 , V_7 , V_8 ) ;
return F_2 ( V_5 , V_6 , V_7 , V_8 ) ;
}
static int F_16 ( struct V_1 * V_5 ,
struct V_34 * V_35 )
{
struct V_22 * V_22 ;
int V_36 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; ++ V_37 ) {
V_22 = V_35 -> V_22 [ V_37 ] ;
V_36 = F_14 ( V_22 , V_14 ) ;
if ( V_36 ) {
F_6 ( & V_5 -> V_11 -> V_20 ,
L_2 , V_36 ) ;
goto V_39;
}
}
return 0 ;
V_39:
for ( -- V_37 ; V_37 >= 0 ; -- V_37 ) {
V_22 = V_35 -> V_22 [ V_37 ] ;
F_17 ( V_22 ) ;
}
return V_36 ;
}
static void F_18 ( struct V_1 * V_5 ,
struct V_34 * V_35 )
{
struct V_22 * V_22 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; ++ V_37 ) {
V_22 = V_35 -> V_22 [ V_37 ] ;
F_17 ( V_22 ) ;
}
}
static int F_19 ( struct V_1 * V_5 )
{
struct V_22 * V_22 ;
int V_36 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_40 ; ++ V_37 ) {
V_22 = V_5 -> V_41 [ V_37 ] ;
V_36 = F_14 ( V_22 , V_14 ) ;
if ( V_36 ) {
F_6 ( & V_5 -> V_11 -> V_20 ,
L_3 , V_36 ) ;
goto V_39;
}
}
return 0 ;
V_39:
for ( -- V_37 ; V_37 >= 0 ; -- V_37 ) {
V_22 = V_5 -> V_41 [ V_37 ] ;
F_17 ( V_22 ) ;
}
return V_36 ;
}
static void F_20 ( struct V_1 * V_5 )
{
struct V_22 * V_22 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_40 ; ++ V_37 ) {
V_22 = V_5 -> V_41 [ V_37 ] ;
F_17 ( V_22 ) ;
}
}
static struct V_22 * F_21 ( struct V_1 * V_5 , T_3 V_42 )
{
struct V_22 * V_22 = NULL ;
unsigned long V_43 ;
int V_37 ;
F_22 ( & V_5 -> V_44 , V_43 ) ;
for ( V_37 = 0 ; V_37 < V_45 ; ++ V_37 ) {
if ( V_5 -> V_46 [ V_37 ] == false &&
V_5 -> V_47 [ V_37 ] == false ) {
V_5 -> V_46 [ V_37 ] = true ;
V_22 = V_5 -> V_48 [ V_37 ] ;
break;
}
}
F_23 ( & V_5 -> V_44 , V_43 ) ;
if ( V_22 )
return V_22 ;
F_24 ( & V_5 -> V_11 -> V_20 ,
L_4 ) ;
return F_11 ( 0 , V_42 ) ;
}
static void F_25 ( struct V_1 * V_5 , struct V_22 * V_22 )
{
unsigned long V_43 ;
int V_37 ;
F_22 ( & V_5 -> V_44 , V_43 ) ;
for ( V_37 = 0 ; V_37 < V_45 ; ++ V_37 ) {
if ( V_22 == V_5 -> V_48 [ V_37 ] ) {
V_5 -> V_46 [ V_37 ] = false ;
V_22 = NULL ;
break;
}
}
F_23 ( & V_5 -> V_44 , V_43 ) ;
F_9 ( V_22 ) ;
}
static void
F_26 ( struct V_49 * V_50 , T_1 V_51 )
{
V_50 -> V_52 [ 0 ] = V_51 ;
}
static void F_27 ( struct V_49 * V_50 )
{
V_50 -> V_52 [ 0 ] = 0 ;
}
static T_1 F_28 ( struct V_49 * V_50 )
{
T_1 V_51 = V_50 -> V_52 [ 0 ] ;
F_27 ( V_50 ) ;
return V_51 ;
}
static int F_29 ( struct V_2 * V_3 , T_1 V_51 ,
struct V_53 * V_54 , T_3 V_42 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
T_4 V_55 ;
int V_13 ;
struct V_22 * V_22 ;
unsigned long V_43 ;
if ( ! F_30 ( V_3 , V_51 ) ) {
F_6 ( & V_10 -> V_20 , L_5 , V_51 ) ;
return - V_56 ;
}
V_22 = F_21 ( V_5 , V_42 ) ;
if ( ! V_22 )
return - V_15 ;
F_22 ( & V_5 -> V_44 , V_43 ) ;
V_54 -> V_57 = V_22 ;
F_23 ( & V_5 -> V_44 , V_43 ) ;
F_26 ( V_54 -> V_50 , V_51 ) ;
V_55 = sizeof( * V_54 -> V_50 ) + V_54 -> V_58 ;
F_31 ( V_22 , V_10 ,
F_32 ( V_10 ,
V_5 -> V_59 ) ,
V_54 -> V_60 , V_55 ,
V_61 , V_54 ) ;
V_22 -> V_62 |= V_63 ;
F_33 ( V_54 ) ;
V_13 = F_14 ( V_22 , V_42 ) ;
if ( V_13 ) {
F_6 ( & V_10 -> V_20 , L_6 , V_13 ) ;
F_22 ( & V_5 -> V_44 , V_43 ) ;
V_54 -> V_57 = NULL ;
F_23 ( & V_5 -> V_44 , V_43 ) ;
F_25 ( V_5 , V_22 ) ;
F_27 ( V_54 -> V_50 ) ;
return V_13 ;
}
return 0 ;
}
static void F_34 ( struct V_53 * V_54 )
{
struct V_2 * V_3 = V_54 -> V_64 -> V_65 -> V_3 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_22 * V_22 ;
int V_37 ;
F_35 () ;
F_36 ( & V_5 -> V_44 ) ;
V_22 = V_54 -> V_57 ;
F_37 ( V_22 ) ;
for ( V_37 = 0 ; V_37 < V_45 ; ++ V_37 ) {
if ( V_22 == V_5 -> V_48 [ V_37 ] ) {
V_5 -> V_47 [ V_37 ] = true ;
break;
}
}
F_38 ( & V_5 -> V_44 ) ;
F_17 ( V_22 ) ;
if ( V_37 < V_45 ) {
F_36 ( & V_5 -> V_44 ) ;
V_5 -> V_47 [ V_37 ] = false ;
F_38 ( & V_5 -> V_44 ) ;
}
F_9 ( V_22 ) ;
}
static int F_39 ( struct V_2 * V_3 , int V_51 ,
unsigned long V_43 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_66 * V_67 = & V_3 -> V_68 ;
int V_69 , V_70 ;
switch ( V_51 ) {
case V_71 :
case V_72 :
F_6 ( & V_3 -> V_20 , L_7 , V_51 ) ;
return - V_73 ;
}
if ( V_43 & V_74 &&
V_43 & V_75 ) {
if ( V_5 -> V_76 ) {
F_6 ( & V_3 -> V_20 , L_8 ) ;
return - V_73 ;
}
V_5 -> V_76 = true ;
return V_72 ;
}
if ( V_51 < 0 ) {
V_69 = 0 ;
V_70 = V_3 -> V_77 ;
} else if ( V_51 < V_3 -> V_77 ) {
V_69 = V_51 ;
V_70 = V_51 + 1 ;
} else {
F_6 ( & V_3 -> V_20 , L_7 , V_51 ) ;
return - V_56 ;
}
return F_40 ( V_67 , V_69 , V_70 , V_14 ) ;
}
static void F_41 ( struct V_2 * V_3 , T_1 V_51 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
switch ( V_51 ) {
case V_72 :
V_5 -> V_76 = false ;
return;
}
F_42 ( & V_3 -> V_68 , V_51 ) ;
}
static int F_43 ( struct V_2 * V_3 , T_1 V_51 ,
unsigned long V_43 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_78 * V_6 ;
T_5 V_79 ;
int V_36 ;
V_6 = F_44 ( sizeof( * V_6 ) , V_14 ) ;
if ( ! V_6 )
return - V_15 ;
V_79 = 0 ;
if ( V_43 & V_80 )
V_79 |= V_81 ;
if ( V_43 & V_82 )
V_79 |= V_83 ;
V_6 -> V_43 = F_45 ( V_79 ) ;
F_24 ( & V_3 -> V_20 , L_9 , V_21 ,
V_51 , V_79 ) ;
V_36 = F_4 ( V_10 , F_5 ( V_10 , 0 ) ,
V_84 ,
V_16 | V_17 |
V_18 , V_51 , 0 ,
V_6 , sizeof( * V_6 ) , V_19 ) ;
if ( V_36 != sizeof( * V_6 ) ) {
F_6 ( & V_10 -> V_20 , L_10 ,
V_51 ) ;
if ( V_36 >= 0 )
V_36 = - V_85 ;
goto V_86;
}
V_36 = 0 ;
V_86:
F_7 ( V_6 ) ;
return V_36 ;
}
static int F_46 ( struct V_2 * V_3 , T_1 V_51 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_87 * V_20 = & V_5 -> V_11 -> V_20 ;
struct V_88 V_6 ;
int V_36 ;
V_6 . V_51 = F_12 ( V_51 ) ;
V_36 = F_47 ( V_5 , V_89 , & V_6 , sizeof( V_6 ) ,
NULL , V_90 ) ;
if ( V_36 ) {
F_6 ( V_20 , L_11 ,
V_51 , V_36 ) ;
return V_36 ;
}
return 0 ;
}
static int F_48 ( struct V_2 * V_3 , T_1 V_51 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_87 * V_20 = & V_5 -> V_11 -> V_20 ;
struct V_91 V_6 ;
int V_36 ;
V_6 . V_51 = F_12 ( V_51 ) ;
V_36 = F_47 ( V_5 , V_92 , & V_6 , sizeof( V_6 ) ,
NULL , V_90 ) ;
if ( V_36 ) {
F_6 ( V_20 , L_12 , V_51 , V_36 ) ;
return V_36 ;
}
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , T_1 V_51 ,
T_2 V_93 , unsigned int V_94 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_87 * V_20 = & V_5 -> V_11 -> V_20 ;
struct V_95 V_6 ;
int V_96 ;
int V_36 ;
if ( V_94 > V_97 )
return - V_56 ;
V_6 . V_51 = F_12 ( V_51 ) ;
V_6 . V_94 = F_12 ( V_94 ) ;
V_6 . V_93 = V_93 ;
V_36 = F_47 ( V_5 , V_98 , & V_6 , sizeof( V_6 ) ,
& V_96 , V_90 + V_94 ) ;
if ( V_36 ) {
F_6 ( V_20 , L_13 ,
V_51 , V_36 , V_96 ) ;
return V_36 ;
}
return 0 ;
}
static int F_50 ( struct V_2 * V_3 , T_1 V_51 ,
T_4 V_99 , unsigned int V_94 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_87 * V_20 = & V_5 -> V_11 -> V_20 ;
struct V_100 V_6 ;
int V_96 ;
int V_36 ;
if ( V_99 > V_97 )
return - V_56 ;
if ( V_94 > V_97 )
return - V_56 ;
V_6 . V_51 = F_12 ( V_51 ) ;
V_6 . V_99 = F_12 ( V_99 ) ;
V_6 . V_94 = F_12 ( V_94 ) ;
V_36 = F_47 ( V_5 , V_101 , & V_6 , sizeof( V_6 ) ,
& V_96 , V_90 + V_94 ) ;
if ( V_36 ) {
F_6 ( V_20 , L_14 ,
V_51 , V_36 , V_96 ) ;
return V_36 ;
}
return 0 ;
}
static int F_51 ( struct V_2 * V_3 , T_1 V_51 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_87 * V_20 = & V_5 -> V_11 -> V_20 ;
struct V_102 V_6 ;
int V_36 ;
V_6 . V_51 = F_12 ( V_51 ) ;
V_36 = F_47 ( V_5 , V_103 , & V_6 , sizeof( V_6 ) ,
NULL , V_90 ) ;
if ( V_36 ) {
F_6 ( V_20 , L_15 , V_51 , V_36 ) ;
return V_36 ;
}
return 0 ;
}
static int F_52 ( struct V_2 * V_3 , T_1 V_51 )
{
int V_13 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
V_13 = F_4 ( V_10 , F_5 ( V_10 , 0 ) ,
V_104 ,
V_16 | V_17 |
V_18 , V_51 , 0 , NULL ,
0 , V_19 ) ;
if ( V_13 < 0 )
F_6 ( & V_10 -> V_20 , L_16 ,
V_51 ) ;
return V_13 ;
}
static int F_53 ( struct V_2 * V_3 , T_1 V_51 )
{
int V_13 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
V_13 = F_4 ( V_10 , F_5 ( V_10 , 0 ) ,
V_105 ,
V_16 | V_17 |
V_18 , V_51 , 0 , NULL ,
0 , V_19 ) ;
if ( V_13 < 0 )
F_6 ( & V_10 -> V_20 , L_17 ,
V_51 ) ;
return V_13 ;
}
static int F_54 ( struct V_2 * V_3 , T_2 V_106 ,
T_6 V_107 , T_5 V_108 , T_5 V_109 )
{
int V_13 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_110 * V_111 ;
V_111 = F_44 ( sizeof( * V_111 ) , V_14 ) ;
if ( ! V_111 )
return - V_15 ;
V_111 -> V_106 = V_106 ;
V_111 -> V_107 = F_55 ( V_107 ) ;
V_111 -> V_108 = F_45 ( V_108 ) ;
V_111 -> V_109 = F_45 ( V_109 ) ;
V_13 = F_4 ( V_10 , F_5 ( V_10 , 0 ) ,
V_112 ,
V_16 | V_17 |
V_18 , 0 , 0 , V_111 ,
sizeof( * V_111 ) , V_19 ) ;
if ( V_13 < 0 )
F_6 ( & V_10 -> V_20 , L_18 , V_13 ) ;
F_7 ( V_111 ) ;
return V_13 ;
}
static int F_56 ( struct V_2 * V_3 )
{
int V_13 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
V_13 = F_4 ( V_10 , F_5 ( V_10 , 0 ) ,
V_113 ,
V_16 | V_17 |
V_18 , 0 , 0 , NULL ,
0 , V_19 ) ;
if ( V_13 < 0 )
F_6 ( & V_10 -> V_20 , L_19 , V_13 ) ;
return V_13 ;
}
static int F_57 ( struct V_2 * V_3 , T_6 * V_107 )
{
int V_13 , V_37 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_114 * V_111 ;
V_111 = F_44 ( sizeof( * V_111 ) , V_14 ) ;
if ( ! V_111 )
return - V_15 ;
for ( V_37 = 0 ; V_37 < V_115 ; V_37 ++ )
V_111 -> V_107 [ V_37 ] = F_55 ( V_107 [ V_37 ] ) ;
V_13 = F_4 ( V_10 , F_5 ( V_10 , 0 ) ,
V_116 ,
V_16 | V_17 |
V_18 , 0 , 0 , V_111 ,
sizeof( * V_111 ) , V_19 ) ;
if ( V_13 < 0 )
F_6 ( & V_10 -> V_20 , L_20 , V_13 ) ;
F_7 ( V_111 ) ;
return V_13 ;
}
static int F_58 ( struct V_2 * V_3 , T_6 * V_107 )
{
int V_13 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
T_7 * V_117 ;
V_117 = F_44 ( sizeof( * V_117 ) , V_14 ) ;
if ( ! V_117 )
return - V_15 ;
V_13 = F_4 ( V_10 , F_59 ( V_10 , 0 ) ,
V_118 ,
V_119 | V_17 |
V_18 , 0 , 0 , V_117 ,
sizeof( * V_117 ) ,
V_19 ) ;
if ( V_13 != sizeof( * V_117 ) ) {
F_6 ( & V_10 -> V_20 , L_21 ,
V_13 ) ;
if ( V_13 >= 0 )
V_13 = - V_85 ;
goto V_86;
}
* V_107 = F_60 ( * V_117 ) ;
V_13 = 0 ;
V_86:
F_7 ( V_117 ) ;
return V_13 ;
}
static int F_61 ( struct V_22 * V_22 )
{
struct V_87 * V_20 = & V_22 -> V_20 -> V_20 ;
int V_120 = V_22 -> V_120 ;
switch ( V_120 ) {
case 0 :
return 0 ;
case - V_121 :
F_6 ( V_20 , L_22 ,
V_21 , V_22 -> V_122 ) ;
case - V_123 :
case - V_124 :
case - V_125 :
case - V_126 :
case - V_127 :
return V_120 ;
}
F_6 ( V_20 , L_23 , V_21 , V_120 ) ;
return - V_128 ;
}
static void F_62 ( struct V_1 * V_5 )
{
struct V_9 * V_10 ;
struct V_22 * V_22 ;
int V_37 ;
F_63 ( V_5 -> V_129 ) ;
F_64 ( V_5 ) ;
for ( V_37 = 0 ; V_37 < V_45 ; ++ V_37 ) {
V_22 = V_5 -> V_48 [ V_37 ] ;
F_17 ( V_22 ) ;
F_9 ( V_22 ) ;
V_5 -> V_48 [ V_37 ] = NULL ;
V_5 -> V_46 [ V_37 ] = false ;
}
for ( V_37 = 0 ; V_37 < V_40 ; ++ V_37 ) {
F_9 ( V_5 -> V_41 [ V_37 ] ) ;
F_7 ( V_5 -> V_130 [ V_37 ] ) ;
V_5 -> V_130 [ V_37 ] = NULL ;
}
for ( V_37 = 0 ; V_37 < V_38 ; ++ V_37 ) {
F_9 ( V_5 -> V_35 . V_22 [ V_37 ] ) ;
F_7 ( V_5 -> V_35 . V_60 [ V_37 ] ) ;
V_5 -> V_35 . V_60 [ V_37 ] = NULL ;
}
F_65 ( V_5 -> V_3 , V_72 ) ;
F_65 ( V_5 -> V_3 , V_71 ) ;
V_10 = V_5 -> V_11 ;
F_66 ( V_5 -> V_3 ) ;
F_67 ( V_10 ) ;
}
static void F_68 ( struct V_22 * V_22 )
{
struct V_2 * V_3 = V_22 -> V_25 ;
struct V_87 * V_20 = & V_22 -> V_20 -> V_20 ;
struct V_49 * V_50 ;
int V_120 = F_61 ( V_22 ) ;
int V_13 ;
T_1 V_51 ;
if ( V_120 ) {
if ( ( V_120 == - V_128 ) || ( V_120 == - V_127 ) )
goto exit;
if ( V_120 == - V_124 || V_120 == - V_125 )
return;
F_6 ( V_20 , L_24 , V_120 ) ;
return;
}
if ( V_22 -> V_122 < sizeof( * V_50 ) ) {
F_6 ( V_20 , L_25 ) ;
goto exit;
}
V_50 = V_22 -> V_131 ;
V_51 = F_28 ( V_50 ) ;
if ( F_30 ( V_3 , V_51 ) ) {
F_69 ( V_3 , V_51 , V_22 -> V_131 ,
V_22 -> V_122 ) ;
} else {
F_6 ( V_20 , L_26 , V_51 ) ;
}
exit:
V_13 = F_14 ( V_22 , V_27 ) ;
if ( V_13 )
F_6 ( V_20 , L_27 , V_13 ) ;
}
static void V_61 ( struct V_22 * V_22 )
{
struct V_53 * V_54 = V_22 -> V_25 ;
struct V_2 * V_3 = V_54 -> V_64 -> V_65 -> V_3 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_120 = F_61 ( V_22 ) ;
unsigned long V_43 ;
F_27 ( V_54 -> V_50 ) ;
F_22 ( & V_5 -> V_44 , V_43 ) ;
V_54 -> V_57 = NULL ;
F_23 ( & V_5 -> V_44 , V_43 ) ;
F_70 ( V_3 , V_54 , V_120 ) ;
F_25 ( V_5 , V_22 ) ;
}
static struct V_132 * F_71 ( void * V_133 , T_1 V_7 , T_2 type )
{
struct V_132 * V_134 ;
if ( V_7 + sizeof( * V_134 -> V_6 ) > V_135 )
return NULL ;
V_134 = F_44 ( sizeof( * V_134 ) , V_14 ) ;
if ( ! V_134 )
return NULL ;
F_72 ( & V_134 -> V_136 ) ;
V_134 -> V_6 = F_44 ( sizeof( * V_134 -> V_6 ) + V_7 , V_14 ) ;
if ( ! V_134 -> V_6 )
goto V_137;
V_134 -> V_138 = F_44 ( sizeof( * V_134 -> V_138 ) , V_14 ) ;
if ( ! V_134 -> V_138 )
goto V_139;
V_134 -> V_6 -> type = type ;
V_134 -> V_6 -> V_7 = F_12 ( sizeof( V_134 -> V_6 ) + V_7 ) ;
memcpy ( V_134 -> V_6 -> V_12 , V_133 , V_7 ) ;
F_73 ( & V_134 -> V_140 ) ;
return V_134 ;
V_139:
F_7 ( V_134 -> V_6 ) ;
V_137:
F_7 ( V_134 ) ;
return NULL ;
}
static void F_74 ( struct V_132 * V_134 )
{
F_7 ( V_134 -> V_6 ) ;
F_7 ( V_134 -> V_138 ) ;
F_7 ( V_134 ) ;
}
static struct V_132 * F_75 ( struct V_1 * V_5 , T_8 V_141 )
{
struct V_132 * V_134 ;
F_76 (rpc, &es2->arpcs, list) {
if ( V_134 -> V_6 -> V_141 == V_141 )
return V_134 ;
}
return NULL ;
}
static void F_77 ( struct V_1 * V_5 , struct V_132 * V_134 )
{
V_134 -> V_142 = true ;
V_134 -> V_6 -> V_141 = F_12 ( V_5 -> V_143 ++ ) ;
F_78 ( & V_134 -> V_136 , & V_5 -> V_144 ) ;
}
static void F_79 ( struct V_1 * V_5 , struct V_132 * V_134 )
{
if ( V_134 -> V_142 ) {
V_134 -> V_142 = false ;
F_80 ( & V_134 -> V_136 ) ;
}
}
static int F_81 ( struct V_1 * V_5 , struct V_132 * V_134 , int V_94 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_13 ;
V_13 = F_4 ( V_10 , F_5 ( V_10 , 0 ) ,
V_145 ,
V_16 | V_17 |
V_18 ,
0 , 0 ,
V_134 -> V_6 , F_82 ( V_134 -> V_6 -> V_7 ) ,
V_19 ) ;
if ( V_13 != F_82 ( V_134 -> V_6 -> V_7 ) ) {
F_6 ( & V_10 -> V_20 ,
L_28 ,
V_134 -> V_6 -> type , V_13 ) ;
if ( V_13 > 0 )
V_13 = - V_85 ;
return V_13 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_5 , T_2 type , void * V_133 ,
T_4 V_7 , int * V_96 , unsigned int V_94 )
{
struct V_132 * V_134 ;
unsigned long V_43 ;
int V_13 ;
if ( V_96 )
* V_96 = 0 ;
V_134 = F_71 ( V_133 , V_7 , type ) ;
if ( ! V_134 )
return - V_15 ;
F_22 ( & V_5 -> V_146 , V_43 ) ;
F_77 ( V_5 , V_134 ) ;
F_23 ( & V_5 -> V_146 , V_43 ) ;
V_13 = F_81 ( V_5 , V_134 , V_94 ) ;
if ( V_13 )
goto V_147;
V_13 = F_83 (
& V_134 -> V_140 ,
F_84 ( V_94 ) ) ;
if ( V_13 <= 0 ) {
if ( ! V_13 )
V_13 = - V_148 ;
goto V_147;
}
if ( V_134 -> V_138 -> V_96 ) {
V_13 = - V_149 ;
if ( V_96 )
* V_96 = V_134 -> V_138 -> V_96 ;
} else {
V_13 = 0 ;
}
V_147:
F_22 ( & V_5 -> V_146 , V_43 ) ;
F_79 ( V_5 , V_134 ) ;
F_23 ( & V_5 -> V_146 , V_43 ) ;
F_74 ( V_134 ) ;
if ( V_13 < 0 && V_13 != - V_149 ) {
F_6 ( & V_5 -> V_11 -> V_20 ,
L_29 , V_13 ) ;
}
return V_13 ;
}
static void F_85 ( struct V_22 * V_22 )
{
struct V_1 * V_5 = V_22 -> V_25 ;
struct V_87 * V_20 = & V_22 -> V_20 -> V_20 ;
int V_120 = F_61 ( V_22 ) ;
struct V_132 * V_134 ;
struct V_150 * V_138 ;
unsigned long V_43 ;
int V_13 ;
if ( V_120 ) {
if ( ( V_120 == - V_128 ) || ( V_120 == - V_127 ) )
goto exit;
if ( V_120 == - V_124 || V_120 == - V_125 )
return;
F_6 ( V_20 , L_30 , V_120 ) ;
return;
}
if ( V_22 -> V_122 < sizeof( * V_138 ) ) {
F_6 ( V_20 , L_31 ) ;
goto exit;
}
V_138 = V_22 -> V_131 ;
F_22 ( & V_5 -> V_146 , V_43 ) ;
V_134 = F_75 ( V_5 , V_138 -> V_141 ) ;
if ( ! V_134 ) {
F_6 ( V_20 , L_32 ,
F_82 ( V_138 -> V_141 ) ) ;
F_23 ( & V_5 -> V_146 , V_43 ) ;
goto exit;
}
F_79 ( V_5 , V_134 ) ;
memcpy ( V_134 -> V_138 , V_138 , sizeof( * V_138 ) ) ;
F_86 ( & V_134 -> V_140 ) ;
F_23 ( & V_5 -> V_146 , V_43 ) ;
exit:
V_13 = F_14 ( V_22 , V_27 ) ;
if ( V_13 )
F_6 ( V_20 , L_33 , V_13 ) ;
}
static void F_87 ( struct V_1 * V_5 , char * V_26 )
{
int V_13 ;
do {
V_13 = F_4 ( V_5 -> V_11 ,
F_59 ( V_5 -> V_11 , 0 ) ,
V_151 ,
V_119 | V_17 | V_18 ,
0x00 , 0x00 ,
V_26 ,
V_152 ,
V_19 ) ;
if ( V_13 > 0 )
F_88 ( & V_5 -> V_153 , V_26 , V_13 ) ;
} while ( V_13 > 0 );
}
static int F_89 ( void * V_12 )
{
struct V_1 * V_5 = V_12 ;
char * V_26 ;
V_26 = F_3 ( V_152 , V_14 ) ;
if ( ! V_26 )
return - V_15 ;
while ( ! F_90 () ) {
F_91 ( 1000 ) ;
F_87 ( V_5 , V_26 ) ;
}
F_7 ( V_26 ) ;
return 0 ;
}
static T_9 F_92 ( struct V_154 * V_155 , char T_10 * V_26 ,
T_4 V_106 , T_11 * V_156 )
{
struct V_1 * V_5 = V_155 -> V_157 -> V_158 ;
T_9 V_36 ;
T_4 V_159 ;
char * V_160 ;
if ( V_106 > V_161 )
V_106 = V_161 ;
V_160 = F_3 ( V_106 , V_14 ) ;
if ( ! V_160 )
return - V_15 ;
V_159 = F_93 ( & V_5 -> V_153 , V_160 , V_106 ) ;
V_36 = F_94 ( V_26 , V_106 , V_156 , V_160 , V_159 ) ;
F_7 ( V_160 ) ;
return V_36 ;
}
static void F_95 ( struct V_1 * V_5 )
{
if ( ! F_96 ( V_5 -> V_162 ) )
return;
V_5 -> V_162 = F_97 ( F_89 , V_5 , L_34 ) ;
if ( F_98 ( V_5 -> V_162 ) )
return;
V_5 -> V_163 = F_99 ( L_34 , V_164 ,
F_100 () , V_5 ,
& V_165 ) ;
}
static void F_64 ( struct V_1 * V_5 )
{
if ( F_96 ( V_5 -> V_162 ) )
return;
F_63 ( V_5 -> V_163 ) ;
V_5 -> V_163 = NULL ;
F_101 ( V_5 -> V_162 ) ;
V_5 -> V_162 = NULL ;
}
static T_9 F_102 ( struct V_154 * V_155 , char T_10 * V_26 ,
T_4 V_106 , T_11 * V_156 )
{
struct V_1 * V_5 = V_155 -> V_157 -> V_158 ;
int V_166 = ! F_96 ( V_5 -> V_162 ) ;
char V_160 [ 3 ] ;
sprintf ( V_160 , L_35 , V_166 ) ;
return F_94 ( V_26 , V_106 , V_156 , V_160 , 3 ) ;
}
static T_9 F_103 ( struct V_154 * V_155 , const char T_10 * V_26 ,
T_4 V_106 , T_11 * V_156 )
{
int V_166 ;
T_9 V_13 ;
struct V_1 * V_5 = V_155 -> V_157 -> V_158 ;
V_13 = F_104 ( V_26 , V_106 , 10 , & V_166 ) ;
if ( V_13 )
return V_13 ;
if ( V_166 )
F_95 ( V_5 ) ;
else
F_64 ( V_5 ) ;
return V_106 ;
}
static int F_105 ( struct V_9 * V_10 )
{
int V_13 ;
T_8 * V_167 ;
V_167 = F_44 ( sizeof( * V_167 ) , V_14 ) ;
if ( ! V_167 )
return - V_15 ;
V_13 = F_4 ( V_10 , F_59 ( V_10 , 0 ) ,
V_168 ,
V_119 | V_17 |
V_18 , 0 , 0 , V_167 ,
sizeof( * V_167 ) , V_19 ) ;
if ( V_13 != sizeof( * V_167 ) ) {
F_6 ( & V_10 -> V_20 , L_36 ,
V_13 ) ;
if ( V_13 >= 0 )
V_13 = - V_85 ;
goto V_86;
}
V_13 = F_82 ( * V_167 ) ;
if ( V_13 > V_169 ) {
V_13 = V_169 ;
F_106 ( & V_10 -> V_20 , L_37 ) ;
}
V_86:
F_7 ( V_167 ) ;
return V_13 ;
}
static int F_107 ( struct V_170 * V_171 ,
const struct V_172 * V_141 )
{
struct V_1 * V_5 ;
struct V_2 * V_3 ;
struct V_9 * V_10 ;
struct V_173 * V_174 ;
struct V_175 * V_176 ;
T_12 V_177 ;
int V_13 ;
int V_37 ;
int V_77 ;
bool V_178 = false ;
bool V_179 = false ;
bool V_180 = false ;
V_10 = F_108 ( F_109 ( V_171 ) ) ;
V_77 = F_105 ( V_10 ) ;
if ( V_77 < 0 ) {
F_67 ( V_10 ) ;
F_6 ( & V_10 -> V_20 , L_36 ,
V_77 ) ;
return V_77 ;
}
V_3 = F_110 ( & V_181 , & V_10 -> V_20 , V_182 ,
V_77 ) ;
if ( F_98 ( V_3 ) ) {
F_67 ( V_10 ) ;
return F_111 ( V_3 ) ;
}
V_5 = F_1 ( V_3 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_183 = V_171 ;
V_5 -> V_11 = V_10 ;
F_112 ( & V_5 -> V_44 ) ;
F_113 ( V_5 -> V_153 ) ;
F_114 ( V_171 , V_5 ) ;
V_13 = F_115 ( V_3 , V_71 ) ;
if ( V_13 )
goto error;
V_13 = F_115 ( V_3 , V_72 ) ;
if ( V_13 )
goto error;
V_174 = V_171 -> V_184 ;
for ( V_37 = 0 ; V_37 < V_174 -> V_185 . V_186 ; ++ V_37 ) {
V_176 = & V_174 -> V_176 [ V_37 ] . V_185 ;
V_177 = V_176 -> V_187 ;
if ( F_116 ( V_176 ) ) {
if ( ! V_179 ) {
V_5 -> V_35 . V_176 = V_177 ;
V_179 = true ;
} else if ( ! V_180 ) {
V_5 -> V_188 = V_177 ;
V_180 = true ;
} else {
F_106 ( & V_10 -> V_20 ,
L_38 ,
V_177 ) ;
}
continue;
}
if ( F_117 ( V_176 ) ) {
if ( ! V_178 ) {
V_5 -> V_59 = V_177 ;
V_178 = true ;
} else {
F_106 ( & V_10 -> V_20 ,
L_39 ,
V_177 ) ;
}
continue;
}
F_106 ( & V_10 -> V_20 ,
L_40 ,
V_177 ) ;
}
if ( ! V_179 || ! V_180 || ! V_178 ) {
F_6 ( & V_10 -> V_20 , L_41 ) ;
V_13 = - V_189 ;
goto error;
}
for ( V_37 = 0 ; V_37 < V_38 ; ++ V_37 ) {
struct V_22 * V_22 ;
T_2 * V_60 ;
V_22 = F_11 ( 0 , V_14 ) ;
if ( ! V_22 ) {
V_13 = - V_15 ;
goto error;
}
V_5 -> V_35 . V_22 [ V_37 ] = V_22 ;
V_60 = F_3 ( V_182 , V_14 ) ;
if ( ! V_60 ) {
V_13 = - V_15 ;
goto error;
}
F_31 ( V_22 , V_10 ,
F_118 ( V_10 , V_5 -> V_35 . V_176 ) ,
V_60 , V_182 ,
F_68 , V_3 ) ;
V_5 -> V_35 . V_60 [ V_37 ] = V_60 ;
}
for ( V_37 = 0 ; V_37 < V_40 ; ++ V_37 ) {
struct V_22 * V_22 ;
T_2 * V_60 ;
V_22 = F_11 ( 0 , V_14 ) ;
if ( ! V_22 ) {
V_13 = - V_15 ;
goto error;
}
V_5 -> V_41 [ V_37 ] = V_22 ;
V_60 = F_3 ( V_190 , V_14 ) ;
if ( ! V_60 ) {
V_13 = - V_15 ;
goto error;
}
F_31 ( V_22 , V_10 ,
F_118 ( V_10 ,
V_5 -> V_188 ) ,
V_60 , V_190 ,
F_85 , V_5 ) ;
V_5 -> V_130 [ V_37 ] = V_60 ;
}
for ( V_37 = 0 ; V_37 < V_45 ; ++ V_37 ) {
struct V_22 * V_22 ;
V_22 = F_11 ( 0 , V_14 ) ;
if ( ! V_22 ) {
V_13 = - V_15 ;
goto error;
}
V_5 -> V_48 [ V_37 ] = V_22 ;
V_5 -> V_46 [ V_37 ] = false ;
}
V_5 -> V_129 = F_99 ( L_42 ,
( V_191 | V_164 ) ,
F_100 () , V_5 ,
& V_192 ) ;
F_72 ( & V_5 -> V_144 ) ;
F_112 ( & V_5 -> V_146 ) ;
V_13 = F_19 ( V_5 ) ;
if ( V_13 )
goto error;
V_13 = F_119 ( V_3 ) ;
if ( V_13 )
goto V_193;
V_13 = F_16 ( V_5 , & V_5 -> V_35 ) ;
if ( V_13 )
goto V_194;
return 0 ;
V_194:
F_120 ( V_3 ) ;
V_193:
F_20 ( V_5 ) ;
error:
F_62 ( V_5 ) ;
return V_13 ;
}
static void F_121 ( struct V_170 * V_171 )
{
struct V_1 * V_5 = F_122 ( V_171 ) ;
F_120 ( V_5 -> V_3 ) ;
F_18 ( V_5 , & V_5 -> V_35 ) ;
F_20 ( V_5 ) ;
F_62 ( V_5 ) ;
}
