static int F_1 ( void * V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
void T_1 * V_4 = ( void T_1 * ) V_1 ;
F_2 ( V_3 , V_4 + V_2 ) ;
return 0 ;
}
static int F_3 ( void * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
void T_1 * V_4 = ( void T_1 * ) V_1 ;
* V_3 = F_4 ( V_4 + V_2 ) ;
return 0 ;
}
static void F_5 ( struct V_5 * V_5 , bool V_3 )
{
F_6 ( V_5 , V_6 ,
V_7 ,
V_3 ? V_7 : 0 ) ;
}
static void F_7 ( struct V_5 * V_5 , int V_3 )
{
F_6 ( V_5 , V_6 ,
V_8 ,
V_3 ? V_8 : 0 ) ;
}
static void F_8 ( struct V_5 * V_5 , T_2 type ,
T_2 V_9 , T_2 V_10 , T_2 V_11 )
{
T_3 V_12 = ( ( V_9 << V_13 [ type ] . V_14 ) |
( V_10 << V_13 [ type ] . V_15 ) |
( V_11 << V_13 [ type ] . V_16 ) ) ;
F_6 ( V_5 , V_13 [ type ] . V_17 ,
V_13 [ type ] . V_18 , V_12 ) ;
}
static void F_9 ( struct V_5 * V_5 , T_2 V_19 ,
bool V_20 )
{
F_6 ( V_5 , V_21 [ V_19 ] . V_22 ,
V_21 [ V_19 ] . V_23 ,
V_20 ? V_21 [ V_19 ] . V_23 : 0 ) ;
}
static void F_10 ( struct V_5 * V_5 ,
T_2 V_19 , T_2 type )
{
T_3 V_12 = ( type & 0x1 ) << V_21 [ V_19 ] . V_24 ;
V_12 |= ( type & 0x2 ) << V_21 [ V_19 ] . V_25 ;
F_6 ( V_5 , V_21 [ V_19 ] . V_22 ,
V_21 [ V_19 ] . V_26 , V_12 ) ;
}
static void F_11 ( struct V_5 * V_5 ,
T_2 V_19 , T_2 V_27 ,
T_2 V_28 )
{
T_3 V_12 = ( V_27 <<
V_21 [ V_19 ] . V_29 ) ;
V_12 |= ( V_28 <<
V_21 [ V_19 ] . V_30 ) ;
F_6 ( V_5 , V_21 [ V_19 ] . V_31 ,
V_21 [ V_19 ] . V_32 ,
V_12 ) ;
}
static void F_12 ( struct V_5 * V_5 , T_2 type ,
bool V_20 )
{
F_6 ( V_5 , V_13 [ type ] . V_22 ,
V_33 ,
V_20 ? V_33 : 0 ) ;
}
static void F_13 ( struct V_5 * V_5 , T_2 type ,
T_2 V_34 , T_4 V_11 , T_2 V_35 )
{
T_3 V_12 = ( ( V_34 << V_36 ) |
( V_11 << V_37 ) |
( V_35 << V_38 ) ) ;
F_6 ( V_5 , V_13 [ type ] . V_22 ,
V_39 , V_12 ) ;
F_6 ( V_5 , V_13 [ type ] . V_40 ,
V_41 , V_11 << 16 ) ;
}
static void F_14 ( struct V_5 * V_5 , T_2 V_42 ,
bool V_20 )
{
F_6 ( V_5 , V_6 ,
F_15 ( V_42 ) ,
V_20 ?
F_15 ( V_42 ) : 0 ) ;
}
static void F_16 ( struct V_5 * V_5 , T_2 V_42 ,
T_2 V_43 )
{
T_3 V_44 = ( ( V_43 & 0x3 ) <<
F_17 ( V_42 ) ) ;
T_3 V_45 = ( ( ( V_43 & 0x4 ) >> 2 ) <<
F_18 ( V_42 ) ) ;
F_6 ( V_5 , V_46 ,
F_19 ( V_42 ) ,
V_44 ) ;
F_6 ( V_5 , V_47 ,
F_20 ( V_42 ) ,
V_45 ) ;
}
static void F_21 ( struct V_48 * V_49 ,
T_2 V_50 , T_2 V_51 )
{
T_4 V_52 , V_53 ;
V_52 = V_49 -> V_54 [ V_49 -> V_55 [ V_50 ] ] ;
V_52 += 1 ;
V_53 = ( V_51 * V_52 ) / V_56 ;
if ( V_53 == 0 ) {
F_9 ( V_49 -> V_5 , V_50 , false ) ;
} else {
if ( V_53 == V_52 )
V_53 = 0 ;
F_11 ( V_49 -> V_5 , V_50 , 0 ,
V_53 ) ;
F_9 ( V_49 -> V_5 , V_50 , true ) ;
}
}
static T_3 F_22 ( struct V_48
* V_49 , T_2 type )
{
T_3 V_57 ;
T_4 V_58 ;
T_2 V_59 , V_60 , V_61 , V_62 ;
V_57 = V_49 -> V_63 ;
V_59 = V_49 -> V_54 [ type ] ;
V_60 = V_49 -> V_64 [ type ] ;
V_60 = 0x1 << V_60 ;
V_61 = V_49 -> V_65 [ type ] ;
if ( V_61 == 0 )
V_61 = 1 ;
else
V_61 = V_61 * 2 ;
V_58 = V_49 -> V_66 [ type ] ;
V_62 = V_49 -> V_67 [ type ] ;
V_62 = 0x4 << ( V_62 * 2 ) ;
return V_57 / ( V_59 * V_60 * V_61 * V_62 * V_58 ) ;
}
static int F_23 ( struct V_48 * V_49 ,
T_2 V_42 )
{
T_3 V_68 , V_69 , V_70 , V_71 , V_3 ;
T_2 V_43 , type ;
F_24 ( V_49 -> V_5 , V_72 , 0 ) ;
F_24 ( V_49 -> V_5 , V_72 , 0x1 << V_42 ) ;
V_43 = V_49 -> V_43 [ V_42 ] ;
type = V_49 -> V_55 [ V_43 ] ;
V_71 = ( 1000 / F_22 ( V_49 , type ) ) ;
F_25 ( V_71 ) ;
F_26 ( V_49 -> V_5 , V_73 , & V_3 ) ;
if ( ! ( V_3 & V_74 ) )
return - V_75 ;
V_68 = V_3 & V_76 ;
V_69 = V_49 -> V_67 [ type ] ;
V_69 = 0x4 << ( V_69 * 2 ) ;
V_70 = V_49 -> V_63 ;
if ( V_68 == 0 )
return 0 ;
return ( V_70 * 60 ) / ( 2 * V_68 * V_69 ) ;
}
static T_5 F_27 ( struct V_77 * V_78 , struct V_79 * V_80 ,
const char * V_81 , T_6 V_82 )
{
struct V_83 * V_84 = F_28 ( V_80 ) ;
int V_50 = V_84 -> V_50 ;
int V_85 ;
struct V_48 * V_49 = F_29 ( V_78 ) ;
long V_51 ;
V_85 = F_30 ( V_81 , 10 , & V_51 ) ;
if ( V_85 != 0 )
return V_85 ;
if ( V_51 < 0 || V_51 > V_56 )
return - V_86 ;
if ( V_49 -> V_87 [ V_50 ] == V_51 )
return V_82 ;
V_49 -> V_87 [ V_50 ] = V_51 ;
F_21 ( V_49 , V_50 , V_51 ) ;
return V_82 ;
}
static T_5 F_31 ( struct V_77 * V_78 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_83 * V_84 = F_28 ( V_80 ) ;
int V_50 = V_84 -> V_50 ;
struct V_48 * V_49 = F_29 ( V_78 ) ;
return sprintf ( V_81 , L_1 , V_49 -> V_87 [ V_50 ] ) ;
}
static T_5 F_32 ( struct V_77 * V_78 , struct V_79 * V_80 ,
char * V_81 )
{
struct V_83 * V_84 = F_28 ( V_80 ) ;
int V_50 = V_84 -> V_50 ;
int V_88 ;
struct V_48 * V_49 = F_29 ( V_78 ) ;
V_88 = F_23 ( V_49 , V_50 ) ;
if ( V_88 < 0 )
return V_88 ;
return sprintf ( V_81 , L_2 , V_88 ) ;
}
static T_7 F_33 ( struct V_89 * V_90 ,
struct V_91 * V_92 , int V_50 )
{
struct V_77 * V_78 = F_34 ( V_90 , struct V_77 , V_90 ) ;
struct V_48 * V_49 = F_29 ( V_78 ) ;
if ( ! V_49 -> V_93 [ V_50 ] )
return 0 ;
return V_92 -> V_34 ;
}
static T_7 F_35 ( struct V_89 * V_90 ,
struct V_91 * V_92 , int V_50 )
{
struct V_77 * V_78 = F_34 ( V_90 , struct V_77 , V_90 ) ;
struct V_48 * V_49 = F_29 ( V_78 ) ;
if ( ! V_49 -> V_94 [ V_50 ] )
return 0 ;
return V_92 -> V_34 ;
}
static void F_36 ( struct V_48 * V_49 )
{
V_49 -> V_64 [ V_95 ] = V_96 ;
V_49 -> V_65 [ V_95 ] = V_97 ;
V_49 -> V_54 [ V_95 ] = V_98 ;
F_8 ( V_49 -> V_5 , V_95 , V_96 ,
V_97 , V_98 ) ;
F_12 ( V_49 -> V_5 , V_95 , true ) ;
V_49 -> V_67 [ V_95 ] = V_99 ;
V_49 -> V_66 [ V_95 ] = V_100 ;
F_13 ( V_49 -> V_5 , V_95 , V_101 ,
V_100 , V_99 ) ;
}
static void F_37 ( struct V_48 * V_49 ,
T_2 V_19 )
{
F_9 ( V_49 -> V_5 , V_19 , true ) ;
V_49 -> V_93 [ V_19 ] = true ;
V_49 -> V_55 [ V_19 ] = V_95 ;
F_10 ( V_49 -> V_5 , V_19 , V_95 ) ;
V_49 -> V_87 [ V_19 ] = V_102 ;
F_21 ( V_49 , V_19 , V_102 ) ;
}
static void F_38 ( struct V_48 * V_49 ,
T_2 * V_42 ,
int V_82 ,
T_2 V_103 )
{
T_2 V_3 , V_50 ;
for ( V_3 = 0 ; V_3 < V_82 ; V_3 ++ ) {
V_50 = V_42 [ V_3 ] ;
F_14 ( V_49 -> V_5 , V_50 , true ) ;
V_49 -> V_94 [ V_50 ] = true ;
V_49 -> V_43 [ V_50 ] = V_103 ;
F_16 ( V_49 -> V_5 , V_50 , V_103 ) ;
}
}
static int F_39 ( struct V_77 * V_78 ,
struct V_104 * V_105 ,
struct V_48 * V_49 )
{
T_2 * V_42 ;
T_3 V_19 ;
int V_85 , V_82 ;
V_85 = F_40 ( V_105 , L_3 , & V_19 ) ;
if ( V_85 )
return V_85 ;
F_37 ( V_49 , ( T_2 ) V_19 ) ;
V_82 = F_41 ( V_105 , L_4 ) ;
if ( V_82 < 1 )
return - V_86 ;
V_42 = F_42 ( V_78 , sizeof( * V_42 ) * V_82 ,
V_106 ) ;
if ( ! V_42 )
return - V_107 ;
V_85 = F_43 ( V_105 , L_4 ,
V_42 , V_82 ) ;
if ( V_85 )
return V_85 ;
F_38 ( V_49 , V_42 , V_82 , V_19 ) ;
return 0 ;
}
static int F_44 ( struct V_108 * V_109 )
{
struct V_77 * V_78 = & V_109 -> V_78 ;
struct V_104 * V_110 , * V_105 ;
struct V_48 * V_49 ;
void T_1 * V_4 ;
struct V_111 * V_112 ;
struct V_77 * V_113 ;
struct V_57 * V_57 ;
int V_85 ;
V_110 = V_78 -> V_114 ;
V_112 = F_45 ( V_109 , V_115 , 0 ) ;
if ( ! V_112 )
return - V_116 ;
V_4 = F_46 ( V_78 , V_112 ) ;
if ( F_47 ( V_4 ) )
return F_48 ( V_4 ) ;
V_49 = F_42 ( V_78 , sizeof( * V_49 ) , V_106 ) ;
if ( ! V_49 )
return - V_107 ;
V_49 -> V_5 = F_49 ( V_78 , NULL , ( V_117 void * ) V_4 ,
& V_118 ) ;
if ( F_47 ( V_49 -> V_5 ) )
return F_48 ( V_49 -> V_5 ) ;
F_24 ( V_49 -> V_5 , V_46 , 0 ) ;
F_24 ( V_49 -> V_5 , V_47 , 0 ) ;
V_57 = F_50 ( V_78 , NULL ) ;
if ( F_47 ( V_57 ) )
return - V_119 ;
V_49 -> V_63 = F_51 ( V_57 ) ;
F_5 ( V_49 -> V_5 , true ) ;
F_7 ( V_49 -> V_5 , 0 ) ;
F_36 ( V_49 ) ;
F_52 (np, child) {
V_85 = F_39 ( V_78 , V_105 , V_49 ) ;
F_53 ( V_105 ) ;
if ( V_85 )
return V_85 ;
}
V_49 -> V_120 [ 0 ] = & V_121 ;
V_49 -> V_120 [ 1 ] = & V_122 ;
V_49 -> V_120 [ 2 ] = NULL ;
V_113 = F_54 ( V_78 ,
L_5 ,
V_49 , V_49 -> V_120 ) ;
return F_55 ( V_113 ) ;
}
