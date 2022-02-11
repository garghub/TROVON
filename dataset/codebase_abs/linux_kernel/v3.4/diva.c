static int F_1 ( int V_1 , int V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_2 ; V_3 ++ ) {
if ( V_4 [ V_1 + V_3 ] ) {
return ( - 1 ) ;
}
}
return ( 0 ) ;
}
static T_1 * F_2 ( struct V_5 * V_6 )
{
T_1 * V_7 = NULL ;
if ( V_6 && ( V_6 -> V_8 != & V_9 ) )
V_7 = F_3 ( V_6 -> V_8 , T_1 , V_10 ) ;
return ( V_7 ) ;
}
void * F_4 ( void * V_11 , unsigned long V_12 )
{
T_2 V_13 ;
T_1 * V_14 , * V_15 ;
int V_3 , V_16 , V_17 , V_2 ;
for ( V_3 = 0 ; V_18 [ V_3 ] . V_12 != - 1 ; V_3 ++ ) {
if ( V_18 [ V_3 ] . V_12 == V_12 ) {
if ( ! ( V_14 = F_5 ( V_3 , V_11 ) ) ) {
return NULL ;
}
switch ( V_12 ) {
case V_19 :
case V_20 :
case V_21 :
case V_22 :
V_17 = V_23 - 4 ;
V_2 = 4 ;
break;
default:
V_17 = V_23 ;
V_2 = 1 ;
}
F_6 ( & V_24 , & V_13 , L_1 ) ;
for ( V_3 = 0 ; V_3 < V_17 ; V_3 ++ ) {
if ( ! F_1 ( V_3 , V_2 ) ) {
V_14 -> V_25 = V_3 + 1 ;
V_14 -> V_26 . V_27 = V_14 -> V_25 ;
V_4 [ V_3 ] = & V_14 -> V_26 ;
F_7 ( & V_24 , & V_13 , L_1 ) ;
F_8 ( V_14 ) ;
F_9 ((L_2,
CardProperties
[CardOrdinal].Name,
pdiva->controller))
F_6 ( & V_24 , & V_13 , L_1 ) ;
V_15 = V_14 ;
for ( V_16 = 1 ; V_16 < V_2 ; V_16 ++ ) {
V_15 = F_2 ( & V_15 -> V_10 ) ;
if ( V_15 && ! V_15 -> V_28 . V_29 ) {
V_15 -> V_25 = V_3 + 1 + V_16 ;
V_15 -> V_26 . V_27 = V_15 -> V_25 ;
V_4 [ V_3 + V_16 ] = & V_15 -> V_26 ;
F_7 ( & V_24 , & V_13 , L_1 ) ;
F_9 ((L_3,
pa->controller))
F_8 ( V_15 ) ;
F_6 ( & V_24 , & V_13 , L_1 ) ;
} else {
F_10 ((L_4))
break;
}
}
F_7 ( & V_24 , & V_13 , L_1 ) ;
return ( V_14 ) ;
}
}
F_7 ( & V_24 , & V_13 , L_1 ) ;
F_10 ((L_5))
F_11 ( V_14 ) ;
return NULL ;
}
}
return NULL ;
}
int F_12 ( void )
{
F_13 ( & V_24 , L_6 ) ;
memset ( & V_4 [ 0 ] , 0x00 , sizeof( V_4 ) ) ;
F_14 () ;
return ( 0 ) ;
}
static T_1 * F_15 ( void )
{
T_2 V_13 ;
T_1 * V_7 = NULL ;
F_6 ( & V_24 , & V_13 , L_7 ) ;
if ( ! F_16 ( & V_9 ) ) {
V_7 = F_3 ( V_9 . V_8 , T_1 , V_10 ) ;
F_17 ( V_9 . V_8 ) ;
}
F_7 ( & V_24 , & V_13 , L_7 ) ;
return ( V_7 ) ;
}
void F_11 ( void * V_14 )
{
T_2 V_13 ;
T_1 * V_7 [ 4 ] ;
T_1 * V_15 ;
int V_3 ;
V_15 = V_7 [ 0 ] = ( T_1 * ) V_14 ;
V_7 [ 1 ] = V_7 [ 2 ] = V_7 [ 3 ] = NULL ;
F_6 ( & V_24 , & V_13 , L_8 ) ;
for ( V_3 = 1 ; V_3 < 4 ; V_3 ++ ) {
if ( ( V_15 = F_2 ( & V_15 -> V_10 ) )
&& ! V_15 -> V_28 . V_29 ) {
V_7 [ V_3 ] = V_15 ;
} else {
break;
}
}
for ( V_3 = 0 ; ( ( V_3 < 4 ) && V_7 [ V_3 ] ) ; V_3 ++ ) {
F_17 ( & V_7 [ V_3 ] -> V_10 ) ;
}
F_7 ( & V_24 , & V_13 , L_7 ) ;
( * ( V_7 [ 0 ] -> V_28 . V_29 ) ) ( V_7 [ 0 ] ) ;
for ( V_3 = 0 ; V_3 < 4 ; V_3 ++ ) {
if ( V_7 [ V_3 ] ) {
if ( V_7 [ V_3 ] -> V_25 ) {
F_9 ((L_9,
a[i]->controller)) V_4 [ V_7 [ V_3 ] -> V_25 - 1 ] = NULL ;
F_18 ( V_7 [ V_3 ] ) ;
}
F_19 ( 0 , V_7 [ V_3 ] ) ;
}
}
}
static void * F_5 ( int V_30 , void * V_31 )
{
T_3 * V_32 = & V_18 [ V_30 ] ;
T_2 V_13 ;
T_1 * V_7 ;
F_9 ((L_10, pI->CardOrdinal, CardProperties[pI->CardOrdinal].Name))
if ( ! ( V_7 = ( T_1 * ) F_20 ( 0 , sizeof( * V_7 ) ) ) ) {
F_10 ( ( L_11 ) ) ;
return NULL ;
}
memset ( V_7 , 0x00 , sizeof( * V_7 ) ) ;
V_7 -> V_33 = V_30 ;
V_7 -> V_12 = V_32 -> V_12 ;
V_7 -> V_34 = V_35 ;
V_7 -> V_26 . V_36 = V_7 -> V_12 ;
V_7 -> V_37 . V_38 . V_39 = F_21 ( V_31 ) ;
V_7 -> V_37 . V_38 . V_40 = F_22 ( V_31 ) ;
V_7 -> V_37 . V_38 . V_41 = V_31 ;
F_6 ( & V_24 , & V_13 , L_12 ) ;
F_23 ( & V_7 -> V_10 , & V_9 ) ;
F_7 ( & V_24 , & V_13 , L_12 ) ;
if ( ( * ( V_32 -> V_42 ) ) ( V_7 ) ) {
F_6 ( & V_24 , & V_13 , L_12 ) ;
F_17 ( & V_7 -> V_10 ) ;
F_7 ( & V_24 , & V_13 , L_12 ) ;
F_19 ( 0 , V_7 ) ;
F_10 ( ( L_13 ) ) ;
return NULL ;
}
return ( V_7 ) ;
}
void F_24 ( void )
{
T_1 * V_7 ;
while ( ( V_7 = F_15 () ) ) {
if ( V_7 -> V_28 . V_29 ) {
( * ( V_7 -> V_28 . V_29 ) ) ( V_7 ) ;
}
if ( V_7 -> V_25 ) {
V_4 [ V_7 -> V_25 - 1 ] = NULL ;
F_18 ( V_7 ) ;
}
F_19 ( 0 , V_7 ) ;
}
F_25 ( & V_24 , L_6 ) ;
}
void * F_26 ( void * V_43 , const void T_4 * V_44 ,
int V_45 ,
T_5 V_46 )
{
T_6 V_47 ;
T_1 * V_7 = NULL ;
T_2 V_13 ;
struct V_5 * V_48 ;
if ( V_45 < sizeof( T_6 ) ) {
F_10 ((L_14,
length, sizeof(diva_xdi_um_cfg_cmd_t)))
return NULL ;
}
if ( (* V_46) ( V_43 , & V_47 , V_44 , sizeof( V_47 ) ) <= 0 ) {
F_10 ((L_15))
return NULL ;
}
F_6 ( & V_24 , & V_13 , L_16 ) ;
F_27 (tmp, &adapter_queue) {
V_7 = F_3 ( V_48 , T_1 , V_10 ) ;
if ( V_7 -> V_25 == ( int ) V_47 . V_49 )
break;
V_7 = NULL ;
}
F_7 ( & V_24 , & V_13 , L_16 ) ;
if ( ! V_7 ) {
F_10 ((L_17, msg.adapter))
}
return ( V_7 ) ;
}
void F_28 ( void * V_49 , void * V_43 )
{
T_1 * V_7 = ( T_1 * ) V_49 ;
V_7 -> V_50 . V_51 &= ~ V_52 ;
if ( V_7 -> V_50 . V_53 ) {
F_19 ( 0 , V_7 -> V_50 . V_53 ) ;
V_7 -> V_50 . V_53 = NULL ;
}
}
int
F_29 ( void * V_49 , void * V_43 , const void T_4 * V_44 ,
int V_45 , T_5 V_46 )
{
T_1 * V_7 = ( T_1 * ) V_49 ;
void * V_53 ;
if ( V_7 -> V_50 . V_51 & V_52 ) {
F_10 ((L_18, a->controller))
return ( - 1 ) ;
}
if ( V_45 < sizeof( T_6 ) ) {
F_10 ((L_19,
a->controller, length,
sizeof(diva_xdi_um_cfg_cmd_t)))
return ( - 3 ) ;
}
if ( ! ( V_53 = F_20 ( 0 , V_45 ) ) ) {
F_10 ((L_20, a->controller))
return ( - 2 ) ;
}
V_45 = (* V_46) ( V_43 , V_53 , V_44 , V_45 ) ;
if ( V_45 > 0 ) {
if ( ( * ( V_7 -> V_28 . V_54 ) )
( V_7 , ( T_6 * ) V_53 , V_45 ) ) {
V_45 = - 3 ;
}
} else {
F_10 ((L_21, a->controller,
length))
}
F_19 ( 0 , V_53 ) ;
return ( V_45 ) ;
}
int
F_30 ( void * V_49 , void * V_43 , void T_4 * V_55 ,
int V_56 , T_7 V_46 )
{
T_1 * V_7 = ( T_1 * ) V_49 ;
int V_57 ;
if ( ! ( V_7 -> V_50 . V_51 & V_52 ) ) {
F_10 ((L_22, a->controller))
return ( - 1 ) ;
}
if ( ! V_7 -> V_50 . V_53 ) {
V_7 -> V_50 . V_51 &= ~ V_52 ;
F_10 ((L_23, a->controller))
return ( - 2 ) ;
}
if ( V_56 < V_7 -> V_50 . V_58 ) {
F_10 ((L_24,
a->controller, max_length,
a->xdi_mbox.data_length))
return ( - 3 ) ;
}
V_57 = (* V_46) ( V_43 , V_55 , V_7 -> V_50 . V_53 ,
V_7 -> V_50 . V_58 ) ;
if ( V_57 > 0 ) {
F_19 ( 0 , V_7 -> V_50 . V_53 ) ;
V_7 -> V_50 . V_53 = NULL ;
V_7 -> V_50 . V_51 &= ~ V_52 ;
}
return ( V_57 ) ;
}
T_8 F_31 ( int V_59 , void * V_60 )
{
T_1 * V_7 = V_60 ;
T_9 V_61 ;
if ( ! V_7 || ! V_7 -> V_26 . V_62 )
return V_63 ;
if ( ( V_61 = V_7 -> V_64 ) ) {
(* V_61) ( V_7 ) ;
V_7 -> V_64 = NULL ;
return V_65 ;
}
( * ( V_7 -> V_26 . V_62 ) ) ( & V_7 -> V_26 ) ;
return V_65 ;
}
static void F_14 ( void )
{
V_66 [ 0 ] = V_67 ;
V_66 [ 1 ] = V_68 ;
V_66 [ 2 ] = V_69 ;
V_66 [ 3 ] = V_70 ;
V_66 [ 4 ] = V_71 ;
V_66 [ 5 ] = V_72 ;
V_66 [ 6 ] = V_73 ;
V_66 [ 7 ] = V_74 ;
V_66 [ 8 ] = V_75 ;
V_66 [ 9 ] = V_76 ;
V_66 [ 10 ] = V_77 ;
V_66 [ 11 ] = V_78 ;
V_66 [ 12 ] = V_79 ;
V_66 [ 13 ] = V_80 ;
V_66 [ 14 ] = V_81 ;
V_66 [ 15 ] = V_82 ;
V_66 [ 16 ] = V_83 ;
V_66 [ 17 ] = V_84 ;
V_66 [ 18 ] = V_85 ;
V_66 [ 19 ] = V_86 ;
V_66 [ 20 ] = V_87 ;
V_66 [ 21 ] = V_88 ;
V_66 [ 22 ] = V_89 ;
V_66 [ 23 ] = V_90 ;
V_66 [ 24 ] = V_91 ;
V_66 [ 25 ] = V_92 ;
V_66 [ 26 ] = V_93 ;
V_66 [ 27 ] = V_94 ;
V_66 [ 28 ] = V_95 ;
V_66 [ 29 ] = V_96 ;
V_66 [ 30 ] = V_97 ;
V_66 [ 31 ] = V_98 ;
}
void F_32 ( int V_99 )
{
T_10 V_100 ;
if ( ! V_99 || ( ( V_99 - 1 ) >= V_23 ) || ! V_4 [ V_99 - 1 ] ) {
return;
}
V_99 -- ;
V_100 = V_4 [ V_99 ] -> V_101 . V_102 ;
F_9 ((L_25, card + 1))
F_9 ((L_26,
(features & DI_FAX3) ? L_27 : L_28))
F_9 ((L_29,
(features & DI_MODEM) ? L_27 : L_28))
F_9 ((L_30,
(features & DI_POST) ? L_27 : L_28))
F_9 ((L_31,
(features & DI_V110) ? L_27 : L_28))
F_9 ((L_32,
(features & DI_V120) ? L_27 : L_28))
F_9 ((L_33,
(features & DI_POTS) ? L_27 : L_28))
F_9 ((L_34,
(features & DI_CODEC) ? L_27 : L_28))
F_9 ((L_35,
(features & DI_MANAGE) ? L_27 : L_28))
F_9 ((L_36,
(features & DI_V_42) ? L_27 : L_28))
F_9 ((L_37,
(features & DI_EXTD_FAX) ? L_27 : L_28))
F_9 ((L_38,
(features & DI_AT_PARSER) ? L_27 : L_28))
F_9 ((L_39,
(features & DI_VOICE_OVER_IP) ? L_27 : L_28))
}
void F_33 ( T_1 * V_7 )
{
T_2 V_13 ;
F_6 ( & V_24 , & V_13 , L_40 ) ;
F_23 ( & V_7 -> V_10 , & V_9 ) ;
F_7 ( & V_24 , & V_13 , L_40 ) ;
}
int F_34 ( T_1 * V_7 )
{
T_11 * V_103 ;
T_12 * V_53 ;
if ( ! V_7 -> V_26 . V_104 || ! V_7 -> V_26 . V_105 ) {
return ( - 1 ) ;
}
if ( ! ( V_53 = F_20 ( 0 , sizeof( struct V_106 ) ) ) ) {
return ( - 1 ) ;
}
memset ( V_53 , 0x00 , sizeof( struct V_106 ) ) ;
if ( ! ( V_103 = F_20 ( 0 , sizeof( * V_103 ) ) ) ) {
F_19 ( 0 , V_53 ) ;
return ( - 1 ) ;
}
V_103 -> V_107 = 0x0400 ;
V_103 -> V_103 = LOG ;
V_103 -> V_108 = 0x00 ;
( * ( V_7 -> V_26 . V_105 ) ) ( & V_7 -> V_26 , ( V_109 * ) V_103 ) ;
if ( ! V_103 -> V_108 || V_103 -> V_103 ) {
F_19 ( 0 , V_53 ) ;
F_19 ( 0 , V_103 ) ;
return ( - 1 ) ;
}
memcpy ( V_53 , & V_103 -> V_103 , sizeof( struct V_106 ) ) ;
F_19 ( 0 , V_103 ) ;
V_7 -> V_50 . V_58 = sizeof( struct V_106 ) ;
V_7 -> V_50 . V_53 = V_53 ;
V_7 -> V_50 . V_51 = V_52 ;
return ( 0 ) ;
}
void F_35 ( void * V_30 )
{
}
