static bool F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_5 type , unsigned int V_6 )
{
struct V_7 V_8 ;
int V_9 ;
union V_10 V_11 ;
if ( F_2 ( type != V_12 && type != V_13 ) )
return false ;
F_3 ( L_1 , V_13 ,
V_6 ) ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
V_11 . V_14 = V_15 ;
V_11 . type = V_16 ;
V_11 . V_17 |= V_18 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_19 = V_11 . V_17 ;
switch ( type ) {
case V_12 :
case V_13 :
V_2 -> V_20 = V_4 -> V_21 -> V_22 . V_23 ( V_4 -> V_21 ,
V_24 ) ;
break;
default:
F_4 ( L_2 , type ) ;
return false ;
}
if ( ! V_2 -> V_20 )
return false ;
V_8 . V_25 = F_5 ( V_4 , & V_8 . V_26 ) ;
if ( ! V_8 . V_25 ) {
F_4 ( L_3 ) ;
goto V_27;
}
V_9 = F_6 ( V_4 , V_6 , & V_2 -> V_28 ) ;
if ( V_9 != 0 ) {
F_4 ( L_4 , V_6 ) ;
goto V_29;
}
V_2 -> V_30 = V_2 -> V_28 -> V_31 ;
V_2 -> V_32 = V_2 -> V_28 -> V_33 ;
V_9 = V_2 -> V_34 . F_1 ( V_2 , V_4 , type , V_6 ) ;
if ( ! V_9 )
goto V_35;
V_9 = F_6 ( V_4 , sizeof( * V_2 -> V_36 ) ,
& V_2 -> V_37 ) ;
if ( V_9 != 0 )
goto V_38;
V_2 -> V_36 = V_2 -> V_37 -> V_31 ;
V_2 -> V_39 = V_2 -> V_37 -> V_33 ;
V_9 = F_6 ( V_4 , sizeof( * V_2 -> V_40 ) ,
& V_2 -> V_41 ) ;
if ( V_9 != 0 )
goto V_42;
V_2 -> V_40 = V_2 -> V_41 -> V_31 ;
V_2 -> V_43 = V_2 -> V_41 -> V_33 ;
memset ( V_2 -> V_30 , 0 , V_6 ) ;
memset ( V_2 -> V_36 , 0 , sizeof( * V_2 -> V_36 ) ) ;
memset ( V_2 -> V_40 , 0 , sizeof( * V_2 -> V_40 ) ) ;
V_8 . V_6 = V_6 ;
V_8 . V_44 = false ;
V_8 . V_45 = 1 ;
V_8 . V_46 = 100 ;
V_8 . type = type ;
V_8 . V_47 = 0 ;
V_8 . V_48 = V_2 -> V_32 ;
V_8 . V_49 = ( V_50 * ) V_2 -> V_39 ;
V_8 . V_51 = ( V_50 * ) V_2 -> V_43 ;
V_8 . V_52 = V_2 -> V_53 ;
V_8 . V_54 = V_55 ;
if ( F_7 ( & V_2 -> V_56 , & V_8 ) != 0 )
goto V_57;
V_2 -> V_56 -> V_58 = V_4 ;
V_2 -> V_56 -> V_59 = F_8 ( V_60 ) ;
V_9 = V_2 -> V_20 -> V_61 ( V_2 -> V_20 , & V_2 -> V_56 -> V_20 ,
& V_2 -> V_56 -> V_62 ,
& V_2 -> V_56 -> V_63 ,
& V_2 -> V_56 -> V_64 ) ;
if ( V_9 != 0 )
goto V_65;
if ( type == V_13 ) {
F_3 ( L_5 ) ;
V_2 -> V_56 -> V_66 = V_67 ;
V_2 -> V_56 -> V_56 = V_68 ;
V_2 -> V_20 -> V_69 ( V_2 -> V_20 , V_2 -> V_56 -> V_20 , V_2 -> V_56 -> V_66 ,
V_2 -> V_56 -> V_56 , & V_2 -> V_56 -> V_64 ,
NULL ) ;
} else {
V_9 = F_6 ( V_4 , sizeof( V_50 ) ,
& V_2 -> V_70 ) ;
if ( V_9 != 0 )
goto V_71;
V_2 -> V_72 = V_2 -> V_70 -> V_31 ;
V_2 -> V_73 = V_2 -> V_70 -> V_33 ;
}
F_9 ( V_2 -> V_56 ) ;
return true ;
V_71:
V_65:
F_10 ( V_2 -> V_56 ) ;
V_57:
F_11 ( V_4 , V_2 -> V_41 ) ;
V_42:
F_11 ( V_4 , V_2 -> V_37 ) ;
V_38:
F_11 ( V_4 , V_2 -> V_74 ) ;
V_35:
F_11 ( V_4 , V_2 -> V_28 ) ;
V_29:
F_12 ( V_4 , V_8 . V_25 ) ;
V_27:
return false ;
}
static void F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_56 -> V_64 . type == V_13 )
V_2 -> V_20 -> V_75 ( V_2 -> V_20 ,
V_2 -> V_56 -> V_20 ,
V_76 ,
V_77 ,
V_2 -> V_56 -> V_66 ,
V_2 -> V_56 -> V_56 ) ;
else if ( V_2 -> V_56 -> V_64 . type == V_12 )
F_11 ( V_2 -> V_4 , V_2 -> V_70 ) ;
V_2 -> V_20 -> V_78 ( V_2 -> V_20 , V_2 -> V_56 -> V_20 , V_2 -> V_56 -> V_62 ) ;
F_11 ( V_2 -> V_4 , V_2 -> V_37 ) ;
F_11 ( V_2 -> V_4 , V_2 -> V_41 ) ;
V_2 -> V_34 . F_13 ( V_2 ) ;
F_11 ( V_2 -> V_4 , V_2 -> V_28 ) ;
F_12 ( V_2 -> V_4 ,
V_2 -> V_56 -> V_64 . V_25 ) ;
F_10 ( V_2 -> V_56 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
T_1 V_79 , unsigned int * * V_80 )
{
T_1 V_81 ;
T_1 V_82 ;
V_50 V_83 , V_84 ;
unsigned int * V_48 ;
V_84 = * V_2 -> V_36 ;
V_83 = * V_2 -> V_40 ;
V_48 = ( unsigned int * ) V_2 -> V_30 ;
V_82 = V_2 -> V_56 -> V_64 . V_6 / sizeof( V_50 ) ;
F_3 ( L_6 , V_84 ) ;
F_3 ( L_7 , V_83 ) ;
F_3 ( L_8 , V_48 ) ;
V_81 = ( V_84 + V_82 - 1 - V_83 ) %
V_82 ;
if ( V_79 > V_81 ) {
* V_80 = NULL ;
return - V_85 ;
}
if ( V_83 + V_79 >= V_82 ) {
if ( V_79 >= V_84 ) {
* V_80 = NULL ;
return - V_85 ;
}
while ( V_83 > 0 ) {
V_48 [ V_83 ] = V_2 -> V_19 ;
V_83 = ( V_83 + 1 ) % V_82 ;
}
}
* V_80 = & V_48 [ V_83 ] ;
V_2 -> V_86 = V_83 + V_79 ;
return 0 ;
}
static void F_15 ( struct V_1 * V_2 )
{
#ifdef F_16
int V_87 ;
for ( V_87 = * V_2 -> V_40 ; V_87 < V_2 -> V_86 ; V_87 ++ ) {
F_3 ( L_9 , V_2 -> V_30 [ V_87 ] ) ;
if ( V_87 % 15 == 0 )
F_3 ( L_10 ) ;
}
F_3 ( L_10 ) ;
#endif
* V_2 -> V_40 = V_2 -> V_86 ;
F_17 ( V_2 -> V_56 -> V_64 . V_25 ,
V_2 -> V_86 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
V_2 -> V_86 = * V_2 -> V_56 -> V_64 . V_51 ;
}
struct V_1 * F_19 ( struct V_3 * V_4 ,
enum V_5 type )
{
struct V_1 * V_2 ;
V_2 = F_20 ( sizeof( * V_2 ) , V_88 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_22 . F_1 = F_1 ;
V_2 -> V_22 . F_13 = F_13 ;
V_2 -> V_22 . F_14 = F_14 ;
V_2 -> V_22 . F_15 = F_15 ;
V_2 -> V_22 . F_18 = F_18 ;
switch ( V_4 -> V_89 -> V_90 ) {
case V_91 :
F_21 ( & V_2 -> V_34 ) ;
break;
case V_92 :
F_22 ( & V_2 -> V_34 ) ;
break;
}
if ( ! V_2 -> V_22 . F_1 ( V_2 , V_4 , type , V_93 ) ) {
F_4 ( L_11 ) ;
F_23 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_24 ( struct V_1 * V_2 )
{
V_2 -> V_22 . F_13 ( V_2 ) ;
F_23 ( V_2 ) ;
}
