int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
if ( ! V_2 -> V_3 ) {
V_2 -> V_4 &= V_5 ;
V_2 -> V_4 |= ( V_3 -> V_6 & V_5 ) ;
F_2 ( V_2 -> V_7 , V_2 , V_3 ) ;
} else {
if ( ! F_3 ( V_2 -> V_7 , V_2 , V_3 ) )
return - V_8 ;
V_2 -> V_9 -> V_10 = V_3 ;
V_2 -> V_9 = V_3 ;
V_2 -> V_11 += V_3 -> V_12 . V_13 ;
}
return 0 ;
}
static int F_4 ( struct V_3 * V_3 )
{
int V_14 = 0 ;
if ( V_3 ) {
if ( F_5 ( V_3 , V_15 ) )
F_6 ( V_3 ) ;
else
V_14 = F_7 ( V_3 ) ;
}
return V_14 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_16 * V_17 , struct V_18 * V_19 ,
T_1 V_20 , bool V_21 )
{
struct V_22 * V_7 = V_2 -> V_7 ;
struct V_3 * V_3 , * V_23 ;
int V_14 ;
if ( V_21 )
V_3 = F_9 ( V_7 , V_17 , V_19 , V_20 ) ;
else
V_3 = F_10 ( V_7 , V_19 , V_20 ) ;
if ( F_11 ( V_3 ) )
return F_12 ( V_3 ) ;
if ( V_17 && V_17 -> V_24 )
F_13 ( V_3 , V_25 ) ;
F_14 ( V_19 , V_3 -> V_12 . V_13 ) ;
if ( V_17 )
V_17 -> V_26 += V_3 -> V_12 . V_13 ;
V_23 = V_3 ;
F_15 ( V_7 , & V_3 ) ;
F_16 ( V_3 ) ;
V_14 = F_1 ( V_2 , V_3 ) ;
if ( V_14 ) {
F_17 ( V_3 ) ;
F_4 ( V_23 ) ;
F_18 ( V_3 ) ;
return V_14 ;
}
return 0 ;
}
int F_19 ( struct V_22 * V_7 , struct V_1 * V_2 ,
struct V_16 * V_17 ,
const struct V_18 * V_19 , T_1 V_20 )
{
bool V_21 = false ;
unsigned long V_27 = V_7 -> V_28 | F_20 ( V_7 ) ;
struct V_3 * V_3 = NULL ;
struct V_18 V_29 ;
int V_14 ;
if ( ! F_21 ( V_19 ) )
goto V_30;
if ( V_17 )
V_21 = true ;
else if ( F_22 ( V_19 ) & V_27 )
V_21 = true ;
else if ( F_23 ( V_7 ) )
V_21 = F_23 ( V_7 ) & F_24 ( V_19 ) ;
V_29 = * V_19 ;
do {
V_14 = F_8 ( V_2 , V_17 , & V_29 , V_20 , V_21 ) ;
if ( V_14 )
goto V_31;
if ( ! V_3 )
V_3 = V_2 -> V_3 ;
} while ( F_25 ( & V_29 ) );
if ( ! F_5 ( V_3 , V_15 ) )
V_2 -> V_32 |= V_33 ;
return 0 ;
V_31:
F_4 ( V_3 ) ;
V_30:
V_2 -> V_3 = NULL ;
return - V_8 ;
}
int F_26 ( struct V_22 * V_7 , struct V_1 * V_2 ,
struct V_16 * V_17 , void T_2 * V_34 ,
unsigned long V_35 , T_1 V_20 )
{
struct V_36 V_37 ;
struct V_18 V_29 ;
int V_14 = F_27 ( F_28 ( V_2 ) , V_34 , V_35 , & V_37 , & V_29 ) ;
if ( F_29 ( V_14 < 0 ) )
return V_14 ;
return F_19 ( V_7 , V_2 , V_17 , & V_29 , V_20 ) ;
}
int F_30 ( struct V_3 * V_3 )
{
struct V_3 * V_38 ;
int V_14 = 0 , V_39 ;
while ( V_3 ) {
V_38 = V_3 ;
if ( F_29 ( F_5 ( V_3 , V_40 ) ) )
V_38 = V_3 -> V_41 ;
V_39 = F_4 ( V_38 ) ;
if ( V_39 && ! V_14 )
V_14 = V_39 ;
V_38 = V_3 ;
V_3 = V_3 -> V_10 ;
F_18 ( V_38 ) ;
}
return V_14 ;
}
int F_31 ( struct V_22 * V_7 , struct V_1 * V_2 , void * V_42 ,
unsigned int V_35 , T_1 V_20 )
{
int V_43 = F_28 ( V_2 ) == V_44 ;
unsigned long V_45 = ( unsigned long ) V_42 ;
int V_46 = 0 ;
struct V_3 * V_3 ;
int V_14 ;
if ( V_35 > ( F_32 ( V_7 ) << 9 ) )
return - V_8 ;
if ( ! V_35 || ! V_42 )
return - V_8 ;
V_46 = ! F_33 ( V_7 , V_45 , V_35 ) || F_34 ( V_42 ) ;
if ( V_46 )
V_3 = F_35 ( V_7 , V_42 , V_35 , V_20 , V_43 ) ;
else
V_3 = F_36 ( V_7 , V_42 , V_35 , V_20 ) ;
if ( F_11 ( V_3 ) )
return F_12 ( V_3 ) ;
if ( ! V_43 )
F_37 ( V_3 , V_47 , 0 ) ;
if ( V_46 )
V_2 -> V_32 |= V_33 ;
V_14 = F_1 ( V_2 , V_3 ) ;
if ( F_29 ( V_14 ) ) {
F_18 ( V_3 ) ;
return V_14 ;
}
F_15 ( V_7 , & V_2 -> V_3 ) ;
return 0 ;
}
