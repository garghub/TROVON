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
if ( F_16 ( V_38 , V_30 , V_31 + V_15 , V_18 - V_15 , V_27 , 16 ) ) {
return 0 ;
}
if ( memcmp ( V_30 , V_34 , V_15 ) != 0 )
return 0 ;
F_15 ( V_31 + V_15 + V_17 ,
V_18 - ( V_15 + V_17 ) ,
& V_26 ) ;
{
T_1 * V_39 ;
T_1 * V_40 ;
V_39 = F_17 ( V_31 , V_18 , V_18 ) ;
F_18 ( V_1 , V_39 ) ;
F_19 ( V_2 , V_39 , L_2 ) ;
F_1 ( V_39 , V_2 , V_3 ,
V_4 , V_23 ) ;
V_40 = F_20 ( V_39 ,
V_15 + V_17 ,
V_18 - ( V_15 + V_17 ) ,
V_18 - ( V_15 + V_17 ) ) ;
return F_21 ( V_41 , V_40 , V_2 , V_3 ) + V_15 + V_17 ;
}
}
static int
F_22 ( T_1 * V_1 ,
T_2 * V_2 , T_3 * V_3 ,
void * T_10 V_42 )
{
if ( V_43 )
{
static int V_44 = - 1 ;
int V_45 ;
static int V_46 ;
int V_47 = - 1 ;
T_4 V_48 [] = { FALSE , TRUE } ;
if ( V_44 != - 1 )
{
int V_49 ;
V_49 = F_9 ( V_1 ,
V_2 ,
V_3 ,
V_48 [ V_46 ] ,
V_43 [ V_44 ] ) ;
if ( V_49 > 0 )
return V_49 ;
else
V_44 = - 1 ;
}
for ( V_45 = 0 ;
V_43 [ V_45 ] ;
V_45 ++ )
{
for ( V_47 = 0 ;
V_47 < 2 ;
V_47 ++ )
{
int V_49 ;
V_49 = F_9 ( V_1 ,
V_2 ,
V_3 ,
V_48 [ V_47 ] ,
V_43 [ V_45 ] ) ;
if ( V_49 > 0 )
{
V_44 = V_45 ;
V_46 = V_47 ;
return V_49 ;
}
else if ( V_49 < 0 )
break;
}
}
}
return F_21 ( V_41 , V_1 , V_2 , V_3 ) ;
}
static void
F_23 ( void )
{
F_24 ( V_43 ) ;
}
void
F_25 ( void )
{
T_11 * V_50 ;
static T_12 V_51 [] = {
{ & V_14 ,
{ L_3 , L_4 ,
V_52 , V_53 , NULL , 0x0 ,
NULL , V_54 } } ,
{ & V_16 ,
{ L_5 , L_6 ,
V_52 , V_53 , NULL , 0x0 ,
NULL , V_54 } } ,
{ & V_20 ,
{ L_7 , L_8 ,
V_55 , V_56 , F_26 ( V_57 ) , 0x0 ,
NULL , V_54 } } ,
{ & V_22 ,
{ L_9 , L_10 ,
V_58 , V_53 , NULL , 0x0 , NULL , V_54 } } ,
} ;
static T_13 * V_59 [] = {
& V_13 ,
} ;
V_11 = F_27 ( L_11 ,
L_1 , L_12 ) ;
F_28 ( V_11 , V_51 , F_29 ( V_51 ) ) ;
F_30 ( V_59 , F_29 ( V_59 ) ) ;
V_50 = F_31 ( V_11 ,
V_60 ) ;
F_32 ( V_50 , L_13 , L_14 ,
L_15 ,
( const T_5 * * ) & V_61 ) ;
F_33 ( F_23 ) ;
}
void
V_60 ( void )
{
static T_4 V_62 = FALSE ;
static T_14 V_63 ;
if ( ! V_62 )
{
V_63 = F_34 ( F_22 , V_11 ) ;
V_41 = F_35 ( L_16 , V_11 ) ;
F_36 ( L_17 , V_64 , V_63 ) ;
V_62 = TRUE ;
}
if ( V_43 ) {
F_24 ( V_43 ) ;
V_43 = NULL ;
}
V_43 = F_37 ( V_61 , L_18 , 0 ) ;
}
