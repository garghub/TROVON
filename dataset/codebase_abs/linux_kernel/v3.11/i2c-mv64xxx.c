static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
T_1 V_5 = 0 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_6 = 0 ;
V_2 -> V_7 = V_4 -> V_8 ;
V_2 -> V_9 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_11 = V_12 |
V_13 | V_14 ;
if ( V_4 -> V_15 & V_16 )
V_5 = 1 ;
if ( V_4 -> V_15 & V_17 ) {
V_2 -> V_18 = 0xf0 | ( ( ( T_1 ) V_4 -> V_19 & 0x300 ) >> 7 ) | V_5 ;
V_2 -> V_20 = ( T_1 ) V_4 -> V_19 & 0xff ;
} else {
V_2 -> V_18 = F_2 ( ( T_1 ) V_4 -> V_19 ) | V_5 ;
V_2 -> V_20 = 0 ;
}
}
static void
F_3 ( struct V_1 * V_2 )
{
F_4 ( 0 , V_2 -> V_21 + V_2 -> V_22 . V_23 ) ;
F_4 ( F_5 ( V_2 -> V_24 ) | F_6 ( V_2 -> V_25 ) ,
V_2 -> V_21 + V_2 -> V_22 . clock ) ;
F_4 ( 0 , V_2 -> V_21 + V_2 -> V_22 . V_19 ) ;
F_4 ( 0 , V_2 -> V_21 + V_2 -> V_22 . V_26 ) ;
F_4 ( V_14 | V_27 ,
V_2 -> V_21 + V_2 -> V_22 . V_28 ) ;
V_2 -> V_29 = V_30 ;
}
static void
F_7 ( struct V_1 * V_2 , T_1 V_31 )
{
if ( V_2 -> V_29 == V_30 ) {
V_2 -> V_32 = V_33 ;
return;
}
switch ( V_31 ) {
case V_34 :
case V_35 :
V_2 -> V_32 = V_36 ;
V_2 -> V_29 = V_37 ;
break;
case V_38 :
if ( V_2 -> V_4 -> V_15 & V_17 ) {
V_2 -> V_32 = V_39 ;
V_2 -> V_29 =
V_40 ;
break;
}
case V_41 :
case V_42 :
if ( ( V_2 -> V_7 == 0 )
|| ( V_2 -> V_9
&& ( V_2 -> V_6 != 0 ) ) ) {
if ( V_2 -> V_43 || V_2 -> V_9 ) {
V_2 -> V_32 = V_33 ;
V_2 -> V_29 = V_30 ;
} else {
V_2 -> V_32 =
V_44 ;
V_2 -> V_29 =
V_45 ;
}
} else {
V_2 -> V_32 = V_46 ;
V_2 -> V_29 =
V_47 ;
V_2 -> V_7 -- ;
}
break;
case V_48 :
if ( V_2 -> V_4 -> V_15 & V_17 ) {
V_2 -> V_32 = V_39 ;
V_2 -> V_29 =
V_40 ;
break;
}
case V_49 :
if ( V_2 -> V_7 == 0 ) {
V_2 -> V_32 = V_33 ;
V_2 -> V_29 = V_30 ;
break;
}
case V_50 :
if ( V_31 != V_50 )
V_2 -> V_32 = V_51 ;
else {
V_2 -> V_32 = V_52 ;
V_2 -> V_7 -- ;
}
V_2 -> V_29 = V_53 ;
if ( ( V_2 -> V_7 == 1 ) || V_2 -> V_9 )
V_2 -> V_11 &= ~ V_12 ;
break;
case V_54 :
V_2 -> V_32 = V_55 ;
V_2 -> V_29 = V_30 ;
break;
case V_56 :
case V_57 :
case V_58 :
V_2 -> V_32 = V_33 ;
V_2 -> V_29 = V_30 ;
V_2 -> V_10 = - V_59 ;
break;
default:
F_8 ( & V_2 -> V_60 . V_61 ,
L_1
L_2 ,
V_2 -> V_29 , V_31 , V_2 -> V_4 -> V_19 ,
V_2 -> V_4 -> V_15 ) ;
V_2 -> V_32 = V_33 ;
F_3 ( V_2 ) ;
V_2 -> V_10 = - V_62 ;
}
}
static void
F_9 ( struct V_1 * V_2 )
{
switch( V_2 -> V_32 ) {
case V_44 :
F_10 ( V_2 -> V_63 == 0 ) ;
V_2 -> V_11 |= V_64 ;
F_4 ( V_2 -> V_11 ,
V_2 -> V_21 + V_2 -> V_22 . V_28 ) ;
V_2 -> V_65 ++ ;
V_2 -> V_63 -- ;
F_1 ( V_2 , V_2 -> V_65 ) ;
V_2 -> V_43 = V_2 -> V_63 == 1 ;
break;
case V_51 :
F_4 ( V_2 -> V_11 ,
V_2 -> V_21 + V_2 -> V_22 . V_28 ) ;
break;
case V_66 :
F_4 ( V_2 -> V_11 | V_64 ,
V_2 -> V_21 + V_2 -> V_22 . V_28 ) ;
break;
case V_36 :
F_4 ( V_2 -> V_18 ,
V_2 -> V_21 + V_2 -> V_22 . V_67 ) ;
F_4 ( V_2 -> V_11 ,
V_2 -> V_21 + V_2 -> V_22 . V_28 ) ;
break;
case V_39 :
F_4 ( V_2 -> V_20 ,
V_2 -> V_21 + V_2 -> V_22 . V_67 ) ;
F_4 ( V_2 -> V_11 ,
V_2 -> V_21 + V_2 -> V_22 . V_28 ) ;
break;
case V_46 :
F_4 ( V_2 -> V_4 -> V_68 [ V_2 -> V_6 ++ ] ,
V_2 -> V_21 + V_2 -> V_22 . V_67 ) ;
F_4 ( V_2 -> V_11 ,
V_2 -> V_21 + V_2 -> V_22 . V_28 ) ;
break;
case V_52 :
V_2 -> V_4 -> V_68 [ V_2 -> V_6 ++ ] =
F_11 ( V_2 -> V_21 + V_2 -> V_22 . V_67 ) ;
F_4 ( V_2 -> V_11 ,
V_2 -> V_21 + V_2 -> V_22 . V_28 ) ;
break;
case V_55 :
V_2 -> V_4 -> V_68 [ V_2 -> V_6 ++ ] =
F_11 ( V_2 -> V_21 + V_2 -> V_22 . V_67 ) ;
V_2 -> V_11 &= ~ V_13 ;
F_4 ( V_2 -> V_11 | V_27 ,
V_2 -> V_21 + V_2 -> V_22 . V_28 ) ;
V_2 -> V_69 = 0 ;
F_12 ( & V_2 -> V_70 ) ;
break;
case V_71 :
default:
F_8 ( & V_2 -> V_60 . V_61 ,
L_3 ,
V_2 -> V_32 ) ;
V_2 -> V_10 = - V_62 ;
case V_33 :
V_2 -> V_11 &= ~ V_13 ;
F_4 ( V_2 -> V_11 | V_27 ,
V_2 -> V_21 + V_2 -> V_22 . V_28 ) ;
V_2 -> V_69 = 0 ;
F_12 ( & V_2 -> V_70 ) ;
break;
}
}
static T_2
F_13 ( int V_72 , void * V_73 )
{
struct V_1 * V_2 = V_73 ;
unsigned long V_15 ;
T_1 V_31 ;
T_2 V_10 = V_74 ;
F_14 ( & V_2 -> V_75 , V_15 ) ;
while ( F_11 ( V_2 -> V_21 + V_2 -> V_22 . V_28 ) &
V_76 ) {
V_31 = F_11 ( V_2 -> V_21 + V_2 -> V_22 . V_31 ) ;
F_7 ( V_2 , V_31 ) ;
F_9 ( V_2 ) ;
V_10 = V_77 ;
}
F_15 ( & V_2 -> V_75 , V_15 ) ;
return V_10 ;
}
static void
F_16 ( struct V_1 * V_2 )
{
long V_78 ;
unsigned long V_15 ;
char abort = 0 ;
V_78 = F_17 ( V_2 -> V_70 ,
! V_2 -> V_69 , V_2 -> V_60 . V_79 ) ;
F_14 ( & V_2 -> V_75 , V_15 ) ;
if ( ! V_78 ) {
V_2 -> V_10 = - V_80 ;
abort = 1 ;
} else if ( V_78 < 0 ) {
V_2 -> V_10 = V_78 ;
abort = 1 ;
}
if ( abort && V_2 -> V_69 ) {
V_2 -> V_9 = 1 ;
F_15 ( & V_2 -> V_75 , V_15 ) ;
V_78 = F_17 ( V_2 -> V_70 ,
! V_2 -> V_69 , V_2 -> V_60 . V_79 ) ;
if ( ( V_78 <= 0 ) && V_2 -> V_69 ) {
V_2 -> V_29 = V_30 ;
F_8 ( & V_2 -> V_60 . V_61 ,
L_4
L_5 , V_2 -> V_69 ,
( int ) V_78 ) ;
F_3 ( V_2 ) ;
}
} else
F_15 ( & V_2 -> V_75 , V_15 ) ;
}
static int
F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_81 )
{
unsigned long V_15 ;
F_14 ( & V_2 -> V_75 , V_15 ) ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_32 = V_66 ;
V_2 -> V_29 = V_82 ;
V_2 -> V_43 = V_81 ;
V_2 -> V_69 = 1 ;
F_9 ( V_2 ) ;
F_15 ( & V_2 -> V_75 , V_15 ) ;
F_16 ( V_2 ) ;
return V_2 -> V_10 ;
}
static T_1
F_19 ( struct V_83 * V_84 )
{
return V_85 | V_86 | V_87 ;
}
static int
F_20 ( struct V_83 * V_84 , struct V_3 V_65 [] , int V_88 )
{
struct V_1 * V_2 = F_21 ( V_84 ) ;
int V_10 , V_89 = V_88 ;
F_10 ( V_2 -> V_65 != NULL ) ;
V_2 -> V_65 = V_65 ;
V_2 -> V_63 = V_88 ;
V_10 = F_18 ( V_2 , & V_65 [ 0 ] , V_88 == 1 ) ;
if ( V_10 < 0 )
V_89 = V_10 ;
V_2 -> V_63 = 0 ;
V_2 -> V_65 = NULL ;
return V_89 ;
}
static int
F_22 ( const int V_90 , const int V_91 , const int V_92 )
{
return V_90 / ( 10 * ( V_92 + 1 ) * ( 2 << V_91 ) ) ;
}
static bool
F_23 ( const T_1 V_93 , const T_1 V_90 , T_1 * V_94 ,
T_1 * V_95 )
{
int V_96 , V_97 , V_98 = V_99 ;
int V_92 , V_91 ;
for ( V_91 = 0 ; V_91 <= 7 ; V_91 ++ )
for ( V_92 = 0 ; V_92 <= 15 ; V_92 ++ ) {
V_96 = F_22 ( V_90 , V_91 , V_92 ) ;
V_97 = V_93 - V_96 ;
if ( V_97 >= 0 && V_97 < V_98 ) {
* V_95 = V_92 ;
* V_94 = V_91 ;
V_98 = V_97 ;
}
if ( V_98 == 0 )
return true ;
}
if ( V_98 == V_99 )
return false ;
return true ;
}
static int
F_24 ( struct V_1 * V_2 ,
struct V_100 * V_61 )
{
const struct V_101 * V_100 ;
struct V_102 * V_103 = V_61 -> V_104 ;
T_1 V_105 , V_90 ;
int V_10 = 0 ;
#if ! F_25 ( V_106 )
return - V_107 ;
#else
if ( F_26 ( V_2 -> V_108 ) ) {
V_10 = - V_107 ;
goto V_109;
}
V_90 = F_27 ( V_2 -> V_108 ) ;
V_10 = F_28 ( V_103 , L_6 , & V_105 ) ;
if ( V_10 )
V_105 = 100000 ;
if ( ! F_23 ( V_105 , V_90 ,
& V_2 -> V_25 , & V_2 -> V_24 ) ) {
V_10 = - V_110 ;
goto V_109;
}
V_2 -> V_72 = F_29 ( V_103 , 0 ) ;
V_2 -> V_60 . V_79 = V_111 ;
V_100 = F_30 ( V_112 , V_61 ) ;
if ( ! V_100 )
return - V_107 ;
memcpy ( & V_2 -> V_22 , V_100 -> V_67 , sizeof( V_2 -> V_22 ) ) ;
V_109:
return V_10 ;
#endif
}
static int
F_24 ( struct V_1 * V_2 ,
struct V_100 * V_61 )
{
return - V_107 ;
}
static int
F_31 ( struct V_113 * V_114 )
{
struct V_1 * V_2 ;
struct V_115 * V_116 = V_114 -> V_61 . V_117 ;
struct V_118 * V_119 ;
int V_10 ;
if ( ( ! V_116 && ! V_114 -> V_61 . V_104 ) )
return - V_107 ;
V_2 = F_32 ( & V_114 -> V_61 , sizeof( struct V_1 ) ,
V_120 ) ;
if ( ! V_2 )
return - V_121 ;
V_119 = F_33 ( V_114 , V_122 , 0 ) ;
V_2 -> V_21 = F_34 ( & V_114 -> V_61 , V_119 ) ;
if ( F_26 ( V_2 -> V_21 ) )
return F_35 ( V_2 -> V_21 ) ;
F_36 ( V_2 -> V_60 . V_123 , V_124 L_7 ,
sizeof( V_2 -> V_60 . V_123 ) ) ;
F_37 ( & V_2 -> V_70 ) ;
F_38 ( & V_2 -> V_75 ) ;
#if F_25 ( V_106 )
V_2 -> V_108 = F_39 ( & V_114 -> V_61 , NULL ) ;
if ( ! F_26 ( V_2 -> V_108 ) ) {
F_40 ( V_2 -> V_108 ) ;
F_41 ( V_2 -> V_108 ) ;
}
#endif
if ( V_116 ) {
V_2 -> V_24 = V_116 -> V_24 ;
V_2 -> V_25 = V_116 -> V_25 ;
V_2 -> V_72 = F_42 ( V_114 , 0 ) ;
V_2 -> V_60 . V_79 = F_43 ( V_116 -> V_79 ) ;
memcpy ( & V_2 -> V_22 , & V_125 , sizeof( V_2 -> V_22 ) ) ;
} else if ( V_114 -> V_61 . V_104 ) {
V_10 = F_24 ( V_2 , & V_114 -> V_61 ) ;
if ( V_10 )
goto V_126;
}
if ( V_2 -> V_72 < 0 ) {
V_10 = - V_59 ;
goto V_126;
}
V_2 -> V_60 . V_61 . V_127 = & V_114 -> V_61 ;
V_2 -> V_60 . V_128 = & V_129 ;
V_2 -> V_60 . V_130 = V_131 ;
V_2 -> V_60 . V_132 = V_133 | V_134 ;
V_2 -> V_60 . V_135 = V_114 -> V_136 ;
V_2 -> V_60 . V_61 . V_104 = V_114 -> V_61 . V_104 ;
F_44 ( V_114 , V_2 ) ;
F_45 ( & V_2 -> V_60 , V_2 ) ;
F_3 ( V_2 ) ;
V_10 = F_46 ( V_2 -> V_72 , F_13 , 0 ,
V_124 , V_2 ) ;
if ( V_10 ) {
F_8 ( & V_2 -> V_60 . V_61 ,
L_8 ,
V_2 -> V_72 , V_10 ) ;
goto V_126;
} else if ( ( V_10 = F_47 ( & V_2 -> V_60 ) ) != 0 ) {
F_8 ( & V_2 -> V_60 . V_61 ,
L_9 , - V_10 ) ;
goto V_137;
}
F_48 ( & V_2 -> V_60 ) ;
return 0 ;
V_137:
F_49 ( V_2 -> V_72 , V_2 ) ;
V_126:
#if F_25 ( V_106 )
if ( ! F_26 ( V_2 -> V_108 ) ) {
F_50 ( V_2 -> V_108 ) ;
F_51 ( V_2 -> V_108 ) ;
}
#endif
return V_10 ;
}
static int
F_52 ( struct V_113 * V_61 )
{
struct V_1 * V_2 = F_53 ( V_61 ) ;
F_54 ( & V_2 -> V_60 ) ;
F_49 ( V_2 -> V_72 , V_2 ) ;
#if F_25 ( V_106 )
if ( ! F_26 ( V_2 -> V_108 ) ) {
F_50 ( V_2 -> V_108 ) ;
F_51 ( V_2 -> V_108 ) ;
}
#endif
return 0 ;
}
