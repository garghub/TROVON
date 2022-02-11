static inline T_1 F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 . V_5 & V_6 )
return F_2 ( V_2 -> V_7 + V_3 ) ;
if ( V_2 -> V_4 . V_5 & V_8 )
return ( ( F_3 ( V_2 -> V_7 + V_3 ) & 0xFFFF ) |
( ( F_3 ( V_2 -> V_7 + V_3 + 2 ) & 0xFFFF ) << 16 ) ) ;
F_4 () ;
return 0 ;
}
static inline T_1
F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( V_2 -> V_4 . V_5 & V_6 )
return F_2 ( V_2 -> V_7 + F_6 ( V_2 , V_3 ) ) ;
if ( V_2 -> V_4 . V_5 & V_8 )
return ( F_3 ( V_2 -> V_7 +
F_6 ( V_2 , V_3 ) ) & 0xFFFF ) |
( ( F_3 ( V_2 -> V_7 +
F_6 ( V_2 , V_3 + 2 ) ) & 0xFFFF ) << 16 ) ;
F_4 () ;
return 0 ;
}
static inline T_1 F_7 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_9 ;
unsigned long V_5 ;
F_8 ( & V_2 -> V_10 , V_5 ) ;
V_9 = V_2 -> V_11 -> V_12 ( V_2 , V_3 ) ;
F_9 ( & V_2 -> V_10 , V_5 ) ;
return V_9 ;
}
static inline void F_10 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_13 )
{
if ( V_2 -> V_4 . V_5 & V_6 ) {
F_11 ( V_13 , V_2 -> V_7 + V_3 ) ;
return;
}
if ( V_2 -> V_4 . V_5 & V_8 ) {
F_12 ( V_13 & 0xFFFF , V_2 -> V_7 + V_3 ) ;
F_12 ( ( V_13 >> 16 ) & 0xFFFF , V_2 -> V_7 + V_3 + 2 ) ;
return;
}
F_4 () ;
}
static inline void
F_13 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_13 )
{
if ( V_2 -> V_4 . V_5 & V_6 ) {
F_11 ( V_13 , V_2 -> V_7 + F_6 ( V_2 , V_3 ) ) ;
return;
}
if ( V_2 -> V_4 . V_5 & V_8 ) {
F_12 ( V_13 & 0xFFFF ,
V_2 -> V_7 + F_6 ( V_2 , V_3 ) ) ;
F_12 ( ( V_13 >> 16 ) & 0xFFFF ,
V_2 -> V_7 + F_6 ( V_2 , V_3 + 2 ) ) ;
return;
}
F_4 () ;
}
static inline void F_14 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_13 )
{
unsigned long V_5 ;
F_8 ( & V_2 -> V_10 , V_5 ) ;
V_2 -> V_11 -> V_14 ( V_2 , V_3 , V_13 ) ;
F_9 ( & V_2 -> V_10 , V_5 ) ;
}
static inline void
F_15 ( struct V_1 * V_2 , unsigned int * V_15 ,
unsigned int V_16 )
{
unsigned long V_5 ;
F_8 ( & V_2 -> V_10 , V_5 ) ;
if ( V_2 -> V_4 . V_5 & V_17 ) {
while ( V_16 -- )
F_10 ( V_2 , V_18 ,
F_16 ( * V_15 ++ ) ) ;
goto V_19;
}
if ( V_2 -> V_4 . V_5 & V_6 ) {
F_17 ( V_2 -> V_7 + V_18 , V_15 , V_16 ) ;
goto V_19;
}
if ( V_2 -> V_4 . V_5 & V_8 ) {
while ( V_16 -- )
F_10 ( V_2 , V_18 , * V_15 ++ ) ;
goto V_19;
}
F_4 () ;
V_19:
F_9 ( & V_2 -> V_10 , V_5 ) ;
}
static inline void
F_18 ( struct V_1 * V_2 , unsigned int * V_15 ,
unsigned int V_16 )
{
unsigned long V_5 ;
F_8 ( & V_2 -> V_10 , V_5 ) ;
if ( V_2 -> V_4 . V_5 & V_17 ) {
while ( V_16 -- )
F_13 ( V_2 , V_18 ,
F_16 ( * V_15 ++ ) ) ;
goto V_19;
}
if ( V_2 -> V_4 . V_5 & V_6 ) {
F_17 ( V_2 -> V_7 + F_6 ( V_2 ,
V_18 ) , V_15 , V_16 ) ;
goto V_19;
}
if ( V_2 -> V_4 . V_5 & V_8 ) {
while ( V_16 -- )
F_13 ( V_2 ,
V_18 , * V_15 ++ ) ;
goto V_19;
}
F_4 () ;
V_19:
F_9 ( & V_2 -> V_10 , V_5 ) ;
}
static inline void
F_19 ( struct V_1 * V_2 , unsigned int * V_15 ,
unsigned int V_16 )
{
unsigned long V_5 ;
F_8 ( & V_2 -> V_10 , V_5 ) ;
if ( V_2 -> V_4 . V_5 & V_17 ) {
while ( V_16 -- )
* V_15 ++ = F_16 ( F_1 ( V_2 ,
V_20 ) ) ;
goto V_19;
}
if ( V_2 -> V_4 . V_5 & V_6 ) {
F_20 ( V_2 -> V_7 + V_20 , V_15 , V_16 ) ;
goto V_19;
}
if ( V_2 -> V_4 . V_5 & V_8 ) {
while ( V_16 -- )
* V_15 ++ = F_1 ( V_2 , V_20 ) ;
goto V_19;
}
F_4 () ;
V_19:
F_9 ( & V_2 -> V_10 , V_5 ) ;
}
static inline void
F_21 ( struct V_1 * V_2 , unsigned int * V_15 ,
unsigned int V_16 )
{
unsigned long V_5 ;
F_8 ( & V_2 -> V_10 , V_5 ) ;
if ( V_2 -> V_4 . V_5 & V_17 ) {
while ( V_16 -- )
* V_15 ++ = F_16 ( F_5 ( V_2 ,
V_20 ) ) ;
goto V_19;
}
if ( V_2 -> V_4 . V_5 & V_6 ) {
F_20 ( V_2 -> V_7 + F_6 ( V_2 ,
V_20 ) , V_15 , V_16 ) ;
goto V_19;
}
if ( V_2 -> V_4 . V_5 & V_8 ) {
while ( V_16 -- )
* V_15 ++ = F_5 ( V_2 ,
V_20 ) ;
goto V_19;
}
F_4 () ;
V_19:
F_9 ( & V_2 -> V_10 , V_5 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
int V_21 ;
T_1 V_13 ;
F_23 ( V_2 ) ;
for ( V_21 = 0 ; V_21 < 40 ; V_21 ++ ) {
V_13 = F_7 ( V_2 , V_22 ) ;
if ( ! ( V_13 & V_23 ) )
return 0 ;
}
F_24 ( V_2 , V_24 , L_1
L_2 , V_13 ) ;
return - V_25 ;
}
static T_1 F_25 ( struct V_1 * V_2 , unsigned int V_26 )
{
unsigned int V_27 ;
F_23 ( V_2 ) ;
V_27 = F_7 ( V_2 , V_22 ) ;
if ( F_26 ( V_27 & V_23 ) ) {
F_24 ( V_2 , V_24 , L_3 ) ;
return 0xFFFFFFFF ;
}
F_14 ( V_2 , V_22 , ( ( V_26 & 0xFF ) |
V_23 | V_28 ) ) ;
V_27 = F_7 ( V_2 , V_29 ) ;
if ( F_27 ( F_22 ( V_2 ) == 0 ) )
return F_7 ( V_2 , V_30 ) ;
F_24 ( V_2 , V_24 , L_4 ) ;
return 0xFFFFFFFF ;
}
static void F_28 ( struct V_1 * V_2 ,
unsigned int V_26 , T_1 V_13 )
{
unsigned int V_27 ;
F_23 ( V_2 ) ;
V_27 = F_7 ( V_2 , V_22 ) ;
if ( F_26 ( V_27 & V_23 ) ) {
F_24 ( V_2 , V_24 ,
L_5 ) ;
return;
}
F_14 ( V_2 , V_30 , V_13 ) ;
F_14 ( V_2 , V_22 , ( ( V_26 & 0xFF ) |
V_23 ) ) ;
V_27 = F_7 ( V_2 , V_29 ) ;
if ( F_27 ( F_22 ( V_2 ) == 0 ) )
return;
F_24 ( V_2 , V_24 , L_6 ) ;
}
static int F_29 ( struct V_31 * V_32 , int V_33 , int V_34 )
{
struct V_1 * V_2 = (struct V_1 * ) V_32 -> V_35 ;
unsigned long V_5 ;
unsigned int V_36 ;
int V_21 , V_3 ;
F_8 ( & V_2 -> V_37 , V_5 ) ;
if ( F_26 ( F_25 ( V_2 , V_38 ) & V_39 ) ) {
F_24 ( V_2 , V_24 , L_7 ) ;
V_3 = - V_25 ;
goto V_19;
}
V_36 = ( ( V_33 & 0x1F ) << 11 ) | ( ( V_34 & 0x1F ) << 6 ) ;
F_28 ( V_2 , V_38 , V_36 ) ;
for ( V_21 = 0 ; V_21 < 100 ; V_21 ++ )
if ( ! ( F_25 ( V_2 , V_38 ) & V_39 ) ) {
V_3 = F_25 ( V_2 , V_40 ) ;
goto V_19;
}
F_24 ( V_2 , V_24 , L_8 ) ;
V_3 = - V_25 ;
V_19:
F_9 ( & V_2 -> V_37 , V_5 ) ;
return V_3 ;
}
static int F_30 ( struct V_31 * V_32 , int V_33 , int V_34 ,
T_2 V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_32 -> V_35 ;
unsigned long V_5 ;
unsigned int V_36 ;
int V_21 , V_3 ;
F_8 ( & V_2 -> V_37 , V_5 ) ;
if ( F_26 ( F_25 ( V_2 , V_38 ) & V_39 ) ) {
F_24 ( V_2 , V_24 , L_9 ) ;
V_3 = - V_25 ;
goto V_19;
}
F_28 ( V_2 , V_40 , V_13 ) ;
V_36 = ( ( V_33 & 0x1F ) << 11 ) | ( ( V_34 & 0x1F ) << 6 ) |
V_41 ;
F_28 ( V_2 , V_38 , V_36 ) ;
for ( V_21 = 0 ; V_21 < 100 ; V_21 ++ )
if ( ! ( F_25 ( V_2 , V_38 ) & V_39 ) ) {
V_3 = 0 ;
goto V_19;
}
F_24 ( V_2 , V_24 , L_10 ) ;
V_3 = - V_25 ;
V_19:
F_9 ( & V_2 -> V_37 , V_5 ) ;
return V_3 ;
}
static void F_31 ( struct V_1 * V_2 )
{
unsigned int V_42 = F_7 ( V_2 , V_43 ) ;
V_42 &= ( ~ V_44 ) ;
V_42 |= V_45 ;
F_14 ( V_2 , V_43 , V_42 ) ;
F_32 ( 10 ) ;
V_42 |= V_46 ;
F_14 ( V_2 , V_43 , V_42 ) ;
V_42 &= ( ~ V_44 ) ;
V_42 |= V_47 ;
F_14 ( V_2 , V_43 , V_42 ) ;
F_32 ( 10 ) ;
V_42 |= V_48 ;
F_14 ( V_2 , V_43 , V_42 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
unsigned int V_42 = F_7 ( V_2 , V_43 ) ;
if ( V_2 -> V_4 . V_5 & V_49 ) {
F_34 ( V_2 , V_24 , L_11 ) ;
V_2 -> V_50 = 0 ;
} else if ( V_2 -> V_4 . V_5 & V_51 ) {
F_34 ( V_2 , V_24 , L_12 ) ;
F_31 ( V_2 ) ;
V_2 -> V_50 = 1 ;
} else if ( V_42 & V_52 ) {
F_34 ( V_2 , V_24 ,
L_13 ) ;
F_31 ( V_2 ) ;
V_2 -> V_50 = 1 ;
} else {
F_34 ( V_2 , V_24 ,
L_14 ) ;
V_2 -> V_50 = 0 ;
}
}
static unsigned int F_35 ( struct V_1 * V_2 )
{
unsigned int V_53 =
F_7 ( V_2 , V_54 ) & V_55 ;
if ( V_53 != 0 )
V_53 = F_7 ( V_2 , V_56 ) ;
return V_53 ;
}
static unsigned int F_36 ( struct V_1 * V_2 )
{
unsigned int V_53 =
F_7 ( V_2 , V_57 ) & V_58 ;
if ( V_53 != 0 )
V_53 = F_7 ( V_2 , V_59 ) ;
return V_53 ;
}
static int F_37 ( struct V_1 * V_2 )
{
unsigned int V_60 ;
T_1 V_61 ;
T_1 V_62 ;
T_3 V_63 ;
for ( V_60 = 0 ; V_60 < 10 ; V_60 ++ ) {
unsigned int V_64 ;
unsigned int V_65 ;
unsigned int V_66 ;
unsigned int V_67 ;
unsigned int V_21 ;
memset ( V_2 -> V_68 , 0 , V_69 ) ;
V_64 = ( T_1 ) ( ( T_3 ) V_2 -> V_70 & 0x03 ) << 16 ;
V_64 |= V_71 | V_72 ;
V_64 |= V_69 ;
V_65 = V_69 << 16 | V_69 ;
F_14 ( V_2 , V_18 , V_64 ) ;
F_14 ( V_2 , V_18 , V_65 ) ;
V_63 = ( T_3 ) V_2 -> V_70 & ( ~ 0x3 ) ;
V_61 = V_69 + 3 ;
V_61 += ( T_1 ) ( ( T_3 ) V_2 -> V_70 & 0x3 ) ;
V_61 >>= 2 ;
V_2 -> V_11 -> V_73 ( V_2 , ( unsigned int * ) V_63 , V_61 ) ;
V_21 = 60 ;
do {
F_32 ( 5 ) ;
V_66 = F_35 ( V_2 ) ;
} while ( ( V_21 -- ) && ( ! V_66 ) );
if ( ! V_66 ) {
F_24 ( V_2 , V_24 ,
L_15 ) ;
continue;
}
if ( V_66 & V_74 ) {
F_24 ( V_2 , V_24 ,
L_16 ) ;
continue;
}
V_21 = 60 ;
do {
F_32 ( 5 ) ;
V_66 = F_36 ( V_2 ) ;
} while ( ( V_21 -- ) && ( ! V_66 ) );
if ( ! V_66 ) {
F_24 ( V_2 , V_24 ,
L_17 ) ;
continue;
}
if ( V_66 & V_75 ) {
F_24 ( V_2 , V_24 ,
L_18 ) ;
continue;
}
V_67 = ( ( V_66 & 0x3FFF0000UL ) >> 16 ) ;
V_63 = ( T_3 ) V_2 -> V_68 ;
V_62 = V_67 + 3 ;
V_62 += ( T_1 ) ( ( T_3 ) V_2 -> V_68 & 0x3 ) ;
V_62 >>= 2 ;
V_2 -> V_11 -> V_76 ( V_2 , ( unsigned int * ) V_63 , V_62 ) ;
if ( V_67 != ( V_69 + 4 ) ) {
F_24 ( V_2 , V_24 , L_19
L_20 ,
V_67 ) ;
} else {
unsigned int V_77 ;
int V_78 = 0 ;
for ( V_77 = 0 ; V_77 < V_69 ; V_77 ++ ) {
if ( V_2 -> V_70 [ V_77 ]
!= V_2 -> V_68 [ V_77 ] ) {
V_78 = 1 ;
break;
}
}
if ( ! V_78 ) {
F_34 ( V_2 , V_24 , L_21
L_22 ) ;
return 0 ;
} else {
F_24 ( V_2 , V_24 , L_23
L_24 ) ;
}
}
}
return - V_25 ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
unsigned int V_27 ;
unsigned int V_21 = 100000 ;
F_39 ( ! V_80 ) ;
F_39 ( ! V_80 -> V_32 ) ;
F_34 ( V_2 , V_24 , L_25 ) ;
F_30 ( V_80 -> V_32 , V_80 -> V_36 , V_81 , V_82 ) ;
do {
F_40 ( 1 ) ;
V_27 = F_29 ( V_80 -> V_32 , V_80 -> V_36 ,
V_81 ) ;
} while ( ( V_21 -- ) && ( V_27 & V_82 ) );
if ( V_27 & V_82 ) {
F_24 ( V_2 , V_24 , L_26 ) ;
return - V_25 ;
}
F_40 ( 1 ) ;
return 0 ;
}
static int F_41 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
struct V_79 * V_80 = V_2 -> V_80 ;
int V_53 = - V_25 ;
unsigned int V_21 , V_13 ;
unsigned long V_5 ;
memset ( V_2 -> V_70 , 0xff , V_85 ) ;
for ( V_21 = 6 ; V_21 < 12 ; V_21 ++ )
V_2 -> V_70 [ V_21 ] = ( char ) V_21 ;
V_2 -> V_70 [ 12 ] = 0x00 ;
V_2 -> V_70 [ 13 ] = 0x00 ;
for ( V_21 = 14 ; V_21 < V_69 ; V_21 ++ )
V_2 -> V_70 [ V_21 ] = ( char ) V_21 ;
V_13 = F_7 ( V_2 , V_43 ) ;
V_13 &= V_86 ;
V_13 |= V_87 ;
F_14 ( V_2 , V_43 , V_13 ) ;
F_14 ( V_2 , V_88 , V_89 ) ;
F_14 ( V_2 , V_90 ,
( T_1 ) ( ( T_3 ) V_2 -> V_68 & 0x03 ) << 8 ) ;
for ( V_21 = 0 ; V_21 < 10 ; V_21 ++ ) {
F_30 ( V_80 -> V_32 , V_80 -> V_36 , V_81 ,
V_91 | V_92 ) ;
F_8 ( & V_2 -> V_37 , V_5 ) ;
F_28 ( V_2 , V_93 , V_94
| V_95 | V_96 ) ;
F_9 ( & V_2 -> V_37 , V_5 ) ;
if ( F_37 ( V_2 ) == 0 ) {
V_53 = 0 ;
break;
}
V_2 -> V_97 ++ ;
F_8 ( & V_2 -> V_37 , V_5 ) ;
F_28 ( V_2 , V_93 , 0 ) ;
F_9 ( & V_2 -> V_37 , V_5 ) ;
F_38 ( V_2 ) ;
}
F_8 ( & V_2 -> V_37 , V_5 ) ;
F_28 ( V_2 , V_93 , 0 ) ;
F_9 ( & V_2 -> V_37 , V_5 ) ;
F_30 ( V_80 -> V_32 , V_80 -> V_36 , V_81 , 0 ) ;
F_14 ( V_2 , V_88 , 0 ) ;
F_14 ( V_2 , V_90 , 0 ) ;
return V_53 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_79 * V_80 = V_2 -> V_80 ;
T_1 V_98 = F_7 ( V_2 , V_99 ) ;
T_1 V_100 ;
unsigned long V_5 ;
if ( V_80 -> V_101 == V_102 ) {
T_2 V_103 = F_44 ( V_80 , V_104 ) ;
T_2 V_105 = F_44 ( V_80 , V_106 ) ;
T_4 V_107 = F_45 ( V_103 , V_105 ) ;
if ( V_107 & V_108 )
V_100 = 0xFFFF0002 ;
else
V_100 = 0 ;
if ( V_107 & V_109 )
V_98 |= 0xF ;
else
V_98 &= ~ 0xF ;
F_34 ( V_2 , V_24 , L_27 ,
( V_107 & V_108 ? L_28 : L_29 ) ,
( V_107 & V_109 ? L_28 : L_29 ) ) ;
} else {
F_34 ( V_2 , V_24 , L_30 ) ;
V_100 = 0 ;
V_98 |= 0xF ;
}
F_8 ( & V_2 -> V_37 , V_5 ) ;
F_28 ( V_2 , V_110 , V_100 ) ;
F_9 ( & V_2 -> V_37 , V_5 ) ;
F_14 ( V_2 , V_99 , V_98 ) ;
}
static void F_46 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
struct V_79 * V_80 = V_2 -> V_80 ;
unsigned long V_5 ;
int V_111 ;
if ( V_80 -> V_101 != V_2 -> V_112 ) {
unsigned int V_113 ;
F_34 ( V_2 , V_24 , L_31 ) ;
F_8 ( & V_2 -> V_37 , V_5 ) ;
V_113 = F_25 ( V_2 , V_93 ) ;
if ( V_80 -> V_101 ) {
F_34 ( V_2 , V_24 ,
L_32 ) ;
V_113 |= V_94 ;
} else {
F_34 ( V_2 , V_24 ,
L_33 ) ;
V_113 &= ~ V_94 ;
}
F_28 ( V_2 , V_93 , V_113 ) ;
F_9 ( & V_2 -> V_37 , V_5 ) ;
F_43 ( V_2 ) ;
V_2 -> V_112 = V_80 -> V_101 ;
}
V_111 = F_47 ( V_84 ) ;
if ( V_111 != V_2 -> V_114 ) {
F_34 ( V_2 , V_24 , L_34 ) ;
if ( V_111 ) {
F_34 ( V_2 , V_24 , L_35 ) ;
if ( ( V_2 -> V_115 & V_116 ) &&
( ! V_2 -> V_50 ) ) {
V_2 -> V_117 = V_2 -> V_115 ;
F_14 ( V_2 , V_118 ,
V_2 -> V_117 ) ;
}
} else {
F_34 ( V_2 , V_24 , L_36 ) ;
V_2 -> V_117 = F_7 ( V_2 ,
V_118 ) ;
if ( ( V_2 -> V_117 & V_116 ) &&
( ! V_2 -> V_50 ) ) {
V_2 -> V_115 = V_2 -> V_117 ;
V_2 -> V_117 &= ~ V_116 ;
V_2 -> V_117 |= ( V_119
| V_120
| V_121 ) ;
F_14 ( V_2 , V_118 ,
V_2 -> V_117 ) ;
}
}
V_2 -> V_114 = V_111 ;
}
}
static int F_48 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
struct V_79 * V_122 = NULL ;
int V_123 ;
V_122 = F_49 ( V_2 -> V_31 ) ;
if ( ! V_122 ) {
F_50 ( V_84 , L_37 ) ;
return - V_124 ;
}
F_34 ( V_2 , V_125 , L_38 ,
V_122 -> V_36 , V_122 -> V_126 ) ;
V_123 = F_51 ( V_84 , V_122 ,
& F_46 , 0 ,
V_2 -> V_4 . V_127 ) ;
if ( V_123 ) {
F_50 ( V_84 , L_39 ) ;
return V_123 ;
}
F_52 ( V_84 ,
L_40 ,
V_122 -> V_128 -> V_129 , F_53 ( & V_122 -> V_84 ) , V_122 -> V_130 ) ;
V_122 -> V_131 &= ( V_132 | V_133 |
V_134 ) ;
V_122 -> V_135 = V_122 -> V_131 ;
V_2 -> V_80 = V_122 ;
V_2 -> V_112 = - 1 ;
V_2 -> V_114 = - 1 ;
#ifdef F_54
if ( F_41 ( V_84 ) < 0 ) {
F_24 ( V_2 , V_24 , L_41 ) ;
return - V_124 ;
}
F_34 ( V_2 , V_24 , L_42 ) ;
#endif
F_34 ( V_2 , V_24 , L_43 ) ;
return 0 ;
}
static int T_5 F_55 ( struct V_136 * V_137 ,
struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
int V_138 = - V_139 , V_21 ;
V_2 -> V_31 = F_56 () ;
if ( ! V_2 -> V_31 ) {
V_138 = - V_140 ;
goto V_141;
}
V_2 -> V_31 -> V_129 = V_142 ;
snprintf ( V_2 -> V_31 -> V_143 , V_144 , L_44 , V_137 -> V_143 ) ;
V_2 -> V_31 -> V_35 = V_2 ;
V_2 -> V_31 -> V_145 = F_29 ;
V_2 -> V_31 -> V_146 = F_30 ;
V_2 -> V_31 -> V_130 = V_2 -> V_147 ;
for ( V_21 = 0 ; V_21 < V_148 ; ++ V_21 )
V_2 -> V_31 -> V_130 [ V_21 ] = V_149 ;
V_2 -> V_31 -> V_150 = & V_137 -> V_84 ;
switch ( V_2 -> V_151 & 0xFFFF0000 ) {
case 0x01170000 :
case 0x01150000 :
case 0x117A0000 :
case 0x115A0000 :
F_33 ( V_2 ) ;
break;
default:
F_34 ( V_2 , V_24 , L_45
L_46 ) ;
V_2 -> V_50 = 0 ;
break;
}
if ( ! V_2 -> V_50 ) {
V_2 -> V_31 -> V_152 = ~ ( 1 << 1 ) ;
}
if ( F_57 ( V_2 -> V_31 ) ) {
F_24 ( V_2 , V_125 , L_47 ) ;
goto V_153;
}
if ( F_48 ( V_84 ) < 0 ) {
F_24 ( V_2 , V_125 , L_47 ) ;
goto V_154;
}
return 0 ;
V_154:
F_58 ( V_2 -> V_31 ) ;
V_153:
F_59 ( V_2 -> V_31 ) ;
V_141:
return V_138 ;
}
static unsigned int F_60 ( struct V_1 * V_2 )
{
return ( F_7 ( V_2 , V_54 )
& V_55 ) >> 16 ;
}
static void F_61 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
unsigned int V_155 ;
while ( ( V_155 = F_35 ( V_2 ) ) != 0 ) {
if ( F_26 ( V_155 & 0x80000000 ) ) {
F_24 ( V_2 , V_24 , L_48 ) ;
} else {
if ( F_26 ( V_155 & V_74 ) ) {
V_84 -> V_156 . V_157 ++ ;
} else {
V_84 -> V_156 . V_158 ++ ;
V_84 -> V_156 . V_159 += ( V_155 >> 16 ) ;
}
if ( F_26 ( V_155 & V_160 ) ) {
V_84 -> V_156 . V_161 += 16 ;
V_84 -> V_156 . V_162 += 1 ;
} else {
V_84 -> V_156 . V_161 +=
( ( V_155 >> 3 ) & 0xF ) ;
}
if ( F_26 ( V_155 & V_163 ) )
V_84 -> V_156 . V_164 += 1 ;
if ( F_26 ( V_155 & V_165 ) ) {
V_84 -> V_156 . V_161 ++ ;
V_84 -> V_156 . V_162 ++ ;
}
}
}
}
static void
F_62 ( struct V_83 * V_84 , unsigned int V_166 )
{
int V_167 = 0 ;
if ( F_26 ( V_166 & V_75 ) ) {
V_84 -> V_156 . V_168 ++ ;
if ( F_26 ( V_166 & V_169 ) ) {
V_84 -> V_156 . V_170 ++ ;
V_167 = 1 ;
}
}
if ( F_27 ( ! V_167 ) ) {
if ( F_26 ( ( V_166 & V_171 ) &&
( V_166 & V_172 ) ) )
V_84 -> V_156 . V_173 ++ ;
if ( V_166 & V_174 )
V_84 -> V_156 . V_175 ++ ;
}
}
static void
F_63 ( struct V_1 * V_2 , unsigned int V_176 )
{
unsigned int V_177 = ( V_176 + V_178 + 3 ) >> 2 ;
if ( F_27 ( V_177 >= 4 ) ) {
unsigned int V_179 = 500 ;
unsigned int V_13 ;
F_14 ( V_2 , V_180 , V_181 ) ;
do {
F_32 ( 1 ) ;
V_13 = F_7 ( V_2 , V_180 ) ;
} while ( ( V_13 & V_181 ) && -- V_179 );
if ( F_26 ( V_179 == 0 ) )
F_24 ( V_2 , V_24 , L_49
L_50 , V_13 ) ;
} else {
unsigned int V_27 ;
while ( V_177 -- )
V_27 = F_7 ( V_2 , V_20 ) ;
}
}
static int F_64 ( struct V_182 * V_183 , int V_184 )
{
struct V_1 * V_2 =
F_65 ( V_183 , struct V_1 , V_183 ) ;
struct V_83 * V_84 = V_2 -> V_84 ;
int V_185 = 0 ;
while ( V_185 < V_184 ) {
unsigned int V_67 ;
unsigned int V_177 ;
struct V_186 * V_187 ;
unsigned int V_166 = F_36 ( V_2 ) ;
if ( ! V_166 ) {
unsigned int V_27 ;
F_14 ( V_2 , V_188 , V_189 ) ;
F_66 ( V_183 ) ;
V_27 = F_7 ( V_2 , V_190 ) ;
V_27 |= V_191 ;
F_14 ( V_2 , V_190 , V_27 ) ;
break;
}
V_185 ++ ;
V_67 = ( ( V_166 & 0x3FFF0000 ) >> 16 ) ;
V_177 = ( V_67 + V_178 + 3 ) >> 2 ;
F_62 ( V_84 , V_166 ) ;
if ( F_26 ( V_166 & V_75 ) ) {
F_24 ( V_2 , V_192 ,
L_51 ) ;
F_63 ( V_2 , V_177 ) ;
V_84 -> V_156 . V_193 ++ ;
continue;
}
V_187 = F_67 ( V_84 , V_67 + V_178 ) ;
if ( F_26 ( ! V_187 ) ) {
F_24 ( V_2 , V_192 ,
L_52 ) ;
F_63 ( V_2 , V_177 ) ;
V_84 -> V_156 . V_193 ++ ;
break;
}
V_187 -> V_9 = V_187 -> V_194 ;
F_68 ( V_187 ) ;
F_69 ( V_187 , V_178 ) ;
F_70 ( V_187 , V_67 - 4 ) ;
V_2 -> V_11 -> V_76 ( V_2 ,
( unsigned int * ) V_187 -> V_194 , V_177 ) ;
V_187 -> V_195 = F_71 ( V_187 , V_84 ) ;
F_72 ( V_187 ) ;
F_73 ( V_187 ) ;
V_84 -> V_156 . V_196 ++ ;
V_84 -> V_156 . V_197 += ( V_67 - 4 ) ;
}
return V_185 ;
}
static unsigned int F_74 ( char V_36 [ V_85 ] )
{
return ( F_75 ( V_85 , V_36 ) >> 26 ) & 0x3f ;
}
static void F_76 ( struct V_1 * V_2 )
{
unsigned int V_113 ;
F_23 ( V_2 ) ;
V_113 = F_25 ( V_2 , V_93 ) ;
V_113 |= V_2 -> V_198 ;
V_113 &= ~ ( V_2 -> V_199 ) ;
F_28 ( V_2 , V_93 , V_113 ) ;
F_28 ( V_2 , V_200 , V_2 -> V_201 ) ;
F_28 ( V_2 , V_202 , V_2 -> V_203 ) ;
F_34 ( V_2 , V_24 , L_53 ,
V_113 , V_2 -> V_201 , V_2 -> V_203 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
unsigned int V_113 ;
F_78 ( & V_2 -> V_37 ) ;
if ( F_25 ( V_2 , V_93 ) & V_96 )
F_24 ( V_2 , V_128 , L_54 ) ;
F_76 ( V_2 ) ;
V_113 = F_25 ( V_2 , V_93 ) ;
V_113 |= V_96 ;
F_28 ( V_2 , V_93 , V_113 ) ;
V_2 -> V_204 = 0 ;
F_79 ( & V_2 -> V_37 ) ;
}
static int F_80 ( struct V_1 * V_2 )
{
unsigned int V_179 ;
unsigned int V_27 ;
F_14 ( V_2 , V_43 , V_205 ) ;
V_179 = 10 ;
do {
F_32 ( 10 ) ;
V_27 = F_7 ( V_2 , V_43 ) ;
} while ( ( -- V_179 ) && ( V_27 & V_205 ) );
if ( F_26 ( V_27 & V_205 ) ) {
F_24 ( V_2 , V_128 , L_55 ) ;
return - V_25 ;
}
return 0 ;
}
static void
F_81 ( struct V_1 * V_2 , T_4 V_206 [ 6 ] )
{
T_1 V_207 = ( V_206 [ 5 ] << 8 ) | V_206 [ 4 ] ;
T_1 V_208 = ( V_206 [ 3 ] << 24 ) | ( V_206 [ 2 ] << 16 ) |
( V_206 [ 1 ] << 8 ) | V_206 [ 0 ] ;
F_23 ( V_2 ) ;
F_28 ( V_2 , V_209 , V_207 ) ;
F_28 ( V_2 , V_210 , V_208 ) ;
}
static int F_82 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
unsigned int V_179 ;
unsigned int V_27 ;
unsigned int V_211 ;
if ( ! V_2 -> V_80 ) {
F_24 ( V_2 , V_24 , L_56 ) ;
return - V_212 ;
}
if ( ! F_83 ( V_84 -> V_206 ) ) {
F_24 ( V_2 , V_24 , L_57 ) ;
return - V_213 ;
}
if ( F_80 ( V_2 ) ) {
F_24 ( V_2 , V_24 , L_58 ) ;
return - V_25 ;
}
F_14 ( V_2 , V_43 , 0x00050000 ) ;
F_14 ( V_2 , V_99 , 0x006E3740 ) ;
F_84 ( & V_2 -> V_37 ) ;
F_28 ( V_2 , V_214 , V_215 ) ;
F_85 ( & V_2 -> V_37 ) ;
V_179 = 50 ;
while ( ( F_7 ( V_2 , V_216 ) & V_217 ) &&
-- V_179 ) {
F_32 ( 10 ) ;
}
if ( F_26 ( V_179 == 0 ) )
F_24 ( V_2 , V_218 ,
L_59 ) ;
F_14 ( V_2 , V_118 , 0x70070000 ) ;
F_84 ( & V_2 -> V_37 ) ;
F_81 ( V_2 , V_84 -> V_206 ) ;
F_85 ( & V_2 -> V_37 ) ;
F_14 ( V_2 , V_190 , 0 ) ;
F_14 ( V_2 , V_188 , 0xFFFFFFFF ) ;
V_211 = ( ( 10 << 24 ) | V_219 ) ;
if ( V_2 -> V_4 . V_220 ) {
F_34 ( V_2 , V_218 , L_60 ) ;
V_211 |= V_221 ;
} else {
F_34 ( V_2 , V_218 , L_61 ) ;
}
if ( V_2 -> V_4 . V_222 ) {
F_34 ( V_2 , V_218 , L_62 ) ;
V_211 |= V_223 ;
} else {
F_34 ( V_2 , V_218 , L_63 ) ;
}
F_14 ( V_2 , V_224 , V_211 ) ;
F_34 ( V_2 , V_218 , L_64 , V_84 -> V_130 ) ;
V_2 -> V_225 = 0 ;
F_86 () ;
V_27 = F_7 ( V_2 , V_190 ) ;
V_27 |= V_226 ;
F_14 ( V_2 , V_190 , V_27 ) ;
V_179 = 1000 ;
while ( V_179 -- ) {
if ( V_2 -> V_225 )
break;
F_40 ( 1 ) ;
}
if ( ! V_2 -> V_225 ) {
F_87 ( V_84 , L_65 ,
V_84 -> V_130 ) ;
return - V_124 ;
}
F_34 ( V_2 , V_218 , L_66 ,
V_84 -> V_130 ) ;
F_52 ( V_84 , L_67 ,
( unsigned long ) V_2 -> V_7 , V_84 -> V_130 ) ;
V_2 -> V_112 = - 1 ;
V_2 -> V_114 = - 1 ;
F_88 ( V_2 -> V_80 ) ;
V_27 = F_7 ( V_2 , V_43 ) ;
V_27 &= ( V_86 | 0x00000FFF ) ;
V_27 |= V_87 ;
F_14 ( V_2 , V_43 , V_27 ) ;
V_27 = F_7 ( V_2 , V_227 ) ;
V_27 |= V_228 ;
V_27 &= ~ ( V_229 ) ;
F_14 ( V_2 , V_227 , V_27 ) ;
F_14 ( V_2 , V_90 , ( 2 << 8 ) ) ;
F_89 ( & V_2 -> V_183 ) ;
V_27 = F_7 ( V_2 , V_190 ) ;
V_27 |= ( V_230 | V_191 | V_231 ) ;
F_14 ( V_2 , V_190 , V_27 ) ;
F_84 ( & V_2 -> V_37 ) ;
V_27 = F_25 ( V_2 , V_93 ) ;
V_27 |= ( V_95 | V_96 | V_232 ) ;
F_28 ( V_2 , V_93 , V_27 ) ;
F_85 ( & V_2 -> V_37 ) ;
F_14 ( V_2 , V_88 , V_89 ) ;
F_90 ( V_84 ) ;
return 0 ;
}
static int F_91 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
unsigned int V_27 ;
V_27 = F_7 ( V_2 , V_224 ) ;
V_27 &= ~ V_219 ;
F_14 ( V_2 , V_224 , V_27 ) ;
F_92 ( V_84 ) ;
F_93 ( & V_2 -> V_183 ) ;
V_84 -> V_156 . V_193 += F_7 ( V_2 , V_233 ) ;
F_61 ( V_84 ) ;
if ( V_2 -> V_80 )
F_94 ( V_2 -> V_80 ) ;
F_34 ( V_2 , V_234 , L_68 ) ;
return 0 ;
}
static int F_95 ( struct V_186 * V_187 , struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
unsigned int V_235 ;
unsigned int V_236 ;
unsigned int V_237 ;
unsigned int V_27 ;
T_1 V_61 ;
T_3 V_63 ;
V_235 = F_7 ( V_2 , V_54 ) & V_238 ;
if ( F_26 ( V_235 < V_239 ) )
F_24 ( V_2 , V_240 ,
L_69 , V_235 ) ;
V_236 = ( T_1 ) ( ( T_3 ) V_187 -> V_9 & 0x03 ) << 16 ;
V_236 |= V_71 | V_72 ;
V_236 |= ( unsigned int ) V_187 -> V_241 ;
V_237 = ( ( unsigned int ) V_187 -> V_241 ) << 16 ;
V_237 |= ( unsigned int ) V_187 -> V_241 ;
F_14 ( V_2 , V_18 , V_236 ) ;
F_14 ( V_2 , V_18 , V_237 ) ;
V_63 = ( T_3 ) V_187 -> V_9 & ( ~ 0x3 ) ;
V_61 = ( T_1 ) V_187 -> V_241 + 3 ;
V_61 += ( T_1 ) ( ( T_3 ) V_187 -> V_9 & 0x3 ) ;
V_61 >>= 2 ;
V_2 -> V_11 -> V_73 ( V_2 , ( unsigned int * ) V_63 , V_61 ) ;
V_235 -= ( V_187 -> V_241 + 32 ) ;
F_96 ( V_187 ) ;
F_97 ( V_187 ) ;
if ( F_26 ( F_60 ( V_2 ) >= 30 ) )
F_61 ( V_84 ) ;
if ( V_235 < V_239 ) {
F_92 ( V_84 ) ;
V_27 = F_7 ( V_2 , V_227 ) ;
V_27 &= 0x00FFFFFF ;
V_27 |= 0x32000000 ;
F_14 ( V_2 , V_227 , V_27 ) ;
}
return V_242 ;
}
static struct V_243 * F_98 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
F_61 ( V_84 ) ;
V_84 -> V_156 . V_193 += F_7 ( V_2 , V_233 ) ;
return & V_84 -> V_156 ;
}
static void F_99 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
unsigned long V_5 ;
if ( V_84 -> V_5 & V_244 ) {
V_2 -> V_198 = V_245 ;
V_2 -> V_199 = ( V_246 | V_247 ) ;
V_2 -> V_201 = 0 ;
V_2 -> V_203 = 0 ;
} else if ( V_84 -> V_5 & V_248 ) {
V_2 -> V_198 = V_246 ;
V_2 -> V_199 = ( V_245 | V_247 ) ;
V_2 -> V_201 = 0 ;
V_2 -> V_203 = 0 ;
} else if ( ! F_100 ( V_84 ) ) {
unsigned int V_249 = 0 ;
unsigned int V_250 = 0 ;
struct V_251 * V_252 ;
V_2 -> V_198 = V_247 ;
V_2 -> V_199 = ( V_245 | V_246 ) ;
F_101 (ha, dev) {
unsigned int V_253 = F_74 ( V_252 -> V_36 ) ;
unsigned int V_254 = 0x01 << ( V_253 & 0x1F ) ;
if ( V_253 & 0x20 )
V_249 |= V_254 ;
else
V_250 |= V_254 ;
}
V_2 -> V_201 = V_249 ;
V_2 -> V_203 = V_250 ;
} else {
V_2 -> V_198 = 0 ;
V_2 -> V_199 =
( V_245 | V_246 | V_247 ) ;
V_2 -> V_201 = 0 ;
V_2 -> V_203 = 0 ;
}
F_8 ( & V_2 -> V_37 , V_5 ) ;
if ( V_2 -> V_255 <= 1 ) {
if ( ! V_2 -> V_204 ) {
unsigned int V_27 ;
F_34 ( V_2 , V_24 , L_70 ) ;
V_2 -> V_204 = 1 ;
V_27 = F_25 ( V_2 , V_93 ) ;
V_27 &= ~ ( V_96 ) ;
F_28 ( V_2 , V_93 , V_27 ) ;
} else {
}
} else {
F_76 ( V_2 ) ;
}
F_9 ( & V_2 -> V_37 , V_5 ) ;
}
static T_6 F_102 ( int V_130 , void * V_256 )
{
struct V_83 * V_84 = V_256 ;
struct V_1 * V_2 = F_42 ( V_84 ) ;
T_1 V_257 = F_7 ( V_2 , V_188 ) ;
T_1 V_258 = F_7 ( V_2 , V_190 ) ;
int V_259 = V_260 ;
T_1 V_27 ;
if ( F_26 ( V_257 & V_258 & V_261 ) ) {
V_27 = F_7 ( V_2 , V_190 ) ;
V_27 &= ( ~ V_226 ) ;
F_14 ( V_2 , V_190 , V_27 ) ;
F_14 ( V_2 , V_188 , V_261 ) ;
V_2 -> V_225 = 1 ;
F_86 () ;
V_259 = V_262 ;
}
if ( F_26 ( V_257 & V_258 & V_263 ) ) {
F_34 ( V_2 , V_264 , L_71 ) ;
F_14 ( V_2 , V_188 , V_263 ) ;
if ( V_2 -> V_204 )
F_77 ( V_2 ) ;
V_259 = V_262 ;
}
if ( V_257 & V_258 & V_265 ) {
V_27 = F_7 ( V_2 , V_227 ) ;
V_27 |= V_228 ;
F_14 ( V_2 , V_227 , V_27 ) ;
F_14 ( V_2 , V_188 , V_265 ) ;
F_103 ( V_84 ) ;
V_259 = V_262 ;
}
if ( F_26 ( V_257 & V_258 & V_266 ) ) {
F_34 ( V_2 , V_264 , L_72 ) ;
F_14 ( V_2 , V_188 , V_266 ) ;
V_259 = V_262 ;
}
if ( F_27 ( V_257 & V_258 & V_189 ) ) {
if ( F_27 ( F_104 ( & V_2 -> V_183 ) ) ) {
V_27 = F_7 ( V_2 , V_190 ) ;
V_27 &= ( ~ V_191 ) ;
F_14 ( V_2 , V_190 , V_27 ) ;
F_105 ( & V_2 -> V_183 ) ;
} else {
F_24 ( V_2 , V_192 , L_73 ) ;
}
V_259 = V_262 ;
}
return V_259 ;
}
static void F_106 ( struct V_83 * V_84 )
{
F_107 ( V_84 -> V_130 ) ;
F_102 ( 0 , V_84 ) ;
F_108 ( V_84 -> V_130 ) ;
}
static int F_109 ( struct V_83 * V_84 , void * V_267 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
struct V_268 * V_36 = V_267 ;
if ( V_2 -> V_255 <= 1 && F_110 ( V_84 ) )
return - V_269 ;
if ( ! F_83 ( V_36 -> V_270 ) )
return - V_213 ;
memcpy ( V_84 -> V_206 , V_36 -> V_270 , V_85 ) ;
F_84 ( & V_2 -> V_37 ) ;
F_81 ( V_2 , V_84 -> V_206 ) ;
F_85 ( & V_2 -> V_37 ) ;
F_52 ( V_84 , L_74 , V_84 -> V_206 ) ;
return 0 ;
}
static int F_111 ( struct V_83 * V_84 , struct V_271 * V_272 , int V_273 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
if ( ! F_110 ( V_84 ) || ! V_2 -> V_80 )
return - V_274 ;
return F_112 ( V_2 -> V_80 , V_272 , V_273 ) ;
}
static int
F_113 ( struct V_83 * V_84 , struct V_275 * V_273 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
V_273 -> V_276 = 1 ;
V_273 -> V_277 = 1 ;
return F_114 ( V_2 -> V_80 , V_273 ) ;
}
static int
F_115 ( struct V_83 * V_84 , struct V_275 * V_273 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
return F_116 ( V_2 -> V_80 , V_273 ) ;
}
static void F_117 ( struct V_83 * V_84 ,
struct V_278 * V_279 )
{
F_118 ( V_279 -> V_280 , V_281 , sizeof( V_279 -> V_280 ) ) ;
F_118 ( V_279 -> V_282 , V_283 , sizeof( V_279 -> V_282 ) ) ;
F_118 ( V_279 -> V_284 , F_53 ( V_84 -> V_84 . V_150 ) ,
sizeof( V_279 -> V_284 ) ) ;
}
static int F_119 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
return F_120 ( V_2 -> V_80 ) ;
}
static T_1 F_121 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
return V_2 -> V_285 ;
}
static void F_122 ( struct V_83 * V_84 , T_1 V_286 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
V_2 -> V_285 = V_286 ;
}
static int F_123 ( struct V_83 * V_84 )
{
return ( ( ( V_287 - V_288 ) / 4 + 1 ) + ( V_289 - V_93 ) + 1 + 32 ) *
sizeof( T_1 ) ;
}
static void
F_124 ( struct V_83 * V_84 , struct V_290 * V_291 ,
void * V_15 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
struct V_79 * V_80 = V_2 -> V_80 ;
unsigned long V_5 ;
unsigned int V_21 ;
unsigned int V_77 = 0 ;
T_1 * V_9 = V_15 ;
V_291 -> V_282 = V_2 -> V_151 ;
for ( V_21 = V_288 ; V_21 <= V_287 ; V_21 += ( sizeof( T_1 ) ) )
V_9 [ V_77 ++ ] = F_7 ( V_2 , V_21 ) ;
for ( V_21 = V_93 ; V_21 <= V_289 ; V_21 ++ ) {
F_8 ( & V_2 -> V_37 , V_5 ) ;
V_9 [ V_77 ++ ] = F_25 ( V_2 , V_21 ) ;
F_9 ( & V_2 -> V_37 , V_5 ) ;
}
for ( V_21 = 0 ; V_21 <= 31 ; V_21 ++ )
V_9 [ V_77 ++ ] = F_29 ( V_80 -> V_32 , V_80 -> V_36 , V_21 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
unsigned int V_27 = F_7 ( V_2 , V_118 ) ;
V_27 &= ~ V_292 ;
F_14 ( V_2 , V_118 , V_27 ) ;
F_40 ( 1 ) ;
}
static int F_126 ( struct V_1 * V_2 , T_1 V_293 )
{
int V_179 = 100 ;
T_1 V_294 ;
F_34 ( V_2 , V_128 , L_75 , V_293 ) ;
if ( F_7 ( V_2 , V_216 ) & V_217 ) {
F_24 ( V_2 , V_128 , L_76 ) ;
return - V_269 ;
}
V_294 = V_293 | V_217 ;
F_14 ( V_2 , V_216 , V_294 ) ;
do {
F_40 ( 1 ) ;
V_294 = F_7 ( V_2 , V_216 ) ;
} while ( ( V_294 & V_217 ) && ( -- V_179 ) );
if ( ! V_179 ) {
F_34 ( V_2 , V_128 , L_77 ) ;
return - V_212 ;
}
if ( V_294 & V_295 ) {
F_34 ( V_2 , V_128 , L_78 ) ;
return - V_274 ;
}
return 0 ;
}
static int F_127 ( struct V_1 * V_2 ,
T_4 V_296 , T_4 * V_9 )
{
T_1 V_293 = V_297 | V_296 ;
int V_123 ;
F_34 ( V_2 , V_128 , L_79 , V_296 ) ;
V_123 = F_126 ( V_2 , V_293 ) ;
if ( ! V_123 )
V_9 [ V_296 ] = F_7 ( V_2 , V_287 ) ;
return V_123 ;
}
static int F_128 ( struct V_1 * V_2 ,
T_4 V_296 , T_4 V_9 )
{
T_1 V_293 = V_298 | V_296 ;
T_1 V_27 ;
int V_123 ;
F_34 ( V_2 , V_128 , L_80 , V_296 , V_9 ) ;
V_123 = F_126 ( V_2 , V_293 ) ;
if ( ! V_123 ) {
V_293 = V_299 | V_296 ;
F_14 ( V_2 , V_287 , ( T_1 ) V_9 ) ;
V_27 = F_7 ( V_2 , V_29 ) ;
V_123 = F_126 ( V_2 , V_293 ) ;
}
return V_123 ;
}
static int F_129 ( struct V_83 * V_84 )
{
return V_300 ;
}
static int F_130 ( struct V_83 * V_84 ,
struct V_301 * V_302 , T_4 * V_9 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
T_4 V_303 [ V_300 ] ;
int V_241 ;
int V_21 ;
F_125 ( V_2 ) ;
V_241 = F_131 ( V_302 -> V_241 , V_300 ) ;
for ( V_21 = 0 ; V_21 < V_241 ; V_21 ++ ) {
int V_123 = F_127 ( V_2 , V_21 , V_303 ) ;
if ( V_123 < 0 ) {
V_302 -> V_241 = 0 ;
return V_123 ;
}
}
memcpy ( V_9 , & V_303 [ V_302 -> V_26 ] , V_241 ) ;
V_302 -> V_241 = V_241 ;
return 0 ;
}
static int F_132 ( struct V_83 * V_84 ,
struct V_301 * V_302 , T_4 * V_9 )
{
int V_123 ;
struct V_1 * V_2 = F_42 ( V_84 ) ;
F_125 ( V_2 ) ;
F_126 ( V_2 , V_304 ) ;
V_123 = F_128 ( V_2 , V_302 -> V_26 , * V_9 ) ;
F_126 ( V_2 , V_305 ) ;
V_302 -> V_241 = 1 ;
return V_123 ;
}
static void T_5 F_133 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
T_1 V_207 = F_25 ( V_2 , V_209 ) ;
T_1 V_208 = F_25 ( V_2 , V_210 ) ;
V_84 -> V_206 [ 0 ] = ( T_4 ) ( V_208 ) ;
V_84 -> V_206 [ 1 ] = ( T_4 ) ( V_208 >> 8 ) ;
V_84 -> V_206 [ 2 ] = ( T_4 ) ( V_208 >> 16 ) ;
V_84 -> V_206 [ 3 ] = ( T_4 ) ( V_208 >> 24 ) ;
V_84 -> V_206 [ 4 ] = ( T_4 ) ( V_207 ) ;
V_84 -> V_206 [ 5 ] = ( T_4 ) ( V_207 >> 8 ) ;
}
static int T_5 F_134 ( struct V_83 * V_84 )
{
struct V_1 * V_2 = F_42 ( V_84 ) ;
unsigned int V_306 ;
unsigned int V_307 = 100 ;
F_34 ( V_2 , V_125 , L_81 ) ;
F_34 ( V_2 , V_125 , L_82 ,
( unsigned long ) V_2 -> V_7 ) ;
F_34 ( V_2 , V_125 , L_83 , V_84 -> V_130 ) ;
F_34 ( V_2 , V_125 , L_84 ) ;
F_135 ( & V_2 -> V_10 ) ;
F_135 ( & V_2 -> V_37 ) ;
if ( V_2 -> V_7 == 0 ) {
F_24 ( V_2 , V_125 , L_85 ) ;
return - V_124 ;
}
while ( ! ( F_7 ( V_2 , V_308 ) & V_309 ) && -- V_307 )
F_32 ( 1000 ) ;
if ( V_307 == 0 ) {
F_136 ( L_86 ) ;
return - V_124 ;
}
V_306 = F_7 ( V_2 , V_29 ) ;
F_34 ( V_2 , V_125 , L_87 , V_306 ) ;
if ( V_306 == 0x43218765 ) {
F_34 ( V_2 , V_125 , L_88
L_89 ) ;
F_14 ( V_2 , V_310 , 0xffffffff ) ;
V_306 = F_7 ( V_2 , V_29 ) ;
V_306 = F_7 ( V_2 , V_29 ) ;
}
if ( V_306 != 0x87654321 ) {
F_24 ( V_2 , V_128 , L_87 , V_306 ) ;
if ( ( ( V_306 >> 16 ) & 0xFFFF ) == ( V_306 & 0xFFFF ) ) {
F_24 ( V_2 , V_125 ,
L_90 ) ;
F_34 ( V_2 , V_125 ,
L_91
L_92 ) ;
}
return - V_124 ;
}
V_2 -> V_255 = 0 ;
V_2 -> V_151 = F_7 ( V_2 , V_288 ) ;
switch ( V_2 -> V_151 & 0xFFFF0000 ) {
case 0x01180000 :
case 0x01170000 :
case 0x01160000 :
case 0x01150000 :
case 0x218A0000 :
V_2 -> V_255 = V_2 -> V_151 & 0x0000FFFF ;
break;
case 0x118A0000 :
case 0x117A0000 :
case 0x116A0000 :
case 0x115A0000 :
V_2 -> V_255 = 3 ;
break;
case 0x92100000 :
case 0x92110000 :
case 0x92200000 :
case 0x92210000 :
V_2 -> V_255 = 4 ;
break;
default:
F_24 ( V_2 , V_125 , L_93 ,
V_2 -> V_151 ) ;
return - V_124 ;
}
F_34 ( V_2 , V_125 ,
L_94 ,
V_2 -> V_151 , V_2 -> V_255 ) ;
if ( V_2 -> V_255 == 0 )
F_24 ( V_2 , V_125 ,
L_95 ) ;
if ( V_2 -> V_4 . V_5 & V_311 ) {
F_84 ( & V_2 -> V_37 ) ;
F_133 ( V_84 ) ;
F_85 ( & V_2 -> V_37 ) ;
}
if ( F_80 ( V_2 ) )
return - V_124 ;
F_14 ( V_2 , V_190 , 0 ) ;
F_137 ( V_84 ) ;
V_84 -> V_5 |= V_312 ;
F_138 ( V_84 , & V_2 -> V_183 , F_64 , V_313 ) ;
V_84 -> V_314 = & V_315 ;
V_84 -> V_316 = & V_317 ;
return 0 ;
}
static int T_7 F_139 ( struct V_136 * V_137 )
{
struct V_83 * V_84 ;
struct V_1 * V_2 ;
struct V_318 * V_319 ;
V_84 = F_140 ( V_137 ) ;
F_39 ( ! V_84 ) ;
V_2 = F_42 ( V_84 ) ;
F_39 ( ! V_2 ) ;
F_39 ( ! V_2 -> V_7 ) ;
F_39 ( ! V_2 -> V_80 ) ;
F_34 ( V_2 , V_234 , L_96 ) ;
F_141 ( V_2 -> V_80 ) ;
V_2 -> V_80 = NULL ;
F_58 ( V_2 -> V_31 ) ;
F_59 ( V_2 -> V_31 ) ;
F_142 ( V_137 , NULL ) ;
F_143 ( V_84 ) ;
F_144 ( V_84 -> V_130 , V_84 ) ;
V_319 = F_145 ( V_137 , V_320 ,
L_97 ) ;
if ( ! V_319 )
V_319 = F_146 ( V_137 , V_320 , 0 ) ;
F_147 ( V_319 -> V_321 , F_148 ( V_319 ) ) ;
F_149 ( V_2 -> V_7 ) ;
F_150 ( V_84 ) ;
return 0 ;
}
static int T_5 F_151 (
struct V_322 * V_4 ,
struct V_323 * V_324 )
{
const char * V_325 ;
T_1 V_326 = 0 ;
if ( ! V_324 )
return - V_124 ;
V_4 -> V_127 = F_152 ( V_324 ) ;
V_325 = F_153 ( V_324 ) ;
if ( V_325 )
memcpy ( V_4 -> V_325 , V_325 , V_85 ) ;
F_154 ( V_324 , L_98 , & V_4 -> V_327 ) ;
F_154 ( V_324 , L_99 , & V_326 ) ;
if ( V_326 == 4 )
V_4 -> V_5 |= V_6 ;
else
V_4 -> V_5 |= V_8 ;
if ( F_155 ( V_324 , L_100 , NULL ) )
V_4 -> V_220 = V_328 ;
if ( F_155 ( V_324 , L_101 , NULL ) )
V_4 -> V_222 = V_329 ;
if ( F_155 ( V_324 , L_102 , NULL ) )
V_4 -> V_5 |= V_49 ;
if ( F_155 ( V_324 , L_103 , NULL ) )
V_4 -> V_5 |= V_51 ;
if ( F_155 ( V_324 , L_104 , NULL ) )
V_4 -> V_5 |= V_311 ;
return 0 ;
}
static inline int F_151 (
struct V_322 * V_4 ,
struct V_323 * V_324 )
{
return - V_124 ;
}
static int T_5 F_156 ( struct V_136 * V_137 )
{
struct V_323 * V_324 = V_137 -> V_84 . V_330 ;
struct V_83 * V_84 ;
struct V_1 * V_2 ;
struct V_322 * V_4 = V_137 -> V_84 . V_331 ;
struct V_318 * V_319 , * V_332 ;
unsigned int V_211 = 0 ;
int V_333 , V_334 ;
int V_335 ;
F_157 ( L_105 , V_283 ) ;
V_319 = F_145 ( V_137 , V_320 ,
L_97 ) ;
if ( ! V_319 )
V_319 = F_146 ( V_137 , V_320 , 0 ) ;
if ( ! V_319 ) {
F_158 ( L_106 ) ;
V_335 = - V_124 ;
goto V_336;
}
V_333 = F_148 ( V_319 ) ;
V_332 = F_146 ( V_137 , V_337 , 0 ) ;
if ( ! V_332 ) {
F_158 ( L_107 ) ;
V_335 = - V_124 ;
goto V_336;
}
if ( ! F_159 ( V_319 -> V_321 , V_333 , V_281 ) ) {
V_335 = - V_269 ;
goto V_336;
}
V_84 = F_160 ( sizeof( struct V_1 ) ) ;
if ( ! V_84 ) {
F_158 ( L_108 ) ;
V_335 = - V_140 ;
goto V_338;
}
F_161 ( V_84 , & V_137 -> V_84 ) ;
V_2 = F_42 ( V_84 ) ;
V_84 -> V_130 = V_332 -> V_321 ;
V_334 = V_332 -> V_5 & V_339 ;
V_2 -> V_7 = F_162 ( V_319 -> V_321 , V_333 ) ;
V_2 -> V_84 = V_84 ;
V_2 -> V_285 = ( ( 1 << V_340 ) - 1 ) ;
if ( V_2 -> V_7 == NULL ) {
F_24 ( V_2 , V_125 , L_109 ) ;
V_335 = - V_140 ;
goto V_341;
}
V_335 = F_151 ( & V_2 -> V_4 , V_324 ) ;
if ( V_335 && V_4 ) {
memcpy ( & V_2 -> V_4 , V_4 , sizeof( V_2 -> V_4 ) ) ;
V_335 = 0 ;
}
if ( V_335 ) {
F_24 ( V_2 , V_125 , L_110 ) ;
goto V_342;
}
V_2 -> V_11 = & V_343 ;
if ( V_2 -> V_4 . V_327 )
V_2 -> V_11 = & V_344 ;
V_335 = F_134 ( V_84 ) ;
if ( V_335 < 0 )
goto V_342;
if ( V_2 -> V_4 . V_220 == V_328 )
V_211 |= V_221 ;
if ( V_2 -> V_4 . V_222 == V_329 )
V_211 |= V_223 ;
F_14 ( V_2 , V_224 , V_211 ) ;
F_14 ( V_2 , V_190 , 0 ) ;
F_14 ( V_2 , V_188 , 0xFFFFFFFF ) ;
V_335 = F_163 ( V_84 -> V_130 , F_102 ,
V_334 | V_345 , V_84 -> V_129 , V_84 ) ;
if ( V_335 ) {
F_24 ( V_2 , V_125 ,
L_111 , V_84 -> V_130 ) ;
goto V_342;
}
F_142 ( V_137 , V_84 ) ;
V_335 = F_164 ( V_84 ) ;
if ( V_335 ) {
F_24 ( V_2 , V_125 , L_112 , V_335 ) ;
goto V_346;
} else {
F_34 ( V_2 , V_125 ,
L_113 , V_84 -> V_129 ) ;
}
V_335 = F_55 ( V_137 , V_84 ) ;
if ( V_335 ) {
F_24 ( V_2 , V_125 , L_114 , V_335 ) ;
goto V_347;
}
F_84 ( & V_2 -> V_37 ) ;
if ( F_83 ( V_84 -> V_206 ) ) {
F_81 ( V_2 , V_84 -> V_206 ) ;
F_34 ( V_2 , V_125 ,
L_115 ) ;
} else if ( F_83 ( V_2 -> V_4 . V_325 ) ) {
memcpy ( V_84 -> V_206 , V_2 -> V_4 . V_325 , 6 ) ;
F_34 ( V_2 , V_125 ,
L_116 ) ;
} else {
F_165 ( V_84 ) ;
if ( F_83 ( V_84 -> V_206 ) ) {
F_34 ( V_2 , V_125 ,
L_117 ) ;
} else {
F_166 ( V_84 -> V_206 ) ;
F_81 ( V_2 , V_84 -> V_206 ) ;
F_34 ( V_2 , V_125 ,
L_118 ) ;
}
}
F_85 ( & V_2 -> V_37 ) ;
F_52 ( V_84 , L_74 , V_84 -> V_206 ) ;
return 0 ;
V_347:
F_143 ( V_84 ) ;
V_346:
F_142 ( V_137 , NULL ) ;
F_144 ( V_84 -> V_130 , V_84 ) ;
V_342:
F_149 ( V_2 -> V_7 ) ;
V_341:
F_150 ( V_84 ) ;
V_338:
F_147 ( V_319 -> V_321 , F_148 ( V_319 ) ) ;
V_336:
return V_335 ;
}
static int F_167 ( struct V_348 * V_84 )
{
struct V_83 * V_349 = F_168 ( V_84 ) ;
struct V_1 * V_2 = F_42 ( V_349 ) ;
F_14 ( V_2 , V_308 ,
V_350 | V_351 |
V_352 | V_353 ) ;
return 0 ;
}
static int F_169 ( struct V_348 * V_84 )
{
struct V_83 * V_349 = F_168 ( V_84 ) ;
struct V_1 * V_2 = F_42 ( V_349 ) ;
unsigned int V_307 = 100 ;
F_14 ( V_2 , V_29 , 0 ) ;
while ( ! ( F_7 ( V_2 , V_308 ) & V_309 ) && -- V_307 )
F_32 ( 1000 ) ;
return ( V_307 == 0 ) ? - V_25 : 0 ;
}
static int T_8 F_170 ( void )
{
F_171 () ;
return F_172 ( & V_354 ) ;
}
static void T_9 F_173 ( void )
{
F_174 ( & V_354 ) ;
}
