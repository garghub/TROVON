int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 == V_6 ) {
memcpy ( V_4 , & V_7 , sizeof( struct V_3 ) ) ;
return 0 ;
} else {
F_2 (KERN_ERR PFX L_1 ) ;
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
char * V_15 ;
T_3 V_16 ;
if ( F_5 () || F_6 () ) {
V_16 = 0x18000000 ;
} else {
V_16 = F_7 ( F_8 ( 0 ) ) ;
V_16 &= V_17 ;
}
V_12 = ( T_2 * ) F_9 ( V_16 ) ;
V_13 = V_12 + V_18 ;
if ( ! memcmp ( V_13 , L_2 , 5 ) )
snprintf ( V_14 , sizeof( V_14 ) , L_3 ,
V_13 [ 5 ] , V_13 [ 6 ] , V_13 [ 7 ] , V_13 [ 8 ] , V_13 [ 9 ] ) ;
else
strcpy ( V_14 , L_4 ) ;
F_2 (KERN_INFO PFX L_5 , cfe_version) ;
F_10 ( V_12 + V_19 ) ;
V_15 = F_11 () ;
for ( V_11 = 0 ; V_11 < F_12 ( V_20 ) ; V_11 ++ ) {
if ( strncmp ( V_15 , V_20 [ V_11 ] -> V_10 , 16 ) )
continue;
memcpy ( & V_9 , V_20 [ V_11 ] , sizeof( V_9 ) ) ;
break;
}
if ( ! V_9 . V_10 [ 0 ] ) {
char V_10 [ 17 ] ;
memcpy ( V_10 , V_15 , 16 ) ;
V_10 [ 16 ] = 0 ;
F_2 (KERN_ERR PFX L_6 ,
name) ;
return;
}
V_16 = 0 ;
#ifdef F_13
if ( V_9 . V_21 ) {
V_22 = 1 ;
if ( F_14 () )
V_16 |= V_23 ;
}
#endif
if ( V_9 . V_24 ) {
if ( F_14 () )
V_16 |= V_25 ;
}
if ( V_9 . V_26 && ! V_9 . V_27 . V_28 ) {
if ( F_14 () )
V_16 |= V_29 |
V_30 ;
}
if ( V_9 . V_31 && ! V_9 . V_32 . V_28 ) {
if ( F_14 () )
V_16 |= V_29 |
V_30 ;
}
F_15 ( V_16 , V_33 ) ;
}
void T_1 F_16 ( void )
{
if ( ! V_9 . V_10 [ 0 ] )
F_17 ( L_7 ) ;
F_2 (KERN_INFO PFX L_8 , board.name) ;
if ( F_18 () != V_9 . V_34 )
F_17 ( L_9 ) ;
}
int T_1 F_19 ( void )
{
if ( V_9 . V_35 )
F_20 ( 0 ) ;
if ( V_9 . V_36 )
F_20 ( 1 ) ;
if ( V_9 . V_24 )
F_21 () ;
if ( V_9 . V_26 &&
! F_22 ( V_9 . V_27 . V_37 ) )
F_23 ( 0 , & V_9 . V_27 ) ;
if ( V_9 . V_31 &&
! F_22 ( V_9 . V_32 . V_37 ) )
F_23 ( 1 , & V_9 . V_32 ) ;
if ( V_9 . V_38 )
F_24 ( & V_9 . V_39 ) ;
if ( V_9 . V_40 )
F_25 ( & V_9 . V_41 ) ;
#ifdef F_26
if ( ! F_22 ( V_7 . V_42 ) ) {
memcpy ( V_7 . V_43 , V_7 . V_42 , V_44 ) ;
memcpy ( V_7 . V_45 , V_7 . V_42 , V_44 ) ;
if ( F_27 (
& F_1 ) < 0 )
F_28 ( V_46 L_10 ) ;
}
#endif
F_29 () ;
F_30 () ;
V_47 . V_48 = F_12 ( V_9 . V_49 ) ;
V_47 . V_49 = V_9 . V_49 ;
F_31 ( & V_50 ) ;
return 0 ;
}
