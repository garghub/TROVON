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
int V_7 , V_15 , V_16 ;
T_1 V_6 ;
for ( V_15 = 0 ; V_15 < F_7 ( V_17 ) ; V_15 ++ ) {
for ( V_16 = 0 ; V_16 < V_18 ; V_16 ++ ) {
if ( V_14 == V_17 [ V_15 ] . V_14 [ V_16 ] )
break;
}
if ( V_16 < V_18 )
break;
}
if ( V_15 == F_7 ( V_17 ) ) {
F_3 ( V_2 -> V_11 , L_3 , V_14 ) ;
return - V_19 ;
}
V_7 = V_2 -> V_9 -> V_10 ( V_2 -> V_11 , V_20 , sizeof( V_6 ) ,
& V_6 ) ;
if ( V_7 < 0 ) {
F_3 ( V_2 -> V_11 , L_4 ) ;
return V_7 ;
}
if ( V_6 != V_17 [ V_15 ] . V_21 ) {
F_3 ( V_2 -> V_11 , L_5 , V_6 ) ;
return - V_19 ;
}
V_2 -> V_22 = & V_17 [ V_15 ] ;
return 0 ;
}
static int F_8 ( struct V_23 * V_24 ,
T_2 V_25 )
{
enum V_26 V_14 = V_24 -> V_14 ;
int V_15 , V_7 ;
T_1 V_5 ;
for ( V_15 = 0 ; V_15 < V_27 ; V_15 ++ )
if ( V_28 [ V_14 ] . V_29 [ V_15 ] . V_25 == V_25 )
break;
if ( V_15 == V_27 )
return - V_30 ;
V_5 = V_28 [ V_14 ] . V_29 [ V_15 ] . V_5 ;
V_7 = F_1 ( V_24 -> V_2 ,
V_28 [ V_14 ] . V_31 . V_3 ,
V_28 [ V_14 ] . V_31 . V_4 ,
V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_24 -> V_25 = V_25 ;
return 0 ;
}
static int F_9 ( struct V_23 * V_24 , T_3 V_32 ,
T_1 * V_5 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_33 ; V_15 ++ )
if ( V_34 [ V_24 -> V_14 ] . V_35 [ V_15 ] . V_36 == V_32 )
break;
if ( V_15 == V_33 )
return - V_30 ;
* V_5 = V_34 [ V_24 -> V_14 ] . V_35 [ V_15 ] . V_5 ;
V_24 -> V_32 = V_32 ;
return 0 ;
}
static int F_10 ( struct V_23 * V_24 , T_3 V_32 )
{
enum V_26 V_14 = V_24 -> V_14 ;
int V_7 ;
T_1 V_5 ;
V_7 = F_9 ( V_24 , V_32 , & V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_1 ( V_24 -> V_2 ,
V_34 [ V_14 ] . V_31 . V_3 ,
V_34 [ V_14 ] . V_31 . V_4 ,
V_5 ) ;
}
int F_11 ( struct V_23 * V_24 )
{
int V_7 ;
V_7 = F_10 ( V_24 , V_24 -> V_32 ) ;
if ( V_7 < 0 )
return V_7 ;
V_24 -> V_2 -> V_37 |= F_12 ( V_24 -> V_14 ) ;
return 0 ;
}
int F_13 ( struct V_23 * V_24 )
{
enum V_26 V_14 = V_24 -> V_14 ;
int V_7 ;
V_7 = F_1 ( V_24 -> V_2 ,
V_34 [ V_14 ] . V_31 . V_3 ,
V_34 [ V_14 ] . V_31 . V_4 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
V_24 -> V_2 -> V_37 &= ~ F_12 ( V_14 ) ;
return 0 ;
}
static int F_14 ( struct V_23 * V_24 ,
T_1 V_3 , int * V_5 )
{
int V_7 , V_38 ;
T_4 V_6 ;
V_7 = F_11 ( V_24 ) ;
if ( V_7 < 0 )
return V_7 ;
V_38 = 1000000 / V_24 -> V_32 ;
F_15 ( V_38 , 2 * V_38 ) ;
V_7 = V_24 -> V_2 -> V_9 -> V_10 ( V_24 -> V_2 -> V_11 , V_3 , sizeof( V_6 ) ,
( T_1 * ) & V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
F_13 ( V_24 ) ;
* V_5 = ( V_39 ) V_6 ;
return V_40 ;
}
static int F_16 ( struct V_41 * V_41 ,
struct V_42 const * V_43 ,
int * V_5 , int * V_44 , long V_4 )
{
struct V_23 * V_24 = F_17 ( V_41 ) ;
int V_45 ;
switch ( V_4 ) {
case V_46 :
V_45 = F_18 ( V_41 ) ;
if ( V_45 )
break;
V_45 = F_14 ( V_24 , V_43 -> V_47 , V_5 ) ;
F_19 ( V_41 ) ;
break;
case V_48 :
* V_5 = V_24 -> V_32 ;
V_45 = V_40 ;
break;
case V_49 :
* V_5 = 0 ;
* V_44 = V_24 -> V_25 ;
V_45 = V_50 ;
break;
default:
V_45 = - V_30 ;
break;
}
return V_45 ;
}
static int F_20 ( struct V_41 * V_41 ,
struct V_42 const * V_51 ,
int V_5 , int V_44 , long V_4 )
{
struct V_23 * V_24 = F_17 ( V_41 ) ;
int V_7 ;
V_7 = F_18 ( V_41 ) ;
if ( V_7 )
return V_7 ;
switch ( V_4 ) {
case V_49 :
V_7 = F_8 ( V_24 , V_44 ) ;
break;
case V_48 : {
T_1 V_6 ;
V_7 = F_9 ( V_24 , V_5 , & V_6 ) ;
break;
}
default:
V_7 = - V_30 ;
break;
}
F_19 ( V_41 ) ;
return V_7 ;
}
static int F_21 ( struct V_41 * V_41 , unsigned int V_5 )
{
struct V_23 * V_24 = F_17 ( V_41 ) ;
struct V_1 * V_2 = V_24 -> V_2 ;
int V_7 , V_52 ;
V_52 = V_2 -> V_22 -> V_53 / V_54 ;
if ( V_5 < 1 || V_5 > V_52 )
return - V_30 ;
V_7 = F_22 ( V_24 , V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
V_24 -> V_55 = V_5 ;
return 0 ;
}
static T_5
F_23 ( struct V_56 * V_11 ,
struct V_57 * V_58 ,
char * V_59 )
{
struct V_23 * V_24 = F_17 ( F_24 ( V_11 ) ) ;
enum V_26 V_14 = V_24 -> V_14 ;
int V_15 , V_60 = 0 ;
for ( V_15 = 0 ; V_15 < V_33 ; V_15 ++ )
V_60 += F_25 ( V_59 + V_60 , V_61 - V_60 , L_6 ,
V_34 [ V_14 ] . V_35 [ V_15 ] . V_36 ) ;
V_59 [ V_60 - 1 ] = '\n' ;
return V_60 ;
}
static T_5 F_26 ( struct V_56 * V_11 ,
struct V_57 * V_58 ,
char * V_59 )
{
struct V_23 * V_24 = F_17 ( F_24 ( V_11 ) ) ;
enum V_26 V_14 = V_24 -> V_14 ;
int V_15 , V_60 = 0 ;
for ( V_15 = 0 ; V_15 < V_27 ; V_15 ++ )
V_60 += F_25 ( V_59 + V_60 , V_61 - V_60 , L_7 ,
V_28 [ V_14 ] . V_29 [ V_15 ] . V_25 ) ;
V_59 [ V_60 - 1 ] = '\n' ;
return V_60 ;
}
static int F_27 ( struct V_1 * V_2 , int * V_62 )
{
struct V_63 * V_64 = V_2 -> V_11 -> V_65 ;
if ( ! V_64 )
return - V_30 ;
return F_28 ( V_64 , L_8 , V_62 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_1 * V_66 )
{
int V_7 = 0 , V_62 ;
if ( F_27 ( V_2 , & V_62 ) < 0 ) {
struct V_67 * V_68 ;
struct V_56 * V_11 = V_2 -> V_11 ;
V_68 = (struct V_67 * ) V_11 -> V_69 ;
V_62 = V_68 ? V_68 -> V_70 : 1 ;
}
switch ( V_62 ) {
case 1 :
* V_66 = V_71 ;
break;
case 2 :
* V_66 = V_72 ;
break;
default:
F_3 ( V_2 -> V_11 , L_9 ) ;
V_7 = - V_30 ;
break;
}
return V_7 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_1 V_6 , V_73 ;
int V_7 ;
V_6 = V_74 ;
V_7 = V_2 -> V_9 -> V_13 ( V_2 -> V_11 , V_75 , sizeof( V_6 ) ,
& V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
F_31 ( 200 ) ;
V_7 = F_1 ( V_2 , V_76 ,
V_77 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_78 ,
V_79 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_1 ( V_2 , V_80 ,
V_81 , 1 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_29 ( V_2 , & V_73 ) ;
if ( V_7 < 0 )
return V_7 ;
return F_1 ( V_2 , V_73 ,
V_82 , 1 ) ;
}
static struct V_41 * F_32 ( struct V_1 * V_2 ,
enum V_26 V_14 ,
const char * V_83 )
{
struct V_23 * V_24 ;
struct V_41 * V_41 ;
V_41 = F_33 ( V_2 -> V_11 , sizeof( * V_24 ) ) ;
if ( ! V_41 )
return NULL ;
V_41 -> V_84 = V_85 ;
V_41 -> V_11 . V_86 = V_2 -> V_11 ;
V_41 -> V_87 = V_88 ;
V_24 = F_17 ( V_41 ) ;
V_24 -> V_14 = V_14 ;
V_24 -> V_2 = V_2 ;
V_24 -> V_32 = V_34 [ V_14 ] . V_35 [ 0 ] . V_36 ;
V_24 -> V_25 = V_28 [ V_14 ] . V_29 [ 0 ] . V_25 ;
V_24 -> V_55 = 1 ;
switch ( V_14 ) {
case V_89 :
V_41 -> V_90 = V_91 ;
V_41 -> V_92 = F_7 ( V_91 ) ;
V_41 -> V_93 = & V_94 ;
V_24 -> V_95 = V_96 ;
F_25 ( V_24 -> V_83 , sizeof( V_24 -> V_83 ) , L_10 ,
V_83 ) ;
break;
case V_97 :
V_41 -> V_90 = V_98 ;
V_41 -> V_92 = F_7 ( V_98 ) ;
V_41 -> V_93 = & V_99 ;
V_24 -> V_95 = V_100 ;
F_25 ( V_24 -> V_83 , sizeof( V_24 -> V_83 ) , L_11 ,
V_83 ) ;
break;
default:
return NULL ;
}
V_41 -> V_83 = V_24 -> V_83 ;
return V_41 ;
}
int F_34 ( struct V_56 * V_11 , int V_101 , int V_102 , const char * V_83 ,
const struct V_103 * V_104 )
{
struct V_1 * V_2 ;
int V_15 , V_7 ;
V_2 = F_35 ( V_11 , sizeof( * V_2 ) , V_105 ) ;
if ( ! V_2 )
return - V_106 ;
F_36 ( V_11 , ( void * ) V_2 ) ;
F_37 ( & V_2 -> V_8 ) ;
F_37 ( & V_2 -> V_107 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_101 = V_101 ;
V_2 -> V_9 = V_104 ;
V_7 = F_6 ( V_2 , V_102 ) ;
if ( V_7 < 0 )
return V_7 ;
for ( V_15 = 0 ; V_15 < V_108 ; V_15 ++ ) {
V_2 -> V_109 [ V_15 ] = F_32 ( V_2 , V_15 , V_83 ) ;
if ( ! V_2 -> V_109 [ V_15 ] )
return - V_106 ;
}
V_7 = F_30 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
if ( V_2 -> V_101 > 0 ) {
V_7 = F_38 ( V_2 ) ;
if ( V_7 < 0 )
return V_7 ;
}
for ( V_15 = 0 ; V_15 < V_108 ; V_15 ++ ) {
V_7 = F_39 ( V_2 -> V_11 , V_2 -> V_109 [ V_15 ] ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static int T_6 F_40 ( struct V_56 * V_11 )
{
struct V_1 * V_2 = F_24 ( V_11 ) ;
struct V_23 * V_24 ;
int V_15 , V_7 = 0 ;
for ( V_15 = 0 ; V_15 < V_108 ; V_15 ++ ) {
V_24 = F_17 ( V_2 -> V_109 [ V_15 ] ) ;
if ( ! ( V_2 -> V_37 & F_12 ( V_24 -> V_14 ) ) )
continue;
V_7 = F_1 ( V_2 ,
V_34 [ V_24 -> V_14 ] . V_31 . V_3 ,
V_34 [ V_24 -> V_14 ] . V_31 . V_4 , 0 ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_2 -> V_110 != V_111 )
V_7 = F_41 ( V_2 ) ;
return V_7 ;
}
static int T_6 F_42 ( struct V_56 * V_11 )
{
struct V_1 * V_2 = F_24 ( V_11 ) ;
struct V_23 * V_24 ;
int V_15 , V_7 = 0 ;
for ( V_15 = 0 ; V_15 < V_108 ; V_15 ++ ) {
V_24 = F_17 ( V_2 -> V_109 [ V_15 ] ) ;
if ( ! ( V_2 -> V_37 & F_12 ( V_24 -> V_14 ) ) )
continue;
V_7 = F_10 ( V_24 , V_24 -> V_32 ) ;
if ( V_7 < 0 )
return V_7 ;
}
if ( V_2 -> V_37 )
V_7 = F_43 ( V_2 , V_112 ) ;
return V_7 ;
}
