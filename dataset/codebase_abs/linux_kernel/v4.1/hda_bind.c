static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
struct V_8 * V_9 =
F_2 ( V_4 , struct V_8 , V_7 ) ;
const struct V_10 * V_11 ;
T_1 V_12 = V_6 -> V_13 ? V_6 -> V_13 : V_6 -> V_7 . V_14 ;
for ( V_11 = V_9 -> V_11 ; V_11 -> V_12 ; V_11 ++ ) {
T_1 V_15 = V_11 -> V_15 ;
if ( V_11 -> V_16 && V_11 -> V_16 != V_6 -> V_7 . V_16 )
continue;
if ( V_11 -> V_17 && V_11 -> V_17 != V_6 -> V_7 . V_17 )
continue;
if ( ! V_15 )
V_15 = ~ 0 ;
if ( V_11 -> V_12 == ( V_12 & V_15 ) &&
( ! V_11 -> V_18 || V_11 -> V_18 == V_6 -> V_7 . V_19 ) ) {
V_6 -> V_11 = V_11 ;
return 1 ;
}
}
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 , struct V_5 , V_7 ) ;
if ( V_6 -> V_21 . V_22 )
V_6 -> V_21 . V_22 ( V_6 , V_20 ) ;
}
static int F_4 ( struct V_5 * V_6 , const char * V_23 )
{
if ( V_23 ) {
F_5 ( V_6 -> V_7 . V_24 ) ;
V_6 -> V_7 . V_24 = F_6 ( V_23 , V_25 ) ;
}
return V_6 -> V_7 . V_24 ? 0 : - V_26 ;
}
static int F_7 ( struct V_27 * V_2 )
{
struct V_5 * V_6 = F_8 ( V_2 ) ;
struct V_28 * V_29 = V_2 -> V_9 -> V_29 ;
int V_30 ;
if ( F_9 ( ! V_6 -> V_11 ) )
return - V_31 ;
V_30 = F_4 ( V_6 , V_6 -> V_11 -> V_23 ) ;
if ( V_30 < 0 )
goto error;
V_30 = F_10 ( & V_6 -> V_7 ) ;
if ( V_30 < 0 )
goto error;
if ( ! F_11 ( V_29 ) ) {
V_30 = - V_31 ;
goto error;
}
V_30 = V_6 -> V_11 -> V_32 ( V_6 ) ;
if ( V_30 < 0 )
goto V_33;
V_30 = F_12 ( V_6 ) ;
if ( V_30 < 0 )
goto V_33;
V_30 = F_13 ( V_6 ) ;
if ( V_30 < 0 )
goto V_33;
if ( V_6 -> V_34 -> V_35 ) {
V_30 = F_14 ( V_6 -> V_34 ) ;
if ( V_30 < 0 )
goto V_33;
F_15 ( V_6 ) ;
}
V_6 -> V_7 . V_36 = true ;
return 0 ;
V_33:
F_16 ( V_29 ) ;
error:
F_17 ( V_6 ) ;
return V_30 ;
}
static int F_18 ( struct V_27 * V_2 )
{
struct V_5 * V_6 = F_8 ( V_2 ) ;
if ( V_6 -> V_21 . free )
V_6 -> V_21 . free ( V_6 ) ;
F_17 ( V_6 ) ;
F_16 ( V_2 -> V_9 -> V_29 ) ;
return 0 ;
}
static void F_19 ( struct V_27 * V_2 )
{
struct V_5 * V_6 = F_8 ( V_2 ) ;
if ( ! F_20 ( V_2 ) && V_6 -> V_21 . V_37 )
V_6 -> V_21 . V_37 ( V_6 ) ;
}
int F_21 ( struct V_8 * V_4 , const char * V_23 ,
struct V_28 * V_29 )
{
V_4 -> V_7 . V_9 . V_23 = V_23 ;
V_4 -> V_7 . V_9 . V_29 = V_29 ;
V_4 -> V_7 . V_9 . V_38 = & V_39 ;
V_4 -> V_7 . V_9 . V_40 = F_7 ;
V_4 -> V_7 . V_9 . remove = F_18 ;
V_4 -> V_7 . V_9 . V_41 = F_19 ;
V_4 -> V_7 . V_9 . V_42 = & V_43 ;
V_4 -> V_7 . type = V_44 ;
V_4 -> V_7 . V_45 = F_1 ;
V_4 -> V_7 . V_22 = F_3 ;
return F_22 ( & V_4 -> V_7 . V_9 ) ;
}
void F_23 ( struct V_8 * V_4 )
{
F_24 ( & V_4 -> V_7 . V_9 ) ;
}
static inline bool F_25 ( struct V_5 * V_6 )
{
return F_26 ( F_27 ( V_6 ) ) > 0 && V_6 -> V_11 ;
}
static void F_28 ( struct V_5 * V_6 )
{
#ifdef F_29
F_30 ( L_1 , V_6 -> V_7 . V_14 ) ;
if ( F_25 ( V_6 ) )
return;
F_30 ( L_2 ,
( V_6 -> V_7 . V_14 >> 16 ) & 0xffff ) ;
if ( F_25 ( V_6 ) )
return;
#endif
}
static bool F_31 ( struct V_5 * V_6 )
{
T_2 V_46 ;
F_32 (nid, codec) {
unsigned int V_47 = F_33 ( V_6 , V_46 ) ;
switch ( F_34 ( V_47 ) ) {
case V_48 :
return false ;
case V_49 :
if ( ! ( V_47 & V_50 ) )
return false ;
break;
}
}
return true ;
}
static int F_35 ( struct V_5 * V_6 )
{
if ( V_6 -> V_13 )
return - V_51 ;
if ( F_31 ( V_6 ) ) {
V_6 -> V_13 = V_52 ;
#if F_36 ( V_53 )
F_30 ( L_3 ) ;
#endif
if ( F_25 ( V_6 ) )
return 0 ;
}
V_6 -> V_13 = V_54 ;
#if F_36 ( V_55 )
F_30 ( L_4 ) ;
#endif
if ( F_25 ( V_6 ) )
return 0 ;
return - V_51 ;
}
int F_37 ( struct V_5 * V_6 )
{
int V_30 ;
if ( F_38 ( V_6 ) )
V_6 -> V_13 = V_54 ;
else
V_6 -> V_13 = 0 ;
V_30 = F_39 ( & V_6 -> V_7 ) ;
if ( V_30 < 0 )
return V_30 ;
if ( ! V_6 -> V_11 )
F_28 ( V_6 ) ;
if ( ! V_6 -> V_11 ) {
V_30 = F_35 ( V_6 ) ;
if ( V_30 < 0 ) {
F_40 ( V_6 , L_5 ) ;
goto error;
}
}
if ( V_6 -> V_7 . V_16 || ! * V_6 -> V_34 -> V_56 )
snprintf ( V_6 -> V_34 -> V_56 ,
sizeof( V_6 -> V_34 -> V_56 ) , L_6 ,
V_6 -> V_7 . V_57 , V_6 -> V_7 . V_24 ) ;
return 0 ;
error:
F_41 ( & V_6 -> V_7 ) ;
return V_30 ;
}
