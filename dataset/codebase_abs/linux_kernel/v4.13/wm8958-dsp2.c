static int F_1 ( struct V_1 * V_2 , const char * V_3 ,
const struct V_4 * V_5 , bool V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
T_1 V_9 ;
T_2 V_10 ;
const T_3 * V_11 ;
char * V_12 ;
T_4 V_13 , V_14 ;
int V_15 = 0 ;
if ( V_8 -> V_16 == V_5 )
return 0 ;
if ( V_5 -> V_17 < 32 ) {
F_3 ( V_2 -> V_18 , L_1 ,
V_3 , V_5 -> V_17 ) ;
goto V_19;
}
if ( memcmp ( V_5 -> V_11 , L_2 , 4 ) != 0 ) {
memcpy ( & V_10 , V_5 -> V_11 , sizeof( V_10 ) ) ;
V_10 = F_4 ( V_10 ) ;
F_3 ( V_2 -> V_18 , L_3 ,
V_3 , V_10 ) ;
goto V_19;
}
memcpy ( & V_10 , V_5 -> V_11 + 4 , sizeof( V_10 ) ) ;
V_14 = F_4 ( V_10 ) ;
memcpy ( & V_10 , V_5 -> V_11 + 8 , sizeof( V_10 ) ) ;
V_10 = F_4 ( V_10 ) ;
if ( ( V_10 >> 24 ) & 0xff ) {
F_3 ( V_2 -> V_18 , L_4 ,
V_3 , ( V_10 >> 24 ) & 0xff ) ;
goto V_19;
}
if ( ( V_10 & 0xffff ) != 8958 ) {
F_3 ( V_2 -> V_18 , L_5 ,
V_3 , V_10 & 0xffff ) ;
goto V_19;
}
if ( ( ( V_10 >> 16 ) & 0xff ) != 0xc ) {
F_3 ( V_2 -> V_18 , L_6 ,
V_3 , ( V_10 >> 16 ) & 0xff ) ;
goto V_19;
}
if ( V_6 ) {
memcpy ( & V_9 , V_5 -> V_11 + 24 , sizeof( T_1 ) ) ;
F_5 ( V_2 -> V_18 , L_7 ,
V_3 , F_6 ( V_9 ) ) ;
} else {
F_7 ( V_2 , 0x102 , 0x2 ) ;
F_7 ( V_2 , 0x900 , 0x2 ) ;
}
V_11 = V_5 -> V_11 + V_14 ;
V_14 = V_5 -> V_17 - V_14 ;
while ( V_14 ) {
if ( V_14 < 12 ) {
F_3 ( V_2 -> V_18 , L_8 ,
V_3 , V_14 ) ;
goto V_19;
}
memcpy ( & V_10 , V_11 + 4 , sizeof( V_10 ) ) ;
V_13 = F_4 ( V_10 ) ;
if ( V_13 + 8 > V_14 ) {
F_3 ( V_2 -> V_18 , L_9 ,
V_13 ) ;
goto V_19;
}
if ( V_13 == 0 ) {
F_3 ( V_2 -> V_18 , L_10 ) ;
goto V_19;
}
memcpy ( & V_10 , V_11 , sizeof( V_10 ) ) ;
V_10 = F_4 ( V_10 ) ;
switch ( ( V_10 >> 24 ) & 0xff ) {
case V_20 :
if ( ! V_6 )
break;
V_12 = F_8 ( V_13 + 1 , V_21 ) ;
if ( V_12 ) {
memcpy ( V_12 , V_11 + 8 , V_13 ) ;
F_5 ( V_2 -> V_18 , L_11 , V_3 , V_12 ) ;
F_9 ( V_12 ) ;
} else {
F_3 ( V_2 -> V_18 , L_12 ) ;
}
break;
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
F_10 ( V_2 -> V_18 , L_13 , V_3 ,
V_13 , ( V_10 >> 24 ) & 0xff ,
V_10 & 0xffffff ) ;
if ( V_6 )
break;
V_10 &= 0xffffff ;
F_11 ( V_8 -> V_8 ,
V_10 & 0xffffff ,
V_13 / 2 ,
( void * ) ( V_11 + 8 ) ) ;
break;
default:
F_12 ( V_2 -> V_18 , L_14 ,
V_3 , ( V_10 >> 24 ) & 0xff ) ;
break;
}
V_13 += V_13 % 4 ;
V_11 += V_13 + 8 ;
V_14 -= V_13 + 8 ;
}
if ( ! V_6 ) {
F_10 ( V_2 -> V_18 , L_15 , V_3 ) ;
V_8 -> V_16 = V_5 ;
} else {
F_5 ( V_2 -> V_18 , L_16 , V_3 ) ;
}
goto V_29;
V_19:
V_15 = - V_30 ;
V_29:
if ( ! V_6 ) {
F_7 ( V_2 , 0x900 , 0x0 ) ;
F_7 ( V_2 , 0x102 , 0x0 ) ;
}
return V_15 ;
}
static void F_13 ( struct V_1 * V_2 , int V_31 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_8 * V_32 = V_8 -> V_8 ;
int V_33 ;
if ( F_14 ( V_2 , V_34 ) & V_35 )
return;
if ( V_8 -> V_36 )
F_1 ( V_2 , L_17 , V_8 -> V_36 , false ) ;
F_15 ( V_2 , V_34 ,
V_35 , V_35 ) ;
if ( V_32 -> V_37 . V_38 ) {
struct V_39 * V_40
= & V_32 -> V_37 . V_41 [ V_8 -> V_42 ] ;
for ( V_33 = 0 ; V_33 < F_16 ( V_40 -> V_43 ) ; V_33 ++ )
F_7 ( V_2 , V_33 + V_44 ,
V_40 -> V_43 [ V_33 ] ) ;
for ( V_33 = 0 ; V_33 < F_16 ( V_40 -> V_45 ) ; V_33 ++ )
F_7 ( V_2 ,
V_33 + V_46 ,
V_40 -> V_45 [ V_33 ] ) ;
}
F_7 ( V_2 , V_47 ,
V_48 ) ;
F_15 ( V_2 , V_49 ,
V_50 |
V_51 ,
V_31 << V_52 |
V_50 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_31 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_8 * V_32 = V_8 -> V_8 ;
int V_33 , V_53 ;
if ( V_8 -> V_54 )
F_1 ( V_2 , L_18 , V_8 -> V_54 , false ) ;
F_15 ( V_2 , V_34 ,
V_35 , V_35 ) ;
if ( V_32 -> V_37 . V_38 ) {
struct V_39 * V_40
= & V_32 -> V_37 . V_41 [ V_8 -> V_42 ] ;
for ( V_33 = 0 ; V_33 < F_16 ( V_40 -> V_55 ) ; V_33 ++ )
F_7 ( V_2 , V_33 + 0x2800 ,
V_40 -> V_55 [ V_33 ] ) ;
}
if ( V_32 -> V_37 . V_56 ) {
struct V_57 * V_40
= & V_32 -> V_37 . V_58 [ V_8 -> V_59 ] ;
for ( V_33 = 0 ; V_33 < F_16 ( V_40 -> V_60 ) ; V_33 ++ )
F_7 ( V_2 , V_33 + 0x2600 , V_40 -> V_60 [ V_33 ] ) ;
}
if ( V_32 -> V_37 . V_61 ) {
struct V_62 * V_40
= & V_32 -> V_37 . V_63 [ V_8 -> V_64 ] ;
for ( V_33 = 0 ; V_33 < F_16 ( V_40 -> V_60 ) ; V_33 ++ )
F_7 ( V_2 , V_33 + 0x2400 , V_40 -> V_60 [ V_33 ] ) ;
}
F_7 ( V_2 , V_47 ,
V_48 ) ;
V_53 = 0 ;
if ( V_8 -> V_65 [ V_31 ] )
V_53 |= 0x8 ;
if ( V_8 -> V_66 [ V_31 ] )
V_53 |= 0x4 ;
if ( V_8 -> V_67 [ V_31 ] )
V_53 |= 0x2 ;
if ( V_8 -> V_68 [ V_31 ] )
V_53 |= 0x1 ;
F_7 ( V_2 , 0x2201 , V_53 ) ;
F_15 ( V_2 , V_49 ,
V_51 | V_50 ,
V_31 << V_52 | V_50 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_31 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_8 * V_32 = V_8 -> V_8 ;
int V_33 ;
F_1 ( V_2 , L_19 , V_8 -> V_69 , false ) ;
F_15 ( V_2 , V_34 ,
V_35 , V_35 ) ;
if ( V_32 -> V_37 . V_70 ) {
struct V_71 * V_40
= & V_32 -> V_37 . V_72 [ V_8 -> V_73 ] ;
for ( V_33 = 0 ; V_33 < F_16 ( V_40 -> V_60 ) ; V_33 ++ )
F_7 ( V_2 , V_33 + 0x2200 ,
V_40 -> V_60 [ V_33 ] ) ;
}
F_7 ( V_2 , V_47 ,
V_48 ) ;
F_15 ( V_2 , V_49 ,
V_51 | V_50 ,
V_31 << V_52 | V_50 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_31 , int V_74 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_75 = F_14 ( V_2 , V_76 ) ;
int V_53 , V_77 , V_78 ;
switch ( V_31 ) {
case 0 :
V_75 &= ( V_79 | V_80 ) ;
V_78 = 0 ;
break;
case 1 :
V_75 &= ( V_81 | V_82 ) ;
V_78 = 0 ;
break;
case 2 :
V_75 &= ( V_83 | V_84 ) ;
V_78 = 1 ;
break;
default:
F_20 ( 1 , L_20 , V_31 ) ;
return;
}
V_53 = V_8 -> V_65 [ V_31 ] || V_8 -> V_68 [ V_31 ] ||
V_8 -> V_67 [ V_31 ] || V_8 -> V_66 [ V_31 ] ||
V_8 -> V_85 [ V_31 ] ;
if ( ! V_75 )
V_53 = 0 ;
V_77 = F_14 ( V_2 , V_34 ) ;
F_10 ( V_2 -> V_18 , L_21 ,
V_31 , V_8 -> V_86 , V_74 , V_75 , V_77 ) ;
if ( V_74 && V_53 ) {
if ( V_77 & V_35 )
return;
if ( ! ( F_14 ( V_2 , V_87 )
& V_88 ) &&
! ( F_14 ( V_2 , V_89 )
& V_90 ) )
return;
F_15 ( V_2 , V_91 ,
V_92 | V_93 ,
V_78 << V_94 |
V_93 ) ;
if ( V_8 -> V_85 [ V_31 ] )
F_18 ( V_2 , V_31 ) ;
else if ( V_8 -> V_68 [ V_31 ] || V_8 -> V_67 [ V_31 ] ||
V_8 -> V_66 [ V_31 ] )
F_17 ( V_2 , V_31 ) ;
else if ( V_8 -> V_65 [ V_31 ] )
F_13 ( V_2 , V_31 ) ;
V_8 -> V_86 = V_31 ;
F_10 ( V_2 -> V_18 , L_22 , V_31 ) ;
}
if ( ! V_74 && V_8 -> V_86 == V_31 ) {
if ( ! ( V_77 & V_35 ) )
return;
F_15 ( V_2 , V_49 ,
V_50 , 0 ) ;
F_7 ( V_2 , V_47 ,
V_95 ) ;
F_15 ( V_2 , V_34 ,
V_35 , 0 ) ;
F_15 ( V_2 , V_91 ,
V_93 , 0 ) ;
V_8 -> V_86 = - 1 ;
F_10 ( V_2 -> V_18 , L_23 ) ;
}
}
int F_21 ( struct V_96 * V_97 ,
struct V_98 * V_99 , int V_100 )
{
struct V_1 * V_2 = F_22 ( V_97 -> V_101 ) ;
int V_33 ;
switch ( V_100 ) {
case V_102 :
case V_103 :
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ )
F_19 ( V_2 , V_33 , 1 ) ;
break;
case V_104 :
case V_105 :
for ( V_33 = 0 ; V_33 < 3 ; V_33 ++ )
F_19 ( V_2 , V_33 , 0 ) ;
break;
}
return 0 ;
}
static int F_23 ( struct V_7 * V_8 , int V_78 )
{
int V_33 ;
for ( V_33 = 0 ; V_33 < F_16 ( V_8 -> V_65 ) ; V_33 ++ ) {
if ( V_33 == V_78 )
continue;
if ( V_8 -> V_65 [ V_33 ] || V_8 -> V_68 [ V_33 ] ||
V_8 -> V_67 [ V_33 ] || V_8 -> V_66 [ V_33 ] )
return 1 ;
}
return 0 ;
}
static int F_24 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_8 * V_32 = V_8 -> V_8 ;
int V_108 = V_107 -> V_108 . V_109 . V_110 [ 0 ] ;
int V_77 ;
V_77 = F_14 ( V_2 , V_91 ) ;
if ( V_77 < 0 || V_77 & V_93 )
return - V_111 ;
if ( V_108 >= V_32 -> V_37 . V_38 )
return - V_30 ;
V_8 -> V_42 = V_108 ;
return 0 ;
}
static int F_26 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . V_109 . V_110 [ 0 ] = V_8 -> V_42 ;
return 0 ;
}
static int F_27 ( struct V_98 * V_99 ,
struct V_112 * V_113 )
{
V_113 -> type = V_114 ;
V_113 -> V_115 = 1 ;
V_113 -> V_108 . integer . V_116 = 0 ;
V_113 -> V_108 . integer . V_117 = 1 ;
return 0 ;
}
static int F_28 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
int V_36 = V_99 -> V_118 ;
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . integer . V_108 [ 0 ] = V_8 -> V_65 [ V_36 ] ;
return 0 ;
}
static int F_29 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
int V_36 = V_99 -> V_118 ;
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_65 [ V_36 ] == V_107 -> V_108 . integer . V_108 [ 0 ] )
return 0 ;
if ( V_107 -> V_108 . integer . V_108 [ 0 ] > 1 )
return - V_30 ;
if ( F_23 ( V_8 , V_36 ) ) {
F_10 ( V_2 -> V_18 , L_24 , V_36 ) ;
return - V_111 ;
}
if ( V_8 -> V_85 [ V_36 ] )
return - V_111 ;
V_8 -> V_65 [ V_36 ] = V_107 -> V_108 . integer . V_108 [ 0 ] ;
F_19 ( V_2 , V_36 , V_8 -> V_65 [ V_36 ] ) ;
return 0 ;
}
static int F_30 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_8 * V_32 = V_8 -> V_8 ;
int V_108 = V_107 -> V_108 . V_109 . V_110 [ 0 ] ;
int V_77 ;
V_77 = F_14 ( V_2 , V_91 ) ;
if ( V_77 < 0 || V_77 & V_93 )
return - V_111 ;
if ( V_108 >= V_32 -> V_37 . V_56 )
return - V_30 ;
V_8 -> V_59 = V_108 ;
return 0 ;
}
static int F_31 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . V_109 . V_110 [ 0 ] = V_8 -> V_59 ;
return 0 ;
}
static int F_32 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_8 * V_32 = V_8 -> V_8 ;
int V_108 = V_107 -> V_108 . V_109 . V_110 [ 0 ] ;
int V_77 ;
V_77 = F_14 ( V_2 , V_91 ) ;
if ( V_77 < 0 || V_77 & V_93 )
return - V_111 ;
if ( V_108 >= V_32 -> V_37 . V_61 )
return - V_30 ;
V_8 -> V_64 = V_108 ;
return 0 ;
}
static int F_33 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . V_109 . V_110 [ 0 ] = V_8 -> V_64 ;
return 0 ;
}
static int F_34 ( struct V_98 * V_99 ,
struct V_112 * V_113 )
{
V_113 -> type = V_114 ;
V_113 -> V_115 = 1 ;
V_113 -> V_108 . integer . V_116 = 0 ;
V_113 -> V_108 . integer . V_117 = 1 ;
return 0 ;
}
static int F_35 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
int V_119 = V_99 -> V_118 ;
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . integer . V_108 [ 0 ] = V_8 -> V_68 [ V_119 ] ;
return 0 ;
}
static int F_36 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
int V_119 = V_99 -> V_118 ;
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_68 [ V_119 ] == V_107 -> V_108 . integer . V_108 [ 0 ] )
return 0 ;
if ( V_107 -> V_108 . integer . V_108 [ 0 ] > 1 )
return - V_30 ;
if ( ! V_8 -> V_54 )
return - V_120 ;
if ( F_23 ( V_8 , V_119 ) ) {
F_10 ( V_2 -> V_18 , L_24 , V_119 ) ;
return - V_111 ;
}
if ( V_8 -> V_85 [ V_119 ] )
return - V_111 ;
V_8 -> V_68 [ V_119 ] = V_107 -> V_108 . integer . V_108 [ 0 ] ;
F_19 ( V_2 , V_119 , V_8 -> V_68 [ V_119 ] ) ;
return 0 ;
}
static int F_37 ( struct V_98 * V_99 ,
struct V_112 * V_113 )
{
V_113 -> type = V_114 ;
V_113 -> V_115 = 1 ;
V_113 -> V_108 . integer . V_116 = 0 ;
V_113 -> V_108 . integer . V_117 = 1 ;
return 0 ;
}
static int F_38 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
int V_121 = V_99 -> V_118 ;
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_121 < 3 )
V_107 -> V_108 . integer . V_108 [ 0 ] = V_8 -> V_67 [ V_121 % 3 ] ;
else
V_107 -> V_108 . integer . V_108 [ 0 ] = V_8 -> V_66 [ V_121 % 3 ] ;
return 0 ;
}
static int F_39 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
int V_121 = V_99 -> V_118 ;
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_121 < 3 ) {
if ( V_8 -> V_67 [ V_121 % 3 ] ==
V_107 -> V_108 . integer . V_108 [ 0 ] )
return 0 ;
} else {
if ( V_8 -> V_66 [ V_121 % 3 ] ==
V_107 -> V_108 . integer . V_108 [ 0 ] )
return 0 ;
}
if ( V_107 -> V_108 . integer . V_108 [ 0 ] > 1 )
return - V_30 ;
if ( ! V_8 -> V_54 )
return - V_120 ;
if ( F_23 ( V_8 , V_121 % 3 ) ) {
F_10 ( V_2 -> V_18 , L_24 , V_121 ) ;
return - V_111 ;
}
if ( V_8 -> V_85 [ V_121 % 3 ] )
return - V_111 ;
if ( V_121 < 3 )
V_8 -> V_67 [ V_121 % 3 ] = V_107 -> V_108 . integer . V_108 [ 0 ] ;
else
V_8 -> V_66 [ V_121 % 3 ] = V_107 -> V_108 . integer . V_108 [ 0 ] ;
F_19 ( V_2 , V_121 % 3 , V_107 -> V_108 . integer . V_108 [ 0 ] ) ;
return 0 ;
}
static int F_40 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_8 * V_32 = V_8 -> V_8 ;
int V_108 = V_107 -> V_108 . V_109 . V_110 [ 0 ] ;
int V_77 ;
V_77 = F_14 ( V_2 , V_91 ) ;
if ( V_77 < 0 || V_77 & V_93 )
return - V_111 ;
if ( V_108 >= V_32 -> V_37 . V_70 )
return - V_30 ;
V_8 -> V_73 = V_108 ;
return 0 ;
}
static int F_41 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . V_109 . V_110 [ 0 ] = V_8 -> V_73 ;
return 0 ;
}
static int F_42 ( struct V_98 * V_99 ,
struct V_112 * V_113 )
{
V_113 -> type = V_114 ;
V_113 -> V_115 = 1 ;
V_113 -> V_108 . integer . V_116 = 0 ;
V_113 -> V_108 . integer . V_117 = 1 ;
return 0 ;
}
static int F_43 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
int V_122 = V_99 -> V_118 ;
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . integer . V_108 [ 0 ] = V_8 -> V_85 [ V_122 ] ;
return 0 ;
}
static int F_44 ( struct V_98 * V_99 ,
struct V_106 * V_107 )
{
int V_122 = V_99 -> V_118 ;
struct V_1 * V_2 = F_25 ( V_99 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_85 [ V_122 ] == V_107 -> V_108 . integer . V_108 [ 0 ] )
return 0 ;
if ( V_107 -> V_108 . integer . V_108 [ 0 ] > 1 )
return - V_30 ;
if ( ! V_8 -> V_69 )
return - V_120 ;
if ( F_23 ( V_8 , V_122 ) ) {
F_10 ( V_2 -> V_18 , L_24 , V_122 ) ;
return - V_111 ;
}
if ( V_8 -> V_65 [ V_122 ] || V_8 -> V_68 [ V_122 ] ||
V_8 -> V_67 [ V_122 ] || V_8 -> V_66 [ V_122 ] )
return - V_111 ;
V_8 -> V_85 [ V_122 ] = V_107 -> V_108 . integer . V_108 [ 0 ] ;
F_19 ( V_2 , V_122 , V_107 -> V_108 . integer . V_108 [ 0 ] ) ;
return 0 ;
}
static void F_45 ( const struct V_4 * V_5 , void * V_123 )
{
struct V_1 * V_2 = V_123 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_5 && ( F_1 ( V_2 , L_19 , V_5 , true ) == 0 ) ) {
F_46 ( & V_8 -> V_124 ) ;
V_8 -> V_69 = V_5 ;
F_47 ( & V_8 -> V_124 ) ;
}
}
static void F_48 ( const struct V_4 * V_5 , void * V_123 )
{
struct V_1 * V_2 = V_123 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_5 && ( F_1 ( V_2 , L_18 , V_5 , true ) == 0 ) ) {
F_46 ( & V_8 -> V_124 ) ;
V_8 -> V_54 = V_5 ;
F_47 ( & V_8 -> V_124 ) ;
}
}
static void F_49 ( const struct V_4 * V_5 , void * V_123 )
{
struct V_1 * V_2 = V_123 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_5 && ( F_1 ( V_2 , L_17 , V_5 , true ) == 0 ) ) {
F_46 ( & V_8 -> V_124 ) ;
V_8 -> V_36 = V_5 ;
F_47 ( & V_8 -> V_124 ) ;
}
}
void F_50 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_8 * V_32 = V_8 -> V_8 ;
struct V_125 * V_37 = & V_32 -> V_37 ;
int V_15 , V_33 ;
V_8 -> V_86 = - 1 ;
F_51 ( V_2 , V_126 ,
F_16 ( V_126 ) ) ;
F_51 ( V_2 , V_127 ,
F_16 ( V_127 ) ) ;
F_51 ( V_2 , V_128 ,
F_16 ( V_128 ) ) ;
F_52 ( V_129 , V_130 ,
L_25 , V_2 -> V_18 , V_21 ,
V_2 , F_49 ) ;
F_52 ( V_129 , V_130 ,
L_26 , V_2 -> V_18 , V_21 ,
V_2 , F_48 ) ;
F_52 ( V_129 , V_130 ,
L_27 , V_2 -> V_18 , V_21 ,
V_2 , F_45 ) ;
if ( V_37 -> V_38 ) {
struct V_131 V_32 [] = {
F_53 ( L_28 , V_8 -> V_132 ,
F_26 , F_24 ) ,
} ;
V_8 -> V_133 = F_54 ( sizeof( char * )
* V_37 -> V_38 , V_21 ) ;
if ( ! V_8 -> V_133 )
return;
for ( V_33 = 0 ; V_33 < V_37 -> V_38 ; V_33 ++ )
V_8 -> V_133 [ V_33 ] = V_37 -> V_41 [ V_33 ] . V_3 ;
V_8 -> V_132 . V_134 = V_37 -> V_38 ;
V_8 -> V_132 . V_135 = V_8 -> V_133 ;
V_15 = F_51 ( V_8 -> V_136 . V_2 ,
V_32 , 1 ) ;
if ( V_15 != 0 )
F_3 ( V_8 -> V_136 . V_2 -> V_18 ,
L_29 , V_15 ) ;
}
if ( V_37 -> V_56 ) {
struct V_131 V_32 [] = {
F_53 ( L_30 , V_8 -> V_137 ,
F_31 , F_30 ) ,
} ;
V_8 -> V_138 = F_54 ( sizeof( char * )
* V_37 -> V_56 , V_21 ) ;
if ( ! V_8 -> V_138 )
return;
for ( V_33 = 0 ; V_33 < V_37 -> V_56 ; V_33 ++ )
V_8 -> V_138 [ V_33 ] = V_37 -> V_58 [ V_33 ] . V_3 ;
V_8 -> V_137 . V_134 = V_37 -> V_56 ;
V_8 -> V_137 . V_135 = V_8 -> V_138 ;
V_15 = F_51 ( V_8 -> V_136 . V_2 ,
V_32 , 1 ) ;
if ( V_15 != 0 )
F_3 ( V_8 -> V_136 . V_2 -> V_18 ,
L_31 , V_15 ) ;
}
if ( V_37 -> V_61 ) {
struct V_131 V_32 [] = {
F_53 ( L_32 , V_8 -> V_139 ,
F_33 ,
F_32 ) ,
} ;
V_8 -> V_140 = F_54 ( sizeof( char * )
* V_37 -> V_61 , V_21 ) ;
if ( ! V_8 -> V_140 )
return;
for ( V_33 = 0 ; V_33 < V_37 -> V_61 ; V_33 ++ )
V_8 -> V_140 [ V_33 ] = V_37 -> V_63 [ V_33 ] . V_3 ;
V_8 -> V_139 . V_134 = V_37 -> V_61 ;
V_8 -> V_139 . V_135 = V_8 -> V_140 ;
V_15 = F_51 ( V_8 -> V_136 . V_2 ,
V_32 , 1 ) ;
if ( V_15 != 0 )
F_3 ( V_8 -> V_136 . V_2 -> V_18 ,
L_33 ,
V_15 ) ;
}
if ( V_37 -> V_70 ) {
struct V_131 V_32 [] = {
F_53 ( L_34 , V_8 -> V_141 ,
F_41 ,
F_40 ) ,
} ;
V_8 -> V_142 = F_54 ( sizeof( char * )
* V_37 -> V_70 , V_21 ) ;
if ( ! V_8 -> V_142 )
return;
for ( V_33 = 0 ; V_33 < V_37 -> V_70 ; V_33 ++ )
V_8 -> V_142 [ V_33 ] = V_37 -> V_72 [ V_33 ] . V_3 ;
V_8 -> V_141 . V_134 = V_37 -> V_70 ;
V_8 -> V_141 . V_135 = V_8 -> V_142 ;
V_15 = F_51 ( V_8 -> V_136 . V_2 ,
V_32 , 1 ) ;
if ( V_15 != 0 )
F_3 ( V_8 -> V_136 . V_2 -> V_18 ,
L_35 ,
V_15 ) ;
}
}
