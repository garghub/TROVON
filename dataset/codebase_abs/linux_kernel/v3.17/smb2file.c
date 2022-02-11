int
F_1 ( const unsigned int V_1 , struct V_2 * V_3 ,
T_1 * V_4 , T_2 * V_5 )
{
int V_6 ;
T_3 * V_7 ;
struct V_8 * V_9 = NULL ;
T_4 V_10 [ 17 ] ;
struct V_11 * V_12 = V_3 -> V_12 ;
V_7 = F_2 ( V_3 -> V_13 , V_3 -> V_14 ) ;
if ( V_7 == NULL ) {
V_6 = - V_15 ;
goto V_16;
}
V_9 = F_3 ( sizeof( struct V_8 ) + V_17 * 2 ,
V_18 ) ;
if ( V_9 == NULL ) {
V_6 = - V_15 ;
goto V_16;
}
V_3 -> V_19 |= V_20 ;
* V_10 = V_21 ;
if ( V_3 -> V_22 -> V_23 -> V_24 -> V_25 & V_26 )
memcpy ( V_10 + 1 , V_12 -> V_27 , V_28 ) ;
V_6 = F_4 ( V_1 , V_3 , V_7 , V_10 , V_9 , NULL ) ;
if ( V_6 )
goto V_16;
if ( V_5 ) {
V_6 = F_5 ( V_1 , V_3 -> V_22 , V_12 -> V_29 ,
V_12 -> V_30 ,
& V_9 -> V_31 ) ;
if ( V_6 ) {
V_9 -> V_31 = 0 ;
V_6 = 0 ;
}
F_6 ( V_5 , V_9 ) ;
}
* V_4 = * V_10 ;
V_16:
F_7 ( V_9 ) ;
F_7 ( V_7 ) ;
return V_6 ;
}
int
F_8 ( struct V_32 * V_33 , struct V_34 * V_35 ,
const unsigned int V_1 )
{
int V_6 = 0 , V_36 ;
unsigned int V_37 , V_38 = 0 , V_39 ;
struct V_40 * V_5 , * V_41 ;
struct V_42 * V_22 = F_9 ( V_33 -> V_43 ) ;
struct V_44 * V_45 = F_10 ( V_33 -> V_46 -> V_47 ) ;
struct V_48 * V_49 , * V_50 ;
T_5 V_51 = 1 + V_35 -> V_52 - V_35 -> V_53 ;
struct V_54 V_55 ;
F_11 ( & V_55 ) ;
V_39 = V_22 -> V_23 -> V_24 -> V_56 ;
if ( ! V_39 )
return - V_57 ;
V_37 = V_39 / sizeof( struct V_40 ) ;
V_5 = F_3 ( V_37 * sizeof( struct V_40 ) , V_18 ) ;
if ( ! V_5 )
return - V_15 ;
V_41 = V_5 ;
F_12 ( & V_45 -> V_58 ) ;
F_13 (li, tmp, &cfile->llist->locks, llist) {
if ( V_35 -> V_53 > V_49 -> V_59 ||
( V_35 -> V_53 + V_51 ) <
( V_49 -> V_59 + V_49 -> V_51 ) )
continue;
if ( V_60 -> V_61 != V_49 -> V_62 )
continue;
if ( V_45 -> V_63 ) {
F_14 ( & V_49 -> V_64 ) ;
F_15 ( V_49 ) ;
F_7 ( V_49 ) ;
continue;
}
V_41 -> V_65 = F_16 ( V_49 -> V_51 ) ;
V_41 -> V_66 = F_16 ( V_49 -> V_59 ) ;
V_41 -> V_67 = F_17 ( V_68 ) ;
F_18 ( & V_49 -> V_64 , & V_55 ) ;
if ( ++ V_38 == V_37 ) {
V_36 = F_19 ( V_1 , V_22 ,
V_33 -> V_12 . V_29 ,
V_33 -> V_12 . V_30 ,
V_60 -> V_61 , V_38 , V_5 ) ;
if ( V_36 ) {
F_20 ( & V_55 ,
& V_33 -> V_64 -> V_69 ) ;
V_6 = V_36 ;
} else
F_21 ( & V_55 ) ;
V_41 = V_5 ;
V_38 = 0 ;
} else
V_41 ++ ;
}
if ( V_38 ) {
V_36 = F_19 ( V_1 , V_22 , V_33 -> V_12 . V_29 ,
V_33 -> V_12 . V_30 , V_60 -> V_61 ,
V_38 , V_5 ) ;
if ( V_36 ) {
F_20 ( & V_55 , & V_33 -> V_64 -> V_69 ) ;
V_6 = V_36 ;
} else
F_21 ( & V_55 ) ;
}
F_22 ( & V_45 -> V_58 ) ;
F_7 ( V_5 ) ;
return V_6 ;
}
static int
F_23 ( struct V_70 * V_71 , const unsigned int V_1 ,
struct V_40 * V_5 , unsigned int V_37 )
{
int V_6 = 0 , V_36 ;
struct V_32 * V_33 = V_71 -> V_33 ;
struct V_48 * V_49 ;
unsigned int V_38 = 0 ;
struct V_40 * V_41 = V_5 ;
struct V_42 * V_22 = F_9 ( V_33 -> V_43 ) ;
F_24 (li, &fdlocks->locks, llist) {
V_41 -> V_65 = F_16 ( V_49 -> V_51 ) ;
V_41 -> V_66 = F_16 ( V_49 -> V_59 ) ;
V_41 -> V_67 = F_17 ( V_49 -> type |
V_72 ) ;
if ( ++ V_38 == V_37 ) {
V_36 = F_19 ( V_1 , V_22 ,
V_33 -> V_12 . V_29 ,
V_33 -> V_12 . V_30 ,
V_60 -> V_61 , V_38 , V_5 ) ;
if ( V_36 )
V_6 = V_36 ;
V_41 = V_5 ;
V_38 = 0 ;
} else
V_41 ++ ;
}
if ( V_38 ) {
V_36 = F_19 ( V_1 , V_22 ,
V_33 -> V_12 . V_29 ,
V_33 -> V_12 . V_30 ,
V_60 -> V_61 , V_38 , V_5 ) ;
if ( V_36 )
V_6 = V_36 ;
}
return V_6 ;
}
int
F_25 ( struct V_32 * V_33 )
{
int V_6 = 0 , V_36 ;
unsigned int V_1 ;
unsigned int V_37 , V_39 ;
struct V_40 * V_5 ;
struct V_44 * V_45 = F_10 ( V_33 -> V_46 -> V_47 ) ;
struct V_70 * V_71 ;
V_1 = F_26 () ;
V_39 = F_9 ( V_33 -> V_43 ) -> V_23 -> V_24 -> V_56 ;
if ( ! V_39 ) {
F_27 ( V_1 ) ;
return - V_57 ;
}
V_37 = V_39 / sizeof( struct V_40 ) ;
V_5 = F_3 ( V_37 * sizeof( struct V_40 ) , V_18 ) ;
if ( ! V_5 ) {
F_27 ( V_1 ) ;
return - V_15 ;
}
F_24 (fdlocks, &cinode->llist, llist) {
V_36 = F_23 ( V_71 , V_1 , V_5 , V_37 ) ;
if ( V_36 )
V_6 = V_36 ;
}
F_7 ( V_5 ) ;
F_27 ( V_1 ) ;
return V_6 ;
}
