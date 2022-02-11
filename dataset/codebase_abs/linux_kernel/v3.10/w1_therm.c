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
static T_3 F_11 ( struct V_14 * V_14 ,
struct V_15 * V_16 , char * V_17 )
{
struct V_1 * V_2 = F_12 ( V_14 ) ;
struct V_18 * V_3 = V_2 -> V_19 ;
T_1 V_5 [ 9 ] , V_20 , V_21 , V_22 ;
int V_11 , V_23 = 10 ;
T_3 V_24 = V_25 ;
V_11 = F_13 ( & V_3 -> V_26 ) ;
if ( V_11 != 0 )
return V_11 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
while ( V_23 -- ) {
V_21 = 0 ;
V_20 = 0 ;
if ( ! F_14 ( V_2 ) ) {
int V_27 = 0 ;
unsigned int V_28 = 750 ;
unsigned long V_29 ;
F_15 ( V_3 , V_30 ) ;
V_22 = F_16 ( V_3 ) ;
if ( F_14 ( V_2 ) )
continue;
if ( V_31 == 2 ||
( ! V_22 && V_31 ) )
F_17 ( V_3 , V_28 ) ;
F_15 ( V_3 , V_32 ) ;
if ( V_22 ) {
F_18 ( & V_3 -> V_26 ) ;
V_29 = F_19 ( V_28 ) ;
if ( V_29 != 0 )
return - V_33 ;
V_11 = F_13 ( & V_3 -> V_26 ) ;
if ( V_11 != 0 )
return V_11 ;
} else if ( ! V_31 ) {
V_29 = F_19 ( V_28 ) ;
if ( V_29 != 0 ) {
F_18 ( & V_3 -> V_26 ) ;
return - V_33 ;
}
}
if ( ! F_14 ( V_2 ) ) {
F_15 ( V_3 , V_34 ) ;
if ( ( V_27 = F_20 ( V_3 , V_5 , 9 ) ) != 9 ) {
F_21 ( V_14 , L_1
L_2 ,
V_27 ) ;
}
V_20 = F_22 ( V_5 , 8 ) ;
if ( V_5 [ 8 ] == V_20 )
V_21 = 1 ;
}
}
if ( V_21 )
break;
}
for ( V_11 = 0 ; V_11 < 9 ; ++ V_11 )
V_24 -= snprintf ( V_17 + V_25 - V_24 , V_24 , L_3 , V_5 [ V_11 ] ) ;
V_24 -= snprintf ( V_17 + V_25 - V_24 , V_24 , L_4 ,
V_20 , ( V_21 ) ? L_5 : L_6 ) ;
if ( V_21 )
memcpy ( V_2 -> V_5 , V_5 , sizeof( V_2 -> V_5 ) ) ;
else
F_21 ( V_14 , L_7 ) ;
for ( V_11 = 0 ; V_11 < 9 ; ++ V_11 )
V_24 -= snprintf ( V_17 + V_25 - V_24 , V_24 , L_3 , V_2 -> V_5 [ V_11 ] ) ;
V_24 -= snprintf ( V_17 + V_25 - V_24 , V_24 , L_8 ,
F_8 ( V_5 , V_2 -> V_35 -> V_10 ) ) ;
F_18 ( & V_3 -> V_26 ) ;
return V_25 - V_24 ;
}
static int T_4 F_23 ( void )
{
int V_36 , V_11 ;
for ( V_11 = 0 ; V_11 < F_9 ( V_12 ) ; ++ V_11 ) {
V_36 = F_24 ( V_12 [ V_11 ] . V_13 ) ;
if ( V_36 )
V_12 [ V_11 ] . V_37 = 1 ;
}
return 0 ;
}
static void T_5 F_25 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_9 ( V_12 ) ; ++ V_11 )
if ( ! V_12 [ V_11 ] . V_37 )
F_26 ( V_12 [ V_11 ] . V_13 ) ;
}
