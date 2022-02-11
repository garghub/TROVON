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
F_13 ( V_11 -> V_28 ) ;
for ( V_6 = 0 ; V_6 < V_27 ; V_6 ++ ) {
F_14 ( V_11 , V_26 [ V_6 ] . V_29 , V_26 [ V_6 ] . y1 ,
V_26 [ V_6 ] . V_30 - V_26 [ V_6 ] . V_29 ,
V_26 [ V_6 ] . V_31 - V_26 [ V_6 ] . y1 ) ;
}
F_15 ( V_11 -> V_28 ) ;
return 0 ;
}
static T_1 F_16 ( struct V_22 * V_22 ,
const struct V_32 * V_32 , int V_19 , int V_33 , int V_34 )
{
T_1 V_35 ;
V_35 = V_22 -> V_35 +
( V_33 * V_32 -> V_17 [ V_19 ] . V_36 ) +
( V_34 * V_22 -> V_37 / V_32 -> V_17 [ V_19 ] . V_38 ) ;
return V_22 -> V_39 + V_35 ;
}
void F_17 ( struct V_10 * V_11 ,
struct V_40 * V_41 , struct V_42 * V_43 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
const struct V_32 * V_32 = V_16 -> V_32 ;
struct V_22 * V_22 = & V_16 -> V_17 [ 0 ] ;
T_1 V_33 , V_34 , V_44 = 0 ;
V_43 -> V_45 = V_32 -> V_8 ;
V_43 -> V_46 = V_41 -> V_47 ;
V_43 -> V_48 = V_41 -> V_49 ;
V_43 -> V_50 = V_41 -> V_51 ;
V_43 -> V_52 = V_41 -> V_53 ;
V_43 -> V_54 = V_41 -> V_55 ;
V_43 -> V_56 = V_41 -> V_57 ;
V_33 = V_41 -> V_58 ;
V_34 = V_41 -> V_59 ;
if ( F_18 ( V_22 -> V_18 ) & V_60 ) {
T_1 V_61 = V_41 -> V_55 ;
T_1 V_62 = V_41 -> V_57 ;
switch ( V_41 -> V_63 & 0xf ) {
default:
F_19 ( V_11 -> V_28 -> V_28 , L_2 ,
( T_1 ) V_41 -> V_63 ) ;
case 0 :
case F_20 ( V_64 ) :
V_44 = 0 ;
break;
case F_20 ( V_65 ) :
V_44 = V_66 | V_67 ;
break;
case F_20 ( V_68 ) :
V_44 = V_67 | V_69 ;
break;
case F_20 ( V_70 ) :
V_44 = V_66 | V_69 ;
break;
}
if ( V_41 -> V_63 & F_20 ( V_71 ) )
V_44 ^= V_67 ;
if ( V_41 -> V_63 & F_20 ( V_72 ) )
V_44 ^= V_69 ;
if ( V_44 & V_66 )
F_21 ( V_61 , V_62 ) ;
if ( V_44 & V_69 )
V_34 += V_62 - 1 ;
if ( V_44 & V_67 )
V_33 += V_61 - 1 ;
F_22 ( V_22 -> V_18 , V_44 , V_33 , V_34 , & V_43 -> V_39 ) ;
V_43 -> V_73 = V_74 ;
V_43 -> V_75 = F_23 ( V_22 -> V_18 , V_44 ) ;
} else {
V_43 -> V_39 = F_16 ( V_22 , V_32 , 0 , V_33 , V_34 ) ;
V_43 -> V_73 = V_76 ;
V_43 -> V_75 = V_22 -> V_37 ;
}
V_43 -> V_75 /= V_32 -> V_17 [ 0 ] . V_36 ;
if ( V_32 -> V_8 == V_77 ) {
V_22 = & V_16 -> V_17 [ 1 ] ;
if ( V_43 -> V_73 == V_74 ) {
F_24 ( ! ( F_18 ( V_22 -> V_18 ) & V_60 ) ) ;
F_22 ( V_22 -> V_18 , V_44 ,
V_33 / 2 , V_34 / 2 , & V_43 -> V_78 ) ;
} else {
V_43 -> V_78 = F_16 ( V_22 , V_32 , 1 , V_33 , V_34 ) ;
}
} else {
V_43 -> V_78 = 0 ;
}
}
int F_25 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_79 , V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
V_79 = F_26 ( V_22 -> V_18 , & V_22 -> V_39 , true ) ;
if ( V_79 )
goto V_80;
F_27 ( V_22 -> V_18 , V_81 ) ;
}
return 0 ;
V_80:
for ( V_6 -- ; V_6 >= 0 ; V_6 -- ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
F_28 ( V_22 -> V_18 ) ;
V_22 -> V_39 = 0 ;
}
return V_79 ;
}
int F_29 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_79 , V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
V_79 = F_28 ( V_22 -> V_18 ) ;
if ( V_79 )
goto V_80;
V_22 -> V_39 = 0 ;
}
return 0 ;
V_80:
return V_79 ;
}
struct V_82 * F_30 ( struct V_10 * V_11 , int V_83 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
if ( V_83 >= F_7 ( V_11 -> V_9 ) )
return NULL ;
return V_16 -> V_17 [ V_83 ] . V_18 ;
}
struct V_84 * F_31 (
struct V_10 * V_11 , struct V_84 * V_85 )
{
struct V_86 * V_28 = V_11 -> V_28 ;
struct V_87 * V_88 = & V_28 -> V_89 . V_88 ;
struct V_84 * V_90 = V_85 ;
if ( ! V_85 )
return F_32 ( V_88 , F_33 ( * V_85 ) , V_91 ) ;
F_34 (connector, connector_list, head) {
if ( V_90 != V_85 ) {
struct V_92 * V_93 = V_90 -> V_93 ;
struct V_94 * V_95 = V_93 ? V_93 -> V_95 : NULL ;
if ( V_95 && V_95 -> V_11 == V_11 )
return V_90 ;
}
}
return NULL ;
}
void F_14 ( struct V_10 * V_11 ,
int V_33 , int V_34 , int V_61 , int V_62 )
{
struct V_84 * V_90 = NULL ;
F_35 ( L_3 , V_33 , V_34 , V_61 , V_62 , V_11 ) ;
while ( ( V_90 = F_31 ( V_11 , V_90 ) ) ) {
if ( V_90 -> V_93 && V_90 -> V_93 -> V_95 ) {
struct V_94 * V_95 = V_90 -> V_93 -> V_95 ;
int V_96 = F_36 ( 0 , V_33 - V_95 -> V_33 ) ;
int V_97 = F_36 ( 0 , V_34 - V_95 -> V_34 ) ;
int V_98 = V_61 + ( V_33 - V_95 -> V_33 ) - V_96 ;
int V_99 = V_62 + ( V_34 - V_95 -> V_34 ) - V_97 ;
F_37 ( V_90 , V_96 , V_97 , V_98 , V_99 ) ;
}
}
}
void F_38 ( struct V_10 * V_11 , struct V_100 * V_101 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
F_39 ( V_101 , L_4 , V_11 -> V_54 , V_11 -> V_56 ,
( char * ) & V_11 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
F_39 ( V_101 , L_5 ,
V_6 , V_22 -> V_35 , V_22 -> V_37 ) ;
F_40 ( V_22 -> V_18 , V_101 ) ;
}
}
struct V_10 * F_41 ( struct V_86 * V_28 ,
struct V_12 * V_102 , struct V_103 * V_104 )
{
struct V_82 * V_105 [ 4 ] ;
struct V_10 * V_11 ;
int V_79 ;
V_79 = F_42 ( V_28 , V_102 , V_104 -> V_9 ,
V_105 , V_104 -> V_106 ) ;
if ( V_79 )
return F_43 ( V_79 ) ;
V_11 = F_44 ( V_28 , V_104 , V_105 ) ;
if ( F_45 ( V_11 ) ) {
int V_6 , V_19 = F_7 ( V_104 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ )
F_10 ( V_105 [ V_6 ] ) ;
return V_11 ;
}
return V_11 ;
}
struct V_10 * F_44 ( struct V_86 * V_28 ,
struct V_103 * V_104 , struct V_82 * * V_105 )
{
struct V_15 * V_16 ;
struct V_10 * V_11 = NULL ;
const struct V_32 * V_32 = NULL ;
int V_79 , V_6 , V_19 = F_7 ( V_104 -> V_9 ) ;
F_8 ( L_6 ,
V_28 , V_104 , V_104 -> V_54 , V_104 -> V_56 ,
( char * ) & V_104 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ ) {
if ( V_7 [ V_6 ] . V_9 == V_104 -> V_9 ) {
V_32 = & V_7 [ V_6 ] ;
break;
}
}
if ( ! V_32 ) {
F_19 ( V_28 -> V_28 , L_7 ,
( char * ) & V_104 -> V_9 ) ;
V_79 = - V_107 ;
goto V_80;
}
V_16 = F_46 ( sizeof( * V_16 ) , V_108 ) ;
if ( ! V_16 ) {
V_79 = - V_109 ;
goto V_80;
}
V_11 = & V_16 -> V_20 ;
V_16 -> V_32 = V_32 ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
int V_110 , V_37 = V_104 -> V_111 [ V_6 ] ;
if ( V_37 < ( V_104 -> V_54 * V_32 -> V_17 [ V_6 ] . V_36 ) ) {
F_19 ( V_28 -> V_28 , L_8 ,
V_37 , V_104 -> V_54 * V_32 -> V_17 [ V_6 ] . V_36 ) ;
V_79 = - V_107 ;
goto V_80;
}
V_110 = V_37 * V_104 -> V_56 / V_32 -> V_17 [ V_6 ] . V_38 ;
if ( V_110 > ( F_47 ( V_105 [ V_6 ] ) - V_104 -> V_112 [ V_6 ] ) ) {
F_19 ( V_28 -> V_28 , L_9 ,
V_105 [ V_6 ] -> V_110 - V_104 -> V_112 [ V_6 ] , V_110 ) ;
V_79 = - V_107 ;
goto V_80;
}
V_22 -> V_18 = V_105 [ V_6 ] ;
V_22 -> V_35 = V_104 -> V_112 [ V_6 ] ;
V_22 -> V_37 = V_37 ;
V_22 -> V_39 = 0 ;
}
F_48 ( V_11 , V_104 ) ;
V_79 = F_49 ( V_28 , V_11 , & V_113 ) ;
if ( V_79 ) {
F_19 ( V_28 -> V_28 , L_10 , V_79 ) ;
goto V_80;
}
F_8 ( L_11 , V_11 -> V_20 . V_21 , V_11 ) ;
return V_11 ;
V_80:
if ( V_11 )
F_6 ( V_11 ) ;
return F_43 ( V_79 ) ;
}
