static inline int F_1 ( T_1 V_1 )
{
return V_1 & 0x0000000f ;
}
static inline int F_2 ( T_1 V_1 )
{
return ( V_1 & 0x000007f0 ) >> 4 ;
}
static inline int F_3 ( T_1 V_1 )
{
return V_1 & 0x00010000 ;
}
static inline T_1 F_4 ( const struct V_2 * V_3 , T_2 V_4 )
{
return F_5 ( V_3 -> V_5 + V_4 ) ;
}
static inline void F_6 ( const struct V_2 * V_3 ,
T_1 V_6 , T_2 V_4 )
{
F_7 ( V_6 , V_3 -> V_5 + V_4 ) ;
}
static inline T_1 F_8 ( const struct V_7 * V_3 , T_2 V_4 )
{
return F_5 ( V_3 -> V_5 + V_4 ) ;
}
static inline void F_9 ( const struct V_7 * V_3 ,
T_1 V_6 , T_2 V_4 )
{
F_7 ( V_6 , V_3 -> V_5 + V_4 ) ;
}
static void F_10 ( struct V_7 * V_3 )
{
#ifdef F_11
const T_1 V_8 = ( T_1 ) ( V_3 -> V_9 >> 32 ) ;
#else
const T_1 V_8 = 0 ;
#endif
F_9 ( V_3 , V_10 , V_11 ) ;
F_9 ( V_3 , ( T_1 ) V_3 -> V_9 ,
V_12 ) ;
F_9 ( V_3 , V_8 , V_13 ) ;
F_9 ( V_3 , V_14 , V_15 ) ;
}
static void F_12 ( struct V_7 * V_3 )
{
F_9 ( V_3 , V_10 , V_11 ) ;
F_9 ( V_3 , 0 , V_12 ) ;
F_9 ( V_3 , 0 , V_13 ) ;
}
static void F_13 ( struct V_7 * V_3 )
{
#ifdef F_11
const T_1 V_8 = ( T_1 ) ( V_3 -> V_16 >> 32 ) ;
#else
const T_1 V_8 = 0 ;
#endif
F_9 ( V_3 , V_10 , V_17 ) ;
F_9 ( V_3 , ( T_1 ) V_3 -> V_16 ,
V_18 ) ;
F_9 ( V_3 , V_8 , V_19 ) ;
F_9 ( V_3 , V_14 , V_20 ) ;
}
static void F_14 ( struct V_7 * V_3 )
{
F_9 ( V_3 , V_10 , V_17 ) ;
F_9 ( V_3 , 0 , V_18 ) ;
F_9 ( V_3 , 0 , V_19 ) ;
}
static void F_15 ( struct V_7 * V_3 )
{
V_3 -> V_21 = F_16 ( * ( V_22 * ) V_3 -> V_23 ) ;
V_3 -> V_21 ++ ;
V_3 -> V_21 &= 0xf ;
F_9 ( V_3 , V_3 -> V_21 , V_24 ) ;
}
static T_3 F_17 ( int V_25 , void * V_26 )
{
struct V_7 * V_3 = V_26 ;
struct V_27 * V_28 = V_3 -> V_23 ;
if ( ! F_18 ( V_3 -> V_29 -> V_30 ) )
( void ) F_4 ( V_3 -> V_29 , V_31 ) ;
V_3 -> V_1 = F_16 ( V_28 -> V_1 ) ;
if ( F_1 ( V_3 -> V_1 ) != V_3 -> V_21 )
return V_32 ;
F_19 ( & V_3 -> V_33 ,
V_28 -> V_34 ,
F_2 ( V_3 -> V_1 ) ) ;
if ( F_3 ( V_3 -> V_1 ) ) {
unsigned long V_35 ;
F_20 ( & V_3 -> V_36 , V_35 ) ;
V_3 -> V_37 ++ ;
F_21 ( & V_3 -> V_36 , V_35 ) ;
F_22 ( V_3 -> V_33 . V_38 ) ;
}
F_15 ( V_3 ) ;
return V_39 ;
}
static int F_23 ( struct V_40 * V_33 )
{
struct V_7 * V_3 = (struct V_7 * ) V_33 ;
int V_41 ;
V_3 -> V_37 = V_42 - 1 ;
V_3 -> V_43 = 0 ;
V_3 -> V_44 [ 0 ] . V_45 = V_3 -> V_46 ;
V_3 -> V_44 [ 0 ] . V_47 = V_3 -> V_16 ;
for ( V_41 = 0 ; V_41 < V_42 ; V_41 ++ ) {
V_3 -> V_44 [ V_41 ] . V_48 = 0 ;
V_3 -> V_44 [ V_41 ] . V_49 = V_50 -
sizeof( struct V_51 ) ;
if ( V_41 ) {
V_3 -> V_44 [ V_41 ] . V_45 =
V_3 -> V_44 [ V_41 - 1 ] . V_45 +
V_50 ;
V_3 -> V_44 [ V_41 ] . V_47 =
V_3 -> V_44 [ V_41 - 1 ] . V_47 +
V_50 ;
}
}
F_13 ( V_3 ) ;
F_9 ( V_3 , V_10 , V_20 ) ;
return 0 ;
}
static int F_24 ( struct V_40 * V_33 )
{
struct V_7 * V_3 = (struct V_7 * ) V_33 ;
T_2 V_52 = F_25 ( & V_3 -> V_53 ) ;
int V_54 ;
switch ( V_52 ) {
case V_55 :
case V_56 :
if ( V_33 -> V_57 . V_58 == V_59 )
break;
V_54 = F_26 ( V_3 -> V_29 -> V_30 -> V_25 ,
F_17 ,
V_60 ,
V_61 ,
V_3 ) ;
if ( V_54 )
return V_54 ;
F_10 ( V_3 ) ;
F_9 ( V_3 , ( V_62 ) << 8 |
V_63 ,
V_64 ) ;
F_9 ( V_3 , V_10 ,
V_15 ) ;
F_9 ( V_3 , ! V_65 ,
V_66 ) ;
F_15 ( V_3 ) ;
F_9 ( V_3 , V_67 ,
V_11 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_27 ( struct V_40 * V_33 )
{
struct V_7 * V_3 = (struct V_7 * ) V_33 ;
unsigned long V_35 ;
F_20 ( & V_3 -> V_29 -> V_68 , V_35 ) ;
F_9 ( V_3 , * ( T_1 * ) V_33 -> V_69 ,
V_70 ) ;
F_9 ( V_3 , * ( T_1 * ) ( V_33 -> V_69 + 4 ) ,
V_71 ) ;
F_21 ( & V_3 -> V_29 -> V_68 , V_35 ) ;
return 0 ;
}
static int F_28 ( struct V_40 * V_33 )
{
struct V_7 * V_3 = (struct V_7 * ) V_33 ;
T_2 V_52 = F_25 ( & V_3 -> V_53 ) ;
switch ( V_52 ) {
case V_72 :
if ( V_33 -> V_57 . V_58 == V_73 )
break;
F_14 ( V_3 ) ;
F_12 ( V_3 ) ;
F_9 ( V_3 , V_67 ,
V_15 ) ;
F_29 ( V_3 -> V_29 -> V_30 -> V_25 , V_3 ) ;
V_33 -> V_57 . V_58 = V_73 ;
break;
}
return 0 ;
}
static void * F_30 ( struct V_40 * V_33 , T_2 V_74 ,
int * V_75 )
{
struct V_7 * V_3 = (struct V_7 * ) V_33 ;
struct V_76 * V_77 = V_3 -> V_44 + V_3 -> V_43 ;
unsigned long V_35 ;
void * V_34 ;
F_20 ( & V_3 -> V_36 , V_35 ) ;
if ( V_77 -> V_48 + V_74 > V_77 -> V_49 ) {
struct V_51 * V_78 ;
if ( ! V_3 -> V_37 ) {
F_21 ( & V_3 -> V_36 , V_35 ) ;
return NULL ;
}
V_3 -> V_37 -- ;
V_78 = V_77 -> V_45 + V_77 -> V_48 ;
V_3 -> V_43 = ( V_3 -> V_43 + 1 ) %
V_42 ;
V_77 = V_3 -> V_44 + V_3 -> V_43 ;
V_78 -> V_49 = F_31 ( sizeof( * V_78 ) ) ;
V_78 -> type = F_31 ( V_79 ) ;
V_78 -> V_80 = F_32 ( V_77 -> V_47 ) ;
#ifdef F_11
V_78 -> V_81 = F_32 ( V_77 -> V_47 >> 32 ) ;
#else
V_78 -> V_81 = 0 ;
#endif
V_77 -> V_48 = 0 ;
}
* V_75 = V_3 -> V_37 * V_77 -> V_49 ;
F_21 ( & V_3 -> V_36 , V_35 ) ;
V_34 = V_77 -> V_45 + V_77 -> V_48 ;
* V_75 += V_77 -> V_49 - ( V_77 -> V_48 + V_74 ) ;
return V_34 ;
}
static int F_33 ( struct V_40 * V_33 ,
struct V_82 * V_34 )
{
struct V_7 * V_3 = (struct V_7 * ) V_33 ;
struct V_76 * V_77 = V_3 -> V_44 + V_3 -> V_43 ;
V_77 -> V_48 += F_34 ( V_34 -> V_49 ) ;
F_9 ( V_3 , 1 , V_83 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_84 )
{
struct V_85 * V_38 ;
struct V_7 * V_3 ;
T_1 V_86 ;
int V_54 ;
V_38 = F_36 ( sizeof( * V_3 ) , V_84 -> V_87 ,
V_88 ) ;
if ( ! V_38 ) {
F_37 ( & V_84 -> V_30 -> V_89 ,
L_1 ) ;
goto V_90;
}
V_3 = F_38 ( V_38 ) ;
V_3 -> V_33 . V_91 = F_24 ;
V_3 -> V_33 . V_92 = F_27 ;
V_3 -> V_33 . V_93 = F_28 ;
V_3 -> V_33 . V_94 = F_23 ;
V_3 -> V_33 . V_95 = F_30 ;
V_3 -> V_33 . V_96 = F_33 ;
V_3 -> V_33 . V_69 = & V_3 -> V_53 ;
V_3 -> V_33 . V_97 = sizeof( V_3 -> V_53 ) ;
V_3 -> V_29 = V_84 ;
V_3 -> V_5 = V_84 -> V_5 + F_39 ( V_3 -> V_33 . V_98 ) ;
V_3 -> V_23 = F_40 ( & V_84 -> V_30 -> V_89 ,
V_99 ,
& V_3 -> V_9 ,
V_100 ) ;
if ( ! V_3 -> V_23 ) {
F_37 ( & V_84 -> V_30 -> V_89 ,
L_2 ,
V_99 ) ;
goto V_101;
}
V_3 -> V_46 = F_40 ( & V_84 -> V_30 -> V_89 ,
V_102 ,
& V_3 -> V_16 ,
V_100 ) ;
if ( ! V_3 -> V_46 ) {
F_37 ( & V_84 -> V_30 -> V_89 ,
L_3 ,
V_102 ) ;
goto V_101;
}
F_9 ( V_3 , V_65 , V_66 ) ;
V_86 = F_8 ( V_3 , V_103 ) ;
switch ( V_86 ) {
case V_104 :
V_3 -> V_33 . V_57 . clock . V_105 = 20 * 1000 * 1000 ;
break;
case V_106 :
V_3 -> V_33 . V_57 . clock . V_105 = 24 * 1000 * 1000 ;
break;
case V_107 :
V_3 -> V_33 . V_57 . clock . V_105 = 30 * 1000 * 1000 ;
break;
case V_108 :
V_3 -> V_33 . V_57 . clock . V_105 = 40 * 1000 * 1000 ;
break;
case V_109 :
V_3 -> V_33 . V_57 . clock . V_105 = 60 * 1000 * 1000 ;
break;
default:
F_9 ( V_3 , V_110 ,
V_103 ) ;
case V_110 :
V_3 -> V_33 . V_57 . clock . V_105 = 80 * 1000 * 1000 ;
break;
}
V_38 -> V_25 = V_84 -> V_30 -> V_25 ;
F_41 ( V_38 , & V_84 -> V_30 -> V_89 ) ;
V_54 = F_42 ( V_38 ) ;
if ( V_54 ) {
F_37 ( & V_84 -> V_30 -> V_89 ,
L_4 , V_54 ) ;
goto V_101;
}
F_43 ( & V_3 -> V_36 ) ;
V_84 -> V_57 [ V_84 -> V_87 ] = V_3 ;
F_44 ( & V_84 -> V_30 -> V_89 , L_5 ,
V_38 -> V_111 , V_3 -> V_5 , V_84 -> V_30 -> V_25 ) ;
return 0 ;
V_101:
F_45 ( V_38 ) ;
V_90:
return - V_112 ;
}
static void F_46 ( struct V_7 * V_3 )
{
F_47 ( V_3 -> V_33 . V_38 ) ;
F_45 ( V_3 -> V_33 . V_38 ) ;
}
static void F_48 ( struct V_2 * V_84 )
{
while ( V_84 -> V_87 > 0 )
F_46 ( V_84 -> V_57 [ -- V_84 -> V_87 ] ) ;
}
static int F_49 ( struct V_30 * V_113 ,
const struct V_114 * V_115 )
{
struct V_2 * V_84 ;
int V_54 , V_87 ;
T_2 V_116 ;
T_4 V_117 ;
T_4 V_118 ;
T_4 V_119 ;
T_1 V_120 ;
V_54 = F_50 ( V_113 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_51 ( V_113 , V_61 ) ;
if ( V_54 )
goto V_121;
V_54 = F_52 ( V_113 , V_122 , & V_116 ) ;
if ( V_54 )
goto V_123;
F_53 ( & V_113 -> V_89 , L_6 ,
V_113 -> V_124 , V_113 -> V_125 , V_116 ) ;
if ( V_116 >= 0x0012 )
V_87 = 4 ;
else if ( V_116 >= 0x0010 )
V_87 = 3 ;
else if ( V_116 >= 0x0004 )
V_87 = 2 ;
else
V_87 = 1 ;
V_84 = F_54 ( & V_113 -> V_89 , sizeof( * V_84 ) +
V_87 * sizeof( * V_84 -> V_57 ) ,
V_100 ) ;
if ( ! V_84 ) {
V_54 = - V_112 ;
goto V_123;
}
V_84 -> V_30 = V_113 ;
F_43 ( & V_84 -> V_68 ) ;
V_84 -> V_5 = F_55 ( V_113 , 0 , V_126 ) ;
if ( ! V_84 -> V_5 ) {
F_37 ( & V_113 -> V_89 , L_7 ) ;
V_54 = - V_112 ;
goto V_123;
}
V_120 = F_4 ( V_84 , V_127 ) ;
V_117 = ( V_120 & 0x0000f000 ) >> 12 ;
V_118 = ( V_120 & 0x00000f00 ) >> 8 ;
V_119 = ( V_120 & 0x000000f0 ) >> 4 ;
F_44 ( & V_113 -> V_89 ,
L_8 , V_87 ,
V_117 , V_118 , V_119 ) ;
F_6 ( V_84 , V_128 ,
V_129 ) ;
F_56 ( V_113 ) ;
while ( V_84 -> V_87 < V_87 ) {
V_54 = F_35 ( V_84 ) ;
if ( V_54 )
goto V_130;
V_84 -> V_87 ++ ;
}
F_6 ( V_84 , V_131 ,
V_132 ) ;
( void ) F_4 ( V_84 , V_31 ) ;
F_6 ( V_84 , V_131 ,
V_129 ) ;
F_6 ( V_84 , V_128 ,
V_132 ) ;
F_57 ( V_113 , V_84 ) ;
return 0 ;
V_130:
F_48 ( V_84 ) ;
F_58 ( V_113 , V_84 -> V_5 ) ;
V_123:
F_59 ( V_113 ) ;
V_121:
F_60 ( V_113 ) ;
return V_54 ;
}
static void F_61 ( struct V_30 * V_113 )
{
struct V_2 * V_84 = F_62 ( V_113 ) ;
F_48 ( V_84 ) ;
F_58 ( V_113 , V_84 -> V_5 ) ;
F_59 ( V_113 ) ;
F_60 ( V_113 ) ;
}
