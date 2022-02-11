static T_1
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void
F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_1
F_5 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_6 ( V_2 -> V_6 , V_3 ) ;
}
static void
F_7 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_8 ( V_2 -> V_6 , V_3 , V_5 ) ;
}
static void
F_9 ( struct V_1 * V_2 )
{
V_2 -> V_7 = & V_8 ;
F_10 ( V_2 -> V_6 ) ;
}
static void *
F_11 ( struct V_1 * V_2 )
{
V_2 -> V_4 = F_12 ( V_2 -> V_6 ) ;
if ( F_13 ( V_2 -> V_4 ) )
V_2 -> V_7 = & V_9 ;
else
V_2 -> V_7 = & V_10 ;
return V_2 -> V_4 ;
}
static T_1
F_14 ( struct V_1 * V_2 , T_1 V_3 )
{
return F_6 ( V_2 -> V_11 , V_2 -> V_12 -> V_3 + V_3 ) ;
}
static void
F_15 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
F_8 ( V_2 -> V_11 , V_2 -> V_12 -> V_3 + V_3 , V_5 ) ;
}
static void
F_16 ( struct V_1 * V_2 )
{
V_2 -> V_7 = & V_13 ;
F_10 ( V_2 -> V_11 ) ;
}
static void *
F_17 ( struct V_1 * V_2 )
{
V_2 -> V_4 = F_12 ( V_2 -> V_11 ) ;
if ( F_13 ( V_2 -> V_4 ) ) {
V_2 -> V_4 = ( V_14 * ) V_2 -> V_4 + V_2 -> V_12 -> V_3 ;
V_2 -> V_7 = & V_15 ;
} else {
V_2 -> V_7 = & V_16 ;
}
return V_2 -> V_4 ;
}
static int
F_18 ( struct V_17 * V_18 , T_1 V_19 , int V_20 , bool V_21 ,
struct V_1 * V_11 , struct V_1 * V_2 )
{
T_1 V_3 ;
int V_22 ;
if ( V_11 ) {
if ( V_20 >= 0 ) {
V_22 = F_19 ( & V_11 -> V_23 , 0 , 1 , V_19 , V_19 ,
F_20 ( V_20 , 1 ) , & V_2 -> V_12 ) ;
} else {
V_22 = F_21 ( & V_11 -> V_23 , 0 , 1 , V_19 , V_19 ,
- V_20 , & V_2 -> V_12 ) ;
}
if ( V_22 )
return V_22 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_7 = & V_13 ;
V_2 -> V_24 = V_11 -> V_24 + V_2 -> V_12 -> V_3 ;
V_2 -> V_19 = V_2 -> V_12 -> V_25 ;
if ( V_21 ) {
F_12 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_2 -> V_19 ; V_3 += 4 )
F_8 ( V_2 , V_3 , 0x00000000 ) ;
F_10 ( V_2 ) ;
}
} else {
V_22 = F_22 ( V_18 , V_26 , V_19 ,
abs ( V_20 ) , V_21 , & V_2 -> V_6 ) ;
if ( V_22 )
return V_22 ;
V_2 -> V_7 = & V_8 ;
V_2 -> V_24 = F_23 ( V_2 -> V_6 ) ;
V_2 -> V_19 = F_24 ( V_2 -> V_6 ) ;
}
return F_25 ( & V_2 -> V_23 , 0 , V_2 -> V_19 , 1 ) ;
}
void
F_26 ( struct V_1 * * V_27 )
{
struct V_1 * V_2 = * V_27 ;
if ( V_2 ) {
if ( V_2 -> V_11 )
F_27 ( & V_2 -> V_11 -> V_23 , & V_2 -> V_12 ) ;
F_28 ( & V_2 -> V_23 ) ;
F_29 ( & V_2 -> V_6 ) ;
F_30 ( * V_27 ) ;
* V_27 = NULL ;
}
}
int
F_31 ( struct V_17 * V_18 , T_1 V_19 , int V_20 , bool V_21 ,
struct V_1 * V_11 , struct V_1 * * V_27 )
{
struct V_1 * V_2 ;
int V_22 ;
if ( ! ( V_2 = * V_27 = F_32 ( sizeof( * V_2 ) , V_28 ) ) )
return - V_29 ;
V_22 = F_18 ( V_18 , V_19 , V_20 , V_21 , V_11 , V_2 ) ;
if ( V_22 )
F_26 ( V_27 ) ;
return V_22 ;
}
int
F_33 ( struct V_1 * V_2 , struct V_30 * V_31 ,
T_1 V_32 , struct V_33 * V_34 )
{
struct V_35 * V_6 = V_2 -> V_6 ;
int V_22 = F_34 ( V_31 , V_2 -> V_19 , 12 , V_32 , V_34 ) ;
if ( V_22 == 0 )
F_35 ( V_6 , V_34 , 0 ) ;
return V_22 ;
}
void
F_36 ( struct V_33 * V_34 )
{
if ( V_34 -> V_12 ) {
F_37 ( V_34 ) ;
F_38 ( V_34 ) ;
}
}
int
F_39 ( struct V_35 * V_6 , struct V_1 * * V_27 )
{
if ( ! ( * V_27 = F_32 ( sizeof( * * V_27 ) , V_28 ) ) )
return - V_29 ;
( * V_27 ) -> V_24 = F_23 ( V_6 ) ;
( * V_27 ) -> V_19 = F_24 ( V_6 ) ;
return 0 ;
}
void
F_40 ( struct V_1 * V_36 , T_1 V_37 , void * V_38 ,
T_1 V_25 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_25 ; V_39 += 4 )
F_8 ( V_36 , V_37 + V_39 , * ( T_1 * ) ( V_38 + V_39 ) ) ;
}
void
F_41 ( void * V_36 , struct V_1 * V_38 , T_1 V_40 ,
T_1 V_25 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < V_25 ; V_39 += 4 )
( ( T_1 * ) V_38 ) [ V_39 / 4 ] = F_6 ( V_38 , V_40 + V_39 ) ;
}
