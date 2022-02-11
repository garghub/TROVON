static const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
case V_5 :
return L_3 ;
case V_6 :
return L_4 ;
case V_7 :
return L_5 ;
case V_8 :
return L_6 ;
case V_9 :
return L_7 ;
case V_10 :
return L_8 ;
case V_11 :
return L_9 ;
case V_12 :
return L_10 ;
case V_13 :
return L_11 ;
case V_14 :
return L_12 ;
case V_15 :
return L_13 ;
case V_16 :
return L_14 ;
case V_17 :
return L_15 ;
case V_18 :
return L_16 ;
case V_19 :
return L_17 ;
case V_20 :
return L_18 ;
case V_21 :
return L_19 ;
case V_22 :
return L_20 ;
case V_23 :
return L_21 ;
case V_24 :
return L_22 ;
case V_25 :
return L_23 ;
case V_26 :
return L_24 ;
case V_27 :
return L_25 ;
case V_28 :
return L_26 ;
case V_29 :
return L_27 ;
case V_30 :
return L_28 ;
case V_31 :
return L_29 ;
case V_32 :
return L_30 ;
case V_33 :
return L_31 ;
}
return L_32 ;
}
struct V_34 * F_2 ( struct V_35 * V_36 )
{
struct V_34 * V_34 ;
V_34 = F_3 ( sizeof( struct V_34 ) , V_37 ) ;
if ( ! V_34 )
return NULL ;
V_34 -> V_38 = V_36 ;
V_34 -> V_39 = false ;
F_4 ( & V_34 -> V_40 ) ;
F_5 ( & V_34 -> V_41 ) ;
F_5 ( & V_34 -> V_42 ) ;
F_6 ( & V_34 -> V_43 ) ;
F_6 ( & V_34 -> V_44 ) ;
F_7 ( & V_34 -> V_45 ) ;
F_8 ( & V_34 -> V_46 ) ;
F_9 ( & V_34 -> V_47 , V_48 ,
( unsigned long ) V_34 ) ;
return V_34 ;
}
void F_10 ( struct V_35 * V_36 )
{
struct V_34 * V_34 = V_36 -> V_34 ;
F_11 ( & V_34 -> V_43 ) ;
V_34 -> V_39 = true ;
F_12 ( & V_34 -> V_43 ) ;
F_13 ( V_36 -> V_34 ) ;
}
void F_14 ( struct V_35 * V_36 )
{
unsigned long V_49 ;
F_15 ( & V_36 -> V_34 -> V_47 ) ;
F_16 ( & V_36 -> V_34 -> V_41 , V_49 ) ;
F_17 ( & V_36 -> V_34 -> V_40 ) ;
F_18 ( & V_36 -> V_34 -> V_41 , V_49 ) ;
}
void V_48 ( unsigned long V_50 )
{
struct V_34 * V_34 = (struct V_34 * ) V_50 ;
struct V_35 * V_36 = V_34 -> V_38 ;
struct V_51 * V_52 ;
void * V_53 ;
struct V_54 * V_55 ;
struct V_56 * V_57 = NULL ;
unsigned long V_49 ;
T_1 V_58 ;
do {
F_16 ( & V_34 -> V_41 , V_49 ) ;
V_57 = F_19 ( & V_34 -> V_40 ) ;
if ( ! V_57 ) {
F_18 ( & V_34 -> V_41 , V_49 ) ;
return;
}
F_18 ( & V_34 -> V_41 , V_49 ) ;
V_52 = (struct V_51 * ) V_57 -> V_50 ;
V_58 = F_20 ( V_52 -> V_59 ) ;
V_53 = F_21 ( V_57 , sizeof( struct V_51 ) ) ;
switch ( V_58 ) {
case V_60 :
V_55 = (struct V_54 * ) V_53 ;
F_22 ( V_36 , V_55 ) ;
break;
case V_61 :
F_23 ( V_34 -> V_38 -> V_62 ,
& V_34 -> V_38 -> V_63 ) ;
break;
case V_64 :
F_24 ( & V_36 -> V_65 . V_66 ) ;
if ( V_36 -> V_65 . V_49 & V_67 ) {
F_25 ( & V_36 -> V_65 . V_66 ) ;
break;
}
F_25 ( & V_36 -> V_65 . V_66 ) ;
F_26 ( V_36 , V_53 ) ;
break;
default:
break;
}
F_27 ( V_57 ) ;
} while ( 1 );
}
void F_28 ( struct V_68 * V_69 )
{
struct V_35 * V_36 = F_29 ( V_69 , struct V_35 ,
V_63 ) ;
struct V_70 * V_71 = F_30 ( V_36 -> V_72 ) ;
F_31 ( V_71 , V_73 , L_33 ) ;
F_32 ( V_36 ) ;
}
static void F_33 ( struct V_34 * V_34 , struct V_56 * V_57 )
{
F_21 ( V_57 , sizeof( struct V_51 ) ) ;
if ( V_34 -> V_74 != NULL && V_34 -> V_75 != 0 )
memcpy ( V_34 -> V_74 , V_57 -> V_50 , V_34 -> V_75 ) ;
F_34 ( & V_34 -> V_45 ) ;
}
static void F_35 ( void * V_36 , struct V_56 * V_57 ,
enum V_76 V_77 )
{
struct V_34 * V_34 = (struct V_34 * ) V_36 ;
struct V_51 * V_52 ;
T_1 V_58 ;
if ( F_36 ( V_34 -> V_39 ) )
goto V_78;
V_52 = (struct V_51 * ) V_57 -> V_50 ;
V_58 = F_20 ( V_52 -> V_59 ) ;
if ( V_58 & 0x1000 ) {
F_37 ( & V_34 -> V_41 ) ;
F_38 ( & V_34 -> V_40 , V_57 ) ;
F_39 ( & V_34 -> V_41 ) ;
F_40 ( & V_34 -> V_47 ) ;
return;
}
F_37 ( & V_34 -> V_41 ) ;
if ( V_58 != V_34 -> V_79 ) {
F_39 ( & V_34 -> V_41 ) ;
goto V_78;
}
F_39 ( & V_34 -> V_41 ) ;
F_33 ( V_34 , V_57 ) ;
V_78:
F_27 ( V_57 ) ;
}
static void F_41 ( void * V_36 , struct V_56 * V_57 ,
enum V_76 V_77 , bool V_80 )
{
F_27 ( V_57 ) ;
}
int F_42 ( struct V_81 * V_82 , struct V_34 * V_34 ,
enum V_76 * V_83 )
{
struct V_84 V_85 ;
int V_86 ;
V_34 -> V_82 = V_82 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_87 . V_36 = V_34 ;
V_85 . V_87 . V_65 = F_41 ;
V_85 . V_87 . V_88 = F_35 ;
V_85 . V_89 = V_90 ;
V_86 = F_43 ( V_82 , & V_85 , & V_34 -> V_91 ) ;
if ( V_86 )
return V_86 ;
* V_83 = V_34 -> V_91 ;
return 0 ;
}
static int F_44 ( struct V_34 * V_34 ,
struct V_56 * V_57 ,
enum V_1 V_92 , T_1 V_93 )
{
struct V_51 * V_52 ;
V_52 = (struct V_51 * ) F_45 ( V_57 , sizeof( struct V_51 ) ) ;
V_52 -> V_59 = F_46 ( V_92 ) ;
V_52 -> V_94 = F_46 ( ++ V_34 -> V_95 ) ;
return F_47 ( V_34 -> V_82 , V_57 , V_34 -> V_91 ) ;
}
int F_48 ( struct V_34 * V_34 , enum V_1 V_58 ,
T_2 * V_96 , T_3 V_97 ,
T_2 * V_98 , T_3 V_99 ,
T_3 V_100 )
{
struct V_101 * V_72 = V_34 -> V_38 -> V_72 ;
struct V_70 * V_71 = F_30 ( V_72 ) ;
T_1 V_102 = sizeof( struct V_103 ) +
sizeof( struct V_51 ) ;
struct V_56 * V_57 ;
T_2 * V_50 ;
int V_104 , V_86 = 0 ;
unsigned long V_49 ;
if ( V_72 -> V_105 & V_106 )
return 0 ;
V_57 = F_49 ( V_102 + V_97 , V_107 ) ;
if ( ! V_57 )
return - V_108 ;
F_50 ( V_57 , V_102 ) ;
if ( V_97 != 0 && V_96 != NULL ) {
V_50 = ( T_2 * ) F_51 ( V_57 , V_97 ) ;
memcpy ( V_50 , V_96 , V_97 ) ;
}
F_11 ( & V_34 -> V_43 ) ;
if ( F_36 ( V_34 -> V_39 ) ) {
V_86 = - V_109 ;
goto V_110;
}
V_34 -> V_74 = V_98 ;
V_34 -> V_75 = V_99 ;
F_16 ( & V_34 -> V_41 , V_49 ) ;
V_34 -> V_79 = V_58 ;
F_18 ( & V_34 -> V_41 , V_49 ) ;
V_86 = F_44 ( V_34 , V_57 , V_58 , V_97 ) ;
if ( V_86 )
goto V_110;
V_104 = F_52 ( & V_34 -> V_45 , V_100 ) ;
if ( ! V_104 ) {
F_31 ( V_71 , V_111 ,
L_34 ,
F_1 ( V_58 ) ) ;
F_12 ( & V_34 -> V_43 ) ;
return - V_112 ;
}
F_12 ( & V_34 -> V_43 ) ;
return 0 ;
V_110:
F_31 ( V_71 , V_111 ,
L_35 , F_1 ( V_58 ) ) ;
F_12 ( & V_34 -> V_43 ) ;
F_27 ( V_57 ) ;
return V_86 ;
}
