static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
struct V_7 * V_8 ,
enum V_9 V_10 )
{
struct V_10 V_11 ;
struct V_12 V_13 ;
unsigned long V_14 ;
if ( ( V_6 -> V_15 . V_16 == V_17 ) ||
( V_6 -> V_15 . V_16 == V_18 ) ) {
F_2 ( L_1
L_2 , V_19 ,
V_6 -> V_15 . V_16 , V_6 -> V_20 . V_21 . V_22 , F_3 ( V_8 ) ) ;
return;
}
F_4 (KERN_ERR MOD L_3
L_4 ,
CQE_QPID(err_cqe), CQE_OPCODE(err_cqe),
CQE_STATUS(err_cqe), CQE_TYPE(err_cqe),
CQE_WRID_HI(err_cqe), CQE_WRID_LOW(err_cqe)) ;
if ( V_6 -> V_15 . V_16 == V_23 ) {
V_13 . V_24 = V_18 ;
F_5 ( V_6 -> V_25 , V_6 , V_26 ,
& V_13 , 0 ) ;
}
V_11 . V_11 = V_10 ;
V_11 . V_27 = V_4 -> V_28 . V_27 ;
if ( V_10 == V_29 )
V_11 . V_30 . V_31 = & V_4 -> V_28 ;
else
V_11 . V_30 . V_32 = & V_6 -> V_33 ;
if ( V_6 -> V_33 . V_34 )
(* V_6 -> V_33 . V_34 )( & V_11 , V_6 -> V_33 . V_35 ) ;
F_6 ( & V_4 -> V_36 , V_14 ) ;
(* V_4 -> V_28 . V_37 )( & V_4 -> V_28 , V_4 -> V_28 . V_38 ) ;
F_7 ( & V_4 -> V_36 , V_14 ) ;
}
void F_8 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_1 V_39 ;
F_9 ( & V_2 -> V_40 ) ;
V_6 = F_10 ( V_2 , F_11 ( V_8 ) ) ;
if ( ! V_6 ) {
F_4 (KERN_ERR MOD L_5
L_6 ,
CQE_QPID(err_cqe),
CQE_OPCODE(err_cqe), CQE_STATUS(err_cqe),
CQE_TYPE(err_cqe), CQE_WRID_HI(err_cqe),
CQE_WRID_LOW(err_cqe)) ;
F_12 ( & V_2 -> V_40 ) ;
goto V_41;
}
if ( F_13 ( V_8 ) )
V_39 = V_6 -> V_15 . V_42 ;
else
V_39 = V_6 -> V_15 . V_43 ;
V_4 = F_14 ( V_2 , V_39 ) ;
if ( ! V_4 ) {
F_4 (KERN_ERR MOD L_7
L_6 ,
cqid, CQE_QPID(err_cqe),
CQE_OPCODE(err_cqe), CQE_STATUS(err_cqe),
CQE_TYPE(err_cqe), CQE_WRID_HI(err_cqe),
CQE_WRID_LOW(err_cqe)) ;
F_12 ( & V_2 -> V_40 ) ;
goto V_41;
}
F_15 ( & V_6 -> V_33 ) ;
F_16 ( & V_4 -> V_44 ) ;
F_12 ( & V_2 -> V_40 ) ;
if ( F_17 ( V_8 ) &&
( F_18 ( V_8 ) == V_45 ) ) {
F_1 ( V_2 , V_4 , V_6 , V_8 , V_46 ) ;
goto V_47;
}
switch ( F_3 ( V_8 ) ) {
case V_48 :
F_4 (KERN_ERR MOD L_8 ) ;
break;
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
case V_55 :
case V_56 :
F_1 ( V_2 , V_4 , V_6 , V_8 , V_57 ) ;
break;
case V_58 :
case V_59 :
case V_60 :
F_1 ( V_2 , V_4 , V_6 , V_8 , V_61 ) ;
break;
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
case V_76 :
case V_77 :
F_1 ( V_2 , V_4 , V_6 , V_8 , V_78 ) ;
break;
default:
F_4 (KERN_ERR MOD L_9 ,
CQE_STATUS(err_cqe), qhp->wq.sq.qid) ;
F_1 ( V_2 , V_4 , V_6 , V_8 , V_78 ) ;
break;
}
V_47:
if ( F_19 ( & V_4 -> V_44 ) )
F_20 ( & V_4 -> V_79 ) ;
F_21 ( & V_6 -> V_33 ) ;
V_41:
return;
}
int F_22 ( struct V_1 * V_2 , T_1 V_22 )
{
struct V_3 * V_4 ;
unsigned long V_14 ;
V_4 = F_14 ( V_2 , V_22 ) ;
if ( V_4 ) {
F_6 ( & V_4 -> V_36 , V_14 ) ;
(* V_4 -> V_28 . V_37 )( & V_4 -> V_28 , V_4 -> V_28 . V_38 ) ;
F_7 ( & V_4 -> V_36 , V_14 ) ;
} else
F_2 ( L_10 , V_19 , V_22 ) ;
return 0 ;
}
