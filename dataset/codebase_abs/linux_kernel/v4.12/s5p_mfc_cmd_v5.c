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
V_17 . V_12 [ 0 ] = V_2 -> V_18 . V_19 ;
return F_1 ( V_2 , V_20 ,
& V_17 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 V_17 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
return F_1 ( V_2 , V_21 , & V_17 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 V_17 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
return F_1 ( V_2 , V_22 ,
& V_17 ) ;
}
static int F_10 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_4 V_17 ;
int V_25 ;
F_11 ( 2 , L_2 , V_24 -> V_26 ) ;
V_2 -> V_27 = V_24 -> V_28 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
switch ( V_24 -> V_26 ) {
case V_29 :
V_17 . V_12 [ 0 ] = V_30 ;
break;
case V_31 :
V_17 . V_12 [ 0 ] = V_32 ;
break;
case V_33 :
V_17 . V_12 [ 0 ] = V_34 ;
break;
case V_35 :
V_17 . V_12 [ 0 ] = V_36 ;
break;
case V_37 :
V_17 . V_12 [ 0 ] = V_38 ;
break;
case V_39 :
V_17 . V_12 [ 0 ] = V_40 ;
break;
case V_41 :
V_17 . V_12 [ 0 ] = V_42 ;
break;
case V_43 :
V_17 . V_12 [ 0 ] = V_44 ;
break;
case V_45 :
V_17 . V_12 [ 0 ] = V_46 ;
break;
default:
V_17 . V_12 [ 0 ] = V_47 ;
}
V_17 . V_12 [ 1 ] = 0 ;
V_17 . V_12 [ 2 ] = V_24 -> V_24 . V_48 ;
V_17 . V_12 [ 3 ] = V_24 -> V_24 . V_19 ;
V_25 = F_1 ( V_2 , V_49 ,
& V_17 ) ;
if ( V_25 ) {
F_4 ( L_3 ) ;
V_24 -> V_50 = V_51 ;
}
return V_25 ;
}
static int F_12 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_2 ;
struct V_4 V_17 ;
int V_25 ;
if ( V_24 -> V_50 == V_52 ) {
F_4 ( L_4 ) ;
V_24 -> V_50 = V_51 ;
return - V_53 ;
}
F_11 ( 2 , L_5 , V_24 -> V_54 ) ;
V_2 -> V_27 = V_24 -> V_28 ;
memset ( & V_17 , 0 , sizeof( struct V_4 ) ) ;
V_17 . V_12 [ 0 ] = V_24 -> V_54 ;
V_25 = F_1 ( V_2 , V_55 ,
& V_17 ) ;
if ( V_25 ) {
F_4 ( L_6 ) ;
V_24 -> V_50 = V_51 ;
return - V_53 ;
}
return 0 ;
}
struct V_56 * F_13 ( void )
{
return & V_57 ;
}
