int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
if ( ( V_2 = F_2 ( sizeof( * V_2 ) ) ) == NULL )
return ( 0 ) ;
V_1 -> V_2 = V_2 ;
V_2 -> V_3 . V_4 = F_3 () ;
V_2 -> V_5 . V_4 = F_3 () ;
V_2 -> V_6 . V_4 = F_3 () ;
if ( V_2 -> V_3 . V_4 == NULL || V_2 -> V_5 . V_4 == NULL
|| V_2 -> V_6 . V_4 == NULL ) {
F_4 ( V_2 -> V_3 . V_4 ) ;
F_4 ( V_2 -> V_5 . V_4 ) ;
F_4 ( V_2 -> V_6 . V_4 ) ;
F_5 ( V_2 ) ;
V_1 -> V_2 = NULL ;
return ( 0 ) ;
}
return 1 ;
}
void F_6 ( T_1 * V_1 )
{
F_7 ( V_1 ) ;
F_4 ( V_1 -> V_2 -> V_3 . V_4 ) ;
F_4 ( V_1 -> V_2 -> V_5 . V_4 ) ;
F_4 ( V_1 -> V_2 -> V_6 . V_4 ) ;
F_5 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
}
void F_7 ( T_1 * V_1 )
{
T_2 * V_2 ;
T_3 * V_7 = NULL ;
T_4 * V_8 ;
T_5 * V_3 ;
T_5 * V_5 ;
T_5 * V_6 ;
V_2 = V_1 -> V_2 ;
while ( ( V_7 = F_8 ( V_2 -> V_3 . V_4 ) ) != NULL ) {
V_8 = ( T_4 * ) V_7 -> V_9 ;
F_5 ( V_8 -> V_10 . V_11 ) ;
F_5 ( V_7 -> V_9 ) ;
F_9 ( V_7 ) ;
}
while ( ( V_7 = F_8 ( V_2 -> V_5 . V_4 ) ) != NULL ) {
V_8 = ( T_4 * ) V_7 -> V_9 ;
F_5 ( V_8 -> V_10 . V_11 ) ;
F_5 ( V_7 -> V_9 ) ;
F_9 ( V_7 ) ;
}
while ( ( V_7 = F_8 ( V_2 -> V_6 . V_4 ) ) != NULL ) {
V_8 = ( T_4 * ) V_7 -> V_9 ;
F_5 ( V_8 -> V_10 . V_11 ) ;
F_5 ( V_7 -> V_9 ) ;
F_9 ( V_7 ) ;
}
V_3 = V_2 -> V_3 . V_4 ;
V_5 = V_2 -> V_5 . V_4 ;
V_6 = V_2 -> V_6 . V_4 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_3 . V_4 = V_3 ;
V_2 -> V_5 . V_4 = V_5 ;
V_2 -> V_6 . V_4 = V_6 ;
}
void F_10 ( T_1 * V_1 , unsigned short V_12 )
{
if ( V_12 == V_1 -> V_2 -> V_13 - 1 ) {
memcpy ( V_1 -> V_2 -> V_14 ,
V_1 -> V_15 , sizeof( V_1 -> V_15 ) ) ;
memcpy ( V_1 -> V_15 ,
V_1 -> V_2 -> V_16 , sizeof( V_1 -> V_15 ) ) ;
} else if ( V_12 == V_1 -> V_2 -> V_13 + 1 ) {
memcpy ( V_1 -> V_2 -> V_16 ,
V_1 -> V_15 , sizeof( unsigned char [ 8 ] ) ) ;
memcpy ( V_1 -> V_15 ,
V_1 -> V_2 -> V_14 , sizeof( V_1 -> V_15 ) ) ;
}
V_1 -> V_2 -> V_13 = V_12 ;
}
void F_11 ( T_1 * V_1 )
{
memcpy ( V_1 -> V_15 , V_1 -> V_17 , sizeof( V_1 -> V_15 ) ) ;
}
void F_12 ( T_1 * V_1 , unsigned char * V_18 )
{
memcpy ( V_1 -> V_15 , V_18 , V_19 ) ;
}
static int F_13 ( T_6 * V_20 , T_3 * V_7 )
{
T_4 * V_8 ;
V_8 = ( T_4 * ) V_7 -> V_9 ;
F_14 ( & V_20 -> V_21 . V_10 ) ;
V_20 -> V_21 . V_22 = V_8 -> V_22 ;
V_20 -> V_21 . V_23 = V_8 -> V_23 ;
memcpy ( & V_20 -> V_21 . V_10 , & ( V_8 -> V_10 ) , sizeof( V_24 ) ) ;
memcpy ( & V_20 -> V_21 . V_25 , & ( V_8 -> V_25 ) , sizeof( V_26 ) ) ;
memcpy ( & ( V_20 -> V_21 . V_17 [ 2 ] ) , & ( V_8 -> V_22 [ 5 ] ) , 6 ) ;
return ( 1 ) ;
}
int F_15 ( T_6 * V_20 , T_7 * V_27 , unsigned char * V_28 )
{
T_4 * V_8 ;
T_3 * V_7 ;
if ( F_16 ( V_27 -> V_4 ) >= 100 )
return 0 ;
V_8 = F_2 ( sizeof( * V_8 ) ) ;
V_7 = F_17 ( V_28 , V_8 ) ;
if ( V_8 == NULL || V_7 == NULL ) {
F_5 ( V_8 ) ;
F_9 ( V_7 ) ;
F_18 ( V_29 , V_30 ) ;
return - 1 ;
}
V_8 -> V_22 = V_20 -> V_21 . V_22 ;
V_8 -> V_23 = V_20 -> V_21 . V_23 ;
memcpy ( & ( V_8 -> V_10 ) , & V_20 -> V_21 . V_10 , sizeof( V_24 ) ) ;
memcpy ( & ( V_8 -> V_25 ) , & V_20 -> V_21 . V_25 , sizeof( V_26 ) ) ;
V_7 -> V_9 = V_8 ;
#ifndef F_19
if ( F_20 ( F_21 ( V_20 ) ) &&
( F_22 ( V_20 ) == V_31
|| F_22 ( V_20 ) == V_32 ) ) {
F_23 ( F_21 ( V_20 ) , V_33 ,
sizeof( V_8 -> V_34 ) , & V_8 -> V_34 ) ;
}
#endif
V_20 -> V_21 . V_22 = NULL ;
V_20 -> V_21 . V_23 = 0 ;
memset ( & V_20 -> V_21 . V_10 , 0 , sizeof( V_20 -> V_21 . V_10 ) ) ;
memset ( & V_20 -> V_21 . V_25 , 0 , sizeof( V_20 -> V_21 . V_25 ) ) ;
if ( ! F_24 ( V_20 ) ) {
F_18 ( V_29 , V_30 ) ;
F_5 ( V_8 -> V_10 . V_11 ) ;
F_5 ( V_8 ) ;
F_9 ( V_7 ) ;
return ( - 1 ) ;
}
if ( F_25 ( V_27 -> V_4 , V_7 ) == NULL ) {
F_18 ( V_29 , V_30 ) ;
F_5 ( V_8 -> V_10 . V_11 ) ;
F_5 ( V_8 ) ;
F_9 ( V_7 ) ;
return ( - 1 ) ;
}
return ( 1 ) ;
}
int F_26 ( T_6 * V_20 , T_7 * V_27 )
{
T_3 * V_7 ;
V_7 = F_8 ( V_27 -> V_4 ) ;
if ( V_7 ) {
F_13 ( V_20 , V_7 ) ;
F_5 ( V_7 -> V_9 ) ;
F_9 ( V_7 ) ;
return ( 1 ) ;
}
return ( 0 ) ;
}
int F_27 ( T_6 * V_20 )
{
T_3 * V_7 ;
V_24 * V_35 ;
V_26 * V_36 ;
T_8 * V_37 ;
unsigned int V_38 ;
int V_39 = 1 ;
V_7 = F_28 ( V_20 -> V_21 . V_2 -> V_3 . V_4 ) ;
if ( V_7 ) {
if ( V_20 -> V_21 . V_2 -> V_3 . V_40 != V_20 -> V_21 . V_2 -> V_41 )
return 1 ;
V_36 = F_29 ( & V_20 -> V_21 ) ;
V_35 = F_30 ( & V_20 -> V_21 ) ;
if ( F_31 ( V_35 ) > 0 ) {
return 1 ;
}
while ( F_28 ( V_20 -> V_21 . V_2 -> V_3 . V_4 ) ) {
F_32 ( V_20 ) ;
V_37 = F_33 ( V_20 , V_36 , & V_38 ) ;
if ( V_37 == NULL ) {
F_18 ( V_42 ,
V_30 ) ;
return 0 ;
}
#ifndef F_19
if ( ! F_20 ( F_21 ( V_20 ) ) )
#endif
{
V_39 = F_34 ( V_20 , V_37 ) ;
}
if ( ! V_39 || ! F_35 ( V_20 , V_37 ) ) {
V_36 -> V_43 = 0 ;
F_36 ( & V_20 -> V_21 ) ;
continue;
}
if ( F_15 ( V_20 , & ( V_20 -> V_21 . V_2 -> V_5 ) ,
F_37 ( V_20 -> V_21 . V_25 ) ) < 0 )
return 0 ;
}
}
V_20 -> V_21 . V_2 -> V_5 . V_40 = V_20 -> V_21 . V_2 -> V_41 ;
V_20 -> V_21 . V_2 -> V_3 . V_40 = V_20 -> V_21 . V_2 -> V_41 + 1 ;
return 1 ;
}
int F_38 ( T_6 * V_20 , int type , int * V_44 , unsigned char * V_11 ,
int V_45 , int V_46 )
{
int V_47 , V_48 , V_49 , V_50 ;
unsigned int V_51 ;
V_26 * V_36 ;
void (* F_39) ( const T_6 * V_52 , int V_53 , int V_54 ) = NULL ;
if ( ! F_40 ( & V_20 -> V_21 . V_10 ) ) {
if ( ! F_24 ( V_20 ) )
return ( - 1 ) ;
}
if ( ( type && ( type != V_55 ) &&
( type != V_56 ) ) ||
( V_46 && ( type != V_55 ) ) ) {
F_18 ( V_57 , V_30 ) ;
return - 1 ;
}
if ( ( V_50 = F_41 ( V_20 , type , V_11 , V_45 ) ) )
return V_50 ;
#ifndef F_19
if ( ( ! F_42 ( V_20 ) && F_43 ( V_20 ) ) ||
( F_20 ( F_21 ( V_20 ) )
&& F_44 ( V_20 )
&& V_20 -> V_58 -> V_59 != 2 ) )
#else
if ( ! F_42 ( V_20 ) && F_43 ( V_20 ) )
#endif
{
V_48 = V_20 -> V_60 ( V_20 ) ;
if ( V_48 < 0 )
return ( V_48 ) ;
if ( V_48 == 0 ) {
F_18 ( V_57 , V_61 ) ;
return ( - 1 ) ;
}
}
V_62:
V_20 -> V_63 = V_64 ;
V_36 = V_20 -> V_21 . V_25 ;
if ( F_45 ( V_20 ) && F_46 ( V_36 ) == 0 ) {
T_3 * V_7 ;
V_7 = F_8 ( V_20 -> V_21 . V_2 -> V_6 . V_4 ) ;
if ( V_7 ) {
#ifndef F_19
if ( F_20 ( F_21 ( V_20 ) ) ) {
T_4 * V_8 = ( T_4 * ) V_7 -> V_9 ;
F_23 ( F_21 ( V_20 ) , V_65 ,
sizeof( V_8 -> V_34 ) , & V_8 -> V_34 ) ;
}
#endif
F_13 ( V_20 , V_7 ) ;
F_5 ( V_7 -> V_9 ) ;
F_9 ( V_7 ) ;
}
}
if ( F_47 ( V_20 ) > 0 )
goto V_62;
if ( ( F_46 ( V_36 ) == 0 )
|| ( V_20 -> V_21 . V_66 == V_67 ) ) {
V_50 = F_48 ( V_20 ) ;
if ( V_50 <= 0 ) {
V_50 = F_49 ( V_20 , V_50 ) ;
if ( V_50 <= 0 )
return ( V_50 ) ;
else
goto V_62;
}
}
if ( V_20 -> V_58 -> V_68
&& ( F_50 ( V_36 ) != V_56 ) ) {
if ( F_15 ( V_20 , & ( V_20 -> V_21 . V_2 -> V_6 ) ,
F_37 ( V_36 ) ) < 0 ) {
F_18 ( V_57 , V_30 ) ;
return - 1 ;
}
F_51 ( V_36 , 0 ) ;
goto V_62;
}
if ( V_20 -> V_69 & V_70 ) {
F_51 ( V_36 , 0 ) ;
V_20 -> V_63 = V_64 ;
return ( 0 ) ;
}
if ( type == F_50 ( V_36 )
|| ( F_50 ( V_36 ) == V_71
&& type == V_56 && V_44 != NULL ) ) {
if ( F_43 ( V_20 ) && ( type == V_55 ) &&
( V_20 -> V_72 == NULL ) ) {
V_47 = V_73 ;
F_18 ( V_57 , V_74 ) ;
goto V_75;
}
if ( V_44 != NULL )
* V_44 = F_50 ( V_36 ) ;
if ( V_45 <= 0 )
return ( V_45 ) ;
if ( ( unsigned int ) V_45 > F_46 ( V_36 ) )
V_51 = F_46 ( V_36 ) ;
else
V_51 = ( unsigned int ) V_45 ;
memcpy ( V_11 , & ( F_52 ( V_36 ) [ F_53 ( V_36 ) ] ) , V_51 ) ;
if ( ! V_46 ) {
F_54 ( V_36 , V_51 ) ;
F_55 ( V_36 , V_51 ) ;
if ( F_46 ( V_36 ) == 0 ) {
V_20 -> V_21 . V_66 = V_76 ;
F_56 ( V_36 , 0 ) ;
}
}
#ifndef F_19
if ( F_20 ( F_21 ( V_20 ) ) &&
F_50 ( V_36 ) == V_55 &&
F_44 ( V_20 ) ) {
V_20 -> V_63 = V_77 ;
F_57 ( F_21 ( V_20 ) ) ;
F_58 ( F_21 ( V_20 ) ) ;
}
if ( F_20 ( F_21 ( V_20 ) ) &&
V_20 -> V_78 -> V_79
&& ! F_59 ( F_21 ( V_20 ) ) ) {
V_20 -> V_69 |= V_70 ;
return ( 0 ) ;
}
#endif
return ( V_51 ) ;
}
{
unsigned int V_80 , V_81 = 0 ;
unsigned char * V_82 = NULL ;
unsigned int * V_83 = NULL ;
if ( F_50 ( V_36 ) == V_56 ) {
V_81 = sizeof V_20 -> V_21 . V_2 -> V_84 ;
V_82 = V_20 -> V_21 . V_2 -> V_84 ;
V_83 = & V_20 -> V_21 . V_2 -> V_85 ;
} else if ( F_50 ( V_36 ) == V_86 ) {
V_81 = sizeof( V_20 -> V_21 . V_2 -> V_87 ) ;
V_82 = V_20 -> V_21 . V_2 -> V_87 ;
V_83 = & V_20 -> V_21 . V_2 -> V_88 ;
}
#ifndef F_60
else if ( F_50 ( V_36 ) == V_89 ) {
if ( F_61 ( V_20 , F_52 ( V_36 ) ,
F_46 ( V_36 ) ) < 0 ) {
return - 1 ;
}
F_51 ( V_36 , 0 ) ;
V_20 -> V_63 = V_77 ;
F_57 ( F_21 ( V_20 ) ) ;
F_58 ( F_21 ( V_20 ) ) ;
return ( - 1 ) ;
}
#endif
else if ( F_50 ( V_36 ) != V_71 ) {
if ( F_50 ( V_36 ) == V_55 ) {
T_9 * V_90 ;
V_20 -> V_58 -> V_59 = 2 ;
V_90 = F_21 ( V_20 ) ;
V_20 -> V_63 = V_77 ;
F_57 ( V_90 ) ;
F_58 ( V_90 ) ;
return ( - 1 ) ;
}
V_47 = V_73 ;
F_18 ( V_57 , V_91 ) ;
goto V_75;
}
if ( V_81 > 0 ) {
if ( F_46 ( V_36 ) < V_81 ) {
#ifdef F_62
T_10 V_92 ;
#endif
V_20 -> V_21 . V_66 = V_76 ;
F_51 ( V_36 , 0 ) ;
goto V_62;
}
for ( V_80 = 0 ; V_80 < V_81 ; V_80 ++ ) {
V_82 [ V_80 ] = F_52 ( V_36 ) [ F_53 ( V_36 ) ] ;
F_55 ( V_36 , 1 ) ;
F_63 ( V_36 , - 1 ) ;
}
* V_83 = V_81 ;
}
}
if ( ( ! V_20 -> V_93 ) &&
( V_20 -> V_21 . V_2 -> V_85 >= V_94 ) &&
( V_20 -> V_21 . V_2 -> V_84 [ 0 ] == V_95 ) &&
( V_20 -> V_96 != NULL ) && ( V_20 -> V_96 -> V_97 != NULL ) ) {
V_20 -> V_21 . V_2 -> V_85 = 0 ;
if ( ( V_20 -> V_21 . V_2 -> V_84 [ 1 ] != 0 ) ||
( V_20 -> V_21 . V_2 -> V_84 [ 2 ] != 0 ) ||
( V_20 -> V_21 . V_2 -> V_84 [ 3 ] != 0 ) ) {
V_47 = V_98 ;
F_18 ( V_57 , V_99 ) ;
goto V_75;
}
if ( V_20 -> V_100 )
V_20 -> V_100 ( 0 , V_20 -> V_101 , V_56 ,
V_20 -> V_21 . V_2 -> V_84 , 4 , V_20 ,
V_20 -> V_102 ) ;
if ( F_45 ( V_20 ) &&
! ( V_20 -> V_58 -> V_103 & V_104 ) &&
! V_20 -> V_58 -> V_105 ) {
V_20 -> V_78 -> V_106 ++ ;
V_20 -> V_107 = 1 ;
F_64 ( V_20 ) ;
if ( F_65 ( V_20 ) ) {
V_48 = V_20 -> V_60 ( V_20 ) ;
if ( V_48 < 0 )
return ( V_48 ) ;
if ( V_48 == 0 ) {
F_18 ( V_57 , V_61 ) ;
return ( - 1 ) ;
}
if ( ! ( V_20 -> V_108 & V_109 ) ) {
if ( F_31 ( & V_20 -> V_21 . V_10 ) == 0 ) {
T_9 * V_90 ;
V_20 -> V_63 = V_77 ;
V_90 = F_21 ( V_20 ) ;
F_57 ( V_90 ) ;
F_58 ( V_90 ) ;
return ( - 1 ) ;
}
}
}
}
goto V_62;
}
if ( V_20 -> V_21 . V_2 -> V_88 >= V_110 ) {
int V_111 = V_20 -> V_21 . V_2 -> V_87 [ 0 ] ;
int V_112 = V_20 -> V_21 . V_2 -> V_87 [ 1 ] ;
V_20 -> V_21 . V_2 -> V_88 = 0 ;
if ( V_20 -> V_100 )
V_20 -> V_100 ( 0 , V_20 -> V_101 , V_86 ,
V_20 -> V_21 . V_2 -> V_87 , 2 , V_20 ,
V_20 -> V_102 ) ;
if ( V_20 -> V_113 != NULL )
F_39 = V_20 -> V_113 ;
else if ( V_20 -> V_114 -> V_113 != NULL )
F_39 = V_20 -> V_114 -> V_113 ;
if ( F_39 != NULL ) {
V_49 = ( V_111 << 8 ) | V_112 ;
F_39 ( V_20 , V_115 , V_49 ) ;
}
if ( V_111 == V_116 ) {
V_20 -> V_58 -> V_117 = V_112 ;
if ( V_112 == V_118 ) {
#ifndef F_19
if ( F_20 ( F_21 ( V_20 ) ) &&
F_59 ( F_21 ( V_20 ) ) ) {
V_20 -> V_78 -> V_79 = 1 ;
V_20 -> V_63 = V_77 ;
F_57 ( F_21 ( V_20 ) ) ;
F_58 ( F_21 ( V_20 ) ) ;
return - 1 ;
}
#endif
V_20 -> V_69 |= V_70 ;
return ( 0 ) ;
}
#if 0
if (alert_descr == DTLS1_AD_MISSING_HANDSHAKE_MESSAGE) {
unsigned short seq;
unsigned int frag_off;
unsigned char *p = &(s->rlayer.d->alert_fragment[2]);
n2s(p, seq);
n2l3(p, frag_off);
dtls1_retransmit_message(s,
dtls1_get_queue_priority
(frag->msg_header.seq, 0), frag_off,
&found);
if (!found && SSL_in_init(s)) {
ssl3_send_alert(s, SSL3_AL_WARNING,
DTLS1_AD_MISSING_HANDSHAKE_MESSAGE);
}
}
#endif
} else if ( V_111 == V_119 ) {
char V_120 [ 16 ] ;
V_20 -> V_63 = V_64 ;
V_20 -> V_58 -> V_121 = V_112 ;
F_18 ( V_57 , V_122 + V_112 ) ;
F_66 ( V_120 , sizeof V_120 , L_1 , V_112 ) ;
F_67 ( 2 , L_2 , V_120 ) ;
V_20 -> V_69 |= V_70 ;
F_68 ( V_20 -> V_123 , V_20 -> V_96 ) ;
return ( 0 ) ;
} else {
V_47 = V_124 ;
F_18 ( V_57 , V_125 ) ;
goto V_75;
}
goto V_62;
}
if ( V_20 -> V_69 & V_126 ) {
V_20 -> V_63 = V_64 ;
F_51 ( V_36 , 0 ) ;
return ( 0 ) ;
}
if ( F_50 ( V_36 ) == V_71 ) {
F_51 ( V_36 , 0 ) ;
goto V_62;
}
if ( ( V_20 -> V_21 . V_2 -> V_85 >= V_94 ) &&
! F_42 ( V_20 ) ) {
struct V_127 V_128 ;
F_69 ( V_36 -> V_9 , & V_128 ) ;
if ( F_70 ( V_36 ) != V_20 -> V_21 . V_2 -> V_41 ) {
F_51 ( V_36 , 0 ) ;
goto V_62;
}
if ( V_128 . type == V_129 ) {
if ( F_71 ( V_20 ) < 0 )
return - 1 ;
F_72 ( V_20 ) ;
F_51 ( V_36 , 0 ) ;
goto V_62;
}
if ( F_45 ( V_20 ) &&
! ( V_20 -> V_58 -> V_103 & V_104 ) ) {
F_73 ( V_20 , 1 ) ;
V_20 -> V_105 = 1 ;
V_20 -> V_107 = 1 ;
}
V_48 = V_20 -> V_60 ( V_20 ) ;
if ( V_48 < 0 )
return ( V_48 ) ;
if ( V_48 == 0 ) {
F_18 ( V_57 , V_61 ) ;
return ( - 1 ) ;
}
if ( ! ( V_20 -> V_108 & V_109 ) ) {
if ( F_31 ( & V_20 -> V_21 . V_10 ) == 0 ) {
T_9 * V_90 ;
V_20 -> V_63 = V_77 ;
V_90 = F_21 ( V_20 ) ;
F_57 ( V_90 ) ;
F_58 ( V_90 ) ;
return ( - 1 ) ;
}
}
goto V_62;
}
switch ( F_50 ( V_36 ) ) {
default:
if ( V_20 -> V_101 == V_130 ) {
F_51 ( V_36 , 0 ) ;
goto V_62;
}
V_47 = V_73 ;
F_18 ( V_57 , V_91 ) ;
goto V_75;
case V_71 :
case V_86 :
case V_56 :
V_47 = V_73 ;
F_18 ( V_57 , V_30 ) ;
goto V_75;
case V_55 :
if ( V_20 -> V_58 -> V_59 &&
( V_20 -> V_58 -> V_131 != 0 ) &&
F_74 ( V_20 ) ) {
V_20 -> V_58 -> V_59 = 2 ;
return ( - 1 ) ;
} else {
V_47 = V_73 ;
F_18 ( V_57 , V_91 ) ;
goto V_75;
}
}
V_75:
F_75 ( V_20 , V_119 , V_47 ) ;
return ( - 1 ) ;
}
static int F_41 ( T_6 * V_20 , int type , unsigned char * V_11 ,
int V_45 )
{
if ( ( type == V_56 )
&& ( V_20 -> V_21 . V_2 -> V_85 > 0 ) )
{
unsigned char * V_132 = V_20 -> V_21 . V_2 -> V_84 ;
unsigned char * V_133 = V_11 ;
unsigned int V_80 , V_51 ;
V_51 = 0 ;
while ( ( V_45 > 0 ) && ( V_20 -> V_21 . V_2 -> V_85 > 0 ) ) {
* V_133 ++ = * V_132 ++ ;
V_45 -- ;
V_20 -> V_21 . V_2 -> V_85 -- ;
V_51 ++ ;
}
for ( V_80 = 0 ; V_80 < V_20 -> V_21 . V_2 -> V_85 ; V_80 ++ )
V_20 -> V_21 . V_2 -> V_84 [ V_80 ] = * V_132 ++ ;
return V_51 ;
}
return 0 ;
}
int F_76 ( T_6 * V_20 , int type , const void * V_11 , int V_45 )
{
int V_48 ;
F_77 ( V_45 <= V_134 ) ;
V_20 -> V_63 = V_64 ;
V_48 = F_78 ( V_20 , type , V_11 , V_45 , 0 ) ;
return V_48 ;
}
int F_78 ( T_6 * V_20 , int type , const unsigned char * V_11 ,
unsigned int V_45 , int V_135 )
{
unsigned char * V_136 , * V_137 ;
int V_48 , V_138 , V_139 = 0 ;
int V_140 = 0 ;
int V_141 ;
V_26 V_142 ;
V_24 * V_143 ;
T_11 * V_144 ;
V_143 = & V_20 -> V_21 . V_145 [ 0 ] ;
if ( F_31 ( V_143 ) != 0 ) {
F_77 ( 0 ) ;
return ( F_79 ( V_20 , type , V_11 , V_45 ) ) ;
}
if ( V_20 -> V_58 -> V_146 ) {
V_48 = V_20 -> V_147 -> V_148 ( V_20 ) ;
if ( V_48 <= 0 )
return ( V_48 ) ;
}
if ( V_45 == 0 && ! V_135 )
return 0 ;
V_144 = V_20 -> V_96 ;
if ( ( V_144 == NULL ) ||
( V_20 -> V_149 == NULL ) || ( F_80 ( V_20 -> V_150 ) == NULL ) )
V_139 = 1 ;
if ( V_139 )
V_138 = 0 ;
else {
V_138 = F_81 ( V_20 -> V_150 ) ;
if ( V_138 < 0 )
goto V_151;
}
V_136 = F_82 ( V_143 ) + V_140 ;
* ( V_136 ++ ) = type & 0xff ;
F_83 ( & V_142 , type ) ;
if ( V_20 -> V_147 -> V_101 == V_152 &&
V_20 -> V_153 != V_154 ) {
* ( V_136 ++ ) = V_155 >> 8 ;
* ( V_136 ++ ) = V_155 & 0xff ;
} else {
* ( V_136 ++ ) = V_20 -> V_101 >> 8 ;
* ( V_136 ++ ) = V_20 -> V_101 & 0xff ;
}
V_137 = V_136 ;
V_136 += 10 ;
if ( V_20 -> V_149 ) {
int V_108 = F_84 ( V_20 -> V_149 ) ;
if ( V_108 == V_156 ) {
V_141 = F_85 ( V_20 -> V_149 ) ;
if ( V_141 <= 1 )
V_141 = 0 ;
}
else if ( V_108 == V_157 )
V_141 = V_158 ;
else if ( V_108 == V_159 )
V_141 = V_160 ;
else
V_141 = 0 ;
} else
V_141 = 0 ;
F_86 ( & V_142 , V_136 + V_141 ) ;
F_51 ( & V_142 , ( int ) V_45 ) ;
F_87 ( & V_142 , ( unsigned char * ) V_11 ) ;
if ( V_20 -> V_161 != NULL ) {
if ( ! F_88 ( V_20 , & V_142 ) ) {
F_18 ( V_162 , V_163 ) ;
goto V_151;
}
} else {
memcpy ( F_52 ( & V_142 ) , F_89 ( & V_142 ) ,
F_46 ( & V_142 ) ) ;
F_90 ( & V_142 ) ;
}
if ( V_138 != 0 ) {
if ( V_20 -> V_147 -> V_164 -> V_165 ( V_20 , & V_142 ,
& ( V_136 [ F_46 ( & V_142 ) + V_141 ] ) ,
1 ) < 0 )
goto V_151;
F_63 ( & V_142 , V_138 ) ;
}
F_86 ( & V_142 , V_136 ) ;
F_90 ( & V_142 ) ;
if ( V_141 )
F_63 ( & V_142 , V_141 ) ;
if ( V_20 -> V_147 -> V_164 -> V_166 ( V_20 , & V_142 , 1 , 1 ) < 1 )
goto V_151;
F_91 ( V_20 -> V_21 . V_2 -> V_13 , V_137 ) ;
memcpy ( V_137 , & ( V_20 -> V_21 . V_15 [ 2 ] ) , 6 ) ;
V_137 += 6 ;
F_91 ( F_46 ( & V_142 ) , V_137 ) ;
if ( V_20 -> V_100 )
V_20 -> V_100 ( 1 , 0 , V_167 , V_137 - V_168 ,
V_168 , V_20 , V_20 -> V_102 ) ;
F_83 ( & V_142 , type ) ;
F_63 ( & V_142 , V_168 ) ;
F_92 ( & ( V_20 -> V_21 . V_15 [ 0 ] ) ) ;
if ( V_135 ) {
return V_142 . V_43 ;
}
F_93 ( V_143 , V_140 + F_46 ( & V_142 ) ) ;
F_94 ( V_143 , 0 ) ;
V_20 -> V_21 . V_169 = V_45 ;
V_20 -> V_21 . V_170 = V_11 ;
V_20 -> V_21 . V_171 = type ;
V_20 -> V_21 . V_172 = V_45 ;
return F_79 ( V_20 , type , V_11 , V_45 ) ;
V_151:
return - 1 ;
}
T_8 * F_33 ( T_6 * V_20 , V_26 * V_36 ,
unsigned int * V_38 )
{
* V_38 = 0 ;
if ( V_36 -> V_40 == V_20 -> V_21 . V_2 -> V_41 )
return & V_20 -> V_21 . V_2 -> V_37 ;
else if ( V_36 -> V_40 == ( unsigned long ) ( V_20 -> V_21 . V_2 -> V_41 + 1 ) &&
V_20 -> V_21 . V_2 -> V_3 . V_40 != V_20 -> V_21 . V_2 -> V_41 &&
( V_36 -> type == V_56 || V_36 -> type == V_86 ) ) {
* V_38 = 1 ;
return & V_20 -> V_21 . V_2 -> V_173 ;
}
return NULL ;
}
void F_95 ( T_6 * V_20 , int V_174 )
{
unsigned char * V_18 ;
unsigned int V_175 = sizeof( V_20 -> V_21 . V_17 ) ;
if ( V_174 & V_176 ) {
V_18 = V_20 -> V_21 . V_17 ;
V_20 -> V_21 . V_2 -> V_41 ++ ;
memcpy ( & V_20 -> V_21 . V_2 -> V_37 , & V_20 -> V_21 . V_2 -> V_173 ,
sizeof( V_20 -> V_21 . V_2 -> V_37 ) ) ;
memset ( & V_20 -> V_21 . V_2 -> V_173 , 0 , sizeof( V_20 -> V_21 . V_2 -> V_173 ) ) ;
F_96 ( V_20 ) ;
} else {
V_18 = V_20 -> V_21 . V_15 ;
memcpy ( V_20 -> V_21 . V_2 -> V_16 , V_18 ,
sizeof( V_20 -> V_21 . V_15 ) ) ;
V_20 -> V_21 . V_2 -> V_13 ++ ;
}
memset ( V_18 , 0 , V_175 ) ;
}
