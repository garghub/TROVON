static int
F_1 ( struct V_1 * V_2 , int V_3 , int V_4 , bool V_5 )
{
struct V_6 * V_7 = ( void * ) V_2 ;
struct V_1 * V_8 = ( void * ) F_2 ( V_7 ) -> V_9 ;
T_1 V_10 , V_11 ;
F_3 ( L_1 , V_3 , V_4 , V_5 ) ;
F_4 ( V_8 , V_7 -> V_12 , 0xa0 , V_4 ) ;
F_4 ( V_8 , V_7 -> V_12 , 0xa1 , V_3 | ( V_5 ? 0x80 : 0x00 ) ) ;
F_4 ( V_8 , V_7 -> V_12 , 0xa2 , 0x01 ) ;
F_4 ( V_8 , V_7 -> V_12 , 0xa8 , 0x01 ) ;
V_11 = 0 ;
while ( ( V_10 = F_5 ( V_8 , V_7 -> V_12 , 0xa8 ) ) & 0x01 ) {
F_6 ( 5 ) ;
if ( V_11 ++ == 100 ) {
F_7 ( V_2 , L_2 ) ;
return - V_13 ;
}
}
if ( V_10 & 0x70 ) {
F_7 ( V_2 , L_3 , V_10 ) ;
return - V_14 ;
}
return 1 ;
}
static int
F_8 ( struct V_1 * V_2 , bool V_15 ,
T_1 type , T_2 V_12 , T_1 * V_16 , T_1 V_17 )
{
struct V_6 * V_7 = ( void * ) V_2 ;
struct V_1 * V_8 = ( void * ) F_2 ( V_7 ) -> V_9 ;
int V_11 , V_18 = - V_13 ;
T_1 V_19 [ 16 ] = {} ;
T_1 V_10 ;
F_3 ( L_4 , type , V_12 , V_17 ) ;
V_10 = F_5 ( V_8 , V_7 -> V_20 , 0x07 ) & ~ 0x04 ;
F_4 ( V_8 , V_7 -> V_20 , 0x07 , V_10 | 0x04 ) ;
F_4 ( V_8 , V_7 -> V_20 , 0x07 , V_10 ) ;
F_4 ( V_8 , V_7 -> V_20 , 0xf7 , 0x01 ) ;
F_4 ( V_8 , V_7 -> V_12 , 0xe4 , 0x80 ) ;
if ( ! ( type & 1 ) ) {
memcpy ( V_19 , V_16 , V_17 ) ;
F_3 ( L_5 , V_19 ) ;
for ( V_11 = 0 ; V_11 < V_17 ; V_11 ++ )
F_4 ( V_8 , V_7 -> V_12 , 0xf0 + V_11 , V_19 [ V_11 ] ) ;
}
F_4 ( V_8 , V_7 -> V_12 , 0xe5 , ( ( V_17 - 1 ) << 4 ) | type ) ;
F_4 ( V_8 , V_7 -> V_12 , 0xe6 , ( V_12 & 0x000ff ) >> 0 ) ;
F_4 ( V_8 , V_7 -> V_12 , 0xe7 , ( V_12 & 0x0ff00 ) >> 8 ) ;
F_4 ( V_8 , V_7 -> V_12 , 0xe8 , ( V_12 & 0xf0000 ) >> 16 ) ;
F_4 ( V_8 , V_7 -> V_12 , 0xe9 , 0x01 ) ;
V_11 = 0 ;
while ( ( V_10 = F_5 ( V_8 , V_7 -> V_12 , 0xe9 ) ) & 0x01 ) {
F_6 ( 5 ) ;
if ( V_11 ++ == 32 )
goto V_21;
}
if ( ( V_10 = F_5 ( V_8 , V_7 -> V_20 , 0xf7 ) ) & 0x01 ) {
V_18 = - V_14 ;
goto V_21;
}
if ( type & 1 ) {
for ( V_11 = 0 ; V_11 < V_17 ; V_11 ++ )
V_19 [ V_11 ] = F_5 ( V_8 , V_7 -> V_12 , 0xf0 + V_11 ) ;
F_3 ( L_5 , V_19 ) ;
memcpy ( V_16 , V_19 , V_17 ) ;
}
V_18 = 0 ;
V_21:
F_4 ( V_8 , V_7 -> V_20 , 0xf7 , 0x01 ) ;
return V_18 ;
}
static int
F_9 ( struct V_22 * V_9 ,
struct V_22 * V_23 ,
struct V_24 * V_25 , void * V_16 , T_2 V_26 ,
struct V_22 * * V_27 )
{
struct V_1 * V_8 = ( void * ) V_9 ;
struct V_6 * V_7 ;
int V_18 ;
V_18 = F_10 ( V_9 , V_23 , V_25 , V_26 ,
& V_28 , & V_29 ,
& V_7 ) ;
* V_27 = F_2 ( V_7 ) ;
if ( V_18 )
return V_18 ;
switch ( ( V_25 -> V_30 & 0xff00 ) >> 8 ) {
case 0x0d :
V_7 -> V_12 = 0x38 ;
V_7 -> V_20 = 0x39 ;
break;
case 0x0e :
V_7 -> V_12 = 0x3c ;
V_7 -> V_20 = 0x3b ;
break;
default:
F_11 ( 1 ) ;
}
if ( V_8 -> V_31 . V_32 == & V_33 ) {
struct V_34 * V_32 = V_8 -> V_31 . V_35 ;
V_32 -> V_36 = F_12 ( V_32 -> V_36 , 40 ) ;
}
return 0 ;
}
static int
F_13 ( struct V_37 * V_38 , struct V_39 * V_40 , int V_41 )
{
struct V_6 * V_2 = V_38 -> V_35 ;
struct V_1 * V_8 = ( void * ) F_2 ( V_2 ) -> V_9 ;
struct V_39 * V_42 = V_40 ;
int V_18 = - V_13 ;
int V_11 , V_43 , V_44 = V_41 ;
T_1 V_45 = 0x00 , V_46 = 0x00 , V_10 ;
V_10 = F_5 ( V_8 , V_2 -> V_20 , 0x07 ) & ~ 0x10 ;
F_4 ( V_8 , V_2 -> V_20 , 0x07 , V_10 | 0x10 ) ;
F_4 ( V_8 , V_2 -> V_20 , 0x07 , V_10 ) ;
F_4 ( V_8 , V_2 -> V_12 , 0x43 , 0x05 ) ;
F_6 ( 5 ) ;
while ( V_44 -- ) {
if ( ( V_42 -> V_47 & V_48 ) && V_42 -> V_12 == 0x50 ) {
F_4 ( V_8 , V_2 -> V_12 , 0x40 , V_42 -> V_12 << 1 ) ;
F_4 ( V_8 , V_2 -> V_12 , 0x41 , V_45 ) ;
F_4 ( V_8 , V_2 -> V_12 , 0x42 , V_46 ) ;
F_4 ( V_8 , V_2 -> V_12 , 0x44 , V_42 -> V_49 ) ;
F_4 ( V_8 , V_2 -> V_12 , 0x45 , 0x00 ) ;
F_4 ( V_8 , V_2 -> V_12 , 0x43 , 0x01 ) ;
for ( V_11 = 0 ; V_11 < V_42 -> V_49 ; V_11 ++ ) {
V_43 = 0 ;
while ( F_5 ( V_8 , V_2 -> V_12 , 0x46 ) & 0x10 ) {
F_6 ( 5 ) ;
if ( V_43 ++ == 32 )
goto V_21;
}
V_42 -> V_19 [ V_11 ] = F_5 ( V_8 , V_2 -> V_12 , 0x47 ) ;
}
} else
if ( ! ( V_42 -> V_47 & V_48 ) ) {
if ( V_42 -> V_12 == 0x50 && V_42 -> V_49 == 0x01 ) {
V_46 = V_42 -> V_19 [ 0 ] ;
} else
if ( V_42 -> V_12 == 0x30 && V_42 -> V_49 == 0x01 ) {
V_45 = V_42 -> V_19 [ 0 ] ;
} else
goto V_21;
} else {
goto V_21;
}
V_42 ++ ;
}
V_18 = V_41 ;
V_21:
F_4 ( V_8 , V_2 -> V_12 , 0x43 , 0x00 ) ;
return V_18 ;
}
static T_2
F_14 ( struct V_37 * V_38 )
{
return V_50 | V_51 ;
}
static int
F_15 ( struct V_22 * V_9 ,
struct V_22 * V_23 ,
struct V_24 * V_25 , void * V_16 , T_2 V_26 ,
struct V_22 * * V_27 )
{
struct V_1 * V_8 = ( void * ) V_9 ;
struct V_6 * V_2 ;
int V_18 ;
V_18 = F_10 ( V_9 , V_23 , V_25 , V_26 ,
& V_52 , & V_53 , & V_2 ) ;
* V_27 = F_2 ( V_2 ) ;
if ( V_18 )
return V_18 ;
switch ( ( V_25 -> V_30 & 0xff00 ) >> 8 ) {
case 0x0d :
V_2 -> V_12 = 0x3d ;
V_2 -> V_20 = 0x39 ;
break;
case 0x0e :
V_2 -> V_12 = 0x3f ;
V_2 -> V_20 = 0x3b ;
break;
default:
F_11 ( 1 ) ;
}
if ( V_8 -> V_31 . V_32 == & V_33 ) {
struct V_34 * V_32 = V_8 -> V_31 . V_35 ;
V_32 -> V_36 = F_12 ( V_32 -> V_36 , 40 ) ;
}
return 0 ;
}
