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
unsigned long V_11 = 0 , V_12 = 0 , V_13 = 0 ;
long V_14 , V_15 ;
unsigned int V_16 ;
int V_17 ;
V_17 = F_6 ( V_2 , V_3 , V_6 ,
V_7 , & V_16 ) ;
if ( V_17 ) {
F_7 ( L_1 ,
V_6 , V_17 ) ;
return V_17 ;
}
V_14 = F_8 ( V_5 , V_3 [ V_16 ] . V_18 * 1000 ) ;
if ( V_14 < 0 )
V_14 = V_3 [ V_16 ] . V_18 * 1000 ;
V_15 = V_14 ;
V_9 . V_19 = V_14 / 1000 ;
V_9 . V_20 = F_4 ( V_5 ) / 1000 ;
if ( V_9 . V_20 == V_9 . V_19 )
return 0 ;
F_9 ( V_2 , & V_9 , V_21 ) ;
if ( V_22 ) {
F_10 () ;
V_10 = F_11 ( V_23 , & V_14 ) ;
if ( F_12 ( V_10 ) ) {
F_13 () ;
F_7 ( L_2 , V_14 ) ;
V_9 . V_19 = V_9 . V_20 ;
V_17 = F_14 ( V_10 ) ;
goto V_24;
}
V_11 = F_15 ( V_10 ) ;
F_13 () ;
V_13 = V_11 * V_25 / 100 ;
V_12 = F_16 ( V_22 ) ;
}
F_17 ( L_3 ,
V_9 . V_20 / 1000 , V_12 ? V_12 / 1000 : - 1 ,
V_9 . V_19 / 1000 , V_11 ? V_11 / 1000 : - 1 ) ;
if ( V_22 && V_9 . V_19 > V_9 . V_20 ) {
V_17 = F_18 ( V_22 , V_11 , V_13 ) ;
if ( V_17 ) {
F_7 ( L_4 , V_17 ) ;
V_9 . V_19 = V_9 . V_20 ;
goto V_24;
}
}
V_17 = F_19 ( V_5 , V_15 ) ;
if ( V_17 ) {
F_7 ( L_5 , V_17 ) ;
if ( V_22 )
F_18 ( V_22 , V_12 , V_13 ) ;
V_9 . V_19 = V_9 . V_20 ;
goto V_24;
}
if ( V_22 && V_9 . V_19 < V_9 . V_20 ) {
V_17 = F_18 ( V_22 , V_11 , V_13 ) ;
if ( V_17 ) {
F_7 ( L_6 , V_17 ) ;
F_19 ( V_5 , V_9 . V_20 * 1000 ) ;
V_9 . V_19 = V_9 . V_20 ;
}
}
V_24:
F_9 ( V_2 , & V_9 , V_26 ) ;
return V_17 ;
}
static int F_20 ( struct V_1 * V_2 )
{
int V_17 ;
V_17 = F_21 ( V_2 , V_3 ) ;
if ( V_17 ) {
F_7 ( L_7 , V_17 ) ;
return V_17 ;
}
V_2 -> V_27 . V_28 = V_28 ;
V_2 -> V_29 = F_4 ( V_5 ) / 1000 ;
F_22 ( V_2 -> V_30 ) ;
F_23 ( V_3 , V_2 -> V_4 ) ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_31 * V_32 )
{
struct V_33 * V_34 , * V_35 ;
int V_17 ;
V_35 = F_27 ( L_8 ) ;
if ( ! V_35 ) {
F_7 ( L_9 ) ;
return - V_36 ;
}
F_28 (parent, np) {
if ( F_29 ( V_34 , L_10 , NULL ) )
break;
}
if ( ! V_34 ) {
F_7 ( L_11 ) ;
V_17 = - V_36 ;
goto V_37;
}
V_23 = & V_32 -> V_38 ;
V_23 -> V_39 = V_34 ;
V_22 = F_30 ( V_23 , L_12 ) ;
if ( F_12 ( V_22 ) ) {
if ( F_14 ( V_22 ) == - V_40 ) {
F_31 ( V_23 , L_13 ) ;
V_17 = - V_40 ;
goto V_41;
}
F_32 ( L_14 ,
F_14 ( V_22 ) ) ;
V_22 = NULL ;
}
V_5 = F_33 ( V_23 , NULL ) ;
if ( F_12 ( V_5 ) ) {
V_17 = F_14 ( V_5 ) ;
F_7 ( L_15 , V_17 ) ;
goto V_41;
}
V_17 = F_34 ( V_23 ) ;
if ( V_17 ) {
F_7 ( L_16 , V_17 ) ;
goto V_41;
}
V_17 = F_35 ( V_23 , & V_3 ) ;
if ( V_17 ) {
F_7 ( L_17 , V_17 ) ;
goto V_41;
}
F_36 ( V_34 , L_18 , & V_25 ) ;
if ( F_36 ( V_34 , L_19 , & V_28 ) )
V_28 = V_42 ;
if ( V_22 ) {
struct V_10 * V_10 ;
unsigned long V_43 , V_44 ;
int V_45 ;
for ( V_45 = 0 ; V_3 [ V_45 ] . V_18 != V_46 ; V_45 ++ )
;
F_10 () ;
V_10 = F_37 ( V_23 ,
V_3 [ 0 ] . V_18 * 1000 , true ) ;
V_43 = F_15 ( V_10 ) ;
V_10 = F_37 ( V_23 ,
V_3 [ V_45 - 1 ] . V_18 * 1000 , true ) ;
V_44 = F_15 ( V_10 ) ;
F_13 () ;
V_17 = F_38 ( V_22 , V_43 , V_44 ) ;
if ( V_17 > 0 )
V_28 += V_17 * 1000 ;
}
V_17 = F_39 ( & V_47 ) ;
if ( V_17 ) {
F_7 ( L_20 , V_17 ) ;
goto V_48;
}
F_40 ( V_34 ) ;
F_40 ( V_35 ) ;
return 0 ;
V_48:
F_41 ( V_23 , & V_3 ) ;
V_41:
F_40 ( V_34 ) ;
V_37:
F_40 ( V_35 ) ;
return V_17 ;
}
static int F_42 ( struct V_31 * V_32 )
{
F_43 ( & V_47 ) ;
F_41 ( V_23 , & V_3 ) ;
return 0 ;
}
