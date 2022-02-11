struct V_1 * F_1 ( void )
{
return F_2 ( & V_2 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_4 ,
int V_5 , int V_6 )
{
int V_7 ;
if ( F_4 ( V_4 -> V_8 ) ) {
return ( 450000 * ( V_5 ) ) / ( 1800 - V_5 ) ;
}
if ( V_4 -> V_9 -> V_10 == V_11 ) {
V_7 = ( V_5 * 1000
- V_4 -> V_9 -> V_12 * V_6 )
/ V_4 -> V_13 ;
} else {
V_7 = ( 80000 * ( V_5 ) ) / ( 1800 - V_5 ) ;
}
return V_7 ;
}
static int F_5 ( struct V_1 * V_4 )
{
int V_14 ;
static int V_15 ;
V_14 = F_6 ( V_4 -> V_16 , V_17 ) ;
if ( V_14 < 0 ) {
F_7 ( V_4 -> V_18 ,
L_1 ,
V_19 ) ;
return V_15 ;
}
V_15 = V_14 ;
return V_14 ;
}
static int F_8 ( struct V_1 * V_4 ,
bool V_20 )
{
int V_21 ;
int V_22 = 0 ;
if ( F_4 ( V_4 -> V_8 ) )
return 0 ;
if ( V_4 -> V_9 -> V_10 == V_11 && V_20 ) {
if ( F_9 ( V_4 -> V_8 ) ) {
if ( V_4 -> V_13 == V_23 )
V_21 = V_24 ;
else
V_21 = V_25 ;
} else if ( F_10 ( V_4 -> V_8 ) || F_11 ( V_4 -> V_8 ) ) {
if ( V_4 -> V_13 == V_26 )
V_21 = V_27 ;
else
V_21 = V_28 ;
} else {
if ( V_4 -> V_13 == V_29 )
V_21 = V_30 ;
else
V_21 = V_31 ;
}
F_12 ( V_4 -> V_18 , L_2 , V_4 -> V_13 ) ;
V_22 = F_13 ( V_4 -> V_18 ,
V_32 , V_33 ,
V_34 , V_34 ) ;
if ( V_22 ) {
F_7 ( V_4 -> V_18 , L_3 ,
V_19 ) ;
return V_22 ;
}
F_14 ( 32 ) ;
V_22 = F_15 ( V_4 -> V_18 ,
V_32 , V_33 ,
V_34 | V_21 ) ;
if ( V_22 ) {
F_7 ( V_4 -> V_18 , L_4 ,
V_19 ) ;
goto V_35;
}
} else if ( V_4 -> V_9 -> V_10 == V_11 && ! V_20 ) {
F_12 ( V_4 -> V_18 , L_5 ) ;
if ( F_9 ( V_4 -> V_8 ) ) {
V_22 = F_13 (
V_4 -> V_18 ,
V_32 , V_33 ,
V_24 | V_25 ,
~ ( V_24 | V_25 ) ) ;
} else if ( F_10 ( V_4 -> V_8 ) || F_11 ( V_4 -> V_8 ) ) {
V_22 = F_13 (
V_4 -> V_18 ,
V_32 , V_33 ,
V_27 | V_28 ,
~ ( V_27 | V_28 ) ) ;
} else {
V_22 = F_13 (
V_4 -> V_18 ,
V_32 , V_33 ,
V_30 | V_31 ,
~ ( V_30 | V_31 ) ) ;
}
if ( V_22 ) {
F_7 ( V_4 -> V_18 , L_6 ,
V_19 ) ;
goto V_35;
}
V_22 = F_13 ( V_4 -> V_18 ,
V_32 , V_33 ,
V_36 | V_37 ,
V_36 | V_37 ) ;
if ( V_22 ) {
F_7 ( V_4 -> V_18 , L_7 ,
V_19 ) ;
goto V_38;
}
F_14 ( 32 ) ;
V_22 = F_13 ( V_4 -> V_18 ,
V_32 , V_33 ,
V_34 , ~ V_34 ) ;
if ( V_22 ) {
F_7 ( V_4 -> V_18 , L_8 ,
V_19 ) ;
goto V_39;
}
}
return V_22 ;
V_35:
if ( F_9 ( V_4 -> V_8 ) ) {
V_22 = F_13 ( V_4 -> V_18 ,
V_32 , V_33 ,
V_24 | V_25 ,
~ ( V_24 | V_25 ) ) ;
} else if ( F_10 ( V_4 -> V_8 ) || F_11 ( V_4 -> V_8 ) ) {
V_22 = F_13 ( V_4 -> V_18 ,
V_32 , V_33 ,
V_27 | V_28 ,
~ ( V_27 | V_28 ) ) ;
} else {
V_22 = F_13 ( V_4 -> V_18 ,
V_32 , V_33 ,
V_30 | V_31 ,
~ ( V_30 | V_31 ) ) ;
}
if ( V_22 ) {
F_7 ( V_4 -> V_18 , L_6 ,
V_19 ) ;
return V_22 ;
}
V_38:
V_22 = F_13 ( V_4 -> V_18 ,
V_32 , V_33 ,
V_36 | V_37 ,
V_36 | V_37 ) ;
if ( V_22 ) {
F_7 ( V_4 -> V_18 , L_7 ,
V_19 ) ;
return V_22 ;
}
V_39:
F_14 ( 32 ) ;
V_22 = F_13 ( V_4 -> V_18 ,
V_32 , V_33 ,
V_34 , ~ V_34 ) ;
if ( V_22 ) {
F_7 ( V_4 -> V_18 , L_8 ,
V_19 ) ;
return V_22 ;
}
return V_22 ;
}
static int F_16 ( struct V_1 * V_4 )
{
int V_22 ;
int V_40 = 0 ;
int V_41 ;
int V_6 ;
int V_42 ;
V_22 = F_8 ( V_4 , true ) ;
if ( V_22 ) {
F_7 ( V_4 -> V_18 , L_9 , V_19 ) ;
return V_22 ;
}
if ( ! V_4 -> V_43 )
V_4 -> V_43 = F_17 () ;
if ( ! V_4 -> V_43 ) {
F_7 ( V_4 -> V_18 , L_10 ) ;
return - V_44 ;
}
V_22 = F_18 ( V_4 -> V_43 ) ;
if ( V_22 ) {
F_7 ( V_4 -> V_18 , L_11 ) ;
return V_22 ;
}
do {
F_19 ( 20 ) ;
} while ( ! F_20 ( V_4 -> V_43 ) );
V_42 = 0 ;
do {
V_40 += F_5 ( V_4 ) ;
V_42 ++ ;
F_19 ( 20 ) ;
} while ( ! F_21 ( V_4 -> V_43 ) );
V_40 /= V_42 ;
V_22 = F_22 ( V_4 -> V_43 , & V_6 ) ;
if ( V_22 ) {
F_7 ( V_4 -> V_18 , L_12 ) ;
return V_22 ;
}
V_41 = F_3 ( V_4 , V_40 , V_6 ) ;
V_22 = F_8 ( V_4 , false ) ;
if ( V_22 ) {
F_7 ( V_4 -> V_18 , L_13 , V_19 ) ;
return V_22 ;
}
F_12 ( V_4 -> V_18 , L_14 ,
V_19 , V_40 , V_41 , V_6 , V_42 ) ;
return V_41 ;
}
static int F_23 ( struct V_1 * V_4 ,
const struct V_45 * V_46 , int V_47 , int V_41 )
{
int V_42 ;
if ( V_41 > V_46 [ 0 ] . V_48 )
V_42 = 0 ;
else if ( V_41 <= V_46 [ V_47 - 1 ] . V_48 )
V_42 = V_47 - 2 ;
else {
V_42 = 0 ;
while ( ! ( V_41 <= V_46 [ V_42 ] . V_48 &&
V_41 > V_46 [ V_42 + 1 ] . V_48 ) )
V_42 ++ ;
}
return V_46 [ V_42 ] . V_49 + ( ( V_46 [ V_42 + 1 ] . V_49 - V_46 [ V_42 ] . V_49 ) *
( V_41 - V_46 [ V_42 ] . V_48 ) ) / ( V_46 [ V_42 + 1 ] . V_48 - V_46 [ V_42 ] . V_48 ) ;
}
static int F_24 ( struct V_1 * V_4 )
{
int V_49 ;
static int V_15 ;
int V_50 , V_51 , V_52 ;
T_1 V_53 ;
V_53 = V_4 -> V_9 -> V_54 ;
if ( V_4 -> V_9 -> V_10 == V_11 &&
V_53 != V_55 ) {
V_50 = F_16 ( V_4 ) ;
if ( V_50 < 0 ) {
F_7 ( V_4 -> V_18 , L_15 ,
V_19 ) ;
return V_56 ;
}
V_49 = F_23 ( V_4 ,
V_4 -> V_9 -> V_57 [ V_53 ] . V_58 ,
V_4 -> V_9 -> V_57 [ V_53 ] . V_59 , V_50 ) ;
} else {
V_52 = F_6 ( V_4 -> V_16 , V_60 ) ;
if ( V_52 < 0 ) {
F_7 ( V_4 -> V_18 ,
L_16
L_17 , V_19 ) ;
return V_15 ;
}
V_51 = 230000 * V_52 / ( V_61 - V_52 ) ;
V_49 = F_23 ( V_4 ,
V_4 -> V_9 -> V_57 [ V_53 ] . V_58 ,
V_4 -> V_9 -> V_57 [ V_53 ] . V_59 , V_51 ) ;
V_15 = V_49 ;
}
F_12 ( V_4 -> V_18 , L_18 , V_49 ) ;
return V_49 ;
}
static int F_25 ( struct V_1 * V_4 )
{
int V_41 ;
T_1 V_42 ;
if ( F_9 ( V_4 -> V_8 ) )
V_4 -> V_13 = V_23 ;
else if ( F_10 ( V_4 -> V_8 ) || F_11 ( V_4 -> V_8 ) )
V_4 -> V_13 = V_26 ;
else
V_4 -> V_13 = V_29 ;
V_4 -> V_9 -> V_54 = V_55 ;
V_41 = F_16 ( V_4 ) ;
if ( V_41 < 0 ) {
F_7 ( V_4 -> V_18 , L_15 , V_19 ) ;
return - V_62 ;
}
for ( V_42 = V_55 + 1 ; V_42 < V_4 -> V_9 -> V_63 ; V_42 ++ ) {
if ( ( V_41 <= V_4 -> V_9 -> V_57 [ V_42 ] . V_64 ) &&
( V_41 >= V_4 -> V_9 -> V_57 [ V_42 ] . V_65 ) ) {
F_12 ( V_4 -> V_18 , L_19
L_20
L_21 ,
V_4 -> V_9 -> V_10 == V_11 ?
L_22 : L_23 ,
V_4 -> V_9 -> V_57 [ V_42 ] . V_65 , V_41 ,
V_4 -> V_9 -> V_57 [ V_42 ] . V_64 , V_42 ) ;
V_4 -> V_9 -> V_54 = V_42 ;
break;
}
}
if ( V_4 -> V_9 -> V_54 == V_55 ) {
F_26 ( V_4 -> V_18 , L_24
L_25 , V_41 ) ;
return - V_62 ;
}
if ( V_4 -> V_9 -> V_10 == V_11 &&
V_4 -> V_9 -> V_54 == 1 ) {
if ( F_9 ( V_4 -> V_8 ) ) {
F_12 ( V_4 -> V_18 ,
L_26 ) ;
V_4 -> V_13 = V_23 ;
} else if ( F_10 ( V_4 -> V_8 ) || F_11 ( V_4 -> V_8 ) ) {
F_12 ( V_4 -> V_18 ,
L_27 ) ;
V_4 -> V_13 = V_26 ;
} else {
F_12 ( V_4 -> V_18 , L_28 ) ;
V_4 -> V_13 = V_66 ;
}
}
return V_4 -> V_9 -> V_54 ;
}
static void F_27 ( struct V_67 * V_68 )
{
int V_69 ;
int V_70 ;
struct V_1 * V_4 = F_28 ( V_68 ,
struct V_1 , V_71 . V_68 ) ;
if ( ! V_4 -> V_72 ) {
if ( F_25 ( V_4 ) < 0 )
F_26 ( V_4 -> V_18 , L_29 ) ;
}
V_70 = F_24 ( V_4 ) ;
if ( ( V_70 == V_4 -> V_73 ) || ! V_4 -> V_72 ) {
if ( ( V_4 -> V_70 != V_4 -> V_73 ) || ! V_4 -> V_72 ) {
V_4 -> V_72 = true ;
V_4 -> V_70 = V_70 ;
F_29 ( V_4 -> V_74 ) ;
}
} else if ( V_70 < V_4 -> V_73 ) {
V_4 -> V_70 -- ;
F_29 ( V_4 -> V_74 ) ;
} else if ( V_70 > V_4 -> V_73 ) {
V_4 -> V_70 ++ ;
F_29 ( V_4 -> V_74 ) ;
}
V_4 -> V_73 = V_70 ;
if ( V_4 -> V_75 . V_76 || V_4 -> V_75 . V_77 )
V_69 = V_4 -> V_9 -> V_78 ;
else
V_69 = V_4 -> V_9 -> V_79 ;
F_30 ( V_4 -> V_80 ,
& V_4 -> V_71 ,
F_31 ( V_69 * V_81 ) ) ;
}
static T_2 F_32 ( int V_82 , void * V_83 )
{
struct V_1 * V_4 = V_83 ;
F_7 ( V_4 -> V_18 , L_30 ) ;
V_4 -> V_75 . V_84 = true ;
F_29 ( V_4 -> V_74 ) ;
return V_85 ;
}
static T_2 F_33 ( int V_82 , void * V_83 )
{
struct V_1 * V_4 = V_83 ;
if ( F_34 ( V_4 -> V_8 ) ) {
F_12 ( V_4 -> V_18 , L_31
L_32 ) ;
} else {
F_35 ( V_4 -> V_18 , L_33 ) ;
V_4 -> V_75 . V_86 = true ;
V_4 -> V_75 . V_87 = false ;
V_4 -> V_75 . V_88 = false ;
V_4 -> V_75 . V_89 = false ;
F_29 ( V_4 -> V_74 ) ;
}
return V_85 ;
}
static T_2 F_36 ( int V_82 , void * V_83 )
{
struct V_1 * V_4 = V_83 ;
F_35 ( V_4 -> V_18 , L_34 ) ;
V_4 -> V_75 . V_87 = true ;
V_4 -> V_75 . V_88 = false ;
V_4 -> V_75 . V_89 = false ;
V_4 -> V_75 . V_86 = false ;
F_29 ( V_4 -> V_74 ) ;
return V_85 ;
}
static T_2 F_37 ( int V_82 , void * V_83 )
{
struct V_1 * V_4 = V_83 ;
F_12 ( V_4 -> V_18 , L_35 ) ;
V_4 -> V_75 . V_89 = true ;
V_4 -> V_75 . V_88 = false ;
V_4 -> V_75 . V_87 = false ;
V_4 -> V_75 . V_86 = false ;
F_29 ( V_4 -> V_74 ) ;
return V_85 ;
}
static T_2 F_38 ( int V_82 , void * V_83 )
{
struct V_1 * V_4 = V_83 ;
F_12 ( V_4 -> V_18 , L_36 ) ;
V_4 -> V_75 . V_88 = true ;
V_4 -> V_75 . V_89 = false ;
V_4 -> V_75 . V_87 = false ;
V_4 -> V_75 . V_86 = false ;
F_29 ( V_4 -> V_74 ) ;
return V_85 ;
}
static void F_39 ( struct V_1 * V_4 ,
bool V_20 )
{
F_12 ( V_4 -> V_18 , L_37 ,
V_20 ) ;
F_40 ( & V_4 -> V_71 ) ;
if ( V_20 )
F_30 ( V_4 -> V_80 , & V_4 -> V_71 , 0 ) ;
}
int F_41 ( struct V_1 * V_4 )
{
int V_49 = 0 ;
if ( F_34 ( V_4 -> V_8 ) ) {
V_49 = V_4 -> V_70 * 10 ;
} else {
if ( V_4 -> V_75 . V_86 ) {
if ( V_49 > V_4 -> V_90 . V_91 )
V_49 = V_4 -> V_90 . V_91 * 10 ;
else
V_49 = V_4 -> V_70 * 10 ;
} else if ( V_4 -> V_75 . V_87 ) {
if ( V_49 < V_4 -> V_90 . V_92 )
V_49 = V_4 -> V_90 . V_92 * 10 ;
else
V_49 = V_4 -> V_70 * 10 ;
} else if ( V_4 -> V_75 . V_89 ) {
if ( V_49 > V_4 -> V_90 . V_93 )
V_49 = V_4 -> V_90 . V_93 * 10 ;
else
V_49 = V_4 -> V_70 * 10 ;
} else if ( V_4 -> V_75 . V_88 ) {
if ( V_49 < V_4 -> V_90 . V_93 )
V_49 = V_4 -> V_90 . V_93 * 10 ;
else
V_49 = V_4 -> V_70 * 10 ;
} else
V_49 = V_4 -> V_70 * 10 ;
}
return V_49 ;
}
int F_42 ( struct V_1 * V_94 )
{
return V_94 -> V_70 * 1000 ;
}
static int F_43 ( struct V_95 * V_96 ,
enum V_97 V_98 ,
union V_99 * V_100 )
{
struct V_1 * V_4 = F_44 ( V_96 ) ;
switch ( V_98 ) {
case V_101 :
case V_102 :
if ( V_4 -> V_75 . V_84 )
V_100 -> V_103 = 0 ;
else
V_100 -> V_103 = 1 ;
break;
case V_104 :
V_100 -> V_103 = V_4 -> V_9 -> V_57 [ V_4 -> V_9 -> V_54 ] . V_105 ;
break;
case V_106 :
V_100 -> V_103 = F_41 ( V_4 ) ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static int F_45 ( struct V_107 * V_18 , void * V_108 )
{
struct V_95 * V_96 ;
struct V_95 * V_109 = F_46 ( V_18 ) ;
const char * * V_110 = ( const char * * ) V_109 -> V_111 ;
struct V_1 * V_4 ;
union V_99 V_22 ;
int V_112 ;
V_96 = (struct V_95 * ) V_108 ;
V_4 = F_44 ( V_96 ) ;
V_112 = F_47 ( V_110 , V_109 -> V_113 , V_96 -> V_114 -> V_105 ) ;
if ( V_112 < 0 )
return 0 ;
for ( V_112 = 0 ; V_112 < V_109 -> V_114 -> V_115 ; V_112 ++ ) {
enum V_97 V_116 ;
V_116 = V_109 -> V_114 -> V_117 [ V_112 ] ;
if ( F_48 ( V_109 , V_116 , & V_22 ) )
continue;
switch ( V_116 ) {
case V_101 :
switch ( V_109 -> V_114 -> type ) {
case V_118 :
if ( ! V_22 . V_103 && V_4 -> V_75 . V_76 ) {
V_4 -> V_75 . V_76 = false ;
}
else if ( V_22 . V_103 && ! V_4 -> V_75 . V_76 ) {
V_4 -> V_75 . V_76 = true ;
if ( ! V_4 -> V_75 . V_77 )
F_39 ( V_4 , true ) ;
}
break;
case V_119 :
if ( ! V_22 . V_103 && V_4 -> V_75 . V_77 ) {
V_4 -> V_75 . V_77 = false ;
}
else if ( V_22 . V_103 && ! V_4 -> V_75 . V_77 ) {
V_4 -> V_75 . V_77 = true ;
if ( ! V_4 -> V_75 . V_76 )
F_39 ( V_4 , true ) ;
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
static void F_49 ( struct V_95 * V_96 )
{
struct V_1 * V_4 = F_44 ( V_96 ) ;
F_50 ( V_120 , NULL ,
V_4 -> V_74 , F_45 ) ;
}
static int F_51 ( struct V_121 * V_122 )
{
struct V_1 * V_4 = F_52 ( V_122 ) ;
F_39 ( V_4 , true ) ;
return 0 ;
}
static int F_53 ( struct V_121 * V_122 ,
T_3 V_123 )
{
struct V_1 * V_4 = F_52 ( V_122 ) ;
F_39 ( V_4 , false ) ;
return 0 ;
}
static int F_54 ( struct V_121 * V_122 )
{
struct V_1 * V_4 = F_52 ( V_122 ) ;
int V_42 , V_82 ;
for ( V_42 = 0 ; V_42 < F_55 ( V_124 ) ; V_42 ++ ) {
V_82 = F_56 ( V_122 , V_124 [ V_42 ] . V_105 ) ;
F_57 ( V_82 , V_4 ) ;
}
F_58 ( V_4 -> V_80 ) ;
F_59 () ;
F_60 ( V_4 -> V_74 ) ;
return 0 ;
}
static int F_61 ( struct V_121 * V_122 )
{
struct V_125 * V_126 = V_122 -> V_18 . V_127 ;
struct V_128 * V_129 = V_122 -> V_18 . V_130 ;
struct V_131 V_132 = {} ;
struct V_1 * V_4 ;
int V_82 , V_42 , V_22 = 0 ;
T_1 V_100 ;
V_4 = F_62 ( & V_122 -> V_18 , sizeof( * V_4 ) , V_133 ) ;
if ( ! V_4 ) {
F_7 ( & V_122 -> V_18 , L_38 , V_19 ) ;
return - V_134 ;
}
if ( ! V_129 ) {
F_7 ( & V_122 -> V_18 , L_39 ) ;
return - V_44 ;
}
V_4 -> V_9 = V_129 ;
if ( V_126 ) {
V_22 = F_63 ( & V_122 -> V_18 , V_126 , V_4 -> V_9 ) ;
if ( V_22 ) {
F_7 ( & V_122 -> V_18 , L_40 ) ;
return V_22 ;
}
}
V_4 -> V_18 = & V_122 -> V_18 ;
V_4 -> V_8 = F_46 ( V_122 -> V_18 . V_8 ) ;
V_4 -> V_16 = F_64 ( L_41 ) ;
V_4 -> V_72 = false ;
V_132 . V_111 = V_135 ;
V_132 . V_113 = F_55 ( V_135 ) ;
V_132 . V_136 = V_4 ;
V_4 -> V_80 =
F_65 ( L_42 , V_137 , 0 ) ;
if ( V_4 -> V_80 == NULL ) {
F_7 ( V_4 -> V_18 , L_43 ) ;
return - V_134 ;
}
F_66 ( & V_4 -> V_71 ,
F_27 ) ;
V_4 -> V_90 . V_91 = V_56 ;
V_4 -> V_90 . V_93 = V_138 ;
V_22 = F_67 ( V_4 -> V_18 , V_32 ,
V_139 , & V_100 ) ;
if ( V_22 < 0 ) {
F_7 ( V_4 -> V_18 , L_44 , V_19 ) ;
goto V_140;
}
switch ( V_100 ) {
case V_141 :
case V_142 :
V_4 -> V_90 . V_92 =
V_143 ;
break;
case V_144 :
V_4 -> V_90 . V_92 =
V_145 ;
break;
case V_146 :
V_4 -> V_90 . V_92 =
V_147 ;
break;
}
V_4 -> V_74 = F_68 ( V_4 -> V_18 , & V_148 ,
& V_132 ) ;
if ( F_69 ( V_4 -> V_74 ) ) {
F_7 ( V_4 -> V_18 , L_45 ) ;
V_22 = F_70 ( V_4 -> V_74 ) ;
goto V_140;
}
for ( V_42 = 0 ; V_42 < F_55 ( V_124 ) ; V_42 ++ ) {
V_82 = F_56 ( V_122 , V_124 [ V_42 ] . V_105 ) ;
V_22 = F_71 ( V_82 , NULL , V_124 [ V_42 ] . V_149 ,
V_150 | V_151 ,
V_124 [ V_42 ] . V_105 , V_4 ) ;
if ( V_22 ) {
F_7 ( V_4 -> V_18 , L_46
, V_124 [ V_42 ] . V_105 , V_82 , V_22 ) ;
goto F_57;
}
F_12 ( V_4 -> V_18 , L_47 ,
V_124 [ V_42 ] . V_105 , V_82 , V_22 ) ;
}
F_72 ( V_122 , V_4 ) ;
F_39 ( V_4 , true ) ;
F_73 ( & V_4 -> V_3 , & V_2 ) ;
return V_22 ;
F_57:
F_60 ( V_4 -> V_74 ) ;
for ( V_42 = V_42 - 1 ; V_42 >= 0 ; V_42 -- ) {
V_82 = F_56 ( V_122 , V_124 [ V_42 ] . V_105 ) ;
F_57 ( V_82 , V_4 ) ;
}
V_140:
F_58 ( V_4 -> V_80 ) ;
return V_22 ;
}
static int T_4 F_74 ( void )
{
return F_75 ( & V_152 ) ;
}
static void T_5 F_76 ( void )
{
F_77 ( & V_152 ) ;
}
