static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
F_3 ( V_3 , V_4 , NULL , NULL ) ;
}
static void F_4 ( struct V_2 * V_3 , int V_5 )
{
F_2 (self != NULL, return;) ;
F_2 (self->magic == LAP_MAGIC, return;) ;
#ifdef F_5
if ( F_6 ( & V_3 -> V_6 ) || V_3 -> V_7 ) {
if ( V_3 -> V_8 == TRUE ) {
if ( V_3 -> V_9 < V_5 ) {
V_3 -> V_9 +=
( V_10 * V_11 / 1000 ) ;
V_5 = V_3 -> V_9 ;
}
} else {
V_3 -> V_8 = TRUE ;
V_3 -> V_9 = 0 ;
V_5 = 0 ;
}
} else
V_3 -> V_8 = FALSE ;
F_7 ( L_1 , V_12 , V_5 , V_13 ) ;
#endif
if ( V_5 == 0 )
F_3 ( V_3 , V_4 , NULL , NULL ) ;
else
F_8 ( & V_3 -> V_14 , V_5 , V_3 ,
F_1 ) ;
}
void F_3 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_20 ;
if ( ! V_3 || V_3 -> V_21 != V_22 )
return;
F_7 ( L_2 , V_12 ,
V_23 [ V_15 ] , V_24 [ V_3 -> V_25 ] ) ;
V_20 = (* V_25 [ V_3 -> V_25 ])( V_3 , V_15 , V_17 , V_19 ) ;
switch ( V_3 -> V_25 ) {
case V_26 :
case V_27 :
F_7 ( L_3 , V_12 ,
F_9 ( & V_3 -> V_6 ) ) ;
if ( ! F_6 ( & V_3 -> V_6 ) ) {
V_3 -> V_28 = TRUE ;
while ( ( V_17 = F_10 ( & V_3 -> V_6 ) ) != NULL ) {
V_20 = (* V_25 [ V_3 -> V_25 ])( V_3 , V_29 ,
V_17 , NULL ) ;
F_11 ( V_17 ) ;
F_12 ( V_3 -> V_30 . V_31 ,
V_32 ) ;
if ( V_20 == - V_33 )
break;
}
V_3 -> V_28 = FALSE ;
} else if ( V_3 -> V_34 ) {
V_3 -> V_34 = FALSE ;
V_20 = (* V_25 [ V_3 -> V_25 ])( V_3 , V_35 ,
NULL , NULL ) ;
}
break;
default:
break;
}
}
static int F_13 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
T_2 * V_36 ;
int V_20 = 0 ;
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == LAP_MAGIC, return -1;) ;
switch ( V_15 ) {
case V_37 :
F_2 (self->netdev != NULL, return -1;) ;
if ( V_3 -> V_38 ) {
F_7 ( L_4 ,
V_12 ) ;
F_14 ( V_3 , V_39 ) ;
F_15 ( V_3 , V_40 ) ;
} else {
F_16 ( V_3 , & V_3 -> V_41 ) ;
F_17 ( V_3 , V_3 -> V_42 ) ;
V_3 -> V_43 = 0 ;
F_14 ( V_3 , V_44 ) ;
}
break;
case V_45 :
if ( V_19 ) {
V_3 -> V_46 = V_19 -> V_46 ;
V_3 -> V_47 = V_19 -> V_47 ;
F_14 ( V_3 , V_48 ) ;
F_18 ( V_3 , V_17 ) ;
} else {
F_7 ( L_5 ,
V_12 ) ;
}
break;
case V_49 :
F_2 (info != NULL, return -1;) ;
if ( V_3 -> V_38 ) {
F_7 ( L_6 ,
V_12 ) ;
F_19 ( V_3 , NULL ) ;
return 0 ;
}
V_3 -> V_50 = V_19 -> V_50 ;
V_3 -> V_51 = V_19 -> V_51 ;
F_20 ( V_3 , V_19 -> V_50 , V_19 -> V_51 , TRUE ,
V_19 -> V_52 ) ;
V_3 -> V_53 = FALSE ;
V_3 -> V_51 ++ ;
F_21 ( V_3 , V_3 -> V_54 ) ;
F_14 ( V_3 , V_55 ) ;
break;
case V_56 :
F_2 (info != NULL, return -1;) ;
if ( V_19 -> V_51 <= V_19 -> V_50 ) {
V_3 -> V_57 = F_22 ( V_19 -> V_50 ,
V_19 -> V_51 ) ;
if ( V_3 -> V_57 == V_19 -> V_51 ) {
V_36 = F_23 () ;
V_36 -> V_1 . V_46 = V_19 -> V_46 ;
F_20 ( V_3 , V_19 -> V_50 ,
V_3 -> V_57 ,
FALSE ,
V_36 ) ;
V_3 -> V_53 = TRUE ;
} else
V_3 -> V_53 = FALSE ;
F_24 ( V_3 , V_19 -> V_50 , V_19 -> V_51 ) ;
F_14 ( V_3 , V_58 ) ;
} else {
F_7 ( L_7 ,
V_12 ) ;
F_25 ( V_3 , V_19 -> V_52 ) ;
}
break;
case V_59 :
#ifdef F_26
if ( ! F_6 ( & V_3 -> V_60 ) ) {
V_20 = (* V_25 [ V_3 -> V_25 ])( V_3 , V_61 ,
NULL , NULL ) ;
}
#endif
if ( V_3 -> V_62 ) {
V_3 -> V_62 = FALSE ;
if ( V_3 -> V_34 )
F_15 ( V_3 , V_63 ) ;
else
V_20 = (* V_25 [ V_3 -> V_25 ])( V_3 ,
V_37 ,
NULL , NULL ) ;
V_3 -> V_34 = FALSE ;
}
break;
#ifdef F_26
case V_61 :
{
int V_64 ;
for ( V_64 = 0 ; ( ( V_64 < 2 ) && ( V_3 -> V_38 == FALSE ) ) ; V_64 ++ ) {
V_17 = F_10 ( & V_3 -> V_60 ) ;
if ( V_17 )
F_27 ( V_3 , V_17 , V_65 ,
V_66 ) ;
else
break;
}
if ( V_64 == 2 ) {
F_28 ( V_3 -> V_67 , TRUE ) ;
}
break;
}
case V_68 :
if ( V_19 -> V_47 != V_65 ) {
F_7 ( L_8 ,
V_12 ) ;
} else
F_29 ( V_3 , V_17 ) ;
break;
#endif
case V_69 :
F_30 ( V_17 , sizeof( struct V_70 ) ) ;
F_31 ( V_3 , V_65 , V_19 -> V_46 , V_17 ) ;
break;
case V_71 :
F_7 ( L_9 , V_12 ) ;
break;
default:
F_7 ( L_10 , V_12 ,
V_23 [ V_15 ] ) ;
V_20 = - 1 ;
break;
}
return V_20 ;
}
static int F_32 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_20 = 0 ;
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == LAP_MAGIC, return -1;) ;
switch ( V_15 ) {
case V_72 :
F_2 (info != NULL, return -1;) ;
F_2 (info->discovery != NULL, return -1;) ;
F_7 ( L_11 , V_12 ,
V_19 -> V_52 -> V_1 . V_46 ) ;
if ( ! V_3 -> V_73 ) {
F_33 ( L_12 ,
V_12 ) ;
break;
}
F_34 ( V_3 -> V_73 ,
( V_74 * ) V_19 -> V_52 ,
V_19 -> V_52 -> V_1 . V_46 , NULL ) ;
break;
case V_56 :
F_2 (info != NULL, return -1;) ;
F_7 ( L_13 ,
V_12 , V_19 -> V_51 ) ;
if ( V_19 -> V_51 == 0xff )
F_25 ( V_3 , V_19 -> V_52 ) ;
break;
case V_75 :
if ( F_35 ( V_3 -> V_67 ) && ! V_3 -> V_76 ) {
F_7 ( L_14 ,
V_12 ) ;
F_21 ( V_3 , F_36 ( 10 ) ) ;
V_3 -> V_76 = TRUE ;
return V_20 ;
}
V_3 -> V_76 = FALSE ;
if ( V_3 -> V_51 < V_3 -> V_50 ) {
F_20 ( V_3 , V_3 -> V_50 ,
V_3 -> V_51 , TRUE ,
V_3 -> V_77 ) ;
V_3 -> V_51 ++ ;
F_21 ( V_3 , V_3 -> V_54 ) ;
F_14 ( V_3 , V_55 ) ;
} else {
F_20 ( V_3 , V_3 -> V_50 , 0xff ,
TRUE ,
V_3 -> V_77 ) ;
F_14 ( V_3 , V_39 ) ;
F_19 ( V_3 , V_3 -> V_73 ) ;
V_3 -> V_73 = NULL ;
}
break;
default:
F_7 ( L_10 , V_12 ,
V_23 [ V_15 ] ) ;
V_20 = - 1 ;
break;
}
return V_20 ;
}
static int F_37 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
T_2 * V_36 ;
int V_20 = 0 ;
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == LAP_MAGIC, return -1;) ;
switch ( V_15 ) {
case V_78 :
F_7 ( L_15 ,
V_12 , V_13 ) ;
F_14 ( V_3 , V_39 ) ;
break;
case V_56 :
F_2 (info != NULL, return -1;) ;
if ( V_19 -> V_51 == 0xff ) {
F_38 ( & V_3 -> V_79 ) ;
F_14 ( V_3 , V_39 ) ;
F_25 ( V_3 , V_19 -> V_52 ) ;
} else {
if ( ( V_19 -> V_51 >= V_3 -> V_57 ) && ( ! V_3 -> V_53 ) ) {
V_36 = F_23 () ;
V_36 -> V_1 . V_46 = V_19 -> V_46 ;
F_20 ( V_3 , V_19 -> V_50 ,
V_3 -> V_57 ,
FALSE ,
V_36 ) ;
V_3 -> V_53 = TRUE ;
}
F_24 ( V_3 , V_19 -> V_50 , V_19 -> V_51 ) ;
}
break;
default:
F_7 ( L_16 , V_12 ,
V_15 , V_23 [ V_15 ] ) ;
V_20 = - 1 ;
break;
}
return V_20 ;
}
static int F_39 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_20 = 0 ;
F_7 ( L_17 , V_12 , V_23 [ V_15 ] ) ;
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == LAP_MAGIC, return -1;) ;
switch ( V_15 ) {
case V_80 :
F_30 ( V_17 , sizeof( struct V_81 ) ) ;
F_2 (self->netdev != NULL, return -1;) ;
F_40 ( V_3 , V_17 ) ;
F_41 ( V_3 ) ;
F_42 ( V_3 , FALSE ) ;
F_43 ( V_3 , & V_3 -> V_41 ) ;
#if 0
irlap_send_ua_response_frame(self, &self->qos_rx);
#endif
F_44 ( V_3 , V_3 -> V_82 ) ;
F_14 ( V_3 , V_83 ) ;
break;
case V_56 :
F_7 ( L_18 ,
V_12 ) ;
F_14 ( V_3 , V_39 ) ;
break;
case V_35 :
F_7 ( L_19 , V_12 ) ;
F_45 ( V_3 ) ;
F_14 ( V_3 , V_39 ) ;
F_15 ( V_3 , V_63 ) ;
break;
default:
F_7 ( L_16 , V_12 ,
V_15 , V_23 [ V_15 ] ) ;
V_20 = - 1 ;
break;
}
return V_20 ;
}
static int F_46 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_20 = 0 ;
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == LAP_MAGIC, return -1;) ;
switch ( V_15 ) {
case V_84 :
if ( V_3 -> V_43 < V_3 -> V_85 ) {
F_47 ( V_3 , F_36 ( 20 +
( V_13 % 30 ) ) ) ;
} else {
F_14 ( V_3 , V_39 ) ;
F_15 ( V_3 , V_86 ) ;
}
break;
case V_87 :
F_16 ( V_3 , & V_3 -> V_41 ) ;
F_17 ( V_3 , V_3 -> V_42 ) ;
V_3 -> V_43 ++ ;
break;
case V_45 :
F_7 ( L_20 , V_12 ) ;
F_2 (skb != NULL, return 0;) ;
F_2 (info != NULL, return 0;) ;
if ( V_19 && ( V_19 -> V_46 > V_3 -> V_88 ) ) {
F_38 ( & V_3 -> V_89 ) ;
F_41 ( V_3 ) ;
F_2 (self->netdev != NULL, return -1;) ;
F_30 ( V_17 , sizeof( struct V_81 ) ) ;
F_40 ( V_3 , V_17 ) ;
F_42 ( V_3 , FALSE ) ;
F_43 ( V_3 , & V_3 -> V_41 ) ;
F_14 ( V_3 , V_83 ) ;
F_48 ( V_3 , V_17 ) ;
F_44 ( V_3 , V_3 -> V_82 ) ;
} else {
F_14 ( V_3 , V_44 ) ;
}
break;
case V_90 :
F_38 ( & V_3 -> V_89 ) ;
F_41 ( V_3 ) ;
F_2 (skb->len > 10 , return -1;) ;
F_30 ( V_17 , sizeof( struct V_91 ) ) ;
F_2 (self->netdev != NULL, return -1;) ;
F_40 ( V_3 , V_17 ) ;
F_42 ( V_3 , TRUE ) ;
V_3 -> V_43 = 0 ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_50 ( V_3 , V_66 ) ;
F_17 ( V_3 , V_3 -> V_42 / 2 ) ;
F_14 ( V_3 , V_93 ) ;
F_48 ( V_3 , V_17 ) ;
break;
case V_94 :
case V_95 :
F_38 ( & V_3 -> V_89 ) ;
F_14 ( V_3 , V_39 ) ;
F_15 ( V_3 , V_63 ) ;
break;
default:
F_7 ( L_16 , V_12 ,
V_15 , V_23 [ V_15 ] ) ;
V_20 = - 1 ;
break;
}
return V_20 ;
}
static int F_51 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
F_7 ( L_21 , V_12 ) ;
return - 1 ;
}
static int F_52 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_20 = 0 ;
switch ( V_15 ) {
case V_29 :
if ( ( V_3 -> V_96 > 0 ) && ( ! V_3 -> V_7 ) ) {
int V_97 ;
#ifdef F_53
struct V_16 * V_98 ;
V_98 = F_54 ( & V_3 -> V_6 ) ;
V_97 = ( ( V_98 != NULL ) &&
( ( V_98 -> V_99 + V_17 -> V_99 ) <=
V_3 -> V_100 ) ) ;
if( ( ! V_97 ) && ( V_17 -> V_99 > V_3 -> V_100 ) ) {
F_7 ( L_22 ,
V_12 ) ;
F_55 ( & V_3 -> V_6 , F_56 ( V_17 ) ) ;
return - V_33 ;
}
V_3 -> V_100 -= V_17 -> V_99 ;
#else
V_97 = ! F_6 ( & V_3 -> V_6 ) ;
#endif
if ( ( V_3 -> V_96 > 1 ) && ( V_97 ) ) {
F_57 ( V_3 , V_17 ) ;
F_14 ( V_3 , V_26 ) ;
} else {
F_58 ( V_3 , V_17 ) ;
V_20 = - V_33 ;
}
#ifdef F_5
V_3 -> V_8 = FALSE ;
#endif
} else {
F_7 ( L_23 ,
V_12 ) ;
F_55 ( & V_3 -> V_6 , F_56 ( V_17 ) ) ;
V_20 = - V_33 ;
}
break;
case V_4 :
F_7 ( L_24 ,
V_12 , V_13 ) ;
F_50 ( V_3 , V_66 ) ;
V_3 -> V_96 = V_3 -> V_101 ;
#ifdef F_53
V_3 -> V_100 = V_3 -> V_102 ;
#endif
F_17 ( V_3 , V_3 -> V_42 ) ;
F_14 ( V_3 , V_93 ) ;
break;
case V_35 :
F_38 ( & V_3 -> V_14 ) ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_59 ( V_3 ) ;
F_60 ( V_3 ) ;
F_17 ( V_3 , V_3 -> V_42 ) ;
V_3 -> V_43 = 0 ;
F_14 ( V_3 , V_103 ) ;
break;
case V_104 :
break;
default:
F_7 ( L_10 ,
V_12 , V_23 [ V_15 ] ) ;
V_20 = - V_105 ;
break;
}
return V_20 ;
}
static int F_61 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_20 = 0 ;
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == LAP_MAGIC, return -1;) ;
switch ( V_15 ) {
case V_90 :
case V_94 :
F_38 ( & V_3 -> V_89 ) ;
F_62 ( V_3 ) ;
F_14 ( V_3 , V_39 ) ;
F_15 ( V_3 , V_63 ) ;
break;
case V_84 :
if ( V_3 -> V_43 < V_3 -> V_85 ) {
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_59 ( V_3 ) ;
F_17 ( V_3 , V_3 -> V_42 ) ;
V_3 -> V_43 ++ ;
} else {
F_62 ( V_3 ) ;
F_14 ( V_3 , V_39 ) ;
F_15 ( V_3 , V_106 ) ;
}
break;
default:
F_7 ( L_25 , V_12 , V_15 ) ;
V_20 = - 1 ;
break;
}
return V_20 ;
}
static int F_63 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_20 = 0 ;
int V_107 ;
int V_108 ;
switch ( V_15 ) {
case V_109 :
if ( F_64 ( V_17 -> V_99 <= V_110 + V_111 ) ) {
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_50 ( V_3 , V_66 ) ;
break;
}
#ifdef F_5
V_3 -> V_8 = FALSE ;
#endif
F_2 ( info != NULL, return -1;) ;
V_107 = F_65 ( V_3 , V_19 -> V_112 ) ;
V_108 = F_66 ( V_3 , V_19 -> V_113 ) ;
if ( ( V_107 == V_114 ) && ( V_108 == V_115 ) ) {
V_3 -> V_116 = ( V_3 -> V_116 + 1 ) % 8 ;
F_67 ( V_3 , V_19 -> V_113 ) ;
V_3 -> V_43 = 0 ;
V_3 -> V_117 = TRUE ;
if ( ! V_19 -> V_118 ) {
F_14 ( V_3 , V_93 ) ;
F_68 ( V_3 , V_17 , FALSE ) ;
} else {
F_38 ( & V_3 -> V_89 ) ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_68 ( V_3 , V_17 , FALSE ) ;
F_14 ( V_3 , V_26 ) ;
F_4 ( V_3 , V_3 -> V_119 ) ;
}
break;
}
if ( ( V_107 == V_120 ) && ( V_108 == V_115 ) )
{
if ( ! V_19 -> V_118 ) {
F_67 ( V_3 , V_19 -> V_113 ) ;
F_14 ( V_3 , V_93 ) ;
} else {
F_7 ( L_26 ,
V_12 ) ;
F_67 ( V_3 , V_19 -> V_113 ) ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_50 ( V_3 , V_66 ) ;
V_3 -> V_117 = FALSE ;
F_17 ( V_3 , V_3 -> V_42 ) ;
F_14 ( V_3 , V_93 ) ;
}
break;
}
if ( ( V_107 == V_114 ) && ( V_108 == V_121 ) )
{
if ( V_19 -> V_118 ) {
V_3 -> V_116 = ( V_3 -> V_116 + 1 ) % 8 ;
F_67 ( V_3 , V_19 -> V_113 ) ;
F_69 ( V_3 , V_66 ) ;
V_3 -> V_117 = FALSE ;
F_17 ( V_3 , 2 * V_3 -> V_42 ) ;
F_14 ( V_3 , V_93 ) ;
F_68 ( V_3 , V_17 , FALSE ) ;
} else {
V_3 -> V_116 = ( V_3 -> V_116 + 1 ) % 8 ;
F_67 ( V_3 , V_19 -> V_113 ) ;
V_3 -> V_117 = FALSE ;
F_14 ( V_3 , V_93 ) ;
F_68 ( V_3 , V_17 , FALSE ) ;
}
break;
}
if ( ( V_107 == V_120 ) &&
( V_108 == V_121 ) )
{
F_7 ( L_27 ,
V_12 ) ;
if ( V_19 -> V_118 ) {
F_69 ( V_3 , V_66 ) ;
F_17 ( V_3 , 2 * V_3 -> V_42 ) ;
F_14 ( V_3 , V_93 ) ;
} else {
V_3 -> V_117 = FALSE ;
}
break;
}
if ( ( V_108 == V_122 ) || ( V_107 == V_123 ) ) {
if ( V_19 -> V_118 ) {
F_38 ( & V_3 -> V_89 ) ;
F_14 ( V_3 , V_124 ) ;
F_15 ( V_3 , V_125 ) ;
V_3 -> V_126 = TRUE ;
} else {
F_38 ( & V_3 -> V_89 ) ;
F_15 ( V_3 , V_125 ) ;
V_3 -> V_126 = FALSE ;
}
break;
}
F_7 ( L_28 , V_12 ) ;
F_7 ( L_29 ,
V_12 , V_23 [ V_15 ] , V_107 , V_108 ) ;
break;
case V_68 :
if ( ! V_19 -> V_118 ) {
F_68 ( V_3 , V_17 , TRUE ) ;
F_14 ( V_3 , V_93 ) ;
} else {
F_38 ( & V_3 -> V_89 ) ;
F_68 ( V_3 , V_17 , TRUE ) ;
F_14 ( V_3 , V_26 ) ;
F_7 ( L_30 ,
V_12 , V_24 [ V_3 -> V_25 ] ) ;
F_4 ( V_3 , V_3 -> V_119 ) ;
}
break;
case V_127 :
V_3 -> V_7 = FALSE ;
F_38 ( & V_3 -> V_89 ) ;
V_20 = F_66 ( V_3 , V_19 -> V_113 ) ;
if ( V_20 == V_115 ) {
F_67 ( V_3 , V_19 -> V_113 ) ;
V_3 -> V_43 = 0 ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_14 ( V_3 , V_26 ) ;
F_4 ( V_3 , V_3 -> V_119 ) ;
} else if ( V_20 == V_121 ) {
F_2 (info != NULL, return -1;) ;
F_67 ( V_3 , V_19 -> V_113 ) ;
F_7 ( L_31 ,
V_3 -> V_43 , V_19 -> V_113 , V_3 -> V_128 ,
V_3 -> V_129 , V_3 -> V_116 ) ;
F_69 ( V_3 , V_66 ) ;
F_17 ( V_3 , V_3 -> V_42 * 2 ) ;
F_14 ( V_3 , V_93 ) ;
} else if ( V_20 == V_122 ) {
F_7 ( L_32 ,
V_12 ) ;
F_14 ( V_3 , V_124 ) ;
F_15 ( V_3 , V_125 ) ;
V_3 -> V_126 = TRUE ;
}
break;
case V_130 :
F_2 (info != NULL, return -1;) ;
F_38 ( & V_3 -> V_89 ) ;
V_3 -> V_7 = TRUE ;
F_67 ( V_3 , V_19 -> V_113 ) ;
F_14 ( V_3 , V_26 ) ;
F_4 ( V_3 , V_3 -> V_119 ) ;
break;
case V_131 :
F_38 ( & V_3 -> V_89 ) ;
V_3 -> V_126 = TRUE ;
F_14 ( V_3 , V_124 ) ;
F_70 ( V_3 ) ;
break;
case V_84 :
if ( F_35 ( V_3 -> V_67 ) && ! V_3 -> V_76 ) {
F_7 ( L_33 ) ;
F_17 ( V_3 , F_36 ( 300 ) ) ;
V_3 -> V_76 = TRUE ;
break;
}
V_3 -> V_76 = FALSE ;
if ( V_3 -> V_43 < V_3 -> V_132 ) {
if ( F_54 ( & V_3 -> V_133 ) == NULL ) {
F_7 ( L_34 ) ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_50 ( V_3 , V_66 ) ;
} else {
F_7 ( L_35 ) ;
F_69 ( V_3 , V_66 ) ;
}
F_17 ( V_3 , V_3 -> V_42 ) ;
V_3 -> V_43 ++ ;
F_7 ( L_36 ,
V_3 -> V_43 ) ;
if( ( V_3 -> V_43 % V_3 -> V_134 ) == 0 )
F_71 ( V_3 ,
V_135 ) ;
} else {
F_62 ( V_3 ) ;
F_14 ( V_3 , V_39 ) ;
F_15 ( V_3 , V_106 ) ;
}
break;
case V_136 :
F_67 ( V_3 , V_19 -> V_113 ) ;
if ( V_3 -> V_7 ) {
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_50 ( V_3 , V_66 ) ;
} else
F_69 ( V_3 , V_66 ) ;
F_17 ( V_3 , 2 * V_3 -> V_42 ) ;
break;
case V_137 :
F_67 ( V_3 , V_19 -> V_113 ) ;
if ( V_3 -> V_7 ) {
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_50 ( V_3 , V_66 ) ;
} else
F_72 ( V_3 , V_66 ) ;
F_17 ( V_3 , 2 * V_3 -> V_42 ) ;
break;
case V_138 :
F_7 ( L_37 , V_12 ) ;
F_60 ( V_3 ) ;
F_14 ( V_3 , V_26 ) ;
F_73 ( V_3 ) ;
break;
default:
F_7 ( L_10 ,
V_12 , V_23 [ V_15 ] ) ;
V_20 = - 1 ;
break;
}
return V_20 ;
}
static int F_74 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_20 = 0 ;
F_7 ( L_38 , V_12 , V_23 [ V_15 ] ) ;
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == LAP_MAGIC, return -1;) ;
switch ( V_15 ) {
case V_139 :
if ( V_3 -> V_126 ) {
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_16 ( V_3 , NULL ) ;
F_17 ( V_3 , V_3 -> V_42 ) ;
F_14 ( V_3 , V_140 ) ;
} else {
F_17 ( V_3 , V_3 -> V_42 ) ;
F_14 ( V_3 , V_140 ) ;
}
break;
case V_35 :
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_59 ( V_3 ) ;
F_60 ( V_3 ) ;
F_17 ( V_3 , V_3 -> V_42 ) ;
V_3 -> V_43 = 0 ;
F_14 ( V_3 , V_103 ) ;
break;
default:
F_7 ( L_10 , V_12 ,
V_23 [ V_15 ] ) ;
V_20 = - 1 ;
break;
}
return V_20 ;
}
static int F_75 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_20 = 0 ;
F_7 ( L_38 , V_12 , V_23 [ V_15 ] ) ;
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == LAP_MAGIC, return -1;) ;
switch ( V_15 ) {
case V_95 :
F_38 ( & V_3 -> V_89 ) ;
F_62 ( V_3 ) ;
F_14 ( V_3 , V_39 ) ;
F_15 ( V_3 , V_106 ) ;
break;
case V_90 :
F_38 ( & V_3 -> V_89 ) ;
F_41 ( V_3 ) ;
F_76 () ;
V_3 -> V_7 = FALSE ;
F_14 ( V_3 , V_26 ) ;
F_4 ( V_3 , V_3 -> V_119 ) ;
break;
case V_84 :
if ( V_3 -> V_43 < 3 ) {
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_2 (self->netdev != NULL, return -1;) ;
F_16 ( V_3 , V_3 -> V_141 ) ;
V_3 -> V_43 ++ ;
F_17 ( V_3 , V_3 -> V_42 ) ;
F_14 ( V_3 , V_140 ) ;
} else if ( V_3 -> V_43 >= V_3 -> V_85 ) {
F_62 ( V_3 ) ;
F_14 ( V_3 , V_39 ) ;
F_15 ( V_3 , V_106 ) ;
}
break;
case V_45 :
if ( ! V_19 ) {
F_7 ( L_39 , V_12 ) ;
F_41 ( V_3 ) ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_43 ( V_3 , & V_3 -> V_41 ) ;
F_76 () ;
F_44 ( V_3 , V_3 -> V_82 ) ;
F_14 ( V_3 , V_39 ) ;
} else {
F_7 ( L_40 ,
V_12 ) ;
}
break;
default:
F_7 ( L_10 ,
V_12 , V_23 [ V_15 ] ) ;
V_20 = - 1 ;
break;
}
return V_20 ;
}
static int F_77 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_20 = 0 ;
F_7 ( L_17 , V_12 , V_23 [ V_15 ] ) ;
F_2 (self != NULL, return -ENODEV;) ;
F_2 (self->magic == LAP_MAGIC, return -EBADR;) ;
switch ( V_15 ) {
case V_29 :
if ( ( V_3 -> V_96 > 0 ) && ( ! V_3 -> V_7 ) ) {
int V_97 ;
#ifdef F_53
struct V_16 * V_98 ;
V_98 = F_54 ( & V_3 -> V_6 ) ;
V_97 = ( ( V_98 != NULL ) &&
( ( V_98 -> V_99 + V_17 -> V_99 ) <=
V_3 -> V_100 ) ) ;
if( ( ! V_97 ) && ( V_17 -> V_99 > V_3 -> V_100 ) ) {
F_7 ( L_22 ,
V_12 ) ;
F_55 ( & V_3 -> V_6 , F_56 ( V_17 ) ) ;
V_3 -> V_96 = V_3 -> V_101 ;
V_3 -> V_100 = V_3 -> V_102 ;
F_44 ( V_3 , V_3 -> V_82 ) ;
F_14 ( V_3 , V_83 ) ;
return - V_33 ;
}
V_3 -> V_100 -= V_17 -> V_99 ;
#else
V_97 = ! F_6 ( & V_3 -> V_6 ) ;
#endif
if ( ( V_3 -> V_96 > 1 ) && ( V_97 ) ) {
F_78 ( V_3 , V_17 ) ;
F_14 ( V_3 , V_27 ) ;
} else {
F_79 ( V_3 , V_17 ) ;
F_14 ( V_3 , V_83 ) ;
V_20 = - V_33 ;
}
} else {
F_7 ( L_41 , V_12 ) ;
F_55 ( & V_3 -> V_6 , F_56 ( V_17 ) ) ;
V_20 = - V_33 ;
}
break;
case V_35 :
F_80 ( V_3 ) ;
F_60 ( V_3 ) ;
F_44 ( V_3 , V_3 -> V_82 ) ;
F_14 ( V_3 , V_142 ) ;
break;
case V_104 :
break;
default:
F_7 ( L_10 , V_12 ,
V_23 [ V_15 ] ) ;
V_20 = - V_105 ;
break;
}
return V_20 ;
}
static int F_81 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
int V_107 ;
int V_108 ;
int V_20 = 0 ;
F_7 ( L_17 , V_12 , V_23 [ V_15 ] ) ;
F_2 (self != NULL, return -1;) ;
F_2 (self->magic == LAP_MAGIC, return -1;) ;
switch ( V_15 ) {
case V_143 :
F_7 ( L_42 ,
V_12 , V_23 [ V_15 ] , V_19 -> V_113 ,
V_3 -> V_129 , V_19 -> V_112 , V_3 -> V_116 , V_19 -> V_118 ) ;
V_3 -> V_43 = 0 ;
V_107 = F_65 ( V_3 , V_19 -> V_112 ) ;
V_108 = F_66 ( V_3 , V_19 -> V_113 ) ;
if ( ( V_107 == V_114 ) && ( V_108 == V_115 ) ) {
V_3 -> V_116 = ( V_3 -> V_116 + 1 ) % 8 ;
F_67 ( V_3 , V_19 -> V_113 ) ;
if ( ! V_19 -> V_118 ) {
V_3 -> V_117 = TRUE ;
#if 0
irda_start_timer(WD_TIMER, self->wd_timeout);
#endif
F_14 ( V_3 , V_83 ) ;
F_68 ( V_3 , V_17 , FALSE ) ;
break;
} else {
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_68 ( V_3 , V_17 , FALSE ) ;
if ( ! F_6 ( & V_3 -> V_6 ) &&
( V_3 -> V_96 > 0 ) )
{
V_3 -> V_117 = TRUE ;
F_38 ( & V_3 -> V_144 ) ;
F_14 ( V_3 , V_27 ) ;
} else {
F_50 ( V_3 , V_145 ) ;
F_44 ( V_3 ,
V_3 -> V_82 ) ;
F_14 ( V_3 , V_83 ) ;
}
break;
}
}
if ( ( V_107 == V_120 ) && ( V_108 == V_115 ) )
{
if ( ! V_19 -> V_118 ) {
F_67 ( V_3 , V_19 -> V_113 ) ;
F_44 ( V_3 , V_3 -> V_82 ) ;
} else {
F_67 ( V_3 , V_19 -> V_113 ) ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_50 ( V_3 , V_145 ) ;
F_44 ( V_3 , V_3 -> V_82 ) ;
}
break;
}
if ( ( V_107 == V_114 ) && ( V_108 == V_121 ) )
{
if ( V_19 -> V_118 ) {
F_7 ( L_43 ) ;
V_3 -> V_116 = ( V_3 -> V_116 + 1 ) % 8 ;
F_67 ( V_3 , V_19 -> V_113 ) ;
F_69 ( V_3 , V_145 ) ;
F_14 ( V_3 , V_83 ) ;
F_68 ( V_3 , V_17 , FALSE ) ;
F_44 ( V_3 , V_3 -> V_82 ) ;
break;
}
if ( ! V_19 -> V_118 ) {
V_3 -> V_116 = ( V_3 -> V_116 + 1 ) % 8 ;
F_67 ( V_3 , V_19 -> V_113 ) ;
F_14 ( V_3 , V_83 ) ;
F_68 ( V_3 , V_17 , FALSE ) ;
F_44 ( V_3 , V_3 -> V_82 ) ;
}
break;
}
if ( V_20 == V_122 ) {
F_7 ( L_44 ) ;
}
if ( V_20 == V_123 ) {
F_7 ( L_45 ) ;
}
break;
case V_68 :
if ( ! V_19 -> V_118 ) {
F_68 ( V_3 , V_17 , TRUE ) ;
F_14 ( V_3 , V_83 ) ;
} else {
if ( ! F_6 ( & V_3 -> V_6 ) &&
( V_3 -> V_96 > 0 ) && ! V_3 -> V_7 )
{
F_68 ( V_3 , V_17 , TRUE ) ;
F_38 ( & V_3 -> V_144 ) ;
F_14 ( V_3 , V_27 ) ;
} else {
F_68 ( V_3 , V_17 , TRUE ) ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_50 ( V_3 , V_145 ) ;
V_3 -> V_117 = FALSE ;
F_44 ( V_3 , V_3 -> V_82 ) ;
F_14 ( V_3 , V_83 ) ;
}
}
break;
case V_146 :
V_3 -> V_43 = 0 ;
V_108 = F_66 ( V_3 , V_19 -> V_113 ) ;
if ( V_108 == V_115 ) {
if ( ! F_6 ( & V_3 -> V_6 ) &&
( V_3 -> V_96 > 0 ) ) {
V_3 -> V_7 = FALSE ;
F_67 ( V_3 , V_19 -> V_113 ) ;
F_38 ( & V_3 -> V_144 ) ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_14 ( V_3 , V_27 ) ;
} else {
V_3 -> V_7 = FALSE ;
F_67 ( V_3 , V_19 -> V_113 ) ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_44 ( V_3 , V_3 -> V_82 ) ;
if ( V_3 -> V_34 ) {
F_80 ( V_3 ) ;
F_60 ( V_3 ) ;
F_14 ( V_3 , V_142 ) ;
} else {
F_50 ( V_3 , V_145 ) ;
F_14 ( V_3 , V_83 ) ;
}
}
} else if ( V_108 == V_121 ) {
V_3 -> V_7 = FALSE ;
F_67 ( V_3 , V_19 -> V_113 ) ;
F_69 ( V_3 , V_145 ) ;
F_44 ( V_3 , V_3 -> V_82 ) ;
F_14 ( V_3 , V_83 ) ;
} else {
F_7 ( L_46 ,
V_12 ) ;
}
break;
case V_45 :
if ( ! V_19 ) {
F_38 ( & V_3 -> V_144 ) ;
F_7 ( L_47 , V_12 ) ;
F_14 ( V_3 , V_147 ) ;
F_70 ( V_3 ) ;
} else {
F_7 ( L_48 ,
V_12 ) ;
}
break;
case V_148 :
F_67 ( V_3 , V_19 -> V_113 ) ;
if ( V_3 -> V_7 ) {
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_50 ( V_3 , V_145 ) ;
} else
F_69 ( V_3 , V_145 ) ;
F_44 ( V_3 , V_3 -> V_82 ) ;
break;
case V_149 :
F_67 ( V_3 , V_19 -> V_113 ) ;
if ( V_3 -> V_7 ) {
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_50 ( V_3 , V_145 ) ;
} else
F_72 ( V_3 , V_145 ) ;
F_44 ( V_3 , V_3 -> V_82 ) ;
break;
case V_150 :
F_7 ( L_49 , V_12 ,
V_3 -> V_43 ) ;
if ( V_3 -> V_43 < ( V_3 -> V_132 / 2 ) ) {
F_44 ( V_3 , V_3 -> V_82 ) ;
V_3 -> V_43 ++ ;
if( ( V_3 -> V_43 % ( V_3 -> V_134 / 2 ) ) == 0 )
F_71 ( V_3 ,
V_135 ) ;
} else {
F_62 ( V_3 ) ;
F_14 ( V_3 , V_39 ) ;
F_15 ( V_3 , V_106 ) ;
}
break;
case V_95 :
F_14 ( V_3 , V_39 ) ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_43 ( V_3 , NULL ) ;
F_38 ( & V_3 -> V_144 ) ;
F_60 ( V_3 ) ;
F_62 ( V_3 ) ;
F_15 ( V_3 , V_63 ) ;
break;
case V_56 :
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_50 ( V_3 , V_145 ) ;
V_3 -> V_117 = TRUE ;
F_44 ( V_3 , V_3 -> V_82 ) ;
F_14 ( V_3 , V_83 ) ;
break;
case V_69 :
F_30 ( V_17 , V_110 + V_111 ) ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_44 ( V_3 , V_3 -> V_82 ) ;
F_31 ( V_3 , V_3 -> V_47 , V_19 -> V_46 , V_17 ) ;
break;
default:
F_7 ( L_50 , V_12 ,
V_15 , V_23 [ V_15 ] ) ;
V_20 = - V_105 ;
break;
}
return V_20 ;
}
static int F_82 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 , struct V_18 * V_19 )
{
F_2 (self != NULL, return -ENODEV;) ;
F_2 (self->magic == LAP_MAGIC, return -EBADR;) ;
switch ( V_15 ) {
case V_95 :
F_14 ( V_3 , V_39 ) ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_43 ( V_3 , NULL ) ;
F_38 ( & V_3 -> V_144 ) ;
F_62 ( V_3 ) ;
F_15 ( V_3 , V_63 ) ;
break;
case V_94 :
case V_127 :
case V_130 :
case V_136 :
case V_137 :
case V_109 :
F_14 ( V_3 , V_39 ) ;
F_38 ( & V_3 -> V_144 ) ;
F_62 ( V_3 ) ;
F_15 ( V_3 , V_63 ) ;
break;
case V_150 :
F_14 ( V_3 , V_39 ) ;
F_62 ( V_3 ) ;
F_15 ( V_3 , V_63 ) ;
break;
default:
if ( V_19 != NULL && V_19 -> V_118 ) {
F_38 ( & V_3 -> V_144 ) ;
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_80 ( V_3 ) ;
F_44 ( V_3 , V_3 -> V_82 ) ;
break;
}
F_7 ( L_50 , V_12 ,
V_15 , V_23 [ V_15 ] ) ;
break;
}
return - 1 ;
}
static int F_83 ( struct V_2 * V_3 , T_1 V_15 ,
struct V_16 * V_17 ,
struct V_18 * V_19 )
{
int V_20 = 0 ;
F_7 ( L_17 , V_12 , V_23 [ V_15 ] ) ;
F_2 (self != NULL, return -ENODEV;) ;
F_2 (self->magic == LAP_MAGIC, return -EBADR;) ;
switch ( V_15 ) {
case V_151 :
F_43 ( V_3 , & V_3 -> V_41 ) ;
F_41 ( V_3 ) ;
F_44 ( V_3 , V_152 ) ;
F_60 ( V_3 ) ;
F_14 ( V_3 , V_83 ) ;
break;
case V_35 :
F_49 ( V_3 , & V_3 -> V_92 ) ;
F_80 ( V_3 ) ;
F_44 ( V_3 , V_152 ) ;
F_14 ( V_3 , V_142 ) ;
break;
default:
F_7 ( L_50 , V_12 ,
V_15 , V_23 [ V_15 ] ) ;
V_20 = - V_105 ;
break;
}
return V_20 ;
}
