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
static int F_10 ( void * V_24 , const void * V_25 , T_3 V_26 )
{
return 0 ;
}
static int F_11 ( void * V_24 ,
const void * V_27 , T_3 V_28 ,
void * V_29 , T_3 V_30 )
{
struct V_8 * V_31 = V_24 ;
void T_1 * V_1 = V_31 -> V_1 ;
unsigned int V_32 = * ( T_2 * ) V_27 ;
T_2 V_33 , * V_34 = V_29 ;
int V_35 ;
int V_36 ;
while ( V_30 > 0 ) {
V_35 = F_8 ( V_32 ) ;
if ( V_35 > 0 ) {
F_4 ( V_31 -> V_14 , V_1 + V_37 ) ;
V_36 = F_1 ( V_1 + V_38 ) ;
if ( V_36 )
return V_36 ;
V_33 = F_2 ( V_1 + V_38 ) ;
V_33 &= ~ V_39 ;
V_33 &= ~ V_40 ;
V_33 |= F_7 ( V_35 , V_41 ) ;
F_4 ( V_33 , V_1 + V_38 ) ;
F_4 ( V_42 ,
V_1 + V_43 ) ;
V_36 = F_1 ( V_1 + V_38 ) ;
if ( V_36 )
return V_36 ;
if ( F_2 ( V_1 ) & V_5 ) {
F_12 ( V_31 -> V_44 , L_1 ,
V_35 ) ;
F_4 ( V_5 , V_1 + V_6 ) ;
}
* V_34 = F_2 ( V_1 + V_45 ) ;
} else {
* V_34 = 0 ;
}
V_34 ++ ;
V_30 -- ;
V_32 += V_28 ;
}
return 0 ;
}
static int F_13 ( struct V_46 * V_47 )
{
struct V_8 * V_9 = F_14 ( V_47 ) ;
return F_15 ( V_9 -> V_48 ) ;
}
static int F_16 ( struct V_46 * V_47 )
{
struct V_49 * V_44 = & V_47 -> V_44 ;
struct V_50 * V_51 ;
struct V_52 * V_52 ;
struct V_8 * V_9 ;
V_9 = F_17 ( & V_47 -> V_44 ,
sizeof( struct V_8 ) , V_53 ) ;
if ( ! V_9 )
return - V_54 ;
V_51 = F_18 ( V_47 , V_55 , 0 ) ;
V_9 -> V_1 = F_19 ( V_44 , V_51 ) ;
if ( F_20 ( V_9 -> V_1 ) )
return F_21 ( V_9 -> V_1 ) ;
V_9 -> V_15 = F_22 ( V_44 , NULL ) ;
if ( F_20 ( V_9 -> V_15 ) ) {
F_23 ( V_44 , L_2 ,
F_21 ( V_9 -> V_15 ) ) ;
return F_21 ( V_9 -> V_15 ) ;
}
V_56 . V_57 = F_24 ( V_51 ) ;
V_52 = F_25 ( V_44 ,
& V_58 , V_9 , & V_56 ) ;
if ( F_20 ( V_52 ) ) {
F_23 ( V_44 , L_3 ) ;
return F_21 ( V_52 ) ;
}
V_59 . V_44 = V_44 ;
V_9 -> V_48 = F_26 ( & V_59 ) ;
if ( F_20 ( V_9 -> V_48 ) )
return F_21 ( V_9 -> V_48 ) ;
V_9 -> V_44 = V_44 ;
F_27 ( V_47 , V_9 ) ;
V_9 -> V_14 = F_5 ( V_9 ) ;
return 0 ;
}
