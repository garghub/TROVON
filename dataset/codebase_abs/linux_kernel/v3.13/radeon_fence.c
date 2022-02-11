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
F_14 ( V_2 -> V_19 , ( * V_14 ) -> V_3 ) ;
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
bool V_28 , bool V_29 )
{
T_2 V_12 [ V_26 ] ;
bool V_30 ;
int V_25 , V_31 ;
while ( ! F_23 ( V_2 , V_27 ) ) {
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( ! V_27 [ V_25 ] )
continue;
V_12 [ V_25 ] = F_8 ( & V_2 -> V_7 [ V_25 ] . V_12 ) ;
F_25 ( V_2 -> V_19 , V_27 [ V_25 ] ) ;
F_26 ( V_2 , V_25 ) ;
}
if ( V_28 ) {
V_31 = F_27 ( V_2 -> V_23 , (
( V_30 = F_23 ( V_2 , V_27 ) )
|| V_2 -> V_32 ) , V_33 ) ;
} else {
V_31 = F_28 ( V_2 -> V_23 , (
( V_30 = F_23 ( V_2 , V_27 ) )
|| V_2 -> V_32 ) , V_33 ) ;
}
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( ! V_27 [ V_25 ] )
continue;
F_29 ( V_2 , V_25 ) ;
F_30 ( V_2 -> V_19 , V_27 [ V_25 ] ) ;
}
if ( F_31 ( V_31 < 0 ) )
return V_31 ;
if ( F_31 ( ! V_30 ) ) {
if ( V_2 -> V_32 )
return - V_34 ;
if ( V_31 )
continue;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( ! V_27 [ V_25 ] )
continue;
if ( V_12 [ V_25 ] != F_8 ( & V_2 -> V_7 [ V_25 ] . V_12 ) )
break;
}
if ( V_25 != V_26 )
continue;
if ( V_29 )
F_32 ( & V_2 -> V_35 ) ;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( ! V_27 [ V_25 ] )
continue;
if ( F_33 ( V_2 , V_25 , & V_2 -> V_4 [ V_25 ] ) )
break;
}
if ( V_25 < V_26 ) {
F_34 ( V_2 -> V_36 , L_1
L_2
L_3 ,
V_27 [ V_25 ] , V_12 [ V_25 ] , V_25 ) ;
V_2 -> V_32 = true ;
if ( V_29 )
F_35 ( & V_2 -> V_35 ) ;
F_17 ( & V_2 -> V_23 ) ;
return - V_34 ;
}
if ( V_29 )
F_35 ( & V_2 -> V_35 ) ;
}
}
return 0 ;
}
int F_36 ( struct V_13 * V_14 , bool V_28 )
{
T_2 V_3 [ V_26 ] = {} ;
int V_31 ;
if ( V_14 == NULL ) {
F_37 ( 1 , L_4 , V_14 ) ;
return - V_37 ;
}
V_3 [ V_14 -> V_4 ] = V_14 -> V_3 ;
if ( V_3 [ V_14 -> V_4 ] == V_24 )
return 0 ;
V_31 = F_24 ( V_14 -> V_2 , V_3 , V_28 , true ) ;
if ( V_31 )
return V_31 ;
V_14 -> V_3 = V_24 ;
return 0 ;
}
int F_38 ( struct V_1 * V_2 ,
struct V_13 * * V_38 ,
bool V_28 )
{
T_2 V_3 [ V_26 ] ;
unsigned V_25 , V_39 = 0 ;
int V_31 ;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
V_3 [ V_25 ] = 0 ;
if ( ! V_38 [ V_25 ] ) {
continue;
}
V_3 [ V_25 ] = V_38 [ V_25 ] -> V_3 ;
++ V_39 ;
if ( V_3 [ V_25 ] == V_24 )
return 0 ;
}
if ( V_39 == 0 )
return - V_40 ;
V_31 = F_24 ( V_2 , V_3 , V_28 , true ) ;
if ( V_31 ) {
return V_31 ;
}
return 0 ;
}
int F_39 ( struct V_13 * V_14 )
{
T_2 V_3 [ V_26 ] = {} ;
int V_31 ;
if ( V_14 == NULL ) {
F_37 ( 1 , L_4 , V_14 ) ;
return - V_37 ;
}
V_3 [ V_14 -> V_4 ] = V_14 -> V_3 ;
if ( V_3 [ V_14 -> V_4 ] == V_24 )
return 0 ;
V_31 = F_24 ( V_14 -> V_2 , V_3 , false , false ) ;
if ( V_31 )
return V_31 ;
V_14 -> V_3 = V_24 ;
return 0 ;
}
int F_40 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_3 [ V_26 ] = {} ;
V_3 [ V_4 ] = F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) + 1ULL ;
if ( V_3 [ V_4 ] >= V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] ) {
return - V_40 ;
}
return F_24 ( V_2 , V_3 , false , false ) ;
}
int F_41 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_3 [ V_26 ] = {} ;
int V_31 ;
V_3 [ V_4 ] = V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] ;
if ( ! V_3 [ V_4 ] )
return 0 ;
V_31 = F_24 ( V_2 , V_3 , false , false ) ;
if ( V_31 ) {
if ( V_31 == - V_34 )
return - V_34 ;
F_42 ( V_2 -> V_36 , L_5 ,
V_4 , V_31 ) ;
}
return 0 ;
}
struct V_13 * F_43 ( struct V_13 * V_14 )
{
F_44 ( & V_14 -> V_17 ) ;
return V_14 ;
}
void F_45 ( struct V_13 * * V_14 )
{
struct V_13 * V_41 = * V_14 ;
* V_14 = NULL ;
if ( V_41 ) {
F_46 ( & V_41 -> V_17 , F_18 ) ;
}
}
unsigned F_47 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_42 ;
F_15 ( V_2 , V_4 ) ;
V_42 = V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ]
- F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) ;
if ( V_42 > 0x10000000 ) {
V_42 = 0x10000000 ;
}
return ( unsigned ) V_42 ;
}
bool F_48 ( struct V_13 * V_14 , int V_43 )
{
struct V_5 * V_44 ;
if ( ! V_14 ) {
return false ;
}
if ( V_14 -> V_4 == V_43 ) {
return false ;
}
V_44 = & V_14 -> V_2 -> V_7 [ V_43 ] ;
if ( V_14 -> V_3 <= V_44 -> V_18 [ V_14 -> V_4 ] ) {
return false ;
}
return true ;
}
void F_49 ( struct V_13 * V_14 , int V_43 )
{
struct V_5 * V_45 , * V_46 ;
unsigned V_25 ;
if ( ! V_14 ) {
return;
}
if ( V_14 -> V_4 == V_43 ) {
return;
}
V_46 = & V_14 -> V_2 -> V_7 [ V_14 -> V_4 ] ;
V_45 = & V_14 -> V_2 -> V_7 [ V_43 ] ;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( V_25 == V_43 ) {
continue;
}
V_45 -> V_18 [ V_25 ] = F_50 ( V_45 -> V_18 [ V_25 ] , V_46 -> V_18 [ V_25 ] ) ;
}
}
int F_51 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_47 ;
int V_31 ;
F_52 ( V_2 , V_2 -> V_7 [ V_4 ] . V_10 ) ;
if ( V_2 -> V_8 . V_48 || ! F_53 ( V_2 , & V_2 -> V_4 [ V_4 ] ) ) {
V_2 -> V_7 [ V_4 ] . V_10 = 0 ;
if ( V_4 != V_49 ) {
V_47 = V_50 + V_4 * 4 ;
V_2 -> V_7 [ V_4 ] . V_11 = & V_2 -> V_8 . V_8 [ V_47 / 4 ] ;
V_2 -> V_7 [ V_4 ] . V_51 = V_2 -> V_8 . V_51 +
V_47 ;
} else {
V_47 = F_54 ( V_2 -> V_52 -> V_53 , 8 ) ;
V_2 -> V_7 [ V_4 ] . V_11 = V_2 -> V_54 . V_11 + V_47 ;
V_2 -> V_7 [ V_4 ] . V_51 = V_2 -> V_54 . V_51 + V_47 ;
}
} else {
V_31 = F_55 ( V_2 , & V_2 -> V_7 [ V_4 ] . V_10 ) ;
if ( V_31 ) {
F_42 ( V_2 -> V_36 , L_6 ) ;
return V_31 ;
}
V_47 = V_55 +
V_2 -> V_7 [ V_4 ] . V_10 -
V_2 -> V_56 . V_57 ;
V_2 -> V_7 [ V_4 ] . V_11 = & V_2 -> V_8 . V_8 [ V_47 / 4 ] ;
V_2 -> V_7 [ V_4 ] . V_51 = V_2 -> V_8 . V_51 + V_47 ;
}
F_1 ( V_2 , F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) , V_4 ) ;
V_2 -> V_7 [ V_4 ] . V_58 = true ;
F_56 ( V_2 -> V_36 , L_7 ,
V_4 , V_2 -> V_7 [ V_4 ] . V_51 , V_2 -> V_7 [ V_4 ] . V_11 ) ;
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , int V_4 )
{
int V_25 ;
V_2 -> V_7 [ V_4 ] . V_10 = - 1 ;
V_2 -> V_7 [ V_4 ] . V_11 = NULL ;
V_2 -> V_7 [ V_4 ] . V_51 = 0 ;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 )
V_2 -> V_7 [ V_4 ] . V_18 [ V_25 ] = 0 ;
F_58 ( & V_2 -> V_7 [ V_4 ] . V_12 , 0 ) ;
V_2 -> V_7 [ V_4 ] . V_58 = false ;
}
int F_59 ( struct V_1 * V_2 )
{
int V_4 ;
F_60 ( & V_2 -> V_23 ) ;
for ( V_4 = 0 ; V_4 < V_26 ; V_4 ++ ) {
F_57 ( V_2 , V_4 ) ;
}
if ( F_61 ( V_2 ) ) {
F_42 ( V_2 -> V_36 , L_8 ) ;
}
return 0 ;
}
void F_62 ( struct V_1 * V_2 )
{
int V_4 , V_31 ;
F_32 ( & V_2 -> V_35 ) ;
for ( V_4 = 0 ; V_4 < V_26 ; V_4 ++ ) {
if ( ! V_2 -> V_7 [ V_4 ] . V_58 )
continue;
V_31 = F_41 ( V_2 , V_4 ) ;
if ( V_31 ) {
F_63 ( V_2 ) ;
}
F_17 ( & V_2 -> V_23 ) ;
F_52 ( V_2 , V_2 -> V_7 [ V_4 ] . V_10 ) ;
V_2 -> V_7 [ V_4 ] . V_58 = false ;
}
F_35 ( & V_2 -> V_35 ) ;
}
void F_63 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_26 ; V_4 ++ ) {
if ( ! V_2 -> V_7 [ V_4 ] . V_58 )
continue;
F_1 ( V_2 , V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] , V_4 ) ;
}
}
static int F_64 ( struct V_59 * V_60 , void * V_61 )
{
struct V_62 * V_63 = (struct V_62 * ) V_60 -> V_64 ;
struct V_65 * V_36 = V_63 -> V_66 -> V_36 ;
struct V_1 * V_2 = V_36 -> V_67 ;
int V_25 , V_68 ;
for ( V_25 = 0 ; V_25 < V_26 ; ++ V_25 ) {
if ( ! V_2 -> V_7 [ V_25 ] . V_58 )
continue;
F_65 ( V_60 , L_9 , V_25 ) ;
F_65 ( V_60 , L_10 ,
( unsigned long long ) F_8 ( & V_2 -> V_7 [ V_25 ] . V_12 ) ) ;
F_65 ( V_60 , L_11 ,
V_2 -> V_7 [ V_25 ] . V_18 [ V_25 ] ) ;
for ( V_68 = 0 ; V_68 < V_26 ; ++ V_68 ) {
if ( V_25 != V_68 && V_2 -> V_7 [ V_68 ] . V_58 )
F_65 ( V_60 , L_12 ,
V_68 , V_2 -> V_7 [ V_25 ] . V_18 [ V_68 ] ) ;
}
}
return 0 ;
}
int F_61 ( struct V_1 * V_2 )
{
#if F_66 ( V_69 )
return F_67 ( V_2 , V_70 , 1 ) ;
#else
return 0 ;
#endif
}
