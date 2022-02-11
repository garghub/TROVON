struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( & V_3 , struct V_1 , V_4 ) ;
return V_2 ;
}
static int F_3 ( struct V_1 * V_5 ,
int V_6 , int V_7 )
{
int V_8 ;
if ( F_4 ( V_5 -> V_9 ) ) {
return ( 450000 * ( V_6 ) ) / ( 1800 - V_6 ) ;
}
if ( V_5 -> V_10 -> V_11 == V_12 ) {
V_8 = ( V_6 * 1000
- V_5 -> V_10 -> V_13 * V_7 )
/ V_5 -> V_14 ;
} else {
V_8 = ( 80000 * ( V_6 ) ) / ( 1800 - V_6 ) ;
}
return V_8 ;
}
static int F_5 ( struct V_1 * V_5 )
{
int V_15 ;
static int V_16 ;
V_15 = F_6 ( V_5 -> V_17 , V_18 ) ;
if ( V_15 < 0 ) {
F_7 ( V_5 -> V_19 ,
L_1 ,
V_20 ) ;
return V_16 ;
}
V_16 = V_15 ;
return V_15 ;
}
static int F_8 ( struct V_1 * V_5 ,
bool V_21 )
{
int V_22 ;
int V_23 = 0 ;
if ( F_4 ( V_5 -> V_9 ) )
return 0 ;
if ( V_5 -> V_10 -> V_11 == V_12 && V_21 ) {
if ( F_9 ( V_5 -> V_9 ) ) {
if ( V_5 -> V_14 == V_24 )
V_22 = V_25 ;
else
V_22 = V_26 ;
} else if ( F_10 ( V_5 -> V_9 ) || F_11 ( V_5 -> V_9 ) ) {
if ( V_5 -> V_14 == V_27 )
V_22 = V_28 ;
else
V_22 = V_29 ;
} else {
if ( V_5 -> V_14 == V_30 )
V_22 = V_31 ;
else
V_22 = V_32 ;
}
F_12 ( V_5 -> V_19 , L_2 , V_5 -> V_14 ) ;
V_23 = F_13 ( V_5 -> V_19 ,
V_33 , V_34 ,
V_35 , V_35 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_3 ,
V_20 ) ;
return V_23 ;
}
F_14 ( 32 ) ;
V_23 = F_15 ( V_5 -> V_19 ,
V_33 , V_34 ,
V_35 | V_22 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_4 ,
V_20 ) ;
goto V_36;
}
} else if ( V_5 -> V_10 -> V_11 == V_12 && ! V_21 ) {
F_12 ( V_5 -> V_19 , L_5 ) ;
if ( F_9 ( V_5 -> V_9 ) ) {
V_23 = F_13 (
V_5 -> V_19 ,
V_33 , V_34 ,
V_25 | V_26 ,
~ ( V_25 | V_26 ) ) ;
} else if ( F_10 ( V_5 -> V_9 ) || F_11 ( V_5 -> V_9 ) ) {
V_23 = F_13 (
V_5 -> V_19 ,
V_33 , V_34 ,
V_28 | V_29 ,
~ ( V_28 | V_29 ) ) ;
} else {
V_23 = F_13 (
V_5 -> V_19 ,
V_33 , V_34 ,
V_31 | V_32 ,
~ ( V_31 | V_32 ) ) ;
}
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_6 ,
V_20 ) ;
goto V_36;
}
V_23 = F_13 ( V_5 -> V_19 ,
V_33 , V_34 ,
V_37 | V_38 ,
V_37 | V_38 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_7 ,
V_20 ) ;
goto V_39;
}
F_14 ( 32 ) ;
V_23 = F_13 ( V_5 -> V_19 ,
V_33 , V_34 ,
V_35 , ~ V_35 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_8 ,
V_20 ) ;
goto V_40;
}
}
return V_23 ;
V_36:
if ( F_9 ( V_5 -> V_9 ) ) {
V_23 = F_13 ( V_5 -> V_19 ,
V_33 , V_34 ,
V_25 | V_26 ,
~ ( V_25 | V_26 ) ) ;
} else if ( F_10 ( V_5 -> V_9 ) || F_11 ( V_5 -> V_9 ) ) {
V_23 = F_13 ( V_5 -> V_19 ,
V_33 , V_34 ,
V_28 | V_29 ,
~ ( V_28 | V_29 ) ) ;
} else {
V_23 = F_13 ( V_5 -> V_19 ,
V_33 , V_34 ,
V_31 | V_32 ,
~ ( V_31 | V_32 ) ) ;
}
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_6 ,
V_20 ) ;
return V_23 ;
}
V_39:
V_23 = F_13 ( V_5 -> V_19 ,
V_33 , V_34 ,
V_37 | V_38 ,
V_37 | V_38 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_7 ,
V_20 ) ;
return V_23 ;
}
V_40:
F_14 ( 32 ) ;
V_23 = F_13 ( V_5 -> V_19 ,
V_33 , V_34 ,
V_35 , ~ V_35 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_8 ,
V_20 ) ;
return V_23 ;
}
return V_23 ;
}
static int F_16 ( struct V_1 * V_5 )
{
int V_23 ;
int V_41 = 0 ;
int V_42 ;
int V_7 ;
int V_43 ;
V_23 = F_8 ( V_5 , true ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_9 , V_20 ) ;
return V_23 ;
}
if ( ! V_5 -> V_44 )
V_5 -> V_44 = F_17 () ;
if ( ! V_5 -> V_44 ) {
F_7 ( V_5 -> V_19 , L_10 ) ;
return - V_45 ;
}
V_23 = F_18 ( V_5 -> V_44 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_11 ) ;
return V_23 ;
}
do {
F_19 ( 20 ) ;
} while ( ! F_20 ( V_5 -> V_44 ) );
V_43 = 0 ;
do {
V_41 += F_5 ( V_5 ) ;
V_43 ++ ;
F_19 ( 20 ) ;
} while ( ! F_21 ( V_5 -> V_44 ) );
V_41 /= V_43 ;
V_23 = F_22 ( V_5 -> V_44 , & V_7 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_12 ) ;
return V_23 ;
}
V_42 = F_3 ( V_5 , V_41 , V_7 ) ;
V_23 = F_8 ( V_5 , false ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_13 , V_20 ) ;
return V_23 ;
}
F_12 ( V_5 -> V_19 , L_14 ,
V_20 , V_41 , V_42 , V_7 , V_43 ) ;
return V_42 ;
}
static int F_23 ( struct V_1 * V_5 ,
const struct V_46 * V_47 , int V_48 , int V_42 )
{
int V_43 , V_49 ;
if ( V_42 > V_47 [ 0 ] . V_50 )
V_43 = 0 ;
else if ( V_42 <= V_47 [ V_48 - 1 ] . V_50 )
V_43 = V_48 - 2 ;
else {
V_43 = 0 ;
while ( ! ( V_42 <= V_47 [ V_43 ] . V_50 &&
V_42 > V_47 [ V_43 + 1 ] . V_50 ) )
V_43 ++ ;
}
V_49 = V_47 [ V_43 ] . V_49 + ( ( V_47 [ V_43 + 1 ] . V_49 - V_47 [ V_43 ] . V_49 ) *
( V_42 - V_47 [ V_43 ] . V_50 ) ) / ( V_47 [ V_43 + 1 ] . V_50 - V_47 [ V_43 ] . V_50 ) ;
return V_49 ;
}
static int F_24 ( struct V_1 * V_5 )
{
int V_49 ;
static int V_16 ;
int V_51 , V_52 , V_53 ;
T_1 V_54 ;
V_54 = V_5 -> V_10 -> V_55 ;
if ( V_5 -> V_10 -> V_11 == V_12 &&
V_54 != V_56 ) {
V_51 = F_16 ( V_5 ) ;
if ( V_51 < 0 ) {
F_7 ( V_5 -> V_19 , L_15 ,
V_20 ) ;
return V_57 ;
}
V_49 = F_23 ( V_5 ,
V_5 -> V_10 -> V_58 [ V_54 ] . V_59 ,
V_5 -> V_10 -> V_58 [ V_54 ] . V_60 , V_51 ) ;
} else {
V_53 = F_6 ( V_5 -> V_17 , V_61 ) ;
if ( V_53 < 0 ) {
F_7 ( V_5 -> V_19 ,
L_16
L_17 , V_20 ) ;
return V_16 ;
}
V_52 = 230000 * V_53 / ( V_62 - V_53 ) ;
V_49 = F_23 ( V_5 ,
V_5 -> V_10 -> V_58 [ V_54 ] . V_59 ,
V_5 -> V_10 -> V_58 [ V_54 ] . V_60 , V_52 ) ;
V_16 = V_49 ;
}
F_12 ( V_5 -> V_19 , L_18 , V_49 ) ;
return V_49 ;
}
static int F_25 ( struct V_1 * V_5 )
{
int V_42 ;
T_1 V_43 ;
if ( F_9 ( V_5 -> V_9 ) )
V_5 -> V_14 = V_24 ;
else if ( F_10 ( V_5 -> V_9 ) || F_11 ( V_5 -> V_9 ) )
V_5 -> V_14 = V_27 ;
else
V_5 -> V_14 = V_30 ;
V_5 -> V_10 -> V_55 = V_56 ;
V_42 = F_16 ( V_5 ) ;
if ( V_42 < 0 ) {
F_7 ( V_5 -> V_19 , L_15 , V_20 ) ;
return - V_63 ;
}
for ( V_43 = V_56 + 1 ; V_43 < V_5 -> V_10 -> V_64 ; V_43 ++ ) {
if ( ( V_42 <= V_5 -> V_10 -> V_58 [ V_43 ] . V_65 ) &&
( V_42 >= V_5 -> V_10 -> V_58 [ V_43 ] . V_66 ) ) {
F_12 ( V_5 -> V_19 , L_19
L_20
L_21 ,
V_5 -> V_10 -> V_11 == V_12 ?
L_22 : L_23 ,
V_5 -> V_10 -> V_58 [ V_43 ] . V_66 , V_42 ,
V_5 -> V_10 -> V_58 [ V_43 ] . V_65 , V_43 ) ;
V_5 -> V_10 -> V_55 = V_43 ;
break;
}
}
if ( V_5 -> V_10 -> V_55 == V_56 ) {
F_26 ( V_5 -> V_19 , L_24
L_25 , V_42 ) ;
return - V_63 ;
}
if ( V_5 -> V_10 -> V_11 == V_12 &&
V_5 -> V_10 -> V_55 == 1 ) {
if ( F_9 ( V_5 -> V_9 ) ) {
F_12 ( V_5 -> V_19 ,
L_26 ) ;
V_5 -> V_14 = V_24 ;
} else if ( F_10 ( V_5 -> V_9 ) || F_11 ( V_5 -> V_9 ) ) {
F_12 ( V_5 -> V_19 ,
L_27 ) ;
V_5 -> V_14 = V_27 ;
} else {
F_12 ( V_5 -> V_19 , L_28 ) ;
V_5 -> V_14 = V_67 ;
}
}
return V_5 -> V_10 -> V_55 ;
}
static void F_27 ( struct V_68 * V_69 )
{
int V_70 ;
int V_71 ;
struct V_1 * V_5 = F_28 ( V_69 ,
struct V_1 , V_72 . V_69 ) ;
if ( ! V_5 -> V_73 ) {
if ( F_25 ( V_5 ) < 0 )
F_26 ( V_5 -> V_19 , L_29 ) ;
}
V_71 = F_24 ( V_5 ) ;
if ( ( V_71 == V_5 -> V_74 ) || ! V_5 -> V_73 ) {
if ( ( V_5 -> V_71 != V_5 -> V_74 ) || ! V_5 -> V_73 ) {
V_5 -> V_73 = true ;
V_5 -> V_71 = V_71 ;
F_29 ( & V_5 -> V_75 ) ;
}
} else if ( V_71 < V_5 -> V_74 ) {
V_5 -> V_71 -- ;
F_29 ( & V_5 -> V_75 ) ;
} else if ( V_71 > V_5 -> V_74 ) {
V_5 -> V_71 ++ ;
F_29 ( & V_5 -> V_75 ) ;
}
V_5 -> V_74 = V_71 ;
if ( V_5 -> V_76 . V_77 || V_5 -> V_76 . V_78 )
V_70 = V_5 -> V_10 -> V_79 ;
else
V_70 = V_5 -> V_10 -> V_80 ;
F_30 ( V_5 -> V_81 ,
& V_5 -> V_72 ,
F_31 ( V_70 * V_82 ) ) ;
}
static T_2 F_32 ( int V_83 , void * V_84 )
{
struct V_1 * V_5 = V_84 ;
F_7 ( V_5 -> V_19 , L_30 ) ;
V_5 -> V_76 . V_85 = true ;
F_29 ( & V_5 -> V_75 ) ;
return V_86 ;
}
static T_2 F_33 ( int V_83 , void * V_84 )
{
struct V_1 * V_5 = V_84 ;
if ( F_34 ( V_5 -> V_9 ) ) {
F_12 ( V_5 -> V_19 , L_31
L_32 ) ;
} else {
F_35 ( V_5 -> V_19 , L_33 ) ;
V_5 -> V_76 . V_87 = true ;
V_5 -> V_76 . V_88 = false ;
V_5 -> V_76 . V_89 = false ;
V_5 -> V_76 . V_90 = false ;
F_29 ( & V_5 -> V_75 ) ;
}
return V_86 ;
}
static T_2 F_36 ( int V_83 , void * V_84 )
{
struct V_1 * V_5 = V_84 ;
F_35 ( V_5 -> V_19 , L_34 ) ;
V_5 -> V_76 . V_88 = true ;
V_5 -> V_76 . V_89 = false ;
V_5 -> V_76 . V_90 = false ;
V_5 -> V_76 . V_87 = false ;
F_29 ( & V_5 -> V_75 ) ;
return V_86 ;
}
static T_2 F_37 ( int V_83 , void * V_84 )
{
struct V_1 * V_5 = V_84 ;
F_12 ( V_5 -> V_19 , L_35 ) ;
V_5 -> V_76 . V_90 = true ;
V_5 -> V_76 . V_89 = false ;
V_5 -> V_76 . V_88 = false ;
V_5 -> V_76 . V_87 = false ;
F_29 ( & V_5 -> V_75 ) ;
return V_86 ;
}
static T_2 F_38 ( int V_83 , void * V_84 )
{
struct V_1 * V_5 = V_84 ;
F_12 ( V_5 -> V_19 , L_36 ) ;
V_5 -> V_76 . V_89 = true ;
V_5 -> V_76 . V_90 = false ;
V_5 -> V_76 . V_88 = false ;
V_5 -> V_76 . V_87 = false ;
F_29 ( & V_5 -> V_75 ) ;
return V_86 ;
}
static void F_39 ( struct V_1 * V_5 ,
bool V_21 )
{
F_12 ( V_5 -> V_19 , L_37 ,
V_21 ) ;
F_40 ( & V_5 -> V_72 ) ;
if ( V_21 )
F_30 ( V_5 -> V_81 , & V_5 -> V_72 , 0 ) ;
}
int F_41 ( struct V_1 * V_5 )
{
int V_49 = 0 ;
if ( F_34 ( V_5 -> V_9 ) ) {
V_49 = V_5 -> V_71 * 10 ;
} else {
if ( V_5 -> V_76 . V_87 ) {
if ( V_49 > V_5 -> V_91 . V_92 )
V_49 = V_5 -> V_91 . V_92 * 10 ;
else
V_49 = V_5 -> V_71 * 10 ;
} else if ( V_5 -> V_76 . V_88 ) {
if ( V_49 < V_5 -> V_91 . V_93 )
V_49 = V_5 -> V_91 . V_93 * 10 ;
else
V_49 = V_5 -> V_71 * 10 ;
} else if ( V_5 -> V_76 . V_90 ) {
if ( V_49 > V_5 -> V_91 . V_94 )
V_49 = V_5 -> V_91 . V_94 * 10 ;
else
V_49 = V_5 -> V_71 * 10 ;
} else if ( V_5 -> V_76 . V_89 ) {
if ( V_49 < V_5 -> V_91 . V_94 )
V_49 = V_5 -> V_91 . V_94 * 10 ;
else
V_49 = V_5 -> V_71 * 10 ;
} else
V_49 = V_5 -> V_71 * 10 ;
}
return V_49 ;
}
int F_42 ( struct V_1 * V_2 )
{
return V_2 -> V_71 * 1000 ;
}
static int F_43 ( struct V_95 * V_96 ,
enum V_97 V_98 ,
union V_99 * V_100 )
{
struct V_1 * V_5 ;
V_5 = F_44 ( V_96 ) ;
switch ( V_98 ) {
case V_101 :
case V_102 :
if ( V_5 -> V_76 . V_85 )
V_100 -> V_103 = 0 ;
else
V_100 -> V_103 = 1 ;
break;
case V_104 :
V_100 -> V_103 = V_5 -> V_10 -> V_58 [ V_5 -> V_10 -> V_55 ] . V_105 ;
break;
case V_106 :
V_100 -> V_103 = F_41 ( V_5 ) ;
break;
default:
return - V_45 ;
}
return 0 ;
}
static int F_45 ( struct V_107 * V_19 , void * V_108 )
{
struct V_95 * V_96 ;
struct V_95 * V_109 ;
struct V_1 * V_5 ;
union V_99 V_23 ;
int V_43 , V_110 ;
bool V_111 = false ;
V_96 = (struct V_95 * ) V_108 ;
V_109 = F_46 ( V_19 ) ;
V_5 = F_44 ( V_96 ) ;
for ( V_43 = 0 ; V_43 < V_109 -> V_112 ; V_43 ++ ) {
if ( ! strcmp ( V_109 -> V_113 [ V_43 ] , V_96 -> V_105 ) )
V_111 = true ;
}
if ( ! V_111 )
return 0 ;
for ( V_110 = 0 ; V_110 < V_109 -> V_114 ; V_110 ++ ) {
enum V_97 V_115 ;
V_115 = V_109 -> V_116 [ V_110 ] ;
if ( V_109 -> V_117 ( V_109 , V_115 , & V_23 ) )
continue;
switch ( V_115 ) {
case V_101 :
switch ( V_109 -> type ) {
case V_118 :
if ( ! V_23 . V_103 && V_5 -> V_76 . V_77 ) {
V_5 -> V_76 . V_77 = false ;
}
else if ( V_23 . V_103 && ! V_5 -> V_76 . V_77 ) {
V_5 -> V_76 . V_77 = true ;
if ( ! V_5 -> V_76 . V_78 )
F_39 ( V_5 , true ) ;
}
break;
case V_119 :
if ( ! V_23 . V_103 && V_5 -> V_76 . V_78 ) {
V_5 -> V_76 . V_78 = false ;
}
else if ( V_23 . V_103 && ! V_5 -> V_76 . V_78 ) {
V_5 -> V_76 . V_78 = true ;
if ( ! V_5 -> V_76 . V_77 )
F_39 ( V_5 , true ) ;
}
break;
default:
break;
}
break;
default:
break;
}
}
return 0 ;
}
static void F_47 ( struct V_95 * V_96 )
{
struct V_1 * V_5 = F_44 ( V_96 ) ;
F_48 ( V_120 , NULL ,
& V_5 -> V_75 , F_45 ) ;
}
static int F_49 ( struct V_121 * V_122 )
{
struct V_1 * V_5 = F_50 ( V_122 ) ;
F_39 ( V_5 , true ) ;
return 0 ;
}
static int F_51 ( struct V_121 * V_122 ,
T_3 V_123 )
{
struct V_1 * V_5 = F_50 ( V_122 ) ;
F_39 ( V_5 , false ) ;
return 0 ;
}
static int F_52 ( struct V_121 * V_122 )
{
struct V_1 * V_5 = F_50 ( V_122 ) ;
int V_43 , V_83 ;
for ( V_43 = 0 ; V_43 < F_53 ( V_124 ) ; V_43 ++ ) {
V_83 = F_54 ( V_122 , V_124 [ V_43 ] . V_105 ) ;
F_55 ( V_83 , V_5 ) ;
}
F_56 ( V_5 -> V_81 ) ;
F_57 () ;
F_58 ( & V_5 -> V_75 ) ;
F_59 ( V_122 , NULL ) ;
return 0 ;
}
static int F_60 ( struct V_121 * V_122 )
{
struct V_125 * V_126 = V_122 -> V_19 . V_127 ;
struct V_128 * V_129 = V_122 -> V_19 . V_130 ;
struct V_1 * V_5 ;
int V_83 , V_43 , V_23 = 0 ;
T_1 V_100 ;
V_5 = F_61 ( & V_122 -> V_19 , sizeof( * V_5 ) , V_131 ) ;
if ( ! V_5 ) {
F_7 ( & V_122 -> V_19 , L_38 , V_20 ) ;
return - V_132 ;
}
if ( ! V_129 ) {
F_7 ( & V_122 -> V_19 , L_39 ) ;
return - V_45 ;
}
V_5 -> V_10 = V_129 ;
if ( V_126 ) {
V_23 = F_62 ( & V_122 -> V_19 , V_126 , V_5 -> V_10 ) ;
if ( V_23 ) {
F_7 ( & V_122 -> V_19 , L_40 ) ;
return V_23 ;
}
}
V_5 -> V_19 = & V_122 -> V_19 ;
V_5 -> V_9 = F_46 ( V_122 -> V_19 . V_9 ) ;
V_5 -> V_17 = F_63 ( L_41 ) ;
V_5 -> V_73 = false ;
V_5 -> V_75 . V_105 = L_42 ;
V_5 -> V_75 . type = V_133 ;
V_5 -> V_75 . V_116 = V_134 ;
V_5 -> V_75 . V_114 = F_53 ( V_134 ) ;
V_5 -> V_75 . V_117 = F_43 ;
V_5 -> V_75 . V_113 = V_135 ;
V_5 -> V_75 . V_112 = F_53 ( V_135 ) ;
V_5 -> V_75 . V_136 =
F_47 ;
V_5 -> V_81 =
F_64 ( L_43 ) ;
if ( V_5 -> V_81 == NULL ) {
F_7 ( V_5 -> V_19 , L_44 ) ;
return - V_132 ;
}
F_65 ( & V_5 -> V_72 ,
F_27 ) ;
V_5 -> V_91 . V_92 = V_57 ;
V_5 -> V_91 . V_94 = V_137 ;
V_23 = F_66 ( V_5 -> V_19 , V_33 ,
V_138 , & V_100 ) ;
if ( V_23 < 0 ) {
F_7 ( V_5 -> V_19 , L_45 , V_20 ) ;
goto V_139;
}
switch ( V_100 ) {
case V_140 :
case V_141 :
V_5 -> V_91 . V_93 =
V_142 ;
break;
case V_143 :
V_5 -> V_91 . V_93 =
V_144 ;
break;
case V_145 :
V_5 -> V_91 . V_93 =
V_146 ;
break;
}
V_23 = F_67 ( V_5 -> V_19 , & V_5 -> V_75 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_46 ) ;
goto V_139;
}
for ( V_43 = 0 ; V_43 < F_53 ( V_124 ) ; V_43 ++ ) {
V_83 = F_54 ( V_122 , V_124 [ V_43 ] . V_105 ) ;
V_23 = F_68 ( V_83 , NULL , V_124 [ V_43 ] . V_147 ,
V_148 | V_149 ,
V_124 [ V_43 ] . V_105 , V_5 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_47
, V_124 [ V_43 ] . V_105 , V_83 , V_23 ) ;
goto F_55;
}
F_12 ( V_5 -> V_19 , L_48 ,
V_124 [ V_43 ] . V_105 , V_83 , V_23 ) ;
}
F_59 ( V_122 , V_5 ) ;
F_39 ( V_5 , true ) ;
F_69 ( & V_5 -> V_4 , & V_3 ) ;
return V_23 ;
F_55:
F_58 ( & V_5 -> V_75 ) ;
for ( V_43 = V_43 - 1 ; V_43 >= 0 ; V_43 -- ) {
V_83 = F_54 ( V_122 , V_124 [ V_43 ] . V_105 ) ;
F_55 ( V_83 , V_5 ) ;
}
V_139:
F_56 ( V_5 -> V_81 ) ;
return V_23 ;
}
static int T_4 F_70 ( void )
{
return F_71 ( & V_150 ) ;
}
static void T_5 F_72 ( void )
{
F_73 ( & V_150 ) ;
}
