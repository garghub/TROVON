static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_10 ;
struct V_11 * V_12 = NULL ;
int V_13 = 0 ;
if ( V_6 -> V_14 >= V_15 ) {
if ( V_6 -> V_14 < V_16 ) {
V_13 = F_2 ( V_2 ,
V_17 , 0 ,
( 1ULL << 40 ) ,
V_18 ,
V_19 ,
& V_12 ) ;
}
V_2 -> V_20 = V_9 -> V_21 . V_22 ;
} else
if ( V_9 -> V_21 . V_23 . V_24 == V_25 ) {
V_13 = F_2 ( V_2 , V_17 , 0 ,
V_6 -> V_26 . V_27 ,
V_18 ,
V_28 , & V_12 ) ;
V_2 -> V_20 = V_9 -> V_21 . V_23 . V_29 << V_30 ;
} else
if ( V_6 -> V_14 != V_31 ) {
V_13 = F_2 ( V_2 , V_17 , 0 ,
V_6 -> V_32 ,
V_18 ,
V_33 , & V_12 ) ;
V_2 -> V_20 = V_9 -> V_21 . V_23 . V_29 << V_30 ;
} else {
V_13 = F_2 ( V_2 , V_17 ,
F_3 ( V_4 -> V_34 , 1 ) ,
V_6 -> V_32 ,
V_18 ,
V_35 , & V_12 ) ;
V_2 -> V_20 = V_9 -> V_21 . V_23 . V_29 << V_30 ;
}
F_4 ( V_12 , & V_2 -> V_12 ) ;
F_4 ( NULL , & V_12 ) ;
return V_13 ;
}
static struct V_8 *
F_5 ( struct V_3 * V_4 )
{
struct V_8 * V_12 = NULL ;
int V_36 , V_13 ;
if ( V_37 )
V_36 = V_38 ;
else
V_36 = V_39 ;
V_13 = F_6 ( V_4 , NULL , 65536 , 0 , V_36 , 0 , 0x0000 , & V_12 ) ;
if ( V_13 ) {
F_7 ( V_4 , L_1 , V_13 ) ;
return NULL ;
}
V_13 = F_8 ( V_12 , V_36 ) ;
if ( V_13 ) {
F_7 ( V_4 , L_2 , V_13 ) ;
F_9 ( NULL , & V_12 ) ;
return NULL ;
}
V_13 = F_10 ( V_12 ) ;
if ( V_13 ) {
F_11 ( V_12 ) ;
F_9 ( NULL , & V_12 ) ;
return NULL ;
}
return V_12 ;
}
int
F_12 ( struct V_3 * V_4 , struct V_1 * * V_40 ,
struct V_41 * V_42 ,
T_1 V_43 , T_1 V_44 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_45 * V_46 = & V_6 -> V_47 . V_48 ;
struct V_1 * V_2 ;
unsigned long V_49 ;
int V_13 ;
V_2 = F_13 ( sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 )
return - V_51 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_42 = V_42 ;
V_2 -> V_43 = V_43 ;
V_2 -> V_44 = V_44 ;
F_14 ( & V_2 -> V_52 ) ;
F_15 ( & V_2 -> V_53 , 1 ) ;
F_16 ( & V_2 -> V_54 ) ;
F_17 ( & V_2 -> V_54 ) ;
F_18 ( & V_6 -> V_55 . V_56 , V_49 ) ;
for ( V_2 -> V_57 = 0 ; V_2 -> V_57 < V_46 -> V_55 ; V_2 -> V_57 ++ ) {
if ( ! V_6 -> V_55 . V_58 [ V_2 -> V_57 ] ) {
F_19 ( V_2 , & V_6 -> V_55 . V_58 [ V_2 -> V_57 ] ) ;
break;
}
}
F_20 ( & V_6 -> V_55 . V_56 , V_49 ) ;
if ( V_2 -> V_57 == V_46 -> V_55 ) {
F_21 ( & V_2 -> V_54 ) ;
F_22 ( V_2 ) ;
return - V_59 ;
}
F_23 ( V_4 , L_3 , V_2 -> V_57 ) ;
F_24 ( & V_2 -> V_60 . V_61 ) ;
F_24 ( & V_2 -> V_60 . V_62 ) ;
F_24 ( & V_2 -> V_63 . V_64 ) ;
V_2 -> V_10 = F_5 ( V_4 ) ;
if ( ! V_2 -> V_10 ) {
V_13 = - V_51 ;
F_7 ( V_4 , L_4 , V_13 ) ;
F_25 ( & V_2 ) ;
return V_13 ;
}
F_26 ( V_2 ) ;
V_2 -> V_65 = 0x40 ;
V_2 -> V_66 = 0x44 ;
V_13 = F_27 ( V_2 ) ;
if ( V_13 ) {
F_7 ( V_4 , L_5 , V_13 ) ;
F_25 ( & V_2 ) ;
return V_13 ;
}
V_13 = F_28 ( V_2 , V_43 , V_44 ) ;
if ( V_13 ) {
F_7 ( V_4 , L_6 , V_13 ) ;
F_25 ( & V_2 ) ;
return V_13 ;
}
V_13 = F_1 ( V_2 ) ;
if ( V_13 ) {
F_7 ( V_4 , L_7 , V_13 ) ;
F_25 ( & V_2 ) ;
return V_13 ;
}
V_46 -> V_67 ( V_4 , false ) ;
V_13 = V_46 -> V_68 ( V_2 ) ;
if ( V_13 ) {
F_25 ( & V_2 ) ;
return V_13 ;
}
V_46 -> V_67 ( V_4 , true ) ;
V_13 = F_29 ( V_2 ) ;
if ( ! V_13 )
V_13 = F_30 ( V_2 ) ;
if ( V_13 ) {
F_25 ( & V_2 ) ;
return V_13 ;
}
F_31 ( V_2 ) ;
F_23 ( V_4 , L_8 , V_2 -> V_57 ) ;
* V_40 = V_2 ;
return 0 ;
}
struct V_1 *
F_32 ( struct V_1 * V_52 )
{
struct V_1 * V_2 = NULL ;
if ( F_33 ( V_52 && F_34 ( & V_52 -> V_53 ) ) )
F_19 ( V_52 , & V_2 ) ;
return V_2 ;
}
struct V_1 *
F_35 ( struct V_3 * V_4 , struct V_41 * V_42 , int V_57 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_1 * V_2 ;
unsigned long V_49 ;
if ( F_36 ( V_57 < 0 || V_57 >= V_69 ) )
return F_37 ( - V_70 ) ;
F_18 ( & V_6 -> V_55 . V_56 , V_49 ) ;
V_2 = F_32 ( V_6 -> V_55 . V_58 [ V_57 ] ) ;
F_20 ( & V_6 -> V_55 . V_56 , V_49 ) ;
if ( F_36 ( ! V_2 ) )
return F_37 ( - V_70 ) ;
if ( F_36 ( V_42 && V_2 -> V_42 != V_42 ) ) {
F_38 ( & V_2 ) ;
return F_37 ( - V_70 ) ;
}
F_17 ( & V_2 -> V_54 ) ;
return V_2 ;
}
void
F_38 ( struct V_1 * * V_71 )
{
struct V_1 * V_2 = * V_71 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_45 * V_46 = & V_6 -> V_47 . V_48 ;
unsigned long V_49 ;
int V_72 ;
if ( F_33 ( ! F_39 ( & V_2 -> V_53 ) ) ) {
F_19 ( NULL , V_71 ) ;
return;
}
F_23 ( V_4 , L_9 , V_2 -> V_57 ) ;
F_40 ( V_2 ) ;
F_41 ( V_2 ) ;
F_42 ( V_2 ) ;
V_46 -> V_67 ( V_4 , false ) ;
V_46 -> V_73 ( V_2 ) ;
for ( V_72 = 0 ; V_72 < V_74 ; V_72 ++ ) {
if ( V_2 -> V_75 [ V_72 ] )
V_6 -> V_76 [ V_72 ] -> F_43 ( V_2 , V_72 ) ;
}
V_46 -> V_67 ( V_4 , true ) ;
F_18 ( & V_6 -> V_55 . V_56 , V_49 ) ;
F_19 ( NULL , & V_6 -> V_55 . V_58 [ V_2 -> V_57 ] ) ;
F_20 ( & V_6 -> V_55 . V_56 , V_49 ) ;
F_4 ( NULL , & V_2 -> V_12 ) ;
if ( V_2 -> V_10 ) {
F_44 ( V_2 -> V_10 ) ;
F_11 ( V_2 -> V_10 ) ;
F_9 ( NULL , & V_2 -> V_10 ) ;
}
F_45 ( V_2 ) ;
F_46 ( V_2 ) ;
F_19 ( NULL , V_71 ) ;
}
void
F_25 ( struct V_1 * * V_71 )
{
F_21 ( & ( * V_71 ) -> V_54 ) ;
F_38 ( V_71 ) ;
}
static void
F_47 ( struct V_77 * V_52 )
{
struct V_1 * V_2 =
F_48 ( V_52 , struct V_1 , V_52 ) ;
F_22 ( V_2 ) ;
}
void
F_19 ( struct V_1 * V_2 ,
struct V_1 * * V_71 )
{
if ( V_2 )
F_49 ( & V_2 -> V_52 ) ;
if ( * V_71 )
F_50 ( & ( * V_71 ) -> V_52 , F_47 ) ;
* V_71 = V_2 ;
}
void
F_41 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_78 * V_63 = NULL ;
int V_13 ;
F_51 ( V_2 ) ;
if ( V_2 -> V_63 . V_79 != V_2 -> V_63 . V_80 ) {
V_13 = F_52 ( V_2 , & V_63 , true ) ;
if ( ! V_13 ) {
V_13 = F_53 ( V_63 , false , false ) ;
F_54 ( & V_63 ) ;
}
if ( V_13 )
F_7 ( V_4 , L_10 , V_2 -> V_57 ) ;
}
}
void
F_55 ( struct V_3 * V_4 , struct V_41 * V_42 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_81 * V_47 = & V_6 -> V_47 ;
struct V_1 * V_2 ;
int V_72 ;
F_23 ( V_4 , L_11 ) ;
for ( V_72 = 0 ; V_72 < V_47 -> V_48 . V_55 ; V_72 ++ ) {
V_2 = F_35 ( V_4 , V_42 , V_72 ) ;
if ( F_56 ( V_2 ) )
continue;
F_57 ( & V_2 -> V_53 ) ;
F_25 ( & V_2 ) ;
}
}
static int
F_58 ( struct V_3 * V_4 , void * V_82 ,
struct V_41 * V_42 )
{
struct V_5 * V_6 = V_4 -> V_7 ;
struct V_83 * V_84 = V_82 ;
struct V_1 * V_2 ;
int V_13 ;
if ( ! V_6 -> V_76 [ V_85 ] )
return - V_59 ;
if ( V_84 -> V_86 == ~ 0 || V_84 -> V_87 == ~ 0 )
return - V_70 ;
V_13 = F_12 ( V_4 , & V_2 , V_42 ,
V_84 -> V_86 ,
V_84 -> V_87 ) ;
if ( V_13 )
return V_13 ;
V_84 -> V_88 = V_2 -> V_57 ;
if ( V_2 -> V_89 . V_90 )
V_84 -> V_91 = V_92 |
V_93 ;
else if ( V_2 -> V_10 -> V_21 . V_23 . V_24 == V_94 )
V_84 -> V_91 = V_92 ;
else
V_84 -> V_91 = V_93 ;
if ( V_6 -> V_14 < V_16 ) {
V_84 -> V_95 [ 0 ] . V_96 = V_97 ;
if ( V_6 -> V_14 < V_15 )
V_84 -> V_95 [ 0 ] . V_98 = 0x0039 ;
else
V_84 -> V_95 [ 0 ] . V_98 = 0x5039 ;
V_84 -> V_95 [ 1 ] . V_96 = V_99 ;
V_84 -> V_95 [ 1 ] . V_98 = V_100 ;
V_84 -> V_101 = 2 ;
} else {
V_84 -> V_95 [ 0 ] . V_96 = 0x9039 ;
V_84 -> V_95 [ 0 ] . V_98 = 0x9039 ;
V_84 -> V_101 = 1 ;
}
V_13 = F_59 ( V_42 , V_2 -> V_102 -> V_103 ,
& V_84 -> V_104 ) ;
if ( V_13 == 0 )
F_60 ( & V_2 -> V_53 ) ;
F_25 ( & V_2 ) ;
return V_13 ;
}
static int
F_61 ( struct V_3 * V_4 , void * V_82 ,
struct V_41 * V_42 )
{
struct V_105 * V_106 = V_82 ;
struct V_1 * V_2 ;
V_2 = F_35 ( V_4 , V_42 , V_106 -> V_88 ) ;
if ( F_56 ( V_2 ) )
return F_62 ( V_2 ) ;
F_57 ( & V_2 -> V_53 ) ;
F_25 ( & V_2 ) ;
return 0 ;
}
