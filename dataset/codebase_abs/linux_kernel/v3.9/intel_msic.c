int F_1 ( unsigned short V_1 , T_1 * V_2 )
{
return F_2 ( V_1 , V_2 ) ;
}
int F_3 ( unsigned short V_1 , T_1 V_2 )
{
return F_4 ( V_1 , V_2 ) ;
}
int F_5 ( unsigned short V_1 , T_1 V_2 , T_1 V_3 )
{
return F_6 ( V_1 , V_2 , V_3 ) ;
}
int F_7 ( unsigned short * V_1 , T_1 * V_4 , T_2 V_5 )
{
if ( F_8 ( V_5 > V_6 ) )
return - V_7 ;
return F_9 ( V_1 , V_4 , V_5 ) ;
}
int F_10 ( unsigned short * V_1 , T_1 * V_4 , T_2 V_5 )
{
if ( F_8 ( V_5 > V_6 ) )
return - V_7 ;
return F_11 ( V_1 , V_4 , V_5 ) ;
}
int F_12 ( struct V_8 * V_9 , unsigned short V_1 , T_1 * V_2 )
{
if ( F_8 ( V_1 < V_10 || V_1 > V_11 ) )
return - V_7 ;
* V_2 = F_13 ( V_9 -> V_12 + ( V_1 - V_10 ) ) ;
return 0 ;
}
static int F_14 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 . V_18 ;
int V_19 , V_20 ;
if ( V_16 -> V_21 ) {
struct V_22 * V_23 = & V_24 [ V_25 ] ;
V_23 -> V_18 = V_16 -> V_21 ;
V_23 -> V_26 = sizeof( * V_16 -> V_21 ) ;
}
if ( V_16 -> V_27 ) {
unsigned V_21 = V_16 -> V_27 -> V_21 ;
V_19 = F_15 ( V_21 , V_28 , L_1 ) ;
if ( V_19 ) {
F_16 ( & V_14 -> V_17 , L_2 ) ;
return V_19 ;
}
V_19 = F_17 ( V_21 ) ;
if ( V_19 < 0 ) {
F_16 ( & V_14 -> V_17 , L_3 ) ;
F_18 ( V_21 ) ;
return V_19 ;
}
V_16 -> V_29 [ V_30 ] = V_19 ;
}
for ( V_20 = 0 ; V_20 < F_19 ( V_24 ) ; V_20 ++ ) {
if ( ! V_16 -> V_29 [ V_20 ] )
continue;
V_19 = F_20 ( & V_14 -> V_17 , - 1 , & V_24 [ V_20 ] , 1 , NULL ,
V_16 -> V_29 [ V_20 ] , NULL ) ;
if ( V_19 )
goto V_31;
}
V_19 = F_20 ( & V_14 -> V_17 , 0 , V_32 ,
F_19 ( V_32 ) , NULL , 0 , NULL ) ;
if ( V_19 )
goto V_31;
return 0 ;
V_31:
F_21 ( & V_14 -> V_17 ) ;
if ( V_16 -> V_27 )
F_18 ( V_16 -> V_27 -> V_21 ) ;
return V_19 ;
}
static void F_22 ( struct V_8 * V_9 )
{
struct V_13 * V_14 = V_9 -> V_14 ;
struct V_15 * V_16 = V_14 -> V_17 . V_18 ;
F_21 ( & V_14 -> V_17 ) ;
if ( V_16 -> V_27 )
F_18 ( V_16 -> V_27 -> V_21 ) ;
}
static int F_23 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 . V_18 ;
struct V_8 * V_9 ;
struct V_33 * V_34 ;
T_1 V_35 , V_36 ;
int V_19 ;
if ( ! V_16 ) {
F_16 ( & V_14 -> V_17 , L_4 ) ;
return - V_7 ;
}
V_19 = F_2 ( V_37 , & V_35 ) ;
if ( V_19 ) {
F_16 ( & V_14 -> V_17 , L_5 ) ;
return - V_38 ;
}
V_19 = F_2 ( V_39 , & V_36 ) ;
if ( V_19 ) {
F_16 ( & V_14 -> V_17 , L_6 ) ;
return - V_38 ;
}
if ( F_24 ( V_35 ) != F_24 ( V_36 ) ) {
F_16 ( & V_14 -> V_17 , L_7 , V_35 , V_36 ) ;
return - V_38 ;
}
V_9 = F_25 ( & V_14 -> V_17 , sizeof( * V_9 ) , V_40 ) ;
if ( ! V_9 )
return - V_41 ;
V_9 -> V_42 = F_24 ( V_35 ) ;
V_9 -> V_43 = F_26 ( V_35 ) ;
V_9 -> V_14 = V_14 ;
V_34 = F_27 ( V_14 , V_44 , 0 ) ;
if ( ! V_34 ) {
F_16 ( & V_14 -> V_17 , L_8 ) ;
return - V_45 ;
}
V_9 -> V_12 = F_28 ( & V_14 -> V_17 , V_34 ) ;
if ( F_29 ( V_9 -> V_12 ) )
return F_30 ( V_9 -> V_12 ) ;
F_31 ( V_14 , V_9 ) ;
V_19 = F_14 ( V_9 ) ;
if ( V_19 ) {
F_16 ( & V_14 -> V_17 , L_9 ) ;
return V_19 ;
}
F_32 ( & V_14 -> V_17 , L_10 ,
F_33 ( V_9 -> V_43 ) , F_34 ( V_9 -> V_43 ) ,
V_9 -> V_42 ) ;
return 0 ;
}
static int F_35 ( struct V_13 * V_14 )
{
struct V_8 * V_9 = F_36 ( V_14 ) ;
F_22 ( V_9 ) ;
F_31 ( V_14 , NULL ) ;
return 0 ;
}
