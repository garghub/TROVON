static void F_1 ( unsigned int V_1 )
{
T_1 V_2 , V_3 , V_4 , V_5 ;
int V_6 ;
V_2 = F_2 () ;
V_5 = V_2 + ( T_1 ) V_7 * V_1 ;
V_3 = V_2 ;
for ( V_6 = 0 ; ; V_6 ++ ) {
F_3 ( & V_8 ) ;
V_4 = V_9 ;
V_3 = F_2 () ;
V_9 = V_3 ;
F_4 ( & V_8 ) ;
if ( F_5 ( ! ( V_6 & 7 ) ) ) {
if ( V_3 > V_5 || V_6 > 10000000 )
break;
F_6 () ;
F_7 () ;
}
if ( F_5 ( V_4 > V_3 ) ) {
F_3 ( & V_8 ) ;
V_10 = F_8 ( V_10 , V_4 - V_3 ) ;
V_11 ++ ;
F_4 ( & V_8 ) ;
}
}
F_9 ( ! ( V_3 - V_2 ) ,
L_1 ,
V_3 - V_2 , V_5 - V_2 ) ;
}
static inline unsigned int F_10 ( int V_12 )
{
return ( F_11 ( F_12 ( V_12 ) ) > 1 ) ? 2 : 20 ;
}
void F_13 ( int V_12 )
{
int V_13 = 2 ;
if ( F_14 () )
return;
if ( V_14 ) {
if ( V_12 == ( V_15 - 1 ) || V_16 != V_17 )
F_15 (
L_2 ) ;
return;
}
F_16 ( & V_18 , 0 ) ;
while ( F_17 ( & V_19 ) != V_13 - 1 )
F_6 () ;
F_18 ( & V_19 ) ;
F_1 ( F_10 ( V_12 ) ) ;
while ( F_17 ( & V_18 ) != V_13 - 1 )
F_6 () ;
if ( V_11 ) {
F_19 ( L_3 ,
F_20 () , V_12 ) ;
F_19 ( L_4
L_5 , V_10 ) ;
F_21 ( L_6 ) ;
} else {
F_22 ( L_7 ,
F_20 () , V_12 ) ;
}
F_16 ( & V_19 , 0 ) ;
V_11 = 0 ;
V_10 = 0 ;
V_9 = 0 ;
F_18 ( & V_18 ) ;
}
void F_23 ( void )
{
int V_13 = 2 ;
if ( F_14 () || V_14 )
return;
F_18 ( & V_19 ) ;
while ( F_17 ( & V_19 ) != V_13 )
F_6 () ;
F_1 ( F_10 ( F_20 () ) ) ;
F_18 ( & V_18 ) ;
while ( F_17 ( & V_18 ) != V_13 )
F_6 () ;
}
