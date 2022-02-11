static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 -> V_4 ) ;
}
static void F_3 ( struct V_2 * V_5 , bool V_6 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
if ( V_6 ) {
V_7 -> V_8 &= ~ V_9 ;
F_4 ( V_7 -> V_8 , V_7 -> V_10 + V_11 ) ;
F_4 ( 0 , V_7 -> V_10 + V_12 ) ;
} else {
F_4 ( F_5 ( V_5 -> V_13 ) , V_7 -> V_10 + V_12 ) ;
V_7 -> V_8 |= V_9 ;
F_4 ( V_7 -> V_8 , V_7 -> V_10 + V_11 ) ;
}
}
static void F_6 ( struct V_1 * V_7 )
{
unsigned int V_14 = 0 ;
if ( V_7 -> V_15 ) {
switch ( V_7 -> V_16 ) {
case 1 :
V_14 = V_7 -> V_15 [ V_7 -> V_17 ] ;
break;
case 2 :
V_14 = ( V_7 -> V_15 [ V_7 -> V_17 * 2 ]
| ( V_7 -> V_15 [ V_7 -> V_17 * 2 + 1 ] << 8 ) ) ;
break;
}
}
F_4 ( V_14 , V_7 -> V_10 + V_18 ) ;
}
static void F_7 ( struct V_1 * V_7 )
{
unsigned int V_19 ;
V_19 = F_8 ( V_7 -> V_10 + V_20 ) ;
if ( V_7 -> V_21 ) {
switch ( V_7 -> V_16 ) {
case 1 :
V_7 -> V_21 [ V_7 -> V_17 ] = V_19 ;
break;
case 2 :
V_7 -> V_21 [ V_7 -> V_17 * 2 ] = V_19 ;
V_7 -> V_21 [ V_7 -> V_17 * 2 + 1 ] = V_19 >> 8 ;
break;
}
}
V_7 -> V_17 ++ ;
}
static int F_9 ( struct V_22 * V_4 ,
struct V_2 * V_5 , struct V_23 * V_24 )
{
struct V_1 * V_7 = F_2 ( V_4 ) ;
V_7 -> V_15 = V_24 -> V_25 ;
V_7 -> V_21 = V_24 -> V_26 ;
V_7 -> V_17 = 0 ;
V_7 -> V_16 = F_10 ( V_24 -> V_27 , 8 ) ;
V_7 -> V_28 = V_24 -> V_28 / V_7 -> V_16 ;
if ( V_7 -> V_29 >= 0 ) {
V_7 -> V_8 |= V_30 ;
F_4 ( V_7 -> V_8 , V_7 -> V_10 + V_11 ) ;
F_6 ( V_7 ) ;
} else {
while ( V_7 -> V_17 < V_7 -> V_28 ) {
F_6 ( V_7 ) ;
while ( ! ( F_8 ( V_7 -> V_10 + V_31 ) &
V_32 ) )
F_11 () ;
F_7 ( V_7 ) ;
}
F_12 ( V_4 ) ;
}
return V_24 -> V_28 ;
}
static T_1 F_13 ( int V_29 , void * V_33 )
{
struct V_22 * V_4 = V_33 ;
struct V_1 * V_7 = F_2 ( V_4 ) ;
F_7 ( V_7 ) ;
if ( V_7 -> V_17 < V_7 -> V_28 ) {
F_6 ( V_7 ) ;
} else {
V_7 -> V_8 &= ~ V_30 ;
F_4 ( V_7 -> V_8 , V_7 -> V_10 + V_11 ) ;
F_12 ( V_4 ) ;
}
return V_34 ;
}
static int F_14 ( struct V_35 * V_36 )
{
struct V_1 * V_7 ;
struct V_22 * V_4 ;
struct V_37 * V_38 ;
int V_39 = - V_40 ;
V_4 = F_15 ( & V_36 -> V_33 , sizeof( struct V_1 ) ) ;
if ( ! V_4 )
return V_39 ;
V_4 -> V_41 = V_36 -> V_42 ;
V_4 -> V_43 = 16 ;
V_4 -> V_44 = V_45 ;
V_4 -> V_46 = F_16 ( 1 , 16 ) ;
V_4 -> V_33 . V_47 = V_36 -> V_33 . V_47 ;
V_4 -> V_48 = F_9 ;
V_4 -> V_49 = F_3 ;
V_7 = F_2 ( V_4 ) ;
V_38 = F_17 ( V_36 , V_50 , 0 ) ;
V_7 -> V_10 = F_18 ( & V_36 -> V_33 , V_38 ) ;
if ( F_19 ( V_7 -> V_10 ) ) {
V_39 = F_20 ( V_7 -> V_10 ) ;
goto exit;
}
V_7 -> V_8 = 0 ;
F_4 ( V_7 -> V_8 , V_7 -> V_10 + V_11 ) ;
F_4 ( 0 , V_7 -> V_10 + V_31 ) ;
if ( F_8 ( V_7 -> V_10 + V_31 ) & V_32 )
F_8 ( V_7 -> V_10 + V_20 ) ;
V_7 -> V_29 = F_21 ( V_36 , 0 ) ;
if ( V_7 -> V_29 >= 0 ) {
V_39 = F_22 ( & V_36 -> V_33 , V_7 -> V_29 , F_13 , 0 ,
V_36 -> V_51 , V_4 ) ;
if ( V_39 )
goto exit;
}
V_39 = F_23 ( & V_36 -> V_33 , V_4 ) ;
if ( V_39 )
goto exit;
F_24 ( & V_36 -> V_33 , L_1 , V_7 -> V_10 , V_7 -> V_29 ) ;
return 0 ;
exit:
F_25 ( V_4 ) ;
return V_39 ;
}
