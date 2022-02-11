int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_3 * * V_5 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
struct V_10 * V_11 = ( void * ) V_4 -> V_12 ;
int V_13 = 0 ;
long V_14 ;
bool V_15 = true ;
struct V_3 * V_16 = NULL ;
if ( F_2 ( ! V_5 ) )
return - V_17 ;
F_3 ( & V_7 -> V_18 ) ;
V_7 -> V_19 ++ ;
V_11 -> V_19 = F_4 ( V_7 -> V_19 ) ;
F_5 ( V_7 -> V_16 , L_1 ) ;
V_7 -> V_20 = true ;
F_6 ( & V_7 -> V_18 ) ;
V_13 = F_7 ( V_2 , V_4 ) ;
F_8 ( V_4 ) ;
if ( F_2 ( V_13 ) )
goto V_21;
V_14 = F_9 (
& V_7 -> V_22 ,
V_23 ) ;
F_3 ( & V_7 -> V_18 ) ;
V_15 = V_7 -> V_20 ;
V_16 = V_7 -> V_16 ;
V_7 -> V_16 = NULL ;
V_7 -> V_20 = false ;
F_6 ( & V_7 -> V_18 ) ;
if ( F_2 ( V_14 <= 0 ) ) {
if ( V_14 == 0 ) {
V_13 = - V_24 ;
F_10 ( L_2 ) ;
} else {
V_13 = - V_25 ;
F_11 ( L_3 ) ;
}
}
if ( F_2 ( ! V_16 || V_15 ) ) {
if ( ! V_13 )
V_13 = - V_17 ;
goto V_21;
}
V_13 = 0 ;
* V_5 = V_16 ;
V_21:
if ( F_2 ( V_16 && V_15 ) )
F_8 ( V_16 ) ;
return V_13 ;
}
static void F_12 ( struct V_1 * V_2 , struct V_3 * V_26 )
{
struct V_6 * V_7 = & V_2 -> V_8 . V_9 ;
const struct V_27 * V_28 = ( const struct V_27 * ) V_26 -> V_12 ;
const T_1 V_29 = F_13 ( V_28 -> V_19 ) ;
F_3 ( & V_7 -> V_18 ) ;
if ( F_2 ( ! V_7 -> V_20 ) ) {
F_10 ( L_4 ) ;
goto V_30;
}
if ( F_2 ( V_29 != V_7 -> V_19 ) ) {
F_10 ( L_5 ) ;
goto V_30;
}
V_7 -> V_16 = V_26 ;
V_7 -> V_20 = false ;
F_6 ( & V_7 -> V_18 ) ;
F_14 ( & V_7 -> V_22 ) ;
return;
V_30:
F_6 ( & V_7 -> V_18 ) ;
F_8 ( V_26 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_3 * V_26 )
{
struct V_31 * V_8 = & V_2 -> V_8 ;
if ( F_16 ( F_17 ( & V_8 -> V_32 ) <
V_8 -> V_33 ) ) {
F_18 ( & V_8 -> V_32 , V_26 ) ;
F_19 ( V_2 -> V_34 , & V_2 -> V_35 ) ;
} else {
F_20 ( L_6 ) ;
F_8 ( V_26 ) ;
return - 1 ;
}
return 0 ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_31 * V_8 = & V_2 -> V_8 ;
F_22 ( & V_8 -> V_9 . V_22 ) ;
F_23 ( & V_8 -> V_9 . V_18 ) ;
F_3 ( & V_8 -> V_9 . V_18 ) ;
V_8 -> V_9 . V_19 = 0 ;
V_8 -> V_9 . V_20 = false ;
V_8 -> V_9 . V_16 = NULL ;
F_6 ( & V_8 -> V_9 . V_18 ) ;
F_24 ( & V_8 -> V_32 ) ;
V_8 -> V_33 = V_36 ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_37 * V_32 = & V_2 -> V_8 . V_32 ;
struct V_3 * V_38 = F_26 ( V_32 ) ;
while ( V_38 ) {
F_27 ( V_38 ) ;
V_38 = F_26 ( V_32 ) ;
}
}
void F_28 ( struct V_1 * V_2 )
{
if ( ! V_2 ) {
F_10 ( L_7 ) ;
return;
}
F_25 ( V_2 ) ;
}
int F_29 ( struct V_1 * V_2 , struct V_3 * V_26 )
{
const struct V_39 * V_40 = ( void * ) V_26 -> V_12 ;
int V_13 = - 1 ;
if ( F_2 ( V_26 -> V_41 < sizeof( * V_40 ) ) ) {
F_20 ( L_8 , V_26 -> V_41 ) ;
F_8 ( V_26 ) ;
return - V_42 ;
}
if ( F_2 ( V_26 -> V_41 != F_13 ( V_40 -> V_41 ) ) ) {
F_20 ( L_9 ,
V_26 -> V_41 , F_13 ( V_40 -> V_41 ) ) ;
F_8 ( V_26 ) ;
return - V_17 ;
}
switch ( F_13 ( V_40 -> type ) ) {
case V_43 :
if ( F_2 ( V_26 -> V_41 < sizeof( struct V_10 ) ) ) {
F_20 ( L_10 , V_26 -> V_41 ) ;
F_8 ( V_26 ) ;
break;
}
F_12 ( V_2 , V_26 ) ;
break;
case V_44 :
if ( F_2 ( V_26 -> V_41 < sizeof( struct V_45 ) ) ) {
F_20 ( L_11 , V_26 -> V_41 ) ;
F_8 ( V_26 ) ;
break;
}
V_13 = F_15 ( V_2 , V_26 ) ;
break;
default:
F_20 ( L_12 , F_13 ( V_40 -> type ) ) ;
F_8 ( V_26 ) ;
break;
}
return V_13 ;
}
