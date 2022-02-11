int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 * V_5 )
{
int V_6 = 0 ;
struct V_7 * V_8 ;
V_8 = F_2 ( V_2 ) ;
if ( V_8 == NULL )
return - V_9 ;
V_4 -> V_10 . V_11 -> V_12 . V_13 = V_8 -> V_13 ;
V_4 -> V_10 . V_11 -> V_12 . V_14 = V_8 -> V_14 ;
if ( V_5 )
* V_5 = V_8 -> V_15 ;
if ( F_3 ( V_8 -> V_16 ) & V_17 )
return 0 ;
switch ( V_8 -> V_15 ) {
case V_18 : {
struct V_19 * V_20 = F_4 ( V_2 ) ;
if ( V_20 == NULL )
break;
V_4 -> V_10 . V_11 -> V_21 = V_20 -> V_22 ;
V_4 -> V_10 . V_11 -> V_23 = V_20 -> V_24 ;
break;
}
case V_25 : {
struct V_26 * V_27 = F_5 ( V_2 ) ;
if ( V_27 == NULL )
break;
V_4 -> V_10 . V_11 -> V_21 = V_27 -> V_22 ;
V_4 -> V_10 . V_11 -> V_23 = V_27 -> V_24 ;
break;
}
case V_28 : {
struct V_29 * V_30 = V_29 ( V_2 ) ;
if ( V_30 == NULL )
break;
V_4 -> V_10 . V_11 -> V_21 = V_30 -> V_31 ;
V_4 -> V_10 . V_11 -> V_23 = V_30 -> V_32 ;
break;
}
case V_33 : {
struct V_34 * V_35 = F_6 ( V_2 ) ;
if ( V_35 == NULL )
break;
V_4 -> V_10 . V_11 -> V_21 = V_35 -> V_22 ;
V_4 -> V_10 . V_11 -> V_23 = V_35 -> V_24 ;
break;
}
default:
V_6 = - V_9 ;
}
return V_6 ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 * V_5 )
{
int V_36 , V_6 = 0 ;
struct V_37 * V_38 ;
T_1 V_39 ;
T_2 V_16 ;
V_38 = F_8 ( V_2 ) ;
if ( V_38 == NULL )
return - V_9 ;
V_4 -> V_10 . V_11 -> V_40 . V_13 = V_38 -> V_13 ;
V_4 -> V_10 . V_11 -> V_40 . V_14 = V_38 -> V_14 ;
V_6 = 0 ;
V_36 = F_9 ( V_2 ) ;
V_36 += sizeof( * V_38 ) ;
V_39 = V_38 -> V_39 ;
V_36 = F_10 ( V_2 , V_36 , & V_39 , & V_16 ) ;
if ( V_36 < 0 )
return 0 ;
if ( V_5 )
* V_5 = V_39 ;
switch ( V_39 ) {
case V_18 : {
struct V_19 V_41 , * V_20 ;
V_20 = F_11 ( V_2 , V_36 , sizeof( V_41 ) , & V_41 ) ;
if ( V_20 == NULL )
break;
V_4 -> V_10 . V_11 -> V_21 = V_20 -> V_22 ;
V_4 -> V_10 . V_11 -> V_23 = V_20 -> V_24 ;
break;
}
case V_25 : {
struct V_26 V_42 , * V_27 ;
V_27 = F_11 ( V_2 , V_36 , sizeof( V_42 ) , & V_42 ) ;
if ( V_27 == NULL )
break;
V_4 -> V_10 . V_11 -> V_21 = V_27 -> V_22 ;
V_4 -> V_10 . V_11 -> V_23 = V_27 -> V_24 ;
break;
}
case V_28 : {
struct V_29 V_43 , * V_30 ;
V_30 = F_11 ( V_2 , V_36 , sizeof( V_43 ) , & V_43 ) ;
if ( V_30 == NULL )
break;
V_4 -> V_10 . V_11 -> V_21 = V_30 -> V_31 ;
V_4 -> V_10 . V_11 -> V_23 = V_30 -> V_32 ;
break;
}
case V_33 : {
struct V_34 V_44 , * V_35 ;
V_35 = F_11 ( V_2 , V_36 , sizeof( V_44 ) , & V_44 ) ;
if ( V_35 == NULL )
break;
V_4 -> V_10 . V_11 -> V_21 = V_35 -> V_22 ;
V_4 -> V_10 . V_11 -> V_23 = V_35 -> V_24 ;
break;
}
default:
V_6 = - V_9 ;
}
return V_6 ;
}
static inline void F_12 ( struct V_45 * V_46 ,
struct V_47 * V_48 , T_2 V_49 ,
char * V_50 , char * V_51 )
{
if ( ! F_13 ( V_48 ) )
F_14 ( V_46 , L_1 , V_50 , V_48 ) ;
if ( V_49 )
F_14 ( V_46 , L_2 , V_51 , F_3 ( V_49 ) ) ;
}
static inline void F_15 ( struct V_45 * V_46 , T_3 V_48 ,
T_2 V_49 , char * V_50 , char * V_51 )
{
if ( V_48 )
F_14 ( V_46 , L_3 , V_50 , & V_48 ) ;
if ( V_49 )
F_14 ( V_46 , L_2 , V_51 , F_3 ( V_49 ) ) ;
}
static void F_16 ( struct V_45 * V_46 ,
struct V_3 * V_52 )
{
struct V_53 * V_54 = V_55 ;
if ( V_52 -> V_54 )
V_54 = V_52 -> V_54 ;
if ( V_54 && V_54 -> V_56 ) {
F_14 ( V_46 , L_4 , V_54 -> V_56 ) ;
F_17 ( V_46 , V_54 -> V_57 ) ;
}
switch ( V_52 -> type ) {
case V_58 :
return;
case V_59 :
F_14 ( V_46 , L_5 , V_52 -> V_10 . V_60 ) ;
break;
case V_61 :
F_14 ( V_46 , L_6 , V_52 -> V_10 . V_62 ) ;
break;
case V_63 : {
struct V_64 * V_64 ;
F_18 ( V_46 , L_7 , & V_52 -> V_10 . V_65 ) ;
V_64 = V_52 -> V_10 . V_65 . V_66 -> V_67 ;
if ( V_64 ) {
F_14 ( V_46 , L_8 ) ;
F_17 ( V_46 , V_64 -> V_68 -> V_69 ) ;
F_14 ( V_46 , L_9 , V_64 -> V_70 ) ;
}
break;
}
case V_71 : {
struct V_64 * V_64 ;
F_14 ( V_46 , L_10 ) ;
F_17 ( V_46 , V_52 -> V_10 . V_66 -> V_72 . V_73 ) ;
V_64 = V_52 -> V_10 . V_66 -> V_67 ;
if ( V_64 ) {
F_14 ( V_46 , L_8 ) ;
F_17 ( V_46 , V_64 -> V_68 -> V_69 ) ;
F_14 ( V_46 , L_9 , V_64 -> V_70 ) ;
}
break;
}
case V_74 : {
struct V_66 * V_66 ;
struct V_64 * V_64 ;
V_64 = V_52 -> V_10 . V_64 ;
V_66 = F_19 ( V_64 ) ;
if ( V_66 ) {
F_14 ( V_46 , L_10 ) ;
F_17 ( V_46 ,
V_66 -> V_72 . V_73 ) ;
F_20 ( V_66 ) ;
}
F_14 ( V_46 , L_8 ) ;
F_17 ( V_46 , V_64 -> V_68 -> V_69 ) ;
F_14 ( V_46 , L_9 , V_64 -> V_70 ) ;
break;
}
case V_75 :
V_54 = V_52 -> V_10 . V_54 ;
if ( V_54 && V_54 -> V_56 ) {
F_14 ( V_46 , L_4 , V_54 -> V_56 ) ;
F_17 ( V_46 , V_54 -> V_57 ) ;
}
break;
case V_76 :
if ( V_52 -> V_10 . V_11 -> V_77 ) {
struct V_78 * V_77 = V_52 -> V_10 . V_11 -> V_77 ;
struct V_79 * V_10 ;
int V_80 = 0 ;
char * V_81 = NULL ;
switch ( V_77 -> V_82 ) {
case V_83 : {
struct V_84 * V_85 = F_21 ( V_77 ) ;
F_15 ( V_46 , V_85 -> V_86 ,
V_85 -> V_87 ,
L_11 , L_12 ) ;
F_15 ( V_46 , V_85 -> V_88 ,
V_85 -> V_89 ,
L_13 , L_14 ) ;
break;
}
case V_90 : {
struct V_84 * V_85 = F_21 ( V_77 ) ;
struct V_91 * V_92 = F_22 ( V_77 ) ;
F_12 ( V_46 , & V_92 -> V_93 ,
V_85 -> V_87 ,
L_11 , L_12 ) ;
F_12 ( V_46 , & V_92 -> V_14 ,
V_85 -> V_89 ,
L_13 , L_14 ) ;
break;
}
case V_94 :
V_10 = F_23 ( V_77 ) ;
if ( V_10 -> V_65 . V_66 ) {
F_18 ( V_46 , L_7 , & V_10 -> V_65 ) ;
break;
}
if ( ! V_10 -> V_48 )
break;
V_80 = V_10 -> V_48 -> V_80 - sizeof( short ) ;
V_81 = & V_10 -> V_48 -> V_73 -> V_95 [ 0 ] ;
F_14 ( V_46 , L_7 ) ;
if ( * V_81 )
F_17 ( V_46 , V_81 ) ;
else
F_24 ( V_46 , V_81 , V_80 ) ;
break;
}
}
switch ( V_52 -> V_10 . V_11 -> V_96 ) {
case V_83 :
F_15 ( V_46 , V_52 -> V_10 . V_11 -> V_12 . V_13 ,
V_52 -> V_10 . V_11 -> V_21 ,
L_15 , L_16 ) ;
F_15 ( V_46 , V_52 -> V_10 . V_11 -> V_12 . V_14 ,
V_52 -> V_10 . V_11 -> V_23 ,
L_17 , L_18 ) ;
break;
case V_90 :
F_12 ( V_46 , & V_52 -> V_10 . V_11 -> V_40 . V_13 ,
V_52 -> V_10 . V_11 -> V_21 ,
L_15 , L_16 ) ;
F_12 ( V_46 , & V_52 -> V_10 . V_11 -> V_40 . V_14 ,
V_52 -> V_10 . V_11 -> V_23 ,
L_17 , L_18 ) ;
break;
}
if ( V_52 -> V_10 . V_11 -> V_97 > 0 ) {
struct V_98 * V_99 ;
V_99 = F_25 ( & V_100 , V_52 -> V_10 . V_11 -> V_97 ) ;
if ( V_99 ) {
F_14 ( V_46 , L_19 , V_99 -> V_73 ) ;
F_26 ( V_99 ) ;
}
}
break;
#ifdef F_27
case V_101 :
F_14 ( V_46 , L_20 , V_52 -> V_10 . V_102 . V_103 ) ;
if ( V_52 -> V_10 . V_102 . V_104 ) {
F_14 ( V_46 , L_21 ) ;
F_17 ( V_46 , V_52 -> V_10 . V_102 . V_104 ) ;
}
break;
#endif
case V_105 :
F_14 ( V_46 , L_22 ) ;
F_17 ( V_46 , V_52 -> V_10 . V_106 ) ;
break;
}
}
void F_28 ( struct V_3 * V_52 ,
void (* F_29)( struct V_45 * , void * ) ,
void (* F_30)( struct V_45 * , void * ) )
{
struct V_45 * V_46 ;
if ( V_52 == NULL )
return;
V_46 = F_31 ( V_55 -> V_107 , V_108 , V_109 ) ;
if ( V_46 == NULL )
return;
if ( F_29 )
F_29 ( V_46 , V_52 ) ;
F_16 ( V_46 , V_52 ) ;
if ( F_30 )
F_30 ( V_46 , V_52 ) ;
F_32 ( V_46 ) ;
}
