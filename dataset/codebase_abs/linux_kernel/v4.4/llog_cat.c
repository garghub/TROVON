static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * * V_5 ,
struct V_6 * V_7 )
{
struct V_3 * V_8 ;
int V_9 = 0 ;
if ( V_4 == NULL )
return - V_10 ;
F_2 ( & V_4 -> V_11 ) ;
F_3 (loghandle, &cathandle->u.chd.chd_head,
u.phd.phd_entry) {
struct V_6 * V_12 = & V_8 -> V_13 ;
if ( F_4 ( & V_12 -> V_14 ) == F_4 ( & V_7 -> V_14 ) &&
F_5 ( & V_12 -> V_14 ) == F_5 ( & V_7 -> V_14 ) ) {
if ( V_12 -> V_15 != V_7 -> V_15 ) {
F_6 ( L_1 V_16 L_2 ,
V_8 -> V_17 -> V_18 -> V_19 ,
F_7 ( & V_7 -> V_14 ) , V_12 -> V_15 ,
V_7 -> V_15 ) ;
continue;
}
V_8 -> V_20 . V_21 . V_22 = V_4 ;
F_8 ( & V_4 -> V_11 ) ;
V_9 = 0 ;
goto V_23;
}
}
F_8 ( & V_4 -> V_11 ) ;
V_9 = F_9 ( V_2 , V_4 -> V_17 , & V_8 , V_7 , NULL ,
V_24 ) ;
if ( V_9 < 0 ) {
F_6 ( L_3 V_16 L_4 ,
V_4 -> V_17 -> V_18 -> V_19 ,
F_7 ( & V_7 -> V_14 ) , V_7 -> V_15 , V_9 ) ;
return V_9 ;
}
V_9 = F_10 ( V_2 , V_8 , V_25 , NULL ) ;
if ( V_9 < 0 ) {
F_11 ( V_2 , V_8 ) ;
V_8 = NULL ;
return V_9 ;
}
F_2 ( & V_4 -> V_11 ) ;
F_12 ( & V_8 -> V_20 . V_21 . V_26 , & V_4 -> V_20 . V_27 . V_28 ) ;
F_8 ( & V_4 -> V_11 ) ;
V_8 -> V_20 . V_21 . V_22 = V_4 ;
V_8 -> V_20 . V_21 . V_29 . V_30 = V_4 -> V_13 ;
V_8 -> V_20 . V_21 . V_29 . V_31 =
V_8 -> V_32 -> V_33 ;
V_23:
F_13 ( V_8 ) ;
* V_5 = V_8 ;
return 0 ;
}
int F_14 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_8 , * V_34 ;
int V_9 ;
F_15 (loghandle, n, &cathandle->u.chd.chd_head,
u.phd.phd_entry) {
F_16 ( & V_8 -> V_20 . V_21 . V_26 ) ;
F_11 ( V_2 , V_8 ) ;
}
if ( V_4 -> V_17 -> V_35 == V_4 )
V_4 -> V_17 -> V_35 = NULL ;
V_9 = F_11 ( V_2 , V_4 ) ;
return V_9 ;
}
static int F_17 ( const struct V_1 * V_2 ,
struct V_3 * V_36 ,
struct V_37 * V_38 , void * V_39 )
{
struct V_40 * V_41 = V_39 ;
struct V_42 * V_43 = (struct V_42 * ) V_38 ;
struct V_3 * V_44 ;
int V_9 ;
if ( V_38 -> V_45 != V_46 ) {
F_6 ( L_5 ) ;
return - V_47 ;
}
F_18 ( V_48 , L_6 V_16 L_7
V_16 L_8 , F_7 ( & V_43 -> V_49 . V_14 ) , V_43 -> V_49 . V_15 ,
V_38 -> V_50 , F_7 ( & V_36 -> V_13 . V_14 ) ) ;
V_9 = F_1 ( V_2 , V_36 , & V_44 , & V_43 -> V_49 ) ;
if ( V_9 ) {
F_6 ( L_9 V_16 L_10 ,
V_36 -> V_17 -> V_18 -> V_19 ,
F_7 ( & V_43 -> V_49 . V_14 ) , V_9 ) ;
return V_9 ;
}
if ( V_38 -> V_50 < V_41 -> V_51 )
V_9 = 0 ;
else if ( V_41 -> V_52 > 0 ) {
struct V_53 V_54 ;
V_54 . V_55 = V_41 -> V_52 ;
V_54 . V_56 = 0 ;
V_9 = F_19 ( V_2 , V_44 , V_41 -> V_57 , V_41 -> V_58 ,
& V_54 , false ) ;
V_41 -> V_52 = 0 ;
} else {
V_9 = F_19 ( V_2 , V_44 , V_41 -> V_57 , V_41 -> V_58 ,
NULL , false ) ;
}
F_20 ( V_44 ) ;
return V_9 ;
}
static int F_21 ( const struct V_1 * V_2 ,
struct V_3 * V_36 ,
T_1 V_59 , void * V_39 , int V_60 ,
int V_61 , bool V_62 )
{
struct V_40 V_41 ;
struct V_63 * V_44 = V_36 -> V_32 ;
int V_9 ;
F_22 ( V_44 -> V_64 & V_65 ) ;
V_41 . V_58 = V_39 ;
V_41 . V_57 = V_59 ;
V_41 . V_51 = V_60 ;
V_41 . V_52 = V_61 ;
if ( V_44 -> V_33 > V_36 -> V_66 ) {
struct V_53 V_54 ;
F_23 ( L_11 V_16 L_12 ,
F_7 ( & V_36 -> V_13 . V_14 ) ) ;
V_54 . V_55 = V_44 -> V_33 ;
V_54 . V_56 = 0 ;
V_9 = F_19 ( V_2 , V_36 , F_17 ,
& V_41 , & V_54 , V_62 ) ;
if ( V_9 != 0 )
return V_9 ;
V_54 . V_55 = 0 ;
V_54 . V_56 = V_36 -> V_66 ;
V_9 = F_19 ( V_2 , V_36 , F_17 ,
& V_41 , & V_54 , V_62 ) ;
} else {
V_9 = F_19 ( V_2 , V_36 , F_17 ,
& V_41 , NULL , V_62 ) ;
}
return V_9 ;
}
int F_24 ( const struct V_1 * V_2 , struct V_3 * V_36 ,
T_1 V_59 , void * V_39 , int V_60 , int V_61 )
{
return F_21 ( V_2 , V_36 , V_59 , V_39 , V_60 ,
V_61 , false ) ;
}
