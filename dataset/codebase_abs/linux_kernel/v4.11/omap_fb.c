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
int V_6 , V_19 = V_11 -> V_20 -> V_21 ;
F_7 ( L_1 , V_11 -> V_22 . V_23 , V_11 ) ;
F_8 ( V_11 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_24 * V_24 = & V_16 -> V_17 [ V_6 ] ;
F_9 ( V_24 -> V_18 ) ;
}
F_10 ( V_16 ) ;
}
static T_1 F_11 ( struct V_24 * V_24 ,
const struct V_25 * V_20 , int V_19 , int V_26 , int V_27 )
{
T_1 V_28 ;
V_28 = V_24 -> V_28
+ ( V_26 * V_20 -> V_29 [ V_19 ] / ( V_19 == 0 ? 1 : V_20 -> V_30 ) )
+ ( V_27 * V_24 -> V_31 / ( V_19 == 0 ? 1 : V_20 -> V_32 ) ) ;
return V_24 -> V_33 + V_28 ;
}
bool F_12 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
struct V_24 * V_24 = & V_16 -> V_17 [ 0 ] ;
return F_13 ( V_24 -> V_18 ) & V_34 ;
}
void F_14 ( struct V_10 * V_11 ,
struct V_35 * V_36 , struct V_37 * V_38 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
const struct V_25 * V_20 = V_16 -> V_20 ;
struct V_24 * V_24 = & V_16 -> V_17 [ 0 ] ;
T_1 V_26 , V_27 , V_39 = 0 ;
V_38 -> V_40 = V_16 -> V_8 ;
V_38 -> V_41 = V_36 -> V_42 ;
V_38 -> V_43 = V_36 -> V_44 ;
V_38 -> V_45 = V_36 -> V_46 ;
V_38 -> V_47 = V_36 -> V_48 ;
V_38 -> V_49 = V_36 -> V_50 ;
V_38 -> V_51 = V_36 -> V_52 ;
V_26 = V_36 -> V_53 ;
V_27 = V_36 -> V_54 ;
if ( F_13 ( V_24 -> V_18 ) & V_34 ) {
T_1 V_55 = V_36 -> V_50 ;
T_1 V_56 = V_36 -> V_52 ;
switch ( V_36 -> V_57 & V_58 ) {
default:
F_15 ( V_11 -> V_59 -> V_59 , L_2 ,
( T_1 ) V_36 -> V_57 ) ;
case 0 :
case V_60 :
V_39 = 0 ;
break;
case V_61 :
V_39 = V_62 | V_63 ;
break;
case V_64 :
V_39 = V_63 | V_65 ;
break;
case V_66 :
V_39 = V_62 | V_65 ;
break;
}
if ( V_36 -> V_57 & V_67 )
V_39 ^= V_63 ;
if ( V_36 -> V_57 & V_68 )
V_39 ^= V_65 ;
if ( V_39 & V_62 )
F_16 ( V_55 , V_56 ) ;
if ( V_39 & V_65 )
V_27 += V_56 - 1 ;
if ( V_39 & V_63 )
V_26 += V_55 - 1 ;
F_17 ( V_24 -> V_18 , V_39 , V_26 , V_27 , & V_38 -> V_33 ) ;
V_38 -> V_69 = V_70 ;
V_38 -> V_71 = F_18 ( V_24 -> V_18 , V_39 ) ;
} else {
switch ( V_36 -> V_57 & V_58 ) {
case 0 :
case V_60 :
break;
default:
F_19 ( V_11 -> V_59 -> V_59 ,
L_3 ,
V_36 -> V_57 ) ;
V_36 -> V_57 = 0 ;
break;
}
V_38 -> V_33 = F_11 ( V_24 , V_20 , 0 , V_26 , V_27 ) ;
V_38 -> V_69 = V_72 ;
V_38 -> V_71 = V_24 -> V_31 ;
}
V_38 -> V_71 /= V_20 -> V_29 [ 0 ] ;
if ( V_16 -> V_8 == V_73 ) {
V_24 = & V_16 -> V_17 [ 1 ] ;
if ( V_38 -> V_69 == V_70 ) {
F_20 ( ! ( F_13 ( V_24 -> V_18 ) & V_34 ) ) ;
F_17 ( V_24 -> V_18 , V_39 ,
V_26 / 2 , V_27 / 2 , & V_38 -> V_74 ) ;
} else {
V_38 -> V_74 = F_11 ( V_24 , V_20 , 1 , V_26 , V_27 ) ;
}
} else {
V_38 -> V_74 = 0 ;
}
}
int F_21 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_75 , V_6 , V_19 = V_11 -> V_20 -> V_21 ;
F_22 ( & V_16 -> V_76 ) ;
if ( V_16 -> V_77 > 0 ) {
V_16 -> V_77 ++ ;
F_23 ( & V_16 -> V_76 ) ;
return 0 ;
}
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_24 * V_24 = & V_16 -> V_17 [ V_6 ] ;
V_75 = F_24 ( V_24 -> V_18 , & V_24 -> V_33 , true ) ;
if ( V_75 )
goto V_78;
F_25 ( V_24 -> V_18 , V_79 ) ;
}
V_16 -> V_77 ++ ;
F_23 ( & V_16 -> V_76 ) ;
return 0 ;
V_78:
for ( V_6 -- ; V_6 >= 0 ; V_6 -- ) {
struct V_24 * V_24 = & V_16 -> V_17 [ V_6 ] ;
F_26 ( V_24 -> V_18 ) ;
V_24 -> V_33 = 0 ;
}
F_23 ( & V_16 -> V_76 ) ;
return V_75 ;
}
void F_27 ( struct V_10 * V_11 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_6 , V_19 = V_11 -> V_20 -> V_21 ;
F_22 ( & V_16 -> V_76 ) ;
V_16 -> V_77 -- ;
if ( V_16 -> V_77 > 0 ) {
F_23 ( & V_16 -> V_76 ) ;
return;
}
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_24 * V_24 = & V_16 -> V_17 [ V_6 ] ;
F_26 ( V_24 -> V_18 ) ;
V_24 -> V_33 = 0 ;
}
F_23 ( & V_16 -> V_76 ) ;
}
struct V_80 * F_28 (
struct V_10 * V_11 , struct V_80 * V_81 )
{
struct V_82 * V_59 = V_11 -> V_59 ;
struct V_83 * V_84 = & V_59 -> V_85 . V_84 ;
struct V_80 * V_86 = V_81 ;
if ( ! V_81 )
return F_29 ( V_84 , F_30 ( * V_81 ) ,
V_87 ) ;
F_31 (connector, connector_list, head) {
if ( V_86 != V_81 ) {
struct V_88 * V_89 = V_86 -> V_89 ;
struct V_90 * V_91 = V_89 ? V_89 -> V_91 : NULL ;
if ( V_91 && V_91 -> V_92 -> V_11 == V_11 )
return V_86 ;
}
}
return NULL ;
}
void F_32 ( struct V_10 * V_11 , struct V_93 * V_94 )
{
struct V_15 * V_16 = F_4 ( V_11 ) ;
int V_6 , V_19 = V_11 -> V_20 -> V_21 ;
F_33 ( V_94 , L_4 , V_11 -> V_49 , V_11 -> V_51 ,
( char * ) & V_11 -> V_20 -> V_20 ) ;
for ( V_6 = 0 ; V_6 < V_19 ; V_6 ++ ) {
struct V_24 * V_24 = & V_16 -> V_17 [ V_6 ] ;
F_33 ( V_94 , L_5 ,
V_6 , V_24 -> V_28 , V_24 -> V_31 ) ;
F_34 ( V_24 -> V_18 , V_94 ) ;
}
}
struct V_10 * F_35 ( struct V_82 * V_59 ,
struct V_12 * V_95 , const struct V_96 * V_97 )
{
unsigned int V_21 = F_36 ( V_97 -> V_9 ) ;
struct V_98 * V_99 [ 4 ] ;
struct V_10 * V_11 ;
int V_6 ;
for ( V_6 = 0 ; V_6 < V_21 ; V_6 ++ ) {
V_99 [ V_6 ] = F_37 ( V_95 , V_97 -> V_100 [ V_6 ] ) ;
if ( ! V_99 [ V_6 ] ) {
V_11 = F_38 ( - V_101 ) ;
goto error;
}
}
V_11 = F_39 ( V_59 , V_97 , V_99 ) ;
if ( F_40 ( V_11 ) )
goto error;
return V_11 ;
error:
while ( -- V_6 > 0 )
F_9 ( V_99 [ V_6 ] ) ;
return V_11 ;
}
struct V_10 * F_39 ( struct V_82 * V_59 ,
const struct V_96 * V_97 , struct V_98 * * V_99 )
{
const struct V_25 * V_20 = NULL ;
struct V_15 * V_16 = NULL ;
struct V_10 * V_11 = NULL ;
enum V_3 V_8 = 0 ;
unsigned int V_31 = V_97 -> V_102 [ 0 ] ;
int V_75 , V_6 ;
F_7 ( L_6 ,
V_59 , V_97 , V_97 -> V_49 , V_97 -> V_51 ,
( char * ) & V_97 -> V_9 ) ;
V_20 = V_25 ( V_97 -> V_9 ) ;
for ( V_6 = 0 ; V_6 < F_2 ( V_7 ) ; V_6 ++ ) {
if ( V_7 [ V_6 ] . V_9 == V_97 -> V_9 ) {
V_8 = V_7 [ V_6 ] . V_8 ;
break;
}
}
if ( ! V_20 || ! V_8 ) {
F_41 ( V_59 -> V_59 , L_7 ,
( char * ) & V_97 -> V_9 ) ;
V_75 = - V_103 ;
goto V_78;
}
V_16 = F_42 ( sizeof( * V_16 ) , V_104 ) ;
if ( ! V_16 ) {
V_75 = - V_105 ;
goto V_78;
}
V_11 = & V_16 -> V_22 ;
V_16 -> V_20 = V_20 ;
V_16 -> V_8 = V_8 ;
F_43 ( & V_16 -> V_76 ) ;
if ( V_20 -> V_21 == 2 && V_31 != V_97 -> V_102 [ 1 ] ) {
F_41 ( V_59 -> V_59 , L_8 ) ;
V_75 = - V_103 ;
goto V_78;
}
if ( V_31 % V_20 -> V_29 [ 0 ] ) {
F_41 ( V_59 -> V_59 ,
L_9 ,
V_31 , V_20 -> V_29 [ 0 ] ) ;
V_75 = - V_103 ;
goto V_78;
}
for ( V_6 = 0 ; V_6 < V_20 -> V_21 ; V_6 ++ ) {
struct V_24 * V_24 = & V_16 -> V_17 [ V_6 ] ;
unsigned int V_32 = V_6 == 0 ? 1 : V_20 -> V_32 ;
unsigned int V_106 ;
V_106 = V_31 * V_97 -> V_51 / V_32 ;
if ( V_106 > F_44 ( V_99 [ V_6 ] ) - V_97 -> V_107 [ V_6 ] ) {
F_41 ( V_59 -> V_59 ,
L_10 ,
V_99 [ V_6 ] -> V_106 - V_97 -> V_107 [ V_6 ] , V_106 ) ;
V_75 = - V_103 ;
goto V_78;
}
V_24 -> V_18 = V_99 [ V_6 ] ;
V_24 -> V_28 = V_97 -> V_107 [ V_6 ] ;
V_24 -> V_31 = V_31 ;
V_24 -> V_33 = 0 ;
}
F_45 ( V_59 , V_11 , V_97 ) ;
V_75 = F_46 ( V_59 , V_11 , & V_108 ) ;
if ( V_75 ) {
F_15 ( V_59 -> V_59 , L_11 , V_75 ) ;
goto V_78;
}
F_7 ( L_12 , V_11 -> V_22 . V_23 , V_11 ) ;
return V_11 ;
V_78:
F_10 ( V_16 ) ;
return F_38 ( V_75 ) ;
}
