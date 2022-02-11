static int F_1 ( void * V_1 )
{
int V_2 ;
struct V_3 * V_3 = V_4 ;
while ( ! F_2 () ) {
V_2 = F_3 ( V_3 -> V_5 , V_6 ) ;
if ( V_2 < 0 )
F_4 ( L_1 ) ;
V_3 -> V_7 = V_2 ;
if ( V_3 -> V_7 & V_8 ) {
F_5 ( V_3 -> V_5 , V_6 ,
V_3 -> V_7 & ~ V_8 ) ;
F_6 () ;
}
F_7 ( V_9 ) ;
F_8 ( V_10 ) ;
}
return 0 ;
}
static T_1 F_9 ( struct V_11 * V_12 ,
struct V_13 * V_14 , char * V_15 )
{
int V_2 ;
struct V_3 * V_3 = V_4 ;
V_2 = F_3 ( V_3 -> V_5 , V_6 ) ;
if ( V_2 < 0 )
return - V_16 ;
V_3 -> V_7 = V_2 ;
return sprintf ( V_15 , L_2 , V_2 ) ;
}
static void F_10 ( void )
{
struct V_3 * V_3 = V_4 ;
F_11 ( L_3 ) ;
F_12 ( & V_3 -> V_17 ) ;
F_5 ( V_3 -> V_5 , V_6 ,
V_3 -> V_7 | V_18 ) ;
F_13 ( & V_3 -> V_17 ) ;
}
static void F_14 ( struct V_19 * V_20 , unsigned int V_21 , int V_22 )
{
struct V_3 * V_3 = F_15 ( V_20 , struct V_3 , V_20 ) ;
T_2 V_23 = 1 << ( 4 + V_21 ) ;
F_12 ( & V_3 -> V_17 ) ;
if ( V_22 )
V_3 -> V_7 &= ~ V_23 ;
else
V_3 -> V_7 |= V_23 ;
F_5 ( V_3 -> V_5 , V_6 , V_3 -> V_7 ) ;
F_13 ( & V_3 -> V_17 ) ;
}
static int F_16 ( struct V_19 * V_20 , unsigned int V_21 , int V_22 )
{
F_14 ( V_20 , V_21 , V_22 ) ;
return 0 ;
}
static int F_17 ( struct V_3 * V_3 )
{
struct V_24 * V_25 ;
struct V_19 * V_20 = & V_3 -> V_20 ;
V_25 = F_18 ( NULL , NULL , L_4 ) ;
if ( ! V_25 )
return - V_16 ;
V_20 -> V_26 = V_27 ;
V_20 -> V_28 = V_25 -> V_29 ;
V_20 -> V_30 = 1 ;
V_20 -> V_31 = V_32 ;
V_20 -> V_33 = - 1 ;
V_20 -> V_34 = F_14 ;
V_20 -> V_35 = F_16 ;
V_20 -> V_36 = V_25 ;
return F_19 ( V_20 ) ;
}
static int F_20 ( struct V_3 * V_3 )
{
return F_21 ( & V_3 -> V_20 ) ;
}
static int F_22 ( struct V_37 * V_5 , const struct V_38 * V_39 )
{
struct V_3 * V_3 ;
int V_2 ;
V_3 = F_23 ( sizeof( * V_3 ) , V_40 ) ;
if ( ! V_3 )
return - V_41 ;
F_24 ( & V_3 -> V_17 ) ;
V_3 -> V_5 = V_5 ;
F_25 ( V_5 , V_3 ) ;
V_2 = F_3 ( V_3 -> V_5 , V_6 ) ;
if ( V_2 < 0 )
goto V_42;
V_3 -> V_7 = V_2 ;
V_2 = F_17 ( V_3 ) ;
if ( V_2 )
goto V_42;
if ( ! V_43 . V_44 ) {
V_4 = V_3 ;
V_43 . V_44 = F_10 ;
F_26 ( & V_5 -> V_45 , L_5 ) ;
}
if ( F_27 ( & V_5 -> V_45 , & V_46 ) )
F_28 ( & V_5 -> V_45 ,
L_6 ) ;
V_47 = F_29 ( F_1 , NULL ,
L_7 ) ;
return 0 ;
V_42:
F_30 ( V_3 ) ;
return V_2 ;
}
static int F_31 ( struct V_37 * V_5 )
{
struct V_3 * V_3 = F_32 ( V_5 ) ;
int V_2 ;
F_33 ( V_47 ) ;
F_34 ( & V_5 -> V_45 , & V_46 ) ;
if ( V_4 == V_3 ) {
V_43 . V_44 = NULL ;
V_4 = NULL ;
}
V_2 = F_20 ( V_3 ) ;
if ( V_2 )
return V_2 ;
F_30 ( V_3 ) ;
return 0 ;
}
