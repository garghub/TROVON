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
V_19 = F_9 ( & V_16 -> V_20 , V_15 ) ;
if ( V_19 )
goto V_21;
if ( V_4 -> V_22 & V_23 ) {
V_19 = F_10 ( & V_16 -> V_20 ) ;
if ( V_19 )
goto V_21;
V_19 = F_11 ( & V_16 -> V_20 , V_4 -> V_24 ) ;
if ( V_19 )
goto V_21;
}
F_12 ( & V_16 -> V_20 ) ;
V_13 -> V_25 = & V_16 -> V_20 ;
#if F_2 ( V_17 )
if ( V_4 -> V_26 -> V_27 ) {
V_8 = F_13 ( & V_4 -> V_8 ) ;
if ( ! V_8 ) {
V_19 = - V_28 ;
goto V_21;
}
}
#endif
if ( V_4 -> V_29 && V_4 -> V_29 -> V_30 ) {
V_19 = V_4 -> V_29 -> V_30 ( V_4 , V_16 ) ;
if ( V_19 < 0 )
goto V_21;
}
return 0 ;
V_21:
#if F_2 ( V_17 )
if ( V_8 )
F_14 ( V_8 ) ;
#endif
F_15 ( & V_16 -> V_20 ) ;
F_16 ( & V_16 -> V_20 ) ;
F_4 ( V_16 ) ;
F_5 ( V_16 ) ;
return V_19 ;
}
static int F_17 ( struct V_13 * V_13 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_3 * V_4 = F_8 ( V_15 ) ;
struct V_31 * V_20 = V_13 -> V_25 ;
struct V_1 * V_16 = F_18 ( V_20 ) ;
if ( V_4 -> V_29 && V_4 -> V_29 -> V_32 )
V_4 -> V_29 -> V_32 ( V_4 , V_16 ) ;
#if F_2 ( V_17 )
if ( V_4 -> V_26 -> V_27 )
F_14 ( & V_4 -> V_8 ) ;
#endif
F_15 ( V_20 ) ;
F_16 ( V_20 ) ;
F_4 ( V_16 ) ;
F_5 ( V_16 ) ;
V_13 -> V_25 = NULL ;
return 0 ;
}
static long F_19 ( struct V_13 * V_13 , unsigned int V_33 , void * V_34 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_3 * V_4 = F_8 ( V_15 ) ;
struct V_31 * V_20 = V_13 -> V_25 ;
#if F_2 ( V_5 )
struct V_1 * V_16 = F_18 ( V_20 ) ;
#endif
switch ( V_33 ) {
case V_35 :
return F_20 ( V_4 -> V_36 , V_34 ) ;
case V_37 :
return F_21 ( V_4 -> V_36 , V_34 ) ;
case V_38 :
return F_22 ( V_4 -> V_36 , V_34 ) ;
case V_39 :
return F_23 ( V_4 -> V_36 , V_34 ) ;
case V_40 :
return F_24 ( V_4 -> V_36 , V_34 ) ;
case V_41 :
return F_25 ( V_4 -> V_36 , V_34 ) ;
case V_42 :
return F_26 ( V_4 -> V_36 , V_34 ) ;
case V_43 :
if ( ! ( V_4 -> V_22 & V_23 ) )
return - V_44 ;
return F_27 ( V_20 , V_34 , V_13 -> V_45 & V_46 ) ;
case V_47 :
return F_28 ( V_4 , V_48 , V_49 , V_20 , V_34 ) ;
case V_50 :
return F_28 ( V_4 , V_48 , V_51 , V_20 , V_34 ) ;
#if F_2 ( V_5 )
case V_52 : {
struct V_53 * V_54 = V_34 ;
if ( V_54 -> V_55 != V_56 &&
V_54 -> V_55 != V_57 )
return - V_58 ;
if ( V_54 -> V_59 >= V_4 -> V_8 . V_9 )
return - V_58 ;
return F_28 ( V_4 , V_59 , V_60 , V_16 , V_54 ) ;
}
case V_61 : {
struct V_53 * V_54 = V_34 ;
if ( V_54 -> V_55 != V_56 &&
V_54 -> V_55 != V_57 )
return - V_58 ;
if ( V_54 -> V_59 >= V_4 -> V_8 . V_9 )
return - V_58 ;
return F_28 ( V_4 , V_59 , V_62 , V_16 , V_54 ) ;
}
case V_63 : {
struct V_64 * V_65 = V_34 ;
if ( V_65 -> V_55 != V_56 &&
V_65 -> V_55 != V_57 )
return - V_58 ;
if ( V_65 -> V_59 >= V_4 -> V_8 . V_9 )
return - V_58 ;
return F_28 ( V_4 , V_59 , V_66 , V_16 , V_65 ) ;
}
case V_67 : {
struct V_64 * V_65 = V_34 ;
if ( V_65 -> V_55 != V_56 &&
V_65 -> V_55 != V_57 )
return - V_58 ;
if ( V_65 -> V_59 >= V_4 -> V_8 . V_9 )
return - V_58 ;
return F_28 ( V_4 , V_59 , V_68 , V_16 , V_65 ) ;
}
case V_69 : {
struct V_70 * V_71 = V_34 ;
if ( V_71 -> V_59 >= V_4 -> V_8 . V_9 )
return - V_58 ;
return F_28 ( V_4 , V_59 , V_72 , V_16 ,
V_71 ) ;
}
case V_73 : {
struct V_74 * V_75 = V_34 ;
if ( V_75 -> V_59 >= V_4 -> V_8 . V_9 )
return - V_58 ;
return F_28 ( V_4 , V_59 , V_76 , V_16 ,
V_75 ) ;
}
case V_77 :
return F_28 ( V_4 , V_78 , V_79 , V_34 ) ;
case V_80 :
return F_28 ( V_4 , V_78 , V_81 , V_34 ) ;
case V_82 : {
struct V_83 * V_84 = V_34 ;
if ( V_84 -> V_59 >= V_4 -> V_8 . V_9 )
return - V_58 ;
return F_28 ( V_4 , V_59 , V_85 , V_16 ,
V_84 ) ;
}
#endif
default:
return F_28 ( V_4 , V_48 , V_86 , V_33 , V_34 ) ;
}
return 0 ;
}
static long F_29 ( struct V_13 * V_13 , unsigned int V_33 ,
unsigned long V_34 )
{
return F_30 ( V_13 , V_33 , V_34 , F_19 ) ;
}
static unsigned int F_31 ( struct V_13 * V_13 , T_1 * V_87 )
{
struct V_14 * V_15 = F_7 ( V_13 ) ;
struct V_3 * V_4 = F_8 ( V_15 ) ;
struct V_31 * V_2 = V_13 -> V_25 ;
if ( ! ( V_4 -> V_22 & V_23 ) )
return V_88 ;
F_32 ( V_13 , & V_2 -> V_89 -> V_87 , V_87 ) ;
if ( F_33 ( V_2 ) )
return V_90 ;
return 0 ;
}
void F_34 ( struct V_3 * V_4 , const struct V_91 * V_92 )
{
F_35 ( & V_4 -> V_93 ) ;
F_36 ( ! V_92 ) ;
V_4 -> V_92 = V_92 ;
V_4 -> V_26 = NULL ;
V_4 -> V_22 = 0 ;
V_4 -> V_94 [ 0 ] = '\0' ;
V_4 -> V_95 = 0 ;
V_4 -> V_96 = NULL ;
V_4 -> V_97 = NULL ;
#if F_2 ( V_17 )
V_4 -> V_8 . V_94 = V_4 -> V_94 ;
V_4 -> V_8 . type = V_98 ;
#endif
}
