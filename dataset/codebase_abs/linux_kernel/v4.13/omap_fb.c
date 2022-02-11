static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned int * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_3 ( V_4 ,
V_7 -> V_8 [ 0 ] . V_9 , V_5 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 , V_11 = V_2 -> V_12 -> V_13 ;
F_5 ( L_1 , V_2 -> V_14 . V_15 , V_2 ) ;
F_6 ( V_2 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
struct V_16 * V_16 = & V_7 -> V_8 [ V_10 ] ;
F_7 ( V_16 -> V_9 ) ;
}
F_8 ( V_7 ) ;
}
static T_1 F_9 ( struct V_16 * V_16 ,
const struct V_17 * V_12 , int V_11 , int V_18 , int V_19 )
{
T_1 V_20 ;
V_20 = V_16 -> V_20
+ ( V_18 * V_12 -> V_21 [ V_11 ] / ( V_11 == 0 ? 1 : V_12 -> V_22 ) )
+ ( V_19 * V_16 -> V_23 / ( V_11 == 0 ? 1 : V_12 -> V_24 ) ) ;
return V_16 -> V_25 + V_20 ;
}
bool F_10 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_16 * V_16 = & V_7 -> V_8 [ 0 ] ;
return F_11 ( V_16 -> V_9 ) & V_26 ;
}
static T_1 F_12 ( unsigned int V_27 )
{
T_1 V_28 ;
switch ( V_27 & V_29 ) {
default:
case V_30 :
V_28 = 0 ;
break;
case V_31 :
V_28 = V_32 | V_33 ;
break;
case V_34 :
V_28 = V_33 | V_35 ;
break;
case V_36 :
V_28 = V_32 | V_35 ;
break;
}
if ( V_27 & V_37 )
V_28 ^= V_33 ;
if ( V_27 & V_38 )
V_28 ^= V_35 ;
return V_28 ;
}
void F_13 ( struct V_1 * V_2 ,
struct V_39 * V_40 , struct V_41 * V_42 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_17 * V_12 = V_7 -> V_12 ;
struct V_16 * V_16 = & V_7 -> V_8 [ 0 ] ;
T_1 V_18 , V_19 , V_28 = 0 ;
V_42 -> V_43 = V_2 -> V_12 -> V_12 ;
V_42 -> V_44 = V_40 -> V_45 ;
V_42 -> V_46 = V_40 -> V_47 ;
V_42 -> V_48 = V_40 -> V_49 ;
V_42 -> V_50 = V_40 -> V_51 ;
V_42 -> V_52 = V_40 -> V_53 >> 16 ;
V_42 -> V_54 = V_40 -> V_55 >> 16 ;
if ( F_14 ( V_40 -> V_56 ) )
F_15 ( V_42 -> V_52 , V_42 -> V_54 ) ;
V_18 = V_40 -> V_57 >> 16 ;
V_19 = V_40 -> V_58 >> 16 ;
if ( F_11 ( V_16 -> V_9 ) & V_26 ) {
T_1 V_59 = V_40 -> V_53 >> 16 ;
T_1 V_60 = V_40 -> V_55 >> 16 ;
V_28 = F_12 ( V_40 -> V_56 ) ;
if ( V_2 -> V_12 -> V_12 == V_61 ||
V_2 -> V_12 -> V_12 == V_62 ) {
V_18 /= 2 ;
V_59 /= 2 ;
}
if ( V_28 & V_35 )
V_19 += V_60 - 1 ;
if ( V_28 & V_33 )
V_18 += V_59 - 1 ;
F_16 ( V_16 -> V_9 , V_28 , V_18 , V_19 ,
& V_42 -> V_63 ) ;
V_42 -> V_64 = V_65 ;
V_42 -> V_56 = V_40 -> V_56 ? : V_30 ;
V_42 -> V_66 = F_17 ( V_16 -> V_9 , V_28 ) ;
} else {
switch ( V_40 -> V_56 & V_29 ) {
case 0 :
case V_30 :
break;
default:
F_18 ( V_2 -> V_67 -> V_67 ,
L_2 ,
V_40 -> V_56 ) ;
break;
}
V_42 -> V_63 = F_9 ( V_16 , V_12 , 0 , V_18 , V_19 ) ;
V_42 -> V_64 = V_68 ;
V_42 -> V_56 = V_30 ;
V_42 -> V_66 = V_16 -> V_23 ;
}
V_42 -> V_66 /= V_12 -> V_21 [ 0 ] ;
if ( V_2 -> V_12 -> V_12 == V_69 ) {
V_16 = & V_7 -> V_8 [ 1 ] ;
if ( V_42 -> V_64 == V_65 ) {
F_19 ( ! ( F_11 ( V_16 -> V_9 ) & V_26 ) ) ;
F_16 ( V_16 -> V_9 , V_28 , V_18 / 2 , V_19 / 2 ,
& V_42 -> V_70 ) ;
} else {
V_42 -> V_70 = F_9 ( V_16 , V_12 , 1 , V_18 , V_19 ) ;
}
} else {
V_42 -> V_70 = 0 ;
}
}
int F_20 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_71 , V_10 , V_11 = V_2 -> V_12 -> V_13 ;
F_21 ( & V_7 -> V_72 ) ;
if ( V_7 -> V_73 > 0 ) {
V_7 -> V_73 ++ ;
F_22 ( & V_7 -> V_72 ) ;
return 0 ;
}
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
struct V_16 * V_16 = & V_7 -> V_8 [ V_10 ] ;
V_71 = F_23 ( V_16 -> V_9 , & V_16 -> V_25 ) ;
if ( V_71 )
goto V_74;
F_24 ( V_16 -> V_9 , V_75 ) ;
}
V_7 -> V_73 ++ ;
F_22 ( & V_7 -> V_72 ) ;
return 0 ;
V_74:
for ( V_10 -- ; V_10 >= 0 ; V_10 -- ) {
struct V_16 * V_16 = & V_7 -> V_8 [ V_10 ] ;
F_25 ( V_16 -> V_9 ) ;
V_16 -> V_25 = 0 ;
}
F_22 ( & V_7 -> V_72 ) ;
return V_71 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 , V_11 = V_2 -> V_12 -> V_13 ;
F_21 ( & V_7 -> V_72 ) ;
V_7 -> V_73 -- ;
if ( V_7 -> V_73 > 0 ) {
F_22 ( & V_7 -> V_72 ) ;
return;
}
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
struct V_16 * V_16 = & V_7 -> V_8 [ V_10 ] ;
F_25 ( V_16 -> V_9 ) ;
V_16 -> V_25 = 0 ;
}
F_22 ( & V_7 -> V_72 ) ;
}
struct V_76 * F_27 (
struct V_1 * V_2 , struct V_76 * V_77 )
{
struct V_78 * V_67 = V_2 -> V_67 ;
struct V_79 * V_80 = & V_67 -> V_81 . V_80 ;
struct V_76 * V_82 = V_77 ;
if ( ! V_77 )
return F_28 ( V_80 , F_29 ( * V_77 ) ,
V_83 ) ;
F_30 (connector, connector_list, head) {
if ( V_82 != V_77 ) {
struct V_84 * V_85 = V_82 -> V_85 ;
struct V_86 * V_87 = V_85 ? V_85 -> V_87 : NULL ;
if ( V_87 && V_87 -> V_88 -> V_2 == V_2 )
return V_82 ;
}
}
return NULL ;
}
void F_31 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_10 , V_11 = V_2 -> V_12 -> V_13 ;
F_32 ( V_90 , L_3 , V_2 -> V_52 , V_2 -> V_54 ,
( char * ) & V_2 -> V_12 -> V_12 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
struct V_16 * V_16 = & V_7 -> V_8 [ V_10 ] ;
F_32 ( V_90 , L_4 ,
V_10 , V_16 -> V_20 , V_16 -> V_23 ) ;
F_33 ( V_16 -> V_9 , V_90 ) ;
}
}
struct V_1 * F_34 ( struct V_78 * V_67 ,
struct V_3 * V_91 , const struct V_92 * V_93 )
{
unsigned int V_13 = F_35 ( V_93 -> V_94 ) ;
struct V_95 * V_96 [ 4 ] ;
struct V_1 * V_2 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
V_96 [ V_10 ] = F_36 ( V_91 , V_93 -> V_97 [ V_10 ] ) ;
if ( ! V_96 [ V_10 ] ) {
V_2 = F_37 ( - V_98 ) ;
goto error;
}
}
V_2 = F_38 ( V_67 , V_93 , V_96 ) ;
if ( F_39 ( V_2 ) )
goto error;
return V_2 ;
error:
while ( -- V_10 > 0 )
F_7 ( V_96 [ V_10 ] ) ;
return V_2 ;
}
struct V_1 * F_38 ( struct V_78 * V_67 ,
const struct V_92 * V_93 , struct V_95 * * V_96 )
{
const struct V_17 * V_12 = NULL ;
struct V_6 * V_7 = NULL ;
struct V_1 * V_2 = NULL ;
unsigned int V_23 = V_93 -> V_99 [ 0 ] ;
int V_71 , V_10 ;
F_5 ( L_5 ,
V_67 , V_93 , V_93 -> V_52 , V_93 -> V_54 ,
( char * ) & V_93 -> V_94 ) ;
V_12 = V_17 ( V_93 -> V_94 ) ;
for ( V_10 = 0 ; V_10 < F_40 ( V_100 ) ; V_10 ++ ) {
if ( V_100 [ V_10 ] == V_93 -> V_94 )
break;
}
if ( ! V_12 || V_10 == F_40 ( V_100 ) ) {
F_41 ( V_67 -> V_67 , L_6 ,
( char * ) & V_93 -> V_94 ) ;
V_71 = - V_101 ;
goto V_74;
}
V_7 = F_42 ( sizeof( * V_7 ) , V_102 ) ;
if ( ! V_7 ) {
V_71 = - V_103 ;
goto V_74;
}
V_2 = & V_7 -> V_14 ;
V_7 -> V_12 = V_12 ;
F_43 ( & V_7 -> V_72 ) ;
if ( V_12 -> V_13 == 2 && V_23 != V_93 -> V_99 [ 1 ] ) {
F_41 ( V_67 -> V_67 , L_7 ) ;
V_71 = - V_101 ;
goto V_74;
}
if ( V_23 % V_12 -> V_21 [ 0 ] ) {
F_41 ( V_67 -> V_67 ,
L_8 ,
V_23 , V_12 -> V_21 [ 0 ] ) ;
V_71 = - V_101 ;
goto V_74;
}
for ( V_10 = 0 ; V_10 < V_12 -> V_13 ; V_10 ++ ) {
struct V_16 * V_16 = & V_7 -> V_8 [ V_10 ] ;
unsigned int V_24 = V_10 == 0 ? 1 : V_12 -> V_24 ;
unsigned int V_104 ;
V_104 = V_23 * V_93 -> V_54 / V_24 ;
if ( V_104 > F_44 ( V_96 [ V_10 ] ) - V_93 -> V_105 [ V_10 ] ) {
F_41 ( V_67 -> V_67 ,
L_9 ,
V_96 [ V_10 ] -> V_104 - V_93 -> V_105 [ V_10 ] , V_104 ) ;
V_71 = - V_101 ;
goto V_74;
}
V_16 -> V_9 = V_96 [ V_10 ] ;
V_16 -> V_20 = V_93 -> V_105 [ V_10 ] ;
V_16 -> V_23 = V_23 ;
V_16 -> V_25 = 0 ;
}
F_45 ( V_67 , V_2 , V_93 ) ;
V_71 = F_46 ( V_67 , V_2 , & V_106 ) ;
if ( V_71 ) {
F_47 ( V_67 -> V_67 , L_10 , V_71 ) ;
goto V_74;
}
F_5 ( L_11 , V_2 -> V_14 . V_15 , V_2 ) ;
return V_2 ;
V_74:
F_8 ( V_7 ) ;
return F_37 ( V_71 ) ;
}
