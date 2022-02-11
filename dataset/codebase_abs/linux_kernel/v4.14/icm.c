static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
if ( V_4 -> V_6 > 0 )
F_2 ( V_2 -> V_7 -> V_8 , V_4 -> V_9 , V_4 -> V_10 ,
V_11 ) ;
for ( V_5 = 0 ; V_5 < V_4 -> V_10 ; ++ V_5 )
F_3 ( F_4 ( & V_4 -> V_9 [ V_5 ] ) ,
F_5 ( V_4 -> V_9 [ V_5 ] . V_12 ) ) ;
}
static void F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_4 -> V_10 ; ++ V_5 )
F_7 ( & V_2 -> V_7 -> V_8 -> V_2 ,
V_4 -> V_9 [ V_5 ] . V_12 ,
F_8 ( F_4 ( & V_4 -> V_9 [ V_5 ] ) ) ,
F_9 ( & V_4 -> V_9 [ V_5 ] ) ) ;
}
void F_10 ( struct V_1 * V_2 , struct V_13 * V_14 , int V_15 )
{
struct V_3 * V_4 , * V_16 ;
if ( ! V_14 )
return;
F_11 (chunk, tmp, &icm->chunk_list, list) {
if ( V_15 )
F_6 ( V_2 , V_4 ) ;
else
F_1 ( V_2 , V_4 ) ;
F_12 ( V_4 ) ;
}
F_12 ( V_14 ) ;
}
static int F_13 ( struct V_17 * V_9 , int V_18 ,
T_1 V_19 , int V_20 )
{
struct V_21 * V_21 ;
V_21 = F_14 ( V_20 , V_19 , V_18 ) ;
if ( ! V_21 ) {
V_21 = F_15 ( V_19 , V_18 ) ;
if ( ! V_21 )
return - V_22 ;
}
F_16 ( V_9 , V_21 , V_23 << V_18 , 0 ) ;
return 0 ;
}
static int F_17 ( struct V_24 * V_2 , struct V_17 * V_9 ,
int V_18 , T_1 V_19 )
{
void * V_25 = F_18 ( V_2 , V_23 << V_18 ,
& F_9 ( V_9 ) , V_19 ) ;
if ( ! V_25 )
return - V_22 ;
if ( F_19 ( V_25 ) ) {
F_7 ( V_2 , V_23 << V_18 ,
V_25 , F_9 ( V_9 ) ) ;
return - V_22 ;
}
F_20 ( V_9 , V_25 , V_23 << V_18 ) ;
F_21 ( V_9 ) = V_23 << V_18 ;
return 0 ;
}
struct V_13 * F_22 ( struct V_1 * V_2 , int V_10 ,
T_1 V_19 , int V_15 )
{
struct V_13 * V_14 ;
struct V_3 * V_4 = NULL ;
int V_26 ;
int V_27 ;
F_23 ( V_15 && ( V_19 & V_28 ) ) ;
V_14 = F_24 ( sizeof( * V_14 ) ,
V_19 & ~ ( V_28 | V_29 ) ,
V_2 -> V_30 ) ;
if ( ! V_14 ) {
V_14 = F_25 ( sizeof( * V_14 ) ,
V_19 & ~ ( V_28 | V_29 ) ) ;
if ( ! V_14 )
return NULL ;
}
V_14 -> V_31 = 0 ;
F_26 ( & V_14 -> V_32 ) ;
V_26 = F_5 ( V_33 ) ;
while ( V_10 > 0 ) {
if ( ! V_4 ) {
V_4 = F_24 ( sizeof( * V_4 ) ,
V_19 & ~ ( V_28 |
V_29 ) ,
V_2 -> V_30 ) ;
if ( ! V_4 ) {
V_4 = F_25 ( sizeof( * V_4 ) ,
V_19 & ~ ( V_28 |
V_29 ) ) ;
if ( ! V_4 )
goto V_34;
}
F_27 ( V_4 -> V_9 , V_35 ) ;
V_4 -> V_10 = 0 ;
V_4 -> V_6 = 0 ;
F_28 ( & V_4 -> V_36 , & V_14 -> V_32 ) ;
}
while ( 1 << V_26 > V_10 )
-- V_26 ;
if ( V_15 )
V_27 = F_17 ( & V_2 -> V_7 -> V_8 -> V_2 ,
& V_4 -> V_9 [ V_4 -> V_10 ] ,
V_26 , V_19 ) ;
else
V_27 = F_13 ( & V_4 -> V_9 [ V_4 -> V_10 ] ,
V_26 , V_19 ,
V_2 -> V_30 ) ;
if ( V_27 ) {
if ( -- V_26 < 0 )
goto V_34;
else
continue;
}
++ V_4 -> V_10 ;
if ( V_15 )
++ V_4 -> V_6 ;
else if ( V_4 -> V_10 == V_35 ) {
V_4 -> V_6 = F_29 ( V_2 -> V_7 -> V_8 , V_4 -> V_9 ,
V_4 -> V_10 ,
V_11 ) ;
if ( V_4 -> V_6 <= 0 )
goto V_34;
}
if ( V_4 -> V_10 == V_35 )
V_4 = NULL ;
V_10 -= 1 << V_26 ;
}
if ( ! V_15 && V_4 ) {
V_4 -> V_6 = F_29 ( V_2 -> V_7 -> V_8 , V_4 -> V_9 ,
V_4 -> V_10 ,
V_11 ) ;
if ( V_4 -> V_6 <= 0 )
goto V_34;
}
return V_14 ;
V_34:
F_10 ( V_2 , V_14 , V_15 ) ;
return NULL ;
}
static int F_30 ( struct V_1 * V_2 , struct V_13 * V_14 , T_2 V_37 )
{
return F_31 ( V_2 , V_38 , V_14 , V_37 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_2 V_37 , T_3 V_39 )
{
return F_33 ( V_2 , V_37 , V_39 , 0 , V_40 ,
V_41 , V_42 ) ;
}
int F_34 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
return F_31 ( V_2 , V_43 , V_14 , - 1 ) ;
}
int F_35 ( struct V_1 * V_2 )
{
return F_33 ( V_2 , 0 , 0 , 0 , V_44 ,
V_41 , V_42 ) ;
}
int F_36 ( struct V_1 * V_2 , struct V_45 * V_46 , T_3 V_47 )
{
T_3 V_5 = ( V_47 & ( V_46 -> V_48 - 1 ) ) /
( V_49 / V_46 -> V_50 ) ;
int V_27 = 0 ;
F_37 ( & V_46 -> V_51 ) ;
if ( V_46 -> V_14 [ V_5 ] ) {
++ V_46 -> V_14 [ V_5 ] -> V_31 ;
goto V_52;
}
V_46 -> V_14 [ V_5 ] = F_22 ( V_2 , V_49 >> V_53 ,
( V_46 -> V_54 ? V_55 : V_56 ) |
V_29 , V_46 -> V_15 ) ;
if ( ! V_46 -> V_14 [ V_5 ] ) {
V_27 = - V_22 ;
goto V_52;
}
if ( F_30 ( V_2 , V_46 -> V_14 [ V_5 ] , V_46 -> V_37 +
( T_2 ) V_5 * V_49 ) ) {
F_10 ( V_2 , V_46 -> V_14 [ V_5 ] , V_46 -> V_15 ) ;
V_46 -> V_14 [ V_5 ] = NULL ;
V_27 = - V_22 ;
goto V_52;
}
++ V_46 -> V_14 [ V_5 ] -> V_31 ;
V_52:
F_38 ( & V_46 -> V_51 ) ;
return V_27 ;
}
void F_39 ( struct V_1 * V_2 , struct V_45 * V_46 , T_3 V_47 )
{
T_3 V_5 ;
T_2 V_57 ;
V_5 = ( V_47 & ( V_46 -> V_48 - 1 ) ) / ( V_49 / V_46 -> V_50 ) ;
F_37 ( & V_46 -> V_51 ) ;
if ( -- V_46 -> V_14 [ V_5 ] -> V_31 == 0 ) {
V_57 = ( T_2 ) V_5 * V_49 ;
F_32 ( V_2 , V_46 -> V_37 + V_57 ,
V_49 / V_58 ) ;
F_10 ( V_2 , V_46 -> V_14 [ V_5 ] , V_46 -> V_15 ) ;
V_46 -> V_14 [ V_5 ] = NULL ;
}
F_38 ( & V_46 -> V_51 ) ;
}
void * F_40 ( struct V_45 * V_46 , T_3 V_47 ,
T_4 * V_59 )
{
int V_57 , V_60 , V_5 ;
T_2 V_61 ;
struct V_3 * V_4 ;
struct V_13 * V_14 ;
struct V_21 * V_21 = NULL ;
if ( ! V_46 -> V_54 )
return NULL ;
F_37 ( & V_46 -> V_51 ) ;
V_61 = ( T_2 ) ( V_47 & ( V_46 -> V_48 - 1 ) ) * V_46 -> V_50 ;
V_14 = V_46 -> V_14 [ V_61 / V_49 ] ;
V_60 = V_57 = V_61 % V_49 ;
if ( ! V_14 )
goto V_52;
F_41 (chunk, &icm->chunk_list, list) {
for ( V_5 = 0 ; V_5 < V_4 -> V_10 ; ++ V_5 ) {
if ( V_59 && V_60 >= 0 ) {
if ( F_21 ( & V_4 -> V_9 [ V_5 ] ) > V_60 )
* V_59 = F_9 ( & V_4 -> V_9 [ V_5 ] ) +
V_60 ;
V_60 -= F_21 ( & V_4 -> V_9 [ V_5 ] ) ;
}
if ( V_4 -> V_9 [ V_5 ] . V_12 > V_57 ) {
V_21 = F_4 ( & V_4 -> V_9 [ V_5 ] ) ;
goto V_52;
}
V_57 -= V_4 -> V_9 [ V_5 ] . V_12 ;
}
}
V_52:
F_38 ( & V_46 -> V_51 ) ;
return V_21 ? F_8 ( V_21 ) + V_57 : NULL ;
}
int F_42 ( struct V_1 * V_2 , struct V_45 * V_46 ,
T_3 V_62 , T_3 V_63 )
{
int V_64 = V_49 / V_46 -> V_50 ;
int V_65 ;
T_3 V_5 ;
for ( V_5 = V_62 ; V_5 <= V_63 ; V_5 += V_64 ) {
V_65 = F_36 ( V_2 , V_46 , V_5 ) ;
if ( V_65 )
goto V_34;
}
return 0 ;
V_34:
while ( V_5 > V_62 ) {
V_5 -= V_64 ;
F_39 ( V_2 , V_46 , V_5 ) ;
}
return V_65 ;
}
void F_43 ( struct V_1 * V_2 , struct V_45 * V_46 ,
T_3 V_62 , T_3 V_63 )
{
T_3 V_5 ;
for ( V_5 = V_62 ; V_5 <= V_63 ; V_5 += V_49 / V_46 -> V_50 )
F_39 ( V_2 , V_46 , V_5 ) ;
}
int F_44 ( struct V_1 * V_2 , struct V_45 * V_46 ,
T_2 V_37 , int V_50 , T_3 V_66 , int V_67 ,
int V_68 , int V_69 )
{
int V_70 ;
int V_71 ;
unsigned V_72 ;
int V_5 ;
T_2 V_73 ;
V_70 = V_49 / V_50 ;
V_71 = ( V_66 + V_70 - 1 ) / V_70 ;
V_46 -> V_14 = F_45 ( V_71 , sizeof( * V_46 -> V_14 ) , V_55 ) ;
if ( ! V_46 -> V_14 )
return - V_22 ;
V_46 -> V_37 = V_37 ;
V_46 -> V_71 = V_71 ;
V_46 -> V_48 = V_66 ;
V_46 -> V_50 = V_50 ;
V_46 -> V_54 = V_68 ;
V_46 -> V_15 = V_69 ;
F_46 ( & V_46 -> V_51 ) ;
V_73 = ( T_2 ) V_66 * V_50 ;
for ( V_5 = 0 ; V_5 * V_49 < V_67 * V_50 ; ++ V_5 ) {
V_72 = V_49 ;
if ( ( V_5 + 1 ) * V_49 > V_73 )
V_72 = F_47 ( V_73 -
V_5 * V_49 ) ;
V_46 -> V_14 [ V_5 ] = F_22 ( V_2 , V_72 >> V_53 ,
( V_68 ? V_55 : V_56 ) |
V_29 , V_69 ) ;
if ( ! V_46 -> V_14 [ V_5 ] )
goto V_65;
if ( F_30 ( V_2 , V_46 -> V_14 [ V_5 ] , V_37 + V_5 * V_49 ) ) {
F_10 ( V_2 , V_46 -> V_14 [ V_5 ] , V_69 ) ;
V_46 -> V_14 [ V_5 ] = NULL ;
goto V_65;
}
++ V_46 -> V_14 [ V_5 ] -> V_31 ;
}
return 0 ;
V_65:
for ( V_5 = 0 ; V_5 < V_71 ; ++ V_5 )
if ( V_46 -> V_14 [ V_5 ] ) {
F_32 ( V_2 , V_37 + V_5 * V_49 ,
V_49 / V_58 ) ;
F_10 ( V_2 , V_46 -> V_14 [ V_5 ] , V_69 ) ;
}
F_12 ( V_46 -> V_14 ) ;
return - V_22 ;
}
void F_48 ( struct V_1 * V_2 , struct V_45 * V_46 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_46 -> V_71 ; ++ V_5 )
if ( V_46 -> V_14 [ V_5 ] ) {
F_32 ( V_2 , V_46 -> V_37 + V_5 * V_49 ,
V_49 / V_58 ) ;
F_10 ( V_2 , V_46 -> V_14 [ V_5 ] , V_46 -> V_15 ) ;
}
F_12 ( V_46 -> V_14 ) ;
}
