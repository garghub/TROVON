static int F_1 ( T_1 * V_1 , T_2 V_2 , unsigned long V_3 ,
void * V_4 )
{
struct V_5 * V_6 = V_4 ;
T_1 V_7 = * V_1 ;
V_7 = F_2 ( V_7 , V_6 -> V_8 ) ;
V_7 = F_3 ( V_7 , V_6 -> V_9 ) ;
F_4 ( V_1 , V_7 ) ;
return 0 ;
}
static int F_5 ( unsigned long V_10 , unsigned long V_11 ,
T_3 V_9 , T_3 V_8 )
{
struct V_5 V_4 ;
int V_12 ;
V_4 . V_9 = V_9 ;
V_4 . V_8 = V_8 ;
V_12 = F_6 ( & V_13 , V_10 , V_11 , F_1 ,
& V_4 ) ;
F_7 ( V_10 , V_10 + V_11 ) ;
return V_12 ;
}
static int F_8 ( unsigned long V_3 , int V_14 ,
T_3 V_9 , T_3 V_8 )
{
unsigned long V_10 = V_3 ;
unsigned long V_11 = V_15 * V_14 ;
unsigned long V_16 = V_10 + V_11 ;
struct V_17 * V_18 ;
if ( ! F_9 ( V_3 ) ) {
V_10 &= V_19 ;
V_16 = V_10 + V_11 ;
F_10 ( 1 ) ;
}
V_18 = F_11 ( ( void * ) V_3 ) ;
if ( ! V_18 ||
V_16 > ( unsigned long ) V_18 -> V_3 + V_18 -> V_11 ||
! ( V_18 -> V_20 & V_21 ) )
return - V_22 ;
if ( ! V_14 )
return 0 ;
return F_5 ( V_10 , V_11 , V_9 , V_8 ) ;
}
int F_12 ( unsigned long V_3 , int V_14 )
{
return F_8 ( V_3 , V_14 ,
F_13 ( V_23 ) ,
F_13 ( V_24 ) ) ;
}
int F_14 ( unsigned long V_3 , int V_14 )
{
return F_8 ( V_3 , V_14 ,
F_13 ( V_24 ) ,
F_13 ( V_23 ) ) ;
}
int F_15 ( unsigned long V_3 , int V_14 )
{
return F_8 ( V_3 , V_14 ,
F_13 ( V_25 ) ,
F_13 ( 0 ) ) ;
}
int F_16 ( unsigned long V_3 , int V_14 )
{
return F_8 ( V_3 , V_14 ,
F_13 ( 0 ) ,
F_13 ( V_25 ) ) ;
}
int F_17 ( unsigned long V_3 , int V_14 , int V_26 )
{
if ( V_26 )
return F_5 ( V_3 , V_15 * V_14 ,
F_13 ( V_27 ) ,
F_13 ( 0 ) ) ;
else
return F_5 ( V_3 , V_15 * V_14 ,
F_13 ( 0 ) ,
F_13 ( V_27 ) ) ;
}
void F_18 ( struct V_28 * V_28 , int V_14 , int V_26 )
{
F_17 ( ( unsigned long ) F_19 ( V_28 ) , V_14 , V_26 ) ;
}
bool F_20 ( struct V_28 * V_28 )
{
T_4 * V_29 ;
T_5 * V_30 ;
T_6 * V_31 ;
T_1 * V_7 ;
unsigned long V_3 = ( unsigned long ) F_19 ( V_28 ) ;
V_29 = F_21 ( V_3 ) ;
if ( F_22 ( * V_29 ) )
return false ;
V_30 = F_23 ( V_29 , V_3 ) ;
if ( F_24 ( * V_30 ) )
return false ;
if ( F_25 ( * V_30 ) )
return true ;
V_31 = F_26 ( V_30 , V_3 ) ;
if ( F_27 ( * V_31 ) )
return false ;
if ( F_28 ( * V_31 ) )
return true ;
V_7 = F_29 ( V_31 , V_3 ) ;
return F_30 ( * V_7 ) ;
}
