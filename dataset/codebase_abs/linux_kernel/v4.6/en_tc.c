static struct V_1 * F_1 ( struct V_2 * V_3 ,
T_1 * V_4 , T_1 * V_5 ,
T_1 V_6 , T_1 V_7 )
{
struct V_8 V_9 = {
. type = V_10 ,
{ . V_11 = V_3 -> V_12 . V_13 . V_14 } ,
} ;
struct V_1 * V_15 ;
bool V_16 = false ;
if ( F_2 ( V_3 -> V_12 . V_17 . V_14 ) ) {
V_3 -> V_12 . V_17 . V_14 =
F_3 ( V_3 -> V_12 . V_18 , 0 ,
V_19 ,
V_20 ) ;
if ( F_4 ( V_3 -> V_12 . V_17 . V_14 ) ) {
F_5 ( V_3 -> V_21 ,
L_1 ) ;
return F_6 ( V_3 -> V_12 . V_17 . V_14 ) ;
}
V_16 = true ;
}
V_15 = F_7 ( V_3 -> V_12 . V_17 . V_14 , V_22 ,
V_4 , V_5 ,
V_6 , V_7 ,
V_6 & V_23 ? & V_9 : NULL ) ;
if ( F_4 ( V_15 ) && V_16 ) {
F_8 ( V_3 -> V_12 . V_17 . V_14 ) ;
V_3 -> V_12 . V_17 . V_14 = NULL ;
}
return V_15 ;
}
static void F_9 ( struct V_2 * V_3 ,
struct V_1 * V_15 )
{
F_10 ( V_15 ) ;
if ( ! F_11 ( V_3 ) ) {
F_8 ( V_3 -> V_12 . V_17 . V_14 ) ;
V_3 -> V_12 . V_17 . V_14 = NULL ;
}
}
static int F_12 ( struct V_2 * V_3 ,
T_1 * V_4 , T_1 * V_5 ,
struct V_24 * V_25 )
{
void * V_26 = F_13 ( V_27 , V_4 , V_28 ) ;
void * V_29 = F_13 ( V_27 , V_5 , V_28 ) ;
T_2 V_30 = 0 ;
T_3 V_31 = 0 ;
if ( V_25 -> V_32 -> V_33 &
~ ( F_14 ( V_34 ) |
F_14 ( V_35 ) |
F_14 ( V_36 ) |
F_14 ( V_37 ) |
F_14 ( V_38 ) |
F_14 ( V_39 ) ) ) {
F_15 ( V_3 -> V_21 , L_2 ,
V_25 -> V_32 -> V_33 ) ;
return - V_40 ;
}
if ( F_16 ( V_25 -> V_32 , V_34 ) ) {
struct V_41 * V_42 =
F_17 ( V_25 -> V_32 ,
V_35 ,
V_25 -> V_42 ) ;
V_30 = V_42 -> V_30 ;
}
if ( F_16 ( V_25 -> V_32 , V_35 ) ) {
struct V_43 * V_42 =
F_17 ( V_25 -> V_32 ,
V_35 ,
V_25 -> V_42 ) ;
struct V_43 * V_44 =
F_17 ( V_25 -> V_32 ,
V_35 ,
V_25 -> V_44 ) ;
V_31 = V_42 -> V_31 ;
F_18 ( V_45 , V_26 , V_46 ,
F_19 ( V_44 -> V_47 ) ) ;
F_18 ( V_45 , V_29 , V_46 ,
F_19 ( V_42 -> V_47 ) ) ;
F_18 ( V_45 , V_26 , V_48 ,
V_44 -> V_31 ) ;
F_18 ( V_45 , V_29 , V_48 ,
V_42 -> V_31 ) ;
}
if ( F_16 ( V_25 -> V_32 , V_36 ) ) {
struct V_49 * V_42 =
F_17 ( V_25 -> V_32 ,
V_36 ,
V_25 -> V_42 ) ;
struct V_49 * V_44 =
F_17 ( V_25 -> V_32 ,
V_36 ,
V_25 -> V_44 ) ;
F_20 ( F_13 ( V_45 , V_26 ,
V_50 ) ,
V_44 -> V_51 ) ;
F_20 ( F_13 ( V_45 , V_29 ,
V_50 ) ,
V_42 -> V_51 ) ;
F_20 ( F_13 ( V_45 , V_26 ,
V_52 ) ,
V_44 -> V_53 ) ;
F_20 ( F_13 ( V_45 , V_29 ,
V_52 ) ,
V_42 -> V_53 ) ;
}
if ( V_30 == V_37 ) {
struct V_54 * V_42 =
F_17 ( V_25 -> V_32 ,
V_37 ,
V_25 -> V_42 ) ;
struct V_54 * V_44 =
F_17 ( V_25 -> V_32 ,
V_37 ,
V_25 -> V_44 ) ;
memcpy ( F_13 ( V_45 , V_26 ,
V_55 . V_56 . V_57 ) ,
& V_44 -> V_53 , sizeof( V_44 -> V_53 ) ) ;
memcpy ( F_13 ( V_45 , V_29 ,
V_55 . V_56 . V_57 ) ,
& V_42 -> V_53 , sizeof( V_42 -> V_53 ) ) ;
memcpy ( F_13 ( V_45 , V_26 ,
V_58 . V_56 . V_57 ) ,
& V_44 -> V_51 , sizeof( V_44 -> V_51 ) ) ;
memcpy ( F_13 ( V_45 , V_29 ,
V_58 . V_56 . V_57 ) ,
& V_42 -> V_51 , sizeof( V_42 -> V_51 ) ) ;
}
if ( V_30 == V_38 ) {
struct V_59 * V_42 =
F_17 ( V_25 -> V_32 ,
V_38 ,
V_25 -> V_42 ) ;
struct V_59 * V_44 =
F_17 ( V_25 -> V_32 ,
V_38 ,
V_25 -> V_44 ) ;
memcpy ( F_13 ( V_45 , V_26 ,
V_55 . V_60 . V_61 ) ,
& V_44 -> V_53 , sizeof( V_44 -> V_53 ) ) ;
memcpy ( F_13 ( V_45 , V_29 ,
V_55 . V_60 . V_61 ) ,
& V_42 -> V_53 , sizeof( V_42 -> V_53 ) ) ;
memcpy ( F_13 ( V_45 , V_26 ,
V_58 . V_60 . V_61 ) ,
& V_44 -> V_51 , sizeof( V_44 -> V_51 ) ) ;
memcpy ( F_13 ( V_45 , V_29 ,
V_58 . V_60 . V_61 ) ,
& V_42 -> V_51 , sizeof( V_42 -> V_51 ) ) ;
}
if ( F_16 ( V_25 -> V_32 , V_39 ) ) {
struct V_62 * V_42 =
F_17 ( V_25 -> V_32 ,
V_39 ,
V_25 -> V_42 ) ;
struct V_62 * V_44 =
F_17 ( V_25 -> V_32 ,
V_39 ,
V_25 -> V_44 ) ;
switch ( V_31 ) {
case V_63 :
F_18 ( V_45 , V_26 ,
V_64 , F_19 ( V_44 -> V_53 ) ) ;
F_18 ( V_45 , V_29 ,
V_64 , F_19 ( V_42 -> V_53 ) ) ;
F_18 ( V_45 , V_26 ,
V_65 , F_19 ( V_44 -> V_51 ) ) ;
F_18 ( V_45 , V_29 ,
V_65 , F_19 ( V_42 -> V_51 ) ) ;
break;
case V_66 :
F_18 ( V_45 , V_26 ,
V_67 , F_19 ( V_44 -> V_53 ) ) ;
F_18 ( V_45 , V_29 ,
V_67 , F_19 ( V_42 -> V_53 ) ) ;
F_18 ( V_45 , V_26 ,
V_68 , F_19 ( V_44 -> V_51 ) ) ;
F_18 ( V_45 , V_29 ,
V_68 , F_19 ( V_42 -> V_51 ) ) ;
break;
default:
F_5 ( V_3 -> V_21 ,
L_3 ) ;
return - V_69 ;
}
}
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , struct V_70 * V_71 ,
T_1 * V_6 , T_1 * V_7 )
{
const struct V_72 * V_73 ;
if ( F_22 ( V_71 ) )
return - V_69 ;
* V_7 = V_74 ;
* V_6 = 0 ;
F_23 (a, exts) {
if ( * V_6 )
return - V_69 ;
if ( F_24 ( V_73 ) ) {
* V_6 |= V_75 ;
continue;
}
if ( F_25 ( V_73 ) ) {
T_1 V_76 = F_26 ( V_73 ) ;
if ( V_76 & ~ V_77 ) {
F_15 ( V_3 -> V_21 , L_4 ,
V_76 ) ;
return - V_69 ;
}
* V_7 = V_76 ;
* V_6 |= V_23 ;
continue;
}
return - V_69 ;
}
return 0 ;
}
int F_27 ( struct V_2 * V_3 , T_4 V_78 ,
struct V_24 * V_25 )
{
struct V_79 * V_17 = & V_3 -> V_12 . V_17 ;
T_1 * V_4 ;
T_1 * V_5 ;
int V_80 = 0 ;
T_1 V_7 ;
T_1 V_6 ;
struct V_81 * V_82 ;
struct V_1 * V_83 = NULL ;
V_82 = F_28 ( & V_17 -> V_84 , & V_25 -> V_85 ,
V_17 -> V_86 ) ;
if ( V_82 )
V_83 = V_82 -> V_15 ;
else
V_82 = F_29 ( sizeof( * V_82 ) , V_87 ) ;
V_4 = F_29 ( F_30 ( V_27 ) , V_87 ) ;
V_5 = F_29 ( F_30 ( V_27 ) , V_87 ) ;
if ( ! V_4 || ! V_5 || ! V_82 ) {
V_80 = - V_88 ;
goto V_89;
}
V_82 -> V_85 = V_25 -> V_85 ;
V_80 = F_12 ( V_3 , V_4 , V_5 , V_25 ) ;
if ( V_80 < 0 )
goto V_89;
V_80 = F_21 ( V_3 , V_25 -> V_71 , & V_6 , & V_7 ) ;
if ( V_80 < 0 )
goto V_89;
V_80 = F_31 ( & V_17 -> V_84 , & V_82 -> V_90 ,
V_17 -> V_86 ) ;
if ( V_80 )
goto V_89;
V_82 -> V_15 = F_1 ( V_3 , V_4 , V_5 , V_6 ,
V_7 ) ;
if ( F_4 ( V_82 -> V_15 ) ) {
V_80 = F_32 ( V_82 -> V_15 ) ;
goto V_91;
}
if ( V_83 )
F_9 ( V_3 , V_83 ) ;
goto V_92;
V_91:
F_33 ( & V_17 -> V_84 , & V_82 -> V_90 , V_17 -> V_86 ) ;
V_89:
if ( ! V_83 )
F_34 ( V_82 ) ;
V_92:
F_34 ( V_4 ) ;
F_34 ( V_5 ) ;
return V_80 ;
}
int F_35 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_81 * V_82 ;
struct V_79 * V_17 = & V_3 -> V_12 . V_17 ;
V_82 = F_28 ( & V_17 -> V_84 , & V_25 -> V_85 ,
V_17 -> V_86 ) ;
if ( ! V_82 )
return - V_69 ;
F_33 ( & V_17 -> V_84 , & V_82 -> V_90 , V_17 -> V_86 ) ;
F_9 ( V_3 , V_82 -> V_15 ) ;
F_34 ( V_82 ) ;
return 0 ;
}
int F_36 ( struct V_2 * V_3 )
{
struct V_79 * V_17 = & V_3 -> V_12 . V_17 ;
V_17 -> V_86 = V_93 ;
return F_37 ( & V_17 -> V_84 , & V_17 -> V_86 ) ;
}
static void F_38 ( void * V_94 , void * V_95 )
{
struct V_81 * V_82 = V_94 ;
struct V_2 * V_3 = V_95 ;
F_9 ( V_3 , V_82 -> V_15 ) ;
F_34 ( V_82 ) ;
}
void F_39 ( struct V_2 * V_3 )
{
struct V_79 * V_17 = & V_3 -> V_12 . V_17 ;
F_40 ( & V_17 -> V_84 , F_38 , V_3 ) ;
if ( ! F_2 ( V_3 -> V_12 . V_17 . V_14 ) ) {
F_8 ( V_3 -> V_12 . V_17 . V_14 ) ;
V_3 -> V_12 . V_17 . V_14 = NULL ;
}
}
