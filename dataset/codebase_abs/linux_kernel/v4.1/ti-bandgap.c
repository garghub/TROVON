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
int V_7 , V_8 = 0 ;
if ( ! F_6 ( V_2 , V_9 ) ) {
V_8 = - V_10 ;
goto exit;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_11 -> V_12 ; V_7 ++ )
F_7 ( V_2 , V_7 , V_13 , V_14 , ! V_6 ) ;
exit:
return V_8 ;
}
static T_1 F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_15 , V_16 ;
V_15 = F_1 ( V_2 , V_3 ) ;
V_16 = F_1 ( V_2 , V_3 ) ;
if ( V_15 == V_16 )
return V_15 ;
return F_1 ( V_2 , V_3 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 , int V_17 )
{
struct V_18 * V_19 ;
T_1 V_20 , V_3 ;
V_19 = V_2 -> V_11 -> V_21 [ V_17 ] . V_22 ;
V_3 = V_19 -> V_13 ;
if ( F_6 ( V_2 , V_23 ) ) {
F_7 ( V_2 , V_17 , V_24 , V_25 , 1 ) ;
V_3 = V_19 -> V_26 ;
}
if ( F_6 ( V_2 , V_27 ) )
V_20 = F_8 ( V_2 , V_3 ) ;
else
V_20 = F_1 ( V_2 , V_3 ) ;
V_20 &= V_19 -> V_28 ;
if ( F_6 ( V_2 , V_23 ) )
F_7 ( V_2 , V_17 , V_24 , V_25 , 0 ) ;
return V_20 ;
}
static T_2 F_10 ( int V_29 , void * V_30 )
{
struct V_1 * V_2 = V_30 ;
struct V_18 * V_19 ;
T_1 V_31 = 0 , V_32 = 0 , V_33 ;
int V_7 ;
F_11 ( & V_2 -> V_34 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_11 -> V_12 ; V_7 ++ ) {
V_19 = V_2 -> V_11 -> V_21 [ V_7 ] . V_22 ;
V_33 = F_1 ( V_2 , V_19 -> V_35 ) ;
V_31 = V_33 & V_19 -> V_36 ;
V_32 = V_33 & V_19 -> V_37 ;
if ( ! V_32 && ! V_31 )
continue;
V_33 = F_1 ( V_2 , V_19 -> V_24 ) ;
if ( V_31 ) {
V_33 &= ~ V_19 -> V_38 ;
V_33 |= V_19 -> V_39 ;
} else if ( V_32 ) {
V_33 &= ~ V_19 -> V_39 ;
V_33 |= V_19 -> V_38 ;
}
F_3 ( V_2 , V_33 , V_19 -> V_24 ) ;
F_12 ( V_2 -> V_40 ,
L_1 ,
V_41 , V_2 -> V_11 -> V_21 [ V_7 ] . V_42 ,
V_31 , V_32 ) ;
if ( V_2 -> V_11 -> V_43 )
V_2 -> V_11 -> V_43 ( V_2 , V_7 ) ;
}
F_13 ( & V_2 -> V_34 ) ;
return V_44 ;
}
static T_2 F_14 ( int V_29 , void * V_30 )
{
F_15 ( L_2 ,
V_41 ) ;
F_16 ( true ) ;
return V_44 ;
}
static
int F_17 ( struct V_1 * V_2 , int V_45 , int * V_46 )
{
const struct V_47 * V_11 = V_2 -> V_11 ;
int V_8 = 0 ;
if ( V_45 < V_11 -> V_48 || V_45 > V_11 -> V_49 ) {
V_8 = - V_50 ;
goto exit;
}
* V_46 = V_2 -> V_11 -> V_51 [ V_45 - V_11 -> V_48 ] ;
exit:
return V_8 ;
}
static
int F_18 ( struct V_1 * V_2 , long V_20 , int * V_52 )
{
const struct V_47 * V_11 = V_2 -> V_11 ;
const int * V_51 = V_2 -> V_11 -> V_51 ;
int V_53 , V_54 , V_55 , V_8 = 0 ;
V_54 = 0 ;
V_53 = V_11 -> V_49 - V_11 -> V_48 ;
V_55 = ( V_53 + V_54 ) / 2 ;
if ( V_20 < V_51 [ V_54 ] || V_20 > V_51 [ V_53 ] ) {
V_8 = - V_50 ;
goto exit;
}
while ( V_54 < V_53 ) {
if ( V_20 < V_51 [ V_55 ] )
V_53 = V_55 - 1 ;
else
V_54 = V_55 + 1 ;
V_55 = ( V_54 + V_53 ) / 2 ;
}
* V_52 = V_11 -> V_48 + V_54 ;
exit:
return V_8 ;
}
static
int F_19 ( struct V_1 * V_2 , int V_45 , int V_56 ,
T_1 * V_57 )
{
int V_20 , V_8 ;
V_8 = F_17 ( V_2 , V_45 , & V_20 ) ;
if ( V_8 < 0 )
goto exit;
V_20 += V_56 ;
V_8 = F_18 ( V_2 , V_20 , V_57 ) ;
exit:
return V_8 ;
}
static void F_20 ( struct V_1 * V_2 , int V_17 ,
T_1 V_31 , T_1 V_32 )
{
struct V_18 * V_19 ;
T_1 V_20 , V_58 ;
V_20 = F_9 ( V_2 , V_17 ) ;
V_19 = V_2 -> V_11 -> V_21 [ V_17 ] . V_22 ;
V_58 = F_1 ( V_2 , V_19 -> V_24 ) ;
if ( V_20 < V_31 )
V_58 |= V_19 -> V_38 ;
else
V_58 &= ~ V_19 -> V_38 ;
if ( V_32 < V_20 )
V_58 |= V_19 -> V_39 ;
else
V_58 &= ~ V_19 -> V_39 ;
F_3 ( V_2 , V_58 , V_19 -> V_24 ) ;
}
static int F_21 ( struct V_1 * V_2 , int V_17 ,
int V_5 , bool V_59 )
{
struct V_60 * V_61 = V_2 -> V_11 -> V_21 [ V_17 ] . V_61 ;
struct V_18 * V_19 ;
T_1 V_62 , V_58 , V_31 , V_32 , V_33 ;
int V_63 = 0 ;
V_19 = V_2 -> V_11 -> V_21 [ V_17 ] . V_22 ;
V_62 = F_1 ( V_2 , V_19 -> V_64 ) ;
V_32 = ( V_62 & V_19 -> V_65 ) >>
F_22 ( V_19 -> V_65 ) ;
V_31 = ( V_62 & V_19 -> V_66 ) >>
F_22 ( V_19 -> V_66 ) ;
if ( V_59 )
V_31 = V_5 ;
else
V_32 = V_5 ;
if ( V_32 > V_31 ) {
if ( V_59 )
V_63 = F_19 ( V_2 , V_31 ,
- V_61 -> V_56 ,
& V_32 ) ;
else
V_63 = F_19 ( V_2 , V_32 ,
V_61 -> V_56 ,
& V_31 ) ;
}
V_58 = V_62 &
~ ( V_19 -> V_66 | V_19 -> V_65 ) ;
V_58 |= ( V_31 << F_22 ( V_19 -> V_66 ) ) |
( V_32 << F_22 ( V_19 -> V_65 ) ) ;
if ( F_6 ( V_2 , V_67 ) ) {
V_33 = F_1 ( V_2 , V_19 -> V_24 ) ;
if ( V_59 )
V_33 &= ~ V_19 -> V_38 ;
else
V_33 &= ~ V_19 -> V_39 ;
F_3 ( V_2 , V_33 , V_19 -> V_24 ) ;
}
F_3 ( V_2 , V_58 , V_19 -> V_64 ) ;
if ( F_6 ( V_2 , V_67 ) ) {
V_33 = F_1 ( V_2 , V_19 -> V_24 ) ;
if ( V_59 )
V_33 |= V_19 -> V_38 ;
else
V_33 |= V_19 -> V_39 ;
F_3 ( V_2 , V_33 , V_19 -> V_24 ) ;
}
if ( V_63 ) {
F_23 ( V_2 -> V_40 , L_3 ) ;
V_63 = - V_68 ;
goto exit;
}
F_20 ( V_2 , V_17 , V_31 , V_32 ) ;
exit:
return V_63 ;
}
static inline int F_24 ( struct V_1 * V_2 , int V_17 )
{
int V_8 = 0 ;
if ( ! V_2 || F_25 ( V_2 ) ) {
F_26 ( L_4 , V_41 ) ;
V_8 = - V_69 ;
goto exit;
}
if ( ( V_17 < 0 ) || ( V_17 >= V_2 -> V_11 -> V_12 ) ) {
F_23 ( V_2 -> V_40 , L_5 ,
V_41 , V_17 ) ;
V_8 = - V_50 ;
}
exit:
return V_8 ;
}
static int F_27 ( struct V_1 * V_2 , int V_17 , int V_5 ,
bool V_59 )
{
struct V_60 * V_61 ;
struct V_18 * V_19 ;
T_1 V_45 ;
int V_8 ;
V_8 = F_24 ( V_2 , V_17 ) ;
if ( V_8 )
goto exit;
if ( ! F_6 ( V_2 , V_70 ) ) {
V_8 = - V_10 ;
goto exit;
}
V_61 = V_2 -> V_11 -> V_21 [ V_17 ] . V_61 ;
V_19 = V_2 -> V_11 -> V_21 [ V_17 ] . V_22 ;
if ( V_59 ) {
if ( V_5 < V_61 -> V_71 + V_61 -> V_56 )
V_8 = - V_69 ;
} else {
if ( V_5 > V_61 -> V_72 + V_61 -> V_56 )
V_8 = - V_69 ;
}
if ( V_8 )
goto exit;
V_8 = F_18 ( V_2 , V_5 , & V_45 ) ;
if ( V_8 < 0 )
goto exit;
F_11 ( & V_2 -> V_34 ) ;
V_8 = F_21 ( V_2 , V_17 , V_45 , V_59 ) ;
F_13 ( & V_2 -> V_34 ) ;
exit:
return V_8 ;
}
static int F_28 ( struct V_1 * V_2 , int V_17 ,
int * V_5 , bool V_59 )
{
struct V_18 * V_19 ;
T_1 V_20 , V_73 ;
int V_8 = 0 ;
V_8 = F_24 ( V_2 , V_17 ) ;
if ( V_8 )
goto exit;
if ( ! F_6 ( V_2 , V_70 ) ) {
V_8 = - V_10 ;
goto exit;
}
V_19 = V_2 -> V_11 -> V_21 [ V_17 ] . V_22 ;
if ( V_59 )
V_73 = V_19 -> V_66 ;
else
V_73 = V_19 -> V_65 ;
V_20 = F_1 ( V_2 , V_19 -> V_64 ) ;
V_20 = ( V_20 & V_73 ) >> F_22 ( V_73 ) ;
V_8 |= F_17 ( V_2 , V_20 , & V_20 ) ;
if ( V_8 ) {
F_23 ( V_2 -> V_40 , L_6 ) ;
V_8 = - V_68 ;
goto exit;
}
* V_5 = V_20 ;
exit:
return V_8 ;
}
int F_29 ( struct V_1 * V_2 , int V_17 , int * V_74 )
{
return F_28 ( V_2 , V_17 , V_74 , true ) ;
}
int F_30 ( struct V_1 * V_2 , int V_17 , int V_5 )
{
return F_27 ( V_2 , V_17 , V_5 , true ) ;
}
int F_31 ( struct V_1 * V_2 , int V_17 , int * V_75 )
{
return F_28 ( V_2 , V_17 , V_75 , false ) ;
}
int F_32 ( struct V_1 * V_2 , int V_17 , int V_5 )
{
return F_27 ( V_2 , V_17 , V_5 , false ) ;
}
static void F_33 ( struct V_1 * V_2 , int V_17 ,
int * V_76 )
{
struct V_18 * V_19 ;
int time ;
V_19 = V_2 -> V_11 -> V_21 [ V_17 ] . V_22 ;
time = F_1 ( V_2 , V_19 -> V_77 ) ;
time = ( time & V_19 -> V_78 ) >>
F_22 ( V_19 -> V_78 ) ;
time = time * 1000 / V_2 -> V_79 ;
* V_76 = time ;
}
static void F_34 ( struct V_1 * V_2 , int V_17 ,
int * V_76 )
{
struct V_18 * V_19 ;
int V_58 ;
V_19 = V_2 -> V_11 -> V_21 [ V_17 ] . V_22 ;
V_58 = F_1 ( V_2 , V_19 -> V_24 ) ;
V_58 = ( V_58 & V_19 -> V_80 ) >>
F_22 ( V_19 -> V_80 ) ;
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
F_35 ( V_2 -> V_40 , L_7 ,
V_58 ) ;
}
}
int F_36 ( struct V_1 * V_2 , int V_17 ,
int * V_76 )
{
int V_8 = 0 ;
V_8 = F_24 ( V_2 , V_17 ) ;
if ( V_8 )
goto exit;
if ( ! F_6 ( V_2 , V_81 ) &&
! F_6 ( V_2 , V_82 ) ) {
V_8 = - V_10 ;
goto exit;
}
if ( F_6 ( V_2 , V_81 ) ) {
F_33 ( V_2 , V_17 , V_76 ) ;
goto exit;
}
F_34 ( V_2 , V_17 , V_76 ) ;
exit:
return V_8 ;
}
static int F_37 ( struct V_1 * V_2 , int V_17 ,
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
F_35 ( V_2 -> V_40 , L_8 , V_76 ) ;
return - V_69 ;
}
F_11 ( & V_2 -> V_34 ) ;
F_7 ( V_2 , V_17 , V_24 , V_80 , V_83 ) ;
F_13 ( & V_2 -> V_34 ) ;
return 0 ;
}
static void F_38 ( struct V_1 * V_2 , int V_17 ,
T_1 V_76 )
{
V_76 = V_76 * V_2 -> V_79 / 1000 ;
F_11 ( & V_2 -> V_34 ) ;
F_7 ( V_2 , V_17 , V_77 , V_78 , V_76 ) ;
F_13 ( & V_2 -> V_34 ) ;
}
int F_39 ( struct V_1 * V_2 ,
int V_17 , T_1 V_76 )
{
int V_8 = F_24 ( V_2 , V_17 ) ;
if ( V_8 )
goto exit;
if ( ! F_6 ( V_2 , V_81 ) &&
! F_6 ( V_2 , V_82 ) ) {
V_8 = - V_10 ;
goto exit;
}
if ( F_6 ( V_2 , V_81 ) ) {
F_38 ( V_2 , V_17 , V_76 ) ;
goto exit;
}
V_8 = F_37 ( V_2 , V_17 , V_76 ) ;
exit:
return V_8 ;
}
int F_40 ( struct V_1 * V_2 , int V_17 ,
int * V_84 )
{
T_1 V_20 ;
int V_8 ;
V_8 = F_24 ( V_2 , V_17 ) ;
if ( V_8 )
return V_8 ;
F_11 ( & V_2 -> V_34 ) ;
V_20 = F_9 ( V_2 , V_17 ) ;
F_13 ( & V_2 -> V_34 ) ;
V_8 |= F_17 ( V_2 , V_20 , & V_20 ) ;
if ( V_8 )
return - V_68 ;
* V_84 = V_20 ;
return 0 ;
}
int F_41 ( struct V_1 * V_2 , int V_17 , void * V_30 )
{
int V_8 = F_24 ( V_2 , V_17 ) ;
if ( V_8 )
return V_8 ;
V_2 -> V_85 [ V_17 ] . V_30 = V_30 ;
return 0 ;
}
void * F_42 ( struct V_1 * V_2 , int V_17 )
{
int V_8 = F_24 ( V_2 , V_17 ) ;
if ( V_8 )
return F_43 ( V_8 ) ;
return V_2 -> V_85 [ V_17 ] . V_30 ;
}
static int
F_44 ( struct V_1 * V_2 , int V_17 )
{
T_1 V_20 = 0 , V_86 = 1000 ;
if ( F_6 ( V_2 , V_87 ) )
F_7 ( V_2 , V_17 , V_88 , V_89 , 0 ) ;
F_7 ( V_2 , V_17 , V_13 , V_90 , 1 ) ;
V_20 = F_9 ( V_2 , V_17 ) ;
while ( ( V_20 == 0 ) && -- V_86 )
V_20 = F_9 ( V_2 , V_17 ) ;
F_7 ( V_2 , V_17 , V_13 , V_90 , 0 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_11 -> V_12 ; V_7 ++ ) {
F_44 ( V_2 , V_7 ) ;
F_7 ( V_2 , V_7 , V_88 , V_89 , 1 ) ;
}
return 0 ;
}
int F_46 ( struct V_1 * V_2 , int V_17 , int * V_91 )
{
struct V_18 * V_19 ;
T_1 V_92 , V_93 , V_94 , V_95 ;
int V_96 , V_97 , V_76 , V_8 = 0 ;
V_8 = F_24 ( V_2 , V_17 ) ;
if ( V_8 )
goto exit;
if ( ! F_6 ( V_2 , V_98 ) ||
! F_6 ( V_2 , V_23 ) ) {
V_8 = - V_10 ;
goto exit;
}
F_11 ( & V_2 -> V_34 ) ;
V_19 = V_2 -> V_11 -> V_21 [ V_17 ] . V_22 ;
F_7 ( V_2 , V_17 , V_24 , V_25 , 1 ) ;
V_94 = V_19 -> V_26 ;
V_95 = V_19 -> V_99 ;
V_92 = F_1 ( V_2 , V_94 ) ;
V_92 &= V_19 -> V_28 ;
V_93 = F_1 ( V_2 , V_95 ) ;
V_93 &= V_19 -> V_28 ;
V_8 = F_17 ( V_2 , V_92 , & V_96 ) ;
if ( V_8 )
goto V_100;
V_8 = F_17 ( V_2 , V_93 , & V_97 ) ;
if ( V_8 )
goto V_100;
V_8 = F_36 ( V_2 , V_17 , & V_76 ) ;
if ( V_8 )
goto V_100;
if ( V_76 == 0 )
V_76 = 1 ;
* V_91 = ( V_96 - V_97 ) / V_76 ;
F_12 ( V_2 -> V_40 , L_9 ,
V_96 , V_97 , * V_91 ) ;
V_100:
F_7 ( V_2 , V_17 , V_24 , V_25 , 0 ) ;
F_13 ( & V_2 -> V_34 ) ;
exit:
return V_8 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
int V_103 = V_2 -> V_104 ;
int V_105 ;
V_105 = F_48 ( V_103 , L_10 ) ;
if ( V_105 < 0 ) {
F_23 ( V_2 -> V_40 , L_11 , 86 ) ;
return V_105 ;
}
V_105 = F_49 ( V_103 ) ;
if ( V_105 ) {
F_23 ( V_2 -> V_40 , L_12 , V_103 ) ;
return V_105 ;
}
V_105 = F_50 ( F_51 ( V_103 ) , F_14 ,
V_106 , L_10 , NULL ) ;
if ( V_105 ) {
F_52 ( V_103 ) ;
F_23 ( V_2 -> V_40 , L_13 ) ;
}
return 0 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_101 * V_102 )
{
int V_8 ;
V_2 -> V_29 = F_54 ( V_102 , 0 ) ;
if ( V_2 -> V_29 < 0 ) {
F_23 ( & V_102 -> V_40 , L_14 ) ;
return V_2 -> V_29 ;
}
V_8 = F_55 ( V_2 -> V_29 , NULL ,
F_10 ,
V_107 | V_108 ,
L_15 , V_2 ) ;
if ( V_8 ) {
F_23 ( & V_102 -> V_40 , L_16 ) ;
return V_8 ;
}
return 0 ;
}
static struct V_1 * F_56 ( struct V_101 * V_102 )
{
struct V_109 * V_110 = V_102 -> V_40 . V_111 ;
const struct V_112 * V_113 ;
struct V_1 * V_2 ;
struct V_114 * V_115 ;
int V_7 ;
if ( ! V_110 ) {
F_23 ( & V_102 -> V_40 , L_17 ) ;
return F_43 ( - V_69 ) ;
}
V_2 = F_57 ( & V_102 -> V_40 , sizeof( * V_2 ) , V_116 ) ;
if ( ! V_2 ) {
F_23 ( & V_102 -> V_40 , L_18 ) ;
return F_43 ( - V_117 ) ;
}
V_113 = F_58 ( V_118 , & V_102 -> V_40 ) ;
if ( V_113 )
V_2 -> V_11 = V_113 -> V_30 ;
V_2 -> V_85 = F_57 ( & V_102 -> V_40 , sizeof( * V_2 -> V_85 ) *
V_2 -> V_11 -> V_12 , V_116 ) ;
if ( ! V_2 -> V_85 ) {
F_23 ( & V_102 -> V_40 , L_18 ) ;
return F_43 ( - V_117 ) ;
}
V_7 = 0 ;
do {
void T_3 * V_119 ;
V_115 = F_59 ( V_102 , V_120 , V_7 ) ;
if ( ! V_115 )
break;
V_119 = F_60 ( & V_102 -> V_40 , V_115 ) ;
if ( V_7 == 0 )
V_2 -> V_4 = V_119 ;
if ( F_25 ( V_119 ) )
return F_61 ( V_119 ) ;
V_7 ++ ;
} while ( V_115 );
if ( F_6 ( V_2 , V_121 ) ) {
V_2 -> V_104 = F_62 ( V_110 , 0 ) ;
if ( ! F_63 ( V_2 -> V_104 ) ) {
F_23 ( & V_102 -> V_40 , L_19 ,
V_2 -> V_104 ) ;
return F_43 ( - V_69 ) ;
}
}
return V_2 ;
}
static
int F_64 ( struct V_101 * V_102 )
{
struct V_1 * V_2 ;
int V_79 , V_8 = 0 , V_7 ;
V_2 = F_56 ( V_102 ) ;
if ( F_25 ( V_2 ) ) {
F_23 ( & V_102 -> V_40 , L_20 ) ;
return F_65 ( V_2 ) ;
}
V_2 -> V_40 = & V_102 -> V_40 ;
if ( F_6 ( V_2 , V_121 ) ) {
V_8 = F_47 ( V_2 , V_102 ) ;
if ( V_8 ) {
F_23 ( & V_102 -> V_40 ,
L_21 ) ;
return V_8 ;
}
}
V_2 -> V_122 = F_66 ( NULL , V_2 -> V_11 -> V_123 ) ;
V_8 = F_25 ( V_2 -> V_122 ) ;
if ( V_8 ) {
F_23 ( & V_102 -> V_40 , L_22 ) ;
V_8 = F_65 ( V_2 -> V_122 ) ;
goto V_124;
}
V_2 -> V_125 = F_66 ( NULL , V_2 -> V_11 -> V_126 ) ;
V_8 = F_25 ( V_2 -> V_125 ) ;
if ( V_8 ) {
F_23 ( & V_102 -> V_40 ,
L_23 ) ;
V_8 = F_65 ( V_2 -> V_125 ) ;
goto V_124;
}
for ( V_7 = 0 ; V_7 < V_2 -> V_11 -> V_12 ; V_7 ++ ) {
struct V_18 * V_19 ;
T_1 V_5 ;
V_19 = V_2 -> V_11 -> V_21 [ V_7 ] . V_22 ;
V_5 = F_1 ( V_2 , V_19 -> V_127 ) ;
if ( V_8 || ! V_5 )
F_67 ( & V_102 -> V_40 ,
L_24 ) ;
}
V_79 = F_68 ( V_2 -> V_125 ,
V_2 -> V_11 -> V_21 [ 0 ] . V_61 -> V_128 ) ;
if ( V_79 < V_2 -> V_11 -> V_21 [ 0 ] . V_61 -> V_129 ||
V_79 <= 0 ) {
V_8 = - V_130 ;
F_23 ( & V_102 -> V_40 , L_25 , V_79 ) ;
goto V_131;
}
V_8 = F_69 ( V_2 -> V_125 , V_79 ) ;
if ( V_8 )
F_23 ( & V_102 -> V_40 , L_26 ) ;
V_2 -> V_79 = V_79 ;
if ( F_6 ( V_2 , V_132 ) )
F_70 ( V_2 -> V_122 ) ;
F_71 ( & V_2 -> V_34 ) ;
V_2 -> V_40 = & V_102 -> V_40 ;
F_72 ( V_102 , V_2 ) ;
F_5 ( V_2 , true ) ;
if ( F_6 ( V_2 , V_81 ) )
for ( V_7 = 0 ; V_7 < V_2 -> V_11 -> V_12 ; V_7 ++ )
F_7 ( V_2 , V_7 , V_77 , V_78 , 1 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_11 -> V_12 ; V_7 ++ ) {
struct V_60 * V_61 ;
V_61 = V_2 -> V_11 -> V_21 [ V_7 ] . V_61 ;
if ( F_6 ( V_2 , V_70 ) ) {
F_7 ( V_2 , V_7 , V_64 ,
V_65 , V_61 -> V_32 ) ;
F_7 ( V_2 , V_7 , V_64 ,
V_66 , V_61 -> V_31 ) ;
F_7 ( V_2 , V_7 , V_24 , V_38 , 1 ) ;
F_7 ( V_2 , V_7 , V_24 , V_39 , 1 ) ;
}
if ( F_6 ( V_2 , V_133 ) ) {
F_7 ( V_2 , V_7 , V_134 ,
V_135 , V_61 -> V_136 ) ;
F_7 ( V_2 , V_7 , V_134 ,
V_137 , V_61 -> V_138 ) ;
}
}
if ( F_6 ( V_2 , V_87 ) )
F_45 ( V_2 ) ;
if ( F_6 ( V_2 , V_81 ) )
for ( V_7 = 0 ; V_7 < V_2 -> V_11 -> V_12 ; V_7 ++ )
F_7 ( V_2 , V_7 , V_77 , V_78 ,
V_2 -> V_79 / 4 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_11 -> V_12 ; V_7 ++ ) {
char * V_42 ;
if ( V_2 -> V_11 -> V_21 [ V_7 ] . V_139 ) {
V_8 = V_2 -> V_11 -> V_21 [ V_7 ] . V_139 ( V_2 , V_7 ) ;
if ( V_8 )
goto V_140;
}
if ( V_2 -> V_11 -> V_141 ) {
V_42 = V_2 -> V_11 -> V_21 [ V_7 ] . V_42 ;
V_8 = V_2 -> V_11 -> V_141 ( V_2 , V_7 , V_42 ) ;
if ( V_8 )
goto V_142;
}
}
if ( F_6 ( V_2 , V_70 ) ) {
V_8 = F_53 ( V_2 , V_102 ) ;
if ( V_8 ) {
F_23 ( & V_102 -> V_40 , L_27 ) ;
V_7 = V_2 -> V_11 -> V_12 ;
goto V_143;
}
}
return 0 ;
V_142:
if ( V_2 -> V_11 -> V_21 [ V_7 ] . V_144 )
V_2 -> V_11 -> V_21 [ V_7 ] . V_144 ( V_2 , V_7 ) ;
V_140:
for ( V_7 -- ; V_7 >= 0 ; V_7 -- ) {
if ( V_2 -> V_11 -> V_21 [ V_7 ] . V_144 )
V_2 -> V_11 -> V_21 [ V_7 ] . V_144 ( V_2 , V_7 ) ;
if ( V_2 -> V_11 -> V_145 )
V_2 -> V_11 -> V_145 ( V_2 , V_7 ) ;
}
F_5 ( V_2 , false ) ;
V_143:
if ( F_6 ( V_2 , V_132 ) )
F_73 ( V_2 -> V_122 ) ;
V_131:
F_74 ( V_2 -> V_122 ) ;
F_74 ( V_2 -> V_125 ) ;
V_124:
if ( F_6 ( V_2 , V_121 ) ) {
F_75 ( F_51 ( V_2 -> V_104 ) , NULL ) ;
F_52 ( V_2 -> V_104 ) ;
}
return V_8 ;
}
static
int F_76 ( struct V_101 * V_102 )
{
struct V_1 * V_2 = F_77 ( V_102 ) ;
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_11 -> V_12 ; V_7 ++ ) {
if ( V_2 -> V_11 -> V_21 [ V_7 ] . V_144 )
V_2 -> V_11 -> V_21 [ V_7 ] . V_144 ( V_2 , V_7 ) ;
if ( V_2 -> V_11 -> V_145 )
V_2 -> V_11 -> V_145 ( V_2 , V_7 ) ;
}
F_5 ( V_2 , false ) ;
if ( F_6 ( V_2 , V_132 ) )
F_73 ( V_2 -> V_122 ) ;
F_74 ( V_2 -> V_122 ) ;
F_74 ( V_2 -> V_125 ) ;
if ( F_6 ( V_2 , V_70 ) )
F_75 ( V_2 -> V_29 , V_2 ) ;
if ( F_6 ( V_2 , V_121 ) ) {
F_75 ( F_51 ( V_2 -> V_104 ) , NULL ) ;
F_52 ( V_2 -> V_104 ) ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_11 -> V_12 ; V_7 ++ ) {
struct V_18 * V_19 ;
struct V_146 * V_83 ;
V_83 = & V_2 -> V_85 [ V_7 ] ;
V_19 = V_2 -> V_11 -> V_21 [ V_7 ] . V_22 ;
if ( F_6 ( V_2 , V_87 ) )
V_83 -> V_147 = F_1 ( V_2 ,
V_19 -> V_88 ) ;
if ( F_6 ( V_2 , V_81 ) )
V_83 -> V_148 = F_1 ( V_2 ,
V_19 -> V_77 ) ;
if ( F_6 ( V_2 , V_70 ) ) {
V_83 -> V_149 = F_1 ( V_2 ,
V_19 -> V_64 ) ;
V_83 -> V_150 = F_1 ( V_2 ,
V_19 -> V_24 ) ;
}
if ( F_6 ( V_2 , V_133 ) )
V_83 -> V_134 = F_1 ( V_2 ,
V_19 -> V_134 ) ;
}
return 0 ;
}
static int F_79 ( struct V_1 * V_2 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_11 -> V_12 ; V_7 ++ ) {
struct V_18 * V_19 ;
struct V_146 * V_83 ;
T_1 V_5 = 0 ;
V_83 = & V_2 -> V_85 [ V_7 ] ;
V_19 = V_2 -> V_11 -> V_21 [ V_7 ] . V_22 ;
if ( F_6 ( V_2 , V_81 ) )
V_5 = F_1 ( V_2 , V_19 -> V_77 ) ;
if ( F_6 ( V_2 , V_133 ) )
F_3 ( V_2 , V_83 -> V_134 ,
V_19 -> V_134 ) ;
F_44 ( V_2 , V_7 ) ;
if ( F_6 ( V_2 , V_81 ) )
F_3 ( V_2 , V_83 -> V_148 ,
V_19 -> V_77 ) ;
if ( F_6 ( V_2 , V_87 ) )
F_3 ( V_2 , V_83 -> V_147 ,
V_19 -> V_88 ) ;
if ( F_6 ( V_2 , V_70 ) ) {
F_3 ( V_2 , V_83 -> V_149 ,
V_19 -> V_64 ) ;
F_3 ( V_2 , V_83 -> V_150 ,
V_19 -> V_24 ) ;
}
}
return 0 ;
}
static int F_80 ( struct V_151 * V_40 )
{
struct V_1 * V_2 = F_81 ( V_40 ) ;
int V_63 ;
V_63 = F_78 ( V_2 ) ;
F_5 ( V_2 , false ) ;
if ( F_6 ( V_2 , V_132 ) )
F_73 ( V_2 -> V_122 ) ;
return V_63 ;
}
static int F_82 ( struct V_151 * V_40 )
{
struct V_1 * V_2 = F_81 ( V_40 ) ;
if ( F_6 ( V_2 , V_132 ) )
F_70 ( V_2 -> V_122 ) ;
F_5 ( V_2 , true ) ;
return F_79 ( V_2 ) ;
}
