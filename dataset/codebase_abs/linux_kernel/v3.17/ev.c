static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
struct V_5 V_6 ;
V_4 = F_2 ( V_2 -> V_7 . V_8 . V_9 [ 0 ] , V_3 ,
( V_10 * ) & V_6 ) ;
if ( V_4 ) {
F_3 ( & V_2 -> V_7 . V_8 . V_11 -> V_2 ,
L_1 , V_12 , V_4 ) ;
return;
}
F_4 ( L_2
L_3 ,
V_3 & 0xffffff00 ,
F_5 ( F_6 ( V_6 . V_13 ) ) ,
F_7 ( F_6 ( V_6 . V_13 ) ) ,
F_8 ( F_6 ( V_6 . V_13 ) ) ,
F_9 ( F_6 ( V_6 . V_13 ) ) ,
F_10 ( F_6 ( V_6 . V_14 ) ) ,
F_11 ( F_6 ( V_6 . V_14 ) ) ,
( ( V_15 ) F_6 ( V_6 . V_16 ) << 32 ) | F_6 ( V_6 . V_17 ) ,
( ( V_15 ) F_6 ( V_6 . V_18 ) << 32 ) | F_6 ( V_6 . V_19 ) ) ;
}
static void F_12 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
T_2 * V_22 = ( void * ) V_21 ;
F_3 ( & V_2 -> V_7 . V_8 . V_11 -> V_2 ,
L_4
L_5 ,
F_13 ( V_21 ) , F_14 ( V_21 ) ,
F_15 ( V_21 ) , F_16 ( V_21 ) , F_6 ( V_21 -> V_23 ) ,
F_17 ( V_21 ) , F_18 ( V_21 ) ) ;
F_4 ( L_6 ,
F_19 ( V_22 [ 0 ] ) , F_19 ( V_22 [ 1 ] ) , F_19 ( V_22 [ 2 ] ) ,
F_19 ( V_22 [ 3 ] ) ) ;
if ( F_20 ( V_21 ) && ( F_14 ( V_21 ) == V_24 ||
F_14 ( V_21 ) == V_25 ) )
F_1 ( V_2 , F_21 ( V_21 ) ) ;
}
static void F_22 ( struct V_1 * V_2 , struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_20 * V_21 ,
enum V_30 V_31 )
{
struct V_31 V_32 ;
struct V_33 V_34 ;
unsigned long V_35 ;
F_12 ( V_2 , V_21 ) ;
if ( V_29 -> V_36 . V_37 == V_38 ) {
V_34 . V_39 = V_40 ;
F_23 ( V_29 -> V_41 , V_29 , V_42 ,
& V_34 , 0 ) ;
}
V_32 . V_32 = V_31 ;
V_32 . V_43 = V_27 -> V_44 . V_43 ;
if ( V_31 == V_45 )
V_32 . V_46 . V_47 = & V_27 -> V_44 ;
else
V_32 . V_46 . V_48 = & V_29 -> V_49 ;
if ( V_29 -> V_49 . V_50 )
(* V_29 -> V_49 . V_50 )( & V_32 , V_29 -> V_49 . V_51 ) ;
F_24 ( & V_27 -> V_52 , V_35 ) ;
(* V_27 -> V_44 . V_53 )( & V_27 -> V_44 , V_27 -> V_44 . V_54 ) ;
F_25 ( & V_27 -> V_52 , V_35 ) ;
}
void F_26 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
struct V_26 * V_27 ;
struct V_28 * V_29 ;
T_1 V_55 ;
F_27 ( & V_2 -> V_56 ) ;
V_29 = F_28 ( V_2 , F_13 ( V_21 ) ) ;
if ( ! V_29 ) {
F_29 (KERN_ERR MOD L_7
L_8 ,
CQE_QPID(err_cqe),
CQE_OPCODE(err_cqe), CQE_STATUS(err_cqe),
CQE_TYPE(err_cqe), CQE_WRID_HI(err_cqe),
CQE_WRID_LOW(err_cqe)) ;
F_30 ( & V_2 -> V_56 ) ;
goto V_57;
}
if ( F_31 ( V_21 ) )
V_55 = V_29 -> V_36 . V_58 ;
else
V_55 = V_29 -> V_36 . V_59 ;
V_27 = F_32 ( V_2 , V_55 ) ;
if ( ! V_27 ) {
F_29 (KERN_ERR MOD L_9
L_8 ,
cqid, CQE_QPID(err_cqe),
CQE_OPCODE(err_cqe), CQE_STATUS(err_cqe),
CQE_TYPE(err_cqe), CQE_WRID_HI(err_cqe),
CQE_WRID_LOW(err_cqe)) ;
F_30 ( & V_2 -> V_56 ) ;
goto V_57;
}
F_33 ( & V_29 -> V_49 ) ;
F_34 ( & V_27 -> V_60 ) ;
F_30 ( & V_2 -> V_56 ) ;
if ( F_20 ( V_21 ) &&
( F_14 ( V_21 ) == V_24 ) ) {
F_22 ( V_2 , V_27 , V_29 , V_21 , V_61 ) ;
goto V_62;
}
switch ( F_15 ( V_21 ) ) {
case V_63 :
F_29 (KERN_ERR MOD L_10 ) ;
break;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
F_22 ( V_2 , V_27 , V_29 , V_21 , V_72 ) ;
break;
case V_73 :
case V_74 :
case V_75 :
F_22 ( V_2 , V_27 , V_29 , V_21 , V_76 ) ;
break;
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
case V_89 :
case V_90 :
case V_91 :
case V_92 :
F_22 ( V_2 , V_27 , V_29 , V_21 , V_93 ) ;
break;
default:
F_29 (KERN_ERR MOD L_11 ,
CQE_STATUS(err_cqe), qhp->wq.sq.qid) ;
F_22 ( V_2 , V_27 , V_29 , V_21 , V_93 ) ;
break;
}
V_62:
if ( F_35 ( & V_27 -> V_60 ) )
F_36 ( & V_27 -> V_94 ) ;
F_37 ( & V_29 -> V_49 ) ;
V_57:
return;
}
int F_38 ( struct V_1 * V_2 , T_1 V_95 )
{
struct V_26 * V_27 ;
unsigned long V_35 ;
V_27 = F_32 ( V_2 , V_95 ) ;
if ( V_27 ) {
F_39 ( & V_27 -> V_47 ) ;
F_24 ( & V_27 -> V_52 , V_35 ) ;
(* V_27 -> V_44 . V_53 )( & V_27 -> V_44 , V_27 -> V_44 . V_54 ) ;
F_25 ( & V_27 -> V_52 , V_35 ) ;
} else
F_4 ( L_12 , V_12 , V_95 ) ;
return 0 ;
}
