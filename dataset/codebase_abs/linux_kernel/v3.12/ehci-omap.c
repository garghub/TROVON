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
struct V_8 * V_9 = F_6 ( V_7 ) ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
void T_1 * V_14 ;
int V_15 = - V_16 ;
int V_17 ;
int V_18 ;
struct V_19 * V_20 ;
if ( F_7 () )
return - V_16 ;
if ( ! V_7 -> V_21 ) {
F_8 ( V_7 , L_1 ) ;
return - V_16 ;
}
if ( V_7 -> V_22 ) {
V_9 = F_6 ( V_7 -> V_21 ) ;
V_7 -> V_23 = V_9 ;
}
if ( ! V_9 ) {
F_8 ( V_7 , L_2 ) ;
return - V_16 ;
}
V_17 = F_9 ( V_5 , 0 ) ;
if ( V_17 < 0 ) {
F_8 ( V_7 , L_3 ) ;
return - V_16 ;
}
V_11 = F_10 ( V_5 , V_24 , 0 ) ;
V_14 = F_11 ( V_7 , V_11 ) ;
if ( F_12 ( V_14 ) )
return F_13 ( V_14 ) ;
if ( ! V_7 -> V_25 )
V_7 -> V_25 = & V_7 -> V_26 ;
if ( ! V_7 -> V_26 )
V_7 -> V_26 = F_14 ( 32 ) ;
V_13 = F_15 ( & V_27 , V_7 ,
F_16 ( V_7 ) ) ;
if ( ! V_13 ) {
F_8 ( V_7 , L_4 ) ;
return - V_28 ;
}
V_13 -> V_29 = V_11 -> V_30 ;
V_13 -> V_31 = F_17 ( V_11 ) ;
V_13 -> V_14 = V_14 ;
F_18 ( V_13 ) -> V_32 = V_14 ;
V_20 = (struct V_19 * ) F_18 ( V_13 ) -> V_33 ;
V_20 -> V_34 = V_9 -> V_34 ;
F_19 ( V_5 , V_13 ) ;
for ( V_18 = 0 ; V_18 < V_20 -> V_34 ; V_18 ++ ) {
struct V_35 * V_36 ;
if ( V_7 -> V_22 )
V_36 = F_20 ( V_7 , L_5 , V_18 ) ;
else
V_36 = F_21 ( V_7 , V_18 ) ;
if ( F_12 ( V_36 ) ) {
if ( V_9 -> V_37 [ V_18 ] != V_38 )
continue;
V_15 = F_13 ( V_36 ) ;
F_8 ( V_7 , L_6 ,
V_18 , V_15 ) ;
goto V_39;
}
V_20 -> V_36 [ V_18 ] = V_36 ;
if ( V_9 -> V_37 [ V_18 ] == V_38 ) {
F_22 ( V_20 -> V_36 [ V_18 ] ) ;
F_23 ( V_20 -> V_36 [ V_18 ] , 0 ) ;
}
}
F_24 ( V_7 ) ;
F_25 ( V_7 ) ;
F_1 ( V_14 , V_40 ,
V_41 ) ;
V_15 = F_26 ( V_13 , V_17 , V_42 ) ;
if ( V_15 ) {
F_8 ( V_7 , L_7 , V_15 ) ;
goto V_43;
}
for ( V_18 = 0 ; V_18 < V_20 -> V_34 ; V_18 ++ ) {
if ( ! V_20 -> V_36 [ V_18 ] ||
V_9 -> V_37 [ V_18 ] == V_38 )
continue;
F_22 ( V_20 -> V_36 [ V_18 ] ) ;
F_23 ( V_20 -> V_36 [ V_18 ] , 0 ) ;
}
return 0 ;
V_43:
F_27 ( V_7 ) ;
V_39:
for ( V_18 = 0 ; V_18 < V_20 -> V_34 ; V_18 ++ ) {
if ( V_20 -> V_36 [ V_18 ] )
F_28 ( V_20 -> V_36 [ V_18 ] ) ;
}
F_29 ( V_13 ) ;
return V_15 ;
}
static int F_30 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_12 * V_13 = F_31 ( V_7 ) ;
struct V_19 * V_20 = (struct V_19 * ) F_18 ( V_13 ) -> V_33 ;
int V_18 ;
F_32 ( V_13 ) ;
for ( V_18 = 0 ; V_18 < V_20 -> V_34 ; V_18 ++ ) {
if ( V_20 -> V_36 [ V_18 ] )
F_28 ( V_20 -> V_36 [ V_18 ] ) ;
}
F_29 ( V_13 ) ;
F_27 ( V_7 ) ;
F_33 ( V_7 ) ;
return 0 ;
}
static int T_3 F_34 ( void )
{
if ( F_7 () )
return - V_16 ;
F_35 ( L_8 V_44 L_9 , V_45 ) ;
F_36 ( & V_27 , & V_46 ) ;
return F_37 ( & V_47 ) ;
}
static void T_4 F_38 ( void )
{
F_39 ( & V_47 ) ;
}
