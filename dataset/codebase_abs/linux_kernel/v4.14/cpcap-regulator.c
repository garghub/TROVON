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
static unsigned int F_7 ( unsigned int V_12 )
{
switch ( V_12 ) {
case V_13 :
return V_14 ;
case V_15 :
return V_16 ;
default:
return - V_17 ;
}
}
static unsigned int F_8 ( struct V_1 * V_2 )
{
int V_18 ;
F_9 ( V_2 -> V_9 , V_2 -> V_6 -> V_19 , & V_18 ) ;
if ( V_18 & V_15 )
return V_16 ;
return V_14 ;
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_12 )
{
int V_18 ;
switch ( V_12 ) {
case V_14 :
V_18 = V_13 ;
break;
case V_16 :
V_18 = V_15 ;
break;
default:
return - V_17 ;
}
return F_4 ( V_2 -> V_9 , V_2 -> V_6 -> V_19 ,
V_15 , V_18 ) ;
}
static int F_11 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
const struct V_24 * V_25 ;
struct V_26 V_27 ;
struct V_28 V_29 ;
int V_30 ;
V_25 = F_12 ( F_13 ( V_31 ) ,
& V_21 -> V_32 ) ;
if ( ! V_25 )
return - V_17 ;
if ( ! V_25 -> V_33 ) {
F_14 ( & V_21 -> V_32 , L_1 ) ;
return - V_34 ;
}
V_23 = F_15 ( & V_21 -> V_32 , sizeof( * V_23 ) , V_35 ) ;
if ( ! V_23 )
return - V_36 ;
V_23 -> V_37 = F_16 ( V_21 -> V_32 . V_38 , NULL ) ;
if ( ! V_23 -> V_37 )
return - V_34 ;
V_23 -> V_32 = & V_21 -> V_32 ;
V_23 -> V_39 = V_25 -> V_33 ;
F_17 ( V_21 , V_23 ) ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
V_27 . V_32 = & V_21 -> V_32 ;
V_27 . V_9 = V_23 -> V_37 ;
V_27 . V_29 = & V_29 ;
for ( V_30 = 0 ; V_30 < V_40 ; V_30 ++ ) {
const struct V_3 * V_4 = & V_23 -> V_39 [ V_30 ] ;
struct V_1 * V_2 ;
if ( ! V_4 -> V_41 . V_42 )
break;
if ( V_4 -> V_41 . V_43 == V_44 )
continue;
V_27 . V_45 = ( void * ) V_4 ;
V_2 = F_18 ( & V_21 -> V_32 ,
& V_4 -> V_41 ,
& V_27 ) ;
if ( F_19 ( V_2 ) ) {
F_14 ( & V_21 -> V_32 , L_2 ,
V_4 -> V_41 . V_42 ) ;
return F_20 ( V_2 ) ;
}
}
return 0 ;
}
