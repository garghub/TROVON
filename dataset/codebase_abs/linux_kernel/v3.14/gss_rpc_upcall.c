static int F_1 ( struct V_1 * V_1 , struct V_2 * * V_3 )
{
static const struct V_4 V_5 = {
. V_6 = V_7 ,
. V_8 = V_9 ,
} ;
struct V_10 args = {
. V_1 = V_1 ,
. V_11 = V_12 ,
. V_13 = (struct V_14 * ) & V_5 ,
. V_15 = sizeof( V_5 ) ,
. V_16 = L_1 ,
. V_17 = & V_18 ,
. V_19 = V_20 ,
. V_21 = V_22 ,
. V_23 = V_24 |
V_25
} ;
struct V_2 * V_26 ;
int V_27 = 0 ;
V_26 = F_2 ( & args ) ;
if ( F_3 ( V_26 ) ) {
F_4 ( L_2
L_3 , F_5 ( V_26 ) ) ;
V_27 = F_5 ( V_26 ) ;
* V_3 = NULL ;
goto V_28;
}
F_4 ( L_4
L_5 , V_26 ) ;
* V_3 = V_26 ;
V_28:
return V_27 ;
}
void F_6 ( struct V_29 * V_30 )
{
F_7 ( & V_30 -> V_31 ) ;
V_30 -> V_32 = NULL ;
}
int F_8 ( struct V_1 * V_1 )
{
struct V_29 * V_30 = F_9 ( V_1 , V_33 ) ;
struct V_2 * V_26 ;
int V_34 ;
F_10 ( & V_30 -> V_31 ) ;
V_34 = F_1 ( V_1 , & V_26 ) ;
if ( ! V_34 ) {
if ( V_30 -> V_32 )
F_11 ( V_30 -> V_32 ) ;
V_30 -> V_32 = V_26 ;
}
F_12 ( & V_30 -> V_31 ) ;
return V_34 ;
}
void F_13 ( struct V_29 * V_30 )
{
F_10 ( & V_30 -> V_31 ) ;
if ( V_30 -> V_32 ) {
F_11 ( V_30 -> V_32 ) ;
V_30 -> V_32 = NULL ;
}
F_12 ( & V_30 -> V_31 ) ;
}
static struct V_2 * F_14 ( struct V_29 * V_30 )
{
struct V_2 * V_26 ;
F_10 ( & V_30 -> V_31 ) ;
V_26 = V_30 -> V_32 ;
if ( V_26 )
F_15 ( & V_26 -> V_35 ) ;
F_12 ( & V_30 -> V_31 ) ;
return V_26 ;
}
static int F_16 ( struct V_1 * V_1 , struct V_36 * V_37 )
{
struct V_29 * V_30 = F_9 ( V_1 , V_33 ) ;
struct V_2 * V_26 ;
int V_38 ;
V_26 = F_14 ( V_30 ) ;
if ( ! V_26 )
return - V_39 ;
V_38 = F_17 ( V_26 , V_37 , 0 ) ;
if ( V_38 < 0 ) {
F_4 ( L_6 , - V_38 ) ;
switch ( V_38 ) {
case - V_40 :
V_38 = - V_41 ;
break;
case - V_42 :
case - V_43 :
case - V_44 :
V_38 = - V_45 ;
break;
case - V_46 :
if ( F_18 () )
V_38 = - V_47 ;
break;
default:
break;
}
}
F_19 ( V_26 ) ;
return V_38 ;
}
static void F_20 ( struct V_48 * V_49 )
{
int V_50 ;
for ( V_50 = 0 ; V_50 < V_49 -> V_51 && V_49 -> V_52 [ V_50 ] ; V_50 ++ )
F_21 ( V_49 -> V_52 [ V_50 ] ) ;
}
static int F_22 ( struct V_48 * V_49 )
{
V_49 -> V_51 = F_23 ( V_53 * 4 , V_54 ) ;
V_49 -> V_52 = F_24 ( V_49 -> V_51 * sizeof( struct V_55 * ) , V_56 ) ;
if ( ! V_49 -> V_52 )
return - V_57 ;
return 0 ;
}
int F_25 ( struct V_1 * V_1 ,
struct V_58 * V_59 )
{
struct V_60 V_61 = {
. V_62 = V_59 -> V_63
} ;
struct V_48 V_49 = {
. V_64 = V_59 -> V_65 ,
} ;
struct V_60 V_66 = {
. V_67 . V_68 = V_69 ,
. V_70 . V_68 = V_71 ,
. V_72 . V_73 . V_68 = V_74
} ;
struct V_75 V_76 = {
. V_77 = & V_66 ,
. V_78 = & V_59 -> V_79
} ;
struct V_36 V_37 = {
. V_80 = & V_81 [ V_82 ] ,
. V_83 = & V_49 ,
. V_84 = & V_76 ,
. V_85 = NULL ,
} ;
struct V_86 V_87 = { 0 , NULL } ;
int V_34 ;
if ( V_59 -> V_63 . V_68 != 0 )
V_49 . V_77 = & V_61 ;
V_76 . V_78 -> V_68 = V_88 ;
V_34 = F_22 ( & V_49 ) ;
if ( V_34 )
return V_34 ;
V_34 = F_16 ( V_1 , & V_37 ) ;
F_20 ( & V_49 ) ;
V_59 -> V_89 = V_76 . V_38 . V_89 ;
V_59 -> V_90 = V_76 . V_38 . V_90 ;
if ( V_76 . V_77 ) {
V_59 -> V_91 = V_66 . V_67 ;
V_59 -> V_92 . V_68 = V_66 . V_70 . V_68 ;
if ( V_66 . V_70 . V_59 )
memcpy ( V_59 -> V_92 . V_59 , V_66 . V_70 . V_59 ,
V_59 -> V_92 . V_68 ) ;
V_87 = V_66 . V_72 . V_73 ;
}
if ( V_76 . V_93 . V_94 == 1 ) {
T_1 * V_95 = & V_76 . V_93 . V_59 [ 0 ] . V_95 ;
if ( V_95 -> V_68 == 1 ) {
V_59 -> V_96 = * (struct V_97 * ) V_95 -> V_59 ;
V_59 -> V_98 = 1 ;
}
F_26 ( V_95 -> V_59 ) ;
}
if ( V_76 . V_93 . V_94 != 0 ) {
F_26 ( V_76 . V_93 . V_59 ) ;
}
if ( V_59 -> V_98 && V_87 . V_59 != NULL ) {
char * V_99 ;
V_59 -> V_96 . V_100 = F_27 ( V_87 . V_59 ,
V_87 . V_68 , V_56 ) ;
if ( V_59 -> V_96 . V_100 ) {
V_99 = strchr ( V_59 -> V_96 . V_100 , '@' ) ;
if ( V_99 ) {
* V_99 = '\0' ;
V_99 = strchr ( V_59 -> V_96 . V_100 , '/' ) ;
if ( V_99 ) * V_99 = '@' ;
}
if ( ! V_99 ) {
F_26 ( V_59 -> V_96 . V_100 ) ;
V_59 -> V_96 . V_100 = NULL ;
}
}
}
F_26 ( V_87 . V_59 ) ;
return V_34 ;
}
void F_28 ( struct V_58 * V_59 )
{
F_26 ( V_59 -> V_63 . V_59 ) ;
F_26 ( V_59 -> V_91 . V_59 ) ;
F_26 ( V_59 -> V_79 . V_59 ) ;
F_29 ( & V_59 -> V_96 ) ;
}
