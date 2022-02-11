static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = ( V_3 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 1 ] = V_3 & 0xFF ;
V_9 -> V_11 [ 2 ] = V_4 ;
V_5 = F_5 ( V_9 -> V_12 , V_9 -> V_11 , 3 ) ;
F_6 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = ( V_3 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 1 ] = V_3 & 0xFF ;
V_9 -> V_11 [ 2 ] = ( V_4 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 3 ] = V_4 & 0xFF ;
V_5 = F_5 ( V_9 -> V_12 , V_9 -> V_11 , 4 ) ;
F_6 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_3 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = ( V_3 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 1 ] = V_3 & 0xFF ;
V_9 -> V_11 [ 2 ] = ( V_4 >> 16 ) & 0xFF ;
V_9 -> V_11 [ 3 ] = ( V_4 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 4 ] = V_4 & 0xFF ;
V_5 = F_5 ( V_9 -> V_12 , V_9 -> V_11 , 5 ) ;
F_6 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_9 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_3 V_4 )
{
int V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = ( V_3 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 1 ] = V_3 & 0xFF ;
V_9 -> V_11 [ 2 ] = ( V_4 >> 24 ) & 0xFF ;
V_9 -> V_11 [ 3 ] = ( V_4 >> 16 ) & 0xFF ;
V_9 -> V_11 [ 4 ] = ( V_4 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 5 ] = V_4 & 0xFF ;
V_5 = F_5 ( V_9 -> V_12 , V_9 -> V_11 , 6 ) ;
F_6 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_10 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_2 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = ( V_3 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 1 ] = V_3 & 0xFF ;
V_5 = F_5 ( V_9 -> V_12 , V_9 -> V_11 , 2 ) ;
if ( V_5 )
goto V_14;
V_5 = F_11 ( V_9 -> V_12 , V_9 -> V_15 , 1 ) ;
if ( V_5 )
goto V_14;
* V_13 = V_9 -> V_15 [ 0 ] ;
V_14:
F_6 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_1 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = ( V_3 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 1 ] = V_3 & 0xFF ;
V_5 = F_5 ( V_9 -> V_12 , V_9 -> V_11 , 2 ) ;
if ( V_5 )
goto V_14;
V_5 = F_11 ( V_9 -> V_12 , V_9 -> V_15 , 2 ) ;
if ( V_5 )
goto V_14;
* V_13 = ( V_9 -> V_15 [ 0 ] << 8 ) | V_9 -> V_15 [ 1 ] ;
V_14:
F_6 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_13 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_3 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = ( V_3 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 1 ] = V_3 & 0xFF ;
V_5 = F_5 ( V_9 -> V_12 , V_9 -> V_11 , 2 ) ;
if ( V_5 )
goto V_14;
V_5 = F_11 ( V_9 -> V_12 , V_9 -> V_15 , 3 ) ;
if ( V_5 )
goto V_14;
* V_13 = ( V_9 -> V_15 [ 0 ] << 16 ) | ( V_9 -> V_15 [ 1 ] << 8 ) | V_9 -> V_15 [ 2 ] ;
V_14:
F_6 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int F_14 ( struct V_1 * V_2 ,
T_1 V_3 ,
T_3 * V_13 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_5 ;
F_4 ( & V_9 -> V_10 ) ;
V_9 -> V_11 [ 0 ] = ( V_3 >> 8 ) & 0xFF ;
V_9 -> V_11 [ 1 ] = V_3 & 0xFF ;
V_5 = F_5 ( V_9 -> V_12 , V_9 -> V_11 , 2 ) ;
if ( V_5 )
goto V_14;
V_5 = F_11 ( V_9 -> V_12 , V_9 -> V_15 , 3 ) ;
if ( V_5 )
goto V_14;
* V_13 = ( V_9 -> V_15 [ 0 ] << 24 ) | ( V_9 -> V_15 [ 1 ] << 16 ) | ( V_9 -> V_15 [ 2 ] << 8 ) | V_9 -> V_15 [ 3 ] ;
V_14:
F_6 ( & V_9 -> V_10 ) ;
return V_5 ;
}
static int T_4 F_15 ( struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
int V_5 ;
struct V_8 * V_9 = F_16 ( sizeof *V_9 , V_20 ) ;
if ( ! V_9 ) {
V_5 = - V_21 ;
return V_5 ;
}
F_17 ( V_17 , V_9 ) ;
V_9 -> V_22 = F_10 ;
V_9 -> V_23 = F_12 ;
V_9 -> V_24 = F_13 ;
V_9 -> V_25 = F_14 ;
V_9 -> V_26 = F_1 ;
V_9 -> V_27 = F_7 ;
V_9 -> V_28 = F_8 ;
V_9 -> V_29 = F_9 ;
V_9 -> V_12 = V_17 ;
V_9 -> V_30 = V_17 -> V_30 ;
V_5 = F_18 ( V_9 , & V_17 -> V_2 ) ;
if ( V_5 ) {
F_19 ( V_9 ) ;
return V_5 ;
}
return V_5 ;
}
static int T_5 F_20 ( struct V_16 * V_17 )
{
return F_21 ( F_22 ( V_17 ) ) ;
}
static T_6 int F_23 ( void )
{
return F_24 ( & V_31 ) ;
}
static T_7 void F_25 ( void )
{
F_26 ( & V_31 ) ;
}
