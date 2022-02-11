static void
F_1 ( const char * V_1 )
{
unsigned long V_2 ;
while ( ( V_2 = * V_1 ++ ) != '\0' ) {
F_2 ( V_2 , 0 , 0 , 0 , V_3 ) ;
if ( V_2 == '\n' )
F_2 ( '\r' , 0 , 0 , 0 , V_3 ) ;
}
}
void
F_3 ( void )
{
static char V_4 [ 4096 ] ;
static char V_5 [ 1024 ] ;
unsigned long V_6 ;
int V_7 , V_8 ;
struct V_9 V_10 ;
struct V_11 V_12 ;
struct V_13 * V_14 ;
struct V_15 * V_15 ;
unsigned long V_16 , V_17 , V_18 ;
register struct V_19 * V_20 ;
char * V_21 , * args ;
long V_22 = 0 ;
F_2 ( 0 , 0 , 0 , 0 , V_23 ) ;
V_22 = F_2 ( ( long ) V_5 , 0 , 0 , 0 , V_24 ) ;
V_21 = L_1 ;
args = V_5 ;
if ( V_22 > 0 ) {
V_21 = V_5 ;
while ( * args != ' ' && * args != '\0' )
++ args , -- V_22 ;
if ( * args == ' ' )
* args ++ = '\0' , -- V_22 ;
}
if ( V_22 <= 0 ) {
args = L_2 ;
V_22 = 1 ;
}
V_7 = F_2 ( ( long ) V_21 , 1 , 0 , 0 , V_25 ) ;
if ( V_7 < 0 ) {
F_1 ( V_21 ) ;
F_1 ( L_3 ) ;
for(; ; ) ;
}
V_12 . V_7 = V_7 ;
V_6 = 0 ;
V_10 . V_26 = sizeof( V_4 ) ;
V_10 . V_27 = ( long ) V_4 ;
F_2 ( V_7 , 1 , ( long ) & V_10 , V_6 , V_28 ) ;
F_2 ( ( long ) & V_12 , 0 , 0 , 0 , V_29 ) ;
V_14 = (struct V_13 * ) V_4 ;
if ( V_14 -> V_30 [ 0 ] == 0x7f && strncmp ( V_14 -> V_30 + 1 , L_4 , 3 ) != 0 ) {
F_1 ( L_5 ) ;
return;
}
if ( V_14 -> V_31 != V_32 ) {
F_1 ( L_6 ) ;
return;
}
if ( ! F_4 ( V_14 ) ) {
F_1 ( L_7 ) ;
return;
}
V_16 = V_14 -> V_16 ;
V_18 = V_14 -> V_18 ;
V_17 = V_14 -> V_17 ;
F_1 ( L_8 ) ;
F_1 ( V_21 ) ;
F_1 ( L_9 ) ;
for ( V_8 = 0 ; V_8 < V_18 ; ++ V_8 ) {
V_10 . V_26 = sizeof( * V_15 ) ;
V_10 . V_27 = ( long ) V_4 ;
F_2 ( V_7 , 1 , ( long ) & V_10 , V_17 , V_28 ) ;
F_2 ( ( long ) & V_12 , 0 , 0 , 0 , V_29 ) ;
if ( V_12 . V_33 != sizeof( * V_15 ) ) {
F_1 ( L_10 ) ;
return;
}
V_17 += sizeof( * V_15 ) ;
V_15 = (struct V_15 * ) V_4 ;
if ( V_15 -> V_34 != V_35 )
continue;
V_10 . V_26 = V_15 -> V_36 ;
V_10 . V_27 = F_5 ( V_15 -> V_37 ) ;
F_2 ( V_7 , 1 , ( long ) & V_10 , V_15 -> V_38 , V_28 ) ;
F_2 ( ( long ) & V_12 , 0 , 0 , 0 , V_29 ) ;
memset ( ( char * ) F_5 ( V_15 -> V_37 ) + V_15 -> V_36 , 0 ,
V_15 -> V_39 - V_15 -> V_36 ) ;
}
F_2 ( V_7 , 0 , 0 , 0 , V_40 ) ;
F_1 ( L_11 ) ;
F_6 ( V_41 , 0xffffc000000UL ) ;
V_20 = F_7 ( args , V_22 ) ;
F_2 ( 0 , ( long ) V_21 , 0 , 0 , V_42 ) ;
F_8 () ;
F_9 ( ( unsigned long ) V_20 , V_16 ) ;
F_1 ( L_12 ) ;
F_2 ( - 1 , 0 , 0 , 0 , V_43 ) ;
}
