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
V_37 | F_3 ( V_36 -> V_11 ) ,
V_36 -> V_38 ) ;
if ( V_6 ) {
F_18 ( & V_34 -> V_26 , L_2 ,
V_36 -> V_38 ) ;
return V_6 ;
}
V_6 = F_17 ( & V_34 -> V_26 , V_36 -> V_12 ,
V_37 | F_3 ( V_36 -> V_12 ) ,
V_36 -> V_38 ) ;
if ( V_6 ) {
F_18 ( & V_34 -> V_26 , L_3 ,
V_36 -> V_38 ) ;
return V_6 ;
}
F_19 ( & V_2 -> V_10 ) ;
V_2 -> V_19 . V_38 = V_36 -> V_38 ;
V_2 -> V_19 . V_39 = V_36 -> V_39 ;
V_2 -> V_19 . V_40 = NULL ;
V_2 -> V_19 . V_41 = F_10 ;
V_2 -> V_19 . V_14 |= V_42 ;
V_2 -> V_11 = V_36 -> V_11 ;
V_2 -> V_12 = V_36 -> V_12 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_22 = ( V_4 == V_23 ) ? 1 : 0 ;
V_2 -> V_19 . V_43 =
( V_4 == V_21 ) ? V_20 : V_44 ;
V_6 = F_20 ( & V_34 -> V_26 , & V_2 -> V_19 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 = F_21 ( V_2 -> V_19 . V_26 , & V_45 ) ;
if ( V_6 < 0 )
goto V_46;
return 0 ;
V_46:
F_22 ( & V_2 -> V_19 ) ;
return V_6 ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 -> V_19 . V_26 , & V_45 ) ;
F_22 ( & V_2 -> V_19 ) ;
}
static int
F_25 ( struct V_25 * V_26 , struct V_47 * V_48 )
{
struct V_49 * V_50 = V_26 -> V_51 ;
struct V_49 * V_52 ;
struct V_35 * V_53 ;
int V_54 = 0 ;
int V_5 = 0 ;
V_54 = F_26 ( V_50 ) ;
if ( ! V_54 )
return - V_55 ;
V_53 = F_27 ( V_26 , V_54 * sizeof( struct V_35 ) ,
V_56 ) ;
if ( ! V_53 )
return - V_57 ;
F_28 (np, child) {
const char * string ;
int V_6 ;
V_6 = F_29 ( V_52 , L_4 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_53 [ V_5 ] . V_11 = V_6 ;
V_6 = F_29 ( V_52 , L_5 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_53 [ V_5 ] . V_12 = V_6 ;
V_6 = F_30 ( V_52 , L_6 , & string ) ;
V_53 [ V_5 ] . V_38 = ( V_6 == 0 ) ? string : V_52 -> V_38 ;
V_6 = F_30 ( V_52 , L_7 ,
& string ) ;
if ( V_6 == 0 )
V_53 [ V_5 ] . V_39 = string ;
V_5 ++ ;
}
V_48 -> V_53 = V_53 ;
V_48 -> V_54 = V_54 ;
return 0 ;
}
static int F_31 ( struct V_33 * V_34 )
{
struct V_47 * V_48 = V_34 -> V_26 . V_58 ;
struct V_1 * V_59 ;
int V_5 ;
int V_6 ;
#ifdef F_32
if ( ! V_48 ) {
V_48 = F_27 ( & V_34 -> V_26 ,
sizeof( struct V_47 ) ,
V_56 ) ;
if ( ! V_48 )
return - V_57 ;
V_6 = F_25 ( & V_34 -> V_26 , V_48 ) ;
if ( V_6 )
return V_6 ;
}
#else
if ( ! V_48 )
return - V_7 ;
#endif
V_59 = F_27 ( & V_34 -> V_26 , sizeof( struct V_1 ) *
V_48 -> V_54 , V_56 ) ;
if ( ! V_59 )
return - V_57 ;
for ( V_5 = 0 ; V_5 < V_48 -> V_54 ; V_5 ++ ) {
V_6 = F_16 ( V_34 , & V_59 [ V_5 ] , & V_48 -> V_53 [ V_5 ] ) ;
if ( V_6 < 0 ) {
for ( V_5 = V_5 - 1 ; V_5 >= 0 ; V_5 -- )
F_23 ( & V_59 [ V_5 ] ) ;
return V_6 ;
}
}
F_33 ( V_34 , V_59 ) ;
return 0 ;
}
static int F_34 ( struct V_33 * V_34 )
{
int V_5 ;
struct V_47 * V_48 = V_34 -> V_26 . V_58 ;
struct V_1 * V_59 ;
V_59 = F_35 ( V_34 ) ;
for ( V_5 = 0 ; V_5 < V_48 -> V_54 ; V_5 ++ )
F_23 ( & V_59 [ V_5 ] ) ;
F_33 ( V_34 , NULL ) ;
return 0 ;
}
