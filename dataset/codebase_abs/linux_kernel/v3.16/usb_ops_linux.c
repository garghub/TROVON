void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
V_4 = (struct V_3 * ) V_2 -> V_6 . V_7 ;
F_2 ( L_1 , V_8 ) ;
V_2 -> V_9 = true ;
for ( V_5 = 0 ; V_5 < V_10 ; V_5 ++ ) {
if ( V_4 -> V_11 )
F_3 ( V_4 -> V_11 ) ;
V_4 ++ ;
}
F_3 ( V_2 -> V_6 . V_12 ) ;
}
static void F_4 ( struct V_13 * V_11 )
{
struct V_14 * V_15 = (struct V_14 * ) V_11 -> V_16 ;
struct V_1 * V_2 = V_15 -> V_2 ;
struct V_17 * V_18 = & V_2 -> V_19 ;
struct V_20 * V_21 ;
unsigned long V_22 ;
switch ( V_15 -> V_23 ) {
case V_24 :
V_18 -> V_25 -- ;
break;
case V_26 :
V_18 -> V_27 -- ;
break;
case V_28 :
V_18 -> V_29 -- ;
break;
case V_30 :
V_18 -> V_31 -- ;
break;
case V_32 :
#ifdef F_5
F_6 ( V_2 ) ;
#endif
break;
default:
break;
}
if ( V_2 -> V_33 || V_2 -> V_34 ||
V_2 -> V_35 ) {
F_7 ( V_36 , V_37 ,
( L_2
L_3 , V_2 -> V_34 ,
V_2 -> V_33 ) ) ;
F_2 ( L_4
L_5
L_6 , V_8 ,
V_2 -> V_34 , V_2 -> V_33 ,
V_2 -> V_9 , V_15 -> V_38 ) ;
goto V_39;
}
if ( V_11 -> V_40 ) {
F_7 ( V_36 , V_37 ,
( L_7
L_8 , V_11 -> V_40 ) ) ;
F_2 ( L_9 ,
V_11 -> V_40 ) ;
if ( V_11 -> V_40 == - V_41 || V_11 -> V_40 == - V_42 ) {
F_8 ( V_2 ,
V_43 ) ;
} else if ( V_11 -> V_40 == - V_44 ) {
F_7 ( V_36 , V_37 ,
( L_10 ) ) ;
goto V_39;
} else if ( V_11 -> V_40 == - V_45 ) {
F_2 ( L_11 , V_8 ) ;
goto V_39;
} else if ( V_11 -> V_40 == - V_46 ) {
F_2 ( L_12 , V_8 ) ;
goto V_39;
} else if ( V_11 -> V_40 == - V_47 ) {
F_7 ( V_36 , V_37 ,
( L_13 ) ) ;
V_2 -> V_34 = true ;
F_7 ( V_36 , V_37 ,
( L_14
L_15 ) ) ;
goto V_39;
} else {
V_2 -> V_33 = true ;
F_2 ( L_16 ) ;
F_7 ( V_36 , V_37 ,
( L_17
L_15 ) ) ;
goto V_39;
}
}
V_21 = F_9 ( V_2 ) ;
V_21 -> V_48 . V_49 = V_50 ;
V_39:
F_10 ( & V_18 -> V_51 , V_22 ) ;
F_11 ( & V_15 -> V_52 ,
V_11 -> V_40 ? V_53 :
V_54 ) ;
F_12 ( & V_18 -> V_51 , V_22 ) ;
F_13 ( V_18 , V_15 ) ;
F_14 ( & V_18 -> V_55 ) ;
}
int F_15 ( struct V_1 * V_2 , T_1 V_56 , T_1 V_57 ,
struct V_14 * V_15 )
{
struct V_13 * V_11 = NULL ;
struct V_58 * V_59 = F_16 ( V_2 ) ;
struct V_17 * V_18 = & V_2 -> V_19 ;
struct V_60 * V_61 ;
struct V_62 * V_63 = V_59 -> V_64 ;
unsigned long V_22 ;
unsigned int V_65 , V_66 ;
int V_40 ;
int V_67 = V_68 ;
F_7 ( V_36 , V_37 , ( L_18 ) ) ;
if ( V_2 -> V_34 || V_2 -> V_33 ||
V_2 -> V_69 . V_70 ) {
F_7 ( V_36 , V_37 ,
( L_19
L_20
L_21 ) ) ;
F_11 ( & V_15 -> V_52 , V_71 ) ;
goto exit;
}
V_61 = (struct V_60 * ) V_15 -> V_72 ;
F_10 ( & V_18 -> V_73 , V_22 ) ;
switch ( V_56 ) {
case V_24 :
V_18 -> V_25 ++ ;
V_15 -> V_23 = V_24 ;
break;
case V_26 :
V_18 -> V_27 ++ ;
V_15 -> V_23 = V_26 ;
break;
case V_28 :
V_18 -> V_29 ++ ;
V_15 -> V_23 = V_28 ;
break;
case V_30 :
V_18 -> V_31 ++ ;
V_15 -> V_23 = V_30 ;
break;
case V_32 :
V_15 -> V_23 = V_32 ;
break;
default:
V_15 -> V_23 = V_74 ;
break;
}
F_12 ( & V_18 -> V_73 , V_22 ) ;
V_11 = V_15 -> V_75 [ 0 ] ;
V_66 = V_59 -> V_76 [ V_56 ] ;
V_65 = F_17 ( V_63 , V_66 ) ;
F_18 ( V_11 , V_63 , V_65 ,
V_61 -> V_77 ,
V_57 , F_4 ,
V_15 ) ;
V_40 = F_19 ( V_11 , V_78 ) ;
if ( ! V_40 ) {
struct V_20 * V_21 = F_9 ( V_2 ) ;
V_21 -> V_48 . V_79 = V_50 ;
} else {
F_11 ( & V_15 -> V_52 ,
V_53 ) ;
F_2 ( L_22 , V_40 ) ;
F_7 ( V_36 , V_37 ,
( L_23 ,
V_40 ) ) ;
switch ( V_40 ) {
case - V_80 :
V_2 -> V_34 = true ;
break;
default:
break;
}
goto exit;
}
V_67 = V_81 ;
F_7 ( V_36 , V_37 , ( L_24 ) ) ;
exit:
if ( V_67 != V_81 )
F_13 ( V_18 , V_15 ) ;
return V_67 ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_82 * V_83 ;
int V_84 ;
F_2 ( L_1 , V_8 ) ;
V_2 -> V_35 = true ;
F_21 (plist, &padapter->xmitpriv.xmitbuf_list) {
V_15 = F_22 ( V_83 , struct V_14 , V_85 ) ;
for ( V_84 = 0 ; V_84 < 8 ; V_84 ++ ) {
if ( V_15 -> V_75 [ V_84 ] )
F_3 ( V_15 -> V_75 [ V_84 ] ) ;
}
}
F_21 (plist, &padapter->xmitpriv.xmitextbuf_list) {
V_15 = F_22 ( V_83 , struct V_14 , V_85 ) ;
for ( V_84 = 0 ; V_84 < 8 ; V_84 ++ ) {
if ( V_15 -> V_75 [ V_84 ] )
F_3 ( V_15 -> V_75 [ V_84 ] ) ;
}
}
}
