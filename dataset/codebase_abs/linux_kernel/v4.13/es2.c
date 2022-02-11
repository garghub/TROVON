static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) & V_3 -> V_4 ;
}
static int F_2 ( struct V_1 * V_5 , void * V_6 , T_1 V_7 , T_2 V_8 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
T_2 * V_12 ;
int V_13 ;
V_12 = F_3 ( V_6 , V_7 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
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
V_24 = F_12 ( sizeof( * V_24 ) + V_7 , V_27 ) ;
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
V_24 -> V_32 = F_13 ( V_7 ) ;
F_14 ( V_22 , V_10 , F_5 ( V_10 , 0 ) ,
( unsigned char * ) V_24 , V_26 , V_7 ,
F_8 , V_24 ) ;
V_13 = F_15 ( V_22 , V_27 ) ;
if ( V_13 ) {
F_9 ( V_22 ) ;
F_7 ( V_24 ) ;
}
return V_13 ;
}
static int F_16 ( struct V_2 * V_3 , void * V_6 , T_1 V_7 , T_2 V_8 ,
bool V_33 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
if ( V_33 )
return F_10 ( V_5 , V_6 , V_7 , V_8 ) ;
return F_2 ( V_5 , V_6 , V_7 , V_8 ) ;
}
static int F_17 ( struct V_1 * V_5 ,
struct V_34 * V_35 )
{
struct V_22 * V_22 ;
int V_36 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; ++ V_37 ) {
V_22 = V_35 -> V_22 [ V_37 ] ;
V_36 = F_15 ( V_22 , V_14 ) ;
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
F_18 ( V_22 ) ;
}
return V_36 ;
}
static void F_19 ( struct V_1 * V_5 ,
struct V_34 * V_35 )
{
struct V_22 * V_22 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_38 ; ++ V_37 ) {
V_22 = V_35 -> V_22 [ V_37 ] ;
F_18 ( V_22 ) ;
}
}
static int F_20 ( struct V_1 * V_5 )
{
struct V_22 * V_22 ;
int V_36 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_40 ; ++ V_37 ) {
V_22 = V_5 -> V_41 [ V_37 ] ;
V_36 = F_15 ( V_22 , V_14 ) ;
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
F_18 ( V_22 ) ;
}
return V_36 ;
}
static void F_21 ( struct V_1 * V_5 )
{
struct V_22 * V_22 ;
int V_37 ;
for ( V_37 = 0 ; V_37 < V_40 ; ++ V_37 ) {
V_22 = V_5 -> V_41 [ V_37 ] ;
F_18 ( V_22 ) ;
}
}
static struct V_22 * F_22 ( struct V_1 * V_5 , T_3 V_42 )
{
struct V_22 * V_22 = NULL ;
unsigned long V_43 ;
int V_37 ;
F_23 ( & V_5 -> V_44 , V_43 ) ;
for ( V_37 = 0 ; V_37 < V_45 ; ++ V_37 ) {
if ( V_5 -> V_46 [ V_37 ] == false &&
V_5 -> V_47 [ V_37 ] == false ) {
V_5 -> V_46 [ V_37 ] = true ;
V_22 = V_5 -> V_48 [ V_37 ] ;
break;
}
}
F_24 ( & V_5 -> V_44 , V_43 ) ;
if ( V_22 )
return V_22 ;
F_25 ( & V_5 -> V_11 -> V_20 ,
L_4 ) ;
return F_11 ( 0 , V_42 ) ;
}
static void F_26 ( struct V_1 * V_5 , struct V_22 * V_22 )
{
unsigned long V_43 ;
int V_37 ;
F_23 ( & V_5 -> V_44 , V_43 ) ;
for ( V_37 = 0 ; V_37 < V_45 ; ++ V_37 ) {
if ( V_22 == V_5 -> V_48 [ V_37 ] ) {
V_5 -> V_46 [ V_37 ] = false ;
V_22 = NULL ;
break;
}
}
F_24 ( & V_5 -> V_44 , V_43 ) ;
F_9 ( V_22 ) ;
}
static void
F_27 ( struct V_49 * V_50 , T_1 V_51 )
{
V_50 -> V_52 [ 0 ] = V_51 ;
}
static void F_28 ( struct V_49 * V_50 )
{
V_50 -> V_52 [ 0 ] = 0 ;
}
static T_1 F_29 ( struct V_49 * V_50 )
{
T_1 V_51 = V_50 -> V_52 [ 0 ] ;
F_28 ( V_50 ) ;
return V_51 ;
}
static int F_30 ( struct V_2 * V_3 , T_1 V_51 ,
struct V_53 * V_54 , T_3 V_42 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
T_4 V_55 ;
int V_13 ;
struct V_22 * V_22 ;
unsigned long V_43 ;
if ( ! F_31 ( V_3 , V_51 ) ) {
F_6 ( & V_10 -> V_20 , L_5 , V_51 ) ;
return - V_56 ;
}
V_22 = F_22 ( V_5 , V_42 ) ;
if ( ! V_22 )
return - V_15 ;
F_23 ( & V_5 -> V_44 , V_43 ) ;
V_54 -> V_57 = V_22 ;
F_24 ( & V_5 -> V_44 , V_43 ) ;
F_27 ( V_54 -> V_50 , V_51 ) ;
V_55 = sizeof( * V_54 -> V_50 ) + V_54 -> V_58 ;
F_32 ( V_22 , V_10 ,
F_33 ( V_10 ,
V_5 -> V_59 ) ,
V_54 -> V_60 , V_55 ,
V_61 , V_54 ) ;
V_22 -> V_62 |= V_63 ;
F_34 ( V_54 ) ;
V_13 = F_15 ( V_22 , V_42 ) ;
if ( V_13 ) {
F_6 ( & V_10 -> V_20 , L_6 , V_13 ) ;
F_23 ( & V_5 -> V_44 , V_43 ) ;
V_54 -> V_57 = NULL ;
F_24 ( & V_5 -> V_44 , V_43 ) ;
F_26 ( V_5 , V_22 ) ;
F_28 ( V_54 -> V_50 ) ;
return V_13 ;
}
return 0 ;
}
static void F_35 ( struct V_53 * V_54 )
{
struct V_2 * V_3 = V_54 -> V_64 -> V_65 -> V_3 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_22 * V_22 ;
int V_37 ;
F_36 () ;
F_37 ( & V_5 -> V_44 ) ;
V_22 = V_54 -> V_57 ;
F_38 ( V_22 ) ;
for ( V_37 = 0 ; V_37 < V_45 ; ++ V_37 ) {
if ( V_22 == V_5 -> V_48 [ V_37 ] ) {
V_5 -> V_47 [ V_37 ] = true ;
break;
}
}
F_39 ( & V_5 -> V_44 ) ;
F_18 ( V_22 ) ;
if ( V_37 < V_45 ) {
F_37 ( & V_5 -> V_44 ) ;
V_5 -> V_47 [ V_37 ] = false ;
F_39 ( & V_5 -> V_44 ) ;
}
F_9 ( V_22 ) ;
}
static int F_40 ( struct V_2 * V_3 , int V_51 ,
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
return F_41 ( V_67 , V_69 , V_70 , V_14 ) ;
}
static void F_42 ( struct V_2 * V_3 , T_1 V_51 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
switch ( V_51 ) {
case V_72 :
V_5 -> V_76 = false ;
return;
}
F_43 ( & V_3 -> V_68 , V_51 ) ;
}
static int F_44 ( struct V_2 * V_3 , T_1 V_51 ,
unsigned long V_43 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_9 * V_10 = V_5 -> V_11 ;
struct V_78 * V_6 ;
T_5 V_79 ;
int V_36 ;
V_6 = F_45 ( sizeof( * V_6 ) , V_14 ) ;
if ( ! V_6 )
return - V_15 ;
V_79 = 0 ;
if ( V_43 & V_80 )
V_79 |= V_81 ;
if ( V_43 & V_82 )
V_79 |= V_83 ;
V_6 -> V_43 = F_46 ( V_79 ) ;
F_25 ( & V_3 -> V_20 , L_9 , V_21 ,
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
static int F_47 ( struct V_2 * V_3 , T_1 V_51 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_87 * V_20 = & V_5 -> V_11 -> V_20 ;
struct V_88 V_6 ;
int V_36 ;
V_6 . V_51 = F_13 ( V_51 ) ;
V_36 = F_48 ( V_5 , V_89 , & V_6 , sizeof( V_6 ) ,
NULL , V_90 ) ;
if ( V_36 ) {
F_6 ( V_20 , L_11 ,
V_51 , V_36 ) ;
return V_36 ;
}
return 0 ;
}
static int F_49 ( struct V_2 * V_3 , T_1 V_51 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_87 * V_20 = & V_5 -> V_11 -> V_20 ;
struct V_91 V_6 ;
int V_36 ;
V_6 . V_51 = F_13 ( V_51 ) ;
V_36 = F_48 ( V_5 , V_92 , & V_6 , sizeof( V_6 ) ,
NULL , V_90 ) ;
if ( V_36 ) {
F_6 ( V_20 , L_12 , V_51 , V_36 ) ;
return V_36 ;
}
return 0 ;
}
static int F_50 ( struct V_2 * V_3 , T_1 V_51 ,
T_2 V_93 , unsigned int V_94 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_87 * V_20 = & V_5 -> V_11 -> V_20 ;
struct V_95 V_6 ;
int V_96 ;
int V_36 ;
if ( V_94 > V_97 )
return - V_56 ;
V_6 . V_51 = F_13 ( V_51 ) ;
V_6 . V_94 = F_13 ( V_94 ) ;
V_6 . V_93 = V_93 ;
V_36 = F_48 ( V_5 , V_98 , & V_6 , sizeof( V_6 ) ,
& V_96 , V_90 + V_94 ) ;
if ( V_36 ) {
F_6 ( V_20 , L_13 ,
V_51 , V_36 , V_96 ) ;
return V_36 ;
}
return 0 ;
}
static int F_51 ( struct V_2 * V_3 , T_1 V_51 ,
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
V_6 . V_51 = F_13 ( V_51 ) ;
V_6 . V_99 = F_13 ( V_99 ) ;
V_6 . V_94 = F_13 ( V_94 ) ;
V_36 = F_48 ( V_5 , V_101 , & V_6 , sizeof( V_6 ) ,
& V_96 , V_90 + V_94 ) ;
if ( V_36 ) {
F_6 ( V_20 , L_14 ,
V_51 , V_36 , V_96 ) ;
return V_36 ;
}
return 0 ;
}
static int F_52 ( struct V_2 * V_3 , T_1 V_51 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_87 * V_20 = & V_5 -> V_11 -> V_20 ;
struct V_102 V_6 ;
int V_36 ;
V_6 . V_51 = F_13 ( V_51 ) ;
V_36 = F_48 ( V_5 , V_103 , & V_6 , sizeof( V_6 ) ,
NULL , V_90 ) ;
if ( V_36 ) {
F_6 ( V_20 , L_15 , V_51 , V_36 ) ;
return V_36 ;
}
return 0 ;
}
static int F_53 ( struct V_2 * V_3 , T_1 V_51 )
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
static int F_54 ( struct V_2 * V_3 , T_1 V_51 )
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
static int F_55 ( struct V_22 * V_22 )
{
struct V_87 * V_20 = & V_22 -> V_20 -> V_20 ;
int V_106 = V_22 -> V_106 ;
switch ( V_106 ) {
case 0 :
return 0 ;
case - V_107 :
F_6 ( V_20 , L_18 ,
V_21 , V_22 -> V_108 ) ;
case - V_109 :
case - V_110 :
case - V_111 :
case - V_112 :
case - V_113 :
return V_106 ;
}
F_6 ( V_20 , L_19 , V_21 , V_106 ) ;
return - V_114 ;
}
static void F_56 ( struct V_1 * V_5 )
{
struct V_9 * V_10 ;
struct V_22 * V_22 ;
int V_37 ;
F_57 ( V_5 -> V_115 ) ;
F_58 ( V_5 ) ;
for ( V_37 = 0 ; V_37 < V_45 ; ++ V_37 ) {
V_22 = V_5 -> V_48 [ V_37 ] ;
F_18 ( V_22 ) ;
F_9 ( V_22 ) ;
V_5 -> V_48 [ V_37 ] = NULL ;
V_5 -> V_46 [ V_37 ] = false ;
}
for ( V_37 = 0 ; V_37 < V_40 ; ++ V_37 ) {
F_9 ( V_5 -> V_41 [ V_37 ] ) ;
F_7 ( V_5 -> V_116 [ V_37 ] ) ;
V_5 -> V_116 [ V_37 ] = NULL ;
}
for ( V_37 = 0 ; V_37 < V_38 ; ++ V_37 ) {
F_9 ( V_5 -> V_35 . V_22 [ V_37 ] ) ;
F_7 ( V_5 -> V_35 . V_60 [ V_37 ] ) ;
V_5 -> V_35 . V_60 [ V_37 ] = NULL ;
}
F_59 ( V_5 -> V_3 , V_72 ) ;
F_59 ( V_5 -> V_3 , V_71 ) ;
V_10 = V_5 -> V_11 ;
F_60 ( V_5 -> V_3 ) ;
F_61 ( V_10 ) ;
}
static void F_62 ( struct V_22 * V_22 )
{
struct V_2 * V_3 = V_22 -> V_25 ;
struct V_87 * V_20 = & V_22 -> V_20 -> V_20 ;
struct V_49 * V_50 ;
int V_106 = F_55 ( V_22 ) ;
int V_13 ;
T_1 V_51 ;
if ( V_106 ) {
if ( ( V_106 == - V_114 ) || ( V_106 == - V_113 ) )
goto exit;
if ( V_106 == - V_110 || V_106 == - V_111 )
return;
F_6 ( V_20 , L_20 , V_106 ) ;
return;
}
if ( V_22 -> V_108 < sizeof( * V_50 ) ) {
F_6 ( V_20 , L_21 ) ;
goto exit;
}
V_50 = V_22 -> V_117 ;
V_51 = F_29 ( V_50 ) ;
if ( F_31 ( V_3 , V_51 ) ) {
F_63 ( V_3 , V_51 , V_22 -> V_117 ,
V_22 -> V_108 ) ;
} else {
F_6 ( V_20 , L_22 , V_51 ) ;
}
exit:
V_13 = F_15 ( V_22 , V_27 ) ;
if ( V_13 )
F_6 ( V_20 , L_23 , V_13 ) ;
}
static void V_61 ( struct V_22 * V_22 )
{
struct V_53 * V_54 = V_22 -> V_25 ;
struct V_2 * V_3 = V_54 -> V_64 -> V_65 -> V_3 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_106 = F_55 ( V_22 ) ;
unsigned long V_43 ;
F_28 ( V_54 -> V_50 ) ;
F_23 ( & V_5 -> V_44 , V_43 ) ;
V_54 -> V_57 = NULL ;
F_24 ( & V_5 -> V_44 , V_43 ) ;
F_64 ( V_3 , V_54 , V_106 ) ;
F_26 ( V_5 , V_22 ) ;
}
static struct V_118 * F_65 ( void * V_119 , T_1 V_7 , T_2 type )
{
struct V_118 * V_120 ;
if ( V_7 + sizeof( * V_120 -> V_6 ) > V_121 )
return NULL ;
V_120 = F_45 ( sizeof( * V_120 ) , V_14 ) ;
if ( ! V_120 )
return NULL ;
F_66 ( & V_120 -> V_122 ) ;
V_120 -> V_6 = F_45 ( sizeof( * V_120 -> V_6 ) + V_7 , V_14 ) ;
if ( ! V_120 -> V_6 )
goto V_123;
V_120 -> V_124 = F_45 ( sizeof( * V_120 -> V_124 ) , V_14 ) ;
if ( ! V_120 -> V_124 )
goto V_125;
V_120 -> V_6 -> type = type ;
V_120 -> V_6 -> V_7 = F_13 ( sizeof( * V_120 -> V_6 ) + V_7 ) ;
memcpy ( V_120 -> V_6 -> V_12 , V_119 , V_7 ) ;
F_67 ( & V_120 -> V_126 ) ;
return V_120 ;
V_125:
F_7 ( V_120 -> V_6 ) ;
V_123:
F_7 ( V_120 ) ;
return NULL ;
}
static void F_68 ( struct V_118 * V_120 )
{
F_7 ( V_120 -> V_6 ) ;
F_7 ( V_120 -> V_124 ) ;
F_7 ( V_120 ) ;
}
static struct V_118 * F_69 ( struct V_1 * V_5 , T_6 V_127 )
{
struct V_118 * V_120 ;
F_70 (rpc, &es2->arpcs, list) {
if ( V_120 -> V_6 -> V_127 == V_127 )
return V_120 ;
}
return NULL ;
}
static void F_71 ( struct V_1 * V_5 , struct V_118 * V_120 )
{
V_120 -> V_128 = true ;
V_120 -> V_6 -> V_127 = F_13 ( V_5 -> V_129 ++ ) ;
F_72 ( & V_120 -> V_122 , & V_5 -> V_130 ) ;
}
static void F_73 ( struct V_1 * V_5 , struct V_118 * V_120 )
{
if ( V_120 -> V_128 ) {
V_120 -> V_128 = false ;
F_74 ( & V_120 -> V_122 ) ;
}
}
static int F_75 ( struct V_1 * V_5 , struct V_118 * V_120 , int V_94 )
{
struct V_9 * V_10 = V_5 -> V_11 ;
int V_13 ;
V_13 = F_4 ( V_10 , F_5 ( V_10 , 0 ) ,
V_131 ,
V_16 | V_17 |
V_18 ,
0 , 0 ,
V_120 -> V_6 , F_76 ( V_120 -> V_6 -> V_7 ) ,
V_19 ) ;
if ( V_13 != F_76 ( V_120 -> V_6 -> V_7 ) ) {
F_6 ( & V_10 -> V_20 ,
L_24 ,
V_120 -> V_6 -> type , V_13 ) ;
if ( V_13 > 0 )
V_13 = - V_85 ;
return V_13 ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_5 , T_2 type , void * V_119 ,
T_4 V_7 , int * V_96 , unsigned int V_94 )
{
struct V_118 * V_120 ;
unsigned long V_43 ;
int V_13 ;
if ( V_96 )
* V_96 = 0 ;
V_120 = F_65 ( V_119 , V_7 , type ) ;
if ( ! V_120 )
return - V_15 ;
F_23 ( & V_5 -> V_132 , V_43 ) ;
F_71 ( V_5 , V_120 ) ;
F_24 ( & V_5 -> V_132 , V_43 ) ;
V_13 = F_75 ( V_5 , V_120 , V_94 ) ;
if ( V_13 )
goto V_133;
V_13 = F_77 (
& V_120 -> V_126 ,
F_78 ( V_94 ) ) ;
if ( V_13 <= 0 ) {
if ( ! V_13 )
V_13 = - V_134 ;
goto V_133;
}
if ( V_120 -> V_124 -> V_96 ) {
V_13 = - V_135 ;
if ( V_96 )
* V_96 = V_120 -> V_124 -> V_96 ;
} else {
V_13 = 0 ;
}
V_133:
F_23 ( & V_5 -> V_132 , V_43 ) ;
F_73 ( V_5 , V_120 ) ;
F_24 ( & V_5 -> V_132 , V_43 ) ;
F_68 ( V_120 ) ;
if ( V_13 < 0 && V_13 != - V_135 ) {
F_6 ( & V_5 -> V_11 -> V_20 ,
L_25 , V_13 ) ;
}
return V_13 ;
}
static void F_79 ( struct V_22 * V_22 )
{
struct V_1 * V_5 = V_22 -> V_25 ;
struct V_87 * V_20 = & V_22 -> V_20 -> V_20 ;
int V_106 = F_55 ( V_22 ) ;
struct V_118 * V_120 ;
struct V_136 * V_124 ;
unsigned long V_43 ;
int V_13 ;
if ( V_106 ) {
if ( ( V_106 == - V_114 ) || ( V_106 == - V_113 ) )
goto exit;
if ( V_106 == - V_110 || V_106 == - V_111 )
return;
F_6 ( V_20 , L_26 , V_106 ) ;
return;
}
if ( V_22 -> V_108 < sizeof( * V_124 ) ) {
F_6 ( V_20 , L_27 ) ;
goto exit;
}
V_124 = V_22 -> V_117 ;
F_23 ( & V_5 -> V_132 , V_43 ) ;
V_120 = F_69 ( V_5 , V_124 -> V_127 ) ;
if ( ! V_120 ) {
F_6 ( V_20 , L_28 ,
F_76 ( V_124 -> V_127 ) ) ;
F_24 ( & V_5 -> V_132 , V_43 ) ;
goto exit;
}
F_73 ( V_5 , V_120 ) ;
memcpy ( V_120 -> V_124 , V_124 , sizeof( * V_124 ) ) ;
F_80 ( & V_120 -> V_126 ) ;
F_24 ( & V_5 -> V_132 , V_43 ) ;
exit:
V_13 = F_15 ( V_22 , V_27 ) ;
if ( V_13 )
F_6 ( V_20 , L_29 , V_13 ) ;
}
static void F_81 ( struct V_1 * V_5 , char * V_26 )
{
int V_13 ;
do {
V_13 = F_4 ( V_5 -> V_11 ,
F_82 ( V_5 -> V_11 , 0 ) ,
V_137 ,
V_138 | V_17 |
V_18 ,
0x00 , 0x00 ,
V_26 ,
V_139 ,
V_19 ) ;
if ( V_13 > 0 )
F_83 ( & V_5 -> V_140 , V_26 , V_13 ) ;
} while ( V_13 > 0 );
}
static int F_84 ( void * V_12 )
{
struct V_1 * V_5 = V_12 ;
char * V_26 ;
V_26 = F_12 ( V_139 , V_14 ) ;
if ( ! V_26 )
return - V_15 ;
while ( ! F_85 () ) {
F_86 ( 1000 ) ;
F_81 ( V_5 , V_26 ) ;
}
F_7 ( V_26 ) ;
return 0 ;
}
static T_7 F_87 ( struct V_141 * V_142 , char T_8 * V_26 ,
T_4 V_143 , T_9 * V_144 )
{
struct V_1 * V_5 = F_88 ( V_142 ) -> V_145 ;
T_7 V_36 ;
T_4 V_146 ;
char * V_147 ;
if ( V_143 > V_148 )
V_143 = V_148 ;
V_147 = F_12 ( V_143 , V_14 ) ;
if ( ! V_147 )
return - V_15 ;
V_146 = F_89 ( & V_5 -> V_140 , V_147 , V_143 ) ;
V_36 = F_90 ( V_26 , V_143 , V_144 , V_147 , V_146 ) ;
F_7 ( V_147 ) ;
return V_36 ;
}
static void F_91 ( struct V_1 * V_5 )
{
if ( ! F_92 ( V_5 -> V_149 ) )
return;
V_5 -> V_149 = F_93 ( F_84 , V_5 , L_30 ) ;
if ( F_94 ( V_5 -> V_149 ) )
return;
V_5 -> V_150 = F_95 ( L_30 , 0444 ,
F_96 () , V_5 ,
& V_151 ) ;
}
static void F_58 ( struct V_1 * V_5 )
{
if ( F_92 ( V_5 -> V_149 ) )
return;
F_57 ( V_5 -> V_150 ) ;
V_5 -> V_150 = NULL ;
F_97 ( V_5 -> V_149 ) ;
V_5 -> V_149 = NULL ;
}
static T_7 F_98 ( struct V_141 * V_142 , char T_8 * V_26 ,
T_4 V_143 , T_9 * V_144 )
{
struct V_1 * V_5 = F_88 ( V_142 ) -> V_145 ;
int V_152 = ! F_92 ( V_5 -> V_149 ) ;
char V_147 [ 3 ] ;
sprintf ( V_147 , L_31 , V_152 ) ;
return F_90 ( V_26 , V_143 , V_144 , V_147 , 3 ) ;
}
static T_7 F_99 ( struct V_141 * V_142 , const char T_8 * V_26 ,
T_4 V_143 , T_9 * V_144 )
{
int V_152 ;
T_7 V_13 ;
struct V_1 * V_5 = F_88 ( V_142 ) -> V_145 ;
V_13 = F_100 ( V_26 , V_143 , 10 , & V_152 ) ;
if ( V_13 )
return V_13 ;
if ( V_152 )
F_91 ( V_5 ) ;
else
F_58 ( V_5 ) ;
return V_143 ;
}
static int F_101 ( struct V_9 * V_10 )
{
int V_13 ;
T_6 * V_153 ;
V_153 = F_45 ( sizeof( * V_153 ) , V_14 ) ;
if ( ! V_153 )
return - V_15 ;
V_13 = F_4 ( V_10 , F_82 ( V_10 , 0 ) ,
V_154 ,
V_138 | V_17 |
V_18 , 0 , 0 , V_153 ,
sizeof( * V_153 ) , V_19 ) ;
if ( V_13 != sizeof( * V_153 ) ) {
F_6 ( & V_10 -> V_20 , L_32 ,
V_13 ) ;
if ( V_13 >= 0 )
V_13 = - V_85 ;
goto V_86;
}
V_13 = F_76 ( * V_153 ) ;
if ( V_13 > V_155 ) {
V_13 = V_155 ;
F_102 ( & V_10 -> V_20 , L_33 ) ;
}
V_86:
F_7 ( V_153 ) ;
return V_13 ;
}
static int F_103 ( struct V_156 * V_157 ,
const struct V_158 * V_127 )
{
struct V_1 * V_5 ;
struct V_2 * V_3 ;
struct V_9 * V_10 ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
T_10 V_163 ;
int V_13 ;
int V_37 ;
int V_77 ;
bool V_164 = false ;
bool V_165 = false ;
bool V_166 = false ;
V_10 = F_104 ( F_105 ( V_157 ) ) ;
V_77 = F_101 ( V_10 ) ;
if ( V_77 < 0 ) {
F_61 ( V_10 ) ;
F_6 ( & V_10 -> V_20 , L_32 ,
V_77 ) ;
return V_77 ;
}
V_3 = F_106 ( & V_167 , & V_10 -> V_20 , V_168 ,
V_77 ) ;
if ( F_94 ( V_3 ) ) {
F_61 ( V_10 ) ;
return F_107 ( V_3 ) ;
}
V_5 = F_1 ( V_3 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_169 = V_157 ;
V_5 -> V_11 = V_10 ;
F_108 ( & V_5 -> V_44 ) ;
F_109 ( V_5 -> V_140 ) ;
F_110 ( V_157 , V_5 ) ;
V_13 = F_111 ( V_3 , V_71 ) ;
if ( V_13 )
goto error;
V_13 = F_111 ( V_3 , V_72 ) ;
if ( V_13 )
goto error;
V_160 = V_157 -> V_170 ;
for ( V_37 = 0 ; V_37 < V_160 -> V_171 . V_172 ; ++ V_37 ) {
V_162 = & V_160 -> V_162 [ V_37 ] . V_171 ;
V_163 = V_162 -> V_173 ;
if ( F_112 ( V_162 ) ) {
if ( ! V_165 ) {
V_5 -> V_35 . V_162 = V_163 ;
V_165 = true ;
} else if ( ! V_166 ) {
V_5 -> V_174 = V_163 ;
V_166 = true ;
} else {
F_102 ( & V_10 -> V_20 ,
L_34 ,
V_163 ) ;
}
continue;
}
if ( F_113 ( V_162 ) ) {
if ( ! V_164 ) {
V_5 -> V_59 = V_163 ;
V_164 = true ;
} else {
F_102 ( & V_10 -> V_20 ,
L_35 ,
V_163 ) ;
}
continue;
}
F_102 ( & V_10 -> V_20 ,
L_36 ,
V_163 ) ;
}
if ( ! V_165 || ! V_166 || ! V_164 ) {
F_6 ( & V_10 -> V_20 , L_37 ) ;
V_13 = - V_175 ;
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
V_60 = F_12 ( V_168 , V_14 ) ;
if ( ! V_60 ) {
V_13 = - V_15 ;
goto error;
}
F_32 ( V_22 , V_10 ,
F_114 ( V_10 , V_5 -> V_35 . V_162 ) ,
V_60 , V_168 ,
F_62 , V_3 ) ;
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
V_60 = F_12 ( V_176 , V_14 ) ;
if ( ! V_60 ) {
V_13 = - V_15 ;
goto error;
}
F_32 ( V_22 , V_10 ,
F_114 ( V_10 ,
V_5 -> V_174 ) ,
V_60 , V_176 ,
F_79 , V_5 ) ;
V_5 -> V_116 [ V_37 ] = V_60 ;
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
V_5 -> V_115 = F_95 ( L_38 ,
0644 ,
F_96 () , V_5 ,
& V_177 ) ;
F_66 ( & V_5 -> V_130 ) ;
F_108 ( & V_5 -> V_132 ) ;
V_13 = F_20 ( V_5 ) ;
if ( V_13 )
goto error;
V_13 = F_115 ( V_3 ) ;
if ( V_13 )
goto V_178;
V_13 = F_17 ( V_5 , & V_5 -> V_35 ) ;
if ( V_13 )
goto V_179;
return 0 ;
V_179:
F_116 ( V_3 ) ;
V_178:
F_21 ( V_5 ) ;
error:
F_56 ( V_5 ) ;
return V_13 ;
}
static void F_117 ( struct V_156 * V_157 )
{
struct V_1 * V_5 = F_118 ( V_157 ) ;
F_116 ( V_5 -> V_3 ) ;
F_19 ( V_5 , & V_5 -> V_35 ) ;
F_21 ( V_5 ) ;
F_56 ( V_5 ) ;
}
