static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 [ V_4 ] ;
if ( F_2 ( V_2 -> V_8 . V_9 || ! V_6 -> V_10 ) ) {
* V_6 -> V_11 = F_3 ( V_3 ) ;
} else {
F_4 ( V_6 -> V_10 , V_3 ) ;
}
}
static T_1 F_5 ( struct V_1 * V_2 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 [ V_4 ] ;
T_1 V_3 = 0 ;
if ( F_2 ( V_2 -> V_8 . V_9 || ! V_6 -> V_10 ) ) {
V_3 = F_6 ( * V_6 -> V_11 ) ;
} else {
V_3 = F_7 ( V_6 -> V_10 ) ;
}
return V_3 ;
}
int F_8 ( struct V_1 * V_2 ,
struct V_12 * * V_13 ,
int V_4 )
{
* V_13 = F_9 ( sizeof( struct V_12 ) , V_14 ) ;
if ( ( * V_13 ) == NULL ) {
return - V_15 ;
}
F_10 ( & ( ( * V_13 ) -> V_16 ) ) ;
( * V_13 ) -> V_2 = V_2 ;
( * V_13 ) -> V_3 = ++ V_2 -> V_7 [ V_4 ] . V_17 [ V_4 ] ;
( * V_13 ) -> V_4 = V_4 ;
F_11 ( V_2 , V_4 , * V_13 ) ;
F_12 ( V_2 -> V_18 , ( * V_13 ) -> V_3 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_3 , V_19 , V_20 ;
unsigned V_21 = 0 ;
bool V_22 = false ;
V_19 = F_14 ( & V_2 -> V_7 [ V_4 ] . V_19 ) ;
do {
V_20 = V_2 -> V_7 [ V_4 ] . V_17 [ V_4 ] ;
V_3 = F_5 ( V_2 , V_4 ) ;
V_3 |= V_19 & 0xffffffff00000000LL ;
if ( V_3 < V_19 ) {
V_3 &= 0xffffffff ;
V_3 |= V_20 & 0xffffffff00000000LL ;
}
if ( V_3 <= V_19 || V_3 > V_20 ) {
break;
}
V_22 = true ;
V_19 = V_3 ;
if ( ( V_21 ++ ) > 10 ) {
break;
}
} while ( F_15 ( & V_2 -> V_7 [ V_4 ] . V_19 , V_3 ) > V_3 );
if ( V_22 ) {
V_2 -> V_7 [ V_4 ] . V_23 = V_24 ;
F_16 ( & V_2 -> V_25 ) ;
}
}
static void F_17 ( struct V_16 * V_16 )
{
struct V_12 * V_13 ;
V_13 = F_18 ( V_16 , struct V_12 , V_16 ) ;
F_19 ( V_13 ) ;
}
static bool F_20 ( struct V_1 * V_2 ,
T_3 V_3 , unsigned V_4 )
{
if ( F_14 ( & V_2 -> V_7 [ V_4 ] . V_19 ) >= V_3 ) {
return true ;
}
F_13 ( V_2 , V_4 ) ;
if ( F_14 ( & V_2 -> V_7 [ V_4 ] . V_19 ) >= V_3 ) {
return true ;
}
return false ;
}
bool F_21 ( struct V_12 * V_13 )
{
if ( ! V_13 ) {
return true ;
}
if ( V_13 -> V_3 == V_26 ) {
return true ;
}
if ( F_20 ( V_13 -> V_2 , V_13 -> V_3 , V_13 -> V_4 ) ) {
V_13 -> V_3 = V_26 ;
return true ;
}
return false ;
}
static int F_22 ( struct V_1 * V_2 , T_3 V_27 ,
unsigned V_4 , bool V_28 , bool V_29 )
{
unsigned long V_30 , V_23 ;
T_2 V_3 ;
unsigned V_31 ;
bool V_32 ;
int V_33 ;
while ( V_27 > F_14 ( & V_2 -> V_7 [ V_4 ] . V_19 ) ) {
if ( ! V_2 -> V_4 [ V_4 ] . V_34 ) {
return - V_35 ;
}
V_30 = V_24 - V_36 ;
if ( F_23 ( V_2 -> V_7 [ V_4 ] . V_23 , V_30 ) ) {
V_30 = V_2 -> V_7 [ V_4 ] . V_23 - V_30 ;
} else {
V_30 = 1 ;
}
V_3 = F_14 ( & V_2 -> V_7 [ V_4 ] . V_19 ) ;
V_23 = V_2 -> V_7 [ V_4 ] . V_23 ;
F_24 ( V_2 -> V_18 , V_3 ) ;
F_25 ( V_2 , V_4 ) ;
if ( V_28 ) {
V_33 = F_26 ( V_2 -> V_25 ,
( V_32 = F_20 ( V_2 , V_27 , V_4 ) ) ,
V_30 ) ;
} else {
V_33 = F_27 ( V_2 -> V_25 ,
( V_32 = F_20 ( V_2 , V_27 , V_4 ) ) ,
V_30 ) ;
}
F_28 ( V_2 , V_4 ) ;
if ( F_29 ( V_33 < 0 ) ) {
return V_33 ;
}
F_30 ( V_2 -> V_18 , V_3 ) ;
if ( F_29 ( ! V_32 ) ) {
if ( V_33 ) {
continue;
}
if ( V_3 != F_14 ( & V_2 -> V_7 [ V_4 ] . V_19 ) ) {
continue;
}
if ( V_29 ) {
F_31 ( & V_2 -> V_37 ) ;
}
if ( V_23 != V_2 -> V_7 [ V_4 ] . V_23 ) {
if ( V_29 ) {
F_32 ( & V_2 -> V_37 ) ;
}
continue;
}
if ( F_33 ( V_2 , V_4 , & V_2 -> V_4 [ V_4 ] ) ) {
F_34 ( V_2 -> V_38 , L_1 ,
V_27 , V_3 ) ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
V_2 -> V_7 [ V_31 ] . V_23 = V_24 ;
}
V_2 -> V_4 [ V_4 ] . V_34 = false ;
if ( V_29 ) {
F_32 ( & V_2 -> V_37 ) ;
}
return - V_40 ;
}
if ( V_29 ) {
F_32 ( & V_2 -> V_37 ) ;
}
}
}
return 0 ;
}
int F_35 ( struct V_12 * V_13 , bool V_28 )
{
int V_33 ;
if ( V_13 == NULL ) {
F_36 ( 1 , L_2 , V_13 ) ;
return - V_41 ;
}
V_33 = F_22 ( V_13 -> V_2 , V_13 -> V_3 ,
V_13 -> V_4 , V_28 , true ) ;
if ( V_33 ) {
return V_33 ;
}
V_13 -> V_3 = V_26 ;
return 0 ;
}
bool F_37 ( struct V_1 * V_2 , T_3 * V_3 )
{
unsigned V_31 ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( V_3 [ V_31 ] && F_20 ( V_2 , V_3 [ V_31 ] , V_31 ) ) {
return true ;
}
}
return false ;
}
static int F_38 ( struct V_1 * V_2 ,
T_3 * V_27 , bool V_28 )
{
unsigned long V_30 , V_23 , V_42 ;
unsigned V_31 , V_4 = V_39 ;
bool V_32 ;
int V_33 ;
for ( V_31 = 0 , V_23 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( ! V_27 [ V_31 ] ) {
continue;
}
if ( F_23 ( V_2 -> V_7 [ V_31 ] . V_23 , V_23 ) ) {
V_23 = V_2 -> V_7 [ V_31 ] . V_23 ;
}
if ( V_31 < V_4 ) {
V_4 = V_31 ;
}
}
if ( V_4 == V_39 ) {
return - V_43 ;
}
while ( ! F_37 ( V_2 , V_27 ) ) {
V_30 = V_24 - V_36 ;
if ( F_23 ( V_23 , V_30 ) ) {
V_30 = V_23 - V_30 ;
} else {
V_30 = 1 ;
}
F_24 ( V_2 -> V_18 , V_27 [ V_4 ] ) ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( V_27 [ V_31 ] ) {
F_25 ( V_2 , V_31 ) ;
}
}
if ( V_28 ) {
V_33 = F_26 ( V_2 -> V_25 ,
( V_32 = F_37 ( V_2 , V_27 ) ) ,
V_30 ) ;
} else {
V_33 = F_27 ( V_2 -> V_25 ,
( V_32 = F_37 ( V_2 , V_27 ) ) ,
V_30 ) ;
}
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( V_27 [ V_31 ] ) {
F_28 ( V_2 , V_31 ) ;
}
}
if ( F_29 ( V_33 < 0 ) ) {
return V_33 ;
}
F_30 ( V_2 -> V_18 , V_27 [ V_4 ] ) ;
if ( F_29 ( ! V_32 ) ) {
if ( V_33 ) {
continue;
}
F_31 ( & V_2 -> V_37 ) ;
for ( V_31 = 0 , V_42 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( F_23 ( V_2 -> V_7 [ V_31 ] . V_23 , V_42 ) ) {
V_42 = V_2 -> V_7 [ V_31 ] . V_23 ;
}
}
if ( V_23 != V_42 ) {
V_23 = V_42 ;
F_32 ( & V_2 -> V_37 ) ;
continue;
}
if ( F_33 ( V_2 , V_4 , & V_2 -> V_4 [ V_4 ] ) ) {
F_34 ( V_2 -> V_38 , L_3 ,
V_27 [ V_4 ] ) ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
V_2 -> V_7 [ V_31 ] . V_23 = V_24 ;
}
V_2 -> V_4 [ V_4 ] . V_34 = false ;
F_32 ( & V_2 -> V_37 ) ;
return - V_40 ;
}
F_32 ( & V_2 -> V_37 ) ;
}
}
return 0 ;
}
int F_39 ( struct V_1 * V_2 ,
struct V_12 * * V_44 ,
bool V_28 )
{
T_2 V_3 [ V_39 ] ;
unsigned V_31 ;
int V_33 ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
V_3 [ V_31 ] = 0 ;
if ( ! V_44 [ V_31 ] ) {
continue;
}
if ( V_44 [ V_31 ] -> V_3 == V_26 ) {
return 0 ;
}
V_3 [ V_31 ] = V_44 [ V_31 ] -> V_3 ;
}
V_33 = F_38 ( V_2 , V_3 , V_28 ) ;
if ( V_33 ) {
return V_33 ;
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_3 ;
V_3 = F_14 ( & V_2 -> V_7 [ V_4 ] . V_19 ) + 1ULL ;
if ( V_3 >= V_2 -> V_7 [ V_4 ] . V_17 [ V_4 ] ) {
return - V_43 ;
}
return F_22 ( V_2 , V_3 , V_4 , false , false ) ;
}
void F_41 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_3 = V_2 -> V_7 [ V_4 ] . V_17 [ V_4 ] ;
while( 1 ) {
int V_33 ;
V_33 = F_22 ( V_2 , V_3 , V_4 , false , false ) ;
if ( V_33 == - V_40 ) {
F_32 ( & V_2 -> V_37 ) ;
V_33 = F_42 ( V_2 ) ;
F_31 ( & V_2 -> V_37 ) ;
if ( ! V_33 )
continue;
}
if ( V_33 ) {
F_43 ( V_2 -> V_38 , L_4
L_5 , V_33 ) ;
}
return;
}
}
struct V_12 * F_44 ( struct V_12 * V_13 )
{
F_45 ( & V_13 -> V_16 ) ;
return V_13 ;
}
void F_46 ( struct V_12 * * V_13 )
{
struct V_12 * V_42 = * V_13 ;
* V_13 = NULL ;
if ( V_42 ) {
F_47 ( & V_42 -> V_16 , F_17 ) ;
}
}
unsigned F_48 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_45 ;
F_13 ( V_2 , V_4 ) ;
V_45 = V_2 -> V_7 [ V_4 ] . V_17 [ V_4 ]
- F_14 ( & V_2 -> V_7 [ V_4 ] . V_19 ) ;
if ( V_45 > 0x10000000 ) {
V_45 = 0x10000000 ;
}
return ( unsigned ) V_45 ;
}
bool F_49 ( struct V_12 * V_13 , int V_46 )
{
struct V_5 * V_47 ;
if ( ! V_13 ) {
return false ;
}
if ( V_13 -> V_4 == V_46 ) {
return false ;
}
V_47 = & V_13 -> V_2 -> V_7 [ V_46 ] ;
if ( V_13 -> V_3 <= V_47 -> V_17 [ V_13 -> V_4 ] ) {
return false ;
}
return true ;
}
void F_50 ( struct V_12 * V_13 , int V_46 )
{
struct V_5 * V_48 , * V_49 ;
unsigned V_31 ;
if ( ! V_13 ) {
return;
}
if ( V_13 -> V_4 == V_46 ) {
return;
}
V_49 = & V_13 -> V_2 -> V_7 [ V_13 -> V_4 ] ;
V_48 = & V_13 -> V_2 -> V_7 [ V_46 ] ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( V_31 == V_46 ) {
continue;
}
V_48 -> V_17 [ V_31 ] = F_51 ( V_48 -> V_17 [ V_31 ] , V_49 -> V_17 [ V_31 ] ) ;
}
}
int F_52 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_50 ;
int V_33 ;
F_53 ( V_2 , V_2 -> V_7 [ V_4 ] . V_10 ) ;
if ( V_2 -> V_8 . V_51 ) {
V_2 -> V_7 [ V_4 ] . V_10 = 0 ;
V_50 = V_52 + V_4 * 4 ;
} else {
V_33 = F_54 ( V_2 , & V_2 -> V_7 [ V_4 ] . V_10 ) ;
if ( V_33 ) {
F_43 ( V_2 -> V_38 , L_6 ) ;
return V_33 ;
}
V_50 = V_53 +
V_2 -> V_7 [ V_4 ] . V_10 -
V_2 -> V_54 . V_55 ;
}
V_2 -> V_7 [ V_4 ] . V_11 = & V_2 -> V_8 . V_8 [ V_50 / 4 ] ;
V_2 -> V_7 [ V_4 ] . V_56 = V_2 -> V_8 . V_56 + V_50 ;
F_1 ( V_2 , F_14 ( & V_2 -> V_7 [ V_4 ] . V_19 ) , V_4 ) ;
V_2 -> V_7 [ V_4 ] . V_57 = true ;
F_55 ( V_2 -> V_38 , L_7 ,
V_4 , V_2 -> V_7 [ V_4 ] . V_56 , V_2 -> V_7 [ V_4 ] . V_11 ) ;
return 0 ;
}
static void F_56 ( struct V_1 * V_2 , int V_4 )
{
int V_31 ;
V_2 -> V_7 [ V_4 ] . V_10 = - 1 ;
V_2 -> V_7 [ V_4 ] . V_11 = NULL ;
V_2 -> V_7 [ V_4 ] . V_56 = 0 ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 )
V_2 -> V_7 [ V_4 ] . V_17 [ V_31 ] = 0 ;
F_57 ( & V_2 -> V_7 [ V_4 ] . V_19 , 0 ) ;
V_2 -> V_7 [ V_4 ] . V_23 = V_24 ;
V_2 -> V_7 [ V_4 ] . V_57 = false ;
}
int F_58 ( struct V_1 * V_2 )
{
int V_4 ;
F_59 ( & V_2 -> V_25 ) ;
for ( V_4 = 0 ; V_4 < V_39 ; V_4 ++ ) {
F_56 ( V_2 , V_4 ) ;
}
if ( F_60 ( V_2 ) ) {
F_43 ( V_2 -> V_38 , L_8 ) ;
}
return 0 ;
}
void F_61 ( struct V_1 * V_2 )
{
int V_4 ;
F_31 ( & V_2 -> V_37 ) ;
for ( V_4 = 0 ; V_4 < V_39 ; V_4 ++ ) {
if ( ! V_2 -> V_7 [ V_4 ] . V_57 )
continue;
F_41 ( V_2 , V_4 ) ;
F_16 ( & V_2 -> V_25 ) ;
F_53 ( V_2 , V_2 -> V_7 [ V_4 ] . V_10 ) ;
V_2 -> V_7 [ V_4 ] . V_57 = false ;
}
F_32 ( & V_2 -> V_37 ) ;
}
static int F_62 ( struct V_58 * V_59 , void * V_60 )
{
struct V_61 * V_62 = (struct V_61 * ) V_59 -> V_63 ;
struct V_64 * V_38 = V_62 -> V_65 -> V_38 ;
struct V_1 * V_2 = V_38 -> V_66 ;
int V_31 , V_67 ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( ! V_2 -> V_7 [ V_31 ] . V_57 )
continue;
F_63 ( V_59 , L_9 , V_31 ) ;
F_63 ( V_59 , L_10 ,
( unsigned long long ) F_14 ( & V_2 -> V_7 [ V_31 ] . V_19 ) ) ;
F_63 ( V_59 , L_11 ,
V_2 -> V_7 [ V_31 ] . V_17 [ V_31 ] ) ;
for ( V_67 = 0 ; V_67 < V_39 ; ++ V_67 ) {
if ( V_31 != V_67 && V_2 -> V_7 [ V_67 ] . V_57 )
F_63 ( V_59 , L_12 ,
V_67 , V_2 -> V_7 [ V_31 ] . V_17 [ V_67 ] ) ;
}
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 )
{
#if F_64 ( V_68 )
return F_65 ( V_2 , V_69 , 1 ) ;
#else
return 0 ;
#endif
}
