static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( 1 , V_2 -> V_3 + V_4 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_3 + V_6 ) ;
}
static inline void F_5 ( struct V_1 * V_2 , T_1 V_5 ,
T_2 V_7 , int V_8 )
{
F_3 ( V_2 , V_5 ) ;
F_6 ( V_7 , V_2 -> V_3 + V_8 ) ;
}
static inline void F_7 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 V_7 , int V_8 )
{
F_3 ( V_2 , V_5 ) ;
F_4 ( V_7 , V_2 -> V_3 + V_8 ) ;
}
static inline void F_8 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 V_9 , int V_8 )
{
T_1 V_10 ;
F_3 ( V_2 , V_5 ) ;
V_10 = F_9 ( V_2 -> V_3 + V_8 ) ;
V_10 |= V_9 ;
F_4 ( V_10 , V_2 -> V_3 + V_8 ) ;
}
static inline void F_10 ( struct V_1 * V_2 , T_1 V_5 ,
T_1 V_9 , int V_8 )
{
T_1 V_10 ;
F_3 ( V_2 , V_5 ) ;
V_10 = F_9 ( V_2 -> V_3 + V_8 ) ;
V_10 &= ~ V_9 ;
F_4 ( V_10 , V_2 -> V_3 + V_8 ) ;
}
static inline void F_11 ( struct V_1 * V_2 , T_1 V_5 ,
T_3 V_7 , int V_8 )
{
F_3 ( V_2 , V_5 ) ;
F_2 ( V_7 , V_2 -> V_3 + V_8 ) ;
}
static inline T_2 F_12 ( struct V_1 * V_2 , T_1 V_5 ,
int V_8 )
{
F_3 ( V_2 , V_5 ) ;
return F_13 ( V_2 -> V_3 + V_8 ) ;
}
static inline T_1 F_14 ( struct V_1 * V_2 , T_1 V_5 ,
int V_8 )
{
F_3 ( V_2 , V_5 ) ;
return F_9 ( V_2 -> V_3 + V_8 ) ;
}
static inline T_3 F_15 ( struct V_1 * V_2 , T_1 V_5 ,
int V_8 )
{
F_3 ( V_2 , V_5 ) ;
return F_16 ( V_2 -> V_3 + V_8 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 & V_12 ) {
F_7 ( V_2 , 3 , 1 , V_13 ) ;
F_18 ( 10 ) ;
F_4 ( 0 , V_2 -> V_3 + V_13 ) ;
} else {
F_2 ( 0x1 , V_2 -> V_3 + V_14 ) ;
F_18 ( 20 ) ;
}
}
static void F_19 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
if ( F_14 ( V_2 , 45 , V_17 ) & 0x4 ) {
F_20 ( V_16 ) ;
F_21 ( V_16 ) ;
} else {
F_22 ( V_16 ) ;
F_23 ( V_16 ) ;
}
}
static void F_24 ( struct V_1 * V_2 )
{
F_8 ( V_2 , 16 , 0x01 , V_18 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_10 ( V_2 , 16 , 0x01 , V_18 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_8 ( V_2 , 16 , 0x01 , V_19 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_10 ( V_2 , 16 , 0x01 , V_19 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
F_7 ( V_2 , 16 , 0x000E , V_18 ) ;
F_7 ( V_2 , 16 , 0x8 | 0x20 | 0x40 | 0x80 | 0x400 ,
V_19 ) ;
F_7 ( V_2 , 17 , 0x4000 , V_20 ) ;
F_7 ( V_2 , 17 , 0x4000 , V_21 ) ;
F_7 ( V_2 , 0 , 0x1000 , V_22 ) ;
F_8 ( V_2 , 32 , 1 << 8 , V_23 ) ;
F_8 ( V_2 , 32 , 1 << 3 , V_24 ) ;
F_7 ( V_2 , 48 , 0x1E07 , V_25 ) ;
F_8 ( V_2 , 49 , 1 << 13 , V_26 ) ;
F_24 ( V_2 ) ;
F_26 ( V_2 ) ;
F_7 ( V_2 , 18 , 0xffff , V_27 ) ;
if ( F_29 ( V_2 ) ) {
F_4 ( V_28 , V_2 -> V_3 + V_29 ) ;
F_7 ( V_2 , 18 , V_30 , V_31 ) ;
} else {
if ( ! ( V_2 -> V_11 & V_12 ) )
F_4 ( V_32 ,
V_2 -> V_3 + V_29 ) ;
F_7 ( V_2 , 18 , V_32 , V_31 ) ;
}
F_7 ( V_2 , 32 , 0x1 , V_33 ) ;
}
static void F_30 ( struct V_1 * V_2 , T_2 * V_34 )
{
int V_35 ;
T_1 V_36 ;
for ( V_35 = 0 ; V_35 < V_37 ; V_35 ++ )
V_34 [ V_37 - V_35 - 1 ] = F_12 ( V_2 , 2 , V_38 + V_35 ) ;
if ( V_2 -> V_11 & V_12 ) {
V_36 = F_14 ( V_2 , 2 , V_38 ) ;
F_7 ( V_2 , 39 , V_36 , V_39 ) ;
V_36 = F_14 ( V_2 , 2 , V_40 ) ;
F_7 ( V_2 , 39 , V_36 , V_41 ) ;
V_36 = F_14 ( V_2 , 2 , V_42 ) ;
F_7 ( V_2 , 39 , V_36 , V_43 ) ;
} else {
V_36 = F_14 ( V_2 , 2 , V_38 ) ;
F_7 ( V_2 , 39 , V_36 , V_43 ) ;
V_36 = F_14 ( V_2 , 2 , V_40 ) ;
F_7 ( V_2 , 39 , V_36 , V_41 ) ;
V_36 = F_14 ( V_2 , 2 , V_42 ) ;
F_7 ( V_2 , 39 , V_36 , V_39 ) ;
}
}
static void F_31 ( struct V_1 * V_2 , T_2 * V_36 )
{
unsigned long V_44 ;
unsigned V_35 ;
F_32 ( & V_2 -> V_45 , V_44 ) ;
for ( V_35 = 0 ; V_35 < V_37 ; V_35 ++ ) {
F_5 ( V_2 , 2 , V_36 [ V_37 - V_35 - 1 ] , V_38 + V_35 ) ;
if ( ! ( V_2 -> V_11 & V_12 ) )
F_5 ( V_2 , 39 , V_36 [ V_37 - V_35 - 1 ] ,
V_43 + V_35 ) ;
}
if ( V_2 -> V_11 & V_12 ) {
T_1 V_36 ;
V_36 = F_14 ( V_2 , 2 , V_38 ) ;
F_7 ( V_2 , 39 , V_36 , V_39 ) ;
V_36 = F_14 ( V_2 , 2 , V_40 ) ;
F_7 ( V_2 , 39 , V_36 , V_41 ) ;
V_36 = F_14 ( V_2 , 2 , V_42 ) ;
F_7 ( V_2 , 39 , V_36 , V_43 ) ;
}
F_33 ( & V_2 -> V_45 , V_44 ) ;
}
static inline T_1 F_34 ( struct V_1 * V_2 )
{
return F_14 ( V_2 , 16 , V_46 ) & 0x1fff ;
}
static int F_35 ( struct V_47 * V_48 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
struct V_49 * V_50 = & V_2 -> V_51 ;
T_2 * V_52 = V_50 -> V_52 ;
if ( V_50 -> V_53 ) {
F_37 ( V_16 , L_1 , V_54 ) ;
return V_55 ;
}
F_38 ( & V_50 -> V_56 ) = V_48 -> V_57 + sizeof( T_3 ) ;
* V_52 ++ = 0x00 ;
* V_52 ++ = 0x01 ;
* V_52 ++ = V_48 -> V_57 & 0xff ;
* V_52 ++ = ( V_48 -> V_57 >> 8 ) & 0xff ;
F_39 ( V_48 , V_52 , V_48 -> V_57 ) ;
F_40 ( V_2 -> V_58 ,
F_41 ( & V_50 -> V_56 ) , 0 , F_38 ( & V_50 -> V_56 ) ,
V_59 ) ;
if ( F_38 ( & V_50 -> V_56 ) % 4 )
F_38 ( & V_50 -> V_56 ) += 4 - F_38 ( & V_50 -> V_56 ) % 4 ;
V_50 -> V_53 = F_42 ( V_50 -> V_60 ,
& V_50 -> V_56 , 1 , V_61 , V_62 ) ;
if ( ! V_50 -> V_53 )
return V_55 ;
V_50 -> V_53 -> V_63 = V_16 ;
V_50 -> V_53 -> V_64 = V_65 ;
V_50 -> V_53 -> V_66 ( V_50 -> V_53 ) ;
V_16 -> V_67 . V_68 += V_48 -> V_57 ;
F_43 ( V_48 ) ;
return V_69 ;
}
static int F_44 ( struct V_47 * V_48 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
int V_57 = V_48 -> V_57 ;
F_37 ( V_16 , L_2 ,
V_54 , V_48 -> V_57 , V_48 -> V_70 , V_48 -> V_71 ,
F_45 ( V_48 ) , F_46 ( V_48 ) ) ;
if ( F_34 ( V_2 ) < V_57 + 8 )
return V_55 ;
if ( V_2 -> V_11 & V_72 ) {
T_1 * V_73 = ( T_1 * ) V_48 -> V_71 ;
F_7 ( V_2 , 17 , 0x8000 | 0x100 , V_74 ) ;
F_7 ( V_2 , 17 , ( T_1 ) V_57 , V_75 ) ;
V_16 -> V_67 . V_68 += V_57 ;
while ( V_57 > 0 ) {
F_4 ( * V_73 ++ , V_2 -> V_3 + V_74 ) ;
F_4 ( * V_73 ++ , V_2 -> V_3 + V_75 ) ;
V_57 -= sizeof( T_3 ) ;
}
} else {
T_3 * V_76 = ( T_3 * ) V_48 -> V_71 ;
T_3 V_77 ;
V_77 = 0x8000 | 0x100 | ( V_57 << 16 ) ;
F_11 ( V_2 , 17 , V_77 , V_74 ) ;
V_16 -> V_67 . V_68 += V_57 ;
while ( V_57 > 0 ) {
F_2 ( * V_76 , V_2 -> V_3 + V_74 ) ;
V_57 -= sizeof( T_3 ) ;
V_76 ++ ;
}
}
F_7 ( V_2 , 17 , 1 , V_78 ) ;
F_43 ( V_48 ) ;
return V_69 ;
}
static void F_47 ( struct V_15 * V_16 , T_3 V_79 )
{
F_37 ( V_16 , L_3 , V_79 ) ;
V_16 -> V_67 . V_80 ++ ;
if ( V_79 & V_81 )
V_16 -> V_67 . V_82 ++ ;
if ( V_79 & V_83 )
V_16 -> V_67 . V_84 ++ ;
if ( V_79 & V_85 )
V_16 -> V_67 . V_86 ++ ;
}
static void F_48 ( struct V_15 * V_16 , T_3 V_79 ,
int V_57 )
{
F_37 ( V_16 , L_4 , V_57 ) ;
V_16 -> V_67 . V_87 ++ ;
V_16 -> V_67 . V_88 += V_57 ;
if ( V_79 & V_89 )
V_16 -> V_67 . V_90 ++ ;
}
static int F_49 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
struct V_91 * V_50 = & V_2 -> V_92 ;
struct V_93 * V_56 = & V_50 -> V_56 ;
int V_94 ;
V_50 -> V_48 = F_50 ( V_16 , V_95 ) ;
if ( V_50 -> V_48 ) {
F_51 ( V_56 , 1 ) ;
F_41 ( V_56 ) = F_52 ( V_2 -> V_58 ,
V_50 -> V_48 -> V_71 , V_95 , V_96 ) ;
V_94 = F_53 ( V_2 -> V_58 , F_41 ( V_56 ) ) ;
if ( F_54 ( V_94 ) ) {
F_41 ( V_56 ) = 0 ;
goto V_97;
}
F_38 ( V_56 ) = V_95 ;
V_50 -> V_53 = F_42 ( V_50 -> V_60 ,
V_56 , 1 , V_98 , V_62 ) ;
if ( ! V_50 -> V_53 )
goto V_97;
V_50 -> V_53 -> V_63 = V_16 ;
V_50 -> V_53 -> V_64 = V_99 ;
V_50 -> V_53 -> V_66 ( V_50 -> V_53 ) ;
} else {
V_94 = - V_100 ;
F_41 ( V_56 ) = 0 ;
goto V_97;
}
return V_94 ;
V_97:
if ( F_41 ( V_56 ) )
F_55 ( V_2 -> V_58 , F_41 ( V_56 ) ,
V_95 , V_96 ) ;
F_41 ( V_56 ) = 0 ;
if ( V_50 -> V_48 )
F_43 ( V_50 -> V_48 ) ;
V_50 -> V_48 = NULL ;
F_56 (KERN_ERR DRV_NAMEL_5 , err) ;
return V_94 ;
}
static void F_57 ( unsigned long V_101 )
{
struct V_15 * V_16 = (struct V_15 * ) V_101 ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
struct V_91 * V_50 = & V_2 -> V_92 ;
struct V_47 * V_48 = V_50 -> V_48 ;
T_4 V_102 = F_41 ( & V_50 -> V_56 ) ;
T_3 V_79 ;
V_50 -> V_53 = NULL ;
F_49 ( V_16 ) ;
F_55 ( V_2 -> V_58 , V_102 , V_95 , V_96 ) ;
V_79 = * ( ( T_3 * ) V_48 -> V_71 ) ;
F_37 ( V_16 , L_6 ,
V_54 , V_79 & 0xffff ) ;
if ( ( V_79 & V_103 ) && ! ( V_79 & V_104 ) ) {
int V_57 = ( V_79 >> 16 ) & 0x7ff ;
F_48 ( V_16 , V_79 , V_57 ) ;
F_58 ( V_48 , 4 ) ;
F_59 ( V_48 , V_57 ) ;
V_48 -> V_105 = F_60 ( V_48 , V_16 ) ;
F_61 ( V_48 ) ;
} else {
F_47 ( V_16 , V_79 ) ;
F_43 ( V_48 ) ;
}
}
static void F_62 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
T_3 V_79 ;
int V_57 ;
if ( V_2 -> V_11 & V_72 ) {
V_79 = F_14 ( V_2 , 17 , V_74 ) ;
V_57 = F_14 ( V_2 , 17 , V_75 ) ;
F_37 ( V_16 , L_6 ,
V_54 , V_79 ) ;
} else {
V_79 = F_15 ( V_2 , 17 , V_74 ) ;
V_57 = ( V_79 >> 16 ) & 0x7ff ;
V_79 &= 0xffff ;
F_37 ( V_16 , L_6 ,
V_54 , V_79 ) ;
}
if ( ( V_79 & V_103 ) && ! ( V_79 & V_104 ) ) {
struct V_47 * V_48 = F_63 ( V_16 , V_57 + 3 ) ;
if ( V_48 ) {
F_48 ( V_16 , V_79 , V_57 ) ;
if ( V_2 -> V_11 & V_72 ) {
T_1 * V_106 = ( T_1 * ) F_59 ( V_48 , V_57 ) ;
F_3 ( V_2 , 17 ) ;
while ( V_57 > 0 ) {
* V_106 ++ = F_9 ( V_2 -> V_3 +
V_74 ) ;
* V_106 ++ = F_9 ( V_2 -> V_3 +
V_75 ) ;
V_57 -= sizeof( T_3 ) ;
}
} else {
T_3 * V_71 = ( T_3 * ) F_59 ( V_48 , V_57 ) ;
F_3 ( V_2 , 17 ) ;
while ( V_57 > 0 ) {
* V_71 ++ = F_16 ( V_2 -> V_3 +
V_74 ) ;
V_57 -= sizeof( T_3 ) ;
}
}
V_48 -> V_105 = F_60 ( V_48 , V_16 ) ;
F_61 ( V_48 ) ;
} else
V_16 -> V_67 . V_107 ++ ;
} else
F_47 ( V_16 , V_79 ) ;
F_10 ( V_2 , 0 , 1 << 12 , V_22 ) ;
F_7 ( V_2 , 17 , 0x01 , V_108 ) ;
F_8 ( V_2 , 0 , 1 << 12 , V_22 ) ;
}
static void F_64 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
T_1 V_109 = F_14 ( V_2 , 16 , V_110 ) & 0x1fff ;
F_37 ( V_16 , L_7 , V_54 , V_109 ) ;
while ( V_109 ) {
F_62 ( V_16 , V_2 ) ;
V_109 = F_14 ( V_2 , 16 , V_110 ) & 0x1fff ;
}
}
static void F_65 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
T_1 V_111 = F_14 ( V_2 , 16 , V_112 ) ;
F_37 ( V_16 , L_8 , V_54 , V_111 ) ;
V_16 -> V_67 . V_113 ++ ;
if ( F_66 ( V_16 ) )
F_21 ( V_16 ) ;
}
static void F_67 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
F_37 ( V_16 , L_9 , V_54 ) ;
V_16 -> V_67 . V_80 ++ ;
V_16 -> V_67 . V_114 ++ ;
}
static void F_68 ( unsigned long V_101 )
{
struct V_15 * V_16 = (struct V_15 * ) V_101 ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
T_1 V_115 ;
unsigned long V_44 ;
T_1 V_116 ;
F_32 ( & V_2 -> V_45 , V_44 ) ;
V_116 = F_9 ( V_2 -> V_3 + V_6 ) ;
F_33 ( & V_2 -> V_45 , V_44 ) ;
V_115 = F_14 ( V_2 , 18 , V_27 ) ;
F_37 ( V_16 , L_10 , V_54 , V_115 ) ;
if ( F_29 ( V_2 ) )
V_115 &= ~ V_117 ;
F_7 ( V_2 , 18 , V_115 , V_27 ) ;
if ( ! ( V_2 -> V_11 & V_12 ) )
F_2 ( 0x1 , V_2 -> V_3 + V_118 ) ;
if ( ! F_69 ( V_16 ) )
return;
if ( V_115 & V_119 )
F_19 ( V_16 , V_2 ) ;
if ( V_115 & ( V_117 | V_120 ) && ! F_29 ( V_2 ) )
F_64 ( V_16 , V_2 ) ;
if ( V_115 & V_121 )
F_65 ( V_16 , V_2 ) ;
if ( V_115 & V_122 )
F_67 ( V_16 , V_2 ) ;
if ( V_115 & V_123 ) {
F_25 ( V_2 ) ;
F_24 ( V_2 ) ;
}
if ( V_115 & V_124 ) {
F_27 ( V_2 ) ;
F_26 ( V_2 ) ;
}
F_32 ( & V_2 -> V_45 , V_44 ) ;
if ( F_29 ( V_2 ) )
F_7 ( V_2 , 18 , V_30 , V_31 ) ;
else
F_7 ( V_2 , 18 , V_32 , V_31 ) ;
F_4 ( V_116 , V_2 -> V_3 + V_6 ) ;
if ( F_29 ( V_2 ) )
F_1 ( V_2 ) ;
F_33 ( & V_2 -> V_45 , V_44 ) ;
}
static T_5 F_70 ( int V_125 , void * V_126 )
{
struct V_15 * V_16 = V_126 ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
T_1 V_115 ;
T_1 V_116 = F_9 ( V_2 -> V_3 + V_6 ) ;
T_5 V_127 = V_128 ;
V_115 = F_14 ( V_2 , 18 , V_27 ) ;
F_37 ( V_16 , L_10 , V_54 , V_115 ) ;
if ( V_115 ) {
if ( F_29 ( V_2 ) )
F_7 ( V_2 , 18 , V_117 , V_31 ) ;
else
F_7 ( V_2 , 18 , 0x00 , V_31 ) ;
F_71 ( & V_2 -> V_129 ) ;
V_127 = V_130 ;
}
F_4 ( V_116 , V_2 -> V_3 + V_6 ) ;
F_1 ( V_2 ) ;
return V_127 ;
}
static void V_99 ( void * V_71 )
{
struct V_15 * V_16 = V_71 ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
F_37 ( V_16 , L_11 ) ;
if ( V_2 -> V_92 . V_53 )
F_71 ( & V_2 -> V_92 . V_129 ) ;
}
static void V_65 ( void * V_71 )
{
struct V_15 * V_16 = V_71 ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
struct V_49 * V_50 = & V_2 -> V_51 ;
F_37 ( V_16 , L_12 ) ;
if ( ! V_50 -> V_53 )
return;
V_16 -> V_67 . V_113 ++ ;
V_50 -> V_53 = NULL ;
if ( F_66 ( V_16 ) )
F_21 ( V_16 ) ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_49 * V_131 = & V_2 -> V_51 ;
struct V_91 * V_132 = & V_2 -> V_92 ;
V_131 -> V_53 = NULL ;
if ( V_131 -> V_60 )
F_73 ( V_131 -> V_60 ) ;
V_132 -> V_53 = NULL ;
if ( V_132 -> V_60 )
F_73 ( V_132 -> V_60 ) ;
if ( F_41 ( & V_132 -> V_56 ) )
F_55 ( V_2 -> V_58 , F_41 ( & V_132 -> V_56 ) ,
V_95 , V_96 ) ;
F_41 ( & V_132 -> V_56 ) = 0 ;
F_43 ( V_132 -> V_48 ) ;
V_132 -> V_48 = NULL ;
}
static void F_74 ( struct V_1 * V_2 )
{
struct V_49 * V_131 = & V_2 -> V_51 ;
struct V_91 * V_132 = & V_2 -> V_92 ;
F_72 ( V_2 ) ;
if ( V_131 -> V_60 )
F_75 ( V_131 -> V_60 ) ;
V_131 -> V_60 = NULL ;
if ( V_132 -> V_60 )
F_75 ( V_132 -> V_60 ) ;
V_132 -> V_60 = NULL ;
F_76 ( & V_132 -> V_129 ) ;
if ( F_41 ( & V_131 -> V_56 ) )
F_55 ( V_2 -> V_58 , F_41 ( & V_131 -> V_56 ) ,
V_95 , V_59 ) ;
F_41 ( & V_131 -> V_56 ) = 0 ;
F_77 ( V_131 -> V_52 ) ;
V_131 -> V_52 = NULL ;
}
static bool F_78 ( struct V_133 * V_60 , void * V_134 )
{
return V_60 -> V_135 == ( long ) V_134 ;
}
static int F_79 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
struct V_49 * V_131 = & V_2 -> V_51 ;
struct V_91 * V_132 = & V_2 -> V_92 ;
int V_94 ;
T_6 V_136 ;
F_80 ( V_136 ) ;
F_81 ( V_137 , V_136 ) ;
F_81 ( V_138 , V_136 ) ;
F_51 ( & V_131 -> V_56 , 1 ) ;
V_131 -> V_60 = F_82 ( V_136 , F_78 ,
( void * ) ( long ) V_131 -> V_139 ) ;
if ( ! V_131 -> V_60 ) {
V_94 = - V_140 ;
goto V_94;
}
V_131 -> V_52 = F_83 ( V_95 , V_141 ) ;
if ( ! V_131 -> V_52 ) {
V_94 = - V_100 ;
goto V_94;
}
F_41 ( & V_131 -> V_56 ) = F_52 ( V_2 -> V_58 ,
V_131 -> V_52 , V_95 , V_59 ) ;
V_94 = F_53 ( V_2 -> V_58 ,
F_41 ( & V_131 -> V_56 ) ) ;
if ( V_94 ) {
F_41 ( & V_131 -> V_56 ) = 0 ;
goto V_94;
}
V_132 -> V_60 = F_82 ( V_136 , F_78 ,
( void * ) ( long ) V_132 -> V_139 ) ;
if ( ! V_132 -> V_60 ) {
V_94 = - V_140 ;
goto V_94;
}
F_84 ( & V_132 -> V_129 , F_57 ,
( unsigned long ) V_16 ) ;
return 0 ;
V_94:
F_74 ( V_2 ) ;
return V_94 ;
}
static int F_85 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
int V_94 ;
F_37 ( V_16 , L_13 , V_54 ) ;
if ( F_29 ( V_2 ) ) {
V_94 = F_79 ( V_16 ) ;
if ( ! V_94 ) {
V_94 = F_49 ( V_16 ) ;
if ( V_94 )
F_74 ( V_2 ) ;
}
if ( V_94 ) {
F_56 (KERN_WARNING DRV_NAME
L_14 ) ;
F_74 ( V_2 ) ;
V_2 -> V_92 . V_139 = - 1 ;
V_2 -> V_51 . V_139 = - 1 ;
}
}
F_28 ( V_2 ) ;
F_31 ( V_2 , V_16 -> V_142 ) ;
F_19 ( V_16 , V_2 ) ;
V_94 = F_86 ( V_2 -> V_125 , F_70 , V_143 , V_144 ,
V_16 ) ;
if ( V_94 ) {
F_87 ( L_15 , V_2 -> V_125 , V_94 ) ;
return V_94 ;
}
return 0 ;
}
static int F_88 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
F_37 ( V_16 , L_13 , V_54 ) ;
F_89 ( & V_2 -> V_145 ) ;
if ( F_29 ( V_2 ) )
F_74 ( V_2 ) ;
F_90 ( V_2 -> V_125 , V_16 ) ;
F_7 ( V_2 , 32 , 0x0 , V_33 ) ;
return 0 ;
}
static T_7 F_91 ( struct V_47 * V_48 ,
struct V_15 * V_16 )
{
int V_127 ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
F_37 ( V_16 , L_9 , V_54 ) ;
if ( F_29 ( V_2 ) ) {
unsigned long V_44 ;
V_127 = F_35 ( V_48 , V_16 ) ;
F_32 ( & V_2 -> V_45 , V_44 ) ;
if ( V_2 -> V_51 . V_53 )
F_22 ( V_16 ) ;
F_33 ( & V_2 -> V_45 , V_44 ) ;
return V_127 ;
}
V_127 = F_44 ( V_48 , V_16 ) ;
if ( F_34 ( V_2 ) < V_16 -> V_146 + 8 )
F_22 ( V_16 ) ;
return V_127 ;
}
static int F_92 ( struct V_15 * V_16 , void * V_147 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
struct V_148 * V_102 = V_147 ;
char * V_36 = ( T_2 * ) V_102 -> V_149 ;
F_37 ( V_16 , L_9 , V_54 ) ;
if ( ! F_93 ( V_102 -> V_149 ) )
return - V_150 ;
memcpy ( V_16 -> V_142 , V_36 , V_16 -> V_151 ) ;
F_31 ( V_2 , V_36 ) ;
return 0 ;
}
static void F_94 ( struct V_152 * V_153 )
{
struct V_1 * V_2 =
F_95 ( V_153 , struct V_1 , V_145 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
unsigned long V_44 ;
F_37 ( V_16 , L_9 , V_54 ) ;
F_32 ( & V_2 -> V_45 , V_44 ) ;
if ( F_29 ( V_2 ) )
F_72 ( V_2 ) ;
F_7 ( V_2 , 18 , 0 , V_31 ) ;
F_7 ( V_2 , 18 , 0xFFFF , V_27 ) ;
F_22 ( V_16 ) ;
F_33 ( & V_2 -> V_45 , V_44 ) ;
F_28 ( V_2 ) ;
F_31 ( V_2 , V_16 -> V_142 ) ;
F_19 ( V_16 , V_2 ) ;
if ( F_29 ( V_2 ) )
F_49 ( V_16 ) ;
}
static void F_96 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
F_37 ( V_16 , L_9 , V_54 ) ;
F_97 ( & V_2 -> V_145 ) ;
}
static int F_98 ( struct V_154 * V_155 )
{
int V_94 = - V_100 ;
struct V_156 * V_157 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_158 * V_159 = F_99 ( & V_155 -> V_58 ) ;
T_1 V_160 ;
unsigned V_35 ;
V_157 = F_100 ( V_155 , V_161 , 0 ) ;
if ( ! F_101 ( V_157 -> V_162 , F_102 ( V_157 ) , V_144 ) )
goto V_163;
V_16 = F_103 ( sizeof( struct V_1 ) ) ;
if ( ! V_16 )
goto V_164;
F_104 ( V_16 , & V_155 -> V_58 ) ;
V_2 = F_36 ( V_16 ) ;
V_2 -> V_16 = V_16 ;
F_105 ( & V_2 -> V_145 , F_94 ) ;
V_2 -> V_3 = F_106 ( V_157 -> V_162 , F_102 ( V_157 ) ) ;
V_2 -> V_11 = V_157 -> V_44 ;
if ( ! V_2 -> V_3 )
goto V_165;
V_2 -> V_125 = F_107 ( V_155 , 0 ) ;
if ( V_2 -> V_125 < 0 ) {
V_94 = V_2 -> V_125 ;
goto V_166;
}
V_2 -> V_58 = ( V_155 -> V_58 . V_167 ) ? V_155 -> V_58 . V_167 : & V_155 -> V_58 ;
if ( ! ( V_2 -> V_11 & V_12 ) && V_159 &&
( V_159 -> V_168 != - 1 ) &&
( V_159 -> V_169 != - 1 ) ) {
V_2 -> V_92 . V_139 = V_159 -> V_169 ;
V_2 -> V_51 . V_139 = V_159 -> V_168 ;
} else {
V_2 -> V_92 . V_139 = - 1 ;
V_2 -> V_51 . V_139 = - 1 ;
}
F_84 ( & V_2 -> V_129 , F_68 , ( unsigned long ) V_16 ) ;
F_108 ( & V_2 -> V_45 ) ;
V_16 -> V_170 = & V_171 ;
V_16 -> V_172 = & V_173 ;
V_35 = V_16 -> V_151 ;
if ( V_159 ) {
for ( V_35 = 0 ; V_35 < V_16 -> V_151 ; V_35 ++ )
if ( V_159 -> V_174 [ V_35 ] != 0 )
break;
if ( V_35 < V_16 -> V_151 )
memcpy ( V_16 -> V_142 , V_159 -> V_174 ,
V_16 -> V_151 ) ;
}
if ( V_35 == V_16 -> V_151 ) {
F_30 ( V_2 , V_16 -> V_142 ) ;
if ( ! F_93 ( V_16 -> V_142 ) )
F_109 ( V_16 ) ;
}
V_160 = F_14 ( V_2 , 32 , V_33 ) ;
strcpy ( V_16 -> V_175 , L_16 ) ;
V_94 = F_110 ( V_16 ) ;
if ( V_94 )
goto V_176;
F_111 ( V_155 , V_16 ) ;
F_112 ( L_17 ,
( V_160 >> 8 ) & 0xff , ( V_160 >> 4 ) & 0xf , ( V_160 >> 1 ) & 0x7 ) ;
return 0 ;
V_176:
V_166:
F_113 ( V_2 -> V_3 ) ;
V_165:
F_114 ( V_16 ) ;
V_164:
F_115 ( V_157 -> V_162 , F_102 ( V_157 ) ) ;
V_163:
return V_94 ;
}
static int F_116 ( struct V_154 * V_155 )
{
struct V_15 * V_16 = F_117 ( V_155 ) ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
struct V_156 * V_157 = F_100 ( V_155 , V_161 , 0 ) ;
F_118 ( V_16 ) ;
F_76 ( & V_2 -> V_129 ) ;
F_113 ( V_2 -> V_3 ) ;
F_114 ( V_16 ) ;
F_115 ( V_157 -> V_162 , F_102 ( V_157 ) ) ;
return 0 ;
}
