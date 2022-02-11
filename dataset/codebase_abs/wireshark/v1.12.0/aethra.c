int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
int V_4 ;
struct V_5 V_6 ;
struct V_7 V_7 ;
T_3 * V_8 ;
V_9 = V_10 ;
V_4 = F_2 ( V_6 . V_11 , sizeof V_6 . V_11 , V_1 -> V_12 ) ;
if ( V_4 != sizeof V_6 . V_11 ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_13 )
return - 1 ;
return 0 ;
}
if ( memcmp ( V_6 . V_11 , V_14 , sizeof V_14 ) != 0 )
return 0 ;
V_9 = V_10 ;
V_4 = F_2 ( ( char * ) & V_6 + sizeof V_6 . V_11 ,
sizeof V_6 - sizeof V_6 . V_11 , V_1 -> V_12 ) ;
if ( V_4 != sizeof V_6 - sizeof V_6 . V_11 ) {
* V_2 = F_3 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 == 0 )
* V_2 = V_13 ;
return - 1 ;
}
V_1 -> V_15 = V_16 ;
V_8 = ( T_3 * ) F_4 ( sizeof( T_3 ) ) ;
V_1 -> V_17 = ( void * ) V_8 ;
V_1 -> V_18 = V_19 ;
V_1 -> V_20 = V_21 ;
V_7 . V_22 = F_5 ( & V_6 . V_23 ) - 1900 ;
V_7 . V_24 = F_5 ( & V_6 . V_25 ) - 1 ;
V_7 . V_26 = F_5 ( & V_6 . V_27 ) ;
V_7 . V_28 = V_6 . V_29 ;
V_7 . V_30 = V_6 . V_31 ;
V_7 . V_32 = V_6 . V_33 ;
V_7 . V_34 = - 1 ;
V_8 -> V_35 = mktime ( & V_7 ) ;
V_1 -> V_36 = V_37 ;
V_1 -> V_38 = 0 ;
V_1 -> V_39 = V_40 ;
return 1 ;
}
static T_4 V_19 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_5 * V_41 )
{
struct V_42 V_6 ;
for (; ; ) {
* V_41 = F_6 ( V_1 -> V_12 ) ;
if ( ! F_7 ( V_1 , V_1 -> V_12 , & V_6 , & V_1 -> V_43 , V_2 , V_3 ) )
return FALSE ;
if ( V_1 -> V_43 . V_44 != 0 ) {
if ( ! F_8 ( V_1 -> V_12 , V_1 -> V_45 ,
V_1 -> V_43 . V_44 , V_2 , V_3 ) )
return FALSE ;
}
#if 0
packet++;
#endif
switch ( V_6 . V_46 ) {
case V_47 :
#if 0
fprintf(stderr, "Packet %u: type 0x%02x (AETHRA_ISDN_LINK)\n",
packet, hdr.rec_type);
#endif
switch ( V_6 . V_48 & V_49 ) {
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
static T_4
V_21 ( T_1 * V_1 , T_5 V_54 , struct V_55 * V_43 ,
T_6 * V_56 , int * V_2 , T_2 * * V_3 )
{
struct V_42 V_6 ;
if ( F_9 ( V_1 -> V_57 , V_54 , V_58 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_7 ( V_1 , V_1 -> V_57 , & V_6 , V_43 , V_2 ,
V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_13 ;
return FALSE ;
}
if ( ! F_8 ( V_1 -> V_57 , V_56 , V_43 -> V_44 , V_2 , V_3 ) )
return FALSE ;
return TRUE ;
}
static T_4
F_7 ( T_1 * V_1 , T_7 V_12 , struct V_42 * V_6 ,
struct V_55 * V_43 , int * V_2 , T_2 * * V_3 )
{
T_3 * V_8 = ( T_3 * ) V_1 -> V_17 ;
int V_4 ;
T_8 V_59 ;
T_8 V_60 ;
T_8 V_61 ;
V_9 = V_10 ;
V_4 = F_2 ( V_6 , sizeof *V_6 , V_12 ) ;
if ( V_4 != sizeof *V_6 ) {
* V_2 = F_3 ( V_12 , V_3 ) ;
if ( * V_2 == 0 && V_4 != 0 )
* V_2 = V_13 ;
return FALSE ;
}
V_59 = F_5 ( V_6 -> V_59 ) ;
if ( V_59 < ( sizeof *V_6 - sizeof V_6 -> V_59 ) ) {
* V_2 = V_62 ;
* V_3 = F_10 ( L_1 ,
V_59 ,
( unsigned int ) ( sizeof *V_6 - sizeof V_6 -> V_59 ) ) ;
return FALSE ;
}
V_60 = V_59 - ( T_8 ) ( sizeof *V_6 - sizeof V_6 -> V_59 ) ;
V_61 = F_11 ( V_6 -> V_63 ) ;
V_43 -> V_46 = V_64 ;
V_43 -> V_65 = V_66 ;
V_43 -> V_67 . V_68 = V_8 -> V_35 + ( V_61 / 1000 ) ;
V_43 -> V_67 . V_69 = ( V_61 % 1000 ) * 1000000 ;
V_43 -> V_44 = V_60 ;
V_43 -> V_70 = V_60 ;
V_43 -> V_71 . V_72 . V_73 = ( V_6 -> V_48 & V_74 ) ;
V_43 -> V_71 . V_72 . V_75 = 0 ;
return TRUE ;
}
