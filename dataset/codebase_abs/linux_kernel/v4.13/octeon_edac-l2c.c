static void F_1 ( struct V_1 * V_2 )
{
union V_3 V_4 , V_5 ;
union V_6 V_7 , V_8 ;
V_5 . V_9 = 0 ;
V_4 . V_9 = F_2 ( V_10 ) ;
if ( V_4 . V_11 . V_12 ) {
F_3 ( V_2 , 0 , 0 ,
L_1 ) ;
V_5 . V_11 . V_12 = 1 ;
}
if ( V_4 . V_11 . V_13 ) {
F_4 ( V_2 , 0 , 0 ,
L_2 ) ;
V_5 . V_11 . V_13 = 1 ;
}
if ( V_5 . V_9 )
F_5 ( V_10 , V_5 . V_9 ) ;
V_8 . V_9 = 0 ;
V_7 . V_9 = F_2 ( V_14 ) ;
if ( V_7 . V_11 . V_12 ) {
F_3 ( V_2 , 0 , 1 ,
L_3 ) ;
V_8 . V_11 . V_12 = 1 ;
}
if ( V_7 . V_11 . V_13 ) {
F_4 ( V_2 , 0 , 1 ,
L_4 ) ;
V_8 . V_11 . V_13 = 1 ;
}
if ( V_8 . V_9 )
F_5 ( V_14 , V_8 . V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_15 )
{
union V_16 V_17 , V_18 ;
union V_19 V_20 , V_21 ;
char V_22 [ 64 ] ;
char V_23 [ 80 ] ;
V_18 . V_9 = 0 ;
V_17 . V_9 = F_2 ( F_7 ( V_15 ) ) ;
if ( V_17 . V_11 . V_24 || V_17 . V_11 . V_25 ||
V_17 . V_11 . V_26 || V_17 . V_11 . V_27 )
snprintf ( V_22 , sizeof( V_22 ) ,
L_5 ,
V_17 . V_11 . type , V_17 . V_11 . V_28 , V_17 . V_11 . V_29 ) ;
if ( V_17 . V_11 . V_24 ) {
snprintf ( V_23 , sizeof( V_23 ) ,
L_6 , V_22 ) ;
V_18 . V_11 . V_24 = 1 ;
F_4 ( V_2 , V_15 , 1 , V_23 ) ;
}
if ( V_17 . V_11 . V_25 ) {
snprintf ( V_23 , sizeof( V_23 ) ,
L_7 , V_22 ) ;
V_18 . V_11 . V_25 = 1 ;
F_3 ( V_2 , V_15 , 1 , V_23 ) ;
}
if ( V_17 . V_11 . V_26 ) {
snprintf ( V_23 , sizeof( V_23 ) ,
L_8 , V_22 ) ;
V_18 . V_11 . V_26 = 1 ;
F_4 ( V_2 , V_15 , 1 , V_23 ) ;
}
if ( V_17 . V_11 . V_27 ) {
snprintf ( V_23 , sizeof( V_23 ) ,
L_9 , V_22 ) ;
V_18 . V_11 . V_27 = 1 ;
F_3 ( V_2 , V_15 , 1 , V_23 ) ;
}
if ( V_18 . V_9 )
F_5 ( F_7 ( V_15 ) , V_18 . V_9 ) ;
V_21 . V_9 = 0 ;
V_20 . V_9 = F_2 ( F_8 ( V_15 ) ) ;
if ( V_20 . V_11 . V_24 || V_20 . V_11 . V_25 )
snprintf ( V_22 , sizeof( V_22 ) ,
L_5 ,
V_20 . V_11 . type , V_20 . V_11 . V_28 , V_20 . V_11 . V_29 ) ;
if ( V_20 . V_11 . V_24 ) {
snprintf ( V_23 , sizeof( V_23 ) ,
L_10 , V_22 ) ;
V_21 . V_11 . V_24 = 1 ;
F_4 ( V_2 , V_15 , 0 , V_23 ) ;
}
if ( V_20 . V_11 . V_25 ) {
snprintf ( V_23 , sizeof( V_23 ) ,
L_11 , V_22 ) ;
V_21 . V_11 . V_25 = 1 ;
F_3 ( V_2 , V_15 , 0 , V_23 ) ;
}
if ( V_21 . V_9 )
F_5 ( F_8 ( V_15 ) , V_21 . V_9 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_31 ; V_30 ++ )
F_6 ( V_2 , V_30 ) ;
}
static int F_10 ( struct V_32 * V_33 )
{
struct V_1 * V_2 ;
int V_34 = F_11 ( V_35 ) ? 4 : 1 ;
V_2 = F_12 ( 0 , L_12 , V_34 , L_12 , 2 , 0 ,
NULL , 0 , F_13 () ) ;
if ( ! V_2 )
return - V_36 ;
V_2 -> V_37 = & V_33 -> V_37 ;
F_14 ( V_33 , V_2 ) ;
V_2 -> V_38 = V_38 ( & V_33 -> V_37 ) ;
V_2 -> V_39 = L_13 ;
V_2 -> V_40 = L_14 ;
if ( F_15 () ) {
union V_3 V_4 ;
union V_6 V_7 ;
V_4 . V_9 = F_2 ( V_10 ) ;
V_4 . V_11 . V_41 = 0 ;
V_4 . V_11 . V_42 = 0 ;
F_5 ( V_10 , V_4 . V_9 ) ;
V_7 . V_9 = F_2 ( V_14 ) ;
V_7 . V_11 . V_41 = 0 ;
V_7 . V_11 . V_42 = 0 ;
F_5 ( V_10 , V_7 . V_9 ) ;
V_2 -> V_43 = F_1 ;
} else {
V_2 -> V_43 = F_9 ;
}
if ( F_16 ( V_2 ) > 0 ) {
F_17 ( L_15 , V_44 ) ;
goto V_45;
}
return 0 ;
V_45:
F_18 ( V_2 ) ;
return - V_46 ;
}
static int F_19 ( struct V_32 * V_33 )
{
struct V_1 * V_2 = F_20 ( V_33 ) ;
F_21 ( & V_33 -> V_37 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
