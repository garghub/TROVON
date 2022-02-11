static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
if ( V_1 -> V_5 && V_1 -> V_5 != - V_6 )
V_3 -> error = V_1 -> V_5 ;
if ( F_2 ( & V_3 -> V_7 ) )
F_3 ( V_3 -> V_8 ) ;
F_4 ( V_1 ) ;
}
int F_5 ( struct V_9 * V_10 , T_1 V_11 ,
T_1 V_12 , T_2 V_13 , unsigned long V_14 )
{
F_6 ( V_8 ) ;
struct V_15 * V_16 = F_7 ( V_10 ) ;
int type = V_17 | V_18 ;
unsigned int V_19 ;
int V_20 ;
struct V_2 V_3 ;
struct V_1 * V_1 ;
int V_21 = 0 ;
struct V_22 V_23 ;
if ( ! V_16 )
return - V_24 ;
if ( ! F_8 ( V_16 ) )
return - V_6 ;
V_19 = F_9 ( V_16 -> V_25 . V_26 >> 9 , 1U ) ;
V_20 = ( F_10 ( V_10 ) >> 9 ) % V_19 ;
if ( V_14 & V_27 ) {
if ( ! F_11 ( V_16 ) )
return - V_6 ;
type |= V_28 ;
}
F_12 ( & V_3 . V_7 , 1 ) ;
V_3 . error = 0 ;
V_3 . V_8 = & V_8 ;
F_13 ( & V_23 ) ;
while ( V_12 ) {
unsigned int V_29 ;
T_1 V_30 , V_31 ;
V_1 = F_14 ( V_13 , 1 ) ;
if ( ! V_1 ) {
V_21 = - V_32 ;
break;
}
V_29 = F_15 ( T_1 , V_12 , V_33 >> 9 ) ;
V_30 = V_11 + V_29 ;
V_31 = V_30 ;
if ( V_29 < V_12 &&
F_16 ( V_31 , V_19 ) != V_20 ) {
V_30 = V_30 - V_20 ;
F_16 ( V_30 , V_19 ) ;
V_30 = V_30 * V_19 + V_20 ;
V_29 = V_30 - V_11 ;
}
V_1 -> V_34 . V_35 = V_11 ;
V_1 -> V_36 = F_1 ;
V_1 -> V_37 = V_10 ;
V_1 -> V_4 = & V_3 ;
V_1 -> V_34 . V_38 = V_29 << 9 ;
V_12 -= V_29 ;
V_11 = V_30 ;
F_17 ( & V_3 . V_7 ) ;
F_18 ( type , V_1 ) ;
F_19 () ;
}
F_20 ( & V_23 ) ;
if ( ! F_2 ( & V_3 . V_7 ) )
F_21 ( & V_8 ) ;
if ( V_3 . error )
return V_3 . error ;
return V_21 ;
}
int F_22 ( struct V_9 * V_10 , T_1 V_11 ,
T_1 V_12 , T_2 V_13 ,
struct V_39 * V_39 )
{
F_6 ( V_8 ) ;
struct V_15 * V_16 = F_7 ( V_10 ) ;
unsigned int V_40 ;
struct V_2 V_3 ;
struct V_1 * V_1 ;
int V_21 = 0 ;
if ( ! V_16 )
return - V_24 ;
V_40 = V_33 >> 9 ;
F_12 ( & V_3 . V_7 , 1 ) ;
V_3 . error = 0 ;
V_3 . V_8 = & V_8 ;
while ( V_12 ) {
V_1 = F_14 ( V_13 , 1 ) ;
if ( ! V_1 ) {
V_21 = - V_32 ;
break;
}
V_1 -> V_34 . V_35 = V_11 ;
V_1 -> V_36 = F_1 ;
V_1 -> V_37 = V_10 ;
V_1 -> V_4 = & V_3 ;
V_1 -> V_41 = 1 ;
V_1 -> V_42 -> V_43 = V_39 ;
V_1 -> V_42 -> V_44 = 0 ;
V_1 -> V_42 -> V_45 = F_23 ( V_10 ) ;
if ( V_12 > V_40 ) {
V_1 -> V_34 . V_38 = V_40 << 9 ;
V_12 -= V_40 ;
V_11 += V_40 ;
} else {
V_1 -> V_34 . V_38 = V_12 << 9 ;
V_12 = 0 ;
}
F_17 ( & V_3 . V_7 ) ;
F_18 ( V_17 | V_46 , V_1 ) ;
}
if ( ! F_2 ( & V_3 . V_7 ) )
F_21 ( & V_8 ) ;
if ( V_3 . error )
return V_3 . error ;
return V_21 ;
}
static int F_24 ( struct V_9 * V_10 , T_1 V_11 ,
T_1 V_12 , T_2 V_13 )
{
int V_21 ;
struct V_1 * V_1 ;
struct V_2 V_3 ;
unsigned int V_47 ;
F_6 ( V_8 ) ;
F_12 ( & V_3 . V_7 , 1 ) ;
V_3 . error = 0 ;
V_3 . V_8 = & V_8 ;
V_21 = 0 ;
while ( V_12 != 0 ) {
V_1 = F_14 ( V_13 ,
F_25 ( V_12 , ( T_1 ) V_48 ) ) ;
if ( ! V_1 ) {
V_21 = - V_32 ;
break;
}
V_1 -> V_34 . V_35 = V_11 ;
V_1 -> V_37 = V_10 ;
V_1 -> V_36 = F_1 ;
V_1 -> V_4 = & V_3 ;
while ( V_12 != 0 ) {
V_47 = F_25 ( ( T_1 ) V_49 >> 9 , V_12 ) ;
V_21 = F_26 ( V_1 , F_27 ( 0 ) , V_47 << 9 , 0 ) ;
V_12 -= V_21 >> 9 ;
V_11 += V_21 >> 9 ;
if ( V_21 < ( V_47 << 9 ) )
break;
}
V_21 = 0 ;
F_17 ( & V_3 . V_7 ) ;
F_18 ( V_50 , V_1 ) ;
}
if ( ! F_2 ( & V_3 . V_7 ) )
F_21 ( & V_8 ) ;
if ( V_3 . error )
return V_3 . error ;
return V_21 ;
}
int F_28 ( struct V_9 * V_10 , T_1 V_11 ,
T_1 V_12 , T_2 V_13 , bool V_51 )
{
struct V_15 * V_16 = F_7 ( V_10 ) ;
if ( V_51 && F_8 ( V_16 ) && V_16 -> V_25 . V_52 &&
F_5 ( V_10 , V_11 , V_12 , V_13 , 0 ) == 0 )
return 0 ;
if ( F_29 ( V_10 ) &&
F_22 ( V_10 , V_11 , V_12 , V_13 ,
F_27 ( 0 ) ) == 0 )
return 0 ;
return F_24 ( V_10 , V_11 , V_12 , V_13 ) ;
}
