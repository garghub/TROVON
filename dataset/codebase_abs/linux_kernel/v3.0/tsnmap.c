struct V_1 * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 V_4 , T_3 V_5 )
{
if ( ! V_2 -> V_6 ) {
V_2 -> V_6 = F_2 ( V_3 >> 3 , V_5 ) ;
if ( V_2 -> V_6 == NULL )
return NULL ;
V_2 -> V_3 = V_3 ;
} else {
F_3 ( V_2 -> V_6 , V_2 -> V_3 ) ;
}
V_2 -> V_7 = V_4 ;
V_2 -> V_8 = V_4 - 1 ;
V_2 -> V_9 = V_2 -> V_8 ;
V_2 -> V_10 = 0 ;
return V_2 ;
}
void F_4 ( struct V_1 * V_2 )
{
V_2 -> V_3 = 0 ;
F_5 ( V_2 -> V_6 ) ;
}
int F_6 ( const struct V_1 * V_2 , T_2 V_11 )
{
T_4 V_12 ;
if ( F_7 ( V_11 , V_2 -> V_8 ) )
return 1 ;
if ( ! F_8 ( V_11 , V_2 -> V_7 + V_13 ) )
return - 1 ;
V_12 = V_11 - V_2 -> V_7 ;
if ( V_12 < V_2 -> V_3 && F_9 ( V_12 , V_2 -> V_6 ) )
return 1 ;
else
return 0 ;
}
int F_10 ( struct V_1 * V_2 , T_2 V_11 )
{
T_5 V_12 ;
if ( F_8 ( V_11 , V_2 -> V_7 ) )
return 0 ;
V_12 = V_11 - V_2 -> V_7 ;
if ( V_12 >= V_2 -> V_3 && ! F_11 ( V_2 , V_12 ) )
return - V_14 ;
if ( ! F_12 ( V_2 ) && V_12 == 0 ) {
V_2 -> V_9 ++ ;
V_2 -> V_8 ++ ;
V_2 -> V_7 ++ ;
} else {
if ( F_8 ( V_2 -> V_9 , V_11 ) )
V_2 -> V_9 = V_11 ;
F_13 ( V_12 , V_2 -> V_6 ) ;
F_14 ( V_2 ) ;
}
return 0 ;
}
T_6 void F_15 ( const struct V_1 * V_2 ,
struct V_15 * V_16 )
{
V_16 -> V_17 = V_2 -> V_8 + 1 ;
}
T_6 int F_16 ( const struct V_1 * V_2 ,
struct V_15 * V_16 ,
T_1 * V_17 , T_1 * V_18 )
{
int V_19 = 0 ;
T_1 V_20 = 0 , V_21 = 0 , V_22 ;
if ( F_7 ( V_2 -> V_9 , V_16 -> V_17 ) )
return 0 ;
V_22 = V_16 -> V_17 - V_2 -> V_7 ;
F_17 ( V_2 -> V_6 , V_22 , V_2 -> V_3 ,
& V_20 , & V_21 ) ;
if ( V_20 && ! V_21 )
V_21 = V_2 -> V_3 - 1 ;
if ( V_21 ) {
* V_17 = V_20 + 1 ;
* V_18 = V_21 + 1 ;
V_16 -> V_17 = V_2 -> V_8 + * V_18 + 1 ;
V_19 = 1 ;
}
return V_19 ;
}
void F_18 ( struct V_1 * V_2 , T_2 V_11 )
{
T_4 V_12 ;
if ( F_8 ( V_11 , V_2 -> V_7 ) )
return;
if ( ! F_8 ( V_11 , V_2 -> V_7 + V_13 ) )
return;
if ( F_8 ( V_2 -> V_9 , V_11 ) )
V_2 -> V_9 = V_11 ;
V_12 = V_11 - V_2 -> V_7 + 1 ;
V_2 -> V_7 += V_12 ;
V_2 -> V_8 += V_12 ;
if ( V_12 >= V_2 -> V_3 ) {
F_3 ( V_2 -> V_6 , V_2 -> V_3 ) ;
} else {
F_19 ( V_2 -> V_6 , V_2 -> V_6 , V_12 , V_2 -> V_3 ) ;
F_14 ( V_2 ) ;
}
}
static void F_14 ( struct V_1 * V_2 )
{
T_5 V_3 ;
unsigned long V_23 ;
V_3 = V_2 -> V_9 - V_2 -> V_8 ;
V_23 = F_20 ( V_2 -> V_6 , V_3 ) ;
if ( ! V_23 )
return;
V_2 -> V_7 += V_23 ;
V_2 -> V_8 += V_23 ;
F_19 ( V_2 -> V_6 , V_2 -> V_6 , V_23 , V_2 -> V_3 ) ;
}
T_1 F_21 ( struct V_1 * V_2 )
{
T_2 V_24 = V_2 -> V_8 ;
T_2 V_25 = V_2 -> V_9 ;
T_2 V_7 = V_2 -> V_7 ;
T_1 V_26 ;
T_4 V_12 , V_27 ;
V_26 = V_25 - V_24 ;
V_12 = V_25 - V_7 ;
if ( V_12 == 0 || V_12 >= V_2 -> V_3 )
goto V_28;
for ( V_27 = 0 ; V_27 < V_12 + 1 ; V_27 ++ ) {
if ( F_9 ( V_27 , V_2 -> V_6 ) )
V_26 -- ;
}
V_28:
return V_26 ;
}
static void F_17 ( unsigned long * V_2 , T_1 V_29 ,
T_1 V_3 , T_1 * V_17 , T_1 * V_18 )
{
int V_27 = V_29 ;
V_27 = F_22 ( V_2 , V_3 , V_29 ) ;
if ( V_27 < V_3 )
* V_17 = V_27 ;
if ( * V_17 ) {
V_27 = F_23 ( V_2 , V_3 , V_27 ) ;
if ( V_27 < V_3 )
* V_18 = V_27 - 1 ;
}
}
void F_24 ( struct V_1 * V_2 , T_2 V_11 )
{
T_4 V_12 ;
if ( F_8 ( V_11 , V_2 -> V_7 ) )
return;
if ( ! F_8 ( V_11 , V_2 -> V_7 + V_2 -> V_3 ) )
return;
V_12 = V_11 - V_2 -> V_7 ;
F_25 ( V_12 , V_2 -> V_6 ) ;
}
T_1 F_26 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_15 V_16 ;
int V_32 = 0 ;
if ( F_12 ( V_2 ) ) {
T_1 V_17 = 0 , V_18 = 0 ;
F_15 ( V_2 , & V_16 ) ;
while ( F_16 ( V_2 , & V_16 ,
& V_17 ,
& V_18 ) ) {
V_31 [ V_32 ] . V_17 = F_27 ( V_17 ) ;
V_31 [ V_32 ] . V_18 = F_27 ( V_18 ) ;
V_32 ++ ;
if ( V_32 >= V_33 )
break;
}
}
return V_32 ;
}
static int F_11 ( struct V_1 * V_2 , T_5 V_12 )
{
unsigned long * V_34 ;
unsigned long V_35 ;
T_5 V_3 ;
if ( V_12 >= V_13 )
return 0 ;
V_35 = F_28 ( ( V_12 - V_2 -> V_3 ) , V_36 ) + V_37 ;
V_3 = F_29 ( T_5 , V_2 -> V_3 + V_35 , V_13 ) ;
V_34 = F_2 ( V_3 >> 3 , V_38 ) ;
if ( ! V_34 )
return 0 ;
F_30 ( V_34 , V_2 -> V_6 , V_2 -> V_9 - V_2 -> V_7 ) ;
F_5 ( V_2 -> V_6 ) ;
V_2 -> V_6 = V_34 ;
V_2 -> V_3 = V_3 ;
return 1 ;
}
