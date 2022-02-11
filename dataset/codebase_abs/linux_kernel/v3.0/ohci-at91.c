static void F_1 ( void )
{
if ( F_2 () || F_3 () )
F_4 ( V_1 ) ;
F_4 ( V_2 ) ;
F_4 ( V_3 ) ;
V_4 = 1 ;
}
static void F_5 ( void )
{
F_6 ( V_3 ) ;
F_6 ( V_2 ) ;
if ( F_2 () || F_3 () )
F_6 ( V_1 ) ;
V_4 = 0 ;
}
static void F_7 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_8 ( V_6 ) ;
struct V_9 T_1 * V_10 = V_8 -> V_10 ;
F_9 ( & V_6 -> V_11 , L_1 ) ;
F_1 () ;
F_10 ( 0 , & V_10 -> V_12 ) ;
}
static void F_11 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_8 ( V_6 ) ;
struct V_9 T_1 * V_10 = V_8 -> V_10 ;
F_9 ( & V_6 -> V_11 , L_2 ) ;
F_10 ( 0 , & V_10 -> V_12 ) ;
F_5 () ;
}
static int F_12 ( const struct V_13 * V_14 ,
struct V_5 * V_6 )
{
int V_15 ;
struct V_7 * V_8 = NULL ;
if ( V_6 -> V_16 != 2 ) {
F_13 ( L_3 ) ;
return - V_17 ;
}
if ( ( V_6 -> V_18 [ 0 ] . V_19 != V_20 )
|| ( V_6 -> V_18 [ 1 ] . V_19 != V_21 ) ) {
F_13 ( L_4 ) ;
return - V_17 ;
}
V_8 = F_14 ( V_14 , & V_6 -> V_11 , L_5 ) ;
if ( ! V_8 )
return - V_22 ;
V_8 -> V_23 = V_6 -> V_18 [ 0 ] . V_24 ;
V_8 -> V_25 = V_6 -> V_18 [ 0 ] . V_26 - V_6 -> V_18 [ 0 ] . V_24 + 1 ;
if ( ! F_15 ( V_8 -> V_23 , V_8 -> V_25 , V_27 ) ) {
F_13 ( L_6 ) ;
V_15 = - V_28 ;
goto V_29;
}
V_8 -> V_10 = F_16 ( V_8 -> V_23 , V_8 -> V_25 ) ;
if ( ! V_8 -> V_10 ) {
F_13 ( L_7 ) ;
V_15 = - V_30 ;
goto V_31;
}
V_2 = F_17 ( & V_6 -> V_11 , L_8 ) ;
V_3 = F_17 ( & V_6 -> V_11 , L_9 ) ;
if ( F_2 () || F_3 () )
V_1 = F_17 ( & V_6 -> V_11 , L_10 ) ;
F_7 ( V_6 ) ;
F_18 ( F_19 ( V_8 ) ) ;
V_15 = F_20 ( V_8 , V_6 -> V_18 [ 1 ] . V_24 , V_32 ) ;
if ( V_15 == 0 )
return V_15 ;
F_11 ( V_6 ) ;
if ( F_2 () || F_3 () )
F_21 ( V_1 ) ;
F_21 ( V_3 ) ;
F_21 ( V_2 ) ;
F_22 ( V_8 -> V_10 ) ;
V_31:
F_23 ( V_8 -> V_23 , V_8 -> V_25 ) ;
V_29:
F_24 ( V_8 ) ;
return V_15 ;
}
static void F_25 ( struct V_7 * V_8 ,
struct V_5 * V_6 )
{
F_26 ( V_8 ) ;
F_11 ( V_6 ) ;
F_22 ( V_8 -> V_10 ) ;
F_23 ( V_8 -> V_23 , V_8 -> V_25 ) ;
F_24 ( V_8 ) ;
if ( F_2 () || F_3 () )
F_21 ( V_1 ) ;
F_21 ( V_3 ) ;
F_21 ( V_2 ) ;
V_3 = V_2 = V_1 = NULL ;
F_27 ( & V_6 -> V_11 , NULL ) ;
}
static int T_2
F_28 ( struct V_7 * V_8 )
{
struct V_33 * V_34 = V_8 -> V_35 . V_36 -> V_37 ;
struct V_38 * V_39 = F_19 ( V_8 ) ;
int V_40 ;
if ( ( V_40 = F_29 ( V_39 ) ) < 0 )
return V_40 ;
V_39 -> V_41 = V_34 -> V_42 ;
if ( ( V_40 = F_30 ( V_39 ) ) < 0 ) {
F_31 ( L_11 , V_8 -> V_35 . V_43 ) ;
F_32 ( V_8 ) ;
return V_40 ;
}
return 0 ;
}
static int F_33 ( struct V_5 * V_6 )
{
struct V_33 * V_44 = V_6 -> V_11 . V_37 ;
int V_45 ;
if ( V_44 ) {
for ( V_45 = 0 ; V_45 < F_34 ( V_44 -> V_46 ) ; V_45 ++ ) {
if ( V_44 -> V_46 [ V_45 ] <= 0 )
continue;
F_35 ( V_44 -> V_46 [ V_45 ] , L_12 ) ;
F_36 ( V_44 -> V_46 [ V_45 ] , 0 ) ;
}
}
F_37 ( & V_6 -> V_11 , 1 ) ;
return F_12 ( & V_47 , V_6 ) ;
}
static int F_38 ( struct V_5 * V_6 )
{
struct V_33 * V_44 = V_6 -> V_11 . V_37 ;
int V_45 ;
if ( V_44 ) {
for ( V_45 = 0 ; V_45 < F_34 ( V_44 -> V_46 ) ; V_45 ++ ) {
if ( V_44 -> V_46 [ V_45 ] <= 0 )
continue;
F_36 ( V_44 -> V_46 [ V_45 ] , 1 ) ;
F_39 ( V_44 -> V_46 [ V_45 ] ) ;
}
}
F_37 ( & V_6 -> V_11 , 0 ) ;
F_25 ( F_8 ( V_6 ) , V_6 ) ;
return 0 ;
}
static int
F_40 ( struct V_5 * V_6 , T_3 V_48 )
{
struct V_7 * V_8 = F_8 ( V_6 ) ;
struct V_38 * V_39 = F_19 ( V_8 ) ;
if ( F_41 ( & V_6 -> V_11 ) )
F_42 ( V_8 -> V_49 ) ;
if ( F_43 () ) {
F_44 ( V_39 ) ;
( void ) F_45 ( V_39 , & V_39 -> V_10 -> V_12 ) ;
F_5 () ;
}
return 0 ;
}
static int F_46 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_8 ( V_6 ) ;
if ( F_41 ( & V_6 -> V_11 ) )
F_47 ( V_8 -> V_49 ) ;
if ( ! V_4 )
F_1 () ;
F_48 ( V_8 ) ;
return 0 ;
}
