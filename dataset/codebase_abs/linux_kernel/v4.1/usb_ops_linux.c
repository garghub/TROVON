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
#ifdef F_5
F_6 ( V_2 ) ;
#endif
break;
default:
break;
}
if ( V_2 -> V_25 || V_2 -> V_26 ||
V_2 -> V_27 ) {
F_7 ( V_28 , V_29 ,
L_2 ,
V_2 -> V_26 , V_2 -> V_25 ) ;
F_2 ( L_3
L_4
L_5 , V_8 ,
V_2 -> V_26 , V_2 -> V_25 ,
V_2 -> V_9 , V_15 -> V_30 ) ;
goto V_31;
}
if ( V_11 -> V_32 ) {
F_7 ( V_28 , V_29 ,
L_6 ,
V_11 -> V_32 ) ;
F_2 ( L_7 ,
V_11 -> V_32 ) ;
if ( V_11 -> V_32 == - V_33 || V_11 -> V_32 == - V_34 ) {
} else if ( V_11 -> V_32 == - V_35 ) {
F_7 ( V_28 , V_29 ,
L_8 ) ;
goto V_31;
} else if ( V_11 -> V_32 == - V_36 ) {
F_2 ( L_9 , V_8 ) ;
goto V_31;
} else if ( V_11 -> V_32 == - V_37 ) {
F_2 ( L_10 , V_8 ) ;
goto V_31;
} else if ( V_11 -> V_32 == - V_38 ) {
F_7 ( V_28 , V_29 ,
L_11 ) ;
V_2 -> V_26 = true ;
F_7 ( V_28 , V_29 ,
L_12 ) ;
goto V_31;
} else {
V_2 -> V_25 = true ;
F_2 ( L_13 ) ;
F_7 ( V_28 , V_29 ,
L_14 ) ;
goto V_31;
}
}
V_21 = F_8 ( V_2 ) ;
V_21 -> V_39 . V_40 = V_41 ;
V_31:
F_9 ( & V_18 -> V_42 , V_22 ) ;
F_10 ( & V_15 -> V_43 ,
V_11 -> V_32 ? V_44 :
V_45 ) ;
F_11 ( & V_18 -> V_42 , V_22 ) ;
F_12 ( V_18 , V_15 ) ;
F_13 ( & V_18 -> V_46 ) ;
}
int F_14 ( struct V_1 * V_2 , T_1 V_47 , T_1 V_48 ,
struct V_14 * V_15 )
{
struct V_13 * V_11 = NULL ;
struct V_49 * V_50 = F_15 ( V_2 ) ;
struct V_17 * V_18 = & V_2 -> V_19 ;
struct V_51 * V_52 ;
struct V_53 * V_54 = V_50 -> V_55 ;
unsigned long V_22 ;
unsigned int V_56 , V_57 ;
int V_32 ;
int V_58 = V_59 ;
F_7 ( V_28 , V_29 , L_15 ) ;
if ( V_2 -> V_26 || V_2 -> V_25 ) {
F_7 ( V_28 , V_29 ,
L_16 ,
V_8 ) ;
F_10 ( & V_15 -> V_43 , V_60 ) ;
goto exit;
}
V_52 = (struct V_51 * ) V_15 -> V_61 ;
F_9 ( & V_18 -> V_62 , V_22 ) ;
switch ( V_47 ) {
case V_63 :
V_15 -> V_23 = V_63 ;
break;
case V_64 :
V_15 -> V_23 = V_64 ;
break;
case V_65 :
V_15 -> V_23 = V_65 ;
break;
case V_66 :
V_15 -> V_23 = V_66 ;
break;
case V_24 :
V_15 -> V_23 = V_24 ;
break;
default:
V_15 -> V_23 = V_67 ;
break;
}
F_11 ( & V_18 -> V_62 , V_22 ) ;
V_11 = V_15 -> V_68 [ 0 ] ;
V_57 = V_50 -> V_69 [ V_47 ] ;
V_56 = F_16 ( V_54 , V_57 ) ;
F_17 ( V_11 , V_54 , V_56 ,
V_52 -> V_70 ,
V_48 , F_4 ,
V_15 ) ;
V_32 = F_18 ( V_11 , V_71 ) ;
if ( ! V_32 ) {
struct V_20 * V_21 = F_8 ( V_2 ) ;
V_21 -> V_39 . V_72 = V_41 ;
} else {
F_10 ( & V_15 -> V_43 ,
V_44 ) ;
F_2 ( L_17 , V_32 ) ;
F_7 ( V_28 , V_29 ,
L_18 ,
V_32 ) ;
switch ( V_32 ) {
case - V_73 :
V_2 -> V_26 = true ;
break;
default:
break;
}
goto exit;
}
V_58 = V_74 ;
F_7 ( V_28 , V_29 , L_19 ) ;
exit:
if ( V_58 != V_74 )
F_12 ( V_18 , V_15 ) ;
return V_58 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_14 * V_15 ;
struct V_75 * V_76 ;
int V_77 ;
F_2 ( L_1 , V_8 ) ;
V_2 -> V_27 = true ;
F_20 (plist, &padapter->xmitpriv.xmitbuf_list) {
V_15 = F_21 ( V_76 , struct V_14 , V_78 ) ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
if ( V_15 -> V_68 [ V_77 ] )
F_3 ( V_15 -> V_68 [ V_77 ] ) ;
}
}
F_20 (plist, &padapter->xmitpriv.xmitextbuf_list) {
V_15 = F_21 ( V_76 , struct V_14 , V_78 ) ;
for ( V_77 = 0 ; V_77 < 8 ; V_77 ++ ) {
if ( V_15 -> V_68 [ V_77 ] )
F_3 ( V_15 -> V_68 [ V_77 ] ) ;
}
}
}
