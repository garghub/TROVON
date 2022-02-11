static bool F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 ) & V_4 ;
}
static int
F_3 ( struct V_5 * V_6 , struct V_1 * V_2 , T_1 V_7 )
{
const char * V_8 , * V_9 , * V_10 = V_2 -> V_11 + V_7 ;
for ( V_8 = V_2 -> V_11 ; * V_8 && V_8 < V_10 ;
V_8 = V_9 + strlen ( V_9 ) + 1 ) {
V_9 = V_8 + strlen ( V_8 ) + 1 ;
if ( V_9 >= V_10 ) {
F_4 ( V_6 , L_1 ) ;
return - V_12 ;
}
if ( V_9 + strlen ( V_9 ) + 1 > V_10 ) {
F_4 ( V_6 , L_2 ) ;
return - V_12 ;
}
}
return 0 ;
}
static int
F_5 ( struct V_5 * V_6 , struct V_1 * V_13 , T_1 V_14 )
{
T_1 V_7 , V_15 ;
V_7 = F_2 ( V_13 -> V_7 ) ;
if ( V_7 > V_14 ) {
F_6 ( V_6 , L_3 , V_7 , V_14 ) ;
return - V_12 ;
}
V_7 -= sizeof( T_1 ) ;
V_15 = F_7 ( V_13 , V_7 ) ;
if ( V_15 != F_8 ( V_13 -> V_16 + V_7 ) ) {
F_6 ( V_6 , L_4 ,
V_15 , F_8 ( V_13 -> V_16 + V_7 ) ) ;
return - V_12 ;
}
return F_3 ( V_6 , V_13 , V_7 ) ;
}
static struct V_1 *
F_9 ( struct V_5 * V_6 , T_2 * V_17 )
{
struct V_1 * V_18 ;
struct V_19 * V_20 ;
T_3 V_21 ;
T_1 V_22 ;
int V_23 ;
T_4 * V_13 ;
V_20 = F_10 ( V_6 , V_24 ) ;
if ( ! F_11 ( V_20 ) ) {
V_22 = F_12 ( V_20 ) ;
V_21 = F_13 ( V_20 ) ;
* V_17 = F_14 ( V_20 ) ;
F_15 ( V_20 ) ;
if ( * V_17 < V_25 )
return NULL ;
} else if ( F_16 ( V_20 ) == - V_26 ) {
V_22 = F_17 ( V_27 ,
V_28 , 0 , 1 ) ;
V_21 = 0x30000 ;
* V_17 = 0x0e000 ;
} else {
return NULL ;
}
V_13 = F_18 ( * V_17 + 1 , V_29 ) ;
if ( ! V_13 )
return NULL ;
V_23 = F_19 ( V_6 , V_22 , V_21 , V_13 , * V_17 ) ;
if ( V_23 != * V_17 )
goto V_30;
V_18 = ( void * ) V_13 ;
if ( F_1 ( V_18 ) )
goto V_30;
if ( F_2 ( V_18 -> V_3 ) != V_31 ) {
F_6 ( V_6 , L_5 ,
F_2 ( V_18 -> V_3 ) ) ;
goto V_30;
}
V_13 [ * V_17 ] = '\0' ;
return ( void * ) V_13 ;
V_30:
F_20 ( V_13 ) ;
return NULL ;
}
static struct V_1 * F_21 ( struct V_5 * V_6 , T_2 * V_32 )
{
const unsigned long V_33 = V_34 + V_35 * V_36 ;
struct V_1 * V_13 ;
int V_23 ;
for (; ; ) {
const unsigned long V_37 = V_34 ;
V_13 = F_9 ( V_6 , V_32 ) ;
if ( V_13 )
return V_13 ;
V_23 = F_22 ( 100 ) ;
if ( V_23 || F_23 ( V_37 , V_33 ) ) {
F_6 ( V_6 , L_6 ) ;
return NULL ;
}
}
}
struct V_1 * F_24 ( struct V_5 * V_6 )
{
struct V_1 * V_13 ;
T_2 V_32 = 0 ;
int V_23 ;
V_13 = F_21 ( V_6 , & V_32 ) ;
if ( ! V_13 )
return NULL ;
V_23 = F_5 ( V_6 , V_13 , V_32 ) ;
if ( V_23 ) {
F_20 ( V_13 ) ;
return NULL ;
}
return V_13 ;
}
const char * F_25 ( struct V_1 * V_2 , const char * V_38 )
{
const char * V_8 , * V_9 , * V_10 ;
if ( ! V_2 || ! V_38 )
return NULL ;
V_10 = V_2 -> V_11 + F_2 ( V_2 -> V_7 ) - sizeof( T_1 ) ;
for ( V_8 = V_2 -> V_11 ; * V_8 && V_8 < V_10 ;
V_8 = V_9 + strlen ( V_9 ) + 1 ) {
V_9 = V_8 + strlen ( V_8 ) + 1 ;
if ( strcmp ( V_8 , V_38 ) == 0 )
return V_9 ;
}
return NULL ;
}
