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
F_4 ( & V_4 -> V_12 ) ;
V_4 -> V_13 = true ;
if ( V_7 ) {
F_5 ( V_7 ) ;
F_6 ( V_7 ) ;
}
F_7 ( V_2 , 500 , false ) ;
{
struct V_14 * V_15 = & V_2 -> V_16 ;
if ( F_8 ( V_15 , V_17 ) ) {
F_9 ( V_15 , V_17 ) ;
F_10 ( V_2 , V_18 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 , V_19 , 0 ) ;
}
}
F_13 ( V_2 , 1 ) ;
F_14 ( V_2 , true ) ;
F_15 ( V_2 ) ;
V_4 -> V_20 = V_21 ;
V_4 -> V_13 = false ;
F_16 ( & V_4 -> V_12 ) ;
return 0 ;
V_11:
F_2 ( L_3 , V_22 ) ;
return - 1 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
F_2 ( L_4 ) ;
F_4 ( & V_4 -> V_12 ) ;
V_4 -> V_13 = true ;
F_18 ( V_2 ) ;
if ( F_19 ( V_7 , false ) != 0 ) {
F_16 ( & V_4 -> V_12 ) ;
goto V_11;
}
F_20 ( V_7 ) ;
F_21 ( V_7 ) ;
if ( ! F_22 ( V_7 ) )
F_23 ( V_7 ) ;
else
F_24 ( V_7 ) ;
V_4 -> V_23 = false ;
V_4 -> V_24 = false ;
V_4 -> V_20 = V_25 ;
V_4 -> V_13 = false ;
F_16 ( & V_4 -> V_12 ) ;
return 0 ;
V_11:
F_2 ( L_5 , V_22 ) ;
return - 1 ;
}
void F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_26 * V_27 = & V_2 -> V_28 ;
if ( V_2 -> V_29 . V_30 == 1 )
return;
if ( V_27 -> V_31 != V_32 ||
V_27 -> V_33 != V_34 ) {
F_26 ( V_35 , L_6 ) ;
F_26 ( V_35 , L_7 ,
V_27 -> V_31 , V_27 -> V_33 ) ;
return;
}
F_4 ( & V_4 -> V_12 ) ;
V_4 -> V_13 = true ;
V_4 -> V_36 = V_4 -> V_37 ;
V_4 -> V_38 ++ ;
F_2 ( L_8 , V_4 -> V_38 ) ;
if ( V_21 == V_4 -> V_39 ) {
V_4 -> V_40 = true ;
F_26 ( V_35 , L_9 ) ;
if ( V_4 -> V_36 == V_41 )
V_4 -> V_23 = true ;
F_27 ( V_2 ) ;
V_4 -> V_20 = V_21 ;
}
V_4 -> V_13 = false ;
F_16 ( & V_4 -> V_12 ) ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_42 * V_43 = & ( V_2 -> V_44 ) ;
struct V_14 * V_15 = & ( V_2 -> V_16 ) ;
int V_45 = V_46 ;
int V_47 ;
F_4 ( & V_4 -> V_12 ) ;
if ( ( V_4 -> V_20 == V_21 ) && ( ! V_4 -> V_13 ) ) {
V_4 -> V_13 = true ;
V_4 -> V_39 = V_25 ;
V_4 -> V_48 ++ ;
F_2 ( L_10 , V_4 -> V_48 ) ;
V_45 = F_29 ( V_2 ) ;
if ( V_45 == V_46 ) {
V_4 -> V_20 = V_25 ;
}
F_26 ( V_35 , L_11 ) ;
if ( ( V_49 == V_43 -> V_50 ) || ( V_51 == V_43 -> V_50 ) ) {
F_2 ( L_12 , V_22 , V_2 -> V_52 . V_53 , V_4 -> V_13 ) ;
F_30 ( V_2 , V_2 -> V_52 . V_53 , V_54 , V_55 ) ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
if ( V_15 -> V_56 & F_31 ( V_47 ) ) {
if ( V_47 == V_43 -> V_57 )
V_45 = F_32 ( V_2 , V_43 , V_47 , 1 ) ;
else
V_45 = F_32 ( V_2 , V_43 , V_47 , 0 ) ;
}
}
}
F_2 ( L_13 , F_33 ( V_2 , 0x4c ) ) ;
V_4 -> V_13 = false ;
V_4 -> V_23 = false ;
V_4 -> V_40 = false ;
}
F_16 ( & V_4 -> V_12 ) ;
return V_45 ;
}
static bool F_34 ( struct V_1 * V_1 )
{
struct V_14 * V_15 = & ( V_1 -> V_16 ) ;
bool V_58 = false ;
if ( F_35 ( V_1 -> V_5 . V_59 , V_60 ) )
goto exit;
if ( F_8 ( V_15 , V_61 | V_62 ) ||
F_8 ( V_15 , V_63 | V_64 ) ||
F_8 ( V_15 , V_65 ) ||
F_8 ( V_15 , V_66 | V_67 ) )
goto exit;
V_58 = true ;
exit:
return V_58 ;
}
void F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_14 * V_15 = & ( V_2 -> V_16 ) ;
enum V_68 V_69 ;
V_4 -> V_70 = true ;
if ( V_4 -> V_13 )
goto exit;
if ( V_2 -> V_5 . V_71 ) {
V_69 = F_37 ( V_2 ) ;
F_2 ( L_14 , V_22 , ( V_69 == V_25 ) ? L_15 : L_16 ) ;
if ( V_69 != V_4 -> V_20 ) {
if ( V_69 == V_21 ) {
V_4 -> V_39 = V_21 ;
V_4 -> V_24 = true ;
F_1 ( V_2 ) ;
} else {
V_4 -> V_39 = V_25 ;
F_17 ( V_2 ) ;
}
F_2 ( L_17 , ( V_4 -> V_20 == V_21 ) ? L_16 : L_15 ) ;
}
V_4 -> V_72 ++ ;
}
if ( V_4 -> V_37 == V_73 )
goto exit;
if ( ! F_34 ( V_2 ) )
goto exit;
if ( ( V_4 -> V_20 == V_25 ) && ( ( V_4 -> V_72 % 4 ) == 0 ) ) {
F_2 ( L_18 , V_22 , F_38 ( V_15 ) ) ;
V_4 -> V_39 = V_21 ;
F_25 ( V_2 ) ;
}
exit:
F_39 ( & V_2 -> V_5 ) ;
V_4 -> V_70 = false ;
return;
}
static void F_40 ( void * V_74 )
{
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
F_41 ( V_2 ) ;
}
void F_42 ( struct V_1 * V_2 , T_1 V_75 )
{
T_1 V_76 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
V_75 = F_43 ( V_75 ) ;
if ( V_4 -> V_77 ) {
if ( V_75 < V_78 )
V_75 = V_79 ;
}
if ( ( V_4 -> V_76 == V_75 ) ) {
F_44 ( V_80 , V_81 ,
( L_19 , V_22 , V_4 -> V_76 , V_75 ) ) ;
return;
}
if ( ( V_2 -> V_10 ) ||
( ! V_2 -> V_82 ) ) {
F_44 ( V_80 , V_81 ,
( L_20 ,
V_22 , V_2 -> V_10 , V_2 -> V_82 ) ) ;
V_4 -> V_83 = V_78 ;
return;
}
if ( V_2 -> V_9 ) {
F_44 ( V_80 , V_81 ,
( L_21 , V_22 , V_75 ) ) ;
if ( V_75 < V_84 ) {
F_44 ( V_80 , V_81 ,
( L_22 , V_22 , V_75 ) ) ;
return;
}
}
V_76 = V_75 | V_4 -> V_85 ;
F_44 ( V_80 , V_86 ,
( L_23 , V_76 , V_4 -> V_83 ) ) ;
V_4 -> V_76 = V_75 ;
F_45 ( V_2 , V_87 , ( T_1 * ) ( & V_76 ) ) ;
V_4 -> V_85 += 0x80 ;
V_4 -> V_83 = V_75 ;
}
static T_1 F_46 ( struct V_1 * V_2 )
{
T_2 V_88 , V_89 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_14 * V_15 = & ( V_2 -> V_16 ) ;
V_88 = V_60 ;
V_89 = V_88 - V_4 -> V_90 ;
if ( V_89 < V_91 )
return false ;
if ( ( F_8 ( V_15 , V_17 ) == false ) ||
( F_8 ( V_15 , V_92 ) ) ||
( F_8 ( V_15 , V_65 ) ) ||
( F_8 ( V_15 , V_66 ) ) ||
( F_8 ( V_15 , V_67 ) ) )
return false ;
if ( V_4 -> V_93 )
return false ;
if ( ( V_2 -> V_44 . V_94 == V_95 ) && ( V_2 -> V_44 . V_96 == false ) ) {
F_2 ( L_24 ) ;
return false ;
}
return true ;
}
void F_47 ( struct V_1 * V_2 , T_1 V_97 , T_1 V_98 , T_1 V_99 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
F_44 ( V_80 , V_86 ,
( L_25 ,
V_22 , V_97 , V_98 ) ) ;
if ( V_97 > V_100 ) {
F_44 ( V_80 , V_81 , ( L_26 , V_97 ) ) ;
return;
}
if ( V_4 -> V_101 == V_97 ) {
if ( V_102 == V_97 )
return;
if ( ( V_4 -> V_98 == V_98 ) &&
( V_4 -> V_99 == V_99 ) )
return;
}
if ( V_97 == V_102 ) {
if ( F_46 ( V_2 ) ) {
F_2 ( L_27 , V_22 ) ;
V_4 -> V_103 = true ;
V_4 -> V_101 = V_97 ;
V_4 -> V_98 = V_98 ;
V_4 -> V_99 = V_99 ;
F_45 ( V_2 , V_104 , ( T_1 * ) ( & V_97 ) ) ;
F_42 ( V_2 , V_84 ) ;
}
}
}
T_3 F_48 ( struct V_1 * V_2 , T_2 V_105 )
{
T_2 V_106 ;
T_1 V_107 = false ;
T_3 V_108 = 0 ;
V_106 = V_60 ;
while ( 1 ) {
F_49 ( V_2 , V_109 , & V_107 ) ;
if ( V_107 )
break;
if ( V_2 -> V_10 ) {
V_108 = - 2 ;
F_2 ( L_28 , V_22 ) ;
break;
}
if ( F_50 ( V_106 ) > V_105 ) {
V_108 = - 1 ;
F_2 ( L_29 , V_22 , V_105 ) ;
break;
}
F_51 ( 1 ) ;
}
return V_108 ;
}
void F_52 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( F_46 ( V_2 ) == false )
return;
if ( V_4 -> V_110 ) {
if ( V_4 -> V_111 >= 2 ) {
if ( V_4 -> V_101 == V_102 ) {
V_4 -> V_40 = true ;
F_2 ( L_30 , V_22 , V_4 -> V_98 ) ;
F_47 ( V_2 , V_4 -> V_112 , V_4 -> V_98 , 0 ) ;
}
} else {
V_4 -> V_111 ++ ;
}
}
}
void F_53 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
if ( V_4 -> V_110 ) {
if ( V_4 -> V_101 != V_102 ) {
F_47 ( V_2 , V_102 , 0 , 0 ) ;
if ( V_4 -> V_101 == V_102 )
F_48 ( V_2 , V_113 ) ;
}
}
V_4 -> V_40 = false ;
}
void F_3 ( struct V_1 * V_114 )
{
struct V_14 * V_15 = & ( V_114 -> V_16 ) ;
T_1 V_115 = 0 ;
if ( F_8 ( V_15 , V_17 ) )
F_12 ( V_114 , V_116 , V_115 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_3 * V_5 = & V_2 -> V_5 ;
F_55 ( & V_5 -> V_12 ) ;
V_5 -> V_20 = V_25 ;
V_5 -> V_38 = 0 ;
V_5 -> V_48 = 0 ;
V_5 -> V_13 = false ;
V_5 -> V_36 = V_2 -> V_29 . V_36 ;
V_5 -> V_37 = V_2 -> V_29 . V_36 ;
V_5 -> V_117 = V_118 ;
V_5 -> V_72 = 0 ;
V_5 -> V_119 = false ;
V_5 -> V_93 = false ;
V_5 -> V_23 = false ;
V_5 -> V_111 = 0 ;
if ( V_2 -> V_29 . V_30 == 1 )
V_5 -> V_112 = V_102 ;
else
V_5 -> V_112 = V_2 -> V_29 . V_112 ;
V_5 -> V_110 = ( V_102 != V_5 -> V_112 ) ? true : false ;
V_5 -> V_103 = false ;
V_5 -> V_76 = 0 ;
V_5 -> V_83 = V_78 ;
V_5 -> V_101 = V_102 ;
V_5 -> V_98 = V_2 -> V_29 . V_98 ;
V_5 -> V_99 = 0 ;
V_5 -> V_85 = 0x80 ;
V_5 -> V_77 = false ;
F_56 ( & ( V_5 -> V_120 ) , V_2 -> V_7 , F_40 , ( T_1 * ) V_2 ) ;
}
inline void F_57 ( struct V_1 * V_2 , T_2 V_121 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
V_4 -> V_59 = V_60 + F_58 ( V_121 ) ;
}
int F_59 ( struct V_1 * V_2 , T_2 V_122 , const char * V_123 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
struct V_14 * V_15 = & V_2 -> V_16 ;
unsigned long V_124 ;
int V_58 = V_46 ;
V_124 = V_60 + F_58 ( V_122 ) ;
if ( F_60 ( V_4 -> V_59 , V_124 ) )
V_4 -> V_59 = V_60 + F_58 ( V_122 ) ;
{
T_2 V_125 = V_60 ;
if ( V_4 -> V_70 ) {
F_2 ( L_31 , V_22 ) ;
while ( V_4 -> V_70 && F_50 ( V_125 ) <= 3000 )
F_51 ( 10 ) ;
if ( V_4 -> V_70 )
F_2 ( L_32 , V_22 ) ;
else
F_2 ( L_33 , V_22 ) ;
}
}
if ( ( ! V_4 -> V_119 ) && ( V_4 -> V_93 ) ) {
V_58 = V_126 ;
goto exit;
}
if ( ( V_4 -> V_119 ) && ( V_2 -> V_127 ) ) {
V_58 = V_126 ;
goto exit;
}
if ( F_8 ( V_15 , V_17 ) ) {
V_58 = V_46 ;
goto exit;
}
if ( V_21 == V_4 -> V_20 ) {
F_2 ( L_34 , V_22 ) ;
if ( V_126 == F_28 ( V_2 ) ) {
F_2 ( L_35 ) ;
V_58 = V_126 ;
goto exit;
}
}
if ( V_2 -> V_9 || ! V_2 -> V_8 ||
! V_2 -> V_82 ) {
F_2 ( L_36
, V_123
, V_2 -> V_9
, V_2 -> V_8
, V_2 -> V_82 ) ;
V_58 = false ;
goto exit;
}
exit:
V_124 = V_60 + F_58 ( V_122 ) ;
if ( F_60 ( V_4 -> V_59 , V_124 ) )
V_4 -> V_59 = V_60 + F_58 ( V_122 ) ;
return V_58 ;
}
int F_61 ( struct V_1 * V_2 , T_1 V_128 )
{
int V_58 = 0 ;
struct V_3 * V_5 = & V_2 -> V_5 ;
if ( V_128 < V_129 ) {
if ( V_5 -> V_112 != V_128 ) {
if ( V_102 == V_128 )
F_3 ( V_2 ) ;
else
V_5 -> V_111 = 2 ;
V_5 -> V_112 = V_128 ;
V_5 -> V_110 = ( V_102 != V_5 -> V_112 ) ? true : false ;
}
} else {
V_58 = - V_130 ;
}
return V_58 ;
}
int F_62 ( struct V_1 * V_2 , T_1 V_128 )
{
struct V_3 * V_5 = & V_2 -> V_5 ;
if ( V_128 == V_131 || V_128 == V_41 ) {
F_63 ( V_5 , V_128 ) ;
F_2 ( L_37 , V_22 , V_128 == V_131 ? L_38 : L_39 ) ;
return 0 ;
} else if ( V_128 == V_73 ) {
F_63 ( V_5 , V_128 ) ;
F_2 ( L_37 , V_22 , L_40 ) ;
if ( ( V_2 -> V_10 == 0 ) && ( V_126 == F_64 ( V_2 ) ) )
return - V_132 ;
} else {
return - V_130 ;
}
return 0 ;
}
