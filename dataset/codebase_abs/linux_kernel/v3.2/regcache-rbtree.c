static inline void F_1 (
struct V_1 * V_2 ,
unsigned int * V_3 , unsigned int * V_4 )
{
* V_3 = V_2 -> V_5 ;
* V_4 = V_2 -> V_5 + V_2 -> V_6 - 1 ;
}
static unsigned int F_2 (
struct V_1 * V_2 , unsigned int V_7 ,
unsigned int V_8 )
{
return F_3 ( V_2 -> V_9 , V_7 , V_8 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned int V_7 , unsigned int V_10 ,
unsigned int V_8 )
{
F_5 ( V_2 -> V_9 , V_7 , V_10 , V_8 ) ;
}
static struct V_1 * F_6 ( struct V_11 * V_12 ,
unsigned int V_13 )
{
struct V_14 * V_15 = V_12 -> V_16 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
unsigned int V_5 , V_19 ;
V_2 = V_15 -> V_20 ;
if ( V_2 ) {
F_1 ( V_2 , & V_5 , & V_19 ) ;
if ( V_13 >= V_5 && V_13 <= V_19 )
return V_2 ;
}
V_18 = V_15 -> V_21 . V_17 ;
while ( V_18 ) {
V_2 = F_7 ( V_18 , struct V_1 , V_18 ) ;
F_1 ( V_2 , & V_5 , & V_19 ) ;
if ( V_13 >= V_5 && V_13 <= V_19 ) {
V_15 -> V_20 = V_2 ;
return V_2 ;
} else if ( V_13 > V_19 ) {
V_18 = V_18 -> V_22 ;
} else if ( V_13 < V_5 ) {
V_18 = V_18 -> V_23 ;
}
}
return NULL ;
}
static int F_8 ( struct V_24 * V_21 ,
struct V_1 * V_2 )
{
struct V_17 * * V_25 , * V_26 ;
struct V_1 * V_27 ;
unsigned int V_28 , V_29 ;
unsigned int V_5 ;
V_26 = NULL ;
V_25 = & V_21 -> V_17 ;
while ( * V_25 ) {
V_27 = F_7 ( * V_25 , struct V_1 ,
V_18 ) ;
F_1 ( V_27 , & V_28 ,
& V_29 ) ;
V_5 = V_2 -> V_5 ;
V_26 = * V_25 ;
if ( V_5 >= V_28 &&
V_5 <= V_29 )
return 0 ;
else if ( V_5 > V_29 )
V_25 = & ( ( * V_25 ) -> V_22 ) ;
else if ( V_5 < V_28 )
V_25 = & ( ( * V_25 ) -> V_23 ) ;
}
F_9 ( & V_2 -> V_18 , V_26 , V_25 ) ;
F_10 ( & V_2 -> V_18 , V_21 ) ;
return 1 ;
}
static int F_11 ( struct V_11 * V_12 )
{
struct V_14 * V_15 ;
int V_30 ;
int V_31 ;
V_12 -> V_16 = F_12 ( sizeof *V_15 , V_32 ) ;
if ( ! V_12 -> V_16 )
return - V_33 ;
V_15 = V_12 -> V_16 ;
V_15 -> V_21 = V_34 ;
V_15 -> V_20 = NULL ;
for ( V_30 = 0 ; V_30 < V_12 -> V_35 ; V_30 ++ ) {
V_31 = F_13 ( V_12 ,
V_12 -> V_36 [ V_30 ] . V_13 ,
V_12 -> V_36 [ V_30 ] . V_37 ) ;
if ( V_31 )
goto V_38;
}
return 0 ;
V_38:
F_14 ( V_12 ) ;
return V_31 ;
}
static int F_15 ( struct V_11 * V_12 )
{
struct V_17 * V_39 ;
struct V_14 * V_15 ;
struct V_1 * V_40 ;
V_15 = V_12 -> V_16 ;
if ( ! V_15 )
return 0 ;
V_39 = F_16 ( & V_15 -> V_21 ) ;
while ( V_39 ) {
V_40 = F_17 ( V_39 , struct V_1 , V_18 ) ;
V_39 = F_18 ( & V_40 -> V_18 ) ;
F_19 ( & V_40 -> V_18 , & V_15 -> V_21 ) ;
F_20 ( V_40 -> V_9 ) ;
F_20 ( V_40 ) ;
}
F_20 ( V_12 -> V_16 ) ;
V_12 -> V_16 = NULL ;
return 0 ;
}
static int F_21 ( struct V_11 * V_12 ,
unsigned int V_13 , unsigned int * V_41 )
{
struct V_1 * V_2 ;
unsigned int V_42 ;
V_2 = F_6 ( V_12 , V_13 ) ;
if ( V_2 ) {
V_42 = V_13 - V_2 -> V_5 ;
* V_41 = F_2 ( V_2 , V_42 ,
V_12 -> V_43 ) ;
} else {
return - V_44 ;
}
return 0 ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned int V_45 , unsigned int V_13 ,
unsigned int V_41 , unsigned int V_8 )
{
T_1 * V_46 ;
V_46 = F_23 ( V_2 -> V_9 ,
( V_2 -> V_6 + 1 ) * V_8 , V_32 ) ;
if ( ! V_46 )
return - V_33 ;
memmove ( V_46 + ( V_45 + 1 ) * V_8 ,
V_46 + V_45 * V_8 ,
( V_2 -> V_6 - V_45 ) * V_8 ) ;
V_2 -> V_9 = V_46 ;
V_2 -> V_6 ++ ;
if ( ! V_45 )
V_2 -> V_5 = V_13 ;
F_4 ( V_2 , V_45 , V_41 , V_8 ) ;
return 0 ;
}
static int F_13 ( struct V_11 * V_12 , unsigned int V_13 ,
unsigned int V_41 )
{
struct V_14 * V_15 ;
struct V_1 * V_2 , * V_27 ;
struct V_17 * V_18 ;
unsigned int V_10 ;
unsigned int V_42 ;
unsigned int V_45 ;
int V_30 ;
int V_31 ;
V_15 = V_12 -> V_16 ;
V_2 = F_6 ( V_12 , V_13 ) ;
if ( V_2 ) {
V_42 = V_13 - V_2 -> V_5 ;
V_10 = F_2 ( V_2 , V_42 ,
V_12 -> V_43 ) ;
if ( V_10 == V_41 )
return 0 ;
F_4 ( V_2 , V_42 , V_41 ,
V_12 -> V_43 ) ;
} else {
for ( V_18 = F_16 ( & V_15 -> V_21 ) ; V_18 ;
V_18 = F_18 ( V_18 ) ) {
V_27 = F_17 ( V_18 , struct V_1 , V_18 ) ;
for ( V_30 = 0 ; V_30 < V_27 -> V_6 ; V_30 ++ ) {
V_42 = V_27 -> V_5 + V_30 ;
if ( abs ( V_42 - V_13 ) != 1 )
continue;
if ( V_42 + 1 == V_13 )
V_45 = V_30 + 1 ;
else
V_45 = V_30 ;
V_31 = F_22 ( V_27 , V_45 ,
V_13 , V_41 ,
V_12 -> V_43 ) ;
if ( V_31 )
return V_31 ;
V_15 -> V_20 = V_27 ;
return 0 ;
}
}
V_2 = F_24 ( sizeof *V_2 , V_32 ) ;
if ( ! V_2 )
return - V_33 ;
V_2 -> V_6 = 1 ;
V_2 -> V_5 = V_13 ;
V_2 -> V_9 = F_12 ( V_2 -> V_6 * V_12 -> V_43 ,
V_32 ) ;
if ( ! V_2 -> V_9 ) {
F_20 ( V_2 ) ;
return - V_33 ;
}
F_4 ( V_2 , 0 , V_41 , V_12 -> V_43 ) ;
F_8 ( & V_15 -> V_21 , V_2 ) ;
V_15 -> V_20 = V_2 ;
}
return 0 ;
}
static int F_25 ( struct V_11 * V_12 )
{
struct V_14 * V_15 ;
struct V_17 * V_18 ;
struct V_1 * V_2 ;
unsigned int V_47 ;
unsigned int V_10 ;
int V_31 ;
int V_30 ;
V_15 = V_12 -> V_16 ;
for ( V_18 = F_16 ( & V_15 -> V_21 ) ; V_18 ; V_18 = F_18 ( V_18 ) ) {
V_2 = F_17 ( V_18 , struct V_1 , V_18 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_6 ; V_30 ++ ) {
V_47 = V_2 -> V_5 + V_30 ;
V_10 = F_2 ( V_2 , V_30 ,
V_12 -> V_43 ) ;
V_31 = F_26 ( V_12 , V_30 ) ;
if ( V_31 > 0 && V_10 == V_12 -> V_36 [ V_31 ] . V_37 )
continue;
V_12 -> V_48 = 1 ;
V_31 = F_27 ( V_12 , V_47 , V_10 ) ;
V_12 -> V_48 = 0 ;
if ( V_31 )
return V_31 ;
F_28 ( V_12 -> V_49 , L_1 ,
V_47 , V_10 ) ;
}
}
return 0 ;
}
