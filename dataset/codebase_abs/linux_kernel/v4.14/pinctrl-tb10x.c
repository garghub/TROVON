static inline void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_4 )
{
T_1 V_5 ;
if ( V_2 -> V_6 [ V_3 ] . V_7 )
return;
V_2 -> V_6 [ V_3 ] . V_4 = V_4 ;
V_5 = F_2 ( V_2 -> V_8 ) & ~ ( F_3 ( V_3 ) ) ;
V_5 |= ( V_4 << ( V_9 * V_3 ) ) & F_3 ( V_3 ) ;
F_4 ( V_5 , V_2 -> V_8 ) ;
}
static inline unsigned int F_5 (
struct V_1 * V_2 ,
unsigned int V_3 )
{
return ( F_2 ( V_2 -> V_8 ) & F_3 ( V_3 ) )
>> ( V_9 * V_3 ) ;
}
static int F_6 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
return V_2 -> V_12 ;
}
static const char * F_8 ( struct V_10 * V_11 , unsigned V_13 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
return V_2 -> V_14 [ V_13 ] . V_15 ;
}
static int F_9 ( struct V_10 * V_11 , unsigned V_13 ,
unsigned const * * V_16 ,
unsigned * const V_17 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
* V_16 = V_2 -> V_14 [ V_13 ] . V_16 ;
* V_17 = V_2 -> V_14 [ V_13 ] . V_18 ;
return 0 ;
}
static int F_10 ( struct V_10 * V_11 ,
struct V_19 * V_20 ,
struct V_21 * * V_22 , unsigned * V_23 )
{
const char * string ;
unsigned V_24 = 0 ;
int V_25 = 0 ;
if ( F_11 ( V_20 , L_1 , & string ) ) {
F_12 ( L_2 ,
V_20 ) ;
return - V_26 ;
}
* V_22 = NULL ;
* V_23 = 0 ;
V_25 = F_13 ( V_11 , V_22 , & V_24 ,
V_23 , 1 ) ;
if ( V_25 )
goto V_27;
V_25 = F_14 ( V_11 , V_22 , & V_24 ,
V_23 , string , V_20 -> V_15 ) ;
V_27:
return V_25 ;
}
static int F_15 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
return V_2 -> V_28 ;
}
static const char * F_16 ( struct V_10 * V_11 ,
unsigned V_13 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
return V_2 -> V_29 [ V_13 ] . V_15 ;
}
static int F_17 ( struct V_10 * V_11 ,
unsigned V_13 , const char * const * * V_30 ,
unsigned * const V_31 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
* V_30 = & V_2 -> V_29 [ V_13 ] . V_32 ;
* V_31 = 1 ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 ,
struct V_33 * V_34 ,
unsigned V_35 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_36 = - 1 ;
int V_37 = - 1 ;
int V_38 ;
F_19 ( & V_2 -> V_39 ) ;
for ( V_38 = 0 ; V_38 < V_2 -> V_12 ; V_38 ++ ) {
const struct V_40 * V_41 = & V_2 -> V_14 [ V_38 ] ;
unsigned int V_4 = V_41 -> V_4 ;
int V_42 , V_3 = V_41 -> V_3 ;
if ( V_3 < 0 )
continue;
for ( V_42 = 0 ; V_42 < V_41 -> V_18 ; V_42 ++ ) {
if ( V_35 == V_41 -> V_16 [ V_42 ] ) {
if ( V_41 -> V_43 ) {
V_36 = V_3 ;
V_37 = V_4 ;
} else if ( V_2 -> V_6 [ V_3 ] . V_7
&& ( V_2 -> V_6 [ V_3 ] . V_4 == V_4 ) ) {
F_20 ( & V_2 -> V_39 ) ;
return - V_44 ;
}
break;
}
}
}
F_21 ( V_35 , V_2 -> V_45 ) ;
if ( V_36 >= 0 )
F_1 ( V_2 , V_36 , V_37 ) ;
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static void F_22 ( struct V_10 * V_11 ,
struct V_33 * V_34 ,
unsigned V_35 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_19 ( & V_2 -> V_39 ) ;
F_23 ( V_35 , V_2 -> V_45 ) ;
F_20 ( & V_2 -> V_39 ) ;
}
static int F_24 ( struct V_10 * V_11 ,
unsigned V_46 , unsigned V_47 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
const struct V_40 * V_48 = & V_2 -> V_14 [ V_47 ] ;
int V_38 ;
if ( V_48 -> V_3 < 0 )
return 0 ;
F_19 ( & V_2 -> V_39 ) ;
if ( V_2 -> V_6 [ V_48 -> V_3 ] . V_7
&& ( V_2 -> V_6 [ V_48 -> V_3 ] . V_4 != V_48 -> V_4 ) ) {
F_20 ( & V_2 -> V_39 ) ;
return - V_44 ;
}
for ( V_38 = 0 ; V_38 < V_48 -> V_18 ; V_38 ++ )
if ( F_25 ( V_48 -> V_16 [ V_38 ] , V_2 -> V_45 ) ) {
F_20 ( & V_2 -> V_39 ) ;
return - V_44 ;
}
F_1 ( V_2 , V_48 -> V_3 , V_48 -> V_4 ) ;
V_2 -> V_6 [ V_48 -> V_3 ] . V_7 ++ ;
F_20 ( & V_2 -> V_39 ) ;
return 0 ;
}
static int F_26 ( struct V_49 * V_50 )
{
int V_25 = - V_26 ;
struct V_51 * V_52 ;
struct V_53 * V_54 = & V_50 -> V_54 ;
struct V_19 * V_55 = V_54 -> V_55 ;
struct V_19 * V_56 ;
struct V_1 * V_2 ;
int V_38 ;
if ( ! V_55 ) {
F_27 ( V_54 , L_3 ) ;
return - V_26 ;
}
V_2 = F_28 ( V_54 , sizeof( struct V_1 ) +
F_29 ( V_55 )
* sizeof( struct V_57 ) ,
V_58 ) ;
if ( ! V_2 )
return - V_59 ;
F_30 ( V_50 , V_2 ) ;
V_2 -> V_29 = (struct V_57 * ) ( V_2 + 1 ) ;
F_31 ( & V_2 -> V_39 ) ;
V_52 = F_32 ( V_50 , V_60 , 0 ) ;
V_2 -> V_8 = F_33 ( V_54 , V_52 ) ;
if ( F_34 ( V_2 -> V_8 ) ) {
V_25 = F_35 ( V_2 -> V_8 ) ;
goto V_61;
}
V_2 -> V_14 = V_62 ;
V_2 -> V_12 = F_36 ( V_62 ) ;
for ( V_38 = 0 ; V_38 < V_63 ; V_38 ++ )
V_2 -> V_6 [ V_38 ] . V_4 = F_5 ( V_2 , V_38 ) ;
F_37 (of_node, child) {
const char * V_15 ;
if ( ! F_11 ( V_56 , L_1 ,
& V_15 ) ) {
V_2 -> V_29 [ V_2 -> V_28 ] . V_15 = V_56 -> V_15 ;
V_2 -> V_29 [ V_2 -> V_28 ] . V_32 = V_15 ;
V_2 -> V_28 ++ ;
}
}
V_2 -> V_11 = F_38 ( V_54 , & V_64 , V_2 ) ;
if ( F_34 ( V_2 -> V_11 ) ) {
F_27 ( V_54 , L_4 ) ;
V_25 = F_35 ( V_2 -> V_11 ) ;
goto V_61;
}
return 0 ;
V_61:
F_39 ( & V_2 -> V_39 ) ;
return V_25 ;
}
static int F_40 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_41 ( V_50 ) ;
F_39 ( & V_2 -> V_39 ) ;
return 0 ;
}
