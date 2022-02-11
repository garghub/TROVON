T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
struct V_4 V_5 ;
struct V_6 V_6 ;
T_4 * V_7 ;
if ( ! F_2 ( V_1 -> V_8 , V_5 . V_9 , sizeof V_5 . V_9 , V_2 ,
V_3 ) ) {
if ( * V_2 != V_10 )
return V_11 ;
return V_12 ;
}
if ( memcmp ( V_5 . V_9 , V_13 , sizeof V_13 ) != 0 )
return V_12 ;
if ( ! F_2 ( V_1 -> V_8 , ( char * ) & V_5 + sizeof V_5 . V_9 ,
sizeof V_5 - sizeof V_5 . V_9 , V_2 , V_3 ) )
return V_11 ;
V_1 -> V_14 = V_15 ;
V_7 = ( T_4 * ) F_3 ( sizeof( T_4 ) ) ;
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
return V_40 ;
}
static T_5 V_18 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_6 * V_41 )
{
struct V_42 V_5 ;
for (; ; ) {
* V_41 = F_5 ( V_1 -> V_8 ) ;
if ( ! F_6 ( V_1 , V_1 -> V_8 , & V_5 , & V_1 -> V_43 , V_2 , V_3 ) )
return FALSE ;
if ( V_1 -> V_43 . V_44 != 0 ) {
if ( ! F_7 ( V_1 -> V_8 , V_1 -> V_45 ,
V_1 -> V_43 . V_44 , V_2 , V_3 ) )
return FALSE ;
}
#if 0
packet++;
#endif
switch ( V_5 . V_46 ) {
case V_47 :
#if 0
fprintf(stderr, "Packet %u: type 0x%02x (AETHRA_ISDN_LINK)\n",
packet, hdr.rec_type);
#endif
switch ( V_5 . V_48 & V_49 ) {
case V_50 :
#if 0
fprintf(stderr, " subtype 0x%02x (AETHRA_ISDN_LINK_LAPD)\n", hdr.flags & AETHRA_ISDN_LINK_SUBTYPE);
#endif
goto V_51;
case V_52 :
#if 0
fprintf(stderr, " subtype 0x%02x (AETHRA_ISDN_LINK_SA_BITS)\n", hdr.flags & AETHRA_ISDN_LINK_SUBTYPE);
#endif
break;
case V_53 :
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
V_51:
return TRUE ;
}
static T_5
V_20 ( T_2 * V_1 , T_6 V_54 , struct V_55 * V_43 ,
T_7 * V_56 , int * V_2 , T_3 * * V_3 )
{
struct V_42 V_5 ;
if ( F_8 ( V_1 -> V_57 , V_54 , V_58 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_6 ( V_1 , V_1 -> V_57 , & V_5 , V_43 , V_2 ,
V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_10 ;
return FALSE ;
}
if ( ! F_7 ( V_1 -> V_57 , V_56 , V_43 -> V_44 , V_2 , V_3 ) )
return FALSE ;
return TRUE ;
}
static T_5
F_6 ( T_2 * V_1 , T_8 V_8 , struct V_42 * V_5 ,
struct V_55 * V_43 , int * V_2 , T_3 * * V_3 )
{
T_4 * V_7 = ( T_4 * ) V_1 -> V_16 ;
T_9 V_59 ;
T_9 V_60 ;
T_9 V_61 ;
if ( ! F_9 ( V_8 , V_5 , sizeof *V_5 , V_2 , V_3 ) )
return FALSE ;
V_59 = F_4 ( V_5 -> V_59 ) ;
if ( V_59 < ( sizeof *V_5 - sizeof V_5 -> V_59 ) ) {
* V_2 = V_62 ;
* V_3 = F_10 ( L_1 ,
V_59 ,
( unsigned int ) ( sizeof *V_5 - sizeof V_5 -> V_59 ) ) ;
return FALSE ;
}
if ( V_59 > V_63 ) {
* V_2 = V_62 ;
* V_3 = F_10 ( L_2 ,
V_59 , V_63 ) ;
return FALSE ;
}
V_60 = V_59 - ( T_9 ) ( sizeof *V_5 - sizeof V_5 -> V_59 ) ;
V_61 = F_11 ( V_5 -> V_64 ) ;
V_43 -> V_46 = V_65 ;
V_43 -> V_66 = V_67 ;
V_43 -> V_68 . V_69 = V_7 -> V_34 + ( V_61 / 1000 ) ;
V_43 -> V_68 . V_70 = ( V_61 % 1000 ) * 1000000 ;
V_43 -> V_44 = V_60 ;
V_43 -> V_71 = V_60 ;
V_43 -> V_72 . V_73 . V_74 = ( V_5 -> V_48 & V_75 ) ;
V_43 -> V_72 . V_73 . V_76 = 0 ;
return TRUE ;
}
