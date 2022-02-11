static inline T_1 F_1 ( T_2 V_1 , T_1 V_2 , T_1 V_3 )
{
if ( V_1 > V_3 )
return 0 ;
if ( ( V_1 + V_2 ) > V_3 )
return V_3 - V_1 ;
return V_2 ;
}
static int F_2 ( struct V_4 * V_5 , int V_1 , int V_2 , char * V_6 )
{
T_3 V_7 [ 3 ] ;
T_3 V_8 [ V_9 ] ;
int V_10 = V_11 ;
do {
V_7 [ 0 ] = V_12 ;
V_7 [ 1 ] = V_1 & 0xff ;
V_7 [ 2 ] = V_1 >> 8 ;
if ( F_3 ( V_5 ) )
return - 1 ;
F_4 ( V_5 -> V_13 , V_7 , 3 ) ;
F_5 ( V_5 -> V_13 , V_6 , V_2 ) ;
if ( F_3 ( V_5 ) )
return - 1 ;
F_4 ( V_5 -> V_13 , V_7 , 3 ) ;
F_5 ( V_5 -> V_13 , V_8 , V_2 ) ;
if ( ! memcmp ( V_8 , V_6 , V_2 ) )
return 0 ;
} while ( -- V_10 );
F_6 ( & V_5 -> V_14 , L_1 ,
V_11 ) ;
return - 1 ;
}
static T_4 F_7 ( struct V_15 * V_16 , struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_6 ,
T_2 V_1 , T_1 V_2 )
{
struct V_4 * V_5 = F_8 ( V_18 ) ;
int V_21 = V_2 ;
V_2 = F_1 ( V_1 , V_2 , V_22 ) ;
if ( V_2 == 0 )
return 0 ;
F_9 ( & V_5 -> V_13 -> V_23 ) ;
while ( V_21 > 0 ) {
int V_24 ;
if ( V_21 >= V_9 )
V_24 = V_9 ;
else
V_24 = V_21 ;
if ( F_2 ( V_5 , V_1 , V_24 , V_6 ) < 0 )
V_2 = - V_25 ;
V_21 -= V_9 ;
V_6 += V_9 ;
V_1 += V_9 ;
}
F_10 ( & V_5 -> V_13 -> V_23 ) ;
return V_2 ;
}
static int F_11 ( struct V_4 * V_5 , int V_26 , int V_27 , const T_3 * V_28 )
{
int V_10 = V_11 ;
T_3 V_7 [ 4 ] ;
T_3 V_29 [ V_30 + 3 ] ;
T_3 V_31 = ( V_26 + V_27 - 1 ) % V_30 ;
V_32:
if ( F_3 ( V_5 ) )
return - 1 ;
V_7 [ 0 ] = V_33 ;
V_7 [ 1 ] = V_26 & 0xff ;
V_7 [ 2 ] = V_26 >> 8 ;
F_4 ( V_5 -> V_13 , V_7 , 3 ) ;
F_4 ( V_5 -> V_13 , V_28 , V_27 ) ;
if ( F_3 ( V_5 ) )
return - 1 ;
F_12 ( V_5 -> V_13 , V_34 ) ;
F_5 ( V_5 -> V_13 , V_29 , V_27 + 3 ) ;
if ( ( V_29 [ 0 ] != V_7 [ 1 ] ) || ( V_29 [ 1 ] != V_7 [ 2 ] ) ||
( V_29 [ 2 ] != V_31 ) || ( memcmp ( V_28 , & V_29 [ 3 ] , V_27 ) != 0 ) ) {
if ( -- V_10 )
goto V_32;
F_6 ( & V_5 -> V_14 ,
L_2 ,
V_11 ) ;
return - 1 ;
}
if ( F_3 ( V_5 ) )
return - 1 ;
V_7 [ 0 ] = V_35 ;
V_7 [ 3 ] = V_31 ;
F_4 ( V_5 -> V_13 , V_7 , 4 ) ;
F_13 ( V_36 ) ;
F_14 ( V_5 -> V_13 ) ;
return 0 ;
}
static T_4 F_15 ( struct V_15 * V_16 , struct V_17 * V_18 ,
struct V_19 * V_20 , char * V_6 ,
T_2 V_1 , T_1 V_2 )
{
struct V_4 * V_5 = F_8 ( V_18 ) ;
int V_26 , V_27 ;
int V_37 ;
V_2 = F_1 ( V_1 , V_2 , V_22 ) ;
if ( V_2 == 0 )
return 0 ;
F_9 ( & V_5 -> V_13 -> V_23 ) ;
V_26 = V_1 ;
V_27 = V_2 ;
while ( V_27 > 0 ) {
if ( V_27 < V_30 || V_26 & V_38 ) {
char V_39 [ V_30 ] ;
if ( F_2 ( V_5 , V_26 & ~ V_38 ,
V_30 , V_39 ) ) {
V_2 = - V_25 ;
goto V_40;
}
V_37 = V_30 -
( V_26 & V_38 ) ;
if ( V_37 > V_27 )
V_37 = V_27 ;
memcpy ( & V_39 [ V_26 & V_38 ] , V_6 , V_37 ) ;
if ( F_11 ( V_5 , V_26 & ~ V_38 ,
V_30 , V_39 ) < 0 ) {
V_2 = - V_25 ;
goto V_40;
}
} else {
V_37 = V_30 ;
if ( F_11 ( V_5 , V_26 , V_37 , V_6 ) < 0 ) {
V_2 = - V_25 ;
goto V_40;
}
}
V_6 += V_37 ;
V_26 += V_37 ;
V_27 -= V_37 ;
}
V_40:
F_10 ( & V_5 -> V_13 -> V_23 ) ;
return V_2 ;
}
