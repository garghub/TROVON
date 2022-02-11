static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
if ( V_4 -> V_5 -> V_6 )
V_4 -> V_5 -> V_6 ( V_4 ) ;
F_2 ( V_4 , F_3 ( 200 ) ) ;
return V_7 ;
}
static int F_4 ( struct V_3 * V_4 )
{
T_2 V_8 = strlen ( F_5 ( V_4 -> V_9 ) ) + 4 ;
struct V_10 * V_11 ;
F_6 ( & V_4 -> V_12 . V_13 ) ;
V_11 = V_4 -> V_12 . V_14 ;
if ( ! V_11 ) {
V_11 = F_7 ( & V_4 -> V_15 , sizeof( * V_11 ) + 2 * V_8 ,
V_16 ) ;
if ( V_11 ) {
V_11 -> V_17 = V_11 -> V_18 + V_8 ;
snprintf ( V_11 -> V_18 , V_8 , L_1 , F_5 ( V_4 -> V_9 ) ) ;
snprintf ( V_11 -> V_17 , V_8 , L_2 , F_5 ( V_4 -> V_9 ) ) ;
V_4 -> V_12 . V_14 = V_11 ;
}
}
F_8 ( & V_4 -> V_12 . V_13 ) ;
return V_11 ? 0 : - V_19 ;
}
int F_9 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 . V_14 ;
if ( ! V_11 || ! V_11 -> V_20 )
return - V_21 ;
if ( V_11 -> V_22 )
return ! F_10 ( V_11 -> V_20 ) ^
! ! ( V_4 -> V_23 & V_24 ) ;
return F_11 ( V_11 -> V_20 ) ;
}
int F_12 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 . V_14 ;
if ( ! V_11 || ! V_11 -> V_25 )
return - V_21 ;
if ( V_11 -> V_26 )
return ! F_10 ( V_11 -> V_25 ) ^
! ! ( V_4 -> V_23 & V_27 ) ;
return F_11 ( V_11 -> V_25 ) ;
}
int F_13 ( struct V_3 * V_4 , unsigned int V_28 )
{
struct V_10 * V_11 ;
int V_29 ;
if ( ! F_14 ( V_28 ) )
return - V_30 ;
V_29 = F_4 ( V_4 ) ;
if ( V_29 < 0 )
return V_29 ;
V_11 = V_4 -> V_12 . V_14 ;
V_29 = F_15 ( & V_4 -> V_15 , V_28 , V_31 ,
V_11 -> V_17 ) ;
if ( V_29 < 0 )
return V_29 ;
V_11 -> V_22 = true ;
V_11 -> V_20 = F_16 ( V_28 ) ;
return 0 ;
}
void F_17 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 . V_14 ;
int V_29 , V_1 ;
if ( V_4 -> V_12 . V_32 >= 0 || ! V_11 || ! V_11 -> V_25 )
return;
V_1 = F_18 ( V_11 -> V_25 ) ;
if ( V_1 >= 0 && V_4 -> V_33 & V_34 )
V_1 = - V_30 ;
if ( V_1 >= 0 ) {
V_29 = F_19 ( & V_4 -> V_15 , V_1 ,
NULL , F_1 ,
V_35 | V_36 | V_37 ,
V_11 -> V_18 , V_4 ) ;
if ( V_29 < 0 )
V_1 = V_29 ;
}
V_4 -> V_12 . V_32 = V_1 ;
if ( V_1 < 0 )
V_4 -> V_33 |= V_34 ;
}
int F_20 ( struct V_3 * V_4 , unsigned int V_28 ,
unsigned int V_38 )
{
struct V_10 * V_11 ;
int V_29 ;
V_29 = F_4 ( V_4 ) ;
if ( V_29 < 0 )
return V_29 ;
V_11 = V_4 -> V_12 . V_14 ;
V_29 = F_15 ( & V_4 -> V_15 , V_28 , V_31 ,
V_11 -> V_18 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_38 ) {
V_29 = F_21 ( V_28 , V_38 ) ;
if ( V_29 < 0 )
return V_29 ;
}
V_11 -> V_26 = true ;
V_11 -> V_25 = F_16 ( V_28 ) ;
F_17 ( V_4 ) ;
return 0 ;
}
void F_22 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 . V_14 ;
int V_28 ;
if ( ! V_11 || ! V_11 -> V_20 )
return;
V_28 = F_23 ( V_11 -> V_20 ) ;
V_11 -> V_20 = NULL ;
F_24 ( & V_4 -> V_15 , V_28 ) ;
}
void F_25 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 . V_14 ;
int V_28 ;
if ( ! V_11 || ! V_11 -> V_25 )
return;
if ( V_4 -> V_12 . V_32 >= 0 ) {
F_26 ( & V_4 -> V_15 , V_4 -> V_12 . V_32 , V_4 ) ;
V_4 -> V_12 . V_32 = - V_30 ;
}
V_28 = F_23 ( V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
F_24 ( & V_4 -> V_15 , V_28 ) ;
}
int F_27 ( struct V_3 * V_4 , const char * V_39 ,
unsigned int V_40 , bool V_41 ,
unsigned int V_38 )
{
struct V_10 * V_11 ;
struct V_42 * V_43 ;
int V_29 ;
V_29 = F_4 ( V_4 ) ;
if ( V_29 < 0 )
return V_29 ;
V_11 = V_4 -> V_12 . V_14 ;
if ( ! V_39 )
V_39 = V_11 -> V_18 ;
V_43 = F_28 ( V_4 -> V_9 , V_39 , V_40 ) ;
if ( F_29 ( V_43 ) )
return F_30 ( V_43 ) ;
V_29 = F_31 ( V_43 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_38 ) {
V_29 = F_32 ( V_43 , V_38 ) ;
if ( V_29 < 0 )
return V_29 ;
}
V_11 -> V_26 = V_41 ;
V_11 -> V_25 = V_43 ;
return 0 ;
}
void F_33 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = V_4 -> V_12 . V_14 ;
if ( ! V_11 || ! V_11 -> V_25 )
return;
if ( V_4 -> V_12 . V_32 >= 0 ) {
F_26 ( & V_4 -> V_15 , V_4 -> V_12 . V_32 , V_4 ) ;
V_4 -> V_12 . V_32 = - V_30 ;
}
F_34 ( & V_4 -> V_15 , V_11 -> V_25 ) ;
V_11 -> V_25 = NULL ;
}
