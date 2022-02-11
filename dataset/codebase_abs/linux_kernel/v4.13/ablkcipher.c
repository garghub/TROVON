static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = V_1 ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_3 -> V_10 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
enum V_13 V_14 , V_15 ;
T_1 V_16 ;
int error ;
bool V_17 ;
V_17 = ( V_5 -> V_18 != V_5 -> V_19 ) ? true : false ;
V_14 = V_17 ? V_20 : V_21 ;
V_15 = V_17 ? V_22 : V_21 ;
error = F_5 ( & V_12 -> V_23 ) ;
if ( error )
F_6 ( V_12 -> V_24 , L_1 ,
error ) ;
if ( V_17 )
F_7 ( V_12 -> V_24 , V_7 -> V_25 , V_7 -> V_26 , V_14 ) ;
F_7 ( V_12 -> V_24 , V_7 -> V_27 , V_7 -> V_28 , V_15 ) ;
F_8 ( & V_7 -> V_29 ) ;
error = F_9 ( V_12 , & V_16 ) ;
if ( error < 0 )
F_6 ( V_12 -> V_24 , L_2 , V_16 ) ;
V_12 -> V_30 ( V_9 -> V_12 , error ) ;
}
static int
F_10 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_31 * V_32 = F_11 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_3 -> V_10 ) ;
struct V_11 * V_12 = V_9 -> V_12 ;
enum V_13 V_14 , V_15 ;
struct V_33 * V_34 ;
bool V_17 ;
T_2 V_35 ;
int V_36 ;
V_7 -> V_37 = V_5 -> V_38 ;
V_7 -> V_39 = F_12 ( V_32 ) ;
V_7 -> V_40 = V_5 -> V_41 ;
V_17 = ( V_5 -> V_18 != V_5 -> V_19 ) ? true : false ;
V_14 = V_17 ? V_20 : V_21 ;
V_15 = V_17 ? V_22 : V_21 ;
V_7 -> V_26 = F_13 ( V_5 -> V_18 , V_5 -> V_41 ) ;
if ( V_17 )
V_7 -> V_28 = F_13 ( V_5 -> V_19 , V_5 -> V_41 ) ;
else
V_7 -> V_28 = V_7 -> V_26 ;
if ( V_7 -> V_26 < 0 ) {
F_14 ( V_12 -> V_24 , L_3 ) ;
return V_7 -> V_26 ;
}
if ( V_7 -> V_28 < 0 ) {
F_14 ( V_12 -> V_24 , L_4 ) ;
return - V_7 -> V_28 ;
}
V_7 -> V_28 += 1 ;
V_35 = ( V_5 -> V_42 . V_43 & V_44 ) ?
V_45 : V_46 ;
V_36 = F_15 ( & V_7 -> V_29 , V_7 -> V_28 , V_35 ) ;
if ( V_36 )
return V_36 ;
F_16 ( & V_7 -> V_47 , V_12 -> V_23 . V_48 , V_49 ) ;
V_34 = F_17 ( & V_7 -> V_29 , V_5 -> V_19 ) ;
if ( F_18 ( V_34 ) ) {
V_36 = F_19 ( V_34 ) ;
goto V_50;
}
V_34 = F_17 ( & V_7 -> V_29 , & V_7 -> V_47 ) ;
if ( F_18 ( V_34 ) ) {
V_36 = F_19 ( V_34 ) ;
goto V_50;
}
F_20 ( V_34 ) ;
V_7 -> V_27 = V_7 -> V_29 . V_51 ;
V_36 = F_21 ( V_12 -> V_24 , V_7 -> V_27 , V_7 -> V_28 , V_15 ) ;
if ( V_36 < 0 )
goto V_50;
if ( V_17 ) {
V_36 = F_21 ( V_12 -> V_24 , V_5 -> V_18 , V_7 -> V_26 , V_14 ) ;
if ( V_36 < 0 )
goto V_52;
V_7 -> V_25 = V_5 -> V_18 ;
} else {
V_7 -> V_25 = V_7 -> V_27 ;
}
V_36 = F_22 ( & V_12 -> V_23 , V_7 -> V_25 , V_7 -> V_26 ,
V_7 -> V_27 , V_7 -> V_28 ,
F_1 , V_3 ) ;
if ( V_36 )
goto V_53;
F_23 ( & V_12 -> V_23 ) ;
V_36 = F_24 ( V_3 , V_9 -> V_54 , V_5 -> V_41 , 0 ) ;
if ( V_36 )
goto V_55;
return 0 ;
V_55:
F_5 ( & V_12 -> V_23 ) ;
V_53:
if ( V_17 )
F_7 ( V_12 -> V_24 , V_5 -> V_18 , V_7 -> V_26 , V_14 ) ;
V_52:
F_7 ( V_12 -> V_24 , V_7 -> V_27 , V_7 -> V_28 , V_15 ) ;
V_50:
F_8 ( & V_7 -> V_29 ) ;
return V_36 ;
}
static int F_25 ( struct V_31 * V_56 , const T_3 * V_57 ,
unsigned int V_58 )
{
struct V_59 * V_10 = F_26 ( V_56 ) ;
struct V_60 * V_61 = F_27 ( V_10 ) ;
unsigned long V_43 = F_4 ( V_10 ) -> V_62 ;
int V_36 ;
if ( ! V_57 || ! V_58 )
return - V_63 ;
if ( F_28 ( V_43 ) ) {
switch ( V_58 ) {
case V_64 :
case V_65 :
break;
default:
goto V_66;
}
} else if ( F_29 ( V_43 ) ) {
T_1 V_67 [ V_68 ] ;
V_36 = F_30 ( V_67 , V_57 ) ;
if ( ! V_36 && F_31 ( V_56 ) &
V_69 )
goto V_70;
}
V_61 -> V_71 = V_58 ;
memcpy ( V_61 -> V_72 , V_57 , V_58 ) ;
return 0 ;
V_66:
V_36 = F_32 ( V_61 -> V_66 , V_57 , V_58 ) ;
if ( ! V_36 )
V_61 -> V_71 = V_58 ;
return V_36 ;
V_70:
F_33 ( V_56 , V_73 ) ;
return - V_63 ;
}
static int F_34 ( struct V_4 * V_5 , int V_74 )
{
struct V_59 * V_10 =
F_26 ( F_11 ( V_5 ) ) ;
struct V_60 * V_61 = F_27 ( V_10 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_8 * V_9 = F_4 ( V_10 ) ;
int V_36 ;
V_7 -> V_43 = V_9 -> V_62 ;
V_7 -> V_43 |= V_74 ? V_75 : V_76 ;
if ( F_28 ( V_7 -> V_43 ) && V_61 -> V_71 != V_64 &&
V_61 -> V_71 != V_65 ) {
F_35 ( V_77 , V_61 -> V_66 ) ;
F_36 ( V_77 , V_61 -> V_66 ) ;
F_37 ( V_77 , V_5 -> V_42 . V_43 ,
NULL , NULL ) ;
F_38 ( V_77 , V_5 -> V_18 , V_5 -> V_19 ,
V_5 -> V_41 , V_5 -> V_38 ) ;
V_36 = V_74 ? F_39 ( V_77 ) :
F_40 ( V_77 ) ;
F_41 ( V_77 ) ;
return V_36 ;
}
return V_9 -> V_12 -> V_78 ( V_9 -> V_12 , & V_5 -> V_42 ) ;
}
static int F_42 ( struct V_4 * V_5 )
{
return F_34 ( V_5 , 1 ) ;
}
static int F_43 ( struct V_4 * V_5 )
{
return F_34 ( V_5 , 0 ) ;
}
static int F_44 ( struct V_59 * V_10 )
{
struct V_60 * V_61 = F_27 ( V_10 ) ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
V_10 -> V_79 . V_80 = sizeof( struct V_6 ) ;
V_61 -> V_66 = F_45 ( F_46 ( V_10 ) , 0 ,
V_81 |
V_82 ) ;
if ( F_18 ( V_61 -> V_66 ) )
return F_19 ( V_61 -> V_66 ) ;
return 0 ;
}
static void F_47 ( struct V_59 * V_10 )
{
struct V_60 * V_61 = F_27 ( V_10 ) ;
F_48 ( V_61 -> V_66 ) ;
}
static int F_49 ( const struct V_83 * V_84 ,
struct V_11 * V_12 )
{
struct V_8 * V_9 ;
struct V_85 * V_86 ;
int V_36 ;
V_9 = F_50 ( sizeof( * V_9 ) , V_45 ) ;
if ( ! V_9 )
return - V_87 ;
V_86 = & V_9 -> V_86 . V_88 ;
snprintf ( V_86 -> V_89 , V_90 , L_5 , V_84 -> V_91 ) ;
snprintf ( V_86 -> V_92 , V_90 , L_5 ,
V_84 -> V_93 ) ;
V_86 -> V_94 = V_84 -> V_95 ;
V_86 -> V_96 . V_39 = V_84 -> V_39 ;
V_86 -> V_96 . V_97 = V_84 -> V_97 ;
V_86 -> V_96 . V_98 = V_84 -> V_98 ;
V_86 -> V_96 . V_99 = F_25 ;
V_86 -> V_96 . V_74 = F_42 ;
V_86 -> V_96 . V_100 = F_43 ;
V_86 -> V_101 = 300 ;
V_86 -> V_102 = V_103 | V_81 |
V_82 ;
V_86 -> V_104 = sizeof( struct V_60 ) ;
V_86 -> V_105 = 0 ;
V_86 -> V_106 = & V_107 ;
V_86 -> V_108 = V_109 ;
V_86 -> V_110 = F_44 ;
V_86 -> V_111 = F_47 ;
F_51 ( & V_86 -> V_112 ) ;
F_51 ( & V_9 -> V_113 ) ;
V_9 -> V_54 = V_103 ;
V_9 -> V_62 = V_84 -> V_43 ;
V_9 -> V_12 = V_12 ;
V_36 = F_52 ( V_86 ) ;
if ( V_36 ) {
F_53 ( V_9 ) ;
F_14 ( V_12 -> V_24 , L_6 , V_86 -> V_89 ) ;
return V_36 ;
}
F_54 ( & V_9 -> V_113 , & V_114 ) ;
F_6 ( V_12 -> V_24 , L_7 , V_86 -> V_89 ) ;
return 0 ;
}
static void F_55 ( struct V_11 * V_12 )
{
struct V_8 * V_9 , * V_115 ;
F_56 (tmpl, n, &ablkcipher_algs, entry) {
F_57 ( & V_9 -> V_86 . V_88 ) ;
F_58 ( & V_9 -> V_113 ) ;
F_53 ( V_9 ) ;
}
}
static int F_59 ( struct V_11 * V_12 )
{
int V_36 , V_116 ;
for ( V_116 = 0 ; V_116 < F_60 ( V_117 ) ; V_116 ++ ) {
V_36 = F_49 ( & V_117 [ V_116 ] , V_12 ) ;
if ( V_36 )
goto V_118;
}
return 0 ;
V_118:
F_55 ( V_12 ) ;
return V_36 ;
}
