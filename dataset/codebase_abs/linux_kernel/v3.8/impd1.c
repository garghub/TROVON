void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
V_4 &= V_3 ;
V_7 = F_3 ( V_6 -> V_8 + V_9 ) & ~ V_3 ;
F_4 ( V_7 | V_4 , V_6 -> V_8 + V_9 ) ;
}
static void F_5 ( struct V_10 * V_11 )
{
F_1 ( V_11 -> V_2 -> V_2 . V_12 , V_13 , 0 ) ;
}
static void F_6 ( struct V_10 * V_11 )
{
F_1 ( V_11 -> V_2 -> V_2 . V_12 , V_13 ,
V_11 -> V_14 -> V_15 | V_16 ) ;
}
static int F_7 ( struct V_10 * V_11 )
{
unsigned long V_17 = V_11 -> V_2 -> V_18 . V_19 + 0x01000000 ;
unsigned long V_20 = V_21 ;
int V_22 = 0 ;
V_11 -> V_14 = & V_23 ;
if ( ! F_8 ( V_17 , V_20 , L_1 ) ) {
F_9 ( V_24 L_2 ) ;
return - V_25 ;
}
V_11 -> V_11 . V_26 = F_10 ( V_17 , V_20 ) ;
if ( ! V_11 -> V_11 . V_26 ) {
F_9 ( V_24 L_3 ) ;
V_22 = - V_27 ;
goto V_28;
}
V_11 -> V_11 . V_29 . V_30 = V_17 ;
V_11 -> V_11 . V_29 . V_31 = V_20 ;
return 0 ;
V_28:
F_11 ( V_17 , V_20 ) ;
return V_22 ;
}
static int F_12 ( struct V_10 * V_11 , struct V_32 * V_33 )
{
unsigned long V_19 , V_34 ;
V_19 = V_33 -> V_35 + ( V_11 -> V_11 . V_29 . V_30 >> V_36 ) ;
V_34 = V_33 -> V_37 - V_33 -> V_38 ;
return F_13 ( V_33 , V_33 -> V_38 , V_19 , V_34 ,
V_33 -> V_39 ) ;
}
static void F_14 ( struct V_10 * V_11 )
{
F_15 ( V_11 -> V_11 . V_26 ) ;
F_11 ( V_11 -> V_11 . V_29 . V_30 , V_11 -> V_11 . V_29 . V_31 ) ;
}
static int F_16 ( struct V_40 * V_2 )
{
struct V_5 * V_6 ;
int V_41 , V_22 ;
if ( V_2 -> V_42 != V_43 )
return - V_44 ;
if ( ! F_8 ( V_2 -> V_45 . V_19 , V_46 , L_4 ) )
return - V_25 ;
V_6 = F_17 ( sizeof( struct V_5 ) , V_47 ) ;
if ( ! V_6 ) {
V_22 = - V_27 ;
goto V_48;
}
V_6 -> V_8 = F_10 ( V_2 -> V_45 . V_19 , V_46 ) ;
if ( ! V_6 -> V_8 ) {
V_22 = - V_27 ;
goto V_49;
}
F_18 ( V_2 , V_6 ) ;
F_9 ( L_5 ,
( unsigned long ) V_2 -> V_45 . V_19 ) ;
F_19 ( V_6 -> V_8 , V_2 -> V_42 ) ;
for ( V_41 = 0 ; V_41 < F_20 ( V_50 ) ; V_41 ++ ) {
struct V_51 * V_52 = V_50 + V_41 ;
struct V_53 * V_54 ;
unsigned long V_55 ;
char V_56 [ 32 ] ;
V_55 = V_2 -> V_45 . V_19 + V_52 -> V_57 ;
snprintf ( V_56 , 32 , L_6 , V_2 -> V_42 , V_52 -> V_57 >> 12 ) ;
V_54 = F_21 ( & V_2 -> V_2 , V_56 , V_55 , V_46 ,
V_2 -> V_58 , V_2 -> V_58 ,
V_52 -> V_59 , V_52 -> V_42 ,
& V_2 -> V_45 ) ;
if ( F_22 ( V_54 ) ) {
F_23 ( & V_2 -> V_2 , L_7 , F_24 ( V_54 ) ) ;
continue;
}
}
return 0 ;
V_49:
if ( V_6 && V_6 -> V_8 )
F_15 ( V_6 -> V_8 ) ;
F_25 ( V_6 ) ;
V_48:
F_11 ( V_2 -> V_45 . V_19 , V_46 ) ;
return V_22 ;
}
static int F_26 ( struct V_1 * V_2 , void * V_60 )
{
F_27 ( V_2 ) ;
return 0 ;
}
static void F_28 ( struct V_40 * V_2 )
{
struct V_5 * V_6 = F_29 ( V_2 ) ;
F_30 ( & V_2 -> V_2 , NULL , F_26 ) ;
F_31 ( V_2 -> V_42 ) ;
F_18 ( V_2 , NULL ) ;
F_15 ( V_6 -> V_8 ) ;
F_25 ( V_6 ) ;
F_11 ( V_2 -> V_45 . V_19 , V_46 ) ;
}
static int T_2 F_32 ( void )
{
return F_33 ( & V_61 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_61 ) ;
}
