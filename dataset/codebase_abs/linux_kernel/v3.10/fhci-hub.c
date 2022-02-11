static void F_1 ( struct V_1 * V_2 , int V_3 , bool V_4 )
{
int V_5 = V_2 -> V_6 [ V_3 ] ;
bool V_7 = V_2 -> V_8 [ V_3 ] ;
if ( ! F_2 ( V_5 ) )
return;
F_3 ( V_5 , V_4 ^ V_7 ) ;
F_4 ( 5 ) ;
}
void F_5 ( struct V_1 * V_2 ,
enum V_9 V_10 )
{
F_6 ( V_2 , L_1 , V_11 , V_10 ) ;
switch ( V_10 ) {
case V_12 :
F_1 ( V_2 , V_13 , false ) ;
break;
case V_14 :
case V_15 :
F_1 ( V_2 , V_13 , true ) ;
break;
case V_16 :
F_1 ( V_2 , V_17 , false ) ;
break;
case V_18 :
F_1 ( V_2 , V_17 , true ) ;
break;
default:
F_7 ( 1 ) ;
break;
}
F_6 ( V_2 , L_2 , V_11 , V_10 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_19 * V_20 = (struct V_19 * ) V_2 -> V_21 ;
enum V_9 V_22 ;
F_6 ( V_2 , L_3 , V_11 ) ;
F_9 ( V_2 ) ;
F_10 ( V_20 ) ;
F_11 ( (struct V_19 * ) V_2 -> V_21 ) ;
V_22 = V_20 -> V_22 ;
V_20 -> V_22 = V_14 ;
V_20 -> V_23 |= V_24 ;
F_12 ( & V_20 -> V_2 -> V_25 -> V_26 , V_20 -> V_23 ) ;
if ( V_22 == V_15 )
F_13 ( V_2 ) ;
V_20 -> V_27 -> V_28 . V_29 &= ~ V_30 ;
V_20 -> V_27 -> V_28 . V_31 |= V_32 ;
F_14 ( (struct V_19 * ) V_2 -> V_21 ) ;
F_6 ( V_2 , L_4 , V_11 ) ;
}
void F_15 ( void * V_33 )
{
struct V_19 * V_20 = (struct V_19 * ) V_33 ;
struct V_1 * V_2 = V_20 -> V_2 ;
F_6 ( V_2 , L_3 , V_11 ) ;
F_5 ( V_2 , V_20 -> V_22 ) ;
if ( ( V_20 -> V_22 != V_18 ) &&
( V_20 -> V_22 != V_16 ) )
F_16 ( V_2 ) ;
V_20 -> V_27 -> V_28 . V_29 |= V_30 ;
V_20 -> V_27 -> V_28 . V_31 |= V_32 ;
F_6 ( V_2 , L_4 , V_11 ) ;
}
void F_17 ( struct V_1 * V_2 )
{
F_6 ( V_2 , L_3 , V_11 ) ;
F_18 ( V_2 -> V_6 [ V_34 ] , 0 ) ;
F_18 ( V_2 -> V_6 [ V_35 ] , 0 ) ;
F_18 ( V_2 -> V_6 [ V_36 ] , 0 ) ;
F_4 ( 5 ) ;
F_19 ( V_2 -> V_37 [ V_38 ] ) ;
F_19 ( V_2 -> V_37 [ V_39 ] ) ;
F_19 ( V_2 -> V_37 [ V_40 ] ) ;
F_6 ( V_2 , L_4 , V_11 ) ;
}
void F_20 ( void * V_33 )
{
struct V_19 * V_20 = (struct V_19 * ) V_33 ;
struct V_1 * V_2 = V_20 -> V_2 ;
T_1 V_41 ;
T_2 V_42 ;
F_6 ( V_2 , L_3 , V_11 ) ;
F_9 ( V_2 ) ;
V_41 = F_21 ( & V_2 -> V_25 -> V_43 ) ;
F_22 ( & V_2 -> V_25 -> V_43 , V_41 & ( ~ V_44 ) ) ;
V_42 = F_23 ( & V_2 -> V_25 -> V_26 ) ;
F_12 ( & V_2 -> V_25 -> V_26 , V_42 & ( ~ V_24 ) ) ;
F_17 ( V_2 ) ;
F_12 ( & V_2 -> V_25 -> V_26 , V_42 ) ;
V_41 = F_21 ( & V_2 -> V_25 -> V_43 ) ;
F_22 ( & V_2 -> V_25 -> V_43 , V_41 | V_44 ) ;
F_16 ( V_2 ) ;
F_6 ( V_2 , L_4 , V_11 ) ;
}
int F_24 ( struct V_45 * V_46 , char * V_47 )
{
struct V_1 * V_2 = F_25 ( V_46 ) ;
int V_48 = 0 ;
unsigned long V_49 ;
F_6 ( V_2 , L_3 , V_11 ) ;
F_26 ( & V_2 -> V_50 , V_49 ) ;
if ( V_2 -> V_27 -> V_28 . V_31 & ( V_51 |
V_32 | V_52 |
V_53 | V_54 ) ) {
* V_47 = 1 << 1 ;
V_48 = 1 ;
F_6 ( V_2 , L_5 , V_11 ) ;
}
F_27 ( & V_2 -> V_50 , V_49 ) ;
F_6 ( V_2 , L_4 , V_11 ) ;
return V_48 ;
}
int F_28 ( struct V_45 * V_46 , T_2 V_55 , T_2 V_56 ,
T_2 V_57 , char * V_47 , T_2 V_58 )
{
struct V_1 * V_2 = F_25 ( V_46 ) ;
int V_59 = 0 ;
int V_60 = 0 ;
struct V_61 * V_62 ;
struct V_63 * V_22 ;
unsigned long V_49 ;
F_26 ( & V_2 -> V_50 , V_49 ) ;
F_6 ( V_2 , L_3 , V_11 ) ;
switch ( V_55 ) {
case V_64 :
switch ( V_56 ) {
case V_65 :
case V_66 :
break;
default:
goto error;
}
break;
case V_67 :
V_2 -> V_27 -> V_68 &= ( 1 << V_56 ) ;
switch ( V_56 ) {
case V_69 :
V_2 -> V_27 -> V_28 . V_29 &=
~ V_30 ;
F_8 ( V_2 ) ;
break;
case V_70 :
V_2 -> V_27 -> V_28 . V_31 &=
~ V_32 ;
break;
case V_71 :
V_2 -> V_27 -> V_28 . V_29 &=
~ V_72 ;
F_9 ( V_2 ) ;
break;
case V_73 :
V_2 -> V_27 -> V_28 . V_31 &=
~ V_52 ;
break;
case V_74 :
V_2 -> V_27 -> V_28 . V_29 &=
~ V_75 ;
F_5 ( V_2 , V_12 ) ;
break;
case V_76 :
V_2 -> V_27 -> V_28 . V_31 &=
~ V_51 ;
break;
case V_77 :
V_2 -> V_27 -> V_28 . V_31 &=
~ V_54 ;
break;
case V_78 :
V_2 -> V_27 -> V_28 . V_31 &=
~ V_53 ;
break;
default:
goto error;
}
break;
case V_79 :
memcpy ( V_47 , V_80 , sizeof( V_80 ) ) ;
V_47 [ 3 ] = 0x11 ;
V_60 = ( V_47 [ 0 ] < V_58 ) ? V_47 [ 0 ] : V_58 ;
break;
case V_81 :
V_62 = (struct V_61 * ) V_47 ;
V_62 -> V_82 =
F_29 ( V_2 -> V_27 -> V_83 . V_82 ) ;
V_62 -> V_84 =
F_29 ( V_2 -> V_27 -> V_83 . V_84 ) ;
V_60 = 4 ;
break;
case V_85 :
V_22 = (struct V_63 * ) V_47 ;
V_22 -> V_29 =
F_29 ( V_2 -> V_27 -> V_28 . V_29 ) ;
V_22 -> V_31 =
F_29 ( V_2 -> V_27 -> V_28 . V_31 ) ;
V_60 = 4 ;
break;
case V_86 :
switch ( V_56 ) {
case V_66 :
case V_65 :
break;
default:
goto error;
}
break;
case V_87 :
V_2 -> V_27 -> V_68 |= ( 1 << V_56 ) ;
switch ( V_56 ) {
case V_69 :
V_2 -> V_27 -> V_28 . V_29 |=
V_30 ;
F_15 ( V_2 -> V_21 ) ;
break;
case V_71 :
V_2 -> V_27 -> V_28 . V_29 |=
V_72 ;
F_9 ( V_2 ) ;
break;
case V_88 :
V_2 -> V_27 -> V_28 . V_29 |=
V_89 ;
F_20 ( V_2 -> V_21 ) ;
V_2 -> V_27 -> V_28 . V_29 |=
V_30 ;
V_2 -> V_27 -> V_28 . V_29 &=
~ V_89 ;
break;
case V_74 :
V_2 -> V_27 -> V_28 . V_29 |=
V_75 ;
F_5 ( V_2 , V_15 ) ;
break;
default:
goto error;
}
break;
default:
error:
V_59 = - V_90 ;
}
F_6 ( V_2 , L_4 , V_11 ) ;
F_27 ( & V_2 -> V_50 , V_49 ) ;
return V_59 ;
}
