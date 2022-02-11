static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
if ( V_2 -> V_5 >= 0 )
F_2 ( V_2 -> V_5 , ( void * ) V_2 ) ;
if ( V_4 -> V_6 [ 0 ] )
F_3 ( V_4 -> V_7 ) ;
F_4 ( V_4 -> V_7 ) ;
F_5 ( V_2 ) ;
return 0 ;
}
static int F_6 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_10 ;
return F_1 ( V_2 ) ;
}
static int F_7 ( struct V_11 * V_12 , struct V_13 * V_7 ,
struct V_14 * V_15 ,
struct V_3 * * V_16 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_17 , V_18 ;
static struct V_19 V_20 = {
. V_21 = F_6 ,
} ;
struct V_22 * V_23 ;
if ( ( V_18 = F_8 ( V_7 ) ) < 0 )
return V_18 ;
F_9 ( V_7 ) ;
V_23 = V_15 -> type == V_24 ? & V_25 : & V_26 ;
V_2 = F_10 ( V_12 , V_15 , V_23 ,
sizeof( struct V_3 ) - sizeof( struct V_1 ) ) ;
if ( ! V_2 ) {
F_4 ( V_7 ) ;
return - V_27 ;
}
V_4 = (struct V_3 * ) V_2 ;
V_4 -> V_7 = V_7 ;
if ( ( V_18 = F_11 ( V_7 , V_28 ) ) < 0 ) {
F_1 ( V_2 ) ;
return V_18 ;
}
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ )
V_4 -> V_6 [ V_17 ] = F_12 ( V_7 , V_17 + 1 ) ;
if ( F_13 ( V_7 -> V_5 , V_29 , V_30 ,
V_31 , V_2 ) ) {
F_14 ( V_12 -> V_32 , L_1 , V_7 -> V_5 ) ;
F_1 ( V_2 ) ;
return - V_33 ;
}
V_2 -> V_5 = V_7 -> V_5 ;
if ( ( V_18 = F_15 ( V_12 , V_34 , V_2 , & V_20 ) ) < 0 ) {
F_1 ( V_2 ) ;
return V_18 ;
}
* V_16 = V_4 ;
return 0 ;
}
static int F_16 ( struct V_13 * V_7 ,
const struct V_35 * V_36 )
{
static int V_32 ;
struct V_11 * V_12 ;
struct V_14 * V_15 ;
struct V_3 * V_4 ;
int V_18 ;
if ( V_32 >= V_37 )
return - V_38 ;
if ( ! V_39 [ V_32 ] ) {
V_32 ++ ;
return - V_40 ;
}
V_18 = F_17 ( & V_7 -> V_32 , V_41 [ V_32 ] , V_42 [ V_32 ] , V_43 ,
0 , & V_12 ) ;
if ( V_18 < 0 )
return V_18 ;
switch ( ( int ) V_36 -> V_44 ) {
case V_45 :
V_15 = & V_46 ;
break;
case V_47 :
default:
if ( V_48 [ V_32 ] )
V_15 = & V_49 ;
else
V_15 = & V_50 ;
break;
}
if ( ( V_18 = F_7 ( V_12 , V_7 , V_15 , & V_4 ) ) < 0 ) {
F_18 ( V_12 ) ;
return V_18 ;
}
V_12 -> V_51 = V_4 ;
V_4 -> V_52 . V_53 . V_54 = V_53 [ V_32 ] ;
sprintf ( V_12 -> V_55 , L_2 ,
V_12 -> V_56 , V_4 -> V_6 [ 0 ] , V_4 -> V_6 [ 1 ] , V_4 -> V_52 . V_5 ) ;
F_19 ( V_12 -> V_32 , L_3 ,
V_12 -> V_56 , V_4 -> V_6 [ 0 ] , V_4 -> V_6 [ 1 ] , V_4 -> V_52 . V_5 ) ;
#ifdef F_20
V_4 -> V_52 . V_32 = & V_7 -> V_32 ;
#endif
if ( ( V_18 = F_21 ( & V_4 -> V_52 ) ) < 0 ) {
F_18 ( V_12 ) ;
return V_18 ;
}
if ( ( V_18 = F_22 ( V_12 ) ) < 0 ) {
F_18 ( V_12 ) ;
return V_18 ;
}
F_23 ( V_7 , V_12 ) ;
V_32 ++ ;
return 0 ;
}
static void F_24 ( struct V_13 * V_7 )
{
F_18 ( F_25 ( V_7 ) ) ;
}
static int F_26 ( struct V_9 * V_32 )
{
struct V_13 * V_7 = F_27 ( V_32 ) ;
struct V_11 * V_12 = F_28 ( V_32 ) ;
struct V_3 * V_4 = V_12 -> V_51 ;
int V_18 ;
V_18 = F_29 ( & V_4 -> V_52 ) ;
F_4 ( V_7 ) ;
F_30 ( V_7 ) ;
F_31 ( V_7 , V_57 ) ;
return V_18 ;
}
static int F_32 ( struct V_9 * V_32 )
{
struct V_13 * V_7 = F_27 ( V_32 ) ;
struct V_11 * V_12 = F_28 ( V_32 ) ;
struct V_3 * V_4 = V_12 -> V_51 ;
F_31 ( V_7 , V_58 ) ;
F_33 ( V_7 ) ;
if ( F_8 ( V_7 ) < 0 ) {
F_14 ( V_32 , L_4 ) ;
F_34 ( V_12 ) ;
return - V_59 ;
}
F_9 ( V_7 ) ;
return F_35 ( & V_4 -> V_52 ) ;
}
