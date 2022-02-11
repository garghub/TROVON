static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 [ V_4 ] ;
if ( F_2 ( V_2 -> V_8 . V_9 || ! V_6 -> V_10 ) ) {
if ( V_6 -> V_11 ) {
* V_6 -> V_11 = F_3 ( V_3 ) ;
}
} else {
F_4 ( V_6 -> V_10 , V_3 ) ;
}
}
static T_1 F_5 ( struct V_1 * V_2 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 [ V_4 ] ;
T_1 V_3 = 0 ;
if ( F_2 ( V_2 -> V_8 . V_9 || ! V_6 -> V_10 ) ) {
if ( V_6 -> V_11 ) {
V_3 = F_6 ( * V_6 -> V_11 ) ;
} else {
V_3 = F_7 ( F_8 ( & V_6 -> V_12 ) ) ;
}
} else {
V_3 = F_9 ( V_6 -> V_10 ) ;
}
return V_3 ;
}
int F_10 ( struct V_1 * V_2 ,
struct V_13 * * V_14 ,
int V_4 )
{
* V_14 = F_11 ( sizeof( struct V_13 ) , V_15 ) ;
if ( ( * V_14 ) == NULL ) {
return - V_16 ;
}
F_12 ( & ( ( * V_14 ) -> V_17 ) ) ;
( * V_14 ) -> V_2 = V_2 ;
( * V_14 ) -> V_3 = ++ V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] ;
( * V_14 ) -> V_4 = V_4 ;
F_13 ( V_2 , V_4 , * V_14 ) ;
F_14 ( V_2 -> V_19 , V_4 , ( * V_14 ) -> V_3 ) ;
return 0 ;
}
void F_15 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_3 , V_12 , V_20 ;
unsigned V_21 = 0 ;
bool V_22 = false ;
V_12 = F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) ;
do {
V_20 = V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] ;
V_3 = F_5 ( V_2 , V_4 ) ;
V_3 |= V_12 & 0xffffffff00000000LL ;
if ( V_3 < V_12 ) {
V_3 &= 0xffffffff ;
V_3 |= V_20 & 0xffffffff00000000LL ;
}
if ( V_3 <= V_12 || V_3 > V_20 ) {
break;
}
V_22 = true ;
V_12 = V_3 ;
if ( ( V_21 ++ ) > 10 ) {
break;
}
} while ( F_16 ( & V_2 -> V_7 [ V_4 ] . V_12 , V_3 ) > V_3 );
if ( V_22 )
F_17 ( & V_2 -> V_23 ) ;
}
static void F_18 ( struct V_17 * V_17 )
{
struct V_13 * V_14 ;
V_14 = F_19 ( V_17 , struct V_13 , V_17 ) ;
F_20 ( V_14 ) ;
}
static bool F_21 ( struct V_1 * V_2 ,
T_3 V_3 , unsigned V_4 )
{
if ( F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) >= V_3 ) {
return true ;
}
F_15 ( V_2 , V_4 ) ;
if ( F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) >= V_3 ) {
return true ;
}
return false ;
}
bool F_22 ( struct V_13 * V_14 )
{
if ( ! V_14 ) {
return true ;
}
if ( V_14 -> V_3 == V_24 ) {
return true ;
}
if ( F_21 ( V_14 -> V_2 , V_14 -> V_3 , V_14 -> V_4 ) ) {
V_14 -> V_3 = V_24 ;
return true ;
}
return false ;
}
static bool F_23 ( struct V_1 * V_2 , T_3 * V_3 )
{
unsigned V_25 ;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( V_3 [ V_25 ] && F_21 ( V_2 , V_3 [ V_25 ] , V_25 ) )
return true ;
}
return false ;
}
static int F_24 ( struct V_1 * V_2 , T_3 * V_27 ,
bool V_28 )
{
T_2 V_12 [ V_26 ] ;
bool V_29 ;
int V_25 , V_30 ;
while ( ! F_23 ( V_2 , V_27 ) ) {
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( ! V_27 [ V_25 ] )
continue;
V_12 [ V_25 ] = F_8 ( & V_2 -> V_7 [ V_25 ] . V_12 ) ;
F_25 ( V_2 -> V_19 , V_25 , V_27 [ V_25 ] ) ;
F_26 ( V_2 , V_25 ) ;
}
if ( V_28 ) {
V_30 = F_27 ( V_2 -> V_23 , (
( V_29 = F_23 ( V_2 , V_27 ) )
|| V_2 -> V_31 ) , V_32 ) ;
} else {
V_30 = F_28 ( V_2 -> V_23 , (
( V_29 = F_23 ( V_2 , V_27 ) )
|| V_2 -> V_31 ) , V_32 ) ;
}
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( ! V_27 [ V_25 ] )
continue;
F_29 ( V_2 , V_25 ) ;
F_30 ( V_2 -> V_19 , V_25 , V_27 [ V_25 ] ) ;
}
if ( F_31 ( V_30 < 0 ) )
return V_30 ;
if ( F_31 ( ! V_29 ) ) {
if ( V_2 -> V_31 )
return - V_33 ;
if ( V_30 )
continue;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( ! V_27 [ V_25 ] )
continue;
if ( V_12 [ V_25 ] != F_8 ( & V_2 -> V_7 [ V_25 ] . V_12 ) )
break;
}
if ( V_25 != V_26 )
continue;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( ! V_27 [ V_25 ] )
continue;
if ( F_32 ( V_2 , V_25 , & V_2 -> V_4 [ V_25 ] ) )
break;
}
if ( V_25 < V_26 ) {
F_33 ( V_2 -> V_34 , L_1
L_2
L_3 ,
V_27 [ V_25 ] , V_12 [ V_25 ] , V_25 ) ;
V_2 -> V_31 = true ;
F_17 ( & V_2 -> V_23 ) ;
return - V_33 ;
}
}
}
return 0 ;
}
int F_34 ( struct V_13 * V_14 , bool V_28 )
{
T_2 V_3 [ V_26 ] = {} ;
int V_30 ;
if ( V_14 == NULL ) {
F_35 ( 1 , L_4 , V_14 ) ;
return - V_35 ;
}
V_3 [ V_14 -> V_4 ] = V_14 -> V_3 ;
if ( V_3 [ V_14 -> V_4 ] == V_24 )
return 0 ;
V_30 = F_24 ( V_14 -> V_2 , V_3 , V_28 ) ;
if ( V_30 )
return V_30 ;
V_14 -> V_3 = V_24 ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 ,
struct V_13 * * V_36 ,
bool V_28 )
{
T_2 V_3 [ V_26 ] ;
unsigned V_25 , V_37 = 0 ;
int V_30 ;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
V_3 [ V_25 ] = 0 ;
if ( ! V_36 [ V_25 ] ) {
continue;
}
V_3 [ V_25 ] = V_36 [ V_25 ] -> V_3 ;
++ V_37 ;
if ( V_3 [ V_25 ] == V_24 )
return 0 ;
}
if ( V_37 == 0 )
return - V_38 ;
V_30 = F_24 ( V_2 , V_3 , V_28 ) ;
if ( V_30 ) {
return V_30 ;
}
return 0 ;
}
int F_37 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_3 [ V_26 ] = {} ;
V_3 [ V_4 ] = F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) + 1ULL ;
if ( V_3 [ V_4 ] >= V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] ) {
return - V_38 ;
}
return F_24 ( V_2 , V_3 , false ) ;
}
int F_38 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_3 [ V_26 ] = {} ;
int V_30 ;
V_3 [ V_4 ] = V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] ;
if ( ! V_3 [ V_4 ] )
return 0 ;
V_30 = F_24 ( V_2 , V_3 , false ) ;
if ( V_30 ) {
if ( V_30 == - V_33 )
return - V_33 ;
F_39 ( V_2 -> V_34 , L_5 ,
V_4 , V_30 ) ;
}
return 0 ;
}
struct V_13 * F_40 ( struct V_13 * V_14 )
{
F_41 ( & V_14 -> V_17 ) ;
return V_14 ;
}
void F_42 ( struct V_13 * * V_14 )
{
struct V_13 * V_39 = * V_14 ;
* V_14 = NULL ;
if ( V_39 ) {
F_43 ( & V_39 -> V_17 , F_18 ) ;
}
}
unsigned F_44 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_40 ;
F_15 ( V_2 , V_4 ) ;
V_40 = V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ]
- F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) ;
if ( V_40 > 0x10000000 ) {
V_40 = 0x10000000 ;
}
return ( unsigned ) V_40 ;
}
bool F_45 ( struct V_13 * V_14 , int V_41 )
{
struct V_5 * V_42 ;
if ( ! V_14 ) {
return false ;
}
if ( V_14 -> V_4 == V_41 ) {
return false ;
}
V_42 = & V_14 -> V_2 -> V_7 [ V_41 ] ;
if ( V_14 -> V_3 <= V_42 -> V_18 [ V_14 -> V_4 ] ) {
return false ;
}
return true ;
}
void F_46 ( struct V_13 * V_14 , int V_41 )
{
struct V_5 * V_43 , * V_44 ;
unsigned V_25 ;
if ( ! V_14 ) {
return;
}
if ( V_14 -> V_4 == V_41 ) {
return;
}
V_44 = & V_14 -> V_2 -> V_7 [ V_14 -> V_4 ] ;
V_43 = & V_14 -> V_2 -> V_7 [ V_41 ] ;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( V_25 == V_41 ) {
continue;
}
V_43 -> V_18 [ V_25 ] = F_47 ( V_43 -> V_18 [ V_25 ] , V_44 -> V_18 [ V_25 ] ) ;
}
}
int F_48 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_45 ;
int V_30 ;
F_49 ( V_2 , V_2 -> V_7 [ V_4 ] . V_10 ) ;
if ( V_2 -> V_8 . V_46 || ! F_50 ( V_2 , & V_2 -> V_4 [ V_4 ] ) ) {
V_2 -> V_7 [ V_4 ] . V_10 = 0 ;
if ( V_4 != V_47 ) {
V_45 = V_48 + V_4 * 4 ;
V_2 -> V_7 [ V_4 ] . V_11 = & V_2 -> V_8 . V_8 [ V_45 / 4 ] ;
V_2 -> V_7 [ V_4 ] . V_49 = V_2 -> V_8 . V_49 +
V_45 ;
} else {
V_45 = F_51 ( V_2 -> V_50 -> V_51 , 8 ) ;
V_2 -> V_7 [ V_4 ] . V_11 = V_2 -> V_52 . V_11 + V_45 ;
V_2 -> V_7 [ V_4 ] . V_49 = V_2 -> V_52 . V_49 + V_45 ;
}
} else {
V_30 = F_52 ( V_2 , & V_2 -> V_7 [ V_4 ] . V_10 ) ;
if ( V_30 ) {
F_39 ( V_2 -> V_34 , L_6 ) ;
return V_30 ;
}
V_45 = V_53 +
V_2 -> V_7 [ V_4 ] . V_10 -
V_2 -> V_54 . V_55 ;
V_2 -> V_7 [ V_4 ] . V_11 = & V_2 -> V_8 . V_8 [ V_45 / 4 ] ;
V_2 -> V_7 [ V_4 ] . V_49 = V_2 -> V_8 . V_49 + V_45 ;
}
F_1 ( V_2 , F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) , V_4 ) ;
V_2 -> V_7 [ V_4 ] . V_56 = true ;
F_53 ( V_2 -> V_34 , L_7 ,
V_4 , V_2 -> V_7 [ V_4 ] . V_49 , V_2 -> V_7 [ V_4 ] . V_11 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 , int V_4 )
{
int V_25 ;
V_2 -> V_7 [ V_4 ] . V_10 = - 1 ;
V_2 -> V_7 [ V_4 ] . V_11 = NULL ;
V_2 -> V_7 [ V_4 ] . V_49 = 0 ;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 )
V_2 -> V_7 [ V_4 ] . V_18 [ V_25 ] = 0 ;
F_55 ( & V_2 -> V_7 [ V_4 ] . V_12 , 0 ) ;
V_2 -> V_7 [ V_4 ] . V_56 = false ;
}
int F_56 ( struct V_1 * V_2 )
{
int V_4 ;
F_57 ( & V_2 -> V_23 ) ;
for ( V_4 = 0 ; V_4 < V_26 ; V_4 ++ ) {
F_54 ( V_2 , V_4 ) ;
}
if ( F_58 ( V_2 ) ) {
F_39 ( V_2 -> V_34 , L_8 ) ;
}
return 0 ;
}
void F_59 ( struct V_1 * V_2 )
{
int V_4 , V_30 ;
F_60 ( & V_2 -> V_57 ) ;
for ( V_4 = 0 ; V_4 < V_26 ; V_4 ++ ) {
if ( ! V_2 -> V_7 [ V_4 ] . V_56 )
continue;
V_30 = F_38 ( V_2 , V_4 ) ;
if ( V_30 ) {
F_61 ( V_2 ) ;
}
F_17 ( & V_2 -> V_23 ) ;
F_49 ( V_2 , V_2 -> V_7 [ V_4 ] . V_10 ) ;
V_2 -> V_7 [ V_4 ] . V_56 = false ;
}
F_62 ( & V_2 -> V_57 ) ;
}
void F_61 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_26 ; V_4 ++ ) {
if ( ! V_2 -> V_7 [ V_4 ] . V_56 )
continue;
F_1 ( V_2 , V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] , V_4 ) ;
}
}
static int F_63 ( struct V_58 * V_59 , void * V_60 )
{
struct V_61 * V_62 = (struct V_61 * ) V_59 -> V_63 ;
struct V_64 * V_34 = V_62 -> V_65 -> V_34 ;
struct V_1 * V_2 = V_34 -> V_66 ;
int V_25 , V_67 ;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( ! V_2 -> V_7 [ V_25 ] . V_56 )
continue;
F_15 ( V_2 , V_25 ) ;
F_64 ( V_59 , L_9 , V_25 ) ;
F_64 ( V_59 , L_10 ,
( unsigned long long ) F_8 ( & V_2 -> V_7 [ V_25 ] . V_12 ) ) ;
F_64 ( V_59 , L_11 ,
V_2 -> V_7 [ V_25 ] . V_18 [ V_25 ] ) ;
for ( V_67 = 0 ; V_67 < V_26 ; ++ V_67 ) {
if ( V_25 != V_67 && V_2 -> V_7 [ V_67 ] . V_56 )
F_64 ( V_59 , L_12 ,
V_67 , V_2 -> V_7 [ V_25 ] . V_18 [ V_67 ] ) ;
}
}
return 0 ;
}
static int F_65 ( struct V_58 * V_59 , void * V_60 )
{
struct V_61 * V_62 = (struct V_61 * ) V_59 -> V_63 ;
struct V_64 * V_34 = V_62 -> V_65 -> V_34 ;
struct V_1 * V_2 = V_34 -> V_66 ;
F_66 ( & V_2 -> V_68 ) ;
F_64 ( V_59 , L_13 , V_2 -> V_31 ) ;
V_2 -> V_31 = true ;
F_67 ( & V_2 -> V_68 ) ;
return 0 ;
}
int F_58 ( struct V_1 * V_2 )
{
#if F_68 ( V_69 )
return F_69 ( V_2 , V_70 , 2 ) ;
#else
return 0 ;
#endif
}
