int F_1 ( struct V_1 * V_2 , char * V_3 )
{
unsigned long V_4 ;
unsigned long V_5 ;
int V_6 ;
int V_7 ;
if ( sscanf ( V_3 , L_1 ,
& V_5 , & V_4 , & V_7 , & V_6 ) < 4 ) {
F_2 ( V_8
L_2 ) ;
return 0 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
F_3 ( & V_2 -> V_6 , V_6 ) ;
F_3 ( & V_2 -> V_7 , V_7 ) ;
return 1 ;
}
static void F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 > 0 && F_5 ( & V_2 -> V_10 ) ) {
F_2 ( V_11 L_3
L_4
L_5 , V_2 -> V_12 ,
V_2 -> V_4 , V_2 -> V_5 ,
F_6 ( & V_2 -> V_7 ) ,
F_6 ( & V_2 -> V_6 ) ) ;
if ( V_2 -> V_9 > 1 )
F_7 () ;
}
}
static bool F_8 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
return ! F_9 () && V_14 -> V_15 ;
}
static bool F_10 ( struct V_1 * V_2 )
{
struct V_16 V_17 ;
int V_18 = V_2 -> V_19 ;
unsigned long V_20 [ V_21 ] ;
int V_22 ;
bool V_23 = ( V_2 -> V_24 == 0 && V_2 -> V_25 == V_26 ) ;
if ( V_18 == 0 )
return V_23 ;
V_17 . V_27 = 0 ;
V_17 . V_20 = V_20 ;
V_17 . V_28 = V_18 ;
V_17 . V_29 = 1 ;
F_11 ( & V_17 ) ;
for ( V_22 = 0 ; V_22 < V_17 . V_27 ; V_22 ++ ) {
if ( V_2 -> V_30 <= V_20 [ V_22 ] &&
V_20 [ V_22 ] < V_2 -> V_31 )
return false ;
if ( V_2 -> V_24 <= V_20 [ V_22 ] &&
V_20 [ V_22 ] < V_2 -> V_25 )
V_23 = true ;
}
return V_23 ;
}
static inline bool F_10 ( struct V_1 * V_2 )
{
return true ;
}
bool F_12 ( struct V_1 * V_2 , T_1 V_32 )
{
if ( V_2 -> V_4 == 0 )
return false ;
if ( V_2 -> V_33 && ! F_8 ( V_2 , V_34 ) )
return false ;
if ( F_6 ( & V_2 -> V_6 ) == 0 )
return false ;
if ( F_6 ( & V_2 -> V_7 ) > V_32 ) {
F_13 ( V_32 , & V_2 -> V_7 ) ;
return false ;
}
if ( V_2 -> V_5 > 1 ) {
V_2 -> V_35 ++ ;
if ( V_2 -> V_35 % V_2 -> V_5 )
return false ;
}
if ( V_2 -> V_4 <= F_14 () % 100 )
return false ;
if ( ! F_10 ( V_2 ) )
return false ;
F_4 ( V_2 ) ;
if ( F_6 ( & V_2 -> V_6 ) != - 1 )
F_15 ( & V_2 -> V_6 ) ;
return true ;
}
static int F_16 ( void * V_36 , T_2 V_37 )
{
* ( unsigned long * ) V_36 = V_37 ;
return 0 ;
}
static int F_17 ( void * V_36 , T_2 * V_37 )
{
* V_37 = * ( unsigned long * ) V_36 ;
return 0 ;
}
static struct V_38 * F_18 ( const char * V_39 , T_3 V_40 ,
struct V_38 * V_41 , unsigned long * V_42 )
{
return F_19 ( V_39 , V_40 , V_41 , V_42 , & V_43 ) ;
}
static int F_20 ( void * V_36 , T_2 V_37 )
{
* ( unsigned long * ) V_36 =
F_21 (unsigned long, val, MAX_STACK_TRACE_DEPTH) ;
return 0 ;
}
static struct V_38 * F_22 (
const char * V_39 , T_3 V_40 ,
struct V_38 * V_41 , unsigned long * V_42 )
{
return F_19 ( V_39 , V_40 , V_41 , V_42 ,
& V_44 ) ;
}
struct V_38 * F_23 ( const char * V_39 ,
struct V_38 * V_41 , struct V_1 * V_2 )
{
T_3 V_40 = V_45 | V_46 | V_47 ;
struct V_38 * V_48 ;
V_48 = F_24 ( V_39 , V_41 ) ;
if ( ! V_48 )
return F_25 ( - V_49 ) ;
if ( ! F_18 ( L_6 , V_40 , V_48 , & V_2 -> V_4 ) )
goto V_50;
if ( ! F_18 ( L_7 , V_40 , V_48 , & V_2 -> V_5 ) )
goto V_50;
if ( ! F_26 ( L_8 , V_40 , V_48 , & V_2 -> V_6 ) )
goto V_50;
if ( ! F_26 ( L_9 , V_40 , V_48 , & V_2 -> V_7 ) )
goto V_50;
if ( ! F_18 ( L_10 , V_40 , V_48 , & V_2 -> V_9 ) )
goto V_50;
if ( ! F_27 ( L_11 , V_40 , V_48 ,
& V_2 -> V_10 . V_5 ) )
goto V_50;
if ( ! F_27 ( L_12 , V_40 , V_48 ,
& V_2 -> V_10 . V_51 ) )
goto V_50;
if ( ! F_28 ( L_13 , V_40 , V_48 , & V_2 -> V_33 ) )
goto V_50;
#ifdef F_29
if ( ! F_22 ( L_14 , V_40 , V_48 ,
& V_2 -> V_19 ) )
goto V_50;
if ( ! F_18 ( L_15 , V_40 , V_48 ,
& V_2 -> V_24 ) )
goto V_50;
if ( ! F_18 ( L_16 , V_40 , V_48 , & V_2 -> V_25 ) )
goto V_50;
if ( ! F_18 ( L_17 , V_40 , V_48 , & V_2 -> V_30 ) )
goto V_50;
if ( ! F_18 ( L_18 , V_40 , V_48 , & V_2 -> V_31 ) )
goto V_50;
#endif
V_2 -> V_12 = F_30 ( V_48 ) ;
return V_48 ;
V_50:
F_31 ( V_48 ) ;
return F_25 ( - V_49 ) ;
}
