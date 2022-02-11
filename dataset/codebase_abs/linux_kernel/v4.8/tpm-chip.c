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
F_15 ( V_2 ) ;
}
struct V_1 * F_16 ( struct V_15 * V_5 ,
const struct V_17 * V_7 )
{
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_17 ( sizeof( * V_2 ) , V_18 ) ;
if ( V_2 == NULL )
return F_18 ( - V_19 ) ;
F_19 ( & V_2 -> V_20 ) ;
F_20 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = V_7 ;
F_8 ( & V_12 ) ;
V_3 = F_21 ( & V_14 , NULL , 0 , V_21 , V_18 ) ;
F_11 ( & V_12 ) ;
if ( V_3 < 0 ) {
F_22 ( V_5 , L_1 ) ;
F_15 ( V_2 ) ;
return F_18 ( V_3 ) ;
}
V_2 -> V_16 = V_3 ;
F_23 ( & V_2 -> V_5 ) ;
V_2 -> V_5 . V_22 = V_23 ;
V_2 -> V_5 . V_24 = F_12 ;
V_2 -> V_5 . V_25 = V_5 ;
V_2 -> V_5 . V_26 = V_2 -> V_26 ;
if ( V_2 -> V_16 == 0 )
V_2 -> V_5 . V_27 = F_24 ( V_28 , V_29 ) ;
else
V_2 -> V_5 . V_27 = F_24 ( F_25 ( V_30 ) , V_2 -> V_16 ) ;
V_3 = F_26 ( & V_2 -> V_5 , L_2 , V_2 -> V_16 ) ;
if ( V_3 )
goto V_31;
if ( ! V_5 )
V_2 -> V_32 |= V_33 ;
F_27 ( & V_2 -> V_34 , & V_35 ) ;
V_2 -> V_34 . V_36 = V_37 ;
V_2 -> V_34 . V_38 . V_25 = & V_2 -> V_5 . V_38 ;
return V_2 ;
V_31:
F_5 ( & V_2 -> V_5 ) ;
return F_18 ( V_3 ) ;
}
struct V_1 * F_28 ( struct V_15 * V_39 ,
const struct V_17 * V_7 )
{
struct V_1 * V_2 ;
int V_3 ;
V_2 = F_16 ( V_39 , V_7 ) ;
if ( F_29 ( V_2 ) )
return V_2 ;
V_3 = F_30 ( V_39 ,
( void ( * ) ( void * ) ) F_5 ,
& V_2 -> V_5 ) ;
if ( V_3 )
return F_18 ( V_3 ) ;
F_31 ( V_39 , V_2 ) ;
return V_2 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_3 ;
V_3 = F_33 ( & V_2 -> V_34 , V_2 -> V_5 . V_27 , 1 ) ;
if ( V_3 ) {
F_22 ( & V_2 -> V_5 ,
L_3 ,
F_34 ( & V_2 -> V_5 ) , F_25 ( V_2 -> V_5 . V_27 ) ,
F_35 ( V_2 -> V_5 . V_27 ) , V_3 ) ;
return V_3 ;
}
V_3 = F_36 ( & V_2 -> V_5 ) ;
if ( V_3 ) {
F_22 ( & V_2 -> V_5 ,
L_4 ,
F_34 ( & V_2 -> V_5 ) , F_25 ( V_2 -> V_5 . V_27 ) ,
F_35 ( V_2 -> V_5 . V_27 ) , V_3 ) ;
F_37 ( & V_2 -> V_34 ) ;
return V_3 ;
}
F_8 ( & V_12 ) ;
F_38 ( & V_14 , V_2 , V_2 -> V_16 ) ;
F_11 ( & V_12 ) ;
return V_3 ;
}
static void F_39 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_34 ) ;
F_40 ( & V_2 -> V_5 ) ;
F_8 ( & V_12 ) ;
F_38 ( & V_14 , NULL , V_2 -> V_16 ) ;
F_11 ( & V_12 ) ;
F_41 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_32 & V_40 )
F_42 ( V_2 , V_41 ) ;
V_2 -> V_7 = NULL ;
F_43 ( & V_2 -> V_6 ) ;
}
static int F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 & V_40 )
return 0 ;
F_45 ( V_2 ) ;
V_2 -> V_42 = F_46 ( F_34 ( & V_2 -> V_5 ) ) ;
return 0 ;
}
static void F_47 ( struct V_1 * V_2 )
{
if ( V_2 -> V_32 & V_40 )
return;
if ( V_2 -> V_42 )
F_48 ( V_2 -> V_42 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_43 * * V_44 ;
if ( V_2 -> V_32 & ( V_40 | V_33 ) )
return;
F_50 ( & V_2 -> V_5 . V_25 -> V_38 , L_5 ) ;
for ( V_44 = V_2 -> V_26 [ 0 ] -> V_45 ; * V_44 != NULL ; ++ V_44 )
F_50 ( & V_2 -> V_5 . V_25 -> V_38 , ( * V_44 ) -> V_46 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_43 * * V_44 ;
int V_3 ;
if ( V_2 -> V_32 & ( V_40 | V_33 ) )
return 0 ;
V_3 = F_52 (
& V_2 -> V_5 . V_25 -> V_38 , & V_2 -> V_5 . V_38 , L_5 ) ;
if ( V_3 && V_3 != - V_47 )
return V_3 ;
for ( V_44 = V_2 -> V_26 [ 0 ] -> V_45 ; * V_44 != NULL ; ++ V_44 ) {
V_3 = F_52 (
& V_2 -> V_5 . V_25 -> V_38 , & V_2 -> V_5 . V_38 , ( * V_44 ) -> V_46 ) ;
if ( V_3 ) {
F_49 ( V_2 ) ;
return V_3 ;
}
}
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_3 ;
if ( V_2 -> V_7 -> V_32 & V_48 ) {
if ( V_2 -> V_32 & V_40 )
V_3 = F_54 ( V_2 ) ;
else
V_3 = F_55 ( V_2 ) ;
if ( V_3 )
return V_3 ;
}
V_3 = F_44 ( V_2 ) ;
if ( V_3 )
return V_3 ;
F_56 ( V_2 ) ;
V_3 = F_32 ( V_2 ) ;
if ( V_3 ) {
F_47 ( V_2 ) ;
return V_3 ;
}
V_2 -> V_32 |= V_49 ;
V_3 = F_51 ( V_2 ) ;
if ( V_3 ) {
F_57 ( V_2 ) ;
return V_3 ;
}
return 0 ;
}
void F_57 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_32 & V_49 ) )
return;
F_49 ( V_2 ) ;
F_47 ( V_2 ) ;
F_39 ( V_2 ) ;
}
