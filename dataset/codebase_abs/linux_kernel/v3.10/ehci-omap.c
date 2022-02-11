static inline void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static inline T_2 F_3 ( void T_1 * V_1 , T_2 V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_8 * V_9 = V_7 -> V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
void T_1 * V_15 ;
int V_16 = - V_17 ;
int V_18 ;
int V_19 ;
struct V_20 * V_21 ;
if ( F_6 () )
return - V_17 ;
if ( ! V_7 -> V_22 ) {
F_7 ( V_7 , L_1 ) ;
return - V_17 ;
}
if ( V_7 -> V_23 ) {
V_9 = V_7 -> V_22 -> V_10 ;
V_7 -> V_10 = V_9 ;
}
if ( ! V_9 ) {
F_7 ( V_7 , L_2 ) ;
return - V_17 ;
}
V_18 = F_8 ( V_5 , 0 ) ;
if ( V_18 < 0 ) {
F_7 ( V_7 , L_3 ) ;
return - V_17 ;
}
V_12 = F_9 ( V_5 , V_24 , 0 ) ;
V_15 = F_10 ( V_7 , V_12 ) ;
if ( F_11 ( V_15 ) )
return F_12 ( V_15 ) ;
if ( ! V_7 -> V_25 )
V_7 -> V_25 = & V_7 -> V_26 ;
if ( ! V_7 -> V_26 )
V_7 -> V_26 = F_13 ( 32 ) ;
V_14 = F_14 ( & V_27 , V_7 ,
F_15 ( V_7 ) ) ;
if ( ! V_14 ) {
F_7 ( V_7 , L_4 ) ;
return - V_28 ;
}
V_14 -> V_29 = V_12 -> V_30 ;
V_14 -> V_31 = F_16 ( V_12 ) ;
V_14 -> V_15 = V_15 ;
F_17 ( V_14 ) -> V_32 = V_15 ;
V_21 = (struct V_20 * ) F_17 ( V_14 ) -> V_33 ;
V_21 -> V_34 = V_9 -> V_34 ;
F_18 ( V_5 , V_14 ) ;
for ( V_19 = 0 ; V_19 < V_21 -> V_34 ; V_19 ++ ) {
struct V_35 * V_36 ;
if ( V_7 -> V_23 )
V_36 = F_19 ( V_7 , L_5 , V_19 ) ;
else
V_36 = F_20 ( V_7 , V_19 ) ;
if ( F_11 ( V_36 ) ) {
if ( V_9 -> V_37 [ V_19 ] != V_38 )
continue;
V_16 = F_12 ( V_36 ) ;
F_7 ( V_7 , L_6 ,
V_19 , V_16 ) ;
goto V_39;
}
V_21 -> V_36 [ V_19 ] = V_36 ;
}
F_21 ( V_7 ) ;
F_22 ( V_7 ) ;
F_1 ( V_15 , V_40 ,
V_41 ) ;
V_16 = F_23 ( V_14 , V_18 , V_42 ) ;
if ( V_16 ) {
F_7 ( V_7 , L_7 , V_16 ) ;
goto V_43;
}
for ( V_19 = 0 ; V_19 < V_21 -> V_34 ; V_19 ++ ) {
if ( ! V_21 -> V_36 [ V_19 ] )
continue;
F_24 ( V_21 -> V_36 [ V_19 ] ) ;
F_25 ( V_21 -> V_36 [ V_19 ] , 0 ) ;
}
return 0 ;
V_43:
F_26 ( V_7 ) ;
V_39:
for ( V_19 = 0 ; V_19 < V_21 -> V_34 ; V_19 ++ ) {
if ( V_21 -> V_36 [ V_19 ] )
F_27 ( V_21 -> V_36 [ V_19 ] ) ;
}
F_28 ( V_14 ) ;
return V_16 ;
}
static int F_29 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_13 * V_14 = F_30 ( V_7 ) ;
struct V_20 * V_21 = (struct V_20 * ) F_17 ( V_14 ) -> V_33 ;
int V_19 ;
F_31 ( V_14 ) ;
for ( V_19 = 0 ; V_19 < V_21 -> V_34 ; V_19 ++ ) {
if ( V_21 -> V_36 [ V_19 ] )
F_27 ( V_21 -> V_36 [ V_19 ] ) ;
}
F_28 ( V_14 ) ;
F_26 ( V_7 ) ;
F_32 ( V_7 ) ;
return 0 ;
}
static void F_33 ( struct V_4 * V_5 )
{
struct V_13 * V_14 = F_30 ( & V_5 -> V_7 ) ;
if ( V_14 -> V_44 -> V_45 )
V_14 -> V_44 -> V_45 ( V_14 ) ;
}
static int T_3 F_34 ( void )
{
if ( F_6 () )
return - V_17 ;
F_35 ( L_8 V_46 L_9 , V_47 ) ;
F_36 ( & V_27 , & V_48 ) ;
return F_37 ( & V_49 ) ;
}
static void T_4 F_38 ( void )
{
F_39 ( & V_49 ) ;
}
