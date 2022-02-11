static inline int
F_1 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
return ( ( V_3 -> V_4 . V_5 . V_6 ==
V_2 -> V_4 . V_5 . V_6 ) &&
( V_3 -> V_7 == V_2 -> V_7 ) ) ;
}
static inline int
F_2 ( struct V_1 * V_2 , struct V_1 * V_3 )
{
return ( ( V_3 -> V_4 . V_5 . V_8 <=
V_2 -> V_4 . V_5 . V_9 ) &&
( V_3 -> V_4 . V_5 . V_9 >=
V_2 -> V_4 . V_5 . V_8 ) ) ;
}
static inline void
F_3 ( struct V_1 * V_2 , enum V_10 V_11 , T_1 V_12 )
{
F_4 ( V_2 , L_1 ,
V_11 , V_12 ) ;
F_5 ( F_6 ( & V_2 -> V_13 ) ) ;
F_7 ( & V_2 -> V_14 ) ;
if ( V_12 == V_15 ) {
V_2 -> V_16 |= V_17 | V_18 ;
F_8 ( V_2 , V_11 ) ;
}
F_9 ( V_2 ) ;
}
static int F_10 ( struct V_1 * V_19 , T_1 * V_12 ,
int V_20 , enum V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = V_19 -> V_27 ;
struct V_28 * V_29 = F_11 ( V_26 ) ;
struct V_23 * V_30 ;
struct V_23 * V_31 = NULL ;
struct V_1 * V_2 = NULL ;
struct V_1 * V_3 = V_19 ;
struct V_1 * V_32 = NULL ;
enum V_10 V_11 = V_19 -> V_33 ;
int V_34 = ( V_11 == V_35 ) ;
int V_36 = 0 ;
int V_37 = 0 ;
const struct V_38 V_39 = { } ;
F_12 ( V_40 ,
L_2 ,
* V_12 , V_3 -> V_4 . V_5 . V_6 ,
V_3 -> V_4 . V_5 . V_41 , V_11 ,
V_19 -> V_4 . V_5 . V_8 ,
V_19 -> V_4 . V_5 . V_9 ) ;
* V_22 = V_42 ;
V_19 -> V_43 = NULL ;
V_44:
if ( ( * V_12 == V_15 ) || ( V_11 == V_35 ) ) {
F_13 (tmp, &res->lr_granted) {
V_2 = F_14 ( V_30 , struct V_1 ,
V_14 ) ;
if ( F_1 ( V_2 , V_19 ) ) {
V_31 = V_30 ;
break;
}
}
} else {
int V_45 = 0 ;
F_15 ( V_11 ) ;
F_13 (tmp, &res->lr_granted) {
V_2 = F_14 ( V_30 , struct V_1 ,
V_14 ) ;
if ( F_1 ( V_2 , V_19 ) ) {
if ( ! V_31 )
V_31 = V_30 ;
continue;
}
if ( F_16 ( V_2 -> V_46 , V_11 ) )
continue;
if ( ! F_2 ( V_2 , V_19 ) )
continue;
if ( ! V_20 ) {
V_45 = 1 ;
continue;
}
if ( * V_12 & V_47 ) {
F_3 ( V_19 , V_11 , * V_12 ) ;
* V_22 = - V_48 ;
return V_49 ;
}
if ( * V_12 & V_50 ) {
F_3 ( V_19 , V_11 , * V_12 ) ;
V_19 -> V_33 = V_2 -> V_46 ;
V_19 -> V_4 . V_5 . V_41 =
V_2 -> V_4 . V_5 . V_41 ;
V_19 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_19 -> V_4 . V_5 . V_9 =
V_2 -> V_4 . V_5 . V_9 ;
* V_12 |= V_51 ;
return V_49 ;
}
F_17 ( V_26 , & V_26 -> V_52 , V_19 ) ;
* V_12 |= V_53 ;
return V_49 ;
}
if ( V_45 )
return V_54 ;
}
if ( * V_12 & V_50 ) {
F_3 ( V_19 , V_11 , * V_12 ) ;
V_19 -> V_33 = V_35 ;
* V_12 |= V_51 ;
return V_49 ;
}
if ( ! V_31 )
V_31 = & V_26 -> V_55 ;
F_18 (ownlocks, tmp, &res->lr_granted) {
V_2 = F_14 ( V_31 , struct V_1 , V_14 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
break;
if ( V_2 -> V_46 == V_11 ) {
if ( ( V_3 -> V_4 . V_5 . V_8 >
( V_2 -> V_4 . V_5 . V_9 + 1 ) ) &&
( V_2 -> V_4 . V_5 . V_9 != V_56 ) )
continue;
if ( ( V_3 -> V_4 . V_5 . V_9 <
( V_2 -> V_4 . V_5 . V_8 - 1 ) ) &&
( V_2 -> V_4 . V_5 . V_8 != 0 ) )
break;
if ( V_3 -> V_4 . V_5 . V_8 <
V_2 -> V_4 . V_5 . V_8 ) {
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_8 ;
} else {
V_3 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
}
if ( V_3 -> V_4 . V_5 . V_9 >
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_9 ;
} else {
V_3 -> V_4 . V_5 . V_9 =
V_2 -> V_4 . V_5 . V_9 ;
}
if ( V_34 ) {
F_3 ( V_2 , V_11 , * V_12 ) ;
} else {
V_3 = V_2 ;
V_34 = 1 ;
}
continue;
}
if ( V_3 -> V_4 . V_5 . V_8 >
V_2 -> V_4 . V_5 . V_9 )
continue;
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_8 )
break;
++ V_36 ;
if ( V_3 -> V_4 . V_5 . V_8 <=
V_2 -> V_4 . V_5 . V_8 ) {
if ( V_3 -> V_4 . V_5 . V_9 <
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
break;
}
F_3 ( V_2 , V_2 -> V_33 , * V_12 ) ;
continue;
}
if ( V_3 -> V_4 . V_5 . V_9 >=
V_2 -> V_4 . V_5 . V_9 ) {
V_2 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
continue;
}
if ( ! V_32 ) {
F_19 ( V_19 ) ;
V_32 = F_20 ( V_29 , & V_26 -> V_57 , V_58 ,
V_2 -> V_46 , & V_39 ,
NULL , 0 , V_59 ) ;
F_21 ( V_19 ) ;
if ( F_22 ( V_32 ) ) {
F_3 ( V_19 , V_2 -> V_46 ,
* V_12 ) ;
* V_22 = F_23 ( V_32 ) ;
return V_49 ;
}
goto V_44;
}
V_37 = 1 ;
V_32 -> V_46 = V_2 -> V_46 ;
V_32 -> V_4 . V_5 . V_41 =
V_3 -> V_4 . V_5 . V_41 ;
V_32 -> V_4 . V_5 . V_6 =
V_3 -> V_4 . V_5 . V_6 ;
V_32 -> V_4 . V_5 . V_8 =
V_2 -> V_4 . V_5 . V_8 ;
V_32 -> V_4 . V_5 . V_9 =
V_3 -> V_4 . V_5 . V_8 - 1 ;
V_2 -> V_4 . V_5 . V_8 =
V_3 -> V_4 . V_5 . V_9 + 1 ;
V_32 -> V_60 = V_2 -> V_60 ;
if ( V_2 -> V_7 ) {
V_32 -> V_7 = F_24 ( V_2 -> V_7 ,
V_32 ) ;
if ( V_32 -> V_7 -> V_61 &&
F_6 ( & V_32 -> V_62 ) )
F_25 ( V_32 -> V_7 -> V_61 ,
& V_32 -> V_63 ,
& V_32 -> V_62 ) ;
}
if ( * V_12 == V_15 )
F_26 ( V_32 ,
V_2 -> V_46 ) ;
F_17 ( V_26 , V_31 , V_32 ) ;
F_27 ( V_32 ) ;
break;
}
if ( V_37 == 0 && V_32 )
F_9 ( V_32 ) ;
V_19 -> V_46 = V_19 -> V_33 ;
if ( ! V_34 ) {
F_7 ( & V_19 -> V_14 ) ;
F_17 ( V_26 , V_31 , V_19 ) ;
}
if ( * V_12 != V_15 ) {
F_28 ( L_3 ) ;
F_29 () ;
}
if ( V_34 )
F_3 ( V_19 , V_11 , * V_12 ) ;
F_30 ( V_64 , V_26 ) ;
return V_54 ;
}
static void
F_31 ( void * V_65 )
{
struct V_1 * V_2 ;
V_2 = ( (struct V_66 * ) V_65 ) -> V_67 ;
F_21 ( V_2 ) ;
F_32 ( V_2 ) ;
F_19 ( V_2 ) ;
}
int
F_33 ( struct V_1 * V_2 , T_1 V_12 , void * V_65 )
{
struct V_68 * V_69 = V_2 -> V_70 ;
struct V_71 * V_72 ;
struct V_73 * V_74 = NULL ;
struct V_66 V_75 ;
struct V_76 V_77 ;
enum V_21 V_22 ;
int V_78 = 0 ;
F_34 ( V_79 , 4 ) ;
if ( F_35 ( V_80 ) ) {
F_21 ( V_2 ) ;
V_2 -> V_16 |= V_81 ;
F_19 ( V_2 ) ;
F_34 ( V_80 , 4 ) ;
}
F_12 ( V_40 , L_4 ,
V_12 , V_65 , V_69 ) ;
F_5 ( V_12 != V_15 ) ;
if ( V_12 & V_82 )
goto V_83;
if ( ! ( V_12 & V_84 ) ) {
if ( ! V_65 )
goto V_83;
F_36 ( & V_2 -> V_85 ) ;
return 0 ;
}
F_4 ( V_2 , L_5 ) ;
V_75 . V_67 = V_2 ;
V_72 = F_37 ( V_2 -> V_60 ) ;
if ( V_72 )
V_74 = V_72 -> V_86 . V_87 . V_88 ;
if ( V_74 ) {
F_38 ( & V_74 -> V_89 ) ;
V_75 . V_90 = V_74 -> V_91 ;
F_39 ( & V_74 -> V_89 ) ;
}
V_77 = F_40 ( 0 , NULL , F_31 , & V_75 ) ;
V_78 = F_41 ( V_2 -> V_85 , F_42 ( V_2 ) , & V_77 ) ;
if ( V_78 ) {
F_4 ( V_2 , L_6 ,
V_78 ) ;
return V_78 ;
}
V_83:
F_34 ( V_92 , 10 ) ;
if ( F_35 ( V_93 ) ) {
F_21 ( V_2 ) ;
V_2 -> V_16 |= V_94 | V_18 ;
F_19 ( V_2 ) ;
F_34 ( V_93 , 4 ) ;
}
if ( F_35 ( V_95 ) ) {
F_21 ( V_2 ) ;
V_2 -> V_16 |= V_81 |
V_94 | V_18 ;
F_19 ( V_2 ) ;
F_34 ( V_95 , 4 ) ;
}
F_21 ( V_2 ) ;
if ( F_43 ( V_2 ) ) {
F_19 ( V_2 ) ;
F_4 ( V_2 , L_7 ) ;
return - V_96 ;
}
F_44 ( V_2 ) ;
if ( F_45 ( V_2 ) || F_46 ( V_2 ) ) {
int V_11 ;
if ( V_12 & V_50 )
F_5 ( F_47 ( V_2 ) ) ;
if ( F_47 ( V_2 ) || F_46 ( V_2 ) )
V_11 = V_69 -> V_97 ;
else
V_11 = V_2 -> V_46 ;
if ( F_46 ( V_2 ) ) {
F_4 ( V_2 , L_8 ) ;
V_78 = - V_98 ;
}
F_3 ( V_2 , V_11 , V_15 ) ;
F_19 ( V_2 ) ;
F_36 ( & V_2 -> V_85 ) ;
return V_78 ? : - V_96 ;
}
F_4 ( V_2 , L_9 ) ;
if ( V_12 & V_50 ) {
F_5 ( F_47 ( V_2 ) ) ;
F_3 ( V_2 , V_69 -> V_97 , V_15 ) ;
switch ( V_2 -> V_46 ) {
case V_99 :
V_69 -> V_97 = V_100 ;
break;
case V_101 :
V_69 -> V_97 = V_102 ;
break;
default:
V_69 -> V_97 = V_103 ;
}
V_69 -> V_104 = ( V_105 ) V_2 -> V_4 . V_5 . V_41 ;
V_69 -> V_106 = ( V_107 ) V_2 -> V_4 . V_5 . V_8 ;
V_69 -> V_108 = ( V_107 ) V_2 -> V_4 . V_5 . V_9 ;
} else {
T_1 V_109 = V_15 ;
F_10 ( V_2 , & V_109 , 1 , & V_22 , NULL ) ;
}
F_19 ( V_2 ) ;
return V_78 ;
}
void F_48 ( const union V_110 * V_111 ,
union V_112 * V_113 )
{
V_113 -> V_5 . V_8 = V_111 -> V_5 . V_114 ;
V_113 -> V_5 . V_9 = V_111 -> V_5 . V_115 ;
V_113 -> V_5 . V_41 = V_111 -> V_5 . V_116 ;
V_113 -> V_5 . V_6 = V_111 -> V_5 . V_117 ;
}
void F_49 ( const union V_112 * V_113 ,
union V_110 * V_111 )
{
memset ( V_111 , 0 , sizeof( * V_111 ) ) ;
V_111 -> V_5 . V_114 = V_113 -> V_5 . V_8 ;
V_111 -> V_5 . V_115 = V_113 -> V_5 . V_9 ;
V_111 -> V_5 . V_116 = V_113 -> V_5 . V_41 ;
V_111 -> V_5 . V_117 = V_113 -> V_5 . V_6 ;
}
