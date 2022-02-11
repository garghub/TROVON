static int F_1 ( struct V_1 * V_2 )
{
unsigned long long V_3 = F_2 () ;
F_3 ( & V_4 ) ;
V_2 -> V_5 [ V_2 -> V_6 ] += V_3 - V_2 -> V_7 ;
V_2 -> V_7 = V_3 ;
F_4 ( & V_4 ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
unsigned int V_8 = V_2 -> V_9 ;
memset ( V_2 -> V_5 , 0 , V_8 * sizeof( V_10 ) ) ;
#ifdef F_6
memset ( V_2 -> V_11 , 0 , V_8 * V_8 * sizeof( int ) ) ;
#endif
V_2 -> V_7 = F_2 () ;
V_2 -> V_12 = 0 ;
}
static T_1 F_7 ( struct V_13 * V_14 , char * V_15 )
{
return sprintf ( V_15 , L_1 , V_14 -> V_2 -> V_12 ) ;
}
static T_1 F_8 ( struct V_13 * V_14 , char * V_15 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
T_1 V_16 = 0 ;
int V_17 ;
if ( V_14 -> V_18 )
return 0 ;
F_1 ( V_2 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_19 ; V_17 ++ ) {
V_16 += sprintf ( V_15 + V_16 , L_2 , V_2 -> V_20 [ V_17 ] ,
( unsigned long long )
F_9 ( V_2 -> V_5 [ V_17 ] ) ) ;
}
return V_16 ;
}
static T_1 F_10 ( struct V_13 * V_14 , const char * V_15 ,
T_2 V_8 )
{
F_5 ( V_14 -> V_2 ) ;
return V_8 ;
}
static T_1 F_11 ( struct V_13 * V_14 , char * V_15 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
T_1 V_16 = 0 ;
int V_17 , V_21 ;
if ( V_14 -> V_18 )
return 0 ;
V_16 += snprintf ( V_15 + V_16 , V_22 - V_16 , L_3 ) ;
V_16 += snprintf ( V_15 + V_16 , V_22 - V_16 , L_4 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_19 ; V_17 ++ ) {
if ( V_16 >= V_22 )
break;
V_16 += snprintf ( V_15 + V_16 , V_22 - V_16 , L_5 ,
V_2 -> V_20 [ V_17 ] ) ;
}
if ( V_16 >= V_22 )
return V_22 ;
V_16 += snprintf ( V_15 + V_16 , V_22 - V_16 , L_6 ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_19 ; V_17 ++ ) {
if ( V_16 >= V_22 )
break;
V_16 += snprintf ( V_15 + V_16 , V_22 - V_16 , L_7 ,
V_2 -> V_20 [ V_17 ] ) ;
for ( V_21 = 0 ; V_21 < V_2 -> V_19 ; V_21 ++ ) {
if ( V_16 >= V_22 )
break;
V_16 += snprintf ( V_15 + V_16 , V_22 - V_16 , L_5 ,
V_2 -> V_11 [ V_17 * V_2 -> V_9 + V_21 ] ) ;
}
if ( V_16 >= V_22 )
break;
V_16 += snprintf ( V_15 + V_16 , V_22 - V_16 , L_6 ) ;
}
if ( V_16 >= V_22 )
return V_22 ;
return V_16 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_9 ; V_24 ++ )
if ( V_2 -> V_20 [ V_24 ] == V_23 )
return V_24 ;
return - 1 ;
}
void F_13 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
if ( ! V_2 )
return;
F_14 ( L_8 , V_25 ) ;
F_15 ( & V_14 -> V_26 , & V_27 ) ;
F_16 ( V_2 -> V_5 ) ;
F_16 ( V_2 ) ;
V_14 -> V_2 = NULL ;
}
void F_17 ( struct V_13 * V_14 )
{
unsigned int V_17 = 0 , V_8 = 0 , V_28 = - V_29 ;
struct V_1 * V_2 ;
unsigned int V_30 ;
struct V_31 * V_32 , * V_33 ;
V_33 = V_14 -> V_20 ;
if ( F_18 ( ! V_33 ) )
return;
if ( V_14 -> V_2 )
return;
V_2 = F_19 ( sizeof( * V_2 ) , V_34 ) ;
if ( ! V_2 )
return;
F_20 (pos, table)
V_8 ++ ;
V_30 = V_8 * sizeof( int ) + V_8 * sizeof( V_10 ) ;
#ifdef F_6
V_30 += V_8 * V_8 * sizeof( int ) ;
#endif
V_2 -> V_5 = F_19 ( V_30 , V_34 ) ;
if ( ! V_2 -> V_5 )
goto V_35;
V_2 -> V_20 = ( unsigned int * ) ( V_2 -> V_5 + V_8 ) ;
#ifdef F_6
V_2 -> V_11 = V_2 -> V_20 + V_8 ;
#endif
V_2 -> V_9 = V_8 ;
F_20 (pos, table)
if ( F_12 ( V_2 , V_32 -> V_36 ) == - 1 )
V_2 -> V_20 [ V_17 ++ ] = V_32 -> V_36 ;
V_2 -> V_19 = V_17 ;
V_2 -> V_7 = F_2 () ;
V_2 -> V_6 = F_12 ( V_2 , V_14 -> V_37 ) ;
V_14 -> V_2 = V_2 ;
V_28 = F_21 ( & V_14 -> V_26 , & V_27 ) ;
if ( ! V_28 )
return;
V_14 -> V_2 = NULL ;
F_16 ( V_2 -> V_5 ) ;
V_35:
F_16 ( V_2 ) ;
}
void F_22 ( struct V_13 * V_14 ,
unsigned int V_38 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
int V_39 , V_40 ;
if ( ! V_2 ) {
F_14 ( L_9 , V_25 ) ;
return;
}
V_39 = V_2 -> V_6 ;
V_40 = F_12 ( V_2 , V_38 ) ;
if ( V_39 == - 1 || V_40 == - 1 || V_39 == V_40 )
return;
F_1 ( V_2 ) ;
V_2 -> V_6 = V_40 ;
#ifdef F_6
V_2 -> V_11 [ V_39 * V_2 -> V_9 + V_40 ] ++ ;
#endif
V_2 -> V_12 ++ ;
}
