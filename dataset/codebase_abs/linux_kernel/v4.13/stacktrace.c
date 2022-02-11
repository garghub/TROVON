static void F_1 ( void )
{
unsigned long V_1 ;
unsigned long V_2 ;
char V_3 [ V_4 ] ;
char V_5 [ V_6 ] ;
V_7 = F_2 ( L_1 ) ;
if ( ! V_7 )
V_7 = 1 ;
else if ( ! F_3 ( V_7 , & V_1 ,
& V_2 , V_3 , V_5 ) )
V_8 = V_1 ;
}
int T_1 F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_10 -> V_12 ;
unsigned long V_13 ;
unsigned long V_14 ;
if ( V_10 -> V_12 & 0x7 )
return - V_15 ;
V_14 = V_12 -> V_12 ;
V_13 = V_12 -> V_13 - 4 ;
#ifdef F_5
if ( ! V_7 )
F_1 () ;
if ( V_8 && V_13 >= V_7 &&
V_13 < V_7 + V_8 ) {
struct V_16 * V_17 = (struct V_16 * ) V_14 ;
if ( F_6 ( V_17 ) )
return - V_15 ;
V_14 = V_17 -> V_18 . V_19 [ 1 ] . V_20 ;
V_13 = V_17 -> V_18 . V_21 [ 4 ] . V_22 ;
}
#endif
if ( V_14 < ( F_7 ( ( unsigned long ) V_12 , V_23 ) +
sizeof( struct V_24 ) ) || V_14 >= ( unsigned long ) V_12 )
return - V_15 ;
V_10 -> V_12 = V_14 ;
V_10 -> V_25 = V_13 ;
return 0 ;
}
int T_1 F_4 ( struct V_9 * V_10 )
{
struct V_11 * V_26 = (struct V_11 * ) V_10 -> V_26 ;
if ( V_10 -> V_26 & 0x7 )
return - V_15 ;
while ( ! F_8 ( V_26 ) ) {
unsigned long V_27 = V_26 -> V_13 - 4 ;
V_26 -- ;
if ( F_9 ( V_27 ) ) {
V_10 -> V_26 = ( unsigned long ) V_26 ;
V_10 -> V_25 = V_27 ;
return 0 ;
}
}
return - V_15 ;
}
void T_1 F_10 ( struct V_9 * V_10 ,
int (* F_11)( struct V_9 * , void * ) , void * V_28 )
{
while ( 1 ) {
int V_29 ;
if ( F_11 ( V_10 , V_28 ) )
break;
V_29 = F_4 ( V_10 ) ;
if ( V_29 < 0 )
break;
}
}
static int F_12 ( struct V_9 * V_10 , void * V_30 )
{
struct V_31 * V_28 = V_30 ;
struct V_32 * V_33 = V_28 -> V_33 ;
unsigned long V_27 = V_10 -> V_25 ;
if ( V_28 -> V_34 && F_13 ( V_27 ) )
return 0 ;
if ( V_28 -> V_35 ) {
V_28 -> V_35 -- ;
return 0 ;
}
V_33 -> V_36 [ V_33 -> V_37 ++ ] = V_27 ;
return V_33 -> V_37 >= V_33 -> V_38 ;
}
void F_14 ( struct V_39 * V_40 , struct V_32 * V_33 )
{
struct V_31 V_28 ;
struct V_9 V_10 ;
V_28 . V_33 = V_33 ;
V_28 . V_35 = V_33 -> V_35 ;
if ( V_40 != V_41 ) {
#ifdef F_15
if ( V_33 -> V_37 < V_33 -> V_38 )
V_33 -> V_36 [ V_33 -> V_37 ++ ] = V_42 ;
return;
#else
V_28 . V_34 = 1 ;
V_10 . V_12 = F_16 ( V_40 ) ;
V_10 . V_26 = F_17 ( V_40 ) ;
V_10 . V_13 = 0 ;
V_10 . V_25 = F_18 ( V_40 ) ;
#endif
} else {
register unsigned long T_2 V_43 ( L_2 ) ;
V_28 . V_34 = 0 ;
V_10 . V_12 = ( unsigned long ) F_19 ( 0 ) ;
V_10 . V_26 = T_2 ;
V_10 . V_13 = ( unsigned long ) F_20 ( 0 ) ;
V_10 . V_25 = ( unsigned long ) F_14 ;
}
F_10 ( & V_10 , F_12 , & V_28 ) ;
if ( V_33 -> V_37 < V_33 -> V_38 )
V_33 -> V_36 [ V_33 -> V_37 ++ ] = V_42 ;
}
void F_21 ( struct V_32 * V_33 )
{
F_14 ( V_41 , V_33 ) ;
}
