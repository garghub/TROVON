void
F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
V_3 &= 0xFF ;
if ( V_3 == V_4 )
return;
if ( V_3 == V_5 ) {
V_2 -> V_6 = true ;
V_2 -> V_7 = true ;
F_2 ( V_8 , L_1 ,
& V_2 -> V_9 ) ;
} else if ( V_3 == V_10 ) {
V_2 -> V_6 = false ;
V_2 -> V_7 = true ;
F_2 ( V_8 , L_2 ,
& V_2 -> V_9 ) ;
} else {
V_2 -> V_6 = false ;
V_2 -> V_7 = false ;
}
}
int
F_3 ( const unsigned int V_11 , struct V_12 * V_13 , const char * V_14 ,
int V_15 , int V_16 , int V_17 ,
struct V_18 * V_19 , T_1 * V_3 , T_2 * V_20 ,
struct V_21 * V_22 )
{
int V_23 ;
T_3 * V_24 ;
struct V_25 * V_26 = NULL ;
T_4 V_27 [ 17 ] ;
V_24 = F_4 ( V_14 , V_22 ) ;
if ( V_24 == NULL ) {
V_23 = - V_28 ;
goto V_29;
}
V_26 = F_5 ( sizeof( struct V_25 ) + V_30 * 2 ,
V_31 ) ;
if ( V_26 == NULL ) {
V_23 = - V_28 ;
goto V_29;
}
V_16 |= V_32 ;
* V_27 = V_5 ;
if ( V_13 -> V_33 -> V_34 -> V_35 & V_36 )
memcpy ( V_27 + 1 , V_19 -> V_37 , V_38 ) ;
V_23 = F_6 ( V_11 , V_13 , V_24 , & V_19 -> V_39 ,
& V_19 -> V_40 , V_16 , V_15 ,
0 , 0 , V_27 , V_26 ) ;
if ( V_23 )
goto V_29;
if ( V_20 ) {
V_23 = F_7 ( V_11 , V_13 , V_19 -> V_39 ,
V_19 -> V_40 ,
& V_26 -> V_41 ) ;
if ( V_23 ) {
V_26 -> V_41 = 0 ;
V_23 = 0 ;
}
F_8 ( V_20 , V_26 ) ;
}
* V_3 = * V_27 ;
V_29:
F_9 ( V_26 ) ;
F_9 ( V_24 ) ;
return V_23 ;
}
int
F_10 ( struct V_42 * V_43 , struct V_44 * V_45 ,
const unsigned int V_11 )
{
int V_23 = 0 , V_46 ;
unsigned int V_47 , V_48 = 0 , V_49 ;
struct V_50 * V_20 , * V_51 ;
struct V_12 * V_13 = F_11 ( V_43 -> V_52 ) ;
struct V_1 * V_2 = F_12 ( V_43 -> V_53 -> V_54 ) ;
struct V_55 * V_56 , * V_57 ;
T_5 V_58 = 1 + V_45 -> V_59 - V_45 -> V_60 ;
struct V_61 V_62 ;
F_13 ( & V_62 ) ;
V_49 = V_13 -> V_33 -> V_34 -> V_63 ;
if ( ! V_49 )
return - V_64 ;
V_47 = V_49 / sizeof( struct V_50 ) ;
V_20 = F_5 ( V_47 * sizeof( struct V_50 ) , V_31 ) ;
if ( ! V_20 )
return - V_28 ;
V_51 = V_20 ;
F_14 ( & V_2 -> V_65 ) ;
F_15 (li, tmp, &cfile->llist->locks, llist) {
if ( V_45 -> V_60 > V_56 -> V_66 ||
( V_45 -> V_60 + V_58 ) <
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
V_51 -> V_72 = F_18 ( V_56 -> V_58 ) ;
V_51 -> V_73 = F_18 ( V_56 -> V_66 ) ;
V_51 -> V_74 = F_19 ( V_75 ) ;
F_20 ( & V_56 -> V_71 , & V_62 ) ;
if ( ++ V_48 == V_47 ) {
V_46 = F_21 ( V_11 , V_13 ,
V_43 -> V_19 . V_39 ,
V_43 -> V_19 . V_40 ,
V_67 -> V_68 , V_48 , V_20 ) ;
if ( V_46 ) {
F_22 ( & V_62 ,
& V_43 -> V_71 -> V_76 ) ;
V_23 = V_46 ;
} else
F_23 ( & V_62 ) ;
V_51 = V_20 ;
V_48 = 0 ;
} else
V_51 ++ ;
}
if ( V_48 ) {
V_46 = F_21 ( V_11 , V_13 , V_43 -> V_19 . V_39 ,
V_43 -> V_19 . V_40 , V_67 -> V_68 ,
V_48 , V_20 ) ;
if ( V_46 ) {
F_22 ( & V_62 , & V_43 -> V_71 -> V_76 ) ;
V_23 = V_46 ;
} else
F_23 ( & V_62 ) ;
}
F_24 ( & V_2 -> V_65 ) ;
F_9 ( V_20 ) ;
return V_23 ;
}
static int
F_25 ( struct V_77 * V_78 , const unsigned int V_11 ,
struct V_50 * V_20 , unsigned int V_47 )
{
int V_23 = 0 , V_46 ;
struct V_42 * V_43 = V_78 -> V_43 ;
struct V_55 * V_56 ;
unsigned int V_48 = 0 ;
struct V_50 * V_51 = V_20 ;
struct V_12 * V_13 = F_11 ( V_43 -> V_52 ) ;
F_26 (li, &fdlocks->locks, llist) {
V_51 -> V_72 = F_18 ( V_56 -> V_58 ) ;
V_51 -> V_73 = F_18 ( V_56 -> V_66 ) ;
V_51 -> V_74 = F_19 ( V_56 -> type |
V_79 ) ;
if ( ++ V_48 == V_47 ) {
V_46 = F_21 ( V_11 , V_13 ,
V_43 -> V_19 . V_39 ,
V_43 -> V_19 . V_40 ,
V_67 -> V_68 , V_48 , V_20 ) ;
if ( V_46 )
V_23 = V_46 ;
V_51 = V_20 ;
V_48 = 0 ;
} else
V_51 ++ ;
}
if ( V_48 ) {
V_46 = F_21 ( V_11 , V_13 ,
V_43 -> V_19 . V_39 ,
V_43 -> V_19 . V_40 ,
V_67 -> V_68 , V_48 , V_20 ) ;
if ( V_46 )
V_23 = V_46 ;
}
return V_23 ;
}
int
F_27 ( struct V_42 * V_43 )
{
int V_23 = 0 , V_46 ;
unsigned int V_11 ;
unsigned int V_47 , V_49 ;
struct V_50 * V_20 ;
struct V_1 * V_2 = F_12 ( V_43 -> V_53 -> V_54 ) ;
struct V_77 * V_78 ;
V_11 = F_28 () ;
V_49 = F_11 ( V_43 -> V_52 ) -> V_33 -> V_34 -> V_63 ;
if ( ! V_49 ) {
F_29 ( V_11 ) ;
return - V_64 ;
}
V_47 = V_49 / sizeof( struct V_50 ) ;
V_20 = F_5 ( V_47 * sizeof( struct V_50 ) , V_31 ) ;
if ( ! V_20 ) {
F_29 ( V_11 ) ;
return - V_28 ;
}
F_26 (fdlocks, &cinode->llist, llist) {
V_46 = F_25 ( V_78 , V_11 , V_20 , V_47 ) ;
if ( V_46 )
V_23 = V_46 ;
}
F_9 ( V_20 ) ;
F_29 ( V_11 ) ;
return V_23 ;
}
