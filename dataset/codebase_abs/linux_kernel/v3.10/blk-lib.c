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
T_1 V_20 ;
T_1 V_21 , V_22 ;
struct V_3 V_4 ;
struct V_1 * V_1 ;
int V_23 = 0 ;
struct V_24 V_25 ;
if ( ! V_17 )
return - V_26 ;
if ( ! F_9 ( V_17 ) )
return - V_6 ;
V_21 = F_10 ( V_17 -> V_27 . V_28 >> 9 , 1U ) ;
V_22 = F_11 ( V_12 ) >> 9 ;
V_22 = F_12 ( V_22 , V_21 ) ;
V_20 = F_13 ( V_17 -> V_27 . V_20 , V_29 >> 9 ) ;
F_12 ( V_20 , V_21 ) ;
V_20 *= V_21 ;
if ( F_14 ( ! V_20 ) ) {
return - V_6 ;
}
if ( V_8 & V_30 ) {
if ( ! F_15 ( V_17 ) )
return - V_6 ;
type |= V_31 ;
}
F_16 ( & V_4 . V_9 , 1 ) ;
V_4 . V_8 = 1 << V_7 ;
V_4 . V_10 = & V_10 ;
F_17 ( & V_25 ) ;
while ( V_14 ) {
unsigned int V_32 ;
T_1 V_33 , V_34 ;
V_1 = F_18 ( V_15 , 1 ) ;
if ( ! V_1 ) {
V_23 = - V_35 ;
break;
}
V_32 = F_19 ( T_1 , V_14 , V_20 ) ;
V_33 = V_13 + V_32 ;
V_34 = V_33 ;
if ( V_32 < V_14 &&
F_12 ( V_34 , V_21 ) != V_22 ) {
V_33 = V_33 - V_22 ;
F_12 ( V_33 , V_21 ) ;
V_33 = V_33 * V_21 + V_22 ;
V_32 = V_33 - V_13 ;
}
V_1 -> V_36 = V_13 ;
V_1 -> V_37 = F_1 ;
V_1 -> V_38 = V_12 ;
V_1 -> V_5 = & V_4 ;
V_1 -> V_39 = V_32 << 9 ;
V_14 -= V_32 ;
V_13 = V_33 ;
F_20 ( & V_4 . V_9 ) ;
F_21 ( type , V_1 ) ;
}
F_22 ( & V_25 ) ;
if ( ! F_3 ( & V_4 . V_9 ) )
F_23 ( & V_10 ) ;
if ( ! F_24 ( V_7 , & V_4 . V_8 ) )
V_23 = - V_40 ;
return V_23 ;
}
int F_25 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 V_14 , T_2 V_15 ,
struct V_41 * V_41 )
{
F_7 ( V_10 ) ;
struct V_16 * V_17 = F_8 ( V_12 ) ;
unsigned int V_42 ;
struct V_3 V_4 ;
struct V_1 * V_1 ;
int V_23 = 0 ;
if ( ! V_17 )
return - V_26 ;
V_42 = V_17 -> V_27 . V_42 ;
if ( V_42 == 0 )
return - V_6 ;
F_16 ( & V_4 . V_9 , 1 ) ;
V_4 . V_8 = 1 << V_7 ;
V_4 . V_10 = & V_10 ;
while ( V_14 ) {
V_1 = F_18 ( V_15 , 1 ) ;
if ( ! V_1 ) {
V_23 = - V_35 ;
break;
}
V_1 -> V_36 = V_13 ;
V_1 -> V_37 = F_1 ;
V_1 -> V_38 = V_12 ;
V_1 -> V_5 = & V_4 ;
V_1 -> V_43 = 1 ;
V_1 -> V_44 -> V_45 = V_41 ;
V_1 -> V_44 -> V_46 = 0 ;
V_1 -> V_44 -> V_47 = F_26 ( V_12 ) ;
if ( V_14 > V_42 ) {
V_1 -> V_39 = V_42 << 9 ;
V_14 -= V_42 ;
V_13 += V_42 ;
} else {
V_1 -> V_39 = V_14 << 9 ;
V_14 = 0 ;
}
F_20 ( & V_4 . V_9 ) ;
F_21 ( V_18 | V_48 , V_1 ) ;
}
if ( ! F_3 ( & V_4 . V_9 ) )
F_23 ( & V_10 ) ;
if ( ! F_24 ( V_7 , & V_4 . V_8 ) )
V_23 = - V_49 ;
return V_23 ;
}
int F_27 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 V_14 , T_2 V_15 )
{
int V_23 ;
struct V_1 * V_1 ;
struct V_3 V_4 ;
unsigned int V_50 ;
F_7 ( V_10 ) ;
F_16 ( & V_4 . V_9 , 1 ) ;
V_4 . V_8 = 1 << V_7 ;
V_4 . V_10 = & V_10 ;
V_23 = 0 ;
while ( V_14 != 0 ) {
V_1 = F_18 ( V_15 ,
F_13 ( V_14 , ( T_1 ) V_51 ) ) ;
if ( ! V_1 ) {
V_23 = - V_35 ;
break;
}
V_1 -> V_36 = V_13 ;
V_1 -> V_38 = V_12 ;
V_1 -> V_37 = F_1 ;
V_1 -> V_5 = & V_4 ;
while ( V_14 != 0 ) {
V_50 = F_13 ( ( T_1 ) V_52 >> 9 , V_14 ) ;
V_23 = F_28 ( V_1 , F_29 ( 0 ) , V_50 << 9 , 0 ) ;
V_14 -= V_23 >> 9 ;
V_13 += V_23 >> 9 ;
if ( V_23 < ( V_50 << 9 ) )
break;
}
V_23 = 0 ;
F_20 ( & V_4 . V_9 ) ;
F_21 ( V_53 , V_1 ) ;
}
if ( ! F_3 ( & V_4 . V_9 ) )
F_23 ( & V_10 ) ;
if ( ! F_24 ( V_7 , & V_4 . V_8 ) )
V_23 = - V_40 ;
return V_23 ;
}
int F_30 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 V_14 , T_2 V_15 )
{
if ( F_31 ( V_12 ) ) {
unsigned char V_54 [ V_55 ] ;
if ( ! F_25 ( V_12 , V_13 , V_14 , V_15 ,
F_29 ( 0 ) ) )
return 0 ;
F_32 ( V_12 , V_54 ) ;
F_33 ( L_1 , V_54 ) ;
}
return F_27 ( V_12 , V_13 , V_14 , V_15 ) ;
}
