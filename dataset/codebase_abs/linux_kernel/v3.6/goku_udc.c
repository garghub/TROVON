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
V_12 -> V_12 . V_44 = V_60 ;
V_12 -> V_12 . V_8 = NULL ;
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
if ( ! V_6 || ! V_12 -> V_12 . V_8 )
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
if ( V_12 -> V_33 )
F_30 ( & V_10 -> V_20 , & V_68 -> V_68 , V_12 -> V_32 ) ;
#ifndef F_31
if ( V_72 && V_72 != - V_23 )
#endif
F_18 ( V_10 , L_8 ,
V_12 -> V_12 . V_37 , & V_68 -> V_68 , V_72 ,
V_68 -> V_68 . V_74 , V_68 -> V_68 . V_75 ) ;
V_12 -> V_45 = 1 ;
F_32 ( & V_10 -> V_38 ) ;
V_68 -> V_68 . V_76 ( & V_12 -> V_12 , & V_68 -> V_68 ) ;
F_33 ( & V_10 -> V_38 ) ;
V_12 -> V_45 = V_45 ;
}
static inline int
F_34 ( T_2 T_1 * V_77 , T_5 * V_78 , struct V_67 * V_68 , unsigned V_14 )
{
unsigned V_75 , V_79 ;
V_75 = F_35 ( V_68 -> V_68 . V_75 - V_68 -> V_68 . V_74 , V_14 ) ;
V_68 -> V_68 . V_74 += V_75 ;
V_79 = V_75 ;
while ( F_29 ( V_79 -- ) )
F_2 ( * V_78 ++ , V_77 ) ;
return V_75 ;
}
static int F_36 ( struct V_11 * V_12 , struct V_67 * V_68 )
{
struct V_9 * V_10 = V_12 -> V_10 ;
T_2 V_39 ;
T_5 * V_78 ;
unsigned V_79 ;
int V_80 ;
V_39 = F_9 ( & V_10 -> V_2 -> V_81 ) ;
V_78 = V_68 -> V_68 . V_78 + V_68 -> V_68 . V_74 ;
F_37 ( V_78 ) ;
V_10 = V_12 -> V_10 ;
if ( F_38 ( V_12 -> V_24 == 0 && V_10 -> V_63 != V_82 ) )
return - V_83 ;
if ( F_38 ( ( V_39 & F_39 ( V_12 -> V_24 ) ) != 0 ) )
return 0 ;
if ( V_12 -> V_24 != 0 )
F_2 ( ~ F_16 ( V_12 -> V_24 ) , & V_10 -> V_2 -> V_84 ) ;
V_79 = F_34 ( V_12 -> V_85 , V_78 , V_68 , V_12 -> V_12 . V_44 ) ;
if ( F_38 ( V_79 != V_12 -> V_12 . V_44 ) ) {
F_2 ( ~ ( 1 << V_12 -> V_24 ) , & V_10 -> V_2 -> V_86 ) ;
if ( V_12 -> V_24 == 0 ) {
V_10 -> V_12 [ 0 ] . V_45 = 1 ;
V_10 -> V_63 = V_87 ;
}
V_80 = 1 ;
} else {
if ( F_29 ( V_68 -> V_68 . V_75 != V_68 -> V_68 . V_74 )
|| V_68 -> V_68 . V_88 )
V_80 = 0 ;
else
V_80 = 1 ;
}
#if 0
VDBG(dev, "wrote %s %u bytes%s IN %u left %p\n",
ep->ep.name, count, is_last ? "/last" : "",
req->req.length - req->req.actual, req);
#endif
if ( V_80 ) {
F_27 ( V_12 , V_68 , 0 ) ;
return 1 ;
}
return 0 ;
}
static int F_40 ( struct V_11 * V_12 , struct V_67 * V_68 )
{
struct V_1 T_1 * V_2 ;
T_2 V_89 , V_90 ;
T_5 * V_78 ;
unsigned V_91 , V_92 , V_93 ;
V_2 = V_12 -> V_10 -> V_2 ;
V_94:
V_78 = V_68 -> V_68 . V_78 + V_68 -> V_68 . V_74 ;
F_41 ( V_78 ) ;
if ( F_38 ( V_12 -> V_24 == 0 && V_12 -> V_10 -> V_63 != V_95 ) )
return - V_83 ;
V_93 = ( V_12 -> V_24 == 1 || V_12 -> V_24 == 2 ) ;
do {
if ( V_12 -> V_24 != 0 )
F_2 ( ~ F_16 ( V_12 -> V_24 ) , & V_2 -> V_84 ) ;
V_90 = F_9 ( & V_2 -> V_81 ) & F_42 ( V_12 -> V_24 ) ;
V_89 = F_9 ( & V_2 -> V_96 [ V_12 -> V_24 ] ) ;
V_91 = V_68 -> V_68 . V_75 - V_68 -> V_68 . V_74 ;
if ( F_29 ( V_12 -> V_24 != 0 || V_91 != 0 ) ) {
if ( F_38 ( V_90 == 0 ) )
break;
if ( ! ( V_89 & V_97 ) )
V_89 = F_9 ( & V_2 -> V_98 [ V_12 -> V_24 ] ) ;
if ( ! ( V_89 & V_97 ) )
break;
V_89 &= V_99 ;
} else
V_89 = 0 ;
V_68 -> V_68 . V_74 += V_89 ;
V_92 = ( V_89 < V_12 -> V_12 . V_44 ) ;
#ifdef F_31
F_18 ( V_12 -> V_10 , L_9 ,
V_12 -> V_12 . V_37 , V_89 , V_92 ? L_10 : L_11 ,
V_68 , V_68 -> V_68 . V_74 , V_68 -> V_68 . V_75 ) ;
#endif
while ( F_29 ( V_89 -- != 0 ) ) {
T_5 V_100 = ( T_5 ) F_9 ( V_12 -> V_85 ) ;
if ( F_38 ( V_91 == 0 ) ) {
if ( V_68 -> V_68 . V_72 != - V_101 )
F_12 ( V_12 -> V_10 , L_12 ,
V_12 -> V_12 . V_37 , V_89 ) ;
V_68 -> V_68 . V_72 = - V_101 ;
} else {
* V_78 ++ = V_100 ;
V_91 -- ;
}
}
if ( F_38 ( V_92 || V_68 -> V_68 . V_74 == V_68 -> V_68 . V_75 ) ) {
if ( F_38 ( V_12 -> V_24 == 0 ) ) {
if ( V_12 -> V_10 -> V_102 )
F_2 ( V_12 -> V_10 -> V_103
? V_104
: 0 ,
& V_2 -> V_105 ) ;
F_2 ( ~ ( 1 << 0 ) , & V_2 -> V_86 ) ;
V_12 -> V_45 = 1 ;
V_12 -> V_10 -> V_63 = V_87 ;
}
F_27 ( V_12 , V_68 , 0 ) ;
if ( V_93 && ! F_25 ( & V_12 -> V_70 ) ) {
V_68 = F_43 ( V_12 -> V_70 . V_106 ,
struct V_67 , V_70 ) ;
goto V_94;
}
return 1 ;
}
} while ( V_93 );
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
V_68 = F_43 ( V_12 -> V_70 . V_106 , struct V_67 , V_70 ) ;
( V_12 -> V_32 ? F_36 : F_40 ) ( V_12 , V_68 ) ;
}
static int F_47 ( struct V_11 * V_12 , struct V_67 * V_68 )
{
struct V_1 T_1 * V_2 = V_12 -> V_10 -> V_2 ;
T_2 V_53 ;
T_2 V_107 = V_68 -> V_68 . V_33 ;
T_2 V_108 = V_107 + V_68 -> V_68 . V_75 - 1 ;
V_53 = F_9 ( & V_2 -> V_54 ) & V_55 ;
if ( F_29 ( V_12 -> V_32 ) ) {
if ( F_38 ( V_53 & V_109 ) ) {
F_12 ( V_12 -> V_10 , L_13 ,
V_53 ) ;
}
F_2 ( V_108 , & V_2 -> V_110 ) ;
F_2 ( V_107 , & V_2 -> V_111 ) ;
V_53 &= ~ V_58 ;
if ( F_38 ( V_68 -> V_68 . V_75 == 0 ) )
V_53 = V_109 | V_112 ;
else if ( ( V_68 -> V_68 . V_75 % V_12 -> V_12 . V_44 ) != 0
|| V_68 -> V_68 . V_88 )
V_53 = V_109 | V_113 ;
else
V_53 = V_109 | V_114 ;
V_12 -> V_10 -> V_47 |= V_50 ;
} else {
if ( F_38 ( V_53 & V_115 ) ) {
F_12 ( V_12 -> V_10 , L_14 ,
V_53 ) ;
}
F_2 ( V_108 , & V_2 -> V_116 ) ;
F_2 ( V_107 , & V_2 -> V_117 ) ;
V_53 &= ~ V_56 ;
V_53 |= V_115 | V_118 ;
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
V_119:
if ( V_12 -> V_32 )
V_10 -> V_47 &= ~ V_50 ;
else
V_10 -> V_47 &= ~ ( V_48 | V_49 ) ;
F_2 ( V_10 -> V_47 , & V_2 -> V_47 ) ;
return;
}
V_68 = F_43 ( V_12 -> V_70 . V_106 , struct V_67 , V_70 ) ;
if ( F_29 ( V_12 -> V_32 ) ) {
if ( F_38 ( V_53 & V_109 ) )
return;
V_68 -> V_68 . V_74 = F_9 ( & V_2 -> V_120 ) ;
} else {
if ( F_38 ( V_53 & V_115 ) )
return;
V_68 -> V_68 . V_74 = F_9 ( & V_2 -> V_121 ) ;
}
V_68 -> V_68 . V_74 -= V_68 -> V_68 . V_33 ;
V_68 -> V_68 . V_74 ++ ;
#ifdef F_31
F_18 ( V_10 , L_15 ,
V_12 -> V_12 . V_37 , V_12 -> V_32 ? L_3 : L_4 ,
V_68 -> V_68 . V_74 , V_68 -> V_68 . V_75 , V_68 ) ;
#endif
F_27 ( V_12 , V_68 , 0 ) ;
if ( F_25 ( & V_12 -> V_70 ) )
goto V_119;
V_68 = F_43 ( V_12 -> V_70 . V_106 , struct V_67 , V_70 ) ;
( void ) F_47 ( V_12 , V_68 ) ;
}
static void F_49 ( struct V_11 * V_12 , int V_72 )
{
struct V_1 T_1 * V_2 = V_12 -> V_10 -> V_2 ;
struct V_67 * V_68 ;
T_2 V_122 , V_53 ;
F_1 ( V_2 , V_123 , V_12 -> V_24 ) ;
V_68 = F_43 ( V_12 -> V_70 . V_106 , struct V_67 , V_70 ) ;
V_53 = F_9 ( & V_2 -> V_54 ) & V_55 ;
if ( V_12 -> V_32 ) {
if ( F_38 ( ( F_9 ( & V_2 -> V_54 ) & V_109 ) == 0 ) )
goto V_124;
V_122 = F_9 ( & V_2 -> V_120 ) ;
F_2 ( V_122 , & V_2 -> V_110 ) ;
F_2 ( V_122 , & V_2 -> V_111 ) ;
V_53 &= ~ V_58 ;
V_53 |= V_59 ;
F_2 ( V_53 , & V_2 -> V_54 ) ;
if ( F_9 ( & V_2 -> V_54 ) & V_109 )
F_12 ( V_12 -> V_10 , L_16 ) ;
} else {
if ( F_38 ( ( F_9 ( & V_2 -> V_54 ) & V_115 ) == 0 ) )
goto V_124;
V_122 = F_9 ( & V_2 -> V_121 ) ;
F_2 ( V_122 , & V_2 -> V_116 ) ;
F_2 ( V_122 , & V_2 -> V_117 ) ;
V_53 &= ~ V_56 ;
V_53 |= V_57 ;
F_2 ( V_53 , & V_2 -> V_54 ) ;
if ( F_9 ( & V_2 -> V_54 ) & V_115 )
F_12 ( V_12 -> V_10 , L_17 ) ;
}
V_68 -> V_68 . V_74 = ( V_122 - V_68 -> V_68 . V_33 ) + 1 ;
V_68 -> V_68 . V_72 = V_72 ;
F_18 ( V_12 -> V_10 , L_18 , V_125 , V_12 -> V_12 . V_37 ,
V_12 -> V_32 ? L_3 : L_4 ,
V_68 -> V_68 . V_74 , V_68 -> V_68 . V_75 ) ;
F_1 ( V_2 , V_126 , V_12 -> V_24 ) ;
return;
V_124:
F_1 ( V_2 , V_126 , V_12 -> V_24 ) ;
V_68 -> V_68 . V_74 = V_68 -> V_68 . V_75 ;
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
if ( F_38 ( ! V_71 || ! V_71 -> V_76
|| ! V_71 -> V_78 || ! F_25 ( & V_68 -> V_70 ) ) )
return - V_18 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( F_38 ( ! V_6 || ( ! V_12 -> V_12 . V_8 && V_12 -> V_24 != 0 ) ) )
return - V_18 ;
V_10 = V_12 -> V_10 ;
if ( F_38 ( ! V_10 -> V_19 || V_10 -> V_20 . V_21 == V_22 ) )
return - V_23 ;
if ( V_10 -> V_63 == V_64 )
return - V_30 ;
if ( V_12 -> V_33 ) {
V_72 = F_51 ( & V_10 -> V_20 , & V_68 -> V_68 ,
V_12 -> V_32 ) ;
if ( V_72 )
return V_72 ;
}
#ifdef F_31
F_18 ( V_10 , L_19 ,
V_6 -> V_37 , V_71 , V_71 -> V_75 , V_71 -> V_78 ) ;
#endif
F_13 ( & V_10 -> V_38 , V_15 ) ;
V_71 -> V_72 = - V_73 ;
V_71 -> V_74 = 0 ;
if ( F_38 ( V_12 -> V_24 == 0 && V_12 -> V_32 ) )
V_71 -> V_88 = 1 ;
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
V_68 = F_43 ( V_12 -> V_70 . V_106 , struct V_67 , V_70 ) ;
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
if ( ! V_6 || ! V_71 || ( ! V_12 -> V_12 . V_8 && V_12 -> V_24 != 0 ) )
return - V_18 ;
V_10 = V_12 -> V_10 ;
if ( ! V_10 -> V_19 )
return - V_23 ;
if ( V_10 -> V_63 == V_64 )
return - V_30 ;
F_18 ( V_10 , L_20 , V_125 , V_6 -> V_37 ,
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
if ( V_12 -> V_33 && V_12 -> V_70 . V_106 == & V_68 -> V_70 && ! V_12 -> V_45 ) {
F_49 ( V_12 , - V_127 ) ;
F_27 ( V_12 , V_68 , - V_127 ) ;
F_48 ( V_10 , V_12 ) ;
} else if ( ! F_25 ( & V_68 -> V_70 ) )
F_27 ( V_12 , V_68 , - V_127 ) ;
else
V_68 = NULL ;
F_14 ( & V_10 -> V_38 , V_15 ) ;
return V_68 ? 0 : - V_128 ;
}
static void F_55 ( struct V_11 * V_12 )
{
F_18 ( V_12 -> V_10 , L_21 , V_12 -> V_12 . V_37 ) ;
F_1 ( V_12 -> V_10 -> V_2 , V_129 , V_12 -> V_24 ) ;
F_1 ( V_12 -> V_10 -> V_2 , V_130 , V_12 -> V_24 ) ;
if ( V_12 -> V_45 ) {
V_12 -> V_45 = 0 ;
if ( V_12 -> V_33 ) {
struct V_67 * V_68 ;
if ( F_25 ( & V_12 -> V_70 ) )
return;
V_68 = F_43 ( V_12 -> V_70 . V_106 , struct V_67 ,
V_70 ) ;
( void ) F_47 ( V_12 , V_68 ) ;
} else
F_46 ( V_12 ) ;
}
}
static int F_56 ( struct V_5 * V_6 , int V_131 )
{
struct V_11 * V_12 ;
unsigned long V_15 ;
int V_132 = 0 ;
if ( ! V_6 )
return - V_62 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( V_12 -> V_24 == 0 ) {
if ( V_131 ) {
V_12 -> V_10 -> V_63 = V_133 ;
V_12 -> V_10 -> V_12 [ 0 ] . V_45 = 1 ;
} else
return - V_18 ;
} else if ( ! V_12 -> V_12 . V_8 ) {
F_12 ( V_12 -> V_10 , L_22 , V_125 , V_12 -> V_12 . V_37 ) ;
return - V_18 ;
}
F_13 ( & V_12 -> V_10 -> V_38 , V_15 ) ;
if ( ! F_25 ( & V_12 -> V_70 ) )
V_132 = - V_134 ;
else if ( V_12 -> V_32 && V_131
&& ( F_9 ( & V_12 -> V_10 -> V_2 -> V_81 )
& F_42 ( V_12 -> V_24 ) ) )
V_132 = - V_134 ;
else if ( ! V_131 )
F_55 ( V_12 ) ;
else {
V_12 -> V_45 = 1 ;
F_18 ( V_12 -> V_10 , L_23 , V_12 -> V_12 . V_37 ) ;
F_1 ( V_12 -> V_10 -> V_2 , V_135 , V_12 -> V_24 ) ;
F_9 ( V_12 -> V_27 ) ;
}
F_14 ( & V_12 -> V_10 -> V_38 , V_15 ) ;
return V_132 ;
}
static int F_57 ( struct V_5 * V_6 )
{
struct V_11 * V_12 ;
struct V_1 T_1 * V_2 ;
T_2 V_89 ;
if ( ! V_6 )
return - V_62 ;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
if ( V_12 -> V_32 )
return - V_128 ;
V_2 = V_12 -> V_10 -> V_2 ;
V_89 = F_9 ( & V_2 -> V_96 [ V_12 -> V_24 ] ) & V_99 ;
V_89 += F_9 ( & V_2 -> V_98 [ V_12 -> V_24 ] ) & V_99 ;
F_18 ( V_12 -> V_10 , L_24 , V_125 , V_12 -> V_12 . V_37 , V_89 ) ;
return V_89 ;
}
static void F_58 ( struct V_5 * V_6 )
{
struct V_11 * V_12 ;
struct V_1 T_1 * V_2 ;
T_2 V_89 ;
if ( ! V_6 )
return;
V_12 = F_6 ( V_6 , struct V_11 , V_12 ) ;
F_18 ( V_12 -> V_10 , L_25 , V_125 , V_12 -> V_12 . V_37 ) ;
if ( ! V_12 -> V_12 . V_8 && V_12 -> V_24 != 0 ) {
F_12 ( V_12 -> V_10 , L_22 , V_125 , V_12 -> V_12 . V_37 ) ;
return;
}
V_2 = V_12 -> V_10 -> V_2 ;
V_89 = F_9 ( & V_2 -> V_96 [ V_12 -> V_24 ] ) ;
V_89 &= V_99 ;
if ( V_89 )
F_1 ( V_2 , V_136 , V_12 -> V_24 ) ;
}
static int F_59 ( struct V_137 * V_138 )
{
return - V_128 ;
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
F_61 ( const char * V_139 , T_2 V_140 , char * * V_106 , unsigned * V_89 )
{
int V_141 ;
V_141 = F_62 (*next, *size,
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
* V_89 -= V_141 ;
* V_106 += V_141 ;
}
static int
F_63 ( char * V_142 , char * * V_107 , T_6 V_143 , int V_79 ,
int * V_144 , void * V_145 )
{
char * V_78 = V_142 ;
struct V_9 * V_10 = V_145 ;
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
char * V_106 = V_78 ;
unsigned V_89 = V_79 ;
unsigned long V_15 ;
int V_146 , V_141 , V_147 ;
T_2 V_39 ;
if ( V_143 != 0 )
return 0 ;
F_64 ( V_15 ) ;
V_39 = F_9 ( & V_2 -> V_148 ) ;
V_147 = V_39 & V_149 ;
V_141 = F_62 (next, size,
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
V_89 -= V_141 ;
V_106 += V_141 ;
F_61 ( L_67 , F_9 ( & V_2 -> V_84 ) , & V_106 , & V_89 ) ;
F_61 ( L_68 , F_9 ( & V_2 -> V_47 ) , & V_106 , & V_89 ) ;
if ( ! V_147 || ! V_10 -> V_19 || ( V_39 & V_150 ) == 0 )
goto F_27;
V_141 = F_62 ( V_106 , V_89 , L_69
L_70 ,
V_10 -> V_61 , F_9 ( & V_2 -> V_81 ) ,
F_9 ( & V_2 -> V_40 ) , F_9 ( & V_2 -> V_41 ) ,
F_9 ( & V_2 -> V_105 ) ,
F_9 ( & V_2 -> V_151 ) ) ;
V_89 -= V_141 ;
V_106 += V_141 ;
V_39 = F_9 ( & V_2 -> V_54 ) ;
V_141 = F_62 ( V_106 , V_89 ,
L_71 V_152 L_25 , V_39 ,
( V_39 & V_114 ) ? L_72 : L_11 ,
( V_39 & V_113 ) ? L_73 : L_11 ,
( V_39 & V_118 ) ? L_74 : L_11 ,
( V_39 & V_153 ) ? L_75 : L_11 ,
( V_39 & V_112 ) ? L_76 : L_11 ,
( V_39 & V_59 ) ? L_77 : L_11 ,
( V_39 & V_57 ) ? L_78 : L_11 ,
( V_39 & V_109 ) ? L_79 : L_11 ,
( V_39 & V_115 ) ? L_80 : L_11 ,
( V_39 & V_154 )
? L_81
: L_82 ) ;
V_89 -= V_141 ;
V_106 += V_141 ;
for ( V_146 = 0 ; V_146 < 4 ; V_146 ++ ) {
struct V_11 * V_12 = & V_10 -> V_12 [ V_146 ] ;
struct V_67 * V_68 ;
if ( V_146 && ! V_12 -> V_12 . V_8 )
continue;
V_39 = F_9 ( V_12 -> V_27 ) ;
V_141 = F_62 (next, size,
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
if ( V_141 <= 0 || V_141 > V_89 )
goto F_27;
V_89 -= V_141 ;
V_106 += V_141 ;
if ( F_25 ( & V_12 -> V_70 ) ) {
V_141 = F_62 ( V_106 , V_89 , L_100 ) ;
if ( V_141 <= 0 || V_141 > V_89 )
goto F_27;
V_89 -= V_141 ;
V_106 += V_141 ;
continue;
}
F_54 (req, &ep->queue, queue) {
if ( V_12 -> V_33 && V_68 -> V_70 . V_155 == & V_12 -> V_70 ) {
if ( V_146 == V_35 )
V_39 = F_9 ( & V_2 -> V_120 ) ;
else
V_39 = F_9 ( & V_2 -> V_121 ) ;
V_39 -= V_68 -> V_68 . V_33 ;
V_39 ++ ;
} else
V_39 = V_68 -> V_68 . V_74 ;
V_141 = F_62 ( V_106 , V_89 ,
L_101 ,
& V_68 -> V_68 , V_39 , V_68 -> V_68 . V_75 ,
V_68 -> V_68 . V_78 ) ;
if ( V_141 <= 0 || V_141 > V_89 )
goto F_27;
V_89 -= V_141 ;
V_106 += V_141 ;
}
}
F_27:
F_65 ( V_15 ) ;
* V_144 = 1 ;
return V_79 - V_89 ;
}
static void F_66 ( struct V_9 * V_10 )
{
static char * V_156 [] = { L_102 , L_103 , L_104 , L_105 } ;
unsigned V_146 ;
F_22 ( & V_10 -> V_20 . V_157 ) ;
V_10 -> V_20 . V_158 = & V_10 -> V_12 [ 0 ] . V_12 ;
V_10 -> V_20 . V_21 = V_22 ;
V_10 -> V_63 = V_159 ;
V_10 -> V_61 = 0 ;
for ( V_146 = 0 ; V_146 < 4 ; V_146 ++ ) {
struct V_11 * V_12 = & V_10 -> V_12 [ V_146 ] ;
V_12 -> V_24 = V_146 ;
V_12 -> V_12 . V_37 = V_156 [ V_146 ] ;
V_12 -> V_85 = & V_10 -> V_2 -> V_160 [ V_146 ] ;
V_12 -> V_27 = & V_10 -> V_2 -> V_161 [ V_146 ] ;
V_12 -> V_42 = & V_10 -> V_2 -> V_162 [ V_146 ] ;
V_12 -> V_12 . V_163 = & V_164 ;
F_52 ( & V_12 -> V_12 . V_157 , & V_10 -> V_20 . V_157 ) ;
V_12 -> V_10 = V_10 ;
F_22 ( & V_12 -> V_70 ) ;
F_15 ( NULL , V_12 ) ;
}
V_10 -> V_12 [ 0 ] . V_42 = NULL ;
V_10 -> V_12 [ 0 ] . V_12 . V_44 = V_165 ;
F_28 ( & V_10 -> V_12 [ 0 ] . V_12 . V_157 ) ;
}
static void F_67 ( struct V_9 * V_10 )
{
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
F_2 ( 0 , & V_2 -> V_148 ) ;
F_2 ( 0 , & V_2 -> V_47 ) ;
F_9 ( & V_2 -> V_47 ) ;
V_10 -> V_47 = 0 ;
F_4 ( 250 ) ;
F_2 ( V_166 , & V_2 -> V_148 ) ;
F_9 ( & V_2 -> V_47 ) ;
}
static void F_68 ( struct V_9 * V_10 )
{
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
unsigned V_146 ;
F_18 ( V_10 , L_106 , V_125 ) ;
F_67 ( V_10 ) ;
F_66 ( V_10 ) ;
F_2 ( V_167 | V_168
| V_169 | V_170
| V_171
| V_172
, & V_2 -> V_173 ) ;
for ( V_146 = 0 ; V_146 < 4 ; V_146 ++ )
V_10 -> V_12 [ V_146 ] . V_61 = 0 ;
for ( V_146 = 0 ; V_146 < V_174 ; V_146 ++ )
F_2 ( 0 , & V_2 -> V_175 [ V_146 ] ) ;
F_2 ( 0 , & V_2 -> V_176 ) ;
F_2 ( V_166 | V_150 , & V_2 -> V_148 ) ;
V_10 -> V_47 = V_177 | V_51 ;
F_2 ( V_10 -> V_47 , & V_10 -> V_2 -> V_47 ) ;
F_9 ( & V_2 -> V_47 ) ;
V_10 -> V_20 . V_21 = V_178 ;
V_10 -> V_63 = V_179 ;
}
static void F_69 ( struct V_9 * V_10 )
{
if ( F_9 ( & V_10 -> V_2 -> V_148 ) & V_149 )
F_68 ( V_10 ) ;
else {
F_12 ( V_10 , L_106 , V_125 ) ;
V_10 -> V_47 = V_180 ;
F_2 ( V_10 -> V_47 , & V_10 -> V_2 -> V_47 ) ;
}
}
static int F_70 ( struct V_181 * V_19 ,
int (* F_71)( struct V_137 * ) )
{
struct V_9 * V_10 = V_182 ;
int V_132 ;
if ( ! V_19
|| V_19 -> V_183 < V_178
|| ! F_71
|| ! V_19 -> V_184
|| ! V_19 -> V_185 )
return - V_18 ;
if ( ! V_10 )
return - V_62 ;
if ( V_10 -> V_19 )
return - V_30 ;
V_19 -> V_19 . V_186 = NULL ;
V_10 -> V_19 = V_19 ;
V_10 -> V_20 . V_10 . V_19 = & V_19 -> V_19 ;
V_132 = F_71 ( & V_10 -> V_20 ) ;
if ( V_132 ) {
F_12 ( V_10 , L_107 ,
V_19 -> V_19 . V_37 , V_132 ) ;
V_10 -> V_19 = NULL ;
V_10 -> V_20 . V_10 . V_19 = NULL ;
return V_132 ;
}
F_69 ( V_10 ) ;
F_12 ( V_10 , L_108 , V_19 -> V_19 . V_37 ) ;
return 0 ;
}
static void
F_72 ( struct V_9 * V_10 , struct V_181 * V_19 )
{
unsigned V_146 ;
F_12 ( V_10 , L_106 , V_125 ) ;
if ( V_10 -> V_20 . V_21 == V_22 )
V_19 = NULL ;
F_67 ( V_10 ) ;
for ( V_146 = 0 ; V_146 < 4 ; V_146 ++ )
F_19 ( & V_10 -> V_12 [ V_146 ] , - V_23 ) ;
if ( V_19 ) {
F_32 ( & V_10 -> V_38 ) ;
V_19 -> V_184 ( & V_10 -> V_20 ) ;
F_33 ( & V_10 -> V_38 ) ;
}
if ( V_10 -> V_19 )
F_69 ( V_10 ) ;
}
static int F_73 ( struct V_181 * V_19 )
{
struct V_9 * V_10 = V_182 ;
unsigned long V_15 ;
if ( ! V_10 )
return - V_62 ;
if ( ! V_19 || V_19 != V_10 -> V_19 || ! V_19 -> V_187 )
return - V_18 ;
F_13 ( & V_10 -> V_38 , V_15 ) ;
V_10 -> V_19 = NULL ;
F_72 ( V_10 , V_19 ) ;
F_14 ( & V_10 -> V_38 , V_15 ) ;
V_19 -> V_187 ( & V_10 -> V_20 ) ;
V_10 -> V_20 . V_10 . V_19 = NULL ;
F_12 ( V_10 , L_109 , V_19 -> V_19 . V_37 ) ;
return 0 ;
}
static void F_74 ( struct V_9 * V_10 )
{
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
struct V_188 V_189 ;
int V_39 ;
V_189 . V_190 = F_9 ( & V_2 -> V_190 ) ;
V_189 . V_191 = F_9 ( & V_2 -> V_191 ) ;
V_189 . V_192 = F_75 ( ( F_9 ( & V_2 -> V_193 ) << 8 )
| F_9 ( & V_2 -> V_194 ) ) ;
V_189 . V_195 = F_75 ( ( F_9 ( & V_2 -> V_196 ) << 8 )
| F_9 ( & V_2 -> V_197 ) ) ;
V_189 . V_198 = F_75 ( ( F_9 ( & V_2 -> V_199 ) << 8 )
| F_9 ( & V_2 -> V_200 ) ) ;
F_2 ( 0 , & V_2 -> V_201 ) ;
F_19 ( & V_10 -> V_12 [ 0 ] , 0 ) ;
V_10 -> V_12 [ 0 ] . V_45 = 0 ;
if ( F_29 ( V_189 . V_190 & V_202 ) ) {
V_10 -> V_12 [ 0 ] . V_32 = 1 ;
V_10 -> V_63 = V_82 ;
F_2 ( V_203 , & V_10 -> V_2 -> V_204 ) ;
} else {
V_10 -> V_12 [ 0 ] . V_32 = 0 ;
V_10 -> V_63 = V_95 ;
switch ( V_189 . V_191 ) {
case V_205 :
switch ( V_189 . V_190 ) {
case V_206 :
V_39 = F_76 ( V_189 . V_195 ) & 0x0f ;
if ( V_39 > 3 ||
( ! V_10 -> V_12 [ V_39 ] . V_12 . V_8 && V_39 != 0 ) )
goto V_207;
if ( V_189 . V_195 & F_75 (
V_202 ) ) {
if ( ! V_10 -> V_12 [ V_39 ] . V_32 )
goto V_207;
} else {
if ( V_10 -> V_12 [ V_39 ] . V_32 )
goto V_207;
}
if ( V_189 . V_192 != F_75 (
V_208 ) )
goto V_207;
if ( V_39 )
F_55 ( & V_10 -> V_12 [ V_39 ] ) ;
V_209:
F_2 ( ~ ( 1 << 0 ) , & V_2 -> V_86 ) ;
V_10 -> V_12 [ 0 ] . V_45 = 1 ;
V_10 -> V_63 = V_87 ;
return;
case V_210 :
if ( V_189 . V_192 != F_75 ( 1 ) )
goto V_207;
F_18 ( V_10 , L_110 ) ;
goto V_209;
case V_211 :
goto V_207;
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
V_189 . V_190 , V_189 . V_191 ,
F_76 ( V_189 . V_192 ) , F_76 ( V_189 . V_195 ) ,
F_76 ( V_189 . V_198 ) ) ;
#endif
V_10 -> V_102 = ( V_189 . V_191 == V_212
&& V_189 . V_190 == V_210 ) ;
if ( F_38 ( V_10 -> V_102 ) )
V_10 -> V_103 = ( V_189 . V_192 != F_75 ( 0 ) ) ;
F_32 ( & V_10 -> V_38 ) ;
V_39 = V_10 -> V_19 -> V_185 ( & V_10 -> V_20 , & V_189 ) ;
F_33 ( & V_10 -> V_38 ) ;
if ( F_38 ( V_39 < 0 ) ) {
V_207:
#ifdef F_31
F_18 ( V_10 , L_112 ,
V_189 . V_190 , V_189 . V_191 , V_39 ) ;
#endif
F_1 ( V_2 , V_135 , 0 ) ;
V_10 -> V_12 [ 0 ] . V_45 = 1 ;
V_10 -> V_63 = V_133 ;
}
}
static T_7 F_77 ( int V_213 , void * V_145 )
{
struct V_9 * V_10 = V_145 ;
struct V_1 T_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_12 ;
T_2 V_214 , V_215 = 0 ;
unsigned V_146 , V_216 = 5 ;
F_33 ( & V_10 -> V_38 ) ;
V_217:
V_214 = F_9 ( & V_2 -> V_84 ) & V_10 -> V_47 ;
if ( ! V_214 )
goto F_27;
V_10 -> V_61 ++ ;
if ( F_38 ( V_214 & V_177 ) ) {
if ( V_214 & V_218 ) {
ERROR ( V_10 , L_113 ) ;
F_72 ( V_10 , V_10 -> V_19 ) ;
V_214 = 0 ;
V_215 = 1 ;
V_10 -> V_19 = NULL ;
goto F_27;
}
if ( V_214 & V_180 ) {
F_2 ( ~ V_214 , & V_2 -> V_84 ) ;
if ( F_9 ( & V_10 -> V_2 -> V_148 ) & V_149 ) {
F_18 ( V_10 , L_114 ) ;
F_68 ( V_10 ) ;
} else {
F_12 ( V_10 , L_115 ) ;
if ( V_10 -> V_20 . V_21 == V_178 )
F_72 ( V_10 , V_10 -> V_19 ) ;
V_10 -> V_63 = V_159 ;
V_10 -> V_47 = V_177 ;
F_2 ( V_10 -> V_47 , & V_10 -> V_2 -> V_47 ) ;
}
V_214 = 0 ;
V_215 = 1 ;
goto F_27;
}
if ( V_214 & V_219 ) {
F_78 ( V_219 ) ;
if ( F_9 ( & V_2 -> V_161 [ 0 ] ) & V_220 ) {
switch ( V_10 -> V_63 ) {
case V_159 :
case V_64 :
goto V_221;
default:
break;
}
F_12 ( V_10 , L_116 ) ;
V_10 -> V_63 = V_64 ;
if ( V_10 -> V_20 . V_21 != V_22
&& V_10 -> V_19
&& V_10 -> V_19 -> V_222 ) {
F_32 ( & V_10 -> V_38 ) ;
V_10 -> V_19 -> V_222 ( & V_10 -> V_20 ) ;
F_33 ( & V_10 -> V_38 ) ;
}
} else {
if ( V_10 -> V_63 != V_64 ) {
F_12 ( V_10 , L_117 ,
V_10 -> V_63 ) ;
goto V_221;
}
F_12 ( V_10 , L_118 ) ;
V_10 -> V_63 = V_179 ;
if ( V_10 -> V_20 . V_21 != V_22
&& V_10 -> V_19
&& V_10 -> V_19 -> V_223 ) {
F_32 ( & V_10 -> V_38 ) ;
V_10 -> V_19 -> V_223 ( & V_10 -> V_20 ) ;
F_33 ( & V_10 -> V_38 ) ;
}
}
}
V_221:
if ( V_214 & V_224 ) {
F_78 ( V_224 ) ;
F_79 ( V_10 , L_119 ,
V_10 -> V_19 -> V_19 . V_37 ) ;
}
}
if ( V_214 & V_225 ) {
F_78 ( V_225 ) ;
V_10 -> V_12 [ 0 ] . V_61 ++ ;
F_74 ( V_10 ) ;
}
if ( V_214 & V_226 ) {
F_78 ( V_226 | V_227 ) ;
if ( V_10 -> V_63 == V_82 ) {
V_12 = & V_10 -> V_12 [ 0 ] ;
V_12 -> V_61 ++ ;
F_19 ( V_12 , 0 ) ;
F_2 ( ~ ( 1 << 0 ) , & V_2 -> V_86 ) ;
V_10 -> V_63 = V_87 ;
}
}
if ( V_214 & V_227 ) {
F_78 ( V_227 ) ;
V_12 = & V_10 -> V_12 [ 0 ] ;
V_12 -> V_61 ++ ;
F_46 ( V_12 ) ;
}
if ( V_214 & V_50 ) {
F_78 ( V_50 ) ;
V_12 = & V_10 -> V_12 [ V_35 ] ;
V_12 -> V_61 ++ ;
F_48 ( V_10 , V_12 ) ;
}
if ( V_214 & V_48 ) {
F_78 ( V_48 ) ;
V_12 = & V_10 -> V_12 [ V_36 ] ;
V_12 -> V_61 ++ ;
F_48 ( V_10 , V_12 ) ;
}
if ( V_214 & V_49 ) {
F_78 ( V_49 ) ;
V_12 = & V_10 -> V_12 [ V_36 ] ;
V_12 -> V_61 ++ ;
ERROR ( V_10 , L_120 , V_12 -> V_12 . V_37 ) ;
}
for ( V_146 = 1 ; V_146 < 4 ; V_146 ++ ) {
T_2 V_39 = F_16 ( V_146 ) ;
if ( ! ( V_214 & V_39 ) )
continue;
V_12 = & V_10 -> V_12 [ V_146 ] ;
F_46 ( V_12 ) ;
if ( F_25 ( & V_12 -> V_70 ) )
F_45 ( V_10 , V_2 , V_146 ) ;
V_214 &= ~ V_39 ;
V_215 = 1 ;
V_12 -> V_61 ++ ;
}
if ( V_216 -- )
goto V_217;
F_27:
( void ) F_9 ( & V_2 -> V_47 ) ;
F_32 ( & V_10 -> V_38 ) ;
if ( V_214 )
F_12 ( V_10 , L_121 , V_214 ,
F_9 ( & V_2 -> V_84 ) , V_10 -> V_47 ) ;
return F_80 ( V_215 ) ;
}
static void F_81 ( struct V_228 * V_145 )
{
struct V_9 * V_10 = F_82 ( V_145 ) ;
F_26 ( V_10 ) ;
}
static void F_83 ( struct V_229 * V_230 )
{
struct V_9 * V_10 = F_84 ( V_230 ) ;
F_12 ( V_10 , L_106 , V_125 ) ;
F_85 ( & V_10 -> V_20 ) ;
F_86 ( V_10 -> V_19 ) ;
#ifdef F_87
F_88 ( V_231 , NULL ) ;
#endif
if ( V_10 -> V_2 )
F_67 ( V_10 ) ;
if ( V_10 -> V_232 )
F_89 ( V_230 -> V_213 , V_10 ) ;
if ( V_10 -> V_2 )
F_90 ( V_10 -> V_2 ) ;
if ( V_10 -> V_233 )
F_91 ( F_92 ( V_230 , 0 ) ,
F_93 ( V_230 , 0 ) ) ;
if ( V_10 -> V_234 )
F_94 ( V_230 ) ;
if ( V_10 -> V_235 )
F_95 ( & V_10 -> V_20 . V_10 ) ;
F_96 ( V_230 , NULL ) ;
V_10 -> V_2 = NULL ;
V_182 = NULL ;
F_79 ( V_10 , L_122 ) ;
}
static int F_97 ( struct V_229 * V_230 , const struct V_236 * V_237 )
{
struct V_9 * V_10 = NULL ;
unsigned long V_238 , V_239 ;
void T_1 * V_240 = NULL ;
int V_132 ;
if ( V_182 ) {
F_98 ( L_123 , F_99 ( V_230 ) ) ;
return - V_30 ;
}
if ( ! V_230 -> V_213 ) {
F_100 ( V_241 L_124 , F_99 ( V_230 ) ) ;
V_132 = - V_62 ;
goto V_242;
}
V_10 = F_21 ( sizeof *V_10 , V_243 ) ;
if ( V_10 == NULL ) {
F_101 ( L_125 , F_99 ( V_230 ) ) ;
V_132 = - V_244 ;
goto V_242;
}
F_102 ( & V_10 -> V_38 ) ;
V_10 -> V_230 = V_230 ;
V_10 -> V_20 . V_163 = & V_245 ;
V_10 -> V_20 . V_183 = V_178 ;
F_103 ( & V_10 -> V_20 . V_10 , L_126 ) ;
V_10 -> V_20 . V_10 . V_246 = & V_230 -> V_10 ;
V_10 -> V_20 . V_10 . V_247 = V_230 -> V_10 . V_247 ;
V_10 -> V_20 . V_10 . V_248 = F_81 ;
V_10 -> V_20 . V_37 = V_249 ;
V_132 = F_104 ( V_230 ) ;
if ( V_132 < 0 ) {
F_12 ( V_10 , L_127 , V_132 ) ;
goto V_242;
}
V_10 -> V_234 = 1 ;
V_238 = F_92 ( V_230 , 0 ) ;
V_239 = F_93 ( V_230 , 0 ) ;
if ( ! F_105 ( V_238 , V_239 , V_249 ) ) {
F_12 ( V_10 , L_128 ) ;
V_132 = - V_30 ;
goto V_242;
}
V_10 -> V_233 = 1 ;
V_240 = F_106 ( V_238 , V_239 ) ;
if ( V_240 == NULL ) {
F_12 ( V_10 , L_129 ) ;
V_132 = - V_250 ;
goto V_242;
}
V_10 -> V_2 = (struct V_1 T_1 * ) V_240 ;
F_96 ( V_230 , V_10 ) ;
F_79 ( V_10 , L_106 , V_251 ) ;
F_79 ( V_10 , L_130 V_252 L_131 , F_60 () ) ;
F_79 ( V_10 , L_132 , V_230 -> V_213 , V_240 ) ;
F_67 ( V_10 ) ;
F_66 ( V_10 ) ;
if ( F_107 ( V_230 -> V_213 , F_77 , V_253 ,
V_249 , V_10 ) != 0 ) {
F_12 ( V_10 , L_133 , V_230 -> V_213 ) ;
V_132 = - V_30 ;
goto V_242;
}
V_10 -> V_232 = 1 ;
if ( V_34 )
F_108 ( V_230 ) ;
#ifdef F_87
F_109 ( V_231 , 0 , NULL , F_63 , V_10 ) ;
#endif
V_182 = V_10 ;
V_132 = F_110 ( & V_10 -> V_20 . V_10 ) ;
if ( V_132 ) {
F_111 ( & V_10 -> V_20 . V_10 ) ;
goto V_242;
}
V_10 -> V_235 = 1 ;
V_132 = F_112 ( & V_230 -> V_10 , & V_10 -> V_20 ) ;
if ( V_132 )
goto V_242;
return 0 ;
V_242:
if ( V_10 )
F_83 ( V_230 ) ;
return V_132 ;
}
