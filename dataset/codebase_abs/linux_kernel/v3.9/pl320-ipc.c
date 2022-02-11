static inline void F_1 ( int V_1 , int V_2 )
{
F_2 ( F_3 ( V_1 ) , V_3 + F_4 ( V_2 ) ) ;
F_2 ( F_3 ( V_1 ) , V_3 + F_5 ( V_2 ) ) ;
}
static inline void F_6 ( int V_1 , int V_2 )
{
F_2 ( F_3 ( V_1 ) , V_3 + F_7 ( V_2 ) ) ;
F_2 ( F_3 ( V_1 ) , V_3 + F_8 ( V_2 ) ) ;
}
static void F_9 ( int V_2 , T_1 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 7 ; V_5 ++ )
F_2 ( V_4 [ V_5 ] , V_3 + F_10 ( V_2 , V_5 ) ) ;
F_2 ( 0x1 , V_3 + F_11 ( V_2 ) ) ;
}
static T_1 F_12 ( int V_2 , T_1 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < 7 ; V_5 ++ )
V_4 [ V_5 ] = F_13 ( V_3 + F_10 ( V_2 , V_5 ) ) ;
return V_4 [ 1 ] ;
}
int F_14 ( T_1 * V_4 )
{
int V_6 ;
F_15 ( & V_7 ) ;
F_16 ( & V_8 ) ;
F_9 ( V_9 , V_4 ) ;
V_6 = F_17 ( & V_8 ,
F_18 ( 1000 ) ) ;
if ( V_6 == 0 ) {
V_6 = - V_10 ;
goto V_11;
}
V_6 = F_12 ( V_9 , V_4 ) ;
V_11:
F_19 ( & V_7 ) ;
return V_6 ;
}
static T_2 F_20 ( int V_12 , void * V_13 )
{
T_1 V_14 ;
T_1 V_4 [ 7 ] ;
V_14 = F_13 ( V_3 + F_21 ( 1 ) ) ;
if ( V_14 & F_22 ( V_9 ) ) {
F_2 ( 0 , V_3 + F_11 ( V_9 ) ) ;
F_23 ( & V_8 ) ;
}
if ( V_14 & F_22 ( V_15 ) ) {
F_12 ( V_15 , V_4 ) ;
F_24 ( & V_16 , V_4 [ 0 ] , V_4 + 1 ) ;
F_2 ( 2 , V_3 + F_11 ( V_15 ) ) ;
}
return V_17 ;
}
int F_25 ( struct V_18 * V_19 )
{
return F_26 ( & V_16 , V_19 ) ;
}
int F_27 ( struct V_18 * V_19 )
{
return F_28 ( & V_16 , V_19 ) ;
}
static int F_29 ( struct V_20 * V_21 , const struct V_22 * V_23 )
{
int V_6 ;
V_3 = F_30 ( V_21 -> V_24 . V_25 , F_31 ( & V_21 -> V_24 ) ) ;
if ( V_3 == NULL )
return - V_26 ;
F_2 ( 0 , V_3 + F_11 ( V_9 ) ) ;
V_27 = V_21 -> V_12 [ 0 ] ;
V_6 = F_32 ( V_27 , F_20 , 0 , F_33 ( & V_21 -> V_13 ) , NULL ) ;
if ( V_6 < 0 )
goto V_28;
F_2 ( F_3 ( V_29 ) ,
V_3 + F_34 ( V_9 ) ) ;
F_2 ( F_3 ( V_30 ) ,
V_3 + F_4 ( V_9 ) ) ;
F_2 ( F_3 ( V_30 ) | F_3 ( V_29 ) ,
V_3 + F_5 ( V_9 ) ) ;
F_2 ( F_3 ( V_30 ) ,
V_3 + F_34 ( V_15 ) ) ;
F_2 ( F_3 ( V_29 ) ,
V_3 + F_4 ( V_15 ) ) ;
F_2 ( F_3 ( V_30 ) | F_3 ( V_29 ) ,
V_3 + F_5 ( V_15 ) ) ;
return 0 ;
V_28:
F_35 ( V_3 ) ;
return V_6 ;
}
static int T_3 F_36 ( void )
{
return F_37 ( & V_31 ) ;
}
