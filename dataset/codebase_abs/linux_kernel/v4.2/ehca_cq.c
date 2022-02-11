int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned int V_5 = V_4 -> V_6 ;
unsigned int V_7 = V_5 & ( V_8 - 1 ) ;
unsigned long V_9 ;
F_2 ( & V_2 -> V_10 , V_9 ) ;
F_3 ( & V_4 -> V_11 , & V_2 -> V_12 [ V_7 ] ) ;
F_4 ( & V_2 -> V_10 , V_9 ) ;
F_5 ( V_2 -> V_13 . V_14 , L_1 ,
V_2 -> V_15 , V_5 ) ;
return 0 ;
}
int F_6 ( struct V_1 * V_2 , unsigned int V_6 )
{
int V_16 = - V_17 ;
unsigned int V_7 = V_6 & ( V_8 - 1 ) ;
struct V_18 * V_19 ;
struct V_3 * V_4 ;
unsigned long V_9 ;
F_2 ( & V_2 -> V_10 , V_9 ) ;
F_7 (iter, &cq->qp_hashtab[key]) {
V_4 = F_8 ( V_19 , struct V_3 , V_11 ) ;
if ( V_4 -> V_6 == V_6 ) {
F_9 ( V_19 ) ;
F_5 ( V_2 -> V_13 . V_14 ,
L_2 ,
V_2 -> V_15 , V_6 ) ;
V_16 = 0 ;
break;
}
}
F_4 ( & V_2 -> V_10 , V_9 ) ;
if ( V_16 )
F_10 ( V_2 -> V_13 . V_14 ,
L_3 ,
V_2 -> V_15 , V_6 ) ;
return V_16 ;
}
struct V_3 * F_11 ( struct V_1 * V_2 , int V_6 )
{
struct V_3 * V_16 = NULL ;
unsigned int V_7 = V_6 & ( V_8 - 1 ) ;
struct V_18 * V_19 ;
struct V_3 * V_4 ;
F_7 (iter, &cq->qp_hashtab[key]) {
V_4 = F_8 ( V_19 , struct V_3 , V_11 ) ;
if ( V_4 -> V_6 == V_6 ) {
V_16 = V_4 ;
break;
}
}
return V_16 ;
}
struct V_13 * F_12 ( struct V_20 * V_14 ,
const struct V_21 * V_22 ,
struct V_23 * V_24 ,
struct V_25 * V_26 )
{
int V_27 = V_22 -> V_27 ;
static const T_1 V_28 = 20 ;
struct V_13 * V_2 ;
struct V_1 * V_29 ;
struct V_30 * V_31 =
F_13 ( V_14 , struct V_30 , V_20 ) ;
struct V_32 V_33 ;
struct V_34 V_35 ;
struct V_36 V_37 ;
void * V_38 ;
T_1 V_39 ;
T_2 V_40 , V_41 , V_42 ;
int V_43 , V_44 ;
unsigned long V_9 ;
if ( V_22 -> V_9 )
return F_14 ( - V_17 ) ;
if ( V_27 >= 0xFFFFFFFF - 64 - V_28 )
return F_14 ( - V_17 ) ;
if ( ! F_15 ( & V_31 -> V_45 , 1 , V_31 -> V_46 ) ) {
F_10 ( V_14 , L_4
L_5 , V_31 -> V_46 ) ;
F_10 ( V_14 , L_6
L_7 ) ;
return F_14 ( - V_47 ) ;
}
V_29 = F_16 ( V_48 , V_49 ) ;
if ( ! V_29 ) {
F_10 ( V_14 , L_8 ,
V_14 ) ;
F_17 ( & V_31 -> V_45 ) ;
return F_14 ( - V_50 ) ;
}
memset ( & V_35 , 0 , sizeof( struct V_34 ) ) ;
F_18 ( & V_29 -> V_10 ) ;
F_18 ( & V_29 -> V_51 ) ;
F_18 ( & V_29 -> V_52 ) ;
F_19 ( & V_29 -> V_53 , 0 ) ;
F_20 ( & V_29 -> V_54 ) ;
V_2 = & V_29 -> V_13 ;
V_33 = V_31 -> V_55 ;
V_35 . V_56 = V_31 -> V_57 . V_58 ;
F_21 ( V_49 ) ;
F_22 ( & V_59 , V_9 ) ;
V_29 -> V_60 = F_23 ( & V_61 , V_29 , 0 , 0x2000000 , V_62 ) ;
F_24 ( & V_59 , V_9 ) ;
F_25 () ;
if ( V_29 -> V_60 < 0 ) {
V_2 = F_14 ( - V_50 ) ;
F_10 ( V_14 , L_9 ,
V_14 ) ;
goto V_63;
}
V_35 . V_64 = V_27 + V_28 ;
V_42 = F_26 ( V_33 , V_29 , & V_35 ) ;
if ( V_42 != V_65 ) {
F_10 ( V_14 , L_10
L_11 , V_42 , V_14 ) ;
V_2 = F_14 ( F_27 ( V_42 ) ) ;
goto V_66;
}
V_43 = F_28 ( NULL , & V_29 -> V_67 , V_35 . V_68 ,
V_69 , sizeof( struct V_70 ) , 0 , 0 ) ;
if ( ! V_43 ) {
F_10 ( V_14 , L_12 ,
V_43 , V_14 ) ;
V_2 = F_14 ( - V_17 ) ;
goto V_71;
}
for ( V_39 = 0 ; V_39 < V_35 . V_68 ; V_39 ++ ) {
V_38 = F_29 ( & V_29 -> V_67 ) ;
if ( ! V_38 ) {
F_10 ( V_14 , L_13
L_14 , V_14 ) ;
V_2 = F_14 ( - V_72 ) ;
goto V_73;
}
V_40 = F_30 ( V_38 ) ;
V_42 = F_31 ( V_33 ,
V_29 -> V_74 ,
& V_29 -> V_75 ,
0 ,
0 ,
V_40 ,
1 ,
V_29 -> V_76 .
V_77 ) ;
if ( V_42 < V_65 ) {
F_10 ( V_14 , L_15
L_16
L_17 , V_29 , V_29 -> V_15 ,
V_42 , V_39 , V_35 . V_68 ) ;
V_2 = F_14 ( - V_17 ) ;
goto V_73;
}
if ( V_39 == ( V_35 . V_68 - 1 ) ) {
V_38 = F_29 ( & V_29 -> V_67 ) ;
if ( ( V_42 != V_65 ) || V_38 ) {
F_10 ( V_14 , L_18
L_19
L_20 , V_29 , V_29 -> V_15 ,
V_42 ) ;
V_2 = F_14 ( - V_72 ) ;
goto V_73;
}
} else {
if ( V_42 != V_78 ) {
F_10 ( V_14 , L_21
L_22
L_23 ,
V_29 , V_29 -> V_15 ,
V_42 , V_39 , V_35 . V_68 ) ;
V_2 = F_14 ( - V_50 ) ;
goto V_73;
}
}
}
F_32 ( & V_29 -> V_67 ) ;
V_37 = V_29 -> V_76 . V_77 ;
V_41 = F_33 ( V_37 , F_34 ( V_41 ) ) ;
F_5 ( V_14 , L_24 ,
V_29 , V_29 -> V_15 , V_41 ) ;
V_29 -> V_13 . V_27 = V_29 -> V_79 =
V_35 . V_80 - V_28 ;
V_29 -> V_15 = ( V_29 -> V_74 . V_81 ) & 0xffff ;
for ( V_44 = 0 ; V_44 < V_8 ; V_44 ++ )
F_35 ( & V_29 -> V_12 [ V_44 ] ) ;
F_36 ( & V_29 -> V_82 ) ;
F_36 ( & V_29 -> V_83 ) ;
if ( V_24 ) {
struct V_67 * V_67 = & V_29 -> V_67 ;
struct V_84 V_85 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_15 = V_29 -> V_15 ;
V_85 . V_60 = V_29 -> V_60 ;
V_85 . V_67 . V_86 = V_67 -> V_86 ;
V_85 . V_67 . V_87 = V_67 -> V_87 ;
V_85 . V_67 . V_88 = V_67 -> V_88 ;
V_85 . V_67 . V_89 = V_67 -> V_89 ;
V_85 . V_67 . V_90 = V_67 -> V_90 ;
V_85 . V_91 = ( T_1 )
( V_29 -> V_76 . V_92 . V_93 & ( V_94 - 1 ) ) ;
if ( F_37 ( V_26 , & V_85 , sizeof( V_85 ) ) ) {
F_10 ( V_14 , L_25 ) ;
V_2 = F_14 ( - V_95 ) ;
goto V_73;
}
}
return V_2 ;
V_73:
F_38 ( NULL , & V_29 -> V_67 ) ;
V_71:
V_42 = F_39 ( V_33 , V_29 , 1 ) ;
if ( V_42 != V_65 )
F_10 ( V_14 , L_26
L_27 , V_29 , V_29 -> V_15 , V_42 ) ;
V_66:
F_22 ( & V_59 , V_9 ) ;
F_40 ( & V_61 , V_29 -> V_60 ) ;
F_24 ( & V_59 , V_9 ) ;
V_63:
F_41 ( V_48 , V_29 ) ;
F_17 ( & V_31 -> V_45 ) ;
return V_2 ;
}
int F_42 ( struct V_13 * V_2 )
{
T_2 V_42 ;
struct V_1 * V_29 = F_13 ( V_2 , struct V_1 , V_13 ) ;
int V_96 = V_29 -> V_15 ;
struct V_20 * V_14 = V_2 -> V_14 ;
struct V_30 * V_31 = F_13 ( V_14 , struct V_30 ,
V_20 ) ;
struct V_32 V_33 = V_31 -> V_55 ;
unsigned long V_9 ;
if ( V_2 -> V_97 ) {
if ( V_29 -> V_98 || V_29 -> V_99 ) {
F_10 ( V_14 , L_28
L_29 , V_29 -> V_15 ) ;
return - V_17 ;
}
}
F_22 ( & V_59 , V_9 ) ;
F_40 ( & V_61 , V_29 -> V_60 ) ;
F_24 ( & V_59 , V_9 ) ;
F_43 ( V_29 -> V_54 , ! F_44 ( & V_29 -> V_53 ) ) ;
V_42 = F_39 ( V_33 , V_29 , 0 ) ;
if ( V_42 == V_100 ) {
F_5 ( V_14 , L_30
L_31 ,
V_29 , V_96 , V_29 -> V_74 . V_81 ) ;
F_45 ( V_31 , V_29 , V_29 -> V_74 . V_81 ) ;
V_42 = F_39 ( V_33 , V_29 , 1 ) ;
if ( V_42 == V_65 )
F_5 ( V_14 , L_32 ,
V_96 ) ;
}
if ( V_42 != V_65 ) {
F_10 ( V_14 , L_33
L_34 , V_42 , V_29 , V_96 ) ;
return F_27 ( V_42 ) ;
}
F_38 ( NULL , & V_29 -> V_67 ) ;
F_41 ( V_48 , V_29 ) ;
F_17 ( & V_31 -> V_45 ) ;
return 0 ;
}
int F_46 ( struct V_13 * V_2 , int V_27 , struct V_25 * V_26 )
{
F_10 ( V_2 -> V_14 , L_35 ) ;
return - V_95 ;
}
int F_47 ( void )
{
V_48 = F_48 ( L_36 ,
sizeof( struct V_1 ) , 0 ,
V_101 ,
NULL ) ;
if ( ! V_48 )
return - V_50 ;
return 0 ;
}
void F_49 ( void )
{
if ( V_48 )
F_50 ( V_48 ) ;
}
