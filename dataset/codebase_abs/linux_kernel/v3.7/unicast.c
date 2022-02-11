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
T_1 * V_14 ;
V_8 = (struct V_7 * ) V_6 -> V_15 ;
if ( V_8 -> V_16 & V_17 ) {
V_9 = V_5 -> V_6 ;
} else {
V_9 = V_6 ;
V_6 = V_5 -> V_6 ;
}
if ( F_2 ( V_6 ) < 0 || F_2 ( V_9 ) < 0 )
goto V_18;
F_3 ( V_9 , sizeof( * V_8 ) ) ;
if ( F_4 ( V_6 , 0 , V_9 -> V_19 , V_20 ) < 0 )
goto V_18;
V_5 -> V_6 = NULL ;
V_5 -> V_21 = 0 ;
F_5 ( & V_5 -> V_22 , V_3 ) ;
memcpy ( F_6 ( V_6 , V_9 -> V_19 ) , V_9 -> V_15 , V_9 -> V_19 ) ;
F_7 ( V_9 ) ;
memmove ( V_6 -> V_15 + V_13 , V_6 -> V_15 , V_12 ) ;
V_14 = F_3 ( V_6 , V_13 ) ;
V_11 = (struct V_10 * ) V_14 ;
V_11 -> V_23 . V_24 = V_25 ;
return V_6 ;
V_18:
F_7 ( V_5 -> V_6 ) ;
return NULL ;
}
static void F_8 ( struct V_2 * V_3 ,
struct V_1 * V_6 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 ;
V_8 = (struct V_7 * ) V_6 -> V_15 ;
V_5 = F_9 ( ( V_3 ) -> V_26 , F_10 ( * V_5 ) , V_22 ) ;
F_7 ( V_5 -> V_6 ) ;
V_5 -> V_21 = F_11 ( V_8 -> V_21 ) ;
V_5 -> V_6 = V_6 ;
F_12 ( & V_5 -> V_22 , V_3 ) ;
return;
}
static int F_13 ( struct V_2 * V_3 )
{
int V_27 ;
struct V_4 * V_5 ;
for ( V_27 = 0 ; V_27 < V_28 ; V_27 ++ ) {
V_5 = F_14 ( sizeof( * V_5 ) , V_20 ) ;
if ( ! V_5 ) {
F_15 ( V_3 ) ;
return - V_29 ;
}
V_5 -> V_6 = NULL ;
V_5 -> V_21 = 0 ;
F_16 ( & V_5 -> V_22 ) ;
F_17 ( & V_5 -> V_22 , V_3 ) ;
}
return 0 ;
}
static struct V_4 *
F_18 ( struct V_2 * V_3 ,
const struct V_7 * V_8 )
{
struct V_4 * V_5 ;
struct V_7 * V_30 = NULL ;
int V_31 , V_32 ;
T_2 V_33 ;
if ( V_8 -> V_16 & V_17 )
V_33 = F_11 ( V_8 -> V_21 ) + 1 ;
else
V_33 = F_11 ( V_8 -> V_21 ) - 1 ;
V_32 = ! ! ( V_8 -> V_16 & V_17 ) ;
F_19 (tfp, head, list) {
if ( ! V_5 -> V_6 )
continue;
if ( V_5 -> V_21 == F_11 ( V_8 -> V_21 ) )
goto V_34;
V_30 = (struct V_7 * ) V_5 -> V_6 -> V_15 ;
if ( V_5 -> V_21 == V_33 ) {
V_31 = ! ! ( V_30 -> V_16 & V_17 ) ;
if ( V_31 != V_32 )
return V_5 ;
else
goto V_34;
}
}
return NULL ;
V_34:
F_5 ( & V_5 -> V_22 , V_3 ) ;
return NULL ;
}
void F_15 ( struct V_2 * V_3 )
{
struct V_4 * V_35 , * V_36 ;
if ( ! F_20 ( V_3 ) ) {
F_21 (pf, tmp_pf, head, list) {
F_7 ( V_35 -> V_6 ) ;
F_22 ( & V_35 -> V_22 ) ;
F_23 ( V_35 ) ;
}
}
return;
}
int F_24 ( struct V_1 * V_6 ,
struct V_37 * V_38 ,
struct V_1 * * V_39 )
{
struct V_40 * V_41 ;
struct V_4 * V_42 ;
int V_43 = V_44 ;
struct V_7 * V_11 ;
V_11 = (struct V_7 * ) V_6 -> V_15 ;
* V_39 = NULL ;
V_41 = F_25 ( V_38 , V_11 -> V_45 ) ;
if ( ! V_41 )
goto V_46;
V_41 -> V_47 = V_48 ;
if ( F_20 ( & V_41 -> V_49 ) &&
F_13 ( & V_41 -> V_49 ) ) {
F_26 ( L_1 ) ;
goto V_46;
}
V_42 = F_18 ( & V_41 -> V_49 ,
V_11 ) ;
if ( ! V_42 ) {
F_8 ( & V_41 -> V_49 , V_6 ) ;
V_43 = V_50 ;
goto V_46;
}
* V_39 = F_1 ( & V_41 -> V_49 ,
V_42 , V_6 ) ;
if ( * V_39 )
V_43 = V_50 ;
V_46:
if ( V_41 )
F_27 ( V_41 ) ;
return V_43 ;
}
int F_28 ( struct V_1 * V_6 , struct V_37 * V_38 ,
struct V_51 * V_52 ,
const T_1 V_53 [] )
{
struct V_10 V_54 , * V_11 ;
struct V_51 * V_55 ;
struct V_1 * V_56 ;
struct V_7 * V_57 , * V_58 ;
int V_59 = sizeof( * V_11 ) ;
int V_60 = sizeof( * V_57 ) ;
int V_61 = V_6 -> V_19 - V_59 ;
int V_62 = 0 , V_43 = V_44 ;
T_2 V_21 ;
V_55 = F_29 ( V_38 ) ;
if ( ! V_55 )
goto V_63;
V_56 = F_30 ( V_61 - ( V_61 / 2 ) + V_60 ) ;
if ( ! V_56 )
goto V_63;
F_31 ( V_56 , V_60 ) ;
V_11 = (struct V_10 * ) V_6 -> V_15 ;
memcpy ( & V_54 , V_11 , V_59 ) ;
F_32 ( V_6 , V_56 , V_61 / 2 + V_59 ) ;
if ( F_33 ( V_6 , V_60 - V_59 ) < 0 ||
F_33 ( V_56 , V_60 ) < 0 )
goto V_64;
V_57 = (struct V_7 * ) V_6 -> V_15 ;
V_58 = (struct V_7 * ) V_56 -> V_15 ;
memcpy ( V_57 , & V_54 , sizeof( V_54 ) ) ;
V_57 -> V_23 . V_65 -- ;
V_57 -> V_23 . V_66 = V_67 ;
V_57 -> V_23 . V_24 = V_68 ;
memcpy ( V_57 -> V_45 , V_55 -> V_69 -> V_70 , V_71 ) ;
memcpy ( V_58 , V_57 , sizeof( * V_58 ) ) ;
if ( V_61 & 1 )
V_62 = V_72 ;
V_57 -> V_16 = V_17 | V_62 ;
V_58 -> V_16 = V_62 ;
V_21 = F_34 ( 2 , & V_52 -> V_73 ) ;
V_57 -> V_21 = F_35 ( V_21 - 1 ) ;
V_58 -> V_21 = F_35 ( V_21 ) ;
F_36 ( V_6 , V_52 , V_53 ) ;
F_36 ( V_56 , V_52 , V_53 ) ;
V_43 = V_50 ;
goto V_46;
V_64:
F_7 ( V_56 ) ;
V_63:
F_7 ( V_6 ) ;
V_46:
if ( V_55 )
F_37 ( V_55 ) ;
return V_43 ;
}
int F_38 ( struct V_1 * V_6 , struct V_37 * V_38 )
{
struct V_74 * V_74 = (struct V_74 * ) V_6 -> V_15 ;
struct V_10 * V_11 ;
struct V_40 * V_41 ;
struct V_75 * V_76 ;
int V_61 = V_6 -> V_19 ;
int V_43 = 1 ;
unsigned int V_77 ;
if ( F_39 ( V_74 -> V_78 ) ) {
V_41 = F_40 ( V_38 ) ;
if ( V_41 )
goto V_79;
}
V_41 = F_41 ( V_38 , V_74 -> V_80 ,
V_74 -> V_78 ) ;
V_79:
V_76 = F_42 ( V_38 , V_41 , NULL ) ;
if ( ! V_76 )
goto V_46;
if ( F_33 ( V_6 , sizeof( * V_11 ) ) < 0 )
goto V_46;
V_11 = (struct V_10 * ) V_6 -> V_15 ;
V_11 -> V_23 . V_66 = V_67 ;
V_11 -> V_23 . V_24 = V_25 ;
V_11 -> V_23 . V_65 = V_81 ;
memcpy ( V_11 -> V_82 , V_41 -> V_45 , V_71 ) ;
V_11 -> V_83 = ( T_1 ) F_43 ( & V_41 -> V_84 ) ;
if ( F_44 ( V_38 , V_74 -> V_78 ) )
V_11 -> V_83 = V_11 -> V_83 - 1 ;
V_77 = V_76 -> V_85 -> V_69 -> V_86 ;
if ( F_43 ( & V_38 -> V_87 ) &&
V_61 + sizeof( * V_11 ) > V_77 ) {
V_11 -> V_23 . V_65 ++ ;
V_43 = F_28 ( V_6 , V_38 ,
V_76 -> V_85 ,
V_76 -> V_88 ) ;
goto V_46;
}
F_36 ( V_6 , V_76 -> V_85 , V_76 -> V_88 ) ;
V_43 = 0 ;
goto V_46;
V_46:
if ( V_76 )
F_45 ( V_76 ) ;
if ( V_41 )
F_27 ( V_41 ) ;
if ( V_43 == 1 )
F_7 ( V_6 ) ;
return V_43 ;
}
