static void F_1 ( void )
{
void * V_1 ;
F_2 ( V_2 . V_3 , V_2 . V_4 ) ;
F_3 ( V_2 . V_5 ) ;
F_4 ( V_2 . V_6 , V_2 . V_7 / 4 , V_2 . V_7 ) ;
V_1 = F_5 ( NULL , L_1 ) ;
if ( V_1 ) {
void * V_8 = NULL ;
F_6 ( V_1 , L_2 , & V_2 . V_7 ,
sizeof( V_2 . V_7 ) ) ;
while ( ( V_8 = F_5 ( V_8 , L_3 ) ) ) {
if ( F_7 ( V_8 ) != V_1 )
continue;
F_6 ( V_8 , L_4 , & V_2 . V_7 ,
sizeof( V_2 . V_7 ) ) ;
}
}
}
void F_8 ( unsigned long V_9 , unsigned long V_10 , unsigned long V_11 ,
unsigned long V_12 , unsigned long V_13 )
{
F_9 () ;
F_10 ( V_14 ) ;
F_11 () ;
V_15 . V_16 = F_1 ;
}
