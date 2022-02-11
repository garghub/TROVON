void F_1 ( unsigned V_1 , unsigned V_2 , void * V_3 )
{
unsigned long V_4 = V_3 ? F_2 ( V_3 ) : 0 ;
V_5 [ V_2 ] [ V_1 ] = V_4 ;
F_3 ( & V_5 [ V_2 ] [ V_1 ] ) ;
}
int T_1 F_4 ( const struct V_6 * V_7 )
{
if ( V_8 )
return - V_9 ;
V_8 = V_7 ;
return 0 ;
}
int F_5 ( unsigned int V_1 , unsigned int V_2 )
{
if ( ! V_8 )
return - V_10 ;
F_6 () ;
return V_8 -> V_11 ( V_1 , V_2 ) ;
}
void F_7 ( void )
{
T_2 V_12 ;
if ( F_8 ( ! V_8 || ! V_8 -> V_13 ) )
return;
F_9 ( ! F_10 () ) ;
F_11 () ;
V_8 -> V_13 () ;
V_12 = ( T_2 ) ( unsigned long ) F_2 ( V_14 ) ;
V_12 ( F_2 ( V_15 ) ) ;
F_12 () ;
}
void F_13 ( T_3 V_16 )
{
T_2 V_12 ;
if ( F_8 ( ! V_8 || ! V_8 -> V_17 ) )
return;
F_9 ( ! F_10 () ) ;
F_11 () ;
V_8 -> V_17 ( V_16 ) ;
V_12 = ( T_2 ) ( unsigned long ) F_2 ( V_14 ) ;
V_12 ( F_2 ( V_15 ) ) ;
F_12 () ;
}
int F_14 ( void )
{
if ( ! V_8 )
return - V_10 ;
if ( V_8 -> V_18 )
V_8 -> V_18 () ;
return 0 ;
}
void F_15 ( unsigned int V_1 , unsigned int V_2 )
{
V_19 . V_20 [ V_2 ] . V_21 [ V_1 ] . V_1 = V_22 ;
F_3 ( & V_19 . V_20 [ V_2 ] . V_21 [ V_1 ] . V_1 ) ;
}
void F_16 ( unsigned int V_1 , unsigned int V_2 )
{
F_17 () ;
V_19 . V_20 [ V_2 ] . V_21 [ V_1 ] . V_1 = V_23 ;
F_3 ( & V_19 . V_20 [ V_2 ] . V_21 [ V_1 ] . V_1 ) ;
F_18 () ;
}
void F_19 ( unsigned int V_2 , int V_24 )
{
F_17 () ;
V_19 . V_20 [ V_2 ] . V_2 = V_24 ;
F_3 ( & V_19 . V_20 [ V_2 ] . V_2 ) ;
F_18 () ;
}
bool F_20 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_25 ;
struct V_26 * V_27 = & V_19 . V_20 [ V_2 ] ;
V_27 -> V_2 = V_28 ;
F_3 ( & V_27 -> V_2 ) ;
F_21 ( & V_27 -> V_29 ) ;
if ( V_27 -> V_29 == V_30 )
goto abort;
F_21 ( & V_27 -> V_21 ) ;
for ( V_25 = 0 ; V_25 < V_31 ; V_25 ++ ) {
int V_32 ;
if ( V_25 == V_1 )
continue;
while ( 1 ) {
V_32 = V_27 -> V_21 [ V_25 ] . V_1 ;
if ( V_32 != V_22 )
break;
F_22 () ;
F_21 ( & V_27 -> V_21 [ V_25 ] . V_1 ) ;
}
switch ( V_32 ) {
case V_23 :
continue;
default:
goto abort;
}
}
return true ;
abort:
F_19 ( V_2 , V_33 ) ;
return false ;
}
int F_23 ( unsigned int V_2 )
{
F_21 ( & V_19 . V_20 [ V_2 ] . V_2 ) ;
return V_19 . V_20 [ V_2 ] . V_2 ;
}
int T_1 F_24 (
void (* F_25)( unsigned int V_34 ) )
{
unsigned int V_25 , V_35 , V_36 , V_37 ;
F_26 ( V_38 * V_39 != sizeof V_19 ) ;
F_9 ( ( unsigned long ) & V_19 & ( V_40 - 1 ) ) ;
for ( V_25 = 0 ; V_25 < V_39 ; V_25 ++ ) {
V_19 . V_20 [ V_25 ] . V_2 = V_41 ;
V_19 . V_20 [ V_25 ] . V_29 = V_42 ;
for ( V_35 = 0 ; V_35 < V_31 ; V_35 ++ )
V_19 . V_20 [ V_25 ] . V_21 [ V_35 ] . V_1 = V_23 ;
}
V_36 = F_27 () ;
V_37 = F_28 ( V_36 , 1 ) ;
F_29 (i)
V_19 . V_20 [ V_37 ] . V_21 [ V_25 ] . V_1 = V_43 ;
V_19 . V_20 [ V_37 ] . V_2 = V_33 ;
F_3 ( & V_19 ) ;
if ( F_25 ) {
V_44 = F_2 ( F_25 ) ;
F_3 ( & V_44 ) ;
}
return 0 ;
}
