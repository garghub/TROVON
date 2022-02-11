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
case V_20 :
V_14 = V_21 ;
V_9 = F_4 ( V_21 ) ;
break;
default:
F_3 ( V_2 , L_3 , type ) ;
return - V_15 ;
}
V_7 = V_13 ( V_2 , V_10 , V_14 , V_9 ) ;
F_5 ( V_10 ) ;
if ( V_7 <= 0 )
return V_7 ;
V_6 -> V_22 = F_6 ( V_2 ,
sizeof( struct V_11 ) *
V_9 , V_23 ) ;
if ( ! V_6 -> V_22 )
return - V_24 ;
V_6 -> V_25 = V_9 ;
V_12 = V_6 -> V_22 ;
for ( V_8 = 0 ; V_8 < V_9 ; V_8 ++ ) {
V_12 -> V_26 = V_8 ;
V_12 -> V_27 = V_14 [ V_8 ] . V_27 ;
V_12 -> V_28 = V_14 [ V_8 ] . V_28 ;
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
static struct V_29
* F_7 ( int V_26 , struct V_5 * V_6 )
{
int V_8 ;
if ( ! V_6 )
return NULL ;
for ( V_8 = 0 ; V_8 < V_6 -> V_25 ; V_8 ++ ) {
if ( V_6 -> V_22 [ V_8 ] . V_26 == V_26 )
return V_6 -> V_22 [ V_8 ] . V_28 ;
}
return NULL ;
}
static void F_8 ( void )
{
struct V_30 * V_30 ;
V_30 = F_9 ( V_31 ) ;
F_10 ( V_30 -> V_32 , V_30 -> V_33 , V_30 -> V_34 ) ;
while ( 1 ) ;
}
static int F_11 ( struct V_35 * V_36 ,
const struct V_37 * V_38 )
{
const struct V_39 * V_22 ;
struct V_5 V_40 , * V_6 ;
struct V_1 * V_2 = & V_36 -> V_2 ;
struct V_3 * * V_4 ;
int V_8 , V_41 , V_25 ;
struct V_30 * V_30 ;
unsigned long type ;
int V_33 , V_34 ;
int V_42 = 0 ;
V_6 = F_12 ( V_2 ) ;
if ( V_2 -> V_4 && ! V_6 ) {
const struct V_43 * V_26 ;
V_26 = F_13 ( F_14 ( V_44 ) , V_2 ) ;
if ( ! V_26 )
return - V_45 ;
type = ( unsigned long ) V_26 -> V_46 ;
V_42 = ! ! F_15 ( V_2 -> V_4 ,
L_4 ,
NULL ) ;
} else {
type = V_38 -> V_47 ;
}
switch ( type ) {
case V_16 :
V_22 = V_48 ;
V_25 = F_4 ( V_48 ) ;
V_33 = - 1 ;
V_34 = - 1 ;
break;
case V_18 :
V_22 = V_49 ;
V_25 = F_4 ( V_49 ) ;
V_33 = V_50 ;
V_34 = V_51 ;
break;
case V_20 :
if ( V_42 ) {
V_22 = V_52 ;
V_25 = F_4 ( V_52 ) ;
} else {
V_22 = V_53 ;
V_25 = F_4 ( V_53 ) ;
}
V_33 = V_54 ;
V_34 = V_55 ;
break;
default:
F_3 ( V_2 , L_3 , type ) ;
return - V_15 ;
}
V_4 = F_6 ( V_2 , sizeof( struct V_3 * ) *
V_25 , V_23 ) ;
if ( ! V_4 )
return - V_24 ;
if ( V_2 -> V_4 && ! V_6 ) {
V_41 = F_1 ( V_2 , V_4 , & V_40 , type ) ;
if ( V_41 < 0 )
return V_41 ;
V_6 = & V_40 ;
}
if ( V_6 -> V_25 > V_25 ) {
F_3 ( V_2 , L_5 ,
V_6 -> V_25 ) ;
return - V_15 ;
}
V_30 = F_6 ( V_2 , sizeof( struct V_30 ) , V_23 ) ;
if ( ! V_30 )
return - V_24 ;
V_30 -> V_32 = F_16 ( V_36 , & V_56 ) ;
if ( F_17 ( V_30 -> V_32 ) ) {
V_41 = F_18 ( V_30 -> V_32 ) ;
F_3 ( & V_36 -> V_2 , L_6 ,
V_41 ) ;
return V_41 ;
}
if ( F_19 ( V_2 -> V_4 ) ) {
if ( ! V_57 && ( V_33 > 0 ) ) {
V_31 = V_36 ;
V_30 -> V_33 = V_33 ;
V_30 -> V_34 = V_34 ;
V_57 = F_8 ;
} else {
F_3 ( V_2 , L_7 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_25 ; V_8 ++ ) {
const struct V_39 * V_58 = & V_22 [ V_8 ] ;
struct V_59 V_60 = { } ;
struct V_61 * V_62 ;
V_60 . V_2 = V_2 ;
V_60 . V_28 = F_7 ( V_58 -> V_26 , V_6 ) ;
V_60 . V_4 = V_4 [ V_8 ] ;
V_60 . V_47 = V_30 ;
V_60 . V_32 = V_30 -> V_32 ;
V_62 = F_20 ( & V_36 -> V_2 , V_58 , & V_60 ) ;
if ( F_17 ( V_62 ) ) {
F_3 ( V_2 , L_8 , V_58 -> V_27 ) ;
return F_18 ( V_62 ) ;
}
}
F_21 ( V_36 , V_30 ) ;
F_22 ( V_2 , V_4 ) ;
return 0 ;
}
