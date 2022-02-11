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
if ( F_8 ( V_8 , V_2 , V_23 , & V_11 , false ) )
goto V_24;
V_12 = F_9 ( V_8 , V_5 -> V_25 ) ;
if ( V_5 -> V_26 & V_27 )
V_12 = F_10 ( F_11 ( V_12 ) ) ;
V_16 = - V_28 ;
V_13 = F_12 ( V_2 , V_3 , V_6 , & V_14 ) ;
if ( ! F_13 ( * V_13 ) )
goto V_29;
F_14 ( V_2 , V_30 ) ;
F_15 ( V_8 , V_5 , V_6 , false ) ;
F_16 ( V_8 , V_11 , false , false ) ;
F_17 ( V_8 , V_5 ) ;
F_18 ( V_2 , V_6 , V_13 , V_12 ) ;
F_19 ( V_5 , V_6 , V_13 ) ;
F_20 ( V_13 , V_14 ) ;
V_16 = 0 ;
V_19:
return V_16 ;
V_29:
F_20 ( V_13 , V_14 ) ;
F_21 ( V_8 , V_11 , false ) ;
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
T_6 * V_36 ;
V_34 = F_28 ( V_32 , V_33 ) ;
V_35 = F_29 ( V_32 , V_34 , V_33 ) ;
if ( ! V_35 )
return NULL ;
V_36 = F_30 ( V_32 , V_35 , V_33 ) ;
if ( ! V_36 )
return NULL ;
return F_31 ( V_32 , V_36 , V_33 ) ;
}
static T_7 T_8 F_32 ( struct V_1 * V_2 ,
struct V_4 * V_5 ,
unsigned long V_37 ,
unsigned long V_38 ,
unsigned long V_39 ,
bool V_40 )
{
int V_41 = V_5 -> V_26 & V_42 ;
int V_43 = V_5 -> V_26 & V_42 ;
T_8 V_44 ;
T_2 * V_13 ;
unsigned long V_7 , V_6 ;
long V_45 ;
struct V_8 * V_8 ;
struct V_46 * V_47 ;
unsigned long V_48 ;
T_9 V_49 ;
T_10 V_50 ;
struct V_51 * V_52 ;
if ( V_40 ) {
F_33 ( & V_2 -> V_53 ) ;
return - V_54 ;
}
V_7 = V_38 ;
V_6 = V_37 ;
V_45 = 0 ;
V_8 = NULL ;
V_48 = F_34 ( V_5 ) ;
V_44 = - V_54 ;
if ( V_37 & ( V_48 - 1 ) || V_39 & ( V_48 - 1 ) )
goto V_31;
V_55:
if ( ! V_5 ) {
V_44 = - V_56 ;
V_5 = F_35 ( V_2 , V_37 ) ;
if ( ! V_5 || ! F_36 ( V_5 ) )
goto V_31;
if ( ! V_5 -> V_57 . V_58 )
goto V_31;
if ( V_37 < V_5 -> V_59 ||
V_37 + V_39 > V_5 -> V_60 )
goto V_31;
V_44 = - V_54 ;
if ( V_48 != F_34 ( V_5 ) )
goto V_31;
V_43 = V_5 -> V_26 & V_42 ;
}
if ( F_37 ( V_6 & ( V_48 - 1 ) ||
( V_39 - V_45 ) & ( V_48 - 1 ) ) )
goto V_31;
V_44 = - V_17 ;
if ( ! V_43 ) {
if ( F_6 ( F_38 ( V_5 ) ) )
goto V_31;
}
V_47 = F_39 ( V_5 ) ;
while ( V_7 < V_38 + V_39 ) {
T_2 V_61 ;
F_40 ( V_6 >= V_37 + V_39 ) ;
F_41 ( V_6 & ~ F_42 ( V_47 ) ) ;
V_49 = F_43 ( V_5 , V_6 ) ;
V_52 = V_5 -> V_62 -> V_63 ;
V_50 = F_44 ( V_47 , V_2 , V_5 , V_52 ,
V_49 , V_6 ) ;
F_45 ( & V_64 [ V_50 ] ) ;
V_44 = - V_17 ;
V_13 = F_46 ( V_2 , V_6 , F_47 ( V_47 ) ) ;
if ( ! V_13 ) {
F_48 ( & V_64 [ V_50 ] ) ;
goto V_31;
}
V_44 = - V_28 ;
V_61 = F_49 ( V_13 ) ;
if ( ! F_50 ( V_61 ) ) {
F_48 ( & V_64 [ V_50 ] ) ;
goto V_31;
}
V_44 = F_51 ( V_2 , V_13 , V_5 ,
V_6 , V_7 , & V_8 ) ;
F_48 ( & V_64 [ V_50 ] ) ;
V_41 = V_43 ;
F_52 () ;
if ( F_6 ( V_44 == - V_22 ) ) {
F_33 ( & V_2 -> V_53 ) ;
F_40 ( ! V_8 ) ;
V_44 = F_53 ( V_8 ,
( const void V_20 * ) V_7 ,
F_54 ( V_47 ) , true ) ;
if ( F_6 ( V_44 ) ) {
V_44 = - V_22 ;
goto V_19;
}
F_55 ( & V_2 -> V_53 ) ;
V_5 = NULL ;
goto V_55;
} else
F_40 ( V_8 ) ;
if ( ! V_44 ) {
V_6 += V_48 ;
V_7 += V_48 ;
V_45 += V_48 ;
if ( F_56 ( V_65 ) )
V_44 = - V_66 ;
}
if ( V_44 )
break;
}
V_31:
F_33 ( & V_2 -> V_53 ) ;
V_19:
if ( V_8 ) {
if ( V_41 )
F_57 ( V_8 ) ;
else
F_58 ( V_8 ) ;
F_22 ( V_8 ) ;
}
F_40 ( V_45 < 0 ) ;
F_40 ( V_44 > 0 ) ;
F_40 ( ! V_45 && ! V_44 ) ;
return V_45 ? V_45 : V_44 ;
}
static T_7 T_8 F_59 ( struct V_1 * V_2 ,
T_1 * V_3 ,
struct V_4 * V_5 ,
unsigned long V_6 ,
unsigned long V_7 ,
struct V_8 * * V_8 ,
bool V_40 )
{
T_8 V_44 ;
if ( F_60 ( V_5 ) ) {
if ( ! V_40 )
V_44 = F_1 ( V_2 , V_3 , V_5 ,
V_6 , V_7 , V_8 ) ;
else
V_44 = F_23 ( V_2 , V_3 ,
V_5 , V_6 ) ;
} else {
if ( ! V_40 )
V_44 = F_61 ( V_2 , V_3 ,
V_5 , V_6 ,
V_7 , V_8 ) ;
else
V_44 = F_62 ( V_2 , V_3 ,
V_5 , V_6 ) ;
}
return V_44 ;
}
static T_7 T_8 F_63 ( struct V_1 * V_2 ,
unsigned long V_37 ,
unsigned long V_38 ,
unsigned long V_39 ,
bool V_40 )
{
struct V_4 * V_5 ;
T_8 V_44 ;
T_1 * V_3 ;
unsigned long V_7 , V_6 ;
long V_45 ;
struct V_8 * V_8 ;
F_40 ( V_37 & ~ V_67 ) ;
F_40 ( V_39 & ~ V_67 ) ;
F_40 ( V_38 + V_39 <= V_38 ) ;
F_40 ( V_37 + V_39 <= V_37 ) ;
V_7 = V_38 ;
V_6 = V_37 ;
V_45 = 0 ;
V_8 = NULL ;
V_55:
F_55 ( & V_2 -> V_53 ) ;
V_44 = - V_56 ;
V_5 = F_35 ( V_2 , V_37 ) ;
if ( ! V_5 )
goto V_31;
if ( ! V_5 -> V_57 . V_58 )
goto V_31;
if ( V_37 < V_5 -> V_59 ||
V_37 + V_39 > V_5 -> V_60 )
goto V_31;
V_44 = - V_54 ;
if ( F_64 ( F_60 ( V_5 ) &&
V_5 -> V_26 & V_42 ) )
goto V_31;
if ( F_36 ( V_5 ) )
return F_32 ( V_2 , V_5 , V_37 ,
V_38 , V_39 , V_40 ) ;
if ( ! F_60 ( V_5 ) && ! F_65 ( V_5 ) )
goto V_31;
V_44 = - V_17 ;
if ( F_60 ( V_5 ) && F_6 ( F_38 ( V_5 ) ) )
goto V_31;
while ( V_7 < V_38 + V_39 ) {
T_1 V_68 ;
F_40 ( V_6 >= V_37 + V_39 ) ;
V_3 = F_27 ( V_2 , V_6 ) ;
if ( F_6 ( ! V_3 ) ) {
V_44 = - V_17 ;
break;
}
V_68 = F_66 ( V_3 ) ;
if ( F_6 ( F_67 ( V_68 ) ) ) {
V_44 = - V_28 ;
break;
}
if ( F_6 ( F_68 ( V_68 ) ) &&
F_6 ( F_69 ( V_2 , V_3 , V_6 ) ) ) {
V_44 = - V_17 ;
break;
}
if ( F_6 ( F_67 ( * V_3 ) ) ) {
V_44 = - V_22 ;
break;
}
F_40 ( F_68 ( * V_3 ) ) ;
F_40 ( F_67 ( * V_3 ) ) ;
V_44 = F_59 ( V_2 , V_3 , V_5 , V_6 ,
V_7 , & V_8 , V_40 ) ;
F_52 () ;
if ( F_6 ( V_44 == - V_22 ) ) {
void * V_15 ;
F_33 ( & V_2 -> V_53 ) ;
F_40 ( ! V_8 ) ;
V_15 = F_70 ( V_8 ) ;
V_44 = F_4 ( V_15 ,
( const void V_20 * ) V_7 ,
V_21 ) ;
F_71 ( V_8 ) ;
if ( F_6 ( V_44 ) ) {
V_44 = - V_22 ;
goto V_19;
}
goto V_55;
} else
F_40 ( V_8 ) ;
if ( ! V_44 ) {
V_6 += V_21 ;
V_7 += V_21 ;
V_45 += V_21 ;
if ( F_56 ( V_65 ) )
V_44 = - V_66 ;
}
if ( V_44 )
break;
}
V_31:
F_33 ( & V_2 -> V_53 ) ;
V_19:
if ( V_8 )
F_22 ( V_8 ) ;
F_40 ( V_45 < 0 ) ;
F_40 ( V_44 > 0 ) ;
F_40 ( ! V_45 && ! V_44 ) ;
return V_45 ? V_45 : V_44 ;
}
T_8 F_72 ( struct V_1 * V_2 , unsigned long V_37 ,
unsigned long V_38 , unsigned long V_39 )
{
return F_63 ( V_2 , V_37 , V_38 , V_39 , false ) ;
}
T_8 F_73 ( struct V_1 * V_2 , unsigned long V_69 ,
unsigned long V_39 )
{
return F_63 ( V_2 , V_69 , 0 , V_39 , true ) ;
}
