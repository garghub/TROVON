static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
bool V_4 = false ;
bool V_5 = false ;
bool V_6 = false ;
bool V_7 = false ;
bool V_8 = false ;
bool V_9 = false ;
V_3 = F_2 ( V_10 ) ;
switch ( V_3 ) {
case V_11 :
F_3 ( V_2 , L_1 ) ;
V_4 = true ;
break;
case V_12 :
F_3 ( V_2 , L_2 ) ;
V_4 = true ;
break;
case V_13 :
F_3 ( V_2 , L_3 ) ;
break;
case V_14 :
F_3 ( V_2 , L_4 ) ;
break;
default:
F_4 ( V_2 , L_5 , V_3 ) ;
break;
}
if ( V_10 & V_15 ) {
if ( V_4 )
F_3 ( V_2 , L_6 ) ;
else
F_4 ( V_2 , L_7 ) ;
}
if ( V_10 & V_16 )
F_3 ( V_2 , L_8 ) ;
if ( V_10 & V_17 ) {
if ( ! V_4 )
F_3 ( V_2 , L_9 ) ;
else
F_3 ( V_2 , L_10 ) ;
}
if ( V_10 & V_18 ) {
F_3 ( V_2 , L_11 ) ;
V_6 = true ;
V_7 = true ;
}
if ( V_10 & V_19 ) {
F_3 ( V_2 , L_12 ) ;
V_6 = true ;
V_8 = true ;
}
if ( V_10 & V_20 ) {
F_3 ( V_2 , L_13 ) ;
V_9 = true ;
}
if ( V_21 && ! V_6 )
F_4 ( V_2 , L_14 ) ;
if ( V_7 && V_8 )
F_4 ( V_2 , L_15 ) ;
if ( V_6 && V_9 )
F_4 ( V_2 , L_16 ) ;
if ( V_10 & V_22 ) {
F_3 ( V_2 , L_17 ) ;
V_5 = true ;
}
if ( V_10 & V_23 ) {
if ( V_5 )
F_3 ( V_2 , L_18 ) ;
else
F_4 ( V_2 , L_19 ) ;
}
}
static inline struct V_24 * F_5 ( struct V_25 * V_26 )
{
struct V_27 * V_28 ;
F_6 (rtd, &card->rtd_list, list) {
if ( ! strncmp ( V_28 -> V_29 -> V_30 , V_31 ,
strlen ( V_31 ) ) )
return V_28 -> V_29 ;
if ( ! strncmp ( V_28 -> V_29 -> V_30 , V_32 ,
strlen ( V_32 ) ) )
return V_28 -> V_29 ;
}
return NULL ;
}
static int F_7 ( struct V_33 * V_34 ,
struct V_35 * V_36 , int V_37 )
{
struct V_38 * V_39 = V_34 -> V_39 ;
struct V_25 * V_26 = V_39 -> V_26 ;
struct V_24 * V_29 ;
struct V_40 * V_41 = F_8 ( V_26 ) ;
int V_42 ;
V_29 = F_5 ( V_26 ) ;
if ( ! V_29 ) {
F_4 ( V_26 -> V_2 ,
L_20 ) ;
return - V_43 ;
}
if ( F_9 ( V_37 ) ) {
if ( ( V_10 & V_22 ) && V_41 -> V_44 ) {
V_42 = F_10 ( V_41 -> V_44 ) ;
if ( V_42 < 0 ) {
F_4 ( V_26 -> V_2 ,
L_21 ) ;
return V_42 ;
}
}
V_42 = F_11 ( V_29 , V_45 ,
48000 * 512 ,
V_46 ) ;
} else {
V_42 = F_11 ( V_29 , V_47 ,
48000 * 512 ,
V_46 ) ;
if ( ! V_42 ) {
if ( ( V_10 & V_22 ) && V_41 -> V_44 )
F_12 ( V_41 -> V_44 ) ;
}
}
if ( V_42 < 0 ) {
F_4 ( V_26 -> V_2 , L_22 , V_42 ) ;
return V_42 ;
}
return 0 ;
}
static int F_13 ( struct V_48 * V_49 ,
struct V_50 * V_51 )
{
struct V_27 * V_28 = V_49 -> V_52 ;
struct V_24 * V_29 = V_28 -> V_29 ;
int V_42 ;
V_42 = F_11 ( V_29 , V_45 ,
F_14 ( V_51 ) * 512 ,
V_46 ) ;
if ( V_42 < 0 ) {
F_4 ( V_28 -> V_2 , L_23 , V_42 ) ;
return V_42 ;
}
if ( ! ( V_10 & V_22 ) ) {
if ( ( V_10 & V_18 ) ||
( V_10 & V_19 ) ) {
V_42 = F_15 ( V_29 , 0 ,
V_53 ,
F_14 ( V_51 ) * 32 ,
F_14 ( V_51 ) * 512 ) ;
} else {
V_42 = F_15 ( V_29 , 0 ,
V_53 ,
F_14 ( V_51 ) * 50 ,
F_14 ( V_51 ) * 512 ) ;
}
} else {
if ( V_10 & V_23 ) {
V_42 = F_15 ( V_29 , 0 ,
V_54 ,
25000000 ,
F_14 ( V_51 ) * 512 ) ;
} else {
V_42 = F_15 ( V_29 , 0 ,
V_54 ,
19200000 ,
F_14 ( V_51 ) * 512 ) ;
}
}
if ( V_42 < 0 ) {
F_4 ( V_28 -> V_2 , L_24 , V_42 ) ;
return V_42 ;
}
return 0 ;
}
static int F_16 ( const struct V_55 * V_56 )
{
V_10 = ( unsigned long ) V_56 -> V_57 ;
return 1 ;
}
static int F_17 ( struct V_27 * V_58 )
{
int V_42 ;
struct V_59 * V_60 = V_58 -> V_60 ;
struct V_25 * V_26 = V_58 -> V_26 ;
const struct V_61 * V_62 ;
struct V_40 * V_41 = F_8 ( V_26 ) ;
int V_63 ;
V_26 -> V_39 . V_64 = true ;
F_18 ( V_60 ,
V_65 |
V_66 |
V_67 |
V_68 |
V_69 |
V_70 ,
V_71 ) ;
V_42 = F_19 ( V_26 , V_72 ,
F_20 ( V_72 ) ) ;
if ( V_42 ) {
F_4 ( V_26 -> V_2 , L_25 ) ;
return V_42 ;
}
switch ( F_2 ( V_10 ) ) {
case V_13 :
V_62 = V_73 ;
V_63 = F_20 ( V_73 ) ;
break;
case V_14 :
V_62 = V_74 ;
V_63 = F_20 ( V_74 ) ;
break;
case V_12 :
V_62 = V_75 ;
V_63 = F_20 ( V_75 ) ;
break;
default:
V_62 = V_76 ;
V_63 = F_20 ( V_76 ) ;
}
V_42 = F_21 ( & V_26 -> V_39 , V_62 , V_63 ) ;
if ( V_42 )
return V_42 ;
if ( V_10 & V_20 ) {
V_42 = F_21 ( & V_26 -> V_39 ,
V_77 ,
F_20 ( V_77 ) ) ;
} else if ( V_10 & V_18 ) {
V_42 = F_21 ( & V_26 -> V_39 ,
V_78 ,
F_20 ( V_78 ) ) ;
} else if ( V_10 & V_19 ) {
V_42 = F_21 ( & V_26 -> V_39 ,
V_79 ,
F_20 ( V_79 ) ) ;
} else {
V_42 = F_21 ( & V_26 -> V_39 ,
V_80 ,
F_20 ( V_80 ) ) ;
}
if ( V_42 )
return V_42 ;
if ( V_10 & V_16 ) {
V_42 = F_21 ( & V_26 -> V_39 ,
V_81 ,
F_20 ( V_81 ) ) ;
} else {
V_42 = F_21 ( & V_26 -> V_39 ,
V_82 ,
F_20 ( V_82 ) ) ;
}
if ( V_42 )
return V_42 ;
if ( V_10 & V_17 ) {
F_22 ( V_60 , V_83 , V_84 ,
V_84 ) ;
}
if ( V_10 & V_15 ) {
V_42 = F_23 ( V_60 , 0 , 0 ) ;
if ( V_42 )
return V_42 ;
}
F_24 ( & V_26 -> V_39 , L_26 ) ;
F_24 ( & V_26 -> V_39 , L_27 ) ;
if ( ( V_10 & V_22 ) && V_41 -> V_44 ) {
V_42 = F_10 ( V_41 -> V_44 ) ;
if ( ! V_42 )
F_12 ( V_41 -> V_44 ) ;
if ( V_10 & V_23 )
V_42 = F_25 ( V_41 -> V_44 , 25000000 ) ;
else
V_42 = F_25 ( V_41 -> V_44 , 19200000 ) ;
if ( V_42 )
F_4 ( V_26 -> V_2 , L_28 ) ;
}
return V_42 ;
}
static int F_26 ( struct V_27 * V_28 ,
struct V_50 * V_51 )
{
struct V_85 * V_86 = F_27 ( V_51 ,
V_87 ) ;
struct V_85 * V_88 = F_27 ( V_51 ,
V_89 ) ;
int V_42 ;
V_86 -> V_90 = V_86 -> V_91 = 48000 ;
V_88 -> V_90 = V_88 -> V_91 = 2 ;
if ( ( V_10 & V_18 ) ||
( V_10 & V_19 ) ) {
F_28 ( V_51 , V_92 ) ;
V_42 = F_29 ( V_28 -> V_93 ,
V_94 |
V_95 |
V_96
) ;
if ( V_42 < 0 ) {
F_4 ( V_28 -> V_2 , L_29 , V_42 ) ;
return V_42 ;
}
V_42 = F_30 ( V_28 -> V_93 , 0x3 , 0x3 , 2 , 16 ) ;
if ( V_42 < 0 ) {
F_4 ( V_28 -> V_2 , L_30 , V_42 ) ;
return V_42 ;
}
} else {
F_28 ( V_51 , V_97 ) ;
V_42 = F_29 ( V_28 -> V_93 ,
V_94 |
V_95 |
V_96
) ;
if ( V_42 < 0 ) {
F_4 ( V_28 -> V_2 , L_29 , V_42 ) ;
return V_42 ;
}
V_42 = F_30 ( V_28 -> V_93 , 0x3 , 0x3 , 2 , 24 ) ;
if ( V_42 < 0 ) {
F_4 ( V_28 -> V_2 , L_30 , V_42 ) ;
return V_42 ;
}
}
return 0 ;
}
static int F_31 ( struct V_48 * V_49 )
{
return F_32 ( V_49 -> V_58 ,
V_87 , 48000 ) ;
}
static bool F_33 ( void )
{
static const struct V_98 V_99 [] = {
{ V_100 , 6 , 55 } ,
{}
} ;
if ( ! F_34 ( V_99 ) )
return false ;
return true ;
}
static int F_35 ( struct V_101 * V_102 )
{
int V_103 = 0 ;
struct V_104 * V_105 ;
const char * V_106 = NULL ;
int V_107 ;
int V_108 ;
struct V_40 * V_41 ;
V_21 = false ;
V_41 = F_36 ( & V_102 -> V_2 , sizeof( * V_41 ) , V_109 ) ;
if ( ! V_41 )
return - V_110 ;
V_111 . V_2 = & V_102 -> V_2 ;
V_105 = V_111 . V_2 -> V_112 ;
F_37 ( & V_111 , V_41 ) ;
V_108 = V_113 + 1 ;
for ( V_107 = 0 ; V_107 < F_20 ( V_114 ) ; V_107 ++ ) {
if ( ! strcmp ( V_114 [ V_107 ] . V_115 , L_31 ) ) {
V_108 = V_107 ;
break;
}
}
V_106 = F_38 ( V_105 -> V_56 ) ;
if ( V_106 != NULL ) {
snprintf ( V_116 , sizeof( V_116 ) ,
L_32 , L_33 , V_106 ) ;
V_114 [ V_108 ] . V_115 = V_116 ;
}
if ( F_33 () ) {
struct V_117 * V_118 = V_105 -> V_119 ;
const struct V_120 * V_121 = V_118 -> V_121 ;
if ( V_121 -> V_122 == 0 )
V_21 = true ;
}
if ( V_21 ) {
struct V_123 V_124 ;
struct V_125 V_126 = { sizeof( L_34 ) , L_34 } ;
struct V_125 V_127 = { 0 , NULL } ;
struct V_128 V_129 ;
bool V_130 = false ;
V_127 . V_131 = sizeof( V_124 ) ;
V_127 . V_132 = & V_124 ;
V_129 . V_30 = L_35 ;
V_129 . V_131 = 2 ;
V_129 . V_126 = & V_126 ;
V_129 . V_127 = & V_127 ;
V_129 . V_133 = false ;
V_130 = F_39 ( V_105 -> V_56 , & V_129 ) ;
if ( V_130 ) {
if ( V_124 . V_134 == 1 ) {
F_3 ( & V_102 -> V_2 , L_36 ) ;
V_10 |= V_18 ;
} else if ( V_124 . V_134 == 2 ) {
F_3 ( & V_102 -> V_2 , L_37 ) ;
V_10 |= V_19 ;
} else {
F_3 ( & V_102 -> V_2 , L_38 ) ;
V_130 = false ;
}
}
if ( ! V_130 ) {
V_10 |= V_19 ;
}
V_10 |= V_13 ;
V_10 |= V_17 ;
} else {
V_10 |= ( V_11 |
V_15 ) ;
}
F_40 ( V_135 ) ;
if ( V_136 ) {
F_3 ( & V_102 -> V_2 , L_39 ,
( unsigned int ) V_10 , V_136 ) ;
V_10 = V_136 ;
}
F_1 ( & V_102 -> V_2 ) ;
if ( ( V_10 & V_20 ) ||
( V_10 & V_19 ) ) {
snprintf ( V_137 ,
sizeof( V_137 ) ,
L_40 , L_41 ) ;
V_114 [ V_108 ] . V_138 =
V_137 ;
}
if ( ( V_10 & V_18 ) ||
( V_10 & V_19 ) ) {
snprintf ( V_139 ,
sizeof( V_139 ) ,
L_40 , L_42 ) ;
V_114 [ V_108 ] . V_140 =
V_139 ;
}
if ( ( V_10 & V_22 ) && ( F_33 () ) ) {
V_41 -> V_44 = F_41 ( & V_102 -> V_2 , L_43 ) ;
if ( F_42 ( V_41 -> V_44 ) ) {
V_103 = F_43 ( V_41 -> V_44 ) ;
F_4 ( & V_102 -> V_2 ,
L_44 ,
V_103 ) ;
if ( V_103 != - V_141 )
return V_103 ;
V_10 &= ~ V_22 ;
}
}
V_103 = F_44 ( & V_102 -> V_2 , & V_111 ) ;
if ( V_103 ) {
F_4 ( & V_102 -> V_2 , L_45 ,
V_103 ) ;
return V_103 ;
}
F_45 ( V_102 , & V_111 ) ;
return V_103 ;
}
