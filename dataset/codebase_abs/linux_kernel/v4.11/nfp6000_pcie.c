static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) ;
}
static T_2 F_3 ( struct V_1 * V_2 )
{
return F_4 ( V_2 -> V_4 -> V_5 , ( V_2 -> V_6 / 8 ) * 2 ) / 8 ;
}
static T_2 F_5 ( struct V_1 * V_2 )
{
return F_6 ( V_2 -> V_4 -> V_5 , ( V_2 -> V_6 / 8 ) * 2 )
+ F_3 ( V_2 ) * ( V_2 -> V_6 & 7 ) ;
}
static int
F_7 ( struct V_7 * V_4 , struct V_1 * V_2 ,
T_1 * V_8 , T_3 * V_9 ,
int V_10 , int V_11 , int V_12 , T_3 V_13 , T_4 V_14 , int V_15 )
{
int V_16 ;
T_1 V_17 ;
if ( V_10 >= V_18 )
return - V_19 ;
switch ( V_15 ) {
case 8 :
V_17 = F_8 (
V_20 ) ;
break;
case 4 :
V_17 = F_8 (
V_21 ) ;
break;
case 0 :
V_17 = F_8 (
V_22 ) ;
break;
default:
return - V_19 ;
}
if ( V_11 != V_23 && V_11 != 0 ) {
T_3 V_24 = ~ ( F_9 ( V_2 ) - 1 ) ;
V_17 |= F_10 (
V_25 ) ;
V_17 |= F_11 ( V_10 ) ;
V_17 |= F_12 ( V_11 ) ;
V_17 |= F_13 ( V_12 ) ;
if ( ( V_13 & V_24 ) != ( ( V_13 + V_14 - 1 ) & V_24 ) )
return - V_19 ;
V_13 &= V_24 ;
V_16 = 40 - 16 ;
} else {
T_3 V_24 = ~ ( F_14 ( V_2 ) - 1 ) ;
V_17 |= F_10 (
V_26 ) ;
V_17 |= F_11 ( V_10 ) ;
V_17 |= F_13 ( V_12 ) ;
if ( ( V_13 & V_24 ) != ( ( V_13 + V_14 - 1 ) & V_24 ) )
return - V_19 ;
V_13 &= V_24 ;
V_16 = 40 - 21 ;
}
if ( V_2 -> V_16 < V_16 )
return - V_19 ;
V_17 |= V_13 >> V_16 ;
if ( V_9 )
* V_9 = V_13 ;
if ( V_8 )
* V_8 = V_17 ;
return 0 ;
}
static int
F_15 ( struct V_7 * V_4 , struct V_1 * V_2 , T_1 V_17 )
{
int V_27 , V_28 ;
int V_29 ;
V_27 = V_2 -> V_6 >> 3 ;
V_28 = V_2 -> V_6 & 7 ;
if ( V_4 -> V_30 . V_31 ) {
V_29 = F_16 ( V_27 , V_28 ) ;
F_17 ( V_17 , V_4 -> V_30 . V_31 + V_29 ) ;
F_18 ( V_4 -> V_30 . V_31 + V_29 ) ;
} else {
V_29 = F_19 ( V_27 , V_28 ) ;
F_20 ( V_4 -> V_5 , V_29 , V_17 ) ;
}
V_2 -> V_3 = V_17 ;
return 0 ;
}
static int
F_21 ( struct V_7 * V_4 , struct V_1 * V_2 ,
int V_10 , int V_11 , int V_12 , T_3 V_13 , T_4 V_14 , int V_15 )
{
T_3 V_32 ;
T_1 V_17 ;
int V_33 ;
V_33 = F_7 ( V_4 , V_2 , & V_17 , & V_32 ,
V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_33 )
return V_33 ;
V_2 -> V_27 = V_32 ;
return F_15 ( V_4 , V_2 , V_17 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 , T_1 V_12 ,
T_3 V_13 , T_4 V_14 , int V_15 )
{
int V_34 , V_35 , V_36 ;
int V_37 ;
T_1 V_38 ;
V_38 = F_2 ( V_2 -> V_3 ) ;
V_34 = F_23 ( V_2 -> V_3 ) ;
V_36 = F_24 ( V_2 -> V_3 ) ;
V_35 = F_25 ( V_2 -> V_3 ) ;
V_37 = F_26 ( V_2 -> V_3 ) ;
switch ( V_37 ) {
case V_21 :
V_37 = 4 ;
break;
case V_20 :
V_37 = 8 ;
break;
case V_22 :
V_37 = 0 ;
break;
default:
V_37 = - 1 ;
break;
}
switch ( V_38 ) {
case V_39 :
V_36 = - 1 ;
case V_26 :
V_35 = V_23 ;
if ( V_11 == 0 )
V_11 = V_23 ;
case V_25 :
break;
default:
return 0 ;
}
if ( V_37 != V_15 )
return 0 ;
if ( ( V_34 < 0 || V_34 == V_10 ) &&
( V_36 < 0 || V_36 == V_12 ) &&
( V_35 == V_11 ) &&
V_2 -> V_27 <= V_13 &&
( V_2 -> V_27 + ( 1 << V_2 -> V_16 ) ) >= ( V_13 + V_14 ) )
return 1 ;
return 0 ;
}
static int
F_27 ( struct V_7 * V_4 ,
T_1 V_10 , T_1 V_11 , T_1 V_12 , T_3 V_13 , T_4 V_14 , int V_15 )
{
int V_40 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_41 ; V_40 ++ ) {
struct V_1 * V_2 = & V_4 -> V_2 [ V_40 ] ;
if ( F_22 ( V_2 , V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ) )
return V_40 ;
}
return - 1 ;
}
static int
F_28 ( struct V_7 * V_4 ,
int V_10 , int V_11 , int V_12 ,
T_3 V_13 , T_4 V_14 , int V_15 )
{
int V_40 , V_42 = 0 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_41 ; V_40 ++ ) {
struct V_1 * V_2 = & V_4 -> V_2 [ V_40 ] ;
int V_33 ;
if ( V_2 -> V_16 == 0 ) {
V_42 ++ ;
continue;
}
if ( F_29 ( & V_2 -> V_43 ) != 0 )
continue;
V_33 = F_7 ( V_4 , V_2 , NULL , NULL ,
V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_33 < 0 )
V_42 ++ ;
else
return V_40 ;
}
return ( V_40 == V_42 ) ? - V_19 : - V_44 ;
}
static int
F_30 ( struct V_7 * V_4 ,
int V_10 , int V_11 , int V_12 ,
T_3 V_13 , T_4 V_14 , int V_15 )
{
unsigned long V_45 ;
int V_40 ;
F_31 ( & V_4 -> V_46 , V_45 ) ;
V_40 = F_28 ( V_4 , V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_40 < 0 )
F_32 ( & V_4 -> V_46 , V_45 ) ;
else
F_33 ( & V_4 -> V_46 ) ;
return V_40 ;
}
static void F_34 ( struct V_7 * V_4 , struct V_1 * V_2 )
{
F_35 ( & V_2 -> V_43 ) ;
}
static void F_36 ( struct V_7 * V_4 , struct V_1 * V_2 )
{
if ( F_37 ( & V_2 -> V_43 ) )
F_38 ( & V_4 -> V_47 ) ;
}
static int
F_39 ( struct V_7 * V_4 , int * V_48 ,
T_1 V_10 , T_1 V_11 , T_1 V_12 , T_3 V_13 , T_4 V_14 , int V_15 )
{
return F_40 ( V_4 -> V_47 ,
( * V_48 = F_30 ( V_4 , V_10 , V_11 , V_12 ,
V_13 , V_14 , V_15 ) )
!= - V_44 ) ;
}
static int
F_41 ( struct V_7 * V_4 ,
T_1 V_10 , T_1 V_11 , T_1 V_12 ,
T_3 V_13 , T_4 V_14 , int V_15 , int V_49 )
{
unsigned long V_50 ;
int V_48 , V_51 ;
if ( V_14 > ( 1 << 24 ) )
return - V_19 ;
F_31 ( & V_4 -> V_46 , V_50 ) ;
V_48 = F_27 ( V_4 , V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_48 >= 0 ) {
F_34 ( V_4 , & V_4 -> V_2 [ V_48 ] ) ;
F_32 ( & V_4 -> V_46 , V_50 ) ;
return V_48 ;
}
V_48 = F_28 ( V_4 , V_10 , V_11 , V_12 ,
V_13 , V_14 , V_15 ) ;
if ( V_48 < 0 ) {
if ( V_49 )
goto V_52;
F_32 ( & V_4 -> V_46 , V_50 ) ;
V_51 = F_39 ( V_4 , & V_48 , V_10 , V_11 , V_12 ,
V_13 , V_14 , V_15 ) ;
if ( V_51 )
return V_51 ;
F_42 ( & V_4 -> V_46 ) ;
}
F_34 ( V_4 , & V_4 -> V_2 [ V_48 ] ) ;
V_51 = F_21 ( V_4 , & V_4 -> V_2 [ V_48 ] ,
V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_51 < 0 ) {
F_36 ( V_4 , & V_4 -> V_2 [ V_48 ] ) ;
V_48 = V_51 ;
}
V_52:
F_32 ( & V_4 -> V_46 , V_50 ) ;
return V_48 ;
}
static int F_43 ( const void * V_53 , const void * V_54 )
{
const struct V_1 * V_55 = V_53 , * V_56 = V_54 ;
if ( V_55 -> V_16 == V_56 -> V_16 )
return V_55 -> V_6 - V_56 -> V_6 ;
else
return V_55 -> V_16 - V_56 -> V_16 ;
}
static int F_44 ( struct V_7 * V_4 , T_5 V_57 )
{
const T_1 V_58 =
F_10 (
V_59 ) |
V_21 ;
const T_1 V_60 =
F_10 (
V_26 ) |
V_21 |
F_11 (
V_61 ) ;
const T_1 V_62 [ 4 ] = {
F_10 (
V_63 ) ,
F_10 (
V_64 ) ,
F_10 (
V_65 ) ,
F_10 (
V_66 ) ,
} ;
struct V_1 * V_2 ;
int V_67 , V_68 ;
int V_69 ;
V_2 = & V_4 -> V_2 [ 0 ] ;
for ( V_67 = 0 ; V_67 < F_45 ( V_4 -> V_2 ) ; V_67 ++ , V_2 ++ ) {
struct V_70 * V_71 ;
V_71 = & V_4 -> V_5 -> V_70 [ ( V_67 >> 3 ) * 2 ] ;
if ( ! ( F_46 ( V_71 ) & V_72 ) ) {
V_2 -- ;
continue;
}
V_2 -> V_70 = V_71 ;
V_2 -> V_3 = 0 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_67 ;
V_2 -> V_24 = F_3 ( V_2 ) - 1 ;
V_2 -> V_16 = F_47 ( V_2 -> V_24 ) ;
V_2 -> V_27 = 0 ;
V_2 -> V_30 = NULL ;
}
V_4 -> V_41 = V_2 - & V_4 -> V_2 [ 0 ] ;
if ( V_4 -> V_41 < 8 ) {
F_48 ( V_4 -> V_73 , L_1 ) ;
return - V_19 ;
}
V_68 = V_4 -> V_41 ;
F_49 ( & V_4 -> V_74 . V_75 ) ;
V_4 -> V_74 . V_76 = ( ( F_50 ( V_57 ) & 3 ) + 4 )
<< 4 ;
V_4 -> V_74 . V_77 = 0x10 ;
V_2 = & V_4 -> V_2 [ 0 ] ;
V_2 -> V_30 = F_51 ( F_5 ( V_2 ) ,
F_3 ( V_2 ) ) ;
if ( V_2 -> V_30 ) {
F_52 ( V_4 -> V_73 ,
L_2 ) ;
F_35 ( & V_2 -> V_43 ) ;
V_68 -- ;
F_15 ( V_4 , V_2 , V_58 ) ;
V_4 -> V_74 . V_78 = V_2 -> V_30 + V_79 + 0x1000 ;
}
if ( V_4 -> V_5 -> V_80 == V_81 ||
V_4 -> V_5 -> V_80 == V_82 ) {
V_4 -> V_30 . V_31 = V_2 -> V_30 + F_53 ( 0 ) ;
V_69 = 4 ;
} else {
int V_83 = V_4 -> V_5 -> V_84 & 7 ;
V_4 -> V_30 . V_31 = V_2 -> V_30 + F_53 ( V_83 ) ;
V_69 = 1 ;
}
V_4 -> V_30 . V_85 = V_2 -> V_30 + V_86 ;
V_2 = & V_4 -> V_2 [ 1 ] ;
F_52 ( V_4 -> V_73 , L_3 ) ;
F_35 ( & V_2 -> V_43 ) ;
V_68 -- ;
F_15 ( V_4 , V_2 , V_60 ) ;
for ( V_67 = 0 ; V_67 < 4 ; V_67 ++ ) {
int V_87 ;
if ( V_67 >= V_88 || V_67 >= V_69 ) {
V_4 -> V_74 . V_89 [ V_67 ] . V_16 = 0 ;
continue;
}
V_2 = & V_4 -> V_2 [ 4 + V_67 ] ;
V_2 -> V_30 = F_51 ( F_5 ( V_2 ) ,
F_3 ( V_2 ) ) ;
if ( V_2 -> V_30 ) {
F_52 ( V_4 -> V_73 ,
L_4 ,
4 + V_67 , V_67 ) ;
F_35 ( & V_2 -> V_43 ) ;
V_68 -- ;
V_4 -> V_74 . V_89 [ V_67 ] . V_16 = V_2 -> V_16 ;
V_4 -> V_74 . V_89 [ V_67 ] . V_90 = V_2 -> V_30 ;
F_15 ( V_4 , V_2 , V_62 [ V_67 ] ) ;
for ( V_87 = 0 ; V_87 < 4 ; V_87 ++ )
V_4 -> V_74 . V_89 [ V_67 ] . free [ V_87 ] = true ;
}
V_4 -> V_30 . V_74 [ V_67 ] = V_2 -> V_30 ;
}
F_54 ( & V_4 -> V_2 [ 0 ] , V_4 -> V_41 , sizeof( V_4 -> V_2 [ 0 ] ) ,
F_43 , NULL ) ;
F_52 ( V_4 -> V_73 , L_5 ,
V_4 -> V_41 , V_68 ) ;
return 0 ;
}
static void F_55 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 [ 0 ] ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_41 ; V_40 ++ , V_2 ++ ) {
if ( V_2 -> V_30 ) {
F_56 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
}
}
}
static int F_57 ( struct V_91 * V_92 , T_1 V_93 ,
unsigned long long V_94 , unsigned long V_14 )
{
struct V_95 * V_96 = F_58 ( V_92 ) ;
T_1 V_97 = F_59 ( V_93 ) ;
T_1 V_98 = F_60 ( V_93 ) ;
T_1 V_99 = F_61 ( V_93 ) ;
int V_100 ;
V_100 = F_62 ( F_63 ( V_97 , V_98 , V_99 ) , V_94 ) ;
if ( V_100 < 0 )
return V_100 ;
V_96 -> V_15 . V_101 = F_64 ( V_100 ) ;
V_96 -> V_15 . V_102 = F_65 ( V_100 ) ;
if ( V_96 -> V_15 . V_101 > 0 &&
V_96 -> V_15 . V_102 > 0 &&
V_96 -> V_15 . V_101 != V_96 -> V_15 . V_102 ) {
return - V_19 ;
}
if ( V_96 -> V_15 . V_101 > 0 )
V_96 -> V_15 . V_2 = V_96 -> V_15 . V_101 ;
else
V_96 -> V_15 . V_2 = V_96 -> V_15 . V_102 ;
F_66 ( & V_96 -> V_43 , 0 ) ;
V_96 -> V_2 = NULL ;
V_96 -> V_97 = V_97 ;
V_96 -> V_98 = V_98 ;
V_96 -> V_99 = V_99 ;
V_96 -> V_13 = V_94 ;
V_96 -> V_14 = V_14 ;
memset ( & V_96 -> V_70 , 0 , sizeof( V_96 -> V_70 ) ) ;
return 0 ;
}
static void F_67 ( struct V_91 * V_92 )
{
}
static void F_68 ( struct V_91 * V_92 )
{
struct V_95 * V_96 = F_58 ( V_92 ) ;
F_35 ( & V_96 -> V_43 ) ;
}
static int F_69 ( struct V_91 * V_92 )
{
struct V_95 * V_96 = F_58 ( V_92 ) ;
if ( F_70 ( ! F_29 ( & V_96 -> V_43 ) ) )
return 0 ;
return F_37 ( & V_96 -> V_43 ) ;
}
static int F_71 ( struct V_91 * V_92 )
{
struct V_7 * V_4 = F_72 ( F_73 ( V_92 ) ) ;
struct V_95 * V_96 = F_58 ( V_92 ) ;
int V_48 , V_33 ;
if ( V_96 -> V_2 ) {
F_68 ( V_92 ) ;
return 0 ;
}
V_48 = F_41 ( V_4 , V_96 -> V_97 , V_96 -> V_98 , V_96 -> V_99 ,
V_96 -> V_13 , V_96 -> V_14 , V_96 -> V_15 . V_2 , 1 ) ;
if ( V_48 < 0 ) {
V_33 = V_48 ;
goto V_103;
}
V_96 -> V_2 = & V_4 -> V_2 [ V_48 ] ;
if ( F_1 ( V_96 -> V_2 ) ==
V_59 ) {
V_96 -> V_104 = V_96 -> V_13 &
( F_74 ( V_96 -> V_2 ) - 1 ) ;
V_96 -> V_104 += F_75 (
V_96 -> V_2 , V_96 -> V_97 ) ;
V_96 -> V_104 += F_76 (
V_96 -> V_2 , V_96 -> V_99 ) ;
} else {
V_96 -> V_104 = V_96 -> V_13 & V_96 -> V_2 -> V_24 ;
}
V_96 -> V_105 = F_5 ( V_96 -> V_2 ) + V_96 -> V_104 ;
V_96 -> V_70 . V_106 = F_77 ( V_92 ) ;
V_96 -> V_70 . V_107 = V_96 -> V_105 ;
V_96 -> V_70 . V_108 = V_96 -> V_70 . V_107 + V_96 -> V_14 - 1 ;
V_96 -> V_70 . V_45 = V_72 ;
if ( V_96 -> V_2 -> V_30 )
V_96 -> V_30 = V_96 -> V_2 -> V_30 + V_96 -> V_104 ;
else
V_96 -> V_30 = F_51 ( V_96 -> V_105 , V_96 -> V_14 ) ;
if ( F_78 ( V_96 -> V_30 ) ) {
F_48 ( V_4 -> V_73 , L_6 ,
( int ) V_96 -> V_14 , V_96 -> V_2 -> V_6 ) ;
V_33 = ! V_96 -> V_30 ? - V_109 : F_79 ( V_96 -> V_30 ) ;
V_96 -> V_30 = NULL ;
goto V_110;
}
F_68 ( V_92 ) ;
return 0 ;
V_110:
F_36 ( V_4 , V_96 -> V_2 ) ;
V_96 -> V_2 = NULL ;
V_103:
return V_33 ;
}
static void F_80 ( struct V_91 * V_92 )
{
struct V_7 * V_4 = F_72 ( F_73 ( V_92 ) ) ;
struct V_95 * V_96 = F_58 ( V_92 ) ;
if ( ! F_69 ( V_92 ) )
return;
if ( ! V_96 -> V_2 -> V_30 )
F_56 ( V_96 -> V_30 ) ;
F_36 ( V_4 , V_96 -> V_2 ) ;
V_96 -> V_2 = NULL ;
V_96 -> V_30 = NULL ;
}
static T_6 F_81 ( struct V_91 * V_92 )
{
struct V_95 * V_96 = F_58 ( V_92 ) ;
return V_96 -> V_105 ;
}
static void T_7 * F_82 ( struct V_91 * V_92 )
{
struct V_95 * V_96 = F_58 ( V_92 ) ;
return V_96 -> V_30 ;
}
static struct V_70 * F_83 ( struct V_91 * V_92 )
{
struct V_95 * V_96 = F_58 ( V_92 ) ;
return V_96 -> V_2 -> V_70 ;
}
static int F_84 ( struct V_91 * V_92 , void * V_111 ,
unsigned long V_13 , unsigned int V_112 )
{
T_3 T_8 * V_113 = V_111 ;
const T_3 T_7 T_8 * V_114 ;
struct V_95 * V_96 ;
T_1 * V_115 = V_111 ;
const T_1 T_7 * V_116 ;
int V_40 , V_15 ;
bool V_117 ;
V_96 = F_58 ( V_92 ) ;
V_114 = V_96 -> V_30 + V_13 ;
V_116 = V_96 -> V_30 + V_13 ;
if ( V_13 + V_112 > V_96 -> V_14 )
return - V_118 ;
V_15 = V_96 -> V_15 . V_101 ;
if ( V_15 <= 0 )
return - V_19 ;
if ( ( V_96 -> V_13 + V_13 ) & ( V_15 - 1 ) )
return F_85 ( F_73 ( V_92 ) ,
F_63 ( V_96 -> V_97 ,
V_96 -> V_98 ,
V_96 -> V_99 ) ,
V_96 -> V_13 + V_13 ,
V_111 , V_112 , V_15 ) ;
V_117 = V_15 == V_119 ;
if ( V_96 -> V_97 == ( V_120 & V_121 ) &&
V_96 -> V_98 == V_23 )
V_117 = false ;
if ( V_117 ) {
if ( V_13 % sizeof( T_3 ) != 0 || V_112 % sizeof( T_3 ) != 0 )
return - V_19 ;
} else {
if ( V_13 % sizeof( T_1 ) != 0 || V_112 % sizeof( T_1 ) != 0 )
return - V_19 ;
}
if ( F_70 ( ! V_96 -> V_2 ) )
return - V_118 ;
if ( V_117 )
#ifndef F_86
return - V_19 ;
#else
for ( V_40 = 0 ; V_40 < V_112 ; V_40 += sizeof( T_3 ) )
* V_113 ++ = F_86 ( V_114 ++ ) ;
#endif
else
for ( V_40 = 0 ; V_40 < V_112 ; V_40 += sizeof( T_1 ) )
* V_115 ++ = F_87 ( V_116 ++ ) ;
return V_40 ;
}
static int
F_88 ( struct V_91 * V_92 ,
const void * V_111 ,
unsigned long V_13 , unsigned int V_112 )
{
const T_3 T_8 * V_114 = V_111 ;
T_3 T_7 T_8 * V_113 ;
const T_1 * V_116 = V_111 ;
struct V_95 * V_96 ;
T_1 T_7 * V_115 ;
int V_40 , V_15 ;
bool V_117 ;
V_96 = F_58 ( V_92 ) ;
V_113 = V_96 -> V_30 + V_13 ;
V_115 = V_96 -> V_30 + V_13 ;
if ( V_13 + V_112 > V_96 -> V_14 )
return - V_118 ;
V_15 = V_96 -> V_15 . V_102 ;
if ( V_15 <= 0 )
return - V_19 ;
if ( ( V_96 -> V_13 + V_13 ) & ( V_15 - 1 ) )
return F_89 ( F_73 ( V_92 ) ,
F_63 ( V_96 -> V_97 ,
V_96 -> V_98 ,
V_96 -> V_99 ) ,
V_96 -> V_13 + V_13 ,
V_111 , V_112 , V_15 ) ;
V_117 = V_15 == V_119 ;
if ( V_96 -> V_97 == ( V_120 & V_121 ) &&
V_96 -> V_98 == V_23 )
V_117 = false ;
if ( V_117 ) {
if ( V_13 % sizeof( T_3 ) != 0 || V_112 % sizeof( T_3 ) != 0 )
return - V_19 ;
} else {
if ( V_13 % sizeof( T_1 ) != 0 || V_112 % sizeof( T_1 ) != 0 )
return - V_19 ;
}
if ( F_70 ( ! V_96 -> V_2 ) )
return - V_118 ;
if ( V_117 )
#ifndef F_90
return - V_19 ;
#else
for ( V_40 = 0 ; V_40 < V_112 ; V_40 += sizeof( T_3 ) ) {
F_90 ( * V_114 ++ , V_113 ++ ) ;
F_91 () ;
}
#endif
else
for ( V_40 = 0 ; V_40 < V_112 ; V_40 += sizeof( T_1 ) ) {
F_92 ( * V_116 ++ , V_115 ++ ) ;
F_91 () ;
}
return V_40 ;
}
static int F_93 ( struct V_122 * V_74 )
{
struct V_7 * V_4 = F_72 ( F_94 ( V_74 ) ) ;
struct V_123 * V_96 = F_95 ( V_74 ) ;
int V_67 , V_87 ;
F_96 ( & V_4 -> V_74 . V_75 ) ;
for ( V_67 = 0 ; V_67 < F_45 ( V_4 -> V_74 . V_89 ) ; V_67 ++ ) {
if ( ! V_4 -> V_74 . V_89 [ V_67 ] . V_16 )
continue;
for ( V_87 = 0 ; V_87 < F_45 ( V_4 -> V_74 . V_89 [ V_67 ] . free ) ; V_87 ++ ) {
T_5 V_124 ;
if ( ! V_4 -> V_74 . V_89 [ V_67 ] . free [ V_87 ] )
continue;
V_96 -> V_4 = V_4 ;
V_96 -> V_2 . V_89 = V_67 ;
V_96 -> V_2 . V_92 = V_87 ;
V_96 -> V_16 = V_4 -> V_74 . V_89 [ V_67 ] . V_16 - 2 ;
V_124 = ( V_96 -> V_2 . V_89 << 9 ) +
( V_96 -> V_2 . V_92 << 7 ) ;
V_96 -> V_78 = V_4 -> V_74 . V_78 + V_124 ;
V_96 -> V_90 = V_4 -> V_74 . V_89 [ V_67 ] . V_90 +
( V_96 -> V_2 . V_92 << V_96 -> V_16 ) ;
V_4 -> V_74 . V_89 [ V_67 ] . free [ V_87 ] = false ;
F_97 ( & V_4 -> V_74 . V_75 ) ;
return 0 ;
}
}
F_97 ( & V_4 -> V_74 . V_75 ) ;
return - V_44 ;
}
static void F_98 ( struct V_122 * V_74 )
{
struct V_123 * V_96 = F_95 ( V_74 ) ;
struct V_7 * V_4 = V_96 -> V_4 ;
F_96 ( & V_4 -> V_74 . V_75 ) ;
V_4 -> V_74 . V_89 [ V_96 -> V_2 . V_89 ] . free [ V_96 -> V_2 . V_92 ] = true ;
F_97 ( & V_4 -> V_74 . V_75 ) ;
}
static int F_99 ( struct V_122 * V_74 ,
const void * V_125 , T_4 V_126 )
{
struct V_123 * V_96 = F_95 ( V_74 ) ;
const T_1 * V_127 = V_125 ;
T_4 V_67 ;
for ( V_67 = 0 ; V_67 < V_126 ; V_67 += sizeof( T_1 ) )
F_17 ( * ( V_127 ++ ) , V_96 -> V_78 + V_67 ) ;
return V_67 ;
}
static int
F_100 ( struct V_122 * V_74 ,
const struct V_128 * V_129 , T_3 V_94 )
{
struct V_123 * V_96 = F_95 ( V_74 ) ;
T_9 V_130 , V_77 , V_131 ;
struct V_7 * V_4 = V_96 -> V_4 ;
int V_132 = 0 ;
T_5 V_133 ;
T_1 V_31 [ 3 ] ;
if ( V_129 -> V_134 )
V_132 |= 1 << V_129 -> V_135 ;
if ( V_129 -> V_136 )
V_132 |= 1 << V_129 -> V_137 ;
V_130 = V_129 -> V_130 ;
if ( ! V_130 )
V_130 = V_4 -> V_74 . V_76 ;
V_77 = V_129 -> V_77 ;
if ( V_130 == V_4 -> V_74 . V_76 )
V_77 = V_4 -> V_74 . V_77 +
( ( V_96 -> V_2 . V_89 * 4 + V_96 -> V_2 . V_92 ) << 1 ) ;
V_131 = V_129 -> V_131 ;
if ( ! V_131 )
V_131 = V_4 -> V_74 . V_76 ;
V_133 = V_129 -> V_133 ;
if ( V_131 == V_4 -> V_74 . V_76 )
V_133 = 0x1000 +
( V_96 -> V_2 . V_89 << 9 ) + ( V_96 -> V_2 . V_92 << 7 ) ;
V_31 [ 0 ] = F_101 ( V_132 ) |
F_102 (
F_61 ( V_129 -> V_138 ) ) |
F_103 ( V_94 >> 16 ) ;
V_31 [ 1 ] = F_104 ( V_77 ) |
F_105 ( V_131 ) |
F_106 ( V_133 ) ;
V_31 [ 2 ] = F_107 (
F_59 ( V_129 -> V_138 ) ) |
F_108 (
F_60 ( V_129 -> V_138 ) ) |
F_109 ( V_129 -> V_126 ) |
F_110 ( V_129 -> V_139 ) |
F_111 ( V_130 ) ;
if ( V_4 -> V_30 . V_31 ) {
F_17 ( V_31 [ 0 ] , V_4 -> V_30 . V_31 +
F_112 ( V_96 -> V_2 . V_89 ,
V_96 -> V_2 . V_92 ) ) ;
F_17 ( V_31 [ 1 ] , V_4 -> V_30 . V_31 +
F_113 ( V_96 -> V_2 . V_89 ,
V_96 -> V_2 . V_92 ) ) ;
F_17 ( V_31 [ 2 ] , V_4 -> V_30 . V_31 +
F_114 ( V_96 -> V_2 . V_89 ,
V_96 -> V_2 . V_92 ) ) ;
F_18 ( V_4 -> V_30 . V_31 +
F_112 ( V_96 -> V_2 . V_89 ,
V_96 -> V_2 . V_92 ) ) ;
F_18 ( V_4 -> V_30 . V_31 +
F_113 ( V_96 -> V_2 . V_89 ,
V_96 -> V_2 . V_92 ) ) ;
F_18 ( V_4 -> V_30 . V_31 +
F_114 ( V_96 -> V_2 . V_89 ,
V_96 -> V_2 . V_92 ) ) ;
} else {
F_20 ( V_4 -> V_5 , 0x400 +
F_112 (
V_96 -> V_2 . V_89 , V_96 -> V_2 . V_92 ) ,
V_31 [ 0 ] ) ;
F_20 ( V_4 -> V_5 , 0x400 +
F_113 (
V_96 -> V_2 . V_89 , V_96 -> V_2 . V_92 ) ,
V_31 [ 1 ] ) ;
F_20 ( V_4 -> V_5 , 0x400 +
F_114 (
V_96 -> V_2 . V_89 , V_96 -> V_2 . V_92 ) ,
V_31 [ 2 ] ) ;
}
F_115 ( V_96 -> V_90 + ( V_94 & ( ( 1 << V_96 -> V_16 ) - 1 ) ) ) ;
return V_132 ;
}
static int F_116 ( struct V_122 * V_74 ,
void * V_125 , T_4 V_126 )
{
struct V_123 * V_96 = F_95 ( V_74 ) ;
T_1 * V_140 = V_125 ;
T_4 V_67 ;
for ( V_67 = 0 ; V_67 < V_126 ; V_67 += sizeof( T_1 ) )
* ( V_140 ++ ) = F_18 ( V_96 -> V_78 + V_67 ) ;
return V_67 ;
}
static int F_117 ( struct V_141 * V_142 )
{
F_118 ( V_142 , V_143 ) ;
F_118 ( V_142 , V_143 ) ;
F_118 ( V_142 , V_144 ) ;
return 0 ;
}
static void F_119 ( struct V_141 * V_142 )
{
struct V_7 * V_4 = F_72 ( V_142 ) ;
F_55 ( V_4 ) ;
F_120 ( V_4 ) ;
}
static void F_121 ( struct V_80 * V_73 , T_9 * V_145 )
{
struct V_146 * V_5 = F_122 ( V_73 ) ;
int V_147 ;
T_1 V_148 ;
V_147 = F_123 ( V_5 , V_149 ) ;
if ( ! V_147 ) {
memset ( V_145 , 0 , V_150 ) ;
return;
}
F_124 ( V_5 , V_147 + 4 , & V_148 ) ;
F_125 ( V_148 >> 16 , V_145 + 4 ) ;
F_124 ( V_5 , V_147 + 8 , & V_148 ) ;
F_126 ( V_148 , V_145 ) ;
}
static T_5 F_127 ( struct V_80 * V_73 )
{
struct V_146 * V_5 = F_122 ( V_73 ) ;
int V_147 ;
T_1 V_148 ;
V_147 = F_123 ( V_5 , V_149 ) ;
if ( ! V_147 )
return F_128 ( V_151 , 0 , 0xff ) ;
F_124 ( V_5 , V_147 + 4 , & V_148 ) ;
return V_148 & 0xffff ;
}
struct V_141 * F_129 ( struct V_146 * V_5 )
{
struct V_7 * V_4 ;
T_5 V_57 ;
int V_33 ;
F_52 ( & V_5 -> V_73 ,
L_7 ) ;
V_4 = F_130 ( sizeof( * V_4 ) , V_152 ) ;
if ( ! V_4 ) {
V_33 = - V_109 ;
goto V_153;
}
V_4 -> V_73 = & V_5 -> V_73 ;
V_4 -> V_5 = V_5 ;
F_131 ( & V_4 -> V_47 ) ;
F_132 ( & V_4 -> V_46 ) ;
V_57 = F_127 ( & V_5 -> V_73 ) ;
if ( F_133 ( V_57 ) !=
V_151 ) {
F_48 ( & V_5 -> V_73 ,
L_8 ,
F_133 ( V_57 ) ,
V_151 ) ;
V_33 = - V_154 ;
goto V_155;
}
if ( F_134 ( V_57 ) !=
V_156 ) {
F_48 ( & V_5 -> V_73 , L_9 ,
F_134 ( V_57 ) ,
V_156 ) ;
V_33 = - V_154 ;
goto V_155;
}
V_33 = F_44 ( V_4 , V_57 ) ;
if ( V_33 )
goto V_155;
return F_135 ( & V_157 , & V_5 -> V_73 , V_4 ) ;
V_155:
F_120 ( V_4 ) ;
V_153:
F_48 ( & V_5 -> V_73 , L_10 ) ;
return F_136 ( V_33 ) ;
}
