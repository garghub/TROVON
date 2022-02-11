int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_5 )
{
if ( ! V_4 -> V_5 )
F_2 ( V_2 , V_4 , V_5 ) ;
else if ( ! F_3 ( V_2 , V_4 , V_5 ) )
return - V_6 ;
else {
V_4 -> V_7 -> V_8 = V_5 ;
V_4 -> V_7 = V_5 ;
V_4 -> V_9 += V_5 -> V_10 . V_11 ;
}
return 0 ;
}
static int F_4 ( struct V_5 * V_5 )
{
int V_12 = 0 ;
if ( V_5 ) {
if ( F_5 ( V_5 , V_13 ) )
F_6 ( V_5 ) ;
else
V_12 = F_7 ( V_5 ) ;
}
return V_12 ;
}
int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_14 * V_15 ,
const struct V_16 * V_17 , T_1 V_18 )
{
struct V_5 * V_5 ;
int V_19 = 0 ;
struct V_16 V_20 ;
struct V_21 V_22 ;
if ( ! V_17 || ! V_17 -> V_23 )
return - V_6 ;
F_9 (iov, i, *iter) {
unsigned long V_24 = ( unsigned long ) V_22 . V_25 ;
if ( ! V_22 . V_26 )
return - V_6 ;
if ( V_24 & F_10 ( V_2 ) )
V_19 = 1 ;
}
if ( V_19 || ( V_2 -> V_27 & V_17 -> V_23 ) || V_15 )
V_5 = F_11 ( V_2 , V_15 , V_17 , V_18 ) ;
else
V_5 = F_12 ( V_2 , V_17 , V_18 ) ;
if ( F_13 ( V_5 ) )
return F_14 ( V_5 ) ;
if ( V_15 && V_15 -> V_28 )
V_5 -> V_29 |= ( 1 << V_30 ) ;
if ( V_5 -> V_10 . V_11 != V_17 -> V_23 ) {
F_15 ( V_5 ) ;
F_16 ( V_5 , 0 ) ;
F_4 ( V_5 ) ;
return - V_6 ;
}
if ( ! F_5 ( V_5 , V_13 ) )
V_4 -> V_31 |= V_32 ;
F_17 ( V_2 , & V_5 ) ;
F_15 ( V_5 ) ;
F_2 ( V_2 , V_4 , V_5 ) ;
return 0 ;
}
int F_18 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_14 * V_15 , void T_2 * V_33 ,
unsigned long V_34 , T_1 V_18 )
{
struct V_21 V_22 ;
struct V_16 V_20 ;
int V_12 = F_19 ( F_20 ( V_4 ) , V_33 , V_34 , & V_22 , & V_20 ) ;
if ( F_21 ( V_12 < 0 ) )
return V_12 ;
return F_8 ( V_2 , V_4 , V_15 , & V_20 , V_18 ) ;
}
int F_22 ( struct V_5 * V_5 )
{
struct V_5 * V_35 ;
int V_12 = 0 , V_36 ;
while ( V_5 ) {
V_35 = V_5 ;
if ( F_21 ( F_5 ( V_5 , V_37 ) ) )
V_35 = V_5 -> V_38 ;
V_36 = F_4 ( V_35 ) ;
if ( V_36 && ! V_12 )
V_12 = V_36 ;
V_35 = V_5 ;
V_5 = V_5 -> V_8 ;
F_23 ( V_35 ) ;
}
return V_12 ;
}
int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 , void * V_39 ,
unsigned int V_34 , T_1 V_18 )
{
int V_40 = F_20 ( V_4 ) == V_41 ;
unsigned long V_42 = ( unsigned long ) V_39 ;
int V_43 = 0 ;
struct V_5 * V_5 ;
int V_12 ;
if ( V_34 > ( F_25 ( V_2 ) << 9 ) )
return - V_6 ;
if ( ! V_34 || ! V_39 )
return - V_6 ;
V_43 = ! F_26 ( V_2 , V_42 , V_34 ) || F_27 ( V_39 ) ;
if ( V_43 )
V_5 = F_28 ( V_2 , V_39 , V_34 , V_18 , V_40 ) ;
else
V_5 = F_29 ( V_2 , V_39 , V_34 , V_18 ) ;
if ( F_13 ( V_5 ) )
return F_14 ( V_5 ) ;
if ( ! V_40 )
V_5 -> V_44 |= V_45 ;
if ( V_43 )
V_4 -> V_31 |= V_32 ;
V_12 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( F_21 ( V_12 ) ) {
F_23 ( V_5 ) ;
return V_12 ;
}
F_17 ( V_2 , & V_4 -> V_5 ) ;
return 0 ;
}
