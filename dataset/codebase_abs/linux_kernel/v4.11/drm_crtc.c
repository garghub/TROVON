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
return F_4 ( & V_8 ) ;
}
int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
int V_9 = 0 ;
F_6 ( V_3 ) ;
F_2 (crtc, dev)
if ( V_5 -> V_10 ) {
V_9 = F_3 ( V_5 ) ;
if ( V_9 )
goto V_11;
}
V_11:
F_7 ( V_3 ) ;
return V_9 ;
}
static unsigned int F_8 ( struct V_2 * V_3 )
{
unsigned int V_12 = 0 ;
struct V_1 * V_13 ;
F_2 (tmp, dev) {
V_12 ++ ;
}
return V_12 ;
}
int F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
int V_9 = 0 ;
F_2 (crtc, dev) {
if ( F_10 ( V_5 ) )
F_11 ( L_1 ,
V_5 -> V_14 ) ;
if ( V_5 -> V_15 -> V_16 )
V_9 = V_5 -> V_15 -> V_16 ( V_5 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_5 ;
F_2 (crtc, dev) {
if ( V_5 -> V_15 -> V_17 )
V_5 -> V_15 -> V_17 ( V_5 ) ;
F_13 ( V_5 ) ;
}
}
static int F_14 ( struct V_1 * V_5 )
{
#ifdef F_15
F_16 ( & V_5 -> V_18 . V_19 ) ;
F_17 ( & V_5 -> V_18 . V_20 ) ;
V_5 -> V_18 . V_21 = F_18 ( L_2 , V_22 ) ;
if ( ! V_5 -> V_18 . V_21 )
return - V_23 ;
#endif
return 0 ;
}
static void F_19 ( struct V_1 * V_5 )
{
#ifdef F_15
F_20 ( V_5 -> V_18 . V_21 ) ;
#endif
}
static struct V_1 * F_21 ( struct V_24 * V_25 )
{
F_22 ( V_25 -> V_26 != & V_27 ) ;
return F_23 ( V_25 -> V_19 , struct V_1 , V_28 ) ;
}
static const char * F_24 ( struct V_24 * V_25 )
{
struct V_1 * V_5 = F_21 ( V_25 ) ;
return V_5 -> V_3 -> V_29 -> V_14 ;
}
static const char * F_25 ( struct V_24 * V_25 )
{
struct V_1 * V_5 = F_21 ( V_25 ) ;
return V_5 -> V_30 ;
}
static bool F_26 ( struct V_24 * V_25 )
{
return true ;
}
struct V_24 * F_27 ( struct V_1 * V_5 )
{
struct V_24 * V_25 ;
V_25 = F_28 ( sizeof( * V_25 ) , V_22 ) ;
if ( ! V_25 )
return NULL ;
F_29 ( V_25 , & V_27 , & V_5 -> V_28 ,
V_5 -> V_31 , ++ V_5 -> V_32 ) ;
return V_25 ;
}
int F_30 ( struct V_2 * V_3 , struct V_1 * V_5 ,
struct V_33 * V_34 ,
struct V_33 * V_35 ,
const struct V_36 * V_15 ,
const char * V_14 , ... )
{
struct V_37 * V_38 = & V_3 -> V_39 ;
int V_9 ;
F_31 ( V_34 && V_34 -> type != V_40 ) ;
F_31 ( V_35 && V_35 -> type != V_41 ) ;
V_5 -> V_3 = V_3 ;
V_5 -> V_15 = V_15 ;
F_32 ( & V_5 -> V_42 ) ;
F_16 ( & V_5 -> V_43 ) ;
F_33 ( & V_5 -> V_44 ) ;
V_9 = F_34 ( V_3 , & V_5 -> V_45 , V_46 ) ;
if ( V_9 )
return V_9 ;
if ( V_14 ) {
T_1 V_47 ;
va_start ( V_47 , V_14 ) ;
V_5 -> V_14 = F_35 ( V_22 , V_14 , V_47 ) ;
va_end ( V_47 ) ;
} else {
V_5 -> V_14 = F_36 ( V_22 , L_3 ,
F_8 ( V_3 ) ) ;
}
if ( ! V_5 -> V_14 ) {
F_37 ( V_3 , & V_5 -> V_45 ) ;
return - V_23 ;
}
V_5 -> V_31 = F_38 ( 1 ) ;
F_16 ( & V_5 -> V_28 ) ;
snprintf ( V_5 -> V_30 , sizeof( V_5 -> V_30 ) ,
L_4 , V_5 -> V_45 . V_48 , V_5 -> V_14 ) ;
V_5 -> V_45 . V_49 = & V_5 -> V_49 ;
F_39 ( & V_5 -> V_50 , & V_38 -> V_51 ) ;
V_5 -> V_6 = V_38 -> V_52 ++ ;
V_5 -> V_34 = V_34 ;
V_5 -> V_35 = V_35 ;
if ( V_34 && ! V_34 -> V_53 )
V_34 -> V_53 = 1 << F_40 ( V_5 ) ;
if ( V_35 && ! V_35 -> V_53 )
V_35 -> V_53 = 1 << F_40 ( V_5 ) ;
V_9 = F_14 ( V_5 ) ;
if ( V_9 ) {
F_37 ( V_3 , & V_5 -> V_45 ) ;
return V_9 ;
}
if ( F_41 ( V_3 , V_54 ) ) {
F_42 ( & V_5 -> V_45 , V_38 -> V_55 , 0 ) ;
F_42 ( & V_5 -> V_45 , V_38 -> V_56 , 0 ) ;
F_42 ( & V_5 -> V_45 ,
V_38 -> V_57 , 0 ) ;
}
return 0 ;
}
void F_43 ( struct V_1 * V_5 )
{
struct V_2 * V_3 = V_5 -> V_3 ;
F_19 ( V_5 ) ;
F_20 ( V_5 -> V_58 ) ;
V_5 -> V_58 = NULL ;
F_44 ( & V_5 -> V_44 ) ;
F_37 ( V_3 , & V_5 -> V_45 ) ;
F_45 ( & V_5 -> V_50 ) ;
V_3 -> V_39 . V_52 -- ;
F_31 ( V_5 -> V_59 && ! V_5 -> V_15 -> V_60 ) ;
if ( V_5 -> V_59 && V_5 -> V_15 -> V_60 )
V_5 -> V_15 -> V_60 ( V_5 , V_5 -> V_59 ) ;
F_20 ( V_5 -> V_14 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
}
int F_46 ( struct V_2 * V_3 ,
void * V_61 , struct V_62 * V_63 )
{
struct V_64 * V_65 = V_61 ;
struct V_1 * V_5 ;
if ( ! F_41 ( V_3 , V_66 ) )
return - V_67 ;
V_5 = F_47 ( V_3 , V_65 -> V_68 ) ;
if ( ! V_5 )
return - V_69 ;
F_48 ( V_5 , V_5 -> V_34 ) ;
V_65 -> V_70 = V_5 -> V_70 ;
if ( V_5 -> V_34 -> V_59 && V_5 -> V_34 -> V_59 -> V_71 )
V_65 -> V_72 = V_5 -> V_34 -> V_59 -> V_71 -> V_45 . V_48 ;
else if ( ! V_5 -> V_34 -> V_59 && V_5 -> V_34 -> V_71 )
V_65 -> V_72 = V_5 -> V_34 -> V_71 -> V_45 . V_48 ;
else
V_65 -> V_72 = 0 ;
if ( V_5 -> V_59 ) {
V_65 -> V_73 = V_5 -> V_34 -> V_59 -> V_74 >> 16 ;
V_65 -> V_75 = V_5 -> V_34 -> V_59 -> V_76 >> 16 ;
if ( V_5 -> V_59 -> V_77 ) {
F_49 ( & V_65 -> V_78 , & V_5 -> V_59 -> V_78 ) ;
V_65 -> V_79 = 1 ;
} else {
V_65 -> V_79 = 0 ;
}
} else {
V_65 -> V_73 = V_5 -> V_73 ;
V_65 -> V_75 = V_5 -> V_75 ;
if ( V_5 -> V_10 ) {
F_49 ( & V_65 -> V_78 , & V_5 -> V_78 ) ;
V_65 -> V_79 = 1 ;
} else {
V_65 -> V_79 = 0 ;
}
}
F_50 ( V_5 ) ;
return 0 ;
}
int F_4 ( struct V_7 * V_8 )
{
struct V_1 * V_5 = V_8 -> V_5 ;
struct V_80 * V_71 ;
struct V_1 * V_13 ;
int V_9 ;
F_2 (tmp, crtc->dev)
V_13 -> V_34 -> V_81 = V_13 -> V_34 -> V_71 ;
V_71 = V_8 -> V_71 ;
V_9 = V_5 -> V_15 -> V_82 ( V_8 ) ;
if ( V_9 == 0 ) {
V_5 -> V_34 -> V_5 = V_5 ;
V_5 -> V_34 -> V_71 = V_71 ;
}
F_2 (tmp, crtc->dev) {
if ( V_13 -> V_34 -> V_71 )
F_51 ( V_13 -> V_34 -> V_71 ) ;
if ( V_13 -> V_34 -> V_81 )
F_52 ( V_13 -> V_34 -> V_81 ) ;
V_13 -> V_34 -> V_81 = NULL ;
}
return V_9 ;
}
int F_53 ( const struct V_1 * V_5 ,
int V_73 , int V_75 ,
const struct V_83 * V_78 ,
const struct V_80 * V_71 )
{
int V_84 , V_85 ;
F_54 ( V_78 , & V_84 , & V_85 ) ;
if ( V_5 -> V_59 &&
F_55 ( V_5 -> V_34 -> V_59 -> V_86 ) )
F_56 ( V_84 , V_85 ) ;
return F_57 ( V_73 << 16 , V_75 << 16 ,
V_84 << 16 , V_85 << 16 ,
V_71 ) ;
}
int F_58 ( struct V_2 * V_3 , void * V_61 ,
struct V_62 * V_63 )
{
struct V_37 * V_38 = & V_3 -> V_39 ;
struct V_64 * V_87 = V_61 ;
struct V_1 * V_5 ;
struct V_88 * * V_89 = NULL , * V_90 ;
struct V_80 * V_71 = NULL ;
struct V_83 * V_78 = NULL ;
struct V_7 V_8 ;
T_2 T_3 * V_91 ;
int V_9 ;
int V_92 ;
if ( ! F_41 ( V_3 , V_66 ) )
return - V_67 ;
if ( V_87 -> V_73 & 0xffff0000 || V_87 -> V_75 & 0xffff0000 )
return - V_93 ;
F_6 ( V_3 ) ;
V_5 = F_47 ( V_3 , V_87 -> V_68 ) ;
if ( ! V_5 ) {
F_59 ( L_5 , V_87 -> V_68 ) ;
V_9 = - V_69 ;
goto V_11;
}
F_59 ( L_6 , V_5 -> V_45 . V_48 , V_5 -> V_14 ) ;
if ( V_87 -> V_79 ) {
if ( V_87 -> V_72 == - 1 ) {
if ( ! V_5 -> V_34 -> V_71 ) {
F_59 ( L_7 ) ;
V_9 = - V_67 ;
goto V_11;
}
V_71 = V_5 -> V_34 -> V_71 ;
F_51 ( V_71 ) ;
} else {
V_71 = F_60 ( V_3 , V_87 -> V_72 ) ;
if ( ! V_71 ) {
F_59 ( L_8 ,
V_87 -> V_72 ) ;
V_9 = - V_69 ;
goto V_11;
}
}
V_78 = F_61 ( V_3 ) ;
if ( ! V_78 ) {
V_9 = - V_23 ;
goto V_11;
}
V_9 = F_62 ( V_78 , & V_87 -> V_78 ) ;
if ( V_9 ) {
F_59 ( L_9 ) ;
goto V_11;
}
if ( ! V_5 -> V_34 -> V_94 ) {
V_9 = F_63 ( V_5 -> V_34 ,
V_71 -> V_95 -> V_95 ) ;
if ( V_9 ) {
struct V_96 V_97 ;
F_59 ( L_10 ,
F_64 ( V_71 -> V_95 -> V_95 ,
& V_97 ) ) ;
goto V_11;
}
}
V_9 = F_53 ( V_5 , V_87 -> V_73 , V_87 -> V_75 ,
V_78 , V_71 ) ;
if ( V_9 )
goto V_11;
}
if ( V_87 -> V_98 == 0 && V_78 ) {
F_59 ( L_11 ) ;
V_9 = - V_67 ;
goto V_11;
}
if ( V_87 -> V_98 > 0 && ( ! V_78 || ! V_71 ) ) {
F_59 ( L_12 ,
V_87 -> V_98 ) ;
V_9 = - V_67 ;
goto V_11;
}
if ( V_87 -> V_98 > 0 ) {
T_4 V_99 ;
if ( V_87 -> V_98 > V_38 -> V_100 ) {
V_9 = - V_67 ;
goto V_11;
}
V_89 = F_65 ( V_87 -> V_98 ,
sizeof( struct V_88 * ) ,
V_22 ) ;
if ( ! V_89 ) {
V_9 = - V_23 ;
goto V_11;
}
for ( V_92 = 0 ; V_92 < V_87 -> V_98 ; V_92 ++ ) {
V_89 [ V_92 ] = NULL ;
V_91 = ( T_2 T_3 * ) ( unsigned long ) V_87 -> V_91 ;
if ( F_66 ( V_99 , & V_91 [ V_92 ] ) ) {
V_9 = - V_101 ;
goto V_11;
}
V_90 = F_67 ( V_3 , V_99 ) ;
if ( ! V_90 ) {
F_59 ( L_13 ,
V_99 ) ;
V_9 = - V_69 ;
goto V_11;
}
F_59 ( L_14 ,
V_90 -> V_45 . V_48 ,
V_90 -> V_14 ) ;
V_89 [ V_92 ] = V_90 ;
}
}
V_8 . V_5 = V_5 ;
V_8 . V_73 = V_87 -> V_73 ;
V_8 . V_75 = V_87 -> V_75 ;
V_8 . V_78 = V_78 ;
V_8 . V_102 = V_89 ;
V_8 . V_103 = V_87 -> V_98 ;
V_8 . V_71 = V_71 ;
V_9 = F_4 ( & V_8 ) ;
V_11:
if ( V_71 )
F_52 ( V_71 ) ;
if ( V_89 ) {
for ( V_92 = 0 ; V_92 < V_87 -> V_98 ; V_92 ++ ) {
if ( V_89 [ V_92 ] )
F_68 ( V_89 [ V_92 ] ) ;
}
}
F_20 ( V_89 ) ;
F_69 ( V_3 , V_78 ) ;
F_7 ( V_3 ) ;
return V_9 ;
}
int F_70 ( struct V_104 * V_105 ,
struct V_106 * V_107 ,
T_5 V_108 )
{
int V_9 = - V_67 ;
struct V_1 * V_5 = F_71 ( V_105 ) ;
if ( V_5 -> V_15 -> V_109 )
V_9 = V_5 -> V_15 -> V_109 ( V_5 , V_107 , V_108 ) ;
if ( ! V_9 )
F_72 ( V_105 , V_107 , V_108 ) ;
return V_9 ;
}
