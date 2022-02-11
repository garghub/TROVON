static inline void
F_1 ( struct V_1 T_1 * V_2 , int F_1 , unsigned V_3 )
{
F_2 ( F_3 ( V_3 ) | F_1 , & V_2 -> V_4 ) ;
F_4 ( 300 ) ;
}
static int
F_5 ( struct V_5 * V_6 , const struct V_7 * V_8 )
{
struct V_9 * V_10 ;
struct V_11 * V_12 ;
T_2 V_13 ;
T_3 V_14 ;
unsigned long V_15 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( ! V_6 || ! V_8 || V_12 -> V_8
|| V_8 -> V_16 != V_17 )
return - V_18 ;
V_10 = V_12 -> V_10 ;
if ( V_12 == & V_10 -> V_12 [ 0 ] )
return - V_18 ;
if ( ! V_10 -> V_19 || V_10 -> V_20 . V_21 == V_22 )
return - V_23 ;
if ( V_12 -> V_24 != F_7 ( V_8 ) )
return - V_18 ;
switch ( F_8 ( V_8 ) ) {
case V_25 :
case V_26 :
break;
default:
return - V_18 ;
}
if ( ( F_9 ( V_12 -> V_27 ) & V_28 )
!= V_29 )
return - V_30 ;
V_13 = 0 ;
V_14 = F_10 ( & V_8 -> V_31 ) ;
switch ( V_14 ) {
case 64 : V_13 ++ ;
case 32 : V_13 ++ ;
case 16 : V_13 ++ ;
case 8 : V_13 <<= 3 ;
break;
default:
return - V_18 ;
}
V_13 |= 2 << 1 ;
V_12 -> V_32 = F_11 ( V_8 ) ;
if ( V_12 -> V_32 ) {
V_13 |= 1 ;
V_12 -> V_33 = ( V_34 != 0 ) && ( V_12 -> V_24 == V_35 ) ;
} else {
V_12 -> V_33 = ( V_34 == 2 ) && ( V_12 -> V_24 == V_36 ) ;
if ( V_12 -> V_33 )
F_12 ( V_10 , L_1 ,
V_12 -> V_12 . V_37 ) ;
}
F_13 ( & V_12 -> V_10 -> V_38 , V_15 ) ;
if ( V_12 -> V_24 < 3 ) {
struct V_1 T_1 * V_2 = V_12 -> V_10 -> V_2 ;
T_2 V_39 ;
V_39 = ( ( V_12 -> V_33 || ! V_12 -> V_32 )
? 0x10
: 0x11
) << V_12 -> V_24 ;
V_39 |= F_9 ( & V_2 -> V_40 ) ;
F_2 ( V_39 , & V_2 -> V_40 ) ;
V_39 = ( V_12 -> V_33 ? 0x10 : 0x11 ) << V_12 -> V_24 ;
V_39 |= F_9 ( & V_2 -> V_41 ) ;
F_2 ( V_39 , & V_2 -> V_41 ) ;
}
F_2 ( V_13 , V_12 -> V_42 ) ;
F_1 ( V_12 -> V_10 -> V_2 , V_43 , V_12 -> V_24 ) ;
V_12 -> V_12 . V_44 = V_14 ;
V_12 -> V_45 = 0 ;
V_12 -> V_8 = V_8 ;
F_14 ( & V_12 -> V_10 -> V_38 , V_15 ) ;
F_12 ( V_10 , L_2 , V_12 -> V_12 . V_37 ,
V_12 -> V_32 ? L_3 : L_4 ,
V_12 -> V_33 ? L_5 : L_6 ,
V_14 ) ;
return 0 ;
}
static void F_15 ( struct V_1 T_1 * V_2 , struct V_11 * V_12 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
if ( V_2 ) {
F_1 ( V_2 , V_46 , V_12 -> V_24 ) ;
if ( V_12 -> V_24 ) {
if ( V_12 -> V_24 == V_36 )
V_10 -> V_47 &= ~ ( V_48
| V_49 ) ;
else if ( V_12 -> V_24 == V_35 )
V_10 -> V_47 &= ~ V_50 ;
V_10 -> V_47 &= ~ F_16 ( V_12 -> V_24 ) ;
} else
V_10 -> V_47 &= ~ V_51 ;
F_2 ( V_10 -> V_47 , & V_2 -> V_47 ) ;
F_9 ( & V_2 -> V_47 ) ;
if ( V_12 -> V_24 < 3 ) {
struct V_1 T_1 * V_52 = V_12 -> V_10 -> V_2 ;
T_2 V_39 ;
V_39 = F_9 ( & V_52 -> V_40 ) ;
V_39 &= ~ ( 0x11 << V_12 -> V_24 ) ;
F_2 ( V_39 , & V_52 -> V_40 ) ;
V_39 = F_9 ( & V_52 -> V_41 ) ;
V_39 &= ~ ( 0x11 << V_12 -> V_24 ) ;
F_2 ( V_39 , & V_52 -> V_41 ) ;
}
if ( V_12 -> V_33 ) {
T_2 V_53 ;
V_53 = F_9 ( & V_2 -> V_54 ) & V_55 ;
if ( V_12 -> V_24 == V_36 ) {
V_53 &= ~ V_56 ;
V_53 |= V_57 ;
} else {
V_53 &= ~ V_58 ;
V_53 |= V_59 ;
}
F_2 ( V_53 , & V_2 -> V_54 ) ;
}
}
V_12 -> V_12 . V_44 = V_60 ;
V_12 -> V_8 = NULL ;
V_12 -> V_45 = 1 ;
V_12 -> V_61 = 0 ;
V_12 -> V_33 = 0 ;
}
static int F_17 ( struct V_5 * V_6 )
{
struct V_11 * V_12 ;
struct V_9 * V_10 ;
unsigned long V_15 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( ! V_6 || ! V_12 -> V_8 )
return - V_62 ;
V_10 = V_12 -> V_10 ;
if ( V_10 -> V_63 == V_64 )
return - V_30 ;
F_18 ( V_10 , L_7 , V_6 -> V_37 ) ;
F_13 ( & V_10 -> V_38 , V_15 ) ;
F_19 ( V_12 , - V_23 ) ;
F_15 ( V_10 -> V_2 , V_12 ) ;
F_14 ( & V_10 -> V_38 , V_15 ) ;
return 0 ;
}
static struct V_65 *
F_20 ( struct V_5 * V_6 , T_4 V_66 )
{
struct V_67 * V_68 ;
if ( ! V_6 )
return NULL ;
V_68 = F_21 ( sizeof *V_68 , V_66 ) ;
if ( ! V_68 )
return NULL ;
V_68 -> V_68 . V_33 = V_69 ;
F_22 ( & V_68 -> V_70 ) ;
return & V_68 -> V_68 ;
}
static void
F_23 ( struct V_5 * V_6 , struct V_65 * V_71 )
{
struct V_67 * V_68 ;
if ( ! V_6 || ! V_71 )
return;
V_68 = F_6 ( V_71 , struct V_67 , V_68 ) ;
F_24 ( ! F_25 ( & V_68 -> V_70 ) ) ;
F_26 ( V_68 ) ;
}
static void
F_27 ( struct V_11 * V_12 , struct V_67 * V_68 , int V_72 )
{
struct V_9 * V_10 ;
unsigned V_45 = V_12 -> V_45 ;
F_28 ( & V_68 -> V_70 ) ;
if ( F_29 ( V_68 -> V_68 . V_72 == - V_73 ) )
V_68 -> V_68 . V_72 = V_72 ;
else
V_72 = V_68 -> V_68 . V_72 ;
V_10 = V_12 -> V_10 ;
if ( V_68 -> V_74 ) {
F_30 ( V_10 -> V_75 , V_68 -> V_68 . V_33 , V_68 -> V_68 . V_76 ,
V_12 -> V_32 ? V_77 : V_78 ) ;
V_68 -> V_68 . V_33 = V_69 ;
V_68 -> V_74 = 0 ;
}
#ifndef F_31
if ( V_72 && V_72 != - V_23 )
#endif
F_18 ( V_10 , L_8 ,
V_12 -> V_12 . V_37 , & V_68 -> V_68 , V_72 ,
V_68 -> V_68 . V_79 , V_68 -> V_68 . V_76 ) ;
V_12 -> V_45 = 1 ;
F_32 ( & V_10 -> V_38 ) ;
V_68 -> V_68 . V_80 ( & V_12 -> V_12 , & V_68 -> V_68 ) ;
F_33 ( & V_10 -> V_38 ) ;
V_12 -> V_45 = V_45 ;
}
static inline int
F_34 ( T_2 T_1 * V_81 , T_5 * V_82 , struct V_67 * V_68 , unsigned V_14 )
{
unsigned V_76 , V_83 ;
V_76 = F_35 ( V_68 -> V_68 . V_76 - V_68 -> V_68 . V_79 , V_14 ) ;
V_68 -> V_68 . V_79 += V_76 ;
V_83 = V_76 ;
while ( F_29 ( V_83 -- ) )
F_2 ( * V_82 ++ , V_81 ) ;
return V_76 ;
}
static int F_36 ( struct V_11 * V_12 , struct V_67 * V_68 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_2 V_39 ;
T_5 * V_82 ;
unsigned V_83 ;
int V_84 ;
V_39 = F_9 ( & V_10 -> V_2 -> V_85 ) ;
V_82 = V_68 -> V_68 . V_82 + V_68 -> V_68 . V_79 ;
F_37 ( V_82 ) ;
V_10 = V_12 -> V_10 ;
if ( F_38 ( V_12 -> V_24 == 0 && V_10 -> V_63 != V_86 ) )
return - V_87 ;
if ( F_38 ( ( V_39 & F_39 ( V_12 -> V_24 ) ) != 0 ) )
return 0 ;
if ( V_12 -> V_24 != 0 )
F_2 ( ~ F_16 ( V_12 -> V_24 ) , & V_10 -> V_2 -> V_88 ) ;
V_83 = F_34 ( V_12 -> V_89 , V_82 , V_68 , V_12 -> V_12 . V_44 ) ;
if ( F_38 ( V_83 != V_12 -> V_12 . V_44 ) ) {
F_2 ( ~ ( 1 << V_12 -> V_24 ) , & V_10 -> V_2 -> V_90 ) ;
if ( V_12 -> V_24 == 0 ) {
V_10 -> V_12 [ 0 ] . V_45 = 1 ;
V_10 -> V_63 = V_91 ;
}
V_84 = 1 ;
} else {
if ( F_29 ( V_68 -> V_68 . V_76 != V_68 -> V_68 . V_79 )
|| V_68 -> V_68 . V_92 )
V_84 = 0 ;
else
V_84 = 1 ;
}
#if 0
VDBG(dev, "wrote %s %u bytes%s IN %u left %p\n",
ep->ep.name, count, is_last ? "/last" : "",
req->req.length - req->req.actual, req);
#endif
if ( V_84 ) {
F_27 ( V_12 , V_68 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_40 ( struct V_11 * V_12 , struct V_67 * V_68 )
{
struct V_1 T_1 * V_2 ;
T_2 V_93 , V_94 ;
T_5 * V_82 ;
unsigned V_95 , V_96 , V_97 ;
V_2 = V_12 -> V_10 -> V_2 ;
V_98:
V_82 = V_68 -> V_68 . V_82 + V_68 -> V_68 . V_79 ;
F_41 ( V_82 ) ;
if ( F_38 ( V_12 -> V_24 == 0 && V_12 -> V_10 -> V_63 != V_99 ) )
return - V_87 ;
V_97 = ( V_12 -> V_24 == 1 || V_12 -> V_24 == 2 ) ;
do {
if ( V_12 -> V_24 != 0 )
F_2 ( ~ F_16 ( V_12 -> V_24 ) , & V_2 -> V_88 ) ;
V_94 = F_9 ( & V_2 -> V_85 ) & F_42 ( V_12 -> V_24 ) ;
V_93 = F_9 ( & V_2 -> V_100 [ V_12 -> V_24 ] ) ;
V_95 = V_68 -> V_68 . V_76 - V_68 -> V_68 . V_79 ;
if ( F_29 ( V_12 -> V_24 != 0 || V_95 != 0 ) ) {
if ( F_38 ( V_94 == 0 ) )
break;
if ( ! ( V_93 & V_101 ) )
V_93 = F_9 ( & V_2 -> V_102 [ V_12 -> V_24 ] ) ;
if ( ! ( V_93 & V_101 ) )
break;
V_93 &= V_103 ;
} else
V_93 = 0 ;
V_68 -> V_68 . V_79 += V_93 ;
V_96 = ( V_93 < V_12 -> V_12 . V_44 ) ;
#ifdef F_31
F_18 ( V_12 -> V_10 , L_9 ,
V_12 -> V_12 . V_37 , V_93 , V_96 ? L_10 : L_11 ,
V_68 , V_68 -> V_68 . V_79 , V_68 -> V_68 . V_76 ) ;
#endif
while ( F_29 ( V_93 -- != 0 ) ) {
T_5 V_104 = ( T_5 ) F_9 ( V_12 -> V_89 ) ;
if ( F_38 ( V_95 == 0 ) ) {
if ( V_68 -> V_68 . V_72 != - V_105 )
F_12 ( V_12 -> V_10 , L_12 ,
V_12 -> V_12 . V_37 , V_93 ) ;
V_68 -> V_68 . V_72 = - V_105 ;
} else {
* V_82 ++ = V_104 ;
V_95 -- ;
}
}
if ( F_38 ( V_96 || V_68 -> V_68 . V_79 == V_68 -> V_68 . V_76 ) ) {
if ( F_38 ( V_12 -> V_24 == 0 ) ) {
if ( V_12 -> V_10 -> V_106 )
F_2 ( V_12 -> V_10 -> V_107
? V_108
: 0 ,
& V_2 -> V_109 ) ;
F_2 ( ~ ( 1 << 0 ) , & V_2 -> V_90 ) ;
V_12 -> V_45 = 1 ;
V_12 -> V_10 -> V_63 = V_91 ;
}
F_27 ( V_12 , V_68 , 0 ) ;
if ( V_97 && ! F_25 ( & V_12 -> V_70 ) ) {
V_68 = F_43 ( V_12 -> V_70 . V_110 ,
struct V_67 , V_70 ) ;
goto V_98;
}
return 1 ;
}
} while ( V_97 );
return 0 ;
}
static inline void
F_44 ( struct V_9 * V_10 ,
struct V_1 T_1 * V_2 , int V_3 )
{
V_10 -> V_47 |= F_16 ( V_3 ) ;
F_2 ( V_10 -> V_47 , & V_2 -> V_47 ) ;
}
static inline void
F_45 ( struct V_9 * V_10 ,
struct V_1 T_1 * V_2 , int V_3 )
{
V_10 -> V_47 &= ~ F_16 ( V_3 ) ;
F_2 ( V_10 -> V_47 , & V_2 -> V_47 ) ;
}
static inline void
F_46 ( struct V_11 * V_12 )
{
struct V_67 * V_68 ;
if ( F_38 ( F_25 ( & V_12 -> V_70 ) ) )
return;
V_68 = F_43 ( V_12 -> V_70 . V_110 , struct V_67 , V_70 ) ;
( V_12 -> V_32 ? F_36 : F_40 ) ( V_12 , V_68 ) ;
}
static int F_47 ( struct V_11 * V_12 , struct V_67 * V_68 )
{
struct V_1 T_1 * V_2 = V_12 -> V_10 -> V_2 ;
T_2 V_53 ;
T_2 V_111 = V_68 -> V_68 . V_33 ;
T_2 V_112 = V_111 + V_68 -> V_68 . V_76 - 1 ;
V_53 = F_9 ( & V_2 -> V_54 ) & V_55 ;
if ( F_29 ( V_12 -> V_32 ) ) {
if ( F_38 ( V_53 & V_113 ) ) {
F_12 ( V_12 -> V_10 , L_13 ,
V_53 ) ;
}
F_2 ( V_112 , & V_2 -> V_114 ) ;
F_2 ( V_111 , & V_2 -> V_115 ) ;
V_53 &= ~ V_58 ;
if ( F_38 ( V_68 -> V_68 . V_76 == 0 ) )
V_53 = V_113 | V_116 ;
else if ( ( V_68 -> V_68 . V_76 % V_12 -> V_12 . V_44 ) != 0
|| V_68 -> V_68 . V_92 )
V_53 = V_113 | V_117 ;
else
V_53 = V_113 | V_118 ;
V_12 -> V_10 -> V_47 |= V_50 ;
} else {
if ( F_38 ( V_53 & V_119 ) ) {
F_12 ( V_12 -> V_10 , L_14 ,
V_53 ) ;
}
F_2 ( V_112 , & V_2 -> V_120 ) ;
F_2 ( V_111 , & V_2 -> V_121 ) ;
V_53 &= ~ V_56 ;
V_53 |= V_119 | V_122 ;
V_12 -> V_10 -> V_47 |= V_48 | V_49 ;
}
F_2 ( V_53 , & V_2 -> V_54 ) ;
F_2 ( V_12 -> V_10 -> V_47 , & V_2 -> V_47 ) ;
return 0 ;
}
static void F_48 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_67 * V_68 ;
struct V_1 T_1 * V_2 = V_12 -> V_10 -> V_2 ;
T_2 V_53 ;
V_53 = F_9 ( & V_2 -> V_54 ) ;
if ( F_38 ( F_25 ( & V_12 -> V_70 ) ) ) {
V_123:
if ( V_12 -> V_32 )
V_10 -> V_47 &= ~ V_50 ;
else
V_10 -> V_47 &= ~ ( V_48 | V_49 ) ;
F_2 ( V_10 -> V_47 , & V_2 -> V_47 ) ;
return;
}
V_68 = F_43 ( V_12 -> V_70 . V_110 , struct V_67 , V_70 ) ;
if ( F_29 ( V_12 -> V_32 ) ) {
if ( F_38 ( V_53 & V_113 ) )
return;
V_68 -> V_68 . V_79 = F_9 ( & V_2 -> V_124 ) ;
} else {
if ( F_38 ( V_53 & V_119 ) )
return;
V_68 -> V_68 . V_79 = F_9 ( & V_2 -> V_125 ) ;
}
V_68 -> V_68 . V_79 -= V_68 -> V_68 . V_33 ;
V_68 -> V_68 . V_79 ++ ;
#ifdef F_31
F_18 ( V_10 , L_15 ,
V_12 -> V_12 . V_37 , V_12 -> V_32 ? L_3 : L_4 ,
V_68 -> V_68 . V_79 , V_68 -> V_68 . V_76 , V_68 ) ;
#endif
F_27 ( V_12 , V_68 , 0 ) ;
if ( F_25 ( & V_12 -> V_70 ) )
goto V_123;
V_68 = F_43 ( V_12 -> V_70 . V_110 , struct V_67 , V_70 ) ;
( void ) F_47 ( V_12 , V_68 ) ;
}
static void F_49 ( struct V_11 * V_12 , int V_72 )
{
struct V_1 T_1 * V_2 = V_12 -> V_10 -> V_2 ;
struct V_67 * V_68 ;
T_2 V_126 , V_53 ;
F_1 ( V_2 , V_127 , V_12 -> V_24 ) ;
V_68 = F_43 ( V_12 -> V_70 . V_110 , struct V_67 , V_70 ) ;
V_53 = F_9 ( & V_2 -> V_54 ) & V_55 ;
if ( V_12 -> V_32 ) {
if ( F_38 ( ( F_9 ( & V_2 -> V_54 ) & V_113 ) == 0 ) )
goto V_128;
V_126 = F_9 ( & V_2 -> V_124 ) ;
F_2 ( V_126 , & V_2 -> V_114 ) ;
F_2 ( V_126 , & V_2 -> V_115 ) ;
V_53 &= ~ V_58 ;
V_53 |= V_59 ;
F_2 ( V_53 , & V_2 -> V_54 ) ;
if ( F_9 ( & V_2 -> V_54 ) & V_113 )
F_12 ( V_12 -> V_10 , L_16 ) ;
} else {
if ( F_38 ( ( F_9 ( & V_2 -> V_54 ) & V_119 ) == 0 ) )
goto V_128;
V_126 = F_9 ( & V_2 -> V_125 ) ;
F_2 ( V_126 , & V_2 -> V_120 ) ;
F_2 ( V_126 , & V_2 -> V_121 ) ;
V_53 &= ~ V_56 ;
V_53 |= V_57 ;
F_2 ( V_53 , & V_2 -> V_54 ) ;
if ( F_9 ( & V_2 -> V_54 ) & V_119 )
F_12 ( V_12 -> V_10 , L_17 ) ;
}
V_68 -> V_68 . V_79 = ( V_126 - V_68 -> V_68 . V_33 ) + 1 ;
V_68 -> V_68 . V_72 = V_72 ;
F_18 ( V_12 -> V_10 , L_18 , V_129 , V_12 -> V_12 . V_37 ,
V_12 -> V_32 ? L_3 : L_4 ,
V_68 -> V_68 . V_79 , V_68 -> V_68 . V_76 ) ;
F_1 ( V_2 , V_130 , V_12 -> V_24 ) ;
return;
V_128:
F_1 ( V_2 , V_130 , V_12 -> V_24 ) ;
V_68 -> V_68 . V_79 = V_68 -> V_68 . V_76 ;
V_68 -> V_68 . V_72 = 0 ;
}
static int
F_50 ( struct V_5 * V_6 , struct V_65 * V_71 , T_4 V_66 )
{
struct V_67 * V_68 ;
struct V_11 * V_12 ;
struct V_9 * V_10 ;
unsigned long V_15 ;
int V_72 ;
V_68 = F_6 ( V_71 , struct V_67 , V_68 ) ;
if ( F_38 ( ! V_71 || ! V_71 -> V_80
|| ! V_71 -> V_82 || ! F_25 ( & V_68 -> V_70 ) ) )
return - V_18 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( F_38 ( ! V_6 || ( ! V_12 -> V_8 && V_12 -> V_24 != 0 ) ) )
return - V_18 ;
V_10 = V_12 -> V_10 ;
if ( F_38 ( ! V_10 -> V_19 || V_10 -> V_20 . V_21 == V_22 ) )
return - V_23 ;
if ( V_10 -> V_63 == V_64 )
return - V_30 ;
if ( V_12 -> V_33 && V_71 -> V_33 == V_69 ) {
V_71 -> V_33 = F_51 ( V_10 -> V_75 , V_71 -> V_82 , V_71 -> V_76 ,
V_12 -> V_32 ? V_77 : V_78 ) ;
V_68 -> V_74 = 1 ;
}
#ifdef F_31
F_18 ( V_10 , L_19 ,
V_6 -> V_37 , V_71 , V_71 -> V_76 , V_71 -> V_82 ) ;
#endif
F_13 ( & V_10 -> V_38 , V_15 ) ;
V_71 -> V_72 = - V_73 ;
V_71 -> V_79 = 0 ;
if ( F_38 ( V_12 -> V_24 == 0 && V_12 -> V_32 ) )
V_71 -> V_92 = 1 ;
V_72 = 0 ;
if ( F_25 ( & V_12 -> V_70 ) && F_29 ( ! V_12 -> V_45 ) ) {
if ( V_12 -> V_33 )
V_72 = F_47 ( V_12 , V_68 ) ;
else
V_72 = ( V_12 -> V_32 ? F_36 : F_40 ) ( V_12 , V_68 ) ;
if ( F_38 ( V_72 != 0 ) ) {
if ( V_72 > 0 )
V_72 = 0 ;
V_68 = NULL ;
}
}
if ( F_29 ( V_68 != 0 ) )
F_52 ( & V_68 -> V_70 , & V_12 -> V_70 ) ;
if ( F_29 ( ! F_25 ( & V_12 -> V_70 ) )
&& F_29 ( V_12 -> V_24 != 0 )
&& ! V_12 -> V_33
&& ! ( V_10 -> V_47 & F_16 ( V_12 -> V_24 ) ) )
F_44 ( V_10 , V_10 -> V_2 , V_12 -> V_24 ) ;
F_14 ( & V_10 -> V_38 , V_15 ) ;
return V_72 ;
}
static void F_19 ( struct V_11 * V_12 , int V_72 )
{
struct V_67 * V_68 ;
V_12 -> V_45 = 1 ;
if ( F_25 ( & V_12 -> V_70 ) )
return;
if ( V_12 -> V_33 )
F_49 ( V_12 , V_72 ) ;
while ( ! F_25 ( & V_12 -> V_70 ) ) {
V_68 = F_43 ( V_12 -> V_70 . V_110 , struct V_67 , V_70 ) ;
F_27 ( V_12 , V_68 , V_72 ) ;
}
}
static int F_53 ( struct V_5 * V_6 , struct V_65 * V_71 )
{
struct V_67 * V_68 ;
struct V_11 * V_12 ;
struct V_9 * V_10 ;
unsigned long V_15 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( ! V_6 || ! V_71 || ( ! V_12 -> V_8 && V_12 -> V_24 != 0 ) )
return - V_18 ;
V_10 = V_12 -> V_10 ;
if ( ! V_10 -> V_19 )
return - V_23 ;
if ( V_10 -> V_63 == V_64 )
return - V_30 ;
F_18 ( V_10 , L_20 , V_129 , V_6 -> V_37 ,
V_12 -> V_32 ? L_3 : L_4 ,
V_12 -> V_33 ? L_5 : L_6 ,
V_71 ) ;
F_13 ( & V_10 -> V_38 , V_15 ) ;
F_54 (req, &ep->queue, queue) {
if ( & V_68 -> V_68 == V_71 )
break;
}
if ( & V_68 -> V_68 != V_71 ) {
F_14 ( & V_10 -> V_38 , V_15 ) ;
return - V_18 ;
}
if ( V_12 -> V_33 && V_12 -> V_70 . V_110 == & V_68 -> V_70 && ! V_12 -> V_45 ) {
F_49 ( V_12 , - V_131 ) ;
F_27 ( V_12 , V_68 , - V_131 ) ;
F_48 ( V_10 , V_12 ) ;
} else if ( ! F_25 ( & V_68 -> V_70 ) )
F_27 ( V_12 , V_68 , - V_131 ) ;
else
V_68 = NULL ;
F_14 ( & V_10 -> V_38 , V_15 ) ;
return V_68 ? 0 : - V_132 ;
}
static void F_55 ( struct V_11 * V_12 )
{
F_18 ( V_12 -> V_10 , L_21 , V_12 -> V_12 . V_37 ) ;
F_1 ( V_12 -> V_10 -> V_2 , V_133 , V_12 -> V_24 ) ;
F_1 ( V_12 -> V_10 -> V_2 , V_134 , V_12 -> V_24 ) ;
if ( V_12 -> V_45 ) {
V_12 -> V_45 = 0 ;
if ( V_12 -> V_33 ) {
struct V_67 * V_68 ;
if ( F_25 ( & V_12 -> V_70 ) )
return;
V_68 = F_43 ( V_12 -> V_70 . V_110 , struct V_67 ,
V_70 ) ;
( void ) F_47 ( V_12 , V_68 ) ;
} else
F_46 ( V_12 ) ;
}
}
static int F_56 ( struct V_5 * V_6 , int V_135 )
{
struct V_11 * V_12 ;
unsigned long V_15 ;
int V_136 = 0 ;
if ( ! V_6 )
return - V_62 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( V_12 -> V_24 == 0 ) {
if ( V_135 ) {
V_12 -> V_10 -> V_63 = V_137 ;
V_12 -> V_10 -> V_12 [ 0 ] . V_45 = 1 ;
} else
return - V_18 ;
} else if ( ! V_12 -> V_8 ) {
F_12 ( V_12 -> V_10 , L_22 , V_129 , V_12 -> V_12 . V_37 ) ;
return - V_18 ;
}
F_13 ( & V_12 -> V_10 -> V_38 , V_15 ) ;
if ( ! F_25 ( & V_12 -> V_70 ) )
V_136 = - V_138 ;
else if ( V_12 -> V_32 && V_135
&& ( F_9 ( & V_12 -> V_10 -> V_2 -> V_85 )
& F_42 ( V_12 -> V_24 ) ) )
V_136 = - V_138 ;
else if ( ! V_135 )
F_55 ( V_12 ) ;
else {
V_12 -> V_45 = 1 ;
F_18 ( V_12 -> V_10 , L_23 , V_12 -> V_12 . V_37 ) ;
F_1 ( V_12 -> V_10 -> V_2 , V_139 , V_12 -> V_24 ) ;
F_9 ( V_12 -> V_27 ) ;
}
F_14 ( & V_12 -> V_10 -> V_38 , V_15 ) ;
return V_136 ;
}
static int F_57 ( struct V_5 * V_6 )
{
struct V_11 * V_12 ;
struct V_1 T_1 * V_2 ;
T_2 V_93 ;
if ( ! V_6 )
return - V_62 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( V_12 -> V_32 )
return - V_132 ;
V_2 = V_12 -> V_10 -> V_2 ;
V_93 = F_9 ( & V_2 -> V_100 [ V_12 -> V_24 ] ) & V_103 ;
V_93 += F_9 ( & V_2 -> V_102 [ V_12 -> V_24 ] ) & V_103 ;
F_18 ( V_12 -> V_10 , L_24 , V_129 , V_12 -> V_12 . V_37 , V_93 ) ;
return V_93 ;
}
static void F_58 ( struct V_5 * V_6 )
{
struct V_11 * V_12 ;
struct V_1 T_1 * V_2 ;
T_2 V_93 ;
if ( ! V_6 )
return;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
F_18 ( V_12 -> V_10 , L_25 , V_129 , V_12 -> V_12 . V_37 ) ;
if ( ! V_12 -> V_8 && V_12 -> V_24 != 0 ) {
F_12 ( V_12 -> V_10 , L_22 , V_129 , V_12 -> V_12 . V_37 ) ;
return;
}
V_2 = V_12 -> V_10 -> V_2 ;
V_93 = F_9 ( & V_2 -> V_100 [ V_12 -> V_24 ] ) ;
V_93 &= V_103 ;
if ( V_93 )
F_1 ( V_2 , V_140 , V_12 -> V_24 ) ;
}
static int F_59 ( struct V_141 * V_142 )
{
return - V_132 ;
}
static inline char * F_60 ( void )
{
if ( V_34 == 0 )
return L_26 ;
else if ( V_34 == 2 )
return L_27 ;
else
return L_28 ;
}
static void
F_61 ( const char * V_143 , T_2 V_144 , char * * V_110 , unsigned * V_93 )
{
int V_145 ;
V_145 = F_62 (*next, *size,
L_29 FOURBITS EIGHTBITS EIGHTBITS L_30 ,
label, mask,
(mask & INT_PWRDETECT) ? L_31 : L_11 ,
(mask & INT_SYSERROR) ? L_32 : L_11 ,
(mask & INT_MSTRDEND) ? L_33 : L_11 ,
(mask & INT_MSTWRTMOUT) ? L_34 : L_11 ,
(mask & INT_MSTWREND) ? L_35 : L_11 ,
(mask & INT_MSTWRSET) ? L_36 : L_11 ,
(mask & INT_ERR) ? L_37 : L_11 ,
(mask & INT_SOF) ? L_38 : L_11 ,
(mask & INT_EP3NAK) ? L_39 : L_11 ,
(mask & INT_EP2NAK) ? L_40 : L_11 ,
(mask & INT_EP1NAK) ? L_41 : L_11 ,
(mask & INT_EP3DATASET) ? L_42 : L_11 ,
(mask & INT_EP2DATASET) ? L_43 : L_11 ,
(mask & INT_EP1DATASET) ? L_44 : L_11 ,
(mask & INT_STATUSNAK) ? L_45 : L_11 ,
(mask & INT_STATUS) ? L_46 : L_11 ,
(mask & INT_SETUP) ? L_47 : L_11 ,
(mask & INT_ENDPOINT0) ? L_48 : L_11 ,
(mask & INT_USBRESET) ? L_49 : L_11 ,
(mask & INT_SUSPEND) ? L_50 : L_11 ) ;
* V_93 -= V_145 ;
* V_110 += V_145 ;
}
static int
F_63 ( char * V_146 , char * * V_111 , T_6 V_147 , int V_83 ,
int * V_148 , void * V_149 )
{
char * V_82 = V_146 ;
struct V_9 * V_10 = V_149 ;
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
char * V_110 = V_82 ;
unsigned V_93 = V_83 ;
unsigned long V_15 ;
int V_150 , V_145 , V_151 ;
T_2 V_39 ;
if ( V_147 != 0 )
return 0 ;
F_64 ( V_15 ) ;
V_39 = F_9 ( & V_2 -> V_152 ) ;
V_151 = V_39 & V_153 ;
V_145 = F_62 (next, size,
L_51
L_52
L_53
L_54
L_30 ,
pci_name(dev->pdev), driver_desc,
driver_name, DRIVER_VERSION, dmastr(),
dev->driver ? dev->driver->driver.name : L_55 ,
is_usb_connected
? ((tmp & PW_PULLUP) ? L_56 : L_57)
: L_58 ,
({char *state;
switch(dev->ep0state){
case EP0_DISCONNECT: state = L_59; break;
case EP0_IDLE: state = L_60; break;
case EP0_IN: state = L_61; break;
case EP0_OUT: state = L_62; break;
case EP0_STATUS: state = L_63; break;
case EP0_STALL: state = L_64; break;
case EP0_SUSPEND: state = L_65; break;
default: state = L_66; break;
} state; })
) ;
V_93 -= V_145 ;
V_110 += V_145 ;
F_61 ( L_67 , F_9 ( & V_2 -> V_88 ) , & V_110 , & V_93 ) ;
F_61 ( L_68 , F_9 ( & V_2 -> V_47 ) , & V_110 , & V_93 ) ;
if ( ! V_151 || ! V_10 -> V_19 || ( V_39 & V_154 ) == 0 )
goto F_27;
V_145 = F_62 ( V_110 , V_93 , L_69
L_70 ,
V_10 -> V_61 , F_9 ( & V_2 -> V_85 ) ,
F_9 ( & V_2 -> V_40 ) , F_9 ( & V_2 -> V_41 ) ,
F_9 ( & V_2 -> V_109 ) ,
F_9 ( & V_2 -> V_155 ) ) ;
V_93 -= V_145 ;
V_110 += V_145 ;
V_39 = F_9 ( & V_2 -> V_54 ) ;
V_145 = F_62 ( V_110 , V_93 ,
L_71 V_156 L_25 , V_39 ,
( V_39 & V_118 ) ? L_72 : L_11 ,
( V_39 & V_117 ) ? L_73 : L_11 ,
( V_39 & V_122 ) ? L_74 : L_11 ,
( V_39 & V_157 ) ? L_75 : L_11 ,
( V_39 & V_116 ) ? L_76 : L_11 ,
( V_39 & V_59 ) ? L_77 : L_11 ,
( V_39 & V_57 ) ? L_78 : L_11 ,
( V_39 & V_113 ) ? L_79 : L_11 ,
( V_39 & V_119 ) ? L_80 : L_11 ,
( V_39 & V_158 )
? L_81
: L_82 ) ;
V_93 -= V_145 ;
V_110 += V_145 ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
struct V_11 * V_12 = & V_10 -> V_12 [ V_150 ] ;
struct V_67 * V_68 ;
if ( V_150 && ! V_12 -> V_8 )
continue;
V_39 = F_9 ( V_12 -> V_27 ) ;
V_145 = F_62 (next, size,
L_83
L_84 FOURBITS L_30 ,
ep->ep.name,
ep->is_in ? L_85 : L_86 ,
ep->ep.maxpacket,
ep->dma ? L_5 : L_6 ,
ep->irqs,
tmp, ({ char *s;
switch (tmp & EPxSTATUS_EP_MASK) {
case EPxSTATUS_EP_READY:
s = L_87; break;
case EPxSTATUS_EP_DATAIN:
s = L_88; break;
case EPxSTATUS_EP_FULL:
s = L_89; break;
case EPxSTATUS_EP_TX_ERR:
s = L_90; break;
case EPxSTATUS_EP_RX_ERR:
s = L_91; break;
case EPxSTATUS_EP_BUSY:
s = L_92; break;
case EPxSTATUS_EP_STALL:
s = L_93; break;
case EPxSTATUS_EP_INVALID:
s = L_94; break;
default:
s = L_95; break;
}; s; }),
(tmp & EPxSTATUS_TOGGLE) ? L_96 : L_97 ,
(tmp & EPxSTATUS_SUSPEND) ? L_50 : L_11 ,
(tmp & EPxSTATUS_FIFO_DISABLE) ? L_98 : L_11 ,
(tmp & EPxSTATUS_STAGE_ERROR) ? L_99 : L_11
) ;
if ( V_145 <= 0 || V_145 > V_93 )
goto F_27;
V_93 -= V_145 ;
V_110 += V_145 ;
if ( F_25 ( & V_12 -> V_70 ) ) {
V_145 = F_62 ( V_110 , V_93 , L_100 ) ;
if ( V_145 <= 0 || V_145 > V_93 )
goto F_27;
V_93 -= V_145 ;
V_110 += V_145 ;
continue;
}
F_54 (req, &ep->queue, queue) {
if ( V_12 -> V_33 && V_68 -> V_70 . V_159 == & V_12 -> V_70 ) {
if ( V_150 == V_35 )
V_39 = F_9 ( & V_2 -> V_124 ) ;
else
V_39 = F_9 ( & V_2 -> V_125 ) ;
V_39 -= V_68 -> V_68 . V_33 ;
V_39 ++ ;
} else
V_39 = V_68 -> V_68 . V_79 ;
V_145 = F_62 ( V_110 , V_93 ,
L_101 ,
& V_68 -> V_68 , V_39 , V_68 -> V_68 . V_76 ,
V_68 -> V_68 . V_82 ) ;
if ( V_145 <= 0 || V_145 > V_93 )
goto F_27;
V_93 -= V_145 ;
V_110 += V_145 ;
}
}
F_27:
F_65 ( V_15 ) ;
* V_148 = 1 ;
return V_83 - V_93 ;
}
static void F_66 ( struct V_9 * V_10 )
{
static char * V_160 [] = { L_102 , L_103 , L_104 , L_105 } ;
unsigned V_150 ;
F_22 ( & V_10 -> V_20 . V_161 ) ;
V_10 -> V_20 . V_162 = & V_10 -> V_12 [ 0 ] . V_12 ;
V_10 -> V_20 . V_21 = V_22 ;
V_10 -> V_63 = V_163 ;
V_10 -> V_61 = 0 ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ ) {
struct V_11 * V_12 = & V_10 -> V_12 [ V_150 ] ;
V_12 -> V_24 = V_150 ;
V_12 -> V_12 . V_37 = V_160 [ V_150 ] ;
V_12 -> V_89 = & V_10 -> V_2 -> V_164 [ V_150 ] ;
V_12 -> V_27 = & V_10 -> V_2 -> V_165 [ V_150 ] ;
V_12 -> V_42 = & V_10 -> V_2 -> V_166 [ V_150 ] ;
V_12 -> V_12 . V_167 = & V_168 ;
F_52 ( & V_12 -> V_12 . V_161 , & V_10 -> V_20 . V_161 ) ;
V_12 -> V_10 = V_10 ;
F_22 ( & V_12 -> V_70 ) ;
F_15 ( NULL , V_12 ) ;
}
V_10 -> V_12 [ 0 ] . V_42 = NULL ;
V_10 -> V_12 [ 0 ] . V_12 . V_44 = V_169 ;
F_28 ( & V_10 -> V_12 [ 0 ] . V_12 . V_161 ) ;
}
static void F_67 ( struct V_9 * V_10 )
{
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
F_2 ( 0 , & V_2 -> V_152 ) ;
F_2 ( 0 , & V_2 -> V_47 ) ;
F_9 ( & V_2 -> V_47 ) ;
V_10 -> V_47 = 0 ;
F_4 ( 250 ) ;
F_2 ( V_170 , & V_2 -> V_152 ) ;
F_9 ( & V_2 -> V_47 ) ;
}
static void F_68 ( struct V_9 * V_10 )
{
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
unsigned V_150 ;
F_18 ( V_10 , L_106 , V_129 ) ;
F_67 ( V_10 ) ;
F_66 ( V_10 ) ;
F_2 ( V_171 | V_172
| V_173 | V_174
| V_175
| V_176
, & V_2 -> V_177 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ )
V_10 -> V_12 [ V_150 ] . V_61 = 0 ;
for ( V_150 = 0 ; V_150 < V_178 ; V_150 ++ )
F_2 ( 0 , & V_2 -> V_179 [ V_150 ] ) ;
F_2 ( 0 , & V_2 -> V_180 ) ;
F_2 ( V_170 | V_154 , & V_2 -> V_152 ) ;
V_10 -> V_47 = V_181 | V_51 ;
F_2 ( V_10 -> V_47 , & V_10 -> V_2 -> V_47 ) ;
F_9 ( & V_2 -> V_47 ) ;
V_10 -> V_20 . V_21 = V_182 ;
V_10 -> V_63 = V_183 ;
}
static void F_69 ( struct V_9 * V_10 )
{
if ( F_9 ( & V_10 -> V_2 -> V_152 ) & V_153 )
F_68 ( V_10 ) ;
else {
F_12 ( V_10 , L_106 , V_129 ) ;
V_10 -> V_47 = V_184 ;
F_2 ( V_10 -> V_47 , & V_10 -> V_2 -> V_47 ) ;
}
}
static int F_70 ( struct V_185 * V_19 ,
int (* F_71)( struct V_141 * ) )
{
struct V_9 * V_10 = V_186 ;
int V_136 ;
if ( ! V_19
|| V_19 -> V_21 < V_182
|| ! F_71
|| ! V_19 -> V_187
|| ! V_19 -> V_188 )
return - V_18 ;
if ( ! V_10 )
return - V_62 ;
if ( V_10 -> V_19 )
return - V_30 ;
V_19 -> V_19 . V_189 = NULL ;
V_10 -> V_19 = V_19 ;
V_10 -> V_20 . V_10 . V_19 = & V_19 -> V_19 ;
V_136 = F_71 ( & V_10 -> V_20 ) ;
if ( V_136 ) {
F_12 ( V_10 , L_107 ,
V_19 -> V_19 . V_37 , V_136 ) ;
V_10 -> V_19 = NULL ;
V_10 -> V_20 . V_10 . V_19 = NULL ;
return V_136 ;
}
F_69 ( V_10 ) ;
F_12 ( V_10 , L_108 , V_19 -> V_19 . V_37 ) ;
return 0 ;
}
static void
F_72 ( struct V_9 * V_10 , struct V_185 * V_19 )
{
unsigned V_150 ;
F_12 ( V_10 , L_106 , V_129 ) ;
if ( V_10 -> V_20 . V_21 == V_22 )
V_19 = NULL ;
F_67 ( V_10 ) ;
for ( V_150 = 0 ; V_150 < 4 ; V_150 ++ )
F_19 ( & V_10 -> V_12 [ V_150 ] , - V_23 ) ;
if ( V_19 ) {
F_32 ( & V_10 -> V_38 ) ;
V_19 -> V_187 ( & V_10 -> V_20 ) ;
F_33 ( & V_10 -> V_38 ) ;
}
if ( V_10 -> V_19 )
F_69 ( V_10 ) ;
}
static int F_73 ( struct V_185 * V_19 )
{
struct V_9 * V_10 = V_186 ;
unsigned long V_15 ;
if ( ! V_10 )
return - V_62 ;
if ( ! V_19 || V_19 != V_10 -> V_19 || ! V_19 -> V_190 )
return - V_18 ;
F_13 ( & V_10 -> V_38 , V_15 ) ;
V_10 -> V_19 = NULL ;
F_72 ( V_10 , V_19 ) ;
F_14 ( & V_10 -> V_38 , V_15 ) ;
V_19 -> V_190 ( & V_10 -> V_20 ) ;
V_10 -> V_20 . V_10 . V_19 = NULL ;
F_12 ( V_10 , L_109 , V_19 -> V_19 . V_37 ) ;
return 0 ;
}
static void F_74 ( struct V_9 * V_10 )
{
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
struct V_191 V_192 ;
int V_39 ;
V_192 . V_193 = F_9 ( & V_2 -> V_193 ) ;
V_192 . V_194 = F_9 ( & V_2 -> V_194 ) ;
V_192 . V_195 = F_75 ( ( F_9 ( & V_2 -> V_196 ) << 8 )
| F_9 ( & V_2 -> V_197 ) ) ;
V_192 . V_198 = F_75 ( ( F_9 ( & V_2 -> V_199 ) << 8 )
| F_9 ( & V_2 -> V_200 ) ) ;
V_192 . V_201 = F_75 ( ( F_9 ( & V_2 -> V_202 ) << 8 )
| F_9 ( & V_2 -> V_203 ) ) ;
F_2 ( 0 , & V_2 -> V_204 ) ;
F_19 ( & V_10 -> V_12 [ 0 ] , 0 ) ;
V_10 -> V_12 [ 0 ] . V_45 = 0 ;
if ( F_29 ( V_192 . V_193 & V_205 ) ) {
V_10 -> V_12 [ 0 ] . V_32 = 1 ;
V_10 -> V_63 = V_86 ;
F_2 ( V_206 , & V_10 -> V_2 -> V_207 ) ;
} else {
V_10 -> V_12 [ 0 ] . V_32 = 0 ;
V_10 -> V_63 = V_99 ;
switch ( V_192 . V_194 ) {
case V_208 :
switch ( V_192 . V_193 ) {
case V_209 :
V_39 = F_76 ( V_192 . V_198 ) & 0x0f ;
if ( V_39 > 3 || ( ! V_10 -> V_12 [ V_39 ] . V_8 && V_39 != 0 ) )
goto V_210;
if ( V_192 . V_198 & F_75 (
V_205 ) ) {
if ( ! V_10 -> V_12 [ V_39 ] . V_32 )
goto V_210;
} else {
if ( V_10 -> V_12 [ V_39 ] . V_32 )
goto V_210;
}
if ( V_192 . V_195 != F_75 (
V_211 ) )
goto V_210;
if ( V_39 )
F_55 ( & V_10 -> V_12 [ V_39 ] ) ;
V_212:
F_2 ( ~ ( 1 << 0 ) , & V_2 -> V_90 ) ;
V_10 -> V_12 [ 0 ] . V_45 = 1 ;
V_10 -> V_63 = V_91 ;
return;
case V_213 :
if ( V_192 . V_195 != F_75 ( 1 ) )
goto V_210;
F_18 ( V_10 , L_110 ) ;
goto V_212;
case V_214 :
goto V_210;
default:
break;
}
break;
default:
break;
}
}
#ifdef F_31
F_18 ( V_10 , L_111 ,
V_192 . V_193 , V_192 . V_194 ,
F_76 ( V_192 . V_195 ) , F_76 ( V_192 . V_198 ) ,
F_76 ( V_192 . V_201 ) ) ;
#endif
V_10 -> V_106 = ( V_192 . V_194 == V_215
&& V_192 . V_193 == V_213 ) ;
if ( F_38 ( V_10 -> V_106 ) )
V_10 -> V_107 = ( V_192 . V_195 != F_75 ( 0 ) ) ;
F_32 ( & V_10 -> V_38 ) ;
V_39 = V_10 -> V_19 -> V_188 ( & V_10 -> V_20 , & V_192 ) ;
F_33 ( & V_10 -> V_38 ) ;
if ( F_38 ( V_39 < 0 ) ) {
V_210:
#ifdef F_31
F_18 ( V_10 , L_112 ,
V_192 . V_193 , V_192 . V_194 , V_39 ) ;
#endif
F_1 ( V_2 , V_139 , 0 ) ;
V_10 -> V_12 [ 0 ] . V_45 = 1 ;
V_10 -> V_63 = V_137 ;
}
}
static T_7 F_77 ( int V_216 , void * V_149 )
{
struct V_9 * V_10 = V_149 ;
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
T_2 V_217 , V_218 = 0 ;
unsigned V_150 , V_219 = 5 ;
F_33 ( & V_10 -> V_38 ) ;
V_220:
V_217 = F_9 ( & V_2 -> V_88 ) & V_10 -> V_47 ;
if ( ! V_217 )
goto F_27;
V_10 -> V_61 ++ ;
if ( F_38 ( V_217 & V_181 ) ) {
if ( V_217 & V_221 ) {
ERROR ( V_10 , L_113 ) ;
F_72 ( V_10 , V_10 -> V_19 ) ;
V_217 = 0 ;
V_218 = 1 ;
V_10 -> V_19 = NULL ;
goto F_27;
}
if ( V_217 & V_184 ) {
F_2 ( ~ V_217 , & V_2 -> V_88 ) ;
if ( F_9 ( & V_10 -> V_2 -> V_152 ) & V_153 ) {
F_18 ( V_10 , L_114 ) ;
F_68 ( V_10 ) ;
} else {
F_12 ( V_10 , L_115 ) ;
if ( V_10 -> V_20 . V_21 == V_182 )
F_72 ( V_10 , V_10 -> V_19 ) ;
V_10 -> V_63 = V_163 ;
V_10 -> V_47 = V_181 ;
F_2 ( V_10 -> V_47 , & V_10 -> V_2 -> V_47 ) ;
}
V_217 = 0 ;
V_218 = 1 ;
goto F_27;
}
if ( V_217 & V_222 ) {
F_78 ( V_222 ) ;
if ( F_9 ( & V_2 -> V_165 [ 0 ] ) & V_223 ) {
switch ( V_10 -> V_63 ) {
case V_163 :
case V_64 :
goto V_224;
default:
break;
}
F_12 ( V_10 , L_116 ) ;
V_10 -> V_63 = V_64 ;
if ( V_10 -> V_20 . V_21 != V_22
&& V_10 -> V_19
&& V_10 -> V_19 -> V_225 ) {
F_32 ( & V_10 -> V_38 ) ;
V_10 -> V_19 -> V_225 ( & V_10 -> V_20 ) ;
F_33 ( & V_10 -> V_38 ) ;
}
} else {
if ( V_10 -> V_63 != V_64 ) {
F_12 ( V_10 , L_117 ,
V_10 -> V_63 ) ;
goto V_224;
}
F_12 ( V_10 , L_118 ) ;
V_10 -> V_63 = V_183 ;
if ( V_10 -> V_20 . V_21 != V_22
&& V_10 -> V_19
&& V_10 -> V_19 -> V_226 ) {
F_32 ( & V_10 -> V_38 ) ;
V_10 -> V_19 -> V_226 ( & V_10 -> V_20 ) ;
F_33 ( & V_10 -> V_38 ) ;
}
}
}
V_224:
if ( V_217 & V_227 ) {
F_78 ( V_227 ) ;
F_79 ( V_10 , L_119 ,
V_10 -> V_19 -> V_19 . V_37 ) ;
}
}
if ( V_217 & V_228 ) {
F_78 ( V_228 ) ;
V_10 -> V_12 [ 0 ] . V_61 ++ ;
F_74 ( V_10 ) ;
}
if ( V_217 & V_229 ) {
F_78 ( V_229 | V_230 ) ;
if ( V_10 -> V_63 == V_86 ) {
V_12 = & V_10 -> V_12 [ 0 ] ;
V_12 -> V_61 ++ ;
F_19 ( V_12 , 0 ) ;
F_2 ( ~ ( 1 << 0 ) , & V_2 -> V_90 ) ;
V_10 -> V_63 = V_91 ;
}
}
if ( V_217 & V_230 ) {
F_78 ( V_230 ) ;
V_12 = & V_10 -> V_12 [ 0 ] ;
V_12 -> V_61 ++ ;
F_46 ( V_12 ) ;
}
if ( V_217 & V_50 ) {
F_78 ( V_50 ) ;
V_12 = & V_10 -> V_12 [ V_35 ] ;
V_12 -> V_61 ++ ;
F_48 ( V_10 , V_12 ) ;
}
if ( V_217 & V_48 ) {
F_78 ( V_48 ) ;
V_12 = & V_10 -> V_12 [ V_36 ] ;
V_12 -> V_61 ++ ;
F_48 ( V_10 , V_12 ) ;
}
if ( V_217 & V_49 ) {
F_78 ( V_49 ) ;
V_12 = & V_10 -> V_12 [ V_36 ] ;
V_12 -> V_61 ++ ;
ERROR ( V_10 , L_120 , V_12 -> V_12 . V_37 ) ;
}
for ( V_150 = 1 ; V_150 < 4 ; V_150 ++ ) {
T_2 V_39 = F_16 ( V_150 ) ;
if ( ! ( V_217 & V_39 ) )
continue;
V_12 = & V_10 -> V_12 [ V_150 ] ;
F_46 ( V_12 ) ;
if ( F_25 ( & V_12 -> V_70 ) )
F_45 ( V_10 , V_2 , V_150 ) ;
V_217 &= ~ V_39 ;
V_218 = 1 ;
V_12 -> V_61 ++ ;
}
if ( V_219 -- )
goto V_220;
F_27:
( void ) F_9 ( & V_2 -> V_47 ) ;
F_32 ( & V_10 -> V_38 ) ;
if ( V_217 )
F_12 ( V_10 , L_121 , V_217 ,
F_9 ( & V_2 -> V_88 ) , V_10 -> V_47 ) ;
return F_80 ( V_218 ) ;
}
static void F_81 ( struct V_231 * V_149 )
{
struct V_9 * V_10 = F_82 ( V_149 ) ;
F_26 ( V_10 ) ;
}
static void F_83 ( struct V_232 * V_75 )
{
struct V_9 * V_10 = F_84 ( V_75 ) ;
F_12 ( V_10 , L_106 , V_129 ) ;
F_85 ( & V_10 -> V_20 ) ;
F_86 ( V_10 -> V_19 ) ;
#ifdef F_87
F_88 ( V_233 , NULL ) ;
#endif
if ( V_10 -> V_2 )
F_67 ( V_10 ) ;
if ( V_10 -> V_234 )
F_89 ( V_75 -> V_216 , V_10 ) ;
if ( V_10 -> V_2 )
F_90 ( V_10 -> V_2 ) ;
if ( V_10 -> V_235 )
F_91 ( F_92 ( V_75 , 0 ) ,
F_93 ( V_75 , 0 ) ) ;
if ( V_10 -> V_236 )
F_94 ( V_75 ) ;
if ( V_10 -> V_237 )
F_95 ( & V_10 -> V_20 . V_10 ) ;
F_96 ( V_75 , NULL ) ;
V_10 -> V_2 = NULL ;
V_186 = NULL ;
F_79 ( V_10 , L_122 ) ;
}
static int F_97 ( struct V_232 * V_75 , const struct V_238 * V_239 )
{
struct V_9 * V_10 = NULL ;
unsigned long V_240 , V_241 ;
void T_1 * V_242 = NULL ;
int V_136 ;
if ( V_186 ) {
F_98 ( L_123 , F_99 ( V_75 ) ) ;
return - V_30 ;
}
if ( ! V_75 -> V_216 ) {
F_100 ( V_243 L_124 , F_99 ( V_75 ) ) ;
V_136 = - V_62 ;
goto V_244;
}
V_10 = F_21 ( sizeof *V_10 , V_245 ) ;
if ( V_10 == NULL ) {
F_101 ( L_125 , F_99 ( V_75 ) ) ;
V_136 = - V_246 ;
goto V_244;
}
F_102 ( & V_10 -> V_38 ) ;
V_10 -> V_75 = V_75 ;
V_10 -> V_20 . V_167 = & V_247 ;
F_103 ( & V_10 -> V_20 . V_10 , L_126 ) ;
V_10 -> V_20 . V_10 . V_248 = & V_75 -> V_10 ;
V_10 -> V_20 . V_10 . V_249 = V_75 -> V_10 . V_249 ;
V_10 -> V_20 . V_10 . V_250 = F_81 ;
V_10 -> V_20 . V_37 = V_251 ;
V_136 = F_104 ( V_75 ) ;
if ( V_136 < 0 ) {
F_12 ( V_10 , L_127 , V_136 ) ;
goto V_244;
}
V_10 -> V_236 = 1 ;
V_240 = F_92 ( V_75 , 0 ) ;
V_241 = F_93 ( V_75 , 0 ) ;
if ( ! F_105 ( V_240 , V_241 , V_251 ) ) {
F_12 ( V_10 , L_128 ) ;
V_136 = - V_30 ;
goto V_244;
}
V_10 -> V_235 = 1 ;
V_242 = F_106 ( V_240 , V_241 ) ;
if ( V_242 == NULL ) {
F_12 ( V_10 , L_129 ) ;
V_136 = - V_252 ;
goto V_244;
}
V_10 -> V_2 = (struct V_1 T_1 * ) V_242 ;
F_96 ( V_75 , V_10 ) ;
F_79 ( V_10 , L_106 , V_253 ) ;
F_79 ( V_10 , L_130 V_254 L_131 , F_60 () ) ;
F_79 ( V_10 , L_132 , V_75 -> V_216 , V_242 ) ;
F_67 ( V_10 ) ;
F_66 ( V_10 ) ;
if ( F_107 ( V_75 -> V_216 , F_77 , V_255 ,
V_251 , V_10 ) != 0 ) {
F_12 ( V_10 , L_133 , V_75 -> V_216 ) ;
V_136 = - V_30 ;
goto V_244;
}
V_10 -> V_234 = 1 ;
if ( V_34 )
F_108 ( V_75 ) ;
#ifdef F_87
F_109 ( V_233 , 0 , NULL , F_63 , V_10 ) ;
#endif
V_186 = V_10 ;
V_136 = F_110 ( & V_10 -> V_20 . V_10 ) ;
if ( V_136 ) {
F_111 ( & V_10 -> V_20 . V_10 ) ;
goto V_244;
}
V_10 -> V_237 = 1 ;
V_136 = F_112 ( & V_75 -> V_10 , & V_10 -> V_20 ) ;
if ( V_136 )
goto V_244;
return 0 ;
V_244:
if ( V_10 )
F_83 ( V_75 ) ;
return V_136 ;
}
static int T_8 F_113 ( void )
{
return F_114 ( & V_256 ) ;
}
static void T_9 F_115 ( void )
{
F_116 ( & V_256 ) ;
}
