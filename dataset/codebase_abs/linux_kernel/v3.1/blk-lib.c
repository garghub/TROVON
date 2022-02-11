static void F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
if ( V_2 && ( V_2 != - V_6 ) )
F_2 ( V_7 , & V_4 -> V_8 ) ;
if ( F_3 ( & V_4 -> V_9 ) )
F_4 ( V_4 -> V_10 ) ;
F_5 ( V_1 ) ;
}
int F_6 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 V_14 , T_2 V_15 , unsigned long V_8 )
{
F_7 ( V_10 ) ;
struct V_16 * V_17 = F_8 ( V_12 ) ;
int type = V_18 | V_19 ;
unsigned int V_20 ;
struct V_3 V_4 ;
struct V_1 * V_1 ;
int V_21 = 0 ;
if ( ! V_17 )
return - V_22 ;
if ( ! F_9 ( V_17 ) )
return - V_6 ;
V_20 = F_10 ( V_17 -> V_23 . V_20 , V_24 >> 9 ) ;
if ( F_11 ( ! V_20 ) ) {
return - V_6 ;
} else if ( V_17 -> V_23 . V_25 ) {
unsigned int V_26 = V_17 -> V_23 . V_25 >> 9 ;
V_20 &= ~ ( V_26 - 1 ) ;
}
if ( V_8 & V_27 ) {
if ( ! F_12 ( V_17 ) )
return - V_6 ;
type |= V_28 ;
}
F_13 ( & V_4 . V_9 , 1 ) ;
V_4 . V_8 = 1 << V_7 ;
V_4 . V_10 = & V_10 ;
while ( V_14 ) {
V_1 = F_14 ( V_15 , 1 ) ;
if ( ! V_1 ) {
V_21 = - V_29 ;
break;
}
V_1 -> V_30 = V_13 ;
V_1 -> V_31 = F_1 ;
V_1 -> V_32 = V_12 ;
V_1 -> V_5 = & V_4 ;
if ( V_14 > V_20 ) {
V_1 -> V_33 = V_20 << 9 ;
V_14 -= V_20 ;
V_13 += V_20 ;
} else {
V_1 -> V_33 = V_14 << 9 ;
V_14 = 0 ;
}
F_15 ( & V_4 . V_9 ) ;
F_16 ( type , V_1 ) ;
}
if ( ! F_3 ( & V_4 . V_9 ) )
F_17 ( & V_10 ) ;
if ( ! F_18 ( V_7 , & V_4 . V_8 ) )
V_21 = - V_34 ;
return V_21 ;
}
int F_19 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 V_14 , T_2 V_15 )
{
int V_21 ;
struct V_1 * V_1 ;
struct V_3 V_4 ;
unsigned int V_35 ;
F_7 ( V_10 ) ;
F_13 ( & V_4 . V_9 , 1 ) ;
V_4 . V_8 = 1 << V_7 ;
V_4 . V_10 = & V_10 ;
V_21 = 0 ;
while ( V_14 != 0 ) {
V_1 = F_14 ( V_15 ,
F_10 ( V_14 , ( T_1 ) V_36 ) ) ;
if ( ! V_1 ) {
V_21 = - V_29 ;
break;
}
V_1 -> V_30 = V_13 ;
V_1 -> V_32 = V_12 ;
V_1 -> V_31 = F_1 ;
V_1 -> V_5 = & V_4 ;
while ( V_14 != 0 ) {
V_35 = F_10 ( ( T_1 ) V_37 >> 9 , V_14 ) ;
V_21 = F_20 ( V_1 , F_21 ( 0 ) , V_35 << 9 , 0 ) ;
V_14 -= V_21 >> 9 ;
V_13 += V_21 >> 9 ;
if ( V_21 < ( V_35 << 9 ) )
break;
}
V_21 = 0 ;
F_15 ( & V_4 . V_9 ) ;
F_16 ( V_38 , V_1 ) ;
}
if ( ! F_3 ( & V_4 . V_9 ) )
F_17 ( & V_10 ) ;
if ( ! F_18 ( V_7 , & V_4 . V_8 ) )
V_21 = - V_34 ;
return V_21 ;
}
