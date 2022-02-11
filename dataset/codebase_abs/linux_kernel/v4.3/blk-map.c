static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_3 * V_5 )
{
unsigned long V_6 ;
if ( ! F_2 ( V_2 ) )
return false ;
if ( V_4 -> V_7 == NULL && V_4 -> V_8 == 0 )
return false ;
V_6 = ( unsigned long ) ( V_4 -> V_7 + V_4 -> V_8 ) ;
return ( ( ( unsigned long ) V_5 -> V_7 & F_2 ( V_2 ) ) ||
V_6 & F_2 ( V_2 ) ) ;
}
int F_3 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_11 * V_11 )
{
if ( ! V_10 -> V_11 )
F_4 ( V_2 , V_10 , V_11 ) ;
else if ( ! F_5 ( V_2 , V_10 , V_11 ) )
return - V_12 ;
else {
V_10 -> V_13 -> V_14 = V_11 ;
V_10 -> V_13 = V_11 ;
V_10 -> V_15 += V_11 -> V_16 . V_17 ;
}
return 0 ;
}
static int F_6 ( struct V_11 * V_11 )
{
int V_18 = 0 ;
if ( V_11 ) {
if ( F_7 ( V_11 , V_19 ) )
F_8 ( V_11 ) ;
else
V_18 = F_9 ( V_11 ) ;
}
return V_18 ;
}
int F_10 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_20 * V_21 ,
const struct V_22 * V_23 , T_1 V_24 )
{
struct V_11 * V_11 ;
int V_25 = 0 ;
struct V_22 V_26 ;
struct V_3 V_27 , V_4 = { . V_7 = NULL , . V_8 = 0 } ;
if ( ! V_23 || ! V_23 -> V_28 )
return - V_12 ;
F_11 (iov, i, *iter) {
unsigned long V_29 = ( unsigned long ) V_27 . V_7 ;
if ( ! V_27 . V_8 )
return - V_12 ;
if ( ( V_29 & F_12 ( V_2 ) ) ||
F_1 ( V_2 , & V_4 , & V_27 ) )
V_25 = 1 ;
V_4 . V_7 = V_27 . V_7 ;
V_4 . V_8 = V_27 . V_8 ;
}
if ( V_25 || ( V_2 -> V_30 & V_23 -> V_28 ) || V_21 )
V_11 = F_13 ( V_2 , V_21 , V_23 , V_24 ) ;
else
V_11 = F_14 ( V_2 , V_23 , V_24 ) ;
if ( F_15 ( V_11 ) )
return F_16 ( V_11 ) ;
if ( V_21 && V_21 -> V_31 )
F_17 ( V_11 , V_32 ) ;
if ( V_11 -> V_16 . V_17 != V_23 -> V_28 ) {
F_18 ( V_11 ) ;
F_19 ( V_11 ) ;
F_6 ( V_11 ) ;
return - V_12 ;
}
if ( ! F_7 ( V_11 , V_19 ) )
V_10 -> V_33 |= V_34 ;
F_20 ( V_2 , & V_11 ) ;
F_18 ( V_11 ) ;
F_4 ( V_2 , V_10 , V_11 ) ;
return 0 ;
}
int F_21 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_20 * V_21 , void T_2 * V_35 ,
unsigned long V_36 , T_1 V_24 )
{
struct V_3 V_27 ;
struct V_22 V_26 ;
int V_18 = F_22 ( F_23 ( V_10 ) , V_35 , V_36 , & V_27 , & V_26 ) ;
if ( F_24 ( V_18 < 0 ) )
return V_18 ;
return F_10 ( V_2 , V_10 , V_21 , & V_26 , V_24 ) ;
}
int F_25 ( struct V_11 * V_11 )
{
struct V_11 * V_37 ;
int V_18 = 0 , V_38 ;
while ( V_11 ) {
V_37 = V_11 ;
if ( F_24 ( F_7 ( V_11 , V_39 ) ) )
V_37 = V_11 -> V_40 ;
V_38 = F_6 ( V_37 ) ;
if ( V_38 && ! V_18 )
V_18 = V_38 ;
V_37 = V_11 ;
V_11 = V_11 -> V_14 ;
F_26 ( V_37 ) ;
}
return V_18 ;
}
int F_27 ( struct V_1 * V_2 , struct V_9 * V_10 , void * V_41 ,
unsigned int V_36 , T_1 V_24 )
{
int V_42 = F_23 ( V_10 ) == V_43 ;
unsigned long V_44 = ( unsigned long ) V_41 ;
int V_45 = 0 ;
struct V_11 * V_11 ;
int V_18 ;
if ( V_36 > ( F_28 ( V_2 ) << 9 ) )
return - V_12 ;
if ( ! V_36 || ! V_41 )
return - V_12 ;
V_45 = ! F_29 ( V_2 , V_44 , V_36 ) || F_30 ( V_41 ) ;
if ( V_45 )
V_11 = F_31 ( V_2 , V_41 , V_36 , V_24 , V_42 ) ;
else
V_11 = F_32 ( V_2 , V_41 , V_36 , V_24 ) ;
if ( F_15 ( V_11 ) )
return F_16 ( V_11 ) ;
if ( ! V_42 )
V_11 -> V_46 |= V_47 ;
if ( V_45 )
V_10 -> V_33 |= V_34 ;
V_18 = F_3 ( V_2 , V_10 , V_11 ) ;
if ( F_24 ( V_18 ) ) {
F_26 ( V_11 ) ;
return V_18 ;
}
F_20 ( V_2 , & V_10 -> V_11 ) ;
return 0 ;
}
