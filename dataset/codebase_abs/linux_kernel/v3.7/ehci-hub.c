static void F_1 ( struct V_1 * V_2 )
{
T_1 T_2 * V_3 ;
T_1 V_4 ;
int V_5 ;
T_3 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
if ( ! V_2 -> V_9 )
return;
F_3 ( 20 ) ;
F_4 ( & V_2 -> V_10 ) ;
V_5 = F_5 ( V_2 -> V_11 ) ;
while ( V_5 -- ) {
if ( F_6 ( V_5 , & V_2 -> V_9 ) ) {
V_3 = & V_2 -> V_12 -> V_13 [ V_5 ] ;
V_4 = F_7 ( V_2 , V_3 ) & ~ V_14 ;
if ( V_4 & V_15 )
F_8 ( V_5 , & V_2 -> V_9 ) ;
else if ( F_6 ( V_5 , & V_2 -> V_16 ) )
F_9 ( V_2 , V_4 & ~ V_17 , V_3 ) ;
else {
F_10 ( & V_2 -> V_10 ) ;
F_11 ( V_8 , V_18 ,
V_19 , V_5 + 1 ,
NULL , 0 ) ;
F_4 ( & V_2 -> V_10 ) ;
}
}
}
F_10 ( & V_2 -> V_10 ) ;
if ( ! V_2 -> V_9 )
return;
F_3 ( 90 ) ;
F_4 ( & V_2 -> V_10 ) ;
V_5 = F_5 ( V_2 -> V_11 ) ;
while ( V_5 -- ) {
if ( F_6 ( V_5 , & V_2 -> V_9 ) ) {
F_10 ( & V_2 -> V_10 ) ;
F_11 ( V_8 , V_20 ,
0 , V_5 + 1 ,
( char * ) & V_6 , sizeof( V_6 ) ) ;
F_4 ( & V_2 -> V_10 ) ;
V_3 = & V_2 -> V_12 -> V_13 [ V_5 ] ;
V_4 = F_7 ( V_2 , V_3 ) & ~ V_14 ;
if ( V_4 & V_15 )
F_9 ( V_2 , V_4 | V_21 , V_3 ) ;
else {
F_12 ( V_2 , L_1 ,
V_5 + 1 , V_4 ) ;
F_9 ( V_2 , V_4 & ~ V_17 , V_3 ) ;
}
}
}
V_2 -> V_9 = 0 ;
F_10 ( & V_2 -> V_10 ) ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_22 = F_5 ( V_2 -> V_11 ) ;
if ( F_7 ( V_2 , & V_2 -> V_12 -> V_4 ) & V_23 )
return 1 ;
while ( V_22 -- )
if ( F_7 ( V_2 , & V_2 -> V_12 -> V_13 [ V_22 ] ) & V_21 )
return 1 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 ,
bool V_24 , bool V_25 )
{
int V_5 ;
T_1 V_26 ;
if ( ! F_2 ( V_2 ) -> V_27 . V_28 -> V_29 || V_25 )
return;
F_4 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_30 ) {
V_5 = F_5 ( V_2 -> V_11 ) ;
while ( V_5 -- ) {
T_1 T_2 * V_31 = & V_2 -> V_12 -> V_32 [ V_5 ] ;
V_26 = F_7 ( V_2 , V_31 ) ;
F_9 ( V_2 , V_26 & ~ V_33 , V_31 ) ;
}
F_10 ( & V_2 -> V_10 ) ;
F_3 ( 5 ) ;
F_4 ( & V_2 -> V_10 ) ;
}
V_5 = F_5 ( V_2 -> V_11 ) ;
while ( V_5 -- ) {
T_1 T_2 * V_3 = & V_2 -> V_12 -> V_13 [ V_5 ] ;
T_1 V_34 = F_7 ( V_2 , V_3 ) & ~ V_14 ;
T_1 V_35 = V_34 & ~ V_36 ;
if ( ! V_24 ) {
if ( V_34 & V_37 )
V_35 |= V_38 | V_39 ;
else
V_35 |= V_38 | V_40 ;
}
F_15 ( V_2 , L_2 ,
V_5 + 1 , V_34 , V_35 ) ;
F_9 ( V_2 , V_35 , V_3 ) ;
}
if ( V_2 -> V_30 ) {
V_5 = F_5 ( V_2 -> V_11 ) ;
while ( V_5 -- ) {
T_1 T_2 * V_31 = & V_2 -> V_12 -> V_32 [ V_5 ] ;
V_26 = F_7 ( V_2 , V_31 ) ;
F_9 ( V_2 , V_26 | V_33 , V_31 ) ;
}
}
if ( ! V_24 && F_13 ( V_2 ) )
F_16 ( F_2 ( V_2 ) ) ;
F_10 ( & V_2 -> V_10 ) ;
}
static int F_17 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_18 ( V_8 ) ;
int V_5 ;
int V_41 ;
int V_42 ;
F_12 ( V_2 , L_3 ) ;
if ( F_19 ( V_43 , V_2 -> V_44 ) )
F_3 ( 5 ) ;
F_20 ( V_2 ) ;
F_4 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_45 < V_46 )
goto V_47;
if ( V_8 -> V_27 . V_28 -> V_29 ) {
if ( V_2 -> V_48 ) {
F_10 ( & V_2 -> V_10 ) ;
F_12 ( V_2 , L_4 ) ;
return - V_49 ;
}
}
V_2 -> V_50 = 0 ;
V_2 -> V_9 = 0 ;
V_42 = 0 ;
V_5 = F_5 ( V_2 -> V_11 ) ;
while ( V_5 -- ) {
T_1 T_2 * V_3 = & V_2 -> V_12 -> V_13 [ V_5 ] ;
T_1 V_34 = F_7 ( V_2 , V_3 ) & ~ V_14 ;
T_1 V_35 = V_34 & ~ V_36 ;
if ( V_34 & V_15 )
F_21 ( V_5 , & V_2 -> V_9 ) ;
else if ( ( V_34 & V_17 ) && ! ( V_34 & V_51 ) ) {
V_35 |= V_51 ;
F_21 ( V_5 , & V_2 -> V_50 ) ;
}
if ( V_8 -> V_27 . V_28 -> V_29 ) {
if ( V_34 & V_37 )
V_35 |= V_38 | V_39 ;
else
V_35 |= V_38 | V_40 ;
}
if ( V_34 != V_35 ) {
F_15 ( V_2 , L_2 ,
V_5 + 1 , V_34 , V_35 ) ;
F_9 ( V_2 , V_35 , V_3 ) ;
V_42 = 1 ;
}
}
if ( V_42 && V_2 -> V_30 ) {
F_10 ( & V_2 -> V_10 ) ;
F_3 ( 5 ) ;
F_4 ( & V_2 -> V_10 ) ;
V_5 = F_5 ( V_2 -> V_11 ) ;
while ( V_5 -- ) {
T_1 T_2 * V_31 = & V_2 -> V_12 -> V_32 [ V_5 ] ;
T_1 V_52 ;
V_52 = F_7 ( V_2 , V_31 ) ;
F_9 ( V_2 , V_52 | V_33 , V_31 ) ;
V_52 = F_7 ( V_2 , V_31 ) ;
F_12 ( V_2 , L_5 ,
V_5 , ( V_52 & V_33 ) ?
L_6 : L_7 ) ;
}
}
F_10 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_50 )
F_22 ( 150 ) ;
F_23 ( V_2 ) ;
F_4 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_53 & F_24 ( V_54 ) )
F_25 ( V_2 ) ;
if ( V_2 -> V_45 != V_46 )
goto V_47;
V_2 -> V_45 = V_55 ;
F_26 ( V_2 ) ;
F_27 ( V_2 ) ;
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
V_41 = V_56 ;
if ( ! V_8 -> V_27 . V_28 -> V_29 )
V_41 &= ~ V_23 ;
F_9 ( V_2 , V_41 , & V_2 -> V_12 -> V_57 ) ;
F_7 ( V_2 , & V_2 -> V_12 -> V_57 ) ;
V_47:
V_2 -> V_44 = V_43 + F_30 ( 10 ) ;
V_2 -> V_53 = 0 ;
V_2 -> V_58 = V_59 ;
F_10 ( & V_2 -> V_10 ) ;
F_31 ( & V_2 -> V_60 ) ;
return 0 ;
}
static int F_32 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_18 ( V_8 ) ;
T_1 V_26 ;
T_1 V_61 ;
int V_22 ;
unsigned long V_62 = 0 ;
if ( F_19 ( V_43 , V_2 -> V_44 ) )
F_3 ( 5 ) ;
F_4 ( & V_2 -> V_10 ) ;
if ( ! F_33 ( V_8 ) || V_2 -> V_63 )
goto V_63;
if ( F_34 ( V_2 -> V_64 ) ) {
if ( ! F_35 ( V_8 ) )
V_2 -> V_64 = NULL ;
else
F_36 ( V_8 ) ;
}
V_61 = F_7 ( V_2 , & V_2 -> V_12 -> V_57 ) ;
F_12 ( V_2 , L_8 ,
V_61 ? L_9 : L_10 ) ;
F_9 ( V_2 , 0 , & V_2 -> V_12 -> V_57 ) ;
F_9 ( V_2 , 0 , & V_2 -> V_12 -> V_65 ) ;
F_9 ( V_2 , V_2 -> V_66 , & V_2 -> V_12 -> V_67 ) ;
F_9 ( V_2 , ( T_1 ) V_2 -> V_68 -> V_69 , & V_2 -> V_12 -> V_70 ) ;
V_2 -> V_71 |= V_72 ;
F_9 ( V_2 , V_2 -> V_71 , & V_2 -> V_12 -> V_71 ) ;
V_2 -> V_45 = V_46 ;
F_10 ( & V_2 -> V_10 ) ;
F_3 ( 8 ) ;
F_4 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_63 )
goto V_63;
if ( V_2 -> V_50 && V_2 -> V_30 ) {
V_22 = F_5 ( V_2 -> V_11 ) ;
while ( V_22 -- ) {
if ( F_6 ( V_22 , & V_2 -> V_50 ) ) {
T_1 T_2 * V_31 =
& V_2 -> V_12 -> V_32 [ V_22 ] ;
V_26 = F_7 ( V_2 , V_31 ) ;
F_9 ( V_2 , V_26 & ~ V_33 ,
V_31 ) ;
}
}
F_10 ( & V_2 -> V_10 ) ;
F_3 ( 5 ) ;
F_4 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_63 )
goto V_63;
}
V_22 = F_5 ( V_2 -> V_11 ) ;
while ( V_22 -- ) {
V_26 = F_7 ( V_2 , & V_2 -> V_12 -> V_13 [ V_22 ] ) ;
V_26 &= ~ ( V_14 | V_36 ) ;
if ( F_6 ( V_22 , & V_2 -> V_50 ) &&
( V_26 & V_51 ) ) {
V_26 |= V_73 ;
F_21 ( V_22 , & V_62 ) ;
}
F_9 ( V_2 , V_26 , & V_2 -> V_12 -> V_13 [ V_22 ] ) ;
}
if ( V_62 ) {
F_10 ( & V_2 -> V_10 ) ;
F_3 ( 20 ) ;
F_4 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_63 )
goto V_63;
}
V_22 = F_5 ( V_2 -> V_11 ) ;
while ( V_22 -- ) {
V_26 = F_7 ( V_2 , & V_2 -> V_12 -> V_13 [ V_22 ] ) ;
if ( F_6 ( V_22 , & V_62 ) ) {
V_26 &= ~ ( V_14 | V_73 ) ;
F_9 ( V_2 , V_26 , & V_2 -> V_12 -> V_13 [ V_22 ] ) ;
F_15 ( V_2 , L_11 , V_22 + 1 ) ;
}
}
V_2 -> V_44 = V_43 + F_30 ( 5 ) ;
F_10 ( & V_2 -> V_10 ) ;
F_1 ( V_2 ) ;
F_4 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_63 )
goto V_63;
F_9 ( V_2 , V_56 , & V_2 -> V_12 -> V_57 ) ;
( void ) F_7 ( V_2 , & V_2 -> V_12 -> V_57 ) ;
F_10 ( & V_2 -> V_10 ) ;
return 0 ;
V_63:
F_10 ( & V_2 -> V_10 ) ;
return - V_74 ;
}
static void F_37 ( struct V_1 * V_2 , int V_75 , int V_76 )
{
T_1 T_2 * V_77 ;
T_1 V_13 ;
int V_78 ;
V_77 = & V_2 -> V_12 -> V_13 [ V_75 ] ;
for ( V_78 = 4 ; V_78 > 0 ; -- V_78 ) {
F_4 ( & V_2 -> V_10 ) ;
V_13 = F_7 ( V_2 , V_77 ) ;
if ( ( V_13 & V_15 ) == V_76
|| ( V_13 & ( V_15 | V_37 ) )
== 0 )
V_78 = 0 ;
else {
V_13 ^= V_15 ;
V_13 &= ~ ( V_17 | V_14 ) ;
F_9 ( V_2 , V_13 , V_77 ) ;
}
F_10 ( & V_2 -> V_10 ) ;
if ( V_78 > 1 )
F_3 ( 5 ) ;
}
}
static int F_38 (
struct V_1 * V_2 ,
int V_79 ,
T_1 T_2 * V_77 ,
int V_13
) {
if ( ! ( V_13 & V_37 ) )
return V_13 ;
if ( ! ( V_13 & V_17 ) ) {
if ( F_39 ( V_2 ) ) {
F_12 ( V_2 ,
L_12 ,
V_79 + 1 ) ;
return V_13 ;
}
F_12 ( V_2 , L_13 ,
V_79 + 1 ) ;
V_13 |= V_15 ;
V_13 &= ~ V_14 ;
F_9 ( V_2 , V_13 , V_77 ) ;
if ( V_2 -> V_80 )
F_40 ( V_2 , 1 ) ;
} else {
F_12 ( V_2 , L_14 ,
V_79 + 1 ) ;
if ( V_2 -> V_80 )
F_40 ( V_2 , 0 ) ;
}
return V_13 ;
}
static int
F_41 ( struct V_7 * V_8 , char * V_6 )
{
struct V_1 * V_2 = F_18 ( V_8 ) ;
T_1 V_26 , V_4 ;
T_1 V_41 ;
int V_81 , V_22 , V_82 = 1 ;
unsigned long V_83 ;
T_1 V_84 = 0 ;
V_6 [ 0 ] = 0 ;
V_81 = F_5 ( V_2 -> V_11 ) ;
if ( V_81 > 7 ) {
V_6 [ 1 ] = 0 ;
V_82 ++ ;
}
V_4 = V_2 -> V_48 ;
if ( ! V_85 )
V_41 = V_21 | V_86 | V_87 ;
else
V_41 = V_21 | V_86 ;
F_42 ( & V_2 -> V_10 , V_83 ) ;
if ( V_2 -> V_88 )
V_84 = F_7 ( V_2 , & V_2 -> V_12 -> V_4 ) >> 16 ;
for ( V_22 = 0 ; V_22 < V_81 ; V_22 ++ ) {
if ( V_2 -> V_88 && ! ( V_84 & ( 1 << V_22 ) ) )
continue;
V_26 = F_7 ( V_2 , & V_2 -> V_12 -> V_13 [ V_22 ] ) ;
if ( ( V_26 & V_41 ) != 0 || F_6 ( V_22 , & V_2 -> V_89 )
|| ( V_2 -> V_90 [ V_22 ] && F_43 (
V_43 , V_2 -> V_90 [ V_22 ] ) ) ) {
if ( V_22 < 7 )
V_6 [ 0 ] |= 1 << ( V_22 + 1 ) ;
else
V_6 [ 1 ] |= 1 << ( V_22 - 7 ) ;
V_4 = V_23 ;
}
}
F_44 ( & V_2 -> V_10 , V_83 ) ;
return V_4 ? V_82 : 0 ;
}
static void
F_45 (
struct V_1 * V_2 ,
struct V_91 * V_92
) {
int V_81 = F_5 ( V_2 -> V_11 ) ;
T_4 V_26 ;
V_92 -> V_93 = 0x29 ;
V_92 -> V_94 = 10 ;
V_92 -> V_95 = 0 ;
V_92 -> V_96 = V_81 ;
V_26 = 1 + ( V_81 / 8 ) ;
V_92 -> V_97 = 7 + 2 * V_26 ;
memset ( & V_92 -> V_98 . V_99 . V_100 [ 0 ] , 0 , V_26 ) ;
memset ( & V_92 -> V_98 . V_99 . V_100 [ V_26 ] , 0xff , V_26 ) ;
V_26 = 0x0008 ;
if ( F_46 ( V_2 -> V_11 ) )
V_26 |= 0x0001 ;
else
V_26 |= 0x0002 ;
#if 0
if (HCS_INDICATOR (ehci->hcs_params))
temp |= 0x0080;
#endif
V_92 -> V_101 = F_47 ( V_26 ) ;
}
static int F_11 (
struct V_7 * V_8 ,
T_4 V_102 ,
T_4 V_103 ,
T_4 V_104 ,
char * V_6 ,
T_4 V_105
) {
struct V_1 * V_2 = F_18 ( V_8 ) ;
int V_81 = F_5 ( V_2 -> V_11 ) ;
T_1 T_2 * V_77 = & V_2 -> V_12 -> V_13 [
( V_104 & 0xff ) - 1 ] ;
T_1 T_2 * V_31 = & V_2 -> V_12 -> V_32 [ ( V_104 & 0xff ) - 1 ] ;
T_1 V_26 , V_106 , V_4 ;
unsigned long V_83 ;
int V_82 = 0 ;
unsigned V_107 ;
F_42 ( & V_2 -> V_10 , V_83 ) ;
switch ( V_102 ) {
case V_108 :
switch ( V_103 ) {
case V_109 :
case V_110 :
break;
default:
goto error;
}
break;
case V_111 :
if ( ! V_104 || V_104 > V_81 )
goto error;
V_104 -- ;
V_26 = F_7 ( V_2 , V_77 ) ;
V_26 &= ~ V_14 ;
switch ( V_103 ) {
case V_112 :
F_9 ( V_2 , V_26 & ~ V_17 , V_77 ) ;
break;
case V_113 :
F_9 ( V_2 , V_26 | V_86 , V_77 ) ;
break;
case V_114 :
if ( V_26 & V_115 )
goto error;
if ( V_2 -> V_116 )
break;
#ifdef F_48
if ( ( V_8 -> V_27 . V_117 == ( V_104 + 1 ) )
&& V_8 -> V_27 . V_118 ) {
F_49 ( V_8 -> V_119 -> V_120 ) ;
break;
}
#endif
if ( ! ( V_26 & V_51 ) )
break;
if ( ( V_26 & V_17 ) == 0 )
goto error;
if ( V_2 -> V_30 ) {
V_106 = F_7 ( V_2 , V_31 ) ;
F_9 ( V_2 , V_106 & ~ V_33 ,
V_31 ) ;
F_44 ( & V_2 -> V_10 , V_83 ) ;
F_3 ( 5 ) ;
F_42 ( & V_2 -> V_10 , V_83 ) ;
}
V_26 &= ~ V_36 ;
F_9 ( V_2 , V_26 | V_73 , V_77 ) ;
V_2 -> V_90 [ V_104 ] = V_43
+ F_30 ( 20 ) ;
break;
case V_121 :
F_8 ( V_104 , & V_2 -> V_89 ) ;
break;
case V_122 :
if ( F_46 ( V_2 -> V_11 ) )
F_9 ( V_2 , V_26 & ~ V_123 ,
V_77 ) ;
break;
case V_124 :
if ( V_2 -> V_125 ) {
V_26 &= ~ V_126 ;
V_26 &= ~ V_127 ;
}
F_9 ( V_2 , V_26 | V_21 , V_77 ) ;
break;
case V_128 :
F_9 ( V_2 , V_26 | V_87 , V_77 ) ;
break;
case V_129 :
break;
default:
goto error;
}
F_7 ( V_2 , & V_2 -> V_12 -> V_71 ) ;
break;
case V_130 :
F_45 ( V_2 , (struct V_91 * )
V_6 ) ;
break;
case V_131 :
memset ( V_6 , 0 , 4 ) ;
break;
case V_20 :
if ( ! V_104 || V_104 > V_81 )
goto error;
V_104 -- ;
V_4 = 0 ;
V_26 = F_7 ( V_2 , V_77 ) ;
if ( V_26 & V_21 )
V_4 |= V_132 << 16 ;
if ( V_26 & V_86 )
V_4 |= V_133 << 16 ;
if ( ( V_26 & V_87 ) && ! V_85 ) {
V_4 |= V_134 << 16 ;
if ( ( V_26 & V_135 ) && F_46 ( V_2 -> V_11 ) ) {
F_9 ( V_2 ,
V_26 & ~ ( V_14 | V_123 ) ,
V_77 ) ;
V_26 = F_7 ( V_2 , V_77 ) ;
}
}
if ( V_26 & V_73 ) {
if ( ! V_2 -> V_90 [ V_104 ] ) {
V_2 -> V_90 [ V_104 ] = V_43
+ F_30 ( 20 ) ;
F_50 ( & F_2 ( V_2 ) -> V_136 ,
V_2 -> V_90 [ V_104 ] ) ;
}
else if ( F_43 ( V_43 ,
V_2 -> V_90 [ V_104 ] ) ) {
F_8 ( V_104 , & V_2 -> V_137 ) ;
F_21 ( V_104 , & V_2 -> V_89 ) ;
V_2 -> V_90 [ V_104 ] = 0 ;
V_26 = F_7 ( V_2 , V_77 ) ;
F_9 ( V_2 ,
V_26 & ~ ( V_14 | V_73 ) ,
V_77 ) ;
F_8 ( V_104 , & V_2 -> V_48 ) ;
V_82 = F_51 ( V_2 , V_77 ,
V_73 , 0 , 2000 ) ;
if ( V_82 != 0 ) {
F_52 ( V_2 ,
L_15 ,
V_104 + 1 , V_82 ) ;
goto error;
}
V_26 &= ~ ( V_51 | V_73 | ( 3 << 10 ) ) ;
}
}
if ( ( V_26 & V_115 )
&& F_43 ( V_43 ,
V_2 -> V_90 [ V_104 ] ) ) {
V_4 |= V_138 << 16 ;
V_2 -> V_90 [ V_104 ] = 0 ;
F_8 ( V_104 , & V_2 -> V_48 ) ;
F_9 ( V_2 , V_26 & ~ ( V_14 | V_115 ) ,
V_77 ) ;
V_82 = F_51 ( V_2 , V_77 ,
V_115 , 0 , 1000 ) ;
if ( V_82 != 0 ) {
F_52 ( V_2 , L_16 ,
V_104 + 1 , V_82 ) ;
goto error;
}
V_26 = F_38 ( V_2 , V_104 , V_77 ,
F_7 ( V_2 , V_77 ) ) ;
}
if ( ! ( V_26 & ( V_73 | V_115 ) ) ) {
V_2 -> V_90 [ V_104 ] = 0 ;
F_8 ( V_104 , & V_2 -> V_48 ) ;
}
if ( ( V_26 & V_37 ) &&
F_6 ( V_104 , & V_2 -> V_16 ) ) {
V_26 &= ~ V_14 ;
V_26 |= V_15 ;
F_9 ( V_2 , V_26 , V_77 ) ;
F_12 ( V_2 , L_17 , V_104 + 1 ) ;
V_26 = F_7 ( V_2 , V_77 ) ;
}
if ( V_26 & V_37 ) {
V_4 |= V_139 ;
if ( V_2 -> V_30 ) {
V_106 = F_7 ( V_2 , V_31 ) ;
V_4 |= F_53 ( V_2 , V_106 ) ;
} else
V_4 |= F_53 ( V_2 , V_26 ) ;
}
if ( V_26 & V_17 )
V_4 |= V_140 ;
if ( V_26 & ( V_51 | V_73 ) ) {
V_4 |= V_141 ;
} else if ( F_6 ( V_104 , & V_2 -> V_137 ) ) {
F_8 ( V_104 , & V_2 -> V_137 ) ;
F_8 ( V_104 , & V_2 -> V_48 ) ;
V_2 -> V_90 [ V_104 ] = 0 ;
if ( V_26 & V_17 )
F_21 ( V_104 , & V_2 -> V_89 ) ;
}
if ( V_26 & V_135 )
V_4 |= V_142 ;
if ( V_26 & V_115 )
V_4 |= V_143 ;
if ( V_26 & V_123 )
V_4 |= V_144 ;
if ( F_6 ( V_104 , & V_2 -> V_89 ) )
V_4 |= V_145 << 16 ;
#ifndef F_54
if ( V_4 & ~ 0xffff )
#endif
F_55 ( V_2 , L_18 , V_104 + 1 , V_26 ) ;
F_56 ( V_4 , V_6 ) ;
break;
case V_146 :
switch ( V_103 ) {
case V_109 :
case V_110 :
break;
default:
goto error;
}
break;
case V_18 :
V_107 = V_104 >> 8 ;
V_104 &= 0xff ;
if ( F_34 ( V_2 -> V_64 ) ) {
if ( V_104 == F_57 ( V_2 -> V_11 ) &&
( F_58 ( & V_2 -> V_64 -> V_147 ) & V_148 ) ) {
V_82 = - V_149 ;
goto V_150;
}
}
if ( ! V_104 || V_104 > V_81 )
goto error;
V_104 -- ;
V_26 = F_7 ( V_2 , V_77 ) ;
if ( V_26 & V_15 )
break;
V_26 &= ~ V_14 ;
switch ( V_103 ) {
case V_114 :
if ( V_2 -> V_116 )
break;
if ( ( V_26 & V_17 ) == 0
|| ( V_26 & V_115 ) != 0 )
goto error;
V_26 &= ~ V_40 ;
V_26 |= V_39 | V_38 ;
F_9 ( V_2 , V_26 | V_51 , V_77 ) ;
if ( V_2 -> V_30 ) {
F_44 ( & V_2 -> V_10 , V_83 ) ;
F_3 ( 5 ) ;
F_42 ( & V_2 -> V_10 , V_83 ) ;
V_106 = F_7 ( V_2 , V_31 ) ;
F_9 ( V_2 , V_106 | V_33 ,
V_31 ) ;
V_106 = F_7 ( V_2 , V_31 ) ;
F_12 ( V_2 , L_19 ,
V_104 , ( V_106 & V_33 ) ?
L_6 : L_7 ) ;
}
F_21 ( V_104 , & V_2 -> V_137 ) ;
break;
case V_122 :
if ( F_46 ( V_2 -> V_11 ) )
F_9 ( V_2 , V_26 | V_123 ,
V_77 ) ;
break;
case V_19 :
if ( V_26 & V_73 )
goto error;
if ( ( V_26 & ( V_17 | V_37 ) ) == V_37
&& ! F_39 ( V_2 )
&& F_59 ( V_26 ) ) {
F_12 ( V_2 ,
L_20 ,
V_104 + 1 ) ;
V_26 |= V_15 ;
} else {
F_15 ( V_2 , L_21 , V_104 + 1 ) ;
V_26 |= V_115 ;
V_26 &= ~ V_17 ;
V_2 -> V_90 [ V_104 ] = V_43
+ F_30 ( 50 ) ;
}
F_9 ( V_2 , V_26 , V_77 ) ;
break;
case V_151 :
if ( ! V_107 || V_107 > 5 )
goto error;
F_44 ( & V_2 -> V_10 , V_83 ) ;
F_20 ( V_2 ) ;
F_42 ( & V_2 -> V_10 , V_83 ) ;
while ( V_81 -- ) {
T_1 T_2 * V_152 =
& V_2 -> V_12 -> V_13 [ V_81 ] ;
V_26 = F_7 ( V_2 , V_152 ) & ~ V_14 ;
if ( V_26 & V_17 )
F_9 ( V_2 , V_26 | V_51 ,
V_152 ) ;
}
F_44 ( & V_2 -> V_10 , V_83 ) ;
F_23 ( V_2 ) ;
F_42 ( & V_2 -> V_10 , V_83 ) ;
V_26 = F_7 ( V_2 , V_77 ) ;
V_26 |= V_107 << 16 ;
F_9 ( V_2 , V_26 , V_77 ) ;
break;
default:
goto error;
}
F_7 ( V_2 , & V_2 -> V_12 -> V_71 ) ;
break;
default:
error:
V_82 = - V_153 ;
}
V_150:
F_44 ( & V_2 -> V_10 , V_83 ) ;
return V_82 ;
}
static void T_5 F_60 ( struct V_7 * V_8 ,
int V_75 )
{
struct V_1 * V_2 = F_18 ( V_8 ) ;
if ( F_39 ( V_2 ) )
return;
F_37 ( V_2 , -- V_75 , V_15 ) ;
}
static int T_5 F_61 ( struct V_7 * V_8 ,
int V_75 )
{
struct V_1 * V_2 = F_18 ( V_8 ) ;
T_1 T_2 * V_3 ;
if ( F_39 ( V_2 ) )
return 0 ;
V_3 = & V_2 -> V_12 -> V_13 [ V_75 - 1 ] ;
return F_7 ( V_2 , V_3 ) & V_15 ;
}
