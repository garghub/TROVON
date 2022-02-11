struct V_1 * F_1 ( int V_2 , const char * V_3 )
{
struct V_1 * V_4 = NULL ;
F_2 ( & V_5 ) ;
F_3 (ssp, &ssp_list, node) {
if ( V_4 -> V_6 == V_2 && V_4 -> V_7 == 0 ) {
V_4 -> V_7 ++ ;
V_4 -> V_3 = V_3 ;
break;
}
}
F_4 ( & V_5 ) ;
if ( & V_4 -> V_8 == & V_9 )
return NULL ;
return V_4 ;
}
struct V_1 * F_5 ( const struct V_10 * V_11 ,
const char * V_3 )
{
struct V_1 * V_4 = NULL ;
F_2 ( & V_5 ) ;
F_3 (ssp, &ssp_list, node) {
if ( V_4 -> V_11 == V_11 && V_4 -> V_7 == 0 ) {
V_4 -> V_7 ++ ;
V_4 -> V_3 = V_3 ;
break;
}
}
F_4 ( & V_5 ) ;
if ( & V_4 -> V_8 == & V_9 )
return NULL ;
return V_4 ;
}
void F_6 ( struct V_1 * V_4 )
{
F_2 ( & V_5 ) ;
if ( V_4 -> V_7 ) {
V_4 -> V_7 -- ;
V_4 -> V_3 = NULL ;
} else
F_7 ( & V_4 -> V_12 -> V_13 , L_1 ) ;
F_4 ( & V_5 ) ;
}
static int F_8 ( struct V_14 * V_12 )
{
struct V_15 * V_16 ;
struct V_1 * V_4 ;
struct V_17 * V_13 = & V_12 -> V_13 ;
V_4 = F_9 ( V_13 , sizeof( struct V_1 ) , V_18 ) ;
if ( V_4 == NULL )
return - V_19 ;
V_4 -> V_12 = V_12 ;
V_4 -> V_20 = F_10 ( V_13 , NULL ) ;
if ( F_11 ( V_4 -> V_20 ) )
return F_12 ( V_4 -> V_20 ) ;
if ( V_13 -> V_11 ) {
struct V_21 V_22 ;
struct V_10 * V_23 = V_13 -> V_11 ;
int V_24 ;
V_24 = F_13 ( V_23 , L_2 , L_3 ,
0 , & V_22 ) ;
if ( V_24 ) {
F_7 ( V_13 , L_4 ) ;
return - V_25 ;
}
V_4 -> V_26 = V_22 . args [ 0 ] ;
F_14 ( V_22 . V_23 ) ;
V_24 = F_13 ( V_23 , L_2 , L_3 ,
1 , & V_22 ) ;
if ( V_24 ) {
F_7 ( V_13 , L_4 ) ;
return - V_25 ;
}
V_4 -> V_27 = V_22 . args [ 0 ] ;
F_14 ( V_22 . V_23 ) ;
} else {
V_16 = F_15 ( V_12 , V_28 , 0 ) ;
if ( V_16 == NULL ) {
F_7 ( V_13 , L_5 ) ;
return - V_25 ;
}
V_4 -> V_26 = V_16 -> V_29 ;
V_16 = F_15 ( V_12 , V_28 , 1 ) ;
if ( V_16 == NULL ) {
F_7 ( V_13 , L_6 ) ;
return - V_25 ;
}
V_4 -> V_27 = V_16 -> V_29 ;
}
V_16 = F_15 ( V_12 , V_30 , 0 ) ;
if ( V_16 == NULL ) {
F_7 ( V_13 , L_7 ) ;
return - V_25 ;
}
V_16 = F_16 ( V_13 , V_16 -> V_29 , F_17 ( V_16 ) ,
V_12 -> V_31 ) ;
if ( V_16 == NULL ) {
F_7 ( V_13 , L_8 ) ;
return - V_32 ;
}
V_4 -> V_33 = V_16 -> V_29 ;
V_4 -> V_34 = F_18 ( V_13 , V_16 -> V_29 , F_17 ( V_16 ) ) ;
if ( V_4 -> V_34 == NULL ) {
F_7 ( V_13 , L_9 ) ;
return - V_25 ;
}
V_4 -> V_35 = F_19 ( V_12 , 0 ) ;
if ( V_4 -> V_35 < 0 ) {
F_7 ( V_13 , L_10 ) ;
return - V_25 ;
}
if ( V_13 -> V_11 ) {
const struct V_36 * V_37 =
F_20 ( F_21 ( V_38 ) , V_13 ) ;
V_4 -> type = ( int ) V_37 -> V_39 ;
} else {
const struct V_40 * V_37 =
F_22 ( V_12 ) ;
V_4 -> type = ( int ) V_37 -> V_41 ;
V_4 -> V_6 = V_12 -> V_37 + 1 ;
}
V_4 -> V_7 = 0 ;
V_4 -> V_11 = V_13 -> V_11 ;
F_2 ( & V_5 ) ;
F_23 ( & V_4 -> V_8 , & V_9 ) ;
F_4 ( & V_5 ) ;
F_24 ( V_12 , V_4 ) ;
return 0 ;
}
static int F_25 ( struct V_14 * V_12 )
{
struct V_15 * V_16 ;
struct V_1 * V_4 ;
V_4 = F_26 ( V_12 ) ;
if ( V_4 == NULL )
return - V_25 ;
F_27 ( V_4 -> V_34 ) ;
V_16 = F_15 ( V_12 , V_30 , 0 ) ;
F_28 ( V_16 -> V_29 , F_17 ( V_16 ) ) ;
F_29 ( V_4 -> V_20 ) ;
F_2 ( & V_5 ) ;
F_30 ( & V_4 -> V_8 ) ;
F_4 ( & V_5 ) ;
F_31 ( V_4 ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
return F_33 ( & V_42 ) ;
}
static void T_2 F_34 ( void )
{
F_35 ( & V_42 ) ;
}
