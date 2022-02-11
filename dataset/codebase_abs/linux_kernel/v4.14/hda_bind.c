static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
struct V_8 * V_9 =
F_2 ( V_4 , struct V_8 , V_7 ) ;
const struct V_10 * V_11 ;
T_1 V_12 = V_6 -> V_13 ? V_6 -> V_13 : V_6 -> V_7 . V_14 ;
T_1 V_15 = V_6 -> V_7 . V_16 ;
for ( V_11 = V_9 -> V_12 ; V_11 -> V_14 ; V_11 ++ ) {
if ( V_11 -> V_14 == V_12 &&
( ! V_11 -> V_15 || V_11 -> V_15 == V_15 ) ) {
V_6 -> V_17 = V_11 ;
return 1 ;
}
}
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_18 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
if ( V_6 -> V_19 . V_20 )
V_6 -> V_19 . V_20 ( V_6 , V_18 ) ;
}
int F_4 ( struct V_5 * V_6 , const char * V_21 )
{
int V_22 ;
if ( ! V_21 )
return 0 ;
V_22 = F_5 ( & V_6 -> V_7 , V_21 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( ! * V_6 -> V_23 -> V_24 ||
V_6 -> V_25 -> V_26 >= V_6 -> V_7 . V_27 ) {
snprintf ( V_6 -> V_23 -> V_24 ,
sizeof( V_6 -> V_23 -> V_24 ) , L_1 ,
V_6 -> V_7 . V_28 , V_6 -> V_7 . V_29 ) ;
V_6 -> V_25 -> V_26 = V_6 -> V_7 . V_27 ;
}
return 0 ;
}
static int F_6 ( struct V_30 * V_2 )
{
struct V_5 * V_6 = F_7 ( V_2 ) ;
struct V_31 * V_32 = V_2 -> V_9 -> V_32 ;
T_2 V_33 ;
int V_22 ;
if ( F_8 ( ! V_6 -> V_17 ) )
return - V_34 ;
V_22 = F_4 ( V_6 , V_6 -> V_17 -> V_21 ) ;
if ( V_22 < 0 )
goto error;
V_22 = F_9 ( & V_6 -> V_7 ) ;
if ( V_22 < 0 )
goto error;
if ( ! F_10 ( V_32 ) ) {
V_22 = - V_34 ;
goto error;
}
V_33 = ( T_2 ) V_6 -> V_17 -> V_35 ;
if ( V_33 ) {
V_22 = V_33 ( V_6 ) ;
if ( V_22 < 0 )
goto V_36;
}
V_22 = F_11 ( V_6 ) ;
if ( V_22 < 0 )
goto V_37;
V_22 = F_12 ( V_6 ) ;
if ( V_22 < 0 )
goto V_37;
if ( V_6 -> V_23 -> V_38 ) {
V_22 = F_13 ( V_6 -> V_23 ) ;
if ( V_22 < 0 )
goto V_37;
F_14 ( V_6 ) ;
}
V_6 -> V_7 . V_39 = true ;
return 0 ;
V_37:
if ( V_6 -> V_19 . free )
V_6 -> V_19 . free ( V_6 ) ;
V_36:
F_15 ( V_32 ) ;
error:
F_16 ( V_6 ) ;
return V_22 ;
}
static int F_17 ( struct V_30 * V_2 )
{
struct V_5 * V_6 = F_7 ( V_2 ) ;
if ( V_6 -> V_19 . free )
V_6 -> V_19 . free ( V_6 ) ;
F_16 ( V_6 ) ;
F_15 ( V_2 -> V_9 -> V_32 ) ;
return 0 ;
}
static void F_18 ( struct V_30 * V_2 )
{
struct V_5 * V_6 = F_7 ( V_2 ) ;
if ( ! F_19 ( V_2 ) && V_6 -> V_19 . V_40 )
V_6 -> V_19 . V_40 ( V_6 ) ;
}
int F_20 ( struct V_8 * V_4 , const char * V_21 ,
struct V_31 * V_32 )
{
V_4 -> V_7 . V_9 . V_21 = V_21 ;
V_4 -> V_7 . V_9 . V_32 = V_32 ;
V_4 -> V_7 . V_9 . V_25 = & V_41 ;
V_4 -> V_7 . V_9 . V_42 = F_6 ;
V_4 -> V_7 . V_9 . remove = F_17 ;
V_4 -> V_7 . V_9 . V_43 = F_18 ;
V_4 -> V_7 . V_9 . V_44 = & V_45 ;
V_4 -> V_7 . type = V_46 ;
V_4 -> V_7 . V_47 = F_1 ;
V_4 -> V_7 . V_20 = F_3 ;
return F_21 ( & V_4 -> V_7 . V_9 ) ;
}
void F_22 ( struct V_8 * V_4 )
{
F_23 ( & V_4 -> V_7 . V_9 ) ;
}
static inline bool F_24 ( struct V_5 * V_6 )
{
return F_25 ( F_26 ( V_6 ) ) > 0 && V_6 -> V_17 ;
}
static void F_27 ( struct V_5 * V_6 )
{
#ifdef F_28
char V_48 [ 32 ] ;
const char * V_49 = NULL ;
switch ( V_6 -> V_13 ) {
case V_50 :
#if F_29 ( V_51 )
V_49 = L_2 ;
#endif
break;
case V_52 :
#if F_29 ( V_53 )
V_49 = L_3 ;
#endif
break;
default:
F_30 ( & V_6 -> V_7 , V_48 , sizeof( V_48 ) ) ;
V_49 = V_48 ;
break;
}
if ( V_49 )
F_31 ( V_49 ) ;
#endif
}
static void F_32 ( struct V_5 * V_6 )
{
#ifdef F_28
F_27 ( V_6 ) ;
if ( F_24 ( V_6 ) )
return;
#endif
}
static bool F_33 ( struct V_5 * V_6 )
{
T_3 V_54 ;
F_34 (nid, codec) {
unsigned int V_55 = F_35 ( V_6 , V_54 ) ;
switch ( F_36 ( V_55 ) ) {
case V_56 :
return false ;
case V_57 :
if ( ! ( V_55 & V_58 ) )
return false ;
break;
}
}
return true ;
}
static int F_37 ( struct V_5 * V_6 )
{
if ( V_6 -> V_13 )
return - V_59 ;
if ( F_33 ( V_6 ) ) {
V_6 -> V_13 = V_50 ;
F_27 ( V_6 ) ;
if ( F_24 ( V_6 ) )
return 0 ;
}
V_6 -> V_13 = V_52 ;
F_27 ( V_6 ) ;
if ( F_24 ( V_6 ) )
return 0 ;
return - V_59 ;
}
int F_38 ( struct V_5 * V_6 )
{
int V_22 ;
if ( F_39 ( V_6 ) )
V_6 -> V_13 = V_52 ;
else
V_6 -> V_13 = 0 ;
V_22 = F_40 ( & V_6 -> V_7 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( ! V_6 -> V_17 )
F_32 ( V_6 ) ;
if ( ! V_6 -> V_17 ) {
V_22 = F_37 ( V_6 ) ;
if ( V_22 < 0 ) {
F_41 ( V_6 , L_4 ) ;
goto error;
}
}
return 0 ;
error:
F_42 ( & V_6 -> V_7 ) ;
return V_22 ;
}
