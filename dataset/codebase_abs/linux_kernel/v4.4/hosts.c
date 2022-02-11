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
error = F_26 ( & V_5 -> V_3 ) ;
if ( error )
goto V_40;
F_27 ( & V_5 -> V_3 ) ;
F_28 ( & V_5 -> V_3 ) ;
F_29 ( & V_5 -> V_3 ) ;
F_4 ( V_5 , V_12 ) ;
F_30 ( V_5 -> V_3 . V_38 ) ;
F_29 ( & V_5 -> V_24 ) ;
error = F_26 ( & V_5 -> V_24 ) ;
if ( error )
goto V_41;
F_30 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_42 -> V_43 ) {
V_5 -> V_44 = F_31 ( V_5 -> V_42 -> V_43 ,
V_45 ) ;
if ( V_5 -> V_44 == NULL ) {
error = - V_36 ;
goto V_46;
}
}
if ( V_5 -> V_42 -> V_47 ) {
snprintf ( V_5 -> V_48 , sizeof( V_5 -> V_48 ) ,
L_5 , V_5 -> V_49 ) ;
V_5 -> V_50 = F_32 (
V_5 -> V_48 ) ;
if ( ! V_5 -> V_50 ) {
error = - V_19 ;
goto V_51;
}
}
error = F_33 ( V_5 ) ;
if ( error )
goto V_52;
F_34 ( V_5 ) ;
return error ;
V_52:
if ( V_5 -> V_50 )
F_35 ( V_5 -> V_50 ) ;
V_51:
F_36 ( V_5 -> V_44 ) ;
V_46:
F_20 ( & V_5 -> V_24 ) ;
V_41:
F_20 ( & V_5 -> V_3 ) ;
V_40:
F_37 ( V_5 ) ;
V_37:
if ( F_22 ( V_5 ) )
F_38 ( V_5 ) ;
V_33:
return error ;
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_40 ( V_2 ) ;
struct V_1 * V_38 = V_2 -> V_38 ;
struct V_53 * V_54 ;
void * V_55 ;
F_41 ( V_5 -> V_28 ) ;
if ( V_5 -> V_23 )
F_35 ( V_5 -> V_23 ) ;
if ( V_5 -> V_56 )
F_42 ( V_5 -> V_56 ) ;
if ( V_5 -> V_50 )
F_35 ( V_5 -> V_50 ) ;
V_54 = V_5 -> V_57 ;
if ( V_54 ) {
V_55 = V_54 -> V_55 ;
F_43 ( V_54 ) ;
F_36 ( V_55 ) ;
}
if ( V_5 -> V_9 == V_10 ) {
F_36 ( F_44 ( & V_5 -> V_24 ) ) ;
}
F_37 ( V_5 ) ;
if ( F_22 ( V_5 ) ) {
if ( V_5 -> V_58 . V_59 )
F_38 ( V_5 ) ;
} else {
if ( V_5 -> V_34 )
F_45 ( V_5 -> V_34 ) ;
}
F_36 ( V_5 -> V_44 ) ;
if ( V_38 )
F_2 ( V_38 ) ;
F_36 ( V_5 ) ;
}
struct V_4 * F_46 ( struct V_26 * V_27 , int V_60 )
{
struct V_4 * V_5 ;
T_1 V_61 = V_45 ;
if ( V_27 -> V_62 && V_60 )
V_61 |= V_63 ;
V_5 = F_31 ( sizeof( struct V_4 ) + V_60 , V_61 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_22 = & V_5 -> V_64 ;
F_47 ( V_5 -> V_22 ) ;
V_5 -> V_9 = V_10 ;
F_48 ( & V_5 -> V_65 ) ;
F_48 ( & V_5 -> V_66 ) ;
F_48 ( & V_5 -> V_67 ) ;
F_48 ( & V_5 -> V_68 ) ;
F_49 ( & V_5 -> V_69 ) ;
F_50 ( & V_5 -> V_21 ) ;
V_5 -> V_49 = F_51 ( & V_70 ) - 1 ;
V_5 -> V_71 = 0xff ;
V_5 -> V_72 = 0 ;
V_5 -> V_73 = 8 ;
V_5 -> V_74 = 8 ;
V_5 -> V_42 = & V_75 ;
V_5 -> V_76 = 12 ;
V_5 -> V_28 = V_27 ;
V_5 -> V_77 = V_27 -> V_77 ;
V_5 -> V_32 = V_27 -> V_32 ;
V_5 -> V_78 = V_27 -> V_78 ;
V_5 -> V_79 = V_27 -> V_79 ;
V_5 -> V_80 = V_27 -> V_80 ;
V_5 -> V_62 = V_27 -> V_62 ;
V_5 -> V_81 = V_27 -> V_81 ;
V_5 -> V_82 = V_27 -> V_82 ;
if ( V_83 == - 1 || ! V_27 -> V_84 )
V_5 -> V_85 = - 1 ;
else if ( ( V_86 ) V_83 * V_87 > V_88 ) {
F_6 ( V_89 , V_5 ,
L_6 ,
V_83 , V_88 / V_87 ) ;
V_5 -> V_85 = V_88 ;
} else
V_5 -> V_85 = V_83 * V_87 ;
if ( V_27 -> V_90 == V_91 )
V_5 -> V_92 = V_93 ;
else
V_5 -> V_92 = V_27 -> V_90 ;
if ( V_27 -> V_94 )
V_5 -> V_94 = V_27 -> V_94 ;
else
V_5 -> V_94 = V_95 ;
if ( V_27 -> V_96 )
V_5 -> V_96 = V_27 -> V_96 ;
else
V_5 -> V_96 = V_97 ;
if ( V_27 -> V_98 )
V_5 -> V_98 = V_27 -> V_98 ;
else
V_5 -> V_98 = 0xffffffff ;
V_5 -> V_99 = V_100 && ! V_5 -> V_28 -> V_101 ;
F_52 ( & V_5 -> V_3 ) ;
F_53 ( & V_5 -> V_3 , L_7 , V_5 -> V_49 ) ;
V_5 -> V_3 . V_102 = & V_103 ;
V_5 -> V_3 . type = & V_104 ;
F_52 ( & V_5 -> V_24 ) ;
V_5 -> V_24 . V_38 = & V_5 -> V_3 ;
V_5 -> V_24 . V_105 = & V_106 ;
F_53 ( & V_5 -> V_24 , L_7 , V_5 -> V_49 ) ;
V_5 -> V_24 . V_107 = V_108 ;
V_5 -> V_56 = F_54 ( V_109 , V_5 ,
L_8 , V_5 -> V_49 ) ;
if ( F_55 ( V_5 -> V_56 ) ) {
F_6 ( V_89 , V_5 ,
L_9 ,
F_56 ( V_5 -> V_56 ) ) ;
goto V_110;
}
V_5 -> V_23 = F_57 ( L_10 ,
V_111 | V_112 ,
1 , V_5 -> V_49 ) ;
if ( ! V_5 -> V_23 ) {
F_6 ( V_89 , V_5 ,
L_11 ) ;
goto V_113;
}
F_58 ( V_5 -> V_28 ) ;
return V_5 ;
V_113:
F_42 ( V_5 -> V_56 ) ;
V_110:
F_36 ( V_5 ) ;
return NULL ;
}
struct V_4 * F_59 ( struct V_26 * V_27 , int V_60 )
{
struct V_4 * V_5 = F_46 ( V_27 , V_60 ) ;
if ( ! V_27 -> V_114 ) {
F_60 ( V_89 L_12
L_13 , V_27 -> V_31 ) ;
F_61 () ;
}
if ( V_5 )
F_62 ( & V_5 -> V_115 , & V_27 -> V_116 ) ;
return V_5 ;
}
void F_63 ( struct V_4 * V_5 )
{
F_64 ( & V_5 -> V_115 ) ;
F_65 ( V_5 ) ;
}
static int F_66 ( struct V_1 * V_2 , const void * V_117 )
{
struct V_4 * V_118 ;
const unsigned short * V_119 = V_117 ;
V_118 = F_3 ( V_2 ) ;
return V_118 -> V_49 == * V_119 ;
}
struct V_4 * F_67 ( unsigned short V_119 )
{
struct V_1 * V_120 ;
struct V_4 * V_5 = NULL ;
V_120 = F_68 ( & V_106 , NULL , & V_119 ,
F_66 ) ;
if ( V_120 ) {
V_5 = F_69 ( F_3 ( V_120 ) ) ;
F_2 ( V_120 ) ;
}
return V_5 ;
}
struct V_4 * F_69 ( struct V_4 * V_5 )
{
if ( ( V_5 -> V_9 == V_16 ) ||
! F_30 ( & V_5 -> V_3 ) )
return NULL ;
return V_5 ;
}
void F_65 ( struct V_4 * V_5 )
{
F_2 ( & V_5 -> V_3 ) ;
}
int F_70 ( void )
{
return F_71 ( & V_106 ) ;
}
void F_72 ( void )
{
F_73 ( & V_106 ) ;
}
int F_74 ( const struct V_1 * V_2 )
{
return V_2 -> type == & V_104 ;
}
int F_75 ( struct V_4 * V_5 , struct V_121 * V_122 )
{
if ( F_76 ( ! V_5 -> V_50 ) ) {
F_6 ( V_18 , V_5 ,
L_14
L_15 , V_5 -> V_28 -> V_31 ) ;
F_61 () ;
return - V_19 ;
}
return F_77 ( V_5 -> V_50 , V_122 ) ;
}
void F_78 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_50 ) {
F_6 ( V_18 , V_5 ,
L_16
L_15 , V_5 -> V_28 -> V_31 ) ;
F_61 () ;
return;
}
F_14 ( V_5 -> V_50 ) ;
}
