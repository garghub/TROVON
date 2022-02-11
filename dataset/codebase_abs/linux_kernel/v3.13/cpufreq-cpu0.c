static unsigned int F_1 ( unsigned int V_1 )
{
return F_2 ( V_2 ) / 1000 ;
}
static int F_3 ( struct V_3 * V_4 , unsigned int V_5 )
{
struct V_6 * V_7 ;
unsigned long V_8 = 0 , V_9 = 0 , V_10 = 0 ;
unsigned int V_11 , V_12 ;
long V_13 , V_14 ;
int V_15 ;
V_13 = F_4 ( V_2 , V_16 [ V_5 ] . V_17 * 1000 ) ;
if ( V_13 < 0 )
V_13 = V_16 [ V_5 ] . V_17 * 1000 ;
V_14 = V_13 ;
V_12 = V_13 / 1000 ;
V_11 = F_2 ( V_2 ) / 1000 ;
if ( ! F_5 ( V_18 ) ) {
F_6 () ;
V_7 = F_7 ( V_19 , & V_13 ) ;
if ( F_5 ( V_7 ) ) {
F_8 () ;
F_9 ( L_1 , V_13 ) ;
return F_10 ( V_7 ) ;
}
V_8 = F_11 ( V_7 ) ;
F_8 () ;
V_10 = V_8 * V_20 / 100 ;
V_9 = F_12 ( V_18 ) ;
}
F_13 ( L_2 ,
V_11 / 1000 , V_9 ? V_9 / 1000 : - 1 ,
V_12 / 1000 , V_8 ? V_8 / 1000 : - 1 ) ;
if ( ! F_5 ( V_18 ) && V_12 > V_11 ) {
V_15 = F_14 ( V_18 , V_8 , V_10 ) ;
if ( V_15 ) {
F_9 ( L_3 , V_15 ) ;
return V_15 ;
}
}
V_15 = F_15 ( V_2 , V_14 ) ;
if ( V_15 ) {
F_9 ( L_4 , V_15 ) ;
if ( ! F_5 ( V_18 ) )
F_14 ( V_18 , V_9 , V_10 ) ;
return V_15 ;
}
if ( ! F_5 ( V_18 ) && V_12 < V_11 ) {
V_15 = F_14 ( V_18 , V_8 , V_10 ) ;
if ( V_15 ) {
F_9 ( L_5 , V_15 ) ;
F_15 ( V_2 , V_11 * 1000 ) ;
}
}
return V_15 ;
}
static int F_16 ( struct V_3 * V_4 )
{
return F_17 ( V_4 , V_16 , V_21 ) ;
}
static int F_18 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
int V_15 ;
V_19 = F_19 ( 0 ) ;
if ( ! V_19 ) {
F_9 ( L_6 ) ;
return - V_26 ;
}
V_25 = F_20 ( V_19 -> V_27 ) ;
if ( ! V_25 ) {
F_9 ( L_7 ) ;
return - V_28 ;
}
V_18 = F_21 ( V_19 , L_8 ) ;
if ( F_5 ( V_18 ) ) {
if ( F_10 ( V_18 ) == - V_29 ) {
F_22 ( V_19 , L_9 ) ;
V_15 = - V_29 ;
goto V_30;
}
F_23 ( L_10 ,
F_10 ( V_18 ) ) ;
}
V_2 = F_24 ( V_19 , NULL ) ;
if ( F_5 ( V_2 ) ) {
V_15 = F_10 ( V_2 ) ;
F_9 ( L_11 , V_15 ) ;
goto V_30;
}
V_15 = F_25 ( V_19 ) ;
if ( V_15 ) {
F_9 ( L_12 , V_15 ) ;
goto V_30;
}
V_15 = F_26 ( V_19 , & V_16 ) ;
if ( V_15 ) {
F_9 ( L_13 , V_15 ) ;
goto V_30;
}
F_27 ( V_25 , L_14 , & V_20 ) ;
if ( F_27 ( V_25 , L_15 , & V_21 ) )
V_21 = V_31 ;
if ( ! F_5 ( V_18 ) ) {
struct V_6 * V_7 ;
unsigned long V_32 , V_33 ;
int V_34 ;
for ( V_34 = 0 ; V_16 [ V_34 ] . V_17 != V_35 ; V_34 ++ )
;
F_6 () ;
V_7 = F_28 ( V_19 ,
V_16 [ 0 ] . V_17 * 1000 , true ) ;
V_32 = F_11 ( V_7 ) ;
V_7 = F_28 ( V_19 ,
V_16 [ V_34 - 1 ] . V_17 * 1000 , true ) ;
V_33 = F_11 ( V_7 ) ;
F_8 () ;
V_15 = F_29 ( V_18 , V_32 , V_33 ) ;
if ( V_15 > 0 )
V_21 += V_15 * 1000 ;
}
V_15 = F_30 ( & V_36 ) ;
if ( V_15 ) {
F_9 ( L_16 , V_15 ) ;
goto V_37;
}
F_31 ( V_25 ) ;
return 0 ;
V_37:
F_32 ( V_19 , & V_16 ) ;
V_30:
F_31 ( V_25 ) ;
return V_15 ;
}
static int F_33 ( struct V_22 * V_23 )
{
F_34 ( & V_36 ) ;
F_32 ( V_19 , & V_16 ) ;
return 0 ;
}
