static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
if ( V_2 -> V_5 . V_6 ) {
* V_2 -> V_7 [ V_4 ] . V_8 = F_2 ( V_3 ) ;
} else {
F_3 ( V_2 -> V_7 [ V_4 ] . V_9 , V_3 ) ;
}
}
static T_1 F_4 ( struct V_1 * V_2 , int V_4 )
{
T_1 V_3 = 0 ;
if ( V_2 -> V_5 . V_6 ) {
V_3 = F_5 ( * V_2 -> V_7 [ V_4 ] . V_8 ) ;
} else {
V_3 = F_6 ( V_2 -> V_7 [ V_4 ] . V_9 ) ;
}
return V_3 ;
}
int F_7 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
if ( V_11 -> V_3 && V_11 -> V_3 < V_12 ) {
return 0 ;
}
V_11 -> V_3 = ++ V_2 -> V_7 [ V_11 -> V_4 ] . V_3 ;
F_8 ( V_2 , V_11 -> V_4 , V_11 ) ;
F_9 ( V_2 -> V_13 , V_11 -> V_3 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_3 , V_14 ;
unsigned V_15 = 0 ;
bool V_16 = false ;
V_14 = F_11 ( & V_2 -> V_7 [ V_4 ] . V_14 ) ;
do {
V_3 = F_4 ( V_2 , V_4 ) ;
V_3 |= V_14 & 0xffffffff00000000LL ;
if ( V_3 < V_14 ) {
V_3 += 0x100000000LL ;
}
if ( V_3 == V_14 ) {
break;
}
V_16 = true ;
V_14 = V_3 ;
if ( ( V_15 ++ ) > 10 ) {
break;
}
} while ( F_12 ( & V_2 -> V_7 [ V_4 ] . V_14 , V_3 ) > V_3 );
if ( V_16 ) {
V_2 -> V_7 [ V_4 ] . V_17 = V_18 ;
F_13 ( & V_2 -> V_19 ) ;
}
}
static void F_14 ( struct V_20 * V_20 )
{
struct V_10 * V_11 ;
V_11 = F_15 ( V_20 , struct V_10 , V_20 ) ;
V_11 -> V_3 = V_12 ;
F_16 ( V_11 ) ;
}
int F_17 ( struct V_1 * V_2 ,
struct V_10 * * V_11 ,
int V_4 )
{
* V_11 = F_18 ( sizeof( struct V_10 ) , V_21 ) ;
if ( ( * V_11 ) == NULL ) {
return - V_22 ;
}
F_19 ( & ( ( * V_11 ) -> V_20 ) ) ;
( * V_11 ) -> V_2 = V_2 ;
( * V_11 ) -> V_3 = V_12 ;
( * V_11 ) -> V_4 = V_4 ;
return 0 ;
}
static bool F_20 ( struct V_1 * V_2 ,
T_3 V_3 , unsigned V_4 )
{
if ( F_11 ( & V_2 -> V_7 [ V_4 ] . V_14 ) >= V_3 ) {
return true ;
}
F_10 ( V_2 , V_4 ) ;
if ( F_11 ( & V_2 -> V_7 [ V_4 ] . V_14 ) >= V_3 ) {
return true ;
}
return false ;
}
bool F_21 ( struct V_10 * V_11 )
{
if ( ! V_11 ) {
return true ;
}
if ( V_11 -> V_3 == V_12 ) {
F_22 ( 1 , L_1 , V_11 ) ;
return true ;
}
if ( V_11 -> V_3 == V_23 ) {
return true ;
}
if ( F_20 ( V_11 -> V_2 , V_11 -> V_3 , V_11 -> V_4 ) ) {
V_11 -> V_3 = V_23 ;
return true ;
}
return false ;
}
static int F_23 ( struct V_1 * V_2 , T_3 V_24 ,
unsigned V_4 , bool V_25 , bool V_26 )
{
unsigned long V_27 , V_17 ;
T_2 V_3 ;
unsigned V_28 ;
bool V_29 ;
int V_30 ;
while ( V_24 > F_11 ( & V_2 -> V_7 [ V_4 ] . V_14 ) ) {
if ( ! V_2 -> V_4 [ V_4 ] . V_31 ) {
return - V_32 ;
}
V_27 = V_18 - V_33 ;
if ( F_24 ( V_2 -> V_7 [ V_4 ] . V_17 , V_27 ) ) {
V_27 = V_2 -> V_7 [ V_4 ] . V_17 - V_27 ;
} else {
V_27 = 1 ;
}
V_3 = F_11 ( & V_2 -> V_7 [ V_4 ] . V_14 ) ;
V_17 = V_2 -> V_7 [ V_4 ] . V_17 ;
F_25 ( V_2 -> V_13 , V_3 ) ;
F_26 ( V_2 , V_4 ) ;
if ( V_25 ) {
V_30 = F_27 ( V_2 -> V_19 ,
( V_29 = F_20 ( V_2 , V_24 , V_4 ) ) ,
V_27 ) ;
} else {
V_30 = F_28 ( V_2 -> V_19 ,
( V_29 = F_20 ( V_2 , V_24 , V_4 ) ) ,
V_27 ) ;
}
F_29 ( V_2 , V_4 ) ;
if ( F_30 ( V_30 < 0 ) ) {
return V_30 ;
}
F_31 ( V_2 -> V_13 , V_3 ) ;
if ( F_30 ( ! V_29 ) ) {
if ( V_30 ) {
continue;
}
if ( V_3 != F_11 ( & V_2 -> V_7 [ V_4 ] . V_14 ) ) {
continue;
}
if ( V_26 ) {
F_32 ( & V_2 -> V_34 ) ;
}
if ( V_17 != V_2 -> V_7 [ V_4 ] . V_17 ) {
if ( V_26 ) {
F_33 ( & V_2 -> V_34 ) ;
}
continue;
}
if ( F_34 ( V_2 , V_4 , & V_2 -> V_4 [ V_4 ] ) ) {
F_35 ( V_2 -> V_35 , L_2 ,
V_24 , V_3 ) ;
for ( V_28 = 0 ; V_28 < V_36 ; ++ V_28 ) {
V_2 -> V_7 [ V_28 ] . V_17 = V_18 ;
}
V_2 -> V_4 [ V_4 ] . V_31 = false ;
if ( V_26 ) {
F_33 ( & V_2 -> V_34 ) ;
}
return - V_37 ;
}
if ( V_26 ) {
F_33 ( & V_2 -> V_34 ) ;
}
}
}
return 0 ;
}
int F_36 ( struct V_10 * V_11 , bool V_25 )
{
int V_30 ;
if ( V_11 == NULL ) {
F_22 ( 1 , L_3 , V_11 ) ;
return - V_38 ;
}
V_30 = F_23 ( V_11 -> V_2 , V_11 -> V_3 ,
V_11 -> V_4 , V_25 , true ) ;
if ( V_30 ) {
return V_30 ;
}
V_11 -> V_3 = V_23 ;
return 0 ;
}
bool F_37 ( struct V_1 * V_2 , T_3 * V_3 )
{
unsigned V_28 ;
for ( V_28 = 0 ; V_28 < V_36 ; ++ V_28 ) {
if ( V_3 [ V_28 ] && F_20 ( V_2 , V_3 [ V_28 ] , V_28 ) ) {
return true ;
}
}
return false ;
}
static int F_38 ( struct V_1 * V_2 ,
T_3 * V_24 , bool V_25 )
{
unsigned long V_27 , V_17 , V_39 ;
unsigned V_28 , V_4 = V_36 ;
bool V_29 ;
int V_30 ;
for ( V_28 = 0 , V_17 = 0 ; V_28 < V_36 ; ++ V_28 ) {
if ( ! V_24 [ V_28 ] ) {
continue;
}
if ( F_24 ( V_2 -> V_7 [ V_28 ] . V_17 , V_17 ) ) {
V_17 = V_2 -> V_7 [ V_28 ] . V_17 ;
}
if ( V_28 < V_4 ) {
V_4 = V_28 ;
}
}
if ( V_4 == V_36 ) {
return 0 ;
}
while ( ! F_37 ( V_2 , V_24 ) ) {
V_27 = V_18 - V_33 ;
if ( F_24 ( V_17 , V_27 ) ) {
V_27 = V_17 - V_27 ;
} else {
V_27 = 1 ;
}
F_25 ( V_2 -> V_13 , V_24 [ V_4 ] ) ;
for ( V_28 = 0 ; V_28 < V_36 ; ++ V_28 ) {
if ( V_24 [ V_28 ] ) {
F_26 ( V_2 , V_28 ) ;
}
}
if ( V_25 ) {
V_30 = F_27 ( V_2 -> V_19 ,
( V_29 = F_37 ( V_2 , V_24 ) ) ,
V_27 ) ;
} else {
V_30 = F_28 ( V_2 -> V_19 ,
( V_29 = F_37 ( V_2 , V_24 ) ) ,
V_27 ) ;
}
for ( V_28 = 0 ; V_28 < V_36 ; ++ V_28 ) {
if ( V_24 [ V_28 ] ) {
F_29 ( V_2 , V_28 ) ;
}
}
if ( F_30 ( V_30 < 0 ) ) {
return V_30 ;
}
F_31 ( V_2 -> V_13 , V_24 [ V_4 ] ) ;
if ( F_30 ( ! V_29 ) ) {
if ( V_30 ) {
continue;
}
F_32 ( & V_2 -> V_34 ) ;
for ( V_28 = 0 , V_39 = 0 ; V_28 < V_36 ; ++ V_28 ) {
if ( F_24 ( V_2 -> V_7 [ V_28 ] . V_17 , V_39 ) ) {
V_39 = V_2 -> V_7 [ V_28 ] . V_17 ;
}
}
if ( V_17 != V_39 ) {
V_17 = V_39 ;
F_33 ( & V_2 -> V_34 ) ;
continue;
}
if ( F_34 ( V_2 , V_4 , & V_2 -> V_4 [ V_4 ] ) ) {
F_35 ( V_2 -> V_35 , L_4 ,
V_24 [ V_4 ] ) ;
for ( V_28 = 0 ; V_28 < V_36 ; ++ V_28 ) {
V_2 -> V_7 [ V_28 ] . V_17 = V_18 ;
}
V_2 -> V_4 [ V_4 ] . V_31 = false ;
F_33 ( & V_2 -> V_34 ) ;
return - V_37 ;
}
F_33 ( & V_2 -> V_34 ) ;
}
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_10 * * V_40 ,
bool V_25 )
{
T_2 V_3 [ V_36 ] ;
unsigned V_28 ;
int V_30 ;
for ( V_28 = 0 ; V_28 < V_36 ; ++ V_28 ) {
V_3 [ V_28 ] = 0 ;
if ( ! V_40 [ V_28 ] ) {
continue;
}
if ( V_40 [ V_28 ] -> V_3 == V_23 ) {
return 0 ;
}
if ( V_40 [ V_28 ] -> V_3 < V_12 ) {
V_3 [ V_28 ] = V_40 [ V_28 ] -> V_3 ;
}
}
V_30 = F_38 ( V_2 , V_3 , V_25 ) ;
if ( V_30 ) {
return V_30 ;
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_3 ;
V_3 = F_11 ( & V_2 -> V_7 [ V_4 ] . V_14 ) + 1ULL ;
if ( V_3 >= V_2 -> V_7 [ V_4 ] . V_3 ) {
return - V_41 ;
}
return F_23 ( V_2 , V_3 , V_4 , false , false ) ;
}
int F_41 ( struct V_1 * V_2 , int V_4 )
{
return F_23 ( V_2 , V_2 -> V_7 [ V_4 ] . V_3 ,
V_4 , false , false ) ;
}
struct V_10 * F_42 ( struct V_10 * V_11 )
{
F_43 ( & V_11 -> V_20 ) ;
return V_11 ;
}
void F_44 ( struct V_10 * * V_11 )
{
struct V_10 * V_39 = * V_11 ;
* V_11 = NULL ;
if ( V_39 ) {
F_45 ( & V_39 -> V_20 , F_14 ) ;
}
}
unsigned F_46 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_42 ;
F_10 ( V_2 , V_4 ) ;
V_42 = V_2 -> V_7 [ V_4 ] . V_3 - F_11 ( & V_2 -> V_7 [ V_4 ] . V_14 ) ;
if ( V_42 > 0x10000000 ) {
V_42 = 0x10000000 ;
}
return ( unsigned ) V_42 ;
}
int F_47 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_43 ;
int V_30 ;
F_48 ( V_2 , V_2 -> V_7 [ V_4 ] . V_9 ) ;
if ( V_2 -> V_5 . V_44 ) {
V_2 -> V_7 [ V_4 ] . V_9 = 0 ;
V_43 = V_45 + V_4 * 4 ;
} else {
V_30 = F_49 ( V_2 , & V_2 -> V_7 [ V_4 ] . V_9 ) ;
if ( V_30 ) {
F_50 ( V_2 -> V_35 , L_5 ) ;
return V_30 ;
}
V_43 = V_46 +
V_2 -> V_7 [ V_4 ] . V_9 -
V_2 -> V_47 . V_48 ;
}
V_2 -> V_7 [ V_4 ] . V_8 = & V_2 -> V_5 . V_5 [ V_43 / 4 ] ;
V_2 -> V_7 [ V_4 ] . V_49 = V_2 -> V_5 . V_49 + V_43 ;
F_1 ( V_2 , V_2 -> V_7 [ V_4 ] . V_3 , V_4 ) ;
V_2 -> V_7 [ V_4 ] . V_50 = true ;
F_51 ( V_2 -> V_35 , L_6 ,
V_4 , V_2 -> V_7 [ V_4 ] . V_49 , V_2 -> V_7 [ V_4 ] . V_8 ) ;
return 0 ;
}
static void F_52 ( struct V_1 * V_2 , int V_4 )
{
V_2 -> V_7 [ V_4 ] . V_9 = - 1 ;
V_2 -> V_7 [ V_4 ] . V_8 = NULL ;
V_2 -> V_7 [ V_4 ] . V_49 = 0 ;
V_2 -> V_7 [ V_4 ] . V_3 = 0 ;
F_53 ( & V_2 -> V_7 [ V_4 ] . V_14 , 0 ) ;
V_2 -> V_7 [ V_4 ] . V_17 = V_18 ;
V_2 -> V_7 [ V_4 ] . V_50 = false ;
}
int F_54 ( struct V_1 * V_2 )
{
int V_4 ;
F_55 ( & V_2 -> V_19 ) ;
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ ) {
F_52 ( V_2 , V_4 ) ;
}
if ( F_56 ( V_2 ) ) {
F_50 ( V_2 -> V_35 , L_7 ) ;
}
return 0 ;
}
void F_57 ( struct V_1 * V_2 )
{
int V_4 ;
F_32 ( & V_2 -> V_34 ) ;
for ( V_4 = 0 ; V_4 < V_36 ; V_4 ++ ) {
if ( ! V_2 -> V_7 [ V_4 ] . V_50 )
continue;
F_41 ( V_2 , V_4 ) ;
F_13 ( & V_2 -> V_19 ) ;
F_48 ( V_2 , V_2 -> V_7 [ V_4 ] . V_9 ) ;
V_2 -> V_7 [ V_4 ] . V_50 = false ;
}
F_33 ( & V_2 -> V_34 ) ;
}
static int F_58 ( struct V_51 * V_52 , void * V_53 )
{
struct V_54 * V_55 = (struct V_54 * ) V_52 -> V_56 ;
struct V_57 * V_35 = V_55 -> V_58 -> V_35 ;
struct V_1 * V_2 = V_35 -> V_59 ;
int V_28 ;
for ( V_28 = 0 ; V_28 < V_36 ; ++ V_28 ) {
if ( ! V_2 -> V_7 [ V_28 ] . V_50 )
continue;
F_59 ( V_52 , L_8 , V_28 ) ;
F_59 ( V_52 , L_9 ,
( unsigned long long ) F_11 ( & V_2 -> V_7 [ V_28 ] . V_14 ) ) ;
F_59 ( V_52 , L_10 ,
V_2 -> V_7 [ V_28 ] . V_3 ) ;
}
return 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
#if F_60 ( V_60 )
return F_61 ( V_2 , V_61 , 1 ) ;
#else
return 0 ;
#endif
}
