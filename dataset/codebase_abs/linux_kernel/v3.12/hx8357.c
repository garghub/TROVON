static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_2 V_4 ,
T_1 * V_5 , T_2 V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 V_10 ;
struct V_11 V_12 [ 2 ] ;
T_2 * V_13 = NULL ;
int V_14 = 0 ;
memset ( V_12 , 0 , sizeof( V_12 ) ) ;
F_3 ( & V_10 ) ;
if ( V_4 ) {
int V_15 ;
V_13 = F_4 ( V_4 , sizeof( * V_13 ) , V_16 ) ;
if ( ! V_13 )
return - V_17 ;
for ( V_15 = 0 ; V_15 < V_4 ; V_15 ++ ) {
V_13 [ V_15 ] = V_3 [ V_15 ] ;
if ( V_15 > 0 )
V_13 [ V_15 ] |= 1 << 8 ;
}
V_12 [ 0 ] . V_18 = 2 * V_4 ;
V_12 [ 0 ] . V_19 = 9 ;
V_12 [ 0 ] . V_20 = V_13 ;
F_5 ( & V_12 [ 0 ] , & V_10 ) ;
}
if ( V_6 ) {
V_12 [ 1 ] . V_18 = V_6 ;
V_12 [ 1 ] . V_19 = 8 ;
V_12 [ 1 ] . V_21 = V_5 ;
F_5 ( & V_12 [ 1 ] , & V_10 ) ;
}
V_14 = F_6 ( V_8 -> V_22 , & V_10 ) ;
if ( V_14 < 0 )
F_7 ( & V_2 -> V_23 , L_1 ) ;
if ( V_4 )
F_8 ( V_13 ) ;
return V_14 ;
}
static inline int F_9 ( struct V_1 * V_2 ,
T_1 * V_24 , T_1 V_18 )
{
return F_1 ( V_2 , V_24 , V_18 , NULL , 0 ) ;
}
static inline int F_10 ( struct V_1 * V_2 ,
T_1 V_24 )
{
return F_1 ( V_2 , & V_24 , 1 , NULL , 0 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_10 ( V_2 , V_25 ) ;
if ( V_14 < 0 )
return V_14 ;
F_12 ( 10000 , 12000 ) ;
V_14 = F_10 ( V_2 , V_26 ) ;
if ( V_14 < 0 )
return V_14 ;
F_13 ( 120 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_10 ( V_2 , V_27 ) ;
if ( V_14 < 0 )
return V_14 ;
F_13 ( 120 ) ;
V_14 = F_10 ( V_2 , V_28 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_16 ( V_8 -> V_29 , 1 ) ;
F_12 ( 10000 , 12000 ) ;
F_16 ( V_8 -> V_29 , 0 ) ;
F_12 ( 10000 , 12000 ) ;
F_16 ( V_8 -> V_29 , 1 ) ;
F_13 ( 120 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_14 ;
if ( V_8 -> V_30 ) {
F_18 ( V_8 -> V_31 [ 0 ] , 1 ) ;
F_18 ( V_8 -> V_31 [ 1 ] , 0 ) ;
F_18 ( V_8 -> V_31 [ 2 ] , 1 ) ;
}
V_14 = F_9 ( V_2 , V_32 ,
F_19 ( V_32 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_33 ,
F_19 ( V_33 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_34 ,
F_19 ( V_34 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_35 ,
F_19 ( V_35 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_36 ,
F_19 ( V_36 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_37 ,
F_19 ( V_37 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_38 ,
F_19 ( V_38 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_39 ,
F_19 ( V_39 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_40 ,
F_19 ( V_40 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_41 ,
F_19 ( V_41 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_42 ,
F_19 ( V_42 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_43 ,
F_19 ( V_43 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_44 ,
F_19 ( V_44 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_45 ,
F_19 ( V_45 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_46 ,
F_19 ( V_46 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_10 ( V_2 , V_27 ) ;
if ( V_14 < 0 )
return V_14 ;
F_13 ( 120 ) ;
V_14 = F_10 ( V_2 , V_28 ) ;
if ( V_14 < 0 )
return V_14 ;
F_12 ( 5000 , 7000 ) ;
V_14 = F_10 ( V_2 , V_47 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_9 ( V_2 , V_48 ,
F_19 ( V_48 ) ) ;
if ( V_14 < 0 )
return V_14 ;
F_12 ( 10000 , 12000 ) ;
V_14 = F_9 ( V_2 , V_49 ,
F_19 ( V_49 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_50 ,
F_19 ( V_50 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_51 ,
F_19 ( V_51 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_52 ,
F_19 ( V_52 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_53 ,
F_19 ( V_53 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 , V_54 ,
F_19 ( V_54 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_10 ( V_2 , V_27 ) ;
if ( V_14 < 0 )
return V_14 ;
F_13 ( 120 ) ;
V_14 = F_9 ( V_2 , V_55 ,
F_19 ( V_55 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_10 ( V_2 , V_27 ) ;
if ( V_14 < 0 )
return V_14 ;
F_12 ( 1000 , 1200 ) ;
V_14 = F_9 ( V_2 , V_56 ,
F_19 ( V_56 ) ) ;
if ( V_14 < 0 )
return V_14 ;
F_12 ( 10000 , 12000 ) ;
V_14 = F_9 ( V_2 ,
V_57 ,
F_19 ( V_57 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_9 ( V_2 ,
V_58 ,
F_19 ( V_58 ) ) ;
if ( V_14 < 0 )
return V_14 ;
F_12 ( 10000 , 12000 ) ;
V_14 = F_9 ( V_2 , V_59 ,
F_19 ( V_59 ) ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_10 ( V_2 , V_28 ) ;
if ( V_14 < 0 )
return V_14 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 , int V_60 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_14 = 0 ;
if ( F_22 ( V_60 ) && ! F_22 ( V_8 -> V_61 ) )
V_14 = F_14 ( V_2 ) ;
else if ( ! F_22 ( V_60 ) && F_22 ( V_8 -> V_61 ) )
V_14 = F_11 ( V_2 ) ;
if ( V_14 == 0 )
V_8 -> V_61 = V_60 ;
else
F_23 ( & V_2 -> V_23 , L_2 , V_60 ) ;
return V_14 ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
return V_8 -> V_61 ;
}
static int F_25 ( struct V_62 * V_22 )
{
struct V_1 * V_2 ;
struct V_7 * V_8 ;
const struct V_63 * V_64 ;
int V_15 , V_14 ;
V_8 = F_26 ( & V_22 -> V_23 , sizeof( * V_8 ) , V_16 ) ;
if ( ! V_8 ) {
F_7 ( & V_22 -> V_23 , L_3 ) ;
return - V_17 ;
}
V_14 = F_27 ( V_22 ) ;
if ( V_14 < 0 ) {
F_7 ( & V_22 -> V_23 , L_4 ) ;
return V_14 ;
}
V_8 -> V_22 = V_22 ;
V_64 = F_28 ( V_65 , & V_22 -> V_23 ) ;
if ( ! V_64 || ! V_64 -> V_66 )
return - V_67 ;
V_8 -> V_29 = F_29 ( V_22 -> V_23 . V_68 , L_5 , 0 ) ;
if ( ! F_30 ( V_8 -> V_29 ) ) {
F_7 ( & V_22 -> V_23 , L_6 ) ;
return - V_67 ;
}
V_14 = F_31 ( & V_22 -> V_23 , V_8 -> V_29 ,
V_69 ,
L_7 ) ;
if ( V_14 ) {
F_7 ( & V_22 -> V_23 ,
L_8 ,
V_8 -> V_29 , V_14 ) ;
return - V_67 ;
}
if ( F_32 ( V_22 -> V_23 . V_68 , L_9 , NULL ) ) {
V_8 -> V_30 = 1 ;
for ( V_15 = 0 ; V_15 < V_70 ; V_15 ++ ) {
V_8 -> V_31 [ V_15 ] = F_29 ( V_22 -> V_23 . V_68 ,
L_9 , V_15 ) ;
if ( V_8 -> V_31 [ V_15 ] == - V_71 ) {
F_33 ( & V_22 -> V_23 , L_10 ) ;
return - V_71 ;
}
if ( ! F_30 ( V_8 -> V_31 [ V_15 ] ) ) {
F_7 ( & V_22 -> V_23 , L_11 ) ;
return - V_67 ;
}
V_14 = F_31 ( & V_22 -> V_23 , V_8 -> V_31 [ V_15 ] ,
V_72 ,
L_12 ) ;
if ( V_14 ) {
F_7 ( & V_22 -> V_23 , L_8 ,
V_8 -> V_31 [ V_15 ] , V_14 ) ;
return - V_67 ;
}
}
} else {
V_8 -> V_30 = 0 ;
}
V_2 = F_34 ( L_13 , & V_22 -> V_23 , V_8 , & V_73 ) ;
if ( F_35 ( V_2 ) ) {
V_14 = F_36 ( V_2 ) ;
return V_14 ;
}
F_37 ( V_22 , V_2 ) ;
F_15 ( V_2 ) ;
V_14 = ( ( int ( * ) ( struct V_1 * ) ) V_64 -> V_66 ) ( V_2 ) ;
if ( V_14 ) {
F_7 ( & V_22 -> V_23 , L_14 ) ;
goto V_74;
}
F_33 ( & V_22 -> V_23 , L_15 ) ;
return 0 ;
V_74:
F_38 ( V_2 ) ;
return V_14 ;
}
static int F_39 ( struct V_62 * V_22 )
{
struct V_1 * V_2 = F_40 ( V_22 ) ;
F_38 ( V_2 ) ;
return 0 ;
}
