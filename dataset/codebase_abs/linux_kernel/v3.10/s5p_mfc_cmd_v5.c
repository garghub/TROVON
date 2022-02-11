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
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 V_17 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
V_17 . V_12 [ 0 ] = V_2 -> V_18 ;
return F_1 ( V_2 , V_19 ,
& V_17 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 V_17 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
return F_1 ( V_2 , V_20 , & V_17 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 V_17 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
return F_1 ( V_2 , V_21 ,
& V_17 ) ;
}
static int F_10 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_4 V_17 ;
int V_24 ;
F_11 ( 2 , L_2 , V_23 -> V_25 ) ;
V_2 -> V_26 = V_23 -> V_27 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
switch ( V_23 -> V_25 ) {
case V_28 :
V_17 . V_12 [ 0 ] = V_29 ;
break;
case V_30 :
V_17 . V_12 [ 0 ] = V_31 ;
break;
case V_32 :
V_17 . V_12 [ 0 ] = V_33 ;
break;
case V_34 :
V_17 . V_12 [ 0 ] = V_35 ;
break;
case V_36 :
V_17 . V_12 [ 0 ] = V_37 ;
break;
case V_38 :
V_17 . V_12 [ 0 ] = V_39 ;
break;
case V_40 :
V_17 . V_12 [ 0 ] = V_41 ;
break;
case V_42 :
V_17 . V_12 [ 0 ] = V_43 ;
break;
case V_44 :
V_17 . V_12 [ 0 ] = V_45 ;
break;
default:
V_17 . V_12 [ 0 ] = V_46 ;
} ;
V_17 . V_12 [ 1 ] = 0 ;
V_17 . V_12 [ 2 ] = V_23 -> V_23 . V_47 ;
V_17 . V_12 [ 3 ] = V_23 -> V_23 . V_48 ;
V_24 = F_1 ( V_2 , V_49 ,
& V_17 ) ;
if ( V_24 ) {
F_4 ( L_3 ) ;
V_23 -> V_50 = V_51 ;
}
return V_24 ;
}
static int F_12 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_2 ;
struct V_4 V_17 ;
int V_24 ;
if ( V_23 -> V_50 == V_52 ) {
F_4 ( L_4 ) ;
V_23 -> V_50 = V_51 ;
return - V_53 ;
}
F_11 ( 2 , L_5 , V_23 -> V_54 ) ;
V_2 -> V_26 = V_23 -> V_27 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
V_17 . V_12 [ 0 ] = V_23 -> V_54 ;
V_24 = F_1 ( V_2 , V_55 ,
& V_17 ) ;
if ( V_24 ) {
F_4 ( L_6 ) ;
V_23 -> V_50 = V_51 ;
return - V_53 ;
}
return 0 ;
}
struct V_56 * F_13 ( void )
{
return & V_57 ;
}
