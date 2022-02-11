static int F_1 ( struct V_1 * V_2 )
{
unsigned long long V_3 = F_2 () ;
F_3 ( & V_4 ) ;
V_2 -> V_5 [ V_2 -> V_6 ] += V_3 - V_2 -> V_7 ;
V_2 -> V_7 = V_3 ;
F_4 ( & V_4 ) ;
return 0 ;
}
static T_1 F_5 ( struct V_8 * V_9 , char * V_10 )
{
return sprintf ( V_10 , L_1 , V_9 -> V_2 -> V_11 ) ;
}
static T_1 F_6 ( struct V_8 * V_9 , char * V_10 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 V_12 = 0 ;
int V_13 ;
F_1 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 ; V_13 ++ ) {
V_12 += sprintf ( V_10 + V_12 , L_2 , V_2 -> V_15 [ V_13 ] ,
( unsigned long long )
F_7 ( V_2 -> V_5 [ V_13 ] ) ) ;
}
return V_12 ;
}
static T_1 F_8 ( struct V_8 * V_9 , char * V_10 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 V_12 = 0 ;
int V_13 , V_16 ;
V_12 += snprintf ( V_10 + V_12 , V_17 - V_12 , L_3 ) ;
V_12 += snprintf ( V_10 + V_12 , V_17 - V_12 , L_4 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 ; V_13 ++ ) {
if ( V_12 >= V_17 )
break;
V_12 += snprintf ( V_10 + V_12 , V_17 - V_12 , L_5 ,
V_2 -> V_15 [ V_13 ] ) ;
}
if ( V_12 >= V_17 )
return V_17 ;
V_12 += snprintf ( V_10 + V_12 , V_17 - V_12 , L_6 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_14 ; V_13 ++ ) {
if ( V_12 >= V_17 )
break;
V_12 += snprintf ( V_10 + V_12 , V_17 - V_12 , L_7 ,
V_2 -> V_15 [ V_13 ] ) ;
for ( V_16 = 0 ; V_16 < V_2 -> V_14 ; V_16 ++ ) {
if ( V_12 >= V_17 )
break;
V_12 += snprintf ( V_10 + V_12 , V_17 - V_12 , L_5 ,
V_2 -> V_18 [ V_13 * V_2 -> V_19 + V_16 ] ) ;
}
if ( V_12 >= V_17 )
break;
V_12 += snprintf ( V_10 + V_12 , V_17 - V_12 , L_6 ) ;
}
if ( V_12 >= V_17 )
return V_17 ;
return V_12 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_20 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 ; V_21 ++ )
if ( V_2 -> V_15 [ V_21 ] == V_20 )
return V_21 ;
return - 1 ;
}
static void F_10 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
if ( ! V_2 )
return;
F_11 ( L_8 , V_22 ) ;
F_12 ( & V_9 -> V_23 , & V_24 ) ;
F_13 ( V_2 -> V_5 ) ;
F_13 ( V_2 ) ;
V_9 -> V_2 = NULL ;
}
static void F_14 ( unsigned int V_25 )
{
struct V_8 * V_9 ;
V_9 = F_15 ( V_25 ) ;
if ( ! V_9 )
return;
F_10 ( V_9 ) ;
F_16 ( V_9 ) ;
}
static int F_17 ( struct V_8 * V_9 )
{
unsigned int V_13 = 0 , V_26 = 0 , V_27 = - V_28 ;
struct V_1 * V_2 ;
unsigned int V_29 ;
unsigned int V_25 = V_9 -> V_25 ;
struct V_30 * V_31 , * V_32 ;
V_32 = F_18 ( V_25 ) ;
if ( F_19 ( ! V_32 ) )
return 0 ;
if ( V_9 -> V_2 )
return - V_33 ;
V_2 = F_20 ( sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 )
return - V_28 ;
F_21 (pos, table)
V_26 ++ ;
V_29 = V_26 * sizeof( int ) + V_26 * sizeof( V_35 ) ;
#ifdef F_22
V_29 += V_26 * V_26 * sizeof( int ) ;
#endif
V_2 -> V_5 = F_20 ( V_29 , V_34 ) ;
if ( ! V_2 -> V_5 )
goto V_36;
V_2 -> V_15 = ( unsigned int * ) ( V_2 -> V_5 + V_26 ) ;
#ifdef F_22
V_2 -> V_18 = V_2 -> V_15 + V_26 ;
#endif
V_2 -> V_19 = V_26 ;
F_21 (pos, table)
if ( F_9 ( V_2 , V_31 -> V_37 ) == - 1 )
V_2 -> V_15 [ V_13 ++ ] = V_31 -> V_37 ;
V_2 -> V_14 = V_13 ;
V_2 -> V_7 = F_2 () ;
V_2 -> V_6 = F_9 ( V_2 , V_9 -> V_38 ) ;
V_9 -> V_2 = V_2 ;
V_27 = F_23 ( & V_9 -> V_23 , & V_24 ) ;
if ( ! V_27 )
return 0 ;
V_9 -> V_2 = NULL ;
F_13 ( V_2 -> V_5 ) ;
V_36:
F_13 ( V_2 ) ;
return V_27 ;
}
static void F_24 ( unsigned int V_25 )
{
struct V_8 * V_9 ;
V_9 = F_15 ( V_25 ) ;
if ( F_25 ( ! V_9 ) )
return;
F_17 ( V_9 ) ;
F_16 ( V_9 ) ;
}
static int F_26 ( struct V_39 * V_40 ,
unsigned long V_41 , void * V_42 )
{
int V_27 = 0 ;
struct V_8 * V_9 = V_42 ;
if ( V_41 == V_43 )
V_27 = F_17 ( V_9 ) ;
else if ( V_41 == V_44 )
F_10 ( V_9 ) ;
return V_27 ;
}
static int F_27 ( struct V_39 * V_40 ,
unsigned long V_41 , void * V_42 )
{
struct V_45 * V_20 = V_42 ;
struct V_8 * V_9 = F_15 ( V_20 -> V_25 ) ;
struct V_1 * V_2 ;
int V_46 , V_47 ;
if ( ! V_9 ) {
F_28 ( L_9 , V_22 ) ;
return 0 ;
}
if ( V_41 != V_48 )
goto V_49;
if ( ! V_9 -> V_2 ) {
F_11 ( L_10 , V_22 ) ;
goto V_49;
}
V_2 = V_9 -> V_2 ;
V_46 = V_2 -> V_6 ;
V_47 = F_9 ( V_2 , V_20 -> V_50 ) ;
if ( V_46 == - 1 || V_47 == - 1 )
goto V_49;
if ( V_46 == V_47 )
goto V_49;
F_1 ( V_2 ) ;
V_2 -> V_6 = V_47 ;
#ifdef F_22
V_2 -> V_18 [ V_46 * V_2 -> V_19 + V_47 ] ++ ;
#endif
V_2 -> V_11 ++ ;
V_49:
F_16 ( V_9 ) ;
return 0 ;
}
static int T_2 F_29 ( void )
{
int V_27 ;
unsigned int V_25 ;
F_30 ( & V_4 ) ;
V_27 = F_31 ( & V_51 ,
V_52 ) ;
if ( V_27 )
return V_27 ;
F_32 (cpu)
F_24 ( V_25 ) ;
V_27 = F_31 ( & V_53 ,
V_54 ) ;
if ( V_27 ) {
F_33 ( & V_51 ,
V_52 ) ;
F_32 (cpu)
F_14 ( V_25 ) ;
return V_27 ;
}
return 0 ;
}
static void T_3 F_34 ( void )
{
unsigned int V_25 ;
F_33 ( & V_51 ,
V_52 ) ;
F_33 ( & V_53 ,
V_54 ) ;
F_32 (cpu)
F_14 ( V_25 ) ;
}
