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
F_14 ( V_5 ) ;
F_12 ( & V_5 -> V_21 ) ;
F_15 ( V_5 ) ;
F_10 ( V_5 -> V_22 , V_20 ) ;
if ( F_4 ( V_5 , V_16 ) )
F_16 ( F_4 ( V_5 , V_17 ) ) ;
F_11 ( V_5 -> V_22 , V_20 ) ;
F_17 ( & V_5 -> V_3 ) ;
F_18 ( & V_5 -> V_23 ) ;
F_19 ( & V_5 -> V_3 ) ;
}
int F_20 ( struct V_4 * V_5 , struct V_1 * V_2 ,
struct V_1 * V_24 )
{
struct V_25 * V_26 = V_5 -> V_27 ;
int error = - V_19 ;
F_21 ( V_28 L_3 , V_5 -> V_29 ,
V_26 -> V_30 ? V_26 -> V_30 ( V_5 ) : V_26 -> V_31 ) ;
if ( ! V_5 -> V_32 ) {
F_21 ( V_18 L_4 ,
V_26 -> V_31 ) ;
goto V_33;
}
error = F_22 ( V_5 ) ;
if ( error )
goto V_33;
if ( ! V_5 -> V_3 . V_34 )
V_5 -> V_3 . V_34 = V_2 ? V_2 : & V_35 ;
if ( ! V_24 )
V_24 = V_5 -> V_3 . V_34 ;
V_5 -> V_24 = V_24 ;
error = F_23 ( & V_5 -> V_3 ) ;
if ( error )
goto V_36;
F_24 ( & V_5 -> V_3 ) ;
F_25 ( & V_5 -> V_3 ) ;
F_26 ( & V_5 -> V_3 ) ;
F_4 ( V_5 , V_12 ) ;
F_27 ( V_5 -> V_3 . V_34 ) ;
F_26 ( & V_5 -> V_23 ) ;
error = F_23 ( & V_5 -> V_23 ) ;
if ( error )
goto V_37;
F_27 ( & V_5 -> V_3 ) ;
if ( V_5 -> V_38 -> V_39 ) {
V_5 -> V_40 = F_28 ( V_5 -> V_38 -> V_39 ,
V_41 ) ;
if ( V_5 -> V_40 == NULL ) {
error = - V_42 ;
goto V_43;
}
}
if ( V_5 -> V_38 -> V_44 ) {
snprintf ( V_5 -> V_45 , sizeof( V_5 -> V_45 ) ,
L_5 , V_5 -> V_29 ) ;
V_5 -> V_46 = F_29 (
V_5 -> V_45 ) ;
if ( ! V_5 -> V_46 ) {
error = - V_19 ;
goto V_47;
}
}
error = F_30 ( V_5 ) ;
if ( error )
goto V_48;
F_31 ( V_5 ) ;
return error ;
V_48:
if ( V_5 -> V_46 )
F_32 ( V_5 -> V_46 ) ;
V_47:
F_33 ( V_5 -> V_40 ) ;
V_43:
F_19 ( & V_5 -> V_23 ) ;
V_37:
F_19 ( & V_5 -> V_3 ) ;
V_36:
F_34 ( V_5 ) ;
V_33:
return error ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_36 ( V_2 ) ;
struct V_1 * V_34 = V_2 -> V_34 ;
struct V_49 * V_50 ;
void * V_51 ;
F_37 ( V_5 -> V_27 ) ;
if ( V_5 -> V_52 )
F_38 ( V_5 -> V_52 ) ;
if ( V_5 -> V_46 )
F_32 ( V_5 -> V_46 ) ;
V_50 = V_5 -> V_53 ;
if ( V_50 ) {
V_51 = V_50 -> V_51 ;
F_39 ( V_50 ) ;
F_33 ( V_51 ) ;
}
F_34 ( V_5 ) ;
if ( V_5 -> V_54 )
F_40 ( V_5 -> V_54 ) ;
F_33 ( V_5 -> V_40 ) ;
if ( V_34 )
F_2 ( V_34 ) ;
F_33 ( V_5 ) ;
}
struct V_4 * F_41 ( struct V_25 * V_26 , int V_55 )
{
struct V_4 * V_5 ;
T_1 V_56 = V_41 ;
if ( V_26 -> V_57 && V_55 )
V_56 |= V_58 ;
V_5 = F_28 ( sizeof( struct V_4 ) + V_55 , V_56 ) ;
if ( ! V_5 )
return NULL ;
V_5 -> V_22 = & V_5 -> V_59 ;
F_42 ( V_5 -> V_22 ) ;
V_5 -> V_9 = V_10 ;
F_43 ( & V_5 -> V_60 ) ;
F_43 ( & V_5 -> V_61 ) ;
F_43 ( & V_5 -> V_62 ) ;
F_43 ( & V_5 -> V_63 ) ;
F_44 ( & V_5 -> V_64 ) ;
F_45 ( & V_5 -> V_21 ) ;
V_5 -> V_29 = F_46 ( & V_65 ) - 1 ;
V_5 -> V_66 = 0xff ;
V_5 -> V_67 = 0 ;
V_5 -> V_68 = 8 ;
V_5 -> V_69 = 8 ;
V_5 -> V_38 = & V_70 ;
V_5 -> V_71 = 12 ;
V_5 -> V_27 = V_26 ;
V_5 -> V_72 = V_26 -> V_72 ;
V_5 -> V_32 = V_26 -> V_32 ;
V_5 -> V_73 = V_26 -> V_73 ;
V_5 -> V_74 = V_26 -> V_74 ;
V_5 -> V_75 = V_26 -> V_75 ;
V_5 -> V_57 = V_26 -> V_57 ;
V_5 -> V_76 = V_26 -> V_76 ;
V_5 -> V_77 = V_26 -> V_77 ;
if ( V_26 -> V_78 == V_79 )
V_5 -> V_80 = V_81 ;
else
V_5 -> V_80 = V_26 -> V_78 ;
if ( V_26 -> V_82 )
V_5 -> V_82 = V_26 -> V_82 ;
else
V_5 -> V_82 = V_83 ;
if ( V_26 -> V_84 )
V_5 -> V_84 = V_26 -> V_84 ;
else
V_5 -> V_84 = V_85 ;
if ( V_26 -> V_86 )
V_5 -> V_86 = V_26 -> V_86 ;
else
V_5 -> V_86 = 0xffffffff ;
F_47 ( & V_5 -> V_3 ) ;
F_48 ( & V_5 -> V_3 , L_6 , V_5 -> V_29 ) ;
V_5 -> V_3 . V_87 = & V_88 ;
V_5 -> V_3 . type = & V_89 ;
F_47 ( & V_5 -> V_23 ) ;
V_5 -> V_23 . V_34 = & V_5 -> V_3 ;
V_5 -> V_23 . V_90 = & V_91 ;
F_48 ( & V_5 -> V_23 , L_6 , V_5 -> V_29 ) ;
V_5 -> V_23 . V_92 = V_93 ;
V_5 -> V_52 = F_49 ( V_94 , V_5 ,
L_7 , V_5 -> V_29 ) ;
if ( F_50 ( V_5 -> V_52 ) ) {
F_21 ( V_95 L_8 ,
V_5 -> V_29 , F_51 ( V_5 -> V_52 ) ) ;
goto V_96;
}
F_52 ( V_5 -> V_27 ) ;
return V_5 ;
V_96:
F_33 ( V_5 ) ;
return NULL ;
}
struct V_4 * F_53 ( struct V_25 * V_26 , int V_55 )
{
struct V_4 * V_5 = F_41 ( V_26 , V_55 ) ;
if ( ! V_26 -> V_97 ) {
F_21 ( V_95 L_9
L_10 , V_26 -> V_31 ) ;
F_54 () ;
}
if ( V_5 )
F_55 ( & V_5 -> V_98 , & V_26 -> V_99 ) ;
return V_5 ;
}
void F_56 ( struct V_4 * V_5 )
{
F_57 ( & V_5 -> V_98 ) ;
F_58 ( V_5 ) ;
}
static int F_59 ( struct V_1 * V_2 , void * V_100 )
{
struct V_4 * V_101 ;
unsigned short * V_102 = ( unsigned short * ) V_100 ;
V_101 = F_3 ( V_2 ) ;
return V_101 -> V_29 == * V_102 ;
}
struct V_4 * F_60 ( unsigned short V_102 )
{
struct V_1 * V_103 ;
struct V_4 * V_5 = NULL ;
V_103 = F_61 ( & V_91 , NULL , & V_102 ,
F_59 ) ;
if ( V_103 ) {
V_5 = F_62 ( F_3 ( V_103 ) ) ;
F_2 ( V_103 ) ;
}
return V_5 ;
}
struct V_4 * F_62 ( struct V_4 * V_5 )
{
if ( ( V_5 -> V_9 == V_16 ) ||
! F_27 ( & V_5 -> V_3 ) )
return NULL ;
return V_5 ;
}
void F_58 ( struct V_4 * V_5 )
{
F_2 ( & V_5 -> V_3 ) ;
}
int F_63 ( void )
{
return F_64 ( & V_91 ) ;
}
void F_65 ( void )
{
F_66 ( & V_91 ) ;
}
int F_67 ( const struct V_1 * V_2 )
{
return V_2 -> type == & V_89 ;
}
int F_68 ( struct V_4 * V_5 , struct V_104 * V_105 )
{
if ( F_69 ( ! V_5 -> V_46 ) ) {
F_21 ( V_18
L_11
L_12 , V_5 -> V_27 -> V_31 ) ;
F_54 () ;
return - V_19 ;
}
return F_70 ( V_5 -> V_46 , V_105 ) ;
}
void F_71 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_46 ) {
F_21 ( V_18
L_13
L_12 , V_5 -> V_27 -> V_31 ) ;
F_54 () ;
return;
}
F_72 ( V_5 -> V_46 ) ;
}
