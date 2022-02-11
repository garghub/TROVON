static int T_1 F_1 ( T_2 * V_1 )
{
if ( V_1 -> V_2 & V_3 )
return 1 ;
return 0 ;
}
static T_3 F_2 ( unsigned long V_4 )
{
T_2 * V_1 ;
F_3 (&memmap, md) {
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
static int T_1 F_4 ( void )
{
T_4 * V_10 ;
void * V_11 ;
T_5 V_12 ;
char V_13 [ 100 ] = L_1 ;
int V_14 , V_15 ;
V_16 . V_17 = F_5 ( V_18 ,
sizeof( V_19 ) ) ;
if ( V_16 . V_17 == NULL ) {
F_6 ( L_2 ) ;
return - V_20 ;
}
F_7 ( V_21 , & V_16 . V_22 ) ;
if ( F_8 ( V_23 ) )
F_7 ( V_24 , & V_16 . V_22 ) ;
if ( V_16 . V_17 -> V_25 . V_26 != V_27 ) {
F_9 ( L_3 ) ;
V_15 = - V_28 ;
goto V_29;
}
if ( ( V_16 . V_17 -> V_25 . V_30 >> 16 ) < 2 )
F_6 ( L_4 ,
V_16 . V_17 -> V_25 . V_30 >> 16 ,
V_16 . V_17 -> V_25 . V_30 & 0xffff ) ;
V_10 = F_5 ( F_2 ( V_16 . V_17 -> V_31 ) ,
sizeof( V_13 ) * sizeof( T_4 ) ) ;
if ( V_10 ) {
for ( V_14 = 0 ; V_14 < ( int ) sizeof( V_13 ) - 1 && * V_10 ; ++ V_14 )
V_13 [ V_14 ] = V_10 [ V_14 ] ;
V_13 [ V_14 ] = '\0' ;
F_10 ( V_10 , sizeof( V_13 ) * sizeof( T_4 ) ) ;
}
F_11 ( L_5 ,
V_16 . V_17 -> V_25 . V_30 >> 16 ,
V_16 . V_17 -> V_25 . V_30 & 0xffff , V_13 ) ;
V_12 = sizeof( V_32 ) * V_16 . V_17 -> V_33 ;
V_11 = F_5 ( F_2 ( V_16 . V_17 -> V_34 ) ,
V_12 ) ;
if ( V_11 == NULL ) {
F_6 ( L_6 ) ;
V_15 = - V_20 ;
goto V_29;
}
V_15 = F_12 ( V_11 , V_16 . V_17 -> V_33 ,
sizeof( V_35 ) , NULL ) ;
F_10 ( V_11 , V_12 ) ;
V_29:
F_10 ( V_16 . V_17 , sizeof( V_19 ) ) ;
return V_15 ;
}
static T_1 int F_13 ( T_2 * V_1 )
{
switch ( V_1 -> type ) {
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
return 0 ;
default:
break;
}
return F_1 ( V_1 ) ;
}
static T_1 void F_14 ( void )
{
T_2 * V_1 ;
T_6 V_42 , V_43 , V_44 ;
if ( F_15 ( V_45 ) )
F_11 ( L_7 ) ;
F_3 (&memmap, md) {
V_42 = V_1 -> V_9 ;
V_43 = V_1 -> V_7 ;
if ( F_15 ( V_45 ) ) {
char V_46 [ 64 ] ;
F_11 ( L_8 ,
V_42 , V_42 + ( V_43 << V_8 ) - 1 ,
F_16 ( V_46 , sizeof( V_46 ) , V_1 ) ) ;
}
F_17 ( & V_42 , & V_43 ) ;
V_44 = V_43 << V_47 ;
if ( F_1 ( V_1 ) )
F_18 ( V_42 , V_44 ) ;
if ( F_13 ( V_1 ) ) {
F_19 ( V_42 , V_44 ) ;
if ( F_15 ( V_45 ) )
F_20 ( L_9 ) ;
}
if ( F_15 ( V_45 ) )
F_20 ( L_10 ) ;
}
F_7 ( V_48 , & V_16 . V_22 ) ;
}
void T_1 F_21 ( void )
{
struct V_49 V_50 ;
if ( ! F_22 ( & V_50 ) )
return;
V_18 = V_50 . V_51 ;
V_52 . V_53 = V_50 . V_54 ;
V_52 . V_55 = F_5 ( V_50 . V_54 , V_50 . V_56 ) ;
if ( V_52 . V_55 == NULL ) {
F_23 ( L_11 ) ;
}
V_52 . V_57 = V_52 . V_55 + V_50 . V_56 ;
V_52 . V_58 = V_50 . V_58 ;
V_52 . V_59 = V_50 . V_60 ;
if ( F_4 () < 0 )
return;
F_14 () ;
F_10 ( V_52 . V_55 , V_50 . V_56 ) ;
if ( F_8 ( V_61 ) ) {
F_19 ( V_50 . V_54 & V_62 ,
F_24 ( V_50 . V_56 +
( V_50 . V_54 & ~ V_62 ) ) ) ;
} else {
F_25 ( V_50 . V_54 & V_62 ,
F_24 ( V_50 . V_56 +
( V_50 . V_54 & ~ V_62 ) ) ) ;
}
}
