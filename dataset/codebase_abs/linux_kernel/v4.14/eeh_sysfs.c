static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_10 ;
if ( ! V_9 || ! V_9 -> V_11 )
return - V_12 ;
V_10 = V_13 -> V_14 ( V_9 -> V_11 , NULL ) ;
return sprintf ( V_5 , L_1 ,
V_10 , V_9 -> V_11 -> V_10 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( ! V_9 || ! V_9 -> V_11 )
return - V_12 ;
if ( ! ( V_9 -> V_11 -> V_10 & V_16 ) )
return V_15 ;
if ( F_5 ( V_9 -> V_11 , true ) )
return - V_17 ;
return V_15 ;
}
void F_6 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_18 = 0 ;
if ( ! F_7 () )
return;
if ( V_9 && ( V_9 -> V_19 & V_20 ) )
return;
V_18 += F_8 ( & V_7 -> V_2 , & V_21 ) ;
V_18 += F_8 ( & V_7 -> V_2 , & V_22 ) ;
V_18 += F_8 ( & V_7 -> V_2 , & V_23 ) ;
if ( V_18 )
F_9 ( L_2 ) ;
else if ( V_9 )
V_9 -> V_19 |= V_20 ;
}
void F_10 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( ! V_7 -> V_2 . V_24 . V_25 ) {
if ( V_9 )
V_9 -> V_19 &= ~ V_20 ;
return;
}
F_11 ( & V_7 -> V_2 , & V_21 ) ;
F_11 ( & V_7 -> V_2 , & V_22 ) ;
F_11 ( & V_7 -> V_2 , & V_23 ) ;
if ( V_9 )
V_9 -> V_19 &= ~ V_20 ;
}
