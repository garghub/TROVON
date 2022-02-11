static int F_1 ( unsigned long V_1 ,
struct V_2 * V_3 )
{
unsigned long V_4 ;
unsigned int V_5 ;
unsigned long V_6 , V_7 , V_8 ;
unsigned long V_9 = 0L ;
int V_10 = V_11 . V_12 ;
int V_13 = F_2 () ;
F_3 ( V_4 ) ;
V_5 = F_4 () ;
V_7 = ( unsigned long ) F_5 () ;
V_6 = F_6 ( V_7 + V_1 ) ;
V_8 = V_14 [ V_10 ] [ V_13 ] ;
if ( V_13 == V_15 [ V_10 ] && F_7 ( V_8 )
&& F_8 ( V_8 , V_6 , V_7 ) ) {
int V_16 ;
int V_17 = V_13 ;
V_14 [ V_10 ] [ V_13 ] = V_6 ;
F_9 (i) {
if ( F_7 ( V_14 [ V_10 ] [ V_16 ] )
&& F_8 ( V_14 [ V_10 ] [ V_16 ] ,
V_14 [ V_10 ] [ V_17 ] , V_7 ) ) {
V_17 = V_16 ;
}
}
V_15 [ V_10 ] = V_17 ;
V_9 = V_14 [ V_10 ] [ V_17 ] ;
} else {
if ( ! F_7 ( V_14 [ V_10 ] [ V_15 [ V_10 ] ] ) ||
F_8 ( V_6 ,
V_14 [ V_10 ] [ V_15 [ V_10 ] ] , V_7 ) ) {
V_15 [ V_10 ] = V_13 ;
V_9 = V_6 ;
}
V_14 [ V_10 ] [ V_13 ] = V_6 ;
}
if ( F_7 ( V_9 ) ) {
F_10 ( V_9 ) ;
F_11 () ;
while ( ( V_9 - ( unsigned long ) F_5 () )
> ( unsigned long ) V_18 ) {
V_9 += V_19 ;
F_10 ( V_9 ) ;
F_11 () ;
}
}
F_12 ( V_5 ) ;
F_13 ( V_4 ) ;
return 0 ;
}
void F_14 ( int V_10 )
{
unsigned long V_4 ;
unsigned int V_5 ;
int V_13 ;
struct V_2 * V_20 ;
unsigned long V_21 ;
unsigned long V_7 ;
V_22:
V_21 = 0L ;
F_9 (cpu) {
F_3 ( V_4 ) ;
V_5 = F_4 () ;
if ( V_23 [ V_13 ] . V_12 == V_10 &&
F_7 ( V_14 [ V_10 ] [ V_13 ] ) ) {
V_7 = ( unsigned long ) F_5 () ;
if ( ( V_14 [ V_10 ] [ V_13 ] - V_7 )
> ( unsigned long ) V_18 ) {
V_14 [ V_10 ] [ V_13 ] = 0L ;
F_12 ( V_5 ) ;
F_13 ( V_4 ) ;
if ( V_13 != F_2 () ) {
F_15 ( V_13 , V_24 , 0 ) ;
} else {
V_20 = & F_16 ( V_25 , V_13 ) ;
V_20 -> V_26 ( V_20 ) ;
}
} else {
if ( ! F_7 ( V_21 ) ||
F_8 ( V_14 [ V_10 ] [ V_13 ] , V_21 ,
V_7 ) ) {
V_15 [ V_10 ] = V_13 ;
V_21 = V_14 [ V_10 ] [ V_13 ] ;
}
F_12 ( V_5 ) ;
F_13 ( V_4 ) ;
}
} else {
F_12 ( V_5 ) ;
F_13 ( V_4 ) ;
}
}
if ( F_7 ( V_21 ) ) {
F_10 ( V_21 ) ;
F_11 () ;
if ( ( V_21 - ( unsigned long ) F_5 () )
> ( unsigned long ) V_18 )
goto V_22;
}
}
T_1 F_17 ( int V_27 , void * V_28 )
{
int V_13 = F_2 () ;
F_18 ( 1 ) ;
if ( F_19 () & ( 1 << 30 ) ) {
F_10 ( F_20 () ) ;
F_14 ( V_23 [ V_13 ] . V_12 ) ;
}
return V_29 ;
}
int F_21 ( void )
{
T_2 V_30 = V_31 ;
unsigned int V_13 = F_2 () ;
struct V_2 * V_20 ;
unsigned int V_27 ;
int V_16 ;
int V_32 ;
if ( ! V_33 || ! V_31 )
return - V_34 ;
if ( V_13 == 0 ) {
for ( V_16 = 0 ; V_16 < F_22 () ; V_16 ++ ) {
V_15 [ V_16 ] = 0 ;
for ( V_32 = 0 ; V_32 < F_22 () ; V_32 ++ )
V_14 [ V_16 ] [ V_32 ] = 0L ;
}
if ( ! F_23 () )
return - V_34 ;
}
V_27 = V_35 + V_36 ;
if ( V_37 )
V_27 = V_37 () ;
V_20 = & F_16 ( V_25 , V_13 ) ;
V_20 -> V_38 = L_1 ;
V_20 -> V_39 = V_40 ;
V_20 -> V_41 = F_24 ( ( unsigned long ) V_30 , V_42 , 32 ) ;
V_20 -> V_43 = 32 ;
V_20 -> V_44 = F_25 ( 0x7fffffff , V_20 ) ;
V_20 -> V_45 = F_25 ( 0x300 , V_20 ) ;
V_20 -> V_46 = 300 ;
V_20 -> V_27 = V_27 ;
V_20 -> V_47 = F_26 ( V_13 ) ;
V_20 -> V_48 = F_1 ;
V_20 -> V_49 = V_50 ;
V_20 -> V_26 = V_51 ;
F_27 ( V_20 ) ;
if ( V_13 )
return 0 ;
V_52 [ V_27 ] = ( 0x100 << V_36 ) ;
if ( V_53 )
return 0 ;
V_53 = 1 ;
F_28 ( V_27 , & V_54 ) ;
return 0 ;
}
