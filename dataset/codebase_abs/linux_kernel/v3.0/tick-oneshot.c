static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 >= V_4 )
return - V_5 ;
if ( V_2 -> V_3 < 5000 )
V_2 -> V_3 = 5000 ;
else
V_2 -> V_3 += V_2 -> V_3 >> 1 ;
if ( V_2 -> V_3 > V_4 )
V_2 -> V_3 = V_4 ;
F_2 ( V_6 L_1 ,
V_2 -> V_7 ? V_2 -> V_7 : L_2 ,
( unsigned long long ) V_2 -> V_3 ) ;
return 0 ;
}
int F_3 ( struct V_1 * V_2 , T_1 V_8 ,
int V_9 )
{
T_1 V_10 = F_4 () ;
int V_11 ;
for ( V_11 = 0 ; ; ) {
int V_12 = F_5 ( V_2 , V_8 , V_10 ) ;
if ( ! V_12 || ! V_9 )
return V_12 ;
V_2 -> V_13 ++ ;
if ( ++ V_11 > 2 ) {
if ( F_1 ( V_2 ) ) {
F_2 ( V_6
L_3 ) ;
V_2 -> V_14 . V_15 = V_16 ;
return - V_5 ;
}
V_11 = 0 ;
}
V_10 = F_4 () ;
V_8 = F_6 ( V_10 , V_2 -> V_3 ) ;
}
}
int F_7 ( T_1 V_8 , int V_9 )
{
struct V_1 * V_2 = F_8 ( V_17 . V_18 ) ;
return F_3 ( V_2 , V_8 , V_9 ) ;
}
void F_9 ( void )
{
struct V_19 * V_20 = & F_10 ( V_17 ) ;
struct V_1 * V_2 = V_20 -> V_18 ;
F_11 ( V_2 , V_21 ) ;
F_7 ( F_4 () , 1 ) ;
}
void F_12 ( struct V_1 * V_22 ,
void (* F_13)( struct V_1 * ) ,
T_1 V_14 )
{
V_22 -> V_23 = F_13 ;
F_11 ( V_22 , V_21 ) ;
F_3 ( V_22 , V_14 , 1 ) ;
}
int F_14 ( void (* F_13)( struct V_1 * ) )
{
struct V_19 * V_20 = & F_10 ( V_17 ) ;
struct V_1 * V_2 = V_20 -> V_18 ;
if ( ! V_2 || ! ( V_2 -> V_24 & V_25 ) ||
! F_15 ( V_2 ) ) {
F_2 ( V_26 L_4
L_5 ) ;
if ( ! V_2 ) {
F_2 ( L_6 ) ;
} else {
if ( ! F_15 ( V_2 ) )
F_2 ( L_7 , V_2 -> V_7 ) ;
else
F_2 ( L_8 ,
V_2 -> V_7 ) ;
}
return - V_27 ;
}
V_20 -> V_28 = V_29 ;
V_2 -> V_23 = F_13 ;
F_11 ( V_2 , V_21 ) ;
F_16 () ;
return 0 ;
}
int F_17 ( void )
{
unsigned long V_30 ;
int V_12 ;
F_18 ( V_30 ) ;
V_12 = F_8 ( V_17 . V_28 ) == V_29 ;
F_19 ( V_30 ) ;
return V_12 ;
}
int F_20 ( void )
{
return F_14 ( V_31 ) ;
}
