struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 ;
F_2 (crtc, dev)
if ( V_4 == V_5 -> V_6 )
return V_5 ;
return NULL ;
}
int F_3 ( struct V_1 * V_5 )
{
struct V_7 V_8 = {
. V_5 = V_5 ,
} ;
F_4 ( F_5 ( V_5 -> V_3 ) ) ;
return F_6 ( & V_8 ) ;
}
int F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
int V_9 = 0 ;
F_8 ( V_3 ) ;
F_2 (crtc, dev)
if ( V_5 -> V_10 ) {
V_9 = F_3 ( V_5 ) ;
if ( V_9 )
goto V_11;
}
V_11:
F_9 ( V_3 ) ;
return V_9 ;
}
static unsigned int F_10 ( struct V_2 * V_3 )
{
unsigned int V_12 = 0 ;
struct V_1 * V_13 ;
F_2 (tmp, dev) {
V_12 ++ ;
}
return V_12 ;
}
int F_11 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
int V_9 = 0 ;
F_2 (crtc, dev) {
if ( F_12 ( V_5 ) )
F_13 ( L_1 ,
V_5 -> V_14 ) ;
if ( V_5 -> V_15 -> V_16 )
V_9 = V_5 -> V_15 -> V_16 ( V_5 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
F_2 (crtc, dev) {
if ( V_5 -> V_15 -> V_17 )
V_5 -> V_15 -> V_17 ( V_5 ) ;
F_15 ( V_5 ) ;
}
}
static int F_16 ( struct V_1 * V_5 )
{
#ifdef F_17
F_18 ( & V_5 -> V_18 . V_19 ) ;
F_19 ( & V_5 -> V_18 . V_20 ) ;
V_5 -> V_18 . V_21 = F_20 ( L_2 , V_22 ) ;
if ( ! V_5 -> V_18 . V_21 )
return - V_23 ;
#endif
return 0 ;
}
static void F_21 ( struct V_1 * V_5 )
{
#ifdef F_17
F_22 ( V_5 -> V_18 . V_21 ) ;
#endif
}
static struct V_1 * F_23 ( struct V_24 * V_25 )
{
F_24 ( V_25 -> V_26 != & V_27 ) ;
return F_25 ( V_25 -> V_19 , struct V_1 , V_28 ) ;
}
static const char * F_26 ( struct V_24 * V_25 )
{
struct V_1 * V_5 = F_23 ( V_25 ) ;
return V_5 -> V_3 -> V_29 -> V_14 ;
}
static const char * F_27 ( struct V_24 * V_25 )
{
struct V_1 * V_5 = F_23 ( V_25 ) ;
return V_5 -> V_30 ;
}
static bool F_28 ( struct V_24 * V_25 )
{
return true ;
}
struct V_24 * F_29 ( struct V_1 * V_5 )
{
struct V_24 * V_25 ;
V_25 = F_30 ( sizeof( * V_25 ) , V_22 ) ;
if ( ! V_25 )
return NULL ;
F_31 ( V_25 , & V_27 , & V_5 -> V_28 ,
V_5 -> V_31 , ++ V_5 -> V_32 ) ;
return V_25 ;
}
int F_32 ( struct V_2 * V_3 , struct V_1 * V_5 ,
struct V_33 * V_34 ,
struct V_33 * V_35 ,
const struct V_36 * V_15 ,
const char * V_14 , ... )
{
struct V_37 * V_38 = & V_3 -> V_39 ;
int V_9 ;
F_4 ( V_34 && V_34 -> type != V_40 ) ;
F_4 ( V_35 && V_35 -> type != V_41 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_15 = V_15 ;
F_33 ( & V_5 -> V_42 ) ;
F_18 ( & V_5 -> V_43 ) ;
F_34 ( & V_5 -> V_44 ) ;
V_9 = F_35 ( V_3 , & V_5 -> V_45 , V_46 ) ;
if ( V_9 )
return V_9 ;
if ( V_14 ) {
T_1 V_47 ;
va_start ( V_47 , V_14 ) ;
V_5 -> V_14 = F_36 ( V_22 , V_14 , V_47 ) ;
va_end ( V_47 ) ;
} else {
V_5 -> V_14 = F_37 ( V_22 , L_3 ,
F_10 ( V_3 ) ) ;
}
if ( ! V_5 -> V_14 ) {
F_38 ( V_3 , & V_5 -> V_45 ) ;
return - V_23 ;
}
V_5 -> V_31 = F_39 ( 1 ) ;
F_18 ( & V_5 -> V_28 ) ;
snprintf ( V_5 -> V_30 , sizeof( V_5 -> V_30 ) ,
L_4 , V_5 -> V_45 . V_48 , V_5 -> V_14 ) ;
V_5 -> V_45 . V_49 = & V_5 -> V_49 ;
F_40 ( & V_5 -> V_50 , & V_38 -> V_51 ) ;
V_5 -> V_6 = V_38 -> V_52 ++ ;
V_5 -> V_34 = V_34 ;
V_5 -> V_35 = V_35 ;
if ( V_34 && ! V_34 -> V_53 )
V_34 -> V_53 = 1 << F_41 ( V_5 ) ;
if ( V_35 && ! V_35 -> V_53 )
V_35 -> V_53 = 1 << F_41 ( V_5 ) ;
V_9 = F_16 ( V_5 ) ;
if ( V_9 ) {
F_38 ( V_3 , & V_5 -> V_45 ) ;
return V_9 ;
}
if ( F_42 ( V_3 , V_54 ) ) {
F_43 ( & V_5 -> V_45 , V_38 -> V_55 , 0 ) ;
F_43 ( & V_5 -> V_45 , V_38 -> V_56 , 0 ) ;
F_43 ( & V_5 -> V_45 ,
V_38 -> V_57 , 0 ) ;
}
return 0 ;
}
void F_44 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
F_21 ( V_5 ) ;
F_22 ( V_5 -> V_58 ) ;
V_5 -> V_58 = NULL ;
F_45 ( & V_5 -> V_44 ) ;
F_38 ( V_3 , & V_5 -> V_45 ) ;
F_46 ( & V_5 -> V_50 ) ;
V_3 -> V_39 . V_52 -- ;
F_4 ( V_5 -> V_59 && ! V_5 -> V_15 -> V_60 ) ;
if ( V_5 -> V_59 && V_5 -> V_15 -> V_60 )
V_5 -> V_15 -> V_60 ( V_5 , V_5 -> V_59 ) ;
F_22 ( V_5 -> V_14 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
}
int F_47 ( struct V_2 * V_3 ,
void * V_61 , struct V_62 * V_63 )
{
struct V_64 * V_65 = V_61 ;
struct V_1 * V_5 ;
if ( ! F_42 ( V_3 , V_66 ) )
return - V_67 ;
V_5 = F_48 ( V_3 , V_65 -> V_68 ) ;
if ( ! V_5 )
return - V_69 ;
V_65 -> V_70 = V_5 -> V_70 ;
F_49 ( & V_5 -> V_34 -> V_44 , NULL ) ;
if ( V_5 -> V_34 -> V_59 && V_5 -> V_34 -> V_59 -> V_71 )
V_65 -> V_72 = V_5 -> V_34 -> V_59 -> V_71 -> V_45 . V_48 ;
else if ( ! V_5 -> V_34 -> V_59 && V_5 -> V_34 -> V_71 )
V_65 -> V_72 = V_5 -> V_34 -> V_71 -> V_45 . V_48 ;
else
V_65 -> V_72 = 0 ;
if ( V_5 -> V_34 -> V_59 ) {
V_65 -> V_73 = V_5 -> V_34 -> V_59 -> V_74 >> 16 ;
V_65 -> V_75 = V_5 -> V_34 -> V_59 -> V_76 >> 16 ;
}
F_50 ( & V_5 -> V_34 -> V_44 ) ;
F_49 ( & V_5 -> V_44 , NULL ) ;
if ( V_5 -> V_59 ) {
if ( V_5 -> V_59 -> V_77 ) {
F_51 ( & V_65 -> V_78 , & V_5 -> V_59 -> V_78 ) ;
V_65 -> V_79 = 1 ;
} else {
V_65 -> V_79 = 0 ;
}
} else {
V_65 -> V_73 = V_5 -> V_73 ;
V_65 -> V_75 = V_5 -> V_75 ;
if ( V_5 -> V_10 ) {
F_51 ( & V_65 -> V_78 , & V_5 -> V_78 ) ;
V_65 -> V_79 = 1 ;
} else {
V_65 -> V_79 = 0 ;
}
}
F_50 ( & V_5 -> V_44 ) ;
return 0 ;
}
static int F_52 ( struct V_7 * V_8 ,
struct V_80 * V_81 )
{
struct V_1 * V_5 = V_8 -> V_5 ;
struct V_82 * V_71 ;
struct V_1 * V_13 ;
int V_9 ;
F_2 (tmp, crtc->dev)
V_13 -> V_34 -> V_83 = V_13 -> V_34 -> V_71 ;
V_71 = V_8 -> V_71 ;
V_9 = V_5 -> V_15 -> V_84 ( V_8 , V_81 ) ;
if ( V_9 == 0 ) {
V_5 -> V_34 -> V_5 = V_5 ;
V_5 -> V_34 -> V_71 = V_71 ;
}
F_2 (tmp, crtc->dev) {
if ( V_13 -> V_34 -> V_71 )
F_53 ( V_13 -> V_34 -> V_71 ) ;
if ( V_13 -> V_34 -> V_83 )
F_54 ( V_13 -> V_34 -> V_83 ) ;
V_13 -> V_34 -> V_83 = NULL ;
}
return V_9 ;
}
int F_6 ( struct V_7 * V_8 )
{
F_4 ( F_5 ( V_8 -> V_5 -> V_3 ) ) ;
return F_52 ( V_8 , NULL ) ;
}
int F_55 ( const struct V_1 * V_5 ,
int V_73 , int V_75 ,
const struct V_85 * V_78 ,
const struct V_82 * V_71 )
{
int V_86 , V_87 ;
F_56 ( V_78 , & V_86 , & V_87 ) ;
if ( V_5 -> V_59 &&
F_57 ( V_5 -> V_34 -> V_59 -> V_88 ) )
F_58 ( V_86 , V_87 ) ;
return F_59 ( V_73 << 16 , V_75 << 16 ,
V_86 << 16 , V_87 << 16 ,
V_71 ) ;
}
int F_60 ( struct V_2 * V_3 , void * V_61 ,
struct V_62 * V_63 )
{
struct V_37 * V_38 = & V_3 -> V_39 ;
struct V_64 * V_89 = V_61 ;
struct V_1 * V_5 ;
struct V_90 * * V_91 = NULL , * V_92 ;
struct V_82 * V_71 = NULL ;
struct V_85 * V_78 = NULL ;
struct V_7 V_8 ;
T_2 T_3 * V_93 ;
struct V_80 V_81 ;
int V_9 ;
int V_94 ;
if ( ! F_42 ( V_3 , V_66 ) )
return - V_67 ;
if ( V_89 -> V_73 & 0xffff0000 || V_89 -> V_75 & 0xffff0000 )
return - V_95 ;
V_5 = F_48 ( V_3 , V_89 -> V_68 ) ;
if ( ! V_5 ) {
F_61 ( L_5 , V_89 -> V_68 ) ;
return - V_69 ;
}
F_61 ( L_6 , V_5 -> V_45 . V_48 , V_5 -> V_14 ) ;
F_62 ( & V_5 -> V_3 -> V_39 . V_44 ) ;
F_63 ( & V_81 , 0 ) ;
V_96:
V_9 = F_64 ( V_5 -> V_3 , & V_81 ) ;
if ( V_9 )
goto V_11;
if ( V_89 -> V_79 ) {
if ( V_89 -> V_72 == - 1 ) {
if ( ! V_5 -> V_34 -> V_71 ) {
F_61 ( L_7 ) ;
V_9 = - V_67 ;
goto V_11;
}
V_71 = V_5 -> V_34 -> V_71 ;
F_53 ( V_71 ) ;
} else {
V_71 = F_65 ( V_3 , V_89 -> V_72 ) ;
if ( ! V_71 ) {
F_61 ( L_8 ,
V_89 -> V_72 ) ;
V_9 = - V_69 ;
goto V_11;
}
}
V_78 = F_66 ( V_3 ) ;
if ( ! V_78 ) {
V_9 = - V_23 ;
goto V_11;
}
V_9 = F_67 ( V_78 , & V_89 -> V_78 ) ;
if ( V_9 ) {
F_61 ( L_9 ) ;
goto V_11;
}
if ( ! V_5 -> V_34 -> V_97 ) {
V_9 = F_68 ( V_5 -> V_34 ,
V_71 -> V_98 -> V_98 ) ;
if ( V_9 ) {
struct V_99 V_100 ;
F_61 ( L_10 ,
F_69 ( V_71 -> V_98 -> V_98 ,
& V_100 ) ) ;
goto V_11;
}
}
V_9 = F_55 ( V_5 , V_89 -> V_73 , V_89 -> V_75 ,
V_78 , V_71 ) ;
if ( V_9 )
goto V_11;
}
if ( V_89 -> V_101 == 0 && V_78 ) {
F_61 ( L_11 ) ;
V_9 = - V_67 ;
goto V_11;
}
if ( V_89 -> V_101 > 0 && ( ! V_78 || ! V_71 ) ) {
F_61 ( L_12 ,
V_89 -> V_101 ) ;
V_9 = - V_67 ;
goto V_11;
}
if ( V_89 -> V_101 > 0 ) {
T_4 V_102 ;
if ( V_89 -> V_101 > V_38 -> V_103 ) {
V_9 = - V_67 ;
goto V_11;
}
V_91 = F_70 ( V_89 -> V_101 ,
sizeof( struct V_90 * ) ,
V_22 ) ;
if ( ! V_91 ) {
V_9 = - V_23 ;
goto V_11;
}
for ( V_94 = 0 ; V_94 < V_89 -> V_101 ; V_94 ++ ) {
V_91 [ V_94 ] = NULL ;
V_93 = ( T_2 T_3 * ) ( unsigned long ) V_89 -> V_93 ;
if ( F_71 ( V_102 , & V_93 [ V_94 ] ) ) {
V_9 = - V_104 ;
goto V_11;
}
V_92 = F_72 ( V_3 , V_102 ) ;
if ( ! V_92 ) {
F_61 ( L_13 ,
V_102 ) ;
V_9 = - V_69 ;
goto V_11;
}
F_61 ( L_14 ,
V_92 -> V_45 . V_48 ,
V_92 -> V_14 ) ;
V_91 [ V_94 ] = V_92 ;
}
}
V_8 . V_5 = V_5 ;
V_8 . V_73 = V_89 -> V_73 ;
V_8 . V_75 = V_89 -> V_75 ;
V_8 . V_78 = V_78 ;
V_8 . V_105 = V_91 ;
V_8 . V_106 = V_89 -> V_101 ;
V_8 . V_71 = V_71 ;
V_9 = F_52 ( & V_8 , & V_81 ) ;
V_11:
if ( V_71 )
F_54 ( V_71 ) ;
if ( V_91 ) {
for ( V_94 = 0 ; V_94 < V_89 -> V_101 ; V_94 ++ ) {
if ( V_91 [ V_94 ] )
F_73 ( V_91 [ V_94 ] ) ;
}
}
F_22 ( V_91 ) ;
F_74 ( V_3 , V_78 ) ;
if ( V_9 == - V_107 ) {
F_75 ( & V_81 ) ;
goto V_96;
}
F_76 ( & V_81 ) ;
F_77 ( & V_81 ) ;
F_78 ( & V_5 -> V_3 -> V_39 . V_44 ) ;
return V_9 ;
}
int F_79 ( struct V_108 * V_109 ,
struct V_110 * V_111 ,
T_5 V_112 )
{
int V_9 = - V_67 ;
struct V_1 * V_5 = F_80 ( V_109 ) ;
if ( V_5 -> V_15 -> V_113 )
V_9 = V_5 -> V_15 -> V_113 ( V_5 , V_111 , V_112 ) ;
if ( ! V_9 )
F_81 ( V_109 , V_111 , V_112 ) ;
return V_9 ;
}
