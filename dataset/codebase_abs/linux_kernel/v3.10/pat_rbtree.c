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
static T_1 F_4 ( struct V_1 * V_7 )
{
T_1 V_10 = V_7 -> V_4 , V_11 ;
V_11 = F_2 ( V_7 -> V_8 . V_12 ) ;
if ( V_11 > V_10 )
V_10 = V_11 ;
V_11 = F_2 ( V_7 -> V_8 . V_13 ) ;
if ( V_11 > V_10 )
V_10 = V_11 ;
return V_10 ;
}
static struct V_1 * F_5 ( struct V_14 * V_15 ,
T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_2 = V_15 -> V_5 ;
struct V_1 * V_16 = NULL ;
while ( V_2 ) {
struct V_1 * V_7 = F_3 ( V_2 , struct V_1 , V_8 ) ;
if ( F_2 ( V_2 -> V_13 ) > V_3 ) {
V_2 = V_2 -> V_13 ;
} else if ( F_1 ( V_7 , V_3 , V_4 ) ) {
V_16 = V_7 ;
break;
} else if ( V_3 >= V_7 -> V_3 ) {
V_2 = V_2 -> V_12 ;
} else {
break;
}
}
return V_16 ;
}
static struct V_1 * F_6 ( struct V_14 * V_15 ,
T_1 V_3 , T_1 V_4 )
{
struct V_1 * V_17 ;
V_17 = F_5 ( V_15 , V_3 , V_4 ) ;
while ( V_17 != NULL && V_17 -> V_3 < V_4 ) {
struct V_5 * V_2 ;
if ( V_17 -> V_3 == V_3 && V_17 -> V_4 == V_4 )
return V_17 ;
V_2 = F_7 ( & V_17 -> V_8 ) ;
if ( V_2 )
V_17 = F_3 ( V_2 , struct V_1 , V_8 ) ;
else
V_17 = NULL ;
}
return NULL ;
}
static int F_8 ( struct V_14 * V_15 ,
T_1 V_3 , T_1 V_4 ,
unsigned long V_18 , unsigned long * V_19 )
{
struct V_5 * V_2 ;
struct V_1 * V_17 ;
int V_20 = V_18 ;
V_17 = F_5 ( & V_21 , V_3 , V_4 ) ;
if ( V_17 == NULL )
goto V_22;
if ( V_17 -> type != V_20 && V_19 == NULL )
goto V_23;
F_9 ( L_1 , V_17 -> V_3 , V_17 -> V_4 ) ;
V_20 = V_17 -> type ;
V_2 = F_7 ( & V_17 -> V_8 ) ;
while ( V_2 ) {
V_17 = F_3 ( V_2 , struct V_1 , V_8 ) ;
if ( V_17 -> V_3 >= V_4 )
goto V_22;
if ( F_1 ( V_17 , V_3 , V_4 ) &&
V_17 -> type != V_20 ) {
goto V_23;
}
V_2 = F_7 ( & V_17 -> V_8 ) ;
}
V_22:
if ( V_19 )
* V_19 = V_20 ;
return 0 ;
V_23:
F_10 ( V_24 L_2
L_3 , V_25 -> V_26 , V_25 -> V_27 , V_3 ,
V_4 , F_11 ( V_20 ) , F_11 ( V_17 -> type ) ) ;
return - V_28 ;
}
static void F_12 ( struct V_14 * V_15 , struct V_1 * V_29 )
{
struct V_5 * * V_2 = & ( V_15 -> V_5 ) ;
struct V_5 * V_30 = NULL ;
while ( * V_2 ) {
struct V_1 * V_7 = F_3 ( * V_2 , struct V_1 , V_8 ) ;
V_30 = * V_2 ;
if ( V_7 -> V_9 < V_29 -> V_4 )
V_7 -> V_9 = V_29 -> V_4 ;
if ( V_29 -> V_3 <= V_7 -> V_3 )
V_2 = & ( ( * V_2 ) -> V_13 ) ;
else if ( V_29 -> V_3 > V_7 -> V_3 )
V_2 = & ( ( * V_2 ) -> V_12 ) ;
}
V_29 -> V_9 = V_29 -> V_4 ;
F_13 ( & V_29 -> V_8 , V_30 , V_2 ) ;
F_14 ( & V_29 -> V_8 , V_15 , & V_31 ) ;
}
int F_15 ( struct V_1 * V_32 , unsigned long * V_33 )
{
int V_34 = 0 ;
V_34 = F_8 ( & V_21 , V_32 -> V_3 , V_32 -> V_4 ,
V_32 -> type , V_33 ) ;
if ( ! V_34 ) {
if ( V_33 )
V_32 -> type = * V_33 ;
V_32 -> V_9 = V_32 -> V_4 ;
F_12 ( & V_21 , V_32 ) ;
}
return V_34 ;
}
struct V_1 * F_16 ( T_1 V_3 , T_1 V_4 )
{
struct V_1 * V_7 ;
V_7 = F_6 ( & V_21 , V_3 , V_4 ) ;
if ( ! V_7 )
goto V_35;
F_17 ( & V_7 -> V_8 , & V_21 , & V_31 ) ;
V_35:
return V_7 ;
}
struct V_1 * F_18 ( T_1 V_36 )
{
struct V_1 * V_7 ;
V_7 = F_5 ( & V_21 , V_36 , V_36 + V_37 ) ;
return V_7 ;
}
int F_19 ( struct V_1 * V_35 , T_2 V_38 )
{
struct V_5 * V_2 ;
int V_39 = 1 ;
V_2 = F_20 ( & V_21 ) ;
while ( V_2 && V_38 != V_39 ) {
V_2 = F_7 ( V_2 ) ;
V_39 ++ ;
}
if ( V_2 ) {
struct V_1 * V_40 = F_3 ( V_2 , struct V_1 , V_8 ) ;
* V_35 = * V_40 ;
return 0 ;
} else {
return 1 ;
}
}
