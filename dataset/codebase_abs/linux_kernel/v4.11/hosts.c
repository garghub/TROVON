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
error = F_22 ( V_5 ) ;
if ( error )
goto V_33;
if ( F_23 ( V_5 ) ) {
error = F_24 ( V_5 ) ;
if ( error )
goto V_33;
} else {
V_5 -> V_34 = F_25 ( V_5 -> V_32 ,
V_5 -> V_28 -> V_35 ) ;
if ( ! V_5 -> V_34 ) {
error = - V_36 ;
goto V_33;
}
}
if ( ! V_5 -> V_3 . V_37 )
V_5 -> V_3 . V_37 = V_2 ? V_2 : & V_38 ;
if ( ! V_25 )
V_25 = V_5 -> V_3 . V_37 ;
V_5 -> V_25 = V_25 ;
F_26 ( & V_5 -> V_3 ) ;
F_27 ( & V_5 -> V_3 ) ;
F_28 ( & V_5 -> V_3 ) ;
F_29 ( & V_5 -> V_3 ) ;
error = F_30 ( & V_5 -> V_3 ) ;
if ( error )
goto V_39;
F_4 ( V_5 , V_12 ) ;
F_31 ( V_5 -> V_3 . V_37 ) ;
F_29 ( & V_5 -> V_24 ) ;
error = F_30 ( & V_5 -> V_24 ) ;
if ( error )
goto V_40;
F_31 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_41 -> V_42 ) {
V_5 -> V_43 = F_32 ( V_5 -> V_41 -> V_42 ,
V_44 ) ;
if ( V_5 -> V_43 == NULL ) {
error = - V_36 ;
goto V_45;
}
}
if ( V_5 -> V_41 -> V_46 ) {
snprintf ( V_5 -> V_47 , sizeof( V_5 -> V_47 ) ,
L_5 , V_5 -> V_48 ) ;
V_5 -> V_49 = F_33 (
V_5 -> V_47 ) ;
if ( ! V_5 -> V_49 ) {
error = - V_19 ;
goto V_50;
}
}
error = F_34 ( V_5 ) ;
if ( error )
goto V_51;
F_35 ( V_5 ) ;
F_36 ( V_5 ) ;
return error ;
V_51:
if ( V_5 -> V_49 )
F_37 ( V_5 -> V_49 ) ;
V_50:
F_38 ( V_5 -> V_43 ) ;
V_45:
F_20 ( & V_5 -> V_24 ) ;
V_40:
F_20 ( & V_5 -> V_3 ) ;
V_39:
F_39 ( & V_5 -> V_3 ) ;
F_40 ( & V_5 -> V_3 ) ;
F_41 ( & V_5 -> V_3 ) ;
F_42 ( & V_5 -> V_3 ) ;
if ( F_23 ( V_5 ) )
F_43 ( V_5 ) ;
V_33:
return error ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_45 ( V_2 ) ;
struct V_1 * V_37 = V_2 -> V_37 ;
struct V_52 * V_53 ;
void * V_54 ;
F_46 ( V_5 -> V_28 ) ;
if ( V_5 -> V_23 )
F_37 ( V_5 -> V_23 ) ;
if ( V_5 -> V_55 )
F_47 ( V_5 -> V_55 ) ;
if ( V_5 -> V_49 )
F_37 ( V_5 -> V_49 ) ;
V_53 = V_5 -> V_56 ;
if ( V_53 ) {
V_54 = V_53 -> V_54 ;
F_48 ( V_53 ) ;
F_38 ( V_54 ) ;
}
if ( V_5 -> V_9 == V_10 ) {
F_38 ( F_49 ( & V_5 -> V_24 ) ) ;
}
if ( F_23 ( V_5 ) ) {
if ( V_5 -> V_57 . V_58 )
F_43 ( V_5 ) ;
} else {
if ( V_5 -> V_34 )
F_50 ( V_5 -> V_34 ) ;
}
F_38 ( V_5 -> V_43 ) ;
F_51 ( & V_59 , V_5 -> V_48 ) ;
if ( V_37 )
F_2 ( V_37 ) ;
F_38 ( V_5 ) ;
}
struct V_4 * F_52 ( struct V_26 * V_27 , int V_60 )
{
struct V_4 * V_5 ;
T_1 V_61 = V_44 ;
int V_62 ;
if ( V_27 -> V_63 && V_60 )
V_61 |= V_64 ;
V_5 = F_32 ( sizeof( struct V_4 ) + V_60 , V_61 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_22 = & V_5 -> V_65 ;
F_53 ( V_5 -> V_22 ) ;
V_5 -> V_9 = V_10 ;
F_54 ( & V_5 -> V_66 ) ;
F_54 ( & V_5 -> V_67 ) ;
F_54 ( & V_5 -> V_68 ) ;
F_54 ( & V_5 -> V_69 ) ;
F_55 ( & V_5 -> V_70 ) ;
F_56 ( & V_5 -> V_21 ) ;
V_62 = F_57 ( & V_59 , 0 , 0 , V_44 ) ;
if ( V_62 < 0 )
goto V_71;
V_5 -> V_48 = V_62 ;
V_5 -> V_72 = 0xff ;
V_5 -> V_73 = 0 ;
V_5 -> V_74 = 8 ;
V_5 -> V_75 = 8 ;
V_5 -> V_41 = & V_76 ;
V_5 -> V_77 = 12 ;
V_5 -> V_28 = V_27 ;
V_5 -> V_78 = V_27 -> V_78 ;
V_5 -> V_32 = V_27 -> V_32 ;
V_5 -> V_79 = V_27 -> V_79 ;
V_5 -> V_80 = V_27 -> V_80 ;
V_5 -> V_81 = V_27 -> V_81 ;
V_5 -> V_63 = V_27 -> V_63 ;
V_5 -> V_82 = V_27 -> V_82 ;
V_5 -> V_83 = V_27 -> V_83 ;
if ( V_84 == - 1 || ! V_27 -> V_85 )
V_5 -> V_86 = - 1 ;
else if ( ( V_87 ) V_84 * V_88 > V_89 ) {
F_6 ( V_90 , V_5 ,
L_6 ,
V_84 , V_89 / V_88 ) ;
V_5 -> V_86 = V_89 ;
} else
V_5 -> V_86 = V_84 * V_88 ;
if ( V_27 -> V_91 == V_92 )
V_5 -> V_93 = V_94 ;
else
V_5 -> V_93 = V_27 -> V_91 ;
if ( V_27 -> V_95 )
V_5 -> V_95 = V_27 -> V_95 ;
else
V_5 -> V_95 = V_96 ;
if ( V_27 -> V_97 )
V_5 -> V_97 = V_27 -> V_97 ;
else
V_5 -> V_97 = V_98 ;
if ( V_27 -> V_99 )
V_5 -> V_99 = V_27 -> V_99 ;
else
V_5 -> V_99 = 0xffffffff ;
V_5 -> V_100 = V_101 ;
F_58 ( & V_5 -> V_3 ) ;
F_59 ( & V_5 -> V_3 , L_7 , V_5 -> V_48 ) ;
V_5 -> V_3 . V_102 = & V_103 ;
V_5 -> V_3 . type = & V_104 ;
F_58 ( & V_5 -> V_24 ) ;
V_5 -> V_24 . V_37 = & V_5 -> V_3 ;
V_5 -> V_24 . V_105 = & V_106 ;
F_59 ( & V_5 -> V_24 , L_7 , V_5 -> V_48 ) ;
V_5 -> V_24 . V_107 = V_108 ;
V_5 -> V_55 = F_60 ( V_109 , V_5 ,
L_8 , V_5 -> V_48 ) ;
if ( F_61 ( V_5 -> V_55 ) ) {
F_6 ( V_90 , V_5 ,
L_9 ,
F_62 ( V_5 -> V_55 ) ) ;
goto V_110;
}
V_5 -> V_23 = F_63 ( L_10 ,
V_111 | V_112 ,
1 , V_5 -> V_48 ) ;
if ( ! V_5 -> V_23 ) {
F_6 ( V_90 , V_5 ,
L_11 ) ;
goto V_113;
}
F_64 ( V_5 -> V_28 ) ;
return V_5 ;
V_113:
F_47 ( V_5 -> V_55 ) ;
V_110:
F_51 ( & V_59 , V_5 -> V_48 ) ;
V_71:
F_38 ( V_5 ) ;
return NULL ;
}
struct V_4 * F_65 ( struct V_26 * V_27 , int V_60 )
{
struct V_4 * V_5 = F_52 ( V_27 , V_60 ) ;
if ( ! V_27 -> V_114 ) {
F_66 ( V_90 L_12
L_13 , V_27 -> V_31 ) ;
F_67 () ;
}
if ( V_5 )
F_68 ( & V_5 -> V_115 , & V_27 -> V_116 ) ;
return V_5 ;
}
void F_69 ( struct V_4 * V_5 )
{
F_70 ( & V_5 -> V_115 ) ;
F_71 ( V_5 ) ;
}
static int F_72 ( struct V_1 * V_2 , const void * V_117 )
{
struct V_4 * V_118 ;
const unsigned short * V_119 = V_117 ;
V_118 = F_3 ( V_2 ) ;
return V_118 -> V_48 == * V_119 ;
}
struct V_4 * F_73 ( unsigned short V_119 )
{
struct V_1 * V_120 ;
struct V_4 * V_5 = NULL ;
V_120 = F_74 ( & V_106 , NULL , & V_119 ,
F_72 ) ;
if ( V_120 ) {
V_5 = F_75 ( F_3 ( V_120 ) ) ;
F_2 ( V_120 ) ;
}
return V_5 ;
}
struct V_4 * F_75 ( struct V_4 * V_5 )
{
if ( ( V_5 -> V_9 == V_16 ) ||
! F_31 ( & V_5 -> V_3 ) )
return NULL ;
return V_5 ;
}
void F_71 ( struct V_4 * V_5 )
{
F_2 ( & V_5 -> V_3 ) ;
}
int F_76 ( void )
{
return F_77 ( & V_106 ) ;
}
void F_78 ( void )
{
F_79 ( & V_106 ) ;
F_80 ( & V_59 ) ;
}
int F_81 ( const struct V_1 * V_2 )
{
return V_2 -> type == & V_104 ;
}
int F_82 ( struct V_4 * V_5 , struct V_121 * V_122 )
{
if ( F_83 ( ! V_5 -> V_49 ) ) {
F_6 ( V_18 , V_5 ,
L_14
L_15 , V_5 -> V_28 -> V_31 ) ;
F_67 () ;
return - V_19 ;
}
return F_84 ( V_5 -> V_49 , V_122 ) ;
}
void F_85 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_49 ) {
F_6 ( V_18 , V_5 ,
L_16
L_15 , V_5 -> V_28 -> V_31 ) ;
F_67 () ;
return;
}
F_14 ( V_5 -> V_49 ) ;
}
