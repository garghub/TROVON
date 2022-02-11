struct V_1 * T_1 F_1 ( void )
{
unsigned int V_2 ;
V_2 = 0x02000000 ;
F_2 ( L_1 , V_2 ) ;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
V_3 [ 0 ] . type = V_4 ;
V_3 [ 0 ] . V_5 = 0x00000000 ;
V_3 [ 0 ] . V_6 = 0x00001000 ;
V_3 [ 1 ] . type = V_7 ;
V_3 [ 1 ] . V_5 = 0x00001000 ;
V_3 [ 1 ] . V_6 = 0x000ff000 ;
V_3 [ 2 ] . type = V_4 ;
V_3 [ 2 ] . V_5 = 0x00100000 ;
V_3 [ 2 ] . V_6 = F_3 ( F_4 ( & V_8 ) ) - V_3 [ 2 ] . V_5 ;
V_3 [ 3 ] . type = V_7 ;
V_3 [ 3 ] . V_5 = F_3 ( F_4 ( & V_8 ) ) ;
V_3 [ 3 ] . V_6 = V_2 - V_3 [ 3 ] . V_5 ;
return & V_3 [ 0 ] ;
}
static int T_1 F_5 ( unsigned int type )
{
switch ( type ) {
case V_7 :
return V_9 ;
case V_4 :
default:
return V_10 ;
}
}
void T_1 F_6 ( void )
{
struct V_1 * V_11 ;
V_11 = F_1 () ;
while ( V_11 -> V_6 ) {
long type ;
unsigned long V_5 , V_6 ;
type = F_5 ( V_11 -> type ) ;
V_5 = V_11 -> V_5 ;
V_6 = V_11 -> V_6 ;
F_7 ( V_5 , V_6 , type ) ;
V_11 ++ ;
}
}
void T_1 F_8 ( void )
{
int V_12 ;
unsigned long V_13 ;
for ( V_12 = 0 ; V_12 < V_14 . V_15 ; V_12 ++ ) {
if ( V_14 . V_16 [ V_12 ] . type != V_17 )
continue;
V_13 = V_14 . V_16 [ V_12 ] . V_13 ;
F_9 ( L_2 ,
V_13 , V_13 + V_14 . V_16 [ V_12 ] . V_6 ) ;
}
}
