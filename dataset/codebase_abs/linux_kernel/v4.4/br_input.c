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
return F_13 ( V_24 , V_25 ,
F_14 ( V_7 ) , NULL , V_5 , V_7 , NULL ,
F_1 ) ;
}
static void F_15 ( struct V_4 * V_5 , struct V_9 * V_10 ,
T_1 V_26 , struct V_27 * V_28 )
{
struct V_6 * V_23 = V_10 -> V_23 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
T_2 * V_33 , * V_34 ;
T_3 V_35 , V_36 ;
F_4 ( V_5 ) -> V_37 = false ;
if ( V_23 -> V_20 & V_38 )
return;
if ( ! F_16 ( V_5 , F_17 ( V_23 ) ) ) {
V_23 -> V_15 . V_39 ++ ;
return;
}
V_32 = F_18 ( V_5 ) ;
if ( V_32 -> V_40 != F_19 ( V_41 ) ||
V_32 -> V_42 != F_19 ( V_43 ) ||
V_32 -> V_44 != V_23 -> V_45 ||
V_32 -> V_46 != 4 )
return;
V_33 = ( T_2 * ) V_32 + sizeof( struct V_31 ) ;
V_34 = V_33 ;
V_33 += V_23 -> V_45 ;
memcpy ( & V_35 , V_33 , sizeof( V_35 ) ) ;
V_33 += sizeof( V_35 ) ;
V_33 += V_23 -> V_45 ;
memcpy ( & V_36 , V_33 , sizeof( V_36 ) ) ;
if ( F_20 ( V_36 ) ||
F_21 ( V_36 ) )
return;
V_30 = F_22 ( & V_47 , & V_36 , V_23 ) ;
if ( V_30 ) {
struct V_48 * V_49 ;
if ( ! ( V_30 -> V_50 & V_51 ) ) {
F_23 ( V_30 ) ;
return;
}
V_49 = F_24 ( V_10 , V_30 -> V_52 , V_26 ) ;
if ( V_49 && ( ( V_28 -> V_20 & V_53 ) ||
( V_49 -> V_54 && ( V_49 -> V_54 -> V_20 & V_55 ) ) ) ) {
F_25 ( V_56 , V_57 , V_35 , V_5 -> V_23 , V_36 ,
V_34 , V_30 -> V_52 , V_34 ) ;
F_4 ( V_5 ) -> V_37 = true ;
}
F_23 ( V_30 ) ;
}
}
int F_26 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
const unsigned char * V_58 = F_27 ( V_5 ) -> V_59 ;
struct V_27 * V_28 = F_28 ( V_5 -> V_23 ) ;
struct V_9 * V_10 ;
struct V_48 * V_54 ;
struct V_60 * V_61 ;
struct V_4 * V_62 ;
bool V_63 = true ;
T_1 V_26 = 0 ;
if ( ! V_28 || V_28 -> V_64 == V_65 )
goto V_66;
if ( ! F_29 ( V_28 -> V_10 , F_30 ( V_28 ) , V_5 , & V_26 ) )
goto V_67;
V_10 = V_28 -> V_10 ;
if ( V_28 -> V_20 & V_68 )
F_31 ( V_10 , V_28 , F_27 ( V_5 ) -> V_69 , V_26 , false ) ;
if ( ! F_32 ( V_58 ) && F_33 ( V_58 ) &&
F_34 ( V_10 , V_28 , V_5 , V_26 ) )
goto V_66;
if ( V_28 -> V_64 == V_70 )
goto V_66;
F_4 ( V_5 ) -> V_8 = V_10 -> V_23 ;
V_62 = NULL ;
if ( V_10 -> V_23 -> V_20 & V_21 )
V_62 = V_5 ;
V_54 = NULL ;
if ( F_35 ( V_71 ) && V_5 -> V_72 == F_19 ( V_57 ) )
F_15 ( V_5 , V_10 , V_26 , V_28 ) ;
if ( F_32 ( V_58 ) ) {
V_62 = V_5 ;
V_63 = false ;
} else if ( F_33 ( V_58 ) ) {
V_61 = F_36 ( V_10 , V_5 , V_26 ) ;
if ( ( V_61 || F_37 ( V_5 ) ) &&
F_38 ( V_10 , F_27 ( V_5 ) ) ) {
if ( ( V_61 && V_61 -> V_73 ) ||
F_39 ( V_10 ) )
V_62 = V_5 ;
F_40 ( V_61 , V_5 , V_62 ) ;
V_5 = NULL ;
if ( ! V_62 )
goto V_67;
} else
V_62 = V_5 ;
V_63 = false ;
V_10 -> V_23 -> V_15 . V_74 ++ ;
} else if ( ( V_54 = F_24 ( V_10 , V_58 , V_26 ) ) &&
V_54 -> V_75 ) {
V_62 = V_5 ;
V_5 = NULL ;
}
if ( V_5 ) {
if ( V_54 ) {
V_54 -> V_76 = V_77 ;
F_41 ( V_54 -> V_54 , V_5 , V_62 ) ;
} else
F_42 ( V_10 , V_5 , V_62 , V_63 ) ;
}
if ( V_62 )
return F_3 ( V_62 ) ;
V_67:
return 0 ;
V_66:
F_11 ( V_5 ) ;
goto V_67;
}
static int F_43 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_27 * V_28 = F_28 ( V_5 -> V_23 ) ;
T_1 V_26 = 0 ;
if ( V_28 -> V_20 & V_68 && F_44 ( V_28 , V_5 , & V_26 ) )
F_31 ( V_28 -> V_10 , V_28 , F_27 ( V_5 ) -> V_69 , V_26 , false ) ;
return 0 ;
}
T_4 F_45 ( struct V_4 * * V_78 )
{
struct V_27 * V_28 ;
struct V_4 * V_5 = * V_78 ;
const unsigned char * V_58 = F_27 ( V_5 ) -> V_59 ;
T_5 * V_79 ;
if ( F_46 ( V_5 -> V_80 == V_81 ) )
return V_82 ;
if ( ! F_47 ( F_27 ( V_5 ) -> V_69 ) )
goto V_66;
V_5 = F_48 ( V_5 , V_83 ) ;
if ( ! V_5 )
return V_84 ;
V_28 = F_28 ( V_5 -> V_23 ) ;
if ( F_46 ( F_49 ( V_58 ) ) ) {
T_1 V_85 = V_28 -> V_10 -> V_86 ;
switch ( V_58 [ 5 ] ) {
case 0x00 :
if ( V_28 -> V_10 -> V_87 == V_88 ||
V_85 & ( 1u << V_58 [ 5 ] ) )
goto V_89;
break;
case 0x01 :
goto V_66;
default:
V_85 |= V_28 -> V_10 -> V_90 ;
if ( V_85 & ( 1u << V_58 [ 5 ] ) )
goto V_89;
}
if ( F_13 ( V_24 , V_25 ,
F_14 ( V_5 -> V_23 ) , NULL , V_5 , V_5 -> V_23 , NULL ,
F_43 ) ) {
return V_84 ;
} else {
* V_78 = V_5 ;
return V_82 ;
}
}
V_89:
switch ( V_28 -> V_64 ) {
case V_91 :
V_79 = F_50 ( V_92 ) ;
if ( V_79 ) {
if ( (* V_79)( V_5 ) ) {
* V_78 = V_5 ;
return V_82 ;
}
V_58 = F_27 ( V_5 ) -> V_59 ;
}
case V_70 :
if ( F_51 ( V_28 -> V_10 -> V_23 -> V_93 , V_58 ) )
V_5 -> V_80 = V_94 ;
F_13 ( V_24 , V_95 ,
F_14 ( V_5 -> V_23 ) , NULL , V_5 , V_5 -> V_23 , NULL ,
F_26 ) ;
break;
default:
V_66:
F_11 ( V_5 ) ;
}
return V_84 ;
}
