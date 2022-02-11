static inline int F_1 ( int V_1 , int V_2 , int V_3 , int V_4 )
{
return V_2 > V_3 && V_1 < V_4 ;
}
int F_2 ( struct V_5 * V_6 )
{
struct V_5 * V_7 ;
int V_8 = 0 ;
if ( F_3 ( & V_9 ) != 0 )
return - V_10 ;
F_4 (ops, &nf_sockopts, list) {
if ( V_7 -> V_11 == V_6 -> V_11
&& ( F_1 ( V_7 -> V_12 , V_7 -> V_13 ,
V_6 -> V_12 , V_6 -> V_13 )
|| F_1 ( V_7 -> V_14 , V_7 -> V_15 ,
V_6 -> V_14 , V_6 -> V_15 ) ) ) {
F_5 ( L_1 ,
V_7 -> V_12 , V_7 -> V_13 ,
V_7 -> V_14 , V_7 -> V_15 ,
V_6 -> V_12 , V_6 -> V_13 ,
V_6 -> V_14 , V_6 -> V_15 ) ;
V_8 = - V_16 ;
goto V_17;
}
}
F_6 ( & V_6 -> V_18 , & V_19 ) ;
V_17:
F_7 ( & V_9 ) ;
return V_8 ;
}
void F_8 ( struct V_5 * V_6 )
{
F_9 ( & V_9 ) ;
F_10 ( & V_6 -> V_18 ) ;
F_7 ( & V_9 ) ;
}
static struct V_5 * F_11 ( struct V_20 * V_21 , T_1 V_11 ,
int V_22 , int V_23 )
{
struct V_5 * V_7 ;
if ( F_3 ( & V_9 ) != 0 )
return F_12 ( - V_10 ) ;
F_4 (ops, &nf_sockopts, list) {
if ( V_7 -> V_11 == V_11 ) {
if ( ! F_13 ( V_7 -> V_24 ) )
goto V_25;
if ( V_23 ) {
if ( V_22 >= V_7 -> V_14 &&
V_22 < V_7 -> V_15 )
goto V_17;
} else {
if ( V_22 >= V_7 -> V_12 &&
V_22 < V_7 -> V_13 )
goto V_17;
}
F_14 ( V_7 -> V_24 ) ;
}
}
V_25:
V_7 = F_12 ( - V_26 ) ;
V_17:
F_7 ( & V_9 ) ;
return V_7 ;
}
static int F_15 ( struct V_20 * V_21 , T_1 V_11 , int V_22 ,
char T_2 * V_27 , int * V_28 , int V_23 )
{
struct V_5 * V_7 ;
int V_8 ;
V_7 = F_11 ( V_21 , V_11 , V_22 , V_23 ) ;
if ( F_16 ( V_7 ) )
return F_17 ( V_7 ) ;
if ( V_23 )
V_8 = V_7 -> V_23 ( V_21 , V_22 , V_27 , V_28 ) ;
else
V_8 = V_7 -> V_29 ( V_21 , V_22 , V_27 , * V_28 ) ;
F_14 ( V_7 -> V_24 ) ;
return V_8 ;
}
int F_18 ( struct V_20 * V_21 , T_1 V_11 , int V_22 , char T_2 * V_27 ,
unsigned int V_28 )
{
return F_15 ( V_21 , V_11 , V_22 , V_27 , & V_28 , 0 ) ;
}
int F_19 ( struct V_20 * V_21 , T_1 V_11 , int V_22 , char T_2 * V_27 ,
int * V_28 )
{
return F_15 ( V_21 , V_11 , V_22 , V_27 , V_28 , 1 ) ;
}
static int F_20 ( struct V_20 * V_21 , T_1 V_11 , int V_22 ,
char T_2 * V_27 , int * V_28 , int V_23 )
{
struct V_5 * V_7 ;
int V_8 ;
V_7 = F_11 ( V_21 , V_11 , V_22 , V_23 ) ;
if ( F_16 ( V_7 ) )
return F_17 ( V_7 ) ;
if ( V_23 ) {
if ( V_7 -> V_30 )
V_8 = V_7 -> V_30 ( V_21 , V_22 , V_27 , V_28 ) ;
else
V_8 = V_7 -> V_23 ( V_21 , V_22 , V_27 , V_28 ) ;
} else {
if ( V_7 -> V_31 )
V_8 = V_7 -> V_31 ( V_21 , V_22 , V_27 , * V_28 ) ;
else
V_8 = V_7 -> V_29 ( V_21 , V_22 , V_27 , * V_28 ) ;
}
F_14 ( V_7 -> V_24 ) ;
return V_8 ;
}
int F_21 ( struct V_20 * V_21 , T_1 V_11 ,
int V_22 , char T_2 * V_27 , unsigned int V_28 )
{
return F_20 ( V_21 , V_11 , V_22 , V_27 , & V_28 , 0 ) ;
}
int F_22 ( struct V_20 * V_21 , T_1 V_11 ,
int V_22 , char T_2 * V_27 , int * V_28 )
{
return F_20 ( V_21 , V_11 , V_22 , V_27 , V_28 , 1 ) ;
}
