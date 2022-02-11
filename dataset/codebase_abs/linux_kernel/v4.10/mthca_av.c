static enum V_1 F_1 ( T_1 V_2 , T_1 V_3 )
{
switch ( V_2 ) {
case V_4 :
return F_2 ( V_3 >> 3 ) ;
case V_5 :
return F_2 ( V_3 >> 2 ) ;
case V_6 :
return F_2 ( V_3 >> 1 ) ;
case V_7 :
default:
return F_2 ( V_3 ) ;
}
}
static enum V_1 F_3 ( T_1 V_2 , T_1 V_3 )
{
switch ( V_2 ) {
case V_8 : return V_9 ;
case V_10 : return V_11 ;
case V_12 : return V_13 ;
default: return F_2 ( V_3 ) ;
}
}
enum V_1 F_4 ( struct V_14 * V_15 , T_1 V_2 , T_1 V_16 )
{
if ( F_5 ( V_15 ) ) {
if ( V_15 -> V_17 . V_18 == 0x3 && V_2 )
return V_9 ;
return F_1 ( V_2 , V_15 -> V_19 [ V_16 - 1 ] ) ;
} else
return F_3 ( V_2 , V_15 -> V_19 [ V_16 - 1 ] ) ;
}
static T_1 F_6 ( T_1 V_20 , T_1 V_21 )
{
if ( V_21 <= V_20 )
return 0 ;
switch ( ( V_21 - 1 ) / V_20 ) {
case 0 : return V_7 ;
case 1 : return V_6 ;
case 2 :
case 3 : return V_5 ;
default: return V_4 ;
}
}
static T_1 F_7 ( T_1 V_22 )
{
switch ( V_22 ) {
case V_9 : return V_8 ;
case V_11 : return V_10 ;
case V_13 : return V_12 ;
default: return V_23 ;
}
}
T_1 F_8 ( struct V_14 * V_15 , int V_22 , T_1 V_16 )
{
T_1 V_19 ;
if ( ! V_22 || F_9 ( V_22 ) >= V_15 -> V_19 [ V_16 - 1 ] )
return 0 ;
if ( F_5 ( V_15 ) )
V_19 = F_6 ( F_9 ( V_22 ) ,
V_15 -> V_19 [ V_16 - 1 ] ) ;
else
V_19 = F_7 ( V_22 ) ;
if ( ! ( V_15 -> V_17 . V_18 & ( 1 << V_19 ) ) )
V_19 = 1 ;
return V_19 ;
}
int F_10 ( struct V_14 * V_15 ,
struct V_24 * V_25 ,
struct V_26 * V_27 ,
struct V_28 * V_29 )
{
T_2 V_30 = - 1 ;
struct V_31 * V_32 = NULL ;
V_29 -> type = V_33 ;
if ( F_5 ( V_15 ) ) {
V_29 -> V_32 = F_11 ( sizeof * V_29 -> V_32 , V_34 ) ;
if ( ! V_29 -> V_32 )
return - V_35 ;
V_29 -> type = V_36 ;
V_32 = V_29 -> V_32 ;
} else if ( ! F_12 ( & V_25 -> V_37 ) &&
! ( V_15 -> V_38 & V_39 ) ) {
V_30 = F_13 ( & V_15 -> V_40 . V_41 ) ;
if ( V_30 == - 1 )
goto V_42;
V_32 = F_11 ( sizeof *V_32 , V_34 ) ;
if ( ! V_32 )
goto V_42;
V_29 -> type = V_43 ;
V_29 -> V_44 = V_15 -> V_40 . V_45 +
V_30 * V_46 ;
}
V_42:
if ( V_29 -> type == V_33 ) {
V_29 -> V_32 = F_14 ( V_15 -> V_40 . V_47 ,
V_34 , & V_29 -> V_44 ) ;
if ( ! V_29 -> V_32 )
return - V_35 ;
V_32 = V_29 -> V_32 ;
}
V_29 -> V_48 = V_25 -> V_49 . V_50 . V_51 ;
V_32 -> V_52 = F_15 ( V_25 -> V_53 | ( V_27 -> V_54 << 24 ) ) ;
V_32 -> V_55 = V_27 -> V_56 ;
V_32 -> V_57 = F_16 ( V_27 -> V_57 ) ;
V_32 -> V_58 = ( 3 << 4 ) |
F_8 ( V_15 , V_27 -> V_22 , V_27 -> V_54 ) ;
V_32 -> V_59 = F_15 ( V_27 -> V_60 << 28 ) ;
if ( V_27 -> V_61 & V_62 ) {
V_32 -> V_55 |= 0x80 ;
V_32 -> V_63 = ( V_27 -> V_54 - 1 ) * V_15 -> V_17 . V_64 +
V_27 -> V_65 . V_66 ;
V_32 -> V_67 = V_27 -> V_65 . V_67 ;
V_32 -> V_59 |=
F_15 ( ( V_27 -> V_65 . V_68 << 20 ) |
V_27 -> V_65 . V_69 ) ;
memcpy ( V_32 -> V_70 , V_27 -> V_65 . V_70 . V_71 , 16 ) ;
} else {
V_32 -> V_70 [ 3 ] = F_15 ( 2 ) ;
}
if ( 0 ) {
int V_72 ;
F_17 ( V_15 , L_1 ,
V_32 , ( unsigned long ) V_29 -> V_44 ) ;
for ( V_72 = 0 ; V_72 < 8 ; ++ V_72 )
F_18 ( V_73 L_2 ,
V_72 * 4 , F_19 ( ( ( V_74 * ) V_32 ) [ V_72 ] ) ) ;
}
if ( V_29 -> type == V_43 ) {
F_20 ( V_15 -> V_40 . V_75 + V_30 * V_46 ,
V_32 , V_46 ) ;
F_21 ( V_32 ) ;
}
return 0 ;
}
int F_22 ( struct V_14 * V_15 , struct V_28 * V_29 )
{
switch ( V_29 -> type ) {
case V_43 :
F_23 ( & V_15 -> V_40 . V_41 ,
( V_29 -> V_44 - V_15 -> V_40 . V_45 ) /
V_46 ) ;
break;
case V_33 :
F_24 ( V_15 -> V_40 . V_47 , V_29 -> V_32 , V_29 -> V_44 ) ;
break;
case V_36 :
F_21 ( V_29 -> V_32 ) ;
break;
}
return 0 ;
}
int F_25 ( struct V_28 * V_29 )
{
return ! ! ( V_29 -> V_32 -> V_55 & 0x80 ) ;
}
int F_26 ( struct V_14 * V_15 , struct V_28 * V_29 ,
struct V_76 * V_77 )
{
if ( V_29 -> type == V_43 )
return - V_78 ;
V_77 -> V_79 . V_80 = F_19 ( V_29 -> V_32 -> V_59 ) >> 28 ;
V_77 -> V_79 . V_81 = V_29 -> V_32 -> V_57 ;
V_77 -> V_79 . V_82 = F_16 ( V_29 -> V_32 -> V_55 & 0x7f ) ;
if ( F_25 ( V_29 ) ) {
V_77 -> V_65 . V_68 =
( F_19 ( V_29 -> V_32 -> V_59 ) >> 20 ) & 0xff ;
V_77 -> V_65 . V_69 =
V_29 -> V_32 -> V_59 & F_15 ( 0xfffff ) ;
V_77 -> V_65 . V_67 = V_29 -> V_32 -> V_67 ;
F_27 ( & V_15 -> V_83 ,
F_19 ( V_29 -> V_32 -> V_52 ) >> 24 ,
V_29 -> V_32 -> V_63 % V_15 -> V_17 . V_64 ,
& V_77 -> V_65 . V_84 , NULL ) ;
memcpy ( V_77 -> V_65 . V_85 . V_71 ,
V_29 -> V_32 -> V_70 , 16 ) ;
}
return 0 ;
}
int F_28 ( struct V_86 * V_87 , struct V_26 * V_88 )
{
struct V_28 * V_29 = F_29 ( V_87 ) ;
struct V_14 * V_15 = F_30 ( V_87 -> V_89 ) ;
if ( V_29 -> type == V_43 )
return - V_90 ;
memset ( V_88 , 0 , sizeof *V_88 ) ;
V_88 -> V_57 = F_31 ( V_29 -> V_32 -> V_57 ) ;
V_88 -> V_60 = F_19 ( V_29 -> V_32 -> V_59 ) >> 28 ;
V_88 -> V_54 = F_19 ( V_29 -> V_32 -> V_52 ) >> 24 ;
V_88 -> V_22 = F_4 ( V_15 , V_29 -> V_32 -> V_58 & 0x7 ,
V_88 -> V_54 ) ;
V_88 -> V_56 = V_29 -> V_32 -> V_55 & 0x7F ;
V_88 -> V_61 = F_25 ( V_29 ) ? V_62 : 0 ;
if ( V_88 -> V_61 ) {
V_88 -> V_65 . V_68 =
F_19 ( V_29 -> V_32 -> V_59 ) >> 20 ;
V_88 -> V_65 . V_69 =
F_19 ( V_29 -> V_32 -> V_59 ) & 0xfffff ;
V_88 -> V_65 . V_67 = V_29 -> V_32 -> V_67 ;
V_88 -> V_65 . V_66 = V_29 -> V_32 -> V_63 &
( V_15 -> V_17 . V_64 - 1 ) ;
memcpy ( V_88 -> V_65 . V_70 . V_71 , V_29 -> V_32 -> V_70 , 16 ) ;
}
return 0 ;
}
int F_32 ( struct V_14 * V_15 )
{
int V_91 ;
if ( F_5 ( V_15 ) )
return 0 ;
V_91 = F_33 ( & V_15 -> V_40 . V_41 ,
V_15 -> V_40 . V_92 ,
V_15 -> V_40 . V_92 - 1 ,
0 ) ;
if ( V_91 )
return V_91 ;
V_15 -> V_40 . V_47 = F_34 ( L_3 , V_15 -> V_93 ,
V_46 ,
V_46 , 0 ) ;
if ( ! V_15 -> V_40 . V_47 )
goto V_94;
if ( ! ( V_15 -> V_38 & V_39 ) ) {
V_15 -> V_40 . V_75 = F_35 ( F_36 ( V_15 -> V_93 , 4 ) +
V_15 -> V_40 . V_45 -
V_15 -> V_95 ,
V_15 -> V_40 . V_92 *
V_46 ) ;
if ( ! V_15 -> V_40 . V_75 )
goto V_96;
} else
V_15 -> V_40 . V_75 = NULL ;
return 0 ;
V_96:
F_37 ( V_15 -> V_40 . V_47 ) ;
V_94:
F_38 ( & V_15 -> V_40 . V_41 ) ;
return - V_35 ;
}
void F_39 ( struct V_14 * V_15 )
{
if ( F_5 ( V_15 ) )
return;
if ( V_15 -> V_40 . V_75 )
F_40 ( V_15 -> V_40 . V_75 ) ;
F_37 ( V_15 -> V_40 . V_47 ) ;
F_38 ( & V_15 -> V_40 . V_41 ) ;
}
