static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_1 * V_6 )
{
struct V_7 * V_8 =
(struct V_7 * ) V_6 -> V_9 ;
struct V_1 * V_10 ;
struct V_11 * V_11 ;
int V_12 = sizeof( * V_11 ) ;
int V_13 = sizeof( * V_8 ) - V_12 ;
if ( V_8 -> V_14 & V_15 ) {
V_10 = V_5 -> V_6 ;
} else {
V_10 = V_6 ;
V_6 = V_5 -> V_6 ;
}
if ( F_2 ( V_6 ) < 0 || F_2 ( V_10 ) < 0 )
goto V_16;
F_3 ( V_10 , sizeof( * V_8 ) ) ;
if ( F_4 ( V_6 , 0 , V_10 -> V_17 , V_18 ) < 0 )
goto V_16;
V_5 -> V_6 = NULL ;
V_5 -> V_19 = 0 ;
F_5 ( & V_5 -> V_20 , V_3 ) ;
memcpy ( F_6 ( V_6 , V_10 -> V_17 ) , V_10 -> V_9 , V_10 -> V_17 ) ;
F_7 ( V_10 ) ;
memmove ( V_6 -> V_9 + V_13 , V_6 -> V_9 , V_12 ) ;
V_11 = (struct V_11 * ) F_3 ( V_6 , V_13 ) ;
V_11 -> V_21 . V_22 = V_23 ;
return V_6 ;
V_16:
F_7 ( V_5 -> V_6 ) ;
return NULL ;
}
static void F_8 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_4 * V_5 ;
struct V_7 * V_8 =
(struct V_7 * ) V_6 -> V_9 ;
V_5 = F_9 ( ( V_3 ) -> V_24 , F_10 ( * V_5 ) , V_20 ) ;
F_7 ( V_5 -> V_6 ) ;
V_5 -> V_19 = F_11 ( V_8 -> V_19 ) ;
V_5 -> V_6 = V_6 ;
F_12 ( & V_5 -> V_20 , V_3 ) ;
return;
}
static int F_13 ( struct V_2 * V_3 )
{
int V_25 ;
struct V_4 * V_5 ;
for ( V_25 = 0 ; V_25 < V_26 ; V_25 ++ ) {
V_5 = F_14 ( sizeof( * V_5 ) , V_18 ) ;
if ( ! V_5 ) {
F_15 ( V_3 ) ;
return - V_27 ;
}
V_5 -> V_6 = NULL ;
V_5 -> V_19 = 0 ;
F_16 ( & V_5 -> V_20 ) ;
F_17 ( & V_5 -> V_20 , V_3 ) ;
}
return 0 ;
}
static struct V_4 * F_18 ( struct V_2 * V_3 ,
const struct V_7 * V_8 )
{
struct V_4 * V_5 ;
struct V_7 * V_28 = NULL ;
T_1 V_29 ;
if ( V_8 -> V_14 & V_15 )
V_29 = F_11 ( V_8 -> V_19 ) + 1 ;
else
V_29 = F_11 ( V_8 -> V_19 ) - 1 ;
F_19 (tfp, head, list) {
if ( ! V_5 -> V_6 )
continue;
if ( V_5 -> V_19 == F_11 ( V_8 -> V_19 ) )
goto V_30;
V_28 = (struct V_7 * ) V_5 -> V_6 -> V_9 ;
if ( V_5 -> V_19 == V_29 ) {
if ( ( V_28 -> V_14 & V_15 ) !=
( V_8 -> V_14 & V_15 ) )
return V_5 ;
else
goto V_30;
}
}
return NULL ;
V_30:
F_5 ( & V_5 -> V_20 , V_3 ) ;
return NULL ;
}
void F_15 ( struct V_2 * V_3 )
{
struct V_4 * V_31 , * V_32 ;
if ( ! F_20 ( V_3 ) ) {
F_21 (pf, tmp_pf, head, list) {
F_7 ( V_31 -> V_6 ) ;
F_22 ( & V_31 -> V_20 ) ;
F_23 ( V_31 ) ;
}
}
return;
}
int F_24 ( struct V_1 * V_6 , struct V_33 * V_33 ,
struct V_1 * * V_34 )
{
struct V_35 * V_35 ;
struct V_4 * V_36 ;
int V_37 = V_38 ;
struct V_7 * V_11 =
(struct V_7 * ) V_6 -> V_9 ;
* V_34 = NULL ;
V_35 = F_25 ( V_33 , V_11 -> V_39 ) ;
if ( ! V_35 )
goto V_40;
V_35 -> V_41 = V_42 ;
if ( F_20 ( & V_35 -> V_43 ) &&
F_13 ( & V_35 -> V_43 ) ) {
F_26 ( L_1 ) ;
goto V_40;
}
V_36 = F_18 ( & V_35 -> V_43 ,
V_11 ) ;
if ( ! V_36 ) {
F_8 ( & V_35 -> V_43 , V_6 ) ;
V_37 = V_44 ;
goto V_40;
}
* V_34 = F_1 ( & V_35 -> V_43 , V_36 ,
V_6 ) ;
if ( * V_34 )
V_37 = V_44 ;
V_40:
if ( V_35 )
F_27 ( V_35 ) ;
return V_37 ;
}
int F_28 ( struct V_1 * V_6 , struct V_33 * V_33 ,
struct V_45 * V_45 , const T_2 V_46 [] )
{
struct V_11 V_47 , * V_11 ;
struct V_45 * V_48 ;
struct V_1 * V_49 ;
struct V_7 * V_50 , * V_51 ;
int V_52 = sizeof( * V_11 ) ;
int V_53 = sizeof( * V_50 ) ;
int V_54 = V_6 -> V_17 - V_52 ;
int V_55 = 0 , V_37 = V_38 ;
T_1 V_19 ;
V_48 = F_29 ( V_33 ) ;
if ( ! V_48 )
goto V_56;
V_49 = F_30 ( V_54 - ( V_54 / 2 ) + V_53 ) ;
if ( ! V_49 )
goto V_56;
F_31 ( V_49 , V_53 ) ;
V_11 = (struct V_11 * ) V_6 -> V_9 ;
memcpy ( & V_47 , V_11 , V_52 ) ;
F_32 ( V_6 , V_49 , V_54 / 2 + V_52 ) ;
if ( F_33 ( V_6 , V_53 - V_52 ) < 0 ||
F_33 ( V_49 , V_53 ) < 0 )
goto V_57;
V_50 = (struct V_7 * ) V_6 -> V_9 ;
V_51 = (struct V_7 * ) V_49 -> V_9 ;
memcpy ( V_50 , & V_47 , sizeof( V_47 ) ) ;
V_50 -> V_21 . V_58 -- ;
V_50 -> V_21 . V_59 = V_60 ;
V_50 -> V_21 . V_22 = V_61 ;
memcpy ( V_50 -> V_39 , V_48 -> V_62 -> V_63 , V_64 ) ;
memcpy ( V_51 , V_50 , sizeof( * V_51 ) ) ;
if ( V_54 & 1 )
V_55 = V_65 ;
V_50 -> V_14 = V_15 | V_55 ;
V_51 -> V_14 = V_55 ;
V_19 = F_34 ( 2 , & V_45 -> V_66 ) ;
V_50 -> V_19 = F_35 ( V_19 - 1 ) ;
V_51 -> V_19 = F_35 ( V_19 ) ;
F_36 ( V_6 , V_45 , V_46 ) ;
F_36 ( V_49 , V_45 , V_46 ) ;
V_37 = V_44 ;
goto V_40;
V_57:
F_7 ( V_49 ) ;
V_56:
F_7 ( V_6 ) ;
V_40:
if ( V_48 )
F_37 ( V_48 ) ;
return V_37 ;
}
int F_38 ( struct V_1 * V_6 , struct V_33 * V_33 )
{
struct V_67 * V_67 = (struct V_67 * ) V_6 -> V_9 ;
struct V_11 * V_11 ;
struct V_35 * V_35 ;
struct V_68 * V_68 ;
int V_54 = V_6 -> V_17 ;
int V_37 = 1 ;
if ( F_39 ( V_67 -> V_69 ) ) {
V_35 = F_40 ( V_33 ) ;
if ( V_35 )
goto V_70;
}
V_35 = F_41 ( V_33 , V_67 -> V_71 ,
V_67 -> V_69 ) ;
V_70:
V_68 = V_70 ( V_33 , V_35 , NULL ) ;
if ( ! V_68 )
goto V_40;
if ( F_33 ( V_6 , sizeof( * V_11 ) ) < 0 )
goto V_40;
V_11 = (struct V_11 * ) V_6 -> V_9 ;
V_11 -> V_21 . V_59 = V_60 ;
V_11 -> V_21 . V_22 = V_23 ;
V_11 -> V_21 . V_58 = V_72 ;
memcpy ( V_11 -> V_73 , V_35 -> V_39 , V_64 ) ;
V_11 -> V_74 =
( T_2 ) F_42 ( & V_35 -> V_75 ) ;
if ( F_42 ( & V_33 -> V_76 ) &&
V_54 + sizeof( * V_11 ) >
V_68 -> V_77 -> V_62 -> V_78 ) {
V_11 -> V_21 . V_58 ++ ;
V_37 = F_28 ( V_6 , V_33 ,
V_68 -> V_77 , V_68 -> V_79 ) ;
goto V_40;
}
F_36 ( V_6 , V_68 -> V_77 , V_68 -> V_79 ) ;
V_37 = 0 ;
goto V_40;
V_40:
if ( V_68 )
F_43 ( V_68 ) ;
if ( V_35 )
F_27 ( V_35 ) ;
if ( V_37 == 1 )
F_7 ( V_6 ) ;
return V_37 ;
}
