static inline void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
char * V_5 = L_1 ;
switch ( V_4 ) {
case - V_6 :
V_5 = L_2 ;
break;
case - V_7 :
V_5 = L_3 ;
break;
case - V_8 :
V_5 = L_4 ;
break;
case - V_9 :
V_5 = L_5 ;
break;
case - V_10 :
V_5 = L_6 ;
break;
case - V_11 :
V_5 = L_7 ;
break;
case - V_12 :
V_5 = L_8 ;
break;
case - V_13 :
V_5 = L_9 ;
break;
}
if ( V_3 < 0 ) {
F_2 ( 1 , L_10 , V_4 , V_5 ) ;
} else {
F_2 ( 1 , L_11 ,
V_3 , V_4 , V_5 ) ;
}
}
static inline int F_3 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
int V_15 ;
if ( ! V_2 )
return 0 ;
if ( ( V_2 -> V_16 & V_17 ) || ( V_2 -> V_16 & V_18 ) )
return 0 ;
if ( V_14 -> V_4 < 0 ) {
F_1 ( V_2 , - 1 , V_14 -> V_4 ) ;
if ( V_14 -> V_4 == - V_6 )
return 0 ;
}
for ( V_15 = 0 ; V_15 < V_14 -> V_19 ; V_15 ++ ) {
int V_4 = V_14 -> V_20 [ V_15 ] . V_4 ;
if ( V_4 < 0 ) {
F_1 ( V_2 , V_15 , V_4 ) ;
if ( V_14 -> V_20 [ V_15 ] . V_4 != - V_11 )
continue;
}
F_4 ( & V_2 -> V_21 -> V_22 ,
V_14 -> V_23 +
V_14 -> V_20 [ V_15 ] . V_24 ,
V_14 -> V_20 [ V_15 ] . V_25 ) ;
}
return 0 ;
}
static inline int F_5 ( struct V_1 * V_2 , struct V_14 * V_14 )
{
if ( ! V_2 )
return 0 ;
if ( ( V_2 -> V_16 & V_17 ) || ( V_2 -> V_16 & V_18 ) )
return 0 ;
if ( V_14 -> V_4 < 0 ) {
F_1 ( V_2 , - 1 , V_14 -> V_4 ) ;
if ( V_14 -> V_4 == - V_6 )
return 0 ;
}
F_4 ( & V_2 -> V_21 -> V_22 ,
V_14 -> V_23 , V_14 -> V_25 ) ;
return 0 ;
}
static int F_6 ( struct V_26 * V_21 )
{
int V_27 ;
struct V_1 * V_2 = V_21 -> V_28 . V_29 ;
if ( V_2 -> V_30 ) {
F_7 ( L_12 ) ;
F_8 ( & V_2 -> V_31 ) ;
F_9 ( V_2 , false ) ;
F_10 ( V_2 , V_32 , 4 ) ;
F_9 ( V_2 , true ) ;
F_11 ( & V_2 -> V_31 ) ;
V_27 = F_12 ( V_2 , V_33 ) ;
if ( V_27 < 0 )
return V_27 ;
V_2 -> V_34 = 1 ;
return F_13 ( V_2 , V_35 ,
V_36 ,
V_2 -> V_37 . V_38 ,
F_3 ) ;
} else {
F_7 ( L_13 ) ;
F_10 ( V_2 , V_32 , 0 ) ;
V_27 = F_12 ( V_2 , V_33 ) ;
if ( V_27 < 0 )
return V_27 ;
V_2 -> V_34 = 1 ;
return F_14 ( V_2 , V_35 ,
V_36 ,
V_2 -> V_37 . V_38 ,
F_5 ) ;
}
}
static int F_15 ( struct V_26 * V_21 )
{
struct V_1 * V_2 = V_21 -> V_28 . V_29 ;
if ( V_2 -> V_30 )
F_16 ( V_2 ) ;
else
F_17 ( V_2 ) ;
F_12 ( V_2 , V_39 ) ;
return 0 ;
}
static int F_18 ( struct V_40 * V_41 )
{
struct V_42 * V_22 = V_41 -> V_22 ;
struct V_26 * V_21 = V_22 -> V_29 ;
int V_27 , V_43 ;
if ( ! V_22 -> V_44 . V_45 )
return - V_46 ;
F_8 ( & V_21 -> V_47 ) ;
V_21 -> V_48 ++ ;
V_27 = V_21 -> V_48 ;
if ( V_21 -> V_48 == 1 ) {
V_43 = F_6 ( V_21 ) ;
if ( V_43 < 0 )
V_27 = V_43 ;
}
F_11 ( & V_21 -> V_47 ) ;
return V_27 ;
}
static int F_19 ( struct V_40 * V_41 )
{
struct V_42 * V_22 = V_41 -> V_22 ;
struct V_26 * V_21 = V_22 -> V_29 ;
int V_49 = 0 ;
F_8 ( & V_21 -> V_47 ) ;
V_21 -> V_48 -- ;
if ( 0 == V_21 -> V_48 )
V_49 = F_15 ( V_21 ) ;
F_11 ( & V_21 -> V_47 ) ;
return V_49 ;
}
static int F_20 ( struct V_50 * V_51 , int V_52 )
{
struct V_1 * V_2 = V_51 -> V_21 -> V_29 ;
if ( V_52 )
return F_12 ( V_2 , V_33 ) ;
else
return F_12 ( V_2 , V_39 ) ;
}
int F_21 ( struct V_1 * V_2 , T_1 V_53 )
{
int V_4 = 0 ;
if ( ( V_2 -> V_21 != NULL ) && ( V_2 -> V_21 -> V_45 != NULL ) ) {
struct V_54 * V_55 = & V_2 -> V_21 -> V_45 -> V_56 . V_57 ;
if ( V_55 -> V_58 != NULL ) {
struct V_59 V_60 ;
V_60 . V_61 = V_53 ;
V_60 . V_62 = V_2 -> V_63 ;
V_60 . V_64 = 0 ;
V_55 -> V_58 ( V_2 -> V_21 -> V_45 , & V_60 ) ;
}
}
return V_4 ;
}
int F_22 ( struct V_1 * V_2 )
{
int V_4 = 0 ;
if ( ( V_2 -> V_21 != NULL ) && ( V_2 -> V_21 -> V_45 != NULL ) ) {
struct V_54 * V_55 = & V_2 -> V_21 -> V_45 -> V_56 . V_57 ;
if ( V_55 -> V_65 != NULL && ! V_2 -> V_66 ) {
F_7 ( L_14 ) ;
V_4 = V_55 -> V_65 ( V_2 -> V_21 -> V_45 ) ;
if ( V_4 == 0 ) {
V_2 -> V_66 = 1 ;
F_7
( L_15 ) ;
} else {
V_2 -> V_66 = 0 ;
F_7
( L_16 ) ;
}
}
}
return V_4 ;
}
static int F_23 ( struct V_26 * V_21 ,
struct V_67 * V_67 ,
struct V_1 * V_2 , struct V_68 * V_68 )
{
int V_69 ;
F_24 ( & V_21 -> V_47 ) ;
V_69 = F_25 ( & V_21 -> V_28 , V_2 -> V_70 , V_67 , V_68 ,
V_71 ) ;
if ( V_69 < 0 ) {
F_26 ( V_72
L_17 ,
V_2 -> V_70 , V_69 ) ;
goto V_73;
}
V_21 -> V_45 -> V_56 . V_74 = F_20 ;
V_21 -> V_28 . V_29 = V_2 ;
V_69 = F_27 ( & V_21 -> V_28 , V_21 -> V_45 ) ;
if ( V_69 < 0 ) {
F_26 ( V_72
L_18 ,
V_2 -> V_70 , V_69 ) ;
goto V_75;
}
V_21 -> V_22 . V_44 . V_76 =
V_77 | V_78 |
V_79 ;
V_21 -> V_22 . V_29 = V_21 ;
V_21 -> V_22 . V_80 = 256 ;
V_21 -> V_22 . V_81 = 256 ;
V_21 -> V_22 . F_18 = F_18 ;
V_21 -> V_22 . F_19 = F_19 ;
V_69 = F_28 ( & V_21 -> V_22 ) ;
if ( V_69 < 0 ) {
F_26 ( V_72 L_19 ,
V_2 -> V_70 , V_69 ) ;
goto V_82;
}
V_21 -> V_83 . V_80 = 256 ;
V_21 -> V_83 . V_22 = & V_21 -> V_22 . V_44 ;
V_21 -> V_83 . V_76 = 0 ;
V_69 = F_29 ( & V_21 -> V_83 , & V_21 -> V_28 ) ;
if ( V_69 < 0 ) {
F_26 ( V_72 L_20 ,
V_2 -> V_70 , V_69 ) ;
goto V_84;
}
V_21 -> V_85 . V_86 = V_87 ;
V_69 = V_21 -> V_22 . V_44 . V_88 ( & V_21 -> V_22 . V_44 , & V_21 -> V_85 ) ;
if ( V_69 < 0 ) {
F_26 ( V_72
L_21 ,
V_2 -> V_70 , V_69 ) ;
goto V_89;
}
V_21 -> V_90 . V_86 = V_91 ;
V_69 = V_21 -> V_22 . V_44 . V_88 ( & V_21 -> V_22 . V_44 , & V_21 -> V_90 ) ;
if ( V_69 < 0 ) {
F_26 ( V_72
L_22 ,
V_2 -> V_70 , V_69 ) ;
goto V_92;
}
V_69 = V_21 -> V_22 . V_44 . V_93 ( & V_21 -> V_22 . V_44 , & V_21 -> V_85 ) ;
if ( V_69 < 0 ) {
F_26 ( V_72
L_23 , V_2 -> V_70 ,
V_69 ) ;
goto V_94;
}
F_30 ( & V_21 -> V_28 , & V_21 -> V_95 , & V_21 -> V_22 . V_44 ) ;
return 0 ;
V_94:
V_21 -> V_22 . V_44 . V_96 ( & V_21 -> V_22 . V_44 , & V_21 -> V_90 ) ;
V_92:
V_21 -> V_22 . V_44 . V_96 ( & V_21 -> V_22 . V_44 , & V_21 -> V_85 ) ;
V_89:
F_31 ( & V_21 -> V_83 ) ;
V_84:
F_32 ( & V_21 -> V_22 ) ;
V_82:
F_33 ( V_21 -> V_45 ) ;
V_75:
F_34 ( V_21 -> V_45 ) ;
F_35 ( & V_21 -> V_28 ) ;
V_73:
return V_69 ;
}
static void F_36 ( struct V_26 * V_21 )
{
F_37 ( & V_21 -> V_95 ) ;
V_21 -> V_22 . V_44 . V_96 ( & V_21 -> V_22 . V_44 , & V_21 -> V_90 ) ;
V_21 -> V_22 . V_44 . V_96 ( & V_21 -> V_22 . V_44 , & V_21 -> V_85 ) ;
F_31 ( & V_21 -> V_83 ) ;
F_32 ( & V_21 -> V_22 ) ;
F_33 ( V_21 -> V_45 ) ;
F_34 ( V_21 -> V_45 ) ;
F_35 ( & V_21 -> V_28 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_69 = 0 ;
struct V_26 * V_21 ;
if ( ! V_2 -> V_97 . V_98 ) {
return 0 ;
}
V_21 = F_39 ( sizeof( struct V_26 ) , V_99 ) ;
if ( V_21 == NULL ) {
F_26 ( V_100 L_24 ) ;
return - V_101 ;
}
V_2 -> V_21 = V_21 ;
V_2 -> F_21 = F_21 ;
V_2 -> F_22 = F_22 ;
F_8 ( & V_2 -> V_47 ) ;
F_12 ( V_2 , V_33 ) ;
F_40 ( V_2 ) ;
switch ( V_2 -> V_102 ) {
case V_103 :
case V_104 :
V_2 -> V_21 -> V_45 = F_41 ( V_105 ,
& V_106 ,
& V_2 -> V_107 [ V_2 -> V_97 . V_108 ] . V_109 ) ;
if ( V_2 -> V_21 -> V_45 == NULL ) {
F_26 ( V_110
L_25 ) ;
V_69 = - V_46 ;
goto V_111;
}
V_21 -> V_45 -> V_112 = V_113 ;
if ( ! F_41 ( V_114 , V_2 -> V_21 -> V_45 ,
& V_2 -> V_107 [ V_2 -> V_97 . V_115 ] . V_109 ,
& V_116 ) ) {
V_69 = - V_46 ;
goto V_111;
}
break;
case V_117 :
case V_118 :
V_2 -> V_21 -> V_45 = F_41 ( V_119 ,
& V_120 ,
& V_2 -> V_107 [ V_2 -> V_97 . V_108 ] . V_109 ) ;
if ( V_2 -> V_21 -> V_45 == NULL ) {
F_26 ( V_110
L_26 ) ;
V_69 = - V_46 ;
goto V_111;
}
V_21 -> V_45 -> V_112 = V_113 ;
if ( ! F_41 ( V_114 , V_2 -> V_21 -> V_45 ,
& V_2 -> V_107 [ V_2 -> V_97 . V_115 ] . V_109 ,
& V_121 ) ) {
V_69 = - V_46 ;
goto V_111;
}
break;
case V_122 :
V_2 -> V_21 -> V_45 = F_41 ( V_105 ,
& V_106 ,
& V_2 -> V_107 [ V_2 -> V_97 . V_108 ] . V_109 ) ;
if ( V_2 -> V_21 -> V_45 == NULL ) {
F_26 ( V_110
L_25 ) ;
V_69 = - V_46 ;
goto V_111;
}
V_21 -> V_45 -> V_112 = V_113 ;
if ( ! F_41 ( V_123 , V_2 -> V_21 -> V_45 ,
0x60 , & V_2 -> V_107 [ V_2 -> V_97 . V_115 ] . V_109 ,
& V_124 ) ) {
V_69 = - V_46 ;
goto V_111;
}
break;
case V_125 :
V_2 -> V_21 -> V_45 = F_41 ( V_119 ,
& V_126 ,
& V_2 -> V_107 [ V_2 -> V_97 . V_108 ] . V_109 ) ;
if ( V_2 -> V_21 -> V_45 == NULL ) {
F_26 ( V_110
L_26 ) ;
V_69 = - V_46 ;
goto V_111;
}
V_21 -> V_45 -> V_112 = V_113 ;
if ( ! F_41 ( V_123 , V_2 -> V_21 -> V_45 ,
0x60 , & V_2 -> V_107 [ V_2 -> V_97 . V_115 ] . V_109 ,
& V_124 ) ) {
V_69 = - V_46 ;
goto V_111;
}
break;
case V_127 :
F_26 ( V_100 L_27 ,
V_128 , F_42 ( & V_2 -> V_107 [ V_2 -> V_97 . V_115 ] . V_109 ) ) ;
V_2 -> V_21 -> V_45 = F_41 ( V_129 ,
& V_130 ,
& V_2 -> V_107 [ V_2 -> V_97 . V_115 ] . V_109 ) ;
if ( V_2 -> V_21 -> V_45 == NULL ) {
F_26 ( V_110
L_28 ) ;
V_69 = - V_46 ;
goto V_111;
}
V_21 -> V_45 -> V_112 = V_113 ;
F_41 ( V_123 , V_2 -> V_21 -> V_45 ,
0x60 , & V_2 -> V_107 [ V_2 -> V_97 . V_115 ] . V_109 ,
& V_131 ) ;
break;
case V_132 :
case V_133 :
F_26 ( V_100 L_29 ,
V_128 , F_42 ( & V_2 -> V_107 [ V_2 -> V_97 . V_115 ] . V_109 ) ) ;
V_2 -> V_21 -> V_45 = F_41 ( V_134 ,
& V_135 ,
& V_2 -> V_107 [ V_2 -> V_97 . V_108 ] . V_109 ) ;
if ( V_2 -> V_21 -> V_45 == NULL ) {
F_26 ( V_110
L_30 ) ;
V_69 = - V_46 ;
goto V_111;
}
V_21 -> V_45 -> V_112 = V_113 ;
F_41 ( V_123 , V_2 -> V_21 -> V_45 ,
0x60 , & V_2 -> V_107 [ V_2 -> V_97 . V_115 ] . V_109 ,
& V_136 ) ;
break;
default:
F_26 ( V_137 L_31
L_32 , V_2 -> V_70 ) ;
break;
}
if ( NULL == V_21 -> V_45 ) {
F_26 ( V_137
L_33 , V_2 -> V_70 ) ;
V_69 = - V_46 ;
goto V_111;
}
V_69 = F_23 ( V_21 , V_138 , V_2 , & V_2 -> V_139 -> V_2 ) ;
if ( V_69 < 0 )
goto V_111;
F_26 ( V_100 L_34 ) ;
V_43:
F_12 ( V_2 , V_39 ) ;
F_11 ( & V_2 -> V_47 ) ;
return V_69 ;
V_111:
F_43 ( V_21 ) ;
V_2 -> V_21 = NULL ;
goto V_43;
}
static int F_44 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_97 . V_98 ) {
return 0 ;
}
if ( V_2 -> V_21 ) {
F_36 ( V_2 -> V_21 ) ;
V_2 -> V_21 = NULL ;
}
return 0 ;
}
static int T_2 F_45 ( void )
{
return F_46 ( & V_140 ) ;
}
static void T_3 F_47 ( void )
{
F_48 ( & V_140 ) ;
}
