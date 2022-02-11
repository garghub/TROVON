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
struct V_13 * F_12 ( struct V_20 * V_14 , int V_21 , int V_22 ,
struct V_23 * V_24 ,
struct V_25 * V_26 )
{
static const T_1 V_27 = 20 ;
struct V_13 * V_2 ;
struct V_1 * V_28 ;
struct V_29 * V_30 =
F_13 ( V_14 , struct V_29 , V_20 ) ;
struct V_31 V_32 ;
struct V_33 V_34 ;
struct V_35 V_36 ;
void * V_37 ;
T_1 V_38 ;
T_2 V_39 , V_40 , V_41 ;
int V_42 , V_43 ;
unsigned long V_9 ;
if ( V_21 >= 0xFFFFFFFF - 64 - V_27 )
return F_14 ( - V_17 ) ;
if ( ! F_15 ( & V_30 -> V_44 , 1 , V_30 -> V_45 ) ) {
F_10 ( V_14 , L_4
L_5 , V_30 -> V_45 ) ;
F_10 ( V_14 , L_6
L_7 ) ;
return F_14 ( - V_46 ) ;
}
V_28 = F_16 ( V_47 , V_48 ) ;
if ( ! V_28 ) {
F_10 ( V_14 , L_8 ,
V_14 ) ;
F_17 ( & V_30 -> V_44 ) ;
return F_14 ( - V_49 ) ;
}
memset ( & V_34 , 0 , sizeof( struct V_33 ) ) ;
F_18 ( & V_28 -> V_10 ) ;
F_18 ( & V_28 -> V_50 ) ;
F_18 ( & V_28 -> V_51 ) ;
F_19 ( & V_28 -> V_52 , 0 ) ;
F_20 ( & V_28 -> V_53 ) ;
V_2 = & V_28 -> V_13 ;
V_32 = V_30 -> V_54 ;
V_34 . V_55 = V_30 -> V_56 . V_57 ;
F_21 ( V_48 ) ;
F_22 ( & V_58 , V_9 ) ;
V_28 -> V_59 = F_23 ( & V_60 , V_28 , 0 , 0x2000000 , V_61 ) ;
F_24 ( & V_58 , V_9 ) ;
F_25 () ;
if ( V_28 -> V_59 < 0 ) {
V_2 = F_14 ( - V_49 ) ;
F_10 ( V_14 , L_9 ,
V_14 ) ;
goto V_62;
}
V_34 . V_63 = V_21 + V_27 ;
V_41 = F_26 ( V_32 , V_28 , & V_34 ) ;
if ( V_41 != V_64 ) {
F_10 ( V_14 , L_10
L_11 , V_41 , V_14 ) ;
V_2 = F_14 ( F_27 ( V_41 ) ) ;
goto V_65;
}
V_42 = F_28 ( NULL , & V_28 -> V_66 , V_34 . V_67 ,
V_68 , sizeof( struct V_69 ) , 0 , 0 ) ;
if ( ! V_42 ) {
F_10 ( V_14 , L_12 ,
V_42 , V_14 ) ;
V_2 = F_14 ( - V_17 ) ;
goto V_70;
}
for ( V_38 = 0 ; V_38 < V_34 . V_67 ; V_38 ++ ) {
V_37 = F_29 ( & V_28 -> V_66 ) ;
if ( ! V_37 ) {
F_10 ( V_14 , L_13
L_14 , V_14 ) ;
V_2 = F_14 ( - V_71 ) ;
goto V_72;
}
V_39 = F_30 ( V_37 ) ;
V_41 = F_31 ( V_32 ,
V_28 -> V_73 ,
& V_28 -> V_74 ,
0 ,
0 ,
V_39 ,
1 ,
V_28 -> V_75 .
V_76 ) ;
if ( V_41 < V_64 ) {
F_10 ( V_14 , L_15
L_16
L_17 , V_28 , V_28 -> V_15 ,
V_41 , V_38 , V_34 . V_67 ) ;
V_2 = F_14 ( - V_17 ) ;
goto V_72;
}
if ( V_38 == ( V_34 . V_67 - 1 ) ) {
V_37 = F_29 ( & V_28 -> V_66 ) ;
if ( ( V_41 != V_64 ) || V_37 ) {
F_10 ( V_14 , L_18
L_19
L_20 , V_28 , V_28 -> V_15 ,
V_41 ) ;
V_2 = F_14 ( - V_71 ) ;
goto V_72;
}
} else {
if ( V_41 != V_77 ) {
F_10 ( V_14 , L_21
L_22
L_23 ,
V_28 , V_28 -> V_15 ,
V_41 , V_38 , V_34 . V_67 ) ;
V_2 = F_14 ( - V_49 ) ;
goto V_72;
}
}
}
F_32 ( & V_28 -> V_66 ) ;
V_36 = V_28 -> V_75 . V_76 ;
V_40 = F_33 ( V_36 , F_34 ( V_40 ) ) ;
F_5 ( V_14 , L_24 ,
V_28 , V_28 -> V_15 , V_40 ) ;
V_28 -> V_13 . V_21 = V_28 -> V_78 =
V_34 . V_79 - V_27 ;
V_28 -> V_15 = ( V_28 -> V_73 . V_80 ) & 0xffff ;
for ( V_43 = 0 ; V_43 < V_8 ; V_43 ++ )
F_35 ( & V_28 -> V_12 [ V_43 ] ) ;
F_36 ( & V_28 -> V_81 ) ;
F_36 ( & V_28 -> V_82 ) ;
if ( V_24 ) {
struct V_66 * V_66 = & V_28 -> V_66 ;
struct V_83 V_84 ;
memset ( & V_84 , 0 , sizeof( V_84 ) ) ;
V_84 . V_15 = V_28 -> V_15 ;
V_84 . V_59 = V_28 -> V_59 ;
V_84 . V_66 . V_85 = V_66 -> V_85 ;
V_84 . V_66 . V_86 = V_66 -> V_86 ;
V_84 . V_66 . V_87 = V_66 -> V_87 ;
V_84 . V_66 . V_88 = V_66 -> V_88 ;
V_84 . V_66 . V_89 = V_66 -> V_89 ;
V_84 . V_90 = ( T_1 )
( V_28 -> V_75 . V_91 . V_92 & ( V_93 - 1 ) ) ;
if ( F_37 ( V_26 , & V_84 , sizeof( V_84 ) ) ) {
F_10 ( V_14 , L_25 ) ;
goto V_72;
}
}
return V_2 ;
V_72:
F_38 ( NULL , & V_28 -> V_66 ) ;
V_70:
V_41 = F_39 ( V_32 , V_28 , 1 ) ;
if ( V_41 != V_64 )
F_10 ( V_14 , L_26
L_27 , V_28 , V_28 -> V_15 , V_41 ) ;
V_65:
F_22 ( & V_58 , V_9 ) ;
F_40 ( & V_60 , V_28 -> V_59 ) ;
F_24 ( & V_58 , V_9 ) ;
V_62:
F_41 ( V_47 , V_28 ) ;
F_17 ( & V_30 -> V_44 ) ;
return V_2 ;
}
int F_42 ( struct V_13 * V_2 )
{
T_2 V_41 ;
struct V_1 * V_28 = F_13 ( V_2 , struct V_1 , V_13 ) ;
int V_94 = V_28 -> V_15 ;
struct V_20 * V_14 = V_2 -> V_14 ;
struct V_29 * V_30 = F_13 ( V_14 , struct V_29 ,
V_20 ) ;
struct V_31 V_32 = V_30 -> V_54 ;
unsigned long V_9 ;
if ( V_2 -> V_95 ) {
if ( V_28 -> V_96 || V_28 -> V_97 ) {
F_10 ( V_14 , L_28
L_29 , V_28 -> V_15 ) ;
return - V_17 ;
}
}
F_22 ( & V_58 , V_9 ) ;
F_40 ( & V_60 , V_28 -> V_59 ) ;
F_24 ( & V_58 , V_9 ) ;
F_43 ( V_28 -> V_53 , ! F_44 ( & V_28 -> V_52 ) ) ;
V_41 = F_39 ( V_32 , V_28 , 0 ) ;
if ( V_41 == V_98 ) {
F_5 ( V_14 , L_30
L_31 ,
V_28 , V_94 , V_28 -> V_73 . V_80 ) ;
F_45 ( V_30 , V_28 , V_28 -> V_73 . V_80 ) ;
V_41 = F_39 ( V_32 , V_28 , 1 ) ;
if ( V_41 == V_64 )
F_5 ( V_14 , L_32 ,
V_94 ) ;
}
if ( V_41 != V_64 ) {
F_10 ( V_14 , L_33
L_34 , V_41 , V_28 , V_94 ) ;
return F_27 ( V_41 ) ;
}
F_38 ( NULL , & V_28 -> V_66 ) ;
F_41 ( V_47 , V_28 ) ;
F_17 ( & V_30 -> V_44 ) ;
return 0 ;
}
int F_46 ( struct V_13 * V_2 , int V_21 , struct V_25 * V_26 )
{
F_10 ( V_2 -> V_14 , L_35 ) ;
return - V_99 ;
}
int F_47 ( void )
{
V_47 = F_48 ( L_36 ,
sizeof( struct V_1 ) , 0 ,
V_100 ,
NULL ) ;
if ( ! V_47 )
return - V_49 ;
return 0 ;
}
void F_49 ( void )
{
if ( V_47 )
F_50 ( V_47 ) ;
}
