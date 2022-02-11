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
V_1 , V_18 - 1 , 1 , V_21 ) ;
V_19 = F_7 ( V_7 ,
V_22 ,
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
const T_5 * V_23 )
{
unsigned char V_24 [ 48 ] ;
T_7 V_25 ;
T_7 V_26 ;
unsigned char * V_27 = & V_24 [ 32 ] ;
unsigned char * V_28 = & V_24 [ 16 ] ;
unsigned char * V_29 = & V_24 [ 0 ] ;
unsigned char V_30 [ V_15 ] ;
int V_18 ;
T_8 * V_31 ;
#define F_10 256
T_5 V_32 [ F_10 ] ;
T_9 V_33 ;
unsigned char * V_34 ;
unsigned char * V_35 ;
V_18 = F_6 ( V_1 ) - ( V_4 ? 1 : 0 ) ;
if ( V_18 < V_15 + V_17 ) {
return 0 ;
}
V_31 = ( T_8 * ) F_11 ( V_2 -> V_36 , V_1 , 0 , V_18 + ( V_4 ? 1 : 0 ) ) ;
if ( V_4 &&
( V_31 [ V_18 ] != V_37 ) ) {
return 0 ;
}
V_34 = V_31 ;
V_35 = V_31 + V_15 ;
memset ( V_32 , 0 , sizeof( V_32 ) ) ;
V_33 = ( strlen ( V_23 ) + 4 ) & 0xFC ;
if ( V_33 > F_10 )
V_33 = F_10 ;
F_12 ( V_32 , V_23 , V_33 ) ;
memset ( V_24 , 0 , sizeof( V_24 ) ) ;
F_13 ( & V_25 ) ;
F_14 ( V_32 ,
( unsigned long ) V_33 , & V_25 ) ;
F_14 ( V_35 , V_17 , & V_25 ) ;
F_15 ( V_24 , sizeof ( V_24 ) , & V_25 ) ;
F_13 ( & V_26 ) ;
F_14 ( V_28 , 16 , & V_26 ) ;
F_14 ( V_29 , 16 , & V_26 ) ;
F_16 ( V_27 , 16 ,
V_31 + V_15 , V_18 - V_15 ,
V_30 ) ;
if ( memcmp ( V_30 , V_34 , V_15 ) != 0 )
return 0 ;
F_15 ( V_31 + V_15 + V_17 ,
V_18 - ( V_15 + V_17 ) ,
& V_26 ) ;
{
T_1 * V_38 ;
T_1 * V_39 ;
V_38 = F_17 ( V_31 , V_18 , V_18 ) ;
F_18 ( V_1 , V_38 ) ;
F_19 ( V_2 , V_38 , L_2 ) ;
F_1 ( V_38 , V_2 , V_3 ,
V_4 , V_23 ) ;
V_39 = F_20 ( V_38 ,
V_15 + V_17 ,
V_18 - ( V_15 + V_17 ) ,
V_18 - ( V_15 + V_17 ) ) ;
return F_21 ( V_40 , V_39 , V_2 , V_3 ) + V_15 + V_17 ;
}
}
static int
F_22 ( T_1 * V_1 ,
T_2 * V_2 , T_3 * V_3 ,
void * T_10 V_41 )
{
if ( V_42 )
{
static int V_43 = - 1 ;
int V_44 ;
static int V_45 ;
int V_46 = - 1 ;
T_4 V_47 [] = { FALSE , TRUE } ;
if ( V_43 != - 1 )
{
int V_48 ;
V_48 = F_9 ( V_1 ,
V_2 ,
V_3 ,
V_47 [ V_45 ] ,
V_42 [ V_43 ] ) ;
if ( V_48 > 0 )
return V_48 ;
else
V_43 = - 1 ;
}
for ( V_44 = 0 ;
V_42 [ V_44 ] ;
V_44 ++ )
{
for ( V_46 = 0 ;
V_46 < 2 ;
V_46 ++ )
{
int V_48 ;
V_48 = F_9 ( V_1 ,
V_2 ,
V_3 ,
V_47 [ V_46 ] ,
V_42 [ V_44 ] ) ;
if ( V_48 > 0 )
{
V_43 = V_44 ;
V_45 = V_46 ;
return V_48 ;
}
else if ( V_48 < 0 )
break;
}
}
}
return F_21 ( V_40 , V_1 , V_2 , V_3 ) ;
}
void
F_23 ( void )
{
T_11 * V_49 ;
static T_12 V_50 [] = {
{ & V_14 ,
{ L_3 , L_4 ,
V_51 , V_52 , NULL , 0x0 ,
NULL , V_53 } } ,
{ & V_16 ,
{ L_5 , L_6 ,
V_51 , V_52 , NULL , 0x0 ,
NULL , V_53 } } ,
{ & V_20 ,
{ L_7 , L_8 ,
V_54 , V_55 , F_24 ( V_56 ) , 0x0 ,
NULL , V_53 } } ,
{ & V_22 ,
{ L_9 , L_10 ,
V_57 , V_52 , NULL , 0x0 , NULL , V_53 } } ,
} ;
static T_13 * V_58 [] = {
& V_13 ,
} ;
V_11 = F_25 ( L_11 ,
L_1 , L_12 ) ;
F_26 ( V_11 , V_50 , F_27 ( V_50 ) ) ;
F_28 ( V_58 , F_27 ( V_58 ) ) ;
V_49 = F_29 ( V_11 ,
V_59 ) ;
F_30 ( V_49 , L_13 ,
L_14 ,
L_15 ,
10 ,
& V_60 ) ;
F_31 ( V_49 , L_16 , L_17 ,
L_18 ,
( const T_5 * * ) & V_61 ) ;
}
void
V_59 ( void )
{
static T_4 V_62 = FALSE ;
static T_14 V_63 ;
static int V_64 = 0 ;
if ( V_62 )
{
F_32 ( L_13 , V_64 , V_63 ) ;
F_32 ( L_13 , V_64 - 1 , V_63 ) ;
}
else
{
V_63 = F_33 ( F_22 ,
V_11 ) ;
V_40 = F_34 ( L_19 , V_11 ) ;
V_62 = TRUE ;
}
if ( V_42 ) {
F_35 ( V_42 ) ;
V_42 = NULL ;
}
V_42 = F_36 ( V_61 ,
L_20 ,
0 ) ;
V_64 = V_60 ;
F_37 ( L_13 , V_64 , V_63 ) ;
F_37 ( L_13 , V_64 - 1 , V_63 ) ;
}
