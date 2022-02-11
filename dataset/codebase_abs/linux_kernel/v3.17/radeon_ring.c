void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
#if V_4
if ( V_2 -> V_5 <= 0 ) {
F_2 ( L_1 ) ;
}
#endif
V_2 -> V_2 [ V_2 -> V_6 ++ ] = V_3 ;
V_2 -> V_6 &= V_2 -> V_7 ;
V_2 -> V_5 -- ;
V_2 -> V_8 -- ;
}
bool F_3 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
switch ( V_2 -> V_11 ) {
case V_12 :
case V_13 :
case V_14 :
return true ;
default:
return false ;
}
}
void F_4 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
T_1 V_15 = F_5 ( V_10 , V_2 ) ;
V_2 -> V_8 = V_15 + ( V_2 -> V_16 / 4 ) ;
V_2 -> V_8 -= V_2 -> V_6 ;
V_2 -> V_8 &= V_2 -> V_7 ;
if ( ! V_2 -> V_8 ) {
V_2 -> V_8 = V_2 -> V_16 / 4 ;
F_6 ( V_10 , V_2 ) ;
}
}
int F_7 ( struct V_9 * V_10 , struct V_1 * V_2 , unsigned V_17 )
{
int V_18 ;
if ( V_17 > ( V_2 -> V_16 / 4 ) )
return - V_19 ;
F_4 ( V_10 , V_2 ) ;
V_17 = ( V_17 + V_2 -> V_20 ) & ~ V_2 -> V_20 ;
while ( V_17 > ( V_2 -> V_8 - 1 ) ) {
F_4 ( V_10 , V_2 ) ;
if ( V_17 < V_2 -> V_8 ) {
break;
}
V_18 = F_8 ( V_10 , V_2 -> V_11 ) ;
if ( V_18 )
return V_18 ;
}
V_2 -> V_5 = V_17 ;
V_2 -> V_21 = V_2 -> V_6 ;
return 0 ;
}
int F_9 ( struct V_9 * V_10 , struct V_1 * V_2 , unsigned V_17 )
{
int V_18 ;
F_10 ( & V_10 -> V_22 ) ;
V_18 = F_7 ( V_10 , V_2 , V_17 ) ;
if ( V_18 ) {
F_11 ( & V_10 -> V_22 ) ;
return V_18 ;
}
return 0 ;
}
void F_12 ( struct V_9 * V_10 , struct V_1 * V_2 ,
bool V_23 )
{
if ( V_23 && V_10 -> V_24 -> V_2 [ V_2 -> V_11 ] -> V_23 )
V_10 -> V_24 -> V_2 [ V_2 -> V_11 ] -> V_23 ( V_10 , V_2 ) ;
while ( V_2 -> V_6 & V_2 -> V_20 ) {
F_1 ( V_2 , V_2 -> V_25 ) ;
}
F_13 () ;
if ( V_23 && V_10 -> V_24 -> V_26 )
V_10 -> V_24 -> V_26 ( V_10 ) ;
F_14 ( V_10 , V_2 ) ;
}
void F_15 ( struct V_9 * V_10 , struct V_1 * V_2 ,
bool V_23 )
{
F_12 ( V_10 , V_2 , V_23 ) ;
F_11 ( & V_10 -> V_22 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
V_2 -> V_6 = V_2 -> V_21 ;
}
void F_17 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
F_11 ( & V_10 -> V_22 ) ;
}
void F_6 ( struct V_9 * V_10 ,
struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_27 , F_5 ( V_10 , V_2 ) ) ;
F_19 ( & V_2 -> V_28 , V_29 ) ;
}
bool F_20 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
T_1 V_15 = F_5 ( V_10 , V_2 ) ;
T_2 V_30 = F_21 ( & V_2 -> V_28 ) ;
T_2 V_31 ;
if ( V_15 != F_22 ( & V_2 -> V_27 ) ) {
F_6 ( V_10 , V_2 ) ;
return false ;
}
V_31 = F_23 ( V_29 - V_30 ) ;
if ( V_32 && V_31 >= V_32 ) {
F_24 ( V_10 -> V_33 , L_2 ,
V_2 -> V_11 , V_31 ) ;
return true ;
}
return false ;
}
unsigned F_25 ( struct V_9 * V_10 , struct V_1 * V_2 ,
T_1 * * V_34 )
{
unsigned V_35 , V_36 , V_37 ;
F_10 ( & V_10 -> V_22 ) ;
* V_34 = NULL ;
if ( V_2 -> V_38 == NULL ) {
F_11 ( & V_10 -> V_22 ) ;
return 0 ;
}
if ( ! F_26 ( V_10 , V_2 -> V_11 ) ) {
F_11 ( & V_10 -> V_22 ) ;
return 0 ;
}
if ( V_2 -> V_39 )
V_36 = F_27 ( V_2 -> V_39 ) ;
else if ( V_10 -> V_40 . V_41 )
V_36 = F_28 ( * V_2 -> V_42 ) ;
else {
F_11 ( & V_10 -> V_22 ) ;
return 0 ;
}
V_35 = V_2 -> V_6 + ( V_2 -> V_16 / 4 ) ;
V_35 -= V_36 ;
V_35 &= V_2 -> V_7 ;
if ( V_35 == 0 ) {
F_11 ( & V_10 -> V_22 ) ;
return 0 ;
}
* V_34 = F_29 ( V_35 , sizeof( T_1 ) , V_43 ) ;
if ( ! * V_34 ) {
F_11 ( & V_10 -> V_22 ) ;
return 0 ;
}
for ( V_37 = 0 ; V_37 < V_35 ; ++ V_37 ) {
( * V_34 ) [ V_37 ] = V_2 -> V_2 [ V_36 ++ ] ;
V_36 &= V_2 -> V_7 ;
}
F_11 ( & V_10 -> V_22 ) ;
return V_35 ;
}
int F_30 ( struct V_9 * V_10 , struct V_1 * V_2 ,
unsigned V_35 , T_1 * V_34 )
{
int V_37 , V_18 ;
if ( ! V_35 || ! V_34 )
return 0 ;
V_18 = F_9 ( V_10 , V_2 , V_35 ) ;
if ( V_18 )
return V_18 ;
for ( V_37 = 0 ; V_37 < V_35 ; ++ V_37 ) {
F_1 ( V_2 , V_34 [ V_37 ] ) ;
}
F_15 ( V_10 , V_2 , false ) ;
F_31 ( V_34 ) ;
return 0 ;
}
int F_32 ( struct V_9 * V_10 , struct V_1 * V_2 , unsigned V_16 ,
unsigned V_44 , T_3 V_25 )
{
int V_18 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_44 = V_44 ;
V_2 -> V_25 = V_25 ;
if ( V_2 -> V_38 == NULL ) {
V_18 = F_33 ( V_10 , V_2 -> V_16 , V_45 , true ,
V_46 , 0 ,
NULL , & V_2 -> V_38 ) ;
if ( V_18 ) {
F_24 ( V_10 -> V_33 , L_3 , V_18 ) ;
return V_18 ;
}
V_18 = F_34 ( V_2 -> V_38 , false ) ;
if ( F_35 ( V_18 != 0 ) )
return V_18 ;
V_18 = F_36 ( V_2 -> V_38 , V_46 ,
& V_2 -> V_47 ) ;
if ( V_18 ) {
F_37 ( V_2 -> V_38 ) ;
F_24 ( V_10 -> V_33 , L_4 , V_18 ) ;
return V_18 ;
}
V_18 = F_38 ( V_2 -> V_38 ,
( void * * ) & V_2 -> V_2 ) ;
F_37 ( V_2 -> V_38 ) ;
if ( V_18 ) {
F_24 ( V_10 -> V_33 , L_5 , V_18 ) ;
return V_18 ;
}
}
V_2 -> V_7 = ( V_2 -> V_16 / 4 ) - 1 ;
V_2 -> V_8 = V_2 -> V_16 / 4 ;
if ( V_10 -> V_40 . V_41 ) {
T_3 V_48 = V_49 + ( V_2 -> V_11 * 4 ) ;
V_2 -> V_50 = V_10 -> V_40 . V_47 + V_48 ;
V_2 -> V_42 = & V_10 -> V_40 . V_40 [ V_48 / 4 ] ;
}
if ( F_39 ( V_10 , V_2 ) ) {
F_2 ( L_6 ) ;
}
F_6 ( V_10 , V_2 ) ;
return 0 ;
}
void F_40 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
int V_18 ;
struct V_51 * V_38 ;
F_10 ( & V_10 -> V_22 ) ;
V_38 = V_2 -> V_38 ;
V_2 -> V_52 = false ;
V_2 -> V_2 = NULL ;
V_2 -> V_38 = NULL ;
F_11 ( & V_10 -> V_22 ) ;
if ( V_38 ) {
V_18 = F_34 ( V_38 , false ) ;
if ( F_41 ( V_18 == 0 ) ) {
F_42 ( V_38 ) ;
F_43 ( V_38 ) ;
F_37 ( V_38 ) ;
}
F_44 ( & V_38 ) ;
}
}
static int F_45 ( struct V_53 * V_54 , void * V_34 )
{
struct V_55 * V_56 = (struct V_55 * ) V_54 -> V_57 ;
struct V_58 * V_33 = V_56 -> V_59 -> V_33 ;
struct V_9 * V_10 = V_33 -> V_60 ;
int V_61 = * ( int * ) V_56 -> V_62 -> V_34 ;
struct V_1 * V_2 = & V_10 -> V_2 [ V_61 ] ;
T_1 V_15 , V_6 , V_63 ;
unsigned V_64 , V_37 , V_65 ;
F_4 ( V_10 , V_2 ) ;
V_64 = ( V_2 -> V_16 / 4 ) - V_2 -> V_8 ;
V_6 = F_46 ( V_10 , V_2 ) ;
F_47 ( V_54 , L_7 ,
V_6 , V_6 ) ;
V_15 = F_5 ( V_10 , V_2 ) ;
F_47 ( V_54 , L_8 ,
V_15 , V_15 ) ;
if ( V_2 -> V_39 ) {
V_63 = F_27 ( V_2 -> V_39 ) ;
F_47 ( V_54 , L_9 ,
V_2 -> V_39 , V_63 , V_63 ) ;
} else
V_63 = ~ 0 ;
F_47 ( V_54 , L_10 ,
V_2 -> V_6 , V_2 -> V_6 ) ;
F_47 ( V_54 , L_11 ,
V_2 -> V_66 ) ;
F_47 ( V_54 , L_12 ,
V_2 -> V_67 ) ;
F_47 ( V_54 , L_13 , V_2 -> V_8 ) ;
F_47 ( V_54 , L_14 , V_64 ) ;
if ( ! V_2 -> V_52 )
return 0 ;
V_37 = ( V_15 + V_2 -> V_7 + 1 - 32 ) & V_2 -> V_7 ;
for ( V_65 = 0 ; V_65 <= ( V_64 + 32 ) ; V_65 ++ ) {
F_47 ( V_54 , L_15 , V_37 , V_2 -> V_2 [ V_37 ] ) ;
if ( V_15 == V_37 )
F_48 ( V_54 , L_16 ) ;
if ( V_63 == V_37 )
F_48 ( V_54 , L_17 ) ;
F_48 ( V_54 , L_18 ) ;
V_37 = ( V_37 + 1 ) & V_2 -> V_7 ;
}
return 0 ;
}
static int F_39 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
#if F_49 ( V_68 )
unsigned V_37 ;
for ( V_37 = 0 ; V_37 < F_50 ( V_69 ) ; ++ V_37 ) {
struct V_70 * V_71 = & V_69 [ V_37 ] ;
int V_61 = * ( int * ) V_69 [ V_37 ] . V_34 ;
unsigned V_18 ;
if ( & V_10 -> V_2 [ V_61 ] != V_2 )
continue;
V_18 = F_51 ( V_10 , V_71 , 1 ) ;
if ( V_18 )
return V_18 ;
}
#endif
return 0 ;
}
