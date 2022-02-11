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
F_10 ( V_22 -> V_18 ) ;
}
F_11 ( V_16 ) ;
}
static T_1 F_12 ( struct V_22 * V_22 ,
const struct V_23 * V_23 , int V_19 , int V_24 , int V_25 )
{
T_1 V_26 ;
V_26 = V_22 -> V_26 +
( V_24 * V_23 -> V_17 [ V_19 ] . V_27 ) +
( V_25 * V_22 -> V_28 / V_23 -> V_17 [ V_19 ] . V_29 ) ;
return V_22 -> V_30 + V_26 ;
}
bool F_13 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
struct V_22 * V_22 = & V_16 -> V_17 [ 0 ] ;
return F_14 ( V_22 -> V_18 ) & V_31 ;
}
void F_15 ( struct V_10 * V_11 ,
struct V_32 * V_33 , struct V_34 * V_35 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
const struct V_23 * V_23 = V_16 -> V_23 ;
struct V_22 * V_22 = & V_16 -> V_17 [ 0 ] ;
T_1 V_24 , V_25 , V_36 = 0 ;
V_35 -> V_37 = V_23 -> V_8 ;
V_35 -> V_38 = V_33 -> V_39 ;
V_35 -> V_40 = V_33 -> V_41 ;
V_35 -> V_42 = V_33 -> V_43 ;
V_35 -> V_44 = V_33 -> V_45 ;
V_35 -> V_46 = V_33 -> V_47 ;
V_35 -> V_48 = V_33 -> V_49 ;
V_24 = V_33 -> V_50 ;
V_25 = V_33 -> V_51 ;
if ( F_14 ( V_22 -> V_18 ) & V_31 ) {
T_1 V_52 = V_33 -> V_47 ;
T_1 V_53 = V_33 -> V_49 ;
switch ( V_33 -> V_54 & V_55 ) {
default:
F_16 ( V_11 -> V_56 -> V_56 , L_2 ,
( T_1 ) V_33 -> V_54 ) ;
case 0 :
case V_57 :
V_36 = 0 ;
break;
case V_58 :
V_36 = V_59 | V_60 ;
break;
case V_61 :
V_36 = V_60 | V_62 ;
break;
case V_63 :
V_36 = V_59 | V_62 ;
break;
}
if ( V_33 -> V_54 & V_64 )
V_36 ^= V_60 ;
if ( V_33 -> V_54 & V_65 )
V_36 ^= V_62 ;
if ( V_36 & V_59 )
F_17 ( V_52 , V_53 ) ;
if ( V_36 & V_62 )
V_25 += V_53 - 1 ;
if ( V_36 & V_60 )
V_24 += V_52 - 1 ;
F_18 ( V_22 -> V_18 , V_36 , V_24 , V_25 , & V_35 -> V_30 ) ;
V_35 -> V_66 = V_67 ;
V_35 -> V_68 = F_19 ( V_22 -> V_18 , V_36 ) ;
} else {
switch ( V_33 -> V_54 & V_55 ) {
case 0 :
case V_57 :
break;
default:
F_20 ( V_11 -> V_56 -> V_56 ,
L_3 ,
V_33 -> V_54 ) ;
V_33 -> V_54 = 0 ;
break;
}
V_35 -> V_30 = F_12 ( V_22 , V_23 , 0 , V_24 , V_25 ) ;
V_35 -> V_66 = V_69 ;
V_35 -> V_68 = V_22 -> V_28 ;
}
V_35 -> V_68 /= V_23 -> V_17 [ 0 ] . V_27 ;
if ( V_23 -> V_8 == V_70 ) {
V_22 = & V_16 -> V_17 [ 1 ] ;
if ( V_35 -> V_66 == V_67 ) {
F_21 ( ! ( F_14 ( V_22 -> V_18 ) & V_31 ) ) ;
F_18 ( V_22 -> V_18 , V_36 ,
V_24 / 2 , V_25 / 2 , & V_35 -> V_71 ) ;
} else {
V_35 -> V_71 = F_12 ( V_22 , V_23 , 1 , V_24 , V_25 ) ;
}
} else {
V_35 -> V_71 = 0 ;
}
}
int F_22 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_72 , V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
F_23 ( & V_16 -> V_73 ) ;
if ( V_16 -> V_74 > 0 ) {
V_16 -> V_74 ++ ;
F_24 ( & V_16 -> V_73 ) ;
return 0 ;
}
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
V_72 = F_25 ( V_22 -> V_18 , & V_22 -> V_30 , true ) ;
if ( V_72 )
goto V_75;
F_26 ( V_22 -> V_18 , V_76 ) ;
}
V_16 -> V_74 ++ ;
F_24 ( & V_16 -> V_73 ) ;
return 0 ;
V_75:
for ( V_6 -- ; V_6 >= 0 ; V_6 -- ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
F_27 ( V_22 -> V_18 ) ;
V_22 -> V_30 = 0 ;
}
F_24 ( & V_16 -> V_73 ) ;
return V_72 ;
}
void F_28 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
F_23 ( & V_16 -> V_73 ) ;
V_16 -> V_74 -- ;
if ( V_16 -> V_74 > 0 ) {
F_24 ( & V_16 -> V_73 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
F_27 ( V_22 -> V_18 ) ;
V_22 -> V_30 = 0 ;
}
F_24 ( & V_16 -> V_73 ) ;
}
struct V_77 * F_29 (
struct V_10 * V_11 , struct V_77 * V_78 )
{
struct V_79 * V_56 = V_11 -> V_56 ;
struct V_80 * V_81 = & V_56 -> V_82 . V_81 ;
struct V_77 * V_83 = V_78 ;
if ( ! V_78 )
return F_30 ( V_81 , F_31 ( * V_78 ) ,
V_84 ) ;
F_32 (connector, connector_list, head) {
if ( V_83 != V_78 ) {
struct V_85 * V_86 = V_83 -> V_86 ;
struct V_87 * V_88 = V_86 ? V_86 -> V_88 : NULL ;
if ( V_88 && V_88 -> V_89 -> V_11 == V_11 )
return V_83 ;
}
}
return NULL ;
}
void F_33 ( struct V_10 * V_11 , struct V_90 * V_91 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_6 , V_19 = F_7 ( V_11 -> V_9 ) ;
F_34 ( V_91 , L_4 , V_11 -> V_46 , V_11 -> V_48 ,
( char * ) & V_11 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
F_34 ( V_91 , L_5 ,
V_6 , V_22 -> V_26 , V_22 -> V_28 ) ;
F_35 ( V_22 -> V_18 , V_91 ) ;
}
}
struct V_10 * F_36 ( struct V_79 * V_56 ,
struct V_12 * V_92 , const struct V_93 * V_94 )
{
struct V_95 * V_96 [ 4 ] ;
struct V_10 * V_11 ;
int V_72 ;
V_72 = F_37 ( V_92 , V_94 -> V_9 ,
V_96 , V_94 -> V_97 ) ;
if ( V_72 )
return F_38 ( V_72 ) ;
V_11 = F_39 ( V_56 , V_94 , V_96 ) ;
if ( F_40 ( V_11 ) ) {
int V_6 , V_19 = F_7 ( V_94 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ )
F_10 ( V_96 [ V_6 ] ) ;
return V_11 ;
}
return V_11 ;
}
struct V_10 * F_39 ( struct V_79 * V_56 ,
const struct V_93 * V_94 , struct V_95 * * V_96 )
{
struct V_15 * V_16 = NULL ;
struct V_10 * V_11 = NULL ;
const struct V_23 * V_23 = NULL ;
int V_72 , V_6 , V_19 = F_7 ( V_94 -> V_9 ) ;
F_8 ( L_6 ,
V_56 , V_94 , V_94 -> V_46 , V_94 -> V_48 ,
( char * ) & V_94 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ ) {
if ( V_7 [ V_6 ] . V_9 == V_94 -> V_9 ) {
V_23 = & V_7 [ V_6 ] ;
break;
}
}
if ( ! V_23 ) {
F_16 ( V_56 -> V_56 , L_7 ,
( char * ) & V_94 -> V_9 ) ;
V_72 = - V_98 ;
goto V_75;
}
V_16 = F_41 ( sizeof( * V_16 ) , V_99 ) ;
if ( ! V_16 ) {
V_72 = - V_100 ;
goto V_75;
}
V_11 = & V_16 -> V_20 ;
V_16 -> V_23 = V_23 ;
F_42 ( & V_16 -> V_73 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_22 * V_22 = & V_16 -> V_17 [ V_6 ] ;
int V_101 , V_28 = V_94 -> V_102 [ V_6 ] ;
if ( V_28 < ( V_94 -> V_46 * V_23 -> V_17 [ V_6 ] . V_27 ) ) {
F_16 ( V_56 -> V_56 , L_8 ,
V_28 , V_94 -> V_46 * V_23 -> V_17 [ V_6 ] . V_27 ) ;
V_72 = - V_98 ;
goto V_75;
}
if ( V_28 % V_23 -> V_17 [ V_6 ] . V_27 != 0 ) {
F_16 ( V_56 -> V_56 ,
L_9 ,
V_28 , V_23 -> V_17 [ V_6 ] . V_27 ) ;
V_72 = - V_98 ;
goto V_75;
}
V_101 = V_28 * V_94 -> V_48 / V_23 -> V_17 [ V_6 ] . V_29 ;
if ( V_101 > ( F_43 ( V_96 [ V_6 ] ) - V_94 -> V_103 [ V_6 ] ) ) {
F_16 ( V_56 -> V_56 , L_10 ,
V_96 [ V_6 ] -> V_101 - V_94 -> V_103 [ V_6 ] , V_101 ) ;
V_72 = - V_98 ;
goto V_75;
}
if ( V_6 > 0 && V_28 != V_94 -> V_102 [ V_6 - 1 ] ) {
F_16 ( V_56 -> V_56 ,
L_11 ,
V_28 , V_94 -> V_102 [ V_6 - 1 ] ) ;
V_72 = - V_98 ;
goto V_75;
}
V_22 -> V_18 = V_96 [ V_6 ] ;
V_22 -> V_26 = V_94 -> V_103 [ V_6 ] ;
V_22 -> V_28 = V_28 ;
V_22 -> V_30 = 0 ;
}
F_44 ( V_11 , V_94 ) ;
V_72 = F_45 ( V_56 , V_11 , & V_104 ) ;
if ( V_72 ) {
F_16 ( V_56 -> V_56 , L_12 , V_72 ) ;
goto V_75;
}
F_8 ( L_13 , V_11 -> V_20 . V_21 , V_11 ) ;
return V_11 ;
V_75:
F_11 ( V_16 ) ;
return F_38 ( V_72 ) ;
}
