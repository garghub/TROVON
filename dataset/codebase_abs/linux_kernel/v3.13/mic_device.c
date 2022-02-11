static void F_1 ( T_1 V_1 )
{
struct V_2 * V_3 = V_4 ;
struct V_5 T_2 * V_6 = V_3 -> V_7 ;
F_2 ( V_1 , & V_6 -> V_8 ) ;
F_3 ( V_3 -> V_9 , L_1 ,
V_10 , __LINE__ , V_1 ) ;
F_4 ( & V_3 -> V_11 , F_5 ( & V_6 -> V_12 ) ) ;
}
static int F_6 ( struct V_13 * V_14 , unsigned long V_15 ,
void * V_16 )
{
struct V_2 * V_3 = V_4 ;
struct V_5 T_2 * V_6 = V_3 -> V_7 ;
F_2 ( - 1 , & V_6 -> V_17 ) ;
F_2 ( - 1 , & V_6 -> V_18 ) ;
F_1 ( V_19 ) ;
return V_20 ;
}
static T_3 F_7 ( int V_21 , void * V_22 )
{
struct V_2 * V_3 = V_4 ;
struct V_5 T_2 * V_6 = V_3 -> V_7 ;
F_8 ( & V_4 -> V_11 ) ;
if ( F_5 ( & V_6 -> V_23 ) )
F_9 ( true ) ;
return V_24 ;
}
static int F_10 ( void )
{
int V_25 = 0 ;
struct V_2 * V_3 = V_4 ;
struct V_5 T_2 * V_6 = V_3 -> V_7 ;
int V_26 ;
V_26 = F_11 () ;
V_27 = F_12 ( F_7 ,
L_2 , V_3 , V_26 ) ;
if ( F_13 ( V_27 ) )
V_25 = F_14 ( V_27 ) ;
else
F_2 ( V_26 , & V_6 -> V_18 ) ;
return V_25 ;
}
static void F_15 ( void )
{
struct V_2 * V_3 = V_4 ;
struct V_5 T_2 * V_6 = V_3 -> V_7 ;
F_2 ( - 1 , & V_6 -> V_18 ) ;
F_16 ( V_27 , V_3 ) ;
}
static int T_4 F_17 ( void )
{
struct V_2 * V_3 = V_4 ;
struct V_28 * V_11 = & V_3 -> V_11 ;
struct V_5 T_2 * V_6 ;
T_5 V_29 , V_30 , V_31 ;
T_6 V_32 ;
V_29 = F_18 ( & V_3 -> V_11 , V_33 ) ;
V_30 = F_18 ( & V_3 -> V_11 , V_34 ) ;
V_31 = V_29 | ( V_30 << 32 ) ;
V_3 -> V_7 = F_19 ( V_11 , V_31 , V_35 ) ;
if ( ! V_3 -> V_7 ) {
F_20 ( V_3 -> V_9 , L_3 ) ;
return - V_36 ;
}
V_6 = V_3 -> V_7 ;
V_32 = F_21 ( & V_6 -> V_32 ) ;
if ( V_37 != V_32 ) {
F_20 ( V_3 -> V_9 , L_4 , V_32 ) ;
return - V_38 ;
}
return 0 ;
}
static void F_22 ( void )
{
F_23 ( & V_4 -> V_11 , V_4 -> V_7 ) ;
}
struct V_39 * F_12 ( T_3 (* F_24)( int V_21 , void * V_22 ) ,
const char * V_40 , void * V_22 , int V_41 )
{
int V_25 = 0 ;
unsigned long V_42 ;
struct V_2 * V_3 = V_4 ;
V_25 = F_25 ( F_26 ( V_3 , V_41 ) , F_24 ,
0 , V_40 , V_22 ) ;
if ( V_25 ) {
F_20 ( V_3 -> V_9 , L_5 , V_25 ) ;
goto V_43;
}
V_3 -> V_44 . V_45 [ V_41 ] ++ ;
V_42 = V_41 ;
return (struct V_39 * ) V_42 ;
V_43:
return F_27 ( V_25 ) ;
}
void F_16 ( struct V_39 * V_42 , void * V_22 )
{
int V_41 ;
struct V_2 * V_3 = V_4 ;
V_41 = ( unsigned long ) V_42 & 0xFFFFU ;
F_28 ( F_26 ( V_3 , V_41 ) , V_22 ) ;
V_3 -> V_44 . V_45 [ V_41 ] -- ;
}
int F_11 ( void )
{
int V_46 ;
int V_41 = 0 ;
struct V_2 * V_3 = V_4 ;
for ( V_46 = 0 ; V_46 < V_3 -> V_47 . V_48 ; V_46 ++ ) {
if ( V_3 -> V_44 . V_45 [ V_46 ] <
V_3 -> V_44 . V_45 [ V_41 ] )
V_41 = V_46 ;
}
return V_41 ;
}
static int F_29 ( void )
{
struct V_2 * V_3 = V_4 ;
V_3 -> V_44 . V_45 = F_30 ( ( sizeof( T_6 ) *
V_3 -> V_47 . V_48 ) ,
V_49 ) ;
if ( ! V_3 -> V_44 . V_45 )
return - V_36 ;
return 0 ;
}
static void F_31 ( void )
{
struct V_2 * V_3 = V_4 ;
F_32 ( V_3 -> V_44 . V_45 ) ;
}
int T_4 F_33 ( struct V_2 * V_3 )
{
int V_25 ;
V_4 = V_3 ;
if ( ! F_34 ( V_3 -> V_9 -> V_50 -> V_51 ) ) {
V_25 = - V_52 ;
goto V_53;
}
V_25 = F_17 () ;
if ( V_25 )
goto V_54;
V_25 = F_29 () ;
if ( V_25 )
goto V_55;
V_25 = F_10 () ;
if ( V_25 )
goto V_56;
V_25 = F_35 ( V_3 ) ;
if ( V_25 )
goto V_57;
F_36 ( V_3 ) ;
F_37 ( & V_58 , & V_59 ) ;
V_53:
return V_25 ;
V_57:
F_15 () ;
V_56:
F_31 () ;
V_55:
F_22 () ;
V_54:
F_38 ( V_3 -> V_9 -> V_50 -> V_51 ) ;
return V_25 ;
}
void F_39 ( struct V_2 * V_3 )
{
F_40 ( V_3 ) ;
F_41 ( V_3 ) ;
F_1 ( V_60 ) ;
F_15 () ;
F_31 () ;
F_22 () ;
F_38 ( V_3 -> V_9 -> V_50 -> V_51 ) ;
}
