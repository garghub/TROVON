void F_1 ( unsigned V_1 , unsigned V_2 , void * V_3 )
{
unsigned long V_4 = V_3 ? F_2 ( V_3 ) : 0 ;
V_5 [ V_2 ] [ V_1 ] = V_4 ;
F_3 ( & V_5 [ V_2 ] [ V_1 ] ) ;
}
void F_4 ( unsigned V_1 , unsigned V_2 ,
unsigned long V_6 , unsigned long V_7 )
{
unsigned long * V_8 = & V_9 [ V_2 ] [ V_1 ] [ 0 ] ;
V_8 [ 0 ] = V_6 ;
V_8 [ 1 ] = V_7 ;
F_5 ( V_8 , 2 * sizeof( * V_8 ) ) ;
}
int T_1 F_6 ( const struct V_10 * V_11 )
{
if ( V_12 )
return - V_13 ;
V_12 = V_11 ;
return 0 ;
}
bool F_7 ( void )
{
return ( V_12 ) ? true : false ;
}
int F_8 ( unsigned int V_1 , unsigned int V_2 )
{
if ( ! V_12 )
return - V_14 ;
F_9 () ;
return V_12 -> V_15 ( V_1 , V_2 ) ;
}
void F_10 ( void )
{
T_2 V_16 ;
if ( F_11 ( ! V_12 || ! V_12 -> V_17 ) )
return;
F_12 ( ! F_13 () ) ;
F_14 () ;
V_12 -> V_17 () ;
V_16 = ( T_2 ) ( unsigned long ) F_2 ( V_18 ) ;
V_16 ( F_2 ( V_19 ) ) ;
F_15 () ;
}
int F_16 ( unsigned int V_1 , unsigned int V_2 )
{
int V_20 ;
if ( F_11 ( ! V_12 || ! V_12 -> V_21 ) )
return - V_14 ;
V_20 = V_12 -> V_21 ( V_1 , V_2 ) ;
if ( V_20 )
F_17 ( L_1 ,
V_22 , V_1 , V_2 , V_20 ) ;
return V_20 ;
}
void F_18 ( T_3 V_23 )
{
T_2 V_16 ;
if ( F_11 ( ! V_12 || ! V_12 -> V_24 ) )
return;
F_12 ( ! F_13 () ) ;
F_14 () ;
V_12 -> V_24 ( V_23 ) ;
V_16 = ( T_2 ) ( unsigned long ) F_2 ( V_18 ) ;
V_16 ( F_2 ( V_19 ) ) ;
F_15 () ;
}
int F_19 ( void )
{
if ( ! V_12 )
return - V_14 ;
if ( V_12 -> V_25 )
V_12 -> V_25 () ;
return 0 ;
}
void F_20 ( unsigned int V_1 , unsigned int V_2 )
{
V_26 . V_27 [ V_2 ] . V_28 [ V_1 ] . V_1 = V_29 ;
F_3 ( & V_26 . V_27 [ V_2 ] . V_28 [ V_1 ] . V_1 ) ;
}
void F_21 ( unsigned int V_1 , unsigned int V_2 )
{
F_22 () ;
V_26 . V_27 [ V_2 ] . V_28 [ V_1 ] . V_1 = V_30 ;
F_3 ( & V_26 . V_27 [ V_2 ] . V_28 [ V_1 ] . V_1 ) ;
F_23 () ;
}
void F_24 ( unsigned int V_2 , int V_31 )
{
F_22 () ;
V_26 . V_27 [ V_2 ] . V_2 = V_31 ;
F_3 ( & V_26 . V_27 [ V_2 ] . V_2 ) ;
F_23 () ;
}
bool F_25 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_32 ;
struct V_33 * V_34 = & V_26 . V_27 [ V_2 ] ;
V_34 -> V_2 = V_35 ;
F_3 ( & V_34 -> V_2 ) ;
F_26 ( & V_34 -> V_36 ) ;
if ( V_34 -> V_36 == V_37 )
goto abort;
F_26 ( & V_34 -> V_28 ) ;
for ( V_32 = 0 ; V_32 < V_38 ; V_32 ++ ) {
int V_39 ;
if ( V_32 == V_1 )
continue;
while ( 1 ) {
V_39 = V_34 -> V_28 [ V_32 ] . V_1 ;
if ( V_39 != V_29 )
break;
F_27 () ;
F_26 ( & V_34 -> V_28 [ V_32 ] . V_1 ) ;
}
switch ( V_39 ) {
case V_30 :
continue;
default:
goto abort;
}
}
return true ;
abort:
F_24 ( V_2 , V_40 ) ;
return false ;
}
int F_28 ( unsigned int V_2 )
{
F_26 ( & V_26 . V_27 [ V_2 ] . V_2 ) ;
return V_26 . V_27 [ V_2 ] . V_2 ;
}
int T_1 F_29 (
void (* F_30)( unsigned int V_41 ) )
{
unsigned int V_32 , V_42 , V_43 , V_44 ;
F_31 ( V_45 * V_46 != sizeof V_26 ) ;
F_12 ( ( unsigned long ) & V_26 & ( V_47 - 1 ) ) ;
for ( V_32 = 0 ; V_32 < V_46 ; V_32 ++ ) {
V_26 . V_27 [ V_32 ] . V_2 = V_48 ;
V_26 . V_27 [ V_32 ] . V_36 = V_49 ;
for ( V_42 = 0 ; V_42 < V_38 ; V_42 ++ )
V_26 . V_27 [ V_32 ] . V_28 [ V_42 ] . V_1 = V_30 ;
}
V_43 = F_32 () ;
V_44 = F_33 ( V_43 , 1 ) ;
F_34 (i)
V_26 . V_27 [ V_44 ] . V_28 [ V_32 ] . V_1 = V_50 ;
V_26 . V_27 [ V_44 ] . V_2 = V_40 ;
F_3 ( & V_26 ) ;
if ( F_30 ) {
V_51 = F_2 ( F_30 ) ;
F_3 ( & V_51 ) ;
}
return 0 ;
}
