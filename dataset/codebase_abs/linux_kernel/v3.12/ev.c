static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
enum V_9 V_10 )
{
struct V_10 V_11 ;
struct V_12 V_13 ;
unsigned long V_14 ;
F_2 (KERN_ERR MOD L_1
L_2 ,
CQE_QPID(err_cqe), CQE_OPCODE(err_cqe),
CQE_STATUS(err_cqe), CQE_TYPE(err_cqe),
CQE_WRID_HI(err_cqe), CQE_WRID_LOW(err_cqe)) ;
if ( V_6 -> V_15 . V_16 == V_17 ) {
V_13 . V_18 = V_19 ;
F_3 ( V_6 -> V_20 , V_6 , V_21 ,
& V_13 , 0 ) ;
}
V_11 . V_11 = V_10 ;
V_11 . V_22 = V_4 -> V_23 . V_22 ;
if ( V_10 == V_24 )
V_11 . V_25 . V_26 = & V_4 -> V_23 ;
else
V_11 . V_25 . V_27 = & V_6 -> V_28 ;
if ( V_6 -> V_28 . V_29 )
(* V_6 -> V_28 . V_29 )( & V_11 , V_6 -> V_28 . V_30 ) ;
F_4 ( & V_4 -> V_31 , V_14 ) ;
(* V_4 -> V_23 . V_32 )( & V_4 -> V_23 , V_4 -> V_23 . V_33 ) ;
F_5 ( & V_4 -> V_31 , V_14 ) ;
}
void F_6 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_1 V_34 ;
F_7 ( & V_2 -> V_35 ) ;
V_6 = F_8 ( V_2 , F_9 ( V_8 ) ) ;
if ( ! V_6 ) {
F_2 (KERN_ERR MOD L_3
L_4 ,
CQE_QPID(err_cqe),
CQE_OPCODE(err_cqe), CQE_STATUS(err_cqe),
CQE_TYPE(err_cqe), CQE_WRID_HI(err_cqe),
CQE_WRID_LOW(err_cqe)) ;
F_10 ( & V_2 -> V_35 ) ;
goto V_36;
}
if ( F_11 ( V_8 ) )
V_34 = V_6 -> V_15 . V_37 ;
else
V_34 = V_6 -> V_15 . V_38 ;
V_4 = F_12 ( V_2 , V_34 ) ;
if ( ! V_4 ) {
F_2 (KERN_ERR MOD L_5
L_4 ,
cqid, CQE_QPID(err_cqe),
CQE_OPCODE(err_cqe), CQE_STATUS(err_cqe),
CQE_TYPE(err_cqe), CQE_WRID_HI(err_cqe),
CQE_WRID_LOW(err_cqe)) ;
F_10 ( & V_2 -> V_35 ) ;
goto V_36;
}
F_13 ( & V_6 -> V_28 ) ;
F_14 ( & V_4 -> V_39 ) ;
F_10 ( & V_2 -> V_35 ) ;
if ( F_15 ( V_8 ) &&
( F_16 ( V_8 ) == V_40 ) ) {
F_1 ( V_2 , V_4 , V_6 , V_8 , V_41 ) ;
goto V_42;
}
switch ( F_17 ( V_8 ) ) {
case V_43 :
F_2 (KERN_ERR MOD L_6 ) ;
break;
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
F_1 ( V_2 , V_4 , V_6 , V_8 , V_52 ) ;
break;
case V_53 :
case V_54 :
case V_55 :
F_1 ( V_2 , V_4 , V_6 , V_8 , V_56 ) ;
break;
case V_57 :
case V_58 :
case V_59 :
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
case V_72 :
F_1 ( V_2 , V_4 , V_6 , V_8 , V_73 ) ;
break;
default:
F_2 (KERN_ERR MOD L_7 ,
CQE_STATUS(err_cqe), qhp->wq.sq.qid) ;
F_1 ( V_2 , V_4 , V_6 , V_8 , V_73 ) ;
break;
}
V_42:
if ( F_18 ( & V_4 -> V_39 ) )
F_19 ( & V_4 -> V_74 ) ;
F_20 ( & V_6 -> V_28 ) ;
V_36:
return;
}
int F_21 ( struct V_1 * V_2 , T_1 V_75 )
{
struct V_3 * V_4 ;
unsigned long V_14 ;
V_4 = F_12 ( V_2 , V_75 ) ;
if ( V_4 ) {
F_4 ( & V_4 -> V_31 , V_14 ) ;
(* V_4 -> V_23 . V_32 )( & V_4 -> V_23 , V_4 -> V_23 . V_33 ) ;
F_5 ( & V_4 -> V_31 , V_14 ) ;
} else
F_22 ( L_8 , V_76 , V_75 ) ;
return 0 ;
}
