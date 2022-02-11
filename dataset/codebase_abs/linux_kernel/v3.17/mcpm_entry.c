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
static int T_1 F_20 ( unsigned long V_26 )
{
void (* F_21)( void ) = ( void * ) V_26 ;
unsigned int V_27 = F_22 () ;
unsigned int V_1 = F_23 ( V_27 , 0 ) ;
unsigned int V_2 = F_23 ( V_27 , 1 ) ;
T_2 V_16 ;
F_1 ( V_1 , V_2 , V_28 ) ;
F_14 () ;
F_24 ( V_1 , V_2 ) ;
F_12 ( ! F_25 ( V_1 , V_2 ) ) ;
F_21 () ;
F_26 ( V_2 , V_29 ) ;
F_27 ( V_1 , V_2 ) ;
V_16 = ( T_2 ) ( unsigned long ) F_2 ( V_18 ) ;
V_16 ( F_2 ( V_19 ) ) ;
F_15 () ;
}
int T_1 F_28 ( void (* F_21)( void ) )
{
int V_20 ;
F_29 () ;
F_30 () ;
V_20 = F_31 () ;
if ( ! V_20 ) {
V_20 = F_32 ( ( unsigned long ) F_21 , F_20 ) ;
F_33 () ;
}
F_34 () ;
F_35 () ;
if ( V_20 )
F_36 ( L_2 , V_22 , V_20 ) ;
return V_20 ;
}
void F_24 ( unsigned int V_1 , unsigned int V_2 )
{
V_30 . V_31 [ V_2 ] . V_32 [ V_1 ] . V_1 = V_33 ;
F_3 ( & V_30 . V_31 [ V_2 ] . V_32 [ V_1 ] . V_1 ) ;
}
void F_27 ( unsigned int V_1 , unsigned int V_2 )
{
F_37 () ;
V_30 . V_31 [ V_2 ] . V_32 [ V_1 ] . V_1 = V_34 ;
F_3 ( & V_30 . V_31 [ V_2 ] . V_32 [ V_1 ] . V_1 ) ;
F_38 () ;
}
void F_26 ( unsigned int V_2 , int V_35 )
{
F_37 () ;
V_30 . V_31 [ V_2 ] . V_2 = V_35 ;
F_3 ( & V_30 . V_31 [ V_2 ] . V_2 ) ;
F_38 () ;
}
bool F_25 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_36 ;
struct V_37 * V_38 = & V_30 . V_31 [ V_2 ] ;
V_38 -> V_2 = V_39 ;
F_3 ( & V_38 -> V_2 ) ;
F_39 ( & V_38 -> V_40 ) ;
if ( V_38 -> V_40 == V_41 )
goto abort;
F_39 ( & V_38 -> V_32 ) ;
for ( V_36 = 0 ; V_36 < V_42 ; V_36 ++ ) {
int V_43 ;
if ( V_36 == V_1 )
continue;
while ( 1 ) {
V_43 = V_38 -> V_32 [ V_36 ] . V_1 ;
if ( V_43 != V_33 )
break;
F_40 () ;
F_39 ( & V_38 -> V_32 [ V_36 ] . V_1 ) ;
}
switch ( V_43 ) {
case V_34 :
continue;
default:
goto abort;
}
}
return true ;
abort:
F_26 ( V_2 , V_44 ) ;
return false ;
}
int F_41 ( unsigned int V_2 )
{
F_39 ( & V_30 . V_31 [ V_2 ] . V_2 ) ;
return V_30 . V_31 [ V_2 ] . V_2 ;
}
int T_1 F_42 (
void (* F_43)( unsigned int V_45 ) )
{
unsigned int V_36 , V_46 , V_27 , V_47 ;
F_44 ( V_48 * V_49 != sizeof V_30 ) ;
F_12 ( ( unsigned long ) & V_30 & ( V_50 - 1 ) ) ;
for ( V_36 = 0 ; V_36 < V_49 ; V_36 ++ ) {
V_30 . V_31 [ V_36 ] . V_2 = V_29 ;
V_30 . V_31 [ V_36 ] . V_40 = V_51 ;
for ( V_46 = 0 ; V_46 < V_42 ; V_46 ++ )
V_30 . V_31 [ V_36 ] . V_32 [ V_46 ] . V_1 = V_34 ;
}
V_27 = F_22 () ;
V_47 = F_23 ( V_27 , 1 ) ;
F_45 (i)
V_30 . V_31 [ V_47 ] . V_32 [ V_36 ] . V_1 = V_52 ;
V_30 . V_31 [ V_47 ] . V_2 = V_44 ;
F_3 ( & V_30 ) ;
if ( F_43 ) {
V_53 = F_2 ( F_43 ) ;
F_3 ( & V_53 ) ;
}
return 0 ;
}
