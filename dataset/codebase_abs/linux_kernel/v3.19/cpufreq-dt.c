static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_8 ;
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_13 * V_14 = V_11 -> V_14 ;
struct V_15 * V_16 = V_11 -> V_16 ;
unsigned long V_17 = 0 , V_18 = 0 , V_19 = 0 ;
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
V_19 = V_17 * V_11 -> V_27 / 100 ;
V_18 = F_12 ( V_16 ) ;
F_13 ( V_14 , L_2 ,
V_26 / 1000 , V_17 ) ;
}
F_13 ( V_14 , L_3 ,
V_20 / 1000 , ( V_18 > 0 ) ? V_18 / 1000 : - 1 ,
V_21 / 1000 , V_17 ? V_17 / 1000 : - 1 ) ;
if ( ! F_4 ( V_16 ) && V_21 > V_20 ) {
V_24 = F_14 ( V_16 , V_17 , V_19 ) ;
if ( V_24 ) {
F_8 ( V_14 , L_4 ,
V_24 ) ;
return V_24 ;
}
}
V_24 = F_15 ( V_9 , V_23 ) ;
if ( V_24 ) {
F_8 ( V_14 , L_5 , V_24 ) ;
if ( ! F_4 ( V_16 ) && V_18 > 0 )
F_14 ( V_16 , V_18 , V_19 ) ;
return V_24 ;
}
if ( ! F_4 ( V_16 ) && V_21 < V_20 ) {
V_24 = F_14 ( V_16 , V_17 , V_19 ) ;
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
if ( F_4 ( V_16 ) ) {
if ( F_9 ( V_16 ) == - V_37 ) {
F_13 ( V_14 , L_10 ,
V_28 ) ;
return - V_37 ;
}
if ( V_34 == V_32 ) {
V_34 = V_33 ;
goto V_36;
}
F_13 ( V_14 , L_11 ,
V_28 , F_9 ( V_16 ) ) ;
}
V_9 = F_20 ( V_14 , NULL ) ;
if ( F_4 ( V_9 ) ) {
if ( ! F_4 ( V_16 ) )
F_21 ( V_16 ) ;
V_24 = F_9 ( V_9 ) ;
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
static int F_22 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
struct V_6 * V_7 ;
struct V_40 * V_41 ;
struct V_10 * V_11 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
unsigned long V_42 = ~ 0 , V_43 = 0 ;
unsigned int V_44 ;
int V_24 ;
V_24 = F_16 ( V_2 -> V_28 , & V_14 , & V_16 , & V_9 ) ;
if ( V_24 ) {
F_18 ( L_14 , V_45 , V_24 ) ;
return V_24 ;
}
V_41 = F_23 ( V_14 -> V_46 ) ;
if ( ! V_41 ) {
F_8 ( V_14 , L_15 , V_2 -> V_28 ) ;
V_24 = - V_47 ;
goto V_48;
}
F_24 ( V_14 ) ;
V_24 = F_25 ( V_14 ) ;
if ( V_24 <= 0 ) {
F_26 ( L_16 ) ;
V_24 = - V_37 ;
goto V_49;
}
V_11 = F_27 ( sizeof( * V_11 ) , V_50 ) ;
if ( ! V_11 ) {
V_24 = - V_51 ;
goto V_49;
}
F_28 ( V_41 , L_17 , & V_11 -> V_27 ) ;
if ( F_28 ( V_41 , L_18 , & V_44 ) )
V_44 = V_52 ;
if ( ! F_4 ( V_16 ) ) {
unsigned long V_26 = 0 ;
while ( 1 ) {
struct V_4 * V_5 ;
unsigned long V_53 , V_54 ;
F_5 () ;
V_5 = F_6 ( V_14 , & V_26 ) ;
if ( F_4 ( V_5 ) ) {
F_7 () ;
break;
}
V_53 = F_10 ( V_5 ) ;
F_7 () ;
V_54 = V_53 * V_11 -> V_27 / 100 ;
if ( F_29 ( V_16 , V_53 ,
V_53 + V_54 ) ) {
if ( V_53 < V_42 )
V_42 = V_53 ;
if ( V_53 > V_43 )
V_43 = V_53 ;
} else {
F_30 ( V_14 , V_26 ) ;
}
V_26 ++ ;
}
V_24 = F_31 ( V_16 , V_42 , V_43 ) ;
if ( V_24 > 0 )
V_44 += V_24 * 1000 ;
}
V_24 = F_32 ( V_14 , & V_7 ) ;
if ( V_24 ) {
F_18 ( L_19 , V_24 ) ;
goto V_55;
}
V_11 -> V_14 = V_14 ;
V_11 -> V_16 = V_16 ;
V_2 -> V_12 = V_11 ;
V_2 -> V_8 = V_9 ;
V_24 = F_33 ( V_2 , V_7 ) ;
if ( V_24 ) {
F_8 ( V_14 , L_20 , V_45 ,
V_24 ) ;
goto V_56;
}
V_2 -> V_57 . V_44 = V_44 ;
V_39 = F_34 () ;
if ( ! V_39 || ! V_39 -> V_58 )
F_35 ( V_2 -> V_59 ) ;
F_36 ( V_41 ) ;
return 0 ;
V_56:
F_37 ( V_14 , & V_7 ) ;
V_55:
F_38 ( V_11 ) ;
V_49:
F_39 ( V_14 ) ;
F_36 ( V_41 ) ;
V_48:
F_40 ( V_9 ) ;
if ( ! F_4 ( V_16 ) )
F_21 ( V_16 ) ;
return V_24 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
if ( V_11 -> V_29 )
F_42 ( V_11 -> V_29 ) ;
F_37 ( V_11 -> V_14 , & V_2 -> V_7 ) ;
F_39 ( V_11 -> V_14 ) ;
F_40 ( V_2 -> V_8 ) ;
if ( ! F_4 ( V_11 -> V_16 ) )
F_21 ( V_11 -> V_16 ) ;
F_38 ( V_11 ) ;
return 0 ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
struct V_40 * V_41 = F_23 ( V_11 -> V_14 -> V_46 ) ;
if ( F_44 ( ! V_41 ) )
return;
if ( F_45 ( V_41 , L_21 , NULL ) ) {
V_11 -> V_29 = F_46 ( V_41 ,
V_2 -> V_60 ) ;
if ( F_4 ( V_11 -> V_29 ) ) {
F_8 ( V_11 -> V_14 ,
L_22 ,
F_9 ( V_11 -> V_29 ) ) ;
V_11 -> V_29 = NULL ;
}
}
F_36 ( V_41 ) ;
}
static int F_47 ( struct V_61 * V_62 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_24 ;
V_24 = F_16 ( 0 , & V_14 , & V_16 , & V_9 ) ;
if ( V_24 )
return V_24 ;
F_40 ( V_9 ) ;
if ( ! F_4 ( V_16 ) )
F_21 ( V_16 ) ;
V_63 . V_12 = F_48 ( & V_62 -> V_64 ) ;
V_24 = F_49 ( & V_63 ) ;
if ( V_24 )
F_8 ( V_14 , L_23 , V_24 ) ;
return V_24 ;
}
static int F_50 ( struct V_61 * V_62 )
{
F_51 ( & V_63 ) ;
return 0 ;
}
