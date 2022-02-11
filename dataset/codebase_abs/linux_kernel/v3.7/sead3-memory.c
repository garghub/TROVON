struct V_1 * T_1 F_1 ( void )
{
char * V_2 , * V_3 ;
unsigned int V_4 ;
static char V_5 [ V_6 ] V_7 ;
long V_8 ;
int V_9 ;
V_2 = F_2 ( L_1 ) ;
if ( ! V_2 ) {
F_3 ( L_2 ) ;
V_10 = 0x02000000 ;
} else {
V_9 = F_4 ( V_2 , 0 , & V_8 ) ;
V_10 = ( unsigned long ) V_8 ;
}
#ifdef F_5
V_10 -= V_11 ;
#endif
strcpy ( V_5 , V_12 ) ;
V_3 = strstr ( V_5 , L_3 ) ;
if ( V_3 && ( V_3 != V_5 ) && ( * ( V_3 - 1 ) != ' ' ) )
V_3 = strstr ( V_3 , L_4 ) ;
if ( V_3 )
V_4 = F_6 ( V_3 + 8 , & V_3 ) ;
else
V_4 = V_10 ;
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
V_13 [ 0 ] . type = V_14 ;
V_13 [ 0 ] . V_15 = 0x00000000 ;
V_13 [ 0 ] . V_16 = 0x00001000 ;
V_13 [ 1 ] . type = V_17 ;
V_13 [ 1 ] . V_15 = 0x00001000 ;
V_13 [ 1 ] . V_16 = 0x000ef000 ;
V_13 [ 2 ] . type = V_14 ;
V_13 [ 2 ] . V_15 = 0x000f0000 ;
V_13 [ 2 ] . V_16 = 0x00010000 ;
V_13 [ 3 ] . type = V_14 ;
V_13 [ 3 ] . V_15 = 0x00100000 ;
V_13 [ 3 ] . V_16 = F_7 ( F_8 ( ( unsigned long ) & V_18 ) ) -
V_13 [ 3 ] . V_15 ;
V_13 [ 4 ] . type = V_19 ;
V_13 [ 4 ] . V_15 = F_7 ( F_8 ( & V_18 ) ) ;
V_13 [ 4 ] . V_16 = V_4 - V_13 [ 4 ] . V_15 ;
return & V_13 [ 0 ] ;
}
static int T_1 F_9 ( unsigned int type )
{
switch ( type ) {
case V_19 :
return V_20 ;
case V_17 :
return V_21 ;
default:
return V_22 ;
}
}
void T_1 F_10 ( void )
{
struct V_1 * V_23 ;
V_23 = F_1 () ;
while ( V_23 -> V_16 ) {
long type ;
unsigned long V_15 , V_16 ;
type = F_9 ( V_23 -> type ) ;
V_15 = V_23 -> V_15 ;
V_16 = V_23 -> V_16 ;
F_11 ( V_15 , V_16 , type ) ;
V_23 ++ ;
}
}
void T_1 F_12 ( void )
{
unsigned long V_24 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_26 . V_27 ; V_25 ++ ) {
if ( V_26 . V_28 [ V_25 ] . type != V_21 )
continue;
V_24 = V_26 . V_28 [ V_25 ] . V_24 ;
F_13 ( L_5 ,
V_24 , V_24 + V_26 . V_28 [ V_25 ] . V_16 ) ;
}
}
