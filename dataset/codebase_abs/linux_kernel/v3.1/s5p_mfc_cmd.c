static int F_1 ( struct V_1 * V_2 , int V_3 ,
struct V_4 * args )
{
int V_5 ;
unsigned long V_6 ;
V_6 = V_7 + F_2 ( V_8 ) ;
do {
if ( F_3 ( V_7 , V_6 ) ) {
F_4 ( L_1 ) ;
return - V_9 ;
}
V_5 = F_5 ( V_2 , V_10 ) ;
} while ( V_5 != V_11 );
F_6 ( V_2 , args -> V_12 [ 0 ] , V_13 ) ;
F_6 ( V_2 , args -> V_12 [ 1 ] , V_14 ) ;
F_6 ( V_2 , args -> V_12 [ 2 ] , V_15 ) ;
F_6 ( V_2 , args -> V_12 [ 3 ] , V_16 ) ;
F_6 ( V_2 , V_3 , V_10 ) ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 )
{
struct V_4 V_17 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
V_17 . V_12 [ 0 ] = V_2 -> V_18 ;
return F_1 ( V_2 , V_19 , & V_17 ) ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_4 V_17 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
return F_1 ( V_2 , V_20 , & V_17 ) ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_4 V_17 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
return F_1 ( V_2 , V_21 , & V_17 ) ;
}
int F_10 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_4 V_17 ;
int V_24 ;
F_11 ( 2 , L_2 , V_23 -> V_25 ) ;
V_2 -> V_26 = V_23 -> V_27 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
V_17 . V_12 [ 0 ] = V_23 -> V_25 ;
V_17 . V_12 [ 1 ] = 0 ;
V_17 . V_12 [ 2 ] = V_23 -> V_28 ;
V_17 . V_12 [ 3 ] = V_23 -> V_29 ;
V_24 = F_1 ( V_2 , V_30 ,
& V_17 ) ;
if ( V_24 ) {
F_4 ( L_3 ) ;
V_23 -> V_31 = V_32 ;
}
return V_24 ;
}
int F_12 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_4 V_17 ;
int V_24 ;
if ( V_23 -> V_31 == V_33 ) {
F_4 ( L_4 ) ;
V_23 -> V_31 = V_32 ;
return - V_34 ;
}
F_11 ( 2 , L_5 , V_23 -> V_35 ) ;
V_2 -> V_26 = V_23 -> V_27 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
V_17 . V_12 [ 0 ] = V_23 -> V_35 ;
V_24 = F_1 ( V_2 , V_36 ,
& V_17 ) ;
if ( V_24 ) {
F_4 ( L_6 ) ;
V_23 -> V_31 = V_32 ;
return - V_34 ;
}
return 0 ;
}
