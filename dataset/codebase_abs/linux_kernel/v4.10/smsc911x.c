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
if ( ! F_28 ( V_2 -> V_27 ) ) {
V_25 = F_29 ( V_2 -> V_27 ) ;
if ( V_25 < 0 )
F_27 ( V_24 , L_2 , V_25 ) ;
}
return V_25 ;
}
static int F_30 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_23 ( V_22 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
int V_25 = 0 ;
V_25 = F_31 ( F_26 ( V_2 -> V_26 ) ,
V_2 -> V_26 ) ;
if ( ! F_28 ( V_2 -> V_27 ) )
F_32 ( V_2 -> V_27 ) ;
return V_25 ;
}
static int F_33 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_23 ( V_22 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
int V_25 = 0 ;
V_2 -> V_26 [ 0 ] . V_28 = L_3 ;
V_2 -> V_26 [ 1 ] . V_28 = L_4 ;
V_25 = F_34 ( & V_22 -> V_29 ,
F_26 ( V_2 -> V_26 ) ,
V_2 -> V_26 ) ;
if ( V_25 ) {
if ( V_25 == - V_30 )
return V_25 ;
F_27 ( V_24 , L_5 ,
V_25 ) ;
}
V_2 -> V_31 = F_35 ( & V_22 -> V_29 ,
L_6 ,
V_32 ) ;
V_2 -> V_27 = F_36 ( & V_22 -> V_29 , NULL ) ;
if ( F_28 ( V_2 -> V_27 ) )
F_37 ( & V_22 -> V_29 , L_7 ,
F_38 ( V_2 -> V_27 ) ) ;
return V_25 ;
}
static void F_39 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_23 ( V_22 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
F_40 ( F_26 ( V_2 -> V_26 ) ,
V_2 -> V_26 ) ;
if ( ! F_28 ( V_2 -> V_27 ) ) {
F_41 ( V_2 -> V_27 ) ;
V_2 -> V_27 = NULL ;
}
}
static int F_42 ( struct V_1 * V_2 )
{
int V_33 ;
T_1 V_13 ;
F_43 ( V_2 ) ;
for ( V_33 = 0 ; V_33 < 40 ; V_33 ++ ) {
V_13 = F_7 ( V_2 , V_34 ) ;
if ( ! ( V_13 & V_35 ) )
return 0 ;
}
F_44 ( V_2 , V_36 , L_8
L_9 , V_13 ) ;
return - V_37 ;
}
static T_1 F_45 ( struct V_1 * V_2 , unsigned int V_38 )
{
unsigned int V_39 ;
F_43 ( V_2 ) ;
V_39 = F_7 ( V_2 , V_34 ) ;
if ( F_46 ( V_39 & V_35 ) ) {
F_44 ( V_2 , V_36 , L_10 ) ;
return 0xFFFFFFFF ;
}
F_14 ( V_2 , V_34 , ( ( V_38 & 0xFF ) |
V_35 | V_40 ) ) ;
V_39 = F_7 ( V_2 , V_41 ) ;
if ( F_47 ( F_42 ( V_2 ) == 0 ) )
return F_7 ( V_2 , V_42 ) ;
F_44 ( V_2 , V_36 , L_11 ) ;
return 0xFFFFFFFF ;
}
static void F_48 ( struct V_1 * V_2 ,
unsigned int V_38 , T_1 V_13 )
{
unsigned int V_39 ;
F_43 ( V_2 ) ;
V_39 = F_7 ( V_2 , V_34 ) ;
if ( F_46 ( V_39 & V_35 ) ) {
F_44 ( V_2 , V_36 ,
L_12 ) ;
return;
}
F_14 ( V_2 , V_42 , V_13 ) ;
F_14 ( V_2 , V_34 , ( ( V_38 & 0xFF ) |
V_35 ) ) ;
V_39 = F_7 ( V_2 , V_41 ) ;
if ( F_47 ( F_42 ( V_2 ) == 0 ) )
return;
F_44 ( V_2 , V_36 , L_13 ) ;
}
static int F_49 ( struct V_43 * V_44 , int V_45 , int V_46 )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 -> V_47 ;
unsigned long V_5 ;
unsigned int V_48 ;
int V_33 , V_3 ;
F_8 ( & V_2 -> V_49 , V_5 ) ;
if ( F_46 ( F_45 ( V_2 , V_50 ) & V_51 ) ) {
F_44 ( V_2 , V_36 , L_14 ) ;
V_3 = - V_37 ;
goto V_19;
}
V_48 = ( ( V_45 & 0x1F ) << 11 ) | ( ( V_46 & 0x1F ) << 6 ) ;
F_48 ( V_2 , V_50 , V_48 ) ;
for ( V_33 = 0 ; V_33 < 100 ; V_33 ++ )
if ( ! ( F_45 ( V_2 , V_50 ) & V_51 ) ) {
V_3 = F_45 ( V_2 , V_52 ) ;
goto V_19;
}
F_44 ( V_2 , V_36 , L_15 ) ;
V_3 = - V_37 ;
V_19:
F_9 ( & V_2 -> V_49 , V_5 ) ;
return V_3 ;
}
static int F_50 ( struct V_43 * V_44 , int V_45 , int V_46 ,
T_2 V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_44 -> V_47 ;
unsigned long V_5 ;
unsigned int V_48 ;
int V_33 , V_3 ;
F_8 ( & V_2 -> V_49 , V_5 ) ;
if ( F_46 ( F_45 ( V_2 , V_50 ) & V_51 ) ) {
F_44 ( V_2 , V_36 , L_16 ) ;
V_3 = - V_37 ;
goto V_19;
}
F_48 ( V_2 , V_52 , V_13 ) ;
V_48 = ( ( V_45 & 0x1F ) << 11 ) | ( ( V_46 & 0x1F ) << 6 ) |
V_53 ;
F_48 ( V_2 , V_50 , V_48 ) ;
for ( V_33 = 0 ; V_33 < 100 ; V_33 ++ )
if ( ! ( F_45 ( V_2 , V_50 ) & V_51 ) ) {
V_3 = 0 ;
goto V_19;
}
F_44 ( V_2 , V_36 , L_17 ) ;
V_3 = - V_37 ;
V_19:
F_9 ( & V_2 -> V_49 , V_5 ) ;
return V_3 ;
}
static void F_51 ( struct V_1 * V_2 )
{
unsigned int V_54 = F_7 ( V_2 , V_55 ) ;
V_54 &= ( ~ V_56 ) ;
V_54 |= V_57 ;
F_14 ( V_2 , V_55 , V_54 ) ;
F_52 ( 10 ) ;
V_54 |= V_58 ;
F_14 ( V_2 , V_55 , V_54 ) ;
V_54 &= ( ~ V_56 ) ;
V_54 |= V_59 ;
F_14 ( V_2 , V_55 , V_54 ) ;
F_52 ( 10 ) ;
V_54 |= V_60 ;
F_14 ( V_2 , V_55 , V_54 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
unsigned int V_54 = F_7 ( V_2 , V_55 ) ;
if ( V_2 -> V_4 . V_5 & V_61 ) {
F_54 ( V_2 , V_36 , L_18 ) ;
V_2 -> V_62 = 0 ;
} else if ( V_2 -> V_4 . V_5 & V_63 ) {
F_54 ( V_2 , V_36 , L_19 ) ;
F_51 ( V_2 ) ;
V_2 -> V_62 = 1 ;
} else if ( V_54 & V_64 ) {
F_54 ( V_2 , V_36 ,
L_20 ) ;
F_51 ( V_2 ) ;
V_2 -> V_62 = 1 ;
} else {
F_54 ( V_2 , V_36 ,
L_21 ) ;
V_2 -> V_62 = 0 ;
}
}
static unsigned int F_55 ( struct V_1 * V_2 )
{
unsigned int V_65 =
F_7 ( V_2 , V_66 ) & V_67 ;
if ( V_65 != 0 )
V_65 = F_7 ( V_2 , V_68 ) ;
return V_65 ;
}
static unsigned int F_56 ( struct V_1 * V_2 )
{
unsigned int V_65 =
F_7 ( V_2 , V_69 ) & V_70 ;
if ( V_65 != 0 )
V_65 = F_7 ( V_2 , V_71 ) ;
return V_65 ;
}
static int F_57 ( struct V_1 * V_2 )
{
unsigned int V_72 ;
T_1 V_73 ;
T_1 V_74 ;
T_3 V_75 ;
for ( V_72 = 0 ; V_72 < 10 ; V_72 ++ ) {
unsigned int V_76 ;
unsigned int V_77 ;
unsigned int V_78 ;
unsigned int V_79 ;
unsigned int V_33 ;
memset ( V_2 -> V_80 , 0 , V_81 ) ;
V_76 = ( T_1 ) ( ( T_3 ) V_2 -> V_82 & 0x03 ) << 16 ;
V_76 |= V_83 | V_84 ;
V_76 |= V_81 ;
V_77 = V_81 << 16 | V_81 ;
F_14 ( V_2 , V_18 , V_76 ) ;
F_14 ( V_2 , V_18 , V_77 ) ;
V_75 = ( T_3 ) V_2 -> V_82 & ( ~ 0x3 ) ;
V_73 = V_81 + 3 ;
V_73 += ( T_1 ) ( ( T_3 ) V_2 -> V_82 & 0x3 ) ;
V_73 >>= 2 ;
V_2 -> V_11 -> V_85 ( V_2 , ( unsigned int * ) V_75 , V_73 ) ;
V_33 = 60 ;
do {
F_52 ( 5 ) ;
V_78 = F_55 ( V_2 ) ;
} while ( ( V_33 -- ) && ( ! V_78 ) );
if ( ! V_78 ) {
F_44 ( V_2 , V_36 ,
L_22 ) ;
continue;
}
if ( V_78 & V_86 ) {
F_44 ( V_2 , V_36 ,
L_23 ) ;
continue;
}
V_33 = 60 ;
do {
F_52 ( 5 ) ;
V_78 = F_56 ( V_2 ) ;
} while ( ( V_33 -- ) && ( ! V_78 ) );
if ( ! V_78 ) {
F_44 ( V_2 , V_36 ,
L_24 ) ;
continue;
}
if ( V_78 & V_87 ) {
F_44 ( V_2 , V_36 ,
L_25 ) ;
continue;
}
V_79 = ( ( V_78 & 0x3FFF0000UL ) >> 16 ) ;
V_75 = ( T_3 ) V_2 -> V_80 ;
V_74 = V_79 + 3 ;
V_74 += ( T_1 ) ( ( T_3 ) V_2 -> V_80 & 0x3 ) ;
V_74 >>= 2 ;
V_2 -> V_11 -> V_88 ( V_2 , ( unsigned int * ) V_75 , V_74 ) ;
if ( V_79 != ( V_81 + 4 ) ) {
F_44 ( V_2 , V_36 , L_26
L_27 ,
V_79 ) ;
} else {
unsigned int V_89 ;
int V_90 = 0 ;
for ( V_89 = 0 ; V_89 < V_81 ; V_89 ++ ) {
if ( V_2 -> V_82 [ V_89 ]
!= V_2 -> V_80 [ V_89 ] ) {
V_90 = 1 ;
break;
}
}
if ( ! V_90 ) {
F_54 ( V_2 , V_36 , L_28
L_29 ) ;
return 0 ;
} else {
F_44 ( V_2 , V_36 , L_30
L_31 ) ;
}
}
}
return - V_37 ;
}
static int F_58 ( struct V_1 * V_2 )
{
unsigned int V_39 ;
unsigned int V_33 = 100000 ;
V_39 = F_7 ( V_2 , V_91 ) ;
F_14 ( V_2 , V_91 , V_39 | V_92 ) ;
do {
F_59 ( 1 ) ;
V_39 = F_7 ( V_2 , V_91 ) ;
} while ( ( V_33 -- ) && ( V_39 & V_92 ) );
if ( F_46 ( V_39 & V_92 ) ) {
F_44 ( V_2 , V_36 , L_32 ) ;
return - V_37 ;
}
F_59 ( 1 ) ;
return 0 ;
}
static int F_60 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_93 * V_94 = V_29 -> V_95 ;
int V_65 = - V_37 ;
unsigned int V_33 , V_13 ;
unsigned long V_5 ;
F_61 ( V_2 -> V_82 ) ;
for ( V_33 = 6 ; V_33 < 12 ; V_33 ++ )
V_2 -> V_82 [ V_33 ] = ( char ) V_33 ;
V_2 -> V_82 [ 12 ] = 0x00 ;
V_2 -> V_82 [ 13 ] = 0x00 ;
for ( V_33 = 14 ; V_33 < V_81 ; V_33 ++ )
V_2 -> V_82 [ V_33 ] = ( char ) V_33 ;
V_13 = F_7 ( V_2 , V_55 ) ;
V_13 &= V_96 ;
V_13 |= V_97 ;
F_14 ( V_2 , V_55 , V_13 ) ;
F_14 ( V_2 , V_98 , V_99 ) ;
F_14 ( V_2 , V_100 ,
( T_1 ) ( ( T_3 ) V_2 -> V_80 & 0x03 ) << 8 ) ;
for ( V_33 = 0 ; V_33 < 10 ; V_33 ++ ) {
F_50 ( V_94 -> V_101 . V_44 , V_94 -> V_101 . V_48 ,
V_102 , V_103 | V_104 ) ;
F_8 ( & V_2 -> V_49 , V_5 ) ;
F_48 ( V_2 , V_105 , V_106
| V_107 | V_108 ) ;
F_9 ( & V_2 -> V_49 , V_5 ) ;
if ( F_57 ( V_2 ) == 0 ) {
V_65 = 0 ;
break;
}
V_2 -> V_109 ++ ;
F_8 ( & V_2 -> V_49 , V_5 ) ;
F_48 ( V_2 , V_105 , 0 ) ;
F_9 ( & V_2 -> V_49 , V_5 ) ;
F_58 ( V_2 ) ;
}
F_8 ( & V_2 -> V_49 , V_5 ) ;
F_48 ( V_2 , V_105 , 0 ) ;
F_9 ( & V_2 -> V_49 , V_5 ) ;
F_50 ( V_94 -> V_101 . V_44 , V_94 -> V_101 . V_48 , V_102 , 0 ) ;
F_14 ( V_2 , V_98 , 0 ) ;
F_14 ( V_2 , V_100 , 0 ) ;
return V_65 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_29 ;
struct V_93 * V_94 = V_24 -> V_95 ;
T_1 V_110 = F_7 ( V_2 , V_111 ) ;
T_1 V_112 ;
unsigned long V_5 ;
if ( V_94 -> V_113 == V_114 ) {
T_2 V_115 = F_63 ( V_94 , V_116 ) ;
T_2 V_117 = F_63 ( V_94 , V_118 ) ;
T_4 V_119 = F_64 ( V_115 , V_117 ) ;
if ( V_119 & V_120 )
V_112 = 0xFFFF0002 ;
else
V_112 = 0 ;
if ( V_119 & V_121 )
V_110 |= 0xF ;
else
V_110 &= ~ 0xF ;
F_54 ( V_2 , V_36 , L_33 ,
( V_119 & V_120 ? L_34 : L_35 ) ,
( V_119 & V_121 ? L_34 : L_35 ) ) ;
} else {
F_54 ( V_2 , V_36 , L_36 ) ;
V_112 = 0 ;
V_110 |= 0xF ;
}
F_8 ( & V_2 -> V_49 , V_5 ) ;
F_48 ( V_2 , V_122 , V_112 ) ;
F_9 ( & V_2 -> V_49 , V_5 ) ;
F_14 ( V_2 , V_111 , V_110 ) ;
}
static void F_65 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_93 * V_94 = V_29 -> V_95 ;
unsigned long V_5 ;
int V_123 ;
if ( V_94 -> V_113 != V_2 -> V_124 ) {
unsigned int V_125 ;
F_54 ( V_2 , V_36 , L_37 ) ;
F_8 ( & V_2 -> V_49 , V_5 ) ;
V_125 = F_45 ( V_2 , V_105 ) ;
if ( V_94 -> V_113 ) {
F_54 ( V_2 , V_36 ,
L_38 ) ;
V_125 |= V_106 ;
} else {
F_54 ( V_2 , V_36 ,
L_39 ) ;
V_125 &= ~ V_106 ;
}
F_48 ( V_2 , V_105 , V_125 ) ;
F_9 ( & V_2 -> V_49 , V_5 ) ;
F_62 ( V_2 ) ;
V_2 -> V_124 = V_94 -> V_113 ;
}
V_123 = F_66 ( V_29 ) ;
if ( V_123 != V_2 -> V_126 ) {
F_54 ( V_2 , V_36 , L_40 ) ;
if ( V_123 ) {
F_54 ( V_2 , V_36 , L_41 ) ;
if ( ( V_2 -> V_127 & V_128 ) &&
( ! V_2 -> V_62 ) ) {
V_2 -> V_129 = V_2 -> V_127 ;
F_14 ( V_2 , V_130 ,
V_2 -> V_129 ) ;
}
} else {
F_54 ( V_2 , V_36 , L_42 ) ;
V_2 -> V_129 = F_7 ( V_2 ,
V_130 ) ;
if ( ( V_2 -> V_129 & V_128 ) &&
( ! V_2 -> V_62 ) ) {
V_2 -> V_127 = V_2 -> V_129 ;
V_2 -> V_129 &= ~ V_128 ;
V_2 -> V_129 |= ( V_131
| V_132
| V_133 ) ;
F_14 ( V_2 , V_130 ,
V_2 -> V_129 ) ;
}
}
V_2 -> V_126 = V_123 ;
}
}
static int F_67 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_93 * V_95 = NULL ;
int V_25 ;
V_95 = F_68 ( V_2 -> V_43 ) ;
if ( ! V_95 ) {
F_27 ( V_29 , L_43 ) ;
return - V_134 ;
}
F_54 ( V_2 , V_135 , L_44 ,
V_95 -> V_101 . V_48 , V_95 -> V_136 ) ;
V_25 = F_69 ( V_29 , V_95 , & F_65 ,
V_2 -> V_4 . V_137 ) ;
if ( V_25 ) {
F_27 ( V_29 , L_45 ) ;
return V_25 ;
}
F_70 ( V_95 ) ;
V_95 -> V_138 &= ( V_139 | V_140 |
V_141 ) ;
V_95 -> V_142 = V_95 -> V_138 ;
V_2 -> V_124 = - 1 ;
V_2 -> V_126 = - 1 ;
#ifdef F_71
if ( F_60 ( V_29 ) < 0 ) {
F_44 ( V_2 , V_36 , L_46 ) ;
F_72 ( V_95 ) ;
return - V_134 ;
}
F_54 ( V_2 , V_36 , L_47 ) ;
#endif
F_54 ( V_2 , V_36 , L_48 ) ;
return 0 ;
}
static int F_73 ( struct V_21 * V_22 ,
struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
int V_143 = - V_144 ;
V_2 -> V_43 = F_74 () ;
if ( ! V_2 -> V_43 ) {
V_143 = - V_145 ;
goto V_146;
}
V_2 -> V_43 -> V_147 = V_148 ;
snprintf ( V_2 -> V_43 -> V_149 , V_150 , L_49 ,
V_22 -> V_147 , V_22 -> V_149 ) ;
V_2 -> V_43 -> V_47 = V_2 ;
V_2 -> V_43 -> V_151 = F_49 ;
V_2 -> V_43 -> V_152 = F_50 ;
V_2 -> V_43 -> V_153 = & V_22 -> V_29 ;
switch ( V_2 -> V_154 & 0xFFFF0000 ) {
case 0x01170000 :
case 0x01150000 :
case 0x117A0000 :
case 0x115A0000 :
F_53 ( V_2 ) ;
break;
default:
F_54 ( V_2 , V_36 , L_50
L_51 ) ;
V_2 -> V_62 = 0 ;
break;
}
if ( ! V_2 -> V_62 ) {
V_2 -> V_43 -> V_155 = ~ ( 1 << 1 ) ;
}
if ( F_75 ( V_2 -> V_43 ) ) {
F_44 ( V_2 , V_135 , L_52 ) ;
goto V_156;
}
return 0 ;
V_156:
F_76 ( V_2 -> V_43 ) ;
V_146:
return V_143 ;
}
static unsigned int F_77 ( struct V_1 * V_2 )
{
return ( F_7 ( V_2 , V_66 )
& V_67 ) >> 16 ;
}
static void F_78 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_157 ;
while ( ( V_157 = F_55 ( V_2 ) ) != 0 ) {
if ( F_46 ( V_157 & 0x80000000 ) ) {
F_44 ( V_2 , V_36 , L_53 ) ;
} else {
if ( F_46 ( V_157 & V_86 ) ) {
V_29 -> V_158 . V_159 ++ ;
} else {
V_29 -> V_158 . V_160 ++ ;
V_29 -> V_158 . V_161 += ( V_157 >> 16 ) ;
}
if ( F_46 ( V_157 & V_162 ) ) {
V_29 -> V_158 . V_163 += 16 ;
V_29 -> V_158 . V_164 += 1 ;
} else {
V_29 -> V_158 . V_163 +=
( ( V_157 >> 3 ) & 0xF ) ;
}
if ( F_46 ( V_157 & V_165 ) )
V_29 -> V_158 . V_166 += 1 ;
if ( F_46 ( V_157 & V_167 ) ) {
V_29 -> V_158 . V_163 ++ ;
V_29 -> V_158 . V_164 ++ ;
}
}
}
}
static void
F_79 ( struct V_23 * V_29 , unsigned int V_168 )
{
int V_169 = 0 ;
if ( F_46 ( V_168 & V_87 ) ) {
V_29 -> V_158 . V_170 ++ ;
if ( F_46 ( V_168 & V_171 ) ) {
V_29 -> V_158 . V_172 ++ ;
V_169 = 1 ;
}
}
if ( F_47 ( ! V_169 ) ) {
if ( F_46 ( ( V_168 & V_173 ) &&
( V_168 & V_174 ) ) )
V_29 -> V_158 . V_175 ++ ;
if ( V_168 & V_176 )
V_29 -> V_158 . V_177 ++ ;
}
}
static void
F_80 ( struct V_1 * V_2 , unsigned int V_178 )
{
if ( F_47 ( V_178 >= 4 ) ) {
unsigned int V_179 = 500 ;
unsigned int V_13 ;
F_14 ( V_2 , V_180 , V_181 ) ;
do {
F_52 ( 1 ) ;
V_13 = F_7 ( V_2 , V_180 ) ;
} while ( ( V_13 & V_181 ) && -- V_179 );
if ( F_46 ( V_179 == 0 ) )
F_44 ( V_2 , V_36 , L_54
L_55 , V_13 ) ;
} else {
unsigned int V_39 ;
while ( V_178 -- )
V_39 = F_7 ( V_2 , V_20 ) ;
}
}
static int F_81 ( struct V_182 * V_183 , int V_184 )
{
struct V_1 * V_2 =
F_82 ( V_183 , struct V_1 , V_183 ) ;
struct V_23 * V_29 = V_2 -> V_29 ;
int V_185 = 0 ;
while ( V_185 < V_184 ) {
unsigned int V_79 ;
unsigned int V_178 ;
struct V_186 * V_187 ;
unsigned int V_168 = F_56 ( V_2 ) ;
if ( ! V_168 ) {
unsigned int V_39 ;
F_14 ( V_2 , V_188 , V_189 ) ;
F_83 ( V_183 ) ;
V_39 = F_7 ( V_2 , V_190 ) ;
V_39 |= V_191 ;
F_14 ( V_2 , V_190 , V_39 ) ;
break;
}
V_185 ++ ;
V_79 = ( ( V_168 & 0x3FFF0000 ) >> 16 ) ;
V_178 = ( V_79 + V_192 + 3 ) >> 2 ;
F_79 ( V_29 , V_168 ) ;
if ( F_46 ( V_168 & V_87 ) ) {
F_44 ( V_2 , V_193 ,
L_56 ) ;
F_80 ( V_2 , V_178 ) ;
V_29 -> V_158 . V_194 ++ ;
continue;
}
V_187 = F_84 ( V_29 , V_178 << 2 ) ;
if ( F_46 ( ! V_187 ) ) {
F_44 ( V_2 , V_193 ,
L_57 ) ;
F_80 ( V_2 , V_178 ) ;
V_29 -> V_158 . V_194 ++ ;
break;
}
V_2 -> V_11 -> V_88 ( V_2 ,
( unsigned int * ) V_187 -> V_9 , V_178 ) ;
F_85 ( V_187 , V_192 ) ;
F_86 ( V_187 , V_79 - 4 ) ;
V_187 -> V_195 = F_87 ( V_187 , V_29 ) ;
F_88 ( V_187 ) ;
F_89 ( V_187 ) ;
V_29 -> V_158 . V_196 ++ ;
V_29 -> V_158 . V_197 += ( V_79 - 4 ) ;
}
return V_185 ;
}
static unsigned int F_90 ( char V_48 [ V_198 ] )
{
return ( F_91 ( V_198 , V_48 ) >> 26 ) & 0x3f ;
}
static void F_92 ( struct V_1 * V_2 )
{
unsigned int V_125 ;
F_43 ( V_2 ) ;
V_125 = F_45 ( V_2 , V_105 ) ;
V_125 |= V_2 -> V_199 ;
V_125 &= ~ ( V_2 -> V_200 ) ;
F_48 ( V_2 , V_105 , V_125 ) ;
F_48 ( V_2 , V_201 , V_2 -> V_202 ) ;
F_48 ( V_2 , V_203 , V_2 -> V_204 ) ;
F_54 ( V_2 , V_36 , L_58 ,
V_125 , V_2 -> V_202 , V_2 -> V_204 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
unsigned int V_125 ;
F_94 ( & V_2 -> V_49 ) ;
if ( F_45 ( V_2 , V_105 ) & V_108 )
F_44 ( V_2 , V_205 , L_59 ) ;
F_92 ( V_2 ) ;
V_125 = F_45 ( V_2 , V_105 ) ;
V_125 |= V_108 ;
F_48 ( V_2 , V_105 , V_125 ) ;
V_2 -> V_206 = 0 ;
F_95 ( & V_2 -> V_49 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_29 ;
struct V_93 * V_94 = V_24 -> V_95 ;
int V_207 = 0 ;
if ( ! V_94 )
return V_207 ;
V_207 = F_63 ( V_94 , V_102 ) ;
if ( V_207 < 0 ) {
F_44 ( V_2 , V_205 , L_60 ) ;
return V_207 ;
}
if ( V_207 & V_208 ) {
V_207 = F_97 ( V_94 , V_102 , V_207 & ~ V_208 ) ;
if ( V_207 < 0 ) {
F_44 ( V_2 , V_205 , L_61 ) ;
return V_207 ;
}
F_98 ( 1000 , 1500 ) ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_29 ;
struct V_93 * V_94 = V_24 -> V_95 ;
int V_207 = 0 ;
if ( ! V_94 )
return V_207 ;
V_207 = F_63 ( V_94 , V_209 ) ;
if ( V_207 < 0 ) {
F_44 ( V_2 , V_205 , L_60 ) ;
return V_207 ;
}
if ( V_207 & V_210 ) {
V_207 = F_97 ( V_94 , V_209 ,
V_207 & ( ~ V_210 ) ) ;
if ( V_207 < 0 ) {
F_44 ( V_2 , V_205 , L_61 ) ;
return V_207 ;
}
F_100 ( 2 ) ;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
struct V_23 * V_24 = V_2 -> V_29 ;
struct V_93 * V_94 = V_24 -> V_95 ;
int V_207 = 0 ;
if ( ! V_94 )
return V_207 ;
V_207 = F_63 ( V_94 , V_209 ) ;
if ( V_207 < 0 ) {
F_44 ( V_2 , V_205 , L_60 ) ;
return V_207 ;
}
if ( ! ( V_207 & V_210 ) ) {
V_207 = F_97 ( V_94 , V_209 ,
V_207 | V_210 ) ;
if ( V_207 < 0 ) {
F_44 ( V_2 , V_205 , L_61 ) ;
return V_207 ;
}
}
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
unsigned int V_179 ;
unsigned int V_39 ;
int V_25 ;
V_25 = F_96 ( V_2 ) ;
if ( V_25 ) {
F_44 ( V_2 , V_205 , L_62 ) ;
return V_25 ;
}
if ( V_2 -> V_211 == 4 ) {
V_25 = F_99 ( V_2 ) ;
if ( V_25 ) {
F_44 ( V_2 , V_205 , L_63 ) ;
return V_25 ;
}
}
F_14 ( V_2 , V_55 , V_212 ) ;
V_179 = 10 ;
do {
F_52 ( 10 ) ;
V_39 = F_7 ( V_2 , V_55 ) ;
} while ( ( -- V_179 ) && ( V_39 & V_212 ) );
if ( F_46 ( V_39 & V_212 ) ) {
F_44 ( V_2 , V_205 , L_64 ) ;
return - V_37 ;
}
if ( V_2 -> V_211 == 4 ) {
V_25 = F_101 ( V_2 ) ;
if ( V_25 ) {
F_44 ( V_2 , V_205 , L_63 ) ;
return V_25 ;
}
}
return 0 ;
}
static void
F_103 ( struct V_1 * V_2 , T_4 V_213 [ 6 ] )
{
T_1 V_214 = ( V_213 [ 5 ] << 8 ) | V_213 [ 4 ] ;
T_1 V_215 = ( V_213 [ 3 ] << 24 ) | ( V_213 [ 2 ] << 16 ) |
( V_213 [ 1 ] << 8 ) | V_213 [ 0 ] ;
F_43 ( V_2 ) ;
F_48 ( V_2 , V_216 , V_214 ) ;
F_48 ( V_2 , V_217 , V_215 ) ;
}
static void F_104 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_14 ( V_2 , V_190 , 0 ) ;
F_14 ( V_2 , V_188 , 0xFFFFFFFF ) ;
}
static T_5 F_105 ( int V_218 , void * V_219 )
{
struct V_23 * V_29 = V_219 ;
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_1 V_220 = F_7 ( V_2 , V_188 ) ;
T_1 V_221 = F_7 ( V_2 , V_190 ) ;
int V_222 = V_223 ;
T_1 V_39 ;
if ( F_46 ( V_220 & V_221 & V_224 ) ) {
V_39 = F_7 ( V_2 , V_190 ) ;
V_39 &= ( ~ V_225 ) ;
F_14 ( V_2 , V_190 , V_39 ) ;
F_14 ( V_2 , V_188 , V_224 ) ;
V_2 -> V_226 = 1 ;
F_106 () ;
V_222 = V_227 ;
}
if ( F_46 ( V_220 & V_221 & V_228 ) ) {
F_54 ( V_2 , V_229 , L_65 ) ;
F_14 ( V_2 , V_188 , V_228 ) ;
if ( V_2 -> V_206 )
F_93 ( V_2 ) ;
V_222 = V_227 ;
}
if ( V_220 & V_221 & V_230 ) {
V_39 = F_7 ( V_2 , V_231 ) ;
V_39 |= V_232 ;
F_14 ( V_2 , V_231 , V_39 ) ;
F_14 ( V_2 , V_188 , V_230 ) ;
F_107 ( V_29 ) ;
V_222 = V_227 ;
}
if ( F_46 ( V_220 & V_221 & V_233 ) ) {
F_54 ( V_2 , V_229 , L_66 ) ;
F_14 ( V_2 , V_188 , V_233 ) ;
V_222 = V_227 ;
}
if ( F_47 ( V_220 & V_221 & V_189 ) ) {
if ( F_47 ( F_108 ( & V_2 -> V_183 ) ) ) {
V_39 = F_7 ( V_2 , V_190 ) ;
V_39 &= ( ~ V_191 ) ;
F_14 ( V_2 , V_190 , V_39 ) ;
F_109 ( & V_2 -> V_183 ) ;
} else {
F_44 ( V_2 , V_193 , L_67 ) ;
}
V_222 = V_227 ;
}
return V_222 ;
}
static int F_110 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_179 ;
unsigned int V_39 ;
unsigned int V_234 ;
int V_235 ;
int V_236 ;
if ( ! V_29 -> V_95 ) {
V_235 = F_67 ( V_29 ) ;
if ( V_235 < 0 ) {
F_44 ( V_2 , V_135 , L_68 ) ;
goto V_19;
}
}
V_235 = F_102 ( V_2 ) ;
if ( V_235 ) {
F_44 ( V_2 , V_36 , L_69 ) ;
goto V_237;
}
F_14 ( V_2 , V_55 , 0x00050000 ) ;
F_14 ( V_2 , V_111 , 0x006E3740 ) ;
F_111 ( & V_2 -> V_49 ) ;
F_48 ( V_2 , V_238 , V_239 ) ;
F_112 ( & V_2 -> V_49 ) ;
V_179 = 50 ;
while ( ( F_7 ( V_2 , V_240 ) & V_241 ) &&
-- V_179 ) {
F_52 ( 10 ) ;
}
if ( F_46 ( V_179 == 0 ) )
F_44 ( V_2 , V_242 ,
L_70 ) ;
F_14 ( V_2 , V_130 , 0x70070000 ) ;
F_111 ( & V_2 -> V_49 ) ;
F_103 ( V_2 , V_29 -> V_213 ) ;
F_112 ( & V_2 -> V_49 ) ;
F_104 ( V_29 ) ;
V_234 = ( ( 10 << 24 ) | V_243 ) ;
if ( V_2 -> V_4 . V_244 ) {
F_54 ( V_2 , V_242 , L_71 ) ;
V_234 |= V_245 ;
} else {
F_54 ( V_2 , V_242 , L_72 ) ;
}
if ( V_2 -> V_4 . V_246 ) {
F_54 ( V_2 , V_242 , L_73 ) ;
V_234 |= V_247 ;
} else {
F_54 ( V_2 , V_242 , L_74 ) ;
}
F_14 ( V_2 , V_248 , V_234 ) ;
F_54 ( V_2 , V_242 , L_75 , V_29 -> V_218 ) ;
V_2 -> V_226 = 0 ;
F_106 () ;
V_236 = F_113 ( V_29 -> V_218 ) ;
V_235 = F_114 ( V_29 -> V_218 , F_105 ,
V_236 | V_249 , V_29 -> V_147 , V_29 ) ;
if ( V_235 ) {
F_44 ( V_2 , V_135 ,
L_76 , V_29 -> V_218 ) ;
goto V_237;
}
V_39 = F_7 ( V_2 , V_190 ) ;
V_39 |= V_225 ;
F_14 ( V_2 , V_190 , V_39 ) ;
V_179 = 1000 ;
while ( V_179 -- ) {
if ( V_2 -> V_226 )
break;
F_59 ( 1 ) ;
}
if ( ! V_2 -> V_226 ) {
F_115 ( V_29 , L_77 ,
V_29 -> V_218 ) ;
V_235 = - V_134 ;
goto V_250;
}
F_54 ( V_2 , V_242 , L_78 ,
V_29 -> V_218 ) ;
F_116 ( V_29 , L_79 ,
( unsigned long ) V_2 -> V_7 , V_29 -> V_218 ) ;
V_2 -> V_124 = - 1 ;
V_2 -> V_126 = - 1 ;
F_117 ( V_29 -> V_95 ) ;
V_39 = F_7 ( V_2 , V_55 ) ;
V_39 &= ( V_96 | 0x00000FFF ) ;
V_39 |= V_97 ;
F_14 ( V_2 , V_55 , V_39 ) ;
V_39 = F_7 ( V_2 , V_231 ) ;
V_39 |= V_232 ;
V_39 &= ~ ( V_251 ) ;
F_14 ( V_2 , V_231 , V_39 ) ;
F_14 ( V_2 , V_100 , ( V_192 << 8 ) ) ;
F_118 ( & V_2 -> V_183 ) ;
V_39 = F_7 ( V_2 , V_190 ) ;
V_39 |= ( V_252 | V_191 | V_253 ) ;
F_14 ( V_2 , V_190 , V_39 ) ;
F_111 ( & V_2 -> V_49 ) ;
V_39 = F_45 ( V_2 , V_105 ) ;
V_39 |= ( V_107 | V_108 | V_254 ) ;
F_48 ( V_2 , V_105 , V_39 ) ;
F_112 ( & V_2 -> V_49 ) ;
F_14 ( V_2 , V_98 , V_99 ) ;
F_119 ( V_29 ) ;
return 0 ;
V_250:
F_120 ( V_29 -> V_218 , V_29 ) ;
V_237:
F_72 ( V_29 -> V_95 ) ;
V_29 -> V_95 = NULL ;
V_19:
return V_235 ;
}
static int F_121 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_39 ;
V_39 = F_7 ( V_2 , V_248 ) ;
V_39 &= ~ V_243 ;
F_14 ( V_2 , V_248 , V_39 ) ;
F_122 ( V_29 ) ;
F_123 ( & V_2 -> V_183 ) ;
V_29 -> V_158 . V_194 += F_7 ( V_2 , V_255 ) ;
F_78 ( V_29 ) ;
F_120 ( V_29 -> V_218 , V_29 ) ;
if ( V_29 -> V_95 ) {
F_124 ( V_29 -> V_95 ) ;
F_72 ( V_29 -> V_95 ) ;
V_29 -> V_95 = NULL ;
}
F_125 ( V_29 ) ;
F_54 ( V_2 , V_256 , L_80 ) ;
return 0 ;
}
static int F_126 ( struct V_186 * V_187 , struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_257 ;
unsigned int V_258 ;
unsigned int V_259 ;
unsigned int V_39 ;
T_1 V_73 ;
T_3 V_75 ;
V_257 = F_7 ( V_2 , V_66 ) & V_260 ;
if ( F_46 ( V_257 < V_261 ) )
F_44 ( V_2 , V_262 ,
L_81 , V_257 ) ;
V_258 = ( T_1 ) ( ( T_3 ) V_187 -> V_9 & 0x03 ) << 16 ;
V_258 |= V_83 | V_84 ;
V_258 |= ( unsigned int ) V_187 -> V_263 ;
V_259 = ( ( unsigned int ) V_187 -> V_263 ) << 16 ;
V_259 |= ( unsigned int ) V_187 -> V_263 ;
F_14 ( V_2 , V_18 , V_258 ) ;
F_14 ( V_2 , V_18 , V_259 ) ;
V_75 = ( T_3 ) V_187 -> V_9 & ( ~ 0x3 ) ;
V_73 = ( T_1 ) V_187 -> V_263 + 3 ;
V_73 += ( T_1 ) ( ( T_3 ) V_187 -> V_9 & 0x3 ) ;
V_73 >>= 2 ;
V_2 -> V_11 -> V_85 ( V_2 , ( unsigned int * ) V_75 , V_73 ) ;
V_257 -= ( V_187 -> V_263 + 32 ) ;
F_127 ( V_187 ) ;
F_128 ( V_187 ) ;
if ( F_46 ( F_77 ( V_2 ) >= 30 ) )
F_78 ( V_29 ) ;
if ( V_257 < V_261 ) {
F_122 ( V_29 ) ;
V_39 = F_7 ( V_2 , V_231 ) ;
V_39 &= 0x00FFFFFF ;
V_39 |= 0x32000000 ;
F_14 ( V_2 , V_231 , V_39 ) ;
}
return V_264 ;
}
static struct V_265 * F_129 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_78 ( V_29 ) ;
V_29 -> V_158 . V_194 += F_7 ( V_2 , V_255 ) ;
return & V_29 -> V_158 ;
}
static void F_130 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned long V_5 ;
if ( V_29 -> V_5 & V_266 ) {
V_2 -> V_199 = V_267 ;
V_2 -> V_200 = ( V_268 | V_269 ) ;
V_2 -> V_202 = 0 ;
V_2 -> V_204 = 0 ;
} else if ( V_29 -> V_5 & V_270 ) {
V_2 -> V_199 = V_268 ;
V_2 -> V_200 = ( V_267 | V_269 ) ;
V_2 -> V_202 = 0 ;
V_2 -> V_204 = 0 ;
} else if ( ! F_131 ( V_29 ) ) {
unsigned int V_271 = 0 ;
unsigned int V_272 = 0 ;
struct V_273 * V_274 ;
V_2 -> V_199 = V_269 ;
V_2 -> V_200 = ( V_267 | V_268 ) ;
F_132 (ha, dev) {
unsigned int V_275 = F_90 ( V_274 -> V_48 ) ;
unsigned int V_276 = 0x01 << ( V_275 & 0x1F ) ;
if ( V_275 & 0x20 )
V_271 |= V_276 ;
else
V_272 |= V_276 ;
}
V_2 -> V_202 = V_271 ;
V_2 -> V_204 = V_272 ;
} else {
V_2 -> V_199 = 0 ;
V_2 -> V_200 =
( V_267 | V_268 | V_269 ) ;
V_2 -> V_202 = 0 ;
V_2 -> V_204 = 0 ;
}
F_8 ( & V_2 -> V_49 , V_5 ) ;
if ( V_2 -> V_211 <= 1 ) {
if ( ! V_2 -> V_206 ) {
unsigned int V_39 ;
F_54 ( V_2 , V_36 , L_82 ) ;
V_2 -> V_206 = 1 ;
V_39 = F_45 ( V_2 , V_105 ) ;
V_39 &= ~ ( V_108 ) ;
F_48 ( V_2 , V_105 , V_39 ) ;
} else {
}
} else {
F_92 ( V_2 ) ;
}
F_9 ( & V_2 -> V_49 , V_5 ) ;
}
static void F_133 ( struct V_23 * V_29 )
{
F_134 ( V_29 -> V_218 ) ;
F_105 ( 0 , V_29 ) ;
F_135 ( V_29 -> V_218 ) ;
}
static int F_136 ( struct V_23 * V_29 , void * V_277 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_278 * V_48 = V_277 ;
if ( V_2 -> V_211 <= 1 && F_137 ( V_29 ) )
return - V_279 ;
if ( ! F_138 ( V_48 -> V_280 ) )
return - V_281 ;
memcpy ( V_29 -> V_213 , V_48 -> V_280 , V_198 ) ;
F_111 ( & V_2 -> V_49 ) ;
F_103 ( V_2 , V_29 -> V_213 ) ;
F_112 ( & V_2 -> V_49 ) ;
F_116 ( V_29 , L_83 , V_29 -> V_213 ) ;
return 0 ;
}
static int F_139 ( struct V_23 * V_29 , struct V_282 * V_283 , int V_284 )
{
if ( ! F_137 ( V_29 ) || ! V_29 -> V_95 )
return - V_285 ;
return F_140 ( V_29 -> V_95 , V_283 , V_284 ) ;
}
static void F_141 ( struct V_23 * V_29 ,
struct V_286 * V_287 )
{
F_142 ( V_287 -> V_288 , V_289 , sizeof( V_287 -> V_288 ) ) ;
F_142 ( V_287 -> V_290 , V_291 , sizeof( V_287 -> V_290 ) ) ;
F_142 ( V_287 -> V_292 , F_143 ( V_29 -> V_29 . V_153 ) ,
sizeof( V_287 -> V_292 ) ) ;
}
static T_1 F_144 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
return V_2 -> V_293 ;
}
static void F_145 ( struct V_23 * V_29 , T_1 V_294 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
V_2 -> V_293 = V_294 ;
}
static int F_146 ( struct V_23 * V_29 )
{
return ( ( ( V_295 - V_296 ) / 4 + 1 ) + ( V_297 - V_105 ) + 1 + 32 ) *
sizeof( T_1 ) ;
}
static void
F_147 ( struct V_23 * V_29 , struct V_298 * V_299 ,
void * V_15 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_93 * V_94 = V_29 -> V_95 ;
unsigned long V_5 ;
unsigned int V_33 ;
unsigned int V_89 = 0 ;
T_1 * V_9 = V_15 ;
V_299 -> V_290 = V_2 -> V_154 ;
for ( V_33 = V_296 ; V_33 <= V_295 ; V_33 += ( sizeof( T_1 ) ) )
V_9 [ V_89 ++ ] = F_7 ( V_2 , V_33 ) ;
for ( V_33 = V_105 ; V_33 <= V_297 ; V_33 ++ ) {
F_8 ( & V_2 -> V_49 , V_5 ) ;
V_9 [ V_89 ++ ] = F_45 ( V_2 , V_33 ) ;
F_9 ( & V_2 -> V_49 , V_5 ) ;
}
for ( V_33 = 0 ; V_33 <= 31 ; V_33 ++ )
V_9 [ V_89 ++ ] = F_49 ( V_94 -> V_101 . V_44 ,
V_94 -> V_101 . V_48 , V_33 ) ;
}
static void F_148 ( struct V_1 * V_2 )
{
unsigned int V_39 = F_7 ( V_2 , V_130 ) ;
V_39 &= ~ V_300 ;
F_14 ( V_2 , V_130 , V_39 ) ;
F_59 ( 1 ) ;
}
static int F_149 ( struct V_1 * V_2 , T_1 V_301 )
{
int V_179 = 100 ;
T_1 V_302 ;
F_54 ( V_2 , V_205 , L_84 , V_301 ) ;
if ( F_7 ( V_2 , V_240 ) & V_241 ) {
F_44 ( V_2 , V_205 , L_85 ) ;
return - V_279 ;
}
V_302 = V_301 | V_241 ;
F_14 ( V_2 , V_240 , V_302 ) ;
do {
F_59 ( 1 ) ;
V_302 = F_7 ( V_2 , V_240 ) ;
} while ( ( V_302 & V_241 ) && ( -- V_179 ) );
if ( ! V_179 ) {
F_54 ( V_2 , V_205 , L_86 ) ;
return - V_303 ;
}
if ( V_302 & V_304 ) {
F_54 ( V_2 , V_205 , L_87 ) ;
return - V_285 ;
}
return 0 ;
}
static int F_150 ( struct V_1 * V_2 ,
T_4 V_305 , T_4 * V_9 )
{
T_1 V_301 = V_306 | V_305 ;
int V_25 ;
F_54 ( V_2 , V_205 , L_88 , V_305 ) ;
V_25 = F_149 ( V_2 , V_301 ) ;
if ( ! V_25 )
V_9 [ V_305 ] = F_7 ( V_2 , V_295 ) ;
return V_25 ;
}
static int F_151 ( struct V_1 * V_2 ,
T_4 V_305 , T_4 V_9 )
{
T_1 V_301 = V_307 | V_305 ;
T_1 V_39 ;
int V_25 ;
F_54 ( V_2 , V_205 , L_89 , V_305 , V_9 ) ;
V_25 = F_149 ( V_2 , V_301 ) ;
if ( ! V_25 ) {
V_301 = V_308 | V_305 ;
F_14 ( V_2 , V_295 , ( T_1 ) V_9 ) ;
V_39 = F_7 ( V_2 , V_41 ) ;
V_25 = F_149 ( V_2 , V_301 ) ;
}
return V_25 ;
}
static int F_152 ( struct V_23 * V_29 )
{
return V_309 ;
}
static int F_153 ( struct V_23 * V_29 ,
struct V_310 * V_311 , T_4 * V_9 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_4 V_312 [ V_309 ] ;
int V_263 ;
int V_33 ;
F_148 ( V_2 ) ;
V_263 = F_154 ( V_311 -> V_263 , V_309 ) ;
for ( V_33 = 0 ; V_33 < V_263 ; V_33 ++ ) {
int V_25 = F_150 ( V_2 , V_33 , V_312 ) ;
if ( V_25 < 0 ) {
V_311 -> V_263 = 0 ;
return V_25 ;
}
}
memcpy ( V_9 , & V_312 [ V_311 -> V_38 ] , V_263 ) ;
V_311 -> V_263 = V_263 ;
return 0 ;
}
static int F_155 ( struct V_23 * V_29 ,
struct V_310 * V_311 , T_4 * V_9 )
{
int V_25 ;
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_148 ( V_2 ) ;
F_149 ( V_2 , V_313 ) ;
V_25 = F_151 ( V_2 , V_311 -> V_38 , * V_9 ) ;
F_149 ( V_2 , V_314 ) ;
V_311 -> V_263 = 1 ;
return V_25 ;
}
static void F_156 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_1 V_214 = F_45 ( V_2 , V_216 ) ;
T_1 V_215 = F_45 ( V_2 , V_217 ) ;
V_29 -> V_213 [ 0 ] = ( T_4 ) ( V_215 ) ;
V_29 -> V_213 [ 1 ] = ( T_4 ) ( V_215 >> 8 ) ;
V_29 -> V_213 [ 2 ] = ( T_4 ) ( V_215 >> 16 ) ;
V_29 -> V_213 [ 3 ] = ( T_4 ) ( V_215 >> 24 ) ;
V_29 -> V_213 [ 4 ] = ( T_4 ) ( V_214 ) ;
V_29 -> V_213 [ 5 ] = ( T_4 ) ( V_214 >> 8 ) ;
}
static int F_157 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_315 , V_276 ;
unsigned int V_316 = 100 ;
F_54 ( V_2 , V_135 , L_90 ) ;
F_54 ( V_2 , V_135 , L_91 ,
( unsigned long ) V_2 -> V_7 ) ;
F_54 ( V_2 , V_135 , L_92 , V_29 -> V_218 ) ;
F_54 ( V_2 , V_135 , L_93 ) ;
F_158 ( & V_2 -> V_10 ) ;
F_158 ( & V_2 -> V_49 ) ;
if ( V_2 -> V_7 == NULL ) {
F_44 ( V_2 , V_135 , L_94 ) ;
return - V_134 ;
}
V_276 = V_317 | F_159 ( V_317 ) ;
while ( ! ( F_7 ( V_2 , V_91 ) & V_276 ) && -- V_316 )
F_52 ( 1000 ) ;
if ( V_316 == 0 ) {
F_27 ( V_29 , L_95 ) ;
return - V_134 ;
}
V_315 = F_7 ( V_2 , V_41 ) ;
F_54 ( V_2 , V_135 , L_96 , V_315 ) ;
if ( V_315 == 0x43218765 ) {
F_54 ( V_2 , V_135 , L_97
L_98 ) ;
F_14 ( V_2 , V_318 , 0xffffffff ) ;
V_315 = F_7 ( V_2 , V_41 ) ;
V_315 = F_7 ( V_2 , V_41 ) ;
}
if ( V_315 != 0x87654321 ) {
F_44 ( V_2 , V_205 , L_96 , V_315 ) ;
if ( ( ( V_315 >> 16 ) & 0xFFFF ) == ( V_315 & 0xFFFF ) ) {
F_44 ( V_2 , V_135 ,
L_99 ) ;
F_54 ( V_2 , V_135 ,
L_100
L_101 ) ;
}
return - V_134 ;
}
V_2 -> V_211 = 0 ;
V_2 -> V_154 = F_7 ( V_2 , V_296 ) ;
switch ( V_2 -> V_154 & 0xFFFF0000 ) {
case 0x01180000 :
case 0x01170000 :
case 0x01160000 :
case 0x01150000 :
case 0x218A0000 :
V_2 -> V_211 = V_2 -> V_154 & 0x0000FFFF ;
break;
case 0x118A0000 :
case 0x117A0000 :
case 0x116A0000 :
case 0x115A0000 :
V_2 -> V_211 = 3 ;
break;
case 0x92100000 :
case 0x92110000 :
case 0x92200000 :
case 0x92210000 :
V_2 -> V_211 = 4 ;
break;
default:
F_44 ( V_2 , V_135 , L_102 ,
V_2 -> V_154 ) ;
return - V_134 ;
}
F_54 ( V_2 , V_135 ,
L_103 ,
V_2 -> V_154 , V_2 -> V_211 ) ;
if ( V_2 -> V_211 == 0 )
F_44 ( V_2 , V_135 ,
L_104 ) ;
if ( V_2 -> V_4 . V_5 & V_319 ) {
F_111 ( & V_2 -> V_49 ) ;
F_156 ( V_29 ) ;
F_112 ( & V_2 -> V_49 ) ;
}
if ( F_58 ( V_2 ) || F_102 ( V_2 ) )
return - V_134 ;
V_29 -> V_5 |= V_320 ;
F_160 ( V_29 , & V_2 -> V_183 , F_81 , V_321 ) ;
V_29 -> V_322 = & V_323 ;
V_29 -> V_324 = & V_325 ;
return 0 ;
}
static int F_161 ( struct V_21 * V_22 )
{
struct V_23 * V_29 ;
struct V_1 * V_2 ;
struct V_326 * V_327 ;
V_29 = F_23 ( V_22 ) ;
F_162 ( ! V_29 ) ;
V_2 = F_24 ( V_29 ) ;
F_162 ( ! V_2 ) ;
F_162 ( ! V_2 -> V_7 ) ;
F_163 ( V_29 -> V_95 ) ;
F_54 ( V_2 , V_256 , L_105 ) ;
F_164 ( V_2 -> V_43 ) ;
F_76 ( V_2 -> V_43 ) ;
F_165 ( V_29 ) ;
V_327 = F_166 ( V_22 , V_328 ,
L_106 ) ;
if ( ! V_327 )
V_327 = F_167 ( V_22 , V_328 , 0 ) ;
F_168 ( V_327 -> V_329 , F_169 ( V_327 ) ) ;
F_170 ( V_2 -> V_7 ) ;
( void ) F_30 ( V_22 ) ;
F_39 ( V_22 ) ;
F_171 ( V_29 ) ;
F_172 ( & V_22 -> V_29 ) ;
F_173 ( & V_22 -> V_29 ) ;
return 0 ;
}
static int F_174 ( struct V_330 * V_4 ,
struct V_331 * V_29 )
{
int V_137 ;
T_1 V_332 = 0 ;
int V_143 ;
V_137 = F_175 ( V_29 ) ;
if ( V_137 < 0 )
V_137 = V_333 ;
V_4 -> V_137 = V_137 ;
F_176 ( V_29 , V_4 -> V_334 , V_198 ) ;
V_143 = F_177 ( V_29 , L_107 , & V_332 ) ;
if ( V_143 == - V_144 )
return V_143 ;
if ( ! V_143 && V_332 == 4 )
V_4 -> V_5 |= V_6 ;
else
V_4 -> V_5 |= V_8 ;
F_177 ( V_29 , L_108 , & V_4 -> V_335 ) ;
if ( F_178 ( V_29 , L_109 ) )
V_4 -> V_244 = V_336 ;
if ( F_178 ( V_29 , L_110 ) )
V_4 -> V_246 = V_337 ;
if ( F_178 ( V_29 , L_111 ) )
V_4 -> V_5 |= V_61 ;
if ( F_178 ( V_29 , L_112 ) )
V_4 -> V_5 |= V_63 ;
if ( F_178 ( V_29 , L_113 ) )
V_4 -> V_5 |= V_319 ;
return 0 ;
}
static int F_179 ( struct V_21 * V_22 )
{
struct V_23 * V_29 ;
struct V_1 * V_2 ;
struct V_330 * V_4 = F_180 ( & V_22 -> V_29 ) ;
struct V_326 * V_327 ;
int V_338 , V_218 ;
int V_235 ;
V_327 = F_166 ( V_22 , V_328 ,
L_106 ) ;
if ( ! V_327 )
V_327 = F_167 ( V_22 , V_328 , 0 ) ;
if ( ! V_327 ) {
F_181 ( L_114 ) ;
V_235 = - V_134 ;
goto V_339;
}
V_338 = F_169 ( V_327 ) ;
V_218 = F_182 ( V_22 , 0 ) ;
if ( V_218 == - V_30 ) {
V_235 = - V_30 ;
goto V_339;
} else if ( V_218 <= 0 ) {
F_181 ( L_115 ) ;
V_235 = - V_134 ;
goto V_339;
}
if ( ! F_183 ( V_327 -> V_329 , V_338 , V_289 ) ) {
V_235 = - V_279 ;
goto V_339;
}
V_29 = F_184 ( sizeof( struct V_1 ) ) ;
if ( ! V_29 ) {
V_235 = - V_145 ;
goto V_340;
}
F_185 ( V_29 , & V_22 -> V_29 ) ;
V_2 = F_24 ( V_29 ) ;
V_29 -> V_218 = V_218 ;
V_2 -> V_7 = F_186 ( V_327 -> V_329 , V_338 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_293 = ( ( 1 << V_341 ) - 1 ) ;
F_187 ( V_22 , V_29 ) ;
V_235 = F_33 ( V_22 ) ;
if ( V_235 )
goto V_342;
V_235 = F_22 ( V_22 ) ;
if ( V_235 )
goto V_343;
if ( V_2 -> V_7 == NULL ) {
F_44 ( V_2 , V_135 , L_116 ) ;
V_235 = - V_145 ;
goto V_344;
}
V_235 = F_174 ( & V_2 -> V_4 , & V_22 -> V_29 ) ;
if ( V_235 && V_4 ) {
memcpy ( & V_2 -> V_4 , V_4 , sizeof( V_2 -> V_4 ) ) ;
V_235 = 0 ;
}
if ( V_235 ) {
F_44 ( V_2 , V_135 , L_117 ) ;
goto V_344;
}
V_2 -> V_11 = & V_345 ;
if ( V_2 -> V_4 . V_335 )
V_2 -> V_11 = & V_346 ;
F_188 ( & V_22 -> V_29 ) ;
F_189 ( & V_22 -> V_29 ) ;
V_235 = F_157 ( V_29 ) ;
if ( V_235 < 0 )
goto V_344;
F_125 ( V_29 ) ;
V_235 = F_73 ( V_22 , V_29 ) ;
if ( V_235 ) {
F_44 ( V_2 , V_135 , L_118 , V_235 ) ;
goto V_344;
}
V_235 = F_190 ( V_29 ) ;
if ( V_235 ) {
F_44 ( V_2 , V_135 , L_119 , V_235 ) ;
goto V_344;
} else {
F_54 ( V_2 , V_135 ,
L_120 , V_29 -> V_147 ) ;
}
F_111 ( & V_2 -> V_49 ) ;
if ( F_138 ( V_29 -> V_213 ) ) {
F_103 ( V_2 , V_29 -> V_213 ) ;
F_54 ( V_2 , V_135 ,
L_121 ) ;
} else if ( F_138 ( V_2 -> V_4 . V_334 ) ) {
memcpy ( V_29 -> V_213 , V_2 -> V_4 . V_334 , V_198 ) ;
F_54 ( V_2 , V_135 ,
L_122 ) ;
} else {
F_191 ( V_29 ) ;
if ( F_138 ( V_29 -> V_213 ) ) {
F_54 ( V_2 , V_135 ,
L_123 ) ;
} else {
F_192 ( V_29 ) ;
F_103 ( V_2 , V_29 -> V_213 ) ;
F_54 ( V_2 , V_135 ,
L_124 ) ;
}
}
F_112 ( & V_2 -> V_49 ) ;
F_116 ( V_29 , L_83 , V_29 -> V_213 ) ;
return 0 ;
V_344:
F_172 ( & V_22 -> V_29 ) ;
F_173 ( & V_22 -> V_29 ) ;
( void ) F_30 ( V_22 ) ;
V_343:
F_39 ( V_22 ) ;
V_342:
F_170 ( V_2 -> V_7 ) ;
F_171 ( V_29 ) ;
V_340:
F_168 ( V_327 -> V_329 , F_169 ( V_327 ) ) ;
V_339:
return V_235 ;
}
static int F_193 ( struct V_331 * V_29 )
{
struct V_23 * V_24 = F_194 ( V_29 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
F_14 ( V_2 , V_91 ,
V_347 | V_348 |
V_349 | V_350 ) ;
F_173 ( V_29 ) ;
F_195 ( V_29 ) ;
return 0 ;
}
static int F_196 ( struct V_331 * V_29 )
{
struct V_23 * V_24 = F_194 ( V_29 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
unsigned int V_316 = 100 ;
F_188 ( V_29 ) ;
F_197 ( V_29 ) ;
F_14 ( V_2 , V_41 , 0 ) ;
while ( ! ( F_7 ( V_2 , V_91 ) & V_317 ) && -- V_316 )
F_52 ( 1000 ) ;
return ( V_316 == 0 ) ? - V_37 : 0 ;
}
static int T_6 F_198 ( void )
{
F_199 () ;
return F_200 ( & V_351 ) ;
}
static void T_7 F_201 ( void )
{
F_202 ( & V_351 ) ;
}
