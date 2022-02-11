T_1 F_1 ( T_2 * V_1 , const short * V_2 , unsigned V_3 , unsigned V_4 , void * V_5 , T_1 V_6 )
{
void * const V_7 = V_1 + 1 ;
T_3 * const V_8 = ( T_3 * ) ( V_7 ) ;
T_4 * V_9 = ( T_4 * ) V_5 ;
T_5 const V_10 = V_3 + 1 ;
T_5 const V_11 = 1 << V_4 ;
T_5 V_12 = V_11 - 1 ;
if ( V_6 < sizeof( T_4 ) * ( V_13 + 1 ) )
return ERROR ( V_14 ) ;
if ( V_3 > V_13 )
return ERROR ( V_15 ) ;
if ( V_4 > V_16 )
return ERROR ( V_14 ) ;
{
T_6 V_17 ;
V_17 . V_4 = ( T_4 ) V_4 ;
V_17 . V_18 = 1 ;
{
T_7 const V_19 = ( T_7 ) ( 1 << ( V_4 - 1 ) ) ;
T_5 V_20 ;
for ( V_20 = 0 ; V_20 < V_10 ; V_20 ++ ) {
if ( V_2 [ V_20 ] == - 1 ) {
V_8 [ V_12 -- ] . V_21 = ( V_22 ) V_20 ;
V_9 [ V_20 ] = 1 ;
} else {
if ( V_2 [ V_20 ] >= V_19 )
V_17 . V_18 = 0 ;
V_9 [ V_20 ] = V_2 [ V_20 ] ;
}
}
}
memcpy ( V_1 , & V_17 , sizeof( V_17 ) ) ;
}
{
T_5 const V_23 = V_11 - 1 ;
T_5 const V_24 = F_2 ( V_11 ) ;
T_5 V_20 , V_25 = 0 ;
for ( V_20 = 0 ; V_20 < V_10 ; V_20 ++ ) {
int V_26 ;
for ( V_26 = 0 ; V_26 < V_2 [ V_20 ] ; V_26 ++ ) {
V_8 [ V_25 ] . V_21 = ( V_22 ) V_20 ;
V_25 = ( V_25 + V_24 ) & V_23 ;
while ( V_25 > V_12 )
V_25 = ( V_25 + V_24 ) & V_23 ;
}
}
if ( V_25 != 0 )
return ERROR ( V_27 ) ;
}
{
T_5 V_28 ;
for ( V_28 = 0 ; V_28 < V_11 ; V_28 ++ ) {
V_22 const V_21 = ( V_22 ) ( V_8 [ V_28 ] . V_21 ) ;
T_4 V_29 = V_9 [ V_21 ] ++ ;
V_8 [ V_28 ] . V_30 = ( V_31 ) ( V_4 - F_3 ( ( T_5 ) V_29 ) ) ;
V_8 [ V_28 ] . V_32 = ( T_4 ) ( ( V_29 << V_8 [ V_28 ] . V_30 ) - V_11 ) ;
}
}
return 0 ;
}
T_1 F_4 ( T_2 * V_1 , V_31 V_33 )
{
void * V_34 = V_1 ;
T_6 * const V_17 = ( T_6 * ) V_34 ;
void * V_35 = V_1 + 1 ;
T_8 * const V_36 = ( T_8 * ) V_35 ;
V_17 -> V_4 = 0 ;
V_17 -> V_18 = 0 ;
V_36 -> V_32 = 0 ;
V_36 -> V_21 = V_33 ;
V_36 -> V_30 = 0 ;
return 0 ;
}
T_1 F_5 ( T_2 * V_1 , unsigned V_30 )
{
void * V_34 = V_1 ;
T_6 * const V_17 = ( T_6 * ) V_34 ;
void * V_35 = V_1 + 1 ;
T_8 * const V_37 = ( T_8 * ) V_35 ;
const unsigned V_11 = 1 << V_30 ;
const unsigned V_23 = V_11 - 1 ;
const unsigned V_10 = V_23 + 1 ;
unsigned V_20 ;
if ( V_30 < 1 )
return ERROR ( V_27 ) ;
V_17 -> V_4 = ( T_4 ) V_30 ;
V_17 -> V_18 = 1 ;
for ( V_20 = 0 ; V_20 < V_10 ; V_20 ++ ) {
V_37 [ V_20 ] . V_32 = 0 ;
V_37 [ V_20 ] . V_21 = ( V_31 ) V_20 ;
V_37 [ V_20 ] . V_30 = ( V_31 ) V_30 ;
}
return 0 ;
}
T_9 T_1 F_6 ( void * V_38 , T_1 V_39 , const void * V_40 , T_1 V_41 , const T_2 * V_1 ,
const unsigned V_42 )
{
V_31 * const V_43 = ( V_31 * ) V_38 ;
V_31 * V_44 = V_43 ;
V_31 * const V_45 = V_44 + V_39 ;
V_31 * const V_46 = V_45 - 3 ;
T_10 V_47 ;
T_11 V_48 ;
T_11 V_49 ;
F_7 ( F_8 ( & V_47 , V_40 , V_41 ) ) ;
F_9 ( & V_48 , & V_47 , V_1 ) ;
F_9 ( & V_49 , & V_47 , V_1 ) ;
#define F_10 ( T_12 ) fast ? FSE_decodeSymbolFast(statePtr, &bitD) : FSE_decodeSymbol(statePtr, &bitD)
for (; ( F_11 ( & V_47 ) == V_50 ) & ( V_44 < V_46 ) ; V_44 += 4 ) {
V_44 [ 0 ] = F_10 ( & V_48 ) ;
if ( V_16 * 2 + 7 > sizeof( V_47 . V_51 ) * 8 )
F_11 ( & V_47 ) ;
V_44 [ 1 ] = F_10 ( & V_49 ) ;
if ( V_16 * 4 + 7 > sizeof( V_47 . V_51 ) * 8 )
{
if ( F_11 ( & V_47 ) > V_50 ) {
V_44 += 2 ;
break;
}
}
V_44 [ 2 ] = F_10 ( & V_48 ) ;
if ( V_16 * 2 + 7 > sizeof( V_47 . V_51 ) * 8 )
F_11 ( & V_47 ) ;
V_44 [ 3 ] = F_10 ( & V_49 ) ;
}
while ( 1 ) {
if ( V_44 > ( V_45 - 2 ) )
return ERROR ( V_52 ) ;
* V_44 ++ = F_10 ( & V_48 ) ;
if ( F_11 ( & V_47 ) == V_53 ) {
* V_44 ++ = F_10 ( & V_49 ) ;
break;
}
if ( V_44 > ( V_45 - 2 ) )
return ERROR ( V_52 ) ;
* V_44 ++ = F_10 ( & V_49 ) ;
if ( F_11 ( & V_47 ) == V_53 ) {
* V_44 ++ = F_10 ( & V_48 ) ;
break;
}
}
return V_44 - V_43 ;
}
T_1 F_12 ( void * V_38 , T_1 V_54 , const void * V_40 , T_1 V_41 , const T_2 * V_1 )
{
const void * V_34 = V_1 ;
const T_6 * V_17 = ( const T_6 * ) V_34 ;
const T_5 V_18 = V_17 -> V_18 ;
if ( V_18 )
return F_6 ( V_38 , V_54 , V_40 , V_41 , V_1 , 1 ) ;
return F_6 ( V_38 , V_54 , V_40 , V_41 , V_1 , 0 ) ;
}
T_1 F_13 ( void * V_38 , T_1 V_55 , const void * V_40 , T_1 V_41 , unsigned V_56 , void * V_5 , T_1 V_6 )
{
const V_31 * const V_57 = ( const V_31 * ) V_40 ;
const V_31 * V_58 = V_57 ;
unsigned V_4 ;
unsigned V_3 = V_13 ;
T_1 V_59 ;
T_2 * V_1 ;
short * V_60 ;
T_1 V_61 = 0 ;
F_14 ( sizeof( T_2 ) == sizeof( T_5 ) ) ;
V_1 = ( T_2 * ) ( ( T_5 * ) V_5 + V_61 ) ;
V_61 += F_15 ( V_56 ) ;
V_60 = ( short * ) ( ( T_5 * ) V_5 + V_61 ) ;
V_61 += F_16 ( sizeof( short ) * ( V_13 + 1 ) , sizeof( T_5 ) ) >> 2 ;
if ( ( V_61 << 2 ) > V_6 )
return ERROR ( V_14 ) ;
V_5 = ( T_5 * ) V_5 + V_61 ;
V_6 -= ( V_61 << 2 ) ;
V_59 = F_17 ( V_60 , & V_3 , & V_4 , V_57 , V_41 ) ;
if ( F_18 ( V_59 ) )
return V_59 ;
if ( V_4 > V_56 )
return ERROR ( V_14 ) ;
V_58 += V_59 ;
V_41 -= V_59 ;
F_7 ( F_1 ( V_1 , V_60 , V_3 , V_4 , V_5 , V_6 ) ) ;
return F_12 ( V_38 , V_55 , V_58 , V_41 , V_1 ) ;
}
