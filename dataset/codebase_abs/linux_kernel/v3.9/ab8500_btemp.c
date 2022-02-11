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
if ( F_9 ( V_5 -> V_9 ) || F_10 ( V_5 -> V_9 ) ) {
if ( V_5 -> V_14 == V_24 )
V_22 = V_25 ;
else
V_22 = V_26 ;
} else {
if ( V_5 -> V_14 == V_27 )
V_22 = V_28 ;
else
V_22 = V_29 ;
}
F_11 ( V_5 -> V_19 , L_2 , V_5 -> V_14 ) ;
V_23 = F_12 ( V_5 -> V_19 ,
V_30 , V_31 ,
V_32 , V_32 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_3 ,
V_20 ) ;
return V_23 ;
}
F_13 ( 32 ) ;
V_23 = F_14 ( V_5 -> V_19 ,
V_30 , V_31 ,
V_32 | V_22 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_4 ,
V_20 ) ;
goto V_33;
}
} else if ( V_5 -> V_10 -> V_11 == V_12 && ! V_21 ) {
F_11 ( V_5 -> V_19 , L_5 ) ;
if ( F_9 ( V_5 -> V_9 ) || F_10 ( V_5 -> V_9 ) ) {
V_23 = F_12 (
V_5 -> V_19 ,
V_30 , V_31 ,
V_25 | V_26 ,
~ ( V_25 | V_26 ) ) ;
} else {
V_23 = F_12 (
V_5 -> V_19 ,
V_30 , V_31 ,
V_28 | V_29 ,
~ ( V_28 | V_29 ) ) ;
}
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_6 ,
V_20 ) ;
goto V_33;
}
V_23 = F_12 ( V_5 -> V_19 ,
V_30 , V_31 ,
V_34 | V_35 ,
V_34 | V_35 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_7 ,
V_20 ) ;
goto V_36;
}
F_13 ( 32 ) ;
V_23 = F_12 ( V_5 -> V_19 ,
V_30 , V_31 ,
V_32 , ~ V_32 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_8 ,
V_20 ) ;
goto V_37;
}
}
return V_23 ;
V_33:
if ( F_9 ( V_5 -> V_9 ) || F_10 ( V_5 -> V_9 ) ) {
V_23 = F_12 ( V_5 -> V_19 ,
V_30 , V_31 ,
V_25 | V_26 ,
~ ( V_25 | V_26 ) ) ;
} else {
V_23 = F_12 ( V_5 -> V_19 ,
V_30 , V_31 ,
V_28 | V_29 ,
~ ( V_28 | V_29 ) ) ;
}
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_6 ,
V_20 ) ;
return V_23 ;
}
V_36:
V_23 = F_12 ( V_5 -> V_19 ,
V_30 , V_31 ,
V_34 | V_35 ,
V_34 | V_35 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_7 ,
V_20 ) ;
return V_23 ;
}
V_37:
F_13 ( 32 ) ;
V_23 = F_12 ( V_5 -> V_19 ,
V_30 , V_31 ,
V_32 , ~ V_32 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_8 ,
V_20 ) ;
return V_23 ;
}
return V_23 ;
}
static int F_15 ( struct V_1 * V_5 )
{
int V_23 ;
int V_38 = 0 ;
int V_39 ;
int V_7 ;
int V_40 ;
V_23 = F_8 ( V_5 , true ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_9 , V_20 ) ;
return V_23 ;
}
if ( ! V_5 -> V_41 )
V_5 -> V_41 = F_16 () ;
if ( ! V_5 -> V_41 ) {
F_7 ( V_5 -> V_19 , L_10 ) ;
return - V_42 ;
}
V_23 = F_17 ( V_5 -> V_41 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_11 ) ;
return V_23 ;
}
do {
F_18 ( 20 ) ;
} while ( ! F_19 ( V_5 -> V_41 ) );
V_40 = 0 ;
do {
V_38 += F_5 ( V_5 ) ;
V_40 ++ ;
F_18 ( 20 ) ;
} while ( ! F_20 ( V_5 -> V_41 ) );
V_38 /= V_40 ;
V_23 = F_21 ( V_5 -> V_41 , & V_7 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_12 ) ;
return V_23 ;
}
V_39 = F_3 ( V_5 , V_38 , V_7 ) ;
V_23 = F_8 ( V_5 , false ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_13 , V_20 ) ;
return V_23 ;
}
F_11 ( V_5 -> V_19 , L_14 ,
V_20 , V_38 , V_39 , V_7 , V_40 ) ;
return V_39 ;
}
static int F_22 ( struct V_1 * V_5 ,
const struct V_43 * V_44 , int V_45 , int V_39 )
{
int V_40 , V_46 ;
if ( V_39 > V_44 [ 0 ] . V_47 )
V_40 = 0 ;
else if ( V_39 <= V_44 [ V_45 - 1 ] . V_47 )
V_40 = V_45 - 2 ;
else {
V_40 = 0 ;
while ( ! ( V_39 <= V_44 [ V_40 ] . V_47 &&
V_39 > V_44 [ V_40 + 1 ] . V_47 ) )
V_40 ++ ;
}
V_46 = V_44 [ V_40 ] . V_46 + ( ( V_44 [ V_40 + 1 ] . V_46 - V_44 [ V_40 ] . V_46 ) *
( V_39 - V_44 [ V_40 ] . V_47 ) ) / ( V_44 [ V_40 + 1 ] . V_47 - V_44 [ V_40 ] . V_47 ) ;
return V_46 ;
}
static int F_23 ( struct V_1 * V_5 )
{
int V_46 ;
static int V_16 ;
int V_48 , V_49 , V_50 ;
T_1 V_51 ;
V_51 = V_5 -> V_10 -> V_52 ;
if ( V_5 -> V_10 -> V_11 == V_12 &&
V_51 != V_53 ) {
V_48 = F_15 ( V_5 ) ;
if ( V_48 < 0 ) {
F_7 ( V_5 -> V_19 , L_15 ,
V_20 ) ;
return V_54 ;
}
V_46 = F_22 ( V_5 ,
V_5 -> V_10 -> V_55 [ V_51 ] . V_56 ,
V_5 -> V_10 -> V_55 [ V_51 ] . V_57 , V_48 ) ;
} else {
V_50 = F_6 ( V_5 -> V_17 , V_58 ) ;
if ( V_50 < 0 ) {
F_7 ( V_5 -> V_19 ,
L_16
L_17 , V_20 ) ;
return V_16 ;
}
V_49 = 230000 * V_50 / ( V_59 - V_50 ) ;
V_46 = F_22 ( V_5 ,
V_5 -> V_10 -> V_55 [ V_51 ] . V_56 ,
V_5 -> V_10 -> V_55 [ V_51 ] . V_57 , V_49 ) ;
V_16 = V_46 ;
}
F_11 ( V_5 -> V_19 , L_18 , V_46 ) ;
return V_46 ;
}
static int F_24 ( struct V_1 * V_5 )
{
int V_39 ;
T_1 V_40 ;
if ( F_9 ( V_5 -> V_9 ) || F_10 ( V_5 -> V_9 ) )
V_5 -> V_14 = V_24 ;
else
V_5 -> V_14 = V_27 ;
V_5 -> V_10 -> V_52 = V_53 ;
V_39 = F_15 ( V_5 ) ;
if ( V_39 < 0 ) {
F_7 ( V_5 -> V_19 , L_15 , V_20 ) ;
return - V_60 ;
}
for ( V_40 = V_53 + 1 ; V_40 < V_5 -> V_10 -> V_61 ; V_40 ++ ) {
if ( ( V_39 <= V_5 -> V_10 -> V_55 [ V_40 ] . V_62 ) &&
( V_39 >= V_5 -> V_10 -> V_55 [ V_40 ] . V_63 ) ) {
F_11 ( V_5 -> V_19 , L_19
L_20
L_21 ,
V_5 -> V_10 -> V_11 == V_12 ?
L_22 : L_23 ,
V_5 -> V_10 -> V_55 [ V_40 ] . V_63 , V_39 ,
V_5 -> V_10 -> V_55 [ V_40 ] . V_62 , V_40 ) ;
V_5 -> V_10 -> V_52 = V_40 ;
break;
}
}
if ( V_5 -> V_10 -> V_52 == V_53 ) {
F_25 ( V_5 -> V_19 , L_24
L_25 , V_39 ) ;
return - V_60 ;
}
if ( V_5 -> V_10 -> V_11 == V_12 &&
V_5 -> V_10 -> V_52 == 1 ) {
if ( F_9 ( V_5 -> V_9 ) || F_10 ( V_5 -> V_9 ) ) {
F_11 ( V_5 -> V_19 , L_26 ) ;
V_5 -> V_14 = V_24 ;
} else {
F_11 ( V_5 -> V_19 , L_27 ) ;
V_5 -> V_14 = V_64 ;
}
}
return V_5 -> V_10 -> V_52 ;
}
static void F_26 ( struct V_65 * V_66 )
{
int V_67 ;
struct V_1 * V_5 = F_27 ( V_66 ,
struct V_1 , V_68 . V_66 ) ;
if ( ! V_5 -> V_69 ) {
V_5 -> V_69 = true ;
if ( F_24 ( V_5 ) < 0 )
F_25 ( V_5 -> V_19 , L_28 ) ;
}
V_5 -> V_70 = F_23 ( V_5 ) ;
if ( V_5 -> V_70 != V_5 -> V_71 ) {
V_5 -> V_71 = V_5 -> V_70 ;
F_28 ( & V_5 -> V_72 ) ;
}
if ( V_5 -> V_73 . V_74 || V_5 -> V_73 . V_75 )
V_67 = V_5 -> V_10 -> V_76 ;
else
V_67 = V_5 -> V_10 -> V_77 ;
F_29 ( V_5 -> V_78 ,
& V_5 -> V_68 ,
F_30 ( V_67 * V_79 ) ) ;
}
static T_2 F_31 ( int V_80 , void * V_81 )
{
struct V_1 * V_5 = V_81 ;
F_7 ( V_5 -> V_19 , L_29 ) ;
V_5 -> V_73 . V_82 = true ;
F_28 ( & V_5 -> V_72 ) ;
return V_83 ;
}
static T_2 F_32 ( int V_80 , void * V_81 )
{
struct V_1 * V_5 = V_81 ;
if ( F_33 ( V_5 -> V_9 ) ) {
F_11 ( V_5 -> V_19 , L_30
L_31 ) ;
} else {
F_34 ( V_5 -> V_19 , L_32 ) ;
V_5 -> V_73 . V_84 = true ;
V_5 -> V_73 . V_85 = false ;
V_5 -> V_73 . V_86 = false ;
V_5 -> V_73 . V_87 = false ;
F_28 ( & V_5 -> V_72 ) ;
}
return V_83 ;
}
static T_2 F_35 ( int V_80 , void * V_81 )
{
struct V_1 * V_5 = V_81 ;
F_34 ( V_5 -> V_19 , L_33 ) ;
V_5 -> V_73 . V_85 = true ;
V_5 -> V_73 . V_86 = false ;
V_5 -> V_73 . V_87 = false ;
V_5 -> V_73 . V_84 = false ;
F_28 ( & V_5 -> V_72 ) ;
return V_83 ;
}
static T_2 F_36 ( int V_80 , void * V_81 )
{
struct V_1 * V_5 = V_81 ;
F_11 ( V_5 -> V_19 , L_34 ) ;
V_5 -> V_73 . V_87 = true ;
V_5 -> V_73 . V_86 = false ;
V_5 -> V_73 . V_85 = false ;
V_5 -> V_73 . V_84 = false ;
F_28 ( & V_5 -> V_72 ) ;
return V_83 ;
}
static T_2 F_37 ( int V_80 , void * V_81 )
{
struct V_1 * V_5 = V_81 ;
F_11 ( V_5 -> V_19 , L_35 ) ;
V_5 -> V_73 . V_86 = true ;
V_5 -> V_73 . V_87 = false ;
V_5 -> V_73 . V_85 = false ;
V_5 -> V_73 . V_84 = false ;
F_28 ( & V_5 -> V_72 ) ;
return V_83 ;
}
static void F_38 ( struct V_1 * V_5 ,
bool V_21 )
{
F_11 ( V_5 -> V_19 , L_36 ,
V_21 ) ;
F_39 ( & V_5 -> V_68 ) ;
if ( V_21 )
F_29 ( V_5 -> V_78 , & V_5 -> V_68 , 0 ) ;
}
static int F_40 ( struct V_1 * V_5 )
{
int V_46 = 0 ;
if ( F_33 ( V_5 -> V_9 ) ) {
V_46 = V_5 -> V_70 * 10 ;
} else {
if ( V_5 -> V_73 . V_84 ) {
if ( V_46 > V_5 -> V_88 . V_89 )
V_46 = V_5 -> V_88 . V_89 * 10 ;
else
V_46 = V_5 -> V_70 * 10 ;
} else if ( V_5 -> V_73 . V_85 ) {
if ( V_46 < V_5 -> V_88 . V_90 )
V_46 = V_5 -> V_88 . V_90 * 10 ;
else
V_46 = V_5 -> V_70 * 10 ;
} else if ( V_5 -> V_73 . V_87 ) {
if ( V_46 > V_5 -> V_88 . V_91 )
V_46 = V_5 -> V_88 . V_91 * 10 ;
else
V_46 = V_5 -> V_70 * 10 ;
} else if ( V_5 -> V_73 . V_86 ) {
if ( V_46 < V_5 -> V_88 . V_91 )
V_46 = V_5 -> V_88 . V_91 * 10 ;
else
V_46 = V_5 -> V_70 * 10 ;
} else
V_46 = V_5 -> V_70 * 10 ;
}
return V_46 ;
}
int F_41 ( struct V_1 * V_2 )
{
return V_2 -> V_70 * 1000 ;
}
static int F_42 ( struct V_92 * V_93 ,
enum V_94 V_95 ,
union V_96 * V_97 )
{
struct V_1 * V_5 ;
V_5 = F_43 ( V_93 ) ;
switch ( V_95 ) {
case V_98 :
case V_99 :
if ( V_5 -> V_73 . V_82 )
V_97 -> V_100 = 0 ;
else
V_97 -> V_100 = 1 ;
break;
case V_101 :
V_97 -> V_100 = V_5 -> V_10 -> V_55 [ V_5 -> V_10 -> V_52 ] . V_102 ;
break;
case V_103 :
V_97 -> V_100 = F_40 ( V_5 ) ;
break;
default:
return - V_42 ;
}
return 0 ;
}
static int F_44 ( struct V_104 * V_19 , void * V_105 )
{
struct V_92 * V_93 ;
struct V_92 * V_106 ;
struct V_1 * V_5 ;
union V_96 V_23 ;
int V_40 , V_107 ;
bool V_108 = false ;
V_93 = (struct V_92 * ) V_105 ;
V_106 = F_45 ( V_19 ) ;
V_5 = F_43 ( V_93 ) ;
for ( V_40 = 0 ; V_40 < V_106 -> V_109 ; V_40 ++ ) {
if ( ! strcmp ( V_106 -> V_110 [ V_40 ] , V_93 -> V_102 ) )
V_108 = true ;
}
if ( ! V_108 )
return 0 ;
for ( V_107 = 0 ; V_107 < V_106 -> V_111 ; V_107 ++ ) {
enum V_94 V_112 ;
V_112 = V_106 -> V_113 [ V_107 ] ;
if ( V_106 -> V_114 ( V_106 , V_112 , & V_23 ) )
continue;
switch ( V_112 ) {
case V_98 :
switch ( V_106 -> type ) {
case V_115 :
if ( ! V_23 . V_100 && V_5 -> V_73 . V_74 ) {
V_5 -> V_73 . V_74 = false ;
}
else if ( V_23 . V_100 && ! V_5 -> V_73 . V_74 ) {
V_5 -> V_73 . V_74 = true ;
if ( ! V_5 -> V_73 . V_75 )
F_38 ( V_5 , true ) ;
}
break;
case V_116 :
if ( ! V_23 . V_100 && V_5 -> V_73 . V_75 ) {
V_5 -> V_73 . V_75 = false ;
}
else if ( V_23 . V_100 && ! V_5 -> V_73 . V_75 ) {
V_5 -> V_73 . V_75 = true ;
if ( ! V_5 -> V_73 . V_74 )
F_38 ( V_5 , true ) ;
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
static void F_46 ( struct V_92 * V_93 )
{
struct V_1 * V_5 = F_43 ( V_93 ) ;
F_47 ( V_117 , NULL ,
& V_5 -> V_72 , F_44 ) ;
}
static int F_48 ( struct V_118 * V_119 )
{
struct V_1 * V_5 = F_49 ( V_119 ) ;
F_38 ( V_5 , true ) ;
return 0 ;
}
static int F_50 ( struct V_118 * V_119 ,
T_3 V_120 )
{
struct V_1 * V_5 = F_49 ( V_119 ) ;
F_38 ( V_5 , false ) ;
return 0 ;
}
static int F_51 ( struct V_118 * V_119 )
{
struct V_1 * V_5 = F_49 ( V_119 ) ;
int V_40 , V_80 ;
for ( V_40 = 0 ; V_40 < F_52 ( V_121 ) ; V_40 ++ ) {
V_80 = F_53 ( V_119 , V_121 [ V_40 ] . V_102 ) ;
F_54 ( V_80 , V_5 ) ;
}
F_55 ( V_5 -> V_78 ) ;
F_56 () ;
F_57 ( & V_5 -> V_72 ) ;
F_58 ( V_119 , NULL ) ;
return 0 ;
}
static int F_59 ( struct V_118 * V_119 )
{
struct V_122 * V_123 = V_119 -> V_19 . V_124 ;
struct V_125 * V_126 = V_119 -> V_19 . V_127 ;
struct V_1 * V_5 ;
int V_80 , V_40 , V_23 = 0 ;
T_1 V_97 ;
V_5 = F_60 ( & V_119 -> V_19 , sizeof( * V_5 ) , V_128 ) ;
if ( ! V_5 ) {
F_7 ( & V_119 -> V_19 , L_37 , V_20 ) ;
return - V_129 ;
}
if ( ! V_126 ) {
F_7 ( & V_119 -> V_19 , L_38 ) ;
return - V_42 ;
}
V_5 -> V_10 = V_126 ;
if ( V_123 ) {
V_23 = F_61 ( & V_119 -> V_19 , V_123 , V_5 -> V_10 ) ;
if ( V_23 ) {
F_7 ( & V_119 -> V_19 , L_39 ) ;
return V_23 ;
}
}
V_5 -> V_19 = & V_119 -> V_19 ;
V_5 -> V_9 = F_45 ( V_119 -> V_19 . V_9 ) ;
V_5 -> V_17 = F_62 ( L_40 ) ;
V_5 -> V_69 = false ;
V_5 -> V_72 . V_102 = L_41 ;
V_5 -> V_72 . type = V_130 ;
V_5 -> V_72 . V_113 = V_131 ;
V_5 -> V_72 . V_111 = F_52 ( V_131 ) ;
V_5 -> V_72 . V_114 = F_42 ;
V_5 -> V_72 . V_110 = V_132 ;
V_5 -> V_72 . V_109 = F_52 ( V_132 ) ;
V_5 -> V_72 . V_133 =
F_46 ;
V_5 -> V_78 =
F_63 ( L_42 ) ;
if ( V_5 -> V_78 == NULL ) {
F_7 ( V_5 -> V_19 , L_43 ) ;
return - V_129 ;
}
F_64 ( & V_5 -> V_68 ,
F_26 ) ;
V_5 -> V_88 . V_89 = V_54 ;
V_5 -> V_88 . V_91 = V_134 ;
V_23 = F_65 ( V_5 -> V_19 , V_30 ,
V_135 , & V_97 ) ;
if ( V_23 < 0 ) {
F_7 ( V_5 -> V_19 , L_44 , V_20 ) ;
goto V_136;
}
switch ( V_97 ) {
case V_137 :
case V_138 :
V_5 -> V_88 . V_90 =
V_139 ;
break;
case V_140 :
V_5 -> V_88 . V_90 =
V_141 ;
break;
case V_142 :
V_5 -> V_88 . V_90 =
V_143 ;
break;
}
V_23 = F_66 ( V_5 -> V_19 , & V_5 -> V_72 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_45 ) ;
goto V_136;
}
for ( V_40 = 0 ; V_40 < F_52 ( V_121 ) ; V_40 ++ ) {
V_80 = F_53 ( V_119 , V_121 [ V_40 ] . V_102 ) ;
V_23 = F_67 ( V_80 , NULL , V_121 [ V_40 ] . V_144 ,
V_145 | V_146 ,
V_121 [ V_40 ] . V_102 , V_5 ) ;
if ( V_23 ) {
F_7 ( V_5 -> V_19 , L_46
, V_121 [ V_40 ] . V_102 , V_80 , V_23 ) ;
goto F_54;
}
F_11 ( V_5 -> V_19 , L_47 ,
V_121 [ V_40 ] . V_102 , V_80 , V_23 ) ;
}
F_58 ( V_119 , V_5 ) ;
F_38 ( V_5 , true ) ;
F_68 ( & V_5 -> V_4 , & V_3 ) ;
return V_23 ;
F_54:
F_57 ( & V_5 -> V_72 ) ;
for ( V_40 = V_40 - 1 ; V_40 >= 0 ; V_40 -- ) {
V_80 = F_53 ( V_119 , V_121 [ V_40 ] . V_102 ) ;
F_54 ( V_80 , V_5 ) ;
}
V_136:
F_55 ( V_5 -> V_78 ) ;
return V_23 ;
}
static int T_4 F_69 ( void )
{
return F_70 ( & V_147 ) ;
}
static void T_5 F_71 ( void )
{
F_72 ( & V_147 ) ;
}
