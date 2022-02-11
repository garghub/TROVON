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
static int F_22 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_23 ( V_22 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
int V_25 = 0 ;
V_25 = F_25 ( F_26 ( V_2 -> V_26 ) ,
V_2 -> V_26 ) ;
if ( V_25 )
F_27 ( V_24 , L_1 ,
V_25 ) ;
return V_25 ;
}
static int F_28 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_23 ( V_22 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
int V_25 = 0 ;
V_25 = F_29 ( F_26 ( V_2 -> V_26 ) ,
V_2 -> V_26 ) ;
return V_25 ;
}
static int F_30 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_23 ( V_22 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
int V_25 = 0 ;
V_2 -> V_26 [ 0 ] . V_27 = L_2 ;
V_2 -> V_26 [ 1 ] . V_27 = L_3 ;
V_25 = F_31 ( & V_22 -> V_28 ,
F_26 ( V_2 -> V_26 ) ,
V_2 -> V_26 ) ;
if ( V_25 )
F_27 ( V_24 , L_4 ,
V_25 ) ;
return V_25 ;
}
static void F_32 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_23 ( V_22 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
F_33 ( F_26 ( V_2 -> V_26 ) ,
V_2 -> V_26 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
int V_29 ;
T_1 V_13 ;
F_35 ( V_2 ) ;
for ( V_29 = 0 ; V_29 < 40 ; V_29 ++ ) {
V_13 = F_7 ( V_2 , V_30 ) ;
if ( ! ( V_13 & V_31 ) )
return 0 ;
}
F_36 ( V_2 , V_32 , L_5
L_6 , V_13 ) ;
return - V_33 ;
}
static T_1 F_37 ( struct V_1 * V_2 , unsigned int V_34 )
{
unsigned int V_35 ;
F_35 ( V_2 ) ;
V_35 = F_7 ( V_2 , V_30 ) ;
if ( F_38 ( V_35 & V_31 ) ) {
F_36 ( V_2 , V_32 , L_7 ) ;
return 0xFFFFFFFF ;
}
F_14 ( V_2 , V_30 , ( ( V_34 & 0xFF ) |
V_31 | V_36 ) ) ;
V_35 = F_7 ( V_2 , V_37 ) ;
if ( F_39 ( F_34 ( V_2 ) == 0 ) )
return F_7 ( V_2 , V_38 ) ;
F_36 ( V_2 , V_32 , L_8 ) ;
return 0xFFFFFFFF ;
}
static void F_40 ( struct V_1 * V_2 ,
unsigned int V_34 , T_1 V_13 )
{
unsigned int V_35 ;
F_35 ( V_2 ) ;
V_35 = F_7 ( V_2 , V_30 ) ;
if ( F_38 ( V_35 & V_31 ) ) {
F_36 ( V_2 , V_32 ,
L_9 ) ;
return;
}
F_14 ( V_2 , V_38 , V_13 ) ;
F_14 ( V_2 , V_30 , ( ( V_34 & 0xFF ) |
V_31 ) ) ;
V_35 = F_7 ( V_2 , V_37 ) ;
if ( F_39 ( F_34 ( V_2 ) == 0 ) )
return;
F_36 ( V_2 , V_32 , L_10 ) ;
}
static int F_41 ( struct V_39 * V_40 , int V_41 , int V_42 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 -> V_43 ;
unsigned long V_5 ;
unsigned int V_44 ;
int V_29 , V_3 ;
F_8 ( & V_2 -> V_45 , V_5 ) ;
if ( F_38 ( F_37 ( V_2 , V_46 ) & V_47 ) ) {
F_36 ( V_2 , V_32 , L_11 ) ;
V_3 = - V_33 ;
goto V_19;
}
V_44 = ( ( V_41 & 0x1F ) << 11 ) | ( ( V_42 & 0x1F ) << 6 ) ;
F_40 ( V_2 , V_46 , V_44 ) ;
for ( V_29 = 0 ; V_29 < 100 ; V_29 ++ )
if ( ! ( F_37 ( V_2 , V_46 ) & V_47 ) ) {
V_3 = F_37 ( V_2 , V_48 ) ;
goto V_19;
}
F_36 ( V_2 , V_32 , L_12 ) ;
V_3 = - V_33 ;
V_19:
F_9 ( & V_2 -> V_45 , V_5 ) ;
return V_3 ;
}
static int F_42 ( struct V_39 * V_40 , int V_41 , int V_42 ,
T_2 V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 -> V_43 ;
unsigned long V_5 ;
unsigned int V_44 ;
int V_29 , V_3 ;
F_8 ( & V_2 -> V_45 , V_5 ) ;
if ( F_38 ( F_37 ( V_2 , V_46 ) & V_47 ) ) {
F_36 ( V_2 , V_32 , L_13 ) ;
V_3 = - V_33 ;
goto V_19;
}
F_40 ( V_2 , V_48 , V_13 ) ;
V_44 = ( ( V_41 & 0x1F ) << 11 ) | ( ( V_42 & 0x1F ) << 6 ) |
V_49 ;
F_40 ( V_2 , V_46 , V_44 ) ;
for ( V_29 = 0 ; V_29 < 100 ; V_29 ++ )
if ( ! ( F_37 ( V_2 , V_46 ) & V_47 ) ) {
V_3 = 0 ;
goto V_19;
}
F_36 ( V_2 , V_32 , L_14 ) ;
V_3 = - V_33 ;
V_19:
F_9 ( & V_2 -> V_45 , V_5 ) ;
return V_3 ;
}
static void F_43 ( struct V_1 * V_2 )
{
unsigned int V_50 = F_7 ( V_2 , V_51 ) ;
V_50 &= ( ~ V_52 ) ;
V_50 |= V_53 ;
F_14 ( V_2 , V_51 , V_50 ) ;
F_44 ( 10 ) ;
V_50 |= V_54 ;
F_14 ( V_2 , V_51 , V_50 ) ;
V_50 &= ( ~ V_52 ) ;
V_50 |= V_55 ;
F_14 ( V_2 , V_51 , V_50 ) ;
F_44 ( 10 ) ;
V_50 |= V_56 ;
F_14 ( V_2 , V_51 , V_50 ) ;
}
static void F_45 ( struct V_1 * V_2 )
{
unsigned int V_50 = F_7 ( V_2 , V_51 ) ;
if ( V_2 -> V_4 . V_5 & V_57 ) {
F_46 ( V_2 , V_32 , L_15 ) ;
V_2 -> V_58 = 0 ;
} else if ( V_2 -> V_4 . V_5 & V_59 ) {
F_46 ( V_2 , V_32 , L_16 ) ;
F_43 ( V_2 ) ;
V_2 -> V_58 = 1 ;
} else if ( V_50 & V_60 ) {
F_46 ( V_2 , V_32 ,
L_17 ) ;
F_43 ( V_2 ) ;
V_2 -> V_58 = 1 ;
} else {
F_46 ( V_2 , V_32 ,
L_18 ) ;
V_2 -> V_58 = 0 ;
}
}
static unsigned int F_47 ( struct V_1 * V_2 )
{
unsigned int V_61 =
F_7 ( V_2 , V_62 ) & V_63 ;
if ( V_61 != 0 )
V_61 = F_7 ( V_2 , V_64 ) ;
return V_61 ;
}
static unsigned int F_48 ( struct V_1 * V_2 )
{
unsigned int V_61 =
F_7 ( V_2 , V_65 ) & V_66 ;
if ( V_61 != 0 )
V_61 = F_7 ( V_2 , V_67 ) ;
return V_61 ;
}
static int F_49 ( struct V_1 * V_2 )
{
unsigned int V_68 ;
T_1 V_69 ;
T_1 V_70 ;
T_3 V_71 ;
for ( V_68 = 0 ; V_68 < 10 ; V_68 ++ ) {
unsigned int V_72 ;
unsigned int V_73 ;
unsigned int V_74 ;
unsigned int V_75 ;
unsigned int V_29 ;
memset ( V_2 -> V_76 , 0 , V_77 ) ;
V_72 = ( T_1 ) ( ( T_3 ) V_2 -> V_78 & 0x03 ) << 16 ;
V_72 |= V_79 | V_80 ;
V_72 |= V_77 ;
V_73 = V_77 << 16 | V_77 ;
F_14 ( V_2 , V_18 , V_72 ) ;
F_14 ( V_2 , V_18 , V_73 ) ;
V_71 = ( T_3 ) V_2 -> V_78 & ( ~ 0x3 ) ;
V_69 = V_77 + 3 ;
V_69 += ( T_1 ) ( ( T_3 ) V_2 -> V_78 & 0x3 ) ;
V_69 >>= 2 ;
V_2 -> V_11 -> V_81 ( V_2 , ( unsigned int * ) V_71 , V_69 ) ;
V_29 = 60 ;
do {
F_44 ( 5 ) ;
V_74 = F_47 ( V_2 ) ;
} while ( ( V_29 -- ) && ( ! V_74 ) );
if ( ! V_74 ) {
F_36 ( V_2 , V_32 ,
L_19 ) ;
continue;
}
if ( V_74 & V_82 ) {
F_36 ( V_2 , V_32 ,
L_20 ) ;
continue;
}
V_29 = 60 ;
do {
F_44 ( 5 ) ;
V_74 = F_48 ( V_2 ) ;
} while ( ( V_29 -- ) && ( ! V_74 ) );
if ( ! V_74 ) {
F_36 ( V_2 , V_32 ,
L_21 ) ;
continue;
}
if ( V_74 & V_83 ) {
F_36 ( V_2 , V_32 ,
L_22 ) ;
continue;
}
V_75 = ( ( V_74 & 0x3FFF0000UL ) >> 16 ) ;
V_71 = ( T_3 ) V_2 -> V_76 ;
V_70 = V_75 + 3 ;
V_70 += ( T_1 ) ( ( T_3 ) V_2 -> V_76 & 0x3 ) ;
V_70 >>= 2 ;
V_2 -> V_11 -> V_84 ( V_2 , ( unsigned int * ) V_71 , V_70 ) ;
if ( V_75 != ( V_77 + 4 ) ) {
F_36 ( V_2 , V_32 , L_23
L_24 ,
V_75 ) ;
} else {
unsigned int V_85 ;
int V_86 = 0 ;
for ( V_85 = 0 ; V_85 < V_77 ; V_85 ++ ) {
if ( V_2 -> V_78 [ V_85 ]
!= V_2 -> V_76 [ V_85 ] ) {
V_86 = 1 ;
break;
}
}
if ( ! V_86 ) {
F_46 ( V_2 , V_32 , L_25
L_26 ) ;
return 0 ;
} else {
F_36 ( V_2 , V_32 , L_27
L_28 ) ;
}
}
}
return - V_33 ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_87 * V_88 = V_2 -> V_88 ;
unsigned int V_35 ;
unsigned int V_29 = 100000 ;
F_51 ( ! V_88 ) ;
F_51 ( ! V_88 -> V_40 ) ;
F_46 ( V_2 , V_32 , L_29 ) ;
F_42 ( V_88 -> V_40 , V_88 -> V_44 , V_89 , V_90 ) ;
do {
F_52 ( 1 ) ;
V_35 = F_41 ( V_88 -> V_40 , V_88 -> V_44 ,
V_89 ) ;
} while ( ( V_29 -- ) && ( V_35 & V_90 ) );
if ( V_35 & V_90 ) {
F_36 ( V_2 , V_32 , L_30 ) ;
return - V_33 ;
}
F_52 ( 1 ) ;
return 0 ;
}
static int F_53 ( struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
struct V_87 * V_88 = V_2 -> V_88 ;
int V_61 = - V_33 ;
unsigned int V_29 , V_13 ;
unsigned long V_5 ;
memset ( V_2 -> V_78 , 0xff , V_91 ) ;
for ( V_29 = 6 ; V_29 < 12 ; V_29 ++ )
V_2 -> V_78 [ V_29 ] = ( char ) V_29 ;
V_2 -> V_78 [ 12 ] = 0x00 ;
V_2 -> V_78 [ 13 ] = 0x00 ;
for ( V_29 = 14 ; V_29 < V_77 ; V_29 ++ )
V_2 -> V_78 [ V_29 ] = ( char ) V_29 ;
V_13 = F_7 ( V_2 , V_51 ) ;
V_13 &= V_92 ;
V_13 |= V_93 ;
F_14 ( V_2 , V_51 , V_13 ) ;
F_14 ( V_2 , V_94 , V_95 ) ;
F_14 ( V_2 , V_96 ,
( T_1 ) ( ( T_3 ) V_2 -> V_76 & 0x03 ) << 8 ) ;
for ( V_29 = 0 ; V_29 < 10 ; V_29 ++ ) {
F_42 ( V_88 -> V_40 , V_88 -> V_44 , V_89 ,
V_97 | V_98 ) ;
F_8 ( & V_2 -> V_45 , V_5 ) ;
F_40 ( V_2 , V_99 , V_100
| V_101 | V_102 ) ;
F_9 ( & V_2 -> V_45 , V_5 ) ;
if ( F_49 ( V_2 ) == 0 ) {
V_61 = 0 ;
break;
}
V_2 -> V_103 ++ ;
F_8 ( & V_2 -> V_45 , V_5 ) ;
F_40 ( V_2 , V_99 , 0 ) ;
F_9 ( & V_2 -> V_45 , V_5 ) ;
F_50 ( V_2 ) ;
}
F_8 ( & V_2 -> V_45 , V_5 ) ;
F_40 ( V_2 , V_99 , 0 ) ;
F_9 ( & V_2 -> V_45 , V_5 ) ;
F_42 ( V_88 -> V_40 , V_88 -> V_44 , V_89 , 0 ) ;
F_14 ( V_2 , V_94 , 0 ) ;
F_14 ( V_2 , V_96 , 0 ) ;
return V_61 ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_87 * V_88 = V_2 -> V_88 ;
T_1 V_104 = F_7 ( V_2 , V_105 ) ;
T_1 V_106 ;
unsigned long V_5 ;
if ( V_88 -> V_107 == V_108 ) {
T_2 V_109 = F_55 ( V_88 , V_110 ) ;
T_2 V_111 = F_55 ( V_88 , V_112 ) ;
T_4 V_113 = F_56 ( V_109 , V_111 ) ;
if ( V_113 & V_114 )
V_106 = 0xFFFF0002 ;
else
V_106 = 0 ;
if ( V_113 & V_115 )
V_104 |= 0xF ;
else
V_104 &= ~ 0xF ;
F_46 ( V_2 , V_32 , L_31 ,
( V_113 & V_114 ? L_32 : L_33 ) ,
( V_113 & V_115 ? L_32 : L_33 ) ) ;
} else {
F_46 ( V_2 , V_32 , L_34 ) ;
V_106 = 0 ;
V_104 |= 0xF ;
}
F_8 ( & V_2 -> V_45 , V_5 ) ;
F_40 ( V_2 , V_116 , V_106 ) ;
F_9 ( & V_2 -> V_45 , V_5 ) ;
F_14 ( V_2 , V_105 , V_104 ) ;
}
static void F_57 ( struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
struct V_87 * V_88 = V_2 -> V_88 ;
unsigned long V_5 ;
int V_117 ;
if ( V_88 -> V_107 != V_2 -> V_118 ) {
unsigned int V_119 ;
F_46 ( V_2 , V_32 , L_35 ) ;
F_8 ( & V_2 -> V_45 , V_5 ) ;
V_119 = F_37 ( V_2 , V_99 ) ;
if ( V_88 -> V_107 ) {
F_46 ( V_2 , V_32 ,
L_36 ) ;
V_119 |= V_100 ;
} else {
F_46 ( V_2 , V_32 ,
L_37 ) ;
V_119 &= ~ V_100 ;
}
F_40 ( V_2 , V_99 , V_119 ) ;
F_9 ( & V_2 -> V_45 , V_5 ) ;
F_54 ( V_2 ) ;
V_2 -> V_118 = V_88 -> V_107 ;
}
V_117 = F_58 ( V_28 ) ;
if ( V_117 != V_2 -> V_120 ) {
F_46 ( V_2 , V_32 , L_38 ) ;
if ( V_117 ) {
F_46 ( V_2 , V_32 , L_39 ) ;
if ( ( V_2 -> V_121 & V_122 ) &&
( ! V_2 -> V_58 ) ) {
V_2 -> V_123 = V_2 -> V_121 ;
F_14 ( V_2 , V_124 ,
V_2 -> V_123 ) ;
}
} else {
F_46 ( V_2 , V_32 , L_40 ) ;
V_2 -> V_123 = F_7 ( V_2 ,
V_124 ) ;
if ( ( V_2 -> V_123 & V_122 ) &&
( ! V_2 -> V_58 ) ) {
V_2 -> V_121 = V_2 -> V_123 ;
V_2 -> V_123 &= ~ V_122 ;
V_2 -> V_123 |= ( V_125
| V_126
| V_127 ) ;
F_14 ( V_2 , V_124 ,
V_2 -> V_123 ) ;
}
}
V_2 -> V_120 = V_117 ;
}
}
static int F_59 ( struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
struct V_87 * V_128 = NULL ;
int V_25 ;
V_128 = F_60 ( V_2 -> V_39 ) ;
if ( ! V_128 ) {
F_27 ( V_28 , L_41 ) ;
return - V_129 ;
}
F_46 ( V_2 , V_130 , L_42 ,
V_128 -> V_44 , V_128 -> V_131 ) ;
V_25 = F_61 ( V_28 , V_128 ,
& F_57 , 0 ,
V_2 -> V_4 . V_132 ) ;
if ( V_25 ) {
F_27 ( V_28 , L_43 ) ;
return V_25 ;
}
F_62 ( V_28 ,
L_44 ,
V_128 -> V_133 -> V_134 , F_63 ( & V_128 -> V_28 ) , V_128 -> V_135 ) ;
V_128 -> V_136 &= ( V_137 | V_138 |
V_139 ) ;
V_128 -> V_140 = V_128 -> V_136 ;
V_2 -> V_88 = V_128 ;
V_2 -> V_118 = - 1 ;
V_2 -> V_120 = - 1 ;
#ifdef F_64
if ( F_53 ( V_28 ) < 0 ) {
F_36 ( V_2 , V_32 , L_45 ) ;
return - V_129 ;
}
F_46 ( V_2 , V_32 , L_46 ) ;
#endif
F_46 ( V_2 , V_32 , L_47 ) ;
return 0 ;
}
static int T_5 F_65 ( struct V_21 * V_22 ,
struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
int V_141 = - V_142 , V_29 ;
V_2 -> V_39 = F_66 () ;
if ( ! V_2 -> V_39 ) {
V_141 = - V_143 ;
goto V_144;
}
V_2 -> V_39 -> V_134 = V_145 ;
snprintf ( V_2 -> V_39 -> V_146 , V_147 , L_48 ,
V_22 -> V_134 , V_22 -> V_146 ) ;
V_2 -> V_39 -> V_43 = V_2 ;
V_2 -> V_39 -> V_148 = F_41 ;
V_2 -> V_39 -> V_149 = F_42 ;
V_2 -> V_39 -> V_135 = V_2 -> V_150 ;
for ( V_29 = 0 ; V_29 < V_151 ; ++ V_29 )
V_2 -> V_39 -> V_135 [ V_29 ] = V_152 ;
V_2 -> V_39 -> V_153 = & V_22 -> V_28 ;
switch ( V_2 -> V_154 & 0xFFFF0000 ) {
case 0x01170000 :
case 0x01150000 :
case 0x117A0000 :
case 0x115A0000 :
F_45 ( V_2 ) ;
break;
default:
F_46 ( V_2 , V_32 , L_49
L_50 ) ;
V_2 -> V_58 = 0 ;
break;
}
if ( ! V_2 -> V_58 ) {
V_2 -> V_39 -> V_155 = ~ ( 1 << 1 ) ;
}
if ( F_67 ( V_2 -> V_39 ) ) {
F_36 ( V_2 , V_130 , L_51 ) ;
goto V_156;
}
if ( F_59 ( V_28 ) < 0 ) {
F_36 ( V_2 , V_130 , L_51 ) ;
goto V_157;
}
return 0 ;
V_157:
F_68 ( V_2 -> V_39 ) ;
V_156:
F_69 ( V_2 -> V_39 ) ;
V_144:
return V_141 ;
}
static unsigned int F_70 ( struct V_1 * V_2 )
{
return ( F_7 ( V_2 , V_62 )
& V_63 ) >> 16 ;
}
static void F_71 ( struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
unsigned int V_158 ;
while ( ( V_158 = F_47 ( V_2 ) ) != 0 ) {
if ( F_38 ( V_158 & 0x80000000 ) ) {
F_36 ( V_2 , V_32 , L_52 ) ;
} else {
if ( F_38 ( V_158 & V_82 ) ) {
V_28 -> V_159 . V_160 ++ ;
} else {
V_28 -> V_159 . V_161 ++ ;
V_28 -> V_159 . V_162 += ( V_158 >> 16 ) ;
}
if ( F_38 ( V_158 & V_163 ) ) {
V_28 -> V_159 . V_164 += 16 ;
V_28 -> V_159 . V_165 += 1 ;
} else {
V_28 -> V_159 . V_164 +=
( ( V_158 >> 3 ) & 0xF ) ;
}
if ( F_38 ( V_158 & V_166 ) )
V_28 -> V_159 . V_167 += 1 ;
if ( F_38 ( V_158 & V_168 ) ) {
V_28 -> V_159 . V_164 ++ ;
V_28 -> V_159 . V_165 ++ ;
}
}
}
}
static void
F_72 ( struct V_23 * V_28 , unsigned int V_169 )
{
int V_170 = 0 ;
if ( F_38 ( V_169 & V_83 ) ) {
V_28 -> V_159 . V_171 ++ ;
if ( F_38 ( V_169 & V_172 ) ) {
V_28 -> V_159 . V_173 ++ ;
V_170 = 1 ;
}
}
if ( F_39 ( ! V_170 ) ) {
if ( F_38 ( ( V_169 & V_174 ) &&
( V_169 & V_175 ) ) )
V_28 -> V_159 . V_176 ++ ;
if ( V_169 & V_177 )
V_28 -> V_159 . V_178 ++ ;
}
}
static void
F_73 ( struct V_1 * V_2 , unsigned int V_179 )
{
if ( F_39 ( V_179 >= 4 ) ) {
unsigned int V_180 = 500 ;
unsigned int V_13 ;
F_14 ( V_2 , V_181 , V_182 ) ;
do {
F_44 ( 1 ) ;
V_13 = F_7 ( V_2 , V_181 ) ;
} while ( ( V_13 & V_182 ) && -- V_180 );
if ( F_38 ( V_180 == 0 ) )
F_36 ( V_2 , V_32 , L_53
L_54 , V_13 ) ;
} else {
unsigned int V_35 ;
while ( V_179 -- )
V_35 = F_7 ( V_2 , V_20 ) ;
}
}
static int F_74 ( struct V_183 * V_184 , int V_185 )
{
struct V_1 * V_2 =
F_75 ( V_184 , struct V_1 , V_184 ) ;
struct V_23 * V_28 = V_2 -> V_28 ;
int V_186 = 0 ;
while ( V_186 < V_185 ) {
unsigned int V_75 ;
unsigned int V_179 ;
struct V_187 * V_188 ;
unsigned int V_169 = F_48 ( V_2 ) ;
if ( ! V_169 ) {
unsigned int V_35 ;
F_14 ( V_2 , V_189 , V_190 ) ;
F_76 ( V_184 ) ;
V_35 = F_7 ( V_2 , V_191 ) ;
V_35 |= V_192 ;
F_14 ( V_2 , V_191 , V_35 ) ;
break;
}
V_186 ++ ;
V_75 = ( ( V_169 & 0x3FFF0000 ) >> 16 ) ;
V_179 = ( V_75 + V_193 + 3 ) >> 2 ;
F_72 ( V_28 , V_169 ) ;
if ( F_38 ( V_169 & V_83 ) ) {
F_36 ( V_2 , V_194 ,
L_55 ) ;
F_73 ( V_2 , V_179 ) ;
V_28 -> V_159 . V_195 ++ ;
continue;
}
V_188 = F_77 ( V_28 , V_179 << 2 ) ;
if ( F_38 ( ! V_188 ) ) {
F_36 ( V_2 , V_194 ,
L_56 ) ;
F_73 ( V_2 , V_179 ) ;
V_28 -> V_159 . V_195 ++ ;
break;
}
V_2 -> V_11 -> V_84 ( V_2 ,
( unsigned int * ) V_188 -> V_9 , V_179 ) ;
F_78 ( V_188 , V_193 ) ;
F_79 ( V_188 , V_75 - 4 ) ;
V_188 -> V_196 = F_80 ( V_188 , V_28 ) ;
F_81 ( V_188 ) ;
F_82 ( V_188 ) ;
V_28 -> V_159 . V_197 ++ ;
V_28 -> V_159 . V_198 += ( V_75 - 4 ) ;
}
return V_186 ;
}
static unsigned int F_83 ( char V_44 [ V_91 ] )
{
return ( F_84 ( V_91 , V_44 ) >> 26 ) & 0x3f ;
}
static void F_85 ( struct V_1 * V_2 )
{
unsigned int V_119 ;
F_35 ( V_2 ) ;
V_119 = F_37 ( V_2 , V_99 ) ;
V_119 |= V_2 -> V_199 ;
V_119 &= ~ ( V_2 -> V_200 ) ;
F_40 ( V_2 , V_99 , V_119 ) ;
F_40 ( V_2 , V_201 , V_2 -> V_202 ) ;
F_40 ( V_2 , V_203 , V_2 -> V_204 ) ;
F_46 ( V_2 , V_32 , L_57 ,
V_119 , V_2 -> V_202 , V_2 -> V_204 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
unsigned int V_119 ;
F_87 ( & V_2 -> V_45 ) ;
if ( F_37 ( V_2 , V_99 ) & V_102 )
F_36 ( V_2 , V_133 , L_58 ) ;
F_85 ( V_2 ) ;
V_119 = F_37 ( V_2 , V_99 ) ;
V_119 |= V_102 ;
F_40 ( V_2 , V_99 , V_119 ) ;
V_2 -> V_205 = 0 ;
F_88 ( & V_2 -> V_45 ) ;
}
static int F_89 ( struct V_1 * V_2 )
{
int V_206 = 0 ;
if ( ! V_2 -> V_88 )
return V_206 ;
V_206 = F_55 ( V_2 -> V_88 , V_207 ) ;
if ( V_206 < 0 ) {
F_36 ( V_2 , V_133 , L_59 ) ;
return V_206 ;
}
if ( ( V_206 & V_208 ) &&
! ( V_206 & V_209 ) ) {
V_206 = F_90 ( V_2 -> V_88 , V_207 ,
V_206 & ( ~ V_208 ) ) ;
if ( V_206 < 0 ) {
F_36 ( V_2 , V_133 , L_60 ) ;
return V_206 ;
}
F_91 ( 1 ) ;
}
return 0 ;
}
static int F_92 ( struct V_1 * V_2 )
{
int V_206 = 0 ;
if ( ! V_2 -> V_88 )
return V_206 ;
V_206 = F_55 ( V_2 -> V_88 , V_207 ) ;
if ( V_206 < 0 ) {
F_36 ( V_2 , V_133 , L_59 ) ;
return V_206 ;
}
if ( ! ( V_206 & V_208 ) ) {
F_91 ( 100 ) ;
V_206 = F_90 ( V_2 -> V_88 , V_207 ,
V_206 | V_208 ) ;
if ( V_206 < 0 ) {
F_36 ( V_2 , V_133 , L_60 ) ;
return V_206 ;
}
F_91 ( 1 ) ;
}
return 0 ;
}
static int F_93 ( struct V_1 * V_2 )
{
unsigned int V_180 ;
unsigned int V_35 ;
int V_25 ;
if ( V_2 -> V_210 == 4 ) {
V_25 = F_89 ( V_2 ) ;
if ( V_25 ) {
F_36 ( V_2 , V_133 , L_61 ) ;
return V_25 ;
}
}
F_14 ( V_2 , V_51 , V_211 ) ;
V_180 = 10 ;
do {
F_44 ( 10 ) ;
V_35 = F_7 ( V_2 , V_51 ) ;
} while ( ( -- V_180 ) && ( V_35 & V_211 ) );
if ( F_38 ( V_35 & V_211 ) ) {
F_36 ( V_2 , V_133 , L_62 ) ;
return - V_33 ;
}
if ( V_2 -> V_210 == 4 ) {
V_25 = F_92 ( V_2 ) ;
if ( V_25 ) {
F_36 ( V_2 , V_133 , L_61 ) ;
return V_25 ;
}
}
return 0 ;
}
static void
F_94 ( struct V_1 * V_2 , T_4 V_212 [ 6 ] )
{
T_1 V_213 = ( V_212 [ 5 ] << 8 ) | V_212 [ 4 ] ;
T_1 V_214 = ( V_212 [ 3 ] << 24 ) | ( V_212 [ 2 ] << 16 ) |
( V_212 [ 1 ] << 8 ) | V_212 [ 0 ] ;
F_35 ( V_2 ) ;
F_40 ( V_2 , V_215 , V_213 ) ;
F_40 ( V_2 , V_216 , V_214 ) ;
}
static void F_95 ( struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
F_14 ( V_2 , V_191 , 0 ) ;
F_14 ( V_2 , V_189 , 0xFFFFFFFF ) ;
}
static int F_96 ( struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
unsigned int V_180 ;
unsigned int V_35 ;
unsigned int V_217 ;
if ( ! V_2 -> V_88 ) {
F_36 ( V_2 , V_32 , L_63 ) ;
return - V_218 ;
}
if ( ! F_97 ( V_28 -> V_212 ) ) {
F_36 ( V_2 , V_32 , L_64 ) ;
return - V_219 ;
}
if ( F_93 ( V_2 ) ) {
F_36 ( V_2 , V_32 , L_65 ) ;
return - V_33 ;
}
F_14 ( V_2 , V_51 , 0x00050000 ) ;
F_14 ( V_2 , V_105 , 0x006E3740 ) ;
F_98 ( & V_2 -> V_45 ) ;
F_40 ( V_2 , V_220 , V_221 ) ;
F_99 ( & V_2 -> V_45 ) ;
V_180 = 50 ;
while ( ( F_7 ( V_2 , V_222 ) & V_223 ) &&
-- V_180 ) {
F_44 ( 10 ) ;
}
if ( F_38 ( V_180 == 0 ) )
F_36 ( V_2 , V_224 ,
L_66 ) ;
F_14 ( V_2 , V_124 , 0x70070000 ) ;
F_98 ( & V_2 -> V_45 ) ;
F_94 ( V_2 , V_28 -> V_212 ) ;
F_99 ( & V_2 -> V_45 ) ;
F_95 ( V_28 ) ;
V_217 = ( ( 10 << 24 ) | V_225 ) ;
if ( V_2 -> V_4 . V_226 ) {
F_46 ( V_2 , V_224 , L_67 ) ;
V_217 |= V_227 ;
} else {
F_46 ( V_2 , V_224 , L_68 ) ;
}
if ( V_2 -> V_4 . V_228 ) {
F_46 ( V_2 , V_224 , L_69 ) ;
V_217 |= V_229 ;
} else {
F_46 ( V_2 , V_224 , L_70 ) ;
}
F_14 ( V_2 , V_230 , V_217 ) ;
F_46 ( V_2 , V_224 , L_71 , V_28 -> V_135 ) ;
V_2 -> V_231 = 0 ;
F_100 () ;
V_35 = F_7 ( V_2 , V_191 ) ;
V_35 |= V_232 ;
F_14 ( V_2 , V_191 , V_35 ) ;
V_180 = 1000 ;
while ( V_180 -- ) {
if ( V_2 -> V_231 )
break;
F_52 ( 1 ) ;
}
if ( ! V_2 -> V_231 ) {
F_101 ( V_28 , L_72 ,
V_28 -> V_135 ) ;
return - V_129 ;
}
F_46 ( V_2 , V_224 , L_73 ,
V_28 -> V_135 ) ;
F_62 ( V_28 , L_74 ,
( unsigned long ) V_2 -> V_7 , V_28 -> V_135 ) ;
V_2 -> V_118 = - 1 ;
V_2 -> V_120 = - 1 ;
F_102 ( V_2 -> V_88 ) ;
V_35 = F_7 ( V_2 , V_51 ) ;
V_35 &= ( V_92 | 0x00000FFF ) ;
V_35 |= V_93 ;
F_14 ( V_2 , V_51 , V_35 ) ;
V_35 = F_7 ( V_2 , V_233 ) ;
V_35 |= V_234 ;
V_35 &= ~ ( V_235 ) ;
F_14 ( V_2 , V_233 , V_35 ) ;
F_14 ( V_2 , V_96 , ( V_193 << 8 ) ) ;
F_103 ( & V_2 -> V_184 ) ;
V_35 = F_7 ( V_2 , V_191 ) ;
V_35 |= ( V_236 | V_192 | V_237 ) ;
F_14 ( V_2 , V_191 , V_35 ) ;
F_98 ( & V_2 -> V_45 ) ;
V_35 = F_37 ( V_2 , V_99 ) ;
V_35 |= ( V_101 | V_102 | V_238 ) ;
F_40 ( V_2 , V_99 , V_35 ) ;
F_99 ( & V_2 -> V_45 ) ;
F_14 ( V_2 , V_94 , V_95 ) ;
F_104 ( V_28 ) ;
return 0 ;
}
static int F_105 ( struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
unsigned int V_35 ;
V_35 = F_7 ( V_2 , V_230 ) ;
V_35 &= ~ V_225 ;
F_14 ( V_2 , V_230 , V_35 ) ;
F_106 ( V_28 ) ;
F_107 ( & V_2 -> V_184 ) ;
V_28 -> V_159 . V_195 += F_7 ( V_2 , V_239 ) ;
F_71 ( V_28 ) ;
if ( V_2 -> V_88 )
F_108 ( V_2 -> V_88 ) ;
F_46 ( V_2 , V_240 , L_75 ) ;
return 0 ;
}
static int F_109 ( struct V_187 * V_188 , struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
unsigned int V_241 ;
unsigned int V_242 ;
unsigned int V_243 ;
unsigned int V_35 ;
T_1 V_69 ;
T_3 V_71 ;
V_241 = F_7 ( V_2 , V_62 ) & V_244 ;
if ( F_38 ( V_241 < V_245 ) )
F_36 ( V_2 , V_246 ,
L_76 , V_241 ) ;
V_242 = ( T_1 ) ( ( T_3 ) V_188 -> V_9 & 0x03 ) << 16 ;
V_242 |= V_79 | V_80 ;
V_242 |= ( unsigned int ) V_188 -> V_247 ;
V_243 = ( ( unsigned int ) V_188 -> V_247 ) << 16 ;
V_243 |= ( unsigned int ) V_188 -> V_247 ;
F_14 ( V_2 , V_18 , V_242 ) ;
F_14 ( V_2 , V_18 , V_243 ) ;
V_71 = ( T_3 ) V_188 -> V_9 & ( ~ 0x3 ) ;
V_69 = ( T_1 ) V_188 -> V_247 + 3 ;
V_69 += ( T_1 ) ( ( T_3 ) V_188 -> V_9 & 0x3 ) ;
V_69 >>= 2 ;
V_2 -> V_11 -> V_81 ( V_2 , ( unsigned int * ) V_71 , V_69 ) ;
V_241 -= ( V_188 -> V_247 + 32 ) ;
F_110 ( V_188 ) ;
F_111 ( V_188 ) ;
if ( F_38 ( F_70 ( V_2 ) >= 30 ) )
F_71 ( V_28 ) ;
if ( V_241 < V_245 ) {
F_106 ( V_28 ) ;
V_35 = F_7 ( V_2 , V_233 ) ;
V_35 &= 0x00FFFFFF ;
V_35 |= 0x32000000 ;
F_14 ( V_2 , V_233 , V_35 ) ;
}
return V_248 ;
}
static struct V_249 * F_112 ( struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
F_71 ( V_28 ) ;
V_28 -> V_159 . V_195 += F_7 ( V_2 , V_239 ) ;
return & V_28 -> V_159 ;
}
static void F_113 ( struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
unsigned long V_5 ;
if ( V_28 -> V_5 & V_250 ) {
V_2 -> V_199 = V_251 ;
V_2 -> V_200 = ( V_252 | V_253 ) ;
V_2 -> V_202 = 0 ;
V_2 -> V_204 = 0 ;
} else if ( V_28 -> V_5 & V_254 ) {
V_2 -> V_199 = V_252 ;
V_2 -> V_200 = ( V_251 | V_253 ) ;
V_2 -> V_202 = 0 ;
V_2 -> V_204 = 0 ;
} else if ( ! F_114 ( V_28 ) ) {
unsigned int V_255 = 0 ;
unsigned int V_256 = 0 ;
struct V_257 * V_258 ;
V_2 -> V_199 = V_253 ;
V_2 -> V_200 = ( V_251 | V_252 ) ;
F_115 (ha, dev) {
unsigned int V_259 = F_83 ( V_258 -> V_44 ) ;
unsigned int V_260 = 0x01 << ( V_259 & 0x1F ) ;
if ( V_259 & 0x20 )
V_255 |= V_260 ;
else
V_256 |= V_260 ;
}
V_2 -> V_202 = V_255 ;
V_2 -> V_204 = V_256 ;
} else {
V_2 -> V_199 = 0 ;
V_2 -> V_200 =
( V_251 | V_252 | V_253 ) ;
V_2 -> V_202 = 0 ;
V_2 -> V_204 = 0 ;
}
F_8 ( & V_2 -> V_45 , V_5 ) ;
if ( V_2 -> V_210 <= 1 ) {
if ( ! V_2 -> V_205 ) {
unsigned int V_35 ;
F_46 ( V_2 , V_32 , L_77 ) ;
V_2 -> V_205 = 1 ;
V_35 = F_37 ( V_2 , V_99 ) ;
V_35 &= ~ ( V_102 ) ;
F_40 ( V_2 , V_99 , V_35 ) ;
} else {
}
} else {
F_85 ( V_2 ) ;
}
F_9 ( & V_2 -> V_45 , V_5 ) ;
}
static T_6 F_116 ( int V_135 , void * V_261 )
{
struct V_23 * V_28 = V_261 ;
struct V_1 * V_2 = F_24 ( V_28 ) ;
T_1 V_262 = F_7 ( V_2 , V_189 ) ;
T_1 V_263 = F_7 ( V_2 , V_191 ) ;
int V_264 = V_265 ;
T_1 V_35 ;
if ( F_38 ( V_262 & V_263 & V_266 ) ) {
V_35 = F_7 ( V_2 , V_191 ) ;
V_35 &= ( ~ V_232 ) ;
F_14 ( V_2 , V_191 , V_35 ) ;
F_14 ( V_2 , V_189 , V_266 ) ;
V_2 -> V_231 = 1 ;
F_100 () ;
V_264 = V_267 ;
}
if ( F_38 ( V_262 & V_263 & V_268 ) ) {
F_46 ( V_2 , V_269 , L_78 ) ;
F_14 ( V_2 , V_189 , V_268 ) ;
if ( V_2 -> V_205 )
F_86 ( V_2 ) ;
V_264 = V_267 ;
}
if ( V_262 & V_263 & V_270 ) {
V_35 = F_7 ( V_2 , V_233 ) ;
V_35 |= V_234 ;
F_14 ( V_2 , V_233 , V_35 ) ;
F_14 ( V_2 , V_189 , V_270 ) ;
F_117 ( V_28 ) ;
V_264 = V_267 ;
}
if ( F_38 ( V_262 & V_263 & V_271 ) ) {
F_46 ( V_2 , V_269 , L_79 ) ;
F_14 ( V_2 , V_189 , V_271 ) ;
V_264 = V_267 ;
}
if ( F_39 ( V_262 & V_263 & V_190 ) ) {
if ( F_39 ( F_118 ( & V_2 -> V_184 ) ) ) {
V_35 = F_7 ( V_2 , V_191 ) ;
V_35 &= ( ~ V_192 ) ;
F_14 ( V_2 , V_191 , V_35 ) ;
F_119 ( & V_2 -> V_184 ) ;
} else {
F_36 ( V_2 , V_194 , L_80 ) ;
}
V_264 = V_267 ;
}
return V_264 ;
}
static void F_120 ( struct V_23 * V_28 )
{
F_121 ( V_28 -> V_135 ) ;
F_116 ( 0 , V_28 ) ;
F_122 ( V_28 -> V_135 ) ;
}
static int F_123 ( struct V_23 * V_28 , void * V_272 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
struct V_273 * V_44 = V_272 ;
if ( V_2 -> V_210 <= 1 && F_124 ( V_28 ) )
return - V_274 ;
if ( ! F_97 ( V_44 -> V_275 ) )
return - V_219 ;
V_28 -> V_276 &= ~ V_277 ;
memcpy ( V_28 -> V_212 , V_44 -> V_275 , V_91 ) ;
F_98 ( & V_2 -> V_45 ) ;
F_94 ( V_2 , V_28 -> V_212 ) ;
F_99 ( & V_2 -> V_45 ) ;
F_62 ( V_28 , L_81 , V_28 -> V_212 ) ;
return 0 ;
}
static int F_125 ( struct V_23 * V_28 , struct V_278 * V_279 , int V_280 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
if ( ! F_124 ( V_28 ) || ! V_2 -> V_88 )
return - V_281 ;
return F_126 ( V_2 -> V_88 , V_279 , V_280 ) ;
}
static int
F_127 ( struct V_23 * V_28 , struct V_282 * V_280 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
V_280 -> V_283 = 1 ;
V_280 -> V_284 = 1 ;
return F_128 ( V_2 -> V_88 , V_280 ) ;
}
static int
F_129 ( struct V_23 * V_28 , struct V_282 * V_280 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
return F_130 ( V_2 -> V_88 , V_280 ) ;
}
static void F_131 ( struct V_23 * V_28 ,
struct V_285 * V_286 )
{
F_132 ( V_286 -> V_287 , V_288 , sizeof( V_286 -> V_287 ) ) ;
F_132 ( V_286 -> V_289 , V_290 , sizeof( V_286 -> V_289 ) ) ;
F_132 ( V_286 -> V_291 , F_63 ( V_28 -> V_28 . V_153 ) ,
sizeof( V_286 -> V_291 ) ) ;
}
static int F_133 ( struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
return F_134 ( V_2 -> V_88 ) ;
}
static T_1 F_135 ( struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
return V_2 -> V_292 ;
}
static void F_136 ( struct V_23 * V_28 , T_1 V_293 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
V_2 -> V_292 = V_293 ;
}
static int F_137 ( struct V_23 * V_28 )
{
return ( ( ( V_294 - V_295 ) / 4 + 1 ) + ( V_296 - V_99 ) + 1 + 32 ) *
sizeof( T_1 ) ;
}
static void
F_138 ( struct V_23 * V_28 , struct V_297 * V_298 ,
void * V_15 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
struct V_87 * V_88 = V_2 -> V_88 ;
unsigned long V_5 ;
unsigned int V_29 ;
unsigned int V_85 = 0 ;
T_1 * V_9 = V_15 ;
V_298 -> V_289 = V_2 -> V_154 ;
for ( V_29 = V_295 ; V_29 <= V_294 ; V_29 += ( sizeof( T_1 ) ) )
V_9 [ V_85 ++ ] = F_7 ( V_2 , V_29 ) ;
for ( V_29 = V_99 ; V_29 <= V_296 ; V_29 ++ ) {
F_8 ( & V_2 -> V_45 , V_5 ) ;
V_9 [ V_85 ++ ] = F_37 ( V_2 , V_29 ) ;
F_9 ( & V_2 -> V_45 , V_5 ) ;
}
for ( V_29 = 0 ; V_29 <= 31 ; V_29 ++ )
V_9 [ V_85 ++ ] = F_41 ( V_88 -> V_40 , V_88 -> V_44 , V_29 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
unsigned int V_35 = F_7 ( V_2 , V_124 ) ;
V_35 &= ~ V_299 ;
F_14 ( V_2 , V_124 , V_35 ) ;
F_52 ( 1 ) ;
}
static int F_140 ( struct V_1 * V_2 , T_1 V_300 )
{
int V_180 = 100 ;
T_1 V_301 ;
F_46 ( V_2 , V_133 , L_82 , V_300 ) ;
if ( F_7 ( V_2 , V_222 ) & V_223 ) {
F_36 ( V_2 , V_133 , L_83 ) ;
return - V_274 ;
}
V_301 = V_300 | V_223 ;
F_14 ( V_2 , V_222 , V_301 ) ;
do {
F_52 ( 1 ) ;
V_301 = F_7 ( V_2 , V_222 ) ;
} while ( ( V_301 & V_223 ) && ( -- V_180 ) );
if ( ! V_180 ) {
F_46 ( V_2 , V_133 , L_84 ) ;
return - V_218 ;
}
if ( V_301 & V_302 ) {
F_46 ( V_2 , V_133 , L_85 ) ;
return - V_281 ;
}
return 0 ;
}
static int F_141 ( struct V_1 * V_2 ,
T_4 V_303 , T_4 * V_9 )
{
T_1 V_300 = V_304 | V_303 ;
int V_25 ;
F_46 ( V_2 , V_133 , L_86 , V_303 ) ;
V_25 = F_140 ( V_2 , V_300 ) ;
if ( ! V_25 )
V_9 [ V_303 ] = F_7 ( V_2 , V_294 ) ;
return V_25 ;
}
static int F_142 ( struct V_1 * V_2 ,
T_4 V_303 , T_4 V_9 )
{
T_1 V_300 = V_305 | V_303 ;
T_1 V_35 ;
int V_25 ;
F_46 ( V_2 , V_133 , L_87 , V_303 , V_9 ) ;
V_25 = F_140 ( V_2 , V_300 ) ;
if ( ! V_25 ) {
V_300 = V_306 | V_303 ;
F_14 ( V_2 , V_294 , ( T_1 ) V_9 ) ;
V_35 = F_7 ( V_2 , V_37 ) ;
V_25 = F_140 ( V_2 , V_300 ) ;
}
return V_25 ;
}
static int F_143 ( struct V_23 * V_28 )
{
return V_307 ;
}
static int F_144 ( struct V_23 * V_28 ,
struct V_308 * V_309 , T_4 * V_9 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
T_4 V_310 [ V_307 ] ;
int V_247 ;
int V_29 ;
F_139 ( V_2 ) ;
V_247 = F_145 ( V_309 -> V_247 , V_307 ) ;
for ( V_29 = 0 ; V_29 < V_247 ; V_29 ++ ) {
int V_25 = F_141 ( V_2 , V_29 , V_310 ) ;
if ( V_25 < 0 ) {
V_309 -> V_247 = 0 ;
return V_25 ;
}
}
memcpy ( V_9 , & V_310 [ V_309 -> V_34 ] , V_247 ) ;
V_309 -> V_247 = V_247 ;
return 0 ;
}
static int F_146 ( struct V_23 * V_28 ,
struct V_308 * V_309 , T_4 * V_9 )
{
int V_25 ;
struct V_1 * V_2 = F_24 ( V_28 ) ;
F_139 ( V_2 ) ;
F_140 ( V_2 , V_311 ) ;
V_25 = F_142 ( V_2 , V_309 -> V_34 , * V_9 ) ;
F_140 ( V_2 , V_312 ) ;
V_309 -> V_247 = 1 ;
return V_25 ;
}
static void T_5 F_147 ( struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
T_1 V_213 = F_37 ( V_2 , V_215 ) ;
T_1 V_214 = F_37 ( V_2 , V_216 ) ;
V_28 -> V_212 [ 0 ] = ( T_4 ) ( V_214 ) ;
V_28 -> V_212 [ 1 ] = ( T_4 ) ( V_214 >> 8 ) ;
V_28 -> V_212 [ 2 ] = ( T_4 ) ( V_214 >> 16 ) ;
V_28 -> V_212 [ 3 ] = ( T_4 ) ( V_214 >> 24 ) ;
V_28 -> V_212 [ 4 ] = ( T_4 ) ( V_213 ) ;
V_28 -> V_212 [ 5 ] = ( T_4 ) ( V_213 >> 8 ) ;
}
static int T_5 F_148 ( struct V_23 * V_28 )
{
struct V_1 * V_2 = F_24 ( V_28 ) ;
unsigned int V_313 ;
unsigned int V_314 = 100 ;
F_46 ( V_2 , V_130 , L_88 ) ;
F_46 ( V_2 , V_130 , L_89 ,
( unsigned long ) V_2 -> V_7 ) ;
F_46 ( V_2 , V_130 , L_90 , V_28 -> V_135 ) ;
F_46 ( V_2 , V_130 , L_91 ) ;
F_149 ( & V_2 -> V_10 ) ;
F_149 ( & V_2 -> V_45 ) ;
if ( V_2 -> V_7 == 0 ) {
F_36 ( V_2 , V_130 , L_92 ) ;
return - V_129 ;
}
while ( ! ( F_7 ( V_2 , V_315 ) & V_316 ) && -- V_314 )
F_44 ( 1000 ) ;
if ( V_314 == 0 ) {
F_150 ( L_93 ) ;
return - V_129 ;
}
V_313 = F_7 ( V_2 , V_37 ) ;
F_46 ( V_2 , V_130 , L_94 , V_313 ) ;
if ( V_313 == 0x43218765 ) {
F_46 ( V_2 , V_130 , L_95
L_96 ) ;
F_14 ( V_2 , V_317 , 0xffffffff ) ;
V_313 = F_7 ( V_2 , V_37 ) ;
V_313 = F_7 ( V_2 , V_37 ) ;
}
if ( V_313 != 0x87654321 ) {
F_36 ( V_2 , V_133 , L_94 , V_313 ) ;
if ( ( ( V_313 >> 16 ) & 0xFFFF ) == ( V_313 & 0xFFFF ) ) {
F_36 ( V_2 , V_130 ,
L_97 ) ;
F_46 ( V_2 , V_130 ,
L_98
L_99 ) ;
}
return - V_129 ;
}
V_2 -> V_210 = 0 ;
V_2 -> V_154 = F_7 ( V_2 , V_295 ) ;
switch ( V_2 -> V_154 & 0xFFFF0000 ) {
case 0x01180000 :
case 0x01170000 :
case 0x01160000 :
case 0x01150000 :
case 0x218A0000 :
V_2 -> V_210 = V_2 -> V_154 & 0x0000FFFF ;
break;
case 0x118A0000 :
case 0x117A0000 :
case 0x116A0000 :
case 0x115A0000 :
V_2 -> V_210 = 3 ;
break;
case 0x92100000 :
case 0x92110000 :
case 0x92200000 :
case 0x92210000 :
V_2 -> V_210 = 4 ;
break;
default:
F_36 ( V_2 , V_130 , L_100 ,
V_2 -> V_154 ) ;
return - V_129 ;
}
F_46 ( V_2 , V_130 ,
L_101 ,
V_2 -> V_154 , V_2 -> V_210 ) ;
if ( V_2 -> V_210 == 0 )
F_36 ( V_2 , V_130 ,
L_102 ) ;
if ( V_2 -> V_4 . V_5 & V_318 ) {
F_98 ( & V_2 -> V_45 ) ;
F_147 ( V_28 ) ;
F_99 ( & V_2 -> V_45 ) ;
}
if ( F_93 ( V_2 ) )
return - V_129 ;
F_151 ( V_28 ) ;
V_28 -> V_5 |= V_319 ;
F_152 ( V_28 , & V_2 -> V_184 , F_74 , V_320 ) ;
V_28 -> V_321 = & V_322 ;
V_28 -> V_323 = & V_324 ;
return 0 ;
}
static int T_7 F_153 ( struct V_21 * V_22 )
{
struct V_23 * V_28 ;
struct V_1 * V_2 ;
struct V_325 * V_326 ;
V_28 = F_23 ( V_22 ) ;
F_51 ( ! V_28 ) ;
V_2 = F_24 ( V_28 ) ;
F_51 ( ! V_2 ) ;
F_51 ( ! V_2 -> V_7 ) ;
F_51 ( ! V_2 -> V_88 ) ;
F_46 ( V_2 , V_240 , L_103 ) ;
F_154 ( V_2 -> V_88 ) ;
V_2 -> V_88 = NULL ;
F_68 ( V_2 -> V_39 ) ;
F_69 ( V_2 -> V_39 ) ;
F_155 ( V_22 , NULL ) ;
F_156 ( V_28 ) ;
F_157 ( V_28 -> V_135 , V_28 ) ;
V_326 = F_158 ( V_22 , V_327 ,
L_104 ) ;
if ( ! V_326 )
V_326 = F_159 ( V_22 , V_327 , 0 ) ;
F_160 ( V_326 -> V_328 , F_161 ( V_326 ) ) ;
F_162 ( V_2 -> V_7 ) ;
( void ) F_28 ( V_22 ) ;
F_32 ( V_22 ) ;
F_163 ( V_28 ) ;
return 0 ;
}
static int T_5 F_164 (
struct V_329 * V_4 ,
struct V_330 * V_331 )
{
const char * V_332 ;
T_1 V_333 = 0 ;
if ( ! V_331 )
return - V_129 ;
V_4 -> V_132 = F_165 ( V_331 ) ;
V_332 = F_166 ( V_331 ) ;
if ( V_332 )
memcpy ( V_4 -> V_332 , V_332 , V_91 ) ;
F_167 ( V_331 , L_105 , & V_4 -> V_334 ) ;
F_167 ( V_331 , L_106 , & V_333 ) ;
if ( V_333 == 4 )
V_4 -> V_5 |= V_6 ;
else
V_4 -> V_5 |= V_8 ;
if ( F_168 ( V_331 , L_107 , NULL ) )
V_4 -> V_226 = V_335 ;
if ( F_168 ( V_331 , L_108 , NULL ) )
V_4 -> V_228 = V_336 ;
if ( F_168 ( V_331 , L_109 , NULL ) )
V_4 -> V_5 |= V_57 ;
if ( F_168 ( V_331 , L_110 , NULL ) )
V_4 -> V_5 |= V_59 ;
if ( F_168 ( V_331 , L_111 , NULL ) )
V_4 -> V_5 |= V_318 ;
return 0 ;
}
static inline int F_164 (
struct V_329 * V_4 ,
struct V_330 * V_331 )
{
return - V_129 ;
}
static int T_5 F_169 ( struct V_21 * V_22 )
{
struct V_330 * V_331 = V_22 -> V_28 . V_337 ;
struct V_23 * V_28 ;
struct V_1 * V_2 ;
struct V_329 * V_4 = V_22 -> V_28 . V_338 ;
struct V_325 * V_326 , * V_339 ;
unsigned int V_217 = 0 ;
int V_340 , V_341 ;
int V_342 ;
F_170 ( L_112 , V_290 ) ;
V_326 = F_158 ( V_22 , V_327 ,
L_104 ) ;
if ( ! V_326 )
V_326 = F_159 ( V_22 , V_327 , 0 ) ;
if ( ! V_326 ) {
F_171 ( L_113 ) ;
V_342 = - V_129 ;
goto V_343;
}
V_340 = F_161 ( V_326 ) ;
V_339 = F_159 ( V_22 , V_344 , 0 ) ;
if ( ! V_339 ) {
F_171 ( L_114 ) ;
V_342 = - V_129 ;
goto V_343;
}
if ( ! F_172 ( V_326 -> V_328 , V_340 , V_288 ) ) {
V_342 = - V_274 ;
goto V_343;
}
V_28 = F_173 ( sizeof( struct V_1 ) ) ;
if ( ! V_28 ) {
V_342 = - V_143 ;
goto V_345;
}
F_174 ( V_28 , & V_22 -> V_28 ) ;
V_2 = F_24 ( V_28 ) ;
V_28 -> V_135 = V_339 -> V_328 ;
V_341 = V_339 -> V_5 & V_346 ;
V_2 -> V_7 = F_175 ( V_326 -> V_328 , V_340 ) ;
V_2 -> V_28 = V_28 ;
V_2 -> V_292 = ( ( 1 << V_347 ) - 1 ) ;
F_155 ( V_22 , V_28 ) ;
V_342 = F_30 ( V_22 ) ;
if ( V_342 )
goto V_348;
V_342 = F_22 ( V_22 ) ;
if ( V_342 )
goto V_349;
if ( V_2 -> V_7 == NULL ) {
F_36 ( V_2 , V_130 , L_115 ) ;
V_342 = - V_143 ;
goto V_350;
}
V_342 = F_164 ( & V_2 -> V_4 , V_331 ) ;
if ( V_342 && V_4 ) {
memcpy ( & V_2 -> V_4 , V_4 , sizeof( V_2 -> V_4 ) ) ;
V_342 = 0 ;
}
if ( V_342 ) {
F_36 ( V_2 , V_130 , L_116 ) ;
goto V_350;
}
V_2 -> V_11 = & V_351 ;
if ( V_2 -> V_4 . V_334 )
V_2 -> V_11 = & V_352 ;
V_342 = F_148 ( V_28 ) ;
if ( V_342 < 0 )
goto V_350;
if ( V_2 -> V_4 . V_226 == V_335 )
V_217 |= V_227 ;
if ( V_2 -> V_4 . V_228 == V_336 )
V_217 |= V_229 ;
F_14 ( V_2 , V_230 , V_217 ) ;
F_95 ( V_28 ) ;
V_342 = F_176 ( V_28 -> V_135 , F_116 ,
V_341 | V_353 , V_28 -> V_134 , V_28 ) ;
if ( V_342 ) {
F_36 ( V_2 , V_130 ,
L_117 , V_28 -> V_135 ) ;
goto V_350;
}
V_342 = F_177 ( V_28 ) ;
if ( V_342 ) {
F_36 ( V_2 , V_130 , L_118 , V_342 ) ;
goto V_354;
} else {
F_46 ( V_2 , V_130 ,
L_119 , V_28 -> V_134 ) ;
}
V_342 = F_65 ( V_22 , V_28 ) ;
if ( V_342 ) {
F_36 ( V_2 , V_130 , L_120 , V_342 ) ;
goto V_355;
}
F_98 ( & V_2 -> V_45 ) ;
if ( F_97 ( V_28 -> V_212 ) ) {
F_94 ( V_2 , V_28 -> V_212 ) ;
F_46 ( V_2 , V_130 ,
L_121 ) ;
} else if ( F_97 ( V_2 -> V_4 . V_332 ) ) {
memcpy ( V_28 -> V_212 , V_2 -> V_4 . V_332 , 6 ) ;
F_46 ( V_2 , V_130 ,
L_122 ) ;
} else {
F_178 ( V_28 ) ;
if ( F_97 ( V_28 -> V_212 ) ) {
F_46 ( V_2 , V_130 ,
L_123 ) ;
} else {
F_179 ( V_28 ) ;
F_94 ( V_2 , V_28 -> V_212 ) ;
F_46 ( V_2 , V_130 ,
L_124 ) ;
}
}
F_99 ( & V_2 -> V_45 ) ;
F_62 ( V_28 , L_81 , V_28 -> V_212 ) ;
return 0 ;
V_355:
F_156 ( V_28 ) ;
V_354:
F_157 ( V_28 -> V_135 , V_28 ) ;
V_350:
( void ) F_28 ( V_22 ) ;
V_349:
F_32 ( V_22 ) ;
V_348:
F_155 ( V_22 , NULL ) ;
F_162 ( V_2 -> V_7 ) ;
F_163 ( V_28 ) ;
V_345:
F_160 ( V_326 -> V_328 , F_161 ( V_326 ) ) ;
V_343:
return V_342 ;
}
static int F_180 ( struct V_356 * V_28 )
{
struct V_23 * V_24 = F_181 ( V_28 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
F_14 ( V_2 , V_315 ,
V_357 | V_358 |
V_359 | V_360 ) ;
return 0 ;
}
static int F_182 ( struct V_356 * V_28 )
{
struct V_23 * V_24 = F_181 ( V_28 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
unsigned int V_314 = 100 ;
F_14 ( V_2 , V_37 , 0 ) ;
while ( ! ( F_7 ( V_2 , V_315 ) & V_316 ) && -- V_314 )
F_44 ( 1000 ) ;
return ( V_314 == 0 ) ? - V_33 : 0 ;
}
static int T_8 F_183 ( void )
{
F_184 () ;
return F_185 ( & V_361 ) ;
}
static void T_9 F_186 ( void )
{
F_187 ( & V_361 ) ;
}
