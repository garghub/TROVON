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
static const struct V_38 * V_20 ;
struct V_5 V_39 , * V_6 ;
struct V_1 * V_2 = & V_35 -> V_2 ;
struct V_3 * * V_4 ;
int V_8 , V_40 , V_23 ;
struct V_29 * V_29 ;
unsigned long type ;
int V_32 , V_33 ;
V_6 = F_12 ( V_2 ) ;
if ( V_2 -> V_4 && ! V_6 ) {
const struct V_41 * V_24 ;
V_24 = F_13 ( F_14 ( V_42 ) , V_2 ) ;
if ( ! V_24 )
return - V_43 ;
type = ( unsigned long ) V_24 -> V_44 ;
} else {
type = V_37 -> V_45 ;
}
switch ( type ) {
case V_16 :
V_20 = V_46 ;
V_23 = F_4 ( V_46 ) ;
V_32 = V_47 ;
V_33 = V_48 ;
break;
case V_18 :
V_20 = V_49 ;
V_23 = F_4 ( V_49 ) ;
V_32 = V_50 ;
V_33 = V_51 ;
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
V_40 = F_1 ( V_2 , V_4 , & V_39 , type ) ;
if ( V_40 < 0 )
return V_40 ;
V_6 = & V_39 ;
}
if ( V_6 -> V_23 > V_23 ) {
F_3 ( V_2 , L_4 ,
V_6 -> V_23 ) ;
return - V_15 ;
}
V_29 = F_6 ( V_2 , sizeof( struct V_29 ) , V_21 ) ;
if ( ! V_29 )
return - V_22 ;
V_29 -> V_31 = F_15 ( V_35 , & V_52 ) ;
if ( F_16 ( V_29 -> V_31 ) ) {
V_40 = F_17 ( V_29 -> V_31 ) ;
F_3 ( & V_35 -> V_2 , L_5 ,
V_40 ) ;
return V_40 ;
}
if ( F_18 ( V_2 -> V_4 ) ) {
if ( ! V_53 ) {
V_30 = V_35 ;
V_29 -> V_32 = V_32 ;
V_29 -> V_33 = V_33 ;
V_53 = F_8 ;
} else {
F_3 ( V_2 , L_6 ) ;
}
}
for ( V_8 = 0 ; V_8 < V_23 ; V_8 ++ ) {
const struct V_38 * V_54 = & V_20 [ V_8 ] ;
struct V_55 V_56 = { } ;
struct V_57 * V_58 ;
V_56 . V_2 = V_2 ;
V_56 . V_27 = F_7 ( V_54 -> V_24 , V_6 ) ;
V_56 . V_4 = V_4 [ V_8 ] ;
V_56 . V_45 = V_29 ;
V_56 . V_31 = V_29 -> V_31 ;
V_58 = F_19 ( & V_35 -> V_2 , V_54 , & V_56 ) ;
if ( F_16 ( V_58 ) ) {
F_3 ( V_2 , L_7 , V_54 -> V_25 ) ;
return F_17 ( V_58 ) ;
}
}
F_20 ( V_35 , V_29 ) ;
F_21 ( V_2 , V_4 ) ;
return 0 ;
}
