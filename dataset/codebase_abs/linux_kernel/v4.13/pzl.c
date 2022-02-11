static void F_1 ( struct V_1 * V_1 , int V_2 , T_1 V_3 )
{
switch ( V_2 ) {
case 0 :
F_2 ( & V_1 -> V_4 [ 0 ] , V_3 ) ;
F_2 ( & V_1 -> V_4 [ 2 ] , V_3 ) ;
F_2 ( & V_1 -> V_4 [ 4 ] , V_3 ) ;
F_2 ( & V_1 -> V_4 [ 6 ] , V_3 ) ;
F_2 ( & V_1 -> V_4 [ 8 ] , V_3 ) ;
F_2 ( & V_1 -> V_4 [ 10 ] , V_3 ) ;
F_2 ( & V_1 -> V_4 [ 12 ] , V_3 ) ;
F_2 ( & V_1 -> V_4 [ 14 ] , V_3 ) ;
break;
case 1 :
F_2 ( & V_1 -> V_4 [ 1 ] , V_3 ) ;
F_2 ( & V_1 -> V_4 [ 5 ] , V_3 ) ;
F_2 ( & V_1 -> V_4 [ 9 ] , V_3 ) ;
F_2 ( & V_1 -> V_4 [ 13 ] , V_3 ) ;
break;
case 2 :
F_2 ( & V_1 -> V_4 [ 3 ] , V_3 ) ;
F_2 ( & V_1 -> V_4 [ 11 ] , V_3 ) ;
break;
case 3 :
F_2 ( & V_1 -> V_4 [ 7 ] , V_3 ) ;
break;
case 4 :
F_2 ( & V_1 -> V_4 [ 15 ] , V_3 ) ;
break;
}
}
static int F_3 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
T_2 V_7 = V_6 -> V_8 -> V_9 . V_7 ;
if ( V_7 < 6 )
V_7 = 6 ;
if ( V_7 > 10 )
V_7 = 10 ;
return V_7 - 6 ;
}
static void F_4 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
int V_2 ;
V_2 = F_3 ( V_1 , V_6 ) ;
F_5 ( V_1 , V_6 ) ;
F_6 ( & V_6 -> V_10 , & V_1 -> V_11 [ V_2 ] ) ;
V_6 -> V_12 = true ;
}
static void F_7 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
F_6 ( & V_6 -> V_10 , & V_1 -> V_13 ) ;
V_6 -> V_14 = false ;
V_6 -> V_12 = false ;
}
static enum V_15 F_8 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
enum V_15 V_16 = 0 ;
T_3 V_17 = 0 ;
while ( V_6 -> V_18 ) {
struct V_19 * V_20 ;
int V_21 ;
V_21 = V_6 -> V_22 ;
V_20 = & V_6 -> V_23 [ V_6 -> V_22 ] ;
V_17 = F_9 ( V_20 -> V_17 ) ;
if ( V_17 & V_24 )
break;
if ( V_17 & V_25 ) {
F_10 ( V_1 , V_6 , V_20 ) ;
V_16 |= V_26 ;
goto V_27;
}
F_11 ( V_1 , V_6 , V_20 ) ;
}
if ( ! V_6 -> remove )
V_16 |= F_12 ( V_1 , V_6 ) ;
V_27:
if ( V_6 -> remove && V_6 -> V_18 == 0 ) {
F_7 ( V_1 , V_6 ) ;
V_16 |= V_28 ;
}
return V_16 ;
}
void F_13 ( struct V_1 * V_1 )
{
F_14 ( V_1 -> V_29 , V_1 -> V_30 + V_31 ) ;
F_15 ( V_1 , V_32 , V_32 ) ;
F_16 ( & V_1 -> V_33 -> V_34 , V_1 -> V_30 + V_35 ,
V_36 , V_36 ,
1000 , L_1 ) ;
}
void F_17 ( struct V_1 * V_1 )
{
F_15 ( V_1 , V_32 , 0 ) ;
F_16 ( & V_1 -> V_33 -> V_34 , V_1 -> V_30 + V_35 ,
V_36 , 0 ,
1000 , L_2 ) ;
}
void F_18 ( struct V_1 * V_1 , T_3 V_37 )
{
struct V_38 * V_38 = & V_1 -> V_38 ;
long V_21 ;
F_19 ( & V_38 -> V_39 ) ;
if ( V_38 -> V_40 ) {
F_15 ( V_1 , V_37 , V_37 ) ;
V_21 = F_20 (
V_1 -> V_41 ,
( F_21 ( V_1 -> V_30 + V_42 ) & V_43 ) == 0 ,
F_22 ( 1000 ) ) ;
if ( V_21 == 0 )
F_23 ( V_1 , L_3 ) ;
}
F_24 ( & V_38 -> V_39 ) ;
}
static void F_25 ( struct V_1 * V_1 )
{
struct V_5 * V_6 , * V_21 ;
int V_2 ;
T_1 V_44 = 0 ;
for ( V_2 = 0 ; V_2 < 5 ; V_2 ++ ) {
F_26 (qset, t, &whc->periodic_list[period], list_node) {
F_2 ( & V_6 -> V_45 . V_46 , V_44 ) ;
V_44 = V_6 -> V_47 ;
V_6 -> V_14 = true ;
}
F_1 ( V_1 , V_2 , V_44 ) ;
}
}
void F_27 ( struct V_48 * V_49 )
{
struct V_1 * V_1 = F_28 ( V_49 , struct V_1 , V_50 ) ;
struct V_5 * V_6 , * V_21 ;
enum V_15 V_16 = 0 ;
int V_2 ;
F_29 ( & V_1 -> V_51 ) ;
for ( V_2 = 4 ; V_2 >= 0 ; V_2 -- ) {
F_26 (qset, t, &whc->periodic_list[period], list_node) {
if ( ! V_6 -> V_14 )
V_16 |= V_52 ;
V_16 |= F_8 ( V_1 , V_6 ) ;
}
}
if ( V_16 & ( V_52 | V_28 ) )
F_25 ( V_1 ) ;
F_30 ( & V_1 -> V_51 ) ;
if ( V_16 ) {
T_3 V_37 = V_43 | V_53 ;
if ( V_16 & V_28 )
V_37 |= V_54 ;
F_18 ( V_1 , V_37 ) ;
}
F_29 ( & V_1 -> V_51 ) ;
F_26 (qset, t, &whc->periodic_removed_list, list_node) {
F_31 ( V_1 , V_6 ) ;
if ( V_6 -> V_55 ) {
F_32 ( V_1 , V_6 ) ;
if ( ! F_33 ( & V_6 -> V_56 ) ) {
F_4 ( V_1 , V_6 ) ;
F_34 ( V_1 -> V_57 , & V_1 -> V_50 ) ;
}
}
}
F_30 ( & V_1 -> V_51 ) ;
}
int F_35 ( struct V_1 * V_1 , struct V_58 * V_58 , T_4 V_59 )
{
struct V_5 * V_6 ;
int V_60 ;
unsigned long V_61 ;
F_36 ( & V_1 -> V_51 , V_61 ) ;
V_60 = F_37 ( & V_1 -> V_38 . V_62 , V_58 ) ;
if ( V_60 < 0 ) {
F_38 ( & V_1 -> V_51 , V_61 ) ;
return V_60 ;
}
V_6 = F_39 ( V_1 , V_58 , V_63 ) ;
if ( V_6 == NULL )
V_60 = - V_64 ;
else
V_60 = F_40 ( V_1 , V_6 , V_58 , V_63 ) ;
if ( ! V_60 ) {
if ( ! V_6 -> V_12 && ! V_6 -> remove )
F_4 ( V_1 , V_6 ) ;
} else
F_41 ( & V_1 -> V_38 . V_62 , V_58 ) ;
F_38 ( & V_1 -> V_51 , V_61 ) ;
if ( ! V_60 )
F_34 ( V_1 -> V_57 , & V_1 -> V_50 ) ;
return V_60 ;
}
int F_42 ( struct V_1 * V_1 , struct V_58 * V_58 , int V_17 )
{
struct V_65 * V_66 = V_58 -> V_67 ;
struct V_5 * V_6 = V_66 -> V_6 ;
struct V_68 * V_69 , * V_21 ;
bool V_70 = false ;
int V_71 ;
unsigned long V_61 ;
F_36 ( & V_1 -> V_51 , V_61 ) ;
V_71 = F_43 ( & V_1 -> V_38 . V_62 , V_58 , V_17 ) ;
if ( V_71 < 0 )
goto V_72;
F_26 (std, t, &qset->stds, list_node) {
if ( V_69 -> V_58 == V_58 ) {
if ( V_69 -> V_23 )
V_70 = true ;
F_44 ( V_1 , V_69 ) ;
} else
V_69 -> V_23 = NULL ;
}
if ( V_70 ) {
F_7 ( V_1 , V_6 ) ;
F_25 ( V_1 ) ;
V_66 -> V_17 = V_17 ;
V_66 -> V_73 = false ;
F_34 ( V_1 -> V_57 , & V_66 -> V_74 ) ;
} else
F_45 ( V_1 , V_6 , V_58 , V_17 ) ;
V_72:
F_38 ( & V_1 -> V_51 , V_61 ) ;
return V_71 ;
}
void F_46 ( struct V_1 * V_1 , struct V_5 * V_6 )
{
V_6 -> remove = 1 ;
F_34 ( V_1 -> V_57 , & V_1 -> V_50 ) ;
F_47 ( V_1 , V_6 ) ;
}
int F_48 ( struct V_1 * V_1 )
{
int V_75 ;
V_1 -> V_4 = F_49 ( & V_1 -> V_33 -> V_34 , sizeof( T_1 ) * 16 ,
& V_1 -> V_29 , V_76 ) ;
if ( V_1 -> V_4 == NULL )
return - V_64 ;
for ( V_75 = 0 ; V_75 < 16 ; V_75 ++ )
V_1 -> V_4 [ V_75 ] = F_50 ( F_51 ( 8 ) | V_77 ) ;
F_14 ( V_1 -> V_29 , V_1 -> V_30 + V_31 ) ;
return 0 ;
}
void F_52 ( struct V_1 * V_1 )
{
if ( V_1 -> V_4 )
F_53 ( & V_1 -> V_33 -> V_34 , sizeof( T_1 ) * 16 , V_1 -> V_4 ,
V_1 -> V_29 ) ;
}
