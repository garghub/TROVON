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
V_19 = V_18 + 127 ;
} else if ( type == V_21 ) {
V_18 += 128 ;
V_19 = V_18 + 255 ;
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
int V_17 ;
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
return 0 ;
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
int F_32 ( struct V_15 * V_16 ,
const struct V_60 * V_61 ,
struct V_62 * V_47 )
{
int V_63 ;
F_15 ( & V_16 -> V_64 ) ;
F_15 ( & V_16 -> V_65 ) ;
F_15 ( & V_16 -> V_66 ) ;
F_15 ( & V_16 -> V_67 ) ;
F_15 ( & V_16 -> V_68 ) ;
F_12 ( & V_16 -> V_69 ) ;
F_12 ( & V_16 -> V_70 ) ;
F_33 ( & V_16 -> V_22 ) ;
F_33 ( & V_16 -> V_71 ) ;
if ( F_14 ( & V_16 -> V_72 , 12 ) ) {
return - V_73 ;
}
V_16 -> V_74 = 6 ;
V_16 -> V_75 [ 0 ] = V_76 ;
V_16 -> V_75 [ 1 ] = V_77 ;
V_16 -> V_75 [ 2 ] = V_78 ;
V_16 -> V_75 [ 3 ] = V_79 ;
V_16 -> V_75 [ 4 ] = V_80 ;
V_16 -> V_75 [ 5 ] = V_81 ;
V_16 -> V_47 = V_47 ;
if ( V_16 -> V_47 -> V_82 -> V_83 ) {
V_63 = V_16 -> V_47 -> V_82 -> V_83 ( V_16 ) ;
if ( V_63 )
goto V_84;
}
V_63 = F_34 ( V_16 ) ;
if ( V_63 ) {
F_35 ( L_4 ) ;
goto V_84;
}
if ( V_47 -> V_85 & V_86 ) {
V_63 = F_36 ( V_16 ) ;
if ( V_63 ) {
F_35 ( L_5
L_6 ) ;
goto V_84;
}
}
return 0 ;
V_84:
F_37 ( V_16 ) ;
return V_63 ;
}
int F_38 ( struct V_15 * V_16 , struct V_28 * * V_29 , int type )
{
struct V_28 * V_87 ;
int V_17 ;
int V_88 ;
F_39 ( L_7 ) ;
V_88 = F_5 ( V_16 , type ) ;
if ( V_88 < 0 )
return V_88 ;
V_87 = F_10 ( sizeof( struct V_28 ) , V_24 ) ;
if ( ! V_87 ) {
V_17 = - V_73 ;
goto V_89;
}
V_87 -> type = type ;
V_87 -> V_90 = F_40 ( V_91 , V_88 ) ;
V_87 -> V_16 = V_16 ;
V_87 -> V_92 = V_88 ;
F_15 ( & V_87 -> V_39 ) ;
F_41 ( & V_23 , V_87 , V_88 ) ;
if ( type == V_93 ) {
V_17 = F_42 ( V_87 , V_94 ) ;
if ( V_17 ) {
F_35 ( L_8 ) ;
goto V_95;
}
} else
V_87 -> V_96 = NULL ;
#if F_43 ( V_97 )
V_17 = F_44 ( V_87 , V_88 , V_98 ) ;
if ( V_17 ) {
F_35 ( L_9 ) ;
goto V_99;
}
#endif
V_17 = F_45 ( V_87 ) ;
if ( V_17 ) {
F_2 ( V_8
L_10 ) ;
goto V_99;
}
* V_29 = V_87 ;
F_39 ( L_11 , V_88 ) ;
return 0 ;
V_99:
if ( V_87 -> type == V_93 )
F_46 ( V_87 , V_94 ) ;
V_95:
F_24 ( V_87 ) ;
V_89:
F_47 ( & V_23 , V_88 ) ;
* V_29 = NULL ;
return V_17 ;
}
int F_48 ( struct V_28 * * V_100 )
{
struct V_28 * V_29 = * V_100 ;
F_39 ( L_12 , V_29 -> V_92 ) ;
if ( V_29 -> type == V_93 )
F_46 ( V_29 , V_94 ) ;
#if F_43 ( V_97 )
F_49 ( V_29 ) ;
#endif
F_50 ( V_29 ) ;
F_47 ( & V_23 , V_29 -> V_92 ) ;
F_24 ( V_29 ) ;
* V_100 = NULL ;
return 0 ;
}
static void F_51 ( struct V_28 * V_29 )
{
F_50 ( V_29 ) ;
}
void F_52 ( struct V_15 * V_16 )
{
struct V_62 * V_47 ;
struct V_44 * V_45 , * V_46 ;
F_39 ( L_7 ) ;
if ( ! V_16 ) {
F_35 ( L_13 ) ;
return;
}
V_47 = V_16 -> V_47 ;
F_37 ( V_16 ) ;
if ( F_53 ( V_16 ) && F_54 ( V_16 ) &&
V_16 -> V_101 && V_16 -> V_101 -> V_102 >= 0 ) {
int V_103 ;
V_103 = F_55 ( V_16 -> V_101 -> V_102 ,
V_16 -> V_101 -> V_104 . V_105 ,
V_16 -> V_101 -> V_104 . V_106 * 1024 * 1024 ) ;
F_39 ( L_14 , V_103 ) ;
}
if ( V_16 -> V_47 -> V_107 )
V_16 -> V_47 -> V_107 ( V_16 ) ;
if ( F_54 ( V_16 ) && V_16 -> V_101 ) {
F_24 ( V_16 -> V_101 ) ;
V_16 -> V_101 = NULL ;
}
F_56 ( V_16 ) ;
F_22 (r_list, list_temp, &dev->maplist, head)
F_57 ( V_16 , V_45 -> V_49 ) ;
F_26 ( & V_16 -> V_72 ) ;
F_58 ( V_16 ) ;
if ( F_59 ( V_16 , V_108 ) )
F_48 ( & V_16 -> V_109 ) ;
if ( V_47 -> V_85 & V_86 )
F_60 ( V_16 ) ;
F_48 ( & V_16 -> V_110 ) ;
F_21 ( & V_16 -> V_111 ) ;
F_24 ( V_16 -> V_52 ) ;
F_24 ( V_16 ) ;
}
void F_61 ( struct V_15 * V_16 )
{
if ( F_59 ( V_16 , V_108 ) )
F_51 ( V_16 -> V_109 ) ;
F_51 ( V_16 -> V_110 ) ;
F_6 ( & V_112 ) ;
F_62 ( V_16 ) ;
if ( V_16 -> V_113 == 0 ) {
F_52 ( V_16 ) ;
}
F_8 ( & V_112 ) ;
}
