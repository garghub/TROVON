static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_2 -> V_5 >= 0 )
F_3 ( V_2 -> V_5 , ( void * ) V_2 ) ;
if ( V_4 -> V_6 [ 0 ] )
F_4 ( V_4 -> V_7 ) ;
F_5 ( V_4 -> V_7 ) ;
F_6 ( V_2 ) ;
return 0 ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
return F_1 ( V_2 ) ;
}
static int F_8 ( struct V_11 * V_12 , struct V_13 * V_7 ,
struct V_14 * V_15 ,
struct V_3 * * V_16 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_17 , V_18 ;
static struct V_19 V_20 = {
. V_21 = F_7 ,
} ;
struct V_22 * V_23 ;
if ( ( V_18 = F_9 ( V_7 ) ) < 0 )
return V_18 ;
F_10 ( V_7 ) ;
V_23 = V_15 -> type == V_24 ? & V_25 : & V_26 ;
V_2 = F_11 ( V_12 , V_15 , V_23 ,
sizeof( struct V_3 ) - sizeof( struct V_1 ) ) ;
if ( ! V_2 ) {
F_5 ( V_7 ) ;
return - V_27 ;
}
V_4 = F_2 ( V_2 ) ;
V_4 -> V_7 = V_7 ;
if ( ( V_18 = F_12 ( V_7 , V_28 ) ) < 0 ) {
F_1 ( V_2 ) ;
return V_18 ;
}
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ )
V_4 -> V_6 [ V_17 ] = F_13 ( V_7 , V_17 + 1 ) ;
if ( F_14 ( V_7 -> V_5 , V_29 ,
V_30 , V_31 ,
V_32 , V_2 ) ) {
F_15 ( V_12 -> V_33 , L_1 , V_7 -> V_5 ) ;
F_1 ( V_2 ) ;
return - V_34 ;
}
V_2 -> V_5 = V_7 -> V_5 ;
if ( ( V_18 = F_16 ( V_12 , V_35 , V_2 , & V_20 ) ) < 0 ) {
F_1 ( V_2 ) ;
return V_18 ;
}
* V_16 = V_4 ;
return 0 ;
}
static int F_17 ( struct V_13 * V_7 ,
const struct V_36 * V_37 )
{
static int V_33 ;
struct V_11 * V_12 ;
struct V_14 * V_15 ;
struct V_3 * V_4 ;
int V_18 ;
if ( V_33 >= V_38 )
return - V_39 ;
if ( ! V_40 [ V_33 ] ) {
V_33 ++ ;
return - V_41 ;
}
V_18 = F_18 ( & V_7 -> V_33 , V_42 [ V_33 ] , V_43 [ V_33 ] , V_44 ,
0 , & V_12 ) ;
if ( V_18 < 0 )
return V_18 ;
switch ( ( int ) V_37 -> V_45 ) {
case V_46 :
V_15 = & V_47 ;
break;
case V_48 :
default:
if ( V_49 [ V_33 ] )
V_15 = & V_50 ;
else
V_15 = & V_51 ;
break;
}
if ( ( V_18 = F_8 ( V_12 , V_7 , V_15 , & V_4 ) ) < 0 ) {
F_19 ( V_12 ) ;
return V_18 ;
}
V_12 -> V_52 = V_4 ;
V_4 -> V_53 . V_54 . V_55 = V_54 [ V_33 ] ;
sprintf ( V_12 -> V_56 , L_2 ,
V_12 -> V_57 , V_4 -> V_6 [ 0 ] , V_4 -> V_6 [ 1 ] , V_4 -> V_53 . V_5 ) ;
F_20 ( V_12 -> V_33 , L_3 ,
V_12 -> V_57 , V_4 -> V_6 [ 0 ] , V_4 -> V_6 [ 1 ] , V_4 -> V_53 . V_5 ) ;
#ifdef F_21
V_4 -> V_53 . V_33 = & V_7 -> V_33 ;
#endif
if ( ( V_18 = F_22 ( & V_4 -> V_53 ) ) < 0 ) {
F_19 ( V_12 ) ;
return V_18 ;
}
if ( ( V_18 = F_23 ( V_12 ) ) < 0 ) {
F_19 ( V_12 ) ;
return V_18 ;
}
F_24 ( V_7 , V_12 ) ;
V_33 ++ ;
return 0 ;
}
static void F_25 ( struct V_13 * V_7 )
{
F_19 ( F_26 ( V_7 ) ) ;
}
static int F_27 ( struct V_9 * V_33 )
{
struct V_11 * V_12 = F_28 ( V_33 ) ;
struct V_3 * V_4 = V_12 -> V_52 ;
return F_29 ( & V_4 -> V_53 ) ;
}
static int F_30 ( struct V_9 * V_33 )
{
struct V_11 * V_12 = F_28 ( V_33 ) ;
struct V_3 * V_4 = V_12 -> V_52 ;
return F_31 ( & V_4 -> V_53 ) ;
}
