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
static int F_13 ( struct V_16 * V_8 , int V_17 , T_1 V_18 )
{
struct V_19 * V_19 ;
V_19 = F_14 ( V_18 , V_17 ) ;
if ( ! V_19 )
return - V_20 ;
F_15 ( V_8 , V_19 , V_21 << V_17 , 0 ) ;
return 0 ;
}
static int F_16 ( struct V_22 * V_2 , struct V_16 * V_8 ,
int V_17 , T_1 V_18 )
{
void * V_23 = F_17 ( V_2 , V_21 << V_17 ,
& F_9 ( V_8 ) , V_18 ) ;
if ( ! V_23 )
return - V_20 ;
F_18 ( V_8 , V_23 , V_21 << V_17 ) ;
F_19 ( V_8 -> V_24 ) ;
F_20 ( V_8 ) = V_21 << V_17 ;
return 0 ;
}
struct V_12 * F_21 ( struct V_1 * V_2 , int V_9 ,
T_1 V_18 , int V_14 )
{
struct V_12 * V_13 ;
struct V_3 * V_4 = NULL ;
int V_25 ;
int V_26 ;
F_19 ( V_14 && ( V_18 & V_27 ) ) ;
V_13 = F_22 ( sizeof *V_13 , V_18 & ~ ( V_27 | V_28 ) ) ;
if ( ! V_13 )
return NULL ;
V_13 -> V_29 = 0 ;
F_23 ( & V_13 -> V_30 ) ;
V_25 = F_5 ( V_31 ) ;
while ( V_9 > 0 ) {
if ( ! V_4 ) {
V_4 = F_22 ( sizeof *V_4 ,
V_18 & ~ ( V_27 | V_28 ) ) ;
if ( ! V_4 )
goto V_32;
F_24 ( V_4 -> V_8 , V_33 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_6 = 0 ;
F_25 ( & V_4 -> V_34 , & V_13 -> V_30 ) ;
}
while ( 1 << V_25 > V_9 )
-- V_25 ;
if ( V_14 )
V_26 = F_16 ( & V_2 -> V_7 -> V_2 ,
& V_4 -> V_8 [ V_4 -> V_9 ] ,
V_25 , V_18 ) ;
else
V_26 = F_13 ( & V_4 -> V_8 [ V_4 -> V_9 ] ,
V_25 , V_18 ) ;
if ( V_26 ) {
if ( -- V_25 < 0 )
goto V_32;
else
continue;
}
++ V_4 -> V_9 ;
if ( V_14 )
++ V_4 -> V_6 ;
else if ( V_4 -> V_9 == V_33 ) {
V_4 -> V_6 = F_26 ( V_2 -> V_7 , V_4 -> V_8 ,
V_4 -> V_9 ,
V_10 ) ;
if ( V_4 -> V_6 <= 0 )
goto V_32;
}
if ( V_4 -> V_9 == V_33 )
V_4 = NULL ;
V_9 -= 1 << V_25 ;
}
if ( ! V_14 && V_4 ) {
V_4 -> V_6 = F_26 ( V_2 -> V_7 , V_4 -> V_8 ,
V_4 -> V_9 ,
V_10 ) ;
if ( V_4 -> V_6 <= 0 )
goto V_32;
}
return V_13 ;
V_32:
F_10 ( V_2 , V_13 , V_14 ) ;
return NULL ;
}
static int F_27 ( struct V_1 * V_2 , struct V_12 * V_13 , T_2 V_35 )
{
return F_28 ( V_2 , V_36 , V_13 , V_35 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_2 V_35 , T_3 V_37 )
{
return F_30 ( V_2 , V_35 , V_37 , 0 , V_38 ,
V_39 , V_40 ) ;
}
int F_31 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
return F_28 ( V_2 , V_41 , V_13 , - 1 ) ;
}
int F_32 ( struct V_1 * V_2 )
{
return F_30 ( V_2 , 0 , 0 , 0 , V_42 ,
V_39 , V_40 ) ;
}
int F_33 ( struct V_1 * V_2 , struct V_43 * V_44 , int V_45 )
{
int V_5 = ( V_45 & ( V_44 -> V_46 - 1 ) ) / ( V_47 / V_44 -> V_48 ) ;
int V_26 = 0 ;
F_34 ( & V_44 -> V_49 ) ;
if ( V_44 -> V_13 [ V_5 ] ) {
++ V_44 -> V_13 [ V_5 ] -> V_29 ;
goto V_50;
}
V_44 -> V_13 [ V_5 ] = F_21 ( V_2 , V_47 >> V_51 ,
( V_44 -> V_52 ? V_53 : V_54 ) |
V_28 , V_44 -> V_14 ) ;
if ( ! V_44 -> V_13 [ V_5 ] ) {
V_26 = - V_20 ;
goto V_50;
}
if ( F_27 ( V_2 , V_44 -> V_13 [ V_5 ] , V_44 -> V_35 +
( T_2 ) V_5 * V_47 ) ) {
F_10 ( V_2 , V_44 -> V_13 [ V_5 ] , V_44 -> V_14 ) ;
V_44 -> V_13 [ V_5 ] = NULL ;
V_26 = - V_20 ;
goto V_50;
}
++ V_44 -> V_13 [ V_5 ] -> V_29 ;
V_50:
F_35 ( & V_44 -> V_49 ) ;
return V_26 ;
}
void F_36 ( struct V_1 * V_2 , struct V_43 * V_44 , int V_45 )
{
int V_5 ;
V_5 = ( V_45 & ( V_44 -> V_46 - 1 ) ) / ( V_47 / V_44 -> V_48 ) ;
F_34 ( & V_44 -> V_49 ) ;
if ( -- V_44 -> V_13 [ V_5 ] -> V_29 == 0 ) {
F_29 ( V_2 , V_44 -> V_35 + V_5 * V_47 ,
V_47 / V_55 ) ;
F_10 ( V_2 , V_44 -> V_13 [ V_5 ] , V_44 -> V_14 ) ;
V_44 -> V_13 [ V_5 ] = NULL ;
}
F_35 ( & V_44 -> V_49 ) ;
}
void * F_37 ( struct V_43 * V_44 , int V_45 , T_4 * V_56 )
{
int V_57 , V_24 , V_58 , V_5 ;
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_19 * V_19 = NULL ;
if ( ! V_44 -> V_52 )
return NULL ;
F_34 ( & V_44 -> V_49 ) ;
V_57 = ( V_45 & ( V_44 -> V_46 - 1 ) ) * V_44 -> V_48 ;
V_13 = V_44 -> V_13 [ V_57 / V_47 ] ;
V_58 = V_24 = V_57 % V_47 ;
if ( ! V_13 )
goto V_50;
F_38 (chunk, &icm->chunk_list, list) {
for ( V_5 = 0 ; V_5 < V_4 -> V_9 ; ++ V_5 ) {
if ( V_56 && V_58 >= 0 ) {
if ( F_20 ( & V_4 -> V_8 [ V_5 ] ) > V_58 )
* V_56 = F_9 ( & V_4 -> V_8 [ V_5 ] ) +
V_58 ;
V_58 -= F_20 ( & V_4 -> V_8 [ V_5 ] ) ;
}
if ( V_4 -> V_8 [ V_5 ] . V_11 > V_24 ) {
V_19 = F_4 ( & V_4 -> V_8 [ V_5 ] ) ;
goto V_50;
}
V_24 -= V_4 -> V_8 [ V_5 ] . V_11 ;
}
}
V_50:
F_35 ( & V_44 -> V_49 ) ;
return V_19 ? F_8 ( V_19 ) + V_24 : NULL ;
}
int F_39 ( struct V_1 * V_2 , struct V_43 * V_44 ,
int V_59 , int V_60 )
{
int V_61 = V_47 / V_44 -> V_48 ;
int V_5 , V_62 ;
for ( V_5 = V_59 ; V_5 <= V_60 ; V_5 += V_61 ) {
V_62 = F_33 ( V_2 , V_44 , V_5 ) ;
if ( V_62 )
goto V_32;
}
return 0 ;
V_32:
while ( V_5 > V_59 ) {
V_5 -= V_61 ;
F_36 ( V_2 , V_44 , V_5 ) ;
}
return V_62 ;
}
void F_40 ( struct V_1 * V_2 , struct V_43 * V_44 ,
int V_59 , int V_60 )
{
int V_5 ;
for ( V_5 = V_59 ; V_5 <= V_60 ; V_5 += V_47 / V_44 -> V_48 )
F_36 ( V_2 , V_44 , V_5 ) ;
}
int F_41 ( struct V_1 * V_2 , struct V_43 * V_44 ,
T_2 V_35 , int V_48 , int V_63 , int V_64 ,
int V_65 , int V_66 )
{
int V_67 ;
int V_68 ;
unsigned V_69 ;
int V_5 ;
V_67 = V_47 / V_48 ;
V_68 = ( V_63 + V_67 - 1 ) / V_67 ;
V_44 -> V_13 = F_42 ( V_68 , sizeof * V_44 -> V_13 , V_53 ) ;
if ( ! V_44 -> V_13 )
return - V_20 ;
V_44 -> V_35 = V_35 ;
V_44 -> V_68 = V_68 ;
V_44 -> V_46 = V_63 ;
V_44 -> V_48 = V_48 ;
V_44 -> V_52 = V_65 ;
V_44 -> V_14 = V_66 ;
F_43 ( & V_44 -> V_49 ) ;
for ( V_5 = 0 ; V_5 * V_47 < V_64 * V_48 ; ++ V_5 ) {
V_69 = V_47 ;
if ( ( V_5 + 1 ) * V_47 > V_63 * V_48 )
V_69 = F_44 ( V_63 * V_48 - V_5 * V_47 ) ;
V_44 -> V_13 [ V_5 ] = F_21 ( V_2 , V_69 >> V_51 ,
( V_65 ? V_53 : V_54 ) |
V_28 , V_66 ) ;
if ( ! V_44 -> V_13 [ V_5 ] )
goto V_62;
if ( F_27 ( V_2 , V_44 -> V_13 [ V_5 ] , V_35 + V_5 * V_47 ) ) {
F_10 ( V_2 , V_44 -> V_13 [ V_5 ] , V_66 ) ;
V_44 -> V_13 [ V_5 ] = NULL ;
goto V_62;
}
++ V_44 -> V_13 [ V_5 ] -> V_29 ;
}
return 0 ;
V_62:
for ( V_5 = 0 ; V_5 < V_68 ; ++ V_5 )
if ( V_44 -> V_13 [ V_5 ] ) {
F_29 ( V_2 , V_35 + V_5 * V_47 ,
V_47 / V_55 ) ;
F_10 ( V_2 , V_44 -> V_13 [ V_5 ] , V_66 ) ;
}
return - V_20 ;
}
void F_45 ( struct V_1 * V_2 , struct V_43 * V_44 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_44 -> V_68 ; ++ V_5 )
if ( V_44 -> V_13 [ V_5 ] ) {
F_29 ( V_2 , V_44 -> V_35 + V_5 * V_47 ,
V_47 / V_55 ) ;
F_10 ( V_2 , V_44 -> V_13 [ V_5 ] , V_44 -> V_14 ) ;
}
F_12 ( V_44 -> V_13 ) ;
}
