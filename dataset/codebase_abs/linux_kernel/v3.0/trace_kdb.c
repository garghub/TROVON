static void F_1 ( int V_1 , long V_2 )
{
static struct V_3 V_4 ;
unsigned int V_5 ;
int V_6 = 0 , V_7 ;
F_2 ( & V_4 ) ;
F_3 (cpu) {
F_4 ( & V_4 . V_8 -> V_9 [ V_7 ] -> V_10 ) ;
}
V_5 = V_11 ;
V_11 &= ~ V_12 ;
F_5 ( L_1 ) ;
memset ( & V_4 . V_13 , 0 ,
sizeof( struct V_3 ) -
F_6 ( struct V_3 , V_13 ) ) ;
V_4 . V_14 |= V_15 ;
V_4 . V_16 = - 1 ;
if ( V_2 == V_17 ) {
F_3 (cpu) {
V_4 . V_18 [ V_7 ] =
F_7 ( V_4 . V_8 -> V_19 , V_7 ) ;
F_8 ( V_4 . V_18 [ V_7 ] ) ;
F_9 ( & V_4 , V_7 ) ;
}
} else {
V_4 . V_2 = V_2 ;
V_4 . V_18 [ V_2 ] =
F_7 ( V_4 . V_8 -> V_19 , V_2 ) ;
F_8 ( V_4 . V_18 [ V_2 ] ) ;
F_9 ( & V_4 , V_2 ) ;
}
if ( ! F_10 ( & V_4 ) )
F_11 ( & V_4 ) ;
while ( ! F_10 ( & V_4 ) ) {
if ( ! V_6 )
F_5 ( L_2 ) ;
V_6 ++ ;
if ( F_11 ( & V_4 ) != NULL && ! V_1 )
F_12 ( & V_4 ) ;
if ( ! V_1 )
F_13 ( & V_4 . V_13 ) ;
else
V_1 -- ;
if ( F_14 ( V_20 ) )
goto V_21;
}
if ( ! V_6 )
F_5 ( L_3 ) ;
else
F_5 ( L_2 ) ;
V_21:
V_11 = V_5 ;
F_3 (cpu) {
F_15 ( & V_4 . V_8 -> V_9 [ V_7 ] -> V_10 ) ;
}
F_3 (cpu)
if ( V_4 . V_18 [ V_7 ] )
F_16 ( V_4 . V_18 [ V_7 ] ) ;
}
static int F_17 ( int V_22 , const char * * V_23 )
{
int V_1 = 0 ;
long V_2 ;
char * V_24 ;
if ( V_22 > 2 )
return V_25 ;
if ( V_22 ) {
V_1 = F_18 ( V_23 [ 1 ] , & V_24 , 0 ) ;
if ( * V_24 )
V_1 = 0 ;
}
if ( V_22 == 2 ) {
V_2 = F_18 ( V_23 [ 2 ] , & V_24 , 0 ) ;
if ( * V_24 || V_2 >= V_26 || V_2 < 0 ||
! F_19 ( V_2 ) )
return V_27 ;
} else {
V_2 = V_17 ;
}
V_28 ++ ;
F_1 ( V_1 , V_2 ) ;
V_28 -- ;
return 0 ;
}
static T_1 int F_20 ( void )
{
F_21 ( L_4 , F_17 , L_5 ,
L_6 , 0 , V_29 ) ;
return 0 ;
}
