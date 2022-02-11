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
if ( ! V_6 || ! V_8
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
V_12 -> V_12 . V_8 = V_8 ;
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
F_17 ( & V_12 -> V_12 , V_60 ) ;
V_12 -> V_12 . V_8 = NULL ;
V_12 -> V_45 = 1 ;
V_12 -> V_61 = 0 ;
V_12 -> V_33 = 0 ;
}
static int F_18 ( struct V_5 * V_6 )
{
struct V_11 * V_12 ;
struct V_9 * V_10 ;
unsigned long V_15 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( ! V_6 || ! V_12 -> V_12 . V_8 )
return - V_62 ;
V_10 = V_12 -> V_10 ;
if ( V_10 -> V_63 == V_64 )
return - V_30 ;
F_19 ( V_10 , L_7 , V_6 -> V_37 ) ;
F_13 ( & V_10 -> V_38 , V_15 ) ;
F_20 ( V_12 , - V_23 ) ;
F_15 ( V_10 -> V_2 , V_12 ) ;
F_14 ( & V_10 -> V_38 , V_15 ) ;
return 0 ;
}
static struct V_65 *
F_21 ( struct V_5 * V_6 , T_4 V_66 )
{
struct V_67 * V_68 ;
if ( ! V_6 )
return NULL ;
V_68 = F_22 ( sizeof *V_68 , V_66 ) ;
if ( ! V_68 )
return NULL ;
F_23 ( & V_68 -> V_69 ) ;
return & V_68 -> V_68 ;
}
static void
F_24 ( struct V_5 * V_6 , struct V_65 * V_70 )
{
struct V_67 * V_68 ;
if ( ! V_6 || ! V_70 )
return;
V_68 = F_6 ( V_70 , struct V_67 , V_68 ) ;
F_25 ( ! F_26 ( & V_68 -> V_69 ) ) ;
F_27 ( V_68 ) ;
}
static void
F_28 ( struct V_11 * V_12 , struct V_67 * V_68 , int V_71 )
{
struct V_9 * V_10 ;
unsigned V_45 = V_12 -> V_45 ;
F_29 ( & V_68 -> V_69 ) ;
if ( F_30 ( V_68 -> V_68 . V_71 == - V_72 ) )
V_68 -> V_68 . V_71 = V_71 ;
else
V_71 = V_68 -> V_68 . V_71 ;
V_10 = V_12 -> V_10 ;
if ( V_12 -> V_33 )
F_31 ( & V_10 -> V_20 , & V_68 -> V_68 , V_12 -> V_32 ) ;
#ifndef F_32
if ( V_71 && V_71 != - V_23 )
#endif
F_19 ( V_10 , L_8 ,
V_12 -> V_12 . V_37 , & V_68 -> V_68 , V_71 ,
V_68 -> V_68 . V_73 , V_68 -> V_68 . V_74 ) ;
V_12 -> V_45 = 1 ;
F_33 ( & V_10 -> V_38 ) ;
F_34 ( & V_12 -> V_12 , & V_68 -> V_68 ) ;
F_35 ( & V_10 -> V_38 ) ;
V_12 -> V_45 = V_45 ;
}
static inline int
F_36 ( T_2 T_1 * V_75 , T_5 * V_76 , struct V_67 * V_68 , unsigned V_14 )
{
unsigned V_74 , V_77 ;
V_74 = F_37 ( V_68 -> V_68 . V_74 - V_68 -> V_68 . V_73 , V_14 ) ;
V_68 -> V_68 . V_73 += V_74 ;
V_77 = V_74 ;
while ( F_30 ( V_77 -- ) )
F_2 ( * V_76 ++ , V_75 ) ;
return V_74 ;
}
static int F_38 ( struct V_11 * V_12 , struct V_67 * V_68 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_2 V_39 ;
T_5 * V_76 ;
unsigned V_77 ;
int V_78 ;
V_39 = F_9 ( & V_10 -> V_2 -> V_79 ) ;
V_76 = V_68 -> V_68 . V_76 + V_68 -> V_68 . V_73 ;
F_39 ( V_76 ) ;
V_10 = V_12 -> V_10 ;
if ( F_40 ( V_12 -> V_24 == 0 && V_10 -> V_63 != V_80 ) )
return - V_81 ;
if ( F_40 ( ( V_39 & F_41 ( V_12 -> V_24 ) ) != 0 ) )
return 0 ;
if ( V_12 -> V_24 != 0 )
F_2 ( ~ F_16 ( V_12 -> V_24 ) , & V_10 -> V_2 -> V_82 ) ;
V_77 = F_36 ( V_12 -> V_83 , V_76 , V_68 , V_12 -> V_12 . V_44 ) ;
if ( F_40 ( V_77 != V_12 -> V_12 . V_44 ) ) {
F_2 ( ~ ( 1 << V_12 -> V_24 ) , & V_10 -> V_2 -> V_84 ) ;
if ( V_12 -> V_24 == 0 ) {
V_10 -> V_12 [ 0 ] . V_45 = 1 ;
V_10 -> V_63 = V_85 ;
}
V_78 = 1 ;
} else {
if ( F_30 ( V_68 -> V_68 . V_74 != V_68 -> V_68 . V_73 )
|| V_68 -> V_68 . V_86 )
V_78 = 0 ;
else
V_78 = 1 ;
}
#if 0
VDBG(dev, "wrote %s %u bytes%s IN %u left %p\n",
ep->ep.name, count, is_last ? "/last" : "",
req->req.length - req->req.actual, req);
#endif
if ( V_78 ) {
F_28 ( V_12 , V_68 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_42 ( struct V_11 * V_12 , struct V_67 * V_68 )
{
struct V_1 T_1 * V_2 ;
T_2 V_87 , V_88 ;
T_5 * V_76 ;
unsigned V_89 , V_90 , V_91 ;
V_2 = V_12 -> V_10 -> V_2 ;
V_92:
V_76 = V_68 -> V_68 . V_76 + V_68 -> V_68 . V_73 ;
F_43 ( V_76 ) ;
if ( F_40 ( V_12 -> V_24 == 0 && V_12 -> V_10 -> V_63 != V_93 ) )
return - V_81 ;
V_91 = ( V_12 -> V_24 == 1 || V_12 -> V_24 == 2 ) ;
do {
if ( V_12 -> V_24 != 0 )
F_2 ( ~ F_16 ( V_12 -> V_24 ) , & V_2 -> V_82 ) ;
V_88 = F_9 ( & V_2 -> V_79 ) & F_44 ( V_12 -> V_24 ) ;
V_87 = F_9 ( & V_2 -> V_94 [ V_12 -> V_24 ] ) ;
V_89 = V_68 -> V_68 . V_74 - V_68 -> V_68 . V_73 ;
if ( F_30 ( V_12 -> V_24 != 0 || V_89 != 0 ) ) {
if ( F_40 ( V_88 == 0 ) )
break;
if ( ! ( V_87 & V_95 ) )
V_87 = F_9 ( & V_2 -> V_96 [ V_12 -> V_24 ] ) ;
if ( ! ( V_87 & V_95 ) )
break;
V_87 &= V_97 ;
} else
V_87 = 0 ;
V_68 -> V_68 . V_73 += V_87 ;
V_90 = ( V_87 < V_12 -> V_12 . V_44 ) ;
#ifdef F_32
F_19 ( V_12 -> V_10 , L_9 ,
V_12 -> V_12 . V_37 , V_87 , V_90 ? L_10 : L_11 ,
V_68 , V_68 -> V_68 . V_73 , V_68 -> V_68 . V_74 ) ;
#endif
while ( F_30 ( V_87 -- != 0 ) ) {
T_5 V_98 = ( T_5 ) F_9 ( V_12 -> V_83 ) ;
if ( F_40 ( V_89 == 0 ) ) {
if ( V_68 -> V_68 . V_71 != - V_99 )
F_12 ( V_12 -> V_10 , L_12 ,
V_12 -> V_12 . V_37 , V_87 ) ;
V_68 -> V_68 . V_71 = - V_99 ;
} else {
* V_76 ++ = V_98 ;
V_89 -- ;
}
}
if ( F_40 ( V_90 || V_68 -> V_68 . V_73 == V_68 -> V_68 . V_74 ) ) {
if ( F_40 ( V_12 -> V_24 == 0 ) ) {
if ( V_12 -> V_10 -> V_100 )
F_2 ( V_12 -> V_10 -> V_101
? V_102
: 0 ,
& V_2 -> V_103 ) ;
F_2 ( ~ ( 1 << 0 ) , & V_2 -> V_84 ) ;
V_12 -> V_45 = 1 ;
V_12 -> V_10 -> V_63 = V_85 ;
}
F_28 ( V_12 , V_68 , 0 ) ;
if ( V_91 && ! F_26 ( & V_12 -> V_69 ) ) {
V_68 = F_45 ( V_12 -> V_69 . V_104 ,
struct V_67 , V_69 ) ;
goto V_92;
}
return 1 ;
}
} while ( V_91 );
return 0 ;
}
static inline void
F_46 ( struct V_9 * V_10 ,
struct V_1 T_1 * V_2 , int V_3 )
{
V_10 -> V_47 |= F_16 ( V_3 ) ;
F_2 ( V_10 -> V_47 , & V_2 -> V_47 ) ;
}
static inline void
F_47 ( struct V_9 * V_10 ,
struct V_1 T_1 * V_2 , int V_3 )
{
V_10 -> V_47 &= ~ F_16 ( V_3 ) ;
F_2 ( V_10 -> V_47 , & V_2 -> V_47 ) ;
}
static inline void
F_48 ( struct V_11 * V_12 )
{
struct V_67 * V_68 ;
if ( F_40 ( F_26 ( & V_12 -> V_69 ) ) )
return;
V_68 = F_45 ( V_12 -> V_69 . V_104 , struct V_67 , V_69 ) ;
( V_12 -> V_32 ? F_38 : F_42 ) ( V_12 , V_68 ) ;
}
static int F_49 ( struct V_11 * V_12 , struct V_67 * V_68 )
{
struct V_1 T_1 * V_2 = V_12 -> V_10 -> V_2 ;
T_2 V_53 ;
T_2 V_105 = V_68 -> V_68 . V_33 ;
T_2 V_106 = V_105 + V_68 -> V_68 . V_74 - 1 ;
V_53 = F_9 ( & V_2 -> V_54 ) & V_55 ;
if ( F_30 ( V_12 -> V_32 ) ) {
if ( F_40 ( V_53 & V_107 ) ) {
F_12 ( V_12 -> V_10 , L_13 ,
V_53 ) ;
}
F_2 ( V_106 , & V_2 -> V_108 ) ;
F_2 ( V_105 , & V_2 -> V_109 ) ;
V_53 &= ~ V_58 ;
if ( F_40 ( V_68 -> V_68 . V_74 == 0 ) )
V_53 = V_107 | V_110 ;
else if ( ( V_68 -> V_68 . V_74 % V_12 -> V_12 . V_44 ) != 0
|| V_68 -> V_68 . V_86 )
V_53 = V_107 | V_111 ;
else
V_53 = V_107 | V_112 ;
V_12 -> V_10 -> V_47 |= V_50 ;
} else {
if ( F_40 ( V_53 & V_113 ) ) {
F_12 ( V_12 -> V_10 , L_14 ,
V_53 ) ;
}
F_2 ( V_106 , & V_2 -> V_114 ) ;
F_2 ( V_105 , & V_2 -> V_115 ) ;
V_53 &= ~ V_56 ;
V_53 |= V_113 | V_116 ;
V_12 -> V_10 -> V_47 |= V_48 | V_49 ;
}
F_2 ( V_53 , & V_2 -> V_54 ) ;
F_2 ( V_12 -> V_10 -> V_47 , & V_2 -> V_47 ) ;
return 0 ;
}
static void F_50 ( struct V_9 * V_10 , struct V_11 * V_12 )
{
struct V_67 * V_68 ;
struct V_1 T_1 * V_2 = V_12 -> V_10 -> V_2 ;
T_2 V_53 ;
V_53 = F_9 ( & V_2 -> V_54 ) ;
if ( F_40 ( F_26 ( & V_12 -> V_69 ) ) ) {
V_117:
if ( V_12 -> V_32 )
V_10 -> V_47 &= ~ V_50 ;
else
V_10 -> V_47 &= ~ ( V_48 | V_49 ) ;
F_2 ( V_10 -> V_47 , & V_2 -> V_47 ) ;
return;
}
V_68 = F_45 ( V_12 -> V_69 . V_104 , struct V_67 , V_69 ) ;
if ( F_30 ( V_12 -> V_32 ) ) {
if ( F_40 ( V_53 & V_107 ) )
return;
V_68 -> V_68 . V_73 = F_9 ( & V_2 -> V_118 ) ;
} else {
if ( F_40 ( V_53 & V_113 ) )
return;
V_68 -> V_68 . V_73 = F_9 ( & V_2 -> V_119 ) ;
}
V_68 -> V_68 . V_73 -= V_68 -> V_68 . V_33 ;
V_68 -> V_68 . V_73 ++ ;
#ifdef F_32
F_19 ( V_10 , L_15 ,
V_12 -> V_12 . V_37 , V_12 -> V_32 ? L_3 : L_4 ,
V_68 -> V_68 . V_73 , V_68 -> V_68 . V_74 , V_68 ) ;
#endif
F_28 ( V_12 , V_68 , 0 ) ;
if ( F_26 ( & V_12 -> V_69 ) )
goto V_117;
V_68 = F_45 ( V_12 -> V_69 . V_104 , struct V_67 , V_69 ) ;
( void ) F_49 ( V_12 , V_68 ) ;
}
static void F_51 ( struct V_11 * V_12 , int V_71 )
{
struct V_1 T_1 * V_2 = V_12 -> V_10 -> V_2 ;
struct V_67 * V_68 ;
T_2 V_120 , V_53 ;
F_1 ( V_2 , V_121 , V_12 -> V_24 ) ;
V_68 = F_45 ( V_12 -> V_69 . V_104 , struct V_67 , V_69 ) ;
V_53 = F_9 ( & V_2 -> V_54 ) & V_55 ;
if ( V_12 -> V_32 ) {
if ( F_40 ( ( F_9 ( & V_2 -> V_54 ) & V_107 ) == 0 ) )
goto V_122;
V_120 = F_9 ( & V_2 -> V_118 ) ;
F_2 ( V_120 , & V_2 -> V_108 ) ;
F_2 ( V_120 , & V_2 -> V_109 ) ;
V_53 &= ~ V_58 ;
V_53 |= V_59 ;
F_2 ( V_53 , & V_2 -> V_54 ) ;
if ( F_9 ( & V_2 -> V_54 ) & V_107 )
F_12 ( V_12 -> V_10 , L_16 ) ;
} else {
if ( F_40 ( ( F_9 ( & V_2 -> V_54 ) & V_113 ) == 0 ) )
goto V_122;
V_120 = F_9 ( & V_2 -> V_119 ) ;
F_2 ( V_120 , & V_2 -> V_114 ) ;
F_2 ( V_120 , & V_2 -> V_115 ) ;
V_53 &= ~ V_56 ;
V_53 |= V_57 ;
F_2 ( V_53 , & V_2 -> V_54 ) ;
if ( F_9 ( & V_2 -> V_54 ) & V_113 )
F_12 ( V_12 -> V_10 , L_17 ) ;
}
V_68 -> V_68 . V_73 = ( V_120 - V_68 -> V_68 . V_33 ) + 1 ;
V_68 -> V_68 . V_71 = V_71 ;
F_19 ( V_12 -> V_10 , L_18 , V_123 , V_12 -> V_12 . V_37 ,
V_12 -> V_32 ? L_3 : L_4 ,
V_68 -> V_68 . V_73 , V_68 -> V_68 . V_74 ) ;
F_1 ( V_2 , V_124 , V_12 -> V_24 ) ;
return;
V_122:
F_1 ( V_2 , V_124 , V_12 -> V_24 ) ;
V_68 -> V_68 . V_73 = V_68 -> V_68 . V_74 ;
V_68 -> V_68 . V_71 = 0 ;
}
static int
F_52 ( struct V_5 * V_6 , struct V_65 * V_70 , T_4 V_66 )
{
struct V_67 * V_68 ;
struct V_11 * V_12 ;
struct V_9 * V_10 ;
unsigned long V_15 ;
int V_71 ;
V_68 = F_6 ( V_70 , struct V_67 , V_68 ) ;
if ( F_40 ( ! V_70 || ! V_70 -> V_125
|| ! V_70 -> V_76 || ! F_26 ( & V_68 -> V_69 ) ) )
return - V_18 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( F_40 ( ! V_6 || ( ! V_12 -> V_12 . V_8 && V_12 -> V_24 != 0 ) ) )
return - V_18 ;
V_10 = V_12 -> V_10 ;
if ( F_40 ( ! V_10 -> V_19 || V_10 -> V_20 . V_21 == V_22 ) )
return - V_23 ;
if ( V_10 -> V_63 == V_64 )
return - V_30 ;
if ( V_12 -> V_33 ) {
V_71 = F_53 ( & V_10 -> V_20 , & V_68 -> V_68 ,
V_12 -> V_32 ) ;
if ( V_71 )
return V_71 ;
}
#ifdef F_32
F_19 ( V_10 , L_19 ,
V_6 -> V_37 , V_70 , V_70 -> V_74 , V_70 -> V_76 ) ;
#endif
F_13 ( & V_10 -> V_38 , V_15 ) ;
V_70 -> V_71 = - V_72 ;
V_70 -> V_73 = 0 ;
if ( F_40 ( V_12 -> V_24 == 0 && V_12 -> V_32 ) )
V_70 -> V_86 = 1 ;
V_71 = 0 ;
if ( F_26 ( & V_12 -> V_69 ) && F_30 ( ! V_12 -> V_45 ) ) {
if ( V_12 -> V_33 )
V_71 = F_49 ( V_12 , V_68 ) ;
else
V_71 = ( V_12 -> V_32 ? F_38 : F_42 ) ( V_12 , V_68 ) ;
if ( F_40 ( V_71 != 0 ) ) {
if ( V_71 > 0 )
V_71 = 0 ;
V_68 = NULL ;
}
}
if ( F_30 ( V_68 != NULL ) )
F_54 ( & V_68 -> V_69 , & V_12 -> V_69 ) ;
if ( F_30 ( ! F_26 ( & V_12 -> V_69 ) )
&& F_30 ( V_12 -> V_24 != 0 )
&& ! V_12 -> V_33
&& ! ( V_10 -> V_47 & F_16 ( V_12 -> V_24 ) ) )
F_46 ( V_10 , V_10 -> V_2 , V_12 -> V_24 ) ;
F_14 ( & V_10 -> V_38 , V_15 ) ;
return V_71 ;
}
static void F_20 ( struct V_11 * V_12 , int V_71 )
{
struct V_67 * V_68 ;
V_12 -> V_45 = 1 ;
if ( F_26 ( & V_12 -> V_69 ) )
return;
if ( V_12 -> V_33 )
F_51 ( V_12 , V_71 ) ;
while ( ! F_26 ( & V_12 -> V_69 ) ) {
V_68 = F_45 ( V_12 -> V_69 . V_104 , struct V_67 , V_69 ) ;
F_28 ( V_12 , V_68 , V_71 ) ;
}
}
static int F_55 ( struct V_5 * V_6 , struct V_65 * V_70 )
{
struct V_67 * V_68 ;
struct V_11 * V_12 ;
struct V_9 * V_10 ;
unsigned long V_15 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( ! V_6 || ! V_70 || ( ! V_12 -> V_12 . V_8 && V_12 -> V_24 != 0 ) )
return - V_18 ;
V_10 = V_12 -> V_10 ;
if ( ! V_10 -> V_19 )
return - V_23 ;
if ( V_10 -> V_63 == V_64 )
return - V_30 ;
F_19 ( V_10 , L_20 , V_123 , V_6 -> V_37 ,
V_12 -> V_32 ? L_3 : L_4 ,
V_12 -> V_33 ? L_5 : L_6 ,
V_70 ) ;
F_13 ( & V_10 -> V_38 , V_15 ) ;
F_56 (req, &ep->queue, queue) {
if ( & V_68 -> V_68 == V_70 )
break;
}
if ( & V_68 -> V_68 != V_70 ) {
F_14 ( & V_10 -> V_38 , V_15 ) ;
return - V_18 ;
}
if ( V_12 -> V_33 && V_12 -> V_69 . V_104 == & V_68 -> V_69 && ! V_12 -> V_45 ) {
F_51 ( V_12 , - V_126 ) ;
F_28 ( V_12 , V_68 , - V_126 ) ;
F_50 ( V_10 , V_12 ) ;
} else if ( ! F_26 ( & V_68 -> V_69 ) )
F_28 ( V_12 , V_68 , - V_126 ) ;
else
V_68 = NULL ;
F_14 ( & V_10 -> V_38 , V_15 ) ;
return V_68 ? 0 : - V_127 ;
}
static void F_57 ( struct V_11 * V_12 )
{
F_19 ( V_12 -> V_10 , L_21 , V_12 -> V_12 . V_37 ) ;
F_1 ( V_12 -> V_10 -> V_2 , V_128 , V_12 -> V_24 ) ;
F_1 ( V_12 -> V_10 -> V_2 , V_129 , V_12 -> V_24 ) ;
if ( V_12 -> V_45 ) {
V_12 -> V_45 = 0 ;
if ( V_12 -> V_33 ) {
struct V_67 * V_68 ;
if ( F_26 ( & V_12 -> V_69 ) )
return;
V_68 = F_45 ( V_12 -> V_69 . V_104 , struct V_67 ,
V_69 ) ;
( void ) F_49 ( V_12 , V_68 ) ;
} else
F_48 ( V_12 ) ;
}
}
static int F_58 ( struct V_5 * V_6 , int V_130 )
{
struct V_11 * V_12 ;
unsigned long V_15 ;
int V_131 = 0 ;
if ( ! V_6 )
return - V_62 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( V_12 -> V_24 == 0 ) {
if ( V_130 ) {
V_12 -> V_10 -> V_63 = V_132 ;
V_12 -> V_10 -> V_12 [ 0 ] . V_45 = 1 ;
} else
return - V_18 ;
} else if ( ! V_12 -> V_12 . V_8 ) {
F_12 ( V_12 -> V_10 , L_22 , V_123 , V_12 -> V_12 . V_37 ) ;
return - V_18 ;
}
F_13 ( & V_12 -> V_10 -> V_38 , V_15 ) ;
if ( ! F_26 ( & V_12 -> V_69 ) )
V_131 = - V_133 ;
else if ( V_12 -> V_32 && V_130
&& ( F_9 ( & V_12 -> V_10 -> V_2 -> V_79 )
& F_44 ( V_12 -> V_24 ) ) )
V_131 = - V_133 ;
else if ( ! V_130 )
F_57 ( V_12 ) ;
else {
V_12 -> V_45 = 1 ;
F_19 ( V_12 -> V_10 , L_23 , V_12 -> V_12 . V_37 ) ;
F_1 ( V_12 -> V_10 -> V_2 , V_134 , V_12 -> V_24 ) ;
F_9 ( V_12 -> V_27 ) ;
}
F_14 ( & V_12 -> V_10 -> V_38 , V_15 ) ;
return V_131 ;
}
static int F_59 ( struct V_5 * V_6 )
{
struct V_11 * V_12 ;
struct V_1 T_1 * V_2 ;
T_2 V_87 ;
if ( ! V_6 )
return - V_62 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( V_12 -> V_32 )
return - V_127 ;
V_2 = V_12 -> V_10 -> V_2 ;
V_87 = F_9 ( & V_2 -> V_94 [ V_12 -> V_24 ] ) & V_97 ;
V_87 += F_9 ( & V_2 -> V_96 [ V_12 -> V_24 ] ) & V_97 ;
F_19 ( V_12 -> V_10 , L_24 , V_123 , V_12 -> V_12 . V_37 , V_87 ) ;
return V_87 ;
}
static void F_60 ( struct V_5 * V_6 )
{
struct V_11 * V_12 ;
struct V_1 T_1 * V_2 ;
T_2 V_87 ;
if ( ! V_6 )
return;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
F_19 ( V_12 -> V_10 , L_25 , V_123 , V_12 -> V_12 . V_37 ) ;
if ( ! V_12 -> V_12 . V_8 && V_12 -> V_24 != 0 ) {
F_12 ( V_12 -> V_10 , L_22 , V_123 , V_12 -> V_12 . V_37 ) ;
return;
}
V_2 = V_12 -> V_10 -> V_2 ;
V_87 = F_9 ( & V_2 -> V_94 [ V_12 -> V_24 ] ) ;
V_87 &= V_97 ;
if ( V_87 )
F_1 ( V_2 , V_135 , V_12 -> V_24 ) ;
}
static int F_61 ( struct V_136 * V_137 )
{
return - V_127 ;
}
static inline const char * F_62 ( void )
{
if ( V_34 == 0 )
return L_26 ;
else if ( V_34 == 2 )
return L_27 ;
else
return L_28 ;
}
static void F_63 ( struct V_138 * V_139 , const char * V_140 , T_2 V_141 )
{
F_64 (m,
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
}
static int F_65 ( struct V_138 * V_139 , void * V_142 )
{
struct V_9 * V_10 = V_139 -> V_143 ;
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
unsigned long V_15 ;
int V_144 , V_145 ;
T_2 V_39 ;
F_66 ( V_15 ) ;
V_39 = F_9 ( & V_2 -> V_146 ) ;
V_145 = V_39 & V_147 ;
F_64 (m,
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
({const char *state;
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
F_63 ( V_139 , L_67 , F_9 ( & V_2 -> V_82 ) ) ;
F_63 ( V_139 , L_68 , F_9 ( & V_2 -> V_47 ) ) ;
if ( ! V_145 || ! V_10 -> V_19 || ( V_39 & V_148 ) == 0 )
goto F_28;
if ( F_64 ( V_139 , L_69
L_70 ,
V_10 -> V_61 , F_9 ( & V_2 -> V_79 ) ,
F_9 ( & V_2 -> V_40 ) , F_9 ( & V_2 -> V_41 ) ,
F_9 ( & V_2 -> V_103 ) ,
F_9 ( & V_2 -> V_149 ) ) < 0 )
goto F_28;
V_39 = F_9 ( & V_2 -> V_54 ) ;
if ( F_64 ( V_139 ,
L_71 V_150 L_25 , V_39 ,
( V_39 & V_112 ) ? L_72 : L_11 ,
( V_39 & V_111 ) ? L_73 : L_11 ,
( V_39 & V_116 ) ? L_74 : L_11 ,
( V_39 & V_151 ) ? L_75 : L_11 ,
( V_39 & V_110 ) ? L_76 : L_11 ,
( V_39 & V_59 ) ? L_77 : L_11 ,
( V_39 & V_57 ) ? L_78 : L_11 ,
( V_39 & V_107 ) ? L_79 : L_11 ,
( V_39 & V_113 ) ? L_80 : L_11 ,
( V_39 & V_152 )
? L_81
: L_82 ) < 0 )
goto F_28;
for ( V_144 = 0 ; V_144 < 4 ; V_144 ++ ) {
struct V_11 * V_12 = & V_10 -> V_12 [ V_144 ] ;
struct V_67 * V_68 ;
if ( V_144 && ! V_12 -> V_12 . V_8 )
continue;
V_39 = F_9 ( V_12 -> V_27 ) ;
if ( F_64 (m,
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
} s; }),
(tmp & EPxSTATUS_TOGGLE) ? L_96 : L_97 ,
(tmp & EPxSTATUS_SUSPEND) ? L_50 : L_11 ,
(tmp & EPxSTATUS_FIFO_DISABLE) ? L_98 : L_11 ,
(tmp & EPxSTATUS_STAGE_ERROR) ? L_99 : L_11
) < 0 )
goto F_28;
if ( F_26 ( & V_12 -> V_69 ) ) {
if ( F_67 ( V_139 , L_100 ) < 0 )
goto F_28;
continue;
}
F_56 (req, &ep->queue, queue) {
if ( V_12 -> V_33 && V_68 -> V_69 . V_153 == & V_12 -> V_69 ) {
if ( V_144 == V_35 )
V_39 = F_9 ( & V_2 -> V_118 ) ;
else
V_39 = F_9 ( & V_2 -> V_119 ) ;
V_39 -= V_68 -> V_68 . V_33 ;
V_39 ++ ;
} else
V_39 = V_68 -> V_68 . V_73 ;
if ( F_64 ( V_139 ,
L_101 ,
& V_68 -> V_68 , V_39 , V_68 -> V_68 . V_74 ,
V_68 -> V_68 . V_76 ) < 0 )
goto F_28;
}
}
F_28:
F_68 ( V_15 ) ;
return 0 ;
}
static int F_69 ( struct V_154 * V_154 , struct V_155 * V_155 )
{
return F_70 ( V_155 , F_65 , F_71 ( F_72 ( V_155 ) ) ) ;
}
static void F_73 ( struct V_9 * V_10 )
{
static char * V_156 [] = { L_102 , L_103 , L_104 , L_105 } ;
unsigned V_144 ;
F_23 ( & V_10 -> V_20 . V_157 ) ;
V_10 -> V_20 . V_158 = & V_10 -> V_12 [ 0 ] . V_12 ;
V_10 -> V_20 . V_21 = V_22 ;
V_10 -> V_63 = V_159 ;
V_10 -> V_61 = 0 ;
for ( V_144 = 0 ; V_144 < 4 ; V_144 ++ ) {
struct V_11 * V_12 = & V_10 -> V_12 [ V_144 ] ;
V_12 -> V_24 = V_144 ;
V_12 -> V_12 . V_37 = V_156 [ V_144 ] ;
V_12 -> V_83 = & V_10 -> V_2 -> V_160 [ V_144 ] ;
V_12 -> V_27 = & V_10 -> V_2 -> V_161 [ V_144 ] ;
V_12 -> V_42 = & V_10 -> V_2 -> V_162 [ V_144 ] ;
V_12 -> V_12 . V_163 = & V_164 ;
F_54 ( & V_12 -> V_12 . V_157 , & V_10 -> V_20 . V_157 ) ;
V_12 -> V_10 = V_10 ;
F_23 ( & V_12 -> V_69 ) ;
F_15 ( NULL , V_12 ) ;
}
V_10 -> V_12 [ 0 ] . V_42 = NULL ;
F_17 ( & V_10 -> V_12 [ 0 ] . V_12 , V_165 ) ;
F_29 ( & V_10 -> V_12 [ 0 ] . V_12 . V_157 ) ;
}
static void F_74 ( struct V_9 * V_10 )
{
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
F_2 ( 0 , & V_2 -> V_146 ) ;
F_2 ( 0 , & V_2 -> V_47 ) ;
F_9 ( & V_2 -> V_47 ) ;
V_10 -> V_47 = 0 ;
F_4 ( 250 ) ;
F_2 ( V_166 , & V_2 -> V_146 ) ;
F_9 ( & V_2 -> V_47 ) ;
}
static void F_75 ( struct V_9 * V_10 )
{
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
unsigned V_144 ;
F_19 ( V_10 , L_106 , V_123 ) ;
F_74 ( V_10 ) ;
F_73 ( V_10 ) ;
F_2 ( V_167 | V_168
| V_169 | V_170
| V_171
| V_172
, & V_2 -> V_173 ) ;
for ( V_144 = 0 ; V_144 < 4 ; V_144 ++ )
V_10 -> V_12 [ V_144 ] . V_61 = 0 ;
for ( V_144 = 0 ; V_144 < V_174 ; V_144 ++ )
F_2 ( 0 , & V_2 -> V_175 [ V_144 ] ) ;
F_2 ( 0 , & V_2 -> V_176 ) ;
F_2 ( V_166 | V_148 , & V_2 -> V_146 ) ;
V_10 -> V_47 = V_177 | V_51 ;
F_2 ( V_10 -> V_47 , & V_10 -> V_2 -> V_47 ) ;
F_9 ( & V_2 -> V_47 ) ;
V_10 -> V_20 . V_21 = V_178 ;
V_10 -> V_63 = V_179 ;
}
static void F_76 ( struct V_9 * V_10 )
{
if ( F_9 ( & V_10 -> V_2 -> V_146 ) & V_147 )
F_75 ( V_10 ) ;
else {
F_12 ( V_10 , L_106 , V_123 ) ;
V_10 -> V_47 = V_180 ;
F_2 ( V_10 -> V_47 , & V_10 -> V_2 -> V_47 ) ;
}
}
static int F_77 ( struct V_136 * V_181 ,
struct V_182 * V_19 )
{
struct V_9 * V_10 = F_78 ( V_181 ) ;
V_19 -> V_19 . V_183 = NULL ;
V_10 -> V_19 = V_19 ;
F_76 ( V_10 ) ;
return 0 ;
}
static void F_79 ( struct V_9 * V_10 )
{
unsigned V_144 ;
F_12 ( V_10 , L_106 , V_123 ) ;
F_74 ( V_10 ) ;
for ( V_144 = 0 ; V_144 < 4 ; V_144 ++ )
F_20 ( & V_10 -> V_12 [ V_144 ] , - V_23 ) ;
if ( V_10 -> V_19 )
F_76 ( V_10 ) ;
}
static int F_80 ( struct V_136 * V_181 )
{
struct V_9 * V_10 = F_78 ( V_181 ) ;
unsigned long V_15 ;
F_13 ( & V_10 -> V_38 , V_15 ) ;
V_10 -> V_19 = NULL ;
F_79 ( V_10 ) ;
F_14 ( & V_10 -> V_38 , V_15 ) ;
return 0 ;
}
static void F_81 ( struct V_9 * V_10 )
{
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
struct V_184 V_185 ;
int V_39 ;
V_185 . V_186 = F_9 ( & V_2 -> V_186 ) ;
V_185 . V_187 = F_9 ( & V_2 -> V_187 ) ;
V_185 . V_188 = F_82 ( ( F_9 ( & V_2 -> V_189 ) << 8 )
| F_9 ( & V_2 -> V_190 ) ) ;
V_185 . V_191 = F_82 ( ( F_9 ( & V_2 -> V_192 ) << 8 )
| F_9 ( & V_2 -> V_193 ) ) ;
V_185 . V_194 = F_82 ( ( F_9 ( & V_2 -> V_195 ) << 8 )
| F_9 ( & V_2 -> V_196 ) ) ;
F_2 ( 0 , & V_2 -> V_197 ) ;
F_20 ( & V_10 -> V_12 [ 0 ] , 0 ) ;
V_10 -> V_12 [ 0 ] . V_45 = 0 ;
if ( F_30 ( V_185 . V_186 & V_198 ) ) {
V_10 -> V_12 [ 0 ] . V_32 = 1 ;
V_10 -> V_63 = V_80 ;
F_2 ( V_199 , & V_10 -> V_2 -> V_200 ) ;
} else {
V_10 -> V_12 [ 0 ] . V_32 = 0 ;
V_10 -> V_63 = V_93 ;
switch ( V_185 . V_187 ) {
case V_201 :
switch ( V_185 . V_186 ) {
case V_202 :
V_39 = F_83 ( V_185 . V_191 ) & 0x0f ;
if ( V_39 > 3 ||
( ! V_10 -> V_12 [ V_39 ] . V_12 . V_8 && V_39 != 0 ) )
goto V_203;
if ( V_185 . V_191 & F_82 (
V_198 ) ) {
if ( ! V_10 -> V_12 [ V_39 ] . V_32 )
goto V_203;
} else {
if ( V_10 -> V_12 [ V_39 ] . V_32 )
goto V_203;
}
if ( V_185 . V_188 != F_82 (
V_204 ) )
goto V_203;
if ( V_39 )
F_57 ( & V_10 -> V_12 [ V_39 ] ) ;
V_205:
F_2 ( ~ ( 1 << 0 ) , & V_2 -> V_84 ) ;
V_10 -> V_12 [ 0 ] . V_45 = 1 ;
V_10 -> V_63 = V_85 ;
return;
case V_206 :
if ( V_185 . V_188 != F_82 ( 1 ) )
goto V_203;
F_19 ( V_10 , L_107 ) ;
goto V_205;
case V_207 :
goto V_203;
default:
break;
}
break;
default:
break;
}
}
#ifdef F_32
F_19 ( V_10 , L_108 ,
V_185 . V_186 , V_185 . V_187 ,
F_83 ( V_185 . V_188 ) , F_83 ( V_185 . V_191 ) ,
F_83 ( V_185 . V_194 ) ) ;
#endif
V_10 -> V_100 = ( V_185 . V_187 == V_208
&& V_185 . V_186 == V_206 ) ;
if ( F_40 ( V_10 -> V_100 ) )
V_10 -> V_101 = ( V_185 . V_188 != F_82 ( 0 ) ) ;
F_33 ( & V_10 -> V_38 ) ;
V_39 = V_10 -> V_19 -> V_209 ( & V_10 -> V_20 , & V_185 ) ;
F_35 ( & V_10 -> V_38 ) ;
if ( F_40 ( V_39 < 0 ) ) {
V_203:
#ifdef F_32
F_19 ( V_10 , L_109 ,
V_185 . V_186 , V_185 . V_187 , V_39 ) ;
#endif
F_1 ( V_2 , V_134 , 0 ) ;
V_10 -> V_12 [ 0 ] . V_45 = 1 ;
V_10 -> V_63 = V_132 ;
}
}
static T_6 F_84 ( int V_210 , void * V_211 )
{
struct V_9 * V_10 = V_211 ;
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
T_2 V_212 , V_213 = 0 ;
unsigned V_144 , V_214 = 5 ;
F_35 ( & V_10 -> V_38 ) ;
V_215:
V_212 = F_9 ( & V_2 -> V_82 ) & V_10 -> V_47 ;
if ( ! V_212 )
goto F_28;
V_10 -> V_61 ++ ;
if ( F_40 ( V_212 & V_177 ) ) {
if ( V_212 & V_216 ) {
ERROR ( V_10 , L_110 ) ;
F_79 ( V_10 ) ;
V_212 = 0 ;
V_213 = 1 ;
V_10 -> V_19 = NULL ;
goto F_28;
}
if ( V_212 & V_180 ) {
F_2 ( ~ V_212 , & V_2 -> V_82 ) ;
if ( F_9 ( & V_10 -> V_2 -> V_146 ) & V_147 ) {
F_19 ( V_10 , L_111 ) ;
F_75 ( V_10 ) ;
} else {
F_12 ( V_10 , L_112 ) ;
if ( V_10 -> V_20 . V_21 == V_178 )
F_79 ( V_10 ) ;
V_10 -> V_63 = V_159 ;
V_10 -> V_47 = V_177 ;
F_2 ( V_10 -> V_47 , & V_10 -> V_2 -> V_47 ) ;
}
V_212 = 0 ;
V_213 = 1 ;
goto F_28;
}
if ( V_212 & V_217 ) {
F_85 ( V_217 ) ;
if ( F_9 ( & V_2 -> V_161 [ 0 ] ) & V_218 ) {
switch ( V_10 -> V_63 ) {
case V_159 :
case V_64 :
goto V_219;
default:
break;
}
F_12 ( V_10 , L_113 ) ;
V_10 -> V_63 = V_64 ;
if ( V_10 -> V_20 . V_21 != V_22
&& V_10 -> V_19
&& V_10 -> V_19 -> V_220 ) {
F_33 ( & V_10 -> V_38 ) ;
V_10 -> V_19 -> V_220 ( & V_10 -> V_20 ) ;
F_35 ( & V_10 -> V_38 ) ;
}
} else {
if ( V_10 -> V_63 != V_64 ) {
F_12 ( V_10 , L_114 ,
V_10 -> V_63 ) ;
goto V_219;
}
F_12 ( V_10 , L_115 ) ;
V_10 -> V_63 = V_179 ;
if ( V_10 -> V_20 . V_21 != V_22
&& V_10 -> V_19
&& V_10 -> V_19 -> V_221 ) {
F_33 ( & V_10 -> V_38 ) ;
V_10 -> V_19 -> V_221 ( & V_10 -> V_20 ) ;
F_35 ( & V_10 -> V_38 ) ;
}
}
}
V_219:
if ( V_212 & V_222 ) {
F_85 ( V_222 ) ;
F_86 ( V_10 , L_116 ,
V_10 -> V_19 -> V_19 . V_37 ) ;
}
}
if ( V_212 & V_223 ) {
F_85 ( V_223 ) ;
V_10 -> V_12 [ 0 ] . V_61 ++ ;
F_81 ( V_10 ) ;
}
if ( V_212 & V_224 ) {
F_85 ( V_224 | V_225 ) ;
if ( V_10 -> V_63 == V_80 ) {
V_12 = & V_10 -> V_12 [ 0 ] ;
V_12 -> V_61 ++ ;
F_20 ( V_12 , 0 ) ;
F_2 ( ~ ( 1 << 0 ) , & V_2 -> V_84 ) ;
V_10 -> V_63 = V_85 ;
}
}
if ( V_212 & V_225 ) {
F_85 ( V_225 ) ;
V_12 = & V_10 -> V_12 [ 0 ] ;
V_12 -> V_61 ++ ;
F_48 ( V_12 ) ;
}
if ( V_212 & V_50 ) {
F_85 ( V_50 ) ;
V_12 = & V_10 -> V_12 [ V_35 ] ;
V_12 -> V_61 ++ ;
F_50 ( V_10 , V_12 ) ;
}
if ( V_212 & V_48 ) {
F_85 ( V_48 ) ;
V_12 = & V_10 -> V_12 [ V_36 ] ;
V_12 -> V_61 ++ ;
F_50 ( V_10 , V_12 ) ;
}
if ( V_212 & V_49 ) {
F_85 ( V_49 ) ;
V_12 = & V_10 -> V_12 [ V_36 ] ;
V_12 -> V_61 ++ ;
ERROR ( V_10 , L_117 , V_12 -> V_12 . V_37 ) ;
}
for ( V_144 = 1 ; V_144 < 4 ; V_144 ++ ) {
T_2 V_39 = F_16 ( V_144 ) ;
if ( ! ( V_212 & V_39 ) )
continue;
V_12 = & V_10 -> V_12 [ V_144 ] ;
F_48 ( V_12 ) ;
if ( F_26 ( & V_12 -> V_69 ) )
F_47 ( V_10 , V_2 , V_144 ) ;
V_212 &= ~ V_39 ;
V_213 = 1 ;
V_12 -> V_61 ++ ;
}
if ( V_214 -- )
goto V_215;
F_28:
( void ) F_9 ( & V_2 -> V_47 ) ;
F_33 ( & V_10 -> V_38 ) ;
if ( V_212 )
F_12 ( V_10 , L_118 , V_212 ,
F_9 ( & V_2 -> V_82 ) , V_10 -> V_47 ) ;
return F_87 ( V_213 ) ;
}
static void F_88 ( struct V_226 * V_211 )
{
struct V_9 * V_10 = F_89 ( V_211 ) ;
F_27 ( V_10 ) ;
}
static void F_90 ( struct V_227 * V_228 )
{
struct V_9 * V_10 = F_91 ( V_228 ) ;
F_12 ( V_10 , L_106 , V_123 ) ;
F_92 ( & V_10 -> V_20 ) ;
F_93 ( V_10 -> V_19 ) ;
#ifdef F_94
F_95 ( V_229 , NULL ) ;
#endif
if ( V_10 -> V_2 )
F_74 ( V_10 ) ;
if ( V_10 -> V_230 )
F_96 ( V_228 -> V_210 , V_10 ) ;
if ( V_10 -> V_2 )
F_97 ( V_10 -> V_2 ) ;
if ( V_10 -> V_231 )
F_98 ( F_99 ( V_228 , 0 ) ,
F_100 ( V_228 , 0 ) ) ;
if ( V_10 -> V_232 )
F_101 ( V_228 ) ;
V_10 -> V_2 = NULL ;
F_86 ( V_10 , L_119 ) ;
}
static int F_102 ( struct V_227 * V_228 , const struct V_233 * V_234 )
{
struct V_9 * V_10 = NULL ;
unsigned long V_235 , V_236 ;
void T_1 * V_237 = NULL ;
int V_131 ;
if ( ! V_228 -> V_210 ) {
F_103 ( V_238 L_120 , F_104 ( V_228 ) ) ;
V_131 = - V_62 ;
goto V_239;
}
V_10 = F_22 ( sizeof *V_10 , V_240 ) ;
if ( V_10 == NULL ) {
F_105 ( L_121 , F_104 ( V_228 ) ) ;
V_131 = - V_241 ;
goto V_239;
}
F_106 ( & V_10 -> V_38 ) ;
V_10 -> V_228 = V_228 ;
V_10 -> V_20 . V_163 = & V_242 ;
V_10 -> V_20 . V_243 = V_178 ;
V_10 -> V_20 . V_37 = V_244 ;
V_131 = F_107 ( V_228 ) ;
if ( V_131 < 0 ) {
F_12 ( V_10 , L_122 , V_131 ) ;
goto V_239;
}
V_10 -> V_232 = 1 ;
V_235 = F_99 ( V_228 , 0 ) ;
V_236 = F_100 ( V_228 , 0 ) ;
if ( ! F_108 ( V_235 , V_236 , V_244 ) ) {
F_12 ( V_10 , L_123 ) ;
V_131 = - V_30 ;
goto V_239;
}
V_10 -> V_231 = 1 ;
V_237 = F_109 ( V_235 , V_236 ) ;
if ( V_237 == NULL ) {
F_12 ( V_10 , L_124 ) ;
V_131 = - V_245 ;
goto V_239;
}
V_10 -> V_2 = (struct V_1 T_1 * ) V_237 ;
F_110 ( V_228 , V_10 ) ;
F_86 ( V_10 , L_106 , V_246 ) ;
F_86 ( V_10 , L_125 V_247 L_126 , F_62 () ) ;
F_86 ( V_10 , L_127 , V_228 -> V_210 , V_237 ) ;
F_74 ( V_10 ) ;
F_73 ( V_10 ) ;
if ( F_111 ( V_228 -> V_210 , F_84 , V_248 ,
V_244 , V_10 ) != 0 ) {
F_12 ( V_10 , L_128 , V_228 -> V_210 ) ;
V_131 = - V_30 ;
goto V_239;
}
V_10 -> V_230 = 1 ;
if ( V_34 )
F_112 ( V_228 ) ;
#ifdef F_94
F_113 ( V_229 , 0 , NULL , & V_249 , V_10 ) ;
#endif
V_131 = F_114 ( & V_228 -> V_10 , & V_10 -> V_20 ,
F_88 ) ;
if ( V_131 )
goto V_239;
return 0 ;
V_239:
if ( V_10 )
F_90 ( V_228 ) ;
return V_131 ;
}
