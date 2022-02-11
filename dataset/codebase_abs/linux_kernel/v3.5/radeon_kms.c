int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 == NULL )
return 0 ;
F_2 ( V_4 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
int F_5 ( struct V_1 * V_2 , unsigned long V_6 )
{
struct V_3 * V_4 ;
int V_7 , V_8 ;
V_4 = F_6 ( sizeof( struct V_3 ) , V_9 ) ;
if ( V_4 == NULL ) {
return - V_10 ;
}
V_2 -> V_5 = ( void * ) V_4 ;
if ( F_7 ( V_2 ) ) {
V_6 |= V_11 ;
} else if ( F_8 ( V_2 -> V_12 ) ) {
V_6 |= V_13 ;
} else {
V_6 |= V_14 ;
}
V_7 = F_9 ( V_4 , V_2 , V_2 -> V_12 , V_6 ) ;
if ( V_7 ) {
F_10 ( & V_2 -> V_12 -> V_2 , L_1 ) ;
goto V_15;
}
V_8 = F_11 ( V_4 ) ;
if ( V_8 )
F_12 ( & V_2 -> V_12 -> V_2 , L_2 ) ;
V_7 = F_13 ( V_4 ) ;
if ( V_7 )
F_10 ( & V_2 -> V_12 -> V_2 , L_3 ) ;
V_15:
if ( V_7 )
F_1 ( V_2 ) ;
return V_7 ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_16 * * V_17 ,
struct V_16 * V_18 ,
T_1 * V_19 )
{
F_15 ( & V_2 -> V_20 ) ;
if ( * V_19 == 1 ) {
if ( ! * V_17 )
* V_17 = V_18 ;
} else if ( * V_19 == 0 ) {
if ( * V_17 == V_18 )
* V_17 = NULL ;
}
* V_19 = * V_17 == V_18 ? 1 : 0 ;
F_16 ( & V_2 -> V_20 ) ;
}
int F_17 ( struct V_1 * V_2 , void * V_21 , struct V_16 * V_22 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 ;
struct V_25 * V_26 = & V_4 -> V_27 ;
T_1 * V_28 ;
T_1 V_19 ;
struct V_29 * V_30 ;
int V_31 , V_32 ;
V_24 = V_21 ;
V_28 = ( T_1 * ) ( ( unsigned long ) V_24 -> V_19 ) ;
if ( F_18 ( & V_19 , V_28 , sizeof( V_19 ) ) )
return - V_33 ;
switch ( V_24 -> V_34 ) {
case V_35 :
V_19 = V_2 -> V_36 ;
break;
case V_37 :
V_19 = V_4 -> V_38 ;
break;
case V_39 :
V_19 = V_4 -> V_40 ;
break;
case V_41 :
if ( ( V_4 -> V_42 >= V_43 ) && ( V_4 -> V_42 <= V_44 ) )
V_19 = false ;
else
V_19 = V_4 -> V_45 ;
break;
case V_46 :
for ( V_31 = 0 , V_32 = 0 ; V_31 < V_4 -> V_47 ; V_31 ++ ) {
V_30 = (struct V_29 * ) V_26 -> V_48 [ V_31 ] ;
if ( V_30 && V_30 -> V_49 . V_50 == V_19 ) {
struct V_51 * V_51 = F_19 ( V_30 ) ;
V_19 = V_51 -> V_52 ;
V_32 = 1 ;
break;
}
}
if ( ! V_32 ) {
F_20 ( L_4 , V_19 ) ;
return - V_53 ;
}
break;
case V_54 :
V_19 = V_4 -> V_45 ;
break;
case V_55 :
if ( V_4 -> V_42 >= V_56 )
V_19 = V_4 -> V_57 . V_58 . V_59 ;
else if ( V_4 -> V_42 >= V_60 )
V_19 = V_4 -> V_57 . V_61 . V_59 ;
else if ( V_4 -> V_42 >= V_43 )
V_19 = V_4 -> V_57 . V_62 . V_59 ;
else if ( V_4 -> V_42 >= V_63 )
V_19 = V_4 -> V_57 . V_64 . V_59 ;
else if ( V_4 -> V_42 >= V_65 )
V_19 = V_4 -> V_57 . V_66 . V_59 ;
else {
F_20 ( L_5 ) ;
return - V_53 ;
}
break;
case V_67 :
if ( V_19 >= 2 ) {
F_20 ( L_6 , V_19 ) ;
return - V_53 ;
}
F_14 ( V_2 , & V_4 -> V_68 , V_22 , & V_19 ) ;
break;
case V_69 :
if ( V_19 >= 2 ) {
F_20 ( L_7 , V_19 ) ;
return - V_53 ;
}
F_14 ( V_2 , & V_4 -> V_70 , V_22 , & V_19 ) ;
break;
case V_71 :
V_19 = V_4 -> clock . V_72 . V_73 * 10 ;
break;
case V_74 :
if ( V_4 -> V_42 >= V_56 )
V_19 = V_4 -> V_57 . V_58 . V_75 *
V_4 -> V_57 . V_58 . V_76 ;
else if ( V_4 -> V_42 >= V_60 )
V_19 = V_4 -> V_57 . V_61 . V_75 *
V_4 -> V_57 . V_61 . V_76 ;
else if ( V_4 -> V_42 >= V_43 )
V_19 = V_4 -> V_57 . V_62 . V_77 ;
else if ( V_4 -> V_42 >= V_63 )
V_19 = V_4 -> V_57 . V_64 . V_77 ;
else if ( V_4 -> V_42 >= V_65 )
V_19 = V_4 -> V_57 . V_66 . V_77 ;
else {
return - V_53 ;
}
break;
case V_78 :
if ( V_4 -> V_42 >= V_56 )
V_19 = V_4 -> V_57 . V_58 . V_79 ;
else if ( V_4 -> V_42 >= V_60 )
V_19 = V_4 -> V_57 . V_61 . V_79 ;
else if ( V_4 -> V_42 >= V_43 )
V_19 = V_4 -> V_57 . V_62 . V_79 ;
else if ( V_4 -> V_42 >= V_63 )
V_19 = V_4 -> V_57 . V_64 . V_79 ;
else if ( V_4 -> V_42 >= V_65 )
V_19 = V_4 -> V_57 . V_66 . V_79 ;
else {
return - V_53 ;
}
break;
case V_80 :
V_19 = 1 ;
break;
case V_81 :
if ( V_4 -> V_42 >= V_56 )
V_19 = V_4 -> V_57 . V_58 . V_82 ;
else if ( V_4 -> V_42 >= V_60 )
V_19 = V_4 -> V_57 . V_61 . V_82 ;
else if ( V_4 -> V_42 >= V_43 )
V_19 = V_4 -> V_57 . V_62 . V_82 ;
else if ( V_4 -> V_42 >= V_63 )
V_19 = V_4 -> V_57 . V_64 . V_82 ;
else if ( V_4 -> V_42 >= V_65 )
V_19 = V_4 -> V_57 . V_66 . V_82 ;
else {
return - V_53 ;
}
break;
case V_83 :
if ( V_4 -> V_42 < V_60 )
return - V_53 ;
V_19 = V_84 ;
break;
case V_85 :
if ( V_4 -> V_42 < V_60 )
return - V_53 ;
V_19 = V_86 ;
break;
case V_87 :
if ( V_4 -> V_42 >= V_56 )
V_19 = V_4 -> V_57 . V_58 . V_88 ;
else if ( V_4 -> V_42 >= V_60 )
V_19 = V_4 -> V_57 . V_61 . V_89 ;
else if ( V_4 -> V_42 >= V_43 )
V_19 = V_4 -> V_57 . V_62 . V_90 ;
else if ( V_4 -> V_42 >= V_63 )
V_19 = V_4 -> V_57 . V_64 . V_90 ;
else if ( V_4 -> V_42 >= V_65 )
V_19 = V_4 -> V_57 . V_66 . V_90 ;
else {
return - V_53 ;
}
break;
default:
F_20 ( L_8 , V_24 -> V_34 ) ;
return - V_53 ;
}
if ( F_21 ( V_28 , & V_19 , sizeof( T_1 ) ) ) {
F_22 ( L_9 ) ;
return - V_33 ;
}
return 0 ;
}
int F_23 ( struct V_1 * V_2 )
{
return 0 ;
}
void F_24 ( struct V_1 * V_2 )
{
F_25 () ;
}
int F_26 ( struct V_1 * V_2 , struct V_16 * V_91 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_91 -> V_92 = NULL ;
if ( V_4 -> V_42 >= V_60 ) {
struct V_93 * V_94 ;
int V_7 ;
V_94 = F_6 ( sizeof( * V_94 ) , V_9 ) ;
if ( F_27 ( ! V_94 ) ) {
return - V_10 ;
}
V_7 = F_28 ( V_4 , & V_94 -> V_95 ) ;
if ( V_7 ) {
F_29 ( V_4 , & V_94 -> V_95 ) ;
F_4 ( V_94 ) ;
return V_7 ;
}
V_91 -> V_92 = V_94 ;
}
return 0 ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_16 * V_91 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_42 >= V_60 && V_91 -> V_92 ) {
struct V_93 * V_94 = V_91 -> V_92 ;
F_29 ( V_4 , & V_94 -> V_95 ) ;
F_4 ( V_94 ) ;
V_91 -> V_92 = NULL ;
}
}
void F_31 ( struct V_1 * V_2 ,
struct V_16 * V_91 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_68 == V_91 )
V_4 -> V_68 = NULL ;
if ( V_4 -> V_70 == V_91 )
V_4 -> V_70 = NULL ;
}
T_2 F_32 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_30 < 0 || V_30 >= V_4 -> V_47 ) {
F_22 ( L_10 , V_30 ) ;
return - V_53 ;
}
return F_33 ( V_4 , V_30 ) ;
}
int F_34 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_30 < 0 || V_30 >= V_4 -> V_47 ) {
F_22 ( L_10 , V_30 ) ;
return - V_53 ;
}
V_4 -> V_96 . V_97 [ V_30 ] = true ;
return F_35 ( V_4 ) ;
}
void F_36 ( struct V_1 * V_2 , int V_30 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_30 < 0 || V_30 >= V_4 -> V_47 ) {
F_22 ( L_10 , V_30 ) ;
return;
}
V_4 -> V_96 . V_97 [ V_30 ] = false ;
F_35 ( V_4 ) ;
}
int F_37 ( struct V_1 * V_2 , int V_30 ,
int * V_98 ,
struct V_99 * V_100 ,
unsigned V_6 )
{
struct V_29 * V_101 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_30 < 0 || V_30 >= V_2 -> V_102 ) {
F_22 ( L_10 , V_30 ) ;
return - V_53 ;
}
V_101 = & V_4 -> V_27 . V_48 [ V_30 ] -> V_49 ;
return F_38 ( V_2 , V_30 , V_98 ,
V_100 , V_6 ,
V_101 ) ;
}
int F_39 ( struct V_1 * V_2 , void * V_21 ,
struct V_16 * V_91 )
{
return - V_53 ;
}
