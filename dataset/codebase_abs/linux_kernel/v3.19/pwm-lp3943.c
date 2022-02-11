static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_5 *
F_3 ( struct V_1 * V_1 , int V_6 )
{
struct V_7 * V_8 = V_1 -> V_8 ;
struct V_9 * V_9 = V_1 -> V_9 ;
struct V_5 * V_10 ;
int V_11 , V_12 ;
V_10 = F_4 ( sizeof( * V_10 ) , V_13 ) ;
if ( ! V_10 )
return F_5 ( - V_14 ) ;
V_10 -> V_15 = V_8 -> V_16 [ V_6 ] -> V_15 ;
V_10 -> V_17 = V_8 -> V_16 [ V_6 ] -> V_17 ;
for ( V_11 = 0 ; V_11 < V_10 -> V_17 ; V_11 ++ ) {
V_12 = V_10 -> V_15 [ V_11 ] ;
if ( F_6 ( V_12 , & V_9 -> V_18 ) ) {
F_7 ( V_10 ) ;
return F_5 ( - V_19 ) ;
}
}
return V_10 ;
}
static int F_8 ( struct V_2 * V_4 , struct V_20 * V_21 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_5 * V_10 ;
V_10 = F_3 ( V_1 , V_21 -> V_6 ) ;
if ( F_9 ( V_10 ) )
return F_10 ( V_10 ) ;
return F_11 ( V_21 , V_10 ) ;
}
static void F_12 ( struct V_1 * V_1 ,
struct V_5 * V_10 )
{
struct V_9 * V_9 = V_1 -> V_9 ;
int V_11 , V_12 ;
for ( V_11 = 0 ; V_11 < V_10 -> V_17 ; V_11 ++ ) {
V_12 = V_10 -> V_15 [ V_11 ] ;
F_13 ( V_12 , & V_9 -> V_18 ) ;
}
F_7 ( V_10 ) ;
}
static void F_14 ( struct V_2 * V_4 , struct V_20 * V_21 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_5 * V_10 = F_15 ( V_21 ) ;
F_12 ( V_1 , V_10 ) ;
}
static int F_16 ( struct V_2 * V_4 , struct V_20 * V_21 ,
int V_22 , int V_23 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_9 * V_9 = V_1 -> V_9 ;
T_1 V_24 , V_25 , V_26 ;
int V_27 ;
if ( V_21 -> V_6 == 0 ) {
V_26 = V_28 ;
V_25 = V_29 ;
} else {
V_26 = V_30 ;
V_25 = V_31 ;
}
V_23 = F_17 ( V_23 , V_32 , V_33 ) ;
V_24 = ( T_1 ) ( V_23 / V_32 - 1 ) ;
V_27 = F_18 ( V_9 , V_26 , V_24 ) ;
if ( V_27 )
return V_27 ;
V_24 = ( T_1 ) ( V_22 * V_34 / V_23 ) ;
return F_18 ( V_9 , V_25 , V_24 ) ;
}
static int F_19 ( struct V_1 * V_1 ,
struct V_5 * V_10 ,
T_1 V_24 )
{
struct V_9 * V_9 = V_1 -> V_9 ;
const struct V_35 * V_36 = V_9 -> V_37 ;
int V_11 , V_38 , V_27 ;
for ( V_11 = 0 ; V_11 < V_10 -> V_17 ; V_11 ++ ) {
V_38 = V_10 -> V_15 [ V_11 ] ;
V_27 = F_20 ( V_9 , V_36 [ V_38 ] . V_39 ,
V_36 [ V_38 ] . V_40 ,
V_24 << V_36 [ V_38 ] . V_41 ) ;
if ( V_27 )
return V_27 ;
}
return 0 ;
}
static int F_21 ( struct V_2 * V_4 , struct V_20 * V_21 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_5 * V_10 = F_15 ( V_21 ) ;
T_1 V_24 ;
if ( V_21 -> V_6 == 0 )
V_24 = V_42 ;
else
V_24 = V_43 ;
return F_19 ( V_1 , V_10 , V_24 ) ;
}
static void F_22 ( struct V_2 * V_4 , struct V_20 * V_21 )
{
struct V_1 * V_1 = F_1 ( V_4 ) ;
struct V_5 * V_10 = F_15 ( V_21 ) ;
F_19 ( V_1 , V_10 , V_44 ) ;
}
static int F_23 ( struct V_45 * V_46 ,
struct V_1 * V_1 )
{
static const char * const V_47 [] = { L_1 , L_2 , } ;
struct V_48 * V_49 = V_46 -> V_50 ;
struct V_7 * V_8 ;
struct V_5 * V_10 ;
enum V_51 * V_15 ;
int V_11 , V_27 , V_52 , V_53 = 0 ;
T_2 V_17 ;
if ( ! V_49 )
return - V_54 ;
V_8 = F_24 ( V_46 , sizeof( * V_8 ) , V_13 ) ;
if ( ! V_8 )
return - V_14 ;
for ( V_11 = 0 ; V_11 < V_55 ; V_11 ++ ) {
if ( ! F_25 ( V_49 , V_47 [ V_11 ] , & V_52 ) )
continue;
V_17 = V_52 / sizeof( T_2 ) ;
if ( V_17 == 0 )
continue;
V_15 = F_24 ( V_46 , sizeof( * V_15 ) * V_17 ,
V_13 ) ;
if ( ! V_15 )
return - V_14 ;
V_27 = F_26 ( V_49 , V_47 [ V_11 ] , V_15 ,
V_17 ) ;
if ( V_27 )
return V_27 ;
V_10 = F_24 ( V_46 , sizeof( * V_10 ) , V_13 ) ;
if ( ! V_10 )
return - V_14 ;
V_10 -> V_15 = V_15 ;
V_10 -> V_17 = V_17 ;
V_8 -> V_16 [ V_11 ] = V_10 ;
V_53 ++ ;
}
if ( V_53 == 0 )
return - V_56 ;
V_1 -> V_8 = V_8 ;
return 0 ;
}
static int F_27 ( struct V_57 * V_58 )
{
struct V_9 * V_9 = F_28 ( V_58 -> V_46 . V_59 ) ;
struct V_1 * V_1 ;
int V_60 ;
V_1 = F_24 ( & V_58 -> V_46 , sizeof( * V_1 ) , V_13 ) ;
if ( ! V_1 )
return - V_14 ;
V_1 -> V_8 = V_9 -> V_8 ;
if ( ! V_1 -> V_8 ) {
if ( F_29 ( V_61 ) )
V_60 = F_23 ( & V_58 -> V_46 , V_1 ) ;
else
V_60 = - V_62 ;
if ( V_60 )
return V_60 ;
}
V_1 -> V_9 = V_9 ;
V_1 -> V_4 . V_46 = & V_58 -> V_46 ;
V_1 -> V_4 . V_63 = & V_64 ;
V_1 -> V_4 . V_65 = V_55 ;
V_1 -> V_4 . V_66 = true ;
F_30 ( V_58 , V_1 ) ;
return F_31 ( & V_1 -> V_4 ) ;
}
static int F_32 ( struct V_57 * V_58 )
{
struct V_1 * V_1 = F_33 ( V_58 ) ;
return F_34 ( & V_1 -> V_4 ) ;
}
