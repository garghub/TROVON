void
F_1 (
struct V_1 * V_2 ,
T_1 V_3 ,
T_2 V_4 ,
T_3 V_5 ,
unsigned int V_6 )
{
struct V_7 * V_8 ;
struct V_7 * V_9 ;
struct V_10 * V_11 ;
struct V_12 * * V_13 ;
struct V_12 * V_14 = NULL ;
V_8 = F_2 ( sizeof( struct V_7 ) , V_15 ) ;
if ( ! V_8 ) {
F_3 ( V_2 -> V_16 , V_3 , V_4 , V_5 ) ;
F_4 ( V_2 ) ;
return;
}
V_8 -> V_3 = V_3 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_17 = V_5 ;
F_5 ( & V_8 -> V_18 ) ;
V_8 -> V_6 = V_6 ;
F_6 ( V_2 -> V_16 , V_3 , V_4 , V_5 ) ;
V_11 = F_7 ( V_2 -> V_16 , V_8 -> V_3 ) ;
F_8 ( & V_11 -> V_19 ) ;
V_13 = & V_11 -> V_20 . V_12 ;
while ( * V_13 ) {
V_14 = * V_13 ;
V_9 = F_9 ( V_14 , struct V_7 , V_12 ) ;
if ( V_8 -> V_4 < V_9 -> V_4 ) {
V_13 = & ( * V_13 ) -> V_21 ;
ASSERT ( V_8 -> V_4 + V_8 -> V_17 <= V_9 -> V_4 ) ;
} else if ( V_8 -> V_4 > V_9 -> V_4 ) {
V_13 = & ( * V_13 ) -> V_22 ;
ASSERT ( V_4 >= V_9 -> V_4 + V_9 -> V_17 ) ;
} else {
ASSERT ( 0 ) ;
}
}
F_10 ( & V_8 -> V_12 , V_14 , V_13 ) ;
F_11 ( & V_8 -> V_12 , & V_11 -> V_20 ) ;
F_12 ( & V_8 -> V_18 , & V_2 -> V_23 ) ;
F_13 ( & V_11 -> V_19 ) ;
F_14 ( V_11 ) ;
}
int
F_15 (
struct V_24 * V_25 ,
T_1 V_3 ,
T_2 V_4 ,
T_3 V_5 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_7 * V_9 ;
int V_26 = 0 ;
V_11 = F_7 ( V_25 , V_3 ) ;
F_8 ( & V_11 -> V_19 ) ;
V_13 = V_11 -> V_20 . V_12 ;
while ( V_13 ) {
V_9 = F_9 ( V_13 , struct V_7 , V_12 ) ;
if ( V_4 < V_9 -> V_4 ) {
if ( V_4 + V_5 > V_9 -> V_4 )
V_26 = - 1 ;
V_13 = V_13 -> V_21 ;
} else if ( V_4 > V_9 -> V_4 ) {
if ( V_4 < V_9 -> V_4 + V_9 -> V_17 )
V_26 = - 1 ;
V_13 = V_13 -> V_22 ;
} else {
V_26 = ( V_9 -> V_17 == V_5 ) ? 1 : - 1 ;
break;
}
}
F_13 ( & V_11 -> V_19 ) ;
F_14 ( V_11 ) ;
return V_26 ;
}
STATIC bool
F_16 (
struct V_24 * V_25 ,
struct V_10 * V_11 ,
struct V_7 * V_9 ,
T_2 V_27 ,
T_3 V_28 ,
bool V_29 ) __releases( &pag->pagb_lock
void
F_17 (
struct V_24 * V_25 ,
T_1 V_3 ,
T_2 V_27 ,
T_3 V_28 ,
bool V_29 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
ASSERT ( V_28 > 0 ) ;
V_11 = F_7 ( V_25 , V_3 ) ;
F_8 ( & V_11 -> V_19 ) ;
V_30:
V_13 = V_11 -> V_20 . V_12 ;
while ( V_13 ) {
struct V_7 * V_9 =
F_9 ( V_13 , struct V_7 , V_12 ) ;
T_2 V_31 = V_9 -> V_4 ;
T_2 V_32 = V_31 + V_9 -> V_17 ;
if ( V_27 + V_28 <= V_31 ) {
V_13 = V_13 -> V_21 ;
continue;
} else if ( V_27 >= V_32 ) {
V_13 = V_13 -> V_22 ;
continue;
}
if ( ! F_16 ( V_25 , V_11 , V_9 , V_27 , V_28 ,
V_29 ) )
goto V_30;
}
F_13 ( & V_11 -> V_19 ) ;
F_14 ( V_11 ) ;
}
void
F_18 (
struct V_33 * args ,
T_2 V_4 ,
T_3 V_5 ,
T_2 * V_34 ,
T_3 * V_35 )
{
T_2 V_27 ;
T_3 V_28 ;
struct V_12 * V_13 ;
ASSERT ( V_5 > 0 ) ;
F_8 ( & args -> V_11 -> V_19 ) ;
V_30:
V_27 = V_4 ;
V_28 = V_5 ;
V_13 = args -> V_11 -> V_20 . V_12 ;
while ( V_13 && V_28 >= args -> V_36 ) {
struct V_7 * V_9 =
F_9 ( V_13 , struct V_7 , V_12 ) ;
T_2 V_37 = V_27 + V_28 ;
T_2 V_31 = V_9 -> V_4 ;
T_2 V_32 = V_31 + V_9 -> V_17 ;
if ( V_37 <= V_31 ) {
V_13 = V_13 -> V_21 ;
continue;
} else if ( V_27 >= V_32 ) {
V_13 = V_13 -> V_22 ;
continue;
}
if ( ! F_19 ( args -> V_38 ) &&
! ( V_9 -> V_6 & V_39 ) ) {
if ( ! F_16 ( args -> V_25 , args -> V_11 ,
V_9 , V_27 , V_28 ,
false ) )
goto V_30;
continue;
}
if ( V_31 <= V_27 ) {
if ( V_37 <= V_32 )
goto V_40;
V_27 = V_32 ;
} else if ( V_32 >= V_37 ) {
V_37 = V_31 ;
} else {
if ( V_31 - V_27 >= args -> V_41 ) {
V_37 = V_31 ;
} else if ( V_37 - V_32 >= args -> V_41 * 4 ) {
V_27 = V_32 ;
} else if ( V_31 - V_27 >= args -> V_36 ) {
V_37 = V_31 ;
} else {
goto V_40;
}
}
V_28 = V_37 - V_27 ;
}
F_13 ( & args -> V_11 -> V_19 ) ;
if ( V_27 != V_4 || V_28 != V_5 ) {
F_20 ( args -> V_25 , args -> V_3 , V_4 , V_5 ,
V_27 , V_28 ) ;
}
* V_34 = V_27 ;
* V_35 = V_28 ;
return;
V_40:
F_13 ( & args -> V_11 -> V_19 ) ;
F_20 ( args -> V_25 , args -> V_3 , V_4 , V_5 , V_27 , 0 ) ;
* V_34 = V_27 ;
* V_35 = 0 ;
}
STATIC void
F_21 (
struct V_24 * V_25 ,
struct V_10 * V_11 ,
struct V_7 * V_9 )
{
if ( V_9 -> V_17 ) {
F_22 ( V_25 , V_9 -> V_3 , V_9 -> V_4 ,
V_9 -> V_17 ) ;
F_23 ( & V_9 -> V_12 , & V_11 -> V_20 ) ;
}
F_24 ( & V_9 -> V_18 ) ;
F_25 ( V_9 ) ;
}
void
F_26 (
struct V_24 * V_25 ,
struct V_42 * V_18 ,
bool V_43 )
{
struct V_7 * V_9 , * V_44 ;
struct V_10 * V_11 = NULL ;
T_1 V_3 = V_45 ;
F_27 (busyp, n, list, list) {
if ( V_9 -> V_3 != V_3 ) {
if ( V_11 ) {
F_13 ( & V_11 -> V_19 ) ;
F_14 ( V_11 ) ;
}
V_11 = F_7 ( V_25 , V_9 -> V_3 ) ;
F_8 ( & V_11 -> V_19 ) ;
V_3 = V_9 -> V_3 ;
}
if ( V_43 && V_9 -> V_17 &&
! ( V_9 -> V_6 & V_46 ) )
V_9 -> V_6 = V_39 ;
else
F_21 ( V_25 , V_11 , V_9 ) ;
}
if ( V_11 ) {
F_13 ( & V_11 -> V_19 ) ;
F_14 ( V_11 ) ;
}
}
int
F_28 (
void * V_47 ,
struct V_42 * V_48 ,
struct V_42 * V_49 )
{
return F_29 ( V_48 , struct V_7 , V_18 ) -> V_3 -
F_29 ( V_49 , struct V_7 , V_18 ) -> V_3 ;
}
