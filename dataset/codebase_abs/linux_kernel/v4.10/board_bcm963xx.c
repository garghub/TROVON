int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 == V_6 ) {
memcpy ( V_4 , & V_7 , sizeof( struct V_3 ) ) ;
return 0 ;
} else {
F_2 ( L_1 ) ;
return - V_8 ;
}
}
const char * F_3 ( void )
{
return V_9 . V_10 ;
}
void T_1 F_4 ( void )
{
unsigned int V_11 ;
T_2 * V_12 , * V_13 ;
char V_14 [ 32 ] ;
char * V_15 = NULL ;
T_3 V_16 ;
struct V_17 * V_18 ;
if ( F_5 () || F_6 () ) {
V_16 = 0x18000000 ;
} else {
V_16 = F_7 ( F_8 ( 0 ) ) ;
V_16 &= V_19 ;
}
V_12 = ( T_2 * ) F_9 ( V_16 ) ;
V_13 = V_12 + V_20 ;
if ( ! memcmp ( V_13 , L_2 , 5 ) )
snprintf ( V_14 , sizeof( V_14 ) , L_3 ,
V_13 [ 5 ] , V_13 [ 6 ] , V_13 [ 7 ] , V_13 [ 8 ] , V_13 [ 9 ] ) ;
else
strcpy ( V_14 , L_4 ) ;
F_10 ( L_5 , V_14 ) ;
F_11 ( V_12 + V_21 ) ;
if ( F_12 () ) {
V_18 = (struct V_17 * ) V_12 ;
V_15 = V_18 -> V_22 ;
} else {
V_15 = F_13 () ;
}
for ( V_11 = 0 ; V_11 < F_14 ( V_23 ) ; V_11 ++ ) {
if ( strncmp ( V_15 , V_23 [ V_11 ] -> V_10 , 16 ) )
continue;
memcpy ( & V_9 , V_23 [ V_11 ] , sizeof( V_9 ) ) ;
break;
}
if ( ! V_9 . V_10 [ 0 ] ) {
char V_10 [ 17 ] ;
memcpy ( V_10 , V_15 , 16 ) ;
V_10 [ 16 ] = 0 ;
F_2 ( L_6 , V_10 ) ;
return;
}
V_16 = 0 ;
#ifdef F_15
if ( V_9 . V_24 ) {
V_25 = 1 ;
if ( F_16 () )
V_16 |= V_26 ;
}
#endif
if ( V_9 . V_27 ) {
if ( F_16 () )
V_16 |= V_28 ;
}
if ( V_9 . V_29 && ! V_9 . V_30 . V_31 ) {
if ( F_16 () )
V_16 |= V_32 |
V_33 ;
}
if ( V_9 . V_34 && ! V_9 . V_35 . V_31 ) {
if ( F_16 () )
V_16 |= V_32 |
V_33 ;
}
F_17 ( V_16 , V_36 ) ;
}
void T_1 F_18 ( void )
{
if ( ! V_9 . V_10 [ 0 ] )
F_19 ( L_7 ) ;
F_10 ( L_8 , V_9 . V_10 ) ;
if ( F_20 () != V_9 . V_37 )
F_19 ( L_9 ) ;
}
int T_1 F_21 ( void )
{
if ( V_9 . V_38 )
F_22 ( 0 ) ;
if ( V_9 . V_39 )
F_22 ( 1 ) ;
if ( V_9 . V_27 )
F_23 () ;
if ( V_9 . V_29 &&
! F_24 ( V_9 . V_30 . V_40 ) )
F_25 ( 0 , & V_9 . V_30 ) ;
if ( V_9 . V_34 &&
! F_24 ( V_9 . V_35 . V_40 ) )
F_25 ( 1 , & V_9 . V_35 ) ;
if ( V_9 . V_41 &&
! F_24 ( V_9 . V_42 . V_40 ) )
F_26 ( & V_9 . V_42 ) ;
if ( V_9 . V_43 )
F_27 ( & V_9 . V_44 ) ;
if ( V_9 . V_45 )
F_28 ( & V_9 . V_46 ) ;
#ifdef F_29
if ( ! F_24 ( V_7 . V_47 ) ) {
memcpy ( V_7 . V_48 , V_7 . V_47 , V_49 ) ;
memcpy ( V_7 . V_50 , V_7 . V_47 , V_49 ) ;
if ( F_30 (
& F_1 ) < 0 )
F_2 ( L_10 ) ;
}
#endif
F_31 () ;
F_32 () ;
F_33 () ;
V_51 . V_52 = F_14 ( V_9 . V_53 ) ;
V_51 . V_53 = V_9 . V_53 ;
F_34 ( & V_54 ) ;
if ( V_9 . V_55 && V_9 . V_56 )
F_35 ( V_9 . V_55 ,
V_9 . V_56 , L_11 ) ;
return 0 ;
}
