static int F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return 8 * 12 ;
case V_4 :
return 64 * 19 ;
case V_5 :
return 512 * 13 * 8 ;
case V_6 :
return 490000 ;
default:
return - 1 ;
}
}
static int F_2 ( struct V_7 * V_8 , struct V_9 * V_9 ,
struct V_10 * V_11 ,
int * V_12 )
{
struct V_13 * V_14 ;
int V_15 = 1 ;
unsigned V_16 ;
unsigned V_17 ;
V_16 = F_3 ( V_11 -> V_18 ) ;
V_17 = F_3 ( V_11 -> V_19 ) ;
switch ( V_11 -> V_20 ) {
case V_21 :
if ( V_11 -> V_22 != V_23 )
break;
V_8 -> V_24 = V_17 ;
V_15 = 0 ;
* V_12 = 0 ;
break;
case V_25 :
if ( V_11 -> V_22 == V_23 ) {
V_15 = 0 ;
switch ( V_17 ) {
case V_26 :
break;
case V_27 :
V_8 -> V_28 . V_29 = 1 ;
break;
case V_30 :
V_8 -> V_28 . V_31 = 1 ;
break;
case V_32 :
V_8 -> V_28 . V_33 = 1 ;
break;
default:
V_15 = - V_34 ;
}
if ( V_15 == 0 ) {
V_8 -> V_35 |= ( 1 << V_17 ) ;
* V_12 = 0 ;
}
} else if ( V_11 -> V_22 == V_36 ) {
V_14 = F_4 ( V_8 , V_16 ) ;
if ( ! V_14 || V_14 -> V_37 . V_38 == V_8 -> V_37 [ 0 ] . V_37 . V_38 ) {
V_15 = - V_34 ;
break;
}
V_14 -> V_39 = 1 ;
V_15 = 0 ;
* V_12 = 0 ;
}
break;
case V_40 :
if ( V_11 -> V_22 == V_23 ) {
V_15 = 0 ;
switch ( V_17 ) {
case V_26 :
V_17 = V_26 ;
break;
case V_41 :
case V_42 :
case V_43 :
V_15 = - V_34 ;
break;
default:
V_15 = - V_34 ;
break;
}
if ( V_15 == 0 ) {
V_8 -> V_35 &= ~ ( 1 << V_17 ) ;
* V_12 = 0 ;
}
} else if ( V_11 -> V_22 == V_36 ) {
V_14 = F_4 ( V_8 , V_16 ) ;
if ( ! V_14 ) {
V_15 = - V_34 ;
break;
}
if ( ! V_14 -> V_44 )
V_14 -> V_39 = 0 ;
V_15 = 0 ;
* V_12 = 0 ;
}
break;
case V_45 :
if ( V_11 -> V_22 == V_46
|| V_11 -> V_22 == V_47
|| V_11 -> V_22 == V_48 ) {
char * V_49 ;
V_49 = ( char * ) V_9 -> V_50 ;
if ( V_9 -> V_51 > 0 ) {
if ( V_11 -> V_22 == V_48 ) {
V_14 = F_4 ( V_8 , V_16 ) ;
if ( ! V_14 ) {
V_15 = - V_34 ;
break;
}
V_49 [ 0 ] = V_14 -> V_39 ;
} else if ( V_11 -> V_22 ==
V_46 ) {
V_49 [ 0 ] = ( V_52 ) V_8 -> V_35 ;
} else
V_49 [ 0 ] = 0 ;
}
if ( V_9 -> V_51 > 1 )
V_49 [ 1 ] = 0 ;
V_9 -> V_53 = F_5 ( V_54 , 2 ,
V_9 -> V_51 ) ;
V_15 = 0 ;
* V_12 = 0 ;
}
break;
}
return V_15 ;
}
static int F_6 ( struct V_7 * V_8 ,
struct V_9 * V_9 , struct V_13 * V_37 , int V_55 )
{
struct V_56 * V_57 ;
int V_58 = 0 ;
V_59:
F_7 (req, &ep->req_queue, req_entry) {
unsigned V_60 , V_61 , V_62 ;
void * V_63 , * V_64 ;
int V_65 , V_66 ;
int V_67 = 0 ;
V_60 = V_9 -> V_51 - V_9 -> V_53 ;
V_61 = V_57 -> V_57 . V_68 - V_57 -> V_57 . V_69 ;
V_62 = F_8 ( V_60 , V_61 ) ;
V_66 = F_9 ( V_9 -> V_70 ) ;
if ( F_10 ( V_62 == 0 ) )
V_65 = 1 ;
else {
if ( V_62 >= V_37 -> V_37 . V_71 ) {
V_65 = 0 ;
if ( V_62 % V_37 -> V_37 . V_71 > 0 )
V_67 = 1 ;
V_62 -= V_62 % V_37 -> V_37 . V_71 ;
} else {
V_65 = 1 ;
}
V_63 = V_9 -> V_50 + V_9 -> V_53 ;
V_64 = V_57 -> V_57 . V_49 + V_57 -> V_57 . V_69 ;
if ( V_9 -> V_70 & V_72 )
memcpy ( V_63 , V_64 , V_62 ) ;
else
memcpy ( V_64 , V_63 , V_62 ) ;
V_9 -> V_53 += V_62 ;
V_57 -> V_57 . V_69 += V_62 ;
V_58 += V_62 ;
}
if ( V_65 ) {
if ( V_60 == V_61 ) {
V_57 -> V_57 . V_12 = 0 ;
V_9 -> V_12 = 0 ;
} else if ( V_66 ) {
V_57 -> V_57 . V_12 = 0 ;
if ( V_61 > V_60 )
V_9 -> V_12 = - V_73 ;
else
V_9 -> V_12 = 0 ;
} else {
V_9 -> V_12 = 0 ;
if ( V_60 > V_61 )
V_57 -> V_57 . V_12 = - V_73 ;
else
V_57 -> V_57 . V_12 = 0 ;
}
} else {
if ( V_57 -> V_57 . V_68 == V_57 -> V_57 . V_69 ) {
if ( V_57 -> V_57 . V_74 && V_66 )
V_67 = 1 ;
else
V_57 -> V_57 . V_12 = 0 ;
}
if ( V_9 -> V_51 == V_9 -> V_53 ) {
if ( V_9 -> V_75 & V_76 &&
! V_66 )
V_67 = 1 ;
else
V_9 -> V_12 = 0 ;
}
}
if ( V_57 -> V_57 . V_12 != - V_77 ) {
F_11 ( & V_57 -> V_78 ) ;
F_12 ( & V_8 -> V_79 ) ;
F_13 ( & V_37 -> V_37 , & V_57 -> V_57 ) ;
F_14 ( & V_8 -> V_79 ) ;
V_67 = 1 ;
}
if ( V_9 -> V_12 != - V_77 )
break;
if ( V_67 )
goto V_59;
}
return V_58 ;
}
static void F_15 ( unsigned long V_80 )
{
struct V_7 * V_8 = (struct V_7 * ) V_80 ;
struct V_81 * V_82 = & V_8 -> V_83 ;
struct V_84 * V_85 , * V_86 ;
unsigned long V_87 ;
struct V_88 * V_89 ;
struct V_13 * V_37 ;
int V_90 = 0 ;
int V_91 , V_55 ;
F_16 ( & V_8 -> V_79 , V_87 ) ;
V_91 = F_1 ( V_8 -> V_28 . V_2 ) ;
if ( V_91 < 0 ) {
V_82 -> V_92 = V_93 ;
F_17 ( & V_8 -> V_79 , V_87 ) ;
return;
}
if ( F_18 ( V_94 , V_82 -> V_95 + F_19 ( 1 ) ) ) {
V_82 -> V_96 = V_91 ;
V_82 -> V_95 = V_94 ;
} else {
V_91 = V_82 -> V_96 ;
}
F_7 (_ep, &udc->gadget.ep_list, ep_list) {
V_37 = F_20 ( V_89 ) ;
V_37 -> V_97 = 0 ;
}
V_98:
F_21 (urb_p, tmp, &udc->urb_queue, urb_entry) {
struct V_9 * V_9 = V_85 -> V_9 ;
V_37 = V_85 -> V_37 ;
if ( V_9 -> V_99 )
goto V_100;
if ( V_82 -> V_92 != V_101 )
continue;
if ( ! V_37 ) {
V_9 -> V_12 = - V_102 ;
goto V_100;
}
if ( V_91 <= 0 && V_37 -> type == V_103 )
continue;
if ( V_37 -> V_97 )
continue;
V_37 -> V_97 = 1 ;
if ( V_37 == & V_8 -> V_37 [ 0 ] && V_85 -> V_104 ) {
V_37 -> V_105 = 1 ;
V_85 -> V_104 = 0 ;
}
if ( V_37 -> V_39 && ! V_37 -> V_105 ) {
V_9 -> V_12 = - V_106 ;
goto V_100;
}
if ( V_37 == & V_8 -> V_37 [ 0 ] && V_37 -> V_105 ) {
V_37 -> V_105 = 0 ;
V_37 -> V_39 = 0 ;
V_90 = F_2 ( V_8 , V_9 ,
(struct V_10 * ) V_9 -> V_107 ,
( & V_9 -> V_12 ) ) ;
if ( V_90 > 0 ) {
F_12 ( & V_8 -> V_79 ) ;
V_90 = V_8 -> V_108 -> V_11 ( & V_8 -> V_28 ,
(struct V_10 * )
V_9 -> V_107 ) ;
F_14 ( & V_8 -> V_79 ) ;
}
if ( V_90 >= 0 ) {
V_55 = 64 * 1024 ;
goto V_109;
} else {
V_9 -> V_12 = - V_106 ;
V_9 -> V_53 = 0 ;
goto V_100;
}
}
V_55 = V_91 ;
switch ( V_37 -> type ) {
case V_110 :
V_9 -> V_12 = - V_111 ;
break;
case V_112 :
V_55 += V_9 -> V_51 ;
default:
V_109:
V_91 -= F_6 ( V_8 , V_9 , V_37 , V_55 ) ;
}
if ( V_9 -> V_12 == - V_77 )
continue;
V_100:
if ( V_37 )
V_37 -> V_97 = V_37 -> V_105 = 0 ;
F_14 ( & V_8 -> V_113 ) ;
F_22 ( & V_85 -> V_114 ) ;
if ( ! V_9 -> V_99 ) {
F_23 ( V_8 , V_85 ) ;
} else {
F_24 ( V_8 , V_85 -> V_115 ,
V_9 -> V_99 ) ;
F_25 ( V_85 ) ;
}
F_26 ( & V_8 -> V_116 ) ;
F_12 ( & V_8 -> V_113 ) ;
goto V_98;
}
if ( F_27 ( & V_8 -> V_117 ) )
V_82 -> V_92 = V_93 ;
else
F_28 ( & V_82 -> V_82 ,
V_82 -> V_95 + F_19 ( 1 ) ) ;
F_17 ( & V_8 -> V_79 , V_87 ) ;
}
void F_29 ( struct V_7 * V_8 )
{
struct V_81 * V_118 = & V_8 -> V_83 ;
F_30 ( & V_118 -> V_82 , F_15 , ( unsigned long ) V_8 ) ;
V_118 -> V_92 = V_119 ;
}
void F_31 ( struct V_7 * V_8 )
{
struct V_81 * V_118 = & V_8 -> V_83 ;
F_32 ( & V_8 -> V_120 -> V_121 , L_1 ) ;
switch ( V_118 -> V_92 ) {
case V_101 :
return;
case V_93 :
return F_33 ( V_8 , V_94 ) ;
case V_119 :
V_118 -> V_92 = V_93 ;
V_118 -> V_95 = V_94 ;
V_118 -> V_96 = F_1 ( V_8 -> V_28 . V_2 ) ;
return F_33 ( V_8 , V_94 ) ;
}
}
void F_33 ( struct V_7 * V_8 , unsigned long time )
{
struct V_81 * V_118 = & V_8 -> V_83 ;
F_32 ( & V_8 -> V_120 -> V_121 , L_2 ) ;
switch ( V_118 -> V_92 ) {
case V_101 :
return;
case V_93 :
V_118 -> V_92 = V_101 ;
case V_119 :
F_28 ( & V_118 -> V_82 , time ) ;
}
}
void F_34 ( struct V_7 * V_8 )
{
struct V_81 * V_118 = & V_8 -> V_83 ;
F_32 ( & V_8 -> V_120 -> V_121 , L_3 ) ;
V_118 -> V_92 = V_119 ;
}
