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
if ( V_22 ) {
V_2 -> V_7 [ V_4 ] . V_23 = V_24 ;
F_17 ( & V_2 -> V_25 ) ;
}
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
if ( V_14 -> V_3 == V_26 ) {
return true ;
}
if ( F_21 ( V_14 -> V_2 , V_14 -> V_3 , V_14 -> V_4 ) ) {
V_14 -> V_3 = V_26 ;
return true ;
}
return false ;
}
static int F_23 ( struct V_1 * V_2 , T_3 V_27 ,
unsigned V_4 , bool V_28 , bool V_29 )
{
unsigned long V_30 , V_23 ;
T_2 V_3 ;
unsigned V_31 ;
bool V_32 ;
int V_33 ;
while ( V_27 > F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) ) {
if ( ! V_2 -> V_4 [ V_4 ] . V_34 ) {
return - V_35 ;
}
V_30 = V_24 - V_36 ;
if ( F_24 ( V_2 -> V_7 [ V_4 ] . V_23 , V_30 ) ) {
V_30 = V_2 -> V_7 [ V_4 ] . V_23 - V_30 ;
} else {
V_30 = 1 ;
}
V_3 = F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) ;
V_23 = V_2 -> V_7 [ V_4 ] . V_23 ;
F_25 ( V_2 -> V_19 , V_3 ) ;
F_26 ( V_2 , V_4 ) ;
if ( V_28 ) {
V_33 = F_27 ( V_2 -> V_25 ,
( V_32 = F_21 ( V_2 , V_27 , V_4 ) ) ,
V_30 ) ;
} else {
V_33 = F_28 ( V_2 -> V_25 ,
( V_32 = F_21 ( V_2 , V_27 , V_4 ) ) ,
V_30 ) ;
}
F_29 ( V_2 , V_4 ) ;
if ( F_30 ( V_33 < 0 ) ) {
return V_33 ;
}
F_31 ( V_2 -> V_19 , V_3 ) ;
if ( F_30 ( ! V_32 ) ) {
if ( V_33 ) {
continue;
}
if ( V_3 != F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) ) {
continue;
}
if ( V_29 ) {
F_32 ( & V_2 -> V_37 ) ;
}
if ( V_23 != V_2 -> V_7 [ V_4 ] . V_23 ) {
if ( V_29 ) {
F_33 ( & V_2 -> V_37 ) ;
}
continue;
}
if ( F_34 ( V_2 , V_4 , & V_2 -> V_4 [ V_4 ] ) ) {
F_35 ( V_2 -> V_38 , L_1 ,
V_27 , V_3 ) ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
V_2 -> V_7 [ V_31 ] . V_23 = V_24 ;
}
V_2 -> V_4 [ V_4 ] . V_34 = false ;
if ( V_29 ) {
F_33 ( & V_2 -> V_37 ) ;
}
return - V_40 ;
}
if ( V_29 ) {
F_33 ( & V_2 -> V_37 ) ;
}
}
}
return 0 ;
}
int F_36 ( struct V_13 * V_14 , bool V_28 )
{
int V_33 ;
if ( V_14 == NULL ) {
F_37 ( 1 , L_2 , V_14 ) ;
return - V_41 ;
}
V_33 = F_23 ( V_14 -> V_2 , V_14 -> V_3 ,
V_14 -> V_4 , V_28 , true ) ;
if ( V_33 ) {
return V_33 ;
}
V_14 -> V_3 = V_26 ;
return 0 ;
}
static bool F_38 ( struct V_1 * V_2 , T_3 * V_3 )
{
unsigned V_31 ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( V_3 [ V_31 ] && F_21 ( V_2 , V_3 [ V_31 ] , V_31 ) ) {
return true ;
}
}
return false ;
}
static int F_39 ( struct V_1 * V_2 ,
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
if ( F_24 ( V_2 -> V_7 [ V_31 ] . V_23 , V_23 ) ) {
V_23 = V_2 -> V_7 [ V_31 ] . V_23 ;
}
if ( V_31 < V_4 ) {
V_4 = V_31 ;
}
}
if ( V_4 == V_39 ) {
return - V_43 ;
}
while ( ! F_38 ( V_2 , V_27 ) ) {
V_30 = V_24 - V_36 ;
if ( F_24 ( V_23 , V_30 ) ) {
V_30 = V_23 - V_30 ;
} else {
V_30 = 1 ;
}
F_25 ( V_2 -> V_19 , V_27 [ V_4 ] ) ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( V_27 [ V_31 ] ) {
F_26 ( V_2 , V_31 ) ;
}
}
if ( V_28 ) {
V_33 = F_27 ( V_2 -> V_25 ,
( V_32 = F_38 ( V_2 , V_27 ) ) ,
V_30 ) ;
} else {
V_33 = F_28 ( V_2 -> V_25 ,
( V_32 = F_38 ( V_2 , V_27 ) ) ,
V_30 ) ;
}
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( V_27 [ V_31 ] ) {
F_29 ( V_2 , V_31 ) ;
}
}
if ( F_30 ( V_33 < 0 ) ) {
return V_33 ;
}
F_31 ( V_2 -> V_19 , V_27 [ V_4 ] ) ;
if ( F_30 ( ! V_32 ) ) {
if ( V_33 ) {
continue;
}
F_32 ( & V_2 -> V_37 ) ;
for ( V_31 = 0 , V_42 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( F_24 ( V_2 -> V_7 [ V_31 ] . V_23 , V_42 ) ) {
V_42 = V_2 -> V_7 [ V_31 ] . V_23 ;
}
}
if ( V_23 != V_42 ) {
V_23 = V_42 ;
F_33 ( & V_2 -> V_37 ) ;
continue;
}
if ( F_34 ( V_2 , V_4 , & V_2 -> V_4 [ V_4 ] ) ) {
F_35 ( V_2 -> V_38 , L_3 ,
V_27 [ V_4 ] ) ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
V_2 -> V_7 [ V_31 ] . V_23 = V_24 ;
}
V_2 -> V_4 [ V_4 ] . V_34 = false ;
F_33 ( & V_2 -> V_37 ) ;
return - V_40 ;
}
F_33 ( & V_2 -> V_37 ) ;
}
}
return 0 ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_13 * * V_44 ,
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
V_33 = F_39 ( V_2 , V_3 , V_28 ) ;
if ( V_33 ) {
return V_33 ;
}
return 0 ;
}
int F_41 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_3 ;
V_3 = F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) + 1ULL ;
if ( V_3 >= V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] ) {
return - V_43 ;
}
return F_23 ( V_2 , V_3 , V_4 , false , false ) ;
}
int F_42 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_3 = V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] ;
int V_33 ;
V_33 = F_23 ( V_2 , V_3 , V_4 , false , false ) ;
if ( V_33 ) {
if ( V_33 == - V_40 ) {
return - V_40 ;
}
F_43 ( V_2 -> V_38 , L_4 ,
V_4 , V_33 ) ;
}
return 0 ;
}
struct V_13 * F_44 ( struct V_13 * V_14 )
{
F_45 ( & V_14 -> V_17 ) ;
return V_14 ;
}
void F_46 ( struct V_13 * * V_14 )
{
struct V_13 * V_42 = * V_14 ;
* V_14 = NULL ;
if ( V_42 ) {
F_47 ( & V_42 -> V_17 , F_18 ) ;
}
}
unsigned F_48 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_45 ;
F_15 ( V_2 , V_4 ) ;
V_45 = V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ]
- F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) ;
if ( V_45 > 0x10000000 ) {
V_45 = 0x10000000 ;
}
return ( unsigned ) V_45 ;
}
bool F_49 ( struct V_13 * V_14 , int V_46 )
{
struct V_5 * V_47 ;
if ( ! V_14 ) {
return false ;
}
if ( V_14 -> V_4 == V_46 ) {
return false ;
}
V_47 = & V_14 -> V_2 -> V_7 [ V_46 ] ;
if ( V_14 -> V_3 <= V_47 -> V_18 [ V_14 -> V_4 ] ) {
return false ;
}
return true ;
}
void F_50 ( struct V_13 * V_14 , int V_46 )
{
struct V_5 * V_48 , * V_49 ;
unsigned V_31 ;
if ( ! V_14 ) {
return;
}
if ( V_14 -> V_4 == V_46 ) {
return;
}
V_49 = & V_14 -> V_2 -> V_7 [ V_14 -> V_4 ] ;
V_48 = & V_14 -> V_2 -> V_7 [ V_46 ] ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( V_31 == V_46 ) {
continue;
}
V_48 -> V_18 [ V_31 ] = F_51 ( V_48 -> V_18 [ V_31 ] , V_49 -> V_18 [ V_31 ] ) ;
}
}
int F_52 ( struct V_1 * V_2 , int V_4 )
{
T_2 V_50 ;
int V_33 ;
F_53 ( V_2 , V_2 -> V_7 [ V_4 ] . V_10 ) ;
if ( V_2 -> V_8 . V_51 || ! F_54 ( V_2 , & V_2 -> V_4 [ V_4 ] ) ) {
V_2 -> V_7 [ V_4 ] . V_10 = 0 ;
if ( V_4 != V_52 ) {
V_50 = V_53 + V_4 * 4 ;
V_2 -> V_7 [ V_4 ] . V_11 = & V_2 -> V_8 . V_8 [ V_50 / 4 ] ;
V_2 -> V_7 [ V_4 ] . V_54 = V_2 -> V_8 . V_54 +
V_50 ;
} else {
V_50 = F_55 ( V_2 -> V_55 -> V_56 , 8 ) ;
V_2 -> V_7 [ V_4 ] . V_11 = V_2 -> V_57 . V_11 + V_50 ;
V_2 -> V_7 [ V_4 ] . V_54 = V_2 -> V_57 . V_54 + V_50 ;
}
} else {
V_33 = F_56 ( V_2 , & V_2 -> V_7 [ V_4 ] . V_10 ) ;
if ( V_33 ) {
F_43 ( V_2 -> V_38 , L_5 ) ;
return V_33 ;
}
V_50 = V_58 +
V_2 -> V_7 [ V_4 ] . V_10 -
V_2 -> V_59 . V_60 ;
V_2 -> V_7 [ V_4 ] . V_11 = & V_2 -> V_8 . V_8 [ V_50 / 4 ] ;
V_2 -> V_7 [ V_4 ] . V_54 = V_2 -> V_8 . V_54 + V_50 ;
}
F_1 ( V_2 , F_8 ( & V_2 -> V_7 [ V_4 ] . V_12 ) , V_4 ) ;
V_2 -> V_7 [ V_4 ] . V_61 = true ;
F_57 ( V_2 -> V_38 , L_6 ,
V_4 , V_2 -> V_7 [ V_4 ] . V_54 , V_2 -> V_7 [ V_4 ] . V_11 ) ;
return 0 ;
}
static void F_58 ( struct V_1 * V_2 , int V_4 )
{
int V_31 ;
V_2 -> V_7 [ V_4 ] . V_10 = - 1 ;
V_2 -> V_7 [ V_4 ] . V_11 = NULL ;
V_2 -> V_7 [ V_4 ] . V_54 = 0 ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 )
V_2 -> V_7 [ V_4 ] . V_18 [ V_31 ] = 0 ;
F_59 ( & V_2 -> V_7 [ V_4 ] . V_12 , 0 ) ;
V_2 -> V_7 [ V_4 ] . V_23 = V_24 ;
V_2 -> V_7 [ V_4 ] . V_61 = false ;
}
int F_60 ( struct V_1 * V_2 )
{
int V_4 ;
F_61 ( & V_2 -> V_25 ) ;
for ( V_4 = 0 ; V_4 < V_39 ; V_4 ++ ) {
F_58 ( V_2 , V_4 ) ;
}
if ( F_62 ( V_2 ) ) {
F_43 ( V_2 -> V_38 , L_7 ) ;
}
return 0 ;
}
void F_63 ( struct V_1 * V_2 )
{
int V_4 , V_33 ;
F_32 ( & V_2 -> V_37 ) ;
for ( V_4 = 0 ; V_4 < V_39 ; V_4 ++ ) {
if ( ! V_2 -> V_7 [ V_4 ] . V_61 )
continue;
V_33 = F_42 ( V_2 , V_4 ) ;
if ( V_33 ) {
F_64 ( V_2 ) ;
}
F_17 ( & V_2 -> V_25 ) ;
F_53 ( V_2 , V_2 -> V_7 [ V_4 ] . V_10 ) ;
V_2 -> V_7 [ V_4 ] . V_61 = false ;
}
F_33 ( & V_2 -> V_37 ) ;
}
void F_64 ( struct V_1 * V_2 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_39 ; V_4 ++ ) {
if ( ! V_2 -> V_7 [ V_4 ] . V_61 )
continue;
F_1 ( V_2 , V_2 -> V_7 [ V_4 ] . V_18 [ V_4 ] , V_4 ) ;
}
}
static int F_65 ( struct V_62 * V_63 , void * V_64 )
{
struct V_65 * V_66 = (struct V_65 * ) V_63 -> V_67 ;
struct V_68 * V_38 = V_66 -> V_69 -> V_38 ;
struct V_1 * V_2 = V_38 -> V_70 ;
int V_31 , V_71 ;
for ( V_31 = 0 ; V_31 < V_39 ; ++ V_31 ) {
if ( ! V_2 -> V_7 [ V_31 ] . V_61 )
continue;
F_66 ( V_63 , L_8 , V_31 ) ;
F_66 ( V_63 , L_9 ,
( unsigned long long ) F_8 ( & V_2 -> V_7 [ V_31 ] . V_12 ) ) ;
F_66 ( V_63 , L_10 ,
V_2 -> V_7 [ V_31 ] . V_18 [ V_31 ] ) ;
for ( V_71 = 0 ; V_71 < V_39 ; ++ V_71 ) {
if ( V_31 != V_71 && V_2 -> V_7 [ V_71 ] . V_61 )
F_66 ( V_63 , L_11 ,
V_71 , V_2 -> V_7 [ V_31 ] . V_18 [ V_71 ] ) ;
}
}
return 0 ;
}
int F_62 ( struct V_1 * V_2 )
{
#if F_67 ( V_72 )
return F_68 ( V_2 , V_73 , 1 ) ;
#else
return 0 ;
#endif
}
