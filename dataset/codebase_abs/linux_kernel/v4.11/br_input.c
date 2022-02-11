static int
F_1 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
F_2 ( V_5 ) ;
return F_3 ( V_5 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_6 * V_7 , * V_8 = F_5 ( V_5 ) -> V_8 ;
struct V_9 * V_10 = F_6 ( V_8 ) ;
struct V_11 * V_12 ;
struct V_13 * V_14 = F_7 ( V_10 -> V_15 ) ;
F_8 ( & V_14 -> V_16 ) ;
V_14 -> V_17 ++ ;
V_14 -> V_18 += V_5 -> V_19 ;
F_9 ( & V_14 -> V_16 ) ;
V_12 = F_10 ( V_10 ) ;
if ( ! ( V_8 -> V_20 & V_21 ) &&
! F_11 ( V_12 , V_5 ) ) {
F_12 ( V_5 ) ;
return V_22 ;
}
V_7 = V_5 -> V_23 ;
V_5 -> V_23 = V_8 ;
V_5 = F_13 ( V_10 , NULL , V_12 , V_5 ) ;
if ( ! V_5 )
return V_22 ;
F_14 ( V_10 , NULL , V_5 , F_15 ( V_5 ) ,
V_24 ) ;
return F_16 ( V_25 , V_26 ,
F_17 ( V_7 ) , NULL , V_5 , V_7 , NULL ,
F_1 ) ;
}
static void F_18 ( struct V_4 * V_5 , struct V_9 * V_10 ,
T_1 V_27 , struct V_28 * V_29 )
{
struct V_6 * V_23 = V_10 -> V_23 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
T_2 * V_34 , * V_35 ;
T_3 V_36 , V_37 ;
F_5 ( V_5 ) -> V_38 = false ;
if ( ( V_23 -> V_20 & V_39 ) ||
! F_19 ( V_5 , F_20 ( V_23 ) ) )
return;
V_33 = F_21 ( V_5 ) ;
if ( V_33 -> V_40 != F_22 ( V_41 ) ||
V_33 -> V_42 != F_22 ( V_43 ) ||
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
if ( F_23 ( V_37 ) ||
F_24 ( V_37 ) )
return;
V_31 = F_25 ( & V_47 , & V_37 , V_23 ) ;
if ( V_31 ) {
struct V_48 * V_49 ;
if ( ! ( V_31 -> V_50 & V_51 ) ) {
F_26 ( V_31 ) ;
return;
}
V_49 = F_27 ( V_10 , V_31 -> V_52 , V_27 ) ;
if ( V_49 && ( ( V_29 -> V_20 & V_53 ) ||
( V_49 -> V_54 && ( V_49 -> V_54 -> V_20 & V_55 ) ) ) ) {
F_28 ( V_56 , V_57 , V_36 , V_5 -> V_23 , V_37 ,
V_35 , V_31 -> V_52 , V_35 ) ;
F_5 ( V_5 ) -> V_38 = true ;
}
F_26 ( V_31 ) ;
}
}
int F_29 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_28 * V_29 = F_30 ( V_5 -> V_23 ) ;
const unsigned char * V_58 = F_31 ( V_5 ) -> V_59 ;
enum V_60 V_61 = V_62 ;
struct V_48 * V_54 = NULL ;
struct V_63 * V_64 ;
bool V_65 , V_66 = false ;
struct V_9 * V_10 ;
T_1 V_27 = 0 ;
if ( ! V_29 || V_29 -> V_67 == V_68 )
goto V_69;
if ( ! F_32 ( V_29 -> V_10 , F_33 ( V_29 ) , V_5 , & V_27 ) )
goto V_70;
F_34 ( V_29 , V_5 ) ;
V_10 = V_29 -> V_10 ;
if ( V_29 -> V_20 & V_71 )
F_35 ( V_10 , V_29 , F_31 ( V_5 ) -> V_72 , V_27 , false ) ;
V_65 = ! ! ( V_10 -> V_23 -> V_20 & V_21 ) ;
if ( F_36 ( V_58 ) ) {
if ( F_37 ( V_58 ) ) {
V_61 = V_73 ;
V_65 = true ;
} else {
V_61 = V_74 ;
if ( F_38 ( V_10 , V_29 , V_5 , V_27 ) )
goto V_69;
}
}
if ( V_29 -> V_67 == V_75 )
goto V_69;
F_5 ( V_5 ) -> V_8 = V_10 -> V_23 ;
if ( F_39 ( V_76 ) && V_5 -> V_77 == F_22 ( V_57 ) )
F_18 ( V_5 , V_10 , V_27 , V_29 ) ;
switch ( V_61 ) {
case V_74 :
V_64 = F_40 ( V_10 , V_5 , V_27 ) ;
if ( ( V_64 || F_41 ( V_5 ) ) &&
F_42 ( V_10 , F_31 ( V_5 ) ) ) {
if ( ( V_64 && V_64 -> V_78 ) ||
F_43 ( V_10 ) ) {
V_65 = true ;
V_10 -> V_23 -> V_15 . V_79 ++ ;
}
V_66 = true ;
} else {
V_65 = true ;
V_10 -> V_23 -> V_15 . V_79 ++ ;
}
break;
case V_62 :
V_54 = F_27 ( V_10 , V_58 , V_27 ) ;
default:
break;
}
if ( V_54 ) {
unsigned long V_80 = V_81 ;
if ( V_54 -> V_82 )
return F_4 ( V_5 ) ;
if ( V_80 != V_54 -> V_83 )
V_54 -> V_83 = V_80 ;
F_44 ( V_54 -> V_54 , V_5 , V_65 , false ) ;
} else {
if ( ! V_66 )
F_45 ( V_10 , V_5 , V_61 , V_65 , false ) ;
else
F_46 ( V_64 , V_5 , V_65 , false ) ;
}
if ( V_65 )
return F_4 ( V_5 ) ;
V_70:
return 0 ;
V_69:
F_12 ( V_5 ) ;
goto V_70;
}
static void F_47 ( struct V_4 * V_5 )
{
struct V_28 * V_29 = F_30 ( V_5 -> V_23 ) ;
T_1 V_27 = 0 ;
if ( V_29 -> V_20 & V_71 && F_48 ( V_29 , V_5 , & V_27 ) )
F_35 ( V_29 -> V_10 , V_29 , F_31 ( V_5 ) -> V_72 , V_27 , false ) ;
}
static int F_49 ( struct V_1 * V_1 , struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_28 * V_29 = F_30 ( V_5 -> V_23 ) ;
F_47 ( V_5 ) ;
F_5 ( V_5 ) -> V_8 = V_29 -> V_10 -> V_23 ;
F_4 ( V_5 ) ;
return 0 ;
}
T_4 F_50 ( struct V_4 * * V_84 )
{
struct V_28 * V_29 ;
struct V_4 * V_5 = * V_84 ;
const unsigned char * V_58 = F_31 ( V_5 ) -> V_59 ;
T_5 * V_85 ;
if ( F_51 ( V_5 -> V_61 == V_86 ) )
return V_87 ;
if ( ! F_52 ( F_31 ( V_5 ) -> V_72 ) )
goto V_69;
V_5 = F_53 ( V_5 , V_88 ) ;
if ( ! V_5 )
return V_89 ;
V_29 = F_30 ( V_5 -> V_23 ) ;
if ( V_29 -> V_20 & V_90 ) {
if ( F_54 ( V_5 , V_29 ,
F_33 ( V_29 ) ) )
goto V_69;
}
if ( F_51 ( F_55 ( V_58 ) ) ) {
T_1 V_91 = V_29 -> V_10 -> V_92 ;
switch ( V_58 [ 5 ] ) {
case 0x00 :
if ( V_29 -> V_10 -> V_93 == V_94 ||
V_91 & ( 1u << V_58 [ 5 ] ) )
goto V_95;
* V_84 = V_5 ;
F_47 ( V_5 ) ;
return V_87 ;
case 0x01 :
goto V_69;
case 0x0E :
V_91 |= V_29 -> V_10 -> V_96 ;
if ( V_91 & ( 1u << V_58 [ 5 ] ) )
goto V_95;
* V_84 = V_5 ;
F_47 ( V_5 ) ;
return V_87 ;
default:
V_91 |= V_29 -> V_10 -> V_96 ;
if ( V_91 & ( 1u << V_58 [ 5 ] ) )
goto V_95;
}
F_16 ( V_25 , V_26 , F_17 ( V_5 -> V_23 ) ,
NULL , V_5 , V_5 -> V_23 , NULL , F_49 ) ;
return V_89 ;
}
V_95:
switch ( V_29 -> V_67 ) {
case V_97 :
V_85 = F_56 ( V_98 ) ;
if ( V_85 ) {
if ( (* V_85)( V_5 ) ) {
* V_84 = V_5 ;
return V_87 ;
}
V_58 = F_31 ( V_5 ) -> V_59 ;
}
case V_75 :
if ( F_57 ( V_29 -> V_10 -> V_23 -> V_99 , V_58 ) )
V_5 -> V_61 = V_100 ;
F_16 ( V_25 , V_101 ,
F_17 ( V_5 -> V_23 ) , NULL , V_5 , V_5 -> V_23 , NULL ,
F_29 ) ;
break;
default:
V_69:
F_12 ( V_5 ) ;
}
return V_89 ;
}
