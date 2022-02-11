static int F_1 ( struct V_1 * V_2 , int (* F_2)( struct V_1 * ) )
{
int V_3 ;
V_3 = F_3 ( F_4 ( V_2 ) ) ;
if ( V_3 == 0 ) {
if ( F_2 ) {
V_3 = F_2 ( V_2 ) ;
if ( V_3 )
F_5 ( F_4 ( V_2 ) ) ;
}
}
F_6 ( V_2 , L_1 , V_3 ) ;
return V_3 ;
}
static int F_7 ( struct V_1 * V_2 , int (* F_2)( struct V_1 * ) )
{
int V_3 = 0 ;
if ( F_2 )
V_3 = F_2 ( V_2 ) ;
F_5 ( F_4 ( V_2 ) ) ;
F_6 ( V_2 , L_2 , V_3 ) ;
return V_3 ;
}
static int
F_8 ( struct V_1 * V_2 , int (* F_2)( struct V_1 * ) )
{
int V_3 = 0 ;
if ( F_9 ( V_2 ) ) {
if ( F_10 ( V_2 ) )
return 0 ;
V_3 = F_1 ( V_2 , F_2 ) ;
}
return V_3 ;
}
static int
F_11 ( struct V_1 * V_2 , int (* F_2)( struct V_1 * ) )
{
int V_3 = 0 ;
if ( F_9 ( V_2 ) )
V_3 = F_7 ( V_2 , F_2 ) ;
if ( V_3 == 0 ) {
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
}
return V_3 ;
}
static int F_15 ( struct V_1 * V_2 )
{
if ( F_9 ( V_2 ) ) {
F_16 ( & V_4 ) ;
} else if ( F_17 ( V_2 ) ) {
F_18 () ;
}
return 0 ;
}
static int F_19 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_2 -> V_7 ? V_2 -> V_7 -> V_6 : NULL ;
return F_8 ( V_2 , V_6 ? V_6 -> V_8 : NULL ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_2 -> V_7 ? V_2 -> V_7 -> V_6 : NULL ;
return F_11 ( V_2 , V_6 ? V_6 -> V_9 : NULL ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_2 -> V_7 ? V_2 -> V_7 -> V_6 : NULL ;
return F_8 ( V_2 , V_6 ? V_6 -> V_10 : NULL ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_2 -> V_7 ? V_2 -> V_7 -> V_6 : NULL ;
return F_11 ( V_2 , V_6 ? V_6 -> V_11 : NULL ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_2 -> V_7 ? V_2 -> V_7 -> V_6 : NULL ;
return F_8 ( V_2 , V_6 ? V_6 -> V_12 : NULL ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_2 -> V_7 ? V_2 -> V_7 -> V_6 : NULL ;
return F_11 ( V_2 , V_6 ? V_6 -> V_13 : NULL ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
const struct V_5 * V_6 = V_2 -> V_7 ? V_2 -> V_7 -> V_6 : NULL ;
F_6 ( V_2 , L_3 ) ;
if ( F_9 ( V_2 ) ) {
V_3 = F_1 ( V_2 ,
V_6 ? V_6 -> V_14 : NULL ) ;
if ( V_3 == - V_15 )
F_26 ( V_2 , F_27 (
F_28 ( V_16 / 10 ) ) ) ;
}
return V_3 ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
const struct V_5 * V_6 = V_2 -> V_7 ? V_2 -> V_7 -> V_6 : NULL ;
F_6 ( V_2 , L_4 ) ;
if ( F_9 ( V_2 ) )
V_3 = F_7 ( V_2 , V_6 ? V_6 -> V_17 : NULL ) ;
return V_3 ;
}
static int F_30 ( struct V_1 * V_2 )
{
int V_3 ;
F_6 ( V_2 , L_5 ) ;
if ( F_9 ( V_2 ) )
V_3 = F_26 ( V_2 , 100 ) ;
else
V_3 = F_31 ( V_2 ) ;
return V_3 ;
}
int F_32 ( struct V_18 * V_19 )
{
int V_3 ;
V_3 = F_33 ( & V_19 -> V_20 ) ;
if ( V_3 < 0 && V_3 != - V_21 )
F_34 ( & V_19 -> V_20 ) ;
else
V_3 = 0 ;
return V_3 ;
}
void F_35 ( struct V_18 * V_19 )
{
F_34 ( & V_19 -> V_20 ) ;
}
void F_36 ( struct V_22 * V_23 )
{
F_33 ( & V_23 -> V_2 ) ;
}
void F_37 ( struct V_22 * V_23 )
{
F_34 ( & V_23 -> V_2 ) ;
}
int F_38 ( struct V_24 * V_25 )
{
int V_3 ;
V_3 = F_33 ( & V_25 -> V_26 ) ;
if ( V_3 < 0 && V_3 != - V_21 )
F_34 ( & V_25 -> V_26 ) ;
else
V_3 = 0 ;
return V_3 ;
}
void F_39 ( struct V_24 * V_25 )
{
F_34 ( & V_25 -> V_26 ) ;
}
