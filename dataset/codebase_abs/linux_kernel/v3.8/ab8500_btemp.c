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
if ( V_5 -> V_14 == V_24 )
V_22 = V_25 ;
else
V_22 = V_26 ;
F_9 ( V_5 -> V_19 , L_2 , V_5 -> V_14 ) ;
V_23 = F_10 ( V_5 -> V_19 ,
V_27 , V_28 ,
V_29 , V_29 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_3 ,
V_20 ) ;
return V_23 ;
}
F_11 ( 32 ) ;
V_23 = F_12 ( V_5 -> V_19 ,
V_27 , V_28 ,
V_29 | V_22 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_4 ,
V_20 ) ;
goto V_30;
}
} else if ( V_5 -> V_10 -> V_11 == V_12 && ! V_21 ) {
F_9 ( V_5 -> V_19 , L_5 ) ;
V_23 = F_10 ( V_5 -> V_19 ,
V_27 , V_28 ,
V_25 | V_26 ,
~ ( V_25 | V_26 ) ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_6 ,
V_20 ) ;
goto V_30;
}
V_23 = F_10 ( V_5 -> V_19 ,
V_27 , V_28 ,
V_31 | V_32 ,
V_31 | V_32 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_7 ,
V_20 ) ;
goto V_33;
}
F_11 ( 32 ) ;
V_23 = F_10 ( V_5 -> V_19 ,
V_27 , V_28 ,
V_29 , ~ V_29 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_8 ,
V_20 ) ;
goto V_34;
}
}
return V_23 ;
V_30:
V_23 = F_10 ( V_5 -> V_19 ,
V_27 , V_28 ,
V_25 | V_26 ,
~ ( V_25 | V_26 ) ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_6 ,
V_20 ) ;
return V_23 ;
}
V_33:
V_23 = F_10 ( V_5 -> V_19 ,
V_27 , V_28 ,
V_31 | V_32 ,
V_31 | V_32 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_7 ,
V_20 ) ;
return V_23 ;
}
V_34:
F_11 ( 32 ) ;
V_23 = F_10 ( V_5 -> V_19 ,
V_27 , V_28 ,
V_29 , ~ V_29 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_8 ,
V_20 ) ;
return V_23 ;
}
return V_23 ;
}
static int F_13 ( struct V_1 * V_5 )
{
int V_23 ;
int V_35 = 0 ;
int V_36 ;
int V_7 ;
int V_37 ;
V_23 = F_8 ( V_5 , true ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_9 , V_20 ) ;
return V_23 ;
}
if ( ! V_5 -> V_38 )
V_5 -> V_38 = F_14 () ;
if ( ! V_5 -> V_38 ) {
F_7 ( V_5 -> V_19 , L_10 ) ;
return - V_39 ;
}
V_23 = F_15 ( V_5 -> V_38 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_11 ) ;
return V_23 ;
}
V_37 = 0 ;
do {
V_35 += F_5 ( V_5 ) ;
V_37 ++ ;
F_16 ( 20 ) ;
} while ( ! F_17 ( V_5 -> V_38 ) );
V_35 /= V_37 ;
V_23 = F_18 ( V_5 -> V_38 , & V_7 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_12 ) ;
return V_23 ;
}
V_36 = F_3 ( V_5 , V_35 , V_7 ) ;
V_23 = F_8 ( V_5 , false ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_13 , V_20 ) ;
return V_23 ;
}
F_9 ( V_5 -> V_19 , L_14 ,
V_20 , V_35 , V_36 , V_7 , V_37 ) ;
return V_36 ;
}
static int F_19 ( struct V_1 * V_5 ,
const struct V_40 * V_41 , int V_42 , int V_36 )
{
int V_37 , V_43 ;
if ( V_36 > V_41 [ 0 ] . V_44 )
V_37 = 0 ;
else if ( V_36 <= V_41 [ V_42 - 1 ] . V_44 )
V_37 = V_42 - 2 ;
else {
V_37 = 0 ;
while ( ! ( V_36 <= V_41 [ V_37 ] . V_44 &&
V_36 > V_41 [ V_37 + 1 ] . V_44 ) )
V_37 ++ ;
}
V_43 = V_41 [ V_37 ] . V_43 + ( ( V_41 [ V_37 + 1 ] . V_43 - V_41 [ V_37 ] . V_43 ) *
( V_36 - V_41 [ V_37 ] . V_44 ) ) / ( V_41 [ V_37 + 1 ] . V_44 - V_41 [ V_37 ] . V_44 ) ;
return V_43 ;
}
static int F_20 ( struct V_1 * V_5 )
{
int V_43 ;
static int V_16 ;
int V_45 , V_46 , V_47 ;
T_1 V_48 ;
V_48 = V_5 -> V_10 -> V_49 ;
if ( V_5 -> V_10 -> V_11 == V_12 &&
V_48 != V_50 ) {
V_45 = F_13 ( V_5 ) ;
if ( V_45 < 0 ) {
F_7 ( V_5 -> V_19 , L_15 ,
V_20 ) ;
return V_51 ;
}
V_43 = F_19 ( V_5 ,
V_5 -> V_10 -> V_52 [ V_48 ] . V_53 ,
V_5 -> V_10 -> V_52 [ V_48 ] . V_54 , V_45 ) ;
} else {
V_47 = F_6 ( V_5 -> V_17 , V_55 ) ;
if ( V_47 < 0 ) {
F_7 ( V_5 -> V_19 ,
L_16
L_17 , V_20 ) ;
return V_16 ;
}
V_46 = 230000 * V_47 / ( V_56 - V_47 ) ;
V_43 = F_19 ( V_5 ,
V_5 -> V_10 -> V_52 [ V_48 ] . V_53 ,
V_5 -> V_10 -> V_52 [ V_48 ] . V_54 , V_46 ) ;
V_16 = V_43 ;
}
F_9 ( V_5 -> V_19 , L_18 , V_43 ) ;
return V_43 ;
}
static int F_21 ( struct V_1 * V_5 )
{
int V_36 ;
T_1 V_37 ;
V_5 -> V_14 = V_24 ;
V_5 -> V_10 -> V_49 = V_50 ;
V_36 = F_13 ( V_5 ) ;
if ( V_36 < 0 ) {
F_7 ( V_5 -> V_19 , L_15 , V_20 ) ;
return - V_57 ;
}
for ( V_37 = V_50 + 1 ; V_37 < V_5 -> V_10 -> V_58 ; V_37 ++ ) {
if ( ( V_36 <= V_5 -> V_10 -> V_52 [ V_37 ] . V_59 ) &&
( V_36 >= V_5 -> V_10 -> V_52 [ V_37 ] . V_60 ) ) {
F_9 ( V_5 -> V_19 , L_19
L_20
L_21 ,
V_5 -> V_10 -> V_11 == V_12 ?
L_22 : L_23 ,
V_5 -> V_10 -> V_52 [ V_37 ] . V_60 , V_36 ,
V_5 -> V_10 -> V_52 [ V_37 ] . V_59 , V_37 ) ;
V_5 -> V_10 -> V_49 = V_37 ;
break;
}
}
if ( V_5 -> V_10 -> V_49 == V_50 ) {
F_22 ( V_5 -> V_19 , L_24
L_25 , V_36 ) ;
return - V_57 ;
}
if ( V_5 -> V_10 -> V_11 == V_12 &&
V_5 -> V_10 -> V_49 == 1 ) {
F_9 ( V_5 -> V_19 , L_26 ) ;
V_5 -> V_14 = V_61 ;
}
return V_5 -> V_10 -> V_49 ;
}
static void F_23 ( struct V_62 * V_63 )
{
int V_64 ;
struct V_1 * V_5 = F_24 ( V_63 ,
struct V_1 , V_65 . V_63 ) ;
V_5 -> V_66 = F_20 ( V_5 ) ;
if ( V_5 -> V_66 != V_5 -> V_67 ) {
V_5 -> V_67 = V_5 -> V_66 ;
F_25 ( & V_5 -> V_68 ) ;
}
if ( V_5 -> V_69 . V_70 || V_5 -> V_69 . V_71 )
V_64 = V_5 -> V_10 -> V_72 ;
else
V_64 = V_5 -> V_10 -> V_73 ;
F_26 ( V_5 -> V_74 ,
& V_5 -> V_65 ,
F_27 ( V_64 * V_75 ) ) ;
}
static T_2 F_28 ( int V_76 , void * V_77 )
{
struct V_1 * V_5 = V_77 ;
F_7 ( V_5 -> V_19 , L_27 ) ;
V_5 -> V_69 . V_78 = true ;
F_25 ( & V_5 -> V_68 ) ;
return V_79 ;
}
static T_2 F_29 ( int V_76 , void * V_77 )
{
struct V_1 * V_5 = V_77 ;
if ( F_30 ( V_5 -> V_9 ) ) {
F_9 ( V_5 -> V_19 , L_28
L_29 ) ;
} else {
F_31 ( V_5 -> V_19 , L_30 ) ;
V_5 -> V_69 . V_80 = true ;
V_5 -> V_69 . V_81 = false ;
V_5 -> V_69 . V_82 = false ;
V_5 -> V_69 . V_83 = false ;
F_25 ( & V_5 -> V_68 ) ;
}
return V_79 ;
}
static T_2 F_32 ( int V_76 , void * V_77 )
{
struct V_1 * V_5 = V_77 ;
F_31 ( V_5 -> V_19 , L_31 ) ;
V_5 -> V_69 . V_81 = true ;
V_5 -> V_69 . V_82 = false ;
V_5 -> V_69 . V_83 = false ;
V_5 -> V_69 . V_80 = false ;
F_25 ( & V_5 -> V_68 ) ;
return V_79 ;
}
static T_2 F_33 ( int V_76 , void * V_77 )
{
struct V_1 * V_5 = V_77 ;
F_9 ( V_5 -> V_19 , L_32 ) ;
V_5 -> V_69 . V_83 = true ;
V_5 -> V_69 . V_82 = false ;
V_5 -> V_69 . V_81 = false ;
V_5 -> V_69 . V_80 = false ;
F_25 ( & V_5 -> V_68 ) ;
return V_79 ;
}
static T_2 F_34 ( int V_76 , void * V_77 )
{
struct V_1 * V_5 = V_77 ;
F_9 ( V_5 -> V_19 , L_33 ) ;
V_5 -> V_69 . V_82 = true ;
V_5 -> V_69 . V_83 = false ;
V_5 -> V_69 . V_81 = false ;
V_5 -> V_69 . V_80 = false ;
F_25 ( & V_5 -> V_68 ) ;
return V_79 ;
}
static void F_35 ( struct V_1 * V_5 ,
bool V_21 )
{
F_9 ( V_5 -> V_19 , L_34 ,
V_21 ) ;
F_36 ( & V_5 -> V_65 ) ;
if ( V_21 )
F_26 ( V_5 -> V_74 , & V_5 -> V_65 , 0 ) ;
}
static int F_37 ( struct V_1 * V_5 )
{
int V_43 = 0 ;
if ( F_30 ( V_5 -> V_9 ) ) {
V_43 = V_5 -> V_66 * 10 ;
} else {
if ( V_5 -> V_69 . V_80 ) {
if ( V_43 > V_5 -> V_84 . V_85 )
V_43 = V_5 -> V_84 . V_85 ;
else
V_43 = V_5 -> V_66 * 10 ;
} else if ( V_5 -> V_69 . V_81 ) {
if ( V_43 < V_5 -> V_84 . V_86 )
V_43 = V_5 -> V_84 . V_86 ;
else
V_43 = V_5 -> V_66 * 10 ;
} else if ( V_5 -> V_69 . V_83 ) {
if ( V_43 > V_5 -> V_84 . V_87 )
V_43 = V_5 -> V_84 . V_87 ;
else
V_43 = V_5 -> V_66 * 10 ;
} else if ( V_5 -> V_69 . V_82 ) {
if ( V_43 < V_5 -> V_84 . V_87 )
V_43 = V_5 -> V_84 . V_87 ;
else
V_43 = V_5 -> V_66 * 10 ;
} else
V_43 = V_5 -> V_66 * 10 ;
}
return V_43 ;
}
int F_38 ( struct V_1 * V_2 )
{
return V_2 -> V_66 * 1000 ;
}
static int F_39 ( struct V_88 * V_89 ,
enum V_90 V_91 ,
union V_92 * V_93 )
{
struct V_1 * V_5 ;
V_5 = F_40 ( V_89 ) ;
switch ( V_91 ) {
case V_94 :
case V_95 :
if ( V_5 -> V_69 . V_78 )
V_93 -> V_96 = 0 ;
else
V_93 -> V_96 = 1 ;
break;
case V_97 :
V_93 -> V_96 = V_5 -> V_10 -> V_52 [ V_5 -> V_10 -> V_49 ] . V_98 ;
break;
case V_99 :
V_93 -> V_96 = F_37 ( V_5 ) ;
break;
default:
return - V_39 ;
}
return 0 ;
}
static int F_41 ( struct V_100 * V_19 , void * V_101 )
{
struct V_88 * V_89 ;
struct V_88 * V_102 ;
struct V_1 * V_5 ;
union V_92 V_23 ;
int V_37 , V_103 ;
bool V_104 = false ;
V_89 = (struct V_88 * ) V_101 ;
V_102 = F_42 ( V_19 ) ;
V_5 = F_40 ( V_89 ) ;
for ( V_37 = 0 ; V_37 < V_102 -> V_105 ; V_37 ++ ) {
if ( ! strcmp ( V_102 -> V_106 [ V_37 ] , V_89 -> V_98 ) )
V_104 = true ;
}
if ( ! V_104 )
return 0 ;
for ( V_103 = 0 ; V_103 < V_102 -> V_107 ; V_103 ++ ) {
enum V_90 V_108 ;
V_108 = V_102 -> V_109 [ V_103 ] ;
if ( V_102 -> V_110 ( V_102 , V_108 , & V_23 ) )
continue;
switch ( V_108 ) {
case V_94 :
switch ( V_102 -> type ) {
case V_111 :
if ( ! V_23 . V_96 && V_5 -> V_69 . V_70 ) {
V_5 -> V_69 . V_70 = false ;
}
else if ( V_23 . V_96 && ! V_5 -> V_69 . V_70 ) {
V_5 -> V_69 . V_70 = true ;
if ( ! V_5 -> V_69 . V_71 )
F_35 ( V_5 , true ) ;
}
break;
case V_112 :
if ( ! V_23 . V_96 && V_5 -> V_69 . V_71 ) {
V_5 -> V_69 . V_71 = false ;
}
else if ( V_23 . V_96 && ! V_5 -> V_69 . V_71 ) {
V_5 -> V_69 . V_71 = true ;
if ( ! V_5 -> V_69 . V_70 )
F_35 ( V_5 , true ) ;
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
static void F_43 ( struct V_88 * V_89 )
{
struct V_1 * V_5 = F_40 ( V_89 ) ;
F_44 ( V_113 , NULL ,
& V_5 -> V_68 , F_41 ) ;
}
static int F_45 ( struct V_114 * V_115 )
{
struct V_1 * V_5 = F_46 ( V_115 ) ;
F_35 ( V_5 , true ) ;
return 0 ;
}
static int F_47 ( struct V_114 * V_115 ,
T_3 V_116 )
{
struct V_1 * V_5 = F_46 ( V_115 ) ;
F_35 ( V_5 , false ) ;
return 0 ;
}
static int F_48 ( struct V_114 * V_115 )
{
struct V_1 * V_5 = F_46 ( V_115 ) ;
int V_37 , V_76 ;
for ( V_37 = 0 ; V_37 < F_49 ( V_117 ) ; V_37 ++ ) {
V_76 = F_50 ( V_115 , V_117 [ V_37 ] . V_98 ) ;
F_51 ( V_76 , V_5 ) ;
}
F_52 ( V_5 -> V_74 ) ;
F_53 () ;
F_54 ( & V_5 -> V_68 ) ;
F_55 ( V_115 , NULL ) ;
return 0 ;
}
static int F_56 ( struct V_114 * V_115 )
{
struct V_118 * V_119 = V_115 -> V_19 . V_120 ;
struct V_1 * V_5 ;
int V_76 , V_37 , V_23 = 0 ;
T_1 V_93 ;
V_5 = F_57 ( & V_115 -> V_19 , sizeof( * V_5 ) , V_121 ) ;
if ( ! V_5 ) {
F_7 ( & V_115 -> V_19 , L_35 , V_20 ) ;
return - V_122 ;
}
V_5 -> V_10 = V_115 -> V_123 -> V_124 ;
if ( ! V_5 -> V_10 ) {
if ( V_119 ) {
V_23 = F_58 ( & V_115 -> V_19 , V_119 , & V_5 -> V_10 ) ;
if ( V_23 ) {
F_7 ( & V_115 -> V_19 ,
L_36 ) ;
return V_23 ;
}
} else {
F_7 ( & V_115 -> V_19 , L_37 ) ;
return - V_39 ;
}
} else {
F_59 ( & V_115 -> V_19 , L_38 ) ;
}
V_5 -> V_19 = & V_115 -> V_19 ;
V_5 -> V_9 = F_42 ( V_115 -> V_19 . V_9 ) ;
V_5 -> V_17 = F_60 ( L_39 ) ;
V_5 -> V_68 . V_98 = L_40 ;
V_5 -> V_68 . type = V_125 ;
V_5 -> V_68 . V_109 = V_126 ;
V_5 -> V_68 . V_107 = F_49 ( V_126 ) ;
V_5 -> V_68 . V_110 = F_39 ;
V_5 -> V_68 . V_106 = V_127 ;
V_5 -> V_68 . V_105 = F_49 ( V_127 ) ;
V_5 -> V_68 . V_128 =
F_43 ;
V_5 -> V_74 =
F_61 ( L_41 ) ;
if ( V_5 -> V_74 == NULL ) {
F_7 ( V_5 -> V_19 , L_42 ) ;
return - V_122 ;
}
F_62 ( & V_5 -> V_65 ,
F_23 ) ;
if ( F_21 ( V_5 ) < 0 )
F_22 ( V_5 -> V_19 , L_43 ) ;
V_5 -> V_84 . V_85 = V_51 ;
V_5 -> V_84 . V_87 = V_129 ;
V_23 = F_63 ( V_5 -> V_19 , V_27 ,
V_130 , & V_93 ) ;
if ( V_23 < 0 ) {
F_7 ( V_5 -> V_19 , L_44 , V_20 ) ;
goto V_131;
}
switch ( V_93 ) {
case V_132 :
case V_133 :
V_5 -> V_84 . V_86 =
V_134 ;
break;
case V_135 :
V_5 -> V_84 . V_86 =
V_136 ;
break;
case V_137 :
V_5 -> V_84 . V_86 =
V_138 ;
break;
}
V_23 = F_64 ( V_5 -> V_19 , & V_5 -> V_68 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_45 ) ;
goto V_131;
}
for ( V_37 = 0 ; V_37 < F_49 ( V_117 ) ; V_37 ++ ) {
V_76 = F_50 ( V_115 , V_117 [ V_37 ] . V_98 ) ;
V_23 = F_65 ( V_76 , NULL , V_117 [ V_37 ] . V_139 ,
V_140 | V_141 ,
V_117 [ V_37 ] . V_98 , V_5 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_46
, V_117 [ V_37 ] . V_98 , V_76 , V_23 ) ;
goto F_51;
}
F_9 ( V_5 -> V_19 , L_47 ,
V_117 [ V_37 ] . V_98 , V_76 , V_23 ) ;
}
F_55 ( V_115 , V_5 ) ;
F_35 ( V_5 , true ) ;
F_66 ( & V_5 -> V_4 , & V_3 ) ;
return V_23 ;
F_51:
F_54 ( & V_5 -> V_68 ) ;
for ( V_37 = V_37 - 1 ; V_37 >= 0 ; V_37 -- ) {
V_76 = F_50 ( V_115 , V_117 [ V_37 ] . V_98 ) ;
F_51 ( V_76 , V_5 ) ;
}
V_131:
F_52 ( V_5 -> V_74 ) ;
return V_23 ;
}
static int T_4 F_67 ( void )
{
return F_68 ( & V_142 ) ;
}
static void T_5 F_69 ( void )
{
F_70 ( & V_142 ) ;
}
