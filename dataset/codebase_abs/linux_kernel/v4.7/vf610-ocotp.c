static int F_1 ( void T_1 * V_1 )
{
int V_2 = V_3 ;
while ( ( F_2 ( V_1 ) & V_4 ) && -- V_2 )
F_3 ( 10 ) ;
if ( ! V_2 ) {
F_4 ( V_5 , V_1 + V_6 ) ;
return - V_7 ;
}
F_3 ( 10 ) ;
return 0 ;
}
static int F_5 ( struct V_8 * V_9 )
{
T_2 V_10 ;
T_2 V_11 , V_12 , V_13 ;
T_2 V_14 ;
V_10 = F_6 ( V_9 -> V_15 ) ;
V_11 = V_10 / ( 1000000000 / V_16 ) - 1 ;
V_13 = V_10 / ( 1000000000 / 10000 ) + 2 * ( V_16 + 1 ) - 1 ;
V_12 = V_10 / ( 1000000000 / 40 ) + 2 * ( V_16 + 1 ) - 1 ;
V_14 = F_7 ( V_11 , V_17 ) ;
V_14 |= F_7 ( V_12 , V_18 ) ;
V_14 |= F_7 ( V_13 , V_19 ) ;
return V_14 ;
}
static int F_8 ( int V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < F_9 ( V_22 ) ; V_21 ++ ) {
if ( V_22 [ V_21 ] [ 0 ] == V_20 )
return V_22 [ V_21 ] [ 1 ] ;
}
return - V_23 ;
}
static int F_10 ( void * V_24 , unsigned int V_25 ,
void * V_26 , T_3 V_27 )
{
struct V_8 * V_28 = V_24 ;
void T_1 * V_1 = V_28 -> V_1 ;
T_2 V_29 , * V_30 = V_26 ;
int V_31 ;
int V_32 ;
while ( V_27 > 0 ) {
V_31 = F_8 ( V_25 ) ;
if ( V_31 > 0 ) {
F_4 ( V_28 -> V_14 , V_1 + V_33 ) ;
V_32 = F_1 ( V_1 + V_34 ) ;
if ( V_32 )
return V_32 ;
V_29 = F_2 ( V_1 + V_34 ) ;
V_29 &= ~ V_35 ;
V_29 &= ~ V_36 ;
V_29 |= F_7 ( V_31 , V_37 ) ;
F_4 ( V_29 , V_1 + V_34 ) ;
F_4 ( V_38 ,
V_1 + V_39 ) ;
V_32 = F_1 ( V_1 + V_34 ) ;
if ( V_32 )
return V_32 ;
if ( F_2 ( V_1 ) & V_5 ) {
F_11 ( V_28 -> V_40 , L_1 ,
V_31 ) ;
F_4 ( V_5 , V_1 + V_6 ) ;
}
* V_30 = F_2 ( V_1 + V_41 ) ;
} else {
* V_30 = 0 ;
}
V_30 ++ ;
V_27 -= 4 ;
V_25 += 4 ;
}
return 0 ;
}
static int F_12 ( struct V_42 * V_43 )
{
struct V_8 * V_9 = F_13 ( V_43 ) ;
return F_14 ( V_9 -> V_44 ) ;
}
static int F_15 ( struct V_42 * V_43 )
{
struct V_45 * V_40 = & V_43 -> V_40 ;
struct V_46 * V_47 ;
struct V_8 * V_9 ;
V_9 = F_16 ( & V_43 -> V_40 ,
sizeof( struct V_8 ) , V_48 ) ;
if ( ! V_9 )
return - V_49 ;
V_47 = F_17 ( V_43 , V_50 , 0 ) ;
V_9 -> V_1 = F_18 ( V_40 , V_47 ) ;
if ( F_19 ( V_9 -> V_1 ) )
return F_20 ( V_9 -> V_1 ) ;
V_9 -> V_15 = F_21 ( V_40 , NULL ) ;
if ( F_19 ( V_9 -> V_15 ) ) {
F_22 ( V_40 , L_2 ,
F_20 ( V_9 -> V_15 ) ) ;
return F_20 ( V_9 -> V_15 ) ;
}
V_51 . V_52 = F_23 ( V_47 ) ;
V_51 . V_53 = V_9 ;
V_51 . V_40 = V_40 ;
V_9 -> V_44 = F_24 ( & V_51 ) ;
if ( F_19 ( V_9 -> V_44 ) )
return F_20 ( V_9 -> V_44 ) ;
V_9 -> V_40 = V_40 ;
F_25 ( V_43 , V_9 ) ;
V_9 -> V_14 = F_5 ( V_9 ) ;
return 0 ;
}
