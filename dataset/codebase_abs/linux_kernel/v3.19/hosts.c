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
}
error = F_24 ( V_5 ) ;
if ( error )
goto V_34;
if ( ! V_5 -> V_3 . V_35 )
V_5 -> V_3 . V_35 = V_2 ? V_2 : & V_36 ;
if ( ! V_25 )
V_25 = V_5 -> V_3 . V_35 ;
V_5 -> V_25 = V_25 ;
error = F_25 ( & V_5 -> V_3 ) ;
if ( error )
goto V_37;
F_26 ( & V_5 -> V_3 ) ;
F_27 ( & V_5 -> V_3 ) ;
F_28 ( & V_5 -> V_3 ) ;
F_4 ( V_5 , V_12 ) ;
F_29 ( V_5 -> V_3 . V_35 ) ;
F_28 ( & V_5 -> V_24 ) ;
error = F_25 ( & V_5 -> V_24 ) ;
if ( error )
goto V_38;
F_29 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_39 -> V_40 ) {
V_5 -> V_41 = F_30 ( V_5 -> V_39 -> V_40 ,
V_42 ) ;
if ( V_5 -> V_41 == NULL ) {
error = - V_43 ;
goto V_44;
}
}
if ( V_5 -> V_39 -> V_45 ) {
snprintf ( V_5 -> V_46 , sizeof( V_5 -> V_46 ) ,
L_5 , V_5 -> V_47 ) ;
V_5 -> V_48 = F_31 (
V_5 -> V_46 ) ;
if ( ! V_5 -> V_48 ) {
error = - V_19 ;
goto V_49;
}
}
error = F_32 ( V_5 ) ;
if ( error )
goto V_50;
F_33 ( V_5 ) ;
return error ;
V_50:
if ( V_5 -> V_48 )
F_34 ( V_5 -> V_48 ) ;
V_49:
F_35 ( V_5 -> V_41 ) ;
V_44:
F_20 ( & V_5 -> V_24 ) ;
V_38:
F_20 ( & V_5 -> V_3 ) ;
V_37:
F_36 ( V_5 ) ;
V_34:
if ( F_22 ( V_5 ) )
F_37 ( V_5 ) ;
V_33:
return error ;
}
static void F_38 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_39 ( V_2 ) ;
struct V_1 * V_35 = V_2 -> V_35 ;
struct V_51 * V_52 ;
void * V_53 ;
F_40 ( V_5 -> V_28 ) ;
if ( V_5 -> V_23 )
F_34 ( V_5 -> V_23 ) ;
if ( V_5 -> V_54 )
F_41 ( V_5 -> V_54 ) ;
if ( V_5 -> V_48 )
F_34 ( V_5 -> V_48 ) ;
V_52 = V_5 -> V_55 ;
if ( V_52 ) {
V_53 = V_52 -> V_53 ;
F_42 ( V_52 ) ;
F_35 ( V_53 ) ;
}
F_36 ( V_5 ) ;
if ( F_22 ( V_5 ) ) {
if ( V_5 -> V_56 . V_57 )
F_37 ( V_5 ) ;
} else {
if ( V_5 -> V_58 )
F_43 ( V_5 -> V_58 ) ;
}
F_35 ( V_5 -> V_41 ) ;
if ( V_35 )
F_2 ( V_35 ) ;
F_35 ( V_5 ) ;
}
struct V_4 * F_44 ( struct V_26 * V_27 , int V_59 )
{
struct V_4 * V_5 ;
T_1 V_60 = V_42 ;
if ( V_27 -> V_61 && V_59 )
V_60 |= V_62 ;
V_5 = F_30 ( sizeof( struct V_4 ) + V_59 , V_60 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_22 = & V_5 -> V_63 ;
F_45 ( V_5 -> V_22 ) ;
V_5 -> V_9 = V_10 ;
F_46 ( & V_5 -> V_64 ) ;
F_46 ( & V_5 -> V_65 ) ;
F_46 ( & V_5 -> V_66 ) ;
F_46 ( & V_5 -> V_67 ) ;
F_47 ( & V_5 -> V_68 ) ;
F_48 ( & V_5 -> V_21 ) ;
V_5 -> V_47 = F_49 ( & V_69 ) - 1 ;
V_5 -> V_70 = 0xff ;
V_5 -> V_71 = 0 ;
V_5 -> V_72 = 8 ;
V_5 -> V_73 = 8 ;
V_5 -> V_39 = & V_74 ;
V_5 -> V_75 = 12 ;
V_5 -> V_28 = V_27 ;
V_5 -> V_76 = V_27 -> V_76 ;
V_5 -> V_32 = V_27 -> V_32 ;
V_5 -> V_77 = V_27 -> V_77 ;
V_5 -> V_78 = V_27 -> V_78 ;
V_5 -> V_79 = V_27 -> V_79 ;
V_5 -> V_61 = V_27 -> V_61 ;
V_5 -> V_80 = V_27 -> V_80 ;
V_5 -> V_81 = V_27 -> V_81 ;
if ( V_82 == - 1 || ! V_27 -> V_83 )
V_5 -> V_84 = - 1 ;
else if ( ( V_85 ) V_82 * V_86 > V_87 ) {
F_6 ( V_88 , V_5 ,
L_6 ,
V_82 , V_87 / V_86 ) ;
V_5 -> V_84 = V_87 ;
} else
V_5 -> V_84 = V_82 * V_86 ;
if ( V_27 -> V_89 == V_90 )
V_5 -> V_91 = V_92 ;
else
V_5 -> V_91 = V_27 -> V_89 ;
if ( V_27 -> V_93 )
V_5 -> V_93 = V_27 -> V_93 ;
else
V_5 -> V_93 = V_94 ;
if ( V_27 -> V_95 )
V_5 -> V_95 = V_27 -> V_95 ;
else
V_5 -> V_95 = V_96 ;
if ( V_27 -> V_97 )
V_5 -> V_97 = V_27 -> V_97 ;
else
V_5 -> V_97 = 0xffffffff ;
V_5 -> V_98 = V_99 && ! V_5 -> V_28 -> V_100 ;
F_50 ( & V_5 -> V_3 ) ;
F_51 ( & V_5 -> V_3 , L_7 , V_5 -> V_47 ) ;
V_5 -> V_3 . V_101 = & V_102 ;
V_5 -> V_3 . type = & V_103 ;
F_50 ( & V_5 -> V_24 ) ;
V_5 -> V_24 . V_35 = & V_5 -> V_3 ;
V_5 -> V_24 . V_104 = & V_105 ;
F_51 ( & V_5 -> V_24 , L_7 , V_5 -> V_47 ) ;
V_5 -> V_24 . V_106 = V_107 ;
V_5 -> V_54 = F_52 ( V_108 , V_5 ,
L_8 , V_5 -> V_47 ) ;
if ( F_53 ( V_5 -> V_54 ) ) {
F_6 ( V_88 , V_5 ,
L_9 ,
F_54 ( V_5 -> V_54 ) ) ;
goto V_109;
}
V_5 -> V_23 = F_55 ( L_10 ,
V_110 | V_111 ,
1 , V_5 -> V_47 ) ;
if ( ! V_5 -> V_23 ) {
F_6 ( V_88 , V_5 ,
L_11 ) ;
goto V_112;
}
F_56 ( V_5 -> V_28 ) ;
return V_5 ;
V_112:
F_41 ( V_5 -> V_54 ) ;
V_109:
F_35 ( V_5 ) ;
return NULL ;
}
struct V_4 * F_57 ( struct V_26 * V_27 , int V_59 )
{
struct V_4 * V_5 = F_44 ( V_27 , V_59 ) ;
if ( ! V_27 -> V_113 ) {
F_58 ( V_88 L_12
L_13 , V_27 -> V_31 ) ;
F_59 () ;
}
if ( V_5 )
F_60 ( & V_5 -> V_114 , & V_27 -> V_115 ) ;
return V_5 ;
}
void F_61 ( struct V_4 * V_5 )
{
F_62 ( & V_5 -> V_114 ) ;
F_63 ( V_5 ) ;
}
static int F_64 ( struct V_1 * V_2 , const void * V_116 )
{
struct V_4 * V_117 ;
const unsigned short * V_118 = V_116 ;
V_117 = F_3 ( V_2 ) ;
return V_117 -> V_47 == * V_118 ;
}
struct V_4 * F_65 ( unsigned short V_118 )
{
struct V_1 * V_119 ;
struct V_4 * V_5 = NULL ;
V_119 = F_66 ( & V_105 , NULL , & V_118 ,
F_64 ) ;
if ( V_119 ) {
V_5 = F_67 ( F_3 ( V_119 ) ) ;
F_2 ( V_119 ) ;
}
return V_5 ;
}
struct V_4 * F_67 ( struct V_4 * V_5 )
{
if ( ( V_5 -> V_9 == V_16 ) ||
! F_29 ( & V_5 -> V_3 ) )
return NULL ;
return V_5 ;
}
void F_63 ( struct V_4 * V_5 )
{
F_2 ( & V_5 -> V_3 ) ;
}
int F_68 ( void )
{
return F_69 ( & V_105 ) ;
}
void F_70 ( void )
{
F_71 ( & V_105 ) ;
}
int F_72 ( const struct V_1 * V_2 )
{
return V_2 -> type == & V_103 ;
}
int F_73 ( struct V_4 * V_5 , struct V_120 * V_121 )
{
if ( F_74 ( ! V_5 -> V_48 ) ) {
F_6 ( V_18 , V_5 ,
L_14
L_15 , V_5 -> V_28 -> V_31 ) ;
F_59 () ;
return - V_19 ;
}
return F_75 ( V_5 -> V_48 , V_121 ) ;
}
void F_76 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_48 ) {
F_6 ( V_18 , V_5 ,
L_16
L_15 , V_5 -> V_28 -> V_31 ) ;
F_59 () ;
return;
}
F_14 ( V_5 -> V_48 ) ;
}
