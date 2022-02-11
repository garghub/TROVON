static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 ,
unsigned int V_5 )
{
T_1 V_6 [ 2 ] ;
V_6 [ 0 ] = V_7 | V_8 ;
V_6 [ 1 ] = V_3 ;
return F_2 ( V_2 , V_6 , 2 , V_4 , V_5 ) ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
T_1 V_10 ;
int V_11 ;
for ( V_9 = 0 ; V_9 < 10 ; V_9 ++ ) {
V_11 = F_1 ( V_2 , V_12 , & V_10 , 1 ) ;
if ( V_11 )
return V_11 ;
if ( ! ( V_10 & V_13 ) )
break;
F_4 ( 1 ) ;
}
if ( V_9 == 10 )
return - V_14 ;
return 0 ;
}
static inline int F_5 ( struct V_1 * V_2 , T_1 V_15 )
{
T_1 V_6 [ 3 ] ;
V_6 [ 0 ] = V_7 | V_16 ;
V_6 [ 1 ] = V_17 ;
V_6 [ 2 ] = V_15 ;
return F_6 ( V_2 , V_6 , sizeof( V_6 ) ) ;
}
static inline int F_7 ( struct V_1 * V_2 , T_1 V_15 )
{
int V_11 = F_3 ( V_2 ) ;
if ( V_11 )
return V_11 ;
return F_5 ( V_2 , V_15 ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_10 ;
int V_18 ;
int V_11 ;
V_11 = F_1 ( V_2 , V_3 , & V_10 , 1 ) ;
if ( V_11 )
return V_11 ;
for ( V_18 = 0 ; V_18 < 10 ; V_18 ++ ) {
V_11 = F_1 ( V_2 , V_12 , & V_10 , 1 ) ;
if ( V_11 )
return V_11 ;
if ( V_10 & V_19 )
break;
F_4 ( 1 ) ;
}
if ( V_18 == 10 )
return - V_14 ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 , T_1 V_15 , T_1 V_3 , T_1 * V_22 ,
unsigned int V_5 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
int V_11 ;
V_11 = F_7 ( V_2 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_8 ( V_2 , V_3 ) ;
if ( V_11 )
return V_11 ;
return F_1 ( V_2 , V_24 , V_22 , V_5 ) ;
}
static int F_10 ( struct V_20 * V_21 , T_1 V_15 , T_1 V_3 , T_1 * V_4 )
{
return F_9 ( V_21 , V_15 , V_3 , V_4 , 1 ) ;
}
static int F_11 ( struct V_20 * V_21 , T_1 V_15 , T_1 V_3 , T_2 * V_4 )
{
int V_11 = F_9 ( V_21 , V_15 , V_3 , ( T_1 * ) V_4 , 2 ) ;
if ( ! V_11 )
* V_4 = F_12 ( * V_4 ) ;
return V_11 ;
}
static int F_13 ( struct V_20 * V_21 , T_1 V_15 , T_1 V_3 , T_3 * V_4 )
{
int V_11 = F_9 ( V_21 , V_15 , V_3 , ( T_1 * ) V_4 , 4 ) ;
if ( ! V_11 )
* V_4 = F_14 ( * V_4 ) ;
return V_11 ;
}
static int F_15 ( struct V_20 * V_21 , T_1 V_15 , T_1 V_3 , T_4 * V_4 )
{
int V_11 ;
* V_4 = 0 ;
V_11 = F_9 ( V_21 , V_15 , V_3 , ( T_1 * ) V_4 , 6 ) ;
if ( ! V_11 )
* V_4 = F_16 ( * V_4 ) ;
return V_11 ;
}
static int F_17 ( struct V_20 * V_21 , T_1 V_15 , T_1 V_3 , T_4 * V_4 )
{
int V_11 = F_9 ( V_21 , V_15 , V_3 , ( T_1 * ) V_4 , 8 ) ;
if ( ! V_11 )
* V_4 = F_16 ( * V_4 ) ;
return V_11 ;
}
static int F_18 ( struct V_20 * V_21 , T_1 V_15 , T_1 V_3 , T_1 V_25 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
int V_11 ;
T_1 V_6 [ 3 ] ;
V_11 = F_7 ( V_2 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_6 [ 0 ] = V_7 | V_16 ;
V_6 [ 1 ] = V_3 ;
V_6 [ 2 ] = V_25 ;
return F_6 ( V_2 , V_6 , sizeof( V_6 ) ) ;
}
static int F_19 ( struct V_20 * V_21 , T_1 V_15 , T_1 V_3 , T_2 V_25 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
int V_11 ;
T_1 V_6 [ 4 ] ;
V_11 = F_7 ( V_2 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_6 [ 0 ] = V_7 | V_16 ;
V_6 [ 1 ] = V_3 ;
F_20 ( V_25 , & V_6 [ 2 ] ) ;
return F_6 ( V_2 , V_6 , sizeof( V_6 ) ) ;
}
static int F_21 ( struct V_20 * V_21 , T_1 V_15 , T_1 V_3 , T_3 V_25 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
int V_11 ;
T_1 V_6 [ 6 ] ;
V_11 = F_7 ( V_2 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_6 [ 0 ] = V_7 | V_16 ;
V_6 [ 1 ] = V_3 ;
F_22 ( V_25 , & V_6 [ 2 ] ) ;
return F_6 ( V_2 , V_6 , sizeof( V_6 ) ) ;
}
static int F_23 ( struct V_20 * V_21 , T_1 V_15 , T_1 V_3 , T_4 V_25 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
int V_11 ;
T_1 V_6 [ 10 ] ;
V_11 = F_7 ( V_2 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_6 [ 0 ] = V_7 | V_16 ;
V_6 [ 1 ] = V_3 ;
F_24 ( V_25 , & V_6 [ 2 ] ) ;
return F_6 ( V_2 , V_6 , sizeof( V_6 ) - 2 ) ;
}
static int F_25 ( struct V_20 * V_21 , T_1 V_15 , T_1 V_3 , T_4 V_25 )
{
struct V_1 * V_2 = V_21 -> V_23 ;
int V_11 ;
T_1 V_6 [ 10 ] ;
V_11 = F_7 ( V_2 , V_15 ) ;
if ( V_11 )
return V_11 ;
V_6 [ 0 ] = V_7 | V_16 ;
V_6 [ 1 ] = V_3 ;
F_24 ( V_25 , & V_6 [ 2 ] ) ;
return F_6 ( V_2 , V_6 , sizeof( V_6 ) ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
int V_11 ;
V_21 = F_27 ( & V_2 -> V_21 , & V_26 , V_2 ) ;
if ( ! V_21 )
return - V_27 ;
if ( V_2 -> V_21 . V_28 )
V_21 -> V_29 = V_2 -> V_21 . V_28 ;
V_11 = F_28 ( V_21 ) ;
if ( V_11 )
return V_11 ;
F_29 ( V_2 , V_21 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_31 ( V_2 ) ;
if ( V_21 )
F_32 ( V_21 ) ;
return 0 ;
}
