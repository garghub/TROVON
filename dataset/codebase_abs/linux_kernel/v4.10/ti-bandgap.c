static T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_1 V_5 , T_1 V_3 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 , bool V_6 )
{
int V_7 ;
if ( ! F_6 ( V_2 , V_8 ) )
return - V_9 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_10 -> V_11 ; V_7 ++ )
F_7 ( V_2 , V_7 , V_12 , V_13 , ! V_6 ) ;
return 0 ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_14 , V_15 ;
V_14 = F_1 ( V_2 , V_3 ) ;
V_15 = F_1 ( V_2 , V_3 ) ;
if ( V_14 == V_15 )
return V_14 ;
return F_1 ( V_2 , V_3 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , int V_16 )
{
struct V_17 * V_18 ;
T_1 V_19 , V_3 ;
V_18 = V_2 -> V_10 -> V_20 [ V_16 ] . V_21 ;
V_3 = V_18 -> V_12 ;
if ( F_6 ( V_2 , V_22 ) ) {
F_7 ( V_2 , V_16 , V_23 , V_24 , 1 ) ;
V_3 = V_18 -> V_25 ;
}
if ( F_6 ( V_2 , V_26 ) )
V_19 = F_8 ( V_2 , V_3 ) ;
else
V_19 = F_1 ( V_2 , V_3 ) ;
V_19 &= V_18 -> V_27 ;
if ( F_6 ( V_2 , V_22 ) )
F_7 ( V_2 , V_16 , V_23 , V_24 , 0 ) ;
return V_19 ;
}
static T_2 F_10 ( int V_28 , void * V_29 )
{
struct V_1 * V_2 = V_29 ;
struct V_17 * V_18 ;
T_1 V_30 = 0 , V_31 = 0 , V_32 ;
int V_7 ;
F_11 ( & V_2 -> V_33 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_10 -> V_11 ; V_7 ++ ) {
V_18 = V_2 -> V_10 -> V_20 [ V_7 ] . V_21 ;
V_32 = F_1 ( V_2 , V_18 -> V_34 ) ;
V_30 = V_32 & V_18 -> V_35 ;
V_31 = V_32 & V_18 -> V_36 ;
if ( ! V_31 && ! V_30 )
continue;
V_32 = F_1 ( V_2 , V_18 -> V_23 ) ;
if ( V_30 ) {
V_32 &= ~ V_18 -> V_37 ;
V_32 |= V_18 -> V_38 ;
} else if ( V_31 ) {
V_32 &= ~ V_18 -> V_38 ;
V_32 |= V_18 -> V_37 ;
}
F_3 ( V_2 , V_32 , V_18 -> V_23 ) ;
F_12 ( V_2 -> V_39 ,
L_1 ,
V_40 , V_2 -> V_10 -> V_20 [ V_7 ] . V_41 ,
V_30 , V_31 ) ;
if ( V_2 -> V_10 -> V_42 )
V_2 -> V_10 -> V_42 ( V_2 , V_7 ) ;
}
F_13 ( & V_2 -> V_33 ) ;
return V_43 ;
}
static T_2 F_14 ( int V_28 , void * V_29 )
{
F_15 ( L_2 ,
V_40 ) ;
F_16 ( true ) ;
return V_43 ;
}
static
int F_17 ( struct V_1 * V_2 , int V_44 , int * V_45 )
{
const struct V_46 * V_10 = V_2 -> V_10 ;
if ( V_44 < V_10 -> V_47 || V_44 > V_10 -> V_48 )
return - V_49 ;
* V_45 = V_2 -> V_10 -> V_50 [ V_44 - V_10 -> V_47 ] ;
return 0 ;
}
static
int F_18 ( struct V_1 * V_2 , long V_19 , int * V_51 )
{
const struct V_46 * V_10 = V_2 -> V_10 ;
const int * V_50 = V_2 -> V_10 -> V_50 ;
int V_52 , V_53 , V_54 ;
V_53 = 0 ;
V_52 = V_10 -> V_48 - V_10 -> V_47 ;
V_54 = ( V_52 + V_53 ) / 2 ;
if ( V_19 < V_50 [ V_53 ] || V_19 > V_50 [ V_52 ] )
return - V_49 ;
while ( V_53 < V_52 ) {
if ( V_19 < V_50 [ V_54 ] )
V_52 = V_54 - 1 ;
else
V_53 = V_54 + 1 ;
V_54 = ( V_53 + V_52 ) / 2 ;
}
* V_51 = V_10 -> V_47 + V_53 ;
return 0 ;
}
static
int F_19 ( struct V_1 * V_2 , int V_44 , int V_55 ,
T_1 * V_56 )
{
int V_19 , V_57 ;
V_57 = F_17 ( V_2 , V_44 , & V_19 ) ;
if ( V_57 < 0 )
return V_57 ;
V_19 += V_55 ;
V_57 = F_18 ( V_2 , V_19 , V_56 ) ;
return V_57 ;
}
static void F_20 ( struct V_1 * V_2 , int V_16 ,
T_1 V_30 , T_1 V_31 )
{
struct V_17 * V_18 ;
T_1 V_19 , V_58 ;
V_19 = F_9 ( V_2 , V_16 ) ;
V_18 = V_2 -> V_10 -> V_20 [ V_16 ] . V_21 ;
V_58 = F_1 ( V_2 , V_18 -> V_23 ) ;
if ( V_19 < V_30 )
V_58 |= V_18 -> V_37 ;
else
V_58 &= ~ V_18 -> V_37 ;
if ( V_31 < V_19 )
V_58 |= V_18 -> V_38 ;
else
V_58 &= ~ V_18 -> V_38 ;
F_3 ( V_2 , V_58 , V_18 -> V_23 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_16 ,
int V_5 , bool V_59 )
{
struct V_60 * V_61 = V_2 -> V_10 -> V_20 [ V_16 ] . V_61 ;
struct V_17 * V_18 ;
T_1 V_62 , V_58 , V_30 , V_31 , V_32 ;
int V_63 = 0 ;
V_18 = V_2 -> V_10 -> V_20 [ V_16 ] . V_21 ;
V_62 = F_1 ( V_2 , V_18 -> V_64 ) ;
V_31 = ( V_62 & V_18 -> V_65 ) >>
F_22 ( V_18 -> V_65 ) ;
V_30 = ( V_62 & V_18 -> V_66 ) >>
F_22 ( V_18 -> V_66 ) ;
if ( V_59 )
V_30 = V_5 ;
else
V_31 = V_5 ;
if ( V_31 > V_30 ) {
if ( V_59 )
V_63 = F_19 ( V_2 , V_30 ,
- V_61 -> V_55 ,
& V_31 ) ;
else
V_63 = F_19 ( V_2 , V_31 ,
V_61 -> V_55 ,
& V_30 ) ;
}
V_58 = V_62 &
~ ( V_18 -> V_66 | V_18 -> V_65 ) ;
V_58 |= ( V_30 << F_22 ( V_18 -> V_66 ) ) |
( V_31 << F_22 ( V_18 -> V_65 ) ) ;
if ( F_6 ( V_2 , V_67 ) ) {
V_32 = F_1 ( V_2 , V_18 -> V_23 ) ;
if ( V_59 )
V_32 &= ~ V_18 -> V_37 ;
else
V_32 &= ~ V_18 -> V_38 ;
F_3 ( V_2 , V_32 , V_18 -> V_23 ) ;
}
F_3 ( V_2 , V_58 , V_18 -> V_64 ) ;
if ( F_6 ( V_2 , V_67 ) ) {
V_32 = F_1 ( V_2 , V_18 -> V_23 ) ;
if ( V_59 )
V_32 |= V_18 -> V_37 ;
else
V_32 |= V_18 -> V_38 ;
F_3 ( V_2 , V_32 , V_18 -> V_23 ) ;
}
if ( V_63 ) {
F_23 ( V_2 -> V_39 , L_3 ) ;
V_63 = - V_68 ;
goto exit;
}
F_20 ( V_2 , V_16 , V_30 , V_31 ) ;
exit:
return V_63 ;
}
static inline int F_24 ( struct V_1 * V_2 , int V_16 )
{
if ( ! V_2 || F_25 ( V_2 ) ) {
F_26 ( L_4 , V_40 ) ;
return - V_69 ;
}
if ( ( V_16 < 0 ) || ( V_16 >= V_2 -> V_10 -> V_11 ) ) {
F_23 ( V_2 -> V_39 , L_5 ,
V_40 , V_16 ) ;
return - V_49 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , int V_16 , int V_5 ,
bool V_59 )
{
struct V_60 * V_61 ;
struct V_17 * V_18 ;
T_1 V_44 ;
int V_57 ;
V_57 = F_24 ( V_2 , V_16 ) ;
if ( V_57 )
return V_57 ;
if ( ! F_6 ( V_2 , V_70 ) )
return - V_9 ;
V_61 = V_2 -> V_10 -> V_20 [ V_16 ] . V_61 ;
V_18 = V_2 -> V_10 -> V_20 [ V_16 ] . V_21 ;
if ( V_59 ) {
if ( V_5 < V_61 -> V_71 + V_61 -> V_55 )
V_57 = - V_69 ;
} else {
if ( V_5 > V_61 -> V_72 + V_61 -> V_55 )
V_57 = - V_69 ;
}
if ( V_57 )
return V_57 ;
V_57 = F_18 ( V_2 , V_5 , & V_44 ) ;
if ( V_57 < 0 )
return V_57 ;
F_11 ( & V_2 -> V_33 ) ;
V_57 = F_21 ( V_2 , V_16 , V_44 , V_59 ) ;
F_13 ( & V_2 -> V_33 ) ;
return V_57 ;
}
static int F_28 ( struct V_1 * V_2 , int V_16 ,
int * V_5 , bool V_59 )
{
struct V_17 * V_18 ;
T_1 V_19 , V_73 ;
int V_57 = 0 ;
V_57 = F_24 ( V_2 , V_16 ) ;
if ( V_57 )
goto exit;
if ( ! F_6 ( V_2 , V_70 ) ) {
V_57 = - V_9 ;
goto exit;
}
V_18 = V_2 -> V_10 -> V_20 [ V_16 ] . V_21 ;
if ( V_59 )
V_73 = V_18 -> V_66 ;
else
V_73 = V_18 -> V_65 ;
V_19 = F_1 ( V_2 , V_18 -> V_64 ) ;
V_19 = ( V_19 & V_73 ) >> F_22 ( V_73 ) ;
V_57 = F_17 ( V_2 , V_19 , & V_19 ) ;
if ( V_57 ) {
F_23 ( V_2 -> V_39 , L_6 ) ;
V_57 = - V_68 ;
goto exit;
}
* V_5 = V_19 ;
exit:
return V_57 ;
}
int F_29 ( struct V_1 * V_2 , int V_16 , int * V_74 )
{
return F_28 ( V_2 , V_16 , V_74 , true ) ;
}
int F_30 ( struct V_1 * V_2 , int V_16 , int V_5 )
{
return F_27 ( V_2 , V_16 , V_5 , true ) ;
}
int F_31 ( struct V_1 * V_2 , int V_16 , int * V_75 )
{
return F_28 ( V_2 , V_16 , V_75 , false ) ;
}
int F_32 ( struct V_1 * V_2 , int V_16 , int V_5 )
{
return F_27 ( V_2 , V_16 , V_5 , false ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_16 ,
int * V_76 )
{
struct V_17 * V_18 ;
int time ;
V_18 = V_2 -> V_10 -> V_20 [ V_16 ] . V_21 ;
time = F_1 ( V_2 , V_18 -> V_77 ) ;
time = ( time & V_18 -> V_78 ) >>
F_22 ( V_18 -> V_78 ) ;
time = time * 1000 / V_2 -> V_79 ;
* V_76 = time ;
}
static void F_34 ( struct V_1 * V_2 , int V_16 ,
int * V_76 )
{
struct V_17 * V_18 ;
int V_58 ;
V_18 = V_2 -> V_10 -> V_20 [ V_16 ] . V_21 ;
V_58 = F_1 ( V_2 , V_18 -> V_23 ) ;
V_58 = ( V_58 & V_18 -> V_80 ) >>
F_22 ( V_18 -> V_80 ) ;
switch ( V_58 ) {
case 0 :
* V_76 = 0 ;
break;
case 1 :
* V_76 = 1 ;
break;
case 2 :
* V_76 = 10 ;
break;
case 3 :
* V_76 = 100 ;
break;
case 4 :
* V_76 = 250 ;
break;
case 5 :
* V_76 = 500 ;
break;
default:
F_35 ( V_2 -> V_39 , L_7 ,
V_58 ) ;
}
}
int F_36 ( struct V_1 * V_2 , int V_16 ,
int * V_76 )
{
int V_57 = 0 ;
V_57 = F_24 ( V_2 , V_16 ) ;
if ( V_57 )
goto exit;
if ( ! F_6 ( V_2 , V_81 ) &&
! F_6 ( V_2 , V_82 ) ) {
V_57 = - V_9 ;
goto exit;
}
if ( F_6 ( V_2 , V_81 ) ) {
F_33 ( V_2 , V_16 , V_76 ) ;
goto exit;
}
F_34 ( V_2 , V_16 , V_76 ) ;
exit:
return V_57 ;
}
static int F_37 ( struct V_1 * V_2 , int V_16 ,
T_1 V_76 )
{
int V_83 ;
switch ( V_76 ) {
case 0 :
V_83 = 0x0 ;
break;
case 1 :
V_83 = 0x1 ;
break;
case 10 :
V_83 = 0x2 ;
break;
case 100 :
V_83 = 0x3 ;
break;
case 250 :
V_83 = 0x4 ;
break;
case 500 :
V_83 = 0x5 ;
break;
default:
F_35 ( V_2 -> V_39 , L_8 , V_76 ) ;
return - V_69 ;
}
F_11 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_16 , V_23 , V_80 , V_83 ) ;
F_13 ( & V_2 -> V_33 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , int V_16 ,
T_1 V_76 )
{
V_76 = V_76 * V_2 -> V_79 / 1000 ;
F_11 ( & V_2 -> V_33 ) ;
F_7 ( V_2 , V_16 , V_77 , V_78 , V_76 ) ;
F_13 ( & V_2 -> V_33 ) ;
}
int F_39 ( struct V_1 * V_2 ,
int V_16 , T_1 V_76 )
{
int V_57 = F_24 ( V_2 , V_16 ) ;
if ( V_57 )
goto exit;
if ( ! F_6 ( V_2 , V_81 ) &&
! F_6 ( V_2 , V_82 ) ) {
V_57 = - V_9 ;
goto exit;
}
if ( F_6 ( V_2 , V_81 ) ) {
F_38 ( V_2 , V_16 , V_76 ) ;
goto exit;
}
V_57 = F_37 ( V_2 , V_16 , V_76 ) ;
exit:
return V_57 ;
}
int F_40 ( struct V_1 * V_2 , int V_16 ,
int * V_84 )
{
T_1 V_19 ;
int V_57 ;
V_57 = F_24 ( V_2 , V_16 ) ;
if ( V_57 )
return V_57 ;
if ( ! F_6 ( V_2 , V_85 ) ) {
V_57 = F_41 ( V_2 , V_16 ) ;
if ( V_57 )
return V_57 ;
}
F_11 ( & V_2 -> V_33 ) ;
V_19 = F_9 ( V_2 , V_16 ) ;
F_13 ( & V_2 -> V_33 ) ;
V_57 = F_17 ( V_2 , V_19 , & V_19 ) ;
if ( V_57 )
return - V_68 ;
* V_84 = V_19 ;
return 0 ;
}
int F_42 ( struct V_1 * V_2 , int V_16 , void * V_29 )
{
int V_57 = F_24 ( V_2 , V_16 ) ;
if ( V_57 )
return V_57 ;
V_2 -> V_86 [ V_16 ] . V_29 = V_29 ;
return 0 ;
}
void * F_43 ( struct V_1 * V_2 , int V_16 )
{
int V_57 = F_24 ( V_2 , V_16 ) ;
if ( V_57 )
return F_44 ( V_57 ) ;
return V_2 -> V_86 [ V_16 ] . V_29 ;
}
static int
F_41 ( struct V_1 * V_2 , int V_16 )
{
T_1 V_87 = 1000 ;
struct V_17 * V_18 ;
if ( F_6 ( V_2 , V_85 ) )
F_7 ( V_2 , V_16 , V_88 , V_89 , 0 ) ;
F_7 ( V_2 , V_16 , V_12 , V_90 , 1 ) ;
V_18 = V_2 -> V_10 -> V_20 [ V_16 ] . V_21 ;
while ( -- V_87 ) {
if ( F_1 ( V_2 , V_18 -> V_12 ) &
V_18 -> V_91 )
break;
}
F_7 ( V_2 , V_16 , V_12 , V_90 , 0 ) ;
V_87 = 1000 ;
while ( -- V_87 ) {
if ( ! ( F_1 ( V_2 , V_18 -> V_12 ) &
V_18 -> V_91 ) )
break;
}
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_10 -> V_11 ; V_7 ++ ) {
F_41 ( V_2 , V_7 ) ;
F_7 ( V_2 , V_7 , V_88 , V_89 , 1 ) ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 , int V_16 , int * V_92 )
{
struct V_17 * V_18 ;
T_1 V_93 , V_94 , V_95 , V_96 ;
int V_97 , V_98 , V_76 , V_57 = 0 ;
V_57 = F_24 ( V_2 , V_16 ) ;
if ( V_57 )
goto exit;
if ( ! F_6 ( V_2 , V_99 ) ||
! F_6 ( V_2 , V_22 ) ) {
V_57 = - V_9 ;
goto exit;
}
F_11 ( & V_2 -> V_33 ) ;
V_18 = V_2 -> V_10 -> V_20 [ V_16 ] . V_21 ;
F_7 ( V_2 , V_16 , V_23 , V_24 , 1 ) ;
V_95 = V_18 -> V_25 ;
V_96 = V_18 -> V_100 ;
V_93 = F_1 ( V_2 , V_95 ) ;
V_93 &= V_18 -> V_27 ;
V_94 = F_1 ( V_2 , V_96 ) ;
V_94 &= V_18 -> V_27 ;
V_57 = F_17 ( V_2 , V_93 , & V_97 ) ;
if ( V_57 )
goto V_101;
V_57 = F_17 ( V_2 , V_94 , & V_98 ) ;
if ( V_57 )
goto V_101;
V_57 = F_36 ( V_2 , V_16 , & V_76 ) ;
if ( V_57 )
goto V_101;
if ( V_76 == 0 )
V_76 = 1 ;
* V_92 = ( V_97 - V_98 ) / V_76 ;
F_12 ( V_2 -> V_39 , L_9 ,
V_97 , V_98 , * V_92 ) ;
V_101:
F_7 ( V_2 , V_16 , V_23 , V_24 , 0 ) ;
F_13 ( & V_2 -> V_33 ) ;
exit:
return V_57 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
int V_104 = V_2 -> V_105 ;
int V_106 ;
V_106 = F_48 ( V_104 , L_10 ) ;
if ( V_106 < 0 ) {
F_23 ( V_2 -> V_39 , L_11 , 86 ) ;
return V_106 ;
}
V_106 = F_49 ( V_104 ) ;
if ( V_106 ) {
F_23 ( V_2 -> V_39 , L_12 , V_104 ) ;
return V_106 ;
}
V_106 = F_50 ( F_51 ( V_104 ) , F_14 ,
V_107 , L_10 , NULL ) ;
if ( V_106 ) {
F_52 ( V_104 ) ;
F_23 ( V_2 -> V_39 , L_13 ) ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_102 * V_103 )
{
int V_57 ;
V_2 -> V_28 = F_54 ( V_103 , 0 ) ;
if ( V_2 -> V_28 < 0 ) {
F_23 ( & V_103 -> V_39 , L_14 ) ;
return V_2 -> V_28 ;
}
V_57 = F_55 ( V_2 -> V_28 , NULL ,
F_10 ,
V_108 | V_109 ,
L_15 , V_2 ) ;
if ( V_57 ) {
F_23 ( & V_103 -> V_39 , L_16 ) ;
return V_57 ;
}
return 0 ;
}
static struct V_1 * F_56 ( struct V_102 * V_103 )
{
struct V_110 * V_111 = V_103 -> V_39 . V_112 ;
const struct V_113 * V_114 ;
struct V_1 * V_2 ;
struct V_115 * V_116 ;
int V_7 ;
if ( ! V_111 ) {
F_23 ( & V_103 -> V_39 , L_17 ) ;
return F_44 ( - V_69 ) ;
}
V_2 = F_57 ( & V_103 -> V_39 , sizeof( * V_2 ) , V_117 ) ;
if ( ! V_2 ) {
F_23 ( & V_103 -> V_39 , L_18 ) ;
return F_44 ( - V_118 ) ;
}
V_114 = F_58 ( V_119 , & V_103 -> V_39 ) ;
if ( V_114 )
V_2 -> V_10 = V_114 -> V_29 ;
V_2 -> V_86 = F_57 ( & V_103 -> V_39 , sizeof( * V_2 -> V_86 ) *
V_2 -> V_10 -> V_11 , V_117 ) ;
if ( ! V_2 -> V_86 ) {
F_23 ( & V_103 -> V_39 , L_18 ) ;
return F_44 ( - V_118 ) ;
}
V_7 = 0 ;
do {
void T_3 * V_120 ;
V_116 = F_59 ( V_103 , V_121 , V_7 ) ;
if ( ! V_116 )
break;
V_120 = F_60 ( & V_103 -> V_39 , V_116 ) ;
if ( V_7 == 0 )
V_2 -> V_4 = V_120 ;
if ( F_25 ( V_120 ) )
return F_61 ( V_120 ) ;
V_7 ++ ;
} while ( V_116 );
if ( F_6 ( V_2 , V_122 ) ) {
V_2 -> V_105 = F_62 ( V_111 , 0 ) ;
if ( ! F_63 ( V_2 -> V_105 ) ) {
F_23 ( & V_103 -> V_39 , L_19 ,
V_2 -> V_105 ) ;
return F_44 ( - V_69 ) ;
}
}
return V_2 ;
}
static
int F_64 ( struct V_102 * V_103 )
{
struct V_1 * V_2 ;
int V_79 , V_57 , V_7 ;
V_2 = F_56 ( V_103 ) ;
if ( F_25 ( V_2 ) ) {
F_23 ( & V_103 -> V_39 , L_20 ) ;
return F_65 ( V_2 ) ;
}
V_2 -> V_39 = & V_103 -> V_39 ;
if ( F_6 ( V_2 , V_123 ) )
F_35 ( & V_103 -> V_39 ,
L_21 ) ;
if ( F_6 ( V_2 , V_122 ) ) {
V_57 = F_47 ( V_2 , V_103 ) ;
if ( V_57 ) {
F_23 ( & V_103 -> V_39 ,
L_22 ) ;
return V_57 ;
}
}
V_2 -> V_124 = F_66 ( NULL , V_2 -> V_10 -> V_125 ) ;
if ( F_25 ( V_2 -> V_124 ) ) {
F_23 ( & V_103 -> V_39 , L_23 ) ;
V_57 = F_65 ( V_2 -> V_124 ) ;
goto V_126;
}
V_2 -> V_127 = F_66 ( NULL , V_2 -> V_10 -> V_128 ) ;
if ( F_25 ( V_2 -> V_127 ) ) {
F_23 ( & V_103 -> V_39 , L_24 ) ;
V_57 = F_65 ( V_2 -> V_127 ) ;
goto V_129;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_10 -> V_11 ; V_7 ++ ) {
struct V_17 * V_18 ;
T_1 V_5 ;
V_18 = V_2 -> V_10 -> V_20 [ V_7 ] . V_21 ;
V_5 = F_1 ( V_2 , V_18 -> V_130 ) ;
if ( ! V_5 )
F_67 ( & V_103 -> V_39 ,
L_25 ) ;
}
V_79 = F_68 ( V_2 -> V_127 ,
V_2 -> V_10 -> V_20 [ 0 ] . V_61 -> V_131 ) ;
if ( V_79 < V_2 -> V_10 -> V_20 [ 0 ] . V_61 -> V_132 ||
V_79 <= 0 ) {
V_57 = - V_133 ;
F_23 ( & V_103 -> V_39 , L_26 , V_79 ) ;
goto V_134;
}
V_57 = F_69 ( V_2 -> V_127 , V_79 ) ;
if ( V_57 )
F_23 ( & V_103 -> V_39 , L_27 ) ;
V_2 -> V_79 = V_79 ;
if ( F_6 ( V_2 , V_135 ) )
F_70 ( V_2 -> V_124 ) ;
F_71 ( & V_2 -> V_33 ) ;
V_2 -> V_39 = & V_103 -> V_39 ;
F_72 ( V_103 , V_2 ) ;
F_5 ( V_2 , true ) ;
if ( F_6 ( V_2 , V_81 ) )
for ( V_7 = 0 ; V_7 < V_2 -> V_10 -> V_11 ; V_7 ++ )
F_7 ( V_2 , V_7 , V_77 , V_78 , 1 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_10 -> V_11 ; V_7 ++ ) {
struct V_60 * V_61 ;
V_61 = V_2 -> V_10 -> V_20 [ V_7 ] . V_61 ;
if ( F_6 ( V_2 , V_70 ) ) {
F_7 ( V_2 , V_7 , V_64 ,
V_65 , V_61 -> V_31 ) ;
F_7 ( V_2 , V_7 , V_64 ,
V_66 , V_61 -> V_30 ) ;
F_7 ( V_2 , V_7 , V_23 , V_37 , 1 ) ;
F_7 ( V_2 , V_7 , V_23 , V_38 , 1 ) ;
}
if ( F_6 ( V_2 , V_136 ) ) {
F_7 ( V_2 , V_7 , V_137 ,
V_138 , V_61 -> V_139 ) ;
F_7 ( V_2 , V_7 , V_137 ,
V_140 , V_61 -> V_141 ) ;
}
}
if ( F_6 ( V_2 , V_85 ) )
F_45 ( V_2 ) ;
if ( F_6 ( V_2 , V_81 ) )
for ( V_7 = 0 ; V_7 < V_2 -> V_10 -> V_11 ; V_7 ++ )
F_7 ( V_2 , V_7 , V_77 , V_78 ,
V_2 -> V_79 / 4 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_10 -> V_11 ; V_7 ++ ) {
char * V_41 ;
if ( V_2 -> V_10 -> V_20 [ V_7 ] . V_142 ) {
V_57 = V_2 -> V_10 -> V_20 [ V_7 ] . V_142 ( V_2 , V_7 ) ;
if ( V_57 )
goto V_143;
}
if ( V_2 -> V_10 -> V_144 ) {
V_41 = V_2 -> V_10 -> V_20 [ V_7 ] . V_41 ;
V_57 = V_2 -> V_10 -> V_144 ( V_2 , V_7 , V_41 ) ;
if ( V_57 )
goto V_145;
}
}
if ( F_6 ( V_2 , V_70 ) ) {
V_57 = F_53 ( V_2 , V_103 ) ;
if ( V_57 ) {
F_23 ( & V_103 -> V_39 , L_28 ) ;
V_7 = V_2 -> V_10 -> V_11 ;
goto V_146;
}
}
return 0 ;
V_145:
if ( V_2 -> V_10 -> V_20 [ V_7 ] . V_147 )
V_2 -> V_10 -> V_20 [ V_7 ] . V_147 ( V_2 , V_7 ) ;
V_143:
for ( V_7 -- ; V_7 >= 0 ; V_7 -- ) {
if ( V_2 -> V_10 -> V_20 [ V_7 ] . V_147 )
V_2 -> V_10 -> V_20 [ V_7 ] . V_147 ( V_2 , V_7 ) ;
if ( V_2 -> V_10 -> V_148 )
V_2 -> V_10 -> V_148 ( V_2 , V_7 ) ;
}
F_5 ( V_2 , false ) ;
V_146:
if ( F_6 ( V_2 , V_135 ) )
F_73 ( V_2 -> V_124 ) ;
V_134:
F_74 ( V_2 -> V_127 ) ;
V_129:
F_74 ( V_2 -> V_124 ) ;
V_126:
if ( F_6 ( V_2 , V_122 ) ) {
F_75 ( F_51 ( V_2 -> V_105 ) , NULL ) ;
F_52 ( V_2 -> V_105 ) ;
}
return V_57 ;
}
static
int F_76 ( struct V_102 * V_103 )
{
struct V_1 * V_2 = F_77 ( V_103 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_10 -> V_11 ; V_7 ++ ) {
if ( V_2 -> V_10 -> V_20 [ V_7 ] . V_147 )
V_2 -> V_10 -> V_20 [ V_7 ] . V_147 ( V_2 , V_7 ) ;
if ( V_2 -> V_10 -> V_148 )
V_2 -> V_10 -> V_148 ( V_2 , V_7 ) ;
}
F_5 ( V_2 , false ) ;
if ( F_6 ( V_2 , V_135 ) )
F_73 ( V_2 -> V_124 ) ;
F_74 ( V_2 -> V_124 ) ;
F_74 ( V_2 -> V_127 ) ;
if ( F_6 ( V_2 , V_70 ) )
F_75 ( V_2 -> V_28 , V_2 ) ;
if ( F_6 ( V_2 , V_122 ) ) {
F_75 ( F_51 ( V_2 -> V_105 ) , NULL ) ;
F_52 ( V_2 -> V_105 ) ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_10 -> V_11 ; V_7 ++ ) {
struct V_17 * V_18 ;
struct V_149 * V_83 ;
V_83 = & V_2 -> V_86 [ V_7 ] ;
V_18 = V_2 -> V_10 -> V_20 [ V_7 ] . V_21 ;
if ( F_6 ( V_2 , V_85 ) )
V_83 -> V_150 = F_1 ( V_2 ,
V_18 -> V_88 ) ;
if ( F_6 ( V_2 , V_81 ) )
V_83 -> V_151 = F_1 ( V_2 ,
V_18 -> V_77 ) ;
if ( F_6 ( V_2 , V_70 ) ) {
V_83 -> V_152 = F_1 ( V_2 ,
V_18 -> V_64 ) ;
V_83 -> V_153 = F_1 ( V_2 ,
V_18 -> V_23 ) ;
}
if ( F_6 ( V_2 , V_136 ) )
V_83 -> V_137 = F_1 ( V_2 ,
V_18 -> V_137 ) ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_10 -> V_11 ; V_7 ++ ) {
struct V_17 * V_18 ;
struct V_149 * V_83 ;
T_1 V_5 = 0 ;
V_83 = & V_2 -> V_86 [ V_7 ] ;
V_18 = V_2 -> V_10 -> V_20 [ V_7 ] . V_21 ;
if ( F_6 ( V_2 , V_81 ) )
V_5 = F_1 ( V_2 , V_18 -> V_77 ) ;
if ( F_6 ( V_2 , V_136 ) )
F_3 ( V_2 , V_83 -> V_137 ,
V_18 -> V_137 ) ;
F_41 ( V_2 , V_7 ) ;
if ( F_6 ( V_2 , V_81 ) )
F_3 ( V_2 , V_83 -> V_151 ,
V_18 -> V_77 ) ;
if ( F_6 ( V_2 , V_85 ) )
F_3 ( V_2 , V_83 -> V_150 ,
V_18 -> V_88 ) ;
if ( F_6 ( V_2 , V_70 ) ) {
F_3 ( V_2 , V_83 -> V_152 ,
V_18 -> V_64 ) ;
F_3 ( V_2 , V_83 -> V_153 ,
V_18 -> V_23 ) ;
}
}
return 0 ;
}
static int F_80 ( struct V_154 * V_39 )
{
struct V_1 * V_2 = F_81 ( V_39 ) ;
int V_63 ;
V_63 = F_78 ( V_2 ) ;
F_5 ( V_2 , false ) ;
if ( F_6 ( V_2 , V_135 ) )
F_73 ( V_2 -> V_124 ) ;
return V_63 ;
}
static int F_82 ( struct V_154 * V_39 )
{
struct V_1 * V_2 = F_81 ( V_39 ) ;
if ( F_6 ( V_2 , V_135 ) )
F_70 ( V_2 -> V_124 ) ;
F_5 ( V_2 , true ) ;
return F_79 ( V_2 ) ;
}
