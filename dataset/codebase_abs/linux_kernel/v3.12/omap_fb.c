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
int F_23 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_79 , V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
V_79 = F_24 ( V_22 -> V_18 , & V_22 -> V_38 , true ) ;
if ( V_79 )
goto V_80;
F_25 ( V_22 -> V_18 , V_81 ) ;
}
return 0 ;
V_80:
for ( V_6 -- ; V_6 >= 0 ; V_6 -- ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
F_26 ( V_22 -> V_18 ) ;
V_22 -> V_38 = 0 ;
}
return V_79 ;
}
int F_27 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_79 , V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
V_79 = F_26 ( V_22 -> V_18 ) ;
if ( V_79 )
goto V_80;
V_22 -> V_38 = 0 ;
}
return 0 ;
V_80:
return V_79 ;
}
struct V_82 * F_28 ( struct V_10 * V_11 , int V_83 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
if ( V_83 >= F_7 ( V_11 -> V_9 ) )
return NULL ;
return V_16 -> V_17 [ V_83 ] . V_18 ;
}
struct V_84 * F_29 (
struct V_10 * V_11 , struct V_84 * V_85 )
{
struct V_86 * V_63 = V_11 -> V_63 ;
struct V_87 * V_88 = & V_63 -> V_89 . V_88 ;
struct V_84 * V_90 = V_85 ;
if ( ! V_85 )
return F_30 ( V_88 , F_31 ( * V_85 ) , V_91 ) ;
F_32 (connector, connector_list, head) {
if ( V_90 != V_85 ) {
struct V_92 * V_93 = V_90 -> V_93 ;
struct V_94 * V_95 = V_93 ? V_93 -> V_95 : NULL ;
if ( V_95 && V_95 -> V_11 == V_11 )
return V_90 ;
}
}
return NULL ;
}
void F_13 ( struct V_10 * V_11 ,
int V_32 , int V_33 , int V_60 , int V_61 )
{
struct V_84 * V_90 = NULL ;
F_33 ( L_3 , V_32 , V_33 , V_60 , V_61 , V_11 ) ;
while ( ( V_90 = F_29 ( V_11 , V_90 ) ) ) {
if ( V_90 -> V_93 && V_90 -> V_93 -> V_95 ) {
struct V_94 * V_95 = V_90 -> V_93 -> V_95 ;
int V_96 = F_34 ( 0 , V_32 - V_95 -> V_32 ) ;
int V_97 = F_34 ( 0 , V_33 - V_95 -> V_33 ) ;
int V_98 = V_60 + ( V_32 - V_95 -> V_32 ) - V_96 ;
int V_99 = V_61 + ( V_33 - V_95 -> V_33 ) - V_97 ;
F_35 ( V_90 , V_96 , V_97 , V_98 , V_99 ) ;
}
}
}
void F_36 ( struct V_10 * V_11 , struct V_100 * V_101 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
F_37 ( V_101 , L_4 , V_11 -> V_53 , V_11 -> V_55 ,
( char * ) & V_11 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
F_37 ( V_101 , L_5 ,
V_6 , V_22 -> V_34 , V_22 -> V_36 ) ;
F_38 ( V_22 -> V_18 , V_101 ) ;
}
}
struct V_10 * F_39 ( struct V_86 * V_63 ,
struct V_12 * V_102 , struct V_103 * V_104 )
{
struct V_82 * V_105 [ 4 ] ;
struct V_10 * V_11 ;
int V_79 ;
V_79 = F_40 ( V_63 , V_102 , V_104 -> V_9 ,
V_105 , V_104 -> V_106 ) ;
if ( V_79 )
return F_41 ( V_79 ) ;
V_11 = F_42 ( V_63 , V_104 , V_105 ) ;
if ( F_43 ( V_11 ) ) {
int V_6 , V_19 = F_7 ( V_104 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ )
F_10 ( V_105 [ V_6 ] ) ;
return V_11 ;
}
return V_11 ;
}
struct V_10 * F_42 ( struct V_86 * V_63 ,
struct V_103 * V_104 , struct V_82 * * V_105 )
{
struct V_15 * V_16 ;
struct V_10 * V_11 = NULL ;
const struct V_31 * V_31 = NULL ;
int V_79 , V_6 , V_19 = F_7 ( V_104 -> V_9 ) ;
F_8 ( L_6 ,
V_63 , V_104 , V_104 -> V_53 , V_104 -> V_55 ,
( char * ) & V_104 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ ) {
if ( V_7 [ V_6 ] . V_9 == V_104 -> V_9 ) {
V_31 = & V_7 [ V_6 ] ;
break;
}
}
if ( ! V_31 ) {
F_17 ( V_63 -> V_63 , L_7 ,
( char * ) & V_104 -> V_9 ) ;
V_79 = - V_107 ;
goto V_80;
}
V_16 = F_44 ( sizeof( * V_16 ) , V_108 ) ;
if ( ! V_16 ) {
V_79 = - V_109 ;
goto V_80;
}
V_11 = & V_16 -> V_20 ;
V_16 -> V_31 = V_31 ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
int V_110 , V_36 = V_104 -> V_111 [ V_6 ] ;
if ( V_36 < ( V_104 -> V_53 * V_31 -> V_17 [ V_6 ] . V_35 ) ) {
F_17 ( V_63 -> V_63 , L_8 ,
V_36 , V_104 -> V_53 * V_31 -> V_17 [ V_6 ] . V_35 ) ;
V_79 = - V_107 ;
goto V_80;
}
V_110 = V_36 * V_104 -> V_55 / V_31 -> V_17 [ V_6 ] . V_37 ;
if ( V_110 > ( F_45 ( V_105 [ V_6 ] ) - V_104 -> V_112 [ V_6 ] ) ) {
F_17 ( V_63 -> V_63 , L_9 ,
V_105 [ V_6 ] -> V_110 - V_104 -> V_112 [ V_6 ] , V_110 ) ;
V_79 = - V_107 ;
goto V_80;
}
V_22 -> V_18 = V_105 [ V_6 ] ;
V_22 -> V_34 = V_104 -> V_112 [ V_6 ] ;
V_22 -> V_36 = V_36 ;
V_22 -> V_38 = 0 ;
}
F_46 ( V_11 , V_104 ) ;
V_79 = F_47 ( V_63 , V_11 , & V_113 ) ;
if ( V_79 ) {
F_17 ( V_63 -> V_63 , L_10 , V_79 ) ;
goto V_80;
}
F_8 ( L_11 , V_11 -> V_20 . V_21 , V_11 ) ;
return V_11 ;
V_80:
if ( V_11 )
F_6 ( V_11 ) ;
return F_41 ( V_79 ) ;
}
