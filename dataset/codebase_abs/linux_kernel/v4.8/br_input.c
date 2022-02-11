static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
return F_2 ( V_5 ) ;
}
static int F_3 ( struct V_4 * V_5 )
{
struct V_6 * V_7 , * V_8 = F_4 ( V_5 ) -> V_8 ;
struct V_9 * V_10 = F_5 ( V_8 ) ;
struct V_11 * V_12 ;
struct V_13 * V_14 = F_6 ( V_10 -> V_15 ) ;
F_7 ( & V_14 -> V_16 ) ;
V_14 -> V_17 ++ ;
V_14 -> V_18 += V_5 -> V_19 ;
F_8 ( & V_14 -> V_16 ) ;
V_12 = F_9 ( V_10 ) ;
if ( ! ( V_8 -> V_20 & V_21 ) &&
! F_10 ( V_12 , V_5 ) ) {
F_11 ( V_5 ) ;
return V_22 ;
}
V_7 = V_5 -> V_23 ;
V_5 -> V_23 = V_8 ;
V_5 = F_12 ( V_10 , V_12 , V_5 ) ;
if ( ! V_5 )
return V_22 ;
F_13 ( V_10 , NULL , V_5 , F_14 ( V_5 ) ,
V_24 ) ;
return F_15 ( V_25 , V_26 ,
F_16 ( V_7 ) , NULL , V_5 , V_7 , NULL ,
F_1 ) ;
}
static void F_17 ( struct V_4 * V_5 , struct V_9 * V_10 ,
T_1 V_27 , struct V_28 * V_29 )
{
struct V_6 * V_23 = V_10 -> V_23 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
T_2 * V_34 , * V_35 ;
T_3 V_36 , V_37 ;
F_4 ( V_5 ) -> V_38 = false ;
if ( ( V_23 -> V_20 & V_39 ) ||
! F_18 ( V_5 , F_19 ( V_23 ) ) )
return;
V_33 = F_20 ( V_5 ) ;
if ( V_33 -> V_40 != F_21 ( V_41 ) ||
V_33 -> V_42 != F_21 ( V_43 ) ||
V_33 -> V_44 != V_23 -> V_45 ||
V_33 -> V_46 != 4 )
return;
V_34 = ( T_2 * ) V_33 + sizeof( struct V_32 ) ;
V_35 = V_34 ;
V_34 += V_23 -> V_45 ;
memcpy ( & V_36 , V_34 , sizeof( V_36 ) ) ;
V_34 += sizeof( V_36 ) ;
V_34 += V_23 -> V_45 ;
memcpy ( & V_37 , V_34 , sizeof( V_37 ) ) ;
if ( F_22 ( V_37 ) ||
F_23 ( V_37 ) )
return;
V_31 = F_24 ( & V_47 , & V_37 , V_23 ) ;
if ( V_31 ) {
struct V_48 * V_49 ;
if ( ! ( V_31 -> V_50 & V_51 ) ) {
F_25 ( V_31 ) ;
return;
}
V_49 = F_26 ( V_10 , V_31 -> V_52 , V_27 ) ;
if ( V_49 && ( ( V_29 -> V_20 & V_53 ) ||
( V_49 -> V_54 && ( V_49 -> V_54 -> V_20 & V_55 ) ) ) ) {
F_27 ( V_56 , V_57 , V_36 , V_5 -> V_23 , V_37 ,
V_35 , V_31 -> V_52 , V_35 ) ;
F_4 ( V_5 ) -> V_38 = true ;
}
F_25 ( V_31 ) ;
}
}
int F_28 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
bool V_58 = false , V_59 = false , V_60 = true ;
struct V_28 * V_29 = F_29 ( V_5 -> V_23 ) ;
const unsigned char * V_61 = F_30 ( V_5 ) -> V_62 ;
struct V_48 * V_54 = NULL ;
struct V_63 * V_64 ;
struct V_9 * V_10 ;
T_1 V_27 = 0 ;
if ( ! V_29 || V_29 -> V_65 == V_66 )
goto V_67;
if ( ! F_31 ( V_29 -> V_10 , F_32 ( V_29 ) , V_5 , & V_27 ) )
goto V_68;
V_10 = V_29 -> V_10 ;
if ( V_29 -> V_20 & V_69 )
F_33 ( V_10 , V_29 , F_30 ( V_5 ) -> V_70 , V_27 , false ) ;
if ( ! F_34 ( V_61 ) && F_35 ( V_61 ) &&
F_36 ( V_10 , V_29 , V_5 , V_27 ) )
goto V_67;
if ( V_29 -> V_65 == V_71 )
goto V_67;
F_4 ( V_5 ) -> V_8 = V_10 -> V_23 ;
V_58 = ! ! ( V_10 -> V_23 -> V_20 & V_21 ) ;
if ( F_37 ( V_72 ) && V_5 -> V_73 == F_21 ( V_57 ) )
F_17 ( V_5 , V_10 , V_27 , V_29 ) ;
if ( F_34 ( V_61 ) ) {
V_58 = true ;
V_60 = false ;
} else if ( F_35 ( V_61 ) ) {
V_64 = F_38 ( V_10 , V_5 , V_27 ) ;
if ( ( V_64 || F_39 ( V_5 ) ) &&
F_40 ( V_10 , F_30 ( V_5 ) ) ) {
if ( ( V_64 && V_64 -> V_74 ) ||
F_41 ( V_10 ) ) {
V_58 = true ;
V_10 -> V_23 -> V_15 . V_75 ++ ;
}
V_59 = true ;
} else {
V_58 = true ;
V_10 -> V_23 -> V_15 . V_75 ++ ;
}
V_60 = false ;
} else if ( ( V_54 = F_26 ( V_10 , V_61 , V_27 ) ) && V_54 -> V_76 ) {
return F_3 ( V_5 ) ;
}
if ( V_54 ) {
V_54 -> V_77 = V_78 ;
F_42 ( V_54 -> V_54 , V_5 , V_58 , false ) ;
} else {
if ( ! V_59 )
F_43 ( V_10 , V_5 , V_60 , V_58 , false ) ;
else
F_44 ( V_64 , V_5 , V_58 , false ) ;
}
if ( V_58 )
return F_3 ( V_5 ) ;
V_68:
return 0 ;
V_67:
F_11 ( V_5 ) ;
goto V_68;
}
static void F_45 ( struct V_4 * V_5 )
{
struct V_28 * V_29 = F_29 ( V_5 -> V_23 ) ;
T_1 V_27 = 0 ;
if ( V_29 -> V_20 & V_69 && F_46 ( V_29 , V_5 , & V_27 ) )
F_33 ( V_29 -> V_10 , V_29 , F_30 ( V_5 ) -> V_70 , V_27 , false ) ;
}
static int F_47 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_28 * V_29 = F_29 ( V_5 -> V_23 ) ;
F_45 ( V_5 ) ;
F_4 ( V_5 ) -> V_8 = V_29 -> V_10 -> V_23 ;
F_3 ( V_5 ) ;
return 0 ;
}
T_4 F_48 ( struct V_4 * * V_79 )
{
struct V_28 * V_29 ;
struct V_4 * V_5 = * V_79 ;
const unsigned char * V_61 = F_30 ( V_5 ) -> V_62 ;
T_5 * V_80 ;
if ( F_49 ( V_5 -> V_81 == V_82 ) )
return V_83 ;
if ( ! F_50 ( F_30 ( V_5 ) -> V_70 ) )
goto V_67;
V_5 = F_51 ( V_5 , V_84 ) ;
if ( ! V_5 )
return V_85 ;
V_29 = F_29 ( V_5 -> V_23 ) ;
if ( F_49 ( F_52 ( V_61 ) ) ) {
T_1 V_86 = V_29 -> V_10 -> V_87 ;
switch ( V_61 [ 5 ] ) {
case 0x00 :
if ( V_29 -> V_10 -> V_88 == V_89 ||
V_86 & ( 1u << V_61 [ 5 ] ) )
goto V_90;
* V_79 = V_5 ;
F_45 ( V_5 ) ;
return V_83 ;
case 0x01 :
goto V_67;
case 0x0E :
V_86 |= V_29 -> V_10 -> V_91 ;
if ( V_86 & ( 1u << V_61 [ 5 ] ) )
goto V_90;
* V_79 = V_5 ;
F_45 ( V_5 ) ;
return V_83 ;
default:
V_86 |= V_29 -> V_10 -> V_91 ;
if ( V_86 & ( 1u << V_61 [ 5 ] ) )
goto V_90;
}
F_15 ( V_25 , V_26 , F_16 ( V_5 -> V_23 ) ,
NULL , V_5 , V_5 -> V_23 , NULL , F_47 ) ;
return V_85 ;
}
V_90:
switch ( V_29 -> V_65 ) {
case V_92 :
V_80 = F_53 ( V_93 ) ;
if ( V_80 ) {
if ( (* V_80)( V_5 ) ) {
* V_79 = V_5 ;
return V_83 ;
}
V_61 = F_30 ( V_5 ) -> V_62 ;
}
case V_71 :
if ( F_54 ( V_29 -> V_10 -> V_23 -> V_94 , V_61 ) )
V_5 -> V_81 = V_95 ;
F_15 ( V_25 , V_96 ,
F_16 ( V_5 -> V_23 ) , NULL , V_5 , V_5 -> V_23 , NULL ,
F_28 ) ;
break;
default:
V_67:
F_11 ( V_5 ) ;
}
return V_85 ;
}
