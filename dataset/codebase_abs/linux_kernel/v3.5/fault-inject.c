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
if ( V_2 -> V_9 > 0 )
F_2 ( V_10 L_3 ) ;
if ( V_2 -> V_9 > 1 )
F_5 () ;
}
static bool F_6 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
return ! F_7 () && V_12 -> V_13 ;
}
static bool F_8 ( struct V_1 * V_2 )
{
struct V_14 V_15 ;
int V_16 = V_2 -> V_17 ;
unsigned long V_18 [ V_19 ] ;
int V_20 ;
bool V_21 = ( V_2 -> V_22 == 0 && V_2 -> V_23 == V_24 ) ;
if ( V_16 == 0 )
return V_21 ;
V_15 . V_25 = 0 ;
V_15 . V_18 = V_18 ;
V_15 . V_26 = V_16 ;
V_15 . V_27 = 1 ;
F_9 ( & V_15 ) ;
for ( V_20 = 0 ; V_20 < V_15 . V_25 ; V_20 ++ ) {
if ( V_2 -> V_28 <= V_18 [ V_20 ] &&
V_18 [ V_20 ] < V_2 -> V_29 )
return false ;
if ( V_2 -> V_22 <= V_18 [ V_20 ] &&
V_18 [ V_20 ] < V_2 -> V_23 )
V_21 = true ;
}
return V_21 ;
}
static inline bool F_8 ( struct V_1 * V_2 )
{
return true ;
}
bool F_10 ( struct V_1 * V_2 , T_1 V_30 )
{
if ( V_2 -> V_4 == 0 )
return false ;
if ( V_2 -> V_31 && ! F_6 ( V_2 , V_32 ) )
return false ;
if ( F_11 ( & V_2 -> V_6 ) == 0 )
return false ;
if ( F_11 ( & V_2 -> V_7 ) > V_30 ) {
F_12 ( V_30 , & V_2 -> V_7 ) ;
return false ;
}
if ( V_2 -> V_5 > 1 ) {
V_2 -> V_33 ++ ;
if ( V_2 -> V_33 % V_2 -> V_5 )
return false ;
}
if ( V_2 -> V_4 <= F_13 () % 100 )
return false ;
if ( ! F_8 ( V_2 ) )
return false ;
F_4 ( V_2 ) ;
if ( F_11 ( & V_2 -> V_6 ) != - 1 )
F_14 ( & V_2 -> V_6 ) ;
return true ;
}
static int F_15 ( void * V_34 , T_2 V_35 )
{
* ( unsigned long * ) V_34 = V_35 ;
return 0 ;
}
static int F_16 ( void * V_34 , T_2 * V_35 )
{
* V_35 = * ( unsigned long * ) V_34 ;
return 0 ;
}
static struct V_36 * F_17 ( const char * V_37 , T_3 V_38 ,
struct V_36 * V_39 , unsigned long * V_40 )
{
return F_18 ( V_37 , V_38 , V_39 , V_40 , & V_41 ) ;
}
static int F_19 ( void * V_34 , T_2 V_35 )
{
* ( unsigned long * ) V_34 =
F_20 (unsigned long, val, MAX_STACK_TRACE_DEPTH) ;
return 0 ;
}
static struct V_36 * F_21 (
const char * V_37 , T_3 V_38 ,
struct V_36 * V_39 , unsigned long * V_40 )
{
return F_18 ( V_37 , V_38 , V_39 , V_40 ,
& V_42 ) ;
}
static int F_22 ( void * V_34 , T_2 V_35 )
{
F_3 ( ( V_43 * ) V_34 , V_35 ) ;
return 0 ;
}
static int F_23 ( void * V_34 , T_2 * V_35 )
{
* V_35 = F_11 ( ( V_43 * ) V_34 ) ;
return 0 ;
}
static struct V_36 * F_24 ( const char * V_37 , T_3 V_38 ,
struct V_36 * V_39 , V_43 * V_40 )
{
return F_18 ( V_37 , V_38 , V_39 , V_40 , & V_44 ) ;
}
struct V_36 * F_25 ( const char * V_37 ,
struct V_36 * V_39 , struct V_1 * V_2 )
{
T_3 V_38 = V_45 | V_46 | V_47 ;
struct V_36 * V_48 ;
V_48 = F_26 ( V_37 , V_39 ) ;
if ( ! V_48 )
return F_27 ( - V_49 ) ;
if ( ! F_17 ( L_4 , V_38 , V_48 , & V_2 -> V_4 ) )
goto V_50;
if ( ! F_17 ( L_5 , V_38 , V_48 , & V_2 -> V_5 ) )
goto V_50;
if ( ! F_24 ( L_6 , V_38 , V_48 , & V_2 -> V_6 ) )
goto V_50;
if ( ! F_24 ( L_7 , V_38 , V_48 , & V_2 -> V_7 ) )
goto V_50;
if ( ! F_17 ( L_8 , V_38 , V_48 , & V_2 -> V_9 ) )
goto V_50;
if ( ! F_28 ( L_9 , V_38 , V_48 , & V_2 -> V_31 ) )
goto V_50;
#ifdef F_29
if ( ! F_21 ( L_10 , V_38 , V_48 ,
& V_2 -> V_17 ) )
goto V_50;
if ( ! F_17 ( L_11 , V_38 , V_48 ,
& V_2 -> V_22 ) )
goto V_50;
if ( ! F_17 ( L_12 , V_38 , V_48 , & V_2 -> V_23 ) )
goto V_50;
if ( ! F_17 ( L_13 , V_38 , V_48 , & V_2 -> V_28 ) )
goto V_50;
if ( ! F_17 ( L_14 , V_38 , V_48 , & V_2 -> V_29 ) )
goto V_50;
#endif
return V_48 ;
V_50:
F_30 ( V_48 ) ;
return F_27 ( - V_49 ) ;
}
