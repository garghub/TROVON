int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
struct V_4 V_5 ;
struct V_6 V_6 ;
T_3 * V_7 ;
V_8 = V_9 ;
if ( ! F_2 ( V_1 -> V_10 , V_5 . V_11 , sizeof V_5 . V_11 , V_2 ,
V_3 ) ) {
if ( * V_2 != V_12 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_5 . V_11 , V_13 , sizeof V_13 ) != 0 )
return 0 ;
V_8 = V_9 ;
if ( ! F_2 ( V_1 -> V_10 , ( char * ) & V_5 + sizeof V_5 . V_11 ,
sizeof V_5 - sizeof V_5 . V_11 , V_2 , V_3 ) )
return - 1 ;
V_1 -> V_14 = V_15 ;
V_7 = ( T_3 * ) F_3 ( sizeof( T_3 ) ) ;
V_1 -> V_16 = ( void * ) V_7 ;
V_1 -> V_17 = V_18 ;
V_1 -> V_19 = V_20 ;
V_6 . V_21 = F_4 ( & V_5 . V_22 ) - 1900 ;
V_6 . V_23 = F_4 ( & V_5 . V_24 ) - 1 ;
V_6 . V_25 = F_4 ( & V_5 . V_26 ) ;
V_6 . V_27 = V_5 . V_28 ;
V_6 . V_29 = V_5 . V_30 ;
V_6 . V_31 = V_5 . V_32 ;
V_6 . V_33 = - 1 ;
V_7 -> V_34 = mktime ( & V_6 ) ;
V_1 -> V_35 = V_36 ;
V_1 -> V_37 = 0 ;
V_1 -> V_38 = V_39 ;
return 1 ;
}
static T_4 V_18 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_40 )
{
struct V_41 V_5 ;
for (; ; ) {
* V_40 = F_5 ( V_1 -> V_10 ) ;
if ( ! F_6 ( V_1 , V_1 -> V_10 , & V_5 , & V_1 -> V_42 , V_2 , V_3 ) )
return FALSE ;
if ( V_1 -> V_42 . V_43 != 0 ) {
if ( ! F_7 ( V_1 -> V_10 , V_1 -> V_44 ,
V_1 -> V_42 . V_43 , V_2 , V_3 ) )
return FALSE ;
}
#if 0
packet++;
#endif
switch ( V_5 . V_45 ) {
case V_46 :
#if 0
fprintf(stderr, "Packet %u: type 0x%02x (AETHRA_ISDN_LINK)\n",
packet, hdr.rec_type);
#endif
switch ( V_5 . V_47 & V_48 ) {
case V_49 :
#if 0
fprintf(stderr, " subtype 0x%02x (AETHRA_ISDN_LINK_LAPD)\n", hdr.flags & AETHRA_ISDN_LINK_SUBTYPE);
#endif
goto V_50;
case V_51 :
#if 0
fprintf(stderr, " subtype 0x%02x (AETHRA_ISDN_LINK_SA_BITS)\n", hdr.flags & AETHRA_ISDN_LINK_SUBTYPE);
#endif
break;
case V_52 :
#if 0
fprintf(stderr, " subtype 0x%02x (AETHRA_ISDN_LINK_ALL_ALARMS_CLEARED)\n", hdr.flags & AETHRA_ISDN_LINK_SUBTYPE);
#endif
break;
default:
#if 0
fprintf(stderr, " subtype 0x%02x, packet_size %u, direction 0x%02x\n",
hdr.flags & AETHRA_ISDN_LINK_SUBTYPE, wth->phdr.caplen, hdr.flags & AETHRA_U_TO_N);
#endif
break;
}
break;
default:
#if 0
fprintf(stderr, "Packet %u: type 0x%02x, packet_size %u, flags 0x%02x\n",
packet, hdr.rec_type, wth->phdr.caplen, hdr.flags);
#endif
break;
}
}
V_50:
return TRUE ;
}
static T_4
V_20 ( T_1 * V_1 , T_5 V_53 , struct V_54 * V_42 ,
T_6 * V_55 , int * V_2 , T_2 * * V_3 )
{
struct V_41 V_5 ;
if ( F_8 ( V_1 -> V_56 , V_53 , V_57 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_6 ( V_1 , V_1 -> V_56 , & V_5 , V_42 , V_2 ,
V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_12 ;
return FALSE ;
}
if ( ! F_7 ( V_1 -> V_56 , V_55 , V_42 -> V_43 , V_2 , V_3 ) )
return FALSE ;
return TRUE ;
}
static T_4
F_6 ( T_1 * V_1 , T_7 V_10 , struct V_41 * V_5 ,
struct V_54 * V_42 , int * V_2 , T_2 * * V_3 )
{
T_3 * V_7 = ( T_3 * ) V_1 -> V_16 ;
T_8 V_58 ;
T_8 V_59 ;
T_8 V_60 ;
V_8 = V_9 ;
if ( ! F_9 ( V_10 , V_5 , sizeof *V_5 , V_2 , V_3 ) )
return FALSE ;
V_58 = F_4 ( V_5 -> V_58 ) ;
if ( V_58 < ( sizeof *V_5 - sizeof V_5 -> V_58 ) ) {
* V_2 = V_61 ;
* V_3 = F_10 ( L_1 ,
V_58 ,
( unsigned int ) ( sizeof *V_5 - sizeof V_5 -> V_58 ) ) ;
return FALSE ;
}
V_59 = V_58 - ( T_8 ) ( sizeof *V_5 - sizeof V_5 -> V_58 ) ;
V_60 = F_11 ( V_5 -> V_62 ) ;
V_42 -> V_45 = V_63 ;
V_42 -> V_64 = V_65 ;
V_42 -> V_66 . V_67 = V_7 -> V_34 + ( V_60 / 1000 ) ;
V_42 -> V_66 . V_68 = ( V_60 % 1000 ) * 1000000 ;
V_42 -> V_43 = V_59 ;
V_42 -> V_69 = V_59 ;
V_42 -> V_70 . V_71 . V_72 = ( V_5 -> V_47 & V_73 ) ;
V_42 -> V_70 . V_71 . V_74 = 0 ;
return TRUE ;
}
