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
F_22 ( V_29 L_3 , V_5 -> V_30 ,
V_27 -> V_31 ? V_27 -> V_31 ( V_5 ) : V_27 -> V_32 ) ;
if ( ! V_5 -> V_33 ) {
F_22 ( V_18 L_4 ,
V_27 -> V_32 ) ;
goto V_34;
}
error = F_23 ( V_5 ) ;
if ( error )
goto V_34;
if ( ! V_5 -> V_3 . V_35 )
V_5 -> V_3 . V_35 = V_2 ? V_2 : & V_36 ;
if ( ! V_25 )
V_25 = V_5 -> V_3 . V_35 ;
V_5 -> V_25 = V_25 ;
error = F_24 ( & V_5 -> V_3 ) ;
if ( error )
goto V_37;
F_25 ( & V_5 -> V_3 ) ;
F_26 ( & V_5 -> V_3 ) ;
F_27 ( & V_5 -> V_3 ) ;
F_4 ( V_5 , V_12 ) ;
F_28 ( V_5 -> V_3 . V_35 ) ;
F_27 ( & V_5 -> V_24 ) ;
error = F_24 ( & V_5 -> V_24 ) ;
if ( error )
goto V_38;
F_28 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_39 -> V_40 ) {
V_5 -> V_41 = F_29 ( V_5 -> V_39 -> V_40 ,
V_42 ) ;
if ( V_5 -> V_41 == NULL ) {
error = - V_43 ;
goto V_44;
}
}
if ( V_5 -> V_39 -> V_45 ) {
snprintf ( V_5 -> V_46 , sizeof( V_5 -> V_46 ) ,
L_5 , V_5 -> V_30 ) ;
V_5 -> V_47 = F_30 (
V_5 -> V_46 ) ;
if ( ! V_5 -> V_47 ) {
error = - V_19 ;
goto V_48;
}
}
error = F_31 ( V_5 ) ;
if ( error )
goto V_49;
F_32 ( V_5 ) ;
return error ;
V_49:
if ( V_5 -> V_47 )
F_33 ( V_5 -> V_47 ) ;
V_48:
F_34 ( V_5 -> V_41 ) ;
V_44:
F_20 ( & V_5 -> V_24 ) ;
V_38:
F_20 ( & V_5 -> V_3 ) ;
V_37:
F_35 ( V_5 ) ;
V_34:
return error ;
}
static void F_36 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_37 ( V_2 ) ;
struct V_1 * V_35 = V_2 -> V_35 ;
struct V_50 * V_51 ;
void * V_52 ;
F_38 ( V_5 -> V_28 ) ;
if ( V_5 -> V_23 )
F_33 ( V_5 -> V_23 ) ;
if ( V_5 -> V_53 )
F_39 ( V_5 -> V_53 ) ;
if ( V_5 -> V_47 )
F_33 ( V_5 -> V_47 ) ;
V_51 = V_5 -> V_54 ;
if ( V_51 ) {
V_52 = V_51 -> V_52 ;
F_40 ( V_51 ) ;
F_34 ( V_52 ) ;
}
F_35 ( V_5 ) ;
if ( V_5 -> V_55 )
F_41 ( V_5 -> V_55 ) ;
F_34 ( V_5 -> V_41 ) ;
if ( V_35 )
F_2 ( V_35 ) ;
F_34 ( V_5 ) ;
}
struct V_4 * F_42 ( struct V_26 * V_27 , int V_56 )
{
struct V_4 * V_5 ;
T_1 V_57 = V_42 ;
if ( V_27 -> V_58 && V_56 )
V_57 |= V_59 ;
V_5 = F_29 ( sizeof( struct V_4 ) + V_56 , V_57 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_22 = & V_5 -> V_60 ;
F_43 ( V_5 -> V_22 ) ;
V_5 -> V_9 = V_10 ;
F_44 ( & V_5 -> V_61 ) ;
F_44 ( & V_5 -> V_62 ) ;
F_44 ( & V_5 -> V_63 ) ;
F_44 ( & V_5 -> V_64 ) ;
F_45 ( & V_5 -> V_65 ) ;
F_46 ( & V_5 -> V_21 ) ;
V_5 -> V_30 = F_47 ( & V_66 ) - 1 ;
V_5 -> V_67 = 0xff ;
V_5 -> V_68 = 0 ;
V_5 -> V_69 = 8 ;
V_5 -> V_70 = 8 ;
V_5 -> V_39 = & V_71 ;
V_5 -> V_72 = 12 ;
V_5 -> V_28 = V_27 ;
V_5 -> V_73 = V_27 -> V_73 ;
V_5 -> V_33 = V_27 -> V_33 ;
V_5 -> V_74 = V_27 -> V_74 ;
V_5 -> V_75 = V_27 -> V_75 ;
V_5 -> V_76 = V_27 -> V_76 ;
V_5 -> V_58 = V_27 -> V_58 ;
V_5 -> V_77 = V_27 -> V_77 ;
V_5 -> V_78 = V_27 -> V_78 ;
V_5 -> V_79 = V_27 -> V_79 ;
if ( V_80 == - 1 )
V_5 -> V_81 = - 1 ;
else if ( ( V_82 ) V_80 * V_83 > V_84 ) {
F_6 ( V_85 , V_5 ,
L_6 ,
V_80 , V_84 / V_83 ) ;
V_5 -> V_81 = V_84 ;
} else
V_5 -> V_81 = V_80 * V_83 ;
if ( V_27 -> V_86 == V_87 )
V_5 -> V_88 = V_89 ;
else
V_5 -> V_88 = V_27 -> V_86 ;
if ( V_27 -> V_90 )
V_5 -> V_90 = V_27 -> V_90 ;
else
V_5 -> V_90 = V_91 ;
if ( V_27 -> V_92 )
V_5 -> V_92 = V_27 -> V_92 ;
else
V_5 -> V_92 = V_93 ;
if ( V_27 -> V_94 )
V_5 -> V_94 = V_27 -> V_94 ;
else
V_5 -> V_94 = 0xffffffff ;
F_48 ( & V_5 -> V_3 ) ;
F_49 ( & V_5 -> V_3 , L_7 , V_5 -> V_30 ) ;
V_5 -> V_3 . V_95 = & V_96 ;
V_5 -> V_3 . type = & V_97 ;
F_48 ( & V_5 -> V_24 ) ;
V_5 -> V_24 . V_35 = & V_5 -> V_3 ;
V_5 -> V_24 . V_98 = & V_99 ;
F_49 ( & V_5 -> V_24 , L_7 , V_5 -> V_30 ) ;
V_5 -> V_24 . V_100 = V_101 ;
V_5 -> V_53 = F_50 ( V_102 , V_5 ,
L_8 , V_5 -> V_30 ) ;
if ( F_51 ( V_5 -> V_53 ) ) {
F_22 ( V_85 L_9 ,
V_5 -> V_30 , F_52 ( V_5 -> V_53 ) ) ;
goto V_103;
}
V_5 -> V_23 = F_53 ( L_10 ,
V_104 | V_105 ,
1 , V_5 -> V_30 ) ;
if ( ! V_5 -> V_23 ) {
F_22 ( V_85 L_11 ,
V_5 -> V_30 ) ;
goto V_106;
}
F_54 ( V_5 -> V_28 ) ;
return V_5 ;
V_106:
F_39 ( V_5 -> V_53 ) ;
V_103:
F_34 ( V_5 ) ;
return NULL ;
}
struct V_4 * F_55 ( struct V_26 * V_27 , int V_56 )
{
struct V_4 * V_5 = F_42 ( V_27 , V_56 ) ;
if ( ! V_27 -> V_107 ) {
F_22 ( V_85 L_12
L_13 , V_27 -> V_32 ) ;
F_56 () ;
}
if ( V_5 )
F_57 ( & V_5 -> V_108 , & V_27 -> V_109 ) ;
return V_5 ;
}
void F_58 ( struct V_4 * V_5 )
{
F_59 ( & V_5 -> V_108 ) ;
F_60 ( V_5 ) ;
}
static int F_61 ( struct V_1 * V_2 , const void * V_110 )
{
struct V_4 * V_111 ;
const unsigned short * V_112 = V_110 ;
V_111 = F_3 ( V_2 ) ;
return V_111 -> V_30 == * V_112 ;
}
struct V_4 * F_62 ( unsigned short V_112 )
{
struct V_1 * V_113 ;
struct V_4 * V_5 = NULL ;
V_113 = F_63 ( & V_99 , NULL , & V_112 ,
F_61 ) ;
if ( V_113 ) {
V_5 = F_64 ( F_3 ( V_113 ) ) ;
F_2 ( V_113 ) ;
}
return V_5 ;
}
struct V_4 * F_64 ( struct V_4 * V_5 )
{
if ( ( V_5 -> V_9 == V_16 ) ||
! F_28 ( & V_5 -> V_3 ) )
return NULL ;
return V_5 ;
}
void F_60 ( struct V_4 * V_5 )
{
F_2 ( & V_5 -> V_3 ) ;
}
int F_65 ( void )
{
return F_66 ( & V_99 ) ;
}
void F_67 ( void )
{
F_68 ( & V_99 ) ;
}
int F_69 ( const struct V_1 * V_2 )
{
return V_2 -> type == & V_97 ;
}
int F_70 ( struct V_4 * V_5 , struct V_114 * V_115 )
{
if ( F_71 ( ! V_5 -> V_47 ) ) {
F_22 ( V_18
L_14
L_15 , V_5 -> V_28 -> V_32 ) ;
F_56 () ;
return - V_19 ;
}
return F_72 ( V_5 -> V_47 , V_115 ) ;
}
void F_73 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_47 ) {
F_22 ( V_18
L_16
L_15 , V_5 -> V_28 -> V_32 ) ;
F_56 () ;
return;
}
F_14 ( V_5 -> V_47 ) ;
}
