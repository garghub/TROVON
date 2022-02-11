static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
struct V_1 * V_6 )
{
struct V_7 * V_8 =
(struct V_7 * ) V_6 -> V_9 ;
struct V_1 * V_10 ;
struct V_11 * V_11 ;
int V_12 = sizeof( struct V_11 ) ;
int V_13 = sizeof( struct V_7 ) - V_12 ;
if ( V_8 -> V_14 & V_15 ) {
V_10 = V_5 -> V_6 ;
} else {
V_10 = V_6 ;
V_6 = V_5 -> V_6 ;
}
if ( F_2 ( V_6 ) < 0 || F_2 ( V_10 ) < 0 )
goto V_16;
F_3 ( V_10 , sizeof( struct V_7 ) ) ;
if ( F_4 ( V_6 , 0 , V_10 -> V_17 , V_18 ) < 0 )
goto V_16;
V_5 -> V_6 = NULL ;
V_5 -> V_19 = 0 ;
F_5 ( & V_5 -> V_20 , V_3 ) ;
memcpy ( F_6 ( V_6 , V_10 -> V_17 ) , V_10 -> V_9 , V_10 -> V_17 ) ;
F_7 ( V_10 ) ;
memmove ( V_6 -> V_9 + V_13 , V_6 -> V_9 , V_12 ) ;
V_11 = (struct V_11 * ) F_3 ( V_6 , V_13 ) ;
V_11 -> V_21 = V_22 ;
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
V_5 = F_9 ( ( V_3 ) -> V_23 , F_10 ( * V_5 ) , V_20 ) ;
F_7 ( V_5 -> V_6 ) ;
V_5 -> V_19 = F_11 ( V_8 -> V_19 ) ;
V_5 -> V_6 = V_6 ;
F_12 ( & V_5 -> V_20 , V_3 ) ;
return;
}
static int F_13 ( struct V_2 * V_3 )
{
int V_24 ;
struct V_4 * V_5 ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ ) {
V_5 = F_14 ( sizeof( struct V_4 ) ,
V_18 ) ;
if ( ! V_5 ) {
F_15 ( V_3 ) ;
return - V_26 ;
}
V_5 -> V_6 = NULL ;
V_5 -> V_19 = 0 ;
F_16 ( & V_5 -> V_20 ) ;
F_17 ( & V_5 -> V_20 , V_3 ) ;
}
return 0 ;
}
static struct V_4 * F_18 ( struct V_2 * V_3 ,
struct V_7 * V_8 )
{
struct V_4 * V_5 ;
struct V_7 * V_27 = NULL ;
T_1 V_28 ;
if ( V_8 -> V_14 & V_15 )
V_28 = F_11 ( V_8 -> V_19 ) + 1 ;
else
V_28 = F_11 ( V_8 -> V_19 ) - 1 ;
F_19 (tfp, head, list) {
if ( ! V_5 -> V_6 )
continue;
if ( V_5 -> V_19 == F_11 ( V_8 -> V_19 ) )
goto V_29;
V_27 = (struct V_7 * ) V_5 -> V_6 -> V_9 ;
if ( V_5 -> V_19 == V_28 ) {
if ( ( V_27 -> V_14 & V_15 ) !=
( V_8 -> V_14 & V_15 ) )
return V_5 ;
else
goto V_29;
}
}
return NULL ;
V_29:
F_5 ( & V_5 -> V_20 , V_3 ) ;
return NULL ;
}
void F_15 ( struct V_2 * V_3 )
{
struct V_4 * V_30 , * V_31 ;
if ( ! F_20 ( V_3 ) ) {
F_21 (pf, tmp_pf, head, list) {
F_7 ( V_30 -> V_6 ) ;
F_22 ( & V_30 -> V_20 ) ;
F_23 ( V_30 ) ;
}
}
return;
}
int F_24 ( struct V_1 * V_6 , struct V_32 * V_32 ,
struct V_1 * * V_33 )
{
struct V_34 * V_34 ;
struct V_4 * V_35 ;
int V_36 = V_37 ;
struct V_7 * V_11 =
(struct V_7 * ) V_6 -> V_9 ;
* V_33 = NULL ;
V_34 = F_25 ( V_32 , V_11 -> V_38 ) ;
if ( ! V_34 )
goto V_39;
V_34 -> V_40 = V_41 ;
if ( F_20 ( & V_34 -> V_42 ) &&
F_13 ( & V_34 -> V_42 ) ) {
F_26 ( L_1 ) ;
goto V_39;
}
V_35 = F_18 ( & V_34 -> V_42 ,
V_11 ) ;
if ( ! V_35 ) {
F_8 ( & V_34 -> V_42 , V_6 ) ;
V_36 = V_43 ;
goto V_39;
}
* V_33 = F_1 ( & V_34 -> V_42 , V_35 ,
V_6 ) ;
if ( * V_33 )
V_36 = V_43 ;
V_39:
if ( V_34 )
F_27 ( V_34 ) ;
return V_36 ;
}
int F_28 ( struct V_1 * V_6 , struct V_32 * V_32 ,
struct V_44 * V_44 , T_2 V_45 [] )
{
struct V_11 V_46 , * V_11 ;
struct V_44 * V_47 ;
struct V_1 * V_48 ;
struct V_7 * V_49 , * V_50 ;
int V_51 = sizeof( struct V_11 ) ;
int V_52 = sizeof( struct V_7 ) ;
int V_53 = V_6 -> V_17 - V_51 ;
int V_54 = 0 , V_36 = V_37 ;
T_1 V_19 ;
V_47 = F_29 ( V_32 ) ;
if ( ! V_47 )
goto V_55;
V_48 = F_30 ( V_53 - ( V_53 / 2 ) + V_52 ) ;
if ( ! V_48 )
goto V_55;
F_31 ( V_48 , V_52 ) ;
V_11 = (struct V_11 * ) V_6 -> V_9 ;
memcpy ( & V_46 , V_11 , V_51 ) ;
F_32 ( V_6 , V_48 , V_53 / 2 + V_51 ) ;
if ( F_33 ( V_6 , V_52 - V_51 ) < 0 ||
F_33 ( V_48 , V_52 ) < 0 )
goto V_56;
V_49 = (struct V_7 * ) V_6 -> V_9 ;
V_50 = (struct V_7 * ) V_48 -> V_9 ;
memcpy ( V_49 , & V_46 , sizeof( struct V_11 ) ) ;
V_49 -> V_57 -- ;
V_49 -> V_58 = V_59 ;
V_49 -> V_21 = V_60 ;
memcpy ( V_49 -> V_38 , V_47 -> V_61 -> V_62 , V_63 ) ;
memcpy ( V_50 , V_49 , sizeof( struct V_7 ) ) ;
if ( V_53 & 1 )
V_54 = V_64 ;
V_49 -> V_14 = V_15 | V_54 ;
V_50 -> V_14 = V_54 ;
V_19 = F_34 ( 2 , & V_44 -> V_65 ) ;
V_49 -> V_19 = F_35 ( V_19 - 1 ) ;
V_50 -> V_19 = F_35 ( V_19 ) ;
F_36 ( V_6 , V_44 , V_45 ) ;
F_36 ( V_48 , V_44 , V_45 ) ;
V_36 = V_43 ;
goto V_39;
V_56:
F_7 ( V_48 ) ;
V_55:
F_7 ( V_6 ) ;
V_39:
if ( V_47 )
F_37 ( V_47 ) ;
return V_36 ;
}
int F_38 ( struct V_1 * V_6 , struct V_32 * V_32 )
{
struct V_66 * V_66 = (struct V_66 * ) V_6 -> V_9 ;
struct V_11 * V_11 ;
struct V_34 * V_34 ;
struct V_67 * V_67 ;
int V_53 = V_6 -> V_17 ;
int V_36 = 1 ;
if ( F_39 ( V_66 -> V_68 ) ) {
V_34 = (struct V_34 * ) F_40 ( V_32 ) ;
if ( V_34 )
goto V_69;
}
V_34 = F_41 ( V_32 , V_66 -> V_68 ) ;
V_69:
V_67 = V_69 ( V_32 , V_34 , NULL ) ;
if ( ! V_67 )
goto V_39;
if ( V_67 -> V_70 -> V_71 != V_72 )
goto V_39;
if ( F_33 ( V_6 , sizeof( struct V_11 ) ) < 0 )
goto V_39;
V_11 = (struct V_11 * ) V_6 -> V_9 ;
V_11 -> V_58 = V_59 ;
V_11 -> V_21 = V_22 ;
V_11 -> V_57 = V_73 ;
memcpy ( V_11 -> V_74 , V_34 -> V_38 , V_63 ) ;
if ( F_42 ( & V_32 -> V_75 ) &&
V_53 + sizeof( struct V_11 ) >
V_67 -> V_70 -> V_61 -> V_76 ) {
V_11 -> V_57 ++ ;
V_36 = F_28 ( V_6 , V_32 ,
V_67 -> V_70 , V_67 -> V_77 ) ;
goto V_39;
}
F_36 ( V_6 , V_67 -> V_70 , V_67 -> V_77 ) ;
V_36 = 0 ;
goto V_39;
V_39:
if ( V_67 )
F_43 ( V_67 ) ;
if ( V_34 )
F_27 ( V_34 ) ;
if ( V_36 == 1 )
F_7 ( V_6 ) ;
return V_36 ;
}
