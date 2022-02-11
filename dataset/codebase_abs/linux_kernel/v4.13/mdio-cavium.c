static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
union V_5 V_6 ;
if ( V_4 == V_2 -> V_7 )
return;
V_6 . V_8 = F_2 ( V_2 -> V_9 + V_10 ) ;
V_6 . V_11 . V_7 = ( V_4 == V_12 ) ? 1 : 0 ;
V_6 . V_11 . V_13 = 1 ;
F_3 ( V_6 . V_8 , V_2 -> V_9 + V_10 ) ;
V_2 -> V_7 = V_4 ;
}
static int F_4 ( struct V_1 * V_2 ,
int V_14 , int V_15 )
{
union V_16 V_17 ;
union V_18 V_19 ;
int V_20 = 1000 ;
F_1 ( V_2 , V_12 ) ;
V_19 . V_8 = 0 ;
V_19 . V_11 . V_21 = V_15 & 0xffff ;
F_3 ( V_19 . V_8 , V_2 -> V_9 + V_22 ) ;
V_15 = ( V_15 >> 16 ) & 0x1f ;
V_17 . V_8 = 0 ;
V_17 . V_11 . V_23 = 0 ;
V_17 . V_11 . V_24 = V_14 ;
V_17 . V_11 . V_25 = V_15 ;
F_3 ( V_17 . V_8 , V_2 -> V_9 + V_26 ) ;
do {
F_5 ( 1000 ) ;
V_19 . V_8 = F_2 ( V_2 -> V_9 + V_22 ) ;
} while ( V_19 . V_11 . V_27 && -- V_20 );
if ( V_20 <= 0 )
return - V_28 ;
return 0 ;
}
int F_6 ( struct V_29 * V_30 , int V_14 , int V_15 )
{
struct V_1 * V_2 = V_30 -> V_31 ;
union V_16 V_17 ;
union V_32 V_33 ;
unsigned int V_34 = 1 ;
int V_20 = 1000 ;
if ( V_15 & V_35 ) {
int V_36 = F_4 ( V_2 , V_14 , V_15 ) ;
if ( V_36 < 0 )
return V_36 ;
V_15 = ( V_15 >> 16 ) & 0x1f ;
V_34 = 3 ;
} else {
F_1 ( V_2 , V_37 ) ;
}
V_17 . V_8 = 0 ;
V_17 . V_11 . V_23 = V_34 ;
V_17 . V_11 . V_24 = V_14 ;
V_17 . V_11 . V_25 = V_15 ;
F_3 ( V_17 . V_8 , V_2 -> V_9 + V_26 ) ;
do {
F_5 ( 1000 ) ;
V_33 . V_8 = F_2 ( V_2 -> V_9 + V_38 ) ;
} while ( V_33 . V_11 . V_27 && -- V_20 );
if ( V_33 . V_11 . V_39 )
return V_33 . V_11 . V_21 ;
else
return - V_28 ;
}
int F_7 ( struct V_29 * V_30 , int V_14 , int V_15 , T_1 V_39 )
{
struct V_1 * V_2 = V_30 -> V_31 ;
union V_16 V_17 ;
union V_18 V_19 ;
unsigned int V_34 = 0 ;
int V_20 = 1000 ;
if ( V_15 & V_35 ) {
int V_36 = F_4 ( V_2 , V_14 , V_15 ) ;
if ( V_36 < 0 )
return V_36 ;
V_15 = ( V_15 >> 16 ) & 0x1f ;
V_34 = 1 ;
} else {
F_1 ( V_2 , V_37 ) ;
}
V_19 . V_8 = 0 ;
V_19 . V_11 . V_21 = V_39 ;
F_3 ( V_19 . V_8 , V_2 -> V_9 + V_22 ) ;
V_17 . V_8 = 0 ;
V_17 . V_11 . V_23 = V_34 ;
V_17 . V_11 . V_24 = V_14 ;
V_17 . V_11 . V_25 = V_15 ;
F_3 ( V_17 . V_8 , V_2 -> V_9 + V_26 ) ;
do {
F_5 ( 1000 ) ;
V_19 . V_8 = F_2 ( V_2 -> V_9 + V_22 ) ;
} while ( V_19 . V_11 . V_27 && -- V_20 );
if ( V_20 <= 0 )
return - V_28 ;
return 0 ;
}
