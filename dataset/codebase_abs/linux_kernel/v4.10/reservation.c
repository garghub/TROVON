int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
T_1 V_6 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 && V_5 -> V_7 ) {
if ( V_5 -> V_8 < V_5 -> V_7 ) {
F_3 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
return 0 ;
} else
V_6 = V_5 -> V_7 * 2 ;
} else
V_6 = 4 ;
V_4 = F_4 ( V_2 -> V_9 , F_5 ( F_6 ( * V_4 ) , V_10 [ V_6 ] ) ,
V_11 ) ;
if ( ! V_4 )
return - V_12 ;
V_2 -> V_9 = V_4 ;
V_4 -> V_7 = V_6 ;
return 0 ;
}
static void
F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_13 * V_14 )
{
T_1 V_15 ;
F_8 ( V_14 ) ;
F_9 () ;
F_10 ( & V_2 -> V_16 ) ;
for ( V_15 = 0 ; V_15 < V_4 -> V_8 ; ++ V_15 ) {
struct V_13 * V_17 ;
V_17 = F_11 ( V_4 -> V_10 [ V_15 ] ,
F_12 ( V_2 ) ) ;
if ( V_17 -> V_18 == V_14 -> V_18 ) {
F_13 ( V_4 -> V_10 [ V_15 ] , V_14 ) ;
F_14 ( & V_2 -> V_16 ) ;
F_15 () ;
F_16 ( V_17 ) ;
return;
}
}
F_13 ( V_4 -> V_10 [ V_4 -> V_8 ] , V_14 ) ;
V_4 -> V_8 ++ ;
F_14 ( & V_2 -> V_16 ) ;
F_15 () ;
}
static void
F_17 ( struct V_1 * V_2 ,
struct V_3 * V_5 ,
struct V_3 * V_4 ,
struct V_13 * V_14 )
{
unsigned V_15 ;
struct V_13 * V_17 = NULL ;
F_8 ( V_14 ) ;
if ( ! V_5 ) {
F_13 ( V_4 -> V_10 [ 0 ] , V_14 ) ;
V_4 -> V_8 = 1 ;
goto V_19;
}
V_4 -> V_8 = V_5 -> V_8 ;
for ( V_15 = 0 ; V_15 < V_5 -> V_8 ; ++ V_15 ) {
struct V_13 * V_20 ;
V_20 = F_11 ( V_5 -> V_10 [ V_15 ] ,
F_12 ( V_2 ) ) ;
if ( ! V_17 && V_20 -> V_18 == V_14 -> V_18 ) {
V_17 = V_20 ;
F_13 ( V_4 -> V_10 [ V_15 ] , V_14 ) ;
} else
F_13 ( V_4 -> V_10 [ V_15 ] , V_20 ) ;
}
if ( ! V_17 ) {
F_13 ( V_4 -> V_10 [ V_4 -> V_8 ] , V_14 ) ;
V_4 -> V_8 ++ ;
}
V_19:
F_9 () ;
F_10 ( & V_2 -> V_16 ) ;
F_13 ( V_2 -> V_14 , V_4 ) ;
F_14 ( & V_2 -> V_16 ) ;
F_15 () ;
if ( V_5 )
F_18 ( V_5 , V_21 ) ;
if ( V_17 )
F_16 ( V_17 ) ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_3 * V_5 , * V_4 = V_2 -> V_9 ;
V_5 = F_2 ( V_2 ) ;
V_2 -> V_9 = NULL ;
if ( ! V_4 ) {
F_20 ( V_5 -> V_8 >= V_5 -> V_7 ) ;
F_7 ( V_2 , V_5 , V_14 ) ;
} else
F_17 ( V_2 , V_5 , V_4 , V_14 ) ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_13 * V_17 = F_22 ( V_2 ) ;
struct V_3 * V_5 ;
T_1 V_15 = 0 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_15 = V_5 -> V_8 ;
if ( V_14 )
F_8 ( V_14 ) ;
F_9 () ;
F_10 ( & V_2 -> V_16 ) ;
F_13 ( V_2 -> V_22 , V_14 ) ;
if ( V_5 )
V_5 -> V_8 = 0 ;
F_14 ( & V_2 -> V_16 ) ;
F_15 () ;
while ( V_15 -- )
F_16 ( F_11 ( V_5 -> V_10 [ V_15 ] ,
F_12 ( V_2 ) ) ) ;
if ( V_17 )
F_16 ( V_17 ) ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_13 * * V_23 ,
unsigned * V_24 ,
struct V_13 * * * V_25 )
{
struct V_13 * * V_10 = NULL ;
struct V_13 * V_22 ;
unsigned int V_8 ;
int V_26 = 1 ;
do {
struct V_3 * V_4 ;
unsigned V_16 ;
unsigned int V_15 ;
V_8 = V_15 = 0 ;
F_24 () ;
V_16 = F_25 ( & V_2 -> V_16 ) ;
V_22 = F_26 ( V_2 -> V_22 ) ;
if ( V_22 && ! F_27 ( V_22 ) )
goto V_27;
V_4 = F_26 ( V_2 -> V_14 ) ;
if ( V_4 ) {
struct V_13 * * V_28 ;
T_2 V_29 = sizeof( * V_10 ) * V_4 -> V_7 ;
V_28 = F_4 ( V_10 , V_29 ,
V_30 | V_31 ) ;
if ( ! V_28 ) {
F_28 () ;
V_28 = F_4 ( V_10 , V_29 , V_11 ) ;
if ( V_28 ) {
V_10 = V_28 ;
continue;
}
V_26 = - V_12 ;
break;
}
V_10 = V_28 ;
V_8 = V_4 -> V_8 ;
for ( V_15 = 0 ; V_15 < V_8 ; ++ V_15 ) {
V_10 [ V_15 ] = F_26 ( V_4 -> V_10 [ V_15 ] ) ;
if ( ! F_27 ( V_10 [ V_15 ] ) )
break;
}
}
if ( V_15 != V_8 || F_29 ( & V_2 -> V_16 , V_16 ) ) {
while ( V_15 -- )
F_16 ( V_10 [ V_15 ] ) ;
F_16 ( V_22 ) ;
goto V_27;
}
V_26 = 0 ;
V_27:
F_28 () ;
} while ( V_26 );
if ( ! V_8 ) {
F_3 ( V_10 ) ;
V_10 = NULL ;
}
* V_24 = V_8 ;
* V_25 = V_10 ;
* V_23 = V_22 ;
return V_26 ;
}
long F_30 ( struct V_1 * V_2 ,
bool V_32 , bool V_33 ,
unsigned long V_34 )
{
struct V_13 * V_14 ;
unsigned V_16 , V_8 , V_15 = 0 ;
long V_26 = V_34 ? V_34 : 1 ;
V_35:
V_14 = NULL ;
V_8 = 0 ;
V_16 = F_25 ( & V_2 -> V_16 ) ;
F_24 () ;
if ( V_32 ) {
struct V_3 * V_4 =
F_26 ( V_2 -> V_14 ) ;
if ( V_4 )
V_8 = V_4 -> V_8 ;
for ( V_15 = 0 ; V_15 < V_8 ; ++ V_15 ) {
struct V_13 * V_36 = F_26 ( V_4 -> V_10 [ V_15 ] ) ;
if ( F_31 ( V_37 ,
& V_36 -> V_38 ) )
continue;
if ( ! F_27 ( V_36 ) )
goto V_39;
if ( F_32 ( V_36 ) ) {
F_16 ( V_36 ) ;
continue;
}
V_14 = V_36 ;
break;
}
}
if ( ! V_8 ) {
struct V_13 * V_22 = F_26 ( V_2 -> V_22 ) ;
if ( V_22 &&
! F_31 ( V_37 ,
& V_22 -> V_38 ) ) {
if ( ! F_27 ( V_22 ) )
goto V_39;
if ( F_32 ( V_22 ) )
F_16 ( V_22 ) ;
else
V_14 = V_22 ;
}
}
F_28 () ;
if ( V_14 ) {
if ( F_29 ( & V_2 -> V_16 , V_16 ) ) {
F_16 ( V_14 ) ;
goto V_35;
}
V_26 = F_33 ( V_14 , V_33 , V_26 ) ;
F_16 ( V_14 ) ;
if ( V_26 > 0 && V_32 && ( V_15 + 1 < V_8 ) )
goto V_35;
}
return V_26 ;
V_39:
F_28 () ;
goto V_35;
}
static inline int
F_34 ( struct V_13 * V_40 )
{
struct V_13 * V_14 , * V_36 = V_40 ;
int V_26 = 1 ;
if ( ! F_31 ( V_37 , & V_36 -> V_38 ) ) {
V_14 = F_27 ( V_36 ) ;
if ( ! V_14 )
return - 1 ;
V_26 = ! ! F_32 ( V_14 ) ;
F_16 ( V_14 ) ;
}
return V_26 ;
}
bool F_35 ( struct V_1 * V_2 ,
bool V_41 )
{
unsigned V_16 , V_8 ;
int V_26 ;
F_24 () ;
V_35:
V_26 = true ;
V_8 = 0 ;
V_16 = F_25 ( & V_2 -> V_16 ) ;
if ( V_41 ) {
unsigned V_15 ;
struct V_3 * V_4 =
F_26 ( V_2 -> V_14 ) ;
if ( V_4 )
V_8 = V_4 -> V_8 ;
for ( V_15 = 0 ; V_15 < V_8 ; ++ V_15 ) {
struct V_13 * V_14 = F_26 ( V_4 -> V_10 [ V_15 ] ) ;
V_26 = F_34 ( V_14 ) ;
if ( V_26 < 0 )
goto V_35;
else if ( ! V_26 )
break;
}
if ( F_29 ( & V_2 -> V_16 , V_16 ) )
goto V_35;
}
if ( ! V_8 ) {
struct V_13 * V_22 = F_26 ( V_2 -> V_22 ) ;
if ( V_22 ) {
V_26 = F_34 (
V_22 ) ;
if ( V_26 < 0 )
goto V_35;
if ( F_29 ( & V_2 -> V_16 , V_16 ) )
goto V_35;
}
}
F_28 () ;
return V_26 ;
}
