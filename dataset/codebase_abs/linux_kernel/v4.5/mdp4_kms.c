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
if ( V_3 -> V_19 ) {
if ( ( V_3 -> V_18 == 2 ) || ( V_3 -> V_18 == 4 ) ) {
V_12 = F_11 ( V_3 -> V_19 ,
1200000 , 1200000 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 ,
L_3 , V_12 ) ;
goto V_17;
}
}
}
if ( V_3 -> V_20 ) {
if ( V_3 -> V_18 == 2 ) {
V_12 = F_11 ( V_3 -> V_20 ,
1800000 , 1800000 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 ,
L_4 , V_12 ) ;
goto V_17;
}
}
}
if ( V_3 -> V_18 > 1 ) {
F_12 ( V_3 , V_21 , 0x0707ffff ) ;
F_12 ( V_3 , V_22 , 0x03073f3f ) ;
}
F_12 ( V_3 , V_23 , 0x3 ) ;
F_12 ( V_3 , V_24 , 0x02222 ) ;
V_11 = F_13 ( V_3 -> V_11 ) ;
if ( ( V_3 -> V_18 >= 1 ) || ( V_11 >= 90000000 ) ) {
V_9 = 0x47 ;
V_10 = 0x47 ;
} else {
V_9 = 0x27 ;
V_10 = 0x43 ;
}
F_9 ( L_5 , V_9 , V_10 ) ;
F_12 ( V_3 , F_14 ( V_25 ) , V_9 ) ;
F_12 ( V_3 , F_14 ( V_26 ) , V_9 ) ;
F_12 ( V_3 , F_15 ( V_27 ) , V_10 ) ;
F_12 ( V_3 , F_15 ( V_28 ) , V_10 ) ;
F_12 ( V_3 , F_15 ( V_29 ) , V_10 ) ;
F_12 ( V_3 , F_15 ( V_30 ) , V_10 ) ;
if ( V_3 -> V_18 >= 2 )
F_12 ( V_3 , V_31 , 1 ) ;
F_12 ( V_3 , V_32 , 0 ) ;
F_12 ( V_3 , F_16 ( V_27 ) , 0 ) ;
F_12 ( V_3 , F_16 ( V_28 ) , 0 ) ;
F_12 ( V_3 , V_33 , 0 ) ;
F_12 ( V_3 , V_34 , 0 ) ;
F_12 ( V_3 , F_17 ( 1 ) , 0 ) ;
F_12 ( V_3 , F_17 ( 2 ) , 0 ) ;
if ( V_3 -> V_18 > 1 )
F_12 ( V_3 , V_35 , 1 ) ;
V_5 -> V_36 . V_37 = true ;
V_17:
F_18 ( V_5 -> V_5 ) ;
return V_12 ;
}
static void F_19 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
int V_40 , V_41 = V_39 -> V_5 -> V_36 . V_42 ;
F_5 ( V_3 ) ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
struct V_43 * V_44 = V_39 -> V_45 [ V_40 ] ;
if ( ! V_44 )
continue;
F_20 ( V_44 ) ;
}
}
static void F_21 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
int V_40 , V_41 = V_39 -> V_5 -> V_36 . V_42 ;
for ( V_40 = 0 ; V_40 < V_41 ; V_40 ++ ) {
struct V_43 * V_44 = V_39 -> V_45 [ V_40 ] ;
if ( ! V_44 )
continue;
F_22 ( V_44 ) ;
}
F_7 ( V_3 ) ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
F_24 ( V_44 ) ;
}
static long F_25 ( struct V_1 * V_2 , unsigned long V_46 ,
struct V_47 * V_48 )
{
switch ( V_48 -> V_49 ) {
case V_50 :
return F_26 ( V_48 , V_46 ) ;
case V_51 :
case V_52 :
default:
return V_46 ;
}
}
static void F_27 ( struct V_1 * V_2 , struct V_53 * V_54 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_55 * V_56 = V_3 -> V_5 -> V_57 ;
unsigned V_40 ;
for ( V_40 = 0 ; V_40 < V_56 -> V_58 ; V_40 ++ )
F_28 ( V_56 -> V_45 [ V_40 ] , V_54 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
if ( V_3 -> V_59 )
F_30 ( V_3 -> V_60 , V_3 -> V_61 ) ;
if ( V_3 -> V_60 )
F_31 ( V_3 -> V_60 ) ;
F_32 ( V_3 ) ;
}
int F_7 ( struct V_3 * V_3 )
{
F_9 ( L_6 ) ;
F_33 ( V_3 -> V_11 ) ;
if ( V_3 -> V_62 )
F_33 ( V_3 -> V_62 ) ;
F_33 ( V_3 -> V_63 ) ;
if ( V_3 -> V_64 )
F_33 ( V_3 -> V_64 ) ;
return 0 ;
}
int F_5 ( struct V_3 * V_3 )
{
F_9 ( L_6 ) ;
F_34 ( V_3 -> V_11 ) ;
if ( V_3 -> V_62 )
F_34 ( V_3 -> V_62 ) ;
F_34 ( V_3 -> V_63 ) ;
if ( V_3 -> V_64 )
F_34 ( V_3 -> V_64 ) ;
return 0 ;
}
static struct V_65 * F_35 ( struct V_4 * V_5 )
{
struct V_65 * V_66 , * V_67 ;
struct V_65 * V_68 = V_5 -> V_5 -> V_69 ;
V_66 = F_36 ( V_68 , NULL ) ;
if ( ! V_66 ) {
F_9 ( L_7 ) ;
return NULL ;
}
V_67 = F_37 ( V_66 ) ;
if ( ! V_67 ) {
F_10 ( V_5 -> V_5 , L_8 ) ;
F_38 ( V_66 ) ;
return F_39 ( - V_70 ) ;
}
F_38 ( V_66 ) ;
return V_67 ;
}
static int F_40 ( struct V_3 * V_3 ,
int V_71 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_55 * V_56 = V_5 -> V_57 ;
struct V_47 * V_48 ;
struct V_72 * V_73 ;
struct V_65 * V_67 ;
struct V_47 * V_74 [ V_75 ] ;
int V_40 , V_76 ;
int V_12 ;
switch ( V_71 ) {
case V_51 :
V_67 = F_35 ( V_5 ) ;
if ( F_41 ( V_67 ) )
return F_42 ( V_67 ) ;
V_48 = F_43 ( V_5 , V_67 ) ;
if ( F_44 ( V_48 ) ) {
F_10 ( V_5 -> V_5 , L_9 ) ;
return F_42 ( V_48 ) ;
}
V_48 -> V_77 = 1 << V_25 ;
V_73 = F_45 ( V_5 , V_67 , V_48 ) ;
if ( F_44 ( V_73 ) ) {
F_10 ( V_5 -> V_5 , L_10 ) ;
return F_42 ( V_73 ) ;
}
V_56 -> V_78 [ V_56 -> V_79 ++ ] = V_48 ;
V_56 -> V_80 [ V_56 -> V_81 ++ ] = V_73 ;
break;
case V_50 :
V_48 = F_46 ( V_5 ) ;
if ( F_44 ( V_48 ) ) {
F_10 ( V_5 -> V_5 , L_11 ) ;
return F_42 ( V_48 ) ;
}
V_48 -> V_77 = 1 << 1 ;
if ( V_56 -> V_82 ) {
V_12 = F_47 ( V_56 -> V_82 , V_5 , V_48 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_12 , V_12 ) ;
return V_12 ;
}
}
V_56 -> V_78 [ V_56 -> V_79 ++ ] = V_48 ;
break;
case V_52 :
V_76 = 0 ;
if ( ! V_56 -> V_83 [ V_76 ] )
break;
for ( V_40 = 0 ; V_40 < V_75 ; V_40 ++ ) {
V_74 [ V_40 ] = F_48 ( V_5 ) ;
if ( F_44 ( V_74 [ V_40 ] ) ) {
V_12 = F_42 ( V_74 [ V_40 ] ) ;
F_10 ( V_5 -> V_5 ,
L_13 ,
V_12 ) ;
return V_12 ;
}
V_74 [ V_40 ] -> V_77 = 1 << V_25 ;
V_56 -> V_78 [ V_56 -> V_79 ++ ] = V_74 [ V_40 ] ;
}
V_12 = F_49 ( V_56 -> V_83 [ V_76 ] , V_5 , V_74 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_14 ,
V_12 ) ;
return V_12 ;
}
break;
default:
F_10 ( V_5 -> V_5 , L_15 ) ;
return - V_84 ;
}
return 0 ;
}
static int F_50 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_55 * V_56 = V_5 -> V_57 ;
struct V_85 * V_86 ;
struct V_43 * V_44 ;
int V_40 , V_12 ;
static const enum V_87 V_88 [] = {
V_29 , V_30 ,
} ;
static const enum V_87 V_89 [] = {
V_27 , V_28 ,
} ;
static const enum V_90 V_91 [] = {
V_25 , V_26 ,
} ;
static const char * const V_92 [] = {
L_16 , L_17 ,
} ;
static const int V_93 [] = {
V_51 ,
V_52 ,
V_50 ,
} ;
for ( V_40 = 0 ; V_40 < F_51 ( V_89 ) ; V_40 ++ ) {
V_86 = F_52 ( V_5 , V_89 [ V_40 ] , false ) ;
if ( F_44 ( V_86 ) ) {
F_10 ( V_5 -> V_5 ,
L_18 , V_40 + 1 ) ;
V_12 = F_42 ( V_86 ) ;
goto V_94;
}
V_56 -> V_95 [ V_56 -> V_96 ++ ] = V_86 ;
}
for ( V_40 = 0 ; V_40 < F_51 ( V_91 ) ; V_40 ++ ) {
V_86 = F_52 ( V_5 , V_88 [ V_40 ] , true ) ;
if ( F_44 ( V_86 ) ) {
F_10 ( V_5 -> V_5 ,
L_19 , V_40 + 1 ) ;
V_12 = F_42 ( V_86 ) ;
goto V_94;
}
V_44 = F_53 ( V_5 , V_86 , V_56 -> V_58 , V_40 ,
V_91 [ V_40 ] ) ;
if ( F_44 ( V_44 ) ) {
F_10 ( V_5 -> V_5 , L_20 ,
V_92 [ V_40 ] ) ;
V_12 = F_42 ( V_44 ) ;
goto V_94;
}
V_56 -> V_45 [ V_56 -> V_58 ++ ] = V_44 ;
}
for ( V_40 = 0 ; V_40 < F_51 ( V_93 ) ; V_40 ++ ) {
V_12 = F_40 ( V_3 , V_93 [ V_40 ] ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_21 ,
V_40 , V_12 ) ;
goto V_94;
}
}
return 0 ;
V_94:
return V_12 ;
}
struct V_1 * F_54 ( struct V_4 * V_5 )
{
struct V_97 * V_98 = V_5 -> V_99 ;
struct V_100 * V_101 = F_55 ( V_98 ) ;
struct V_3 * V_3 ;
struct V_1 * V_2 = NULL ;
struct V_102 * V_103 ;
int V_12 ;
V_3 = F_56 ( sizeof( * V_3 ) , V_104 ) ;
if ( ! V_3 ) {
F_10 ( V_5 -> V_5 , L_22 ) ;
V_12 = - V_105 ;
goto V_94;
}
F_57 ( & V_3 -> V_106 , & V_107 ) ;
V_2 = & V_3 -> V_106 . V_106 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_108 = F_58 ( V_98 , NULL , L_23 ) ;
if ( F_44 ( V_3 -> V_108 ) ) {
V_12 = F_42 ( V_3 -> V_108 ) ;
goto V_94;
}
V_3 -> V_19 =
F_59 ( & V_98 -> V_5 , L_24 ) ;
if ( F_44 ( V_3 -> V_19 ) )
V_3 -> V_19 = NULL ;
V_3 -> V_20 =
F_59 ( & V_98 -> V_5 , L_25 ) ;
if ( F_44 ( V_3 -> V_20 ) )
V_3 -> V_20 = NULL ;
V_3 -> V_109 = F_60 ( & V_98 -> V_5 , L_26 ) ;
if ( F_44 ( V_3 -> V_109 ) )
V_3 -> V_109 = NULL ;
if ( V_3 -> V_109 ) {
V_12 = F_61 ( V_3 -> V_109 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_27 , V_12 ) ;
goto V_94;
}
}
V_3 -> V_11 = F_62 ( & V_98 -> V_5 , L_28 ) ;
if ( F_44 ( V_3 -> V_11 ) ) {
F_10 ( V_5 -> V_5 , L_29 ) ;
V_12 = F_42 ( V_3 -> V_11 ) ;
goto V_94;
}
V_3 -> V_62 = F_62 ( & V_98 -> V_5 , L_30 ) ;
if ( F_44 ( V_3 -> V_62 ) )
V_3 -> V_62 = NULL ;
V_3 -> V_63 = F_62 ( & V_98 -> V_5 , L_31 ) ;
if ( F_44 ( V_3 -> V_63 ) ) {
F_10 ( V_5 -> V_5 , L_32 ) ;
V_12 = F_42 ( V_3 -> V_63 ) ;
goto V_94;
}
V_3 -> V_64 = F_62 ( & V_98 -> V_5 , L_33 ) ;
if ( F_44 ( V_3 -> V_64 ) ) {
F_10 ( V_5 -> V_5 , L_34 ) ;
V_12 = F_42 ( V_3 -> V_64 ) ;
goto V_94;
}
F_63 ( V_3 -> V_11 , V_101 -> V_110 ) ;
F_63 ( V_3 -> V_63 , V_101 -> V_110 ) ;
F_5 ( V_3 ) ;
F_12 ( V_3 , V_111 , 0 ) ;
F_12 ( V_3 , V_112 , 0 ) ;
F_12 ( V_3 , V_113 , 0 ) ;
F_7 ( V_3 ) ;
F_64 ( 16 ) ;
if ( V_101 -> V_114 ) {
V_103 = F_65 ( & V_98 -> V_5 , V_101 -> V_114 ) ;
if ( F_44 ( V_103 ) ) {
V_12 = F_42 ( V_103 ) ;
goto V_94;
}
V_12 = V_103 -> V_115 -> V_116 ( V_103 , V_117 ,
F_51 ( V_117 ) ) ;
if ( V_12 )
goto V_94;
} else {
F_66 ( V_5 -> V_5 , L_35
L_36 ) ;
V_103 = NULL ;
}
V_3 -> V_61 = F_67 ( V_5 , V_103 ) ;
if ( V_3 -> V_61 < 0 ) {
V_12 = V_3 -> V_61 ;
F_10 ( V_5 -> V_5 , L_37 , V_12 ) ;
goto V_94;
}
V_12 = F_50 ( V_3 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_38 , V_12 ) ;
goto V_94;
}
F_68 ( & V_5 -> V_118 ) ;
V_3 -> V_60 = F_69 ( V_5 , V_119 , V_120 ) ;
F_70 ( & V_5 -> V_118 ) ;
if ( F_44 ( V_3 -> V_60 ) ) {
V_12 = F_42 ( V_3 -> V_60 ) ;
F_10 ( V_5 -> V_5 , L_39 , V_12 ) ;
V_3 -> V_60 = NULL ;
goto V_94;
}
V_12 = F_71 ( V_3 -> V_60 , V_3 -> V_61 ,
& V_3 -> V_59 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_40 , V_12 ) ;
goto V_94;
}
V_5 -> V_36 . V_121 = 0 ;
V_5 -> V_36 . V_122 = 0 ;
V_5 -> V_36 . V_123 = 2048 ;
V_5 -> V_36 . V_124 = 2048 ;
return V_2 ;
V_94:
if ( V_2 )
F_29 ( V_2 ) ;
return F_39 ( V_12 ) ;
}
static struct V_100 * F_55 ( struct V_97 * V_5 )
{
static struct V_100 V_101 = {} ;
V_101 . V_110 = 266667000 ;
V_101 . V_114 = F_72 ( & V_125 ) ;
return & V_101 ;
}
