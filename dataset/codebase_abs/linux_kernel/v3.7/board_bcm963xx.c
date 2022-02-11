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
static int F_4 ( T_1 * V_11 )
{
T_1 * V_12 ;
int V_13 ;
if ( V_14 >= V_15 . V_16 ) {
F_2 (KERN_ERR PFX L_2 ) ;
return - V_17 ;
}
memcpy ( V_11 , V_15 . V_18 , V_19 ) ;
V_12 = V_11 + V_19 / 2 - 1 ;
V_13 = V_14 ;
while ( V_13 -- ) {
T_1 * V_20 = V_11 + V_19 - 1 ;
do {
( * V_20 ) ++ ;
if ( * V_20 != 0 )
break;
V_20 -- ;
} while ( V_20 != V_12 );
if ( V_20 == V_12 ) {
F_2 (KERN_ERR PFX L_3 ) ;
return - V_17 ;
}
}
V_14 ++ ;
return 0 ;
}
void T_2 F_5 ( void )
{
unsigned int V_21 , V_22 ;
T_1 * V_23 , * V_24 , * V_20 ;
char V_25 [ 32 ] ;
T_3 V_26 ;
if ( F_6 () )
V_26 = 0x18000000 ;
else {
V_26 = F_7 ( F_8 ( 0 ) ) ;
V_26 &= V_27 ;
}
V_23 = ( T_1 * ) F_9 ( V_26 ) ;
V_24 = V_23 + V_28 ;
if ( ! memcmp ( V_24 , L_4 , 5 ) )
snprintf ( V_25 , sizeof( V_25 ) , L_5 ,
V_24 [ 5 ] , V_24 [ 6 ] , V_24 [ 7 ] , V_24 [ 8 ] , V_24 [ 9 ] ) ;
else
strcpy ( V_25 , L_6 ) ;
F_2 (KERN_INFO PFX L_7 , cfe_version) ;
memcpy ( & V_15 , V_23 + V_29 , sizeof( V_15 ) ) ;
if ( V_15 . V_30 <= 4 )
V_21 = F_10 ( struct V_31 , V_32 ) ;
else
V_21 = sizeof( V_15 ) ;
V_26 = 0 ;
V_20 = ( T_1 * ) & V_15 ;
while ( V_21 -- )
V_26 += * V_20 ;
if ( V_26 ) {
F_2 (KERN_ERR PFX L_8 ) ;
return;
}
for ( V_22 = 0 ; V_22 < F_11 ( V_33 ) ; V_22 ++ ) {
if ( strncmp ( V_15 . V_10 , V_33 [ V_22 ] -> V_10 ,
sizeof( V_15 . V_10 ) ) )
continue;
memcpy ( & V_9 , V_33 [ V_22 ] , sizeof( V_9 ) ) ;
break;
}
if ( ! V_9 . V_10 [ 0 ] ) {
char V_10 [ 17 ] ;
memcpy ( V_10 , V_15 . V_10 , 16 ) ;
V_10 [ 16 ] = 0 ;
F_2 (KERN_ERR PFX L_9 ,
name) ;
return;
}
V_26 = 0 ;
#ifdef F_12
if ( V_9 . V_34 ) {
V_35 = 1 ;
if ( F_13 () )
V_26 |= V_36 ;
}
#endif
if ( V_9 . V_37 ) {
if ( F_13 () )
V_26 |= V_38 ;
}
if ( V_9 . V_39 && ! V_9 . V_40 . V_41 ) {
if ( F_13 () )
V_26 |= V_42 |
V_43 ;
}
if ( V_9 . V_44 && ! V_9 . V_45 . V_41 ) {
if ( F_13 () )
V_26 |= V_42 |
V_43 ;
}
F_14 ( V_26 , V_46 ) ;
}
void T_2 F_15 ( void )
{
if ( ! V_9 . V_10 [ 0 ] )
F_16 ( L_10 ) ;
F_2 (KERN_INFO PFX L_11 , board.name) ;
if ( F_17 () != V_9 . V_47 )
F_16 ( L_12 ) ;
}
int T_2 F_18 ( void )
{
if ( V_9 . V_48 )
F_19 ( 0 ) ;
if ( V_9 . V_49 )
F_19 ( 1 ) ;
if ( V_9 . V_37 )
F_20 () ;
if ( V_9 . V_39 &&
! F_4 ( V_9 . V_40 . V_50 ) )
F_21 ( 0 , & V_9 . V_40 ) ;
if ( V_9 . V_44 &&
! F_4 ( V_9 . V_45 . V_50 ) )
F_21 ( 1 , & V_9 . V_45 ) ;
if ( V_9 . V_51 )
F_22 ( & V_9 . V_52 ) ;
if ( V_9 . V_53 )
F_23 ( & V_9 . V_54 ) ;
#ifdef F_24
if ( ! F_4 ( V_7 . V_55 ) ) {
memcpy ( V_7 . V_56 , V_7 . V_55 , V_19 ) ;
memcpy ( V_7 . V_57 , V_7 . V_55 , V_19 ) ;
if ( F_25 (
& F_1 ) < 0 )
F_26 ( V_58 L_13 ) ;
}
#endif
F_27 () ;
F_28 () ;
V_59 . V_60 = F_11 ( V_9 . V_61 ) ;
V_59 . V_61 = V_9 . V_61 ;
F_29 ( & V_62 ) ;
return 0 ;
}
