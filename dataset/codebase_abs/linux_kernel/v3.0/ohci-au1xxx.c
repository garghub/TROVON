static void F_1 ( void )
{
#ifndef F_2
F_3 ( V_1 , V_2 ) ;
F_4 () ;
F_5 ( 1000 ) ;
F_3 ( F_6 ( V_2 ) | V_3 , V_2 ) ;
F_4 () ;
F_5 ( 1000 ) ;
while ( F_6 ( V_2 ) ,
! ( F_6 ( V_2 ) & V_4 ) )
F_5 ( 1000 ) ;
#else
F_3 ( F_6 ( V_2 ) | V_1 , V_2 ) ;
F_4 () ;
F_5 ( 1000 ) ;
F_3 ( F_6 ( V_2 ) | V_3 , V_2 ) ;
F_4 () ;
F_5 ( 2000 ) ;
#endif
}
static void F_7 ( void )
{
#ifdef F_2
F_3 ( F_6 ( V_2 ) & ~ V_5 , V_2 ) ;
F_4 () ;
F_5 ( 1000 ) ;
#endif
F_3 ( F_6 ( V_2 ) & ~ V_1 , V_2 ) ;
F_4 () ;
}
static int T_1 F_8 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_9 ( V_7 ) ;
int V_10 ;
F_10 ( V_9 , L_1 , V_9 ) ;
if ( ( V_10 = F_11 ( V_9 ) ) < 0 )
return V_10 ;
if ( ( V_10 = F_12 ( V_9 ) ) < 0 ) {
F_13 ( L_2 , V_7 -> V_11 . V_12 ) ;
F_14 ( V_7 ) ;
return V_10 ;
}
return 0 ;
}
static int F_15 ( struct V_13 * V_14 )
{
int V_10 ;
struct V_6 * V_7 ;
if ( F_16 () )
return - V_15 ;
#if F_17 ( F_2 ) && F_17 ( V_16 )
if ( ! ( F_18 () & 0xff ) ) {
F_19 ( V_17 L_3 ,
V_14 -> V_18 ) ;
F_19 ( V_17 L_4
L_5 , V_14 -> V_18 ) ;
return - V_15 ;
}
#endif
if ( V_14 -> V_19 [ 1 ] . V_20 != V_21 ) {
F_20 ( L_6 ) ;
return - V_22 ;
}
V_7 = F_21 ( & V_23 , & V_14 -> V_24 , L_7 ) ;
if ( ! V_7 )
return - V_22 ;
V_7 -> V_25 = V_14 -> V_19 [ 0 ] . V_26 ;
V_7 -> V_27 = V_14 -> V_19 [ 0 ] . V_28 - V_14 -> V_19 [ 0 ] . V_26 + 1 ;
if ( ! F_22 ( V_7 -> V_25 , V_7 -> V_27 , V_29 ) ) {
F_20 ( L_8 ) ;
V_10 = - V_30 ;
goto V_31;
}
V_7 -> V_32 = F_23 ( V_7 -> V_25 , V_7 -> V_27 ) ;
if ( ! V_7 -> V_32 ) {
F_20 ( L_9 ) ;
V_10 = - V_22 ;
goto V_33;
}
F_1 () ;
F_24 ( F_9 ( V_7 ) ) ;
V_10 = F_25 ( V_7 , V_14 -> V_19 [ 1 ] . V_26 ,
V_34 | V_35 ) ;
if ( V_10 == 0 ) {
F_26 ( V_14 , V_7 ) ;
return V_10 ;
}
F_7 () ;
F_27 ( V_7 -> V_32 ) ;
V_33:
F_28 ( V_7 -> V_25 , V_7 -> V_27 ) ;
V_31:
F_29 ( V_7 ) ;
return V_10 ;
}
static int F_30 ( struct V_13 * V_14 )
{
struct V_6 * V_7 = F_31 ( V_14 ) ;
F_32 ( V_7 ) ;
F_7 () ;
F_27 ( V_7 -> V_32 ) ;
F_28 ( V_7 -> V_25 , V_7 -> V_27 ) ;
F_29 ( V_7 ) ;
F_26 ( V_14 , NULL ) ;
return 0 ;
}
static int F_33 ( struct V_36 * V_24 )
{
struct V_6 * V_7 = F_34 ( V_24 ) ;
struct V_8 * V_9 = F_9 ( V_7 ) ;
unsigned long V_20 ;
int V_37 ;
V_37 = 0 ;
F_35 ( & V_9 -> V_38 , V_20 ) ;
if ( V_7 -> V_39 != V_40 ) {
V_37 = - V_41 ;
goto V_42;
}
F_36 ( V_9 , V_43 , & V_9 -> V_32 -> V_44 ) ;
( void ) F_37 ( V_9 , & V_9 -> V_32 -> V_44 ) ;
F_38 ( V_45 , & V_7 -> V_20 ) ;
F_7 () ;
V_42:
F_39 ( & V_9 -> V_38 , V_20 ) ;
return V_37 ;
}
static int F_40 ( struct V_36 * V_24 )
{
struct V_6 * V_7 = F_34 ( V_24 ) ;
F_1 () ;
F_41 ( V_45 , & V_7 -> V_20 ) ;
F_42 ( V_7 ) ;
return 0 ;
}
