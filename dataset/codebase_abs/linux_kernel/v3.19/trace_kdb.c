static void F_1 ( int V_1 , long V_2 )
{
static struct V_3 V_4 ;
static struct V_5 * V_6 [ V_7 ] ;
unsigned int V_8 ;
int V_9 = 0 , V_10 ;
F_2 ( & V_4 ) ;
V_4 . V_6 = V_6 ;
F_3 (cpu) {
F_4 ( & F_5 ( V_4 . V_11 -> V_12 , V_10 ) -> V_13 ) ;
}
V_8 = V_14 ;
V_14 &= ~ V_15 ;
F_6 ( L_1 ) ;
memset ( & V_4 . V_16 , 0 ,
sizeof( struct V_3 ) -
F_7 ( struct V_3 , V_16 ) ) ;
V_4 . V_17 |= V_18 ;
V_4 . V_19 = - 1 ;
if ( V_2 == V_20 ) {
F_3 (cpu) {
V_4 . V_6 [ V_10 ] =
F_8 ( V_4 . V_11 -> V_21 , V_10 ) ;
F_9 ( V_4 . V_6 [ V_10 ] ) ;
F_10 ( & V_4 , V_10 ) ;
}
} else {
V_4 . V_2 = V_2 ;
V_4 . V_6 [ V_2 ] =
F_8 ( V_4 . V_11 -> V_21 , V_2 ) ;
F_9 ( V_4 . V_6 [ V_2 ] ) ;
F_10 ( & V_4 , V_2 ) ;
}
while ( F_11 ( & V_4 ) ) {
if ( ! V_9 )
F_6 ( L_2 ) ;
V_9 ++ ;
if ( ! V_1 ) {
F_12 ( & V_4 ) ;
F_13 ( & V_4 . V_16 ) ;
} else {
V_1 -- ;
}
if ( F_14 ( V_22 ) )
goto V_23;
}
if ( ! V_9 )
F_6 ( L_3 ) ;
else
F_6 ( L_2 ) ;
V_23:
V_14 = V_8 ;
F_3 (cpu) {
F_15 ( & F_5 ( V_4 . V_11 -> V_12 , V_10 ) -> V_13 ) ;
}
F_3 (cpu) {
if ( V_4 . V_6 [ V_10 ] ) {
F_16 ( V_4 . V_6 [ V_10 ] ) ;
V_4 . V_6 [ V_10 ] = NULL ;
}
}
}
static int F_17 ( int V_24 , const char * * V_25 )
{
int V_1 = 0 ;
long V_2 ;
char * V_26 ;
if ( V_24 > 2 )
return V_27 ;
if ( V_24 ) {
V_1 = F_18 ( V_25 [ 1 ] , & V_26 , 0 ) ;
if ( * V_26 )
V_1 = 0 ;
}
if ( V_24 == 2 ) {
V_2 = F_18 ( V_25 [ 2 ] , & V_26 , 0 ) ;
if ( * V_26 || V_2 >= V_28 || V_2 < 0 ||
! F_19 ( V_2 ) )
return V_29 ;
} else {
V_2 = V_20 ;
}
V_30 ++ ;
F_1 ( V_1 , V_2 ) ;
V_30 -- ;
return 0 ;
}
static T_1 int F_20 ( void )
{
F_21 ( L_4 , F_17 , L_5 ,
L_6 , 0 , V_31 ) ;
return 0 ;
}
