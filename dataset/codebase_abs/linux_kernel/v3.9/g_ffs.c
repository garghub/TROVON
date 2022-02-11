static int T_1 F_1 ( void )
{
int V_1 ;
F_2 () ;
if ( ! V_2 ) {
V_3 = true ;
V_2 = 1 ;
}
V_4 = F_3 ( V_2 , sizeof *V_4 , V_5 ) ;
if ( ! V_4 )
return - V_6 ;
if ( ! V_3 )
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
V_4 [ V_1 ] . V_7 = V_8 [ V_1 ] ;
V_9 = V_2 ;
return F_4 () ;
}
static void T_2 F_5 ( void )
{
F_2 () ;
F_6 ( & V_10 ) ;
if ( V_11 )
F_7 ( & V_12 ) ;
V_11 = false ;
F_8 () ;
F_9 ( & V_10 ) ;
F_10 ( V_4 ) ;
}
static struct V_13 * F_11 ( const char * V_14 )
{
int V_1 ;
F_2 () ;
if ( V_3 )
return & V_4 [ 0 ] ;
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
if ( strcmp ( V_4 [ V_1 ] . V_7 , V_14 ) == 0 )
return & V_4 [ V_1 ] ;
return NULL ;
}
static int F_12 ( struct V_15 * V_16 )
{
struct V_13 * V_17 ;
int V_18 ;
F_2 () ;
F_6 ( & V_10 ) ;
V_17 = V_16 -> V_19 ;
if ( ! V_17 ) {
V_18 = - V_20 ;
goto V_21;
}
if ( F_13 ( V_17 -> V_22 ) ) {
V_18 = - V_23 ;
goto V_21;
}
V_17 -> V_22 = true ;
V_17 -> V_15 = V_16 ;
if ( -- V_9 ) {
V_18 = 0 ;
goto V_21;
}
if ( V_11 ) {
V_18 = - V_23 ;
goto V_21;
}
V_11 = true ;
V_18 = F_14 ( & V_12 ) ;
if ( F_15 ( V_18 < 0 ) )
V_11 = false ;
V_21:
F_9 ( & V_10 ) ;
return V_18 ;
}
static void F_16 ( struct V_15 * V_16 )
{
struct V_13 * V_17 ;
F_2 () ;
F_6 ( & V_10 ) ;
V_17 = V_16 -> V_19 ;
if ( ! V_17 )
goto V_21;
V_17 -> V_22 = false ;
V_9 ++ ;
if ( V_11 )
F_7 ( & V_12 ) ;
V_11 = false ;
V_21:
F_9 ( & V_10 ) ;
}
static void * F_17 ( const char * V_14 )
{
struct V_13 * V_24 ;
F_2 () ;
F_6 ( & V_10 ) ;
V_24 = F_11 ( V_14 ) ;
if ( ! V_24 ) {
V_24 = F_18 ( - V_25 ) ;
goto V_21;
}
if ( V_24 -> V_26 ) {
V_24 = F_18 ( - V_23 ) ;
goto V_21;
}
V_24 -> V_26 = true ;
V_21:
F_9 ( & V_10 ) ;
return V_24 ;
}
static void F_19 ( struct V_15 * V_15 )
{
struct V_13 * V_24 ;
F_2 () ;
F_6 ( & V_10 ) ;
V_24 = V_15 -> V_19 ;
if ( V_24 )
V_24 -> V_26 = false ;
F_9 ( & V_10 ) ;
}
static int F_20 ( struct V_27 * V_28 )
{
int V_18 , V_1 ;
F_2 () ;
if ( V_9 )
return - V_25 ;
V_18 = F_21 ( V_28 -> V_29 , V_30 ) ;
if ( F_15 ( V_18 < 0 ) )
goto V_31;
V_32 = true ;
V_18 = F_22 ( V_28 , V_33 ) ;
if ( F_15 ( V_18 < 0 ) )
goto error;
V_34 . V_35 = V_33 [ V_36 ] . V_37 ;
for ( V_1 = V_2 ; V_1 -- ; ) {
V_18 = F_23 ( V_4 [ V_1 ] . V_15 , V_28 ) ;
if ( F_15 ( V_18 < 0 ) ) {
while ( ++ V_1 < V_2 )
F_24 ( V_4 [ V_1 ] . V_15 ) ;
goto error;
}
}
for ( V_1 = 0 ; V_1 < F_25 ( V_38 ) ; ++ V_1 ) {
struct V_39 * V_40 = V_38 + V_1 ;
int V_41 = V_42 + V_1 ;
V_40 -> V_40 . V_43 = V_33 [ V_41 ] . V_44 ;
V_40 -> V_40 . V_45 = V_33 [ V_41 ] . V_37 ;
V_40 -> V_40 . V_46 = 1 + V_1 ;
V_40 -> V_40 . V_47 = V_48 ;
V_18 = F_26 ( V_28 , & V_40 -> V_40 , V_49 ) ;
if ( F_15 ( V_18 < 0 ) )
goto V_50;
}
F_27 ( V_28 , & V_51 ) ;
return 0 ;
V_50:
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ )
F_24 ( V_4 [ V_1 ] . V_15 ) ;
error:
F_28 () ;
V_31:
V_32 = false ;
return V_18 ;
}
static int F_29 ( struct V_27 * V_28 )
{
int V_1 ;
F_2 () ;
if ( V_32 )
F_28 () ;
V_32 = false ;
for ( V_1 = V_2 ; V_1 -- ; )
if ( V_4 [ V_1 ] . V_15 )
F_24 ( V_4 [ V_1 ] . V_15 ) ;
return 0 ;
}
static int V_49 ( struct V_52 * V_40 )
{
struct V_39 * V_53 =
F_30 ( V_40 , struct V_39 , V_40 ) ;
int V_1 ;
int V_18 ;
if ( V_9 )
return - V_25 ;
if ( F_31 ( V_40 -> V_28 -> V_29 ) ) {
V_40 -> V_54 = V_55 ;
V_40 -> V_47 |= V_56 ;
}
if ( V_53 -> V_57 ) {
V_18 = V_53 -> V_57 ( V_40 , V_30 ) ;
if ( F_15 ( V_18 < 0 ) )
return V_18 ;
}
for ( V_1 = 0 ; V_1 < V_2 ; V_1 ++ ) {
V_18 = F_32 ( V_40 -> V_28 , V_40 , V_4 [ V_1 ] . V_15 ) ;
if ( F_15 ( V_18 < 0 ) )
return V_18 ;
}
if ( V_40 -> V_58 < F_25 ( V_40 -> V_59 ) )
V_40 -> V_59 [ V_40 -> V_58 ] = NULL ;
return 0 ;
}
static int F_33 ( struct V_52 * V_40 , T_3 V_60 [ V_61 ] )
{
return F_34 ( V_40 -> V_28 -> V_29 )
? F_35 ( V_40 , V_60 )
: F_36 ( V_40 , V_60 ) ;
}
