static struct V_1 * T_1 F_1 ( void )
{
char * V_2 ;
unsigned int V_3 ;
char * V_4 ;
static char V_5 [ V_6 ] V_7 ;
V_2 = F_2 ( L_1 ) ;
if ( ! V_2 ) {
F_3 ( V_8
L_2 ) ;
V_9 = 0x02000000 ;
} else {
#ifdef F_4
F_5 ( L_3 , V_2 ) ;
#endif
V_9 = F_6 ( V_2 , NULL , 0 ) ;
}
#ifdef F_7
V_9 -= V_10 ;
#endif
strcpy ( V_5 , V_11 ) ;
V_4 = strstr ( V_5 , L_4 ) ;
if ( V_4 && ( V_4 != V_5 ) && ( * ( V_4 - 1 ) != ' ' ) )
V_4 = strstr ( V_4 , L_5 ) ;
if ( V_4 )
V_3 = F_8 ( V_4 + 8 , & V_4 ) ;
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
V_12 [ 3 ] . V_15 = F_9 ( F_10 ( ( unsigned long ) & V_17 ) ) - V_12 [ 3 ] . V_14 ;
V_12 [ 4 ] . type = V_18 ;
V_12 [ 4 ] . V_14 = F_9 ( F_10 ( & V_17 ) ) ;
V_12 [ 4 ] . V_15 = V_3 - V_12 [ 4 ] . V_14 ;
return & V_12 [ 0 ] ;
}
static int T_1 F_11 ( unsigned int type )
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
void T_1 F_12 ( void )
{
struct V_1 * V_22 ;
#ifdef F_4
F_5 ( L_6 ) ;
V_22 = F_1 () ;
while ( V_22 -> V_15 ) {
int V_23 = 0 ;
F_5 ( L_7 ,
V_23 , V_22 , V_22 -> V_14 , V_22 -> V_15 , V_24 [ V_22 -> type ] ) ;
V_22 ++ ;
V_23 ++ ;
}
#endif
V_22 = F_1 () ;
while ( V_22 -> V_15 ) {
long type ;
unsigned long V_14 , V_15 ;
type = F_11 ( V_22 -> type ) ;
V_14 = V_22 -> V_14 ;
V_15 = V_22 -> V_15 ;
F_13 ( V_14 , V_15 , type ) ;
V_22 ++ ;
}
}
void T_1 F_14 ( void )
{
unsigned long V_25 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < V_26 . V_27 ; V_23 ++ ) {
if ( V_26 . V_28 [ V_23 ] . type != V_20 )
continue;
V_25 = V_26 . V_28 [ V_23 ] . V_25 ;
F_15 ( L_8 ,
V_25 , V_25 + V_26 . V_28 [ V_23 ] . V_15 ) ;
}
}
