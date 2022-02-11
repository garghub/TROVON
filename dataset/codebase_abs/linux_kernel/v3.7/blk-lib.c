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
unsigned int V_21 , V_22 , V_23 ;
struct V_3 V_4 ;
struct V_1 * V_1 ;
int V_24 = 0 ;
if ( ! V_17 )
return - V_25 ;
if ( ! F_9 ( V_17 ) )
return - V_6 ;
V_21 = F_10 ( V_17 -> V_26 . V_27 >> 9 , 1U ) ;
V_23 = V_21 - 1 ;
V_22 = ( F_11 ( V_12 ) >> 9 ) & V_23 ;
V_20 = F_12 ( V_17 -> V_26 . V_20 , V_28 >> 9 ) ;
V_20 = F_13 ( V_20 , V_21 ) ;
if ( F_14 ( ! V_20 ) ) {
return - V_6 ;
}
if ( V_8 & V_29 ) {
if ( ! F_15 ( V_17 ) )
return - V_6 ;
type |= V_30 ;
}
F_16 ( & V_4 . V_9 , 1 ) ;
V_4 . V_8 = 1 << V_7 ;
V_4 . V_10 = & V_10 ;
while ( V_14 ) {
unsigned int V_31 ;
T_1 V_32 ;
V_1 = F_17 ( V_15 , 1 ) ;
if ( ! V_1 ) {
V_24 = - V_33 ;
break;
}
V_31 = F_18 ( T_1 , V_14 , V_20 ) ;
V_32 = V_13 + V_31 ;
if ( V_31 < V_14 && ( V_32 & V_23 ) != V_22 ) {
V_32 =
F_13 ( V_32 - V_22 , V_21 )
+ V_22 ;
V_31 = V_32 - V_13 ;
}
V_1 -> V_34 = V_13 ;
V_1 -> V_35 = F_1 ;
V_1 -> V_36 = V_12 ;
V_1 -> V_5 = & V_4 ;
V_1 -> V_37 = V_31 << 9 ;
V_14 -= V_31 ;
V_13 = V_32 ;
F_19 ( & V_4 . V_9 ) ;
F_20 ( type , V_1 ) ;
}
if ( ! F_3 ( & V_4 . V_9 ) )
F_21 ( & V_10 ) ;
if ( ! F_22 ( V_7 , & V_4 . V_8 ) )
V_24 = - V_38 ;
return V_24 ;
}
int F_23 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 V_14 , T_2 V_15 ,
struct V_39 * V_39 )
{
F_7 ( V_10 ) ;
struct V_16 * V_17 = F_8 ( V_12 ) ;
unsigned int V_40 ;
struct V_3 V_4 ;
struct V_1 * V_1 ;
int V_24 = 0 ;
if ( ! V_17 )
return - V_25 ;
V_40 = V_17 -> V_26 . V_40 ;
if ( V_40 == 0 )
return - V_6 ;
F_16 ( & V_4 . V_9 , 1 ) ;
V_4 . V_8 = 1 << V_7 ;
V_4 . V_10 = & V_10 ;
while ( V_14 ) {
V_1 = F_17 ( V_15 , 1 ) ;
if ( ! V_1 ) {
V_24 = - V_33 ;
break;
}
V_1 -> V_34 = V_13 ;
V_1 -> V_35 = F_1 ;
V_1 -> V_36 = V_12 ;
V_1 -> V_5 = & V_4 ;
V_1 -> V_41 = 1 ;
V_1 -> V_42 -> V_43 = V_39 ;
V_1 -> V_42 -> V_44 = 0 ;
V_1 -> V_42 -> V_45 = F_24 ( V_12 ) ;
if ( V_14 > V_40 ) {
V_1 -> V_37 = V_40 << 9 ;
V_14 -= V_40 ;
V_13 += V_40 ;
} else {
V_1 -> V_37 = V_14 << 9 ;
V_14 = 0 ;
}
F_19 ( & V_4 . V_9 ) ;
F_20 ( V_18 | V_46 , V_1 ) ;
}
if ( ! F_3 ( & V_4 . V_9 ) )
F_21 ( & V_10 ) ;
if ( ! F_22 ( V_7 , & V_4 . V_8 ) )
V_24 = - V_47 ;
return V_24 ;
}
int F_25 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 V_14 , T_2 V_15 )
{
int V_24 ;
struct V_1 * V_1 ;
struct V_3 V_4 ;
unsigned int V_48 ;
F_7 ( V_10 ) ;
F_16 ( & V_4 . V_9 , 1 ) ;
V_4 . V_8 = 1 << V_7 ;
V_4 . V_10 = & V_10 ;
V_24 = 0 ;
while ( V_14 != 0 ) {
V_1 = F_17 ( V_15 ,
F_12 ( V_14 , ( T_1 ) V_49 ) ) ;
if ( ! V_1 ) {
V_24 = - V_33 ;
break;
}
V_1 -> V_34 = V_13 ;
V_1 -> V_36 = V_12 ;
V_1 -> V_35 = F_1 ;
V_1 -> V_5 = & V_4 ;
while ( V_14 != 0 ) {
V_48 = F_12 ( ( T_1 ) V_50 >> 9 , V_14 ) ;
V_24 = F_26 ( V_1 , F_27 ( 0 ) , V_48 << 9 , 0 ) ;
V_14 -= V_24 >> 9 ;
V_13 += V_24 >> 9 ;
if ( V_24 < ( V_48 << 9 ) )
break;
}
V_24 = 0 ;
F_19 ( & V_4 . V_9 ) ;
F_20 ( V_51 , V_1 ) ;
}
if ( ! F_3 ( & V_4 . V_9 ) )
F_21 ( & V_10 ) ;
if ( ! F_22 ( V_7 , & V_4 . V_8 ) )
V_24 = - V_38 ;
return V_24 ;
}
int F_28 ( struct V_11 * V_12 , T_1 V_13 ,
T_1 V_14 , T_2 V_15 )
{
if ( F_29 ( V_12 ) ) {
unsigned char V_52 [ V_53 ] ;
if ( ! F_23 ( V_12 , V_13 , V_14 , V_15 ,
F_27 ( 0 ) ) )
return 0 ;
F_30 ( V_12 , V_52 ) ;
F_31 ( L_1 , V_52 ) ;
}
return F_25 ( V_12 , V_13 , V_14 , V_15 ) ;
}
