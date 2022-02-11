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
void F_9 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
T_1 V_26 , V_27 ;
V_26 = F_10 () ;
V_27 = F_2 ( V_2 ) -> V_15 -> V_28
+ F_11 ( V_29 ) ;
if ( F_12 ( V_27 , V_26 ) )
V_27 -= V_26 ;
else
V_27 = 0 ;
F_13 ( V_30 , V_25 , V_27 ) ;
}
static void F_14 ( struct V_31 * V_15 , int V_11 ,
void * V_32 , T_2 V_6 ,
void * V_33 )
{
struct V_34 * V_35 = V_33 ;
struct V_36 * V_37 = F_15 ( V_35 -> V_37 ) ;
if ( V_37 == NULL )
return;
if ( V_11 == V_18 )
F_16 ( V_37 , V_35 -> V_38 ) ;
else if ( ! F_5 ( V_11 ) )
V_35 -> V_39 = F_17 ( 0 , 0 ) ;
else
V_35 -> error = true ;
V_35 -> V_40 = true ;
if ( ! F_18 ( V_37 ) )
F_19 ( & V_35 -> V_41 ) ;
}
static void F_20 ( struct V_42 * V_41 )
{
struct V_34 * V_35 =
F_21 ( V_41 , struct V_34 , V_41 ) ;
struct V_36 * V_37 = F_15 ( V_35 -> V_37 ) ;
int V_10 ;
int type ;
if ( ! V_35 -> V_40 || V_35 -> error )
return;
if ( V_37 == NULL || F_18 ( V_37 ) )
return;
if ( F_22 ( V_35 -> V_39 , F_23 () ) ) {
F_19 ( & V_35 -> V_41 ) ;
return;
}
memset ( V_35 -> V_43 , 0 , V_35 -> V_44 ) ;
V_35 -> V_38 = V_35 -> V_45 ( V_37 , V_35 -> V_43 ) ;
if ( V_35 -> V_38 <= 0 ) {
if ( V_35 -> V_38 == 0 ) {
V_35 -> V_39 = F_17 ( 0 , 0 ) ;
F_19 ( & V_35 -> V_41 ) ;
} else {
V_35 -> error = true ;
}
return;
}
if ( V_35 -> V_44 == 4 )
type = V_46 ;
else
type = V_47 ;
V_35 -> V_39 = F_24 ( F_23 () ,
V_35 -> V_38 * 8 * V_48 / 31250 ) ;
V_35 -> V_40 = false ;
V_10 = V_35 -> V_49 -> V_10 ;
F_3 () ;
F_25 ( V_35 -> V_49 -> V_15 , & V_35 -> V_50 , type ,
V_35 -> V_49 -> V_16 , V_10 ,
V_35 -> V_49 -> V_17 , V_35 -> V_51 ,
V_35 -> V_43 , V_35 -> V_44 , F_14 ,
V_35 ) ;
}
int F_26 ( struct V_34 * V_35 ,
struct V_1 * V_2 , T_1 V_51 , unsigned int V_44 ,
T_3 V_45 )
{
V_35 -> V_44 = F_27 ( V_44 , 4 ) * 4 ;
V_35 -> V_43 = F_28 ( V_35 -> V_44 , V_52 ) ;
if ( V_35 -> V_43 == NULL )
return - V_53 ;
V_35 -> V_49 = F_2 ( V_2 ) ;
V_35 -> V_51 = V_51 ;
V_35 -> V_45 = V_45 ;
V_35 -> V_40 = true ;
V_35 -> V_39 = F_17 ( 0 , 0 ) ;
V_35 -> error = false ;
F_29 ( & V_35 -> V_41 , F_20 ) ;
return 0 ;
}
void F_30 ( struct V_34 * V_35 )
{
F_31 ( V_35 ) ;
F_32 ( & V_35 -> V_41 ) ;
F_33 ( V_35 -> V_43 ) ;
}
