T_1 F_1 ( T_1 * V_1 ,
T_1 V_2 , enum V_3 V_4 )
{
T_1 V_5 = 0 ;
int V_6 = 0 ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) && V_5 < V_2 ; V_6 ++ )
if ( V_7 [ V_6 ] . V_8 & V_4 )
V_1 [ V_5 ++ ] = V_7 [ V_6 ] . V_9 ;
return V_5 ;
}
static int F_3 ( struct V_10 * V_11 ,
struct V_12 * V_13 ,
unsigned int * V_14 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
return F_5 ( V_13 ,
V_16 -> V_17 [ 0 ] . V_18 , V_14 ) ;
}
static void F_6 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
F_8 ( L_1 , V_11 -> V_20 . V_21 , V_11 ) ;
F_9 ( V_11 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
if ( V_22 -> V_18 )
F_10 ( V_22 -> V_18 ) ;
}
F_11 ( V_16 ) ;
}
static int F_12 ( struct V_10 * V_11 ,
struct V_12 * V_13 , unsigned V_23 , unsigned V_24 ,
struct V_25 * V_26 , unsigned V_27 )
{
int V_6 ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ ) {
F_13 ( V_11 , V_26 [ V_6 ] . V_28 , V_26 [ V_6 ] . y1 ,
V_26 [ V_6 ] . V_29 - V_26 [ V_6 ] . V_28 ,
V_26 [ V_6 ] . V_30 - V_26 [ V_6 ] . y1 ) ;
}
return 0 ;
}
static T_1 F_14 ( struct V_22 * V_22 ,
const struct V_31 * V_31 , int V_19 , int V_32 , int V_33 )
{
T_1 V_34 ;
V_34 = V_22 -> V_34 +
( V_32 * V_31 -> V_17 [ V_19 ] . V_35 ) +
( V_33 * V_22 -> V_36 / V_31 -> V_17 [ V_19 ] . V_37 ) ;
return V_22 -> V_38 + V_34 ;
}
void F_15 ( struct V_10 * V_11 ,
struct V_39 * V_40 , struct V_41 * V_42 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
const struct V_31 * V_31 = V_16 -> V_31 ;
struct V_22 * V_22 = & V_16 -> V_17 [ 0 ] ;
T_1 V_32 , V_33 , V_43 = 0 ;
V_42 -> V_44 = V_31 -> V_8 ;
V_42 -> V_45 = V_40 -> V_46 ;
V_42 -> V_47 = V_40 -> V_48 ;
V_42 -> V_49 = V_40 -> V_50 ;
V_42 -> V_51 = V_40 -> V_52 ;
V_42 -> V_53 = V_40 -> V_54 ;
V_42 -> V_55 = V_40 -> V_56 ;
V_32 = V_40 -> V_57 ;
V_33 = V_40 -> V_58 ;
if ( F_16 ( V_22 -> V_18 ) & V_59 ) {
T_1 V_60 = V_40 -> V_54 ;
T_1 V_61 = V_40 -> V_56 ;
switch ( V_40 -> V_62 & 0xf ) {
default:
F_17 ( V_11 -> V_63 -> V_63 , L_2 ,
( T_1 ) V_40 -> V_62 ) ;
case 0 :
case F_18 ( V_64 ) :
V_43 = 0 ;
break;
case F_18 ( V_65 ) :
V_43 = V_66 | V_67 ;
break;
case F_18 ( V_68 ) :
V_43 = V_67 | V_69 ;
break;
case F_18 ( V_70 ) :
V_43 = V_66 | V_69 ;
break;
}
if ( V_40 -> V_62 & F_18 ( V_71 ) )
V_43 ^= V_67 ;
if ( V_40 -> V_62 & F_18 ( V_72 ) )
V_43 ^= V_69 ;
if ( V_43 & V_66 )
F_19 ( V_60 , V_61 ) ;
if ( V_43 & V_69 )
V_33 += V_61 - 1 ;
if ( V_43 & V_67 )
V_32 += V_60 - 1 ;
F_20 ( V_22 -> V_18 , V_43 , V_32 , V_33 , & V_42 -> V_38 ) ;
V_42 -> V_73 = V_74 ;
V_42 -> V_75 = F_21 ( V_22 -> V_18 , V_43 ) ;
} else {
V_42 -> V_38 = F_14 ( V_22 , V_31 , 0 , V_32 , V_33 ) ;
V_42 -> V_73 = V_76 ;
V_42 -> V_75 = V_22 -> V_36 ;
}
V_42 -> V_75 /= V_31 -> V_17 [ 0 ] . V_35 ;
if ( V_31 -> V_8 == V_77 ) {
V_22 = & V_16 -> V_17 [ 1 ] ;
if ( V_42 -> V_73 == V_74 ) {
F_22 ( ! ( F_16 ( V_22 -> V_18 ) & V_59 ) ) ;
F_20 ( V_22 -> V_18 , V_43 ,
V_32 / 2 , V_33 / 2 , & V_42 -> V_78 ) ;
} else {
V_42 -> V_78 = F_14 ( V_22 , V_31 , 1 , V_32 , V_33 ) ;
}
} else {
V_42 -> V_78 = 0 ;
}
}
int F_23 ( struct V_10 * V_79 ,
struct V_10 * V_80 , void * V_81 ,
void (* F_24)( void * V_81 , struct V_82 * V_18 ) )
{
int V_83 = 0 , V_6 , V_84 , V_85 ;
struct V_15 * V_86 = F_4 ( V_79 ) ;
struct V_15 * V_87 = F_4 ( V_80 ) ;
T_1 V_88 = 0 ;
V_84 = V_79 ? F_7 ( V_79 -> V_9 ) : 0 ;
V_85 = V_80 ? F_7 ( V_80 -> V_9 ) : 0 ;
for ( V_6 = 0 ; V_6 < F_25 ( V_84 , V_85 ) ; V_6 ++ ) {
struct V_22 * V_89 , * V_90 ;
V_89 = ( V_6 < V_84 ) ? & V_86 -> V_17 [ V_6 ] : NULL ;
V_90 = ( V_6 < V_85 ) ? & V_87 -> V_17 [ V_6 ] : NULL ;
if ( V_89 )
F_24 ( V_81 , V_89 -> V_18 ) ;
if ( V_90 && ! V_83 ) {
V_83 = F_26 ( V_90 -> V_18 , & V_90 -> V_38 , true ) ;
if ( ! V_83 ) {
F_27 ( V_90 -> V_18 , V_91 ) ;
V_88 |= ( 1 << V_6 ) ;
}
}
}
if ( V_83 ) {
for ( V_6 = 0 ; V_6 < V_85 ; V_6 ++ ) {
if ( V_88 & ( 1 << V_6 ) ) {
struct V_22 * V_90 = & V_86 -> V_17 [ V_6 ] ;
F_24 ( V_81 , V_90 -> V_18 ) ;
}
}
}
return V_83 ;
}
struct V_82 * F_28 ( struct V_10 * V_11 , int V_92 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
if ( V_92 >= F_7 ( V_11 -> V_9 ) )
return NULL ;
return V_16 -> V_17 [ V_92 ] . V_18 ;
}
struct V_93 * F_29 (
struct V_10 * V_11 , struct V_93 * V_94 )
{
struct V_95 * V_63 = V_11 -> V_63 ;
struct V_96 * V_97 = & V_63 -> V_98 . V_97 ;
struct V_93 * V_99 = V_94 ;
if ( ! V_94 )
return F_30 ( V_97 , F_31 ( * V_94 ) , V_100 ) ;
F_32 (connector, connector_list, head) {
if ( V_99 != V_94 ) {
struct V_101 * V_102 = V_99 -> V_102 ;
struct V_103 * V_104 = V_102 ? V_102 -> V_104 : NULL ;
if ( V_104 && V_104 -> V_11 == V_11 )
return V_99 ;
}
}
return NULL ;
}
void F_13 ( struct V_10 * V_11 ,
int V_32 , int V_33 , int V_60 , int V_61 )
{
struct V_93 * V_99 = NULL ;
F_33 ( L_3 , V_32 , V_33 , V_60 , V_61 , V_11 ) ;
while ( ( V_99 = F_29 ( V_11 , V_99 ) ) ) {
if ( V_99 -> V_102 && V_99 -> V_102 -> V_104 ) {
struct V_103 * V_104 = V_99 -> V_102 -> V_104 ;
int V_105 = F_25 ( 0 , V_32 - V_104 -> V_32 ) ;
int V_106 = F_25 ( 0 , V_33 - V_104 -> V_33 ) ;
int V_107 = V_60 + ( V_32 - V_104 -> V_32 ) - V_105 ;
int V_108 = V_61 + ( V_33 - V_104 -> V_33 ) - V_106 ;
F_34 ( V_99 , V_105 , V_106 , V_107 , V_108 ) ;
}
}
}
void F_35 ( struct V_10 * V_11 , struct V_109 * V_110 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
F_36 ( V_110 , L_4 , V_11 -> V_53 , V_11 -> V_55 ,
( char * ) & V_11 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
F_36 ( V_110 , L_5 ,
V_6 , V_22 -> V_34 , V_22 -> V_36 ) ;
F_37 ( V_22 -> V_18 , V_110 ) ;
}
}
struct V_10 * F_38 ( struct V_95 * V_63 ,
struct V_12 * V_111 , struct V_112 * V_113 )
{
struct V_82 * V_114 [ 4 ] ;
struct V_10 * V_11 ;
int V_83 ;
V_83 = F_39 ( V_63 , V_111 , V_113 -> V_9 ,
V_114 , V_113 -> V_115 ) ;
if ( V_83 )
return F_40 ( V_83 ) ;
V_11 = F_41 ( V_63 , V_113 , V_114 ) ;
if ( F_42 ( V_11 ) ) {
int V_6 , V_19 = F_7 ( V_113 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ )
F_10 ( V_114 [ V_6 ] ) ;
return V_11 ;
}
return V_11 ;
}
struct V_10 * F_41 ( struct V_95 * V_63 ,
struct V_112 * V_113 , struct V_82 * * V_114 )
{
struct V_15 * V_16 ;
struct V_10 * V_11 = NULL ;
const struct V_31 * V_31 = NULL ;
int V_83 , V_6 , V_19 = F_7 ( V_113 -> V_9 ) ;
F_8 ( L_6 ,
V_63 , V_113 , V_113 -> V_53 , V_113 -> V_55 ,
( char * ) & V_113 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ ) {
if ( V_7 [ V_6 ] . V_9 == V_113 -> V_9 ) {
V_31 = & V_7 [ V_6 ] ;
break;
}
}
if ( ! V_31 ) {
F_17 ( V_63 -> V_63 , L_7 ,
( char * ) & V_113 -> V_9 ) ;
V_83 = - V_116 ;
goto V_117;
}
V_16 = F_43 ( sizeof( * V_16 ) , V_118 ) ;
if ( ! V_16 ) {
F_17 ( V_63 -> V_63 , L_8 ) ;
V_83 = - V_119 ;
goto V_117;
}
V_11 = & V_16 -> V_20 ;
V_83 = F_44 ( V_63 , V_11 , & V_120 ) ;
if ( V_83 ) {
F_17 ( V_63 -> V_63 , L_9 , V_83 ) ;
goto V_117;
}
F_8 ( L_10 , V_11 -> V_20 . V_21 , V_11 ) ;
V_16 -> V_31 = V_31 ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
int V_121 , V_36 = V_113 -> V_122 [ V_6 ] ;
if ( V_36 < ( V_113 -> V_53 * V_31 -> V_17 [ V_6 ] . V_35 ) ) {
F_17 ( V_63 -> V_63 , L_11 ,
V_36 , V_113 -> V_53 * V_31 -> V_17 [ V_6 ] . V_35 ) ;
V_83 = - V_116 ;
goto V_117;
}
V_121 = V_36 * V_113 -> V_55 / V_31 -> V_17 [ V_6 ] . V_37 ;
if ( V_121 > ( F_45 ( V_114 [ V_6 ] ) - V_113 -> V_123 [ V_6 ] ) ) {
F_17 ( V_63 -> V_63 , L_12 ,
V_114 [ V_6 ] -> V_121 - V_113 -> V_123 [ V_6 ] , V_121 ) ;
V_83 = - V_116 ;
goto V_117;
}
V_22 -> V_18 = V_114 [ V_6 ] ;
V_22 -> V_34 = V_113 -> V_123 [ V_6 ] ;
V_22 -> V_36 = V_36 ;
V_22 -> V_38 = 0 ;
}
F_46 ( V_11 , V_113 ) ;
return V_11 ;
V_117:
if ( V_11 )
F_6 ( V_11 ) ;
return F_40 ( V_83 ) ;
}
