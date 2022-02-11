static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_4 * V_5 = V_3 -> V_5 ;
T_1 V_6 , V_7 , V_8 , V_9 , V_10 ;
unsigned long V_11 ;
int V_12 = 0 ;
F_4 ( V_5 -> V_5 ) ;
F_5 ( V_3 ) ;
V_6 = F_6 ( V_3 , V_13 ) ;
F_7 ( V_3 ) ;
V_7 = F_8 ( V_6 , V_14 ) ;
V_8 = F_8 ( V_6 , V_15 ) ;
F_9 ( L_1 , V_7 , V_8 ) ;
if ( V_7 != 4 ) {
F_10 ( V_5 -> V_5 , L_2 ,
V_7 , V_8 ) ;
V_12 = - V_16 ;
goto V_17;
}
V_3 -> V_18 = V_8 ;
if ( V_3 -> V_18 > 1 ) {
F_11 ( V_3 , V_19 , 0x0707ffff ) ;
F_11 ( V_3 , V_20 , 0x03073f3f ) ;
}
F_11 ( V_3 , V_21 , 0x3 ) ;
F_11 ( V_3 , V_22 , 0x02222 ) ;
V_11 = F_12 ( V_3 -> V_11 ) ;
if ( ( V_3 -> V_18 >= 1 ) || ( V_11 >= 90000000 ) ) {
V_9 = 0x47 ;
V_10 = 0x47 ;
} else {
V_9 = 0x27 ;
V_10 = 0x43 ;
}
F_9 ( L_3 , V_9 , V_10 ) ;
F_11 ( V_3 , F_13 ( V_23 ) , V_9 ) ;
F_11 ( V_3 , F_13 ( V_24 ) , V_9 ) ;
F_11 ( V_3 , F_14 ( V_25 ) , V_10 ) ;
F_11 ( V_3 , F_14 ( V_26 ) , V_10 ) ;
F_11 ( V_3 , F_14 ( V_27 ) , V_10 ) ;
F_11 ( V_3 , F_14 ( V_28 ) , V_10 ) ;
if ( V_3 -> V_18 >= 2 )
F_11 ( V_3 , V_29 , 1 ) ;
F_11 ( V_3 , V_30 , 0 ) ;
F_11 ( V_3 , F_15 ( V_25 ) , 0 ) ;
F_11 ( V_3 , F_15 ( V_26 ) , 0 ) ;
F_11 ( V_3 , V_31 , 0 ) ;
F_11 ( V_3 , V_32 , 0 ) ;
F_11 ( V_3 , F_16 ( 1 ) , 0 ) ;
F_11 ( V_3 , F_16 ( 2 ) , 0 ) ;
if ( V_3 -> V_18 > 1 )
F_11 ( V_3 , V_33 , 1 ) ;
V_5 -> V_34 . V_35 = true ;
V_17:
F_17 ( V_5 -> V_5 ) ;
return V_12 ;
}
static void F_18 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
int V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
F_5 ( V_3 ) ;
F_19 (state, crtc, crtc_state, i)
F_20 ( V_40 ) ;
}
static void F_21 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
int V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
F_19 (state, crtc, crtc_state, i)
F_22 ( V_40 ) ;
F_7 ( V_3 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
F_24 ( V_40 ) ;
}
static long F_25 ( struct V_1 * V_2 , unsigned long V_43 ,
struct V_44 * V_45 )
{
switch ( V_45 -> V_46 ) {
case V_47 :
return F_26 ( V_45 , V_43 ) ;
case V_48 :
case V_49 :
default:
return V_43 ;
}
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_50 * V_5 = V_3 -> V_5 -> V_5 ;
struct V_51 * V_52 = V_3 -> V_52 ;
if ( V_3 -> V_53 )
F_28 ( V_3 -> V_54 , V_3 -> V_55 ) ;
F_29 ( V_3 -> V_54 ) ;
if ( V_52 ) {
V_52 -> V_56 -> V_57 -> V_58 ( V_52 -> V_56 ,
V_59 , F_30 ( V_59 ) ) ;
F_31 ( V_52 ) ;
}
if ( V_3 -> V_60 )
F_32 ( V_5 ) ;
F_33 ( V_3 ) ;
}
int F_7 ( struct V_3 * V_3 )
{
F_9 ( L_4 ) ;
F_34 ( V_3 -> V_11 ) ;
if ( V_3 -> V_61 )
F_34 ( V_3 -> V_61 ) ;
F_34 ( V_3 -> V_62 ) ;
if ( V_3 -> V_63 )
F_34 ( V_3 -> V_63 ) ;
return 0 ;
}
int F_5 ( struct V_3 * V_3 )
{
F_9 ( L_4 ) ;
F_35 ( V_3 -> V_11 ) ;
if ( V_3 -> V_61 )
F_35 ( V_3 -> V_61 ) ;
F_35 ( V_3 -> V_62 ) ;
if ( V_3 -> V_63 )
F_35 ( V_3 -> V_63 ) ;
return 0 ;
}
static int F_36 ( struct V_3 * V_3 ,
int V_64 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_65 * V_66 = V_5 -> V_67 ;
struct V_44 * V_45 ;
struct V_68 * V_69 ;
struct V_70 * V_71 ;
int V_72 ;
int V_12 ;
switch ( V_64 ) {
case V_48 :
V_71 = F_37 ( V_5 -> V_5 -> V_73 , 0 , 0 ) ;
if ( ! V_71 )
return 0 ;
V_45 = F_38 ( V_5 , V_71 ) ;
if ( F_39 ( V_45 ) ) {
F_10 ( V_5 -> V_5 , L_5 ) ;
return F_40 ( V_45 ) ;
}
V_45 -> V_74 = 1 << V_23 ;
V_69 = F_41 ( V_5 , V_71 , V_45 ) ;
if ( F_39 ( V_69 ) ) {
F_10 ( V_5 -> V_5 , L_6 ) ;
return F_40 ( V_69 ) ;
}
V_66 -> V_75 [ V_66 -> V_76 ++ ] = V_45 ;
V_66 -> V_77 [ V_66 -> V_78 ++ ] = V_69 ;
break;
case V_47 :
V_45 = F_42 ( V_5 ) ;
if ( F_39 ( V_45 ) ) {
F_10 ( V_5 -> V_5 , L_7 ) ;
return F_40 ( V_45 ) ;
}
V_45 -> V_74 = 1 << 1 ;
if ( V_66 -> V_79 ) {
V_12 = F_43 ( V_66 -> V_79 , V_5 , V_45 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_8 , V_12 ) ;
return V_12 ;
}
}
V_66 -> V_75 [ V_66 -> V_76 ++ ] = V_45 ;
break;
case V_49 :
V_72 = 0 ;
if ( ! V_66 -> V_80 [ V_72 ] )
break;
V_45 = F_44 ( V_5 ) ;
if ( F_39 ( V_45 ) ) {
V_12 = F_40 ( V_45 ) ;
F_10 ( V_5 -> V_5 ,
L_9 , V_12 ) ;
return V_12 ;
}
V_45 -> V_74 = 1 << V_23 ;
V_66 -> V_75 [ V_66 -> V_76 ++ ] = V_45 ;
V_12 = F_45 ( V_66 -> V_80 [ V_72 ] , V_5 , V_45 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_10 ,
V_12 ) ;
return V_12 ;
}
break;
default:
F_10 ( V_5 -> V_5 , L_11 ) ;
return - V_81 ;
}
return 0 ;
}
static int F_46 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_65 * V_66 = V_5 -> V_67 ;
struct V_82 * V_83 ;
struct V_39 * V_40 ;
int V_38 , V_12 ;
static const enum V_84 V_85 [] = {
V_27 , V_28 ,
} ;
static const enum V_84 V_86 [] = {
V_25 , V_26 ,
} ;
static const enum V_87 V_88 [] = {
V_23 , V_24 ,
} ;
static const char * const V_89 [] = {
L_12 , L_13 ,
} ;
static const int V_90 [] = {
V_48 ,
V_49 ,
V_47 ,
} ;
for ( V_38 = 0 ; V_38 < F_30 ( V_86 ) ; V_38 ++ ) {
V_83 = F_47 ( V_5 , V_86 [ V_38 ] , false ) ;
if ( F_39 ( V_83 ) ) {
F_10 ( V_5 -> V_5 ,
L_14 , V_38 + 1 ) ;
V_12 = F_40 ( V_83 ) ;
goto V_91;
}
V_66 -> V_92 [ V_66 -> V_93 ++ ] = V_83 ;
}
for ( V_38 = 0 ; V_38 < F_30 ( V_88 ) ; V_38 ++ ) {
V_83 = F_47 ( V_5 , V_85 [ V_38 ] , true ) ;
if ( F_39 ( V_83 ) ) {
F_10 ( V_5 -> V_5 ,
L_15 , V_38 + 1 ) ;
V_12 = F_40 ( V_83 ) ;
goto V_91;
}
V_40 = F_48 ( V_5 , V_83 , V_66 -> V_94 , V_38 ,
V_88 [ V_38 ] ) ;
if ( F_39 ( V_40 ) ) {
F_10 ( V_5 -> V_5 , L_16 ,
V_89 [ V_38 ] ) ;
V_12 = F_40 ( V_40 ) ;
goto V_91;
}
V_66 -> V_95 [ V_66 -> V_94 ++ ] = V_40 ;
}
for ( V_38 = 0 ; V_38 < F_30 ( V_90 ) ; V_38 ++ ) {
V_12 = F_36 ( V_3 , V_90 [ V_38 ] ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_17 ,
V_38 , V_12 ) ;
goto V_91;
}
}
return 0 ;
V_91:
return V_12 ;
}
struct V_1 * F_49 ( struct V_4 * V_5 )
{
struct V_96 * V_97 = F_50 ( V_5 -> V_5 ) ;
struct V_98 * V_99 = F_51 ( V_97 ) ;
struct V_3 * V_3 ;
struct V_1 * V_2 = NULL ;
struct V_51 * V_52 ;
int V_100 , V_12 ;
V_3 = F_52 ( sizeof( * V_3 ) , V_101 ) ;
if ( ! V_3 ) {
F_10 ( V_5 -> V_5 , L_18 ) ;
V_12 = - V_102 ;
goto V_91;
}
F_53 ( & V_3 -> V_103 , & V_104 ) ;
V_2 = & V_3 -> V_103 . V_103 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_105 = F_54 ( V_97 , NULL , L_19 ) ;
if ( F_39 ( V_3 -> V_105 ) ) {
V_12 = F_40 ( V_3 -> V_105 ) ;
goto V_91;
}
V_100 = F_55 ( V_97 , 0 ) ;
if ( V_100 < 0 ) {
V_12 = V_100 ;
F_10 ( V_5 -> V_5 , L_20 , V_12 ) ;
goto V_91;
}
V_2 -> V_100 = V_100 ;
V_3 -> V_106 = F_56 ( & V_97 -> V_5 , L_21 ) ;
if ( F_39 ( V_3 -> V_106 ) )
V_3 -> V_106 = NULL ;
if ( V_3 -> V_106 ) {
V_12 = F_57 ( V_3 -> V_106 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_22 , V_12 ) ;
goto V_91;
}
}
V_3 -> V_11 = F_58 ( & V_97 -> V_5 , L_23 ) ;
if ( F_39 ( V_3 -> V_11 ) ) {
F_10 ( V_5 -> V_5 , L_24 ) ;
V_12 = F_40 ( V_3 -> V_11 ) ;
goto V_91;
}
V_3 -> V_61 = F_58 ( & V_97 -> V_5 , L_25 ) ;
if ( F_39 ( V_3 -> V_61 ) )
V_3 -> V_61 = NULL ;
V_3 -> V_62 = F_58 ( & V_97 -> V_5 , L_26 ) ;
if ( F_39 ( V_3 -> V_62 ) ) {
F_10 ( V_5 -> V_5 , L_27 ) ;
V_12 = F_40 ( V_3 -> V_62 ) ;
goto V_91;
}
V_3 -> V_63 = F_58 ( & V_97 -> V_5 , L_28 ) ;
if ( F_39 ( V_3 -> V_63 ) ) {
F_10 ( V_5 -> V_5 , L_29 ) ;
V_12 = F_40 ( V_3 -> V_63 ) ;
goto V_91;
}
F_59 ( V_3 -> V_11 , V_99 -> V_107 ) ;
F_59 ( V_3 -> V_62 , V_99 -> V_107 ) ;
F_60 ( V_5 -> V_5 ) ;
V_3 -> V_60 = true ;
F_5 ( V_3 ) ;
F_11 ( V_3 , V_108 , 0 ) ;
F_11 ( V_3 , V_109 , 0 ) ;
F_11 ( V_3 , V_110 , 0 ) ;
F_7 ( V_3 ) ;
F_61 ( 16 ) ;
if ( V_99 -> V_111 ) {
V_52 = F_62 ( & V_97 -> V_5 ,
V_99 -> V_111 , L_30 ) ;
if ( F_39 ( V_52 ) ) {
V_12 = F_40 ( V_52 ) ;
goto V_91;
}
V_3 -> V_52 = V_52 ;
V_12 = V_52 -> V_56 -> V_57 -> V_112 ( V_52 -> V_56 , V_59 ,
F_30 ( V_59 ) ) ;
if ( V_12 )
goto V_91;
} else {
F_63 ( V_5 -> V_5 , L_31
L_32 ) ;
V_52 = NULL ;
}
V_3 -> V_55 = F_64 ( V_5 , V_52 ) ;
if ( V_3 -> V_55 < 0 ) {
V_12 = V_3 -> V_55 ;
F_10 ( V_5 -> V_5 , L_33 , V_12 ) ;
goto V_91;
}
V_12 = F_46 ( V_3 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_34 , V_12 ) ;
goto V_91;
}
F_65 ( & V_5 -> V_113 ) ;
V_3 -> V_54 = F_66 ( V_5 , V_114 , V_115 ) ;
F_67 ( & V_5 -> V_113 ) ;
if ( F_39 ( V_3 -> V_54 ) ) {
V_12 = F_40 ( V_3 -> V_54 ) ;
F_10 ( V_5 -> V_5 , L_35 , V_12 ) ;
V_3 -> V_54 = NULL ;
goto V_91;
}
V_12 = F_68 ( V_3 -> V_54 , V_3 -> V_55 ,
& V_3 -> V_53 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_36 , V_12 ) ;
goto V_91;
}
V_5 -> V_34 . V_116 = 0 ;
V_5 -> V_34 . V_117 = 0 ;
V_5 -> V_34 . V_118 = 2048 ;
V_5 -> V_34 . V_119 = 2048 ;
return V_2 ;
V_91:
if ( V_2 )
F_27 ( V_2 ) ;
return F_69 ( V_12 ) ;
}
static struct V_98 * F_51 ( struct V_96 * V_5 )
{
static struct V_98 V_99 = {} ;
V_99 . V_107 = 266667000 ;
V_99 . V_111 = F_70 ( & V_120 ) ;
if ( V_99 . V_111 ) {
V_99 . V_111 -> V_121 . V_122 = 0x1000 ;
V_99 . V_111 -> V_121 . V_123 = 0xffffffff ;
}
return & V_99 ;
}
