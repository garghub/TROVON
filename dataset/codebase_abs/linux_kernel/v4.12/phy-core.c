static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 ,
T_1 V_5 )
{
V_2 -> V_6 ( V_2 , V_3 , V_7 , V_4 ) ;
V_2 -> V_6 ( V_2 , V_3 , V_8 , V_5 ) ;
V_2 -> V_6 ( V_2 , V_3 , V_7 , V_4 | V_9 ) ;
}
int F_2 ( struct V_10 * V_11 , int V_4 , T_2 V_5 )
{
int V_12 ;
if ( V_5 > ( T_1 ) ~ 0 || V_4 > 32 )
return - V_13 ;
if ( V_11 -> V_14 -> V_15 ) {
V_12 = V_11 -> V_14 -> V_15 ( V_11 , V_4 , V_5 ) ;
} else if ( V_11 -> V_16 ) {
T_2 V_17 = V_18 | ( V_4 << 16 ) | ( V_5 & 0xffff ) ;
V_12 = F_3 ( V_11 -> V_19 . V_2 , V_11 -> V_19 . V_17 , V_17 ) ;
} else {
struct V_1 * V_2 = V_11 -> V_19 . V_2 ;
int V_3 = V_11 -> V_19 . V_17 ;
F_4 ( & V_2 -> V_20 ) ;
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
V_12 = V_2 -> V_21 ( V_2 , V_3 , V_8 ) ;
F_5 ( & V_2 -> V_20 ) ;
}
return V_12 ;
}
int F_6 ( struct V_10 * V_11 , int V_4 , T_2 V_5 , T_1 V_12 )
{
int V_22 ;
if ( V_5 > ( T_1 ) ~ 0 || V_4 > 32 )
return - V_13 ;
if ( V_11 -> V_14 -> V_23 ) {
V_22 = V_11 -> V_14 -> V_23 ( V_11 , V_4 , V_5 , V_12 ) ;
} else if ( V_11 -> V_16 ) {
T_2 V_17 = V_18 | ( V_4 << 16 ) | ( V_5 & 0xffff ) ;
V_22 = F_7 ( V_11 -> V_19 . V_2 , V_11 -> V_19 . V_17 ,
V_17 , V_12 ) ;
} else {
struct V_1 * V_2 = V_11 -> V_19 . V_2 ;
int V_3 = V_11 -> V_19 . V_17 ;
F_4 ( & V_2 -> V_20 ) ;
F_1 ( V_2 , V_3 , V_4 , V_5 ) ;
V_2 -> V_6 ( V_2 , V_3 , V_8 , V_12 ) ;
F_5 ( & V_2 -> V_20 ) ;
V_22 = 0 ;
}
return V_22 ;
}
