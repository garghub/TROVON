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
memset ( V_2 -> V_11 , 0 , V_8 * V_8 * sizeof( int ) ) ;
V_2 -> V_7 = F_2 () ;
V_2 -> V_12 = 0 ;
}
static T_1 F_6 ( struct V_13 * V_14 , char * V_15 )
{
return sprintf ( V_15 , L_1 , V_14 -> V_2 -> V_12 ) ;
}
static T_1 F_7 ( struct V_13 * V_14 , char * V_15 )
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
F_8 ( V_2 -> V_5 [ V_17 ] ) ) ;
}
return V_16 ;
}
static T_1 F_9 ( struct V_13 * V_14 , const char * V_15 ,
T_2 V_8 )
{
F_5 ( V_14 -> V_2 ) ;
return V_8 ;
}
static T_1 F_10 ( struct V_13 * V_14 , char * V_15 )
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
static int F_11 ( struct V_1 * V_2 , unsigned int V_23 )
{
int V_24 ;
for ( V_24 = 0 ; V_24 < V_2 -> V_9 ; V_24 ++ )
if ( V_2 -> V_20 [ V_24 ] == V_23 )
return V_24 ;
return - 1 ;
}
void F_12 ( struct V_13 * V_14 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
if ( ! V_2 )
return;
F_13 ( L_8 , V_25 ) ;
F_14 ( & V_14 -> V_26 , & V_27 ) ;
F_15 ( V_2 -> V_5 ) ;
F_15 ( V_2 ) ;
V_14 -> V_2 = NULL ;
}
void F_16 ( struct V_13 * V_14 )
{
unsigned int V_17 = 0 , V_8 = 0 , V_28 = - V_29 ;
struct V_1 * V_2 ;
unsigned int V_30 ;
struct V_31 * V_32 ;
V_8 = F_17 ( V_14 ) ;
if ( ! V_8 )
return;
if ( V_14 -> V_2 )
return;
V_2 = F_18 ( sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return;
V_30 = V_8 * sizeof( int ) + V_8 * sizeof( V_10 ) ;
V_30 += V_8 * V_8 * sizeof( int ) ;
V_2 -> V_5 = F_18 ( V_30 , V_33 ) ;
if ( ! V_2 -> V_5 )
goto V_34;
V_2 -> V_20 = ( unsigned int * ) ( V_2 -> V_5 + V_8 ) ;
V_2 -> V_11 = V_2 -> V_20 + V_8 ;
V_2 -> V_9 = V_8 ;
F_19 (pos, policy->freq_table)
if ( F_11 ( V_2 , V_32 -> V_35 ) == - 1 )
V_2 -> V_20 [ V_17 ++ ] = V_32 -> V_35 ;
V_2 -> V_19 = V_17 ;
V_2 -> V_7 = F_2 () ;
V_2 -> V_6 = F_11 ( V_2 , V_14 -> V_36 ) ;
V_14 -> V_2 = V_2 ;
V_28 = F_20 ( & V_14 -> V_26 , & V_27 ) ;
if ( ! V_28 )
return;
V_14 -> V_2 = NULL ;
F_15 ( V_2 -> V_5 ) ;
V_34:
F_15 ( V_2 ) ;
}
void F_21 ( struct V_13 * V_14 ,
unsigned int V_37 )
{
struct V_1 * V_2 = V_14 -> V_2 ;
int V_38 , V_39 ;
if ( ! V_2 ) {
F_13 ( L_9 , V_25 ) ;
return;
}
V_38 = V_2 -> V_6 ;
V_39 = F_11 ( V_2 , V_37 ) ;
if ( V_38 == - 1 || V_39 == - 1 || V_38 == V_39 )
return;
F_1 ( V_2 ) ;
V_2 -> V_6 = V_39 ;
V_2 -> V_11 [ V_38 * V_2 -> V_9 + V_39 ] ++ ;
V_2 -> V_12 ++ ;
}
