unsigned int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned int V_7 = 0 , V_8 = 0 ;
if ( V_3 == V_9 ) {
V_7 = F_2 ( V_5 , V_2 -> V_10 [ 0 ] ) ;
} else if ( V_3 == V_11 ) {
V_7 = F_3 ( V_5 , V_2 -> V_10 [ 1 ] ) ;
} else if ( V_3 < V_12 ) {
V_8 = V_2 -> V_13 [ V_3 ] ;
V_7 = F_4 ( V_5 , V_8 ) ;
}
return V_7 ;
}
void F_5 ( struct V_14 * V_15 , T_1 V_3 , T_1 V_16 , T_2 * V_17 )
{
}
void F_6 ( struct V_14 * V_15 , T_1 V_3 , T_1 V_16 , T_2 * V_18 )
{
}
void F_7 ( struct V_14 * V_15 )
{
struct V_19 * V_20 ;
struct V_21 * V_22 = V_15 -> V_22 ;
int V_23 ;
V_20 = (struct V_19 * ) V_22 -> V_24 . V_25 ;
F_8 ( L_1 , V_26 ) ;
V_22 -> V_27 = true ;
for ( V_23 = 0 ; V_23 < V_28 ; V_23 ++ ) {
if ( V_20 -> V_29 )
F_9 ( V_20 -> V_29 ) ;
V_20 ++ ;
}
F_9 ( V_22 -> V_24 . V_30 ) ;
}
static void F_10 ( struct V_31 * V_29 , struct V_32 * V_33 )
{
struct V_34 * V_35 = (struct V_34 * ) V_29 -> V_36 ;
struct V_21 * V_22 = V_35 -> V_22 ;
struct V_37 * V_38 = & V_22 -> V_39 ;
struct V_40 * V_41 ;
unsigned long V_42 ;
switch ( V_35 -> V_43 ) {
case V_44 :
V_38 -> V_45 -- ;
break;
case V_46 :
V_38 -> V_47 -- ;
break;
case V_48 :
V_38 -> V_49 -- ;
break;
case V_50 :
V_38 -> V_51 -- ;
break;
case V_52 :
#ifdef F_11
F_12 ( V_22 ) ;
#endif
break;
default:
break;
}
if ( V_22 -> V_53 || V_22 -> V_54 ||
V_22 -> V_55 ) {
F_13 ( V_56 , V_57 ,
( L_2 ,
V_22 -> V_54 , V_22 -> V_53 ) ) ;
F_8 ( L_3 ,
V_26 , V_22 -> V_54 ,
V_22 -> V_53 , V_22 -> V_27 ,
V_35 -> V_58 ) ;
goto V_59;
}
if ( V_29 -> V_60 ) {
F_13 ( V_56 , V_57 ,
( L_4 ,
V_29 -> V_60 ) ) ;
F_8 ( L_5 ,
V_29 -> V_60 ) ;
if ( ( V_29 -> V_60 == - V_61 ) || ( V_29 -> V_60 == - V_62 ) ) {
F_14 ( V_22 ,
V_63 ) ;
} else if ( V_29 -> V_60 == - V_64 ) {
F_13 ( V_56 , V_57 ,
( L_6 ) ) ;
goto V_59;
} else if ( V_29 -> V_60 == - V_65 ) {
F_8 ( L_7 , V_26 ) ;
goto V_59;
} else if ( V_29 -> V_60 == - V_66 ) {
F_8 ( L_8 , V_26 ) ;
goto V_59;
} else if ( V_29 -> V_60 == - V_67 ) {
F_13 ( V_56 , V_57 ,
( L_9 ) ) ;
V_22 -> V_54 = true ;
F_13 ( V_56 , V_57 ,
( L_10 ) ) ;
goto V_59;
} else {
V_22 -> V_53 = true ;
F_8 ( L_11 ) ;
F_13 ( V_56 , V_57 ,
( L_12 ) ) ;
goto V_59;
}
}
V_41 = F_15 ( V_22 ) ;
V_41 -> V_68 . V_69 = V_70 ;
V_59:
F_16 ( & V_38 -> V_71 , V_42 ) ;
F_17 ( & V_35 -> V_72 ,
V_29 -> V_60 ? V_73 :
V_74 ) ;
F_18 ( & V_38 -> V_71 , V_42 ) ;
F_19 ( V_38 , V_35 ) ;
F_20 ( & V_38 -> V_75 ) ;
}
T_1 F_21 ( struct V_14 * V_15 , T_1 V_3 , T_1 V_16 ,
struct V_34 * V_35 )
{
struct V_31 * V_29 = NULL ;
struct V_21 * V_22 = (struct V_21 * ) V_15 -> V_22 ;
struct V_1 * V_2 = F_22 ( V_22 ) ;
struct V_37 * V_38 = & V_22 -> V_39 ;
struct V_76 * V_77 = (struct V_76 * ) V_35 -> V_78 ;
struct V_4 * V_5 = V_2 -> V_6 ;
unsigned long V_42 ;
unsigned int V_7 ;
int V_60 ;
T_1 V_79 = V_80 ;
F_13 ( V_56 , V_57 , ( L_13 ) ) ;
if ( ( V_22 -> V_54 ) || ( V_22 -> V_53 ) ||
( V_22 -> V_81 . V_82 ) ) {
F_13 ( V_56 , V_57 ,
( L_14 ) ) ;
F_17 ( & V_35 -> V_72 , V_83 ) ;
goto exit;
}
F_16 ( & V_38 -> V_84 , V_42 ) ;
switch ( V_3 ) {
case V_44 :
V_38 -> V_45 ++ ;
V_35 -> V_43 = V_44 ;
break;
case V_46 :
V_38 -> V_47 ++ ;
V_35 -> V_43 = V_46 ;
break;
case V_48 :
V_38 -> V_49 ++ ;
V_35 -> V_43 = V_48 ;
break;
case V_50 :
V_38 -> V_51 ++ ;
V_35 -> V_43 = V_50 ;
break;
case V_52 :
V_35 -> V_43 = V_52 ;
break;
default:
V_35 -> V_43 = V_85 ;
break;
}
F_18 ( & V_38 -> V_84 , V_42 ) ;
V_29 = V_35 -> V_86 [ 0 ] ;
V_7 = F_1 ( V_2 , V_3 ) ;
F_23 ( V_29 , V_5 , V_7 ,
V_77 -> V_87 ,
V_16 , F_10 ,
V_35 ) ;
V_60 = F_24 ( V_29 , V_88 ) ;
if ( ! V_60 ) {
struct V_40 * V_41 = F_15 ( V_22 ) ;
V_41 -> V_68 . V_89 = V_70 ;
} else {
F_17 ( & V_35 -> V_72 ,
V_73 ) ;
F_8 ( L_15 , V_60 ) ;
F_13 ( V_56 , V_57 ,
( L_16 ,
V_60 ) ) ;
switch ( V_60 ) {
case - V_90 :
V_22 -> V_54 = true ;
break;
default:
break;
}
goto exit;
}
V_79 = V_91 ;
F_13 ( V_56 , V_57 , ( L_17 ) ) ;
exit:
if ( V_79 != V_91 )
F_19 ( V_38 , V_35 ) ;
return V_79 ;
}
void F_25 ( struct V_14 * V_15 )
{
struct V_21 * V_22 = V_15 -> V_22 ;
struct V_34 * V_35 ;
struct V_92 * V_93 ;
int V_94 ;
F_8 ( L_1 , V_26 ) ;
V_22 -> V_55 = true ;
F_26 (plist, &padapter->xmitpriv.xmitbuf_list) {
V_35 = F_27 ( V_93 , struct V_34 , V_95 ) ;
for ( V_94 = 0 ; V_94 < 8 ; V_94 ++ ) {
if ( V_35 -> V_86 [ V_94 ] )
F_9 ( V_35 -> V_86 [ V_94 ] ) ;
}
}
F_26 (plist, &padapter->xmitpriv.xmitextbuf_list) {
V_35 = F_27 ( V_93 , struct V_34 , V_95 ) ;
for ( V_94 = 0 ; V_94 < 8 ; V_94 ++ ) {
if ( V_35 -> V_86 [ V_94 ] )
F_9 ( V_35 -> V_86 [ V_94 ] ) ;
}
}
}
