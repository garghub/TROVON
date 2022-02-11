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
F_5 () ;
V_5 = F_6 ( V_14 , & V_22 ) ;
if ( F_4 ( V_5 ) ) {
F_7 () ;
F_8 ( V_14 , L_1 ,
V_22 ) ;
return F_9 ( V_5 ) ;
}
V_17 = F_10 ( V_5 ) ;
F_7 () ;
V_19 = V_17 * V_11 -> V_26 / 100 ;
V_18 = F_11 ( V_16 ) ;
}
F_12 ( V_14 , L_2 ,
V_20 / 1000 , V_18 ? V_18 / 1000 : - 1 ,
V_21 / 1000 , V_17 ? V_17 / 1000 : - 1 ) ;
if ( ! F_4 ( V_16 ) && V_21 > V_20 ) {
V_24 = F_13 ( V_16 , V_17 , V_19 ) ;
if ( V_24 ) {
F_8 ( V_14 , L_3 ,
V_24 ) ;
return V_24 ;
}
}
V_24 = F_14 ( V_9 , V_23 ) ;
if ( V_24 ) {
F_8 ( V_14 , L_4 , V_24 ) ;
if ( ! F_4 ( V_16 ) )
F_13 ( V_16 , V_18 , V_19 ) ;
return V_24 ;
}
if ( ! F_4 ( V_16 ) && V_21 < V_20 ) {
V_24 = F_13 ( V_16 , V_17 , V_19 ) ;
if ( V_24 ) {
F_8 ( V_14 , L_5 ,
V_24 ) ;
F_14 ( V_9 , V_20 * 1000 ) ;
}
}
return V_24 ;
}
static int F_15 ( int V_27 , struct V_13 * * V_28 ,
struct V_15 * * V_29 , struct V_8 * * V_30 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_24 = 0 ;
char * V_31 = L_6 , * V_32 = L_7 , * V_33 ;
V_14 = F_16 ( V_27 ) ;
if ( ! V_14 ) {
F_17 ( L_8 , V_27 ) ;
return - V_34 ;
}
if ( ! V_27 )
V_33 = V_31 ;
else
V_33 = V_32 ;
V_35:
V_16 = F_18 ( V_14 , V_33 ) ;
if ( F_4 ( V_16 ) ) {
if ( F_9 ( V_16 ) == - V_36 ) {
F_12 ( V_14 , L_9 ,
V_27 ) ;
return - V_36 ;
}
if ( V_33 == V_31 ) {
V_33 = V_32 ;
goto V_35;
}
F_12 ( V_14 , L_10 ,
V_27 , F_9 ( V_16 ) ) ;
}
V_9 = F_19 ( V_14 , NULL ) ;
if ( F_4 ( V_9 ) ) {
if ( ! F_4 ( V_16 ) )
F_20 ( V_16 ) ;
V_24 = F_9 ( V_9 ) ;
if ( V_24 == - V_36 )
F_12 ( V_14 , L_11 , V_27 ) ;
else
F_8 ( V_14 , L_12 , V_27 ,
V_24 ) ;
} else {
* V_28 = V_14 ;
* V_29 = V_16 ;
* V_30 = V_9 ;
}
return V_24 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_37 * V_38 ;
struct V_6 * V_7 ;
struct V_39 * V_28 ;
struct V_40 * V_41 ;
struct V_10 * V_11 ;
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
unsigned long V_42 = ~ 0 , V_43 = 0 ;
unsigned int V_44 ;
int V_24 ;
V_24 = F_15 ( V_2 -> V_27 , & V_14 , & V_16 , & V_9 ) ;
if ( V_24 ) {
F_17 ( L_13 , V_45 , V_24 ) ;
return V_24 ;
}
V_41 = F_22 ( V_14 -> V_46 ) ;
if ( ! V_41 ) {
F_8 ( V_14 , L_14 , V_2 -> V_27 ) ;
V_24 = - V_47 ;
goto V_48;
}
F_23 ( V_14 ) ;
V_11 = F_24 ( sizeof( * V_11 ) , V_49 ) ;
if ( ! V_11 ) {
V_24 = - V_50 ;
goto V_51;
}
F_25 ( V_41 , L_15 , & V_11 -> V_26 ) ;
if ( F_25 ( V_41 , L_16 , & V_44 ) )
V_44 = V_52 ;
if ( ! F_4 ( V_16 ) ) {
unsigned long V_53 = 0 ;
while ( 1 ) {
struct V_4 * V_5 ;
unsigned long V_54 , V_55 ;
F_5 () ;
V_5 = F_6 ( V_14 , & V_53 ) ;
if ( F_4 ( V_5 ) ) {
F_7 () ;
break;
}
V_54 = F_10 ( V_5 ) ;
F_7 () ;
V_55 = V_54 * V_11 -> V_26 / 100 ;
if ( F_26 ( V_16 , V_54 ,
V_54 + V_55 ) ) {
if ( V_54 < V_42 )
V_42 = V_54 ;
if ( V_54 > V_43 )
V_43 = V_54 ;
} else {
F_27 ( V_14 , V_53 ) ;
}
V_53 ++ ;
}
V_24 = F_28 ( V_16 , V_42 , V_43 ) ;
if ( V_24 > 0 )
V_44 += V_24 * 1000 ;
}
V_24 = F_29 ( V_14 , & V_7 ) ;
if ( V_24 ) {
F_17 ( L_17 , V_24 ) ;
goto V_56;
}
if ( F_30 ( V_41 , L_18 , NULL ) ) {
V_28 = F_31 ( V_41 , V_57 ) ;
if ( F_4 ( V_28 ) )
F_8 ( V_14 ,
L_19 ,
F_9 ( V_28 ) ) ;
else
V_11 -> V_28 = V_28 ;
}
V_11 -> V_14 = V_14 ;
V_11 -> V_16 = V_16 ;
V_2 -> V_12 = V_11 ;
V_2 -> V_8 = V_9 ;
V_24 = F_32 ( V_2 , V_7 ) ;
if ( V_24 ) {
F_8 ( V_14 , L_20 , V_45 ,
V_24 ) ;
goto V_58;
}
V_2 -> V_59 . V_44 = V_44 ;
V_38 = F_33 () ;
if ( ! V_38 || ! V_38 -> V_60 )
F_34 ( V_2 -> V_61 ) ;
F_35 ( V_41 ) ;
return 0 ;
V_58:
F_36 ( V_11 -> V_28 ) ;
F_37 ( V_14 , & V_7 ) ;
V_56:
F_38 ( V_11 ) ;
V_51:
F_35 ( V_41 ) ;
V_48:
F_39 ( V_9 ) ;
if ( ! F_4 ( V_16 ) )
F_20 ( V_16 ) ;
return V_24 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
F_36 ( V_11 -> V_28 ) ;
F_37 ( V_11 -> V_14 , & V_2 -> V_7 ) ;
F_39 ( V_2 -> V_8 ) ;
if ( ! F_4 ( V_11 -> V_16 ) )
F_20 ( V_11 -> V_16 ) ;
F_38 ( V_11 ) ;
return 0 ;
}
static int F_41 ( struct V_62 * V_63 )
{
struct V_13 * V_14 ;
struct V_15 * V_16 ;
struct V_8 * V_9 ;
int V_24 ;
V_24 = F_15 ( 0 , & V_14 , & V_16 , & V_9 ) ;
if ( V_24 )
return V_24 ;
F_39 ( V_9 ) ;
if ( ! F_4 ( V_16 ) )
F_20 ( V_16 ) ;
V_64 . V_12 = F_42 ( & V_63 -> V_65 ) ;
V_24 = F_43 ( & V_64 ) ;
if ( V_24 )
F_8 ( V_14 , L_21 , V_24 ) ;
return V_24 ;
}
static int F_44 ( struct V_62 * V_63 )
{
F_45 ( & V_64 ) ;
return 0 ;
}
