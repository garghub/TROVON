static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 type , unsigned int V_6 )
{
struct V_7 V_8 ;
int V_9 ;
union V_10 V_11 ;
F_2 ( ! V_2 || ! V_4 ) ;
F_2 ( type != V_12 && type != V_13 ) ;
F_3 ( L_1 ,
V_14 , V_13 , V_6 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_15 = V_16 ;
V_11 . type = V_17 ;
V_11 . V_18 |= V_19 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_20 = V_11 . V_18 ;
switch ( type ) {
case V_12 :
case V_13 :
V_2 -> V_21 = V_4 -> V_22 -> V_23 . V_24 ( V_4 -> V_22 ,
V_25 ) ;
break;
default:
F_4 () ;
break;
}
if ( V_2 -> V_21 == NULL )
return false ;
V_8 . V_26 = F_5 ( V_4 , & V_8 . V_27 ) ;
if ( V_8 . V_26 == NULL ) {
F_6 ( L_2 ) ;
goto V_28;
}
V_9 = F_7 ( V_4 , V_6 , & V_2 -> V_29 ) ;
if ( V_9 != 0 ) {
F_6 ( L_3 , V_6 ) ;
goto V_30;
}
V_2 -> V_31 = V_2 -> V_29 -> V_32 ;
V_2 -> V_33 = V_2 -> V_29 -> V_34 ;
V_9 = V_2 -> V_35 . F_1 ( V_2 , V_4 , type , V_6 ) ;
if ( V_9 == false )
goto V_36;
V_9 = F_7 ( V_4 , sizeof( * V_2 -> V_37 ) ,
& V_2 -> V_38 ) ;
if ( V_9 != 0 )
goto V_39;
V_2 -> V_37 = V_2 -> V_38 -> V_32 ;
V_2 -> V_40 = V_2 -> V_38 -> V_34 ;
V_9 = F_7 ( V_4 , sizeof( * V_2 -> V_41 ) ,
& V_2 -> V_42 ) ;
if ( V_9 != 0 )
goto V_43;
V_2 -> V_41 = V_2 -> V_42 -> V_32 ;
V_2 -> V_44 = V_2 -> V_42 -> V_34 ;
memset ( V_2 -> V_31 , 0 , V_6 ) ;
memset ( V_2 -> V_37 , 0 , sizeof( * V_2 -> V_37 ) ) ;
memset ( V_2 -> V_41 , 0 , sizeof( * V_2 -> V_41 ) ) ;
V_8 . V_6 = V_6 ;
V_8 . V_45 = false ;
V_8 . V_46 = 1 ;
V_8 . V_47 = 100 ;
V_8 . type = type ;
V_8 . V_48 = 0 ;
V_8 . V_49 = V_2 -> V_33 ;
V_8 . V_50 = ( V_51 * ) V_2 -> V_40 ;
V_8 . V_52 = ( V_51 * ) V_2 -> V_44 ;
V_8 . V_53 = V_2 -> V_54 ;
V_8 . V_55 = V_56 ;
if ( F_8 ( & V_2 -> V_57 , & V_8 ) != 0 )
goto V_58;
V_2 -> V_57 -> V_59 = V_4 ;
V_2 -> V_57 -> V_60 = F_9 ( V_61 ) ;
V_9 = V_2 -> V_21 -> V_62 ( V_2 -> V_21 , & V_2 -> V_57 -> V_21 ,
& V_2 -> V_57 -> V_63 ,
& V_2 -> V_57 -> V_64 ,
& V_2 -> V_57 -> V_65 ) ;
if ( V_9 != 0 )
goto V_66;
if ( type == V_13 ) {
F_3 ( L_4 ) ;
V_2 -> V_57 -> V_67 = V_68 ;
V_2 -> V_57 -> V_57 = V_69 ;
V_2 -> V_21 -> V_70 ( V_2 -> V_21 , V_2 -> V_57 -> V_21 , V_2 -> V_57 -> V_67 ,
V_2 -> V_57 -> V_57 , NULL ) ;
} else {
V_9 = F_7 ( V_4 , sizeof( V_51 ) ,
& V_2 -> V_71 ) ;
if ( V_9 != 0 )
goto V_72;
V_2 -> V_73 = V_2 -> V_71 -> V_32 ;
V_2 -> V_74 = V_2 -> V_71 -> V_34 ;
}
F_10 ( V_2 -> V_57 ) ;
return true ;
V_72:
V_66:
F_11 ( V_2 -> V_57 ) ;
V_58:
F_12 ( V_4 , V_2 -> V_42 ) ;
V_43:
F_12 ( V_4 , V_2 -> V_38 ) ;
V_39:
F_12 ( V_4 , V_2 -> V_75 ) ;
V_36:
F_12 ( V_4 , V_2 -> V_29 ) ;
V_30:
F_13 ( V_4 , V_8 . V_26 ) ;
V_28:
return false ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
if ( V_2 -> V_57 -> V_65 . type == V_13 )
V_2 -> V_21 -> V_76 ( V_2 -> V_21 ,
NULL ,
false ,
V_77 ,
V_2 -> V_57 -> V_67 ,
V_2 -> V_57 -> V_57 ) ;
else if ( V_2 -> V_57 -> V_65 . type == V_12 )
F_12 ( V_2 -> V_4 , V_2 -> V_71 ) ;
V_2 -> V_21 -> V_78 ( V_2 -> V_21 , V_2 -> V_57 -> V_21 , V_2 -> V_57 -> V_63 ) ;
F_12 ( V_2 -> V_4 , V_2 -> V_38 ) ;
F_12 ( V_2 -> V_4 , V_2 -> V_42 ) ;
V_2 -> V_35 . F_14 ( V_2 ) ;
F_12 ( V_2 -> V_4 , V_2 -> V_29 ) ;
F_13 ( V_2 -> V_4 ,
V_2 -> V_57 -> V_65 . V_26 ) ;
F_11 ( V_2 -> V_57 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
T_1 V_79 , unsigned int * * V_80 )
{
T_1 V_81 ;
T_1 V_82 ;
V_51 V_83 , V_84 ;
unsigned int * V_49 ;
F_2 ( ! V_2 || ! V_80 ) ;
V_84 = * V_2 -> V_37 ;
V_83 = * V_2 -> V_41 ;
V_49 = ( unsigned int * ) V_2 -> V_31 ;
V_82 = V_2 -> V_57 -> V_65 . V_6 / sizeof( V_51 ) ;
F_3 ( L_5 , V_84 ) ;
F_3 ( L_6 , V_83 ) ;
F_3 ( L_7 , V_49 ) ;
V_81 = ( V_84 - 1 - V_83 + V_82 ) %
V_82 ;
if ( V_79 >= V_82 ||
V_79 >= V_81 ) {
* V_80 = NULL ;
return - V_85 ;
}
if ( V_83 + V_79 >= V_82 ) {
while ( V_83 > 0 ) {
V_49 [ V_83 ] = V_2 -> V_20 ;
V_83 = ( V_83 + 1 ) % V_82 ;
}
}
* V_80 = & V_49 [ V_83 ] ;
V_2 -> V_86 = V_83 + V_79 ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
#ifdef F_17
int V_87 ;
#endif
F_2 ( ! V_2 ) ;
#ifdef F_17
for ( V_87 = * V_2 -> V_41 ; V_87 < V_2 -> V_86 ; V_87 ++ ) {
F_3 ( L_8 , V_2 -> V_31 [ V_87 ] ) ;
if ( V_87 % 15 == 0 )
F_3 ( L_9 ) ;
}
F_3 ( L_9 ) ;
#endif
* V_2 -> V_41 = V_2 -> V_86 ;
F_18 ( V_2 -> V_57 -> V_65 . V_26 ,
V_2 -> V_86 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
V_2 -> V_86 = * V_2 -> V_57 -> V_65 . V_52 ;
}
struct V_1 * F_20 ( struct V_3 * V_4 ,
enum V_5 type )
{
struct V_1 * V_2 ;
F_2 ( ! V_4 ) ;
V_2 = F_21 ( sizeof( struct V_1 ) , V_88 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_23 . F_1 = F_1 ;
V_2 -> V_23 . F_14 = F_14 ;
V_2 -> V_23 . F_15 = F_15 ;
V_2 -> V_23 . F_16 = F_16 ;
V_2 -> V_23 . F_19 = F_19 ;
switch ( V_4 -> V_89 -> V_90 ) {
case V_91 :
F_22 ( & V_2 -> V_35 ) ;
break;
case V_92 :
F_23 ( & V_2 -> V_35 ) ;
break;
}
if ( ! V_2 -> V_23 . F_1 ( V_2 , V_4 , type , V_93 ) ) {
F_6 ( L_10 ) ;
F_24 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
V_2 -> V_23 . F_14 ( V_2 ) ;
F_24 ( V_2 ) ;
}
