static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 ,
V_7 -> V_8 , V_7 -> V_9 , V_7 -> V_1 ) ;
}
static const struct V_10 * F_3 ( struct V_6 * V_7 ,
const struct V_10 * V_11 )
{
if ( V_11 -> V_8 != ( V_12 ) V_13 && V_11 -> V_8 != V_7 -> V_8 )
return NULL ;
if ( V_11 -> V_9 != ( V_14 ) V_13 && V_11 -> V_9 != V_7 -> V_9 )
return NULL ;
if ( V_11 -> V_1 != ( V_14 ) V_13 && V_11 -> V_1 != V_7 -> V_1 )
return NULL ;
return V_11 ;
}
static const struct V_10 * F_4 ( struct V_6 * V_7 ,
struct V_15 * V_16 )
{
const struct V_10 * V_17 ;
V_17 = V_16 -> V_18 ;
if ( V_17 ) {
while ( V_17 -> V_8 || V_17 -> V_9 || V_17 -> V_1 ) {
if ( F_3 ( V_7 , V_17 ) )
return V_17 ;
V_17 ++ ;
}
}
return NULL ;
}
static int F_5 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_15 * V_16 = F_6 ( V_20 ) ;
if ( F_4 ( V_7 , V_16 ) )
return 1 ;
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( F_8 ( V_22 ,
L_2 , V_7 -> V_8 ) )
return - V_23 ;
if ( F_8 ( V_22 ,
L_3 , V_7 -> V_9 , V_7 -> V_1 ) )
return - V_23 ;
if ( F_8 ( V_22 ,
L_4 ,
V_7 -> V_8 , V_7 -> V_9 , V_7 -> V_1 ) )
return - V_23 ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_15 * V_20 = F_6 ( V_2 -> V_24 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
const struct V_10 * V_11 ;
int V_25 ;
V_11 = F_4 ( V_7 , V_20 ) ;
if ( ! V_11 )
return - V_26 ;
if ( V_7 -> V_27 -> V_28 -> V_29 & V_30 ) {
V_25 = F_10 ( V_2 ) ;
if ( V_25 < 0 )
goto V_31;
}
F_11 ( V_7 ) ;
V_25 = F_12 ( V_7 , 0 ) ;
F_13 ( V_7 ) ;
if ( V_25 )
goto V_31;
V_25 = V_20 -> V_32 ( V_7 , V_11 ) ;
if ( V_25 )
goto V_31;
return 0 ;
V_31:
if ( V_7 -> V_27 -> V_28 -> V_29 & V_30 )
F_14 ( V_2 ) ;
return V_25 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_15 * V_20 = F_6 ( V_2 -> V_24 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
int V_25 = 0 ;
if ( V_7 -> V_27 -> V_28 -> V_29 & V_30 )
F_10 ( V_2 ) ;
V_20 -> remove ( V_7 ) ;
if ( V_7 -> V_33 ) {
F_16 ( L_5
L_6 , V_20 -> V_34 ) ;
F_11 ( V_7 ) ;
F_17 ( V_7 ) ;
F_13 ( V_7 ) ;
}
if ( V_7 -> V_27 -> V_28 -> V_29 & V_30 )
F_14 ( V_2 ) ;
if ( V_7 -> V_27 -> V_28 -> V_29 & V_30 )
F_18 ( V_2 ) ;
return V_25 ;
}
int F_19 ( void )
{
return F_20 ( & V_35 ) ;
}
void F_21 ( void )
{
F_22 ( & V_35 ) ;
}
int F_23 ( struct V_15 * V_20 )
{
V_20 -> V_20 . V_34 = V_20 -> V_34 ;
V_20 -> V_20 . V_36 = & V_35 ;
return F_24 ( & V_20 -> V_20 ) ;
}
void F_25 ( struct V_15 * V_20 )
{
V_20 -> V_20 . V_36 = & V_35 ;
F_26 ( & V_20 -> V_20 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_28 ( V_7 ) ;
F_29 ( V_7 -> V_37 ) ;
F_29 ( V_7 ) ;
}
struct V_6 * F_30 ( struct V_38 * V_27 )
{
struct V_6 * V_7 ;
V_7 = F_31 ( sizeof( struct V_6 ) , V_39 ) ;
if ( ! V_7 )
return F_32 ( - V_23 ) ;
V_7 -> V_27 = V_27 ;
F_33 ( & V_7 -> V_2 ) ;
V_7 -> V_2 . V_40 = & V_27 -> V_2 ;
V_7 -> V_2 . V_36 = & V_35 ;
V_7 -> V_2 . V_41 = F_27 ;
return V_7 ;
}
static void F_34 ( struct V_6 * V_7 )
{
struct V_42 * V_28 = V_7 -> V_27 -> V_28 ;
T_2 V_43 = ( V_28 -> V_44 << 16 ) | V_7 -> V_45 ;
F_35 ( & V_7 -> V_2 , F_36 ( V_28 -> V_40 ) , V_43 ) ;
}
static inline void F_34 ( struct V_6 * V_7 ) {}
int F_37 ( struct V_6 * V_7 )
{
int V_25 ;
F_38 ( & V_7 -> V_2 , L_7 , F_39 ( V_7 -> V_27 ) , V_7 -> V_45 ) ;
F_34 ( V_7 ) ;
V_25 = F_40 ( & V_7 -> V_2 ) ;
if ( V_25 == 0 ) {
F_41 ( V_7 ) ;
F_42 ( & V_7 -> V_2 , false ) ;
}
return V_25 ;
}
void F_43 ( struct V_6 * V_7 )
{
if ( ! F_44 ( V_7 ) )
return;
F_45 ( & V_7 -> V_2 , false ) ;
F_46 ( & V_7 -> V_2 ) ;
F_47 ( & V_7 -> V_2 ) ;
}
