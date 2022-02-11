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
static int F_8 ( struct V_3 * V_4 ,
struct V_14 * V_15 , struct V_16 * V_17 ,
T_1 V_18 , bool V_19 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_5 * V_5 , * V_20 ;
int V_12 ;
if ( V_19 )
V_5 = F_9 ( V_2 , V_15 , V_17 , V_18 ) ;
else
V_5 = F_10 ( V_2 , V_17 , V_18 ) ;
if ( F_11 ( V_5 ) )
return F_12 ( V_5 ) ;
if ( V_15 && V_15 -> V_21 )
F_13 ( V_5 , V_22 ) ;
F_14 ( V_17 , V_5 -> V_10 . V_11 ) ;
if ( V_15 )
V_15 -> V_23 += V_5 -> V_10 . V_11 ;
V_20 = V_5 ;
F_15 ( V_2 , & V_5 ) ;
F_16 ( V_5 ) ;
V_12 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( V_12 ) {
F_17 ( V_5 ) ;
F_4 ( V_20 ) ;
F_18 ( V_5 ) ;
return V_12 ;
}
return 0 ;
}
int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_14 * V_15 ,
const struct V_16 * V_17 , T_1 V_18 )
{
bool V_19 = false ;
unsigned long V_24 = V_2 -> V_25 | F_20 ( V_2 ) ;
struct V_5 * V_5 = NULL ;
struct V_16 V_26 ;
int V_12 ;
if ( V_15 )
V_19 = true ;
else if ( F_21 ( V_17 ) & V_24 )
V_19 = true ;
else if ( F_22 ( V_2 ) )
V_19 = F_22 ( V_2 ) & F_23 ( V_17 ) ;
V_26 = * V_17 ;
do {
V_12 = F_8 ( V_4 , V_15 , & V_26 , V_18 , V_19 ) ;
if ( V_12 )
goto V_27;
if ( ! V_5 )
V_5 = V_4 -> V_5 ;
} while ( F_24 ( & V_26 ) );
if ( ! F_5 ( V_5 , V_13 ) )
V_4 -> V_28 |= V_29 ;
return 0 ;
V_27:
F_4 ( V_5 ) ;
V_4 -> V_5 = NULL ;
return - V_6 ;
}
int F_25 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_14 * V_15 , void T_2 * V_30 ,
unsigned long V_31 , T_1 V_18 )
{
struct V_32 V_33 ;
struct V_16 V_26 ;
int V_12 = F_26 ( F_27 ( V_4 ) , V_30 , V_31 , & V_33 , & V_26 ) ;
if ( F_28 ( V_12 < 0 ) )
return V_12 ;
return F_19 ( V_2 , V_4 , V_15 , & V_26 , V_18 ) ;
}
int F_29 ( struct V_5 * V_5 )
{
struct V_5 * V_34 ;
int V_12 = 0 , V_35 ;
while ( V_5 ) {
V_34 = V_5 ;
if ( F_28 ( F_5 ( V_5 , V_36 ) ) )
V_34 = V_5 -> V_37 ;
V_35 = F_4 ( V_34 ) ;
if ( V_35 && ! V_12 )
V_12 = V_35 ;
V_34 = V_5 ;
V_5 = V_5 -> V_8 ;
F_18 ( V_34 ) ;
}
return V_12 ;
}
int F_30 ( struct V_1 * V_2 , struct V_3 * V_4 , void * V_38 ,
unsigned int V_31 , T_1 V_18 )
{
int V_39 = F_27 ( V_4 ) == V_40 ;
unsigned long V_41 = ( unsigned long ) V_38 ;
int V_42 = 0 ;
struct V_5 * V_5 ;
int V_12 ;
if ( V_31 > ( F_31 ( V_2 ) << 9 ) )
return - V_6 ;
if ( ! V_31 || ! V_38 )
return - V_6 ;
V_42 = ! F_32 ( V_2 , V_41 , V_31 ) || F_33 ( V_38 ) ;
if ( V_42 )
V_5 = F_34 ( V_2 , V_38 , V_31 , V_18 , V_39 ) ;
else
V_5 = F_35 ( V_2 , V_38 , V_31 , V_18 ) ;
if ( F_11 ( V_5 ) )
return F_12 ( V_5 ) ;
if ( ! V_39 )
V_5 -> V_43 |= V_44 ;
if ( V_42 )
V_4 -> V_28 |= V_29 ;
V_12 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( F_28 ( V_12 ) ) {
F_18 ( V_5 ) ;
return V_12 ;
}
F_15 ( V_2 , & V_4 -> V_5 ) ;
return 0 ;
}
