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
if ( V_14 && V_14 -> V_21 )
F_13 ( V_3 , V_22 ) ;
F_14 ( V_16 , V_3 -> V_9 . V_10 ) ;
if ( V_14 )
V_14 -> V_23 += V_3 -> V_9 . V_10 ;
V_20 = V_3 ;
F_15 ( V_4 , & V_3 ) ;
F_16 ( V_3 ) ;
V_11 = F_1 ( V_2 , V_3 ) ;
if ( V_11 ) {
F_17 ( V_3 ) ;
F_4 ( V_20 ) ;
F_18 ( V_3 ) ;
return V_11 ;
}
return 0 ;
}
int F_19 ( struct V_19 * V_4 , struct V_1 * V_2 ,
struct V_13 * V_14 ,
const struct V_15 * V_16 , T_1 V_17 )
{
bool V_18 = false ;
unsigned long V_24 = V_4 -> V_25 | F_20 ( V_4 ) ;
struct V_3 * V_3 = NULL ;
struct V_15 V_26 ;
int V_11 ;
if ( V_14 )
V_18 = true ;
else if ( F_21 ( V_16 ) & V_24 )
V_18 = true ;
else if ( F_22 ( V_4 ) )
V_18 = F_22 ( V_4 ) & F_23 ( V_16 ) ;
V_26 = * V_16 ;
do {
V_11 = F_8 ( V_2 , V_14 , & V_26 , V_17 , V_18 ) ;
if ( V_11 )
goto V_27;
if ( ! V_3 )
V_3 = V_2 -> V_3 ;
} while ( F_24 ( & V_26 ) );
if ( ! F_5 ( V_3 , V_12 ) )
V_2 -> V_28 |= V_29 ;
return 0 ;
V_27:
F_4 ( V_3 ) ;
V_2 -> V_3 = NULL ;
return - V_5 ;
}
int F_25 ( struct V_19 * V_4 , struct V_1 * V_2 ,
struct V_13 * V_14 , void T_2 * V_30 ,
unsigned long V_31 , T_1 V_17 )
{
struct V_32 V_33 ;
struct V_15 V_26 ;
int V_11 = F_26 ( F_27 ( V_2 ) , V_30 , V_31 , & V_33 , & V_26 ) ;
if ( F_28 ( V_11 < 0 ) )
return V_11 ;
return F_19 ( V_4 , V_2 , V_14 , & V_26 , V_17 ) ;
}
int F_29 ( struct V_3 * V_3 )
{
struct V_3 * V_34 ;
int V_11 = 0 , V_35 ;
while ( V_3 ) {
V_34 = V_3 ;
if ( F_28 ( F_5 ( V_3 , V_36 ) ) )
V_34 = V_3 -> V_37 ;
V_35 = F_4 ( V_34 ) ;
if ( V_35 && ! V_11 )
V_11 = V_35 ;
V_34 = V_3 ;
V_3 = V_3 -> V_7 ;
F_18 ( V_34 ) ;
}
return V_11 ;
}
int F_30 ( struct V_19 * V_4 , struct V_1 * V_2 , void * V_38 ,
unsigned int V_31 , T_1 V_17 )
{
int V_39 = F_27 ( V_2 ) == V_40 ;
unsigned long V_41 = ( unsigned long ) V_38 ;
int V_42 = 0 ;
struct V_3 * V_3 ;
int V_11 ;
if ( V_31 > ( F_31 ( V_4 ) << 9 ) )
return - V_5 ;
if ( ! V_31 || ! V_38 )
return - V_5 ;
V_42 = ! F_32 ( V_4 , V_41 , V_31 ) || F_33 ( V_38 ) ;
if ( V_42 )
V_3 = F_34 ( V_4 , V_38 , V_31 , V_17 , V_39 ) ;
else
V_3 = F_35 ( V_4 , V_38 , V_31 , V_17 ) ;
if ( F_11 ( V_3 ) )
return F_12 ( V_3 ) ;
if ( ! V_39 )
F_36 ( V_3 , V_43 , 0 ) ;
if ( V_42 )
V_2 -> V_28 |= V_29 ;
V_11 = F_1 ( V_2 , V_3 ) ;
if ( F_28 ( V_11 ) ) {
F_18 ( V_3 ) ;
return V_11 ;
}
F_15 ( V_4 , & V_2 -> V_3 ) ;
return 0 ;
}
