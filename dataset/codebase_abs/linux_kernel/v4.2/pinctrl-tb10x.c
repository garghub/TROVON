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
V_20 -> V_26 ) ;
return - V_27 ;
}
* V_22 = NULL ;
* V_23 = 0 ;
V_25 = F_13 ( V_11 , V_22 , & V_24 ,
V_23 , 1 ) ;
if ( V_25 )
goto V_28;
V_25 = F_14 ( V_11 , V_22 , & V_24 ,
V_23 , string , V_20 -> V_15 ) ;
V_28:
return V_25 ;
}
static int F_15 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
return V_2 -> V_29 ;
}
static const char * F_16 ( struct V_10 * V_11 ,
unsigned V_13 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
return V_2 -> V_30 [ V_13 ] . V_15 ;
}
static int F_17 ( struct V_10 * V_11 ,
unsigned V_13 , const char * const * * V_31 ,
unsigned * const V_32 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
* V_31 = & V_2 -> V_30 [ V_13 ] . V_33 ;
* V_32 = 1 ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 ,
struct V_34 * V_35 ,
unsigned V_36 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
int V_37 = - 1 ;
int V_38 = - 1 ;
int V_39 ;
F_19 ( & V_2 -> V_40 ) ;
for ( V_39 = 0 ; V_39 < V_2 -> V_12 ; V_39 ++ ) {
const struct V_41 * V_42 = & V_2 -> V_14 [ V_39 ] ;
unsigned int V_4 = V_42 -> V_4 ;
int V_43 , V_3 = V_42 -> V_3 ;
if ( V_3 < 0 )
continue;
for ( V_43 = 0 ; V_43 < V_42 -> V_18 ; V_43 ++ ) {
if ( V_36 == V_42 -> V_16 [ V_43 ] ) {
if ( V_42 -> V_44 ) {
V_37 = V_3 ;
V_38 = V_4 ;
} else if ( V_2 -> V_6 [ V_3 ] . V_7
&& ( V_2 -> V_6 [ V_3 ] . V_4 == V_4 ) ) {
F_20 ( & V_2 -> V_40 ) ;
return - V_45 ;
}
break;
}
}
}
F_21 ( V_36 , V_2 -> V_46 ) ;
if ( V_37 >= 0 )
F_1 ( V_2 , V_37 , V_38 ) ;
F_20 ( & V_2 -> V_40 ) ;
return 0 ;
}
static void F_22 ( struct V_10 * V_11 ,
struct V_34 * V_35 ,
unsigned V_36 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
F_19 ( & V_2 -> V_40 ) ;
F_23 ( V_36 , V_2 -> V_46 ) ;
F_20 ( & V_2 -> V_40 ) ;
}
static int F_24 ( struct V_10 * V_11 ,
unsigned V_47 , unsigned V_48 )
{
struct V_1 * V_2 = F_7 ( V_11 ) ;
const struct V_41 * V_49 = & V_2 -> V_14 [ V_48 ] ;
int V_39 ;
if ( V_49 -> V_3 < 0 )
return 0 ;
F_19 ( & V_2 -> V_40 ) ;
if ( V_2 -> V_6 [ V_49 -> V_3 ] . V_7
&& ( V_2 -> V_6 [ V_49 -> V_3 ] . V_4 != V_49 -> V_4 ) ) {
F_20 ( & V_2 -> V_40 ) ;
return - V_45 ;
}
for ( V_39 = 0 ; V_39 < V_49 -> V_18 ; V_39 ++ )
if ( F_25 ( V_49 -> V_16 [ V_39 ] , V_2 -> V_46 ) ) {
F_20 ( & V_2 -> V_40 ) ;
return - V_45 ;
}
F_1 ( V_2 , V_49 -> V_3 , V_49 -> V_4 ) ;
V_2 -> V_6 [ V_49 -> V_3 ] . V_7 ++ ;
F_20 ( & V_2 -> V_40 ) ;
return 0 ;
}
static int F_26 ( struct V_50 * V_51 )
{
int V_25 = - V_27 ;
struct V_52 * V_53 ;
struct V_54 * V_55 = & V_51 -> V_55 ;
struct V_19 * V_56 = V_55 -> V_56 ;
struct V_19 * V_57 ;
struct V_1 * V_2 ;
int V_39 ;
if ( ! V_56 ) {
F_27 ( V_55 , L_3 ) ;
return - V_27 ;
}
V_2 = F_28 ( V_55 , sizeof( struct V_1 ) +
F_29 ( V_56 )
* sizeof( struct V_58 ) ,
V_59 ) ;
if ( ! V_2 )
return - V_60 ;
F_30 ( V_51 , V_2 ) ;
V_2 -> V_30 = (struct V_58 * ) ( V_2 + 1 ) ;
F_31 ( & V_2 -> V_40 ) ;
V_53 = F_32 ( V_51 , V_61 , 0 ) ;
V_2 -> V_8 = F_33 ( V_55 , V_53 ) ;
if ( F_34 ( V_2 -> V_8 ) ) {
V_25 = F_35 ( V_2 -> V_8 ) ;
goto V_62;
}
V_2 -> V_14 = V_63 ;
V_2 -> V_12 = F_36 ( V_63 ) ;
for ( V_39 = 0 ; V_39 < V_64 ; V_39 ++ )
V_2 -> V_6 [ V_39 ] . V_4 = F_5 ( V_2 , V_39 ) ;
F_37 (of_node, child) {
const char * V_15 ;
if ( ! F_11 ( V_57 , L_1 ,
& V_15 ) ) {
V_2 -> V_30 [ V_2 -> V_29 ] . V_15 = V_57 -> V_15 ;
V_2 -> V_30 [ V_2 -> V_29 ] . V_33 = V_15 ;
V_2 -> V_29 ++ ;
}
}
V_2 -> V_11 = F_38 ( & V_65 , V_55 , V_2 ) ;
if ( F_34 ( V_2 -> V_11 ) ) {
F_27 ( V_55 , L_4 ) ;
V_25 = F_35 ( V_2 -> V_11 ) ;
goto V_62;
}
return 0 ;
V_62:
F_39 ( & V_2 -> V_40 ) ;
return V_25 ;
}
static int F_40 ( struct V_50 * V_51 )
{
struct V_1 * V_2 = F_41 ( V_51 ) ;
F_42 ( V_2 -> V_11 ) ;
F_39 ( & V_2 -> V_40 ) ;
return 0 ;
}
