static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 [] , struct V_5 * V_7 [] )
{
struct V_3 * V_8 [ 2 ] ;
unsigned char V_9 ;
if ( ! V_7 [ V_10 ] ) {
F_2 ( V_4 , L_1 ) ;
return - V_11 ;
}
V_8 [ 0 ] = F_3 ( V_2 , F_4 ( V_7 [ V_10 ] ) ) ;
if ( ! V_7 [ V_12 ] ) {
F_2 ( V_4 , L_2 ) ;
return - V_11 ;
}
V_8 [ 1 ] = F_3 ( V_2 , F_4 ( V_7 [ V_12 ] ) ) ;
if ( ! V_8 [ 0 ] || ! V_8 [ 1 ] )
return - V_13 ;
if ( V_8 [ 0 ] == V_8 [ 1 ] )
return - V_11 ;
if ( ! V_7 [ V_14 ] )
V_9 = 0 ;
else
V_9 = F_5 ( V_7 [ V_14 ] ) ;
return F_6 ( V_4 , V_8 , V_9 ) ;
}
static int F_7 ( struct V_15 * V_16 , const struct V_3 * V_4 )
{
struct V_17 * V_17 ;
V_17 = F_8 ( V_4 ) ;
if ( V_17 -> V_18 [ 0 ] )
if ( F_9 ( V_16 , V_10 , V_17 -> V_18 [ 0 ] -> V_19 ) )
goto V_20;
if ( V_17 -> V_18 [ 1 ] )
if ( F_9 ( V_16 , V_12 , V_17 -> V_18 [ 1 ] -> V_19 ) )
goto V_20;
if ( F_10 ( V_16 , V_21 , V_22 ,
V_17 -> V_23 ) ||
F_11 ( V_16 , V_24 , V_17 -> V_25 ) )
goto V_20;
return 0 ;
V_20:
return - V_26 ;
}
void F_12 ( struct V_17 * V_17 , unsigned char V_27 [ V_22 ] ,
enum V_28 V_29 )
{
struct V_15 * V_16 ;
void * V_30 ;
int V_31 ;
int V_19 ;
V_16 = F_13 ( V_32 , V_33 ) ;
if ( ! V_16 )
goto V_34;
V_30 = F_14 ( V_16 , 0 , 0 , & V_35 , 0 , V_36 ) ;
if ( ! V_30 )
goto V_20;
V_31 = F_10 ( V_16 , V_37 , V_22 , V_27 ) ;
if ( V_31 < 0 )
goto V_20;
if ( V_17 -> V_18 [ V_29 ] )
V_19 = V_17 -> V_18 [ V_29 ] -> V_19 ;
else
V_19 = - 1 ;
V_31 = F_9 ( V_16 , V_38 , V_19 ) ;
if ( V_31 < 0 )
goto V_20;
F_15 ( V_16 , V_30 ) ;
F_16 ( & V_35 , V_16 , 0 , 0 , V_33 ) ;
return;
V_20:
F_17 ( V_16 ) ;
V_34:
F_18 ( V_17 -> V_4 , L_3 ) ;
}
void F_19 ( struct V_17 * V_17 , unsigned char V_27 [ V_22 ] )
{
struct V_15 * V_16 ;
void * V_30 ;
int V_31 ;
V_16 = F_13 ( V_32 , V_33 ) ;
if ( ! V_16 )
goto V_34;
V_30 = F_14 ( V_16 , 0 , 0 , & V_35 , 0 , V_39 ) ;
if ( ! V_30 )
goto V_20;
V_31 = F_10 ( V_16 , V_37 , V_22 , V_27 ) ;
if ( V_31 < 0 )
goto V_20;
F_15 ( V_16 , V_30 ) ;
F_16 ( & V_35 , V_16 , 0 , 0 , V_33 ) ;
return;
V_20:
F_17 ( V_16 ) ;
V_34:
F_18 ( V_17 -> V_4 , L_4 ) ;
}
static int F_20 ( struct V_15 * V_40 , struct V_41 * V_42 )
{
struct V_5 * V_43 ;
struct V_3 * V_44 ;
struct V_15 * V_45 ;
void * V_30 ;
struct V_17 * V_17 ;
unsigned char V_46 [ V_22 ] ;
int V_47 ;
T_1 V_48 ;
int V_49 ;
T_1 V_50 ;
int V_51 ;
int V_31 ;
if ( ! V_42 )
goto V_52;
V_43 = V_42 -> V_53 [ V_38 ] ;
if ( ! V_43 )
goto V_52;
V_43 = V_42 -> V_53 [ V_37 ] ;
if ( ! V_43 )
goto V_52;
V_44 = F_3 ( F_21 ( V_42 ) ,
F_4 ( V_42 -> V_53 [ V_38 ] ) ) ;
if ( ! V_44 )
goto V_52;
if ( ! F_22 ( V_44 ) )
goto V_52;
V_45 = F_13 ( V_32 , V_54 ) ;
if ( ! V_45 ) {
V_31 = - V_55 ;
goto V_34;
}
V_30 = F_14 ( V_45 , F_23 ( V_40 ) . V_56 ,
V_42 -> V_57 , & V_35 , 0 ,
V_58 ) ;
if ( ! V_30 ) {
V_31 = - V_55 ;
goto V_20;
}
V_31 = F_9 ( V_45 , V_38 , V_44 -> V_19 ) ;
if ( V_31 < 0 )
goto V_20;
V_17 = F_8 ( V_44 ) ;
V_31 = F_24 ( V_17 ,
( unsigned char * ) F_25 ( V_42 -> V_53 [ V_37 ] ) ,
V_46 ,
& V_51 ,
& V_47 ,
& V_48 ,
& V_49 ,
& V_50 ) ;
if ( V_31 < 0 )
goto V_20;
V_31 = F_10 ( V_45 , V_37 , V_22 ,
F_25 ( V_42 -> V_53 [ V_37 ] ) ) ;
if ( V_31 < 0 )
goto V_20;
if ( V_51 > - 1 ) {
V_31 = F_10 ( V_45 , V_59 , V_22 ,
V_46 ) ;
if ( V_31 < 0 )
goto V_20;
V_31 = F_9 ( V_45 , V_60 , V_51 ) ;
if ( V_31 < 0 )
goto V_20;
}
V_31 = F_9 ( V_45 , V_61 , V_47 ) ;
if ( V_31 < 0 )
goto V_20;
V_31 = F_11 ( V_45 , V_62 , V_48 ) ;
if ( V_31 < 0 )
goto V_20;
if ( V_17 -> V_18 [ 0 ] )
V_31 = F_9 ( V_45 , V_63 ,
V_17 -> V_18 [ 0 ] -> V_19 ) ;
if ( V_31 < 0 )
goto V_20;
V_31 = F_9 ( V_45 , V_64 , V_49 ) ;
if ( V_31 < 0 )
goto V_20;
V_31 = F_11 ( V_45 , V_65 , V_50 ) ;
if ( V_31 < 0 )
goto V_20;
if ( V_17 -> V_18 [ 1 ] )
V_31 = F_9 ( V_45 , V_66 ,
V_17 -> V_18 [ 1 ] -> V_19 ) ;
F_15 ( V_45 , V_30 ) ;
F_26 ( F_21 ( V_42 ) , V_45 , V_42 -> V_67 ) ;
return 0 ;
V_52:
F_27 ( V_40 , F_28 ( V_40 ) , - V_11 ) ;
return 0 ;
V_20:
F_17 ( V_45 ) ;
V_34:
return V_31 ;
}
static int F_29 ( struct V_15 * V_40 , struct V_41 * V_42 )
{
struct V_5 * V_43 ;
struct V_3 * V_44 ;
struct V_15 * V_45 ;
void * V_30 ;
struct V_17 * V_17 ;
void * V_68 ;
unsigned char V_27 [ V_22 ] ;
int V_31 ;
if ( ! V_42 )
goto V_52;
V_43 = V_42 -> V_53 [ V_38 ] ;
if ( ! V_43 )
goto V_52;
V_44 = F_3 ( F_21 ( V_42 ) ,
F_4 ( V_42 -> V_53 [ V_38 ] ) ) ;
if ( ! V_44 )
goto V_52;
if ( ! F_22 ( V_44 ) )
goto V_52;
V_45 = F_13 ( V_32 , V_54 ) ;
if ( ! V_45 ) {
V_31 = - V_55 ;
goto V_34;
}
V_30 = F_14 ( V_45 , F_23 ( V_40 ) . V_56 ,
V_42 -> V_57 , & V_35 , 0 ,
V_69 ) ;
if ( ! V_30 ) {
V_31 = - V_55 ;
goto V_20;
}
V_31 = F_9 ( V_45 , V_38 , V_44 -> V_19 ) ;
if ( V_31 < 0 )
goto V_20;
V_17 = F_8 ( V_44 ) ;
F_30 () ;
V_68 = F_31 ( V_17 , NULL , V_27 ) ;
while ( V_68 ) {
V_31 = F_10 ( V_45 , V_37 , V_22 , V_27 ) ;
if ( V_31 < 0 ) {
F_32 () ;
goto V_20;
}
V_68 = F_31 ( V_17 , V_68 , V_27 ) ;
}
F_32 () ;
F_15 ( V_45 , V_30 ) ;
F_26 ( F_21 ( V_42 ) , V_45 , V_42 -> V_67 ) ;
return 0 ;
V_52:
F_27 ( V_40 , F_28 ( V_40 ) , - V_11 ) ;
return 0 ;
V_20:
F_17 ( V_45 ) ;
V_34:
return V_31 ;
}
int T_2 F_33 ( void )
{
int V_70 ;
V_70 = F_34 ( & V_71 ) ;
if ( V_70 )
goto V_72;
V_70 = F_35 ( & V_35 , V_73 ,
V_74 ) ;
if ( V_70 )
goto V_75;
return 0 ;
V_75:
F_36 ( & V_71 ) ;
V_72:
return V_70 ;
}
void T_3 F_37 ( void )
{
F_38 ( & V_35 ) ;
F_36 ( & V_71 ) ;
}
