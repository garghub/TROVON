static int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_5 * V_6 ,
unsigned long type )
{
int V_7 , V_8 , V_9 ;
struct V_3 * V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_10 = F_2 ( V_2 -> V_4 , L_1 ) ;
if ( ! V_10 ) {
F_3 ( V_2 , L_2 ) ;
return - V_15 ;
}
switch ( type ) {
case V_16 :
V_14 = V_17 ;
V_9 = F_4 ( V_17 ) ;
break;
case V_18 :
V_14 = V_19 ;
V_9 = F_4 ( V_19 ) ;
break;
default:
F_3 ( V_2 , L_3 , type ) ;
return - V_15 ;
}
V_7 = V_13 ( V_2 , V_10 , V_14 , V_9 ) ;
F_5 ( V_10 ) ;
if ( V_7 <= 0 )
return V_7 ;
V_6 -> V_20 = F_6 ( V_2 ,
sizeof( struct V_11 ) *
V_9 , V_21 ) ;
if ( ! V_6 -> V_20 )
return - V_22 ;
V_6 -> V_23 = V_9 ;
V_12 = V_6 -> V_20 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
V_12 -> V_24 = V_8 ;
V_12 -> V_25 = V_14 [ V_8 ] . V_25 ;
V_12 -> V_26 = V_14 [ V_8 ] . V_27 ;
V_4 [ V_8 ] = V_14 [ V_8 ] . V_4 ;
V_12 ++ ;
}
return 0 ;
}
static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * * V_4 ,
struct V_5 * V_6 ,
unsigned long type )
{
return 0 ;
}
static struct V_28
* F_7 ( int V_24 , struct V_5 * V_6 )
{
int V_8 ;
if ( ! V_6 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_6 -> V_23 ; V_8 ++ ) {
if ( V_6 -> V_20 [ V_8 ] . V_24 == V_24 )
return V_6 -> V_20 [ V_8 ] . V_26 ;
}
return NULL ;
}
static int F_8 ( struct V_29 * V_30 ,
const struct V_31 * V_32 )
{
static const struct V_33 * V_20 ;
struct V_5 V_34 , * V_6 ;
struct V_1 * V_2 = & V_30 -> V_2 ;
struct V_3 * * V_4 ;
int V_8 , V_35 , V_23 ;
struct V_36 * V_36 ;
unsigned long type ;
V_6 = F_9 ( V_2 ) ;
if ( V_2 -> V_4 && ! V_6 ) {
const struct V_37 * V_24 ;
V_24 = F_10 ( F_11 ( V_38 ) , V_2 ) ;
if ( ! V_24 )
return - V_39 ;
type = ( unsigned long ) V_24 -> V_40 ;
} else {
type = V_32 -> V_41 ;
}
switch ( type ) {
case V_16 :
V_20 = V_42 ;
V_23 = F_4 ( V_42 ) ;
break;
case V_18 :
V_20 = V_43 ;
V_23 = F_4 ( V_43 ) ;
break;
default:
F_3 ( V_2 , L_3 , type ) ;
return - V_15 ;
}
V_4 = F_6 ( V_2 , sizeof( struct V_3 * ) *
V_23 , V_21 ) ;
if ( ! V_4 )
return - V_22 ;
if ( V_2 -> V_4 && ! V_6 ) {
V_35 = F_1 ( V_2 , V_4 , & V_34 , type ) ;
if ( V_35 < 0 )
return V_35 ;
V_6 = & V_34 ;
}
if ( V_6 -> V_23 > V_23 ) {
F_3 ( V_2 , L_4 ,
V_6 -> V_23 ) ;
return - V_15 ;
}
V_36 = F_6 ( V_2 , sizeof( struct V_36 ) , V_21 ) ;
if ( ! V_36 )
return - V_22 ;
V_36 -> V_44 = F_12 ( V_30 , & V_45 ) ;
if ( F_13 ( V_36 -> V_44 ) ) {
V_35 = F_14 ( V_36 -> V_44 ) ;
F_3 ( & V_30 -> V_2 , L_5 ,
V_35 ) ;
return V_35 ;
}
for ( V_8 = 0 ; V_8 < V_23 ; V_8 ++ ) {
const struct V_33 * V_46 = & V_20 [ V_8 ] ;
struct V_47 V_48 = { } ;
struct V_49 * V_50 ;
V_48 . V_2 = V_2 ;
V_48 . V_27 = F_7 ( V_46 -> V_24 , V_6 ) ;
V_48 . V_4 = V_4 [ V_8 ] ;
V_48 . V_41 = V_36 ;
V_48 . V_44 = V_36 -> V_44 ;
V_50 = F_15 ( & V_30 -> V_2 , V_46 , & V_48 ) ;
if ( F_13 ( V_50 ) ) {
F_3 ( V_2 , L_6 , V_46 -> V_25 ) ;
return F_14 ( V_50 ) ;
}
}
F_16 ( V_30 , V_36 ) ;
F_17 ( V_2 , V_4 ) ;
return 0 ;
}
