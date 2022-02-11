static int T_1 F_1 ( T_2 * V_1 )
{
if ( V_1 -> V_2 & ( V_3 | V_4 | V_5 ) )
return 1 ;
return 0 ;
}
static T_3 F_2 ( unsigned long V_6 )
{
T_2 * V_1 ;
F_3 (md) {
if ( ! ( V_1 -> V_2 & V_7 ) )
continue;
if ( V_1 -> V_8 == 0 )
break;
if ( V_1 -> V_8 <= V_6 &&
( V_6 - V_1 -> V_8 ) < ( V_1 -> V_9 << V_10 ) )
return V_1 -> V_11 + V_6 - V_1 -> V_8 ;
}
return V_6 ;
}
static void T_1 F_4 ( void )
{
struct V_12 * V_13 ;
if ( V_14 != V_15 ) {
V_13 = F_5 ( V_14 , sizeof( * V_13 ) ) ;
if ( ! V_13 ) {
F_6 ( L_1 ) ;
return;
}
V_12 = * V_13 ;
F_7 ( V_13 , sizeof( * V_13 ) ) ;
V_12 . V_16 = 80 ;
V_12 . V_17 = 25 ;
}
if ( V_12 . V_18 == V_19 &&
F_8 ( V_12 . V_20 ) )
F_9 ( V_12 . V_20 , V_12 . V_21 ) ;
}
static int T_1 F_10 ( void )
{
T_4 * V_22 ;
void * V_23 ;
T_5 V_24 ;
char V_25 [ 100 ] = L_2 ;
int V_26 , V_27 ;
V_28 . V_29 = F_5 ( V_30 ,
sizeof( V_31 ) ) ;
if ( V_28 . V_29 == NULL ) {
F_11 ( L_3 ) ;
return - V_32 ;
}
F_12 ( V_33 , & V_28 . V_34 ) ;
if ( F_13 ( V_35 ) )
F_12 ( V_36 , & V_28 . V_34 ) ;
if ( V_28 . V_29 -> V_37 . V_38 != V_39 ) {
F_6 ( L_4 ) ;
V_27 = - V_40 ;
goto V_41;
}
if ( ( V_28 . V_29 -> V_37 . V_42 >> 16 ) < 2 )
F_11 ( L_5 ,
V_28 . V_29 -> V_37 . V_42 >> 16 ,
V_28 . V_29 -> V_37 . V_42 & 0xffff ) ;
V_28 . V_43 = V_28 . V_29 -> V_37 . V_42 ;
V_22 = F_5 ( F_2 ( V_28 . V_29 -> V_44 ) ,
sizeof( V_25 ) * sizeof( T_4 ) ) ;
if ( V_22 ) {
for ( V_26 = 0 ; V_26 < ( int ) sizeof( V_25 ) - 1 && * V_22 ; ++ V_26 )
V_25 [ V_26 ] = V_22 [ V_26 ] ;
V_25 [ V_26 ] = '\0' ;
F_7 ( V_22 , sizeof( V_25 ) * sizeof( T_4 ) ) ;
}
F_14 ( L_6 ,
V_28 . V_29 -> V_37 . V_42 >> 16 ,
V_28 . V_29 -> V_37 . V_42 & 0xffff , V_25 ) ;
V_24 = sizeof( V_45 ) * V_28 . V_29 -> V_46 ;
V_23 = F_5 ( F_2 ( V_28 . V_29 -> V_47 ) ,
V_24 ) ;
if ( V_23 == NULL ) {
F_11 ( L_7 ) ;
V_27 = - V_32 ;
goto V_41;
}
V_27 = F_15 ( V_23 , V_28 . V_29 -> V_46 ,
sizeof( V_48 ) ,
V_49 ) ;
if ( ! V_27 )
V_28 . V_50 = ( unsigned long ) V_28 . V_29 -> V_47 ;
F_7 ( V_23 , V_24 ) ;
V_41:
F_7 ( V_28 . V_29 , sizeof( V_31 ) ) ;
return V_27 ;
}
static T_1 int F_16 ( T_2 * V_1 )
{
switch ( V_1 -> type ) {
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
case V_57 :
return ( V_1 -> V_2 & V_3 ) ;
default:
break;
}
return false ;
}
static T_1 void F_17 ( void )
{
T_2 * V_1 ;
T_6 V_58 , V_59 , V_60 ;
if ( F_18 ( V_61 ) )
F_14 ( L_8 ) ;
F_19 () ;
F_20 ( 0 , ( T_3 ) V_62 ) ;
F_3 (md) {
V_58 = V_1 -> V_11 ;
V_59 = V_1 -> V_9 ;
if ( F_18 ( V_61 ) ) {
char V_63 [ 64 ] ;
F_14 ( L_9 ,
V_58 , V_58 + ( V_59 << V_10 ) - 1 ,
F_21 ( V_63 , sizeof( V_63 ) , V_1 ) ) ;
}
F_22 ( & V_58 , & V_59 ) ;
V_60 = V_59 << V_64 ;
if ( F_1 ( V_1 ) ) {
F_23 ( V_58 , V_60 ) ;
if ( ! F_16 ( V_1 ) )
F_9 ( V_58 , V_60 ) ;
if ( V_1 -> type == V_53 )
F_24 ( V_58 , V_60 ) ;
}
}
}
void T_1 F_25 ( void )
{
struct V_65 V_66 ;
struct V_67 V_68 ;
if ( ! F_26 ( & V_68 ) )
return;
V_30 = V_68 . V_69 ;
V_66 . V_70 = V_68 . V_71 ;
V_66 . V_72 = V_68 . V_72 ;
V_66 . V_60 = V_68 . V_73 ;
V_66 . V_74 = V_68 . V_75 ;
if ( F_27 ( & V_66 ) < 0 ) {
F_28 ( L_10 ) ;
}
F_29 ( V_28 . V_76 . V_70 != 1 ,
L_11 ,
V_28 . V_76 . V_70 ) ;
if ( F_10 () < 0 ) {
F_30 () ;
return;
}
F_17 () ;
F_31 () ;
F_30 () ;
F_24 ( V_68 . V_75 & V_77 ,
F_32 ( V_68 . V_73 +
( V_68 . V_75 & ~ V_77 ) ) ) ;
F_4 () ;
}
static int T_1 F_33 ( void )
{
void * V_78 ;
if ( V_12 . V_18 != V_19 )
return 0 ;
V_78 = F_34 ( NULL , L_12 , 0 ,
& V_12 , sizeof( V_12 ) ) ;
return F_35 ( V_78 ) ;
}
