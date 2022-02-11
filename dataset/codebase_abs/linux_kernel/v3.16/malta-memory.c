T_1 * T_2 F_1 ( int V_1 )
{
char * V_2 , * V_3 = NULL , * V_4 ;
unsigned long V_5 = 0 , V_6 = 0 ;
static char V_7 [ V_8 ] V_9 ;
int V_10 ;
V_2 = F_2 ( L_1 ) ;
if ( V_2 )
V_10 = F_3 ( V_2 , 0 , & V_5 ) ;
if ( V_1 ) {
V_3 = F_2 ( L_2 ) ;
if ( V_3 )
V_10 = F_3 ( V_3 , 0 , & V_6 ) ;
}
if ( ! V_5 && ! V_6 ) {
F_4 ( L_3 ) ;
V_11 = 0x02000000 ;
} else {
V_11 = V_6 ? : V_5 ;
}
#ifdef F_5
V_11 -= V_12 ;
#endif
strcpy ( V_7 , V_13 ) ;
V_4 = strstr ( V_7 , L_4 ) ;
if ( V_4 && ( V_4 != V_7 ) && ( * ( V_4 - 1 ) != ' ' ) )
V_4 = strstr ( V_4 , L_5 ) ;
if ( V_1 ) {
V_4 = strstr ( V_7 , L_6 ) ;
if ( V_4 && ( V_4 != V_7 ) && ( * ( V_4 - 1 ) != ' ' ) )
V_4 = strstr ( V_4 , L_7 ) ;
}
if ( V_4 )
V_5 = F_6 ( V_4 + 8 + ( V_1 ? 1 : 0 ) , & V_4 ) ;
else
V_5 = V_11 ;
if ( V_5 > 0x7fff0000 )
V_5 = 0x7fff0000 ;
memset ( V_14 , 0 , sizeof( V_14 ) ) ;
V_14 [ 0 ] . type = V_15 ;
V_14 [ 0 ] . V_16 = V_17 ;
V_14 [ 0 ] . V_18 = 0x00001000 ;
V_14 [ 1 ] . type = V_19 ;
V_14 [ 1 ] . V_16 = V_14 [ 0 ] . V_16 + 0x00001000UL ;
V_14 [ 1 ] . V_18 = 0x000ef000 ;
V_14 [ 2 ] . type = V_15 ;
V_14 [ 2 ] . V_16 = V_14 [ 0 ] . V_16 + 0x000f0000UL ;
V_14 [ 2 ] . V_18 = 0x00010000 ;
V_14 [ 3 ] . type = V_15 ;
V_14 [ 3 ] . V_16 = V_14 [ 0 ] . V_16 + 0x00100000UL ;
V_14 [ 3 ] . V_18 = F_7 ( F_8 ( ( unsigned long ) & V_20 ) ) -
0x00100000UL ;
V_14 [ 4 ] . type = V_21 ;
V_14 [ 4 ] . V_16 = V_14 [ 0 ] . V_16 + F_7 ( F_8 ( & V_20 ) ) ;
V_14 [ 4 ] . V_18 = V_5 - F_7 ( V_14 [ 4 ] . V_16 ) ;
return & V_14 [ 0 ] ;
}
static void F_9 ( void * V_22 , void * V_23 )
{
F_10 ( L_8 , F_11 ( ( unsigned long * ) V_22 ) ,
F_11 ( ( unsigned long * ) V_23 ) ) ;
}
static int T_2 F_12 ( unsigned int type )
{
switch ( type ) {
case V_21 :
return V_24 ;
case V_19 :
return V_25 ;
default:
return V_26 ;
}
}
void T_2 F_13 ( void )
{
T_1 * V_27 ;
V_27 = F_1 ( F_14 ( V_28 ) ) ;
V_29 = ( F_14 ( V_28 ) ?
F_9 : NULL ) ;
while ( V_27 -> V_18 ) {
long type ;
unsigned long V_16 , V_18 ;
type = F_12 ( V_27 -> type ) ;
V_16 = V_27 -> V_16 ;
V_18 = V_27 -> V_18 ;
F_15 ( V_16 , V_18 , type ) ;
V_27 ++ ;
}
}
void T_2 F_16 ( void )
{
unsigned long V_30 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_32 . V_33 ; V_31 ++ ) {
if ( V_32 . V_34 [ V_31 ] . type != V_25 )
continue;
V_30 = V_32 . V_34 [ V_31 ] . V_30 ;
F_10 ( L_9 ,
V_30 , V_30 + V_32 . V_34 [ V_31 ] . V_18 ) ;
}
}
