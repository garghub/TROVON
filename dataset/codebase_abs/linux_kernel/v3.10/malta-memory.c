T_1 * T_2 F_1 ( void )
{
char * V_1 , * V_2 ;
unsigned int V_3 ;
static char V_4 [ V_5 ] V_6 ;
long V_7 ;
int V_8 ;
V_1 = F_2 ( L_1 ) ;
if ( ! V_1 ) {
F_3 ( L_2 ) ;
V_9 = 0x02000000 ;
} else {
V_8 = F_4 ( V_1 , 0 , & V_7 ) ;
V_9 = ( unsigned long ) V_7 ;
}
#ifdef F_5
V_9 -= V_10 ;
#endif
strcpy ( V_4 , V_11 ) ;
V_2 = strstr ( V_4 , L_3 ) ;
if ( V_2 && ( V_2 != V_4 ) && ( * ( V_2 - 1 ) != ' ' ) )
V_2 = strstr ( V_2 , L_4 ) ;
if ( V_2 )
V_3 = F_6 ( V_2 + 8 , & V_2 ) ;
else
V_3 = V_9 ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
V_12 [ 0 ] . type = V_13 ;
V_12 [ 0 ] . V_14 = 0x00000000 ;
V_12 [ 0 ] . V_15 = 0x00001000 ;
V_12 [ 1 ] . type = V_16 ;
V_12 [ 1 ] . V_14 = 0x00001000 ;
V_12 [ 1 ] . V_15 = 0x000ef000 ;
V_12 [ 2 ] . type = V_13 ;
V_12 [ 2 ] . V_14 = 0x000f0000 ;
V_12 [ 2 ] . V_15 = 0x00010000 ;
V_12 [ 3 ] . type = V_13 ;
V_12 [ 3 ] . V_14 = 0x00100000 ;
V_12 [ 3 ] . V_15 = F_7 ( F_8 ( ( unsigned long ) & V_17 ) ) -
V_12 [ 3 ] . V_14 ;
V_12 [ 4 ] . type = V_18 ;
V_12 [ 4 ] . V_14 = F_7 ( F_8 ( & V_17 ) ) ;
V_12 [ 4 ] . V_15 = V_3 - V_12 [ 4 ] . V_14 ;
return & V_12 [ 0 ] ;
}
static int T_2 F_9 ( unsigned int type )
{
switch ( type ) {
case V_18 :
return V_19 ;
case V_16 :
return V_20 ;
default:
return V_21 ;
}
}
void T_2 F_10 ( void )
{
T_1 * V_22 ;
V_22 = F_1 () ;
while ( V_22 -> V_15 ) {
long type ;
unsigned long V_14 , V_15 ;
type = F_9 ( V_22 -> type ) ;
V_14 = V_22 -> V_14 ;
V_15 = V_22 -> V_15 ;
F_11 ( V_14 , V_15 , type ) ;
V_22 ++ ;
}
}
void T_2 F_12 ( void )
{
unsigned long V_23 ;
int V_24 ;
for ( V_24 = 0 ; V_24 < V_25 . V_26 ; V_24 ++ ) {
if ( V_25 . V_27 [ V_24 ] . type != V_20 )
continue;
V_23 = V_25 . V_27 [ V_24 ] . V_23 ;
F_13 ( L_5 ,
V_23 , V_23 + V_25 . V_27 [ V_24 ] . V_15 ) ;
}
}
