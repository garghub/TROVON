void T_1 F_1 ( void )
{
if ( ! F_2 ( V_1 ) )
return;
V_2 . V_3 = V_4 - 1 ;
F_3 ( & V_5 , & V_2 ) ;
V_6 = V_4 ;
}
void * F_4 ( unsigned long V_7 , const char * V_8 )
{
struct V_9 * V_10 ;
V_7 = F_5 ( V_7 ) ;
#ifdef F_6
F_7 ( L_1 , V_7 ) ;
#endif
V_10 = F_8 ( sizeof( struct V_9 ) , V_11 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_8 = V_8 ;
if ( F_9 ( & V_2 , V_10 , V_7 , 0 , V_12 , V_13 , NULL , NULL ) < 0 ) {
F_10 ( V_10 ) ;
return NULL ;
}
V_6 -= V_7 ;
#ifdef F_6
F_7 ( L_2 , V_10 -> V_14 ) ;
#endif
return ( void * ) F_11 ( V_10 -> V_14 ) ;
}
void * T_1 F_12 ( unsigned long V_7 , struct V_9 * V_10 )
{
unsigned long V_14 ;
V_7 = F_5 ( V_7 ) ;
V_14 = V_15 + V_6 - V_7 ;
#ifdef F_6
F_7 ( L_3 , V_7 ) ;
#endif
if ( F_9 ( & V_2 , V_10 , V_7 , V_14 , V_12 , V_13 , NULL , NULL ) < 0 ) {
F_7 ( L_4 ) ;
if ( F_9 ( & V_2 , V_10 , V_7 , 0 , V_12 , V_13 , NULL , NULL ) < 0 )
return NULL ;
}
V_6 -= V_7 ;
#ifdef F_6
F_7 ( L_5 , V_10 -> V_14 ) ;
#endif
return ( void * ) F_11 ( V_10 -> V_14 ) ;
}
void F_13 ( void * V_16 )
{
unsigned long V_14 = F_14 ( V_16 ) ;
struct V_9 * * V_17 , * V_10 ;
unsigned long V_7 ;
for ( V_17 = & V_2 . V_18 ; ( V_10 = * V_17 ) ; V_17 = & V_10 -> V_19 ) {
if ( V_10 -> V_14 != V_14 )
continue;
* V_17 = V_10 -> V_19 ;
V_7 = V_10 -> V_3 - V_14 ;
#ifdef F_6
F_7 ( L_6 , V_7 , V_16 ) ;
#endif
V_6 += V_7 ;
F_10 ( V_10 ) ;
return;
}
F_7 ( L_7 , V_16 ) ;
}
unsigned long F_15 ( void )
{
#ifdef F_6
F_7 ( L_8 , V_6 ) ;
#endif
return V_6 ;
}
