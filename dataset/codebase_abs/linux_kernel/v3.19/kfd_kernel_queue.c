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
V_11 . V_15 = V_16 ;
V_11 . type = V_17 ;
V_11 . V_18 |= V_19 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_20 = V_11 . V_18 ;
switch ( type ) {
case V_12 :
case V_13 :
V_2 -> V_21 = V_4 -> V_22 -> V_23 ( V_4 -> V_22 ,
V_24 ) ;
break;
default:
F_4 () ;
break;
}
if ( V_2 -> V_21 == NULL )
return false ;
V_8 . V_25 = F_5 ( V_4 , & V_8 . V_26 ) ;
if ( V_8 . V_25 == NULL )
goto V_27;
V_9 = V_28 -> V_29 ( V_4 -> V_30 ,
V_6 ,
V_31 ,
V_32 ,
(struct V_33 * * ) & V_2 -> V_34 ) ;
if ( V_9 != 0 )
goto V_35;
V_2 -> V_36 = V_2 -> V_34 -> V_37 ;
V_2 -> V_38 = V_2 -> V_34 -> V_39 ;
V_9 = V_28 -> V_29 ( V_4 -> V_30 ,
sizeof( * V_2 -> V_40 ) ,
32 ,
V_32 ,
(struct V_33 * * ) & V_2 -> V_41 ) ;
if ( V_9 != 0 )
goto V_42;
V_2 -> V_40 = V_2 -> V_41 -> V_37 ;
V_2 -> V_43 = V_2 -> V_41 -> V_39 ;
V_9 = V_28 -> V_29 ( V_4 -> V_30 ,
sizeof( * V_2 -> V_44 ) ,
32 ,
V_32 ,
(struct V_33 * * ) & V_2 -> V_45 ) ;
if ( V_9 != 0 )
goto V_46;
V_2 -> V_44 = V_2 -> V_45 -> V_37 ;
V_2 -> V_47 = V_2 -> V_45 -> V_39 ;
memset ( V_2 -> V_36 , 0 , V_6 ) ;
memset ( V_2 -> V_40 , 0 , sizeof( * V_2 -> V_40 ) ) ;
memset ( V_2 -> V_44 , 0 , sizeof( * V_2 -> V_44 ) ) ;
V_8 . V_6 = V_6 ;
V_8 . V_48 = false ;
V_8 . V_49 = 1 ;
V_8 . V_50 = 100 ;
V_8 . type = type ;
V_8 . V_51 = 0 ;
V_8 . V_52 = V_2 -> V_38 ;
V_8 . V_53 = ( V_54 * ) V_2 -> V_43 ;
V_8 . V_55 = ( V_54 * ) V_2 -> V_47 ;
if ( F_6 ( & V_2 -> V_56 , V_8 ) != 0 )
goto V_57;
V_2 -> V_56 -> V_58 = V_4 ;
V_2 -> V_56 -> V_59 = F_7 ( V_60 ) ;
V_9 = V_2 -> V_21 -> V_61 ( V_2 -> V_21 , & V_2 -> V_56 -> V_21 ,
& V_2 -> V_56 -> V_62 ,
& V_2 -> V_56 -> V_63 ,
& V_2 -> V_56 -> V_64 ) ;
if ( V_9 != 0 )
goto V_65;
if ( type == V_13 ) {
F_3 ( L_2 ) ;
V_2 -> V_56 -> V_66 = V_67 ;
V_2 -> V_56 -> V_56 = V_68 ;
V_2 -> V_21 -> V_69 ( V_2 -> V_21 , V_2 -> V_56 -> V_21 , V_2 -> V_56 -> V_66 ,
V_2 -> V_56 -> V_56 , NULL ) ;
} else {
V_9 = V_28 -> V_29 ( V_4 -> V_30 ,
sizeof( V_54 ) ,
32 ,
V_32 ,
(struct V_33 * * ) & V_2 -> V_70 ) ;
if ( V_9 != 0 )
goto V_71;
V_2 -> V_72 = V_2 -> V_70 -> V_37 ;
V_2 -> V_73 = V_2 -> V_70 -> V_39 ;
}
F_8 ( V_2 -> V_56 ) ;
return true ;
V_71:
V_65:
F_9 ( V_2 -> V_56 ) ;
V_57:
V_28 -> V_74 ( V_4 -> V_30 , (struct V_33 * ) V_2 -> V_45 ) ;
V_46:
V_28 -> V_74 ( V_4 -> V_30 , (struct V_33 * ) V_2 -> V_41 ) ;
V_42:
V_28 -> V_74 ( V_4 -> V_30 , (struct V_33 * ) V_2 -> V_34 ) ;
V_35:
F_10 ( L_3 ) ;
F_11 ( V_4 , V_8 . V_25 ) ;
V_27:
F_10 ( L_4 ) ;
return false ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
if ( V_2 -> V_56 -> V_64 . type == V_13 )
V_2 -> V_21 -> V_75 ( V_2 -> V_21 ,
NULL ,
false ,
V_76 ,
V_2 -> V_56 -> V_66 ,
V_2 -> V_56 -> V_56 ) ;
V_28 -> V_74 ( V_2 -> V_4 -> V_30 , (struct V_33 * ) V_2 -> V_41 ) ;
V_28 -> V_74 ( V_2 -> V_4 -> V_30 , (struct V_33 * ) V_2 -> V_45 ) ;
V_28 -> V_74 ( V_2 -> V_4 -> V_30 , (struct V_33 * ) V_2 -> V_34 ) ;
F_11 ( V_2 -> V_4 ,
V_2 -> V_56 -> V_64 . V_25 ) ;
F_9 ( V_2 -> V_56 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
T_1 V_77 , unsigned int * * V_78 )
{
T_1 V_79 ;
T_1 V_80 ;
V_54 V_81 , V_82 ;
unsigned int * V_52 ;
F_2 ( ! V_2 || ! V_78 ) ;
V_82 = * V_2 -> V_40 ;
V_81 = * V_2 -> V_44 ;
V_52 = ( unsigned int * ) V_2 -> V_36 ;
V_80 = V_2 -> V_56 -> V_64 . V_6 / sizeof( V_54 ) ;
F_3 ( L_5 ,
V_14 , V_82 , V_81 , V_52 ) ;
V_79 = ( V_82 - 1 - V_81 + V_80 ) %
V_80 ;
if ( V_77 >= V_80 ||
V_77 >= V_79 ) {
* V_78 = NULL ;
return - V_83 ;
}
if ( V_81 + V_77 >= V_80 ) {
while ( V_81 > 0 ) {
V_52 [ V_81 ] = V_2 -> V_20 ;
V_81 = ( V_81 + 1 ) % V_80 ;
}
}
* V_78 = & V_52 [ V_81 ] ;
V_2 -> V_84 = V_81 + V_77 ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
#ifdef F_15
int V_85 ;
#endif
F_2 ( ! V_2 ) ;
#ifdef F_15
for ( V_85 = * V_2 -> V_44 ; V_85 < V_2 -> V_84 ; V_85 ++ ) {
F_3 ( L_6 , V_2 -> V_36 [ V_85 ] ) ;
if ( V_85 % 15 == 0 )
F_3 ( L_7 ) ;
}
F_3 ( L_7 ) ;
#endif
* V_2 -> V_44 = V_2 -> V_84 ;
F_16 ( V_2 -> V_56 -> V_64 . V_25 ,
V_2 -> V_84 ) ;
}
static int F_17 ( struct V_1 * V_2 , unsigned long V_86 )
{
unsigned long V_87 ;
F_2 ( ! V_2 ) ;
V_87 = V_86 ;
V_86 += V_88 * 1000 / V_89 ;
while ( * V_2 -> V_44 != * V_2 -> V_40 ) {
if ( F_18 ( V_88 * 1000 / V_89 , V_86 ) ) {
F_10 ( L_8 ,
V_14 , V_87 ) ;
F_10 ( L_9 ,
* V_2 -> V_44 , * V_2 -> V_40 ) ;
return - V_90 ;
}
F_19 () ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
V_2 -> V_84 = * V_2 -> V_56 -> V_64 . V_55 ;
}
struct V_1 * F_21 ( struct V_3 * V_4 ,
enum V_5 type )
{
struct V_1 * V_2 ;
F_2 ( ! V_4 ) ;
V_2 = F_22 ( sizeof( struct V_1 ) , V_91 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> F_1 = F_1 ;
V_2 -> F_12 = F_12 ;
V_2 -> F_13 = F_13 ;
V_2 -> F_14 = F_14 ;
V_2 -> F_17 = F_17 ;
V_2 -> F_20 = F_20 ;
if ( V_2 -> F_1 ( V_2 , V_4 , type , V_92 ) == false ) {
F_10 ( L_10 ) ;
F_23 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_24 ( struct V_1 * V_2 )
{
F_2 ( ! V_2 ) ;
V_2 -> F_12 ( V_2 ) ;
F_23 ( V_2 ) ;
}
