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
F_7 ( const struct V_7 * V_4 , const struct V_1 * V_2 ,
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
F_28 ( const struct V_7 * V_4 ,
int V_10 , int V_11 , int V_12 ,
T_3 V_13 , T_4 V_14 , int V_15 )
{
int V_40 , V_42 = 0 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_41 ; V_40 ++ ) {
const struct V_1 * V_2 = & V_4 -> V_2 [ V_40 ] ;
int V_33 ;
if ( ! V_2 -> V_16 )
continue;
V_33 = F_7 ( V_4 , V_2 , NULL , NULL ,
V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_33 )
continue;
if ( ! F_29 ( & V_2 -> V_43 ) )
return V_40 ;
V_42 ++ ;
}
if ( F_30 ( ! V_42 , L_1 ,
V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ) )
return - V_19 ;
return - V_44 ;
}
static int
F_31 ( struct V_7 * V_4 ,
int V_10 , int V_11 , int V_12 ,
T_3 V_13 , T_4 V_14 , int V_15 )
{
unsigned long V_45 ;
int V_40 ;
F_32 ( & V_4 -> V_46 , V_45 ) ;
V_40 = F_28 ( V_4 , V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_40 < 0 )
F_33 ( & V_4 -> V_46 , V_45 ) ;
else
F_34 ( & V_4 -> V_46 ) ;
return V_40 ;
}
static void F_35 ( struct V_7 * V_4 , struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_43 ) ;
}
static void F_37 ( struct V_7 * V_4 , struct V_1 * V_2 )
{
if ( F_38 ( & V_2 -> V_43 ) )
F_39 ( & V_4 -> V_47 ) ;
}
static int
F_40 ( struct V_7 * V_4 , int * V_48 ,
T_1 V_10 , T_1 V_11 , T_1 V_12 , T_3 V_13 , T_4 V_14 , int V_15 )
{
return F_41 ( V_4 -> V_47 ,
( * V_48 = F_31 ( V_4 , V_10 , V_11 , V_12 ,
V_13 , V_14 , V_15 ) )
!= - V_44 ) ;
}
static int
F_42 ( struct V_7 * V_4 ,
T_1 V_10 , T_1 V_11 , T_1 V_12 ,
T_3 V_13 , T_4 V_14 , int V_15 , int V_49 )
{
unsigned long V_50 ;
int V_48 , V_51 ;
if ( V_14 > ( 1 << 24 ) )
return - V_19 ;
F_32 ( & V_4 -> V_46 , V_50 ) ;
V_48 = F_27 ( V_4 , V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_48 >= 0 ) {
F_35 ( V_4 , & V_4 -> V_2 [ V_48 ] ) ;
F_33 ( & V_4 -> V_46 , V_50 ) ;
return V_48 ;
}
V_48 = F_28 ( V_4 , V_10 , V_11 , V_12 ,
V_13 , V_14 , V_15 ) ;
if ( V_48 < 0 ) {
if ( V_49 )
goto V_52;
F_33 ( & V_4 -> V_46 , V_50 ) ;
V_51 = F_40 ( V_4 , & V_48 , V_10 , V_11 , V_12 ,
V_13 , V_14 , V_15 ) ;
if ( V_51 )
return V_51 ;
F_43 ( & V_4 -> V_46 ) ;
}
F_35 ( V_4 , & V_4 -> V_2 [ V_48 ] ) ;
V_51 = F_21 ( V_4 , & V_4 -> V_2 [ V_48 ] ,
V_10 , V_11 , V_12 , V_13 , V_14 , V_15 ) ;
if ( V_51 < 0 ) {
F_37 ( V_4 , & V_4 -> V_2 [ V_48 ] ) ;
V_48 = V_51 ;
}
V_52:
F_33 ( & V_4 -> V_46 , V_50 ) ;
return V_48 ;
}
static int F_44 ( const void * V_53 , const void * V_54 )
{
const struct V_1 * V_55 = V_53 , * V_56 = V_54 ;
if ( V_55 -> V_16 == V_56 -> V_16 )
return V_55 -> V_6 - V_56 -> V_6 ;
else
return V_55 -> V_16 - V_56 -> V_16 ;
}
static int F_45 ( struct V_7 * V_4 , T_5 V_57 )
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
char V_67 [ 196 ] = {} ;
struct V_1 * V_2 ;
int V_68 , V_69 ;
int V_70 ;
char * V_71 , * V_72 ;
V_71 = V_67 +
snprintf ( V_67 , sizeof( V_67 ) - 1 , L_2 ) ;
V_72 = V_67 + sizeof( V_67 ) - 1 ;
V_2 = & V_4 -> V_2 [ 0 ] ;
for ( V_68 = 0 ; V_68 < F_46 ( V_4 -> V_2 ) ; V_68 ++ , V_2 ++ ) {
struct V_73 * V_74 ;
V_74 = & V_4 -> V_5 -> V_73 [ ( V_68 >> 3 ) * 2 ] ;
if ( ! ( F_47 ( V_74 ) & V_75 ) ) {
V_2 -- ;
continue;
}
V_2 -> V_73 = V_74 ;
V_2 -> V_3 = 0 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = V_68 ;
V_2 -> V_24 = F_3 ( V_2 ) - 1 ;
V_2 -> V_16 = F_48 ( V_2 -> V_24 ) ;
V_2 -> V_27 = 0 ;
V_2 -> V_30 = NULL ;
}
V_4 -> V_41 = V_2 - & V_4 -> V_2 [ 0 ] ;
if ( V_4 -> V_41 < 8 ) {
F_49 ( V_4 -> V_76 , L_3 ) ;
return - V_19 ;
}
V_69 = V_4 -> V_41 ;
F_50 ( & V_4 -> V_77 . V_78 ) ;
V_4 -> V_77 . V_79 = ( ( F_51 ( V_57 ) & 3 ) + 4 )
<< 4 ;
V_4 -> V_77 . V_80 = 0x10 ;
V_2 = & V_4 -> V_2 [ 0 ] ;
if ( F_3 ( V_2 ) >= V_81 )
V_2 -> V_30 = F_52 ( F_5 ( V_2 ) ,
F_3 ( V_2 ) ) ;
if ( V_2 -> V_30 ) {
V_71 += snprintf ( V_71 , V_72 - V_71 , L_4 ) ;
F_36 ( & V_2 -> V_43 ) ;
V_69 -- ;
F_15 ( V_4 , V_2 , V_58 ) ;
V_4 -> V_77 . V_82 = V_2 -> V_30 + V_83 + 0x1000 ;
if ( V_4 -> V_5 -> V_84 == V_85 ||
V_4 -> V_5 -> V_84 == V_86 ) {
V_4 -> V_30 . V_31 = V_2 -> V_30 + F_53 ( 0 ) ;
} else {
int V_87 = V_4 -> V_5 -> V_88 & 7 ;
V_4 -> V_30 . V_31 = V_2 -> V_30 + F_53 ( V_87 ) ;
}
V_4 -> V_30 . V_89 = V_2 -> V_30 + V_90 ;
}
if ( V_4 -> V_5 -> V_84 == V_85 ||
V_4 -> V_5 -> V_84 == V_86 )
V_70 = 4 ;
else
V_70 = 1 ;
V_2 = & V_4 -> V_2 [ 1 ] ;
V_71 += snprintf ( V_71 , V_72 - V_71 , L_5 ) ;
F_36 ( & V_2 -> V_43 ) ;
V_69 -- ;
F_15 ( V_4 , V_2 , V_60 ) ;
for ( V_68 = 0 ; V_68 < 4 ; V_68 ++ ) {
int V_91 ;
if ( V_68 >= V_92 || V_68 >= V_70 ) {
V_4 -> V_77 . V_93 [ V_68 ] . V_16 = 0 ;
continue;
}
V_2 = & V_4 -> V_2 [ 4 + V_68 ] ;
V_2 -> V_30 = F_52 ( F_5 ( V_2 ) ,
F_3 ( V_2 ) ) ;
if ( V_2 -> V_30 ) {
V_71 += snprintf ( V_71 , V_72 - V_71 ,
L_6 , 4 + V_68 , V_68 ) ;
F_36 ( & V_2 -> V_43 ) ;
V_69 -- ;
V_4 -> V_77 . V_93 [ V_68 ] . V_16 = V_2 -> V_16 ;
V_4 -> V_77 . V_93 [ V_68 ] . V_94 = V_2 -> V_30 ;
F_15 ( V_4 , V_2 , V_62 [ V_68 ] ) ;
for ( V_91 = 0 ; V_91 < 4 ; V_91 ++ )
V_4 -> V_77 . V_93 [ V_68 ] . free [ V_91 ] = true ;
}
V_4 -> V_30 . V_77 [ V_68 ] = V_2 -> V_30 ;
}
F_54 ( & V_4 -> V_2 [ 0 ] , V_4 -> V_41 , sizeof( V_4 -> V_2 [ 0 ] ) ,
F_44 , NULL ) ;
F_55 ( V_4 -> V_76 , L_7 , V_67 , V_69 , V_4 -> V_41 ) ;
return 0 ;
}
static void F_56 ( struct V_7 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 [ 0 ] ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_4 -> V_41 ; V_40 ++ , V_2 ++ ) {
if ( V_2 -> V_30 ) {
F_57 ( V_2 -> V_30 ) ;
V_2 -> V_30 = NULL ;
}
}
}
static int F_58 ( struct V_95 * V_96 , T_1 V_97 ,
unsigned long long V_98 , unsigned long V_14 )
{
struct V_99 * V_100 = F_59 ( V_96 ) ;
T_1 V_101 = F_60 ( V_97 ) ;
T_1 V_102 = F_61 ( V_97 ) ;
T_1 V_103 = F_62 ( V_97 ) ;
int V_104 ;
V_104 = F_63 ( F_64 ( V_101 , V_102 , V_103 ) , V_98 ) ;
if ( V_104 < 0 )
return V_104 ;
V_100 -> V_15 . V_105 = F_65 ( V_104 ) ;
V_100 -> V_15 . V_106 = F_66 ( V_104 ) ;
if ( V_100 -> V_15 . V_105 > 0 &&
V_100 -> V_15 . V_106 > 0 &&
V_100 -> V_15 . V_105 != V_100 -> V_15 . V_106 ) {
return - V_19 ;
}
if ( V_100 -> V_15 . V_105 > 0 )
V_100 -> V_15 . V_2 = V_100 -> V_15 . V_105 ;
else
V_100 -> V_15 . V_2 = V_100 -> V_15 . V_106 ;
F_67 ( & V_100 -> V_43 , 0 ) ;
V_100 -> V_2 = NULL ;
V_100 -> V_101 = V_101 ;
V_100 -> V_102 = V_102 ;
V_100 -> V_103 = V_103 ;
V_100 -> V_13 = V_98 ;
V_100 -> V_14 = V_14 ;
memset ( & V_100 -> V_73 , 0 , sizeof( V_100 -> V_73 ) ) ;
return 0 ;
}
static void F_68 ( struct V_95 * V_96 )
{
}
static void F_69 ( struct V_95 * V_96 )
{
struct V_99 * V_100 = F_59 ( V_96 ) ;
F_36 ( & V_100 -> V_43 ) ;
}
static int F_70 ( struct V_95 * V_96 )
{
struct V_99 * V_100 = F_59 ( V_96 ) ;
if ( F_71 ( ! F_29 ( & V_100 -> V_43 ) ) )
return 0 ;
return F_38 ( & V_100 -> V_43 ) ;
}
static int F_72 ( struct V_95 * V_96 )
{
struct V_7 * V_4 = F_73 ( F_74 ( V_96 ) ) ;
struct V_99 * V_100 = F_59 ( V_96 ) ;
int V_48 , V_33 ;
if ( V_100 -> V_2 ) {
F_69 ( V_96 ) ;
return 0 ;
}
V_48 = F_42 ( V_4 , V_100 -> V_101 , V_100 -> V_102 , V_100 -> V_103 ,
V_100 -> V_13 , V_100 -> V_14 , V_100 -> V_15 . V_2 , 1 ) ;
if ( V_48 < 0 ) {
V_33 = V_48 ;
goto V_107;
}
V_100 -> V_2 = & V_4 -> V_2 [ V_48 ] ;
if ( F_1 ( V_100 -> V_2 ) ==
V_59 ) {
V_100 -> V_108 = V_100 -> V_13 &
( F_75 ( V_100 -> V_2 ) - 1 ) ;
V_100 -> V_108 += F_76 (
V_100 -> V_2 , V_100 -> V_101 ) ;
V_100 -> V_108 += F_77 (
V_100 -> V_2 , V_100 -> V_103 ) ;
} else {
V_100 -> V_108 = V_100 -> V_13 & V_100 -> V_2 -> V_24 ;
}
V_100 -> V_109 = F_5 ( V_100 -> V_2 ) + V_100 -> V_108 ;
V_100 -> V_73 . V_110 = F_78 ( V_96 ) ;
V_100 -> V_73 . V_111 = V_100 -> V_109 ;
V_100 -> V_73 . V_72 = V_100 -> V_73 . V_111 + V_100 -> V_14 - 1 ;
V_100 -> V_73 . V_45 = V_75 ;
if ( V_100 -> V_2 -> V_30 )
V_100 -> V_30 = V_100 -> V_2 -> V_30 + V_100 -> V_108 ;
else
V_100 -> V_30 = F_52 ( V_100 -> V_109 , V_100 -> V_14 ) ;
if ( F_79 ( V_100 -> V_30 ) ) {
F_49 ( V_4 -> V_76 , L_8 ,
( int ) V_100 -> V_14 , V_100 -> V_2 -> V_6 ) ;
V_33 = ! V_100 -> V_30 ? - V_112 : F_80 ( V_100 -> V_30 ) ;
V_100 -> V_30 = NULL ;
goto V_113;
}
F_69 ( V_96 ) ;
return 0 ;
V_113:
F_37 ( V_4 , V_100 -> V_2 ) ;
V_100 -> V_2 = NULL ;
V_107:
return V_33 ;
}
static void F_81 ( struct V_95 * V_96 )
{
struct V_7 * V_4 = F_73 ( F_74 ( V_96 ) ) ;
struct V_99 * V_100 = F_59 ( V_96 ) ;
if ( ! F_70 ( V_96 ) )
return;
if ( ! V_100 -> V_2 -> V_30 )
F_57 ( V_100 -> V_30 ) ;
F_37 ( V_4 , V_100 -> V_2 ) ;
V_100 -> V_2 = NULL ;
V_100 -> V_30 = NULL ;
}
static T_6 F_82 ( struct V_95 * V_96 )
{
struct V_99 * V_100 = F_59 ( V_96 ) ;
return V_100 -> V_109 ;
}
static void T_7 * F_83 ( struct V_95 * V_96 )
{
struct V_99 * V_100 = F_59 ( V_96 ) ;
return V_100 -> V_30 ;
}
static struct V_73 * F_84 ( struct V_95 * V_96 )
{
struct V_99 * V_100 = F_59 ( V_96 ) ;
return V_100 -> V_2 -> V_73 ;
}
static int F_85 ( struct V_95 * V_96 , void * V_114 ,
unsigned long V_13 , unsigned int V_115 )
{
T_3 T_8 * V_116 = V_114 ;
const T_3 T_7 T_8 * V_117 ;
struct V_99 * V_100 ;
T_1 * V_118 = V_114 ;
const T_1 T_7 * V_119 ;
int V_40 , V_15 ;
bool V_120 ;
V_100 = F_59 ( V_96 ) ;
V_117 = V_100 -> V_30 + V_13 ;
V_119 = V_100 -> V_30 + V_13 ;
if ( V_13 + V_115 > V_100 -> V_14 )
return - V_121 ;
V_15 = V_100 -> V_15 . V_105 ;
if ( V_15 <= 0 )
return - V_19 ;
if ( ( V_100 -> V_13 + V_13 ) & ( V_15 - 1 ) )
return F_86 ( F_74 ( V_96 ) ,
F_64 ( V_100 -> V_101 ,
V_100 -> V_102 ,
V_100 -> V_103 ) ,
V_100 -> V_13 + V_13 ,
V_114 , V_115 , V_15 ) ;
V_120 = V_15 == V_122 ;
if ( V_100 -> V_101 == ( V_123 & V_124 ) &&
V_100 -> V_102 == V_23 )
V_120 = false ;
if ( V_120 ) {
if ( V_13 % sizeof( T_3 ) != 0 || V_115 % sizeof( T_3 ) != 0 )
return - V_19 ;
} else {
if ( V_13 % sizeof( T_1 ) != 0 || V_115 % sizeof( T_1 ) != 0 )
return - V_19 ;
}
if ( F_71 ( ! V_100 -> V_2 ) )
return - V_121 ;
if ( V_120 )
#ifndef F_87
return - V_19 ;
#else
for ( V_40 = 0 ; V_40 < V_115 ; V_40 += sizeof( T_3 ) )
* V_116 ++ = F_87 ( V_117 ++ ) ;
#endif
else
for ( V_40 = 0 ; V_40 < V_115 ; V_40 += sizeof( T_1 ) )
* V_118 ++ = F_88 ( V_119 ++ ) ;
return V_40 ;
}
static int
F_89 ( struct V_95 * V_96 ,
const void * V_114 ,
unsigned long V_13 , unsigned int V_115 )
{
const T_3 T_8 * V_117 = V_114 ;
T_3 T_7 T_8 * V_116 ;
const T_1 * V_119 = V_114 ;
struct V_99 * V_100 ;
T_1 T_7 * V_118 ;
int V_40 , V_15 ;
bool V_120 ;
V_100 = F_59 ( V_96 ) ;
V_116 = V_100 -> V_30 + V_13 ;
V_118 = V_100 -> V_30 + V_13 ;
if ( V_13 + V_115 > V_100 -> V_14 )
return - V_121 ;
V_15 = V_100 -> V_15 . V_106 ;
if ( V_15 <= 0 )
return - V_19 ;
if ( ( V_100 -> V_13 + V_13 ) & ( V_15 - 1 ) )
return F_90 ( F_74 ( V_96 ) ,
F_64 ( V_100 -> V_101 ,
V_100 -> V_102 ,
V_100 -> V_103 ) ,
V_100 -> V_13 + V_13 ,
V_114 , V_115 , V_15 ) ;
V_120 = V_15 == V_122 ;
if ( V_100 -> V_101 == ( V_123 & V_124 ) &&
V_100 -> V_102 == V_23 )
V_120 = false ;
if ( V_120 ) {
if ( V_13 % sizeof( T_3 ) != 0 || V_115 % sizeof( T_3 ) != 0 )
return - V_19 ;
} else {
if ( V_13 % sizeof( T_1 ) != 0 || V_115 % sizeof( T_1 ) != 0 )
return - V_19 ;
}
if ( F_71 ( ! V_100 -> V_2 ) )
return - V_121 ;
if ( V_120 )
#ifndef F_91
return - V_19 ;
#else
for ( V_40 = 0 ; V_40 < V_115 ; V_40 += sizeof( T_3 ) ) {
F_91 ( * V_117 ++ , V_116 ++ ) ;
F_92 () ;
}
#endif
else
for ( V_40 = 0 ; V_40 < V_115 ; V_40 += sizeof( T_1 ) ) {
F_93 ( * V_119 ++ , V_118 ++ ) ;
F_92 () ;
}
return V_40 ;
}
static int F_94 ( struct V_125 * V_77 )
{
struct V_7 * V_4 = F_73 ( F_95 ( V_77 ) ) ;
struct V_126 * V_100 = F_96 ( V_77 ) ;
int V_68 , V_91 ;
F_97 ( & V_4 -> V_77 . V_78 ) ;
for ( V_68 = 0 ; V_68 < F_46 ( V_4 -> V_77 . V_93 ) ; V_68 ++ ) {
if ( ! V_4 -> V_77 . V_93 [ V_68 ] . V_16 )
continue;
for ( V_91 = 0 ; V_91 < F_46 ( V_4 -> V_77 . V_93 [ V_68 ] . free ) ; V_91 ++ ) {
T_5 V_127 ;
if ( ! V_4 -> V_77 . V_93 [ V_68 ] . free [ V_91 ] )
continue;
V_100 -> V_4 = V_4 ;
V_100 -> V_2 . V_93 = V_68 ;
V_100 -> V_2 . V_96 = V_91 ;
V_100 -> V_16 = V_4 -> V_77 . V_93 [ V_68 ] . V_16 - 2 ;
V_127 = ( V_100 -> V_2 . V_93 << 9 ) +
( V_100 -> V_2 . V_96 << 7 ) ;
V_100 -> V_82 = V_4 -> V_77 . V_82 + V_127 ;
V_100 -> V_94 = V_4 -> V_77 . V_93 [ V_68 ] . V_94 +
( V_100 -> V_2 . V_96 << V_100 -> V_16 ) ;
V_4 -> V_77 . V_93 [ V_68 ] . free [ V_91 ] = false ;
F_98 ( & V_4 -> V_77 . V_78 ) ;
return 0 ;
}
}
F_98 ( & V_4 -> V_77 . V_78 ) ;
return - V_44 ;
}
static void F_99 ( struct V_125 * V_77 )
{
struct V_126 * V_100 = F_96 ( V_77 ) ;
struct V_7 * V_4 = V_100 -> V_4 ;
F_97 ( & V_4 -> V_77 . V_78 ) ;
V_4 -> V_77 . V_93 [ V_100 -> V_2 . V_93 ] . free [ V_100 -> V_2 . V_96 ] = true ;
F_98 ( & V_4 -> V_77 . V_78 ) ;
}
static int F_100 ( struct V_125 * V_77 ,
const void * V_128 , T_4 V_129 )
{
struct V_126 * V_100 = F_96 ( V_77 ) ;
const T_1 * V_130 = V_128 ;
T_4 V_68 ;
for ( V_68 = 0 ; V_68 < V_129 ; V_68 += sizeof( T_1 ) )
F_17 ( * ( V_130 ++ ) , V_100 -> V_82 + V_68 ) ;
return V_68 ;
}
static int
F_101 ( struct V_125 * V_77 ,
const struct V_131 * V_132 , T_3 V_98 )
{
struct V_126 * V_100 = F_96 ( V_77 ) ;
T_9 V_133 , V_80 , V_134 ;
struct V_7 * V_4 = V_100 -> V_4 ;
int V_135 = 0 ;
T_5 V_136 ;
T_1 V_31 [ 3 ] ;
if ( V_132 -> V_137 )
V_135 |= 1 << V_132 -> V_138 ;
if ( V_132 -> V_139 )
V_135 |= 1 << V_132 -> V_140 ;
V_133 = V_132 -> V_133 ;
if ( ! V_133 )
V_133 = V_4 -> V_77 . V_79 ;
V_80 = V_132 -> V_80 ;
if ( V_133 == V_4 -> V_77 . V_79 )
V_80 = V_4 -> V_77 . V_80 +
( ( V_100 -> V_2 . V_93 * 4 + V_100 -> V_2 . V_96 ) << 1 ) ;
V_134 = V_132 -> V_134 ;
if ( ! V_134 )
V_134 = V_4 -> V_77 . V_79 ;
V_136 = V_132 -> V_136 ;
if ( V_134 == V_4 -> V_77 . V_79 )
V_136 = 0x1000 +
( V_100 -> V_2 . V_93 << 9 ) + ( V_100 -> V_2 . V_96 << 7 ) ;
V_31 [ 0 ] = F_102 ( V_135 ) |
F_103 (
F_62 ( V_132 -> V_141 ) ) |
F_104 ( V_98 >> 16 ) ;
V_31 [ 1 ] = F_105 ( V_80 ) |
F_106 ( V_134 ) |
F_107 ( V_136 ) ;
V_31 [ 2 ] = F_108 (
F_60 ( V_132 -> V_141 ) ) |
F_109 (
F_61 ( V_132 -> V_141 ) ) |
F_110 ( V_132 -> V_129 ) |
F_111 ( V_132 -> V_142 ) |
F_112 ( V_133 ) ;
if ( V_4 -> V_30 . V_31 ) {
F_17 ( V_31 [ 0 ] , V_4 -> V_30 . V_31 +
F_113 ( V_100 -> V_2 . V_93 ,
V_100 -> V_2 . V_96 ) ) ;
F_17 ( V_31 [ 1 ] , V_4 -> V_30 . V_31 +
F_114 ( V_100 -> V_2 . V_93 ,
V_100 -> V_2 . V_96 ) ) ;
F_17 ( V_31 [ 2 ] , V_4 -> V_30 . V_31 +
F_115 ( V_100 -> V_2 . V_93 ,
V_100 -> V_2 . V_96 ) ) ;
F_18 ( V_4 -> V_30 . V_31 +
F_113 ( V_100 -> V_2 . V_93 ,
V_100 -> V_2 . V_96 ) ) ;
F_18 ( V_4 -> V_30 . V_31 +
F_114 ( V_100 -> V_2 . V_93 ,
V_100 -> V_2 . V_96 ) ) ;
F_18 ( V_4 -> V_30 . V_31 +
F_115 ( V_100 -> V_2 . V_93 ,
V_100 -> V_2 . V_96 ) ) ;
} else {
F_20 ( V_4 -> V_5 , 0x400 +
F_113 (
V_100 -> V_2 . V_93 , V_100 -> V_2 . V_96 ) ,
V_31 [ 0 ] ) ;
F_20 ( V_4 -> V_5 , 0x400 +
F_114 (
V_100 -> V_2 . V_93 , V_100 -> V_2 . V_96 ) ,
V_31 [ 1 ] ) ;
F_20 ( V_4 -> V_5 , 0x400 +
F_115 (
V_100 -> V_2 . V_93 , V_100 -> V_2 . V_96 ) ,
V_31 [ 2 ] ) ;
}
F_116 ( V_100 -> V_94 + ( V_98 & ( ( 1 << V_100 -> V_16 ) - 1 ) ) ) ;
return V_135 ;
}
static int F_117 ( struct V_125 * V_77 ,
void * V_128 , T_4 V_129 )
{
struct V_126 * V_100 = F_96 ( V_77 ) ;
T_1 * V_143 = V_128 ;
T_4 V_68 ;
for ( V_68 = 0 ; V_68 < V_129 ; V_68 += sizeof( T_1 ) )
* ( V_143 ++ ) = F_18 ( V_100 -> V_82 + V_68 ) ;
return V_68 ;
}
static int F_118 ( struct V_144 * V_145 )
{
F_119 ( V_145 , V_146 ) ;
F_119 ( V_145 , V_146 ) ;
F_119 ( V_145 , V_147 ) ;
return 0 ;
}
static void F_120 ( struct V_144 * V_145 )
{
struct V_7 * V_4 = F_73 ( V_145 ) ;
F_56 ( V_4 ) ;
F_121 ( V_4 ) ;
}
static void F_122 ( struct V_84 * V_76 , T_9 * V_148 )
{
struct V_149 * V_5 = F_123 ( V_76 ) ;
int V_150 ;
T_1 V_151 ;
V_150 = F_124 ( V_5 , V_152 ) ;
if ( ! V_150 ) {
memset ( V_148 , 0 , V_153 ) ;
return;
}
F_125 ( V_5 , V_150 + 4 , & V_151 ) ;
F_126 ( V_151 >> 16 , V_148 + 4 ) ;
F_125 ( V_5 , V_150 + 8 , & V_151 ) ;
F_127 ( V_151 , V_148 ) ;
}
static T_5 F_128 ( struct V_84 * V_76 )
{
struct V_149 * V_5 = F_123 ( V_76 ) ;
int V_150 ;
T_1 V_151 ;
V_150 = F_124 ( V_5 , V_152 ) ;
if ( ! V_150 )
return F_129 ( V_154 , 0 , 0xff ) ;
F_125 ( V_5 , V_150 + 4 , & V_151 ) ;
return V_151 & 0xffff ;
}
struct V_144 * F_130 ( struct V_149 * V_5 )
{
struct V_7 * V_4 ;
T_5 V_57 ;
int V_33 ;
F_55 ( & V_5 -> V_76 ,
L_9 ) ;
V_4 = F_131 ( sizeof( * V_4 ) , V_155 ) ;
if ( ! V_4 ) {
V_33 = - V_112 ;
goto V_156;
}
V_4 -> V_76 = & V_5 -> V_76 ;
V_4 -> V_5 = V_5 ;
F_132 ( & V_4 -> V_47 ) ;
F_133 ( & V_4 -> V_46 ) ;
V_57 = F_128 ( & V_5 -> V_76 ) ;
if ( F_134 ( V_57 ) !=
V_154 ) {
F_49 ( & V_5 -> V_76 ,
L_10 ,
F_134 ( V_57 ) ,
V_154 ) ;
V_33 = - V_157 ;
goto V_158;
}
if ( F_135 ( V_57 ) !=
V_159 ) {
F_49 ( & V_5 -> V_76 , L_11 ,
F_135 ( V_57 ) ,
V_159 ) ;
V_33 = - V_157 ;
goto V_158;
}
V_33 = F_45 ( V_4 , V_57 ) ;
if ( V_33 )
goto V_158;
return F_136 ( & V_160 , & V_5 -> V_76 , V_4 ) ;
V_158:
F_121 ( V_4 ) ;
V_156:
F_49 ( & V_5 -> V_76 , L_12 ) ;
return F_137 ( V_33 ) ;
}
