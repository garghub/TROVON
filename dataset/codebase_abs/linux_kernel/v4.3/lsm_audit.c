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
char V_53 [ sizeof( V_54 -> V_53 ) ] ;
F_17 ( sizeof( V_52 -> V_10 ) > sizeof( void * ) * 2 ) ;
F_14 ( V_46 , L_4 , F_18 ( V_54 ) ) ;
F_19 ( V_46 , memcpy ( V_53 , V_54 -> V_53 , sizeof( V_53 ) ) ) ;
switch ( V_52 -> type ) {
case V_55 :
return;
case V_56 :
F_14 ( V_46 , L_5 , V_52 -> V_10 . V_57 ) ;
break;
case V_58 :
F_14 ( V_46 , L_6 , V_52 -> V_10 . V_59 ) ;
break;
case V_60 : {
struct V_61 * V_61 ;
F_20 ( V_46 , L_7 , & V_52 -> V_10 . V_62 ) ;
V_61 = F_21 ( V_52 -> V_10 . V_62 . V_63 ) ;
if ( V_61 ) {
F_14 ( V_46 , L_8 ) ;
F_19 ( V_46 , V_61 -> V_64 -> V_65 ) ;
F_14 ( V_46 , L_9 , V_61 -> V_66 ) ;
}
break;
}
case V_67 : {
struct V_61 * V_61 ;
F_20 ( V_46 , L_7 , & V_52 -> V_10 . V_68 -> V_62 ) ;
V_61 = V_52 -> V_10 . V_68 -> V_62 . V_63 -> V_69 ;
if ( V_61 ) {
F_14 ( V_46 , L_8 ) ;
F_19 ( V_46 , V_61 -> V_64 -> V_65 ) ;
F_14 ( V_46 , L_9 , V_61 -> V_66 ) ;
}
F_14 ( V_46 , L_10 , V_52 -> V_10 . V_68 -> V_70 ) ;
break;
}
case V_71 : {
struct V_61 * V_61 ;
F_14 ( V_46 , L_11 ) ;
F_19 ( V_46 , V_52 -> V_10 . V_63 -> V_72 . V_73 ) ;
V_61 = F_21 ( V_52 -> V_10 . V_63 ) ;
if ( V_61 ) {
F_14 ( V_46 , L_8 ) ;
F_19 ( V_46 , V_61 -> V_64 -> V_65 ) ;
F_14 ( V_46 , L_9 , V_61 -> V_66 ) ;
}
break;
}
case V_74 : {
struct V_63 * V_63 ;
struct V_61 * V_61 ;
V_61 = V_52 -> V_10 . V_61 ;
V_63 = F_22 ( V_61 ) ;
if ( V_63 ) {
F_14 ( V_46 , L_11 ) ;
F_19 ( V_46 ,
V_63 -> V_72 . V_73 ) ;
F_23 ( V_63 ) ;
}
F_14 ( V_46 , L_8 ) ;
F_19 ( V_46 , V_61 -> V_64 -> V_65 ) ;
F_14 ( V_46 , L_9 , V_61 -> V_66 ) ;
break;
}
case V_75 : {
struct V_76 * V_77 = V_52 -> V_10 . V_77 ;
if ( V_77 ) {
T_4 V_78 = F_18 ( V_77 ) ;
if ( V_78 ) {
char V_53 [ sizeof( V_77 -> V_53 ) ] ;
F_14 ( V_46 , L_12 , V_78 ) ;
F_19 ( V_46 ,
memcpy ( V_53 , V_77 -> V_53 , sizeof( V_53 ) ) ) ;
}
}
break;
}
case V_79 :
if ( V_52 -> V_10 . V_11 -> V_80 ) {
struct V_81 * V_80 = V_52 -> V_10 . V_11 -> V_80 ;
struct V_82 * V_10 ;
int V_83 = 0 ;
char * V_84 = NULL ;
switch ( V_80 -> V_85 ) {
case V_86 : {
struct V_87 * V_88 = F_24 ( V_80 ) ;
F_15 ( V_46 , V_88 -> V_89 ,
V_88 -> V_90 ,
L_13 , L_14 ) ;
F_15 ( V_46 , V_88 -> V_91 ,
V_88 -> V_92 ,
L_15 , L_16 ) ;
break;
}
#if F_25 ( V_93 )
case V_94 : {
struct V_87 * V_88 = F_24 ( V_80 ) ;
F_12 ( V_46 , & V_80 -> V_95 ,
V_88 -> V_90 ,
L_13 , L_14 ) ;
F_12 ( V_46 , & V_80 -> V_96 ,
V_88 -> V_92 ,
L_15 , L_16 ) ;
break;
}
#endif
case V_97 :
V_10 = F_26 ( V_80 ) ;
if ( V_10 -> V_62 . V_63 ) {
F_20 ( V_46 , L_7 , & V_10 -> V_62 ) ;
break;
}
if ( ! V_10 -> V_48 )
break;
V_83 = V_10 -> V_48 -> V_83 - sizeof( short ) ;
V_84 = & V_10 -> V_48 -> V_73 -> V_98 [ 0 ] ;
F_14 ( V_46 , L_7 ) ;
if ( * V_84 )
F_19 ( V_46 , V_84 ) ;
else
F_27 ( V_46 , V_84 , V_83 ) ;
break;
}
}
switch ( V_52 -> V_10 . V_11 -> V_99 ) {
case V_86 :
F_15 ( V_46 , V_52 -> V_10 . V_11 -> V_12 . V_13 ,
V_52 -> V_10 . V_11 -> V_21 ,
L_17 , L_18 ) ;
F_15 ( V_46 , V_52 -> V_10 . V_11 -> V_12 . V_14 ,
V_52 -> V_10 . V_11 -> V_23 ,
L_19 , L_20 ) ;
break;
case V_94 :
F_12 ( V_46 , & V_52 -> V_10 . V_11 -> V_40 . V_13 ,
V_52 -> V_10 . V_11 -> V_21 ,
L_17 , L_18 ) ;
F_12 ( V_46 , & V_52 -> V_10 . V_11 -> V_40 . V_14 ,
V_52 -> V_10 . V_11 -> V_23 ,
L_19 , L_20 ) ;
break;
}
if ( V_52 -> V_10 . V_11 -> V_100 > 0 ) {
struct V_101 * V_102 ;
V_102 = F_28 ( & V_103 , V_52 -> V_10 . V_11 -> V_100 ) ;
if ( V_102 ) {
F_14 ( V_46 , L_21 , V_102 -> V_73 ) ;
F_29 ( V_102 ) ;
}
}
break;
#ifdef F_30
case V_104 :
F_14 ( V_46 , L_22 , V_52 -> V_10 . V_105 . V_106 ) ;
if ( V_52 -> V_10 . V_105 . V_107 ) {
F_14 ( V_46 , L_23 ) ;
F_19 ( V_46 , V_52 -> V_10 . V_105 . V_107 ) ;
}
break;
#endif
case V_108 :
F_14 ( V_46 , L_24 ) ;
F_19 ( V_46 , V_52 -> V_10 . V_109 ) ;
break;
}
}
void F_31 ( struct V_3 * V_52 ,
void (* F_32)( struct V_45 * , void * ) ,
void (* F_33)( struct V_45 * , void * ) )
{
struct V_45 * V_46 ;
if ( V_52 == NULL )
return;
V_46 = F_34 ( V_54 -> V_110 , V_111 | V_112 ,
V_113 ) ;
if ( V_46 == NULL )
return;
if ( F_32 )
F_32 ( V_46 , V_52 ) ;
F_16 ( V_46 , V_52 ) ;
if ( F_33 )
F_33 ( V_46 , V_52 ) ;
F_35 ( V_46 ) ;
}
