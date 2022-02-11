static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
if ( ( ! V_2 -> V_8 ) || ( V_2 -> V_9 ) ||
( V_2 -> V_10 ) ) {
F_2 ( L_1 ,
V_2 -> V_8 , V_2 -> V_9 ,
V_2 -> V_10 ) ;
goto V_11;
}
F_3 ( V_2 ) ;
F_2 ( L_2 ) ;
F_4 ( & V_4 -> F_4 ) ;
V_4 -> V_12 = true ;
if ( V_7 ) {
F_5 ( V_7 ) ;
F_6 ( V_7 ) ;
}
F_7 ( V_2 , 500 , false ) ;
{
struct V_13 * V_14 = & V_2 -> V_15 ;
if ( F_8 ( V_14 , V_16 ) ) {
F_9 ( V_14 , V_16 ) ;
F_10 ( V_2 , V_17 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 , V_18 , 0 ) ;
}
}
F_13 ( V_2 ) ;
F_14 ( V_2 , true ) ;
F_15 ( V_2 ) ;
V_4 -> V_19 = V_20 ;
V_4 -> V_12 = false ;
F_16 ( & V_4 -> F_4 ) ;
return 0 ;
V_11:
F_2 ( L_3 , V_21 ) ;
return - 1 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( L_4 ) ;
F_4 ( & V_4 -> F_4 ) ;
V_4 -> V_12 = true ;
F_18 ( V_2 ) ;
if ( F_19 ( V_7 , false ) != 0 ) {
F_16 ( & V_4 -> F_4 ) ;
goto V_11;
}
F_20 ( V_7 ) ;
F_21 ( V_7 ) ;
if ( ! F_22 ( V_7 ) )
F_23 ( V_7 ) ;
else
F_24 ( V_7 ) ;
V_4 -> V_22 = false ;
V_4 -> V_23 = false ;
V_4 -> V_19 = V_24 ;
V_4 -> V_12 = false ;
F_16 ( & V_4 -> F_4 ) ;
return 0 ;
V_11:
F_2 ( L_5 , V_21 ) ;
return - 1 ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_25 * V_26 = & V_2 -> V_27 ;
if ( V_2 -> V_28 . V_29 == 1 )
return;
if ( V_26 -> V_30 != V_31 ||
V_26 -> V_32 != V_33 ) {
F_26 ( V_34 , L_6 ) ;
F_26 ( V_34 , L_7 ,
V_26 -> V_30 , V_26 -> V_32 ) ;
return;
}
F_4 ( & V_4 -> F_4 ) ;
V_4 -> V_12 = true ;
V_4 -> V_35 = V_4 -> V_36 ;
V_4 -> V_37 ++ ;
F_2 ( L_8 , V_4 -> V_37 ) ;
if ( V_20 == V_4 -> V_38 ) {
V_4 -> V_39 = true ;
F_26 ( V_34 , L_9 ) ;
if ( V_4 -> V_35 == V_40 )
V_4 -> V_22 = true ;
F_27 ( V_2 ) ;
V_4 -> V_19 = V_20 ;
}
V_4 -> V_12 = false ;
F_16 ( & V_4 -> F_4 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_41 * V_42 = & ( V_2 -> V_43 ) ;
struct V_13 * V_14 = & ( V_2 -> V_15 ) ;
int V_44 = V_45 ;
int V_46 ;
F_4 ( & V_4 -> F_4 ) ;
if ( ( V_4 -> V_19 == V_20 ) && ( ! V_4 -> V_12 ) ) {
V_4 -> V_12 = true ;
V_4 -> V_38 = V_24 ;
V_4 -> V_47 ++ ;
F_2 ( L_10 , V_4 -> V_47 ) ;
V_44 = F_29 ( V_2 ) ;
if ( V_44 == V_45 ) {
V_4 -> V_19 = V_24 ;
}
F_26 ( V_34 , L_11 ) ;
if ( ( V_48 == V_42 -> V_49 ) || ( V_50 == V_42 -> V_49 ) ) {
F_2 ( L_12 , V_21 , V_2 -> V_51 . V_52 , V_4 -> V_12 ) ;
F_30 ( V_2 , V_2 -> V_51 . V_52 , V_53 , V_54 ) ;
for ( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
if ( V_14 -> V_55 & F_31 ( V_46 ) ) {
if ( V_46 == V_42 -> V_56 )
V_44 = F_32 ( V_2 , V_42 , V_46 , 1 ) ;
else
V_44 = F_32 ( V_2 , V_42 , V_46 , 0 ) ;
}
}
}
F_2 ( L_13 , F_33 ( V_2 , 0x4c ) ) ;
V_4 -> V_12 = false ;
V_4 -> V_22 = false ;
V_4 -> V_39 = false ;
}
F_16 ( & V_4 -> F_4 ) ;
return V_44 ;
}
static bool F_34 ( struct V_1 * V_1 )
{
struct V_13 * V_14 = & ( V_1 -> V_15 ) ;
bool V_57 = false ;
if ( F_35 ( V_1 -> V_5 . V_58 , V_59 ) )
goto exit;
if ( F_8 ( V_14 , V_60 | V_61 ) ||
F_8 ( V_14 , V_62 | V_63 ) ||
F_8 ( V_14 , V_64 ) ||
F_8 ( V_14 , V_65 | V_66 ) )
goto exit;
V_57 = true ;
exit:
return V_57 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_13 * V_14 = & ( V_2 -> V_15 ) ;
enum V_67 V_68 ;
V_4 -> V_69 = true ;
if ( V_4 -> V_12 )
goto exit;
if ( V_2 -> V_5 . V_70 ) {
V_68 = F_37 ( V_2 ) ;
F_2 ( L_14 , V_21 , ( V_68 == V_24 ) ? L_15 : L_16 ) ;
if ( V_68 != V_4 -> V_19 ) {
if ( V_68 == V_20 ) {
V_4 -> V_38 = V_20 ;
V_4 -> V_23 = true ;
F_1 ( V_2 ) ;
} else {
V_4 -> V_38 = V_24 ;
F_17 ( V_2 ) ;
}
F_2 ( L_17 , ( V_4 -> V_19 == V_20 ) ? L_16 : L_15 ) ;
}
V_4 -> V_71 ++ ;
}
if ( V_4 -> V_36 == V_72 )
goto exit;
if ( ! F_34 ( V_2 ) )
goto exit;
if ( ( V_4 -> V_19 == V_24 ) && ( ( V_4 -> V_71 % 4 ) == 0 ) ) {
F_2 ( L_18 , V_21 , F_38 ( V_14 ) ) ;
V_4 -> V_38 = V_20 ;
F_25 ( V_2 ) ;
}
exit:
F_39 ( & V_2 -> V_5 ) ;
V_4 -> V_69 = false ;
}
static void F_40 ( unsigned long V_73 )
{
struct V_1 * V_2 = (struct V_1 * ) V_73 ;
F_41 ( V_2 ) ;
}
void F_42 ( struct V_1 * V_2 , T_1 V_74 )
{
T_1 V_75 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
V_74 = F_43 ( V_74 ) ;
if ( V_4 -> V_76 ) {
if ( V_74 < V_77 )
V_74 = V_78 ;
}
if ( ( V_4 -> V_75 == V_74 ) ) {
F_44 ( V_79 , V_80 ,
( L_19 , V_21 , V_4 -> V_75 , V_74 ) ) ;
return;
}
if ( ( V_2 -> V_10 ) ||
( ! V_2 -> V_81 ) ) {
F_44 ( V_79 , V_80 ,
( L_20 ,
V_21 , V_2 -> V_10 , V_2 -> V_81 ) ) ;
V_4 -> V_82 = V_77 ;
return;
}
if ( V_2 -> V_9 ) {
F_44 ( V_79 , V_80 ,
( L_21 , V_21 , V_74 ) ) ;
if ( V_74 < V_83 ) {
F_44 ( V_79 , V_80 ,
( L_22 , V_21 , V_74 ) ) ;
return;
}
}
V_75 = V_74 | V_4 -> V_84 ;
F_44 ( V_79 , V_85 ,
( L_23 , V_75 , V_4 -> V_82 ) ) ;
V_4 -> V_75 = V_74 ;
F_45 ( V_2 , V_86 , ( T_1 * ) ( & V_75 ) ) ;
V_4 -> V_84 += 0x80 ;
V_4 -> V_82 = V_74 ;
}
static T_1 F_46 ( struct V_1 * V_2 )
{
unsigned long V_87 , V_88 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_13 * V_14 = & ( V_2 -> V_15 ) ;
V_87 = V_59 ;
V_88 = V_87 - V_4 -> V_89 ;
if ( V_88 < V_90 )
return false ;
if ( ( F_8 ( V_14 , V_16 ) == false ) ||
( F_8 ( V_14 , V_91 ) ) ||
( F_8 ( V_14 , V_64 ) ) ||
( F_8 ( V_14 , V_65 ) ) ||
( F_8 ( V_14 , V_66 ) ) )
return false ;
if ( V_4 -> V_92 )
return false ;
if ( ( V_2 -> V_43 . V_93 == V_94 ) && ( V_2 -> V_43 . V_95 == false ) ) {
F_2 ( L_24 ) ;
return false ;
}
return true ;
}
void F_47 ( struct V_1 * V_2 , T_1 V_96 , T_1 V_97 , T_1 V_98 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_44 ( V_79 , V_85 ,
( L_25 ,
V_21 , V_96 , V_97 ) ) ;
if ( V_96 > V_99 ) {
F_44 ( V_79 , V_80 , ( L_26 , V_96 ) ) ;
return;
}
if ( V_4 -> V_100 == V_96 ) {
if ( V_101 == V_96 )
return;
if ( ( V_4 -> V_97 == V_97 ) &&
( V_4 -> V_98 == V_98 ) )
return;
}
if ( V_96 == V_101 ) {
if ( F_46 ( V_2 ) ) {
F_2 ( L_27 , V_21 ) ;
V_4 -> V_102 = true ;
V_4 -> V_100 = V_96 ;
V_4 -> V_97 = V_97 ;
V_4 -> V_98 = V_98 ;
F_45 ( V_2 , V_103 , ( T_1 * ) ( & V_96 ) ) ;
F_42 ( V_2 , V_83 ) ;
}
}
}
T_2 F_48 ( struct V_1 * V_2 , T_3 V_104 )
{
unsigned long V_105 ;
T_1 V_106 = false ;
T_2 V_107 = 0 ;
V_105 = V_59 ;
while ( 1 ) {
F_49 ( V_2 , V_108 , & V_106 ) ;
if ( V_106 )
break;
if ( V_2 -> V_10 ) {
V_107 = - 2 ;
F_2 ( L_28 , V_21 ) ;
break;
}
if ( F_50 ( V_59 - V_105 ) > V_104 ) {
V_107 = - 1 ;
F_2 ( L_29 , V_21 , V_104 ) ;
break;
}
F_51 ( 1 ) ;
}
return V_107 ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_46 ( V_2 ) == false )
return;
if ( V_4 -> V_109 ) {
if ( V_4 -> V_110 >= 2 ) {
if ( V_4 -> V_100 == V_101 ) {
V_4 -> V_39 = true ;
F_2 ( L_30 , V_21 , V_4 -> V_97 ) ;
F_47 ( V_2 , V_4 -> V_111 , V_4 -> V_97 , 0 ) ;
}
} else {
V_4 -> V_110 ++ ;
}
}
}
void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( V_4 -> V_109 ) {
if ( V_4 -> V_100 != V_101 ) {
F_47 ( V_2 , V_101 , 0 , 0 ) ;
if ( V_4 -> V_100 == V_101 )
F_48 ( V_2 , V_112 ) ;
}
}
V_4 -> V_39 = false ;
}
void F_3 ( struct V_1 * V_113 )
{
struct V_13 * V_14 = & ( V_113 -> V_15 ) ;
T_1 V_114 = 0 ;
if ( F_8 ( V_14 , V_16 ) )
F_12 ( V_113 , V_115 , V_114 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_5 = & V_2 -> V_5 ;
F_55 ( & V_5 -> F_4 ) ;
V_5 -> V_19 = V_24 ;
V_5 -> V_37 = 0 ;
V_5 -> V_47 = 0 ;
V_5 -> V_12 = false ;
V_5 -> V_35 = V_2 -> V_28 . V_35 ;
V_5 -> V_36 = V_2 -> V_28 . V_35 ;
V_5 -> V_116 = V_117 ;
V_5 -> V_71 = 0 ;
V_5 -> V_118 = false ;
V_5 -> V_92 = false ;
V_5 -> V_22 = false ;
V_5 -> V_110 = 0 ;
if ( V_2 -> V_28 . V_29 == 1 )
V_5 -> V_111 = V_101 ;
else
V_5 -> V_111 = V_2 -> V_28 . V_111 ;
V_5 -> V_109 = ( V_101 != V_5 -> V_111 ) ? true : false ;
V_5 -> V_102 = false ;
V_5 -> V_75 = 0 ;
V_5 -> V_82 = V_77 ;
V_5 -> V_100 = V_101 ;
V_5 -> V_97 = V_2 -> V_28 . V_97 ;
V_5 -> V_98 = 0 ;
V_5 -> V_84 = 0x80 ;
V_5 -> V_76 = false ;
F_56 ( & V_5 -> V_119 ,
F_40 ,
( unsigned long ) V_2 ) ;
}
int F_57 ( struct V_1 * V_2 , T_3 V_120 , const char * V_121 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_13 * V_14 = & V_2 -> V_15 ;
unsigned long V_122 ;
unsigned long V_123 ;
int V_57 = V_45 ;
V_122 = V_59 + F_58 ( V_120 ) ;
if ( F_59 ( V_4 -> V_58 , V_122 ) )
V_4 -> V_58 = V_59 + F_58 ( V_120 ) ;
V_123 = V_59 ;
if ( V_4 -> V_69 ) {
F_2 ( L_31 , V_21 ) ;
while ( V_4 -> V_69 &&
F_50 ( V_59 - V_123 ) <= 3000 )
F_60 ( 1000 , 3000 ) ;
if ( V_4 -> V_69 )
F_2 ( L_32 , V_21 ) ;
else
F_2 ( L_33 , V_21 ) ;
}
if ( ( ! V_4 -> V_118 ) && ( V_4 -> V_92 ) ) {
V_57 = V_124 ;
goto exit;
}
if ( ( V_4 -> V_118 ) && ( V_2 -> V_125 ) ) {
V_57 = V_124 ;
goto exit;
}
if ( F_8 ( V_14 , V_16 ) ) {
V_57 = V_45 ;
goto exit;
}
if ( V_20 == V_4 -> V_19 ) {
F_2 ( L_34 , V_21 ) ;
if ( V_124 == F_28 ( V_2 ) ) {
F_2 ( L_35 ) ;
V_57 = V_124 ;
goto exit;
}
}
if ( V_2 -> V_9 || ! V_2 -> V_8 ||
! V_2 -> V_81 ) {
F_2 ( L_36
, V_121
, V_2 -> V_9
, V_2 -> V_8
, V_2 -> V_81 ) ;
V_57 = false ;
goto exit;
}
exit:
V_122 = V_59 + F_58 ( V_120 ) ;
if ( F_59 ( V_4 -> V_58 , V_122 ) )
V_4 -> V_58 = V_59 + F_58 ( V_120 ) ;
return V_57 ;
}
int F_61 ( struct V_1 * V_2 , T_1 V_126 )
{
int V_57 = 0 ;
struct V_3 * V_5 = & V_2 -> V_5 ;
if ( V_126 < V_127 ) {
if ( V_5 -> V_111 != V_126 ) {
if ( V_101 == V_126 )
F_3 ( V_2 ) ;
else
V_5 -> V_110 = 2 ;
V_5 -> V_111 = V_126 ;
V_5 -> V_109 = ( V_101 != V_5 -> V_111 ) ? true : false ;
}
} else {
V_57 = - V_128 ;
}
return V_57 ;
}
int F_62 ( struct V_1 * V_2 , T_1 V_126 )
{
struct V_3 * V_5 = & V_2 -> V_5 ;
if ( V_126 == V_129 || V_126 == V_40 ) {
F_63 ( V_5 , V_126 ) ;
F_2 ( L_37 , V_21 , V_126 == V_129 ? L_38 : L_39 ) ;
return 0 ;
} else if ( V_126 == V_72 ) {
F_63 ( V_5 , V_126 ) ;
F_2 ( L_37 , V_21 , L_40 ) ;
if ( ( V_2 -> V_10 == 0 ) && ( V_124 == F_64 ( V_2 ) ) )
return - V_130 ;
} else {
return - V_128 ;
}
return 0 ;
}
