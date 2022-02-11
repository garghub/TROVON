int F_1 ( struct V_1 * V_2 , int V_3 ,
T_1 V_4 , void * V_5 , T_2 V_6 ,
unsigned int V_7 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
int V_10 , V_11 , V_12 = 0 ;
V_10 = V_7 & V_13 ;
for (; ; ) {
if ( ! ( V_7 & V_14 ) ) {
V_10 = V_9 -> V_10 ;
F_3 () ;
}
V_11 = F_4 ( V_9 -> V_15 , V_3 ,
V_9 -> V_16 , V_10 ,
V_9 -> V_17 , V_4 ,
V_5 , V_6 ) ;
if ( V_11 == V_18 )
return 0 ;
if ( V_11 == V_19 && ( V_7 & V_14 ) )
return - V_20 ;
if ( F_5 ( V_11 ) || ++ V_12 >= 3 ) {
if ( ! ( V_7 & V_21 ) )
F_6 ( & V_2 -> V_9 ,
L_1 ,
F_7 ( V_11 ) ) ;
return - V_22 ;
}
F_8 ( V_23 ) ;
}
}
static void F_9 ( struct V_24 * V_15 , int V_11 ,
void * V_25 , T_2 V_6 ,
void * V_26 )
{
struct V_27 * V_28 = V_26 ;
struct V_29 * V_30 = F_10 ( V_28 -> V_30 ) ;
if ( V_30 == NULL )
return;
if ( V_11 == V_18 )
F_11 ( V_30 , V_28 -> V_31 ) ;
else if ( ! F_5 ( V_11 ) )
V_28 -> V_32 = F_12 ( 0 , 0 ) ;
else
V_28 -> error = true ;
V_28 -> V_33 = true ;
if ( ! F_13 ( V_30 ) )
F_14 ( & V_28 -> V_34 ) ;
}
static void F_15 ( struct V_35 * V_34 )
{
struct V_27 * V_28 =
F_16 ( V_34 , struct V_27 , V_34 ) ;
struct V_29 * V_30 = F_10 ( V_28 -> V_30 ) ;
int V_10 ;
int type ;
if ( ! V_28 -> V_33 || V_28 -> error )
return;
if ( V_30 == NULL || F_13 ( V_30 ) )
return;
if ( F_17 ( V_28 -> V_32 , F_18 () ) ) {
F_14 ( & V_28 -> V_34 ) ;
return;
}
memset ( V_28 -> V_36 , 0 , V_28 -> V_37 ) ;
V_28 -> V_31 = V_28 -> V_38 ( V_30 , V_28 -> V_36 ) ;
if ( V_28 -> V_31 <= 0 ) {
if ( V_28 -> V_31 == 0 ) {
V_28 -> V_32 = F_12 ( 0 , 0 ) ;
F_14 ( & V_28 -> V_34 ) ;
} else {
V_28 -> error = true ;
}
return;
}
if ( V_28 -> V_37 == 4 )
type = V_39 ;
else
type = V_40 ;
V_28 -> V_32 = F_19 ( F_18 () ,
V_28 -> V_31 * 8 * V_41 / 31250 ) ;
V_28 -> V_33 = false ;
V_10 = V_28 -> V_42 -> V_10 ;
F_3 () ;
F_20 ( V_28 -> V_42 -> V_15 , & V_28 -> V_43 , type ,
V_28 -> V_42 -> V_16 , V_10 ,
V_28 -> V_42 -> V_17 , V_28 -> V_44 ,
V_28 -> V_36 , V_28 -> V_37 , F_9 ,
V_28 ) ;
}
int F_21 ( struct V_27 * V_28 ,
struct V_1 * V_2 , T_1 V_44 , unsigned int V_37 ,
T_3 V_38 )
{
V_28 -> V_37 = F_22 ( V_37 , 4 ) * 4 ;
V_28 -> V_36 = F_23 ( V_28 -> V_37 , V_45 ) ;
if ( V_28 -> V_36 == NULL )
return - V_46 ;
V_28 -> V_42 = F_2 ( V_2 ) ;
V_28 -> V_44 = V_44 ;
V_28 -> V_38 = V_38 ;
V_28 -> V_33 = true ;
V_28 -> V_32 = F_12 ( 0 , 0 ) ;
V_28 -> error = false ;
F_24 ( & V_28 -> V_34 , F_15 ) ;
return 0 ;
}
void F_25 ( struct V_27 * V_28 )
{
F_26 ( V_28 ) ;
F_27 ( & V_28 -> V_34 ) ;
F_28 ( V_28 -> V_36 ) ;
}
