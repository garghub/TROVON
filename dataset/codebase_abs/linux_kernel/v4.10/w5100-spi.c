static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
T_2 V_8 [ 3 ] = { V_9 , V_3 >> 8 , V_3 & 0xff } ;
T_2 V_10 ;
int V_11 ;
V_11 = F_3 ( V_5 , V_8 , sizeof( V_8 ) , & V_10 , 1 ) ;
return V_11 ? V_11 : V_10 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
T_2 V_8 [ 4 ] = { V_12 , V_3 >> 8 , V_3 & 0xff , V_10 } ;
return F_3 ( V_5 , V_8 , sizeof( V_8 ) , NULL , 0 ) ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
T_3 V_10 ;
int V_11 ;
V_11 = F_1 ( V_2 , V_3 ) ;
if ( V_11 < 0 )
return V_11 ;
V_10 = V_11 << 8 ;
V_11 = F_1 ( V_2 , V_3 + 1 ) ;
return V_11 < 0 ? V_11 : V_10 | V_11 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_10 )
{
int V_11 ;
V_11 = F_4 ( V_2 , V_3 , V_10 >> 8 ) ;
if ( V_11 )
return V_11 ;
return F_4 ( V_2 , V_3 + 1 , V_10 & 0xff ) ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_13 ,
int V_14 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ ) {
int V_11 = F_1 ( V_2 , V_3 + V_15 ) ;
if ( V_11 < 0 )
return V_11 ;
V_13 [ V_15 ] = V_11 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_3 , const T_2 * V_13 ,
int V_14 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_14 ; V_15 ++ ) {
int V_11 = F_4 ( V_2 , V_3 + V_15 , V_13 [ V_15 ] ) ;
if ( V_11 )
return V_11 ;
}
return 0 ;
}
static struct V_16 * V_16 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = V_16 ( V_2 ) ;
F_11 ( & V_17 -> V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
T_2 V_8 [ 4 ] = { V_3 >> 8 , V_3 & 0xff , 0 , 1 } ;
T_2 V_10 ;
int V_11 ;
V_11 = F_3 ( V_5 , V_8 , sizeof( V_8 ) , & V_10 , 1 ) ;
return V_11 ? V_11 : V_10 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
T_2 V_8 [ 5 ] = { V_3 >> 8 , V_3 & 0xff , V_19 , 1 , V_10 } ;
return F_3 ( V_5 , V_8 , sizeof( V_8 ) , NULL , 0 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
T_2 V_8 [ 4 ] = { V_3 >> 8 , V_3 & 0xff , 0 , 2 } ;
T_4 V_10 ;
int V_11 ;
V_11 = F_3 ( V_5 , V_8 , sizeof( V_8 ) , & V_10 , sizeof( V_10 ) ) ;
return V_11 ? V_11 : F_15 ( V_10 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
T_2 V_8 [ 6 ] = {
V_3 >> 8 , V_3 & 0xff ,
V_19 , 2 ,
V_10 >> 8 , V_10 & 0xff
} ;
return F_3 ( V_5 , V_8 , sizeof( V_8 ) , NULL , 0 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_13 ,
int V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
struct V_20 V_21 [] = {
{
. V_22 = V_17 -> V_23 ,
. V_14 = sizeof( V_17 -> V_23 ) ,
} ,
{
. V_24 = V_13 ,
. V_14 = V_14 ,
} ,
} ;
int V_11 ;
F_18 ( & V_17 -> V_18 ) ;
V_17 -> V_23 [ 0 ] = V_3 >> 8 ;
V_17 -> V_23 [ 1 ] = V_3 ;
V_17 -> V_23 [ 2 ] = V_14 >> 8 ;
V_17 -> V_23 [ 3 ] = V_14 ;
V_11 = F_19 ( V_5 , V_21 , F_20 ( V_21 ) ) ;
F_21 ( & V_17 -> V_18 ) ;
return V_11 ;
}
static int F_22 ( struct V_1 * V_2 , T_1 V_3 , const T_2 * V_13 ,
int V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_16 * V_17 = V_16 ( V_2 ) ;
struct V_20 V_21 [] = {
{
. V_22 = V_17 -> V_23 ,
. V_14 = sizeof( V_17 -> V_23 ) ,
} ,
{
. V_22 = V_13 ,
. V_14 = V_14 ,
} ,
} ;
int V_11 ;
F_18 ( & V_17 -> V_18 ) ;
V_17 -> V_23 [ 0 ] = V_3 >> 8 ;
V_17 -> V_23 [ 1 ] = V_3 ;
V_17 -> V_23 [ 2 ] = V_19 | ( V_14 >> 8 ) ;
V_17 -> V_23 [ 3 ] = V_14 ;
V_11 = F_19 ( V_5 , V_21 , F_20 ( V_21 ) ) ;
F_21 ( & V_17 -> V_18 ) ;
return V_11 ;
}
static struct V_25 * V_25 ( struct V_1 * V_2 )
{
return F_9 ( V_2 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_25 * V_17 = V_25 ( V_2 ) ;
F_11 ( & V_17 -> V_18 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
T_2 V_8 [ 3 ] = {
V_3 >> 8 ,
V_3 ,
F_25 (addr)
} ;
T_2 V_10 ;
int V_11 ;
V_11 = F_3 ( V_5 , V_8 , sizeof( V_8 ) , & V_10 , 1 ) ;
return V_11 ? V_11 : V_10 ;
}
static int F_26 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
T_2 V_8 [ 4 ] = {
V_3 >> 8 ,
V_3 ,
F_27 ( V_3 ) ,
V_10
} ;
return F_3 ( V_5 , V_8 , sizeof( V_8 ) , NULL , 0 ) ;
}
static int F_28 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
T_2 V_8 [ 3 ] = {
V_3 >> 8 ,
V_3 ,
F_25 (addr)
} ;
T_4 V_10 ;
int V_11 ;
V_11 = F_3 ( V_5 , V_8 , sizeof( V_8 ) , & V_10 , sizeof( V_10 ) ) ;
return V_11 ? V_11 : F_15 ( V_10 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_1 V_3 , T_3 V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
T_2 V_8 [ 5 ] = {
V_3 >> 8 ,
V_3 ,
F_27 ( V_3 ) ,
V_10 >> 8 ,
V_10
} ;
return F_3 ( V_5 , V_8 , sizeof( V_8 ) , NULL , 0 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_13 ,
int V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_25 * V_17 = V_25 ( V_2 ) ;
struct V_20 V_21 [] = {
{
. V_22 = V_17 -> V_23 ,
. V_14 = sizeof( V_17 -> V_23 ) ,
} ,
{
. V_24 = V_13 ,
. V_14 = V_14 ,
} ,
} ;
int V_11 ;
F_18 ( & V_17 -> V_18 ) ;
V_17 -> V_23 [ 0 ] = V_3 >> 8 ;
V_17 -> V_23 [ 1 ] = V_3 ;
V_17 -> V_23 [ 2 ] = F_25 ( V_3 ) ;
V_11 = F_19 ( V_5 , V_21 , F_20 ( V_21 ) ) ;
F_21 ( & V_17 -> V_18 ) ;
return V_11 ;
}
static int F_31 ( struct V_1 * V_2 , T_1 V_3 , const T_2 * V_13 ,
int V_14 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_25 * V_17 = V_25 ( V_2 ) ;
struct V_20 V_21 [] = {
{
. V_22 = V_17 -> V_23 ,
. V_14 = sizeof( V_17 -> V_23 ) ,
} ,
{
. V_22 = V_13 ,
. V_14 = V_14 ,
} ,
} ;
int V_11 ;
F_18 ( & V_17 -> V_18 ) ;
V_17 -> V_23 [ 0 ] = V_3 >> 8 ;
V_17 -> V_23 [ 1 ] = V_3 ;
V_17 -> V_23 [ 2 ] = F_27 ( V_3 ) ;
V_11 = F_19 ( V_5 , V_21 , F_20 ( V_21 ) ) ;
F_21 ( & V_17 -> V_18 ) ;
return V_11 ;
}
static int F_32 ( struct V_4 * V_5 )
{
const struct V_26 * V_27 = F_33 ( V_5 ) ;
const struct V_28 * V_29 ;
int V_30 ;
const void * V_31 = F_34 ( V_5 -> V_6 . V_32 ) ;
switch ( V_27 -> V_33 ) {
case V_34 :
V_29 = & V_35 ;
V_30 = 0 ;
break;
case V_36 :
V_29 = & V_37 ;
V_30 = sizeof( struct V_16 ) ;
break;
case V_38 :
V_29 = & V_39 ;
V_30 = sizeof( struct V_25 ) ;
break;
default:
return - V_40 ;
}
return F_35 ( & V_5 -> V_6 , V_29 , V_30 , V_31 , V_5 -> V_41 , - V_40 ) ;
}
static int F_36 ( struct V_4 * V_5 )
{
return F_37 ( & V_5 -> V_6 ) ;
}
