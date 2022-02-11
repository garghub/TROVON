static int
F_1 ( T_1 * V_1 ,
T_2 * V_2 , T_3 * V_3 ,
T_4 V_4 ,
const T_5 * V_5 )
{
T_6 * V_6 ;
T_3 * V_7 ;
F_2 ( V_2 -> V_8 , V_9 , L_1 ) ;
F_3 ( V_2 -> V_8 , V_10 ) ;
if ( V_3 )
{
V_6 = F_4 ( V_3 , V_11 , V_1 , 0 ,
- 1 , V_12 ) ;
V_7 = F_5 ( V_6 , V_13 ) ;
F_4 ( V_7 ,
V_14 ,
V_1 , 0 , V_15 , V_12 ) ;
F_4 ( V_7 ,
V_16 ,
V_1 , V_15 , V_17 , V_12 ) ;
if ( V_4 )
{
int V_18 = F_6 ( V_1 ) ;
T_6 * V_19 ;
F_4 ( V_7 ,
V_20 ,
V_1 , V_18 - 1 , 1 , V_12 ) ;
V_19 = F_7 ( V_7 ,
V_21 ,
V_1 , 0 , 0 , V_5 ) ;
F_8 ( V_19 ) ;
}
}
return V_15 + V_17 ;
}
static int
F_9 ( T_1 * V_1 ,
T_2 * V_2 , T_3 * V_3 ,
T_4 V_4 ,
const T_5 * V_22 )
{
unsigned char V_23 [ 48 ] ;
T_7 V_24 ;
T_7 V_25 ;
unsigned char * V_26 = & V_23 [ 32 ] ;
unsigned char * V_27 = & V_23 [ 16 ] ;
unsigned char * V_28 = & V_23 [ 0 ] ;
unsigned char V_29 [ V_15 ] ;
int V_18 ;
T_8 * V_30 ;
#define F_10 256
T_5 V_31 [ F_10 ] ;
T_9 V_32 ;
unsigned char * V_33 ;
unsigned char * V_34 ;
V_18 = F_6 ( V_1 ) - ( V_4 ? 1 : 0 ) ;
if ( V_18 < V_15 + V_17 ) {
return 0 ;
}
V_30 = ( T_8 * ) F_11 ( V_2 -> V_35 , V_1 , 0 , V_18 + ( V_4 ? 1 : 0 ) ) ;
if ( V_4 &&
( V_30 [ V_18 ] != V_36 ) ) {
return 0 ;
}
V_33 = V_30 ;
V_34 = V_30 + V_15 ;
memset ( V_31 , 0 , sizeof( V_31 ) ) ;
V_32 = ( strlen ( V_22 ) + 4 ) & 0xFC ;
if ( V_32 > F_10 )
V_32 = F_10 ;
F_12 ( V_31 , V_22 , V_32 ) ;
memset ( V_23 , 0 , sizeof( V_23 ) ) ;
F_13 ( & V_24 ) ;
F_14 ( V_31 ,
( unsigned long ) V_32 , & V_24 ) ;
F_14 ( V_34 , V_17 , & V_24 ) ;
F_15 ( V_23 , sizeof ( V_23 ) , & V_24 ) ;
F_13 ( & V_25 ) ;
F_14 ( V_27 , 16 , & V_25 ) ;
F_14 ( V_28 , 16 , & V_25 ) ;
F_16 ( V_26 , 16 ,
V_30 + V_15 , V_18 - V_15 ,
V_29 ) ;
if ( memcmp ( V_29 , V_33 , V_15 ) != 0 )
return 0 ;
F_15 ( V_30 + V_15 + V_17 ,
V_18 - ( V_15 + V_17 ) ,
& V_25 ) ;
{
T_1 * V_37 ;
T_1 * V_38 ;
V_37 = F_17 ( V_30 , V_18 , V_18 ) ;
F_18 ( V_1 , V_37 ) ;
F_19 ( V_2 , V_37 , L_2 ) ;
F_1 ( V_37 , V_2 , V_3 ,
V_4 , V_22 ) ;
V_38 = F_20 ( V_37 ,
V_15 + V_17 ,
V_18 - ( V_15 + V_17 ) ,
V_18 - ( V_15 + V_17 ) ) ;
return F_21 ( V_39 , V_38 , V_2 , V_3 ) + V_15 + V_17 ;
}
}
static int
F_22 ( T_1 * V_1 ,
T_2 * V_2 , T_3 * V_3 ,
void * T_10 V_40 )
{
if ( V_41 )
{
static int V_42 = - 1 ;
int V_43 ;
static int V_44 ;
int V_45 = - 1 ;
T_4 V_46 [] = { FALSE , TRUE } ;
if ( V_42 != - 1 )
{
int V_47 ;
V_47 = F_9 ( V_1 ,
V_2 ,
V_3 ,
V_46 [ V_44 ] ,
V_41 [ V_42 ] ) ;
if ( V_47 > 0 )
return V_47 ;
else
V_42 = - 1 ;
}
for ( V_43 = 0 ;
V_41 [ V_43 ] ;
V_43 ++ )
{
for ( V_45 = 0 ;
V_45 < 2 ;
V_45 ++ )
{
int V_47 ;
V_47 = F_9 ( V_1 ,
V_2 ,
V_3 ,
V_46 [ V_45 ] ,
V_41 [ V_43 ] ) ;
if ( V_47 > 0 )
{
V_42 = V_43 ;
V_44 = V_45 ;
return V_47 ;
}
else if ( V_47 < 0 )
break;
}
}
}
return F_21 ( V_39 , V_1 , V_2 , V_3 ) ;
}
void
F_23 ( void )
{
T_11 * V_48 ;
static T_12 V_49 [] = {
{ & V_14 ,
{ L_3 , L_4 ,
V_50 , V_51 , NULL , 0x0 ,
NULL , V_52 } } ,
{ & V_16 ,
{ L_5 , L_6 ,
V_50 , V_51 , NULL , 0x0 ,
NULL , V_52 } } ,
{ & V_20 ,
{ L_7 , L_8 ,
V_53 , V_54 , F_24 ( V_55 ) , 0x0 ,
NULL , V_52 } } ,
{ & V_21 ,
{ L_9 , L_10 ,
V_56 , V_51 , NULL , 0x0 , NULL , V_52 } } ,
} ;
static T_13 * V_57 [] = {
& V_13 ,
} ;
V_11 = F_25 ( L_11 ,
L_1 , L_12 ) ;
F_26 ( V_11 , V_49 , F_27 ( V_49 ) ) ;
F_28 ( V_57 , F_27 ( V_57 ) ) ;
V_48 = F_29 ( V_11 ,
V_58 ) ;
F_30 ( V_48 , L_13 ,
L_14 ,
L_15 ,
10 ,
& V_59 ) ;
F_31 ( V_48 , L_16 , L_17 ,
L_18 ,
( const T_5 * * ) & V_60 ) ;
}
void
V_58 ( void )
{
static T_4 V_61 = FALSE ;
static T_14 V_62 ;
static int V_63 = 0 ;
if ( V_61 )
{
F_32 ( L_13 , V_63 , V_62 ) ;
F_32 ( L_13 , V_63 - 1 , V_62 ) ;
}
else
{
V_62 = F_33 ( F_22 ,
V_11 ) ;
V_39 = F_34 ( L_19 ) ;
V_61 = TRUE ;
}
if ( V_41 ) {
F_35 ( V_41 ) ;
V_41 = NULL ;
}
V_41 = F_36 ( V_60 ,
L_20 ,
0 ) ;
V_63 = V_59 ;
F_37 ( L_13 , V_63 , V_62 ) ;
F_37 ( L_13 , V_63 - 1 , V_62 ) ;
}
