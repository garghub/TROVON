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
int V_15 ;
int V_16 ;
int V_17 ;
struct V_18 * V_19 ;
if ( F_7 () )
return - V_20 ;
if ( ! V_7 -> V_21 ) {
F_8 ( V_7 , L_1 ) ;
return - V_20 ;
}
if ( V_7 -> V_22 ) {
V_9 = F_6 ( V_7 -> V_21 ) ;
V_7 -> V_23 = V_9 ;
}
if ( ! V_9 ) {
F_8 ( V_7 , L_2 ) ;
return - V_20 ;
}
V_16 = F_9 ( V_5 , 0 ) ;
if ( V_16 < 0 ) {
F_8 ( V_7 , L_3 ) ;
return - V_20 ;
}
V_11 = F_10 ( V_5 , V_24 , 0 ) ;
V_14 = F_11 ( V_7 , V_11 ) ;
if ( F_12 ( V_14 ) )
return F_13 ( V_14 ) ;
V_15 = F_14 ( V_7 , F_15 ( 32 ) ) ;
if ( V_15 )
return V_15 ;
V_15 = - V_20 ;
V_13 = F_16 ( & V_25 , V_7 ,
F_17 ( V_7 ) ) ;
if ( ! V_13 ) {
F_8 ( V_7 , L_4 ) ;
return - V_26 ;
}
V_13 -> V_27 = V_11 -> V_28 ;
V_13 -> V_29 = F_18 ( V_11 ) ;
V_13 -> V_14 = V_14 ;
F_19 ( V_13 ) -> V_30 = V_14 ;
V_19 = (struct V_18 * ) F_19 ( V_13 ) -> V_31 ;
V_19 -> V_32 = V_9 -> V_32 ;
F_20 ( V_5 , V_13 ) ;
for ( V_17 = 0 ; V_17 < V_19 -> V_32 ; V_17 ++ ) {
struct V_33 * V_34 ;
if ( V_7 -> V_22 )
V_34 = F_21 ( V_7 , L_5 , V_17 ) ;
else
V_34 = F_22 ( V_7 , V_17 ) ;
if ( F_12 ( V_34 ) ) {
if ( V_9 -> V_35 [ V_17 ] != V_36 )
continue;
V_15 = F_13 ( V_34 ) ;
F_8 ( V_7 , L_6 ,
V_17 , V_15 ) ;
goto V_37;
}
V_19 -> V_34 [ V_17 ] = V_34 ;
if ( V_9 -> V_35 [ V_17 ] == V_36 ) {
F_23 ( V_19 -> V_34 [ V_17 ] ) ;
F_24 ( V_19 -> V_34 [ V_17 ] , 0 ) ;
}
}
F_25 ( V_7 ) ;
F_26 ( V_7 ) ;
F_1 ( V_14 , V_38 ,
V_39 ) ;
V_15 = F_27 ( V_13 , V_16 , V_40 ) ;
if ( V_15 ) {
F_8 ( V_7 , L_7 , V_15 ) ;
goto V_41;
}
for ( V_17 = 0 ; V_17 < V_19 -> V_32 ; V_17 ++ ) {
if ( ! V_19 -> V_34 [ V_17 ] ||
V_9 -> V_35 [ V_17 ] == V_36 )
continue;
F_23 ( V_19 -> V_34 [ V_17 ] ) ;
F_24 ( V_19 -> V_34 [ V_17 ] , 0 ) ;
}
return 0 ;
V_41:
F_28 ( V_7 ) ;
V_37:
for ( V_17 = 0 ; V_17 < V_19 -> V_32 ; V_17 ++ ) {
if ( V_19 -> V_34 [ V_17 ] )
F_29 ( V_19 -> V_34 [ V_17 ] ) ;
}
F_30 ( V_13 ) ;
return V_15 ;
}
static int F_31 ( struct V_4 * V_5 )
{
struct V_6 * V_7 = & V_5 -> V_7 ;
struct V_12 * V_13 = F_32 ( V_7 ) ;
struct V_18 * V_19 = (struct V_18 * ) F_19 ( V_13 ) -> V_31 ;
int V_17 ;
F_33 ( V_13 ) ;
for ( V_17 = 0 ; V_17 < V_19 -> V_32 ; V_17 ++ ) {
if ( V_19 -> V_34 [ V_17 ] )
F_29 ( V_19 -> V_34 [ V_17 ] ) ;
}
F_30 ( V_13 ) ;
F_28 ( V_7 ) ;
F_34 ( V_7 ) ;
return 0 ;
}
static int T_3 F_35 ( void )
{
if ( F_7 () )
return - V_20 ;
F_36 ( L_8 V_42 L_9 , V_43 ) ;
F_37 ( & V_25 , & V_44 ) ;
return F_38 ( & V_45 ) ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_45 ) ;
}
