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
F_36 ( V_24 , L_6 , F_37 ( V_2 -> V_27 ) ) ;
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
struct V_88 * V_89 = V_2 -> V_89 ;
unsigned int V_36 ;
unsigned int V_30 = 100000 ;
F_58 ( ! V_89 ) ;
F_58 ( ! V_89 -> V_41 ) ;
F_53 ( V_2 , V_33 , L_31 ) ;
F_49 ( V_89 -> V_41 , V_89 -> V_45 , V_90 , V_91 ) ;
do {
F_59 ( 1 ) ;
V_36 = F_48 ( V_89 -> V_41 , V_89 -> V_45 ,
V_90 ) ;
} while ( ( V_30 -- ) && ( V_36 & V_91 ) );
if ( V_36 & V_91 ) {
F_43 ( V_2 , V_33 , L_32 ) ;
return - V_34 ;
}
F_59 ( 1 ) ;
return 0 ;
}
static int F_60 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_88 * V_89 = V_2 -> V_89 ;
int V_62 = - V_34 ;
unsigned int V_30 , V_13 ;
unsigned long V_5 ;
memset ( V_2 -> V_79 , 0xff , V_92 ) ;
for ( V_30 = 6 ; V_30 < 12 ; V_30 ++ )
V_2 -> V_79 [ V_30 ] = ( char ) V_30 ;
V_2 -> V_79 [ 12 ] = 0x00 ;
V_2 -> V_79 [ 13 ] = 0x00 ;
for ( V_30 = 14 ; V_30 < V_78 ; V_30 ++ )
V_2 -> V_79 [ V_30 ] = ( char ) V_30 ;
V_13 = F_7 ( V_2 , V_52 ) ;
V_13 &= V_93 ;
V_13 |= V_94 ;
F_14 ( V_2 , V_52 , V_13 ) ;
F_14 ( V_2 , V_95 , V_96 ) ;
F_14 ( V_2 , V_97 ,
( T_1 ) ( ( T_3 ) V_2 -> V_77 & 0x03 ) << 8 ) ;
for ( V_30 = 0 ; V_30 < 10 ; V_30 ++ ) {
F_49 ( V_89 -> V_41 , V_89 -> V_45 , V_90 ,
V_98 | V_99 ) ;
F_8 ( & V_2 -> V_46 , V_5 ) ;
F_47 ( V_2 , V_100 , V_101
| V_102 | V_103 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
if ( F_56 ( V_2 ) == 0 ) {
V_62 = 0 ;
break;
}
V_2 -> V_104 ++ ;
F_8 ( & V_2 -> V_46 , V_5 ) ;
F_47 ( V_2 , V_100 , 0 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
F_57 ( V_2 ) ;
}
F_8 ( & V_2 -> V_46 , V_5 ) ;
F_47 ( V_2 , V_100 , 0 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
F_49 ( V_89 -> V_41 , V_89 -> V_45 , V_90 , 0 ) ;
F_14 ( V_2 , V_95 , 0 ) ;
F_14 ( V_2 , V_97 , 0 ) ;
return V_62 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = V_2 -> V_89 ;
T_1 V_105 = F_7 ( V_2 , V_106 ) ;
T_1 V_107 ;
unsigned long V_5 ;
if ( V_89 -> V_108 == V_109 ) {
T_2 V_110 = F_62 ( V_89 , V_111 ) ;
T_2 V_112 = F_62 ( V_89 , V_113 ) ;
T_4 V_114 = F_63 ( V_110 , V_112 ) ;
if ( V_114 & V_115 )
V_107 = 0xFFFF0002 ;
else
V_107 = 0 ;
if ( V_114 & V_116 )
V_105 |= 0xF ;
else
V_105 &= ~ 0xF ;
F_53 ( V_2 , V_33 , L_33 ,
( V_114 & V_115 ? L_34 : L_35 ) ,
( V_114 & V_116 ? L_34 : L_35 ) ) ;
} else {
F_53 ( V_2 , V_33 , L_36 ) ;
V_107 = 0 ;
V_105 |= 0xF ;
}
F_8 ( & V_2 -> V_46 , V_5 ) ;
F_47 ( V_2 , V_117 , V_107 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
F_14 ( V_2 , V_106 , V_105 ) ;
}
static void F_64 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_88 * V_89 = V_2 -> V_89 ;
unsigned long V_5 ;
int V_118 ;
if ( V_89 -> V_108 != V_2 -> V_119 ) {
unsigned int V_120 ;
F_53 ( V_2 , V_33 , L_37 ) ;
F_8 ( & V_2 -> V_46 , V_5 ) ;
V_120 = F_44 ( V_2 , V_100 ) ;
if ( V_89 -> V_108 ) {
F_53 ( V_2 , V_33 ,
L_38 ) ;
V_120 |= V_101 ;
} else {
F_53 ( V_2 , V_33 ,
L_39 ) ;
V_120 &= ~ V_101 ;
}
F_47 ( V_2 , V_100 , V_120 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
F_61 ( V_2 ) ;
V_2 -> V_119 = V_89 -> V_108 ;
}
V_118 = F_65 ( V_29 ) ;
if ( V_118 != V_2 -> V_121 ) {
F_53 ( V_2 , V_33 , L_40 ) ;
if ( V_118 ) {
F_53 ( V_2 , V_33 , L_41 ) ;
if ( ( V_2 -> V_122 & V_123 ) &&
( ! V_2 -> V_59 ) ) {
V_2 -> V_124 = V_2 -> V_122 ;
F_14 ( V_2 , V_125 ,
V_2 -> V_124 ) ;
}
} else {
F_53 ( V_2 , V_33 , L_42 ) ;
V_2 -> V_124 = F_7 ( V_2 ,
V_125 ) ;
if ( ( V_2 -> V_124 & V_123 ) &&
( ! V_2 -> V_59 ) ) {
V_2 -> V_122 = V_2 -> V_124 ;
V_2 -> V_124 &= ~ V_123 ;
V_2 -> V_124 |= ( V_126
| V_127
| V_128 ) ;
F_14 ( V_2 , V_125 ,
V_2 -> V_124 ) ;
}
}
V_2 -> V_121 = V_118 ;
}
}
static int F_66 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_88 * V_129 = NULL ;
int V_25 ;
V_129 = F_67 ( V_2 -> V_40 ) ;
if ( ! V_129 ) {
F_27 ( V_29 , L_43 ) ;
return - V_130 ;
}
F_53 ( V_2 , V_131 , L_44 ,
V_129 -> V_45 , V_129 -> V_132 ) ;
V_25 = F_68 ( V_29 , V_129 , & F_64 ,
V_2 -> V_4 . V_133 ) ;
if ( V_25 ) {
F_27 ( V_29 , L_45 ) ;
return V_25 ;
}
F_69 ( V_29 ,
L_46 ,
V_129 -> V_134 -> V_135 , F_70 ( & V_129 -> V_29 ) , V_129 -> V_136 ) ;
V_129 -> V_137 &= ( V_138 | V_139 |
V_140 ) ;
V_129 -> V_141 = V_129 -> V_137 ;
V_2 -> V_89 = V_129 ;
V_2 -> V_119 = - 1 ;
V_2 -> V_121 = - 1 ;
#ifdef F_71
if ( F_60 ( V_29 ) < 0 ) {
F_43 ( V_2 , V_33 , L_47 ) ;
return - V_130 ;
}
F_53 ( V_2 , V_33 , L_48 ) ;
#endif
F_53 ( V_2 , V_33 , L_49 ) ;
return 0 ;
}
static int F_72 ( struct V_21 * V_22 ,
struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
int V_142 = - V_143 , V_30 ;
V_2 -> V_40 = F_73 () ;
if ( ! V_2 -> V_40 ) {
V_142 = - V_144 ;
goto V_145;
}
V_2 -> V_40 -> V_135 = V_146 ;
snprintf ( V_2 -> V_40 -> V_147 , V_148 , L_50 ,
V_22 -> V_135 , V_22 -> V_147 ) ;
V_2 -> V_40 -> V_44 = V_2 ;
V_2 -> V_40 -> V_149 = F_48 ;
V_2 -> V_40 -> V_150 = F_49 ;
V_2 -> V_40 -> V_136 = V_2 -> V_151 ;
for ( V_30 = 0 ; V_30 < V_152 ; ++ V_30 )
V_2 -> V_40 -> V_136 [ V_30 ] = V_153 ;
V_2 -> V_40 -> V_154 = & V_22 -> V_29 ;
switch ( V_2 -> V_155 & 0xFFFF0000 ) {
case 0x01170000 :
case 0x01150000 :
case 0x117A0000 :
case 0x115A0000 :
F_52 ( V_2 ) ;
break;
default:
F_53 ( V_2 , V_33 , L_51
L_52 ) ;
V_2 -> V_59 = 0 ;
break;
}
if ( ! V_2 -> V_59 ) {
V_2 -> V_40 -> V_156 = ~ ( 1 << 1 ) ;
}
if ( F_74 ( V_2 -> V_40 ) ) {
F_43 ( V_2 , V_131 , L_53 ) ;
goto V_157;
}
if ( F_66 ( V_29 ) < 0 ) {
F_43 ( V_2 , V_131 , L_53 ) ;
goto V_158;
}
return 0 ;
V_158:
F_75 ( V_2 -> V_40 ) ;
V_157:
F_76 ( V_2 -> V_40 ) ;
V_145:
return V_142 ;
}
static unsigned int F_77 ( struct V_1 * V_2 )
{
return ( F_7 ( V_2 , V_63 )
& V_64 ) >> 16 ;
}
static void F_78 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_159 ;
while ( ( V_159 = F_54 ( V_2 ) ) != 0 ) {
if ( F_45 ( V_159 & 0x80000000 ) ) {
F_43 ( V_2 , V_33 , L_54 ) ;
} else {
if ( F_45 ( V_159 & V_83 ) ) {
V_29 -> V_160 . V_161 ++ ;
} else {
V_29 -> V_160 . V_162 ++ ;
V_29 -> V_160 . V_163 += ( V_159 >> 16 ) ;
}
if ( F_45 ( V_159 & V_164 ) ) {
V_29 -> V_160 . V_165 += 16 ;
V_29 -> V_160 . V_166 += 1 ;
} else {
V_29 -> V_160 . V_165 +=
( ( V_159 >> 3 ) & 0xF ) ;
}
if ( F_45 ( V_159 & V_167 ) )
V_29 -> V_160 . V_168 += 1 ;
if ( F_45 ( V_159 & V_169 ) ) {
V_29 -> V_160 . V_165 ++ ;
V_29 -> V_160 . V_166 ++ ;
}
}
}
}
static void
F_79 ( struct V_23 * V_29 , unsigned int V_170 )
{
int V_171 = 0 ;
if ( F_45 ( V_170 & V_84 ) ) {
V_29 -> V_160 . V_172 ++ ;
if ( F_45 ( V_170 & V_173 ) ) {
V_29 -> V_160 . V_174 ++ ;
V_171 = 1 ;
}
}
if ( F_46 ( ! V_171 ) ) {
if ( F_45 ( ( V_170 & V_175 ) &&
( V_170 & V_176 ) ) )
V_29 -> V_160 . V_177 ++ ;
if ( V_170 & V_178 )
V_29 -> V_160 . V_179 ++ ;
}
}
static void
F_80 ( struct V_1 * V_2 , unsigned int V_180 )
{
if ( F_46 ( V_180 >= 4 ) ) {
unsigned int V_181 = 500 ;
unsigned int V_13 ;
F_14 ( V_2 , V_182 , V_183 ) ;
do {
F_51 ( 1 ) ;
V_13 = F_7 ( V_2 , V_182 ) ;
} while ( ( V_13 & V_183 ) && -- V_181 );
if ( F_45 ( V_181 == 0 ) )
F_43 ( V_2 , V_33 , L_55
L_56 , V_13 ) ;
} else {
unsigned int V_36 ;
while ( V_180 -- )
V_36 = F_7 ( V_2 , V_20 ) ;
}
}
static int F_81 ( struct V_184 * V_185 , int V_186 )
{
struct V_1 * V_2 =
F_82 ( V_185 , struct V_1 , V_185 ) ;
struct V_23 * V_29 = V_2 -> V_29 ;
int V_187 = 0 ;
while ( V_187 < V_186 ) {
unsigned int V_76 ;
unsigned int V_180 ;
struct V_188 * V_189 ;
unsigned int V_170 = F_55 ( V_2 ) ;
if ( ! V_170 ) {
unsigned int V_36 ;
F_14 ( V_2 , V_190 , V_191 ) ;
F_83 ( V_185 ) ;
V_36 = F_7 ( V_2 , V_192 ) ;
V_36 |= V_193 ;
F_14 ( V_2 , V_192 , V_36 ) ;
break;
}
V_187 ++ ;
V_76 = ( ( V_170 & 0x3FFF0000 ) >> 16 ) ;
V_180 = ( V_76 + V_194 + 3 ) >> 2 ;
F_79 ( V_29 , V_170 ) ;
if ( F_45 ( V_170 & V_84 ) ) {
F_43 ( V_2 , V_195 ,
L_57 ) ;
F_80 ( V_2 , V_180 ) ;
V_29 -> V_160 . V_196 ++ ;
continue;
}
V_189 = F_84 ( V_29 , V_180 << 2 ) ;
if ( F_45 ( ! V_189 ) ) {
F_43 ( V_2 , V_195 ,
L_58 ) ;
F_80 ( V_2 , V_180 ) ;
V_29 -> V_160 . V_196 ++ ;
break;
}
V_2 -> V_11 -> V_85 ( V_2 ,
( unsigned int * ) V_189 -> V_9 , V_180 ) ;
F_85 ( V_189 , V_194 ) ;
F_86 ( V_189 , V_76 - 4 ) ;
V_189 -> V_197 = F_87 ( V_189 , V_29 ) ;
F_88 ( V_189 ) ;
F_89 ( V_189 ) ;
V_29 -> V_160 . V_198 ++ ;
V_29 -> V_160 . V_199 += ( V_76 - 4 ) ;
}
return V_187 ;
}
static unsigned int F_90 ( char V_45 [ V_92 ] )
{
return ( F_91 ( V_92 , V_45 ) >> 26 ) & 0x3f ;
}
static void F_92 ( struct V_1 * V_2 )
{
unsigned int V_120 ;
F_42 ( V_2 ) ;
V_120 = F_44 ( V_2 , V_100 ) ;
V_120 |= V_2 -> V_200 ;
V_120 &= ~ ( V_2 -> V_201 ) ;
F_47 ( V_2 , V_100 , V_120 ) ;
F_47 ( V_2 , V_202 , V_2 -> V_203 ) ;
F_47 ( V_2 , V_204 , V_2 -> V_205 ) ;
F_53 ( V_2 , V_33 , L_59 ,
V_120 , V_2 -> V_203 , V_2 -> V_205 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
unsigned int V_120 ;
F_94 ( & V_2 -> V_46 ) ;
if ( F_44 ( V_2 , V_100 ) & V_103 )
F_43 ( V_2 , V_134 , L_60 ) ;
F_92 ( V_2 ) ;
V_120 = F_44 ( V_2 , V_100 ) ;
V_120 |= V_103 ;
F_47 ( V_2 , V_100 , V_120 ) ;
V_2 -> V_206 = 0 ;
F_95 ( & V_2 -> V_46 ) ;
}
static int F_96 ( struct V_1 * V_2 )
{
int V_207 = 0 ;
if ( ! V_2 -> V_89 )
return V_207 ;
V_207 = F_62 ( V_2 -> V_89 , V_208 ) ;
if ( V_207 < 0 ) {
F_43 ( V_2 , V_134 , L_61 ) ;
return V_207 ;
}
if ( ( V_207 & V_209 ) &&
! ( V_207 & V_210 ) ) {
V_207 = F_97 ( V_2 -> V_89 , V_208 ,
V_207 & ( ~ V_209 ) ) ;
if ( V_207 < 0 ) {
F_43 ( V_2 , V_134 , L_62 ) ;
return V_207 ;
}
F_98 ( 1 ) ;
}
return 0 ;
}
static int F_99 ( struct V_1 * V_2 )
{
int V_207 = 0 ;
if ( ! V_2 -> V_89 )
return V_207 ;
V_207 = F_62 ( V_2 -> V_89 , V_208 ) ;
if ( V_207 < 0 ) {
F_43 ( V_2 , V_134 , L_61 ) ;
return V_207 ;
}
if ( ! ( V_207 & V_209 ) ) {
F_98 ( 100 ) ;
V_207 = F_97 ( V_2 -> V_89 , V_208 ,
V_207 | V_209 ) ;
if ( V_207 < 0 ) {
F_43 ( V_2 , V_134 , L_62 ) ;
return V_207 ;
}
F_98 ( 1 ) ;
}
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
unsigned int V_181 ;
unsigned int V_36 ;
int V_25 ;
if ( V_2 -> V_211 == 4 ) {
V_25 = F_96 ( V_2 ) ;
if ( V_25 ) {
F_43 ( V_2 , V_134 , L_63 ) ;
return V_25 ;
}
}
F_14 ( V_2 , V_52 , V_212 ) ;
V_181 = 10 ;
do {
F_51 ( 10 ) ;
V_36 = F_7 ( V_2 , V_52 ) ;
} while ( ( -- V_181 ) && ( V_36 & V_212 ) );
if ( F_45 ( V_36 & V_212 ) ) {
F_43 ( V_2 , V_134 , L_64 ) ;
return - V_34 ;
}
if ( V_2 -> V_211 == 4 ) {
V_25 = F_99 ( V_2 ) ;
if ( V_25 ) {
F_43 ( V_2 , V_134 , L_63 ) ;
return V_25 ;
}
}
return 0 ;
}
static void
F_101 ( struct V_1 * V_2 , T_4 V_213 [ 6 ] )
{
T_1 V_214 = ( V_213 [ 5 ] << 8 ) | V_213 [ 4 ] ;
T_1 V_215 = ( V_213 [ 3 ] << 24 ) | ( V_213 [ 2 ] << 16 ) |
( V_213 [ 1 ] << 8 ) | V_213 [ 0 ] ;
F_42 ( V_2 ) ;
F_47 ( V_2 , V_216 , V_214 ) ;
F_47 ( V_2 , V_217 , V_215 ) ;
}
static void F_102 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_14 ( V_2 , V_192 , 0 ) ;
F_14 ( V_2 , V_190 , 0xFFFFFFFF ) ;
}
static int F_103 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_181 ;
unsigned int V_36 ;
unsigned int V_218 ;
if ( ! V_2 -> V_89 ) {
F_43 ( V_2 , V_33 , L_65 ) ;
return - V_219 ;
}
if ( F_100 ( V_2 ) ) {
F_43 ( V_2 , V_33 , L_66 ) ;
return - V_34 ;
}
F_14 ( V_2 , V_52 , 0x00050000 ) ;
F_14 ( V_2 , V_106 , 0x006E3740 ) ;
F_104 ( & V_2 -> V_46 ) ;
F_47 ( V_2 , V_220 , V_221 ) ;
F_105 ( & V_2 -> V_46 ) ;
V_181 = 50 ;
while ( ( F_7 ( V_2 , V_222 ) & V_223 ) &&
-- V_181 ) {
F_51 ( 10 ) ;
}
if ( F_45 ( V_181 == 0 ) )
F_43 ( V_2 , V_224 ,
L_67 ) ;
F_14 ( V_2 , V_125 , 0x70070000 ) ;
F_104 ( & V_2 -> V_46 ) ;
F_101 ( V_2 , V_29 -> V_213 ) ;
F_105 ( & V_2 -> V_46 ) ;
F_102 ( V_29 ) ;
V_218 = ( ( 10 << 24 ) | V_225 ) ;
if ( V_2 -> V_4 . V_226 ) {
F_53 ( V_2 , V_224 , L_68 ) ;
V_218 |= V_227 ;
} else {
F_53 ( V_2 , V_224 , L_69 ) ;
}
if ( V_2 -> V_4 . V_228 ) {
F_53 ( V_2 , V_224 , L_70 ) ;
V_218 |= V_229 ;
} else {
F_53 ( V_2 , V_224 , L_71 ) ;
}
F_14 ( V_2 , V_230 , V_218 ) ;
F_53 ( V_2 , V_224 , L_72 , V_29 -> V_136 ) ;
V_2 -> V_231 = 0 ;
F_106 () ;
V_36 = F_7 ( V_2 , V_192 ) ;
V_36 |= V_232 ;
F_14 ( V_2 , V_192 , V_36 ) ;
V_181 = 1000 ;
while ( V_181 -- ) {
if ( V_2 -> V_231 )
break;
F_59 ( 1 ) ;
}
if ( ! V_2 -> V_231 ) {
F_36 ( V_29 , L_73 ,
V_29 -> V_136 ) ;
return - V_130 ;
}
F_53 ( V_2 , V_224 , L_74 ,
V_29 -> V_136 ) ;
F_69 ( V_29 , L_75 ,
( unsigned long ) V_2 -> V_7 , V_29 -> V_136 ) ;
V_2 -> V_119 = - 1 ;
V_2 -> V_121 = - 1 ;
F_107 ( V_2 -> V_89 ) ;
V_36 = F_7 ( V_2 , V_52 ) ;
V_36 &= ( V_93 | 0x00000FFF ) ;
V_36 |= V_94 ;
F_14 ( V_2 , V_52 , V_36 ) ;
V_36 = F_7 ( V_2 , V_233 ) ;
V_36 |= V_234 ;
V_36 &= ~ ( V_235 ) ;
F_14 ( V_2 , V_233 , V_36 ) ;
F_14 ( V_2 , V_97 , ( V_194 << 8 ) ) ;
F_108 ( & V_2 -> V_185 ) ;
V_36 = F_7 ( V_2 , V_192 ) ;
V_36 |= ( V_236 | V_193 | V_237 ) ;
F_14 ( V_2 , V_192 , V_36 ) ;
F_104 ( & V_2 -> V_46 ) ;
V_36 = F_44 ( V_2 , V_100 ) ;
V_36 |= ( V_102 | V_103 | V_238 ) ;
F_47 ( V_2 , V_100 , V_36 ) ;
F_105 ( & V_2 -> V_46 ) ;
F_14 ( V_2 , V_95 , V_96 ) ;
F_109 ( V_29 ) ;
return 0 ;
}
static int F_110 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_36 ;
V_36 = F_7 ( V_2 , V_230 ) ;
V_36 &= ~ V_225 ;
F_14 ( V_2 , V_230 , V_36 ) ;
F_111 ( V_29 ) ;
F_112 ( & V_2 -> V_185 ) ;
V_29 -> V_160 . V_196 += F_7 ( V_2 , V_239 ) ;
F_78 ( V_29 ) ;
if ( V_2 -> V_89 )
F_113 ( V_2 -> V_89 ) ;
F_53 ( V_2 , V_240 , L_76 ) ;
return 0 ;
}
static int F_114 ( struct V_188 * V_189 , struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_241 ;
unsigned int V_242 ;
unsigned int V_243 ;
unsigned int V_36 ;
T_1 V_70 ;
T_3 V_72 ;
V_241 = F_7 ( V_2 , V_63 ) & V_244 ;
if ( F_45 ( V_241 < V_245 ) )
F_43 ( V_2 , V_246 ,
L_77 , V_241 ) ;
V_242 = ( T_1 ) ( ( T_3 ) V_189 -> V_9 & 0x03 ) << 16 ;
V_242 |= V_80 | V_81 ;
V_242 |= ( unsigned int ) V_189 -> V_247 ;
V_243 = ( ( unsigned int ) V_189 -> V_247 ) << 16 ;
V_243 |= ( unsigned int ) V_189 -> V_247 ;
F_14 ( V_2 , V_18 , V_242 ) ;
F_14 ( V_2 , V_18 , V_243 ) ;
V_72 = ( T_3 ) V_189 -> V_9 & ( ~ 0x3 ) ;
V_70 = ( T_1 ) V_189 -> V_247 + 3 ;
V_70 += ( T_1 ) ( ( T_3 ) V_189 -> V_9 & 0x3 ) ;
V_70 >>= 2 ;
V_2 -> V_11 -> V_82 ( V_2 , ( unsigned int * ) V_72 , V_70 ) ;
V_241 -= ( V_189 -> V_247 + 32 ) ;
F_115 ( V_189 ) ;
F_116 ( V_189 ) ;
if ( F_45 ( F_77 ( V_2 ) >= 30 ) )
F_78 ( V_29 ) ;
if ( V_241 < V_245 ) {
F_111 ( V_29 ) ;
V_36 = F_7 ( V_2 , V_233 ) ;
V_36 &= 0x00FFFFFF ;
V_36 |= 0x32000000 ;
F_14 ( V_2 , V_233 , V_36 ) ;
}
return V_248 ;
}
static struct V_249 * F_117 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_78 ( V_29 ) ;
V_29 -> V_160 . V_196 += F_7 ( V_2 , V_239 ) ;
return & V_29 -> V_160 ;
}
static void F_118 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned long V_5 ;
if ( V_29 -> V_5 & V_250 ) {
V_2 -> V_200 = V_251 ;
V_2 -> V_201 = ( V_252 | V_253 ) ;
V_2 -> V_203 = 0 ;
V_2 -> V_205 = 0 ;
} else if ( V_29 -> V_5 & V_254 ) {
V_2 -> V_200 = V_252 ;
V_2 -> V_201 = ( V_251 | V_253 ) ;
V_2 -> V_203 = 0 ;
V_2 -> V_205 = 0 ;
} else if ( ! F_119 ( V_29 ) ) {
unsigned int V_255 = 0 ;
unsigned int V_256 = 0 ;
struct V_257 * V_258 ;
V_2 -> V_200 = V_253 ;
V_2 -> V_201 = ( V_251 | V_252 ) ;
F_120 (ha, dev) {
unsigned int V_259 = F_90 ( V_258 -> V_45 ) ;
unsigned int V_260 = 0x01 << ( V_259 & 0x1F ) ;
if ( V_259 & 0x20 )
V_255 |= V_260 ;
else
V_256 |= V_260 ;
}
V_2 -> V_203 = V_255 ;
V_2 -> V_205 = V_256 ;
} else {
V_2 -> V_200 = 0 ;
V_2 -> V_201 =
( V_251 | V_252 | V_253 ) ;
V_2 -> V_203 = 0 ;
V_2 -> V_205 = 0 ;
}
F_8 ( & V_2 -> V_46 , V_5 ) ;
if ( V_2 -> V_211 <= 1 ) {
if ( ! V_2 -> V_206 ) {
unsigned int V_36 ;
F_53 ( V_2 , V_33 , L_78 ) ;
V_2 -> V_206 = 1 ;
V_36 = F_44 ( V_2 , V_100 ) ;
V_36 &= ~ ( V_103 ) ;
F_47 ( V_2 , V_100 , V_36 ) ;
} else {
}
} else {
F_92 ( V_2 ) ;
}
F_9 ( & V_2 -> V_46 , V_5 ) ;
}
static T_5 F_121 ( int V_136 , void * V_261 )
{
struct V_23 * V_29 = V_261 ;
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_1 V_262 = F_7 ( V_2 , V_190 ) ;
T_1 V_263 = F_7 ( V_2 , V_192 ) ;
int V_264 = V_265 ;
T_1 V_36 ;
if ( F_45 ( V_262 & V_263 & V_266 ) ) {
V_36 = F_7 ( V_2 , V_192 ) ;
V_36 &= ( ~ V_232 ) ;
F_14 ( V_2 , V_192 , V_36 ) ;
F_14 ( V_2 , V_190 , V_266 ) ;
V_2 -> V_231 = 1 ;
F_106 () ;
V_264 = V_267 ;
}
if ( F_45 ( V_262 & V_263 & V_268 ) ) {
F_53 ( V_2 , V_269 , L_79 ) ;
F_14 ( V_2 , V_190 , V_268 ) ;
if ( V_2 -> V_206 )
F_93 ( V_2 ) ;
V_264 = V_267 ;
}
if ( V_262 & V_263 & V_270 ) {
V_36 = F_7 ( V_2 , V_233 ) ;
V_36 |= V_234 ;
F_14 ( V_2 , V_233 , V_36 ) ;
F_14 ( V_2 , V_190 , V_270 ) ;
F_122 ( V_29 ) ;
V_264 = V_267 ;
}
if ( F_45 ( V_262 & V_263 & V_271 ) ) {
F_53 ( V_2 , V_269 , L_80 ) ;
F_14 ( V_2 , V_190 , V_271 ) ;
V_264 = V_267 ;
}
if ( F_46 ( V_262 & V_263 & V_191 ) ) {
if ( F_46 ( F_123 ( & V_2 -> V_185 ) ) ) {
V_36 = F_7 ( V_2 , V_192 ) ;
V_36 &= ( ~ V_193 ) ;
F_14 ( V_2 , V_192 , V_36 ) ;
F_124 ( & V_2 -> V_185 ) ;
} else {
F_43 ( V_2 , V_195 , L_81 ) ;
}
V_264 = V_267 ;
}
return V_264 ;
}
static void F_125 ( struct V_23 * V_29 )
{
F_126 ( V_29 -> V_136 ) ;
F_121 ( 0 , V_29 ) ;
F_127 ( V_29 -> V_136 ) ;
}
static int F_128 ( struct V_23 * V_29 , void * V_272 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_273 * V_45 = V_272 ;
if ( V_2 -> V_211 <= 1 && F_129 ( V_29 ) )
return - V_274 ;
if ( ! F_130 ( V_45 -> V_275 ) )
return - V_276 ;
memcpy ( V_29 -> V_213 , V_45 -> V_275 , V_92 ) ;
F_104 ( & V_2 -> V_46 ) ;
F_101 ( V_2 , V_29 -> V_213 ) ;
F_105 ( & V_2 -> V_46 ) ;
F_69 ( V_29 , L_82 , V_29 -> V_213 ) ;
return 0 ;
}
static int F_131 ( struct V_23 * V_29 , struct V_277 * V_278 , int V_279 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
if ( ! F_129 ( V_29 ) || ! V_2 -> V_89 )
return - V_280 ;
return F_132 ( V_2 -> V_89 , V_278 , V_279 ) ;
}
static int
F_133 ( struct V_23 * V_29 , struct V_281 * V_279 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
V_279 -> V_282 = 1 ;
V_279 -> V_283 = 1 ;
return F_134 ( V_2 -> V_89 , V_279 ) ;
}
static int
F_135 ( struct V_23 * V_29 , struct V_281 * V_279 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
return F_136 ( V_2 -> V_89 , V_279 ) ;
}
static void F_137 ( struct V_23 * V_29 ,
struct V_284 * V_285 )
{
F_138 ( V_285 -> V_286 , V_287 , sizeof( V_285 -> V_286 ) ) ;
F_138 ( V_285 -> V_288 , V_289 , sizeof( V_285 -> V_288 ) ) ;
F_138 ( V_285 -> V_290 , F_70 ( V_29 -> V_29 . V_154 ) ,
sizeof( V_285 -> V_290 ) ) ;
}
static int F_139 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
return F_140 ( V_2 -> V_89 ) ;
}
static T_1 F_141 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
return V_2 -> V_291 ;
}
static void F_142 ( struct V_23 * V_29 , T_1 V_292 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
V_2 -> V_291 = V_292 ;
}
static int F_143 ( struct V_23 * V_29 )
{
return ( ( ( V_293 - V_294 ) / 4 + 1 ) + ( V_295 - V_100 ) + 1 + 32 ) *
sizeof( T_1 ) ;
}
static void
F_144 ( struct V_23 * V_29 , struct V_296 * V_297 ,
void * V_15 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_88 * V_89 = V_2 -> V_89 ;
unsigned long V_5 ;
unsigned int V_30 ;
unsigned int V_86 = 0 ;
T_1 * V_9 = V_15 ;
V_297 -> V_288 = V_2 -> V_155 ;
for ( V_30 = V_294 ; V_30 <= V_293 ; V_30 += ( sizeof( T_1 ) ) )
V_9 [ V_86 ++ ] = F_7 ( V_2 , V_30 ) ;
for ( V_30 = V_100 ; V_30 <= V_295 ; V_30 ++ ) {
F_8 ( & V_2 -> V_46 , V_5 ) ;
V_9 [ V_86 ++ ] = F_44 ( V_2 , V_30 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
}
for ( V_30 = 0 ; V_30 <= 31 ; V_30 ++ )
V_9 [ V_86 ++ ] = F_48 ( V_89 -> V_41 , V_89 -> V_45 , V_30 ) ;
}
static void F_145 ( struct V_1 * V_2 )
{
unsigned int V_36 = F_7 ( V_2 , V_125 ) ;
V_36 &= ~ V_298 ;
F_14 ( V_2 , V_125 , V_36 ) ;
F_59 ( 1 ) ;
}
static int F_146 ( struct V_1 * V_2 , T_1 V_299 )
{
int V_181 = 100 ;
T_1 V_300 ;
F_53 ( V_2 , V_134 , L_83 , V_299 ) ;
if ( F_7 ( V_2 , V_222 ) & V_223 ) {
F_43 ( V_2 , V_134 , L_84 ) ;
return - V_274 ;
}
V_300 = V_299 | V_223 ;
F_14 ( V_2 , V_222 , V_300 ) ;
do {
F_59 ( 1 ) ;
V_300 = F_7 ( V_2 , V_222 ) ;
} while ( ( V_300 & V_223 ) && ( -- V_181 ) );
if ( ! V_181 ) {
F_53 ( V_2 , V_134 , L_85 ) ;
return - V_219 ;
}
if ( V_300 & V_301 ) {
F_53 ( V_2 , V_134 , L_86 ) ;
return - V_280 ;
}
return 0 ;
}
static int F_147 ( struct V_1 * V_2 ,
T_4 V_302 , T_4 * V_9 )
{
T_1 V_299 = V_303 | V_302 ;
int V_25 ;
F_53 ( V_2 , V_134 , L_87 , V_302 ) ;
V_25 = F_146 ( V_2 , V_299 ) ;
if ( ! V_25 )
V_9 [ V_302 ] = F_7 ( V_2 , V_293 ) ;
return V_25 ;
}
static int F_148 ( struct V_1 * V_2 ,
T_4 V_302 , T_4 V_9 )
{
T_1 V_299 = V_304 | V_302 ;
T_1 V_36 ;
int V_25 ;
F_53 ( V_2 , V_134 , L_88 , V_302 , V_9 ) ;
V_25 = F_146 ( V_2 , V_299 ) ;
if ( ! V_25 ) {
V_299 = V_305 | V_302 ;
F_14 ( V_2 , V_293 , ( T_1 ) V_9 ) ;
V_36 = F_7 ( V_2 , V_38 ) ;
V_25 = F_146 ( V_2 , V_299 ) ;
}
return V_25 ;
}
static int F_149 ( struct V_23 * V_29 )
{
return V_306 ;
}
static int F_150 ( struct V_23 * V_29 ,
struct V_307 * V_308 , T_4 * V_9 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_4 V_309 [ V_306 ] ;
int V_247 ;
int V_30 ;
F_145 ( V_2 ) ;
V_247 = F_151 ( V_308 -> V_247 , V_306 ) ;
for ( V_30 = 0 ; V_30 < V_247 ; V_30 ++ ) {
int V_25 = F_147 ( V_2 , V_30 , V_309 ) ;
if ( V_25 < 0 ) {
V_308 -> V_247 = 0 ;
return V_25 ;
}
}
memcpy ( V_9 , & V_309 [ V_308 -> V_35 ] , V_247 ) ;
V_308 -> V_247 = V_247 ;
return 0 ;
}
static int F_152 ( struct V_23 * V_29 ,
struct V_307 * V_308 , T_4 * V_9 )
{
int V_25 ;
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_145 ( V_2 ) ;
F_146 ( V_2 , V_310 ) ;
V_25 = F_148 ( V_2 , V_308 -> V_35 , * V_9 ) ;
F_146 ( V_2 , V_311 ) ;
V_308 -> V_247 = 1 ;
return V_25 ;
}
static void F_153 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_1 V_214 = F_44 ( V_2 , V_216 ) ;
T_1 V_215 = F_44 ( V_2 , V_217 ) ;
V_29 -> V_213 [ 0 ] = ( T_4 ) ( V_215 ) ;
V_29 -> V_213 [ 1 ] = ( T_4 ) ( V_215 >> 8 ) ;
V_29 -> V_213 [ 2 ] = ( T_4 ) ( V_215 >> 16 ) ;
V_29 -> V_213 [ 3 ] = ( T_4 ) ( V_215 >> 24 ) ;
V_29 -> V_213 [ 4 ] = ( T_4 ) ( V_214 ) ;
V_29 -> V_213 [ 5 ] = ( T_4 ) ( V_214 >> 8 ) ;
}
static int F_154 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_312 , V_260 ;
unsigned int V_313 = 100 ;
F_53 ( V_2 , V_131 , L_89 ) ;
F_53 ( V_2 , V_131 , L_90 ,
( unsigned long ) V_2 -> V_7 ) ;
F_53 ( V_2 , V_131 , L_91 , V_29 -> V_136 ) ;
F_53 ( V_2 , V_131 , L_92 ) ;
F_155 ( & V_2 -> V_10 ) ;
F_155 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_7 == NULL ) {
F_43 ( V_2 , V_131 , L_93 ) ;
return - V_130 ;
}
V_260 = V_314 | F_156 ( V_314 ) ;
while ( ! ( F_7 ( V_2 , V_315 ) & V_260 ) && -- V_313 )
F_51 ( 1000 ) ;
if ( V_313 == 0 ) {
F_157 ( L_94 ) ;
return - V_130 ;
}
V_312 = F_7 ( V_2 , V_38 ) ;
F_53 ( V_2 , V_131 , L_95 , V_312 ) ;
if ( V_312 == 0x43218765 ) {
F_53 ( V_2 , V_131 , L_96
L_97 ) ;
F_14 ( V_2 , V_316 , 0xffffffff ) ;
V_312 = F_7 ( V_2 , V_38 ) ;
V_312 = F_7 ( V_2 , V_38 ) ;
}
if ( V_312 != 0x87654321 ) {
F_43 ( V_2 , V_134 , L_95 , V_312 ) ;
if ( ( ( V_312 >> 16 ) & 0xFFFF ) == ( V_312 & 0xFFFF ) ) {
F_43 ( V_2 , V_131 ,
L_98 ) ;
F_53 ( V_2 , V_131 ,
L_99
L_100 ) ;
}
return - V_130 ;
}
V_2 -> V_211 = 0 ;
V_2 -> V_155 = F_7 ( V_2 , V_294 ) ;
switch ( V_2 -> V_155 & 0xFFFF0000 ) {
case 0x01180000 :
case 0x01170000 :
case 0x01160000 :
case 0x01150000 :
case 0x218A0000 :
V_2 -> V_211 = V_2 -> V_155 & 0x0000FFFF ;
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
F_43 ( V_2 , V_131 , L_101 ,
V_2 -> V_155 ) ;
return - V_130 ;
}
F_53 ( V_2 , V_131 ,
L_102 ,
V_2 -> V_155 , V_2 -> V_211 ) ;
if ( V_2 -> V_211 == 0 )
F_43 ( V_2 , V_131 ,
L_103 ) ;
if ( V_2 -> V_4 . V_5 & V_317 ) {
F_104 ( & V_2 -> V_46 ) ;
F_153 ( V_29 ) ;
F_105 ( & V_2 -> V_46 ) ;
}
if ( F_100 ( V_2 ) )
return - V_130 ;
F_158 ( V_29 ) ;
V_29 -> V_5 |= V_318 ;
F_159 ( V_29 , & V_2 -> V_185 , F_81 , V_319 ) ;
V_29 -> V_320 = & V_321 ;
V_29 -> V_322 = & V_323 ;
return 0 ;
}
static int F_160 ( struct V_21 * V_22 )
{
struct V_23 * V_29 ;
struct V_1 * V_2 ;
struct V_324 * V_325 ;
V_29 = F_23 ( V_22 ) ;
F_58 ( ! V_29 ) ;
V_2 = F_24 ( V_29 ) ;
F_58 ( ! V_2 ) ;
F_58 ( ! V_2 -> V_7 ) ;
F_58 ( ! V_2 -> V_89 ) ;
F_53 ( V_2 , V_240 , L_104 ) ;
F_161 ( V_2 -> V_89 ) ;
V_2 -> V_89 = NULL ;
F_75 ( V_2 -> V_40 ) ;
F_76 ( V_2 -> V_40 ) ;
F_162 ( V_22 , NULL ) ;
F_163 ( V_29 ) ;
F_164 ( V_29 -> V_136 , V_29 ) ;
V_325 = F_165 ( V_22 , V_326 ,
L_105 ) ;
if ( ! V_325 )
V_325 = F_166 ( V_22 , V_326 , 0 ) ;
F_167 ( V_325 -> V_327 , F_168 ( V_325 ) ) ;
F_169 ( V_2 -> V_7 ) ;
( void ) F_30 ( V_22 ) ;
F_38 ( V_22 ) ;
F_170 ( V_29 ) ;
return 0 ;
}
static int F_171 ( struct V_328 * V_4 ,
struct V_329 * V_330 )
{
const char * V_331 ;
T_1 V_332 = 0 ;
if ( ! V_330 )
return - V_130 ;
V_4 -> V_133 = F_172 ( V_330 ) ;
V_331 = F_173 ( V_330 ) ;
if ( V_331 )
memcpy ( V_4 -> V_331 , V_331 , V_92 ) ;
F_174 ( V_330 , L_106 , & V_4 -> V_333 ) ;
F_174 ( V_330 , L_107 , & V_332 ) ;
if ( V_332 == 4 )
V_4 -> V_5 |= V_6 ;
else
V_4 -> V_5 |= V_8 ;
if ( F_175 ( V_330 , L_108 , NULL ) )
V_4 -> V_226 = V_334 ;
if ( F_175 ( V_330 , L_109 , NULL ) )
V_4 -> V_228 = V_335 ;
if ( F_175 ( V_330 , L_110 , NULL ) )
V_4 -> V_5 |= V_58 ;
if ( F_175 ( V_330 , L_111 , NULL ) )
V_4 -> V_5 |= V_60 ;
if ( F_175 ( V_330 , L_112 , NULL ) )
V_4 -> V_5 |= V_317 ;
return 0 ;
}
static inline int F_171 (
struct V_328 * V_4 ,
struct V_329 * V_330 )
{
return - V_130 ;
}
static int F_176 ( struct V_21 * V_22 )
{
struct V_329 * V_330 = V_22 -> V_29 . V_336 ;
struct V_23 * V_29 ;
struct V_1 * V_2 ;
struct V_328 * V_4 = V_22 -> V_29 . V_337 ;
struct V_324 * V_325 , * V_338 ;
unsigned int V_218 = 0 ;
int V_339 , V_340 ;
int V_341 ;
F_177 ( L_113 , V_289 ) ;
V_325 = F_165 ( V_22 , V_326 ,
L_105 ) ;
if ( ! V_325 )
V_325 = F_166 ( V_22 , V_326 , 0 ) ;
if ( ! V_325 ) {
F_178 ( L_114 ) ;
V_341 = - V_130 ;
goto V_342;
}
V_339 = F_168 ( V_325 ) ;
V_338 = F_166 ( V_22 , V_343 , 0 ) ;
if ( ! V_338 ) {
F_178 ( L_115 ) ;
V_341 = - V_130 ;
goto V_342;
}
if ( ! F_179 ( V_325 -> V_327 , V_339 , V_287 ) ) {
V_341 = - V_274 ;
goto V_342;
}
V_29 = F_180 ( sizeof( struct V_1 ) ) ;
if ( ! V_29 ) {
V_341 = - V_144 ;
goto V_344;
}
F_181 ( V_29 , & V_22 -> V_29 ) ;
V_2 = F_24 ( V_29 ) ;
V_29 -> V_136 = V_338 -> V_327 ;
V_340 = V_338 -> V_5 & V_345 ;
V_2 -> V_7 = F_182 ( V_325 -> V_327 , V_339 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_291 = ( ( 1 << V_346 ) - 1 ) ;
F_162 ( V_22 , V_29 ) ;
V_341 = F_33 ( V_22 ) ;
if ( V_341 )
goto V_347;
V_341 = F_22 ( V_22 ) ;
if ( V_341 )
goto V_348;
if ( V_2 -> V_7 == NULL ) {
F_43 ( V_2 , V_131 , L_116 ) ;
V_341 = - V_144 ;
goto V_349;
}
V_341 = F_171 ( & V_2 -> V_4 , V_330 ) ;
if ( V_341 && V_4 ) {
memcpy ( & V_2 -> V_4 , V_4 , sizeof( V_2 -> V_4 ) ) ;
V_341 = 0 ;
}
if ( V_341 ) {
F_43 ( V_2 , V_131 , L_117 ) ;
goto V_349;
}
V_2 -> V_11 = & V_350 ;
if ( V_2 -> V_4 . V_333 )
V_2 -> V_11 = & V_351 ;
V_341 = F_154 ( V_29 ) ;
if ( V_341 < 0 )
goto V_349;
if ( V_2 -> V_4 . V_226 == V_334 )
V_218 |= V_227 ;
if ( V_2 -> V_4 . V_228 == V_335 )
V_218 |= V_229 ;
F_14 ( V_2 , V_230 , V_218 ) ;
F_102 ( V_29 ) ;
V_341 = F_183 ( V_29 -> V_136 , F_121 ,
V_340 | V_352 , V_29 -> V_135 , V_29 ) ;
if ( V_341 ) {
F_43 ( V_2 , V_131 ,
L_118 , V_29 -> V_136 ) ;
goto V_349;
}
V_341 = F_184 ( V_29 ) ;
if ( V_341 ) {
F_43 ( V_2 , V_131 , L_119 , V_341 ) ;
goto V_353;
} else {
F_53 ( V_2 , V_131 ,
L_120 , V_29 -> V_135 ) ;
}
V_341 = F_72 ( V_22 , V_29 ) ;
if ( V_341 ) {
F_43 ( V_2 , V_131 , L_121 , V_341 ) ;
goto V_354;
}
F_104 ( & V_2 -> V_46 ) ;
if ( F_130 ( V_29 -> V_213 ) ) {
F_101 ( V_2 , V_29 -> V_213 ) ;
F_53 ( V_2 , V_131 ,
L_122 ) ;
} else if ( F_130 ( V_2 -> V_4 . V_331 ) ) {
memcpy ( V_29 -> V_213 , V_2 -> V_4 . V_331 , 6 ) ;
F_53 ( V_2 , V_131 ,
L_123 ) ;
} else {
F_185 ( V_29 ) ;
if ( F_130 ( V_29 -> V_213 ) ) {
F_53 ( V_2 , V_131 ,
L_124 ) ;
} else {
F_186 ( V_29 ) ;
F_101 ( V_2 , V_29 -> V_213 ) ;
F_53 ( V_2 , V_131 ,
L_125 ) ;
}
}
F_105 ( & V_2 -> V_46 ) ;
F_69 ( V_29 , L_82 , V_29 -> V_213 ) ;
return 0 ;
V_354:
F_163 ( V_29 ) ;
V_353:
F_164 ( V_29 -> V_136 , V_29 ) ;
V_349:
( void ) F_30 ( V_22 ) ;
V_348:
F_38 ( V_22 ) ;
V_347:
F_162 ( V_22 , NULL ) ;
F_169 ( V_2 -> V_7 ) ;
F_170 ( V_29 ) ;
V_344:
F_167 ( V_325 -> V_327 , F_168 ( V_325 ) ) ;
V_342:
return V_341 ;
}
static int F_187 ( struct V_355 * V_29 )
{
struct V_23 * V_24 = F_188 ( V_29 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
F_14 ( V_2 , V_315 ,
V_356 | V_357 |
V_358 | V_359 ) ;
return 0 ;
}
static int F_189 ( struct V_355 * V_29 )
{
struct V_23 * V_24 = F_188 ( V_29 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
unsigned int V_313 = 100 ;
F_14 ( V_2 , V_38 , 0 ) ;
while ( ! ( F_7 ( V_2 , V_315 ) & V_314 ) && -- V_313 )
F_51 ( 1000 ) ;
return ( V_313 == 0 ) ? - V_34 : 0 ;
}
static int T_6 F_190 ( void )
{
F_191 () ;
return F_192 ( & V_360 ) ;
}
static void T_7 F_193 ( void )
{
F_194 ( & V_360 ) ;
}
