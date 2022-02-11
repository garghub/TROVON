static int F_1 ( struct V_1 * V_2 ,
enum V_3 * V_4 )
{
int V_5 ;
int V_6 = - V_7 ;
int V_8 ;
int V_9 ;
V_8 = F_2 ( V_2 -> V_10 ) ;
V_9 = F_2 ( V_2 -> V_11 ) ;
for ( V_5 = 0 ; V_5 < V_2 -> V_12 ; V_5 ++ ) {
if ( V_8 == V_2 -> V_13 [ V_5 ] . V_8 &&
V_9 == V_2 -> V_13 [ V_5 ] . V_9 ) {
* V_4 = V_2 -> V_13 [ V_5 ] . V_4 ;
V_6 = 0 ;
break;
}
}
return V_6 ;
}
static void F_3 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
int V_5 ;
bool V_14 = false ;
unsigned long V_15 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_12 ; V_5 ++ )
if ( V_4 == V_2 -> V_13 [ V_5 ] . V_4 ) {
V_14 = true ;
break;
}
if ( ! V_14 )
return;
F_4 ( & V_2 -> V_16 , V_15 ) ;
if ( ! V_2 -> V_17 ) {
F_5 ( V_2 -> V_10 ,
V_2 -> V_13 [ V_5 ] . V_8 ) ;
F_5 ( V_2 -> V_11 ,
V_2 -> V_13 [ V_5 ] . V_9 ) ;
goto V_18;
}
F_6 ( V_2 -> V_10 , V_2 -> V_13 [ V_5 ] . V_8 ) ;
F_6 ( V_2 -> V_11 , V_2 -> V_13 [ V_5 ] . V_9 ) ;
V_18:
F_7 ( & V_2 -> V_16 , V_15 ) ;
}
static void F_8 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
struct V_1 * V_2 =
F_9 ( V_20 , struct V_1 , V_23 ) ;
enum V_3 V_4 ;
if ( V_22 == V_24 )
V_4 = V_25 ;
else if ( V_2 -> V_26 )
V_4 = V_27 ;
else
V_4 = V_28 ;
F_3 ( V_2 , V_4 ) ;
}
static int F_10 ( struct V_19 * V_20 ,
enum V_21 V_22 )
{
F_8 ( V_20 , V_22 ) ;
return 0 ;
}
static T_1 F_11 ( struct V_29 * V_30 ,
struct V_31 * V_32 ,
const char * V_33 , T_2 V_34 )
{
struct V_19 * V_20 = F_12 ( V_30 ) ;
struct V_1 * V_2 =
F_9 ( V_20 , struct V_1 , V_23 ) ;
int V_6 ;
unsigned long V_35 ;
V_6 = F_13 ( V_33 , 10 , & V_35 ) ;
if ( V_6 < 0 )
return V_6 ;
V_35 = ! ! V_35 ;
if ( V_2 -> V_26 == V_35 )
goto exit;
V_2 -> V_26 = V_35 ;
if ( ! F_14 ( V_20 ) )
goto exit;
if ( V_35 )
F_3 ( V_2 , V_27 ) ;
else
F_3 ( V_2 , V_28 ) ;
exit:
return V_34 ;
}
static T_1 F_15 ( struct V_29 * V_30 ,
struct V_31 * V_32 , char * V_36 )
{
struct V_19 * V_20 = F_12 ( V_30 ) ;
struct V_1 * V_2 =
F_9 ( V_20 , struct V_1 , V_23 ) ;
return sprintf ( V_36 , L_1 , V_2 -> V_26 ) ;
}
static int
F_16 ( struct V_37 * V_38 , struct V_1 * V_2 ,
const struct V_39 * V_40 )
{
int V_6 ;
enum V_3 V_4 ;
V_6 = F_17 ( & V_38 -> V_30 , V_40 -> V_10 ,
F_2 ( V_40 -> V_10 ) ?
V_41 : V_42 ,
V_40 -> V_43 ) ;
if ( V_6 ) {
F_18 ( & V_38 -> V_30 , L_2 ,
V_40 -> V_43 ) ;
return V_6 ;
}
V_6 = F_17 ( & V_38 -> V_30 , V_40 -> V_11 ,
F_2 ( V_40 -> V_11 ) ?
V_41 : V_42 ,
V_40 -> V_43 ) ;
if ( V_6 ) {
F_18 ( & V_38 -> V_30 , L_3 ,
V_40 -> V_43 ) ;
return V_6 ;
}
F_19 ( & V_2 -> V_16 ) ;
V_2 -> V_23 . V_43 = V_40 -> V_43 ;
V_2 -> V_23 . V_44 = V_40 -> V_44 ;
V_2 -> V_23 . V_45 = NULL ;
V_2 -> V_23 . V_15 |= V_46 ;
V_2 -> V_23 . V_47 = V_48 ;
V_2 -> V_10 = V_40 -> V_10 ;
V_2 -> V_11 = V_40 -> V_11 ;
V_2 -> V_17 = F_20 ( V_2 -> V_10 ) |
F_20 ( V_2 -> V_11 ) ;
if ( V_2 -> V_17 )
V_2 -> V_23 . V_49 = F_10 ;
else
V_2 -> V_23 . V_50 = F_8 ;
V_2 -> V_13 = V_40 -> V_13 ;
V_2 -> V_12 = V_40 -> V_12 ;
V_6 = F_1 ( V_2 , & V_4 ) ;
if ( V_6 < 0 )
return V_6 ;
V_2 -> V_26 = ( V_4 == V_27 ) ? 1 : 0 ;
V_2 -> V_23 . V_51 =
( V_4 == V_25 ) ? V_24 : V_52 ;
V_6 = F_21 ( & V_38 -> V_30 , & V_2 -> V_23 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static void F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_23 ) ;
}
static int
F_24 ( struct V_29 * V_30 , struct V_53 * V_54 )
{
struct V_55 * V_56 = V_30 -> V_57 ;
struct V_55 * V_58 ;
struct V_39 * V_59 , * V_60 ;
int V_61 = 0 ;
V_61 = F_25 ( V_56 ) ;
if ( ! V_61 )
return - V_62 ;
V_60 = F_26 ( V_30 , V_61 * sizeof( struct V_39 ) ,
V_63 ) ;
if ( ! V_60 )
return - V_64 ;
V_59 = V_60 ;
F_27 (np, child) {
const char * string ;
int V_6 , V_5 , V_12 ;
struct V_65 * V_13 ;
V_6 = F_28 ( V_58 , L_4 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_59 -> V_10 = V_6 ;
V_6 = F_28 ( V_58 , L_5 , 0 ) ;
if ( V_6 < 0 )
return V_6 ;
V_59 -> V_11 = V_6 ;
V_6 = F_29 ( V_58 , L_6 , & string ) ;
V_59 -> V_43 = ( V_6 == 0 ) ? string : V_58 -> V_43 ;
V_6 = F_29 ( V_58 , L_7 ,
& string ) ;
if ( V_6 == 0 )
V_59 -> V_44 = string ;
V_6 = F_30 ( V_58 , L_8 ) ;
if ( V_6 < 0 || V_6 % 3 ) {
F_18 ( V_30 ,
L_9 ) ;
return - V_7 ;
}
V_12 = V_6 / 3 ;
V_13 = F_26 ( V_30 ,
V_12 * sizeof( struct V_65 ) ,
V_63 ) ;
if ( ! V_13 )
return - V_64 ;
for ( V_5 = 0 ; V_5 < V_12 ; V_5 ++ ) {
F_31 ( V_58 ,
L_8 , 3 * V_5 ,
( V_66 * ) & V_13 [ V_5 ] . V_4 ) ;
F_31 ( V_58 ,
L_8 , 3 * V_5 + 1 ,
( V_66 * ) & V_13 [ V_5 ] . V_8 ) ;
F_31 ( V_58 ,
L_8 , 3 * V_5 + 2 ,
( V_66 * ) & V_13 [ V_5 ] . V_9 ) ;
}
V_59 -> V_12 = V_12 ;
V_59 -> V_13 = V_13 ;
V_59 ++ ;
}
V_54 -> V_60 = V_60 ;
V_54 -> V_61 = V_61 ;
return 0 ;
}
static inline int F_32 ( int V_61 )
{
return sizeof( struct V_67 ) +
( sizeof( struct V_1 ) * V_61 ) ;
}
static int F_33 ( struct V_37 * V_38 )
{
struct V_53 * V_54 = F_34 ( & V_38 -> V_30 ) ;
struct V_67 * V_68 ;
int V_5 ;
int V_6 ;
#ifdef F_35
if ( ! V_54 ) {
V_54 = F_26 ( & V_38 -> V_30 ,
sizeof( struct V_53 ) ,
V_63 ) ;
if ( ! V_54 )
return - V_64 ;
V_6 = F_24 ( & V_38 -> V_30 , V_54 ) ;
if ( V_6 )
return V_6 ;
}
#else
if ( ! V_54 )
return - V_7 ;
#endif
V_68 = F_26 ( & V_38 -> V_30 ,
F_32 ( V_54 -> V_61 ) , V_63 ) ;
if ( ! V_68 )
return - V_64 ;
V_68 -> V_61 = V_54 -> V_61 ;
for ( V_5 = 0 ; V_5 < V_68 -> V_61 ; V_5 ++ ) {
V_6 = F_16 ( V_38 , & V_68 -> V_69 [ V_5 ] ,
& V_54 -> V_60 [ V_5 ] ) ;
if ( V_6 < 0 ) {
for ( V_5 = V_5 - 1 ; V_5 >= 0 ; V_5 -- )
F_22 ( & V_68 -> V_69 [ V_5 ] ) ;
return V_6 ;
}
}
F_36 ( V_38 , V_68 ) ;
return 0 ;
}
static int F_37 ( struct V_37 * V_38 )
{
int V_5 ;
struct V_67 * V_68 ;
V_68 = F_38 ( V_38 ) ;
for ( V_5 = 0 ; V_5 < V_68 -> V_61 ; V_5 ++ )
F_22 ( & V_68 -> V_69 [ V_5 ] ) ;
return 0 ;
}
