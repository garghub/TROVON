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
const struct V_36 * V_36 = F_12 () , * V_37 ;
if ( ! V_24 )
return - V_29 ;
if ( ! V_32 )
V_4 = V_31 -> V_13 ;
else {
struct V_10 * V_38 ;
V_35 = - V_39 ;
F_13 () ;
V_38 = F_14 ( V_32 ) ;
if ( ! V_38 )
goto V_40;
V_35 = - V_41 ;
V_37 = F_15 ( V_38 ) ;
if ( V_36 -> V_42 -> V_43 != V_37 -> V_42 -> V_43 ) {
if ( ! F_16 ( V_37 -> V_42 -> V_43 , V_44 ) )
goto V_40;
goto V_45;
}
if ( V_36 -> V_46 != V_37 -> V_46 &&
V_36 -> V_46 != V_37 -> V_47 &&
! F_16 ( V_37 -> V_42 -> V_43 , V_44 ) )
goto V_40;
V_45:
V_4 = V_38 -> V_13 ;
F_17 () ;
}
if ( F_18 ( sizeof( * V_4 ) , V_34 ) )
return - V_6 ;
return F_18 ( F_5 ( V_4 ) , V_33 ) ;
V_40:
F_17 () ;
return V_35 ;
}
T_4 long F_19 ( T_6 T_2 * V_9 , int V_48 , T_6 V_49 ,
struct V_50 T_2 * V_51 , T_6 T_2 * V_52 ,
T_6 V_53 )
{
struct V_54 V_55 ;
T_7 V_56 , * V_57 = NULL ;
int V_58 = 0 ;
int V_59 = V_48 & V_60 ;
if ( V_51 && ( V_59 == V_61 || V_59 == V_62 ||
V_59 == V_63 ||
V_59 == V_64 ) ) {
if ( F_20 ( & V_55 , V_51 ) )
return - V_6 ;
if ( ! F_21 ( & V_55 ) )
return - V_30 ;
V_56 = F_22 ( V_55 ) ;
if ( V_59 == V_61 )
V_56 = F_23 ( F_24 () , V_56 ) ;
V_57 = & V_56 ;
}
if ( V_59 == V_65 || V_59 == V_66 ||
V_59 == V_67 || V_59 == V_68 )
V_58 = ( int ) ( unsigned long ) V_51 ;
return F_25 ( V_9 , V_48 , V_49 , V_57 , V_52 , V_58 , V_53 ) ;
}
