unsigned char F_1 ( int V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
unsigned char F_3 ( int V_1 )
{
unsigned long V_3 ;
unsigned char V_4 ;
F_4 ( & V_5 , V_3 ) ;
V_4 = F_1 ( V_1 ) ;
F_5 ( & V_5 , V_3 ) ;
return V_4 ;
}
void F_6 ( unsigned char V_4 , int V_1 )
{
F_7 ( V_4 , V_2 + V_1 ) ;
}
void F_8 ( unsigned char V_4 , int V_1 )
{
unsigned long V_3 ;
F_4 ( & V_5 , V_3 ) ;
F_6 ( V_4 , V_1 ) ;
F_5 ( & V_5 , V_3 ) ;
}
int F_9 ( void )
{
return F_10 () ;
}
int F_11 ( void )
{
unsigned long V_3 ;
int V_6 ;
F_4 ( & V_5 , V_3 ) ;
V_6 = F_9 () ;
F_5 ( & V_5 , V_3 ) ;
return V_6 ;
}
static void F_12 ( void )
{
F_13 () ;
}
static T_1 F_14 ( struct V_7 * V_7 , T_1 V_8 , int V_9 )
{
return F_15 ( V_7 , V_8 , V_9 , V_10 ,
V_11 ) ;
}
static T_2 F_16 ( struct V_7 * V_7 , char T_3 * V_12 ,
T_4 V_13 , T_1 * V_14 )
{
unsigned char V_15 [ V_11 ] ;
unsigned V_1 = * V_14 ;
unsigned char * V_16 ;
F_17 ( & V_5 ) ;
if ( ! F_9 () )
goto V_17;
for ( V_16 = V_15 ; V_13 -- > 0 && V_1 < V_11 ; ++ V_1 , ++ V_16 )
* V_16 = F_1 ( V_1 ) ;
F_18 ( & V_5 ) ;
if ( F_19 ( V_12 , V_15 , V_16 - V_15 ) )
return - V_18 ;
* V_14 = V_1 ;
return V_16 - V_15 ;
V_17:
F_18 ( & V_5 ) ;
return - V_19 ;
}
static T_2 F_20 ( struct V_7 * V_7 , const char T_3 * V_12 ,
T_4 V_13 , T_1 * V_14 )
{
unsigned char V_15 [ V_11 ] ;
unsigned V_1 = * V_14 ;
unsigned char * V_16 ;
if ( V_1 >= V_11 )
return 0 ;
if ( V_13 > V_11 - V_1 )
V_13 = V_11 - V_1 ;
if ( V_13 > V_11 )
return - V_18 ;
if ( F_21 ( V_15 , V_12 , V_13 ) )
return - V_18 ;
F_17 ( & V_5 ) ;
if ( ! F_9 () )
goto V_17;
for ( V_16 = V_15 ; V_13 -- ; ++ V_1 , ++ V_16 )
F_6 ( * V_16 , V_1 ) ;
F_12 () ;
F_18 ( & V_5 ) ;
* V_14 = V_1 ;
return V_16 - V_15 ;
V_17:
F_18 ( & V_5 ) ;
return - V_19 ;
}
static long F_22 ( struct V_7 * V_7 , unsigned int V_20 ,
unsigned long V_21 )
{
int V_1 ;
switch ( V_20 ) {
case V_22 :
if ( ! F_23 ( V_23 ) )
return - V_24 ;
F_24 ( & V_25 ) ;
F_17 ( & V_5 ) ;
for ( V_1 = 0 ; V_1 < V_11 ; ++ V_1 )
F_6 ( 0 , V_1 ) ;
F_12 () ;
F_18 ( & V_5 ) ;
F_25 ( & V_25 ) ;
return 0 ;
case V_26 :
if ( ! F_23 ( V_23 ) )
return - V_24 ;
F_24 ( & V_25 ) ;
F_17 ( & V_5 ) ;
F_12 () ;
F_18 ( & V_5 ) ;
F_25 ( & V_25 ) ;
return 0 ;
default:
return - V_27 ;
}
}
static int F_26 ( struct V_28 * V_28 , struct V_7 * V_7 )
{
F_27 ( & V_29 ) ;
if ( ( V_30 && ( V_7 -> V_31 & V_32 ) ) ||
( V_33 & V_34 ) ||
( ( V_7 -> V_35 & V_36 ) && ( V_33 & V_37 ) ) ) {
F_28 ( & V_29 ) ;
return - V_38 ;
}
if ( V_7 -> V_31 & V_32 )
V_33 |= V_34 ;
if ( V_7 -> V_35 & V_36 )
V_33 |= V_37 ;
V_30 ++ ;
F_28 ( & V_29 ) ;
return 0 ;
}
static int F_29 ( struct V_28 * V_28 , struct V_7 * V_7 )
{
F_27 ( & V_29 ) ;
V_30 -- ;
if ( V_33 & V_34 )
V_33 &= ~ V_34 ;
if ( V_7 -> V_35 & V_36 )
V_33 &= ~ V_37 ;
F_28 ( & V_29 ) ;
return 0 ;
}
static int F_30 ( void )
{
return 0 ;
}
static int F_31 ( struct V_39 * V_40 , void * V_8 )
{
unsigned char V_15 [ V_11 ] ;
int V_1 = 0 ;
F_17 ( & V_5 ) ;
for ( V_1 = 0 ; V_1 < V_11 ; ++ V_1 )
V_15 [ V_1 ] = F_1 ( V_1 ) ;
F_18 ( & V_5 ) ;
F_32 ( V_15 , V_40 , V_8 ) ;
return 0 ;
}
static int F_33 ( struct V_28 * V_28 , struct V_7 * V_7 )
{
return F_34 ( V_7 , F_31 , NULL ) ;
}
static int F_30 ( void )
{
if ( ! F_35 ( L_1 , 0 , NULL , & V_41 ) )
return - V_42 ;
return 0 ;
}
static int T_5 F_36 ( void )
{
int V_43 ;
if ( ! F_37 () )
return - V_44 ;
V_43 = F_38 ( & V_45 ) ;
if ( V_43 ) {
F_39 ( V_46 L_2 ,
V_47 ) ;
goto V_48;
}
V_43 = F_30 () ;
if ( V_43 ) {
F_39 ( V_46 L_3 ) ;
goto V_49;
}
V_43 = 0 ;
F_39 ( V_50 L_4 V_51 L_5 ) ;
V_48:
return V_43 ;
V_49:
F_40 ( & V_45 ) ;
goto V_48;
}
static void T_6 F_41 ( void )
{
F_42 ( L_1 , NULL ) ;
F_40 ( & V_45 ) ;
}
static int F_43 ( void )
{
int V_1 ;
unsigned short V_52 = 0 ;
unsigned short V_53 ;
for ( V_1 = V_54 ; V_1 <= V_55 ; ++ V_1 )
V_52 += F_1 ( V_1 ) ;
V_53 = F_1 ( V_56 ) << 8 |
F_1 ( V_56 + 1 ) ;
return ( V_52 & 0xffff ) == V_53 ;
}
static void F_44 ( void )
{
int V_1 ;
unsigned short V_52 = 0 ;
for ( V_1 = V_54 ; V_1 <= V_55 ; ++ V_1 )
V_52 += F_1 ( V_1 ) ;
F_6 ( V_52 >> 8 , V_56 ) ;
F_6 ( V_52 & 0xff , V_56 + 1 ) ;
}
static void F_45 ( unsigned char * V_57 , struct V_39 * V_40 ,
void * V_8 )
{
int V_58 ;
int type ;
F_17 ( & V_5 ) ;
V_58 = F_9 () ;
F_18 ( & V_5 ) ;
F_46 ( V_40 , L_6 , V_58 ? L_7 : L_8 ) ;
F_46 ( V_40 , L_9 ,
( V_57 [ 6 ] & 1 ) ? ( V_57 [ 6 ] >> 6 ) + 1 : 0 ) ;
F_46 ( V_40 , L_10 ) ;
type = V_57 [ 2 ] >> 4 ;
if ( type < F_47 ( V_59 ) )
F_46 ( V_40 , L_11 , V_59 [ type ] ) ;
else
F_46 ( V_40 , L_12 , type ) ;
F_46 ( V_40 , L_13 ) ;
type = V_57 [ 2 ] & 0x0f ;
if ( type < F_47 ( V_59 ) )
F_46 ( V_40 , L_11 , V_59 [ type ] ) ;
else
F_46 ( V_40 , L_12 , type ) ;
F_46 ( V_40 , L_14 ) ;
type = V_57 [ 4 ] >> 4 ;
if ( type )
F_46 ( V_40 , L_15 , type == 0x0f ? V_57 [ 11 ] : type ) ;
else
F_46 ( V_40 , L_16 ) ;
F_46 ( V_40 , L_17 ) ;
type = V_57 [ 4 ] & 0x0f ;
if ( type )
F_46 ( V_40 , L_15 , type == 0x0f ? V_57 [ 12 ] : type ) ;
else
F_46 ( V_40 , L_16 ) ;
F_46 ( V_40 , L_18 ,
V_57 [ 18 ] | ( V_57 [ 19 ] << 8 ) ,
V_57 [ 20 ] , V_57 [ 25 ] ,
V_57 [ 21 ] | ( V_57 [ 22 ] << 8 ) , V_57 [ 23 ] | ( V_57 [ 24 ] << 8 ) ) ;
F_46 ( V_40 , L_19 ,
V_57 [ 39 ] | ( V_57 [ 40 ] << 8 ) ,
V_57 [ 41 ] , V_57 [ 46 ] ,
V_57 [ 42 ] | ( V_57 [ 43 ] << 8 ) , V_57 [ 44 ] | ( V_57 [ 45 ] << 8 ) ) ;
F_46 ( V_40 , L_20 , V_57 [ 7 ] | ( V_57 [ 8 ] << 8 ) ) ;
F_46 ( V_40 , L_21 ,
V_57 [ 9 ] | ( V_57 [ 10 ] << 8 ) , V_57 [ 34 ] | ( V_57 [ 35 ] << 8 ) ) ;
F_46 ( V_40 , L_22 ,
V_60 [ ( V_57 [ 6 ] >> 4 ) & 3 ] ) ;
F_46 ( V_40 , L_23 ,
( V_57 [ 6 ] & 2 ) ? L_7 : L_8 ) ;
return;
}
static int F_48 ( void )
{
int V_1 ;
unsigned char V_52 = 0 ;
for ( V_1 = V_61 ; V_1 <= V_62 ; ++ V_1 )
V_52 += F_1 ( V_1 ) ;
return ( F_1 ( V_63 ) == ( ~ V_52 & 0xff ) ) &&
( F_1 ( V_63 + 1 ) == ( V_52 & 0xff ) ) ;
}
static void F_49 ( void )
{
int V_1 ;
unsigned char V_52 = 0 ;
for ( V_1 = V_61 ; V_1 <= V_62 ; ++ V_1 )
V_52 += F_1 ( V_1 ) ;
F_6 ( ~ V_52 , V_63 ) ;
F_6 ( V_52 , V_63 + 1 ) ;
}
static void F_50 ( unsigned char * V_57 , struct V_39 * V_40 ,
void * V_8 )
{
int V_58 = F_11 () ;
int V_1 ;
unsigned V_64 ;
F_46 ( V_40 , L_24 , V_58 ? L_7 : L_8 ) ;
F_46 ( V_40 , L_25 ) ;
for ( V_1 = F_47 ( V_65 ) - 1 ; V_1 >= 0 ; -- V_1 ) {
if ( V_57 [ 1 ] == V_65 [ V_1 ] . V_66 ) {
F_46 ( V_40 , L_11 , V_65 [ V_1 ] . V_67 ) ;
break;
}
}
if ( V_1 < 0 )
F_46 ( V_40 , L_26 , V_57 [ 1 ] ) ;
F_46 ( V_40 , L_27 ,
( V_57 [ 16 ] & 0x80 ) ? L_28 : L_29 ) ;
F_46 ( V_40 , L_30 ) ;
if ( V_57 [ 16 ] & 0x80 )
F_46 ( V_40 , L_31 , V_57 [ 16 ] & 7 ) ;
else
F_46 ( V_40 , L_32 ) ;
if ( ( V_68 >> 16 ) != V_69 )
return;
F_46 ( V_40 , L_33 ) ;
if ( V_57 [ 6 ] < F_47 ( V_70 ) )
F_46 ( V_40 , L_11 , V_70 [ V_57 [ 6 ] ] ) ;
else
F_46 ( V_40 , L_34 , V_57 [ 6 ] ) ;
F_46 ( V_40 , L_35 ) ;
if ( V_57 [ 7 ] < F_47 ( V_70 ) )
F_46 ( V_40 , L_11 , V_70 [ V_57 [ 7 ] ] ) ;
else
F_46 ( V_40 , L_34 , V_57 [ 7 ] ) ;
F_46 ( V_40 , L_36 ) ;
F_46 ( V_40 , V_71 [ V_57 [ 8 ] & 7 ] ,
V_57 [ 9 ] ? V_57 [ 9 ] : '/' , V_57 [ 9 ] ? V_57 [ 9 ] : '/' ) ;
F_46 ( V_40 , L_37 , V_57 [ 8 ] & 16 ? 24 : 12 ) ;
F_46 ( V_40 , L_38 ) ;
if ( V_57 [ 10 ] == 0 )
F_46 ( V_40 , L_39 ) ;
else
F_46 ( V_40 , L_40 , V_57 [ 10 ] ,
V_57 [ 10 ] < 8 ? L_41 : L_7 ) ;
V_64 = ( V_57 [ 14 ] << 8 ) | V_57 [ 15 ] ;
F_46 ( V_40 ,
L_42 ,
V_72 [ V_64 & 7 ] ,
V_64 & 8 ? 80 : 40 ,
V_64 & 16 ? L_43 : L_44 , V_64 & 32 ? L_45 : L_46 ) ;
F_46 ( V_40 , L_47 ,
V_64 & 64 ? L_7 : L_48 ,
V_64 & 128 ? L_28 : L_29 ,
V_64 & 256 ?
( V_64 & 16 ? L_49 : L_50 ) : L_7 ) ;
return;
}
