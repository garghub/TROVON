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
int V_18 ;
int V_19 = 0 , V_20 = 63 ;
if ( type == V_21 ) {
V_19 += 64 ;
V_20 = V_19 + 127 ;
} else if ( type == V_22 ) {
V_19 += 128 ;
V_20 = V_19 + 255 ;
}
V_23:
if ( F_6 ( & V_24 , V_25 ) == 0 ) {
F_7 ( L_4 ) ;
return - V_26 ;
}
F_8 ( & V_16 -> V_27 ) ;
V_18 = F_9 ( & V_24 , NULL ,
V_19 , & V_17 ) ;
F_10 ( & V_16 -> V_27 ) ;
if ( V_18 == - V_28 )
goto V_23;
else if ( V_18 )
return V_18 ;
if ( V_17 >= V_20 ) {
F_11 ( & V_24 , V_17 ) ;
return - V_29 ;
}
return V_17 ;
}
struct V_30 * F_12 ( struct V_31 * V_32 )
{
struct V_30 * V_33 ;
V_33 = F_13 ( sizeof( * V_33 ) , V_25 ) ;
if ( ! V_33 )
return NULL ;
F_14 ( & V_33 -> V_34 ) ;
F_15 ( & V_33 -> V_35 . V_36 ) ;
F_16 ( & V_33 -> V_35 . V_37 ) ;
F_17 ( & V_33 -> V_38 , V_39 ) ;
F_18 ( & V_33 -> V_40 ) ;
V_33 -> V_32 = V_32 ;
F_19 ( & V_33 -> V_41 , & V_32 -> V_42 ) ;
return V_33 ;
}
struct V_30 * F_20 ( struct V_30 * V_33 )
{
F_21 ( & V_33 -> V_34 ) ;
return V_33 ;
}
static void F_22 ( struct V_43 * V_43 )
{
struct V_30 * V_33 = F_23 ( V_43 , struct V_30 , V_34 ) ;
struct V_44 * V_45 , * V_46 ;
struct V_15 * V_16 = V_33 -> V_32 -> V_16 ;
struct V_47 * V_48 , * V_49 ;
F_24 ( & V_33 -> V_41 ) ;
if ( V_16 -> V_50 -> V_51 )
V_16 -> V_50 -> V_51 ( V_16 , V_33 ) ;
F_25 (r_list, list_temp, &dev->maplist, head) {
if ( V_48 -> V_33 == V_33 ) {
F_26 ( V_16 , V_48 -> V_52 ) ;
V_48 = NULL ;
}
}
if ( V_33 -> V_53 ) {
F_27 ( V_33 -> V_53 ) ;
V_33 -> V_53 = NULL ;
V_33 -> V_54 = 0 ;
}
F_27 ( V_16 -> V_55 ) ;
V_16 -> V_55 = NULL ;
F_25 (pt, next, &master->magicfree, head) {
F_24 ( & V_45 -> V_41 ) ;
F_28 ( & V_33 -> V_38 , & V_45 -> V_56 ) ;
F_27 ( V_45 ) ;
}
F_29 ( & V_33 -> V_38 ) ;
F_27 ( V_33 ) ;
}
void F_30 ( struct V_30 * * V_33 )
{
F_31 ( & ( * V_33 ) -> V_34 , F_22 ) ;
* V_33 = NULL ;
}
int F_32 ( struct V_15 * V_16 , void * V_57 ,
struct V_58 * V_59 )
{
int V_18 ;
if ( V_59 -> V_60 )
return 0 ;
if ( V_59 -> V_32 -> V_33 && V_59 -> V_32 -> V_33 != V_59 -> V_33 )
return - V_29 ;
if ( ! V_59 -> V_33 )
return - V_29 ;
if ( V_59 -> V_32 -> V_33 )
return - V_29 ;
F_8 ( & V_16 -> V_27 ) ;
V_59 -> V_32 -> V_33 = F_20 ( V_59 -> V_33 ) ;
V_59 -> V_60 = 1 ;
if ( V_16 -> V_50 -> V_61 ) {
V_18 = V_16 -> V_50 -> V_61 ( V_16 , V_59 , false ) ;
if ( F_33 ( V_18 != 0 ) ) {
V_59 -> V_60 = 0 ;
F_30 ( & V_59 -> V_32 -> V_33 ) ;
}
}
F_10 ( & V_16 -> V_27 ) ;
return 0 ;
}
int F_34 ( struct V_15 * V_16 , void * V_57 ,
struct V_58 * V_59 )
{
if ( ! V_59 -> V_60 )
return - V_29 ;
if ( ! V_59 -> V_32 -> V_33 )
return - V_29 ;
F_8 ( & V_16 -> V_27 ) ;
if ( V_16 -> V_50 -> V_62 )
V_16 -> V_50 -> V_62 ( V_16 , V_59 , false ) ;
F_30 ( & V_59 -> V_32 -> V_33 ) ;
V_59 -> V_60 = 0 ;
F_10 ( & V_16 -> V_27 ) ;
return 0 ;
}
int F_35 ( struct V_15 * V_16 ,
const struct V_63 * V_64 ,
struct V_65 * V_50 )
{
int V_66 ;
F_18 ( & V_16 -> V_67 ) ;
F_18 ( & V_16 -> V_68 ) ;
F_18 ( & V_16 -> V_69 ) ;
F_18 ( & V_16 -> V_70 ) ;
F_18 ( & V_16 -> V_71 ) ;
F_15 ( & V_16 -> V_72 ) ;
F_15 ( & V_16 -> V_73 ) ;
F_36 ( & V_16 -> V_27 ) ;
F_36 ( & V_16 -> V_74 ) ;
if ( F_17 ( & V_16 -> V_75 , 12 ) ) {
return - V_26 ;
}
V_16 -> V_76 = 6 ;
V_16 -> V_77 [ 0 ] = V_78 ;
V_16 -> V_77 [ 1 ] = V_79 ;
V_16 -> V_77 [ 2 ] = V_80 ;
V_16 -> V_77 [ 3 ] = V_81 ;
V_16 -> V_77 [ 4 ] = V_82 ;
V_16 -> V_77 [ 5 ] = V_83 ;
V_16 -> V_50 = V_50 ;
if ( V_16 -> V_50 -> V_84 -> V_85 ) {
V_66 = V_16 -> V_50 -> V_84 -> V_85 ( V_16 ) ;
if ( V_66 )
goto V_86;
}
V_66 = F_37 ( V_16 ) ;
if ( V_66 ) {
F_7 ( L_5 ) ;
goto V_86;
}
if ( V_50 -> V_87 & V_88 ) {
V_66 = F_38 ( V_16 ) ;
if ( V_66 ) {
F_7 ( L_6
L_7 ) ;
goto V_86;
}
}
return 0 ;
V_86:
F_39 ( V_16 ) ;
return V_66 ;
}
int F_40 ( struct V_15 * V_16 , struct V_31 * * V_32 , int type )
{
struct V_31 * V_89 ;
int V_18 ;
int V_90 ;
F_41 ( L_8 ) ;
V_90 = F_5 ( V_16 , type ) ;
if ( V_90 < 0 )
return V_90 ;
V_89 = F_13 ( sizeof( struct V_31 ) , V_25 ) ;
if ( ! V_89 ) {
V_18 = - V_26 ;
goto V_91;
}
V_89 -> type = type ;
V_89 -> V_92 = F_42 ( V_93 , V_90 ) ;
V_89 -> V_16 = V_16 ;
V_89 -> V_94 = V_90 ;
F_18 ( & V_89 -> V_42 ) ;
F_43 ( & V_24 , V_89 , V_90 ) ;
if ( type == V_95 ) {
V_18 = F_44 ( V_89 , V_90 , V_96 ) ;
if ( V_18 ) {
F_7 ( L_9 ) ;
goto V_97;
}
} else
V_89 -> V_98 = NULL ;
#if F_45 ( V_99 )
V_18 = F_46 ( V_89 , V_90 , V_100 ) ;
if ( V_18 ) {
F_7 ( L_10 ) ;
goto V_101;
}
#endif
V_18 = F_47 ( V_89 ) ;
if ( V_18 ) {
F_2 ( V_8
L_11 ) ;
goto V_101;
}
* V_32 = V_89 ;
F_41 ( L_12 , V_90 ) ;
return 0 ;
V_101:
if ( V_89 -> type == V_95 )
F_48 ( V_89 , V_96 ) ;
V_97:
F_27 ( V_89 ) ;
V_91:
F_11 ( & V_24 , V_90 ) ;
* V_32 = NULL ;
return V_18 ;
}
int F_49 ( struct V_31 * * V_102 )
{
struct V_31 * V_32 = * V_102 ;
F_41 ( L_13 , V_32 -> V_94 ) ;
if ( V_32 -> type == V_95 )
F_48 ( V_32 , V_96 ) ;
#if F_45 ( V_99 )
F_50 ( V_32 ) ;
#endif
F_51 ( V_32 ) ;
F_11 ( & V_24 , V_32 -> V_94 ) ;
F_27 ( V_32 ) ;
* V_102 = NULL ;
return 0 ;
}
static void F_52 ( struct V_31 * V_32 )
{
F_51 ( V_32 ) ;
}
void F_53 ( struct V_15 * V_16 )
{
struct V_65 * V_50 ;
struct V_47 * V_48 , * V_49 ;
F_41 ( L_8 ) ;
if ( ! V_16 ) {
F_7 ( L_14 ) ;
return;
}
V_50 = V_16 -> V_50 ;
F_39 ( V_16 ) ;
if ( F_54 ( V_16 ) && F_55 ( V_16 ) &&
V_16 -> V_103 && V_16 -> V_103 -> V_104 >= 0 ) {
int V_105 ;
V_105 = F_56 ( V_16 -> V_103 -> V_104 ,
V_16 -> V_103 -> V_106 . V_107 ,
V_16 -> V_103 -> V_106 . V_108 * 1024 * 1024 ) ;
F_41 ( L_15 , V_105 ) ;
}
if ( V_16 -> V_50 -> V_109 )
V_16 -> V_50 -> V_109 ( V_16 ) ;
if ( F_55 ( V_16 ) && V_16 -> V_103 ) {
F_27 ( V_16 -> V_103 ) ;
V_16 -> V_103 = NULL ;
}
F_57 ( V_16 ) ;
F_25 (r_list, list_temp, &dev->maplist, head)
F_58 ( V_16 , V_48 -> V_52 ) ;
F_29 ( & V_16 -> V_75 ) ;
F_59 ( V_16 ) ;
if ( F_60 ( V_16 , V_110 ) )
F_49 ( & V_16 -> V_111 ) ;
if ( V_50 -> V_87 & V_88 )
F_61 ( V_16 ) ;
F_49 ( & V_16 -> V_112 ) ;
F_24 ( & V_16 -> V_113 ) ;
F_27 ( V_16 -> V_55 ) ;
F_27 ( V_16 ) ;
}
void F_62 ( struct V_15 * V_16 )
{
if ( F_60 ( V_16 , V_110 ) )
F_52 ( V_16 -> V_111 ) ;
F_52 ( V_16 -> V_112 ) ;
F_8 ( & V_114 ) ;
F_63 ( V_16 ) ;
if ( V_16 -> V_115 == 0 ) {
F_53 ( V_16 ) ;
}
F_10 ( & V_114 ) ;
}
