static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_7 , V_8 ;
T_1 V_9 , V_10 ;
unsigned long V_11 ;
T_2 * V_12 ;
T_3 V_13 ;
#ifdef F_2
F_3 ( V_14 L_1 , ( long ) V_4 -> V_15 ,
( long ) V_4 -> V_16 ) ;
#endif
V_11 = V_4 -> V_15 + V_4 -> V_16 - 1 ;
V_9 = V_11 & ~ ( V_6 -> V_17 - 1 ) ;
V_7 = V_4 -> V_15 & ~ ( V_6 -> V_17 - 1 ) ;
V_10 = V_11 & ( V_6 -> V_17 - 1 ) ;
V_8 = V_4 -> V_15 & ( V_6 -> V_17 - 1 ) ;
F_4 ( V_2 , V_4 -> V_15 , V_4 -> V_16 , & V_13 ,
( void * * ) & V_12 , NULL ) ;
if ( V_7 == V_9 || V_2 -> V_18 == V_6 -> V_17 ) {
memset ( V_12 , 0xff , V_4 -> V_16 ) ;
} else {
while ( V_7 != V_9 ) {
#ifdef F_2
F_3 ( V_14 L_2
L_3 , ( long ) V_7 , ( long ) V_9 ) ;
#endif
memset ( V_12 , 0xff , V_6 -> V_17 ) ;
if ( V_7 + V_6 -> V_17 >= V_2 -> V_18 ) {
goto V_19;
}
V_7 += V_6 -> V_17 ;
F_4 ( V_2 , ( V_6 -> V_20 | V_7 ) ,
V_6 -> V_17 , & V_13 ,
( void * * ) & V_12 , NULL ) ;
}
memset ( V_12 , 0xff , V_10 ) ;
}
V_19:
V_4 -> V_21 = V_22 ;
#ifdef F_2
F_3 ( V_14 L_4 ) ;
#endif
F_5 ( V_4 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_4 V_23 , T_3 V_16 ,
T_3 * V_13 , void * * V_24 , T_5 * V_25 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_7 ;
T_1 V_8 ;
#ifdef F_2
F_3 ( V_14 L_5 , ( long ) V_23 , ( long ) V_16 ) ;
#endif
V_7 = V_23 & ~ ( V_6 -> V_17 - 1 ) ;
V_8 = V_23 & ( V_6 -> V_17 - 1 ) ;
if ( V_6 -> V_26 != V_23 ) {
F_6 ( V_6 -> V_27 , V_28 ,
( V_6 -> V_20 | V_7 ) ) ;
V_6 -> V_26 = V_7 ;
}
* V_24 = V_6 -> V_29 + V_8 ;
* V_13 = V_16 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_4 V_23 , T_3 V_16 )
{
#ifdef F_2
F_3 ( V_14 L_6 ) ;
#endif
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_4 V_23 , T_3 V_16 ,
T_3 * V_13 , T_2 * V_30 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_7 , V_8 ;
T_1 V_9 , V_10 ;
unsigned long V_11 ;
T_2 * V_12 ;
T_2 * V_31 = V_30 ;
#ifdef F_2
F_3 ( V_14 L_7 ,
( long ) V_23 , ( long ) V_16 , ( long ) V_6 -> V_17 ) ;
#endif
V_11 = V_23 + V_16 - 1 ;
V_7 = V_23 & ~ ( V_6 -> V_17 - 1 ) ;
V_9 = V_11 & ~ ( V_6 -> V_17 - 1 ) ;
V_8 = V_23 & ( V_6 -> V_17 - 1 ) ;
V_10 = V_11 & ( V_6 -> V_17 - 1 ) ;
F_4 ( V_2 , V_23 , V_16 , V_13 , ( void * * ) & V_12 , NULL ) ;
if ( V_7 == V_9 ) {
memcpy ( V_31 , V_12 , V_16 ) ;
V_31 += V_16 ;
} else {
while ( V_7 != V_9 ) {
#ifdef F_2
F_3 ( V_14 L_8
L_3 , ( long ) V_7 , ( long ) V_9 ) ;
#endif
memcpy ( V_31 , V_12 , V_6 -> V_17 ) ;
V_31 += V_6 -> V_17 ;
if ( V_7 + V_6 -> V_17 >= V_2 -> V_18 ) {
goto V_19;
}
V_7 += V_6 -> V_17 ;
F_4 ( V_2 , V_7 , V_6 -> V_17 , V_13 ,
( void * * ) & V_12 , NULL ) ;
}
memcpy ( V_31 , V_12 , V_10 ) ;
V_31 += V_10 ;
}
V_19:
#ifdef F_2
F_3 ( V_14 L_9 ) ;
#endif
* V_13 = V_31 - V_30 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_4 V_32 , T_3 V_16 ,
T_3 * V_13 , const T_2 * V_30 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_7 , V_8 ;
T_1 V_9 , V_10 ;
unsigned long V_11 ;
T_2 * V_12 ;
const T_2 * V_33 = V_30 ;
#ifdef F_2
F_3 ( V_14 L_10 ,
( long ) V_32 , ( long ) V_16 , ( long ) V_6 -> V_17 ) ;
#endif
V_11 = V_32 + V_16 - 1 ;
V_7 = V_32 & ~ ( V_6 -> V_17 - 1 ) ;
V_9 = V_11 & ~ ( V_6 -> V_17 - 1 ) ;
V_8 = V_32 & ( V_6 -> V_17 - 1 ) ;
V_10 = V_11 & ( V_6 -> V_17 - 1 ) ;
F_4 ( V_2 , V_32 , V_16 , V_13 , ( void * * ) & V_12 , NULL ) ;
if ( V_7 == V_9 ) {
memcpy ( V_12 , V_33 , V_16 ) ;
V_33 += V_16 ;
} else {
while ( V_7 != V_9 ) {
#ifdef F_2
F_3 ( V_14 L_11
L_3 , ( long ) V_7 , ( long ) V_9 ) ;
#endif
memcpy ( V_12 , V_33 , V_6 -> V_17 ) ;
V_33 += V_6 -> V_17 ;
if ( V_7 >= V_2 -> V_18 ) {
goto V_19;
}
V_7 += V_6 -> V_17 ;
F_4 ( V_2 , V_7 , V_6 -> V_17 , V_13 ,
( void * * ) & V_12 , NULL ) ;
}
memcpy ( V_12 , V_33 , V_10 ) ;
V_33 += V_10 ;
}
V_19:
#ifdef F_2
F_3 ( V_14 L_12 ) ;
#endif
* V_13 = V_33 - V_30 ;
return 0 ;
}
static int F_10 ( struct V_34 * V_27 )
{
#ifdef F_11
T_1 V_35 ;
#endif
T_1 V_18 , V_36 , V_37 , V_38 ;
T_6 V_39 , V_40 , V_41 ;
T_7 V_42 , V_43 ;
if ( ! V_27 ) {
return - V_44 ;
}
V_43 = 0 ;
F_12 ( V_27 , V_45 , 0xA5 ) ;
F_13 ( V_27 , V_45 , & V_42 ) ;
for ( V_41 = 0 ; V_41 < 10 ; V_41 ++ ) {
V_43 = 0 ;
V_42 &= ~ 0x80 ;
while ( V_43 ++ < 100 ) {
F_12 ( V_27 , V_45 , V_42 ) ;
}
V_43 = 0 ;
V_42 |= 0x80 ;
while ( V_43 ++ < 100 ) {
F_12 ( V_27 , V_45 , V_42 ) ;
}
}
V_42 |= ( 0x40 | 0x20 ) ;
F_12 ( V_27 , V_45 , V_42 ) ;
F_14 ( V_27 , V_46 , & V_39 ) ;
V_40 = V_39 & ~ ( V_47 | V_48 ) ;
F_15 ( V_27 , V_46 , V_40 ) ;
F_16 ( V_27 , V_28 , & V_36 ) ;
V_38 = ( V_36 | V_49 | V_50 ) ;
F_6 ( V_27 , V_28 , V_38 ) ;
F_16 ( V_27 , V_51 , & V_37 ) ;
#ifndef F_11
F_6 ( V_27 , V_51 , ~ 0 ) ;
F_16 ( V_27 , V_51 , & V_18 ) ;
V_18 = ( V_18 & V_52 ) ;
V_18 &= ~ ( V_18 - 1 ) ;
F_6 ( V_27 , V_51 , V_37 ) ;
#else
F_16 ( V_27 , V_53 , & V_35 ) ;
V_18 = F_17 ( V_35 ) ;
V_35 = F_18 ( V_35 , 0x5 ) ;
V_35 = F_19 ( V_35 , 0x9 ) ;
F_6 ( V_27 , V_53 , V_35 ) ;
F_16 ( V_27 , V_54 , & V_35 ) ;
V_18 += F_17 ( V_35 ) ;
V_35 = F_18 ( V_35 , 0x5 ) ;
V_35 = F_19 ( V_35 , 0x9 ) ;
F_6 ( V_27 , V_54 , V_35 ) ;
F_16 ( V_27 , V_55 , & V_35 ) ;
V_18 += F_17 ( V_35 ) ;
V_35 = F_18 ( V_35 , 0x5 ) ;
V_35 = F_19 ( V_35 , 0x9 ) ;
F_6 ( V_27 , V_55 , V_35 ) ;
F_16 ( V_27 , V_56 , & V_35 ) ;
V_18 += F_17 ( V_35 ) ;
V_35 = F_18 ( V_35 , 0x5 ) ;
V_35 = F_19 ( V_35 , 0x9 ) ;
F_6 ( V_27 , V_56 , V_35 ) ;
if ( ( V_18 &= V_52 ) == 0 ) {
return - V_44 ;
}
#endif
if ( ( V_37 & V_57 ) != V_58 ) {
return - V_44 ;
}
F_15 ( V_27 , V_59 , 0x0400 ) ;
F_15 ( V_27 , V_60 , 0x00bf ) ;
do {
F_14 ( V_27 , V_60 , & V_39 ) ;
if ( V_43 ++ > 100 )
break;
} while ( ( V_47 ) & V_39 );
for ( V_41 = 1 ; V_41 <= 8 ; V_41 ++ ) {
F_15 ( V_27 , V_60 , 0x0df ) ;
V_43 = 0 ;
do {
F_14 ( V_27 , V_60 , & V_39 ) ;
if ( V_43 ++ > 100 )
break;
} while ( ( V_47 ) & V_39 );
}
F_15 ( V_27 , V_59 , 0x0020 ) ;
F_15 ( V_27 , V_60 , 0x0ff ) ;
V_43 = 0 ;
do {
F_14 ( V_27 , V_60 , & V_39 ) ;
if ( V_43 ++ > 100 )
break;
} while ( ( V_47 ) & V_39 );
F_16 ( V_27 , V_61 , & V_36 ) ;
V_36 |= 0x02000000 ;
F_6 ( V_27 , V_61 , V_36 ) ;
F_14 ( V_27 , V_62 , & V_39 ) ;
if ( ( V_39 & V_63 ) == 0 ) {
V_39 |= V_63 ;
F_15 ( V_27 , V_62 , V_39 ) ;
}
if ( ( V_39 & V_64 ) != 0x0 ) {
V_39 &= ~ V_64 ;
F_15 ( V_27 , V_62 , V_39 ) ;
}
F_15 ( V_27 , V_46 ,
V_48 | V_47 ) ;
#ifdef F_2
F_3 ( V_14 L_13
L_14 , ( V_18 < 1024 ) ? V_18 : ( V_18 < 1048576 ) ?
V_18 >> 10 : V_18 >> 20 ,
( V_18 < 1024 ) ? L_15 : ( V_18 < 1048576 ) ? L_16 : L_17 , V_18 ,
( ( V_36 & ( 0x1 << 3 ) ) == 0 ) ? L_18 : L_15 ,
( unsigned long long ) F_20 ( V_27 , 0 ) ) ;
F_16 ( V_27 , V_53 , & V_36 ) ;
F_3 ( V_14 L_19
L_20
L_21 ,
( ( ( 0x1 << 1 ) & V_36 ) == 0 ) ? L_22 : L_23 ,
( ( ( 0x1 << 0 ) & V_36 ) == 0 ) ? L_24 : L_25 ,
F_17 ( V_36 ) ,
( ( V_36 >> 20 ) & 0x7FF ) , ( ( V_36 >> 13 ) & 0x7 ) ,
( ( V_36 >> 9 ) & 0xF ) ) ;
F_16 ( V_27 , V_54 , & V_36 ) ;
F_3 ( V_14 L_26
L_27
L_28 ,
( ( ( 0x1 << 1 ) & V_36 ) == 0 ) ? L_22 : L_23 ,
( ( ( 0x1 << 0 ) & V_36 ) == 0 ) ? L_24 : L_25 ,
F_17 ( V_36 ) ,
( ( V_36 >> 20 ) & 0x7FF ) , ( ( V_36 >> 13 ) & 0x7 ) ,
( ( V_36 >> 9 ) & 0xF ) ) ;
F_16 ( V_27 , V_55 , & V_36 ) ;
F_3 ( V_14 L_29
L_30
L_31 ,
( ( ( 0x1 << 1 ) & V_36 ) == 0 ) ? L_22 : L_23 ,
( ( ( 0x1 << 0 ) & V_36 ) == 0 ) ? L_24 : L_25 ,
F_17 ( V_36 ) ,
( ( V_36 >> 20 ) & 0x7FF ) , ( ( V_36 >> 13 ) & 0x7 ) ,
( ( V_36 >> 9 ) & 0xF ) ) ;
F_16 ( V_27 , V_56 , & V_36 ) ;
F_3 ( V_14 L_32
L_33
L_34 ,
( ( ( 0x1 << 1 ) & V_36 ) == 0 ) ? L_22 : L_23 ,
( ( ( 0x1 << 0 ) & V_36 ) == 0 ) ? L_24 : L_25 ,
F_17 ( V_36 ) ,
( ( V_36 >> 20 ) & 0x7FF ) , ( ( V_36 >> 13 ) & 0x7 ) ,
( ( V_36 >> 9 ) & 0xF ) ) ;
F_14 ( V_27 , V_46 , & V_39 ) ;
F_3 ( V_14 L_35 ,
( ( ( 0x1 << 1 ) & V_39 ) == 0 ) ? L_36 : L_37 ) ;
F_3 ( V_14 L_38 ,
( ( ( 0x1 << 0 ) & V_39 ) == 0 ) ? L_36 : L_37 ) ;
F_14 ( V_27 , V_62 , & V_39 ) ;
F_3 ( V_14 L_39 ,
( ( V_64 & V_39 ) == 0x000 ) ? L_40 :
( ( V_64 & V_39 ) == 0x200 ) ? L_41 :
( ( V_64 & V_39 ) == 0x400 ) ? L_42 : L_43 ) ;
F_3 ( V_14 L_44 ,
( ( V_63 & V_39 ) == 0 ) ? L_45 : L_15 ) ;
F_13 ( V_27 , V_45 , & V_42 ) ;
F_3 ( V_14 L_46
L_47
L_48 ,
( V_42 & 0x1 ) ? L_49 : L_50 ,
( V_42 & 0x20 ) ? L_15 : L_51 , ( V_42 & 0x40 ) ? L_15 : L_51 ) ;
#endif
return V_18 ;
}
static int T_8 F_21 ( void )
{
struct V_34 * V_65 = NULL ;
struct V_5 * V_6 ;
int V_66 = 0 ;
struct V_1 * V_2 ;
int V_67 = 0 ;
if ( V_68 ) {
V_68 = ( 1 << ( F_22 ( V_68 ) - 1 ) ) << 20 ;
if ( V_68 > ( 1 << 30 ) ) {
F_3 ( V_69 L_52 ,
V_68 ) ;
return - V_70 ;
}
}
if ( V_17 ) {
V_17 = ( 1 << ( F_22 ( V_17 ) - 1 ) ) << 20 ;
if ( V_17 > ( 1 << 30 ) ) {
F_3 ( V_69 L_53
L_54 , V_17 ) ;
return - V_70 ;
}
}
F_3 (KERN_INFO PMC551_VERSION) ;
for (; ; ) {
if ( ( V_65 = F_23 ( V_71 ,
V_72 ,
V_65 ) ) == NULL ) {
break;
}
F_3 ( V_69 L_55 ,
( unsigned long long ) F_20 ( V_65 , 0 ) ) ;
if ( ( V_67 = F_10 ( V_65 ) ) <= 0 ) {
F_3 ( V_69 L_56 ) ;
break;
}
if ( V_68 ) {
V_67 = V_68 ;
F_3 ( V_69 L_57
L_58 , V_67 ) ;
} else {
V_68 = V_67 ;
}
V_2 = F_24 ( sizeof( struct V_1 ) , V_73 ) ;
if ( ! V_2 )
break;
V_6 = F_24 ( sizeof( struct V_5 ) , V_73 ) ;
if ( ! V_6 ) {
F_25 ( V_2 ) ;
break;
}
V_2 -> V_6 = V_6 ;
V_6 -> V_27 = V_65 ;
if ( V_17 > V_67 ) {
F_3 ( V_69 L_59
L_60 , V_67 >> 20 ) ;
V_6 -> V_17 = V_17 = V_67 ;
} else if ( V_17 == 0 || V_17 == V_67 ) {
F_3 ( V_69 L_61
L_62 , V_67 >> 20 ) ;
V_6 -> V_17 = V_17 = V_67 ;
} else {
F_3 ( V_69 L_63
L_62 , V_17 >> 20 ) ;
V_6 -> V_17 = V_17 ;
}
V_6 -> V_29 = F_26 ( V_65 , 0 , V_6 -> V_17 ) ;
if ( ! V_6 -> V_29 ) {
F_3 ( V_69 L_64 ) ;
F_25 ( V_2 -> V_6 ) ;
F_25 ( V_2 ) ;
break;
}
#ifdef F_2
F_3 ( V_14 L_65 ,
F_22 ( V_6 -> V_17 >> 20 ) - 1 ) ;
#endif
V_6 -> V_20 = ( V_50
| V_49
| ( F_22 ( V_6 -> V_17 >> 20 ) - 1 ) << 4 ) ;
V_6 -> V_26 = V_6 -> V_20 ;
F_6 ( V_6 -> V_27 , V_28 ,
V_6 -> V_26 ) ;
#ifdef F_2
F_3 ( V_14 L_66 ,
( V_6 -> V_20 & 0xF0 ) >> 4 ) ;
#endif
V_2 -> V_18 = V_68 ;
V_2 -> V_74 = V_75 ;
V_2 -> V_76 = F_1 ;
V_2 -> V_77 = F_8 ;
V_2 -> V_78 = F_9 ;
V_2 -> V_79 = F_4 ;
V_2 -> V_80 = F_7 ;
V_2 -> type = V_81 ;
V_2 -> V_82 = L_67 ;
V_2 -> V_83 = 0x10000 ;
V_2 -> V_84 = 1 ;
V_2 -> V_85 = V_86 ;
if ( F_27 ( V_2 , NULL , 0 ) ) {
F_3 ( V_69 L_68 ) ;
F_28 ( V_65 , V_6 -> V_29 ) ;
F_25 ( V_2 -> V_6 ) ;
F_25 ( V_2 ) ;
break;
}
F_29 ( V_65 ) ;
F_3 ( V_69 L_69 ) ;
F_3 ( V_69 L_70 ,
V_6 -> V_17 >> 20 ,
V_6 -> V_29 , V_6 -> V_29 + V_6 -> V_17 ) ;
F_3 ( V_69 L_71 ,
( V_67 < 1024 ) ? V_67 :
( V_67 < 1048576 ) ? V_67 >> 10 : V_67 >> 20 ,
( V_67 < 1024 ) ? L_15 : ( V_67 < 1048576 ) ? L_16 : L_17 ) ;
V_6 -> V_87 = V_88 ;
V_88 = V_2 ;
V_66 ++ ;
}
if ( V_65 )
F_30 ( V_65 ) ;
if ( ! V_88 ) {
F_3 ( V_69 L_72 ) ;
return - V_44 ;
} else {
F_3 ( V_69 L_73 , V_66 ) ;
return 0 ;
}
}
static void T_9 F_31 ( void )
{
int V_66 = 0 ;
struct V_1 * V_2 ;
struct V_5 * V_6 ;
while ( ( V_2 = V_88 ) ) {
V_6 = V_2 -> V_6 ;
V_88 = V_6 -> V_87 ;
if ( V_6 -> V_29 ) {
F_3 ( V_14 L_74
L_75 , V_6 -> V_17 >> 20 , V_6 -> V_29 ) ;
F_28 ( V_6 -> V_27 , V_6 -> V_29 ) ;
}
F_30 ( V_6 -> V_27 ) ;
F_25 ( V_2 -> V_6 ) ;
F_32 ( V_2 ) ;
F_25 ( V_2 ) ;
V_66 ++ ;
}
F_3 ( V_69 L_76 , V_66 ) ;
}
