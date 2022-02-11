static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , unsigned int V_4 )
{
unsigned long V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
unsigned int V_8 = F_4 ( V_2 ) ;
T_2 * V_9 = F_5 ( ( void * ) V_7 -> V_7 ,
( V_5 | ( F_6 ( T_2 ) - 1 ) ) + 1 ) ;
T_3 V_10 [ 2 ] ;
int V_11 , V_12 = 0 ;
T_1 V_13 , V_14 ;
V_12 = F_7 ( V_7 -> V_15 , V_3 , V_4 ) ;
if ( V_12 )
return V_12 ;
memset ( V_9 , 0 , V_8 ) ;
F_8 ( V_7 -> V_15 , ( T_1 * ) V_9 , ( T_1 * ) V_9 ) ;
switch ( V_8 ) {
case 16 :
V_14 = 0x87 ;
V_10 [ 0 ] = F_9 ( V_9 [ 1 ] ) ;
V_10 [ 1 ] = F_9 ( V_9 [ 0 ] ) ;
for ( V_11 = 0 ; V_11 < 4 ; V_11 += 2 ) {
V_13 = ( ( V_16 ) V_10 [ 1 ] >> 63 ) & V_14 ;
V_10 [ 1 ] = ( V_10 [ 1 ] << 1 ) | ( V_10 [ 0 ] >> 63 ) ;
V_10 [ 0 ] = ( V_10 [ 0 ] << 1 ) ^ V_13 ;
V_9 [ V_11 + 0 ] = F_10 ( V_10 [ 1 ] ) ;
V_9 [ V_11 + 1 ] = F_10 ( V_10 [ 0 ] ) ;
}
break;
case 8 :
V_14 = 0x1B ;
V_10 [ 0 ] = F_9 ( V_9 [ 0 ] ) ;
for ( V_11 = 0 ; V_11 < 2 ; V_11 ++ ) {
V_13 = ( ( V_16 ) V_10 [ 0 ] >> 63 ) & V_14 ;
V_10 [ 0 ] = ( V_10 [ 0 ] << 1 ) ^ V_13 ;
V_9 [ V_11 ] = F_10 ( V_10 [ 0 ] ) ;
}
break;
}
return 0 ;
}
static int F_11 ( struct V_17 * V_18 )
{
unsigned long V_5 = F_2 ( V_18 -> V_19 ) ;
struct V_20 * V_7 = F_12 ( V_18 ) ;
int V_8 = F_4 ( V_18 -> V_19 ) ;
T_1 * V_21 = F_5 ( ( void * ) V_7 -> V_7 , V_5 + 1 ) + V_8 ;
V_7 -> V_22 = 0 ;
memset ( V_21 , 0 , V_8 ) ;
return 0 ;
}
static int F_13 ( struct V_17 * V_18 , const T_1 * V_23 ,
unsigned int V_22 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
unsigned long V_5 = F_2 ( V_2 ) ;
struct V_6 * V_24 = F_3 ( V_2 ) ;
struct V_20 * V_7 = F_12 ( V_18 ) ;
struct V_25 * V_19 = V_24 -> V_15 ;
int V_8 = F_4 ( V_2 ) ;
T_1 * V_26 = F_5 ( ( void * ) V_7 -> V_7 , V_5 + 1 ) ;
T_1 * V_21 = V_26 + V_8 ;
if ( ( V_7 -> V_22 + V_22 ) <= V_8 ) {
memcpy ( V_26 + V_7 -> V_22 , V_23 , V_22 ) ;
V_7 -> V_22 += V_22 ;
return 0 ;
}
memcpy ( V_26 + V_7 -> V_22 , V_23 , V_8 - V_7 -> V_22 ) ;
V_22 -= V_8 - V_7 -> V_22 ;
V_23 += V_8 - V_7 -> V_22 ;
F_14 ( V_21 , V_26 , V_8 ) ;
F_8 ( V_19 , V_21 , V_21 ) ;
V_7 -> V_22 = 0 ;
while ( V_22 > V_8 ) {
F_14 ( V_21 , V_23 , V_8 ) ;
F_8 ( V_19 , V_21 , V_21 ) ;
V_23 += V_8 ;
V_22 -= V_8 ;
}
if ( V_22 ) {
memcpy ( V_26 , V_23 , V_22 ) ;
V_7 -> V_22 = V_22 ;
}
return 0 ;
}
static int F_15 ( struct V_17 * V_18 , T_1 * V_27 )
{
struct V_1 * V_2 = V_18 -> V_19 ;
unsigned long V_5 = F_2 ( V_2 ) ;
struct V_6 * V_24 = F_3 ( V_2 ) ;
struct V_20 * V_7 = F_12 ( V_18 ) ;
struct V_25 * V_19 = V_24 -> V_15 ;
int V_8 = F_4 ( V_2 ) ;
T_1 * V_9 = F_5 ( ( void * ) V_24 -> V_7 ,
( V_5 | ( F_6 ( T_2 ) - 1 ) ) + 1 ) ;
T_1 * V_26 = F_5 ( ( void * ) V_7 -> V_7 , V_5 + 1 ) ;
T_1 * V_21 = V_26 + V_8 ;
unsigned int V_28 = 0 ;
if ( V_7 -> V_22 != V_8 ) {
unsigned int V_29 ;
T_1 * V_23 = V_26 + V_7 -> V_22 ;
* V_23 = 0x80 ;
V_23 ++ ;
V_29 = V_8 - V_7 -> V_22 - 1 ;
if ( V_29 )
memset ( V_23 , 0 , V_29 ) ;
V_28 += V_8 ;
}
F_14 ( V_21 , V_26 , V_8 ) ;
F_14 ( V_21 , V_9 + V_28 , V_8 ) ;
F_8 ( V_19 , V_27 , V_21 ) ;
return 0 ;
}
static int F_16 ( struct V_30 * V_19 )
{
struct V_25 * V_31 ;
struct V_32 * V_33 = ( void * ) V_19 -> V_34 ;
struct V_35 * V_36 = F_17 ( V_33 ) ;
struct V_6 * V_7 = F_18 ( V_19 ) ;
V_31 = F_19 ( V_36 ) ;
if ( F_20 ( V_31 ) )
return F_21 ( V_31 ) ;
V_7 -> V_15 = V_31 ;
return 0 ;
}
static void F_22 ( struct V_30 * V_19 )
{
struct V_6 * V_7 = F_18 ( V_19 ) ;
F_23 ( V_7 -> V_15 ) ;
}
static int F_24 ( struct V_37 * V_38 , struct V_39 * * V_40 )
{
struct V_41 * V_33 ;
struct V_42 * V_43 ;
unsigned long V_5 ;
int V_12 ;
V_12 = F_25 ( V_40 , V_44 ) ;
if ( V_12 )
return V_12 ;
V_43 = F_26 ( V_40 , V_45 ,
V_46 ) ;
if ( F_20 ( V_43 ) )
return F_21 ( V_43 ) ;
switch ( V_43 -> V_47 ) {
case 16 :
case 8 :
break;
default:
V_12 = - V_48 ;
goto V_49;
}
V_33 = F_27 ( L_1 , V_43 ) ;
V_12 = F_21 ( V_33 ) ;
if ( F_20 ( V_33 ) )
goto V_49;
V_12 = F_28 ( F_29 ( V_33 ) , V_43 ,
F_30 ( V_33 ) ,
V_46 ) ;
if ( V_12 )
goto V_50;
V_5 = V_43 -> V_51 | ( F_6 ( V_52 ) - 1 ) ;
V_33 -> V_43 . V_53 . V_51 = V_5 ;
V_33 -> V_43 . V_53 . V_54 = V_43 -> V_54 ;
V_33 -> V_43 . V_53 . V_47 = V_43 -> V_47 ;
V_33 -> V_43 . V_55 = V_43 -> V_47 ;
V_33 -> V_43 . V_56 =
F_31 ( sizeof( struct V_20 ) , F_32 () )
+ ( V_5 & ~ ( F_32 () - 1 ) )
+ V_43 -> V_47 * 2 ;
V_33 -> V_43 . V_53 . V_57 =
F_31 ( sizeof( struct V_6 ) , F_32 () )
+ ( ( V_5 | ( F_6 ( T_2 ) - 1 ) ) &
~ ( F_32 () - 1 ) )
+ V_43 -> V_47 * 2 ;
V_33 -> V_43 . V_53 . V_58 = F_16 ;
V_33 -> V_43 . V_53 . V_59 = F_22 ;
V_33 -> V_43 . V_60 = F_11 ;
V_33 -> V_43 . V_61 = F_13 ;
V_33 -> V_43 . V_62 = F_15 ;
V_33 -> V_43 . V_63 = F_1 ;
V_12 = F_33 ( V_38 , V_33 ) ;
if ( V_12 ) {
V_50:
F_34 ( F_30 ( V_33 ) ) ;
}
V_49:
F_35 ( V_43 ) ;
return V_12 ;
}
static int T_4 F_36 ( void )
{
return F_37 ( & V_64 ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( & V_64 ) ;
}
