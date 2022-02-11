static void F_1 ( void )
{
void * V_1 ;
F_2 ( V_2 . V_3 , V_2 . V_4 ) ;
F_3 ( L_1 , V_2 . V_5 ) ;
F_3 ( L_2 , V_2 . V_6 ) ;
F_4 ( V_2 . V_7 , V_2 . V_8 / 4 , V_2 . V_8 ) ;
V_1 = F_5 ( NULL , L_3 ) ;
if ( V_1 ) {
void * V_9 = NULL ;
F_6 ( V_1 , L_4 , & V_2 . V_8 ,
sizeof( V_2 . V_8 ) ) ;
while ( ( V_9 = F_5 ( V_9 , L_5 ) ) ) {
if ( F_7 ( V_9 ) != V_1 )
continue;
F_6 ( V_9 , L_6 , & V_2 . V_8 ,
sizeof( V_2 . V_8 ) ) ;
}
}
}
void F_8 ( unsigned long V_10 , unsigned long V_11 , unsigned long V_12 ,
unsigned long V_13 , unsigned long V_14 )
{
F_9 () ;
F_10 ( V_15 ) ;
F_11 () ;
V_16 . V_17 = F_1 ;
}
