static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = & V_3 -> V_7 . V_8 ;
struct V_1 * V_9 ;
F_2 ( & V_6 -> V_10 ) ;
V_9 = F_3 ( & V_6 -> V_11 , V_4 ) ;
if ( V_9 )
F_4 ( & V_9 -> V_12 ) ;
F_5 ( & V_6 -> V_10 ) ;
if ( ! V_9 ) {
F_6 ( V_3 , L_1 ,
V_4 ) ;
return NULL ;
}
return V_9 ;
}
void F_7 ( struct V_1 * V_9 )
{
if ( F_8 ( & V_9 -> V_12 ) )
F_9 ( & V_9 -> free ) ;
}
static T_2 F_10 ( void )
{
T_2 V_13 ;
V_13 = F_11 ( V_14 ) |
F_11 ( V_15 ) |
F_11 ( V_16 ) |
F_11 ( V_17 ) |
F_11 ( V_18 ) |
F_11 ( V_19 ) |
F_11 ( V_20 ) |
F_11 ( V_21 ) ;
return V_13 ;
}
static T_2 F_12 ( void )
{
T_2 V_13 ;
V_13 = F_11 ( V_17 ) |
F_11 ( V_18 ) ;
return V_13 ;
}
static T_2 F_13 ( void )
{
return F_11 ( V_18 ) ;
}
static bool F_14 ( int V_22 , int V_23 )
{
switch ( V_22 ) {
case V_24 :
return F_11 ( V_23 ) & F_10 () ;
case V_25 :
return F_11 ( V_23 ) & F_12 () ;
case V_26 :
return F_11 ( V_23 ) & F_13 () ;
default:
F_15 ( 1 , L_2 ) ;
return false ;
}
}
void F_16 ( struct V_2 * V_3 , T_1 V_4 , int V_23 )
{
struct V_1 * V_9 = F_1 ( V_3 , V_4 ) ;
struct V_27 * V_28 ;
if ( ! V_9 )
return;
if ( ! F_14 ( ( V_4 >> V_29 ) , V_23 ) ) {
F_6 ( V_3 , L_3 ,
V_23 , V_4 ) ;
return;
}
switch ( V_9 -> V_30 ) {
case V_31 :
case V_32 :
case V_33 :
V_28 = (struct V_27 * ) V_9 ;
V_28 -> V_34 ( V_28 , V_23 ) ;
break;
default:
F_6 ( V_3 , L_4 , V_4 ) ;
}
F_7 ( V_9 ) ;
}
void F_17 ( struct V_2 * V_3 , struct V_35 * V_36 )
{
struct V_37 * V_38 = & V_36 -> V_39 . V_40 ;
int V_41 = F_18 ( V_38 -> V_42 ) & V_43 ;
struct V_1 * V_9 = F_1 ( V_3 , V_41 ) ;
struct V_27 * V_28 =
F_19 ( V_9 , struct V_27 , V_9 ) ;
struct V_44 V_45 ;
if ( ! V_28 ) {
F_6 ( V_3 , L_5 ,
V_41 ) ;
return;
}
V_45 . V_46 = V_36 -> V_47 ;
V_45 . V_48 = ( F_18 ( V_38 -> V_42 ) >> V_49 ) &
( V_50 | V_51 | V_52 ) ;
V_45 . V_53 = F_18 (
V_38 -> V_53 ) ;
F_20 ( V_3 ,
L_6 ,
V_36 -> V_47 , V_45 . V_48 ) ;
switch ( V_36 -> V_47 ) {
case V_54 :
V_45 . V_55 . V_56 =
F_18 ( V_38 -> V_55 . V_56 ) ;
V_45 . V_55 . V_57 =
F_21 ( V_38 -> V_55 . V_58 ) ;
V_45 . V_55 . V_59 =
F_18 ( V_38 -> V_55 . V_59 ) ;
V_45 . V_55 . V_60 =
F_22 ( V_38 -> V_55 . V_60 ) ;
F_20 ( V_3 ,
L_7 ,
V_41 , V_45 . V_55 . V_56 ) ;
F_20 ( V_3 ,
L_8 ,
V_45 . V_55 . V_59 ) ;
F_20 ( V_3 ,
L_9 ,
V_45 . V_55 . V_60 ) ;
F_20 ( V_3 ,
L_10 ,
V_45 . V_53 ) ;
break;
case V_61 :
V_45 . V_62 . V_63 =
F_21 ( V_38 -> V_62 . V_63 ) ;
V_45 . V_62 . V_57 =
F_21 ( V_38 -> V_62 . V_58 ) ;
F_20 ( V_3 ,
L_11 ,
V_41 , V_45 . V_62 . V_63 ) ;
F_20 ( V_3 ,
L_10 ,
V_45 . V_53 ) ;
break;
default:
F_6 ( V_3 ,
L_12 ,
V_36 -> V_47 , V_41 ) ;
}
if ( V_28 -> V_64 ) {
V_28 -> V_64 ( V_28 , & V_45 ) ;
} else {
F_23 ( V_3 ,
L_13 ,
V_41 ) ;
}
F_7 ( V_9 ) ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
int V_22 )
{
struct V_5 * V_6 = & V_3 -> V_7 . V_8 ;
int V_65 ;
V_28 -> V_9 . V_30 = V_22 ;
F_25 ( & V_6 -> V_10 ) ;
V_65 = F_26 ( & V_6 -> V_11 ,
V_28 -> V_41 | ( V_22 << V_29 ) ,
V_28 ) ;
F_27 ( & V_6 -> V_10 ) ;
if ( V_65 )
return V_65 ;
F_28 ( & V_28 -> V_9 . V_12 , 1 ) ;
F_29 ( & V_28 -> V_9 . free ) ;
V_28 -> V_66 = V_67 -> V_66 ;
return 0 ;
}
static void F_30 ( struct V_2 * V_3 ,
struct V_27 * V_28 )
{
struct V_5 * V_6 = & V_3 -> V_7 . V_8 ;
unsigned long V_48 ;
F_31 ( & V_6 -> V_10 , V_48 ) ;
F_32 ( & V_6 -> V_11 ,
V_28 -> V_41 | ( V_28 -> V_9 . V_30 << V_29 ) ) ;
F_33 ( & V_6 -> V_10 , V_48 ) ;
F_7 ( (struct V_1 * ) V_28 ) ;
F_34 ( & V_28 -> V_9 . free ) ;
}
int F_35 ( struct V_2 * V_3 ,
struct V_27 * V_28 ,
struct V_68 * V_69 ,
int V_70 )
{
struct V_71 V_72 ;
struct V_73 V_74 ;
struct V_75 V_76 ;
int V_65 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_69 -> V_77 . V_78 = F_36 ( V_79 ) ;
V_65 = F_37 ( V_3 , V_69 , V_70 , & V_72 , sizeof( V_72 ) ) ;
if ( V_65 ) {
F_6 ( V_3 , L_14 , V_65 ) ;
return V_65 ;
}
if ( V_72 . V_77 . V_80 ) {
F_6 ( V_3 , L_15 ,
F_38 ( & V_3 -> V_81 ) ) ;
return F_39 ( & V_72 . V_77 ) ;
}
V_28 -> V_41 = F_18 ( V_72 . V_41 ) & 0xffffff ;
F_20 ( V_3 , L_16 , V_28 -> V_41 ) ;
V_65 = F_24 ( V_3 , V_28 , V_31 ) ;
if ( V_65 )
goto V_82;
V_65 = F_40 ( V_3 , V_28 ) ;
if ( V_65 )
F_20 ( V_3 , L_17 ,
V_28 -> V_41 ) ;
F_4 ( & V_3 -> V_81 ) ;
return 0 ;
V_82:
memset ( & V_74 , 0 , sizeof( V_74 ) ) ;
memset ( & V_76 , 0 , sizeof( V_76 ) ) ;
V_74 . V_77 . V_78 = F_36 ( V_83 ) ;
V_74 . V_41 = F_41 ( V_28 -> V_41 ) ;
F_37 ( V_3 , & V_74 , sizeof( V_74 ) , & V_72 , sizeof( V_76 ) ) ;
return V_65 ;
}
int F_42 ( struct V_2 * V_3 ,
struct V_27 * V_28 )
{
struct V_73 V_69 ;
struct V_75 V_72 ;
int V_65 ;
F_43 ( V_3 , V_28 ) ;
F_30 ( V_3 , V_28 ) ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_69 . V_77 . V_78 = F_36 ( V_83 ) ;
V_69 . V_41 = F_41 ( V_28 -> V_41 ) ;
V_65 = F_37 ( V_3 , & V_69 , sizeof( V_69 ) , & V_72 , sizeof( V_72 ) ) ;
if ( V_65 )
return V_65 ;
if ( V_72 . V_77 . V_80 )
return F_39 ( & V_72 . V_77 ) ;
F_44 ( & V_3 -> V_81 ) ;
return 0 ;
}
int F_45 ( struct V_2 * V_3 , T_3 V_84 ,
struct V_85 * V_69 , int V_86 ,
struct V_27 * V_28 )
{
struct V_87 V_72 ;
int V_65 = 0 ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_69 -> V_77 . V_78 = F_36 ( V_84 ) ;
V_69 -> V_41 = F_41 ( V_28 -> V_41 ) ;
V_65 = F_37 ( V_3 , V_69 , sizeof( * V_69 ) , & V_72 , sizeof( V_72 ) ) ;
if ( V_65 )
return V_65 ;
return F_39 ( & V_72 . V_77 ) ;
}
void F_46 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = & V_3 -> V_7 . V_8 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_47 ( & V_6 -> V_10 ) ;
F_48 ( & V_6 -> V_11 , V_88 ) ;
F_49 ( V_3 ) ;
}
void F_50 ( struct V_2 * V_3 )
{
F_51 ( V_3 ) ;
}
int F_52 ( struct V_2 * V_3 , struct V_27 * V_28 ,
struct V_89 * V_72 , int V_90 )
{
struct V_91 V_69 ;
int V_65 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
memset ( V_72 , 0 , V_90 ) ;
V_69 . V_77 . V_78 = F_36 ( V_92 ) ;
V_69 . V_41 = F_41 ( V_28 -> V_41 ) ;
V_65 = F_37 ( V_3 , & V_69 , sizeof( V_69 ) , V_72 , V_90 ) ;
if ( V_65 )
return V_65 ;
if ( V_72 -> V_77 . V_80 )
return F_39 ( & V_72 -> V_77 ) ;
return V_65 ;
}
int F_53 ( struct V_2 * V_3 , T_1 * V_93 )
{
struct V_94 V_69 ;
struct V_95 V_72 ;
int V_65 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_69 . V_77 . V_78 = F_36 ( V_96 ) ;
V_65 = F_37 ( V_3 , & V_69 , sizeof( V_69 ) , & V_72 , sizeof( V_72 ) ) ;
if ( V_65 )
return V_65 ;
if ( V_72 . V_77 . V_80 )
V_65 = F_39 ( & V_72 . V_77 ) ;
else
* V_93 = F_18 ( V_72 . V_93 ) & 0xffffff ;
return V_65 ;
}
int F_54 ( struct V_2 * V_3 , T_1 V_93 )
{
struct V_97 V_69 ;
struct V_98 V_72 ;
int V_65 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_69 . V_77 . V_78 = F_36 ( V_99 ) ;
V_69 . V_93 = F_41 ( V_93 ) ;
V_65 = F_37 ( V_3 , & V_69 , sizeof( V_69 ) , & V_72 , sizeof( V_72 ) ) ;
if ( V_65 )
return V_65 ;
if ( V_72 . V_77 . V_80 )
V_65 = F_39 ( & V_72 . V_77 ) ;
return V_65 ;
}
int F_55 ( struct V_2 * V_3 , T_1 V_41 ,
T_4 V_48 , int error )
{
struct V_100 V_69 ;
struct V_101 V_72 ;
int V_65 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
V_69 . V_77 . V_78 = F_36 ( V_102 ) ;
V_69 . V_77 . V_103 = 0 ;
V_48 &= ( V_104 |
V_105 |
V_106 ) ;
V_48 |= ( error ? V_107 : 0 ) ;
V_69 . V_42 = F_41 ( ( V_41 & V_43 ) |
( V_48 << V_49 ) ) ;
V_65 = F_37 ( V_3 , & V_69 , sizeof( V_69 ) , & V_72 , sizeof( V_72 ) ) ;
if ( V_65 )
return V_65 ;
if ( V_72 . V_77 . V_80 )
V_65 = F_39 ( & V_72 . V_77 ) ;
return V_65 ;
}
int F_56 ( struct V_2 * V_3 , T_1 * V_69 , int V_70 ,
struct V_27 * V_108 )
{
int V_65 ;
T_1 V_109 ;
V_65 = F_57 ( V_3 , V_69 , V_70 , & V_109 ) ;
if ( V_65 )
return V_65 ;
V_108 -> V_41 = V_109 ;
V_65 = F_24 ( V_3 , V_108 , V_32 ) ;
if ( V_65 )
goto V_110;
return 0 ;
V_110:
F_58 ( V_3 , V_108 -> V_41 ) ;
return V_65 ;
}
void F_59 ( struct V_2 * V_3 ,
struct V_27 * V_108 )
{
F_30 ( V_3 , V_108 ) ;
F_58 ( V_3 , V_108 -> V_41 ) ;
}
int F_60 ( struct V_2 * V_3 , T_1 * V_69 , int V_70 ,
struct V_27 * V_111 )
{
int V_65 ;
T_1 V_112 ;
V_65 = F_61 ( V_3 , V_69 , V_70 , & V_112 ) ;
if ( V_65 )
return V_65 ;
V_111 -> V_41 = V_112 ;
V_65 = F_24 ( V_3 , V_111 , V_33 ) ;
if ( V_65 )
goto V_113;
return 0 ;
V_113:
F_62 ( V_3 , V_111 -> V_41 ) ;
return V_65 ;
}
void F_63 ( struct V_2 * V_3 ,
struct V_27 * V_111 )
{
F_30 ( V_3 , V_111 ) ;
F_62 ( V_3 , V_111 -> V_41 ) ;
}
int F_64 ( struct V_2 * V_3 , T_3 * V_114 )
{
T_1 V_69 [ F_65 ( V_115 ) ] ;
T_1 V_72 [ F_65 ( V_116 ) ] ;
int V_65 ;
memset ( V_69 , 0 , sizeof( V_69 ) ) ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
F_66 ( V_115 , V_69 , V_78 , V_117 ) ;
V_65 = F_67 ( V_3 , V_69 , sizeof( V_69 ) , V_72 , sizeof( V_72 ) ) ;
if ( ! V_65 )
* V_114 = F_68 ( V_116 , V_72 ,
V_118 ) ;
return V_65 ;
}
int F_69 ( struct V_2 * V_3 , T_3 V_114 )
{
T_1 V_69 [ F_65 ( V_119 ) ] ;
T_1 V_72 [ F_65 ( V_120 ) ] ;
memset ( V_69 , 0 , sizeof( V_69 ) ) ;
memset ( V_72 , 0 , sizeof( V_72 ) ) ;
F_66 ( V_119 , V_69 , V_78 ,
V_121 ) ;
F_66 ( V_119 , V_69 , V_118 , V_114 ) ;
return F_67 ( V_3 , V_69 , sizeof( V_69 ) , V_72 ,
sizeof( V_72 ) ) ;
}
int F_70 ( struct V_2 * V_3 , T_3 V_114 ,
int V_122 , void * V_72 , int V_123 )
{
T_1 V_69 [ F_65 ( V_124 ) ] ;
memset ( V_69 , 0 , sizeof( V_69 ) ) ;
F_66 ( V_124 , V_69 , V_78 , V_125 ) ;
F_66 ( V_124 , V_69 , V_126 , V_122 ) ;
F_66 ( V_124 , V_69 , V_118 , V_114 ) ;
return F_67 ( V_3 , V_69 , sizeof( V_69 ) , V_72 , V_123 ) ;
}
int F_71 ( struct V_2 * V_3 , T_3 V_114 ,
T_1 * V_127 )
{
int V_90 = F_72 ( V_128 ) ;
void * V_72 ;
int V_65 ;
V_72 = F_73 ( V_90 ) ;
if ( ! V_72 )
return - V_129 ;
V_65 = F_70 ( V_3 , V_114 , 0 , V_72 , V_90 ) ;
if ( ! V_65 )
* V_127 = F_68 ( V_128 , V_72 ,
V_127 ) ;
F_74 ( V_72 ) ;
return V_65 ;
}
