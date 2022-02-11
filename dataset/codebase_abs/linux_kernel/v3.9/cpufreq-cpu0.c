static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static unsigned int F_3 ( unsigned int V_4 )
{
return F_4 ( V_5 ) / 1000 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_6 , unsigned int V_7 )
{
struct V_8 V_9 ;
struct V_10 * V_10 ;
unsigned long V_11 , V_12 = 0 , V_13 = 0 , V_14 = 0 ;
unsigned int V_15 , V_4 ;
int V_16 ;
V_16 = F_6 ( V_2 , V_3 , V_6 ,
V_7 , & V_15 ) ;
if ( V_16 ) {
F_7 ( L_1 ,
V_6 , V_16 ) ;
return V_16 ;
}
V_11 = F_8 ( V_5 , V_3 [ V_15 ] . V_17 * 1000 ) ;
if ( V_11 < 0 )
V_11 = V_3 [ V_15 ] . V_17 * 1000 ;
V_9 . V_18 = V_11 / 1000 ;
V_9 . V_19 = F_4 ( V_5 ) / 1000 ;
if ( V_9 . V_19 == V_9 . V_18 )
return 0 ;
F_9 (cpu) {
V_9 . V_4 = V_4 ;
F_10 ( & V_9 , V_20 ) ;
}
if ( V_21 ) {
F_11 () ;
V_10 = F_12 ( V_22 , & V_11 ) ;
if ( F_13 ( V_10 ) ) {
F_14 () ;
F_7 ( L_2 , V_11 ) ;
return F_15 ( V_10 ) ;
}
V_12 = F_16 ( V_10 ) ;
F_14 () ;
V_14 = V_12 * V_23 / 100 ;
V_13 = F_17 ( V_21 ) ;
}
F_18 ( L_3 ,
V_9 . V_19 / 1000 , V_13 ? V_13 / 1000 : - 1 ,
V_9 . V_18 / 1000 , V_12 ? V_12 / 1000 : - 1 ) ;
if ( V_21 && V_9 . V_18 > V_9 . V_19 ) {
V_16 = F_19 ( V_21 , V_12 , V_14 ) ;
if ( V_16 ) {
F_7 ( L_4 , V_16 ) ;
V_9 . V_18 = V_9 . V_19 ;
return V_16 ;
}
}
V_16 = F_20 ( V_5 , V_9 . V_18 * 1000 ) ;
if ( V_16 ) {
F_7 ( L_5 , V_16 ) ;
if ( V_21 )
F_19 ( V_21 , V_13 , V_14 ) ;
return V_16 ;
}
if ( V_21 && V_9 . V_18 < V_9 . V_19 ) {
V_16 = F_19 ( V_21 , V_12 , V_14 ) ;
if ( V_16 ) {
F_7 ( L_6 , V_16 ) ;
F_20 ( V_5 , V_9 . V_19 * 1000 ) ;
V_9 . V_18 = V_9 . V_19 ;
return V_16 ;
}
}
F_9 (cpu) {
V_9 . V_4 = V_4 ;
F_10 ( & V_9 , V_24 ) ;
}
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_16 ;
if ( V_2 -> V_4 != 0 )
return - V_25 ;
V_16 = F_22 ( V_2 , V_3 ) ;
if ( V_16 ) {
F_7 ( L_7 , V_16 ) ;
return V_16 ;
}
V_2 -> V_26 . V_27 = V_27 ;
V_2 -> V_28 = F_4 ( V_5 ) / 1000 ;
F_23 ( V_2 -> V_29 ) ;
F_24 ( V_3 , V_2 -> V_4 ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_4 ) ;
return 0 ;
}
static int F_27 ( struct V_30 * V_31 )
{
struct V_32 * V_33 , * V_34 ;
int V_16 ;
V_34 = F_28 ( L_8 ) ;
if ( ! V_34 ) {
F_7 ( L_9 ) ;
return - V_35 ;
}
F_29 (parent, np) {
if ( F_30 ( V_33 , L_10 , NULL ) )
break;
}
if ( ! V_33 ) {
F_7 ( L_11 ) ;
return - V_35 ;
}
V_22 = & V_31 -> V_36 ;
V_22 -> V_37 = V_33 ;
V_5 = F_31 ( V_22 , NULL ) ;
if ( F_13 ( V_5 ) ) {
V_16 = F_15 ( V_5 ) ;
F_7 ( L_12 , V_16 ) ;
goto V_38;
}
V_21 = F_32 ( V_22 , L_13 ) ;
if ( F_13 ( V_21 ) ) {
F_33 ( L_14 ) ;
V_21 = NULL ;
}
V_16 = F_34 ( V_22 ) ;
if ( V_16 ) {
F_7 ( L_15 , V_16 ) ;
goto V_38;
}
V_16 = F_35 ( V_22 , & V_3 ) ;
if ( V_16 ) {
F_7 ( L_16 , V_16 ) ;
goto V_38;
}
F_36 ( V_33 , L_17 , & V_23 ) ;
if ( F_36 ( V_33 , L_18 , & V_27 ) )
V_27 = V_39 ;
if ( V_21 ) {
struct V_10 * V_10 ;
unsigned long V_40 , V_41 ;
int V_42 ;
for ( V_42 = 0 ; V_3 [ V_42 ] . V_17 != V_43 ; V_42 ++ )
;
F_11 () ;
V_10 = F_37 ( V_22 ,
V_3 [ 0 ] . V_17 * 1000 , true ) ;
V_40 = F_16 ( V_10 ) ;
V_10 = F_37 ( V_22 ,
V_3 [ V_42 - 1 ] . V_17 * 1000 , true ) ;
V_41 = F_16 ( V_10 ) ;
F_14 () ;
V_16 = F_38 ( V_21 , V_40 , V_41 ) ;
if ( V_16 > 0 )
V_27 += V_16 * 1000 ;
}
V_16 = F_39 ( & V_44 ) ;
if ( V_16 ) {
F_7 ( L_19 , V_16 ) ;
goto V_45;
}
F_40 ( V_33 ) ;
return 0 ;
V_45:
F_41 ( V_22 , & V_3 ) ;
V_38:
F_40 ( V_33 ) ;
return V_16 ;
}
static int F_42 ( struct V_30 * V_31 )
{
F_43 ( & V_44 ) ;
F_41 ( V_22 , & V_3 ) ;
return 0 ;
}
