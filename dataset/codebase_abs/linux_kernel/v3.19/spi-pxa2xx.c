static bool F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 == V_4 ;
}
static bool F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 == V_5 ;
}
static T_1 F_3 ( const struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_5 :
return V_6 ;
default:
return V_7 ;
}
}
static T_1
F_4 ( const struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case V_5 :
return V_8 ;
default:
return V_9 ;
}
}
static bool F_5 ( const struct V_1 * V_2 )
{
void T_2 * V_10 = V_2 -> V_11 ;
T_1 V_12 ;
switch ( V_2 -> V_3 ) {
case V_5 :
V_12 = V_13 ;
break;
default:
V_12 = V_14 ;
break;
}
return ( F_6 ( V_10 ) & V_12 ) == V_12 ;
}
static void F_7 ( const struct V_1 * V_2 ,
T_1 * V_15 )
{
T_1 V_12 ;
switch ( V_2 -> V_3 ) {
case V_5 :
V_12 = V_16 ;
break;
default:
V_12 = V_17 ;
break;
}
* V_15 &= ~ V_12 ;
}
static void F_8 ( const struct V_1 * V_2 ,
T_1 * V_15 , T_1 V_18 )
{
switch ( V_2 -> V_3 ) {
case V_5 :
* V_15 |= F_9 ( V_18 ) ;
break;
default:
* V_15 |= F_10 ( V_18 ) ;
break;
}
}
static T_1 F_11 ( const struct V_1 * V_2 ,
T_1 V_19 , T_3 V_20 )
{
switch ( V_2 -> V_3 ) {
case V_5 :
return V_19
| V_21
| F_12 ( V_20 > 32 ? 8 : V_20 )
| V_22 ;
default:
return V_19
| V_23
| F_13 ( V_20 > 16 ? V_20 - 16 : V_20 )
| V_22
| ( V_20 > 16 ? V_24 : 0 ) ;
}
}
static T_1 F_14 ( struct V_1 * V_2 , unsigned V_25 )
{
F_15 ( ! V_2 -> V_26 ) ;
return F_16 ( V_2 -> V_26 + V_25 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned V_25 , T_1 V_27 )
{
F_15 ( ! V_2 -> V_26 ) ;
F_18 ( V_27 , V_2 -> V_26 + V_25 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
unsigned V_25 = 0x400 ;
T_1 V_27 , V_28 ;
if ( ! F_1 ( V_2 ) )
return;
V_28 = F_16 ( V_2 -> V_11 + V_25 + V_29 ) ;
V_27 = V_28 | V_30 ;
F_18 ( V_27 , V_2 -> V_11 + V_25 + V_29 ) ;
V_27 = F_16 ( V_2 -> V_11 + V_25 + V_29 ) ;
if ( V_27 != ( V_28 | V_30 ) ) {
V_25 = 0x800 ;
goto V_31;
}
V_28 = F_16 ( V_2 -> V_11 + V_25 + V_29 ) ;
V_27 = V_28 & ~ V_30 ;
F_18 ( V_27 , V_2 -> V_11 + V_25 + V_29 ) ;
V_27 = F_16 ( V_2 -> V_11 + V_25 + V_29 ) ;
if ( V_27 != ( V_28 & ~ V_30 ) ) {
V_25 = 0x800 ;
goto V_31;
}
V_31:
V_2 -> V_26 = V_2 -> V_11 + V_25 ;
V_27 = V_30 | V_32 ;
F_17 ( V_2 , V_29 , V_27 ) ;
if ( V_2 -> V_33 -> V_34 ) {
F_17 ( V_2 , V_35 , 1 ) ;
V_27 = F_14 ( V_2 , V_36 ) ;
V_27 |= V_37 ;
F_17 ( V_2 , V_36 , V_27 ) ;
}
}
static void F_20 ( struct V_1 * V_2 , bool V_38 )
{
T_1 V_27 ;
if ( ! F_1 ( V_2 ) )
return;
V_27 = F_14 ( V_2 , V_29 ) ;
if ( V_38 )
V_27 &= ~ V_32 ;
else
V_27 |= V_32 ;
F_17 ( V_2 , V_29 , V_27 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_41 ;
if ( V_2 -> V_3 == V_42 ) {
F_22 ( V_2 -> V_41 -> V_43 , V_2 -> V_11 ) ;
return;
}
if ( V_40 -> V_44 ) {
V_40 -> V_44 ( V_45 ) ;
return;
}
if ( F_23 ( V_40 -> V_46 ) ) {
F_24 ( V_40 -> V_46 , V_40 -> V_47 ) ;
return;
}
F_20 ( V_2 , true ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_39 * V_40 = V_2 -> V_41 ;
if ( V_2 -> V_3 == V_42 )
return;
if ( V_40 -> V_44 ) {
V_40 -> V_44 ( V_48 ) ;
return;
}
if ( F_23 ( V_40 -> V_46 ) ) {
F_24 ( V_40 -> V_46 , ! V_40 -> V_47 ) ;
return;
}
F_20 ( V_2 , false ) ;
}
int F_26 ( struct V_1 * V_2 )
{
unsigned long V_49 = V_50 << 1 ;
void T_2 * V_10 = V_2 -> V_11 ;
do {
while ( F_6 ( V_10 ) & V_51 ) {
F_27 ( V_10 ) ;
}
} while ( ( F_6 ( V_10 ) & V_52 ) && -- V_49 );
F_28 ( V_2 , V_53 ) ;
return V_49 ;
}
static int F_29 ( struct V_1 * V_2 )
{
void T_2 * V_10 = V_2 -> V_11 ;
T_3 V_54 = V_2 -> V_54 ;
if ( F_5 ( V_2 )
|| ( V_2 -> V_55 == V_2 -> V_56 ) )
return 0 ;
F_30 ( 0 , V_10 ) ;
V_2 -> V_55 += V_54 ;
return 1 ;
}
static int F_31 ( struct V_1 * V_2 )
{
void T_2 * V_10 = V_2 -> V_11 ;
T_3 V_54 = V_2 -> V_54 ;
while ( ( F_6 ( V_10 ) & V_51 )
&& ( V_2 -> V_57 < V_2 -> V_58 ) ) {
F_27 ( V_10 ) ;
V_2 -> V_57 += V_54 ;
}
return V_2 -> V_57 == V_2 -> V_58 ;
}
static int F_32 ( struct V_1 * V_2 )
{
void T_2 * V_10 = V_2 -> V_11 ;
if ( F_5 ( V_2 )
|| ( V_2 -> V_55 == V_2 -> V_56 ) )
return 0 ;
F_30 ( * ( T_3 * ) ( V_2 -> V_55 ) , V_10 ) ;
++ V_2 -> V_55 ;
return 1 ;
}
static int F_33 ( struct V_1 * V_2 )
{
void T_2 * V_10 = V_2 -> V_11 ;
while ( ( F_6 ( V_10 ) & V_51 )
&& ( V_2 -> V_57 < V_2 -> V_58 ) ) {
* ( T_3 * ) ( V_2 -> V_57 ) = F_27 ( V_10 ) ;
++ V_2 -> V_57 ;
}
return V_2 -> V_57 == V_2 -> V_58 ;
}
static int F_34 ( struct V_1 * V_2 )
{
void T_2 * V_10 = V_2 -> V_11 ;
if ( F_5 ( V_2 )
|| ( V_2 -> V_55 == V_2 -> V_56 ) )
return 0 ;
F_30 ( * ( V_59 * ) ( V_2 -> V_55 ) , V_10 ) ;
V_2 -> V_55 += 2 ;
return 1 ;
}
static int F_35 ( struct V_1 * V_2 )
{
void T_2 * V_10 = V_2 -> V_11 ;
while ( ( F_6 ( V_10 ) & V_51 )
&& ( V_2 -> V_57 < V_2 -> V_58 ) ) {
* ( V_59 * ) ( V_2 -> V_57 ) = F_27 ( V_10 ) ;
V_2 -> V_57 += 2 ;
}
return V_2 -> V_57 == V_2 -> V_58 ;
}
static int F_36 ( struct V_1 * V_2 )
{
void T_2 * V_10 = V_2 -> V_11 ;
if ( F_5 ( V_2 )
|| ( V_2 -> V_55 == V_2 -> V_56 ) )
return 0 ;
F_30 ( * ( T_1 * ) ( V_2 -> V_55 ) , V_10 ) ;
V_2 -> V_55 += 4 ;
return 1 ;
}
static int F_37 ( struct V_1 * V_2 )
{
void T_2 * V_10 = V_2 -> V_11 ;
while ( ( F_6 ( V_10 ) & V_51 )
&& ( V_2 -> V_57 < V_2 -> V_58 ) ) {
* ( T_1 * ) ( V_2 -> V_57 ) = F_27 ( V_10 ) ;
V_2 -> V_57 += 4 ;
}
return V_2 -> V_57 == V_2 -> V_58 ;
}
void * F_38 ( struct V_1 * V_2 )
{
struct V_60 * V_61 = V_2 -> V_62 ;
struct V_63 * V_64 = V_2 -> V_65 ;
if ( V_64 -> V_66 . V_67 != & V_61 -> V_68 ) {
V_2 -> V_65 =
F_39 ( V_64 -> V_66 . V_67 ,
struct V_63 ,
V_66 ) ;
return V_69 ;
} else
return V_70 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_63 * V_71 ;
struct V_60 * V_61 ;
V_61 = V_2 -> V_62 ;
V_2 -> V_62 = NULL ;
V_2 -> V_65 = NULL ;
V_71 = F_41 ( & V_61 -> V_68 , struct V_63 ,
V_66 ) ;
if ( V_71 -> V_72 )
F_42 ( V_71 -> V_72 ) ;
if ( ! V_71 -> V_73 )
F_25 ( V_2 ) ;
else {
struct V_60 * V_74 ;
V_74 = F_43 ( V_2 -> V_75 ) ;
if ( V_74 && V_74 -> V_76 != V_61 -> V_76 )
V_74 = NULL ;
if ( ! V_74 || V_61 -> V_77 == V_78 )
F_25 ( V_2 ) ;
}
V_2 -> V_41 = NULL ;
F_44 ( V_2 -> V_75 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
void T_2 * V_10 = V_2 -> V_11 ;
struct V_39 * V_40 = V_2 -> V_41 ;
T_1 V_15 ;
V_15 = F_46 ( V_10 ) & ~ V_2 -> V_79 ;
V_15 &= ~ V_17 ;
V_15 |= V_40 -> V_18 ;
F_47 ( V_15 , V_10 ) ;
}
static void F_48 ( struct V_1 * V_2 , const char * V_61 )
{
void T_2 * V_10 = V_2 -> V_11 ;
F_28 ( V_2 , V_2 -> V_80 ) ;
F_45 ( V_2 ) ;
if ( ! F_49 ( V_2 ) )
F_50 ( 0 , V_10 ) ;
F_26 ( V_2 ) ;
F_51 ( F_52 ( V_10 ) & ~ V_22 , V_10 ) ;
F_53 ( & V_2 -> V_81 -> V_82 , L_1 , V_61 ) ;
V_2 -> V_62 -> V_77 = V_78 ;
F_54 ( & V_2 -> V_83 ) ;
}
static void F_55 ( struct V_1 * V_2 )
{
void T_2 * V_10 = V_2 -> V_11 ;
F_28 ( V_2 , V_2 -> V_80 ) ;
F_45 ( V_2 ) ;
if ( ! F_49 ( V_2 ) )
F_50 ( 0 , V_10 ) ;
V_2 -> V_62 -> V_84 += V_2 -> V_85 -
( V_2 -> V_58 - V_2 -> V_57 ) ;
V_2 -> V_62 -> V_77 = F_38 ( V_2 ) ;
F_54 ( & V_2 -> V_83 ) ;
}
static T_4 F_56 ( struct V_1 * V_2 )
{
void T_2 * V_10 = V_2 -> V_11 ;
T_1 V_86 = ( F_46 ( V_10 ) & V_87 ) ?
V_2 -> V_88 : V_2 -> V_88 & ~ V_89 ;
T_1 V_90 = F_6 ( V_10 ) & V_86 ;
if ( V_90 & V_53 ) {
F_48 ( V_2 , L_2 ) ;
return V_91 ;
}
if ( V_90 & V_92 ) {
F_22 ( V_92 , V_10 ) ;
if ( V_2 -> V_93 ( V_2 ) ) {
F_55 ( V_2 ) ;
return V_91 ;
}
}
do {
if ( V_2 -> V_93 ( V_2 ) ) {
F_55 ( V_2 ) ;
return V_91 ;
}
} while ( V_2 -> V_94 ( V_2 ) );
if ( V_2 -> V_93 ( V_2 ) ) {
F_55 ( V_2 ) ;
return V_91 ;
}
if ( V_2 -> V_55 == V_2 -> V_56 ) {
T_1 V_95 ;
T_1 V_15 ;
V_15 = F_46 ( V_10 ) ;
V_15 &= ~ V_87 ;
if ( F_49 ( V_2 ) ) {
T_1 V_96 ;
F_7 ( V_2 , & V_15 ) ;
V_95 = V_2 -> V_58 - V_2 -> V_57 ;
switch ( V_2 -> V_54 ) {
case 4 :
V_95 >>= 1 ;
case 2 :
V_95 >>= 1 ;
}
V_96 = F_4 ( V_2 ) ;
if ( V_96 > V_95 )
V_96 = V_95 ;
F_8 ( V_2 , & V_15 , V_96 ) ;
}
F_47 ( V_15 , V_10 ) ;
}
return V_91 ;
}
static T_4 F_57 ( int V_97 , void * V_98 )
{
struct V_1 * V_2 = V_98 ;
void T_2 * V_10 = V_2 -> V_11 ;
T_1 V_15 ;
T_1 V_12 = V_2 -> V_88 ;
T_1 V_99 ;
if ( F_58 ( & V_2 -> V_81 -> V_82 ) )
return V_100 ;
V_99 = F_6 ( V_10 ) ;
if ( V_99 == ~ 0 )
return V_100 ;
V_15 = F_46 ( V_10 ) ;
if ( ! ( V_15 & V_87 ) )
V_12 &= ~ V_89 ;
if ( ! ( V_99 & V_12 ) )
return V_100 ;
if ( ! V_2 -> V_62 ) {
F_51 ( F_52 ( V_10 ) & ~ V_22 , V_10 ) ;
F_47 ( F_46 ( V_10 ) & ~ V_2 -> V_79 , V_10 ) ;
if ( ! F_49 ( V_2 ) )
F_50 ( 0 , V_10 ) ;
F_28 ( V_2 , V_2 -> V_80 ) ;
F_53 ( & V_2 -> V_81 -> V_82 ,
L_3 ) ;
return V_91 ;
}
return V_2 -> V_101 ( V_2 ) ;
}
static T_1 F_59 ( T_1 V_102 , T_1 * V_103 , T_1 * V_19 )
{
unsigned int V_104 ;
for ( V_104 = 0 ; V_104 < F_60 ( V_105 ) ; V_104 ++ ) {
if ( V_102 >= V_105 [ V_104 ] . V_106 ) {
* V_103 = V_105 [ V_104 ] . V_107 ;
* V_19 = V_105 [ V_104 ] . V_19 ;
return V_105 [ V_104 ] . V_106 ;
}
}
* V_103 = V_105 [ V_104 - 1 ] . V_107 ;
* V_19 = V_105 [ V_104 - 1 ] . V_19 ;
return V_105 [ V_104 - 1 ] . V_106 ;
}
static unsigned int F_61 ( struct V_1 * V_2 , int V_102 )
{
unsigned long V_108 = V_2 -> V_109 ;
const struct V_110 * V_111 = V_2 -> V_111 ;
V_102 = F_62 ( int , V_108 , V_102 ) ;
if ( V_111 -> type == V_112 || V_111 -> type == V_42 )
return ( ( V_108 / ( 2 * V_102 ) - 1 ) & 0xff ) << 8 ;
else
return ( ( V_108 / V_102 - 1 ) & 0xfff ) << 8 ;
}
static unsigned int F_63 ( struct V_1 * V_2 ,
struct V_39 * V_40 , int V_102 )
{
T_1 V_19 ;
switch ( V_2 -> V_3 ) {
case V_5 :
F_59 ( V_102 , & V_40 -> V_113 , & V_19 ) ;
return V_19 << 8 ;
default:
return F_61 ( V_2 , V_102 ) ;
}
}
static void V_83 ( unsigned long V_114 )
{
struct V_1 * V_2 = (struct V_1 * ) V_114 ;
struct V_60 * V_115 = NULL ;
struct V_63 * V_116 = NULL ;
struct V_63 * V_117 = NULL ;
struct V_39 * V_40 = NULL ;
void T_2 * V_10 = V_2 -> V_11 ;
T_1 V_19 = 0 ;
T_3 V_20 = 0 ;
T_1 V_118 = 0 ;
T_1 V_119 ;
T_1 V_120 ;
T_1 V_121 = V_2 -> V_41 -> V_122 ;
T_1 V_123 = V_2 -> V_41 -> V_124 ;
T_1 V_125 = F_3 ( V_2 ) ;
V_115 = V_2 -> V_62 ;
V_116 = V_2 -> V_65 ;
V_40 = V_2 -> V_41 ;
if ( V_115 -> V_77 == V_78 ) {
V_115 -> V_99 = - V_126 ;
F_40 ( V_2 ) ;
return;
}
if ( V_115 -> V_77 == V_70 ) {
V_115 -> V_99 = 0 ;
F_40 ( V_2 ) ;
return;
}
if ( V_115 -> V_77 == V_69 ) {
V_117 = F_39 ( V_116 -> V_66 . V_127 ,
struct V_63 ,
V_66 ) ;
if ( V_117 -> V_72 )
F_42 ( V_117 -> V_72 ) ;
if ( V_117 -> V_73 )
F_25 ( V_2 ) ;
}
if ( ! F_64 ( V_116 -> V_85 ) && V_40 -> V_34 ) {
if ( V_115 -> V_128
|| V_116 -> V_129 || V_116 -> V_130 ) {
F_53 ( & V_2 -> V_81 -> V_82 ,
L_4
L_5 ,
V_116 -> V_85 , V_131 ) ;
V_115 -> V_99 = - V_132 ;
F_40 ( V_2 ) ;
return;
}
F_65 ( & V_115 -> V_76 -> V_82 ,
L_6
L_7 ,
( long ) V_2 -> V_85 , V_131 ) ;
}
if ( F_26 ( V_2 ) == 0 ) {
F_53 ( & V_2 -> V_81 -> V_82 , L_8 ) ;
V_115 -> V_99 = - V_126 ;
F_40 ( V_2 ) ;
return;
}
V_2 -> V_54 = V_40 -> V_54 ;
V_2 -> V_55 = ( void * ) V_116 -> V_133 ;
V_2 -> V_56 = V_2 -> V_55 + V_116 -> V_85 ;
V_2 -> V_57 = V_116 -> V_134 ;
V_2 -> V_58 = V_2 -> V_57 + V_116 -> V_85 ;
V_2 -> V_129 = V_116 -> V_129 ;
V_2 -> V_130 = V_116 -> V_130 ;
V_2 -> V_85 = V_116 -> V_85 ;
V_2 -> V_94 = V_2 -> V_55 ? V_40 -> V_94 : F_29 ;
V_2 -> V_93 = V_2 -> V_57 ? V_40 -> V_93 : F_31 ;
V_119 = V_40 -> V_119 ;
if ( V_116 -> V_135 || V_116 -> V_136 ) {
V_20 = V_40 -> V_136 ;
V_118 = V_40 -> V_135 ;
if ( V_116 -> V_135 )
V_118 = V_116 -> V_135 ;
if ( V_116 -> V_136 )
V_20 = V_116 -> V_136 ;
V_19 = F_63 ( V_2 , V_40 , V_118 ) ;
if ( V_20 <= 8 ) {
V_2 -> V_54 = 1 ;
V_2 -> V_93 = V_2 -> V_93 != F_31 ?
F_33 : F_31 ;
V_2 -> V_94 = V_2 -> V_94 != F_29 ?
F_32 : F_29 ;
} else if ( V_20 <= 16 ) {
V_2 -> V_54 = 2 ;
V_2 -> V_93 = V_2 -> V_93 != F_31 ?
F_35 : F_31 ;
V_2 -> V_94 = V_2 -> V_94 != F_29 ?
F_34 : F_29 ;
} else if ( V_20 <= 32 ) {
V_2 -> V_54 = 4 ;
V_2 -> V_93 = V_2 -> V_93 != F_31 ?
F_37 : F_31 ;
V_2 -> V_94 = V_2 -> V_94 != F_29 ?
F_36 : F_29 ;
}
if ( V_40 -> V_34 ) {
if ( F_66 ( V_40 ,
V_115 -> V_76 ,
V_20 , & V_123 ,
& V_121 ) )
F_65 ( & V_115 -> V_76 -> V_82 ,
L_9 ) ;
}
V_119 = F_11 ( V_2 , V_19 , V_20 ) ;
}
V_115 -> V_77 = V_69 ;
V_2 -> V_137 = 0 ;
if ( F_64 ( V_2 -> V_85 ) )
V_2 -> V_137 = F_67 ( V_2 ) ;
if ( V_2 -> V_137 ) {
V_2 -> V_101 = V_138 ;
F_68 ( V_2 , V_123 ) ;
V_120 = V_40 -> V_120 | V_121 | V_2 -> V_139 ;
F_22 ( V_2 -> V_80 , V_10 ) ;
F_69 ( V_2 ) ;
} else {
V_2 -> V_101 = F_56 ;
V_120 = V_40 -> V_120 | V_40 -> V_18 | V_2 -> V_79 ;
F_28 ( V_2 , V_2 -> V_80 ) ;
}
if ( F_1 ( V_2 ) ) {
if ( ( F_70 ( V_10 ) & 0xff ) != V_40 -> V_140 )
F_71 ( V_40 -> V_140 , V_10 ) ;
if ( ( F_72 ( V_10 ) & 0xffff ) != V_40 -> V_141 )
F_73 ( V_40 -> V_141 , V_10 ) ;
}
if ( F_2 ( V_2 ) &&
( F_74 ( V_10 ) != V_40 -> V_113 ) )
F_75 ( V_40 -> V_113 , V_10 ) ;
if ( ( F_52 ( V_10 ) != V_119 ) ||
( F_46 ( V_10 ) & V_125 ) != ( V_120 & V_125 ) ) {
F_51 ( V_119 & ~ V_22 , V_10 ) ;
if ( ! F_49 ( V_2 ) )
F_50 ( V_40 -> V_142 , V_10 ) ;
F_47 ( V_120 & V_125 , V_10 ) ;
F_51 ( V_119 , V_10 ) ;
} else {
if ( ! F_49 ( V_2 ) )
F_50 ( V_40 -> V_142 , V_10 ) ;
}
F_21 ( V_2 ) ;
F_47 ( V_120 , V_10 ) ;
}
static int F_76 ( struct V_143 * V_75 ,
struct V_60 * V_61 )
{
struct V_1 * V_2 = F_77 ( V_75 ) ;
V_2 -> V_62 = V_61 ;
V_2 -> V_62 -> V_77 = V_144 ;
V_2 -> V_65 = F_39 ( V_2 -> V_62 -> V_68 . V_67 ,
struct V_63 ,
V_66 ) ;
V_2 -> V_41 = F_78 ( V_2 -> V_62 -> V_76 ) ;
F_54 ( & V_2 -> V_83 ) ;
return 0 ;
}
static int F_79 ( struct V_143 * V_75 )
{
struct V_1 * V_2 = F_77 ( V_75 ) ;
F_51 ( F_52 ( V_2 -> V_11 ) & ~ V_22 ,
V_2 -> V_11 ) ;
return 0 ;
}
static int F_80 ( struct V_145 * V_76 , struct V_39 * V_40 ,
struct V_146 * V_147 )
{
int V_148 = 0 ;
if ( V_40 == NULL || V_147 == NULL )
return 0 ;
if ( F_23 ( V_40 -> V_46 ) )
F_81 ( V_40 -> V_46 ) ;
if ( V_147 -> V_44 ) {
V_40 -> V_44 = V_147 -> V_44 ;
return 0 ;
}
if ( F_23 ( V_147 -> V_46 ) ) {
V_148 = F_82 ( V_147 -> V_46 , L_10 ) ;
if ( V_148 ) {
F_53 ( & V_76 -> V_82 , L_11 ,
V_147 -> V_46 ) ;
return V_148 ;
}
V_40 -> V_46 = V_147 -> V_46 ;
V_40 -> V_47 = V_76 -> V_149 & V_150 ;
V_148 = F_83 ( V_40 -> V_46 ,
! V_40 -> V_47 ) ;
}
return V_148 ;
}
static int F_84 ( struct V_145 * V_76 )
{
struct V_146 * V_147 = NULL ;
struct V_39 * V_40 ;
struct V_1 * V_2 = F_77 ( V_76 -> V_75 ) ;
unsigned int V_19 ;
T_5 V_151 , V_152 , V_153 ;
switch ( V_2 -> V_3 ) {
case V_5 :
V_151 = V_154 ;
V_152 = 0 ;
V_153 = V_8 ;
break;
case V_4 :
V_151 = V_155 ;
V_152 = V_156 ;
V_153 = V_157 ;
break;
default:
V_151 = V_158 ;
V_152 = 0 ;
V_153 = V_9 ;
break;
}
V_40 = F_78 ( V_76 ) ;
if ( ! V_40 ) {
V_40 = F_85 ( sizeof( struct V_39 ) , V_159 ) ;
if ( ! V_40 )
return - V_160 ;
if ( V_2 -> V_3 == V_42 ) {
if ( V_76 -> V_161 > 4 ) {
F_53 ( & V_76 -> V_82 ,
L_12 ) ;
F_86 ( V_40 ) ;
return - V_132 ;
}
V_40 -> V_43 = V_76 -> V_161 ;
} else
V_40 -> V_46 = - 1 ;
V_40 -> V_34 = 0 ;
V_40 -> V_142 = V_162 ;
}
V_147 = V_76 -> V_163 ;
V_40 -> V_120 = 0 ;
if ( V_147 ) {
if ( V_147 -> V_142 )
V_40 -> V_142 = V_147 -> V_142 ;
if ( V_147 -> V_164 )
V_151 = V_147 -> V_164 ;
if ( V_147 -> V_165 )
V_152 = V_147 -> V_165 ;
if ( V_147 -> V_166 )
V_153 = V_147 -> V_166 ;
V_40 -> V_34 = V_2 -> V_33 -> V_34 ;
V_40 -> V_122 = 0 ;
if ( V_147 -> V_167 )
V_40 -> V_120 = V_168 ;
} else if ( F_87 ( & V_76 -> V_82 ) ) {
V_40 -> V_34 = V_2 -> V_33 -> V_34 ;
}
V_40 -> V_140 = F_88 ( V_153 ) ;
V_40 -> V_141 = F_89 ( V_151 )
| F_90 ( V_152 ) ;
if ( V_40 -> V_34 ) {
if ( F_66 ( V_40 , V_76 ,
V_76 -> V_136 ,
& V_40 -> V_124 ,
& V_40 -> V_122 ) ) {
F_91 ( & V_76 -> V_82 ,
L_13 ) ;
}
}
V_19 = F_63 ( V_2 , V_40 , V_76 -> V_169 ) ;
V_40 -> V_135 = V_76 -> V_169 ;
V_40 -> V_119 = F_11 ( V_2 , V_19 ,
V_76 -> V_136 ) ;
switch ( V_2 -> V_3 ) {
case V_5 :
V_40 -> V_18 = ( F_9 ( V_153 )
& V_16 )
| ( F_92 ( V_151 )
& V_170 ) ;
break;
default:
V_40 -> V_18 = ( F_10 ( V_153 ) & V_17 ) |
( F_93 ( V_151 ) & V_171 ) ;
break;
}
V_40 -> V_120 &= ~ ( V_172 | V_173 ) ;
V_40 -> V_120 |= ( ( ( V_76 -> V_149 & V_174 ) != 0 ) ? V_173 : 0 )
| ( ( ( V_76 -> V_149 & V_175 ) != 0 ) ? V_172 : 0 ) ;
if ( V_76 -> V_149 & V_176 )
V_40 -> V_120 |= V_168 ;
if ( ! F_49 ( V_2 ) )
F_94 ( & V_76 -> V_82 , L_14 ,
V_2 -> V_109
/ ( 1 + ( ( V_40 -> V_119 & F_95 ( 0xfff ) ) >> 8 ) ) ,
V_40 -> V_34 ? L_15 : L_16 ) ;
else
F_94 ( & V_76 -> V_82 , L_14 ,
V_2 -> V_109 / 2
/ ( 1 + ( ( V_40 -> V_119 & F_95 ( 0x0ff ) ) >> 8 ) ) ,
V_40 -> V_34 ? L_15 : L_16 ) ;
if ( V_76 -> V_136 <= 8 ) {
V_40 -> V_54 = 1 ;
V_40 -> V_93 = F_33 ;
V_40 -> V_94 = F_32 ;
} else if ( V_76 -> V_136 <= 16 ) {
V_40 -> V_54 = 2 ;
V_40 -> V_93 = F_35 ;
V_40 -> V_94 = F_34 ;
} else if ( V_76 -> V_136 <= 32 ) {
if ( ! F_2 ( V_2 ) )
V_40 -> V_119 |= V_24 ;
V_40 -> V_54 = 4 ;
V_40 -> V_93 = F_37 ;
V_40 -> V_94 = F_36 ;
}
V_40 -> V_136 = V_76 -> V_136 ;
F_96 ( V_76 , V_40 ) ;
if ( V_2 -> V_3 == V_42 )
return 0 ;
return F_80 ( V_76 , V_40 , V_147 ) ;
}
static void F_97 ( struct V_145 * V_76 )
{
struct V_39 * V_40 = F_78 ( V_76 ) ;
struct V_1 * V_2 = F_77 ( V_76 -> V_75 ) ;
if ( ! V_40 )
return;
if ( V_2 -> V_3 != V_42 && F_23 ( V_40 -> V_46 ) )
F_81 ( V_40 -> V_46 ) ;
F_86 ( V_40 ) ;
}
static struct V_177 *
F_98 ( struct V_178 * V_81 )
{
struct V_177 * V_179 ;
struct V_180 * V_181 ;
struct V_110 * V_111 ;
struct V_182 * V_183 ;
int V_184 ;
if ( ! F_87 ( & V_81 -> V_82 ) ||
F_99 ( F_87 ( & V_81 -> V_82 ) , & V_181 ) )
return NULL ;
V_179 = F_100 ( & V_81 -> V_82 , sizeof( * V_179 ) , V_159 ) ;
if ( ! V_179 )
return NULL ;
V_183 = F_101 ( V_81 , V_185 , 0 ) ;
if ( ! V_183 )
return NULL ;
V_111 = & V_179 -> V_111 ;
V_111 -> V_186 = V_183 -> V_187 ;
V_111 -> V_188 = F_102 ( & V_81 -> V_82 , V_183 ) ;
if ( F_103 ( V_111 -> V_188 ) )
return NULL ;
V_111 -> V_189 = F_104 ( & V_81 -> V_82 , NULL ) ;
V_111 -> V_97 = F_105 ( V_81 , 0 ) ;
V_111 -> type = V_4 ;
V_111 -> V_81 = V_81 ;
V_111 -> V_190 = - 1 ;
if ( V_181 -> V_191 . V_192 && ! F_106 ( V_181 -> V_191 . V_192 , 0 , & V_184 ) )
V_111 -> V_190 = V_184 ;
V_179 -> V_193 = 1 ;
V_179 -> V_34 = true ;
return V_179 ;
}
static inline struct V_177 *
F_98 ( struct V_178 * V_81 )
{
return NULL ;
}
static int F_107 ( struct V_178 * V_81 )
{
struct V_194 * V_82 = & V_81 -> V_82 ;
struct V_177 * V_195 ;
struct V_143 * V_75 ;
struct V_1 * V_2 ;
struct V_110 * V_111 ;
int V_99 ;
V_195 = F_108 ( V_82 ) ;
if ( ! V_195 ) {
V_195 = F_98 ( V_81 ) ;
if ( ! V_195 ) {
F_53 ( & V_81 -> V_82 , L_17 ) ;
return - V_196 ;
}
}
V_111 = F_109 ( V_81 -> V_197 , V_81 -> V_198 ) ;
if ( ! V_111 )
V_111 = & V_195 -> V_111 ;
if ( ! V_111 -> V_188 ) {
F_53 ( & V_81 -> V_82 , L_18 ) ;
return - V_196 ;
}
V_75 = F_110 ( V_82 , sizeof( struct V_1 ) + 16 ) ;
if ( ! V_75 ) {
F_53 ( & V_81 -> V_82 , L_19 ) ;
F_111 ( V_111 ) ;
return - V_160 ;
}
V_2 = F_77 ( V_75 ) ;
V_2 -> V_75 = V_75 ;
V_2 -> V_33 = V_195 ;
V_2 -> V_81 = V_81 ;
V_2 -> V_111 = V_111 ;
V_75 -> V_82 . V_199 = & V_81 -> V_82 ;
V_75 -> V_82 . V_200 = V_81 -> V_82 . V_200 ;
V_75 -> V_201 = V_175 | V_174 | V_150 | V_176 ;
V_75 -> V_202 = V_111 -> V_190 ;
V_75 -> V_193 = V_195 -> V_193 ;
V_75 -> V_203 = V_204 ;
V_75 -> F_97 = F_97 ;
V_75 -> F_84 = F_84 ;
V_75 -> V_205 = F_76 ;
V_75 -> V_206 = F_79 ;
V_75 -> V_207 = true ;
V_2 -> V_3 = V_111 -> type ;
V_2 -> V_208 = ( T_1 * ) F_112 ( & V_2 [ 1 ] , V_204 ) ;
V_2 -> V_11 = V_111 -> V_188 ;
V_2 -> V_209 = V_111 -> V_186 + V_210 ;
if ( F_49 ( V_2 ) ) {
switch ( V_2 -> V_3 ) {
case V_5 :
V_75 -> V_211 = F_113 ( 4 , 32 ) ;
break;
default:
V_75 -> V_211 = F_113 ( 4 , 16 ) ;
break;
}
V_2 -> V_79 = V_87 | V_212 ;
V_2 -> V_139 = 0 ;
V_2 -> V_80 = V_53 ;
V_2 -> V_88 = V_213 | V_89 | V_53 ;
} else {
V_75 -> V_211 = F_113 ( 4 , 32 ) ;
V_2 -> V_79 = V_87 | V_212 | V_214 ;
V_2 -> V_139 = V_215 ;
V_2 -> V_80 = V_53 | V_92 ;
V_2 -> V_88 = V_92 | V_213 | V_89 | V_53 ;
}
V_99 = F_114 ( V_111 -> V_97 , F_57 , V_216 , F_115 ( V_82 ) ,
V_2 ) ;
if ( V_99 < 0 ) {
F_53 ( & V_81 -> V_82 , L_20 , V_111 -> V_97 ) ;
goto V_217;
}
V_2 -> V_218 = - 1 ;
V_2 -> V_219 = - 1 ;
if ( V_195 -> V_34 ) {
V_99 = F_116 ( V_2 ) ;
if ( V_99 ) {
F_94 ( V_82 , L_21 ) ;
V_195 -> V_34 = false ;
}
}
F_117 ( V_111 -> V_189 ) ;
V_2 -> V_109 = F_118 ( V_111 -> V_189 ) ;
F_51 ( 0 , V_2 -> V_11 ) ;
switch ( V_2 -> V_3 ) {
case V_5 :
F_47 ( F_9 (
V_8 ) |
F_92 (
V_154 ) ,
V_2 -> V_11 ) ;
F_51 ( V_21
| F_12 ( 8 ) ,
V_2 -> V_11 ) ;
break;
default:
F_47 ( F_10 ( V_9 ) |
F_93 ( V_158 ) ,
V_2 -> V_11 ) ;
F_51 ( F_95 ( 2 )
| V_23
| F_13 ( 8 ) ,
V_2 -> V_11 ) ;
break;
}
if ( ! F_49 ( V_2 ) )
F_50 ( 0 , V_2 -> V_11 ) ;
if ( ! F_2 ( V_2 ) )
F_119 ( 0 , V_2 -> V_11 ) ;
F_19 ( V_2 ) ;
F_120 ( & V_2 -> V_83 , V_83 ,
( unsigned long ) V_2 ) ;
F_121 ( & V_81 -> V_82 , 50 ) ;
F_122 ( & V_81 -> V_82 ) ;
F_123 ( & V_81 -> V_82 ) ;
F_124 ( & V_81 -> V_82 ) ;
F_125 ( V_81 , V_2 ) ;
V_99 = F_126 ( & V_81 -> V_82 , V_75 ) ;
if ( V_99 != 0 ) {
F_53 ( & V_81 -> V_82 , L_22 ) ;
goto V_220;
}
return V_99 ;
V_220:
F_127 ( V_111 -> V_189 ) ;
F_128 ( V_2 ) ;
F_129 ( V_111 -> V_97 , V_2 ) ;
V_217:
F_130 ( V_75 ) ;
F_111 ( V_111 ) ;
return V_99 ;
}
static int F_131 ( struct V_178 * V_81 )
{
struct V_1 * V_2 = F_132 ( V_81 ) ;
struct V_110 * V_111 ;
if ( ! V_2 )
return 0 ;
V_111 = V_2 -> V_111 ;
F_133 ( & V_81 -> V_82 ) ;
F_51 ( 0 , V_2 -> V_11 ) ;
F_127 ( V_111 -> V_189 ) ;
if ( V_2 -> V_33 -> V_34 )
F_128 ( V_2 ) ;
F_134 ( & V_81 -> V_82 ) ;
F_135 ( & V_81 -> V_82 ) ;
F_129 ( V_111 -> V_97 , V_2 ) ;
F_111 ( V_111 ) ;
return 0 ;
}
static void F_136 ( struct V_178 * V_81 )
{
int V_99 = 0 ;
if ( ( V_99 = F_131 ( V_81 ) ) != 0 )
F_53 ( & V_81 -> V_82 , L_23 , V_99 ) ;
}
static int F_137 ( struct V_194 * V_82 )
{
struct V_1 * V_2 = F_138 ( V_82 ) ;
struct V_110 * V_111 = V_2 -> V_111 ;
int V_99 = 0 ;
V_99 = F_139 ( V_2 -> V_75 ) ;
if ( V_99 != 0 )
return V_99 ;
F_51 ( 0 , V_2 -> V_11 ) ;
if ( ! F_58 ( V_82 ) )
F_127 ( V_111 -> V_189 ) ;
return 0 ;
}
static int F_140 ( struct V_194 * V_82 )
{
struct V_1 * V_2 = F_138 ( V_82 ) ;
struct V_110 * V_111 = V_2 -> V_111 ;
int V_99 = 0 ;
F_141 ( V_2 ) ;
if ( ! F_58 ( V_82 ) )
F_117 ( V_111 -> V_189 ) ;
F_19 ( V_2 ) ;
V_99 = F_142 ( V_2 -> V_75 ) ;
if ( V_99 != 0 ) {
F_53 ( V_82 , L_24 , V_99 ) ;
return V_99 ;
}
return 0 ;
}
static int F_143 ( struct V_194 * V_82 )
{
struct V_1 * V_2 = F_138 ( V_82 ) ;
F_127 ( V_2 -> V_111 -> V_189 ) ;
return 0 ;
}
static int F_144 ( struct V_194 * V_82 )
{
struct V_1 * V_2 = F_138 ( V_82 ) ;
F_117 ( V_2 -> V_111 -> V_189 ) ;
return 0 ;
}
static int T_6 F_145 ( void )
{
return F_146 ( & V_221 ) ;
}
static void T_7 F_147 ( void )
{
F_148 ( & V_221 ) ;
}
