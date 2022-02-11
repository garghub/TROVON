T_1 * T_2 F_1 ( int V_1 )
{
char * V_2 , * V_3 V_4 = NULL , * V_5 ;
unsigned long V_6 = 0 , V_7 V_4 = 0 ;
static char V_8 [ V_9 ] V_10 ;
int V_11 ;
V_2 = F_2 ( L_1 ) ;
if ( V_2 )
V_11 = F_3 ( V_2 , 0 , & V_6 ) ;
if ( V_1 ) {
V_3 = F_2 ( L_2 ) ;
if ( V_3 )
V_11 = F_3 ( V_3 , 0 , & V_7 ) ;
}
if ( ! V_6 && ! V_7 ) {
F_4 ( L_3 ) ;
V_12 = 0x02000000 ;
} else {
V_12 = V_7 ? : V_6 ;
}
#ifdef F_5
V_12 -= V_13 ;
#endif
strcpy ( V_8 , V_14 ) ;
V_5 = strstr ( V_8 , L_4 ) ;
if ( V_5 && ( V_5 != V_8 ) && ( * ( V_5 - 1 ) != ' ' ) )
V_5 = strstr ( V_5 , L_5 ) ;
if ( V_1 ) {
V_5 = strstr ( V_8 , L_6 ) ;
if ( V_5 && ( V_5 != V_8 ) && ( * ( V_5 - 1 ) != ' ' ) )
V_5 = strstr ( V_5 , L_7 ) ;
}
if ( V_5 )
V_6 = F_6 ( V_5 + 8 + ( V_1 ? 1 : 0 ) , & V_5 ) ;
else
V_6 = V_12 ;
if ( V_6 > 0x7fff0000 )
V_6 = 0x7fff0000 ;
memset ( V_15 , 0 , sizeof( V_15 ) ) ;
V_15 [ 0 ] . type = V_16 ;
V_15 [ 0 ] . V_17 = V_18 ;
V_15 [ 0 ] . V_19 = 0x00001000 ;
V_15 [ 1 ] . type = V_20 ;
V_15 [ 1 ] . V_17 = V_15 [ 0 ] . V_17 + 0x00001000UL ;
V_15 [ 1 ] . V_19 = 0x000ef000 ;
V_15 [ 2 ] . type = V_16 ;
V_15 [ 2 ] . V_17 = V_15 [ 0 ] . V_17 + 0x000f0000UL ;
V_15 [ 2 ] . V_19 = 0x00010000 ;
V_15 [ 3 ] . type = V_16 ;
V_15 [ 3 ] . V_17 = V_15 [ 0 ] . V_17 + 0x00100000UL ;
V_15 [ 3 ] . V_19 = F_7 ( F_8 ( ( unsigned long ) & V_21 ) ) -
0x00100000UL ;
V_15 [ 4 ] . type = V_22 ;
V_15 [ 4 ] . V_17 = V_15 [ 0 ] . V_17 + F_7 ( F_8 ( & V_21 ) ) ;
V_15 [ 4 ] . V_19 = V_6 - F_7 ( V_15 [ 4 ] . V_17 ) ;
return & V_15 [ 0 ] ;
}
static void F_9 ( void * V_23 , void * V_24 )
{
F_10 ( L_8 , F_11 ( ( unsigned long * ) V_23 ) ,
F_11 ( ( unsigned long * ) V_24 ) ) ;
}
static int T_2 F_12 ( unsigned int type )
{
switch ( type ) {
case V_22 :
return V_25 ;
case V_20 :
return V_26 ;
default:
return V_27 ;
}
}
void T_2 F_13 ( void )
{
T_1 * V_28 ;
V_28 = F_1 ( F_14 ( V_29 ) ) ;
V_30 = ( F_14 ( V_29 ) ?
F_9 : NULL ) ;
while ( V_28 -> V_19 ) {
long type ;
unsigned long V_17 , V_19 ;
type = F_12 ( V_28 -> type ) ;
V_17 = V_28 -> V_17 ;
V_19 = V_28 -> V_19 ;
F_15 ( V_17 , V_19 , type ) ;
V_28 ++ ;
}
}
void T_2 F_16 ( void )
{
unsigned long V_31 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < V_33 . V_34 ; V_32 ++ ) {
if ( V_33 . V_35 [ V_32 ] . type != V_26 )
continue;
V_31 = V_33 . V_35 [ V_32 ] . V_31 ;
F_10 ( L_9 ,
V_31 , V_31 + V_33 . V_35 [ V_32 ] . V_19 ) ;
}
}
