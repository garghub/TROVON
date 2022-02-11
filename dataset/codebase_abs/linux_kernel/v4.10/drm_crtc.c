int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 = {
. V_2 = V_2 ,
} ;
return F_2 ( & V_4 ) ;
}
int F_3 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
int V_7 = 0 ;
F_4 ( V_6 ) ;
F_5 (crtc, dev)
if ( V_2 -> V_8 ) {
V_7 = F_1 ( V_2 ) ;
if ( V_7 )
goto V_9;
}
V_9:
F_6 ( V_6 ) ;
return V_7 ;
}
static unsigned int F_7 ( struct V_5 * V_6 )
{
unsigned int V_10 = 0 ;
struct V_1 * V_11 ;
F_5 (tmp, dev) {
V_10 ++ ;
}
return V_10 ;
}
int F_8 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
int V_7 = 0 ;
F_5 (crtc, dev) {
if ( F_9 ( V_2 ) )
F_10 ( L_1 ,
V_2 -> V_12 ) ;
if ( V_2 -> V_13 -> V_14 )
V_7 = V_2 -> V_13 -> V_14 ( V_2 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
void F_11 ( struct V_5 * V_6 )
{
struct V_1 * V_2 ;
F_5 (crtc, dev) {
if ( V_2 -> V_13 -> V_15 )
V_2 -> V_13 -> V_15 ( V_2 ) ;
F_12 ( V_2 ) ;
}
}
static int F_13 ( struct V_1 * V_2 )
{
#ifdef F_14
F_15 ( & V_2 -> V_16 . V_17 ) ;
F_16 ( & V_2 -> V_16 . V_18 ) ;
V_2 -> V_16 . V_19 = F_17 ( L_2 , V_20 ) ;
if ( ! V_2 -> V_16 . V_19 )
return - V_21 ;
#endif
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
#ifdef F_14
F_19 ( V_2 -> V_16 . V_19 ) ;
#endif
}
static struct V_1 * F_20 ( struct V_22 * V_23 )
{
F_21 ( V_23 -> V_24 != & V_25 ) ;
return F_22 ( V_23 -> V_17 , struct V_1 , V_26 ) ;
}
static const char * F_23 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_20 ( V_23 ) ;
return V_2 -> V_6 -> V_27 -> V_12 ;
}
static const char * F_24 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_20 ( V_23 ) ;
return V_2 -> V_28 ;
}
static bool F_25 ( struct V_22 * V_23 )
{
return true ;
}
struct V_22 * F_26 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
V_23 = F_27 ( sizeof( * V_23 ) , V_20 ) ;
if ( ! V_23 )
return NULL ;
F_28 ( V_23 , & V_25 , & V_2 -> V_26 ,
V_2 -> V_29 , ++ V_2 -> V_30 ) ;
return V_23 ;
}
int F_29 ( struct V_5 * V_6 , struct V_1 * V_2 ,
struct V_31 * V_32 ,
struct V_31 * V_33 ,
const struct V_34 * V_13 ,
const char * V_12 , ... )
{
struct V_35 * V_36 = & V_6 -> V_37 ;
int V_7 ;
F_30 ( V_32 && V_32 -> type != V_38 ) ;
F_30 ( V_33 && V_33 -> type != V_39 ) ;
V_2 -> V_6 = V_6 ;
V_2 -> V_13 = V_13 ;
F_31 ( & V_2 -> V_40 ) ;
F_15 ( & V_2 -> V_41 ) ;
F_32 ( & V_2 -> V_42 ) ;
V_7 = F_33 ( V_6 , & V_2 -> V_43 , V_44 ) ;
if ( V_7 )
return V_7 ;
if ( V_12 ) {
T_1 V_45 ;
va_start ( V_45 , V_12 ) ;
V_2 -> V_12 = F_34 ( V_20 , V_12 , V_45 ) ;
va_end ( V_45 ) ;
} else {
V_2 -> V_12 = F_35 ( V_20 , L_3 ,
F_7 ( V_6 ) ) ;
}
if ( ! V_2 -> V_12 ) {
F_36 ( V_6 , & V_2 -> V_43 ) ;
return - V_21 ;
}
V_2 -> V_29 = F_37 ( 1 ) ;
F_15 ( & V_2 -> V_26 ) ;
snprintf ( V_2 -> V_28 , sizeof( V_2 -> V_28 ) ,
L_4 , V_2 -> V_43 . V_46 , V_2 -> V_12 ) ;
V_2 -> V_43 . V_47 = & V_2 -> V_47 ;
F_38 ( & V_2 -> V_48 , & V_36 -> V_49 ) ;
V_2 -> V_50 = V_36 -> V_51 ++ ;
V_2 -> V_32 = V_32 ;
V_2 -> V_33 = V_33 ;
if ( V_32 && ! V_32 -> V_52 )
V_32 -> V_52 = 1 << F_39 ( V_2 ) ;
if ( V_33 && ! V_33 -> V_52 )
V_33 -> V_52 = 1 << F_39 ( V_2 ) ;
V_7 = F_13 ( V_2 ) ;
if ( V_7 ) {
F_36 ( V_6 , & V_2 -> V_43 ) ;
return V_7 ;
}
if ( F_40 ( V_6 , V_53 ) ) {
F_41 ( & V_2 -> V_43 , V_36 -> V_54 , 0 ) ;
F_41 ( & V_2 -> V_43 , V_36 -> V_55 , 0 ) ;
F_41 ( & V_2 -> V_43 ,
V_36 -> V_56 , 0 ) ;
}
return 0 ;
}
void F_42 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_18 ( V_2 ) ;
F_19 ( V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
F_43 ( & V_2 -> V_42 ) ;
F_36 ( V_6 , & V_2 -> V_43 ) ;
F_44 ( & V_2 -> V_48 ) ;
V_6 -> V_37 . V_51 -- ;
F_30 ( V_2 -> V_58 && ! V_2 -> V_13 -> V_59 ) ;
if ( V_2 -> V_58 && V_2 -> V_13 -> V_59 )
V_2 -> V_13 -> V_59 ( V_2 , V_2 -> V_58 ) ;
F_19 ( V_2 -> V_12 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
}
int F_45 ( struct V_5 * V_6 ,
void * V_60 , struct V_61 * V_62 )
{
struct V_63 * V_64 = V_60 ;
struct V_1 * V_2 ;
if ( ! F_40 ( V_6 , V_65 ) )
return - V_66 ;
V_2 = F_46 ( V_6 , V_64 -> V_67 ) ;
if ( ! V_2 )
return - V_68 ;
F_47 ( V_2 , V_2 -> V_32 ) ;
V_64 -> V_69 = V_2 -> V_69 ;
if ( V_2 -> V_32 -> V_70 )
V_64 -> V_71 = V_2 -> V_32 -> V_70 -> V_43 . V_46 ;
else
V_64 -> V_71 = 0 ;
if ( V_2 -> V_58 ) {
V_64 -> V_72 = V_2 -> V_32 -> V_58 -> V_73 >> 16 ;
V_64 -> V_74 = V_2 -> V_32 -> V_58 -> V_75 >> 16 ;
if ( V_2 -> V_58 -> V_76 ) {
F_48 ( & V_64 -> V_77 , & V_2 -> V_58 -> V_77 ) ;
V_64 -> V_78 = 1 ;
} else {
V_64 -> V_78 = 0 ;
}
} else {
V_64 -> V_72 = V_2 -> V_72 ;
V_64 -> V_74 = V_2 -> V_74 ;
if ( V_2 -> V_8 ) {
F_48 ( & V_64 -> V_77 , & V_2 -> V_77 ) ;
V_64 -> V_78 = 1 ;
} else {
V_64 -> V_78 = 0 ;
}
}
F_49 ( V_2 ) ;
return 0 ;
}
int F_2 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = V_4 -> V_2 ;
struct V_79 * V_70 ;
struct V_1 * V_11 ;
int V_7 ;
F_5 (tmp, crtc->dev)
V_11 -> V_32 -> V_80 = V_11 -> V_32 -> V_70 ;
V_70 = V_4 -> V_70 ;
V_7 = V_2 -> V_13 -> V_81 ( V_4 ) ;
if ( V_7 == 0 ) {
V_2 -> V_32 -> V_2 = V_2 ;
V_2 -> V_32 -> V_70 = V_70 ;
}
F_5 (tmp, crtc->dev) {
if ( V_11 -> V_32 -> V_70 )
F_50 ( V_11 -> V_32 -> V_70 ) ;
if ( V_11 -> V_32 -> V_80 )
F_51 ( V_11 -> V_32 -> V_80 ) ;
V_11 -> V_32 -> V_80 = NULL ;
}
return V_7 ;
}
void F_52 ( const struct V_82 * V_77 ,
int * V_83 , int * V_84 )
{
struct V_82 V_85 ;
F_53 ( & V_85 , V_77 ) ;
F_54 ( & V_85 , V_86 ) ;
* V_83 = V_85 . V_87 ;
* V_84 = V_85 . V_88 ;
}
int F_55 ( const struct V_1 * V_2 ,
int V_72 , int V_74 ,
const struct V_82 * V_77 ,
const struct V_79 * V_70 )
{
int V_83 , V_84 ;
F_52 ( V_77 , & V_83 , & V_84 ) ;
if ( V_2 -> V_58 &&
F_56 ( V_2 -> V_32 -> V_58 -> V_89 ) )
F_57 ( V_83 , V_84 ) ;
return F_58 ( V_72 << 16 , V_74 << 16 ,
V_83 << 16 , V_84 << 16 ,
V_70 ) ;
}
int F_59 ( struct V_5 * V_6 , void * V_60 ,
struct V_61 * V_62 )
{
struct V_35 * V_36 = & V_6 -> V_37 ;
struct V_63 * V_90 = V_60 ;
struct V_1 * V_2 ;
struct V_91 * * V_92 = NULL , * V_93 ;
struct V_79 * V_70 = NULL ;
struct V_82 * V_77 = NULL ;
struct V_3 V_4 ;
T_2 T_3 * V_94 ;
int V_7 ;
int V_95 ;
if ( ! F_40 ( V_6 , V_65 ) )
return - V_66 ;
if ( V_90 -> V_72 & 0xffff0000 || V_90 -> V_74 & 0xffff0000 )
return - V_96 ;
F_4 ( V_6 ) ;
V_2 = F_46 ( V_6 , V_90 -> V_67 ) ;
if ( ! V_2 ) {
F_60 ( L_5 , V_90 -> V_67 ) ;
V_7 = - V_68 ;
goto V_9;
}
F_60 ( L_6 , V_2 -> V_43 . V_46 , V_2 -> V_12 ) ;
if ( V_90 -> V_78 ) {
if ( V_90 -> V_71 == - 1 ) {
if ( ! V_2 -> V_32 -> V_70 ) {
F_60 ( L_7 ) ;
V_7 = - V_66 ;
goto V_9;
}
V_70 = V_2 -> V_32 -> V_70 ;
F_50 ( V_70 ) ;
} else {
V_70 = F_61 ( V_6 , V_90 -> V_71 ) ;
if ( ! V_70 ) {
F_60 ( L_8 ,
V_90 -> V_71 ) ;
V_7 = - V_68 ;
goto V_9;
}
}
V_77 = F_62 ( V_6 ) ;
if ( ! V_77 ) {
V_7 = - V_21 ;
goto V_9;
}
V_7 = F_63 ( V_77 , & V_90 -> V_77 ) ;
if ( V_7 ) {
F_60 ( L_9 ) ;
goto V_9;
}
if ( ! V_2 -> V_32 -> V_97 ) {
V_7 = F_64 ( V_2 -> V_32 ,
V_70 -> V_98 ) ;
if ( V_7 ) {
struct V_99 V_100 ;
F_60 ( L_10 ,
F_65 ( V_70 -> V_98 ,
& V_100 ) ) ;
goto V_9;
}
}
V_7 = F_55 ( V_2 , V_90 -> V_72 , V_90 -> V_74 ,
V_77 , V_70 ) ;
if ( V_7 )
goto V_9;
}
if ( V_90 -> V_101 == 0 && V_77 ) {
F_60 ( L_11 ) ;
V_7 = - V_66 ;
goto V_9;
}
if ( V_90 -> V_101 > 0 && ( ! V_77 || ! V_70 ) ) {
F_60 ( L_12 ,
V_90 -> V_101 ) ;
V_7 = - V_66 ;
goto V_9;
}
if ( V_90 -> V_101 > 0 ) {
T_4 V_102 ;
if ( V_90 -> V_101 > V_36 -> V_103 ) {
V_7 = - V_66 ;
goto V_9;
}
V_92 = F_66 ( V_90 -> V_101 ,
sizeof( struct V_91 * ) ,
V_20 ) ;
if ( ! V_92 ) {
V_7 = - V_21 ;
goto V_9;
}
for ( V_95 = 0 ; V_95 < V_90 -> V_101 ; V_95 ++ ) {
V_92 [ V_95 ] = NULL ;
V_94 = ( T_2 T_3 * ) ( unsigned long ) V_90 -> V_94 ;
if ( F_67 ( V_102 , & V_94 [ V_95 ] ) ) {
V_7 = - V_104 ;
goto V_9;
}
V_93 = F_68 ( V_6 , V_102 ) ;
if ( ! V_93 ) {
F_60 ( L_13 ,
V_102 ) ;
V_7 = - V_68 ;
goto V_9;
}
F_60 ( L_14 ,
V_93 -> V_43 . V_46 ,
V_93 -> V_12 ) ;
V_92 [ V_95 ] = V_93 ;
}
}
V_4 . V_2 = V_2 ;
V_4 . V_72 = V_90 -> V_72 ;
V_4 . V_74 = V_90 -> V_74 ;
V_4 . V_77 = V_77 ;
V_4 . V_105 = V_92 ;
V_4 . V_106 = V_90 -> V_101 ;
V_4 . V_70 = V_70 ;
V_7 = F_2 ( & V_4 ) ;
V_9:
if ( V_70 )
F_51 ( V_70 ) ;
if ( V_92 ) {
for ( V_95 = 0 ; V_95 < V_90 -> V_101 ; V_95 ++ ) {
if ( V_92 [ V_95 ] )
F_69 ( V_92 [ V_95 ] ) ;
}
}
F_19 ( V_92 ) ;
F_70 ( V_6 , V_77 ) ;
F_6 ( V_6 ) ;
return V_7 ;
}
int F_71 ( struct V_107 * V_108 ,
struct V_109 * V_110 ,
T_5 V_111 )
{
int V_7 = - V_66 ;
struct V_1 * V_2 = F_72 ( V_108 ) ;
if ( V_2 -> V_13 -> V_112 )
V_7 = V_2 -> V_13 -> V_112 ( V_2 , V_110 , V_111 ) ;
if ( ! V_7 )
F_73 ( V_108 , V_110 , V_111 ) ;
return V_7 ;
}
