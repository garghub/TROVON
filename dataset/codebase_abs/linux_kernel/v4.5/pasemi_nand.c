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
struct V_19 * V_20 ;
struct V_21 * V_22 = V_18 -> V_23 . V_24 ;
struct V_25 V_26 ;
struct V_5 * V_6 ;
int V_27 = 0 ;
V_27 = F_12 ( V_22 , 0 , & V_26 ) ;
if ( V_27 )
return - V_28 ;
if ( V_29 )
return - V_30 ;
F_13 ( L_1 , & V_26 ) ;
V_6 = F_14 ( sizeof( struct V_5 ) , V_31 ) ;
if ( ! V_6 ) {
F_15 ( V_32
L_2 ) ;
V_27 = - V_33 ;
goto V_34;
}
V_29 = F_16 ( V_6 ) ;
V_29 -> V_23 . V_35 = & V_18 -> V_23 ;
V_6 -> V_7 = F_17 ( V_22 , 0 ) ;
V_6 -> V_12 = V_6 -> V_7 ;
if ( ! V_6 -> V_7 ) {
V_27 = - V_36 ;
goto V_37;
}
V_20 = F_18 ( V_38 , 0xa008 , NULL ) ;
if ( ! V_20 ) {
V_27 = - V_30 ;
goto V_39;
}
V_15 = F_19 ( V_20 , 0 ) ;
F_20 ( V_20 ) ;
if ( ! F_21 ( V_15 , 4 , V_40 ) ) {
V_27 = - V_41 ;
goto V_39;
}
V_6 -> V_42 = F_6 ;
V_6 -> V_43 = F_10 ;
V_6 -> V_44 = F_1 ;
V_6 -> V_45 = F_4 ;
V_6 -> V_46 = 0 ;
V_6 -> V_47 . V_48 = V_49 ;
V_6 -> V_50 = V_51 ;
if ( F_22 ( V_29 , 1 ) ) {
V_27 = - V_52 ;
goto V_53;
}
if ( F_23 ( V_29 , NULL , 0 ) ) {
F_15 ( V_54 L_3 ) ;
V_27 = - V_30 ;
goto V_53;
}
F_15 ( V_55 L_4 ,
V_26 . V_56 , V_15 ) ;
return 0 ;
V_53:
F_24 ( V_15 , 4 ) ;
V_39:
F_25 ( V_6 -> V_7 ) ;
V_37:
F_26 ( V_6 ) ;
V_34:
return V_27 ;
}
static int F_27 ( struct V_17 * V_18 )
{
struct V_5 * V_6 ;
if ( ! V_29 )
return 0 ;
V_6 = F_2 ( V_29 ) ;
F_28 ( V_29 ) ;
F_24 ( V_15 , 4 ) ;
F_25 ( V_6 -> V_7 ) ;
F_26 ( V_6 ) ;
V_29 = NULL ;
return 0 ;
}
