static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
if ( V_4 -> V_6 > 0 )
F_2 ( V_2 -> V_7 , V_4 -> V_8 , V_4 -> V_9 ,
V_10 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_9 ; ++ V_5 )
F_3 ( F_4 ( & V_4 -> V_8 [ V_5 ] ) ,
F_5 ( V_4 -> V_8 [ V_5 ] . V_11 ) ) ;
}
static void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_9 ; ++ V_5 )
F_7 ( & V_2 -> V_7 -> V_2 , V_4 -> V_8 [ V_5 ] . V_11 ,
F_8 ( F_4 ( & V_4 -> V_8 [ V_5 ] ) ) ,
F_9 ( & V_4 -> V_8 [ V_5 ] ) ) ;
}
void F_10 ( struct V_1 * V_2 , struct V_12 * V_13 , int V_14 )
{
struct V_3 * V_4 , * V_15 ;
if ( ! V_13 )
return;
F_11 (chunk, tmp, &icm->chunk_list, list) {
if ( V_14 )
F_6 ( V_2 , V_4 ) ;
else
F_1 ( V_2 , V_4 ) ;
F_12 ( V_4 ) ;
}
F_12 ( V_13 ) ;
}
static int F_13 ( struct V_16 * V_8 , int V_17 ,
T_1 V_18 , int V_19 )
{
struct V_20 * V_20 ;
V_20 = F_14 ( V_19 , V_18 , V_17 ) ;
if ( ! V_20 ) {
V_20 = F_15 ( V_18 , V_17 ) ;
if ( ! V_20 )
return - V_21 ;
}
F_16 ( V_8 , V_20 , V_22 << V_17 , 0 ) ;
return 0 ;
}
static int F_17 ( struct V_23 * V_2 , struct V_16 * V_8 ,
int V_17 , T_1 V_18 )
{
void * V_24 = F_18 ( V_2 , V_22 << V_17 ,
& F_9 ( V_8 ) , V_18 ) ;
if ( ! V_24 )
return - V_21 ;
F_19 ( V_8 , V_24 , V_22 << V_17 ) ;
F_20 ( V_8 -> V_25 ) ;
F_21 ( V_8 ) = V_22 << V_17 ;
return 0 ;
}
struct V_12 * F_22 ( struct V_1 * V_2 , int V_9 ,
T_1 V_18 , int V_14 )
{
struct V_12 * V_13 ;
struct V_3 * V_4 = NULL ;
int V_26 ;
int V_27 ;
F_20 ( V_14 && ( V_18 & V_28 ) ) ;
V_13 = F_23 ( sizeof( * V_13 ) ,
V_18 & ~ ( V_28 | V_29 ) ,
V_2 -> V_30 ) ;
if ( ! V_13 ) {
V_13 = F_24 ( sizeof( * V_13 ) ,
V_18 & ~ ( V_28 | V_29 ) ) ;
if ( ! V_13 )
return NULL ;
}
V_13 -> V_31 = 0 ;
F_25 ( & V_13 -> V_32 ) ;
V_26 = F_5 ( V_33 ) ;
while ( V_9 > 0 ) {
if ( ! V_4 ) {
V_4 = F_23 ( sizeof( * V_4 ) ,
V_18 & ~ ( V_28 |
V_29 ) ,
V_2 -> V_30 ) ;
if ( ! V_4 ) {
V_4 = F_24 ( sizeof( * V_4 ) ,
V_18 & ~ ( V_28 |
V_29 ) ) ;
if ( ! V_4 )
goto V_34;
}
F_26 ( V_4 -> V_8 , V_35 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_6 = 0 ;
F_27 ( & V_4 -> V_36 , & V_13 -> V_32 ) ;
}
while ( 1 << V_26 > V_9 )
-- V_26 ;
if ( V_14 )
V_27 = F_17 ( & V_2 -> V_7 -> V_2 ,
& V_4 -> V_8 [ V_4 -> V_9 ] ,
V_26 , V_18 ) ;
else
V_27 = F_13 ( & V_4 -> V_8 [ V_4 -> V_9 ] ,
V_26 , V_18 ,
V_2 -> V_30 ) ;
if ( V_27 ) {
if ( -- V_26 < 0 )
goto V_34;
else
continue;
}
++ V_4 -> V_9 ;
if ( V_14 )
++ V_4 -> V_6 ;
else if ( V_4 -> V_9 == V_35 ) {
V_4 -> V_6 = F_28 ( V_2 -> V_7 , V_4 -> V_8 ,
V_4 -> V_9 ,
V_10 ) ;
if ( V_4 -> V_6 <= 0 )
goto V_34;
}
if ( V_4 -> V_9 == V_35 )
V_4 = NULL ;
V_9 -= 1 << V_26 ;
}
if ( ! V_14 && V_4 ) {
V_4 -> V_6 = F_28 ( V_2 -> V_7 , V_4 -> V_8 ,
V_4 -> V_9 ,
V_10 ) ;
if ( V_4 -> V_6 <= 0 )
goto V_34;
}
return V_13 ;
V_34:
F_10 ( V_2 , V_13 , V_14 ) ;
return NULL ;
}
static int F_29 ( struct V_1 * V_2 , struct V_12 * V_13 , T_2 V_37 )
{
return F_30 ( V_2 , V_38 , V_13 , V_37 ) ;
}
static int F_31 ( struct V_1 * V_2 , T_2 V_37 , T_3 V_39 )
{
return F_32 ( V_2 , V_37 , V_39 , 0 , V_40 ,
V_41 , V_42 ) ;
}
int F_33 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
return F_30 ( V_2 , V_43 , V_13 , - 1 ) ;
}
int F_34 ( struct V_1 * V_2 )
{
return F_32 ( V_2 , 0 , 0 , 0 , V_44 ,
V_41 , V_42 ) ;
}
int F_35 ( struct V_1 * V_2 , struct V_45 * V_46 , T_3 V_47 )
{
T_3 V_5 = ( V_47 & ( V_46 -> V_48 - 1 ) ) /
( V_49 / V_46 -> V_50 ) ;
int V_27 = 0 ;
F_36 ( & V_46 -> V_51 ) ;
if ( V_46 -> V_13 [ V_5 ] ) {
++ V_46 -> V_13 [ V_5 ] -> V_31 ;
goto V_52;
}
V_46 -> V_13 [ V_5 ] = F_22 ( V_2 , V_49 >> V_53 ,
( V_46 -> V_54 ? V_55 : V_56 ) |
V_29 , V_46 -> V_14 ) ;
if ( ! V_46 -> V_13 [ V_5 ] ) {
V_27 = - V_21 ;
goto V_52;
}
if ( F_29 ( V_2 , V_46 -> V_13 [ V_5 ] , V_46 -> V_37 +
( T_2 ) V_5 * V_49 ) ) {
F_10 ( V_2 , V_46 -> V_13 [ V_5 ] , V_46 -> V_14 ) ;
V_46 -> V_13 [ V_5 ] = NULL ;
V_27 = - V_21 ;
goto V_52;
}
++ V_46 -> V_13 [ V_5 ] -> V_31 ;
V_52:
F_37 ( & V_46 -> V_51 ) ;
return V_27 ;
}
void F_38 ( struct V_1 * V_2 , struct V_45 * V_46 , T_3 V_47 )
{
T_3 V_5 ;
T_2 V_25 ;
V_5 = ( V_47 & ( V_46 -> V_48 - 1 ) ) / ( V_49 / V_46 -> V_50 ) ;
F_36 ( & V_46 -> V_51 ) ;
if ( -- V_46 -> V_13 [ V_5 ] -> V_31 == 0 ) {
V_25 = ( T_2 ) V_5 * V_49 ;
F_31 ( V_2 , V_46 -> V_37 + V_25 ,
V_49 / V_57 ) ;
F_10 ( V_2 , V_46 -> V_13 [ V_5 ] , V_46 -> V_14 ) ;
V_46 -> V_13 [ V_5 ] = NULL ;
}
F_37 ( & V_46 -> V_51 ) ;
}
void * F_39 ( struct V_45 * V_46 , T_3 V_47 ,
T_4 * V_58 )
{
int V_25 , V_59 , V_5 ;
T_2 V_60 ;
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_20 * V_20 = NULL ;
if ( ! V_46 -> V_54 )
return NULL ;
F_36 ( & V_46 -> V_51 ) ;
V_60 = ( T_2 ) ( V_47 & ( V_46 -> V_48 - 1 ) ) * V_46 -> V_50 ;
V_13 = V_46 -> V_13 [ V_60 / V_49 ] ;
V_59 = V_25 = V_60 % V_49 ;
if ( ! V_13 )
goto V_52;
F_40 (chunk, &icm->chunk_list, list) {
for ( V_5 = 0 ; V_5 < V_4 -> V_9 ; ++ V_5 ) {
if ( V_58 && V_59 >= 0 ) {
if ( F_21 ( & V_4 -> V_8 [ V_5 ] ) > V_59 )
* V_58 = F_9 ( & V_4 -> V_8 [ V_5 ] ) +
V_59 ;
V_59 -= F_21 ( & V_4 -> V_8 [ V_5 ] ) ;
}
if ( V_4 -> V_8 [ V_5 ] . V_11 > V_25 ) {
V_20 = F_4 ( & V_4 -> V_8 [ V_5 ] ) ;
goto V_52;
}
V_25 -= V_4 -> V_8 [ V_5 ] . V_11 ;
}
}
V_52:
F_37 ( & V_46 -> V_51 ) ;
return V_20 ? F_8 ( V_20 ) + V_25 : NULL ;
}
int F_41 ( struct V_1 * V_2 , struct V_45 * V_46 ,
T_3 V_61 , T_3 V_62 )
{
int V_63 = V_49 / V_46 -> V_50 ;
int V_64 ;
T_3 V_5 ;
for ( V_5 = V_61 ; V_5 <= V_62 ; V_5 += V_63 ) {
V_64 = F_35 ( V_2 , V_46 , V_5 ) ;
if ( V_64 )
goto V_34;
}
return 0 ;
V_34:
while ( V_5 > V_61 ) {
V_5 -= V_63 ;
F_38 ( V_2 , V_46 , V_5 ) ;
}
return V_64 ;
}
void F_42 ( struct V_1 * V_2 , struct V_45 * V_46 ,
T_3 V_61 , T_3 V_62 )
{
T_3 V_5 ;
for ( V_5 = V_61 ; V_5 <= V_62 ; V_5 += V_49 / V_46 -> V_50 )
F_38 ( V_2 , V_46 , V_5 ) ;
}
int F_43 ( struct V_1 * V_2 , struct V_45 * V_46 ,
T_2 V_37 , int V_50 , T_3 V_65 , int V_66 ,
int V_67 , int V_68 )
{
int V_69 ;
int V_70 ;
unsigned V_71 ;
int V_5 ;
T_2 V_72 ;
V_69 = V_49 / V_50 ;
V_70 = ( V_65 + V_69 - 1 ) / V_69 ;
V_46 -> V_13 = F_44 ( V_70 , sizeof * V_46 -> V_13 , V_55 ) ;
if ( ! V_46 -> V_13 )
return - V_21 ;
V_46 -> V_37 = V_37 ;
V_46 -> V_70 = V_70 ;
V_46 -> V_48 = V_65 ;
V_46 -> V_50 = V_50 ;
V_46 -> V_54 = V_67 ;
V_46 -> V_14 = V_68 ;
F_45 ( & V_46 -> V_51 ) ;
V_72 = ( T_2 ) V_65 * V_50 ;
for ( V_5 = 0 ; V_5 * V_49 < V_66 * V_50 ; ++ V_5 ) {
V_71 = V_49 ;
if ( ( V_5 + 1 ) * V_49 > V_72 )
V_71 = F_46 ( V_72 -
V_5 * V_49 ) ;
V_46 -> V_13 [ V_5 ] = F_22 ( V_2 , V_71 >> V_53 ,
( V_67 ? V_55 : V_56 ) |
V_29 , V_68 ) ;
if ( ! V_46 -> V_13 [ V_5 ] )
goto V_64;
if ( F_29 ( V_2 , V_46 -> V_13 [ V_5 ] , V_37 + V_5 * V_49 ) ) {
F_10 ( V_2 , V_46 -> V_13 [ V_5 ] , V_68 ) ;
V_46 -> V_13 [ V_5 ] = NULL ;
goto V_64;
}
++ V_46 -> V_13 [ V_5 ] -> V_31 ;
}
return 0 ;
V_64:
for ( V_5 = 0 ; V_5 < V_70 ; ++ V_5 )
if ( V_46 -> V_13 [ V_5 ] ) {
F_31 ( V_2 , V_37 + V_5 * V_49 ,
V_49 / V_57 ) ;
F_10 ( V_2 , V_46 -> V_13 [ V_5 ] , V_68 ) ;
}
F_12 ( V_46 -> V_13 ) ;
return - V_21 ;
}
void F_47 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_46 -> V_70 ; ++ V_5 )
if ( V_46 -> V_13 [ V_5 ] ) {
F_31 ( V_2 , V_46 -> V_37 + V_5 * V_49 ,
V_49 / V_57 ) ;
F_10 ( V_2 , V_46 -> V_13 [ V_5 ] , V_46 -> V_14 ) ;
}
F_12 ( V_46 -> V_13 ) ;
}
