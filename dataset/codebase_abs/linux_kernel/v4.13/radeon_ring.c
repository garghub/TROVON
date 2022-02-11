bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
switch ( V_4 -> V_5 ) {
case V_6 :
case V_7 :
case V_8 :
return true ;
default:
return false ;
}
}
void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_9 = F_3 ( V_2 , V_4 ) ;
V_4 -> V_10 = V_9 + ( V_4 -> V_11 / 4 ) ;
V_4 -> V_10 -= V_4 -> V_12 ;
V_4 -> V_10 &= V_4 -> V_13 ;
if ( ! V_4 -> V_10 ) {
V_4 -> V_10 = V_4 -> V_11 / 4 ;
F_4 ( V_2 , V_4 ) ;
}
}
int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned V_14 )
{
int V_15 ;
if ( V_14 > ( V_4 -> V_11 / 4 ) )
return - V_16 ;
F_2 ( V_2 , V_4 ) ;
V_14 = ( V_14 + V_4 -> V_17 ) & ~ V_4 -> V_17 ;
while ( V_14 > ( V_4 -> V_10 - 1 ) ) {
F_2 ( V_2 , V_4 ) ;
if ( V_14 < V_4 -> V_10 ) {
break;
}
V_15 = F_6 ( V_2 , V_4 -> V_5 ) ;
if ( V_15 )
return V_15 ;
}
V_4 -> V_18 = V_14 ;
V_4 -> V_19 = V_4 -> V_12 ;
return 0 ;
}
int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned V_14 )
{
int V_15 ;
F_8 ( & V_2 -> V_20 ) ;
V_15 = F_5 ( V_2 , V_4 , V_14 ) ;
if ( V_15 ) {
F_9 ( & V_2 -> V_20 ) ;
return V_15 ;
}
return 0 ;
}
void F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool V_21 )
{
if ( V_21 && V_2 -> V_22 -> V_4 [ V_4 -> V_5 ] -> V_21 )
V_2 -> V_22 -> V_4 [ V_4 -> V_5 ] -> V_21 ( V_2 , V_4 ) ;
while ( V_4 -> V_12 & V_4 -> V_17 ) {
F_11 ( V_4 , V_4 -> V_23 ) ;
}
F_12 () ;
if ( V_21 && V_2 -> V_22 -> V_24 )
V_2 -> V_22 -> V_24 ( V_2 ) ;
F_13 ( V_2 , V_4 ) ;
}
void F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
bool V_21 )
{
F_10 ( V_2 , V_4 , V_21 ) ;
F_9 ( & V_2 -> V_20 ) ;
}
void F_15 ( struct V_3 * V_4 )
{
V_4 -> V_12 = V_4 -> V_19 ;
}
void F_16 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_15 ( V_4 ) ;
F_9 ( & V_2 -> V_20 ) ;
}
void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_17 ( & V_4 -> V_25 , F_3 ( V_2 , V_4 ) ) ;
F_18 ( & V_4 -> V_26 , V_27 ) ;
}
bool F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_9 = F_3 ( V_2 , V_4 ) ;
T_2 V_28 = F_20 ( & V_4 -> V_26 ) ;
T_2 V_29 ;
if ( V_9 != F_21 ( & V_4 -> V_25 ) ) {
F_4 ( V_2 , V_4 ) ;
return false ;
}
V_29 = F_22 ( V_27 - V_28 ) ;
if ( V_30 && V_29 >= V_30 ) {
F_23 ( V_2 -> V_31 , L_1 ,
V_4 -> V_5 , V_29 ) ;
return true ;
}
return false ;
}
unsigned F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 * * V_32 )
{
unsigned V_33 , V_34 , V_35 ;
F_8 ( & V_2 -> V_20 ) ;
* V_32 = NULL ;
if ( V_4 -> V_36 == NULL ) {
F_9 ( & V_2 -> V_20 ) ;
return 0 ;
}
if ( ! F_25 ( V_2 , V_4 -> V_5 ) ) {
F_9 ( & V_2 -> V_20 ) ;
return 0 ;
}
if ( V_4 -> V_37 )
V_34 = F_26 ( V_4 -> V_37 ) ;
else if ( V_2 -> V_38 . V_39 )
V_34 = F_27 ( * V_4 -> V_40 ) ;
else {
F_9 ( & V_2 -> V_20 ) ;
return 0 ;
}
V_33 = V_4 -> V_12 + ( V_4 -> V_11 / 4 ) ;
V_33 -= V_34 ;
V_33 &= V_4 -> V_13 ;
if ( V_33 == 0 ) {
F_9 ( & V_2 -> V_20 ) ;
return 0 ;
}
* V_32 = F_28 ( V_33 , sizeof( T_1 ) , V_41 ) ;
if ( ! * V_32 ) {
F_9 ( & V_2 -> V_20 ) ;
return 0 ;
}
for ( V_35 = 0 ; V_35 < V_33 ; ++ V_35 ) {
( * V_32 ) [ V_35 ] = V_4 -> V_4 [ V_34 ++ ] ;
V_34 &= V_4 -> V_13 ;
}
F_9 ( & V_2 -> V_20 ) ;
return V_33 ;
}
int F_29 ( struct V_1 * V_2 , struct V_3 * V_4 ,
unsigned V_33 , T_1 * V_32 )
{
int V_35 , V_15 ;
if ( ! V_33 || ! V_32 )
return 0 ;
V_15 = F_7 ( V_2 , V_4 , V_33 ) ;
if ( V_15 )
return V_15 ;
for ( V_35 = 0 ; V_35 < V_33 ; ++ V_35 ) {
F_11 ( V_4 , V_32 [ V_35 ] ) ;
}
F_14 ( V_2 , V_4 , false ) ;
F_30 ( V_32 ) ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 , struct V_3 * V_4 , unsigned V_11 ,
unsigned V_42 , T_3 V_23 )
{
int V_15 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_42 = V_42 ;
V_4 -> V_23 = V_23 ;
if ( V_4 -> V_36 == NULL ) {
V_15 = F_32 ( V_2 , V_4 -> V_11 , V_43 , true ,
V_44 , 0 , NULL ,
NULL , & V_4 -> V_36 ) ;
if ( V_15 ) {
F_23 ( V_2 -> V_31 , L_2 , V_15 ) ;
return V_15 ;
}
V_15 = F_33 ( V_4 -> V_36 , false ) ;
if ( F_34 ( V_15 != 0 ) )
return V_15 ;
V_15 = F_35 ( V_4 -> V_36 , V_44 ,
& V_4 -> V_45 ) ;
if ( V_15 ) {
F_36 ( V_4 -> V_36 ) ;
F_23 ( V_2 -> V_31 , L_3 , V_15 ) ;
return V_15 ;
}
V_15 = F_37 ( V_4 -> V_36 ,
( void * * ) & V_4 -> V_4 ) ;
F_36 ( V_4 -> V_36 ) ;
if ( V_15 ) {
F_23 ( V_2 -> V_31 , L_4 , V_15 ) ;
return V_15 ;
}
}
V_4 -> V_13 = ( V_4 -> V_11 / 4 ) - 1 ;
V_4 -> V_10 = V_4 -> V_11 / 4 ;
if ( V_2 -> V_38 . V_39 ) {
T_3 V_46 = V_47 + ( V_4 -> V_5 * 4 ) ;
V_4 -> V_48 = V_2 -> V_38 . V_45 + V_46 ;
V_4 -> V_40 = & V_2 -> V_38 . V_38 [ V_46 / 4 ] ;
}
if ( F_38 ( V_2 , V_4 ) ) {
F_39 ( L_5 ) ;
}
F_4 ( V_2 , V_4 ) ;
return 0 ;
}
void F_40 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_15 ;
struct V_49 * V_36 ;
F_8 ( & V_2 -> V_20 ) ;
V_36 = V_4 -> V_36 ;
V_4 -> V_50 = false ;
V_4 -> V_4 = NULL ;
V_4 -> V_36 = NULL ;
F_9 ( & V_2 -> V_20 ) ;
if ( V_36 ) {
V_15 = F_33 ( V_36 , false ) ;
if ( F_41 ( V_15 == 0 ) ) {
F_42 ( V_36 ) ;
F_43 ( V_36 ) ;
F_36 ( V_36 ) ;
}
F_44 ( & V_36 ) ;
}
}
static int F_45 ( struct V_51 * V_52 , void * V_32 )
{
struct V_53 * V_54 = (struct V_53 * ) V_52 -> V_55 ;
struct V_56 * V_31 = V_54 -> V_57 -> V_31 ;
struct V_1 * V_2 = V_31 -> V_58 ;
int V_59 = * ( int * ) V_54 -> V_60 -> V_32 ;
struct V_3 * V_4 = & V_2 -> V_4 [ V_59 ] ;
T_1 V_9 , V_12 , V_61 ;
unsigned V_62 , V_35 , V_63 ;
F_2 ( V_2 , V_4 ) ;
V_62 = ( V_4 -> V_11 / 4 ) - V_4 -> V_10 ;
V_12 = F_46 ( V_2 , V_4 ) ;
F_47 ( V_52 , L_6 ,
V_12 , V_12 ) ;
V_9 = F_3 ( V_2 , V_4 ) ;
F_47 ( V_52 , L_7 ,
V_9 , V_9 ) ;
if ( V_4 -> V_37 ) {
V_61 = F_26 ( V_4 -> V_37 ) ;
F_47 ( V_52 , L_8 ,
V_4 -> V_37 , V_61 , V_61 ) ;
} else
V_61 = ~ 0 ;
F_47 ( V_52 , L_9 ,
V_4 -> V_12 , V_4 -> V_12 ) ;
F_47 ( V_52 , L_10 ,
V_4 -> V_64 ) ;
F_47 ( V_52 , L_11 ,
V_4 -> V_65 ) ;
F_47 ( V_52 , L_12 , V_4 -> V_10 ) ;
F_47 ( V_52 , L_13 , V_62 ) ;
if ( ! V_4 -> V_4 )
return 0 ;
V_35 = ( V_9 + V_4 -> V_13 + 1 - 32 ) & V_4 -> V_13 ;
for ( V_63 = 0 ; V_63 <= ( V_62 + 32 ) ; V_63 ++ ) {
F_47 ( V_52 , L_14 , V_35 , V_4 -> V_4 [ V_35 ] ) ;
if ( V_9 == V_35 )
F_48 ( V_52 , L_15 ) ;
if ( V_61 == V_35 )
F_48 ( V_52 , L_16 ) ;
F_48 ( V_52 , L_17 ) ;
V_35 = ( V_35 + 1 ) & V_4 -> V_13 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#if F_49 ( V_66 )
unsigned V_35 ;
for ( V_35 = 0 ; V_35 < F_50 ( V_67 ) ; ++ V_35 ) {
struct V_68 * V_69 = & V_67 [ V_35 ] ;
int V_59 = * ( int * ) V_67 [ V_35 ] . V_32 ;
unsigned V_15 ;
if ( & V_2 -> V_4 [ V_59 ] != V_4 )
continue;
V_15 = F_51 ( V_2 , V_69 , 1 ) ;
if ( V_15 )
return V_15 ;
}
#endif
return 0 ;
}
