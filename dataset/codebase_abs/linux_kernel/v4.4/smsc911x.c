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
F_49 ( V_91 -> V_41 , V_91 -> V_45 , V_97 ,
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
F_49 ( V_91 -> V_41 , V_91 -> V_45 , V_97 , 0 ) ;
F_14 ( V_2 , V_94 , 0 ) ;
F_14 ( V_2 , V_96 , 0 ) ;
return V_62 ;
}
static void F_61 ( struct V_1 * V_2 )
{
struct V_90 * V_91 = V_2 -> V_91 ;
T_1 V_105 = F_7 ( V_2 , V_106 ) ;
T_1 V_107 ;
unsigned long V_5 ;
if ( V_91 -> V_108 == V_109 ) {
T_2 V_110 = F_62 ( V_91 , V_111 ) ;
T_2 V_112 = F_62 ( V_91 , V_113 ) ;
T_4 V_114 = F_63 ( V_110 , V_112 ) ;
if ( V_114 & V_115 )
V_107 = 0xFFFF0002 ;
else
V_107 = 0 ;
if ( V_114 & V_116 )
V_105 |= 0xF ;
else
V_105 &= ~ 0xF ;
F_53 ( V_2 , V_33 , L_32 ,
( V_114 & V_115 ? L_33 : L_34 ) ,
( V_114 & V_116 ? L_33 : L_34 ) ) ;
} else {
F_53 ( V_2 , V_33 , L_35 ) ;
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
struct V_90 * V_91 = V_2 -> V_91 ;
unsigned long V_5 ;
int V_118 ;
if ( V_91 -> V_108 != V_2 -> V_119 ) {
unsigned int V_120 ;
F_53 ( V_2 , V_33 , L_36 ) ;
F_8 ( & V_2 -> V_46 , V_5 ) ;
V_120 = F_44 ( V_2 , V_100 ) ;
if ( V_91 -> V_108 ) {
F_53 ( V_2 , V_33 ,
L_37 ) ;
V_120 |= V_101 ;
} else {
F_53 ( V_2 , V_33 ,
L_38 ) ;
V_120 &= ~ V_101 ;
}
F_47 ( V_2 , V_100 , V_120 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
F_61 ( V_2 ) ;
V_2 -> V_119 = V_91 -> V_108 ;
}
V_118 = F_65 ( V_29 ) ;
if ( V_118 != V_2 -> V_121 ) {
F_53 ( V_2 , V_33 , L_39 ) ;
if ( V_118 ) {
F_53 ( V_2 , V_33 , L_40 ) ;
if ( ( V_2 -> V_122 & V_123 ) &&
( ! V_2 -> V_59 ) ) {
V_2 -> V_124 = V_2 -> V_122 ;
F_14 ( V_2 , V_125 ,
V_2 -> V_124 ) ;
}
} else {
F_53 ( V_2 , V_33 , L_41 ) ;
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
struct V_90 * V_129 = NULL ;
int V_25 ;
V_129 = F_67 ( V_2 -> V_40 ) ;
if ( ! V_129 ) {
F_27 ( V_29 , L_42 ) ;
return - V_130 ;
}
F_53 ( V_2 , V_131 , L_43 ,
V_129 -> V_45 , V_129 -> V_132 ) ;
V_25 = F_68 ( V_29 , V_129 , & F_64 ,
V_2 -> V_4 . V_133 ) ;
if ( V_25 ) {
F_27 ( V_29 , L_44 ) ;
return V_25 ;
}
F_69 ( V_29 ,
L_45 ,
V_129 -> V_134 -> V_135 , F_70 ( & V_129 -> V_29 ) , V_129 -> V_136 ) ;
V_129 -> V_137 &= ( V_138 | V_139 |
V_140 ) ;
V_129 -> V_141 = V_129 -> V_137 ;
V_2 -> V_91 = V_129 ;
V_2 -> V_119 = - 1 ;
V_2 -> V_121 = - 1 ;
#ifdef F_71
if ( F_59 ( V_29 ) < 0 ) {
F_43 ( V_2 , V_33 , L_46 ) ;
F_72 ( V_129 ) ;
return - V_130 ;
}
F_53 ( V_2 , V_33 , L_47 ) ;
#endif
F_53 ( V_2 , V_33 , L_48 ) ;
return 0 ;
}
static int F_73 ( struct V_21 * V_22 ,
struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
int V_142 = - V_143 , V_30 ;
V_2 -> V_40 = F_74 () ;
if ( ! V_2 -> V_40 ) {
V_142 = - V_144 ;
goto V_145;
}
V_2 -> V_40 -> V_135 = V_146 ;
snprintf ( V_2 -> V_40 -> V_147 , V_148 , L_49 ,
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
F_53 ( V_2 , V_33 , L_50
L_51 ) ;
V_2 -> V_59 = 0 ;
break;
}
if ( ! V_2 -> V_59 ) {
V_2 -> V_40 -> V_156 = ~ ( 1 << 1 ) ;
}
if ( F_75 ( V_2 -> V_40 ) ) {
F_43 ( V_2 , V_131 , L_52 ) ;
goto V_157;
}
if ( F_66 ( V_29 ) < 0 ) {
F_43 ( V_2 , V_131 , L_52 ) ;
goto V_158;
}
return 0 ;
V_158:
F_76 ( V_2 -> V_40 ) ;
V_157:
F_77 ( V_2 -> V_40 ) ;
V_145:
return V_142 ;
}
static unsigned int F_78 ( struct V_1 * V_2 )
{
return ( F_7 ( V_2 , V_63 )
& V_64 ) >> 16 ;
}
static void F_79 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_159 ;
while ( ( V_159 = F_54 ( V_2 ) ) != 0 ) {
if ( F_45 ( V_159 & 0x80000000 ) ) {
F_43 ( V_2 , V_33 , L_53 ) ;
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
F_80 ( struct V_23 * V_29 , unsigned int V_170 )
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
F_81 ( struct V_1 * V_2 , unsigned int V_180 )
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
F_43 ( V_2 , V_33 , L_54
L_55 , V_13 ) ;
} else {
unsigned int V_36 ;
while ( V_180 -- )
V_36 = F_7 ( V_2 , V_20 ) ;
}
}
static int F_82 ( struct V_184 * V_185 , int V_186 )
{
struct V_1 * V_2 =
F_83 ( V_185 , struct V_1 , V_185 ) ;
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
F_84 ( V_185 ) ;
V_36 = F_7 ( V_2 , V_192 ) ;
V_36 |= V_193 ;
F_14 ( V_2 , V_192 , V_36 ) ;
break;
}
V_187 ++ ;
V_76 = ( ( V_170 & 0x3FFF0000 ) >> 16 ) ;
V_180 = ( V_76 + V_194 + 3 ) >> 2 ;
F_80 ( V_29 , V_170 ) ;
if ( F_45 ( V_170 & V_84 ) ) {
F_43 ( V_2 , V_195 ,
L_56 ) ;
F_81 ( V_2 , V_180 ) ;
V_29 -> V_160 . V_196 ++ ;
continue;
}
V_189 = F_85 ( V_29 , V_180 << 2 ) ;
if ( F_45 ( ! V_189 ) ) {
F_43 ( V_2 , V_195 ,
L_57 ) ;
F_81 ( V_2 , V_180 ) ;
V_29 -> V_160 . V_196 ++ ;
break;
}
V_2 -> V_11 -> V_85 ( V_2 ,
( unsigned int * ) V_189 -> V_9 , V_180 ) ;
F_86 ( V_189 , V_194 ) ;
F_87 ( V_189 , V_76 - 4 ) ;
V_189 -> V_197 = F_88 ( V_189 , V_29 ) ;
F_89 ( V_189 ) ;
F_90 ( V_189 ) ;
V_29 -> V_160 . V_198 ++ ;
V_29 -> V_160 . V_199 += ( V_76 - 4 ) ;
}
return V_187 ;
}
static unsigned int F_91 ( char V_45 [ V_200 ] )
{
return ( F_92 ( V_200 , V_45 ) >> 26 ) & 0x3f ;
}
static void F_93 ( struct V_1 * V_2 )
{
unsigned int V_120 ;
F_42 ( V_2 ) ;
V_120 = F_44 ( V_2 , V_100 ) ;
V_120 |= V_2 -> V_201 ;
V_120 &= ~ ( V_2 -> V_202 ) ;
F_47 ( V_2 , V_100 , V_120 ) ;
F_47 ( V_2 , V_203 , V_2 -> V_204 ) ;
F_47 ( V_2 , V_205 , V_2 -> V_206 ) ;
F_53 ( V_2 , V_33 , L_58 ,
V_120 , V_2 -> V_204 , V_2 -> V_206 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
unsigned int V_120 ;
F_95 ( & V_2 -> V_46 ) ;
if ( F_44 ( V_2 , V_100 ) & V_103 )
F_43 ( V_2 , V_134 , L_59 ) ;
F_93 ( V_2 ) ;
V_120 = F_44 ( V_2 , V_100 ) ;
V_120 |= V_103 ;
F_47 ( V_2 , V_100 , V_120 ) ;
V_2 -> V_207 = 0 ;
F_96 ( & V_2 -> V_46 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_208 = 0 ;
if ( ! V_2 -> V_91 )
return V_208 ;
V_208 = F_62 ( V_2 -> V_91 , V_97 ) ;
if ( V_208 < 0 ) {
F_43 ( V_2 , V_134 , L_60 ) ;
return V_208 ;
}
if ( V_208 & V_209 ) {
V_208 = F_98 ( V_2 -> V_91 , V_97 , V_208 & ~ V_209 ) ;
if ( V_208 < 0 ) {
F_43 ( V_2 , V_134 , L_61 ) ;
return V_208 ;
}
F_99 ( 1000 , 1500 ) ;
}
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_208 = 0 ;
if ( ! V_2 -> V_91 )
return V_208 ;
V_208 = F_62 ( V_2 -> V_91 , V_210 ) ;
if ( V_208 < 0 ) {
F_43 ( V_2 , V_134 , L_60 ) ;
return V_208 ;
}
if ( V_208 & V_211 ) {
V_208 = F_98 ( V_2 -> V_91 , V_210 ,
V_208 & ( ~ V_211 ) ) ;
if ( V_208 < 0 ) {
F_43 ( V_2 , V_134 , L_61 ) ;
return V_208 ;
}
F_101 ( 2 ) ;
}
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_208 = 0 ;
if ( ! V_2 -> V_91 )
return V_208 ;
V_208 = F_62 ( V_2 -> V_91 , V_210 ) ;
if ( V_208 < 0 ) {
F_43 ( V_2 , V_134 , L_60 ) ;
return V_208 ;
}
if ( ! ( V_208 & V_211 ) ) {
V_208 = F_98 ( V_2 -> V_91 , V_210 ,
V_208 | V_211 ) ;
if ( V_208 < 0 ) {
F_43 ( V_2 , V_134 , L_61 ) ;
return V_208 ;
}
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
unsigned int V_181 ;
unsigned int V_36 ;
int V_25 ;
V_25 = F_97 ( V_2 ) ;
if ( V_25 ) {
F_43 ( V_2 , V_134 , L_62 ) ;
return V_25 ;
}
if ( V_2 -> V_212 == 4 ) {
V_25 = F_100 ( V_2 ) ;
if ( V_25 ) {
F_43 ( V_2 , V_134 , L_63 ) ;
return V_25 ;
}
}
F_14 ( V_2 , V_52 , V_213 ) ;
V_181 = 10 ;
do {
F_51 ( 10 ) ;
V_36 = F_7 ( V_2 , V_52 ) ;
} while ( ( -- V_181 ) && ( V_36 & V_213 ) );
if ( F_45 ( V_36 & V_213 ) ) {
F_43 ( V_2 , V_134 , L_64 ) ;
return - V_34 ;
}
if ( V_2 -> V_212 == 4 ) {
V_25 = F_102 ( V_2 ) ;
if ( V_25 ) {
F_43 ( V_2 , V_134 , L_63 ) ;
return V_25 ;
}
}
return 0 ;
}
static void
F_104 ( struct V_1 * V_2 , T_4 V_214 [ 6 ] )
{
T_1 V_215 = ( V_214 [ 5 ] << 8 ) | V_214 [ 4 ] ;
T_1 V_216 = ( V_214 [ 3 ] << 24 ) | ( V_214 [ 2 ] << 16 ) |
( V_214 [ 1 ] << 8 ) | V_214 [ 0 ] ;
F_42 ( V_2 ) ;
F_47 ( V_2 , V_217 , V_215 ) ;
F_47 ( V_2 , V_218 , V_216 ) ;
}
static void F_105 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_14 ( V_2 , V_192 , 0 ) ;
F_14 ( V_2 , V_190 , 0xFFFFFFFF ) ;
}
static int F_106 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_181 ;
unsigned int V_36 ;
unsigned int V_219 ;
if ( ! V_2 -> V_91 ) {
F_43 ( V_2 , V_33 , L_65 ) ;
return - V_220 ;
}
if ( F_103 ( V_2 ) ) {
F_43 ( V_2 , V_33 , L_66 ) ;
return - V_34 ;
}
F_14 ( V_2 , V_52 , 0x00050000 ) ;
F_14 ( V_2 , V_106 , 0x006E3740 ) ;
F_107 ( & V_2 -> V_46 ) ;
F_47 ( V_2 , V_221 , V_222 ) ;
F_108 ( & V_2 -> V_46 ) ;
V_181 = 50 ;
while ( ( F_7 ( V_2 , V_223 ) & V_224 ) &&
-- V_181 ) {
F_51 ( 10 ) ;
}
if ( F_45 ( V_181 == 0 ) )
F_43 ( V_2 , V_225 ,
L_67 ) ;
F_14 ( V_2 , V_125 , 0x70070000 ) ;
F_107 ( & V_2 -> V_46 ) ;
F_104 ( V_2 , V_29 -> V_214 ) ;
F_108 ( & V_2 -> V_46 ) ;
F_105 ( V_29 ) ;
V_219 = ( ( 10 << 24 ) | V_226 ) ;
if ( V_2 -> V_4 . V_227 ) {
F_53 ( V_2 , V_225 , L_68 ) ;
V_219 |= V_228 ;
} else {
F_53 ( V_2 , V_225 , L_69 ) ;
}
if ( V_2 -> V_4 . V_229 ) {
F_53 ( V_2 , V_225 , L_70 ) ;
V_219 |= V_230 ;
} else {
F_53 ( V_2 , V_225 , L_71 ) ;
}
F_14 ( V_2 , V_231 , V_219 ) ;
F_53 ( V_2 , V_225 , L_72 , V_29 -> V_136 ) ;
V_2 -> V_232 = 0 ;
F_109 () ;
V_36 = F_7 ( V_2 , V_192 ) ;
V_36 |= V_233 ;
F_14 ( V_2 , V_192 , V_36 ) ;
V_181 = 1000 ;
while ( V_181 -- ) {
if ( V_2 -> V_232 )
break;
F_58 ( 1 ) ;
}
if ( ! V_2 -> V_232 ) {
F_110 ( V_29 , L_73 ,
V_29 -> V_136 ) ;
return - V_130 ;
}
F_53 ( V_2 , V_225 , L_74 ,
V_29 -> V_136 ) ;
F_69 ( V_29 , L_75 ,
( unsigned long ) V_2 -> V_7 , V_29 -> V_136 ) ;
V_2 -> V_119 = - 1 ;
V_2 -> V_121 = - 1 ;
F_111 ( V_2 -> V_91 ) ;
V_36 = F_7 ( V_2 , V_52 ) ;
V_36 &= ( V_92 | 0x00000FFF ) ;
V_36 |= V_93 ;
F_14 ( V_2 , V_52 , V_36 ) ;
V_36 = F_7 ( V_2 , V_234 ) ;
V_36 |= V_235 ;
V_36 &= ~ ( V_236 ) ;
F_14 ( V_2 , V_234 , V_36 ) ;
F_14 ( V_2 , V_96 , ( V_194 << 8 ) ) ;
F_112 ( & V_2 -> V_185 ) ;
V_36 = F_7 ( V_2 , V_192 ) ;
V_36 |= ( V_237 | V_193 | V_238 ) ;
F_14 ( V_2 , V_192 , V_36 ) ;
F_107 ( & V_2 -> V_46 ) ;
V_36 = F_44 ( V_2 , V_100 ) ;
V_36 |= ( V_102 | V_103 | V_239 ) ;
F_47 ( V_2 , V_100 , V_36 ) ;
F_108 ( & V_2 -> V_46 ) ;
F_14 ( V_2 , V_94 , V_95 ) ;
F_113 ( V_29 ) ;
return 0 ;
}
static int F_114 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_36 ;
V_36 = F_7 ( V_2 , V_231 ) ;
V_36 &= ~ V_226 ;
F_14 ( V_2 , V_231 , V_36 ) ;
F_115 ( V_29 ) ;
F_116 ( & V_2 -> V_185 ) ;
V_29 -> V_160 . V_196 += F_7 ( V_2 , V_240 ) ;
F_79 ( V_29 ) ;
if ( V_2 -> V_91 )
F_117 ( V_2 -> V_91 ) ;
F_53 ( V_2 , V_241 , L_76 ) ;
return 0 ;
}
static int F_118 ( struct V_188 * V_189 , struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_242 ;
unsigned int V_243 ;
unsigned int V_244 ;
unsigned int V_36 ;
T_1 V_70 ;
T_3 V_72 ;
V_242 = F_7 ( V_2 , V_63 ) & V_245 ;
if ( F_45 ( V_242 < V_246 ) )
F_43 ( V_2 , V_247 ,
L_77 , V_242 ) ;
V_243 = ( T_1 ) ( ( T_3 ) V_189 -> V_9 & 0x03 ) << 16 ;
V_243 |= V_80 | V_81 ;
V_243 |= ( unsigned int ) V_189 -> V_248 ;
V_244 = ( ( unsigned int ) V_189 -> V_248 ) << 16 ;
V_244 |= ( unsigned int ) V_189 -> V_248 ;
F_14 ( V_2 , V_18 , V_243 ) ;
F_14 ( V_2 , V_18 , V_244 ) ;
V_72 = ( T_3 ) V_189 -> V_9 & ( ~ 0x3 ) ;
V_70 = ( T_1 ) V_189 -> V_248 + 3 ;
V_70 += ( T_1 ) ( ( T_3 ) V_189 -> V_9 & 0x3 ) ;
V_70 >>= 2 ;
V_2 -> V_11 -> V_82 ( V_2 , ( unsigned int * ) V_72 , V_70 ) ;
V_242 -= ( V_189 -> V_248 + 32 ) ;
F_119 ( V_189 ) ;
F_120 ( V_189 ) ;
if ( F_45 ( F_78 ( V_2 ) >= 30 ) )
F_79 ( V_29 ) ;
if ( V_242 < V_246 ) {
F_115 ( V_29 ) ;
V_36 = F_7 ( V_2 , V_234 ) ;
V_36 &= 0x00FFFFFF ;
V_36 |= 0x32000000 ;
F_14 ( V_2 , V_234 , V_36 ) ;
}
return V_249 ;
}
static struct V_250 * F_121 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_79 ( V_29 ) ;
V_29 -> V_160 . V_196 += F_7 ( V_2 , V_240 ) ;
return & V_29 -> V_160 ;
}
static void F_122 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned long V_5 ;
if ( V_29 -> V_5 & V_251 ) {
V_2 -> V_201 = V_252 ;
V_2 -> V_202 = ( V_253 | V_254 ) ;
V_2 -> V_204 = 0 ;
V_2 -> V_206 = 0 ;
} else if ( V_29 -> V_5 & V_255 ) {
V_2 -> V_201 = V_253 ;
V_2 -> V_202 = ( V_252 | V_254 ) ;
V_2 -> V_204 = 0 ;
V_2 -> V_206 = 0 ;
} else if ( ! F_123 ( V_29 ) ) {
unsigned int V_256 = 0 ;
unsigned int V_257 = 0 ;
struct V_258 * V_259 ;
V_2 -> V_201 = V_254 ;
V_2 -> V_202 = ( V_252 | V_253 ) ;
F_124 (ha, dev) {
unsigned int V_260 = F_91 ( V_259 -> V_45 ) ;
unsigned int V_261 = 0x01 << ( V_260 & 0x1F ) ;
if ( V_260 & 0x20 )
V_256 |= V_261 ;
else
V_257 |= V_261 ;
}
V_2 -> V_204 = V_256 ;
V_2 -> V_206 = V_257 ;
} else {
V_2 -> V_201 = 0 ;
V_2 -> V_202 =
( V_252 | V_253 | V_254 ) ;
V_2 -> V_204 = 0 ;
V_2 -> V_206 = 0 ;
}
F_8 ( & V_2 -> V_46 , V_5 ) ;
if ( V_2 -> V_212 <= 1 ) {
if ( ! V_2 -> V_207 ) {
unsigned int V_36 ;
F_53 ( V_2 , V_33 , L_78 ) ;
V_2 -> V_207 = 1 ;
V_36 = F_44 ( V_2 , V_100 ) ;
V_36 &= ~ ( V_103 ) ;
F_47 ( V_2 , V_100 , V_36 ) ;
} else {
}
} else {
F_93 ( V_2 ) ;
}
F_9 ( & V_2 -> V_46 , V_5 ) ;
}
static T_5 F_125 ( int V_136 , void * V_262 )
{
struct V_23 * V_29 = V_262 ;
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_1 V_263 = F_7 ( V_2 , V_190 ) ;
T_1 V_264 = F_7 ( V_2 , V_192 ) ;
int V_265 = V_266 ;
T_1 V_36 ;
if ( F_45 ( V_263 & V_264 & V_267 ) ) {
V_36 = F_7 ( V_2 , V_192 ) ;
V_36 &= ( ~ V_233 ) ;
F_14 ( V_2 , V_192 , V_36 ) ;
F_14 ( V_2 , V_190 , V_267 ) ;
V_2 -> V_232 = 1 ;
F_109 () ;
V_265 = V_268 ;
}
if ( F_45 ( V_263 & V_264 & V_269 ) ) {
F_53 ( V_2 , V_270 , L_79 ) ;
F_14 ( V_2 , V_190 , V_269 ) ;
if ( V_2 -> V_207 )
F_94 ( V_2 ) ;
V_265 = V_268 ;
}
if ( V_263 & V_264 & V_271 ) {
V_36 = F_7 ( V_2 , V_234 ) ;
V_36 |= V_235 ;
F_14 ( V_2 , V_234 , V_36 ) ;
F_14 ( V_2 , V_190 , V_271 ) ;
F_126 ( V_29 ) ;
V_265 = V_268 ;
}
if ( F_45 ( V_263 & V_264 & V_272 ) ) {
F_53 ( V_2 , V_270 , L_80 ) ;
F_14 ( V_2 , V_190 , V_272 ) ;
V_265 = V_268 ;
}
if ( F_46 ( V_263 & V_264 & V_191 ) ) {
if ( F_46 ( F_127 ( & V_2 -> V_185 ) ) ) {
V_36 = F_7 ( V_2 , V_192 ) ;
V_36 &= ( ~ V_193 ) ;
F_14 ( V_2 , V_192 , V_36 ) ;
F_128 ( & V_2 -> V_185 ) ;
} else {
F_43 ( V_2 , V_195 , L_81 ) ;
}
V_265 = V_268 ;
}
return V_265 ;
}
static void F_129 ( struct V_23 * V_29 )
{
F_130 ( V_29 -> V_136 ) ;
F_125 ( 0 , V_29 ) ;
F_131 ( V_29 -> V_136 ) ;
}
static int F_132 ( struct V_23 * V_29 , void * V_273 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_274 * V_45 = V_273 ;
if ( V_2 -> V_212 <= 1 && F_133 ( V_29 ) )
return - V_275 ;
if ( ! F_134 ( V_45 -> V_276 ) )
return - V_277 ;
memcpy ( V_29 -> V_214 , V_45 -> V_276 , V_200 ) ;
F_107 ( & V_2 -> V_46 ) ;
F_104 ( V_2 , V_29 -> V_214 ) ;
F_108 ( & V_2 -> V_46 ) ;
F_69 ( V_29 , L_82 , V_29 -> V_214 ) ;
return 0 ;
}
static int F_135 ( struct V_23 * V_29 , struct V_278 * V_279 , int V_280 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
if ( ! F_133 ( V_29 ) || ! V_2 -> V_91 )
return - V_281 ;
return F_136 ( V_2 -> V_91 , V_279 , V_280 ) ;
}
static int
F_137 ( struct V_23 * V_29 , struct V_282 * V_280 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
V_280 -> V_283 = 1 ;
V_280 -> V_284 = 1 ;
return F_138 ( V_2 -> V_91 , V_280 ) ;
}
static int
F_139 ( struct V_23 * V_29 , struct V_282 * V_280 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
return F_140 ( V_2 -> V_91 , V_280 ) ;
}
static void F_141 ( struct V_23 * V_29 ,
struct V_285 * V_286 )
{
F_142 ( V_286 -> V_287 , V_288 , sizeof( V_286 -> V_287 ) ) ;
F_142 ( V_286 -> V_289 , V_290 , sizeof( V_286 -> V_289 ) ) ;
F_142 ( V_286 -> V_291 , F_70 ( V_29 -> V_29 . V_154 ) ,
sizeof( V_286 -> V_291 ) ) ;
}
static int F_143 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
return F_144 ( V_2 -> V_91 ) ;
}
static T_1 F_145 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
return V_2 -> V_292 ;
}
static void F_146 ( struct V_23 * V_29 , T_1 V_293 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
V_2 -> V_292 = V_293 ;
}
static int F_147 ( struct V_23 * V_29 )
{
return ( ( ( V_294 - V_295 ) / 4 + 1 ) + ( V_296 - V_100 ) + 1 + 32 ) *
sizeof( T_1 ) ;
}
static void
F_148 ( struct V_23 * V_29 , struct V_297 * V_298 ,
void * V_15 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_90 * V_91 = V_2 -> V_91 ;
unsigned long V_5 ;
unsigned int V_30 ;
unsigned int V_86 = 0 ;
T_1 * V_9 = V_15 ;
V_298 -> V_289 = V_2 -> V_155 ;
for ( V_30 = V_295 ; V_30 <= V_294 ; V_30 += ( sizeof( T_1 ) ) )
V_9 [ V_86 ++ ] = F_7 ( V_2 , V_30 ) ;
for ( V_30 = V_100 ; V_30 <= V_296 ; V_30 ++ ) {
F_8 ( & V_2 -> V_46 , V_5 ) ;
V_9 [ V_86 ++ ] = F_44 ( V_2 , V_30 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
}
for ( V_30 = 0 ; V_30 <= 31 ; V_30 ++ )
V_9 [ V_86 ++ ] = F_48 ( V_91 -> V_41 , V_91 -> V_45 , V_30 ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
unsigned int V_36 = F_7 ( V_2 , V_125 ) ;
V_36 &= ~ V_299 ;
F_14 ( V_2 , V_125 , V_36 ) ;
F_58 ( 1 ) ;
}
static int F_150 ( struct V_1 * V_2 , T_1 V_300 )
{
int V_181 = 100 ;
T_1 V_301 ;
F_53 ( V_2 , V_134 , L_83 , V_300 ) ;
if ( F_7 ( V_2 , V_223 ) & V_224 ) {
F_43 ( V_2 , V_134 , L_84 ) ;
return - V_275 ;
}
V_301 = V_300 | V_224 ;
F_14 ( V_2 , V_223 , V_301 ) ;
do {
F_58 ( 1 ) ;
V_301 = F_7 ( V_2 , V_223 ) ;
} while ( ( V_301 & V_224 ) && ( -- V_181 ) );
if ( ! V_181 ) {
F_53 ( V_2 , V_134 , L_85 ) ;
return - V_220 ;
}
if ( V_301 & V_302 ) {
F_53 ( V_2 , V_134 , L_86 ) ;
return - V_281 ;
}
return 0 ;
}
static int F_151 ( struct V_1 * V_2 ,
T_4 V_303 , T_4 * V_9 )
{
T_1 V_300 = V_304 | V_303 ;
int V_25 ;
F_53 ( V_2 , V_134 , L_87 , V_303 ) ;
V_25 = F_150 ( V_2 , V_300 ) ;
if ( ! V_25 )
V_9 [ V_303 ] = F_7 ( V_2 , V_294 ) ;
return V_25 ;
}
static int F_152 ( struct V_1 * V_2 ,
T_4 V_303 , T_4 V_9 )
{
T_1 V_300 = V_305 | V_303 ;
T_1 V_36 ;
int V_25 ;
F_53 ( V_2 , V_134 , L_88 , V_303 , V_9 ) ;
V_25 = F_150 ( V_2 , V_300 ) ;
if ( ! V_25 ) {
V_300 = V_306 | V_303 ;
F_14 ( V_2 , V_294 , ( T_1 ) V_9 ) ;
V_36 = F_7 ( V_2 , V_38 ) ;
V_25 = F_150 ( V_2 , V_300 ) ;
}
return V_25 ;
}
static int F_153 ( struct V_23 * V_29 )
{
return V_307 ;
}
static int F_154 ( struct V_23 * V_29 ,
struct V_308 * V_309 , T_4 * V_9 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_4 V_310 [ V_307 ] ;
int V_248 ;
int V_30 ;
F_149 ( V_2 ) ;
V_248 = F_155 ( V_309 -> V_248 , V_307 ) ;
for ( V_30 = 0 ; V_30 < V_248 ; V_30 ++ ) {
int V_25 = F_151 ( V_2 , V_30 , V_310 ) ;
if ( V_25 < 0 ) {
V_309 -> V_248 = 0 ;
return V_25 ;
}
}
memcpy ( V_9 , & V_310 [ V_309 -> V_35 ] , V_248 ) ;
V_309 -> V_248 = V_248 ;
return 0 ;
}
static int F_156 ( struct V_23 * V_29 ,
struct V_308 * V_309 , T_4 * V_9 )
{
int V_25 ;
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_149 ( V_2 ) ;
F_150 ( V_2 , V_311 ) ;
V_25 = F_152 ( V_2 , V_309 -> V_35 , * V_9 ) ;
F_150 ( V_2 , V_312 ) ;
V_309 -> V_248 = 1 ;
return V_25 ;
}
static void F_157 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_1 V_215 = F_44 ( V_2 , V_217 ) ;
T_1 V_216 = F_44 ( V_2 , V_218 ) ;
V_29 -> V_214 [ 0 ] = ( T_4 ) ( V_216 ) ;
V_29 -> V_214 [ 1 ] = ( T_4 ) ( V_216 >> 8 ) ;
V_29 -> V_214 [ 2 ] = ( T_4 ) ( V_216 >> 16 ) ;
V_29 -> V_214 [ 3 ] = ( T_4 ) ( V_216 >> 24 ) ;
V_29 -> V_214 [ 4 ] = ( T_4 ) ( V_215 ) ;
V_29 -> V_214 [ 5 ] = ( T_4 ) ( V_215 >> 8 ) ;
}
static int F_158 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_313 , V_261 ;
unsigned int V_314 = 100 ;
F_53 ( V_2 , V_131 , L_89 ) ;
F_53 ( V_2 , V_131 , L_90 ,
( unsigned long ) V_2 -> V_7 ) ;
F_53 ( V_2 , V_131 , L_91 , V_29 -> V_136 ) ;
F_53 ( V_2 , V_131 , L_92 ) ;
F_159 ( & V_2 -> V_10 ) ;
F_159 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_7 == NULL ) {
F_43 ( V_2 , V_131 , L_93 ) ;
return - V_130 ;
}
V_261 = V_315 | F_160 ( V_315 ) ;
while ( ! ( F_7 ( V_2 , V_88 ) & V_261 ) && -- V_314 )
F_51 ( 1000 ) ;
if ( V_314 == 0 ) {
F_27 ( V_29 , L_94 ) ;
return - V_130 ;
}
V_313 = F_7 ( V_2 , V_38 ) ;
F_53 ( V_2 , V_131 , L_95 , V_313 ) ;
if ( V_313 == 0x43218765 ) {
F_53 ( V_2 , V_131 , L_96
L_97 ) ;
F_14 ( V_2 , V_316 , 0xffffffff ) ;
V_313 = F_7 ( V_2 , V_38 ) ;
V_313 = F_7 ( V_2 , V_38 ) ;
}
if ( V_313 != 0x87654321 ) {
F_43 ( V_2 , V_134 , L_95 , V_313 ) ;
if ( ( ( V_313 >> 16 ) & 0xFFFF ) == ( V_313 & 0xFFFF ) ) {
F_43 ( V_2 , V_131 ,
L_98 ) ;
F_53 ( V_2 , V_131 ,
L_99
L_100 ) ;
}
return - V_130 ;
}
V_2 -> V_212 = 0 ;
V_2 -> V_155 = F_7 ( V_2 , V_295 ) ;
switch ( V_2 -> V_155 & 0xFFFF0000 ) {
case 0x01180000 :
case 0x01170000 :
case 0x01160000 :
case 0x01150000 :
case 0x218A0000 :
V_2 -> V_212 = V_2 -> V_155 & 0x0000FFFF ;
break;
case 0x118A0000 :
case 0x117A0000 :
case 0x116A0000 :
case 0x115A0000 :
V_2 -> V_212 = 3 ;
break;
case 0x92100000 :
case 0x92110000 :
case 0x92200000 :
case 0x92210000 :
V_2 -> V_212 = 4 ;
break;
default:
F_43 ( V_2 , V_131 , L_101 ,
V_2 -> V_155 ) ;
return - V_130 ;
}
F_53 ( V_2 , V_131 ,
L_102 ,
V_2 -> V_155 , V_2 -> V_212 ) ;
if ( V_2 -> V_212 == 0 )
F_43 ( V_2 , V_131 ,
L_103 ) ;
if ( V_2 -> V_4 . V_5 & V_317 ) {
F_107 ( & V_2 -> V_46 ) ;
F_157 ( V_29 ) ;
F_108 ( & V_2 -> V_46 ) ;
}
if ( F_57 ( V_2 ) || F_103 ( V_2 ) )
return - V_130 ;
V_29 -> V_5 |= V_318 ;
F_161 ( V_29 , & V_2 -> V_185 , F_82 , V_319 ) ;
V_29 -> V_320 = & V_321 ;
V_29 -> V_322 = & V_323 ;
return 0 ;
}
static int F_162 ( struct V_21 * V_22 )
{
struct V_23 * V_29 ;
struct V_1 * V_2 ;
struct V_324 * V_325 ;
V_29 = F_23 ( V_22 ) ;
F_163 ( ! V_29 ) ;
V_2 = F_24 ( V_29 ) ;
F_163 ( ! V_2 ) ;
F_163 ( ! V_2 -> V_7 ) ;
F_163 ( ! V_2 -> V_91 ) ;
F_53 ( V_2 , V_241 , L_104 ) ;
F_72 ( V_2 -> V_91 ) ;
V_2 -> V_91 = NULL ;
F_76 ( V_2 -> V_40 ) ;
F_77 ( V_2 -> V_40 ) ;
F_164 ( V_29 ) ;
F_165 ( V_29 -> V_136 , V_29 ) ;
V_325 = F_166 ( V_22 , V_326 ,
L_105 ) ;
if ( ! V_325 )
V_325 = F_167 ( V_22 , V_326 , 0 ) ;
F_168 ( V_325 -> V_327 , F_169 ( V_325 ) ) ;
F_170 ( V_2 -> V_7 ) ;
( void ) F_30 ( V_22 ) ;
F_38 ( V_22 ) ;
F_171 ( V_29 ) ;
F_172 ( & V_22 -> V_29 ) ;
F_173 ( & V_22 -> V_29 ) ;
return 0 ;
}
static int F_174 ( struct V_328 * V_4 ,
struct V_329 * V_29 )
{
int V_133 ;
T_1 V_330 = 0 ;
int V_142 ;
V_133 = F_175 ( V_29 ) ;
if ( V_133 < 0 )
V_133 = V_331 ;
V_4 -> V_133 = V_133 ;
F_176 ( V_29 , V_4 -> V_332 , V_200 ) ;
V_142 = F_177 ( V_29 , L_106 , & V_330 ) ;
if ( V_142 == - V_143 )
return V_142 ;
if ( ! V_142 && V_330 == 4 )
V_4 -> V_5 |= V_6 ;
else
V_4 -> V_5 |= V_8 ;
F_177 ( V_29 , L_107 , & V_4 -> V_333 ) ;
if ( F_178 ( V_29 , L_108 ) )
V_4 -> V_227 = V_334 ;
if ( F_178 ( V_29 , L_109 ) )
V_4 -> V_229 = V_335 ;
if ( F_178 ( V_29 , L_110 ) )
V_4 -> V_5 |= V_58 ;
if ( F_178 ( V_29 , L_111 ) )
V_4 -> V_5 |= V_60 ;
if ( F_178 ( V_29 , L_112 ) )
V_4 -> V_5 |= V_317 ;
return 0 ;
}
static int F_179 ( struct V_21 * V_22 )
{
struct V_23 * V_29 ;
struct V_1 * V_2 ;
struct V_328 * V_4 = F_180 ( & V_22 -> V_29 ) ;
struct V_324 * V_325 ;
unsigned int V_219 = 0 ;
int V_336 , V_136 , V_337 ;
int V_338 ;
V_325 = F_166 ( V_22 , V_326 ,
L_105 ) ;
if ( ! V_325 )
V_325 = F_167 ( V_22 , V_326 , 0 ) ;
if ( ! V_325 ) {
F_181 ( L_113 ) ;
V_338 = - V_130 ;
goto V_339;
}
V_336 = F_169 ( V_325 ) ;
V_136 = F_182 ( V_22 , 0 ) ;
if ( V_136 == - V_340 ) {
V_338 = - V_340 ;
goto V_339;
} else if ( V_136 <= 0 ) {
F_181 ( L_114 ) ;
V_338 = - V_130 ;
goto V_339;
}
if ( ! F_183 ( V_325 -> V_327 , V_336 , V_288 ) ) {
V_338 = - V_275 ;
goto V_339;
}
V_29 = F_184 ( sizeof( struct V_1 ) ) ;
if ( ! V_29 ) {
V_338 = - V_144 ;
goto V_341;
}
F_185 ( V_29 , & V_22 -> V_29 ) ;
V_2 = F_24 ( V_29 ) ;
V_29 -> V_136 = V_136 ;
V_337 = F_186 ( V_136 ) ;
V_2 -> V_7 = F_187 ( V_325 -> V_327 , V_336 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_292 = ( ( 1 << V_342 ) - 1 ) ;
F_188 ( V_22 , V_29 ) ;
V_338 = F_33 ( V_22 ) ;
if ( V_338 )
goto V_343;
V_338 = F_22 ( V_22 ) ;
if ( V_338 )
goto V_344;
if ( V_2 -> V_7 == NULL ) {
F_43 ( V_2 , V_131 , L_115 ) ;
V_338 = - V_144 ;
goto V_345;
}
V_338 = F_174 ( & V_2 -> V_4 , & V_22 -> V_29 ) ;
if ( V_338 && V_4 ) {
memcpy ( & V_2 -> V_4 , V_4 , sizeof( V_2 -> V_4 ) ) ;
V_338 = 0 ;
}
if ( V_338 ) {
F_43 ( V_2 , V_131 , L_116 ) ;
goto V_345;
}
V_2 -> V_11 = & V_346 ;
if ( V_2 -> V_4 . V_333 )
V_2 -> V_11 = & V_347 ;
F_189 ( & V_22 -> V_29 ) ;
F_190 ( & V_22 -> V_29 ) ;
V_338 = F_158 ( V_29 ) ;
if ( V_338 < 0 )
goto V_345;
if ( V_2 -> V_4 . V_227 == V_334 )
V_219 |= V_228 ;
if ( V_2 -> V_4 . V_229 == V_335 )
V_219 |= V_230 ;
F_14 ( V_2 , V_231 , V_219 ) ;
F_105 ( V_29 ) ;
V_338 = F_191 ( V_29 -> V_136 , F_125 ,
V_337 | V_348 , V_29 -> V_135 , V_29 ) ;
if ( V_338 ) {
F_43 ( V_2 , V_131 ,
L_117 , V_29 -> V_136 ) ;
goto V_345;
}
F_192 ( V_29 ) ;
V_338 = F_193 ( V_29 ) ;
if ( V_338 ) {
F_43 ( V_2 , V_131 , L_118 , V_338 ) ;
goto V_349;
} else {
F_53 ( V_2 , V_131 ,
L_119 , V_29 -> V_135 ) ;
}
V_338 = F_73 ( V_22 , V_29 ) ;
if ( V_338 ) {
F_43 ( V_2 , V_131 , L_120 , V_338 ) ;
goto V_350;
}
F_107 ( & V_2 -> V_46 ) ;
if ( F_134 ( V_29 -> V_214 ) ) {
F_104 ( V_2 , V_29 -> V_214 ) ;
F_53 ( V_2 , V_131 ,
L_121 ) ;
} else if ( F_134 ( V_2 -> V_4 . V_332 ) ) {
memcpy ( V_29 -> V_214 , V_2 -> V_4 . V_332 , V_200 ) ;
F_53 ( V_2 , V_131 ,
L_122 ) ;
} else {
F_194 ( V_29 ) ;
if ( F_134 ( V_29 -> V_214 ) ) {
F_53 ( V_2 , V_131 ,
L_123 ) ;
} else {
F_195 ( V_29 ) ;
F_104 ( V_2 , V_29 -> V_214 ) ;
F_53 ( V_2 , V_131 ,
L_124 ) ;
}
}
F_108 ( & V_2 -> V_46 ) ;
F_69 ( V_29 , L_82 , V_29 -> V_214 ) ;
return 0 ;
V_350:
F_164 ( V_29 ) ;
V_349:
F_165 ( V_29 -> V_136 , V_29 ) ;
V_345:
F_172 ( & V_22 -> V_29 ) ;
F_173 ( & V_22 -> V_29 ) ;
( void ) F_30 ( V_22 ) ;
V_344:
F_38 ( V_22 ) ;
V_343:
F_170 ( V_2 -> V_7 ) ;
F_171 ( V_29 ) ;
V_341:
F_168 ( V_325 -> V_327 , F_169 ( V_325 ) ) ;
V_339:
return V_338 ;
}
static int F_196 ( struct V_329 * V_29 )
{
struct V_23 * V_24 = F_197 ( V_29 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
F_14 ( V_2 , V_88 ,
V_351 | V_352 |
V_353 | V_354 ) ;
return 0 ;
}
static int F_198 ( struct V_329 * V_29 )
{
struct V_23 * V_24 = F_197 ( V_29 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
unsigned int V_314 = 100 ;
F_14 ( V_2 , V_38 , 0 ) ;
while ( ! ( F_7 ( V_2 , V_88 ) & V_315 ) && -- V_314 )
F_51 ( 1000 ) ;
return ( V_314 == 0 ) ? - V_34 : 0 ;
}
static int T_6 F_199 ( void )
{
F_200 () ;
return F_201 ( & V_355 ) ;
}
static void T_7 F_202 ( void )
{
F_203 ( & V_355 ) ;
}
