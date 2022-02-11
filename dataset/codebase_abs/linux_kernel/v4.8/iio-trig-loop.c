static int F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
F_2 () ;
do {
F_3 ( V_3 ) ;
} while ( F_4 ( ! F_5 ( NULL ) ) );
return 0 ;
}
static int F_6 ( struct V_2 * V_3 , bool V_4 )
{
struct V_5 * V_6 = F_7 ( V_3 ) ;
if ( V_4 ) {
V_6 -> V_7 = F_8 ( F_1 ,
V_3 , V_3 -> V_8 ) ;
if ( F_9 ( F_10 ( V_6 -> V_7 ) ) ) {
F_11 ( & V_3 -> V_9 ,
L_1 ) ;
return F_12 ( V_6 -> V_7 ) ;
}
} else {
F_13 ( V_6 -> V_7 ) ;
}
return 0 ;
}
static struct V_10 * F_14 ( const char * V_8 )
{
struct V_5 * V_11 ;
int V_12 ;
V_11 = F_15 ( sizeof( * V_11 ) , V_13 ) ;
if ( ! V_11 )
return F_16 ( - V_14 ) ;
V_11 -> V_15 . V_16 = F_17 ( L_2 , V_8 ) ;
if ( ! V_11 -> V_15 . V_16 ) {
V_12 = - V_14 ;
goto V_17;
}
F_18 ( V_11 -> V_15 . V_16 , V_11 ) ;
V_11 -> V_15 . V_16 -> V_18 = & V_19 ;
V_12 = F_19 ( V_11 -> V_15 . V_16 ) ;
if ( V_12 )
goto V_20;
F_20 ( & V_11 -> V_15 , V_8 , & V_21 ) ;
return & V_11 -> V_15 ;
V_20:
F_21 ( V_11 -> V_15 . V_16 ) ;
V_17:
F_22 ( V_11 ) ;
return F_16 ( V_12 ) ;
}
static int F_23 ( struct V_10 * V_15 )
{
struct V_5 * V_11 ;
V_11 = F_7 ( V_15 -> V_16 ) ;
F_24 ( V_15 -> V_16 ) ;
F_21 ( V_15 -> V_16 ) ;
F_22 ( V_11 ) ;
return 0 ;
}
