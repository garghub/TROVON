void F_1 ( unsigned char V_1 [ 16 ] )
{
F_2 ( V_1 , 16 ) ;
V_1 [ 6 ] = ( V_1 [ 6 ] & 0x0F ) | 0x40 ;
V_1 [ 8 ] = ( V_1 [ 8 ] & 0x3F ) | 0x80 ;
}
static void F_3 ( T_1 V_2 [ 16 ] )
{
F_4 ( V_2 , 16 ) ;
V_2 [ 8 ] = ( V_2 [ 8 ] & 0x3F ) | 0x80 ;
}
void F_5 ( T_2 * V_3 )
{
F_3 ( V_3 -> V_2 ) ;
V_3 -> V_2 [ 7 ] = ( V_3 -> V_2 [ 7 ] & 0x0F ) | 0x40 ;
}
void F_6 ( T_3 * V_4 )
{
F_3 ( V_4 -> V_2 ) ;
V_4 -> V_2 [ 6 ] = ( V_4 -> V_2 [ 6 ] & 0x0F ) | 0x40 ;
}
bool F_7 ( const char * V_1 )
{
unsigned int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_5 == 8 || V_5 == 13 || V_5 == 18 || V_5 == 23 ) {
if ( V_1 [ V_5 ] != '-' )
return false ;
} else if ( ! isxdigit ( V_1 [ V_5 ] ) ) {
return false ;
}
}
return true ;
}
static int F_8 ( const char * V_1 , T_1 V_2 [ 16 ] , const T_4 V_7 [ 16 ] )
{
static const T_4 V_8 [ 16 ] = { 0 , 2 , 4 , 6 , 9 , 11 , 14 , 16 , 19 , 21 , 24 , 26 , 28 , 30 , 32 , 34 } ;
unsigned int V_5 ;
if ( ! F_7 ( V_1 ) )
return - V_9 ;
for ( V_5 = 0 ; V_5 < 16 ; V_5 ++ ) {
int V_10 = F_9 ( V_1 [ V_8 [ V_5 ] + 0 ] ) ;
int V_11 = F_9 ( V_1 [ V_8 [ V_5 ] + 1 ] ) ;
V_2 [ V_7 [ V_5 ] ] = ( V_10 << 4 ) | V_11 ;
}
return 0 ;
}
int F_10 ( const char * V_1 , T_2 * V_12 )
{
return F_8 ( V_1 , V_12 -> V_2 , V_13 ) ;
}
int F_11 ( const char * V_1 , T_3 * V_12 )
{
return F_8 ( V_1 , V_12 -> V_2 , V_14 ) ;
}
