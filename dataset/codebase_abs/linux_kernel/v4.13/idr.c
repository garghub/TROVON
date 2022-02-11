int F_1 ( struct V_1 * V_1 , void * V_2 , int V_3 , int V_4 , T_1 V_5 )
{
void T_2 * * V_6 ;
struct V_7 V_8 ;
if ( F_2 ( V_3 < 0 ) )
return - V_9 ;
if ( F_2 ( F_3 ( V_2 ) ) )
return - V_9 ;
F_4 ( & V_8 , V_3 ) ;
V_6 = F_5 ( & V_1 -> V_10 , & V_8 , V_5 , V_4 ) ;
if ( F_6 ( V_6 ) )
return F_7 ( V_6 ) ;
F_8 ( & V_1 -> V_10 , & V_8 , V_6 , V_2 ) ;
F_9 ( & V_1 -> V_10 , & V_8 , V_11 ) ;
return V_8 . V_12 ;
}
int F_10 ( struct V_1 * V_1 , void * V_2 , int V_3 , int V_4 , T_1 V_5 )
{
int V_13 , V_14 = V_1 -> V_15 ;
if ( V_14 < V_3 )
V_14 = V_3 ;
V_13 = F_1 ( V_1 , V_2 , V_14 , V_4 , V_5 ) ;
if ( ( V_13 == - V_16 ) && ( V_14 > V_3 ) )
V_13 = F_1 ( V_1 , V_2 , V_3 , V_14 , V_5 ) ;
if ( V_13 >= 0 )
V_1 -> V_15 = V_13 + 1U ;
return V_13 ;
}
int F_11 ( const struct V_1 * V_1 ,
int (* F_12)( int V_13 , void * V_17 , void * V_18 ) , void * V_18 )
{
struct V_7 V_8 ;
void T_2 * * V_6 ;
F_13 (slot, &idr->idr_rt, &iter, 0 ) {
int V_19 = F_12 ( V_8 . V_12 , F_14 ( * V_6 ) , V_18 ) ;
if ( V_19 )
return V_19 ;
}
return 0 ;
}
void * F_15 ( struct V_1 * V_1 , int * V_20 )
{
struct V_7 V_8 ;
void T_2 * * V_6 ;
V_6 = F_16 ( & V_1 -> V_10 , & V_8 , * V_20 ) ;
if ( ! V_6 )
return NULL ;
* V_20 = V_8 . V_12 ;
return F_14 ( * V_6 ) ;
}
void * F_17 ( struct V_1 * V_1 , void * V_2 , int V_13 )
{
struct V_21 * V_22 ;
void T_2 * * V_6 = NULL ;
void * V_23 ;
if ( F_2 ( V_13 < 0 ) )
return F_18 ( - V_9 ) ;
if ( F_2 ( F_3 ( V_2 ) ) )
return F_18 ( - V_9 ) ;
V_23 = F_19 ( & V_1 -> V_10 , V_13 , & V_22 , & V_6 ) ;
if ( ! V_6 || F_20 ( & V_1 -> V_10 , V_13 , V_11 ) )
return F_18 ( - V_24 ) ;
F_21 ( & V_1 -> V_10 , V_22 , V_6 , V_2 , NULL , NULL ) ;
return V_23 ;
}
int F_22 ( struct V_25 * V_25 , int V_3 , int * V_13 )
{
struct V_26 * V_27 = & V_25 -> V_28 ;
void T_2 * * V_6 ;
struct V_7 V_8 ;
struct V_29 * V_30 ;
unsigned long V_12 ;
unsigned V_31 , V_32 ;
int V_33 ;
V_12 = V_3 / V_34 ;
V_31 = V_3 % V_34 ;
V_32 = V_31 + V_35 ;
V_6 = F_4 ( & V_8 , V_12 ) ;
for (; ; ) {
if ( V_6 )
V_6 = F_23 ( V_6 , & V_8 ,
V_36 ) ;
if ( ! V_6 ) {
V_6 = F_5 ( V_27 , & V_8 , V_37 , V_38 ) ;
if ( F_6 ( V_6 ) ) {
if ( V_6 == F_18 ( - V_39 ) )
return - V_40 ;
return F_7 ( V_6 ) ;
}
}
if ( V_8 . V_12 > V_12 ) {
V_31 = 0 ;
V_32 = V_35 ;
}
V_33 = V_8 . V_12 * V_34 ;
V_30 = F_14 ( * V_6 ) ;
if ( F_24 ( V_30 ) ) {
unsigned long V_41 = ( unsigned long ) V_30 ;
V_32 = F_25 ( & V_41 , V_42 , V_32 ) ;
if ( V_32 < V_42 ) {
V_41 |= 1UL << V_32 ;
F_26 ( * V_6 , ( void * ) V_41 ) ;
* V_13 = V_33 + V_32 - V_35 ;
return 0 ;
}
V_30 = F_27 ( V_29 , NULL ) ;
if ( ! V_30 )
return - V_40 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
V_30 -> V_30 [ 0 ] = V_41 >> V_35 ;
F_26 ( * V_6 , V_30 ) ;
}
if ( V_30 ) {
V_31 = F_25 ( V_30 -> V_30 ,
V_34 , V_31 ) ;
V_33 += V_31 ;
if ( V_33 < 0 )
return - V_16 ;
if ( V_31 == V_34 )
continue;
F_28 ( V_31 , V_30 -> V_30 ) ;
if ( F_29 ( V_30 -> V_30 , V_34 ) )
F_9 ( V_27 , & V_8 ,
V_11 ) ;
} else {
V_33 += V_31 ;
if ( V_33 < 0 )
return - V_16 ;
if ( V_32 < V_42 ) {
V_30 = ( void * ) ( ( 1UL << V_32 ) |
V_43 ) ;
F_8 ( V_27 , & V_8 , V_6 ,
V_30 ) ;
* V_13 = V_33 ;
return 0 ;
}
V_30 = F_27 ( V_29 , NULL ) ;
if ( ! V_30 )
return - V_40 ;
memset ( V_30 , 0 , sizeof( * V_30 ) ) ;
F_28 ( V_31 , V_30 -> V_30 ) ;
F_8 ( V_27 , & V_8 , V_6 , V_30 ) ;
}
* V_13 = V_33 ;
return 0 ;
}
}
void F_30 ( struct V_25 * V_25 , int V_13 )
{
unsigned long V_12 = V_13 / V_34 ;
unsigned V_44 = V_13 % V_34 ;
struct V_29 * V_30 ;
unsigned long * V_45 ;
struct V_7 V_8 ;
void T_2 * * V_6 ;
V_6 = F_31 ( & V_25 -> V_28 , & V_8 , V_12 ) ;
if ( ! V_6 )
goto V_46;
V_30 = F_14 ( * V_6 ) ;
if ( F_24 ( V_30 ) ) {
V_45 = ( unsigned long * ) V_6 ;
V_44 += V_35 ;
if ( V_44 >= V_42 )
goto V_46;
} else {
V_45 = V_30 -> V_30 ;
}
if ( ! F_32 ( V_44 , V_45 ) )
goto V_46;
F_33 ( V_44 , V_45 ) ;
F_34 ( & V_25 -> V_28 , & V_8 , V_11 ) ;
if ( F_24 ( V_30 ) ) {
if ( F_14 ( * V_6 ) ==
( void * ) V_43 )
F_35 ( & V_25 -> V_28 , & V_8 , V_6 ) ;
} else if ( F_36 ( V_45 , V_34 ) ) {
F_37 ( V_30 ) ;
F_35 ( & V_25 -> V_28 , & V_8 , V_6 ) ;
}
return;
V_46:
F_38 ( 1 , L_1 , V_13 ) ;
}
void F_39 ( struct V_25 * V_25 )
{
struct V_7 V_8 ;
void T_2 * * V_6 ;
F_13 (slot, &ida->ida_rt, &iter, 0 ) {
struct V_29 * V_30 = F_14 ( * V_6 ) ;
if ( ! F_24 ( V_30 ) )
F_37 ( V_30 ) ;
F_35 ( & V_25 -> V_28 , & V_8 , V_6 ) ;
}
}
int F_40 ( struct V_25 * V_25 , unsigned int V_3 , unsigned int V_4 ,
T_1 V_47 )
{
int V_19 , V_13 ;
unsigned int V_48 ;
unsigned long V_49 ;
F_41 ( ( int ) V_3 < 0 ) ;
F_41 ( ( int ) V_4 < 0 ) ;
if ( V_4 == 0 )
V_48 = 0x80000000 ;
else {
F_41 ( V_4 < V_3 ) ;
V_48 = V_4 - 1 ;
}
V_50:
if ( ! F_42 ( V_25 , V_47 ) )
return - V_39 ;
F_43 ( & V_51 , V_49 ) ;
V_19 = F_22 ( V_25 , V_3 , & V_13 ) ;
if ( ! V_19 ) {
if ( V_13 > V_48 ) {
F_30 ( V_25 , V_13 ) ;
V_19 = - V_16 ;
} else {
V_19 = V_13 ;
}
}
F_44 ( & V_51 , V_49 ) ;
if ( F_45 ( V_19 == - V_40 ) )
goto V_50;
return V_19 ;
}
void F_46 ( struct V_25 * V_25 , unsigned int V_13 )
{
unsigned long V_49 ;
F_41 ( ( int ) V_13 < 0 ) ;
F_43 ( & V_51 , V_49 ) ;
F_30 ( V_25 , V_13 ) ;
F_44 ( & V_51 , V_49 ) ;
}
