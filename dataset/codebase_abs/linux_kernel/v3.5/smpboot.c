void T_1 F_1 ( void )
{
int V_1 = F_2 () ;
F_3 ( V_1 , 1 ) ;
F_4 ( V_1 , 1 ) ;
F_5 ( V_2 ) = V_3 ;
F_6 () ;
}
void T_1 F_7 ( unsigned int V_4 )
{
long V_5 ;
int V_1 , V_6 ;
int V_7 = F_2 () ;
F_8 () -> V_1 = V_7 ;
V_5 = F_9 ( V_8 -> V_9 , F_10 ( V_7 ) ) ;
if ( V_5 != 0 )
F_11 ( L_1 , V_5 ) ;
F_12 () ;
V_10 = ( unsigned long ) & V_11 ;
V_6 = 1 ;
for ( V_1 = 0 ; V_1 < V_12 ; ++ V_1 ) {
struct V_13 * V_14 ;
if ( V_1 == V_7 )
continue;
if ( ! F_13 ( V_1 ) ) {
F_14 ( V_15 , V_1 ) = 0 ;
F_14 ( V_16 , V_1 ) = ( unsigned long ) V_17 ;
continue;
}
V_14 = F_15 ( V_1 ) ;
if ( F_16 ( V_14 ) )
F_17 ( L_2 , V_1 ) ;
V_14 -> V_18 . V_19 = ( unsigned long ) V_20 ;
F_14 ( V_15 , V_1 ) = F_18 ( V_14 ) ;
F_14 ( V_16 , V_1 ) = V_14 -> V_18 . V_19 ;
++ V_6 ;
}
F_19 ( V_6 > ( V_4 ? V_4 : 1 ) ) ;
F_20 ( V_21 ) ;
if ( F_21 ( V_22 ) > 1 ) {
F_22 () ;
F_23 () ;
}
}
static T_1 int F_24 ( void )
{
long V_5 = F_9 ( V_8 -> V_9 , & V_23 ) ;
if ( V_5 != 0 )
F_25 ( L_3 ,
V_5 ) ;
return 0 ;
}
static void T_2 V_20 ( void )
{
int V_24 = F_2 () ;
F_26 ( V_25 [ V_24 ] ) ;
F_27 () ;
F_5 ( V_26 ) = V_27 ;
F_28 ( & V_28 . V_29 ) ;
V_8 -> V_30 = & V_28 ;
if ( V_8 -> V_31 )
F_29 () ;
F_30 ( & V_28 , V_8 ) ;
F_6 () ;
F_31 () ;
if ( F_32 ( V_24 , & V_32 ) ) {
F_25 ( L_4 , V_24 ) ;
for (; ; )
F_31 () ;
}
V_17 () ;
}
void T_2 V_11 ( void )
{
F_33 () ;
F_19 ( F_34 () ) ;
F_35 () ;
F_36 ( F_2 () ) ;
F_37 () ;
F_3 ( F_2 () , 1 ) ;
F_38 () ;
F_5 ( V_2 ) = V_3 ;
F_39 ( 0 ) ;
F_40 () ;
F_41 () ;
F_42 () ;
}
int T_2 F_43 ( unsigned int V_1 , struct V_13 * V_33 )
{
static int V_34 ;
for (; ! F_44 ( V_1 , & V_32 ) ; V_34 ++ ) {
if ( V_34 >= 50000 ) {
F_45 ( L_5 , V_1 ) ;
F_31 () ;
return - V_35 ;
}
F_46 ( 100 ) ;
}
F_31 () ;
F_14 ( V_2 , V_1 ) = V_36 ;
F_47 ( V_1 , V_37 ) ;
while ( ! F_44 ( V_1 , V_38 ) )
F_48 () ;
return 0 ;
}
static void F_49 ( void )
{
F_17 ( L_6 ) ;
}
void T_1 F_50 ( unsigned int V_4 )
{
int V_1 , V_39 , V_5 ;
V_10 = ( unsigned long ) & F_49 ;
F_51 ( & V_23 , V_38 ) ;
for ( V_1 = F_52 ( & V_23 ) ;
( V_39 = F_53 ( V_1 , & V_23 ) ) < V_40 ;
V_1 = V_39 )
;
V_5 = F_9 ( V_8 -> V_9 , F_10 ( V_1 ) ) ;
if ( V_5 != 0 )
F_11 ( L_7 , V_1 , V_5 ) ;
}
