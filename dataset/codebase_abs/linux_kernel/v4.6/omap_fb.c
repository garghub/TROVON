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
return 0 ;
}
static T_1 F_13 ( struct V_22 * V_22 ,
const struct V_28 * V_28 , int V_19 , int V_29 , int V_30 )
{
T_1 V_31 ;
V_31 = V_22 -> V_31 +
( V_29 * V_28 -> V_17 [ V_19 ] . V_32 ) +
( V_30 * V_22 -> V_33 / V_28 -> V_17 [ V_19 ] . V_34 ) ;
return V_22 -> V_35 + V_31 ;
}
bool F_14 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
struct V_22 * V_22 = & V_16 -> V_17 [ 0 ] ;
return F_15 ( V_22 -> V_18 ) & V_36 ;
}
void F_16 ( struct V_10 * V_11 ,
struct V_37 * V_38 , struct V_39 * V_40 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
const struct V_28 * V_28 = V_16 -> V_28 ;
struct V_22 * V_22 = & V_16 -> V_17 [ 0 ] ;
T_1 V_29 , V_30 , V_41 = 0 ;
V_40 -> V_42 = V_28 -> V_8 ;
V_40 -> V_43 = V_38 -> V_44 ;
V_40 -> V_45 = V_38 -> V_46 ;
V_40 -> V_47 = V_38 -> V_48 ;
V_40 -> V_49 = V_38 -> V_50 ;
V_40 -> V_51 = V_38 -> V_52 ;
V_40 -> V_53 = V_38 -> V_54 ;
V_29 = V_38 -> V_55 ;
V_30 = V_38 -> V_56 ;
if ( F_15 ( V_22 -> V_18 ) & V_36 ) {
T_1 V_57 = V_38 -> V_52 ;
T_1 V_58 = V_38 -> V_54 ;
switch ( V_38 -> V_59 & V_60 ) {
default:
F_17 ( V_11 -> V_61 -> V_61 , L_2 ,
( T_1 ) V_38 -> V_59 ) ;
case 0 :
case F_18 ( V_62 ) :
V_41 = 0 ;
break;
case F_18 ( V_63 ) :
V_41 = V_64 | V_65 ;
break;
case F_18 ( V_66 ) :
V_41 = V_65 | V_67 ;
break;
case F_18 ( V_68 ) :
V_41 = V_64 | V_67 ;
break;
}
if ( V_38 -> V_59 & F_18 ( V_69 ) )
V_41 ^= V_65 ;
if ( V_38 -> V_59 & F_18 ( V_70 ) )
V_41 ^= V_67 ;
if ( V_41 & V_64 )
F_19 ( V_57 , V_58 ) ;
if ( V_41 & V_67 )
V_30 += V_58 - 1 ;
if ( V_41 & V_65 )
V_29 += V_57 - 1 ;
F_20 ( V_22 -> V_18 , V_41 , V_29 , V_30 , & V_40 -> V_35 ) ;
V_40 -> V_71 = V_72 ;
V_40 -> V_73 = F_21 ( V_22 -> V_18 , V_41 ) ;
} else {
switch ( V_38 -> V_59 & V_60 ) {
case 0 :
case F_18 ( V_62 ) :
break;
default:
F_22 ( V_11 -> V_61 -> V_61 ,
L_3 ,
V_38 -> V_59 ) ;
V_38 -> V_59 = 0 ;
break;
}
V_40 -> V_35 = F_13 ( V_22 , V_28 , 0 , V_29 , V_30 ) ;
V_40 -> V_71 = V_74 ;
V_40 -> V_73 = V_22 -> V_33 ;
}
V_40 -> V_73 /= V_28 -> V_17 [ 0 ] . V_32 ;
if ( V_28 -> V_8 == V_75 ) {
V_22 = & V_16 -> V_17 [ 1 ] ;
if ( V_40 -> V_71 == V_72 ) {
F_23 ( ! ( F_15 ( V_22 -> V_18 ) & V_36 ) ) ;
F_20 ( V_22 -> V_18 , V_41 ,
V_29 / 2 , V_30 / 2 , & V_40 -> V_76 ) ;
} else {
V_40 -> V_76 = F_13 ( V_22 , V_28 , 1 , V_29 , V_30 ) ;
}
} else {
V_40 -> V_76 = 0 ;
}
}
int F_24 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_77 , V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
F_25 ( & V_16 -> V_78 ) ;
if ( V_16 -> V_79 > 0 ) {
V_16 -> V_79 ++ ;
F_26 ( & V_16 -> V_78 ) ;
return 0 ;
}
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
V_77 = F_27 ( V_22 -> V_18 , & V_22 -> V_35 , true ) ;
if ( V_77 )
goto V_80;
F_28 ( V_22 -> V_18 , V_81 ) ;
}
V_16 -> V_79 ++ ;
F_26 ( & V_16 -> V_78 ) ;
return 0 ;
V_80:
for ( V_6 -- ; V_6 >= 0 ; V_6 -- ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
F_29 ( V_22 -> V_18 ) ;
V_22 -> V_35 = 0 ;
}
F_26 ( & V_16 -> V_78 ) ;
return V_77 ;
}
void F_30 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
F_25 ( & V_16 -> V_78 ) ;
V_16 -> V_79 -- ;
if ( V_16 -> V_79 > 0 ) {
F_26 ( & V_16 -> V_78 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
F_29 ( V_22 -> V_18 ) ;
V_22 -> V_35 = 0 ;
}
F_26 ( & V_16 -> V_78 ) ;
}
struct V_82 * F_31 ( struct V_10 * V_11 , int V_83 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
if ( V_83 >= F_7 ( V_11 -> V_9 ) )
return NULL ;
return V_16 -> V_17 [ V_83 ] . V_18 ;
}
struct V_84 * F_32 (
struct V_10 * V_11 , struct V_84 * V_85 )
{
struct V_86 * V_61 = V_11 -> V_61 ;
struct V_87 * V_88 = & V_61 -> V_89 . V_88 ;
struct V_84 * V_90 = V_85 ;
if ( ! V_85 )
return F_33 ( V_88 , F_34 ( * V_85 ) ,
V_91 ) ;
F_35 (connector, connector_list, head) {
if ( V_90 != V_85 ) {
struct V_92 * V_93 = V_90 -> V_93 ;
struct V_94 * V_95 = V_93 ? V_93 -> V_95 : NULL ;
if ( V_95 && V_95 -> V_96 -> V_11 == V_11 )
return V_90 ;
}
}
return NULL ;
}
void F_36 ( struct V_10 * V_11 , struct V_97 * V_98 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
F_37 ( V_98 , L_4 , V_11 -> V_51 , V_11 -> V_53 ,
( char * ) & V_11 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
F_37 ( V_98 , L_5 ,
V_6 , V_22 -> V_31 , V_22 -> V_33 ) ;
F_38 ( V_22 -> V_18 , V_98 ) ;
}
}
struct V_10 * F_39 ( struct V_86 * V_61 ,
struct V_12 * V_99 , const struct V_100 * V_101 )
{
struct V_82 * V_102 [ 4 ] ;
struct V_10 * V_11 ;
int V_77 ;
V_77 = F_40 ( V_61 , V_99 , V_101 -> V_9 ,
V_102 , V_101 -> V_103 ) ;
if ( V_77 )
return F_41 ( V_77 ) ;
V_11 = F_42 ( V_61 , V_101 , V_102 ) ;
if ( F_43 ( V_11 ) ) {
int V_6 , V_19 = F_7 ( V_101 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ )
F_10 ( V_102 [ V_6 ] ) ;
return V_11 ;
}
return V_11 ;
}
struct V_10 * F_42 ( struct V_86 * V_61 ,
const struct V_100 * V_101 , struct V_82 * * V_102 )
{
struct V_15 * V_16 = NULL ;
struct V_10 * V_11 = NULL ;
const struct V_28 * V_28 = NULL ;
int V_77 , V_6 , V_19 = F_7 ( V_101 -> V_9 ) ;
F_8 ( L_6 ,
V_61 , V_101 , V_101 -> V_51 , V_101 -> V_53 ,
( char * ) & V_101 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ ) {
if ( V_7 [ V_6 ] . V_9 == V_101 -> V_9 ) {
V_28 = & V_7 [ V_6 ] ;
break;
}
}
if ( ! V_28 ) {
F_17 ( V_61 -> V_61 , L_7 ,
( char * ) & V_101 -> V_9 ) ;
V_77 = - V_104 ;
goto V_80;
}
V_16 = F_44 ( sizeof( * V_16 ) , V_105 ) ;
if ( ! V_16 ) {
V_77 = - V_106 ;
goto V_80;
}
V_11 = & V_16 -> V_20 ;
V_16 -> V_28 = V_28 ;
F_45 ( & V_16 -> V_78 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
int V_107 , V_33 = V_101 -> V_108 [ V_6 ] ;
if ( V_33 < ( V_101 -> V_51 * V_28 -> V_17 [ V_6 ] . V_32 ) ) {
F_17 ( V_61 -> V_61 , L_8 ,
V_33 , V_101 -> V_51 * V_28 -> V_17 [ V_6 ] . V_32 ) ;
V_77 = - V_104 ;
goto V_80;
}
if ( V_33 % V_28 -> V_17 [ V_6 ] . V_32 != 0 ) {
F_17 ( V_61 -> V_61 ,
L_9 ,
V_33 , V_28 -> V_17 [ V_6 ] . V_32 ) ;
V_77 = - V_104 ;
goto V_80;
}
V_107 = V_33 * V_101 -> V_53 / V_28 -> V_17 [ V_6 ] . V_34 ;
if ( V_107 > ( F_46 ( V_102 [ V_6 ] ) - V_101 -> V_109 [ V_6 ] ) ) {
F_17 ( V_61 -> V_61 , L_10 ,
V_102 [ V_6 ] -> V_107 - V_101 -> V_109 [ V_6 ] , V_107 ) ;
V_77 = - V_104 ;
goto V_80;
}
if ( V_6 > 0 && V_33 != V_101 -> V_108 [ V_6 - 1 ] ) {
F_17 ( V_61 -> V_61 ,
L_11 ,
V_33 , V_101 -> V_108 [ V_6 - 1 ] ) ;
V_77 = - V_104 ;
goto V_80;
}
V_22 -> V_18 = V_102 [ V_6 ] ;
V_22 -> V_31 = V_101 -> V_109 [ V_6 ] ;
V_22 -> V_33 = V_33 ;
V_22 -> V_35 = 0 ;
}
F_47 ( V_11 , V_101 ) ;
V_77 = F_48 ( V_61 , V_11 , & V_110 ) ;
if ( V_77 ) {
F_17 ( V_61 -> V_61 , L_12 , V_77 ) ;
goto V_80;
}
F_8 ( L_13 , V_11 -> V_20 . V_21 , V_11 ) ;
return V_11 ;
V_80:
F_11 ( V_16 ) ;
return F_41 ( V_77 ) ;
}
