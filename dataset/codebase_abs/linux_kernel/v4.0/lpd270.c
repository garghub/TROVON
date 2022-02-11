static void F_1 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 - F_2 ( 0 ) ;
F_3 ( ~ ( 1 << V_3 ) , V_5 ) ;
V_6 &= ~ ( 1 << V_3 ) ;
F_3 ( V_6 , V_7 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_3 = V_2 -> V_4 - F_2 ( 0 ) ;
V_6 |= 1 << V_3 ;
F_3 ( V_6 , V_7 ) ;
}
static void F_5 ( unsigned int V_4 , struct V_8 * V_9 )
{
unsigned long V_10 ;
V_10 = F_6 ( V_5 ) & V_6 ;
do {
V_9 -> V_1 . V_11 -> V_12 ( & V_9 -> V_1 ) ;
if ( F_7 ( V_10 ) ) {
V_4 = F_2 ( 0 ) + F_8 ( V_10 ) ;
F_9 ( V_4 ) ;
V_10 = F_6 ( V_5 ) &
V_6 ;
}
} while ( V_10 );
}
static void T_1 F_10 ( void )
{
int V_4 ;
F_11 () ;
F_3 ( 0 , V_7 ) ;
F_3 ( 0 , V_5 ) ;
for ( V_4 = F_2 ( 2 ) ; V_4 <= F_2 ( 4 ) ; V_4 ++ ) {
F_12 ( V_4 , & V_13 ,
V_14 ) ;
F_13 ( V_4 , V_15 | V_16 ) ;
}
F_14 ( F_15 ( 0 ) , F_5 ) ;
F_16 ( F_15 ( 0 ) , V_17 ) ;
}
static void F_17 ( void )
{
F_3 ( V_6 , V_7 ) ;
}
static int T_1 F_18 ( void )
{
if ( F_19 () ) {
F_20 ( & V_18 ) ;
return 0 ;
}
return - V_19 ;
}
static int T_1 F_21 ( char * V_20 )
{
if ( ! strncasecmp ( V_20 , L_1 , 11 ) ) {
V_21 = & V_22 ;
} else if ( ! strncasecmp ( V_20 , L_2 , 11 ) ) {
V_21 = & V_23 ;
} else if ( ! strncasecmp ( V_20 , L_3 , 11 ) ) {
V_21 = & V_24 ;
} else if ( ! strncasecmp ( V_20 , L_4 , 8 ) ) {
V_21 = & V_25 ;
} else if ( ! strncasecmp ( V_20 , L_5 , 8 ) ) {
V_21 = & V_26 ;
} else if ( ! strncasecmp ( V_20 , L_6 , 14 ) ) {
V_21 = & V_27 ;
} else {
F_22 ( V_28 L_7 , V_20 ) ;
}
return 1 ;
}
static void T_1 F_23 ( void )
{
F_24 ( F_25 ( V_29 ) ) ;
F_26 ( NULL ) ;
F_27 ( NULL ) ;
F_28 ( NULL ) ;
V_30 [ 0 ] . V_31 = ( F_29 ( V_32 ) & 1 ) ? 2 : 4 ;
V_30 [ 1 ] . V_31 = 4 ;
V_33 = V_34 | 0x234 ;
F_30 ( V_35 , F_31 ( V_35 ) ) ;
F_32 ( NULL ) ;
if ( V_21 != NULL )
F_33 ( NULL , V_21 ) ;
F_34 ( & V_36 ) ;
}
static void T_1 F_35 ( void )
{
F_36 () ;
F_37 ( V_37 , F_31 ( V_37 ) ) ;
V_38 |= 0x00000F04 ;
V_39 = 0x00000066 ;
}
