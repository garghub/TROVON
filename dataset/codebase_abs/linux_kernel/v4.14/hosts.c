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
F_46 ( V_5 -> V_28 ) ;
if ( V_5 -> V_23 )
F_37 ( V_5 -> V_23 ) ;
if ( V_5 -> V_52 )
F_47 ( V_5 -> V_52 ) ;
if ( V_5 -> V_49 )
F_37 ( V_5 -> V_49 ) ;
if ( V_5 -> V_9 == V_10 ) {
F_38 ( F_48 ( & V_5 -> V_24 ) ) ;
}
if ( F_23 ( V_5 ) ) {
if ( V_5 -> V_53 . V_54 )
F_43 ( V_5 ) ;
} else {
if ( V_5 -> V_34 )
F_49 ( V_5 -> V_34 ) ;
}
F_38 ( V_5 -> V_43 ) ;
F_50 ( & V_55 , V_5 -> V_48 ) ;
if ( V_37 )
F_2 ( V_37 ) ;
F_38 ( V_5 ) ;
}
struct V_4 * F_51 ( struct V_26 * V_27 , int V_56 )
{
struct V_4 * V_5 ;
T_1 V_57 = V_44 ;
int V_58 ;
if ( V_27 -> V_59 && V_56 )
V_57 |= V_60 ;
V_5 = F_32 ( sizeof( struct V_4 ) + V_56 , V_57 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_22 = & V_5 -> V_61 ;
F_52 ( V_5 -> V_22 ) ;
V_5 -> V_9 = V_10 ;
F_53 ( & V_5 -> V_62 ) ;
F_53 ( & V_5 -> V_63 ) ;
F_53 ( & V_5 -> V_64 ) ;
F_53 ( & V_5 -> V_65 ) ;
F_54 ( & V_5 -> V_66 ) ;
F_55 ( & V_5 -> V_21 ) ;
V_58 = F_56 ( & V_55 , 0 , 0 , V_44 ) ;
if ( V_58 < 0 )
goto V_67;
V_5 -> V_48 = V_58 ;
V_5 -> V_68 = 0xff ;
V_5 -> V_69 = 0 ;
V_5 -> V_70 = 8 ;
V_5 -> V_71 = 8 ;
V_5 -> V_41 = & V_72 ;
V_5 -> V_73 = 12 ;
V_5 -> V_28 = V_27 ;
V_5 -> V_74 = V_27 -> V_74 ;
V_5 -> V_32 = V_27 -> V_32 ;
V_5 -> V_75 = V_27 -> V_75 ;
V_5 -> V_76 = V_27 -> V_76 ;
V_5 -> V_77 = V_27 -> V_77 ;
V_5 -> V_59 = V_27 -> V_59 ;
V_5 -> V_78 = V_27 -> V_78 ;
V_5 -> V_79 = V_27 -> V_79 ;
if ( V_80 == - 1 || ! V_27 -> V_81 )
V_5 -> V_82 = - 1 ;
else if ( ( V_83 ) V_80 * V_84 > V_85 ) {
F_6 ( V_86 , V_5 ,
L_6 ,
V_80 , V_85 / V_84 ) ;
V_5 -> V_82 = V_85 ;
} else
V_5 -> V_82 = V_80 * V_84 ;
if ( V_27 -> V_87 == V_88 )
V_5 -> V_89 = V_90 ;
else
V_5 -> V_89 = V_27 -> V_87 ;
if ( V_27 -> V_91 )
V_5 -> V_91 = V_27 -> V_91 ;
else
V_5 -> V_91 = V_92 ;
if ( V_27 -> V_93 )
V_5 -> V_93 = V_27 -> V_93 ;
else
V_5 -> V_93 = V_94 ;
if ( V_27 -> V_95 )
V_5 -> V_95 = V_27 -> V_95 ;
else
V_5 -> V_95 = 0xffffffff ;
V_5 -> V_96 = V_97 ;
F_57 ( & V_5 -> V_3 ) ;
F_58 ( & V_5 -> V_3 , L_7 , V_5 -> V_48 ) ;
V_5 -> V_3 . V_98 = & V_99 ;
V_5 -> V_3 . type = & V_100 ;
F_57 ( & V_5 -> V_24 ) ;
V_5 -> V_24 . V_37 = & V_5 -> V_3 ;
V_5 -> V_24 . V_101 = & V_102 ;
F_58 ( & V_5 -> V_24 , L_7 , V_5 -> V_48 ) ;
V_5 -> V_24 . V_103 = V_104 ;
V_5 -> V_52 = F_59 ( V_105 , V_5 ,
L_8 , V_5 -> V_48 ) ;
if ( F_60 ( V_5 -> V_52 ) ) {
F_6 ( V_86 , V_5 ,
L_9 ,
F_61 ( V_5 -> V_52 ) ) ;
goto V_106;
}
V_5 -> V_23 = F_62 ( L_10 ,
V_107 | V_108 ,
1 , V_5 -> V_48 ) ;
if ( ! V_5 -> V_23 ) {
F_6 ( V_86 , V_5 ,
L_11 ) ;
goto V_109;
}
F_63 ( V_5 -> V_28 ) ;
return V_5 ;
V_109:
F_47 ( V_5 -> V_52 ) ;
V_106:
F_50 ( & V_55 , V_5 -> V_48 ) ;
V_67:
F_38 ( V_5 ) ;
return NULL ;
}
struct V_4 * F_64 ( struct V_26 * V_27 , int V_56 )
{
struct V_4 * V_5 = F_51 ( V_27 , V_56 ) ;
if ( ! V_27 -> V_110 ) {
F_65 ( V_86 L_12
L_13 , V_27 -> V_31 ) ;
F_66 () ;
}
if ( V_5 )
F_67 ( & V_5 -> V_111 , & V_27 -> V_112 ) ;
return V_5 ;
}
void F_68 ( struct V_4 * V_5 )
{
F_69 ( & V_5 -> V_111 ) ;
F_70 ( V_5 ) ;
}
static int F_71 ( struct V_1 * V_2 , const void * V_113 )
{
struct V_4 * V_114 ;
const unsigned short * V_115 = V_113 ;
V_114 = F_3 ( V_2 ) ;
return V_114 -> V_48 == * V_115 ;
}
struct V_4 * F_72 ( unsigned short V_115 )
{
struct V_1 * V_116 ;
struct V_4 * V_5 = NULL ;
V_116 = F_73 ( & V_102 , NULL , & V_115 ,
F_71 ) ;
if ( V_116 ) {
V_5 = F_74 ( F_3 ( V_116 ) ) ;
F_2 ( V_116 ) ;
}
return V_5 ;
}
struct V_4 * F_74 ( struct V_4 * V_5 )
{
if ( ( V_5 -> V_9 == V_16 ) ||
! F_31 ( & V_5 -> V_3 ) )
return NULL ;
return V_5 ;
}
void F_70 ( struct V_4 * V_5 )
{
F_2 ( & V_5 -> V_3 ) ;
}
int F_75 ( void )
{
return F_76 ( & V_102 ) ;
}
void F_77 ( void )
{
F_78 ( & V_102 ) ;
F_79 ( & V_55 ) ;
}
int F_80 ( const struct V_1 * V_2 )
{
return V_2 -> type == & V_100 ;
}
int F_81 ( struct V_4 * V_5 , struct V_117 * V_118 )
{
if ( F_82 ( ! V_5 -> V_49 ) ) {
F_6 ( V_18 , V_5 ,
L_14
L_15 , V_5 -> V_28 -> V_31 ) ;
F_66 () ;
return - V_19 ;
}
return F_83 ( V_5 -> V_49 , V_118 ) ;
}
void F_84 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_49 ) {
F_6 ( V_18 , V_5 ,
L_16
L_15 , V_5 -> V_28 -> V_31 ) ;
F_66 () ;
return;
}
F_14 ( V_5 -> V_49 ) ;
}
