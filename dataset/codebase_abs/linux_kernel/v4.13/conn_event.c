static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_7 * V_8 ;
struct V_9 V_10 ;
struct V_11 V_12 ;
struct {
struct V_13 V_14 ;
union {
struct {
T_1 V_15 ;
} abort ;
struct {
struct V_16 V_17 ;
T_2 V_18 [ 3 ] ;
struct V_19 V_20 ;
};
};
} V_21 ( ( V_22 ) ) V_23 ;
T_3 V_24 ;
T_4 V_25 , V_26 , V_27 ;
F_3 ( L_1 , V_2 -> V_28 ) ;
V_8 = & V_2 -> V_29 [ V_6 -> V_30 . V_31 & V_32 ] ;
V_27 = F_4 ( V_8 -> V_33 ) ;
F_5 () ;
if ( V_27 != V_6 -> V_30 . V_34 )
return;
V_10 . V_35 = & V_2 -> V_36 . V_37 -> V_38 . V_39 ;
V_10 . V_40 = V_2 -> V_36 . V_37 -> V_38 . V_41 ;
V_10 . V_42 = NULL ;
V_10 . V_43 = 0 ;
V_10 . V_44 = 0 ;
V_23 . V_14 . V_45 = F_6 ( V_6 -> V_30 . V_45 ) ;
V_23 . V_14 . V_31 = F_6 ( V_6 -> V_30 . V_31 ) ;
V_23 . V_14 . V_34 = F_6 ( V_6 -> V_30 . V_34 ) ;
V_23 . V_14 . V_46 = 0 ;
V_23 . V_14 . type = V_8 -> V_47 ;
V_23 . V_14 . V_48 = V_2 -> V_49 ;
V_23 . V_14 . V_50 = 0 ;
V_23 . V_14 . V_51 = V_2 -> V_52 ;
V_23 . V_14 . V_53 = 0 ;
V_23 . V_14 . V_54 = F_7 ( V_2 -> V_55 ) ;
V_24 = sizeof( V_23 . V_14 ) ;
switch ( V_8 -> V_47 ) {
case V_56 :
V_23 . abort . V_15 = F_6 ( V_8 -> V_57 ) ;
V_24 += sizeof( V_23 . abort ) ;
break;
case V_58 :
V_26 = V_2 -> V_36 . V_37 -> V_59 ;
V_26 -= V_2 -> V_36 . V_37 -> V_60 ;
V_23 . V_17 . V_61 = 0 ;
V_23 . V_17 . V_62 = F_7 ( V_4 -> V_63 ) ;
V_23 . V_17 . V_64 = F_6 ( V_8 -> V_65 ) ;
V_23 . V_17 . V_66 = F_6 ( V_8 -> V_65 - 1 ) ;
V_23 . V_17 . V_25 = F_6 ( V_6 -> V_30 . V_25 ) ;
V_23 . V_17 . V_67 = V_68 ;
V_23 . V_17 . V_69 = 0 ;
V_23 . V_20 . V_70 = F_6 ( V_71 ) ;
V_23 . V_20 . V_72 = F_6 ( V_26 ) ;
V_23 . V_20 . V_73 = F_6 ( V_74 ) ;
V_23 . V_20 . V_75 = F_6 ( V_76 ) ;
V_23 . V_14 . V_48 |= V_77 ;
V_24 += sizeof( V_23 . V_17 ) + sizeof( V_23 . V_20 ) ;
break;
}
F_5 () ;
if ( F_4 ( V_8 -> V_33 ) != V_27 )
return;
V_12 . V_78 = & V_23 ;
V_12 . V_79 = V_24 ;
V_25 = F_8 ( & V_2 -> V_25 ) ;
V_23 . V_14 . V_25 = F_6 ( V_25 ) ;
switch ( V_8 -> V_47 ) {
case V_56 :
F_9 ( L_2 , V_25 , V_2 -> V_80 ) ;
break;
case V_58 :
F_10 ( NULL , V_25 , V_8 -> V_65 , 0 ,
V_68 , 0 ) ;
F_9 ( L_3 , V_25 ) ;
break;
}
F_11 ( V_2 -> V_36 . V_81 -> V_82 , & V_10 , & V_12 , 1 , V_24 ) ;
F_12 ( L_4 ) ;
return;
}
static void F_13 ( struct V_1 * V_2 ,
enum V_83 V_84 ,
T_4 V_85 , int error )
{
struct V_86 * V_87 ;
int V_88 ;
F_3 ( L_5 , V_2 -> V_28 , V_85 ) ;
F_14 ( & V_2 -> V_89 ) ;
for ( V_88 = 0 ; V_88 < V_90 ; V_88 ++ ) {
V_87 = F_15 (
V_2 -> V_29 [ V_88 ] . V_87 ,
F_16 ( & V_2 -> V_89 ) ) ;
if ( V_87 ) {
if ( V_84 == V_91 )
F_17 ( L_6 , V_87 -> V_31 ,
V_87 -> V_27 , 0 ,
V_85 , error ) ;
if ( F_18 ( V_87 , V_84 ,
V_85 , error ) )
F_19 ( V_87 ) ;
}
}
F_20 ( & V_2 -> V_89 ) ;
F_12 ( L_4 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
int error , T_4 V_85 )
{
struct V_13 V_14 ;
struct V_9 V_10 ;
struct V_11 V_12 [ 2 ] ;
T_1 V_92 ;
T_3 V_24 ;
T_4 V_25 ;
int V_93 ;
F_3 ( L_7 , V_2 -> V_28 , error , V_85 ) ;
F_22 ( & V_2 -> V_94 ) ;
if ( V_2 -> V_95 >= V_96 ) {
F_23 ( & V_2 -> V_94 ) ;
F_12 ( L_8 ) ;
return 0 ;
}
V_2 -> V_95 = V_97 ;
F_23 ( & V_2 -> V_94 ) ;
F_13 ( V_2 , V_91 , V_85 , error ) ;
V_10 . V_35 = & V_2 -> V_36 . V_37 -> V_38 . V_39 ;
V_10 . V_40 = V_2 -> V_36 . V_37 -> V_38 . V_41 ;
V_10 . V_42 = NULL ;
V_10 . V_43 = 0 ;
V_10 . V_44 = 0 ;
V_14 . V_45 = F_6 ( V_2 -> V_98 . V_45 ) ;
V_14 . V_31 = F_6 ( V_2 -> V_98 . V_31 ) ;
V_14 . V_34 = 0 ;
V_14 . V_46 = 0 ;
V_14 . type = V_56 ;
V_14 . V_48 = V_2 -> V_49 ;
V_14 . V_50 = 0 ;
V_14 . V_51 = V_2 -> V_52 ;
V_14 . V_53 = 0 ;
V_14 . V_54 = F_7 ( V_2 -> V_55 ) ;
V_92 = F_6 ( V_2 -> V_80 ) ;
V_12 [ 0 ] . V_78 = & V_14 ;
V_12 [ 0 ] . V_79 = sizeof( V_14 ) ;
V_12 [ 1 ] . V_78 = & V_92 ;
V_12 [ 1 ] . V_79 = sizeof( V_92 ) ;
V_24 = V_12 [ 0 ] . V_79 + V_12 [ 1 ] . V_79 ;
V_25 = F_8 ( & V_2 -> V_25 ) ;
V_14 . V_25 = F_6 ( V_25 ) ;
F_9 ( L_9 , V_25 , V_2 -> V_80 ) ;
V_93 = F_11 ( V_2 -> V_36 . V_81 -> V_82 , & V_10 , V_12 , 2 , V_24 ) ;
if ( V_93 < 0 ) {
F_24 ( L_10 , V_93 ) ;
return - V_99 ;
}
F_12 ( L_11 ) ;
return 0 ;
}
static void F_25 ( struct V_86 * V_87 )
{
F_3 ( L_12 , V_87 ) ;
if ( V_87 ) {
F_26 ( & V_87 -> V_94 ) ;
if ( V_87 -> V_95 == V_100 ) {
V_87 -> V_95 = V_101 ;
F_19 ( V_87 ) ;
}
F_27 ( & V_87 -> V_94 ) ;
}
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_4 * V_102 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
T_1 V_103 ;
T_4 V_85 ;
int V_104 , V_93 ;
if ( V_2 -> V_95 >= V_96 ) {
F_12 ( L_13 , V_2 -> V_95 ) ;
return - V_105 ;
}
F_3 ( L_14 , V_2 -> V_28 , V_6 -> V_30 . type , V_6 -> V_30 . V_25 ) ;
switch ( V_6 -> V_30 . type ) {
case V_106 :
case V_58 :
F_1 ( V_2 , V_4 ) ;
return 0 ;
case V_107 :
return 0 ;
case V_56 :
if ( F_29 ( V_4 , sizeof( struct V_13 ) ,
& V_103 , sizeof( V_103 ) ) < 0 ) {
F_30 ( NULL , V_6 -> V_30 . V_25 ,
F_31 ( L_15 ) ) ;
return - V_108 ;
}
V_85 = F_32 ( V_103 ) ;
F_9 ( L_16 , V_6 -> V_30 . V_25 , V_85 ) ;
V_2 -> V_95 = V_96 ;
F_13 ( V_2 , V_109 ,
V_85 , - V_105 ) ;
return - V_105 ;
case V_110 :
return V_2 -> V_111 -> V_112 ( V_2 , V_4 ,
V_102 ) ;
case V_113 :
V_93 = V_2 -> V_111 -> V_114 ( V_2 , V_4 , V_102 ) ;
if ( V_93 < 0 )
return V_93 ;
V_93 = V_2 -> V_111 -> V_115 ( V_2 ) ;
if ( V_93 < 0 )
return V_93 ;
V_93 = V_2 -> V_111 -> V_116 ( V_2 ) ;
if ( V_93 < 0 )
return V_93 ;
F_14 ( & V_2 -> V_89 ) ;
F_14 ( & V_2 -> V_94 ) ;
if ( V_2 -> V_95 == V_117 ) {
V_2 -> V_95 = V_118 ;
F_20 ( & V_2 -> V_94 ) ;
for ( V_104 = 0 ; V_104 < V_90 ; V_104 ++ )
F_25 (
F_15 (
V_2 -> V_29 [ V_104 ] . V_87 ,
F_16 ( & V_2 -> V_89 ) ) ) ;
} else {
F_20 ( & V_2 -> V_94 ) ;
}
F_20 ( & V_2 -> V_89 ) ;
return 0 ;
default:
F_30 ( NULL , V_6 -> V_30 . V_25 ,
F_31 ( L_17 ) ) ;
return - V_108 ;
}
}
static void F_33 ( struct V_1 * V_2 )
{
T_4 V_85 ;
int V_93 ;
F_3 ( L_18 , V_2 -> V_28 ) ;
ASSERT ( V_2 -> V_52 != 0 ) ;
if ( ! V_2 -> V_36 . V_119 ) {
F_24 ( L_19 ) ;
V_93 = F_34 ( V_2 ) ;
switch ( V_93 ) {
case 0 :
break;
case - V_120 :
V_85 = V_121 ;
goto abort;
default:
V_85 = V_122 ;
goto abort;
}
}
if ( V_2 -> V_111 -> V_123 ( V_2 ) < 0 ) {
V_85 = V_121 ;
V_93 = - V_124 ;
goto abort;
}
F_12 ( L_4 ) ;
return;
abort:
F_24 ( L_20 , V_93 , V_85 ) ;
F_21 ( V_2 , V_93 , V_85 ) ;
F_12 ( L_21 ) ;
}
void F_35 ( struct V_125 * V_126 )
{
struct V_1 * V_2 =
F_36 ( V_126 , struct V_1 , V_127 ) ;
struct V_3 * V_4 ;
T_4 V_85 = V_128 ;
int V_93 ;
F_37 ( V_2 ) ;
if ( F_38 ( V_129 , & V_2 -> V_130 ) )
F_33 ( V_2 ) ;
while ( ( V_4 = F_39 ( & V_2 -> V_131 ) ) ) {
F_40 ( V_4 , V_132 ) ;
V_93 = F_28 ( V_2 , V_4 , & V_85 ) ;
switch ( V_93 ) {
case - V_108 :
case - V_133 :
case - V_134 :
goto V_135;
case - V_99 :
goto V_136;
case - V_105 :
default:
F_41 ( V_4 , V_137 ) ;
break;
}
}
V_138:
F_42 ( V_2 ) ;
F_12 ( L_4 ) ;
return;
V_136:
F_43 ( & V_2 -> V_131 , V_4 ) ;
goto V_138;
V_135:
if ( F_21 ( V_2 , V_93 , V_85 ) < 0 )
goto V_136;
F_41 ( V_4 , V_137 ) ;
goto V_138;
}
