static T_1 int
F_1 ( char * V_1 )
{
char * V_2 = V_1 , * V_3 ;
int V_4 = - 1 ;
while( V_2 != NULL && ( V_3 = strchr ( V_2 , ':' ) ) != NULL ) {
int V_5 = ( int ) F_2 ( ++ V_3 , NULL , 0 ) ;
if( ! strncmp ( V_2 , L_1 , 5 ) )
V_4 = V_5 ;
else if( ! strncmp ( V_2 , L_2 , 3 ) ) {
if( V_4 == - 1 ) {
F_3 ( V_6 L_3 ) ;
} else if( V_4 >= V_7 ) {
F_3 ( V_6 L_4 , V_4 , V_5 ) ;
} else {
V_8 [ V_4 ] = V_5 ;
}
}
if( ( V_2 = strchr ( V_2 , V_9 ) ) != NULL )
V_2 ++ ;
}
return 1 ;
}
static T_2 int
F_4 ( struct V_10 * V_11 , unsigned long V_12 ,
int V_13 , int clock , int V_14 , int V_15 )
{
struct V_16 * V_17 = NULL ;
struct V_18 * V_19 =
F_5 ( sizeof( struct V_18 ) , V_20 ) ;
F_3 ( V_21 L_5 , F_6 ( V_11 ) ) ;
F_3 ( V_21 L_6 ,
V_13 , clock , V_12 , V_15 ) ;
if( V_19 == NULL ) {
F_3 ( V_22 L_7 ) ;
goto V_23;
}
if( F_7 ( V_12 , 64 , L_8 ) == NULL ) {
F_3 ( V_22 L_9 ,
V_12 ) ;
goto V_24;
}
V_19 -> V_25 = F_8 ( V_12 , 64 ) ;
V_19 -> V_14 = V_14 ;
V_19 -> clock = clock ;
V_19 -> V_26 = 1 ;
V_19 -> V_27 = 8 ;
if( ( V_17 = F_9 ( & V_28 , V_19 , V_11 ) )
== NULL ) {
F_3 ( V_22 L_10 ) ;
goto V_29;
}
V_17 -> V_30 = V_15 ;
V_17 -> V_25 = V_12 ;
V_17 -> V_13 = V_13 ;
if ( F_10 ( V_13 , V_31 , V_32 , L_8 , V_17 ) ) {
F_3 ( V_22 L_11 ) ;
goto V_33;
}
F_11 ( V_11 , V_17 ) ;
F_12 ( V_17 ) ;
return 0 ;
V_33:
F_13 ( V_17 ) ;
V_29:
F_14 ( V_12 , 64 ) ;
V_24:
F_15 ( V_19 ) ;
V_23:
return - V_34 ;
}
static T_3 int
F_16 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = F_17 ( V_11 ) ;
struct V_18 * V_19 =
(struct V_18 * ) V_17 -> V_19 [ 0 ] ;
F_18 ( V_17 ) ;
F_19 ( V_17 ) ;
F_15 ( V_19 ) ;
F_20 ( V_17 -> V_13 , V_17 ) ;
F_14 ( V_17 -> V_25 , 64 ) ;
return 0 ;
}
static T_1 int
F_21 ( struct V_10 * V_11 )
{
struct V_35 * V_36 = F_22 ( V_11 ) ;
unsigned long V_37 = V_36 -> V_12 ;
char V_38 [] = { 11 , 14 , 15 , 10 , 9 , 0 } ;
char V_39 [] = { 3 , 4 , 5 , 7 , 12 , 10 , 11 , 0 } ;
char * V_40 ;
unsigned char V_41 ;
unsigned char V_13 , V_14 = 0 , V_15 = 7 ;
if( strcmp ( V_36 -> V_42 . V_43 , L_12 ) == 0 ) {
T_4 V_5 ;
V_40 = V_39 ;
V_41 = ( F_23 ( V_37 + 0xc85 ) & 0x7 ) - 1 ;
V_5 = F_23 ( V_37 + 0x4 ) ;
V_15 = F_24 ( V_5 ) - 1 ;
if( V_15 > 7 || ( V_5 & ~ ( 1 << V_15 ) ) != 0 ) {
F_3 ( V_22 L_13 , F_6 ( V_11 ) ) ;
V_15 = 7 ;
}
} else {
V_40 = V_38 ;
V_41 = F_23 ( V_37 + 0xc88 ) & 0x07 ;
}
if( V_41 >= strlen ( V_40 ) ) {
F_3 ( L_14 ) ;
return - V_34 ;
}
V_13 = V_40 [ V_41 ] ;
return F_4 ( V_11 , V_37 , V_13 , 50 ,
V_14 , V_15 ) ;
}
static int T_1 F_25 ( void )
{
int V_44 = - V_34 ;
#ifdef F_26
if ( V_45 )
F_1 ( V_45 ) ;
#endif
#ifdef F_27
V_44 = F_28 ( & V_46 ) ;
#endif
return 0 ;
}
static void T_5 F_29 ( void )
{
#ifdef F_27
F_30 ( & V_46 ) ;
#endif
}
