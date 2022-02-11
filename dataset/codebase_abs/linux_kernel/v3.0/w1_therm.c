static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 , & V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_3 , & V_4 ) ;
}
static inline int F_5 ( T_1 V_5 [ 9 ] )
{
T_2 V_6 = F_6 ( ( V_7 * ) V_5 ) ;
return V_6 * 1000 / 16 ;
}
static inline int F_7 ( T_1 V_5 [ 9 ] )
{
int V_6 , V_8 ;
if ( ! V_5 [ 7 ] )
return 0 ;
if ( V_5 [ 1 ] == 0 )
V_6 = ( ( V_9 ) V_5 [ 0 ] >> 1 ) * 1000 ;
else
V_6 = 1000 * ( - 1 * ( V_9 ) ( 0x100 - V_5 [ 0 ] ) >> 1 ) ;
V_6 -= 250 ;
V_8 = 1000 * ( ( V_9 ) V_5 [ 7 ] - ( V_9 ) V_5 [ 6 ] ) ;
V_8 /= ( V_9 ) V_5 [ 7 ] ;
V_6 += V_8 ;
return V_6 ;
}
static inline int F_8 ( T_1 V_5 [ 9 ] , T_1 V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_9 ( V_12 ) ; ++ V_11 )
if ( V_12 [ V_11 ] . V_13 -> V_10 == V_10 )
return V_12 [ V_11 ] . F_10 ( V_5 ) ;
return 0 ;
}
static int F_11 ( T_1 V_5 [ 9 ] )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < sizeof( V_14 ) / 9 ; ++ V_11 )
if ( ! memcmp ( V_14 [ V_11 ] , V_5 , 9 ) )
return 1 ;
return 0 ;
}
static T_3 F_12 ( struct V_15 * V_15 ,
struct V_16 * V_17 , char * V_18 )
{
struct V_1 * V_2 = F_13 ( V_15 ) ;
struct V_19 * V_3 = V_2 -> V_20 ;
T_1 V_5 [ 9 ] , V_21 , V_22 ;
int V_11 , V_23 = 10 ;
T_3 V_24 = V_25 ;
F_14 ( & V_3 -> V_26 ) ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
V_22 = 0 ;
V_21 = 0 ;
while ( V_23 -- ) {
if ( ! F_15 ( V_2 ) ) {
int V_27 = 0 ;
unsigned int V_28 = 750 ;
if ( V_29 )
F_16 ( V_3 , V_28 ) ;
F_17 ( V_3 , V_30 ) ;
if ( ! V_29 )
F_18 ( V_28 ) ;
if ( ! F_15 ( V_2 ) ) {
F_17 ( V_3 , V_31 ) ;
if ( ( V_27 = F_19 ( V_3 , V_5 , 9 ) ) != 9 ) {
F_20 ( V_15 , L_1
L_2 ,
V_27 ) ;
}
V_21 = F_21 ( V_5 , 8 ) ;
if ( V_5 [ 8 ] == V_21 )
V_22 = 1 ;
}
}
if ( ! F_11 ( V_5 ) )
break;
}
for ( V_11 = 0 ; V_11 < 9 ; ++ V_11 )
V_24 -= snprintf ( V_18 + V_25 - V_24 , V_24 , L_3 , V_5 [ V_11 ] ) ;
V_24 -= snprintf ( V_18 + V_25 - V_24 , V_24 , L_4 ,
V_21 , ( V_22 ) ? L_5 : L_6 ) ;
if ( V_22 )
memcpy ( V_2 -> V_5 , V_5 , sizeof( V_2 -> V_5 ) ) ;
else
F_20 ( V_15 , L_7 ) ;
for ( V_11 = 0 ; V_11 < 9 ; ++ V_11 )
V_24 -= snprintf ( V_18 + V_25 - V_24 , V_24 , L_3 , V_2 -> V_5 [ V_11 ] ) ;
V_24 -= snprintf ( V_18 + V_25 - V_24 , V_24 , L_8 ,
F_8 ( V_5 , V_2 -> V_32 -> V_10 ) ) ;
F_22 ( & V_3 -> V_26 ) ;
return V_25 - V_24 ;
}
static int T_4 F_23 ( void )
{
int V_33 , V_11 ;
for ( V_11 = 0 ; V_11 < F_9 ( V_12 ) ; ++ V_11 ) {
V_33 = F_24 ( V_12 [ V_11 ] . V_13 ) ;
if ( V_33 )
V_12 [ V_11 ] . V_34 = 1 ;
}
return 0 ;
}
static void T_5 F_25 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_9 ( V_12 ) ; ++ V_11 )
if ( ! V_12 [ V_11 ] . V_34 )
F_26 ( V_12 [ V_11 ] . V_13 ) ;
}
