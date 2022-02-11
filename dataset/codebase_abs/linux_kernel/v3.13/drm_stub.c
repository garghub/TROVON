int F_1 ( const char * V_1 , const char * V_2 , ... )
{
struct V_3 V_4 ;
T_1 args ;
int V_5 ;
va_start ( args , V_2 ) ;
V_4 . V_6 = V_2 ;
V_4 . V_7 = & args ;
V_5 = F_2 ( V_8 L_1 V_9 L_2 , V_1 , & V_4 ) ;
va_end ( args ) ;
return V_5 ;
}
void F_3 ( unsigned int V_10 ,
const char * V_11 ,
const char * V_12 ,
const char * V_2 , ... )
{
T_1 args ;
if ( V_13 & V_10 ) {
if ( V_12 )
F_2 ( V_14 L_3 , V_11 , V_12 ) ;
va_start ( args , V_2 ) ;
F_4 ( V_2 , args ) ;
va_end ( args ) ;
}
}
static int F_5 ( struct V_15 * V_16 , int type )
{
int V_17 ;
int V_18 = 0 , V_19 = 63 ;
if ( type == V_20 ) {
V_18 += 64 ;
V_19 = V_18 + 63 ;
} else if ( type == V_21 ) {
V_18 += 128 ;
V_19 = V_18 + 63 ;
}
F_6 ( & V_16 -> V_22 ) ;
V_17 = F_7 ( & V_23 , NULL , V_18 , V_19 , V_24 ) ;
F_8 ( & V_16 -> V_22 ) ;
return V_17 == - V_25 ? - V_26 : V_17 ;
}
struct V_27 * F_9 ( struct V_28 * V_29 )
{
struct V_27 * V_30 ;
V_30 = F_10 ( sizeof( * V_30 ) , V_24 ) ;
if ( ! V_30 )
return NULL ;
F_11 ( & V_30 -> V_31 ) ;
F_12 ( & V_30 -> V_32 . V_33 ) ;
F_13 ( & V_30 -> V_32 . V_34 ) ;
F_14 ( & V_30 -> V_35 , V_36 ) ;
F_15 ( & V_30 -> V_37 ) ;
V_30 -> V_29 = V_29 ;
F_16 ( & V_30 -> V_38 , & V_29 -> V_39 ) ;
return V_30 ;
}
struct V_27 * F_17 ( struct V_27 * V_30 )
{
F_18 ( & V_30 -> V_31 ) ;
return V_30 ;
}
static void F_19 ( struct V_40 * V_40 )
{
struct V_27 * V_30 = F_20 ( V_40 , struct V_27 , V_31 ) ;
struct V_41 * V_42 , * V_43 ;
struct V_15 * V_16 = V_30 -> V_29 -> V_16 ;
struct V_44 * V_45 , * V_46 ;
F_21 ( & V_30 -> V_38 ) ;
if ( V_16 -> V_47 -> V_48 )
V_16 -> V_47 -> V_48 ( V_16 , V_30 ) ;
F_22 (r_list, list_temp, &dev->maplist, head) {
if ( V_45 -> V_30 == V_30 ) {
F_23 ( V_16 , V_45 -> V_49 ) ;
V_45 = NULL ;
}
}
if ( V_30 -> V_50 ) {
F_24 ( V_30 -> V_50 ) ;
V_30 -> V_50 = NULL ;
V_30 -> V_51 = 0 ;
}
F_24 ( V_16 -> V_52 ) ;
V_16 -> V_52 = NULL ;
F_22 (pt, next, &master->magicfree, head) {
F_21 ( & V_42 -> V_38 ) ;
F_25 ( & V_30 -> V_35 , & V_42 -> V_53 ) ;
F_24 ( V_42 ) ;
}
F_26 ( & V_30 -> V_35 ) ;
F_24 ( V_30 ) ;
}
void F_27 ( struct V_27 * * V_30 )
{
F_28 ( & ( * V_30 ) -> V_31 , F_19 ) ;
* V_30 = NULL ;
}
int F_29 ( struct V_15 * V_16 , void * V_54 ,
struct V_55 * V_56 )
{
int V_17 = 0 ;
if ( V_56 -> V_57 )
return 0 ;
if ( V_56 -> V_29 -> V_30 && V_56 -> V_29 -> V_30 != V_56 -> V_30 )
return - V_26 ;
if ( ! V_56 -> V_30 )
return - V_26 ;
if ( V_56 -> V_29 -> V_30 )
return - V_26 ;
F_6 ( & V_16 -> V_22 ) ;
V_56 -> V_29 -> V_30 = F_17 ( V_56 -> V_30 ) ;
V_56 -> V_57 = 1 ;
if ( V_16 -> V_47 -> V_58 ) {
V_17 = V_16 -> V_47 -> V_58 ( V_16 , V_56 , false ) ;
if ( F_30 ( V_17 != 0 ) ) {
V_56 -> V_57 = 0 ;
F_27 ( & V_56 -> V_29 -> V_30 ) ;
}
}
F_8 ( & V_16 -> V_22 ) ;
return V_17 ;
}
int F_31 ( struct V_15 * V_16 , void * V_54 ,
struct V_55 * V_56 )
{
if ( ! V_56 -> V_57 )
return - V_26 ;
if ( ! V_56 -> V_29 -> V_30 )
return - V_26 ;
F_6 ( & V_16 -> V_22 ) ;
if ( V_16 -> V_47 -> V_59 )
V_16 -> V_47 -> V_59 ( V_16 , V_56 , false ) ;
F_27 ( & V_56 -> V_29 -> V_30 ) ;
V_56 -> V_57 = 0 ;
F_8 ( & V_16 -> V_22 ) ;
return 0 ;
}
static int F_32 ( struct V_15 * V_16 , struct V_28 * * V_29 ,
int type )
{
struct V_28 * V_60 ;
int V_17 ;
int V_61 ;
F_33 ( L_4 ) ;
V_61 = F_5 ( V_16 , type ) ;
if ( V_61 < 0 )
return V_61 ;
V_60 = F_10 ( sizeof( struct V_28 ) , V_24 ) ;
if ( ! V_60 ) {
V_17 = - V_62 ;
goto V_63;
}
V_60 -> type = type ;
V_60 -> V_64 = F_34 ( V_65 , V_61 ) ;
V_60 -> V_16 = V_16 ;
V_60 -> V_66 = V_61 ;
F_15 ( & V_60 -> V_39 ) ;
F_35 ( & V_23 , V_60 , V_61 ) ;
#if F_36 ( V_67 )
V_17 = F_37 ( V_60 , V_61 , V_68 ) ;
if ( V_17 ) {
F_38 ( L_5 ) ;
goto V_69;
}
#endif
V_17 = F_39 ( V_60 ) ;
if ( V_17 ) {
F_2 ( V_8
L_6 ) ;
goto V_70;
}
* V_29 = V_60 ;
F_33 ( L_7 , V_61 ) ;
return 0 ;
V_70:
#if F_36 ( V_67 )
F_40 ( V_60 ) ;
V_69:
#endif
F_24 ( V_60 ) ;
V_63:
F_41 ( & V_23 , V_61 ) ;
* V_29 = NULL ;
return V_17 ;
}
static void F_42 ( struct V_28 * V_29 )
{
if ( ! V_29 || ! V_29 -> V_71 )
return;
#if F_36 ( V_67 )
F_40 ( V_29 ) ;
#endif
F_43 ( V_29 ) ;
F_41 ( & V_23 , V_29 -> V_66 ) ;
}
static void F_44 ( struct V_28 * V_29 )
{
if ( ! V_29 )
return;
F_33 ( L_8 , V_29 -> V_66 ) ;
F_42 ( V_29 ) ;
F_24 ( V_29 ) ;
}
void F_45 ( struct V_15 * V_16 )
{
F_33 ( L_4 ) ;
if ( ! V_16 ) {
F_38 ( L_9 ) ;
return;
}
F_46 ( V_16 ) ;
F_47 ( V_16 ) ;
}
void F_48 ( struct V_15 * V_16 )
{
if ( F_49 ( V_16 , V_72 ) )
F_42 ( V_16 -> V_73 ) ;
if ( V_16 -> V_74 )
F_42 ( V_16 -> V_74 ) ;
F_42 ( V_16 -> V_75 ) ;
F_6 ( & V_76 ) ;
F_50 ( V_16 ) ;
if ( V_16 -> V_77 == 0 ) {
F_45 ( V_16 ) ;
}
F_8 ( & V_76 ) ;
}
struct V_15 * F_51 ( struct V_78 * V_47 ,
struct V_64 * V_79 )
{
struct V_15 * V_16 ;
int V_17 ;
V_16 = F_10 ( sizeof( * V_16 ) , V_24 ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_16 = V_79 ;
V_16 -> V_47 = V_47 ;
F_15 ( & V_16 -> V_80 ) ;
F_15 ( & V_16 -> V_81 ) ;
F_15 ( & V_16 -> V_82 ) ;
F_15 ( & V_16 -> V_83 ) ;
F_15 ( & V_16 -> V_84 ) ;
F_12 ( & V_16 -> V_85 ) ;
F_12 ( & V_16 -> V_86 ) ;
F_52 ( & V_16 -> V_22 ) ;
F_52 ( & V_16 -> V_87 ) ;
if ( F_14 ( & V_16 -> V_88 , 12 ) )
goto V_89;
V_17 = F_53 ( V_16 ) ;
if ( V_17 ) {
F_38 ( L_10 ) ;
goto V_90;
}
if ( V_47 -> V_91 & V_92 ) {
V_17 = F_54 ( V_16 ) ;
if ( V_17 ) {
F_38 ( L_11 ) ;
goto V_93;
}
}
return V_16 ;
V_93:
F_55 ( V_16 ) ;
V_90:
F_26 ( & V_16 -> V_88 ) ;
V_89:
F_24 ( V_16 ) ;
return NULL ;
}
void F_47 ( struct V_15 * V_16 )
{
F_44 ( V_16 -> V_73 ) ;
F_44 ( V_16 -> V_74 ) ;
F_44 ( V_16 -> V_75 ) ;
if ( V_16 -> V_47 -> V_91 & V_92 )
F_56 ( V_16 ) ;
F_55 ( V_16 ) ;
F_26 ( & V_16 -> V_88 ) ;
F_24 ( V_16 -> V_52 ) ;
F_24 ( V_16 ) ;
}
int F_57 ( struct V_15 * V_16 , unsigned long V_94 )
{
int V_17 ;
F_6 ( & V_76 ) ;
if ( V_16 -> V_47 -> V_95 -> V_96 ) {
V_17 = V_16 -> V_47 -> V_95 -> V_96 ( V_16 ) ;
if ( V_17 )
goto V_97;
}
if ( F_49 ( V_16 , V_72 ) ) {
V_17 = F_32 ( V_16 , & V_16 -> V_73 , V_20 ) ;
if ( V_17 )
goto V_98;
}
if ( F_49 ( V_16 , V_99 ) && V_100 ) {
V_17 = F_32 ( V_16 , & V_16 -> V_74 , V_21 ) ;
if ( V_17 )
goto V_101;
}
V_17 = F_32 ( V_16 , & V_16 -> V_75 , V_102 ) ;
if ( V_17 )
goto V_103;
if ( V_16 -> V_47 -> V_104 ) {
V_17 = V_16 -> V_47 -> V_104 ( V_16 , V_94 ) ;
if ( V_17 )
goto V_105;
}
if ( F_49 ( V_16 , V_72 ) ) {
V_17 = F_58 ( V_16 ,
& V_16 -> V_75 -> V_106 ) ;
if ( V_17 )
goto V_107;
}
F_16 ( & V_16 -> V_108 , & V_16 -> V_47 -> V_109 ) ;
V_17 = 0 ;
goto V_97;
V_107:
if ( V_16 -> V_47 -> V_110 )
V_16 -> V_47 -> V_110 ( V_16 ) ;
V_105:
F_42 ( V_16 -> V_75 ) ;
V_103:
F_42 ( V_16 -> V_74 ) ;
V_101:
F_42 ( V_16 -> V_73 ) ;
V_98:
if ( V_16 -> V_47 -> V_95 -> V_111 )
V_16 -> V_47 -> V_95 -> V_111 ( V_16 ) ;
V_97:
F_8 ( & V_76 ) ;
return V_17 ;
}
void F_46 ( struct V_15 * V_16 )
{
struct V_44 * V_45 , * V_46 ;
F_59 ( V_16 ) ;
if ( V_16 -> V_47 -> V_110 )
V_16 -> V_47 -> V_110 ( V_16 ) ;
if ( V_16 -> V_47 -> V_95 -> V_111 )
V_16 -> V_47 -> V_95 -> V_111 ( V_16 ) ;
F_60 ( V_16 ) ;
F_22 (r_list, list_temp, &dev->maplist, head)
F_61 ( V_16 , V_45 -> V_49 ) ;
F_42 ( V_16 -> V_73 ) ;
F_42 ( V_16 -> V_74 ) ;
F_42 ( V_16 -> V_75 ) ;
F_21 ( & V_16 -> V_108 ) ;
}
