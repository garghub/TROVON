static inline void F_1 ( void T_1 * V_1 , int V_2 , T_2 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static inline T_2 F_3 ( void T_1 * V_1 , int V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static inline void F_5 ( struct V_4 * V_5 , T_2 V_6 )
{
T_2 V_7 = 0 ;
if ( V_6 == V_8 ) {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_1 ( V_5 -> V_9 , F_6 ( V_7 ) , 0 ) ;
} else {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_1 ( V_5 -> V_9 , F_7 ( V_7 ) , 0 ) ;
}
}
static inline void F_8 ( struct V_4 * V_5 , T_2 V_6 )
{
T_2 V_7 = 0 ;
if ( V_6 == V_8 ) {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_1 ( V_5 -> V_9 , F_9 ( V_7 ) , 0 ) ;
} else {
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ )
F_1 ( V_5 -> V_9 , F_10 ( V_7 ) , 0 ) ;
}
}
static void F_11 ( struct V_4 * V_5 ,
struct V_10 * V_11 )
{
F_1 ( V_5 -> V_9 , V_12 , 1 ) ;
if ( V_11 -> V_6 == V_8 )
F_1 ( V_5 -> V_9 , V_13 , 1 ) ;
else
F_1 ( V_5 -> V_9 , V_14 , 1 ) ;
F_1 ( V_5 -> V_9 , V_15 , 1 ) ;
}
static void F_12 ( struct V_4 * V_5 ,
struct V_10 * V_11 )
{
T_2 V_7 = 0 , V_16 ;
F_8 ( V_5 , V_11 -> V_6 ) ;
if ( V_11 -> V_6 == V_8 ) {
F_1 ( V_5 -> V_9 , V_13 , 0 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_16 = F_3 ( V_5 -> V_9 , F_13 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_13 ( V_7 ) , V_16 | 0x30 ) ;
}
} else {
F_1 ( V_5 -> V_9 , V_14 , 0 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_16 = F_3 ( V_5 -> V_9 , F_13 ( V_7 ) ) ;
F_1 ( V_5 -> V_9 , F_13 ( V_7 ) , V_16 | 0x03 ) ;
}
}
if ( ! V_5 -> V_17 ) {
F_1 ( V_5 -> V_9 , V_15 , 0 ) ;
F_1 ( V_5 -> V_9 , V_12 , 0 ) ;
}
}
static int F_14 ( struct V_10 * V_11 ,
struct V_18 * V_19 )
{
struct V_4 * V_5 = F_15 ( V_19 ) ;
struct V_20 * V_21 = NULL ;
if ( ! ( V_5 -> V_22 & V_23 ) &&
( V_11 -> V_6 == V_24 ) )
return - V_25 ;
if ( ! ( V_5 -> V_22 & V_26 ) &&
( V_11 -> V_6 == V_8 ) )
return - V_25 ;
if ( V_11 -> V_6 == V_8 )
V_21 = & V_5 -> V_27 ;
else if ( V_11 -> V_6 == V_24 )
V_21 = & V_5 -> V_28 ;
F_16 ( V_19 , V_11 , ( void * ) V_21 ) ;
return 0 ;
}
static int F_17 ( struct V_10 * V_11 ,
struct V_29 * V_30 , struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
struct V_32 * V_33 = & V_5 -> V_33 ;
T_2 V_34 , V_35 , V_36 , V_16 ;
int V_37 ;
switch ( F_18 ( V_30 ) ) {
case V_38 :
V_33 -> V_39 = 16 ;
V_34 = 0x00 ;
V_35 = 0x02 ;
break;
case V_40 :
V_33 -> V_39 = 24 ;
V_34 = 0x08 ;
V_35 = 0x04 ;
break;
case V_41 :
V_33 -> V_39 = 32 ;
V_34 = 0x10 ;
V_35 = 0x05 ;
break;
default:
F_19 ( V_5 -> V_5 , L_1 ) ;
return - V_25 ;
}
V_33 -> V_42 = F_20 ( V_30 ) ;
switch ( V_33 -> V_42 ) {
case V_43 :
V_36 = 3 ;
break;
case V_44 :
V_36 = 2 ;
break;
case V_45 :
V_36 = 1 ;
break;
case V_46 :
V_36 = 0 ;
break;
default:
F_19 ( V_5 -> V_5 , L_2 ) ;
return - V_25 ;
}
F_5 ( V_5 , V_11 -> V_6 ) ;
if ( V_11 -> V_6 == V_8 ) {
F_1 ( V_5 -> V_9 , F_21 ( V_36 ) , V_35 ) ;
F_1 ( V_5 -> V_9 , F_22 ( V_36 ) , 0x02 ) ;
V_16 = F_3 ( V_5 -> V_9 , F_13 ( V_36 ) ) ;
F_1 ( V_5 -> V_9 , F_13 ( V_36 ) , V_16 & ~ 0x30 ) ;
F_1 ( V_5 -> V_9 , F_6 ( V_36 ) , 1 ) ;
} else {
F_1 ( V_5 -> V_9 , F_23 ( V_36 ) , V_35 ) ;
F_1 ( V_5 -> V_9 , F_24 ( V_36 ) , 0x07 ) ;
V_16 = F_3 ( V_5 -> V_9 , F_13 ( V_36 ) ) ;
F_1 ( V_5 -> V_9 , F_13 ( V_36 ) , V_16 & ~ 0x03 ) ;
F_1 ( V_5 -> V_9 , F_7 ( V_36 ) , 1 ) ;
}
F_1 ( V_5 -> V_9 , V_47 , V_34 ) ;
V_33 -> V_48 = F_25 ( V_30 ) ;
if ( ! V_5 -> V_49 )
return - V_25 ;
V_37 = V_5 -> V_49 ( V_33 ) ;
if ( V_37 < 0 ) {
F_19 ( V_5 -> V_5 , L_3 ) ;
return V_37 ;
}
return 0 ;
}
static void F_26 ( struct V_10 * V_11 ,
struct V_18 * V_31 )
{
F_16 ( V_31 , V_11 , NULL ) ;
}
static int F_27 ( struct V_10 * V_11 ,
int V_50 , struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
int V_37 = 0 ;
switch ( V_50 ) {
case V_51 :
case V_52 :
case V_53 :
V_5 -> V_17 ++ ;
F_11 ( V_5 , V_11 ) ;
break;
case V_54 :
case V_55 :
case V_56 :
V_5 -> V_17 -- ;
F_12 ( V_5 , V_11 ) ;
break;
default:
V_37 = - V_25 ;
break;
}
return V_37 ;
}
static int F_28 ( struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
F_29 ( V_5 -> V_57 ) ;
return 0 ;
}
static int F_30 ( struct V_18 * V_31 )
{
struct V_4 * V_5 = F_15 ( V_31 ) ;
F_31 ( V_5 -> V_57 ) ;
return 0 ;
}
static int F_32 ( struct V_58 * V_59 )
{
const struct V_60 * V_61 = V_59 -> V_5 . V_62 ;
struct V_4 * V_5 ;
struct V_63 * V_64 ;
int V_37 ;
unsigned int V_65 ;
struct V_66 * V_67 ;
if ( ! V_61 ) {
F_19 ( & V_59 -> V_5 , L_4 ) ;
return - V_25 ;
}
V_64 = F_33 ( V_59 , V_68 , 0 ) ;
if ( ! V_64 ) {
F_19 ( & V_59 -> V_5 , L_5 ) ;
return - V_69 ;
}
if ( ! F_34 ( & V_59 -> V_5 , V_64 -> V_70 ,
F_35 ( V_64 ) , V_59 -> V_71 ) ) {
F_19 ( & V_59 -> V_5 , L_6 ) ;
return - V_72 ;
}
V_5 = F_36 ( & V_59 -> V_5 , sizeof( * V_5 ) , V_73 ) ;
if ( ! V_5 ) {
F_37 ( & V_59 -> V_5 , L_7 ) ;
return - V_74 ;
}
V_5 -> V_9 = F_38 ( & V_59 -> V_5 , V_64 -> V_70 ,
F_35 ( V_64 ) ) ;
if ( ! V_5 -> V_9 ) {
F_19 ( & V_59 -> V_5 , L_8 ) ;
return - V_74 ;
}
V_65 = V_61 -> V_65 ;
V_5 -> V_22 = V_65 ;
V_5 -> V_49 = V_61 -> V_49 ;
V_5 -> V_27 . V_75 = V_61 -> V_27 ;
V_5 -> V_28 . V_75 = V_61 -> V_28 ;
V_5 -> V_27 . V_76 = V_64 -> V_70 + V_77 ;
V_5 -> V_28 . V_76 = V_64 -> V_70 + V_78 ;
V_5 -> V_27 . V_79 = 16 ;
V_5 -> V_28 . V_79 = 16 ;
V_5 -> V_27 . V_80 = V_81 ;
V_5 -> V_28 . V_80 = V_81 ;
V_5 -> V_27 . V_82 = V_61 -> V_82 ;
V_5 -> V_28 . V_82 = V_61 -> V_82 ;
V_5 -> V_57 = F_39 ( & V_59 -> V_5 , NULL ) ;
if ( F_40 ( V_5 -> V_57 ) )
return F_41 ( V_5 -> V_57 ) ;
V_37 = F_31 ( V_5 -> V_57 ) ;
if ( V_37 < 0 )
goto V_83;
V_67 = F_36 ( & V_59 -> V_5 , sizeof( * V_67 ) , V_73 ) ;
if ( ! V_67 ) {
F_19 ( & V_59 -> V_5 , L_9 ) ;
V_37 = - V_74 ;
goto V_84;
}
if ( V_65 & V_26 ) {
F_42 ( & V_59 -> V_5 , L_10 ) ;
V_67 -> V_85 . V_86 = V_87 ;
V_67 -> V_85 . V_88 = V_61 -> V_89 ;
V_67 -> V_85 . V_90 = V_61 -> V_91 ;
V_67 -> V_85 . V_92 = V_61 -> V_93 ;
}
if ( V_65 & V_23 ) {
F_42 ( & V_59 -> V_5 , L_11 ) ;
V_67 -> V_94 . V_86 = V_87 ;
V_67 -> V_94 . V_88 = V_61 -> V_89 ;
V_67 -> V_94 . V_90 = V_61 -> V_91 ;
V_67 -> V_94 . V_92 = V_61 -> V_93 ;
}
V_67 -> V_95 = & V_96 ;
V_67 -> V_97 = F_28 ;
V_67 -> V_98 = F_30 ;
V_5 -> V_5 = & V_59 -> V_5 ;
F_43 ( & V_59 -> V_5 , V_5 ) ;
V_37 = F_44 ( & V_59 -> V_5 , V_67 ) ;
if ( V_37 != 0 ) {
F_19 ( & V_59 -> V_5 , L_12 ) ;
goto V_99;
}
return 0 ;
V_99:
F_43 ( & V_59 -> V_5 , NULL ) ;
V_84:
F_29 ( V_5 -> V_57 ) ;
V_83:
F_45 ( V_5 -> V_57 ) ;
return V_37 ;
}
static int F_46 ( struct V_58 * V_59 )
{
struct V_4 * V_5 = F_47 ( & V_59 -> V_5 ) ;
F_48 ( & V_59 -> V_5 ) ;
F_43 ( & V_59 -> V_5 , NULL ) ;
F_45 ( V_5 -> V_57 ) ;
return 0 ;
}
