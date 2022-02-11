void F_1 ( int V_1 , void * V_2 , const void * V_3 , T_1 V_4 )
{
unsigned long V_5 ;
unsigned char V_6 ;
unsigned long V_7 = ( ( unsigned long ) V_2 ) % 0x4000 ;
if ( ! F_2 ( V_1 ) ) {
F_3 ( L_1 , V_1 ) ;
return;
}
if ( V_4 > V_8 )
return;
V_6 = ( unsigned long ) V_2 / V_8 ;
F_3 ( L_2 , V_9 [ V_1 ] -> V_10 , V_6 ) ;
F_4 ( & V_9 [ V_1 ] -> V_11 , V_5 ) ;
F_5 ( ( ( V_9 [ V_1 ] -> V_12 + V_6 * V_8 ) >> 14 ) | 0x80 ,
V_9 [ V_1 ] -> V_13 [ V_9 [ V_1 ] -> V_14 ] ) ;
F_6 ( ( void V_15 * ) ( V_9 [ V_1 ] -> V_16 + V_7 ) , V_3 , V_4 ) ;
F_7 ( & V_9 [ V_1 ] -> V_11 , V_5 ) ;
F_3 ( L_3 , V_9 [ V_1 ] -> V_10 ,
( ( V_9 [ V_1 ] -> V_12 + V_6 * V_8 ) >> 14 ) | 0x80 ) ;
F_3 ( L_4 ,
V_9 [ V_1 ] -> V_10 , V_4 ,
( unsigned long ) V_3 ,
V_9 [ V_1 ] -> V_16 + ( ( unsigned long ) V_2 % 0x4000 ) ) ;
}
void F_8 ( int V_1 , void * V_2 , const void * V_3 , T_1 V_4 )
{
unsigned long V_5 ;
unsigned char V_6 ;
if( ! F_2 ( V_1 ) ) {
F_3 ( L_1 , V_1 ) ;
return;
}
if( V_4 > V_8 ) {
return;
}
V_6 = ( unsigned long ) V_3 / V_8 ;
F_3 ( L_2 , V_9 [ V_1 ] -> V_10 , V_6 ) ;
F_4 ( & V_9 [ V_1 ] -> V_11 , V_5 ) ;
F_5 ( ( ( V_9 [ V_1 ] -> V_12 + V_6 * V_8 ) >> 14 ) | 0x80 ,
V_9 [ V_1 ] -> V_13 [ V_9 [ V_1 ] -> V_14 ] ) ;
F_9 ( V_2 , ( void * ) ( V_9 [ V_1 ] -> V_16 +
( ( unsigned long ) V_3 % 0x4000 ) ) , V_4 ) ;
F_7 ( & V_9 [ V_1 ] -> V_11 , V_5 ) ;
F_3 ( L_3 , V_9 [ V_1 ] -> V_10 ,
( ( V_9 [ V_1 ] -> V_12 + V_6 * V_8 ) >> 14 ) | 0x80 ) ;
}
