static int T_1 F_1 ( T_2 * V_1 )
{
if ( V_1 -> V_2 & V_3 )
return 1 ;
return 0 ;
}
static T_3 F_2 ( unsigned long V_4 )
{
T_2 * V_1 ;
F_3 (md) {
if ( ! ( V_1 -> V_2 & V_5 ) )
continue;
if ( V_1 -> V_6 == 0 )
break;
if ( V_1 -> V_6 <= V_4 &&
( V_4 - V_1 -> V_6 ) < ( V_1 -> V_7 << V_8 ) )
return V_1 -> V_9 + V_4 - V_1 -> V_6 ;
}
return V_4 ;
}
static void T_1 F_4 ( void )
{
struct V_10 * V_11 ;
if ( V_12 != V_13 ) {
V_11 = F_5 ( V_12 , sizeof( * V_11 ) ) ;
if ( ! V_11 ) {
F_6 ( L_1 ) ;
return;
}
V_10 = * V_11 ;
F_7 ( V_11 , sizeof( * V_11 ) ) ;
V_10 . V_14 = 80 ;
V_10 . V_15 = 25 ;
}
if ( V_10 . V_16 == V_17 &&
F_8 ( V_10 . V_18 ) )
F_9 ( V_10 . V_18 , V_10 . V_19 ) ;
}
static int T_1 F_10 ( void )
{
T_4 * V_20 ;
void * V_21 ;
T_5 V_22 ;
char V_23 [ 100 ] = L_2 ;
int V_24 , V_25 ;
V_26 . V_27 = F_5 ( V_28 ,
sizeof( V_29 ) ) ;
if ( V_26 . V_27 == NULL ) {
F_11 ( L_3 ) ;
return - V_30 ;
}
F_12 ( V_31 , & V_26 . V_32 ) ;
if ( F_13 ( V_33 ) )
F_12 ( V_34 , & V_26 . V_32 ) ;
if ( V_26 . V_27 -> V_35 . V_36 != V_37 ) {
F_6 ( L_4 ) ;
V_25 = - V_38 ;
goto V_39;
}
if ( ( V_26 . V_27 -> V_35 . V_40 >> 16 ) < 2 )
F_11 ( L_5 ,
V_26 . V_27 -> V_35 . V_40 >> 16 ,
V_26 . V_27 -> V_35 . V_40 & 0xffff ) ;
V_26 . V_41 = V_26 . V_27 -> V_35 . V_40 ;
V_20 = F_5 ( F_2 ( V_26 . V_27 -> V_42 ) ,
sizeof( V_23 ) * sizeof( T_4 ) ) ;
if ( V_20 ) {
for ( V_24 = 0 ; V_24 < ( int ) sizeof( V_23 ) - 1 && * V_20 ; ++ V_24 )
V_23 [ V_24 ] = V_20 [ V_24 ] ;
V_23 [ V_24 ] = '\0' ;
F_7 ( V_20 , sizeof( V_23 ) * sizeof( T_4 ) ) ;
}
F_14 ( L_6 ,
V_26 . V_27 -> V_35 . V_40 >> 16 ,
V_26 . V_27 -> V_35 . V_40 & 0xffff , V_23 ) ;
V_22 = sizeof( V_43 ) * V_26 . V_27 -> V_44 ;
V_21 = F_5 ( F_2 ( V_26 . V_27 -> V_45 ) ,
V_22 ) ;
if ( V_21 == NULL ) {
F_11 ( L_7 ) ;
V_25 = - V_30 ;
goto V_39;
}
V_25 = F_15 ( V_21 , V_26 . V_27 -> V_44 ,
sizeof( V_46 ) ,
V_47 ) ;
F_7 ( V_21 , V_22 ) ;
V_39:
F_7 ( V_26 . V_27 , sizeof( V_29 ) ) ;
return V_25 ;
}
static T_1 int F_16 ( T_2 * V_1 )
{
switch ( V_1 -> type ) {
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return 0 ;
default:
break;
}
return F_1 ( V_1 ) ;
}
static T_1 void F_17 ( void )
{
T_2 * V_1 ;
T_6 V_54 , V_55 , V_56 ;
int V_57 ;
if ( F_18 ( V_58 ) )
F_14 ( L_8 ) ;
F_19 () ;
F_20 ( 0 , ( T_3 ) V_59 ) ;
F_3 (md) {
V_54 = V_1 -> V_9 ;
V_55 = V_1 -> V_7 ;
V_57 = F_16 ( V_1 ) ;
if ( F_18 ( V_58 ) ) {
char V_60 [ 64 ] ;
F_14 ( L_9 ,
V_54 , V_54 + ( V_55 << V_8 ) - 1 ,
F_21 ( V_60 , sizeof( V_60 ) , V_1 ) ,
V_57 ? L_10 : L_11 ) ;
}
F_22 ( & V_54 , & V_55 ) ;
V_56 = V_55 << V_61 ;
if ( F_1 ( V_1 ) )
F_23 ( V_54 , V_56 ) ;
if ( V_57 )
F_9 ( V_54 , V_56 ) ;
}
F_12 ( V_62 , & V_26 . V_32 ) ;
}
void T_1 F_24 ( void )
{
struct V_63 V_64 ;
if ( ! F_25 ( & V_64 ) )
return;
V_28 = V_64 . V_65 ;
V_26 . V_66 . V_67 = V_64 . V_68 ;
V_26 . V_66 . V_69 = F_5 ( V_64 . V_68 , V_64 . V_70 ) ;
if ( V_26 . V_66 . V_69 == NULL ) {
F_26 ( L_12 ) ;
}
V_26 . V_66 . V_71 = V_26 . V_66 . V_69 + V_64 . V_70 ;
V_26 . V_66 . V_72 = V_64 . V_72 ;
V_26 . V_66 . V_73 = V_64 . V_74 ;
F_27 ( V_26 . V_66 . V_73 != 1 ,
L_13 ,
V_26 . V_66 . V_73 ) ;
if ( F_10 () < 0 )
return;
F_17 () ;
F_28 () ;
F_7 ( V_26 . V_66 . V_69 , V_64 . V_70 ) ;
F_29 ( V_64 . V_68 & V_75 ,
F_30 ( V_64 . V_70 +
( V_64 . V_68 & ~ V_75 ) ) ) ;
F_4 () ;
}
static int T_1 F_31 ( void )
{
void * V_76 ;
if ( V_10 . V_16 != V_17 )
return 0 ;
V_76 = F_32 ( NULL , L_14 , 0 ,
& V_10 , sizeof( V_10 ) ) ;
return F_33 ( V_76 ) ;
}
