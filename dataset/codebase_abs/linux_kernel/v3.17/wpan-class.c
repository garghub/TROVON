static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
int V_8 ;
int V_9 , V_10 = 0 ;
F_3 ( & V_7 -> V_11 ) ;
for ( V_9 = 0 ; V_9 < 32 ; V_9 ++ ) {
V_8 = snprintf ( V_5 + V_10 , V_12 - V_10 ,
L_1 , V_7 -> V_13 [ V_9 ] ) ;
if ( V_8 < 0 )
break;
V_10 += V_8 ;
}
F_4 ( & V_7 -> V_11 ) ;
return V_10 ;
}
static void F_5 ( struct V_1 * V_14 )
{
struct V_6 * V_7 = F_2 ( V_14 , struct V_6 , V_2 ) ;
F_6 ( V_7 ) ;
}
static int F_7 ( struct V_1 * V_2 , const void * V_15 )
{
return ! strcmp ( F_8 ( V_2 ) , ( const char * ) V_15 ) ;
}
struct V_6 * F_9 ( const char * V_16 )
{
struct V_1 * V_2 ;
if ( F_10 ( ! V_16 ) )
return NULL ;
V_2 = F_11 ( & V_17 , NULL , V_16 , F_7 ) ;
if ( ! V_2 )
return NULL ;
return F_2 ( V_2 , struct V_6 , V_2 ) ;
}
static int F_12 ( struct V_1 * V_2 , void * V_18 )
{
struct V_19 * V_20 = V_18 ;
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
return V_20 -> V_21 ( V_7 , V_20 -> V_15 ) ;
}
int F_13 ( int (* V_21)( struct V_6 * V_7 , void * V_15 ) ,
void * V_15 )
{
struct V_19 V_20 = {
. V_21 = V_21 ,
. V_15 = V_15 ,
} ;
return F_14 ( & V_17 , NULL ,
& V_20 , F_12 ) ;
}
static int F_15 ( int V_22 )
{
return V_22 >= 0 ;
}
struct V_6 * F_16 ( T_2 V_23 )
{
struct V_6 * V_7 = F_17 ( sizeof( * V_7 ) + V_23 ,
V_24 ) ;
if ( ! V_7 )
goto V_25;
F_3 ( & V_26 ) ;
V_7 -> V_22 = V_27 ++ ;
if ( F_18 ( ! F_15 ( V_7 -> V_22 ) ) ) {
V_27 -- ;
F_4 ( & V_26 ) ;
F_6 ( V_7 ) ;
goto V_25;
}
F_4 ( & V_26 ) ;
F_19 ( & V_7 -> V_11 ) ;
F_20 ( & V_7 -> V_2 ) ;
F_21 ( & V_7 -> V_2 , L_2 , V_7 -> V_22 ) ;
V_7 -> V_2 . V_28 = & V_17 ;
V_7 -> V_29 = - 1 ;
V_7 -> V_30 = 0 ;
return V_7 ;
V_25:
return NULL ;
}
int F_22 ( struct V_6 * V_7 )
{
return F_23 ( & V_7 -> V_2 ) ;
}
void F_24 ( struct V_6 * V_7 )
{
F_25 ( & V_7 -> V_2 ) ;
}
void F_26 ( struct V_6 * V_7 )
{
F_27 ( & V_7 -> V_2 ) ;
}
static int T_3 F_28 ( void )
{
int V_31 ;
V_31 = F_29 ( & V_17 ) ;
if ( V_31 )
goto V_32;
V_31 = F_30 () ;
if ( V_31 )
goto V_33;
return 0 ;
V_33:
F_31 ( & V_17 ) ;
V_32:
return V_31 ;
}
static void T_4 F_32 ( void )
{
F_33 () ;
F_31 ( & V_17 ) ;
}
