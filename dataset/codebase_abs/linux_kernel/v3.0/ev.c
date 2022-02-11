static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
enum V_9 V_10 )
{
struct V_10 V_11 ;
struct V_12 V_13 ;
if ( ( V_6 -> V_14 . V_15 == V_16 ) ||
( V_6 -> V_14 . V_15 == V_17 ) ) {
F_2 ( L_1
L_2 , V_18 ,
V_6 -> V_14 . V_15 , V_6 -> V_19 . V_20 . V_21 , F_3 ( V_8 ) ) ;
return;
}
F_4 (KERN_ERR MOD L_3
L_4 ,
CQE_QPID(err_cqe), CQE_OPCODE(err_cqe),
CQE_STATUS(err_cqe), CQE_TYPE(err_cqe),
CQE_WRID_HI(err_cqe), CQE_WRID_LOW(err_cqe)) ;
if ( V_6 -> V_14 . V_15 == V_22 ) {
V_13 . V_23 = V_17 ;
F_5 ( V_6 -> V_24 , V_6 , V_25 ,
& V_13 , 0 ) ;
}
V_11 . V_11 = V_10 ;
V_11 . V_26 = V_4 -> V_27 . V_26 ;
if ( V_10 == V_28 )
V_11 . V_29 . V_30 = & V_4 -> V_27 ;
else
V_11 . V_29 . V_31 = & V_6 -> V_32 ;
if ( V_6 -> V_32 . V_33 )
(* V_6 -> V_32 . V_33 )( & V_11 , V_6 -> V_32 . V_34 ) ;
(* V_4 -> V_27 . V_35 )( & V_4 -> V_27 , V_4 -> V_27 . V_36 ) ;
}
void F_6 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_1 V_37 ;
F_7 ( & V_2 -> V_38 ) ;
V_6 = F_8 ( V_2 , F_9 ( V_8 ) ) ;
if ( ! V_6 ) {
F_4 (KERN_ERR MOD L_5
L_6 ,
CQE_QPID(err_cqe),
CQE_OPCODE(err_cqe), CQE_STATUS(err_cqe),
CQE_TYPE(err_cqe), CQE_WRID_HI(err_cqe),
CQE_WRID_LOW(err_cqe)) ;
F_10 ( & V_2 -> V_38 ) ;
goto V_39;
}
if ( F_11 ( V_8 ) )
V_37 = V_6 -> V_14 . V_40 ;
else
V_37 = V_6 -> V_14 . V_41 ;
V_4 = F_12 ( V_2 , V_37 ) ;
if ( ! V_4 ) {
F_4 (KERN_ERR MOD L_7
L_6 ,
cqid, CQE_QPID(err_cqe),
CQE_OPCODE(err_cqe), CQE_STATUS(err_cqe),
CQE_TYPE(err_cqe), CQE_WRID_HI(err_cqe),
CQE_WRID_LOW(err_cqe)) ;
F_10 ( & V_2 -> V_38 ) ;
goto V_39;
}
F_13 ( & V_6 -> V_32 ) ;
F_14 ( & V_4 -> V_42 ) ;
F_10 ( & V_2 -> V_38 ) ;
if ( F_15 ( V_8 ) &&
( F_16 ( V_8 ) == V_43 ) ) {
F_1 ( V_2 , V_4 , V_6 , V_8 , V_44 ) ;
goto V_45;
}
switch ( F_3 ( V_8 ) ) {
case V_46 :
F_4 (KERN_ERR MOD L_8 ) ;
break;
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
F_1 ( V_2 , V_4 , V_6 , V_8 , V_55 ) ;
break;
case V_56 :
case V_57 :
case V_58 :
F_1 ( V_2 , V_4 , V_6 , V_8 , V_59 ) ;
break;
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
case V_73 :
case V_74 :
case V_75 :
F_1 ( V_2 , V_4 , V_6 , V_8 , V_76 ) ;
break;
default:
F_4 (KERN_ERR MOD L_9 ,
CQE_STATUS(err_cqe), qhp->wq.sq.qid) ;
F_1 ( V_2 , V_4 , V_6 , V_8 , V_76 ) ;
break;
}
V_45:
if ( F_17 ( & V_4 -> V_42 ) )
F_18 ( & V_4 -> V_77 ) ;
F_19 ( & V_6 -> V_32 ) ;
V_39:
return;
}
int F_20 ( struct V_1 * V_2 , T_1 V_21 )
{
struct V_3 * V_4 ;
V_4 = F_12 ( V_2 , V_21 ) ;
if ( V_4 )
(* V_4 -> V_27 . V_35 )( & V_4 -> V_27 , V_4 -> V_27 . V_36 ) ;
else
F_2 ( L_10 , V_18 , V_21 ) ;
return 0 ;
}
