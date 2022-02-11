int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
if ( ! V_2 -> V_3 ) {
F_2 ( V_2 -> V_4 , V_2 , V_3 ) ;
} else {
if ( ! F_3 ( V_2 -> V_4 , V_2 , V_3 ) )
return - V_5 ;
V_2 -> V_6 -> V_7 = V_3 ;
V_2 -> V_6 = V_3 ;
V_2 -> V_8 += V_3 -> V_9 . V_10 ;
}
return 0 ;
}
static int F_4 ( struct V_3 * V_3 )
{
int V_11 = 0 ;
if ( V_3 ) {
if ( F_5 ( V_3 , V_12 ) )
F_6 ( V_3 ) ;
else
V_11 = F_7 ( V_3 ) ;
}
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_13 * V_14 , struct V_15 * V_16 ,
T_1 V_17 , bool V_18 )
{
struct V_19 * V_4 = V_2 -> V_4 ;
struct V_3 * V_3 , * V_20 ;
int V_11 ;
if ( V_18 )
V_3 = F_9 ( V_4 , V_14 , V_16 , V_17 ) ;
else
V_3 = F_10 ( V_4 , V_16 , V_17 ) ;
if ( F_11 ( V_3 ) )
return F_12 ( V_3 ) ;
V_3 -> V_21 &= ~ V_22 ;
V_3 -> V_21 |= F_13 ( V_2 ) ;
if ( V_14 && V_14 -> V_23 )
F_14 ( V_3 , V_24 ) ;
F_15 ( V_16 , V_3 -> V_9 . V_10 ) ;
if ( V_14 )
V_14 -> V_25 += V_3 -> V_9 . V_10 ;
V_20 = V_3 ;
F_16 ( V_4 , & V_3 ) ;
F_17 ( V_3 ) ;
V_11 = F_1 ( V_2 , V_3 ) ;
if ( V_11 ) {
F_18 ( V_3 ) ;
F_4 ( V_20 ) ;
F_19 ( V_3 ) ;
return V_11 ;
}
return 0 ;
}
int F_20 ( struct V_19 * V_4 , struct V_1 * V_2 ,
struct V_13 * V_14 ,
const struct V_15 * V_16 , T_1 V_17 )
{
bool V_18 = false ;
unsigned long V_26 = V_4 -> V_27 | F_21 ( V_4 ) ;
struct V_3 * V_3 = NULL ;
struct V_15 V_28 ;
int V_11 ;
if ( ! F_22 ( V_16 ) )
goto V_29;
if ( V_14 )
V_18 = true ;
else if ( F_23 ( V_16 ) & V_26 )
V_18 = true ;
else if ( F_24 ( V_4 ) )
V_18 = F_24 ( V_4 ) & F_25 ( V_16 ) ;
V_28 = * V_16 ;
do {
V_11 = F_8 ( V_2 , V_14 , & V_28 , V_17 , V_18 ) ;
if ( V_11 )
goto V_30;
if ( ! V_3 )
V_3 = V_2 -> V_3 ;
} while ( F_26 ( & V_28 ) );
if ( ! F_5 ( V_3 , V_12 ) )
V_2 -> V_31 |= V_32 ;
return 0 ;
V_30:
F_4 ( V_3 ) ;
V_29:
V_2 -> V_3 = NULL ;
return - V_5 ;
}
int F_27 ( struct V_19 * V_4 , struct V_1 * V_2 ,
struct V_13 * V_14 , void T_2 * V_33 ,
unsigned long V_34 , T_1 V_17 )
{
struct V_35 V_36 ;
struct V_15 V_28 ;
int V_11 = F_28 ( F_29 ( V_2 ) , V_33 , V_34 , & V_36 , & V_28 ) ;
if ( F_30 ( V_11 < 0 ) )
return V_11 ;
return F_20 ( V_4 , V_2 , V_14 , & V_28 , V_17 ) ;
}
int F_31 ( struct V_3 * V_3 )
{
struct V_3 * V_37 ;
int V_11 = 0 , V_38 ;
while ( V_3 ) {
V_37 = V_3 ;
if ( F_30 ( F_5 ( V_3 , V_39 ) ) )
V_37 = V_3 -> V_40 ;
V_38 = F_4 ( V_37 ) ;
if ( V_38 && ! V_11 )
V_11 = V_38 ;
V_37 = V_3 ;
V_3 = V_3 -> V_7 ;
F_19 ( V_37 ) ;
}
return V_11 ;
}
int F_32 ( struct V_19 * V_4 , struct V_1 * V_2 , void * V_41 ,
unsigned int V_34 , T_1 V_17 )
{
int V_42 = F_29 ( V_2 ) == V_43 ;
unsigned long V_44 = ( unsigned long ) V_41 ;
int V_45 = 0 ;
struct V_3 * V_3 ;
int V_11 ;
if ( V_34 > ( F_33 ( V_4 ) << 9 ) )
return - V_5 ;
if ( ! V_34 || ! V_41 )
return - V_5 ;
V_45 = ! F_34 ( V_4 , V_44 , V_34 ) || F_35 ( V_41 ) ;
if ( V_45 )
V_3 = F_36 ( V_4 , V_41 , V_34 , V_17 , V_42 ) ;
else
V_3 = F_37 ( V_4 , V_41 , V_34 , V_17 ) ;
if ( F_11 ( V_3 ) )
return F_12 ( V_3 ) ;
V_3 -> V_21 &= ~ V_22 ;
V_3 -> V_21 |= F_13 ( V_2 ) ;
if ( V_45 )
V_2 -> V_31 |= V_32 ;
V_11 = F_1 ( V_2 , V_3 ) ;
if ( F_30 ( V_11 ) ) {
F_19 ( V_3 ) ;
return V_11 ;
}
F_16 ( V_4 , & V_2 -> V_3 ) ;
return 0 ;
}
