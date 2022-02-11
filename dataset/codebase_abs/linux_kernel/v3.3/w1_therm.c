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
T_1 V_5 [ 9 ] , V_21 , V_22 , V_23 ;
int V_11 , V_24 = 10 ;
T_3 V_25 = V_26 ;
V_11 = F_14 ( & V_3 -> V_27 ) ;
if ( V_11 != 0 )
return V_11 ;
memset ( V_5 , 0 , sizeof( V_5 ) ) ;
V_22 = 0 ;
V_21 = 0 ;
while ( V_24 -- ) {
if ( ! F_15 ( V_2 ) ) {
int V_28 = 0 ;
unsigned int V_29 = 750 ;
unsigned long V_30 ;
F_16 ( V_3 , V_31 ) ;
V_23 = F_17 ( V_3 ) ;
if ( F_15 ( V_2 ) )
continue;
if ( ! V_23 && V_32 )
F_18 ( V_3 , V_29 ) ;
F_16 ( V_3 , V_33 ) ;
if ( V_23 ) {
F_19 ( & V_3 -> V_27 ) ;
V_30 = F_20 ( V_29 ) ;
if ( V_30 != 0 )
return - V_34 ;
V_11 = F_14 ( & V_3 -> V_27 ) ;
if ( V_11 != 0 )
return V_11 ;
} else if ( ! V_32 ) {
V_30 = F_20 ( V_29 ) ;
if ( V_30 != 0 ) {
F_19 ( & V_3 -> V_27 ) ;
return - V_34 ;
}
}
if ( ! F_15 ( V_2 ) ) {
F_16 ( V_3 , V_35 ) ;
if ( ( V_28 = F_21 ( V_3 , V_5 , 9 ) ) != 9 ) {
F_22 ( V_15 , L_1
L_2 ,
V_28 ) ;
}
V_21 = F_23 ( V_5 , 8 ) ;
if ( V_5 [ 8 ] == V_21 )
V_22 = 1 ;
}
}
if ( ! F_11 ( V_5 ) )
break;
}
for ( V_11 = 0 ; V_11 < 9 ; ++ V_11 )
V_25 -= snprintf ( V_18 + V_26 - V_25 , V_25 , L_3 , V_5 [ V_11 ] ) ;
V_25 -= snprintf ( V_18 + V_26 - V_25 , V_25 , L_4 ,
V_21 , ( V_22 ) ? L_5 : L_6 ) ;
if ( V_22 )
memcpy ( V_2 -> V_5 , V_5 , sizeof( V_2 -> V_5 ) ) ;
else
F_22 ( V_15 , L_7 ) ;
for ( V_11 = 0 ; V_11 < 9 ; ++ V_11 )
V_25 -= snprintf ( V_18 + V_26 - V_25 , V_25 , L_3 , V_2 -> V_5 [ V_11 ] ) ;
V_25 -= snprintf ( V_18 + V_26 - V_25 , V_25 , L_8 ,
F_8 ( V_5 , V_2 -> V_36 -> V_10 ) ) ;
F_19 ( & V_3 -> V_27 ) ;
return V_26 - V_25 ;
}
static int T_4 F_24 ( void )
{
int V_37 , V_11 ;
for ( V_11 = 0 ; V_11 < F_9 ( V_12 ) ; ++ V_11 ) {
V_37 = F_25 ( V_12 [ V_11 ] . V_13 ) ;
if ( V_37 )
V_12 [ V_11 ] . V_38 = 1 ;
}
return 0 ;
}
static void T_5 F_26 ( void )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < F_9 ( V_12 ) ; ++ V_11 )
if ( ! V_12 [ V_11 ] . V_38 )
F_27 ( V_12 [ V_11 ] . V_13 ) ;
}
