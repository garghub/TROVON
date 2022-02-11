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
V_24 -> V_38 = V_26 -> V_24 -> V_38 ;
F_11 ( & V_2 -> V_32 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_39 * V_40 = V_3 ;
struct V_4 * V_41 ;
int V_29 ;
int V_30 ;
V_29 = V_40 -> V_29 ;
V_30 = 0 ;
F_8 ( & V_2 -> V_32 ) ;
F_13 (pt, &dev->filelist, lhead) {
if ( V_30 ++ >= V_29 ) {
V_40 -> V_42 = V_41 -> V_43 ;
V_40 -> V_44 = V_41 -> V_44 ;
V_40 -> V_45 = V_41 -> V_45 ;
V_40 -> V_46 = V_41 -> V_46 ;
V_40 -> V_47 = V_41 -> V_48 ;
F_11 ( & V_2 -> V_32 ) ;
return 0 ;
}
}
F_11 ( & V_2 -> V_32 ) ;
return - V_17 ;
}
int F_14 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
struct V_49 * V_50 = V_3 ;
int V_30 ;
memset ( V_50 , 0 , sizeof( * V_50 ) ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_51 ; V_30 ++ ) {
if ( V_2 -> V_52 [ V_30 ] == V_53 )
V_50 -> V_3 [ V_30 ] . V_54 =
( V_5 -> V_9 -> V_55 . V_56 ? V_5 -> V_9 -> V_55 . V_56 -> V_55 : 0 ) ;
else
V_50 -> V_3 [ V_30 ] . V_54 = F_15 ( & V_2 -> V_57 [ V_30 ] ) ;
V_50 -> V_3 [ V_30 ] . type = V_2 -> V_52 [ V_30 ] ;
}
V_50 -> V_58 = V_2 -> V_51 ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_59 * V_60 = V_3 ;
V_60 -> V_54 = 0 ;
switch ( V_60 -> V_61 ) {
case V_62 :
if ( V_2 -> V_18 -> V_63 )
V_60 -> V_54 = 1 ;
break;
case V_64 :
V_60 -> V_54 = 1 ;
break;
case V_65 :
V_60 -> V_54 = V_2 -> V_66 . V_67 ;
break;
case V_68 :
V_60 -> V_54 = V_2 -> V_66 . V_69 ;
break;
default:
return - V_17 ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 , void * V_3 , struct V_4 * V_5 )
{
struct V_70 * V_71 = V_3 ;
int V_72 , V_73 = 0 ;
if ( V_71 -> V_74 != - 1 ) {
if ( V_71 -> V_74 != V_75 ||
V_71 -> V_76 < 0 || V_71 -> V_76 > V_77 ) {
V_73 = - V_17 ;
goto V_78;
}
V_72 = F_18 ( V_71 -> V_74 ,
V_71 -> V_76 ) ;
V_2 -> V_72 = F_19 ( V_72 , V_2 -> V_72 ) ;
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
if ( V_2 -> V_18 -> V_83 )
V_2 -> V_18 -> V_83 ( V_2 , V_71 ) ;
}
V_78:
V_71 -> V_74 = V_75 ;
V_71 -> V_76 = V_77 ;
V_71 -> V_79 = V_2 -> V_18 -> V_80 ;
V_71 -> V_81 = V_2 -> V_18 -> V_82 ;
return V_73 ;
}
int F_20 ( struct V_1 * V_2 , void * V_3 ,
struct V_4 * V_5 )
{
F_21 ( L_1 ) ;
return 0 ;
}
