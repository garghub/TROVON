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
if ( V_25 )
F_27 ( V_24 , L_5 ,
V_25 ) ;
V_2 -> V_27 = F_35 ( & V_22 -> V_29 , NULL ) ;
if ( F_28 ( V_2 -> V_27 ) )
F_36 ( & V_22 -> V_29 , L_6 ,
F_37 ( V_2 -> V_27 ) ) ;
return V_25 ;
}
static void F_38 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = F_23 ( V_22 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
F_39 ( F_26 ( V_2 -> V_26 ) ,
V_2 -> V_26 ) ;
if ( ! F_28 ( V_2 -> V_27 ) ) {
F_40 ( V_2 -> V_27 ) ;
V_2 -> V_27 = NULL ;
}
}
static int F_41 ( struct V_1 * V_2 )
{
int V_30 ;
T_1 V_13 ;
F_42 ( V_2 ) ;
for ( V_30 = 0 ; V_30 < 40 ; V_30 ++ ) {
V_13 = F_7 ( V_2 , V_31 ) ;
if ( ! ( V_13 & V_32 ) )
return 0 ;
}
F_43 ( V_2 , V_33 , L_7
L_8 , V_13 ) ;
return - V_34 ;
}
static T_1 F_44 ( struct V_1 * V_2 , unsigned int V_35 )
{
unsigned int V_36 ;
F_42 ( V_2 ) ;
V_36 = F_7 ( V_2 , V_31 ) ;
if ( F_45 ( V_36 & V_32 ) ) {
F_43 ( V_2 , V_33 , L_9 ) ;
return 0xFFFFFFFF ;
}
F_14 ( V_2 , V_31 , ( ( V_35 & 0xFF ) |
V_32 | V_37 ) ) ;
V_36 = F_7 ( V_2 , V_38 ) ;
if ( F_46 ( F_41 ( V_2 ) == 0 ) )
return F_7 ( V_2 , V_39 ) ;
F_43 ( V_2 , V_33 , L_10 ) ;
return 0xFFFFFFFF ;
}
static void F_47 ( struct V_1 * V_2 ,
unsigned int V_35 , T_1 V_13 )
{
unsigned int V_36 ;
F_42 ( V_2 ) ;
V_36 = F_7 ( V_2 , V_31 ) ;
if ( F_45 ( V_36 & V_32 ) ) {
F_43 ( V_2 , V_33 ,
L_11 ) ;
return;
}
F_14 ( V_2 , V_39 , V_13 ) ;
F_14 ( V_2 , V_31 , ( ( V_35 & 0xFF ) |
V_32 ) ) ;
V_36 = F_7 ( V_2 , V_38 ) ;
if ( F_46 ( F_41 ( V_2 ) == 0 ) )
return;
F_43 ( V_2 , V_33 , L_12 ) ;
}
static int F_48 ( struct V_40 * V_41 , int V_42 , int V_43 )
{
struct V_1 * V_2 = (struct V_1 * ) V_41 -> V_44 ;
unsigned long V_5 ;
unsigned int V_45 ;
int V_30 , V_3 ;
F_8 ( & V_2 -> V_46 , V_5 ) ;
if ( F_45 ( F_44 ( V_2 , V_47 ) & V_48 ) ) {
F_43 ( V_2 , V_33 , L_13 ) ;
V_3 = - V_34 ;
goto V_19;
}
V_45 = ( ( V_42 & 0x1F ) << 11 ) | ( ( V_43 & 0x1F ) << 6 ) ;
F_47 ( V_2 , V_47 , V_45 ) ;
for ( V_30 = 0 ; V_30 < 100 ; V_30 ++ )
if ( ! ( F_44 ( V_2 , V_47 ) & V_48 ) ) {
V_3 = F_44 ( V_2 , V_49 ) ;
goto V_19;
}
F_43 ( V_2 , V_33 , L_14 ) ;
V_3 = - V_34 ;
V_19:
F_9 ( & V_2 -> V_46 , V_5 ) ;
return V_3 ;
}
static int F_49 ( struct V_40 * V_41 , int V_42 , int V_43 ,
T_2 V_13 )
{
struct V_1 * V_2 = (struct V_1 * ) V_41 -> V_44 ;
unsigned long V_5 ;
unsigned int V_45 ;
int V_30 , V_3 ;
F_8 ( & V_2 -> V_46 , V_5 ) ;
if ( F_45 ( F_44 ( V_2 , V_47 ) & V_48 ) ) {
F_43 ( V_2 , V_33 , L_15 ) ;
V_3 = - V_34 ;
goto V_19;
}
F_47 ( V_2 , V_49 , V_13 ) ;
V_45 = ( ( V_42 & 0x1F ) << 11 ) | ( ( V_43 & 0x1F ) << 6 ) |
V_50 ;
F_47 ( V_2 , V_47 , V_45 ) ;
for ( V_30 = 0 ; V_30 < 100 ; V_30 ++ )
if ( ! ( F_44 ( V_2 , V_47 ) & V_48 ) ) {
V_3 = 0 ;
goto V_19;
}
F_43 ( V_2 , V_33 , L_16 ) ;
V_3 = - V_34 ;
V_19:
F_9 ( & V_2 -> V_46 , V_5 ) ;
return V_3 ;
}
static void F_50 ( struct V_1 * V_2 )
{
unsigned int V_51 = F_7 ( V_2 , V_52 ) ;
V_51 &= ( ~ V_53 ) ;
V_51 |= V_54 ;
F_14 ( V_2 , V_52 , V_51 ) ;
F_51 ( 10 ) ;
V_51 |= V_55 ;
F_14 ( V_2 , V_52 , V_51 ) ;
V_51 &= ( ~ V_53 ) ;
V_51 |= V_56 ;
F_14 ( V_2 , V_52 , V_51 ) ;
F_51 ( 10 ) ;
V_51 |= V_57 ;
F_14 ( V_2 , V_52 , V_51 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
unsigned int V_51 = F_7 ( V_2 , V_52 ) ;
if ( V_2 -> V_4 . V_5 & V_58 ) {
F_53 ( V_2 , V_33 , L_17 ) ;
V_2 -> V_59 = 0 ;
} else if ( V_2 -> V_4 . V_5 & V_60 ) {
F_53 ( V_2 , V_33 , L_18 ) ;
F_50 ( V_2 ) ;
V_2 -> V_59 = 1 ;
} else if ( V_51 & V_61 ) {
F_53 ( V_2 , V_33 ,
L_19 ) ;
F_50 ( V_2 ) ;
V_2 -> V_59 = 1 ;
} else {
F_53 ( V_2 , V_33 ,
L_20 ) ;
V_2 -> V_59 = 0 ;
}
}
static unsigned int F_54 ( struct V_1 * V_2 )
{
unsigned int V_62 =
F_7 ( V_2 , V_63 ) & V_64 ;
if ( V_62 != 0 )
V_62 = F_7 ( V_2 , V_65 ) ;
return V_62 ;
}
static unsigned int F_55 ( struct V_1 * V_2 )
{
unsigned int V_62 =
F_7 ( V_2 , V_66 ) & V_67 ;
if ( V_62 != 0 )
V_62 = F_7 ( V_2 , V_68 ) ;
return V_62 ;
}
static int F_56 ( struct V_1 * V_2 )
{
unsigned int V_69 ;
T_1 V_70 ;
T_1 V_71 ;
T_3 V_72 ;
for ( V_69 = 0 ; V_69 < 10 ; V_69 ++ ) {
unsigned int V_73 ;
unsigned int V_74 ;
unsigned int V_75 ;
unsigned int V_76 ;
unsigned int V_30 ;
memset ( V_2 -> V_77 , 0 , V_78 ) ;
V_73 = ( T_1 ) ( ( T_3 ) V_2 -> V_79 & 0x03 ) << 16 ;
V_73 |= V_80 | V_81 ;
V_73 |= V_78 ;
V_74 = V_78 << 16 | V_78 ;
F_14 ( V_2 , V_18 , V_73 ) ;
F_14 ( V_2 , V_18 , V_74 ) ;
V_72 = ( T_3 ) V_2 -> V_79 & ( ~ 0x3 ) ;
V_70 = V_78 + 3 ;
V_70 += ( T_1 ) ( ( T_3 ) V_2 -> V_79 & 0x3 ) ;
V_70 >>= 2 ;
V_2 -> V_11 -> V_82 ( V_2 , ( unsigned int * ) V_72 , V_70 ) ;
V_30 = 60 ;
do {
F_51 ( 5 ) ;
V_75 = F_54 ( V_2 ) ;
} while ( ( V_30 -- ) && ( ! V_75 ) );
if ( ! V_75 ) {
F_43 ( V_2 , V_33 ,
L_21 ) ;
continue;
}
if ( V_75 & V_83 ) {
F_43 ( V_2 , V_33 ,
L_22 ) ;
continue;
}
V_30 = 60 ;
do {
F_51 ( 5 ) ;
V_75 = F_55 ( V_2 ) ;
} while ( ( V_30 -- ) && ( ! V_75 ) );
if ( ! V_75 ) {
F_43 ( V_2 , V_33 ,
L_23 ) ;
continue;
}
if ( V_75 & V_84 ) {
F_43 ( V_2 , V_33 ,
L_24 ) ;
continue;
}
V_76 = ( ( V_75 & 0x3FFF0000UL ) >> 16 ) ;
V_72 = ( T_3 ) V_2 -> V_77 ;
V_71 = V_76 + 3 ;
V_71 += ( T_1 ) ( ( T_3 ) V_2 -> V_77 & 0x3 ) ;
V_71 >>= 2 ;
V_2 -> V_11 -> V_85 ( V_2 , ( unsigned int * ) V_72 , V_71 ) ;
if ( V_76 != ( V_78 + 4 ) ) {
F_43 ( V_2 , V_33 , L_25
L_26 ,
V_76 ) ;
} else {
unsigned int V_86 ;
int V_87 = 0 ;
for ( V_86 = 0 ; V_86 < V_78 ; V_86 ++ ) {
if ( V_2 -> V_79 [ V_86 ]
!= V_2 -> V_77 [ V_86 ] ) {
V_87 = 1 ;
break;
}
}
if ( ! V_87 ) {
F_53 ( V_2 , V_33 , L_27
L_28 ) ;
return 0 ;
} else {
F_43 ( V_2 , V_33 , L_29
L_30 ) ;
}
}
}
return - V_34 ;
}
static int F_57 ( struct V_1 * V_2 )
{
unsigned int V_36 ;
unsigned int V_30 = 100000 ;
V_36 = F_7 ( V_2 , V_88 ) ;
F_14 ( V_2 , V_88 , V_36 | V_89 ) ;
do {
F_58 ( 1 ) ;
V_36 = F_7 ( V_2 , V_88 ) ;
} while ( ( V_30 -- ) && ( V_36 & V_89 ) );
if ( F_45 ( V_36 & V_89 ) ) {
F_43 ( V_2 , V_33 , L_31 ) ;
return - V_34 ;
}
F_58 ( 1 ) ;
return 0 ;
}
static int F_59 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_90 * V_91 = V_2 -> V_91 ;
int V_62 = - V_34 ;
unsigned int V_30 , V_13 ;
unsigned long V_5 ;
F_60 ( V_2 -> V_79 ) ;
for ( V_30 = 6 ; V_30 < 12 ; V_30 ++ )
V_2 -> V_79 [ V_30 ] = ( char ) V_30 ;
V_2 -> V_79 [ 12 ] = 0x00 ;
V_2 -> V_79 [ 13 ] = 0x00 ;
for ( V_30 = 14 ; V_30 < V_78 ; V_30 ++ )
V_2 -> V_79 [ V_30 ] = ( char ) V_30 ;
V_13 = F_7 ( V_2 , V_52 ) ;
V_13 &= V_92 ;
V_13 |= V_93 ;
F_14 ( V_2 , V_52 , V_13 ) ;
F_14 ( V_2 , V_94 , V_95 ) ;
F_14 ( V_2 , V_96 ,
( T_1 ) ( ( T_3 ) V_2 -> V_77 & 0x03 ) << 8 ) ;
for ( V_30 = 0 ; V_30 < 10 ; V_30 ++ ) {
F_49 ( V_91 -> V_97 . V_41 , V_91 -> V_97 . V_45 ,
V_98 , V_99 | V_100 ) ;
F_8 ( & V_2 -> V_46 , V_5 ) ;
F_47 ( V_2 , V_101 , V_102
| V_103 | V_104 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
if ( F_56 ( V_2 ) == 0 ) {
V_62 = 0 ;
break;
}
V_2 -> V_105 ++ ;
F_8 ( & V_2 -> V_46 , V_5 ) ;
F_47 ( V_2 , V_101 , 0 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
F_57 ( V_2 ) ;
}
F_8 ( & V_2 -> V_46 , V_5 ) ;
F_47 ( V_2 , V_101 , 0 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
F_49 ( V_91 -> V_97 . V_41 , V_91 -> V_97 . V_45 , V_98 , 0 ) ;
F_14 ( V_2 , V_94 , 0 ) ;
F_14 ( V_2 , V_96 , 0 ) ;
return V_62 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_90 * V_91 = V_2 -> V_91 ;
T_1 V_106 = F_7 ( V_2 , V_107 ) ;
T_1 V_108 ;
unsigned long V_5 ;
if ( V_91 -> V_109 == V_110 ) {
T_2 V_111 = F_62 ( V_91 , V_112 ) ;
T_2 V_113 = F_62 ( V_91 , V_114 ) ;
T_4 V_115 = F_63 ( V_111 , V_113 ) ;
if ( V_115 & V_116 )
V_108 = 0xFFFF0002 ;
else
V_108 = 0 ;
if ( V_115 & V_117 )
V_106 |= 0xF ;
else
V_106 &= ~ 0xF ;
F_53 ( V_2 , V_33 , L_32 ,
( V_115 & V_116 ? L_33 : L_34 ) ,
( V_115 & V_117 ? L_33 : L_34 ) ) ;
} else {
F_53 ( V_2 , V_33 , L_35 ) ;
V_108 = 0 ;
V_106 |= 0xF ;
}
F_8 ( & V_2 -> V_46 , V_5 ) ;
F_47 ( V_2 , V_118 , V_108 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
F_14 ( V_2 , V_107 , V_106 ) ;
}
static void F_64 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_90 * V_91 = V_2 -> V_91 ;
unsigned long V_5 ;
int V_119 ;
if ( V_91 -> V_109 != V_2 -> V_120 ) {
unsigned int V_121 ;
F_53 ( V_2 , V_33 , L_36 ) ;
F_8 ( & V_2 -> V_46 , V_5 ) ;
V_121 = F_44 ( V_2 , V_101 ) ;
if ( V_91 -> V_109 ) {
F_53 ( V_2 , V_33 ,
L_37 ) ;
V_121 |= V_102 ;
} else {
F_53 ( V_2 , V_33 ,
L_38 ) ;
V_121 &= ~ V_102 ;
}
F_47 ( V_2 , V_101 , V_121 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
F_61 ( V_2 ) ;
V_2 -> V_120 = V_91 -> V_109 ;
}
V_119 = F_65 ( V_29 ) ;
if ( V_119 != V_2 -> V_122 ) {
F_53 ( V_2 , V_33 , L_39 ) ;
if ( V_119 ) {
F_53 ( V_2 , V_33 , L_40 ) ;
if ( ( V_2 -> V_123 & V_124 ) &&
( ! V_2 -> V_59 ) ) {
V_2 -> V_125 = V_2 -> V_123 ;
F_14 ( V_2 , V_126 ,
V_2 -> V_125 ) ;
}
} else {
F_53 ( V_2 , V_33 , L_41 ) ;
V_2 -> V_125 = F_7 ( V_2 ,
V_126 ) ;
if ( ( V_2 -> V_125 & V_124 ) &&
( ! V_2 -> V_59 ) ) {
V_2 -> V_123 = V_2 -> V_125 ;
V_2 -> V_125 &= ~ V_124 ;
V_2 -> V_125 |= ( V_127
| V_128
| V_129 ) ;
F_14 ( V_2 , V_126 ,
V_2 -> V_125 ) ;
}
}
V_2 -> V_122 = V_119 ;
}
}
static int F_66 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_90 * V_130 = NULL ;
int V_25 ;
V_130 = F_67 ( V_2 -> V_40 ) ;
if ( ! V_130 ) {
F_27 ( V_29 , L_42 ) ;
return - V_131 ;
}
F_53 ( V_2 , V_132 , L_43 ,
V_130 -> V_97 . V_45 , V_130 -> V_133 ) ;
V_25 = F_68 ( V_29 , V_130 , & F_64 ,
V_2 -> V_4 . V_134 ) ;
if ( V_25 ) {
F_27 ( V_29 , L_44 ) ;
return V_25 ;
}
F_69 ( V_130 ) ;
V_130 -> V_135 &= ( V_136 | V_137 |
V_138 ) ;
V_130 -> V_139 = V_130 -> V_135 ;
V_2 -> V_91 = V_130 ;
V_2 -> V_120 = - 1 ;
V_2 -> V_122 = - 1 ;
#ifdef F_70
if ( F_59 ( V_29 ) < 0 ) {
F_43 ( V_2 , V_33 , L_45 ) ;
F_71 ( V_130 ) ;
return - V_131 ;
}
F_53 ( V_2 , V_33 , L_46 ) ;
#endif
F_53 ( V_2 , V_33 , L_47 ) ;
return 0 ;
}
static int F_72 ( struct V_21 * V_22 ,
struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
int V_140 = - V_141 ;
V_2 -> V_40 = F_73 () ;
if ( ! V_2 -> V_40 ) {
V_140 = - V_142 ;
goto V_143;
}
V_2 -> V_40 -> V_144 = V_145 ;
snprintf ( V_2 -> V_40 -> V_146 , V_147 , L_48 ,
V_22 -> V_144 , V_22 -> V_146 ) ;
V_2 -> V_40 -> V_44 = V_2 ;
V_2 -> V_40 -> V_148 = F_48 ;
V_2 -> V_40 -> V_149 = F_49 ;
V_2 -> V_40 -> V_150 = & V_22 -> V_29 ;
switch ( V_2 -> V_151 & 0xFFFF0000 ) {
case 0x01170000 :
case 0x01150000 :
case 0x117A0000 :
case 0x115A0000 :
F_52 ( V_2 ) ;
break;
default:
F_53 ( V_2 , V_33 , L_49
L_50 ) ;
V_2 -> V_59 = 0 ;
break;
}
if ( ! V_2 -> V_59 ) {
V_2 -> V_40 -> V_152 = ~ ( 1 << 1 ) ;
}
if ( F_74 ( V_2 -> V_40 ) ) {
F_43 ( V_2 , V_132 , L_51 ) ;
goto V_153;
}
if ( F_66 ( V_29 ) < 0 ) {
F_43 ( V_2 , V_132 , L_51 ) ;
goto V_154;
}
return 0 ;
V_154:
F_75 ( V_2 -> V_40 ) ;
V_153:
F_76 ( V_2 -> V_40 ) ;
V_143:
return V_140 ;
}
static unsigned int F_77 ( struct V_1 * V_2 )
{
return ( F_7 ( V_2 , V_63 )
& V_64 ) >> 16 ;
}
static void F_78 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_155 ;
while ( ( V_155 = F_54 ( V_2 ) ) != 0 ) {
if ( F_45 ( V_155 & 0x80000000 ) ) {
F_43 ( V_2 , V_33 , L_52 ) ;
} else {
if ( F_45 ( V_155 & V_83 ) ) {
V_29 -> V_156 . V_157 ++ ;
} else {
V_29 -> V_156 . V_158 ++ ;
V_29 -> V_156 . V_159 += ( V_155 >> 16 ) ;
}
if ( F_45 ( V_155 & V_160 ) ) {
V_29 -> V_156 . V_161 += 16 ;
V_29 -> V_156 . V_162 += 1 ;
} else {
V_29 -> V_156 . V_161 +=
( ( V_155 >> 3 ) & 0xF ) ;
}
if ( F_45 ( V_155 & V_163 ) )
V_29 -> V_156 . V_164 += 1 ;
if ( F_45 ( V_155 & V_165 ) ) {
V_29 -> V_156 . V_161 ++ ;
V_29 -> V_156 . V_162 ++ ;
}
}
}
}
static void
F_79 ( struct V_23 * V_29 , unsigned int V_166 )
{
int V_167 = 0 ;
if ( F_45 ( V_166 & V_84 ) ) {
V_29 -> V_156 . V_168 ++ ;
if ( F_45 ( V_166 & V_169 ) ) {
V_29 -> V_156 . V_170 ++ ;
V_167 = 1 ;
}
}
if ( F_46 ( ! V_167 ) ) {
if ( F_45 ( ( V_166 & V_171 ) &&
( V_166 & V_172 ) ) )
V_29 -> V_156 . V_173 ++ ;
if ( V_166 & V_174 )
V_29 -> V_156 . V_175 ++ ;
}
}
static void
F_80 ( struct V_1 * V_2 , unsigned int V_176 )
{
if ( F_46 ( V_176 >= 4 ) ) {
unsigned int V_177 = 500 ;
unsigned int V_13 ;
F_14 ( V_2 , V_178 , V_179 ) ;
do {
F_51 ( 1 ) ;
V_13 = F_7 ( V_2 , V_178 ) ;
} while ( ( V_13 & V_179 ) && -- V_177 );
if ( F_45 ( V_177 == 0 ) )
F_43 ( V_2 , V_33 , L_53
L_54 , V_13 ) ;
} else {
unsigned int V_36 ;
while ( V_176 -- )
V_36 = F_7 ( V_2 , V_20 ) ;
}
}
static int F_81 ( struct V_180 * V_181 , int V_182 )
{
struct V_1 * V_2 =
F_82 ( V_181 , struct V_1 , V_181 ) ;
struct V_23 * V_29 = V_2 -> V_29 ;
int V_183 = 0 ;
while ( V_183 < V_182 ) {
unsigned int V_76 ;
unsigned int V_176 ;
struct V_184 * V_185 ;
unsigned int V_166 = F_55 ( V_2 ) ;
if ( ! V_166 ) {
unsigned int V_36 ;
F_14 ( V_2 , V_186 , V_187 ) ;
F_83 ( V_181 ) ;
V_36 = F_7 ( V_2 , V_188 ) ;
V_36 |= V_189 ;
F_14 ( V_2 , V_188 , V_36 ) ;
break;
}
V_183 ++ ;
V_76 = ( ( V_166 & 0x3FFF0000 ) >> 16 ) ;
V_176 = ( V_76 + V_190 + 3 ) >> 2 ;
F_79 ( V_29 , V_166 ) ;
if ( F_45 ( V_166 & V_84 ) ) {
F_43 ( V_2 , V_191 ,
L_55 ) ;
F_80 ( V_2 , V_176 ) ;
V_29 -> V_156 . V_192 ++ ;
continue;
}
V_185 = F_84 ( V_29 , V_176 << 2 ) ;
if ( F_45 ( ! V_185 ) ) {
F_43 ( V_2 , V_191 ,
L_56 ) ;
F_80 ( V_2 , V_176 ) ;
V_29 -> V_156 . V_192 ++ ;
break;
}
V_2 -> V_11 -> V_85 ( V_2 ,
( unsigned int * ) V_185 -> V_9 , V_176 ) ;
F_85 ( V_185 , V_190 ) ;
F_86 ( V_185 , V_76 - 4 ) ;
V_185 -> V_193 = F_87 ( V_185 , V_29 ) ;
F_88 ( V_185 ) ;
F_89 ( V_185 ) ;
V_29 -> V_156 . V_194 ++ ;
V_29 -> V_156 . V_195 += ( V_76 - 4 ) ;
}
return V_183 ;
}
static unsigned int F_90 ( char V_45 [ V_196 ] )
{
return ( F_91 ( V_196 , V_45 ) >> 26 ) & 0x3f ;
}
static void F_92 ( struct V_1 * V_2 )
{
unsigned int V_121 ;
F_42 ( V_2 ) ;
V_121 = F_44 ( V_2 , V_101 ) ;
V_121 |= V_2 -> V_197 ;
V_121 &= ~ ( V_2 -> V_198 ) ;
F_47 ( V_2 , V_101 , V_121 ) ;
F_47 ( V_2 , V_199 , V_2 -> V_200 ) ;
F_47 ( V_2 , V_201 , V_2 -> V_202 ) ;
F_53 ( V_2 , V_33 , L_57 ,
V_121 , V_2 -> V_200 , V_2 -> V_202 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
unsigned int V_121 ;
F_94 ( & V_2 -> V_46 ) ;
if ( F_44 ( V_2 , V_101 ) & V_104 )
F_43 ( V_2 , V_203 , L_58 ) ;
F_92 ( V_2 ) ;
V_121 = F_44 ( V_2 , V_101 ) ;
V_121 |= V_104 ;
F_47 ( V_2 , V_101 , V_121 ) ;
V_2 -> V_204 = 0 ;
F_95 ( & V_2 -> V_46 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_205 = 0 ;
if ( ! V_2 -> V_91 )
return V_205 ;
V_205 = F_62 ( V_2 -> V_91 , V_98 ) ;
if ( V_205 < 0 ) {
F_43 ( V_2 , V_203 , L_59 ) ;
return V_205 ;
}
if ( V_205 & V_206 ) {
V_205 = F_97 ( V_2 -> V_91 , V_98 , V_205 & ~ V_206 ) ;
if ( V_205 < 0 ) {
F_43 ( V_2 , V_203 , L_60 ) ;
return V_205 ;
}
F_98 ( 1000 , 1500 ) ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_205 = 0 ;
if ( ! V_2 -> V_91 )
return V_205 ;
V_205 = F_62 ( V_2 -> V_91 , V_207 ) ;
if ( V_205 < 0 ) {
F_43 ( V_2 , V_203 , L_59 ) ;
return V_205 ;
}
if ( V_205 & V_208 ) {
V_205 = F_97 ( V_2 -> V_91 , V_207 ,
V_205 & ( ~ V_208 ) ) ;
if ( V_205 < 0 ) {
F_43 ( V_2 , V_203 , L_60 ) ;
return V_205 ;
}
F_100 ( 2 ) ;
}
return 0 ;
}
static int F_101 ( struct V_1 * V_2 )
{
int V_205 = 0 ;
if ( ! V_2 -> V_91 )
return V_205 ;
V_205 = F_62 ( V_2 -> V_91 , V_207 ) ;
if ( V_205 < 0 ) {
F_43 ( V_2 , V_203 , L_59 ) ;
return V_205 ;
}
if ( ! ( V_205 & V_208 ) ) {
V_205 = F_97 ( V_2 -> V_91 , V_207 ,
V_205 | V_208 ) ;
if ( V_205 < 0 ) {
F_43 ( V_2 , V_203 , L_60 ) ;
return V_205 ;
}
}
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
unsigned int V_177 ;
unsigned int V_36 ;
int V_25 ;
V_25 = F_96 ( V_2 ) ;
if ( V_25 ) {
F_43 ( V_2 , V_203 , L_61 ) ;
return V_25 ;
}
if ( V_2 -> V_209 == 4 ) {
V_25 = F_99 ( V_2 ) ;
if ( V_25 ) {
F_43 ( V_2 , V_203 , L_62 ) ;
return V_25 ;
}
}
F_14 ( V_2 , V_52 , V_210 ) ;
V_177 = 10 ;
do {
F_51 ( 10 ) ;
V_36 = F_7 ( V_2 , V_52 ) ;
} while ( ( -- V_177 ) && ( V_36 & V_210 ) );
if ( F_45 ( V_36 & V_210 ) ) {
F_43 ( V_2 , V_203 , L_63 ) ;
return - V_34 ;
}
if ( V_2 -> V_209 == 4 ) {
V_25 = F_101 ( V_2 ) ;
if ( V_25 ) {
F_43 ( V_2 , V_203 , L_62 ) ;
return V_25 ;
}
}
return 0 ;
}
static void
F_103 ( struct V_1 * V_2 , T_4 V_211 [ 6 ] )
{
T_1 V_212 = ( V_211 [ 5 ] << 8 ) | V_211 [ 4 ] ;
T_1 V_213 = ( V_211 [ 3 ] << 24 ) | ( V_211 [ 2 ] << 16 ) |
( V_211 [ 1 ] << 8 ) | V_211 [ 0 ] ;
F_42 ( V_2 ) ;
F_47 ( V_2 , V_214 , V_212 ) ;
F_47 ( V_2 , V_215 , V_213 ) ;
}
static void F_104 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_14 ( V_2 , V_188 , 0 ) ;
F_14 ( V_2 , V_186 , 0xFFFFFFFF ) ;
}
static int F_105 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_177 ;
unsigned int V_36 ;
unsigned int V_216 ;
if ( ! V_2 -> V_91 ) {
F_43 ( V_2 , V_33 , L_64 ) ;
return - V_217 ;
}
if ( F_102 ( V_2 ) ) {
F_43 ( V_2 , V_33 , L_65 ) ;
return - V_34 ;
}
F_14 ( V_2 , V_52 , 0x00050000 ) ;
F_14 ( V_2 , V_107 , 0x006E3740 ) ;
F_106 ( & V_2 -> V_46 ) ;
F_47 ( V_2 , V_218 , V_219 ) ;
F_107 ( & V_2 -> V_46 ) ;
V_177 = 50 ;
while ( ( F_7 ( V_2 , V_220 ) & V_221 ) &&
-- V_177 ) {
F_51 ( 10 ) ;
}
if ( F_45 ( V_177 == 0 ) )
F_43 ( V_2 , V_222 ,
L_66 ) ;
F_14 ( V_2 , V_126 , 0x70070000 ) ;
F_106 ( & V_2 -> V_46 ) ;
F_103 ( V_2 , V_29 -> V_211 ) ;
F_107 ( & V_2 -> V_46 ) ;
F_104 ( V_29 ) ;
V_216 = ( ( 10 << 24 ) | V_223 ) ;
if ( V_2 -> V_4 . V_224 ) {
F_53 ( V_2 , V_222 , L_67 ) ;
V_216 |= V_225 ;
} else {
F_53 ( V_2 , V_222 , L_68 ) ;
}
if ( V_2 -> V_4 . V_226 ) {
F_53 ( V_2 , V_222 , L_69 ) ;
V_216 |= V_227 ;
} else {
F_53 ( V_2 , V_222 , L_70 ) ;
}
F_14 ( V_2 , V_228 , V_216 ) ;
F_53 ( V_2 , V_222 , L_71 , V_29 -> V_229 ) ;
V_2 -> V_230 = 0 ;
F_108 () ;
V_36 = F_7 ( V_2 , V_188 ) ;
V_36 |= V_231 ;
F_14 ( V_2 , V_188 , V_36 ) ;
V_177 = 1000 ;
while ( V_177 -- ) {
if ( V_2 -> V_230 )
break;
F_58 ( 1 ) ;
}
if ( ! V_2 -> V_230 ) {
F_109 ( V_29 , L_72 ,
V_29 -> V_229 ) ;
return - V_131 ;
}
F_53 ( V_2 , V_222 , L_73 ,
V_29 -> V_229 ) ;
F_110 ( V_29 , L_74 ,
( unsigned long ) V_2 -> V_7 , V_29 -> V_229 ) ;
V_2 -> V_120 = - 1 ;
V_2 -> V_122 = - 1 ;
F_111 ( V_2 -> V_91 ) ;
V_36 = F_7 ( V_2 , V_52 ) ;
V_36 &= ( V_92 | 0x00000FFF ) ;
V_36 |= V_93 ;
F_14 ( V_2 , V_52 , V_36 ) ;
V_36 = F_7 ( V_2 , V_232 ) ;
V_36 |= V_233 ;
V_36 &= ~ ( V_234 ) ;
F_14 ( V_2 , V_232 , V_36 ) ;
F_14 ( V_2 , V_96 , ( V_190 << 8 ) ) ;
F_112 ( & V_2 -> V_181 ) ;
V_36 = F_7 ( V_2 , V_188 ) ;
V_36 |= ( V_235 | V_189 | V_236 ) ;
F_14 ( V_2 , V_188 , V_36 ) ;
F_106 ( & V_2 -> V_46 ) ;
V_36 = F_44 ( V_2 , V_101 ) ;
V_36 |= ( V_103 | V_104 | V_237 ) ;
F_47 ( V_2 , V_101 , V_36 ) ;
F_107 ( & V_2 -> V_46 ) ;
F_14 ( V_2 , V_94 , V_95 ) ;
F_113 ( V_29 ) ;
return 0 ;
}
static int F_114 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_36 ;
V_36 = F_7 ( V_2 , V_228 ) ;
V_36 &= ~ V_223 ;
F_14 ( V_2 , V_228 , V_36 ) ;
F_115 ( V_29 ) ;
F_116 ( & V_2 -> V_181 ) ;
V_29 -> V_156 . V_192 += F_7 ( V_2 , V_238 ) ;
F_78 ( V_29 ) ;
if ( V_2 -> V_91 )
F_117 ( V_2 -> V_91 ) ;
F_53 ( V_2 , V_239 , L_75 ) ;
return 0 ;
}
static int F_118 ( struct V_184 * V_185 , struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_240 ;
unsigned int V_241 ;
unsigned int V_242 ;
unsigned int V_36 ;
T_1 V_70 ;
T_3 V_72 ;
V_240 = F_7 ( V_2 , V_63 ) & V_243 ;
if ( F_45 ( V_240 < V_244 ) )
F_43 ( V_2 , V_245 ,
L_76 , V_240 ) ;
V_241 = ( T_1 ) ( ( T_3 ) V_185 -> V_9 & 0x03 ) << 16 ;
V_241 |= V_80 | V_81 ;
V_241 |= ( unsigned int ) V_185 -> V_246 ;
V_242 = ( ( unsigned int ) V_185 -> V_246 ) << 16 ;
V_242 |= ( unsigned int ) V_185 -> V_246 ;
F_14 ( V_2 , V_18 , V_241 ) ;
F_14 ( V_2 , V_18 , V_242 ) ;
V_72 = ( T_3 ) V_185 -> V_9 & ( ~ 0x3 ) ;
V_70 = ( T_1 ) V_185 -> V_246 + 3 ;
V_70 += ( T_1 ) ( ( T_3 ) V_185 -> V_9 & 0x3 ) ;
V_70 >>= 2 ;
V_2 -> V_11 -> V_82 ( V_2 , ( unsigned int * ) V_72 , V_70 ) ;
V_240 -= ( V_185 -> V_246 + 32 ) ;
F_119 ( V_185 ) ;
F_120 ( V_185 ) ;
if ( F_45 ( F_77 ( V_2 ) >= 30 ) )
F_78 ( V_29 ) ;
if ( V_240 < V_244 ) {
F_115 ( V_29 ) ;
V_36 = F_7 ( V_2 , V_232 ) ;
V_36 &= 0x00FFFFFF ;
V_36 |= 0x32000000 ;
F_14 ( V_2 , V_232 , V_36 ) ;
}
return V_247 ;
}
static struct V_248 * F_121 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_78 ( V_29 ) ;
V_29 -> V_156 . V_192 += F_7 ( V_2 , V_238 ) ;
return & V_29 -> V_156 ;
}
static void F_122 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned long V_5 ;
if ( V_29 -> V_5 & V_249 ) {
V_2 -> V_197 = V_250 ;
V_2 -> V_198 = ( V_251 | V_252 ) ;
V_2 -> V_200 = 0 ;
V_2 -> V_202 = 0 ;
} else if ( V_29 -> V_5 & V_253 ) {
V_2 -> V_197 = V_251 ;
V_2 -> V_198 = ( V_250 | V_252 ) ;
V_2 -> V_200 = 0 ;
V_2 -> V_202 = 0 ;
} else if ( ! F_123 ( V_29 ) ) {
unsigned int V_254 = 0 ;
unsigned int V_255 = 0 ;
struct V_256 * V_257 ;
V_2 -> V_197 = V_252 ;
V_2 -> V_198 = ( V_250 | V_251 ) ;
F_124 (ha, dev) {
unsigned int V_258 = F_90 ( V_257 -> V_45 ) ;
unsigned int V_259 = 0x01 << ( V_258 & 0x1F ) ;
if ( V_258 & 0x20 )
V_254 |= V_259 ;
else
V_255 |= V_259 ;
}
V_2 -> V_200 = V_254 ;
V_2 -> V_202 = V_255 ;
} else {
V_2 -> V_197 = 0 ;
V_2 -> V_198 =
( V_250 | V_251 | V_252 ) ;
V_2 -> V_200 = 0 ;
V_2 -> V_202 = 0 ;
}
F_8 ( & V_2 -> V_46 , V_5 ) ;
if ( V_2 -> V_209 <= 1 ) {
if ( ! V_2 -> V_204 ) {
unsigned int V_36 ;
F_53 ( V_2 , V_33 , L_77 ) ;
V_2 -> V_204 = 1 ;
V_36 = F_44 ( V_2 , V_101 ) ;
V_36 &= ~ ( V_104 ) ;
F_47 ( V_2 , V_101 , V_36 ) ;
} else {
}
} else {
F_92 ( V_2 ) ;
}
F_9 ( & V_2 -> V_46 , V_5 ) ;
}
static T_5 F_125 ( int V_229 , void * V_260 )
{
struct V_23 * V_29 = V_260 ;
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_1 V_261 = F_7 ( V_2 , V_186 ) ;
T_1 V_262 = F_7 ( V_2 , V_188 ) ;
int V_263 = V_264 ;
T_1 V_36 ;
if ( F_45 ( V_261 & V_262 & V_265 ) ) {
V_36 = F_7 ( V_2 , V_188 ) ;
V_36 &= ( ~ V_231 ) ;
F_14 ( V_2 , V_188 , V_36 ) ;
F_14 ( V_2 , V_186 , V_265 ) ;
V_2 -> V_230 = 1 ;
F_108 () ;
V_263 = V_266 ;
}
if ( F_45 ( V_261 & V_262 & V_267 ) ) {
F_53 ( V_2 , V_268 , L_78 ) ;
F_14 ( V_2 , V_186 , V_267 ) ;
if ( V_2 -> V_204 )
F_93 ( V_2 ) ;
V_263 = V_266 ;
}
if ( V_261 & V_262 & V_269 ) {
V_36 = F_7 ( V_2 , V_232 ) ;
V_36 |= V_233 ;
F_14 ( V_2 , V_232 , V_36 ) ;
F_14 ( V_2 , V_186 , V_269 ) ;
F_126 ( V_29 ) ;
V_263 = V_266 ;
}
if ( F_45 ( V_261 & V_262 & V_270 ) ) {
F_53 ( V_2 , V_268 , L_79 ) ;
F_14 ( V_2 , V_186 , V_270 ) ;
V_263 = V_266 ;
}
if ( F_46 ( V_261 & V_262 & V_187 ) ) {
if ( F_46 ( F_127 ( & V_2 -> V_181 ) ) ) {
V_36 = F_7 ( V_2 , V_188 ) ;
V_36 &= ( ~ V_189 ) ;
F_14 ( V_2 , V_188 , V_36 ) ;
F_128 ( & V_2 -> V_181 ) ;
} else {
F_43 ( V_2 , V_191 , L_80 ) ;
}
V_263 = V_266 ;
}
return V_263 ;
}
static void F_129 ( struct V_23 * V_29 )
{
F_130 ( V_29 -> V_229 ) ;
F_125 ( 0 , V_29 ) ;
F_131 ( V_29 -> V_229 ) ;
}
static int F_132 ( struct V_23 * V_29 , void * V_271 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_272 * V_45 = V_271 ;
if ( V_2 -> V_209 <= 1 && F_133 ( V_29 ) )
return - V_273 ;
if ( ! F_134 ( V_45 -> V_274 ) )
return - V_275 ;
memcpy ( V_29 -> V_211 , V_45 -> V_274 , V_196 ) ;
F_106 ( & V_2 -> V_46 ) ;
F_103 ( V_2 , V_29 -> V_211 ) ;
F_107 ( & V_2 -> V_46 ) ;
F_110 ( V_29 , L_81 , V_29 -> V_211 ) ;
return 0 ;
}
static int F_135 ( struct V_23 * V_29 , struct V_276 * V_277 , int V_278 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
if ( ! F_133 ( V_29 ) || ! V_2 -> V_91 )
return - V_279 ;
return F_136 ( V_2 -> V_91 , V_277 , V_278 ) ;
}
static int
F_137 ( struct V_23 * V_29 , struct V_280 * V_278 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
V_278 -> V_281 = 1 ;
V_278 -> V_282 = 1 ;
return F_138 ( V_2 -> V_91 , V_278 ) ;
}
static int
F_139 ( struct V_23 * V_29 , struct V_280 * V_278 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
return F_140 ( V_2 -> V_91 , V_278 ) ;
}
static void F_141 ( struct V_23 * V_29 ,
struct V_283 * V_284 )
{
F_142 ( V_284 -> V_285 , V_286 , sizeof( V_284 -> V_285 ) ) ;
F_142 ( V_284 -> V_287 , V_288 , sizeof( V_284 -> V_287 ) ) ;
F_142 ( V_284 -> V_289 , F_143 ( V_29 -> V_29 . V_150 ) ,
sizeof( V_284 -> V_289 ) ) ;
}
static int F_144 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
return F_145 ( V_2 -> V_91 ) ;
}
static T_1 F_146 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
return V_2 -> V_290 ;
}
static void F_147 ( struct V_23 * V_29 , T_1 V_291 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
V_2 -> V_290 = V_291 ;
}
static int F_148 ( struct V_23 * V_29 )
{
return ( ( ( V_292 - V_293 ) / 4 + 1 ) + ( V_294 - V_101 ) + 1 + 32 ) *
sizeof( T_1 ) ;
}
static void
F_149 ( struct V_23 * V_29 , struct V_295 * V_296 ,
void * V_15 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_90 * V_91 = V_2 -> V_91 ;
unsigned long V_5 ;
unsigned int V_30 ;
unsigned int V_86 = 0 ;
T_1 * V_9 = V_15 ;
V_296 -> V_287 = V_2 -> V_151 ;
for ( V_30 = V_293 ; V_30 <= V_292 ; V_30 += ( sizeof( T_1 ) ) )
V_9 [ V_86 ++ ] = F_7 ( V_2 , V_30 ) ;
for ( V_30 = V_101 ; V_30 <= V_294 ; V_30 ++ ) {
F_8 ( & V_2 -> V_46 , V_5 ) ;
V_9 [ V_86 ++ ] = F_44 ( V_2 , V_30 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
}
for ( V_30 = 0 ; V_30 <= 31 ; V_30 ++ )
V_9 [ V_86 ++ ] = F_48 ( V_91 -> V_97 . V_41 ,
V_91 -> V_97 . V_45 , V_30 ) ;
}
static void F_150 ( struct V_1 * V_2 )
{
unsigned int V_36 = F_7 ( V_2 , V_126 ) ;
V_36 &= ~ V_297 ;
F_14 ( V_2 , V_126 , V_36 ) ;
F_58 ( 1 ) ;
}
static int F_151 ( struct V_1 * V_2 , T_1 V_298 )
{
int V_177 = 100 ;
T_1 V_299 ;
F_53 ( V_2 , V_203 , L_82 , V_298 ) ;
if ( F_7 ( V_2 , V_220 ) & V_221 ) {
F_43 ( V_2 , V_203 , L_83 ) ;
return - V_273 ;
}
V_299 = V_298 | V_221 ;
F_14 ( V_2 , V_220 , V_299 ) ;
do {
F_58 ( 1 ) ;
V_299 = F_7 ( V_2 , V_220 ) ;
} while ( ( V_299 & V_221 ) && ( -- V_177 ) );
if ( ! V_177 ) {
F_53 ( V_2 , V_203 , L_84 ) ;
return - V_217 ;
}
if ( V_299 & V_300 ) {
F_53 ( V_2 , V_203 , L_85 ) ;
return - V_279 ;
}
return 0 ;
}
static int F_152 ( struct V_1 * V_2 ,
T_4 V_301 , T_4 * V_9 )
{
T_1 V_298 = V_302 | V_301 ;
int V_25 ;
F_53 ( V_2 , V_203 , L_86 , V_301 ) ;
V_25 = F_151 ( V_2 , V_298 ) ;
if ( ! V_25 )
V_9 [ V_301 ] = F_7 ( V_2 , V_292 ) ;
return V_25 ;
}
static int F_153 ( struct V_1 * V_2 ,
T_4 V_301 , T_4 V_9 )
{
T_1 V_298 = V_303 | V_301 ;
T_1 V_36 ;
int V_25 ;
F_53 ( V_2 , V_203 , L_87 , V_301 , V_9 ) ;
V_25 = F_151 ( V_2 , V_298 ) ;
if ( ! V_25 ) {
V_298 = V_304 | V_301 ;
F_14 ( V_2 , V_292 , ( T_1 ) V_9 ) ;
V_36 = F_7 ( V_2 , V_38 ) ;
V_25 = F_151 ( V_2 , V_298 ) ;
}
return V_25 ;
}
static int F_154 ( struct V_23 * V_29 )
{
return V_305 ;
}
static int F_155 ( struct V_23 * V_29 ,
struct V_306 * V_307 , T_4 * V_9 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_4 V_308 [ V_305 ] ;
int V_246 ;
int V_30 ;
F_150 ( V_2 ) ;
V_246 = F_156 ( V_307 -> V_246 , V_305 ) ;
for ( V_30 = 0 ; V_30 < V_246 ; V_30 ++ ) {
int V_25 = F_152 ( V_2 , V_30 , V_308 ) ;
if ( V_25 < 0 ) {
V_307 -> V_246 = 0 ;
return V_25 ;
}
}
memcpy ( V_9 , & V_308 [ V_307 -> V_35 ] , V_246 ) ;
V_307 -> V_246 = V_246 ;
return 0 ;
}
static int F_157 ( struct V_23 * V_29 ,
struct V_306 * V_307 , T_4 * V_9 )
{
int V_25 ;
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_150 ( V_2 ) ;
F_151 ( V_2 , V_309 ) ;
V_25 = F_153 ( V_2 , V_307 -> V_35 , * V_9 ) ;
F_151 ( V_2 , V_310 ) ;
V_307 -> V_246 = 1 ;
return V_25 ;
}
static void F_158 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_1 V_212 = F_44 ( V_2 , V_214 ) ;
T_1 V_213 = F_44 ( V_2 , V_215 ) ;
V_29 -> V_211 [ 0 ] = ( T_4 ) ( V_213 ) ;
V_29 -> V_211 [ 1 ] = ( T_4 ) ( V_213 >> 8 ) ;
V_29 -> V_211 [ 2 ] = ( T_4 ) ( V_213 >> 16 ) ;
V_29 -> V_211 [ 3 ] = ( T_4 ) ( V_213 >> 24 ) ;
V_29 -> V_211 [ 4 ] = ( T_4 ) ( V_212 ) ;
V_29 -> V_211 [ 5 ] = ( T_4 ) ( V_212 >> 8 ) ;
}
static int F_159 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_311 , V_259 ;
unsigned int V_312 = 100 ;
F_53 ( V_2 , V_132 , L_88 ) ;
F_53 ( V_2 , V_132 , L_89 ,
( unsigned long ) V_2 -> V_7 ) ;
F_53 ( V_2 , V_132 , L_90 , V_29 -> V_229 ) ;
F_53 ( V_2 , V_132 , L_91 ) ;
F_160 ( & V_2 -> V_10 ) ;
F_160 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_7 == NULL ) {
F_43 ( V_2 , V_132 , L_92 ) ;
return - V_131 ;
}
V_259 = V_313 | F_161 ( V_313 ) ;
while ( ! ( F_7 ( V_2 , V_88 ) & V_259 ) && -- V_312 )
F_51 ( 1000 ) ;
if ( V_312 == 0 ) {
F_27 ( V_29 , L_93 ) ;
return - V_131 ;
}
V_311 = F_7 ( V_2 , V_38 ) ;
F_53 ( V_2 , V_132 , L_94 , V_311 ) ;
if ( V_311 == 0x43218765 ) {
F_53 ( V_2 , V_132 , L_95
L_96 ) ;
F_14 ( V_2 , V_314 , 0xffffffff ) ;
V_311 = F_7 ( V_2 , V_38 ) ;
V_311 = F_7 ( V_2 , V_38 ) ;
}
if ( V_311 != 0x87654321 ) {
F_43 ( V_2 , V_203 , L_94 , V_311 ) ;
if ( ( ( V_311 >> 16 ) & 0xFFFF ) == ( V_311 & 0xFFFF ) ) {
F_43 ( V_2 , V_132 ,
L_97 ) ;
F_53 ( V_2 , V_132 ,
L_98
L_99 ) ;
}
return - V_131 ;
}
V_2 -> V_209 = 0 ;
V_2 -> V_151 = F_7 ( V_2 , V_293 ) ;
switch ( V_2 -> V_151 & 0xFFFF0000 ) {
case 0x01180000 :
case 0x01170000 :
case 0x01160000 :
case 0x01150000 :
case 0x218A0000 :
V_2 -> V_209 = V_2 -> V_151 & 0x0000FFFF ;
break;
case 0x118A0000 :
case 0x117A0000 :
case 0x116A0000 :
case 0x115A0000 :
V_2 -> V_209 = 3 ;
break;
case 0x92100000 :
case 0x92110000 :
case 0x92200000 :
case 0x92210000 :
V_2 -> V_209 = 4 ;
break;
default:
F_43 ( V_2 , V_132 , L_100 ,
V_2 -> V_151 ) ;
return - V_131 ;
}
F_53 ( V_2 , V_132 ,
L_101 ,
V_2 -> V_151 , V_2 -> V_209 ) ;
if ( V_2 -> V_209 == 0 )
F_43 ( V_2 , V_132 ,
L_102 ) ;
if ( V_2 -> V_4 . V_5 & V_315 ) {
F_106 ( & V_2 -> V_46 ) ;
F_158 ( V_29 ) ;
F_107 ( & V_2 -> V_46 ) ;
}
if ( F_57 ( V_2 ) || F_102 ( V_2 ) )
return - V_131 ;
V_29 -> V_5 |= V_316 ;
F_162 ( V_29 , & V_2 -> V_181 , F_81 , V_317 ) ;
V_29 -> V_318 = & V_319 ;
V_29 -> V_320 = & V_321 ;
return 0 ;
}
static int F_163 ( struct V_21 * V_22 )
{
struct V_23 * V_29 ;
struct V_1 * V_2 ;
struct V_322 * V_323 ;
V_29 = F_23 ( V_22 ) ;
F_164 ( ! V_29 ) ;
V_2 = F_24 ( V_29 ) ;
F_164 ( ! V_2 ) ;
F_164 ( ! V_2 -> V_7 ) ;
F_164 ( ! V_2 -> V_91 ) ;
F_53 ( V_2 , V_239 , L_103 ) ;
F_71 ( V_2 -> V_91 ) ;
V_2 -> V_91 = NULL ;
F_75 ( V_2 -> V_40 ) ;
F_76 ( V_2 -> V_40 ) ;
F_165 ( V_29 ) ;
F_166 ( V_29 -> V_229 , V_29 ) ;
V_323 = F_167 ( V_22 , V_324 ,
L_104 ) ;
if ( ! V_323 )
V_323 = F_168 ( V_22 , V_324 , 0 ) ;
F_169 ( V_323 -> V_325 , F_170 ( V_323 ) ) ;
F_171 ( V_2 -> V_7 ) ;
( void ) F_30 ( V_22 ) ;
F_38 ( V_22 ) ;
F_172 ( V_29 ) ;
F_173 ( & V_22 -> V_29 ) ;
F_174 ( & V_22 -> V_29 ) ;
return 0 ;
}
static int F_175 ( struct V_326 * V_4 ,
struct V_327 * V_29 )
{
int V_134 ;
T_1 V_328 = 0 ;
int V_140 ;
V_134 = F_176 ( V_29 ) ;
if ( V_134 < 0 )
V_134 = V_329 ;
V_4 -> V_134 = V_134 ;
F_177 ( V_29 , V_4 -> V_330 , V_196 ) ;
V_140 = F_178 ( V_29 , L_105 , & V_328 ) ;
if ( V_140 == - V_141 )
return V_140 ;
if ( ! V_140 && V_328 == 4 )
V_4 -> V_5 |= V_6 ;
else
V_4 -> V_5 |= V_8 ;
F_178 ( V_29 , L_106 , & V_4 -> V_331 ) ;
if ( F_179 ( V_29 , L_107 ) )
V_4 -> V_224 = V_332 ;
if ( F_179 ( V_29 , L_108 ) )
V_4 -> V_226 = V_333 ;
if ( F_179 ( V_29 , L_109 ) )
V_4 -> V_5 |= V_58 ;
if ( F_179 ( V_29 , L_110 ) )
V_4 -> V_5 |= V_60 ;
if ( F_179 ( V_29 , L_111 ) )
V_4 -> V_5 |= V_315 ;
return 0 ;
}
static int F_180 ( struct V_21 * V_22 )
{
struct V_23 * V_29 ;
struct V_1 * V_2 ;
struct V_326 * V_4 = F_181 ( & V_22 -> V_29 ) ;
struct V_322 * V_323 ;
unsigned int V_216 = 0 ;
int V_334 , V_229 , V_335 ;
int V_336 ;
V_323 = F_167 ( V_22 , V_324 ,
L_104 ) ;
if ( ! V_323 )
V_323 = F_168 ( V_22 , V_324 , 0 ) ;
if ( ! V_323 ) {
F_182 ( L_112 ) ;
V_336 = - V_131 ;
goto V_337;
}
V_334 = F_170 ( V_323 ) ;
V_229 = F_183 ( V_22 , 0 ) ;
if ( V_229 == - V_338 ) {
V_336 = - V_338 ;
goto V_337;
} else if ( V_229 <= 0 ) {
F_182 ( L_113 ) ;
V_336 = - V_131 ;
goto V_337;
}
if ( ! F_184 ( V_323 -> V_325 , V_334 , V_286 ) ) {
V_336 = - V_273 ;
goto V_337;
}
V_29 = F_185 ( sizeof( struct V_1 ) ) ;
if ( ! V_29 ) {
V_336 = - V_142 ;
goto V_339;
}
F_186 ( V_29 , & V_22 -> V_29 ) ;
V_2 = F_24 ( V_29 ) ;
V_29 -> V_229 = V_229 ;
V_335 = F_187 ( V_229 ) ;
V_2 -> V_7 = F_188 ( V_323 -> V_325 , V_334 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_290 = ( ( 1 << V_340 ) - 1 ) ;
F_189 ( V_22 , V_29 ) ;
V_336 = F_33 ( V_22 ) ;
if ( V_336 )
goto V_341;
V_336 = F_22 ( V_22 ) ;
if ( V_336 )
goto V_342;
if ( V_2 -> V_7 == NULL ) {
F_43 ( V_2 , V_132 , L_114 ) ;
V_336 = - V_142 ;
goto V_343;
}
V_336 = F_175 ( & V_2 -> V_4 , & V_22 -> V_29 ) ;
if ( V_336 && V_4 ) {
memcpy ( & V_2 -> V_4 , V_4 , sizeof( V_2 -> V_4 ) ) ;
V_336 = 0 ;
}
if ( V_336 ) {
F_43 ( V_2 , V_132 , L_115 ) ;
goto V_343;
}
V_2 -> V_11 = & V_344 ;
if ( V_2 -> V_4 . V_331 )
V_2 -> V_11 = & V_345 ;
F_190 ( & V_22 -> V_29 ) ;
F_191 ( & V_22 -> V_29 ) ;
V_336 = F_159 ( V_29 ) ;
if ( V_336 < 0 )
goto V_343;
if ( V_2 -> V_4 . V_224 == V_332 )
V_216 |= V_225 ;
if ( V_2 -> V_4 . V_226 == V_333 )
V_216 |= V_227 ;
F_14 ( V_2 , V_228 , V_216 ) ;
F_104 ( V_29 ) ;
V_336 = F_192 ( V_29 -> V_229 , F_125 ,
V_335 | V_346 , V_29 -> V_144 , V_29 ) ;
if ( V_336 ) {
F_43 ( V_2 , V_132 ,
L_116 , V_29 -> V_229 ) ;
goto V_343;
}
F_193 ( V_29 ) ;
V_336 = F_194 ( V_29 ) ;
if ( V_336 ) {
F_43 ( V_2 , V_132 , L_117 , V_336 ) ;
goto V_347;
} else {
F_53 ( V_2 , V_132 ,
L_118 , V_29 -> V_144 ) ;
}
V_336 = F_72 ( V_22 , V_29 ) ;
if ( V_336 ) {
F_43 ( V_2 , V_132 , L_119 , V_336 ) ;
goto V_348;
}
F_106 ( & V_2 -> V_46 ) ;
if ( F_134 ( V_29 -> V_211 ) ) {
F_103 ( V_2 , V_29 -> V_211 ) ;
F_53 ( V_2 , V_132 ,
L_120 ) ;
} else if ( F_134 ( V_2 -> V_4 . V_330 ) ) {
memcpy ( V_29 -> V_211 , V_2 -> V_4 . V_330 , V_196 ) ;
F_53 ( V_2 , V_132 ,
L_121 ) ;
} else {
F_195 ( V_29 ) ;
if ( F_134 ( V_29 -> V_211 ) ) {
F_53 ( V_2 , V_132 ,
L_122 ) ;
} else {
F_196 ( V_29 ) ;
F_103 ( V_2 , V_29 -> V_211 ) ;
F_53 ( V_2 , V_132 ,
L_123 ) ;
}
}
F_107 ( & V_2 -> V_46 ) ;
F_110 ( V_29 , L_81 , V_29 -> V_211 ) ;
return 0 ;
V_348:
F_165 ( V_29 ) ;
V_347:
F_166 ( V_29 -> V_229 , V_29 ) ;
V_343:
F_173 ( & V_22 -> V_29 ) ;
F_174 ( & V_22 -> V_29 ) ;
( void ) F_30 ( V_22 ) ;
V_342:
F_38 ( V_22 ) ;
V_341:
F_171 ( V_2 -> V_7 ) ;
F_172 ( V_29 ) ;
V_339:
F_169 ( V_323 -> V_325 , F_170 ( V_323 ) ) ;
V_337:
return V_336 ;
}
static int F_197 ( struct V_327 * V_29 )
{
struct V_23 * V_24 = F_198 ( V_29 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
F_14 ( V_2 , V_88 ,
V_349 | V_350 |
V_351 | V_352 ) ;
return 0 ;
}
static int F_199 ( struct V_327 * V_29 )
{
struct V_23 * V_24 = F_198 ( V_29 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
unsigned int V_312 = 100 ;
F_14 ( V_2 , V_38 , 0 ) ;
while ( ! ( F_7 ( V_2 , V_88 ) & V_313 ) && -- V_312 )
F_51 ( 1000 ) ;
return ( V_312 == 0 ) ? - V_34 : 0 ;
}
static int T_6 F_200 ( void )
{
F_201 () ;
return F_202 ( & V_353 ) ;
}
static void T_7 F_203 ( void )
{
F_204 ( & V_353 ) ;
}
