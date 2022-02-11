static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 V_5 ;
unsigned int V_6 ;
int V_7 ;
F_3 ( V_4 -> V_8 , & V_5 ) ;
V_6 = F_4 ( & V_5 , 100 ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_9 -> V_10 ; V_7 ++ ) {
if ( V_6 == V_4 -> V_11 [ V_7 ] . V_6 ) {
V_4 -> V_12 = V_7 ;
return;
}
}
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_12 < 0 )
F_1 ( V_2 ) ;
return V_4 -> V_12 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 V_14 ;
int V_15 ;
F_7 ( V_4 -> V_8 , & V_14 ) ;
F_8 ( & V_14 ,
V_4 -> V_11 [ V_13 ] . V_6 , 100 ) ;
V_15 = F_9 ( V_4 -> V_8 , & V_14 ) ;
if ( V_15 ) {
F_10 ( & V_2 -> V_16 , L_1 , V_15 ) ;
return V_15 ;
}
V_4 -> V_12 = V_13 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_13 >= V_2 -> V_9 -> V_10 )
return - V_17 ;
return V_4 -> V_11 [ V_13 ] . V_18 ;
}
static int F_12 ( struct V_1 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_16 ) ;
if ( V_4 -> V_19 )
F_13 ( V_4 -> V_19 , 1 ) ;
return F_14 ( V_4 -> V_8 ) ;
}
static int F_15 ( struct V_1 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_16 ) ;
F_16 ( V_4 -> V_8 ) ;
if ( V_4 -> V_19 )
F_13 ( V_4 -> V_19 , 0 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_16 )
{
struct V_3 * V_4 = F_2 ( V_16 ) ;
if ( V_4 -> V_19 && ! F_18 ( V_4 -> V_19 ) )
return false ;
return F_19 ( V_4 -> V_8 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_20 = V_4 -> V_21 . V_22 ;
unsigned int V_23 = V_4 -> V_21 . V_24 ;
unsigned int V_25 = V_4 -> V_21 . V_26 ;
int V_27 = V_2 -> V_28 -> V_27 ;
int V_29 = V_2 -> V_28 -> V_29 ;
int V_30 = V_29 - V_27 ;
struct V_5 V_14 ;
unsigned int V_31 ;
unsigned int V_32 ;
F_3 ( V_4 -> V_8 , & V_14 ) ;
V_32 = F_4 ( & V_14 , V_25 ) ;
if ( V_23 < V_20 ) {
V_32 = V_20 - V_32 ;
V_31 = V_20 - V_23 ;
} else {
V_32 = V_32 - V_20 ;
V_31 = V_23 - V_20 ;
}
V_32 = F_21 ( ( V_33 ) V_32 * V_30 , V_31 ) ;
return V_32 + V_27 ;
}
static int F_22 ( struct V_1 * V_2 ,
int V_34 , int V_35 ,
unsigned int * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_20 = V_4 -> V_21 . V_22 ;
unsigned int V_23 = V_4 -> V_21 . V_24 ;
unsigned int V_25 = V_4 -> V_21 . V_26 ;
unsigned int V_36 = V_2 -> V_28 -> V_36 ;
int V_27 = V_2 -> V_28 -> V_27 ;
int V_29 = V_2 -> V_28 -> V_29 ;
int V_30 = V_29 - V_27 ;
struct V_5 V_14 ;
int V_37 = F_20 ( V_2 ) ;
unsigned int V_31 ;
unsigned int V_6 ;
int V_15 ;
F_7 ( V_4 -> V_8 , & V_14 ) ;
if ( V_23 < V_20 )
V_31 = V_20 - V_23 ;
else
V_31 = V_23 - V_20 ;
V_6 = F_21 ( ( V_33 ) ( V_34 - V_27 ) *
V_31 ,
V_30 ) ;
if ( V_23 < V_20 )
V_6 = V_20 - V_6 ;
else
V_6 = V_20 + V_6 ;
F_8 ( & V_14 , V_6 , V_25 ) ;
V_15 = F_9 ( V_4 -> V_8 , & V_14 ) ;
if ( V_15 ) {
F_10 ( & V_2 -> V_16 , L_1 , V_15 ) ;
return V_15 ;
}
if ( ( V_36 == 0 ) || ! F_17 ( V_2 ) )
return 0 ;
V_36 = F_23 ( abs ( V_34 - V_37 ) , V_36 ) ;
F_24 ( V_36 , V_36 + F_23 ( V_36 , 10 ) ) ;
return 0 ;
}
static int F_25 ( struct V_38 * V_39 ,
struct V_3 * V_4 )
{
struct V_40 * V_41 = V_39 -> V_16 . V_42 ;
struct V_43 * V_11 ;
unsigned int V_44 = 0 ;
int V_15 ;
F_26 ( V_41 , L_2 , & V_44 ) ;
if ( ( V_44 < sizeof( * V_11 ) ) ||
( V_44 % sizeof( * V_11 ) ) ) {
F_10 ( & V_39 -> V_16 , L_3 ,
V_44 ) ;
return - V_17 ;
}
V_11 = F_27 ( & V_39 -> V_16 , V_44 , V_45 ) ;
if ( ! V_11 )
return - V_46 ;
V_15 = F_28 ( V_41 , L_2 ,
( V_47 * ) V_11 ,
V_44 / sizeof( V_47 ) ) ;
if ( V_15 ) {
F_10 ( & V_39 -> V_16 , L_4 , V_15 ) ;
return V_15 ;
}
V_4 -> V_12 = - V_17 ;
V_4 -> V_11 = V_11 ;
memcpy ( & V_4 -> V_48 , & V_49 ,
sizeof( V_4 -> V_48 ) ) ;
V_4 -> V_9 . V_48 = & V_4 -> V_48 ;
V_4 -> V_9 . V_10 = V_44 / sizeof( * V_11 ) ;
return 0 ;
}
static int F_29 ( struct V_38 * V_39 ,
struct V_3 * V_4 )
{
V_47 V_50 [ 2 ] = { 0 , 100 } ;
V_47 V_26 = 100 ;
memcpy ( & V_4 -> V_48 , & V_51 ,
sizeof( V_4 -> V_48 ) ) ;
V_4 -> V_9 . V_48 = & V_4 -> V_48 ;
V_4 -> V_9 . V_52 = true ;
F_28 ( V_39 -> V_16 . V_42 ,
L_5 ,
V_50 , 2 ) ;
F_30 ( V_39 -> V_16 . V_42 , L_6 ,
& V_26 ) ;
if ( V_50 [ 0 ] > V_26 ||
V_50 [ 1 ] > V_26 )
return - V_17 ;
V_4 -> V_21 . V_26 = V_26 ;
V_4 -> V_21 . V_22 = V_50 [ 0 ] ;
V_4 -> V_21 . V_24 = V_50 [ 1 ] ;
return 0 ;
}
static int F_31 ( struct V_38 * V_39 )
{
const struct V_53 * V_54 ;
struct V_3 * V_4 ;
struct V_1 * V_55 ;
struct V_56 V_57 = { } ;
struct V_40 * V_41 = V_39 -> V_16 . V_42 ;
enum V_58 V_59 ;
int V_15 ;
if ( ! V_41 ) {
F_10 ( & V_39 -> V_16 , L_7 ) ;
return - V_17 ;
}
V_4 = F_27 ( & V_39 -> V_16 , sizeof( * V_4 ) , V_45 ) ;
if ( ! V_4 )
return - V_46 ;
memcpy ( & V_4 -> V_9 , & V_60 , sizeof( V_4 -> V_9 ) ) ;
if ( F_26 ( V_41 , L_2 , NULL ) )
V_15 = F_25 ( V_39 , V_4 ) ;
else
V_15 = F_29 ( V_39 , V_4 ) ;
if ( V_15 )
return V_15 ;
V_54 = F_32 ( & V_39 -> V_16 , V_41 ,
& V_4 -> V_9 ) ;
if ( ! V_54 )
return - V_46 ;
V_57 . V_42 = V_41 ;
V_57 . V_16 = & V_39 -> V_16 ;
V_57 . V_61 = V_4 ;
V_57 . V_54 = V_54 ;
V_4 -> V_8 = F_33 ( & V_39 -> V_16 , NULL ) ;
if ( F_34 ( V_4 -> V_8 ) ) {
V_15 = F_35 ( V_4 -> V_8 ) ;
F_10 ( & V_39 -> V_16 , L_8 , V_15 ) ;
return V_15 ;
}
if ( V_54 -> V_28 . V_62 || V_54 -> V_28 . V_63 )
V_59 = V_64 ;
else
V_59 = V_65 ;
V_4 -> V_19 = F_36 ( & V_39 -> V_16 , L_9 ,
V_59 ) ;
if ( F_34 ( V_4 -> V_19 ) ) {
V_15 = F_35 ( V_4 -> V_19 ) ;
F_10 ( & V_39 -> V_16 , L_10 , V_15 ) ;
return V_15 ;
}
V_15 = F_37 ( V_4 -> V_8 ) ;
if ( V_15 )
return V_15 ;
V_55 = F_38 ( & V_39 -> V_16 ,
& V_4 -> V_9 , & V_57 ) ;
if ( F_34 ( V_55 ) ) {
V_15 = F_35 ( V_55 ) ;
F_10 ( & V_39 -> V_16 , L_11 ,
V_4 -> V_9 . V_66 , V_15 ) ;
return V_15 ;
}
return 0 ;
}
