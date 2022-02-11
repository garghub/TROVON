static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & F_3 ( V_2 ) -> V_3 ) ;
}
int F_4 ( struct V_4 * V_5 , enum V_6 V_7 )
{
enum V_6 V_8 = V_5 -> V_9 ;
if ( V_7 == V_8 )
return 0 ;
switch ( V_7 ) {
case V_10 :
goto V_11;
case V_12 :
switch ( V_8 ) {
case V_10 :
case V_13 :
break;
default:
goto V_11;
}
break;
case V_13 :
switch ( V_8 ) {
case V_12 :
break;
default:
goto V_11;
}
break;
case V_14 :
switch ( V_8 ) {
case V_10 :
case V_12 :
case V_15 :
break;
default:
goto V_11;
}
break;
case V_16 :
switch ( V_8 ) {
case V_14 :
case V_17 :
break;
default:
goto V_11;
}
break;
case V_15 :
switch ( V_8 ) {
case V_14 :
case V_13 :
break;
default:
goto V_11;
}
break;
case V_17 :
switch ( V_8 ) {
case V_15 :
break;
default:
goto V_11;
}
break;
}
V_5 -> V_9 = V_7 ;
return 0 ;
V_11:
F_5 ( 1 ,
F_6 ( V_18 , V_5 ,
L_1
L_2 ,
F_7 ( V_8 ) ,
F_7 ( V_7 ) ) ) ;
return - V_19 ;
}
void F_8 ( struct V_4 * V_5 )
{
unsigned long V_20 ;
F_9 ( & V_5 -> V_21 ) ;
F_10 ( V_5 -> V_22 , V_20 ) ;
if ( F_4 ( V_5 , V_14 ) )
if ( F_4 ( V_5 , V_15 ) ) {
F_11 ( V_5 -> V_22 , V_20 ) ;
F_12 ( & V_5 -> V_21 ) ;
return;
}
F_11 ( V_5 -> V_22 , V_20 ) ;
F_13 ( V_5 ) ;
F_14 ( V_5 -> V_23 ) ;
F_15 ( V_5 ) ;
F_12 ( & V_5 -> V_21 ) ;
F_16 ( V_5 ) ;
F_10 ( V_5 -> V_22 , V_20 ) ;
if ( F_4 ( V_5 , V_16 ) )
F_17 ( F_4 ( V_5 , V_17 ) ) ;
F_11 ( V_5 -> V_22 , V_20 ) ;
F_18 ( & V_5 -> V_3 ) ;
F_19 ( & V_5 -> V_24 ) ;
F_20 ( & V_5 -> V_3 ) ;
}
int F_21 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_1 * V_25 )
{
struct V_26 * V_27 = V_5 -> V_28 ;
int error = - V_19 ;
F_6 ( V_29 , V_5 , L_3 ,
V_27 -> V_30 ? V_27 -> V_30 ( V_5 ) : V_27 -> V_31 ) ;
if ( ! V_5 -> V_32 ) {
F_6 ( V_18 , V_5 ,
L_4 ) ;
goto V_33;
}
if ( F_22 ( V_5 ) ) {
error = F_23 ( V_5 ) ;
if ( error )
goto V_33;
} else {
V_5 -> V_34 = F_24 ( V_5 -> V_32 ,
V_5 -> V_28 -> V_35 ) ;
if ( ! V_5 -> V_34 ) {
error = - V_36 ;
goto V_33;
}
}
error = F_25 ( V_5 ) ;
if ( error )
goto V_37;
if ( ! V_5 -> V_3 . V_38 )
V_5 -> V_3 . V_38 = V_2 ? V_2 : & V_39 ;
if ( ! V_25 )
V_25 = V_5 -> V_3 . V_38 ;
V_5 -> V_25 = V_25 ;
F_26 ( & V_5 -> V_3 ) ;
F_27 ( & V_5 -> V_3 ) ;
F_28 ( & V_5 -> V_3 ) ;
F_29 ( & V_5 -> V_3 ) ;
error = F_30 ( & V_5 -> V_3 ) ;
if ( error )
goto V_40;
F_4 ( V_5 , V_12 ) ;
F_31 ( V_5 -> V_3 . V_38 ) ;
F_29 ( & V_5 -> V_24 ) ;
error = F_30 ( & V_5 -> V_24 ) ;
if ( error )
goto V_41;
F_31 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_42 -> V_43 ) {
V_5 -> V_44 = F_32 ( V_5 -> V_42 -> V_43 ,
V_45 ) ;
if ( V_5 -> V_44 == NULL ) {
error = - V_36 ;
goto V_46;
}
}
if ( V_5 -> V_42 -> V_47 ) {
snprintf ( V_5 -> V_48 , sizeof( V_5 -> V_48 ) ,
L_5 , V_5 -> V_49 ) ;
V_5 -> V_50 = F_33 (
V_5 -> V_48 ) ;
if ( ! V_5 -> V_50 ) {
error = - V_19 ;
goto V_51;
}
}
error = F_34 ( V_5 ) ;
if ( error )
goto V_52;
F_35 ( V_5 ) ;
F_36 ( V_5 ) ;
return error ;
V_52:
if ( V_5 -> V_50 )
F_37 ( V_5 -> V_50 ) ;
V_51:
F_38 ( V_5 -> V_44 ) ;
V_46:
F_20 ( & V_5 -> V_24 ) ;
V_41:
F_20 ( & V_5 -> V_3 ) ;
V_40:
F_39 ( & V_5 -> V_3 ) ;
F_40 ( & V_5 -> V_3 ) ;
F_41 ( & V_5 -> V_3 ) ;
F_42 ( & V_5 -> V_3 ) ;
F_43 ( V_5 ) ;
V_37:
if ( F_22 ( V_5 ) )
F_44 ( V_5 ) ;
V_33:
return error ;
}
static void F_45 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_46 ( V_2 ) ;
struct V_1 * V_38 = V_2 -> V_38 ;
struct V_53 * V_54 ;
void * V_55 ;
F_47 ( V_5 -> V_28 ) ;
if ( V_5 -> V_23 )
F_37 ( V_5 -> V_23 ) ;
if ( V_5 -> V_56 )
F_48 ( V_5 -> V_56 ) ;
if ( V_5 -> V_50 )
F_37 ( V_5 -> V_50 ) ;
V_54 = V_5 -> V_57 ;
if ( V_54 ) {
V_55 = V_54 -> V_55 ;
F_49 ( V_54 ) ;
F_38 ( V_55 ) ;
}
if ( V_5 -> V_9 == V_10 ) {
F_38 ( F_50 ( & V_5 -> V_24 ) ) ;
}
F_43 ( V_5 ) ;
if ( F_22 ( V_5 ) ) {
if ( V_5 -> V_58 . V_59 )
F_44 ( V_5 ) ;
} else {
if ( V_5 -> V_34 )
F_51 ( V_5 -> V_34 ) ;
}
F_38 ( V_5 -> V_44 ) ;
F_52 ( & V_60 , V_5 -> V_49 ) ;
if ( V_38 )
F_2 ( V_38 ) ;
F_38 ( V_5 ) ;
}
struct V_4 * F_53 ( struct V_26 * V_27 , int V_61 )
{
struct V_4 * V_5 ;
T_1 V_62 = V_45 ;
int V_63 ;
if ( V_27 -> V_64 && V_61 )
V_62 |= V_65 ;
V_5 = F_32 ( sizeof( struct V_4 ) + V_61 , V_62 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_22 = & V_5 -> V_66 ;
F_54 ( V_5 -> V_22 ) ;
V_5 -> V_9 = V_10 ;
F_55 ( & V_5 -> V_67 ) ;
F_55 ( & V_5 -> V_68 ) ;
F_55 ( & V_5 -> V_69 ) ;
F_55 ( & V_5 -> V_70 ) ;
F_56 ( & V_5 -> V_71 ) ;
F_57 ( & V_5 -> V_21 ) ;
V_63 = F_58 ( & V_60 , 0 , 0 , V_45 ) ;
if ( V_63 < 0 )
goto V_72;
V_5 -> V_49 = V_63 ;
V_5 -> V_73 = 0xff ;
V_5 -> V_74 = 0 ;
V_5 -> V_75 = 8 ;
V_5 -> V_76 = 8 ;
V_5 -> V_42 = & V_77 ;
V_5 -> V_78 = 12 ;
V_5 -> V_28 = V_27 ;
V_5 -> V_79 = V_27 -> V_79 ;
V_5 -> V_32 = V_27 -> V_32 ;
V_5 -> V_80 = V_27 -> V_80 ;
V_5 -> V_81 = V_27 -> V_81 ;
V_5 -> V_82 = V_27 -> V_82 ;
V_5 -> V_64 = V_27 -> V_64 ;
V_5 -> V_83 = V_27 -> V_83 ;
V_5 -> V_84 = V_27 -> V_84 ;
if ( V_85 == - 1 || ! V_27 -> V_86 )
V_5 -> V_87 = - 1 ;
else if ( ( V_88 ) V_85 * V_89 > V_90 ) {
F_6 ( V_91 , V_5 ,
L_6 ,
V_85 , V_90 / V_89 ) ;
V_5 -> V_87 = V_90 ;
} else
V_5 -> V_87 = V_85 * V_89 ;
if ( V_27 -> V_92 == V_93 )
V_5 -> V_94 = V_95 ;
else
V_5 -> V_94 = V_27 -> V_92 ;
if ( V_27 -> V_96 )
V_5 -> V_96 = V_27 -> V_96 ;
else
V_5 -> V_96 = V_97 ;
if ( V_27 -> V_98 )
V_5 -> V_98 = V_27 -> V_98 ;
else
V_5 -> V_98 = V_99 ;
if ( V_27 -> V_100 )
V_5 -> V_100 = V_27 -> V_100 ;
else
V_5 -> V_100 = 0xffffffff ;
V_5 -> V_101 = V_102 ;
F_59 ( & V_5 -> V_3 ) ;
F_60 ( & V_5 -> V_3 , L_7 , V_5 -> V_49 ) ;
V_5 -> V_3 . V_103 = & V_104 ;
V_5 -> V_3 . type = & V_105 ;
F_59 ( & V_5 -> V_24 ) ;
V_5 -> V_24 . V_38 = & V_5 -> V_3 ;
V_5 -> V_24 . V_106 = & V_107 ;
F_60 ( & V_5 -> V_24 , L_7 , V_5 -> V_49 ) ;
V_5 -> V_24 . V_108 = V_109 ;
V_5 -> V_56 = F_61 ( V_110 , V_5 ,
L_8 , V_5 -> V_49 ) ;
if ( F_62 ( V_5 -> V_56 ) ) {
F_6 ( V_91 , V_5 ,
L_9 ,
F_63 ( V_5 -> V_56 ) ) ;
goto V_111;
}
V_5 -> V_23 = F_64 ( L_10 ,
V_112 | V_113 ,
1 , V_5 -> V_49 ) ;
if ( ! V_5 -> V_23 ) {
F_6 ( V_91 , V_5 ,
L_11 ) ;
goto V_114;
}
F_65 ( V_5 -> V_28 ) ;
return V_5 ;
V_114:
F_48 ( V_5 -> V_56 ) ;
V_111:
F_52 ( & V_60 , V_5 -> V_49 ) ;
V_72:
F_38 ( V_5 ) ;
return NULL ;
}
struct V_4 * F_66 ( struct V_26 * V_27 , int V_61 )
{
struct V_4 * V_5 = F_53 ( V_27 , V_61 ) ;
if ( ! V_27 -> V_115 ) {
F_67 ( V_91 L_12
L_13 , V_27 -> V_31 ) ;
F_68 () ;
}
if ( V_5 )
F_69 ( & V_5 -> V_116 , & V_27 -> V_117 ) ;
return V_5 ;
}
void F_70 ( struct V_4 * V_5 )
{
F_71 ( & V_5 -> V_116 ) ;
F_72 ( V_5 ) ;
}
static int F_73 ( struct V_1 * V_2 , const void * V_118 )
{
struct V_4 * V_119 ;
const unsigned short * V_120 = V_118 ;
V_119 = F_3 ( V_2 ) ;
return V_119 -> V_49 == * V_120 ;
}
struct V_4 * F_74 ( unsigned short V_120 )
{
struct V_1 * V_121 ;
struct V_4 * V_5 = NULL ;
V_121 = F_75 ( & V_107 , NULL , & V_120 ,
F_73 ) ;
if ( V_121 ) {
V_5 = F_76 ( F_3 ( V_121 ) ) ;
F_2 ( V_121 ) ;
}
return V_5 ;
}
struct V_4 * F_76 ( struct V_4 * V_5 )
{
if ( ( V_5 -> V_9 == V_16 ) ||
! F_31 ( & V_5 -> V_3 ) )
return NULL ;
return V_5 ;
}
void F_72 ( struct V_4 * V_5 )
{
F_2 ( & V_5 -> V_3 ) ;
}
int F_77 ( void )
{
return F_78 ( & V_107 ) ;
}
void F_79 ( void )
{
F_80 ( & V_107 ) ;
F_81 ( & V_60 ) ;
}
int F_82 ( const struct V_1 * V_2 )
{
return V_2 -> type == & V_105 ;
}
int F_83 ( struct V_4 * V_5 , struct V_122 * V_123 )
{
if ( F_84 ( ! V_5 -> V_50 ) ) {
F_6 ( V_18 , V_5 ,
L_14
L_15 , V_5 -> V_28 -> V_31 ) ;
F_68 () ;
return - V_19 ;
}
return F_85 ( V_5 -> V_50 , V_123 ) ;
}
void F_86 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_50 ) {
F_6 ( V_18 , V_5 ,
L_16
L_15 , V_5 -> V_28 -> V_31 ) ;
F_68 () ;
return;
}
F_14 ( V_5 -> V_50 ) ;
}
