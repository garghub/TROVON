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
if ( ! F_15 ( V_54 -> V_55 ) ) {
V_8 = F_16 ( V_54 -> V_55 ) ;
if ( V_8 != 0 ) {
F_17 ( & V_4 -> V_15 ,
L_3 ) ;
return V_8 ;
}
} else {
V_8 = F_18 ( V_54 -> V_55 ) ;
if ( V_8 != - V_57 )
return V_8 ;
}
V_54 -> V_58 = F_14 ( V_4 -> V_15 . V_56 , L_4 ) ;
if ( ! F_15 ( V_54 -> V_58 ) ) {
V_8 = F_16 ( V_54 -> V_58 ) ;
if ( V_8 != 0 ) {
F_17 ( & V_4 -> V_15 ,
L_5 ) ;
goto V_59;
}
} else {
V_8 = F_18 ( V_54 -> V_58 ) ;
if ( V_8 != - V_57 )
goto V_59;
}
return 0 ;
V_59:
if ( ! F_19 ( V_54 -> V_55 ) )
F_20 ( V_54 -> V_55 ) ;
return V_8 ;
}
void F_21 ( struct V_3 * V_4 )
{
struct V_10 * V_54 = F_3 ( V_4 ) ;
if ( ! F_19 ( V_54 -> V_55 ) )
F_20 ( V_54 -> V_55 ) ;
if ( ! F_19 ( V_54 -> V_58 ) )
F_20 ( V_54 -> V_58 ) ;
}
static int F_22 ( struct V_3 * V_4 ,
struct V_60 * V_54 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
if ( V_11 -> V_23 -> V_61 . V_35 == 0 ) {
if ( V_54 -> V_62 )
F_23 ( & V_4 -> V_15 ,
L_6
L_7 ,
V_54 -> V_62 ) ;
return 0 ;
}
switch ( V_54 -> V_62 ) {
case 1 :
if ( V_11 -> V_23 -> V_61 . V_63 == 0 ) {
F_10 ( & V_4 -> V_15 ,
L_8 ) ;
return - V_29 ;
}
V_11 -> V_62 = 1 ;
break;
case 2 :
if ( V_11 -> V_23 -> V_61 . V_64 == 0 ) {
F_10 ( & V_4 -> V_15 ,
L_9 ) ;
return - V_29 ;
}
V_11 -> V_62 = 2 ;
break;
default:
F_10 ( & V_4 -> V_15 , L_10 ) ;
return - V_29 ;
}
if ( V_54 -> V_65 ) {
if ( ! V_11 -> V_23 -> V_61 . V_66 )
F_10 ( & V_4 -> V_15 ,
L_11 ) ;
else
V_11 -> V_67 = true ;
}
return 0 ;
}
static struct V_60 * F_24 ( struct V_68 * V_15 ,
struct V_60 * V_69 )
{
struct V_60 * V_54 ;
struct V_70 * V_71 = V_15 -> V_72 ;
T_1 V_73 ;
if ( ! V_71 )
return NULL ;
V_54 = F_25 ( V_15 , sizeof( * V_54 ) , V_74 ) ;
if ( ! F_26 ( V_71 , L_12 , & V_73 ) && ( V_73 <= 2 ) )
V_54 -> V_62 = ( T_2 ) V_73 ;
else
V_54 -> V_62 = V_69 ? V_69 -> V_62 : 0 ;
V_54 -> V_65 = F_27 ( V_71 , L_13 ) ;
return V_54 ;
}
static struct V_60 * F_24 ( struct V_68 * V_15 ,
struct V_60 * V_69 )
{
return NULL ;
}
int F_28 ( struct V_3 * V_4 ,
struct V_60 * V_54 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
struct V_60 * V_75 ;
int V_8 = 0 ;
V_75 = F_24 ( V_4 -> V_15 . V_56 , V_54 ) ;
if ( V_75 )
V_54 = V_75 ;
if ( V_54 ) {
V_8 = F_22 ( V_4 , V_54 ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_8 = F_11 ( V_4 , false ) ;
if ( V_8 < 0 )
return V_8 ;
V_8 = F_29 ( V_4 , false ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_11 -> V_44 ) {
V_8 = F_9 ( V_4 ,
V_11 -> V_44 -> V_42 ) ;
if ( V_8 < 0 )
return V_8 ;
} else
F_23 ( & V_4 -> V_15 , L_14 ) ;
V_8 = F_7 ( V_4 , V_11 -> V_24 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_11 -> V_23 -> V_76 . V_35 ) {
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_76 . V_35 ,
V_11 -> V_23 -> V_76 . V_6 , true ) ;
if ( V_8 < 0 )
return V_8 ;
}
if ( V_11 -> V_67 ) {
F_23 ( & V_4 -> V_15 ,
L_15 ) ;
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_61 . V_66 ,
V_11 -> V_23 -> V_61 . V_77 , 1 ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_8 = F_12 ( V_4 , V_78 ) ;
return V_8 ;
}
int F_29 ( struct V_3 * V_4 , bool V_46 )
{
int V_8 ;
T_2 V_79 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
if ( ! V_11 -> V_23 -> V_61 . V_35 )
return 0 ;
if ( V_11 -> V_23 -> V_61 . V_80 . V_81 > 0 ) {
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_61 . V_80 . V_81 ,
V_11 -> V_23 -> V_61 . V_80 . V_82 ,
( int ) V_46 ) ;
if ( V_8 < 0 )
goto V_83;
}
if ( V_11 -> V_62 == 1 )
V_79 = V_11 -> V_23 -> V_61 . V_63 ;
else
V_79 = V_11 -> V_23 -> V_61 . V_64 ;
V_11 -> V_84 = V_46 ;
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_61 . V_35 ,
V_79 , ( int ) V_46 ) ;
V_83:
return V_8 ;
}
int F_30 ( struct V_3 * V_4 , int V_85 )
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
static int F_31 ( struct V_3 * V_4 ,
struct V_88 const * V_89 , int * V_7 )
{
int V_8 ;
T_2 * V_90 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
unsigned int V_91 = V_89 -> V_92 . V_93 >> 3 ;
V_90 = F_32 ( V_91 , V_74 ) ;
if ( ! V_90 )
return - V_94 ;
V_8 = V_11 -> V_12 -> V_95 ( & V_11 -> V_14 , V_11 -> V_15 ,
V_89 -> V_96 , V_91 ,
V_90 , V_11 -> V_97 ) ;
if ( V_8 < 0 )
goto V_98;
if ( V_91 == 1 )
* V_7 = ( V_99 ) * V_90 ;
else if ( V_91 == 2 )
* V_7 = ( V_100 ) F_33 ( V_90 ) ;
else if ( V_91 == 3 )
* V_7 = ( V_2 ) F_1 ( V_90 ) ;
V_98:
F_34 ( V_90 ) ;
return V_8 ;
}
int F_35 ( struct V_3 * V_4 ,
struct V_88 const * V_89 , int * V_73 )
{
int V_8 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_36 ( & V_4 -> V_101 ) ;
if ( V_4 -> V_102 == V_103 ) {
V_8 = - V_104 ;
goto V_105;
} else {
V_8 = F_11 ( V_4 , true ) ;
if ( V_8 < 0 )
goto V_105;
F_37 ( ( V_11 -> V_23 -> V_106 * 1000 ) / V_11 -> V_24 ) ;
V_8 = F_31 ( V_4 , V_89 , V_73 ) ;
if ( V_8 < 0 )
goto V_105;
* V_73 = * V_73 >> V_89 -> V_92 . V_107 ;
V_8 = F_11 ( V_4 , false ) ;
}
V_105:
F_38 ( & V_4 -> V_101 ) ;
return V_8 ;
}
int F_39 ( struct V_3 * V_4 ,
int V_108 ,
const struct V_22 * V_23 )
{
int V_27 , V_109 , V_8 = 0 ;
T_2 V_110 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
for ( V_27 = 0 ; V_27 < V_108 ; V_27 ++ ) {
for ( V_109 = 0 ; V_109 < V_111 ; V_109 ++ ) {
if ( strcmp ( V_4 -> V_112 ,
V_23 [ V_27 ] . V_113 [ V_109 ] ) == 0 ) {
break;
}
}
if ( V_109 < V_111 )
break;
}
if ( V_27 == V_108 ) {
F_10 ( & V_4 -> V_15 , L_16 ,
V_4 -> V_112 ) ;
return - V_57 ;
}
if ( V_23 [ V_27 ] . V_114 ) {
V_8 = V_11 -> V_12 -> V_13 ( & V_11 -> V_14 , V_11 -> V_15 ,
V_23 [ V_27 ] . V_114 , & V_110 ) ;
if ( V_8 < 0 ) {
F_10 ( & V_4 -> V_15 ,
L_17 ) ;
return V_8 ;
}
if ( V_23 [ V_27 ] . V_110 != V_110 ) {
F_10 ( & V_4 -> V_15 ,
L_18 ,
V_4 -> V_112 , V_110 ) ;
return - V_29 ;
}
}
V_11 -> V_23 =
(struct V_22 * ) & V_23 [ V_27 ] ;
return V_27 ;
}
T_3 F_40 ( struct V_68 * V_15 ,
struct V_115 * V_116 , char * V_117 )
{
int V_27 , V_118 = 0 ;
struct V_3 * V_4 = F_41 ( V_15 ) ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_36 ( & V_4 -> V_101 ) ;
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ ) {
if ( V_11 -> V_23 -> V_24 . V_31 [ V_27 ] . V_32 == 0 )
break;
V_118 += F_42 ( V_117 + V_118 , V_119 - V_118 , L_19 ,
V_11 -> V_23 -> V_24 . V_31 [ V_27 ] . V_32 ) ;
}
F_38 ( & V_4 -> V_101 ) ;
V_117 [ V_118 - 1 ] = '\n' ;
return V_118 ;
}
T_3 F_43 ( struct V_68 * V_15 ,
struct V_115 * V_116 , char * V_117 )
{
int V_27 , V_118 = 0 ;
struct V_3 * V_4 = F_41 ( V_15 ) ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_36 ( & V_4 -> V_101 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ ) {
if ( V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_42 == 0 )
break;
V_118 += F_42 ( V_117 + V_118 , V_119 - V_118 , L_20 ,
V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_86 ) ;
}
F_38 ( & V_4 -> V_101 ) ;
V_117 [ V_118 - 1 ] = '\n' ;
return V_118 ;
}
