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
V_7 [ 1 ] = V_1 & 0x7f ;
V_7 [ 2 ] = 0 ;
if ( F_3 ( V_5 ) )
return - 1 ;
F_4 ( V_5 -> V_13 , V_7 , sizeof( V_7 ) ) ;
F_5 ( V_5 -> V_13 , V_6 , V_2 ) ;
if ( F_3 ( V_5 ) )
return - 1 ;
F_4 ( V_5 -> V_13 , V_7 , sizeof( V_7 ) ) ;
F_5 ( V_5 -> V_13 , V_8 , V_2 ) ;
if ( ! memcmp ( V_8 , V_6 , V_2 ) )
return 0 ;
} while ( -- V_10 );
F_6 ( & V_5 -> V_14 , L_1 ,
V_11 ) ;
return - 1 ;
}
static T_4 F_7 ( struct V_15 * V_16 , struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_6 , T_2 V_1 , T_1 V_2 )
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
if ( F_2 ( V_5 , V_1 , V_24 , V_6 ) < 0 ) {
V_2 = - V_25 ;
break;
}
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
T_3 V_7 [ 3 ] ;
T_3 V_29 [ V_30 ] ;
T_3 V_31 ;
if ( ( V_26 & 1 ) || ( V_27 != 2 ) ) {
F_6 ( & V_5 -> V_14 , L_2 ,
V_32 , V_26 , V_27 ) ;
return - 1 ;
}
V_33:
if ( F_3 ( V_5 ) )
return - 1 ;
V_7 [ 0 ] = V_34 ;
V_7 [ 1 ] = V_26 & 0xff ;
V_7 [ 2 ] = 0xff ;
F_4 ( V_5 -> V_13 , V_7 , sizeof( V_7 ) ) ;
F_4 ( V_5 -> V_13 , V_28 , V_27 ) ;
F_5 ( V_5 -> V_13 , V_29 , sizeof( V_29 ) ) ;
if ( ( V_29 [ 0 ] != V_28 [ 0 ] ) || ( V_29 [ 1 ] != V_28 [ 1 ] ) ) {
if ( -- V_10 )
goto V_33;
F_6 ( & V_5 -> V_14 ,
L_3 ,
V_11 ) ;
F_12 ( L_4 ,
V_32 , V_29 [ 0 ] , V_29 [ 1 ] , V_28 [ 0 ] , V_28 [ 1 ] ) ;
return - 1 ;
}
F_13 ( V_5 -> V_13 , V_35 ) ;
F_14 ( V_36 ) ;
V_31 = F_15 ( V_5 -> V_13 ) ;
if ( V_31 != V_37 ) {
F_6 ( & V_5 -> V_14 , L_5 , V_31 ) ;
return - 1 ;
}
return 0 ;
}
static T_4 F_16 ( struct V_15 * V_16 , struct V_17 * V_18 ,
struct V_19 * V_20 ,
char * V_6 , T_2 V_1 , T_1 V_2 )
{
struct V_4 * V_5 = F_8 ( V_18 ) ;
int V_26 , V_27 ;
int V_38 ;
V_2 = F_1 ( V_1 , V_2 , V_22 ) ;
if ( V_2 == 0 )
return 0 ;
F_9 ( & V_5 -> V_13 -> V_23 ) ;
V_26 = V_1 ;
V_27 = V_2 ;
while ( V_27 > 0 ) {
if ( V_27 < V_30 || V_26 & V_39 ) {
char V_40 [ V_30 ] ;
if ( F_2 ( V_5 , V_26 & ~ V_39 ,
V_30 , V_40 ) ) {
V_2 = - V_25 ;
goto V_41;
}
V_38 = V_30 -
( V_26 & V_39 ) ;
if ( V_38 > V_27 )
V_38 = V_27 ;
memcpy ( & V_40 [ V_26 & V_39 ] , V_6 , V_38 ) ;
if ( F_11 ( V_5 , V_26 & ~ V_39 ,
V_30 , V_40 ) < 0 ) {
V_2 = - V_25 ;
goto V_41;
}
} else {
V_38 = V_30 ;
if ( F_11 ( V_5 , V_26 , V_38 , V_6 ) < 0 ) {
V_2 = - V_25 ;
goto V_41;
}
}
V_6 += V_38 ;
V_26 += V_38 ;
V_27 -= V_38 ;
}
V_41:
F_10 ( & V_5 -> V_13 -> V_23 ) ;
return V_2 ;
}
static int F_17 ( struct V_4 * V_5 )
{
return F_18 ( & V_5 -> V_14 . V_18 , & V_42 ) ;
}
static void F_19 ( struct V_4 * V_5 )
{
F_20 ( & V_5 -> V_14 . V_18 , & V_42 ) ;
}
static int T_5 F_21 ( void )
{
F_12 ( L_6 , V_32 ) ;
return F_22 ( & V_43 ) ;
}
static void T_6 F_23 ( void )
{
F_12 ( L_6 , V_32 ) ;
F_24 ( & V_43 ) ;
}
