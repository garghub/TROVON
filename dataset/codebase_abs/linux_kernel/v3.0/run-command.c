static inline void F_1 ( int V_1 [ 2 ] )
{
F_2 ( V_1 [ 0 ] ) ;
F_2 ( V_1 [ 1 ] ) ;
}
static inline void F_3 ( int V_2 )
{
int V_1 = F_4 ( L_1 , V_3 ) ;
F_5 ( V_1 , V_2 ) ;
F_2 ( V_1 ) ;
}
int F_6 ( struct V_4 * V_5 )
{
int V_6 , V_7 , V_8 ;
int V_9 [ 2 ] , V_10 [ 2 ] , V_11 [ 2 ] ;
V_6 = ! V_5 -> V_12 && V_5 -> V_13 < 0 ;
if ( V_6 ) {
if ( F_7 ( V_9 ) < 0 ) {
if ( V_5 -> V_14 > 0 )
F_2 ( V_5 -> V_14 ) ;
return - V_15 ;
}
V_5 -> V_13 = V_9 [ 1 ] ;
}
V_7 = ! V_5 -> V_16
&& ! V_5 -> V_17
&& V_5 -> V_14 < 0 ;
if ( V_7 ) {
if ( F_7 ( V_10 ) < 0 ) {
if ( V_6 )
F_1 ( V_9 ) ;
else if ( V_5 -> V_13 )
F_2 ( V_5 -> V_13 ) ;
return - V_15 ;
}
V_5 -> V_14 = V_10 [ 0 ] ;
}
V_8 = ! V_5 -> V_18 && V_5 -> V_19 < 0 ;
if ( V_8 ) {
if ( F_7 ( V_11 ) < 0 ) {
if ( V_6 )
F_1 ( V_9 ) ;
else if ( V_5 -> V_13 )
F_2 ( V_5 -> V_13 ) ;
if ( V_7 )
F_1 ( V_10 ) ;
else if ( V_5 -> V_14 )
F_2 ( V_5 -> V_14 ) ;
return - V_15 ;
}
V_5 -> V_19 = V_11 [ 0 ] ;
}
fflush ( NULL ) ;
V_5 -> V_20 = F_8 () ;
if ( ! V_5 -> V_20 ) {
if ( V_5 -> V_12 )
F_3 ( 0 ) ;
else if ( V_6 ) {
F_5 ( V_9 [ 0 ] , 0 ) ;
F_1 ( V_9 ) ;
} else if ( V_5 -> V_13 ) {
F_5 ( V_5 -> V_13 , 0 ) ;
F_2 ( V_5 -> V_13 ) ;
}
if ( V_5 -> V_18 )
F_3 ( 2 ) ;
else if ( V_8 ) {
F_5 ( V_11 [ 1 ] , 2 ) ;
F_1 ( V_11 ) ;
}
if ( V_5 -> V_16 )
F_3 ( 1 ) ;
else if ( V_5 -> V_17 )
F_5 ( 2 , 1 ) ;
else if ( V_7 ) {
F_5 ( V_10 [ 1 ] , 1 ) ;
F_1 ( V_10 ) ;
} else if ( V_5 -> V_14 > 1 ) {
F_5 ( V_5 -> V_14 , 1 ) ;
F_2 ( V_5 -> V_14 ) ;
}
if ( V_5 -> V_21 && F_9 ( V_5 -> V_21 ) )
F_10 ( L_2 , V_5 -> V_22 [ 0 ] ,
V_5 -> V_21 , strerror ( V_23 ) ) ;
if ( V_5 -> V_24 ) {
for (; * V_5 -> V_24 ; V_5 -> V_24 ++ ) {
if ( strchr ( * V_5 -> V_24 , '=' ) )
putenv ( ( char * ) * V_5 -> V_24 ) ;
else
F_11 ( * V_5 -> V_24 ) ;
}
}
if ( V_5 -> V_25 )
V_5 -> V_25 () ;
if ( V_5 -> V_26 ) {
F_12 ( V_5 -> V_22 ) ;
} else {
F_13 ( V_5 -> V_22 [ 0 ] , ( char * const * ) V_5 -> V_22 ) ;
}
exit ( 127 ) ;
}
if ( V_5 -> V_20 < 0 ) {
int V_19 = V_23 ;
if ( V_6 )
F_1 ( V_9 ) ;
else if ( V_5 -> V_13 )
F_2 ( V_5 -> V_13 ) ;
if ( V_7 )
F_1 ( V_10 ) ;
else if ( V_5 -> V_14 )
F_2 ( V_5 -> V_14 ) ;
if ( V_8 )
F_1 ( V_11 ) ;
return V_19 == V_27 ?
- V_28 :
- V_29 ;
}
if ( V_6 )
F_2 ( V_9 [ 0 ] ) ;
else if ( V_5 -> V_13 )
F_2 ( V_5 -> V_13 ) ;
if ( V_7 )
F_2 ( V_10 [ 1 ] ) ;
else if ( V_5 -> V_14 )
F_2 ( V_5 -> V_14 ) ;
if ( V_8 )
F_2 ( V_11 [ 1 ] ) ;
return 0 ;
}
static int F_14 ( T_1 V_20 )
{
for (; ; ) {
int V_30 , V_31 ;
T_1 V_32 = F_15 ( V_20 , & V_30 , 0 ) ;
if ( V_32 < 0 ) {
if ( V_23 == V_33 )
continue;
error ( L_3 , strerror ( V_23 ) ) ;
return - V_34 ;
}
if ( V_32 != V_20 )
return - V_35 ;
if ( F_16 ( V_30 ) )
return - V_36 ;
if ( ! F_17 ( V_30 ) )
return - V_37 ;
V_31 = F_18 ( V_30 ) ;
switch ( V_31 ) {
case 127 :
return - V_28 ;
case 0 :
return 0 ;
default:
return - V_31 ;
}
}
}
int F_19 ( struct V_4 * V_5 )
{
return F_14 ( V_5 -> V_20 ) ;
}
int F_20 ( struct V_4 * V_5 )
{
int V_31 = F_6 ( V_5 ) ;
if ( V_31 )
return V_31 ;
return F_19 ( V_5 ) ;
}
static void F_21 ( struct V_4 * V_5 ,
const char * * V_22 ,
int V_38 )
{
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_22 = V_22 ;
V_5 -> V_12 = V_38 & V_39 ? 1 : 0 ;
V_5 -> V_26 = V_38 & V_40 ? 1 : 0 ;
V_5 -> V_17 = V_38 & V_41 ? 1 : 0 ;
}
int F_22 ( const char * * V_22 , int V_38 )
{
struct V_4 V_5 ;
F_21 ( & V_5 , V_22 , V_38 ) ;
return F_20 ( & V_5 ) ;
}
