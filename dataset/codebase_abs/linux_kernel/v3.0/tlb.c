void T_1
F_1 ( void )
{
V_1 . V_2 = F_2 ( ( V_1 . V_3 + 1 ) >> 3 ) ;
V_1 . V_4 = F_2 ( ( V_1 . V_3 + 1 ) >> 3 ) ;
}
void
F_3 ( struct V_5 * V_6 )
{
int V_7 , V_8 ;
unsigned long V_9 ;
for ( V_7 = 0 ; V_7 <= V_1 . V_3 / V_10 ; V_7 ++ ) {
V_9 = F_4 ( & V_1 . V_4 [ V_7 ] , 0 ) ;
V_1 . V_2 [ V_7 ] ^= V_9 ;
}
V_1 . V_11 = F_5 ( V_1 . V_2 ,
V_1 . V_3 , 300 ) ;
V_1 . V_12 = F_6 ( V_1 . V_2 ,
V_1 . V_3 , V_1 . V_11 ) ;
V_8 = F_7 () ;
F_8 (i)
if ( V_7 != V_8 )
F_9 ( V_13 , V_7 ) = 1 ;
F_10 () ;
F_11 () ;
}
static inline void F_12 ( struct V_14 * V_15 , int V_16 )
{
V_15 -> V_17 = 0 ;
V_15 -> V_18 = V_16 ;
}
static inline void F_13 ( struct V_14 * V_15 )
{
unsigned long V_19 = F_14 ( 1 , & V_15 -> V_17 , V_20 ) , V_18 ;
if ( F_15 ( V_19 , V_15 -> V_18 ) )
return;
F_16 () ;
for (; ; ) {
asm volatile ("ld8.c.nc %0=[%1]" : "=r"(serve) : "r"(&ss->serve) : "memory");
if ( F_15 ( V_19 , V_18 ) )
return;
F_17 () ;
}
}
static inline void F_18 ( struct V_14 * V_15 )
{
F_14 ( 1 , & V_15 -> V_18 , V_21 ) ;
}
static int T_1
F_19 ( char * V_22 )
{
int V_23 = 0 ;
F_20 ( & V_22 , & V_23 ) ;
F_21 ( V_23 , V_24 ) ;
return 1 ;
}
void
F_21 ( int V_25 , int V_26 )
{
static int V_27 ;
static int V_28 ;
static int V_29 = 1 ;
if ( V_30 ) {
if ( V_26 == V_31 && V_25 == 0 )
F_22 ( 1 < V_32 ) ;
else
F_22 ( V_25 < V_32 ) ;
return;
}
if ( V_26 == V_24 ) {
V_27 = 1 ;
V_32 = V_25 ;
goto V_33;
}
if ( V_27 ) {
V_34 = F_23 () > V_32 ;
return;
}
if ( V_26 == V_35 ) {
V_28 = 1 ;
if ( V_25 == 0 )
F_24 ( L_1 ) ;
V_32 = V_25 ;
if ( V_32 == V_36 ) {
V_34 = 0 ;
return;
}
goto V_33;
}
if ( V_28 ) {
if ( V_32 != V_36 )
V_34 = ( F_23 () > V_32 ) ;
return;
}
if ( V_25 == 0 ) V_25 = 1 ;
if ( V_29 ) {
V_32 = V_25 ;
V_29 = 0 ;
}
if ( V_25 < V_32 )
V_32 = V_25 ;
if ( V_32 == V_37 ) {
V_34 = 0 ;
return;
} else
V_34 = ( F_23 () > V_32 ) ;
V_33:
F_12 ( & V_38 , V_25 ) ;
}
void
F_25 ( struct V_5 * V_6 , unsigned long V_39 ,
unsigned long V_40 , unsigned long V_41 )
{
struct V_5 * V_42 = V_43 -> V_42 ;
V_30 = 1 ;
if ( V_6 != V_42 ) {
if ( V_6 && V_42 ) {
F_26 ( V_6 ) ;
} else {
F_27 () ;
return;
}
}
if ( V_34 )
F_13 ( & V_38 ) ;
do {
F_28 ( V_39 , ( V_41 << 2 ) ) ;
F_29 () ;
V_39 += ( 1UL << V_41 ) ;
} while ( V_39 < V_40 );
if ( V_34 )
F_18 ( & V_38 ) ;
if ( V_6 != V_42 ) {
F_26 ( V_42 ) ;
}
}
void
F_11 ( void )
{
unsigned long V_7 , V_44 , V_45 , V_46 , V_47 , V_48 , V_49 , V_50 ;
V_50 = V_51 -> V_52 ;
V_46 = V_51 -> V_53 [ 0 ] ;
V_47 = V_51 -> V_53 [ 1 ] ;
V_48 = V_51 -> V_54 [ 0 ] ;
V_49 = V_51 -> V_54 [ 1 ] ;
F_30 ( V_45 ) ;
for ( V_7 = 0 ; V_7 < V_46 ; ++ V_7 ) {
for ( V_44 = 0 ; V_44 < V_47 ; ++ V_44 ) {
F_31 ( V_50 ) ;
V_50 += V_49 ;
}
V_50 += V_48 ;
}
F_32 ( V_45 ) ;
F_29 () ;
}
void
F_33 ( struct V_55 * V_56 , unsigned long V_39 ,
unsigned long V_40 )
{
struct V_5 * V_6 = V_56 -> V_57 ;
unsigned long V_58 = V_40 - V_39 ;
unsigned long V_41 ;
#ifndef F_34
if ( V_6 != V_43 -> V_42 ) {
V_6 -> V_59 = 0 ;
return;
}
#endif
V_41 = F_35 ( V_58 + 0xfff ) ;
while ( F_36 ( ( ( 1UL << V_41 ) & V_60 . V_61 ) == 0 ) &&
( V_41 < V_60 . V_62 ) )
++ V_41 ;
if ( V_41 > V_60 . V_62 )
V_41 = V_60 . V_62 ;
V_39 &= ~ ( ( 1UL << V_41 ) - 1 ) ;
F_37 () ;
#ifdef F_34
if ( V_6 != V_43 -> V_42 || F_38 ( F_39 ( V_6 ) ) != 1 ) {
F_40 ( V_6 , V_39 , V_40 , V_41 ) ;
F_41 () ;
return;
}
#endif
do {
F_42 ( V_39 , ( V_41 << 2 ) ) ;
V_39 += ( 1UL << V_41 ) ;
} while ( V_39 < V_40 );
F_41 () ;
F_29 () ;
}
void T_2
F_43 ( void )
{
T_3 V_63 ( V_64 ) ;
T_4 V_65 ;
long V_66 ;
T_5 V_67 ;
T_6 V_68 ;
int V_8 = F_44 () ;
if ( ( V_66 = F_45 ( & V_65 , & V_60 . V_61 ) ) != 0 ) {
F_46 ( V_69 L_2
L_3 , V_66 ) ;
V_60 . V_61 = 0x115557000UL ;
}
V_60 . V_62 = F_35 ( V_60 . V_61 ) ;
F_47 ( & V_64 ) ;
V_51 -> V_52 = V_64 . V_70 ;
V_51 -> V_53 [ 0 ] = V_64 . V_71 [ 0 ] ;
V_51 -> V_53 [ 1 ] = V_64 . V_71 [ 1 ] ;
V_51 -> V_54 [ 0 ] = V_64 . V_72 [ 0 ] ;
V_51 -> V_54 [ 1 ] = V_64 . V_72 [ 1 ] ;
F_11 () ;
V_66 = F_48 ( & V_67 , & V_68 ) ;
if ( V_66 ) {
F_46 ( V_69 L_4 , V_66 ) ;
F_9 ( V_73 , V_8 ) = 8 ;
return;
}
F_9 ( V_73 , V_8 ) = V_67 . V_74 . V_75 + 1 ;
if ( F_9 ( V_73 , V_8 ) >
( V_67 . V_74 . V_76 + 1 ) )
F_9 ( V_73 , V_8 ) =
V_67 . V_74 . V_76 + 1 ;
if ( F_9 ( V_73 , V_8 ) > V_77 ) {
static int V_78 = 1 ;
F_9 ( V_73 , V_8 ) = V_77 ;
if ( V_78 ) {
V_78 = 0 ;
F_46 ( V_79 L_5
L_6 ) ;
}
}
}
static int F_49 ( struct V_80 * V_81 , T_4 V_82 , T_4 V_83 )
{
T_4 V_84 ;
T_4 V_85 ;
T_4 V_86 = F_50 ( V_82 ) ;
T_4 V_87 = F_51 ( V_86 ) ;
T_4 va_end = V_82 + ( 1 << V_83 ) - 1 ;
if ( V_87 != F_51 ( V_81 -> V_88 ) )
return 0 ;
V_84 = ( V_81 -> V_89 & 0xff ) >> 2 ;
V_85 = V_81 -> V_90 + ( 1 << V_84 ) - 1 ;
if ( V_82 > V_85 || V_81 -> V_90 > va_end )
return 0 ;
return 1 ;
}
int F_52 ( T_4 V_91 , T_4 V_82 , T_4 V_92 , T_4 V_83 )
{
int V_7 , V_93 ;
unsigned long V_94 ;
struct V_80 * V_81 ;
int V_8 = F_44 () ;
if ( ! V_95 [ V_8 ] ) {
V_95 [ V_8 ] = F_53 ( 2 * V_77 *
sizeof ( struct V_80 ) , V_96 ) ;
if ( ! V_95 [ V_8 ] )
return - V_97 ;
}
V_93 = - V_98 ;
if ( V_91 & 0x1 ) {
V_81 = V_95 [ V_8 ] ;
for ( V_7 = V_99 ; V_7 <= F_9 ( V_100 , V_8 ) ;
V_7 ++ , V_81 ++ ) {
if ( V_81 -> V_92 & 0x1 )
if ( F_49 ( V_81 , V_82 , V_83 ) ) {
F_46 ( V_79 L_7
L_8 ) ;
goto V_101;
}
}
}
if ( V_91 & 0x2 ) {
V_81 = V_95 [ V_8 ] + V_77 ;
for ( V_7 = V_99 ; V_7 <= F_9 ( V_100 , V_8 ) ;
V_7 ++ , V_81 ++ ) {
if ( V_81 -> V_92 & 0x1 )
if ( F_49 ( V_81 , V_82 , V_83 ) ) {
F_46 ( V_79 L_7
L_8 ) ;
goto V_101;
}
}
}
for ( V_7 = V_99 ; V_7 < F_9 ( V_73 , V_8 ) ; V_7 ++ ) {
switch ( V_91 & 0x3 ) {
case 1 :
if ( ! ( ( V_95 [ V_8 ] + V_7 ) -> V_92 & 0x1 ) )
goto V_102;
continue;
case 2 :
if ( ! ( ( V_95 [ V_8 ] + V_77 + V_7 ) -> V_92 & 0x1 ) )
goto V_102;
continue;
case 3 :
if ( ! ( ( V_95 [ V_8 ] + V_7 ) -> V_92 & 0x1 ) &&
! ( ( V_95 [ V_8 ] + V_77 + V_7 ) -> V_92 & 0x1 ) )
goto V_102;
continue;
default:
V_93 = - V_98 ;
goto V_101;
}
}
V_102:
if ( V_7 >= F_9 ( V_73 , V_8 ) )
return - V_103 ;
if ( V_7 > F_9 ( V_100 , V_8 ) )
F_9 ( V_100 , V_8 ) = V_7 ;
V_94 = F_54 () ;
if ( V_91 & 0x1 ) {
F_55 ( 0x1 , V_7 , V_82 , V_92 , V_83 ) ;
F_29 () ;
V_81 = V_95 [ V_8 ] + V_7 ;
V_81 -> V_90 = V_82 ;
V_81 -> V_92 = V_92 ;
V_81 -> V_89 = V_83 << 2 ;
V_81 -> V_88 = F_50 ( V_82 ) ;
}
if ( V_91 & 0x2 ) {
F_55 ( 0x2 , V_7 , V_82 , V_92 , V_83 ) ;
F_29 () ;
V_81 = V_95 [ V_8 ] + V_77 + V_7 ;
V_81 -> V_90 = V_82 ;
V_81 -> V_92 = V_92 ;
V_81 -> V_89 = V_83 << 2 ;
V_81 -> V_88 = F_50 ( V_82 ) ;
}
F_56 ( V_94 ) ;
V_93 = V_7 ;
V_101:
return V_93 ;
}
void F_57 ( T_4 V_91 , int V_104 )
{
int V_8 = F_44 () ;
int V_7 ;
struct V_80 * V_81 ;
if ( V_104 < V_99 || V_104 >= F_9 ( V_73 , V_8 ) )
return;
if ( V_91 & 0x1 ) {
V_81 = V_95 [ V_8 ] + V_104 ;
if ( ( V_81 -> V_92 & 0x1 ) && F_49 ( V_81 , V_81 -> V_90 , V_81 -> V_89 >> 2 ) ) {
V_81 -> V_92 = 0 ;
F_58 ( 0x1 , V_81 -> V_90 , V_81 -> V_89 >> 2 ) ;
F_29 () ;
}
}
if ( V_91 & 0x2 ) {
V_81 = V_95 [ V_8 ] + V_77 + V_104 ;
if ( ( V_81 -> V_92 & 0x1 ) && F_49 ( V_81 , V_81 -> V_90 , V_81 -> V_89 >> 2 ) ) {
V_81 -> V_92 = 0 ;
F_58 ( 0x2 , V_81 -> V_90 , V_81 -> V_89 >> 2 ) ;
F_29 () ;
}
}
for ( V_7 = F_9 ( V_100 , V_8 ) ; V_7 >= V_99 ; V_7 -- ) {
if ( ( ( V_95 [ V_8 ] + V_7 ) -> V_92 & 0x1 ) ||
( ( V_95 [ V_8 ] + V_77 + V_7 ) -> V_92 & 0x1 ) )
break;
}
F_9 ( V_100 , V_8 ) = V_7 ;
}
