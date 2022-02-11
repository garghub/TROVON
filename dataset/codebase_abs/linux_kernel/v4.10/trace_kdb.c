static void F_1 ( int V_1 , long V_2 )
{
static struct V_3 V_4 ;
static struct V_5 * V_6 [ V_7 ] ;
struct V_8 * V_9 ;
unsigned int V_10 ;
int V_11 = 0 , V_12 ;
F_2 ( & V_4 ) ;
V_4 . V_6 = V_6 ;
V_9 = V_4 . V_9 ;
F_3 (cpu) {
F_4 ( & F_5 ( V_4 . V_13 -> V_14 , V_12 ) -> V_15 ) ;
}
V_10 = V_9 -> V_16 ;
V_9 -> V_16 &= ~ V_17 ;
F_6 ( L_1 ) ;
memset ( & V_4 . V_18 , 0 ,
sizeof( struct V_3 ) -
F_7 ( struct V_3 , V_18 ) ) ;
V_4 . V_19 |= V_20 ;
V_4 . V_21 = - 1 ;
if ( V_2 == V_22 ) {
F_3 (cpu) {
V_4 . V_6 [ V_12 ] =
F_8 ( V_4 . V_13 -> V_23 , V_12 ) ;
F_9 ( V_4 . V_6 [ V_12 ] ) ;
F_10 ( & V_4 , V_12 ) ;
}
} else {
V_4 . V_2 = V_2 ;
V_4 . V_6 [ V_2 ] =
F_8 ( V_4 . V_13 -> V_23 , V_2 ) ;
F_9 ( V_4 . V_6 [ V_2 ] ) ;
F_10 ( & V_4 , V_2 ) ;
}
while ( F_11 ( & V_4 ) ) {
if ( ! V_11 )
F_6 ( L_2 ) ;
V_11 ++ ;
if ( ! V_1 ) {
F_12 ( & V_4 ) ;
F_13 ( & V_4 . V_18 ) ;
} else {
V_1 -- ;
}
if ( F_14 ( V_24 ) )
goto V_25;
}
if ( ! V_11 )
F_6 ( L_3 ) ;
else
F_6 ( L_2 ) ;
V_25:
V_9 -> V_16 = V_10 ;
F_3 (cpu) {
F_15 ( & F_5 ( V_4 . V_13 -> V_14 , V_12 ) -> V_15 ) ;
}
F_3 (cpu) {
if ( V_4 . V_6 [ V_12 ] ) {
F_16 ( V_4 . V_6 [ V_12 ] ) ;
V_4 . V_6 [ V_12 ] = NULL ;
}
}
}
static int F_17 ( int V_26 , const char * * V_27 )
{
int V_1 = 0 ;
long V_2 ;
char * V_28 ;
if ( V_26 > 2 )
return V_29 ;
if ( V_26 ) {
V_1 = F_18 ( V_27 [ 1 ] , & V_28 , 0 ) ;
if ( * V_28 )
V_1 = 0 ;
}
if ( V_26 == 2 ) {
V_2 = F_18 ( V_27 [ 2 ] , & V_28 , 0 ) ;
if ( * V_28 || V_2 >= V_30 || V_2 < 0 ||
! F_19 ( V_2 ) )
return V_31 ;
} else {
V_2 = V_22 ;
}
V_32 ++ ;
F_1 ( V_1 , V_2 ) ;
V_32 -- ;
return 0 ;
}
static T_1 int F_20 ( void )
{
F_21 ( L_4 , F_17 , L_5 ,
L_6 , 0 , V_33 ) ;
return 0 ;
}
