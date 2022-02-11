static void F_1 ( struct V_1 * V_2 )
{
if ( V_3 & V_4 )
F_2 ( V_2 , L_1 ) ;
if ( V_3 & V_5 )
F_2 ( V_2 , L_2 ) ;
if ( V_3 & V_6 )
F_2 ( V_2 , L_3 ) ;
}
static inline struct V_7 * F_3 ( struct V_8 * V_9 )
{
struct V_10 * V_11 ;
F_4 (rtd, &card->rtd_list, list) {
if ( ! strncmp ( V_11 -> V_12 -> V_13 , V_14 ,
strlen ( V_14 ) ) )
return V_11 -> V_12 ;
if ( ! strncmp ( V_11 -> V_12 -> V_13 , V_15 ,
strlen ( V_15 ) ) )
return V_11 -> V_12 ;
}
return NULL ;
}
static int F_5 ( struct V_16 * V_17 ,
struct V_18 * V_19 , int V_20 )
{
struct V_21 * V_22 = V_17 -> V_22 ;
struct V_8 * V_9 = V_22 -> V_9 ;
struct V_7 * V_12 ;
struct V_23 * V_24 = F_6 ( V_9 ) ;
int V_25 ;
V_12 = F_3 ( V_9 ) ;
if ( ! V_12 ) {
F_7 ( V_9 -> V_2 , L_4 ) ;
return - V_26 ;
}
if ( F_8 ( V_20 ) ) {
if ( V_24 -> V_27 ) {
V_25 = F_9 ( V_24 -> V_27 ) ;
if ( V_25 < 0 ) {
F_7 ( V_9 -> V_2 ,
L_5 ) ;
return V_25 ;
}
}
} else {
V_25 = F_10 ( V_12 , V_28 ,
48000 * 512 , V_29 ) ;
if ( V_25 < 0 ) {
F_7 ( V_9 -> V_2 , L_6 , V_25 ) ;
return V_25 ;
}
if ( V_24 -> V_27 )
F_11 ( V_24 -> V_27 ) ;
}
return 0 ;
}
static int F_12 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_10 * V_11 = V_31 -> V_34 ;
struct V_7 * V_12 = V_11 -> V_12 ;
int V_25 ;
V_25 = F_13 ( V_12 , 0 , V_35 ,
V_36 , F_14 ( V_33 ) * 512 ) ;
if ( V_25 < 0 ) {
F_7 ( V_11 -> V_2 , L_7 , V_25 ) ;
return V_25 ;
}
V_25 = F_10 ( V_12 , V_37 ,
F_14 ( V_33 ) * 512 , V_29 ) ;
if ( V_25 < 0 ) {
F_7 ( V_11 -> V_2 , L_6 , V_25 ) ;
return V_25 ;
}
return 0 ;
}
static int F_15 ( struct V_10 * V_38 )
{
int V_25 ;
int V_39 ;
struct V_40 * V_41 = V_38 -> V_41 ;
struct V_8 * V_9 = V_38 -> V_9 ;
struct V_23 * V_24 = F_6 ( V_38 -> V_9 ) ;
if ( ( V_3 & V_4 ) ||
( V_3 & V_6 ) ) {
F_16 ( V_41 ,
V_42 |
V_43 |
V_44 |
V_45 ,
V_46 ) ;
} else {
F_16 ( V_41 ,
V_42 |
V_43 |
V_44 |
V_45 ,
V_47 ) ;
}
if ( V_3 & V_4 ) {
V_25 = F_17 ( & V_9 -> V_22 ,
V_48 ,
F_18 ( V_48 ) ) ;
} else if ( V_3 & V_5 ) {
V_25 = F_17 ( & V_9 -> V_22 ,
V_49 ,
F_18 ( V_49 ) ) ;
} else if ( V_3 & V_6 ) {
V_25 = F_17 ( & V_9 -> V_22 ,
V_50 ,
F_18 ( V_50 ) ) ;
} else {
V_25 = F_17 ( & V_9 -> V_22 ,
V_51 ,
F_18 ( V_51 ) ) ;
}
if ( V_25 )
return V_25 ;
if ( V_24 -> V_52 -> V_53 == V_54 )
V_39 = V_55 | V_56 |
V_57 | V_58 |
V_59 | V_60 ;
else
V_39 = V_55 | V_56 ;
V_25 = F_19 ( V_38 -> V_9 , L_8 ,
V_39 , & V_24 -> V_61 ,
V_62 , F_18 ( V_62 ) ) ;
if ( V_25 ) {
F_7 ( V_38 -> V_2 , L_9 , V_25 ) ;
return V_25 ;
}
F_20 ( V_41 , & V_24 -> V_61 , & V_24 -> V_61 , & V_24 -> V_61 ) ;
if ( V_24 -> V_27 ) {
V_25 = F_9 ( V_24 -> V_27 ) ;
if ( ! V_25 )
F_11 ( V_24 -> V_27 ) ;
V_25 = F_21 ( V_24 -> V_27 , V_36 ) ;
if ( V_25 )
F_7 ( V_38 -> V_2 , L_10 ) ;
}
return V_25 ;
}
static int F_22 ( struct V_10 * V_11 ,
struct V_32 * V_33 )
{
int V_25 ;
struct V_63 * V_64 = F_23 ( V_33 ,
V_65 ) ;
struct V_63 * V_66 = F_23 ( V_33 ,
V_67 ) ;
V_64 -> V_68 = V_64 -> V_69 = 48000 ;
V_66 -> V_68 = V_66 -> V_69 = 2 ;
if ( ( V_3 & V_5 ) ||
( V_3 & V_6 ) ) {
F_24 ( V_33 , V_70 ) ;
V_25 = F_25 ( V_11 -> V_71 ,
V_72 |
V_73 |
V_74
) ;
if ( V_25 < 0 ) {
F_7 ( V_11 -> V_2 , L_11 , V_25 ) ;
return V_25 ;
}
V_25 = F_25 ( V_11 -> V_12 ,
V_72 |
V_73 |
V_74
) ;
if ( V_25 < 0 ) {
F_7 ( V_11 -> V_2 , L_11 , V_25 ) ;
return V_25 ;
}
V_25 = F_26 ( V_11 -> V_71 , 0x3 , 0x3 , 2 , 16 ) ;
if ( V_25 < 0 ) {
F_7 ( V_11 -> V_2 , L_12 , V_25 ) ;
return V_25 ;
}
} else {
F_24 ( V_33 , V_75 ) ;
V_25 = F_25 ( V_11 -> V_12 ,
V_76 |
V_77 |
V_74 ) ;
if ( V_25 < 0 ) {
F_7 ( V_11 -> V_2 , L_13 , V_25 ) ;
return V_25 ;
}
V_25 = F_26 ( V_11 -> V_12 , 0xF , 0xF , 4 , 24 ) ;
if ( V_25 < 0 ) {
F_7 ( V_11 -> V_2 , L_14 , V_25 ) ;
return V_25 ;
}
}
return 0 ;
}
static int F_27 ( struct V_30 * V_31 )
{
return F_28 ( V_31 -> V_38 ,
V_65 , 48000 ) ;
}
static bool F_29 ( void )
{
static const struct V_78 V_79 [] = {
{ V_80 , 6 , 55 } ,
{}
} ;
if ( ! F_30 ( V_79 ) )
return false ;
return true ;
}
static int F_31 ( struct V_81 * V_82 )
{
int V_83 = 0 ;
int V_84 ;
struct V_23 * V_85 ;
struct V_8 * V_9 = V_86 [ 0 ] . V_87 ;
struct V_88 * V_89 ;
const char * V_90 = NULL ;
int V_91 = 0 ;
bool V_92 = false ;
bool V_93 = false ;
V_85 = F_32 ( & V_82 -> V_2 , sizeof( * V_85 ) , V_94 ) ;
if ( ! V_85 )
return - V_95 ;
V_89 = ( & V_82 -> V_2 ) -> V_96 ;
for ( V_84 = 0 ; V_84 < F_18 ( V_86 ) ; V_84 ++ ) {
if ( F_33 ( V_86 [ V_84 ] . V_97 ) &&
( ! strncmp ( V_86 [ V_84 ] . V_97 , V_89 -> V_98 , 8 ) ) ) {
F_34 ( & V_82 -> V_2 ,
L_15 , V_86 [ V_84 ] . V_97 ) ;
V_9 = V_86 [ V_84 ] . V_87 ;
V_85 -> V_52 = & V_86 [ V_84 ] ;
V_92 = true ;
break;
}
}
if ( ! V_92 ) {
F_7 ( & V_82 -> V_2 , L_16 ) ;
return - V_99 ;
}
V_9 -> V_2 = & V_82 -> V_2 ;
sprintf ( V_85 -> V_100 , L_17 , V_85 -> V_52 -> V_97 ) ;
for ( V_84 = 0 ; V_84 < F_18 ( V_101 ) ; V_84 ++ )
if ( ! strcmp ( V_9 -> V_102 [ V_84 ] . V_100 , L_18 ) ) {
V_9 -> V_102 [ V_84 ] . V_100 = V_85 -> V_100 ;
V_91 = V_84 ;
}
V_90 = F_35 ( V_89 -> V_98 ) ;
if ( V_90 != NULL ) {
snprintf ( V_103 , sizeof( V_103 ) ,
L_19 , L_20 , V_90 ) ;
V_101 [ V_91 ] . V_100 = V_103 ;
}
if ( F_29 () ) {
struct V_104 * V_105 = V_89 -> V_106 ;
const struct V_107 * V_108 = V_105 -> V_108 ;
if ( V_108 -> V_109 == 0 )
V_93 = true ;
}
if ( V_93 ) {
struct V_110 V_111 ;
struct V_112 V_113 = { sizeof( L_21 ) , L_21 } ;
struct V_112 V_114 = { 0 , NULL } ;
struct V_115 V_116 ;
bool V_117 = false ;
V_114 . V_118 = sizeof( V_111 ) ;
V_114 . V_119 = & V_111 ;
V_116 . V_13 = L_22 ;
V_116 . V_118 = 2 ;
V_116 . V_113 = & V_113 ;
V_116 . V_114 = & V_114 ;
V_116 . V_120 = false ;
V_117 = F_36 ( V_89 -> V_98 , & V_116 ) ;
if ( V_117 ) {
if ( V_111 . V_121 == 1 ) {
F_2 ( & V_82 -> V_2 , L_23 ) ;
V_3 |= V_5 ;
} else if ( V_111 . V_121 == 2 ) {
F_2 ( & V_82 -> V_2 , L_24 ) ;
V_3 |= V_6 ;
} else {
F_2 ( & V_82 -> V_2 , L_25 ) ;
V_117 = false ;
}
}
if ( ! V_117 ) {
V_3 |= V_6 ;
}
}
F_37 ( V_122 ) ;
F_1 ( & V_82 -> V_2 ) ;
if ( ( V_3 & V_4 ) ||
( V_3 & V_6 ) ) {
snprintf ( V_123 ,
sizeof( V_123 ) ,
L_26 , L_27 ) ;
V_101 [ V_91 ] . V_124 =
V_123 ;
}
if ( ( V_3 & V_5 ) ||
( V_3 & V_6 ) ) {
snprintf ( V_125 ,
sizeof( V_125 ) ,
L_26 , L_28 ) ;
V_101 [ V_91 ] . V_126 =
V_125 ;
}
if ( F_29 () ) {
V_85 -> V_27 = F_38 ( & V_82 -> V_2 , L_29 ) ;
if ( F_39 ( V_85 -> V_27 ) ) {
F_7 ( & V_82 -> V_2 ,
L_30 ,
F_40 ( V_85 -> V_27 ) ) ;
return F_40 ( V_85 -> V_27 ) ;
}
}
F_41 ( V_9 , V_85 ) ;
V_83 = F_42 ( & V_82 -> V_2 , V_9 ) ;
if ( V_83 ) {
F_7 ( & V_82 -> V_2 ,
L_31 , V_83 ) ;
return V_83 ;
}
F_43 ( V_82 , V_9 ) ;
return V_83 ;
}
