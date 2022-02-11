static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int error , V_5 ;
error = F_3 ( V_2 ) ;
if ( error )
return error ;
if ( V_2 -> V_6 -> V_7 & V_8 ) {
error = F_4 ( V_2 -> V_9 , V_4 -> V_10 ,
V_4 -> V_11 ,
V_4 -> V_11 ) ;
if ( error )
V_5 = F_5 ( V_2 ) ;
}
return error ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int error , V_5 ;
if ( V_2 -> V_6 -> V_7 & V_8 ) {
error = F_4 ( V_2 -> V_9 , V_4 -> V_10 ,
V_4 -> V_11 , 0 ) ;
if ( error )
return error ;
}
error = F_5 ( V_2 ) ;
if ( error && ( V_2 -> V_6 -> V_7 & V_8 ) ) {
V_5 = F_4 ( V_2 -> V_9 , V_4 -> V_10 ,
V_4 -> V_11 ,
V_4 -> V_11 ) ;
}
return error ;
}
static unsigned int F_7 ( struct V_1 * V_2 )
{
int V_12 ;
F_8 ( V_2 -> V_9 , V_2 -> V_6 -> V_13 , & V_12 ) ;
if ( ! ( V_12 & V_14 ) )
return V_15 ;
return V_16 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_17 )
{
int V_12 ;
switch ( V_17 ) {
case V_16 :
V_12 = V_14 ;
break;
case V_15 :
V_12 = 0 ;
break;
default:
return - V_18 ;
}
return F_4 ( V_2 -> V_9 , V_2 -> V_6 -> V_13 ,
V_14 , V_12 ) ;
}
static int F_10 ( struct V_19 * V_20 )
{
struct V_21 * V_22 ;
const struct V_23 * V_24 ;
struct V_25 V_26 ;
struct V_27 V_28 ;
int V_29 ;
V_24 = F_11 ( F_12 ( V_30 ) ,
& V_20 -> V_31 ) ;
if ( ! V_24 )
return - V_18 ;
if ( ! V_24 -> V_32 ) {
F_13 ( & V_20 -> V_31 , L_1 ) ;
return - V_33 ;
}
V_22 = F_14 ( & V_20 -> V_31 , sizeof( * V_22 ) , V_34 ) ;
if ( ! V_22 )
return - V_35 ;
V_22 -> V_36 = F_15 ( V_20 -> V_31 . V_37 , NULL ) ;
if ( ! V_22 -> V_36 )
return - V_33 ;
V_22 -> V_31 = & V_20 -> V_31 ;
V_22 -> V_38 = V_24 -> V_32 ;
F_16 ( V_20 , V_22 ) ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
V_26 . V_31 = & V_20 -> V_31 ;
V_26 . V_9 = V_22 -> V_36 ;
V_26 . V_28 = & V_28 ;
for ( V_29 = 0 ; V_29 < V_39 ; V_29 ++ ) {
const struct V_3 * V_4 = & V_22 -> V_38 [ V_29 ] ;
struct V_1 * V_2 ;
if ( ! V_4 -> V_40 . V_41 )
break;
if ( V_4 -> V_40 . V_42 == V_43 )
continue;
V_26 . V_44 = ( void * ) V_4 ;
V_2 = F_17 ( & V_20 -> V_31 ,
& V_4 -> V_40 ,
& V_26 ) ;
if ( F_18 ( V_2 ) ) {
F_13 ( & V_20 -> V_31 , L_2 ,
V_4 -> V_40 . V_41 ) ;
return F_19 ( V_2 ) ;
}
}
return 0 ;
}
