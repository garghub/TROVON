static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
return true ;
default:
return false ;
}
}
static bool F_2 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
case V_33 :
case V_34 :
case V_35 :
case V_36 :
case V_37 :
case V_5 :
case V_38 :
case V_39 :
case V_6 :
case V_7 :
case V_8 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
return true ;
default:
return false ;
}
}
static void F_3 ( struct V_44 * V_45 )
{
unsigned int V_3 ;
int V_46 = 0 ;
F_4 ( V_45 -> V_2 , L_1 ) ;
do {
V_46 ++ ;
F_5 ( 1 ) ;
V_3 = F_6 ( V_45 , V_6 ) ;
F_4 ( V_45 -> V_2 , L_2 , V_3 ) ;
} while ( ( V_3 & V_47 )
!= V_47 && V_46 < 1000 );
if ( ( V_3 & V_47 )
!= V_47 )
F_7 ( V_45 -> V_2 , L_3 ) ;
}
static int F_8 ( struct V_48 * V_49 ,
struct V_50 * V_51 , int V_52 )
{
struct V_44 * V_45 = V_49 -> V_45 ;
unsigned int V_3 = F_6 ( V_45 , V_40 ) ;
switch ( V_52 ) {
case V_53 :
F_9 ( V_45 , V_37 ,
V_54 , V_54 ) ;
F_5 ( 5 ) ;
F_9 ( V_45 , V_9 ,
V_55 | V_56 ,
V_55 | V_56 ) ;
V_3 |= V_57 | V_58 ;
F_10 ( V_45 , V_40 , V_3 ) ;
F_10 ( V_45 , V_5 ,
V_59 |
V_60 |
V_61 |
V_62 ) ;
F_3 ( V_45 ) ;
V_3 |= V_63 | V_64 |
V_65 | V_66 ;
F_10 ( V_45 , V_40 , V_3 ) ;
break;
case V_67 :
V_3 &= ~ ( V_66 |
V_57 |
V_65 |
V_64 |
V_58 |
V_63 ) ;
F_10 ( V_45 , V_40 , V_3 ) ;
F_10 ( V_45 , V_5 , 0 ) ;
F_9 ( V_45 , V_9 ,
V_55 | V_56 ,
0 ) ;
F_9 ( V_45 , V_37 ,
V_54 , 0 ) ;
break;
}
return 0 ;
}
static int F_11 ( struct V_44 * V_45 )
{
struct V_68 * V_69 = F_12 ( V_45 ) ;
struct V_70 * V_71 = & V_45 -> V_71 ;
int V_72 ;
F_13 ( V_71 , V_73 ,
F_14 ( V_73 ) ) ;
F_15 ( V_71 , V_74 , F_14 ( V_74 ) ) ;
F_16 ( V_45 , V_75 ,
F_14 ( V_75 ) ) ;
if ( V_69 -> V_76 . V_77 ) {
F_15 ( V_71 , V_78 ,
F_14 ( V_78 ) ) ;
} else {
F_15 ( V_71 , V_79 ,
F_14 ( V_79 ) ) ;
F_16 ( V_45 , V_80 ,
F_14 ( V_80 ) ) ;
}
if ( V_69 -> V_76 . V_81 ) {
F_15 ( V_71 , V_82 ,
F_14 ( V_82 ) ) ;
} else {
F_15 ( V_71 , V_83 ,
F_14 ( V_83 ) ) ;
F_16 ( V_45 , V_84 ,
F_14 ( V_84 ) ) ;
}
if ( V_69 -> V_76 . V_85 ) {
for ( V_72 = 0 ; V_72 < F_14 ( V_69 -> V_76 . V_86 ) ; V_72 ++ )
F_10 ( V_45 , V_41 + V_72 ,
V_69 -> V_76 . V_86 [ V_72 ] ) ;
F_9 ( V_45 , V_11 ,
V_87 , V_87 ) ;
} else {
F_9 ( V_45 , V_11 ,
V_87 , 0 ) ;
}
return 0 ;
}
static int F_17 ( struct V_44 * V_45 ,
enum V_88 V_89 )
{
struct V_68 * V_69 = F_12 ( V_45 ) ;
switch ( V_89 ) {
case V_90 :
break;
case V_91 :
F_9 ( V_45 , V_30 , V_92 ,
V_92 ) ;
F_9 ( V_45 , V_9 ,
V_93 |
V_94 ,
V_93 |
1 << V_95 ) ;
F_5 ( 1 ) ;
break;
case V_96 :
if ( V_45 -> V_71 . V_97 == V_98 ) {
F_18 ( V_69 -> V_99 ) ;
}
F_9 ( V_45 , V_9 ,
V_93 | V_94 , 0 ) ;
F_9 ( V_45 , V_30 ,
V_92 , 0 ) ;
break;
case V_98 :
break;
}
V_45 -> V_71 . V_97 = V_89 ;
return 0 ;
}
static int F_19 ( struct V_44 * V_45 )
{
F_9 ( V_45 , V_15 ,
V_100 | V_101 ,
V_100 | V_101 ) ;
F_9 ( V_45 , V_16 ,
V_100 | V_102 ,
V_100 | V_102 ) ;
F_9 ( V_45 , V_17 ,
V_103 | V_104 ,
V_103 | V_104 ) ;
F_9 ( V_45 , V_18 ,
V_103 | V_105 ,
V_103 | V_105 ) ;
F_9 ( V_45 , V_24 ,
V_106 | V_107 ,
V_106 | V_107 ) ;
F_9 ( V_45 , V_19 ,
V_108 | V_109 ,
V_108 | V_109 ) ;
F_9 ( V_45 , V_20 ,
V_108 | V_110 ,
V_108 | V_110 ) ;
F_9 ( V_45 , V_12 ,
V_111 , V_111 ) ;
F_11 ( V_45 ) ;
return 0 ;
}
static int F_20 ( struct V_112 * V_113 ,
const struct V_114 * V_115 )
{
struct V_68 * V_69 ;
unsigned int V_3 ;
int V_116 ;
V_69 = F_21 ( & V_113 -> V_2 , sizeof( * V_69 ) , V_117 ) ;
if ( ! V_69 )
return - V_118 ;
V_69 -> V_99 = F_22 ( V_113 , & V_119 ) ;
if ( F_23 ( V_69 -> V_99 ) ) {
V_116 = F_24 ( V_69 -> V_99 ) ;
F_7 ( & V_113 -> V_2 , L_4 , V_116 ) ;
return V_116 ;
}
V_116 = F_25 ( V_69 -> V_99 , V_4 , & V_3 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( V_3 != 0x9093 ) {
F_7 ( & V_113 -> V_2 , L_5 , V_3 ) ;
return - V_120 ;
}
V_116 = F_26 ( V_69 -> V_99 , V_4 , 0 ) ;
if ( V_116 < 0 )
return V_116 ;
if ( V_113 -> V_2 . V_121 )
memcpy ( & V_69 -> V_76 , V_113 -> V_2 . V_121 ,
sizeof( V_69 -> V_76 ) ) ;
F_27 ( V_113 , V_69 ) ;
V_116 = F_28 ( & V_113 -> V_2 ,
& V_122 , NULL , 0 ) ;
if ( V_116 != 0 ) {
F_7 ( & V_113 -> V_2 , L_6 , V_116 ) ;
return V_116 ;
}
return 0 ;
}
static int F_29 ( struct V_112 * V_113 )
{
F_30 ( & V_113 -> V_2 ) ;
return 0 ;
}
