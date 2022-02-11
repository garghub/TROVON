static inline T_1 F_1 ( T_1 V_1 )
{
__asm__ __volatile__("emudat = %0;" : : "d"(emudat));
return V_1 ;
}
static inline T_1 F_2 ( void )
{
T_1 V_1 ;
__asm__ __volatile__("%0 = emudat;" : "=d"(emudat));
return V_1 ;
}
static int F_3 ( T_1 V_2 , const char * V_3 , int V_4 )
{
static T_1 V_5 ;
T_1 V_1 ;
int V_6 ;
if ( F_4 () & V_7 )
return 0 ;
if ( ! V_5 ) {
V_5 = V_4 ;
F_1 ( V_5 ) ;
return 0 ;
}
V_6 = F_5 ( V_5 , ( T_1 ) 4 ) ;
memcpy ( & V_1 , V_3 , V_6 ) ;
F_1 ( V_1 ) ;
V_5 -= V_6 ;
return V_6 ;
}
static int F_6 ( T_1 V_2 , char * V_3 , int V_4 )
{
static T_1 V_8 ;
T_1 V_1 ;
int V_6 ;
if ( ! ( F_4 () & V_9 ) )
return 0 ;
V_1 = F_2 () ;
if ( ! V_8 ) {
V_8 = V_1 ;
return 0 ;
}
V_6 = F_5 ( V_8 , ( T_1 ) 4 ) ;
memcpy ( V_3 , & V_1 , V_6 ) ;
V_8 -= V_6 ;
return V_6 ;
}
static int T_2 F_7 ( void )
{
F_8 ( 0 , 0 , & V_10 ) ;
return 0 ;
}
static int T_2 F_9 ( void )
{
F_10 ( 0 , 0 , & V_10 , 128 ) ;
return 0 ;
}
