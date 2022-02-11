static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 = F_2 ( V_2 ) -> V_5 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_7 -> V_10 ) ;
struct V_11 * V_12 ;
F_5 ( & V_9 -> V_13 ) ;
V_9 -> V_14 ++ ;
V_9 -> V_15 += V_2 -> V_16 ;
F_6 ( & V_9 -> V_13 ) ;
V_12 = F_7 ( V_7 ) ;
if ( ! ( V_5 -> V_17 & V_18 ) &&
! F_8 ( V_7 , V_12 , V_2 ) ) {
F_9 ( V_2 ) ;
return V_19 ;
}
V_4 = V_2 -> V_20 ;
V_2 -> V_20 = V_5 ;
V_2 = F_10 ( V_7 , V_12 , V_2 ) ;
if ( ! V_2 )
return V_19 ;
return F_11 ( V_21 , V_22 , V_2 , V_4 , NULL ,
V_23 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_1 V_24 )
{
struct V_3 * V_20 = V_7 -> V_20 ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
T_2 * V_29 , * V_30 ;
T_3 V_31 , V_32 ;
if ( V_20 -> V_17 & V_33 )
return;
if ( ! F_13 ( V_2 , F_14 ( V_20 ) ) ) {
V_20 -> V_10 . V_34 ++ ;
return;
}
V_28 = F_15 ( V_2 ) ;
if ( V_28 -> V_35 != F_16 ( V_36 ) ||
V_28 -> V_37 != F_16 ( V_38 ) ||
V_28 -> V_39 != V_20 -> V_40 ||
V_28 -> V_41 != 4 )
return;
V_29 = ( T_2 * ) V_28 + sizeof( struct V_27 ) ;
V_30 = V_29 ;
V_29 += V_20 -> V_40 ;
memcpy ( & V_31 , V_29 , sizeof( V_31 ) ) ;
V_29 += sizeof( V_31 ) ;
V_29 += V_20 -> V_40 ;
memcpy ( & V_32 , V_29 , sizeof( V_32 ) ) ;
if ( F_17 ( V_32 ) ||
F_18 ( V_32 ) )
return;
V_26 = F_19 ( & V_42 , & V_32 , V_20 ) ;
if ( V_26 ) {
struct V_43 * V_44 ;
if ( ! ( V_26 -> V_45 & V_46 ) ) {
F_20 ( V_26 ) ;
return;
}
V_44 = F_21 ( V_7 , V_26 -> V_47 , V_24 ) ;
if ( V_44 )
F_22 ( V_48 , V_49 , V_31 , V_2 -> V_20 , V_32 ,
V_30 , V_26 -> V_47 , V_30 ) ;
F_20 ( V_26 ) ;
}
}
int F_23 ( struct V_1 * V_2 )
{
const unsigned char * V_50 = F_24 ( V_2 ) -> V_51 ;
struct V_52 * V_53 = F_25 ( V_2 -> V_20 ) ;
struct V_6 * V_7 ;
struct V_43 * V_54 ;
struct V_55 * V_56 ;
struct V_1 * V_57 ;
bool V_58 = true ;
T_1 V_24 = 0 ;
if ( ! V_53 || V_53 -> V_59 == V_60 )
goto V_61;
if ( ! F_26 ( V_53 -> V_7 , F_27 ( V_53 ) , V_2 , & V_24 ) )
goto V_62;
V_7 = V_53 -> V_7 ;
if ( V_53 -> V_17 & V_63 )
F_28 ( V_7 , V_53 , F_24 ( V_2 ) -> V_64 , V_24 , false ) ;
if ( ! F_29 ( V_50 ) && F_30 ( V_50 ) &&
F_31 ( V_7 , V_53 , V_2 , V_24 ) )
goto V_61;
if ( V_53 -> V_59 == V_65 )
goto V_61;
F_2 ( V_2 ) -> V_5 = V_7 -> V_20 ;
V_57 = NULL ;
if ( V_7 -> V_20 -> V_17 & V_18 )
V_57 = V_2 ;
V_54 = NULL ;
if ( F_29 ( V_50 ) ) {
if ( F_32 ( V_66 ) &&
V_53 -> V_17 & V_67 &&
V_2 -> V_68 == F_16 ( V_49 ) )
F_12 ( V_2 , V_7 , V_24 ) ;
V_57 = V_2 ;
V_58 = false ;
} else if ( F_30 ( V_50 ) ) {
V_56 = F_33 ( V_7 , V_2 , V_24 ) ;
if ( ( V_56 || F_34 ( V_2 ) ) &&
F_35 ( V_7 , F_24 ( V_2 ) ) ) {
if ( ( V_56 && V_56 -> V_69 ) ||
F_36 ( V_7 ) )
V_57 = V_2 ;
F_37 ( V_56 , V_2 , V_57 ) ;
V_2 = NULL ;
if ( ! V_57 )
goto V_62;
} else
V_57 = V_2 ;
V_58 = false ;
V_7 -> V_20 -> V_10 . V_70 ++ ;
} else if ( ( V_54 = F_21 ( V_7 , V_50 , V_24 ) ) &&
V_54 -> V_71 ) {
V_57 = V_2 ;
V_2 = NULL ;
}
if ( V_2 ) {
if ( V_54 ) {
V_54 -> V_72 = V_73 ;
F_38 ( V_54 -> V_54 , V_2 , V_57 ) ;
} else
F_39 ( V_7 , V_2 , V_57 , V_58 ) ;
}
if ( V_57 )
return F_1 ( V_57 ) ;
V_62:
return 0 ;
V_61:
F_9 ( V_2 ) ;
goto V_62;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_52 * V_53 = F_25 ( V_2 -> V_20 ) ;
T_1 V_24 = 0 ;
if ( V_53 -> V_17 & V_63 && F_41 ( V_53 , V_2 , & V_24 ) )
F_28 ( V_53 -> V_7 , V_53 , F_24 ( V_2 ) -> V_64 , V_24 , false ) ;
return 0 ;
}
T_4 F_42 ( struct V_1 * * V_74 )
{
struct V_52 * V_53 ;
struct V_1 * V_2 = * V_74 ;
const unsigned char * V_50 = F_24 ( V_2 ) -> V_51 ;
T_5 * V_75 ;
if ( F_43 ( V_2 -> V_76 == V_77 ) )
return V_78 ;
if ( ! F_44 ( F_24 ( V_2 ) -> V_64 ) )
goto V_61;
V_2 = F_45 ( V_2 , V_79 ) ;
if ( ! V_2 )
return V_80 ;
V_53 = F_25 ( V_2 -> V_20 ) ;
if ( F_43 ( F_46 ( V_50 ) ) ) {
T_1 V_81 = V_53 -> V_7 -> V_82 ;
switch ( V_50 [ 5 ] ) {
case 0x00 :
if ( V_53 -> V_7 -> V_83 == V_84 ||
V_81 & ( 1u << V_50 [ 5 ] ) )
goto V_85;
break;
case 0x01 :
goto V_61;
default:
V_81 |= V_53 -> V_7 -> V_86 ;
if ( V_81 & ( 1u << V_50 [ 5 ] ) )
goto V_85;
}
if ( F_11 ( V_21 , V_22 , V_2 , V_2 -> V_20 ,
NULL , F_40 ) ) {
return V_80 ;
} else {
* V_74 = V_2 ;
return V_78 ;
}
}
V_85:
switch ( V_53 -> V_59 ) {
case V_87 :
V_75 = F_47 ( V_88 ) ;
if ( V_75 ) {
if ( (* V_75)( V_2 ) ) {
* V_74 = V_2 ;
return V_78 ;
}
V_50 = F_24 ( V_2 ) -> V_51 ;
}
case V_65 :
if ( F_48 ( V_53 -> V_7 -> V_20 -> V_89 , V_50 ) )
V_2 -> V_76 = V_90 ;
F_11 ( V_21 , V_91 , V_2 , V_2 -> V_20 , NULL ,
F_23 ) ;
break;
default:
V_61:
F_9 ( V_2 ) ;
}
return V_80 ;
}
