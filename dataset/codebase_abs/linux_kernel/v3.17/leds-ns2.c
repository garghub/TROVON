static int F_1 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
int V_5 ;
int V_6 = - V_7 ;
int V_8 ;
int V_9 ;
F_2 ( & V_2 -> V_10 ) ;
V_8 = F_3 ( V_2 -> V_11 ) ;
V_9 = F_3 ( V_2 -> V_12 ) ;
for ( V_5 = 0 ; V_5 < F_4 ( V_13 ) ; V_5 ++ ) {
if ( V_8 == V_13 [ V_5 ] . V_8 &&
V_9 == V_13 [ V_5 ] . V_9 ) {
* V_4 = V_13 [ V_5 ] . V_4 ;
V_6 = 0 ;
break;
}
}
F_5 ( & V_2 -> V_10 ) ;
return V_6 ;
}
static void F_6 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
unsigned long V_14 ;
F_7 ( & V_2 -> V_10 , V_14 ) ;
for ( V_5 = 0 ; V_5 < F_4 ( V_13 ) ; V_5 ++ ) {
if ( V_4 == V_13 [ V_5 ] . V_4 ) {
F_8 ( V_2 -> V_11 ,
V_13 [ V_5 ] . V_8 ) ;
F_8 ( V_2 -> V_12 ,
V_13 [ V_5 ] . V_9 ) ;
}
}
F_9 ( & V_2 -> V_10 , V_14 ) ;
}
static void F_10 ( struct V_15 * V_16 ,
enum V_17 V_18 )
{
struct V_1 * V_2 =
F_11 ( V_16 , struct V_1 , V_19 ) ;
enum V_3 V_4 ;
if ( V_18 == V_20 )
V_4 = V_21 ;
else if ( V_2 -> V_22 )
V_4 = V_23 ;
else
V_4 = V_24 ;
F_6 ( V_2 , V_4 ) ;
}
static T_1 F_12 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_29 , T_2 V_30 )
{
struct V_15 * V_16 = F_13 ( V_26 ) ;
struct V_1 * V_2 =
F_11 ( V_16 , struct V_1 , V_19 ) ;
int V_6 ;
unsigned long V_31 ;
enum V_3 V_4 ;
V_6 = F_14 ( V_29 , 10 , & V_31 ) ;
if ( V_6 < 0 )
return V_6 ;
V_31 = ! ! V_31 ;
if ( V_2 -> V_22 == V_31 )
return V_30 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( V_31 && V_4 == V_24 )
F_6 ( V_2 , V_23 ) ;
if ( ! V_31 && V_4 == V_23 )
F_6 ( V_2 , V_24 ) ;
V_2 -> V_22 = V_31 ;
return V_30 ;
}
static T_1 F_15 ( struct V_25 * V_26 ,
struct V_27 * V_28 , char * V_32 )
{
struct V_15 * V_16 = F_13 ( V_26 ) ;
struct V_1 * V_2 =
F_11 ( V_16 , struct V_1 , V_19 ) ;
return sprintf ( V_32 , L_1 , V_2 -> V_22 ) ;
}
static int
F_16 ( struct V_33 * V_34 , struct V_1 * V_2 ,
const struct V_35 * V_36 )
{
int V_6 ;
enum V_3 V_4 ;
V_6 = F_17 ( & V_34 -> V_26 , V_36 -> V_11 ,
F_3 ( V_36 -> V_11 ) ?
V_37 : V_38 ,
V_36 -> V_39 ) ;
if ( V_6 ) {
F_18 ( & V_34 -> V_26 , L_2 ,
V_36 -> V_39 ) ;
return V_6 ;
}
V_6 = F_17 ( & V_34 -> V_26 , V_36 -> V_12 ,
F_3 ( V_36 -> V_12 ) ?
V_37 : V_38 ,
V_36 -> V_39 ) ;
if ( V_6 ) {
F_18 ( & V_34 -> V_26 , L_3 ,
V_36 -> V_39 ) ;
return V_6 ;
}
F_19 ( & V_2 -> V_10 ) ;
V_2 -> V_19 . V_39 = V_36 -> V_39 ;
V_2 -> V_19 . V_40 = V_36 -> V_40 ;
V_2 -> V_19 . V_41 = NULL ;
V_2 -> V_19 . V_42 = F_10 ;
V_2 -> V_19 . V_14 |= V_43 ;
V_2 -> V_19 . V_44 = V_45 ;
V_2 -> V_11 = V_36 -> V_11 ;
V_2 -> V_12 = V_36 -> V_12 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_22 = ( V_4 == V_23 ) ? 1 : 0 ;
V_2 -> V_19 . V_46 =
( V_4 == V_21 ) ? V_20 : V_47 ;
V_6 = F_20 ( & V_34 -> V_26 , & V_2 -> V_19 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_19 ) ;
}
static int
F_23 ( struct V_25 * V_26 , struct V_48 * V_49 )
{
struct V_50 * V_51 = V_26 -> V_52 ;
struct V_50 * V_53 ;
struct V_35 * V_54 ;
int V_55 = 0 ;
int V_5 = 0 ;
V_55 = F_24 ( V_51 ) ;
if ( ! V_55 )
return - V_56 ;
V_54 = F_25 ( V_26 , V_55 * sizeof( struct V_35 ) ,
V_57 ) ;
if ( ! V_54 )
return - V_58 ;
F_26 (np, child) {
const char * string ;
int V_6 ;
V_6 = F_27 ( V_53 , L_4 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_54 [ V_5 ] . V_11 = V_6 ;
V_6 = F_27 ( V_53 , L_5 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_54 [ V_5 ] . V_12 = V_6 ;
V_6 = F_28 ( V_53 , L_6 , & string ) ;
V_54 [ V_5 ] . V_39 = ( V_6 == 0 ) ? string : V_53 -> V_39 ;
V_6 = F_28 ( V_53 , L_7 ,
& string ) ;
if ( V_6 == 0 )
V_54 [ V_5 ] . V_40 = string ;
V_5 ++ ;
}
V_49 -> V_54 = V_54 ;
V_49 -> V_55 = V_55 ;
return 0 ;
}
static inline int F_29 ( int V_55 )
{
return sizeof( struct V_59 ) +
( sizeof( struct V_1 ) * V_55 ) ;
}
static int F_30 ( struct V_33 * V_34 )
{
struct V_48 * V_49 = F_31 ( & V_34 -> V_26 ) ;
struct V_59 * V_60 ;
int V_5 ;
int V_6 ;
#ifdef F_32
if ( ! V_49 ) {
V_49 = F_25 ( & V_34 -> V_26 ,
sizeof( struct V_48 ) ,
V_57 ) ;
if ( ! V_49 )
return - V_58 ;
V_6 = F_23 ( & V_34 -> V_26 , V_49 ) ;
if ( V_6 )
return V_6 ;
}
#else
if ( ! V_49 )
return - V_7 ;
#endif
V_60 = F_25 ( & V_34 -> V_26 ,
F_29 ( V_49 -> V_55 ) , V_57 ) ;
if ( ! V_60 )
return - V_58 ;
V_60 -> V_55 = V_49 -> V_55 ;
for ( V_5 = 0 ; V_5 < V_60 -> V_55 ; V_5 ++ ) {
V_6 = F_16 ( V_34 , & V_60 -> V_61 [ V_5 ] ,
& V_49 -> V_54 [ V_5 ] ) ;
if ( V_6 < 0 ) {
for ( V_5 = V_5 - 1 ; V_5 >= 0 ; V_5 -- )
F_21 ( & V_60 -> V_61 [ V_5 ] ) ;
return V_6 ;
}
}
F_33 ( V_34 , V_60 ) ;
return 0 ;
}
static int F_34 ( struct V_33 * V_34 )
{
int V_5 ;
struct V_59 * V_60 ;
V_60 = F_35 ( V_34 ) ;
for ( V_5 = 0 ; V_5 < V_60 -> V_55 ; V_5 ++ )
F_21 ( & V_60 -> V_61 [ V_5 ] ) ;
return 0 ;
}
