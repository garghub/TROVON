static int F_1 ( unsigned int V_1 )
{
struct V_2 * V_3 ;
unsigned long long V_4 ;
V_4 = F_2 () ;
F_3 ( & V_5 ) ;
V_3 = F_4 ( V_6 , V_1 ) ;
if ( V_3 -> V_7 )
V_3 -> V_7 [ V_3 -> V_8 ] +=
V_4 - V_3 -> V_9 ;
V_3 -> V_9 = V_4 ;
F_5 ( & V_5 ) ;
return 0 ;
}
static T_1 F_6 ( struct V_10 * V_11 , char * V_12 )
{
struct V_2 * V_3 = F_4 ( V_6 , V_11 -> V_1 ) ;
if ( ! V_3 )
return 0 ;
return sprintf ( V_12 , L_1 ,
F_4 ( V_6 , V_3 -> V_1 ) -> V_13 ) ;
}
static T_1 F_7 ( struct V_10 * V_11 , char * V_12 )
{
T_1 V_14 = 0 ;
int V_15 ;
struct V_2 * V_3 = F_4 ( V_6 , V_11 -> V_1 ) ;
if ( ! V_3 )
return 0 ;
F_1 ( V_3 -> V_1 ) ;
for ( V_15 = 0 ; V_15 < V_3 -> V_16 ; V_15 ++ ) {
V_14 += sprintf ( V_12 + V_14 , L_2 , V_3 -> V_17 [ V_15 ] ,
( unsigned long long )
F_8 ( V_3 -> V_7 [ V_15 ] ) ) ;
}
return V_14 ;
}
static T_1 F_9 ( struct V_10 * V_11 , char * V_12 )
{
T_1 V_14 = 0 ;
int V_15 , V_18 ;
struct V_2 * V_3 = F_4 ( V_6 , V_11 -> V_1 ) ;
if ( ! V_3 )
return 0 ;
F_1 ( V_3 -> V_1 ) ;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_3 ) ;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_4 ) ;
for ( V_15 = 0 ; V_15 < V_3 -> V_16 ; V_15 ++ ) {
if ( V_14 >= V_19 )
break;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_5 ,
V_3 -> V_17 [ V_15 ] ) ;
}
if ( V_14 >= V_19 )
return V_19 ;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_6 ) ;
for ( V_15 = 0 ; V_15 < V_3 -> V_16 ; V_15 ++ ) {
if ( V_14 >= V_19 )
break;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_7 ,
V_3 -> V_17 [ V_15 ] ) ;
for ( V_18 = 0 ; V_18 < V_3 -> V_16 ; V_18 ++ ) {
if ( V_14 >= V_19 )
break;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_5 ,
V_3 -> V_20 [ V_15 * V_3 -> V_21 + V_18 ] ) ;
}
if ( V_14 >= V_19 )
break;
V_14 += snprintf ( V_12 + V_14 , V_19 - V_14 , L_6 ) ;
}
if ( V_14 >= V_19 )
return V_19 ;
return V_14 ;
}
static int F_10 ( struct V_2 * V_3 , unsigned int V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_3 -> V_21 ; V_23 ++ )
if ( V_3 -> V_17 [ V_23 ] == V_22 )
return V_23 ;
return - 1 ;
}
static void F_11 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_4 ( V_6 , V_11 -> V_1 ) ;
if ( ! V_3 )
return;
F_12 ( L_8 , V_24 ) ;
F_13 ( & V_11 -> V_25 , & V_26 ) ;
F_14 ( V_3 -> V_7 ) ;
F_14 ( V_3 ) ;
F_4 ( V_6 , V_11 -> V_1 ) = NULL ;
}
static void F_15 ( unsigned int V_1 )
{
struct V_10 * V_11 ;
V_11 = F_16 ( V_1 ) ;
if ( ! V_11 )
return;
if ( F_17 ( V_11 -> V_1 ) )
F_11 ( V_11 ) ;
F_18 ( V_11 ) ;
}
static int F_19 ( struct V_10 * V_11 )
{
unsigned int V_15 , V_27 = 0 , V_28 = 0 ;
struct V_2 * V_3 ;
unsigned int V_29 ;
unsigned int V_1 = V_11 -> V_1 ;
struct V_30 * V_31 , * V_32 ;
V_32 = F_17 ( V_1 ) ;
if ( F_20 ( ! V_32 ) )
return 0 ;
if ( F_4 ( V_6 , V_1 ) )
return - V_33 ;
V_3 = F_21 ( sizeof( * V_3 ) , V_34 ) ;
if ( ( V_3 ) == NULL )
return - V_35 ;
V_28 = F_22 ( & V_11 -> V_25 , & V_26 ) ;
if ( V_28 )
goto V_36;
V_3 -> V_1 = V_1 ;
F_4 ( V_6 , V_1 ) = V_3 ;
F_23 (pos, table)
V_27 ++ ;
V_29 = V_27 * sizeof( int ) + V_27 * sizeof( V_37 ) ;
#ifdef F_24
V_29 += V_27 * V_27 * sizeof( int ) ;
#endif
V_3 -> V_21 = V_27 ;
V_3 -> V_7 = F_21 ( V_29 , V_34 ) ;
if ( ! V_3 -> V_7 ) {
V_28 = - V_35 ;
goto V_38;
}
V_3 -> V_17 = ( unsigned int * ) ( V_3 -> V_7 + V_27 ) ;
#ifdef F_24
V_3 -> V_20 = V_3 -> V_17 + V_27 ;
#endif
V_15 = 0 ;
F_23 (pos, table)
if ( F_10 ( V_3 , V_31 -> V_39 ) == - 1 )
V_3 -> V_17 [ V_15 ++ ] = V_31 -> V_39 ;
V_3 -> V_16 = V_15 ;
F_3 ( & V_5 ) ;
V_3 -> V_9 = F_2 () ;
V_3 -> V_8 = F_10 ( V_3 , V_11 -> V_40 ) ;
F_5 ( & V_5 ) ;
return 0 ;
V_38:
F_13 ( & V_11 -> V_25 , & V_26 ) ;
V_36:
F_14 ( V_3 ) ;
F_4 ( V_6 , V_1 ) = NULL ;
return V_28 ;
}
static void F_25 ( unsigned int V_1 )
{
struct V_10 * V_11 ;
V_11 = F_16 ( V_1 ) ;
if ( F_26 ( ! V_11 ) )
return;
F_19 ( V_11 ) ;
F_18 ( V_11 ) ;
}
static void F_27 ( struct V_10 * V_11 )
{
struct V_2 * V_3 = F_4 ( V_6 ,
V_11 -> V_41 ) ;
F_12 ( L_9 ,
V_11 -> V_1 , V_11 -> V_41 ) ;
F_4 ( V_6 , V_11 -> V_1 ) = F_4 ( V_6 ,
V_11 -> V_41 ) ;
F_4 ( V_6 , V_11 -> V_41 ) = NULL ;
V_3 -> V_1 = V_11 -> V_1 ;
}
static int F_28 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_45 )
{
int V_28 = 0 ;
struct V_10 * V_11 = V_45 ;
if ( V_44 == V_46 ) {
F_27 ( V_11 ) ;
return 0 ;
}
if ( V_44 == V_47 )
V_28 = F_19 ( V_11 ) ;
else if ( V_44 == V_48 )
F_11 ( V_11 ) ;
return V_28 ;
}
static int F_29 ( struct V_42 * V_43 ,
unsigned long V_44 , void * V_45 )
{
struct V_49 * V_22 = V_45 ;
struct V_2 * V_3 ;
int V_50 , V_51 ;
if ( V_44 != V_52 )
return 0 ;
V_3 = F_4 ( V_6 , V_22 -> V_1 ) ;
if ( ! V_3 )
return 0 ;
V_50 = V_3 -> V_8 ;
V_51 = F_10 ( V_3 , V_22 -> V_53 ) ;
if ( V_50 == - 1 || V_51 == - 1 )
return 0 ;
F_1 ( V_22 -> V_1 ) ;
if ( V_50 == V_51 )
return 0 ;
F_3 ( & V_5 ) ;
V_3 -> V_8 = V_51 ;
#ifdef F_24
V_3 -> V_20 [ V_50 * V_3 -> V_21 + V_51 ] ++ ;
#endif
V_3 -> V_13 ++ ;
F_5 ( & V_5 ) ;
return 0 ;
}
static int T_2 F_30 ( void )
{
int V_28 ;
unsigned int V_1 ;
F_31 ( & V_5 ) ;
V_28 = F_32 ( & V_54 ,
V_55 ) ;
if ( V_28 )
return V_28 ;
F_33 (cpu)
F_25 ( V_1 ) ;
V_28 = F_32 ( & V_56 ,
V_57 ) ;
if ( V_28 ) {
F_34 ( & V_54 ,
V_55 ) ;
F_33 (cpu)
F_15 ( V_1 ) ;
return V_28 ;
}
return 0 ;
}
static void T_3 F_35 ( void )
{
unsigned int V_1 ;
F_34 ( & V_54 ,
V_55 ) ;
F_34 ( & V_56 ,
V_57 ) ;
F_33 (cpu)
F_15 ( V_1 ) ;
}
