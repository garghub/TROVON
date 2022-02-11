static int
F_1 ( T_1 * V_1 , void * V_2 , T_2 * V_3 , int V_4 , int V_5 , int V_6 )
{
enum V_7 type = (enum V_7 ) V_4 ;
T_3 * V_8 = ( T_3 * ) V_2 ;
T_2 * V_9 = F_2 ( V_3 ) ;
T_4 V_10 ;
switch ( type ) {
case V_11 :
break;
case V_12 :
if ( V_6 == 4 ) {
F_3 ( V_3 , V_13 . V_14 , V_1 , V_5 , 4 , V_8 -> V_15 , & V_10 ) ;
F_4 ( V_3 , L_1 , V_10 ) ;
F_4 ( V_9 , L_2 , V_10 ) ;
V_5 += 4 ;
}
break;
case V_16 :
if ( V_6 == 4 ) {
T_5 V_17 ;
F_5 ( V_3 , V_1 , V_5 , V_18 . V_14 , V_19 , V_20 , V_8 -> V_15 , V_21 , & V_17 ) ;
F_4 ( V_3 , L_3 , ( T_4 ) V_17 ) ;
F_4 ( V_9 , L_4 , ( T_4 ) V_17 ) ;
V_5 += 4 ;
}
break;
}
return V_5 ;
}
static int
F_6 ( T_1 * V_1 , void * V_2 , T_2 * V_3 , int V_4 , int V_5 , int V_6 )
{
enum V_22 type = (enum V_22 ) V_4 ;
T_3 * V_8 = ( T_3 * ) V_2 ;
T_2 * V_9 = F_2 ( V_3 ) ;
T_4 V_10 ;
const T_6 * V_23 ;
switch ( type ) {
case V_24 :
break;
case V_25 :
F_7 ( V_3 , V_26 . V_14 , V_1 , V_5 , V_6 , V_27 , F_8 () , & V_23 ) ;
F_4 ( V_3 , L_5 , V_23 ) ;
F_4 ( V_9 , L_6 , V_23 ) ;
V_5 += V_6 ;
break;
case V_28 :
if ( V_6 == 4 ) {
F_3 ( V_3 , V_29 . V_14 , V_1 , V_5 , 4 , V_8 -> V_15 , & V_10 ) ;
F_4 ( V_3 , L_1 , V_10 ) ;
F_4 ( V_9 , L_2 , V_10 ) ;
V_5 += 4 ;
}
break;
}
return V_5 ;
}
static int
F_9 ( T_1 * V_1 , void * V_2 , T_2 * V_3 , int V_4 , int V_5 , int V_6 )
{
enum V_30 type = (enum V_30 ) V_4 ;
T_3 * V_8 = ( T_3 * ) V_2 ;
T_4 V_10 ;
switch ( type ) {
case V_31 :
break;
case V_32 :
if ( V_6 == 2 ) {
F_3 ( V_3 , V_33 . V_14 , V_1 , V_5 , 2 , V_8 -> V_15 , & V_10 ) ;
F_4 ( V_3 , L_7 , V_10 ) ;
V_8 -> V_34 = V_10 ;
V_5 += 2 ;
}
break;
case V_35 :
F_7 ( V_3 , V_36 . V_14 , V_1 , V_5 , V_6 , V_27 , F_8 () , & V_8 -> V_37 ) ;
F_4 ( V_3 , L_5 , V_8 -> V_37 ) ;
V_5 += V_6 ;
break;
case V_38 :
if ( V_6 == 4 ) {
F_3 ( V_3 , V_39 . V_14 , V_1 , V_5 , 4 , V_8 -> V_15 , & V_10 ) ;
F_4 ( V_3 , L_1 , V_10 ) ;
V_5 += 4 ;
}
break;
case V_40 :
if ( V_6 == 4 ) {
F_3 ( V_3 , V_41 . V_14 , V_1 , V_5 , 4 , V_8 -> V_15 , & V_10 ) ;
F_4 ( V_3 , L_1 , V_10 ) ;
V_5 += 4 ;
}
break;
case V_42 :
if ( V_6 == 4 ) {
F_3 ( V_3 , V_43 . V_14 , V_1 , V_5 , 4 , V_8 -> V_15 , & V_10 ) ;
F_4 ( V_3 , L_1 , V_10 ) ;
V_5 += 4 ;
}
break;
case V_44 :
V_5 = F_10 ( V_1 , & V_45 , V_46 , V_47 , V_8 , V_8 -> V_2 , V_3 , V_5 , V_6 , F_1 ) ;
break;
case V_48 :
V_5 = F_10 ( V_1 , & V_49 , V_50 , V_51 , V_8 , V_8 -> V_2 , V_3 , V_5 , V_6 , F_6 ) ;
break;
}
return V_5 ;
}
static int
F_11 ( T_1 * V_1 , T_7 * T_8 V_52 , T_2 * V_3 V_52 , void * V_2 )
{
T_9 * V_53 = ( T_9 * ) V_2 ;
T_3 V_8 ;
int V_5 ;
if ( ! V_53 ) {
return 0 ;
}
V_8 . V_2 = V_53 -> V_2 ;
V_8 . V_15 = V_53 -> V_15 ;
V_8 . V_34 = 0 ;
V_8 . V_37 = NULL ;
V_5 = F_12 ( V_1 , V_53 , & V_54 ) ;
F_13 ( V_1 , & V_55 , V_56 , & V_8 , V_8 . V_2 , V_53 -> V_57 , V_5 , - 1 , F_9 ) ;
if ( V_8 . V_34 && V_8 . V_34 != V_58 && V_8 . V_37 ) {
F_14 ( V_59 , F_15 ( V_8 . V_34 ) , F_16 ( F_17 () , V_8 . V_37 ) ) ;
}
return F_18 ( V_1 ) ;
}
int F_12 ( T_1 * V_1 , T_9 * V_53 , T_10 * V_60 )
{
int V_5 = 0 ;
if ( ! V_60 ) {
V_60 = & V_61 ;
}
F_19 ( V_53 -> V_57 , V_60 , V_1 , V_5 , 1 , V_62 ) ;
V_5 ++ ;
F_19 ( V_53 -> V_57 , & V_63 , V_1 , V_5 , 1 , V_62 ) ;
V_5 ++ ;
F_19 ( V_53 -> V_57 , & V_64 , V_1 , V_5 , 2 , V_53 -> V_15 ) ;
V_5 += 2 ;
return V_5 ;
}
static int
F_20 ( T_1 * V_1 , T_7 * T_8 , T_2 * V_3 , void * V_65 )
{
struct V_66 * V_2 = (struct V_66 * ) V_65 ;
T_9 V_8 ;
T_2 * V_67 ;
T_11 * V_68 , * V_69 ;
const char * V_37 ;
T_1 * V_70 ;
int V_5 = 0 ;
F_21 ( V_2 && V_2 -> V_71 == V_72 ) ;
F_22 ( T_8 -> V_73 , V_74 , L_8 ) ;
F_23 ( T_8 -> V_73 , V_75 ) ;
V_68 = F_19 ( V_3 , F_24 ( V_76 ) , V_1 , 0 , - 1 , V_62 ) ;
V_67 = F_25 ( V_68 , V_77 ) ;
V_5 = F_26 ( V_1 , V_67 , V_5 , V_2 -> V_15 , & V_78 , & V_69 ) ;
V_37 = ( const char * ) F_27 ( V_59 , F_15 ( V_2 -> type ) ) ;
F_4 ( V_69 , L_9 , V_37 ? V_37 : L_10 ) ;
V_8 . V_2 = V_2 ;
V_8 . V_15 = V_2 -> V_15 ;
V_8 . V_57 = V_67 ;
V_8 . V_79 = F_28 ( V_1 , V_5 ) ;
V_70 = F_29 ( V_1 , V_5 ) ;
if ( F_30 ( V_1 , V_5 + 4 ) ) {
if ( V_37 ) {
int V_80 ;
V_80 = F_31 ( V_81 , V_37 , V_70 , T_8 , V_3 , & V_8 ) ;
if ( V_80 ) {
return V_80 ;
}
}
}
V_5 = F_12 ( V_70 , & V_8 , NULL ) ;
if ( F_30 ( V_1 , V_5 ) ) {
V_70 = F_29 ( V_1 , V_5 ) ;
F_32 ( V_70 , T_8 , V_3 ) ;
}
return V_5 ;
}
static void
F_33 ( void )
{
F_14 ( V_59 , F_15 ( V_58 ) , V_82 ) ;
}
void
F_34 ( void )
{
#ifndef F_35
static T_10 * V_83 [] = {
& V_78 ,
& V_61 ,
& V_63 ,
& V_64 ,
& V_55 ,
& V_54 ,
& V_33 ,
& V_36 ,
& V_39 ,
& V_41 ,
& V_43 ,
& V_45 ,
& V_49 ,
& V_13 ,
& V_18 ,
& V_84 ,
& V_85 ,
& V_86 ,
& V_87 ,
& V_88 ,
& V_26 ,
& V_29 ,
} ;
#endif
static T_12 * V_89 [] = {
& V_77 ,
& V_56 ,
& V_46 ,
& V_47 ,
& V_19 ,
& V_50 ,
& V_51 ,
& V_90 ,
} ;
V_76 = F_36 ( L_11 , L_12 , L_12 ) ;
V_91 = F_24 ( V_76 ) ;
F_37 ( V_76 , V_83 , F_38 ( V_83 ) ) ;
F_39 ( V_89 , F_38 ( V_89 ) ) ;
V_92 = F_40 ( F_20 , V_76 ) ;
V_93 = F_40 ( F_11 , V_76 ) ;
V_81 = F_41 (
L_13 ,
L_14 ,
V_76 , V_94 ,
V_95
) ;
V_59 = F_42 ( F_43 () , F_17 () , V_96 , V_97 ) ;
F_44 ( F_33 ) ;
}
void
F_45 ( void )
{
F_46 ( L_13 , V_82 , V_93 ) ;
F_47 ( L_15 , V_98 , V_92 ) ;
}
