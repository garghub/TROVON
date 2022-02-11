static inline int F_1 ( T_1 V_1 [ 9 ] )
{
T_2 V_2 = F_2 ( ( V_3 * ) V_1 ) ;
return V_2 * 1000 / 16 ;
}
static inline int F_3 ( T_1 V_1 [ 9 ] )
{
int V_2 , V_4 ;
if ( ! V_1 [ 7 ] )
return 0 ;
if ( V_1 [ 1 ] == 0 )
V_2 = ( ( V_5 ) V_1 [ 0 ] >> 1 ) * 1000 ;
else
V_2 = 1000 * ( - 1 * ( V_5 ) ( 0x100 - V_1 [ 0 ] ) >> 1 ) ;
V_2 -= 250 ;
V_4 = 1000 * ( ( V_5 ) V_1 [ 7 ] - ( V_5 ) V_1 [ 6 ] ) ;
V_4 /= ( V_5 ) V_1 [ 7 ] ;
V_2 += V_4 ;
return V_2 ;
}
static inline int F_4 ( T_1 V_1 [ 9 ] , T_1 V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_5 ( V_8 ) ; ++ V_7 )
if ( V_8 [ V_7 ] . V_9 -> V_6 == V_6 )
return V_8 [ V_7 ] . F_6 ( V_1 ) ;
return 0 ;
}
static T_3 F_7 ( struct V_10 * V_10 ,
struct V_11 * V_12 , char * V_13 )
{
struct V_14 * V_15 = F_8 ( V_10 ) ;
struct V_16 * V_17 = V_15 -> V_18 ;
T_1 V_1 [ 9 ] , V_19 , V_20 , V_21 ;
int V_7 , V_22 = 10 ;
T_3 V_23 = V_24 ;
V_7 = F_9 ( & V_17 -> V_25 ) ;
if ( V_7 != 0 )
return V_7 ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
while ( V_22 -- ) {
V_20 = 0 ;
V_19 = 0 ;
if ( ! F_10 ( V_15 ) ) {
int V_26 = 0 ;
unsigned int V_27 = 750 ;
unsigned long V_28 ;
F_11 ( V_17 , V_29 ) ;
V_21 = F_12 ( V_17 ) ;
if ( F_10 ( V_15 ) )
continue;
if ( V_30 == 2 ||
( ! V_21 && V_30 ) )
F_13 ( V_17 , V_27 ) ;
F_11 ( V_17 , V_31 ) ;
if ( V_21 ) {
F_14 ( & V_17 -> V_25 ) ;
V_28 = F_15 ( V_27 ) ;
if ( V_28 != 0 )
return - V_32 ;
V_7 = F_9 ( & V_17 -> V_25 ) ;
if ( V_7 != 0 )
return V_7 ;
} else if ( ! V_30 ) {
V_28 = F_15 ( V_27 ) ;
if ( V_28 != 0 ) {
F_14 ( & V_17 -> V_25 ) ;
return - V_32 ;
}
}
if ( ! F_10 ( V_15 ) ) {
F_11 ( V_17 , V_33 ) ;
if ( ( V_26 = F_16 ( V_17 , V_1 , 9 ) ) != 9 ) {
F_17 ( V_10 , L_1
L_2 ,
V_26 ) ;
}
V_19 = F_18 ( V_1 , 8 ) ;
if ( V_1 [ 8 ] == V_19 )
V_20 = 1 ;
}
}
if ( V_20 )
break;
}
for ( V_7 = 0 ; V_7 < 9 ; ++ V_7 )
V_23 -= snprintf ( V_13 + V_24 - V_23 , V_23 , L_3 , V_1 [ V_7 ] ) ;
V_23 -= snprintf ( V_13 + V_24 - V_23 , V_23 , L_4 ,
V_19 , ( V_20 ) ? L_5 : L_6 ) ;
if ( V_20 )
memcpy ( V_15 -> V_1 , V_1 , sizeof( V_15 -> V_1 ) ) ;
else
F_17 ( V_10 , L_7 ) ;
for ( V_7 = 0 ; V_7 < 9 ; ++ V_7 )
V_23 -= snprintf ( V_13 + V_24 - V_23 , V_23 , L_3 , V_15 -> V_1 [ V_7 ] ) ;
V_23 -= snprintf ( V_13 + V_24 - V_23 , V_23 , L_8 ,
F_4 ( V_1 , V_15 -> V_34 -> V_6 ) ) ;
F_14 ( & V_17 -> V_25 ) ;
return V_24 - V_23 ;
}
static int T_4 F_19 ( void )
{
int V_35 , V_7 ;
for ( V_7 = 0 ; V_7 < F_5 ( V_8 ) ; ++ V_7 ) {
V_35 = F_20 ( V_8 [ V_7 ] . V_9 ) ;
if ( V_35 )
V_8 [ V_7 ] . V_36 = 1 ;
}
return 0 ;
}
static void T_5 F_21 ( void )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < F_5 ( V_8 ) ; ++ V_7 )
if ( ! V_8 [ V_7 ] . V_36 )
F_22 ( V_8 [ V_7 ] . V_9 ) ;
}
