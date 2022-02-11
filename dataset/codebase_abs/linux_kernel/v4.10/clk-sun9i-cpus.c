static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_6 ;
T_1 V_7 ;
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( F_4 ( V_7 ) == V_8 )
V_3 /= F_5 ( V_7 ) + 1 ;
V_6 = V_3 / ( F_6 ( V_7 ) + 1 ) ;
return V_6 ;
}
static long F_7 ( unsigned long V_6 , T_2 * V_9 , T_2 * V_10 ,
T_2 V_11 , unsigned long V_3 )
{
T_2 div , V_12 = 1 ;
if ( V_3 && V_6 > V_3 )
V_6 = V_3 ;
div = F_8 ( V_3 , V_6 ) ;
if ( V_11 == V_8 && div > 4 ) {
if ( div < 32 ) {
V_12 = div ;
div = 1 ;
} else if ( div < 64 ) {
V_12 = F_8 ( div , 2 ) ;
div = 2 ;
} else if ( div < 96 ) {
V_12 = F_8 ( div , 3 ) ;
div = 3 ;
} else {
V_12 = F_8 ( div , 4 ) ;
div = 4 ;
}
}
if ( V_9 ) {
* V_9 = div - 1 ;
* V_10 = V_12 - 1 ;
}
return V_3 / V_12 / div ;
}
static int F_9 ( struct V_1 * V_13 ,
struct V_14 * V_15 )
{
struct V_1 * V_11 , * V_16 = NULL ;
int V_17 , V_18 ;
unsigned long V_3 , V_19 = 0 , V_20 , V_21 = 0 ;
unsigned long V_6 = V_15 -> V_6 ;
V_18 = F_10 ( V_13 ) ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
V_11 = F_11 ( V_13 , V_17 ) ;
if ( ! V_11 )
continue;
if ( F_12 ( V_13 ) & V_22 )
V_3 = F_13 ( V_11 , V_6 ) ;
else
V_3 = F_14 ( V_11 ) ;
V_20 = F_7 ( V_6 , NULL , NULL , V_17 ,
V_3 ) ;
if ( V_20 <= V_6 && V_20 > V_21 ) {
V_16 = V_11 ;
V_19 = V_3 ;
V_21 = V_20 ;
}
}
if ( ! V_16 )
return - V_23 ;
V_15 -> V_24 = V_16 ;
V_15 -> V_25 = V_19 ;
V_15 -> V_6 = V_21 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_26 ;
T_2 div , V_12 , V_11 ;
T_1 V_7 ;
F_16 ( & V_27 , V_26 ) ;
V_7 = F_3 ( V_5 -> V_7 ) ;
V_11 = F_4 ( V_7 ) ;
F_7 ( V_6 , & div , & V_12 , V_11 , V_3 ) ;
V_7 = F_17 ( V_7 , div ) ;
V_7 = F_18 ( V_7 , V_12 ) ;
F_19 ( V_7 , V_5 -> V_7 ) ;
F_20 ( & V_27 , V_26 ) ;
return 0 ;
}
static void F_21 ( struct V_28 * V_29 )
{
const char * V_30 = V_29 -> V_31 ;
const char * V_32 [ V_33 ] ;
struct V_34 V_35 ;
struct V_4 * V_5 ;
struct V_36 * V_37 ;
struct V_13 * V_13 ;
int V_38 ;
V_5 = F_22 ( sizeof( * V_5 ) , V_39 ) ;
if ( ! V_5 )
return;
V_5 -> V_7 = F_23 ( V_29 , 0 , F_24 ( V_29 ) ) ;
if ( F_25 ( V_5 -> V_7 ) )
goto V_40;
F_26 ( V_29 , L_1 , & V_30 ) ;
V_38 = F_27 ( V_29 , V_32 , V_33 ) ;
V_37 = F_22 ( sizeof( * V_37 ) , V_39 ) ;
if ( ! V_37 )
goto V_41;
V_37 -> V_7 = V_5 -> V_7 ;
V_37 -> V_42 = V_43 ;
V_37 -> V_44 = V_45 >> V_43 ;
V_37 -> V_46 = & V_27 ;
V_13 = F_28 ( NULL , V_30 , V_32 , V_38 ,
& V_37 -> V_2 , & V_47 ,
& V_5 -> V_2 , & V_48 ,
NULL , NULL , 0 ) ;
if ( F_25 ( V_13 ) )
goto V_49;
V_38 = F_29 ( V_29 , V_50 , V_13 ) ;
if ( V_38 )
goto V_51;
return;
V_51:
F_30 ( V_13 ) ;
V_49:
F_31 ( V_37 ) ;
V_41:
F_32 ( V_5 -> V_7 ) ;
F_33 ( V_29 , 0 , & V_35 ) ;
F_34 ( V_35 . V_52 , F_35 ( & V_35 ) ) ;
V_40:
F_31 ( V_5 ) ;
}
