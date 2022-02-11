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
static int T_2 F_16 ( struct V_40 * V_2 )
{
struct V_5 * V_6 ;
int V_41 ;
int V_42 ;
if ( V_2 -> V_43 != V_44 )
return - V_45 ;
if ( ! F_17 ( & V_2 -> V_2 , V_2 -> V_46 . V_19 ,
V_47 , L_4 ) )
return - V_25 ;
V_6 = F_18 ( & V_2 -> V_2 , sizeof( struct V_5 ) ,
V_48 ) ;
if ( ! V_6 )
return - V_27 ;
V_6 -> V_8 = F_19 ( & V_2 -> V_2 , V_2 -> V_46 . V_19 , V_47 ) ;
if ( ! V_6 -> V_8 )
return - V_27 ;
F_20 ( V_6 -> V_8 , V_2 -> V_43 ) ;
if ( ! F_17 ( & V_2 -> V_2 ,
V_2 -> V_46 . V_19 + 0x03000000 ,
V_47 , L_5 ) )
return - V_25 ;
V_6 -> V_49 = F_19 ( & V_2 -> V_2 ,
V_2 -> V_46 . V_19 + 0x03000000 ,
V_47 ) ;
if ( ! V_6 -> V_49 )
return - V_27 ;
V_41 = F_21 ( V_6 -> V_49 , V_2 -> V_50 ,
V_51 , 0 ) ;
F_22 ( V_2 , V_6 ) ;
F_23 ( & V_2 -> V_2 , L_6 ,
( unsigned long ) V_2 -> V_46 . V_19 ) ;
for ( V_42 = 0 ; V_42 < F_24 ( V_52 ) ; V_42 ++ ) {
struct V_53 * V_54 = V_52 + V_42 ;
struct V_55 * V_56 ;
unsigned long V_57 ;
char V_58 [ 32 ] ;
int V_59 = V_54 -> V_50 [ 0 ] ;
int V_60 = V_54 -> V_50 [ 1 ] ;
if ( V_59 )
V_59 += V_41 ;
if ( V_60 )
V_60 += V_41 ;
V_57 = V_2 -> V_46 . V_19 + V_54 -> V_61 ;
snprintf ( V_58 , 32 , L_7 , V_2 -> V_43 , V_54 -> V_61 >> 12 ) ;
if ( V_54 -> V_61 == 0x00400000 ) {
struct V_62 * V_63 ;
char * V_64 ;
char * V_65 ;
V_63 = F_18 ( & V_2 -> V_2 ,
sizeof( * V_63 ) + 3 * sizeof( struct V_66 ) ,
V_48 ) ;
V_64 = F_25 ( & V_2 -> V_2 , V_58 , V_48 ) ;
V_65 = F_26 ( V_48 , L_8 , V_2 -> V_43 ) ;
V_63 -> V_67 = V_65 ;
V_63 -> V_68 [ 0 ] . V_69 = V_64 ;
V_63 -> V_68 [ 0 ] . V_70 = 3 ;
V_63 -> V_68 [ 0 ] . V_71 = L_9 ;
V_63 -> V_68 [ 1 ] . V_69 = V_64 ;
V_63 -> V_68 [ 1 ] . V_70 = 4 ;
V_63 -> V_68 [ 1 ] . V_71 = L_10 ;
V_63 -> V_68 [ 1 ] . V_72 = V_73 ;
F_27 ( V_63 ) ;
}
V_56 = F_28 ( & V_2 -> V_2 , V_58 , V_57 , V_47 ,
V_59 , V_60 ,
V_54 -> V_74 , V_54 -> V_43 ,
& V_2 -> V_46 ) ;
if ( F_29 ( V_56 ) ) {
F_30 ( & V_2 -> V_2 , L_11 , F_31 ( V_56 ) ) ;
continue;
}
}
return 0 ;
}
static int F_32 ( struct V_1 * V_2 , void * V_75 )
{
F_33 ( V_2 ) ;
return 0 ;
}
static void F_34 ( struct V_40 * V_2 )
{
F_35 ( & V_2 -> V_2 , NULL , F_32 ) ;
F_36 ( V_2 -> V_43 ) ;
F_22 ( V_2 , NULL ) ;
}
static int T_3 F_37 ( void )
{
return F_38 ( & V_76 ) ;
}
static void T_4 F_39 ( void )
{
F_40 ( & V_76 ) ;
}
