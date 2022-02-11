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
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_14 * V_15 , void T_1 * V_16 ,
unsigned int V_17 , T_2 V_18 )
{
unsigned long V_19 ;
struct V_5 * V_5 , * V_20 ;
int V_21 , V_12 ;
V_21 = F_9 ( V_4 ) == V_22 ;
V_19 = ( unsigned long ) V_16 ;
if ( F_10 ( V_2 , V_19 , V_17 ) && ! V_15 )
V_5 = F_11 ( V_2 , NULL , V_19 , V_17 , V_21 , V_18 ) ;
else
V_5 = F_12 ( V_2 , V_15 , V_19 , V_17 , V_21 , V_18 ) ;
if ( F_13 ( V_5 ) )
return F_14 ( V_5 ) ;
if ( V_15 && V_15 -> V_23 )
V_5 -> V_24 |= ( 1 << V_25 ) ;
V_20 = V_5 ;
F_15 ( V_2 , & V_5 ) ;
F_16 ( V_5 ) ;
V_12 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( ! V_12 )
return V_5 -> V_10 . V_11 ;
F_17 ( V_5 , 0 ) ;
F_4 ( V_20 ) ;
F_18 ( V_5 ) ;
return V_12 ;
}
int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_14 * V_15 , void T_1 * V_16 ,
unsigned long V_17 , T_2 V_18 )
{
unsigned long V_26 = 0 ;
struct V_5 * V_5 = NULL ;
int V_12 ;
if ( V_17 > ( F_20 ( V_2 ) << 9 ) )
return - V_6 ;
if ( ! V_17 )
return - V_6 ;
if ( ! V_16 && ( ! V_15 || ! V_15 -> V_23 ) )
return - V_6 ;
while ( V_26 != V_17 ) {
unsigned long V_27 , V_28 , V_29 ;
V_27 = F_21 (unsigned long, len - bytes_read, BIO_MAX_SIZE) ;
V_28 = ( ( unsigned long ) V_16 + V_27 + V_30 - 1 )
>> V_31 ;
V_29 = ( unsigned long ) V_16 >> V_31 ;
if ( V_28 - V_29 > V_32 )
V_27 -= V_30 ;
V_12 = F_8 ( V_2 , V_4 , V_15 , V_16 , V_27 ,
V_18 ) ;
if ( V_12 < 0 )
goto V_33;
if ( ! V_5 )
V_5 = V_4 -> V_5 ;
V_26 += V_12 ;
V_16 += V_12 ;
if ( V_15 )
V_15 -> V_34 += V_12 ;
}
if ( ! F_5 ( V_5 , V_13 ) )
V_4 -> V_35 |= V_36 ;
V_4 -> V_37 = NULL ;
return 0 ;
V_33:
F_22 ( V_5 ) ;
V_4 -> V_5 = NULL ;
return V_12 ;
}
int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_14 * V_15 , const struct V_38 * V_39 ,
int V_40 , unsigned int V_17 , T_2 V_18 )
{
struct V_5 * V_5 ;
int V_41 , V_42 = F_9 ( V_4 ) == V_22 ;
int V_43 = 0 ;
if ( ! V_39 || V_40 <= 0 )
return - V_6 ;
for ( V_41 = 0 ; V_41 < V_40 ; V_41 ++ ) {
unsigned long V_19 = ( unsigned long ) V_39 [ V_41 ] . V_44 ;
if ( ! V_39 [ V_41 ] . V_45 )
return - V_6 ;
if ( V_19 & F_24 ( V_2 ) )
V_43 = 1 ;
}
if ( V_43 || ( V_2 -> V_46 & V_17 ) || V_15 )
V_5 = F_25 ( V_2 , V_15 , V_39 , V_40 , V_42 ,
V_18 ) ;
else
V_5 = F_26 ( V_2 , NULL , V_39 , V_40 , V_42 , V_18 ) ;
if ( F_13 ( V_5 ) )
return F_14 ( V_5 ) ;
if ( V_5 -> V_10 . V_11 != V_17 ) {
F_16 ( V_5 ) ;
F_17 ( V_5 , 0 ) ;
F_4 ( V_5 ) ;
return - V_6 ;
}
if ( ! F_5 ( V_5 , V_13 ) )
V_4 -> V_35 |= V_36 ;
F_15 ( V_2 , & V_5 ) ;
F_16 ( V_5 ) ;
F_2 ( V_2 , V_4 , V_5 ) ;
V_4 -> V_37 = NULL ;
return 0 ;
}
int F_22 ( struct V_5 * V_5 )
{
struct V_5 * V_47 ;
int V_12 = 0 , V_48 ;
while ( V_5 ) {
V_47 = V_5 ;
if ( F_27 ( F_5 ( V_5 , V_49 ) ) )
V_47 = V_5 -> V_50 ;
V_48 = F_4 ( V_47 ) ;
if ( V_48 && ! V_12 )
V_12 = V_48 ;
V_47 = V_5 ;
V_5 = V_5 -> V_8 ;
F_18 ( V_47 ) ;
}
return V_12 ;
}
int F_28 ( struct V_1 * V_2 , struct V_3 * V_4 , void * V_51 ,
unsigned int V_17 , T_2 V_18 )
{
int V_21 = F_9 ( V_4 ) == V_22 ;
unsigned long V_52 = ( unsigned long ) V_51 ;
int V_53 = 0 ;
struct V_5 * V_5 ;
int V_12 ;
if ( V_17 > ( F_20 ( V_2 ) << 9 ) )
return - V_6 ;
if ( ! V_17 || ! V_51 )
return - V_6 ;
V_53 = ! F_10 ( V_2 , V_52 , V_17 ) || F_29 ( V_51 ) ;
if ( V_53 )
V_5 = F_30 ( V_2 , V_51 , V_17 , V_18 , V_21 ) ;
else
V_5 = F_31 ( V_2 , V_51 , V_17 , V_18 ) ;
if ( F_13 ( V_5 ) )
return F_14 ( V_5 ) ;
if ( ! V_21 )
V_5 -> V_54 |= V_55 ;
if ( V_53 )
V_4 -> V_35 |= V_36 ;
V_12 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( F_27 ( V_12 ) ) {
F_18 ( V_5 ) ;
return V_12 ;
}
F_15 ( V_2 , & V_4 -> V_5 ) ;
V_4 -> V_37 = NULL ;
return 0 ;
}
