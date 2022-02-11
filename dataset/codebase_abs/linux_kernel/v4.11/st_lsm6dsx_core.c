int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 ,
T_1 V_5 )
{
T_1 V_6 ;
int V_7 ;
F_2 ( & V_2 -> V_8 ) ;
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_3 , sizeof( V_6 ) , & V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 , L_1 , V_3 ) ;
goto V_12;
}
V_6 = ( V_6 & ~ V_4 ) | ( ( V_5 << F_4 ( V_4 ) ) & V_4 ) ;
V_7 = V_2 -> V_9 -> V_13 ( V_2 -> V_11 , V_3 , sizeof( V_6 ) , & V_6 ) ;
if ( V_7 < 0 )
F_3 ( V_2 -> V_11 , L_2 , V_3 ) ;
V_12:
F_5 ( & V_2 -> V_8 ) ;
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 , int V_14 )
{
int V_7 , V_15 ;
T_1 V_6 ;
for ( V_15 = 0 ; V_15 < F_7 ( V_16 ) ; V_15 ++ ) {
if ( V_14 == V_16 [ V_15 ] . V_14 )
break;
}
if ( V_15 == F_7 ( V_16 ) ) {
F_3 ( V_2 -> V_11 , L_3 , V_14 ) ;
return - V_17 ;
}
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_18 , sizeof( V_6 ) ,
& V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 , L_4 ) ;
return V_7 ;
}
if ( V_6 != V_16 [ V_15 ] . V_19 ) {
F_3 ( V_2 -> V_11 , L_5 , V_6 ) ;
return - V_17 ;
}
V_2 -> V_20 = & V_16 [ V_15 ] ;
return 0 ;
}
static int F_8 ( struct V_21 * V_22 ,
T_2 V_23 )
{
enum V_24 V_14 = V_22 -> V_14 ;
int V_15 , V_7 ;
T_1 V_5 ;
for ( V_15 = 0 ; V_15 < V_25 ; V_15 ++ )
if ( V_26 [ V_14 ] . V_27 [ V_15 ] . V_23 == V_23 )
break;
if ( V_15 == V_25 )
return - V_28 ;
V_5 = V_26 [ V_14 ] . V_27 [ V_15 ] . V_5 ;
V_7 = F_1 ( V_22 -> V_2 ,
V_26 [ V_14 ] . V_29 . V_3 ,
V_26 [ V_14 ] . V_29 . V_4 ,
V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_22 -> V_23 = V_23 ;
return 0 ;
}
static int F_9 ( struct V_21 * V_22 , T_3 V_30 )
{
enum V_24 V_14 = V_22 -> V_14 ;
int V_15 , V_7 ;
T_1 V_5 ;
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ )
if ( V_32 [ V_14 ] . V_33 [ V_15 ] . V_34 == V_30 )
break;
if ( V_15 == V_31 )
return - V_28 ;
V_5 = V_32 [ V_14 ] . V_33 [ V_15 ] . V_5 ;
V_7 = F_1 ( V_22 -> V_2 ,
V_32 [ V_14 ] . V_29 . V_3 ,
V_32 [ V_14 ] . V_29 . V_4 ,
V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_22 -> V_30 = V_30 ;
return 0 ;
}
int F_10 ( struct V_21 * V_22 )
{
int V_7 ;
V_7 = F_9 ( V_22 , V_22 -> V_30 ) ;
if ( V_7 < 0 )
return V_7 ;
V_22 -> V_2 -> V_35 |= F_11 ( V_22 -> V_14 ) ;
return 0 ;
}
int F_12 ( struct V_21 * V_22 )
{
enum V_24 V_14 = V_22 -> V_14 ;
int V_7 ;
V_7 = F_1 ( V_22 -> V_2 ,
V_32 [ V_14 ] . V_29 . V_3 ,
V_32 [ V_14 ] . V_29 . V_4 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_22 -> V_2 -> V_35 &= ~ F_11 ( V_14 ) ;
return 0 ;
}
static int F_13 ( struct V_21 * V_22 ,
T_1 V_3 , int * V_5 )
{
int V_7 , V_36 ;
T_4 V_6 ;
V_7 = F_10 ( V_22 ) ;
if ( V_7 < 0 )
return V_7 ;
V_36 = 1000000 / V_22 -> V_30 ;
F_14 ( V_36 , 2 * V_36 ) ;
V_7 = V_22 -> V_2 -> V_9 -> V_10 ( V_22 -> V_2 -> V_11 , V_3 , sizeof( V_6 ) ,
( T_1 * ) & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
F_12 ( V_22 ) ;
* V_5 = ( V_37 ) V_6 ;
return V_38 ;
}
static int F_15 ( struct V_39 * V_39 ,
struct V_40 const * V_41 ,
int * V_5 , int * V_42 , long V_4 )
{
struct V_21 * V_22 = F_16 ( V_39 ) ;
int V_43 ;
switch ( V_4 ) {
case V_44 :
V_43 = F_17 ( V_39 ) ;
if ( V_43 )
break;
V_43 = F_13 ( V_22 , V_41 -> V_45 , V_5 ) ;
F_18 ( V_39 ) ;
break;
case V_46 :
* V_5 = V_22 -> V_30 ;
V_43 = V_38 ;
break;
case V_47 :
* V_5 = 0 ;
* V_42 = V_22 -> V_23 ;
V_43 = V_48 ;
break;
default:
V_43 = - V_28 ;
break;
}
return V_43 ;
}
static int F_19 ( struct V_39 * V_39 ,
struct V_40 const * V_49 ,
int V_5 , int V_42 , long V_4 )
{
struct V_21 * V_22 = F_16 ( V_39 ) ;
int V_7 ;
V_7 = F_17 ( V_39 ) ;
if ( V_7 )
return V_7 ;
switch ( V_4 ) {
case V_47 :
V_7 = F_8 ( V_22 , V_42 ) ;
break;
case V_46 :
V_7 = F_9 ( V_22 , V_5 ) ;
break;
default:
V_7 = - V_28 ;
break;
}
F_18 ( V_39 ) ;
return V_7 ;
}
static int F_20 ( struct V_39 * V_39 , unsigned int V_5 )
{
struct V_21 * V_22 = F_16 ( V_39 ) ;
struct V_1 * V_2 = V_22 -> V_2 ;
int V_7 , V_50 ;
V_50 = V_2 -> V_20 -> V_51 / V_52 ;
if ( V_5 < 1 || V_5 > V_50 )
return - V_28 ;
V_7 = F_21 ( V_22 , V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_22 -> V_53 = V_5 ;
return 0 ;
}
static T_5
F_22 ( struct V_54 * V_11 ,
struct V_55 * V_56 ,
char * V_57 )
{
struct V_21 * V_22 = F_16 ( F_23 ( V_11 ) ) ;
enum V_24 V_14 = V_22 -> V_14 ;
int V_15 , V_58 = 0 ;
for ( V_15 = 0 ; V_15 < V_31 ; V_15 ++ )
V_58 += F_24 ( V_57 + V_58 , V_59 - V_58 , L_6 ,
V_32 [ V_14 ] . V_33 [ V_15 ] . V_34 ) ;
V_57 [ V_58 - 1 ] = '\n' ;
return V_58 ;
}
static T_5 F_25 ( struct V_54 * V_11 ,
struct V_55 * V_56 ,
char * V_57 )
{
struct V_21 * V_22 = F_16 ( F_23 ( V_11 ) ) ;
enum V_24 V_14 = V_22 -> V_14 ;
int V_15 , V_58 = 0 ;
for ( V_15 = 0 ; V_15 < V_25 ; V_15 ++ )
V_58 += F_24 ( V_57 + V_58 , V_59 - V_58 , L_7 ,
V_26 [ V_14 ] . V_27 [ V_15 ] . V_23 ) ;
V_57 [ V_58 - 1 ] = '\n' ;
return V_58 ;
}
static int F_26 ( struct V_1 * V_2 , int * V_60 )
{
struct V_61 * V_62 = V_2 -> V_11 -> V_63 ;
int V_7 ;
if ( ! V_62 )
return - V_28 ;
V_7 = F_27 ( V_62 , L_8 , V_60 ) ;
if ( V_7 == - V_64 ) {
* V_60 = 1 ;
V_7 = 0 ;
}
return V_7 ;
}
static int F_28 ( struct V_1 * V_2 , T_1 * V_65 )
{
int V_7 = 0 , V_60 ;
if ( F_26 ( V_2 , & V_60 ) < 0 ) {
struct V_66 * V_67 ;
struct V_54 * V_11 = V_2 -> V_11 ;
V_67 = (struct V_66 * ) V_11 -> V_68 ;
V_60 = V_67 ? V_67 -> V_69 : 1 ;
}
switch ( V_60 ) {
case 1 :
* V_65 = V_70 ;
break;
case 2 :
* V_65 = V_71 ;
break;
default:
F_3 ( V_2 -> V_11 , L_9 ) ;
V_7 = - V_28 ;
break;
}
return V_7 ;
}
static int F_29 ( struct V_1 * V_2 )
{
T_1 V_6 , V_72 ;
int V_7 ;
V_6 = V_73 ;
V_7 = V_2 -> V_9 -> V_13 ( V_2 -> V_11 , V_74 , sizeof( V_6 ) ,
& V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
F_30 ( 200 ) ;
V_7 = F_1 ( V_2 , V_75 ,
V_76 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_77 ,
V_78 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_79 ,
V_80 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_28 ( V_2 , & V_72 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_1 ( V_2 , V_72 ,
V_81 , 1 ) ;
}
static struct V_39 * F_31 ( struct V_1 * V_2 ,
enum V_24 V_14 )
{
struct V_21 * V_22 ;
struct V_39 * V_39 ;
V_39 = F_32 ( V_2 -> V_11 , sizeof( * V_22 ) ) ;
if ( ! V_39 )
return NULL ;
V_39 -> V_82 = V_83 ;
V_39 -> V_11 . V_84 = V_2 -> V_11 ;
V_39 -> V_85 = V_86 ;
V_22 = F_16 ( V_39 ) ;
V_22 -> V_14 = V_14 ;
V_22 -> V_2 = V_2 ;
V_22 -> V_30 = V_32 [ V_14 ] . V_33 [ 0 ] . V_34 ;
V_22 -> V_23 = V_26 [ V_14 ] . V_27 [ 0 ] . V_23 ;
V_22 -> V_53 = 1 ;
switch ( V_14 ) {
case V_87 :
V_39 -> V_88 = V_89 ;
V_39 -> V_90 = F_7 ( V_89 ) ;
V_39 -> V_91 = L_10 ;
V_39 -> V_92 = & V_93 ;
V_22 -> V_94 = V_95 ;
break;
case V_96 :
V_39 -> V_88 = V_97 ;
V_39 -> V_90 = F_7 ( V_97 ) ;
V_39 -> V_91 = L_11 ;
V_39 -> V_92 = & V_98 ;
V_22 -> V_94 = V_99 ;
break;
default:
return NULL ;
}
return V_39 ;
}
int F_33 ( struct V_54 * V_11 , int V_100 , int V_101 ,
const struct V_102 * V_103 )
{
struct V_1 * V_2 ;
int V_15 , V_7 ;
V_2 = F_34 ( V_11 , sizeof( * V_2 ) , V_104 ) ;
if ( ! V_2 )
return - V_105 ;
F_35 ( V_11 , ( void * ) V_2 ) ;
F_36 ( & V_2 -> V_8 ) ;
F_36 ( & V_2 -> V_106 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_100 = V_100 ;
V_2 -> V_9 = V_103 ;
V_7 = F_6 ( V_2 , V_101 ) ;
if ( V_7 < 0 )
return V_7 ;
for ( V_15 = 0 ; V_15 < V_107 ; V_15 ++ ) {
V_2 -> V_108 [ V_15 ] = F_31 ( V_2 , V_15 ) ;
if ( ! V_2 -> V_108 [ V_15 ] )
return - V_105 ;
}
V_7 = F_29 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_2 -> V_100 > 0 ) {
V_7 = F_37 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
}
for ( V_15 = 0 ; V_15 < V_107 ; V_15 ++ ) {
V_7 = F_38 ( V_2 -> V_11 , V_2 -> V_108 [ V_15 ] ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
