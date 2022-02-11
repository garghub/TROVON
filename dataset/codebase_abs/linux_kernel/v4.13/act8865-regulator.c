static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long type )
{
int V_5 , V_6 , V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
switch ( type ) {
case V_14 :
V_13 = V_15 ;
V_7 = F_2 ( V_15 ) ;
break;
case V_16 :
V_13 = V_17 ;
V_7 = F_2 ( V_17 ) ;
break;
case V_18 :
V_13 = V_19 ;
V_7 = F_2 ( V_19 ) ;
break;
default:
F_3 ( V_2 , L_1 , type ) ;
return - V_20 ;
}
V_9 = F_4 ( V_2 -> V_21 , L_2 ) ;
if ( ! V_9 ) {
F_3 ( V_2 , L_3 ) ;
return - V_20 ;
}
V_5 = V_12 ( V_2 , V_9 , V_13 , V_7 ) ;
F_5 ( V_9 ) ;
if ( V_5 <= 0 )
return V_5 ;
V_4 -> V_22 = F_6 ( V_2 ,
sizeof( struct V_10 ) *
V_7 , V_23 ) ;
if ( ! V_4 -> V_22 )
return - V_24 ;
V_4 -> V_25 = V_7 ;
V_11 = V_4 -> V_22 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ ) {
V_11 -> V_26 = V_6 ;
V_11 -> V_27 = V_13 [ V_6 ] . V_27 ;
V_11 -> V_28 = V_13 [ V_6 ] . V_28 ;
V_11 -> V_21 = V_13 [ V_6 ] . V_21 ;
V_11 ++ ;
}
return 0 ;
}
static inline int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
unsigned long type )
{
return 0 ;
}
static struct V_10 * F_7 (
int V_26 , struct V_3 * V_4 )
{
int V_6 ;
if ( ! V_4 )
return NULL ;
for ( V_6 = 0 ; V_6 < V_4 -> V_25 ; V_6 ++ ) {
if ( V_4 -> V_22 [ V_6 ] . V_26 == V_26 )
return & V_4 -> V_22 [ V_6 ] ;
}
return NULL ;
}
static void F_8 ( void )
{
struct V_29 * V_29 ;
V_29 = F_9 ( V_30 ) ;
F_10 ( V_29 -> V_31 , V_29 -> V_32 , V_29 -> V_33 ) ;
while ( 1 ) ;
}
static int F_11 ( struct V_34 * V_35 ,
const struct V_36 * V_37 )
{
const struct V_38 * V_22 ;
struct V_3 V_39 , * V_4 ;
struct V_1 * V_2 = & V_35 -> V_2 ;
int V_6 , V_40 , V_25 ;
struct V_29 * V_29 ;
const struct V_41 * V_41 ;
unsigned long type ;
int V_32 , V_33 ;
int V_42 = 0 ;
V_4 = F_12 ( V_2 ) ;
if ( V_2 -> V_21 && ! V_4 ) {
const struct V_43 * V_26 ;
V_26 = F_13 ( F_14 ( V_44 ) , V_2 ) ;
if ( ! V_26 )
return - V_45 ;
type = ( unsigned long ) V_26 -> V_46 ;
V_42 = ! ! F_15 ( V_2 -> V_21 ,
L_4 ,
NULL ) ;
} else {
type = V_37 -> V_47 ;
}
switch ( type ) {
case V_14 :
V_22 = V_48 ;
V_25 = F_2 ( V_48 ) ;
V_41 = & V_49 ;
V_32 = - 1 ;
V_33 = - 1 ;
break;
case V_16 :
V_22 = V_50 ;
V_25 = F_2 ( V_50 ) ;
V_41 = & V_51 ;
V_32 = V_52 ;
V_33 = V_53 ;
break;
case V_18 :
if ( V_42 ) {
V_22 = V_54 ;
V_25 = F_2 ( V_54 ) ;
} else {
V_22 = V_55 ;
V_25 = F_2 ( V_55 ) ;
}
V_41 = & V_51 ;
V_32 = V_56 ;
V_33 = V_57 ;
break;
default:
F_3 ( V_2 , L_1 , type ) ;
return - V_20 ;
}
if ( V_2 -> V_21 && ! V_4 ) {
V_40 = F_1 ( V_2 , & V_39 , type ) ;
if ( V_40 < 0 )
return V_40 ;
V_4 = & V_39 ;
}
V_29 = F_6 ( V_2 , sizeof( struct V_29 ) , V_23 ) ;
if ( ! V_29 )
return - V_24 ;
V_29 -> V_31 = F_16 ( V_35 , V_41 ) ;
if ( F_17 ( V_29 -> V_31 ) ) {
V_40 = F_18 ( V_29 -> V_31 ) ;
F_3 ( V_2 , L_5 , V_40 ) ;
return V_40 ;
}
if ( F_19 ( V_2 -> V_21 ) ) {
if ( ! V_58 && ( V_32 > 0 ) ) {
V_30 = V_35 ;
V_29 -> V_32 = V_32 ;
V_29 -> V_33 = V_33 ;
V_58 = F_8 ;
} else {
F_3 ( V_2 , L_6 ) ;
}
}
for ( V_6 = 0 ; V_6 < V_25 ; V_6 ++ ) {
const struct V_38 * V_59 = & V_22 [ V_6 ] ;
struct V_60 V_61 = { } ;
struct V_10 * V_62 ;
struct V_63 * V_64 ;
V_61 . V_2 = V_2 ;
V_61 . V_47 = V_29 ;
V_61 . V_31 = V_29 -> V_31 ;
V_62 = F_7 ( V_59 -> V_26 , V_4 ) ;
if ( V_62 ) {
V_61 . V_28 = V_62 -> V_28 ;
V_61 . V_21 = V_62 -> V_21 ;
}
V_64 = F_20 ( V_2 , V_59 , & V_61 ) ;
if ( F_17 ( V_64 ) ) {
F_3 ( V_2 , L_7 , V_59 -> V_27 ) ;
return F_18 ( V_64 ) ;
}
}
F_21 ( V_35 , V_29 ) ;
return 0 ;
}
