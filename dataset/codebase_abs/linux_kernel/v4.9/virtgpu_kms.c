static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 =
F_2 ( V_2 , struct V_3 ,
V_5 ) ;
T_1 V_6 , V_7 = 0 ;
F_3 ( V_4 -> V_8 , struct V_9 ,
V_6 , & V_6 ) ;
if ( V_6 & V_10 ) {
F_4 ( V_4 ) ;
F_5 ( V_4 -> V_11 ) ;
V_7 |= V_10 ;
}
F_6 ( V_4 -> V_8 , struct V_9 ,
V_7 , & V_7 ) ;
}
static void F_7 ( struct V_3 * V_4 ,
T_2 * V_12 )
{
int V_13 ;
F_8 ( V_14 ) ;
F_9 ( & V_4 -> V_15 ) ;
V_13 = F_10 ( & V_4 -> V_16 , NULL , 1 , 0 , 0 ) ;
F_11 ( & V_4 -> V_15 ) ;
F_12 () ;
* V_12 = V_13 ;
}
static void F_13 ( struct V_3 * V_4 , T_2 V_17 )
{
F_9 ( & V_4 -> V_15 ) ;
F_14 ( & V_4 -> V_16 , V_17 ) ;
F_11 ( & V_4 -> V_15 ) ;
}
static void F_15 ( struct V_3 * V_4 ,
T_2 V_18 , const char * V_19 ,
T_2 * V_20 )
{
F_7 ( V_4 , V_20 ) ;
F_16 ( V_4 , * V_20 , V_18 , V_19 ) ;
}
static void F_17 ( struct V_3 * V_4 ,
T_2 V_20 )
{
F_18 ( V_4 , V_20 ) ;
F_13 ( V_4 , V_20 ) ;
}
static void F_19 ( struct V_21 * V_22 ,
void (* F_20)( struct V_1 * V_2 ) )
{
F_21 ( & V_22 -> V_23 ) ;
F_22 ( & V_22 -> V_24 ) ;
F_23 ( & V_22 -> V_25 , F_20 ) ;
}
static void F_24 ( struct V_3 * V_4 ,
int V_26 )
{
int V_27 , V_28 ;
V_4 -> V_29 = F_25 ( V_26 ,
sizeof( struct V_30 ) ,
V_14 ) ;
if ( ! V_4 -> V_29 ) {
F_26 ( L_1 ) ;
return;
}
for ( V_27 = 0 ; V_27 < V_26 ; V_27 ++ ) {
F_27 ( V_4 , V_27 ) ;
V_28 = F_28 ( V_4 -> V_31 ,
V_4 -> V_29 [ V_27 ] . V_17 > 0 , 5 * V_32 ) ;
if ( V_28 == 0 ) {
F_26 ( L_2 , V_27 ) ;
F_29 ( V_4 -> V_29 ) ;
V_4 -> V_29 = NULL ;
return;
}
F_30 ( L_3 ,
V_27 , V_4 -> V_29 [ V_27 ] . V_17 ,
V_4 -> V_29 [ V_27 ] . V_33 ,
V_4 -> V_29 [ V_27 ] . V_34 ) ;
}
V_4 -> V_26 = V_26 ;
}
int F_31 ( struct V_35 * V_36 , unsigned long V_37 )
{
static T_3 * V_38 [] = {
V_39 , V_40
} ;
static const char * const V_41 [] = { L_4 , L_5 } ;
struct V_3 * V_4 ;
struct V_42 * V_43 [ 2 ] ;
T_1 V_44 , V_26 ;
int V_28 ;
if ( ! F_32 ( V_36 -> V_45 , V_46 ) )
return - V_47 ;
V_4 = F_33 ( sizeof( struct V_3 ) , V_14 ) ;
if ( ! V_4 )
return - V_48 ;
V_4 -> V_11 = V_36 ;
V_36 -> V_49 = V_4 ;
V_4 -> V_8 = V_36 -> V_45 ;
V_4 -> V_36 = V_36 -> V_36 ;
F_21 ( & V_4 -> V_50 ) ;
F_21 ( & V_4 -> V_15 ) ;
F_34 ( & V_4 -> V_16 ) ;
F_21 ( & V_4 -> V_51 ) ;
F_34 ( & V_4 -> V_52 ) ;
F_22 ( & V_4 -> V_31 ) ;
F_19 ( & V_4 -> V_53 , V_54 ) ;
F_19 ( & V_4 -> V_55 , V_56 ) ;
V_4 -> V_57 . V_58 = F_35 ( 1 ) ;
F_21 ( & V_4 -> V_57 . V_59 ) ;
F_36 ( & V_4 -> V_57 . V_60 ) ;
F_36 ( & V_4 -> V_61 ) ;
F_23 ( & V_4 -> V_5 ,
F_1 ) ;
if ( F_32 ( V_4 -> V_8 , V_62 ) )
V_4 -> V_63 = true ;
F_30 ( L_6 ,
V_4 -> V_63 ? L_7 : L_8 ) ;
V_28 = V_4 -> V_8 -> V_64 -> V_65 ( V_4 -> V_8 , 2 , V_43 ,
V_38 , V_41 ) ;
if ( V_28 ) {
F_26 ( L_9 ) ;
goto V_66;
}
V_4 -> V_53 . V_67 = V_43 [ 0 ] ;
V_4 -> V_55 . V_67 = V_43 [ 1 ] ;
V_28 = F_37 ( V_4 ) ;
if ( V_28 ) {
F_26 ( L_10 ) ;
goto V_68;
}
V_28 = F_38 ( V_4 ) ;
if ( V_28 ) {
F_26 ( L_11 , V_28 ) ;
goto V_69;
}
F_3 ( V_4 -> V_8 , struct V_9 ,
V_44 , & V_44 ) ;
V_4 -> V_44 = F_39 ( T_2 , V_44 ,
V_70 ) ;
if ( ! V_4 -> V_44 ) {
F_26 ( L_12 ) ;
V_28 = - V_71 ;
goto V_72;
}
F_30 ( L_13 , V_44 ) ;
F_3 ( V_4 -> V_8 , struct V_9 ,
V_26 , & V_26 ) ;
F_30 ( L_14 , V_26 ) ;
V_28 = F_40 ( V_4 ) ;
if ( V_28 )
goto V_73;
F_41 ( V_4 -> V_8 ) ;
V_4 -> V_74 = true ;
if ( V_26 )
F_24 ( V_4 , V_26 ) ;
F_4 ( V_4 ) ;
F_28 ( V_4 -> V_31 , ! V_4 -> V_75 ,
5 * V_32 ) ;
if ( V_76 )
F_42 ( V_4 ) ;
return 0 ;
V_73:
V_72:
F_43 ( V_4 ) ;
V_69:
F_44 ( V_4 ) ;
V_68:
V_4 -> V_8 -> V_64 -> V_77 ( V_4 -> V_8 ) ;
V_66:
F_29 ( V_4 ) ;
return V_28 ;
}
static void F_45 ( struct V_3 * V_4 )
{
struct V_78 * V_79 , * V_80 ;
F_46 (cache_ent, tmp, &vgdev->cap_cache, head) {
F_29 ( V_79 -> V_81 ) ;
F_29 ( V_79 ) ;
}
}
int F_47 ( struct V_35 * V_36 )
{
struct V_3 * V_4 = V_36 -> V_49 ;
V_4 -> V_74 = false ;
F_48 ( & V_4 -> V_53 . V_25 ) ;
F_48 ( & V_4 -> V_55 . V_25 ) ;
F_48 ( & V_4 -> V_5 ) ;
V_4 -> V_8 -> V_64 -> V_77 ( V_4 -> V_8 ) ;
F_49 ( V_4 ) ;
F_43 ( V_4 ) ;
F_44 ( V_4 ) ;
F_45 ( V_4 ) ;
F_29 ( V_4 -> V_29 ) ;
F_29 ( V_4 ) ;
return 0 ;
}
int F_50 ( struct V_35 * V_36 , struct V_82 * V_83 )
{
struct V_3 * V_4 = V_36 -> V_49 ;
struct V_84 * V_85 ;
T_2 V_17 ;
char V_86 [ 64 ] , V_87 [ V_88 ] ;
if ( ! V_4 -> V_63 )
return 0 ;
F_51 ( V_87 , V_89 ) ;
snprintf ( V_86 , sizeof( V_86 ) , L_15 , V_87 ) ;
V_86 [ 63 ] = 0 ;
V_85 = F_33 ( sizeof( * V_85 ) , V_14 ) ;
if ( ! V_85 )
return - V_48 ;
F_15 ( V_4 , strlen ( V_86 ) , V_86 , & V_17 ) ;
V_85 -> V_20 = V_17 ;
V_83 -> V_90 = V_85 ;
return 0 ;
}
void F_52 ( struct V_35 * V_36 , struct V_82 * V_83 )
{
struct V_3 * V_4 = V_36 -> V_49 ;
struct V_84 * V_85 ;
if ( ! V_4 -> V_63 )
return;
V_85 = V_83 -> V_90 ;
F_17 ( V_4 , V_85 -> V_20 ) ;
F_29 ( V_85 ) ;
V_83 -> V_90 = NULL ;
}
