static struct V_1 *
F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_1 * V_6 )
{
struct V_7 * V_8 ;
struct V_1 * V_9 ;
struct V_10 * V_11 ;
int V_12 = sizeof( * V_11 ) ;
int V_13 = sizeof( * V_8 ) - V_12 ;
V_8 = (struct V_7 * ) V_6 -> V_14 ;
if ( V_8 -> V_15 & V_16 ) {
V_9 = V_5 -> V_6 ;
} else {
V_9 = V_6 ;
V_6 = V_5 -> V_6 ;
}
if ( F_2 ( V_6 ) < 0 || F_2 ( V_9 ) < 0 )
goto V_17;
F_3 ( V_9 , sizeof( * V_8 ) ) ;
if ( F_4 ( V_6 , 0 , V_9 -> V_18 , V_19 ) < 0 )
goto V_17;
V_5 -> V_6 = NULL ;
V_5 -> V_20 = 0 ;
F_5 ( & V_5 -> V_21 , V_3 ) ;
memcpy ( F_6 ( V_6 , V_9 -> V_18 ) , V_9 -> V_14 , V_9 -> V_18 ) ;
F_7 ( V_9 ) ;
memmove ( V_6 -> V_14 + V_13 , V_6 -> V_14 , V_12 ) ;
V_11 = (struct V_10 * ) F_3 ( V_6 ,
V_13 ) ;
V_11 -> V_22 . V_23 = V_24 ;
return V_6 ;
V_17:
F_7 ( V_5 -> V_6 ) ;
return NULL ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_8 = (struct V_7 * ) V_6 -> V_14 ;
V_5 = F_9 ( ( V_3 ) -> V_25 , F_10 ( * V_5 ) , V_21 ) ;
F_7 ( V_5 -> V_6 ) ;
V_5 -> V_20 = F_11 ( V_8 -> V_20 ) ;
V_5 -> V_6 = V_6 ;
F_12 ( & V_5 -> V_21 , V_3 ) ;
return;
}
static int F_13 ( struct V_2 * V_3 )
{
int V_26 ;
struct V_4 * V_5 ;
for ( V_26 = 0 ; V_26 < V_27 ; V_26 ++ ) {
V_5 = F_14 ( sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 ) {
F_15 ( V_3 ) ;
return - V_28 ;
}
V_5 -> V_6 = NULL ;
V_5 -> V_20 = 0 ;
F_16 ( & V_5 -> V_21 ) ;
F_17 ( & V_5 -> V_21 , V_3 ) ;
}
return 0 ;
}
static struct V_4 *
F_18 ( struct V_2 * V_3 ,
const struct V_7 * V_8 )
{
struct V_4 * V_5 ;
struct V_7 * V_29 = NULL ;
T_1 V_30 ;
if ( V_8 -> V_15 & V_16 )
V_30 = F_11 ( V_8 -> V_20 ) + 1 ;
else
V_30 = F_11 ( V_8 -> V_20 ) - 1 ;
F_19 (tfp, head, list) {
if ( ! V_5 -> V_6 )
continue;
if ( V_5 -> V_20 == F_11 ( V_8 -> V_20 ) )
goto V_31;
V_29 = (struct V_7 * ) V_5 -> V_6 -> V_14 ;
if ( V_5 -> V_20 == V_30 ) {
if ( ( V_29 -> V_15 & V_16 ) !=
( V_8 -> V_15 & V_16 ) )
return V_5 ;
else
goto V_31;
}
}
return NULL ;
V_31:
F_5 ( & V_5 -> V_21 , V_3 ) ;
return NULL ;
}
void F_15 ( struct V_2 * V_3 )
{
struct V_4 * V_32 , * V_33 ;
if ( ! F_20 ( V_3 ) ) {
F_21 (pf, tmp_pf, head, list) {
F_7 ( V_32 -> V_6 ) ;
F_22 ( & V_32 -> V_21 ) ;
F_23 ( V_32 ) ;
}
}
return;
}
int F_24 ( struct V_1 * V_6 ,
struct V_34 * V_35 ,
struct V_1 * * V_36 )
{
struct V_37 * V_38 ;
struct V_4 * V_39 ;
int V_40 = V_41 ;
struct V_7 * V_11 ;
V_11 = (struct V_7 * ) V_6 -> V_14 ;
* V_36 = NULL ;
V_38 = F_25 ( V_35 , V_11 -> V_42 ) ;
if ( ! V_38 )
goto V_43;
V_38 -> V_44 = V_45 ;
if ( F_20 ( & V_38 -> V_46 ) &&
F_13 ( & V_38 -> V_46 ) ) {
F_26 ( L_1 ) ;
goto V_43;
}
V_39 = F_18 ( & V_38 -> V_46 ,
V_11 ) ;
if ( ! V_39 ) {
F_8 ( & V_38 -> V_46 , V_6 ) ;
V_40 = V_47 ;
goto V_43;
}
* V_36 = F_1 ( & V_38 -> V_46 ,
V_39 , V_6 ) ;
if ( * V_36 )
V_40 = V_47 ;
V_43:
if ( V_38 )
F_27 ( V_38 ) ;
return V_40 ;
}
int F_28 ( struct V_1 * V_6 , struct V_34 * V_35 ,
struct V_48 * V_49 ,
const T_2 V_50 [] )
{
struct V_10 V_51 , * V_11 ;
struct V_48 * V_52 ;
struct V_1 * V_53 ;
struct V_7 * V_54 , * V_55 ;
int V_56 = sizeof( * V_11 ) ;
int V_57 = sizeof( * V_54 ) ;
int V_58 = V_6 -> V_18 - V_56 ;
int V_59 = 0 , V_40 = V_41 ;
T_1 V_20 ;
V_52 = F_29 ( V_35 ) ;
if ( ! V_52 )
goto V_60;
V_53 = F_30 ( V_58 - ( V_58 / 2 ) + V_57 ) ;
if ( ! V_53 )
goto V_60;
F_31 ( V_53 , V_57 ) ;
V_11 = (struct V_10 * ) V_6 -> V_14 ;
memcpy ( & V_51 , V_11 , V_56 ) ;
F_32 ( V_6 , V_53 , V_58 / 2 + V_56 ) ;
if ( F_33 ( V_6 , V_57 - V_56 ) < 0 ||
F_33 ( V_53 , V_57 ) < 0 )
goto V_61;
V_54 = (struct V_7 * ) V_6 -> V_14 ;
V_55 = (struct V_7 * ) V_53 -> V_14 ;
memcpy ( V_54 , & V_51 , sizeof( V_51 ) ) ;
V_54 -> V_22 . V_62 -- ;
V_54 -> V_22 . V_63 = V_64 ;
V_54 -> V_22 . V_23 = V_65 ;
memcpy ( V_54 -> V_42 , V_52 -> V_66 -> V_67 , V_68 ) ;
memcpy ( V_55 , V_54 , sizeof( * V_55 ) ) ;
if ( V_58 & 1 )
V_59 = V_69 ;
V_54 -> V_15 = V_16 | V_59 ;
V_55 -> V_15 = V_59 ;
V_20 = F_34 ( 2 , & V_49 -> V_70 ) ;
V_54 -> V_20 = F_35 ( V_20 - 1 ) ;
V_55 -> V_20 = F_35 ( V_20 ) ;
F_36 ( V_6 , V_49 , V_50 ) ;
F_36 ( V_53 , V_49 , V_50 ) ;
V_40 = V_47 ;
goto V_43;
V_61:
F_7 ( V_53 ) ;
V_60:
F_7 ( V_6 ) ;
V_43:
if ( V_52 )
F_37 ( V_52 ) ;
return V_40 ;
}
int F_38 ( struct V_1 * V_6 , struct V_34 * V_35 )
{
struct V_71 * V_71 = (struct V_71 * ) V_6 -> V_14 ;
struct V_10 * V_11 ;
struct V_37 * V_38 ;
struct V_72 * V_73 ;
int V_58 = V_6 -> V_18 ;
int V_40 = 1 ;
unsigned int V_74 ;
if ( F_39 ( V_71 -> V_75 ) ) {
V_38 = F_40 ( V_35 ) ;
if ( V_38 )
goto V_76;
}
V_38 = F_41 ( V_35 , V_71 -> V_77 ,
V_71 -> V_75 ) ;
V_76:
V_73 = F_42 ( V_35 , V_38 , NULL ) ;
if ( ! V_73 )
goto V_43;
if ( F_33 ( V_6 , sizeof( * V_11 ) ) < 0 )
goto V_43;
V_11 = (struct V_10 * ) V_6 -> V_14 ;
V_11 -> V_22 . V_63 = V_64 ;
V_11 -> V_22 . V_23 = V_24 ;
V_11 -> V_22 . V_62 = V_78 ;
memcpy ( V_11 -> V_79 , V_38 -> V_42 , V_68 ) ;
V_11 -> V_80 =
( T_2 ) F_43 ( & V_38 -> V_81 ) ;
if ( F_44 ( V_35 , V_71 -> V_75 ) )
V_11 -> V_80 = V_11 -> V_80 - 1 ;
V_74 = V_73 -> V_82 -> V_66 -> V_83 ;
if ( F_43 ( & V_35 -> V_84 ) &&
V_58 + sizeof( * V_11 ) > V_74 ) {
V_11 -> V_22 . V_62 ++ ;
V_40 = F_28 ( V_6 , V_35 ,
V_73 -> V_82 ,
V_73 -> V_85 ) ;
goto V_43;
}
F_36 ( V_6 , V_73 -> V_82 , V_73 -> V_85 ) ;
V_40 = 0 ;
goto V_43;
V_43:
if ( V_73 )
F_45 ( V_73 ) ;
if ( V_38 )
F_27 ( V_38 ) ;
if ( V_40 == 1 )
F_7 ( V_6 ) ;
return V_40 ;
}
