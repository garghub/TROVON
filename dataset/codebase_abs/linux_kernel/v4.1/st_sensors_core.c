static inline T_1 F_1 ( const T_2 * V_1 )
{
return ( V_2 ) ( ( V_1 [ 0 ] | V_1 [ 1 ] << 8 | V_1 [ 2 ] << 16 ) << 8 ) >> 8 ;
}
static int F_2 ( struct V_3 * V_4 ,
T_2 V_5 , T_2 V_6 , T_2 V_7 )
{
int V_8 ;
T_2 V_9 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
V_8 = V_11 -> V_12 -> V_13 ( & V_11 -> V_14 , V_11 -> V_15 , V_5 , & V_9 ) ;
if ( V_8 < 0 )
goto V_16;
V_9 = ( ( V_9 & ( ~ V_6 ) ) | ( ( V_7 << F_4 ( V_6 ) ) & V_6 ) ) ;
V_8 = V_11 -> V_12 -> V_17 ( & V_11 -> V_14 , V_11 -> V_15 , V_5 , V_9 ) ;
V_16:
return V_8 ;
}
static int F_5 ( struct V_18 * V_19 ,
unsigned int V_20 , struct V_21 * V_22 )
{
int V_23 , V_24 = - V_25 ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
if ( V_19 -> V_20 . V_27 [ V_23 ] . V_28 == 0 )
goto V_29;
if ( V_19 -> V_20 . V_27 [ V_23 ] . V_28 == V_20 ) {
V_22 -> V_28 = V_19 -> V_20 . V_27 [ V_23 ] . V_28 ;
V_22 -> V_30 = V_19 -> V_20 . V_27 [ V_23 ] . V_30 ;
V_24 = 0 ;
break;
}
}
V_29:
return V_24 ;
}
int F_6 ( struct V_3 * V_4 , unsigned int V_20 )
{
int V_8 ;
struct V_21 V_22 = { 0 , 0 } ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
V_8 = F_5 ( V_11 -> V_19 , V_20 , & V_22 ) ;
if ( V_8 < 0 )
goto V_29;
if ( ( V_11 -> V_19 -> V_20 . V_31 ==
V_11 -> V_19 -> V_32 . V_31 ) &&
( V_11 -> V_19 -> V_20 . V_6 ==
V_11 -> V_19 -> V_32 . V_6 ) ) {
if ( V_11 -> V_33 == true ) {
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_20 . V_31 ,
V_11 -> V_19 -> V_20 . V_6 ,
V_22 . V_30 ) ;
} else {
V_8 = 0 ;
}
} else {
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_20 . V_31 ,
V_11 -> V_19 -> V_20 . V_6 ,
V_22 . V_30 ) ;
}
if ( V_8 >= 0 )
V_11 -> V_20 = V_22 . V_28 ;
V_29:
return V_8 ;
}
static int F_7 ( struct V_18 * V_19 ,
unsigned int V_34 , int * V_35 )
{
int V_23 , V_24 = - V_25 ;
for ( V_23 = 0 ; V_23 < V_36 ; V_23 ++ ) {
if ( V_19 -> V_34 . V_37 [ V_23 ] . V_38 == 0 )
goto V_29;
if ( V_19 -> V_34 . V_37 [ V_23 ] . V_38 == V_34 ) {
* V_35 = V_23 ;
V_24 = 0 ;
break;
}
}
V_29:
return V_24 ;
}
static int F_8 ( struct V_3 * V_4 , unsigned int V_34 )
{
int V_8 , V_23 = 0 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
V_8 = F_7 ( V_11 -> V_19 , V_34 , & V_23 ) ;
if ( V_8 < 0 )
goto V_39;
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_34 . V_31 ,
V_11 -> V_19 -> V_34 . V_6 ,
V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_30 ) ;
if ( V_8 < 0 )
goto V_39;
V_11 -> V_40 = (struct V_41 * )
& V_11 -> V_19 -> V_34 . V_37 [ V_23 ] ;
return V_8 ;
V_39:
F_9 ( & V_4 -> V_15 , L_1 ) ;
return V_8 ;
}
int F_10 ( struct V_3 * V_4 , bool V_42 )
{
T_2 V_43 ;
int V_8 = - V_25 ;
bool V_44 = false ;
struct V_21 V_22 = { 0 , 0 } ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
if ( V_42 ) {
V_43 = V_11 -> V_19 -> V_32 . V_45 ;
if ( ( V_11 -> V_19 -> V_20 . V_31 ==
V_11 -> V_19 -> V_32 . V_31 ) &&
( V_11 -> V_19 -> V_20 . V_6 ==
V_11 -> V_19 -> V_32 . V_6 ) ) {
V_8 = F_5 ( V_11 -> V_19 ,
V_11 -> V_20 , & V_22 ) ;
if ( V_8 < 0 )
goto V_46;
V_43 = V_22 . V_30 ;
V_44 = true ;
}
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_32 . V_31 ,
V_11 -> V_19 -> V_32 . V_6 , V_43 ) ;
if ( V_8 < 0 )
goto V_46;
V_11 -> V_33 = true ;
if ( V_44 )
V_11 -> V_20 = V_22 . V_28 ;
} else {
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_32 . V_31 ,
V_11 -> V_19 -> V_32 . V_6 ,
V_11 -> V_19 -> V_32 . V_47 ) ;
if ( V_8 < 0 )
goto V_46;
V_11 -> V_33 = false ;
}
V_46:
return V_8 ;
}
int F_11 ( struct V_3 * V_4 , T_2 V_48 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
return F_2 ( V_4 ,
V_11 -> V_19 -> V_49 . V_31 ,
V_11 -> V_19 -> V_49 . V_6 ,
V_48 ) ;
}
void F_12 ( struct V_3 * V_4 )
{
struct V_10 * V_50 = F_3 ( V_4 ) ;
int V_8 ;
V_50 -> V_51 = F_13 ( V_4 -> V_15 . V_52 , L_2 ) ;
if ( ! F_14 ( V_50 -> V_51 ) ) {
V_8 = F_15 ( V_50 -> V_51 ) ;
if ( V_8 != 0 )
F_16 ( & V_4 -> V_15 ,
L_3 ) ;
}
V_50 -> V_53 = F_13 ( V_4 -> V_15 . V_52 , L_4 ) ;
if ( ! F_14 ( V_50 -> V_53 ) ) {
V_8 = F_15 ( V_50 -> V_53 ) ;
if ( V_8 != 0 )
F_16 ( & V_4 -> V_15 ,
L_5 ) ;
}
}
void F_17 ( struct V_3 * V_4 )
{
struct V_10 * V_50 = F_3 ( V_4 ) ;
if ( ! F_14 ( V_50 -> V_51 ) )
F_18 ( V_50 -> V_51 ) ;
if ( ! F_14 ( V_50 -> V_53 ) )
F_18 ( V_50 -> V_53 ) ;
}
static int F_19 ( struct V_3 * V_4 ,
struct V_54 * V_50 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
switch ( V_50 -> V_55 ) {
case 1 :
if ( V_11 -> V_19 -> V_56 . V_57 == 0 ) {
F_9 ( & V_4 -> V_15 ,
L_6 ) ;
return - V_25 ;
}
V_11 -> V_55 = 1 ;
break;
case 2 :
if ( V_11 -> V_19 -> V_56 . V_58 == 0 ) {
F_9 ( & V_4 -> V_15 ,
L_7 ) ;
return - V_25 ;
}
V_11 -> V_55 = 2 ;
break;
default:
F_9 ( & V_4 -> V_15 , L_8 ) ;
return - V_25 ;
}
return 0 ;
}
static struct V_54 * F_20 ( struct V_59 * V_15 ,
struct V_54 * V_60 )
{
struct V_54 * V_50 ;
struct V_61 * V_62 = V_15 -> V_63 ;
T_1 V_64 ;
if ( ! V_62 )
return NULL ;
V_50 = F_21 ( V_15 , sizeof( * V_50 ) , V_65 ) ;
if ( ! F_22 ( V_62 , L_9 , & V_64 ) && ( V_64 <= 2 ) )
V_50 -> V_55 = ( T_2 ) V_64 ;
else
V_50 -> V_55 = V_60 ? V_60 -> V_55 : 1 ;
return V_50 ;
}
static struct V_54 * F_20 ( struct V_59 * V_15 ,
struct V_54 * V_60 )
{
return NULL ;
}
int F_23 ( struct V_3 * V_4 ,
struct V_54 * V_50 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
struct V_54 * V_66 ;
int V_8 = 0 ;
V_66 = F_20 ( V_4 -> V_15 . V_52 , V_50 ) ;
if ( V_66 )
V_50 = V_66 ;
if ( V_50 ) {
V_8 = F_19 ( V_4 , V_50 ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_8 = F_10 ( V_4 , false ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_11 -> V_40 ) {
V_8 = F_8 ( V_4 ,
V_11 -> V_40 -> V_38 ) ;
if ( V_8 < 0 )
return V_8 ;
} else
F_24 ( & V_4 -> V_15 , L_10 ) ;
V_8 = F_6 ( V_4 , V_11 -> V_20 ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_67 . V_31 ,
V_11 -> V_19 -> V_67 . V_6 , true ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_11 ( V_4 , V_68 ) ;
return V_8 ;
}
int F_25 ( struct V_3 * V_4 , bool V_42 )
{
int V_8 ;
T_2 V_69 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
if ( ! V_11 -> V_19 -> V_56 . V_31 )
return 0 ;
if ( V_11 -> V_19 -> V_56 . V_70 . V_71 > 0 ) {
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_56 . V_70 . V_71 ,
V_11 -> V_19 -> V_56 . V_70 . V_72 ,
( int ) V_42 ) ;
if ( V_8 < 0 )
goto V_73;
}
if ( V_11 -> V_55 == 1 )
V_69 = V_11 -> V_19 -> V_56 . V_57 ;
else
V_69 = V_11 -> V_19 -> V_56 . V_58 ;
V_8 = F_2 ( V_4 ,
V_11 -> V_19 -> V_56 . V_31 ,
V_69 , ( int ) V_42 ) ;
V_73:
return V_8 ;
}
int F_26 ( struct V_3 * V_4 , int V_74 )
{
int V_8 = - V_25 , V_23 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
for ( V_23 = 0 ; V_23 < V_36 ; V_23 ++ ) {
if ( ( V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_75 == V_74 ) &&
( V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_75 != 0 ) ) {
V_8 = 0 ;
break;
}
}
if ( V_8 < 0 )
goto V_76;
V_8 = F_8 ( V_4 ,
V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_38 ) ;
V_76:
return V_8 ;
}
static int F_27 ( struct V_3 * V_4 ,
struct V_77 const * V_78 , int * V_7 )
{
int V_8 ;
T_2 * V_79 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
unsigned int V_80 = V_78 -> V_81 . V_82 >> 3 ;
V_79 = F_28 ( V_80 , V_65 ) ;
if ( ! V_79 )
return - V_83 ;
V_8 = V_11 -> V_12 -> V_84 ( & V_11 -> V_14 , V_11 -> V_15 ,
V_78 -> V_85 , V_80 ,
V_79 , V_11 -> V_86 ) ;
if ( V_8 < 0 )
goto V_87;
if ( V_80 == 2 )
* V_7 = ( V_88 ) F_29 ( V_79 ) ;
else if ( V_80 == 3 )
* V_7 = ( V_2 ) F_1 ( V_79 ) ;
V_87:
F_30 ( V_79 ) ;
return V_8 ;
}
int F_31 ( struct V_3 * V_4 ,
struct V_77 const * V_78 , int * V_64 )
{
int V_8 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_32 ( & V_4 -> V_89 ) ;
if ( V_4 -> V_90 == V_91 ) {
V_8 = - V_92 ;
goto V_93;
} else {
V_8 = F_10 ( V_4 , true ) ;
if ( V_8 < 0 )
goto V_93;
F_33 ( ( V_11 -> V_19 -> V_94 * 1000 ) / V_11 -> V_20 ) ;
V_8 = F_27 ( V_4 , V_78 , V_64 ) ;
if ( V_8 < 0 )
goto V_93;
* V_64 = * V_64 >> V_78 -> V_81 . V_95 ;
V_8 = F_10 ( V_4 , false ) ;
}
V_93:
F_34 ( & V_4 -> V_89 ) ;
return V_8 ;
}
int F_35 ( struct V_3 * V_4 ,
int V_96 ,
const struct V_18 * V_19 )
{
T_2 V_97 ;
int V_23 , V_98 , V_8 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
V_8 = V_11 -> V_12 -> V_13 ( & V_11 -> V_14 , V_11 -> V_15 ,
V_99 , & V_97 ) ;
if ( V_8 < 0 ) {
F_9 ( & V_4 -> V_15 , L_11 ) ;
goto V_100;
}
for ( V_23 = 0 ; V_23 < V_96 ; V_23 ++ ) {
if ( V_19 [ V_23 ] . V_97 == V_97 )
break;
}
if ( V_23 == V_96 )
goto V_101;
for ( V_98 = 0 ; V_98 < F_36 ( V_19 [ V_23 ] . V_102 ) ; V_98 ++ ) {
if ( strcmp ( V_4 -> V_103 ,
& V_19 [ V_23 ] . V_102 [ V_98 ] [ 0 ] ) == 0 )
break;
}
if ( V_98 == F_36 ( V_19 [ V_23 ] . V_102 ) ) {
F_9 ( & V_4 -> V_15 , L_12 ) ;
goto V_104;
}
V_11 -> V_19 =
(struct V_18 * ) & V_19 [ V_23 ] ;
return V_23 ;
V_101:
F_9 ( & V_4 -> V_15 , L_13 , V_97 ) ;
V_104:
V_8 = - V_105 ;
V_100:
return V_8 ;
}
T_3 F_37 ( struct V_59 * V_15 ,
struct V_106 * V_107 , char * V_108 )
{
int V_23 , V_109 = 0 ;
struct V_3 * V_4 = F_38 ( V_15 ) ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_32 ( & V_4 -> V_89 ) ;
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) {
if ( V_11 -> V_19 -> V_20 . V_27 [ V_23 ] . V_28 == 0 )
break;
V_109 += F_39 ( V_108 + V_109 , V_110 - V_109 , L_14 ,
V_11 -> V_19 -> V_20 . V_27 [ V_23 ] . V_28 ) ;
}
F_34 ( & V_4 -> V_89 ) ;
V_108 [ V_109 - 1 ] = '\n' ;
return V_109 ;
}
T_3 F_40 ( struct V_59 * V_15 ,
struct V_106 * V_107 , char * V_108 )
{
int V_23 , V_109 = 0 ;
struct V_3 * V_4 = F_38 ( V_15 ) ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_32 ( & V_4 -> V_89 ) ;
for ( V_23 = 0 ; V_23 < V_36 ; V_23 ++ ) {
if ( V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_38 == 0 )
break;
V_109 += F_39 ( V_108 + V_109 , V_110 - V_109 , L_15 ,
V_11 -> V_19 -> V_34 . V_37 [ V_23 ] . V_75 ) ;
}
F_34 ( & V_4 -> V_89 ) ;
V_108 [ V_109 - 1 ] = '\n' ;
return V_109 ;
}
