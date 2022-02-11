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
int F_10 ( struct V_1 * V_2 , T_2 V_11 ,
struct V_14 * V_15 )
{
T_5 V_12 ;
if ( F_8 ( V_11 , V_2 -> V_7 ) )
return 0 ;
V_12 = V_11 - V_2 -> V_7 ;
if ( V_12 >= V_2 -> V_3 && ! F_11 ( V_2 , V_12 + 1 ) )
return - V_16 ;
if ( ! F_12 ( V_2 ) && V_12 == 0 ) {
V_2 -> V_9 ++ ;
V_2 -> V_8 ++ ;
if ( V_15 )
V_15 -> V_17 =
V_15 -> V_18 -> V_19 . V_17 ;
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
struct V_20 * V_21 )
{
V_21 -> V_22 = V_2 -> V_8 + 1 ;
}
T_6 int F_16 ( const struct V_1 * V_2 ,
struct V_20 * V_21 ,
T_1 * V_22 , T_1 * V_23 )
{
int V_24 = 0 ;
T_1 V_25 = 0 , V_26 = 0 , V_27 ;
if ( F_7 ( V_2 -> V_9 , V_21 -> V_22 ) )
return 0 ;
V_27 = V_21 -> V_22 - V_2 -> V_7 ;
F_17 ( V_2 -> V_6 , V_27 , V_2 -> V_3 ,
& V_25 , & V_26 ) ;
if ( V_25 && ! V_26 )
V_26 = V_2 -> V_3 - 1 ;
if ( V_26 ) {
* V_22 = V_25 + 1 ;
* V_23 = V_26 + 1 ;
V_21 -> V_22 = V_2 -> V_8 + * V_23 + 1 ;
V_24 = 1 ;
}
return V_24 ;
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
unsigned long V_28 ;
V_3 = V_2 -> V_9 - V_2 -> V_8 ;
V_28 = F_20 ( V_2 -> V_6 , V_3 ) ;
if ( ! V_28 )
return;
V_2 -> V_7 += V_28 ;
V_2 -> V_8 += V_28 ;
F_19 ( V_2 -> V_6 , V_2 -> V_6 , V_28 , V_2 -> V_3 ) ;
}
T_1 F_21 ( struct V_1 * V_2 )
{
T_2 V_29 = V_2 -> V_8 ;
T_2 V_30 = V_2 -> V_9 ;
T_2 V_7 = V_2 -> V_7 ;
T_1 V_31 ;
T_4 V_12 ;
V_31 = V_30 - V_29 ;
V_12 = V_30 - V_7 ;
if ( V_12 == 0 || V_12 >= V_2 -> V_3 )
goto V_32;
V_31 -= F_22 ( V_2 -> V_6 , V_12 + 1 ) ;
V_32:
return V_31 ;
}
static void F_17 ( unsigned long * V_2 , T_1 V_33 ,
T_1 V_3 , T_1 * V_22 , T_1 * V_23 )
{
int V_34 = V_33 ;
V_34 = F_23 ( V_2 , V_3 , V_33 ) ;
if ( V_34 < V_3 )
* V_22 = V_34 ;
if ( * V_22 ) {
V_34 = F_24 ( V_2 , V_3 , V_34 ) ;
if ( V_34 < V_3 )
* V_23 = V_34 - 1 ;
}
}
void F_25 ( struct V_1 * V_2 , T_2 V_11 )
{
T_4 V_12 ;
if ( F_8 ( V_11 , V_2 -> V_7 ) )
return;
if ( ! F_8 ( V_11 , V_2 -> V_7 + V_2 -> V_3 ) )
return;
V_12 = V_11 - V_2 -> V_7 ;
F_26 ( V_12 , V_2 -> V_6 ) ;
}
T_1 F_27 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
struct V_20 V_21 ;
int V_37 = 0 ;
if ( F_12 ( V_2 ) ) {
T_1 V_22 = 0 , V_23 = 0 ;
F_15 ( V_2 , & V_21 ) ;
while ( F_16 ( V_2 , & V_21 ,
& V_22 ,
& V_23 ) ) {
V_36 [ V_37 ] . V_22 = F_28 ( V_22 ) ;
V_36 [ V_37 ] . V_23 = F_28 ( V_23 ) ;
V_37 ++ ;
if ( V_37 >= V_38 )
break;
}
}
return V_37 ;
}
static int F_11 ( struct V_1 * V_2 , T_5 V_39 )
{
unsigned long * V_40 ;
unsigned long V_41 ;
T_5 V_3 ;
if ( V_39 > V_13 )
return 0 ;
V_41 = F_29 ( ( V_39 - V_2 -> V_3 ) , V_42 ) + V_43 ;
V_3 = F_30 ( T_5 , V_2 -> V_3 + V_41 , V_13 ) ;
V_40 = F_2 ( V_3 >> 3 , V_44 ) ;
if ( ! V_40 )
return 0 ;
F_31 ( V_40 , V_2 -> V_6 ,
V_2 -> V_9 - V_2 -> V_8 ) ;
F_5 ( V_2 -> V_6 ) ;
V_2 -> V_6 = V_40 ;
V_2 -> V_3 = V_3 ;
return 1 ;
}
