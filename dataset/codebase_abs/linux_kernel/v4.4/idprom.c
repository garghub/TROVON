static void T_1 F_1 ( unsigned char V_1 )
{
register int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if( V_4 [ V_2 ] . V_5 == V_1 ) {
if ( V_1 != ( V_6 | 0x00 ) )
F_2 ( L_1 , V_4 [ V_2 ] . V_7 ) ;
else {
#if 0
prom_getproperty(prom_root_node, "banner-name",
sysname, sizeof(sysname));
printk("TYPE: %s\n", sysname);
#endif
}
return;
}
}
F_3 ( L_2 , V_1 ) ;
F_4 () ;
}
void F_5 ( unsigned char * V_8 )
{
register int V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ ) {
if( V_4 [ V_2 ] . V_5 == V_9 -> V_5 ) {
strcpy ( V_8 , V_4 [ V_2 ] . V_7 ) ;
return;
}
}
}
static unsigned char T_1 F_6 ( struct V_9 * V_9 )
{
unsigned char V_10 , V_2 , * V_11 = ( unsigned char * ) V_9 ;
for ( V_2 = V_10 = 0 ; V_2 <= 0x0E ; V_2 ++ )
V_10 ^= * V_11 ++ ;
return V_10 ;
}
void T_1 F_7 ( void )
{
F_8 ( ( char * ) & V_12 , sizeof( V_12 ) ) ;
V_9 = & V_12 ;
if ( V_9 -> V_13 != 0x01 ) {
F_3 ( L_3 ) ;
F_4 () ;
}
if ( V_9 -> V_14 != F_6 ( V_9 ) ) {
F_3 ( L_4 ,
V_9 -> V_14 , F_6 ( V_9 ) ) ;
F_4 () ;
}
F_1 ( V_9 -> V_5 ) ;
F_2 ( L_5 , V_9 -> V_15 ) ;
}
