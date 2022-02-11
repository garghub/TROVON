static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 ;
unsigned long V_6 = 0 , V_7 = 0 , V_8 = 0 ;
unsigned int V_9 , V_10 ;
long V_11 , V_12 ;
int V_13 ;
V_11 = F_2 ( V_14 , V_15 [ V_3 ] . V_16 * 1000 ) ;
if ( V_11 <= 0 )
V_11 = V_15 [ V_3 ] . V_16 * 1000 ;
V_12 = V_11 ;
V_10 = V_11 / 1000 ;
V_9 = F_3 ( V_14 ) / 1000 ;
if ( ! F_4 ( V_17 ) ) {
F_5 () ;
V_5 = F_6 ( V_18 , & V_11 ) ;
if ( F_4 ( V_5 ) ) {
F_7 () ;
F_8 ( L_1 , V_11 ) ;
return F_9 ( V_5 ) ;
}
V_6 = F_10 ( V_5 ) ;
F_7 () ;
V_8 = V_6 * V_19 / 100 ;
V_7 = F_11 ( V_17 ) ;
}
F_12 ( L_2 ,
V_9 / 1000 , V_7 ? V_7 / 1000 : - 1 ,
V_10 / 1000 , V_6 ? V_6 / 1000 : - 1 ) ;
if ( ! F_4 ( V_17 ) && V_10 > V_9 ) {
V_13 = F_13 ( V_17 , V_6 , V_8 ) ;
if ( V_13 ) {
F_8 ( L_3 , V_13 ) ;
return V_13 ;
}
}
V_13 = F_14 ( V_14 , V_12 ) ;
if ( V_13 ) {
F_8 ( L_4 , V_13 ) ;
if ( ! F_4 ( V_17 ) )
F_13 ( V_17 , V_7 , V_8 ) ;
return V_13 ;
}
if ( ! F_4 ( V_17 ) && V_10 < V_9 ) {
V_13 = F_13 ( V_17 , V_6 , V_8 ) ;
if ( V_13 ) {
F_8 ( L_5 , V_13 ) ;
F_14 ( V_14 , V_9 * 1000 ) ;
}
}
return V_13 ;
}
static int F_15 ( struct V_1 * V_2 )
{
V_2 -> V_20 = V_14 ;
return F_16 ( V_2 , V_15 , V_21 ) ;
}
static int F_17 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
int V_13 ;
V_18 = F_18 ( 0 ) ;
if ( ! V_18 ) {
F_8 ( L_6 ) ;
return - V_26 ;
}
V_25 = F_19 ( V_18 -> V_27 ) ;
if ( ! V_25 ) {
F_8 ( L_7 ) ;
return - V_28 ;
}
V_17 = F_20 ( V_18 , L_8 ) ;
if ( F_4 ( V_17 ) ) {
if ( F_9 ( V_17 ) == - V_29 ) {
F_21 ( V_18 , L_9 ) ;
V_13 = - V_29 ;
goto V_30;
}
F_22 ( L_10 ,
F_9 ( V_17 ) ) ;
}
V_14 = F_23 ( V_18 , NULL ) ;
if ( F_4 ( V_14 ) ) {
V_13 = F_9 ( V_14 ) ;
F_8 ( L_11 , V_13 ) ;
goto V_30;
}
V_13 = F_24 ( V_18 ) ;
if ( V_13 ) {
F_8 ( L_12 , V_13 ) ;
goto V_30;
}
V_13 = F_25 ( V_18 , & V_15 ) ;
if ( V_13 ) {
F_8 ( L_13 , V_13 ) ;
goto V_30;
}
F_26 ( V_25 , L_14 , & V_19 ) ;
if ( F_26 ( V_25 , L_15 , & V_21 ) )
V_21 = V_31 ;
if ( ! F_4 ( V_17 ) ) {
struct V_4 * V_5 ;
unsigned long V_32 , V_33 ;
int V_34 ;
for ( V_34 = 0 ; V_15 [ V_34 ] . V_16 != V_35 ; V_34 ++ )
;
F_5 () ;
V_5 = F_27 ( V_18 ,
V_15 [ 0 ] . V_16 * 1000 , true ) ;
V_32 = F_10 ( V_5 ) ;
V_5 = F_27 ( V_18 ,
V_15 [ V_34 - 1 ] . V_16 * 1000 , true ) ;
V_33 = F_10 ( V_5 ) ;
F_7 () ;
V_13 = F_28 ( V_17 , V_32 , V_33 ) ;
if ( V_13 > 0 )
V_21 += V_13 * 1000 ;
}
V_13 = F_29 ( & V_36 ) ;
if ( V_13 ) {
F_8 ( L_16 , V_13 ) ;
goto V_37;
}
if ( F_30 ( V_25 , L_17 , NULL ) ) {
V_38 = F_31 ( V_25 , V_39 ) ;
if ( F_4 ( V_38 ) )
F_8 ( L_18 ,
F_9 ( V_38 ) ) ;
}
F_32 ( V_25 ) ;
return 0 ;
V_37:
F_33 ( V_18 , & V_15 ) ;
V_30:
F_32 ( V_25 ) ;
return V_13 ;
}
static int F_34 ( struct V_22 * V_23 )
{
F_35 ( V_38 ) ;
F_36 ( & V_36 ) ;
F_33 ( V_18 , & V_15 ) ;
return 0 ;
}
