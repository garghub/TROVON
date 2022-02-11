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
struct V_1 * F_17 ( struct V_15 * V_22 ,
const struct V_23 * V_7 )
{
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_18 ( sizeof( * V_2 ) , V_24 ) ;
if ( V_2 == NULL )
return F_19 ( - V_25 ) ;
F_20 ( & V_2 -> V_26 ) ;
F_21 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = V_7 ;
F_8 ( & V_12 ) ;
V_3 = F_22 ( & V_14 , NULL , 0 , V_27 , V_24 ) ;
F_11 ( & V_12 ) ;
if ( V_3 < 0 ) {
F_23 ( V_22 , L_1 ) ;
F_15 ( V_2 ) ;
return F_19 ( V_3 ) ;
}
V_2 -> V_16 = V_3 ;
F_24 ( & V_2 -> V_5 ) ;
F_24 ( & V_2 -> V_21 ) ;
V_2 -> V_5 . V_28 = V_29 ;
V_2 -> V_5 . V_30 = F_12 ;
V_2 -> V_5 . V_31 = V_22 ;
V_2 -> V_5 . V_32 = V_2 -> V_32 ;
V_2 -> V_21 . V_31 = V_22 ;
V_2 -> V_21 . V_28 = V_33 ;
V_2 -> V_21 . V_30 = F_16 ;
if ( V_2 -> V_34 & V_35 )
F_2 ( & V_2 -> V_5 ) ;
if ( V_2 -> V_16 == 0 )
V_2 -> V_5 . V_36 = F_25 ( V_37 , V_38 ) ;
else
V_2 -> V_5 . V_36 = F_25 ( F_26 ( V_39 ) , V_2 -> V_16 ) ;
V_2 -> V_21 . V_36 =
F_25 ( F_26 ( V_39 ) , V_2 -> V_16 + V_27 ) ;
V_3 = F_27 ( & V_2 -> V_5 , L_2 , V_2 -> V_16 ) ;
if ( V_3 )
goto V_40;
V_3 = F_27 ( & V_2 -> V_21 , L_3 , V_2 -> V_16 ) ;
if ( V_3 )
goto V_40;
if ( ! V_22 )
V_2 -> V_34 |= V_41 ;
F_28 ( & V_2 -> V_42 , & V_43 ) ;
F_28 ( & V_2 -> V_44 , & V_45 ) ;
V_2 -> V_42 . V_46 = V_47 ;
V_2 -> V_44 . V_46 = V_47 ;
V_2 -> V_18 . V_19 = F_18 ( V_48 , V_24 ) ;
if ( ! V_2 -> V_18 . V_19 ) {
V_3 = - V_25 ;
goto V_40;
}
V_2 -> V_18 . V_20 = F_18 ( V_48 , V_24 ) ;
if ( ! V_2 -> V_18 . V_20 ) {
V_3 = - V_25 ;
goto V_40;
}
V_2 -> V_49 = - 1 ;
return V_2 ;
V_40:
F_5 ( & V_2 -> V_21 ) ;
F_5 ( & V_2 -> V_5 ) ;
return F_19 ( V_3 ) ;
}
struct V_1 * F_29 ( struct V_15 * V_22 ,
const struct V_23 * V_7 )
{
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_17 ( V_22 , V_7 ) ;
if ( F_30 ( V_2 ) )
return V_2 ;
V_3 = F_31 ( V_22 ,
( void ( * ) ( void * ) ) F_5 ,
& V_2 -> V_5 ) ;
if ( V_3 )
return F_19 ( V_3 ) ;
F_32 ( V_22 , V_2 ) ;
return V_2 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_34 ( & V_2 -> V_42 , & V_2 -> V_5 ) ;
if ( V_3 ) {
F_23 ( & V_2 -> V_5 ,
L_4 ,
F_35 ( & V_2 -> V_5 ) , F_26 ( V_2 -> V_5 . V_36 ) ,
F_36 ( V_2 -> V_5 . V_36 ) , V_3 ) ;
return V_3 ;
}
if ( V_2 -> V_34 & V_35 ) {
V_3 = F_34 ( & V_2 -> V_44 , & V_2 -> V_21 ) ;
if ( V_3 ) {
F_23 ( & V_2 -> V_21 ,
L_4 ,
F_35 ( & V_2 -> V_21 ) , F_26 ( V_2 -> V_21 . V_36 ) ,
F_36 ( V_2 -> V_21 . V_36 ) , V_3 ) ;
return V_3 ;
}
}
F_8 ( & V_12 ) ;
F_37 ( & V_14 , V_2 , V_2 -> V_16 ) ;
F_11 ( & V_12 ) ;
return V_3 ;
}
static void F_38 ( struct V_1 * V_2 )
{
F_39 ( & V_2 -> V_42 , & V_2 -> V_5 ) ;
F_8 ( & V_12 ) ;
F_37 ( & V_14 , NULL , V_2 -> V_16 ) ;
F_11 ( & V_12 ) ;
F_40 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_34 & V_35 )
F_41 ( V_2 , V_50 ) ;
V_2 -> V_7 = NULL ;
F_42 ( & V_2 -> V_6 ) ;
}
static void F_43 ( struct V_1 * V_2 )
{
struct V_51 * * V_52 ;
if ( V_2 -> V_34 & ( V_35 | V_41 ) )
return;
F_44 ( & V_2 -> V_5 . V_31 -> V_53 , L_5 ) ;
for ( V_52 = V_2 -> V_32 [ 0 ] -> V_54 ; * V_52 != NULL ; ++ V_52 )
F_44 ( & V_2 -> V_5 . V_31 -> V_53 , ( * V_52 ) -> V_55 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_51 * * V_52 ;
int V_3 ;
if ( V_2 -> V_34 & ( V_35 | V_41 ) )
return 0 ;
V_3 = F_46 (
& V_2 -> V_5 . V_31 -> V_53 , & V_2 -> V_5 . V_53 , L_5 ) ;
if ( V_3 && V_3 != - V_56 )
return V_3 ;
for ( V_52 = V_2 -> V_32 [ 0 ] -> V_54 ; * V_52 != NULL ; ++ V_52 ) {
V_3 = F_46 (
& V_2 -> V_5 . V_31 -> V_53 , & V_2 -> V_5 . V_53 , ( * V_52 ) -> V_55 ) ;
if ( V_3 ) {
F_43 ( V_2 ) ;
return V_3 ;
}
}
return 0 ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_7 -> V_34 & V_57 ) {
if ( V_2 -> V_34 & V_35 )
V_3 = F_48 ( V_2 ) ;
else
V_3 = F_49 ( V_2 ) ;
if ( V_3 )
return V_3 ;
}
F_50 ( V_2 ) ;
V_3 = F_51 ( V_2 ) ;
if ( V_3 != 0 && V_3 != - V_58 )
return V_3 ;
F_52 ( V_2 ) ;
V_3 = F_33 ( V_2 ) ;
if ( V_3 ) {
F_53 ( V_2 ) ;
return V_3 ;
}
V_3 = F_45 ( V_2 ) ;
if ( V_3 ) {
F_54 ( V_2 ) ;
return V_3 ;
}
return 0 ;
}
void F_54 ( struct V_1 * V_2 )
{
F_43 ( V_2 ) ;
F_53 ( V_2 ) ;
if ( V_2 -> V_34 & V_35 )
F_39 ( & V_2 -> V_44 , & V_2 -> V_21 ) ;
F_38 ( V_2 ) ;
}
