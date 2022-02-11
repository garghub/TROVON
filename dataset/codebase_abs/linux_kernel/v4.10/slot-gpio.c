static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
V_4 -> V_5 = true ;
F_2 ( V_4 , F_3 ( 200 ) ) ;
return V_6 ;
}
int F_4 ( struct V_3 * V_4 )
{
T_2 V_7 = strlen ( F_5 ( V_4 -> V_8 ) ) + 4 ;
struct V_9 * V_10 = F_6 ( V_4 -> V_8 ,
sizeof( * V_10 ) + 2 * V_7 , V_11 ) ;
if ( V_10 ) {
V_10 -> V_12 = V_10 -> V_13 + V_7 ;
snprintf ( V_10 -> V_13 , V_7 , L_1 , F_5 ( V_4 -> V_8 ) ) ;
snprintf ( V_10 -> V_12 , V_7 , L_2 , F_5 ( V_4 -> V_8 ) ) ;
V_4 -> V_14 . V_15 = V_10 ;
V_4 -> V_14 . V_16 = - V_17 ;
}
return V_10 ? 0 : - V_18 ;
}
int F_7 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_14 . V_15 ;
if ( ! V_10 || ! V_10 -> V_19 )
return - V_20 ;
if ( V_10 -> V_21 )
return ! F_8 ( V_10 -> V_19 ) ^
! ! ( V_4 -> V_22 & V_23 ) ;
return F_9 ( V_10 -> V_19 ) ;
}
int F_10 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_14 . V_15 ;
if ( ! V_10 || ! V_10 -> V_24 )
return - V_20 ;
if ( V_10 -> V_25 )
return ! F_8 ( V_10 -> V_24 ) ^
! ! ( V_4 -> V_22 & V_26 ) ;
return F_9 ( V_10 -> V_24 ) ;
}
int F_11 ( struct V_3 * V_4 , unsigned int V_27 )
{
struct V_9 * V_10 = V_4 -> V_14 . V_15 ;
int V_28 ;
if ( ! F_12 ( V_27 ) )
return - V_17 ;
V_28 = F_13 ( V_4 -> V_8 , V_27 , V_29 ,
V_10 -> V_12 ) ;
if ( V_28 < 0 )
return V_28 ;
V_10 -> V_21 = true ;
V_10 -> V_19 = F_14 ( V_27 ) ;
return 0 ;
}
void F_15 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_14 . V_15 ;
int V_28 , V_1 ;
if ( V_4 -> V_14 . V_16 >= 0 || ! V_10 || ! V_10 -> V_24 )
return;
V_1 = F_16 ( V_10 -> V_24 ) ;
if ( V_1 >= 0 && V_4 -> V_30 & V_31 )
V_1 = - V_17 ;
if ( V_1 >= 0 ) {
if ( ! V_10 -> V_32 )
V_10 -> V_32 = F_1 ;
V_28 = F_17 ( V_4 -> V_8 , V_1 ,
NULL , V_10 -> V_32 ,
V_33 | V_34 | V_35 ,
V_10 -> V_13 , V_4 ) ;
if ( V_28 < 0 )
V_1 = V_28 ;
}
V_4 -> V_14 . V_16 = V_1 ;
if ( V_1 < 0 )
V_4 -> V_30 |= V_31 ;
}
void F_18 ( struct V_3 * V_4 ,
T_1 (* F_19)( int V_1 , void * V_2 ) )
{
struct V_9 * V_10 = V_4 -> V_14 . V_15 ;
F_20 ( V_10 -> V_32 ) ;
V_10 -> V_32 = F_19 ;
}
int F_21 ( struct V_3 * V_4 , unsigned int V_27 ,
unsigned int V_36 )
{
struct V_9 * V_10 = V_4 -> V_14 . V_15 ;
int V_28 ;
V_28 = F_13 ( V_4 -> V_8 , V_27 , V_29 ,
V_10 -> V_13 ) ;
if ( V_28 < 0 )
return V_28 ;
if ( V_36 ) {
V_28 = F_22 ( V_27 , V_36 ) ;
if ( V_28 < 0 )
return V_28 ;
}
V_10 -> V_25 = true ;
V_10 -> V_24 = F_14 ( V_27 ) ;
return 0 ;
}
int F_23 ( struct V_3 * V_4 , const char * V_37 ,
unsigned int V_38 , bool V_39 ,
unsigned int V_36 , bool * V_40 )
{
struct V_9 * V_10 = V_4 -> V_14 . V_15 ;
struct V_41 * V_42 ;
int V_28 ;
if ( ! V_37 )
V_37 = V_10 -> V_13 ;
V_42 = F_24 ( V_4 -> V_8 , V_37 , V_38 , V_43 ) ;
if ( F_25 ( V_42 ) )
return F_26 ( V_42 ) ;
if ( V_36 ) {
V_28 = F_27 ( V_42 , V_36 ) ;
if ( V_28 < 0 )
return V_28 ;
}
if ( V_40 )
* V_40 = ! F_28 ( V_42 ) ;
V_10 -> V_25 = V_39 ;
V_10 -> V_24 = V_42 ;
return 0 ;
}
bool F_29 ( struct V_3 * V_4 )
{
struct V_9 * V_10 = V_4 -> V_14 . V_15 ;
return V_10 -> V_24 ? true : false ;
}
int F_30 ( struct V_3 * V_4 , const char * V_37 ,
unsigned int V_38 , bool V_39 ,
unsigned int V_36 , bool * V_40 )
{
struct V_9 * V_10 = V_4 -> V_14 . V_15 ;
struct V_41 * V_42 ;
int V_28 ;
if ( ! V_37 )
V_37 = V_10 -> V_12 ;
V_42 = F_24 ( V_4 -> V_8 , V_37 , V_38 , V_43 ) ;
if ( F_25 ( V_42 ) )
return F_26 ( V_42 ) ;
if ( V_36 ) {
V_28 = F_27 ( V_42 , V_36 ) ;
if ( V_28 < 0 )
return V_28 ;
}
if ( V_40 )
* V_40 = ! F_28 ( V_42 ) ;
V_10 -> V_21 = V_39 ;
V_10 -> V_19 = V_42 ;
return 0 ;
}
