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
F_3 ( V_2 -> V_18 , L_1 , V_3 ) ;
goto V_19;
}
if ( memcmp ( V_5 -> V_11 , L_2 , 4 ) != 0 ) {
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
F_11 ( V_2 -> V_29 ,
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
goto V_30;
V_19:
V_15 = - V_31 ;
V_30:
if ( ! V_6 ) {
F_7 ( V_2 , 0x900 , 0x0 ) ;
F_7 ( V_2 , 0x102 , 0x0 ) ;
}
return V_15 ;
}
static void F_13 ( struct V_1 * V_2 , int V_32 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_33 * V_34 = V_8 -> V_34 ;
int V_35 ;
if ( F_14 ( V_2 , V_36 ) & V_37 )
return;
if ( V_8 -> V_38 )
F_1 ( V_2 , L_17 , V_8 -> V_38 , false ) ;
F_15 ( V_2 , V_36 ,
V_37 , V_37 ) ;
if ( V_34 && V_34 -> V_39 ) {
struct V_40 * V_41
= & V_34 -> V_42 [ V_8 -> V_43 ] ;
for ( V_35 = 0 ; V_35 < F_16 ( V_41 -> V_44 ) ; V_35 ++ )
F_7 ( V_2 , V_35 + V_45 ,
V_41 -> V_44 [ V_35 ] ) ;
for ( V_35 = 0 ; V_35 < F_16 ( V_41 -> V_46 ) ; V_35 ++ )
F_7 ( V_2 ,
V_35 + V_47 ,
V_41 -> V_46 [ V_35 ] ) ;
}
F_7 ( V_2 , V_48 ,
V_49 ) ;
F_15 ( V_2 , V_50 ,
V_51 |
V_52 ,
V_32 << V_53 |
V_51 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_32 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_33 * V_34 = V_8 -> V_34 ;
int V_35 , V_54 ;
if ( V_8 -> V_55 )
F_1 ( V_2 , L_18 , V_8 -> V_55 , false ) ;
F_15 ( V_2 , V_36 ,
V_37 , V_37 ) ;
if ( V_34 && V_34 -> V_39 ) {
struct V_40 * V_41
= & V_34 -> V_42 [ V_8 -> V_43 ] ;
for ( V_35 = 0 ; V_35 < F_16 ( V_41 -> V_56 ) ; V_35 ++ )
F_7 ( V_2 , V_35 + 0x2800 ,
V_41 -> V_56 [ V_35 ] ) ;
}
if ( V_34 && V_34 -> V_57 ) {
struct V_58 * V_41
= & V_34 -> V_59 [ V_8 -> V_60 ] ;
for ( V_35 = 0 ; V_35 < F_16 ( V_41 -> V_61 ) ; V_35 ++ )
F_7 ( V_2 , V_35 + 0x2600 , V_41 -> V_61 [ V_35 ] ) ;
}
if ( V_34 && V_34 -> V_62 ) {
struct V_63 * V_41
= & V_34 -> V_64 [ V_8 -> V_65 ] ;
for ( V_35 = 0 ; V_35 < F_16 ( V_41 -> V_61 ) ; V_35 ++ )
F_7 ( V_2 , V_35 + 0x2400 , V_41 -> V_61 [ V_35 ] ) ;
}
F_7 ( V_2 , V_48 ,
V_49 ) ;
V_54 = 0 ;
if ( V_8 -> V_66 [ V_32 ] )
V_54 |= 0x8 ;
if ( V_8 -> V_67 [ V_32 ] )
V_54 |= 0x4 ;
if ( V_8 -> V_68 [ V_32 ] )
V_54 |= 0x2 ;
if ( V_8 -> V_69 [ V_32 ] )
V_54 |= 0x1 ;
F_7 ( V_2 , 0x2201 , V_54 ) ;
F_15 ( V_2 , V_50 ,
V_52 | V_51 ,
V_32 << V_53 | V_51 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_32 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_33 * V_34 = V_8 -> V_34 ;
int V_35 ;
F_1 ( V_2 , L_19 , V_8 -> V_70 , false ) ;
F_15 ( V_2 , V_36 ,
V_37 , V_37 ) ;
if ( V_34 && V_34 -> V_71 ) {
struct V_72 * V_41
= & V_34 -> V_73 [ V_8 -> V_74 ] ;
for ( V_35 = 0 ; V_35 < F_16 ( V_41 -> V_61 ) ; V_35 ++ )
F_7 ( V_2 , V_35 + 0x2200 ,
V_41 -> V_61 [ V_35 ] ) ;
}
F_7 ( V_2 , V_48 ,
V_49 ) ;
F_15 ( V_2 , V_50 ,
V_52 | V_51 ,
V_32 << V_53 | V_51 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_32 , int V_75 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_76 = F_14 ( V_2 , V_77 ) ;
int V_54 , V_78 , V_79 ;
switch ( V_32 ) {
case 0 :
V_76 &= ( V_80 | V_81 ) ;
V_79 = 0 ;
break;
case 1 :
V_76 &= ( V_82 | V_83 ) ;
V_79 = 0 ;
break;
case 2 :
V_76 &= ( V_84 | V_85 ) ;
V_79 = 1 ;
break;
default:
F_20 () ;
return;
}
V_54 = V_8 -> V_66 [ V_32 ] || V_8 -> V_69 [ V_32 ] ||
V_8 -> V_68 [ V_32 ] || V_8 -> V_67 [ V_32 ] ||
V_8 -> V_86 [ V_32 ] ;
if ( ! V_76 )
V_54 = 0 ;
V_78 = F_14 ( V_2 , V_36 ) ;
F_10 ( V_2 -> V_18 , L_20 ,
V_32 , V_8 -> V_87 , V_75 , V_76 , V_78 ) ;
if ( V_75 && V_54 ) {
if ( V_78 & V_37 )
return;
if ( ! ( F_14 ( V_2 , V_88 )
& V_89 ) &&
! ( F_14 ( V_2 , V_90 )
& V_91 ) )
return;
F_15 ( V_2 , V_92 ,
V_93 | V_94 ,
V_79 << V_95 |
V_94 ) ;
if ( V_8 -> V_86 [ V_32 ] )
F_18 ( V_2 , V_32 ) ;
else if ( V_8 -> V_69 [ V_32 ] || V_8 -> V_68 [ V_32 ] ||
V_8 -> V_67 [ V_32 ] )
F_17 ( V_2 , V_32 ) ;
else if ( V_8 -> V_66 [ V_32 ] )
F_13 ( V_2 , V_32 ) ;
V_8 -> V_87 = V_32 ;
F_10 ( V_2 -> V_18 , L_21 , V_32 ) ;
}
if ( ! V_75 && V_8 -> V_87 == V_32 ) {
if ( ! ( V_78 & V_37 ) )
return;
F_15 ( V_2 , V_50 ,
V_51 , 0 ) ;
F_7 ( V_2 , V_48 ,
V_96 ) ;
F_15 ( V_2 , V_36 ,
V_37 , 0 ) ;
F_15 ( V_2 , V_92 ,
V_94 , 0 ) ;
V_8 -> V_87 = - 1 ;
F_10 ( V_2 -> V_18 , L_22 ) ;
}
}
int F_21 ( struct V_97 * V_98 ,
struct V_99 * V_100 , int V_101 )
{
struct V_1 * V_2 = V_98 -> V_2 ;
int V_35 ;
switch ( V_101 ) {
case V_102 :
case V_103 :
for ( V_35 = 0 ; V_35 < 3 ; V_35 ++ )
F_19 ( V_2 , V_35 , 1 ) ;
break;
case V_104 :
case V_105 :
for ( V_35 = 0 ; V_35 < 3 ; V_35 ++ )
F_19 ( V_2 , V_35 , 0 ) ;
break;
}
return 0 ;
}
static int F_22 ( struct V_7 * V_8 , int V_79 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < F_16 ( V_8 -> V_66 ) ; V_35 ++ ) {
if ( V_35 == V_79 )
continue;
if ( V_8 -> V_66 [ V_35 ] || V_8 -> V_69 [ V_35 ] ||
V_8 -> V_68 [ V_35 ] || V_8 -> V_67 [ V_35 ] )
return 1 ;
}
return 0 ;
}
static int F_23 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_33 * V_34 = V_8 -> V_34 ;
int V_108 = V_107 -> V_108 . integer . V_108 [ 0 ] ;
int V_78 ;
V_78 = F_14 ( V_2 , V_92 ) ;
if ( V_78 < 0 || V_78 & V_94 )
return - V_109 ;
if ( V_108 >= V_34 -> V_39 )
return - V_31 ;
V_8 -> V_43 = V_108 ;
return 0 ;
}
static int F_25 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . V_110 . V_111 [ 0 ] = V_8 -> V_43 ;
return 0 ;
}
static int F_26 ( struct V_99 * V_100 ,
struct V_112 * V_113 )
{
V_113 -> type = V_114 ;
V_113 -> V_115 = 1 ;
V_113 -> V_108 . integer . V_116 = 0 ;
V_113 -> V_108 . integer . V_117 = 1 ;
return 0 ;
}
static int F_27 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
int V_38 = V_100 -> V_118 ;
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . integer . V_108 [ 0 ] = V_8 -> V_66 [ V_38 ] ;
return 0 ;
}
static int F_28 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
int V_38 = V_100 -> V_118 ;
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_66 [ V_38 ] == V_107 -> V_108 . integer . V_108 [ 0 ] )
return 0 ;
if ( V_107 -> V_108 . integer . V_108 [ 0 ] > 1 )
return - V_31 ;
if ( F_22 ( V_8 , V_38 ) ) {
F_10 ( V_2 -> V_18 , L_23 , V_38 ) ;
return - V_109 ;
}
if ( V_8 -> V_86 [ V_38 ] )
return - V_109 ;
V_8 -> V_66 [ V_38 ] = V_107 -> V_108 . integer . V_108 [ 0 ] ;
F_19 ( V_2 , V_38 , V_8 -> V_66 [ V_38 ] ) ;
return 0 ;
}
static int F_29 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_33 * V_34 = V_8 -> V_34 ;
int V_108 = V_107 -> V_108 . integer . V_108 [ 0 ] ;
int V_78 ;
V_78 = F_14 ( V_2 , V_92 ) ;
if ( V_78 < 0 || V_78 & V_94 )
return - V_109 ;
if ( V_108 >= V_34 -> V_57 )
return - V_31 ;
V_8 -> V_60 = V_108 ;
return 0 ;
}
static int F_30 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . V_110 . V_111 [ 0 ] = V_8 -> V_60 ;
return 0 ;
}
static int F_31 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_33 * V_34 = V_8 -> V_34 ;
int V_108 = V_107 -> V_108 . integer . V_108 [ 0 ] ;
int V_78 ;
V_78 = F_14 ( V_2 , V_92 ) ;
if ( V_78 < 0 || V_78 & V_94 )
return - V_109 ;
if ( V_108 >= V_34 -> V_62 )
return - V_31 ;
V_8 -> V_65 = V_108 ;
return 0 ;
}
static int F_32 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . V_110 . V_111 [ 0 ] = V_8 -> V_65 ;
return 0 ;
}
static int F_33 ( struct V_99 * V_100 ,
struct V_112 * V_113 )
{
V_113 -> type = V_114 ;
V_113 -> V_115 = 1 ;
V_113 -> V_108 . integer . V_116 = 0 ;
V_113 -> V_108 . integer . V_117 = 1 ;
return 0 ;
}
static int F_34 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
int V_119 = V_100 -> V_118 ;
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . integer . V_108 [ 0 ] = V_8 -> V_69 [ V_119 ] ;
return 0 ;
}
static int F_35 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
int V_119 = V_100 -> V_118 ;
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_69 [ V_119 ] == V_107 -> V_108 . integer . V_108 [ 0 ] )
return 0 ;
if ( V_107 -> V_108 . integer . V_108 [ 0 ] > 1 )
return - V_31 ;
if ( ! V_8 -> V_55 )
return - V_120 ;
if ( F_22 ( V_8 , V_119 ) ) {
F_10 ( V_2 -> V_18 , L_23 , V_119 ) ;
return - V_109 ;
}
if ( V_8 -> V_86 [ V_119 ] )
return - V_109 ;
V_8 -> V_69 [ V_119 ] = V_107 -> V_108 . integer . V_108 [ 0 ] ;
F_19 ( V_2 , V_119 , V_8 -> V_69 [ V_119 ] ) ;
return 0 ;
}
static int F_36 ( struct V_99 * V_100 ,
struct V_112 * V_113 )
{
V_113 -> type = V_114 ;
V_113 -> V_115 = 1 ;
V_113 -> V_108 . integer . V_116 = 0 ;
V_113 -> V_108 . integer . V_117 = 1 ;
return 0 ;
}
static int F_37 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
int V_121 = V_100 -> V_118 ;
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_121 < 3 )
V_107 -> V_108 . integer . V_108 [ 0 ] = V_8 -> V_68 [ V_121 % 3 ] ;
else
V_107 -> V_108 . integer . V_108 [ 0 ] = V_8 -> V_67 [ V_121 % 3 ] ;
return 0 ;
}
static int F_38 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
int V_121 = V_100 -> V_118 ;
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_121 < 3 ) {
if ( V_8 -> V_68 [ V_121 % 3 ] ==
V_107 -> V_108 . integer . V_108 [ 0 ] )
return 0 ;
} else {
if ( V_8 -> V_67 [ V_121 % 3 ] ==
V_107 -> V_108 . integer . V_108 [ 0 ] )
return 0 ;
}
if ( V_107 -> V_108 . integer . V_108 [ 0 ] > 1 )
return - V_31 ;
if ( ! V_8 -> V_55 )
return - V_120 ;
if ( F_22 ( V_8 , V_121 % 3 ) ) {
F_10 ( V_2 -> V_18 , L_23 , V_121 ) ;
return - V_109 ;
}
if ( V_8 -> V_86 [ V_121 % 3 ] )
return - V_109 ;
if ( V_121 < 3 )
V_8 -> V_68 [ V_121 % 3 ] = V_107 -> V_108 . integer . V_108 [ 0 ] ;
else
V_8 -> V_67 [ V_121 % 3 ] = V_107 -> V_108 . integer . V_108 [ 0 ] ;
F_19 ( V_2 , V_121 % 3 , V_107 -> V_108 . integer . V_108 [ 0 ] ) ;
return 0 ;
}
static int F_39 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_33 * V_34 = V_8 -> V_34 ;
int V_108 = V_107 -> V_108 . integer . V_108 [ 0 ] ;
int V_78 ;
V_78 = F_14 ( V_2 , V_92 ) ;
if ( V_78 < 0 || V_78 & V_94 )
return - V_109 ;
if ( V_108 >= V_34 -> V_71 )
return - V_31 ;
V_8 -> V_74 = V_108 ;
return 0 ;
}
static int F_40 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . V_110 . V_111 [ 0 ] = V_8 -> V_74 ;
return 0 ;
}
static int F_41 ( struct V_99 * V_100 ,
struct V_112 * V_113 )
{
V_113 -> type = V_114 ;
V_113 -> V_115 = 1 ;
V_113 -> V_108 . integer . V_116 = 0 ;
V_113 -> V_108 . integer . V_117 = 1 ;
return 0 ;
}
static int F_42 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
int V_122 = V_100 -> V_118 ;
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
V_107 -> V_108 . integer . V_108 [ 0 ] = V_8 -> V_86 [ V_122 ] ;
return 0 ;
}
static int F_43 ( struct V_99 * V_100 ,
struct V_106 * V_107 )
{
int V_122 = V_100 -> V_118 ;
struct V_1 * V_2 = F_24 ( V_100 ) ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_8 -> V_86 [ V_122 ] == V_107 -> V_108 . integer . V_108 [ 0 ] )
return 0 ;
if ( V_107 -> V_108 . integer . V_108 [ 0 ] > 1 )
return - V_31 ;
if ( ! V_8 -> V_70 )
return - V_120 ;
if ( F_22 ( V_8 , V_122 ) ) {
F_10 ( V_2 -> V_18 , L_23 , V_122 ) ;
return - V_109 ;
}
if ( V_8 -> V_66 [ V_122 ] || V_8 -> V_69 [ V_122 ] ||
V_8 -> V_68 [ V_122 ] || V_8 -> V_67 [ V_122 ] )
return - V_109 ;
V_8 -> V_86 [ V_122 ] = V_107 -> V_108 . integer . V_108 [ 0 ] ;
F_19 ( V_2 , V_122 , V_107 -> V_108 . integer . V_108 [ 0 ] ) ;
return 0 ;
}
static void F_44 ( const struct V_4 * V_5 , void * V_123 )
{
struct V_1 * V_2 = V_123 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_5 && ( F_1 ( V_2 , L_19 , V_5 , true ) == 0 ) ) {
F_45 ( & V_2 -> V_124 ) ;
V_8 -> V_70 = V_5 ;
F_46 ( & V_2 -> V_124 ) ;
}
}
static void F_47 ( const struct V_4 * V_5 , void * V_123 )
{
struct V_1 * V_2 = V_123 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( V_5 && ( F_1 ( V_2 , L_18 , V_5 , true ) == 0 ) ) {
F_45 ( & V_2 -> V_124 ) ;
V_8 -> V_55 = V_5 ;
F_46 ( & V_2 -> V_124 ) ;
}
F_48 ( V_125 , V_126 ,
L_24 , V_2 -> V_18 , V_21 ,
V_2 , F_44 ) ;
}
static void F_49 ( const struct V_4 * V_5 , void * V_123 )
{
struct V_1 * V_2 = V_123 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( F_1 ( V_2 , L_17 , V_5 , true ) != 0 )
return;
F_45 ( & V_2 -> V_124 ) ;
V_8 -> V_38 = V_5 ;
F_46 ( & V_2 -> V_124 ) ;
F_48 ( V_125 , V_126 ,
L_25 , V_2 -> V_18 , V_21 ,
V_2 , F_47 ) ;
}
void F_50 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_33 * V_34 = V_8 -> V_34 ;
int V_15 , V_35 ;
V_8 -> V_87 = - 1 ;
F_51 ( V_2 , V_127 ,
F_16 ( V_127 ) ) ;
F_51 ( V_2 , V_128 ,
F_16 ( V_128 ) ) ;
F_51 ( V_2 , V_129 ,
F_16 ( V_129 ) ) ;
F_48 ( V_125 , V_126 ,
L_26 , V_2 -> V_18 , V_21 ,
V_2 , F_49 ) ;
if ( ! V_34 )
return;
if ( V_34 -> V_39 ) {
struct V_130 V_131 [] = {
F_52 ( L_27 , V_8 -> V_132 ,
F_25 , F_23 ) ,
} ;
V_8 -> V_133 = F_53 ( sizeof( char * )
* V_34 -> V_39 , V_21 ) ;
if ( ! V_8 -> V_133 ) {
F_3 ( V_8 -> V_2 -> V_18 ,
L_28 ,
V_34 -> V_39 ) ;
return;
}
for ( V_35 = 0 ; V_35 < V_34 -> V_39 ; V_35 ++ )
V_8 -> V_133 [ V_35 ] = V_34 -> V_42 [ V_35 ] . V_3 ;
V_8 -> V_132 . V_117 = V_34 -> V_39 ;
V_8 -> V_132 . V_134 = V_8 -> V_133 ;
V_15 = F_51 ( V_8 -> V_2 , V_131 , 1 ) ;
if ( V_15 != 0 )
F_3 ( V_8 -> V_2 -> V_18 ,
L_29 , V_15 ) ;
}
if ( V_34 -> V_57 ) {
struct V_130 V_131 [] = {
F_52 ( L_30 , V_8 -> V_135 ,
F_30 , F_29 ) ,
} ;
V_8 -> V_136 = F_53 ( sizeof( char * )
* V_34 -> V_57 , V_21 ) ;
if ( ! V_8 -> V_136 ) {
F_3 ( V_8 -> V_2 -> V_18 ,
L_31 ,
V_34 -> V_57 ) ;
return;
}
for ( V_35 = 0 ; V_35 < V_34 -> V_57 ; V_35 ++ )
V_8 -> V_136 [ V_35 ] = V_34 -> V_59 [ V_35 ] . V_3 ;
V_8 -> V_135 . V_117 = V_34 -> V_57 ;
V_8 -> V_135 . V_134 = V_8 -> V_136 ;
V_15 = F_51 ( V_8 -> V_2 , V_131 , 1 ) ;
if ( V_15 != 0 )
F_3 ( V_8 -> V_2 -> V_18 ,
L_32 , V_15 ) ;
}
if ( V_34 -> V_62 ) {
struct V_130 V_131 [] = {
F_52 ( L_33 , V_8 -> V_137 ,
F_32 ,
F_31 ) ,
} ;
V_8 -> V_138 = F_53 ( sizeof( char * )
* V_34 -> V_62 , V_21 ) ;
if ( ! V_8 -> V_138 ) {
F_3 ( V_8 -> V_2 -> V_18 ,
L_34 ,
V_34 -> V_62 ) ;
return;
}
for ( V_35 = 0 ; V_35 < V_34 -> V_62 ; V_35 ++ )
V_8 -> V_138 [ V_35 ] = V_34 -> V_64 [ V_35 ] . V_3 ;
V_8 -> V_137 . V_117 = V_34 -> V_62 ;
V_8 -> V_137 . V_134 = V_8 -> V_138 ;
V_15 = F_51 ( V_8 -> V_2 , V_131 , 1 ) ;
if ( V_15 != 0 )
F_3 ( V_8 -> V_2 -> V_18 ,
L_35 ,
V_15 ) ;
}
if ( V_34 -> V_71 ) {
struct V_130 V_131 [] = {
F_52 ( L_36 , V_8 -> V_139 ,
F_40 ,
F_39 ) ,
} ;
V_8 -> V_140 = F_53 ( sizeof( char * )
* V_34 -> V_71 , V_21 ) ;
if ( ! V_8 -> V_140 ) {
F_3 ( V_8 -> V_2 -> V_18 ,
L_37 ,
V_34 -> V_71 ) ;
return;
}
for ( V_35 = 0 ; V_35 < V_34 -> V_71 ; V_35 ++ )
V_8 -> V_140 [ V_35 ] = V_34 -> V_73 [ V_35 ] . V_3 ;
V_8 -> V_139 . V_117 = V_34 -> V_71 ;
V_8 -> V_139 . V_134 = V_8 -> V_140 ;
V_15 = F_51 ( V_8 -> V_2 , V_131 , 1 ) ;
if ( V_15 != 0 )
F_3 ( V_8 -> V_2 -> V_18 ,
L_38 ,
V_15 ) ;
}
}
