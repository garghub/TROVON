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
return F_11 ( V_21 , V_22 , NULL , V_2 ,
V_4 , NULL ,
V_23 ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_1 V_24 , struct V_25 * V_26 )
{
struct V_3 * V_20 = V_7 -> V_20 ;
struct V_27 * V_28 ;
struct V_29 * V_30 ;
T_2 * V_31 , * V_32 ;
T_3 V_33 , V_34 ;
F_2 ( V_2 ) -> V_35 = false ;
if ( V_20 -> V_17 & V_36 )
return;
if ( ! F_13 ( V_2 , F_14 ( V_20 ) ) ) {
V_20 -> V_10 . V_37 ++ ;
return;
}
V_30 = F_15 ( V_2 ) ;
if ( V_30 -> V_38 != F_16 ( V_39 ) ||
V_30 -> V_40 != F_16 ( V_41 ) ||
V_30 -> V_42 != V_20 -> V_43 ||
V_30 -> V_44 != 4 )
return;
V_31 = ( T_2 * ) V_30 + sizeof( struct V_29 ) ;
V_32 = V_31 ;
V_31 += V_20 -> V_43 ;
memcpy ( & V_33 , V_31 , sizeof( V_33 ) ) ;
V_31 += sizeof( V_33 ) ;
V_31 += V_20 -> V_43 ;
memcpy ( & V_34 , V_31 , sizeof( V_34 ) ) ;
if ( F_17 ( V_34 ) ||
F_18 ( V_34 ) )
return;
V_28 = F_19 ( & V_45 , & V_34 , V_20 ) ;
if ( V_28 ) {
struct V_46 * V_47 ;
if ( ! ( V_28 -> V_48 & V_49 ) ) {
F_20 ( V_28 ) ;
return;
}
V_47 = F_21 ( V_7 , V_28 -> V_50 , V_24 ) ;
if ( V_47 && ( ( V_26 -> V_17 & V_51 ) ||
( V_47 -> V_52 && ( V_47 -> V_52 -> V_17 & V_53 ) ) ) ) {
F_22 ( V_54 , V_55 , V_33 , V_2 -> V_20 , V_34 ,
V_32 , V_28 -> V_50 , V_32 ) ;
F_2 ( V_2 ) -> V_35 = true ;
}
F_20 ( V_28 ) ;
}
}
int F_23 ( struct V_56 * V_57 , struct V_1 * V_2 )
{
const unsigned char * V_58 = F_24 ( V_2 ) -> V_59 ;
struct V_25 * V_26 = F_25 ( V_2 -> V_20 ) ;
struct V_6 * V_7 ;
struct V_46 * V_52 ;
struct V_60 * V_61 ;
struct V_1 * V_62 ;
bool V_63 = true ;
T_1 V_24 = 0 ;
if ( ! V_26 || V_26 -> V_64 == V_65 )
goto V_66;
if ( ! F_26 ( V_26 -> V_7 , F_27 ( V_26 ) , V_2 , & V_24 ) )
goto V_67;
V_7 = V_26 -> V_7 ;
if ( V_26 -> V_17 & V_68 )
F_28 ( V_7 , V_26 , F_24 ( V_2 ) -> V_69 , V_24 , false ) ;
if ( ! F_29 ( V_58 ) && F_30 ( V_58 ) &&
F_31 ( V_7 , V_26 , V_2 , V_24 ) )
goto V_66;
if ( V_26 -> V_64 == V_70 )
goto V_66;
F_2 ( V_2 ) -> V_5 = V_7 -> V_20 ;
V_62 = NULL ;
if ( V_7 -> V_20 -> V_17 & V_18 )
V_62 = V_2 ;
V_52 = NULL ;
if ( F_32 ( V_71 ) && V_2 -> V_72 == F_16 ( V_55 ) )
F_12 ( V_2 , V_7 , V_24 , V_26 ) ;
if ( F_29 ( V_58 ) ) {
V_62 = V_2 ;
V_63 = false ;
} else if ( F_30 ( V_58 ) ) {
V_61 = F_33 ( V_7 , V_2 , V_24 ) ;
if ( ( V_61 || F_34 ( V_2 ) ) &&
F_35 ( V_7 , F_24 ( V_2 ) ) ) {
if ( ( V_61 && V_61 -> V_73 ) ||
F_36 ( V_7 ) )
V_62 = V_2 ;
F_37 ( V_61 , V_2 , V_62 ) ;
V_2 = NULL ;
if ( ! V_62 )
goto V_67;
} else
V_62 = V_2 ;
V_63 = false ;
V_7 -> V_20 -> V_10 . V_74 ++ ;
} else if ( ( V_52 = F_21 ( V_7 , V_58 , V_24 ) ) &&
V_52 -> V_75 ) {
V_62 = V_2 ;
V_2 = NULL ;
}
if ( V_2 ) {
if ( V_52 ) {
V_52 -> V_76 = V_77 ;
F_38 ( V_52 -> V_52 , V_2 , V_62 ) ;
} else
F_39 ( V_7 , V_2 , V_62 , V_63 ) ;
}
if ( V_62 )
return F_1 ( V_62 ) ;
V_67:
return 0 ;
V_66:
F_9 ( V_2 ) ;
goto V_67;
}
static int F_40 ( struct V_56 * V_57 , struct V_1 * V_2 )
{
struct V_25 * V_26 = F_25 ( V_2 -> V_20 ) ;
T_1 V_24 = 0 ;
if ( V_26 -> V_17 & V_68 && F_41 ( V_26 , V_2 , & V_24 ) )
F_28 ( V_26 -> V_7 , V_26 , F_24 ( V_2 ) -> V_69 , V_24 , false ) ;
return 0 ;
}
T_4 F_42 ( struct V_1 * * V_78 )
{
struct V_25 * V_26 ;
struct V_1 * V_2 = * V_78 ;
const unsigned char * V_58 = F_24 ( V_2 ) -> V_59 ;
T_5 * V_79 ;
if ( F_43 ( V_2 -> V_80 == V_81 ) )
return V_82 ;
if ( ! F_44 ( F_24 ( V_2 ) -> V_69 ) )
goto V_66;
V_2 = F_45 ( V_2 , V_83 ) ;
if ( ! V_2 )
return V_84 ;
V_26 = F_25 ( V_2 -> V_20 ) ;
if ( F_43 ( F_46 ( V_58 ) ) ) {
T_1 V_85 = V_26 -> V_7 -> V_86 ;
switch ( V_58 [ 5 ] ) {
case 0x00 :
if ( V_26 -> V_7 -> V_87 == V_88 ||
V_85 & ( 1u << V_58 [ 5 ] ) )
goto V_89;
break;
case 0x01 :
goto V_66;
default:
V_85 |= V_26 -> V_7 -> V_90 ;
if ( V_85 & ( 1u << V_58 [ 5 ] ) )
goto V_89;
}
if ( F_11 ( V_21 , V_22 , NULL , V_2 ,
V_2 -> V_20 , NULL , F_40 ) ) {
return V_84 ;
} else {
* V_78 = V_2 ;
return V_82 ;
}
}
V_89:
switch ( V_26 -> V_64 ) {
case V_91 :
V_79 = F_47 ( V_92 ) ;
if ( V_79 ) {
if ( (* V_79)( V_2 ) ) {
* V_78 = V_2 ;
return V_82 ;
}
V_58 = F_24 ( V_2 ) -> V_59 ;
}
case V_70 :
if ( F_48 ( V_26 -> V_7 -> V_20 -> V_93 , V_58 ) )
V_2 -> V_80 = V_94 ;
F_11 ( V_21 , V_95 , NULL , V_2 ,
V_2 -> V_20 , NULL ,
F_23 ) ;
break;
default:
V_66:
F_9 ( V_2 ) ;
}
return V_84 ;
}
