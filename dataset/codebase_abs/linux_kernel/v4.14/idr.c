int F_1 ( struct V_1 * V_1 , void * V_2 , unsigned long * V_3 ,
unsigned long V_4 , unsigned long V_5 , T_1 V_6 ,
bool V_7 )
{
struct V_8 V_9 ;
void T_2 * * V_10 ;
if ( F_2 ( F_3 ( V_2 ) ) )
return - V_11 ;
F_4 ( & V_9 , V_4 ) ;
if ( V_7 )
V_10 = F_5 ( & V_1 -> V_12 , & V_9 , V_6 , V_5 ) ;
else
V_10 = F_6 ( & V_1 -> V_12 , & V_9 , V_6 , V_5 ) ;
if ( F_7 ( V_10 ) )
return F_8 ( V_10 ) ;
F_9 ( & V_1 -> V_12 , & V_9 , V_10 , V_2 ) ;
F_10 ( & V_1 -> V_12 , & V_9 , V_13 ) ;
if ( V_3 )
* V_3 = V_9 . V_3 ;
return 0 ;
}
int F_11 ( struct V_1 * V_1 , void * V_2 , int V_4 , int V_5 , T_1 V_6 )
{
int V_14 , V_15 = V_1 -> V_16 ;
if ( V_15 < V_4 )
V_15 = V_4 ;
V_14 = F_12 ( V_1 , V_2 , V_15 , V_5 , V_6 ) ;
if ( ( V_14 == - V_17 ) && ( V_15 > V_4 ) )
V_14 = F_12 ( V_1 , V_2 , V_4 , V_15 , V_6 ) ;
if ( V_14 >= 0 )
V_1 -> V_16 = V_14 + 1U ;
return V_14 ;
}
int F_13 ( const struct V_1 * V_1 ,
int (* F_14)( int V_14 , void * V_18 , void * V_19 ) , void * V_19 )
{
struct V_8 V_9 ;
void T_2 * * V_10 ;
F_15 (slot, &idr->idr_rt, &iter, 0 ) {
int V_20 = F_14 ( V_9 . V_3 , F_16 ( * V_10 ) , V_19 ) ;
if ( V_20 )
return V_20 ;
}
return 0 ;
}
void * F_17 ( struct V_1 * V_1 , int * V_21 )
{
struct V_8 V_9 ;
void T_2 * * V_10 ;
V_10 = F_18 ( & V_1 -> V_12 , & V_9 , * V_21 ) ;
if ( ! V_10 )
return NULL ;
* V_21 = V_9 . V_3 ;
return F_16 ( * V_10 ) ;
}
void * F_19 ( struct V_1 * V_1 , unsigned long * V_21 )
{
struct V_8 V_9 ;
void T_2 * * V_10 ;
V_10 = F_18 ( & V_1 -> V_12 , & V_9 , * V_21 ) ;
if ( ! V_10 )
return NULL ;
* V_21 = V_9 . V_3 ;
return F_16 ( * V_10 ) ;
}
void * F_20 ( struct V_1 * V_1 , void * V_2 , int V_14 )
{
if ( V_14 < 0 )
return F_21 ( - V_11 ) ;
return F_22 ( V_1 , V_2 , V_14 ) ;
}
void * F_22 ( struct V_1 * V_1 , void * V_2 , unsigned long V_14 )
{
struct V_22 * V_23 ;
void T_2 * * V_10 = NULL ;
void * V_24 ;
if ( F_2 ( F_3 ( V_2 ) ) )
return F_21 ( - V_11 ) ;
V_24 = F_23 ( & V_1 -> V_12 , V_14 , & V_23 , & V_10 ) ;
if ( ! V_10 || F_24 ( & V_1 -> V_12 , V_14 , V_13 ) )
return F_21 ( - V_25 ) ;
F_25 ( & V_1 -> V_12 , V_23 , V_10 , V_2 , NULL , NULL ) ;
return V_24 ;
}
int F_26 ( struct V_26 * V_26 , int V_4 , int * V_14 )
{
struct V_27 * V_28 = & V_26 -> V_29 ;
void T_2 * * V_10 ;
struct V_8 V_9 ;
struct V_30 * V_31 ;
unsigned long V_3 ;
unsigned V_32 , V_33 ;
int V_34 ;
V_3 = V_4 / V_35 ;
V_32 = V_4 % V_35 ;
V_33 = V_32 + V_36 ;
V_10 = F_4 ( & V_9 , V_3 ) ;
for (; ; ) {
if ( V_10 )
V_10 = F_27 ( V_10 , & V_9 ,
V_37 ) ;
if ( ! V_10 ) {
V_10 = F_6 ( V_28 , & V_9 , V_38 , V_39 ) ;
if ( F_7 ( V_10 ) ) {
if ( V_10 == F_21 ( - V_40 ) )
return - V_41 ;
return F_8 ( V_10 ) ;
}
}
if ( V_9 . V_3 > V_3 ) {
V_32 = 0 ;
V_33 = V_36 ;
}
V_34 = V_9 . V_3 * V_35 ;
V_31 = F_16 ( * V_10 ) ;
if ( F_28 ( V_31 ) ) {
unsigned long V_42 = ( unsigned long ) V_31 ;
V_33 = F_29 ( & V_42 , V_43 , V_33 ) ;
if ( V_33 < V_43 ) {
V_42 |= 1UL << V_33 ;
F_30 ( * V_10 , ( void * ) V_42 ) ;
* V_14 = V_34 + V_33 - V_36 ;
return 0 ;
}
V_31 = F_31 ( V_30 , NULL ) ;
if ( ! V_31 )
return - V_41 ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
V_31 -> V_31 [ 0 ] = V_42 >> V_36 ;
F_30 ( * V_10 , V_31 ) ;
}
if ( V_31 ) {
V_32 = F_29 ( V_31 -> V_31 ,
V_35 , V_32 ) ;
V_34 += V_32 ;
if ( V_34 < 0 )
return - V_17 ;
if ( V_32 == V_35 )
continue;
F_32 ( V_32 , V_31 -> V_31 ) ;
if ( F_33 ( V_31 -> V_31 , V_35 ) )
F_10 ( V_28 , & V_9 ,
V_13 ) ;
} else {
V_34 += V_32 ;
if ( V_34 < 0 )
return - V_17 ;
if ( V_33 < V_43 ) {
V_31 = ( void * ) ( ( 1UL << V_33 ) |
V_44 ) ;
F_9 ( V_28 , & V_9 , V_10 ,
V_31 ) ;
* V_14 = V_34 ;
return 0 ;
}
V_31 = F_31 ( V_30 , NULL ) ;
if ( ! V_31 )
return - V_41 ;
memset ( V_31 , 0 , sizeof( * V_31 ) ) ;
F_32 ( V_32 , V_31 -> V_31 ) ;
F_9 ( V_28 , & V_9 , V_10 , V_31 ) ;
}
* V_14 = V_34 ;
return 0 ;
}
}
void F_34 ( struct V_26 * V_26 , int V_14 )
{
unsigned long V_3 = V_14 / V_35 ;
unsigned V_45 = V_14 % V_35 ;
struct V_30 * V_31 ;
unsigned long * V_46 ;
struct V_8 V_9 ;
void T_2 * * V_10 ;
V_10 = F_35 ( & V_26 -> V_29 , & V_9 , V_3 ) ;
if ( ! V_10 )
goto V_47;
V_31 = F_16 ( * V_10 ) ;
if ( F_28 ( V_31 ) ) {
V_46 = ( unsigned long * ) V_10 ;
V_45 += V_36 ;
if ( V_45 >= V_43 )
goto V_47;
} else {
V_46 = V_31 -> V_31 ;
}
if ( ! F_36 ( V_45 , V_46 ) )
goto V_47;
F_37 ( V_45 , V_46 ) ;
F_38 ( & V_26 -> V_29 , & V_9 , V_13 ) ;
if ( F_28 ( V_31 ) ) {
if ( F_16 ( * V_10 ) ==
( void * ) V_44 )
F_39 ( & V_26 -> V_29 , & V_9 , V_10 ) ;
} else if ( F_40 ( V_46 , V_35 ) ) {
F_41 ( V_31 ) ;
F_39 ( & V_26 -> V_29 , & V_9 , V_10 ) ;
}
return;
V_47:
F_42 ( 1 , L_1 , V_14 ) ;
}
void F_43 ( struct V_26 * V_26 )
{
struct V_8 V_9 ;
void T_2 * * V_10 ;
F_15 (slot, &ida->ida_rt, &iter, 0 ) {
struct V_30 * V_31 = F_16 ( * V_10 ) ;
if ( ! F_28 ( V_31 ) )
F_41 ( V_31 ) ;
F_39 ( & V_26 -> V_29 , & V_9 , V_10 ) ;
}
}
int F_44 ( struct V_26 * V_26 , unsigned int V_4 , unsigned int V_5 ,
T_1 V_48 )
{
int V_20 , V_14 ;
unsigned int V_49 ;
unsigned long V_50 ;
F_45 ( ( int ) V_4 < 0 ) ;
F_45 ( ( int ) V_5 < 0 ) ;
if ( V_5 == 0 )
V_49 = 0x80000000 ;
else {
F_45 ( V_5 < V_4 ) ;
V_49 = V_5 - 1 ;
}
V_51:
if ( ! F_46 ( V_26 , V_48 ) )
return - V_40 ;
F_47 ( & V_52 , V_50 ) ;
V_20 = F_26 ( V_26 , V_4 , & V_14 ) ;
if ( ! V_20 ) {
if ( V_14 > V_49 ) {
F_34 ( V_26 , V_14 ) ;
V_20 = - V_17 ;
} else {
V_20 = V_14 ;
}
}
F_48 ( & V_52 , V_50 ) ;
if ( F_49 ( V_20 == - V_41 ) )
goto V_51;
return V_20 ;
}
void F_50 ( struct V_26 * V_26 , unsigned int V_14 )
{
unsigned long V_50 ;
F_45 ( ( int ) V_14 < 0 ) ;
F_47 ( & V_52 , V_50 ) ;
F_34 ( V_26 , V_14 ) ;
F_48 ( & V_52 , V_50 ) ;
}
