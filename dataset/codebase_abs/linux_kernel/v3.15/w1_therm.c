static int F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = F_2 ( 9 , V_4 ) ;
if ( ! V_2 -> V_3 )
return - V_5 ;
return 0 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
static inline int F_5 ( T_1 V_6 [ 9 ] )
{
T_2 V_7 = F_6 ( ( V_8 * ) V_6 ) ;
return V_7 * 1000 / 16 ;
}
static inline int F_7 ( T_1 V_6 [ 9 ] )
{
int V_7 , V_9 ;
if ( ! V_6 [ 7 ] )
return 0 ;
if ( V_6 [ 1 ] == 0 )
V_7 = ( ( V_10 ) V_6 [ 0 ] >> 1 ) * 1000 ;
else
V_7 = 1000 * ( - 1 * ( V_10 ) ( 0x100 - V_6 [ 0 ] ) >> 1 ) ;
V_7 -= 250 ;
V_9 = 1000 * ( ( V_10 ) V_6 [ 7 ] - ( V_10 ) V_6 [ 6 ] ) ;
V_9 /= ( V_10 ) V_6 [ 7 ] ;
V_7 += V_9 ;
return V_7 ;
}
static inline int F_8 ( T_1 V_6 [ 9 ] , T_1 V_11 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < F_9 ( V_13 ) ; ++ V_12 )
if ( V_13 [ V_12 ] . V_14 -> V_11 == V_11 )
return V_13 [ V_12 ] . F_10 ( V_6 ) ;
return 0 ;
}
static T_3 F_11 ( struct V_15 * V_15 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_1 * V_2 = F_12 ( V_15 ) ;
struct V_19 * V_20 = V_2 -> V_21 ;
T_1 V_6 [ 9 ] , V_22 , V_23 , V_24 ;
int V_12 , V_25 = 10 ;
T_3 V_26 = V_27 ;
V_12 = F_13 ( & V_20 -> V_28 ) ;
if ( V_12 != 0 )
return V_12 ;
memset ( V_6 , 0 , sizeof( V_6 ) ) ;
while ( V_25 -- ) {
V_23 = 0 ;
V_22 = 0 ;
if ( ! F_14 ( V_2 ) ) {
int V_29 = 0 ;
unsigned int V_30 = 750 ;
unsigned long V_31 ;
F_15 ( V_20 , V_32 ) ;
V_24 = F_16 ( V_20 ) ;
if ( F_14 ( V_2 ) )
continue;
if ( V_33 == 2 ||
( ! V_24 && V_33 ) )
F_17 ( V_20 , V_30 ) ;
F_15 ( V_20 , V_34 ) ;
if ( V_24 ) {
F_18 ( & V_20 -> V_28 ) ;
V_31 = F_19 ( V_30 ) ;
if ( V_31 != 0 )
return - V_35 ;
V_12 = F_13 ( & V_20 -> V_28 ) ;
if ( V_12 != 0 )
return V_12 ;
} else if ( ! V_33 ) {
V_31 = F_19 ( V_30 ) ;
if ( V_31 != 0 ) {
F_18 ( & V_20 -> V_28 ) ;
return - V_35 ;
}
}
if ( ! F_14 ( V_2 ) ) {
F_15 ( V_20 , V_36 ) ;
if ( ( V_29 = F_20 ( V_20 , V_6 , 9 ) ) != 9 ) {
F_21 ( V_15 , L_1
L_2 ,
V_29 ) ;
}
V_22 = F_22 ( V_6 , 8 ) ;
if ( V_6 [ 8 ] == V_22 )
V_23 = 1 ;
}
}
if ( V_23 )
break;
}
for ( V_12 = 0 ; V_12 < 9 ; ++ V_12 )
V_26 -= snprintf ( V_18 + V_27 - V_26 , V_26 , L_3 , V_6 [ V_12 ] ) ;
V_26 -= snprintf ( V_18 + V_27 - V_26 , V_26 , L_4 ,
V_22 , ( V_23 ) ? L_5 : L_6 ) ;
if ( V_23 )
memcpy ( V_2 -> V_3 , V_6 , sizeof( V_6 ) ) ;
else
F_21 ( V_15 , L_7 ) ;
for ( V_12 = 0 ; V_12 < 9 ; ++ V_12 )
V_26 -= snprintf ( V_18 + V_27 - V_26 , V_26 , L_3 ,
( ( T_1 * ) V_2 -> V_3 ) [ V_12 ] ) ;
V_26 -= snprintf ( V_18 + V_27 - V_26 , V_26 , L_8 ,
F_8 ( V_6 , V_2 -> V_37 -> V_11 ) ) ;
F_18 ( & V_20 -> V_28 ) ;
return V_27 - V_26 ;
}
static int T_4 F_23 ( void )
{
int V_38 , V_12 ;
for ( V_12 = 0 ; V_12 < F_9 ( V_13 ) ; ++ V_12 ) {
V_38 = F_24 ( V_13 [ V_12 ] . V_14 ) ;
if ( V_38 )
V_13 [ V_12 ] . V_39 = 1 ;
}
return 0 ;
}
static void T_5 F_25 ( void )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < F_9 ( V_13 ) ; ++ V_12 )
if ( ! V_13 [ V_12 ] . V_39 )
F_26 ( V_13 [ V_12 ] . V_14 ) ;
}
