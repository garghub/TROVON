static void F_1 ( struct V_1 * V_2 , T_1 * V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( V_4 > 0x800 ) {
F_3 ( V_3 , V_6 -> V_7 , 0x800 ) ;
V_3 += 0x800 ;
V_4 -= 0x800 ;
}
F_3 ( V_3 , V_6 -> V_7 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 , const T_1 * V_3 , int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
while ( V_4 > 0x800 ) {
F_5 ( V_6 -> V_7 , V_3 , 0x800 ) ;
V_3 += 0x800 ;
V_4 -= 0x800 ;
}
F_5 ( V_6 -> V_7 , V_3 , V_4 ) ;
}
static void F_6 ( struct V_1 * V_2 , int V_8 ,
unsigned int V_9 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( V_8 == V_10 )
return;
if ( V_9 & V_11 )
F_7 ( V_6 -> V_12 + ( 1 << V_13 ) , V_8 ) ;
else
F_7 ( V_6 -> V_12 + ( 1 << V_14 ) , V_8 ) ;
F_8 () ;
F_9 ( V_15 ) ;
}
int F_10 ( struct V_1 * V_2 )
{
return ! ! ( F_9 ( V_15 ) & V_16 ) ;
}
static int F_11 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_20 ;
struct V_21 * V_22 ;
struct V_23 * V_24 = V_20 -> V_25 ;
struct V_26 V_27 ;
struct V_5 * V_6 ;
int V_28 = 0 ;
V_28 = F_12 ( V_24 , 0 , & V_27 ) ;
if ( V_28 )
return - V_29 ;
if ( V_30 )
return - V_31 ;
F_13 ( V_20 , L_1 , & V_27 ) ;
V_6 = F_14 ( sizeof( struct V_5 ) , V_32 ) ;
if ( ! V_6 ) {
V_28 = - V_33 ;
goto V_34;
}
V_30 = F_15 ( V_6 ) ;
V_30 -> V_20 . V_35 = V_20 ;
V_6 -> V_7 = F_16 ( V_24 , 0 ) ;
V_6 -> V_12 = V_6 -> V_7 ;
if ( ! V_6 -> V_7 ) {
V_28 = - V_36 ;
goto V_37;
}
V_22 = F_17 ( V_38 , 0xa008 , NULL ) ;
if ( ! V_22 ) {
V_28 = - V_31 ;
goto V_39;
}
V_15 = F_18 ( V_22 , 0 ) ;
F_19 ( V_22 ) ;
if ( ! F_20 ( V_15 , 4 , V_40 ) ) {
V_28 = - V_41 ;
goto V_39;
}
V_6 -> V_42 = F_6 ;
V_6 -> V_43 = F_10 ;
V_6 -> V_44 = F_1 ;
V_6 -> V_45 = F_4 ;
V_6 -> V_46 = 0 ;
V_6 -> V_47 . V_48 = V_49 ;
V_6 -> V_47 . V_50 = V_51 ;
V_6 -> V_52 = V_53 ;
V_28 = F_21 ( V_30 , 1 ) ;
if ( V_28 )
goto V_54;
if ( F_22 ( V_30 , NULL , 0 ) ) {
F_23 ( V_20 , L_2 ) ;
V_28 = - V_31 ;
goto V_54;
}
F_24 ( V_20 , L_3 , & V_27 ,
V_15 ) ;
return 0 ;
V_54:
F_25 ( V_15 , 4 ) ;
V_39:
F_26 ( V_6 -> V_7 ) ;
V_37:
F_27 ( V_6 ) ;
V_34:
return V_28 ;
}
static int F_28 ( struct V_17 * V_18 )
{
struct V_5 * V_6 ;
if ( ! V_30 )
return 0 ;
V_6 = F_2 ( V_30 ) ;
F_29 ( V_30 ) ;
F_25 ( V_15 , 4 ) ;
F_26 ( V_6 -> V_7 ) ;
F_27 ( V_6 ) ;
V_30 = NULL ;
return 0 ;
}
