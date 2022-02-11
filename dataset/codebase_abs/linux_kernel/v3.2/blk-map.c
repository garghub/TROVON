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
V_4 -> V_9 += V_5 -> V_10 ;
}
return 0 ;
}
static int F_4 ( struct V_5 * V_5 )
{
int V_11 = 0 ;
if ( V_5 ) {
if ( F_5 ( V_5 , V_12 ) )
F_6 ( V_5 ) ;
else
V_11 = F_7 ( V_5 ) ;
}
return V_11 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_13 * V_14 , void T_1 * V_15 ,
unsigned int V_16 , T_2 V_17 )
{
unsigned long V_18 ;
struct V_5 * V_5 , * V_19 ;
int V_20 , V_11 ;
V_20 = F_9 ( V_4 ) == V_21 ;
V_18 = ( unsigned long ) V_15 ;
if ( F_10 ( V_2 , V_18 , V_16 ) && ! V_14 )
V_5 = F_11 ( V_2 , NULL , V_18 , V_16 , V_20 , V_17 ) ;
else
V_5 = F_12 ( V_2 , V_14 , V_18 , V_16 , V_20 , V_17 ) ;
if ( F_13 ( V_5 ) )
return F_14 ( V_5 ) ;
if ( V_14 && V_14 -> V_22 )
V_5 -> V_23 |= ( 1 << V_24 ) ;
V_19 = V_5 ;
F_15 ( V_2 , & V_5 ) ;
F_16 ( V_5 ) ;
V_11 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( ! V_11 )
return V_5 -> V_10 ;
F_17 ( V_5 , 0 ) ;
F_4 ( V_19 ) ;
F_18 ( V_5 ) ;
return V_11 ;
}
int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_13 * V_14 , void T_1 * V_15 ,
unsigned long V_16 , T_2 V_17 )
{
unsigned long V_25 = 0 ;
struct V_5 * V_5 = NULL ;
int V_11 ;
if ( V_16 > ( F_20 ( V_2 ) << 9 ) )
return - V_6 ;
if ( ! V_16 )
return - V_6 ;
if ( ! V_15 && ( ! V_14 || ! V_14 -> V_22 ) )
return - V_6 ;
while ( V_25 != V_16 ) {
unsigned long V_26 , V_27 , V_28 ;
V_26 = F_21 (unsigned long, len - bytes_read, BIO_MAX_SIZE) ;
V_27 = ( ( unsigned long ) V_15 + V_26 + V_29 - 1 )
>> V_30 ;
V_28 = ( unsigned long ) V_15 >> V_30 ;
if ( V_27 - V_28 > V_31 )
V_26 -= V_29 ;
V_11 = F_8 ( V_2 , V_4 , V_14 , V_15 , V_26 ,
V_17 ) ;
if ( V_11 < 0 )
goto V_32;
if ( ! V_5 )
V_5 = V_4 -> V_5 ;
V_25 += V_11 ;
V_15 += V_11 ;
if ( V_14 )
V_14 -> V_33 += V_11 ;
}
if ( ! F_5 ( V_5 , V_12 ) )
V_4 -> V_34 |= V_35 ;
V_4 -> V_36 = NULL ;
return 0 ;
V_32:
F_22 ( V_5 ) ;
V_4 -> V_5 = NULL ;
return V_11 ;
}
int F_23 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_13 * V_14 , struct V_37 * V_38 ,
int V_39 , unsigned int V_16 , T_2 V_17 )
{
struct V_5 * V_5 ;
int V_40 , V_41 = F_9 ( V_4 ) == V_21 ;
int V_42 = 0 ;
if ( ! V_38 || V_39 <= 0 )
return - V_6 ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
unsigned long V_18 = ( unsigned long ) V_38 [ V_40 ] . V_43 ;
if ( ! V_38 [ V_40 ] . V_44 )
return - V_6 ;
if ( V_18 & F_24 ( V_2 ) )
V_42 = 1 ;
}
if ( V_42 || ( V_2 -> V_45 & V_16 ) || V_14 )
V_5 = F_25 ( V_2 , V_14 , V_38 , V_39 , V_41 ,
V_17 ) ;
else
V_5 = F_26 ( V_2 , NULL , V_38 , V_39 , V_41 , V_17 ) ;
if ( F_13 ( V_5 ) )
return F_14 ( V_5 ) ;
if ( V_5 -> V_10 != V_16 ) {
F_16 ( V_5 ) ;
F_17 ( V_5 , 0 ) ;
F_4 ( V_5 ) ;
return - V_6 ;
}
if ( ! F_5 ( V_5 , V_12 ) )
V_4 -> V_34 |= V_35 ;
F_15 ( V_2 , & V_5 ) ;
F_16 ( V_5 ) ;
F_2 ( V_2 , V_4 , V_5 ) ;
V_4 -> V_36 = NULL ;
return 0 ;
}
int F_22 ( struct V_5 * V_5 )
{
struct V_5 * V_46 ;
int V_11 = 0 , V_47 ;
while ( V_5 ) {
V_46 = V_5 ;
if ( F_27 ( F_5 ( V_5 , V_48 ) ) )
V_46 = V_5 -> V_49 ;
V_47 = F_4 ( V_46 ) ;
if ( V_47 && ! V_11 )
V_11 = V_47 ;
V_46 = V_5 ;
V_5 = V_5 -> V_8 ;
F_18 ( V_46 ) ;
}
return V_11 ;
}
int F_28 ( struct V_1 * V_2 , struct V_3 * V_4 , void * V_50 ,
unsigned int V_16 , T_2 V_17 )
{
int V_20 = F_9 ( V_4 ) == V_21 ;
unsigned long V_51 = ( unsigned long ) V_50 ;
int V_52 = 0 ;
struct V_5 * V_5 ;
int V_11 ;
if ( V_16 > ( F_20 ( V_2 ) << 9 ) )
return - V_6 ;
if ( ! V_16 || ! V_50 )
return - V_6 ;
V_52 = ! F_10 ( V_2 , V_51 , V_16 ) || F_29 ( V_50 ) ;
if ( V_52 )
V_5 = F_30 ( V_2 , V_50 , V_16 , V_17 , V_20 ) ;
else
V_5 = F_31 ( V_2 , V_50 , V_16 , V_17 ) ;
if ( F_13 ( V_5 ) )
return F_14 ( V_5 ) ;
if ( ! V_20 )
V_5 -> V_53 |= V_54 ;
if ( V_52 )
V_4 -> V_34 |= V_35 ;
V_11 = F_1 ( V_2 , V_4 , V_5 ) ;
if ( F_27 ( V_11 ) ) {
F_18 ( V_5 ) ;
return V_11 ;
}
F_15 ( V_2 , & V_4 -> V_5 ) ;
V_4 -> V_36 = NULL ;
return 0 ;
}
