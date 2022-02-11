static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
if ( V_2 -> V_3 >= V_4 || V_2 -> V_4 <= V_3 )
return 0 ;
return 1 ;
}
static T_1 F_2 ( struct V_5 * V_2 )
{
T_1 V_6 = 0 ;
if ( V_2 ) {
struct V_1 * V_7 = F_3 ( V_2 , struct V_1 , V_8 ) ;
V_6 = V_7 -> V_9 ;
}
return V_6 ;
}
static void F_4 ( struct V_5 * V_2 , void * V_10 )
{
struct V_1 * V_7 ;
T_1 V_11 , V_12 ;
if ( ! V_2 )
return;
V_7 = F_3 ( V_2 , struct V_1 , V_8 ) ;
V_11 = V_7 -> V_4 ;
V_12 = F_2 ( V_2 -> V_13 ) ;
if ( V_12 > V_11 )
V_11 = V_12 ;
V_12 = F_2 ( V_2 -> V_14 ) ;
if ( V_12 > V_11 )
V_11 = V_12 ;
V_7 -> V_9 = V_11 ;
}
static struct V_1 * F_5 ( struct V_15 * V_16 ,
T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_2 = V_16 -> V_5 ;
struct V_1 * V_17 = NULL ;
while ( V_2 ) {
struct V_1 * V_7 = F_3 ( V_2 , struct V_1 , V_8 ) ;
if ( F_2 ( V_2 -> V_14 ) > V_3 ) {
V_2 = V_2 -> V_14 ;
} else if ( F_1 ( V_7 , V_3 , V_4 ) ) {
V_17 = V_7 ;
break;
} else if ( V_3 >= V_7 -> V_3 ) {
V_2 = V_2 -> V_13 ;
} else {
break;
}
}
return V_17 ;
}
static struct V_1 * F_6 ( struct V_15 * V_16 ,
T_1 V_3 , T_1 V_4 )
{
struct V_1 * V_18 ;
V_18 = F_5 ( V_16 , V_3 , V_4 ) ;
while ( V_18 != NULL && V_18 -> V_3 < V_4 ) {
struct V_5 * V_2 ;
if ( V_18 -> V_3 == V_3 && V_18 -> V_4 == V_4 )
return V_18 ;
V_2 = F_7 ( & V_18 -> V_8 ) ;
if ( V_2 )
V_18 = F_3 ( V_2 , struct V_1 , V_8 ) ;
else
V_18 = NULL ;
}
return NULL ;
}
static int F_8 ( struct V_15 * V_16 ,
T_1 V_3 , T_1 V_4 ,
unsigned long V_19 , unsigned long * V_20 )
{
struct V_5 * V_2 ;
struct V_1 * V_18 ;
int V_21 = V_19 ;
V_18 = F_5 ( & V_22 , V_3 , V_4 ) ;
if ( V_18 == NULL )
goto V_23;
if ( V_18 -> type != V_21 && V_20 == NULL )
goto V_24;
F_9 ( L_1 , V_18 -> V_3 , V_18 -> V_4 ) ;
V_21 = V_18 -> type ;
V_2 = F_7 ( & V_18 -> V_8 ) ;
while ( V_2 ) {
V_18 = F_3 ( V_2 , struct V_1 , V_8 ) ;
if ( V_18 -> V_3 >= V_4 )
goto V_23;
if ( F_1 ( V_18 , V_3 , V_4 ) &&
V_18 -> type != V_21 ) {
goto V_24;
}
V_2 = F_7 ( & V_18 -> V_8 ) ;
}
V_23:
if ( V_20 )
* V_20 = V_21 ;
return 0 ;
V_24:
F_10 ( V_25 L_2
L_3 , V_26 -> V_27 , V_26 -> V_28 , V_3 ,
V_4 , F_11 ( V_21 ) , F_11 ( V_18 -> type ) ) ;
return - V_29 ;
}
static void F_12 ( struct V_15 * V_16 , struct V_1 * V_30 )
{
struct V_5 * * V_2 = & ( V_16 -> V_5 ) ;
struct V_5 * V_31 = NULL ;
while ( * V_2 ) {
struct V_1 * V_7 = F_3 ( * V_2 , struct V_1 , V_8 ) ;
V_31 = * V_2 ;
if ( V_30 -> V_3 <= V_7 -> V_3 )
V_2 = & ( ( * V_2 ) -> V_14 ) ;
else if ( V_30 -> V_3 > V_7 -> V_3 )
V_2 = & ( ( * V_2 ) -> V_13 ) ;
}
F_13 ( & V_30 -> V_8 , V_31 , V_2 ) ;
F_14 ( & V_30 -> V_8 , V_16 ) ;
F_15 ( & V_30 -> V_8 , F_4 , NULL ) ;
}
int F_16 ( struct V_1 * V_32 , unsigned long * V_33 )
{
int V_34 = 0 ;
V_34 = F_8 ( & V_22 , V_32 -> V_3 , V_32 -> V_4 ,
V_32 -> type , V_33 ) ;
if ( ! V_34 ) {
if ( V_33 )
V_32 -> type = * V_33 ;
V_32 -> V_9 = V_32 -> V_4 ;
F_12 ( & V_22 , V_32 ) ;
}
return V_34 ;
}
struct V_1 * F_17 ( T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_35 ;
struct V_1 * V_7 ;
V_7 = F_6 ( & V_22 , V_3 , V_4 ) ;
if ( ! V_7 )
goto V_36;
V_35 = F_18 ( & V_7 -> V_8 ) ;
F_19 ( & V_7 -> V_8 , & V_22 ) ;
F_20 ( V_35 , F_4 , NULL ) ;
V_36:
return V_7 ;
}
struct V_1 * F_21 ( T_1 V_37 )
{
struct V_1 * V_7 ;
V_7 = F_5 ( & V_22 , V_37 , V_37 + V_38 ) ;
return V_7 ;
}
int F_22 ( struct V_1 * V_36 , T_2 V_39 )
{
struct V_5 * V_2 ;
int V_40 = 1 ;
V_2 = F_23 ( & V_22 ) ;
while ( V_2 && V_39 != V_40 ) {
V_2 = F_7 ( V_2 ) ;
V_40 ++ ;
}
if ( V_2 ) {
struct V_1 * V_41 = F_3 ( V_2 , struct V_1 , V_8 ) ;
* V_36 = * V_41 ;
return 0 ;
} else {
return 1 ;
}
}
