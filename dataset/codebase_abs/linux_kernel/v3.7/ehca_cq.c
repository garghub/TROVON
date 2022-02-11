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
int V_42 , V_16 , V_43 ;
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
do {
if ( ! F_21 ( & V_58 , V_48 ) ) {
V_2 = F_14 ( - V_49 ) ;
F_10 ( V_14 , L_9 ,
V_14 ) ;
goto V_59;
}
F_22 ( & V_60 , V_9 ) ;
V_16 = F_23 ( & V_58 , V_28 , & V_28 -> V_61 ) ;
F_24 ( & V_60 , V_9 ) ;
} while ( V_16 == - V_62 );
if ( V_16 ) {
V_2 = F_14 ( - V_49 ) ;
F_10 ( V_14 , L_10 ,
V_14 ) ;
goto V_59;
}
if ( V_28 -> V_61 > 0x1FFFFFF ) {
V_2 = F_14 ( - V_49 ) ;
F_10 ( V_14 , L_11 , V_14 ) ;
goto V_63;
}
V_34 . V_64 = V_21 + V_27 ;
V_41 = F_25 ( V_32 , V_28 , & V_34 ) ;
if ( V_41 != V_65 ) {
F_10 ( V_14 , L_12
L_13 , V_41 , V_14 ) ;
V_2 = F_14 ( F_26 ( V_41 ) ) ;
goto V_63;
}
V_42 = F_27 ( NULL , & V_28 -> V_66 , V_34 . V_67 ,
V_68 , sizeof( struct V_69 ) , 0 , 0 ) ;
if ( ! V_42 ) {
F_10 ( V_14 , L_14 ,
V_42 , V_14 ) ;
V_2 = F_14 ( - V_17 ) ;
goto V_70;
}
for ( V_38 = 0 ; V_38 < V_34 . V_67 ; V_38 ++ ) {
V_37 = F_28 ( & V_28 -> V_66 ) ;
if ( ! V_37 ) {
F_10 ( V_14 , L_15
L_16 , V_14 ) ;
V_2 = F_14 ( - V_62 ) ;
goto V_71;
}
V_39 = F_29 ( V_37 ) ;
V_41 = F_30 ( V_32 ,
V_28 -> V_72 ,
& V_28 -> V_73 ,
0 ,
0 ,
V_39 ,
1 ,
V_28 -> V_74 .
V_75 ) ;
if ( V_41 < V_65 ) {
F_10 ( V_14 , L_17
L_18
L_19 , V_28 , V_28 -> V_15 ,
V_41 , V_38 , V_34 . V_67 ) ;
V_2 = F_14 ( - V_17 ) ;
goto V_71;
}
if ( V_38 == ( V_34 . V_67 - 1 ) ) {
V_37 = F_28 ( & V_28 -> V_66 ) ;
if ( ( V_41 != V_65 ) || V_37 ) {
F_10 ( V_14 , L_20
L_21
L_22 , V_28 , V_28 -> V_15 ,
V_41 ) ;
V_2 = F_14 ( - V_62 ) ;
goto V_71;
}
} else {
if ( V_41 != V_76 ) {
F_10 ( V_14 , L_23
L_24
L_25 ,
V_28 , V_28 -> V_15 ,
V_41 , V_38 , V_34 . V_67 ) ;
V_2 = F_14 ( - V_49 ) ;
goto V_71;
}
}
}
F_31 ( & V_28 -> V_66 ) ;
V_36 = V_28 -> V_74 . V_75 ;
V_40 = F_32 ( V_36 , F_33 ( V_40 ) ) ;
F_5 ( V_14 , L_26 ,
V_28 , V_28 -> V_15 , V_40 ) ;
V_28 -> V_13 . V_21 = V_28 -> V_77 =
V_34 . V_78 - V_27 ;
V_28 -> V_15 = ( V_28 -> V_72 . V_79 ) & 0xffff ;
for ( V_43 = 0 ; V_43 < V_8 ; V_43 ++ )
F_34 ( & V_28 -> V_12 [ V_43 ] ) ;
F_35 ( & V_28 -> V_80 ) ;
F_35 ( & V_28 -> V_81 ) ;
if ( V_24 ) {
struct V_66 * V_66 = & V_28 -> V_66 ;
struct V_82 V_83 ;
memset ( & V_83 , 0 , sizeof( V_83 ) ) ;
V_83 . V_15 = V_28 -> V_15 ;
V_83 . V_61 = V_28 -> V_61 ;
V_83 . V_66 . V_84 = V_66 -> V_84 ;
V_83 . V_66 . V_85 = V_66 -> V_85 ;
V_83 . V_66 . V_86 = V_66 -> V_86 ;
V_83 . V_66 . V_87 = V_66 -> V_87 ;
V_83 . V_66 . V_88 = V_66 -> V_88 ;
V_83 . V_89 = ( T_1 )
( V_28 -> V_74 . V_90 . V_91 & ( V_92 - 1 ) ) ;
if ( F_36 ( V_26 , & V_83 , sizeof( V_83 ) ) ) {
F_10 ( V_14 , L_27 ) ;
goto V_71;
}
}
return V_2 ;
V_71:
F_37 ( NULL , & V_28 -> V_66 ) ;
V_70:
V_41 = F_38 ( V_32 , V_28 , 1 ) ;
if ( V_41 != V_65 )
F_10 ( V_14 , L_28
L_29 , V_28 , V_28 -> V_15 , V_41 ) ;
V_63:
F_22 ( & V_60 , V_9 ) ;
F_39 ( & V_58 , V_28 -> V_61 ) ;
F_24 ( & V_60 , V_9 ) ;
V_59:
F_40 ( V_47 , V_28 ) ;
F_17 ( & V_30 -> V_44 ) ;
return V_2 ;
}
int F_41 ( struct V_13 * V_2 )
{
T_2 V_41 ;
struct V_1 * V_28 = F_13 ( V_2 , struct V_1 , V_13 ) ;
int V_93 = V_28 -> V_15 ;
struct V_20 * V_14 = V_2 -> V_14 ;
struct V_29 * V_30 = F_13 ( V_14 , struct V_29 ,
V_20 ) ;
struct V_31 V_32 = V_30 -> V_54 ;
unsigned long V_9 ;
if ( V_2 -> V_94 ) {
if ( V_28 -> V_95 || V_28 -> V_96 ) {
F_10 ( V_14 , L_30
L_31 , V_28 -> V_15 ) ;
return - V_17 ;
}
}
F_22 ( & V_60 , V_9 ) ;
F_39 ( & V_58 , V_28 -> V_61 ) ;
F_24 ( & V_60 , V_9 ) ;
F_42 ( V_28 -> V_53 , ! F_43 ( & V_28 -> V_52 ) ) ;
V_41 = F_38 ( V_32 , V_28 , 0 ) ;
if ( V_41 == V_97 ) {
F_5 ( V_14 , L_32
L_33 ,
V_28 , V_93 , V_28 -> V_72 . V_79 ) ;
F_44 ( V_30 , V_28 , V_28 -> V_72 . V_79 ) ;
V_41 = F_38 ( V_32 , V_28 , 1 ) ;
if ( V_41 == V_65 )
F_5 ( V_14 , L_34 ,
V_93 ) ;
}
if ( V_41 != V_65 ) {
F_10 ( V_14 , L_35
L_36 , V_41 , V_28 , V_93 ) ;
return F_26 ( V_41 ) ;
}
F_37 ( NULL , & V_28 -> V_66 ) ;
F_40 ( V_47 , V_28 ) ;
F_17 ( & V_30 -> V_44 ) ;
return 0 ;
}
int F_45 ( struct V_13 * V_2 , int V_21 , struct V_25 * V_26 )
{
F_10 ( V_2 -> V_14 , L_37 ) ;
return - V_98 ;
}
int F_46 ( void )
{
V_47 = F_47 ( L_38 ,
sizeof( struct V_1 ) , 0 ,
V_99 ,
NULL ) ;
if ( ! V_47 )
return - V_49 ;
return 0 ;
}
void F_48 ( void )
{
if ( V_47 )
F_49 ( V_47 ) ;
}
