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
void F_13 ( struct V_3 * V_4 )
{
struct V_10 * V_54 = F_3 ( V_4 ) ;
int V_8 ;
V_54 -> V_55 = F_14 ( V_4 -> V_15 . V_56 , L_2 ) ;
if ( ! F_15 ( V_54 -> V_55 ) ) {
V_8 = F_16 ( V_54 -> V_55 ) ;
if ( V_8 != 0 )
F_17 ( & V_4 -> V_15 ,
L_3 ) ;
}
V_54 -> V_57 = F_14 ( V_4 -> V_15 . V_56 , L_4 ) ;
if ( ! F_15 ( V_54 -> V_57 ) ) {
V_8 = F_16 ( V_54 -> V_57 ) ;
if ( V_8 != 0 )
F_17 ( & V_4 -> V_15 ,
L_5 ) ;
}
}
void F_18 ( struct V_3 * V_4 )
{
struct V_10 * V_54 = F_3 ( V_4 ) ;
if ( ! F_15 ( V_54 -> V_55 ) )
F_19 ( V_54 -> V_55 ) ;
if ( ! F_15 ( V_54 -> V_57 ) )
F_19 ( V_54 -> V_57 ) ;
}
static int F_20 ( struct V_3 * V_4 ,
struct V_58 * V_54 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
if ( V_11 -> V_23 -> V_59 . V_35 == 0 ) {
if ( V_54 -> V_60 )
F_21 ( & V_4 -> V_15 ,
L_6
L_7 ,
V_54 -> V_60 ) ;
return 0 ;
}
switch ( V_54 -> V_60 ) {
case 1 :
if ( V_11 -> V_23 -> V_59 . V_61 == 0 ) {
F_10 ( & V_4 -> V_15 ,
L_8 ) ;
return - V_29 ;
}
V_11 -> V_60 = 1 ;
break;
case 2 :
if ( V_11 -> V_23 -> V_59 . V_62 == 0 ) {
F_10 ( & V_4 -> V_15 ,
L_9 ) ;
return - V_29 ;
}
V_11 -> V_60 = 2 ;
break;
default:
F_10 ( & V_4 -> V_15 , L_10 ) ;
return - V_29 ;
}
return 0 ;
}
static struct V_58 * F_22 ( struct V_63 * V_15 ,
struct V_58 * V_64 )
{
struct V_58 * V_54 ;
struct V_65 * V_66 = V_15 -> V_67 ;
T_1 V_68 ;
if ( ! V_66 )
return NULL ;
V_54 = F_23 ( V_15 , sizeof( * V_54 ) , V_69 ) ;
if ( ! F_24 ( V_66 , L_11 , & V_68 ) && ( V_68 <= 2 ) )
V_54 -> V_60 = ( T_2 ) V_68 ;
else
V_54 -> V_60 = V_64 ? V_64 -> V_60 : 0 ;
return V_54 ;
}
static struct V_58 * F_22 ( struct V_63 * V_15 ,
struct V_58 * V_64 )
{
return NULL ;
}
int F_25 ( struct V_3 * V_4 ,
struct V_58 * V_54 )
{
struct V_10 * V_11 = F_3 ( V_4 ) ;
struct V_58 * V_70 ;
int V_8 = 0 ;
V_70 = F_22 ( V_4 -> V_15 . V_56 , V_54 ) ;
if ( V_70 )
V_54 = V_70 ;
if ( V_54 ) {
V_8 = F_20 ( V_4 , V_54 ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_8 = F_11 ( V_4 , false ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_11 -> V_44 ) {
V_8 = F_9 ( V_4 ,
V_11 -> V_44 -> V_42 ) ;
if ( V_8 < 0 )
return V_8 ;
} else
F_21 ( & V_4 -> V_15 , L_12 ) ;
V_8 = F_7 ( V_4 , V_11 -> V_24 ) ;
if ( V_8 < 0 )
return V_8 ;
if ( V_11 -> V_23 -> V_71 . V_35 ) {
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_71 . V_35 ,
V_11 -> V_23 -> V_71 . V_6 , true ) ;
if ( V_8 < 0 )
return V_8 ;
}
V_8 = F_12 ( V_4 , V_72 ) ;
return V_8 ;
}
int F_26 ( struct V_3 * V_4 , bool V_46 )
{
int V_8 ;
T_2 V_73 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
if ( ! V_11 -> V_23 -> V_59 . V_35 )
return 0 ;
if ( V_11 -> V_23 -> V_59 . V_74 . V_75 > 0 ) {
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_59 . V_74 . V_75 ,
V_11 -> V_23 -> V_59 . V_74 . V_76 ,
( int ) V_46 ) ;
if ( V_8 < 0 )
goto V_77;
}
if ( V_11 -> V_60 == 1 )
V_73 = V_11 -> V_23 -> V_59 . V_61 ;
else
V_73 = V_11 -> V_23 -> V_59 . V_62 ;
V_8 = F_2 ( V_4 ,
V_11 -> V_23 -> V_59 . V_35 ,
V_73 , ( int ) V_46 ) ;
V_77:
return V_8 ;
}
int F_27 ( struct V_3 * V_4 , int V_78 )
{
int V_8 = - V_29 , V_27 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ ) {
if ( ( V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_79 == V_78 ) &&
( V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_79 != 0 ) ) {
V_8 = 0 ;
break;
}
}
if ( V_8 < 0 )
goto V_80;
V_8 = F_9 ( V_4 ,
V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_42 ) ;
V_80:
return V_8 ;
}
static int F_28 ( struct V_3 * V_4 ,
struct V_81 const * V_82 , int * V_7 )
{
int V_8 ;
T_2 * V_83 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
unsigned int V_84 = V_82 -> V_85 . V_86 >> 3 ;
V_83 = F_29 ( V_84 , V_69 ) ;
if ( ! V_83 )
return - V_87 ;
V_8 = V_11 -> V_12 -> V_88 ( & V_11 -> V_14 , V_11 -> V_15 ,
V_82 -> V_89 , V_84 ,
V_83 , V_11 -> V_90 ) ;
if ( V_8 < 0 )
goto V_91;
if ( V_84 == 1 )
* V_7 = ( V_92 ) * V_83 ;
else if ( V_84 == 2 )
* V_7 = ( V_93 ) F_30 ( V_83 ) ;
else if ( V_84 == 3 )
* V_7 = ( V_2 ) F_1 ( V_83 ) ;
V_91:
F_31 ( V_83 ) ;
return V_8 ;
}
int F_32 ( struct V_3 * V_4 ,
struct V_81 const * V_82 , int * V_68 )
{
int V_8 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_33 ( & V_4 -> V_94 ) ;
if ( V_4 -> V_95 == V_96 ) {
V_8 = - V_97 ;
goto V_98;
} else {
V_8 = F_11 ( V_4 , true ) ;
if ( V_8 < 0 )
goto V_98;
F_34 ( ( V_11 -> V_23 -> V_99 * 1000 ) / V_11 -> V_24 ) ;
V_8 = F_28 ( V_4 , V_82 , V_68 ) ;
if ( V_8 < 0 )
goto V_98;
* V_68 = * V_68 >> V_82 -> V_85 . V_100 ;
V_8 = F_11 ( V_4 , false ) ;
}
V_98:
F_35 ( & V_4 -> V_94 ) ;
return V_8 ;
}
int F_36 ( struct V_3 * V_4 ,
int V_101 ,
const struct V_22 * V_23 )
{
int V_27 , V_102 , V_8 ;
T_2 V_103 ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
for ( V_27 = 0 ; V_27 < V_101 ; V_27 ++ ) {
for ( V_102 = 0 ; V_102 < V_104 ; V_102 ++ ) {
if ( strcmp ( V_4 -> V_105 ,
V_23 [ V_27 ] . V_106 [ V_102 ] ) == 0 ) {
break;
}
}
if ( V_102 < V_104 )
break;
}
if ( V_27 == V_101 ) {
F_10 ( & V_4 -> V_15 , L_13 ,
V_4 -> V_105 ) ;
return - V_107 ;
}
V_8 = V_11 -> V_12 -> V_13 ( & V_11 -> V_14 , V_11 -> V_15 ,
V_23 [ V_27 ] . V_108 , & V_103 ) ;
if ( V_8 < 0 ) {
F_10 ( & V_4 -> V_15 , L_14 ) ;
return V_8 ;
}
if ( V_23 [ V_27 ] . V_103 != V_103 ) {
F_10 ( & V_4 -> V_15 , L_15 ,
V_4 -> V_105 , V_103 ) ;
return - V_29 ;
}
V_11 -> V_23 =
(struct V_22 * ) & V_23 [ V_27 ] ;
return V_27 ;
}
T_3 F_37 ( struct V_63 * V_15 ,
struct V_109 * V_110 , char * V_111 )
{
int V_27 , V_112 = 0 ;
struct V_3 * V_4 = F_38 ( V_15 ) ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_33 ( & V_4 -> V_94 ) ;
for ( V_27 = 0 ; V_27 < V_30 ; V_27 ++ ) {
if ( V_11 -> V_23 -> V_24 . V_31 [ V_27 ] . V_32 == 0 )
break;
V_112 += F_39 ( V_111 + V_112 , V_113 - V_112 , L_16 ,
V_11 -> V_23 -> V_24 . V_31 [ V_27 ] . V_32 ) ;
}
F_35 ( & V_4 -> V_94 ) ;
V_111 [ V_112 - 1 ] = '\n' ;
return V_112 ;
}
T_3 F_40 ( struct V_63 * V_15 ,
struct V_109 * V_110 , char * V_111 )
{
int V_27 , V_112 = 0 ;
struct V_3 * V_4 = F_38 ( V_15 ) ;
struct V_10 * V_11 = F_3 ( V_4 ) ;
F_33 ( & V_4 -> V_94 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ ) {
if ( V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_42 == 0 )
break;
V_112 += F_39 ( V_111 + V_112 , V_113 - V_112 , L_17 ,
V_11 -> V_23 -> V_38 . V_41 [ V_27 ] . V_79 ) ;
}
F_35 ( & V_4 -> V_94 ) ;
V_111 [ V_112 - 1 ] = '\n' ;
return V_112 ;
}
