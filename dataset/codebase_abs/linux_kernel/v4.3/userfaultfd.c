static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 ,
struct V_4 * V_5 ,
unsigned long V_6 ,
unsigned long V_7 ,
struct V_8 * * V_9 )
{
struct V_10 * V_11 ;
T_2 V_12 , * V_13 ;
T_3 * V_14 ;
void * V_15 ;
int V_16 ;
struct V_8 * V_8 ;
if ( ! * V_9 ) {
V_16 = - V_17 ;
V_8 = F_2 ( V_18 , V_5 , V_6 ) ;
if ( ! V_8 )
goto V_19;
V_15 = F_3 ( V_8 ) ;
V_16 = F_4 ( V_15 ,
( const void V_20 * ) V_7 ,
V_21 ) ;
F_5 ( V_15 ) ;
if ( F_6 ( V_16 ) ) {
V_16 = - V_22 ;
* V_9 = V_8 ;
goto V_19;
}
} else {
V_8 = * V_9 ;
* V_9 = NULL ;
}
F_7 ( V_8 ) ;
V_16 = - V_17 ;
if ( F_8 ( V_8 , V_2 , V_23 , & V_11 ) )
goto V_24;
V_12 = F_9 ( V_8 , V_5 -> V_25 ) ;
if ( V_5 -> V_26 & V_27 )
V_12 = F_10 ( F_11 ( V_12 ) ) ;
V_16 = - V_28 ;
V_13 = F_12 ( V_2 , V_3 , V_6 , & V_14 ) ;
if ( ! F_13 ( * V_13 ) )
goto V_29;
F_14 ( V_2 , V_30 ) ;
F_15 ( V_8 , V_5 , V_6 ) ;
F_16 ( V_8 , V_11 , false ) ;
F_17 ( V_8 , V_5 ) ;
F_18 ( V_2 , V_6 , V_13 , V_12 ) ;
F_19 ( V_5 , V_6 , V_13 ) ;
F_20 ( V_13 , V_14 ) ;
V_16 = 0 ;
V_19:
return V_16 ;
V_29:
F_20 ( V_13 , V_14 ) ;
F_21 ( V_8 , V_11 ) ;
V_24:
F_22 ( V_8 ) ;
goto V_19;
}
static int F_23 ( struct V_1 * V_2 ,
T_1 * V_3 ,
struct V_4 * V_5 ,
unsigned long V_6 )
{
T_2 V_12 , * V_13 ;
T_3 * V_14 ;
int V_16 ;
V_12 = F_24 ( F_25 ( F_26 ( V_6 ) ,
V_5 -> V_25 ) ) ;
V_16 = - V_28 ;
V_13 = F_12 ( V_2 , V_3 , V_6 , & V_14 ) ;
if ( ! F_13 ( * V_13 ) )
goto V_31;
F_18 ( V_2 , V_6 , V_13 , V_12 ) ;
F_19 ( V_5 , V_6 , V_13 ) ;
V_16 = 0 ;
V_31:
F_20 ( V_13 , V_14 ) ;
return V_16 ;
}
static T_1 * F_27 ( struct V_1 * V_32 , unsigned long V_33 )
{
T_4 * V_34 ;
T_5 * V_35 ;
T_1 * V_36 = NULL ;
V_34 = F_28 ( V_32 , V_33 ) ;
V_35 = F_29 ( V_32 , V_34 , V_33 ) ;
if ( V_35 )
V_36 = F_30 ( V_32 , V_35 , V_33 ) ;
return V_36 ;
}
static T_6 T_7 F_31 ( struct V_1 * V_2 ,
unsigned long V_37 ,
unsigned long V_38 ,
unsigned long V_39 ,
bool V_40 )
{
struct V_4 * V_5 ;
T_7 V_41 ;
T_1 * V_3 ;
unsigned long V_7 , V_6 ;
long V_42 ;
struct V_8 * V_8 ;
F_32 ( V_37 & ~ V_43 ) ;
F_32 ( V_39 & ~ V_43 ) ;
F_32 ( V_38 + V_39 <= V_38 ) ;
F_32 ( V_37 + V_39 <= V_37 ) ;
V_7 = V_38 ;
V_6 = V_37 ;
V_42 = 0 ;
V_8 = NULL ;
V_44:
F_33 ( & V_2 -> V_45 ) ;
V_41 = - V_46 ;
V_5 = F_34 ( V_2 , V_37 ) ;
if ( ! V_5 || ( V_5 -> V_26 & V_47 ) )
goto V_31;
if ( V_37 < V_5 -> V_48 ||
V_37 + V_39 > V_5 -> V_49 )
goto V_31;
if ( ! V_5 -> V_50 . V_51 )
goto V_31;
if ( V_5 -> V_52 )
goto V_31;
V_41 = - V_17 ;
if ( F_6 ( F_35 ( V_5 ) ) )
goto V_31;
while ( V_7 < V_38 + V_39 ) {
T_1 V_53 ;
F_32 ( V_6 >= V_37 + V_39 ) ;
V_3 = F_27 ( V_2 , V_6 ) ;
if ( F_6 ( ! V_3 ) ) {
V_41 = - V_17 ;
break;
}
V_53 = F_36 ( V_3 ) ;
if ( F_6 ( F_37 ( V_53 ) ) ) {
V_41 = - V_28 ;
break;
}
if ( F_6 ( F_38 ( V_53 ) ) &&
F_6 ( F_39 ( V_2 , V_5 , V_3 ,
V_6 ) ) ) {
V_41 = - V_17 ;
break;
}
if ( F_6 ( F_37 ( * V_3 ) ) ) {
V_41 = - V_22 ;
break;
}
F_32 ( F_38 ( * V_3 ) ) ;
F_32 ( F_37 ( * V_3 ) ) ;
if ( ! V_40 )
V_41 = F_1 ( V_2 , V_3 , V_5 ,
V_6 , V_7 , & V_8 ) ;
else
V_41 = F_23 ( V_2 , V_3 , V_5 ,
V_6 ) ;
F_40 () ;
if ( F_6 ( V_41 == - V_22 ) ) {
void * V_15 ;
F_41 ( & V_2 -> V_45 ) ;
F_32 ( ! V_8 ) ;
V_15 = F_42 ( V_8 ) ;
V_41 = F_4 ( V_15 ,
( const void V_20 * ) V_7 ,
V_21 ) ;
F_43 ( V_8 ) ;
if ( F_6 ( V_41 ) ) {
V_41 = - V_22 ;
goto V_19;
}
goto V_44;
} else
F_32 ( V_8 ) ;
if ( ! V_41 ) {
V_6 += V_21 ;
V_7 += V_21 ;
V_42 += V_21 ;
if ( F_44 ( V_54 ) )
V_41 = - V_55 ;
}
if ( V_41 )
break;
}
V_31:
F_41 ( & V_2 -> V_45 ) ;
V_19:
if ( V_8 )
F_22 ( V_8 ) ;
F_32 ( V_42 < 0 ) ;
F_32 ( V_41 > 0 ) ;
F_32 ( ! V_42 && ! V_41 ) ;
return V_42 ? V_42 : V_41 ;
}
T_7 F_45 ( struct V_1 * V_2 , unsigned long V_37 ,
unsigned long V_38 , unsigned long V_39 )
{
return F_31 ( V_2 , V_37 , V_38 , V_39 , false ) ;
}
T_7 F_46 ( struct V_1 * V_2 , unsigned long V_56 ,
unsigned long V_39 )
{
return F_31 ( V_2 , V_56 , 0 , V_39 , true ) ;
}
