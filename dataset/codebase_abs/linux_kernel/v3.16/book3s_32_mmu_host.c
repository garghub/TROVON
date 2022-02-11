void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
volatile T_1 * V_5 ;
V_5 = ( T_1 * ) V_4 -> V_6 ;
V_5 [ 0 ] = 0 ;
asm volatile ("sync");
asm volatile ("tlbie %0" : : "r" (pte->pte.eaddr) : "memory");
asm volatile ("sync");
asm volatile ("tlbsync");
}
static T_2 F_2 ( struct V_1 * V_2 , T_3 V_7 )
{
return ( T_2 ) ( ( ( V_7 >> ( V_8 * 7 ) ) & V_9 ) ^
( ( V_7 >> ( V_8 * 6 ) ) & V_9 ) ^
( ( V_7 >> ( V_8 * 5 ) ) & V_9 ) ^
( ( V_7 >> ( V_8 * 4 ) ) & V_9 ) ^
( ( V_7 >> ( V_8 * 3 ) ) & V_9 ) ^
( ( V_7 >> ( V_8 * 2 ) ) & V_9 ) ^
( ( V_7 >> ( V_8 * 1 ) ) & V_9 ) ^
( ( V_7 >> ( V_8 * 0 ) ) & V_9 ) ) ;
}
static struct V_10 * F_3 ( struct V_1 * V_2 , T_3 V_7 )
{
struct V_10 * V_11 ;
T_2 V_12 ;
if ( F_4 ( V_2 ) & V_13 )
V_7 |= V_14 ;
V_12 = F_2 ( V_2 , V_7 ) ;
V_11 = & F_5 ( V_2 ) -> V_15 [ V_12 ] ;
if ( V_11 -> V_16 == V_7 ) {
F_6 ( L_1 ,
V_7 , V_11 -> V_17 ) ;
return V_11 ;
}
V_11 = & F_5 ( V_2 ) -> V_15 [ V_9 - V_12 ] ;
if ( V_11 -> V_16 == V_7 ) {
F_6 ( L_1 ,
V_7 , V_11 -> V_17 ) ;
return V_11 ;
}
F_6 ( L_2 , V_7 ) ;
return NULL ;
}
static T_1 * F_7 ( struct V_1 * V_2 , T_1 V_18 , T_1 V_19 ,
bool V_20 )
{
T_1 V_21 , V_22 ;
T_4 V_5 = V_23 ;
V_21 = ( V_19 & ~ V_24 ) >> 12 ;
V_22 = ( ( V_18 ^ V_21 ) << 6 ) ;
if ( ! V_20 )
V_22 = ~ V_22 ;
V_22 &= V_25 ;
V_5 |= V_22 ;
F_8 ( L_3 ,
V_23 , V_22 , V_25 , V_5 ) ;
return ( T_1 * ) V_5 ;
}
int F_9 ( struct V_1 * V_2 , struct V_26 * V_27 ,
bool V_28 )
{
T_5 V_29 ;
T_3 V_30 ;
T_3 V_18 ;
struct V_10 * V_11 ;
volatile T_1 * V_5 ;
T_1 V_19 = V_27 -> V_19 ;
T_1 V_31 , V_32 ;
register int V_33 = 0 ;
bool V_20 = false ;
bool V_34 = false ;
struct V_3 * V_4 ;
int V_35 = 0 ;
bool V_36 ;
V_29 = F_10 ( V_2 , V_27 -> V_37 >> V_38 ,
V_28 , & V_36 ) ;
if ( F_11 ( V_29 ) ) {
F_12 ( V_39 L_4 ,
V_27 -> V_19 ) ;
V_35 = - V_40 ;
goto V_41;
}
V_29 <<= V_38 ;
V_2 -> V_42 . V_43 . V_44 ( V_2 , V_27 -> V_19 >> V_45 , & V_18 ) ;
V_11 = F_3 ( V_2 , V_18 ) ;
if ( ! V_11 ) {
F_13 ( V_2 , V_19 ) ;
V_11 = F_3 ( V_2 , V_18 ) ;
}
F_14 ( ! V_11 ) ;
V_18 = V_11 -> V_17 ;
V_30 = ( V_18 << ( V_45 - V_46 ) ) |
( ( V_19 & ~ V_24 ) >> V_46 ) ;
V_47:
if ( V_33 == 16 ) {
V_20 = ! V_20 ;
V_34 = true ;
V_33 = 0 ;
}
V_5 = F_7 ( V_2 , V_18 , V_19 , V_20 ) ;
if ( ! V_34 && ( V_5 [ V_33 ] & V_48 ) ) {
V_33 += 2 ;
goto V_47;
}
F_8 ( L_5 , V_5 , V_33 ) ;
F_8 ( L_6 , V_5 [ 0 ] , V_5 [ 1 ] ) ;
F_8 ( L_6 , V_5 [ 2 ] , V_5 [ 3 ] ) ;
F_8 ( L_6 , V_5 [ 4 ] , V_5 [ 5 ] ) ;
F_8 ( L_6 , V_5 [ 6 ] , V_5 [ 7 ] ) ;
F_8 ( L_6 , V_5 [ 8 ] , V_5 [ 9 ] ) ;
F_8 ( L_6 , V_5 [ 10 ] , V_5 [ 11 ] ) ;
F_8 ( L_6 , V_5 [ 12 ] , V_5 [ 13 ] ) ;
F_8 ( L_6 , V_5 [ 14 ] , V_5 [ 15 ] ) ;
V_31 = ( ( V_19 & 0x0fffffff ) >> 22 ) | ( V_18 << 7 ) | V_48 |
( V_20 ? 0 : V_49 ) ;
V_32 = V_29 | V_50 | V_51 | V_52 ;
if ( V_27 -> V_53 && V_36 ) {
V_32 |= V_54 ;
F_15 ( V_2 -> V_55 , V_27 -> V_37 >> V_38 ) ;
} else {
V_32 |= V_56 ;
}
if ( V_27 -> V_57 )
F_16 ( V_29 >> V_38 ) ;
F_17 () ;
if ( V_5 [ V_33 ] ) {
V_5 [ V_33 ] = 0 ;
asm volatile ("sync");
}
V_5 [ V_33 + 1 ] = V_32 ;
V_5 [ V_33 ] = V_31 ;
asm volatile ("sync");
F_18 () ;
F_8 ( L_7 , V_5 ) ;
F_8 ( L_6 , V_5 [ 0 ] , V_5 [ 1 ] ) ;
F_8 ( L_6 , V_5 [ 2 ] , V_5 [ 3 ] ) ;
F_8 ( L_6 , V_5 [ 4 ] , V_5 [ 5 ] ) ;
F_8 ( L_6 , V_5 [ 6 ] , V_5 [ 7 ] ) ;
F_8 ( L_6 , V_5 [ 8 ] , V_5 [ 9 ] ) ;
F_8 ( L_6 , V_5 [ 10 ] , V_5 [ 11 ] ) ;
F_8 ( L_6 , V_5 [ 12 ] , V_5 [ 13 ] ) ;
F_8 ( L_6 , V_5 [ 14 ] , V_5 [ 15 ] ) ;
V_4 = F_19 ( V_2 ) ;
if ( ! V_4 ) {
F_20 ( V_29 >> V_38 ) ;
V_35 = - V_58 ;
goto V_41;
}
F_8 ( L_8 ,
V_27 -> V_53 ? 'w' : '-' ,
V_27 -> V_57 ? 'x' : '-' ,
V_27 -> V_19 , ( T_4 ) V_5 , V_30 ,
V_27 -> V_59 , V_29 ) ;
V_4 -> V_6 = ( T_4 ) & V_5 [ V_33 ] ;
V_4 -> V_60 = V_30 ;
V_4 -> V_4 = * V_27 ;
V_4 -> V_61 = V_29 >> V_38 ;
F_21 ( V_2 , V_4 ) ;
F_20 ( V_29 >> V_38 ) ;
V_41:
return V_35 ;
}
void F_22 ( struct V_1 * V_2 , struct V_26 * V_4 )
{
F_23 ( V_2 , V_4 -> V_59 , 0xfffffffffULL ) ;
}
static struct V_10 * F_24 ( struct V_1 * V_2 , T_3 V_7 )
{
struct V_10 * V_11 ;
struct V_62 * V_63 = F_5 ( V_2 ) ;
T_2 V_12 ;
static int V_64 = 0 ;
if ( F_4 ( V_2 ) & V_13 )
V_7 |= V_14 ;
V_12 = F_2 ( V_2 , V_7 ) ;
if ( V_64 )
V_12 = V_9 - V_12 ;
V_11 = & F_5 ( V_2 ) -> V_15 [ V_12 ] ;
V_64 = ! V_64 ;
if ( V_63 -> V_65 >= V_66 ) {
V_63 -> V_65 = 0 ;
memset ( V_63 -> V_15 , 0 ,
sizeof( struct V_10 ) * V_67 ) ;
F_25 ( V_2 , 0 , 0 ) ;
F_26 ( V_2 ) ;
}
V_11 -> V_17 = V_63 -> V_68 [ V_63 -> V_65 ] ;
V_63 -> V_65 ++ ;
V_11 -> V_16 = V_7 ;
V_11 -> V_69 = true ;
return V_11 ;
}
int F_13 ( struct V_1 * V_2 , T_4 V_19 )
{
T_1 V_70 = V_19 >> V_45 ;
T_3 V_7 ;
T_1 V_71 ;
struct V_10 * V_11 ;
struct V_72 * V_73 = F_27 ( V_2 ) ;
int V_35 = 0 ;
if ( V_2 -> V_42 . V_43 . V_44 ( V_2 , V_70 , & V_7 ) ) {
V_73 -> V_71 [ V_70 ] = V_74 ;
V_35 = - V_75 ;
goto V_41;
}
V_11 = F_3 ( V_2 , V_7 ) ;
if ( ! V_11 )
V_11 = F_24 ( V_2 , V_7 ) ;
V_11 -> V_76 = V_70 ;
V_71 = V_11 -> V_17 | V_77 ;
V_73 -> V_71 [ V_70 ] = V_71 ;
F_6 ( L_9 , V_70 , V_71 ) ;
V_41:
F_28 ( V_73 ) ;
return V_35 ;
}
void F_26 ( struct V_1 * V_2 )
{
int V_78 ;
struct V_72 * V_73 = F_27 ( V_2 ) ;
F_6 ( L_10 , F_29 ( V_73 -> V_71 ) ) ;
for ( V_78 = 0 ; V_78 < F_29 ( V_73 -> V_71 ) ; V_78 ++ )
V_73 -> V_71 [ V_78 ] = V_74 ;
F_28 ( V_73 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
int V_78 ;
F_31 ( V_2 ) ;
F_32 () ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ )
F_33 ( F_5 ( V_2 ) -> V_80 [ V_78 ] ) ;
F_34 () ;
}
int F_35 ( struct V_1 * V_2 )
{
struct V_62 * V_81 = F_5 ( V_2 ) ;
int V_82 ;
T_4 V_83 ;
int V_78 ;
int V_84 ;
for ( V_78 = 0 ; V_78 < V_79 ; V_78 ++ ) {
V_82 = F_36 () ;
if ( V_82 < 0 )
goto V_85;
V_81 -> V_80 [ V_78 ] = V_82 ;
for ( V_84 = 0 ; V_84 < 16 ; V_84 ++ )
V_81 -> V_68 [ ( V_78 * 16 ) + V_84 ] = F_37 ( V_82 , V_84 ) ;
}
V_81 -> V_65 = 0 ;
asm ( "mfsdr1 %0" : "=r"(sdr1) );
V_25 = ( ( V_83 & 0x1FF ) << 16 ) | 0xFFC0 ;
V_23 = ( T_4 ) F_38 ( V_83 & 0xffff0000 ) ;
F_39 ( V_2 ) ;
return 0 ;
V_85:
for ( V_84 = 0 ; V_84 < V_78 ; V_84 ++ ) {
if ( ! V_81 -> V_80 [ V_84 ] )
continue;
F_33 ( F_5 ( V_2 ) -> V_80 [ V_84 ] ) ;
}
return - 1 ;
}
