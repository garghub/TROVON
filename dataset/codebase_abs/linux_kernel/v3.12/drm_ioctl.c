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
F_4 ( V_2 -> V_13 ) ;
V_2 -> V_13 = NULL ;
F_4 ( V_9 -> V_11 ) ;
V_9 -> V_11 = NULL ;
V_9 -> V_10 = 0 ;
V_9 -> V_14 = 0 ;
}
int F_5 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_6 * V_7 = V_3 ;
struct V_8 * V_9 = V_5 -> V_9 ;
int V_15 ;
if ( V_9 -> V_10 || V_9 -> V_11 )
return - V_16 ;
if ( ! V_7 -> V_10 || V_7 -> V_10 > 1024 )
return - V_17 ;
if ( ! V_2 -> V_18 -> V_19 -> V_20 )
return - V_17 ;
V_15 = V_2 -> V_18 -> V_19 -> V_20 ( V_2 , V_9 , V_7 ) ;
if ( V_15 )
goto V_21;
return 0 ;
V_21:
F_3 ( V_2 , V_9 ) ;
return V_15 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_9 ;
int V_15 ;
if ( V_9 -> V_11 != NULL )
F_3 ( V_2 , V_9 ) ;
V_15 = V_2 -> V_18 -> V_19 -> V_22 ( V_2 , V_9 ) ;
if ( V_15 )
goto V_21;
return 0 ;
V_21:
F_3 ( V_2 , V_9 ) ;
return V_15 ;
}
int F_7 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_23 * V_24 = V_3 ;
struct V_25 * V_26 = NULL ;
struct V_27 * V_28 ;
int V_29 ;
int V_30 ;
V_29 = V_24 -> V_31 ;
if ( V_29 < 0 )
return - V_17 ;
V_30 = 0 ;
F_8 ( & V_2 -> V_32 ) ;
F_9 (list, &dev->maplist) {
if ( V_30 == V_29 ) {
V_26 = F_10 ( V_28 , struct V_25 , V_33 ) ;
break;
}
V_30 ++ ;
}
if ( ! V_26 || ! V_26 -> V_24 ) {
F_11 ( & V_2 -> V_32 ) ;
return - V_17 ;
}
V_24 -> V_31 = V_26 -> V_24 -> V_31 ;
V_24 -> V_34 = V_26 -> V_24 -> V_34 ;
V_24 -> type = V_26 -> V_24 -> type ;
V_24 -> V_35 = V_26 -> V_24 -> V_35 ;
V_24 -> V_36 = ( void * ) ( unsigned long ) V_26 -> V_37 ;
#ifdef F_12
V_24 -> V_38 = F_13 ( V_26 -> V_24 -> V_38 ) ;
#else
V_24 -> V_38 = - 1 ;
#endif
F_11 ( & V_2 -> V_32 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_39 * V_40 = V_3 ;
if ( V_40 -> V_29 == 0 ) {
V_40 -> V_41 = V_5 -> V_42 ;
V_40 -> V_43 = F_15 ( V_5 -> V_43 ) ;
V_40 -> V_44 = F_16 ( F_17 () ,
V_5 -> V_44 ) ;
V_40 -> V_45 = 0 ;
V_40 -> V_46 = 0 ;
return 0 ;
} else {
return - V_17 ;
}
}
int F_18 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_47 * V_48 = V_3 ;
memset ( V_48 , 0 , sizeof( * V_48 ) ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_49 * V_50 = V_3 ;
V_50 -> V_51 = 0 ;
switch ( V_50 -> V_52 ) {
case V_53 :
if ( V_2 -> V_18 -> V_54 )
V_50 -> V_51 = 1 ;
break;
case V_55 :
V_50 -> V_51 = 1 ;
break;
case V_56 :
V_50 -> V_51 = V_2 -> V_57 . V_58 ;
break;
case V_59 :
V_50 -> V_51 = V_2 -> V_57 . V_60 ;
break;
case V_61 :
V_50 -> V_51 |= V_2 -> V_18 -> V_62 ? V_63 : 0 ;
V_50 -> V_51 |= V_2 -> V_18 -> V_64 ? V_65 : 0 ;
break;
case V_66 :
V_50 -> V_51 = V_67 ;
break;
case V_68 :
V_50 -> V_51 = V_2 -> V_57 . V_69 ;
break;
default:
return - V_17 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_70 * V_71 = V_3 ;
int V_72 , V_73 = 0 ;
if ( V_71 -> V_74 != - 1 ) {
if ( V_71 -> V_74 != V_75 ||
V_71 -> V_76 < 0 || V_71 -> V_76 > V_77 ) {
V_73 = - V_17 ;
goto V_78;
}
V_72 = F_21 ( V_71 -> V_74 ,
V_71 -> V_76 ) ;
V_2 -> V_72 = F_22 ( V_72 , V_2 -> V_72 ) ;
if ( V_71 -> V_76 >= 1 ) {
V_73 = F_6 ( V_2 , V_5 ) ;
if ( V_73 )
goto V_78;
}
}
if ( V_71 -> V_79 != - 1 ) {
if ( V_71 -> V_79 != V_2 -> V_18 -> V_80 ||
V_71 -> V_81 < 0 || V_71 -> V_81 >
V_2 -> V_18 -> V_82 ) {
V_73 = - V_17 ;
goto V_78;
}
}
V_78:
V_71 -> V_74 = V_75 ;
V_71 -> V_76 = V_77 ;
V_71 -> V_79 = V_2 -> V_18 -> V_80 ;
V_71 -> V_81 = V_2 -> V_18 -> V_82 ;
return V_73 ;
}
int F_23 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
F_24 ( L_1 ) ;
return 0 ;
}
