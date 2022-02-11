static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_8 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_15 * V_16 = V_11 -> V_16 ;
unsigned long V_17 = 0 , V_18 = 0 ;
int V_19 = 0 ;
unsigned int V_20 , V_21 ;
long V_22 , V_23 ;
int V_24 ;
V_22 = F_2 ( V_9 , V_7 [ V_3 ] . V_25 * 1000 ) ;
if ( V_22 <= 0 )
V_22 = V_7 [ V_3 ] . V_25 * 1000 ;
V_23 = V_22 ;
V_21 = V_22 / 1000 ;
V_20 = F_3 ( V_9 ) / 1000 ;
if ( ! F_4 ( V_16 ) ) {
unsigned long V_26 ;
F_5 () ;
V_5 = F_6 ( V_14 , & V_22 ) ;
if ( F_4 ( V_5 ) ) {
F_7 () ;
F_8 ( V_14 , L_1 ,
V_22 ) ;
return F_9 ( V_5 ) ;
}
V_17 = F_10 ( V_5 ) ;
V_26 = F_11 ( V_5 ) ;
F_7 () ;
V_18 = V_17 * V_11 -> V_27 / 100 ;
V_19 = F_12 ( V_16 ) ;
F_13 ( V_14 , L_2 ,
V_26 / 1000 , V_17 ) ;
}
F_13 ( V_14 , L_3 ,
V_20 / 1000 , ( V_19 > 0 ) ? V_19 / 1000 : - 1 ,
V_21 / 1000 , V_17 ? V_17 / 1000 : - 1 ) ;
if ( ! F_4 ( V_16 ) && V_21 > V_20 ) {
V_24 = F_14 ( V_16 , V_17 , V_18 ) ;
if ( V_24 ) {
F_8 ( V_14 , L_4 ,
V_24 ) ;
return V_24 ;
}
}
V_24 = F_15 ( V_9 , V_23 ) ;
if ( V_24 ) {
F_8 ( V_14 , L_5 , V_24 ) ;
if ( ! F_4 ( V_16 ) && V_19 > 0 )
F_14 ( V_16 , V_19 , V_18 ) ;
return V_24 ;
}
if ( ! F_4 ( V_16 ) && V_21 < V_20 ) {
V_24 = F_14 ( V_16 , V_17 , V_18 ) ;
if ( V_24 ) {
F_8 ( V_14 , L_6 ,
V_24 ) ;
F_15 ( V_9 , V_20 * 1000 ) ;
}
}
return V_24 ;
}
static int F_16 ( int V_28 , struct V_13 * * V_29 ,
struct V_15 * * V_30 , struct V_8 * * V_31 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_24 = 0 ;
char * V_32 = L_7 , * V_33 = L_8 , * V_34 ;
V_14 = F_17 ( V_28 ) ;
if ( ! V_14 ) {
F_18 ( L_9 , V_28 ) ;
return - V_35 ;
}
if ( ! V_28 )
V_34 = V_32 ;
else
V_34 = V_33 ;
V_36:
V_16 = F_19 ( V_14 , V_34 ) ;
V_24 = F_20 ( V_16 ) ;
if ( V_24 ) {
if ( V_24 == - V_37 ) {
F_13 ( V_14 , L_10 ,
V_28 ) ;
return V_24 ;
}
if ( V_34 == V_32 ) {
V_34 = V_33 ;
goto V_36;
}
F_13 ( V_14 , L_11 , V_28 , V_24 ) ;
}
V_9 = F_21 ( V_14 , NULL ) ;
V_24 = F_20 ( V_9 ) ;
if ( V_24 ) {
if ( ! F_4 ( V_16 ) )
F_22 ( V_16 ) ;
if ( V_24 == - V_37 )
F_13 ( V_14 , L_12 , V_28 ) ;
else
F_8 ( V_14 , L_13 , V_28 ,
V_24 ) ;
} else {
* V_29 = V_14 ;
* V_30 = V_16 ;
* V_31 = V_9 ;
}
return V_24 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_38 * V_39 ;
struct V_10 * V_11 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
struct V_4 * V_40 ;
unsigned long V_41 = ~ 0 , V_42 = 0 ;
unsigned int V_43 ;
bool V_44 = false ;
int V_24 ;
V_24 = F_16 ( V_2 -> V_28 , & V_14 , & V_16 , & V_9 ) ;
if ( V_24 ) {
F_18 ( L_14 , V_45 , V_24 ) ;
return V_24 ;
}
V_39 = F_24 ( V_14 -> V_46 ) ;
if ( ! V_39 ) {
F_8 ( V_14 , L_15 , V_2 -> V_28 ) ;
V_24 = - V_47 ;
goto V_48;
}
V_24 = F_25 ( V_14 , V_2 -> V_49 ) ;
if ( V_24 ) {
if ( V_24 == - V_47 )
V_44 = true ;
else
goto V_50;
}
F_26 ( V_2 -> V_49 ) ;
V_24 = F_27 ( V_14 ) ;
if ( V_24 <= 0 ) {
F_28 ( L_16 ) ;
V_24 = - V_37 ;
goto V_51;
}
if ( V_44 ) {
struct V_52 * V_53 = F_29 () ;
if ( ! V_53 || ! V_53 -> V_54 )
F_30 ( V_2 -> V_49 ) ;
V_24 = F_31 ( V_14 , V_2 -> V_49 ) ;
if ( V_24 )
F_8 ( V_14 , L_17 ,
V_45 , V_24 ) ;
F_32 ( V_39 , L_18 , & V_43 ) ;
} else {
V_43 = F_33 ( V_14 ) ;
}
V_11 = F_34 ( sizeof( * V_11 ) , V_55 ) ;
if ( ! V_11 ) {
V_24 = - V_56 ;
goto V_51;
}
F_32 ( V_39 , L_19 , & V_11 -> V_27 ) ;
if ( ! V_43 )
V_43 = V_57 ;
if ( ! F_4 ( V_16 ) ) {
unsigned long V_26 = 0 ;
while ( 1 ) {
struct V_4 * V_5 ;
unsigned long V_58 , V_59 ;
F_5 () ;
V_5 = F_6 ( V_14 , & V_26 ) ;
if ( F_4 ( V_5 ) ) {
F_7 () ;
break;
}
V_58 = F_10 ( V_5 ) ;
F_7 () ;
V_59 = V_58 * V_11 -> V_27 / 100 ;
if ( F_35 ( V_16 ,
V_58 - V_59 ,
V_58 + V_59 ) ) {
if ( V_58 < V_41 )
V_41 = V_58 ;
if ( V_58 > V_42 )
V_42 = V_58 ;
} else {
F_36 ( V_14 , V_26 ) ;
}
V_26 ++ ;
}
V_24 = F_37 ( V_16 , V_41 , V_42 ) ;
if ( V_24 > 0 )
V_43 += V_24 * 1000 ;
}
V_24 = F_38 ( V_14 , & V_7 ) ;
if ( V_24 ) {
F_18 ( L_20 , V_24 ) ;
goto V_60;
}
V_11 -> V_14 = V_14 ;
V_11 -> V_16 = V_16 ;
V_2 -> V_12 = V_11 ;
V_2 -> V_8 = V_9 ;
F_5 () ;
V_40 = F_39 ( V_14 ) ;
if ( V_40 )
V_2 -> V_61 = F_11 ( V_40 ) / 1000 ;
F_7 () ;
V_24 = F_40 ( V_2 , V_7 ) ;
if ( V_24 ) {
F_8 ( V_14 , L_21 , V_45 ,
V_24 ) ;
goto V_62;
}
if ( F_41 ( V_2 ) ) {
V_24 = F_42 () ;
if ( V_24 )
goto V_62;
V_63 [ 1 ] = & V_64 ;
}
V_2 -> V_65 . V_43 = V_43 ;
F_43 ( V_39 ) ;
return 0 ;
V_62:
F_44 ( V_14 , & V_7 ) ;
V_60:
F_45 ( V_11 ) ;
V_51:
F_46 ( V_2 -> V_49 ) ;
V_50:
F_43 ( V_39 ) ;
V_48:
F_47 ( V_9 ) ;
if ( ! F_4 ( V_16 ) )
F_22 ( V_16 ) ;
return V_24 ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
F_49 ( V_11 -> V_29 ) ;
F_44 ( V_11 -> V_14 , & V_2 -> V_7 ) ;
F_46 ( V_2 -> V_66 ) ;
F_47 ( V_2 -> V_8 ) ;
if ( ! F_4 ( V_11 -> V_16 ) )
F_22 ( V_11 -> V_16 ) ;
F_45 ( V_11 ) ;
return 0 ;
}
static void F_50 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_38 * V_39 = F_24 ( V_11 -> V_14 -> V_46 ) ;
if ( F_51 ( ! V_39 ) )
return;
if ( F_52 ( V_39 , L_22 , NULL ) ) {
T_1 V_67 = 0 ;
F_32 ( V_39 , L_23 ,
& V_67 ) ;
V_11 -> V_29 = F_53 ( V_39 ,
V_2 -> V_66 , V_67 , NULL ) ;
if ( F_4 ( V_11 -> V_29 ) ) {
F_8 ( V_11 -> V_14 ,
L_24 ,
F_9 ( V_11 -> V_29 ) ) ;
V_11 -> V_29 = NULL ;
}
}
F_43 ( V_39 ) ;
}
static int F_54 ( struct V_68 * V_69 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_24 ;
V_24 = F_16 ( 0 , & V_14 , & V_16 , & V_9 ) ;
if ( V_24 )
return V_24 ;
F_47 ( V_9 ) ;
if ( ! F_4 ( V_16 ) )
F_22 ( V_16 ) ;
V_70 . V_12 = F_55 ( & V_69 -> V_71 ) ;
V_24 = F_56 ( & V_70 ) ;
if ( V_24 )
F_8 ( V_14 , L_25 , V_24 ) ;
return V_24 ;
}
static int F_57 ( struct V_68 * V_69 )
{
F_58 ( & V_70 ) ;
return 0 ;
}
