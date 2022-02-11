static void F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = & V_4 -> V_6 . V_7 ;
T_1 V_8 [ F_2 ( V_6 -> V_8 ) ] ;
struct V_9 * V_10 ;
bool V_11 = false ;
unsigned int V_12 = 0 ;
T_1 V_13 ;
V_10 = F_3 ( V_2 , L_1 , NULL ) ;
if ( V_10 ) {
const T_2 * V_14 = NULL ;
int V_15 ;
for ( V_15 = 0 ; V_15 < F_2 ( V_8 ) ; V_15 ++ ) {
V_14 = F_4 ( V_10 , V_14 , & V_8 [ V_15 ] ) ;
if ( ! V_14 )
break;
}
V_6 -> V_16 = V_15 ;
while ( V_15 -- )
V_6 -> V_8 [ V_15 ] = V_8 [ V_15 ] ;
}
if ( ! F_5 ( V_2 , L_2 , & V_13 ) ) {
V_6 -> V_17 = V_13 ;
V_11 = true ;
}
if ( F_6 ( V_2 , L_3 , & V_13 ) )
V_12 |= V_18 ;
else if ( V_11 || V_6 -> V_16 > 0 )
V_12 |= V_19 ;
V_6 -> V_12 = V_12 ;
V_4 -> V_20 = V_21 ;
}
static void F_7 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_22 * V_6 = & V_4 -> V_6 . V_23 ;
unsigned int V_12 = 0 ;
T_1 V_13 ;
if ( ! F_5 ( V_2 , L_4 , & V_13 ) )
V_12 |= V_13 ? V_24 :
V_25 ;
if ( ! F_5 ( V_2 , L_5 , & V_13 ) )
V_12 |= V_13 ? V_26 :
V_27 ;
if ( ! F_5 ( V_2 , L_6 , & V_13 ) )
V_12 |= V_13 ? V_28 :
V_29 ;
if ( ! F_5 ( V_2 , L_7 , & V_13 ) )
V_12 |= V_13 ? V_30 :
V_31 ;
if ( V_12 )
V_4 -> V_20 = V_32 ;
else
V_4 -> V_20 = V_33 ;
if ( ! F_5 ( V_2 , L_8 , & V_13 ) )
V_12 |= V_13 ? V_34 :
V_35 ;
if ( F_6 ( V_2 , L_9 , & V_13 ) )
V_12 |= V_36 ;
else
V_12 |= V_37 ;
if ( ! F_5 ( V_2 , L_10 , & V_13 ) )
V_6 -> V_38 = V_13 ;
if ( ! F_5 ( V_2 , L_11 , & V_13 ) )
V_6 -> V_39 = V_13 ;
if ( ! F_5 ( V_2 , L_12 , & V_13 ) )
V_12 |= V_13 ? V_40 :
V_41 ;
V_6 -> V_12 = V_12 ;
}
int F_8 ( const struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_9 ( V_2 , & V_4 -> V_42 ) ;
V_4 -> V_20 = 0 ;
memset ( & V_4 -> V_6 , 0 , sizeof( V_4 -> V_6 ) ) ;
F_1 ( V_2 , V_4 ) ;
if ( V_4 -> V_6 . V_7 . V_12 == 0 )
F_7 ( V_2 , V_4 ) ;
return 0 ;
}
