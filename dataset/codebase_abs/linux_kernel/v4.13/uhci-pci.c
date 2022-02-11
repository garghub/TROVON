static void F_1 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( F_4 ( V_2 ) ) , V_2 -> V_3 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_6 ( F_3 ( F_4 ( V_2 ) ) ,
V_2 -> V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_3 ( F_4 ( V_2 ) ) ;
F_8 ( V_5 , V_6 , V_7 ) ;
if ( V_5 -> V_8 == V_9 )
F_9 ( V_5 , V_10 , 0 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_11 ;
switch ( F_3 ( F_4 ( V_2 ) ) -> V_8 ) {
default:
break;
case V_12 :
return 1 ;
case V_9 :
for ( V_11 = 0 ; V_11 < V_2 -> V_13 ; ++ V_11 ) {
if ( F_11 ( V_2 -> V_3 + V_14 + V_11 * 2 ) &
V_15 )
return 1 ;
}
break;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_11 ;
const char * V_16 ;
static const char V_17 [] = L_1 ;
V_16 = F_13 ( V_18 ) ;
if ( V_16 && ! strcmp ( V_16 , V_17 ) ) {
for ( V_11 = 0 ; V_11 < V_2 -> V_13 ; ++ V_11 ) {
if ( F_11 ( V_2 -> V_3 + V_14 + V_11 * 2 ) &
V_19 )
return 1 ;
}
}
return 0 ;
}
static int F_14 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_15 ( V_21 ) ;
V_2 -> V_3 = ( unsigned long ) V_21 -> V_22 ;
V_2 -> V_13 = F_16 ( V_21 ) ;
if ( F_3 ( F_4 ( V_2 ) ) -> V_8 == V_23 )
V_2 -> V_24 = 1 ;
if ( F_3 ( F_4 ( V_2 ) ) -> V_8 == V_25 )
V_2 -> V_26 = 1 ;
if ( F_3 ( F_4 ( V_2 ) ) -> V_8 == V_9 )
F_17 ( F_4 ( V_2 ) , true ) ;
V_2 -> V_27 = F_1 ;
V_2 -> V_28 = F_5 ;
V_2 -> V_29 = F_7 ;
V_2 -> V_30 =
F_10 ;
V_2 -> V_31 =
F_12 ;
V_28 ( V_2 ) ;
return 0 ;
}
static void F_18 ( struct V_4 * V_5 )
{
struct V_20 * V_21 = F_19 ( V_5 ) ;
F_20 ( F_15 ( V_21 ) ) ;
}
static int F_21 ( struct V_20 * V_21 , bool V_32 )
{
struct V_1 * V_2 = F_15 ( V_21 ) ;
struct V_4 * V_5 = F_3 ( F_4 ( V_2 ) ) ;
int V_33 = 0 ;
F_22 ( F_4 ( V_2 ) , L_2 , V_34 ) ;
F_23 ( & V_2 -> V_35 ) ;
if ( ! F_24 ( V_21 ) || V_2 -> V_36 )
goto V_37;
F_8 ( V_5 , V_6 , 0 ) ;
F_25 ( V_38 , & V_21 -> V_39 ) ;
if ( V_32 ) {
if ( V_5 -> V_8 == V_9 )
F_9 ( V_5 , V_10 ,
V_40 | V_41 ) ;
}
V_37:
F_25 ( V_42 , & V_21 -> V_39 ) ;
F_26 ( & V_2 -> V_35 ) ;
F_27 ( V_21 -> V_43 ) ;
if ( V_32 && F_28 ( V_21 ) ) {
F_29 ( V_21 , false ) ;
V_33 = - V_44 ;
}
return V_33 ;
}
static int F_29 ( struct V_20 * V_21 , bool V_45 )
{
struct V_1 * V_2 = F_15 ( V_21 ) ;
F_22 ( F_4 ( V_2 ) , L_2 , V_34 ) ;
F_30 ( V_42 , & V_21 -> V_39 ) ;
F_23 ( & V_2 -> V_35 ) ;
if ( V_45 ) {
V_2 -> V_27 ( V_2 ) ;
F_31 ( V_2 ) ;
}
else {
V_28 ( V_2 ) ;
}
V_29 ( V_2 ) ;
if ( V_2 -> V_46 == V_47 )
F_32 ( V_21 -> V_48 . V_49 ) ;
F_26 ( & V_2 -> V_35 ) ;
if ( ! V_2 -> V_50 && V_21 -> V_48 . V_49 -> V_51 )
F_30 ( V_38 , & V_21 -> V_39 ) ;
F_33 ( V_21 ) ;
return 0 ;
}
