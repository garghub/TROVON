static int F_1 ( struct V_1 * V_2 )
{
static const int V_3 [] = {
800 , 1000 , 2000 , 900 , 1200 , 2400 , 0 , 0 } ;
static const int V_4 [] = {
400 , 500 , 1000 , 450 , 550 , 1200 , 0 , 0 } ;
struct V_5 * V_6 = F_2 ( & V_2 -> V_7 ) ;
struct V_8 * V_9 ;
int V_10 = 0 ;
V_9 = F_3 () ;
if ( ! V_9 )
return - V_11 ;
V_9 -> V_12 = V_6 ;
V_6 -> V_13 = V_9 ;
if ( V_6 -> V_2 . V_14 == V_15 ) {
V_9 -> V_16 = V_17 ;
V_9 -> V_18 = V_19 ;
memcpy ( V_9 -> V_20 , V_3 ,
sizeof( V_3 ) ) ;
V_9 -> V_21 = V_19 ;
V_9 -> V_22 = L_1 ;
V_9 -> V_23 = V_24 ;
} else if ( V_6 -> V_2 . V_14 == V_25 ) {
V_9 -> V_16 = V_17 ;
V_9 -> V_18 = V_19 ;
V_9 -> V_21 = V_19 ;
if ( F_4 ( & V_6 -> V_26 , V_27 ) &&
F_4 ( & V_6 -> V_26 , V_28 ) ) {
V_9 -> V_18 = V_29 ;
V_9 -> V_21 = V_29 ;
}
memcpy ( V_9 -> V_20 , V_4 ,
sizeof( V_4 ) ) ;
V_9 -> V_22 = L_2 ;
V_9 -> V_23 = V_30 ;
} else {
F_5 ( V_9 ) ;
return - V_31 ;
}
V_9 -> V_32 = 1 ;
V_10 = F_6 ( V_9 ) ;
if ( V_10 ) {
V_6 -> V_13 = NULL ;
F_5 ( V_9 ) ;
}
return V_10 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_2 ( & V_2 -> V_7 ) -> V_13 ;
if ( V_9 )
F_8 ( V_9 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_10 ( & V_2 -> V_7 ) ;
struct V_35 * V_36 = NULL ;
int V_10 ;
switch ( V_2 -> V_14 ) {
case V_15 :
V_36 = F_11 ( V_37 ) ;
if ( ! V_36 )
return - V_11 ;
break;
case V_25 :
V_36 = F_11 ( V_38 ) ;
if ( ! V_36 )
return - V_11 ;
break;
}
if ( ! V_36 )
return - V_31 ;
V_36 -> V_39 = F_12 ( V_40 , V_41 ) ;
V_36 -> V_42 = V_34 ;
V_36 -> V_32 = 1 ;
F_13 ( & V_36 -> V_43 , 0 ) ;
F_14 ( V_34 , & V_36 -> V_44 ) ;
V_34 -> V_45 = V_46 ,
V_34 -> V_13 = V_36 ;
V_10 = F_15 ( V_36 ) ;
if ( V_10 ) {
V_34 -> V_13 = NULL ;
F_16 ( V_36 ) ;
}
return V_10 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_33 * V_34 = F_10 ( & V_2 -> V_7 ) ;
struct V_35 * V_36 = V_34 -> V_13 ;
F_18 ( V_34 ) ;
if ( V_36 )
F_19 ( V_36 ) ;
}
int T_1 F_20 ( void )
{
int V_10 ;
V_10 = F_21 ( & V_47 ,
V_48 , L_3 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_21 ( & V_49 ,
V_48 , L_4 ) ;
if ( V_10 )
F_22 ( & V_47 ) ;
return V_10 ;
}
void T_2 F_23 ( void )
{
F_22 ( & V_49 ) ;
F_22 ( & V_47 ) ;
}
