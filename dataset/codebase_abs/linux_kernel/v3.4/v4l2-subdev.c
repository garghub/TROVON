static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
#if F_2 ( V_5 )
V_2 -> V_6 = F_3 ( ( sizeof( * V_2 -> V_6 ) + sizeof( * V_2 -> V_7 ) )
* V_4 -> V_8 . V_9 , V_10 ) ;
if ( V_2 -> V_6 == NULL )
return - V_11 ;
V_2 -> V_7 = (struct V_12 * )
( V_2 -> V_6 + V_4 -> V_8 . V_9 ) ;
#endif
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
#if F_2 ( V_5 )
F_5 ( V_2 -> V_6 ) ;
V_2 -> V_6 = NULL ;
V_2 -> V_7 = NULL ;
#endif
}
static int F_6 ( struct V_13 * V_13 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_3 * V_4 = F_8 ( V_15 ) ;
struct V_1 * V_16 ;
#if F_2 ( V_17 )
struct V_18 * V_8 = NULL ;
#endif
int V_19 ;
V_16 = F_3 ( sizeof( * V_16 ) , V_10 ) ;
if ( V_16 == NULL )
return - V_11 ;
V_19 = F_1 ( V_16 , V_4 ) ;
if ( V_19 ) {
F_5 ( V_16 ) ;
return V_19 ;
}
F_9 ( & V_16 -> V_20 , V_15 ) ;
F_10 ( & V_16 -> V_20 ) ;
V_13 -> V_21 = & V_16 -> V_20 ;
#if F_2 ( V_17 )
if ( V_4 -> V_22 -> V_23 ) {
V_8 = F_11 ( & V_4 -> V_8 ) ;
if ( ! V_8 ) {
V_19 = - V_24 ;
goto V_25;
}
}
#endif
if ( V_4 -> V_26 && V_4 -> V_26 -> V_27 ) {
V_19 = V_4 -> V_26 -> V_27 ( V_4 , V_16 ) ;
if ( V_19 < 0 )
goto V_25;
}
return 0 ;
V_25:
#if F_2 ( V_17 )
if ( V_8 )
F_12 ( V_8 ) ;
#endif
F_13 ( & V_16 -> V_20 ) ;
F_14 ( & V_16 -> V_20 ) ;
F_4 ( V_16 ) ;
F_5 ( V_16 ) ;
return V_19 ;
}
static int F_15 ( struct V_13 * V_13 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_3 * V_4 = F_8 ( V_15 ) ;
struct V_28 * V_20 = V_13 -> V_21 ;
struct V_1 * V_16 = F_16 ( V_20 ) ;
if ( V_4 -> V_26 && V_4 -> V_26 -> V_29 )
V_4 -> V_26 -> V_29 ( V_4 , V_16 ) ;
#if F_2 ( V_17 )
if ( V_4 -> V_22 -> V_23 )
F_12 ( & V_4 -> V_8 ) ;
#endif
F_13 ( V_20 ) ;
F_14 ( V_20 ) ;
F_4 ( V_16 ) ;
F_5 ( V_16 ) ;
V_13 -> V_21 = NULL ;
return 0 ;
}
static long F_17 ( struct V_13 * V_13 , unsigned int V_30 , void * V_31 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_3 * V_4 = F_8 ( V_15 ) ;
struct V_28 * V_20 = V_13 -> V_21 ;
#if F_2 ( V_5 )
struct V_1 * V_16 = F_16 ( V_20 ) ;
#endif
switch ( V_30 ) {
case V_32 :
return F_18 ( V_20 -> V_33 , V_31 ) ;
case V_34 :
return F_19 ( V_20 -> V_33 , V_31 ) ;
case V_35 :
return F_20 ( V_20 -> V_33 , V_31 ) ;
case V_36 :
return F_21 ( V_20 , V_20 -> V_33 , V_31 ) ;
case V_37 :
return F_22 ( V_20 -> V_33 , V_31 ) ;
case V_38 :
return F_23 ( V_20 , V_20 -> V_33 , V_31 ) ;
case V_39 :
return F_24 ( V_20 -> V_33 , V_31 ) ;
case V_40 :
if ( ! ( V_4 -> V_41 & V_42 ) )
return - V_43 ;
return F_25 ( V_20 , V_31 , V_13 -> V_44 & V_45 ) ;
case V_46 :
return F_26 ( V_4 , V_47 , V_48 , V_20 , V_31 ) ;
case V_49 :
return F_26 ( V_4 , V_47 , V_50 , V_20 , V_31 ) ;
#ifdef F_27
case V_51 :
{
struct V_52 * V_53 = V_31 ;
if ( ! F_28 ( V_54 ) )
return - V_55 ;
return F_26 ( V_4 , V_47 , V_56 , V_53 ) ;
}
case V_57 :
{
struct V_52 * V_53 = V_31 ;
if ( ! F_28 ( V_54 ) )
return - V_55 ;
return F_26 ( V_4 , V_47 , V_58 , V_53 ) ;
}
#endif
case V_59 : {
int V_19 ;
F_29 ( L_1 ,
V_4 -> V_60 ) ;
V_19 = F_26 ( V_4 , V_47 , V_61 ) ;
F_29 ( L_2 ,
V_4 -> V_60 ) ;
return V_19 ;
}
#if F_2 ( V_5 )
case V_62 : {
struct V_63 * V_64 = V_31 ;
if ( V_64 -> V_65 != V_66 &&
V_64 -> V_65 != V_67 )
return - V_68 ;
if ( V_64 -> V_69 >= V_4 -> V_8 . V_9 )
return - V_68 ;
return F_26 ( V_4 , V_69 , V_70 , V_16 , V_64 ) ;
}
case V_71 : {
struct V_63 * V_64 = V_31 ;
if ( V_64 -> V_65 != V_66 &&
V_64 -> V_65 != V_67 )
return - V_68 ;
if ( V_64 -> V_69 >= V_4 -> V_8 . V_9 )
return - V_68 ;
return F_26 ( V_4 , V_69 , V_72 , V_16 , V_64 ) ;
}
case V_73 : {
struct V_74 * V_75 = V_31 ;
if ( V_75 -> V_65 != V_66 &&
V_75 -> V_65 != V_67 )
return - V_68 ;
if ( V_75 -> V_69 >= V_4 -> V_8 . V_9 )
return - V_68 ;
return F_26 ( V_4 , V_69 , V_76 , V_16 , V_75 ) ;
}
case V_77 : {
struct V_74 * V_75 = V_31 ;
if ( V_75 -> V_65 != V_66 &&
V_75 -> V_65 != V_67 )
return - V_68 ;
if ( V_75 -> V_69 >= V_4 -> V_8 . V_9 )
return - V_68 ;
return F_26 ( V_4 , V_69 , V_78 , V_16 , V_75 ) ;
}
case V_79 : {
struct V_80 * V_81 = V_31 ;
if ( V_81 -> V_69 >= V_4 -> V_8 . V_9 )
return - V_68 ;
return F_26 ( V_4 , V_69 , V_82 , V_16 ,
V_81 ) ;
}
case V_83 : {
struct V_84 * V_85 = V_31 ;
if ( V_85 -> V_69 >= V_4 -> V_8 . V_9 )
return - V_68 ;
return F_26 ( V_4 , V_69 , V_86 , V_16 ,
V_85 ) ;
}
case V_87 :
return F_26 ( V_4 , V_88 , V_89 , V_31 ) ;
case V_90 :
return F_26 ( V_4 , V_88 , V_91 , V_31 ) ;
case V_92 : {
struct V_93 * V_94 = V_31 ;
if ( V_94 -> V_69 >= V_4 -> V_8 . V_9 )
return - V_68 ;
return F_26 ( V_4 , V_69 , V_95 , V_16 ,
V_94 ) ;
}
#endif
default:
return F_26 ( V_4 , V_47 , V_96 , V_30 , V_31 ) ;
}
return 0 ;
}
static long F_30 ( struct V_13 * V_13 , unsigned int V_30 ,
unsigned long V_31 )
{
return F_31 ( V_13 , V_30 , V_31 , F_17 ) ;
}
static unsigned int F_32 ( struct V_13 * V_13 , T_1 * V_97 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_3 * V_4 = F_8 ( V_15 ) ;
struct V_28 * V_2 = V_13 -> V_21 ;
if ( ! ( V_4 -> V_41 & V_42 ) )
return V_98 ;
F_33 ( V_13 , & V_2 -> V_97 , V_97 ) ;
if ( F_34 ( V_2 ) )
return V_99 ;
return 0 ;
}
void F_35 ( struct V_3 * V_4 , const struct V_100 * V_101 )
{
F_36 ( & V_4 -> V_102 ) ;
F_37 ( ! V_101 ) ;
V_4 -> V_101 = V_101 ;
V_4 -> V_22 = NULL ;
V_4 -> V_41 = 0 ;
V_4 -> V_60 [ 0 ] = '\0' ;
V_4 -> V_103 = 0 ;
V_4 -> V_104 = NULL ;
V_4 -> V_105 = NULL ;
#if F_2 ( V_17 )
V_4 -> V_8 . V_60 = V_4 -> V_60 ;
V_4 -> V_8 . type = V_106 ;
#endif
}
