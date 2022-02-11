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
F_8 ( & V_30 -> V_33 ) ;
}
int F_9 ( struct V_1 * V_1 )
{
struct V_29 * V_30 = F_10 ( V_1 , V_34 ) ;
struct V_2 * V_26 ;
int V_35 ;
F_11 ( & V_30 -> V_31 ) ;
V_35 = F_1 ( V_1 , & V_26 ) ;
if ( ! V_35 ) {
if ( V_30 -> V_32 )
F_12 ( V_30 -> V_32 ) ;
V_30 -> V_32 = V_26 ;
}
F_13 ( & V_30 -> V_31 ) ;
F_14 ( & V_30 -> V_33 ) ;
return V_35 ;
}
void F_15 ( struct V_29 * V_30 )
{
F_11 ( & V_30 -> V_31 ) ;
if ( V_30 -> V_32 ) {
F_12 ( V_30 -> V_32 ) ;
V_30 -> V_32 = NULL ;
}
F_13 ( & V_30 -> V_31 ) ;
}
static struct V_2 * F_16 ( struct V_29 * V_30 )
{
struct V_2 * V_26 ;
F_11 ( & V_30 -> V_31 ) ;
V_26 = V_30 -> V_32 ;
if ( V_26 )
F_17 ( & V_26 -> V_36 ) ;
F_13 ( & V_30 -> V_31 ) ;
return V_26 ;
}
static int F_18 ( struct V_1 * V_1 , struct V_37 * V_38 )
{
struct V_29 * V_30 = F_10 ( V_1 , V_34 ) ;
struct V_2 * V_26 ;
int V_39 ;
V_26 = F_16 ( V_30 ) ;
if ( ! V_26 )
return - V_40 ;
V_39 = F_19 ( V_26 , V_38 , 0 ) ;
if ( V_39 < 0 ) {
F_4 ( L_6 , - V_39 ) ;
switch ( V_39 ) {
case - V_41 :
V_39 = - V_42 ;
break;
case - V_43 :
case - V_44 :
case - V_45 :
V_39 = - V_46 ;
break;
case - V_47 :
if ( F_20 () )
V_39 = - V_48 ;
break;
default:
break;
}
}
F_21 ( V_26 ) ;
return V_39 ;
}
static void F_22 ( struct V_49 * V_50 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_52 && V_50 -> V_53 [ V_51 ] ; V_51 ++ )
F_23 ( V_50 -> V_53 [ V_51 ] ) ;
}
static int F_24 ( struct V_49 * V_50 )
{
V_50 -> V_52 = F_25 ( V_54 * 4 , V_55 ) ;
V_50 -> V_53 = F_26 ( V_50 -> V_52 * sizeof( struct V_56 * ) , V_57 ) ;
if ( ! V_50 -> V_53 )
return - V_58 ;
return 0 ;
}
int F_27 ( struct V_1 * V_1 ,
struct V_59 * V_60 )
{
struct V_61 V_62 = {
. V_63 = V_60 -> V_64
} ;
struct V_49 V_50 = {
. V_65 = V_60 -> V_66 ,
} ;
struct V_61 V_67 = {
. V_68 . V_69 = V_70 ,
. V_71 . V_69 = V_72 ,
. V_73 . V_74 . V_69 = V_75
} ;
struct V_76 V_77 = {
. V_78 = & V_67 ,
. V_79 = & V_60 -> V_80
} ;
struct V_37 V_38 = {
. V_81 = & V_82 [ V_83 ] ,
. V_84 = & V_50 ,
. V_85 = & V_77 ,
. V_86 = NULL ,
} ;
struct V_87 V_88 = { 0 , NULL } ;
int V_35 ;
if ( V_60 -> V_64 . V_69 != 0 )
V_50 . V_78 = & V_62 ;
V_77 . V_79 -> V_69 = V_89 ;
V_35 = F_24 ( & V_50 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_18 ( V_1 , & V_38 ) ;
F_22 ( & V_50 ) ;
V_60 -> V_90 = V_77 . V_39 . V_90 ;
V_60 -> V_91 = V_77 . V_39 . V_91 ;
if ( V_77 . V_78 ) {
V_60 -> V_92 = V_67 . V_68 ;
V_60 -> V_93 . V_69 = V_67 . V_71 . V_69 ;
memcpy ( V_60 -> V_93 . V_60 , V_67 . V_71 . V_60 ,
V_60 -> V_93 . V_69 ) ;
V_88 = V_67 . V_73 . V_74 ;
}
if ( V_77 . V_94 . V_95 == 1 ) {
T_1 * V_96 = & V_77 . V_94 . V_60 [ 0 ] . V_96 ;
if ( V_96 -> V_69 == 1 ) {
V_60 -> V_97 = * (struct V_98 * ) V_96 -> V_60 ;
V_60 -> V_99 = 1 ;
}
F_28 ( V_96 -> V_60 ) ;
}
if ( V_77 . V_94 . V_95 != 0 ) {
F_28 ( V_77 . V_94 . V_60 ) ;
}
if ( V_60 -> V_99 && V_88 . V_60 != NULL ) {
char * V_100 ;
V_60 -> V_97 . V_101 = F_29 ( V_88 . V_60 ,
V_88 . V_69 , V_57 ) ;
if ( V_60 -> V_97 . V_101 ) {
V_100 = strchr ( V_60 -> V_97 . V_101 , '@' ) ;
if ( V_100 ) {
* V_100 = '\0' ;
V_100 = strchr ( V_60 -> V_97 . V_101 , '/' ) ;
if ( V_100 ) * V_100 = '@' ;
}
if ( ! V_100 ) {
F_28 ( V_60 -> V_97 . V_101 ) ;
V_60 -> V_97 . V_101 = NULL ;
}
}
}
F_28 ( V_88 . V_60 ) ;
return V_35 ;
}
void F_30 ( struct V_59 * V_60 )
{
F_28 ( V_60 -> V_64 . V_60 ) ;
F_28 ( V_60 -> V_92 . V_60 ) ;
F_28 ( V_60 -> V_80 . V_60 ) ;
F_31 ( & V_60 -> V_97 ) ;
}
