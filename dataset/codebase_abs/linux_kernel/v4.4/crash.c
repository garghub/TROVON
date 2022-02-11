static int F_1 ( struct V_1 * V_2 )
{
if ( V_3 == F_2 () )
longjmp ( V_4 , 1 ) ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
static T_1 V_5 = V_6 ;
int V_7 = F_2 () ;
if ( ! F_4 ( V_7 ) )
return;
F_5 () ;
if ( ! F_6 ( V_7 , & V_5 ) ) {
F_7 ( V_2 , V_7 ) ;
F_8 ( V_7 , & V_5 ) ;
}
F_9 ( & V_8 ) ;
F_10 () ;
while ( ! V_9 )
F_11 () ;
if ( V_10 . V_11 )
V_10 . V_11 ( 1 , 1 ) ;
#ifdef F_12
F_13 () ;
#else
for (; ; ) ;
#endif
}
static void F_14 ( int V_7 )
{
unsigned int V_12 ;
unsigned int V_13 = F_15 () - 1 ;
int V_14 = 0 ;
int (* F_16)( struct V_1 * V_2 );
F_17 ( V_15 L_1 ) ;
F_18 ( F_3 ) ;
F_19 () ;
V_16:
V_12 = V_17 ;
while ( ( F_20 ( & V_8 ) < V_13 ) && ( -- V_12 > 0 ) )
F_21 ( 1 ) ;
if ( F_20 ( & V_8 ) >= V_13 ) {
F_17 ( V_15 L_2 ) ;
return;
}
F_17 ( V_15 L_3 ,
V_13 - F_20 ( & V_8 ) ) ;
if ( ( V_18 > 0 ) || ( V_14 > 0 ) )
return;
F_16 = V_19 ;
V_19 = F_1 ;
V_3 = F_2 () ;
if ( setjmp ( V_4 ) == 0 ) {
F_17 ( V_15 L_4
L_5 ) ;
F_22 ( & V_8 , 0 ) ;
F_23 () ;
while ( F_20 ( & V_8 ) < V_13 )
F_11 () ;
}
V_3 = - 1 ;
V_19 = F_16 ;
V_14 ++ ;
goto V_16;
}
void F_24 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
int V_12 = V_21 ;
F_25 ( V_20 ) ;
while ( V_22 < 0 ) {
if ( -- V_12 < 0 ) {
F_26 ( V_20 ) ;
return;
}
F_21 ( 1 ) ;
}
F_3 ( V_2 ) ;
}
static void F_14 ( int V_7 )
{
#ifdef F_12
F_27 () ;
#else
#endif
}
void F_24 ( struct V_1 * V_2 )
{
}
static void T_2 F_28 ( int V_7 )
{
unsigned int V_12 ;
int V_23 ;
V_12 = V_24 ;
for ( V_23 = 0 ; V_23 < V_25 && V_12 > 0 ; V_23 ++ ) {
if ( V_23 == V_7 )
continue;
while ( V_26 [ V_23 ] . V_27 < V_28 ) {
F_29 () ;
if ( ! F_30 ( V_23 ) || ! F_4 ( V_23 ) || ( V_12 <= 0 ) )
break;
V_12 -- ;
F_21 ( 1 ) ;
}
}
F_31 () ;
}
static inline void F_28 ( int V_7 ) {}
int F_32 ( T_3 V_29 )
{
unsigned int V_23 , V_30 ;
F_33 ( & V_31 ) ;
for ( V_23 = 0 ; V_23 < V_32 ; V_23 ++ )
if ( ! V_33 [ V_23 ] ) {
V_33 [ V_23 ] = V_29 ;
V_30 = 0 ;
break;
}
if ( V_23 == V_32 ) {
F_17 ( V_34 L_6
L_7 ) ;
V_30 = 1 ;
}
F_34 ( & V_31 ) ;
return V_30 ;
}
int F_35 ( T_3 V_29 )
{
unsigned int V_23 , V_30 ;
F_33 ( & V_31 ) ;
for ( V_23 = 0 ; V_23 < V_32 ; V_23 ++ )
if ( V_33 [ V_23 ] == V_29 )
break;
if ( V_23 == V_32 ) {
F_17 ( V_34 L_8 ) ;
V_30 = 1 ;
} else {
for (; V_33 [ V_23 ] ; V_23 ++ )
V_33 [ V_23 ] =
V_33 [ V_23 + 1 ] ;
V_30 = 0 ;
}
F_34 ( & V_31 ) ;
return V_30 ;
}
void F_36 ( struct V_1 * V_2 )
{
unsigned int V_23 ;
int (* F_16)( struct V_1 * V_2 );
F_5 () ;
V_22 = F_2 () ;
if ( F_37 ( V_2 ) == 0x100 )
F_21 ( V_35 ) ;
F_14 ( V_22 ) ;
F_7 ( V_2 , V_22 ) ;
V_9 = 1 ;
F_28 ( V_22 ) ;
F_38 () ;
F_16 = V_36 ;
V_36 = F_1 ;
V_3 = F_2 () ;
for ( V_23 = 0 ; V_33 [ V_23 ] ; V_23 ++ ) {
if ( setjmp ( V_4 ) == 0 ) {
asm volatile("sync; isync");
V_33 [ V_23 ] ( ) ;
asm volatile("sync; isync");
}
}
V_3 = - 1 ;
V_36 = F_16 ;
if ( V_10 . V_11 )
V_10 . V_11 ( 1 , 0 ) ;
}
