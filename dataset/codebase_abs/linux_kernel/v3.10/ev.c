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
F_2 ( L_1\
L_2 ,
V_19 , F_3 ( V_8 ) , F_4 ( V_8 ) ,
F_5 ( V_8 ) , F_6 ( V_8 ) ,
F_7 ( V_8 ) , F_8 ( V_8 ) ) ;
return;
}
F_9 (KERN_ERR MOD L_3
L_2 ,
CQE_QPID(err_cqe), CQE_OPCODE(err_cqe),
CQE_STATUS(err_cqe), CQE_TYPE(err_cqe),
CQE_WRID_HI(err_cqe), CQE_WRID_LOW(err_cqe)) ;
if ( V_6 -> V_15 . V_16 == V_20 ) {
V_13 . V_21 = V_18 ;
F_10 ( V_6 -> V_22 , V_6 , V_23 ,
& V_13 , 0 ) ;
}
V_11 . V_11 = V_10 ;
V_11 . V_24 = V_4 -> V_25 . V_24 ;
if ( V_10 == V_26 )
V_11 . V_27 . V_28 = & V_4 -> V_25 ;
else
V_11 . V_27 . V_29 = & V_6 -> V_30 ;
if ( V_6 -> V_30 . V_31 )
(* V_6 -> V_30 . V_31 )( & V_11 , V_6 -> V_30 . V_32 ) ;
F_11 ( & V_4 -> V_33 , V_14 ) ;
(* V_4 -> V_25 . V_34 )( & V_4 -> V_25 , V_4 -> V_25 . V_35 ) ;
F_12 ( & V_4 -> V_33 , V_14 ) ;
}
void F_13 ( struct V_1 * V_2 , struct V_7 * V_8 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
T_1 V_36 ;
F_14 ( & V_2 -> V_37 ) ;
V_6 = F_15 ( V_2 , F_3 ( V_8 ) ) ;
if ( ! V_6 ) {
F_9 (KERN_ERR MOD L_4
L_5 ,
CQE_QPID(err_cqe),
CQE_OPCODE(err_cqe), CQE_STATUS(err_cqe),
CQE_TYPE(err_cqe), CQE_WRID_HI(err_cqe),
CQE_WRID_LOW(err_cqe)) ;
F_16 ( & V_2 -> V_37 ) ;
goto V_38;
}
if ( F_17 ( V_8 ) )
V_36 = V_6 -> V_15 . V_39 ;
else
V_36 = V_6 -> V_15 . V_40 ;
V_4 = F_18 ( V_2 , V_36 ) ;
if ( ! V_4 ) {
F_9 (KERN_ERR MOD L_6
L_5 ,
cqid, CQE_QPID(err_cqe),
CQE_OPCODE(err_cqe), CQE_STATUS(err_cqe),
CQE_TYPE(err_cqe), CQE_WRID_HI(err_cqe),
CQE_WRID_LOW(err_cqe)) ;
F_16 ( & V_2 -> V_37 ) ;
goto V_38;
}
F_19 ( & V_6 -> V_30 ) ;
F_20 ( & V_4 -> V_41 ) ;
F_16 ( & V_2 -> V_37 ) ;
if ( F_21 ( V_8 ) &&
( F_4 ( V_8 ) == V_42 ) ) {
F_1 ( V_2 , V_4 , V_6 , V_8 , V_43 ) ;
goto V_44;
}
switch ( F_5 ( V_8 ) ) {
case V_45 :
F_9 (KERN_ERR MOD L_7 ) ;
break;
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
case V_52 :
case V_53 :
F_1 ( V_2 , V_4 , V_6 , V_8 , V_54 ) ;
break;
case V_55 :
case V_56 :
case V_57 :
F_1 ( V_2 , V_4 , V_6 , V_8 , V_58 ) ;
break;
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
case V_73 :
case V_74 :
F_1 ( V_2 , V_4 , V_6 , V_8 , V_75 ) ;
break;
default:
F_9 (KERN_ERR MOD L_8 ,
CQE_STATUS(err_cqe), qhp->wq.sq.qid) ;
F_1 ( V_2 , V_4 , V_6 , V_8 , V_75 ) ;
break;
}
V_44:
if ( F_22 ( & V_4 -> V_41 ) )
F_23 ( & V_4 -> V_76 ) ;
F_24 ( & V_6 -> V_30 ) ;
V_38:
return;
}
int F_25 ( struct V_1 * V_2 , T_1 V_77 )
{
struct V_3 * V_4 ;
unsigned long V_14 ;
V_4 = F_18 ( V_2 , V_77 ) ;
if ( V_4 ) {
F_11 ( & V_4 -> V_33 , V_14 ) ;
(* V_4 -> V_25 . V_34 )( & V_4 -> V_25 , V_4 -> V_25 . V_35 ) ;
F_12 ( & V_4 -> V_33 , V_14 ) ;
} else
F_26 ( L_9 , V_19 , V_77 ) ;
return 0 ;
}
