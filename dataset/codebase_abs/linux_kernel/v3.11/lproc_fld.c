static int
F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
struct V_7 * V_8 ;
V_9 ;
F_2 ( V_5 != NULL ) ;
F_3 ( & V_5 -> V_10 ) ;
F_4 (target,
&fld->lcf_targets, ft_chain)
F_5 ( V_2 , L_1 , F_6 ( V_8 ) ) ;
F_7 ( & V_5 -> V_10 ) ;
RETURN ( 0 ) ;
}
static int
F_8 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = (struct V_4 * ) V_2 -> V_6 ;
V_9 ;
F_2 ( V_5 != NULL ) ;
F_3 ( & V_5 -> V_10 ) ;
F_5 ( V_2 , L_1 , V_5 -> V_11 -> V_12 ) ;
F_7 ( & V_5 -> V_10 ) ;
RETURN ( 0 ) ;
}
static T_1
F_9 ( struct V_13 * V_13 , const char * V_14 ,
T_2 V_15 , T_3 * V_16 )
{
struct V_4 * V_5 = ( (struct V_1 * ) V_13 -> V_17 ) -> V_6 ;
struct V_18 * V_19 = NULL ;
int V_20 ;
V_9 ;
F_2 ( V_5 != NULL ) ;
for ( V_20 = 0 ; V_21 [ V_20 ] . V_12 != NULL ; V_20 ++ ) {
if ( V_15 != strlen ( V_21 [ V_20 ] . V_12 ) )
continue;
if ( ! strncmp ( V_21 [ V_20 ] . V_12 , V_14 , V_15 ) ) {
V_19 = & V_21 [ V_20 ] ;
break;
}
}
if ( V_19 != NULL ) {
F_3 ( & V_5 -> V_10 ) ;
V_5 -> V_11 = V_19 ;
F_7 ( & V_5 -> V_10 ) ;
F_10 ( V_22 , L_2 ,
V_5 -> V_23 , V_19 -> V_12 ) ;
}
RETURN ( V_15 ) ;
}
static T_1
F_11 ( struct V_13 * V_13 , const char T_4 * V_14 ,
T_2 V_15 , T_3 * V_24 )
{
struct V_4 * V_5 = V_13 -> V_17 ;
V_9 ;
F_2 ( V_5 != NULL ) ;
F_12 ( V_5 -> V_25 ) ;
F_10 ( V_22 , L_3 , V_5 -> V_23 ) ;
RETURN ( V_15 ) ;
}
static int F_13 ( struct V_26 * V_26 , struct V_13 * V_13 )
{
V_13 -> V_17 = F_14 ( V_26 ) ;
return 0 ;
}
static int F_15 ( struct V_26 * V_26 , struct V_13 * V_13 )
{
V_13 -> V_17 = NULL ;
return 0 ;
}
static void * F_16 ( struct V_1 * V_27 , T_3 * V_24 )
{
struct V_28 * V_29 = V_27 -> V_6 ;
struct V_30 * V_5 ;
struct V_31 * V_32 ;
const struct V_33 * V_34 ;
if ( V_29 == NULL || V_29 -> V_35 )
return NULL ;
V_5 = V_29 -> V_36 ;
V_32 = V_5 -> V_37 ;
F_2 ( V_32 != NULL ) ;
V_34 = & V_32 -> V_38 -> V_39 ;
V_34 -> V_40 ( & V_29 -> V_41 , V_29 -> V_42 , * V_24 ) ;
* V_24 = F_17 ( * ( V_43 * ) V_34 -> V_44 ( & V_29 -> V_41 , V_29 -> V_42 ) ) ;
return V_29 ;
}
static void F_18 ( struct V_1 * V_27 , void * V_45 )
{
struct V_28 * V_29 = V_27 -> V_6 ;
const struct V_33 * V_34 ;
struct V_30 * V_5 ;
struct V_31 * V_32 ;
if ( V_29 == NULL )
return;
V_5 = V_29 -> V_36 ;
V_32 = V_5 -> V_37 ;
F_2 ( V_32 != NULL ) ;
V_34 = & V_32 -> V_38 -> V_39 ;
V_34 -> V_46 ( & V_29 -> V_41 , V_29 -> V_42 ) ;
}
static void * F_19 ( struct V_1 * V_27 , void * V_45 , T_3 * V_24 )
{
struct V_28 * V_29 = V_27 -> V_6 ;
struct V_30 * V_5 ;
struct V_31 * V_32 ;
const struct V_33 * V_34 ;
int V_47 ;
if ( V_29 == NULL || V_29 -> V_35 )
return NULL ;
V_5 = V_29 -> V_36 ;
V_32 = V_5 -> V_37 ;
F_2 ( V_32 != NULL ) ;
V_34 = & V_32 -> V_38 -> V_39 ;
V_47 = V_34 -> V_48 ( & V_29 -> V_41 , V_29 -> V_42 ) ;
if ( V_47 > 0 ) {
V_29 -> V_35 = 1 ;
return NULL ;
}
* V_24 = F_17 ( * ( V_43 * ) V_34 -> V_44 ( & V_29 -> V_41 , V_29 -> V_42 ) ) ;
return V_29 ;
}
static int F_20 ( struct V_1 * V_27 , void * V_45 )
{
struct V_28 * V_29 = V_27 -> V_6 ;
struct V_30 * V_5 ;
struct V_31 * V_32 ;
const struct V_33 * V_34 ;
struct V_49 * V_50 ;
struct V_51 * V_52 ;
int V_47 ;
if ( V_29 == NULL || V_29 -> V_35 )
return 0 ;
V_5 = V_29 -> V_36 ;
V_32 = V_5 -> V_37 ;
F_2 ( V_32 != NULL ) ;
V_34 = & V_32 -> V_38 -> V_39 ;
V_50 = F_21 ( & V_29 -> V_41 . V_53 ,
& V_54 ) ;
V_52 = & V_50 -> V_55 ;
V_47 = V_34 -> V_56 ( & V_29 -> V_41 , V_29 -> V_42 ,
(struct V_57 * ) V_52 , 0 ) ;
if ( V_47 != 0 ) {
F_22 ( L_4 ,
V_5 -> V_58 , V_47 ) ;
} else if ( V_52 -> V_59 != 0 ) {
F_23 ( V_52 , V_52 ) ;
V_47 = F_5 ( V_27 , V_60 L_5 , F_24 ( V_52 ) ) ;
}
return V_47 ;
}
static int F_25 ( struct V_26 * V_26 , struct V_13 * V_13 )
{
struct V_1 * V_61 ;
struct V_30 * V_5 = (struct V_30 * ) F_14 ( V_26 ) ;
struct V_31 * V_32 ;
const struct V_33 * V_34 ;
struct V_28 * V_29 = NULL ;
int V_62 = 0 ;
int V_47 ;
V_47 = F_26 ( V_13 , & V_63 ) ;
if ( V_47 )
GOTO ( V_64 , V_47 ) ;
V_32 = V_5 -> V_37 ;
if ( V_32 == NULL ) {
V_61 = V_13 -> V_17 ;
V_61 -> V_6 = NULL ;
return 0 ;
}
F_27 ( V_29 ) ;
if ( V_29 == NULL )
GOTO ( V_64 , V_47 = - V_65 ) ;
V_47 = F_28 ( & V_29 -> V_41 , V_66 ) ;
if ( V_47 != 0 )
GOTO ( V_64 , V_47 ) ;
V_62 = 1 ;
V_34 = & V_32 -> V_38 -> V_39 ;
V_29 -> V_42 = V_34 -> V_67 ( & V_29 -> V_41 , V_32 , 0 , NULL ) ;
if ( F_29 ( V_29 -> V_42 ) )
GOTO ( V_64 , V_47 = F_30 ( V_29 -> V_42 ) ) ;
V_29 -> V_36 = V_5 ;
V_29 -> V_35 = 0 ;
V_61 = V_13 -> V_17 ;
V_61 -> V_6 = V_29 ;
V_64:
if ( V_47 != 0 ) {
if ( V_62 == 1 )
F_31 ( & V_29 -> V_41 ) ;
if ( V_29 != NULL )
F_32 ( V_29 ) ;
}
return V_47 ;
}
static int F_33 ( struct V_26 * V_26 , struct V_13 * V_13 )
{
struct V_1 * V_61 = V_13 -> V_17 ;
struct V_28 * V_29 ;
struct V_30 * V_5 ;
struct V_31 * V_32 ;
const struct V_33 * V_34 ;
V_29 = V_61 -> V_6 ;
if ( V_29 == NULL ) {
F_34 ( V_26 , V_13 ) ;
return 0 ;
}
V_5 = V_29 -> V_36 ;
V_32 = V_5 -> V_37 ;
F_2 ( V_32 != NULL ) ;
V_34 = & V_32 -> V_38 -> V_39 ;
F_2 ( V_34 != NULL ) ;
F_2 ( V_32 != NULL ) ;
F_2 ( V_29 -> V_42 != NULL ) ;
V_34 -> V_68 ( & V_29 -> V_41 , V_29 -> V_42 ) ;
F_31 ( & V_29 -> V_41 ) ;
F_32 ( V_29 ) ;
F_34 ( V_26 , V_13 ) ;
return 0 ;
}
