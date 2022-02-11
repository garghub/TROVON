static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , L_1 ) ;
F_4 ( V_4 , V_6 ) ;
F_4 ( V_4 , V_7 ) ;
F_4 ( V_4 , V_8 ) ;
F_4 ( V_4 , V_9 ) ;
F_4 ( V_4 , V_10 ) ;
F_4 ( V_4 , V_11 ) ;
F_4 ( V_4 , V_12 ) ;
F_4 ( V_4 , V_13 ) ;
F_4 ( V_4 , V_14 ) ;
F_4 ( V_4 , V_15 ) ;
F_3 ( V_4 -> V_5 , L_2 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_6 ( V_4 , V_17 , V_18 ,
V_19 , V_16 ? V_19 : 0 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_20 * V_21 ;
V_21 = & V_2 -> V_22 [ V_23 ] ;
F_8 ( V_4 , V_17 , V_24 ,
V_25 ) ;
F_8 ( V_4 , V_17 , V_26 ,
V_27 ) ;
F_8 ( V_4 , V_17 , V_28 , 0 ) ;
F_8 ( V_4 , V_17 , V_29 , 0 ) ;
F_8 ( V_4 , V_17 , V_30 ,
( V_21 -> V_31 - 2 ) & V_32 ) ;
F_8 ( V_4 , V_17 , V_33 ,
( V_21 -> V_34 - 1 ) & V_35 ) ;
F_9 ( V_4 , V_17 , V_36 ,
V_37 | V_38 ) ;
F_8 ( V_4 , V_17 , V_39 ,
V_40 | V_41 |
V_42 | V_43 ) ;
V_21 = & V_2 -> V_22 [ V_44 ] ;
}
static int F_10 ( struct V_45 * V_46 , int V_16 )
{
struct V_1 * V_2 = F_11 ( V_46 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_47 = 0 ;
if ( V_2 -> V_48 == V_49 ) {
if ( V_16 == V_49 )
return 0 ;
F_12 ( V_4 , V_50 ) ;
F_8 ( V_4 , V_17 , V_51 ,
V_52 ) ;
F_8 ( V_4 , V_17 , V_53 ,
V_54 | V_55 |
V_56 | V_57 ) ;
}
switch ( V_16 ) {
case V_58 :
F_7 ( V_2 ) ;
F_1 ( V_2 ) ;
F_13 ( & V_2 -> V_59 , 0 ) ;
F_5 ( V_2 , 1 ) ;
break;
case V_49 :
if ( V_2 -> V_48 == V_49 )
return 0 ;
if ( F_14 ( & V_46 -> V_60 , & V_2 -> V_61 ,
& V_2 -> V_59 ) )
V_47 = - V_62 ;
F_5 ( V_2 , 0 ) ;
F_15 ( V_4 , V_50 ) ;
break;
}
V_2 -> V_48 = V_16 ;
return V_47 ;
}
static struct V_20 *
F_16 ( struct V_1 * V_2 ,
struct V_63 * V_64 ,
unsigned int V_65 ,
enum V_66 V_67 )
{
if ( V_67 == V_68 )
return F_17 ( & V_2 -> V_69 , V_64 , V_65 ) ;
return & V_2 -> V_22 [ V_65 ] ;
}
static void
F_18 ( struct V_1 * V_2 ,
struct V_63 * V_64 ,
unsigned int V_65 ,
struct V_20 * V_70 ,
enum V_66 V_67 )
{
struct V_20 * V_21 ;
unsigned int V_34 = V_70 -> V_34 ;
unsigned int V_31 = V_70 -> V_31 ;
unsigned int V_71 ;
switch ( V_65 ) {
case V_23 :
for ( V_71 = 0 ; V_71 < F_19 ( V_72 ) ; V_71 ++ ) {
if ( V_70 -> V_73 == V_72 [ V_71 ] )
break;
}
if ( V_71 >= F_19 ( V_72 ) )
V_70 -> V_73 = V_74 ;
V_70 -> V_34 = F_20 ( V_75 , V_34 , 1 , 8192 ) ;
V_70 -> V_31 = F_20 ( V_75 , V_31 , 1 , 8192 ) ;
V_70 -> V_76 = V_77 ;
break;
case V_44 :
V_21 = F_16 ( V_2 , V_64 , V_23 , V_67 ) ;
memcpy ( V_70 , V_21 , sizeof( * V_70 ) ) ;
V_70 -> V_73 = V_78 ;
V_70 -> V_34 = F_20 ( V_75 , V_34 , 32 , V_70 -> V_34 ) ;
V_70 -> V_31 = F_20 ( V_75 , V_31 , 32 , V_70 -> V_31 ) ;
V_70 -> V_76 = V_79 ;
break;
}
V_70 -> V_80 = V_81 ;
}
static int F_21 ( struct V_45 * V_46 ,
struct V_63 * V_64 ,
struct V_82 * V_73 )
{
switch ( V_73 -> V_65 ) {
case V_23 :
if ( V_73 -> V_83 >= F_19 ( V_72 ) )
return - V_84 ;
V_73 -> V_73 = V_72 [ V_73 -> V_83 ] ;
break;
case V_44 :
if ( V_73 -> V_83 != 0 )
return - V_84 ;
V_73 -> V_73 = V_78 ;
break;
default:
return - V_84 ;
}
return 0 ;
}
static int F_22 ( struct V_45 * V_46 ,
struct V_63 * V_64 ,
struct V_85 * V_86 )
{
struct V_1 * V_2 = F_11 ( V_46 ) ;
struct V_20 V_21 ;
if ( V_86 -> V_83 != 0 )
return - V_84 ;
V_21 . V_73 = V_86 -> V_73 ;
V_21 . V_34 = 1 ;
V_21 . V_31 = 1 ;
F_18 ( V_2 , V_64 , V_86 -> V_65 , & V_21 , V_86 -> V_67 ) ;
V_86 -> V_87 = V_21 . V_34 ;
V_86 -> V_88 = V_21 . V_31 ;
if ( V_21 . V_73 != V_86 -> V_73 )
return - V_84 ;
V_21 . V_73 = V_86 -> V_73 ;
V_21 . V_34 = - 1 ;
V_21 . V_31 = - 1 ;
F_18 ( V_2 , V_64 , V_86 -> V_65 , & V_21 , V_86 -> V_67 ) ;
V_86 -> V_89 = V_21 . V_34 ;
V_86 -> V_90 = V_21 . V_31 ;
return 0 ;
}
static int F_23 ( struct V_45 * V_46 ,
struct V_63 * V_64 ,
struct V_91 * V_70 )
{
struct V_1 * V_2 = F_11 ( V_46 ) ;
struct V_20 * V_21 ;
V_21 = F_16 ( V_2 , V_64 , V_70 -> V_65 , V_70 -> V_67 ) ;
if ( ! V_21 )
return - V_84 ;
V_70 -> V_21 = * V_21 ;
return 0 ;
}
static int F_24 ( struct V_45 * V_46 ,
struct V_63 * V_64 ,
struct V_91 * V_70 )
{
struct V_1 * V_2 = F_11 ( V_46 ) ;
struct V_20 * V_21 ;
V_21 = F_16 ( V_2 , V_64 , V_70 -> V_65 , V_70 -> V_67 ) ;
if ( ! V_21 )
return - V_84 ;
F_18 ( V_2 , V_64 , V_70 -> V_65 , & V_70 -> V_21 , V_70 -> V_67 ) ;
* V_21 = V_70 -> V_21 ;
if ( V_70 -> V_65 == V_23 ) {
V_21 = F_16 ( V_2 , V_64 , V_44 ,
V_70 -> V_67 ) ;
* V_21 = V_70 -> V_21 ;
F_18 ( V_2 , V_64 , V_44 , V_21 ,
V_70 -> V_67 ) ;
}
return 0 ;
}
static int F_25 ( struct V_45 * V_46 , struct V_92 * V_93 ,
struct V_91 * V_94 ,
struct V_91 * V_95 )
{
if ( V_94 -> V_21 . V_34 != V_95 -> V_21 . V_34 ||
V_94 -> V_21 . V_31 != V_95 -> V_21 . V_31 )
return - V_96 ;
if ( V_94 -> V_21 . V_73 != V_95 -> V_21 . V_73 )
return - V_96 ;
return 0 ;
}
static int F_26 ( struct V_45 * V_46 , struct V_97 * V_98 )
{
struct V_91 V_21 ;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_65 = V_23 ;
V_21 . V_67 = V_98 ? V_68 : V_99 ;
V_21 . V_21 . V_73 = V_74 ;
V_21 . V_21 . V_34 = 4096 ;
V_21 . V_21 . V_31 = 4096 ;
F_24 ( V_46 , V_98 ? V_98 -> V_65 : NULL , & V_21 ) ;
return 0 ;
}
static int F_27 ( struct V_100 * V_60 ,
const struct V_101 * V_102 ,
const struct V_101 * V_103 , V_75 V_104 )
{
struct V_45 * V_46 = F_28 ( V_60 ) ;
struct V_1 * V_2 = F_11 ( V_46 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_102 -> V_83 | F_29 ( V_103 -> V_60 ) ) {
case V_23 | V_105 :
if ( ! ( V_104 & V_106 ) ) {
V_2 -> V_107 = V_108 ;
break;
}
if ( V_2 -> V_107 != V_108 )
return - V_109 ;
if ( V_103 -> V_60 == & V_4 -> V_110 . V_69 . V_60 )
V_2 -> V_107 = V_111 ;
break;
case V_44 | V_105 :
if ( V_104 & V_106 ) {
if ( V_2 -> V_112 & ~ V_113 )
return - V_109 ;
V_2 -> V_112 |= V_113 ;
} else {
V_2 -> V_112 &= ~ V_113 ;
}
break;
default:
return - V_84 ;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_45 * V_46 = & V_2 -> V_69 ;
struct V_101 * V_114 = V_2 -> V_114 ;
struct V_100 * V_115 = & V_46 -> V_60 ;
int V_47 ;
V_2 -> V_107 = V_108 ;
F_31 ( V_46 , & V_116 ) ;
V_46 -> V_117 = & V_118 ;
F_32 ( V_46 -> V_119 , L_3 , sizeof( V_46 -> V_119 ) ) ;
V_46 -> V_120 = 1 << 16 ;
F_33 ( V_46 , V_2 ) ;
V_46 -> V_104 |= V_121 ;
V_114 [ V_23 ] . V_104 = V_122 ;
V_114 [ V_44 ] . V_104 = V_123 ;
V_115 -> V_124 = & V_125 ;
V_47 = F_34 ( V_115 , V_126 , V_114 , 0 ) ;
if ( V_47 < 0 )
return V_47 ;
F_26 ( V_46 , NULL ) ;
return 0 ;
}
void F_35 ( struct V_1 * V_2 )
{
F_36 ( & V_2 -> V_69 ) ;
}
int F_37 ( struct V_1 * V_2 ,
struct V_127 * V_128 )
{
int V_47 ;
V_47 = F_38 ( V_128 , & V_2 -> V_69 ) ;
if ( V_47 < 0 )
goto error;
return 0 ;
error:
F_35 ( V_2 ) ;
return V_47 ;
}
int F_39 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
V_2 -> V_48 = V_49 ;
F_40 ( & V_2 -> V_61 ) ;
return F_30 ( V_2 ) ;
}
void F_41 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = & V_4 -> V_2 ;
F_42 ( & V_2 -> V_69 . V_60 ) ;
}
