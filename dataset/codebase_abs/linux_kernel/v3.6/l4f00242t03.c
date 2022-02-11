static void F_1 ( unsigned int V_1 )
{
F_2 ( L_1 ) ;
F_3 ( V_1 , 1 ) ;
F_4 ( 100 ) ;
F_3 ( V_1 , 0 ) ;
F_4 ( 10 ) ;
F_3 ( V_1 , 1 ) ;
F_4 ( 20 ) ;
}
static void F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 . V_7 ;
struct V_8 * V_9 = F_6 ( & V_3 -> V_6 ) ;
const T_1 V_10 [] = { 0x36 , F_7 ( 0 ) , 0x3A , F_7 ( 0x60 ) } ;
F_8 ( & V_3 -> V_6 , L_2 ) ;
F_9 ( V_9 -> V_11 , 1800000 , 1800000 ) ;
F_10 ( V_9 -> V_11 ) ;
F_9 ( V_9 -> V_12 , 2800000 , 2800000 ) ;
F_10 ( V_9 -> V_12 ) ;
F_1 ( V_5 -> V_13 ) ;
F_3 ( V_5 -> V_14 , 1 ) ;
F_11 ( 60 ) ;
F_12 ( V_3 , ( const V_15 * ) V_10 , F_13 ( V_10 ) * sizeof( T_1 ) ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_3 -> V_6 . V_7 ;
struct V_8 * V_9 = F_6 ( & V_3 -> V_6 ) ;
F_8 ( & V_3 -> V_6 , L_3 ) ;
F_3 ( V_5 -> V_14 , 0 ) ;
F_15 ( V_9 -> V_11 ) ;
F_15 ( V_9 -> V_12 ) ;
}
static int F_16 ( struct V_16 * V_17 )
{
struct V_8 * V_9 = F_17 ( V_17 ) ;
return V_9 -> V_18 ;
}
static int F_18 ( struct V_16 * V_17 , int V_19 )
{
struct V_8 * V_9 = F_17 ( V_17 ) ;
struct V_2 * V_3 = V_9 -> V_3 ;
const T_1 V_20 = 0x11 ;
const T_1 V_21 = 0x29 ;
const T_1 V_22 = 0x10 ;
const T_1 V_23 = 0x28 ;
if ( V_19 <= V_24 ) {
if ( V_9 -> V_18 <= V_24 ) {
} else if ( V_9 -> V_18 < V_25 ) {
F_8 ( & V_3 -> V_6 , L_4 ) ;
F_12 ( V_3 , ( const V_15 * ) & V_20 , sizeof( T_1 ) ) ;
F_11 ( 60 ) ;
F_12 ( V_3 , ( const V_15 * ) & V_21 , sizeof( T_1 ) ) ;
} else {
F_5 ( V_3 ) ;
V_9 -> V_18 = V_26 ;
F_18 ( V_9 -> V_17 , V_19 ) ;
}
} else if ( V_19 < V_25 ) {
if ( V_9 -> V_18 <= V_24 ) {
F_8 ( & V_3 -> V_6 , L_5 ) ;
F_12 ( V_3 , ( const V_15 * ) & V_23 , sizeof( T_1 ) ) ;
F_11 ( 60 ) ;
F_12 ( V_3 , ( const V_15 * ) & V_22 , sizeof( T_1 ) ) ;
} else if ( V_9 -> V_18 < V_25 ) {
} else {
F_5 ( V_3 ) ;
V_9 -> V_18 = V_27 ;
F_18 ( V_17 , V_19 ) ;
}
} else {
if ( V_9 -> V_18 != V_25 ) {
F_12 ( V_3 , ( const V_15 * ) & V_23 , sizeof( T_1 ) ) ;
F_11 ( 60 ) ;
F_14 ( V_3 ) ;
}
}
V_9 -> V_18 = V_19 ;
return 0 ;
}
static int T_2 F_19 ( struct V_2 * V_3 )
{
struct V_8 * V_9 ;
struct V_4 * V_5 = V_3 -> V_6 . V_7 ;
int V_28 ;
if ( V_5 == NULL ) {
F_20 ( & V_3 -> V_6 , L_6 ) ;
return - V_29 ;
}
V_9 = F_21 ( & V_3 -> V_6 , sizeof( struct V_8 ) ,
V_30 ) ;
if ( V_9 == NULL ) {
F_20 ( & V_3 -> V_6 , L_7 ) ;
return - V_31 ;
}
F_22 ( & V_3 -> V_6 , V_9 ) ;
V_3 -> V_32 = 9 ;
F_23 ( V_3 ) ;
V_9 -> V_3 = V_3 ;
V_28 = F_24 ( & V_3 -> V_6 , V_5 -> V_13 ,
V_33 , L_8 ) ;
if ( V_28 ) {
F_20 ( & V_3 -> V_6 ,
L_9 ) ;
return V_28 ;
}
V_28 = F_24 ( & V_3 -> V_6 , V_5 -> V_14 ,
V_34 , L_10 ) ;
if ( V_28 ) {
F_20 ( & V_3 -> V_6 ,
L_11 ) ;
return V_28 ;
}
V_9 -> V_11 = F_25 ( & V_3 -> V_6 , L_12 ) ;
if ( F_26 ( V_9 -> V_11 ) ) {
F_20 ( & V_3 -> V_6 , L_13 ,
V_35 ) ;
return F_27 ( V_9 -> V_11 ) ;
}
V_9 -> V_12 = F_25 ( & V_3 -> V_6 , L_14 ) ;
if ( F_26 ( V_9 -> V_12 ) ) {
V_28 = F_27 ( V_9 -> V_12 ) ;
F_20 ( & V_3 -> V_6 , L_15 ,
V_35 ) ;
goto V_36;
}
V_9 -> V_17 = F_28 ( L_16 ,
& V_3 -> V_6 , V_9 , & V_37 ) ;
if ( F_26 ( V_9 -> V_17 ) ) {
V_28 = F_27 ( V_9 -> V_17 ) ;
goto V_38;
}
F_5 ( V_3 ) ;
V_9 -> V_18 = V_26 ;
F_18 ( V_9 -> V_17 , V_27 ) ;
F_29 ( & V_3 -> V_6 , L_17 ) ;
return 0 ;
V_38:
F_30 ( V_9 -> V_12 ) ;
V_36:
F_30 ( V_9 -> V_11 ) ;
return V_28 ;
}
static int T_3 F_31 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_6 ( & V_3 -> V_6 ) ;
F_18 ( V_9 -> V_17 , V_25 ) ;
F_32 ( V_9 -> V_17 ) ;
F_22 ( & V_3 -> V_6 , NULL ) ;
F_30 ( V_9 -> V_11 ) ;
F_30 ( V_9 -> V_12 ) ;
return 0 ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_8 * V_9 = F_6 ( & V_3 -> V_6 ) ;
if ( V_9 )
F_18 ( V_9 -> V_17 , V_25 ) ;
}
