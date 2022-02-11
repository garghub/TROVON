int
F_1 (
T_1 * V_1 ,
T_2 V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( V_1 , V_2 ) ;
V_5 = F_3 ( & V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
return V_5 ;
}
static int
F_5 (
T_1 * V_1 ,
T_2 V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = F_2 ( V_1 , V_2 ) ;
V_5 = F_6 ( & V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
return V_5 ;
}
static void
F_7 (
T_1 * V_1 ,
T_2 V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_1 , V_2 ) ;
F_8 ( & V_4 -> V_6 ) ;
F_4 ( V_4 ) ;
}
static void
F_9 (
struct V_7 * V_8 )
{
struct V_9 * V_10 =
F_10 ( V_8 , struct V_9 , V_8 ) ;
F_7 ( V_10 -> V_11 -> V_12 , V_10 -> V_13 ) ;
F_11 ( V_10 -> V_11 , V_10 -> V_13 ) ;
F_12 ( V_10 ) ;
}
static int
F_13 (
struct V_14 * V_11 ,
T_2 V_15 ,
T_2 * V_16 ,
int V_17 ,
T_3 V_18 )
{
struct V_19 * V_1 = V_11 -> V_12 ;
struct V_9 * V_10 ;
struct V_3 * V_4 ;
T_3 V_20 , free = 0 , V_21 , V_22 = 0 ;
T_2 V_13 , V_23 = V_24 ;
int V_25 , V_26 , V_27 ;
ASSERT ( F_14 ( F_15 ( V_11 ) -> V_28 ) ) ;
V_21 = V_1 -> V_29 . V_30 / 50 ;
V_13 = V_15 ;
* V_16 = V_24 ;
V_26 = V_31 ;
for ( V_27 = 0 ; 1 ; V_27 ++ ) {
F_16 ( V_11 , V_13 ) ;
V_4 = F_2 ( V_1 , V_13 ) ;
if ( ! V_4 -> V_32 ) {
V_25 = F_17 ( V_1 , NULL , V_13 , V_26 ) ;
if ( V_25 && ! V_26 ) {
F_4 ( V_4 ) ;
return V_25 ;
}
}
if ( ! V_4 -> V_32 )
goto V_33;
if ( V_4 -> V_34 > V_22 ) {
V_22 = V_4 -> V_34 ;
V_23 = V_13 ;
}
if ( F_5 ( V_1 , V_13 ) > 1 ) {
F_7 ( V_1 , V_13 ) ;
goto V_33;
}
V_20 = F_18 ( V_1 , V_4 ,
F_19 ( V_1 , V_4 ) ) ;
if ( ( ( V_18 && V_20 >= V_18 ) ||
( ! V_18 && V_4 -> V_34 >= V_21 ) ) &&
( ! V_4 -> V_35 || ! ( V_17 & V_36 ) ||
( V_17 & V_37 ) ) ) {
free = V_4 -> V_34 ;
F_4 ( V_4 ) ;
* V_16 = V_13 ;
break;
}
F_7 ( V_1 , V_13 ) ;
V_33:
F_4 ( V_4 ) ;
if ( ++ V_13 >= V_1 -> V_29 . V_38 )
V_13 = 0 ;
if ( V_13 != V_15 )
continue;
if ( V_26 != 0 ) {
V_26 = 0 ;
continue;
}
if ( ! ( V_17 & V_37 ) ) {
V_17 |= V_37 ;
continue;
}
if ( V_23 != V_24 ) {
F_5 ( V_1 , V_23 ) ;
free = V_22 ;
* V_16 = V_23 ;
break;
}
F_20 ( V_11 , * V_16 , free , V_27 ) ;
* V_16 = 0 ;
return 0 ;
}
F_20 ( V_11 , * V_16 , free , V_27 ) ;
if ( * V_16 == V_24 )
return 0 ;
V_25 = - V_39 ;
V_10 = F_21 ( sizeof( * V_10 ) , V_40 ) ;
if ( ! V_10 )
goto V_41;
V_10 -> V_13 = * V_16 ;
V_10 -> V_11 = V_11 ;
V_25 = F_22 ( V_1 -> V_42 , V_11 -> V_43 , & V_10 -> V_8 ) ;
if ( V_25 ) {
if ( V_25 == - V_44 )
V_25 = 0 ;
goto V_45;
}
return 0 ;
V_45:
F_12 ( V_10 ) ;
V_41:
F_7 ( V_1 , * V_16 ) ;
return V_25 ;
}
static struct V_14 *
F_23 (
struct V_14 * V_11 )
{
struct V_46 * V_46 = F_15 ( V_11 ) , * V_47 = NULL ;
struct V_48 * V_48 , * V_49 ;
V_48 = F_24 ( V_46 ) ;
if ( ! V_48 )
goto V_50;
V_49 = F_25 ( V_48 ) ;
if ( ! V_49 )
goto V_51;
V_47 = F_26 ( F_27 ( V_49 ) ) ;
F_28 ( V_49 ) ;
V_51:
F_28 ( V_48 ) ;
V_50:
return V_47 ? F_29 ( V_47 ) : NULL ;
}
T_2
F_30 (
struct V_14 * V_11 )
{
struct V_19 * V_1 = V_11 -> V_12 ;
struct V_14 * V_52 = NULL ;
T_2 V_15 , V_13 = V_24 ;
struct V_7 * V_8 ;
ASSERT ( F_31 ( F_15 ( V_11 ) -> V_28 ) ) ;
V_52 = F_23 ( V_11 ) ;
if ( ! V_52 )
return V_24 ;
V_8 = F_32 ( V_1 -> V_42 , V_52 -> V_43 ) ;
if ( V_8 ) {
V_13 = F_10 ( V_8 , struct V_9 , V_8 ) -> V_13 ;
F_33 ( V_1 -> V_42 ) ;
F_34 ( V_11 , V_13 ) ;
goto V_50;
}
if ( V_1 -> V_53 & V_54 ) {
T_2 V_55 = V_56 ;
V_15 = ( V_1 -> V_57 / V_55 ) % V_1 -> V_29 . V_38 ;
V_1 -> V_57 = ( V_1 -> V_57 + 1 ) %
( V_1 -> V_29 . V_38 * V_55 ) ;
} else
V_15 = F_35 ( V_1 , V_52 -> V_43 ) ;
if ( F_13 ( V_52 , V_15 , & V_13 , 0 , 0 ) )
V_13 = V_24 ;
V_50:
F_36 ( V_52 ) ;
return V_13 ;
}
int
F_37 (
struct V_58 * V_59 ,
T_2 * V_16 )
{
struct V_14 * V_11 = V_59 -> V_11 , * V_52 ;
struct V_19 * V_1 = V_11 -> V_12 ;
T_3 V_18 = V_59 -> V_60 ;
T_2 V_15 = 0 ;
int V_17 , V_25 = 0 ;
struct V_7 * V_8 ;
* V_16 = V_24 ;
V_52 = F_23 ( V_11 ) ;
if ( ! V_52 )
goto exit;
V_8 = F_38 ( V_1 -> V_42 , V_52 -> V_43 ) ;
if ( V_8 ) {
struct V_9 * V_10 =
F_10 ( V_8 , struct V_9 , V_8 ) ;
V_15 = ( V_10 -> V_13 + 1 ) % V_1 -> V_29 . V_38 ;
}
V_17 = ( V_59 -> V_61 ? V_36 : 0 ) |
( V_59 -> V_62 -> V_63 ? V_37 : 0 ) ;
V_25 = F_13 ( V_52 , V_15 , V_16 , V_17 , V_18 ) ;
if ( V_8 )
F_9 ( V_8 ) ;
F_36 ( V_52 ) ;
exit:
if ( * V_16 == V_24 )
* V_16 = 0 ;
return V_25 ;
}
void
F_39 (
struct V_14 * V_11 )
{
F_40 ( V_11 -> V_12 -> V_42 , V_11 -> V_43 ) ;
}
int
F_41 (
T_1 * V_1 )
{
return F_42 ( & V_1 -> V_42 , V_64 * 10 ,
10 , F_9 ) ;
}
void
F_43 (
T_1 * V_1 )
{
F_44 ( V_1 -> V_42 ) ;
}
