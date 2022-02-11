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
int V_38 , V_39 = V_37 -> V_5 -> V_34 . V_40 ;
F_5 ( V_3 ) ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
struct V_41 * V_42 = V_37 -> V_43 [ V_38 ] ;
if ( ! V_42 )
continue;
F_19 ( V_42 ) ;
}
}
static void F_20 ( struct V_1 * V_2 , struct V_36 * V_37 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
int V_38 , V_39 = V_37 -> V_5 -> V_34 . V_40 ;
for ( V_38 = 0 ; V_38 < V_39 ; V_38 ++ ) {
struct V_41 * V_42 = V_37 -> V_43 [ V_38 ] ;
if ( ! V_42 )
continue;
F_21 ( V_42 ) ;
}
F_7 ( V_3 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
F_23 ( V_42 ) ;
}
static long F_24 ( struct V_1 * V_2 , unsigned long V_44 ,
struct V_45 * V_46 )
{
switch ( V_46 -> V_47 ) {
case V_48 :
return F_25 ( V_46 , V_44 ) ;
case V_49 :
case V_50 :
default:
return V_44 ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( F_3 ( V_2 ) ) ;
struct V_51 * V_52 = V_3 -> V_52 ;
if ( V_52 ) {
V_52 -> V_53 -> V_54 ( V_52 , V_55 , F_27 ( V_55 ) ) ;
V_52 -> V_53 -> V_56 ( V_52 ) ;
}
if ( V_3 -> V_57 )
F_28 ( V_3 -> V_58 , V_3 -> V_59 ) ;
if ( V_3 -> V_58 )
F_29 ( V_3 -> V_58 ) ;
F_30 ( V_3 ) ;
}
int F_7 ( struct V_3 * V_3 )
{
F_9 ( L_4 ) ;
F_31 ( V_3 -> V_11 ) ;
if ( V_3 -> V_60 )
F_31 ( V_3 -> V_60 ) ;
F_31 ( V_3 -> V_61 ) ;
if ( V_3 -> V_62 )
F_31 ( V_3 -> V_62 ) ;
return 0 ;
}
int F_5 ( struct V_3 * V_3 )
{
F_9 ( L_4 ) ;
F_32 ( V_3 -> V_11 ) ;
if ( V_3 -> V_60 )
F_32 ( V_3 -> V_60 ) ;
F_32 ( V_3 -> V_61 ) ;
if ( V_3 -> V_62 )
F_32 ( V_3 -> V_62 ) ;
return 0 ;
}
static struct V_63 * F_33 ( struct V_4 * V_5 )
{
struct V_63 * V_64 , * V_65 ;
struct V_63 * V_66 = V_5 -> V_5 -> V_67 ;
V_64 = F_34 ( V_66 , NULL ) ;
if ( ! V_64 ) {
F_9 ( L_5 ) ;
return NULL ;
}
V_65 = F_35 ( V_64 ) ;
if ( ! V_65 ) {
F_10 ( V_5 -> V_5 , L_6 ) ;
F_36 ( V_64 ) ;
return F_37 ( - V_68 ) ;
}
F_36 ( V_64 ) ;
return V_65 ;
}
static int F_38 ( struct V_3 * V_3 ,
int V_69 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_70 * V_71 = V_5 -> V_72 ;
struct V_45 * V_46 ;
struct V_73 * V_74 ;
struct V_63 * V_65 ;
struct V_45 * V_75 [ V_76 ] ;
int V_38 , V_77 ;
int V_12 ;
switch ( V_69 ) {
case V_49 :
V_65 = F_33 ( V_5 ) ;
if ( F_39 ( V_65 ) )
return F_40 ( V_65 ) ;
V_46 = F_41 ( V_5 , V_65 ) ;
if ( F_42 ( V_46 ) ) {
F_10 ( V_5 -> V_5 , L_7 ) ;
return F_40 ( V_46 ) ;
}
V_46 -> V_78 = 1 << V_23 ;
V_74 = F_43 ( V_5 , V_65 , V_46 ) ;
if ( F_42 ( V_74 ) ) {
F_10 ( V_5 -> V_5 , L_8 ) ;
return F_40 ( V_74 ) ;
}
V_71 -> V_79 [ V_71 -> V_80 ++ ] = V_46 ;
V_71 -> V_81 [ V_71 -> V_82 ++ ] = V_74 ;
break;
case V_48 :
V_46 = F_44 ( V_5 ) ;
if ( F_42 ( V_46 ) ) {
F_10 ( V_5 -> V_5 , L_9 ) ;
return F_40 ( V_46 ) ;
}
V_46 -> V_78 = 1 << 1 ;
if ( V_71 -> V_83 ) {
V_12 = F_45 ( V_71 -> V_83 , V_5 , V_46 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_10 , V_12 ) ;
return V_12 ;
}
}
V_71 -> V_79 [ V_71 -> V_80 ++ ] = V_46 ;
break;
case V_50 :
V_77 = 0 ;
if ( ! V_71 -> V_84 [ V_77 ] )
break;
for ( V_38 = 0 ; V_38 < V_76 ; V_38 ++ ) {
V_75 [ V_38 ] = F_46 ( V_5 ) ;
if ( F_42 ( V_75 [ V_38 ] ) ) {
V_12 = F_40 ( V_75 [ V_38 ] ) ;
F_10 ( V_5 -> V_5 ,
L_11 ,
V_12 ) ;
return V_12 ;
}
V_75 [ V_38 ] -> V_78 = 1 << V_23 ;
V_71 -> V_79 [ V_71 -> V_80 ++ ] = V_75 [ V_38 ] ;
}
V_12 = F_47 ( V_71 -> V_84 [ V_77 ] , V_5 , V_75 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_12 ,
V_12 ) ;
return V_12 ;
}
break;
default:
F_10 ( V_5 -> V_5 , L_13 ) ;
return - V_85 ;
}
return 0 ;
}
static int F_48 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_5 ;
struct V_70 * V_71 = V_5 -> V_72 ;
struct V_86 * V_87 ;
struct V_41 * V_42 ;
int V_38 , V_12 ;
static const enum V_88 V_89 [] = {
V_27 , V_28 ,
} ;
static const enum V_88 V_90 [] = {
V_25 , V_26 ,
} ;
static const enum V_91 V_92 [] = {
V_23 , V_24 ,
} ;
static const char * const V_93 [] = {
L_14 , L_15 ,
} ;
static const int V_94 [] = {
V_49 ,
V_50 ,
V_48 ,
} ;
for ( V_38 = 0 ; V_38 < F_27 ( V_90 ) ; V_38 ++ ) {
V_87 = F_49 ( V_5 , V_90 [ V_38 ] , false ) ;
if ( F_42 ( V_87 ) ) {
F_10 ( V_5 -> V_5 ,
L_16 , V_38 + 1 ) ;
V_12 = F_40 ( V_87 ) ;
goto V_95;
}
V_71 -> V_96 [ V_71 -> V_97 ++ ] = V_87 ;
}
for ( V_38 = 0 ; V_38 < F_27 ( V_92 ) ; V_38 ++ ) {
V_87 = F_49 ( V_5 , V_89 [ V_38 ] , true ) ;
if ( F_42 ( V_87 ) ) {
F_10 ( V_5 -> V_5 ,
L_17 , V_38 + 1 ) ;
V_12 = F_40 ( V_87 ) ;
goto V_95;
}
V_42 = F_50 ( V_5 , V_87 , V_71 -> V_98 , V_38 ,
V_92 [ V_38 ] ) ;
if ( F_42 ( V_42 ) ) {
F_10 ( V_5 -> V_5 , L_18 ,
V_93 [ V_38 ] ) ;
V_12 = F_40 ( V_42 ) ;
goto V_95;
}
V_71 -> V_43 [ V_71 -> V_98 ++ ] = V_42 ;
}
for ( V_38 = 0 ; V_38 < F_27 ( V_94 ) ; V_38 ++ ) {
V_12 = F_38 ( V_3 , V_94 [ V_38 ] ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_19 ,
V_38 , V_12 ) ;
goto V_95;
}
}
return 0 ;
V_95:
return V_12 ;
}
struct V_1 * F_51 ( struct V_4 * V_5 )
{
struct V_99 * V_100 = V_5 -> V_101 ;
struct V_102 * V_103 = F_52 ( V_100 ) ;
struct V_3 * V_3 ;
struct V_1 * V_2 = NULL ;
struct V_51 * V_52 ;
int V_12 ;
V_3 = F_53 ( sizeof( * V_3 ) , V_104 ) ;
if ( ! V_3 ) {
F_10 ( V_5 -> V_5 , L_20 ) ;
V_12 = - V_105 ;
goto V_95;
}
F_54 ( & V_3 -> V_106 , & V_107 ) ;
V_2 = & V_3 -> V_106 . V_106 ;
V_3 -> V_5 = V_5 ;
V_3 -> V_108 = F_55 ( V_100 , NULL , L_21 ) ;
if ( F_42 ( V_3 -> V_108 ) ) {
V_12 = F_40 ( V_3 -> V_108 ) ;
goto V_95;
}
V_3 -> V_109 = F_56 ( & V_100 -> V_5 , L_22 ) ;
if ( F_42 ( V_3 -> V_109 ) )
V_3 -> V_109 = NULL ;
if ( V_3 -> V_109 ) {
V_12 = F_57 ( V_3 -> V_109 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_23 , V_12 ) ;
goto V_95;
}
}
V_3 -> V_11 = F_58 ( & V_100 -> V_5 , L_24 ) ;
if ( F_42 ( V_3 -> V_11 ) ) {
F_10 ( V_5 -> V_5 , L_25 ) ;
V_12 = F_40 ( V_3 -> V_11 ) ;
goto V_95;
}
V_3 -> V_60 = F_58 ( & V_100 -> V_5 , L_26 ) ;
if ( F_42 ( V_3 -> V_60 ) )
V_3 -> V_60 = NULL ;
V_3 -> V_61 = F_58 ( & V_100 -> V_5 , L_27 ) ;
if ( F_42 ( V_3 -> V_61 ) ) {
F_10 ( V_5 -> V_5 , L_28 ) ;
V_12 = F_40 ( V_3 -> V_61 ) ;
goto V_95;
}
V_3 -> V_62 = F_58 ( & V_100 -> V_5 , L_29 ) ;
if ( F_42 ( V_3 -> V_62 ) ) {
F_10 ( V_5 -> V_5 , L_30 ) ;
V_12 = F_40 ( V_3 -> V_62 ) ;
goto V_95;
}
F_59 ( V_3 -> V_11 , V_103 -> V_110 ) ;
F_59 ( V_3 -> V_61 , V_103 -> V_110 ) ;
F_5 ( V_3 ) ;
F_11 ( V_3 , V_111 , 0 ) ;
F_11 ( V_3 , V_112 , 0 ) ;
F_11 ( V_3 , V_113 , 0 ) ;
F_7 ( V_3 ) ;
F_60 ( 16 ) ;
if ( V_103 -> V_114 ) {
V_52 = F_61 ( & V_100 -> V_5 , V_103 -> V_114 ) ;
if ( F_42 ( V_52 ) ) {
V_12 = F_40 ( V_52 ) ;
goto V_95;
}
V_12 = V_52 -> V_53 -> V_115 ( V_52 , V_55 ,
F_27 ( V_55 ) ) ;
if ( V_12 )
goto V_95;
V_3 -> V_52 = V_52 ;
} else {
F_62 ( V_5 -> V_5 , L_31
L_32 ) ;
V_52 = NULL ;
}
V_3 -> V_59 = F_63 ( V_5 , V_52 ) ;
if ( V_3 -> V_59 < 0 ) {
V_12 = V_3 -> V_59 ;
F_10 ( V_5 -> V_5 , L_33 , V_12 ) ;
goto V_95;
}
V_12 = F_48 ( V_3 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_34 , V_12 ) ;
goto V_95;
}
F_64 ( & V_5 -> V_116 ) ;
V_3 -> V_58 = F_65 ( V_5 , V_117 , V_118 ) ;
F_66 ( & V_5 -> V_116 ) ;
if ( F_42 ( V_3 -> V_58 ) ) {
V_12 = F_40 ( V_3 -> V_58 ) ;
F_10 ( V_5 -> V_5 , L_35 , V_12 ) ;
V_3 -> V_58 = NULL ;
goto V_95;
}
V_12 = F_67 ( V_3 -> V_58 , V_3 -> V_59 ,
& V_3 -> V_57 ) ;
if ( V_12 ) {
F_10 ( V_5 -> V_5 , L_36 , V_12 ) ;
goto V_95;
}
V_5 -> V_34 . V_119 = 0 ;
V_5 -> V_34 . V_120 = 0 ;
V_5 -> V_34 . V_121 = 2048 ;
V_5 -> V_34 . V_122 = 2048 ;
return V_2 ;
V_95:
if ( V_2 )
F_26 ( V_2 ) ;
return F_37 ( V_12 ) ;
}
static struct V_102 * F_52 ( struct V_99 * V_5 )
{
static struct V_102 V_103 = {} ;
V_103 . V_110 = 266667000 ;
V_103 . V_114 = F_68 ( & V_123 ) ;
return & V_103 ;
}
