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
struct V_13 * V_13 )
{
T_1 V_14 ;
F_8 ( V_13 ) ;
F_9 () ;
F_10 ( & V_2 -> V_15 ) ;
for ( V_14 = 0 ; V_14 < V_4 -> V_8 ; ++ V_14 ) {
struct V_13 * V_16 ;
V_16 = F_11 ( V_4 -> V_10 [ V_14 ] ,
F_12 ( V_2 ) ) ;
if ( V_16 -> V_17 == V_13 -> V_17 ) {
F_13 ( V_4 -> V_10 [ V_14 ] , V_13 ) ;
F_14 ( & V_2 -> V_15 ) ;
F_15 () ;
F_16 ( V_16 ) ;
return;
}
}
F_13 ( V_4 -> V_10 [ V_4 -> V_8 ] , V_13 ) ;
V_4 -> V_8 ++ ;
F_14 ( & V_2 -> V_15 ) ;
F_15 () ;
}
static void
F_17 ( struct V_1 * V_2 ,
struct V_3 * V_5 ,
struct V_3 * V_4 ,
struct V_13 * V_13 )
{
unsigned V_14 ;
struct V_13 * V_16 = NULL ;
F_8 ( V_13 ) ;
if ( ! V_5 ) {
F_13 ( V_4 -> V_10 [ 0 ] , V_13 ) ;
V_4 -> V_8 = 1 ;
goto V_18;
}
V_4 -> V_8 = V_5 -> V_8 ;
for ( V_14 = 0 ; V_14 < V_5 -> V_8 ; ++ V_14 ) {
struct V_13 * V_19 ;
V_19 = F_11 ( V_5 -> V_10 [ V_14 ] ,
F_12 ( V_2 ) ) ;
if ( ! V_16 && V_19 -> V_17 == V_13 -> V_17 ) {
V_16 = V_19 ;
F_13 ( V_4 -> V_10 [ V_14 ] , V_13 ) ;
} else
F_13 ( V_4 -> V_10 [ V_14 ] , V_19 ) ;
}
if ( ! V_16 ) {
F_13 ( V_4 -> V_10 [ V_4 -> V_8 ] , V_13 ) ;
V_4 -> V_8 ++ ;
}
V_18:
F_9 () ;
F_10 ( & V_2 -> V_15 ) ;
F_13 ( V_2 -> V_13 , V_4 ) ;
F_14 ( & V_2 -> V_15 ) ;
F_15 () ;
if ( V_5 )
F_18 ( V_5 , V_20 ) ;
if ( V_16 )
F_16 ( V_16 ) ;
}
void F_19 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
struct V_3 * V_5 , * V_4 = V_2 -> V_9 ;
V_5 = F_2 ( V_2 ) ;
V_2 -> V_9 = NULL ;
if ( ! V_4 ) {
F_20 ( V_5 -> V_8 >= V_5 -> V_7 ) ;
F_7 ( V_2 , V_5 , V_13 ) ;
} else
F_17 ( V_2 , V_5 , V_4 , V_13 ) ;
}
void F_21 ( struct V_1 * V_2 ,
struct V_13 * V_13 )
{
struct V_13 * V_16 = F_22 ( V_2 ) ;
struct V_3 * V_5 ;
T_1 V_14 = 0 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
V_14 = V_5 -> V_8 ;
if ( V_13 )
F_8 ( V_13 ) ;
F_9 () ;
F_10 ( & V_2 -> V_15 ) ;
F_13 ( V_2 -> V_21 , V_13 ) ;
if ( V_5 )
V_5 -> V_8 = 0 ;
F_14 ( & V_2 -> V_15 ) ;
F_15 () ;
while ( V_14 -- )
F_16 ( F_11 ( V_5 -> V_10 [ V_14 ] ,
F_12 ( V_2 ) ) ) ;
if ( V_16 )
F_16 ( V_16 ) ;
}
int F_23 ( struct V_1 * V_2 ,
struct V_13 * * V_22 ,
unsigned * V_23 ,
struct V_13 * * * V_24 )
{
unsigned V_8 = 0 ;
unsigned V_25 = 1 ;
struct V_13 * * V_10 = NULL , * V_21 = NULL ;
int V_26 = 0 ;
while ( V_25 ) {
struct V_3 * V_4 ;
unsigned V_15 ;
V_15 = F_24 ( & V_2 -> V_15 ) ;
F_25 () ;
V_4 = F_26 ( V_2 -> V_13 ) ;
if ( V_4 ) {
struct V_13 * * V_27 ;
T_2 V_28 = sizeof( * V_10 ) * V_4 -> V_7 ;
V_27 = F_4 ( V_10 , V_28 ,
V_29 | V_30 ) ;
if ( ! V_27 ) {
F_27 () ;
V_27 = F_4 ( V_10 , V_28 , V_11 ) ;
if ( V_27 ) {
V_10 = V_27 ;
continue;
}
V_26 = - V_12 ;
V_8 = 0 ;
break;
}
V_10 = V_27 ;
memcpy ( V_10 , V_4 -> V_10 , V_28 ) ;
V_8 = V_4 -> V_8 ;
} else
V_8 = 0 ;
V_21 = F_26 ( V_2 -> V_21 ) ;
V_25 = F_28 ( & V_2 -> V_15 , V_15 ) ;
if ( V_25 )
goto V_31;
if ( ! V_21 || F_29 ( V_21 ) ) {
unsigned V_14 ;
for ( V_14 = 0 ; V_14 < V_8 ; ++ V_14 ) {
if ( F_29 ( V_10 [ V_14 ] ) )
continue;
while ( V_14 -- )
F_16 ( V_10 [ V_14 ] ) ;
if ( V_21 ) {
F_16 ( V_21 ) ;
V_21 = NULL ;
}
V_25 = 1 ;
break;
}
} else
V_25 = 1 ;
V_31:
F_27 () ;
}
* V_23 = V_8 ;
if ( V_8 )
* V_24 = V_10 ;
else {
* V_24 = NULL ;
F_3 ( V_10 ) ;
}
* V_22 = V_21 ;
return V_26 ;
}
long F_30 ( struct V_1 * V_2 ,
bool V_32 , bool V_33 ,
unsigned long V_34 )
{
struct V_13 * V_13 ;
unsigned V_15 , V_8 , V_14 = 0 ;
long V_26 = V_34 ;
V_25:
V_13 = NULL ;
V_8 = 0 ;
V_15 = F_24 ( & V_2 -> V_15 ) ;
F_25 () ;
if ( V_32 ) {
struct V_3 * V_4 = F_26 ( V_2 -> V_13 ) ;
if ( V_4 )
V_8 = V_4 -> V_8 ;
if ( F_28 ( & V_2 -> V_15 , V_15 ) )
goto V_35;
for ( V_14 = 0 ; V_14 < V_8 ; ++ V_14 ) {
struct V_13 * V_36 = F_26 ( V_4 -> V_10 [ V_14 ] ) ;
if ( F_31 ( V_37 , & V_36 -> V_38 ) )
continue;
if ( ! F_29 ( V_36 ) )
goto V_35;
if ( F_32 ( V_36 ) ) {
F_16 ( V_36 ) ;
continue;
}
V_13 = V_36 ;
break;
}
}
if ( ! V_8 ) {
struct V_13 * V_21 = F_26 ( V_2 -> V_21 ) ;
if ( F_28 ( & V_2 -> V_15 , V_15 ) )
goto V_35;
if ( V_21 &&
! F_31 ( V_37 , & V_21 -> V_38 ) ) {
if ( ! F_29 ( V_21 ) )
goto V_35;
if ( F_32 ( V_21 ) )
F_16 ( V_21 ) ;
else
V_13 = V_21 ;
}
}
F_27 () ;
if ( V_13 ) {
V_26 = F_33 ( V_13 , V_33 , V_26 ) ;
F_16 ( V_13 ) ;
if ( V_26 > 0 && V_32 && ( V_14 + 1 < V_8 ) )
goto V_25;
}
return V_26 ;
V_35:
F_27 () ;
goto V_25;
}
static inline int
F_34 ( struct V_13 * V_39 )
{
struct V_13 * V_13 , * V_36 = V_39 ;
int V_26 = 1 ;
if ( ! F_31 ( V_37 , & V_36 -> V_38 ) ) {
int V_26 ;
V_13 = F_29 ( V_36 ) ;
if ( ! V_13 )
return - 1 ;
V_26 = ! ! F_32 ( V_13 ) ;
F_16 ( V_13 ) ;
}
return V_26 ;
}
bool F_35 ( struct V_1 * V_2 ,
bool V_40 )
{
unsigned V_15 , V_8 ;
int V_26 = true ;
V_25:
V_8 = 0 ;
V_15 = F_24 ( & V_2 -> V_15 ) ;
F_25 () ;
if ( V_40 ) {
unsigned V_14 ;
struct V_3 * V_4 = F_26 ( V_2 -> V_13 ) ;
if ( V_4 )
V_8 = V_4 -> V_8 ;
if ( F_28 ( & V_2 -> V_15 , V_15 ) )
goto V_35;
for ( V_14 = 0 ; V_14 < V_8 ; ++ V_14 ) {
struct V_13 * V_13 = F_26 ( V_4 -> V_10 [ V_14 ] ) ;
V_26 = F_34 ( V_13 ) ;
if ( V_26 < 0 )
goto V_35;
else if ( ! V_26 )
break;
}
}
if ( ! V_8 ) {
struct V_13 * V_21 = F_26 ( V_2 -> V_21 ) ;
if ( F_28 ( & V_2 -> V_15 , V_15 ) )
goto V_35;
if ( V_21 ) {
V_26 = F_34 ( V_21 ) ;
if ( V_26 < 0 )
goto V_35;
}
}
F_27 () ;
return V_26 ;
V_35:
F_27 () ;
goto V_25;
}
