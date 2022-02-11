static void F_1 ( unsigned int V_1 )
{
T_1 V_2 , V_3 , V_4 , V_5 ;
int V_6 ;
F_2 () ;
V_2 = F_3 () ;
F_2 () ;
V_5 = V_2 + ( T_1 ) V_7 * V_1 ;
V_3 = V_2 ;
for ( V_6 = 0 ; ; V_6 ++ ) {
F_4 ( & V_8 ) ;
V_4 = V_9 ;
F_2 () ;
V_3 = F_3 () ;
F_2 () ;
V_9 = V_3 ;
F_5 ( & V_8 ) ;
if ( F_6 ( ! ( V_6 & 7 ) ) ) {
if ( V_3 > V_5 || V_6 > 10000000 )
break;
F_7 () ;
F_8 () ;
}
if ( F_6 ( V_4 > V_3 ) ) {
F_4 ( & V_8 ) ;
V_10 = F_9 ( V_10 , V_4 - V_3 ) ;
V_11 ++ ;
F_5 ( & V_8 ) ;
}
}
F_10 ( ! ( V_3 - V_2 ) ,
L_1 ,
V_3 - V_2 , V_5 - V_2 ) ;
}
static inline unsigned int F_11 ( int V_12 )
{
return ( F_12 ( F_13 ( V_12 ) ) > 1 ) ? 2 : 20 ;
}
void F_14 ( int V_12 )
{
int V_13 = 2 ;
if ( F_15 () )
return;
if ( V_14 ) {
if ( V_12 == ( V_15 - 1 ) || V_16 != V_17 )
F_16 (
L_2 ) ;
return;
}
F_17 ( & V_18 , 0 ) ;
while ( F_18 ( & V_19 ) != V_13 - 1 )
F_7 () ;
F_19 ( & V_19 ) ;
F_1 ( F_11 ( V_12 ) ) ;
while ( F_18 ( & V_18 ) != V_13 - 1 )
F_7 () ;
if ( V_11 ) {
F_20 ( L_3 ,
F_21 () , V_12 ) ;
F_20 ( L_4
L_5 , V_10 ) ;
F_22 ( L_6 ) ;
} else {
F_23 ( L_7 ,
F_21 () , V_12 ) ;
}
F_17 ( & V_19 , 0 ) ;
V_11 = 0 ;
V_10 = 0 ;
V_9 = 0 ;
F_19 ( & V_18 ) ;
}
void F_24 ( void )
{
int V_13 = 2 ;
if ( F_15 () || V_14 )
return;
F_19 ( & V_19 ) ;
while ( F_18 ( & V_19 ) != V_13 )
F_7 () ;
F_1 ( F_11 ( F_21 () ) ) ;
F_19 ( & V_18 ) ;
while ( F_18 ( & V_18 ) != V_13 )
F_7 () ;
}
