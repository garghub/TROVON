int F_1 ( struct V_1 * V_2 , const char * V_3 , int V_4 )
{
struct V_5 * V_6 ;
int V_7 ;
V_6 = F_2 ( V_2 , V_3 , & V_7 ) ;
if ( ! V_6 || V_7 != 4 )
return V_4 ;
return * ( int * ) V_6 -> V_8 ;
}
int F_3 ( struct V_1 * V_9 , const char * V_3 , void * V_10 , int V_7 )
{
struct V_5 * * V_11 ;
unsigned long V_12 ;
void * V_13 ;
int V_14 ;
V_13 = F_4 ( V_10 , V_7 , V_15 ) ;
if ( ! V_13 )
return - V_16 ;
V_14 = - V_17 ;
F_5 ( & V_18 ) ;
F_6 ( & V_19 , V_12 ) ;
V_11 = & V_9 -> V_20 ;
while ( * V_11 ) {
struct V_5 * V_6 = * V_11 ;
if ( ! strcasecmp ( V_6 -> V_3 , V_3 ) ) {
void * V_21 = V_6 -> V_8 ;
int V_22 ;
V_22 = F_7 ( V_9 -> V_23 , V_3 , V_10 , V_7 ) ;
V_14 = - V_24 ;
if ( V_22 >= 0 ) {
V_6 -> V_8 = V_13 ;
V_6 -> V_25 = V_7 ;
if ( F_8 ( V_6 ) )
F_9 ( V_21 ) ;
F_10 ( V_6 ) ;
V_14 = 0 ;
}
break;
}
V_11 = & ( * V_11 ) -> V_26 ;
}
F_11 ( & V_19 , V_12 ) ;
F_12 ( & V_18 ) ;
return V_14 ;
}
int F_13 ( const char * V_27 , const char * V_28 , int V_7 )
{
while ( V_7 > 0 ) {
int V_29 ;
if ( ! strcmp ( V_27 , V_28 ) )
return 1 ;
V_29 = strlen ( V_27 ) + 1 ;
V_27 += V_29 ;
V_7 -= V_29 ;
}
return 0 ;
}
static int T_1 F_14 ( char * V_30 , const char * V_3 )
{
if ( ! V_3 || strlen ( V_3 ) == 0 )
return - 1 ;
#ifdef F_15
strcpy ( V_30 , V_3 ) ;
#endif
return 0 ;
}
static int T_1 F_16 ( V_23 V_31 , char * V_32 , char * V_30 )
{
const char * V_3 ;
V_30 [ 0 ] = '\0' ;
V_3 = F_17 ( V_31 , V_32 , V_30 ) ;
return F_14 ( V_30 , V_3 ) ;
}
void T_1 F_18 ( void )
{
F_19 ( V_33 , & V_34 ) ;
F_20 () ;
F_21 ( L_1 ,
V_35 ) ;
}
