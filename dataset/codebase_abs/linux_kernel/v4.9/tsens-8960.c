static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
unsigned int V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_3 = F_2 ( V_6 , V_7 , & V_2 -> V_8 . V_9 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_2 ( V_6 , V_10 , & V_2 -> V_8 . V_11 ) ;
if ( V_3 )
return V_3 ;
if ( V_2 -> V_12 > 1 )
V_4 = V_13 | V_14 ;
else
V_4 = V_15 | V_14 ;
V_3 = F_3 ( V_6 , V_10 , V_4 , 0 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_5 * V_6 = V_2 -> V_6 ;
V_3 = F_3 ( V_6 , V_10 , V_16 , V_16 ) ;
if ( V_3 )
return V_3 ;
if ( V_2 -> V_12 > 1 ) {
V_3 = F_3 ( V_6 , V_17 , V_18 , V_19 ) ;
if ( V_3 )
return V_3 ;
}
V_3 = F_5 ( V_6 , V_7 , V_2 -> V_8 . V_9 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_5 ( V_6 , V_10 , V_2 -> V_8 . V_11 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , int V_20 )
{
int V_3 ;
T_1 V_21 , V_4 ;
V_3 = F_2 ( V_2 -> V_6 , V_10 , & V_21 ) ;
if ( V_3 )
return V_3 ;
V_4 = F_7 ( V_20 + V_22 ) ;
V_3 = F_5 ( V_2 -> V_6 , V_10 , V_21 | V_16 ) ;
if ( V_3 )
return V_3 ;
if ( V_2 -> V_12 > 1 )
V_21 |= V_4 | V_13 | V_14 ;
else
V_21 |= V_4 | V_15 | V_14 ;
V_3 = F_5 ( V_2 -> V_6 , V_10 , V_21 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
int V_3 ;
T_1 V_23 ;
T_1 V_4 ;
V_4 = F_9 ( V_2 -> V_12 - 1 , 0 ) ;
V_4 <<= V_22 ;
V_4 |= V_14 ;
V_3 = F_2 ( V_2 -> V_6 , V_10 , & V_23 ) ;
if ( V_3 )
return;
V_23 &= ~ V_4 ;
if ( V_2 -> V_12 > 1 )
V_23 &= ~ V_13 ;
else
V_23 &= ~ V_15 ;
F_5 ( V_2 -> V_6 , V_10 , V_23 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_3 , V_24 ;
T_1 V_23 ;
V_2 -> V_6 = F_11 ( V_2 -> V_25 , NULL ) ;
if ( ! V_2 -> V_6 )
return - V_26 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_12 ; V_24 ++ ) {
if ( V_24 >= 5 )
V_2 -> V_27 [ V_24 ] . V_28 = V_29 + 40 ;
V_2 -> V_27 [ V_24 ] . V_28 += V_24 * 4 ;
}
V_23 = V_16 ;
V_3 = F_3 ( V_2 -> V_6 , V_10 , V_16 , V_23 ) ;
if ( V_3 )
return V_3 ;
if ( V_2 -> V_12 > 1 ) {
V_23 |= V_13 | ( V_30 << 18 ) ;
V_23 &= ~ V_16 ;
V_3 = F_3 ( V_2 -> V_6 , V_17 ,
V_18 , V_19 ) ;
} else {
V_23 |= V_15 | ( V_30 << 16 ) ;
V_23 &= ~ V_31 ;
V_23 |= V_32 << V_33 ;
}
V_23 |= F_9 ( V_2 -> V_12 - 1 , 0 ) << V_22 ;
V_3 = F_5 ( V_2 -> V_6 , V_10 , V_23 ) ;
if ( V_3 )
return V_3 ;
V_23 |= V_14 ;
V_3 = F_5 ( V_2 -> V_6 , V_10 , V_23 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_24 ;
char * V_34 ;
T_2 V_35 = V_2 -> V_12 ;
struct V_36 * V_37 = V_2 -> V_27 ;
V_34 = F_13 ( V_2 -> V_25 , L_1 ) ;
if ( F_14 ( V_34 ) )
V_34 = F_13 ( V_2 -> V_25 , L_2 ) ;
if ( F_14 ( V_34 ) )
return F_15 ( V_34 ) ;
for ( V_24 = 0 ; V_24 < V_35 ; V_24 ++ , V_37 ++ )
V_37 -> V_38 = V_34 [ V_24 ] ;
return 0 ;
}
static inline int F_16 ( T_1 V_39 , const struct V_36 * V_37 )
{
int V_40 , V_38 ;
V_40 = F_17 ( V_37 -> V_41 ) ;
V_38 = V_42 - V_40 * V_37 -> V_38 ;
return V_39 * V_40 + V_38 ;
}
static int F_18 ( struct V_1 * V_2 , int V_20 , int * V_43 )
{
int V_3 ;
T_1 V_44 , V_45 ;
const struct V_36 * V_37 = & V_2 -> V_27 [ V_20 ] ;
unsigned long V_46 ;
V_46 = V_47 + F_19 ( V_48 ) ;
do {
V_3 = F_2 ( V_2 -> V_6 , V_49 , & V_45 ) ;
if ( V_3 )
return V_3 ;
if ( ! ( V_45 & V_50 ) )
continue;
V_3 = F_2 ( V_2 -> V_6 , V_37 -> V_28 , & V_44 ) ;
if ( V_3 )
return V_3 ;
* V_43 = F_16 ( V_44 , V_37 ) ;
return 0 ;
} while ( F_20 ( V_47 , V_46 ) );
return - V_51 ;
}
