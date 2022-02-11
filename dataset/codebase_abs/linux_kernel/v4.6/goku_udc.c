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
static struct V_5 * F_62 ( struct V_136 * V_138 ,
struct V_7 * V_8 ,
struct V_139 * V_140 )
{
struct V_9 * V_10 = F_63 ( V_138 ) ;
struct V_5 * V_12 ;
switch ( F_8 ( V_8 ) ) {
case V_26 :
V_12 = & V_10 -> V_12 [ 3 ] . V_12 ;
if ( F_64 ( V_138 , V_12 , V_8 , V_140 ) )
return V_12 ;
break;
case V_25 :
if ( F_11 ( V_8 ) ) {
V_12 = & V_10 -> V_12 [ 2 ] . V_12 ;
if ( F_64 ( V_138 , V_12 , V_8 , V_140 ) )
return V_12 ;
}
break;
default:
;
}
return NULL ;
}
static inline const char * F_65 ( void )
{
if ( V_34 == 0 )
return L_26 ;
else if ( V_34 == 2 )
return L_27 ;
else
return L_28 ;
}
static void F_66 ( struct V_141 * V_142 , const char * V_143 , T_2 V_144 )
{
F_67 (m, L_29 FOURBITS EIGHTBITS EIGHTBITS L_30 ,
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
static const char * F_68 ( enum V_63 V_145 )
{
switch ( V_145 ) {
case V_146 :
return L_51 ;
case V_147 :
return L_52 ;
case V_80 :
return L_53 ;
case V_93 :
return L_54 ;
case V_85 :
return L_55 ;
case V_132 :
return L_56 ;
case V_64 :
return L_57 ;
}
return L_58 ;
}
static const char * F_69 ( T_2 V_71 )
{
switch ( V_71 & V_28 ) {
case V_148 :
return L_59 ;
case V_149 :
return L_60 ;
case V_150 :
return L_61 ;
case V_151 :
return L_62 ;
case V_152 :
return L_63 ;
case V_153 :
return L_64 ;
case V_154 :
return L_65 ;
case V_29 :
return L_66 ;
}
return L_67 ;
}
static int F_70 ( struct V_141 * V_142 , void * V_155 )
{
struct V_9 * V_10 = V_142 -> V_156 ;
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
unsigned long V_15 ;
int V_157 , V_158 ;
T_2 V_39 ;
F_71 ( V_15 ) ;
V_39 = F_9 ( & V_2 -> V_159 ) ;
V_158 = V_39 & V_160 ;
F_67 ( V_142 ,
L_68
L_69
L_70
L_71
L_30 ,
F_72 ( V_10 -> V_161 ) , V_162 ,
V_163 , V_164 , F_65 () ,
V_10 -> V_19 ? V_10 -> V_19 -> V_19 . V_37 : L_72 ,
V_158
? ( ( V_39 & V_165 ) ? L_73 : L_74 )
: L_75 ,
F_68 ( V_10 -> V_63 ) ) ;
F_66 ( V_142 , L_76 , F_9 ( & V_2 -> V_82 ) ) ;
F_66 ( V_142 , L_77 , F_9 ( & V_2 -> V_47 ) ) ;
if ( ! V_158 || ! V_10 -> V_19 || ( V_39 & V_165 ) == 0 )
goto F_28;
F_67 ( V_142 , L_78 ,
V_10 -> V_61 , F_9 ( & V_2 -> V_79 ) ,
F_9 ( & V_2 -> V_40 ) , F_9 ( & V_2 -> V_41 ) ,
F_9 ( & V_2 -> V_103 ) ,
F_9 ( & V_2 -> V_166 ) ) ;
if ( F_73 ( V_142 ) )
goto F_28;
V_39 = F_9 ( & V_2 -> V_54 ) ;
F_67 ( V_142 , L_79 V_167 L_25 ,
V_39 ,
( V_39 & V_112 ) ? L_80 : L_11 ,
( V_39 & V_111 ) ? L_81 : L_11 ,
( V_39 & V_116 ) ? L_82 : L_11 ,
( V_39 & V_168 ) ? L_83 : L_11 ,
( V_39 & V_110 ) ? L_84 : L_11 ,
( V_39 & V_59 ) ? L_85 : L_11 ,
( V_39 & V_57 ) ? L_86 : L_11 ,
( V_39 & V_107 ) ? L_87 : L_11 ,
( V_39 & V_113 ) ? L_88 : L_11 ,
( V_39 & V_169 ) ? L_89 : L_90 ) ;
if ( F_73 ( V_142 ) )
goto F_28;
for ( V_157 = 0 ; V_157 < 4 ; V_157 ++ ) {
struct V_11 * V_12 = & V_10 -> V_12 [ V_157 ] ;
struct V_67 * V_68 ;
if ( V_157 && ! V_12 -> V_12 . V_8 )
continue;
V_39 = F_9 ( V_12 -> V_27 ) ;
F_67 ( V_142 , L_91 V_170 L_30 ,
V_12 -> V_12 . V_37 ,
V_12 -> V_32 ? L_92 : L_93 ,
V_12 -> V_12 . V_44 ,
V_12 -> V_33 ? L_5 : L_6 ,
V_12 -> V_61 ,
V_39 , F_69 ( V_39 ) ,
( V_39 & V_171 ) ? L_94 : L_95 ,
( V_39 & V_172 ) ? L_50 : L_11 ,
( V_39 & V_173 ) ? L_96 : L_11 ,
( V_39 & V_174 ) ? L_97 : L_11 ) ;
if ( F_73 ( V_142 ) )
goto F_28;
if ( F_26 ( & V_12 -> V_69 ) ) {
F_74 ( V_142 , L_98 ) ;
if ( F_73 ( V_142 ) )
goto F_28;
continue;
}
F_56 (req, &ep->queue, queue) {
if ( V_12 -> V_33 && V_68 -> V_69 . V_175 == & V_12 -> V_69 ) {
if ( V_157 == V_35 )
V_39 = F_9 ( & V_2 -> V_118 ) ;
else
V_39 = F_9 ( & V_2 -> V_119 ) ;
V_39 -= V_68 -> V_68 . V_33 ;
V_39 ++ ;
} else
V_39 = V_68 -> V_68 . V_73 ;
F_67 ( V_142 , L_99 ,
& V_68 -> V_68 , V_39 , V_68 -> V_68 . V_74 ,
V_68 -> V_68 . V_76 ) ;
if ( F_73 ( V_142 ) )
goto F_28;
}
}
F_28:
F_75 ( V_15 ) ;
return 0 ;
}
static int F_76 ( struct V_176 * V_176 , struct V_177 * V_177 )
{
return F_77 ( V_177 , F_70 , F_78 ( F_79 ( V_177 ) ) ) ;
}
static void F_80 ( struct V_9 * V_10 )
{
static char * V_178 [] = { L_100 , L_101 , L_102 , L_103 } ;
unsigned V_157 ;
F_23 ( & V_10 -> V_20 . V_179 ) ;
V_10 -> V_20 . V_180 = & V_10 -> V_12 [ 0 ] . V_12 ;
V_10 -> V_20 . V_21 = V_22 ;
V_10 -> V_63 = V_146 ;
V_10 -> V_61 = 0 ;
for ( V_157 = 0 ; V_157 < 4 ; V_157 ++ ) {
struct V_11 * V_12 = & V_10 -> V_12 [ V_157 ] ;
V_12 -> V_24 = V_157 ;
V_12 -> V_12 . V_37 = V_178 [ V_157 ] ;
V_12 -> V_83 = & V_10 -> V_2 -> V_181 [ V_157 ] ;
V_12 -> V_27 = & V_10 -> V_2 -> V_182 [ V_157 ] ;
V_12 -> V_42 = & V_10 -> V_2 -> V_183 [ V_157 ] ;
V_12 -> V_12 . V_184 = & V_185 ;
F_54 ( & V_12 -> V_12 . V_179 , & V_10 -> V_20 . V_179 ) ;
V_12 -> V_10 = V_10 ;
F_23 ( & V_12 -> V_69 ) ;
F_15 ( NULL , V_12 ) ;
if ( V_157 == 0 )
V_12 -> V_12 . V_186 . V_187 = true ;
else
V_12 -> V_12 . V_186 . V_188 = true ;
V_12 -> V_12 . V_186 . V_189 = true ;
V_12 -> V_12 . V_186 . V_190 = true ;
}
V_10 -> V_12 [ 0 ] . V_42 = NULL ;
F_17 ( & V_10 -> V_12 [ 0 ] . V_12 , V_191 ) ;
F_29 ( & V_10 -> V_12 [ 0 ] . V_12 . V_179 ) ;
}
static void F_81 ( struct V_9 * V_10 )
{
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
F_2 ( 0 , & V_2 -> V_159 ) ;
F_2 ( 0 , & V_2 -> V_47 ) ;
F_9 ( & V_2 -> V_47 ) ;
V_10 -> V_47 = 0 ;
F_4 ( 250 ) ;
F_2 ( V_192 , & V_2 -> V_159 ) ;
F_9 ( & V_2 -> V_47 ) ;
}
static void F_82 ( struct V_9 * V_10 )
{
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
unsigned V_157 ;
F_19 ( V_10 , L_104 , V_123 ) ;
F_81 ( V_10 ) ;
F_80 ( V_10 ) ;
F_2 ( V_193 | V_194
| V_195 | V_196
| V_197
| V_198
, & V_2 -> V_199 ) ;
for ( V_157 = 0 ; V_157 < 4 ; V_157 ++ )
V_10 -> V_12 [ V_157 ] . V_61 = 0 ;
for ( V_157 = 0 ; V_157 < V_200 ; V_157 ++ )
F_2 ( 0 , & V_2 -> V_201 [ V_157 ] ) ;
F_2 ( 0 , & V_2 -> V_202 ) ;
F_2 ( V_192 | V_165 , & V_2 -> V_159 ) ;
V_10 -> V_47 = V_203 | V_51 ;
F_2 ( V_10 -> V_47 , & V_10 -> V_2 -> V_47 ) ;
F_9 ( & V_2 -> V_47 ) ;
V_10 -> V_20 . V_21 = V_204 ;
V_10 -> V_63 = V_147 ;
}
static void F_83 ( struct V_9 * V_10 )
{
if ( F_9 ( & V_10 -> V_2 -> V_159 ) & V_160 )
F_82 ( V_10 ) ;
else {
F_12 ( V_10 , L_104 , V_123 ) ;
V_10 -> V_47 = V_205 ;
F_2 ( V_10 -> V_47 , & V_10 -> V_2 -> V_47 ) ;
}
}
static int F_84 ( struct V_136 * V_138 ,
struct V_206 * V_19 )
{
struct V_9 * V_10 = F_63 ( V_138 ) ;
V_19 -> V_19 . V_207 = NULL ;
V_10 -> V_19 = V_19 ;
F_83 ( V_10 ) ;
return 0 ;
}
static void F_85 ( struct V_9 * V_10 )
{
unsigned V_157 ;
F_12 ( V_10 , L_104 , V_123 ) ;
F_81 ( V_10 ) ;
for ( V_157 = 0 ; V_157 < 4 ; V_157 ++ )
F_20 ( & V_10 -> V_12 [ V_157 ] , - V_23 ) ;
if ( V_10 -> V_19 )
F_83 ( V_10 ) ;
}
static int F_86 ( struct V_136 * V_138 )
{
struct V_9 * V_10 = F_63 ( V_138 ) ;
unsigned long V_15 ;
F_13 ( & V_10 -> V_38 , V_15 ) ;
V_10 -> V_19 = NULL ;
F_85 ( V_10 ) ;
F_14 ( & V_10 -> V_38 , V_15 ) ;
return 0 ;
}
static void F_87 ( struct V_9 * V_10 )
{
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
struct V_208 V_209 ;
int V_39 ;
V_209 . V_210 = F_9 ( & V_2 -> V_210 ) ;
V_209 . V_211 = F_9 ( & V_2 -> V_211 ) ;
V_209 . V_212 = F_88 ( ( F_9 ( & V_2 -> V_213 ) << 8 )
| F_9 ( & V_2 -> V_214 ) ) ;
V_209 . V_215 = F_88 ( ( F_9 ( & V_2 -> V_216 ) << 8 )
| F_9 ( & V_2 -> V_217 ) ) ;
V_209 . V_218 = F_88 ( ( F_9 ( & V_2 -> V_219 ) << 8 )
| F_9 ( & V_2 -> V_220 ) ) ;
F_2 ( 0 , & V_2 -> V_221 ) ;
F_20 ( & V_10 -> V_12 [ 0 ] , 0 ) ;
V_10 -> V_12 [ 0 ] . V_45 = 0 ;
if ( F_30 ( V_209 . V_210 & V_222 ) ) {
V_10 -> V_12 [ 0 ] . V_32 = 1 ;
V_10 -> V_63 = V_80 ;
F_2 ( V_223 , & V_10 -> V_2 -> V_224 ) ;
} else {
V_10 -> V_12 [ 0 ] . V_32 = 0 ;
V_10 -> V_63 = V_93 ;
switch ( V_209 . V_211 ) {
case V_225 :
switch ( V_209 . V_210 ) {
case V_226 :
V_39 = F_89 ( V_209 . V_215 ) & 0x0f ;
if ( V_39 > 3 ||
( ! V_10 -> V_12 [ V_39 ] . V_12 . V_8 && V_39 != 0 ) )
goto V_227;
if ( V_209 . V_215 & F_88 (
V_222 ) ) {
if ( ! V_10 -> V_12 [ V_39 ] . V_32 )
goto V_227;
} else {
if ( V_10 -> V_12 [ V_39 ] . V_32 )
goto V_227;
}
if ( V_209 . V_212 != F_88 (
V_228 ) )
goto V_227;
if ( V_39 )
F_57 ( & V_10 -> V_12 [ V_39 ] ) ;
V_229:
F_2 ( ~ ( 1 << 0 ) , & V_2 -> V_84 ) ;
V_10 -> V_12 [ 0 ] . V_45 = 1 ;
V_10 -> V_63 = V_85 ;
return;
case V_230 :
if ( V_209 . V_212 != F_88 ( 1 ) )
goto V_227;
F_19 ( V_10 , L_105 ) ;
goto V_229;
case V_231 :
goto V_227;
default:
break;
}
break;
default:
break;
}
}
#ifdef F_32
F_19 ( V_10 , L_106 ,
V_209 . V_210 , V_209 . V_211 ,
F_89 ( V_209 . V_212 ) , F_89 ( V_209 . V_215 ) ,
F_89 ( V_209 . V_218 ) ) ;
#endif
V_10 -> V_100 = ( V_209 . V_211 == V_232
&& V_209 . V_210 == V_230 ) ;
if ( F_40 ( V_10 -> V_100 ) )
V_10 -> V_101 = ( V_209 . V_212 != F_88 ( 0 ) ) ;
F_33 ( & V_10 -> V_38 ) ;
V_39 = V_10 -> V_19 -> V_233 ( & V_10 -> V_20 , & V_209 ) ;
F_35 ( & V_10 -> V_38 ) ;
if ( F_40 ( V_39 < 0 ) ) {
V_227:
#ifdef F_32
F_19 ( V_10 , L_107 ,
V_209 . V_210 , V_209 . V_211 , V_39 ) ;
#endif
F_1 ( V_2 , V_134 , 0 ) ;
V_10 -> V_12 [ 0 ] . V_45 = 1 ;
V_10 -> V_63 = V_132 ;
}
}
static T_6 F_90 ( int V_234 , void * V_235 )
{
struct V_9 * V_10 = V_235 ;
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
T_2 V_236 , V_237 = 0 ;
unsigned V_157 , V_238 = 5 ;
F_35 ( & V_10 -> V_38 ) ;
V_239:
V_236 = F_9 ( & V_2 -> V_82 ) & V_10 -> V_47 ;
if ( ! V_236 )
goto F_28;
V_10 -> V_61 ++ ;
if ( F_40 ( V_236 & V_203 ) ) {
if ( V_236 & V_240 ) {
ERROR ( V_10 , L_108 ) ;
F_85 ( V_10 ) ;
V_236 = 0 ;
V_237 = 1 ;
V_10 -> V_19 = NULL ;
goto F_28;
}
if ( V_236 & V_205 ) {
F_2 ( ~ V_236 , & V_2 -> V_82 ) ;
if ( F_9 ( & V_10 -> V_2 -> V_159 ) & V_160 ) {
F_19 ( V_10 , L_109 ) ;
F_82 ( V_10 ) ;
} else {
F_12 ( V_10 , L_110 ) ;
if ( V_10 -> V_20 . V_21 == V_204 )
F_85 ( V_10 ) ;
V_10 -> V_63 = V_146 ;
V_10 -> V_47 = V_203 ;
F_2 ( V_10 -> V_47 , & V_10 -> V_2 -> V_47 ) ;
}
V_236 = 0 ;
V_237 = 1 ;
goto F_28;
}
if ( V_236 & V_241 ) {
F_91 ( V_241 ) ;
if ( F_9 ( & V_2 -> V_182 [ 0 ] ) & V_172 ) {
switch ( V_10 -> V_63 ) {
case V_146 :
case V_64 :
goto V_242;
default:
break;
}
F_12 ( V_10 , L_111 ) ;
V_10 -> V_63 = V_64 ;
if ( V_10 -> V_20 . V_21 != V_22
&& V_10 -> V_19
&& V_10 -> V_19 -> V_243 ) {
F_33 ( & V_10 -> V_38 ) ;
V_10 -> V_19 -> V_243 ( & V_10 -> V_20 ) ;
F_35 ( & V_10 -> V_38 ) ;
}
} else {
if ( V_10 -> V_63 != V_64 ) {
F_12 ( V_10 , L_112 ,
V_10 -> V_63 ) ;
goto V_242;
}
F_12 ( V_10 , L_113 ) ;
V_10 -> V_63 = V_147 ;
if ( V_10 -> V_20 . V_21 != V_22
&& V_10 -> V_19
&& V_10 -> V_19 -> V_244 ) {
F_33 ( & V_10 -> V_38 ) ;
V_10 -> V_19 -> V_244 ( & V_10 -> V_20 ) ;
F_35 ( & V_10 -> V_38 ) ;
}
}
}
V_242:
if ( V_236 & V_245 ) {
F_91 ( V_245 ) ;
F_92 ( V_10 , L_114 ,
V_10 -> V_19 -> V_19 . V_37 ) ;
}
}
if ( V_236 & V_246 ) {
F_91 ( V_246 ) ;
V_10 -> V_12 [ 0 ] . V_61 ++ ;
F_87 ( V_10 ) ;
}
if ( V_236 & V_247 ) {
F_91 ( V_247 | V_248 ) ;
if ( V_10 -> V_63 == V_80 ) {
V_12 = & V_10 -> V_12 [ 0 ] ;
V_12 -> V_61 ++ ;
F_20 ( V_12 , 0 ) ;
F_2 ( ~ ( 1 << 0 ) , & V_2 -> V_84 ) ;
V_10 -> V_63 = V_85 ;
}
}
if ( V_236 & V_248 ) {
F_91 ( V_248 ) ;
V_12 = & V_10 -> V_12 [ 0 ] ;
V_12 -> V_61 ++ ;
F_48 ( V_12 ) ;
}
if ( V_236 & V_50 ) {
F_91 ( V_50 ) ;
V_12 = & V_10 -> V_12 [ V_35 ] ;
V_12 -> V_61 ++ ;
F_50 ( V_10 , V_12 ) ;
}
if ( V_236 & V_48 ) {
F_91 ( V_48 ) ;
V_12 = & V_10 -> V_12 [ V_36 ] ;
V_12 -> V_61 ++ ;
F_50 ( V_10 , V_12 ) ;
}
if ( V_236 & V_49 ) {
F_91 ( V_49 ) ;
V_12 = & V_10 -> V_12 [ V_36 ] ;
V_12 -> V_61 ++ ;
ERROR ( V_10 , L_115 , V_12 -> V_12 . V_37 ) ;
}
for ( V_157 = 1 ; V_157 < 4 ; V_157 ++ ) {
T_2 V_39 = F_16 ( V_157 ) ;
if ( ! ( V_236 & V_39 ) )
continue;
V_12 = & V_10 -> V_12 [ V_157 ] ;
F_48 ( V_12 ) ;
if ( F_26 ( & V_12 -> V_69 ) )
F_47 ( V_10 , V_2 , V_157 ) ;
V_236 &= ~ V_39 ;
V_237 = 1 ;
V_12 -> V_61 ++ ;
}
if ( V_238 -- )
goto V_239;
F_28:
( void ) F_9 ( & V_2 -> V_47 ) ;
F_33 ( & V_10 -> V_38 ) ;
if ( V_236 )
F_12 ( V_10 , L_116 , V_236 ,
F_9 ( & V_2 -> V_82 ) , V_10 -> V_47 ) ;
return F_93 ( V_237 ) ;
}
static void F_94 ( struct V_249 * V_235 )
{
struct V_9 * V_10 = F_95 ( V_235 ) ;
F_27 ( V_10 ) ;
}
static void F_96 ( struct V_250 * V_161 )
{
struct V_9 * V_10 = F_97 ( V_161 ) ;
F_12 ( V_10 , L_104 , V_123 ) ;
F_98 ( & V_10 -> V_20 ) ;
F_99 ( V_10 -> V_19 ) ;
#ifdef F_100
F_101 ( V_251 , NULL ) ;
#endif
if ( V_10 -> V_2 )
F_81 ( V_10 ) ;
if ( V_10 -> V_252 )
F_102 ( V_161 -> V_234 , V_10 ) ;
if ( V_10 -> V_2 )
F_103 ( V_10 -> V_2 ) ;
if ( V_10 -> V_253 )
F_104 ( F_105 ( V_161 , 0 ) ,
F_106 ( V_161 , 0 ) ) ;
if ( V_10 -> V_254 )
F_107 ( V_161 ) ;
V_10 -> V_2 = NULL ;
F_92 ( V_10 , L_117 ) ;
}
static int F_108 ( struct V_250 * V_161 , const struct V_255 * V_256 )
{
struct V_9 * V_10 = NULL ;
unsigned long V_257 , V_258 ;
void T_1 * V_259 = NULL ;
int V_131 ;
if ( ! V_161 -> V_234 ) {
F_109 ( V_260 L_118 , F_72 ( V_161 ) ) ;
V_131 = - V_62 ;
goto V_261;
}
V_10 = F_22 ( sizeof *V_10 , V_262 ) ;
if ( V_10 == NULL ) {
F_110 ( L_119 , F_72 ( V_161 ) ) ;
V_131 = - V_263 ;
goto V_261;
}
F_111 ( & V_10 -> V_38 ) ;
V_10 -> V_161 = V_161 ;
V_10 -> V_20 . V_184 = & V_264 ;
V_10 -> V_20 . V_265 = V_204 ;
V_10 -> V_20 . V_37 = V_163 ;
V_131 = F_112 ( V_161 ) ;
if ( V_131 < 0 ) {
F_12 ( V_10 , L_120 , V_131 ) ;
goto V_261;
}
V_10 -> V_254 = 1 ;
V_257 = F_105 ( V_161 , 0 ) ;
V_258 = F_106 ( V_161 , 0 ) ;
if ( ! F_113 ( V_257 , V_258 , V_163 ) ) {
F_12 ( V_10 , L_121 ) ;
V_131 = - V_30 ;
goto V_261;
}
V_10 -> V_253 = 1 ;
V_259 = F_114 ( V_257 , V_258 ) ;
if ( V_259 == NULL ) {
F_12 ( V_10 , L_122 ) ;
V_131 = - V_266 ;
goto V_261;
}
V_10 -> V_2 = (struct V_1 T_1 * ) V_259 ;
F_115 ( V_161 , V_10 ) ;
F_92 ( V_10 , L_104 , V_162 ) ;
F_92 ( V_10 , L_123 V_164 L_124 , F_65 () ) ;
F_92 ( V_10 , L_125 , V_161 -> V_234 , V_259 ) ;
F_81 ( V_10 ) ;
F_80 ( V_10 ) ;
if ( F_116 ( V_161 -> V_234 , F_90 , V_267 ,
V_163 , V_10 ) != 0 ) {
F_12 ( V_10 , L_126 , V_161 -> V_234 ) ;
V_131 = - V_30 ;
goto V_261;
}
V_10 -> V_252 = 1 ;
if ( V_34 )
F_117 ( V_161 ) ;
#ifdef F_100
F_118 ( V_251 , 0 , NULL , & V_268 , V_10 ) ;
#endif
V_131 = F_119 ( & V_161 -> V_10 , & V_10 -> V_20 ,
F_94 ) ;
if ( V_131 )
goto V_261;
return 0 ;
V_261:
if ( V_10 )
F_96 ( V_161 ) ;
return V_131 ;
}
