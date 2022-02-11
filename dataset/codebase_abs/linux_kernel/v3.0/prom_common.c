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
void * V_12 ;
int V_13 ;
V_12 = F_4 ( V_7 , V_14 ) ;
if ( ! V_12 )
return - V_15 ;
memcpy ( V_12 , V_10 , V_7 ) ;
V_13 = - V_16 ;
F_5 ( & V_17 ) ;
F_6 ( & V_18 ) ;
V_11 = & V_9 -> V_19 ;
while ( * V_11 ) {
struct V_5 * V_6 = * V_11 ;
if ( ! strcasecmp ( V_6 -> V_3 , V_3 ) ) {
void * V_20 = V_6 -> V_8 ;
int V_21 ;
V_21 = F_7 ( V_9 -> V_22 , V_3 , V_10 , V_7 ) ;
V_13 = - V_23 ;
if ( V_21 >= 0 ) {
V_6 -> V_8 = V_12 ;
V_6 -> V_24 = V_7 ;
if ( F_8 ( V_6 ) )
F_9 ( V_20 ) ;
F_10 ( V_6 ) ;
V_13 = 0 ;
}
break;
}
V_11 = & ( * V_11 ) -> V_25 ;
}
F_11 ( & V_18 ) ;
F_12 ( & V_17 ) ;
return V_13 ;
}
int F_13 ( const char * V_26 , const char * V_27 , int V_7 )
{
while ( V_7 > 0 ) {
int V_28 ;
if ( ! strcmp ( V_26 , V_27 ) )
return 1 ;
V_28 = strlen ( V_26 ) + 1 ;
V_26 += V_28 ;
V_7 -= V_28 ;
}
return 0 ;
}
static int T_1 F_14 ( char * V_29 , const char * V_3 )
{
if ( ! V_3 || strlen ( V_3 ) == 0 )
return - 1 ;
#ifdef F_15
strcpy ( V_29 , V_3 ) ;
#endif
return 0 ;
}
static int T_1 F_16 ( V_22 V_30 , char * V_31 , char * V_29 )
{
const char * V_3 ;
V_29 [ 0 ] = '\0' ;
V_3 = F_17 ( V_30 , V_31 , V_29 ) ;
return F_14 ( V_29 , V_3 ) ;
}
void T_1 F_18 ( void )
{
F_19 ( V_32 , & V_33 ) ;
F_20 () ;
F_21 ( L_1 ,
V_34 ) ;
}
