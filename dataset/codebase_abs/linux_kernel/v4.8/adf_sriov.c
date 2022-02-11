static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
}
static void F_5 ( void * V_7 )
{
struct V_8 * V_6 = (struct V_8 * ) V_7 ;
struct V_3 * V_4 ;
V_4 = F_6 ( sizeof( * V_4 ) , V_9 ) ;
if ( ! V_4 )
return;
V_4 -> V_6 = V_6 ;
F_7 ( & V_4 -> V_5 , F_1 ) ;
F_8 ( V_10 , & V_4 -> V_5 ) ;
}
static int F_9 ( struct V_11 * V_12 )
{
struct V_13 * V_14 = F_10 ( V_12 ) ;
int V_15 = F_11 ( V_14 ) ;
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_19 * V_20 =
& F_12 ( V_12 ) [ V_17 -> V_21 ( V_17 ) ] ;
void T_1 * V_22 = V_20 -> V_23 ;
struct V_8 * V_6 ;
int V_24 ;
T_2 V_25 ;
for ( V_24 = 0 , V_6 = V_12 -> V_26 . V_6 ; V_24 < V_15 ;
V_24 ++ , V_6 ++ ) {
V_6 -> V_12 = V_12 ;
V_6 -> V_27 = V_24 ;
F_13 ( & V_6 -> V_28 ,
( void * ) F_5 ,
( unsigned long ) V_6 ) ;
F_14 ( & V_6 -> V_29 ) ;
F_15 ( & V_6 -> V_30 ,
V_31 ,
V_32 ) ;
}
for ( V_24 = 0 ; V_24 < V_33 ; V_24 ++ ) {
V_25 = F_16 ( V_22 , V_24 ) ;
V_25 |= V_34 ;
F_17 ( V_22 , V_24 , V_25 ) ;
}
for ( V_24 = 0 ; V_24 < V_35 ; V_24 ++ ) {
V_25 = F_18 ( V_22 , V_24 ) ;
V_25 |= V_34 ;
F_19 ( V_22 , V_24 , V_25 ) ;
}
F_20 ( V_12 , F_21 ( V_15 - 1 , 0 ) ) ;
return F_22 ( V_14 , V_15 ) ;
}
void F_23 ( struct V_11 * V_12 )
{
struct V_16 * V_17 = V_12 -> V_18 ;
struct V_19 * V_20 =
& F_12 ( V_12 ) [ V_17 -> V_21 ( V_17 ) ] ;
void T_1 * V_22 = V_20 -> V_23 ;
int V_15 = F_11 ( F_10 ( V_12 ) ) ;
struct V_8 * V_36 ;
T_2 V_25 ;
int V_24 ;
if ( ! V_12 -> V_26 . V_6 )
return;
F_24 ( V_12 ) ;
F_25 ( F_10 ( V_12 ) ) ;
F_26 ( V_12 , 0xFFFFFFFF ) ;
for ( V_24 = 0 ; V_24 < V_33 ; V_24 ++ ) {
V_25 = F_16 ( V_22 , V_24 ) ;
V_25 &= ~ V_34 ;
F_17 ( V_22 , V_24 , V_25 ) ;
}
for ( V_24 = 0 ; V_24 < V_35 ; V_24 ++ ) {
V_25 = F_18 ( V_22 , V_24 ) ;
V_25 &= ~ V_34 ;
F_19 ( V_22 , V_24 , V_25 ) ;
}
for ( V_24 = 0 , V_36 = V_12 -> V_26 . V_6 ; V_24 < V_15 ; V_24 ++ , V_36 ++ ) {
F_27 ( & V_36 -> V_28 ) ;
F_28 ( & V_36 -> V_28 ) ;
F_29 ( & V_36 -> V_29 ) ;
}
F_4 ( V_12 -> V_26 . V_6 ) ;
V_12 -> V_26 . V_6 = NULL ;
}
int F_30 ( struct V_13 * V_14 , int V_37 )
{
struct V_11 * V_12 = F_31 ( V_14 ) ;
int V_15 = F_11 ( V_14 ) ;
unsigned long V_38 ;
int V_39 ;
if ( ! V_12 ) {
F_32 ( & V_14 -> V_40 , L_1 ) ;
return - V_41 ;
}
if ( ! F_33 ( & V_42 ) )
F_34 ( & V_14 -> V_40 , L_2 ) ;
if ( V_12 -> V_26 . V_6 ) {
F_35 ( & V_14 -> V_40 , L_3 ) ;
return - V_43 ;
}
if ( F_36 ( V_12 ) ) {
if ( F_37 ( V_12 ) ||
F_38 ( V_12 ) ) {
F_32 ( & F_39 ( V_12 ) , L_4 ) ;
return - V_44 ;
}
F_40 ( V_12 ) ;
F_41 ( V_12 ) ;
}
if ( F_42 ( V_12 , V_45 ) )
return - V_41 ;
V_38 = 0 ;
if ( F_43 ( V_12 , V_45 ,
V_46 , ( void * ) & V_38 , V_47 ) )
return - V_41 ;
F_44 ( V_48 , & V_12 -> V_49 ) ;
V_12 -> V_26 . V_6 = F_45 ( V_15 ,
sizeof( struct V_8 ) ,
V_50 ) ;
if ( ! V_12 -> V_26 . V_6 )
return - V_51 ;
if ( F_46 ( V_12 ) ) {
F_32 ( & F_39 ( V_12 ) , L_5 ,
V_12 -> V_52 ) ;
return - V_41 ;
}
if ( F_47 ( V_12 ) ) {
F_32 ( & F_39 ( V_12 ) , L_6 ,
V_12 -> V_52 ) ;
return - V_41 ;
}
V_39 = F_9 ( V_12 ) ;
if ( V_39 )
return V_39 ;
return V_37 ;
}
int T_3 F_48 ( void )
{
V_10 = F_49 ( L_7 , V_53 , 0 ) ;
return ! V_10 ? - V_51 : 0 ;
}
void F_50 ( void )
{
if ( V_10 ) {
F_51 ( V_10 ) ;
V_10 = NULL ;
}
}
