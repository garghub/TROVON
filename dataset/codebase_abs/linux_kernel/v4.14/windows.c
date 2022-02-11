void F_1 ( void )
{
register int T_1 V_1 ( L_1 ) ;
T_1 = 0 ;
__asm__ __volatile__(
"\n1:\n\t"
"ld [%%g6 + %2], %%g4\n\t"
"orcc %%g0, %%g4, %%g0\n\t"
"add %0, 1, %0\n\t"
"bne 1b\n\t"
" save %%sp, -64, %%sp\n"
"2:\n\t"
"subcc %0, 1, %0\n\t"
"bne 2b\n\t"
" restore %%g0, %%g0, %%g0\n"
: "=&r" (ctr)
: "0" (ctr),
"i" ((const unsigned long)TI_UWINMASK)
: "g4", "cc");
}
static inline void F_2 ( int V_2 , int V_3 , struct V_4 * V_5 )
{
int V_6 ;
for( V_6 = V_2 ; V_6 < V_3 ; V_6 ++ ) {
V_5 -> V_7 [ V_6 ] = V_5 -> V_7 [ V_6 + 1 ] ;
memcpy ( & V_5 -> V_8 [ V_6 ] , & V_5 -> V_8 [ V_6 + 1 ] , sizeof( struct V_9 ) ) ;
}
}
void F_3 ( void )
{
struct V_4 * V_5 = F_4 () ;
int V_10 ;
F_1 () ;
if( ! V_5 -> V_11 )
return;
for( V_10 = V_5 -> V_11 - 1 ; V_10 >= 0 ; V_10 -- ) {
unsigned long V_12 = V_5 -> V_7 [ V_10 ] ;
if ( F_5 ( ( char V_13 * ) V_12 , & V_5 -> V_8 [ V_10 ] ,
sizeof( struct V_9 ) ) )
continue;
F_2 ( V_10 , V_5 -> V_11 - 1 , V_5 ) ;
V_5 -> V_11 -- ;
}
}
void F_6 ( struct V_14 * V_15 , int V_16 )
{
struct V_4 * V_5 = F_4 () ;
int V_10 ;
F_1 () ;
for( V_10 = 0 ; V_10 < V_5 -> V_11 ; V_10 ++ ) {
unsigned long V_12 = V_5 -> V_7 [ V_10 ] ;
if ( ( V_12 & 7 ) ||
F_5 ( ( char V_13 * ) V_12 , & V_5 -> V_8 [ V_10 ] ,
sizeof( struct V_9 ) ) )
F_7 ( V_17 ) ;
}
V_5 -> V_11 = 0 ;
}
