static int T_1
F_1 ( char * string )
{
char * V_1 = string , * V_2 ;
int V_3 = - 1 , V_4 = - 1 ;
while( V_1 != NULL && ( V_2 = strchr ( V_1 , ':' ) ) != NULL ) {
int V_5 = ( int ) F_2 ( ++ V_2 , NULL , 0 ) ;
if( ! strncmp ( V_1 , L_1 , 5 ) )
V_3 = V_5 ;
else if( ! strncmp ( V_1 , L_2 , 5 ) )
V_4 = V_5 ;
else if( ! strncmp ( V_1 , L_3 , 3 ) ) {
if( V_3 == - 1 ) {
F_3 ( V_6 L_4 ) ;
} else if( V_3 > V_7 ) {
F_3 ( V_6 L_5 , V_3 , V_5 ) ;
} else {
if( V_4 != 0 && V_4 != 1 ) {
V_8 [ V_3 * 2 ] = V_5 ;
V_8 [ V_3 * 2 + 1 ] = V_5 ;
} else {
V_8 [ V_3 * 2 + V_4 ] = V_5 ;
}
}
}
if( ( V_1 = strchr ( V_1 , V_9 ) ) != NULL )
V_1 ++ ;
}
return 1 ;
}
static int T_2
F_4 ( struct V_10 * V_11 , int V_4 , int V_12 ,
int V_3 , T_3 V_13 , int V_14 )
{
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_19 ;
V_16 = F_5 ( sizeof( * V_16 ) , V_20 ) ;
if ( ! V_16 ) {
F_3 ( V_21 L_6
L_7 , V_4 ) ;
return - V_22 ;
}
if ( ! F_6 ( V_13 , 64 , L_8 ) ) {
F_3 ( V_21 L_9 ,
V_13 ) ;
V_19 = - V_23 ;
goto V_24;
}
V_16 -> V_25 = F_7 ( V_13 , 64 ) ;
V_16 -> V_14 = ( ( ( 1 << V_4 ) & V_14 ) != 0 ) ;
V_16 -> clock = V_26 ;
V_16 -> V_27 = 8 ;
V_18 = F_8 ( & V_28 , V_16 , V_11 -> V_29 ) ;
if ( ! V_18 ) {
V_19 = - V_22 ;
goto V_30;
}
V_11 -> V_31 [ V_4 ] = V_18 ;
V_18 -> V_32 = V_8 [ V_3 * 2 + V_4 ] ;
V_18 -> V_12 = V_12 ;
V_18 -> V_25 = V_13 ;
F_9 ( V_18 ) ;
return 0 ;
V_30:
F_10 ( V_13 , 64 ) ;
V_24:
F_11 ( V_16 ) ;
return V_19 ;
}
static T_4
F_12 ( int V_12 , void * V_33 )
{
struct V_10 * V_11 = (struct V_10 * ) V_33 ;
int V_34 , V_35 = 0 ;
for ( V_34 = 0 ; V_34 < 2 ; V_34 ++ )
if ( V_11 -> V_31 [ V_34 ] &&
F_13 ( V_12 , V_11 -> V_31 [ V_34 ] ) == V_36 )
V_35 ++ ;
return V_35 ? V_36 : V_37 ;
}
static int T_2
F_14 ( struct V_38 * V_29 )
{
struct V_10 * V_11 ;
int V_14 ;
static int V_39 = 1 ;
struct V_40 * V_41 = F_15 ( V_29 ) ;
int V_3 = V_41 -> V_3 ;
int V_35 = 0 ;
int V_12 , V_34 ;
int V_42 , V_43 , V_44 , V_45 , V_46 ;
T_5 V_47 , V_48 ;
V_46 = F_16 ( V_41 , 4 ) ;
V_46 |= 0x4 ;
F_17 ( V_41 , 4 , V_46 ) ;
F_17 ( V_41 , 6 , 9 ) ;
V_42 = F_16 ( V_41 , 3 ) ;
F_17 ( V_41 , 6 , 10 ) ;
V_43 = F_16 ( V_41 , 3 ) ;
F_17 ( V_41 , 6 , 0 ) ;
V_44 = F_16 ( V_41 , 3 ) ;
F_17 ( V_41 , 6 , 1 ) ;
V_45 = F_16 ( V_41 , 3 ) ;
V_47 = ( ( V_42 << 8 ) | V_43 ) & 0xfffffff0 ;
V_48 = ( ( V_44 << 8 ) | V_45 ) & 0xffffff70 ;
V_12 = ( V_46 & 0x3 ) + 11 ;
if( V_12 >= 13 )
V_12 ++ ;
if( V_39 ) {
F_3 ( V_49 L_10 V_50 L_11
L_12
L_13 ) ;
V_39 = 0 ;
}
V_12 = F_18 ( V_41 , V_12 ) ;
V_47 = F_19 ( V_41 , V_47 ) ;
V_48 = F_19 ( V_41 , V_48 ) ;
F_3 ( V_49 L_14 , V_3 , V_12 , V_48 ) ;
( void ) F_20 ( V_47 + 0x08 ) ;
switch( V_14 = ( F_20 ( V_47 + 0x08 ) >> 6 ) ) {
case 0x00 :
V_14 = 0x02 ;
break;
case 0x01 :
V_14 = 0x03 ;
break;
case 0x03 :
V_14 = 0x00 ;
break;
default:
F_3 ( V_21 L_15 ,
V_14 ) ;
V_14 = 0x00 ;
break;
}
V_11 = F_5 ( sizeof( * V_11 ) , V_20 ) ;
if ( ! V_11 )
return - V_22 ;
V_11 -> V_29 = V_29 ;
snprintf ( V_11 -> V_51 , sizeof( V_11 -> V_51 ) , L_16 , F_21 ( V_29 ) ) ;
if ( F_22 ( V_12 , F_12 , V_52 , V_11 -> V_51 , V_11 ) ) {
F_3 ( V_21 L_17 ) ;
F_11 ( V_11 ) ;
return - V_53 ;
}
for ( V_34 = 0 ; V_34 < 2 ; V_34 ++ ) {
int V_54 ;
if ( ( V_54 = F_4 ( V_11 , V_34 , V_12 , V_3 ,
V_48 + ( 0x80 * V_34 ) ,
V_14 ) ) != 0 )
F_3 ( L_18 ,
V_34 , V_54 ) ;
else
V_35 ++ ;
}
if ( ! V_35 ) {
F_11 ( V_11 ) ;
return - V_23 ;
}
F_23 ( V_41 , 1 ) ;
F_24 ( V_41 , L_8 ) ;
F_25 ( V_29 , V_11 ) ;
return 0 ;
}
static void T_6
F_26 ( struct V_17 * V_18 )
{
F_27 ( V_18 ) ;
F_28 ( V_18 ) ;
F_11 ( (struct V_15 * ) V_18 -> V_16 [ 0 ] ) ;
F_29 ( V_18 -> V_12 , V_18 ) ;
F_10 ( V_18 -> V_25 , 64 ) ;
}
static int T_6
F_30 ( struct V_38 * V_29 )
{
struct V_10 * V_11 = F_31 ( V_29 ) ;
int V_34 ;
for ( V_34 = 0 ; V_34 < 2 ; V_34 ++ )
F_26 ( V_11 -> V_31 [ V_34 ] ) ;
F_11 ( V_11 ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
#ifdef F_33
if ( V_55 )
F_1 ( V_55 ) ;
#endif
return F_34 ( & V_56 ) ;
}
static void T_7 F_35 ( void )
{
F_36 ( & V_56 ) ;
}
