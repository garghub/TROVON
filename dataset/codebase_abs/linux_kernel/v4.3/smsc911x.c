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
F_61 ( V_2 -> V_79 ) ;
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
F_49 ( V_89 -> V_41 , V_89 -> V_45 , V_90 ,
V_97 | V_98 ) ;
F_8 ( & V_2 -> V_46 , V_5 ) ;
F_47 ( V_2 , V_99 , V_100
| V_101 | V_102 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
if ( F_56 ( V_2 ) == 0 ) {
V_62 = 0 ;
break;
}
V_2 -> V_103 ++ ;
F_8 ( & V_2 -> V_46 , V_5 ) ;
F_47 ( V_2 , V_99 , 0 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
F_57 ( V_2 ) ;
}
F_8 ( & V_2 -> V_46 , V_5 ) ;
F_47 ( V_2 , V_99 , 0 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
F_49 ( V_89 -> V_41 , V_89 -> V_45 , V_90 , 0 ) ;
F_14 ( V_2 , V_94 , 0 ) ;
F_14 ( V_2 , V_96 , 0 ) ;
return V_62 ;
}
static void F_62 ( struct V_1 * V_2 )
{
struct V_88 * V_89 = V_2 -> V_89 ;
T_1 V_104 = F_7 ( V_2 , V_105 ) ;
T_1 V_106 ;
unsigned long V_5 ;
if ( V_89 -> V_107 == V_108 ) {
T_2 V_109 = F_63 ( V_89 , V_110 ) ;
T_2 V_111 = F_63 ( V_89 , V_112 ) ;
T_4 V_113 = F_64 ( V_109 , V_111 ) ;
if ( V_113 & V_114 )
V_106 = 0xFFFF0002 ;
else
V_106 = 0 ;
if ( V_113 & V_115 )
V_104 |= 0xF ;
else
V_104 &= ~ 0xF ;
F_53 ( V_2 , V_33 , L_33 ,
( V_113 & V_114 ? L_34 : L_35 ) ,
( V_113 & V_115 ? L_34 : L_35 ) ) ;
} else {
F_53 ( V_2 , V_33 , L_36 ) ;
V_106 = 0 ;
V_104 |= 0xF ;
}
F_8 ( & V_2 -> V_46 , V_5 ) ;
F_47 ( V_2 , V_116 , V_106 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
F_14 ( V_2 , V_105 , V_104 ) ;
}
static void F_65 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_88 * V_89 = V_2 -> V_89 ;
unsigned long V_5 ;
int V_117 ;
if ( V_89 -> V_107 != V_2 -> V_118 ) {
unsigned int V_119 ;
F_53 ( V_2 , V_33 , L_37 ) ;
F_8 ( & V_2 -> V_46 , V_5 ) ;
V_119 = F_44 ( V_2 , V_99 ) ;
if ( V_89 -> V_107 ) {
F_53 ( V_2 , V_33 ,
L_38 ) ;
V_119 |= V_100 ;
} else {
F_53 ( V_2 , V_33 ,
L_39 ) ;
V_119 &= ~ V_100 ;
}
F_47 ( V_2 , V_99 , V_119 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
F_62 ( V_2 ) ;
V_2 -> V_118 = V_89 -> V_107 ;
}
V_117 = F_66 ( V_29 ) ;
if ( V_117 != V_2 -> V_120 ) {
F_53 ( V_2 , V_33 , L_40 ) ;
if ( V_117 ) {
F_53 ( V_2 , V_33 , L_41 ) ;
if ( ( V_2 -> V_121 & V_122 ) &&
( ! V_2 -> V_59 ) ) {
V_2 -> V_123 = V_2 -> V_121 ;
F_14 ( V_2 , V_124 ,
V_2 -> V_123 ) ;
}
} else {
F_53 ( V_2 , V_33 , L_42 ) ;
V_2 -> V_123 = F_7 ( V_2 ,
V_124 ) ;
if ( ( V_2 -> V_123 & V_122 ) &&
( ! V_2 -> V_59 ) ) {
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
static int F_67 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_88 * V_128 = NULL ;
int V_25 ;
V_128 = F_68 ( V_2 -> V_40 ) ;
if ( ! V_128 ) {
F_27 ( V_29 , L_43 ) ;
return - V_129 ;
}
F_53 ( V_2 , V_130 , L_44 ,
V_128 -> V_45 , V_128 -> V_131 ) ;
V_25 = F_69 ( V_29 , V_128 , & F_65 ,
V_2 -> V_4 . V_132 ) ;
if ( V_25 ) {
F_27 ( V_29 , L_45 ) ;
return V_25 ;
}
F_70 ( V_29 ,
L_46 ,
V_128 -> V_133 -> V_134 , F_71 ( & V_128 -> V_29 ) , V_128 -> V_135 ) ;
V_128 -> V_136 &= ( V_137 | V_138 |
V_139 ) ;
V_128 -> V_140 = V_128 -> V_136 ;
V_2 -> V_89 = V_128 ;
V_2 -> V_118 = - 1 ;
V_2 -> V_120 = - 1 ;
#ifdef F_72
if ( F_60 ( V_29 ) < 0 ) {
F_43 ( V_2 , V_33 , L_47 ) ;
return - V_129 ;
}
F_53 ( V_2 , V_33 , L_48 ) ;
#endif
F_53 ( V_2 , V_33 , L_49 ) ;
return 0 ;
}
static int F_73 ( struct V_21 * V_22 ,
struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
int V_141 = - V_142 , V_30 ;
V_2 -> V_40 = F_74 () ;
if ( ! V_2 -> V_40 ) {
V_141 = - V_143 ;
goto V_144;
}
V_2 -> V_40 -> V_134 = V_145 ;
snprintf ( V_2 -> V_40 -> V_146 , V_147 , L_50 ,
V_22 -> V_134 , V_22 -> V_146 ) ;
V_2 -> V_40 -> V_44 = V_2 ;
V_2 -> V_40 -> V_148 = F_48 ;
V_2 -> V_40 -> V_149 = F_49 ;
V_2 -> V_40 -> V_135 = V_2 -> V_150 ;
for ( V_30 = 0 ; V_30 < V_151 ; ++ V_30 )
V_2 -> V_40 -> V_135 [ V_30 ] = V_152 ;
V_2 -> V_40 -> V_153 = & V_22 -> V_29 ;
switch ( V_2 -> V_154 & 0xFFFF0000 ) {
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
V_2 -> V_40 -> V_155 = ~ ( 1 << 1 ) ;
}
if ( F_75 ( V_2 -> V_40 ) ) {
F_43 ( V_2 , V_130 , L_53 ) ;
goto V_156;
}
if ( F_67 ( V_29 ) < 0 ) {
F_43 ( V_2 , V_130 , L_53 ) ;
goto V_157;
}
return 0 ;
V_157:
F_76 ( V_2 -> V_40 ) ;
V_156:
F_77 ( V_2 -> V_40 ) ;
V_144:
return V_141 ;
}
static unsigned int F_78 ( struct V_1 * V_2 )
{
return ( F_7 ( V_2 , V_63 )
& V_64 ) >> 16 ;
}
static void F_79 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_158 ;
while ( ( V_158 = F_54 ( V_2 ) ) != 0 ) {
if ( F_45 ( V_158 & 0x80000000 ) ) {
F_43 ( V_2 , V_33 , L_54 ) ;
} else {
if ( F_45 ( V_158 & V_83 ) ) {
V_29 -> V_159 . V_160 ++ ;
} else {
V_29 -> V_159 . V_161 ++ ;
V_29 -> V_159 . V_162 += ( V_158 >> 16 ) ;
}
if ( F_45 ( V_158 & V_163 ) ) {
V_29 -> V_159 . V_164 += 16 ;
V_29 -> V_159 . V_165 += 1 ;
} else {
V_29 -> V_159 . V_164 +=
( ( V_158 >> 3 ) & 0xF ) ;
}
if ( F_45 ( V_158 & V_166 ) )
V_29 -> V_159 . V_167 += 1 ;
if ( F_45 ( V_158 & V_168 ) ) {
V_29 -> V_159 . V_164 ++ ;
V_29 -> V_159 . V_165 ++ ;
}
}
}
}
static void
F_80 ( struct V_23 * V_29 , unsigned int V_169 )
{
int V_170 = 0 ;
if ( F_45 ( V_169 & V_84 ) ) {
V_29 -> V_159 . V_171 ++ ;
if ( F_45 ( V_169 & V_172 ) ) {
V_29 -> V_159 . V_173 ++ ;
V_170 = 1 ;
}
}
if ( F_46 ( ! V_170 ) ) {
if ( F_45 ( ( V_169 & V_174 ) &&
( V_169 & V_175 ) ) )
V_29 -> V_159 . V_176 ++ ;
if ( V_169 & V_177 )
V_29 -> V_159 . V_178 ++ ;
}
}
static void
F_81 ( struct V_1 * V_2 , unsigned int V_179 )
{
if ( F_46 ( V_179 >= 4 ) ) {
unsigned int V_180 = 500 ;
unsigned int V_13 ;
F_14 ( V_2 , V_181 , V_182 ) ;
do {
F_51 ( 1 ) ;
V_13 = F_7 ( V_2 , V_181 ) ;
} while ( ( V_13 & V_182 ) && -- V_180 );
if ( F_45 ( V_180 == 0 ) )
F_43 ( V_2 , V_33 , L_55
L_56 , V_13 ) ;
} else {
unsigned int V_36 ;
while ( V_179 -- )
V_36 = F_7 ( V_2 , V_20 ) ;
}
}
static int F_82 ( struct V_183 * V_184 , int V_185 )
{
struct V_1 * V_2 =
F_83 ( V_184 , struct V_1 , V_184 ) ;
struct V_23 * V_29 = V_2 -> V_29 ;
int V_186 = 0 ;
while ( V_186 < V_185 ) {
unsigned int V_76 ;
unsigned int V_179 ;
struct V_187 * V_188 ;
unsigned int V_169 = F_55 ( V_2 ) ;
if ( ! V_169 ) {
unsigned int V_36 ;
F_14 ( V_2 , V_189 , V_190 ) ;
F_84 ( V_184 ) ;
V_36 = F_7 ( V_2 , V_191 ) ;
V_36 |= V_192 ;
F_14 ( V_2 , V_191 , V_36 ) ;
break;
}
V_186 ++ ;
V_76 = ( ( V_169 & 0x3FFF0000 ) >> 16 ) ;
V_179 = ( V_76 + V_193 + 3 ) >> 2 ;
F_80 ( V_29 , V_169 ) ;
if ( F_45 ( V_169 & V_84 ) ) {
F_43 ( V_2 , V_194 ,
L_57 ) ;
F_81 ( V_2 , V_179 ) ;
V_29 -> V_159 . V_195 ++ ;
continue;
}
V_188 = F_85 ( V_29 , V_179 << 2 ) ;
if ( F_45 ( ! V_188 ) ) {
F_43 ( V_2 , V_194 ,
L_58 ) ;
F_81 ( V_2 , V_179 ) ;
V_29 -> V_159 . V_195 ++ ;
break;
}
V_2 -> V_11 -> V_85 ( V_2 ,
( unsigned int * ) V_188 -> V_9 , V_179 ) ;
F_86 ( V_188 , V_193 ) ;
F_87 ( V_188 , V_76 - 4 ) ;
V_188 -> V_196 = F_88 ( V_188 , V_29 ) ;
F_89 ( V_188 ) ;
F_90 ( V_188 ) ;
V_29 -> V_159 . V_197 ++ ;
V_29 -> V_159 . V_198 += ( V_76 - 4 ) ;
}
return V_186 ;
}
static unsigned int F_91 ( char V_45 [ V_199 ] )
{
return ( F_92 ( V_199 , V_45 ) >> 26 ) & 0x3f ;
}
static void F_93 ( struct V_1 * V_2 )
{
unsigned int V_119 ;
F_42 ( V_2 ) ;
V_119 = F_44 ( V_2 , V_99 ) ;
V_119 |= V_2 -> V_200 ;
V_119 &= ~ ( V_2 -> V_201 ) ;
F_47 ( V_2 , V_99 , V_119 ) ;
F_47 ( V_2 , V_202 , V_2 -> V_203 ) ;
F_47 ( V_2 , V_204 , V_2 -> V_205 ) ;
F_53 ( V_2 , V_33 , L_59 ,
V_119 , V_2 -> V_203 , V_2 -> V_205 ) ;
}
static void F_94 ( struct V_1 * V_2 )
{
unsigned int V_119 ;
F_95 ( & V_2 -> V_46 ) ;
if ( F_44 ( V_2 , V_99 ) & V_102 )
F_43 ( V_2 , V_133 , L_60 ) ;
F_93 ( V_2 ) ;
V_119 = F_44 ( V_2 , V_99 ) ;
V_119 |= V_102 ;
F_47 ( V_2 , V_99 , V_119 ) ;
V_2 -> V_206 = 0 ;
F_96 ( & V_2 -> V_46 ) ;
}
static int F_97 ( struct V_1 * V_2 )
{
int V_207 = 0 ;
if ( ! V_2 -> V_89 )
return V_207 ;
V_207 = F_63 ( V_2 -> V_89 , V_90 ) ;
if ( V_207 < 0 ) {
F_43 ( V_2 , V_133 , L_61 ) ;
return V_207 ;
}
if ( V_207 & V_208 ) {
V_207 = F_98 ( V_2 -> V_89 , V_90 , V_207 & ~ V_208 ) ;
if ( V_207 < 0 ) {
F_43 ( V_2 , V_133 , L_62 ) ;
return V_207 ;
}
F_99 ( 1000 , 1500 ) ;
}
return 0 ;
}
static int F_100 ( struct V_1 * V_2 )
{
int V_207 = 0 ;
if ( ! V_2 -> V_89 )
return V_207 ;
V_207 = F_63 ( V_2 -> V_89 , V_209 ) ;
if ( V_207 < 0 ) {
F_43 ( V_2 , V_133 , L_61 ) ;
return V_207 ;
}
if ( V_207 & V_210 ) {
V_207 = F_98 ( V_2 -> V_89 , V_209 ,
V_207 & ( ~ V_210 ) ) ;
if ( V_207 < 0 ) {
F_43 ( V_2 , V_133 , L_62 ) ;
return V_207 ;
}
F_101 ( 2 ) ;
}
return 0 ;
}
static int F_102 ( struct V_1 * V_2 )
{
int V_207 = 0 ;
if ( ! V_2 -> V_89 )
return V_207 ;
V_207 = F_63 ( V_2 -> V_89 , V_209 ) ;
if ( V_207 < 0 ) {
F_43 ( V_2 , V_133 , L_61 ) ;
return V_207 ;
}
if ( ! ( V_207 & V_210 ) ) {
V_207 = F_98 ( V_2 -> V_89 , V_209 ,
V_207 | V_210 ) ;
if ( V_207 < 0 ) {
F_43 ( V_2 , V_133 , L_62 ) ;
return V_207 ;
}
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
unsigned int V_180 ;
unsigned int V_36 ;
int V_25 ;
V_25 = F_97 ( V_2 ) ;
if ( V_25 ) {
F_43 ( V_2 , V_133 , L_63 ) ;
return V_25 ;
}
if ( V_2 -> V_211 == 4 ) {
V_25 = F_100 ( V_2 ) ;
if ( V_25 ) {
F_43 ( V_2 , V_133 , L_64 ) ;
return V_25 ;
}
}
F_14 ( V_2 , V_52 , V_212 ) ;
V_180 = 10 ;
do {
F_51 ( 10 ) ;
V_36 = F_7 ( V_2 , V_52 ) ;
} while ( ( -- V_180 ) && ( V_36 & V_212 ) );
if ( F_45 ( V_36 & V_212 ) ) {
F_43 ( V_2 , V_133 , L_65 ) ;
return - V_34 ;
}
if ( V_2 -> V_211 == 4 ) {
V_25 = F_102 ( V_2 ) ;
if ( V_25 ) {
F_43 ( V_2 , V_133 , L_64 ) ;
return V_25 ;
}
}
return 0 ;
}
static void
F_104 ( struct V_1 * V_2 , T_4 V_213 [ 6 ] )
{
T_1 V_214 = ( V_213 [ 5 ] << 8 ) | V_213 [ 4 ] ;
T_1 V_215 = ( V_213 [ 3 ] << 24 ) | ( V_213 [ 2 ] << 16 ) |
( V_213 [ 1 ] << 8 ) | V_213 [ 0 ] ;
F_42 ( V_2 ) ;
F_47 ( V_2 , V_216 , V_214 ) ;
F_47 ( V_2 , V_217 , V_215 ) ;
}
static void F_105 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_14 ( V_2 , V_191 , 0 ) ;
F_14 ( V_2 , V_189 , 0xFFFFFFFF ) ;
}
static int F_106 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_180 ;
unsigned int V_36 ;
unsigned int V_218 ;
if ( ! V_2 -> V_89 ) {
F_43 ( V_2 , V_33 , L_66 ) ;
return - V_219 ;
}
if ( F_103 ( V_2 ) ) {
F_43 ( V_2 , V_33 , L_67 ) ;
return - V_34 ;
}
F_14 ( V_2 , V_52 , 0x00050000 ) ;
F_14 ( V_2 , V_105 , 0x006E3740 ) ;
F_107 ( & V_2 -> V_46 ) ;
F_47 ( V_2 , V_220 , V_221 ) ;
F_108 ( & V_2 -> V_46 ) ;
V_180 = 50 ;
while ( ( F_7 ( V_2 , V_222 ) & V_223 ) &&
-- V_180 ) {
F_51 ( 10 ) ;
}
if ( F_45 ( V_180 == 0 ) )
F_43 ( V_2 , V_224 ,
L_68 ) ;
F_14 ( V_2 , V_124 , 0x70070000 ) ;
F_107 ( & V_2 -> V_46 ) ;
F_104 ( V_2 , V_29 -> V_213 ) ;
F_108 ( & V_2 -> V_46 ) ;
F_105 ( V_29 ) ;
V_218 = ( ( 10 << 24 ) | V_225 ) ;
if ( V_2 -> V_4 . V_226 ) {
F_53 ( V_2 , V_224 , L_69 ) ;
V_218 |= V_227 ;
} else {
F_53 ( V_2 , V_224 , L_70 ) ;
}
if ( V_2 -> V_4 . V_228 ) {
F_53 ( V_2 , V_224 , L_71 ) ;
V_218 |= V_229 ;
} else {
F_53 ( V_2 , V_224 , L_72 ) ;
}
F_14 ( V_2 , V_230 , V_218 ) ;
F_53 ( V_2 , V_224 , L_73 , V_29 -> V_135 ) ;
V_2 -> V_231 = 0 ;
F_109 () ;
V_36 = F_7 ( V_2 , V_191 ) ;
V_36 |= V_232 ;
F_14 ( V_2 , V_191 , V_36 ) ;
V_180 = 1000 ;
while ( V_180 -- ) {
if ( V_2 -> V_231 )
break;
F_59 ( 1 ) ;
}
if ( ! V_2 -> V_231 ) {
F_110 ( V_29 , L_74 ,
V_29 -> V_135 ) ;
return - V_129 ;
}
F_53 ( V_2 , V_224 , L_75 ,
V_29 -> V_135 ) ;
F_70 ( V_29 , L_76 ,
( unsigned long ) V_2 -> V_7 , V_29 -> V_135 ) ;
V_2 -> V_118 = - 1 ;
V_2 -> V_120 = - 1 ;
F_111 ( V_2 -> V_89 ) ;
V_36 = F_7 ( V_2 , V_52 ) ;
V_36 &= ( V_92 | 0x00000FFF ) ;
V_36 |= V_93 ;
F_14 ( V_2 , V_52 , V_36 ) ;
V_36 = F_7 ( V_2 , V_233 ) ;
V_36 |= V_234 ;
V_36 &= ~ ( V_235 ) ;
F_14 ( V_2 , V_233 , V_36 ) ;
F_14 ( V_2 , V_96 , ( V_193 << 8 ) ) ;
F_112 ( & V_2 -> V_184 ) ;
V_36 = F_7 ( V_2 , V_191 ) ;
V_36 |= ( V_236 | V_192 | V_237 ) ;
F_14 ( V_2 , V_191 , V_36 ) ;
F_107 ( & V_2 -> V_46 ) ;
V_36 = F_44 ( V_2 , V_99 ) ;
V_36 |= ( V_101 | V_102 | V_238 ) ;
F_47 ( V_2 , V_99 , V_36 ) ;
F_108 ( & V_2 -> V_46 ) ;
F_14 ( V_2 , V_94 , V_95 ) ;
F_113 ( V_29 ) ;
return 0 ;
}
static int F_114 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_36 ;
V_36 = F_7 ( V_2 , V_230 ) ;
V_36 &= ~ V_225 ;
F_14 ( V_2 , V_230 , V_36 ) ;
F_115 ( V_29 ) ;
F_116 ( & V_2 -> V_184 ) ;
V_29 -> V_159 . V_195 += F_7 ( V_2 , V_239 ) ;
F_79 ( V_29 ) ;
if ( V_2 -> V_89 )
F_117 ( V_2 -> V_89 ) ;
F_53 ( V_2 , V_240 , L_77 ) ;
return 0 ;
}
static int F_118 ( struct V_187 * V_188 , struct V_23 * V_29 )
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
L_78 , V_241 ) ;
V_242 = ( T_1 ) ( ( T_3 ) V_188 -> V_9 & 0x03 ) << 16 ;
V_242 |= V_80 | V_81 ;
V_242 |= ( unsigned int ) V_188 -> V_247 ;
V_243 = ( ( unsigned int ) V_188 -> V_247 ) << 16 ;
V_243 |= ( unsigned int ) V_188 -> V_247 ;
F_14 ( V_2 , V_18 , V_242 ) ;
F_14 ( V_2 , V_18 , V_243 ) ;
V_72 = ( T_3 ) V_188 -> V_9 & ( ~ 0x3 ) ;
V_70 = ( T_1 ) V_188 -> V_247 + 3 ;
V_70 += ( T_1 ) ( ( T_3 ) V_188 -> V_9 & 0x3 ) ;
V_70 >>= 2 ;
V_2 -> V_11 -> V_82 ( V_2 , ( unsigned int * ) V_72 , V_70 ) ;
V_241 -= ( V_188 -> V_247 + 32 ) ;
F_119 ( V_188 ) ;
F_120 ( V_188 ) ;
if ( F_45 ( F_78 ( V_2 ) >= 30 ) )
F_79 ( V_29 ) ;
if ( V_241 < V_245 ) {
F_115 ( V_29 ) ;
V_36 = F_7 ( V_2 , V_233 ) ;
V_36 &= 0x00FFFFFF ;
V_36 |= 0x32000000 ;
F_14 ( V_2 , V_233 , V_36 ) ;
}
return V_248 ;
}
static struct V_249 * F_121 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_79 ( V_29 ) ;
V_29 -> V_159 . V_195 += F_7 ( V_2 , V_239 ) ;
return & V_29 -> V_159 ;
}
static void F_122 ( struct V_23 * V_29 )
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
} else if ( ! F_123 ( V_29 ) ) {
unsigned int V_255 = 0 ;
unsigned int V_256 = 0 ;
struct V_257 * V_258 ;
V_2 -> V_200 = V_253 ;
V_2 -> V_201 = ( V_251 | V_252 ) ;
F_124 (ha, dev) {
unsigned int V_259 = F_91 ( V_258 -> V_45 ) ;
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
F_53 ( V_2 , V_33 , L_79 ) ;
V_2 -> V_206 = 1 ;
V_36 = F_44 ( V_2 , V_99 ) ;
V_36 &= ~ ( V_102 ) ;
F_47 ( V_2 , V_99 , V_36 ) ;
} else {
}
} else {
F_93 ( V_2 ) ;
}
F_9 ( & V_2 -> V_46 , V_5 ) ;
}
static T_5 F_125 ( int V_135 , void * V_261 )
{
struct V_23 * V_29 = V_261 ;
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_1 V_262 = F_7 ( V_2 , V_189 ) ;
T_1 V_263 = F_7 ( V_2 , V_191 ) ;
int V_264 = V_265 ;
T_1 V_36 ;
if ( F_45 ( V_262 & V_263 & V_266 ) ) {
V_36 = F_7 ( V_2 , V_191 ) ;
V_36 &= ( ~ V_232 ) ;
F_14 ( V_2 , V_191 , V_36 ) ;
F_14 ( V_2 , V_189 , V_266 ) ;
V_2 -> V_231 = 1 ;
F_109 () ;
V_264 = V_267 ;
}
if ( F_45 ( V_262 & V_263 & V_268 ) ) {
F_53 ( V_2 , V_269 , L_80 ) ;
F_14 ( V_2 , V_189 , V_268 ) ;
if ( V_2 -> V_206 )
F_94 ( V_2 ) ;
V_264 = V_267 ;
}
if ( V_262 & V_263 & V_270 ) {
V_36 = F_7 ( V_2 , V_233 ) ;
V_36 |= V_234 ;
F_14 ( V_2 , V_233 , V_36 ) ;
F_14 ( V_2 , V_189 , V_270 ) ;
F_126 ( V_29 ) ;
V_264 = V_267 ;
}
if ( F_45 ( V_262 & V_263 & V_271 ) ) {
F_53 ( V_2 , V_269 , L_81 ) ;
F_14 ( V_2 , V_189 , V_271 ) ;
V_264 = V_267 ;
}
if ( F_46 ( V_262 & V_263 & V_190 ) ) {
if ( F_46 ( F_127 ( & V_2 -> V_184 ) ) ) {
V_36 = F_7 ( V_2 , V_191 ) ;
V_36 &= ( ~ V_192 ) ;
F_14 ( V_2 , V_191 , V_36 ) ;
F_128 ( & V_2 -> V_184 ) ;
} else {
F_43 ( V_2 , V_194 , L_82 ) ;
}
V_264 = V_267 ;
}
return V_264 ;
}
static void F_129 ( struct V_23 * V_29 )
{
F_130 ( V_29 -> V_135 ) ;
F_125 ( 0 , V_29 ) ;
F_131 ( V_29 -> V_135 ) ;
}
static int F_132 ( struct V_23 * V_29 , void * V_272 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_273 * V_45 = V_272 ;
if ( V_2 -> V_211 <= 1 && F_133 ( V_29 ) )
return - V_274 ;
if ( ! F_134 ( V_45 -> V_275 ) )
return - V_276 ;
memcpy ( V_29 -> V_213 , V_45 -> V_275 , V_199 ) ;
F_107 ( & V_2 -> V_46 ) ;
F_104 ( V_2 , V_29 -> V_213 ) ;
F_108 ( & V_2 -> V_46 ) ;
F_70 ( V_29 , L_83 , V_29 -> V_213 ) ;
return 0 ;
}
static int F_135 ( struct V_23 * V_29 , struct V_277 * V_278 , int V_279 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
if ( ! F_133 ( V_29 ) || ! V_2 -> V_89 )
return - V_280 ;
return F_136 ( V_2 -> V_89 , V_278 , V_279 ) ;
}
static int
F_137 ( struct V_23 * V_29 , struct V_281 * V_279 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
V_279 -> V_282 = 1 ;
V_279 -> V_283 = 1 ;
return F_138 ( V_2 -> V_89 , V_279 ) ;
}
static int
F_139 ( struct V_23 * V_29 , struct V_281 * V_279 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
return F_140 ( V_2 -> V_89 , V_279 ) ;
}
static void F_141 ( struct V_23 * V_29 ,
struct V_284 * V_285 )
{
F_142 ( V_285 -> V_286 , V_287 , sizeof( V_285 -> V_286 ) ) ;
F_142 ( V_285 -> V_288 , V_289 , sizeof( V_285 -> V_288 ) ) ;
F_142 ( V_285 -> V_290 , F_71 ( V_29 -> V_29 . V_153 ) ,
sizeof( V_285 -> V_290 ) ) ;
}
static int F_143 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
return F_144 ( V_2 -> V_89 ) ;
}
static T_1 F_145 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
return V_2 -> V_291 ;
}
static void F_146 ( struct V_23 * V_29 , T_1 V_292 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
V_2 -> V_291 = V_292 ;
}
static int F_147 ( struct V_23 * V_29 )
{
return ( ( ( V_293 - V_294 ) / 4 + 1 ) + ( V_295 - V_99 ) + 1 + 32 ) *
sizeof( T_1 ) ;
}
static void
F_148 ( struct V_23 * V_29 , struct V_296 * V_297 ,
void * V_15 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
struct V_88 * V_89 = V_2 -> V_89 ;
unsigned long V_5 ;
unsigned int V_30 ;
unsigned int V_86 = 0 ;
T_1 * V_9 = V_15 ;
V_297 -> V_288 = V_2 -> V_154 ;
for ( V_30 = V_294 ; V_30 <= V_293 ; V_30 += ( sizeof( T_1 ) ) )
V_9 [ V_86 ++ ] = F_7 ( V_2 , V_30 ) ;
for ( V_30 = V_99 ; V_30 <= V_295 ; V_30 ++ ) {
F_8 ( & V_2 -> V_46 , V_5 ) ;
V_9 [ V_86 ++ ] = F_44 ( V_2 , V_30 ) ;
F_9 ( & V_2 -> V_46 , V_5 ) ;
}
for ( V_30 = 0 ; V_30 <= 31 ; V_30 ++ )
V_9 [ V_86 ++ ] = F_48 ( V_89 -> V_41 , V_89 -> V_45 , V_30 ) ;
}
static void F_149 ( struct V_1 * V_2 )
{
unsigned int V_36 = F_7 ( V_2 , V_124 ) ;
V_36 &= ~ V_298 ;
F_14 ( V_2 , V_124 , V_36 ) ;
F_59 ( 1 ) ;
}
static int F_150 ( struct V_1 * V_2 , T_1 V_299 )
{
int V_180 = 100 ;
T_1 V_300 ;
F_53 ( V_2 , V_133 , L_84 , V_299 ) ;
if ( F_7 ( V_2 , V_222 ) & V_223 ) {
F_43 ( V_2 , V_133 , L_85 ) ;
return - V_274 ;
}
V_300 = V_299 | V_223 ;
F_14 ( V_2 , V_222 , V_300 ) ;
do {
F_59 ( 1 ) ;
V_300 = F_7 ( V_2 , V_222 ) ;
} while ( ( V_300 & V_223 ) && ( -- V_180 ) );
if ( ! V_180 ) {
F_53 ( V_2 , V_133 , L_86 ) ;
return - V_219 ;
}
if ( V_300 & V_301 ) {
F_53 ( V_2 , V_133 , L_87 ) ;
return - V_280 ;
}
return 0 ;
}
static int F_151 ( struct V_1 * V_2 ,
T_4 V_302 , T_4 * V_9 )
{
T_1 V_299 = V_303 | V_302 ;
int V_25 ;
F_53 ( V_2 , V_133 , L_88 , V_302 ) ;
V_25 = F_150 ( V_2 , V_299 ) ;
if ( ! V_25 )
V_9 [ V_302 ] = F_7 ( V_2 , V_293 ) ;
return V_25 ;
}
static int F_152 ( struct V_1 * V_2 ,
T_4 V_302 , T_4 V_9 )
{
T_1 V_299 = V_304 | V_302 ;
T_1 V_36 ;
int V_25 ;
F_53 ( V_2 , V_133 , L_89 , V_302 , V_9 ) ;
V_25 = F_150 ( V_2 , V_299 ) ;
if ( ! V_25 ) {
V_299 = V_305 | V_302 ;
F_14 ( V_2 , V_293 , ( T_1 ) V_9 ) ;
V_36 = F_7 ( V_2 , V_38 ) ;
V_25 = F_150 ( V_2 , V_299 ) ;
}
return V_25 ;
}
static int F_153 ( struct V_23 * V_29 )
{
return V_306 ;
}
static int F_154 ( struct V_23 * V_29 ,
struct V_307 * V_308 , T_4 * V_9 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
T_4 V_309 [ V_306 ] ;
int V_247 ;
int V_30 ;
F_149 ( V_2 ) ;
V_247 = F_155 ( V_308 -> V_247 , V_306 ) ;
for ( V_30 = 0 ; V_30 < V_247 ; V_30 ++ ) {
int V_25 = F_151 ( V_2 , V_30 , V_309 ) ;
if ( V_25 < 0 ) {
V_308 -> V_247 = 0 ;
return V_25 ;
}
}
memcpy ( V_9 , & V_309 [ V_308 -> V_35 ] , V_247 ) ;
V_308 -> V_247 = V_247 ;
return 0 ;
}
static int F_156 ( struct V_23 * V_29 ,
struct V_307 * V_308 , T_4 * V_9 )
{
int V_25 ;
struct V_1 * V_2 = F_24 ( V_29 ) ;
F_149 ( V_2 ) ;
F_150 ( V_2 , V_310 ) ;
V_25 = F_152 ( V_2 , V_308 -> V_35 , * V_9 ) ;
F_150 ( V_2 , V_311 ) ;
V_308 -> V_247 = 1 ;
return V_25 ;
}
static void F_157 ( struct V_23 * V_29 )
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
static int F_158 ( struct V_23 * V_29 )
{
struct V_1 * V_2 = F_24 ( V_29 ) ;
unsigned int V_312 , V_260 ;
unsigned int V_313 = 100 ;
F_53 ( V_2 , V_130 , L_90 ) ;
F_53 ( V_2 , V_130 , L_91 ,
( unsigned long ) V_2 -> V_7 ) ;
F_53 ( V_2 , V_130 , L_92 , V_29 -> V_135 ) ;
F_53 ( V_2 , V_130 , L_93 ) ;
F_159 ( & V_2 -> V_10 ) ;
F_159 ( & V_2 -> V_46 ) ;
if ( V_2 -> V_7 == NULL ) {
F_43 ( V_2 , V_130 , L_94 ) ;
return - V_129 ;
}
V_260 = V_314 | F_160 ( V_314 ) ;
while ( ! ( F_7 ( V_2 , V_315 ) & V_260 ) && -- V_313 )
F_51 ( 1000 ) ;
if ( V_313 == 0 ) {
F_27 ( V_29 , L_95 ) ;
return - V_129 ;
}
V_312 = F_7 ( V_2 , V_38 ) ;
F_53 ( V_2 , V_130 , L_96 , V_312 ) ;
if ( V_312 == 0x43218765 ) {
F_53 ( V_2 , V_130 , L_97
L_98 ) ;
F_14 ( V_2 , V_316 , 0xffffffff ) ;
V_312 = F_7 ( V_2 , V_38 ) ;
V_312 = F_7 ( V_2 , V_38 ) ;
}
if ( V_312 != 0x87654321 ) {
F_43 ( V_2 , V_133 , L_96 , V_312 ) ;
if ( ( ( V_312 >> 16 ) & 0xFFFF ) == ( V_312 & 0xFFFF ) ) {
F_43 ( V_2 , V_130 ,
L_99 ) ;
F_53 ( V_2 , V_130 ,
L_100
L_101 ) ;
}
return - V_129 ;
}
V_2 -> V_211 = 0 ;
V_2 -> V_154 = F_7 ( V_2 , V_294 ) ;
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
F_43 ( V_2 , V_130 , L_102 ,
V_2 -> V_154 ) ;
return - V_129 ;
}
F_53 ( V_2 , V_130 ,
L_103 ,
V_2 -> V_154 , V_2 -> V_211 ) ;
if ( V_2 -> V_211 == 0 )
F_43 ( V_2 , V_130 ,
L_104 ) ;
if ( V_2 -> V_4 . V_5 & V_317 ) {
F_107 ( & V_2 -> V_46 ) ;
F_157 ( V_29 ) ;
F_108 ( & V_2 -> V_46 ) ;
}
if ( F_103 ( V_2 ) )
return - V_129 ;
V_29 -> V_5 |= V_318 ;
F_161 ( V_29 , & V_2 -> V_184 , F_82 , V_319 ) ;
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
F_58 ( ! V_29 ) ;
V_2 = F_24 ( V_29 ) ;
F_58 ( ! V_2 ) ;
F_58 ( ! V_2 -> V_7 ) ;
F_58 ( ! V_2 -> V_89 ) ;
F_53 ( V_2 , V_240 , L_105 ) ;
F_163 ( V_2 -> V_89 ) ;
V_2 -> V_89 = NULL ;
F_76 ( V_2 -> V_40 ) ;
F_77 ( V_2 -> V_40 ) ;
F_164 ( V_29 ) ;
F_165 ( V_29 -> V_135 , V_29 ) ;
V_325 = F_166 ( V_22 , V_326 ,
L_106 ) ;
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
int V_132 ;
T_1 V_330 = 0 ;
int V_141 ;
V_132 = F_175 ( V_29 ) ;
if ( V_132 < 0 )
V_132 = V_331 ;
V_4 -> V_132 = V_132 ;
F_176 ( V_29 , V_4 -> V_332 , V_199 ) ;
V_141 = F_177 ( V_29 , L_107 , & V_330 ) ;
if ( V_141 == - V_142 )
return V_141 ;
if ( ! V_141 && V_330 == 4 )
V_4 -> V_5 |= V_6 ;
else
V_4 -> V_5 |= V_8 ;
F_177 ( V_29 , L_108 , & V_4 -> V_333 ) ;
if ( F_178 ( V_29 , L_109 ) )
V_4 -> V_226 = V_334 ;
if ( F_178 ( V_29 , L_110 ) )
V_4 -> V_228 = V_335 ;
if ( F_178 ( V_29 , L_111 ) )
V_4 -> V_5 |= V_58 ;
if ( F_178 ( V_29 , L_112 ) )
V_4 -> V_5 |= V_60 ;
if ( F_178 ( V_29 , L_113 ) )
V_4 -> V_5 |= V_317 ;
return 0 ;
}
static int F_179 ( struct V_21 * V_22 )
{
struct V_23 * V_29 ;
struct V_1 * V_2 ;
struct V_328 * V_4 = F_180 ( & V_22 -> V_29 ) ;
struct V_324 * V_325 ;
unsigned int V_218 = 0 ;
int V_336 , V_135 , V_337 ;
int V_338 ;
V_325 = F_166 ( V_22 , V_326 ,
L_106 ) ;
if ( ! V_325 )
V_325 = F_167 ( V_22 , V_326 , 0 ) ;
if ( ! V_325 ) {
F_181 ( L_114 ) ;
V_338 = - V_129 ;
goto V_339;
}
V_336 = F_169 ( V_325 ) ;
V_135 = F_182 ( V_22 , 0 ) ;
if ( V_135 == - V_340 ) {
V_338 = - V_340 ;
goto V_339;
} else if ( V_135 <= 0 ) {
F_181 ( L_115 ) ;
V_338 = - V_129 ;
goto V_339;
}
if ( ! F_183 ( V_325 -> V_327 , V_336 , V_287 ) ) {
V_338 = - V_274 ;
goto V_339;
}
V_29 = F_184 ( sizeof( struct V_1 ) ) ;
if ( ! V_29 ) {
V_338 = - V_143 ;
goto V_341;
}
F_185 ( V_29 , & V_22 -> V_29 ) ;
V_2 = F_24 ( V_29 ) ;
V_29 -> V_135 = V_135 ;
V_337 = F_186 ( V_135 ) ;
V_2 -> V_7 = F_187 ( V_325 -> V_327 , V_336 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_291 = ( ( 1 << V_342 ) - 1 ) ;
F_188 ( V_22 , V_29 ) ;
V_338 = F_33 ( V_22 ) ;
if ( V_338 )
goto V_343;
V_338 = F_22 ( V_22 ) ;
if ( V_338 )
goto V_344;
if ( V_2 -> V_7 == NULL ) {
F_43 ( V_2 , V_130 , L_116 ) ;
V_338 = - V_143 ;
goto V_345;
}
V_338 = F_174 ( & V_2 -> V_4 , & V_22 -> V_29 ) ;
if ( V_338 && V_4 ) {
memcpy ( & V_2 -> V_4 , V_4 , sizeof( V_2 -> V_4 ) ) ;
V_338 = 0 ;
}
if ( V_338 ) {
F_43 ( V_2 , V_130 , L_117 ) ;
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
if ( V_2 -> V_4 . V_226 == V_334 )
V_218 |= V_227 ;
if ( V_2 -> V_4 . V_228 == V_335 )
V_218 |= V_229 ;
F_14 ( V_2 , V_230 , V_218 ) ;
F_105 ( V_29 ) ;
V_338 = F_191 ( V_29 -> V_135 , F_125 ,
V_337 | V_348 , V_29 -> V_134 , V_29 ) ;
if ( V_338 ) {
F_43 ( V_2 , V_130 ,
L_118 , V_29 -> V_135 ) ;
goto V_345;
}
F_192 ( V_29 ) ;
V_338 = F_193 ( V_29 ) ;
if ( V_338 ) {
F_43 ( V_2 , V_130 , L_119 , V_338 ) ;
goto V_349;
} else {
F_53 ( V_2 , V_130 ,
L_120 , V_29 -> V_134 ) ;
}
V_338 = F_73 ( V_22 , V_29 ) ;
if ( V_338 ) {
F_43 ( V_2 , V_130 , L_121 , V_338 ) ;
goto V_350;
}
F_107 ( & V_2 -> V_46 ) ;
if ( F_134 ( V_29 -> V_213 ) ) {
F_104 ( V_2 , V_29 -> V_213 ) ;
F_53 ( V_2 , V_130 ,
L_122 ) ;
} else if ( F_134 ( V_2 -> V_4 . V_332 ) ) {
memcpy ( V_29 -> V_213 , V_2 -> V_4 . V_332 , V_199 ) ;
F_53 ( V_2 , V_130 ,
L_123 ) ;
} else {
F_194 ( V_29 ) ;
if ( F_134 ( V_29 -> V_213 ) ) {
F_53 ( V_2 , V_130 ,
L_124 ) ;
} else {
F_195 ( V_29 ) ;
F_104 ( V_2 , V_29 -> V_213 ) ;
F_53 ( V_2 , V_130 ,
L_125 ) ;
}
}
F_108 ( & V_2 -> V_46 ) ;
F_70 ( V_29 , L_83 , V_29 -> V_213 ) ;
return 0 ;
V_350:
F_164 ( V_29 ) ;
V_349:
F_165 ( V_29 -> V_135 , V_29 ) ;
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
F_14 ( V_2 , V_315 ,
V_351 | V_352 |
V_353 | V_354 ) ;
return 0 ;
}
static int F_198 ( struct V_329 * V_29 )
{
struct V_23 * V_24 = F_197 ( V_29 ) ;
struct V_1 * V_2 = F_24 ( V_24 ) ;
unsigned int V_313 = 100 ;
F_14 ( V_2 , V_38 , 0 ) ;
while ( ! ( F_7 ( V_2 , V_315 ) & V_314 ) && -- V_313 )
F_51 ( 1000 ) ;
return ( V_313 == 0 ) ? - V_34 : 0 ;
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
