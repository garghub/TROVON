void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_3 &= 0xFF ;
if ( V_3 == V_4 )
return;
if ( V_3 == V_5 ||
V_3 == V_6 ) {
V_2 -> V_7 = true ;
V_2 -> V_8 = true ;
F_2 ( V_9 , L_1 ,
& V_2 -> V_10 ) ;
} else if ( V_3 == V_11 ) {
V_2 -> V_7 = false ;
V_2 -> V_8 = true ;
F_2 ( V_9 , L_2 ,
& V_2 -> V_10 ) ;
} else {
V_2 -> V_7 = false ;
V_2 -> V_8 = false ;
}
}
int
F_3 ( const unsigned int V_12 , struct V_13 * V_14 ,
T_1 * V_3 , T_2 * V_15 )
{
int V_16 ;
T_3 * V_17 ;
struct V_18 * V_19 = NULL ;
T_4 V_20 [ 17 ] ;
struct V_21 * V_22 = V_14 -> V_22 ;
V_17 = F_4 ( V_14 -> V_23 , V_14 -> V_24 ) ;
if ( V_17 == NULL ) {
V_16 = - V_25 ;
goto V_26;
}
V_19 = F_5 ( sizeof( struct V_18 ) + V_27 * 2 ,
V_28 ) ;
if ( V_19 == NULL ) {
V_16 = - V_25 ;
goto V_26;
}
V_14 -> V_29 |= V_30 ;
* V_20 = V_6 ;
if ( V_14 -> V_31 -> V_32 -> V_33 -> V_34 & V_35 )
memcpy ( V_20 + 1 , V_22 -> V_36 , V_37 ) ;
V_16 = F_6 ( V_12 , V_14 , V_17 , V_20 , V_19 ) ;
if ( V_16 )
goto V_26;
if ( V_15 ) {
V_16 = F_7 ( V_12 , V_14 -> V_31 , V_22 -> V_38 ,
V_22 -> V_39 ,
& V_19 -> V_40 ) ;
if ( V_16 ) {
V_19 -> V_40 = 0 ;
V_16 = 0 ;
}
F_8 ( V_15 , V_19 ) ;
}
* V_3 = * V_20 ;
V_26:
F_9 ( V_19 ) ;
F_9 ( V_17 ) ;
return V_16 ;
}
int
F_10 ( struct V_41 * V_42 , struct V_43 * V_44 ,
const unsigned int V_12 )
{
int V_16 = 0 , V_45 ;
unsigned int V_46 , V_47 = 0 , V_48 ;
struct V_49 * V_15 , * V_50 ;
struct V_51 * V_31 = F_11 ( V_42 -> V_52 ) ;
struct V_1 * V_2 = F_12 ( V_42 -> V_53 -> V_54 ) ;
struct V_55 * V_56 , * V_57 ;
T_5 V_58 = 1 + V_44 -> V_59 - V_44 -> V_60 ;
struct V_61 V_62 ;
F_13 ( & V_62 ) ;
V_48 = V_31 -> V_32 -> V_33 -> V_63 ;
if ( ! V_48 )
return - V_64 ;
V_46 = V_48 / sizeof( struct V_49 ) ;
V_15 = F_5 ( V_46 * sizeof( struct V_49 ) , V_28 ) ;
if ( ! V_15 )
return - V_25 ;
V_50 = V_15 ;
F_14 ( & V_2 -> V_65 ) ;
F_15 (li, tmp, &cfile->llist->locks, llist) {
if ( V_44 -> V_60 > V_56 -> V_66 ||
( V_44 -> V_60 + V_58 ) <
( V_56 -> V_66 + V_56 -> V_58 ) )
continue;
if ( V_67 -> V_68 != V_56 -> V_69 )
continue;
if ( V_2 -> V_70 ) {
F_16 ( & V_56 -> V_71 ) ;
F_17 ( V_56 ) ;
F_9 ( V_56 ) ;
continue;
}
V_50 -> V_72 = F_18 ( V_56 -> V_58 ) ;
V_50 -> V_73 = F_18 ( V_56 -> V_66 ) ;
V_50 -> V_74 = F_19 ( V_75 ) ;
F_20 ( & V_56 -> V_71 , & V_62 ) ;
if ( ++ V_47 == V_46 ) {
V_45 = F_21 ( V_12 , V_31 ,
V_42 -> V_22 . V_38 ,
V_42 -> V_22 . V_39 ,
V_67 -> V_68 , V_47 , V_15 ) ;
if ( V_45 ) {
F_22 ( & V_62 ,
& V_42 -> V_71 -> V_76 ) ;
V_16 = V_45 ;
} else
F_23 ( & V_62 ) ;
V_50 = V_15 ;
V_47 = 0 ;
} else
V_50 ++ ;
}
if ( V_47 ) {
V_45 = F_21 ( V_12 , V_31 , V_42 -> V_22 . V_38 ,
V_42 -> V_22 . V_39 , V_67 -> V_68 ,
V_47 , V_15 ) ;
if ( V_45 ) {
F_22 ( & V_62 , & V_42 -> V_71 -> V_76 ) ;
V_16 = V_45 ;
} else
F_23 ( & V_62 ) ;
}
F_24 ( & V_2 -> V_65 ) ;
F_9 ( V_15 ) ;
return V_16 ;
}
static int
F_25 ( struct V_77 * V_78 , const unsigned int V_12 ,
struct V_49 * V_15 , unsigned int V_46 )
{
int V_16 = 0 , V_45 ;
struct V_41 * V_42 = V_78 -> V_42 ;
struct V_55 * V_56 ;
unsigned int V_47 = 0 ;
struct V_49 * V_50 = V_15 ;
struct V_51 * V_31 = F_11 ( V_42 -> V_52 ) ;
F_26 (li, &fdlocks->locks, llist) {
V_50 -> V_72 = F_18 ( V_56 -> V_58 ) ;
V_50 -> V_73 = F_18 ( V_56 -> V_66 ) ;
V_50 -> V_74 = F_19 ( V_56 -> type |
V_79 ) ;
if ( ++ V_47 == V_46 ) {
V_45 = F_21 ( V_12 , V_31 ,
V_42 -> V_22 . V_38 ,
V_42 -> V_22 . V_39 ,
V_67 -> V_68 , V_47 , V_15 ) ;
if ( V_45 )
V_16 = V_45 ;
V_50 = V_15 ;
V_47 = 0 ;
} else
V_50 ++ ;
}
if ( V_47 ) {
V_45 = F_21 ( V_12 , V_31 ,
V_42 -> V_22 . V_38 ,
V_42 -> V_22 . V_39 ,
V_67 -> V_68 , V_47 , V_15 ) ;
if ( V_45 )
V_16 = V_45 ;
}
return V_16 ;
}
int
F_27 ( struct V_41 * V_42 )
{
int V_16 = 0 , V_45 ;
unsigned int V_12 ;
unsigned int V_46 , V_48 ;
struct V_49 * V_15 ;
struct V_1 * V_2 = F_12 ( V_42 -> V_53 -> V_54 ) ;
struct V_77 * V_78 ;
V_12 = F_28 () ;
V_48 = F_11 ( V_42 -> V_52 ) -> V_32 -> V_33 -> V_63 ;
if ( ! V_48 ) {
F_29 ( V_12 ) ;
return - V_64 ;
}
V_46 = V_48 / sizeof( struct V_49 ) ;
V_15 = F_5 ( V_46 * sizeof( struct V_49 ) , V_28 ) ;
if ( ! V_15 ) {
F_29 ( V_12 ) ;
return - V_25 ;
}
F_26 (fdlocks, &cinode->llist, llist) {
V_45 = F_25 ( V_78 , V_12 , V_15 , V_46 ) ;
if ( V_45 )
V_16 = V_45 ;
}
F_9 ( V_15 ) ;
F_29 ( V_12 ) ;
return V_16 ;
}
