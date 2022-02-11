static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_2 ) ;
int V_5 = V_4 -> V_6 ;
F_3 ( V_4 -> V_7 , V_4 -> V_8 [ V_5 ] . V_9 ) ;
F_3 ( V_4 -> V_10 , V_4 -> V_8 [ V_5 ] . V_11 ) ;
}
static int F_4 ( struct V_3 * V_4 ,
enum V_12 * V_13 )
{
int V_5 ;
int V_14 = - V_15 ;
int V_9 ;
int V_11 ;
V_9 = F_5 ( V_4 -> V_7 ) ;
V_11 = F_5 ( V_4 -> V_10 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_16 ; V_5 ++ ) {
if ( V_9 == V_4 -> V_8 [ V_5 ] . V_9 &&
V_11 == V_4 -> V_8 [ V_5 ] . V_11 ) {
* V_13 = V_4 -> V_8 [ V_5 ] . V_13 ;
V_14 = 0 ;
break;
}
}
return V_14 ;
}
static void F_6 ( struct V_3 * V_4 ,
enum V_12 V_13 )
{
int V_5 ;
bool V_17 = false ;
unsigned long V_18 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_16 ; V_5 ++ )
if ( V_13 == V_4 -> V_8 [ V_5 ] . V_13 ) {
V_17 = true ;
break;
}
if ( ! V_17 )
return;
F_7 ( & V_4 -> V_19 , V_18 ) ;
if ( ! V_4 -> V_20 ) {
F_8 ( V_4 -> V_7 ,
V_4 -> V_8 [ V_5 ] . V_9 ) ;
F_8 ( V_4 -> V_10 ,
V_4 -> V_8 [ V_5 ] . V_11 ) ;
goto V_21;
}
V_4 -> V_6 = V_5 ;
F_9 ( & V_4 -> V_2 ) ;
V_21:
F_10 ( & V_4 -> V_19 , V_18 ) ;
}
static void F_11 ( struct V_22 * V_23 ,
enum V_24 V_25 )
{
struct V_3 * V_4 =
F_2 ( V_23 , struct V_3 , V_26 ) ;
enum V_12 V_13 ;
if ( V_25 == V_27 )
V_13 = V_28 ;
else if ( V_4 -> V_29 )
V_13 = V_30 ;
else
V_13 = V_31 ;
F_6 ( V_4 , V_13 ) ;
}
static T_1 F_12 ( struct V_32 * V_33 ,
struct V_34 * V_35 ,
const char * V_36 , T_2 V_37 )
{
struct V_22 * V_23 = F_13 ( V_33 ) ;
struct V_3 * V_4 =
F_2 ( V_23 , struct V_3 , V_26 ) ;
int V_14 ;
unsigned long V_38 ;
V_14 = F_14 ( V_36 , 10 , & V_38 ) ;
if ( V_14 < 0 )
return V_14 ;
V_38 = ! ! V_38 ;
if ( V_4 -> V_29 == V_38 )
goto exit;
V_4 -> V_29 = V_38 ;
if ( ! F_15 ( V_23 ) )
goto exit;
if ( V_38 )
F_6 ( V_4 , V_30 ) ;
else
F_6 ( V_4 , V_31 ) ;
exit:
return V_37 ;
}
static T_1 F_16 ( struct V_32 * V_33 ,
struct V_34 * V_35 , char * V_39 )
{
struct V_22 * V_23 = F_13 ( V_33 ) ;
struct V_3 * V_4 =
F_2 ( V_23 , struct V_3 , V_26 ) ;
return sprintf ( V_39 , L_1 , V_4 -> V_29 ) ;
}
static int
F_17 ( struct V_40 * V_41 , struct V_3 * V_4 ,
const struct V_42 * V_43 )
{
int V_14 ;
enum V_12 V_13 ;
V_14 = F_18 ( & V_41 -> V_33 , V_43 -> V_7 ,
F_5 ( V_43 -> V_7 ) ?
V_44 : V_45 ,
V_43 -> V_46 ) ;
if ( V_14 ) {
F_19 ( & V_41 -> V_33 , L_2 ,
V_43 -> V_46 ) ;
return V_14 ;
}
V_14 = F_18 ( & V_41 -> V_33 , V_43 -> V_10 ,
F_5 ( V_43 -> V_10 ) ?
V_44 : V_45 ,
V_43 -> V_46 ) ;
if ( V_14 ) {
F_19 ( & V_41 -> V_33 , L_3 ,
V_43 -> V_46 ) ;
return V_14 ;
}
F_20 ( & V_4 -> V_19 ) ;
V_4 -> V_26 . V_46 = V_43 -> V_46 ;
V_4 -> V_26 . V_47 = V_43 -> V_47 ;
V_4 -> V_26 . V_48 = NULL ;
V_4 -> V_26 . V_49 = F_11 ;
V_4 -> V_26 . V_18 |= V_50 ;
V_4 -> V_26 . V_51 = V_52 ;
V_4 -> V_7 = V_43 -> V_7 ;
V_4 -> V_10 = V_43 -> V_10 ;
V_4 -> V_20 = F_21 ( V_4 -> V_7 ) |
F_21 ( V_4 -> V_10 ) ;
V_4 -> V_8 = V_43 -> V_8 ;
V_4 -> V_16 = V_43 -> V_16 ;
V_14 = F_4 ( V_4 , & V_13 ) ;
if ( V_14 < 0 )
return V_14 ;
V_4 -> V_29 = ( V_13 == V_30 ) ? 1 : 0 ;
V_4 -> V_26 . V_53 =
( V_13 == V_28 ) ? V_27 : V_54 ;
F_22 ( & V_4 -> V_2 , F_1 ) ;
V_14 = F_23 ( & V_41 -> V_33 , & V_4 -> V_26 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static void F_24 ( struct V_3 * V_4 )
{
F_25 ( & V_4 -> V_26 ) ;
F_26 ( & V_4 -> V_2 ) ;
}
static int
F_27 ( struct V_32 * V_33 , struct V_55 * V_56 )
{
struct V_57 * V_58 = V_33 -> V_59 ;
struct V_57 * V_60 ;
struct V_42 * V_61 , * V_62 ;
int V_63 = 0 ;
V_63 = F_28 ( V_58 ) ;
if ( ! V_63 )
return - V_64 ;
V_62 = F_29 ( V_33 , V_63 * sizeof( struct V_42 ) ,
V_65 ) ;
if ( ! V_62 )
return - V_66 ;
V_61 = V_62 ;
F_30 (np, child) {
const char * string ;
int V_14 , V_5 , V_16 ;
struct V_67 * V_8 ;
V_14 = F_31 ( V_60 , L_4 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
V_61 -> V_7 = V_14 ;
V_14 = F_31 ( V_60 , L_5 , 0 ) ;
if ( V_14 < 0 )
return V_14 ;
V_61 -> V_10 = V_14 ;
V_14 = F_32 ( V_60 , L_6 , & string ) ;
V_61 -> V_46 = ( V_14 == 0 ) ? string : V_60 -> V_46 ;
V_14 = F_32 ( V_60 , L_7 ,
& string ) ;
if ( V_14 == 0 )
V_61 -> V_47 = string ;
V_14 = F_33 ( V_60 , L_8 ) ;
if ( V_14 < 0 || V_14 % 3 ) {
F_19 ( V_33 ,
L_9 ) ;
return - V_15 ;
}
V_16 = V_14 / 3 ;
V_8 = F_29 ( V_33 ,
V_16 * sizeof( struct V_67 ) ,
V_65 ) ;
if ( ! V_8 )
return - V_66 ;
for ( V_5 = 0 ; V_5 < V_16 ; V_5 ++ ) {
F_34 ( V_60 ,
L_8 , 3 * V_5 ,
( V_68 * ) & V_8 [ V_5 ] . V_13 ) ;
F_34 ( V_60 ,
L_8 , 3 * V_5 + 1 ,
( V_68 * ) & V_8 [ V_5 ] . V_9 ) ;
F_34 ( V_60 ,
L_8 , 3 * V_5 + 2 ,
( V_68 * ) & V_8 [ V_5 ] . V_11 ) ;
}
V_61 -> V_16 = V_16 ;
V_61 -> V_8 = V_8 ;
V_61 ++ ;
}
V_56 -> V_62 = V_62 ;
V_56 -> V_63 = V_63 ;
return 0 ;
}
static inline int F_35 ( int V_63 )
{
return sizeof( struct V_69 ) +
( sizeof( struct V_3 ) * V_63 ) ;
}
static int F_36 ( struct V_40 * V_41 )
{
struct V_55 * V_56 = F_37 ( & V_41 -> V_33 ) ;
struct V_69 * V_70 ;
int V_5 ;
int V_14 ;
#ifdef F_38
if ( ! V_56 ) {
V_56 = F_29 ( & V_41 -> V_33 ,
sizeof( struct V_55 ) ,
V_65 ) ;
if ( ! V_56 )
return - V_66 ;
V_14 = F_27 ( & V_41 -> V_33 , V_56 ) ;
if ( V_14 )
return V_14 ;
}
#else
if ( ! V_56 )
return - V_15 ;
#endif
V_70 = F_29 ( & V_41 -> V_33 ,
F_35 ( V_56 -> V_63 ) , V_65 ) ;
if ( ! V_70 )
return - V_66 ;
V_70 -> V_63 = V_56 -> V_63 ;
for ( V_5 = 0 ; V_5 < V_70 -> V_63 ; V_5 ++ ) {
V_14 = F_17 ( V_41 , & V_70 -> V_71 [ V_5 ] ,
& V_56 -> V_62 [ V_5 ] ) ;
if ( V_14 < 0 ) {
for ( V_5 = V_5 - 1 ; V_5 >= 0 ; V_5 -- )
F_24 ( & V_70 -> V_71 [ V_5 ] ) ;
return V_14 ;
}
}
F_39 ( V_41 , V_70 ) ;
return 0 ;
}
static int F_40 ( struct V_40 * V_41 )
{
int V_5 ;
struct V_69 * V_70 ;
V_70 = F_41 ( V_41 ) ;
for ( V_5 = 0 ; V_5 < V_70 -> V_63 ; V_5 ++ )
F_24 ( & V_70 -> V_71 [ V_5 ] ) ;
return 0 ;
}
