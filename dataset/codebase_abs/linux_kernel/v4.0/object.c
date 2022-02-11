int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , T_1 V_6 ,
int V_7 , void * * V_8 )
{
struct V_1 * V_9 ;
V_9 = * V_8 = F_2 ( V_7 , V_10 ) ;
if ( ! V_9 )
return - V_11 ;
F_3 ( V_2 , & V_9 -> V_2 ) ;
F_3 ( V_3 , (struct V_1 * * ) & V_9 -> V_3 ) ;
V_9 -> V_5 = V_5 ;
V_9 -> V_5 -> V_12 |= V_6 ;
F_4 ( & V_9 -> V_13 , 1 ) ;
F_4 ( & V_9 -> V_14 , 0 ) ;
#ifdef F_5
V_9 -> V_15 = F_5 ;
F_6 ( & V_16 ) ;
F_7 ( & V_9 -> V_17 , & V_18 ) ;
F_8 ( & V_16 ) ;
#endif
return 0 ;
}
int
F_9 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_19 , T_1 V_7 ,
struct V_1 * * V_8 )
{
if ( V_7 != 0 )
return - V_20 ;
return F_10 ( V_2 , V_3 , V_5 , 0 , V_8 ) ;
}
void
F_11 ( struct V_1 * V_9 )
{
#ifdef F_5
F_6 ( & V_16 ) ;
F_12 ( & V_9 -> V_17 ) ;
F_8 ( & V_16 ) ;
#endif
F_3 ( NULL , (struct V_1 * * ) & V_9 -> V_3 ) ;
F_3 ( NULL , & V_9 -> V_2 ) ;
F_13 ( V_9 ) ;
}
int
F_14 ( struct V_1 * V_9 )
{
return 0 ;
}
int
F_15 ( struct V_1 * V_9 , bool V_21 )
{
return 0 ;
}
int
F_16 ( struct V_1 * V_2 , struct V_1 * V_3 ,
struct V_4 * V_5 , void * V_19 , T_1 V_7 ,
struct V_1 * * V_8 )
{
struct V_22 * V_23 = V_5 -> V_23 ;
struct V_1 * V_9 = NULL ;
int V_24 ;
V_24 = V_23 -> V_25 ( V_2 , V_3 , V_5 , V_19 , V_7 , & V_9 ) ;
* V_8 = V_9 ;
if ( V_24 < 0 ) {
if ( V_24 != - V_26 ) {
F_17 ( V_2 , L_1 ,
V_5 -> V_12 , V_24 ) ;
}
if ( V_9 ) {
V_23 -> V_27 ( V_9 ) ;
* V_8 = NULL ;
}
return V_24 ;
}
if ( V_24 == 0 ) {
F_18 ( V_9 , L_2 ) ;
F_4 ( & V_9 -> V_13 , 1 ) ;
}
return 0 ;
}
static void
F_19 ( struct V_1 * V_9 )
{
F_18 ( V_9 , L_3 ) ;
F_20 ( V_9 ) -> V_27 ( V_9 ) ;
}
void
F_3 ( struct V_1 * V_28 , struct V_1 * * V_29 )
{
if ( V_28 ) {
F_21 ( & V_28 -> V_13 ) ;
F_18 ( V_28 , L_4 , F_22 ( & V_28 -> V_13 ) ) ;
}
if ( * V_29 ) {
int V_30 = F_23 ( & ( * V_29 ) -> V_13 ) ;
F_18 ( * V_29 , L_5 , F_22 ( & ( * V_29 ) -> V_13 ) ) ;
if ( V_30 )
F_19 ( * V_29 ) ;
}
* V_29 = V_28 ;
}
int
F_24 ( struct V_1 * V_9 )
{
int V_29 = F_25 ( 1 , & V_9 -> V_14 ) ;
int V_24 ;
F_18 ( V_9 , L_6 , F_22 ( & V_9 -> V_14 ) ) ;
if ( V_29 != 1 )
return 0 ;
F_18 ( V_9 , L_7 ) ;
if ( V_9 -> V_2 ) {
V_24 = F_24 ( V_9 -> V_2 ) ;
if ( V_24 ) {
F_17 ( V_9 , L_8 , V_24 ) ;
goto V_31;
}
}
if ( V_9 -> V_3 ) {
F_26 ( & F_27 ( V_9 -> V_3 ) -> V_32 ) ;
V_24 = F_24 ( & V_9 -> V_3 -> V_33 . V_9 ) ;
F_28 ( & F_27 ( V_9 -> V_3 ) -> V_32 ) ;
if ( V_24 ) {
F_17 ( V_9 , L_9 , V_24 ) ;
goto V_34;
}
}
V_24 = F_20 ( V_9 ) -> F_29 ( V_9 ) ;
F_4 ( & V_9 -> V_14 , 1 ) ;
if ( V_24 ) {
F_17 ( V_9 , L_10 , V_24 ) ;
goto V_35;
}
F_18 ( V_9 , L_11 ) ;
return 0 ;
V_35:
if ( V_9 -> V_3 ) {
F_26 ( & F_27 ( V_9 -> V_3 ) -> V_32 ) ;
F_30 ( & V_9 -> V_3 -> V_33 . V_9 , false ) ;
F_28 ( & F_27 ( V_9 -> V_3 ) -> V_32 ) ;
}
V_34:
if ( V_9 -> V_2 )
F_30 ( V_9 -> V_2 , false ) ;
V_31:
F_31 ( & V_9 -> V_14 ) ;
return V_24 ;
}
static int
F_32 ( struct V_1 * V_9 )
{
int V_24 ;
F_18 ( V_9 , L_12 ) ;
V_24 = F_20 ( V_9 ) -> F_33 ( V_9 , false ) ;
F_4 ( & V_9 -> V_14 , 0 ) ;
if ( V_24 )
F_34 ( V_9 , L_13 , V_24 ) ;
if ( V_9 -> V_3 ) {
F_26 ( & F_27 ( V_9 -> V_3 ) -> V_32 ) ;
F_30 ( & V_9 -> V_3 -> V_33 . V_9 , false ) ;
F_28 ( & F_27 ( V_9 -> V_3 ) -> V_32 ) ;
}
if ( V_9 -> V_2 )
F_30 ( V_9 -> V_2 , false ) ;
F_18 ( V_9 , L_14 ) ;
return 0 ;
}
static int
F_35 ( struct V_1 * V_9 )
{
int V_24 , V_36 ;
F_18 ( V_9 , L_15 ) ;
V_24 = F_20 ( V_9 ) -> F_33 ( V_9 , true ) ;
F_4 ( & V_9 -> V_14 , 0 ) ;
if ( V_24 ) {
F_17 ( V_9 , L_16 , V_24 ) ;
return V_24 ;
}
if ( V_9 -> V_3 ) {
F_26 ( & F_27 ( V_9 -> V_3 ) -> V_32 ) ;
V_24 = F_30 ( & V_9 -> V_3 -> V_33 . V_9 , true ) ;
F_28 ( & F_27 ( V_9 -> V_3 ) -> V_32 ) ;
if ( V_24 ) {
F_34 ( V_9 , L_17 , V_24 ) ;
goto V_34;
}
}
if ( V_9 -> V_2 ) {
V_24 = F_30 ( V_9 -> V_2 , true ) ;
if ( V_24 ) {
F_34 ( V_9 , L_18 , V_24 ) ;
goto V_31;
}
}
F_18 ( V_9 , L_19 ) ;
return 0 ;
V_31:
if ( V_9 -> V_3 ) {
F_26 ( & F_27 ( V_9 -> V_3 ) -> V_32 ) ;
V_36 = F_24 ( & V_9 -> V_3 -> V_33 . V_9 ) ;
F_28 ( & F_27 ( V_9 -> V_3 ) -> V_32 ) ;
if ( V_36 )
F_36 ( V_9 , L_20 , V_36 ) ;
}
V_34:
V_36 = F_20 ( V_9 ) -> F_29 ( V_9 ) ;
if ( V_36 )
F_36 ( V_9 , L_21 , V_36 ) ;
return V_24 ;
}
int
F_30 ( struct V_1 * V_9 , bool V_21 )
{
int V_29 = F_25 ( - 1 , & V_9 -> V_14 ) ;
int V_24 ;
F_18 ( V_9 , L_22 , F_22 ( & V_9 -> V_14 ) ) ;
if ( V_29 == 0 ) {
if ( V_21 )
V_24 = F_35 ( V_9 ) ;
else
V_24 = F_32 ( V_9 ) ;
if ( V_24 ) {
F_21 ( & V_9 -> V_14 ) ;
return V_24 ;
}
}
return 0 ;
}
void
F_37 ( void )
{
#ifdef F_5
struct V_1 * V_9 ;
if ( ! F_38 ( & V_18 ) ) {
F_36 ( NULL , L_23 ) ;
F_36 ( NULL , L_24 ) ;
F_36 ( NULL , L_23 ) ;
F_39 (object, &_objlist, list) {
F_36 ( V_9 , L_25 ,
V_9 -> V_2 , V_9 -> V_3 ,
F_22 ( & V_9 -> V_13 ) ,
F_22 ( & V_9 -> V_14 ) ) ;
}
}
#endif
}
