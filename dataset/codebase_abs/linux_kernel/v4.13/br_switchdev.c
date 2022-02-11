static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 ;
F_2 (p, &br->port_list, list) {
if ( F_3 ( V_4 , V_6 -> V_4 ) )
return V_6 -> V_7 ;
}
return ++ V_2 -> V_7 ;
}
int F_4 ( struct V_5 * V_6 )
{
struct V_8 V_9 = {
. V_10 = V_6 -> V_4 ,
. V_11 = V_12 ,
} ;
int V_13 ;
F_5 () ;
V_13 = F_6 ( V_6 -> V_4 , & V_9 ) ;
if ( V_13 ) {
if ( V_13 == - V_14 )
return 0 ;
return V_13 ;
}
V_6 -> V_7 = F_1 ( V_6 -> V_2 , V_6 -> V_4 ) ;
return 0 ;
}
void F_7 ( const struct V_5 * V_6 ,
struct V_15 * V_16 )
{
if ( V_16 -> V_7 && ! F_8 ( ! V_6 -> V_7 ) )
F_9 ( V_16 ) -> V_7 = V_6 -> V_7 ;
}
bool F_10 ( const struct V_5 * V_6 ,
const struct V_15 * V_16 )
{
return ! V_16 -> V_7 ||
F_9 ( V_16 ) -> V_7 != V_6 -> V_7 ;
}
int F_11 ( struct V_5 * V_6 ,
unsigned long V_17 ,
unsigned long V_18 )
{
struct V_8 V_9 = {
. V_10 = V_6 -> V_4 ,
. V_11 = V_19 ,
} ;
int V_13 ;
if ( V_18 & ~ V_20 )
return 0 ;
V_13 = F_6 ( V_6 -> V_4 , & V_9 ) ;
if ( V_13 == - V_14 )
return 0 ;
if ( V_13 )
return V_13 ;
if ( ! ( V_9 . V_21 . V_22 & V_18 ) ) {
F_12 ( V_6 -> V_2 , L_1 ,
( unsigned int ) V_6 -> V_23 , V_6 -> V_4 -> V_24 ) ;
return - V_14 ;
}
V_9 . V_11 = V_25 ;
V_9 . V_17 = V_26 ;
V_9 . V_21 . V_27 = V_17 ;
V_13 = F_13 ( V_6 -> V_4 , & V_9 ) ;
if ( V_13 ) {
F_12 ( V_6 -> V_2 , L_2 ,
( unsigned int ) V_6 -> V_23 , V_6 -> V_4 -> V_24 ) ;
return V_13 ;
}
return 0 ;
}
static void
F_14 ( bool V_28 , const unsigned char * V_29 ,
T_1 V_30 , struct V_3 * V_4 )
{
struct V_31 V_32 ;
unsigned long V_33 ;
V_32 . V_34 = V_29 ;
V_32 . V_30 = V_30 ;
V_33 = V_28 ? V_35 : V_36 ;
F_15 ( V_33 , V_4 , & V_32 . V_32 ) ;
}
void
F_16 ( const struct V_37 * V_38 , int type )
{
if ( ! V_38 -> V_39 || ! V_38 -> V_40 )
return;
switch ( type ) {
case V_41 :
F_14 ( false , V_38 -> V_34 . V_34 ,
V_38 -> V_42 ,
V_38 -> V_40 -> V_4 ) ;
break;
case V_43 :
F_14 ( true , V_38 -> V_34 . V_34 ,
V_38 -> V_42 ,
V_38 -> V_40 -> V_4 ) ;
break;
}
}
