void T_1 F_1 ( int V_1 , int V_2 , int V_3 ,
int V_4 )
{
V_5 . V_6 = V_1 ;
V_5 . V_7 = V_2 ;
V_5 . V_8 = V_3 ;
V_5 . V_9 = V_4 ;
F_2 ( & V_5 ) ;
}
void T_1 F_3 ( unsigned long V_10 )
{
static const unsigned long V_11 [] = {
0xe3a00101 ,
0xe380060f ,
0xe590f008 ,
} ;
memcpy ( F_4 ( V_10 ) , V_11 , sizeof( V_11 ) ) ;
}
static void F_5 ( int V_12 , struct V_13 * V_14 )
{
F_6 ( V_15 , V_12 ) ;
}
void T_1 F_7 ( int V_3 , struct V_16 * V_17 )
{
V_18 . V_19 = V_17 ;
if ( F_8 ( V_3 ) ) {
if ( ! F_9 ( V_3 , L_1 ) ) {
F_10 ( L_2 ) ;
return;
}
if ( ! F_11 ( V_3 , 1 ) ) {
F_10 ( L_3 ) ;
return;
}
V_15 = V_3 ;
V_18 . V_20 = F_5 ;
}
F_12 ( NULL , & V_18 ) ;
}
void T_1 F_13 ( int V_21 , int V_22 , int V_23 )
{
V_24 . V_25 = V_21 ;
V_24 . V_26 = V_22 ;
V_24 . V_27 = V_23 ;
if ( ! F_9 ( V_22 , L_4 ) ) {
F_11 ( V_22 ,
V_24 . V_27 ) ;
F_14 ( V_22 ) ;
} else
return;
F_15 ( & V_28 ) ;
}
void T_1 F_16 ( int V_29 )
{
V_30 . V_31 = V_29 ;
F_17 ( & V_30 ) ;
}
void T_1 F_18 ( int V_32 , int V_33 , int V_34 , int V_35 )
{
V_36 . V_37 = V_35 ;
V_38 . V_39 = V_34 ;
if ( V_32 < 0 || V_33 < 0 ) {
V_36 . V_40 [ 0 ] = NULL ;
F_19 ( & V_36 ) ;
} else {
V_41 . V_42 = V_32 ,
V_41 . V_43 = V_33 ,
F_19 ( & V_36 ) ;
F_15 ( & V_44 ) ;
}
}
static int F_20 ( struct V_45 * V_46 )
{
int V_47 ;
V_47 = F_9 ( V_48 , L_5 ) ;
if ( V_47 )
goto V_49;
V_47 = F_11 ( V_48 , 0 ) ;
if ( V_47 )
goto V_50;
if ( F_8 ( V_51 ) ) {
V_47 = F_9 ( V_51 , L_6 ) ;
if ( V_47 )
goto V_50;
V_47 = F_11 ( V_51 , 0 ) ;
if ( V_47 )
goto V_52;
}
return 0 ;
V_52:
F_14 ( V_51 ) ;
V_50:
F_14 ( V_48 ) ;
V_49:
return V_47 ;
}
static int F_21 ( struct V_45 * V_46 , int V_53 )
{
F_6 ( V_48 , V_53 ) ;
if ( F_8 ( V_51 ) )
F_6 ( V_51 , V_53 ) ;
return V_53 ;
}
static void F_22 ( struct V_45 * V_46 )
{
F_14 ( V_48 ) ;
if ( F_8 ( V_51 ) )
F_14 ( V_51 ) ;
}
void T_1 F_23 ( int V_54 , int V_55 )
{
V_48 = V_54 ;
V_51 = V_55 ;
F_15 ( & V_56 ) ;
}
static int F_24 ( struct V_45 * V_46 )
{
int V_47 ;
V_47 = F_9 ( V_57 , L_7 ) ;
if ( V_47 )
goto V_58;
V_47 = F_25 ( V_57 ) ;
if ( V_47 )
goto V_50;
if ( F_8 ( V_59 ) ) {
V_47 = F_9 ( V_59 , L_8 ) ;
if ( V_47 )
goto V_50;
V_47 = F_25 ( V_59 ) ;
if ( V_47 )
goto V_52;
}
return 0 ;
V_52:
F_14 ( V_59 ) ;
V_50:
F_14 ( V_57 ) ;
V_58:
return V_47 ;
}
static void F_26 ( struct V_45 * V_46 )
{
F_14 ( V_59 ) ;
F_14 ( V_57 ) ;
}
static int F_27 ( void )
{
return F_28 ( V_57 ) ;
}
static int F_29 ( void )
{
return ! F_28 ( V_59 ) ;
}
void T_1 F_30 ( int V_60 , int V_61 )
{
V_57 = V_60 ;
V_59 = V_61 ;
F_15 ( & V_62 ) ;
}
void T_1 F_31 ( void )
{
F_32 ( 1 , F_33 ( V_63 ) ) ;
F_34 ( & V_64 ) ;
}
