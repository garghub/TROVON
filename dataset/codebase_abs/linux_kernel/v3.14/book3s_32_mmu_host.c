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
if ( V_2 -> V_13 . V_14 -> V_15 & V_16 )
V_7 |= V_17 ;
V_12 = F_2 ( V_2 , V_7 ) ;
V_11 = & F_4 ( V_2 ) -> V_18 [ V_12 ] ;
if ( V_11 -> V_19 == V_7 ) {
F_5 ( L_1 ,
V_7 , V_11 -> V_20 ) ;
return V_11 ;
}
V_11 = & F_4 ( V_2 ) -> V_18 [ V_9 - V_12 ] ;
if ( V_11 -> V_19 == V_7 ) {
F_5 ( L_1 ,
V_7 , V_11 -> V_20 ) ;
return V_11 ;
}
F_5 ( L_2 , V_7 ) ;
return NULL ;
}
static T_1 * F_6 ( struct V_1 * V_2 , T_1 V_21 , T_1 V_22 ,
bool V_23 )
{
T_1 V_24 , V_25 ;
T_4 V_5 = V_26 ;
V_24 = ( V_22 & ~ V_27 ) >> 12 ;
V_25 = ( ( V_21 ^ V_24 ) << 6 ) ;
if ( ! V_23 )
V_25 = ~ V_25 ;
V_25 &= V_28 ;
V_5 |= V_25 ;
F_7 ( L_3 ,
V_26 , V_25 , V_28 , V_5 ) ;
return ( T_1 * ) V_5 ;
}
int F_8 ( struct V_1 * V_2 , struct V_29 * V_30 ,
bool V_31 )
{
T_5 V_32 ;
T_3 V_33 ;
T_3 V_21 ;
struct V_10 * V_11 ;
volatile T_1 * V_5 ;
T_1 V_22 = V_30 -> V_22 ;
T_1 V_34 , V_35 ;
register int V_36 = 0 ;
bool V_23 = false ;
bool V_37 = false ;
struct V_3 * V_4 ;
int V_38 = 0 ;
bool V_39 ;
V_32 = F_9 ( V_2 , V_30 -> V_40 >> V_41 ,
V_31 , & V_39 ) ;
if ( F_10 ( V_32 ) ) {
F_11 ( V_42 L_4 ,
V_30 -> V_22 ) ;
V_38 = - V_43 ;
goto V_44;
}
V_32 <<= V_41 ;
V_2 -> V_13 . V_45 . V_46 ( V_2 , V_30 -> V_22 >> V_47 , & V_21 ) ;
V_11 = F_3 ( V_2 , V_21 ) ;
if ( ! V_11 ) {
F_12 ( V_2 , V_22 ) ;
V_11 = F_3 ( V_2 , V_21 ) ;
}
F_13 ( ! V_11 ) ;
V_21 = V_11 -> V_20 ;
V_33 = ( V_21 << ( V_47 - V_48 ) ) |
( ( V_22 & ~ V_27 ) >> V_48 ) ;
V_49:
if ( V_36 == 16 ) {
V_23 = ! V_23 ;
V_37 = true ;
V_36 = 0 ;
}
V_5 = F_6 ( V_2 , V_21 , V_22 , V_23 ) ;
if ( ! V_37 && ( V_5 [ V_36 ] & V_50 ) ) {
V_36 += 2 ;
goto V_49;
}
F_7 ( L_5 , V_5 , V_36 ) ;
F_7 ( L_6 , V_5 [ 0 ] , V_5 [ 1 ] ) ;
F_7 ( L_6 , V_5 [ 2 ] , V_5 [ 3 ] ) ;
F_7 ( L_6 , V_5 [ 4 ] , V_5 [ 5 ] ) ;
F_7 ( L_6 , V_5 [ 6 ] , V_5 [ 7 ] ) ;
F_7 ( L_6 , V_5 [ 8 ] , V_5 [ 9 ] ) ;
F_7 ( L_6 , V_5 [ 10 ] , V_5 [ 11 ] ) ;
F_7 ( L_6 , V_5 [ 12 ] , V_5 [ 13 ] ) ;
F_7 ( L_6 , V_5 [ 14 ] , V_5 [ 15 ] ) ;
V_34 = ( ( V_22 & 0x0fffffff ) >> 22 ) | ( V_21 << 7 ) | V_50 |
( V_23 ? 0 : V_51 ) ;
V_35 = V_32 | V_52 | V_53 | V_54 ;
if ( V_30 -> V_55 && V_39 ) {
V_35 |= V_56 ;
F_14 ( V_2 -> V_57 , V_30 -> V_40 >> V_41 ) ;
} else {
V_35 |= V_58 ;
}
if ( V_30 -> V_59 )
F_15 ( V_32 >> V_41 ) ;
F_16 () ;
if ( V_5 [ V_36 ] ) {
V_5 [ V_36 ] = 0 ;
asm volatile ("sync");
}
V_5 [ V_36 + 1 ] = V_35 ;
V_5 [ V_36 ] = V_34 ;
asm volatile ("sync");
F_17 () ;
F_7 ( L_7 , V_5 ) ;
F_7 ( L_6 , V_5 [ 0 ] , V_5 [ 1 ] ) ;
F_7 ( L_6 , V_5 [ 2 ] , V_5 [ 3 ] ) ;
F_7 ( L_6 , V_5 [ 4 ] , V_5 [ 5 ] ) ;
F_7 ( L_6 , V_5 [ 6 ] , V_5 [ 7 ] ) ;
F_7 ( L_6 , V_5 [ 8 ] , V_5 [ 9 ] ) ;
F_7 ( L_6 , V_5 [ 10 ] , V_5 [ 11 ] ) ;
F_7 ( L_6 , V_5 [ 12 ] , V_5 [ 13 ] ) ;
F_7 ( L_6 , V_5 [ 14 ] , V_5 [ 15 ] ) ;
V_4 = F_18 ( V_2 ) ;
if ( ! V_4 ) {
F_19 ( V_32 >> V_41 ) ;
V_38 = - V_60 ;
goto V_44;
}
F_7 ( L_8 ,
V_30 -> V_55 ? 'w' : '-' ,
V_30 -> V_59 ? 'x' : '-' ,
V_30 -> V_22 , ( T_4 ) V_5 , V_33 ,
V_30 -> V_61 , V_32 ) ;
V_4 -> V_6 = ( T_4 ) & V_5 [ V_36 ] ;
V_4 -> V_62 = V_33 ;
V_4 -> V_4 = * V_30 ;
V_4 -> V_63 = V_32 >> V_41 ;
F_20 ( V_2 , V_4 ) ;
F_19 ( V_32 >> V_41 ) ;
V_44:
return V_38 ;
}
void F_21 ( struct V_1 * V_2 , struct V_29 * V_4 )
{
F_22 ( V_2 , V_4 -> V_61 , 0xfffffffffULL ) ;
}
static struct V_10 * F_23 ( struct V_1 * V_2 , T_3 V_7 )
{
struct V_10 * V_11 ;
struct V_64 * V_65 = F_4 ( V_2 ) ;
T_2 V_12 ;
static int V_66 = 0 ;
if ( V_2 -> V_13 . V_14 -> V_15 & V_16 )
V_7 |= V_17 ;
V_12 = F_2 ( V_2 , V_7 ) ;
if ( V_66 )
V_12 = V_9 - V_12 ;
V_11 = & F_4 ( V_2 ) -> V_18 [ V_12 ] ;
V_66 = ! V_66 ;
if ( V_65 -> V_67 >= V_68 ) {
V_65 -> V_67 = 0 ;
memset ( V_65 -> V_18 , 0 ,
sizeof( struct V_10 ) * V_69 ) ;
F_24 ( V_2 , 0 , 0 ) ;
F_25 ( V_2 ) ;
}
V_11 -> V_20 = V_65 -> V_70 [ V_65 -> V_67 ] ;
V_65 -> V_67 ++ ;
V_11 -> V_19 = V_7 ;
V_11 -> V_71 = true ;
return V_11 ;
}
int F_12 ( struct V_1 * V_2 , T_4 V_22 )
{
T_1 V_72 = V_22 >> V_47 ;
T_3 V_7 ;
T_1 V_73 ;
struct V_10 * V_11 ;
struct V_74 * V_75 = F_26 ( V_2 ) ;
int V_38 = 0 ;
if ( V_2 -> V_13 . V_45 . V_46 ( V_2 , V_72 , & V_7 ) ) {
V_75 -> V_73 [ V_72 ] = V_76 ;
V_38 = - V_77 ;
goto V_44;
}
V_11 = F_3 ( V_2 , V_7 ) ;
if ( ! V_11 )
V_11 = F_23 ( V_2 , V_7 ) ;
V_11 -> V_78 = V_72 ;
V_73 = V_11 -> V_20 | V_79 ;
V_75 -> V_73 [ V_72 ] = V_73 ;
F_5 ( L_9 , V_72 , V_73 ) ;
V_44:
F_27 ( V_75 ) ;
return V_38 ;
}
void F_25 ( struct V_1 * V_2 )
{
int V_80 ;
struct V_74 * V_75 = F_26 ( V_2 ) ;
F_5 ( L_10 , F_28 ( V_75 -> V_73 ) ) ;
for ( V_80 = 0 ; V_80 < F_28 ( V_75 -> V_73 ) ; V_80 ++ )
V_75 -> V_73 [ V_80 ] = V_76 ;
F_27 ( V_75 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
int V_80 ;
F_30 ( V_2 ) ;
F_31 () ;
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ )
F_32 ( F_4 ( V_2 ) -> V_82 [ V_80 ] ) ;
F_33 () ;
}
int F_34 ( struct V_1 * V_2 )
{
struct V_64 * V_83 = F_4 ( V_2 ) ;
int V_84 ;
T_4 V_85 ;
int V_80 ;
int V_86 ;
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ ) {
V_84 = F_35 () ;
if ( V_84 < 0 )
goto V_87;
V_83 -> V_82 [ V_80 ] = V_84 ;
for ( V_86 = 0 ; V_86 < 16 ; V_86 ++ )
V_83 -> V_70 [ ( V_80 * 16 ) + V_86 ] = F_36 ( V_84 , V_86 ) ;
}
V_83 -> V_67 = 0 ;
asm ( "mfsdr1 %0" : "=r"(sdr1) );
V_28 = ( ( V_85 & 0x1FF ) << 16 ) | 0xFFC0 ;
V_26 = ( T_4 ) F_37 ( V_85 & 0xffff0000 ) ;
F_38 ( V_2 ) ;
return 0 ;
V_87:
for ( V_86 = 0 ; V_86 < V_80 ; V_86 ++ ) {
if ( ! V_83 -> V_82 [ V_86 ] )
continue;
F_32 ( F_4 ( V_2 ) -> V_82 [ V_86 ] ) ;
}
return - 1 ;
}
