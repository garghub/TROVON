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
static int F_25 ( struct V_14 * V_15 ,
int (* F_2)( struct V_1 * ) )
{
int V_3 ;
V_3 = F_26 ( V_15 -> V_16 ) ;
if ( V_3 )
return V_3 ;
if ( F_2 )
V_3 = F_2 ( & V_15 -> V_17 ) ;
F_27 ( V_15 -> V_16 , V_3 ) ;
return V_3 ;
}
static int F_28 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 = V_2 -> V_7 ? V_2 -> V_7 -> V_6 : NULL ;
int (* F_2)( struct V_1 * ) = V_6 ? V_6 -> V_18 : NULL ;
struct V_14 * V_15 = F_4 ( V_2 ) ;
int V_3 ;
if ( V_15 -> V_16 -> V_2 )
return F_25 ( V_15 , F_2 ) ;
V_3 = F_1 ( V_2 , F_2 ) ;
if ( V_3 == - V_19 )
F_29 ( V_2 , F_30 (
F_31 ( V_20 / 10 ) ) ) ;
return V_3 ;
}
static int F_32 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_6 ( V_2 , L_3 ) ;
if ( F_9 ( V_2 ) )
V_3 = F_28 ( V_2 ) ;
return V_3 ;
}
static int F_33 ( struct V_14 * V_15 ,
int (* F_2)( struct V_1 * ) )
{
int V_3 = 0 ;
F_34 ( V_15 -> V_16 ) ;
if ( F_2 )
V_3 = F_2 ( & V_15 -> V_17 ) ;
F_35 ( V_15 -> V_16 , V_3 ) ;
return V_3 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
const struct V_5 * V_6 = V_2 -> V_7 ? V_2 -> V_7 -> V_6 : NULL ;
int (* F_2)( struct V_1 * ) = V_6 ? V_6 -> V_21 : NULL ;
if ( V_15 -> V_16 -> V_2 )
return F_33 ( V_15 , F_2 ) ;
else
return F_7 ( V_2 , F_2 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
F_6 ( V_2 , L_4 ) ;
if ( F_9 ( V_2 ) )
V_3 = F_36 ( V_2 ) ;
return V_3 ;
}
static int F_38 ( struct V_1 * V_2 )
{
int V_3 ;
F_6 ( V_2 , L_5 ) ;
if ( F_9 ( V_2 ) ) {
struct V_14 * V_15 = F_4 ( V_2 ) ;
if ( V_15 -> V_16 -> V_2 ) {
F_39 ( V_2 ) ;
V_3 = F_40 ( V_2 ) ;
} else {
V_3 = F_41 ( V_2 ) ;
}
} else {
V_3 = F_41 ( V_2 ) ;
}
return V_3 ;
}
int F_42 ( struct V_14 * V_15 )
{
int V_3 ;
V_3 = F_43 ( & V_15 -> V_17 ) ;
if ( V_3 < 0 && V_3 != - V_22 )
F_44 ( & V_15 -> V_17 ) ;
else
V_3 = 0 ;
return V_3 ;
}
void F_45 ( struct V_14 * V_15 )
{
F_44 ( & V_15 -> V_17 ) ;
}
void F_46 ( struct V_23 * V_24 )
{
F_43 ( & V_24 -> V_2 ) ;
}
void F_47 ( struct V_23 * V_24 )
{
F_44 ( & V_24 -> V_2 ) ;
}
int F_48 ( struct V_25 * V_26 )
{
int V_3 ;
V_3 = F_43 ( & V_26 -> V_27 ) ;
if ( V_3 < 0 && V_3 != - V_22 )
F_44 ( & V_26 -> V_27 ) ;
else
V_3 = 0 ;
return V_3 ;
}
void F_49 ( struct V_25 * V_26 )
{
F_44 ( & V_26 -> V_27 ) ;
}
