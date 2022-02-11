static inline int F_1 ( int V_1 , int V_2 , int V_3 , int V_4 )
{
return V_2 > V_3 && V_1 < V_4 ;
}
int F_2 ( struct V_5 * V_6 )
{
struct V_5 * V_7 ;
int V_8 = 0 ;
F_3 ( & V_9 ) ;
F_4 (ops, &nf_sockopts, list) {
if ( V_7 -> V_10 == V_6 -> V_10
&& ( F_1 ( V_7 -> V_11 , V_7 -> V_12 ,
V_6 -> V_11 , V_6 -> V_12 )
|| F_1 ( V_7 -> V_13 , V_7 -> V_14 ,
V_6 -> V_13 , V_6 -> V_14 ) ) ) {
F_5 ( L_1 ,
V_7 -> V_11 , V_7 -> V_12 ,
V_7 -> V_13 , V_7 -> V_14 ,
V_6 -> V_11 , V_6 -> V_12 ,
V_6 -> V_13 , V_6 -> V_14 ) ;
V_8 = - V_15 ;
goto V_16;
}
}
F_6 ( & V_6 -> V_17 , & V_18 ) ;
V_16:
F_7 ( & V_9 ) ;
return V_8 ;
}
void F_8 ( struct V_5 * V_6 )
{
F_3 ( & V_9 ) ;
F_9 ( & V_6 -> V_17 ) ;
F_7 ( & V_9 ) ;
}
static struct V_5 * F_10 ( struct V_19 * V_20 , T_1 V_10 ,
int V_21 , int V_22 )
{
struct V_5 * V_7 ;
F_3 ( & V_9 ) ;
F_4 (ops, &nf_sockopts, list) {
if ( V_7 -> V_10 == V_10 ) {
if ( ! F_11 ( V_7 -> V_23 ) )
goto V_24;
if ( V_22 ) {
if ( V_21 >= V_7 -> V_13 &&
V_21 < V_7 -> V_14 )
goto V_16;
} else {
if ( V_21 >= V_7 -> V_11 &&
V_21 < V_7 -> V_12 )
goto V_16;
}
F_12 ( V_7 -> V_23 ) ;
}
}
V_24:
V_7 = F_13 ( - V_25 ) ;
V_16:
F_7 ( & V_9 ) ;
return V_7 ;
}
static int F_14 ( struct V_19 * V_20 , T_1 V_10 , int V_21 ,
char T_2 * V_26 , int * V_27 , int V_22 )
{
struct V_5 * V_7 ;
int V_8 ;
V_7 = F_10 ( V_20 , V_10 , V_21 , V_22 ) ;
if ( F_15 ( V_7 ) )
return F_16 ( V_7 ) ;
if ( V_22 )
V_8 = V_7 -> V_22 ( V_20 , V_21 , V_26 , V_27 ) ;
else
V_8 = V_7 -> V_28 ( V_20 , V_21 , V_26 , * V_27 ) ;
F_12 ( V_7 -> V_23 ) ;
return V_8 ;
}
int F_17 ( struct V_19 * V_20 , T_1 V_10 , int V_21 , char T_2 * V_26 ,
unsigned int V_27 )
{
return F_14 ( V_20 , V_10 , V_21 , V_26 , & V_27 , 0 ) ;
}
int F_18 ( struct V_19 * V_20 , T_1 V_10 , int V_21 , char T_2 * V_26 ,
int * V_27 )
{
return F_14 ( V_20 , V_10 , V_21 , V_26 , V_27 , 1 ) ;
}
static int F_19 ( struct V_19 * V_20 , T_1 V_10 , int V_21 ,
char T_2 * V_26 , int * V_27 , int V_22 )
{
struct V_5 * V_7 ;
int V_8 ;
V_7 = F_10 ( V_20 , V_10 , V_21 , V_22 ) ;
if ( F_15 ( V_7 ) )
return F_16 ( V_7 ) ;
if ( V_22 ) {
if ( V_7 -> V_29 )
V_8 = V_7 -> V_29 ( V_20 , V_21 , V_26 , V_27 ) ;
else
V_8 = V_7 -> V_22 ( V_20 , V_21 , V_26 , V_27 ) ;
} else {
if ( V_7 -> V_30 )
V_8 = V_7 -> V_30 ( V_20 , V_21 , V_26 , * V_27 ) ;
else
V_8 = V_7 -> V_28 ( V_20 , V_21 , V_26 , * V_27 ) ;
}
F_12 ( V_7 -> V_23 ) ;
return V_8 ;
}
int F_20 ( struct V_19 * V_20 , T_1 V_10 ,
int V_21 , char T_2 * V_26 , unsigned int V_27 )
{
return F_19 ( V_20 , V_10 , V_21 , V_26 , & V_27 , 0 ) ;
}
int F_21 ( struct V_19 * V_20 , T_1 V_10 ,
int V_21 , char T_2 * V_26 , int * V_27 )
{
return F_19 ( V_20 , V_10 , V_21 , V_26 , V_27 , 1 ) ;
}
