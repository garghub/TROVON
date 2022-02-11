void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( & V_2 ) ;
}
static int F_4 ( void )
{
return F_5 ( & V_2 ) ;
}
int F_6 ( struct V_3 * V_4 , struct V_5 * V_6 )
{
struct V_3 * V_7 ;
V_7 = F_7 ( V_4 , V_8 ) ;
F_8 ( V_4 ) ;
if ( V_7 != NULL ) {
F_9 ( & V_1 , V_7 ) ;
if ( ! F_4 () )
F_10 () ;
}
return 1 ;
}
static void F_10 ( void )
{
F_11 ( & V_2 ) ;
V_2 . V_9 = 0 ;
V_2 . V_10 = & V_11 ;
V_2 . V_12 = V_13 + 10 ;
F_12 ( & V_2 ) ;
}
static void V_11 ( unsigned long V_14 )
{
struct V_3 * V_4 ;
struct V_15 * V_16 ;
T_1 * V_17 ;
struct V_18 * V_19 ;
unsigned short V_20 ;
unsigned int V_21 , V_22 ;
while ( ( V_4 = F_13 ( & V_1 ) ) != NULL ) {
if ( V_4 -> V_23 < V_24 ) {
F_8 ( V_4 ) ;
continue;
}
V_21 = ( ( V_4 -> V_9 [ 0 ] << 8 ) & 0xF00 ) + ( ( V_4 -> V_9 [ 1 ] << 0 ) & 0x0FF ) ;
V_20 = V_4 -> V_9 [ 2 ] ;
if ( V_20 == V_25 &&
( V_4 -> V_23 <= V_26 ||
V_4 -> V_9 [ V_27 ] !=
V_28 ) ) {
F_8 ( V_4 ) ;
continue;
}
V_17 = ( T_1 * ) ( V_4 -> V_9 + V_29 ) ;
V_22 = V_30 + 1 - V_21 ;
F_14 ( V_4 ) ;
V_19 = F_15 ( V_22 , V_31 ) ;
if ( V_19 ) {
if ( F_16 ( V_19 , V_4 ) == 0 )
F_8 ( V_4 ) ;
continue;
}
if ( V_20 == V_25 ) {
if ( ( V_16 = F_17 ( V_17 ) ) != NULL ) {
if ( F_18 ( V_4 , V_16 , V_31 , V_22 ) == 0 )
F_8 ( V_4 ) ;
} else {
F_8 ( V_4 ) ;
}
} else {
F_8 ( V_4 ) ;
}
}
}
void T_2 F_19 ( void )
{
struct V_3 * V_4 ;
F_11 ( & V_2 ) ;
while ( ( V_4 = F_13 ( & V_1 ) ) != NULL ) {
V_4 -> V_19 = NULL ;
F_8 ( V_4 ) ;
}
}
