static inline int
F_1 ( T_1 * V_1 , struct V_2 T_2 * * V_3 ,
T_1 T_2 * V_4 , unsigned int * V_5 )
{
if ( F_2 ( * V_1 , V_4 ) )
return - V_6 ;
* V_3 = F_3 ( ( * V_1 ) & ~ 1 ) ;
* V_5 = ( unsigned int ) ( * V_1 ) & 1 ;
return 0 ;
}
static void T_2 * F_4 ( struct V_2 T_2 * V_3 ,
T_3 V_7 )
{
T_1 V_8 = F_5 ( V_3 ) ;
void T_2 * V_9 = F_3 ( V_8 + V_7 ) ;
return V_9 ;
}
void F_6 ( struct V_10 * V_11 )
{
struct V_12 T_2 * V_4 = V_11 -> V_13 ;
struct V_2 T_2 * V_3 , * V_14 , * V_15 ;
unsigned int V_16 = V_17 , V_5 , V_18 ;
unsigned int V_19 ( V_20 ) ;
T_1 V_1 , V_21 , V_22 ;
T_3 V_7 ;
int V_23 ;
if ( ! V_24 )
return;
if ( F_1 ( & V_1 , & V_3 , & V_4 -> V_25 . V_26 , & V_5 ) )
return;
if ( F_2 ( V_7 , & V_4 -> V_7 ) )
return;
if ( F_1 ( & V_22 , & V_15 ,
& V_4 -> V_27 , & V_18 ) )
return;
V_14 = NULL ;
while ( V_3 != (struct V_2 T_2 * ) & V_4 -> V_25 ) {
V_23 = F_1 ( & V_21 , & V_14 ,
( T_1 T_2 * ) & V_3 -> V_26 , & V_20 ) ;
if ( V_3 != V_15 ) {
void T_2 * V_9 = F_4 ( V_3 , V_7 ) ;
if ( F_7 ( V_9 , V_11 , V_5 ) )
return;
}
if ( V_23 )
return;
V_1 = V_21 ;
V_3 = V_14 ;
V_5 = V_20 ;
if ( ! -- V_16 )
break;
F_8 () ;
}
if ( V_15 ) {
void T_2 * V_9 = F_4 ( V_15 , V_7 ) ;
F_7 ( V_9 , V_11 , V_18 ) ;
}
}
T_4 long
F_9 ( struct V_12 T_2 * V_4 ,
T_5 V_28 )
{
if ( ! V_24 )
return - V_29 ;
if ( F_10 ( V_28 != sizeof( * V_4 ) ) )
return - V_30 ;
V_31 -> V_13 = V_4 ;
return 0 ;
}
T_4 long
F_11 ( int V_32 , T_1 T_2 * V_33 ,
T_5 T_2 * V_34 )
{
struct V_12 T_2 * V_4 ;
unsigned long V_35 ;
struct V_10 * V_36 ;
if ( ! V_24 )
return - V_29 ;
F_12 ( 1 , L_1 ) ;
F_13 () ;
V_35 = - V_37 ;
if ( ! V_32 )
V_36 = V_31 ;
else {
V_36 = F_14 ( V_32 ) ;
if ( ! V_36 )
goto V_38;
}
V_35 = - V_39 ;
if ( ! F_15 ( V_36 , V_40 ) )
goto V_38;
V_4 = V_36 -> V_13 ;
F_16 () ;
if ( F_17 ( sizeof( * V_4 ) , V_34 ) )
return - V_6 ;
return F_17 ( F_5 ( V_4 ) , V_33 ) ;
V_38:
F_16 () ;
return V_35 ;
}
T_4 long F_18 ( T_6 T_2 * V_9 , int V_41 , T_6 V_42 ,
struct V_43 T_2 * V_44 , T_6 T_2 * V_45 ,
T_6 V_46 )
{
struct V_47 V_48 ;
T_7 V_49 , * V_50 = NULL ;
int V_51 = 0 ;
int V_52 = V_41 & V_53 ;
if ( V_44 && ( V_52 == V_54 || V_52 == V_55 ||
V_52 == V_56 ||
V_52 == V_57 ) ) {
if ( F_19 ( & V_48 , V_44 ) )
return - V_6 ;
if ( ! F_20 ( & V_48 ) )
return - V_30 ;
V_49 = F_21 ( V_48 ) ;
if ( V_52 == V_54 )
V_49 = F_22 ( F_23 () , V_49 ) ;
V_50 = & V_49 ;
}
if ( V_52 == V_58 || V_52 == V_59 ||
V_52 == V_60 || V_52 == V_61 )
V_51 = ( int ) ( unsigned long ) V_44 ;
return F_24 ( V_9 , V_41 , V_42 , V_50 , V_45 , V_51 , V_46 ) ;
}
