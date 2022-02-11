static inline unsigned int F_1 ( void )
{
return F_2 ( V_1 ) & 1 ;
}
static inline void F_3 ( void )
{
do { } while ( ! F_1 () );
}
static inline void F_4 ( void )
{
do { } while ( F_1 () );
}
static inline void F_5 ( void )
{
if ( F_1 () ) {
F_6 ( L_1 ) ;
do {
( void ) F_2 ( V_2 ) ;
F_7 () ;
} while ( F_1 () );
F_6 ( L_2 ) ;
}
}
T_1 F_8 ( T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 , V_6 ;
F_9 ( & V_7 , V_4 ) ;
F_5 () ;
F_10 ( ( V_8 << 24 ) | ( V_3 & 0x00ffffff ) , V_2 ) ;
F_7 () ;
F_3 () ;
V_5 = F_2 ( V_2 ) ;
F_7 () ;
V_6 = F_2 ( V_2 ) ;
F_4 () ;
F_6 ( L_3 , V_3 , V_6 , V_5 ) ;
F_11 ( & V_7 , V_4 ) ;
return V_6 ;
}
void F_12 ( T_1 V_6 , T_1 V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
F_9 ( & V_7 , V_4 ) ;
F_5 () ;
F_10 ( ( V_9 << 24 ) | ( V_3 & 0x00ffffff ) , V_2 ) ;
F_7 () ;
F_10 ( V_6 , V_2 ) ;
F_7 () ;
F_3 () ;
V_5 = F_2 ( V_2 ) ;
F_4 () ;
F_6 ( L_4 , V_3 , V_6 , V_5 ) ;
F_11 ( & V_7 , V_4 ) ;
}
