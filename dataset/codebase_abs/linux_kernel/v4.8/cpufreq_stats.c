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
if ( V_9 -> V_14 )
return 0 ;
F_1 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_15 ; V_13 ++ ) {
V_12 += sprintf ( V_10 + V_12 , L_2 , V_2 -> V_16 [ V_13 ] ,
( unsigned long long )
F_7 ( V_2 -> V_5 [ V_13 ] ) ) ;
}
return V_12 ;
}
static T_1 F_8 ( struct V_8 * V_9 , char * V_10 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 V_12 = 0 ;
int V_13 , V_17 ;
if ( V_9 -> V_14 )
return 0 ;
V_12 += snprintf ( V_10 + V_12 , V_18 - V_12 , L_3 ) ;
V_12 += snprintf ( V_10 + V_12 , V_18 - V_12 , L_4 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_15 ; V_13 ++ ) {
if ( V_12 >= V_18 )
break;
V_12 += snprintf ( V_10 + V_12 , V_18 - V_12 , L_5 ,
V_2 -> V_16 [ V_13 ] ) ;
}
if ( V_12 >= V_18 )
return V_18 ;
V_12 += snprintf ( V_10 + V_12 , V_18 - V_12 , L_6 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_15 ; V_13 ++ ) {
if ( V_12 >= V_18 )
break;
V_12 += snprintf ( V_10 + V_12 , V_18 - V_12 , L_7 ,
V_2 -> V_16 [ V_13 ] ) ;
for ( V_17 = 0 ; V_17 < V_2 -> V_15 ; V_17 ++ ) {
if ( V_12 >= V_18 )
break;
V_12 += snprintf ( V_10 + V_12 , V_18 - V_12 , L_5 ,
V_2 -> V_19 [ V_13 * V_2 -> V_20 + V_17 ] ) ;
}
if ( V_12 >= V_18 )
break;
V_12 += snprintf ( V_10 + V_12 , V_18 - V_12 , L_6 ) ;
}
if ( V_12 >= V_18 )
return V_18 ;
return V_12 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_21 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_20 ; V_22 ++ )
if ( V_2 -> V_16 [ V_22 ] == V_21 )
return V_22 ;
return - 1 ;
}
void F_10 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
if ( ! V_2 )
return;
F_11 ( L_8 , V_23 ) ;
F_12 ( & V_9 -> V_24 , & V_25 ) ;
F_13 ( V_2 -> V_5 ) ;
F_13 ( V_2 ) ;
V_9 -> V_2 = NULL ;
}
void F_14 ( struct V_8 * V_9 )
{
unsigned int V_13 = 0 , V_26 = 0 , V_27 = - V_28 ;
struct V_1 * V_2 ;
unsigned int V_29 ;
struct V_30 * V_31 , * V_32 ;
V_32 = V_9 -> V_16 ;
if ( F_15 ( ! V_32 ) )
return;
if ( V_9 -> V_2 )
return;
V_2 = F_16 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return;
F_17 (pos, table)
V_26 ++ ;
V_29 = V_26 * sizeof( int ) + V_26 * sizeof( V_34 ) ;
#ifdef F_18
V_29 += V_26 * V_26 * sizeof( int ) ;
#endif
V_2 -> V_5 = F_16 ( V_29 , V_33 ) ;
if ( ! V_2 -> V_5 )
goto V_35;
V_2 -> V_16 = ( unsigned int * ) ( V_2 -> V_5 + V_26 ) ;
#ifdef F_18
V_2 -> V_19 = V_2 -> V_16 + V_26 ;
#endif
V_2 -> V_20 = V_26 ;
F_17 (pos, table)
if ( F_9 ( V_2 , V_31 -> V_36 ) == - 1 )
V_2 -> V_16 [ V_13 ++ ] = V_31 -> V_36 ;
V_2 -> V_15 = V_13 ;
V_2 -> V_7 = F_2 () ;
V_2 -> V_6 = F_9 ( V_2 , V_9 -> V_37 ) ;
V_9 -> V_2 = V_2 ;
V_27 = F_19 ( & V_9 -> V_24 , & V_25 ) ;
if ( ! V_27 )
return;
V_9 -> V_2 = NULL ;
F_13 ( V_2 -> V_5 ) ;
V_35:
F_13 ( V_2 ) ;
}
void F_20 ( struct V_8 * V_9 ,
unsigned int V_38 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
int V_39 , V_40 ;
if ( ! V_2 ) {
F_11 ( L_9 , V_23 ) ;
return;
}
V_39 = V_2 -> V_6 ;
V_40 = F_9 ( V_2 , V_38 ) ;
if ( V_39 == - 1 || V_40 == - 1 || V_39 == V_40 )
return;
F_1 ( V_2 ) ;
V_2 -> V_6 = V_40 ;
#ifdef F_18
V_2 -> V_19 [ V_39 * V_2 -> V_20 + V_40 ] ++ ;
#endif
V_2 -> V_11 ++ ;
}
