static int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_3 * * V_5 ,
struct V_6 * V_7 )
{
struct V_3 * V_8 ;
enum V_9 V_10 ;
int V_11 = 0 ;
if ( ! V_4 )
return - V_12 ;
V_10 = V_4 -> V_13 -> V_14 & V_15 ;
F_2 ( & V_4 -> V_16 ) ;
F_3 (loghandle, &cathandle->u.chd.chd_head,
u.phd.phd_entry) {
struct V_6 * V_17 = & V_8 -> V_18 ;
if ( F_4 ( & V_17 -> V_19 ) == F_4 ( & V_7 -> V_19 ) &&
F_5 ( & V_17 -> V_19 ) == F_5 ( & V_7 -> V_19 ) ) {
if ( V_17 -> V_20 != V_7 -> V_20 ) {
F_6 ( L_1 V_21 L_2 ,
V_8 -> V_22 -> V_23 -> V_24 ,
F_7 ( & V_7 -> V_19 ) , V_17 -> V_20 ,
V_7 -> V_20 ) ;
continue;
}
V_8 -> V_25 . V_26 . V_27 = V_4 ;
F_8 ( & V_4 -> V_16 ) ;
V_11 = 0 ;
goto V_28;
}
}
F_8 ( & V_4 -> V_16 ) ;
V_11 = F_9 ( V_2 , V_4 -> V_22 , & V_8 , V_7 , NULL ,
V_29 ) ;
if ( V_11 < 0 ) {
F_6 ( L_3 V_21 L_4 ,
V_4 -> V_22 -> V_23 -> V_24 ,
F_7 ( & V_7 -> V_19 ) , V_7 -> V_20 , V_11 ) ;
return V_11 ;
}
V_11 = F_10 ( V_2 , V_8 , V_10 | V_30 , NULL ) ;
if ( V_11 < 0 ) {
F_11 ( V_2 , V_8 ) ;
V_8 = NULL ;
return V_11 ;
}
F_2 ( & V_4 -> V_16 ) ;
F_12 ( & V_8 -> V_25 . V_26 . V_31 , & V_4 -> V_25 . V_32 . V_33 ) ;
F_8 ( & V_4 -> V_16 ) ;
V_8 -> V_25 . V_26 . V_27 = V_4 ;
V_8 -> V_25 . V_26 . V_34 . V_35 = V_4 -> V_18 ;
V_8 -> V_25 . V_26 . V_34 . V_36 =
V_8 -> V_13 -> V_37 ;
V_28:
F_13 ( V_8 ) ;
* V_5 = V_8 ;
return 0 ;
}
int F_14 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_8 , * V_38 ;
F_15 (loghandle, n, &cathandle->u.chd.chd_head,
u.phd.phd_entry) {
F_16 ( & V_8 -> V_25 . V_26 . V_31 ) ;
F_11 ( V_2 , V_8 ) ;
}
if ( V_4 -> V_22 -> V_39 == V_4 )
V_4 -> V_22 -> V_39 = NULL ;
return F_11 ( V_2 , V_4 ) ;
}
static int F_17 ( const struct V_1 * V_2 ,
struct V_3 * V_40 ,
struct V_41 * V_42 , void * V_43 )
{
struct V_44 * V_45 = V_43 ;
struct V_46 * V_47 = (struct V_46 * ) V_42 ;
struct V_3 * V_48 ;
int V_11 ;
if ( V_42 -> V_49 != V_50 ) {
F_6 ( L_5 ) ;
return - V_51 ;
}
F_18 ( V_52 , L_6 V_21 L_7
V_21 L_8 , F_7 ( & V_47 -> V_53 . V_19 ) , V_47 -> V_53 . V_20 ,
V_42 -> V_54 , F_7 ( & V_40 -> V_18 . V_19 ) ) ;
V_11 = F_1 ( V_2 , V_40 , & V_48 , & V_47 -> V_53 ) ;
if ( V_11 ) {
F_6 ( L_9 V_21 L_10 ,
V_40 -> V_22 -> V_23 -> V_24 ,
F_7 ( & V_47 -> V_53 . V_19 ) , V_11 ) ;
return V_11 ;
}
if ( V_42 -> V_54 < V_45 -> V_55 )
V_11 = 0 ;
else if ( V_45 -> V_56 > 0 ) {
struct V_57 V_58 ;
V_58 . V_59 = V_45 -> V_56 ;
V_58 . V_60 = 0 ;
V_11 = F_19 ( V_2 , V_48 , V_45 -> V_61 , V_45 -> V_62 ,
& V_58 , false ) ;
V_45 -> V_56 = 0 ;
} else {
V_11 = F_19 ( V_2 , V_48 , V_45 -> V_61 , V_45 -> V_62 ,
NULL , false ) ;
}
F_20 ( V_48 ) ;
return V_11 ;
}
static int F_21 ( const struct V_1 * V_2 ,
struct V_3 * V_40 ,
T_1 V_63 , void * V_43 , int V_64 ,
int V_65 , bool V_66 )
{
struct V_44 V_45 ;
struct V_67 * V_48 = V_40 -> V_13 ;
int V_11 ;
F_22 ( V_48 -> V_14 & V_68 ) ;
V_45 . V_62 = V_43 ;
V_45 . V_61 = V_63 ;
V_45 . V_55 = V_64 ;
V_45 . V_56 = V_65 ;
if ( V_48 -> V_37 > V_40 -> V_69 ) {
struct V_57 V_58 ;
F_23 ( L_11 V_21 L_12 ,
F_7 ( & V_40 -> V_18 . V_19 ) ) ;
V_58 . V_59 = V_48 -> V_37 ;
V_58 . V_60 = 0 ;
V_11 = F_19 ( V_2 , V_40 , F_17 ,
& V_45 , & V_58 , V_66 ) ;
if ( V_11 != 0 )
return V_11 ;
V_58 . V_59 = 0 ;
V_58 . V_60 = V_40 -> V_69 ;
V_11 = F_19 ( V_2 , V_40 , F_17 ,
& V_45 , & V_58 , V_66 ) ;
} else {
V_11 = F_19 ( V_2 , V_40 , F_17 ,
& V_45 , NULL , V_66 ) ;
}
return V_11 ;
}
int F_24 ( const struct V_1 * V_2 , struct V_3 * V_40 ,
T_1 V_63 , void * V_43 , int V_64 , int V_65 )
{
return F_21 ( V_2 , V_40 , V_63 , V_43 , V_64 ,
V_65 , false ) ;
}
