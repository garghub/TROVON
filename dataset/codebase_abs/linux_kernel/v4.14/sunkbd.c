static T_1 F_1 ( struct V_1 * V_1 ,
unsigned char V_2 , unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
if ( V_4 -> V_5 <= - 1 ) {
V_4 -> V_5 = V_2 ;
F_3 ( & V_4 -> V_6 ) ;
goto V_7;
}
if ( V_4 -> V_8 == - 1 ) {
V_4 -> V_8 = V_2 ;
F_3 ( & V_4 -> V_6 ) ;
goto V_7;
}
switch ( V_2 ) {
case V_9 :
F_4 ( & V_4 -> V_10 ) ;
V_4 -> V_5 = - 1 ;
break;
case V_11 :
V_4 -> V_8 = - 1 ;
break;
case V_12 :
break;
default:
if ( ! V_4 -> V_13 )
break;
if ( V_4 -> V_14 [ V_2 & V_15 ] ) {
F_5 ( V_4 -> V_16 ,
V_4 -> V_14 [ V_2 & V_15 ] ,
! ( V_2 & V_17 ) ) ;
F_6 ( V_4 -> V_16 ) ;
} else {
F_7 ( V_18
L_1 ,
V_2 & V_15 ,
V_2 & V_17 ? L_2 : L_3 ) ;
}
}
V_7:
return V_19 ;
}
static int F_8 ( struct V_20 * V_16 ,
unsigned int type , unsigned int V_21 , int V_22 )
{
struct V_4 * V_4 = F_9 ( V_16 ) ;
switch ( type ) {
case V_23 :
F_10 ( V_4 -> V_1 , V_24 ) ;
F_10 ( V_4 -> V_1 ,
( ! ! F_11 ( V_25 , V_16 -> V_26 ) << 3 ) |
( ! ! F_11 ( V_27 , V_16 -> V_26 ) << 2 ) |
( ! ! F_11 ( V_28 , V_16 -> V_26 ) << 1 ) |
! ! F_11 ( V_29 , V_16 -> V_26 ) ) ;
return 0 ;
case V_30 :
switch ( V_21 ) {
case V_31 :
F_10 ( V_4 -> V_1 , V_32 - V_22 ) ;
return 0 ;
case V_33 :
F_10 ( V_4 -> V_1 , V_34 - V_22 ) ;
return 0 ;
}
break;
}
return - 1 ;
}
static int F_12 ( struct V_4 * V_4 )
{
V_4 -> V_5 = - 2 ;
F_10 ( V_4 -> V_1 , V_35 ) ;
F_13 ( V_4 -> V_6 , V_4 -> V_5 >= 0 , V_36 ) ;
if ( V_4 -> V_5 < 0 )
return - 1 ;
V_4 -> type = V_4 -> V_5 ;
if ( V_4 -> type == 4 ) {
V_4 -> V_8 = - 2 ;
F_10 ( V_4 -> V_1 , V_37 ) ;
F_13 ( V_4 -> V_6 ,
V_4 -> V_8 >= 0 , V_36 / 4 ) ;
if ( V_4 -> V_8 < 0 )
return - 1 ;
if ( V_4 -> V_8 & V_38 )
V_4 -> type = 5 ;
}
return 0 ;
}
static void F_14 ( struct V_39 * V_40 )
{
struct V_4 * V_4 = F_15 ( V_40 , struct V_4 , V_10 ) ;
F_13 ( V_4 -> V_6 , V_4 -> V_5 >= 0 , V_36 ) ;
F_10 ( V_4 -> V_1 , V_24 ) ;
F_10 ( V_4 -> V_1 ,
( ! ! F_11 ( V_25 , V_4 -> V_16 -> V_26 ) << 3 ) |
( ! ! F_11 ( V_27 , V_4 -> V_16 -> V_26 ) << 2 ) |
( ! ! F_11 ( V_28 , V_4 -> V_16 -> V_26 ) << 1 ) |
! ! F_11 ( V_29 , V_4 -> V_16 -> V_26 ) ) ;
F_10 ( V_4 -> V_1 ,
V_32 - ! ! F_11 ( V_31 , V_4 -> V_16 -> V_41 ) ) ;
F_10 ( V_4 -> V_1 ,
V_34 - ! ! F_11 ( V_33 , V_4 -> V_16 -> V_41 ) ) ;
}
static void F_16 ( struct V_4 * V_4 , bool V_42 )
{
F_17 ( V_4 -> V_1 ) ;
V_4 -> V_13 = V_42 ;
F_18 ( V_4 -> V_1 ) ;
}
static int F_19 ( struct V_1 * V_1 , struct V_43 * V_44 )
{
struct V_4 * V_4 ;
struct V_20 * V_20 ;
int V_45 = - V_46 ;
int V_47 ;
V_4 = F_20 ( sizeof( struct V_4 ) , V_48 ) ;
V_20 = F_21 () ;
if ( ! V_4 || ! V_20 )
goto V_49;
V_4 -> V_1 = V_1 ;
V_4 -> V_16 = V_20 ;
F_22 ( & V_4 -> V_6 ) ;
F_23 ( & V_4 -> V_10 , F_14 ) ;
snprintf ( V_4 -> V_50 , sizeof( V_4 -> V_50 ) , L_4 , V_1 -> V_50 ) ;
F_24 ( V_1 , V_4 ) ;
V_45 = F_25 ( V_1 , V_44 ) ;
if ( V_45 )
goto V_51;
if ( F_12 ( V_4 ) < 0 ) {
V_45 = - V_52 ;
goto V_53;
}
snprintf ( V_4 -> V_54 , sizeof( V_4 -> V_54 ) ,
L_5 , V_4 -> type ) ;
memcpy ( V_4 -> V_14 , V_55 , sizeof( V_4 -> V_14 ) ) ;
V_20 -> V_54 = V_4 -> V_54 ;
V_20 -> V_50 = V_4 -> V_50 ;
V_20 -> V_56 . V_57 = V_58 ;
V_20 -> V_56 . V_59 = V_60 ;
V_20 -> V_56 . V_61 = V_4 -> type ;
V_20 -> V_56 . V_62 = 0x0100 ;
V_20 -> V_16 . V_63 = & V_1 -> V_16 ;
F_26 ( V_20 , V_4 ) ;
V_20 -> V_64 = F_8 ;
V_20 -> V_65 [ 0 ] = F_27 ( V_66 ) | F_27 ( V_23 ) |
F_27 ( V_30 ) | F_27 ( V_67 ) ;
V_20 -> V_68 [ 0 ] = F_27 ( V_25 ) | F_27 ( V_28 ) |
F_27 ( V_27 ) | F_27 ( V_29 ) ;
V_20 -> V_69 [ 0 ] = F_27 ( V_31 ) | F_27 ( V_33 ) ;
V_20 -> V_14 = V_4 -> V_14 ;
V_20 -> V_70 = sizeof( unsigned char ) ;
V_20 -> V_71 = F_28 ( V_55 ) ;
for ( V_47 = 0 ; V_47 < F_28 ( V_55 ) ; V_47 ++ )
F_29 ( V_4 -> V_14 [ V_47 ] , V_20 -> V_72 ) ;
F_30 ( V_73 , V_20 -> V_72 ) ;
F_16 ( V_4 , true ) ;
V_45 = F_31 ( V_4 -> V_16 ) ;
if ( V_45 )
goto V_74;
return 0 ;
V_74: F_16 ( V_4 , false ) ;
V_53: F_32 ( V_1 ) ;
V_51: F_24 ( V_1 , NULL ) ;
V_49: F_33 ( V_20 ) ;
F_34 ( V_4 ) ;
return V_45 ;
}
static void F_35 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
F_16 ( V_4 , false ) ;
F_36 ( V_4 -> V_16 ) ;
F_32 ( V_1 ) ;
F_24 ( V_1 , NULL ) ;
F_34 ( V_4 ) ;
}
