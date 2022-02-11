int
F_1 ( const unsigned int V_1 , struct V_2 * V_3 ,
T_1 * V_4 , T_2 * V_5 )
{
int V_6 ;
T_3 * V_7 ;
struct V_8 * V_9 = NULL ;
T_4 V_10 [ 17 ] ;
struct V_11 * V_12 = V_3 -> V_12 ;
struct V_13 V_14 ;
V_7 = F_2 ( V_3 -> V_15 , V_3 -> V_16 ) ;
if ( V_7 == NULL ) {
V_6 = - V_17 ;
goto V_18;
}
V_9 = F_3 ( sizeof( struct V_8 ) + V_19 * 2 ,
V_20 ) ;
if ( V_9 == NULL ) {
V_6 = - V_17 ;
goto V_18;
}
V_3 -> V_21 |= V_22 ;
* V_10 = V_23 ;
if ( V_3 -> V_24 -> V_25 -> V_26 -> V_27 & V_28 )
memcpy ( V_10 + 1 , V_12 -> V_29 , V_30 ) ;
V_6 = F_4 ( V_1 , V_3 , V_7 , V_10 , V_9 , NULL ) ;
if ( V_6 )
goto V_18;
if ( V_3 -> V_24 -> V_31 ) {
V_14 . V_32 = 0 ;
V_14 . V_33 = 0 ;
V_6 = F_5 ( V_1 , V_3 -> V_24 , V_12 -> V_34 ,
V_12 -> V_35 , V_36 , true ,
( char * ) & V_14 , sizeof( V_14 ) ,
NULL , NULL ) ;
if ( V_6 == - V_37 ) {
F_6 ( V_38 ,
L_1 ) ;
V_3 -> V_24 -> V_31 = false ;
} else if ( V_6 )
F_6 ( V_39 , L_2 , V_6 ) ;
V_6 = 0 ;
}
if ( V_5 ) {
V_6 = F_7 ( V_1 , V_3 -> V_24 , V_12 -> V_34 ,
V_12 -> V_35 ,
& V_9 -> V_40 ) ;
if ( V_6 ) {
V_9 -> V_40 = 0 ;
V_6 = 0 ;
}
F_8 ( V_5 , V_9 ) ;
}
* V_4 = * V_10 ;
V_18:
F_9 ( V_9 ) ;
F_9 ( V_7 ) ;
return V_6 ;
}
int
F_10 ( struct V_41 * V_42 , struct V_43 * V_44 ,
const unsigned int V_1 )
{
int V_6 = 0 , V_45 ;
unsigned int V_46 , V_47 = 0 , V_48 ;
struct V_49 * V_5 , * V_50 ;
struct V_51 * V_24 = F_11 ( V_42 -> V_52 ) ;
struct V_53 * V_54 = F_12 ( F_13 ( V_42 -> V_55 ) ) ;
struct V_56 * V_57 , * V_58 ;
T_5 V_59 = 1 + V_44 -> V_60 - V_44 -> V_61 ;
struct V_62 V_63 ;
F_14 ( & V_63 ) ;
V_48 = V_24 -> V_25 -> V_26 -> V_64 ;
if ( ! V_48 )
return - V_65 ;
V_46 = V_48 / sizeof( struct V_49 ) ;
V_5 = F_15 ( V_46 , sizeof( struct V_49 ) , V_20 ) ;
if ( ! V_5 )
return - V_17 ;
V_50 = V_5 ;
F_16 ( & V_54 -> V_66 ) ;
F_17 (li, tmp, &cfile->llist->locks, llist) {
if ( V_44 -> V_61 > V_57 -> V_67 ||
( V_44 -> V_61 + V_59 ) <
( V_57 -> V_67 + V_57 -> V_59 ) )
continue;
if ( V_68 -> V_69 != V_57 -> V_70 )
continue;
if ( V_54 -> V_71 ) {
F_18 ( & V_57 -> V_72 ) ;
F_19 ( V_57 ) ;
F_9 ( V_57 ) ;
continue;
}
V_50 -> V_73 = F_20 ( V_57 -> V_59 ) ;
V_50 -> V_74 = F_20 ( V_57 -> V_67 ) ;
V_50 -> V_75 = F_21 ( V_76 ) ;
F_22 ( & V_57 -> V_72 , & V_63 ) ;
if ( ++ V_47 == V_46 ) {
V_45 = F_23 ( V_1 , V_24 ,
V_42 -> V_12 . V_34 ,
V_42 -> V_12 . V_35 ,
V_68 -> V_69 , V_47 , V_5 ) ;
if ( V_45 ) {
F_24 ( & V_63 ,
& V_42 -> V_72 -> V_77 ) ;
V_6 = V_45 ;
} else
F_25 ( & V_63 ) ;
V_50 = V_5 ;
V_47 = 0 ;
} else
V_50 ++ ;
}
if ( V_47 ) {
V_45 = F_23 ( V_1 , V_24 , V_42 -> V_12 . V_34 ,
V_42 -> V_12 . V_35 , V_68 -> V_69 ,
V_47 , V_5 ) ;
if ( V_45 ) {
F_24 ( & V_63 , & V_42 -> V_72 -> V_77 ) ;
V_6 = V_45 ;
} else
F_25 ( & V_63 ) ;
}
F_26 ( & V_54 -> V_66 ) ;
F_9 ( V_5 ) ;
return V_6 ;
}
static int
F_27 ( struct V_78 * V_79 , const unsigned int V_1 ,
struct V_49 * V_5 , unsigned int V_46 )
{
int V_6 = 0 , V_45 ;
struct V_41 * V_42 = V_79 -> V_42 ;
struct V_56 * V_57 ;
unsigned int V_47 = 0 ;
struct V_49 * V_50 = V_5 ;
struct V_51 * V_24 = F_11 ( V_42 -> V_52 ) ;
F_28 (li, &fdlocks->locks, llist) {
V_50 -> V_73 = F_20 ( V_57 -> V_59 ) ;
V_50 -> V_74 = F_20 ( V_57 -> V_67 ) ;
V_50 -> V_75 = F_21 ( V_57 -> type |
V_80 ) ;
if ( ++ V_47 == V_46 ) {
V_45 = F_23 ( V_1 , V_24 ,
V_42 -> V_12 . V_34 ,
V_42 -> V_12 . V_35 ,
V_68 -> V_69 , V_47 , V_5 ) ;
if ( V_45 )
V_6 = V_45 ;
V_50 = V_5 ;
V_47 = 0 ;
} else
V_50 ++ ;
}
if ( V_47 ) {
V_45 = F_23 ( V_1 , V_24 ,
V_42 -> V_12 . V_34 ,
V_42 -> V_12 . V_35 ,
V_68 -> V_69 , V_47 , V_5 ) ;
if ( V_45 )
V_6 = V_45 ;
}
return V_6 ;
}
int
F_29 ( struct V_41 * V_42 )
{
int V_6 = 0 , V_45 ;
unsigned int V_1 ;
unsigned int V_46 , V_48 ;
struct V_49 * V_5 ;
struct V_53 * V_54 = F_12 ( F_13 ( V_42 -> V_55 ) ) ;
struct V_78 * V_79 ;
V_1 = F_30 () ;
V_48 = F_11 ( V_42 -> V_52 ) -> V_25 -> V_26 -> V_64 ;
if ( ! V_48 ) {
F_31 ( V_1 ) ;
return - V_65 ;
}
V_46 = V_48 / sizeof( struct V_49 ) ;
V_5 = F_15 ( V_46 , sizeof( struct V_49 ) , V_20 ) ;
if ( ! V_5 ) {
F_31 ( V_1 ) ;
return - V_17 ;
}
F_28 (fdlocks, &cinode->llist, llist) {
V_45 = F_27 ( V_79 , V_1 , V_5 , V_46 ) ;
if ( V_45 )
V_6 = V_45 ;
}
F_9 ( V_5 ) ;
F_31 ( V_1 ) ;
return V_6 ;
}
