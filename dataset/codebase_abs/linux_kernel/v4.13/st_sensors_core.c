static inline T_1 F_1 ( const T_2 * V_1 )
{
return ( V_2 ) ( ( V_1 [ 0 ] | V_1 [ 1 ] << 8 | V_1 [ 2 ] << 16 ) << 8 ) >> 8 ;
}
int F_2 ( struct V_3 * V_4 ,
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
int F_5 ( struct V_3 * V_4 ,
unsigned V_18 , unsigned V_19 ,
unsigned * V_20 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
T_2 V_21 ;
int V_8 ;
if ( ! V_20 )
return V_11 -> V_12 -> V_17 ( & V_11 -> V_14 , V_11 -> V_15 ,
( T_2 ) V_18 , ( T_2 ) V_19 ) ;
V_8 = V_11 -> V_12 -> V_13 ( & V_11 -> V_14 , V_11 -> V_15 , ( T_2 ) V_18 , & V_21 ) ;
if ( V_8 < 0 )
return V_8 ;
* V_20 = ( unsigned ) V_21 ;
return 0 ;
}
static int F_6 ( struct V_22 * V_23 ,
unsigned int V_24 , struct V_25 * V_26 )
{
int V_27 , V_28 = - V_29 ;
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ ) {
if ( V_23 -> V_24 . V_31 [ V_27 ] . V_32 == 0 )
goto V_33;
if ( V_23 -> V_24 . V_31 [ V_27 ] . V_32 == V_24 ) {
V_26 -> V_32 = V_23 -> V_24 . V_31 [ V_27 ] . V_32 ;
V_26 -> V_34 = V_23 -> V_24 . V_31 [ V_27 ] . V_34 ;
V_28 = 0 ;
break;
}
}
V_33:
return V_28 ;
}
int F_7 ( struct V_3 * V_4 , unsigned int V_24 )
{
int V_8 ;
struct V_25 V_26 = { 0 , 0 } ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
V_8 = F_6 ( V_11 -> V_23 , V_24 , & V_26 ) ;
if ( V_8 < 0 )
goto V_33;
if ( ( V_11 -> V_23 -> V_24 . V_35 ==
V_11 -> V_23 -> V_36 . V_35 ) &&
( V_11 -> V_23 -> V_24 . V_6 ==
V_11 -> V_23 -> V_36 . V_6 ) ) {
if ( V_11 -> V_37 == true ) {
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_24 . V_35 ,
V_11 -> V_23 -> V_24 . V_6 ,
V_26 . V_34 ) ;
} else {
V_8 = 0 ;
}
} else {
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_24 . V_35 ,
V_11 -> V_23 -> V_24 . V_6 ,
V_26 . V_34 ) ;
}
if ( V_8 >= 0 )
V_11 -> V_24 = V_26 . V_32 ;
V_33:
return V_8 ;
}
static int F_8 ( struct V_22 * V_23 ,
unsigned int V_38 , int * V_39 )
{
int V_27 , V_28 = - V_29 ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ ) {
if ( V_23 -> V_38 . V_41 [ V_27 ] . V_42 == 0 )
goto V_33;
if ( V_23 -> V_38 . V_41 [ V_27 ] . V_42 == V_38 ) {
* V_39 = V_27 ;
V_28 = 0 ;
break;
}
}
V_33:
return V_28 ;
}
static int F_9 ( struct V_3 * V_4 , unsigned int V_38 )
{
int V_8 , V_27 = 0 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
if ( V_11 -> V_23 -> V_38 . V_35 == 0 )
return 0 ;
V_8 = F_8 ( V_11 -> V_23 , V_38 , & V_27 ) ;
if ( V_8 < 0 )
goto V_43;
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_38 . V_35 ,
V_11 -> V_23 -> V_38 . V_6 ,
V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_34 ) ;
if ( V_8 < 0 )
goto V_43;
V_11 -> V_44 = (struct V_45 * )
& V_11 -> V_23 -> V_38 . V_41 [ V_27 ] ;
return V_8 ;
V_43:
F_10 ( & V_4 -> V_15 , L_1 ) ;
return V_8 ;
}
int F_11 ( struct V_3 * V_4 , bool V_46 )
{
T_2 V_47 ;
int V_8 = - V_29 ;
bool V_48 = false ;
struct V_25 V_26 = { 0 , 0 } ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
if ( V_46 ) {
V_47 = V_11 -> V_23 -> V_36 . V_49 ;
if ( ( V_11 -> V_23 -> V_24 . V_35 ==
V_11 -> V_23 -> V_36 . V_35 ) &&
( V_11 -> V_23 -> V_24 . V_6 ==
V_11 -> V_23 -> V_36 . V_6 ) ) {
V_8 = F_6 ( V_11 -> V_23 ,
V_11 -> V_24 , & V_26 ) ;
if ( V_8 < 0 )
goto V_50;
V_47 = V_26 . V_34 ;
V_48 = true ;
}
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_36 . V_35 ,
V_11 -> V_23 -> V_36 . V_6 , V_47 ) ;
if ( V_8 < 0 )
goto V_50;
V_11 -> V_37 = true ;
if ( V_48 )
V_11 -> V_24 = V_26 . V_32 ;
} else {
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_36 . V_35 ,
V_11 -> V_23 -> V_36 . V_6 ,
V_11 -> V_23 -> V_36 . V_51 ) ;
if ( V_8 < 0 )
goto V_50;
V_11 -> V_37 = false ;
}
V_50:
return V_8 ;
}
int F_12 ( struct V_3 * V_4 , T_2 V_52 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
return F_2 ( V_4 ,
V_11 -> V_23 -> V_53 . V_35 ,
V_11 -> V_23 -> V_53 . V_6 ,
V_52 ) ;
}
int F_13 ( struct V_3 * V_4 )
{
struct V_10 * V_54 = F_3 ( V_4 ) ;
int V_8 ;
V_54 -> V_55 = F_14 ( V_4 -> V_15 . V_56 , L_2 ) ;
if ( F_15 ( V_54 -> V_55 ) ) {
F_10 ( & V_4 -> V_15 , L_3 ) ;
return F_16 ( V_54 -> V_55 ) ;
}
V_8 = F_17 ( V_54 -> V_55 ) ;
if ( V_8 != 0 ) {
F_18 ( & V_4 -> V_15 ,
L_4 ) ;
return V_8 ;
}
V_54 -> V_57 = F_14 ( V_4 -> V_15 . V_56 , L_5 ) ;
if ( F_15 ( V_54 -> V_57 ) ) {
F_10 ( & V_4 -> V_15 , L_6 ) ;
V_8 = F_16 ( V_54 -> V_57 ) ;
goto V_58;
}
V_8 = F_17 ( V_54 -> V_57 ) ;
if ( V_8 != 0 ) {
F_18 ( & V_4 -> V_15 ,
L_7 ) ;
goto V_58;
}
return 0 ;
V_58:
F_19 ( V_54 -> V_55 ) ;
return V_8 ;
}
void F_20 ( struct V_3 * V_4 )
{
struct V_10 * V_54 = F_3 ( V_4 ) ;
F_19 ( V_54 -> V_55 ) ;
F_19 ( V_54 -> V_57 ) ;
}
static int F_21 ( struct V_3 * V_4 ,
struct V_59 * V_54 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
if ( V_11 -> V_23 -> V_60 . V_35 == 0 ) {
if ( V_54 -> V_61 )
F_22 ( & V_4 -> V_15 ,
L_8
L_9 ,
V_54 -> V_61 ) ;
return 0 ;
}
switch ( V_54 -> V_61 ) {
case 1 :
if ( V_11 -> V_23 -> V_60 . V_62 == 0 ) {
F_10 ( & V_4 -> V_15 ,
L_10 ) ;
return - V_29 ;
}
V_11 -> V_61 = 1 ;
break;
case 2 :
if ( V_11 -> V_23 -> V_60 . V_63 == 0 ) {
F_10 ( & V_4 -> V_15 ,
L_11 ) ;
return - V_29 ;
}
V_11 -> V_61 = 2 ;
break;
default:
F_10 ( & V_4 -> V_15 , L_12 ) ;
return - V_29 ;
}
if ( V_54 -> V_64 ) {
if ( ! V_11 -> V_23 -> V_60 . V_65 )
F_10 ( & V_4 -> V_15 ,
L_13 ) ;
else
V_11 -> V_66 = true ;
}
return 0 ;
}
static struct V_59 * F_23 ( struct V_67 * V_15 ,
struct V_59 * V_68 )
{
struct V_59 * V_54 ;
struct V_69 * V_70 = V_15 -> V_71 ;
T_1 V_72 ;
if ( ! V_70 )
return NULL ;
V_54 = F_24 ( V_15 , sizeof( * V_54 ) , V_73 ) ;
if ( ! F_25 ( V_70 , L_14 , & V_72 ) && ( V_72 <= 2 ) )
V_54 -> V_61 = ( T_2 ) V_72 ;
else
V_54 -> V_61 = V_68 ? V_68 -> V_61 : 0 ;
V_54 -> V_64 = F_26 ( V_70 , L_15 ) ;
return V_54 ;
}
static struct V_59 * F_23 ( struct V_67 * V_15 ,
struct V_59 * V_68 )
{
return NULL ;
}
int F_27 ( struct V_3 * V_4 ,
struct V_59 * V_54 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
struct V_59 * V_74 ;
int V_8 = 0 ;
V_74 = F_23 ( V_4 -> V_15 . V_56 , V_54 ) ;
if ( V_74 )
V_54 = V_74 ;
if ( V_54 ) {
V_8 = F_21 ( V_4 , V_54 ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_8 = F_11 ( V_4 , false ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_28 ( V_4 , false ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_11 -> V_44 ) {
V_8 = F_9 ( V_4 ,
V_11 -> V_44 -> V_42 ) ;
if ( V_8 < 0 )
return V_8 ;
} else
F_22 ( & V_4 -> V_15 , L_16 ) ;
V_8 = F_7 ( V_4 , V_11 -> V_24 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_11 -> V_23 -> V_75 . V_35 ) {
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_75 . V_35 ,
V_11 -> V_23 -> V_75 . V_6 , true ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_11 -> V_23 -> V_76 . V_35 ) {
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_76 . V_35 ,
V_11 -> V_23 -> V_76 . V_6 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_11 -> V_66 ) {
F_22 ( & V_4 -> V_15 ,
L_17 ) ;
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_60 . V_65 ,
V_11 -> V_23 -> V_60 . V_77 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_8 = F_12 ( V_4 , V_78 ) ;
return V_8 ;
}
int F_28 ( struct V_3 * V_4 , bool V_46 )
{
int V_8 ;
T_2 V_79 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
if ( ! V_11 -> V_23 -> V_60 . V_35 )
return 0 ;
if ( V_11 -> V_23 -> V_60 . V_80 . V_81 > 0 ) {
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_60 . V_80 . V_81 ,
V_11 -> V_23 -> V_60 . V_80 . V_82 ,
( int ) V_46 ) ;
if ( V_8 < 0 )
goto V_83;
}
if ( V_11 -> V_61 == 1 )
V_79 = V_11 -> V_23 -> V_60 . V_62 ;
else
V_79 = V_11 -> V_23 -> V_60 . V_63 ;
V_11 -> V_84 = V_46 ;
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_60 . V_35 ,
V_79 , ( int ) V_46 ) ;
V_83:
return V_8 ;
}
int F_29 ( struct V_3 * V_4 , int V_85 )
{
int V_8 = - V_29 , V_27 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ ) {
if ( ( V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_86 == V_85 ) &&
( V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_86 != 0 ) ) {
V_8 = 0 ;
break;
}
}
if ( V_8 < 0 )
goto V_87;
V_8 = F_9 ( V_4 ,
V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_42 ) ;
V_87:
return V_8 ;
}
static int F_30 ( struct V_3 * V_4 ,
struct V_88 const * V_89 , int * V_7 )
{
int V_8 ;
T_2 * V_90 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
unsigned int V_91 ;
V_91 = F_31 ( V_89 -> V_92 . V_93 +
V_89 -> V_92 . V_94 , 8 ) ;
V_90 = F_32 ( V_91 , V_73 ) ;
if ( ! V_90 )
return - V_95 ;
V_8 = V_11 -> V_12 -> V_96 ( & V_11 -> V_14 , V_11 -> V_15 ,
V_89 -> V_97 , V_91 ,
V_90 , V_11 -> V_98 ) ;
if ( V_8 < 0 )
goto V_99;
if ( V_91 == 1 )
* V_7 = ( V_100 ) * V_90 ;
else if ( V_91 == 2 )
* V_7 = ( V_101 ) F_33 ( V_90 ) ;
else if ( V_91 == 3 )
* V_7 = ( V_2 ) F_1 ( V_90 ) ;
V_99:
F_34 ( V_90 ) ;
return V_8 ;
}
int F_35 ( struct V_3 * V_4 ,
struct V_88 const * V_89 , int * V_72 )
{
int V_8 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_36 ( & V_4 -> V_102 ) ;
if ( V_4 -> V_103 == V_104 ) {
V_8 = - V_105 ;
goto V_106;
} else {
V_8 = F_11 ( V_4 , true ) ;
if ( V_8 < 0 )
goto V_106;
F_37 ( ( V_11 -> V_23 -> V_107 * 1000 ) / V_11 -> V_24 ) ;
V_8 = F_30 ( V_4 , V_89 , V_72 ) ;
if ( V_8 < 0 )
goto V_106;
* V_72 = * V_72 >> V_89 -> V_92 . V_94 ;
V_8 = F_11 ( V_4 , false ) ;
}
V_106:
F_38 ( & V_4 -> V_102 ) ;
return V_8 ;
}
static int F_39 ( struct V_3 * V_4 ,
const struct V_22 * V_23 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
struct V_69 * V_70 = V_11 -> V_15 -> V_71 ;
struct V_59 * V_54 ;
V_54 = (struct V_59 * ) V_11 -> V_15 -> V_108 ;
if ( ( ( V_70 && F_26 ( V_70 , L_18 ) ) ||
( V_54 && V_54 -> V_109 ) ) && V_23 -> V_110 . V_35 ) {
int V_8 ;
V_8 = V_11 -> V_12 -> V_17 ( & V_11 -> V_14 , V_11 -> V_15 ,
V_23 -> V_110 . V_35 ,
V_23 -> V_110 . V_34 ) ;
if ( V_8 < 0 ) {
F_10 ( & V_4 -> V_15 ,
L_19 ) ;
return V_8 ;
}
}
return 0 ;
}
int F_40 ( struct V_3 * V_4 ,
int V_111 ,
const struct V_22 * V_23 )
{
int V_27 , V_112 , V_8 = 0 ;
T_2 V_113 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
for ( V_27 = 0 ; V_27 < V_111 ; V_27 ++ ) {
for ( V_112 = 0 ; V_112 < V_114 ; V_112 ++ ) {
if ( strcmp ( V_4 -> V_115 ,
V_23 [ V_27 ] . V_116 [ V_112 ] ) == 0 ) {
break;
}
}
if ( V_112 < V_114 )
break;
}
if ( V_27 == V_111 ) {
F_10 ( & V_4 -> V_15 , L_20 ,
V_4 -> V_115 ) ;
return - V_117 ;
}
V_8 = F_39 ( V_4 , & V_23 [ V_27 ] ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_23 [ V_27 ] . V_118 ) {
V_8 = V_11 -> V_12 -> V_13 ( & V_11 -> V_14 , V_11 -> V_15 ,
V_23 [ V_27 ] . V_118 , & V_113 ) ;
if ( V_8 < 0 ) {
F_10 ( & V_4 -> V_15 ,
L_21 ) ;
return V_8 ;
}
if ( V_23 [ V_27 ] . V_113 != V_113 ) {
F_10 ( & V_4 -> V_15 ,
L_22 ,
V_4 -> V_115 , V_113 ) ;
return - V_29 ;
}
}
V_11 -> V_23 =
(struct V_22 * ) & V_23 [ V_27 ] ;
return V_27 ;
}
T_3 F_41 ( struct V_67 * V_15 ,
struct V_119 * V_120 , char * V_121 )
{
int V_27 , V_122 = 0 ;
struct V_3 * V_4 = F_42 ( V_15 ) ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_36 ( & V_4 -> V_102 ) ;
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ ) {
if ( V_11 -> V_23 -> V_24 . V_31 [ V_27 ] . V_32 == 0 )
break;
V_122 += F_43 ( V_121 + V_122 , V_123 - V_122 , L_23 ,
V_11 -> V_23 -> V_24 . V_31 [ V_27 ] . V_32 ) ;
}
F_38 ( & V_4 -> V_102 ) ;
V_121 [ V_122 - 1 ] = '\n' ;
return V_122 ;
}
T_3 F_44 ( struct V_67 * V_15 ,
struct V_119 * V_120 , char * V_121 )
{
int V_27 , V_122 = 0 , V_124 , V_125 ;
struct V_3 * V_4 = F_42 ( V_15 ) ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_36 ( & V_4 -> V_102 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ ) {
if ( V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_42 == 0 )
break;
V_124 = V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_86 / 1000000 ;
V_125 = V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_86 % 1000000 ;
V_122 += F_43 ( V_121 + V_122 , V_123 - V_122 , L_24 , V_124 , V_125 ) ;
}
F_38 ( & V_4 -> V_102 ) ;
V_121 [ V_122 - 1 ] = '\n' ;
return V_122 ;
}
