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
V_8 -> V_3 = V_3 ;
V_8 -> V_4 = V_4 ;
V_8 -> V_16 = V_5 ;
F_3 ( & V_8 -> V_17 ) ;
V_8 -> V_6 = V_6 ;
F_4 ( V_2 -> V_18 , V_3 , V_4 , V_5 ) ;
V_11 = F_5 ( V_2 -> V_18 , V_8 -> V_3 ) ;
F_6 ( & V_11 -> V_19 ) ;
V_13 = & V_11 -> V_20 . V_12 ;
while ( * V_13 ) {
V_14 = * V_13 ;
V_9 = F_7 ( V_14 , struct V_7 , V_12 ) ;
if ( V_8 -> V_4 < V_9 -> V_4 ) {
V_13 = & ( * V_13 ) -> V_21 ;
ASSERT ( V_8 -> V_4 + V_8 -> V_16 <= V_9 -> V_4 ) ;
} else if ( V_8 -> V_4 > V_9 -> V_4 ) {
V_13 = & ( * V_13 ) -> V_22 ;
ASSERT ( V_4 >= V_9 -> V_4 + V_9 -> V_16 ) ;
} else {
ASSERT ( 0 ) ;
}
}
F_8 ( & V_8 -> V_12 , V_14 , V_13 ) ;
F_9 ( & V_8 -> V_12 , & V_11 -> V_20 ) ;
F_10 ( & V_8 -> V_17 , & V_2 -> V_23 ) ;
F_11 ( & V_11 -> V_19 ) ;
F_12 ( V_11 ) ;
}
int
F_13 (
struct V_24 * V_25 ,
T_1 V_3 ,
T_2 V_4 ,
T_3 V_5 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
struct V_7 * V_9 ;
int V_26 = 0 ;
V_11 = F_5 ( V_25 , V_3 ) ;
F_6 ( & V_11 -> V_19 ) ;
V_13 = V_11 -> V_20 . V_12 ;
while ( V_13 ) {
V_9 = F_7 ( V_13 , struct V_7 , V_12 ) ;
if ( V_4 < V_9 -> V_4 ) {
if ( V_4 + V_5 > V_9 -> V_4 )
V_26 = - 1 ;
V_13 = V_13 -> V_21 ;
} else if ( V_4 > V_9 -> V_4 ) {
if ( V_4 < V_9 -> V_4 + V_9 -> V_16 )
V_26 = - 1 ;
V_13 = V_13 -> V_22 ;
} else {
V_26 = ( V_9 -> V_16 == V_5 ) ? 1 : - 1 ;
break;
}
}
F_11 ( & V_11 -> V_19 ) ;
F_12 ( V_11 ) ;
return V_26 ;
}
STATIC bool
F_14 (
struct V_24 * V_25 ,
struct V_10 * V_11 ,
struct V_7 * V_9 ,
T_2 V_27 ,
T_3 V_28 ,
bool V_29 ) __releases( &pag->pagb_lock
void
F_15 (
struct V_24 * V_25 ,
T_1 V_3 ,
T_2 V_27 ,
T_3 V_28 ,
bool V_29 )
{
struct V_10 * V_11 ;
struct V_12 * V_13 ;
ASSERT ( V_28 > 0 ) ;
V_11 = F_5 ( V_25 , V_3 ) ;
F_6 ( & V_11 -> V_19 ) ;
V_30:
V_13 = V_11 -> V_20 . V_12 ;
while ( V_13 ) {
struct V_7 * V_9 =
F_7 ( V_13 , struct V_7 , V_12 ) ;
T_2 V_31 = V_9 -> V_4 ;
T_2 V_32 = V_31 + V_9 -> V_16 ;
if ( V_27 + V_28 <= V_31 ) {
V_13 = V_13 -> V_21 ;
continue;
} else if ( V_27 >= V_32 ) {
V_13 = V_13 -> V_22 ;
continue;
}
if ( ! F_14 ( V_25 , V_11 , V_9 , V_27 , V_28 ,
V_29 ) )
goto V_30;
}
F_11 ( & V_11 -> V_19 ) ;
F_12 ( V_11 ) ;
}
bool
F_16 (
struct V_33 * args ,
T_2 * V_4 ,
T_3 * V_5 ,
unsigned * V_34 )
{
T_2 V_27 ;
T_3 V_28 ;
struct V_12 * V_13 ;
bool V_35 = false ;
ASSERT ( * V_5 > 0 ) ;
F_6 ( & args -> V_11 -> V_19 ) ;
V_30:
V_27 = * V_4 ;
V_28 = * V_5 ;
V_13 = args -> V_11 -> V_20 . V_12 ;
while ( V_13 && V_28 >= args -> V_36 ) {
struct V_7 * V_9 =
F_7 ( V_13 , struct V_7 , V_12 ) ;
T_2 V_37 = V_27 + V_28 ;
T_2 V_31 = V_9 -> V_4 ;
T_2 V_32 = V_31 + V_9 -> V_16 ;
if ( V_37 <= V_31 ) {
V_13 = V_13 -> V_21 ;
continue;
} else if ( V_27 >= V_32 ) {
V_13 = V_13 -> V_22 ;
continue;
}
if ( ! F_17 ( args -> V_38 ) &&
! ( V_9 -> V_6 & V_39 ) ) {
if ( ! F_14 ( args -> V_25 , args -> V_11 ,
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
V_42:
if ( V_27 != * V_4 || V_28 != * V_5 ) {
F_18 ( args -> V_25 , args -> V_3 , * V_4 , * V_5 ,
V_27 , V_28 ) ;
* V_4 = V_27 ;
* V_5 = V_28 ;
* V_34 = args -> V_11 -> V_43 ;
V_35 = true ;
}
F_11 ( & args -> V_11 -> V_19 ) ;
return V_35 ;
V_40:
V_28 = 0 ;
goto V_42;
}
STATIC void
F_19 (
struct V_24 * V_25 ,
struct V_10 * V_11 ,
struct V_7 * V_9 )
{
if ( V_9 -> V_16 ) {
F_20 ( V_25 , V_9 -> V_3 , V_9 -> V_4 ,
V_9 -> V_16 ) ;
F_21 ( & V_9 -> V_12 , & V_11 -> V_20 ) ;
}
F_22 ( & V_9 -> V_17 ) ;
F_23 ( V_9 ) ;
}
static void
F_24 (
struct V_10 * V_11 ,
bool V_44 )
__releases( V_11 -> V_19 )
{
if ( V_44 ) {
V_11 -> V_43 ++ ;
F_25 ( & V_11 -> V_45 ) ;
}
F_11 ( & V_11 -> V_19 ) ;
F_12 ( V_11 ) ;
}
void
F_26 (
struct V_24 * V_25 ,
struct V_46 * V_17 ,
bool V_47 )
{
struct V_7 * V_9 , * V_48 ;
struct V_10 * V_11 = NULL ;
T_1 V_3 = V_49 ;
bool V_44 = false ;
F_27 (busyp, n, list, list) {
if ( V_9 -> V_3 != V_3 ) {
if ( V_11 )
F_24 ( V_11 , V_44 ) ;
V_3 = V_9 -> V_3 ;
V_11 = F_5 ( V_25 , V_3 ) ;
F_6 ( & V_11 -> V_19 ) ;
V_44 = false ;
}
if ( V_47 && V_9 -> V_16 &&
! ( V_9 -> V_6 & V_50 ) ) {
V_9 -> V_6 = V_39 ;
} else {
F_19 ( V_25 , V_11 , V_9 ) ;
V_44 = true ;
}
}
if ( V_11 )
F_24 ( V_11 , V_44 ) ;
}
void
F_28 (
struct V_24 * V_25 ,
struct V_10 * V_11 ,
unsigned V_34 )
{
F_29 ( V_51 ) ;
int V_52 = 0 , error ;
F_30 ( V_25 , 0 , V_53 ) ;
error = F_31 ( V_25 , V_54 , & V_52 ) ;
if ( error )
return;
do {
F_32 ( & V_11 -> V_45 , & V_51 , V_55 ) ;
if ( V_34 != F_33 ( V_11 -> V_43 ) )
break;
F_34 () ;
} while ( 1 );
F_35 ( & V_11 -> V_45 , & V_51 ) ;
}
void
F_36 (
struct V_24 * V_25 )
{
F_29 ( V_51 ) ;
T_1 V_3 ;
for ( V_3 = 0 ; V_3 < V_25 -> V_56 . V_57 ; V_3 ++ ) {
struct V_10 * V_11 = F_5 ( V_25 , V_3 ) ;
do {
F_32 ( & V_11 -> V_45 , & V_51 , V_55 ) ;
if ( F_37 ( & V_11 -> V_20 ) )
break;
F_34 () ;
} while ( 1 );
F_35 ( & V_11 -> V_45 , & V_51 ) ;
F_12 ( V_11 ) ;
}
}
int
F_38 (
void * V_58 ,
struct V_46 * V_59 ,
struct V_46 * V_60 )
{
struct V_7 * V_61 =
F_39 ( V_59 , struct V_7 , V_17 ) ;
struct V_7 * V_62 =
F_39 ( V_60 , struct V_7 , V_17 ) ;
T_4 V_63 ;
V_63 = V_61 -> V_3 - V_62 -> V_3 ;
if ( ! V_63 )
V_63 = V_61 -> V_4 - V_62 -> V_4 ;
return V_63 ;
}
