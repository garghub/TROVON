int F_1 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 ;
struct V_8 * V_9 = V_5 -> V_9 ;
if ( V_7 -> V_10 >= V_9 -> V_10 ) {
if ( F_2 ( V_7 -> V_11 , V_9 -> V_11 , V_9 -> V_10 ) )
return - V_12 ;
}
V_7 -> V_10 = V_9 -> V_10 ;
return 0 ;
}
static void
F_3 ( struct V_1 * V_2 ,
struct V_8 * V_9 )
{
F_4 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
V_9 -> V_10 = 0 ;
V_9 -> V_13 = 0 ;
}
int F_5 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 ;
struct V_8 * V_9 = V_5 -> V_9 ;
int V_14 ;
if ( V_9 -> V_10 || V_9 -> V_11 )
return - V_15 ;
if ( ! V_7 -> V_10 || V_7 -> V_10 > 1024 )
return - V_16 ;
if ( F_6 ( V_2 , V_17 ) )
return 0 ;
if ( F_7 ( ! V_2 -> V_18 ) )
return - V_16 ;
V_14 = F_8 ( V_2 , V_9 , V_7 ) ;
if ( V_14 )
goto V_19;
return 0 ;
V_19:
F_3 ( V_2 , V_9 ) ;
return V_14 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_9 ;
int V_14 ;
if ( V_9 -> V_11 != NULL )
F_3 ( V_2 , V_9 ) ;
if ( V_2 -> V_20 -> V_21 && V_2 -> V_20 -> V_21 -> V_22 ) {
V_14 = V_2 -> V_20 -> V_21 -> V_22 ( V_2 , V_9 ) ;
if ( V_14 ) {
F_3 ( V_2 , V_9 ) ;
return V_14 ;
}
} else {
if ( F_10 ( V_2 -> V_11 == NULL ,
L_1
L_2
L_3 , V_2 -> V_20 ) )
return - V_16 ;
V_9 -> V_11 = F_11 ( V_2 -> V_11 , V_23 ) ;
if ( V_9 -> V_11 )
V_9 -> V_10 = strlen ( V_2 -> V_11 ) ;
}
return 0 ;
}
int F_12 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_24 * V_25 = V_3 ;
struct V_26 * V_27 = NULL ;
struct V_28 * V_29 ;
int V_30 ;
int V_31 ;
V_30 = V_25 -> V_32 ;
if ( V_30 < 0 )
return - V_16 ;
V_31 = 0 ;
F_13 ( & V_2 -> V_33 ) ;
F_14 (list, &dev->maplist) {
if ( V_31 == V_30 ) {
V_27 = F_15 ( V_29 , struct V_26 , V_34 ) ;
break;
}
V_31 ++ ;
}
if ( ! V_27 || ! V_27 -> V_25 ) {
F_16 ( & V_2 -> V_33 ) ;
return - V_16 ;
}
V_25 -> V_32 = V_27 -> V_25 -> V_32 ;
V_25 -> V_35 = V_27 -> V_25 -> V_35 ;
V_25 -> type = V_27 -> V_25 -> type ;
V_25 -> V_36 = V_27 -> V_25 -> V_36 ;
V_25 -> V_37 = ( void * ) ( unsigned long ) V_27 -> V_38 ;
#ifdef F_17
V_25 -> V_39 = F_18 ( V_27 -> V_25 -> V_39 ) ;
#else
V_25 -> V_39 = - 1 ;
#endif
F_16 ( & V_2 -> V_33 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_40 * V_41 = V_3 ;
if ( V_41 -> V_30 == 0 ) {
V_41 -> V_42 = V_5 -> V_43 ;
V_41 -> V_44 = F_20 ( V_5 -> V_44 ) ;
V_41 -> V_45 = F_21 ( F_22 () ,
V_5 -> V_45 ) ;
V_41 -> V_46 = 0 ;
V_41 -> V_47 = 0 ;
return 0 ;
} else {
return - V_16 ;
}
}
int F_23 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_48 * V_49 = V_3 ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
return 0 ;
}
int F_24 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_50 * V_51 = V_3 ;
V_51 -> V_52 = 0 ;
switch ( V_51 -> V_53 ) {
case V_54 :
if ( V_2 -> V_20 -> V_55 )
V_51 -> V_52 = 1 ;
break;
case V_56 :
V_51 -> V_52 = 1 ;
break;
case V_57 :
V_51 -> V_52 = V_2 -> V_58 . V_59 ;
break;
case V_60 :
V_51 -> V_52 = V_2 -> V_58 . V_61 ;
break;
case V_62 :
V_51 -> V_52 |= V_2 -> V_20 -> V_63 ? V_64 : 0 ;
V_51 -> V_52 |= V_2 -> V_20 -> V_65 ? V_66 : 0 ;
break;
case V_67 :
V_51 -> V_52 = V_68 ;
break;
case V_69 :
V_51 -> V_52 = V_2 -> V_58 . V_70 ;
break;
case V_71 :
if ( V_2 -> V_58 . V_72 )
V_51 -> V_52 = V_2 -> V_58 . V_72 ;
else
V_51 -> V_52 = 64 ;
break;
case V_73 :
if ( V_2 -> V_58 . V_74 )
V_51 -> V_52 = V_2 -> V_58 . V_74 ;
else
V_51 -> V_52 = 64 ;
break;
default:
return - V_16 ;
}
return 0 ;
}
int
F_25 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_75 * V_51 = V_3 ;
switch ( V_51 -> V_53 ) {
case V_76 :
if ( V_51 -> V_52 > 1 )
return - V_16 ;
V_5 -> V_77 = V_51 -> V_52 ;
break;
case V_78 :
if ( ! V_79 )
return - V_16 ;
if ( V_51 -> V_52 > 1 )
return - V_16 ;
V_5 -> V_80 = V_51 -> V_52 ;
break;
default:
return - V_16 ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_81 * V_82 = V_3 ;
int V_83 , V_84 = 0 ;
if ( V_82 -> V_85 != - 1 ) {
if ( V_82 -> V_85 != V_86 ||
V_82 -> V_87 < 0 || V_82 -> V_87 > V_88 ) {
V_84 = - V_16 ;
goto V_89;
}
V_83 = F_27 ( V_82 -> V_85 ,
V_82 -> V_87 ) ;
V_2 -> V_83 = F_28 ( V_83 , V_2 -> V_83 ) ;
if ( V_82 -> V_87 >= 1 ) {
V_84 = F_9 ( V_2 , V_5 ) ;
if ( V_84 )
goto V_89;
}
}
if ( V_82 -> V_90 != - 1 ) {
if ( V_82 -> V_90 != V_2 -> V_20 -> V_91 ||
V_82 -> V_92 < 0 || V_82 -> V_92 >
V_2 -> V_20 -> V_93 ) {
V_84 = - V_16 ;
goto V_89;
}
}
V_89:
V_82 -> V_85 = V_86 ;
V_82 -> V_87 = V_88 ;
V_82 -> V_90 = V_2 -> V_20 -> V_91 ;
V_82 -> V_92 = V_2 -> V_20 -> V_93 ;
return V_84 ;
}
int F_29 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
F_30 ( L_4 ) ;
return 0 ;
}
