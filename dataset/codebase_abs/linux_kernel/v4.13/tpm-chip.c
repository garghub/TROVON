int F_1 ( struct V_1 * V_2 )
{
int V_3 = - V_4 ;
F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_7 )
goto V_8;
return 0 ;
V_8:
F_4 ( & V_2 -> V_6 ) ;
F_5 ( & V_2 -> V_5 ) ;
return V_3 ;
}
void F_6 ( struct V_1 * V_2 )
{
F_4 ( & V_2 -> V_6 ) ;
F_5 ( & V_2 -> V_5 ) ;
}
struct V_1 * F_7 ( int V_9 )
{
struct V_1 * V_2 , * V_10 = NULL ;
int V_11 ;
F_8 ( & V_12 ) ;
if ( V_9 == V_13 ) {
V_9 = 0 ;
do {
V_11 = V_9 ;
V_2 = F_9 ( & V_14 , & V_9 ) ;
if ( V_2 && ! F_1 ( V_2 ) ) {
V_10 = V_2 ;
break;
}
} while ( V_11 != V_9 );
} else {
V_2 = F_10 ( & V_14 , V_9 ) ;
if ( V_2 && ! F_1 ( V_2 ) )
V_10 = V_2 ;
}
F_11 ( & V_12 ) ;
return V_10 ;
}
static void F_12 ( struct V_15 * V_5 )
{
struct V_1 * V_2 = F_13 ( V_5 , struct V_1 , V_5 ) ;
F_8 ( & V_12 ) ;
F_14 ( & V_14 , V_2 -> V_16 ) ;
F_11 ( & V_12 ) ;
F_15 ( V_2 -> log . V_17 ) ;
F_15 ( V_2 -> V_18 . V_19 ) ;
F_15 ( V_2 -> V_18 . V_20 ) ;
F_15 ( V_2 ) ;
}
static void F_16 ( struct V_15 * V_5 )
{
struct V_1 * V_2 = F_13 ( V_5 , struct V_1 , V_21 ) ;
F_5 ( & V_2 -> V_5 ) ;
}
static int F_17 ( struct V_15 * V_5 )
{
struct V_1 * V_2 = F_13 ( V_5 , struct V_1 , V_5 ) ;
if ( V_2 -> V_22 & V_23 ) {
F_18 ( & V_2 -> V_6 ) ;
F_19 ( V_2 , V_24 ) ;
V_2 -> V_7 = NULL ;
F_20 ( & V_2 -> V_6 ) ;
}
if ( V_5 -> V_25 && V_5 -> V_25 -> V_26 )
V_5 -> V_25 -> V_26 ( V_5 ) ;
else if ( V_5 -> V_27 && V_5 -> V_27 -> V_26 )
V_5 -> V_27 -> V_26 ( V_5 ) ;
return 0 ;
}
struct V_1 * F_21 ( struct V_15 * V_28 ,
const struct V_29 * V_7 )
{
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_22 ( sizeof( * V_2 ) , V_30 ) ;
if ( V_2 == NULL )
return F_23 ( - V_31 ) ;
F_24 ( & V_2 -> V_32 ) ;
F_25 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = V_7 ;
F_8 ( & V_12 ) ;
V_3 = F_26 ( & V_14 , NULL , 0 , V_33 , V_30 ) ;
F_11 ( & V_12 ) ;
if ( V_3 < 0 ) {
F_27 ( V_28 , L_1 ) ;
F_15 ( V_2 ) ;
return F_23 ( V_3 ) ;
}
V_2 -> V_16 = V_3 ;
F_28 ( & V_2 -> V_5 ) ;
F_28 ( & V_2 -> V_21 ) ;
V_2 -> V_5 . V_34 = V_35 ;
V_2 -> V_5 . V_34 -> V_26 = F_17 ;
V_2 -> V_5 . V_36 = F_12 ;
V_2 -> V_5 . V_37 = V_28 ;
V_2 -> V_5 . V_38 = V_2 -> V_38 ;
V_2 -> V_21 . V_37 = V_28 ;
V_2 -> V_21 . V_34 = V_39 ;
V_2 -> V_21 . V_36 = F_16 ;
if ( V_2 -> V_22 & V_23 )
F_2 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_16 == 0 )
V_2 -> V_5 . V_40 = F_29 ( V_41 , V_42 ) ;
else
V_2 -> V_5 . V_40 = F_29 ( F_30 ( V_43 ) , V_2 -> V_16 ) ;
V_2 -> V_21 . V_40 =
F_29 ( F_30 ( V_43 ) , V_2 -> V_16 + V_33 ) ;
V_3 = F_31 ( & V_2 -> V_5 , L_2 , V_2 -> V_16 ) ;
if ( V_3 )
goto V_44;
V_3 = F_31 ( & V_2 -> V_21 , L_3 , V_2 -> V_16 ) ;
if ( V_3 )
goto V_44;
if ( ! V_28 )
V_2 -> V_22 |= V_45 ;
F_32 ( & V_2 -> V_46 , & V_47 ) ;
F_32 ( & V_2 -> V_48 , & V_49 ) ;
V_2 -> V_46 . V_50 = V_51 ;
V_2 -> V_48 . V_50 = V_51 ;
V_2 -> V_18 . V_19 = F_22 ( V_52 , V_30 ) ;
if ( ! V_2 -> V_18 . V_19 ) {
V_3 = - V_31 ;
goto V_44;
}
V_2 -> V_18 . V_20 = F_22 ( V_52 , V_30 ) ;
if ( ! V_2 -> V_18 . V_20 ) {
V_3 = - V_31 ;
goto V_44;
}
V_2 -> V_53 = - 1 ;
return V_2 ;
V_44:
F_5 ( & V_2 -> V_21 ) ;
F_5 ( & V_2 -> V_5 ) ;
return F_23 ( V_3 ) ;
}
struct V_1 * F_33 ( struct V_15 * V_28 ,
const struct V_29 * V_7 )
{
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_21 ( V_28 , V_7 ) ;
if ( F_34 ( V_2 ) )
return V_2 ;
V_3 = F_35 ( V_28 ,
( void ( * ) ( void * ) ) F_5 ,
& V_2 -> V_5 ) ;
if ( V_3 )
return F_23 ( V_3 ) ;
F_36 ( V_28 , V_2 ) ;
return V_2 ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_38 ( & V_2 -> V_46 , & V_2 -> V_5 ) ;
if ( V_3 ) {
F_27 ( & V_2 -> V_5 ,
L_4 ,
F_39 ( & V_2 -> V_5 ) , F_30 ( V_2 -> V_5 . V_40 ) ,
F_40 ( V_2 -> V_5 . V_40 ) , V_3 ) ;
return V_3 ;
}
if ( V_2 -> V_22 & V_23 ) {
V_3 = F_38 ( & V_2 -> V_48 , & V_2 -> V_21 ) ;
if ( V_3 ) {
F_27 ( & V_2 -> V_21 ,
L_4 ,
F_39 ( & V_2 -> V_21 ) , F_30 ( V_2 -> V_21 . V_40 ) ,
F_40 ( V_2 -> V_21 . V_40 ) , V_3 ) ;
return V_3 ;
}
}
F_8 ( & V_12 ) ;
F_41 ( & V_14 , V_2 , V_2 -> V_16 ) ;
F_11 ( & V_12 ) ;
return V_3 ;
}
static void F_42 ( struct V_1 * V_2 )
{
F_43 ( & V_2 -> V_46 , & V_2 -> V_5 ) ;
F_8 ( & V_12 ) ;
F_41 ( & V_14 , NULL , V_2 -> V_16 ) ;
F_11 ( & V_12 ) ;
F_18 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_22 & V_23 )
F_19 ( V_2 , V_24 ) ;
V_2 -> V_7 = NULL ;
F_20 ( & V_2 -> V_6 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_54 * * V_55 ;
if ( V_2 -> V_22 & ( V_23 | V_45 ) )
return;
F_45 ( & V_2 -> V_5 . V_37 -> V_56 , L_5 ) ;
for ( V_55 = V_2 -> V_38 [ 0 ] -> V_57 ; * V_55 != NULL ; ++ V_55 )
F_45 ( & V_2 -> V_5 . V_37 -> V_56 , ( * V_55 ) -> V_58 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_54 * * V_55 ;
int V_3 ;
if ( V_2 -> V_22 & ( V_23 | V_45 ) )
return 0 ;
V_3 = F_47 (
& V_2 -> V_5 . V_37 -> V_56 , & V_2 -> V_5 . V_56 , L_5 ) ;
if ( V_3 && V_3 != - V_59 )
return V_3 ;
for ( V_55 = V_2 -> V_38 [ 0 ] -> V_57 ; * V_55 != NULL ; ++ V_55 ) {
V_3 = F_47 (
& V_2 -> V_5 . V_37 -> V_56 , & V_2 -> V_5 . V_56 , ( * V_55 ) -> V_58 ) ;
if ( V_3 ) {
F_44 ( V_2 ) ;
return V_3 ;
}
}
return 0 ;
}
int F_48 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_7 -> V_22 & V_60 ) {
if ( V_2 -> V_22 & V_23 )
V_3 = F_49 ( V_2 ) ;
else
V_3 = F_50 ( V_2 ) ;
if ( V_3 )
return V_3 ;
}
F_51 ( V_2 ) ;
V_3 = F_52 ( V_2 ) ;
if ( V_3 != 0 && V_3 != - V_61 )
return V_3 ;
F_53 ( V_2 ) ;
V_3 = F_37 ( V_2 ) ;
if ( V_3 ) {
F_54 ( V_2 ) ;
return V_3 ;
}
V_3 = F_46 ( V_2 ) ;
if ( V_3 ) {
F_55 ( V_2 ) ;
return V_3 ;
}
return 0 ;
}
void F_55 ( struct V_1 * V_2 )
{
F_44 ( V_2 ) ;
F_54 ( V_2 ) ;
if ( V_2 -> V_22 & V_23 )
F_43 ( & V_2 -> V_48 , & V_2 -> V_21 ) ;
F_42 ( V_2 ) ;
}
