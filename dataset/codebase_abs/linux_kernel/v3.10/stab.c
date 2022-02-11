static int F_1 ( unsigned long V_1 , unsigned long V_2 , unsigned long V_3 )
{
unsigned long V_4 , V_5 ;
unsigned long V_6 , V_7 , V_8 , V_9 , V_10 ;
unsigned int V_11 ;
struct V_12 * V_13 , * V_14 ;
unsigned long V_15 = ( V_2 << V_16 ) >= V_17 ;
V_5 = V_3 << V_18 ;
V_4 = V_2 << V_16 | V_19 | V_20 ;
if ( ! V_15 )
V_4 |= V_21 ;
V_11 = ( V_2 & 0x1f ) << 3 ;
V_13 = (struct V_12 * ) ( V_1 | ( ( V_2 & 0x1f ) << 7 ) ) ;
for ( V_7 = 0 ; V_7 < 2 ; V_7 ++ ) {
for ( V_6 = 0 ; V_6 < 8 ; V_6 ++ , V_13 ++ ) {
if ( ! ( V_13 -> V_4 & V_20 ) ) {
V_13 -> V_5 = V_5 ;
F_2 () ;
V_13 -> V_4 = V_4 ;
return ( V_11 | V_6 ) ;
}
}
V_11 = ( ( ~ V_2 ) & 0x1f ) << 3 ;
V_13 = (struct V_12 * ) ( V_1 | ( ( ( ~ V_2 ) & 0x1f ) << 7 ) ) ;
}
V_9 = F_3 () -> V_22 ;
for ( V_10 = 0 ; V_10 < 16 ; V_10 ++ ) {
if ( V_9 < 8 ) {
V_11 = ( V_2 & 0x1f ) << 3 ;
V_13 = (struct V_12 * ) ( V_1 | ( ( V_2 & 0x1f ) << 7 ) ) ;
V_14 = V_13 + V_9 ;
} else {
V_11 = ( ( ~ V_2 ) & 0x1f ) << 3 ;
V_13 = (struct V_12 * ) ( V_1 | ( ( ( ~ V_2 ) & 0x1f ) << 7 ) ) ;
V_14 = V_13 + ( V_9 - 8 ) ;
}
if ( ( V_14 -> V_4 & V_23 ) != V_17 )
break;
V_9 = ( V_9 + 1 ) & 0xf ;
}
F_3 () -> V_22 = ( V_9 + 1 ) & 0xf ;
asm volatile("isync" : : : "memory");
V_8 = V_14 -> V_4 >> V_16 ;
V_14 -> V_4 = 0 ;
asm volatile("sync" : : : "memory");
V_14 -> V_5 = V_5 ;
F_2 () ;
V_14 -> V_4 = V_4 ;
asm volatile("slbie %0" : : "r" (old_esid << SID_SHIFT));
asm volatile("sync" : : : "memory");
return ( V_11 | ( V_9 & 0x7 ) ) ;
}
static int F_4 ( unsigned long V_24 , struct V_25 * V_26 )
{
unsigned long V_3 ;
unsigned char V_12 ;
unsigned long V_27 ;
if ( F_5 ( V_24 ) ) {
V_3 = F_6 ( V_24 , V_28 ) ;
} else {
if ( ( V_24 >= V_29 ) || ( ! V_26 ) )
return 1 ;
V_3 = F_7 ( V_26 -> V_30 . V_31 , V_24 , V_28 ) ;
}
V_12 = F_1 ( F_3 () -> V_32 , F_8 ( V_24 ) , V_3 ) ;
if ( ! F_5 ( V_24 ) ) {
V_27 = F_9 ( V_33 ) ;
if ( V_27 < V_34 )
F_9 ( V_35 [ V_27 ++ ] ) = V_12 ;
else
V_27 = V_34 + 1 ;
F_9 ( V_33 ) = V_27 ;
asm volatile("sync":::"memory");
}
return 0 ;
}
int F_10 ( unsigned long V_24 )
{
return F_4 ( V_24 , V_36 -> V_26 ) ;
}
void F_11 ( struct V_37 * V_38 , struct V_25 * V_26 )
{
struct V_12 * V_1 = (struct V_12 * ) F_3 () -> V_32 ;
struct V_12 * V_13 ;
unsigned long V_27 ;
unsigned long V_39 = F_12 ( V_38 ) ;
unsigned long V_40 = F_13 ( V_38 ) ;
unsigned long V_41 ;
asm volatile("isync" : : : "memory");
F_14 () ;
V_27 = F_9 ( V_33 ) ;
if ( V_27 <= V_34 ) {
int V_10 ;
for ( V_10 = 0 ; V_10 < V_27 ; V_10 ++ ) {
V_13 = V_1 + F_9 ( V_35 [ V_10 ] ) ;
V_13 -> V_4 = 0 ;
}
} else {
unsigned long V_6 ;
V_13 = V_1 ;
V_13 += 1 ;
for ( V_6 = 1 ;
V_6 < ( V_42 / sizeof( struct V_12 ) ) ;
V_6 ++ , V_13 ++ ) {
unsigned long V_24 ;
V_24 = V_13 -> V_4 & V_23 ;
if ( ! F_5 ( V_24 ) ) {
V_13 -> V_4 = 0 ;
}
}
}
asm volatile("sync; slbia; sync":::"memory");
F_9 ( V_33 ) = 0 ;
if ( F_15 ( V_38 , V_43 ) )
V_41 = V_44 ;
else
V_41 = V_45 ;
F_4 ( V_39 , V_26 ) ;
if ( F_8 ( V_39 ) == F_8 ( V_40 ) )
return;
F_4 ( V_40 , V_26 ) ;
if ( ( F_8 ( V_39 ) == F_8 ( V_41 ) )
|| ( F_8 ( V_40 ) == F_8 ( V_41 ) ) )
return;
F_4 ( V_41 , V_26 ) ;
asm volatile("sync" : : : "memory");
}
void T_1 F_16 ( void )
{
int V_46 ;
if ( F_17 ( V_47 ) )
return;
F_18 (cpu) {
unsigned long V_48 ;
if ( V_46 == 0 )
continue;
V_48 = F_19 ( V_42 , V_42 ,
1 << V_16 ) ;
V_48 = ( unsigned long ) F_20 ( V_48 ) ;
memset ( ( void * ) V_48 , 0 , V_42 ) ;
V_49 [ V_46 ] . V_32 = V_48 ;
V_49 [ V_46 ] . V_50 = F_21 ( V_48 ) ;
F_22 ( V_51 L_1
L_2 ,
V_46 , V_49 [ V_46 ] . V_32 , V_49 [ V_46 ] . V_50 ) ;
}
}
void F_23 ( unsigned long V_1 )
{
unsigned long V_3 = F_6 ( V_17 , V_28 ) ;
unsigned long V_52 ;
asm volatile("isync; slbia; isync":::"memory");
F_1 ( V_1 , F_8 ( V_17 ) , V_3 ) ;
asm volatile("sync":::"memory");
V_52 = F_3 () -> V_50 | 0x1ul ;
F_24 ( V_53 , V_52 ) ;
}
