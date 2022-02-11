void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_3 &= 0xFF ;
if ( V_3 == V_4 )
return;
if ( V_3 == V_5 ) {
V_2 -> V_6 = true ;
V_2 -> V_7 = true ;
F_2 ( 1 , L_1 ,
& V_2 -> V_8 ) ;
} else if ( V_3 == V_9 ) {
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
F_2 ( 1 , L_2 ,
& V_2 -> V_8 ) ;
} else {
V_2 -> V_6 = false ;
V_2 -> V_7 = false ;
}
}
int
F_3 ( const unsigned int V_10 , struct V_11 * V_12 , const char * V_13 ,
int V_14 , int V_15 , int V_16 ,
struct V_17 * V_18 , T_1 * V_3 , T_2 * V_19 ,
struct V_20 * V_21 )
{
int V_22 ;
T_3 * V_23 ;
struct V_24 * V_25 = NULL ;
T_4 V_26 [ 17 ] ;
V_23 = F_4 ( V_13 , V_21 ) ;
if ( V_23 == NULL ) {
V_22 = - V_27 ;
goto V_28;
}
V_25 = F_5 ( sizeof( struct V_24 ) + V_29 * 2 ,
V_30 ) ;
if ( V_25 == NULL ) {
V_22 = - V_27 ;
goto V_28;
}
V_15 |= V_31 ;
* V_26 = V_5 ;
if ( V_12 -> V_32 -> V_33 -> V_34 & V_35 )
memcpy ( V_26 + 1 , V_18 -> V_36 , V_37 ) ;
V_22 = F_6 ( V_10 , V_12 , V_23 , & V_18 -> V_38 ,
& V_18 -> V_39 , V_15 , V_14 ,
0 , 0 , V_26 , V_25 ) ;
if ( V_22 )
goto V_28;
if ( V_19 ) {
V_22 = F_7 ( V_10 , V_12 , V_18 -> V_38 ,
V_18 -> V_39 ,
& V_25 -> V_40 ) ;
if ( V_22 ) {
V_25 -> V_40 = 0 ;
V_22 = 0 ;
}
F_8 ( V_19 , V_25 ) ;
}
* V_3 = * V_26 ;
V_28:
F_9 ( V_25 ) ;
F_9 ( V_23 ) ;
return V_22 ;
}
int
F_10 ( struct V_41 * V_42 , struct V_43 * V_44 ,
const unsigned int V_10 )
{
int V_22 = 0 , V_45 ;
unsigned int V_46 , V_47 = 0 , V_48 ;
struct V_49 * V_19 , * V_50 ;
struct V_11 * V_12 = F_11 ( V_42 -> V_51 ) ;
struct V_1 * V_2 = F_12 ( V_42 -> V_52 -> V_53 ) ;
struct V_54 * V_55 , * V_56 ;
T_5 V_57 = 1 + V_44 -> V_58 - V_44 -> V_59 ;
struct V_60 V_61 ;
F_13 ( & V_61 ) ;
V_48 = V_12 -> V_32 -> V_33 -> V_62 ;
if ( ! V_48 )
return - V_63 ;
V_46 = V_48 / sizeof( struct V_49 ) ;
V_19 = F_5 ( V_46 * sizeof( struct V_49 ) , V_30 ) ;
if ( ! V_19 )
return - V_27 ;
V_50 = V_19 ;
F_14 ( & V_2 -> V_64 ) ;
F_15 (li, tmp, &cfile->llist->locks, llist) {
if ( V_44 -> V_59 > V_55 -> V_65 ||
( V_44 -> V_59 + V_57 ) <
( V_55 -> V_65 + V_55 -> V_57 ) )
continue;
if ( V_66 -> V_67 != V_55 -> V_68 )
continue;
if ( V_2 -> V_69 ) {
F_16 ( & V_55 -> V_70 ) ;
F_17 ( V_55 ) ;
F_9 ( V_55 ) ;
continue;
}
V_50 -> V_71 = F_18 ( V_55 -> V_57 ) ;
V_50 -> V_72 = F_18 ( V_55 -> V_65 ) ;
V_50 -> V_73 = F_19 ( V_74 ) ;
F_20 ( & V_55 -> V_70 , & V_61 ) ;
if ( ++ V_47 == V_46 ) {
V_45 = F_21 ( V_10 , V_12 ,
V_42 -> V_18 . V_38 ,
V_42 -> V_18 . V_39 ,
V_66 -> V_67 , V_47 , V_19 ) ;
if ( V_45 ) {
F_22 ( & V_61 ,
& V_42 -> V_70 -> V_75 ) ;
V_22 = V_45 ;
} else
F_23 ( & V_61 ) ;
V_50 = V_19 ;
V_47 = 0 ;
} else
V_50 ++ ;
}
if ( V_47 ) {
V_45 = F_21 ( V_10 , V_12 , V_42 -> V_18 . V_38 ,
V_42 -> V_18 . V_39 , V_66 -> V_67 ,
V_47 , V_19 ) ;
if ( V_45 ) {
F_22 ( & V_61 , & V_42 -> V_70 -> V_75 ) ;
V_22 = V_45 ;
} else
F_23 ( & V_61 ) ;
}
F_24 ( & V_2 -> V_64 ) ;
F_9 ( V_19 ) ;
return V_22 ;
}
static int
F_25 ( struct V_76 * V_77 , const unsigned int V_10 ,
struct V_49 * V_19 , unsigned int V_46 )
{
int V_22 = 0 , V_45 ;
struct V_41 * V_42 = V_77 -> V_42 ;
struct V_54 * V_55 ;
unsigned int V_47 = 0 ;
struct V_49 * V_50 = V_19 ;
struct V_11 * V_12 = F_11 ( V_42 -> V_51 ) ;
F_26 (li, &fdlocks->locks, llist) {
V_50 -> V_71 = F_18 ( V_55 -> V_57 ) ;
V_50 -> V_72 = F_18 ( V_55 -> V_65 ) ;
V_50 -> V_73 = F_19 ( V_55 -> type |
V_78 ) ;
if ( ++ V_47 == V_46 ) {
V_45 = F_21 ( V_10 , V_12 ,
V_42 -> V_18 . V_38 ,
V_42 -> V_18 . V_39 ,
V_66 -> V_67 , V_47 , V_19 ) ;
if ( V_45 )
V_22 = V_45 ;
V_50 = V_19 ;
V_47 = 0 ;
} else
V_50 ++ ;
}
if ( V_47 ) {
V_45 = F_21 ( V_10 , V_12 ,
V_42 -> V_18 . V_38 ,
V_42 -> V_18 . V_39 ,
V_66 -> V_67 , V_47 , V_19 ) ;
if ( V_45 )
V_22 = V_45 ;
}
return V_22 ;
}
int
F_27 ( struct V_41 * V_42 )
{
int V_22 = 0 , V_45 ;
unsigned int V_10 ;
unsigned int V_46 , V_48 ;
struct V_49 * V_19 ;
struct V_1 * V_2 = F_12 ( V_42 -> V_52 -> V_53 ) ;
struct V_76 * V_77 ;
V_10 = F_28 () ;
V_48 = F_11 ( V_42 -> V_51 ) -> V_32 -> V_33 -> V_62 ;
if ( ! V_48 ) {
F_29 ( V_10 ) ;
return - V_63 ;
}
V_46 = V_48 / sizeof( struct V_49 ) ;
V_19 = F_5 ( V_46 * sizeof( struct V_49 ) , V_30 ) ;
if ( ! V_19 ) {
F_29 ( V_10 ) ;
return - V_27 ;
}
F_26 (fdlocks, &cinode->llist, llist) {
V_45 = F_25 ( V_77 , V_10 , V_19 , V_46 ) ;
if ( V_45 )
V_22 = V_45 ;
}
F_9 ( V_19 ) ;
F_29 ( V_10 ) ;
return V_22 ;
}
