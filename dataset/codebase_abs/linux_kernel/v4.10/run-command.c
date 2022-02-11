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
char V_12 [ V_13 ] ;
V_6 = ! V_5 -> V_14 && V_5 -> V_15 < 0 ;
if ( V_6 ) {
if ( F_7 ( V_9 ) < 0 ) {
if ( V_5 -> V_16 > 0 )
F_2 ( V_5 -> V_16 ) ;
return - V_17 ;
}
V_5 -> V_15 = V_9 [ 1 ] ;
}
V_7 = ! V_5 -> V_18
&& ! V_5 -> V_19
&& V_5 -> V_16 < 0 ;
if ( V_7 ) {
if ( F_7 ( V_10 ) < 0 ) {
if ( V_6 )
F_1 ( V_9 ) ;
else if ( V_5 -> V_15 )
F_2 ( V_5 -> V_15 ) ;
return - V_17 ;
}
V_5 -> V_16 = V_10 [ 0 ] ;
}
V_8 = ! V_5 -> V_20 && V_5 -> V_21 < 0 ;
if ( V_8 ) {
if ( F_7 ( V_11 ) < 0 ) {
if ( V_6 )
F_1 ( V_9 ) ;
else if ( V_5 -> V_15 )
F_2 ( V_5 -> V_15 ) ;
if ( V_7 )
F_1 ( V_10 ) ;
else if ( V_5 -> V_16 )
F_2 ( V_5 -> V_16 ) ;
return - V_17 ;
}
V_5 -> V_21 = V_11 [ 0 ] ;
}
fflush ( NULL ) ;
V_5 -> V_22 = F_8 () ;
if ( ! V_5 -> V_22 ) {
if ( V_5 -> V_14 )
F_3 ( 0 ) ;
else if ( V_6 ) {
F_5 ( V_9 [ 0 ] , 0 ) ;
F_1 ( V_9 ) ;
} else if ( V_5 -> V_15 ) {
F_5 ( V_5 -> V_15 , 0 ) ;
F_2 ( V_5 -> V_15 ) ;
}
if ( V_5 -> V_20 )
F_3 ( 2 ) ;
else if ( V_8 ) {
F_5 ( V_11 [ 1 ] , 2 ) ;
F_1 ( V_11 ) ;
}
if ( V_5 -> V_18 )
F_3 ( 1 ) ;
else if ( V_5 -> V_19 )
F_5 ( 2 , 1 ) ;
else if ( V_7 ) {
F_5 ( V_10 [ 1 ] , 1 ) ;
F_1 ( V_10 ) ;
} else if ( V_5 -> V_16 > 1 ) {
F_5 ( V_5 -> V_16 , 1 ) ;
F_2 ( V_5 -> V_16 ) ;
}
if ( V_5 -> V_23 && F_9 ( V_5 -> V_23 ) )
F_10 ( L_2 , V_5 -> V_24 [ 0 ] ,
V_5 -> V_23 , F_11 ( V_25 , V_12 , sizeof( V_12 ) ) ) ;
if ( V_5 -> V_26 ) {
for (; * V_5 -> V_26 ; V_5 -> V_26 ++ ) {
if ( strchr ( * V_5 -> V_26 , '=' ) )
putenv ( ( char * ) * V_5 -> V_26 ) ;
else
F_12 ( * V_5 -> V_26 ) ;
}
}
if ( V_5 -> V_27 )
V_5 -> V_27 () ;
if ( V_5 -> V_28 ) {
F_13 ( V_5 -> V_24 ) ;
} else {
F_14 ( V_5 -> V_24 [ 0 ] , ( char * const * ) V_5 -> V_24 ) ;
}
exit ( 127 ) ;
}
if ( V_5 -> V_22 < 0 ) {
int V_21 = V_25 ;
if ( V_6 )
F_1 ( V_9 ) ;
else if ( V_5 -> V_15 )
F_2 ( V_5 -> V_15 ) ;
if ( V_7 )
F_1 ( V_10 ) ;
else if ( V_5 -> V_16 )
F_2 ( V_5 -> V_16 ) ;
if ( V_8 )
F_1 ( V_11 ) ;
return V_21 == V_29 ?
- V_30 :
- V_31 ;
}
if ( V_6 )
F_2 ( V_9 [ 0 ] ) ;
else if ( V_5 -> V_15 )
F_2 ( V_5 -> V_15 ) ;
if ( V_7 )
F_2 ( V_10 [ 1 ] ) ;
else if ( V_5 -> V_16 )
F_2 ( V_5 -> V_16 ) ;
if ( V_8 )
F_2 ( V_11 [ 1 ] ) ;
return 0 ;
}
static int F_15 ( T_1 V_22 )
{
char V_12 [ V_13 ] ;
for (; ; ) {
int V_32 , V_33 ;
T_1 V_34 = F_16 ( V_22 , & V_32 , 0 ) ;
if ( V_34 < 0 ) {
if ( V_25 == V_35 )
continue;
fprintf ( V_36 , L_3 ,
F_11 ( V_25 , V_12 , sizeof( V_12 ) ) ) ;
return - V_37 ;
}
if ( V_34 != V_22 )
return - V_38 ;
if ( F_17 ( V_32 ) )
return - V_39 ;
if ( ! F_18 ( V_32 ) )
return - V_40 ;
V_33 = F_19 ( V_32 ) ;
switch ( V_33 ) {
case 127 :
return - V_30 ;
case 0 :
return 0 ;
default:
return - V_33 ;
}
}
}
int F_20 ( struct V_4 * V_5 )
{
return F_15 ( V_5 -> V_22 ) ;
}
int F_21 ( struct V_4 * V_5 )
{
int V_33 = F_6 ( V_5 ) ;
if ( V_33 )
return V_33 ;
return F_20 ( V_5 ) ;
}
static void F_22 ( struct V_4 * V_5 ,
const char * * V_24 ,
int V_41 )
{
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
V_5 -> V_24 = V_24 ;
V_5 -> V_14 = V_41 & V_42 ? 1 : 0 ;
V_5 -> V_28 = V_41 & V_43 ? 1 : 0 ;
V_5 -> V_19 = V_41 & V_44 ? 1 : 0 ;
}
int F_23 ( const char * * V_24 , int V_41 )
{
struct V_4 V_5 ;
F_22 ( & V_5 , V_24 , V_41 ) ;
return F_21 ( & V_5 ) ;
}
