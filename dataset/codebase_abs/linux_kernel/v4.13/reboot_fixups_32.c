static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , 0x44 , 0x1 ) ;
F_3 ( 50 ) ;
return;
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_3 , 1ULL ) ;
F_3 ( 50 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
unsigned V_4 ;
F_7 ( 0x80003840 , 0xCF8 ) ;
V_4 = F_8 ( 0xCFC ) ;
V_4 |= 0x1600 ;
F_7 ( V_4 , 0xCFC ) ;
F_9 ( 1 , 0x92 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < 10 ; V_4 ++ ) {
F_9 ( 0x2 , 0xcf9 ) ;
F_3 ( 50 ) ;
}
}
void F_11 ( void )
{
const struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_4 ;
if ( F_12 () )
return;
for ( V_4 = 0 ; V_4 < F_13 ( V_7 ) ; V_4 ++ ) {
V_6 = & ( V_7 [ V_4 ] ) ;
V_2 = F_14 ( V_6 -> V_8 , V_6 -> V_9 , NULL ) ;
if ( ! V_2 )
continue;
V_6 -> V_10 ( V_2 ) ;
F_15 ( V_2 ) ;
}
}
