static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
F_3 ( & V_4 -> V_6 ) ;
F_4 ( & V_4 -> V_7 , & V_2 -> V_8 ) ;
F_5 ( & V_2 -> V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_7 ( & V_4 -> V_6 ) ;
F_2 ( & V_2 -> V_5 ) ;
F_8 ( & V_4 -> V_7 ) ;
F_9 ( & V_4 -> V_6 ) ;
F_4 ( & V_4 -> V_7 , & V_2 -> V_8 ) ;
F_5 ( & V_2 -> V_5 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_11 (w, &cq->waiters, list_node) {
if ( ! F_12 ( & V_4 -> V_6 ) ) {
F_13 ( & V_4 -> V_6 ) ;
break;
}
}
}
static void F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
F_8 ( & V_4 -> V_7 ) ;
F_10 ( V_2 ) ;
if ( F_12 ( & V_4 -> V_6 ) )
F_10 ( V_2 ) ;
F_5 ( & V_2 -> V_5 ) ;
}
static struct V_9 * F_15 ( struct V_10 * V_11 ,
T_1 V_12 )
{
struct V_9 * V_13 ;
F_11 (sess, &ctxdata->sess_list, list_node)
if ( V_13 -> V_12 == V_12 )
return V_13 ;
return NULL ;
}
T_1 F_16 ( struct V_14 * V_15 , T_2 V_16 )
{
struct V_17 * V_17 = F_17 ( V_15 -> V_18 ) ;
struct V_3 V_4 ;
struct V_19 V_20 = { } ;
T_1 V_21 ;
V_20 . V_22 = V_23 ;
F_18 ( & V_20 . V_24 , & V_20 . V_25 , V_16 ) ;
F_1 ( & V_17 -> V_26 , & V_4 ) ;
while ( true ) {
struct V_27 V_28 ;
V_17 -> V_29 ( V_20 . V_22 , V_20 . V_24 , V_20 . V_25 , V_20 . V_30 ,
V_20 . V_31 , V_20 . V_32 , V_20 . V_33 , V_20 . V_34 ,
& V_28 ) ;
if ( V_28 . V_22 == V_35 ) {
F_6 ( & V_17 -> V_26 , & V_4 ) ;
} else if ( F_19 ( V_28 . V_22 ) ) {
V_20 . V_22 = V_28 . V_22 ;
V_20 . V_24 = V_28 . V_24 ;
V_20 . V_25 = V_28 . V_25 ;
V_20 . V_30 = V_28 . V_30 ;
F_20 ( V_15 , & V_20 ) ;
} else {
V_21 = V_28 . V_22 ;
break;
}
}
F_14 ( & V_17 -> V_26 , & V_4 ) ;
return V_21 ;
}
static struct V_36 * F_21 ( struct V_14 * V_15 , T_3 V_37 ,
struct V_38 * * V_39 ,
T_2 * V_40 )
{
int V_41 ;
struct V_36 * V_42 ;
struct V_38 * V_43 ;
V_42 = F_22 ( V_15 , F_23 ( V_37 ) ,
V_44 ) ;
if ( F_24 ( V_42 ) )
return V_42 ;
V_43 = F_25 ( V_42 , 0 ) ;
if ( F_24 ( V_43 ) ) {
V_41 = F_26 ( V_43 ) ;
goto V_45;
}
V_41 = F_27 ( V_42 , 0 , V_40 ) ;
if ( V_41 )
goto V_45;
memset ( V_43 , 0 , F_23 ( V_37 ) ) ;
V_43 -> V_37 = V_37 ;
* V_39 = V_43 ;
V_45:
if ( V_41 ) {
F_28 ( V_42 ) ;
return F_29 ( V_41 ) ;
}
return V_42 ;
}
int F_30 ( struct V_14 * V_15 ,
struct V_46 * V_47 ,
struct V_48 * V_20 )
{
struct V_10 * V_11 = V_15 -> V_49 ;
int V_41 ;
struct V_36 * V_42 ;
struct V_38 * V_39 ;
T_2 V_40 ;
struct V_9 * V_13 = NULL ;
V_42 = F_21 ( V_15 , V_47 -> V_37 + 2 , & V_39 , & V_40 ) ;
if ( F_24 ( V_42 ) )
return F_26 ( V_42 ) ;
V_39 -> V_50 = V_51 ;
V_39 -> V_52 = V_47 -> V_52 ;
V_39 -> V_53 [ 0 ] . V_54 = V_55 |
V_56 ;
V_39 -> V_53 [ 1 ] . V_54 = V_55 |
V_56 ;
memcpy ( & V_39 -> V_53 [ 0 ] . V_57 . V_58 , V_47 -> V_59 , sizeof( V_47 -> V_59 ) ) ;
memcpy ( & V_39 -> V_53 [ 1 ] . V_57 . V_58 , V_47 -> V_59 , sizeof( V_47 -> V_60 ) ) ;
V_39 -> V_53 [ 1 ] . V_57 . V_58 . V_6 = V_47 -> V_61 ;
V_41 = F_31 ( V_39 -> V_53 + 2 , V_47 -> V_37 , V_20 ) ;
if ( V_41 )
goto V_45;
V_13 = F_32 ( sizeof( * V_13 ) , V_62 ) ;
if ( ! V_13 ) {
V_41 = - V_63 ;
goto V_45;
}
if ( F_16 ( V_15 , V_40 ) ) {
V_39 -> V_21 = V_64 ;
V_39 -> V_65 = V_66 ;
}
if ( V_39 -> V_21 == V_67 ) {
V_13 -> V_12 = V_39 -> V_68 ;
F_2 ( & V_11 -> V_5 ) ;
F_33 ( & V_13 -> V_7 , & V_11 -> V_69 ) ;
F_5 ( & V_11 -> V_5 ) ;
} else {
F_34 ( V_13 ) ;
}
if ( F_35 ( V_20 , V_47 -> V_37 , V_39 -> V_53 + 2 ) ) {
V_47 -> V_21 = V_64 ;
V_47 -> V_65 = V_66 ;
F_36 ( V_15 , V_39 -> V_68 ) ;
} else {
V_47 -> V_68 = V_39 -> V_68 ;
V_47 -> V_21 = V_39 -> V_21 ;
V_47 -> V_65 = V_39 -> V_65 ;
}
V_45:
F_28 ( V_42 ) ;
return V_41 ;
}
int F_36 ( struct V_14 * V_15 , T_1 V_68 )
{
struct V_10 * V_11 = V_15 -> V_49 ;
struct V_36 * V_42 ;
struct V_38 * V_39 ;
T_2 V_40 ;
struct V_9 * V_13 ;
F_2 ( & V_11 -> V_5 ) ;
V_13 = F_15 ( V_11 , V_68 ) ;
if ( V_13 )
F_8 ( & V_13 -> V_7 ) ;
F_5 ( & V_11 -> V_5 ) ;
if ( ! V_13 )
return - V_70 ;
F_34 ( V_13 ) ;
V_42 = F_21 ( V_15 , 0 , & V_39 , & V_40 ) ;
if ( F_24 ( V_42 ) )
return F_26 ( V_42 ) ;
V_39 -> V_50 = V_71 ;
V_39 -> V_68 = V_68 ;
F_16 ( V_15 , V_40 ) ;
F_28 ( V_42 ) ;
return 0 ;
}
int F_37 ( struct V_14 * V_15 , struct V_72 * V_47 ,
struct V_48 * V_20 )
{
struct V_10 * V_11 = V_15 -> V_49 ;
struct V_36 * V_42 ;
struct V_38 * V_39 ;
T_2 V_40 ;
struct V_9 * V_13 ;
int V_41 ;
F_2 ( & V_11 -> V_5 ) ;
V_13 = F_15 ( V_11 , V_47 -> V_68 ) ;
F_5 ( & V_11 -> V_5 ) ;
if ( ! V_13 )
return - V_70 ;
V_42 = F_21 ( V_15 , V_47 -> V_37 , & V_39 , & V_40 ) ;
if ( F_24 ( V_42 ) )
return F_26 ( V_42 ) ;
V_39 -> V_50 = V_73 ;
V_39 -> V_74 = V_47 -> V_74 ;
V_39 -> V_68 = V_47 -> V_68 ;
V_39 -> V_52 = V_47 -> V_52 ;
V_41 = F_31 ( V_39 -> V_53 , V_47 -> V_37 , V_20 ) ;
if ( V_41 )
goto V_45;
if ( F_16 ( V_15 , V_40 ) ) {
V_39 -> V_21 = V_64 ;
V_39 -> V_65 = V_66 ;
}
if ( F_35 ( V_20 , V_47 -> V_37 , V_39 -> V_53 ) ) {
V_39 -> V_21 = V_64 ;
V_39 -> V_65 = V_66 ;
}
V_47 -> V_21 = V_39 -> V_21 ;
V_47 -> V_65 = V_39 -> V_65 ;
V_45:
F_28 ( V_42 ) ;
return V_41 ;
}
int F_38 ( struct V_14 * V_15 , T_1 V_52 , T_1 V_68 )
{
struct V_10 * V_11 = V_15 -> V_49 ;
struct V_36 * V_42 ;
struct V_38 * V_39 ;
T_2 V_40 ;
struct V_9 * V_13 ;
F_2 ( & V_11 -> V_5 ) ;
V_13 = F_15 ( V_11 , V_68 ) ;
F_5 ( & V_11 -> V_5 ) ;
if ( ! V_13 )
return - V_70 ;
V_42 = F_21 ( V_15 , 0 , & V_39 , & V_40 ) ;
if ( F_24 ( V_42 ) )
return F_26 ( V_42 ) ;
V_39 -> V_50 = V_75 ;
V_39 -> V_68 = V_68 ;
V_39 -> V_52 = V_52 ;
F_16 ( V_15 , V_40 ) ;
F_28 ( V_42 ) ;
return 0 ;
}
void F_39 ( struct V_17 * V_17 )
{
struct V_3 V_4 ;
F_1 ( & V_17 -> V_26 , & V_4 ) ;
while ( true ) {
struct V_27 V_28 ;
V_17 -> V_29 ( V_76 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , & V_28 ) ;
if ( V_28 . V_22 == V_77 )
break;
F_6 ( & V_17 -> V_26 , & V_4 ) ;
}
F_14 ( & V_17 -> V_26 , & V_4 ) ;
}
void F_40 ( struct V_17 * V_17 )
{
struct V_3 V_4 ;
F_1 ( & V_17 -> V_26 , & V_4 ) ;
while ( true ) {
union {
struct V_27 V_78 ;
struct V_79 V_80 ;
} V_28 ;
V_17 -> V_29 ( V_81 , 0 , 0 , 0 , 0 , 0 , 0 ,
0 , & V_28 . V_78 ) ;
if ( V_28 . V_80 . V_82 == V_83 )
break;
if ( V_28 . V_80 . V_82 == V_77 ) {
struct V_36 * V_42 ;
V_42 = F_41 ( V_28 . V_80 . V_84 ,
V_28 . V_80 . V_85 ) ;
F_28 ( V_42 ) ;
} else {
F_6 ( & V_17 -> V_26 , & V_4 ) ;
}
}
F_14 ( & V_17 -> V_26 , & V_4 ) ;
}
