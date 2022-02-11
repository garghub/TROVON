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
static int F_10 ( struct V_9 * V_10 ,
struct V_20 * V_21 , struct V_22 * V_23 ,
T_1 V_24 , bool V_25 )
{
struct V_1 * V_2 = V_10 -> V_2 ;
struct V_11 * V_11 , * V_26 ;
int V_18 ;
if ( V_25 )
V_11 = F_11 ( V_2 , V_21 , V_23 , V_24 ) ;
else
V_11 = F_12 ( V_2 , V_23 , V_24 ) ;
if ( F_13 ( V_11 ) )
return F_14 ( V_11 ) ;
if ( V_21 && V_21 -> V_27 )
F_15 ( V_11 , V_28 ) ;
F_16 ( V_23 , V_11 -> V_16 . V_17 ) ;
if ( V_21 )
V_21 -> V_29 += V_11 -> V_16 . V_17 ;
V_26 = V_11 ;
F_17 ( V_2 , & V_11 ) ;
F_18 ( V_11 ) ;
V_18 = F_3 ( V_2 , V_10 , V_11 ) ;
if ( V_18 ) {
F_19 ( V_11 ) ;
F_6 ( V_26 ) ;
F_20 ( V_11 ) ;
return V_18 ;
}
return 0 ;
}
int F_21 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_20 * V_21 ,
const struct V_22 * V_23 , T_1 V_24 )
{
struct V_3 V_30 , V_4 = { . V_7 = NULL , . V_8 = 0 } ;
bool V_25 = ( V_2 -> V_31 & V_23 -> V_32 ) || V_21 ;
struct V_11 * V_11 = NULL ;
struct V_22 V_33 ;
int V_18 ;
if ( ! V_23 || ! V_23 -> V_32 )
return - V_12 ;
F_22 (iov, i, *iter) {
unsigned long V_34 = ( unsigned long ) V_30 . V_7 ;
if ( ! V_30 . V_8 )
return - V_12 ;
if ( ( V_34 & F_23 ( V_2 ) ) ||
F_1 ( V_2 , & V_4 , & V_30 ) )
V_25 = true ;
V_4 . V_7 = V_30 . V_7 ;
V_4 . V_8 = V_30 . V_8 ;
}
V_33 = * V_23 ;
do {
V_18 = F_10 ( V_10 , V_21 , & V_33 , V_24 , V_25 ) ;
if ( V_18 )
goto V_35;
if ( ! V_11 )
V_11 = V_10 -> V_11 ;
} while ( F_24 ( & V_33 ) );
if ( ! F_7 ( V_11 , V_19 ) )
V_10 -> V_36 |= V_37 ;
return 0 ;
V_35:
F_6 ( V_11 ) ;
V_10 -> V_11 = NULL ;
return - V_12 ;
}
int F_25 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_20 * V_21 , void T_2 * V_38 ,
unsigned long V_39 , T_1 V_24 )
{
struct V_3 V_30 ;
struct V_22 V_33 ;
int V_18 = F_26 ( F_27 ( V_10 ) , V_38 , V_39 , & V_30 , & V_33 ) ;
if ( F_28 ( V_18 < 0 ) )
return V_18 ;
return F_21 ( V_2 , V_10 , V_21 , & V_33 , V_24 ) ;
}
int F_29 ( struct V_11 * V_11 )
{
struct V_11 * V_40 ;
int V_18 = 0 , V_41 ;
while ( V_11 ) {
V_40 = V_11 ;
if ( F_28 ( F_7 ( V_11 , V_42 ) ) )
V_40 = V_11 -> V_43 ;
V_41 = F_6 ( V_40 ) ;
if ( V_41 && ! V_18 )
V_18 = V_41 ;
V_40 = V_11 ;
V_11 = V_11 -> V_14 ;
F_20 ( V_40 ) ;
}
return V_18 ;
}
int F_30 ( struct V_1 * V_2 , struct V_9 * V_10 , void * V_44 ,
unsigned int V_39 , T_1 V_24 )
{
int V_45 = F_27 ( V_10 ) == V_46 ;
unsigned long V_47 = ( unsigned long ) V_44 ;
int V_48 = 0 ;
struct V_11 * V_11 ;
int V_18 ;
if ( V_39 > ( F_31 ( V_2 ) << 9 ) )
return - V_12 ;
if ( ! V_39 || ! V_44 )
return - V_12 ;
V_48 = ! F_32 ( V_2 , V_47 , V_39 ) || F_33 ( V_44 ) ;
if ( V_48 )
V_11 = F_34 ( V_2 , V_44 , V_39 , V_24 , V_45 ) ;
else
V_11 = F_35 ( V_2 , V_44 , V_39 , V_24 ) ;
if ( F_13 ( V_11 ) )
return F_14 ( V_11 ) ;
if ( ! V_45 )
V_11 -> V_49 |= V_50 ;
if ( V_48 )
V_10 -> V_36 |= V_37 ;
V_18 = F_3 ( V_2 , V_10 , V_11 ) ;
if ( F_28 ( V_18 ) ) {
F_20 ( V_11 ) ;
return V_18 ;
}
F_17 ( V_2 , & V_10 -> V_11 ) ;
return 0 ;
}
