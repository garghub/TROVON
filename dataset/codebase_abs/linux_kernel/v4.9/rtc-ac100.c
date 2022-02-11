static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 , div ;
F_3 ( V_5 -> V_7 , V_5 -> V_8 , & V_6 ) ;
if ( V_3 != V_9 ) {
div = ( V_6 >> V_10 ) &
( ( 1 << V_11 ) - 1 ) ;
V_3 = F_4 ( V_2 , V_3 , div ,
V_12 , 0 ) ;
}
div = ( V_6 >> V_13 ) &
( F_5 ( V_14 ) - 1 ) ;
return F_4 ( V_2 , V_3 , div , NULL ,
V_15 ) ;
}
static long F_6 ( struct V_1 * V_2 , unsigned long V_16 ,
unsigned long V_3 )
{
unsigned long V_17 = 0 , V_18 , V_19 ;
int V_20 ;
if ( V_3 == V_9 )
return F_7 ( V_2 , V_16 , & V_3 , NULL ,
V_14 ,
V_15 ) ;
for ( V_20 = 0 ; V_12 [ V_20 ] . div ; V_20 ++ ) {
V_19 = F_8 ( V_3 , V_12 [ V_20 ] . V_21 ) ;
V_18 = F_7 ( V_2 , V_16 , & V_19 , NULL ,
V_14 ,
V_15 ) ;
if ( V_18 > V_16 )
continue;
if ( V_16 - V_18 < V_17 - V_18 )
V_17 = V_18 ;
}
return V_17 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_1 * V_24 ;
unsigned long V_25 = 0 ;
int V_20 , V_26 = F_10 ( V_2 ) ;
for ( V_20 = 0 ; V_20 < V_26 ; V_20 ++ ) {
struct V_1 * V_27 = F_11 ( V_2 , V_20 ) ;
unsigned long V_28 , V_3 = F_12 ( V_27 ) ;
V_28 = F_6 ( V_2 , V_23 -> V_16 , V_3 ) ;
if ( V_28 > V_23 -> V_16 )
continue;
if ( V_23 -> V_16 - V_28 < V_23 -> V_16 - V_25 ) {
V_25 = V_28 ;
V_24 = V_27 ;
}
}
if ( ! V_25 )
return - V_29 ;
V_23 -> V_30 = V_24 ;
V_23 -> V_31 = V_25 ;
V_23 -> V_16 = V_25 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned long V_16 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int div = 0 , V_32 = 0 ;
do {
div = F_14 ( V_16 * V_12 [ V_32 ] . div ,
V_3 , NULL , V_14 ,
V_15 ) ;
if ( div >= 0 )
break;
} while ( V_3 != V_9 &&
V_12 [ ++ V_32 ] . div );
if ( div < 0 )
return div ;
V_32 = V_12 [ V_32 ] . V_21 ;
F_15 ( V_5 -> V_7 , V_5 -> V_8 ,
( ( 1 << V_14 ) - 1 ) << V_13 |
( ( 1 << V_11 ) - 1 ) << V_10 ,
( div - 1 ) << V_13 |
( V_32 - 1 ) << V_10 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_15 ( V_5 -> V_7 , V_5 -> V_8 , V_33 ,
V_33 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_15 ( V_5 -> V_7 , V_5 -> V_8 , V_33 , 0 ) ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
F_3 ( V_5 -> V_7 , V_5 -> V_8 , & V_6 ) ;
return V_6 & V_33 ;
}
static T_1 F_19 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
F_3 ( V_5 -> V_7 , V_5 -> V_8 , & V_6 ) ;
return ( V_6 >> V_34 ) & 0x1 ;
}
static int F_20 ( struct V_1 * V_2 , T_1 V_35 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_15 ( V_5 -> V_7 , V_5 -> V_8 ,
F_5 ( V_34 ) ,
V_35 ? F_5 ( V_34 ) : 0 ) ;
}
static int F_21 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = V_37 -> V_40 -> V_41 ;
const char * V_42 [ 2 ] = { V_43 } ;
int V_20 , V_44 ;
V_37 -> V_45 = F_22 ( V_37 -> V_40 , sizeof( * V_37 -> V_45 ) +
sizeof( * V_37 -> V_45 -> V_46 ) *
V_47 ,
V_48 ) ;
if ( ! V_37 -> V_45 )
return - V_49 ;
V_37 -> V_50 = F_23 ( V_37 -> V_40 ,
V_43 ,
NULL , 0 ,
V_9 ) ;
if ( F_24 ( V_37 -> V_50 ) ) {
V_44 = F_25 ( V_37 -> V_50 ) ;
F_26 ( V_37 -> V_40 , L_1 ,
V_44 ) ;
return V_44 ;
}
V_42 [ 1 ] = F_27 ( V_39 , 0 ) ;
if ( ! V_42 [ 1 ] ) {
F_26 ( V_37 -> V_40 , L_2 ) ;
return - V_29 ;
}
for ( V_20 = 0 ; V_20 < V_47 ; V_20 ++ ) {
struct V_4 * V_5 = & V_37 -> V_51 [ V_20 ] ;
struct V_52 V_53 = {
. V_54 = V_55 [ V_20 ] ,
. V_56 = & V_57 ,
. V_58 = V_42 ,
. V_26 = F_28 ( V_42 ) ,
. V_59 = 0 ,
} ;
F_29 ( V_39 , L_3 ,
V_20 , & V_53 . V_54 ) ;
V_5 -> V_7 = V_37 -> V_7 ;
V_5 -> V_8 = V_60 + V_20 ;
V_5 -> V_2 . V_53 = & V_53 ;
V_44 = F_30 ( V_37 -> V_40 , & V_5 -> V_2 ) ;
if ( V_44 ) {
F_26 ( V_37 -> V_40 , L_4 ,
V_53 . V_54 , V_44 ) ;
goto V_61;
}
V_37 -> V_45 -> V_46 [ V_20 ] = & V_5 -> V_2 ;
}
V_37 -> V_45 -> V_62 = V_20 ;
V_44 = F_31 ( V_39 , V_63 , V_37 -> V_45 ) ;
if ( V_44 )
goto V_61;
return 0 ;
V_61:
F_32 ( V_37 -> V_50 -> V_5 ) ;
return V_44 ;
}
static void F_33 ( struct V_36 * V_37 )
{
F_34 ( V_37 -> V_40 -> V_41 ) ;
F_32 ( V_37 -> V_50 -> V_5 ) ;
}
static int F_35 ( struct V_64 * V_40 , struct V_65 * V_66 )
{
struct V_36 * V_37 = F_36 ( V_40 ) ;
struct V_7 * V_7 = V_37 -> V_7 ;
T_2 V_6 [ 7 ] ;
int V_44 ;
V_44 = F_37 ( V_7 , V_67 , V_6 , 7 ) ;
if ( V_44 )
return V_44 ;
V_66 -> V_68 = F_38 ( V_6 [ 0 ] & V_69 ) ;
V_66 -> V_70 = F_38 ( V_6 [ 1 ] & V_71 ) ;
V_66 -> V_72 = F_38 ( V_6 [ 2 ] & V_73 ) ;
V_66 -> V_74 = F_38 ( V_6 [ 3 ] & V_75 ) ;
V_66 -> V_76 = F_38 ( V_6 [ 4 ] & V_77 ) ;
V_66 -> V_78 = F_38 ( V_6 [ 5 ] & V_79 ) - 1 ;
V_66 -> V_80 = F_38 ( V_6 [ 6 ] & V_81 ) +
V_82 ;
return F_39 ( V_66 ) ;
}
static int F_40 ( struct V_64 * V_40 , struct V_65 * V_66 )
{
struct V_36 * V_37 = F_36 ( V_40 ) ;
struct V_7 * V_7 = V_37 -> V_7 ;
int V_83 ;
T_2 V_6 [ 8 ] ;
V_83 = V_66 -> V_80 - V_82 ;
if ( V_83 < 0 || V_83 > ( V_84 - 1900 ) ) {
F_26 ( V_40 , L_5 ,
V_85 , V_84 ) ;
return - V_29 ;
}
V_6 [ 0 ] = F_41 ( V_66 -> V_68 ) & V_69 ;
V_6 [ 1 ] = F_41 ( V_66 -> V_70 ) & V_71 ;
V_6 [ 2 ] = F_41 ( V_66 -> V_72 ) & V_73 ;
V_6 [ 3 ] = F_41 ( V_66 -> V_74 ) & V_75 ;
V_6 [ 4 ] = F_41 ( V_66 -> V_76 ) & V_77 ;
V_6 [ 5 ] = F_41 ( V_66 -> V_78 + 1 ) & V_79 ;
V_6 [ 6 ] = F_41 ( V_83 ) & V_81 ;
V_6 [ 7 ] = V_86 ;
if ( F_42 ( V_83 + V_82 + 1900 ) )
V_6 [ 6 ] |= V_87 ;
return F_43 ( V_7 , V_67 , V_6 , 8 ) ;
}
static int F_44 ( struct V_64 * V_40 , unsigned int V_88 )
{
struct V_36 * V_37 = F_36 ( V_40 ) ;
struct V_7 * V_7 = V_37 -> V_7 ;
unsigned int V_21 ;
V_21 = V_88 ? V_89 : 0 ;
return F_45 ( V_7 , V_90 , V_21 ) ;
}
static int F_46 ( struct V_64 * V_40 , struct V_91 * V_92 )
{
struct V_36 * V_37 = F_36 ( V_40 ) ;
struct V_7 * V_7 = V_37 -> V_7 ;
struct V_65 * V_93 = & V_92 -> time ;
T_2 V_6 [ 7 ] ;
unsigned int V_21 ;
int V_44 ;
V_44 = F_3 ( V_7 , V_90 , & V_21 ) ;
if ( V_44 )
return V_44 ;
V_92 -> V_94 = ! ! ( V_21 & V_89 ) ;
V_44 = F_37 ( V_7 , V_95 , V_6 , 7 ) ;
if ( V_44 )
return V_44 ;
V_93 -> V_68 = F_38 ( V_6 [ 0 ] & V_96 ) ;
V_93 -> V_70 = F_38 ( V_6 [ 1 ] & V_97 ) ;
V_93 -> V_72 = F_38 ( V_6 [ 2 ] & V_98 ) ;
V_93 -> V_74 = F_38 ( V_6 [ 3 ] & V_99 ) ;
V_93 -> V_76 = F_38 ( V_6 [ 4 ] & V_100 ) ;
V_93 -> V_78 = F_38 ( V_6 [ 5 ] & V_101 ) - 1 ;
V_93 -> V_80 = F_38 ( V_6 [ 6 ] & V_102 ) +
V_82 ;
return 0 ;
}
static int F_47 ( struct V_64 * V_40 , struct V_91 * V_92 )
{
struct V_36 * V_37 = F_36 ( V_40 ) ;
struct V_7 * V_7 = V_37 -> V_7 ;
struct V_65 * V_93 = & V_92 -> time ;
T_2 V_6 [ 8 ] ;
int V_83 ;
int V_44 ;
V_83 = V_93 -> V_80 - V_82 ;
if ( V_83 < 0 || V_83 > ( V_84 - 1900 ) ) {
F_26 ( V_40 , L_6 ,
V_85 , V_84 ) ;
return - V_29 ;
}
V_6 [ 0 ] = ( F_41 ( V_93 -> V_68 ) & V_96 ) |
V_103 ;
V_6 [ 1 ] = ( F_41 ( V_93 -> V_70 ) & V_97 ) |
V_103 ;
V_6 [ 2 ] = ( F_41 ( V_93 -> V_72 ) & V_98 ) |
V_103 ;
V_6 [ 3 ] = F_41 ( V_93 -> V_74 ) & V_99 ;
V_6 [ 4 ] = ( F_41 ( V_93 -> V_76 ) & V_100 ) |
V_103 ;
V_6 [ 5 ] = ( F_41 ( V_93 -> V_78 + 1 ) & V_101 ) |
V_103 ;
V_6 [ 6 ] = ( F_41 ( V_83 ) & V_102 ) |
V_103 ;
V_6 [ 7 ] = V_104 ;
V_44 = F_43 ( V_7 , V_95 , V_6 , 8 ) ;
if ( V_44 )
return V_44 ;
return F_44 ( V_40 , V_92 -> V_94 ) ;
}
static T_3 F_48 ( int V_105 , void * V_106 )
{
struct V_36 * V_37 = V_106 ;
struct V_7 * V_7 = V_37 -> V_7 ;
unsigned int V_21 = 0 ;
int V_44 ;
F_49 ( & V_37 -> V_107 -> V_108 ) ;
V_44 = F_3 ( V_7 , V_109 , & V_21 ) ;
if ( V_44 )
goto V_110;
if ( V_21 & V_89 ) {
F_50 ( V_37 -> V_107 , 1 , V_111 | V_112 ) ;
V_44 = F_45 ( V_7 , V_109 , V_21 ) ;
if ( V_44 )
goto V_110;
V_44 = F_44 ( V_37 -> V_40 , 0 ) ;
if ( V_44 )
goto V_110;
}
V_110:
F_51 ( & V_37 -> V_107 -> V_108 ) ;
return V_113 ;
}
static int F_52 ( struct V_114 * V_115 )
{
struct V_116 * V_117 = F_36 ( V_115 -> V_40 . V_27 ) ;
struct V_36 * V_37 ;
int V_44 ;
V_37 = F_22 ( & V_115 -> V_40 , sizeof( * V_37 ) , V_48 ) ;
if ( ! V_37 )
return - V_49 ;
F_53 ( V_115 , V_37 ) ;
V_37 -> V_40 = & V_115 -> V_40 ;
V_37 -> V_7 = V_117 -> V_7 ;
V_37 -> V_105 = F_54 ( V_115 , 0 ) ;
if ( V_37 -> V_105 < 0 ) {
F_26 ( & V_115 -> V_40 , L_7 ) ;
return V_37 -> V_105 ;
}
V_44 = F_55 ( & V_115 -> V_40 , V_37 -> V_105 , NULL ,
F_48 ,
V_118 | V_119 ,
F_56 ( & V_115 -> V_40 ) , V_37 ) ;
if ( V_44 ) {
F_26 ( & V_115 -> V_40 , L_8 ) ;
return V_44 ;
}
F_57 ( V_37 -> V_7 , V_120 , V_121 ,
V_121 ) ;
F_45 ( V_37 -> V_7 , V_90 , 0 ) ;
F_45 ( V_37 -> V_7 , V_109 , V_89 ) ;
V_37 -> V_107 = F_58 ( & V_115 -> V_40 , L_9 ,
& V_122 , V_123 ) ;
if ( F_24 ( V_37 -> V_107 ) ) {
F_26 ( & V_115 -> V_40 , L_10 ) ;
return F_25 ( V_37 -> V_107 ) ;
}
V_44 = F_21 ( V_37 ) ;
if ( V_44 )
return V_44 ;
F_59 ( & V_115 -> V_40 , L_11 ) ;
return 0 ;
}
static int F_60 ( struct V_114 * V_115 )
{
struct V_36 * V_37 = F_61 ( V_115 ) ;
F_33 ( V_37 ) ;
return 0 ;
}
