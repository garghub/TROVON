static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
V_4 -> V_5 = true ;
F_2 ( V_4 , F_3 ( 200 ) ) ;
return V_6 ;
}
static int F_4 ( struct V_3 * V_4 )
{
T_2 V_7 = strlen ( F_5 ( V_4 -> V_8 ) ) + 4 ;
struct V_9 * V_10 ;
F_6 ( & V_4 -> V_11 . V_12 ) ;
V_10 = V_4 -> V_11 . V_13 ;
if ( ! V_10 ) {
V_10 = F_7 ( & V_4 -> V_14 , sizeof( * V_10 ) + 2 * V_7 ,
V_15 ) ;
if ( V_10 ) {
V_10 -> V_16 = V_10 -> V_17 + V_7 ;
snprintf ( V_10 -> V_17 , V_7 , L_1 , F_5 ( V_4 -> V_8 ) ) ;
snprintf ( V_10 -> V_16 , V_7 , L_2 , F_5 ( V_4 -> V_8 ) ) ;
V_4 -> V_11 . V_13 = V_10 ;
}
}
F_8 ( & V_4 -> V_11 . V_12 ) ;
return V_10 ? 0 : - V_18 ;
}
int F_9 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_11 . V_13 ;
if ( ! V_10 || ! V_10 -> V_19 )
return - V_20 ;
if ( V_10 -> V_21 )
return ! F_10 ( V_10 -> V_19 ) ^
! ! ( V_4 -> V_22 & V_23 ) ;
return F_11 ( V_10 -> V_19 ) ;
}
int F_12 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_11 . V_13 ;
if ( ! V_10 || ! V_10 -> V_24 )
return - V_20 ;
if ( V_10 -> V_25 )
return ! F_10 ( V_10 -> V_24 ) ^
! ! ( V_4 -> V_22 & V_26 ) ;
return F_11 ( V_10 -> V_24 ) ;
}
int F_13 ( struct V_3 * V_4 , unsigned int V_27 )
{
struct V_9 * V_10 ;
int V_28 ;
if ( ! F_14 ( V_27 ) )
return - V_29 ;
V_28 = F_4 ( V_4 ) ;
if ( V_28 < 0 )
return V_28 ;
V_10 = V_4 -> V_11 . V_13 ;
V_28 = F_15 ( & V_4 -> V_14 , V_27 , V_30 ,
V_10 -> V_16 ) ;
if ( V_28 < 0 )
return V_28 ;
V_10 -> V_21 = true ;
V_10 -> V_19 = F_16 ( V_27 ) ;
return 0 ;
}
void F_17 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_11 . V_13 ;
int V_28 , V_1 ;
if ( V_4 -> V_11 . V_31 >= 0 || ! V_10 || ! V_10 -> V_24 )
return;
V_1 = F_18 ( V_10 -> V_24 ) ;
if ( V_1 >= 0 && V_4 -> V_32 & V_33 )
V_1 = - V_29 ;
if ( V_1 >= 0 ) {
V_28 = F_19 ( & V_4 -> V_14 , V_1 ,
NULL , F_1 ,
V_34 | V_35 | V_36 ,
V_10 -> V_17 , V_4 ) ;
if ( V_28 < 0 )
V_1 = V_28 ;
}
V_4 -> V_11 . V_31 = V_1 ;
if ( V_1 < 0 )
V_4 -> V_32 |= V_33 ;
}
int F_20 ( struct V_3 * V_4 , unsigned int V_27 ,
unsigned int V_37 )
{
struct V_9 * V_10 ;
int V_28 ;
V_28 = F_4 ( V_4 ) ;
if ( V_28 < 0 )
return V_28 ;
V_10 = V_4 -> V_11 . V_13 ;
V_28 = F_15 ( & V_4 -> V_14 , V_27 , V_30 ,
V_10 -> V_17 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_37 ) {
V_28 = F_21 ( V_27 , V_37 ) ;
if ( V_28 < 0 )
return V_28 ;
}
V_10 -> V_25 = true ;
V_10 -> V_24 = F_16 ( V_27 ) ;
return 0 ;
}
void F_22 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_11 . V_13 ;
int V_27 ;
if ( ! V_10 || ! V_10 -> V_19 )
return;
V_27 = F_23 ( V_10 -> V_19 ) ;
V_10 -> V_19 = NULL ;
F_24 ( & V_4 -> V_14 , V_27 ) ;
}
void F_25 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_11 . V_13 ;
int V_27 ;
if ( ! V_10 || ! V_10 -> V_24 )
return;
if ( V_4 -> V_11 . V_31 >= 0 ) {
F_26 ( & V_4 -> V_14 , V_4 -> V_11 . V_31 , V_4 ) ;
V_4 -> V_11 . V_31 = - V_29 ;
}
V_27 = F_23 ( V_10 -> V_24 ) ;
V_10 -> V_24 = NULL ;
F_24 ( & V_4 -> V_14 , V_27 ) ;
}
int F_27 ( struct V_3 * V_4 , const char * V_38 ,
unsigned int V_39 , bool V_40 ,
unsigned int V_37 , bool * V_41 )
{
struct V_9 * V_10 ;
struct V_42 * V_43 ;
int V_28 ;
V_28 = F_4 ( V_4 ) ;
if ( V_28 < 0 )
return V_28 ;
V_10 = V_4 -> V_11 . V_13 ;
if ( ! V_38 )
V_38 = V_10 -> V_17 ;
V_43 = F_28 ( V_4 -> V_8 , V_38 , V_39 , V_44 ) ;
if ( F_29 ( V_43 ) )
return F_30 ( V_43 ) ;
if ( V_37 ) {
V_28 = F_31 ( V_43 , V_37 ) ;
if ( V_28 < 0 )
return V_28 ;
}
if ( V_41 )
* V_41 = ! F_32 ( V_43 ) ;
V_10 -> V_25 = V_40 ;
V_10 -> V_24 = V_43 ;
return 0 ;
}
int F_33 ( struct V_3 * V_4 , const char * V_38 ,
unsigned int V_39 , bool V_40 ,
unsigned int V_37 , bool * V_41 )
{
struct V_9 * V_10 ;
struct V_42 * V_43 ;
int V_28 ;
V_28 = F_4 ( V_4 ) ;
if ( V_28 < 0 )
return V_28 ;
V_10 = V_4 -> V_11 . V_13 ;
if ( ! V_38 )
V_38 = V_10 -> V_16 ;
V_43 = F_28 ( V_4 -> V_8 , V_38 , V_39 , V_44 ) ;
if ( F_29 ( V_43 ) )
return F_30 ( V_43 ) ;
if ( V_37 ) {
V_28 = F_31 ( V_43 , V_37 ) ;
if ( V_28 < 0 )
return V_28 ;
}
if ( V_41 )
* V_41 = ! F_32 ( V_43 ) ;
V_10 -> V_21 = V_40 ;
V_10 -> V_19 = V_43 ;
return 0 ;
}
void F_34 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_11 . V_13 ;
if ( ! V_10 || ! V_10 -> V_24 )
return;
if ( V_4 -> V_11 . V_31 >= 0 ) {
F_26 ( & V_4 -> V_14 , V_4 -> V_11 . V_31 , V_4 ) ;
V_4 -> V_11 . V_31 = - V_29 ;
}
F_35 ( V_4 -> V_8 , V_10 -> V_24 ) ;
V_10 -> V_24 = NULL ;
}
