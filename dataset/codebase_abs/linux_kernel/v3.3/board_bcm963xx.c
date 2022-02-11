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
V_12 = V_11 + V_19 - 1 ;
V_13 = V_14 ;
while ( V_13 -- ) {
do {
( * V_12 ) ++ ;
if ( * V_12 != 0 )
break;
V_12 -- ;
} while ( V_12 != V_11 );
}
if ( V_12 == V_11 ) {
F_2 (KERN_ERR PFX L_3 ) ;
return - V_17 ;
}
V_14 ++ ;
return 0 ;
}
void T_2 F_5 ( void )
{
unsigned int V_20 , V_21 ;
T_1 * V_22 , * V_23 , * V_12 ;
char V_24 [ 32 ] ;
T_3 V_25 ;
V_25 = F_6 ( F_7 ( 0 ) ) ;
V_25 &= V_26 ;
V_22 = ( T_1 * ) F_8 ( V_25 ) ;
V_23 = V_22 + V_27 ;
if ( ! memcmp ( V_23 , L_4 , 5 ) )
snprintf ( V_24 , sizeof( V_24 ) , L_5 ,
V_23 [ 5 ] , V_23 [ 6 ] , V_23 [ 7 ] , V_23 [ 8 ] , V_23 [ 9 ] ) ;
else
strcpy ( V_24 , L_6 ) ;
F_2 (KERN_INFO PFX L_7 , cfe_version) ;
memcpy ( & V_15 , V_22 + V_28 , sizeof( V_15 ) ) ;
if ( V_15 . V_29 <= 4 )
V_20 = F_9 ( struct V_30 , V_31 ) ;
else
V_20 = sizeof( V_15 ) ;
V_25 = 0 ;
V_12 = ( T_1 * ) & V_15 ;
while ( V_20 -- )
V_25 += * V_12 ;
if ( V_25 ) {
F_2 (KERN_ERR PFX L_8 ) ;
return;
}
for ( V_21 = 0 ; V_21 < F_10 ( V_32 ) ; V_21 ++ ) {
if ( strncmp ( V_15 . V_10 , V_32 [ V_21 ] -> V_10 ,
sizeof( V_15 . V_10 ) ) )
continue;
memcpy ( & V_9 , V_32 [ V_21 ] , sizeof( V_9 ) ) ;
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
V_25 = 0 ;
#ifdef F_11
if ( V_9 . V_33 ) {
V_34 = 1 ;
if ( F_12 () )
V_25 |= V_35 ;
}
#endif
if ( V_9 . V_36 ) {
if ( F_12 () )
V_25 |= V_37 ;
}
if ( V_9 . V_38 && ! V_9 . V_39 . V_40 ) {
if ( F_12 () )
V_25 |= V_41 |
V_42 ;
}
if ( V_9 . V_43 && ! V_9 . V_44 . V_40 ) {
if ( F_12 () )
V_25 |= V_41 |
V_42 ;
}
F_13 ( V_25 , V_45 ) ;
}
void T_2 F_14 ( void )
{
if ( ! V_9 . V_10 [ 0 ] )
F_15 ( L_10 ) ;
F_2 (KERN_INFO PFX L_11 , board.name) ;
if ( F_16 () != V_9 . V_46 )
F_15 ( L_12 ) ;
}
int T_2 F_17 ( void )
{
T_3 V_25 ;
if ( V_9 . V_47 )
F_18 ( 0 ) ;
if ( V_9 . V_48 )
F_18 ( 1 ) ;
if ( V_9 . V_36 )
F_19 () ;
if ( V_9 . V_38 &&
! F_4 ( V_9 . V_39 . V_49 ) )
F_20 ( 0 , & V_9 . V_39 ) ;
if ( V_9 . V_43 &&
! F_4 ( V_9 . V_44 . V_49 ) )
F_20 ( 1 , & V_9 . V_44 ) ;
if ( V_9 . V_50 )
F_21 ( & V_9 . V_51 ) ;
#ifdef F_22
if ( ! F_4 ( V_7 . V_52 ) ) {
memcpy ( V_7 . V_53 , V_7 . V_52 , V_19 ) ;
memcpy ( V_7 . V_54 , V_7 . V_52 , V_19 ) ;
if ( F_23 (
& F_1 ) < 0 )
F_24 ( V_55 L_13 ) ;
}
#endif
V_25 = F_6 ( F_7 ( 0 ) ) ;
V_25 &= V_26 ;
V_56 [ 0 ] . V_57 = V_25 ;
V_56 [ 0 ] . V_58 = 0x1FFFFFFF ;
F_25 ( & V_59 ) ;
V_60 . V_61 = F_10 ( V_9 . V_62 ) ;
V_60 . V_62 = V_9 . V_62 ;
F_25 ( & V_63 ) ;
return 0 ;
}
