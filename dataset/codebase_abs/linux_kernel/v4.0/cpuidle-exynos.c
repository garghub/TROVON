static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
int V_6 ;
V_7 -> V_8 () ;
F_2 ( V_2 , & V_9 ) ;
V_6 = V_2 -> V_10 ? V_7 -> V_11 ()
: V_7 -> V_12 () ;
if ( V_6 )
V_5 = V_6 ;
F_2 ( V_2 , & V_9 ) ;
V_7 -> V_13 () ;
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
int V_5 )
{
int V_14 = V_5 ;
if ( F_4 () > 1 || V_2 -> V_10 != 0 )
V_14 = V_4 -> V_15 ;
if ( V_14 == 0 )
return F_5 ( V_2 , V_4 , V_14 ) ;
F_6 () ;
return V_14 ;
}
static int F_7 ( struct V_16 * V_17 )
{
int V_6 ;
if ( F_8 ( L_1 ) ) {
V_7 = V_17 -> V_2 . V_18 ;
V_6 = F_9 ( & V_19 ,
V_20 ) ;
} else {
F_6 = ( void * ) ( V_17 -> V_2 . V_18 ) ;
V_6 = F_9 ( & V_21 , NULL ) ;
}
if ( V_6 ) {
F_10 ( & V_17 -> V_2 , L_2 ) ;
return V_6 ;
}
return 0 ;
}
