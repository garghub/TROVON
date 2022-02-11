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
V_50 -> V_53 = V_50 -> V_60 -> V_61 -> V_62 ( V_50 -> V_60 ,
& V_50 -> V_56 , 1 , V_59 ,
V_63 | V_64 ) ;
if ( ! V_50 -> V_53 )
return V_55 ;
V_50 -> V_53 -> V_65 = V_16 ;
V_50 -> V_53 -> V_66 = V_67 ;
V_50 -> V_53 -> V_68 ( V_50 -> V_53 ) ;
V_16 -> V_69 . V_70 += V_48 -> V_57 ;
F_42 ( V_48 ) ;
return V_71 ;
}
static int F_43 ( struct V_47 * V_48 , struct V_15 * V_16 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
int V_57 = V_48 -> V_57 ;
F_37 ( V_16 , L_2 ,
V_54 , V_48 -> V_57 , V_48 -> V_72 , V_48 -> V_73 ,
F_44 ( V_48 ) , F_45 ( V_48 ) ) ;
if ( F_34 ( V_2 ) < V_57 + 8 )
return V_55 ;
if ( V_2 -> V_11 & V_74 ) {
T_1 * V_75 = ( T_1 * ) V_48 -> V_73 ;
F_7 ( V_2 , 17 , 0x8000 | 0x100 , V_76 ) ;
F_7 ( V_2 , 17 , ( T_1 ) V_57 , V_77 ) ;
V_16 -> V_69 . V_70 += V_57 ;
while ( V_57 > 0 ) {
F_4 ( * V_75 ++ , V_2 -> V_3 + V_76 ) ;
F_4 ( * V_75 ++ , V_2 -> V_3 + V_77 ) ;
V_57 -= sizeof( T_3 ) ;
}
} else {
T_3 * V_78 = ( T_3 * ) V_48 -> V_73 ;
T_3 V_79 ;
V_79 = 0x8000 | 0x100 | ( V_57 << 16 ) ;
F_11 ( V_2 , 17 , V_79 , V_76 ) ;
V_16 -> V_69 . V_70 += V_57 ;
while ( V_57 > 0 ) {
F_2 ( * V_78 , V_2 -> V_3 + V_76 ) ;
V_57 -= sizeof( T_3 ) ;
V_78 ++ ;
}
}
F_7 ( V_2 , 17 , 1 , V_80 ) ;
F_42 ( V_48 ) ;
return V_71 ;
}
static void F_46 ( struct V_15 * V_16 , T_3 V_81 )
{
F_37 ( V_16 , L_3 , V_81 ) ;
V_16 -> V_69 . V_82 ++ ;
if ( V_81 & V_83 )
V_16 -> V_69 . V_84 ++ ;
if ( V_81 & V_85 )
V_16 -> V_69 . V_86 ++ ;
if ( V_81 & V_87 )
V_16 -> V_69 . V_88 ++ ;
}
static void F_47 ( struct V_15 * V_16 , T_3 V_81 ,
int V_57 )
{
F_37 ( V_16 , L_4 , V_57 ) ;
V_16 -> V_69 . V_89 ++ ;
V_16 -> V_69 . V_90 += V_57 ;
if ( V_81 & V_91 )
V_16 -> V_69 . V_92 ++ ;
}
static int F_48 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
struct V_93 * V_50 = & V_2 -> V_94 ;
struct V_95 * V_56 = & V_50 -> V_56 ;
int V_96 ;
V_50 -> V_48 = F_49 ( V_16 , V_97 ) ;
if ( V_50 -> V_48 ) {
F_50 ( V_56 , 1 ) ;
F_41 ( V_56 ) = F_51 ( V_2 -> V_58 ,
V_50 -> V_48 -> V_73 , V_97 , V_98 ) ;
V_96 = F_52 ( V_2 -> V_58 , F_41 ( V_56 ) ) ;
if ( F_53 ( V_96 ) ) {
F_41 ( V_56 ) = 0 ;
goto V_99;
}
F_38 ( V_56 ) = V_97 ;
V_50 -> V_53 = V_50 -> V_60 -> V_61 -> V_62 ( V_50 -> V_60 ,
V_56 , 1 , V_98 ,
V_63 | V_64 ) ;
if ( ! V_50 -> V_53 )
goto V_99;
V_50 -> V_53 -> V_65 = V_16 ;
V_50 -> V_53 -> V_66 = V_100 ;
V_50 -> V_53 -> V_68 ( V_50 -> V_53 ) ;
} else {
V_96 = - V_101 ;
F_41 ( V_56 ) = 0 ;
goto V_99;
}
return V_96 ;
V_99:
if ( F_41 ( V_56 ) )
F_54 ( V_2 -> V_58 , F_41 ( V_56 ) ,
V_97 , V_98 ) ;
F_41 ( V_56 ) = 0 ;
if ( V_50 -> V_48 )
F_42 ( V_50 -> V_48 ) ;
V_50 -> V_48 = NULL ;
F_55 (KERN_ERR DRV_NAMEL_5 , err) ;
return V_96 ;
}
static void F_56 ( unsigned long V_102 )
{
struct V_15 * V_16 = (struct V_15 * ) V_102 ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
struct V_93 * V_50 = & V_2 -> V_94 ;
struct V_47 * V_48 = V_50 -> V_48 ;
T_4 V_103 = F_41 ( & V_50 -> V_56 ) ;
T_3 V_81 ;
V_50 -> V_53 = NULL ;
F_48 ( V_16 ) ;
F_54 ( V_2 -> V_58 , V_103 , V_97 , V_98 ) ;
V_81 = * ( ( T_3 * ) V_48 -> V_73 ) ;
F_37 ( V_16 , L_6 ,
V_54 , V_81 & 0xffff ) ;
if ( ( V_81 & V_104 ) && ! ( V_81 & V_105 ) ) {
int V_57 = ( V_81 >> 16 ) & 0x7ff ;
F_47 ( V_16 , V_81 , V_57 ) ;
F_57 ( V_48 , 4 ) ;
F_58 ( V_48 , V_57 ) ;
V_48 -> V_106 = F_59 ( V_48 , V_16 ) ;
F_60 ( V_48 ) ;
} else {
F_46 ( V_16 , V_81 ) ;
F_42 ( V_48 ) ;
}
}
static void F_61 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
T_3 V_81 ;
int V_57 ;
if ( V_2 -> V_11 & V_74 ) {
V_81 = F_14 ( V_2 , 17 , V_76 ) ;
V_57 = F_14 ( V_2 , 17 , V_77 ) ;
F_37 ( V_16 , L_6 ,
V_54 , V_81 ) ;
} else {
V_81 = F_15 ( V_2 , 17 , V_76 ) ;
V_57 = ( V_81 >> 16 ) & 0x7ff ;
V_81 &= 0xffff ;
F_37 ( V_16 , L_6 ,
V_54 , V_81 ) ;
}
if ( ( V_81 & V_104 ) && ! ( V_81 & V_105 ) ) {
struct V_47 * V_48 = F_62 ( V_16 , V_57 + 3 ) ;
if ( V_48 ) {
F_47 ( V_16 , V_81 , V_57 ) ;
if ( V_2 -> V_11 & V_74 ) {
T_1 * V_107 = ( T_1 * ) F_58 ( V_48 , V_57 ) ;
F_3 ( V_2 , 17 ) ;
while ( V_57 > 0 ) {
* V_107 ++ = F_9 ( V_2 -> V_3 +
V_76 ) ;
* V_107 ++ = F_9 ( V_2 -> V_3 +
V_77 ) ;
V_57 -= sizeof( T_3 ) ;
}
} else {
T_3 * V_73 = ( T_3 * ) F_58 ( V_48 , V_57 ) ;
F_3 ( V_2 , 17 ) ;
while ( V_57 > 0 ) {
* V_73 ++ = F_16 ( V_2 -> V_3 +
V_76 ) ;
V_57 -= sizeof( T_3 ) ;
}
}
V_48 -> V_106 = F_59 ( V_48 , V_16 ) ;
F_60 ( V_48 ) ;
} else
V_16 -> V_69 . V_108 ++ ;
} else
F_46 ( V_16 , V_81 ) ;
F_10 ( V_2 , 0 , 1 << 12 , V_22 ) ;
F_7 ( V_2 , 17 , 0x01 , V_109 ) ;
F_8 ( V_2 , 0 , 1 << 12 , V_22 ) ;
}
void F_63 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
T_1 V_110 = F_14 ( V_2 , 16 , V_111 ) & 0x1fff ;
F_37 ( V_16 , L_7 , V_54 , V_110 ) ;
while ( V_110 ) {
F_61 ( V_16 , V_2 ) ;
V_110 = F_14 ( V_2 , 16 , V_111 ) & 0x1fff ;
}
}
void F_64 ( struct V_15 * V_16 , struct V_1 * V_2 )
{
T_1 V_112 = F_14 ( V_2 , 16 , V_113 ) ;
F_37 ( V_16 , L_8 , V_54 , V_112 ) ;
V_16 -> V_69 . V_114 ++ ;
if ( F_65 ( V_16 ) )
F_21 ( V_16 ) ;
}
void F_66 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
F_37 ( V_16 , L_9 , V_54 ) ;
V_16 -> V_69 . V_82 ++ ;
V_16 -> V_69 . V_115 ++ ;
}
void F_67 ( unsigned long V_102 )
{
struct V_15 * V_16 = (struct V_15 * ) V_102 ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
T_1 V_116 ;
unsigned long V_44 ;
T_1 V_117 ;
F_32 ( & V_2 -> V_45 , V_44 ) ;
V_117 = F_9 ( V_2 -> V_3 + V_6 ) ;
F_33 ( & V_2 -> V_45 , V_44 ) ;
V_116 = F_14 ( V_2 , 18 , V_27 ) ;
F_37 ( V_16 , L_10 , V_54 , V_116 ) ;
if ( F_29 ( V_2 ) )
V_116 &= ~ V_118 ;
F_7 ( V_2 , 18 , V_116 , V_27 ) ;
if ( ! ( V_2 -> V_11 & V_12 ) )
F_2 ( 0x1 , V_2 -> V_3 + V_119 ) ;
if ( ! F_68 ( V_16 ) )
return;
if ( V_116 & V_120 )
F_19 ( V_16 , V_2 ) ;
if ( V_116 & ( V_118 | V_121 ) && ! F_29 ( V_2 ) )
F_63 ( V_16 , V_2 ) ;
if ( V_116 & V_122 )
F_64 ( V_16 , V_2 ) ;
if ( V_116 & V_123 )
F_66 ( V_16 , V_2 ) ;
if ( V_116 & V_124 ) {
F_25 ( V_2 ) ;
F_24 ( V_2 ) ;
}
if ( V_116 & V_125 ) {
F_27 ( V_2 ) ;
F_26 ( V_2 ) ;
}
F_32 ( & V_2 -> V_45 , V_44 ) ;
if ( F_29 ( V_2 ) )
F_7 ( V_2 , 18 , V_30 , V_31 ) ;
else
F_7 ( V_2 , 18 , V_32 , V_31 ) ;
F_4 ( V_117 , V_2 -> V_3 + V_6 ) ;
if ( F_29 ( V_2 ) )
F_1 ( V_2 ) ;
F_33 ( & V_2 -> V_45 , V_44 ) ;
}
static T_5 F_69 ( int V_126 , void * V_127 )
{
struct V_15 * V_16 = V_127 ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
T_1 V_116 ;
T_1 V_117 = F_9 ( V_2 -> V_3 + V_6 ) ;
T_5 V_128 = V_129 ;
V_116 = F_14 ( V_2 , 18 , V_27 ) ;
F_37 ( V_16 , L_10 , V_54 , V_116 ) ;
if ( V_116 ) {
if ( F_29 ( V_2 ) )
F_7 ( V_2 , 18 , V_118 , V_31 ) ;
else
F_7 ( V_2 , 18 , 0x00 , V_31 ) ;
F_70 ( & V_2 -> V_130 ) ;
V_128 = V_131 ;
}
F_4 ( V_117 , V_2 -> V_3 + V_6 ) ;
F_1 ( V_2 ) ;
return V_128 ;
}
static void V_100 ( void * V_73 )
{
struct V_15 * V_16 = V_73 ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
F_37 ( V_16 , L_11 ) ;
if ( V_2 -> V_94 . V_53 )
F_70 ( & V_2 -> V_94 . V_130 ) ;
}
static void V_67 ( void * V_73 )
{
struct V_15 * V_16 = V_73 ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
struct V_49 * V_50 = & V_2 -> V_51 ;
F_37 ( V_16 , L_12 ) ;
if ( ! V_50 -> V_53 )
return;
V_16 -> V_69 . V_114 ++ ;
V_50 -> V_53 = NULL ;
if ( F_65 ( V_16 ) )
F_21 ( V_16 ) ;
}
static void F_71 ( struct V_1 * V_2 )
{
struct V_49 * V_132 = & V_2 -> V_51 ;
struct V_93 * V_133 = & V_2 -> V_94 ;
V_132 -> V_53 = NULL ;
if ( V_132 -> V_60 )
V_132 -> V_60 -> V_61 -> V_134 ( V_132 -> V_60 ,
V_135 , 0 ) ;
V_133 -> V_53 = NULL ;
if ( V_133 -> V_60 )
V_133 -> V_60 -> V_61 -> V_134 ( V_133 -> V_60 ,
V_135 , 0 ) ;
if ( F_41 ( & V_133 -> V_56 ) )
F_54 ( V_2 -> V_58 , F_41 ( & V_133 -> V_56 ) ,
V_97 , V_98 ) ;
F_41 ( & V_133 -> V_56 ) = 0 ;
F_42 ( V_133 -> V_48 ) ;
V_133 -> V_48 = NULL ;
}
static void F_72 ( struct V_1 * V_2 )
{
struct V_49 * V_132 = & V_2 -> V_51 ;
struct V_93 * V_133 = & V_2 -> V_94 ;
F_71 ( V_2 ) ;
if ( V_132 -> V_60 )
F_73 ( V_132 -> V_60 ) ;
V_132 -> V_60 = NULL ;
if ( V_133 -> V_60 )
F_73 ( V_133 -> V_60 ) ;
V_133 -> V_60 = NULL ;
F_74 ( & V_133 -> V_130 ) ;
if ( F_41 ( & V_132 -> V_56 ) )
F_54 ( V_2 -> V_58 , F_41 ( & V_132 -> V_56 ) ,
V_97 , V_59 ) ;
F_41 ( & V_132 -> V_56 ) = 0 ;
F_75 ( V_132 -> V_52 ) ;
V_132 -> V_52 = NULL ;
}
static bool F_76 ( struct V_136 * V_60 , void * V_137 )
{
return V_60 -> V_138 == ( long ) V_137 ;
}
static int F_77 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
struct V_49 * V_132 = & V_2 -> V_51 ;
struct V_93 * V_133 = & V_2 -> V_94 ;
int V_96 ;
T_6 V_139 ;
F_78 ( V_139 ) ;
F_79 ( V_140 , V_139 ) ;
F_79 ( V_141 , V_139 ) ;
F_50 ( & V_132 -> V_56 , 1 ) ;
V_132 -> V_60 = F_80 ( V_139 , F_76 ,
( void * ) ( long ) V_132 -> V_142 ) ;
if ( ! V_132 -> V_60 ) {
V_96 = - V_143 ;
goto V_96;
}
V_132 -> V_52 = F_81 ( V_97 , V_144 ) ;
if ( ! V_132 -> V_52 ) {
V_96 = - V_101 ;
goto V_96;
}
F_41 ( & V_132 -> V_56 ) = F_51 ( V_2 -> V_58 ,
V_132 -> V_52 , V_97 , V_59 ) ;
V_96 = F_52 ( V_2 -> V_58 ,
F_41 ( & V_132 -> V_56 ) ) ;
if ( V_96 ) {
F_41 ( & V_132 -> V_56 ) = 0 ;
goto V_96;
}
V_133 -> V_60 = F_80 ( V_139 , F_76 ,
( void * ) ( long ) V_133 -> V_142 ) ;
if ( ! V_133 -> V_60 ) {
V_96 = - V_143 ;
goto V_96;
}
F_82 ( & V_133 -> V_130 , F_56 ,
( unsigned long ) V_16 ) ;
return 0 ;
V_96:
F_72 ( V_2 ) ;
return V_96 ;
}
static int F_83 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
int V_96 ;
F_37 ( V_16 , L_13 , V_54 ) ;
if ( F_29 ( V_2 ) ) {
V_96 = F_77 ( V_16 ) ;
if ( ! V_96 ) {
V_96 = F_48 ( V_16 ) ;
if ( V_96 )
F_72 ( V_2 ) ;
}
if ( V_96 ) {
F_55 (KERN_WARNING DRV_NAME
L_14 ) ;
F_72 ( V_2 ) ;
V_2 -> V_94 . V_142 = - 1 ;
V_2 -> V_51 . V_142 = - 1 ;
}
}
F_28 ( V_2 ) ;
F_31 ( V_2 , V_16 -> V_145 ) ;
F_19 ( V_16 , V_2 ) ;
V_96 = F_84 ( V_2 -> V_126 , F_69 , V_146 , V_147 ,
V_16 ) ;
if ( V_96 ) {
F_85 ( L_15 , V_2 -> V_126 , V_96 ) ;
return V_96 ;
}
return 0 ;
}
static int F_86 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
F_37 ( V_16 , L_13 , V_54 ) ;
F_87 ( & V_2 -> V_148 ) ;
if ( F_29 ( V_2 ) )
F_72 ( V_2 ) ;
F_88 ( V_2 -> V_126 , V_16 ) ;
F_7 ( V_2 , 32 , 0x0 , V_33 ) ;
return 0 ;
}
static T_7 F_89 ( struct V_47 * V_48 ,
struct V_15 * V_16 )
{
int V_128 ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
F_37 ( V_16 , L_9 , V_54 ) ;
if ( F_29 ( V_2 ) ) {
unsigned long V_44 ;
V_128 = F_35 ( V_48 , V_16 ) ;
F_32 ( & V_2 -> V_45 , V_44 ) ;
if ( V_2 -> V_51 . V_53 )
F_22 ( V_16 ) ;
F_33 ( & V_2 -> V_45 , V_44 ) ;
return V_128 ;
}
V_128 = F_43 ( V_48 , V_16 ) ;
if ( F_34 ( V_2 ) < V_16 -> V_149 + 8 )
F_22 ( V_16 ) ;
return V_128 ;
}
static int F_90 ( struct V_15 * V_16 , void * V_150 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
struct V_151 * V_103 = V_150 ;
char * V_36 = ( T_2 * ) V_103 -> V_152 ;
F_37 ( V_16 , L_9 , V_54 ) ;
if ( ! F_91 ( V_103 -> V_152 ) )
return - V_153 ;
memcpy ( V_16 -> V_145 , V_36 , V_16 -> V_154 ) ;
F_31 ( V_2 , V_36 ) ;
return 0 ;
}
static void F_92 ( struct V_155 * V_156 )
{
struct V_1 * V_2 =
F_93 ( V_156 , struct V_1 , V_148 ) ;
struct V_15 * V_16 = V_2 -> V_16 ;
unsigned long V_44 ;
F_37 ( V_16 , L_9 , V_54 ) ;
F_32 ( & V_2 -> V_45 , V_44 ) ;
if ( F_29 ( V_2 ) )
F_71 ( V_2 ) ;
F_7 ( V_2 , 18 , 0 , V_31 ) ;
F_7 ( V_2 , 18 , 0xFFFF , V_27 ) ;
F_22 ( V_16 ) ;
F_33 ( & V_2 -> V_45 , V_44 ) ;
F_28 ( V_2 ) ;
F_31 ( V_2 , V_16 -> V_145 ) ;
F_19 ( V_16 , V_2 ) ;
if ( F_29 ( V_2 ) )
F_48 ( V_16 ) ;
}
static void F_94 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_36 ( V_16 ) ;
F_37 ( V_16 , L_9 , V_54 ) ;
F_95 ( & V_2 -> V_148 ) ;
}
static int T_8 F_96 ( struct V_157 * V_158 )
{
int V_96 = - V_101 ;
struct V_159 * V_160 ;
struct V_15 * V_16 ;
struct V_1 * V_2 ;
struct V_161 * V_162 = V_158 -> V_58 . V_163 ;
T_1 V_164 ;
unsigned V_35 ;
V_160 = F_97 ( V_158 , V_165 , 0 ) ;
if ( ! F_98 ( V_160 -> V_166 , F_99 ( V_160 ) , V_147 ) )
goto V_167;
V_16 = F_100 ( sizeof( struct V_1 ) ) ;
if ( ! V_16 )
goto V_168;
F_101 ( V_16 , & V_158 -> V_58 ) ;
V_2 = F_36 ( V_16 ) ;
V_2 -> V_16 = V_16 ;
F_102 ( & V_2 -> V_148 , F_92 ) ;
V_2 -> V_3 = F_103 ( V_160 -> V_166 , F_99 ( V_160 ) ) ;
V_2 -> V_11 = V_160 -> V_44 ;
if ( ! V_2 -> V_3 )
goto V_169;
V_2 -> V_126 = F_104 ( V_158 , 0 ) ;
if ( V_2 -> V_126 < 0 ) {
V_96 = V_2 -> V_126 ;
goto V_170;
}
V_2 -> V_58 = ( V_158 -> V_58 . V_171 ) ? V_158 -> V_58 . V_171 : & V_158 -> V_58 ;
if ( ! ( V_2 -> V_11 & V_12 ) && V_162 &&
( V_162 -> V_172 != - 1 ) &&
( V_162 -> V_173 != - 1 ) ) {
V_2 -> V_94 . V_142 = V_162 -> V_173 ;
V_2 -> V_51 . V_142 = V_162 -> V_172 ;
} else {
V_2 -> V_94 . V_142 = - 1 ;
V_2 -> V_51 . V_142 = - 1 ;
}
F_82 ( & V_2 -> V_130 , F_67 , ( unsigned long ) V_16 ) ;
F_105 ( & V_2 -> V_45 ) ;
V_16 -> V_174 = & V_175 ;
V_16 -> V_176 = & V_177 ;
V_35 = V_16 -> V_154 ;
if ( V_162 ) {
for ( V_35 = 0 ; V_35 < V_16 -> V_154 ; V_35 ++ )
if ( V_162 -> V_178 [ V_35 ] != 0 )
break;
if ( V_35 < V_16 -> V_154 )
memcpy ( V_16 -> V_145 , V_162 -> V_178 ,
V_16 -> V_154 ) ;
}
if ( V_35 == V_16 -> V_154 ) {
F_30 ( V_2 , V_16 -> V_145 ) ;
if ( ! F_91 ( V_16 -> V_145 ) )
F_106 ( V_16 -> V_145 ) ;
}
V_164 = F_14 ( V_2 , 32 , V_33 ) ;
strcpy ( V_16 -> V_179 , L_16 ) ;
V_96 = F_107 ( V_16 ) ;
if ( V_96 )
goto V_180;
F_108 ( V_158 , V_16 ) ;
F_109 ( L_17 ,
( V_164 >> 8 ) & 0xff , ( V_164 >> 4 ) & 0xf , ( V_164 >> 1 ) & 0x7 ) ;
return 0 ;
V_180:
V_170:
F_110 ( V_2 -> V_3 ) ;
V_169:
F_111 ( V_16 ) ;
V_168:
F_112 ( V_160 -> V_166 , F_99 ( V_160 ) ) ;
V_167:
return V_96 ;
}
static int T_9 F_113 ( struct V_157 * V_158 )
{
struct V_15 * V_16 = F_114 ( V_158 ) ;
struct V_1 * V_2 = F_36 ( V_16 ) ;
struct V_159 * V_160 = F_97 ( V_158 , V_165 , 0 ) ;
F_115 ( V_16 ) ;
F_74 ( & V_2 -> V_130 ) ;
F_110 ( V_2 -> V_3 ) ;
F_111 ( V_16 ) ;
F_112 ( V_160 -> V_166 , F_99 ( V_160 ) ) ;
F_108 ( V_158 , NULL ) ;
return 0 ;
}
static int T_10 F_116 ( void )
{
return F_117 ( & V_181 ) ;
}
static void T_11 F_118 ( void )
{
F_119 ( & V_181 ) ;
}
