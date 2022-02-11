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
case V_34 :
return L_32 ;
}
return L_33 ;
}
struct V_35 * F_2 ( struct V_36 * V_37 )
{
struct V_35 * V_35 ;
V_35 = F_3 ( sizeof( struct V_35 ) , V_38 ) ;
if ( ! V_35 )
return NULL ;
V_35 -> V_39 = V_37 ;
V_35 -> V_40 = false ;
F_4 ( & V_35 -> V_41 ) ;
F_5 ( & V_35 -> V_42 ) ;
F_5 ( & V_35 -> V_43 ) ;
F_6 ( & V_35 -> V_44 ) ;
F_6 ( & V_35 -> V_45 ) ;
F_6 ( & V_35 -> V_46 ) ;
F_7 ( & V_35 -> V_47 ) ;
F_8 ( & V_35 -> V_48 ) ;
F_9 ( & V_35 -> V_49 , V_50 ,
( unsigned long ) V_35 ) ;
return V_35 ;
}
void F_10 ( struct V_36 * V_37 )
{
struct V_35 * V_35 = V_37 -> V_35 ;
F_11 ( & V_35 -> V_44 ) ;
V_35 -> V_40 = true ;
F_12 ( & V_35 -> V_44 ) ;
F_13 ( V_37 -> V_35 ) ;
}
void F_14 ( struct V_36 * V_37 )
{
unsigned long V_51 ;
F_15 ( & V_37 -> V_35 -> V_49 ) ;
F_16 ( & V_37 -> V_35 -> V_42 , V_51 ) ;
F_17 ( & V_37 -> V_35 -> V_41 ) ;
F_18 ( & V_37 -> V_35 -> V_42 , V_51 ) ;
}
void V_50 ( unsigned long V_52 )
{
struct V_35 * V_35 = (struct V_35 * ) V_52 ;
struct V_36 * V_37 = V_35 -> V_39 ;
struct V_53 * V_54 ;
void * V_55 ;
struct V_56 * V_57 ;
struct V_58 * V_59 = NULL ;
unsigned long V_51 ;
T_1 V_60 ;
do {
F_16 ( & V_35 -> V_42 , V_51 ) ;
V_59 = F_19 ( & V_35 -> V_41 ) ;
if ( ! V_59 ) {
F_18 ( & V_35 -> V_42 , V_51 ) ;
return;
}
F_18 ( & V_35 -> V_42 , V_51 ) ;
V_54 = (struct V_53 * ) V_59 -> V_52 ;
V_60 = F_20 ( V_54 -> V_61 ) ;
V_55 = F_21 ( V_59 , sizeof( struct V_53 ) ) ;
switch ( V_60 ) {
case V_62 :
V_57 = (struct V_56 * ) V_55 ;
F_22 ( V_37 , V_57 ) ;
break;
case V_63 :
F_23 ( V_35 -> V_39 -> V_64 ,
& V_35 -> V_39 -> V_65 ) ;
break;
case V_66 :
F_24 ( & V_37 -> V_67 . V_68 ) ;
if ( V_37 -> V_67 . V_51 & V_69 ) {
F_25 ( & V_37 -> V_67 . V_68 ) ;
break;
}
F_25 ( & V_37 -> V_67 . V_68 ) ;
F_26 ( V_37 , V_55 ) ;
break;
default:
break;
}
F_27 ( V_59 ) ;
} while ( 1 );
}
void F_28 ( struct V_70 * V_71 )
{
struct V_36 * V_37 = F_29 ( V_71 , struct V_36 ,
V_65 ) ;
struct V_72 * V_73 = F_30 ( V_37 -> V_74 ) ;
F_31 ( V_73 , V_75 , L_34 ) ;
F_32 ( V_37 ) ;
}
static void F_33 ( struct V_35 * V_35 , struct V_58 * V_59 )
{
F_21 ( V_59 , sizeof( struct V_53 ) ) ;
if ( V_35 -> V_76 != NULL && V_35 -> V_77 != 0 )
memcpy ( V_35 -> V_76 , V_59 -> V_52 , V_35 -> V_77 ) ;
F_34 ( & V_35 -> V_47 ) ;
}
static void F_35 ( void * V_37 , struct V_58 * V_59 ,
enum V_78 V_79 )
{
struct V_35 * V_35 = (struct V_35 * ) V_37 ;
struct V_53 * V_54 ;
T_1 V_60 ;
if ( F_36 ( V_35 -> V_40 ) )
goto V_80;
V_54 = (struct V_53 * ) V_59 -> V_52 ;
V_60 = F_20 ( V_54 -> V_61 ) ;
if ( V_60 & 0x1000 ) {
F_37 ( & V_35 -> V_42 ) ;
F_38 ( & V_35 -> V_41 , V_59 ) ;
F_39 ( & V_35 -> V_42 ) ;
F_40 ( & V_35 -> V_49 ) ;
return;
}
F_37 ( & V_35 -> V_42 ) ;
if ( F_20 ( V_54 -> V_81 ) != V_35 -> V_82 ) {
F_39 ( & V_35 -> V_42 ) ;
goto V_80;
}
F_39 ( & V_35 -> V_42 ) ;
F_33 ( V_35 , V_59 ) ;
V_80:
F_27 ( V_59 ) ;
}
static void F_41 ( void * V_37 , struct V_58 * V_59 ,
enum V_78 V_79 , bool V_83 )
{
F_27 ( V_59 ) ;
}
int F_42 ( struct V_84 * V_85 , struct V_35 * V_35 ,
enum V_78 * V_86 )
{
struct V_87 V_88 ;
int V_89 ;
V_35 -> V_85 = V_85 ;
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_90 . V_37 = V_35 ;
V_88 . V_90 . V_67 = F_41 ;
V_88 . V_90 . V_91 = F_35 ;
V_88 . V_92 = V_93 ;
V_89 = F_43 ( V_85 , & V_88 , & V_35 -> V_94 ) ;
if ( V_89 )
return V_89 ;
* V_86 = V_35 -> V_94 ;
return 0 ;
}
static int F_44 ( struct V_35 * V_35 ,
struct V_58 * V_59 ,
enum V_1 V_95 , T_1 V_96 )
{
struct V_53 * V_54 ;
unsigned long V_51 ;
V_54 = (struct V_53 * ) F_45 ( V_59 , sizeof( struct V_53 ) ) ;
V_54 -> V_61 = F_46 ( V_95 ) ;
V_54 -> V_81 = F_46 ( ++ V_35 -> V_97 ) ;
F_16 ( & V_35 -> V_42 , V_51 ) ;
V_35 -> V_82 = V_35 -> V_97 ;
F_18 ( & V_35 -> V_42 , V_51 ) ;
return F_47 ( V_35 -> V_85 , V_59 , V_35 -> V_94 ) ;
}
int F_48 ( struct V_35 * V_35 , enum V_1 V_60 ,
T_2 * V_98 , T_3 V_99 ,
T_2 * V_100 , T_3 V_101 ,
T_3 V_102 )
{
struct V_103 * V_74 = V_35 -> V_39 -> V_74 ;
struct V_72 * V_73 = F_30 ( V_74 ) ;
T_1 V_104 = sizeof( struct V_105 ) +
sizeof( struct V_53 ) ;
struct V_58 * V_59 ;
T_2 * V_52 ;
int V_106 , V_89 = 0 ;
if ( V_74 -> V_107 & V_108 )
return 0 ;
V_59 = F_49 ( V_104 + V_99 , V_109 ) ;
if ( ! V_59 )
return - V_110 ;
F_50 ( V_59 , V_104 ) ;
if ( V_99 != 0 && V_98 != NULL ) {
V_52 = ( T_2 * ) F_51 ( V_59 , V_99 ) ;
memcpy ( V_52 , V_98 , V_99 ) ;
}
F_11 ( & V_35 -> V_44 ) ;
if ( F_36 ( V_35 -> V_40 ) ) {
V_89 = - V_111 ;
goto V_112;
}
V_35 -> V_76 = V_100 ;
V_35 -> V_77 = V_101 ;
V_89 = F_44 ( V_35 , V_59 , V_60 , V_99 ) ;
if ( V_89 )
goto V_112;
V_106 = F_52 ( & V_35 -> V_47 , V_102 ) ;
if ( ! V_106 ) {
F_31 ( V_73 , V_113 , L_35 ,
F_1 ( V_60 ) ) ;
F_12 ( & V_35 -> V_44 ) ;
return - V_114 ;
}
F_12 ( & V_35 -> V_44 ) ;
return 0 ;
V_112:
F_31 ( V_73 , V_113 , L_36 , F_1 ( V_60 ) ) ;
F_12 ( & V_35 -> V_44 ) ;
F_27 ( V_59 ) ;
return V_89 ;
}
