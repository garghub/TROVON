static int F_1 ( int * V_1 )
{
T_1 V_2 ;
if ( V_3 || V_4 )
return 0 ;
if ( V_5 . V_6 != V_7 )
return 0 ;
if ( ! V_8 || F_2 () < 6 )
return 0 ;
F_3 ( V_9 , V_2 ) ;
* V_1 = F_4 ( unsigned , V_10 , V_2 & 0xff ) ;
return ! ! ( V_2 & V_11 ) ;
}
static void F_5 ( void )
{
F_6 ( V_12 , & F_7 ( V_13 ) ) ;
F_8 () ;
}
static void F_9 ( char * type , int * V_14 , int V_15 )
{
if ( * V_14 == 0 )
F_10 ( V_16 L_1 , F_11 () ) ;
* V_14 = 1 ;
F_10 ( V_17 L_2 , type , V_15 ) ;
}
static void F_12 ( int V_1 , int V_18 )
{
unsigned long * V_19 = ( void * ) & F_7 ( V_13 ) ;
unsigned long V_20 ;
int V_14 = 0 ;
int V_21 ;
F_13 ( & V_22 , V_20 ) ;
for ( V_21 = 0 ; V_21 < V_1 ; V_21 ++ ) {
T_1 V_23 ;
if ( F_14 ( V_21 , V_19 ) )
continue;
F_3 ( F_15 ( V_21 ) , V_23 ) ;
if ( V_23 & V_24 ) {
if ( F_16 ( V_21 , V_19 ) && ! V_18 )
F_9 ( L_3 , & V_14 , V_21 ) ;
F_17 ( V_21 , F_7 ( V_25 ) ) ;
continue;
}
V_23 &= ~ V_26 ;
V_23 |= V_24 | V_27 ;
F_18 ( F_15 ( V_21 ) , V_23 ) ;
F_3 ( F_15 ( V_21 ) , V_23 ) ;
if ( V_23 & V_24 ) {
if ( ! F_19 ( V_21 , V_19 ) && ! V_18 )
F_9 ( L_4 , & V_14 , V_21 ) ;
F_17 ( V_21 , F_7 ( V_25 ) ) ;
} else {
F_20 ( ! F_14 ( V_21 , F_7 ( V_25 ) ) ) ;
}
}
F_21 ( & V_22 , V_20 ) ;
if ( V_14 )
F_10 ( V_17 L_5 ) ;
}
void F_22 ( void )
{
unsigned long V_20 ;
int V_1 ;
if ( ! F_23 ( F_24 ( & V_28 ) ) || ! F_1 ( & V_1 ) )
return;
F_25 ( V_20 ) ;
F_6 ( V_12 , & F_7 ( V_13 ) ) ;
F_26 ( V_20 ) ;
}
void F_27 ( void )
{
unsigned long V_20 ;
int V_21 ;
int V_1 ;
T_1 V_23 ;
if ( ! F_1 ( & V_1 ) )
return;
F_13 ( & V_22 , V_20 ) ;
for ( V_21 = 0 ; V_21 < V_1 ; V_21 ++ ) {
if ( ! F_14 ( V_21 , F_7 ( V_13 ) ) )
continue;
F_3 ( F_15 ( V_21 ) , V_23 ) ;
V_23 &= ~ ( V_24 | V_26 ) ;
F_18 ( F_15 ( V_21 ) , V_23 ) ;
F_17 ( V_21 , F_7 ( V_13 ) ) ;
}
F_21 ( & V_22 , V_20 ) ;
}
void F_28 ( int V_29 )
{
int V_1 ;
int V_30 ;
T_2 V_31 ;
if ( ! F_1 ( & V_1 ) )
return;
if ( ! F_29 ( & V_31 , V_32 ) )
return;
F_30 ( V_31 , & V_33 -> V_34 ) ;
F_31 (cpu) {
if ( V_30 == V_29 )
continue;
if ( F_32 ( V_33 , F_33 ( V_30 ) ) )
continue;
if ( F_1 ( & V_1 ) )
F_12 ( V_1 , 0 ) ;
}
F_32 ( V_33 , V_31 ) ;
F_34 ( V_31 ) ;
}
void F_35 ( void )
{
int V_1 ;
if ( F_1 ( & V_1 ) )
F_12 ( V_1 , 0 ) ;
}
static void F_36 ( void )
{
int V_1 ;
if ( ! F_1 ( & V_1 ) )
return;
V_35 = F_5 ;
F_12 ( V_1 , 1 ) ;
F_37 ( V_36 , V_37 | V_38 ) ;
F_22 () ;
}
void F_38 ( struct V_39 * V_40 )
{
F_39 ( V_40 ) ;
F_36 () ;
}
