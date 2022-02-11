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
bool V_29 )
{
T_2 V_30 = V_27 + V_28 ;
T_2 V_31 = V_9 -> V_4 ;
T_2 V_32 = V_31 + V_9 -> V_17 ;
if ( V_9 -> V_6 & V_33 ) {
F_13 ( & V_11 -> V_19 ) ;
F_17 ( 1 ) ;
F_8 ( & V_11 -> V_19 ) ;
return false ;
}
if ( V_29 )
goto V_34;
if ( V_31 < V_27 && V_32 > V_30 ) {
goto V_34;
} else if ( V_31 >= V_27 && V_32 <= V_30 ) {
F_18 ( & V_9 -> V_12 , & V_11 -> V_20 ) ;
V_9 -> V_17 = 0 ;
return false ;
} else if ( V_30 < V_32 ) {
V_9 -> V_4 = V_30 ;
} else if ( V_31 < V_27 ) {
V_9 -> V_17 = V_27 - V_9 -> V_4 ;
} else {
ASSERT ( 0 ) ;
}
F_19 ( V_25 , V_11 -> V_35 , V_27 , V_28 ) ;
return true ;
V_34:
F_13 ( & V_11 -> V_19 ) ;
F_20 ( V_25 , V_36 ) ;
F_21 ( V_25 , V_11 -> V_35 , V_27 , V_28 ) ;
F_8 ( & V_11 -> V_19 ) ;
return false ;
}
void
F_22 (
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
V_37:
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
goto V_37;
}
F_13 ( & V_11 -> V_19 ) ;
F_14 ( V_11 ) ;
}
void
F_23 (
struct V_38 * args ,
T_2 V_4 ,
T_3 V_5 ,
T_2 * V_39 ,
T_3 * V_40 )
{
T_2 V_27 ;
T_3 V_28 ;
struct V_12 * V_13 ;
ASSERT ( V_5 > 0 ) ;
F_8 ( & args -> V_11 -> V_19 ) ;
V_37:
V_27 = V_4 ;
V_28 = V_5 ;
V_13 = args -> V_11 -> V_20 . V_12 ;
while ( V_13 && V_28 >= args -> V_41 ) {
struct V_7 * V_9 =
F_9 ( V_13 , struct V_7 , V_12 ) ;
T_2 V_30 = V_27 + V_28 ;
T_2 V_31 = V_9 -> V_4 ;
T_2 V_32 = V_31 + V_9 -> V_17 ;
if ( V_30 <= V_31 ) {
V_13 = V_13 -> V_21 ;
continue;
} else if ( V_27 >= V_32 ) {
V_13 = V_13 -> V_22 ;
continue;
}
if ( ! args -> V_29 &&
! ( V_9 -> V_6 & V_33 ) ) {
if ( ! F_16 ( args -> V_25 , args -> V_11 ,
V_9 , V_27 , V_28 ,
false ) )
goto V_37;
continue;
}
if ( V_31 <= V_27 ) {
if ( V_30 <= V_32 )
goto V_42;
V_27 = V_32 ;
} else if ( V_32 >= V_30 ) {
V_30 = V_31 ;
} else {
if ( V_31 - V_27 >= args -> V_43 ) {
V_30 = V_31 ;
} else if ( V_30 - V_32 >= args -> V_43 * 4 ) {
V_27 = V_32 ;
} else if ( V_31 - V_27 >= args -> V_41 ) {
V_30 = V_31 ;
} else {
goto V_42;
}
}
V_28 = V_30 - V_27 ;
}
F_13 ( & args -> V_11 -> V_19 ) ;
if ( V_27 != V_4 || V_28 != V_5 ) {
F_24 ( args -> V_25 , args -> V_3 , V_4 , V_5 ,
V_27 , V_28 ) ;
}
* V_39 = V_27 ;
* V_40 = V_28 ;
return;
V_42:
F_13 ( & args -> V_11 -> V_19 ) ;
F_24 ( args -> V_25 , args -> V_3 , V_4 , V_5 , V_27 , 0 ) ;
* V_39 = V_27 ;
* V_40 = 0 ;
}
STATIC void
F_25 (
struct V_24 * V_25 ,
struct V_10 * V_11 ,
struct V_7 * V_9 )
{
if ( V_9 -> V_17 ) {
F_26 ( V_25 , V_9 -> V_3 , V_9 -> V_4 ,
V_9 -> V_17 ) ;
F_18 ( & V_9 -> V_12 , & V_11 -> V_20 ) ;
}
F_27 ( & V_9 -> V_18 ) ;
F_28 ( V_9 ) ;
}
void
F_29 (
struct V_24 * V_25 ,
struct V_44 * V_18 ,
bool V_45 )
{
struct V_7 * V_9 , * V_46 ;
struct V_10 * V_11 = NULL ;
T_1 V_3 = V_47 ;
F_30 (busyp, n, list, list) {
if ( V_9 -> V_3 != V_3 ) {
if ( V_11 ) {
F_13 ( & V_11 -> V_19 ) ;
F_14 ( V_11 ) ;
}
V_11 = F_7 ( V_25 , V_9 -> V_3 ) ;
F_8 ( & V_11 -> V_19 ) ;
V_3 = V_9 -> V_3 ;
}
if ( V_45 && V_9 -> V_17 &&
! ( V_9 -> V_6 & V_48 ) )
V_9 -> V_6 = V_33 ;
else
F_25 ( V_25 , V_11 , V_9 ) ;
}
if ( V_11 ) {
F_13 ( & V_11 -> V_19 ) ;
F_14 ( V_11 ) ;
}
}
int
F_31 (
void * V_49 ,
struct V_44 * V_50 ,
struct V_44 * V_51 )
{
return F_32 ( V_50 , struct V_7 , V_18 ) -> V_3 -
F_32 ( V_51 , struct V_7 , V_18 ) -> V_3 ;
}
