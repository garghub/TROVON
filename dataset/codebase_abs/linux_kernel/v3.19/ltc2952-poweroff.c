static enum V_1 F_1 ( struct V_2 * V_3 )
{
T_1 V_4 ;
int V_5 ;
unsigned long V_6 ;
if ( V_7 )
return V_8 ;
V_5 = F_2 ( V_9 -> V_10 [ V_11 ] ) ;
F_3 ( V_9 -> V_10 [ V_11 ] , ! V_5 ) ;
V_4 = F_4 ( V_3 ) ;
V_6 = F_5 ( V_3 , V_4 , V_9 -> V_12 ) ;
return V_13 ;
}
static enum V_1 F_6 (
struct V_2 * V_3 )
{
int V_14 ;
V_14 = F_7 ( & V_9 -> V_15 ,
V_9 -> V_12 , V_16 ) ;
if ( V_14 ) {
F_8 ( V_9 -> V_17 , L_1 ) ;
}
F_9 ( V_9 -> V_17 , L_2 ) ;
F_10 ( true ) ;
return V_8 ;
}
static T_2 F_11 ( int V_18 , void * V_19 )
{
int V_14 ;
struct V_20 * V_21 = V_19 ;
if ( V_7 )
goto V_22;
if ( F_12 ( & V_21 -> V_15 ) ) {
goto V_22;
}
if ( ! F_12 ( & V_21 -> V_23 ) ) {
V_14 = F_7 ( & V_21 -> V_23 , V_21 -> V_24 ,
V_16 ) ;
if ( V_14 )
F_8 ( V_21 -> V_17 , L_3 ) ;
} else {
V_14 = F_13 ( & V_21 -> V_23 ) ;
}
V_22:
return V_25 ;
}
static void F_14 ( void )
{
F_3 ( V_9 -> V_10 [ V_26 ] , 1 ) ;
}
static int F_15 ( struct V_27 * V_28 ,
T_3 V_5 )
{
return - V_29 ;
}
static int F_16 ( struct V_27 * V_28 )
{
return - V_29 ;
}
static void F_17 ( struct V_20 * V_21 )
{
unsigned int V_30 ;
for ( V_30 = 0 ; V_30 < F_18 ( V_21 -> V_10 ) ; V_30 ++ )
V_21 -> V_10 [ V_30 ] = NULL ;
V_21 -> V_12 = F_19 ( 0 , 300L * 1E6L ) ;
V_21 -> V_24 = F_19 ( 2 , 500L * 1E6L ) ;
F_20 ( & V_21 -> V_23 , V_31 , V_16 ) ;
V_21 -> V_23 . V_32 = & F_6 ;
F_20 ( & V_21 -> V_15 , V_31 , V_16 ) ;
V_21 -> V_15 . V_32 = & F_1 ;
}
static int F_21 ( struct V_27 * V_28 )
{
int V_14 , V_33 ;
unsigned int V_30 ;
struct V_20 * V_21 ;
static char * V_34 [] = {
L_4 ,
L_5 ,
L_6 ,
NULL
} ;
V_21 = V_9 ;
F_17 ( V_9 ) ;
for ( V_30 = 0 ; V_30 < F_18 ( V_9 -> V_10 ) ; V_30 ++ ) {
V_9 -> V_10 [ V_30 ] = F_22 ( & V_28 -> V_17 , V_34 [ V_30 ] ) ;
if ( F_23 ( V_9 -> V_10 [ V_30 ] ) ) {
V_14 = F_24 ( V_9 -> V_10 [ V_30 ] ) ;
F_8 ( & V_28 -> V_17 ,
L_7 ,
V_34 [ V_30 ] ) ;
goto V_35;
}
}
V_14 = F_25 (
V_9 -> V_10 [ V_11 ] , 0 ) ;
if ( V_14 ) {
F_8 ( & V_28 -> V_17 , L_8 ) ;
goto V_35;
}
V_14 = F_25 ( V_9 -> V_10 [ V_26 ] , 0 ) ;
if ( V_14 ) {
F_8 ( & V_28 -> V_17 , L_9 ) ;
goto V_35;
}
V_33 = F_26 ( V_9 -> V_10 [ V_36 ] ) ;
if ( V_33 < 0 ) {
F_8 ( & V_28 -> V_17 , L_10 ) ;
goto V_35;
}
V_9 -> V_33 = V_33 ;
V_14 = F_27 ( V_33 ,
F_11 ,
( V_37 | V_38 ) ,
L_11 ,
V_9
) ;
if ( V_14 ) {
F_8 ( & V_28 -> V_17 , L_12 ) ;
goto V_35;
}
return 0 ;
V_35:
for ( V_30 = 0 ; V_30 < F_18 ( V_9 -> V_10 ) ; V_30 ++ )
if ( V_9 -> V_10 [ V_30 ] )
F_28 ( V_9 -> V_10 [ V_30 ] ) ;
return V_14 ;
}
static int F_29 ( struct V_27 * V_28 )
{
int V_14 ;
if ( V_39 ) {
F_8 ( & V_28 -> V_17 , L_13 ) ;
return - V_40 ;
}
V_9 = F_30 ( sizeof( * V_9 ) , V_41 ) ;
if ( ! V_9 )
return - V_42 ;
V_9 -> V_17 = & V_28 -> V_17 ;
V_14 = F_21 ( V_28 ) ;
if ( V_14 )
goto V_43;
V_39 = & F_14 ;
F_9 ( & V_28 -> V_17 , L_14 ) ;
return 0 ;
V_43:
F_31 ( V_9 ) ;
return V_14 ;
}
static int F_32 ( struct V_27 * V_28 )
{
unsigned int V_30 ;
V_39 = NULL ;
if ( V_9 ) {
F_33 ( V_9 -> V_33 , V_9 ) ;
for ( V_30 = 0 ; V_30 < F_18 ( V_9 -> V_10 ) ; V_30 ++ )
F_28 ( V_9 -> V_10 [ V_30 ] ) ;
F_31 ( V_9 ) ;
}
return 0 ;
}
static int F_34 ( struct V_44 * V_45 ,
unsigned long V_46 , void * V_47 )
{
V_7 = 1 ;
return V_48 ;
}
static int T_4 F_35 ( void )
{
V_7 = 0 ;
F_36 ( & V_49 ,
& V_50 ) ;
return F_37 ( & V_51 ) ;
}
static void T_5 F_38 ( void )
{
F_39 ( & V_49 ,
& V_50 ) ;
F_40 ( & V_51 ) ;
}
