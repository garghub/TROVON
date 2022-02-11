void F_1 ( int V_1 )
{
if ( V_1 >= 1000 ) {
F_2 ( ( V_1 + 999 ) / 1000 ) ;
} else {
F_3 ( V_1 ) ;
F_4 () ;
}
}
T_1 F_5 ( T_1 V_2 ,
struct V_3 * V_4 , struct V_5 * V_6 )
{
unsigned V_7 = F_6 ( V_4 ) ;
unsigned V_8 = F_7 ( V_6 ) ;
unsigned type = V_6 -> V_9 ;
T_1 V_10 ;
V_10 = ( V_2 * type ) * V_8 ;
if ( ( ( type * V_8 ) > V_7 ) && ( ( V_2 & 0xff ) == 0xaa ) )
V_10 |= ( type >> 1 ) * V_8 ;
return V_10 ;
}
T_2 F_8 ( T_3 V_11 , struct V_3 * V_4 , struct V_5 * V_6 )
{
T_2 V_12 = { { 0 } } ;
int V_13 , V_14 , V_15 , V_16 ;
unsigned long V_17 ;
int V_18 ;
if ( F_9 ( V_4 ) ) {
V_13 = sizeof( unsigned long ) ;
V_14 = ( F_6 ( V_4 ) ) / V_13 ;
} else {
V_13 = F_6 ( V_4 ) ;
V_14 = 1 ;
}
V_15 = F_6 ( V_4 ) / F_7 ( V_6 ) ;
V_16 = V_13 * F_7 ( V_6 ) / F_6 ( V_4 ) ;
switch ( V_15 ) {
default: F_10 () ;
case 1 :
V_17 = V_11 ;
break;
case 2 :
V_17 = F_11 ( V_4 , V_11 ) ;
break;
case 4 :
V_17 = F_12 ( V_4 , V_11 ) ;
break;
}
switch ( V_16 ) {
default: F_10 () ;
#if V_19 >= 64
case 8 :
V_17 |= ( V_17 << ( V_15 * 32 ) ) ;
#endif
case 4 :
V_17 |= ( V_17 << ( V_15 * 16 ) ) ;
case 2 :
V_17 |= ( V_17 << ( V_15 * 8 ) ) ;
case 1 :
;
}
for ( V_18 = 0 ; V_18 < V_14 ; V_18 ++ ) {
V_12 . V_20 [ V_18 ] = V_17 ;
}
return V_12 ;
}
unsigned long F_13 ( T_2 V_12 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_13 , V_14 , V_15 , V_16 ;
unsigned long V_21 , V_22 = 0 ;
int V_18 ;
if ( F_9 ( V_4 ) ) {
V_13 = sizeof( unsigned long ) ;
V_14 = ( F_6 ( V_4 ) ) / V_13 ;
} else {
V_13 = F_6 ( V_4 ) ;
V_14 = 1 ;
}
V_15 = F_6 ( V_4 ) / F_7 ( V_6 ) ;
V_16 = V_13 * F_7 ( V_6 ) / F_6 ( V_4 ) ;
V_21 = V_12 . V_20 [ 0 ] ;
for ( V_18 = 1 ; V_18 < V_14 ; V_18 ++ ) {
V_21 |= V_12 . V_20 [ V_18 ] ;
}
V_22 = V_21 ;
switch( V_16 ) {
default: F_10 () ;
#if V_19 >= 64
case 8 :
V_22 |= ( V_21 >> ( V_15 * 32 ) ) ;
#endif
case 4 :
V_22 |= ( V_21 >> ( V_15 * 16 ) ) ;
case 2 :
V_22 |= ( V_21 >> ( V_15 * 8 ) ) ;
case 1 :
;
}
switch ( V_15 ) {
case 1 :
break;
case 2 :
V_22 = F_14 ( V_4 , V_22 ) ;
break;
case 4 :
V_22 = F_15 ( V_4 , V_22 ) ;
break;
default: F_10 () ;
}
return V_22 ;
}
T_1 F_16 ( T_4 V_11 , T_1 V_23 , T_1 V_24 ,
struct V_3 * V_4 , struct V_5 * V_6 ,
int type , T_2 * V_25 )
{
T_2 V_12 ;
T_1 V_10 = V_24 + F_5 ( V_23 , V_4 , V_6 ) ;
V_12 = F_8 ( V_11 , V_4 , V_6 ) ;
if ( V_25 )
* V_25 = F_17 ( V_4 , V_10 ) ;
F_18 ( V_4 , V_12 , V_10 ) ;
return V_10 - V_24 ;
}
int T_5 F_19 ( struct V_3 * V_4 , T_6 V_24 ,
struct V_5 * V_6 )
{
int V_26 = V_6 -> V_8 * V_6 -> V_9 ;
T_2 V_12 [ 3 ] ;
T_2 V_27 [ 3 ] ;
V_27 [ 0 ] = F_8 ( 'Q' , V_4 , V_6 ) ;
V_27 [ 1 ] = F_8 ( 'R' , V_4 , V_6 ) ;
V_27 [ 2 ] = F_8 ( 'Y' , V_4 , V_6 ) ;
V_12 [ 0 ] = F_17 ( V_4 , V_24 + V_26 * 0x10 ) ;
V_12 [ 1 ] = F_17 ( V_4 , V_24 + V_26 * 0x11 ) ;
V_12 [ 2 ] = F_17 ( V_4 , V_24 + V_26 * 0x12 ) ;
if ( ! F_20 ( V_4 , V_27 [ 0 ] , V_12 [ 0 ] ) )
return 0 ;
if ( ! F_20 ( V_4 , V_27 [ 1 ] , V_12 [ 1 ] ) )
return 0 ;
if ( ! F_20 ( V_4 , V_27 [ 2 ] , V_12 [ 2 ] ) )
return 0 ;
return 1 ;
}
int T_5 F_21 ( T_1 V_24 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_16 ( 0xF0 , 0 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
F_16 ( 0x98 , 0x55 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
if ( F_19 ( V_4 , V_24 , V_6 ) )
return 1 ;
F_16 ( 0xF0 , 0 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
F_16 ( 0xFF , 0 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
F_16 ( 0x98 , 0x55 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
if ( F_19 ( V_4 , V_24 , V_6 ) )
return 1 ;
F_16 ( 0xF0 , 0 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
F_16 ( 0x98 , 0x555 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
if ( F_19 ( V_4 , V_24 , V_6 ) )
return 1 ;
F_16 ( 0xF0 , 0 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
F_16 ( 0xAA , 0x5555 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
F_16 ( 0x55 , 0x2AAA , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
F_16 ( 0x98 , 0x5555 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
if ( F_19 ( V_4 , V_24 , V_6 ) )
return 1 ;
F_16 ( 0xF0 , 0 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
F_16 ( 0xAA , 0x555 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
F_16 ( 0x55 , 0x2AA , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
F_16 ( 0x98 , 0x555 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
if ( F_19 ( V_4 , V_24 , V_6 ) )
return 1 ;
return 0 ;
}
void T_5 F_22 ( T_1 V_24 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_16 ( 0xF0 , 0 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
F_16 ( 0xFF , 0 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
if ( ( V_6 -> V_28 == V_29 ) && ( V_6 -> V_30 == 0x227E || V_6 -> V_30 == 0x7E ) )
F_16 ( 0xF0 , 0 , V_24 , V_4 , V_6 , V_6 -> V_9 , NULL ) ;
}
struct V_31 *
T_5 F_23 ( struct V_3 * V_4 , T_7 V_32 , T_7 V_33 , const char * V_34 )
{
struct V_5 * V_6 = V_4 -> V_35 ;
T_6 V_24 = 0 ;
int V_36 = V_6 -> V_8 * V_6 -> V_9 ;
int V_18 ;
struct V_31 * V_37 = NULL ;
if ( ! V_32 )
goto V_38;
F_24 ( V_39 L_1 , V_34 , V_32 ) ;
V_37 = F_25 ( V_33 , V_40 ) ;
if ( ! V_37 )
goto V_38;
#ifdef F_26
F_27 () ;
#endif
F_21 ( V_24 , V_4 , V_6 ) ;
for ( V_18 = 0 ; V_18 < V_33 ; V_18 ++ ) {
( ( unsigned char * ) V_37 ) [ V_18 ] =
F_28 ( V_4 , V_24 + ( ( V_32 + V_18 ) * V_36 ) ) ;
}
F_22 ( V_24 , V_4 , V_6 ) ;
#ifdef F_26
( void ) F_17 ( V_4 , V_24 ) ;
F_29 () ;
F_30 () ;
#endif
V_38: return V_37 ;
}
void F_31 ( struct V_41 * V_42 , struct F_31 * V_43 )
{
struct V_3 * V_4 = V_42 -> V_44 ;
struct V_5 * V_6 = V_4 -> V_35 ;
struct F_31 * V_45 ;
for ( V_45 = V_43 ; V_45 -> V_46 ; V_45 ++ ) {
if ( ( ( V_45 -> V_28 == V_47 ) || ( V_45 -> V_28 == V_6 -> V_28 ) ) &&
( ( V_45 -> V_30 == V_48 ) || ( V_45 -> V_30 == V_6 -> V_30 ) ) ) {
V_45 -> V_46 ( V_42 ) ;
}
}
}
int F_32 ( struct V_41 * V_42 , T_8 V_49 ,
T_9 V_50 , T_10 V_51 , void * V_52 )
{
struct V_3 * V_4 = V_42 -> V_44 ;
struct V_5 * V_6 = V_4 -> V_35 ;
unsigned long V_32 ;
int V_53 , V_54 = 0 ;
int V_18 , V_55 ;
struct V_56 * V_57 = V_42 -> V_58 ;
V_18 = 0 ;
while ( V_18 < V_42 -> V_59 && V_50 >= V_57 [ V_18 ] . V_60 )
V_18 ++ ;
V_18 -- ;
if ( V_50 & ( V_57 [ V_18 ] . V_61 - 1 ) )
return - V_62 ;
V_55 = V_18 ;
while ( V_18 < V_42 -> V_59 && ( V_50 + V_51 ) >= V_57 [ V_18 ] . V_60 )
V_18 ++ ;
V_18 -- ;
if ( ( V_50 + V_51 ) & ( V_57 [ V_18 ] . V_61 - 1 ) )
return - V_62 ;
V_53 = V_50 >> V_6 -> V_63 ;
V_32 = V_50 - ( V_53 << V_6 -> V_63 ) ;
V_18 = V_55 ;
while( V_51 ) {
int V_33 = V_57 [ V_18 ] . V_61 ;
V_54 = (* V_49)( V_4 , & V_6 -> V_64 [ V_53 ] , V_32 , V_33 , V_52 ) ;
if ( V_54 )
return V_54 ;
V_32 += V_33 ;
V_50 += V_33 ;
V_51 -= V_33 ;
if ( V_50 == V_57 [ V_18 ] . V_60 + V_33 * V_57 [ V_18 ] . V_65 )
V_18 ++ ;
if ( V_32 >> V_6 -> V_63 ) {
V_32 = 0 ;
V_53 ++ ;
if ( V_53 >= V_6 -> V_66 )
break;
}
}
return 0 ;
}
