static void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_3 ) == V_4 )
F_3 ( V_2 , L_1 ) ;
if ( F_2 ( V_3 ) == V_5 )
F_3 ( V_2 , L_2 ) ;
if ( F_2 ( V_3 ) == V_6 )
F_3 ( V_2 , L_3 ) ;
if ( F_2 ( V_3 ) == V_7 )
F_3 ( V_2 , L_4 ) ;
if ( V_3 & V_8 )
F_3 ( V_2 , L_5 ) ;
if ( V_3 & V_9 )
F_3 ( V_2 , L_6 ) ;
if ( V_3 & V_10 )
F_3 ( V_2 , L_7 ) ;
if ( V_3 & V_11 )
F_3 ( V_2 , L_8 ) ;
if ( V_3 & V_12 )
F_3 ( V_2 , L_9 ) ;
if ( V_3 & V_13 )
F_3 ( V_2 , L_10 ) ;
if ( V_3 & V_14 )
F_3 ( V_2 , L_11 ) ;
if ( V_3 & V_15 )
F_3 ( V_2 , L_12 ) ;
}
static inline struct V_16 * F_4 ( struct V_17 * V_18 )
{
struct V_19 * V_20 ;
F_5 (rtd, &card->rtd_list, list) {
if ( ! strncmp ( V_20 -> V_21 -> V_22 , V_23 ,
strlen ( V_23 ) ) )
return V_20 -> V_21 ;
if ( ! strncmp ( V_20 -> V_21 -> V_22 , V_24 ,
strlen ( V_24 ) ) )
return V_20 -> V_21 ;
}
return NULL ;
}
static int F_6 ( struct V_25 * V_26 ,
struct V_27 * V_28 , int V_29 )
{
struct V_30 * V_31 = V_26 -> V_31 ;
struct V_17 * V_18 = V_31 -> V_18 ;
struct V_16 * V_21 ;
struct V_32 * V_33 = F_7 ( V_18 ) ;
int V_34 ;
V_21 = F_4 ( V_18 ) ;
if ( ! V_21 ) {
F_8 ( V_18 -> V_2 ,
L_13 ) ;
return - V_35 ;
}
if ( F_9 ( V_29 ) ) {
if ( ( V_3 & V_14 ) && V_33 -> V_36 ) {
V_34 = F_10 ( V_33 -> V_36 ) ;
if ( V_34 < 0 ) {
F_8 ( V_18 -> V_2 ,
L_14 ) ;
return V_34 ;
}
}
V_34 = F_11 ( V_21 , V_37 ,
48000 * 512 ,
V_38 ) ;
} else {
V_34 = F_11 ( V_21 , V_39 ,
48000 * 512 ,
V_38 ) ;
if ( ! V_34 ) {
if ( ( V_3 & V_14 ) && V_33 -> V_36 )
F_12 ( V_33 -> V_36 ) ;
}
}
if ( V_34 < 0 ) {
F_8 ( V_18 -> V_2 , L_15 , V_34 ) ;
return V_34 ;
}
return 0 ;
}
static int F_13 ( struct V_40 * V_41 ,
struct V_42 * V_43 )
{
struct V_19 * V_20 = V_41 -> V_44 ;
struct V_16 * V_21 = V_20 -> V_21 ;
int V_34 ;
V_34 = F_11 ( V_21 , V_37 ,
F_14 ( V_43 ) * 512 ,
V_38 ) ;
if ( V_34 < 0 ) {
F_8 ( V_20 -> V_2 , L_16 , V_34 ) ;
return V_34 ;
}
if ( ! ( V_3 & V_14 ) ) {
if ( ( V_3 & V_12 ) ||
( V_3 & V_13 ) ) {
V_34 = F_15 ( V_21 , 0 ,
V_45 ,
F_14 ( V_43 ) * 32 ,
F_14 ( V_43 ) * 512 ) ;
} else {
V_34 = F_15 ( V_21 , 0 ,
V_45 ,
F_14 ( V_43 ) * 50 ,
F_14 ( V_43 ) * 512 ) ;
}
} else {
if ( V_3 & V_15 ) {
V_34 = F_15 ( V_21 , 0 ,
V_46 ,
25000000 ,
F_14 ( V_43 ) * 512 ) ;
} else {
V_34 = F_15 ( V_21 , 0 ,
V_46 ,
19200000 ,
F_14 ( V_43 ) * 512 ) ;
}
}
if ( V_34 < 0 ) {
F_8 ( V_20 -> V_2 , L_17 , V_34 ) ;
return V_34 ;
}
return 0 ;
}
static int F_16 ( const struct V_47 * V_48 )
{
V_3 = ( unsigned long ) V_48 -> V_49 ;
return 1 ;
}
static int F_17 ( struct V_19 * V_50 )
{
int V_34 ;
struct V_51 * V_52 = V_50 -> V_52 ;
struct V_17 * V_18 = V_50 -> V_18 ;
const struct V_53 * V_54 ;
struct V_32 * V_33 = F_7 ( V_18 ) ;
int V_55 ;
V_18 -> V_31 . V_56 = true ;
F_18 ( V_52 ,
V_57 |
V_58 |
V_59 |
V_60 |
V_61 |
V_62 ,
V_63 ) ;
V_34 = F_19 ( V_18 , V_64 ,
F_20 ( V_64 ) ) ;
if ( V_34 ) {
F_8 ( V_18 -> V_2 , L_18 ) ;
return V_34 ;
}
switch ( F_2 ( V_3 ) ) {
case V_6 :
V_54 = V_65 ;
V_55 = F_20 ( V_65 ) ;
break;
case V_7 :
V_54 = V_66 ;
V_55 = F_20 ( V_66 ) ;
break;
case V_5 :
V_54 = V_67 ;
V_55 = F_20 ( V_67 ) ;
break;
default:
V_54 = V_68 ;
V_55 = F_20 ( V_68 ) ;
}
V_34 = F_21 ( & V_18 -> V_31 , V_54 , V_55 ) ;
if ( V_34 )
return V_34 ;
if ( V_3 & V_11 ) {
V_34 = F_21 ( & V_18 -> V_31 ,
V_69 ,
F_20 ( V_69 ) ) ;
} else if ( V_3 & V_12 ) {
V_34 = F_21 ( & V_18 -> V_31 ,
V_70 ,
F_20 ( V_70 ) ) ;
} else if ( V_3 & V_13 ) {
V_34 = F_21 ( & V_18 -> V_31 ,
V_71 ,
F_20 ( V_71 ) ) ;
} else {
V_34 = F_21 ( & V_18 -> V_31 ,
V_72 ,
F_20 ( V_72 ) ) ;
}
if ( V_34 )
return V_34 ;
if ( V_3 & V_9 ) {
V_34 = F_21 ( & V_18 -> V_31 ,
V_73 ,
F_20 ( V_73 ) ) ;
} else {
V_34 = F_21 ( & V_18 -> V_31 ,
V_74 ,
F_20 ( V_74 ) ) ;
}
if ( V_34 )
return V_34 ;
if ( V_3 & V_10 ) {
F_22 ( V_52 , V_75 , V_76 ,
V_76 ) ;
}
if ( V_3 & V_8 ) {
V_34 = F_23 ( V_52 , 0 , 0 ) ;
if ( V_34 )
return V_34 ;
}
F_24 ( & V_18 -> V_31 , L_19 ) ;
F_24 ( & V_18 -> V_31 , L_20 ) ;
if ( ( V_3 & V_14 ) && V_33 -> V_36 ) {
V_34 = F_10 ( V_33 -> V_36 ) ;
if ( ! V_34 )
F_12 ( V_33 -> V_36 ) ;
if ( V_3 & V_15 )
V_34 = F_25 ( V_33 -> V_36 , 25000000 ) ;
else
V_34 = F_25 ( V_33 -> V_36 , 19200000 ) ;
if ( V_34 )
F_8 ( V_18 -> V_2 , L_21 ) ;
}
return V_34 ;
}
static int F_26 ( struct V_19 * V_20 ,
struct V_42 * V_43 )
{
struct V_77 * V_78 = F_27 ( V_43 ,
V_79 ) ;
struct V_77 * V_80 = F_27 ( V_43 ,
V_81 ) ;
int V_34 ;
V_78 -> V_82 = V_78 -> V_83 = 48000 ;
V_80 -> V_82 = V_80 -> V_83 = 2 ;
if ( ( V_3 & V_12 ) ||
( V_3 & V_13 ) ) {
F_28 ( V_43 , V_84 ) ;
V_34 = F_29 ( V_20 -> V_85 ,
V_86 |
V_87 |
V_88
) ;
if ( V_34 < 0 ) {
F_8 ( V_20 -> V_2 , L_22 , V_34 ) ;
return V_34 ;
}
V_34 = F_30 ( V_20 -> V_85 , 0x3 , 0x3 , 2 , 16 ) ;
if ( V_34 < 0 ) {
F_8 ( V_20 -> V_2 , L_23 , V_34 ) ;
return V_34 ;
}
} else {
F_28 ( V_43 , V_89 ) ;
V_34 = F_29 ( V_20 -> V_85 ,
V_86 |
V_87 |
V_88
) ;
if ( V_34 < 0 ) {
F_8 ( V_20 -> V_2 , L_22 , V_34 ) ;
return V_34 ;
}
V_34 = F_30 ( V_20 -> V_85 , 0x3 , 0x3 , 2 , 24 ) ;
if ( V_34 < 0 ) {
F_8 ( V_20 -> V_2 , L_23 , V_34 ) ;
return V_34 ;
}
}
return 0 ;
}
static int F_31 ( struct V_40 * V_41 )
{
return F_32 ( V_41 -> V_50 ,
V_79 , 48000 ) ;
}
static bool F_33 ( void )
{
static const struct V_90 V_91 [] = {
{ V_92 , 6 , 55 } ,
{}
} ;
if ( ! F_34 ( V_91 ) )
return false ;
return true ;
}
static int F_35 ( struct V_93 * V_94 )
{
int V_95 = 0 ;
struct V_96 * V_97 ;
const char * V_98 = NULL ;
int V_99 ;
int V_100 ;
struct V_32 * V_33 ;
bool V_101 = false ;
V_33 = F_36 ( & V_94 -> V_2 , sizeof( * V_33 ) , V_102 ) ;
if ( ! V_33 )
return - V_103 ;
V_104 . V_2 = & V_94 -> V_2 ;
V_97 = V_104 . V_2 -> V_105 ;
F_37 ( & V_104 , V_33 ) ;
V_100 = V_106 + 1 ;
for ( V_99 = 0 ; V_99 < F_20 ( V_107 ) ; V_99 ++ ) {
if ( ! strcmp ( V_107 [ V_99 ] . V_108 , L_24 ) ) {
V_100 = V_99 ;
break;
}
}
V_98 = F_38 ( V_97 -> V_48 ) ;
if ( V_98 != NULL ) {
snprintf ( V_109 , sizeof( V_109 ) ,
L_25 , L_26 , V_98 ) ;
V_107 [ V_100 ] . V_108 = V_109 ;
}
if ( F_33 () ) {
struct V_110 * V_111 = V_97 -> V_112 ;
const struct V_113 * V_114 = V_111 -> V_114 ;
if ( V_114 -> V_115 == 0 )
V_101 = true ;
}
if ( V_101 ) {
struct V_116 V_117 ;
struct V_118 V_119 = { sizeof( L_27 ) , L_27 } ;
struct V_118 V_120 = { 0 , NULL } ;
struct V_121 V_122 ;
bool V_123 = false ;
V_120 . V_124 = sizeof( V_117 ) ;
V_120 . V_125 = & V_117 ;
V_122 . V_22 = L_28 ;
V_122 . V_124 = 2 ;
V_122 . V_119 = & V_119 ;
V_122 . V_120 = & V_120 ;
V_122 . V_126 = false ;
V_123 = F_39 ( V_97 -> V_48 , & V_122 ) ;
if ( V_123 ) {
if ( V_117 . V_127 == 1 ) {
F_3 ( & V_94 -> V_2 , L_29 ) ;
V_3 |= V_12 ;
} else if ( V_117 . V_127 == 2 ) {
F_3 ( & V_94 -> V_2 , L_30 ) ;
V_3 |= V_13 ;
} else {
F_3 ( & V_94 -> V_2 , L_31 ) ;
V_123 = false ;
}
}
if ( ! V_123 ) {
V_3 |= V_13 ;
}
V_3 |= V_6 ;
V_3 |= V_10 ;
} else {
V_3 |= ( V_4 |
V_8 ) ;
}
F_40 ( V_128 ) ;
F_1 ( & V_94 -> V_2 ) ;
if ( ( V_3 & V_11 ) ||
( V_3 & V_13 ) ) {
snprintf ( V_129 ,
sizeof( V_129 ) ,
L_32 , L_33 ) ;
V_107 [ V_100 ] . V_130 =
V_129 ;
}
if ( ( V_3 & V_12 ) ||
( V_3 & V_13 ) ) {
snprintf ( V_131 ,
sizeof( V_131 ) ,
L_32 , L_34 ) ;
V_107 [ V_100 ] . V_132 =
V_131 ;
}
if ( ( V_3 & V_14 ) && ( F_33 () ) ) {
V_33 -> V_36 = F_41 ( & V_94 -> V_2 , L_35 ) ;
if ( F_42 ( V_33 -> V_36 ) ) {
V_95 = F_43 ( V_33 -> V_36 ) ;
F_8 ( & V_94 -> V_2 ,
L_36 ,
V_95 ) ;
if ( V_95 != - V_133 )
return V_95 ;
V_3 &= ~ V_14 ;
}
}
V_95 = F_44 ( & V_94 -> V_2 , & V_104 ) ;
if ( V_95 ) {
F_8 ( & V_94 -> V_2 , L_37 ,
V_95 ) ;
return V_95 ;
}
F_45 ( V_94 , & V_104 ) ;
return V_95 ;
}
