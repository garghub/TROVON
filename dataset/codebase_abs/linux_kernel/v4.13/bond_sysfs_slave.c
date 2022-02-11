static T_1 F_1 ( struct V_1 * V_1 , char * V_2 )
{
switch ( F_2 ( V_1 ) ) {
case V_3 :
return sprintf ( V_2 , L_1 ) ;
case V_4 :
return sprintf ( V_2 , L_2 ) ;
default:
return sprintf ( V_2 , L_3 ) ;
}
}
static T_1 F_3 ( struct V_1 * V_1 , char * V_2 )
{
return sprintf ( V_2 , L_4 , F_4 ( V_1 -> V_5 ) ) ;
}
static T_1 F_5 ( struct V_1 * V_1 , char * V_2 )
{
return sprintf ( V_2 , L_5 , V_1 -> V_6 ) ;
}
static T_1 F_6 ( struct V_1 * V_1 , char * V_2 )
{
return sprintf ( V_2 , L_6 , V_1 -> V_7 ) ;
}
static T_1 F_7 ( struct V_1 * V_1 , char * V_2 )
{
return sprintf ( V_2 , L_5 , V_1 -> V_8 ) ;
}
static T_1 F_8 ( struct V_1 * V_1 , char * V_2 )
{
const struct V_9 * V_10 ;
if ( F_9 ( V_1 -> V_11 ) == V_12 ) {
V_10 = F_10 ( V_1 ) -> V_13 . V_9 ;
if ( V_10 )
return sprintf ( V_2 , L_5 ,
V_10 -> V_14 ) ;
}
return sprintf ( V_2 , L_7 ) ;
}
static T_1 F_11 ( struct V_1 * V_1 , char * V_2 )
{
const struct V_13 * V_15 ;
if ( F_9 ( V_1 -> V_11 ) == V_12 ) {
V_15 = & F_10 ( V_1 ) -> V_13 ;
if ( V_15 -> V_9 )
return sprintf ( V_2 , L_8 ,
V_15 -> V_16 ) ;
}
return sprintf ( V_2 , L_7 ) ;
}
static T_1 F_12 ( struct V_1 * V_1 , char * V_2 )
{
const struct V_13 * V_15 ;
if ( F_9 ( V_1 -> V_11 ) == V_12 ) {
V_15 = & F_10 ( V_1 ) -> V_13 ;
if ( V_15 -> V_9 )
return sprintf ( V_2 , L_8 ,
V_15 -> V_17 . V_18 ) ;
}
return sprintf ( V_2 , L_7 ) ;
}
static T_1 F_13 ( struct V_19 * V_20 ,
struct V_21 * V_22 , char * V_2 )
{
struct V_23 * V_24 = F_14 ( V_22 ) ;
struct V_1 * V_1 = F_15 ( V_20 ) ;
return V_24 -> V_25 ( V_1 , V_2 ) ;
}
int F_16 ( struct V_1 * V_1 )
{
const struct V_23 * * V_26 ;
int V_27 ;
V_27 = F_17 ( & V_1 -> V_20 , & V_28 ,
& ( V_1 -> V_29 -> V_29 . V_20 ) , L_9 ) ;
if ( V_27 )
return V_27 ;
for ( V_26 = V_30 ; * V_26 ; ++ V_26 ) {
V_27 = F_18 ( & V_1 -> V_20 , & ( ( * V_26 ) -> V_22 ) ) ;
if ( V_27 ) {
F_19 ( & V_1 -> V_20 ) ;
return V_27 ;
}
}
return 0 ;
}
void F_20 ( struct V_1 * V_1 )
{
const struct V_23 * * V_26 ;
for ( V_26 = V_30 ; * V_26 ; ++ V_26 )
F_21 ( & V_1 -> V_20 , & ( ( * V_26 ) -> V_22 ) ) ;
F_19 ( & V_1 -> V_20 ) ;
}
