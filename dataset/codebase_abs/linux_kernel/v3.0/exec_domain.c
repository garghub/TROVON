static void
F_1 ( int V_1 , struct V_2 * V_3 )
{
F_2 ( 0 ) ;
if ( F_3 () -> V_4 -> V_5 != F_1 )
F_3 () -> V_4 -> V_5 ( V_1 , V_3 ) ;
else
F_4 ( V_6 , V_7 , 1 ) ;
}
static struct V_4 *
F_5 ( unsigned int V_8 )
{
unsigned int V_9 = V_8 ( V_8 ) ;
struct V_4 * V_10 ;
F_6 ( & V_11 ) ;
for ( V_10 = V_12 ; V_10 ; V_10 = V_10 -> V_13 ) {
if ( V_9 >= V_10 -> V_14 && V_9 <= V_10 -> V_15 )
if ( F_7 ( V_10 -> V_16 ) )
goto V_17;
}
#ifdef F_8
F_9 ( & V_11 ) ;
F_10 ( L_1 , V_9 ) ;
F_6 ( & V_11 ) ;
for ( V_10 = V_12 ; V_10 ; V_10 = V_10 -> V_13 ) {
if ( V_9 >= V_10 -> V_14 && V_9 <= V_10 -> V_15 )
if ( F_7 ( V_10 -> V_16 ) )
goto V_17;
}
#endif
V_10 = & V_18 ;
V_17:
F_9 ( & V_11 ) ;
return ( V_10 ) ;
}
int
F_11 ( struct V_4 * V_10 )
{
struct V_4 * V_19 ;
int V_20 = - V_21 ;
if ( V_10 == NULL )
return - V_22 ;
if ( V_10 -> V_13 != NULL )
return - V_21 ;
F_12 ( & V_11 ) ;
for ( V_19 = V_12 ; V_19 ; V_19 = V_19 -> V_13 ) {
if ( V_19 == V_10 )
goto V_17;
}
V_10 -> V_13 = V_12 ;
V_12 = V_10 ;
V_20 = 0 ;
V_17:
F_13 ( & V_11 ) ;
return ( V_20 ) ;
}
int
F_14 ( struct V_4 * V_10 )
{
struct V_4 * * V_23 ;
V_23 = & V_12 ;
F_12 ( & V_11 ) ;
for ( V_23 = & V_12 ; * V_23 ; V_23 = & ( * V_23 ) -> V_13 ) {
if ( V_10 == * V_23 )
goto V_24;
}
F_13 ( & V_11 ) ;
return - V_22 ;
V_24:
* V_23 = V_10 -> V_13 ;
V_10 -> V_13 = NULL ;
F_13 ( & V_11 ) ;
return 0 ;
}
int F_15 ( unsigned int V_8 )
{
struct V_4 * V_25 = F_3 () -> V_4 ;
F_3 () -> V_4 = F_5 ( V_8 ) ;
V_7 -> V_8 = V_8 ;
F_16 ( V_25 -> V_16 ) ;
return 0 ;
}
static int F_17 ( struct V_26 * V_27 , void * V_28 )
{
struct V_4 * V_10 ;
F_6 ( & V_11 ) ;
for ( V_10 = V_12 ; V_10 ; V_10 = V_10 -> V_13 )
F_18 ( V_27 , L_2 ,
V_10 -> V_14 , V_10 -> V_15 , V_10 -> V_29 ,
F_19 ( V_10 -> V_16 ) ) ;
F_9 ( & V_11 ) ;
return 0 ;
}
static int F_20 ( struct V_30 * V_30 , struct V_31 * V_31 )
{
return F_21 ( V_31 , F_17 , NULL ) ;
}
static int T_1 F_22 ( void )
{
F_23 ( L_3 , 0 , NULL , & V_32 ) ;
return 0 ;
}
